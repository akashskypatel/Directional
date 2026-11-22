# TB-REV-163 — independent staged uncut-owner census review (2026-11-22 UTC)

> **Continued after handover:** [adversarial record](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md) (Y1–Y7). It resolves REV163-O1 by realignment: orbits {6}/{12} are proved, the root cause is site C over-recording nested chords, and the exact CB-181/CB-182 are frozen. The successor is CB-181.

## Situation and verdict

**TB163 immutable full gate independently VERIFIED: 979/979 PASS. Accepted CP2 prefix: 491/491 PASS. Typed STOP on owner repair.** The exact predeclared R-a and H5 predicates are both absent from the new evidence. This review does not authorize an owner-repair helper, wiring, or production/selector promotion. Its source-backed decision remains a **REVIEW_BLOCKER**: an oriented source-edge-side owner must be proved, not selected by preference.

## Background and immutable identity

- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open, draft and unmerged at review entry. Current turn `M6-CP3-TB-REV-163-P13-STAGED-UNCUT-OWNER-CENSUS-RECEIPT-FULL-GATE`.
- Source under test: `23d66f60d87329e178d9fc3963489cbef088555e`; test-only CB-180 package `14749353214` from compile run `45010876980`, ZIP SHA-256 `fdcba4479936b7e8b1d3ee955bd1ac069715f4fa513ec874bc4e535a8872a668`. No build or runtime was initiated in this independent review.
- TB163 full gate run `45012486246`, result artifact `14750681733`, ZIP SHA-256 `ed9112f827ae22cea3f80fb32e32594d6a332da30946e0c6fded00e0ae56461e`; TB162 independent reference artifact `14746794132`, ZIP SHA-256 `92c4420abe82ed0dae8476de609454f89fcf8a86f2846bb219d53516f78e64e2`.
- Frozen 979-row case manifest SHA-256 `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a`. The 1060-member gate membership is byte-identical. The last accepted CP2 selector is **491/491**; the test-ledger prefix (`binary|test|verdict` joined with newline) has independent SHA-256 `ae566a563f5b07f57f353c5a603153617938fd0ebc5f7532e314078470399057`. This derived hash is not a substitute for the frozen selector-file hash.

## Independent archive and runtime-record checks

Downloaded both immutable artifacts and verified their complete outer ZIP hashes; both internal `SHA256SUMS` inventories have **1966/1966 valid entries**. In both, the 979-row ledger matches each exact raw test-log hash; all rows are PASS with zero abnormal, RED, missing, skipped or duplicate rows. The execution boundaries declare no configure, compile, relink or benchmark run, and successful postflight. Both contain 1060 identical membership identities. All non-hash ledger fields compare equal, 979/979. Exactly **755/979** raw logs are byte-identical; all **979/979** normalize to equality with only frozen N1 elapsed-time and N2 line-ending normalization (N3 reordering was not required). All 1750 `region_support_projection` N3 records occur in each artifact. The first 978 rows have zero changed evidence under the normalization.

Row 979 preserves all **60** prior `SphereStaged*` TB162 lines verbatim and in the same order and adds exactly **48** allowed lines: two `SphereStagedUncutCensus`, sixteen `SphereStagedUncutBoundary`, thirty `SphereStagedArc`, no `SphereStagedUncutInteriorArc`, and no `SphereStagedUncutVertexTransit`. All 48 lines match the retained [verbatim TB163 receipt](evidence/Architecture_M6_CP3_TB163_P13_Staged_Uncut_Owner_Census_Receipt_Raw_20261122.txt). The independently rerun archive comparator is available as a review-local script; no test binary ran.

The three-case production census was not rerun: TB161 artifact `14741883606` remains its last evidence (Cylinder PASS, BunnyRandom and Vase expected RED). The staged cut graph's embedded χ2 does not certify source-face ownership; its staged plan still stops with `UncutFaceComponentOrbitSeedNotUnique` at source face `2-5-12`. Production sphere still stops at `CutSearchExhaustedBeforeCellularity`, with `sourceFaceCellularity=0`.

## Re-derived component and boundary classification

For component 1, exact census `faces=8 status=1 boundaryEdges=8 interiorArcs=0 vertexTransits=0 seedAttributions=0 truncated=0`; component 5 reports the **same** tuple. Together they contain all 16 unavailable source faces. On **each of their sixteen boundary-edge records**: `barrier=0 class=0 oppositeTraceCut=1 sideOwner=1 status=0`; the opposite face advertises three distinct orbit identifiers and four trace-side records. There is no truncated census. All thirty published arcs are complete; their endpoint nodes do not establish a component-to-chord-side incidence by themselves.

The real source `src/geometry/SurfaceCutGraph.cpp`, function `build_source_face_ownership`, creates separate direct-owner, edge-side-owner and trace-side owner structures. Boundary seed propagation requires a singleton source-backed candidate, not the mere presence of an owner record. The printed `sideOwner=1` in `tests/FieldAlignedCurveNetworkTests.cpp` is derived from **presence/non-emptiness**, not an owner-set cardinality of exactly one. Consequently it cannot prove an admissible singleton orbit or tell which directed side touches the uncut face. The opposite-face `status=0` likewise proves an established owner of the *other* face, not the missing face's owner.

### Exact frozen decision-map audit

| Frozen branch | Necessary exact witness | TB163 actual | Decision |
|---|---|---|---|
| R-a | `barrier=0 oppositeTraceCut=1 sideOwner=0` and exact unique chord-side orbit facing the component | `sideOwner=1` for all 16; no oriented unique candidate identity | **Not demonstrated** |
| H5 boundary | `barrier=1` on **every** boundary edge, supported by shared terminal-slit arc endpoints | `barrier=0` on every edge; shared endpoints alone do not establish the barrier predicate | **Not demonstrated** |
| H5 interior | an interior arc within the component with `forward≠reverse` | both components have zero interior arcs | **Not demonstrated** |
| Otherwise | no satisfied branch | exactly this case | **Typed STOP** |

The known terminal-piece candidate (trace 0 terminal arc `segments=[6,7)` ending at node 1; trace 9 also reaches node 1) is a useful **independent H5 investigation lead**, not a proof that all sixteen boundaries should be barriers. Do not substitute that hint for the map's exact predicate.

## Missing evidence, falsifiers and prohibited operations

**Blocking obligation REV163-O1:** Obtain an orientation-aware, source-entity-attached list of **every** candidate `directOwnersByEdgeSide` / `traceSides` orbit and its multiplicity for each boundary halfedge of uncut components 1 and 5; provide the source-chart and geometric side that faces the component. Prove exactly one consistent orbit per component across all boundary sides, or show the competing alternatives explicitly. Include both positive and negative candidate cases so that dropping the uniqueness guard changes an expected outcome. Distinguish a *missing edge-side recording rule* from a *trace-side fan / terminal-slit classification error* without guessing. The source decision on `terminalSlit && !separatesCertifiedFaces` needs its own directed separating-side predicate with the actual component incidence, not only shared terminal nodes.

**Stop rules:** two admissible orbits, zero admissible orbits, incompatible sheet/component, source-arc ambiguity, or lack of an oriented incidence witness must remain a typed rejection. Do not choose first/lowest orbit, change owner defaults, loosen `proves_cellularity()`, alter `GlobalTopologyPlan` validation, accept partial product, promote selector/497/D0/H4, change production activation, reinterpret no-interior-arc as proof of a barrier, or change tested source in a Review turn. Preserve all 103 crossed and 73 established face owners and every prior 60-line row979 receipt.

**Carry:** TB-REV-162 X1–X6 (X2 withdrawn prose remains withdrawn; X4 remains an unproved H5 lead), TB-REV-161 W6–W8, TB-REV-160 V3–V11 (including V3b), TB-REV-159-U3, RA-281 F1–F3, RA-275 S4a, sphere output χ+4 and four unowned contacts, R1 and O48/O49, prior six-part component census. H2 label-artifact alternative is not proved; H3/H4 were excluded for this fixture. No new stable regression event: **66 events / 17 categories / 49 recurrences**, witness debt **1**, deferred **81**, CP2 491/491 accepted, CP3 497 identities unaccepted.

## Recommendation and turn authority

**Do not freeze CB-181 or CB-182 from this evidence.** The existing conditional sequence has no authorized owner-repair branch. The next action is a review/definition decision supplying REV163-O1's missing oriented singleton / separation proof under the current authority, not implementation or an automatic successor. Record a typed review stop and keep the canonical review turn. No code, tests, workflow, manifest or selector changed in this review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491/491 ledger identity prefix SHA-256 `ae566a563f5b07f57f353c5a603153617938fd0ebc5f7532e314078470399057`; no selector mutation; authoritative frozen manifest SHA `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a`. |
| Decisive claims independently re-derived | Both 1966-item ZIP internal hashes, 979 ledger/raw hashes per archive, 979 normalized log comparisons, 48 new / 60 retained row-979 lines, 16 boundary records, source owner-seeding conditions. |
| Non-vacuity checked | All component boundaries exist (8 each) and both R-a and H5 discriminators are explicitly false; gate would fail for changed ledger, omitted line, unmatched checksum or first 978 evidence. |
| Prior obligations discharged/carried | TB163 immutable gate obligation discharged; X1–X6, W6–W8, V3–V11, U3 and related product obligations carried under REV163-O1 / existing owners. |
| Stable accounting | 66/17/49, debt 1, deferred 81, accepted CP2 491/491; CP3/497/D0/H4 unpromoted. |
| New candidates/obligations recorded | REV163-O1 non-stable evidence gap; root/falsifier/owner/prohibitions added to regression tracker and TODO. |
| ORIENTATION currency line | TB-REV-163, 2026-11-22 UTC, typed STOP. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 updated; §4 current TB163 witness added without altering older witnesses; §7 stale CB-180 next removed; §8 records presence-versus-unique semantic pattern. |
| CHANGELOG | This review, independent evidence and STOP recorded. |
| ROADMAP | n/a: no checkpoint, gate, selector or milestone changed. |
| Selector manifest | n/a: no selector accepted, changed or promoted. |
| LESSONS | Existing single-writer and non-vacuous evidence rules applied; no new generalized lesson. |
| Consolidation under CLEAN_UP_POLICY | n/a during source-evidence STOP: current TB163 receipt and TB-REV-162 adversarial decision map remain necessary, not obsolete; no deletion of recoverable history. |
| Successor frozen | n/a under the exact prior decision map's **typed STOP**: neither conditional CB-181 nor CB-182 is authorized; successor remains UNKNOWN until REV163-O1 proof. |
| Turn boundary held | Yes: read-only review; no tests or build run, no product/source/test/selector/workflow mutation. |
| review_check.py boundary | Local offline snapshot check: product/test/fixture/build and selector boundaries PASS; historical ancestor and durable rewrite source checks FAIL because this review-only `git init` has no original Git history. Do not claim a complete boundary gate PASS. |
| `STATUS` lifecycle maintained | Entered same canonical TB-REV-163 review; final review blocker/status beacon must match this record's typed STOP; no successor work. |
| Pushed to origin, branch in sync | Not yet established at review draft; requires verified remote patch application. If transport fails, this row remains unresolved and turn continues. |
