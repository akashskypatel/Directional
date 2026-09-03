#!/usr/bin/env python3
"""review_check.py -- authority verification and review-boundary enforcement.

REVIEW AID ONLY. Read-only with respect to the repository: runs git plumbing and hashes,
never writes.

Two things every REVIEW turn does by hand, now one command each:

  authority   The BG0/BI0-style opener. Given the semantic/package source SHA a TB report
              declares, prove (a) the commit exists, (b) it is an ancestor of HEAD, and
              (c) no code surface has drifted between it and HEAD. (c) is what licenses
              static review of the working tree as evidence about the immutable package --
              without it, reading HEAD proves nothing about what was tested.

  boundary    The pre-commit gate for a REVIEW turn. Proves the turn mutated no product,
              test, fixture, benchmark, build or selector byte; that every selector still
              hashes to its committed value; and that durable section markers survived.

Usage
-----
    python3 review_check.py authority 71ece3ca184e90858d9222fb014b37c16d292294
    python3 review_check.py boundary
    python3 review_check.py boundary --expect-selector 378=86259d91...440b8

Exit codes: 0 = all checks passed, 1 = at least one check failed.
"""

import argparse
import hashlib
import os
import re
import subprocess
import sys

CODE_SURFACES = ["src", "include", "tests", "benchmarks", "CMakeLists.txt", "cmake"]

DURABLE_FILES = {
    ".agents/Directional/Future_Chat_Session_Handoff.md": "DURABLE",
    ".agents/Directional/ORIENTATION.md": "DURABLE",
}

FAILED = []


def repo_root():
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.abspath(os.path.join(here, os.pardir, os.pardir, os.pardir))


def git(*args):
    """Run git, always decoding as UTF-8.

    The default locale codec is cp1252 on a Windows review machine, and the durable
    documents contain non-ASCII (em dashes, Greek). Without an explicit encoding the
    reader thread dies with UnicodeDecodeError and stdout comes back None.
    """
    return subprocess.run(["git"] + list(args), cwd=repo_root(),
                          capture_output=True, text=True,
                          encoding="utf-8", errors="replace")


def report(ok, label, detail=""):
    print("  [%s] %-52s %s" % ("PASS" if ok else "FAIL", label, detail))
    if not ok:
        FAILED.append(label)


def sha_lf(path):
    raw = open(path, "rb").read().replace(b"\r\n", b"\n")
    return hashlib.sha256(raw).hexdigest()


def selector_paths():
    base = os.path.join(repo_root(), ".agents", "Directional")
    out = {}
    for name in os.listdir(base):
        m = re.search(r"Required_Green_Selector_(\d+)\.txt$", name)
        if m:
            out[int(m.group(1))] = os.path.join(base, name)
    return out


# ---------------------------------------------------------------- authority
def cmd_authority(args):
    sha = args.source
    print("authority check for semantic/package source %s" % sha)

    kind = git("cat-file", "-t", sha)
    report(kind.returncode == 0 and kind.stdout.strip() == "commit",
           "source commit exists", kind.stdout.strip() or kind.stderr.strip())
    if kind.returncode != 0:
        return

    show = git("log", "-1", "--format=%H%n%ci%n%s", sha)
    for line in show.stdout.strip().split("\n"):
        print("      %s" % line)

    anc = git("merge-base", "--is-ancestor", sha, "HEAD")
    report(anc.returncode == 0, "source is an ancestor of HEAD")

    drift = git("diff", "--name-only", sha, "HEAD", "--", *CODE_SURFACES)
    changed = [x for x in drift.stdout.strip().split("\n") if x.strip()]
    report(not changed,
           "no code drift source..HEAD",
           "clean" if not changed else "%d file(s) changed" % len(changed))
    for path in changed[:20]:
        print("        %s" % path)
    if len(changed) > 20:
        print("        ... and %d more" % (len(changed) - 20))

    if not changed:
        print("      => static review of the working tree is valid evidence about the package.")
    else:
        print("      => working tree has DRIFTED; do NOT cite HEAD as package evidence.")


# ---------------------------------------------------------------- boundary
def cmd_boundary(args):
    print("review-turn boundary check")

    status = git("status", "--porcelain")
    entries = [line for line in status.stdout.split("\n") if line.strip()]
    paths = [line[3:].strip().strip('"') for line in entries]

    def is_code(p):
        return any(p == s or p.startswith(s + "/") for s in CODE_SURFACES)

    code_touched = [p for p in paths if is_code(p)]
    report(not code_touched, "no product/test/fixture/build mutation",
           "clean" if not code_touched else ", ".join(code_touched[:6]))

    # An actual byte-frozen selector is a .txt named by a number, or the M1 full
    # selector. Match those exactly -- a substring test also fires on documents
    # about selectors, such as Required_Green_Selector_Manifest.md.
    selector_touched = [p for p in paths
                        if re.search(r"Required_Green_Selector_\d+\.txt$", p)
                        or p.endswith("M1_Full_Required_Green_Selector.txt")]
    report(not selector_touched, "no selector mutation",
           "clean" if not selector_touched else ", ".join(selector_touched))

    sels = selector_paths()
    for n in sorted(sels):
        rel = os.path.relpath(sels[n], repo_root()).replace("\\", "/")
        blob = git("show", "HEAD:%s" % rel)
        if blob.returncode != 0:
            report(True, "selector %d (untracked, new this turn)" % n, sha_lf(sels[n])[:16])
            continue
        committed = hashlib.sha256(
            blob.stdout.encode("utf-8").replace(b"\r\n", b"\n")).hexdigest()
        live = sha_lf(sels[n])
        report(committed == live, "selector %d hash matches HEAD" % n, live[:16] + "...")

    for expect in args.expect_selector or []:
        if "=" not in expect:
            sys.exit("--expect-selector wants N=SHA, got %r" % expect)
        n_s, want = expect.split("=", 1)
        n = int(n_s)
        if n not in sels:
            report(False, "selector %d present" % n, "missing")
            continue
        live = sha_lf(sels[n])
        ok = live.startswith(want.rstrip(".")) or live == want
        report(ok, "selector %d matches declared hash" % n, live)

    for rel, marker in DURABLE_FILES.items():
        path = os.path.join(repo_root(), rel)
        if not os.path.exists(path):
            report(False, "durable file present: %s" % os.path.basename(rel), "missing")
            continue
        live = open(path, encoding="utf-8", errors="replace").read().count(marker)
        blob = git("show", "HEAD:%s" % rel)
        if blob.returncode != 0:
            report(True, "durable markers in %s" % os.path.basename(rel),
                   "%d (new file)" % live)
            continue
        was = blob.stdout.count(marker)
        report(live >= was, "durable markers preserved in %s" % os.path.basename(rel),
               "%d -> %d" % (was, live))

    docs = [p for p in paths if not is_code(p) and "Required_Green_Selector_" not in p]
    print("\n  documents changed this turn (%d):" % len(docs))
    for p in docs:
        print("      %s" % p)


def main():
    parser = argparse.ArgumentParser(
        description="Authority and review-boundary checks (review aid only).")
    subs = parser.add_subparsers(dest="cmd", required=True)

    p = subs.add_parser("authority")
    p.add_argument("source")
    p.set_defaults(fn=cmd_authority)

    p = subs.add_parser("boundary")
    p.add_argument("--expect-selector", nargs="*")
    p.set_defaults(fn=cmd_boundary)

    args = parser.parse_args()
    args.fn(args)
    print("\n%s" % ("ALL CHECKS PASSED" if not FAILED
                    else "FAILED: " + "; ".join(FAILED)))
    sys.exit(1 if FAILED else 0)


if __name__ == "__main__":
    main()
