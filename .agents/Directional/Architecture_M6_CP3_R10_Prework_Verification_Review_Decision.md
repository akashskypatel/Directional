# Review decision — RA-82: R10 pre-work verified on real history; R10 split

**Turn:** `M6-CP3-R10-PREWORK-VERIFICATION-REV` · **Verdict:** pre-work `0660af9d1` ACCEPTED; the blocked R10 turn is closed and replaced by R10A/R10B · **Date:** 2026-10-17
**Verified at:** full clone, HEAD `2858919ea`. Source unchanged since `d938ecb57` (`src`, `include`, `tests`).

## Why R10 blocked

The implementation agent works from a source snapshot with no `.git`. `review_check.py` reads history
(`cat-file`, `merge-base`, `rev-list`, `show`) and fails closed there: on a `git archive` snapshot of HEAD,
`boundary` fails 4 checks (rewrite base and the three rewrite sources). The RA-81 handoff made those
history checks a completion criterion of an implementation turn, which that environment cannot satisfy.
That was a gate-placement error in the handoff, not an implementation defect. `document_drift_audit.py`
without `--base` needs no history (snapshot: 0 errors, 0 warnings). The R10 definition itself was not
started: `0d969b6e2` is an empty commit and no specification exists in the repository.

## RA-82.1 — pre-work verified against genuine history

| Check | Result |
|---|---|
| `review_check.py boundary` | ALL PASS — handoff 4/4 durable sections, ORIENTATION 1/1, tracker 0/0, every selector hash unchanged |
| `review_check.py ledgers --base 8b7299b43` | ALL PASS — root `CHANGELOG.md` and `LESSONS.md` never shrank |
| `document_drift_audit.py --base b738cd13e` | 0 errors; 3 `PROTECTED_CHANGE` warnings = `ORIENTATION.md:85`, `RETENTION_POLICY.md:34,53`, `ROADMAP.md:7`, exactly the user-authorized edits |
| Changelog move | `.agents/Directional/CHANGELOG.md` deleted. 433/433 identifiers (hex ≥ 7, decimal ≥ 9 digits) present in root; all 1,505 non-blank lines of old root and 904/938 of the old `.agents` file kept verbatim — the other 34 are headings of entries merged with a same-turn root entry (394 → 360 headings); 0 date-order inversions |
| Live references | none left; remaining mentions are dated historical prose |
| Non-vacuity (scratch clone) | FAIL on: deleted durable heading; committed root-changelog shrink (also with a later `--base`, and after regrowth); committed `LESSONS.md` shrink |

## RA-82.2 — known limits of the re-baselined tool (accepted, not blocking)

Reproduced on the scratch clone; each passes when it arguably should not:
- **Heading level only:** a durable section emptied under its heading passes (17 lines removed, PASS).
- **Line counts only:** a same-length rewrite of a changelog line passes.
- **Committed history only:** an uncommitted changelog shrink passes until committed.
- The tracker had no durable section at the rewrite base, so its check is `0/0`.
- `--base` is ignored; any future changelog shrink fails permanently unless the tool is changed under its own authorization.

The Review Agent covers these by reading each turn's diff. No hardening turn is authorized; it would not
advance CP3.

## RA-82.3 — where the history gates run (frozen)

`review_check.py authority|boundary|ledgers` and `document_drift_audit.py --base` are **Review Agent
gates**, run on a full clone at every Review. An implementation turn runs
`document_drift_audit.py --root .` (no `--base`), reports the history gates as *deferred to Review*, and
never blocks on their absence or tries to recreate history.

## RA-82.4 — the coverage gap has two layers in the verifier (reviewer reading, R10A to confirm)

- **Consumer** (`SurfaceCellTracing.cpp:19397-19425`), per endpoint: a terminal vertex is chosen only
  from published contact endpoints; otherwise the interior-carrier branch needs `0 < t < 1`. Vertex 4
  falls through to `reject("no-exact-terminal-corner")`.
- **Verifier, route level** (`:8581-8615`): an open-rail front needs at least one endpoint whose
  `terminalVertex` is a published contact endpoint touching its carrier (`singleTerminalValid`), or
  both endpoints terminal in opposite order.
- **Verifier, per endpoint** (`:8699-8721`): the vertex must be a contact endpoint; with no vertex,
  the point must be strictly interior to the carrier.

Consequences to confirm: (a) a front with **no** endpoint on a rail terminal — the middle front of any open
rail cut into three or more fronts — is rejected at route level whatever per-endpoint branch is added, so
a fix verified only on the two-front fixture rail `1–4–7` would fail on longer rails; (b) the consumer can
already emit an I/I certificate that the verifier rejects.

**Witness asymmetry:** closed rails publish an ordered vertex chain (`SurfaceHardRailClosedChain`,
`include/directional/geometry/SurfaceCellTracing.h:1538`); open rails publish only
`{component, endpoints}` (`SurfaceHardRailTerminalContact`, `:1530`). That a vertex is interior to an
open rail is carried today only by the certificate's own route, which RA-65.5 may treat as absent.
Both star-path implementations skip hard-feature spokes (`:19433-19441`; `unique_terminal_star_path`
`:8166-8220`), so at an interior rail vertex the two rail edges split the star into two sectors. Whether
that gives exactly one path per side is for R10A to establish.

**Prior art:** the verifier's junction check (`:8775-8870`) already certifies a vertex where a route
*passes through* consecutive rail edges, using source authority rather than the certificate: exactly two
hard spokes at the vertex, both route edges; an interior two-manifold link; two disjoint sector paths
covering the star. An endpoint *stopping* at such a vertex has no counterpart. R10A must say which of
these checks transfer.

## RA-82.5 — R10 split into narrow turns

R10 asked for four deliverables in one turn. It is replaced by:

1. `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS` — facts only: a rejection trace per checker
   per front shape, and a witness inventory (publisher or *absent*). No rule.
2. `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV` — census errors have recurred (RA-71), so
   the facts are reviewed before a rule is built on them.
3. `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE` — the rule against both checkers and both
   layers, using only accepted witnesses; an endpoint it still rejects; repair or relocation (RA-72.5);
   admit/reject test cases.
4. R10B Review; code only if it authorizes it.

Only steps 1 and 2 are authorized now.

## Disposition

`RP-01` open, still owned by the consumer endpoint contract, now known to need a route-level decision as
well. `RP-02` unreached; Gate C suspended. Stable 66/17/49, debt 1, CP2 491/491, R3 403/497, selector
497 unchanged; no promotion. Consolidation: nothing to fold — the RA-81 decision, the R9A census and the
R9B specification remain current inputs to R10A.
