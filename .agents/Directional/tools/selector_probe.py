#!/usr/bin/env python3
"""selector_probe.py -- selector and test-identity lookups for Directional review turns.

REVIEW AID ONLY. Read-only: never writes a selector, never mutates the repository.

Every REVIEW turn re-derives the same handful of selector facts (BG0/BI0-style measures):
hashes, cardinality, prefix continuity, ordinal <-> identity, and whether an identity sits
in the accepted-365 prefix. This script exists so those are one command instead of a fresh
inline script each time.

Hashing convention
------------------
Selector hashes published in reports are SHA-256 of the file with **LF** line endings. On a
Windows checkout the working-tree bytes may be CRLF, so a naive `sha256sum` will NOT match.
This script normalizes CRLF -> LF before hashing, which is what reproduces published values.

Usage
-----
    python3 selector_probe.py list
    python3 selector_probe.py hash 378 [--prefix 365 377]
    python3 selector_probe.py ordinal 366 [--selector 378]
    python3 selector_probe.py find RotationRay [--selector 378]
    python3 selector_probe.py prefix 377 378
    python3 selector_probe.py identity tests/FieldAlignedCurveNetworkTests.cpp:9408
    python3 selector_probe.py identity --name ResolvedBranchContinuation.RejectsUnresolvedRegularVertexSector
"""

import argparse
import glob
import hashlib
import os
import re
import sys

ACCEPTED_PREFIX = 365


def repo_root():
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.abspath(os.path.join(here, os.pardir, os.pardir, os.pardir))


def agents_dir():
    return os.path.join(repo_root(), ".agents", "Directional")


def selector_files():
    """Map selector cardinality -> path, for every Required_Green_Selector_<n>.txt."""
    found = {}
    pattern = os.path.join(agents_dir(), "*Required_Green_Selector_*.txt")
    for path in glob.glob(pattern):
        m = re.search(r"Required_Green_Selector_(\d+)\.txt$", os.path.basename(path))
        if m:
            found[int(m.group(1))] = path
    return found


def load_identities(path):
    raw = open(path, "rb").read().replace(b"\r\n", b"\n")
    return [line for line in raw.decode("utf-8").split("\n") if line.strip()]


def sha_lf(path):
    raw = open(path, "rb").read().replace(b"\r\n", b"\n")
    return hashlib.sha256(raw).hexdigest()


def sha_of_identities(identities):
    body = "\n".join(identities) + "\n"
    return hashlib.sha256(body.encode("utf-8")).hexdigest()


def resolve(n):
    files = selector_files()
    if n not in files:
        sys.exit("no selector file for %d (have: %s)" % (n, sorted(files)))
    return files[n]


def newest_selector():
    files = selector_files()
    if not files:
        sys.exit("no selector files found under %s" % agents_dir())
    return max(files)


# ---------------------------------------------------------------- subcommands
def cmd_list(args):
    files = selector_files()
    print("%-6s %-64s %-6s %s" % ("sel", "sha256(LF)", "ids", "file"))
    for n in sorted(files):
        ids = load_identities(files[n])
        flag = "" if len(ids) == n else "   <-- CARDINALITY MISMATCH"
        print("%-6d %-64s %-6d %s%s"
              % (n, sha_lf(files[n]), len(ids), os.path.basename(files[n]), flag))


def cmd_hash(args):
    path = resolve(args.n)
    ids = load_identities(path)
    print("selector      : %d" % args.n)
    print("file          : %s" % os.path.basename(path))
    print("sha256(LF)    : %s" % sha_lf(path))
    print("identities    : %d%s" % (len(ids), "" if len(ids) == args.n else "  <-- MISMATCH"))
    for p in args.prefix or []:
        if p > len(ids):
            print("prefix %-6d : n/a (only %d identities)" % (p, len(ids)))
            continue
        print("prefix %-6d : %s" % (p, sha_of_identities(ids[:p])))


def cmd_ordinal(args):
    n = args.selector or newest_selector()
    ids = load_identities(resolve(n))
    for o in args.values:
        if o < 1 or o > len(ids):
            print("ordinal %-5d OUT OF RANGE (selector %d has %d)" % (o, n, len(ids)))
            continue
        name = ids[o - 1]
        print("ordinal %-5d %s%s"
              % (o, name, "   [accepted-365]" if o <= ACCEPTED_PREFIX else ""))


def cmd_find(args):
    n = args.selector or newest_selector()
    ids = load_identities(resolve(n))
    rx = re.compile(args.pattern, re.IGNORECASE)
    hits = 0
    for i, name in enumerate(ids, 1):
        if rx.search(name):
            hits += 1
            print("ordinal %-5d %s%s"
                  % (i, name, "   [accepted-365]" if i <= ACCEPTED_PREFIX else ""))
    if not hits:
        print("no identity in selector %d matches %r" % (n, args.pattern))


def cmd_prefix(args):
    small, large = load_identities(resolve(args.a)), load_identities(resolve(args.b))
    if len(small) > len(large):
        sys.exit("selector %d is larger than %d" % (args.a, args.b))
    head = large[:len(small)]
    exact = head == small
    print("selector %d is an exact prefix of %d : %s" % (args.a, args.b, exact))
    print("prefix sha256 : %s" % sha_of_identities(head))
    print("file   sha256 : %s" % sha_lf(resolve(args.a)))
    if not exact:
        for i, (x, y) in enumerate(zip(small, head), 1):
            if x != y:
                print("  first divergence at ordinal %d:\n    %s\n    %s" % (i, x, y))
                break
    added = large[len(small):]
    print("appended by %d (%d):" % (args.b, len(added)))
    for i, name in enumerate(added, len(small) + 1):
        print("  ordinal %-5d %s" % (i, name))


TEST_RE = re.compile(r"TEST(?:_F)?\(\s*(\w+)\s*,\s*(\w+)\s*\)")


def enclosing_identity(path, line_no):
    lines = open(path, encoding="utf-8", errors="replace").read().split("\n")
    best = None
    for i, line in enumerate(lines, 1):
        if i > line_no:
            break
        m = TEST_RE.match(line.strip())
        if m:
            best = (i, m.group(1) + "." + m.group(2))
    return best


def cmd_identity(args):
    n = args.selector or newest_selector()
    ids = load_identities(resolve(n))
    index = {name: i for i, name in enumerate(ids, 1)}

    names = []
    if args.name:
        names.append((None, args.name))
    for token in args.locations or []:
        if ":" not in token:
            sys.exit("expected <file>:<line>, got %r" % token)
        rel, line_s = token.rsplit(":", 1)
        path = rel if os.path.isabs(rel) else os.path.join(repo_root(), rel)
        if not os.path.exists(path):
            sys.exit("no such file: %s" % path)
        found = enclosing_identity(path, int(line_s))
        if not found:
            print("%s -> no enclosing TEST()" % token)
            continue
        names.append((token, found[1]))

    for origin, name in names:
        ordinal = index.get(name)
        where = "%s -> " % origin if origin else ""
        if ordinal is None:
            print("%s%s   NOT IN SELECTOR %d" % (where, name, n))
        else:
            tag = "accepted-365" if ordinal <= ACCEPTED_PREFIX else "unaccepted"
            print("%s%s   ordinal=%d  [%s]" % (where, name, ordinal, tag))


def main():
    parser = argparse.ArgumentParser(
        description="Selector and test-identity lookups (review aid only).")
    subs = parser.add_subparsers(dest="cmd", required=True)

    subs.add_parser("list").set_defaults(fn=cmd_list)

    p = subs.add_parser("hash")
    p.add_argument("n", type=int)
    p.add_argument("--prefix", type=int, nargs="*")
    p.set_defaults(fn=cmd_hash)

    p = subs.add_parser("ordinal")
    p.add_argument("values", type=int, nargs="+")
    p.add_argument("--selector", type=int)
    p.set_defaults(fn=cmd_ordinal)

    p = subs.add_parser("find")
    p.add_argument("pattern")
    p.add_argument("--selector", type=int)
    p.set_defaults(fn=cmd_find)

    p = subs.add_parser("prefix")
    p.add_argument("a", type=int)
    p.add_argument("b", type=int)
    p.set_defaults(fn=cmd_prefix)

    p = subs.add_parser("identity")
    p.add_argument("locations", nargs="*")
    p.add_argument("--name")
    p.add_argument("--selector", type=int)
    p.set_defaults(fn=cmd_identity)

    args = parser.parse_args()
    args.fn(args)


if __name__ == "__main__":
    main()
