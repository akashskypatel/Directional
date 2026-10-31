# RA-120 — CB22B accepted statically; the site reaches all nine A5-ISO rows; TB23 harvest issued (2026-10-21)

**Turn:** `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES-REV`. **Input:** CB22B record `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Code_Build_Record_20261021.md`; source `c6e90916e`. **Lines:** TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, RP = `src/pipeline/RemeshPipeline.cpp`, both at `c6e90916e`.

## RA-120.1 Package verified independently

- Compile run [39591106454](https://github.com/akashskypatel/Directional/actions/runs/39591106454) success; package `12341307713`, ZIP SHA-256 `b5f9a668…8ad5` (recomputed locally, equal to the provider digest), expires 2026-10-28T11:21:37Z.
- 28/28 `SHA256SUMS`; root manifest `7c396be6…7f11`; source archive `c3779cc9…cd75`: all 1,046 files match `c6e90916e` byte for byte (350 in `src`/`include`/`tests`).
- Build and preflight exit 0; the eight targets; GMP/GMPXX linked; `runtimeExecution=false`; five source-status files empty; zero compiler warnings. The record's figures agree.

## RA-120.2 Diff accepted statically against RA-119.4

- TQ only, +22/−24; RP, the header and every other source file are identical to `f082d9aeb`. Widest added line 85 columns.
- The helper matches the specification: no error gives `A5:unexpected-disposition`; otherwise `A5:<code name>`, plus `;site=` when the site is non-empty.
- The five sites are exactly as specified; the two removed `a5Error` declarations had no other use. Message text is unchanged apart from the `;site=` suffix and the two new messages (TQ:6017, TQ:6202–6203). No assertion condition, fixture, selection or control flow changed.
- **Coverage now complete.** Every A5 isolation return carries a site: `MismatchedIsolationEvidence` is returned only at RP:4161 (through `transition_between`) and RP:5262, and `MissingIsolationEvidence` only at RP:4149; all three reach the four side sites or the relation site. All nine A5-ISO rows print it: five through the pipeline failure string, four through the CB22B messages.

## RA-120.3 Residual ambiguity, resolved in the plan rather than by code

`focused30:24` asserts inside a `verify` lambda called for three fixtures (TQ:6191–6193), so one failure line does not name its fixture. The W rows `focused30:20` and `selector:446` build the same witness product through the pipeline path. TB23 P3 therefore predicts exactly one failure carrying the W site, and reports any other count in call order. No CB is warranted: the cross-check is falsifiable without changing a test.

## RA-120.4 Next unit — `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST` (Test + Benchmark, artifact-only)

Plan: `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`. It holds the package identity, the sixteen rows with fixture and output path, the ledger columns, P1–P5, the falsifiers, and the pre-registered routing to H-ISO-1/2/3 (RA-117.3) for TB23-REV.

## RA-120.5 Unchanged and sequence

66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497 frozen, TB21 candidate 449/497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended. CB22 + CB22A + CB22B form one statically accepted diagnostic unit; none of it is runtime evidence until TB23.

Sequence: **TB23** → TB23-REV → DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.

Closed by RA-121 (`Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md`): TB23 reviewed; CB23 seam-face measurement next.
