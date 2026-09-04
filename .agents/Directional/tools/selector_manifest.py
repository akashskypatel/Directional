"""Regenerate .agents/Directional/Required_Green_Selector_Manifest.md.

Derived index of every byte-frozen Required_Green_Selector file: identity count,
LF-normalized SHA-256, prefix parent, appended identities, role. Reads only; it
never writes a selector file. Run after any turn that appends a selector.

    python .agents/Directional/tools/selector_manifest.py
"""
import glob, os, re, hashlib, io, subprocess

root = subprocess.run(["git", "rev-parse", "--show-toplevel"], capture_output=True,
                      text=True, encoding="utf-8").stdout.strip() or os.getcwd()
d = os.path.join(root, ".agents", "Directional")

def lf_lines(p):
    return io.open(p, encoding="utf-8").read().replace("\r\n", "\n").rstrip("\n").split("\n")

def lf_sha(lines):
    return hashlib.sha256(("\n".join(lines) + "\n").encode()).hexdigest()

fs = sorted(glob.glob(os.path.join(d, "*Required_Green_Selector_*.txt")),
            key=lambda p: int(re.search(r"_(\d+)\.txt$", p).group(1)))

ROLE = {
    357: ("superseded", "CP4c-2 gate before the 358 branch. **Off-chain** - not a prefix of 358."),
    358: ("withdrawn", "**Off-chain** - not a prefix of 361. Retained as historical authority by DEFN-R2 AG0."),
    361: ("superseded", "First file of the current prefix chain."),
    365: ("**ACCEPTED AUTHORITY**", "The load-bearing boundary. Every acceptance claim cites this hash."),
    385: ("superseded", "Name is 385; identity count is **388**. See the naming section above."),
    391: ("superseded", "CB23 appends three diagnostic-only witnesses to the frozen 388-identity selector 385."),
    393: ("**CURRENT GATE**", "CB24 appends two diagnostic-only projection witnesses to frozen selector 391."),
}

rows = []
prev = None
for p in fs:
    num = int(re.search(r"_(\d+)\.txt$", p).group(1))
    L = lf_lines(p)
    sha = lf_sha(L)
    if prev is None:
        parent, added = "-", []
    else:
        pn, pL = prev
        if L[:len(pL)] == pL:
            parent = "%d" % pn
            added = L[len(pL):]
        else:
            parent = "**none**"
            added = None
    role, note = ROLE.get(num, ("superseded", ""))
    rows.append((num, os.path.basename(p), len(L), sha, parent, added, role, note))
    prev = (num, L)

def git_first_commit(path):
    r = subprocess.run(["git", "log", "--reverse", "--format=%h %ad", "--date=short", "--", path],
                       cwd=root, capture_output=True, text=True, encoding="utf-8", errors="replace")
    line = (r.stdout or "").strip().split("\n")[0]
    return line if line else "-"

out = []
out.append("""# Required Green Selector Manifest

**Purpose — DURABLE, DO NOT DELETE.** One auditable index of every byte-frozen `Required_Green_Selector` file:
its identity count, its LF-normalized SHA-256, its prefix parent, what it appended, and its role.

This file is **derived and additive**. It changes no selector byte and grants no authority. Where it disagrees with
a selector file, **the selector file wins** — recompute with
`.agents/Directional/tools/selector_probe.py hash <n>`.

## Why every one of these files is retained

The prefix chain is the project's core safety invariant: every turn re-proves that accepted selector **365** is an
exact prefix of the current gate. **That check has force only because 365's bytes are stored independently of the
current gate file.** Collapsing the chain into one file plus line counts would make the check compare a file
against itself, so it could never fail — deleting the witness while keeping the assertion.

Each file is also hash-pinned in an immutable Test + Benchmark report and a GitHub Actions artifact, and
`tools/review_check.py boundary` re-verifies every hash against HEAD each turn. Consolidation, renaming, or
deletion of any selector file requires explicit user authorization; `M3_CP4c_Frozen_Definitions.md` Parts IV and V
additionally prohibit changing the bytes of 357, 358, 361, 365 and 367.

## Naming — read this before deriving a count from a filename

Selector files **357 through 384** are each named by their identity count. **This no longer holds.**
`Architecture_M3_CP4c3_Required_Green_Selector_385.txt` is named 385 and contains **388** identities, because
`M3-CP4c-3-CB22` appended four witnesses under a plan whose wording predicted one file number. Its bytes are
frozen, hash-verified and correct and it must **not** be renamed.

**Never derive an identity count from a selector filename. Use the `identities` column below.**
Future selector files are named by their resulting identity count.

## The chain
""")

out.append("| Selector | Identities | LF SHA-256 | Prefix parent | Appended | Role |")
out.append("|---|---:|---|---|---:|---|")
for num, name, n, sha, parent, added, role, note in rows:
    app = "-" if (added is None or parent == "-") else ("%d" % len(added) if added else "0")
    out.append("| **%d** | %d | `%s` | %s | %s | %s |" % (num, n, sha, parent, app, role))

out.append("""
`Prefix parent` **none** marks a file that is *not* an extension of the previous one — a superseded or withdrawn
branch carrying unique bytes. Those are not redundant with anything and cannot be reconstructed from the chain.

## Per-file notes and appended identities
""")
for num, name, n, sha, parent, added, role, note in rows:
    out.append("### %d — %s" % (num, role.replace("**", "")))
    out.append("")
    out.append("`%s` — %d identities, first committed %s." % (name, n, git_first_commit(".agents/Directional/" + name)))
    if note:
        out.append("")
        out.append(note)
    out.append("")
    if added is None:
        out.append("**Off-chain:** not an extension of selector %s. Holds unique bytes." % rows[[r[0] for r in rows].index(num) - 1][0])
    elif parent == "-":
        out.append("Chain root in this family.")
    elif not added:
        out.append("Appended nothing to selector %s." % parent)
    else:
        out.append("Appended %d identit%s to selector %s:" % (len(added), "y" if len(added) == 1 else "ies", parent))
        out.append("")
        for a in added:
            out.append("- `%s`" % a.strip())
    out.append("")

m1 = os.path.join(d, "M1_Full_Required_Green_Selector.txt")
if os.path.exists(m1):
    L = lf_lines(m1)
    out.append("""## Separate lineage — M1

`M1_Full_Required_Green_Selector.txt` — **%d** identities, LF SHA-256 `%s`. This is the M1 milestone's full
selector and is **not** part of the CP4c prefix chain above. It is retained under `M1_Closure_Record.md`.
""" % (len(L), lf_sha(L)))

out.append("""## Regenerating this manifest

Every column is derived. `tools/selector_probe.py` computes counts, LF hashes, prefix relations and appended
identities; hashes here are over **LF-normalized** bytes, which is what the published hashes use — a Windows
checkout stores CRLF, so a raw file hash will not match.

Regenerate after any turn that appends a selector, and never edit a selector file to make it agree with this one.
""")

path = os.path.join(d, "Required_Green_Selector_Manifest.md")
io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(out) + "\n")
print("wrote %s (%d lines, %d selectors)" % (os.path.basename(path), len("\n".join(out).split("\n")), len(rows)))
