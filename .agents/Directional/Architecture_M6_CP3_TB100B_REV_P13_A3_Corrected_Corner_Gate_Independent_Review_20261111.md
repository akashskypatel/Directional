# TB100B corrected boundary-field corners — independent Review (2026-11-11 UTC)

## Situation

**MATCH, limited to the corrected CB119B test gate.** The immutable 938-row gate is green. This is not CP3 acceptance, a production switch, or evidence that BunnyRandom/Vase are repaired. The original TB100 row-938 RED was an unpromoted test-oracle defect. This Review is runtime-free and changes no code, tests, selectors, fixtures, workflows, or benchmark inputs.

## Background and frozen authority

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft/unmerged PR #8. Independent source snapshot `71e567e6b2085c8abcc017ec3447aa1e4e926a98`, [run 42986263182](https://github.com/akashskypatel/Directional/actions/runs/42986263182), source ZIP artifact `13838799157`, ZIP SHA-256 `24360f5641afbebd00a98314d075232b6ff0aa82f59dae55fdd24c1a8065c34a`, unpacked file SHA-256 **5,451/5,451 verified**. This snapshot was created after the Review entry STATUS and contains no semantic-source change from the CB119B gate.
- CB119B compiled source `d47b7c24b11cfb568d4ffce971590b8e5f966dc4`, compiled artifact `13826405755`; unchanged [TB100B report](Architecture_M6_CP3_TB100B_P13_A3_Boundary_Field_Corners_Corrected_Gate_Execution_Report_20261111.md).
- [Corrected gate 42958701539](https://github.com/akashskypatel/Directional/actions/runs/42958701539), artifact `13828258166`, outer ZIP SHA-256 `29f63afec634b08a1e708457ef6b2f97e887b50bc595ba16551cb2510e4a8247`; 1,884/1,884 embedded file hashes verified.
- [Corrected census 42958806101](https://github.com/akashskypatel/Directional/actions/runs/42958806101), artifact `13828198354`, ZIP SHA-256 `8b1d00f279eed7ea9af6fd89dcf6ee14cf1a2b608dfe2790bbd004d20cfce390`; 9/9 embedded hashes verified.
- Historical TB100 gate artifact `13817910944`, ZIP SHA-256 `11178b67745aa3130391eba69c1ef6c680343ace3d834dc2422e621a5cf58604`; historical census artifact `13817628224`, ZIP SHA-256 `d1c6ef75300439e808d8a245f547a02f1bece4947e37b987f584c0864b4b9927`.

## Assessment — independently re-derived

1. Corrected gate execution boundary reports 938 planned, 938 executed, 938 passed, zero skipped/missing/duplicate/control-bad and exit 0. Membership is 1,019. Postflight is true; configure, compile, relink, and benchmark are false. The original gate had 937 PASS and exactly row 938 RED. The first 936 inherited results and all 937 rows before the corrected row are unchanged in the compared machine-readable ledger fields; no inherited regression was hidden by the correction.
2. Gate and census raw diagnostic comparisons to the original TB100 artifacts: all **seven** `platform-digest` and **seven** `a3-coverage` records are byte-identical; all **four** `d4-rim` records are byte-identical; both `FIELD_CORNER_RECEIPT` records are byte-identical. Receipts: rail `corners=12 passThroughRimNodes=12 sideStarts=12 rimSideStarts=8`; plain `corners=8 passThroughRimNodes=16 sideStarts=8 rimSideStarts=8`. No empty-record/vacuous equality is accepted.
3. In `tests/SurfaceCellsPhase10Tests.cpp`, the corrected row-938 oracle separately constructs hard-feature edges `(1,4),(4,7),(10,13),(13,16)`; derives source-boundary endpoints `(1, 7, 10, 16)`; checks those edges exactly against non-traversable `HardFeature` atlas barriers; and unions the endpoints with the eight original geometric rim corners `(0, 2, 6, 8, 9, 11, 15, 17)`. The source test requires the full corner set, the plain no-feature set, both source-face row orders, and a separate restricted rim pass-through/side-start agreement. Each check can fail independently if the producer or barrier interpretation is wrong. `FieldTransportAtlas.cpp` makes hard-feature crossings non-traversable; `SurfaceCellTracing.cpp` generates only source-boundary corner identities.
4. Original row 938 expected eight geometric corners on hard-rail input while the source/barrier contract required twelve including `(1, 7, 10, 16)`. The prior test expectation, not a proved product defect, caused that RED. The correction changes test authority at CB119B and leaves implementation untouched. The plain control and both input orders rule out a hardcoded one-order or unconditional 12-corner oracle.
5. Three-case census: Cylinder PASS; BunnyRandom and Vase still registered RED at the same prior acceptance site. No new production error class or improved production success is inferred. CP2 accepted 491/491; stable 66 events / 17 categories / 49 recurrences; debt 1; deferred 81. CP3, selector497 and production D5/D4 switch remain unpromoted.

## Remaining obligations and next bounded turn

- **O38:** source-boundary corner product is defined and unwired. **Owner** next `M6-CP3-CB120A-P13-A3-FIELD-CORNER-STOP-NODES`: add only the field-corner source to the stop-node helper, leave producer/factory and selector code unchanged. The pre-declared falsifiers are: the new stop-node set differs from the independently derived union; a hard-feature rim endpoint disappears; an off-rim feature point enters the stop set; pass-through rim nodes become corner stops; face-row reversal changes the canonical stop identities; inherited stop/side behavior changes without a named contract. **Stop** on any violation or unsupported source identity; do not paper over it in a test. Compile-only CB followed by distinct artifact-only `M6-CP3-TB101A-P13-A3-FIELD-CORNER-STOP-NODES-EXEC` and its gate.
- **O39:** near-tie boundary branch decisions still use floating-point classification. **Owner** separate Review definition and subsequent distinct Code + Build and Test + Benchmark before O36. Do not claim exact topology or certified fallback from this corrected fixture.
- **O34/O35/O37/O36/D6:** unchanged; retain their current owners and stop rules. O36 production switch requires prior O39 and separately validated production chain and stop/factory/census stages. No successor beyond the one bounded CB120A turn is authorized here.
- **New stable event:** none. Historical TB100 oracle candidate remains non-stable and is now corrected by the unpromoted TB100B test. No change to regression totals. See `Regression_Root_Cause_Tracker.md`.

## Verification limits and workflow discipline

Local `review_check.py boundary` was invoked against the source snapshot, but it returned **exit 1**: the downloaded snapshot contains no `.git` history, so its Git-ancestry assertions cannot be established locally. This is not a product or gate failure and is **not** reported as a passing boundary check. A full-history repository validation remains unverified. During start-up, direct document reads were made before the mandatory snapshot pre-read gate was selected; later inspection used one verified snapshot. Record this conservation-policy miss rather than normalizing it. Existing document drift audit flags the handoff and orientation length as pre-existing bloat. Do not weaken those audits.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB100B gate manifest unchanged from TB100, SHA-256 `2df4bd96ee8a52323ffa4f07292e37a3b6e4aedd6424fb9dc68e805da2cbc24c` for 938 rows; historical 936-row TB99 prefix byte-identical to TB100 (SHA-256 `c137e3f81c75e94ed9596c59b3065e535bd678c05de178501b60923563249d2d`); selector497 itself unchanged/unpromoted. |
| Decisive claims independently re-derived | Machine-readable 938/938 ledger, corrected-versus-original 937-row identity, exact checksum sets, raw record comparisons, source/atlas corner-oracle path. |
| Non-vacuity checked | Positive rail and plain cases; all 12 rail corners, independent 4 barrier endpoints, 8 geometric corners, forward/reverse, separate scoped side check; negative guards can fail. |
| Prior obligations discharged/carried | Old row-938 oracle corrected/discharged for this fixture; O38 moves to CB120A; O39 and O34/O35/O36/O37/D6 carried without scope change. |
| Stable accounting | Accepted CP2 491/491, 66 events / 17 categories / 49 recurrences; debt 1; deferred 81; CP3 and selector497 unpromoted. |
| New candidates/obligations recorded | No new stable category; existing TB100 non-stable test-oracle candidate disposition updated in Regression_Root_Cause_Tracker. |
| ORIENTATION currency line | Updated to this Review, 2026-11-11. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 current gate/successor; §4 no witness changed; §8 existing test-oracle defect pattern, no new category. |
| CHANGELOG | One entry for TB100B Review. |
| ROADMAP | n/a: no checkpoint advanced. |
| Selector manifest | n/a: no accepted selector added or changed. |
| LESSONS | Existing oracle-nonvacuity lessons apply; no new general defect pattern. |
| Consolidation under CLEAN_UP_POLICY | n/a for safe deletions: current TB100B gate, prior independent TB100 source-adjudication, and adversarial audit retain different source-grounded facts and are all referenced as evidence; no fact-free obsolete document can be established from this snapshot without loss. No silent deletions. |
| Successor frozen | `M6-CP3-CB120A-P13-A3-FIELD-CORNER-STOP-NODES` only; falsifiers and stop rules specified above. |
| Turn boundary held | Review was read-only with respect to source, tests, manifests, selectors, workflows; no new runtime or build. |
| review_check.py boundary | Exit 1 in gitless source snapshot; full-history Git ancestry check not established, explicitly unresolved. |
| `STATUS` lifecycle maintained | Entry written for this Review with Started at `2026-11-11T08:19:22Z`; final beacon must match the published closeout disposition. |
| Pushed to origin, branch in sync | Verified the applied review report and updated TODO from the working GitHub branch after successful Drive patch workflow 42987458768; remote PR #8 remained open and draft. A local `git status -sb` with genuine branch history was unavailable from the gitless source snapshot; no false local-sync claim is made. |

## Owner-requested adversarial re-review — technical corrections (2026-11-11)

### Situation

**Prior narrow gate verdict stands; the prior Review is INCOMPLETE as an architectural acceptance.** The corrected 938/938 result establishes only that the two test inputs satisfy their current assertions. It does not establish general source-boundary corner correctness, fan identity, or certified consumer behavior. The revised implementation turn below is authorized for a small helper-only change, not for wiring the product into production. This addendum supersedes conflicting falsifiers in the earlier Review closeout and handoff.

### Background — source evidence

- `src/geometry/GlobalConformityBaselineSupport.cpp:482-505` already inserts **both endpoints of every hard-feature edge** into the stop set. A rule that rejects an off-rim hard-feature endpoint as a stop is false. The new `fieldCornerVertices` source must add stops; it must never remove this existing stop reason.
- `src/geometry/SurfaceCellTracing.cpp:21582-21654` emits source **vertex IDs**, not field-chart or local-sheet IDs, for every boundary fan that turns, is undecidable, or crosses a nontraversable edge. `GlobalConformityBaselineSupport.cpp:499-504` maps a source vertex to **every network node** with that vertex. This is correct only if all such nodes are valid stop owners or source-vertex uniqueness across the accepted fan/sheet domain is established. That identity condition is **not proved** by the two current gate fixtures.
- `tests/SurfaceCellsPhase10Tests.cpp:8308-8438` asserts two face-row orders, a simple triangular field example and a rectangular hard-rail fixture. Its pass-through comparison reduces node identities to a **set of source vertex indices**. This can hide a node-per-chart or local-sheet disagreement. No tested case independently combines a nonzero transported quarter-turn with a geometrically straight pass-through source rim and no hard-feature barrier.
- `src/geometry/SurfaceCellTracing.cpp:21541-21576` and `:16700-16753` duplicate the same floating-point field-branch comparison. `DESIGN.md` Amendment 18 forbids topology decisions based on an uncertified floating-point derivation. The current helper's optional null atlas uses principal matching rather than required A1 authority; that path is test ingress, **not production certification**.
- `src/geometry/SurfaceCellTracing.cpp:21606-21650` collapses an undecided edge, a nontraversable A1 barrier and an invalid fan transport into a simple stop/no-stop result. This is an acceptable conservative **stop request** in the current isolated test, not an independently verified reason that the bounded-disk producer can succeed. A future certified consumer must distinguish an intentional barrier from missing/invalid required transport and must not turn the latter into silent success.

### Assessment — corrected findings and test meaning

**A1, critical: two prior falsifiers contradict the source contract.** The phrases "an off-rim feature endpoint becomes a stop" and "a pass-through rim node is added" must not be applied without a qualifier. Both may be *required*: an off-rim hard-feature endpoint already stops, and an otherwise pass-through rim node must start a new chain when it is in the field-corner source. A test implementing either blanket prohibition would weaken correctness while remaining green for the wrong reason.

**A2, high: set equality is narrower than chart-safe correctness.** A correct eight/twelve-vertex result does not prove node-per-fan or sheet separation. Treat duplicate source-vertex owners as an unresolved identity question; do not assume a defect is proven on the accepted mesh class. Before any production consumption, either prove a unique admissible node mapping for the relevant charts or introduce chart/sheet-qualified stop ownership at the authoritative stage. Reuse existing source-chart authority; do not introduce speculative new identity types for the helper turn.

**A3, high: missing independent field-transport coverage.** The 938-case gate is a valid regression gate, but neither named fixture forces a geometrically straight source-rim pass-through vertex to become a corner solely because of a known nontrivial transported quarter-turn. A later focused test must use independent A1 transport expectations, both row permutations, vertex/edge orientation variants when valid, and a negative same-branch control. Compare node ownership, not only source-vertex sets. Do not modify the immutable accepted TB100B manifest retroactively.

**A4, high: no certified shared branch owner.** The source product and the bounded-disk producer each choose branches. The algorithm can drift under a rule change even if the present output matches. O39 must define exact input authority and one writer, including what can be certified from conditioned exact field data. Converting a previously normalized floating-point direction to a rational just before comparison does **not** meet Amendment 18. Separate definition and code/build/test turns are required before O36.

**A5, medium: an additive helper cannot prove a production switch.** CB120A can establish precisely the stop-set union from known inputs, and TB101A can test that assertion. CB120B can establish factory forwarding, TB101B the forwarded chain split; CB120C/TB101C can establish a census. None alone certifies the source product at every fan, its publication through A1/A3, or production success. Current Cylinder PASS, BunnyRandom and Vase RED remain unchanged; CP2 and the stable regression ledger must remain frozen.

### Recommendation — narrow, ordered work with independent gates

| Order | Turn | Scope and independently failing gate |
|---|---|---|
| NEXT | `M6-CP3-CB120A-P13-A3-FIELD-CORNER-STOP-NODES` | Code + Build. Change only `GlobalConformityBaselineSupport.{h,cpp}` and its focused `GlobalConformityBaselineTests.cpp` test. The result equals **old stops UNION nodes whose source vertex is a declared field corner**, including pass-through field corners; old off-rim hard-feature endpoint stops must remain. An unrelated off-rim node must not be added solely by the new source. Verify missing vertex IDs, duplicates and permutation invariance; compile only, no factory or production change. |
| 2 | `M6-CP3-TB101A-P13-A3-FIELD-CORNER-STOP-NODES-EXEC` | Artifact-only focused execution on the exact CB120A package. Require positive added pass-through stop and all inherited old stop causes; mismatch routes to Review, not to factory. |
| 3 | `M6-CP3-CB120B-P13-A3-FIELD-CORNER-FACTORY-FORWARDING` | Code + Build. Forward the product through the **unwired** chained-input factory; add only focused factory regression. No A1/pipeline publication. |
| 4 | `M6-CP3-TB101B-P13-A3-FIELD-CORNER-FACTORY-EXEC` | Artifact-only. Confirm chain splits exactly at the injected corner and existing chains remain unchanged when the corner is already a stop. |
| 5 | `M6-CP3-CB120C-P13-A3-FIELD-CORNER-CENSUS` | Code + Build. Add only the diagnostic census assertions/receipts; preserve prior rim records. |
| 6 | `M6-CP3-TB101C-P13-A3-FIELD-CORNER-STOPS-FULL-GATE-EXEC` | Artifact-only original frozen 940-row gate plus census, with independent receipt comparison; treat full-gate PASS as regression stability, not source/production certification. |
| 7 | `M6-CP3-TB101C-P13-A3-FIELD-CORNER-STOPS-FULL-GATE-REV` | Independent Review of identity/fan falsifiers and the full-gate result. No production switch. |
| 8 | **Review only**: `M6-CP3-DEFN-P13-A3-BOUNDARY-FAN-STOP-IDENTITY` | Decide from existing A0/A1 contracts whether source-vertex-only stops can affect another local sheet/fan; freeze a small independent fixture and failure behavior. Do not assume new identity structure is required. |
| 9 | **Review only**: `M6-CP3-DEFN-P13-A3-EXACT-BOUNDARY-BRANCH-OWNER` | Define the exact/certified branch input and a single-writer producer/product path under Amendment 18. Decompose any resulting implementation into **one producer/consumer concern per Code + Build and a separate artifact-only test turn**. O39 and O34/O35/O37 remain pre-O36 requirements. |

All turns are conditional on the preceding acceptance gate. No successor after the named NEXT is entered in this Review. The historical one-shot CB120 patch and 940-case manifest are reference evidence only; do not apply CB120 wholesale or rewrite accepted TB100B results. Keep PR #8 draft/unmerged and selectors unchanged.

### Review verification

Verified with the immutable `b4fee1c9dbbf91dd2a8aa96870f3ae3b988d1c54` source snapshot, workflow `42990207237`, SHA-256 `e24bc46ed24e62e8908f049b2b87ab3c3ee22b6c1abf6927d8e788bbb914df29`, **5,452/5,452** source file hashes and the existing TB100B gate report. This re-review is static: no compiled tests or benchmarks were run. The 938/938 claim comes from the independently verified earlier gate artifact, not from a new execution. This review adjusts interpretation and future tests, not accepted test evidence or regression totals.
