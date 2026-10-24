# TB34-REV — independent cycle-transport locus and fixture ownership decision (2026-10-24)

**Canonical turn:** `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST-REV`. **Decision: ACCEPT the TB34 diagnostic measurement; classify selector189–195 as one shared INVALID TEST FIXTURE A3 input, not a demonstrated A3 producer bug.** No formerly RED identity is marked recovered, and no Direct SurfaceCells acceptance is claimed. The first A3 rejection is appropriate for the field supplied by the current helper.

## Primary immutable evidence independently re-opened

- Parsed the actual downloaded result artifact `12558378347`, independently verified all **17/17** recorded `SHA256SUMS` and all twelve row-level log hashes, joined twelve exact distinct tests against the frozen local manifest (SHA-256 `c8782727bcf15c234ba50070284b9d6965eb339b956b7bdbffd3fd3f35bc6cff`); no duplicate, skip, missing or invalid process.
- **Seven actual RED logs:** selectors189–195 each run exactly one GoogleTest, exit 1, report first exception `periodic-route fixture source A3 unavailable;code=CycleTransportMismatch;topologyRegion=0;site=cycle-transport;cycleRowIndex=0;cycleKind=LocalVertex`. **Five actual PASS logs:** two unchanged atlas tamper guards and three TB33 factory controls, each exactly one test, exit 0. Thus the seven are **one fixture-root family**, not seven independently supported A3 defects. TB34 is 5 PASS / 7 RED.
- Compared the original `tests/SurfaceCellsPhase10Tests.cpp` helper and the actual `benchmarks/fixtures/milestone-g/cylinder.obj` (80 vertices, 128 triangles), `src/authority/FieldTransportAtlas.cpp`, `include/directional/fields/CrossField.h`, and `src/fields/FieldMatching.cpp` from a 5,843-file hash-verified source snapshot at `e11a4cd2fe2b963e7fbb3560ef94712693abb877`. GitHub compare to the review marker commit `0164468a5c2d480c11799c4da07be40caae376b5` contains only the source-snapshot marker and `STATUS`, with no semantic/test changes from the verified CB33 snapshot. No binaries were executed in Review.

## Independent causal derivation — first predicate and owner

1. `balanced_periodic_route_field()` copies `fixture.authoritativeField`, then calls `assign_directed_matching` on only `expectedRoute[0]` and `[1]`, setting directed matches to **+1** and **−1**, respectively. `assign_directed_matching` changes `CrossFieldEdgeTransition::matching` **only**; it does **not** change `effort` or any other incident edge matching. This is exactly the `sourceField` passed into `FieldTransportAtlas::make`, before network construction, for all seven tests (including the negative cases).
2. The committed cylinder fixture independently establishes face0 `(0,1,2)`, face1 `(0,2,3)`, face30 `(30,0,3)` (0-based). The modified interior edges are `(0,2)` (faces0↔1) and `(0,3)` (faces1↔30). The first interior source vertex in sorted local order is global vertex **2**, because vertices0/1 are boundary and vertex2 at z=−0.5 has a closed interior star. Thus the region-local `LocalVertex` row0 genuinely winds around vertex2. That star contains `(0,2)` but **does not** contain `(0,3)`; the other changed edge is incident to vertex3, not vertex2.
3. `FieldTransportAtlas::make` constructs `turningLift` from `(bundle.cycles * raw.effort + 4 * bundle.cycleCurvatures)/(2π)` and independently composes `QuarterTurn::from_integer(raw.matching)` along directed cycle steps. The helper's changed `matching` rotates the vertex2 cycle by **one quarter turn** (sign follows direction); its untouched effort/curvature keep the original turningLift. The S1 comparison therefore fails **modulo 4** for local row0. The two modifications cancel on the chosen 32-step periodic route, but **not** around vertex2/vertex3 local stars. A route-level zero sum is insufficient to make an atlas-admissible cross-field transition system.
4. This is fixture/test-authority invalidity before A4, not proof of an A3 producer defect. The existing S1 rejection is a necessary safety check and must not be bypassed. The preexisting TB34 diagnostic `site` was exercised and correct. The S2 boundary-correction check remains mathematically unreachable in defined arithmetic: it adds only a multiple of four to a lift already checked at S1. Its `cycleRowIndex` uses atlas-global indexing, unlike the region-local S1 row; neither is an observed S2 failure.

## Correction owner and precommitted falsifiers

**Authorize one test-fixture-only Code + Build turn** `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR` using [Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Plan_20261024.md](Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Plan_20261024.md). Construct the nonzero matching example as a *face-gauge coboundary* on the complete star of the intermediate face, not two isolated edge edits. For a chosen gauge `g(face1)=+1`, `g(other faces)=0`, consistently transform every incident interior transition by the directed face-gauge difference; this changes the 0→1 and 1→30 route transitions by +1 and −1 **and the third face1↔32 transition by its required inverse sign**, so closed local cycles telescope. Preserve effort, exact source provenance, reflection/permutation remapping, the unchanged canonical 497 selector, and all seven original positive/negative oracles.

Before claiming the correction, independently establish from *raw source topology* that all local-vertex cycle sums/turningLift residues are consistent and the two 32-step route witnesses still contain nonzero steps and net zero; also prove the original two-edge-only corruption fails S1 and a truly nonzero periodic tracing mutation still rejects with the original typed failure. No disabling/widening validation, synthetic PASS, tautological oracle or change to A3 production logic. A pure gauge transformation is a **proposed** valid fixture construction, not yet compiled or tested; if it fails these independent requirements, stop and return to Review instead of loosening assertions.

**Separate mandatory TB and Review boundaries** follow a successful compile-only package; the next CB may not execute binaries. TB must rerun all seven on the exact packaged artifact in independent fresh processes, both atlas guards, the three factory controls, then the accepted-green and CP3 candidate selector census per the frozen gate. Failure of a specific original assertion remains a real RED to adjudicate, not a reason to rewrite the expected result.

## Non-vacuity, prior obligations and accounting

- The two atlas controls each assert independently that tampered cycle order/typed payloads reject with original codes, and construct a baseline before mutation; they **do not** test the new `site` formatting directly. The three TB33 controls exercise missing gauge, one-face gauge tamper and uniform gauge shift, **not** a positive 32-edge periodic-route witness. Seven first-site REDs exercise S1 formatting but cannot establish later A4 behavior. None is credited as producer success.
- **RA-149.4 / CB33-REV:** correct site/row-kind diagnostic exercised and closed as diagnostic-only. **RA-149.3:** S2 independent-owner premise disproved, kept corrected. **RA-149.5 / TB34:** seven loci measured, first owner now assigned to invalid fixture helper; repair obligation transferred to CB34 and separate immutable TB/REV. **RA-148, RA-146, A3 selector442, A5 focused30:12, 7 untyped producer candidates, three CP3 entry failures, G4-B002/A6** remain open, unaffected.
- CP2 accepted **491/491**; frozen selector497 unchanged, including its exact 449-line accepted prefix; TB32 **481/500 candidate**, 19 inherited RED. Stable **66 events / 17 categories / 49 recurrences**, project debt **1**. RP-01 open, RP-02 unreached, Gate C suspended. No newly accepted production success, no stable regression or new stable event.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Frozen selector449 expected LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; selector was unchanged and no new prefix generated; independent selector byte rehash pending if the exact manifest file is not locally present |
| Decisive claims independently re-derived | 17/17 hashes; 12 row/log hashes; 7× S1 actual logs; committed OBJ face/edge/star; matching vs effort dataflow and S1 modulo-four predicate |
| Non-vacuity checked | Guards reject independent tamper but do not certify periodic route; TB33 controls cannot establish A4 route; seven RED do reach S1 formatter |
| Prior obligations discharged/carried | RA-149.3 corrected, RA-149.4 diagnostic discharged, RA-149.5 measurement discharged / fixture repair to CB34; all other inherited obligations carried |
| Stable accounting | 66/17/49, debt1; CP2 491/491 accepted; TB32 481/500 candidate, 19 inherited RED; selector497 unchanged |
| New candidates/obligations recorded | Fixture-invalidity owner and exact falsifiers in tracker; no new stable event |
| ORIENTATION currency line | TB34-REV 2026-10-24 |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7/§8 updated; §4 unchanged (no new representative witness) |
| CHANGELOG | TB34-REV entry added |
| ROADMAP | n/a: M6-CP3 remains active, no checkpoint movement |
| Selector manifest | n/a: frozen selector497 neither added to nor accepted |
| LESSONS | Existing sections 2/4/5 reused; no new generalized lesson needed |
| Consolidation under CLEAN_UP_POLICY | No obsolete record deleted; no historical facts dropped |
| Successor frozen | `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR`; scope/stop rules in linked plan |
| Turn boundary held | Review-only static calculations and immutable artifact inspection, no tests/builds/product/fixture/selector mutation |
| review_check.py boundary | Pending review static check receipt; review cannot assert test execution |
| `STATUS` lifecycle maintained | New attempt started previously, resumed at 2026-10-24T13:28:19Z; final COMPLETE beacon only after durable publication and cleanup |
| Pushed to origin, branch in sync | Pending verified remote patch application and compare-and-swap closeout |
