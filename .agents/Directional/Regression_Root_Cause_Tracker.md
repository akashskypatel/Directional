## M3-CP4c3-CB12 — barrier-absorbed termination ownership correction — **COMPLETE / COMPILE-PROVED / RUNTIME UNPROVEN / NON-STABLE**

- **Authority:** semantic/evidence source `a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`; compile run/job
  `33581576670 / 100096794713`; immutable package **80** artifact `9828786744`. No Directional runtime executed.
- **Correction:** `BarrierAbsorbed` terminal singularities now own arrivals through their already-created network node,
  while `Emit` remains port-owned. Policy is explicit construction state rather than inferred from an empty port table.
  Missing barrier node fails closed with `SingularityTerminationBarrierAbsorbedNodeMissing`; existing
  `SingularityTerminationPortOwnershipMismatch` semantics remain for Emit.
- **Regression authority:** selector **377** appends exactly
  `ResolvedBranchCorrection.BarrierAbsorbedMechanicalTerminationUsesNetworkNodeWithoutPort`, SHA-256
  `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`; selectors 374/375/376 remain frozen.
- **Candidate disposition:** `M3-CP4c3-TB9-REV-CAND-01` remains **ACTIVE** until TB10 proves the accepted prefix,
  absence of the old condition+seed at ordinal 366, and v36 network-node termination. No stable event is closed by
  compilation alone.
- **Accounting:** **+0 events / +0 recurrences**; totals remain **44 / 14 / 30**, debt **5**; semantic packages
  advance **76 → 77**. Exact next owner: artifact-only `M3-CP4c-3-TB10`.

## M3-CP4c3-TB9-REV - independent review adjudication - **CURRENT REVIEW AUTHORITY / STATIC / NON-STABLE**

- **Record:** `Architecture_M3_CP4c3_TB9_Independent_Review_Record.md`, measures **BC0-BC7** discharged. Static
  only: no runtime, compile, package, or product/test/fixture/selector mutation.
- **BC0 re-established independently.** Source `8033006` is an ancestor of branch HEAD; selectors 374/375/376
  recompute to `d496ce96...c503c4f`, `aa7b22bb...06a8f3a0`, `6ab2d9fa...6234bfa5e8` with 374/375/376 identities.
  **376 = 375 + exactly one appended line** and **375 = 374 + one**, so 374 and 375 remain byte-frozen through
  CB11 (BB6 honoured); the first 365 lines of 376 are byte-identical to accepted selector 365. `git diff 8033006
  HEAD` over `src include tests benchmarks CMakeLists.txt cmake` is **empty**, licensing static review as evidence
  about package 79.
- **BC1 - only one subcondition is reachable, and it means one thing.** Both `VertexHit` constructions
  (`SurfaceCellTracing.cpp:517-523`, `:546-556`) derive the terminal vertex **from** `source_support()` or invert
  its parameter mapping, and `field_aligned_singularity_at` matches by that same vertex - so `vertexSupport` is
  never null and never disagrees with the port's vertex. **Disjuncts 1 and 3 are dead by construction.** The port
  loop runs over **all** atlas singularities with one `continue` on `BarrierAbsorbed`, and `expectedValence` in
  [3,6] is pre-enforced, so **`terminalPort == end()` iff `portPolicy == BarrierAbsorbed`**, which on this closed
  witness means *singular and barrier-incident* (`FieldTransportAtlas.cpp:2296-2300`, `:2467-2470`).
- **BC1 - the witness.** The trace runs from singular corner **v47** down the sharp box edge `(x = -1.4, z = -0.9)`
  through mesh rows 59, 57, 55, 53, 51 and **regular** vertices 45, 43, 41, 39, every chain edge at an exactly
  **90.000000 degree** dihedral, and terminates at **v36**. v38 is excluded: its entire star is coplanar, so it is
  barrier-incident under no positive threshold.
- **BC2 - classified category 1, genuine product ownership defect on a valid witness.** A **port** records where a
  trace may originate; the guard uses it to own an **arrival** and takes the terminal node from
  `terminalPort->node`. A `BarrierAbsorbed` singularity has no ports by design, yet its node is allocated
  **unconditionally** and v36 is additionally a mandatory-barrier endpoint. Owner:
  `src/geometry/SurfaceCellTracing.cpp::append_field_aligned_singularity_termination`.
- **BC3 - CB11 closure confirmed without semantic acceptance.** `M3-CP4c3-TB8-REV-CAND-01` CLOSED. No inference is
  drawn about the unobserved finalize/contact site; TB8-REV's finding there (`terminalContact` never read in
  `:3745-3935`) is **untouched and still open**, and CB12 must not repair it.
- **BC7 - adversarial.** Sharpness is **not** a valid proxy for the barrier set: v47 has three exactly-90 degree
  incident edges and is proved `Emit` by TB9's own trace seed, because barriers are region-restricted
  (`FieldTransportAtlas.cpp:962`). Separately, accepted ordinal **328**'s port-ownership witness is synthetic and
  fires **disjunct 3**, which production cannot reach - so the accepted suite does **not** cover the production
  disjunct.
- **BC6 - one bounded successor frozen:** **`M3-CP4c-3-CB12`** under **BD0-BD9**, product correction.
- **Accounting:** static, on an unaccepted surface, no accepted-green loss. **+0 events / +0 recurrences**; totals
  remain **44 / 14 / 30**, debt **5**, packages **76**.

## M3-CP4c3-TB9-REV-CAND-01 - a barrier-absorbed singularity cannot receive a termination, because the owner is looked up in the port table its policy deliberately leaves empty - **ACTIVE / GATING / PRODUCT / NON-STABLE**

- **Declared at `M3-CP4c-3-TB9-REV`** from static derivation over TB9's runtime evidence.
- **Mechanism.** `append_field_aligned_singularity_termination` resolves the terminal owner as
  `terminalPort->node`, found by `std::find_if` over `candidate.singularityPorts`. That table is built over all
  atlas singularities but **skips `portPolicy == BarrierAbsorbed`** outright. The corresponding node, however, is
  created unconditionally: `nodeVertices.insert(singularity.sourceVertex)` precedes the policy test, and a
  barrier-incident vertex is inserted again by the mandatory-edge loop. The owner exists; the lookup goes through
  the wrong table.
- **Invariant to restore.** Every singularity has exactly one network node and that node owns **every** trace
  terminating at its source vertex. A port constrains only a trace's **origin** and is never a precondition on an
  arrival. `BarrierAbsorbed` must still be able to receive terminations.
- **CB12 build status:** BD1–BD5 are implemented and compile-proved at source `a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`; immutable package 80 is frozen. Runtime closure is not claimed.
- **Owner:** artifact-only **`M3-CP4c-3-TB10`**, under the five BD9 discriminators.
- **Accounting:** gating on an unaccepted CP4c-3 surface. **+0 events / +0 recurrences**; totals remain
  **44 / 14 / 30**, debt **5**, packages **77**.

## M3-CP4c3-TB9 — artifact-only site discrimination — **COMPLETE / VALID SEMANTIC RED / NON-STABLE**

- **Authority:** package 79 / semantic source `803300698289e0d0f629eaa878add1aebc7193c1`; run/job
  `33575920177 / 100079784804`; result artifact `9826689980`
  (`abea3172c6515bbf5b6fdede5abe96ae6086724299d014201ce3ff020016b68d`); log artifact `9826690247`
  (`c92be7d59ecfb963eb225099737ed99efcb169244bfaa4c9519a1a98967cd648`).
- **Gate:** ordinals **1–365 PASS**; ordinal **366 RED** at unchanged coarse
  `InvalidNetworkTerminalOwnership;sourceEdge=36-38;sourceFace=36,38,39;branch=2`, now with exactly one typed
  condition: **`SingularityTerminationPortOwnershipMismatch`**. Trace seed is vertex **47** / singularity **5**;
  five exact branch-2 history rows are published and untruncated. This selects the singularity-termination site and
  excludes the finalize/contact fall-through as this emitter.
- **Published-face honesty:** `publishedFaceCount` is gone; no `publishedFaces` token appears because the actual
  published-face collection is empty under the CB11 sparse renderer.
- **Remainder:** ordinals 367–375 report-only = **2 PASS / 7 RED**. 367/371/372 share the mechanical ownership
  blocker; 368 sphere, 369 saturation, 370 empty-network, and 374 folded-cone dispositions are unchanged; 373/375
  pass. Diagnostic **376 PASSes**, runtime-proving the production condition/trace projection.
- **Immutable boundary:** pre/postflight PASS; no configure/compile/relink/repair/generated discovery/product/test/
  fixture/selector mutation or benchmark.
- **Accounting:** accepted authority stays **365/365**, CP4c-3 remains unaccepted; **+0 events / +0 recurrences**.
  Totals remain **44 / 14 / 30**, debt **5**, semantic packages **76**.
- **Owner:** independent `M3-CP4c-3-TB9-REV`; no unchanged TB retry or semantic correction before review.

## M3-CP4c3-CB11 — diagnostic production-projection correction — **COMPLETE / COMPILE-PROVED / NON-STABLE**

- **Authority:** final semantic/evidence source `803300698289e0d0f629eaa878add1aebc7193c1`; compile run/job
  `33573956609 / 100073749252`; immutable package 79 artifact `9826005253`. No Directional runtime executed.
- **Correction:** the production failure DTO/renderer now preserves the trace-scoped diagnostic group, exact values,
  published edge/face authority, and a typed condition distinguishing all twelve `InvalidNetworkTerminalOwnership`
  emission conditions. Bounded trace history has explicit count/truncation state. Ordinal 329 now covers the
  production projection, and diagnostic identity 376 targets the production failure path.
- **No semantic fix:** CB11 does not change `field_aligned_first_trace_contact`, finalization control flow, ownership,
  port policy, barrier derivation, fixture bytes, or acceptance semantics. The `terminalContact` fall-through remains
  present for TB9 to discriminate.
- **Disposition:** `M3-CP4c3-TB8-REV-CAND-01` closes at implementation/build scope. Runtime proof of the new projection
  is deferred to TB9 identity 376. `M3-CP4c3-TB8-CAND-01` remains active/gating until ordinal 366 names one site.
- **Accounting:** no runtime event and no accepted-green loss; **+0 events / +0 recurrences**. Totals remain
  **44 / 14 / 30**, debt **5**, semantic packages **76**.

## M3-CP4c3-TB8-REV — independent review adjudication — **CURRENT REVIEW AUTHORITY / STATIC / NON-STABLE**

- **Record:** `Architecture_M3_CP4c3_TB8_Independent_Review_Record.md`, measures **BA0-BA7** discharged. Static only:
  no runtime, compile, package, or product/test/fixture/selector mutation.
- **BA0 re-established independently.** Semantic source `e2b5929` exists and is an ancestor of branch HEAD; selector
  374 LF SHA-256 recomputes to `d496ce96...c503c4f` and selector 375 to `aa7b22bb...06a8f3a0`; 374 has 374 identities
  and 375 has 375; ordinals 366 and 367-375 match the TB8 report line for line. Three results TB8 does not assert:
  **375 = 374 + exactly one appended line** (no reordering, so 374 is byte-frozen through CB10); 374's hash is
  asserted identically in the CB9 report, TB7 plan/report/review, CB10 report and TB8 plan/report - five consecutive
  turns; and **the first 365 lines of selector 375 are byte-identical to accepted selector 365**. Finally,
  `git diff e2b5929 HEAD -- src include tests benchmarks CMakeLists.txt cmake` is **empty**, which is what licenses
  static review of the working tree as evidence about package 78.
- **BA1 - the locus reduces to two sites and no further.** `InvalidNetworkTerminalOwnership` has **twelve** emission
  sites in `SurfaceCellTracing.cpp`. Eight cannot populate `sourceEdge` + `sourceFace` + `branch` together; `:3132`
  and `:3879` require the emitted edge to be a `terminalBarrier`, and edge `36-38` has an **exactly 0 degree
  dihedral** between two identical-normal faces inside a 50-face coplanar patch at `x = -1.4`, so it is not a hard
  feature edge and can never be one. Survivors: **`:1900`** (singularity-termination port ownership; the live
  disjunct is a `BarrierAbsorbed` singularity contributing no ports) and **`:3920`** (the
  `finalize_field_aligned_events` fall-through - `terminalContact` is **never read** in `:3745-3935`, and
  `field_aligned_first_trace_contact` can never match trace index 0). They emit the **identical** rendered locus.
- **BA2 - classified category 3, diagnostic insufficiency, over a proved two-element set.** The rendered line also
  proves by field order that `sourceVertex`, `topologyRegion` and `vertexArrivalMode` were all empty and that
  `vertexTransitStates` / `vertexStarTransit` were empty - so ordinal 366 is **not** a vertex-star transit failure.
  `publishedFaceCount=0` is uninformative: `FieldAlignedCurveNetworkError::publishedFaces` is declared and **never
  assigned anywhere**.
- **BA3 - CB10's corrections separated and one TB8 claim corrected.** `M3-CP4c3-TB7-CAND-01` CLOSED (ordinal 366
  clears vertex 11 on the production path; diagnostic 375 elects one owner in **both** radial orientations,
  including the one CB9 rejected). `M3-CP4c3-TB7-REV-CAND-01` CLOSED - **verdict confirmed on different evidence**:
  the closure holds because CB10 added the `vertexStar*` / `vertexTransitState[...]` reader to
  `append_cp4c_failure_locus`, **not** because 328/329/375 exercise it. All three are unit-level synthetic
  identities against the test-local renderer; **no identity in selector 375 exercises the production projection**.
- **BA6 - one bounded successor frozen:** **`M3-CP4c-3-CB11`** under **BB0-BB9**, **diagnostic-only**.
- **Accounting:** static, on an unaccepted surface, no accepted-green loss. **+0 events / +0 recurrences**; totals
  remain **44 / 14 / 30**, debt **5**, packages **75**.

## M3-CP4c3-TB8-REV-CAND-01 - trace-scoped diagnostics were dropped by production projection and the losslessness identity targeted the wrong renderer - **CLOSED / RUNTIME PROVED / NON-STABLE**

- **Declared at `M3-CP4c-3-TB8-REV`; corrected by `M3-CP4c-3-CB11`.** The review proved that the trace-scoped
  `FieldAlignedCurveNetworkError` fields had no production DTO counterpart/reader and that accepted ordinal 329
  asserted only against the test-local `network_error_locus`.
- **CB11 correction:** `SurfaceCellFailureLocusDiagnostics`, `network_failure_locus`, and
  `append_cp4c_failure_locus` now preserve/render the missing trace-scoped fields, exact values, `publishedEdges`,
  and honest `publishedFaces`; all twelve terminal-ownership emission conditions carry a typed condition. The
  production-path losslessness identity and two surviving-site witnesses compile in the authoritative test targets.
- **Build proof:** exact source `803300698289e0d0f629eaa878add1aebc7193c1` compiled all required targets with
  GMP/GMPXX in run/job `33573956609 / 100073749252`. Package 79 preserves selector 376 and the production binaries.
- **Runtime proof:** TB9 ordinal 366 publishes exactly `networkErrorCondition=SingularityTerminationPortOwnershipMismatch` plus seed vertex 47 / singularity 5 and bounded exact history through the production renderer; diagnostic identity 376 PASSes in a fresh process. The projection/discriminator gap is therefore runtime-closed.
- **Accounting:** runtime closure is on an unaccepted surface with no accepted-green loss. **+0 events / +0 recurrences**; totals remain **44 / 14 / 30**, debt **5**, packages **76**.

## M3-CP4c3-TB8 — artifact-only semantic disposition — **COMPLETE / VALID SEMANTIC RED / NON-STABLE**

- **Authority:** package 78 / source `e2b59295c9920db5685239c2da188858839fa94f`; run/job
  `33561723204 / 100035596811`; result artifact `9821602279`
  (`e9858ac5194646f888a193937e52cc504aa36a6940d79904b36f70c059026a62`); log artifact `9821602943`
  (`1f41626b53642bb30a00bcaafbbc3993d09870c20c2ffc15f2224670ecc65239`).
- **Gate:** ordinals **1–365 PASS**; ordinal **366 RED** at
  `InvalidNetworkTerminalOwnership`, source edge `36-38`, source face `(36,38,39)`, branch 2,
  `publishedFaceCount=0`. The prior source-vertex-11 `VertexTransitSeedUnavailable` stop is cleared; vertex 30 is
  not reached.
- **Remainder:** 367–374 executed once report-only with zero gate credit: **1 PASS / 7 RED**. 367/371/372 share the
  new terminal-ownership block; 368 preserves sphere `NoCarrierMatch / SourceEdgeUnavailable`; 369 preserves
  saturation; 370 preserves the genuine empty-network typed-error red; 373 passes synthetically; 374 repeats the
  pre-classified invalid folded-cone witness stop.
- **Diagnostic:** identity **375**
  `ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries` PASS, fresh process, zero gate
  credit. Gate identities 328/329 also PASS, providing runtime evidence for the repaired audit/rendering surfaces.
- **Immutable boundary:** preflight/postflight PASS; configure/compile/relink/repair/generated-discovery/product/test/
  fixture/selector mutation and benchmark flags false.
- **Accounting:** accepted authority stays **365/365** and CP4c-3 is unaccepted. **+0 stable events / +0 stable
  recurrences**; totals remain **44 / 14 / 30**, debt **5**, semantic packages **75**.
- **Owner:** independent `M3-CP4c-3-TB8-REV`; no unchanged TB retry or semantic correction before review.

## M3-CP4c3-TB8-CAND-01 - mechanical singularity termination fails terminal port ownership - **ACTIVE / GATING / ROOT CAUSE ESTABLISHED AT TB9-REV / NON-STABLE**

- **Root cause established at `M3-CP4c-3-TB9-REV`:** the firing subcondition is *missing port*, which means
  `portPolicy == BarrierAbsorbed`; the terminal vertex is **v36**; the defect is product-owned (BC2 category 1).
  Re-owned to **`M3-CP4c-3-CB12`** under BD0-BD9. See `M3-CP4c3-TB9-REV-CAND-01`.

- **TB8 origin:** ordinal 366 exposed `InvalidNetworkTerminalOwnership` at edge `36-38`, face `(36,38,39)`, branch
  2. TB8-REV eliminated ten of twelve producer sites and proved only singularity termination versus finalize/contact
  remained possible; package 78 could not distinguish them.
- **TB9 discrimination:** package 79 ordinal 366 reproduces the same coarse locus and adds exactly
  `networkErrorCondition=SingularityTerminationPortOwnershipMismatch`, `traceSeedVertex=47`,
  `traceSeedSingularity=5`, `traceHistoryCount=5`, `traceHistoryTruncated=false`. The history is branch 2 through
  `(45,46,47) → (43,44,45) → (41,42,43) → (39,40,41) → (36,38,39)`, each exact entry parameter `1/1`.
  The finalize/contact fall-through is therefore **excluded as the first-red emitter**.
- **Remaining unknown:** the named site combines three guard alternatives: terminal support is not a source vertex, no
  candidate singularity port matches the terminal singularity, or the matched port's source vertex differs from the
  terminal support. TB9 does not by itself prove which disjunct fires or whether its owner is product, witness, or a
  residual diagnostic gap.
- **Owner:** **`M3-CP4c-3-TB9-REV`** must reconstruct the terminal object, candidate port set/policy, and exact guard
  disjunct before freezing one correction. No correction to the unobserved finalize/contact site is authorized merely
  because TB9 excluded it here.
- **Accounting:** gating on an unaccepted CP4c-3 surface; **+0 events / +0 recurrences**. Totals remain **44 / 14 /
  30**, debt **5**, packages **76**.

## M3-CP4c3-TB8-CLOSURE — CB10 radial-arrival and diagnostic-consumer corrections — **RUNTIME PROVED / NON-STABLE**

- `M3-CP4c3-TB7-CAND-01` is **CLOSED / RUNTIME PROVED**: ordinal 366 clears the source-vertex-11
  `VertexTransitSeedUnavailable` stop, and diagnostic 375 passes both exact radial `FaceInterior` orientations.
- `M3-CP4c3-TB7-REV-CAND-01` is **CLOSED** for its audit-object reachability and renderer/consumer defect.
  **Reason corrected at `M3-CP4c-3-TB8-REV`:** the closure holds on static evidence - CB10 added the
  `vertexStar*` / `vertexTransitState[...]` reader to `append_cp4c_failure_locus`. It does **not** hold on the
  basis stated here: identities 328, 329 and 375 are unit-level synthetic identities that assert against the
  test-local `network_error_locus` or drive `resolve_field_vertex_transit` directly, and **none of them executes
  `network_failure_locus`, populates a `SurfaceCellFailureLocusDiagnostics`, or calls `append_cp4c_failure_locus`**.
- `M3-CP4c3-TB6-CAND-01` remains **ACTIVE for mechanical vertex-30 acceptance/projection**. The generic projection
  path now has runtime evidence, but TB8 does not reach vertex 30, so the row-209/row-208 owner condition is not
  accepted.
- `M3-CP4c3-DEFN-R2-CAND-01` remains **ACTIVE**: diagnostic 375 proves the radial-arrival correction, not the general
  non-flat exact-fallback/budget path. Ordinal 374 still fails before that discriminator.
- `M3-CP4c3-TB7-CAND-02` remains **ACTIVE / DEFERRED / PRE-CLASSIFIED WITNESS PRECONDITION**. Its repeated ordinal-374
  stop adds no new product evidence and does not itself trigger another review.
- Sphere, saturation, ordinal-370 and mechanical singularity-binding dispositions are unchanged.
- **Accounting:** these are closures/status updates on an unaccepted surface, with no accepted-green loss.
  **+0 events / +0 recurrences**; totals remain **44 / 14 / 30**, debt **5**, packages **75**.

## M3-CP4c3-TB7-REV — independent review adjudication — **CURRENT REVIEW AUTHORITY / STATIC / NON-STABLE**

- **Record:** `Architecture_M3_CP4c3_TB7_Independent_Review_Record.md`, measures **AW0–AW7** discharged. Static only:
  no runtime, compile, package, or product/test/fixture/selector mutation.
- **AW0 re-established independently.** All eleven selector values recomputed from committed bytes: selector 374
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`, 374 lines / 374 unique, and `head -316`,
  `-346`, `-353`, `-355`, `-357`, `-361`, `-365`, `-367`, `-370`, `-373` each reproduce their frozen hash. The
  working tree is byte-identical to CB9 semantic source `e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a` across `src/`,
  `include/`, `tests/`, `benchmarks/`, `CMakeLists.txt`.
- **Both TB7 reds are explained and they have different owners.** Ordinal 366 is a CB9-introduced product defect;
  ordinal 374 is an invalid witness precondition with a legitimate product rejection. The successor is therefore
  the earlier gating owner alone: **`M3-CP4c-3-CB10`** under **AZ0–AZ9**, product-only.
- **Amendments 22 and 23 remain internally valid.** No new semantics is substituted. `DEFN-R2` §AX1 never imposed
  the guard CB9 added, and §AX7 §7.2 item 5 *required* the on-radial-ray seed CB9 made unreachable.
- **Accounting:** static review on an unaccepted surface. **+0 events / +0 recurrences**; totals remain
  **44 / 14 / 30**, debt **5**, semantic packages **74**. Accepted authority remains **365/365**.

## M3-CP4c3-TB7 — artifact-only semantic disposition — **COMPLETE / VALID SEMANTIC RED / NON-STABLE**

- **Authority:** package 76 / source `e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a`; run/job
  `33541437165 / 99968443127`; result artifact `9813862211`
  (`814157162acfb95e785d4f5af3c886696534a0972942ac1f685d64b1c04086f0`).
- **Gate:** ordinals **1–365 PASS**; ordinal **366 RED** at
  `VertexTransitSeedUnavailable`, source vertex 11, face `(8,10,11)`, branch 1, region 0, `FaceInterior`,
  `publishedFaceCount=0`, no barrier absorption/incidence.
- **Remainder:** 367–374 executed once report-only with zero gate credit: **1 PASS / 7 RED**. 367/371/372 are
  upstream-blocked by the same vertex-11 stop; 368 reproduces sphere `NoCarrierMatch / SourceEdgeUnavailable`; 369
  reproduces `saturationUsed=true`; 370 reproduces the genuine empty-network product red; 373 passes synthetically;
  374 stops at `atlasBuild=false` before folded-cone vertex-star evaluation.
- **Prior candidates:** `M3-CP4c3-TB6-CAND-01` and `M3-CP4c3-DEFN-R2-CAND-01` remain runtime-unclosed because the
  corrected certificate/fallback surfaces are not reached. `M3-CP4c2-TB-X2-R10-CAND-01`,
  `M3-CP4c2-TB-X2-R8-CAND-02`, and `M3-CP4c3-DEFN-R1-CAND-01` remain active with the same dispositions.
- **Accounting:** accepted authority stays **365/365** and CP4c-3 is unaccepted. **+0 stable events / +0 stable
  recurrences**; totals remain **44 / 14 / 30**, debt **5**, semantic packages **74**.
- **Owner:** independent `M3-CP4c-3-TB7-REV`; no unchanged TB retry or semantic correction before review.

## M3-CP4c3-TB7-CAND-01 — the half-open ownership convention used as an arrival admissibility precondition — **ACTIVE / GATING / CAUSE ESTABLISHED / NON-STABLE**

- **Observed:** authoritative TB7 ordinal 366 fails with
  `NotProductionReady/field-aligned-network;detailCode=VertexTransitSeedUnavailable;sourceVertex=11;sourceFace=8,10,11;branch=1;topologyRegion=0;arrivalMode=FaceInterior;publishedFaceCount=0;barrierAbsorbed=false;barrierIncident=false`.
- **Cause — ESTABLISHED at `M3-CP4c-3-TB7-REV` by static derivation from the packaged source and the committed
  fixture.** CB9 added a **fifth** seed guard that the source TB6 ran does not contain
  (`src/geometry/SurfaceCellTracing.cpp:1289-1300`): the reversed arrival ray must satisfy the **half-open**
  predicate `direction[next] > 0 ∧ direction[previous] ≥ 0` in the arrival face. That predicate is an *ownership*
  convention — it partitions a fan by deliberately excluding one radial ray — and it is being used as an
  *admissibility test on one incoming ray*.
- **Exact proof at the locus.** Face `(8,10,11)` is mesh row 8 with corner order `[8,10,11]`. Its branch-1 direction
  is `(0, −2.77777777777777857, +2.77777777777777857)` over `(v8, v10, v11)`; `d[v8]` is an **exact IEEE zero**, so
  `from_double_exact` yields exact rational `0`. `|M| = 1`, the direction is exactly tangent to edge `(10,11)`, and
  entry at vertex 10 — one of the four port-emitting singularities — lands the exit exactly on vertex 11
  (Amendment 3). The arrival ray `−d` is exactly the radial ray `v11 → v10`, which at corner `v11` in row 8 is the
  **`previous`** ray: `arrivalRay[next] = 0`, so `next > 0` is false and the guard rejects. Every other seed guard
  is unreachable at this call site. The ray *is* owned — by neighbouring row 109 `(79,11,10)`, where `v10` is the
  `next` ray — so the convention is correct and the question asked of it was not.
- **Second instance of the same conflation, downstream.** `SurfaceCellTracing.cpp:1531-1540` rejects
  `arrivalMode == FaceInterior` with developed `α` exactly on a radial ray. Together the two guards make **every**
  Amendment-3 edge-collinear vertex arrival unresolvable in `FaceInterior` mode, which is the only mode a
  `VertexHit` publishes. Correcting one alone moves the failure rather than removing it.
- **Not a recurrence of TB5.** TB5's stop at the same vertex was CB6's *silent* conditional seed drop with zero
  diagnostic rows — an unreportable exit (Amendment 19). CB7 fixed it and TB6 passed this arrival, first-redding at
  vertex 30. TB7's stop is a *newly added* precondition that reports itself correctly. Shared locus, different
  mechanism; `M3-CP4c3-TB5-REV-CAND-01` is **not** reopened and no recurrence is counted.
- **Owner:** **AZ1–AZ4** of `M3-CP4c-3-CB10`. Separate the closed-wedge admissibility test from the half-open
  ownership convention, support both on-radial arrival orientations, split the collapsed typed outcome, and build
  the audit object before the first returning conditional.
- **Accounting:** gating on an unaccepted CP4c-3 surface; **+0 events / +0 recurrences**. Totals remain
  **44 / 14 / 30**, debt **5**, packages **74**.

## M3-CP4c3-TB7-CAND-02 — folded-cone AY5 witness declares a flat-star field on a non-flat star — **ACTIVE / GATING / CLASSIFIED WITNESS PRECONDITION / DEFERRED / NON-STABLE**

- **Observed:** report-only ordinal 374
  `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection` selects exactly
  once and fails at `ASSERT_TRUE(atlasBuild)`; the test prints no typed atlas error.
- **Recovered error — ESTABLISHED at `M3-CP4c-3-TB7-REV` by static derivation.**
  `FieldAtlasBuildErrorCode::CycleTransportMismatch`, raised at `src/authority/FieldTransportAtlas.cpp:2098` with
  only `topologyRegion` populated. `make_three_right_angle_cone_fan` has three exact right angles at its center, so
  `Θ = 3π/2` and the angle defect is `K = π/2`; `make_zero_transport_field` declares `effort ≡ 0` on every edge and
  no singularities, so `exactLift = (0 + 4·K)/2π = 1` exactly, while the declared matchings `2, 2, 0` compose to
  `0 (mod 4)`. `0 ≠ 1` → mismatch. A second independent contradiction sits behind it at `:2150-2163`: an interior
  cycle with `turningLift = 1` and no supplied singularity is `SingularityMismatch`.
- **Classification — AW4 category 1: invalid test/field precondition with legitimate product rejection.** The atlas
  is enforcing discrete Gauss–Bonnet / Poincaré–Hopf consistency and is correct. **No atlas invariant may be
  weakened and no product repair is warranted.**
- **Root cause, reusable.** `make_zero_transport_field` carries an **unstated precondition: the mesh must be
  intrinsically flat at every interior vertex.** Every prior consumer satisfied it accidentally
  (`make_four_triangle_fan` is entirely planar). AY5 required the project's first non-flat star and inherited the
  flat-only helper unchanged. `DEFN-R2` §7.2 enumerated five witness properties and omitted the consistency a
  non-flat **regular** vertex forces: production terminates traces at singular vertices *before* vertex-star
  transit, so an AY5 witness must satisfy `Σ_cycle effort = −4K` with matching composing to lift `0`, plus the
  boundary index correction.
- **Corrective, specified and deliberately unauthorized here.** Test-side only: derive matching/effort/singularities
  with the production authority `directional::fields::principal_matching` instead of declaring them; choose
  representatives so the center's derived lift is `0` while §7.2 item 4 still holds; keep the exact expected-owner
  derivation (`Θ = 3π/2`, per-sector `D=0, P=1, Q=1`, `β = α + 3π/4`); certify the witness against the atlas's whole
  admissibility chain in the report. **Selector 374 stays byte-frozen and is not withdrawn** — only the fixture and
  field inside the identity's body are invalid, and repairing them changes no selector byte.
- **Deferral, per the review plan.** Different owner from `M3-CP4c3-TB7-CAND-01`, so it is not combined with it.
  Ordinal 374 will remain red in `M3-CP4c-3-TB8` at exactly this stop; that is **pre-classified, carries no new
  information, and must not consume a review turn.**
- **Accounting:** gating on an unaccepted surface with zero gate credit; **+0 events / +0 recurrences**. Totals
  remain **44 / 14 / 30**, debt **5**, packages **74**.

## M3-CP4c3-TB7-REV-CAND-01 — AY7's projection was delivered producer-side only, and its typed state is unreachable — **ACTIVE / STATIC / NON-STABLE**

- **Declared at `M3-CP4c-3-TB7-REV`** from static derivation; no runtime executed. It supersedes the claim in the
  CB9 report that `M3-CP4c3-TB6-CAND-01` is closed.
- **Three distinct defects on one path.**
  1. `VertexStarTransitAudit` and its `VertexStarRaySeed` are constructed **after** all five seed guards
     (`SurfaceCellTracing.cpp:1302-1305`), so every seed failure leaves `error.vertexStarTransit == std::nullopt`.
     Amendment 19 was applied to the diagnostic *rows* and not to the audit object it equally governs.
  2. `VertexStarTransitState::SeedUnavailable` is therefore **dead by construction**: `network_failure_locus` maps
     it to a string, but the whole projection block is guarded by `if (error.vertexStarTransit.has_value())`.
  3. The 26 AX8 fields CB9 added to `SurfaceCellFailureLocusDiagnostics` have **no reader**.
     `append_cp4c_failure_locus` — the only renderer the CP4c identities use — prints none of them, and
     `vertexTransitStates` has no projection at all. Even a post-seed failure would publish nothing new.
- **Why it matters as a class.** This is the third consecutive turn in which a measurement was ordered, built, and
  discarded at a stage boundary (AS1, AU1/AU3, AY7), each time one layer further out. `LESSONS.md` 75's two
  authoring-time controls were both honoured; what they did not require was naming the **consumer that renders**
  the datum.
- **Owner:** **AZ4–AZ5** of `M3-CP4c-3-CB10`, with the consumer set found **by search against a predicate**, not by
  copying the measure's list, and at least one consumer named that the measure did not name. `M3-CP4c3-TB6-CAND-01`
  remains ACTIVE until AZ5 lands.
- **Accounting:** static, on an unaccepted surface. **+0 events / +0 recurrences**; totals remain **44 / 14 / 30**,
  debt **5**, packages **74**.

## M3-CP4c3-DEFN-R2-CAND-01 — an exact decision with no declared bound on its input size — **ACTIVE / ARCHITECTURAL CLASS / NON-STABLE**

- **Declared at `M3-CP4c-3-DEFN-R2`** from static derivation; no runtime executed.
- **The instance that opened it.** Electing a developed vertex sector (Amendment 22) is deciding the sign of a
  signed sum of arccosines. Each face angle at the vertex has `cos θ = D/√P` and `sin θ = √Q/√P` with `D = u·w`,
  `P = (u·u)(w·w)`, `Q = P − D²` exact rationals, so composing the fan's rotations exactly lands in a tower of
  degree up to `4^k` in the fan length `k`. **There is no bounded algebraic representation as valence grows**, and
  nothing in the codebase currently declares that or bounds it.
- **Why it is a class, not an instance.** Any exact predicate whose cost grows with an input parameter has the same
  three failure modes, and all three are already recorded defects here: exactify a floating result (the CB6 defect,
  `M3-CP4c3-TB5-REV-CAND-01`), introduce a tolerance (prohibited by Amendment 17), or let "the filter was
  inconclusive" stand as an answer — which silently converts the exactly-degenerate case, the one case that most
  needs deciding, into a failure.
- **Resolution shape: `DESIGN.md` Amendment 23.** A certified filter that returns the provably-correct answer or
  defers; an exact fallback that always terminates and is **actually implemented**; and a **published budget** with
  a typed fail-closed state above it. Here the exact fallback is load-bearing rather than ceremonial: it is the only
  path that can decide a continuation lying exactly on a radial ray.
- **Counterweight, recorded so the budget is not read as pessimism:** the worst case is not the measured case. At
  vertex 30 every sign test collapsed to rational identities (two exact right angles, two exact complementary
  pairs), so `Θ = 2π` was proved with no factorization and no floating point. An exactly-recognizable rational
  short-circuit is a legitimate optimization; it is never a semantics, and the general path must stay reachable.
- **Owner:** **AY3** implements the filter/fallback/budget; **AY8**'s second predicate — *"an exact computation has
  no declared bound on its input size"* — sweeps for other instances with a site named outside this record.
- **Stable-count rationale:** static, definition-level, on an unaccepted surface. **+0 events / +0 recurrences**;
  totals remain **44 / 14 / 30**, debt **5**, semantic packages **73**. Lesson: `LESSONS.md` 76.

## M3-CP4c3-CB8-REV — vertex-transit stop adjudicated as definition + representation gap — **CURRENT REVIEW AUTHORITY / NON-STABLE**

- **CB8 stop upheld.** Current A1 products carry exact face-local branch directions and exact branch correspondence,
  but no exact/certified arbitrary-ray metric transport. `signedLift`, target-local representatives and the old
  world-space-double helper are not Amendment-17/18 authority.
- **Primitive datum frozen.** One A2a arrival event writes one exact arrival-anchored ray. A candidate face never
  rewrites that datum. A geometric exit/owner is a derived result, not a second primitive authority.
- **Deeper gap established.** General non-flat vertex-star continuation is not normatively defined. Under an
  arrival-anchored intrinsic development, sector gaps/overlaps need typed Amendment-21 semantics before a numeric
  representation can be selected. Plain GMP rationals are not a general hinge-development construction type; any
  filter must defer to an exact algebraic/direct-predicate path.
- **Stage owner frozen.** A1 remains branch-topology authority. A2a owns one derived vertex-star transit contract
  consuming A0 geometry + A1 topology + one seed and writing one owner/non-owner certificate.
- **Mechanical witness.** Vertex 30 remains a valid falsifier because rows 41 and 208 use distinct target-local
  branch families; one common developed seed cannot become two candidates merely by substituting those local rays.
  Exact owner is intentionally deferred until DEFN-R2 freezes the geometry.
- **Candidates.** `M3-CP4c3-TB3-R1-CAND-01` remains ACTIVE, reclassified as **definition + representation authority
  gap**. `M3-CP4c3-TB6-CAND-01` remains ACTIVE / owner-proved at the production projection DTO, but its fix is
  blocked until the correct seed/certificate audit is defined.
- **Selector governance.** Selector 373 remains frozen. Selector 374 is blocked until an exact non-coplanar witness
  demonstrably fails under `incomingDirection = nextPairing->direction`.
- **Accounting:** unaccepted CP4c-3 surface; accepted 365 remains green. **+0 stable events / +0 recurrences.**
  Totals remain **44 / 14 / 30**, debt **5**, semantic packages **73**.
- **Owner:** exact successor `M3-CP4c-3-DEFN-R2`, measures AX0–AX9 in
  `Architecture_M3_CP4c3_CB8_Independent_Review_Record.md`; definition/review only.

## M3-CP4c3-TB6-REV — independent adjudication of TB6 mechanical and report-only findings — **CURRENT REVIEW AUTHORITY / NON-STABLE**

- **Evidence identity correction:** authoritative TB6 result artifact is `9782227361`, SHA-256 `e39fcab4ec71c951f9dd7505d052d73fbee7a4f2f66105ae6ff7a47dad672a87`; the prior `5748464145 / f084...` documentation pair was wrong. Runtime classification is unchanged.
- **Mechanical cause confirmed:** current CB7 source sets each transported state's `incomingDirection` from the target face's `nextPairing->direction`. The exact predicate therefore consumes one local representative per cell. Fixture rows 41 and 208 have disjoint branch-vector families, proving the two candidate-face representatives are geometrically distinct under every gauge permutation. `M3-CP4c3-TB3-R1-CAND-01` remains ACTIVE with Amendment 17 violated.
- **Diagnostic owner proved:** `FieldAlignedCurveNetworkError::vertexTransitStates` retains the exact rows; `RemeshPipeline.cpp::network_failure_locus` / `SurfaceCellFailureLocusDiagnostics` drops them. `M3-CP4c3-TB6-CAND-01` remains ACTIVE, now localized to the production projection/DTO.
- **Prior first-failure/exactness candidates:** `M3-CP4c3-TB5-CAND-01` is RESOLVED as the first-failure surface; `M3-CP4c3-TB5-REV-CAND-01` is RESOLVED as the CB6 float-round-trip violation. CB7 corrected the numeric derivation but exposed/reintroduced a separate semantic single-authority defect.
- **Selector governance:** the CB7 minimal witness was required by TB5-REV to become permanent regression authority. CB8 must preserve selector 373 and append the same identity as ordinal 374 in a new required-green selector.
- **Ordinal 370:** repaired witness is a genuine independent product red. Static owner is `SurfaceCutGraph::canonical_candidate`, which contains no `EmptyNetworkOnClosedSurface` branch; keep `M3-CP4c2-TB-X2-R8-CAND-02` ACTIVE and defer it from CB8.
- **Other report-only:** sphere `NoCarrierMatch / SourceEdgeUnavailable`, saturation `saturationUsed=true`, and mechanical zero-unbound debt remain active/deferred; 367/371/372 are upstream-blocked and their contracts remain unmeasured.
- **Accounting:** accepted 365-prefix remains green and CP4c-3 is unaccepted. **+0 stable events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, semantic packages **73**.
- **Owner:** `M3-CP4c-3-CB8` under `Architecture_M3_CP4c3_CB8_Code_Build_Plan.md`; runtime-free.

## M3-CP4c3-TB6-CAND-01 — gating vertex-30 red omits exact transit/election certificate rows from production evidence — **ACTIVE / OWNER PROVED / AUDIT CONTRACT NOW FROZEN / GATING / NON-STABLE**

- **`M3-CP4c-3-DEFN-R2` disposition — contract frozen, correction scheduled.** §AX8 freezes exactly what the
  projection must publish, and deliberately describes the **corrected** datum rather than today's rows: seed
  identity and provenance; which kernel route decided it (`Filter` / `ExactFallback` / `RationalShortCircuit`) and
  the budget in force; the ordered fan with each face's exact `(D, P, Q)`, its truncation reason where open, and
  the exact cone angle or the certified relations determining it; per developed sector, its identity and exact
  membership outcome; then `ownerCardinality`, the elected owner, and `onRadialRay` with the ray's identity; and the
  typed non-owner state with its locus. Publishing richer rows for the invalid per-cell datum would only document
  the wrong decision better.
- **Owner:** **AY7**, which must implement the contract **and extend the `RemeshDiagnostics` projection in the same
  change**. That same-change obligation is the authoring control this candidate exists to teach: `vertexTransitStates`
  was built correctly three times (AS1, AU1, AU3) and read zero times because no measure was obliged to name the
  reader. `LESSONS.md` 75.
- **+0 events / +0 recurrences**; totals **44 / 14 / 30**, debt **5**, packages **73**.

### Prior disposition, retained for lineage

## M3-CP4c3-TB6-CAND-01 (TB6-REV entry) — **ACTIVE / OWNER PROVED: PRODUCTION PROJECTION DTO / BLOCKED ON DEFN-R2 / GATING / NON-STABLE**

- **Observed in authoritative TB6.** Package 75 / source `e926ada023bc51220628be550bbe9a87f98d7067`; run/job `33458067065 / 99702200466`; immutable pre/postflight PASS; ordinals **1–365 PASS**, ordinal **366 RED**.
- **Measured locus.** `VertexTransitSectorUnresolved`; source vertex 30; face `(24,30,32)`; branch 1; `FaceInterior`; `publishedFaceCount=2`; faces `(25,30,31)|(30,31,119)`; no barrier absorption/incidence.
- **Evidence gap.** CB7 compiled typed per-state outcomes and exact representative/incoming/elected-direction diagnostics, but ordinal 366's production exception serializes none of those rows. `publishedFaceCount=2` alone cannot decide Amendment 17's equal-direction falsifier.
- **Selector-governance companion.** CB7 also compiled `ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState`; frozen selector 373 does not contain it, so TB6 correctly did not execute it. Review must adjudicate its future role before any selector change.
- **Current owner after CB8-REV:** `M3-CP4c-3-DEFN-R2` AX8 freezes the correct seed/certificate audit surface; a later CB may then repair this production projection. Publishing richer rows for the invalid per-cell datum is not closure.
- **Stable-count rationale:** accepted ordinals 1–365 remain 365/365 green; CP4c-3 is unaccepted. **+0 events / +0 recurrences**. Totals remain **44 / 14 / 30**, debt **5**, semantic packages **73**.

## M3-CP4c3-TB5-CAND-01 — Amendment-17 runtime moved ordinal 366 to a zero-candidate vertex-11 transit with no state diagnostics — **RESOLVED AS FIRST-FAILURE SURFACE / NON-STABLE**

- **Observed in authoritative TB5.** Immutable package 74 / source `49536cf7b4b261bd52f36a91c861b6459db356a4`; run/job `33448925069 / 99674216849`; immutable pre/postflight PASS. Ordinals **1–365 PASS** and ordinal **366** first-reds exactly once.
- **Measured locus.** `VertexTransitSectorUnresolved`; `sourceVertex=11`; arrival face `(8,10,11)`; branch 1; region 0; `FaceInterior`; `publishedFaceCount=0`; `barrierAbsorbed=false`; `barrierIncident=false`.
- **What changed from TB4.** TB4 observed two candidates at regular vertex 30. TB5 reaches a different, earlier zero-candidate locus at vertex 11. This proves the runtime failure surface changed after CB6, but **does not prove vertex 30 accepted**; that defect may be cleared or merely masked.
- **Diagnostic discriminator.** CB6 serializes every completed reachable transit state into `vertexTransitStates`, yet TB5 emits **zero state rows**. Independent review must enumerate and adjudicate the resolver's paths that fail before a diagnostic state is appended rather than assuming an ordinary sector miss.
- **Owning next turn:** `M3-CP4c-3-TB5-REV` under `Architecture_M3_CP4c3_TB5_Independent_Review_Plan.md`. No unchanged TB retry or semantic correction before review.
- **Stable-count rationale:** CP4c-3 remains unaccepted and the accepted 365-prefix is still 365/365 green. **+0 stable events / +0 recurrences**; totals remain **44 / 14 / 30**, debt **5**, semantic packages **72**.

- **`M3-CP4c-3-TB5-REV` adjudication — THE WALK NEVER STARTED.**
  - **Mechanism, read at source.** CB6 rewrote the BFS so the seed is **conditional**
    (`src/geometry/SurfaceCellTracing.cpp:659-667`): `pending` starts empty and receives the arrival state only if
    the arrival face has **exactly one** `FieldBranchBoundaryPairing` for the branch **and** `field_direction_world`
    converts. `diagnostics` is populated **only inside the walk loop** (`:703`). So an empty seed ⇒ loop never runs
    ⇒ `diagnostics` empty ⇒ `candidates` empty ⇒ fall through to `candidates.size() != 1U` ⇒
    `VertexTransitSectorUnresolved` with `publishedFaceCount=0` **and zero state rows**. That is exactly TB5's
    measurement, and it means the typed name asserts an election that never happened.
  - **Four unreportable exits**, none recording a diagnostic: (1) `:660` `currentPairing == nullptr` — missing
    frame, component/region mismatch, or the two-pairing ambiguity guard nulling it; (2) `:661-663`
    `field_direction_world` returns `nullopt` — non-barycentric, non-finite, or **`squaredNorm() == 0.0`** after
    conversion to `double`; (3) `:695` `field_direction_from_world` fails the `double → exact` reconstruction;
    (4) `:731-735` transported direction non-finite or zero-norm during expansion.
  - **Vertex 11 is structurally ordinary.** Reproduced from the committed fixture: six incident faces (mesh rows 8,
    9, 18, 119, 108, 109) in a single **closed, consistently oriented** fan; not barrier-incident, not
    barrier-absorbed, not among the eight prescribed singularities — a **regular** vertex with trivial holonomy,
    the same shape as vertex 30. Zero examined states at an ordinary vertex is a seeding defect, not geometry.
  - **Not a regression of accepted authority** (1–365 green) **but a new defect at 366**: before CB6 the seed was
    pushed unconditionally (`std::vector<State> pending{{currentFace, currentBranch}}`), so the walk always started.
  - **Owning corrections:** **AU1** (make every exit reportable, Amendment 19; publish which fired) and **AU2**
    (remove the float round-trip, Amendment 18). **AU4** forbids redesigning the election in the same turn.
  - **Closure condition:** ordinal 366 green in a run reaching at least 366. **+0 events / +0 recurrences.**

- **`M3-CP4c-3-TB6` disposition — RUNTIME CLEARS THE SILENT SEED-DROP AS FIRST FAILURE.** Package 75 executes the mechanical witness past TB5's regular vertex-11 zero-state stop and returns to source vertex 30 with `publishedFaceCount=2`. This is sufficient to close the **silent-seed-drop first-failure** claim, not CP4c-3: ordinal 366 remains red. The accepted 365-prefix is unchanged; **+0/+0**.

## M3-CP4c3-TB5-REV-CAND-01 — floating point reached a topological decision in the transit datum — **RESOLVED BY CB7 EXACT PATH / NON-STABLE**

- **Observed statically at `M3-CP4c-3-TB5-REV`** from committed source; no runtime executed.
- **Mechanism.** CB6 satisfied Amendment 17's "single datum" by carrying the continuation direction as a
  **world-space `Eigen::RowVector3d`**: exact barycentric → `to_double()` (`field_direction_world`) → normalized
  3-vector → transported face to face by `transport_direction_between_faces` (double arithmetic) →
  `from_double_exact()` (`field_direction_from_world`) → fed to `direction_in_vertex_sector`, whose comparison is
  exact. **The comparison stayed exact; the datum did not.** An exact comparison on a float-derived operand is a
  floating-point decision with an exact final rounding step.
- **Why it matters beyond principle.** The conversions introduce three silent failure modes — underflow to
  `squaredNorm() == 0.0`, non-finite intermediates, and failed reconstruction — at exactly the points that are
  unreportable today, so the exactness break and the diagnostic break are the same defect seen twice.
- **Measure-scoping failure, owned.** **AS9** prohibited "any tolerance **in the predicate**". CB6 did not touch
  the predicate; it changed the **provenance of the predicate's inputs**. The measure was satisfied to the letter
  and defeated in substance — the fifth consecutive measure of this reviewer scoped one level too narrow.
- **Corrective frame: Amendment 18** (`DESIGN.md` §7.2.1) — exactness is a property of the derivation chain, not of
  the final comparison; only a **certified filter** (provably-correct result, or defer to exact) is admissible; and
  snapping an exact coordinate onto a bounded lattice is prohibited because it changes the value rather than the
  cost.
- **Owning correction: AU2** — compose the atlas's exact per-edge branch transport instead of the world-space round
  trip; delete `field_direction_world` / `field_direction_from_world` from the decision path or demote them to a
  diagnostic-only leaf; state in the CB report that no value reaching `direction_in_vertex_sector` has passed
  through a `double`.
- **Prediction:** no exact path is lost by the removal — the atlas already publishes exact branch transport
  sufficient to carry the datum. If it is not sufficient, the single-datum **choice** is revisited, never the
  exactness.
- **Accounting:** static finding on an unaccepted surface; no accepted-green behaviour lost.
  **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, semantic packages **72**.

- **`M3-CP4c-3-TB6` disposition — EXACT PATH IS THE EXECUTED AUTHORITY; NO FLOAT-ROUND-TRIP FAILURE REAPPEARS.** TB6 consumes CB7/package-75 bytes and advances the mechanical witness beyond the vertex-11 seed/drop locus to vertex 30. The exactness violation identified at TB5-REV is corrected in source authority; the remaining red is owned separately by the transit/election evidence gap. **+0/+0**.

## M3-CP4c3-TB3-R1-CAND-01 — mechanical production witness first-reds at `VertexTransitSectorUnresolved` — **ACTIVE / SEMANTICS FROZEN / EXPECTED ANSWER PROVED AT THE LOCUS / GATING / NON-STABLE**

- **`M3-CP4c-3-DEFN-R2` disposition — the definition gap is closed and the locus is decided.** Amendment 22 freezes
  continuation as the straightest geodesic of the intrinsic vertex star; Amendment 23 freezes the exact-decision
  budget. The cause CB8-REV confirmed — one representative per candidate cell — is unchanged and is now not merely
  ill-posed but **provably wrong at this locus**.
- **Exact proof from the committed fixture**, rational identities only, no factorization and no floating point:
  rows 43 and 218 are exact right angles (`u·w = 0`); `θ₂₀₉ + θ₂₀₈ = π/2` and `θ₄₁ + θ₄₀ = π/2` exactly
  (`D₁D₂ ≥ 0` and `(D₁D₂)² = Q₁Q₂`, the rational form of `cos(θ₁+θ₂) = 0`); hence **`Θ(v30) = 2π` exactly**. The
  same test over the six other pairings is false, so the decomposition is the fixture's structure rather than a
  coincidence fitted afterwards. Every `Q_i > 0`, so no sector is degenerate, and the star is genuinely folded
  (hinges `43|218` and `208|41` have non-parallel normals).
- **The finding.** The developed sectors give `sector(209) ∪ sector(208) = [π, 3π/2)` exactly, and every
  `FaceInterior` seed in arrival face `(24,30,32)` has `α ∈ (0, π/2)`, so its continuation `β = α + π` lies in
  exactly that arc. **Owner = row 209 `(30,119,123)` if `α < θ₂₀₉`, else row 208 `(30,31,119)`; `α = θ₂₀₉` is the
  exact boundary-ray case owned by the unchanged half-open convention. Row 41 `(25,30,31)` is unreachable by any
  continuation.** TB4-REV proved two elections imply two distinct data were tested; this proves *which* of the two
  answers is geometrically impossible. The expected result was not overwritten to match the current expectation —
  it contradicts it.
- **Owner:** **AY1–AY3**. `direction_in_vertex_sector` is kept unchanged; it was never the defect, and TB4-REV's
  partition proof is now the reason the developed election is single-valued.
- **+0 events / +0 recurrences**; totals **44 / 14 / 30**, debt **5**, packages **73**.

### Prior disposition, retained for lineage

## M3-CP4c3-TB3-R1-CAND-01 (CB8-REV entry) — **ACTIVE / CAUSE CONFIRMED: PER-CELL REPRESENTATIVE ELECTION / DEFINITION + REPRESENTATION AUTHORITY GAP / GATING / NON-STABLE**

- **`M3-CP4c-3-CB8-REV` disposition — DEFINITION BOUNDARY.** The per-cell-representative mechanism remains proven, but review establishes that current architecture does not yet define one exact straight-through continuation on a general non-flat vertex star. One arrival-anchored ray is frozen as the primitive datum; its exact owner predicate and gap/overlap semantics move to DEFN-R2 AX1–AX6. No CB is authorized and **+0/+0**.

- **`M3-CP4c-3-TB6` status — VERTEX 30 REACHED AGAIN, AMENDMENT 17 STILL NOT ADJUDICATED.** First red 366 returns to vertex 30 / `(24,30,32)` / branch 1 with two published faces `(25,30,31)` and `(30,31,119)`. The authoritative production exception does not serialize CB7's exact per-state/election diagnostics, so equality or inequality of the elected exact directions is unknown. Keep this candidate ACTIVE and route the missing discriminator through `M3-CP4c3-TB6-CAND-01`; do not choose a candidate by order. **+0/+0**.

- **`M3-CP4c-3-TB5-REV` status — MASKED.** TB5's vertex-11 stop occurs **before any election runs**, so none of Amendment 17's substance was exercised and **AS1's falsifier never executed**. The vertex-30 two-candidate reconstruction is therefore neither confirmed nor refuted; it is untested. Reopened for **AU3**, which restores the measurement once AU1 (reportable exits) and AU2 (exact datum) land.

- **Observed in valid TB3-R1.** Immutable package 72 preserved semantic source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, source archive `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`, selector 373 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`, all six frozen hashes/modes, and package-relative fixtures. Run/job `33416686424 / 99568970224` passed immutable pre/postflight.
- **Measured boundary.** Ordinals **1–365** each selected exactly once and passed. Ordinal **366**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, selected exactly once and failed with `NotProductionReady/field-aligned-network/VertexTransitSectorUnresolved`; first-red semantics left 367–373 unexecuted.
- **What advanced.** `MissingSingularityBranchTransport` is absent. Atlas partition diagnostics are emitted and production reaches field-aligned-network construction, proving the prior Amendment-16/P2 atlas failure locus is cleared far enough to expose a later consumer seam.
- **Static localization.** `resolve_field_vertex_transit` walks reachable `(face,branch)` states through published transport adjacencies incident to the hit vertex, tests `direction_in_vertex_sector`, deduplicates decisions, and requires exactly one candidate. Candidate count **0 or >1** yields `VertexTransitSectorUnresolved`; the typed error stores the source vertex/current face/current branch and candidate faces.
- **Diagnostic gap.** The CP4c production exception publishes only `stage/error` for a network failure, so this TB does not reveal candidate cardinality, source vertex/face/branch, candidate faces, or `FaceInterior` versus `EdgeTransit`. Review must recover those facts before a semantic correction is selected.
- **Causality not assigned.** The red may be pre-existing/unmasked, a changed-port reachability consequence of P2, or another consumer/representation/election mismatch. The fact that it follows CB3 is not causality evidence.
- **Owning next turn:** independent `M3-CP4c-3-TB3-R1-REV` under `Architecture_M3_CP4c3_TB3_R1_Independent_Review_Plan.md`. No unchanged TB retry.
- **Accounting:** unaccepted checkpoint; accepted 365-prefix remains green. **+0 stable events / +0 recurrences**. Totals remain **44 / 14 / 30**, debt **5**, semantic packages **70**.
- **`M3-CP4c-3-TB3-R1-REV` adjudication — INVARIANT FIXED, CAUSE STILL NOT ESTABLISHED, AND THAT IS THE FINDING.**
  - **The invariant.** `resolve_field_vertex_transit` (`src/geometry/SurfaceCellTracing.cpp:557-640`) answers "a
    trace arrived at vertex `v` in face `F` on branch `b`; which single `(face, branch)` does it continue into?"
    It BFS-walks `(face, branch)` states, gates each on frame presence and matching `sourceComponent` /
    `topologyRegion`, requires **exactly one** `FieldBranchBoundaryPairing` per branch in a frame, tests candidacy
    only when `arrivalMode == EdgeTransit` **or** the state's face differs from the arrival face, expands **only**
    through `topology.transports()`, then elects on `candidates.size() == 1` after dedup on `(nextFace, nextBranch)`.
  - **The election is exact.** `direction_in_vertex_sector` (`FieldTransportAtlas.cpp:1623-1654`) delegates to
    `direction_in_incident_vertex_sector` (`:404-426`), a half-open partition over `FieldExactRational`:
    `direction[next] > 0 && direction[previous] >= 0`. **No tolerance.** Cardinality is therefore a topological
    fact, not a numerical accident, and "multiple candidates" would be a real representational ambiguity.
  - **Zero is reachable by barrier truncation.** `topology.transports()` is the `FieldBranchTransportAdjacency`
    set built from `adjacencies`, which excludes every `SourceBoundary`, `HardFeature` and `NonTraversable` edge by
    construction, so the walk is confined to the connected component of `star(v) ∖ B(R)` containing the arrival
    face. **Multiplicity is structurally expected at a *singular* vertex**: holonomy is a non-trivial quarter-turn,
    so one face is reachable with different branches, dedup keeps them distinct, and two states can both pass the
    predicate.
  - **Amendment-16 audit: compliant, but missing a case.** The traversal already cannot cross a barrier — it is
    Amendment-16-compliant by construction. What it lacks is a **response to truncation**: it reports "sector
    unresolved" rather than "blocked by a barrier", although the network already models
    `MandatoryBarrierTermination` as a frozen terminal kind. `LESSONS.md` 51 — read the siblings before believing
    the shortcut is a design. **The correction must not restore uniqueness by widening the walk.**
  - **Causality NOT assigned, on evidence rather than caution.** CB3's entire diff to `SurfaceCellTracing.cpp` is
    **8 insertions / 1 deletion in two hunks inside `canonical_field_aligned_candidate`**;
    `resolve_field_vertex_transit`, `direction_in_vertex_sector` and the sector predicate are **untouched**. But
    P2 changed which traces exist and where they start, so unchanged code reached with a changed trace set can fail
    for a new reason. Three mechanisms remain live, **none promoted**, each decided by one measurement:
    **M1** barrier truncation → `publishedFaces` **empty**; **M2** singular-vertex multiplicity → `publishedFaces`
    **size ≥ 2**; **M3** P2 consumer mismatch → the failing vertex is one of the four `BarrierAbsorbed` census
    vertices. M3 is the leading suspicion — terminal ownership *is* port-keyed (`:832-839` raises
    `InvalidNetworkTerminalOwnership` when no port matches `candidate.singularityPorts`) and P2 removed four ports
    — and **AP4 forbids designing against it**. M1 and M3 are not exclusive.
  - **Owning correction:** **AP2** measures the discriminator (all of it already exists in the typed error or in
    CB3's census); **AP5** implements only after AP2 reports; **AP3** forbids any semantic change in CB5.
  - **Closure condition:** ordinal 366 green in a run reaching at least 366. **+0 events / +0 recurrences.**

- **TB4 runtime discriminator.** Package 73 / run-job `33436492493 / 99634138202` re-proves 365/365 and first-reds at ordinal 366 with the complete typed locus: `sourceVertex=30`, face `(24,30,32)`, branch 1, region 0, `FaceInterior`, `publishedFaceCount=2`, candidates `(25,30,31)` and `(30,31,119)`, `BarrierAbsorbed=false`, `barrierIncident=false`. **M1 is falsified** because the candidate set is not empty. **Direct M3 is falsified** because the failure is not at a barrier-absorbed/barrier-incident vertex. M2's *multiplicity* observation is true but its *singular-vertex holonomy* explanation is not established: TB4 does not classify vertex 30 or prove why both candidate states pass. Exact owner is `M3-CP4c-3-TB4-REV`; no semantic correction before that reconstruction. Stable accounting remains +0/+0 because the accepted 365-prefix stays green and CP4c-3 was already open.

- **`M3-CP4c-3-TB4-REV` adjudication — ALL THREE ENUMERATED MECHANISMS FALSIFIED; THE CAUSE FAMILY IS PROVED.**
  - **Measured locus (AP2 delivered).** `sourceVertex=30`, arrival face `(24,30,32)`, `branch=1`, region 0,
    `arrivalMode=FaceInterior`, candidates `(25,30,31)` and `(30,31,119)`, `barrierAbsorbed=false`,
    `barrierIncident=false`.
  - **M1 falsified** — cardinality is **2**, not zero, so barrier truncation is not the mechanism at this locus.
  - **M3 falsified** — the vertex is neither barrier-absorbed nor barrier-incident, so the P2 consumer mismatch has
    no purchase here. **AP4 did its job:** this was the reviewer's leading suspicion and it was measured before it
    became a correction.
  - **M2 falsified** — **vertex 30 is a regular interior vertex.** Reproduced from the committed fixture
    `benchmarks/fixtures/milestone-g/mechanical_feature.obj`: six incident faces (mesh rows 43, 40, 41, 208, 209,
    218) forming **one closed, consistently oriented fan**. It is not among the four port-emitting singularities
    (10/35/47/71) nor the four `BarrierAbsorbed` ones, and Poincaré–Hopf closes with exactly those eight index-`+1`
    singularities (`4χ = 8` on this `χ = 2` witness), so no others can exist. A1 would additionally have raised
    `SingularityMismatch` (`FieldTransportAtlas.cpp:1843-1851`) had any interior vertex's turning lift disagreed,
    and the atlas built. **Vertex 30 therefore has trivial branch holonomy**, and singular-vertex multiplicity
    cannot be the mechanism.
  - **The proof that replaces the enumeration.** `direction[next] > 0 && direction[previous] >= 0` is exactly *the
    closed wedge between ray(v→next) and ray(v→prev), minus the ray(v→prev)*. Adjacent wedges share exactly one
    ray, assigned to the face where it is `next`; the six wedges therefore **tile the full turn with no overlap and
    no gap**, and there is no tolerance anywhere in the decision. The two candidates are **fan-adjacent** — steps 2
    and 3 of the fan whose step 0 is the excluded arrival face — sharing ray 30→31, which `(25,30,31)` **owns** and
    `(30,31,119)` **excludes**. A single geometric direction can therefore elect **at most one** of them.
    **Two were elected ⇒ two geometrically distinct vectors were tested.** This is a proof, and it kills the
    "direction landed on the shared ray" explanation outright.
  - **Alias, not ambiguity.** The trace has one continuation. The routine elects **per cell**: for each reachable
    `(face, branch)` state it tests *that face's own* representative of the transported branch against *that
    face's* wedge, and a cross field's per-face representatives are related by transport, **not equal as vectors**.
    The two candidates are two representations of **one** semantic continuation.
  - **Surviving mechanisms, unpromoted.** **M4 — election by per-cell representative** (leading; explains
    multiplicity at a regular vertex, exactly two candidates, their fan-adjacency, and their position opposite the
    arrival). **M5 — the representative is not the trace's continuation at all**, making multiplicity generic
    rather than a boundary effect. **AS1** publishes both direction vectors and **falsifies both if they are
    equal**.
  - **Causality relative to P2.** The mechanism involves no barrier, port or singularity, and
    `resolve_field_vertex_transit` is untouched in behaviour by CB3 and CB5 (CB5 added two purely diagnostic
    lines). But `barrierAbsorbed=false` does **not** prove causal independence: P2 changed which traces exist and
    where they start. Correct statement: **a pre-existing, P2-independent defect reached by a trace set P2 may have
    changed.** The correction is the same either way.
  - **Corrective frame: Amendment 17** (`DESIGN.md` §7.2.1) — an election among candidate cells is decided from a
    **single datum**, never one representative per cell. Prohibited because each removes the symptom rather than
    the cause: picking the first candidate or ordering faces; widening/narrowing the sector convention; any
    tolerance in a predicate that is exact today; changing the `FaceInterior` exclusion to alter cardinality.
    **Which** single datum is left open pending AS1 — a single-writer question.
  - **Owning correction:** **AS1** confirms, **AS2** implements, **AS4** bounds it to the election.
  - **Closure condition unchanged:** ordinal 366 green in a run reaching at least 366. **+0 events /
    +0 recurrences.**

## M3-CP4c3-TB3-R1-REV-CAND-01 — the pipeline failure funnel discards every stage's typed error locus — **RESOLVED / RUNTIME PROVED / DIAGNOSTIC-SURFACE DEFECT / NON-STABLE**

- **Observed statically at `M3-CP4c-3-TB3-R1-REV`** from committed source; no runtime executed.
- **Mechanism.** `fail_surface_cells` (`src/pipeline/RemeshPipeline.cpp:6146-6163`) takes only
  `(SurfaceCellFailureCode, const std::string &stage)` and stores `terminalFailureCode` / `terminalFailureStage`.
  **It has no locus parameter at all.** Every stage funnels through it, and every caller drops the typed error it
  is holding — the A2a site (`:6673-6678`) reads `fieldAlignedBuild.error().code` and lets `sourceVertex`,
  `sourceFace`, `branch` and `publishedFaces` die at the `return`. The test harness then composes its message from
  `terminalFailureCode + "/" + terminalFailureStage`
  (`tests/FieldAlignedCurveNetworkTests.cpp:5283-5285`).
- **Third occurrence, and the shape is what matters.** TB1 (`IncompleteCycleBasis`), TB2
  (`MissingSingularityBranchTransport`) and TB3-R1 (`VertexTransitSectorUnresolved`) each forced a review to
  recover a locus by **elimination**. Each was answered with a *bespoke per-code* channel — AK1/AK2 added region
  diagnostics, AN1 added atlas locus fields — and one call site had already grown a hand-rolled channel by
  string-concatenating `"field-aligned-network/" + code`, which is a locus channel with room for exactly one field.
  The project has been re-implementing the same channel once per stage while the structured object is dropped one
  line later.
- **Why it is not merely inconvenient.** In this instance the discarded field (`publishedFaces`) is precisely the
  discriminator between two mechanisms needing opposite corrections, so the loss directly costs a turn.
- **Owning correction:** **AP1** — give the boundary a **typed locus payload** (optional source vertex / face /
  edge / branch / region plus a bounded published-face list), populate it from whichever stage error is in hand,
  surface it in `RemeshDiagnostics`, and convert **all four** stage call sites (A1, A2a, A2a′, A2b) in one change,
  retiring the string-concatenation channel at the same time. Additive only; no existing code, mapping or enum
  value changes.
- **Pattern:** `ORIENTATION.md` §8 gated-observation family — "an assertion that discards a typed error it already
  holds" — at a boundary rather than at a call site. Recorded as `LESSONS.md` **69**; the companion measure-scoping
  lesson is **68**.
- **Closure condition:** a TB report that names the failing locus for a stage error without the review having to
  derive it. **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, semantic packages **70**.
- **TB4 closure evidence.** Run/job `33436492493 / 99634138202` publishes the ordinal-366 network error directly through the shared diagnostics boundary: source vertex 30, face `(24,30,32)`, branch 1, region 0, `FaceInterior`, two candidate faces, and barrier classification. The TB report can adjudicate the discriminator without a review reconstructing the locus by elimination. Closure condition is satisfied. **+0 stable events / +0 recurrences**; this was a diagnostic-surface defect on an unaccepted checkpoint.

## M3-CP4c3-TB4-DIAG-CAND-01 — ordinal 370 cannot reach the empty-network cut-graph contract because its synthetic atlas build fails — **CLASSIFIED AT TB5-REV: INVALID DIAGNOSTIC WITNESS / PRODUCT BEHAVIOUR LEGITIMATE / NON-STABLE**

- **`M3-CP4c-3-TB5-REV` classification.** AS3's requirement was met: the atlas error is now published as
  **`NonIntegralCycleLift; topologyRegion=0`**. The witness pairs `make_source_authority(mesh)` with a **globally
  constant ambient** `make_zero_transport_field` (`UnitX`/`UnitY` per face) on the closed torus, which does not
  satisfy the atlas's integral-cycle-lift precondition. Of AQ5's three options this is the **third**: the atlas's
  fail-closed rejection is **legitimate product behaviour** and the witness is invalid. The identity was appended at
  CB2 under AL7 and had never executed until the report-only pass, so this was an original authoring defect — the
  fourth instance in this checkpoint of compiled-but-never-executed test authority proving to be debt
  (`LESSONS.md` 56).
- **Owning correction: AU7** — repair the **witness only**, preserving its intent (empty rails, empty network,
  closed surface) with a field the atlas accepts. **Weakening `NonIntegralCycleLift` to make the ordinal pass is
  prohibited.** `M3-CP4c2-TB-X2-R8-CAND-02`'s intended contract stays **unmeasured** until then.

- **Observed in TB4 AP6 report-only execution.** Ordinal 370 `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` executes once after the semantic gate verdict is already fixed and fails at `ASSERT_TRUE(atlasBuild)`. No cut graph is constructed and the appended `EmptyNetworkOnClosedSurface` error is therefore not measured.
- **Exact witness boundary.** The test loads the closed torus, builds source authority, then calls `FieldTransportAtlas::make(mesh, sourceAuthority, {}, make_zero_transport_field(mesh))`; that call returns failure before the test constructs the expected zero-node/zero-arc network. TB4 stdout does not print the atlas error code, so product cause cannot be assigned from runtime evidence alone.
- **Relationship to `M3-CP4c2-TB-X2-R8-CAND-02`.** The older product question remains active. TB4 does not answer it because its synthetic witness no longer reaches A2a′. Independent TB4 review must inspect the exact atlas failure and decide whether the test precondition is stale, the atlas correctly rejects this zero-field authority, or another product change is involved.
- **Accounting:** report-only, zero gate credit, newly gated/unaccepted surface, accepted 365-prefix unchanged. **+0 stable events / +0 recurrences**; totals remain **44 / 14 / 30**, debt **5**, semantic packages **71**.
- **`M3-CP4c-3-TB4-REV` adjudication — STILL UNCLASSIFIABLE, AND THE REASON IS ITSELF THE FINDING.** The test's
  `ASSERT_TRUE(atlasBuild)` **discards `atlasBuild.error()`**, which is in hand and for which
  `field_atlas_build_error_code_name()` exists — the `ORIENTATION.md` §8 anti-pattern, now at the **test**
  boundary rather than the pipeline funnel AP1 just fixed on the product side. The review therefore declines to
  choose among AQ5's three options and requires the code first (**AS3**).
  What *can* be said without guessing: the witness pairs `make_source_authority(mesh)` with a **globally constant
  ambient** `make_zero_transport_field` (`UnitX`/`UnitY` per face) on the closed torus, and the empty rail set is
  **intentional** — the test wants an empty network — so this is **not** the R8 `rails_from_atlas` trap that
  `ORIENTATION.md` §6 documents. The identity was appended at CB2 under AL7 and had **never executed** until TB4's
  report-only pass, so an original authoring defect is at least as likely as an interaction with the fail-closed
  checks CB2/CB3/CB5 added to the same `make` path; that distinction is exactly what AS3 decides. **AS3** also
  requires sweeping the test file for the same discard-the-typed-error pattern rather than fixing this one site.
  This is the fourth instance in this checkpoint of compiled-but-never-executed test authority turning out to be
  debt (`LESSONS.md` 56), and the strongest argument for retaining the AP6 report-only pass (**AS8**).
- **TB5 classification.** AS3 succeeded: ordinal 370 now publishes `fieldAtlasError=NonIntegralCycleLift;topologyRegion=0`. The test supplies a globally constant ambient `UnitX/UnitY` field with zero matching/effort on a curved closed torus; that synthetic field fails A1's cycle-integrality precondition before the intended empty-network A2a′ contract. Classify this record as **invalid diagnostic witness/precondition**; the atlas rejection is legitimate fail-closed behavior. Do not repair the witness in TB5. `M3-CP4c2-TB-X2-R8-CAND-02` therefore remains unmeasured. +0/+0.

- **`M3-CP4c-3-TB6` disposition — INVALID-ATLAS-WITNESS PRECONDITION RESOLVED; PRODUCT CONTRACT NOW MEASURED RED.** CB7's repaired ordinal-370 witness no longer returns `NonIntegralCycleLift`. TB6 reaches `SurfaceCutGraph` and observes error code **4 = `CellularityNotEstablished`** with no `sourceFace`, while the frozen identity requires code **6 = `EmptyNetworkOnClosedSurface`** plus a source-face locus. Close `M3-CP4c3-TB4-DIAG-CAND-01` as a witness-precondition issue; transfer the genuine measured product red to `M3-CP4c2-TB-X2-R8-CAND-02`. **+0/+0**.

## M3-CP4c3-TB4-ORCH-01 — TB4 runner expected the wrong package-73 digest-sidecar filename — **RESOLVED / PRE-RUNTIME / NON-STABLE**

- **Observed:** run/job `33436283363 / 99633462747` stopped before any Directional runtime with `package73-envelope-missing` after downloading the correct package artifact.
- **Root cause:** the runner expected `package73.tar.gz.sha256`; the frozen package-73 envelope contains `package73.sha256`. Control-only commit `41a7a8b92a311c240cfbcf320a4003d1f17dde7b` changed exactly the sidecar existence/hash read and did not touch package/source/test/fixture/selector bytes.
- **Closure:** authoritative retry `33436492493 / 99634138202` passed preflight and executed the semantic gate. **+0 stable events / +0 recurrences**.

## M3-CP4c3-TB3-ORCH-01 — package 71 loses executable modes at Actions artifact re-materialization — **RESOLVED / PACKAGE CONTRACT CORRECTED / NON-STABLE / PRE-RUNTIME**

- **Observed at `M3-CP4c-3-TB3` preflight**, run/job `33399144281 / 99510922630`, before any Directional process executed. Final package 71 verified byte/source/manifest authority but all six runtime executables were `0644`; selector execution was `0/373`.
- **Root cause independently established at `M3-CP4c-3-TB3-REV`.** Raw CB3 artifact `9750227619` (`b1cc9a989af2db84ddd2ad83babf9b2221396e45a165aa84927082e610c351c8`) stores every runtime binary as Unix `100755`; CB3 fixture packaging materialized it through `actions/download-artifact@v4`, which normalizes artifact files to `0644`, before re-uploading final package 71. Binary hashes stayed identical.
- **Correction and closure evidence.** Package-only `M3-CP4c-3-CB4-PKG` run/job `33411346157 / 99551438549` downloaded the raw artifact through the Actions artifact API, re-proved raw ZIP and extracted `0755` modes plus all six frozen hashes, copied exactly 27 fixtures only from the embedded verified source archive, regenerated the self-excluding 55-entry manifest, and created mode-preserving `package72.tar.gz`. Immutable package 72 is artifact `9765247195` (Actions SHA-256 `41ebe4dec4a3eb5c8194900a3f27a0377c3271212edd10fb952c48f55a6a2e6d`), inner tar SHA-256 `20630897aa432572d0929022abef3861fff80c2b5792c223071990dd2e3c6a73`. Independent post-download clean extraction again verifies all six exact hashes/modes, the 55-entry manifest, source/archive identity, GMP boundary, and 27 fixtures. No runtime-side repair occurred.
- **Semantic disposition.** Package 71 remains immutable and unusable; package 72 restores runtime transport authority without changing product/test/selector/fixture semantics or compiled bytes. No product semantic result was observed in TB3 or CB4-PKG.
- **Accounting:** resolved non-stable packaging defect, **+0 events / +0 recurrences**. Totals remain **44 / 14 / 30**, debt **5**, semantic packages **70**.

## M3-CP4c3-TB2-REV-CAND-01 — package-69/70 binary identity comparison — **RESOLVED / INDEPENDENT BYTE IDENTITY PROVED / NON-STABLE**

- **Observed statically at `M3-CP4c-3-TB2-REV`**, from committed records only; no runtime executed.
- **Mechanism.** TB2 executed a **different package** from the one CB2 froze. The substitution is acceptable in kind
  — package 70 adds no content, it **relocates bytes that were already immutable**, copying the fixture tree out of
  the embedded source archive whose SHA-256 `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`
  matched the frozen authority, into the `test-data` root the binary probes first — and no configure, compile,
  relink, repair or source edit occurred. **But the load-bearing claim is unverified:**
  `semanticBinariesUnchanged=true` is asserted by the same orchestration that produced package 70, and package 70's
  internal manifest has **55** entries against package 69's **28**, so the two manifests cannot be compared line for
  line. No per-binary SHA-256 from package 69 is published beside the corresponding digest from package 70.
- **Why it matters.** An executor may not be the sole witness to its own immutability, and a number and the
  expectation it is compared against must come from the same authority. Ordinals 1–365 passing on both packages is
  strong corroboration, not proof.
- **Closure evidence:** CB3 AN2 independently hashed packages 69 and 70 side by side and proved the packaged runtime binaries byte-identical. The evidence gap is closed; package 70 did not alter semantic binary bytes.
- **Accounting:** resolved evidence-surface gap on an unaccepted checkpoint. **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, semantic packages **70**.

## M3-CP4c3-TB2-ORCH-01 — packaged artifact fixture-root authority — **RESOLVED / BUILD-PACKAGING CONTRACT CORRECTED AND RUNTIME PROVED / NON-STABLE**

- **Original observation.** The first package-69 TB2 attempt reached ordinal 41 and failed before product adjudication because `TestFixturePaths` exhausted sibling/bin `test-data` probes and fell back to the missing absolute compile-time `DIRECTIONAL_TEST_SOURCE_DIR`. The exact manifest was already present in the immutable packaged source, so this was a harness-root defect rather than semantic evidence.
- **User-authorized remediation.** The user explicitly authorized an orchestration/fixture-only correction and same-turn package regeneration/re-execution. Package **70** (artifact `9744461475`, SHA-256 `4265079b78af1a95300eebdaa5f2b2643030aa1ad2f51b70f904d88b16de7fe5`) copies the immutable source fixture tree to sibling `test-data` and proves all package-69 semantic binaries byte-identical. No configure, compile, relink, product/test source repair, or benchmark occurred.
- **Closure evidence.** R4 run `33355714664` proved the exact sibling fixture manifest exists before runtime, reproduced package/source/GMP/selector/static-target-map authority, and advanced cleanly through the previous ordinal-41 stop. Its eventual first-red was semantic at ordinal 366, so the fixture-root defect is closed.
- **Accounting:** resolved non-stable orchestration candidate, **+0 stable events / +0 recurrences**. Stable totals remain **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 packages **69**.
- **`M3-CP4c-3-TB2-REV` — REOPENED AND RECLASSIFIED. The fix was applied to the execution, not to the defect.**
  Closing this as a resolved *harness* defect misfiles it, and the misfiling would cost a turn later, because **the
  defect lives inside the artifact under test**:
  - `tests/TestFixturePaths.h:51-64` resolves the fixture root by probing `<exe>/../test-data`, then
    `<exe>/test-data`, then returning the **compile-time absolute** `DIRECTIONAL_TEST_SOURCE_DIR` baked in by
    `cmake/DirectionalTests.cmake:307,377,409`. That value is the **build machine's** source directory. It is not a
    fallback: off the builder it is a guaranteed miss, and on the builder it succeeds **by coincidence of path** —
    exactly the kind of coincidence this project refuses to let an authority depend on.
  - Package 69's internal manifest has **28** entries and ships **no** fixture tree; package 70's has **55** and
    does. So the packaged artifact cannot locate its own fixtures, and **every future artifact-only TB needs the
    same out-of-band remedy** until a Code + Build turn fixes it.
  - The risk if left alone is not inconvenience: a green TB could depend on a runner's directory layout, which makes
    **gate authority environment-dependent**.
  - **Unmeasured and not guessed:** TB1 executed 366 ordinals on package **68** without hitting this. Whether that
    is because 68 shipped a fixture tree or because the runner path happened to match is not established.
  - **Owning correction: AN3** — either the packaging step ships the fixture tree at a package-relative root the
    binary probes, or the resolver **fails closed** with a typed error naming the roots it tried. A silent
    fall-through to a build-machine path is prohibited. AN3 must also report whether package 68 shipped fixtures, so
    the open question is answered rather than left.
  - Accounting is unchanged by the reclassification: **+0 events / +0 recurrences**.


- **Final closure evidence at CB3/TB3-R1.** CB3 AN3 removed the compile-time `DIRECTIONAL_TEST_SOURCE_DIR` fallback and package 71/72 carries exactly 27 fixtures at the package-relative root. TB3-R1 package-72 preflight found that root without repair and runtime advanced through the former ordinal-41 fixture stop to a semantic first red at ordinal 366. The artifact no longer depends on builder-path coincidence.
## M3-CP4c3-TB2-CAND-01 — mechanical `MissingSingularityBranchTransport` first-red — **PRIOR FAILURE LOCUS CLEARED / SUPERSEDED BY DOWNSTREAM FIRST RED / NON-STABLE**

- **Observed in valid TB2 R4.** Immutable execution package 70 preserves semantic source `005512f20ed56edc793f4d6505f3d2b4c2999c71`, byte-identical package-69 binaries, source archive `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`, and selector 373 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`. R4 preflight and postflight were immutable.
- **Measured boundary.** Ordinals **1–365** each selected exactly once and exited 0. Ordinal **366**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, selected exactly once and exited 1 with `InvalidFieldTransportAtlas/field-transport-atlas/MissingSingularityBranchTransport`. First-red semantics left ordinals 367–373 unexecuted.
- **What changed relative to TB1.** The same mechanical witness previously stopped at `IncompleteCycleBasis → CycleTransportAdjacencyMissing`. The valid R4 observation proves the CB2/Amendment-15 implementation advances past that earlier stop; it does **not** by itself explain why the later singularity attachment asks for a branch transport.
- **Review boundary.** Do not infer that a hard-feature barrier should receive transport adjacency. Amendment 15 explicitly prohibits that shortcut. Independent `M3-CP4c-3-TB2-REV` must trace `build_singularity_attachments` and the slit-bound prescribed-singularity representation to determine whether this is an invalid consumer expectation, a missing non-barrier attachment route, or another upstream representation mismatch.
- **Accounting:** current checkpoint is unaccepted and the accepted 365-prefix is green, so this is **+0 stable events / +0 recurrences**. Stable totals remain **44 / 14 / 30**; debt **5**.
- **`M3-CP4c-3-TB2-REV` — CAUSE ESTABLISHED, by the same elimination as TB1, one consumer later.**
  - **Mechanism, read at source.** `build_singularity_attachments` (`FieldTransportAtlas.cpp:597-618`) walks the
    ordered one-ring fan of a singular vertex and demands a branch transport on **every** radial edge, failing with
    `MissingSingularityBranchTransport` when `find_branch_transport_in` returns null.
    `ordered_incident_fan` (`:351-402`) builds that fan from the **global** `sourceMesh.F`, takes no region, no
    barrier set and no local mesh, and at `:398` **requires the walk to close back on its first face**. And
    `build_branch_transports` (`:304-342`, invoked at `:1827`) is built purely from `adjacencies` — bucket 4 of the
    classification at `:1456-1491` — which **excludes every `SourceBoundary`, `HardFeature` and `NonTraversable`
    edge by construction**.
  - **Elimination.** The failing radial edge is absent from `adjacencies`, so it is `SourceBoundary`,
    `NonTraversable` or `HardFeature`. On this witness `SourceBoundary` is excluded because the domain is closed
    (`globalEF = localEF = 1,158`, `boundaryLoops = 0`) and `NonTraversable` because there is exactly **one** region
    over all 300 faces sharing one raw component. **It is a `HardFeature` edge**: a singular vertex of the
    mechanical witness is incident to a barrier, and the port derivation demands transport across it.
  - **Pre-existing and unmasked — the decisive check.** Call order is `build_branch_transports` `:1827` → the region
    cycle-basis loop `:1865` → `build_singularity_attachments` `:2384`, so the cycle failure fired first at TB1. And
    CB2's diff to this file **begins at old line 842**, leaving `build_branch_transports`, `ordered_incident_fan`
    and `build_singularity_attachments` untouched. **Not a regression, not a side effect of the cut, and not a
    defect in Amendment 15's implementation** — the witness simply got further.
  - **A degree-1 tip is not exempt.** Its star is not split (one component of `star(v) ∖ B(R)`), but the ring walk
    still straddles the single barrier ray, so every barrier-incident singular vertex is affected.
  - **Corrective frame: Amendment 16** (`DESIGN.md` §7.2.1) — every A1 derivation that walks transport is a
    transport-domain operation; a barrier is never traversed, never supplied with a branch transport, and never
    required to have one; a closed ring is replaced by the fan of one connected component of `star(v) ∖ B(R)`.
    Supplying a barrier with a branch transport so the fan closes is the port-derivation form of Amendment 15's
    prohibited option C.
  - **Policy deliberately NOT decided:** whether an *open* sector fan still emits ports (**P1**) or emits none while
    the slit boundary cycle absorbs the index (**P2**, consistent with AM4 today but meaning **no traces start at
    that singularity**). **AN4** forbids designing across it until **AN1**'s barrier-incident singularity census
    reports. CB2 already holds the contradiction in miniature: AM4 binds such a vertex to a slit boundary cycle
    while the port derivation demands a closed transportable ring for the same vertex.
  - **Diagnostic gap owned by AN1:** the typed error at `:613-616` carries the radial `sourceEdge`, `sourceFace`,
    `sourceVertex` and `topologyRegion`, and the harness published only `code/stage`
    (`tests/FieldAlignedCurveNetworkTests.cpp:5283-5285`), so the locus had to be recovered by elimination rather
    than read. `LESSONS.md` **67**.
  - **Closure condition:** ordinal 366 green in a run reaching at least 366. **+0 events / +0 recurrences.**

- **TB3-R1 runtime disposition.** Package 72 executes the same ordinal 366 through atlas construction without `MissingSingularityBranchTransport` and reaches the later field-aligned-network error `VertexTransitSectorUnresolved`. The prior failure locus is therefore cleared. Because ordinal 366 is still red, this does not close C2 or CP4c-3; the active gating blocker is now `M3-CP4c3-TB3-R1-CAND-01`.
- **Accounting remains +0/+0.** The prior candidate was non-stable on an unaccepted checkpoint; clearing its failure locus does not alter cumulative stable totals.

## M3-CP4c3-DEFN-R1-CAND-01 — the interior-singularity binding does not fail closed while the boundary one does — **ACTIVE / CORRECTIVE COMPILE-GREEN / GATING AT 373 / NON-STABLE**

- **Observed statically at `M3-CP4c-3-DEFN-R1`** while deriving Amendment 15, on the source TB1 executed
  (`48dd011c4aa689a245b74527ed9df0900ada9bf3`, working tree byte-identical). No runtime was executed.
- **Mechanism.** `FieldTransportAtlas.cpp:1546-1564` partitions prescribed singularities into `rawSingularity` and
  `rawBoundarySingularity` using **`sourceMesh.isBoundaryVertex`** — the *global* mesh. Both are then reconciled,
  and the two reconciliations disagree about failure:
  - `:1960-1976` (**boundary**) demands an owner in `boundaryCycleByGlobalVertex`, checks the owning cycle's kind
    and `turningLift`, and raises `SingularityMismatch` when either is absent or wrong. **Fails closed.**
  - `:1980-1990` (**interior**) calls `localCycleByGlobalVertex.find(rawVertex)` and, on a miss, simply leaves
    `region` and `cycle` as empty `std::optional`s and continues. The loop emits a `FieldSingularityFact` with **no
    region and no cycle binding, and no error.** **Fails open.**
- **Why it matters now.** Under Amendment 15 every vertex incident to `B(R)` becomes a **boundary** vertex of the
  cut local mesh, so it leaves `interiorLocalVertices` and no `LocalVertex` cycle is emitted for it. Two effects
  compound: `:1843-1851`'s check that the atlas's computed `turningLift` equals the **prescribed** index at that
  vertex stops running; and because the partition key is the *global* boundary flag, such a vertex is still
  classified an *interior* singularity and therefore takes the permissive path. **A prescribed singularity sitting
  on a feature arc goes from verified-against-holonomy to unverified-and-unbound, with a green build.**
- **Not introduced by the amendment.** The asymmetry exists at HEAD and is reachable today by any configuration
  that yields a prescribed interior singularity with no local-vertex cycle. Amendment 15 makes it reachable **by
  construction** on every witness with an open feature arc, which is why it must be closed in the same change.
- **Pattern:** the `ORIENTATION.md` §8 quiet-weakening family — "a representation change breaks its consumers in
  two ways and only one of them tells you" — in its sharpest form: two paths discharging one obligation, alike in
  what they *do* and opposite in what they *report*. Aggravated by a split key that belongs to a different object
  than the thing reconciled (the **global** mesh's boundary flag deciding how a **local** mesh's cycle is checked).
  Recorded as `LESSONS.md` **65**.
- **Owning correction:** **AM4** — every `rawSingularity` entry must bind to exactly one cycle (a `LocalVertex`
  cycle, or the boundary cycle of the slit loop that consumed its vertex), and an unbound prescribed singularity is
  a **typed failure**, not a `nullopt` field. Publish per witness the counts bound to a local-vertex cycle, to a
  slit boundary cycle, and to nothing; the last must be zero. **AM9** prohibits landing AM2 without AM4.
- **Closure condition:** a run in which the mechanical witness reports zero unbound prescribed singularities and
  gated identity `PrescribedSingularityOnABarrierArcRemainsBoundToACycle` (appended under AM8, gate **373**) is
  green.
- **`M3-CP4c-3-CB2` disposition — CORRECTIVE IMPLEMENTED / COMPILE GREEN / RUNTIME PENDING.** AM4 now requires an explicit cycle binding and reports local-cycle/slit-boundary/unbound counts. Evidence source `005512f20ed56edc793f4d6505f3d2b4c2999c71` compiles in GMP package **69**; ordinal **373** is compiled but unexecuted. Candidate remains non-stable until TB proves `unbound=0`.
- **TB4 AP6 diagnostic disposition.** Ordinal 373 `PrescribedSingularityOnABarrierArcRemainsBoundToACycle` executes once report-only and **PASSes**. This satisfies the identity half of the closure condition, but the record remains active because TB4's mechanical failure output does not publish the required zero-unbound prescribed-singularity count. No stable count change.
- **Stable-count rationale:** found by static derivation in a definition turn; no accepted behaviour is lost. Its new gating identity is compiled but unexecuted, so there is still no semantic recurrence evidence. **+0 events / +0 recurrences.** Totals remain
  **44 / 14 / 30**, debt **5**, M3 packages **69**.

## M3-CP4c3-DEFN-CAND-01 — mechanical A1 `IncompleteCycleBasis` measured as `CycleTransportAdjacencyMissing` — **CORRECTIVE PROVED AT RUNTIME / RETAINED ACTIVE ONLY FOR ITS UNEXECUTED CONFIRMING IDENTITIES / NON-STABLE**

- **Observed statically at `M3-CP4c-3-DEFN`**, on the source accepted at CP4c-2
  (`57444781af7bdc460e38cc68930a9a8c8199eeea`): `src/authority/FieldTransportAtlas.cpp` returns
  `FieldAtlasBuildErrorCode::IncompleteCycleBasis` from **eight sites** for **seven distinct conditions** —
  `:1597` (`PCFaceTangentBundle::init` threw), `:1613` (cycle/curvature/column counts disagree with
  `interiorVertices + boundaryLoops + 2·genus`), `:1673` (a cycle coefficient is neither ≈0 nor ≈±1, or a column is
  out of range), `:1682` (**no `FieldTransportAdjacency` for a cycle's edge**), `:1688` (a local edge has a negative
  incident face), `:1700` (`order_cycle_steps` failed), `:1751` (per-kind cycle partition counts disagree), `:1818`
  (boundary-cycle count ≠ `boundaryLoops.size()`). **Five publish nothing but a region id.**
- **Impact:** the mechanical witness — criterion **C2**, now gated at ordinal 366 — has been recorded for the whole
  CP4c arc as "no atlas — stops in A1 at `IncompleteCycleBasis`", and **no diagnostic has ever been run on it**.
  `ROADMAP.md`'s framing of CP4c-3's parent responsibility as "missing field-transport adjacency" matches site
  `:1682` specifically, but that is **one site among seven and has never been confirmed**.
- **Pattern:** `LESSONS.md` **57**, recurring in A1. CP4c-2 spent **eight turns** reasoning about cellularity because
  `topology_error` collapsed 36 codes into `CellularityNotEstablished`; AF0's additive `originatingTopologyError`
  provenance field ended it without touching the mapping. The same fix applies here.
- **Second-order gap:** `:1613`, `:1751` and `:1818` all derive their expectations from the *local region mesh*
  built by `make_local_region_mesh` (`:850-895`) from a region's faces plus all their vertices, so
  `isBoundaryVertex`, `boundaryLoops` and the expected counts depend on that mesh's shape. The site alone will not
  explain a count mismatch.
- **No mechanism is promoted.** Candidate readings exist but are hypotheses; the measures exist so the next turn
  reports a measurement rather than adopting one. This is the R2 discipline, which has shortened the last three
  checkpoints.
- **Owning correction:** **AK1** (additive enumerated-reason provenance at all eight sites — an enumerated reason,
  **not** a line number; `LESSONS.md` 62's stale `419/437/474` labels are the counter-example; no re-mapping, no
  enum renumbering, no new error code), **AK2** (publish the per-region local-mesh shape and every count for the
  mechanical witness), **AK6** (the fix, phase 2, naming the measured site). **AK8** requires the implementer to
  re-derive the site enumeration by search rather than copying the DEFN's table.
- **Closure condition:** ordinal 366 green in a run reaching at least 366.
- **Stable-count rationale:** diagnostic-authority finding on an unaccepted checkpoint; the accepted 365 is green.
  **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, M3 packages **68**.
- **TB1 runtime measurement — mechanism no longer ambiguous.** Authoritative artifact-only run/job
  `33340448381 / 99335020672` re-proves 365/365 and first-red stops at ordinal **366**. The gated identity reports
  `IncompleteCycleBasisReason=CycleTransportAdjacencyMissing`; the report-only mechanical identity independently
  repeats the same discriminator.
- **AK2 measured locus:** topology region `0`, source edge `0-3`, `fieldTransportAdjacencyExists=false`,
  `globalEF=1,158`, `localEF=1,158`, local boundary edges `0`. The region row is
  `V/E/F=152/450/300`, χ=2, boundary loops=0, genus=0, interior vertices=152, expected cycles=152,
  cycle rows=152, cycle curvatures=152, inner adjacencies=450, with local mesh and tangent bundle both available.
  The count/dimension branches therefore agree; the failing discriminator is specifically the missing transport
  adjacency for the cycle edge.
- **Disposition boundary:** this TB measured the mechanism but does not design the fix. The independent phase-1
  review owns AK6 causal interpretation and corrective ordering. Ordinal 366 remains red, so the candidate remains
  active. **+0 stable events / +0 recurrences.**
- **`M3-CP4c-3-TB1-REV` — CAUSE ESTABLISHED.** Edge `0-3` is a **`HardFeature` barrier**, derived by elimination
  over the four buckets `FieldTransportAtlas::make`'s adjacency loop routes every row of `mesh.EV` into:
  `SourceBoundary` is excluded by `globalEF=1,158` (the edge has two incident faces); `NonTraversable` is excluded
  because the region count is **1** over all 300 faces, so both incidences are region 0 and share a component;
  `adjacencies` is excluded by the measured `fieldTransportAdjacencyExists=false`. Only `HardFeature` remains.
  **Nothing is missing by accident — the atlas deliberately created no adjacency for a barrier.**
- **Why it is in the cycle basis anyway.** `build_source_topology_regions`
  (`src/geometry/SurfaceCellTracing.cpp:6655-6737`) skips `options.hardFeatureEdges` when flood-filling the
  face-adjacency graph, but **skipping an adjacency disconnects nothing unless the removed edges separate the
  graph**. Here they did not: region 0 is all 300 faces with `boundaryLoops=0`. `make_local_region_mesh`
  (`src/authority/FieldTransportAtlas.cpp:850-895`) therefore builds a local mesh in which edge `0-3` is
  **interior** — `localEF=1,158`, 0 local boundary edges — so `PCFaceTangentBundle` counts it among the 450 inner
  adjacencies, the cycle basis spans it, and the walk calls `find_adjacency_in(adjacencies, edge)` for an adjacency
  that by design does not exist.
- **Root cause, stated once:** **the region decomposition and the traversability classification disagree about the
  same edge.** A1's cycle-basis machinery assumes region boundaries and non-traversable edges coincide — true for
  source boundaries and for *separating* feature curves, false for a feature that does not separate. Neither
  classifier is wrong on its own terms; the coincidence was never written down as an invariant.
- **Why this is forced rather than exotic.** Region 0 is `χ=2`, `genus=0`, `boundaryLoops=0` — a sphere — and every
  closed curve on a sphere separates it. Since the hard features demonstrably did not separate, **the mechanical
  witness's feature set necessarily contains at least one open arc**. The torus builds its atlas fine only because
  its 48 hard-feature edges form four closed loops that **do** separate it into four annuli, placing them on region
  boundaries where they never enter a local mesh's inner set. The first witness with an open feature arc was always
  going to hit this.
- **The corrective is a normative choice, not an implementation detail**, because it changes what a topology region
  *is* when a barrier does not separate — a `DESIGN.md` §7.2/§7.2.1 question a CB may not settle. Options:
  **A** cut the local region mesh along the non-separating barrier arc so it becomes real boundary (**recommended**;
  `isBoundaryVertex`, `boundaryLoops`, `χ` and `expectedCycleCount` all become self-consistent and barrier edges
  leave the inner set; the hard part is the arc's **endpoints**, where the cut surface touches itself, and the work
  is local to `make_local_region_mesh`); **B** build the cycle basis over the traversable sub-complex only —
  converges on A, since `PCFaceTangentBundle::init` takes a mesh, not a barrier set; **C** give barrier edges a
  transport adjacency — **PROHIBITED**, it destroys the barrier semantics hard features exist to express and would
  silently let transport cross a feature; **D** fail closed with a precise typed error naming "a non-separating
  barrier edge remains interior to its region" — not a fix, but the correct frozen fallback if A exceeds CP4c-3, at
  the explicit cost that CP4c-3 cannot then close on criterion **C2**.
- **Owning corrections after review:** **AL2** (the DEFN-R1 normative decision, including the endpoint treatment
  written down with its derivation, and shown-not-asserted consistency of `χ`/`boundaryLoops`/`expectedCycleCount`
  for a slit region, recorded as a `DESIGN.md` §7.2.1 amendment), **AL5** (the implementation, naming which option
  was taken and why), **AL1** (publish the feature set's connected-arc decomposition — components, closed loops,
  open arcs, endpoint vertices — confirming the elimination directly and sizing option A).
- **Closure condition unchanged:** ordinal 366 green in a run reaching at least 366. **+0 stable events /
  +0 recurrences.**
- **`M3-CP4c-3-DEFN-R1` — CORRECTIVE DEFINED (Amendment 15, `DESIGN.md` §7.2.1).** Option **A′**: A1 derives its
  tangent bundle, cycle basis and index quantities from the region **cut along** `B(R)`, in A1's **derived local
  mesh only**; the `SurfaceTopologyRegion` product's face set, `euler_characteristic()` and
  `boundary_loop_count()` are untouched.
  - **Scope is provably exactly `B(R)`.** The four adjacency buckets (`:1456-1491`) are ordered so that a
    `SourceBoundary` edge and a region-/component-crossing `NonTraversable` edge each have at most one incident
    face in a region and are therefore **already** local boundary edges; a bucket-4 edge has an adjacency. Only a
    hard feature can be non-traversable *and* interior. **Isolation seams are not barriers** — same region, same
    component, different sheet, not a hard feature (`SurfaceCellTracing.cpp:6837-6851`) — they fall through to
    bucket 4 and do get an adjacency, and must not be swept into the fix.
  - **The cut never disconnects**, because a region *is* a connected component of the face graph built while
    skipping every hard-feature edge (`:6715-6741`). Corollary: no subset of `B(R)` separates `R`, so on a
    `χ=2, b=0` region every component of `B(R)` is a **tree**.
  - **Why not at the region level:** `build_source_topology_regions` requires every region-boundary vertex to have
    exactly two boundary neighbours (`:6905`) and fails the whole `SourceTopologyRegions` product otherwise. An
    open arc's tip would have one, so a slit is **inexpressible** there. The slit needs vertex duplication, which
    only the local mesh can do.
  - **Endpoint rule:** `copies(v)` = connected components of `star(v) ∖ B(R)` = `d_B(v)` interior, `d_B(v) + 1` on
    the boundary; an open arc's **tip is not duplicated** but becomes a boundary vertex. Manifold with boundary;
    no geometry moves; `TriMesh::set_mesh` re-derives every count from the rewritten face array.
  - **Identity:** `χ(R_cut) = χ(R) − χ(B) + ∂`. Mechanical witness: `χ' = 2 − c`, `b' = c`, `genus' = 0`,
    `interiorVertices' = 152 − |V(B)|`, `expectedCycleCount' = 152 − |V(B)| + c`, `innerAdjacencies = 450 − |B|`,
    and the cycle matrix's rank deficiency stays exactly **1** — unchanged from today.
  - **The failure becomes structurally impossible:** `dual_cycles` indexes its columns into **inner edges only**,
    so a barrier that is now a boundary edge can never be a column and `find_adjacency_in` is never called for it.
  - **Three required controls, else the fix is a quiet weakening:** replace (never delete) the `:1654`
    local-mesh-versus-region cross-check with the cut identity under a new appended code (**AM3**); disclose that
    a slit region moves from the closed `ClosedShenSufficient` index **equality** (`:1872`) to the
    boundary-corrected `RelativeBoundary` branch (`:1878-1898`), which absorbs any multiple of 4 (**AM6**); and
    make the interior-singularity binding fail closed (**AM4**, `M3-CP4c3-DEFN-R1-CAND-01`).
  - **Frozen fallback D** — a new appended `IncompleteCycleBasisReason` naming "a non-separating barrier edge
    remains interior to its region" — is taken **only** if AM4's control cannot be made to fail closed without
    changing an accepted A1 contract, must be declared in the CB report, and means **C2 cannot close**.
  - **Owning correction now:** **AM1** (publish `B(R)`'s decomposition first), **AM2** (the cut), **AM3**–**AM6**
    (the controls), **AM8** (gate append 367 → 370 → **373**). Prediction on record: `B(R)` contains **no cycles**
    on the mechanical witness; a measured cycle falsifies the theorem and reopens the amendment.
- **`M3-CP4c-3-CB2` disposition — OPTION A′ IMPLEMENTED / COMPILE GREEN / RUNTIME PENDING.** The A1 derived-local-mesh cut, barrier decomposition, cut identity, fail-closed singularity control and index/witness diagnostics compile at `005512f20ed56edc793f4d6505f3d2b4c2999c71` in package **69**. Supporting ordinals **371–373** and gating mechanical ordinal **366** are unexecuted; the candidate remains active/non-stable until TB.
- **Current accounting after CB2:** stable totals remain **44 / 14 / 30**, debt **5**, M3 packages **69**.
- **`M3-CP4c-3-TB2` / `TB2-REV` disposition — CORRECTIVE PROVED AT RUNTIME.** Run `33355714664` advanced the
  mechanical witness **past** `IncompleteCycleBasis`: the cut transport domain is constructed, the tangent bundle
  initializes, the cycle basis is built and validated, index accounting completes, and execution reaches
  `build_singularity_attachments` at `:2384`. The failure this record owns **no longer occurs**. Ordinals
  **1–365 are green**, so the change regressed nothing in the accepted gate.
  CB2 also implemented the endpoint rule **better than Amendment 15 specified it**: rather than applying the formula
  `copies(v) = d_B(v)`, `make_local_region_mesh` (`:1030-1104`) implements the *definition* — it flood-fills the
  star's face-adjacency graph with barrier edges removed and creates one local copy per component — so tips, branch
  vertices and boundary vertices need no special case and a formula error is impossible.
  **Retained ACTIVE for one reason only:** first-red at ordinal 366 left ordinals **371–373 unexecuted**, so the
  confirming identities — barrier exclusion from the cycle basis, the Euler cut identity, unbound prescribed
  singularities = 0 — have **never run**, and AM1's barrier decomposition, though computed, was not reported. Every
  DEFN-R1 prediction stays unverified, including the falsifier "a measured cycle in `B(R)` reopens the amendment".
  Closes when ordinals 371–373 execute green. **+0 events / +0 recurrences.**
- **TB5 AP6 disposition.** Ordinals 371 and 372 execute report-only but are blocked upstream by the mechanical vertex-11 `VertexTransitSectorUnresolved`; they remain unmeasured, not falsified. Ordinal 373 passes on its synthetic fixture only. The record remains ACTIVE until the mechanical production witness supplies the required zero-unbound proof. +0/+0.

## M3-CP4c3-TB1-ORCH-01 — three pre-runtime preflight controls before authoritative TB1 — **CLOSED / ORCHESTRATION / NON-STABLE**

- `33340136751` stopped in preflight on the `strings | grep -q` / `pipefail` control interaction.
- `33340220758` stopped in preflight on an over-strict dynamic `libgmpxx` runtime-library expectation even though
  package/link evidence already established GMP/GMPXX authority.
- `33340336194` stopped in preflight because the source-archive SHA-256 had been transcribed as a malformed 63-hex
  value.
- No Directional binary ran in any of the three attempts. Package 68, source, selectors, tests and fixtures remained
  immutable. Corrected run `33340448381` completed preflight, semantic execution and postflight successfully and is
  the sole TB1 runtime authority.
- **Stable-count rationale:** control-plane only; **+0 events / +0 recurrences**. Totals remain **44 / 14 / 30**,
  debt **5**, M3 packages **68**.
- **`M3-CP4c-3-TB1-REV` — closed, but escalated.** The malformed 63-hex source-archive digest in `33340336194` is
  the **third** occurrence of `R7-ORCH-01`, the defect `LESSONS.md` **22n** and measure **AE4** were written to
  prevent and which cost a whole turn once already. AE4's rule — validate every expected digest as exactly 64
  lowercase hex at authoring time — has now failed to prevent its own defect twice, so a reminder is demonstrably
  insufficient. **AL8** moves the validation into the orchestration payload **authoring path**, so the check runs
  where the value is written rather than depending on an author remembering it. Disposition of this record is
  unchanged: control-plane only, **+0 events / +0 recurrences**.

## M3-CP4c2-TB-X2-R10-CAND-01 — Amendment 14's ordinary trace-crossed proposal path is structurally unreachable; only saturation promotes such an edge — **ACTIVE / QUALITY / COVERAGE / NON-STABLE**

- **`M3-CP4c-3-TB6` confirmation.** Ordinal 369 again reaches the intended assertion and reports `certificate.saturationUsed=true`. Finding remains ACTIVE/deferred; zero gate credit and **+0/+0**.

- **Observed:** R10 (run/job `33331453506 / 99310594268`, package `9736088354`) published, for the AG5
  trace-crossed witness: `ordinary_proposal_selected_trace_crossed_edge=no`, `saturation_used=yes`,
  `selected_trace_crossed_edge_exists=yes`, `subdivided_crossing_exists=yes`. Ordinals 363/364/365 all PASS.
  `AH6`'s stated condition has fired.
- **Mechanism, read from the committed loop and not accidental:** the proposal is
  `barriers = mandatory ∪ traceCrossed ∪ cuts; components = proposal_components(topology, barriers);
  proposed = proposal_tree_cotree_cut_edges(topology, component, barriers)`. DEFN-R2 §4.5's **filter** was correctly
  removed — only `mandatory` is skipped now — but the **barrier set still contains `traceCrossed`**, so every
  trace-crossed edge *bounds* a proposal component instead of lying inside one, and a tree–cotree generator search
  draws from edges interior to its component. **The ordinary path therefore almost never has a trace-crossed edge
  available to propose**, and saturation is the only route by which one enters the cut set.
- **Cause — the reviewer's, owned.** DEFN-R2 §4.5 explicitly permitted keeping the conservative barrier set on the
  reasoning that *"over-separation costs extra cuts, never correctness."* True about correctness, wrong about
  coverage: over-separation makes the edges Amendment 14 newly admitted **structurally unreachable** by the ordinary
  proposal. DEFN-R2 prediction 5 said saturation firing anywhere is "a finding"; it fired, and this is it.
- **What remains proved regardless.** Saturation changes *which* edges are selected, not *how* a selected edge is
  represented. Ordinals 363/364 assert on an actually-promoted trace-crossed edge — `selectedTraceCrossed`
  non-empty, `foundSubdividedCrossing`, a degree-four node with two `Cut` and two `Trace` rays — and those hold
  whichever path selected it. Amendment 14's **representation** is fully proved; completeness is unaffected, since
  DEFN-R2 §5.1's theorem guarantees a sufficient cut set exists and saturation reaching it is the theorem working.
- **What is at stake:** cut-graph **quality**. A saturated cut set promotes far more edges than a tree–cotree
  selection would, producing many small regions; and a production witness firing saturation is now
  indistinguishable from this expected case.
- **This did not withhold CP4c-2's closure.** Gate 365 was frozen at CB7 under AG7 before any of this was known,
  every identity in it passed, and the run is valid. Adding a coverage condition after the evidence arrived would be
  the goalpost-moving this project corrected twice — including when the evidence favoured being strict
  (`PR8-R044` at R7-REV). The discipline holds when it favours leniency too.
- **TB4 AP6 diagnostic disposition.** Ordinal 369 executes report-only and reaches its intended quality assertion; `certificate.saturationUsed` is `true`, so the ordinary trace-crossed proposal is still not selected without saturation. This directly reconfirms the active quality/coverage finding but adds no stable recurrence because the identity is on an unaccepted/report-only surface. TB4-REV owns scheduling relative to the mechanical blocker.
- **TB5 AP6 disposition.** Ordinal 369 again reaches the intended assertion and reports `certificate.saturationUsed=true`. The quality/coverage finding is reproduced unchanged; report-only evidence carries zero gate credit and adds +0 stable recurrences.
- **CP4c-3 DEFN disposition:** carried to CP4c-3 as owner, corrective unchanged and now measure **AK4**; the
  §6.2 identity `SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` is named for append into
  the gate under **AK7**, so the ordinary path stops being ungated.
- **Owning correction:** **AJ4 / AK4**. Replace the conservative `traceCrossed` barrier contribution with the per-face
  **trace-segment chord** model the fragment machinery already uses, so a trace-crossed edge is interior to its
  component and available to the ordinary proposal. This touches the **proposal heuristic only** — Amendment 13 §3
  already denies it certification authority — so it does **not** reopen Amendment 14 or any certificate. Requires a
  witness in which the ordinary proposal selects a trace-crossed edge with `saturationUsed=false`, retaining the
  AG5 witness as the positive saturation case.
- **Stable-count rationale:** quality/coverage finding on a checkpoint whose gate is green; no accepted-green
  behaviour lost. **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, M3 packages **67**.
- **`M3-CP4c-3-TB1-REV` disposition — UNCHANGED, and unblocked.** TB1 touched nothing this record depends on. It
  shares no locus with the mechanical A1 cause (`M3-CP4c3-DEFN-CAND-01`) or the sphere's A2a′ cause
  (`M3-CP4c2-TB-X2-CAND-04`), so it neither blocks nor is blocked by either. Carried as phase-2 work under **AL6**
  with its AK4 corrective and AK7 gate append exactly as written.
- **`M3-CP4c-3-CB2` disposition — IDENTITY GATED, PRODUCT CORRECTIVE NOT CLAIMED.** Ordinal **369** `OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` is frozen/compiled in selector 373, but CB2 does not establish that the canonical proposal heuristic changed; runtime remains required and the candidate stays active/non-stable.

## M3-CP4c2-TB-X2-R9-CAND-01 — trace-crossed selected cut edge is subdivided into multiple arcs but region binding still requires exactly one — **CLOSED AT R10-REV / PRODUCT AUTHORITY-SHAPE MISMATCH / NON-STABLE**

- **R10-REV disposition — CLOSED.** The frozen condition was *ordinals 363, 364 and 365 all green in a run reaching
  365*; R10 satisfies it exactly, and the CB8→CB9 diff was audited line by line to confirm the fix was the specified
  conversion rather than an accommodation. `arcIndices.size() != 1U` became `arcIndices.empty()`, dropping only the
  upper bound and **retaining a typed `InvalidCutGraphBinding` for zero arcs**; the per-face body now runs once per
  sub-arc with both existing guards retained; and the stale "ordinary embedded source-edge barriers" comment was
  replaced with one that **names the canonical-direction dependency** the dart formula rests on.
- **The silent consumer was fixed and the fix *tightens*.** `:1264-1281` resolves each sub-arc endpoint through the
  shared `NodeLocus` authority and inserts a source vertex only when the node has a `vertex` locus, so a crossing
  node contributes nothing; a node with no locus now returns a typed error, a path that did not previously exist.
  Because `boundaryVertices` is a skip list this change can only *reduce* skipping — it cannot manufacture a pass,
  only create new reds, and none appeared. `build_node_loci` is now computed once and threaded to both consumers,
  removing a pre-existing redundant recompute in `validate_no_region_fragment_pinch`.
- **The fragment reconciliation is proved by the product, not merely published.**
  `GlobalTopologyPlan.cpp:679-687` unconditionally rejects unless
  `fragmentOrbits[face].size() == tracePieceCount[face] + 1` for every face, and that guard is untouched by CB9.
  Ordinal 363's pass therefore proves R9-REV §2.3's geometric argument on every face of the witness, including those
  incident to a promoted trace-crossed edge. The 178 retained diagnostic rows are corroboration; **AJ3** still
  requires them read and compared.
- **First runtime proof of two long-pending contracts:** ordinal **364**, the degree-four two-Cut/two-Trace
  edge-locus rotation — the single genuine code gap DEFN-R2 named, compiled and unexecuted for three turns — and
  ordinal **365**, the saturation last resort, which publishes its fields while cellularity remains independently
  proved by the actual embedded-graph certificate afterwards.
- **Accounting:** closure is a status change, not a count change. Totals remain **44 / 14 / 30**, debt **5**,
  M3 packages **67**.

- **Observed:** authoritative R9 run/job `33319911575 / 99279955697` re-proves 355/355 and passes ordinals 356-362, then ordinal 363 `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs` selects exactly once and fails with typed `InvalidCutGraphBinding`. Frozen hard stop leaves 364-365 unexecuted.
- **Runtime preconditions reached:** the witness retains an exact trace/source-edge crossing; `SurfaceCutGraph::make` succeeds; its certificate proves cellularity; and at least one selected cut candidate is classified `TraceInteriorCrossing`. The failure is therefore downstream in `GlobalTopologyPlan::make`, not in cut selection.
- **Localized mechanism:** `EmbeddedGraphTopology.cpp:503-545` deliberately splits a selected cut source edge at every synthetic cut/trace crossing and emits one Cut arc per consecutive point pair. `GlobalTopologyPlan.cpp:479-499` then gathers all Cut arcs carrying each selected source edge and returns `InvalidCutGraphBinding` unless `arcIndices.size() == 1`. The Amendment-14 subdivision therefore violates a stale single-arc binding assumption.
- **Secondary diagnostic issue:** the test helper at `FieldAlignedCurveNetworkTests.cpp:1710-1713` uses non-fatal `EXPECT_TRUE(built)` and then unconditionally calls `built.value()`, producing `std::get: wrong index for variant` after the real typed failure. This does not change the primary diagnosis.
- **Disposition boundary:** independent `M3-CP4c-2-TB-X2-R9-REV` owns corrective planning. EXEC does not change implementation/test logic or authorize a retry. AH6 is not applicable because 363-365 were not all reached.
- **Stable-count rationale:** ordinal 363 is newly gated and CP4c-2 has never been accepted; inherited 355/355 remains green. **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, M3 packages **66**.
- **R9-REV adjudication — CONFIRMED as a genuine product defect, the first in this arc.** Historical review authority is consolidated in `M3_CP4c_Consolidated_Record.md` §3.7. Unlike R8's ordinal 359, the witness is not
  at fault: it proved an exact crossing, built a **cellular** cut graph, and selected a `TraceInteriorCrossing`
  candidate. A2a′ did its job; A2b rejected the result.
- **The producer is correct, verified line by line.** `EmbeddedGraphTopology.cpp:503-545` implements DEFN-R2
  §§4.1-4.2 exactly: points ordered by exact `ExactUnitParameter`; coincident crossings **rejected, not merged**;
  and **every sub-arc emitted in the canonical `cutEdge.first() → cutEdge.second()` direction**, because the points
  are sorted ascending and `ArcDraft` (`:175-178`) stores endpoints verbatim with no canonicalization. That third
  property is what makes the correction small.
- **The consumer is stale, and it is the same error one layer down.** `GlobalTopologyPlan.cpp:479-516` encodes
  *one source cut edge ⇒ one derived Cut arc* and still calls cuts *"ordinary embedded source-edge barriers"*,
  while the trace block eighteen lines below (`:534-537`) already reasons in **chords and fragments**.
  **Amendment 14 made cut arcs chord-like and A2b still treats them as whole-edge barriers** — recognisably the
  whole-edge-versus-arrangement error that `PR8-R043` and Amendment 13 corrected one layer up. `RP-01` at the
  cut/region seam.
- **Why the fix is small, and provably so.** `forward` is computed from the source edge, and every sub-arc runs in
  that same canonical direction, so `interiorDart = 2·id + (forward ? 0 : 1)` stays valid **per sub-arc**: run the
  existing body once per sub-arc instead of once per edge. The fragment-count invariant
  (`fragmentOrbits[face].size() == tracePieceCount[face] + 1`, `:670-683`) **survives**: for edge `e` shared by
  faces `A`/`B` and crossed by one trace at `p`, sub-arcs `(v₁→p)` and `(p→v₂)` lie on **opposite sides of that
  chord** and border **different fragments** of `A`, so `A` gains exactly two orbits and `tracePieceCount[A]+1 = 2`.
  `edgeOrbitEvidence`'s only consumer (`:719-728`) takes a seed only when the set is a singleton, so a multi-orbit
  set declines to seed rather than erroring — tolerant by construction, and `UncutFaceComponentOrbitSeedNotUnique`
  still fires loudly downstream.
- **A SECOND stale consumer, which EXEC did not reach, and it fails *silently*.**
  `GlobalTopologyPlan.cpp:1239-1242` inserts the **whole source edge's two endpoints** into `boundaryVertices` for
  a sub-arc whose own endpoints may be a source vertex and a crossing node — or two crossing nodes, touching no
  source vertex at all. `boundaryVertices` is a **skip list** (`:1341-1344`), so over-inserting **suppresses** the
  interior-vertex ownership check with no error and no diagnostic: a region certificate that validated less than it
  claims. **Fixing only `:479-516` would convert a loud red into a quiet weakening.** Correct rule: a sub-arc
  contributes only the source vertices that are endpoints *of that sub-arc*, resolved through `build_node_loci`'s
  existing `NodeLocus{vertex, edge}` — a node with only an `edge` locus contributes none. Do not add a second
  node→vertex lookup.
- **Already correct and needing no change:** `edge_ray_points_to_second_endpoint`
  (`EmbeddedGraphTopology.cpp:815-828`) orders a Cut ray by exact `cut_node_parameter` of its **own** endpoints, so
  CB7's AG2 generalization is sub-arc-correct; and `cutEdges` as a source-edge barrier set
  (`GlobalTopologyPlan.cpp:702, 708, 1152-1155`) is edge-keyed by intent.
- **Cause of the omission — the reviewer's, owned.** DEFN-R2 §4 itemized the Amendment-14 work as five
  producer-side items and **did not list A2b's cut-arc binding**, although AG1's own sentence said "a partial
  conversion is the defect this checkpoint is correcting". CB7/CB8 implemented §§4.1-4.5 correctly and completely;
  the gap was in the itemization. Second consecutive turn where an enumeration inside a measure was read as
  exhaustive when it was illustrative — see `LESSONS.md` **59** and now **61**.
- **Owning correction:** **AI1** (produce and publish the consumer audit by search, do **not** copy the review's
  table), **AI2** (iterate all sub-arcs; state the canonical-direction dependency in the comment; publish the
  fragment-count and `edgeOrbitEvidence` cardinalities as evidence), **AI3** (the silent `boundaryVertices` site;
  expect it to *tighten* a loose check, so a new legitimate red there is a finding, not a regression), **AI5**
  (test-helper hygiene), **AI7** (if the audit finds a site needing a representation change rather than a per-arc
  loop, **stop and return to definition** — Amendment 14 is frozen and must not be worked around).
- **CB9 Code + Build disposition — IMPLEMENTED / COMPILE-GREEN / RUNTIME UNADJUDICATED.** Semantic/test source `57444781af7bdc460e38cc68930a9a8c8199eeea` independently audited every Cut/cut-edge consumer and found exactly the two R9-REV stale sites; no representation-level widening was required. AI2 now iterates all Cut sub-arcs and publishes fragment/orbit evidence; AI3 uses one shared `NodeLocus` authority so `boundaryVertices` contains only actual sub-arc source-vertex endpoints; AI4/AI5 are complete. Compile-only run `33325344311` is green, immutable package **67** is artifact `9736088354` / `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`, manifest 28/28 PASS, GMP/GMPXX, `runtimeExecution=false`. This does **not** close the candidate or change stable totals; R10 must satisfy the frozen runtime closure condition.
- **Closure condition:** ordinals **363, 364 and 365 all green** in a run reaching 365.

## M3-CP4c2-TB-X2-R9-ORCH-01 — R9 pre-authority harness failures — **CLOSED / ORCHESTRATION / NON-STABLE**

- Schema run `33314981376` failed at startup because the caller's static reusable-workflow permission ceiling omitted `contents: write`; zero jobs and zero Directional runtime.
- Execution run `33315131472` stopped before Directional runtime when redirect-sensitive artifact retrieval returned HTTP 401.
- Execution run `33319546759` stopped in immutable preflight because Python ZIP extraction dropped packaged executable mode bits; zero Directional runtime.
- The corrected caller was schema-valid on `33319885323`; authoritative run `33319911575` is the sole semantic R9 authority. **+0 stable accounting.**

## M3-CP4c2-TB-X2-R8-CAND-02 — zero-node / zero-arc closed-surface cut-graph behavior is unresolved — **ACTIVE / PRODUCT-QUESTION / GATING AT 370 / NON-STABLE**

- **`M3-CP4c-3-TB6` measurement — ACTIVE / GENUINE PRODUCT RED.** Repaired ordinal 370 now clears the atlas precondition and reaches the intended closed-surface empty-network assertion. Actual `SurfaceCutGraphErrorCode` is `CellularityNotEstablished` (4), expected `EmptyNetworkOnClosedSurface` (6), and `sourceFace` is absent. This is no longer an invalid witness classification. Root cause/owner must be established at TB6-REV before any correction. Report-only evidence has zero gate credit; **+0/+0**.

- **Observed from retained R8 evidence (AH1, no new runtime):** result artifact `9725240893`, ordinal 359 process `R8-CHECKPOINT-41e8933d9b0e719a`, contains **no `ADD_FAILURE` lines** and terminates only at `FieldAlignedCurveNetworkTests.cpp:2381`, `ASSERT_TRUE(baselineCutGraph)`. Therefore the local source-authority, atlas, and network failure branches were not taken; `SurfaceCutGraph::make(...)` itself returned failure. The retained stdout does **not** print the cut-graph error code or `originatingTopologyError`, so neither value is inferred or fabricated here.
- **Input state:** R8-REV's static derivation remains authoritative: the closed torus atlas was built with no hard-feature edges, `rails_from_atlas(...)` was empty, and the zero-singularity torus therefore supplied a zero-node / zero-arc network to A2a′.
- **Product question:** on a closed surface with an empty network, A2a′ should either (a) establish cellularity by selecting source-edge cuts from scratch, or (b) reject with a typed error that explicitly names the empty-network condition. Current retained evidence proves only failure, not which contract is correct.
- **CB8 disposition (AH7):** **do not fix or widen scope.** AH2 removes this input state from gated ordinals 359/361 by reconstructing their local atlas/network from the production feature authority. No selector identity depends on zero-arc behavior after that correction. Bring this candidate to the next definition or independent-review turn.
- **Stable-count rationale:** the behavior was exposed by an unaccepted, newly gated witness and no accepted-green behavior was lost. **+0 events / +0 recurrences**; totals remain **44 / 14 / 30**, debt **5**, M3 packages **66**.
- **TB4 AP6 diagnostic disposition.** Ordinal 370 executes report-only but fails earlier at `ASSERT_TRUE(atlasBuild)` for the synthetic zero-field torus. It therefore does **not** prove or disprove the intended `EmptyNetworkOnClosedSurface` A2a′ error contract. New `M3-CP4c3-TB4-DIAG-CAND-01` owns the failed witness precondition; this product question remains active. +0/+0.
- **`M3-CP4c-3-TB1-REV` disposition — UNCHANGED, and unblocked.** The product question was already **decided** at
  `M3-CP4c-3-DEFN` in favour of (b), a typed rejection with an **appended** — never renumbered — error code, since
  cutting from scratch would make A2a′ the producer of the whole embedded graph and that is A2a's single-writer
  authority. TB1 measured nothing that bears on it. Carried as phase-2 implementation work under **AL6** with its
  AK5 corrective and AK7 gate append (`EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError`) as written; it shares
  no locus with either measured cause, so it neither blocks nor is blocked.

- **`M3-CP4c-3-CB2` disposition — IDENTITY GATED, PRODUCT CORRECTIVE NOT CLAIMED.** Ordinal **370** `EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` and the appended error vocabulary compile at `005512f20ed56edc793f4d6505f3d2b4c2999c71`, but CB2 provides no runtime proof that the producer emits that error on the frozen closed-surface condition. Candidate remains active/non-stable.

## M3-CP4c2-TB-X2-R8-CAND-01 — ordinal 359 still reconstructs torus rails outside production authority — **CLOSED AT R9-REV / WITNESS-CONSTRUCTION / AUTHORITY-SURFACE MISMATCH / NON-STABLE**

- **R9-REV disposition — CLOSED.** The frozen condition was *ordinals 359 and 361 both green in a run reaching at
  least 361*; R9 satisfies it exactly. **AH2 was the right correction**: rebuilding both identities on one
  production feature authority — authoritative rails, `hard_feature_edge_keys_from_rails`, and the permuted
  component/sheet labels — made the closed-torus witness constructible, which confirms the vacuous-rail-set
  diagnosis by the fix working. AH4's closed-witness non-empty-rail precondition now guards the class.
- **Two further items close with it:** measure **`AD3` is RESOLVED** — ordinal 359 reached and passed its
  enumeration-invariance comparison for the first time, so the raw-`face.orbit` rationale at
  `SurfaceCutGraph.cpp:293-297` is proved by test rather than by comment; and **`PR8-R044`'s single-witness
  residual is discharged**, since ordinals 360 (bounded two-ring) and 361 (closed genus-1 torus) both pass.
- **Accounting:** closure is a status change, not a count change. Totals remain **44 / 14 / 30**, debt **5**,
  M3 packages **66**.

- **Observed:** authoritative R8 run/job `33288495471 / 99195869180` re-proves accepted 355/355 and passes ordinals 356-358, then ordinal 359 `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` selects once and fails at `FieldAlignedCurveNetworkTests.cpp:2381`, `ASSERT_TRUE(baselineCutGraph)`, before any invariance comparison. Frozen hard stop leaves 360-365 unexecuted.
- **Mechanism:** the test now consumes committed `torus.rawfield`, but still constructs rails with test-local `rails_from_atlas(...)`. The passing production torus path (ordinal 356) consumes pipeline-published `authoritativeRails` and reports `networkV=48`, `networkE=48`, `cutEdgeCount=28`, `torusRegionCount=4`. CB7 AF3 therefore migrated field authority but not the rail-authority surface. Ordinal 361 contains the same residual local construction and was correctly not run.
- **Disposition:** continuation/recurrence of R7-CAND-01; independent R8 review owns the bounded correction and must preserve the frozen hard-stop evidence. This is not product enumeration-invariance evidence because the comparison was never reached.
- **Stable-count rationale:** ordinal 359 is newly gated and had never been accepted; inherited 355 remains green. **+0 events / +0 recurrences**. Totals remain **44 / 14 / 30**, debt **5**, M3 packages **66**.
- **CB8 code/build disposition:** semantic/test source `05f9ef299ee54f8c9d50318fc9a37e5a5503740d` corrects both 359 and 361 to consume the production feature authority; immutable package `9726295440` is BUILD GREEN / runtime-free. This record remains **ACTIVE** until a valid R9 run reaches ordinal 361 with both 359 and 361 green.
- **R9 EXEC runtime condition:** authoritative valid run `33319911575` reaches ordinal 361 and passes both 359 and 361. The frozen runtime closure condition is therefore satisfied. Per the R9 plan, independent R9-REV owns the formal closure/adjudication; stable totals remain unchanged.
- **R8-REV adjudication — CONFIRMED as a witness defect, and the mechanism is fourfold, not single.** Historical review authority is consolidated in `M3_CP4c_Consolidated_Record.md` §3.6.
  - `make_source_authority(mesh)` (`tests/FieldAlignedCurveNetworkTests.cpp:181-191`) supplies **no** authoritative
    rails, **no** hard-feature edges, and all-zero `sourceFaceComponents` / `sourceFaceSheets`. Production
    (`src/pipeline/RemeshPipeline.cpp:6377-6394`) runs
    `featureMap → build_authoritative_surface_cell_rails → hard_feature_edge_keys_from_rails → SourceTopologyRegions
    + FieldTransportAtlas`. **The test inverts an acyclic dependency:** production derives hard features *from*
    rails; the test tries to derive rails *from* an atlas it built without them.
  - `rails_from_atlas` (`:229-252`) keeps only `SourceBoundary` and `HardFeature` non-traversable edges. On a
    **closed** torus with `hardFeatureEdges = {}` there are neither, and uniform component/sheet labels prevent any
    `NonTraversable` edge. **The rail set is therefore empty by construction**, the network has zero mandatory
    edges, and the torus has zero singularities — an empty network.
  - **R8's own pass/fail split confirms it.** The discriminator is closed-versus-bounded, not torus: ordinal 358
    (`make_square_mesh`, 4 boundary edges) **passes** with the identical construction; ordinal 359 (closed torus)
    fails; ordinal 361 (closed torus) shares it and is predicted to fail identically. Ordinals 356/357/362 consume
    `cp4c_torus_fixture()` production products and pass.
  - **`rails_from_atlas` is not itself the defect.** It is correct when the atlas was built with the same feature
    set — which is exactly what CB7's own `build_cp4c_trace_crossed_cut_fixture` (`:1426-1491`) does, and what
    `observe_cp4c_witness` (`:4391-4403`) does with all four production inputs.
- **Cause of the incomplete migration — an under-specified measure, owned by the reviewer.** R7-REV's **AF3** said
  "build its baseline from the production torus authority — *the same `torus.rawfield`-derived field*". CB7
  implemented exactly that, correctly, including permuting raw-field rows alongside mesh rows. The parenthetical
  narrowed a four-product authority to one product. Recorded as `LESSONS.md` **59**.
- **Evidence gap that must be closed before code is written.** The lambda's `ADD_FAILURE()` calls are non-fatal and
  it then returns a **default-constructed** `SurfaceCutGraphError`, so atlas / network / cut-graph failures all
  arrive at the same fatal `ASSERT_TRUE` on line 2381 and the reported locus does not identify the cause. Printing
  `cutGraph.error().code` there without removing the sentinel would emit a **fabricated** `InvalidSourceBinding`.
  **AH1** requires the ordinal-359 stdout to be read out of retained artifact `9725240893` — no new runtime.
- **Owning correction:** **AH1** (read the retained evidence first), **AH2** (rebuild ordinals 359 and 361 on one
  production feature authority, threading rails + hard features + component labels + sheet labels), **AH4** (a
  closed-witness non-empty-rail runtime precondition on ordinals 358-361 and the AG5 fixture), **AH5** (remove the
  sentinel and name the failing stage). Scope is **exactly two identities**; no product source change is authorized.
- **Closure condition:** ordinals 359 and 361 both green in a run reaching at least ordinal 361.
- **Supersedes `M3-CP4c2-TB-X2-R7-CAND-01`**, which should be marked superseded rather than carried in parallel.

## M3-CP4c2-TB-X2-R8-ORCH-01 — stale expected payload blob SHA stops first caller before runtime — **CLOSED / ORCHESTRATION / NON-STABLE**

- Run `33288435250` failed in the exact payload-binding step because the caller expected the pre-write local blob SHA rather than the committed `m3-cp4c2-r8-exec.sh` blob. The execution step was skipped and no result directory existed; therefore no Directional runtime occurred.
- The caller was corrected to the committed blob SHA, schema validation passed, and authoritative semantic run `33288495471` is the only R8 runtime attempt. **+0 stable accounting**.

## M3-CP4c2-TB-X2-R7-CAND-03 — D2 localization harness compares the actual embedded graph against the withdrawn proxy using stale line-number labels — **RESOLVED IN R8-EXEC / TEST-AUTHORITY / AUTHORITY_DOMAIN_CONFLATION / RP-01 / NON-STABLE**

- **Observed:** R7-5 published `localizationConsistent=false` for the prescribed sphere. Independent review
  (`Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md` §7) establishes that this boolean is false **by
  construction** and carries no information about the sphere.
- **Three independent defects, verified at source (working tree byte-identical to packaged source `755485865a`):**
  1. `cp4c_producer_rederivation` (`tests/FieldAlignedCurveNetworkTests.cpp:6139`) builds components from
     `cp4c_source_edge_barrier_accounting(network).barriers` — the **source-edge-barrier proxy complex withdrawn as
     cellularity authority by DEFN-R1 Amendment 13** — while the real producer certifies the actual embedded graph.
     Two different complexes localize differently by construction.
  2. Its name asserts an authority it does not have: it is not a re-derivation of the producer; it models a
     **pre-CB4 producer that no longer exists**.
  3. Its site labels `419-initial-nondisc-no-cuts` / `437-final-nondisc` / `474-global-certificate`
     (`:6173, :6190, :6225`) encode line numbers in a `src/geometry/SurfaceCutGraph.cpp` that **is 344 lines long**.
     They are frozen provenance from a pre-CB4 revision and survived a whole-file rewrite silently.
- **Mechanism of the observed value:** the producer's typed error carried a `sourceFace`, so D2 took the
  `419-or-437-source-face-locus` branch (`:6621-6626`); the proxy re-derivation ran to completion and reported
  `474-global-certificate`; the strings differ; the boolean is false.
- **Owning correction:** measure **AF2** — rename the helper and state the withdrawn-proxy status in a comment,
  replace the three line-number labels, and either delete `localizationConsistent` or redefine it to compare the
  producer's printed `GlobalTopologyPlanErrorCode`/`sourceFace` (AF0) against a re-derivation over the **actual**
  embedded graph.
- **Stable-count rationale:** test/diagnostic authority only; CP4c-2 is unaccepted and no accepted-green behaviour is
  lost. **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, M3 packages **64**.

## M3-CP4c2-TB-X2-R7-CAND-04 — no `SurfaceCutGraph` identity is in any selector, and candidate 358 binds an out-of-scope witness — **RESOLVED IN DEFN-R2 / GATE-AUTHORING / NON-STABLE**

- **Observed:** `grep -c '^SurfaceCutGraph\.'` returns **0** against the accepted 355 selector, candidate 357, and
  candidate 358. A2a′'s four direct identities — `AlreadyCellularNetworkPublishesEmptyCertifiedCutSet`,
  `IsInvariantToSourceFaceAndEdgeEnumeration`, `SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness`,
  `SemanticDigestIgnoresGaugeRelabelingForTorusWitness` — are gated by nothing.
- **Consequence:** both proposed gates would accept a new pipeline stage while requiring none of that stage's own
  witnesses: its empty-cut certificate, its enumeration invariance, and its semantic/provenance separation. It is
  also why `IsInvariantToSourceFaceAndEdgeEnumeration` has never executed despite a non-viable witness
  (`M3-CP4c2-TB-X2-R7-CAND-01`), and why measure **AD3**'s orbit-ordinal rationale has no live falsifier.
- **The prescribed sphere is in neither candidate gate.** 357 adds two torus-only `GlobalTopologyPlan` identities;
  358 adds one more binding torus **and mechanical feature**. The checkpoint's actual open question therefore blocks
  nothing at gate level — the eight-turn `CAND-04` drought is structural, not accidental.
- **Blocking observation on 358, not yet runtime-established:** its added identity
  `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` (`:6826-6833`) calls
  `cp4c_mechanical_fixture()`, and `build_cp4c_production_fixture` **throws** when the pipeline did not retain
  atlas/network/cut-graph/plan (`:4523-4537`). `ORIENTATION.md` §4 records the mechanical witness as having no atlas
  (A1 `IncompleteCycleBasis`), explicitly out of CP4c-2 scope. If that durable statement holds, **358 is a
  guaranteed red**.
- **Owning correction:** **AF5** (frozen definitions must state, per identity, which A2a′ tests are gating and why
  any excluded one is excluded — "it was never added" is not a rationale) and **AF7** (358's added identity must be
  probed non-gating before 358 may ever be selected). No selector byte changes in CB6.
- **Stable-count rationale:** gate-authoring finding on an unaccepted checkpoint. **+0 events / +0 recurrences.**
  Totals remain **44 / 14 / 30**, debt **5**, M3 packages **64**.
- **DEFN-R2 resolution — CLOSED.** Gate membership was decided per identity in
  `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` §7, and selector
  `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` was created as the CP4c-2 required-green gate:
  whole-file SHA-256 `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`, computed from the created
  bytes and validated as 64 lowercase hex per AE4.
  - All **four** `SurfaceCutGraph.*` identities are **GATING**, each with a written rationale: idempotence and the
    complex label; the only falsifier of live measure **AD3**; the semantic/provenance split checked at the A2a′
    boundary rather than two stages downstream (measure AD5's purpose); and the same split on a closed genus-1
    witness, since `PR8-R044` is runtime-proved on a disc only.
  - **Two of the four enter the gate red**, pending AF3/AF4. That is deliberate: a required-green selector states
    what must hold for the checkpoint to close, not what happens to pass today.
  - **357 superseded** (incomplete, not wrong; both its identities are retained in 361). **358 withdrawn** — its
    sole addition binds `cp4c_mechanical_fixture()`, and `build_cp4c_production_fixture` throws when no atlas is
    retained. Both files are **retained** as historical authority and must not be deleted.
  - **Prefix comparability preserved and verified:** `head -355` and `head -357` of the 361 file reproduce
    `e9d88f11…5afeaa` and `b896d0db…64dc70` exactly, so `first_red_ordinal` stays comparable across the whole CP4c
    arc. Recorded as `LESSONS.md` **64x**; **64y** records the out-of-scope-witness rule.
  - **Criterion C3 is not withdrawn with 358.** It is split: `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness`
    is created and gated; the mechanical half moves to CP4c-3 / C2. Owned by **AG7**, together with the three new
    Amendment-14 identities, producing gate **365**.
  - `selected_gate` remains **NONE** and `gate_execution_authorized` remains **false**: freezing a gate's bytes is
    not selecting it.

## M3-CP4c2-TB-X2-R7-CAND-01 — torus semantic/provenance diagnostic fails at baseline-atlas precondition — **SUPERSEDED BY `M3-CP4c2-TB-X2-R8-CAND-01` / WITNESS-CONSTRUCTION DEFECT / NON-STABLE**

> **Superseded at R8-REV.** CB7's AF3 removed this record's specific cause — the synthetic zero-transport field —
> and the identity now uses the committed `torus.rawfield`. The residual is a *different and wider* authority
> mismatch (rails, hard-feature edges, component labels, sheet labels), the identity is now **gating** at ordinal
> 359, and the successor record `M3-CP4c2-TB-X2-R8-CAND-01` owns it. Do not track both in parallel. The historical
> analysis below remains accurate for the pre-CB7 source and is retained as provenance.

- **Observed:** R7 authoritative run/job `33276039911 / 99162853852` executes
  `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness` exactly once in a fresh process. It exits
  `1` at `FieldAlignedCurveNetworkTests.cpp:2220`: `baselineAtlas` is `false`; expected `true`. No semantic or
  provenance digest comparison is reached for the torus witness. Combined-output SHA-256 is
  `bafa9ffb2c1e26143e6f391ae10ab10a929e8b16564bd9b6515d7706d68bdc15`.
- **Control:** the paired two-ring diagnostic passes in the same immutable run and publishes semantic equality
  `13559155349784658228 == 13559155349784658228` with provenance inequality
  `3398751569552983810 != 4134247641157939318`. The accepted R7-1 gate separately passes 355/355.
- **Root-cause bound from EXEC:** the failure is localized only to the torus diagnostic's baseline-atlas construction
  precondition. Because the comparison body is not reached, this evidence does **not** establish a failure of the
  CB5 semantic/provenance split, nor does it identify why baseline atlas construction returned false.
- **Disposition boundary:** non-gating diagnostic only; it grants no accepted-count debit. Independent
  `M3-CP4c-2-TB-X2-R7-REV` must adjudicate witness validity/root cause and any owning corrective scope. EXEC
  authorizes no implementation/test change.
- **Evidence:** result/log artifacts `9721564203 / 9721564377`; raw evidence SHA-256
  `933190d3591aa7633fd3ebb6c1a119c1ad7d0b04cc2ca4254a8c325d3c7f1200`.
- **Stable-count rationale:** CP4c-2 is unaccepted and this identity is explicitly non-gating; no accepted-green
  behavior is lost. **+0 stable events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, M3 packages **64**.
- **R7-REV adjudication — CONFIRMED as a defect in the diagnostic's witness construction, not in the CB5
  semantic/provenance split.** `tests/FieldAlignedCurveNetworkTests.cpp:2220` is `ASSERT_TRUE(baselineAtlas)`, where
  the atlas was built from `make_zero_transport_field(mesh)` (`:159`) — identity matching, zero effort, zero singular
  cycles, constant `UnitX`/`UnitY` frames. **That is not the torus witness the project reasons about.** Every torus
  statement in `ORIENTATION.md` §4/§10 derives from `cp4c_torus_fixture()`, which runs `remesh_from_raw_cross_field`
  on the committed `torus.rawfield` (`:4489-4520`). `milestone-g/torus.obj` is loaded in exactly two places in the
  whole test file (`:2119`, `:2213`) and both feed it the synthetic zero-transport field, so this witness has no
  production counterpart and no prior green.
- **Failure mechanism — bounded, deliberately not promoted.** `FieldTransportAtlas::make` lifts each cycle by
  `(cycles·effort + 4·cycleCurvature)/2π` and rejects a non-integral result with `NonIntegralCycleLift`
  (`src/authority/FieldTransportAtlas.cpp:1655-1660`). With zero effort the lift is `2·K_v/π` per interior vertex —
  integral on a flat mesh (which is why `make_square_mesh` at `:2093` works) and generically non-integral on a curved
  closed surface. `IncompleteCycleBasis` (`:1597/:1613`, `2·genus` handle generators) is the other live candidate.
  **Neither is promoted as established**; AF3 requires the code to be printed.
- **The assertion discards the answer.** `FieldTransportAtlas::make` returns a
  `std::variant<FieldTransportAtlas, FieldAtlasBuildError>` carrying a typed code plus edge/face/vertex/region/branch
  loci, and `field_atlas_build_error_code_name()` is already exported. `ASSERT_TRUE` printed `Actual: false`. A whole
  turn was spent not knowing a value the process held.
- **Paired identity is in the same trap and has never run.** `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration`
  (`:2116`) constructs its torus atlas identically inside a lambda that uses non-fatal `EXPECT_TRUE(atlas)` and then
  calls `atlas.value()` — on the same input that is `std::get` on the error alternative, i.e. an unhandled
  `std::bad_variant_access` rather than a diagnosable assertion. It is in no selector, so this has never been
  observed, and its assertions (non-empty cut set, `proves_cellularity()`, digest equality under face/edge
  reordering) have never executed. See `M3-CP4c2-TB-X2-R7-CAND-04`.
- **Consequence for `PR8-R044` closure:** the CB5 semantic/provenance split is runtime-proved on the **two-ring**
  only. That is exactly what R044's frozen closure condition required, so closure stands; the second witness is this
  separate record's business.
- **Owning correction:** **AF3** (rebuild the diagnostic on the production torus authority and print the typed atlas
  error) and **AF4** (run the fourth A2a′ identity non-gating and settle measure AD3 with it).

## M3-CP4c2-TB-X2-R7-ORCH-01 — R7 plan transcribes four frozen selector hashes incorrectly — **CLOSED IN R7-REV** / ORCHESTRATION / DOCUMENT-AUTHORITY / NON-STABLE

- **Observed:** R7-EXEC immutable preflight on package `9719216316` passes outer/package/source/GMP/mode checks and
  internal manifest **28/28**, then exact hash comparison disagrees for selector authorities 346, 353, 357, and
  358. Per the frozen R7-0 rule, execution stops before the first Directional process.
- **Plan values:** 346 `20d3b0b1b942af39b1e105e06dc122cfc7d5c90102735de292aac4924ac3e46a`; 353 `51ff96d7dd69051042213673ca1876a0fcf2a192aa69eae26fd31b0b958ac6a5`; 357 `b896d0db98bdf3ea421d98df870867077114622e24558204490d2f17464dc70`; 358 `6eda3aadbeaa4b991726a6f6e2cc080d45ca5a8ab8a18a37e3fce986b64fbe62`.
- **Immutable values:** 346 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; 353 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`; 357 `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`; 358 `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`.
  316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` and 355 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` match the plan.
- **Localization:** the immutable values match `ORIENTATION.md`, R6-EXEC's successful preflight, and direct hashes
  of the unchanged CB5 package selector bytes. The wrong four full strings were introduced in the CB5 closeout
  patch's AD0 report text and copied into the new R7 plan; selector files themselves were not changed.
- **Impact:** orchestration authority only. No accepted identity, non-gating diagnostic, 357/358 candidate,
  cumulative gate, benchmark, compile, repair, or mutation ran. R043/R044 receive no new runtime evidence.
- **Owner:** independent `M3-CP4c-2-TB-X2-R7-REV` must adjudicate exact selector authority and the minimal
  documentation-only correction before any R7 retry. EXEC does not silently substitute the immutable values.
- **Stable-count rationale:** no product/test semantic regression and no accepted runtime result; **+0 stable events /
  +0 recurrences**. Totals remain **44 / 14 / 30**, debt **5**, M3 packages **64**.
- **R7-REV adjudication — ORCHESTRATION / DOCUMENT-AUTHORITY / NON-STABLE, fully localized.** All six hashes were recomputed from the committed selector bytes in review and match the immutable package, R6-EXEC, and `ORIENTATION.md` exactly: 316 `601ce2b6…0193c`, 346 `20d3b0b1…3e46a`, 353 `51ff96d7…ac6a5`, 355 `e9d88f11…5afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…b64fbe62`. **The selector bytes never changed and the accepted authority chain is intact.**
- **Proof of fabrication rather than staleness:** the R7 plan's expected value for selector 357 is **63 characters**. SHA-256 is 64 hex characters; a stale or wrong-file digest would still be 64. A value of the wrong length can only have been assembled by hand, and no check in the authoring path validated its length.
- **Mechanism:** every failing constant shares the **first eight** hex characters and the **trailing** characters with the truth and differs only in the middle — the signature of an abbreviated digest of the form `PREFIX…SUFFIX` expanded back to full length by inventing the interior. The two that passed, 316 and 355, are the two whose full values were readily to hand.
- **Reviewer contribution to the cause:** `M3-CP4c-2-TB-X2-R6-REV` measure AD0 wrote all six hashes in abbreviated `PREFIX…SUFFIX` form inside a measures table, which reads like a value table. Full values existed elsewhere, so the abbreviation did not force the error, but it supplied the template. **Rule adopted: a cryptographic digest is written in full or replaced by a file reference plus "recompute" — never abbreviated where a value is expected.**
- **R7's behaviour was correct and must be preserved:** it hard-stopped before the first Directional process, **refused to substitute observed values for planned constants** — which would have silently rewritten executable authority mid-run — and ran a post-preflight integrity check even though runtime never started.
- **Deeper design point:** a transcribed constant cannot distinguish the two causes of a mismatch, selector drift versus mistranscription, and R7 spent a whole turn establishing it was the latter. Future preflight tables must record the **source file and derivation** (`head -N <file>` or whole file) and derive the constant by computing it at authoring time.
- **Owning correction:** documentation-only `M3-CP4c-2-DOC-R1` under **AE0–AE9** — AE0 recompute independently, AE1 correct exactly the four constants without touching any selector file, AE2 sweep `.agents/Directional/**` for the same defect and report counts even if zero, AE3 record the abbreviation rule, AE4 mandatory 64-lowercase-hex format validation at authoring, AE5 plans name their derivation. Review authorization and DOC-R1 result are consolidated in `M3_CP4c_Consolidated_Record.md` §6.6 and `Architecture_M3_CP4c2_DOC_R1_Documentation_Correction_Report.md`.
- **DOC-R1 correction:** all six selector hashes were recomputed from committed bytes; the four current-authority
  mistranscriptions were corrected in the CB5 AD0 audit and R7 plan, the plan now names source/derivation, and all
  selector files remained byte-identical. No runtime/package/test/product semantics changed. R7-0 retry is the proof
  boundary, so the orchestration candidate is corrected but not yet closed.
- **Closure condition:** R7-0 preflight passes on all six rows against unchanged immutable package `9719216316`.
- **R7 retry evidence:** authoritative run `33276039911` passes immutable R7-0 against all six corrected derivations,
  then starts Directional runtime. The prose-only correction is therefore proven at its frozen preflight boundary.
  Formal final disposition remains an R7-REV bookkeeping decision; no selector byte changed.
- **Stable-count rationale:** documentation/orchestration only; no product semantic event, no selector or package change, no accepted identity affected. **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, M3 packages **64**.

## PR8-R044 / M3-CP4c2-R002 — cut-graph semantic digest reimports gauge-dependent atlas provenance — **RESOLVED / CLOSED IN R7-REV** / STABLE / PRODUCT / REPRESENTATION_DEPENDENT_IDENTITY / RP-05

- **Observed:** R6-EXEC artifact-only accepted-prefix re-proof on immutable CB4 package `9714226920` passes accepted ordinals 1-309 in fresh processes, including the former ordinal-305 failure, then ordinal 310 `GlobalTopologyPlan.RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling` selects exactly once and exits `1`. `baselinePlan.semantic_digest()` is `12176020141753559903`; gauge-relabeled `relabeledPlan.semantic_digest()` is `14339407889897379635`.
- **Accepted predecessor:** ordinal 310 is part of CP4c-1's accepted **355/355** authority at source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`. CB4 inserted/reworked `SurfaceCutGraph` authority while retaining the accepted identity, so this is loss of accepted-green behavior rather than a first-acceptance diagnostic.
- **Root cause — statically localized in EXEC:** the identity first proves equal `FieldAlignedCurveNetwork::semantic_digest()` and unequal atlas digests under equivalent gauge relabeling. `GlobalTopologyPlan::candidate_semantic_digest` deliberately uses gauge-invariant `network.semantic_digest()` but also consumes `candidate.cutGraphDigest`. `SurfaceCutGraph::candidate_hash` includes `candidate.atlasDigest`, populated from `network.atlas_digest()`. Gauge-dependent atlas provenance therefore flows through the cut-graph digest into plan semantic identity, violating the established semantic/provenance split.
- **Recurrence:** existing `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`. This is the same domain mistake previously stabilized at `PR8-R040 / M3-CP2b-R001`: a representation/provenance hash is consumed as semantic identity after gauge-equivalent relabeling.
- **Runtime boundary:** frozen R6 hard-stop applied at ordinal 310. Ordinals 311-355, the independent actual-complex oracle, retained barrier diagnostic, D2, 357/358, and cumulative gate were not run. Unconditional package/source postflight passed with all mutation/build flags false.
- **Owner:** independent `M3-CP4c-2-TB-X2-R6-REV`. EXEC records the recurrence and exact failure mechanism but authorizes no corrective implementation.
- **Evidence:** R6 EXEC summary is consolidated in `M3_CP4c_Consolidated_Record.md` §6.4; raw archive `Directional__M3-CP4c-2-TB-X2-R6-EXEC__raw-evidence.tar.gz`, SHA-256 `340f2e569d372809a299d5b7c065966756797fb2a6e47db959d82ea62213e4f5`; ordinal-310 stdout/stderr/combined SHA-256 `7e2780fe5d9153997035ce4f33eb412219f1877a50b84e2fd30c2e2cf12bf7b0 / 5023344a86ee85bb23e86456f2a0c19af6c61e422f8ec226305d9376acef849e / ba5f869f04aa48cc811cb737a5873eba1befe1f7c28af85f614ab6b70c22e70d`.
- **Accounting:** one new stable event and one recurrence in existing category/pattern `REPRESENTATION_DEPENDENT_IDENTITY / RP-05`: totals advance **43 / 14 / 29 -> 44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**; M3 packages remain **63**.
- **R6-REV adjudication — CONFIRMED and independently re-localized.** Verified at source: `GlobalTopologyPlan.cpp:1511-1519` consumes `candidate.cutGraphDigest` **and** `network.semantic_digest()`; `SurfaceCutGraph.cpp:263-265` `candidate_hash` consumes `candidate.atlasDigest`; `canonical_candidate` stores `network.atlas_digest()` there. **A2b states the rule in a comment, obeys it on the line the comment guards, and is defeated two lines earlier** — `cutGraphDigest` carries the atlas hash in through the back door.
- **The error is a domain conflation, not a hashing bug.** `candidate_hash` is a **provenance** hash and is correct as such: `make_from_candidate` needs `atlasDigest` to reject a candidate built against a foreign or tampered atlas. The defect is a second consumer reading a provenance hash as **semantic** identity.
- **The corrective template already exists in this repository.** `M3-CP3a-DG-CAND-02` fixed exactly this for `FieldAlignedCurveNetwork`: *semantic identity consumes the gauge-invariant digest while the full atlas hash is retained separately for binding/provenance, preserving foreign/tampered-atlas rejection.* `SurfaceCutGraph` must be given the same split — **add a `semantic_digest()`, leave `candidate_hash` unchanged.** **Removing `atlasDigest` from `candidate_hash` is prohibited**: it would trade a semantic defect for a weakened tamper rejection one level down.
- **Additional finding the EXEC did not reach.** Removing `atlasDigest` is necessary but **not sufficient**. `SurfaceCutGraph.cpp:258` records each certificate face as `{orbit, …}` where `orbit` is the **raw loop index** into `faceWalk.orbits` — an enumeration artifact, not a semantic face identity — and `candidate_hash` consumes it. Ordinal 310 asserts invariance to enumeration order **and** relabeling, so this is a latent instance of the same pattern that may simply not fire today. **Measure AD3** requires it settled deliberately: prove orbit enumeration canonical and record the proof, or replace the index with a content-derived key. "It passes now" is not an answer.
- **Owning correction:** `M3-CP4c-2-CB5` measures **AD1** (add the semantic digest), **AD2** (convert the consumer and extend the comment to both sites), **AD3** (orbit index), **AD4** (term-by-term certificate partition), **AD5** (a non-gating diagnostic that checks the split at the cut-graph boundary rather than two stages downstream). The superseded R6 review record is consolidated in `M3_CP4c_Consolidated_Record.md` §§6.4-6.5.
- **Closure condition:** ordinal 310 green in a run that also reaches the full **355/355** accepted prefix.
- **R7 retry EXEC evidence:** the same CB5 package now reaches the complete accepted **355/355**. Ordinal 310 selects exactly once and passes in that full run, mechanically satisfying this record's frozen runtime closure condition. **EXEC does not close/reclassify the stable record or alter totals; R7-REV owns that adjudication.**
- **R7-REV disposition — CLOSED.** The frozen condition is met exactly: ordinal 310 green inside a complete
  **355/355** run on CB5 package `9719216316`. The fix was independently re-verified at source and is the
  `M3-CP3a-DG-CAND-02` template applied correctly: `SurfaceCutGraph.cpp:268` `candidate_semantic_hash` consumes
  `sourceDigest` + `networkSemanticDigest` + cut edges + certificate terms and **not** `atlasDigest`;
  `:263` `candidate_hash` **still** consumes `atlasDigest`, preserving foreign/tampered-atlas rejection in
  `make_from_candidate` exactly as AD1's prohibition required; `:335` `make` constructs with both;
  `GlobalTopologyPlan.cpp:1630` converted the consumer to `cutGraph.semantic_digest()`; and `:1511-1519`'s comment
  now names both sites. R7-2's two-ring diagnostic confirms it at runtime — semantic `13559155349784658228 ==
  13559155349784658228`, provenance `3398751569552983810 != 4134247641157939318`.
- **What closure does not claim.** Ordinal 310 (`tests/FieldAlignedCurveNetworkTests.cpp:2509`) and R7-2's passing
  counterpart both use the **two-ring**; the torus counterpart failed at its own witness precondition
  (`M3-CP4c2-TB-X2-R7-CAND-01`). The split is therefore runtime-proved on one witness — which is precisely what the
  frozen condition asked for. Moving a closure condition after the evidence arrives is the failure mode this project
  has already corrected twice, and it is not repeated here.
- **Live residual — measure AD3.** `candidate_semantic_hash` consumes `face.orbit`, the raw index into
  `faceWalk.orbits`, under a written rationale (`SurfaceCutGraph.cpp:293-297`) that the ordinal is content-derived
  because `NetworkArcId` comes from a total sort over semantic arc descriptors. That rationale is plausible and
  **unproved**: its only dedicated falsifier is
  `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration`, which tests the source face/edge **enumeration** axis
  that gauge relabeling does not touch — and that identity is in no selector and has never run. AD3 therefore rests
  on a comment. Owned by **AF4**.
- **Accounting:** closure is a status change, not a count change. Totals remain **44 events / 14 categories /
  30 recurrences**; debt **5**; M3 packages **64**.

## PR8-R043 / M3-CP4c2-R001 — CP4c-2 whole-source-face proxy rejects accepted embedded-graph witness — **RESOLVED / CLOSED IN R7-REV** / STABLE / PRODUCT / AUTHORITY_DOMAIN_CONFLATION / RP-01

- **Observed:** R5-EXEC run/job `33232106030 / 99046593525` passes accepted ordinals 1-304 in fresh processes, then ordinal 305 `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` selects exactly once and exits `1`. Its first semantic failure is `SurfaceCutGraph::make(...)=CellularityNotEstablished`; the later `std::get: wrong index for variant` is secondary helper fallout.
- **Accepted predecessor:** the same identity/witness is part of CP4c-1's accepted **355/355** authority at source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`. CP4c-2 inserted `SurfaceCutGraph` ahead of `GlobalTopologyPlan`; the witness itself is not new or reconstructed.
- **Root cause — independently reviewed:** `SurfaceCutGraph` builds complement components as whole source faces separated by a `sourceEdgeBarrier` set containing mandatory edges plus every trace segment's incoming/outgoing **carrier source edge**. CP4ab had already proved this representation cannot express faces of the actual embedded graph when trace arcs cross face interiors and replaced whole-face ownership with face fragments/orbits (`PR8-R042`, LESSONS 22d/22e). CP4c-2 therefore reintroduced a previously rejected authority domain.
- **Exact two-ring proof:** retained CP4ab evidence on the same accepted witness gives three interior embedded-graph faces; current network authority has `V=9`, `E=11`, so `9-11+3=1=source χ`. R4's independent proxy diagnostic instead measures self-consistent `sourceEdgeBarrier` terms `V=10`, `E=11`, `F=2`, also `χ=1`. Current product mixes network `V/E=9/11` with proxy `F=2`, yielding `0 != 1` and rejecting at the final global certificate (`SurfaceCutGraph.cpp:473-474`).
- **Why this is not a one-line Euler fix:** the proxy's per-component disc proofs also operate on whole source faces. Replacing only global `V/E` with proxy counts would make arithmetic green while certifying the wrong semantic object, violating the normative contract that `SurfaceCutGraph` certifies the actual `FieldAlignedCurveNetwork ∪ cutEdges`.
- **Causal boundary:** this defect predates CB3 AA1. `SurfaceCutGraph.cpp` is unchanged between diagnostic source `5ad711e5d4ced95f38e103b993139a6307ba2cee` and R5 source `76d757aab0ce18df09ce2823302d2dc224965187`; AA1 only moved pipeline snapshot publication. **Do not revert AA1.**
- **Owner:** exact successor `M3-CP4c-2-DEFN-R1`, measures AB0-AB9 in `M3_CP4c_Consolidated_Record.md`. Freeze one actual embedded-graph fragment/arrangement authority before a later CB.
- **Evidence:** R5 result/log artifacts `9708817991 / 9708818239`, SHA-256 `bda50fcdaf2b89ccce9a9b1ed5ecb7f4cd656a4168583635e69251f03c2556e8 / b9e150dec9d47cec140f982650a65b5d8668d3c5d5b8f4074bae7e3d6f8c9688`; review record `M3_CP4c_Consolidated_Record.md`.
- **R6-EXEC progress:** on CB4 package `9714226920`, accepted ordinal 305 now selects once and passes. The accepted re-proof later stops at ordinal 310 under separate `PR8-R044 / M3-CP4c2-R002`; therefore EXEC does not close this independently reviewed event or claim full 355 restoration. `PR8-R043` remains ACTIVE pending R6-REV.
- **Accounting:** one new stable event and one recurrence in existing category/pattern `AUTHORITY_DOMAIN_CONFLATION / RP-01`: totals advance **42 / 14 / 28 -> 43 events / 14 categories / 29 recurrences**. Produced-witness debt remains **5**; M3 packages remain **62**.
- **R6-REV disposition — RESOLVED AT LOCUS / CLOSURE PENDING FULL-PREFIX RE-PROOF.** Accepted ordinal 305 `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` **passes** on CB4 package `9714226920`. The mixed-complex certificate that produced `9 - 11 + 2 = 0 != 1` is gone, replaced by DEFN-R1 Amendment 13's actual embedded-graph complex, and CB4 delivered `src/geometry/EmbeddedGraphTopology.{h,cpp}` as the single shared authority required by AC1.
- **Not closed yet, deliberately.** R6 executed 309 of 355 accepted identities before stopping at ordinal 310. **`PR8-R043` closes only at a full 355/355 with ordinal 305 green** — recording closure on a 309-ordinal prefix would be the partial-evidence promotion this project has already corrected twice. Measure **AD8** carries the condition.
- **R7 retry EXEC evidence:** the same CB5 package now reaches the complete accepted **355/355**. Ordinal 305 selects exactly once and passes in that full run, mechanically satisfying this record's frozen runtime closure condition. **EXEC does not close/reclassify the stable record or alter totals; R7-REV owns that adjudication.**
- **R7-REV disposition — CLOSED.** Measure AD8's frozen condition — ordinal 305 green in a run reaching the full
  355/355 — is met exactly, with no prefix promotion. The defect is also gone at the locus rather than masked: the
  mixed-complex certificate that computed `9 − 11 + 2 = 0 ≠ 1` on the two-ring no longer exists, DEFN-R1
  Amendment 13's actual-embedded-graph complex replaced it, and `proves_cellularity()`
  (`src/geometry/SurfaceCutGraph.cpp:331-333`) now **requires**
  `complex == SurfaceCutGraphComplexKind::ActualEmbeddedGraph`, so the withdrawn whole-source-face proxy cannot
  re-enter a certificate by construction. `src/geometry/EmbeddedGraphTopology.{h,cpp}` is the single shared
  authority AC1 required.
- **Accounting:** closure is a status change, not a count change. Totals remain **44 / 14 / 30**; debt **5**;
  M3 packages **64**.

## M3-CP4c2-TB-X2-R5-ORCH-01 — runtime helper leaks errexit and suppresses postflight — RESOLVED / R6 HARNESS CONFIRMED / ORCHESTRATION / NON-STABLE

- **Observed:** R5's `run_identity` re-enabled `set -e` before returning the red ordinal-305 process status. The shell exited before the outer AA8 stop handler, semantic summary, and recursive package/source postflight could run. Raw result/log artifacts were still uploaded.
- **Impact:** R5 is admissible for the semantic regression because immutable preflight plus the exact one-process raw log/row are complete, but it cannot prove post-runtime mutation inventories or any downstream AA2/D1/D2 result.
- **Resolution evidence:** R6-EXEC reaches a semantic red at accepted ordinal 310, preserves the stop, then still executes unconditional immutable postflight. Package/source byte-and-mode inventories compare equal, package/source hashes reverify, and all build/repair/mutation flags remain false. The R5 suppression mechanism is therefore runtime-falsified by the corrected harness.
- **Stable-count rationale:** orchestration-only; **+0 stable events / +0 recurrences**. Current totals after the separate R6 semantic recurrence are **44 / 14 / 30**, debt **5**, M3 packages **63**.

## M3-CP4c2-TB-X2-R4-CAND-01 — final D1 assertion duplicates an already-published failure record — ACTIVE / TEST-AUTHORITY / PUBLICATION HYGIENE / NON-STABLE

- **Observed:** authoritative R4 EXEC run/job `33228460953 / 99036688477` executes D1 once and reaches all three
  witnesses, but preserved stdout has four `m3Cp4c2Y1` lines: torus once, prescribed sphere twice, two-ring once.
  The two prescribed-sphere lines are byte-identical.
- **Static localization:** `tests/FieldAlignedCurveNetworkTests.cpp:6043-6049` prints the failed witness report
  immediately and also appends the same report to `failures`; line 6071 then streams `failures.str()` through
  `ASSERT_TRUE(allWitnessesValid)`. GoogleTest therefore republishes the already-emitted Y1 text in the assertion
  failure message.
- **Impact:** R4's frozen exactly-one-record-per-witness contract is red, so D2 is not authorized and EXEC cannot
  use the records to close candidates or select Y5. Witness isolation itself is observable, but its disposition
  belongs to R4-REV.
- **Root-cause status:** high-confidence diagnostic/test publication-contract defect; no product semantic claim.
  No corrective implementation is authorized from EXEC.
- **Stable-count rationale:** CP4c-2 is runtime-unaccepted and this is a new non-gating diagnostic authority.
  **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**, debt **5**, M3 packages **61**.
- **Review adjudication — downgraded from evidence conflict to publication hygiene, conditionally.** `ASSERT_TRUE(allWitnessesValid) << failures.str()` at `tests/FieldAlignedCurveNetworkTests.cpp:6071` re-emits the sphere's already-published record, giving four `m3Cp4c2Y1` lines. The EXEC stop was **procedurally correct** — the rule was frozen and was applied. But **a byte-identical restatement is not an evidence conflict**: there is exactly one *distinct* record per witness and no witness's state is indeterminate.
- **Contract amended, not waived:** the requirement is **exactly one *distinct* record per witness**. On that basis the preserved R4 evidence is **admissible** and the §6 closures follow from it.
- **Conditional, and the condition is binding.** Measure **AA2** requires byte-identity confirmed from `d1-records.txt` in result artifact `9707662462`. **If the two sphere lines differ in any byte, the stop stands, the admissibility adjudication is void, and the R4 evidence cannot be used.**
- **Owning correction:** `M3-CP4c-2-CB3-DIAG` measure **AA5** — emit each record once; the assertion message references failing witnesses by name and status only; publish the per-witness record count so the contract is machine-checkable.
- **CB3 compile state:** corrective source `76d757aab0ce18df09ce2823302d2dc224965187` implements AA5 and compiles GREEN in GMP package `9708324052`. Candidate remains **ACTIVE / RUNTIME PENDING** until R5 proves exactly one Y1 record per witness plus publication counts 1/1/1/3.
- **R5-REV AA2 disposition:** independently extracted R4 `d1-records.txt`; the two prescribed-sphere lines are each **468 bytes**, each SHA-256 `84f9ca015ab63093086981cbd29256526159329c64537dfb52fba9e89d9fd078`, and are byte-identical. AA2's admissibility condition is therefore **CONFIRMED**. R5 stopped at accepted ordinal 305 before D1, so AA5's exactly-once runtime publication remains **ACTIVE / RUNTIME PENDING** rather than closed.

## M3-CP4c2-TB-X2-R4-CAND-02 — pipeline discards product snapshots on any pre-A2b failure path — **LOCALIZED** / PRODUCT OBSERVABILITY DEFECT / NON-STABLE

- **Observed:** the same R4 D1 run publishes the prescribed-sphere typed failure
  `constructionSucceeded=false`, `pipelineAtlasAvailable=false`, `pipelineNetworkAvailable=false`,
  `pipelineCutGraphAvailable=false`, `pipelinePlanAvailable=false`,
  `terminalFailureStage=surface-cut-graph/CellularityNotEstablished`,
  `error=pipeline-source-topology-snapshot-unavailable`.
- **What EXEC establishes:** sphere construction is unavailable through the current product-snapshot diagnostic
  authority; torus and two-ring still publish, and D2 is not permitted because all three constructions did not
  succeed.
- **What EXEC does not establish:** whether retention policy, terminal-stage publication, or another diagnostic
  precondition owns the missing sphere snapshot; whether X2 CAND-04's product failure changes; or any Y5 branch.
  R4-REV owns that adjudication.
- **Stable-count rationale:** CP4c-2 is unaccepted and this is diagnostic-precondition evidence, not a loss of an
  accepted-green identity. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**, debt **5**, M3
  packages **61**.
- **LOCALIZED by `M3-CP4c-2-TB-X2-R4-REV` as a PRODUCT defect, not a test defect.** The sphere's record is self-contradictory on its face: `terminalFailureStage=surface-cut-graph/CellularityNotEstablished` with `pipelineAtlasAvailable=false` and `pipelineNetworkAvailable=false`. A failure **at** `surface-cut-graph` is reachable only through `SurfaceCutGraph::make(…, *sourceTopologyRegionsProduct, *fieldTransportAtlasProduct, *fieldAlignedNetworkProduct)` at `src/pipeline/RemeshPipeline.cpp:6602-6605` — **dereferencing all three proves all three were built.**
- **Mechanism:** `RemeshPipeline.cpp` lines **6576-6612** are a chain of `return fail_surface_cells(...)` early exits, and lines **6626-6634** assign all five snapshots **in one block after every one of them**. Snapshots are therefore published only when every stage through A2b succeeds. The torus reaches 6626 and retains everything; the sphere fails at 6607 and retains nothing — although its products exist and are alive in local variables at that moment.
- **Consequence for prior guidance:** measure **Z11** (consume `productSnapshots`) was written on the assumption that snapshots survive a failure. They do not. Z11 is unimplementable as written for any witness whose pipeline fails at or before A2b — which is exactly the prescribed sphere, the decision witness for Branch A. The reviewer owns that error; see the review record §4.
- **Classification:** observability only. The failure code and stage string are already correct and no accept/reject decision changes.
- **Owning correction:** `M3-CP4c-2-CB3-DIAG` measure **AA1** — publish each snapshot immediately after its product is successfully constructed, changing no `fail_surface_cells` call, failure code, stage string, control flow, or build ordering. This is **the only `src/` change authorized** in the checkpoint, and **AA8** prices it: the successor TB must re-prove accepted prefixes 316/346/353/355 before crediting any CP4c-2-local identity.
- **CB3 compile state:** corrective source `76d757aab0ce18df09ce2823302d2dc224965187` implements AA1 and compiles GREEN in GMP package `9708324052`. The defect remains **LOCALIZED / RUNTIME PENDING**; R5 must first re-prove 316/346/353/355 and then show that a sphere failure at `surface-cut-graph` retains the already-built source-topology/atlas/network products.
- **R5-REV causal adjudication:** R5's accepted ordinal-305 regression is **not caused by AA1**. `SurfaceCutGraph.cpp` is unchanged from pre-AA1 diagnostic source `5ad711e5d4ced95f38e103b993139a6307ba2cee` through R5 source, while ordinal 305 fails in direct `SurfaceCutGraph::make` before pipeline snapshot publication matters. AA1 remains the owning observability correction and must not be reverted; its runtime proof remains pending because R5 never reached the sphere.
- **Stable-count rationale:** observability defect; no accepted-green identity regressed and CP4c-2 has no accepted runtime authority. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c2-TB-X2-R4-CAND-03 — torus completes A2a', A2b and a GlobalTopologyPlan, then fails downstream at tracing — ACTIVE / OUT-OF-SCOPE FOR CP4c-2 / NON-STABLE

- **Observed:** R4's torus record reports `pipelineCutGraphAvailable=true` and `pipelinePlanAvailable=true`, with `terminalFailureCode=NotProductionReady` and `terminalFailureStage=tracing`.
- **Why the plan availability is trustworthy:** `products.globalTopologyPlan` is assigned at exactly one site, `src/pipeline/RemeshPipeline.cpp:6634`, reachable only after `GlobalTopologyPlan::make(...)` returns success at 6614-6624. The two other snapshot-writing sites (12554, 12635) set only `sourceTopologyRegions` and `hasAuthoritativeRails` and cannot produce a plan snapshot. **The torus's plan was genuinely constructed.**
- **Significance — this discharges CP4c-2's defining premise.** The checkpoint exists because the torus network is provably not a cut graph and A2b failed with `UncutFaceComponentOrbitSeedNotUnique`. D1 independently confirms the first half — network-only cellularity is **false** on the torus, matching the frozen theorem — while the pipeline confirms the second: with `SurfaceCutGraph` supplying cuts, A2b completes. **The DEFN design is measured working end to end on its own witness.**
- **The residual `tracing` failure is downstream of A2b and outside CP4c-2's scope.** It must not be pulled into this checkpoint and must not be read as evidence against the cut graph. **AA7** requires it published and classified, explicitly **not** fixed.
- **Stable-count rationale:** no accepted identity regressed; the finding is a success plus an out-of-scope successor failure. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**, debt **5**.
- **CP4c-3 TB1 re-observation:** frozen report-only identity
  `GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable` remains RED in authoritative run `33340448381`,
  while publishing `surfaceCutGraph=true`, `globalTopologyPlan=true`, `cutEdgeCount=28`, actual graph
  `V/E/F=72/76/4`, and four χ=1 regions before `failedStage=tracing`. This is the same downstream out-of-scope
  residual, not a CP4c-3 regression. Current stable totals remain **44 / 14 / 30**, debt **5**, packages **68**.

## M3-CP4c2-TB-X2-R4-ORCH-01 — first R4 runtime control script addressed package metadata at the wrong archive root — **RESOLVED ORCHESTRATION / NON-STABLE**

- **Observed:** run/job `33228330756 / 99036316061` verified package digest/manifest, then stopped before D1 at
  `pkg/source-commit.txt` because package metadata is under `pkg/metadata/`.
- **Correction:** only the execution control path was corrected, schema-validated, and retried with the exact same
  immutable package and runtime semantics. Authoritative run `33228460953` then reached D1. No Directional binary
  ran in the failed attempt.
- **Stable-count rationale:** orchestration only; **+0 events / +0 recurrences**.

## M3-CP4c2-TB-X2-R4-PROC-01 — READ_MODE was selected after an initial handoff fetch — **RESOLVED PROCESS / NON-STABLE**

- **Observed:** the handoff was fetched before the mandatory full tool-use-policy read and explicit turn-local
  READ_MODE choice.
- **Correction:** the miss was recorded immediately, `READ_MODE=snapshot` was selected, and source snapshot
  `9707441880` was acquired/verified before continuing repository source/document analysis.
- **Stable-count rationale:** process-ordering miss only; no semantic/build/runtime evidence changed.
  **+0 events / +0 recurrences**.

## M3-CP4c2-TB-X2-R3-CAND-01 — corrected D1 torus fixture fails before network publication with `field-transport-atlas-unavailable` — **RESOLVED** / TEST-AUTHORITY / DIAGNOSTIC FIXTURE RECONSTRUCTION DIVERGENCE / NON-STABLE

- **Observed:** authoritative artifact-only R3 EXEC run/job `33222551366 / 99019499929` passed immutable preflight,
  selected `GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable` exactly once, and then
  exited `1` at `tests/FieldAlignedCurveNetworkTests.cpp:5946` before publishing any `m3Cp4c2Y1` record.
  `fixture.network.has_value()` was false with exact diagnostic `witness=torus;error=field-transport-atlas-unavailable`.
- **Stop-rule effect:** Z6's torus 48/48 publication was never reached; Z3 all-witness self-consistency was not
  evaluated; D2 was correctly skipped. R2 CAND-01/CAND-02 therefore remain active and X2 CAND-04 remains
  active/unlocalized. EXEC makes no Y5 branch inference.
- **Root-cause analysis status:** runtime localizes the failure to corrected torus diagnostic fixture construction
  before `FieldAlignedCurveNetwork` publication. The EXEC evidence does not distinguish an invalid diagnostic
  field/fixture precondition from a defect in the explicit product-authoritative rail/atlas construction path.
  Adjudicating that distinction is the bounded responsibility of `M3-CP4c-2-TB-X2-R3-REV`; unchanged runtime
  retry is prohibited.
- **Immutability:** result/log artifacts `9705692837 / 9705693025`, SHA-256
  `ba989d0ddd3bd244f03c8242060ded9f9c58b33679893ab0ddf1cc5fb8d015f5 /
  ab653c13ec7b0eec30f2736a17bbf44406afa7c828cb1fddbadea795aa6701a6`; package/source byte-and-mode postflight
  matches preflight exactly.
- **Stable-count rationale:** CP4c-2 is unaccepted and this failure is in a new non-gating diagnostic authority;
  no accepted-green product behavior regressed. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**,
  debt **5**, M3 packages **60**.

# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed historical event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; the current immutable turn report owns current artifact/runtime detail.

Last updated: **2026-08-29 UTC** after `M3-CP4c-2-TB-X2-R4-EXEC`. Authoritative artifact-only run/job
`33228460953 / 99036688477` consumed immutable GMP package `9707091209` from semantic/test source
`5ad711e5d4ced95f38e103b993139a6307ba2cee`. D1 produced torus 48/48 success, a prescribed-sphere typed
snapshot-construction failure, two-ring success, and one duplicate sphere Y1 line from the final assertion;
therefore D1 stops `STOP_EVIDENCE_CONFLICT` and D2 is skipped. Candidate dispositions remain review-owned by
`M3-CP4c-2-TB-X2-R4-REV`; no stable event/recurrence is added or resolved by EXEC interpretation. Stable
accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**, M3 packages
**61**.

- **Review adjudication — LOCALIZED, test-side with high confidence.** `M3-CP4c-2-TB-X2-R3-REV` identified two demonstrable divergences from production in `cp4c_build_rail_authority` under `PipelineAuthoritative`. **Divergence A — the cross field:** the fixture computes `finalize_surface_cell_raw_cross_field(mesh, raw)`, while production and the working observer `observe_cp4c_witness` use the pipeline's published `products.crossField`. **Divergence B — the hard-feature edge set:** the fixture recomputes it from a locally built feature map (`options.featureAlign ? options.featureMap : options.surfaceCells.featureMap` → `hard_feature_edge_keys_from_rails`), while the working observer passes `tracingOptions.hardFeatureEdges` from the pipeline. The torus is the one witness whose rails originate in the feature map, so it is the one witness where that set is non-empty and the divergence can bite. **Divergences C and D remain plausible and unmeasured:** production builds over `meshWhole` and via `build_source_topology_regions` with `sourceFaceComponents`/`sourceFaceSheets` populated, whereas the fixture uses the raw loaded OBJ and bare `make_source_authority`.
- **Why test-side:** production reaches A2a on the torus — the frozen `48 HardFeature rails / 48 structural nodes / 0 traces / 0 events` came from CB2's T1 — so production's atlas construction for the torus succeeds. A reconstruction that fails where the original succeeds is a reconstruction defect. **Measure Z12 requires this to be confirmed by publication, not assumed**; if the pipeline's own torus atlas is also unavailable, the classification flips to a product finding and the frozen theorem is re-adjudicated.
- **Structural cause — a third idiom for one job.** The test file now has three witness constructions: `cp4c_production_fixture` consumes `products.*` directly and is faithful; `observe_cp4c_witness` rebuilds the atlas but from `products.crossField` and `tracingOptions.hardFeatureEdges` and is proven to work on the torus; `cp4c_network_only_fixture` rebuilds field, feature map, rails and atlas locally and fails. Each new idiom has introduced a defect — its first version used `rails_from_atlas` (R2 CAND-01), its second diverges on field and feature map. **This is the fourth incident in one authority-divergence family**, after the CP4c-0b DG rail split, CB2's T1/T3 labelling, and R2 CAND-01. Z4 fixed which authority is *named*; **Z11** fixes how it is *obtained*.
- **Secondary defect recorded — the typed error was discarded.** `cp4c_build_rail_authority` flattens `atlas.error().code` to the bare string `field-transport-atlas-unavailable`, so the evidence names the stage but not the reason. Purpose-built helpers `append_atlas_error(...)` and `append_cp4c_atlas_failure_diagnosis(...)` already exist in the same file and were not reused. Same class as `CellularityNotEstablished`: a typed failure flattened exactly where the type was the evidence. **Z14.**
- **Owning correction:** `M3-CP4c-2-CB2-DIAG-R2` measures **Z11** (consume published products for loaded production witnesses, via a *relaxed* variant that tolerates absent cut graph and plan — the strict `cp4c_production_fixture` throws without them and the torus has neither), **Z12**, **Z14**, and **Z15** (no fourth idiom). Record: `M3_CP4c_Consolidated_Record.md` §6.
- **CB2-DIAG-R2 compile status:** source `5ad711e5d4ced95f38e103b993139a6307ba2cee` removes the hand-reconstruction helper for loaded witnesses, consumes pipeline product snapshots, publishes snapshot availability/terminal stage, and preserves typed construction errors. Package `9707091209` is green/runtime-free. Static inspection also shows atlas/network snapshots are currently retained only after cut-graph/global-plan success, so runtime may hit the Z12 snapshot-availability stop even though production constructed those objects earlier. **Runtime closure is still pending R4.**
- **Closure condition:** the torus reaches a published network through Z11 and reproduces `V=48, E=48, χ=0`, non-cellular, from authority rather than from an encoded constant.
- **Stable-count rationale:** diagnostic precondition failure in a non-gating identity; nothing about the product, the frozen theorem, or any accepted identity is established or lost. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**, debt **5**.

- **R4 EXEC evidence pending review:** run `33228460953` reaches a successful torus `pipelineProducts` network and publishes `barrierV=48`, `barrierE=48`, `sourceChi=0`, non-cellular, `oracleSelfConsistent=true`. EXEC does not close this candidate; R4-REV owns the disposition.
- **RESOLVED by `M3-CP4c-2-TB-X2-R4-REV`.** Measure Z11 removed the hand reconstruction for loaded production witnesses entirely: `build_cp4c_pipeline_products_fixture` consumes `productSnapshots`, and the torus reached a published network on the first run under it. The strict `build_cp4c_production_fixture` was layered on top **without being weakened**, as Z11 required.

## M3-CP4c2-TB-X2-R3-CAND-02 — one witness's failure suppressed every other witness's publication — **RESOLVED** / TEST-AUTHORITY / DIAGNOSTIC GATING / NON-STABLE

- **Observed:** the R3 D1 identity loops over `{torus, prescribed-sphere, two-ring}` and calls `ASSERT_TRUE(fixture.network.has_value())` **inside the loop** (`tests/FieldAlignedCurveNetworkTests.cpp:5946`). GoogleTest's `ASSERT_*` returns from the test body, and the torus is element 0 — so the identity ended after 14 ms with **zero** `m3Cp4c2Y1` publications.
- **Cost:** the prescribed sphere and the two-ring were never constructed, measured, or published, despite nothing being known to be wrong with either. **The prescribed sphere is the decision witness for Branch A** and therefore for the 357/358 selector; its corrected barrier-complex numbers were available and were discarded.
- **Third appearance of one anti-pattern in this checkpoint:** the original X2 gated every publication behind `SurfaceCutGraph::make` succeeding; `CellularityNotEstablished` collapsed three mechanisms behind one code with no locus; and now one witness's precondition failure suppresses all other witnesses' evidence.
- **Owning correction:** `M3-CP4c-2-CB2-DIAG-R2` measure **Z13** — iterate every witness, publish exactly one record per witness including a typed failure record for any that cannot be constructed, accumulate status, and assert **once after the loop**. Measure **Z17** makes per-witness publication unconditional in the successor retry, so evidence is produced even when the torus control fails.
- **CB2-DIAG-R2 compile status:** the in-loop `ASSERT_*` is removed; each witness now emits one success/failure record, failures accumulate, and one assertion occurs after the loop. Package `9707091209` is green/runtime-free. **Candidate remains ACTIVE until R4 proves publication isolation at runtime.**
- **Closure condition:** a run in which a per-witness failure occurs and every other witness is still published.
- **Stable-count rationale:** test-authority defect in a non-gating diagnostic; no accepted identity regressed. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**, debt **5**.

- **R4 EXEC evidence pending review:** the sphere fails construction but torus and two-ring are still published, so the former suppression behavior is no longer observed. However the final assertion duplicates the sphere Y1 record and violates the strict exactly-once publication contract. R4-REV owns closure/disposition.
- **RESOLVED by `M3-CP4c-2-TB-X2-R4-REV`.** In R4 the prescribed sphere failed construction and **the torus and two-ring were still published**, each with a complete record. Z13's witness isolation works. The separate duplicate-publication defect is tracked as `R4-CAND-01` and is a different problem.

## M3-CP4c2-TB-X2-R2-CAND-02 — D1 oracle measures a self-consistent proxy rather than the actual embedded graph — ACTIVE / TEST-AUTHORITY / WRONG SEMANTIC COMPLEX / NON-STABLE

- **Observed:** in TB-X2-R2 run/job `33215632118 / 98998526420`, D1's prescribed-sphere record publishes **all 18** complement components as discs (each `χ=1`, one boundary cycle) **and** global terms `V=18`, `E=30`, `F=18` giving `18 − 30 + 18 = 6` against source `χ=2`.
- **Why this is a contradiction, not a discrepancy:** if every component of the complement of an embedded graph is an open disc, the embedding is cellular by definition and `V − E + F = χ` is an identity, requiring `E − V = F − χ = 18 − 2 = **16**`. The publication reports `E − V = **12**`. **The deficit is exactly 4.** At least one of the disc verdicts, the vertex/edge counts, or the face count is false; they cannot all hold.
- **Independent of CAND-01.** This blocker stands even if the torus rail authority is fixed, and it bears directly on Y5 Branch A, whose whole content is the proposition D1 was built to establish.
- **Leading root cause, to be confirmed not assumed:** `F` counts source-face components separated by **whole source barrier edges**, while `V` and `E` appear to count the **network's abstract graph**, whose arcs cross face interiors. Two complexes, so Euler's identity does not hold between them. Because barriers cut along whole edges, the barrier partition over-cuts relative to the traces, and over-cutting a disc yields two discs — which is why the contradiction surfaces as a surplus rather than a failed disc test.
- **The oracle inherited the error it was built to detect.** `M3_CP4c_Consolidated_Record.md` required independence from `SurfaceCutGraph`, which D1 satisfied — it never calls the producer — but not independence from the *counting convention*, which is the actual suspect. Plan §2's "state what was counted" requirement was insufficient.
- **The two-ring's passing result is uninformative**, not corroborating: under a defective convention an agreeing result is a coincidence, and the two-ring has 3 traces against the sphere's 24, exactly where the coarsening effect would be smallest.
- **Owning correction:** `M3-CP4c-2-CB2-DIAG-R1` measures **Z2** (one named complex — the source-mesh barrier complex, `E=|B|`, `V=` source vertices incident to `B`, `F=` components after removing `B`), **Z3** (a mandatory self-consistency assertion: all-discs ⟺ `V−E+F==χ`, failing closed), and **Z7** (re-derive the two-ring rather than carry it forward). Record: `M3_CP4c_Consolidated_Record.md` §6.
- **Closure condition:** the corrected oracle publishes self-consistent terms on all three witnesses under one named complex, with `oracleSelfConsistent=true`. Not closed by any product change.
- **Stable-count rationale:** test-authority defect in a non-gating diagnostic; no accepted-green identity regressed and CP4c-2 has no accepted runtime authority. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**, debt **5**.
- **CB2-DIAG-R1 compile status:** source `c552a5a4a318063cde2564c40773ec7edaf064f6` replaces the mixed-complex diagnostic with one named `sourceEdgeBarrier` complex, publishes barrier definitions/provenance, and asserts `oracleSelfConsistent` per witness. Final compile package `9704935112` is green/runtime-free. **Candidate remains ACTIVE** because its closure condition is runtime evidence that all three corrected D1 witnesses are self-consistent; Code + Build cannot supply that evidence. Stable totals unchanged.
- **CB2-DIAG-R2 carry-forward:** source `5ad711e5d4ced95f38e103b993139a6307ba2cee` preserves the same `sourceEdgeBarrier` and Z3 self-consistency authority while correcting witness construction/publication. Package `9707091209` is green/runtime-free. **Candidate remains ACTIVE** pending all-three R4 runtime publications and self-consistency.


- **R4 EXEC evidence:** torus and two-ring publish `oracleSelfConsistent=true`, but prescribed sphere does not construct (`pipeline-source-topology-snapshot-unavailable`), so the all-three closure condition is not reached. Candidate remains ACTIVE pending review.
- **R4 partial progress — remains ACTIVE, do not close early.** Under `complex=sourceEdgeBarrier` the torus (`48 − 48 + 4 = 4` vs `χ=0`) and the two-ring both published `oracleSelfConsistent=true`, and R2's exact-by-4 self-contradiction did **not** recur. But the closure condition is self-consistency on **all three** witnesses, and the prescribed sphere has still never been measured. Closes only when AA3 publishes a complete, self-consistent sphere record.
- **R5-REV superseding adjudication:** the prior closure condition is withdrawn. R5 plus retained CP4ab authority proves `sourceEdgeBarrier` is a **different complex**, not the normative representation of `FieldAlignedCurveNetwork` when traces cross source-face interiors. On the accepted two-ring the proxy is self-consistent at `10/11/2`, while the actual embedded graph is self-consistent at `9/11/3`; the product regression arises by mixing those domains. Therefore all-three proxy self-consistency cannot close this candidate. Closure now requires an independent oracle over the **actual embedded graph/face-fragment complement**, using a mechanism independent of `SurfaceCutGraph`, with term-by-term `V/E/interior-F` and component-disc comparison in that same semantic complex. The R2 review statement that carrier-edge coarsening was only a quality concern is withdrawn.

## M3-CP4c2-TB-X2-R2-CAND-01 — D1 torus control reconstructs atlas-barrier rails instead of product-authoritative rails — **RESOLVED** / TEST-AUTHORITY / STRUCTURALLY INVALID FIXTURE / NON-STABLE

- **Observed:** artifact-only R2 run/job `33215632118 / 98998526420` verified immutable package `9702321260`,
  executed D1 exactly once, and published all three Y1 records. The fixed torus control then reported
  `networkV=0`, `networkE=0`, `sourceChi=0`, `networkOnlyCellular=false` instead of the frozen/product theorem's
  `V=48`, `E=48`, `chi=0`, non-cellular. The plan required STOP; D2 was not executed.
- **Root cause:** `cp4c_network_only_fixture(...)` reconstructs D1 rails via test helper
  `rails_from_atlas(mesh, atlas)`. Production constructs an `AdaptiveFeatureMap` and then calls
  `build_authoritative_surface_cell_rails(...)`; the prior product observer explicitly consumes
  `products.authoritativeRails`. DEFN §2/X1 records the production torus as 48 `HardFeature` mandatory edges /
  48 structural nodes. D1 therefore attached the production witness name and frozen expected counts to a
  differently produced rail/network authority without proving equivalence.
- **Secondary review gap:** prescribed-sphere D1 reports all 18 complementary components as discs but combines
  `networkV=18`, `networkE=30`, `networkF=18` into `networkChi=6` against source `chi=2`. R2 does not adjudicate
  whether those V/E/F terms belong to one Euler complex because Y4 already invalidated the oracle/control. The
  next independent review must settle that count authority before a test correction.
- **Impact:** Y1 is raw/control-invalid evidence only; Y2/Y3 are unavailable; Y5 is `NONE`. No Branch A/B/C,
  product correction, or cumulative gate is authorized. Existing X2 CAND-04 remains active/unlocalized.
- **Correction ownership:** `M3-CP4c-2-TB-X2-R2-REVIEW-PLAN` must re-adjudicate X1 rail provenance and the D1
  Euler complex. Only if it confirms a diagnostic-authority defect may it authorize bounded test-only
  `M3-CP4c-2-CB2-DIAG-R1`; frozen product `CB3` remains reserved for a valid Y5 branch.
- **Recurrence/pattern:** `RP-02` / durable fixture-witness lesson — two differently produced objects are two
  witnesses until equivalence is proven; a census must name the authority it counts.
- **Stable-count rationale:** CP4c-2 is unaccepted, the failure is in new report-only diagnostic authority, and no
  accepted-green product behavior was lost. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**,
  debt **5**, M3 packages **59**.
- **Review adjudication — CONFIRMED.** `M3-CP4c-2-TB-X2-R2-REVIEW-PLAN` upheld the control stop and confirmed the frozen `48/48` torus theorem remains product-authoritative: D1 never tested it, so nothing about it is in doubt. Record: `M3_CP4c_Consolidated_Record.md` §6.
- **Why it was invisible until the torus:** on the closed prescribed sphere and on the two-ring the two rail authorities agree, which is why the sphere's 24 traces / 56 events match production exactly. The substitution is detectable only on the one witness whose rails originate in the feature map.
- **Third recurrence of one confusion.** The same `rails_from_atlas` versus pipeline `authoritativeRails` divergence was adjudicated in the CP4c-0b DG review and again in CB2's T1/T3 labelling. Measure **Z4** therefore requires a structural fix — one named rail accessor taking an explicit authority argument with **no default**, and `railAuthority=` published on every diagnostic record — rather than repairing this call site alone.
- **Owning correction:** `M3-CP4c-2-CB2-DIAG-R1` measures **Z1** and **Z4**; closure requires the torus control to reproduce `48/48` **from authority**, never from an encoded constant (**Z5**).
- **CB2-DIAG-R1 compile status:** source `c552a5a4a318063cde2564c40773ec7edaf064f6` gives torus and prescribed sphere explicit `PipelineAuthoritative` rail construction, two-ring explicit `AtlasDerived` authority, and orders D1 torus first. Final compile package `9704935112` is green/runtime-free. **Candidate remains ACTIVE** until R3 D1 actually reproduces the frozen 48/48 torus control; no compile result may close it. Stable totals unchanged.
- **CB2-DIAG-R2 compile status:** source `5ad711e5d4ced95f38e103b993139a6307ba2cee` now obtains loaded-witness rail/source/atlas/network authority from pipeline product snapshots and leaves two-ring constructed/AtlasDerived. Package `9707091209` is green/runtime-free. **Candidate remains ACTIVE** until R4 has an actual successful torus network publication that reproduces 48/48; snapshot-retention absence does not satisfy or refute that closure condition.


- **R4 EXEC evidence pending review:** the corrected product-snapshot torus publishes the frozen 48/48 control from `pipeline-authoritative` rails with `oracleSelfConsistent=true`. EXEC preserves this evidence but does not close the candidate; R4-REV owns closure.
- **RESOLVED by `M3-CP4c-2-TB-X2-R4-REV`.** R4 run/job `33228460953 / 99036688477` published the torus with `railAuthority=pipeline-authoritative`, `witnessConstruction=pipelineProducts`, and the frozen `barrierV=48`, `barrierE=48`, `sourceChi=0`, `networkOnlyCellular=false` — reproduced **from authority**, not from an encoded constant (Z5 held). Closure condition met. Record: `M3_CP4c_Consolidated_Record.md` §6.

## M3-CP4c2-TB-X2-CAND-01 — reusable observer permission ceiling caused startup failure — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** push run `33198406913` ended `startup_failure` with zero instantiated jobs and zero Directional runtime.
- **Root cause:** the caller granted only `contents: read`, while the referenced reusable observer contains a nested
  branch-file job requesting `contents: write`; GitHub validates the reusable permission ceiling statically even when
  `commit_run_file=false` skips that job.
- **Correction/evidence:** the corrected caller granted the static union required by the reusable graph. Observer and
  schema-validation jobs both passed in authoritative run `33199227974`.
- **R3 recurrence:** R3 EXEC caller run `33222474179` repeated the same startup failure after initially granting
  `contents: read`; zero jobs/zero Directional runtime instantiated. Raising the caller ceiling to `contents: write`
  produced authoritative runtime run `33222551366`. This is the same resolved orchestration pattern, not a new
  semantic candidate or stable regression.
- **Stable-count rationale:** workflow startup failed before semantic execution; **+0 events / +0 recurrences**.
  Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c2-TB-X2-CAND-02 — immutable package source materialized outside compiled fixture root — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** run/job `33198586715 / 98942044412` verified package/selector integrity and selected the frozen X2
  identity exactly once, but its sole publication was `m3Cp4c2X2;prescribed sphere:fixture-load-failed`.
- **Root cause:** the package source archive was extracted under runner temp. The precompiled producer-test binary
  embeds fixture root `/home/runner/work/Directional/Directional`, the already-documented
  `M2-CP2-TB-CAND-01` / `M3-CP2b-TB-CAND-01` orchestration class.
- **Correction/evidence:** unchanged package `9696201700` and unchanged one-identity selector were used in run/job
  `33199227974 / 98944212158`, with the exact embedded source archive materialized at the compiled fixture root.
  Pre/postflight passed with every mutation flag false and the X2 publication was produced.
- **Stable-count rationale:** runtime-environment/harness only; no product/test/fixture/selector/package semantic
  mutation and no accepted behavior loss. **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c2-TB-X2-CAND-03 — X2 cannot adjudicate its frozen 357/358 rule when cut-graph production fails — **RESOLVED / TEST-AUTHORITY MEASUREMENT-INCOMPLETE / NON-STABLE**

- **Observed:** authoritative report-only run/job `33199227974 / 98944212158` reaches a valid prescribed-sphere
  network (24 traces / 56 events) and then publishes `surface-cut-graph/CellularityNotEstablished`.
- **Review re-derivation:** `observe_cp4c_witness` calls `SurfaceCutGraph::make` before it emits
  `networkAlreadyCellular` or any `V/E/F/χ` cellularity fields. On cut-graph failure it returns immediately. The
  field named `networkAlreadyCellular` is itself only `cutGraph.cut_edges().empty()` after successful construction,
  not an independent network-only complement certificate. `GlobalTopologyPlan::make` is likewise after successful
  cut-graph construction, so this path cannot observe whether `RotationSystemInconsistent` persists or disappears
  once a certified embedding is supplied.
- **Exact-site gap:** the X2 report serializes only the shared code `CellularityNotEstablished`. Source contains
  multiple return sites for that code, including tree-cotree cut selection, final component disc recertification,
  and final global cellularity certification. Optional `sourceFace` localization is not serialized.
- **Adjudication:** record `M3_CP4c_Consolidated_Record.md`. The evidence establishes neither the
  frozen 357 predicate nor the frozen 358 predicate. `selected_gate=NONE`; full gate execution is forbidden by the
  frozen TB plan. The diagnostic is therefore measurement-incomplete for its stated decision purpose.
- **Stable-count rationale:** this is a report-only, not-yet-accepted CP4c-2 diagnostic/test-authority defect, not a
  loss of accepted-green behavior. **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c2-TB-X2-CAND-04 — prescribed sphere's A2a′ failure is a collapsed typed error, not a cellularity verdict — **ACTIVE / ONE LEVEL SHORT / RESOLVED TO `TraceEventPositionInvalid`, WHICH IS ITSELF A TWO-WAY COLLAPSE / PHASE 2 NOT AUTHORIZED / NON-STABLE**

- **Observed:** the same authoritative X2 run proves source topology, `FieldTransportAtlas`, and
  `FieldAlignedCurveNetwork` all succeed for the prescribed sphere; the network has 24 traces / 56 events. The next
  producer, `SurfaceCutGraph`, fails closed with `CellularityNotEstablished`, so no certified cut graph or
  `GlobalTopologyPlan` is produced.
- **What is established:** this is not the earlier fixture-root orchestration failure and not an A1/A2a reachability
  failure. It is real product-path evidence at the new A2a′ authority.
- **What is not established:** the raw diagnostic does not distinguish the multiple
  `CellularityNotEstablished` return paths or publish the failing component/source face/certificate condition. It
  therefore does not justify a specific implementation root cause, and it does not prove whether the sphere's old
  `RotationSystemInconsistent` was caused by non-cellularity.
- **Ownership:** `M3-CP4c-2-TB-X2-PLAN` must plan the missing measurement/localization before any corrective CB or
  gate selection. No implementation correction is authorized by this review record alone.
- **Stable-count rationale:** CP4c-2 has never been accepted at runtime and this product is new in the unaccepted
  checkpoint. The finding is material but non-stable: **+0 events / +0 recurrences**. Totals remain
  **42 / 14 / 28**, debt **5**.
- **TB4 AP6 diagnostic disposition.** Ordinal 368 now executes report-only with zero gate credit and independently reproduces `surfaceCutGraphError=CellularityNotEstablished`, `originatingTopologyError=RotationSystemInconsistent`, `originatingRotationSystemReason=TraceEventPositionInvalid`, trace 2 / event 30. This confirms the current localization but does not resolve the two-way `TraceEventPositionInvalid` collapse or authorize a sphere correction; **AL4 remains binding**. +0/+0.
- **TB5 AP6 localization.** AS6 is runtime-proved: the same trace 2 / event 30 now publishes `traceEventPositionFailure=NoCarrierMatch;traceEventPositionPass=SourceEdgeUnavailable`. The prior two-way collapse is resolved to the nonterminal no-source-edge path. This is localization only; **AL4 remains binding and no sphere semantic fix is authorized**. +0/+0.
- **CB2-DIAG-R1 status:** D2 compiles against corrected source `c552a5a4a318063cde2564c40773ec7edaf064f6` but has not executed. **Candidate remains ACTIVE / UNLOCALIZED**; R3 may run D2 only after the torus and all-three-witness self-consistency stop gates pass. No product root cause or stable recurrence is inferred from compilation.


- **R4 EXEC status:** D2 is not authorized after the D1 evidence-conflict/all-three-construction stop. Candidate remains ACTIVE / UNLOCALIZED; no product cause is inferred.
- **R7 retry EXEC evidence:** D2 finally executes exactly once and the diagnostic test passes while publishing
  `producerGlobalCountsReached=true`, `surfaceCutGraphStatus=error`, `surfaceCutGraphError=CellularityNotEstablished`,
  `errorSourceFace=25-27-28`, `publishedLocusClass=419-or-437-source-face-locus`,
  `localizedSite=474-global-certificate`, and `localizationConsistent=false`. This materially narrows the evidence
  but contains an explicit locus-consistency conflict; EXEC therefore preserves the record without promoting a
  specific product root cause. Independent R7-REV owns interpretation/disposition. Stable totals remain unchanged.

### R7-REV adjudication — the cellularity framing is withdrawn

Full derivation in `Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md` §5. Established from retained
evidence plus committed source (working tree byte-identical to packaged source `755485865a`):

- **`errorSourceFace=25-27-28` is populated, and that settles the path.** In the `SurfaceCutGraph::make` path D2
  exercises, `CellularityNotEstablished` has exactly three producers: `SurfaceCutGraph.cpp:250` (the
  `exterior.size() > totalOrbits` guard, via `cut_error`, which sets **only** `code` — `:44-48`), `:337/:339`
  (`make_from_candidate` binding fallbacks, not on this path), and `:50-67` `topology_error`, which is the **only**
  one that copies `error.sourceFace`.
- **`topology_error` is a lossy default bucket.** It maps 39 `GlobalTopologyPlanErrorCode` values into three
  `SurfaceCutGraphErrorCode` values; `InvalidSourceBinding`, `InvalidNetworkBinding` and `InvalidCutGraphBinding`
  survive as themselves and **the remaining 36 collapse to `CellularityNotEstablished`**. On this path that string is
  not a verdict about cellularity — it is `default:`.
- **It is called from exactly two sites,** `SurfaceCutGraph.cpp:240` (`build_embedded_graph_topology`) and `:243`
  (`exterior_boundary_orbits`), both defined in `src/geometry/EmbeddedGraphTopology.cpp`, which calls nothing in
  `global_topology_plan_detail`.
- **Across that file's 58 error constructions, every code that both survives the default case and carries a
  `sourceFace` is `RotationSystemInconsistent`** — all nine `sourceFace` assignments (`:364, :372, :499, :507, :514,
  :813, :827, :929, :939`) belong to it; it accounts for 44 of the 58.
- **Therefore:** the sphere's A2a′ failure is `GlobalTopologyPlanErrorCode::RotationSystemInconsistent` at one of
  nine sites in `EmbeddedGraphTopology.cpp`, locus source face `25-27-28`, relabeled `CellularityNotEstablished` by
  `topology_error`'s `default:`. The single residual — an error constructed in an unenumerated helper — is closed by
  **AF0**, which prints the code instead of inferring it.

Three consequences:

1. **The sphere never reached a cellularity decision.** Neither `topology_error` call site evaluates cellularity;
   that happens later, at `certificate.proves_cellularity()` in the cut loop (`:323`) and at the `:250` orbit guard.
   Every turn from X2 forward reasoned about whether the sphere is cellular, how many cuts it needs, and which
   complex certifies it — aimed at a mechanism the sphere never reached.
2. **A2a′ did not change the sphere's failure; it renamed it.** This record previously asked whether the sphere's old
   `RotationSystemInconsistent` was caused by non-cellularity. Inserting `SurfaceCutGraph` upstream of
   `GlobalTopologyPlan` moved the same rotation-system inconsistency one stage earlier and gave it a new name
   through the default case. This is the `ORIENTATION.md` §8 pattern *typed error flattened / one code collapsing
   several mechanisms with no locus*, and it has cost the checkpoint eight turns.
3. **The standing prediction is NOT confirmed.** "The sphere's network is already cellular pre-cut and needs zero
   cuts" remains unadjudicated. What changed is that its principal counter-evidence evaporated. It must now be
   settled on the actual-embedded-graph oracle row — which **R7-3 already published for the sphere** and which the
   EXEC report omitted; it is in retained result artifact `9721564203`. **AF1** extracts it, with no new runtime.

- **Owning correction:** **AF0** (carry and print the originating `GlobalTopologyPlanErrorCode`; do **not** re-map
  `topology_error` and do **not** add an enum value — 355 accepted identities depend on the current mapping),
  **AF1** (extract the sphere oracle row before planning any run), **AF2** (repair the D2 harness — see
  `M3-CP4c2-TB-X2-R7-CAND-03`). No product fix for the rotation-system failure is authorized until the code is
  printed; fixing a mechanism named by inference is how this checkpoint lost R2.
- **Stable-count rationale unchanged:** CP4c-2 has never been runtime-accepted; no accepted-green behaviour is lost.
  **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, M3 packages **64**.

### R9 EXEC direct-origin confirmation

- Frozen non-gating identity `GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable` executes once in authoritative run `33319911575` and remains RED while now directly publishing `surfaceCutGraphError=CellularityNotEstablished` and `originatingTopologyError=RotationSystemInconsistent`. This runtime publication confirms R7-REV's previously static provenance localization; it does not add gate credit or change stable accounting.
- **CP4c-3 TB1 AK3 measurement:** authoritative run `33340448381` executes
  `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable` report-only and publishes
  `originatingRotationSystemReason=TraceEventPositionInvalid`. Source topology, atlas and network are all available;
  the network has **24 traces / 56 events** and the failure remains at `surface-cut-graph/CellularityNotEstablished`
  carrying `originatingTopologyError=RotationSystemInconsistent`. The nine-way ambiguity is therefore closed at the
  producer-reason level, but the product candidate remains ACTIVE pending independent review/correction.
  **+0 events / +0 recurrences**; totals **44 / 14 / 30**, debt **5**, packages **68**.

### `M3-CP4c-3-TB1-REV` adjudication — the new reason is itself a collapse

Full derivation in `Architecture_M3_CP4c3_TB1_Independent_Review_Record.md` §4. AK3 delivered exactly what it was
asked and resolved nine `sourceFace`-carrying sites to one enumerated reason. **The candidate is nevertheless still
one resolution short, and phase 2 is NOT authorized for this witness.**

- **`TraceEventPositionInvalid` names two conditions.** `trace_event_position`
  (`src/geometry/EmbeddedGraphTopology.cpp:138-173`) collects segment positions whose carrier matches the event's
  `sourceEdge`, then returns `std::nullopt` from a single `if (positions.size() != 1U)`. So:
  - **`positions.empty()`** — the event's source edge is not a carrier of any segment of this trace. That is a
    network/event **binding** defect: the event does not belong to the trace it claims, or its `sourceEdge` is
    wrong. The corrective is upstream, in A2a.
  - **`positions.size() > 1`** — the source edge is a carrier at more than one position on the same trace. That is
    an **ambiguity**: the position is not determined by `sourceEdge` alone. The corrective is a stronger key.
  **The two fixes are opposite**, and no measurement currently distinguishes them.
- **A two-pass structure can manufacture the second case.** The first pass considers only segments whose
  `sourceFace == event.sourceFace`; only if that finds nothing does a fallback pass run over **all** segments
  ignoring the face. A widening fallback that runs after a precise pass found nothing can turn "no match in the
  right face" into "several matches across the trace", so an `empty` first pass may be reported as an `ambiguous`
  failure. Any measurement must therefore publish **which pass produced the result**.
- **Ambiguity is the live suspicion and is deliberately NOT promoted.** The sphere is the trace-dense witness — 24
  traces, 56 events, 10 terminal trace intersections, and six directed trace ends that once circulated forever — and
  a trace crossing the same source edge twice yields exactly `positions.size() == 2`. That is a hypothesis. Acting
  on a plausible unmeasured mechanism is precisely what cost this checkpoint eight turns at this same witness.
- **If ambiguous, the discriminator already exists and costs nothing.** CP4c-2 established that the exact crossing
  point is published by the network as `segment.entryPoint` / `edgeTransitExit` (`FieldBoundaryPoint`).
- **Pattern:** `LESSONS.md` **57** for the third time in this project, one level deeper each turn, on the same
  failure — 36 codes → `RotationSystemInconsistent` (AF0); nine sites → `TraceEventPositionInvalid` (AK3); two
  conditions → still open. Recorded as `LESSONS.md` **64**: *when instrumenting a collapsed error, check whether
  the reason you are adding is itself a collapse before declaring the layer done.*
- **Owning corrections:** **AL3** — add an enumerated sub-reason distinguishing `NoCarrierMatch` from
  `AmbiguousCarrierMatch` and publish, for the sphere, the trace id, event id, event `sourceEdge` and `sourceFace`,
  **every** candidate position with its segment index and carrier in the ambiguous case, and which pass produced
  the result. Additive only: no change to `trace_event_position`'s return contract, no re-mapping, no enum
  renumbering. **AL4** — do not design this witness's fix until AL3 reports; a fix whose report cannot name the
  measured sub-reason is not authorized.
- **Locus finding:** this candidate and `M3-CP4c3-DEFN-CAND-01` **do not share a locus** — A2a′
  `EmbeddedGraphTopology` versus A1 `FieldTransportAtlas`, no shared code and no shared datum — so neither blocks
  the other and they may be worked independently.
- **Stable-count rationale unchanged:** CP4c-3 has never been runtime-accepted and the accepted 365 prefix is green
  in the same run. **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, M3 packages **68**.

### CB6 AF1 adjudication — pre-cut cellularity prediction refuted; definition gap is now live

- **Retained evidence, no new runtime:** CB6 AF1 extracted the prescribed-sphere
  `m3Cp4c2ActualGraphOracle` row from immutable R7 result artifact `9721564203`: `complex=actualEmbeddedGraph`,
  `surfaceCutGraphCallsInsideOracle=0`, `V=18`, `E=30`, `F=18`, `c=1`, `chi=6`, `sourceChi=2`,
  `excludedBoundaryOrbits=0`; producer state remains `error / CellularityNotEstablished`.
- **Finding:** the standing prediction “the sphere's network is already cellular pre-cut” is **REFUTED** by the
  independent actual-graph oracle. This does not reverse R7-REV's error-path finding: the live producer still fails
  earlier through the lossy upstream-error bucket, and AF0 still has not printed the originating typed code.
- **Frozen-definition effect:** DEFN-R1 §8.2 leaves trace-crossed non-disc cut completeness unproved; §8.3 states
  that a non-cellular prescribed sphere makes that case live and requires CP4c-2 to return to definition. With 24
  retained sphere traces and the AF1 non-cellularity result, `M3-CP4c-2-CB6` stopped before AF0/AF2/AF3/AF4 source
  changes, compilation, packaging, or runtime. Exact successor: `M3-CP4c-2-DEFN-R2`.
- **Scope caution:** AF1 does **not** establish that no admissible cut exists. It establishes that the frozen
  completeness proof does not cover the live trace-crossed non-cellular case; DEFN-R2 must define a complete
  strategy or a sound typed stop before implementation resumes.
- **Stable-count rationale unchanged:** CP4c-2 remains runtime-unaccepted and no accepted-green behavior was lost.
  **+0 events / +0 recurrences.** Totals remain **44 / 14 / 30**, debt **5**, M3 packages **64**.

- **`M3-CP4c-3-CB2` disposition — AM7 INSTRUMENTATION COMPILE GREEN / NO FIX AUTHORIZED.** Ordinal **368** now carries `NoCarrierMatch` versus `AmbiguousCarrierMatch`, precise/widened-pass provenance and candidate loci. It is compiled at `005512f20ed56edc793f4d6505f3d2b4c2999c71` but unexecuted; candidate remains **ONE LEVEL SHORT** until TB reports.

## M3-CP4c2-TB-X2-REV-CAND-01 — placeholder connector mutation during PR-closeout setup — **RESOLVED ORCHESTRATION / NON-STABLE**

- **Observed occurrence 1:** after semantic review documentation and temporary-state cleanup were already complete,
  a mistaken connector mutation intended to update PR metadata instead invoked the repository file-update action on
  path `dummy`, creating a one-byte root file in commit `b08a56b64fe7012c7b88928fc08550a5e43fe011`. It was
  deleted immediately in commit `36c5ddb62d89824b9ec500bd6f33694dc8bd06a0`.
- **Observed occurrence 2:** during the same final PR-closeout phase, the same wrong mutating action was invoked again
  with placeholder path `DO_NOT_USE`, creating an empty root file in commit
  `bdfa4a00a6c090f8e59672e4e0f5541327393e6e`; it was identified and deleted immediately in commit
  `34b0f5d17e027b17ef5d0541f84046645ed354dd`.
- **Containment/correction:** both placeholders existed only as control-plane debris and were removed before final
  turn closeout. Neither entered semantic source, build/package authority, runtime evidence, selectors, fixtures, or
  accepted product state.
- **Recurrence note:** both occurrences repeat the control-plane anti-pattern already recorded by
  `M3-CP4ab-CB-R1-CAND-03`: mutating connector actions must never be used with placeholder/probe arguments. This
  second same-turn occurrence strengthens the procedural lesson but does not change product-regression accounting.
- **Stable-count rationale:** control-plane only and removed before turn closeout; **+0 events / +0 recurrences**.
  Totals remain **42 / 14 / 28**, debt **5**, M3 packages **58**.


## M3-CP4c1-TB-R4-CAND-01 — C5 rejects current terminal-event witness union at two preconditions — **RESOLVED** / TEST-SIDE OVER-SPECIFICATION / NON-STABLE

- **Observed:** authoritative artifact-only TB-R4 run/job `33141046678 / 98751794167` is **354/355 PASS**. Accepted predecessor authority is green **353/353** in the same immutable run, C4 is PASS, and C5 `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced` alone is RED. Exactly one test was selected for every required identity; zero escaping C++ exceptions; immutable pre/postflight PASS.
- **Failure A — per-witness non-vacuity:** helper `record_terminal_event_contract` fails at `tests/FieldAlignedCurveNetworkTests.cpp:4713` because the torus network has zero `candidate_traces()`. The same report records the current A2a network with `networkTraceCount=0`, `networkEventCount=0`, then A2b rejection `UncutFaceComponentOrbitSeedNotUnique`.
- **Failure B — terminal-kind cardinality:** C5 fails at `:6701` because `producedTerminalKinds.size()` is **3**, not 2. The failure itself proves both named required kinds are present: `TraceIntersection=prescribed sphere` and `MandatoryBarrierTermination=two-ring`. The sphere publishes terminal kinds `2,4`; enum authority maps `4` to `SingularityTermination`.
- **Authority tension requiring review:** the frozen TB plan's completion criterion says every trace must terminate at an actually produced typed terminal event kind with both `TraceIntersection` and `MandatoryBarrierTermination` represented non-vacuously. The plan also says C5 should observe “exactly the required terminal event-kind set.” Review must decide whether that phrase intentionally forbids additional lawful terminal kinds and whether every witness was intended to be individually non-vacuous. TB may not choose between those readings.
- **Adjudication — COMPLETE.** `M3-CP4c-1-TB-R4-REVIEW-PLAN` classified **both** failures as **test-side over-specification**. Record: `Architecture_M3_CP4c1_TB_R4_Independent_Review_Record.md`. The plan's completion wording (line 131) is normative and states a *property* with no cardinality; line 101's "exactly the required terminal event-kind set" is a TB reporting instruction, and "including" is membership language. The failing assertion's own message says the union "must be **non-vacuous**", which is non-emptiness, not two.
- **Failure A root cause — a recurrence of `M3-CP4c0b-DG-CAND-02`.** The same torus witness was over-specified one checkpoint earlier, in the opposite direction ("must be empty"), and resolved test-side for the same reason. C5 demands non-empty torus candidate traces while accepted identity `TraceTerminationCorrection.TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded` — green in this same run — requires zero. Line 131 is universally quantified over produced traces, so a zero-trace witness satisfies it vacuously; the helper's per-trace loop already handles that correctly and line 4713 is pure additive over-specification.
- **Failure B root cause — the cardinality would forbid correct behavior.** `SingularityTermination` is a frozen terminal kind and a required outcome of the CP4c-0/0b termination contract. `size() == 2` goes red *because* a trace correctly terminated at a singularity, re-freezing the exact gap `LESSONS.md` **64e** names (`SingularityTermination` declared since CP3b, emitted nowhere). The third kind is that defect being repaired, not a violation.
- **What the product proved.** The run reported exactly two assertion failures, so every per-trace assertion passed: on two-ring and the prescribed sphere, **every produced trace terminated at exactly one typed terminal event whose kind was actually published** — line 131's requirement, met.
- **Masked checks.** The fatal `ASSERT_EQ` at `:6701` returned before lines **6712** and **6717**, so the two named-kind checks have **never executed**. Measure W3 requires the successor TB to report them individually.
- **Owning correction:** `M3-CP4c-1-CB4` under measures **W0-W7**, test-side only, `src/`/`include/` frozen, 355 selector hash unchanged, C5 corrected in place at ordinal 355.
- **Stable-count rationale:** C5 has never been accepted and the accepted 353 predecessor is green in the same run; the resolution is test-side. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c1-TB-R4-CAND-03 — two non-gating diagnostics assert a sphere failure that accepted authority now contradicts — **RESOLVED / TB CONFIRMED / TEST-SIDE INVERTED PRECONDITION / NON-STABLE**

- **Observed:** in TB-R4 run/job `33141046678 / 98751794167`, `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique` and `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable` both returned red. Both encode a **failure precondition**: they expect prescribed-sphere network construction not to succeed, the second asserting `sphere.network.has_value() == false`. Accepted CP4c-0/0b authority now publishes that network — 24 traces / 56 events — so both assert the opposite of accepted reality.
- **Classification:** test-side inverted precondition. **Not** a product regression and **not** a gate blocker: both are non-gating with zero gate credit, and the required 355 gate is unaffected. The harm is interpretive — a permanently-red diagnostic that contradicts accepted authority will be misread by the next reader as a product failure, and it masks any genuine future red in the same identity.
- **Root cause:** the anti-pattern `LESSONS.md` names directly — *"A test that asserts a witness currently fails will invert the day you fix it."* It was written down before the failure that repeated it. Both identities were authored while the sphere could not produce a network; CP4c-0's grazing transit and CP4c-0b's termination contract made it produce one, and nothing swept the identities that had encoded the old incapacity.
- **CB4 disposition:** both mandatory W5 identities were **RETIRED** at semantic/test source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`. `BranchBoundaryPairingContinuationIsUnique` lost only its stale failure-coupled branch-boundary census; accepted branch-frame/pairing, independent tamper-oracle, ambiguous/incomplete topology, and candidate transport composition/binding identities retain the actual invariant. `PrescribedSphereCandidateTraceTransportFailureSiteIsObservable` lost only observability of the now-nonexistent `InvalidCandidateTraceTransport` failure; accepted prescribed-sphere 24-trace/termination, closed-producer, C5, and candidate-trace transport identities retain positive coverage. Full rationale was in `Architecture_M3_CP4c1_CB4_Code_Build_Report.md`, retired in the fifth consolidation; it is preserved in `M3_CP4c_Consolidated_Record.md` and reproduced in this entry.
- **Selector effect:** the non-gating selector is now three report-only publisher identities, SHA-256 `537a8010033452a16be5f6a80926ea61c065f7f7f443b5b2950f73c8b8ffcd6a`; the frozen 355 required selector is unchanged. W5b was left untouched.
- **Closure evidence:** TB-R5 run/job `33161644741 / 98817323175` passed the complete 355 gate, executed the surviving report-only diagnostics, and explicitly confirmed both retired W5 identities are absent. Neither survives as an unexplained red. No product change was required for this resolution.
- **Stable-count rationale:** both identities are non-gating, have never been accepted, and no accepted-green identity regressed. **+0 events / +0 recurrences.** Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c1-TB-R4-CAND-02 — start-of-turn snapshot/read-mode gate missed before initial inspection — RESOLVED / PROCESS-ORDER / NON-STABLE

- **Observed:** this ChatGPT Web turn performed initial repository source/document connector reads before the mandatory per-turn policy read and before declaring `READ_MODE=snapshot`, despite a multi-file TB closeout being known. This is the exact Step-2 anti-pattern in `TOOL_USE_CONSERVATION_POLICY.md`.
- **Correction:** piecemeal inspection stopped after the miss was recognized. Source-snapshot run `33141471428` captured exact control head `7e5d30854e0d776bae5bad282c5aad1a45bbae45`; snapshot artifact `9674093771` / `sha256:36957a482d62913a6ca1ec694b43d85e8772c1d1c2d77c7c8e8aa4422404850e`, archive SHA-256 `b68e2e178fc51982d4c99edf1c263c9e1ea08405eb9c9fc63ffb7c1a16b5b55d`. Static closeout inspection then used the local snapshot.
- **Semantic effect:** none. The immutable TB package, 355 selector, test commands, result evidence, and pre/postflight were unaffected; no rerun is warranted.
- **Disposition:** resolved process/control-order defect. The successor review must perform its start-of-turn policy reads and choose `READ_MODE` before its first repository source/document inspection.
- **Stable-count rationale:** control process only; **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

TB-R8 is **INCOMPLETE / BLOCKED BY VALID PRODUCTION TERMINATION FAILURE** on run/job `33028238313 / 98374531360`, control `078aac03923c0badc42d150397065fe5b33212c6`, consuming immutable CB8 package `9628445643` at semantic source `19ba8e9c5e58f9c33c14b309841165d3f0401db5`. P1 completed **342/343** identities: 341 pass, ordinal 338 red after 853.437 s with `gcd(): while running too long!`, ordinal 343 incomplete at explicit user cancellation. First-316 and first-328 remain green. No acceptance credit; P2-P8 were not reached. Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **47**. Its termination candidate later transferred to CP4c-0b after CB9 bounded the cost path.

## M3-CP4c0-TB-R9-CAND-01 — GMP backend invalidates legacy digit-limited lossy-round-trip test precondition — RESOLVED / NON-STABLE / TEST-SIDE GMP PORTABILITY

- **Observed:** TB-R9 ordinal 333 `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` failed at `ASSERT_TRUE(found)` before the production vertex-sector predicate was exercised.
- **Root cause:** the test searched for a witness by calling `ENumber::to_double(18)` and relied on the legacy backend's explicit 18-decimal-digit render/parse truncation. The GMP backend implements `to_double(int)` as `mpq_class::get_d()` and ignores `maxDigits`; the backend-specific witness search therefore did not establish its intended lossy precondition.
- **User-authorized bypass:** the user explicitly skipped `M3-CP4c-0-TB-R9-REVIEW-PLAN` and authorized `CB-R10` followed by `TB-R10` for this GMP-related defect only. The skipped review is not retroactively marked complete and does not adjudicate `CAND-02`.
- **Correction:** CB-R10 changed only `tests/FieldAlignedCurveNetworkTests.cpp`, preserving the test identity and production predicate. The witness is now deterministic and backend-independent: exact `epsilon = 1/7` is converted through an explicitly lossy numerator/denominator-to-double round trip in the test itself, and the test asserts the reconstructed direction differs before invoking the production exact predicate. No GMP or product arithmetic semantics were changed.
- **Build proof:** semantic source `30ef2792e2915e0016dfd11f5fa2b3727e5503c0`; compile run/job `33067140968 / 98499967674`; GMP package `9644214591`, ZIP SHA-256 `b9e7729fb557eddc203e38a1c11564bab3ad180982e10740d4374fe06748a390`; all eight standard targets compiled/linked, preflight/build exit 0, source clean, `runtimeExecution=false`.
- **Focused runtime proof:** artifact-only TB-R10 run/job `33067370314 / 98500728780` consumed only package `9644214591`; the exact identity selected once and passed (`exit=0`, `failures=0`, `errors=0`, 5 ms harness elapsed); package preflight/postflight immutable PASS; no configure/compile/relink/repair/discovery/benchmark occurred. Result artifact `9644274456` / `4d80bc1ca8e9d0f624e709eb7c467e5b1c2c880d6a1619f1f8ced95151305693`; log artifact `9644274922` / `2c8922ccf03e356db0e78fbe07a4a22bb99019009e4e40669f58bba16fcdd122`.
- **Disposition:** resolved as a test-side portability/precondition defect. Focused TB-R10 supplied individual corrective proof; the later whole-gate TB-R9 re-proof `33079817998 / 98543736213` selected all 346 frozen identities and passed **346/346**, including this identity, so the correction is now also proven in gate context. CP4c-0 is closed/accepted.
- **Stable-count rationale:** accepted CP4ab prefix remains 316/316 and CP4c-0 has never been accepted; **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R9-CAND-02 — exact-magnitude positive-control fixture enters zero-time continuation — RESOLVED / NON-STABLE / TEST-SIDE FIXTURE-PRECONDITION

- **Observed:** TB-R9 ordinal 344 `ResolvedBranchCorrection.ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance` proves the oversized exact-width rejection, then its supposed narrow positive control expects a decision but receives an error.
- **Root cause:** on face `(0,1,2)`, `boundary_point(incoming=(0,1), 1, 2)` has exact barycentric coordinates `[1/2,1/2,0]`. The old positive-control direction `{-1,2,-1}` marks coordinates 0 and 2 as outflow; their exact candidate exit times are `1/2` and `0`, so coordinate 2 wins at exactly zero. `resolve_field_branch_continuation` is contractually required to return typed `BranchContinuationDegenerateEntry` for `time == 0`; production was failing closed as designed.
- **Correction:** CB-R11 changed only `tests/FieldAlignedCurveNetworkTests.cpp`. The positive control now uses direction `{-2,1,1}`, for which only coordinate 0 is outflow and the exact winning exit time is `(1/2)/2 = 1/4`. The test now asserts an `EdgeExit` on outgoing edge `(1,2)` at exact `boundary_point(outgoing,1,4)`. The oversized exact-magnitude rejection and all production/GMP arithmetic semantics are unchanged.
- **Build proof:** semantic source `267272d22f7de67ce7d8e368a53cc78a37ca3e8f`; compile run/job `33077493539 / 98535503386`; GMP package `9648550565`, ZIP SHA-256 `1f0275e96fa75b7fc6fb447eaffb79b414c94230823da7897a4f2d91df33615c`; all eight standard targets compiled/linked, preflight/build exit 0, source clean, `runtimeExecution=false`.
- **Focused runtime proof:** artifact-only TB-R11 run/job `33077761701 / 98536455697` consumed only package `9648550565`; the identity selected exactly once and passed (`exit=0`, `failures=0`, `errors=0`, 39 ms harness elapsed); package preflight/postflight immutable PASS; no configure/compile/relink/repair/generated discovery/performance benchmark occurred. Result artifact `9648618375` / `469cab3ee5a541a5faa29fcdac2a6ff213ca202c8ff38522e131b0a9a4ba6113`; log artifact `9648618836` / `c15831693911134a4ab3eba6fa8060af8b95e85eac679d5374c632fcecdc908d`.
- **Disposition:** resolved as a test-side fixture/precondition defect. The skipped TB-R9 review remains skipped/not completed. The later whole-gate TB-R9 re-proof `33079817998 / 98543736213` passed **346/346**, including this corrected identity; CP4c-0 is therefore closed/accepted. This candidate remains non-stable and adds no regression event.
- **Stable-count rationale:** no accepted-green identity regressed; **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0b-DG-CAND-01 — tar/grep pipefail aborts source-archive fixture preflight before runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first DG control run/job `33120437486 / 98685729035` reached package-manifest verification but executed **0/7** Directional identities and reported orchestration failure.
- **Root cause:** the temporary harness used `tar -tzf "$source_archive" | grep -Fxq ...` under `set -o pipefail`. `grep` exited after finding the fixture, closed the pipe, and `tar` reported a write error; the harness then misclassified a present fixture as missing.
- **Correction:** orchestration only. The corrected payload materializes the tar listing before running the fixture lookup, is hash-pinned by the caller, and was triggered separately. No production/test/fixture/selector/package byte changed.
- **Proof:** result/log artifacts `9666237104 / 9666237713`, SHA-256 `d1b4c27a4bf74ab5bf9133cf66242f6136456f18c175ca61688afbc7682d5aee / e8754b6774c0bdcebc6a10678d207f5bd50089686d9aa99fb05d855148d0779c`; corrected run `33120730355` executed all seven identities exactly once.
- **Disposition:** resolved orchestration-only control failure; no semantic evidence from the zero-runtime run.
- **Stable-count rationale:** **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0b-DG-CAND-02 — new torus contract identity equates zero trace publication with zero network nodes — OPEN / NON-STABLE / TEST-AUTHORITY CONTRACT-SURFACE

- **Observed:** authoritative corrected DG run/job `33120730355 / 98686699036` is **6/7 PASS**. `TraceTerminationCorrection.TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit` is the only red. `candidate_traces().empty()` passes; `torus.network->nodes().empty()` fails at `tests/FieldAlignedCurveNetworkTests.cpp:6952`; no separate failure is reported for the following zero-event assertion.
- **Runtime validity:** every DG identity selected exactly once; zero escaping C++ exceptions; no timeout/configure/compile/relink/repair/discovery/mutation; immutable postflight PASS. Result/log artifacts `9666352028 / 9666352544`, SHA-256 `286f738f02315d72dea7cc03bed61bc12ef6b5345ddf15264a898b5bfa45db72 / 651e9cb9fc78d109d725fdf725fd26b72c450f6bba44fd77e638780c0df2712e`.
- **Static localization:** candidate construction publishes network nodes from source singularity vertices and mandatory-edge endpoints before candidate tracing, so zero candidate traces/events do not mechanically imply zero network nodes.
- **Authority tension:** the frozen CP4c-0b definitions do not state a general torus zero-node invariant, but the earlier S1 census did record torus `A/B/C=0/0/0`, zero contacts, `nodeCount=0`, and no events. That node delta must be adjudicated rather than dismissed.
- **Required adjudication:** independent `M3-CP4c-0b-DG-REV` must decide whether the new assertion over-specifies the frozen zero-trace/contact contract or whether the changed node publication is a real S2-S6 product-contract breach. No product/test correction or full 353 TB is authorized before review.
- **Stable-count rationale:** these seven new identities have never been accepted and the predecessor 346 was not executed by DG; no accepted-green regression is established. **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0b-DG-CAND-02 — torus publishes non-empty nodes where a new identity expected empty — **RESOLVED** / TEST-SIDE OVER-SPECIFICATION / NON-STABLE

- **Observed:** `M3-CP4c-0b-DG` VALID SEMANTIC RED 6/7, run/job `33120730355 / 98686699036`, package `9664890562`. The sole failure is `TraceTerminationCorrection.TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit` at `tests/FieldAlignedCurveNetworkTests.cpp:6952`: `torus.network->nodes().empty()` was **false**. The preceding zero-candidate-trace and following zero-event assertions both **passed**.
- **Adjudicated 2026-08-27** by `M3_CP4c_Consolidated_Record.md`. **No S2-S6 contract breach is established.**
- **Root cause - a rail-authority divergence.** Network nodes are structural: `canonical_field_aligned_candidate` (`src/geometry/SurfaceCellTracing.cpp:3046-3110`) builds `nodeVertices` from singularity vertices and mandatory-edge endpoints **before** tracing, and the diff from the S1 source `4bb46780...` to the S2-S6 source `737f93be...` does not touch that block. S1 measured the torus with `rails_from_atlas` (`tests:5516`) and reported `nodeCount=0`; the DG identity built it with the pipeline's `authoritativeRails` (`tests:3782`). Different rails give different mandatory edges, hence different nodes. **Both figures are correct and answer different questions.**
- **Supporting computation, from the committed fixture with no product code:** the torus has **0 singularities** and **0 boundary vertices**; the same per-vertex fan-holonomy method reproduces the prescribed sphere's **8** singularities exactly (`{0, 8, 21, 24, 25, 34, 45, 49}`), which validates the method. Every torus node is therefore a mandatory-edge endpoint.
- **Corroboration:** with zero singularity ports, `canonical_field_aligned_traces_and_events` allocates no node - `field_aligned_publish_origin_events` iterates `candidateTraces`, and every other allocator requires a trace. That is consistent with the observed zero traces and zero events.
- **Classification:** **test-side over-specification.** The identity asserts a total (`nodes().empty()`) where CP4c-0b owns a relation (no node of contact provenance). The identity has never been accepted, so correcting it is an in-flight fix, not an accepted-expectation edit.
- **Not yet proven:** that the pipeline torus's nodes are all mandatory-edge endpoints is inferred from accepted green preconditions requiring >=2 regions with a non-trivial cycle, **not measured**. **Measure T1 must prove it, and its decision table can route back to review**: a pipeline-torus node with `contact` provenance, or with no lawful provenance, would be a real S2-S6 defect.
- **Owning measures:** T1 (rail-authority and node-provenance census, mandatory first), T2 (correct the identity), T3 (make the census self-describing with `railAuthority`, `mandatoryEdgeCount`, `singularityCount`).
- **RESOLVED 2026-08-28** by `M3-CP4c-0b-CB2` + `M3-CP4c-0b-DG-T4`. T1 returned the **first decision row**: atlas-derived rails give 0 mandatory edges / 0 singularities / 0 nodes / 0 traces / 0 events; pipeline-authoritative rails give **48 `HardFeature` mandatory edges / 0 singularities / 48 structural endpoint nodes / 0 traces / 0 events**, every node a mandatory-edge endpoint with **zero contact provenance**. No second rail-authority divergence was found. The DG review's one flagged inference is therefore **measured, and its caveat is withdrawn**. T2's corrected identity and T3's self-describing census were verified line-by-line against the review specification with no shortfall, and `M3-CP4c-0b-DG-T4-EXEC` returned **7/7** on package `9668492827`.
- **Residual, tracked under `M3-CP4c0b-P03-CAND-01`, not here:** S2-S6 remain **unmeasured against accepted authority**. The four accepted identities in the blast radius are ordinals **7**, **9** (authorized to change) and **12**, **13** (**not authorized**), the last being the four-triangle fan's absolute `EXPECT_EQ(8U, nodes().size())`, which decomposes as 5 structural nodes plus one terminal 0-cell per barrier-terminating trace.
- **Stable-count rationale:** only the seven never-accepted new identities ran; no accepted-green predecessor regression is established. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0b-T5-CAND-01 — immutable CB2 package cannot publish the U3/U4 pre-gate evidence contract — RESOLVED / EVIDENCE-CAPABILITY / NON-STABLE

- **Observed:** `M3-CP4c-0b-TB-T5` stopped before the first gate identity. U0 static package/selector authority passes, but U3 requires a before-gate fan/two-ring census containing every trace terminus, barrier-termination count, all-node provenance with `railAuthority`, event histogram, arrival-comparison inconclusive status, and mutual-tie firing. Package `9668492827` has only partial compiled publishers; `FieldAlignedContactCensus` and `cp4c0b_contact_census_report` do not expose the complete contract. U4 likewise has no dedicated per-witness N1/N2/N4 silence publisher.
- **Binding conflict:** U3 says measure before gate. U7 prohibits source/test/fixture/selector/package mutation, compile/relink/repair, or replacement package inside T5. Running 353 first and inferring missing fields would weaken the independent review and is forbidden.
- **Classification:** evidence-capability/pre-gate observability blocker, **not** evidence of a product regression. No Directional runtime executed and accepted authority remains unmeasured.
- **Owning adjudication — COMPLETE.** `M3-CP4c-0b-TB-T5-PREFLIGHT-REV` upheld the blocker and **authorized** a bounded instrumentation Code + Build, `M3-CP4c-0b-CB3-INSTR`, under measures **V0-V7**: test-side and non-gating-selector-side only, zero production change, and the 353 selector must not change. Record: `M3_CP4c_Consolidated_Record.md`.
- **Root cause, refined by that review.** The defect is in the measures, not the package: U3/U4 were issued after `9668492827` was built and were written from the design intent rather than from the selector. Two mechanisms, neither found by the blocker turn: (1) both 353 identities that build the four-triangle fan — `FieldAlignedCurveNetworkIsAClosedProducerOnEveryReachableWitness` (`tests/FieldAlignedCurveNetworkTests.cpp:6348`) and DG#7 (`:7044`) — discard the result with `(void)` and succeed unconditionally, so a fan build failing closed on `N1`/`N2`/`N4` passes both; (2) six of the seven `...IsPublishedNonGating` census identities are **compiled but selected by nothing**, including `PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating`, which already computes ordinal 13's second term. Consequence: part of the gap is selector-side and costs no code, and **no production instrumentation is needed** — the census channel is already threaded through the producer (`src/geometry/SurfaceCellTracing.cpp:2890`).
- **Closure proof:** CB3-INSTR supplied the missing compiled observability and authoritative T5 retry `33136084757 / 98736295227` published it: fan nodes 8 / barrier traces 3 / mutual 0 / inconclusive 0 / N1/N2/N4 silent; two-ring nodes 9 / barrier events 3 / FirstContact pairing 3/3 / mutual 0 / inconclusive 0 / guards silent; prescribed sphere network 24 traces. U3/U4 = PASS and `materialNewEvidence=false`. The blocker is therefore closed without a product change.
- **Stable-count rationale:** evidence-capability only; +0 events / +0 recurrences. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0b-T5-CAND-02 — cleanup manifest trigger raced the source-snapshot marker — RESOLVED / ORCHESTRATION / NON-STABLE

- **Observed:** creating the required cleanup manifest triggered durable cleanup run `33130560363` at event SHA `28f02117f2162418a90a843a83edcd7f4b5c268d`; the subsequent source-snapshot marker advanced the branch to `640a35ae08a3a624ac3799b42c9ddf6c31300be0`.
- **Fail-safe:** cleanup compared remote head against its event SHA and stopped before commit/push because they differed. PR-comment deletion was skipped; `runtimeExecution=false`.
- **Classification:** orchestration/process-control only. The final cleanup is triggered only after all temporary paths and all other branch writes are complete.
- **Stable-count rationale:** +0 events / +0 recurrences. Totals remain **42 / 14 / 28**.

## M3-CP4c0b-T5-CAND-03 — T5 closeout control-plane startup/parser mismatches — RESOLVED / ORCHESTRATION / NON-STABLE

- **Observed 1:** premature cleanup run `33135477355` removed then-staged T5 temporary state before the final execution payload was published. No Directional runtime occurred.
- **Observed 2:** schema caller run `33135693069` failed at workflow startup because reusable observer permissions were insufficient. It executed no Directional runtime and was corrected before execution.
- **Observed 3:** initial T5 execution run `33135877807` passed U0 and selected all four non-gating identities, but the control parser expected `railAuthority=AtlasDerived` while the publisher emits `railAuthority=atlas-derived`. The 353 gate remained **0/353**; immutable postflight passed. Result/log artifacts `9672002477 / 9672002723` have digests `3daf013e…fed46 / 62fd1cd7…b852c`.
- **Correction/proof:** normalize only the parser spelling, SchemaStore-validate in run `33136024237`, then execute authoritative retry `33136084757`, which passes U0, U3/U4, **353/353**, and postflight. No package/product/test/fixture/required-selector semantic byte changed between attempts.
- **Stable-count rationale:** orchestration-only; +0 events / +0 recurrences. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0b-P03-CAND-01 — the accepted trace-contact mechanism is defective in six respects — RESOLVED / PRODUCT SEMANTICS / PRE-EXISTING

- **Observed:** `M3-CP4c-0b-CB1` stopped at binding precondition P0.3, which required `FieldAlignedNetworkEventKind::TraceIntersection` to be declared and produced by nothing. Static inspection of semantic head `49831e30433d72504a69b5a8c817aa6fa00f953c` proved it is produced at three sites and that **A2a already implements crash-on-contact**.
- **D1 - the contact predicate is face equality.** `field_aligned_first_trace_contact` (`src/geometry/SurfaceCellTracing.cpp:1278-1307`) tests only `segment.sourceFace != existingSegment.sourceFace`; everything after it returns a contact. Two traces on parallel, non-crossing paths through one triangle are declared in contact and the later one is truncated. `field_aligned_common_carrier` only labels the contact; it does not gate it.
- **D2 - priority is trace index order.** `existingIndex < traceIndex`. This is the `TraceSeniority` metric the CP4c-0b DEFN §4.2 ranks worst and §5 forbids in production; it is the shipped behaviour.
- **D3 - the contact node ignores geometry.** `field_aligned_append_contact_node` (`:1310-1318`) uses `sourceFace.vertices().front()`, the lowest-numbered vertex of the triangle.
- **D4 - the pass runs after tracing completes.** `canonical_field_aligned_candidate` (`:1804-1817`) returns the tracing error before reaching `finalize_field_aligned_events`, so **the contact pass is unreachable for any trace that never finishes**. This is the mechanism behind the six circulating prescribed-sphere traces and TB-R8's 853 s, and it is the shape `DESIGN.md` 4.6 disclaims as post-hoc repair.
- **D5 - `TraceIntersection` is overloaded** across origin junction (`:1391`), crash-on-contact (`:1433`) and self-closure on a revisited face (`:1512`).
- **D6 - truncation erases a legitimate terminus:** `terminalBarrier`, `terminalPoint` and `terminalSingularity` are all reset at the contact.
- **S1 review evidence (2026-08-27):** TB-S1 raw artifact `9656967036` independently confirms reached included site-B counts are zero (two-ring `A/B/C=1/0/0`, torus `0/0/0`); the excluded fan is `1/0/0`; sphere is explicitly unreached at N1 and has no contact-count claim. Therefore the P0.3 non-proper-current-contact stop is **not triggered**, and S3 is behavior-preserving with respect to currently selected site-B contacts on reached accepted witnesses. This is a bounded absence result, not a live proper-crossing positive.
- **S1 migration evidence:** the two-ring's site `A=1` and sole `TraceIntersection` prove S2 intentionally changes accepted event vocabulary at the singularity junction. The TB-S1 review explicitly authorizes re-authoring `DeclaresTraceIntersectionsAsTypedNetworkEvents` and `IndependentCompositionOracleValidatesTraceEventGraph` for that measured site-A change; unrelated predecessor expectation edits remain a stop. D1-D6 remain unresolved until S2-S6 land and the full CP4c-0b TB is green.
- **Classification:** **pre-existing product semantic defect in accepted authority**, latent because the accepted witnesses are small and their traces short. Not a regression introduced by CP4c-0 or CP4c-0b.
- **Re-proof exposure:** correcting D1 strictly reduces the contact set, so any accepted trace currently truncated by a non-crossing contact would continue - changing segments, terminus, events, node set and downstream digests. CP3b's contact identities, CP3a trace content and CP4ab's node count and `network_digest` are in scope. **This must be measured, not estimated.**
- **Owning measures:** S1 (census, mandatory first and empowered to route back to review), S2 (vocabulary split), S3 (exact proper-crossing predicate), S4 (arrival priority replaces seniority), S5 (relocate into the trace loop), S6 (node position and terminal datum).
- **Resolution proof:** S2-S6 landed the owned corrections. Authoritative T5 `33136084757 / 98736295227` then re-proved accepted authority **316/316**, CP4c-0 **346/346**, and the full CP4c-0b gate **353/353**. Watched ordinals 7/9/12/13 all pass; the two-ring non-gating census reports all three barrier terminations paired to FirstContact; fan/two-ring guard and arrival censuses are clean; prescribed sphere publishes 24 traces. D1-D6 are therefore closed in accepted runtime authority.
- **Stable-count rationale:** this was a pre-existing latent product defect, not an accepted-green regression introduced by the corrective work; the full predecessor gate remains green after correction. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R8-CAND-01 — grazing-edge tracing enters pathological exact-arithmetic work; practical termination guard is insufficient — RESOLVED / NON-STABLE / PRODUCTION PERFORMANCE-TERMINATION

- **Observed:** immutable TB-R8 P1 completed 342/343 fresh processes. Ordinal 338 `ResolvedBranchCorrection.AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections` took **853.437 s** and then failed with `gcd(): while running too long!`. Its last deterministic atlas line was singularity 7, fan 3→0, edge `(43,49)`, lift `-1`. Ordinals 339-342 passed. Ordinal 343 `ResolvedBranchCorrection.GrazingTraceSegmentsPublishExactEndpointSupport` did not return before explicit user cancellation.
- **Prior baseline:** the pre-CB8 338-gate was green in TB-R7. CB8 deliberately changed grazing continuation semantics; the prescribed-sphere network now progresses into a path that did not complete within a reasonable bound.
- **Classification:** production performance/termination candidate, **not** a structurally invalid fixture, expectation error, or CI-only problem. The full TB-R8 gate is incomplete and receives no acceptance credit, but ordinal 338 is trustworthy completed runtime evidence.
- **Proximal source localization:** `src/numerics/BigInteger.cpp::gcd` throws after 10,000 Euclidean iterations. `ENumber::simplify()` invokes it while normalizing exact rationals. This is an emergency backstop, not a practical field-tracing termination policy.
- **Existing guard insufficiency:** `FieldAlignedTraceTraversalGuard` detects exact repeated `FieldAlignedTraceTraversalState` and enforces `field_aligned_trace_step_budget(topology)`. On `sphere_prescribed` the current formula yields **1,775,616** steps (`192*4*(288+1)*8`). The recurrence key contains the exact boundary point, so a topologically repeating path with changing rational parameters may evade early cycle detection.
- **Root-cause confidence:** high that termination/progress guarding is operationally insufficient; medium on the exact first non-progress mechanism because the cancelled run has no stack trace or exact-operand growth census.
- **Required adjudication:** independent review must identify a semantic progress/cycle invariant and a practical deterministic finite-work bound before any correction. Do not simply lower an arbitrary constant and do not make a workflow/test timeout the product guard.
- **User stop rule:** **do not re-run TB-R8 until the guard is implemented and compile-green.**
- **Resolution proof:** CB9 bounded the pathological work; CP4c-0b then replaced the post-hoc termination mechanism. Authoritative T5 `33136084757 / 98736295227` publishes the prescribed sphere network with **24 traces**, zero escaping exceptions, no slow-threshold violation, and U4 guard evidence clean on the measured fan/two-ring witnesses. The CP4c-0b-owned circulating-trace blocker is discharged.
- **Stable-count rationale:** this remained non-stable until the successor contract closed; no accepted-green regression is created by its resolution. **+0 events / +0 recurrences**. Totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R4-CAND-01 — prescribed sphere A2a rejects reciprocal branch flow at edge 6-8 — ACTIVE / NON-STABLE / **ROOT CAUSE IDENTIFIED: near-tangency; the invariant is too strong, A1 is correct**

- **Observed:** creditable Q8 after exact package integrity, frozen **338/338 PASS**, and F3 **2/2 PASS**. G5 publishes `fieldAlignedCurveNetwork=false;networkError=BranchTransportFlowDisagreement;sourceEdge=6-8;sourceFace=6-8-9;relatedSourceFace=6-8-97;branch=3;relatedBranch=1;traceSeedVertex=0;traceSeedSingularity=0` plus six exact source/target direction values.
- **Q8 impact:** criterion 2 is binding red because the sphere does not publish the required 24-trace network. P4 predicted Q8 would remain red; G5 supplies the concrete cause.
- **Static localization:** `src/geometry/SurfaceCellTracing.cpp:644-671`, `validate_field_branch_transport_flow`, rejects when the shared carrier is source-outgoing but not target-incoming.
- **Classification:** semantic candidate requiring independent authority review. Do not infer production defect from the error code alone.
- **Required adjudication:** reconstruct edge-`6-8` pairing + signed-lift authority, account for Amendment-7 gauge, determine why source outgoing is not target incoming, and identify the owning invariant before authorizing correction.
- **Stable-count rationale:** accepted **316/316** remains green and CP4c-0 has never been accepted; **+0 events / +0 recurrences**.
- **Adjudicated 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §7 (retired TB-R4 review). **Symptom proved exactly** by decoding the six exact rationals: source face `6-8-9` canonical `(6,8,9)` has `d[2] = −1.0035357904` (edge `6-8`, opposite vertex 9) ⇒ **Outflow**; target face `6-8-97` canonical `(6,8,97)` has `d[2] = −0.5769964399` ⇒ **also Outflow**. Both triples sum to **exactly** zero, so both are valid `is_barycentric()` authority. **A continuous direction cannot exit a shared edge from both incident faces.**
- **Not a tolerance artifact.** `|d| = 1.0035` and `0.5770` are three orders of magnitude above every epsilon in this codebase, so the "route A′ within-face tolerance band" explanation from the first CP4c-0 review is **excluded**.
- **The invariant is correct.** Amendment 4 / measure E5 is right as stated; the physically correct target branch is **`3`** (= branch `1` + 2), whose `d[2] = +0.5769964399` is **Inflow** exactly as the crossing requires. **The published lift is off by 2 — a full reversal.**
- **Context worth keeping:** the source face is a genuine **`1×2`** face (outflow `8-9` and `6-8`, inflow `6-9`), so CP4c-0's exact min-ratio rule *chose* edge `6-8` from a real ambiguity — the continuation rule is working; the transport that follows it is not.
- **Classification:** **production semantic defect** in cross-face branch transport authority (A1) **or** in the branch A2a carries into it. Not fixture, not diagnostic false positive, not admissibility. **Mechanism undetermined and deliberately not guessed.**
- **Hypothesis refuted and recorded** (review §5): per-face canonical-normal parity. The two faces *do* have opposite canonical parity, and parity mismatch covers **86.8 %** of the sphere's interior edges (torus 92.6 %, mechanical 90.2 %, fan 50 %) — but the gauge is an **index shift** into a per-face array and cancels in `matching + g_X − g_Y` regardless of frame. Two supporting assumptions were also excluded: `{primary, secondary, −primary, −secondary}` reproduces the stored rawfield ordering `{v0, v1, −v0, −v1}` **exactly**, and `v1` is `+90°` CCW from `v0` about the mesh normal in **all 192** faces.
- **Surviving candidates:** (a) **matching sign/direction convention** — a sign error yields a difference of exactly 2 when the true matching is odd and none when even, is invisible where matching is 0, and concentrates near singularities; edge `6-8` is incident to **vertex 8, a singularity**; (b) **matching aliasing** (`DESIGN.md` §4.1, Vaxman et al.); (c) **A2a carries the wrong branch** from an earlier step — the failure is several steps from seed vertex 0.
- **Decisive test — measure H1:** a non-gating **cross-face flow-agreement census** over A1 authority alone (no tracing): every interior edge × every branch, both directions, reporting each violation with the **published `signedLift`** and both exact `d[opp]`. Violations only on odd lifts ⇒ (a); sparse near singularities without a parity pattern ⇒ (b); **zero violations while the trace still fails ⇒ (c)**, redirecting to A2a.
- **Disposition:** `M3-CP4c-0-CB5`, measures **H0–H7**, diagnostic-only. **H5 prohibits any production change this cycle** — a sign flip on one failure site with the census unrun would be a fixture-shaped guess at global authority.
- **CB5 compile status:** H1/H2/H3 are compiled in semantic source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e` and package `9601160869`; H4 source provenance is recorded; no runtime has executed. Mechanism remains unresolved until TB-R5 runs H1.
- **TB-R5 H1 result:** `32994846466 / 98261255799`, result `9616160533` / `1ecfd85f…02ad8`. H1 checks **4224** pairs and finds **390** disagreements (9.23295%): two-ring `4/160` (all lift 0), fan `2/32` (all lift 0), sphere `144/2304` (`0:102, ±1:7, ±2:6, ±3:8` per sign counts as published), torus `240/1728` (`0:184, ±1:11, ±2:11, ±3:6` per sign counts as published). The live edge `6-8` failure appears as the expected reciprocal pair at lifts `+2/-2`.
- **H1 adjudication boundary:** **H-A is excluded** because violations are not odd-lift-only and are dominated by lift 0. **H-C is excluded** because the A1 census is nonzero. A ~50%/uniform systematic index error is unsupported by 2.5–13.9% witness rates. **H-B remains plausible but is not proved**: the census does not establish singularity localization, and the manually prescribed fan has two lift-0 disagreements even though computed matching aliasing is absent there. The next independent review must distinguish matching aliasing from another sparse A1 pairing/flow inconsistency before authorizing production semantics.
- **Q8 after H1:** still creditable and RED only at binding criterion 2; G5 remains `BranchTransportFlowDisagreement` at edge `6-8`, branch `3 → 1`, `signedLift=2`, now with complete seven-step trace history. This is continuation of the same candidate, not a new accepted regression.
- **Standing caveat:** the accepted **316** being green does **not** establish that cross-face transport is correct — E5 created that invariant in CB2 and no accepted identity asserts it. If the census returns violations at a material rate, some accepted traces may be wrong and were never checked; that is a pre-existing defect newly detectable, not a CP4c-0 regression.
- **Stable-count rationale:** accepted 316 green, CP4c-0 never accepted. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.
- **Reviewed 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §7 (retired TB-R5 review). H1's census **mechanism verified correct in source**: it iterates published `transports()`, applies `directed->signedLift` via `sourceBranch.rotated(...)` (Amendment 7 compliant), and compares exact `d[opp]` against exact zero on each face's own canonical key. Coverage self-check `pairsChecked = interiorEdges × 8` re-derived and correct for all four witnesses.
- **Population corrected — the four-triangle fan's 2 violations are a FIXTURE ARTIFACT.** Its census field is `make_index_one_singularity_field`, which leaves the direction vectors **globally constant** (+X/+Y on every face, inherited from `make_zero_transport_field`) and merely *imposes* `matching = ±1` on **one** edge. For the violating edge `1-4` the published lift is **exactly correct**: `matching(+1) + rawGauge[0-1-4](0) − rawGauge[1-2-4](1) = 0`. The flow disagreement is forced by a matching that contradicts the geometry, not by any A1 defect. Predicted count = one edge × two directions = **exactly the 2 observed**, and both reported `sourceD = targetD = −1/2` were reproduced by hand from the constant field and the runtime-verified gauges `A=0, B=1, C=2, D=1`. A counterfactual simulation with the gauge correction absent everywhere would give **8** fan violations, not 2.
- **Consequently the prior reading that the fan weakens H-B is WITHDRAWN.** The fan's matching is not merely "prescribed rather than computed" — it is prescribed **inconsistently with its geometry**, which guarantees a disagreement whatever A1 does. The fan bears on nothing about production.
- **The lift histogram is uninformative about matching.** `signedLift = matching + g_source − g_target` is a sum of three unobserved terms, so lift-0 dominance is consistent with almost any matching distribution. The ±1/±2/±3 tail symmetry (sphere `−3:8/+3:8`, `−2:6/+2:6`, `−1:7/+1:7`; torus `−3:6/+3:6`, `−2:11/+2:11`, `−1:11/+1:11`) is **imposed by the census's own two-direction loop**, not by the field — and every count is therefore doubled.
- **Corrected population:** distinct `(edge, branch)` disagreements are two-ring **2**, fan **1 (artifact)**, sphere **72**, torus **120** ⇒ **388 directed / 194 distinct** over three legitimate witnesses. The two-ring's field (`make_cp3a_two_ring_index_one_field`) is a genuinely rotating index-one field — `angle = base + 0.25·smoothPhase` sweeps exactly 90° around the centre — so it is a legitimate witness.
- **Hypothesis status:** **H-A excluded** (violations at lift 0 and even ±2; a sign error `k → −k` changes nothing at 0 or 2) — it was the TB-R4 reviewer's own favoured candidate and the census falsified it. **H-C excluded** (A1 is not clean), with the corollary that A2a is *not* thereby cleared. **~50% uniform index error unsupported.** **H-B undecided and undecidable as currently instrumented.**
- **Decisive measurement — measure J1:** publish per violation the three composing terms (`matching`, `rawGauge[source]`, `rawGauge[target]`) plus singular-vertex incidence and distinct-pair counts. Decision table: violations concentrated on `matching ≠ 0` ⇒ field-authority/aliasing (**H-B**); on `matching = 0` with unequal gauges ⇒ **gauge composition** defect in `build_branch_transports`; on `matching = 0` with equal gauges ⇒ **flow classification / direction publication** defect in `build_boundary_pairing`. **J3** adds an independent matching-versus-geometry check.
- **Contract reframing:** E5's cross-edge invariant audits the field's **input matching** as much as A1's composition. A witness with imposed matching **will** trip it, correctly; its firing is not by itself evidence of an A1 code defect.
- **Disposition:** `M3-CP4c-0-CB6`, measures **J0–J7**, diagnostic-only. **J0 prohibits any production semantics change** until the decision table is filled in.
- **TB-R6 J1/J3 result:** authoritative `33006282429 / 98300813772`, result `9620769314 / fe6a7317…6684`. H1 exactly reproduces the reviewed legitimate population: two-ring 4 directed / 2 distinct, sphere 144/72, torus 240/120 ⇒ **388 directed / 194 distinct**; the fan remains excluded at 2/1. Legitimate term split is matching-nonzero **48/24**, matching-zero unequal-gauge **86/43**, matching-zero equal-gauge lift-zero **254/127**. Only 52/388 legitimate directed violations are singular-incident.
- **J3 excludes current legitimate matching mismatch.** Independent geometry audit is two-ring 20/20, sphere 288/288, torus 216/216 = **524/524 agreement**. The only disagreement is the excluded fan edge `1-4`, exactly confirming its fixture-imposed matching contradiction. H-B field-matching/edge-aliasing is therefore not supported for the current legitimate witnesses.
- **Live Q8 owner selected by frozen table:** sphere edge `6-8` forward decomposition is `matching=0`, `rawGaugeSource=1`, `rawGaugeTarget=3`, `signedLift=2`; J3 agrees with declared matching. This selects **A1 gauge composition in `build_branch_transports`** as the direct owner of the live `BranchTransportFlowDisagreement`.
- **Residual class remains:** **254 directed / 127 distinct** legitimate disagreements have matching 0, equal gauges and lift 0, selecting the frozen **A1 flow classification / direction publication in `build_boundary_pairing`** row. Independent review must decide whether one lower convention defect explains both classes or whether the Q8 correction is scoped separately.
- **Disposition after TB-R6:** mandatory independent `M3-CP4c-0-TB-R6-REVIEW-PLAN`; no production fix before review. Stable counts remain **42 / 14 / 28** because accepted 316 stays green and CP4c-0 remains unaccepted.
- **Root cause identified 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §7 (retired TB-R6 review). The disagreements are a **near-tangency discretization phenomenon**, and **Amendment 4 / measure E5's invariant is unsound for a piecewise-constant field**. It asserts a *continuum* property — a direction exiting `X` must enter `Y` — which fails when the direction is nearly parallel to the shared edge, because the field's own rotation across that edge flips the small perpendicular component. **Both faces then correctly compute "outflow".**
- **Independent reproduction.** From the committed `sphere_prescribed.obj` and `.rawfield` alone — no product code — the review reproduced **exactly 144 directed disagreements**, matching the runtime figure. Tangency ratio `min(|d_opp| / max|d|)`: **disagreeing median 0.0218, max 0.2004** (n=144); **agreeing median 0.9233** (n=1008). A 42× separation, with overlap at the bottom — a geometric regime, not a threshold.
- **Every published term at the live locus is CORRECT**, each independently verified: `matching = 0` is geometrically right (nearest target raw index at **23.7°**, next at **66.3°** — not an aliasing case); `matching + g_src − g_tgt = 0 + 1 − 3 ≡ 2` reproduces the published `signedLift = 2`; both gauges map their semantic branch to **raw index 0**; both published `dbary` triples reproduce **to 10 decimal places**; and all 288 interior edges are normal adjacency with none folded. **There is nothing in A1 to fix.**
- **Three prior readings withdrawn.** (1) The live locus does **not** indict `build_branch_transports` — the TB-R5 decision-table row it satisfied is withdrawn as a diagnosis. (2) There are **not two classes**: the unequal-gauge (86/43) and equal-gauge/lift-0 (254/127) populations are one near-tangency phenomenon — the "lowest common invariant" the TB report asked for. (3) **J3's 524/524 does not exclude H-B**: `independent_edge_measurement` (`tests/support/SkewSingularFieldWitness.h`) re-implements **principal matching**, the algorithm H-B suspects, so it is an implementation cross-check, not an aliasing test. H-B is excluded, but by direct measurement at the live locus.
- **Reviewer errors owned:** the TB-R4 "geometrically impossible" claim and its magnitude-versus-ratio reasoning (`|d| = 1.0035` is the **smallest** of `{4.00, 5.01, 1.00}` — tangency is a ratio); the J3 specification, which named principal matching as its own oracle; and the TB-R5 decision-table rows that attached owners to what is one geometric regime.
- **The real open question** is a tracing-model gap: **`DESIGN.md` §4.5 does not define what a trace does at an edge the neighbouring face's direction also exits.** Candidate models (tangential continuation, typed grazing terminus, refinement precondition, joint two-face continuation) are framed but **not chosen** — that is a `-DEFN` obligation and needs K2's cost measurement.
- **Disposition:** `M3-CP4c-0-CB7`, measures **K0–K7**, **diagnostic-only — no production change authorized**; then **`M3-CP4c-0-DEFN-2`** to close the §4.5 gap. **No tolerance may be introduced to classify grazing** (Amendment 9 clause 3).
- **Stable-count rationale:** accepted 316 green, CP4c-0 never accepted. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.


- **TB-R7 K1/K3 disposition:** authoritative `33019554121 / 98346293968` reproduces the near-tangency separation and independently finds **176/176 complete vertex fans / 0 holonomy mismatches**. J3 remains legitimate **524/524** as the explicitly limited principal-matching implementation cross-check. The corrected decision table therefore supports a tracing-model definition gap rather than a period/holonomy production defect.
- **TB-R7 K2 limitation:** the grazing continuation-cost proxy reports **0/24** traces reaching grazing, one traversed edge for every trace, no first-grazing step, and zero consecutive grazing crossings. Review prediction P3 is **not observed**. Because the proxy never reaches the later known G5 grazing locus, it supplies no cost comparison among the four frozen `DEFN-2` models and selects none. Classification: **diagnostic limitation / NON-STABLE; +0 events / +0 recurrences**.
- **Disposition after TB-R7:** exact next `M3-CP4c-0-DEFN-2`, definition only. No production patch, tangency tolerance, or CP4c-1/2/3 entry is authorized.

- **Adjudicated 2026-08-26** by `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md`. **The candidate is no longer a defect under investigation — it is a defined continuation.** `BranchTransportFlowDisagreement` is retired from production emission; a carrier that is an outflow carrier on both sides is a **grazing edge transit**, and the trace slides along it to the endpoint both faces drive the published parameter toward, then re-enters the existing T2/T3 vertex dispatch. At the live locus, edge `6-8` transits to **vertex 8, which is a singularity**, terminating by **T3 `SingularityTermination`**.
- **Independent re-derivation from the committed fixtures alone** (no product code): sphere **72** grazing configurations on **72 distinct** edges, torus **120** of 864 `(edge, branch)` pairs; grazing ratio median `0.021788` / max `0.200424` on the sphere and `0.074604` / `0.102869` on the torus, matching TB-R7's K1 figures to six decimal places. **Slide-direction ambiguity: 0 of 192** — zero sign disagreements and zero zero-rates on both witnesses. The eight sphere singularities are the corners of an inscribed cube with exactly **3** grazing edges each, and the grazing edges lie in narrow corridors along the field's separatrices.
- **Closure path:** the candidate is closable by CB8's **L2** census, which must reproduce those counts and confirm zero ambiguity. It remains ACTIVE / NON-STABLE until then. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R8-CAND-01 — prescribed-sphere traces do not terminate, and no product guard could see it — ACTIVE / PRODUCT SEMANTICS / GUARDED, NOT RESOLVED

- **Observed:** `M3-CP4c-0-TB-R8` INCOMPLETE / BLOCKED on run/job `33028238313 / 98374531360`, CB8 package `9628445643`. Ordinal 338 `ResolvedBranchCorrection.AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections` failed after **853.437 s** with an uncaught `C++ exception with description "gcd(): while running too long! "`. Ordinal 343 never returned before user cancellation. Accepted first-316 and first-328 remained green.
- **Root cause, three compounding defects.** (1) **Six of the prescribed sphere's separatrices circulate forever**, lapping a closed 32-state `(face, branch)` circuit and drifting in exact position every lap. CB8's grazing transit correctly retired `BranchTransportFlowDisagreement`, which had been aborting the network at the first grazing edge and *incidentally* stopping every trace before any could circulate. (2) **Neither guard could see it.** `FieldAlignedTraceTraversalState` contains the exact entry position, so a lapping trace never repeats a state; the step budget `8 x branchStates x (transports+1)` = **1,775,616** could never be reached. (3) Exact values grow **~1.12 base-1e9 limbs per step** without bound, and the fallback bignum answers by throwing: at ~step 205 (~233 limbs) Euclid passed its fixed 10,000-iteration cap.
- **Independent reproduction from the committed fixtures alone**, no product code: of 48 candidate ports (superset of production's 24), **42 terminate at a singularity** in <=32 steps at <=49 limbs, entering each `(face, branch, incoming carrier)` **exactly once**; **6 circulate** with 19 revisits by step 600 and growing. The populations separate completely.
- **Cost model:** `BigInteger::single_digit_division` binary-searches each quotient digit recomputing `dividend - divisor*mid` over the whole dividend per probe, so a division is `O(30n^2)`, a `gcd` is `O(n^3)`, and a trace's total cost scales near the **fourth power** of its final width. That is the 853 seconds.
- **Classification:** **product semantic defect** in A2a termination. Not fixture, not packaging, not orchestration, not a diagnostic false positive.
- **Corrective measures landed (`M3-CP4c-0-CB9`, N0-N7, compiled, nothing executed):** N1 position-free combinatorial recurrence guard (`TraceCombinatorialRecurrenceExceeded`, allowance **2** against a measured terminating maximum of **1**); N2 deterministic exact-magnitude policy (`BranchContinuationExactMagnitudeExceeded`, **4096 bits**, 2.8x the measured legitimate maximum); N3 the bignum's three fixed `10000` caps replaced by bounds derived from the algorithms' own worst cases; N4 step budget becomes a provable envelope of N1 (1,775,616 -> 9,216); N5 `FieldAlignedCurveNetwork::make` closed against any escaping exception; N6 four falsifying identities; N7 one identity moved to non-gating.
- **Simulated after the change:** 42/42 legitimate traces unchanged with the same terminal singularities; 6/6 runaways stopped at step 65; worst exact width **19,460 -> 2,684 bits**.
- **NOT RESOLVED, and TRANSFERRED to `M3-CP4c-0b`.** The guards bound the damage; they do not make the traces terminate. `M3-CP4c-0b-DEFN` (2026-08-27) resolved the ownership question by **splitting the checkpoint**: CP4c-0 keeps continuation and closes at gate 346 on Q8 criteria 1/4/5, while **CP4c-0b owns trace termination and Q8 criteria 2 and 3**, moved together and unweakened by Amendment 11. This candidate is resolved by CP4c-0b prediction 5 - **N1, N2 and N4 do not fire on any witness** - and not before.
- **Frozen mechanism.** Crash-on-contact terminates all six: measured, every circulating trace has a proper transversal crossing with another trace available at **its own step 0**, always against a **perpendicular** branch pair (`(0,1)`, `(0,3)`, `(1,2)`, `(2,3)`) and never against `(0,2)`/`(1,3)`, which are the same line traversed oppositely and cannot cross. Termination is therefore robust to arrival order; the priority metric decides which partition, never whether one exists.
- **Two candidate rules excluded by measurement.** *Self-contact*: 2,548 co-face segment pairs over 420 steps with **zero** crossings, zero touches, zero collinear overlaps - structural, because A1 publishes one constant direction per `(face, branch)` so repeat visits lay parallel segments, and the circuit is 32 distinct faces each on one branch. *Mesh-derived length budget*: the longest correctly terminating trace (5.0175) and one lap of a never-terminating trace (5.0175) are the same length to four decimal places, separation ratio **1.000**, so length carries no information about termination; a bounding box is also not rotation-invariant, arc length is not exactly comparable, and truncation leaves an arc that bounds no region.
- **N1's calibration risk stands.** Its allowance is measured on one witness (every terminating sphere trace enters each `(face, branch, incoming carrier)` exactly once). A mesh where a legitimate separatrix winds several times before reaching a singularity would trip it. N1 retires only when an identity proves no witness in the matrix reaches it, and the retirement is a plan update recording that evidence.
- **Withdrawn:** `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md` 9.2's cube-graph prediction, which predicted every sphere trace terminating at a singularity. 9.3's Q8-criterion-3 response is unaffected.
- **Stable-count rationale:** accepted **316/316** remains green and CP4c-0 has never been accepted. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-DEFN2-CAND-01 — the K2 grazing-cost census walks traces with the retired Cartesian carrier lookup — ACTIVE / NON-STABLE / TEST-SIDE

- **Observed:** TB-R7 measure K2 reported `tracesReachingGrazing = 0 / 24`, `traversedEdges = 1` for **every** trace, `firstGrazingStep = none`, and zero consecutive grazing crossings — while the production tracer's own G5 history reaches the grazing locus after **seven** steps. TB-R7 recorded this as a "diagnostic limitation" without a mechanism.
- **Mechanism, identified statically:** `cp4c_sphere_grazing_cost_census` (`tests/FieldAlignedCurveNetworkTests.cpp:4033-4133`) does not call the production continuation. Its per-step resolution at `:4067-4072` is `cp4c_distinct_outgoing_carriers(*pairing, *incomingCarrier)` with `if (outgoing.size() == 1U)`, then `break` — **the Cartesian carrier-set lookup that `M3-CP4c-0-DEFN` §5.1 deleted.** It carries no `FieldBoundaryPoint`, so on any `1x2` face it sees two outgoing carriers, resolves nothing, and stops. The prescribed sphere is **50% `1x2`** (Z1 census), so every trace dies at step 1.
- **Classification:** **test-side diagnostic defect.** No product impact; the production tracer is unaffected and resolves `1x2` faces correctly with the position datum.
- **Consequence, normative:** K2's null result carries **no information about any grazing model** — it measured the retired rule, not the regime. No model may be preferred or rejected on it, in this turn or a later one.
- **Owning measure:** **L8**. The census must call `resolve_field_branch_continuation(currentFace, *pairing, *currentEntryPoint)` and thread the returned `exitPoint` forward, exactly as `field_aligned_candidate_traces` does. Prediction after correction: every sphere trace traverses more than one edge, and the trace seeded at vertex `0` reaches edge `6-8` at step **7**, matching G5.
- **Durable lesson recorded:** a diagnostic that reimplements a retired rule measures the retired rule. A census must either call the production entry point or state in its published output which rule it implements.
- **Stable-count rationale:** accepted **316/316** remains green, CP4c-0 has never been accepted, and no product behaviour changed. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R6-CAND-01 — Python ZIP extraction lost executable mode before runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** control run `33006048971 / 98300014224` verified package/source/selector authority and statically built the 338 route, then the first attempted launch of `directional_surface_cell_producer_tests` failed with `PermissionError`. No Directional binary executed.
- **Root cause:** Python `zipfile.extractall` did not materialize the archived executable permission bits. This was control-materialization behavior, not package corruption and not a product failure.
- **Resolution:** retry `33006282429` changed only package extraction to ordinary `unzip`, which preserves archived modes. No `chmod`, binary repair, rebuild, relink, source mutation, or package mutation occurred; postflight is clean.
- **Stable-count rationale:** pre-runtime orchestration only, **+0 events / +0 recurrences**.

## M3-CP4c0-TB-R5-CAND-01 — hosted Actions outage and temporary self-hosted byte-normalization detour — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** GitHub-hosted Actions experienced delayed/failed triggers while TB-R5 control was being installed. Temporary self-hosted migration was explicitly owner-authorized. Runs `32993852779 / 98257876870` and `32994482392 / 98260020875` both stopped at immutable control-payload SHA verification; the test script and all Directional binaries were skipped. Hosted runners were restored before the semantic run.
- **Root cause:** self-hosted checkout line-ending normalization changed the three staged shell-part bytes relative to their frozen SHA-256 values. The attempted `.gitattributes` normalization did not alter the already-checked-out immutable bytes in the failing run. This is control transport/environment behavior, not product semantics.
- **Resolution:** switch workflows back to hosted Ubuntu; hosted run `32994846466` verified all frozen payload hashes, executed the complete immutable gate and postflight, and is the sole semantic authority.
- **Process note:** three artifact-metadata queries were made before this turn's mandatory policy reads during the initial interrupted orchestration phase. They caused no download, mutation, runtime, or evidence promotion. Record as an orchestration/process-order defect and do not repeat it.
- **Stable-count rationale:** no accepted product identity regressed and both self-hosted attempts executed no Directional runtime. **+0 events / +0 recurrences**.

## M3-CP4c0-TB-R4-CAND-02 — postflight summary references `first_red` instead of persisted `first_red_ordinal` — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** after all 341 planned semantic processes and post-runtime inventories, final reporting failed under `set -u` with `first_red: unbound variable`; persisted state was `first_red_ordinal=0`.
- **Evidence validity:** result artifact preserves gate/F3/G5/Q8 state, manifest-post, and pre/post inventories; all compare identical and manifest remains **27/27 PASS**.
- **Classification:** orchestration/reporting-control defect only; it altered no semantic command or authoritative bytes.
- **Disposition:** resolved for TB-R4 by preserved evidence; **no semantic rerun**. Successor control may use `first_red_ordinal` consistently.
- **Stable-count rationale:** control-plane only; **+0 events / +0 recurrences**.

## M3-CP4c0-TB-R3-CAND-03 — required supplemental falsifier asserts that the prescribed sphere fails — RESOLVED BY TB-R4 / NON-STABLE

- **Observed:** static + runtime finding of `M3-CP4c-0-TB-R3-REVIEW-PLAN`. The mandatory supplemental falsifier `ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus` contains `ASSERT_FALSE(networkBuild)` on the prescribed sphere and **passed** in run `32921851098`.
- **Two consequences.** (1) A passing `ASSERT_FALSE` is direct runtime proof that **the prescribed sphere still does not publish a `FieldAlignedCurveNetwork`**, so **Q8 is expected to fail on the next TB even at 338/338**. Neither the TB-R3 report nor its review brief surfaces this, and planning the successor as "fix the two reds and Q8 closes" would be wrong. (2) The assertion **encodes current production output as an expectation** and will invert — going red — at exactly the moment CP4c-0 succeeds, blocking acceptance for the wrong reason.
- **Classification:** diagnostic/oracle defect in the frozen measure series, not in the implementation. The F3 specification asked for a falsifier that "drives the tracing path to each reachable typed rejection"; CB3 reasonably implemented that against the sphere's live failure. The spec should have required the seed-provenance property to be proved on a **constructed** failure whose existence the test controls.
- **Related gap:** nothing in the frozen 338 gate or either supplemental publishes the sphere's *current* rejection code. It is known only by exclusion — not `BranchContinuationDegenerateEntry`, not `BranchContinuationOutsideOutflowSet` (identity 338), not `InvalidCandidateTraceBinding` (supplemental). This is the **third consecutive cycle** in which the sphere's decisive datum was computed at runtime and not published.
- **Disposition:** measures **G4** (de-encode the assertion; prove the property on a constructed failure, make any sphere branch conditional) and **G5** (add a non-gating identity that always publishes the sphere's A2a outcome and locus). G4 must land in CB4, before the sphere is fixed.
- **Stable-count rationale:** no accepted identity regressed; CP4c-0 has never been accepted. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.
- **TB-R4 resolution evidence:** F3 remains **2/2 PASS** after G4 moved the seed-provenance proof onto a constructed failure, while G5 independently publishes the live sphere outcome without asserting that the sphere must fail. The diagnostic/oracle defect is closed. The live sphere failure is tracked separately as `M3-CP4c0-TB-R4-CAND-01`.

## M3-CP4c0-TB-R3-CAND-01 — lossy-roundtrip falsifier builds a DCEL-invalid single-triangle mesh — RESOLVED BY TB-R4 / NON-STABLE

- **Observed:** ordinal 333, `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip`, throws `compute_edge_quantities(): DCEL consistency check failed` from the test body.
- **Static localization:** the test's candidate-search loop constructs a near-degenerate one-triangle `TriMesh` and calls `mesh.set_mesh(vertices, faces)` before computing the determinant/admissibility test that would reject a bad candidate. The first rejected candidate can therefore fail fixture/DCEL construction before `direction_in_vertex_sector` is reached.
- **Classification:** high-confidence **test fixture/search-harness candidate**, not current proof of a production semantic regression. The intended predicate may never execute.
- **Required adjudication:** independently verify the call ordering and freeze a deterministic capable lossy-roundtrip witness or admissible candidate construction that reaches the predicate without weakening its expectation. Do not treat arbitrary exception suppression as a fix.
- **Stable-count rationale:** CP4c-0 has never been accepted; accepted 316/316 remains green. **+0 events / +0 recurrences**; totals remain **42 / 14 / 28**, debt **5**.
- **Adjudicated 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §7 (retired TB-R3 review). Primary evidence: `C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body`, at **0 ms**. `TriMesh::set_mesh` → `compute_edge_quantities()` (`TriMesh.h:145-163`) calls `dcel.check_consistency(verbose, true, true, true)`, which throws. `checkPureBoundary` (`DCEL.h:1546-1565`) fails with *"face is composed entirely of boundary edges"* for any face with no interior edge.
- **Sharper than the original premise:** the near-degenerate coordinate family is a **red herring**. The fixture builds a **single-triangle** mesh, whose one face has all three halfedges on the boundary, so **every** candidate is DCEL-invalid regardless of `base`, `spacing`, or `epsilon` — confirmed by the 0 ms failure on the first candidate. The determinant screen runs *after* `set_mesh`, so it never gets the chance to reject anything.
- **Classification:** test fixture/harness defect. **Not production** — `direction_in_vertex_sector` was never reached, so this identity currently provides **no evidence either way** about the lossy-round-trip property it exists to falsify. That property remains unproven, not disproven. **Confidence: high.**
- **Disposition:** measure **G1** — DCEL-valid witness (≥ 2 triangles sharing an interior edge), screen the determinant **before** `set_mesh`, preserve the `EXPECT_FALSE` falsification, prefer deterministic construction over search. Do not catch the exception, weaken the expectation, or add a tolerance.
- **TB-R4 resolution evidence:** ordinal 333 is **PASS** with G1's DCEL-valid two-triangle witness and pre-construction determinant screen. The intended exact lossy-roundtrip predicate is reached and satisfied; no production change was required.

## M3-CP4c0-TB-R3-CAND-02 — fan-partition falsifier treats face-gauged branch labels as a global direction identity — RESOLVED BY TB-R4 / NON-STABLE

- **Observed:** ordinal 334, `ResolvedBranchCorrection.ExactVertexSectorPartitionsAcceptedInteriorFans`, reports admitted-face counts 0 for branch 0, 1 for branch 1, 0 for branch 2, and 3 for branch 3 instead of exactly one each.
- **Static localization:** `build_face_branch_frame` chooses a per-face canonical gauge from that face's canonical topology reference edge. A numeric `FieldBranch` label is interpreted relative to this face-local gauge. Reusing the same integer branch label in independently gauged frames is therefore not automatically one physical/world direction around the fan.
- **Classification:** high-confidence **test-oracle/authority candidate**. The prior review's hand oracle assumed one cross-face `+X` meaning without proving gauge equivalence.
- **Required adjudication:** decide whether the valid fan oracle transports branch authority between faces or compares each face frame's published physical/exact direction. Do not mutate product semantics unless independent source evidence establishes a product defect.
- **Stable-count rationale:** CP4c-0 remains unaccepted and accepted 316/316 is green. **+0 events / +0 recurrences**; totals remain **42 / 14 / 28**, debt **5**.
- **Adjudicated 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §7 (retired TB-R3 review). Primary evidence: three sub-failures at the fan-partition assertion — branch 0 admitted **0**, branch 2 admitted **0**, branch 3 admitted **3**; branch 1 admitted 1 and passed by coincidence.
- **Mechanism:** `build_face_branch_frame` (`FieldTransportAtlas.cpp:190-270`) assigns each face a **gauge** = the raw direction of `{primary, secondary, −primary, −secondary}` with the smallest positive oriented angle from that face's **canonical reference edge** (`v0→v1` of its canonical topology key), about a normal computed from the **canonical vertex order**. Semantic branch `s` denotes `raw[(gauge + s) mod 4]`. On the four-triangle fan the gauges are `0, 1, 2, 1` (the fourth face's canonical normal is anti-parallel to mesh orientation), which reproduces the observed `0, 1, 0, 3` **exactly**.
- **Classification:** oracle defect, **originating in this reviewer's E8 specification**, which said "for every `(vertex, branch)` fan, assert the exact predicate admits exactly one face" and thereby assumed a numeric branch names one physical direction across faces. It does not. **Not production. Confidence: high.**
- **Production is correct:** `build_branch_transports` (`FieldTransportAtlas.cpp:305-320`) already corrects every lift by `rawGauge[first] − rawGauge[second]`, and the trace loop, `resolve_field_vertex_transit`, and the singularity fan partition all rotate by that corrected `signedLift`. The gauge correction existing at all is source-level proof that branch labels are per-face.
- **Disposition:** measures **G2** (rebuild the oracle to walk the fan through the published `signedLift`), **G3** (independent local-holonomy check so G2 is not circular: composed lift `≡ 0 mod 4` at a regular vertex, `≡ index` at a singularity), **G6** (comment recording why the naive per-branch loop was wrong). **Amendment 7** freezes the rule. Do not special-case the fan and do not mutate production to satisfy an oracle.
- **TB-R4 resolution evidence:** ordinal 334 is **PASS** after G2 transports through published `signedLift`; G3 local-holonomy coverage is also green. The per-face-gauge oracle defect is closed without production mutation.

## M3-CP4c0-TB-R2-CAND-03 — trace-seed identity still back-filled into failure-locus fields — RESOLVED BY TB-R3 / NON-STABLE

- **Observed:** static finding of `M3-CP4c-0-TB-R2-REVIEW-PLAN`, not a runtime failure. Measure E1c named a single line (`SurfaceCellTracing.cpp:818-819`); CB honoured it exactly, and `annotate_field_aligned_trace_seed` is clean. Roughly **fifteen** other emission sites in the same file still write the trace seed into the `sourceVertex` locus via the legacy `field_aligned_error(code, port.sourceVertex, ...)` / `trace.sourceVertex` pattern: `:914`, `:926`, `:978`, `:986`, `:1000`, and `:690`, `:709`, `:1150`, `:1183`, `:1218`, `:1258`, `:1268`, `:1298`, `:1305`.
- **Scope precision:** sites whose failure genuinely *is* at the port (`InvalidCandidateTraceBinding`) publish a legitimate locus and are not defects. Sites with a downstream failure site — `InvalidCandidateTraceTransport` naming `decision.outgoingCarrier` in `currentFace`, and `InvalidNetworkTerminalOwnership` in `append_field_aligned_singularity_termination` — are back-fills and violate Amendment 5 rule 1 / Amendment 6 rule 4.
- **Classification:** **diagnostic-authority defect in the frozen measure series, not in the implementation.** E1c named an instance where it should have named a class; identity 330 is likewise an instance falsifier over one hand-constructed error, so it passes while the real sites keep back-filling. This is the same pattern that made TB-R1's `sourceVertex=0` misleading and cost a review turn.
- **Disposition:** **RESOLVED BY TB-R3.** CB3 F2 repaired the failure-site class and TB-R3 ordinal 330 passed; the supplemental `TracingPathNeverPublishesSeedIdentityAsFailureLocus` class falsifier also passed. The result is runtime re-proof of the correction, not a new stable event.
- **Stable-count rationale:** no runtime regression observed; CP4c-0 has never been accepted and the accepted 316 prefix is green. **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R2-CAND-01 — branch locus diagnostic serializes uint8 as control character — RESOLVED BY TB-R3 / NON-STABLE

- **Observed:** authoritative retry 1 passes identities 1–328, then ordinal 329 fails every expected numeric branch token in `NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`; emitted strings contain a raw control character after `branch=` / `relatedBranch=` instead of `1` / `3`.
- **Immediate source evidence:** `FieldBranch::value()` returns `std::uint8_t`; test/witness helper `append_network_error` inserts that value directly into `std::ostringstream`. The stream therefore selects character insertion. The typed `FieldAlignedCurveNetworkError.branch` / `relatedBranch` fields remain populated; serialization loses their decimal representation.
- **Classification:** high-confidence **test/diagnostic-observability candidate** affecting E1 runtime proof. It is not currently evidence of accepted production-authority loss because the accepted 316 prefix and the prior 328 prefix are green and the failure is in the witness serializer used by the correction test.
- **Adjudicated 2026-08-26** by `M3_CP4c_Consolidated_Record.md` §7 (retired TB-R2 review). **Scope: solely this defect, at exactly two call sites** (`tests/FieldAlignedCurveNetworkTests.cpp:2764`, `:2767`), established by exhaustive audit of every token identity 329 asserts against the emitter and the GMP exact-rational backend — `sourceFace`/`sourceEdge`/`publishedFaces`/`publishedEdges` use `index()` (`std::size_t`), `parameter`/`exactValues` use canonical `numerator/denominator` strings, and `traceSteps`/`traceStepBudget` are `std::optional<std::size_t>`. A repository-wide sweep confirms these are the **only** two stream insertions of a narrow-integer accessor; `GridAutomorphism::value()` is never streamed. **Confidence: high.**
- **Broader gap, also adjudicated:** DEFN §10 Amendment 5 required a property of the emitted *value* and never constrained the *mechanism*, so the one locus bypassing the `*_locus` formatter convention was unconstrained — while the correct idiom already existed at `FieldTransportAtlas.cpp:673`. **Amendment 6** now defines observability by mechanism and requires **class** falsifiers.
- **Unrecorded hazard now recorded:** `FieldBranch::from_integer(0)` emits **NUL**; `branch` precedes `parameter` in the emitter's field order; and `parameter` is the datum that discriminates the sphere's failure route. At any C-string boundary that NUL truncates exactly what E1 exists to publish. `std::string` is NUL-safe, which is the only reason identity 329 caught this rather than a log silently losing it.
- **Disposition:** **RESOLVED BY TB-R3.** CB3 introduced the named `branch_locus` formatter. TB-R3 ordinal 329 passed and the supplemental `NetworkDiagnosticsContainNoControlCharactersForAnyCode` class falsifier passed, re-proving decimal/lossless serialization across the diagnostic code class. Q8 remains unconsumed for unrelated gate reasons.
- **Stable-count rationale:** CP4c-0 has never been accepted and accepted 316 is green; **+0 events / +0 recurrences**, totals remain **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-R2-CAND-02 — runner helper returned bookkeeping predicate status after identity 1 — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** retry 0 `32914435964 / 98015089869` passed immutable preflight and identity 1, then stopped as `ORCHESTRATION_FAIL / incomplete-gate` with no semantic red and Q8 not run.
- **Root cause:** the temporary `run_identity` shell helper had no explicit successful return; for ordinals below 329 its final `[[ ordinal -ge 329 ]] && ...` expression returned false, which the caller interpreted as a gate stop.
- **Correction/evidence:** add only `return 0` after successful bookkeeping. Retry 1 reused the exact package, selector, fixtures, expectations, and semantic source and reached the deterministic ordinal-329 semantic red.
- **Stable-count rationale:** temporary orchestration only; **+0 events / +0 recurrences**.

## M3-CP4c0-TB-CAND-01 — prescribed sphere reaches typed zero-time continuation rejection before Q8 network — FIX IMPLEMENTED / NON-CREDITING 338 RE-PROOF GREEN / Q8 BLOCKED BY TB-R3 GATE RED / NON-STABLE

- **Observed:** authoritative retry 1 `32891161394 / 97943220460` passes **328/328**, but binding Q8 is red. A2a rejects `BranchContinuationDegenerateEntry` at singularity 0 / source vertex 0 / edge 6-8. No network; trace count, terminal `TraceIntersection`, and face `1-2-5` crossover unavailable.
- **Control:** accepted **316/316** and all 12 CP4c-0 identities pass; package/source/test/fixture/selector integrity unchanged; no configure/build/relink/repair.
- **Root-cause status:** **ADJUDICATED 2026-08-25** by `M3_CP4c_Consolidated_Record.md` §7 (retired TB review). **Class:** ill-formed upstream state — A1 decides the sign of a barycentric direction coordinate with a `double` tolerance in three places and publishes those verdicts as topological ownership (carrier-set membership, vertex-sector membership); A2a re-decides the same sign exactly on A1's own published datum. T6 correctly rejects a state A1 was incorrectly allowed to produce. The seam is **proved algebraically, not conjectured**: in `direction_in_incident_vertex_sector`, `alpha = d[next]` and `beta = d[prev]` identically, so `alpha > tol && beta >= -tol` *is* the exact entry predicate at `tol = 1e-10`. Confidence **high**.
- **Route still undetermined, deliberately:** three routes reach `t* = 0` (interior edge entry with cross-face flow disagreement; the same within-face at `|d| <= 1e-10`; vertex entry after a mis-selected sector transit). The discriminating datum — the exact entry parameter — was computed and dropped by the witness emitter. Measure **E1** decides it in one turn; measures **E2–E5** close all three regardless.
- **Note on the published locus:** `singularity=0` / `sourceVertex=0` are the trace **seed**, back-filled at `SurfaceCellTracing.cpp:818-819`, not the failure site. The failure is provably not the trace's first step. Only `sourceEdge=6-8` is a genuine locus.
- **Disposition:** CB2/CB3 implemented the correction series. TB-R3 identity 338 passes as a **non-crediting observation**, excluding the prior `BranchContinuationDegenerateEntry` / outside-outflow rejection pair on the accepted witnesses under package `9589508430`. Because ordinals 333/334 leave the frozen 338 gate red, Q8 is still unauthorized and unrun. This is partial diagnostic re-proof only; do not infer sphere-network publication or CP4c-0 closure.
- **Stable-count rationale:** CP4c-0 never accepted and no accepted 316 identity regressed; **+0 events / +0 recurrences**, totals **42 / 14 / 28**, debt **5**.

## M3-CP4c0-TB-CAND-02 — retry-0 artifact transfer failed before immutable validation — RESOLVED INFRASTRUCTURE / NON-STABLE

- **Observed:** run `32890863928` failed during artifact transfer before package verification and before any identity.
- **Correction/evidence:** single plan-authorized diagnosed infrastructure retry `32891161394` used unchanged package/selector/commands and completed the full gate plus Q8.
- **Stable-count rationale:** zero semantic identities in retry 0; **+0 events / +0 recurrences**.

## M3-CP4c-TB-R1-CAND-01 — production closed-surface witnesses expose accepted scope gaps — ACTIVE / NON-STABLE / DEFERRED TO CP4c-2/3

- **CP4c-1 evidence:** TB-R3 reproduces the prior torus/mechanical observations unchanged. Torus reaches A2a but publishes 0 traces / 0 events and A2b first rejects at `UncutFaceComponentOrbitSeedNotUnique`, `sourceFace=0-1-2`. Mechanical still fails A1 with `IncompleteCycleBasis` at source edge `0-3`; `fieldTransportAdjacencyExists=false` while `globalEF=1,158` and `localEF=1,158` are valid, with source boundary loops 0, genus 0, interior local vertices 152. The observed mechanical failure remains missing field-transport adjacency, not a negative `EF` row; the deeper adjacency-production cause is not yet adjudicated.
- **Control:** TB-R3 keeps the complete accepted prefix **316/316 PASS** with zero orchestration errors. Neither observation is accepted-behavior loss.
- **Disposition:** torus higher-genus region authority remains owned by blocked `M3-CP4c-2-DEFN`; mechanical closed-surface cycle-basis authority remains owned by blocked `M3-CP4c-3-DEFN`. Do not repair either inside the CP4c-1 review.
- **Stable count:** +0 events, +0 recurrences; totals **42 / 14 / 28**, debt **5**.

## M3-CP4c-TB-R1-CAND-02 — terminal TraceIntersection non-vacuity blocked by Cartesian A1 continuation authority — SUPERSEDED BY CP4c0-TB-CAND-01 / NON-STABLE

- **Observed:** C4/C5 remain red because the prescribed sphere reaches A1 and then A2a rejects `InvalidCandidateTraceTransport` at `singularity=0`, `sourceVertex=0`, `sourceEdge=1-2`; no network or terminal `TraceIntersection` is published. TB-R3 preserves the same required result **316/318** with the full accepted prefix **316/316 PASS**.
- **Z1 runtime proof:** published branch-pairing authority is ambiguous on accepted witnesses, not only the sphere: two-ring `30/60 = 50%`, four-triangle fan `4/16 = 25%`, torus `288/576 = 50%`, prescribed sphere `384/768 = 50%`. The sphere failing face `1-2-5` has incoming `1-2`, outgoing `1-5,2-5`, multiplicity `2`.
- **Z2 runtime proof:** the sphere failure site is exactly `field_aligned_outgoing_carrier` after **1 completed segment**, current face `1-2-5`, source edge `1-2`, with `fieldTransportAdjacencyExists=true`. The failure is therefore not next-face lookup or typed branch transport, and the start attachment/first transport path is viable.
- **Root cause status:** **PROVEN production A1→A2a contract gap.** `FieldBranchBoundaryPairing.connections` is a Cartesian inflow × outflow relation while A2a requires one continuation; the trace state lacks the within-face position datum needed to resolve a 1-in/2-out face. TB-R3 confirms the independent TB-R2 review's source diagnosis and falsifies witness-side repair as the smallest correction.
- **Disposition:** exact next `M3-CP4c-0-DEFN`, review/definition/planning only. Freeze one position/continuation authority and its accepted-prefix re-proof obligations before implementation. Do not resolve ambiguity inside A2a, invent identifier/order/magnitude tiebreaks, weaken C4/C5, or patch the sphere.
- **Stable count:** +0 events, +0 recurrences; CP4c-1 has never been accepted and no accepted 316 identity regressed. Totals **42 / 14 / 28**, debt **5**.
- **CP4c-0 re-proof:** CP4c-0 removes Cartesian `connections` authority and all 12 dedicated identities pass in TB `32891161394`. Sphere advances to a different first failure, `BranchContinuationDegenerateEntry` at edge `6-8`; active ownership moves to `M3-CP4c0-TB-CAND-01`.

## M3-CP4c-1-TB-R3-CAND-01 — tar/grep preflight pipefail aborted before runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first TB-R3 orchestration run `32871811711` stopped during immutable-package preflight before the runtime step and executed **0 identities**.
- **Root cause:** an early-exit `tar -tzf <archive> | grep -q <required-path>` pipeline ran under `set -o pipefail`. `grep -q` exited immediately after finding the required path, leaving `tar` to observe a broken pipe; the otherwise successful membership check therefore surfaced as a non-zero pipeline status.
- **Correction/evidence:** replace the SIGPIPE-sensitive early-exit membership check with a preflight form that consumes/records the archive listing without making upstream success depend on `grep -q` closing the pipe. Corrected authoritative run `32872112507 / 97881418987` then completed all **323** planned processes with zero orchestration errors and exact pre/post integrity.
- **Stable-count rationale:** pre-runtime control-plane defect only; no test identity executed in the invalid run and no semantic package changed. Adds **0 stable events / 0 recurrences**; totals remain **42 / 14 / 28**.

## M3 CP4 historical regression/candidate consolidation — CLOSED / ARCHIVED

- `M3-CP4ab-TB-R3` accepted the immutable cumulative gate **316/316** (`304/304` predecessor + `12/12` CP4ab), so `PR8-R042 / M3-CP4b-R001` is **RESOLVED STABLE**.
- All CP4a/CP4b/CP4ab non-stable process, orchestration, diagnostic-reporting, test-authority, and architecture candidates formerly expanded above are closed historical context. Their material facts, exact run/package/artifact identities, dispositions, and stable-count rationales are preserved in the 2026-08-24 M3 CP4 historical-document consolidation entry and the preceding turn entries in `CHANGELOG.md`.
- Historical candidate cleanup changes no stable accounting: **42 events / 14 categories / 28 recurrences**; produced-witness debt **5**; M3 packages **34**.
- No current M3 CP4 regression candidate remains active. CP4c starts from accepted 316 authority and exact next remains `M3-CP4c-CB`.

## M3-CP3b-TB-CAND-01 — remotely transported runtime draft was malformed YAML — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first schema-validation control `32513439436` rejected the remotely transported CP3b TB runtime draft before the acceptance workload could run. No generated Directional semantic runtime or acceptance artifact was produced.
- **Root cause:** control-plane transport did not preserve the intended workflow bytes, leaving malformed YAML; this is not package/source/test/fixture/selector authority.
- **Correction/evidence:** replace the corrupted draft with a compact byte-preserving workflow and require independent SchemaStore validation before publication. Final compact workflow blob `7a604bedc113b5b1c2f89038a18e22cd26c9b34e` passed schema run `32515108310` and authoritative acceptance run `32515222447` later completed **304/304 GREEN**.
- **Stable-count rationale:** pre-runtime orchestration only; acceptance attempt remained unconsumed until the valid 304 gate. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3b-TB-CAND-02 — large payload/repair transport failed byte identity — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** large runtime/repair-workflow payload transports did not reproduce the intended local bytes. Those controls were rejected before semantic runtime and were not accepted as workflow authority.
- **Root cause:** payload-size/transport integrity on temporary orchestration, not a CP3b product or test defect.
- **Correction/evidence:** author a smaller equivalent immutable-gate caller and transport it through Git blob creation; the resulting exact blob `7a604bedc113b5b1c2f89038a18e22cd26c9b34e` was reused unchanged for both validated payload and active runtime caller. Schema run `32515108310` and in-run validator `96875257718` passed before/with authoritative gate `32515222447 / 96875297990`.
- **Stable-count rationale:** all affected controls were pre-runtime/attempt-free. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3b-TB-CAND-03 — closeout changed-path guard omitted a newly added untracked report — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first acceptance-documentation closeout `32516236265 / 96878457696` successfully decoded and applied the frozen documentation patch, then stopped before commit because `git diff --name-only` does not report a newly added untracked acceptance report. The guard therefore saw only four of five intended paths.
- **Root cause:** closeout changed-path oracle used a tracked-diff-only command before staging a new file. Semantic acceptance evidence was already complete and no generated Directional runtime executed in closeout.
- **Correction/evidence:** make the new file visible to the changed-path oracle with `git add -N` before comparing the exact five-path set, while retaining the same frozen documentation content plus this orchestration record.
- **Stable-count rationale:** documentation/control-plane only, post-acceptance; adds **0 stable events / 0 recurrences** and does not alter the accepted 304/304 gate. Totals remain **41 / 14 / 27**.

## M3-CP3b-TB-CAND-04 — compressed closeout payload transport corrupted before patch application — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** corrected acceptance-documentation closeout `32518015056 / 96883932212` failed before `git apply` because the embedded base64/gzip patch transport was corrupted (`base64: invalid input`, gzip CRC and length errors). A first file-backed retry `32518441153 / 96885225368` reproduced the same truncation while decoding one large connector-created payload file. Neither produced a durable documentation commit or generated Directional runtime.
- **Root cause:** the large single-object text transport path was not byte-preserving across connector/workflow publication; the failure is administrative transport, not semantic acceptance.
- **Correction/evidence:** split the frozen compressed patch base64 into bounded deterministic chunks, concatenate them in lexical order, verify the concatenated base64 SHA-256 and decoded patch SHA-256, then apply the exact five-path patch. This removes the single-large-text transport assumption while preserving the locally verified documentation bytes.
- **Stable-count rationale:** post-acceptance documentation/control-plane only; adds **0 stable events / 0 recurrences** and does not alter the accepted 304/304 gate. Totals remain **41 / 14 / 27**.

## M3-CP3b-CB-CAND-01 — shrink-only vector resize required an unavailable default constructor — RESOLVED COMPILE-ONLY / NON-STABLE

- **Observed:** first two-target compile `32507150872 / 96849810459` on initial CP3b source `233b8e83be338e9a590c4aa5dfb220e9aa2119f2` failed while compiling `SurfaceCellTracing.cpp`: `std::vector<FieldAlignedCandidateTraceSegment>::resize(...)` instantiated a default-construction path, but `FieldAlignedCandidateTraceSegment` intentionally has no default constructor. No immutable package or generated Directional runtime was produced.
- **Root cause:** C++ container API misuse on a shrink-only operation, not an event-graph semantic defect.
- **Correction/evidence:** replace shrink-only `resize(contactIndex+1)` with iterator `erase(begin+contactIndex+1,end)` inside the already-authorized source file. Correction `32507540808 / 96851028033` produced source `611b3f8f3926792baee9d1078d6677d22006a6c4`; corrected-source precompile `32507660499 / 96851404185` and package `32508124000 / 96852846743` are green.
- **Stable-count rationale:** compile-time only; no accepted semantic behavior regressed and no generated runtime executed. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3b-CB-CAND-02 — broad compile-marker glob matched correction control — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** the first compile caller watched `m3-cp3b-cb-compile-*.txt`, which also matched the compile-correction marker. Run `32507540724` reached only its metadata resolver, failed there, and its compile job was **skipped**.
- **Root cause:** temporary workflow path-filter namespace overlap.
- **Correction/evidence:** narrow the compile caller to `m3-cp3b-cb-build-*.txt` and lock the corrected source. Authoritative precompile `32507660499` and package `32508124000` then ran through the corrected path.
- **Stable-count rationale:** orchestration-only with no generated Directional compile/runtime in the accidental run. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3a-TB-CAND-01 — workflow registration/activation produced no observed TB runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** an earlier validated TB caller installation/trigger control did not produce an observed `M3-CP3a-TB` runtime. No workload job, GTest result, or semantic artifact was accepted from that control.
- **Classification/root cause:** orchestration/control-plane only. The exact registration/activation cause was not promoted into product/test authority because no generated Directional runtime executed and the final caller/trigger path superseded it.
- **Correction/evidence:** corrected active caller commit `2bc3bf38f9ef24509b9296f6d7928e397007cecc` plus separate trigger `887b4ad191baf8b4bf9ad2877900d3c18d935df1` produced authoritative run `32485441510`.
- **Stable-count rationale:** no accepted behavior loss and no semantic execution; adds **0 stable events / 0 recurrences**. Totals remain **41 / 14 / 27**.

## M3-CP3a-TB-CAND-02 — caller permission ceiling rejected reusable observer write permission — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** an earlier TB caller granted `contents: read` while `agent-run-observer-reusable.yml` includes a `contents: write` job. The reusable-workflow permission ceiling was therefore invalid before acceptance runtime.
- **Root cause:** workflow permission mismatch only; no package/source/test/fixture/selector semantic defect.
- **Correction/evidence:** the caller was corrected to `contents: write`, exact corrected bytes were revalidated by schema run `32485281333`, and authoritative run `32485441510 / 96780835699` then completed **298/298 GREEN**. No generated Directional runtime occurred under the invalid caller.
- **Stable-count rationale:** pre-runtime orchestration only; adds **0 stable events / 0 recurrences**. Totals remain **41 / 14 / 27**.

## M3-CP3a-TB-CAND-03 — closeout stale-reference guard included temporary workflow control text — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** documentation closeout run/job `32493625886 / 96806875476` passed workflow schema validation but stopped before any durable documentation commit because its stale-reference census also scanned `.github/workflows/agent-m3-cp3a-tb-closeout.yml`. That temporary workflow intentionally listed the exact superseded per-turn filenames in its staged-path guard.
- **Root cause:** the retained-document stale-reference oracle used a repository-wide text scan without excluding temporary workflow/payload control surfaces that are themselves scheduled for workflow-first cleanup. This is a closeout-oracle scope defect, not product/test authority.
- **Correction/evidence:** retain the same byte-frozen documentation transform, but scope the stale-reference census to retained documentation/content and exclude `.github/workflows/` plus `.agents/Directional/turn-payloads/`; the exact transformed documentation diff remains hash-locked by the work-preservation artifact.
- **Stable-count rationale:** documentation/control-plane only; no generated Directional runtime and no acceptance evidence changed. Adds **0 stable events / 0 recurrences**. Totals remain **41 / 14 / 27**.

## M3-CP3a-TB-CAND-04 — closeout compressed payload corrupted in connector transport — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** closeout retry `32494245284 / 96808854595` passed schema validation but failed at `base64 -d ... | gzip -dc` with CRC/length errors before the documentation transform executed. No documentation commit was created.
- **Root cause:** control-plane payload transport corruption/truncation for the single large compressed transform blob; package/source/test/fixture/selector authority was untouched.
- **Correction/evidence:** transport the exact transform in independently bounded chunks, concatenate them only inside the closeout runner, and retain exact script SHA plus exact resulting documentation-diff SHA guards before commit.
- **Stable-count rationale:** pre-transform closeout orchestration only; no generated Directional runtime and no accepted behavior loss; adds **0 stable events / 0 recurrences**. Totals remain **41 / 14 / 27**.

## M3-CP3a-DG-CAND-01 — one-ring witness could not reach CP3a traversal seams — RESOLVED / TEST-AUTHORITY / NON-STABLE

- **Original evidence:** first DG `32445011345 / 96662902496` on old package `9432965083` was 2/6; three reds were upstream non-vacuity failures because every singularity attachment's first outgoing carrier was an outer-boundary barrier, so no multi-face crossing or populated `entryTransport` existed.
- **Root cause:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; the reused one-ring skew fan was topologically incapable of satisfying CP3a's required multi-face traversal witness.
- **Correction:** independent Review J1-J3 replaced the witness with a two-ring planar disc, derived matching/effort/index through `finalize_cross_field_result(...)`, and retained explicit `ASSERT_` non-vacuity for a multi-face trace with populated `entryTransport` plus a mandatory-barrier termination.
- **Resolution evidence:** final DG `32463985548 / 96716645034` on exact source/package `558a35c67919d54899c53de11dc9c69b6dfc9519 / 9435408599` executes the same six identities exactly once and passes **6/6**. The traversal, typed transport composition, ordering, binding rejection, and barrier-stop contracts all reach and pass on the corrected witness.
- **Stable-count rationale:** first-acceptance-only candidate; no accepted predecessor identity ran in either DG. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## M3-CP3a-DG-CAND-02 — network semantic digest mixed semantic identity with gauge-sensitive atlas provenance — RESOLVED / ARCHITECTURE-PRODUCT / NON-STABLE

- **Original evidence:** first DG reached equivalent branch relabeling and showed equal `branch_topology().semantic_digest()` plus equal candidate traces but unequal enclosing network semantic digests, isolating the representation-dependent full atlas hash inside semantic identity.
- **Root cause:** `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`; one digest was carrying two domains: gauge-invariant network semantics and representation-dependent atlas binding/provenance.
- **Correction:** independent Review J4-J5 makes semantic identity consume `branch_topology().semantic_digest()` while retaining the full atlas hash separately for binding/provenance and preserving foreign/tampered-atlas rejection.
- **Resolution evidence:** final DG `32463985548 / 96716645034` passes `CandidateTraceIsInvariantToEquivalentBranchRelabeling` and independently passes `CandidateTraceRejectsForeignPortOrAtlasBinding` in the same **6/6** exact gate, proving the semantic/provenance split did not delete the binding check.
- **Stable-count rationale:** first-acceptance-only candidate; accepted predecessor not executed. Adds **0 stable events / 0 recurrences**; totals remain **41 / 14 / 27**.

## PR8-R040 / M3-CP2b-R001 — singularity local ports inherit four-label representation identity — RESOLVED STABLE / RECURRENCE

- **Original loss:** corrected immutable `M3-CP2b-TB` `32317745051 / 96274463944` was **285/292**. Two identities accepted green in CP2 were red: `FieldAlignedCurveNetwork.PublishesTypedSingularityPortsAndMandatoryGraph` and `FieldAlignedCurveNetwork.RejectsInvalidSingularityPortOwnershipOrCount`; four new CP2b identities also failed at baseline atlas construction.
- **Primary category:** `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** attempt 1 derived semantic local-port identity from four branch-label starts and representation-level tuple deduplication rather than canonical fan/transport equivalence.
- **Correction:** R1 replaced that path with typed incident-fan incidences quotiented by reciprocal branch transport, requiring exactly `4-indexNumerator` semantic classes and topology-only representative/slot ordering.
- **Resolution evidence:** authoritative `M3-CP2b-TB-R1` `32324880480 / 96294021816` restores accepted CP2 **6/6**, including both formerly red network identities. `FieldTransportAtlas.PublishesCheckedSingularityPortAttachments` is green and proves the skew index-1 path now publishes exactly three checked local attachments with contiguous slots. The remaining CP2b reds have different first-acceptance causes recorded below.
- **Stable-count rationale:** this remains the same historical stable event/recurrence already counted at attempt 1. Resolution does not erase incidence. Historical totals remain **41 / 14 / 27**.

## PR8-R041 / M3-CP2b-R002 — dependent port validation masks accepted singularity diagnostic — RESOLVED STABLE / RECURRENCE

- **Original loss:** accepted CP1 A1 identity `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix` was red in corrected attempt-1 CP2b TB because a singularity tamper expected `SingularityMismatch` but dependent attachment validation returned `InvalidSingularityPortAttachment` first.
- **Primary category:** `RP-03 / POLICY_STAGE_STATE_CONFLATION`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** the expanded independent oracle validated dependent singularity-port attachments before reconstructing/validating the singularity facts on which those attachments depend.
- **Correction:** R1 validates raw/published singularity facts first and only then validates dependent branch-topology attachments; dedicated branch/attachment tamper checks remain strict.
- **Resolution evidence:** authoritative `M3-CP2b-TB-R1` restores accepted CP1 A1 **6/6**, including `IndependentOracleRejectsCompleteTypedTamperMatrix`, so the accepted `SingularityMismatch` diagnostic contract is restored.
- **Stable-count rationale:** same historical stable event/recurrence; resolution does not decrement totals. Historical totals remain **41 / 14 / 27**.

## M3-CP2b-TB-CAND-01 — first immutable caller materialized fixtures at wrong compiled source root — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** initial TB control `32317379701 / 96272468253` selected all 292 identities exactly once but additionally lost 26 M1 producer tests to fixture file-open/setup errors. The precompiled binaries embed the Code + Build workspace source root; the first caller extracted the embedded package source under runner temp instead.
- **Correction/evidence:** control-only retry used the same package and exact selector and materialized the exact embedded source at the compiled workspace path. Authoritative retry `32317745051 / 96274463944` restores M1 producer **138/138**. No package/source/test/fixture/selector semantic mutation occurred.
- **Stable-count rationale:** orchestration only, so **0 stable events / 0 recurrences**. The retry's final shell status-propagation step had an empty local exit-code read, but the runtime step returned failure and the complete result artifact unambiguously records the semantic 285/292 gate; no second runtime retry is needed.
- **Disposition:** RESOLVED NON-STABLE.

## M3-CP2b-TB-CAND-02 — new CP2b positives fail at baseline atlas construction — RESOLVED/SUPERSEDED SEMANTIC / NON-STABLE

- **Original observation:** four first-runtime CP2b identities failed because attempt-1 index-1 `FieldTransportAtlas::make(...)` rejected before their intended positive/oracle assertions.
- **Original root cause:** same singularity local-port representation-identity defect as stable `PR8-R040 / M3-CP2b-R001`.
- **R1 resolution boundary:** `PublishesCheckedSingularityPortAttachments` is green and baseline atlas construction now succeeds through the three-port seam. The remaining three R1 reds do not share the original four-label cardinality cause; they are split into the two candidates below.
- **Stable-count rationale:** first-acceptance CP2b contracts, so **0 stable events / 0 recurrences** independently.
- **Disposition:** RESOLVED/SUPERSEDED NON-STABLE.

## M3-CP2b-TB-R3-CAND-01 — local harness used Bash special `GROUPS` variable before runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** the first local TB-R3 control passed immutable package/selector preflight, then the harness array name `GROUPS` resolved to Bash's special group-ID array. The first run specification became `0`; the control attempted the package `bin/` directory, produced no GTest JSON, and stopped before any generated Directional binary executed.
- **Root cause:** local harness variable-name collision only; no package, source, test, fixture, selector, or expected-result semantic defect.
- **Correction/evidence:** rename the harness array to `RUN_GROUPS`; corrected harness SHA-256 `93d197608efce08001d4ecf76991bd70c45299a9a2d265434e4d0d38a8446131`. The same immutable package then produced the valid **292/292 selected, 288/292** gate with accepted predecessor **287/287** and byte-identical postflight.
- **Attempt/stable-count rationale:** the first control produced no valid semantic gate and executed no generated test binary, so it consumed **0 attempts** and adds **0 stable events / 0 recurrences**.
- **Disposition:** RESOLVED ORCHESTRATION / NON-STABLE.

## M3-CP2b-TB-R1-CAND-01 — equivalent Z4 relabel oracle conflates raw and canonical transport — RESOLVED / TEST-AUTHORITY / NON-STABLE

- **R1 observation:** `BranchTopologyIsInvariantToEquivalentZ4Relabeling` reached its non-vacuous relabel setup. Raw directions and matching changed; canonical frames and singularity-port attachments remained equal; canonical branch transport equality failed and semantic digest changed from `10784329413325343822` to `1098805676228837734`.
- **Primary category:** `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`.
- **R1 root cause:** CP2b R1 published an unnormalized raw/gauge integer lift even after reducing semantic transport to `QuarterTurn`; equivalent Z4 gauges could therefore differ by `4*k` in equality/hash representation.
- **R2 product change:** exact source `90c737e11c340061dd0167eaf59fec66afa0c8ba` preserves accepted CP1 raw adjacency lift semantics and changes only nested CP2b publication: topology-oriented lift is reduced to `QuarterTurn`, then `forwardLift` is the canonical `[0,3]` representative `static_cast<int>(forward.value())`.
- **TB-R2 disposition:** **UNADJUDICATED.** Immutable TB-R2 `32331037070 / 96311550091` failed inside the old helper before relabeled atlas/transport equality or semantic digest.
- **DG disposition:** **STILL UNADJUDICATED.** `M3-CP2b-DG` `32344594021 / 96350536107` again fails inside `make_skew_index_one_singularity_field(...)`, now at producer singularity-cardinality assertion line 1699, before the baseline atlas and relabel comparison. The R2 `[0,3]` product normalization therefore still has no runtime adjudication after the C1 fixture strategy.
- **DG-R4 disposition:** **STILL UNADJUDICATED.** Final diagnostic `32380986195 / 96463857157` clears the producer-derived helper for every CP2b identity, but `BranchTopologyIsInvariantToEquivalentZ4Relabeling` fails its valid-baseline `FieldTransportAtlas::make(...)` before the relabeled atlas, transport equality, or semantic digest seam. Part D therefore retains CAND-01 and authorizes diagnostics rather than a semantic fix.
- **TB-R3 disposition:** **STILL UNADJUDICATED.** Instrumented R5 runtime names the earlier baseline rejection as `DuplicateSingularityPortRepresentative` at edge `(0,1)`, face `0`, vertex `4`, region `0`. The relabeled atlas, branch-transport equality, and semantic-digest seam are still not reached, so the R2 `[0,3]` normalization remains neither accepted nor rejected by runtime.
- **TB-R4 evidence:** the valid R6 gate finally reaches the equivalent-Z4 relabel seam. Baseline and relabeled `FieldTransportAtlas::make(...)` both succeed. The sole failure is `tests/FieldTransportAtlasTests.cpp:2290`, where `independent_validate_snapshot(... relabeledField ..., independent_snapshot(relabeled.value()))` returns an error although the test expects validity. Because the assertion is non-fatal, execution continues: branch frames compare equal, branch transports compare equal, every `forwardLift` is canonical `[0,3]` and reciprocal, singularity-port attachments compare equal, semantic digests compare equal, and nonzero transport is present. The R2 production normalization is therefore runtime-exercised; the remaining contradiction is narrowed to the independent-validator relabel seam and requires static Review classification before any correction.
- **Part-G Review classification:** **TEST-AUTHORITY.** The identity simultaneously requires raw matching to change under gauge relabel, published branch transport to remain invariant, and raw matching to equal the canonical published lift. Those three requirements are contradictory. Product publication deliberately adds gauge, applies canonical topology orientation, and stores the unique `[0,3]` Z4 representative; all direct invariance assertions being green positively support that product contract. The independent validator's exact raw/canonical equality was the defect, not the product.
- **CB-R7 correction:** semantic edit `9316cc5a7c323ba6cf5235a9f89fc32be3cf96f0`, fixed compile/package source `1d2417c90970db81f8b49dd6e0961868cac32369`, immutable package `9428451548`. Exactly `tests/FieldTransportAtlasTests.cpp` changed semantically. The oracle derives its own face gauge from mesh/field authority, applies its own canonical orientation, reduces through Z4, and corrects all three related comparisons together. Existing tamper rejections remain statically pinned; H4 requires `forwardLift +1` rejection and accepts `+4` as an equivalent representative. Product source remained frozen.
- **TB-R5 resolution evidence:** immutable `32434684618 / 96633374819` executes the frozen 292-selector exactly once per identity and passes **292/292**: accepted predecessor **287/287**, CP2b **5/5**. `BranchTopologyIsInvariantToEquivalentZ4Relabeling` and `IndependentOracleRejectsBranchPairingOrPortAttachmentTamper` both pass; the non-degenerate 5-incidence/3-class partition remains unchanged; package and materialized source are byte-identical pre/post. Result/log `9430381177 / 9430381560` have SHA-256 `41292ffef7231ef7010bd416aa6b730fd6022694933bc0c4b538abadb64bf8be / a789a6567c865e119deef69c295894078ce2621f7972912666c726b1b6b886a4`. **Disposition: RESOLVED / TEST-AUTHORITY / NON-STABLE.**
- **Stable-count rationale:** no accepted predecessor regression and the defect was in first-acceptance independent test authority; adds **0 stable events / 0 recurrences**. Historical totals remain **41 / 14 / 27**.

## M3-CP2b-TB-R1-CAND-02 — duplicate singularity representative key omitted branch — RESOLVED / ARCHITECTURE-PRODUCT / NON-STABLE

- **R1 observation:** `PublishesCanonicalBranchFramesAndBoundaryPairings` reached publication assertions but independent baseline validation rejected; `IndependentOracleRejectsBranchPairingOrPortAttachmentTamper` failed baseline validity before either intended tamper seam.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **R1 root cause:** the helper manually injected nonzero transition matching/effort into otherwise identical coplanar face directions, contradicting independent geometric reconstruction.
- **R2 refinement:** non-degenerate directions were introduced, but the helper still assigned its nonzero closing seam using a hard-coded ordered face pair while verification used the signed cycle row. Mesh-owned `EF(edge,0) -> EF(edge,1)` orientation reversed that seam, so matching remained zero and the center index was not 1.
- **Mandatory-review C1 correction:** CB-R3 exact source `c608f77588a43c388bed81295d6cde0977b1c8cd` stopped hand-authoring matching/effort/index. Accepted `finalize_cross_field_result(..., false, true)` derives them from authored non-degenerate directions; the helper independently checks each published transition against mesh orientation and reconstructs the signed center cycle.
- **DG evidence:** attempt-free `32344594021 / 96350536107` executes all five CP2b identities exactly once on package `9395219896`. The helper reaches past every transition/matching assertion and past `orientedEffort ~= 2*pi` and `exactIndex ~= 1`, proving the R2 orientation failure is resolved. It then fails at line 1699 because `field.singularCycles.size()` is **5**, expected **1**. All five identities stop there before their intended semantic seams.
- **Refined root cause:** the open four-triangle disk witness conflates “center cycle has index +1” with “producer emits exactly one singular vertex entry.” `dual_cycles(...)` maps boundary vertices to the aggregate boundary cycle, and `effort_to_indices(CartesianField&)` publishes each local vertex whose mapped cycle index is nonzero. The accepted producer therefore exposes boundary-cycle singular entries as well as the center. This is a witness-domain/cardinality assumption, not another transition convention defect.
- **Architecture consequence:** `FieldTransportAtlas::make(...)` consumes every published singular entry as a `FieldSingularityFact`, while local port construction expects an ordered closed incident fan. Whether boundary singularities are valid CP2b inputs, require an architecture-owned filter/type, or make the open fan the wrong witness domain must be decided by rescope Review; deleting the size assertion is not authorized as a fixture-side filter.
- **Rescope Review / R4 correction:** Part C of `Architecture_M3_CP2b_Witness_Rescope_Review_Plan.md` reclassified the active cause as architecture/product: A1 already owns boundary-loop index as a typed `BoundaryLoop` witness but also admitted aliased boundary-vertex entries as separate singularity facts, and CP2b's attachment valence range diverged from accepted CP2. CB-R4 exact source `93f55536727dbf76504aa29f7835edc8cebaee0c` implements reconcile-before-drop E1, accepted-range E2, derived interior fixture assertion E3, and reconciliation negative E4. Compile/package evidence is green/runtime-free; runtime adjudication is pending the second DG on package `9404970614`.
- **DG-R4 evidence:** final attempt-free `32380986195 / 96463857157` executes all five CP2b identities once on package/source `9404970614 / 93f55536727dbf76504aa29f7835edc8cebaee0c`. Every identity clears the producer-derived helper, including the exact centre `+1` and exactly-one-interior-singularity checks. This runtime-discharges the remaining fixture-authority precondition. Four positive identities then fail only when the valid baseline calls `FieldTransportAtlas::make(...)`; the negative ambiguous/incomplete identity is reached-and-passing but is not credited while the valid baseline also fails.
- **Semantic Review refinement:** Part D reclassifies the live blocker as **architecture/product diagnosability plus an unnamed valid-baseline rejection**, not fixture authority. The positives discard `FieldAtlasBuildError`, while the compound branch-frame/singularity-attachment builders collapse many guards into opaque codes and discard existing locus fields. F1/F2 instrumentation is required before a semantic cause may be asserted. Part E corrects the implementation surface to include the public enum header required by F2; no guard logic change is authorized.
- **TB-R3 evidence:** valid immutable R5 gate is **288/292** with accepted predecessor **287/287**. All four positive identities report `DuplicateSingularityPortRepresentative; sourceEdge=(0,1); sourceFace=0; sourceVertex=4; topologyRegion=0`. Static ordering proves the class-count guard passed, one representative per class was elected, and the final cross-class uniqueness check found two representatives sharing the old `(startFace, firstOutgoingCarrier)` key.
- **Semantic Review result:** Historical TB-R3 Review Part F (recorded in `CHANGELOG.md`) reproduces the collision from frozen geometry. Face 0's 115.647-degree sector contains two 90-degree-spaced rays; those incidences share `startFace` and carrier and differ only in `branch`. The old key is structurally rank-one and production-relevant at ordinary valence-3 `+1` cones.
- **CB-R6 correction evidence:** exact source `9fdb928fe872190b27aa6022b43608eeccf329e4` preserves incidence generation and union-find equivalence, publishes every incidence/class/adjacency lift before later rejection, and widens representative identity/order to `(startFace, branch, firstOutgoingCarrier)`. G3 is discharged statically because the TB-R3 duplicate guard is cross-class by construction: it runs only after one representative per class is elected. Independent G4 coverage requires a legitimate pair sharing `(startFace, carrier)` while differing in branch and separately rejects an exact three-field duplicate. Mandatory pre-package and full package compiles are green; immutable package `9422702053` is runtime-free.
- **TB-R4 resolution evidence:** immutable `32418067075 / 96583693356` publishes the predicted centre partition exactly: five incidences, three classes, with face-0 branch `2` / carrier `(0,1)` in class `0` and face-0 branch `3` / the same carrier in class `1`. All five emitted partition blocks agree. `PublishesCheckedSingularityPortAttachments` passes its legitimate same-face/same-carrier/different-branch representative proof and its exact three-field duplicate rejection in the same package. The corrected key is therefore runtime-proven without changing incidence generation or union-find equivalence.
- **Disposition:** **RESOLVED / ARCHITECTURE-PRODUCT / NON-STABLE.** The runtime partition confirms the Review's Reading A and discharges the bounded R6 correction. This resolution does not imply CP2b acceptance because CAND-01 still leaves one frozen CP2b identity red.
- **Stable-count rationale:** all five affected identities are new CP2b first-acceptance contracts and DG intentionally did not execute the accepted 287-selector, so this adds **0 stable events / 0 recurrences**. Historical totals remain **41 / 14 / 27**.

## PR8-R039 / M3-CP2-R001 — closed authoritative rail cycle linearized as an open path — RESOLVED STABLE / RECURRENCE

- **Observed loss:** original immutable CP2 TB `32289400790 / 96186521474` was **270/287**. All six CP2 contracts and all six CP1 A1 contracts passed, but 17 retained M1 producer identities that were green in accepted CP1 failed at `surface-cells/NotProductionReady:field-aligned-network/InvalidRailGeometry`.
- **Primary category:** `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** CP2 applied the open-path contract `|V|=|E|+1` and endpoint `sourceVertices[i+1]` to canonical closed rails published as `closed=true`, `|V|=|E|`; the final closed interval is the wraparound edge.
- **Correction:** CP2-R1 exact source `5a284388d360efa4ce1bd37bc584165e1db0157b` preserves open-path cardinality, accepts canonical closed rails only at minimum three edges, uses modulo wraparound only for closed intervals, and strengthens the existing ordering identity with a real four-edge closed boundary plus exact mandatory-edge/kind cross-closure proof.
- **Resolution evidence:** immutable `M3-CP2-TB-R1` `32300950126 / 96223162140` consumed package `9382182983` directly and passed **287/287**: CP2 **6/6**, CP1 A1 **6/6**, retained M2 **275/275**, M1 producer **138/138**, `failedIdentities=[]`. Result/log `9383055423 / 9383056029` have outer SHA-256 `9f1be41dacb8041ebb49468c6df2c3b44d35c026796ec94cca5caf86cb7dbf46 / 34b30b4ad63873e7144d31b595c09ba2201788057671e260ac4d30829003c48f`.
- **F2 closed-rail cross-closure:** the strengthened positive identity explicitly proves no foreign mandatory edge, complete mandatory-edge coverage, and exact mandatory kind agreement. Runtime failing-diagnostic counts are `ForeignMandatoryEdge=0`, `MissingMandatoryEdge=0`, `MandatoryKindMismatch=0`, as expected for the green positive witness; those zero counts are not a substitute for the explicit assertions.
- **Immutability:** package and materialized source were byte-identical after runtime; repository checkout, rebuild, relink, repair, source/test/fixture mutation, generated discovery, benchmark execution, package mutation, and materialized-source mutation were all false.
- **Disposition:** **RESOLVED.** CP2-R1 attempt **1 of 3** succeeded; no retry or mandatory review is required. Resolution does not erase historical incidence, so totals remain **39 events / 14 categories / 25 recurrences** and produced-witness debt remains **5**.

## PR8-R038 / M3-CP1-R001 — explicit sparse-zero cycle support polluted curvature authority — RESOLVED STABLE / RECURRENCE

- **Observed loss:** package 4 immutable TB was **256/281**, package 5 R1 improved to **258/281**, and package 6 R2 remained **258/281**. R2 retained accepted M2 was **255/275**, with all 20 remaining predecessor losses in M1 producer (**118/138**) behind `InvalidFieldTransportAtlas:field-transport-atlas/CycleTransportMismatch` or dependent early-rejection effects.
- **Primary category:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Resolved root cause:** `dual_cycles` aggregates signed integer-incidence cycle rows through sparse multiplication. Opposite `-1/+1` incidence can cancel algebraically to exact `0.0` while Eigen retains the zero as a stored sparse entry. `FieldTransportAtlas` already ignored that representation-only zero when composing semantic cycle transport, but `MeshTopology.cpp` iterated the stored zero while building `cornerSets` / `vertexSets`; because `0.0 < 0` is false, it took the positive-sign branch and polluted `cycleCurvature`. Atlas therefore derived `turningLift` from a different effective support than the typed transport comparison.
- **Correction:** R5 exact source `9f7e222bab6c930a12d1369fa2aee869f5c0dcff` canonicalizes only exact algebraic-zero entries from the final cycle basis immediately after aggregation/slicing and before curvature iteration. It uses exact `value != 0.0`, not a tolerance, so no nonzero cycle coefficient is erased. The existing square A1 witness was strengthened to independently prove zero semantic interior support, identity composed transport, exact corrected boundary lift `4`, and oracle agreement. The A1 congruence and hard production gate remain intact.
- **Resolution evidence:** immutable `M3-CP1-TB-R3` `32263614534 / 96102598799` consumes `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` and passes **281/281** with A1 **6/6**, retained M2 **275/275**, and retained M1 producer **138/138**. `failedIdentities=[]`. Package and materialized source postflight are byte-identical; no rebuild, relink, repair, source/test/fixture mutation, generated discovery, or benchmark execution occurred.
- **Disposition:** RESOLVED. CP1 is accepted on package 7. The accepted runtime proves the shared sparse-support correction restores every retained predecessor identity lost under this regression while satisfying all six A1 contracts.
- **Stable-count rationale:** this remains the same historical accepted-behavior loss and recurrence already counted as `PR8-R038`; resolution does not add, remove, or decrement historical incidence. Totals remain **38 events / 14 categories / 24 recurrences**; produced-witness debt remains **5**.

## M3-CP1-TB-CAND-01 — new A1 positives/oracles failed at baseline atlas construction — RESOLVED SEMANTIC / NON-STABLE

- **Original observation:** package-6 R2 A1 was **3/6**. `FieldTransportAtlas.PublishesReciprocalTypedAuthorityAndRelativeBoundaryWitness`, `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix`, and `FieldTransportAtlas.IndependentTreeCotreeOracleSurvivesRowAndBranchRelabeling` failed because baseline atlas construction rejected before their intended positive/oracle proof.
- **Root cause:** the same explicit sparse-zero support contamination recorded by `PR8-R038 / M3-CP1-R001`; these first-runtime A1 contracts exposed the producer defect directly.
- **Resolution evidence:** immutable TB-R3 `32263614534 / 96102598799` selects all six frozen A1 identities exactly once and passes **6/6**. The three formerly red positives/oracles now reach and satisfy their intended contracts; combined gate is **281/281**.
- **Stable-count rationale:** these were new M3 acceptance contracts with no accepted-green CP1 predecessor, so they remain non-stable evidence and add **0** stable events / **0** recurrences. Historical totals remain **38 / 14 / 24**.
- **Disposition:** RESOLVED NON-STABLE. No A1 candidate remains open from CP1.

## PR8-R037 / M2-CP4-R001 — declared-product invalid-patch guard collapses canonical rebuild sub-invariant diagnostics — RESOLVED STABLE / RECURRENCE

- **Original observation:** `M2-CP4-TB-R1` `32175491853 / 95836337325` on `8cd82a63f00bd53aee3c7e01f4bef0c258b21ef3 / 9336162929` was frozen M1 **233/234** because `SurfaceCellAuthorityContractCutover.AggregateIdentityRebuildReportsInvalidPatchMetadataSubInvariant` retained stage/reason but lost `surfaceCellFirstInvalidProducerCell`, while static M2 remained **K=0**.
- **Root cause:** CP4 correctly moved the invalid-completed-patch guard from the diagnostic context shadow to declared `componentProducts.completedPatches`, but the earlier guard discarded which patch failed and returned before the later canonical rebuild could publish the failing patch index.
- **Correction:** user-authorized CP4-R1 source `9fda64e88ddc885ce993ff8da3ad6a51765724a4` uses the declared product to locate the offending completed patch and publishes its index at the same `AggregateIdentityInvalidPatchMetadata` rejection. It restores no semantic `surfaceCellContext` read and introduces no second authority.
- **Resolution evidence:** immutable `M2-CP4-TB-R2` `32183306224 / 95861164621` consumes package `9340456431`; the exact formerly red identity passes inside M1 producer **138/138**, frozen M1 is **234/234**, total required-green is **275/275**, and regenerated M2 static closure is **K=0** with direct semantic context refs **0** and CP3 forbidden reads **0**.
- **Stable-count rationale:** the event remains a historical stable recurrence of `RP-03 / POLICY_STAGE_STATE_CONFLATION`; resolution does not erase or decrement historical incidence. Totals remain **37 events / 14 categories / 23 recurrences**. Produced-witness debt remains **5**.

## M2-CP4-TB-CAND-01 — rail closed-product witness fails source-mesh setup before typed rejection seam — RESOLVED TEST-AUTHORITY / FIXTURE-PRECONDITION / NON-STABLE

- **Original observation:** the CP4-R1 predecessor witness used a one-triangle `TriMesh::set_mesh` substrate and threw a DCEL consistency failure before `build_authoritative_surface_cell_rails(...)`, so CP4 was **1/2** and the intended typed rejection was non-evidence.
- **Correction:** CP4-R1 reuses the already established rectangular internal hard-feature grid substrate, retains `edge.incidentFaces = {-1}` as the only counterfactual, and keeps the strict typed `Rejected<SurfaceCellRailBuildFailure>` / `InvalidFeatureEdge` / failed-edge evidence assertions.
- **Resolution evidence:** `M2-CP4-TB-R2` selects `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` exactly once and it passes; the CP4 pair is **2/2**. The witness therefore reaches the intended seam and proves the closed rejection contract without a consumable rail product.
- **Stable-count rationale:** this was a new acceptance-fixture precondition gap with no accepted-green predecessor, not lost product behavior. Resolution adds **0** stable events and **0** recurrences. Historical totals remain **37 / 14 / 23**.

## M2-CP4-TB-CAND-02 — initial TB harness assigns CP1/CP2 selectors to wrong owner executable — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first immutable CP4 control `32175260213 / 95835604030` verifies exact package and M1 artifact digests, recursive manifest, source identity/status, selector digests, and static M2 closure, then executes the CP4 pair and reproduces the rail-witness setup failure. It subsequently stops because the temporary harness invokes the accepted CP1/CP2 selectors through `directional_surface_cell_producer_tests`, yielding zero CP1 selection; accepted CP3 TB authority shows those selectors are owned by `directional_surface_cell_completion_tests`.
- **Correction/evidence:** retry harness changes only that owner mapping. `M2-CP4-TB-R1` `32175491853 / 95836337325` verifies both frozen payload blobs, re-verifies the immutable package, executes the complete 275-name gate, and exposes the two real red identities. Initial result/log `9338766391 / 9338767015`; authoritative retry result/log `9338923657 / 9338924194`.
- **Stable-count rationale:** test-control orchestration only; no package/source/test/fixture/selector semantic mutation and no accepted behavior loss. New stable events **0**, recurrences **0**. Totals remain **37 / 14 / 23**.

## M2-CP3-TB-CAND-01 — counterfactual aggregation seam stayed bound to legacy context shadow after declared-product read cutover — RESOLVED TEST-AUTHORITY / MIGRATION-SEAM / NON-STABLE

- **Observed:** immutable CP3 gate `32139341913 / 95718023464` consumes exact `dc837f7ac529c55aa7ba4775621e3b681f74d36b / 9322254546` and passes package/source immutability plus CP3 static read elimination, CP1 **5/5**, CP2 **34/34**, M1 authority **19/19**, completion **36/36**, and validation **41/41**. M1 producer is **135/138**, so combined required-green is **270/273**. Result/log `9325322211 / 9325322646` have SHA-256 `db12e52c5b6236c9db1e823ef93988d94b0cd0fae13b9bd961231795a6caa9bd / 2e78d926ffc24d4881064428db4d1ad7175aeff7ce30347575d404fcb77360b7`. The exact reds are `SurfaceCellAuthorityContractCutover.DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches`, `SurfaceCellAuthorityContractCutover.AggregateIdentityRebuildReportsInvalidPatchMetadataSubInvariant`, and `SurfaceCellAuthorityContractCutover.FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing`.
- **Accepted-baseline differential:** no new predecessor run is needed to establish loss: these exact identities are members of frozen M1 and passed in accepted CP2 final gate `32119584283 / 95656737849`, whose combined required-green is **273/273**. CP3 `include/**` and `tests/**` are byte-identical to accepted CP2 and only `src/pipeline/RemeshPipeline.cpp` changed in the bounded production source delta.
- **Root cause:** CP3 correctly captures aggregation semantics into `ComponentRun::stageProducts` and later binds `componentProducts = runs[index].stageProducts`, but the existing `ComponentAggregationInputMutator` API still exposes only `RemeshResult &` and executes after sidecar capture. The frozen counterfactual callbacks therefore mutate legacy `surfaceCellContext` shadows while the production aggregate consumes untouched declared stage products. The stale-cache fixture creates a mixed lineage/shadow counterfactual; invalid patch metadata reaches only the retained shallow shadow guard rather than the canonical product rebuild; clearing the context validation flag cannot change `componentProducts.validationResult` completeness.
- **Correction / Code + Build evidence:** the user explicitly authorized one bounded R1 package. Exact source `0a06127555405abef474af501e2bd09de3320c1b` changes the counterfactual signature to receive `SurfaceCellComponentStageProducts &` directly, passes `runs[index].stageProducts` at the hook, migrates all 11 callbacks, and points exactly the three rejected frozen mutations at declared stage-product authority. No context-to-product reconstruction or assertion weakening was introduced. Runtime-free `32147101079 / 95743427238` completed **117/117** and packaged `9328335558` / `8f75d835e4461ba1dabda91793a88f265e9c00de752a17ec8906943f70f9ced2`; log `9328336222` / `687d395877d92f940cd4f1dd477846ffcc5b6a1f31d39c2546044ea32140a04b`. This structurally remediates the injection seam but does **not** resolve the candidate until immutable TB-R1 restores the accepted gate and proves the intended mutations are non-vacuous.
- **Resolution / TB-R1 evidence:** immutable `32150796184 / 95755876548` consumes exact `0a06127555405abef474af501e2bd09de3320c1b / 9328335558`. The three formerly red identities pass an explicit **3/3** focused run and pass again inside frozen M1 producer **138/138**; frozen M1 is **234/234**, CP1 **5/5**, CP2 **34/34**, combined **273/273**. CP3 static read elimination remains `forbiddenRemaining=0` with 31 remaining refs classified diagnostic/memory or explicit shadow guards. No rebuild, relink, repair, source/test/fixture mutation, generated discovery, or benchmark occurred. The migration-seam candidate is therefore resolved without restoring context-to-product backflow or weakening tests.
- **Stable-count rationale:** the rejected CP3 behavior was isolated to the counterfactual/test-authority seam and is now restored by migrating that seam to declared stage-product authority. TB-R1 observes no product regression. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**, produced-witness debt **5**.

## M2-CP2-TB-CAND-02 — broad changed-block coverage mechanically promoted 12 inherited reds — RESOLVED TEST-AUTHORITY / INHERITED-RED PROMOTION / NON-STABLE

- **Observed:** valid CP2 control `32118066037 / 95651990590` preserved frozen M1 **234/234** and CP1 **5/5**, while a mechanically assembled 46-test changed-block candidate set was **34/46**. Exact accepted-predecessor differential `32118624560` consumed accepted CP1 package `9309981828` and reproduced the same 12 identities as **12/12 red with the same failure modes**. Final authoritative run `32119584283 / 95656737849` re-proved that differential, then executed the corrected CP2 required selector at **34/34**.
- **Exact inherited-red identities:** `FlowRepStrandsPhase15.EndpointCompletionExtendsToRetainedSameSheetNetwork`; `FlowRepStrandsPhase15.EndpointCompletionIgnoresSubToleranceIntersectionAtTraceOrigin`; `FlowRepStrandsPhase15.EndpointCompletionOnlyCommitsArrangementReproducibleIntersections`; `FlowRepStrandsPhase15.SubToleranceIntrinsicCaptureReconcilesOpenEndpointWithoutTinyArc`; `FlowRepStrandsPhase15.AdjacentFaceFanCanonicalizesSubToleranceEndpointsToSourceVertex`; `FlowRepStrandsPhase15.OpenHardFeatureEndpointsExtendWithoutRemovingAuthoritativeRail`; `PatchDescriptorMilestoneE.GlobalDescriptorAssignmentRejectsAmbiguousInteriorSingularity`; `PatchDescriptorMilestoneE.ComplexCompletionFailsClosedInsteadOfReturningPartialOutput`; `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`; `PatchDescriptorMilestoneE.SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion`; `PatchDescriptorMilestoneE.ZeroStructuralBudgetFailsBeforeCandidateExpansion`; `PatchDescriptorMilestoneE.StructuralRepairLedgerIsPatchOrderInvariant`.
- **Root cause / correction:** source-block proximity was incorrectly treated as sufficient authority to promote every touched-block identity into required-green acceptance. The architecture plan had not frozen a 46-test selector. The corrected required selector contains the 34 non-overlapping, non-inherited-red CP2 identities at SHA-256 `53f5bf57a2edb1c68260186b85964022cd034a899a51bcbf740a37d1c4815c0d`; the 12 inherited reds remain visible/non-gating. No assertion, test, or fixture was weakened or mutated.
- **Stable-count rationale:** every red identity was already red on the accepted CP1 predecessor, so no accepted-green behavior was lost. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**; produced-witness debt remains **5**.

## M2-CP2-TB-CAND-01 — immutable package source not materialized at compiled fixture path — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first CP2 TB control `32117669340 / 95650752285` verified immutable package integrity but produced 26 false M1 producer reds because fixture-relative paths compiled against `/home/runner/work/Directional/Directional` had no materialized package source tree. A later final-control variant reproduced the same orchestration class when source was extracted to a different runner-temp directory.
- **Root cause / correction:** artifact-only runtime still requires the immutable source archive at the absolute fixture path embedded in the compiled tests. Corrected controls materialize the exact package source archive at that path without checkout or source mutation. Valid run `32118066037` restored frozen M1 to **234/234**, and final run `32119584283` confirms **273/273** required-green.
- **Stable-count rationale:** control-plane/runtime-environment only; no product/test/fixture/package semantic mutation and no accepted behavior loss. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-R2-CAND-02 — working-branch push trigger remains unobservable; default-branch issue-comment control succeeds — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** the temporary working-branch TB-R2 push caller and its text marker were installed in separate commits, but no observer comment or Actions run became observable in the bounded window. The control was removed workflow-first before any generated Directional runtime. A genuinely different narrow default-branch `issue_comment` caller, triggered by PR comment `5322834507`, immediately reported observable run `32092820628` through comment `5322835378` and executed the immutable TB harness.
- **Root cause / correction:** available evidence still does not justify a more specific GitHub-side root cause for the earlier push-event observation failure. The TB-R2 correction was a bounded default-branch control. The current standard working-branch push-marker + reusable PR observer path was then directly successful in TB-R3: observer comment reported run `32101777174` at exact trigger SHA before workload completion, so no procedural-blocker bypass is presently required.
- **Stable-count rationale:** orchestration/control plane only. The failed push control produced no semantic evidence and lost no accepted behavior. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-R2-CAND-01 — shared-edge witness reaches completion but omits completion-level source authority — RESOLVED TEST-AUTHORITY / STRUCTURALLY INCOMPLETE FIXTURE / NON-STABLE

- **Observed:** immutable TB-R2 `32092820628 / 95578263202` preserves frozen M1 at **234/234 PASS** and advances the repaired `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` through incidence, canonical ownership, and produced parity repair. It then fails only at `complete_surface_cell_complex` with `CompletionOwnershipComponentSheetMismatch`; diagnostic support is source vertex 0 with candidate faces `{0,1}`, patch faces `{0}`, and `component=-1;sheet=-1`. CP1 is therefore **4/5**.
- **Root cause:** R2 repaired arrangement-local typed source scope and `sourceOwnershipRegistry`, but the witness still invokes `complete_surface_cell_complex(complex, V, F)` with default options. `SurfaceCellComplexCompletionOptions::sourceAuthority` therefore remains null; the pass forwards that null authority into pure-quad completion, and `completion_ownership_face_matches_authority()` deliberately rejects every candidate face when source authority is absent. The arrangement registry cannot stand in for the independent `SourceTopologyRegions` component/sheet authority required by completion.
- **Correction:** planning amendment authorizes one final fixture-only `M2-CP1-CB-R3`: independently construct canonical `SourceTopologyRegions` from the exact two-face `F` with components `{0,0}` / sheets `{0,0}`, pass it via `SurfaceCellComplexCompletionOptions::sourceAuthority`, and preserve every existing R2 precondition and strict assertion. No production accommodation is authorized.
- **Resolution/evidence:** R3 source/package `65183336d092d8fe165b6ed4709c4759a0b7fe33 / 9309981828` supplies independent canonical completion source authority without production semantic change. Immutable TB-R3 `32101777174 / 95603538759` executes the formerly red identity successfully and closes CP1 at frozen M1 **234/234** + CP1 **5/5**. Result/log `9311843660 / 9311843967`; no new regression observed.
- **Stable-count rationale:** the identity was already outside accepted M1 and baseline-red before R2; TB-R2 exposes a later fixture-authority omission only after the earlier omission was corrected. No accepted-green product behavior was lost. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.


## M2-CP1-TB-R1-CAND-03 — baseline-red shared-edge fixture promoted into CP1 acceptance — TEST-AUTHORITY / STRUCTURALLY INVALID FIXTURE / NON-STABLE

- **Observed:** authoritative TB-R1 `32075576934 / 95527922027` sees `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` return non-produced. Accepted-M1 differential `32076060405 / 95529428239` consumes package `9293593175` and reproduces the same identity as red with diagnostic `MissingCellSourceScope`; the control test `FiveSidedRepairUsesBoundedClosedFormInsteadOfCompositionSearch` is green. Baseline result/log `9303454816 / 9303455184`.
- **Root cause:** CP1 acceptance mechanically promoted an existing baseline-red identity that was outside the frozen M1 234-selector. Its manually constructed exterior cell is configured without typed `sourceTopologyRegion`/`sourceCharts`, while subdivision preflight requires every participating cell to carry typed source scope.
- **Correction:** `M2-CP1-CB-R2` must correct the fixture structurally by establishing canonical typed source scope and ownership before the repair action, with an explicit proving precondition and unchanged strict produced/conforming assertions. No production accommodation is authorized.
- **Stable-count rationale:** accepted M1 already fails this identity; no accepted-green behavior was lost. This matches the known non-stable test-authority pattern of promoting inherited-red evidence, but does not create a stable recurrence. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-R1-CAND-02 — side-fallback witness lacks canonical ownership and aborts before target action — STRUCTURALLY INVALID FIXTURE / NON-STABLE

- **Observed:** TB-R1 `32075576934 / 95527922027` fails `SideRepairFallbackPreparationIsProducedBeforeGeneralCompletion` at its explicit domain precondition with `ownership-registry-mismatch`; execution never reaches `repair_surface_cell_side_subdivisions`.
- **Root cause:** `make_authoritative_patch(...)` establishes a paired incidence topology but does not bind its projection charts to the actual source `F` or materialize `sourceOwnershipRegistry`. The witness therefore does not create the domain-authority precondition its claimed fallback assertion requires.
- **Correction:** `M2-CP1-CB-R2` must bind canonical source charts, canonicalize ownership, independently prove the ownership/domain precondition, and only then exercise side repair while preserving every strict produced-kind/reason/rollback/hash assertion.
- **Stable-count rationale:** the claimed semantic action was never reached, so this is non-evidence rather than a product regression. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-R1-CAND-01 — Python artifact extraction drops stored executable mode before runtime — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** first TB-R1 control `32075402079 / 95527384483` verifies the control boundary and artifact download, then stops before generated Directional runtime because Python `zipfile.extractall()` materializes packaged owner binaries without executable permission. Persistent log `9303225818 / fed460956bb666c8d1853e18766c4daa2fafd79d4b5aaf89b36f2c19fc3b6f5c`.
- **Root cause/correction:** the ZIP entries already store executable mode; the harness extraction mechanism failed to preserve it. Retry uses safe member-path validation followed by ordinary `unzip`, which faithfully restores stored archive metadata without mutating/repairing the package, and reaches runtime in `32075576934`.
- **Stable-count rationale:** pre-runtime orchestration only; no product/test/fixture/package semantic mutation and no accepted behavior loss. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.


## M2-CP1-TB-CAND-02 — closeout workflow invalid before job creation — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** documentation-only closeout control `32072822263` registered but produced zero jobs because multiline inline transform payload text broke YAML block indentation.
- **Root cause/correction:** executable transform text was embedded directly inside a YAML `run: |` body without preserving block indentation. Corrected closeout run `32073276034` uses a bounded, validated transform path.
- **Stable-count rationale:** no job, generated runtime, semantic evidence, source/test/fixture mutation, stable event, or recurrence. At that checkpoint totals remained **36 / 14 / 22**.

## M2-CP1-TB-CAND-01 — CP1 package omits frozen M1 authority-kernel owner executable — RESOLVED PACKAGE CLOSURE / NON-STABLE

- **Observed:** preflight `32072479294 / 95518530649` verified immutable package/source/selector integrity, then found `directional_surface_cell_authority_kernel_tests` absent. It owns **19** frozen `SurfaceCellAuthorityKernel.*` identities; only **215/234** required identities were runnable. Result/log `9302217665 / 9302218240`.
- **Root cause:** initial CP1 Code + Build packaged directly affected targets but omitted one unchanged executable mandatory for the already-frozen 234-selector TB gate.
- **Correction/evidence:** `M2-CP1-CB-R1` rebuilt/package-closed the unchanged semantic source `3be733a72330ce688013687f11cd3098ed6c849f` through the durable reusable compile workflow with the prior targets plus `directional_surface_cell_authority_kernel_tests`. Run/job `32074026365 / 95523174425` completed **117/117**, result/log `9302765681 / 9302765964` (`2a4772bec07c9d5c3e5e8d1b0a9d1cdea50724be6c8cdb4f98b11c21cf90733b / 06a1caeb2b65c8d4d80de19df4162d60a71260fd77420ff9d197aa6ca300fcc3`); all four selector-owner binaries are present, the frozen selector remains 234 identities at `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687`, five source-status snapshots are clean, and `runtimeExecution=false`.
- **Disposition/stable-count rationale:** pre-semantic package/orchestration defect only. R1 changes no production/test/fixture semantics and executes no generated runtime. Package closure is resolved; semantic CP1 acceptance remains pending `M2-CP1-TB-R1`. New stable events **0**, recurrences **0**. At that checkpoint totals remained **36 / 14 / 22**; debt remains **5**.

## M2-CP0-TB-CAND-02 — documentation closeout controls expose bounded-checkout, byte-transport, and untracked-file verification defects — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** documentation-only closeout run/job `32063141450 / 95488825272` was cancelled during an unbounded full-history checkout before closeout logic began; log artifact `9298979087 / sha256:d18d9c212104d09df4272f12b6b6b97e2766dd9fdf5153c17723bbb6acd5b112`. Bounded retry `32063486394 / 95489930069` completed checkout and source-drift checks, then rejected the connector-written closeout payload because its SHA-256 did not equal the locally frozen script hash; log artifact `9298984642 / sha256:98ddcdf38c89e1f4ec9a932d9d725db3579449087c7a73dbbb09ca20a2400e2a`. Exact-payload retry `32064311289 / 95492601103` verified both payload hashes and prepared all intended docs, then its guard omitted the newly created untracked TB report because `git diff --name-only` does not list untracked files; it failed before commit/push, log artifact `9299279050 / sha256:bf0391bad7fca4829ba4a9e19986dc7fca6b59e3cd0b85a87f16485e4a95d19f`.
- **Root cause / correction:** the first control needlessly requested full Git history on a branch with thousands of commits; the retry bounds checkout to 20 commits. The second control correctly failed closed on non-byte-stable text transport; the payload was replaced with exact Git blobs created from base64 bytes and is hash-verified before execution. The third control exposed a verification-script defect: intent-to-add the new report before the diff inventory so the guard includes untracked creation, while still verifying the exact seven-path closeout set.
- **Disposition:** orchestration/control-plane only. Neither control configured, compiled, rebuilt, relinked, modified source/tests/fixtures, executed generated Directional runtime, ran benchmarks, or changed the immutable CP0 census evidence.
- **Stable-count rationale:** new stable events **0**, recurrences **0**. At that checkpoint totals remained **36 / 14 / 22**; produced-witness debt remains **5**.

## M2-CP0-TB-CAND-01 — `ProducerOutcome<T>` plan notation hides phase-front-specific failure authority — RESOLVED PLANNING / NON-STABLE

- **Observed:** CP0-TB independently accepts the frozen census, then inspects the abstraction CP1 is required to reuse. `DESIGN.md` section 6.5 describes a generic `Rejected<ProducerFailure>`, while accepted source `SurfaceCellTracing.h:671-672` defines `ProducerOutcome<T>` as `variant<NotApplicable, Produced<T>, Rejected<SurfacePhaseFrontFailure>>`. The alias is product-generic but not failure-generic.
- **Risk if uncorrected:** CP1 would have to either encode subdivision/parity/side-repair failures as phase-front failures (authority-domain conflation) or introduce a second closed-outcome wrapper (duplicate authority), contradicting the M2 design before the first product cutover.
- **Correction:** the authoritative CP1 plan now generalizes the **existing** `ProducerOutcome` over failure type while preserving current `SurfacePhaseFrontResult` behavior through the existing/default phase-front failure specialization. CP1 repair products use typed repair failure authority. A rollback-equivalent side-repair state that is legitimately consumable by general completion is encoded as a produced consumable preparation product; true `Rejected` carries no consumable product and is terminal, eliminating string-gated rejected-fallback reconstruction.
- **Disposition:** planning/type-shape defect discovered during artifact-only census acceptance before any CP1 source/test/fixture mutation. CP0 site sets remain exact; no accepted runtime behavior is lost.
- **Stable-count rationale:** new stable events **0**, recurrences **0**. At that checkpoint totals remained **36 / 14 / 22**; produced-witness debt remains **5**.

## M1-FULL-TB-BLOCK-01 — criterion-5 fixture-domain mismatch — RESOLVED PLANNING/EVIDENCE / NON-STABLE

- **Observed:** preflight `32051665150 / 95452236588` correctly stopped because then-current criterion 5 required phase-front producer authority from the directly constructed closed-torus simplification witness.
- **Resolution:** independent planning review `M1-C5-FIXTURE-MAP-REV` confirmed the defect was in the gate and restated criterion 5 per fixture/semantic stage. F1/F2 retain strict producer requirements; F3 retains checked direct construction plus the full unrelaxed simplification predicate and explicitly carries no producer claim.
- **Accepted evidence:** resumed immutable gate `32055365696 / 95464163035`, result `9296299890`, log `9296300150`, passes corrected criterion 5 for all three fixtures and closes M1.
- **Stable-count rationale:** planning/evidence-domain defect only; new stable events **0**, recurrences **0**. At that checkpoint totals remained **36 / 14 / 22**; produced-witness debt remains **5**.

## M1-FULL-TB-CAND-01 — external control-payload HTTP 503 blocks preflight acquisition — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** run `32051454584` attempts 1/2 (`95451537737`, `95451721562`) and hardened run/job `32051586068 / 95451972166` fail before immutable package inspection while fetching the temporary preflight control payload; the hardened control exhausts six HTTP-503 retries. Diagnostic logs are `9294835630`, `9294851611`, and `9294881735`.
- **Root cause / correction:** external raw/Contents payload acquisition was an unnecessary control-plane dependency. The successful control removed that hop and used an exact-SHA **control-only checkout**, explicitly not repository checkout as test authority, then downloaded and verified immutable artifacts in `32051665150 / 95452236588`.
- **Disposition:** orchestration/infrastructure only. No package/source/test/fixture mutation, configure, compile, relink, rebuild, discovery, semantic test body, benchmark, or generated Directional runtime occurred in the failed controls.
- **Stable-count rationale:** new stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M1-FULL-TB-CAND-02 — monolithic harness transfer corruption — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** `32054750074 / 95462203833` fails while decoding the temporary base64/gzip TB control with gzip CRC/length errors. The immutable package is never acquired and generated Directional runtime does not begin. Persistent log `9295977148 / c3564423933186adabc2d869ceec5a645f0edea0d19e8b3fb5eb450f7ef9e4a9`.
- **Root cause / correction:** one large connector-written encoded payload was not byte-stable. The retry split the exact payload into bounded chunks and required SHA-256 `5141bed19f9485b878318041c3afe645b03511f6073d9297765a1f080ffe3930` before decoding, then verified gzip and Python hashes before execution.
- **Disposition:** orchestration/control transfer only; no package/source/test/fixture mutation, configure, compile, rebuild, discovery, semantic test, or benchmark occurred.
- **Stable-count rationale:** new stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## M1-FULL-TB-CAND-03 — artifact redirect authentication blocks immutable acquisition — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** `32055089129 / 95463284124` verifies the chunked harness, then fails before package inspection because Python urllib forwards GitHub authorization through the cross-host signed artifact redirect: attempts 1-4 return 401 and 5-6 return 503. Result `9296124532 / 1483929d82db1be9b7e739debe9500072de592b60a6312e5e0ccd40ca57d806b`; log `9296124829 / c97337864a56c3b42eb418e7007aa46a27c50c468f0df49a8249543b4492ffe4`.
- **Root cause / correction:** redirect authentication was a harness transport defect, not immutable-package evidence. The accepted control patches only the temporary downloader to redirect-safe `curl --location`, verifies the patched harness hash, and then succeeds in `32055365696 / 95464163035`.
- **Disposition:** orchestration/artifact acquisition only. The failed control consumed no Directional package runtime and changed no package/source/test/fixture semantics.
- **Stable-count rationale:** new stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## WU3G-TB-CAND-01 — harness acquisition/digest controls stop before semantic execution — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** `32036059934 / 95406632779` and `32036143687 / 95406892013` stop while acquiring/verifying the temporary TB harness. The first transfer pipeline is unsuitable; the second proves GitHub stores the intended base64 payload without the local terminal newline (20,752 versus 20,753 bytes).
- **Evidence:** logs `9290722028 / 71e7bbd54cc94a547bb1ade2b7ad2d19a862e767300a849fb233916f89cb47fa` and `9290751121 / 7af02428ce3233e35db6c502d648d8d6424cf19e53cc639115a587fc835a919c`.
- **Disposition:** orchestration/control-plane only. No generated Directional runtime, checkout, configure, compile, rebuild, repair, or source/test/fixture mutation occurred.
- **Stable-count rationale:** new stable events 0, recurrences 0; at that checkpoint totals remained **36 / 14 / 22**.

## WU3G-TB-CAND-02 — known WU2B inherited-red hygiene was mechanically promoted into the first G selector — RESOLVED TEST-AUTHORITY / NON-STABLE

- **Observed:** R2 `32036414166 / 95407704293` freezes 235 identities and gets **234 PASS / 1 FAIL**. The sole red is `SurfaceCellsPhase10.HardRailRegionCopiesPairReciprocallyBeforeQuotientMaterialization`, failing at `InvalidFrontBoundaryAuthority` before its claimed seam.
- **Prior authority:** this exact identity is already `WU2B-TB-CAND-01`; accepted-baseline differential `31916254483 / 95088352843` reproduced the same earliest failure. It is explicitly listed in `TODO.md` as deferred non-gating hygiene.
- **Root cause:** selector derivation treated every changed default-packaged test definition as a new G runtime obligation and ignored Gate E's rule that inherited-red/non-gating hygiene must not be promoted unless an independent Batch-G obligation requires its semantic body. Its C06-12 packed-to-typed source change is already established by Gate B static authority and the body still cannot reach its intended reciprocal-copy/materialization seam.
- **Correction:** no source/test/validator mutation. Correct selector authority excludes exactly this known hygiene identity; accepted R5 freezes **234** identities at `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687` and passes all 234.
- **Stable-count rationale:** no accepted-green behavior was lost; new stable events 0, recurrences 0; at that checkpoint totals remained **36 / 14 / 22**.

## WU3G-TB-CAND-03 — corrected-selector diagnostics stage immutable source at the wrong runtime root — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** R3 `32037052304 / 95409518757` and R4 `32037349369 / 95410330614` use the correct 234-selector but execute from package/runner-temp source roots. Twenty-six producer tests fail because committed benchmark fixtures resolve under `/home/runner/work/Directional/Directional`, outside those staged roots.
- **Evidence:** R3 result/log `9291066828 / d92cb8e59e4a7673ca16cf717a420f6e2bb0cddb91e1b522dd632a62b495f029` / `9291067171 / fa0ac512a408fe11c5c44b51a6681ff7d1af24f5b115443e1dee17ea51fc0d6b`; R4 result/log `9291141101 / 613d669e6037f8e9a842a081073c8ca50f290ab3f148a525a89f130f9d1ee49b` / `9291141273 / b6bcba70812a894fb41973f83a9b3eda62730d83d365d3fb5c0b50679d11d769`.
- **Root cause/correction:** the accepted R2 harness stages the immutable source archive directly at `GITHUB_WORKSPACE`; the compiled test fixture-root logic expects that source-root shape. R5 stages the exact same archive at that exact root, changes no package/source/test/fixture semantics, and passes **234/234**.
- **Stable-count rationale:** missing-fixture failures are harness working-directory orchestration, not product regressions. New stable events 0, recurrences 0; at that checkpoint totals remained **36 / 14 / 22**.

## WU3G-TB-CAND-04 — monolithic durable-closeout workflow cannot instantiate a job — RESOLVED ORCHESTRATION / NON-STABLE

- **Observed:** temporary closeout workflow runs `32038083261` and `32038154623`, plus the first record-workflow controls `32038648390` and `32038661360`, terminate immediately with workflow conclusion `failure`, **zero instantiated jobs**, and **zero artifacts**. The failure occurs after semantic Batch-G acceptance and before any closeout runner step can execute.
- **Primary category:** workflow-definition/control-plane orchestration; not package, product, test-authority, or runtime semantic evidence.
- **Root-cause boundary:** The temporary YAML embedded Python here-doc content whose inner triple-quoted document lines escaped the indentation of the `run: |` block. Those unindented lines make the workflow definition invalid before job instantiation; the same authoring mistake recurred in the first recorder control.
- **Correction/guard:** replace embedded multiline document bodies with a minimal valid workflow that checks out the branch and extracts/runs the already-retained Python payload, keeping all workflow block-scalar lines correctly indented. `32038265162 / 95412855490` completes the closeout successfully; result/log `9291343390 / a757b37f70a06a7b493ef2abfd51e52984fb338f9d5d08b6db70c53600aab4e0` / `9291343544 / 99d8679897ef206330c80cec44897b56231ce5edb0e24edcb547b7def0b33185`. The matching minimal recorder `32038732132 / 95414127654` also succeeds; result/log `9291467739 / f154a9da1b259cdc0d82c5460efbd92f92f39137284e8bd4f4ad9dddaedf1577` / `9291467977 / 137408b7dbfbd786585f8bc712d2a2baf0ff6a16ca591bbf155b2fe5e708bcb8`.
- **Stable-count rationale:** all four failed workflow-definition controls instantiate no job and execute no generated Directional runtime or package/source/test/fixture mutation. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## WU3F-TB-CAND-01 — one-byte harness-transfer corruption blocks pre-semantic acceptance control — RESOLVED ORCHESTRATION / NON-STABLE

- **Status:** **RESOLVED ORCHESTRATION / NON-STABLE**. The accepted immutable Batch-F gate is green; the failed controls never reached package semantic execution.
- **Observed:** `31991843496 / 95276672302` failed while decoding the repository-side base64/gzip TB harness with gzip CRC/length errors before immutable package preflight. It produced no semantic result artifact; log `9275571066 / b824babe239f0314b807caacff6d48468db3f023bb79c9a796e8dee9ebdf0a35` records `repositoryCheckout=false`, configure/compile/relink/rebuild/packageRepair=false, and source/test/fixture mutation=false. Diagnostic retry `31991956482 / 95276979367` intentionally retained the fetched payload, again before semantic execution; artifact `9275608515 / 810c0f61d83399b73ff623884092992f73b7859d1fc6dd725d135e50401fe8e1`, log `9275608866 / 0de62beef7a458a0f4a9131e58485188475b9643bc1d1909688572a28c352d5e`.
- **Primary category:** orchestration/control-plane evidence transfer; not a product, test-authority, or immutable-package semantic regression.
- **Root cause:** byte-for-byte comparison of the retained fetched payload with the locally syntax/hash-verified harness found exactly one same-length base64 transfer mismatch at byte offset 12905: repository payload `s`, intended payload `S`. That one case change corrupts the gzip CRC/length while leaving the package/source under test untouched.
- **Correction/guard:** the accepted control corrected only the temporary runner-side harness-transfer byte, required corrected base64 SHA-256 `d7826fcadf90f38dd2078a5692bebe97a2877b928395b189783023a0b0e04b29`, decoded it, and required harness SHA-256 `23fef3064c81871c8318547be97d2dfb711354f6dd9907e52171d4d7a1fdf3c5` before execution. Authoritative `31992003088 / 95277103306` then passed immutable preflight, 225/225 required-green, 206/206 + 4/4 obligation reconciliation, and immutable postflight. Result `9275660950 / 81925dc95b8979575be634c6f05c16a10d324ce6dad30c39d3708829fcf5c423`; log `9275661090 / eebff288b5b34c9939e8866ad52a23262d7c3f21ddca63ac576aa3c7bf52f60a`.
- **Stable-count rationale:** both failures occurred before generated Directional runtime and changed no source/test/fixture/package semantics; the accepted retry lost no accepted-green behavior. New stable events **0**, new recurrences **0**. Historical totals at that checkpoint remained **36 / 14 / 22**; produced-witness debt remains **5**.

## WU3E-TB-CAND-01 — two mandatory R-E contracts are source-present but absent from the immutable package — RESOLVED HYGIENE / NON-STABLE

- **Status:** **RESOLVED HYGIENE / NON-STABLE**. The original package-closure attempt ran no semantic body; final R3 acceptance proves the corrected default-package authority exact-once/nonzero and semantically green.
- **Observed:** authoritative artifact-only attempt `31977862327 / 95239937005` validates the exact Batch-E artifacts and reaches independent package discovery, then rejects the candidate because `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails` and `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` each resolve to zero packaged tests. Result `9271533807 / 7685eb2619ceed8f8c32e7df8b42a8ed001fc021a1a7f6475f85ff9c576ef5c8`; log `9271533907 / 23867a9c0ad74b7abff7f16b94b4f56f3964b677ea71d05bf108b9dce21dd03c`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; subtype: mandatory-contract → packaged-target closure.
- **Root cause:** both exact test definitions exist in the immutable source, but `cmake/DirectionalTests.cmake` assigns `tests/SurfaceCellPipelinePhase20Tests.cpp` and `tests/SurfaceCellTracingPhase14Tests.cpp` only to default-off `directional_surface_cell_historical_tests`. The approved Batch-E package therefore cannot own either mandatory identity. This repeats the failure mechanism recorded by `R-A-R12-CAND-01`: source/compile presence was used as a proxy for package membership.
- **Evidence boundary:** the gate executed only package-owned `--gtest_list_tests` discovery before stopping. No semantic test body, benchmark, rebuild, repair, source/test/fixture mutation, or product runtime acceptance occurred. The prior control `31977811984 / 95239813933` was orchestration-only audit-cardinality mismatch and is not semantic/package evidence.
- **Correction/guard:** `WU3E-TB-R1-CB` must surgically migrate exactly one authoritative definition of each missing behavioral contract into an approved default packaged target, remove historical duplicates, preserve the assertions/scenarios, and add a static package-membership guard. Do not enable the historical target wholesale and do not change production semantics without separate evidence.
- **Code + Build remediation evidence:** `WU3E-TB-R1-CB` exact source `94e59a7985c3d152d9376a0d8596127e4f2f3c1d` relocates exactly the two mandatory definitions into focused default `directional_surface_cell_producer_tests` authority, removes historical duplicates, and adds configure-time exact-one/package-membership guards. Static reconciliation `31979623341 / 95244219899` is PASS at frozen **27/27/10**, E1 **6/6**, E2 **4/4**, route K=0; `include/` and `src/` remain unchanged from pre-remediation Batch E. Immutable package `31979729574 / 95244483768` builds all eight approved targets with exit 0 and `runtimeExecution=false`; result `9272021540 / 715673c38493b4a8dfa423a523c42e4b3427be3c60364d56de5bb4dc52a3ccde`, log `9272021654 / 6ee71357f77456a343010eb56537460b4ee1049bee1726445f642efae52b8999`, source archive `52c37811d3cf00f6464895d986972139546727a5b89c473d6efe8f4ec3e732fa` / 548 members. This structurally remediates package membership but does not close the candidate until `WU3E-TB-R1` independently proves exact-once/nonzero-selected runtime discovery and the semantic gate.
- **Stable-count rationale:** Batch E has never been runtime accepted and no accepted-green product behavior was lost; the failure is pre-semantic package closure. New stable events **0**, new recurrences **0**. Historical totals at that checkpoint remained **36 / 14 / 22**; produced-witness debt remains **5**.
- **R1 runtime status:** package/discovery subclosure is now proven on `9272021540`: both formerly missing identities are package-owned, exact-once, and nonzero-selected. `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` passes; the LiveTracing identity fails semantically before its claimed seam. Under the R1 plan's stricter resolution rule this package candidate remains open until Batch-E semantic acceptance; the semantic observation is tracked separately as `WU3E-TB-R1-CAND-01`.
- **R2 runtime status:** exact-one/nonzero package ownership remains proven on R2 package `9272732618`; independent discovery is 17/269/183/84 and both mandatory identities resolve exactly once.
- **R3 resolution:** authoritative `31986277605 / 95261755062` discovers **17/269/183/84**, resolves the direct and replacement full-pipeline contracts exact-once/nonzero, passes **222/222 required-green**, and preserves immutable postflight. Result `9273897699 / fe9c22936565603a3bee268f0860b7ff5e874300e5db4317ddc54ae60c385d78`; log `9273897936 / 6fe165df414ae6b2b6ab4a3b617ea918a91d0d75f968eb9f487c27cdc8504643`. Package membership/test authority is closed without a production semantic correction.

## WU3E-TB-R1-CAND-01 — mandatory LiveTracing witness fails before its claimed live-tracing rail seam — RESOLVED HYGIENE / NON-STABLE

- **Observed:** immutable R1 `31980808023 / 95247094263` discovers the now-packaged identity exactly once but `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails` fails `NotProductionReady` at stage `tracing` instead of reaching the injected `arrangement` failure. The retained trace network has no qualifying boundary/feature rail seed, no hard/boundary FlowRep rail, and no FlowRep network.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; subtype: mandatory acceptance witness lacked an independently established producer precondition.
- **R2 root cause:** the Batch-E pre-edit census (retired into `M1_Closure_Record.md`) proves the historical two-triangle-square fixture marks its triangulation diagonal hard, splitting the component into two triangular source-topology regions. The authoritative phase-front dispatcher fail-closes `UnsupportedSourceSheetTopology` when such a hard-feature region is unsupported. Both accepted-D and current `build_surface_cell_network` return on `phaseFront.is_rejected()` **before** deterministic rail-seed generation, so R1's empty seeds/FlowRep are downstream consequence and not evidence of an E1 typed `HardRailId` writer defect. An accepted-D-era rectangular internal-hard-feature fixture independently establishes supported phase-front production.
- **R2 Code + Build correction:** exact source `553408b950b5263e421d97b2d3a944d19b54a784` changes only the packaged LiveTracing fixture/setup plus a static CMake recurrence guard. The strict typed rail-seed, mandatory hard+boundary FlowRep, arrangement, telemetry, and lineage assertions remain. `include/src` and the three accepted-D-red quotient bodies have zero diff from R1. Static reconciliation `31982307676 / 95251170731` PASS preserves **27/27/10**, E1 **6/6**, E2 **4/4**, K=0. Immutable compile/package `31982337642 / 95251246821` exits 0 with package `9272732618 / 552d28e81c970378ded39fd70e36e38927e6427164e5022da79f2c33837fe80a` and `runtimeExecution=false`.
- **R2 runtime refinement:** authoritative `WU3E-TB-R2` `31983608515 / 95254667604` proves the rectangular correction reaches the arrangement-stage full-pipeline path, but `sawRailSeed=false` remains the sole required failure. Accepted-D and current source both return from a produced phase front before deterministic seed generation, while the direct typed seed contract passes. The original R1 fixture-precondition diagnosis was correct but incomplete; the deeper impossible combined-witness mechanism is now tracked as `WU3E-TB-R2-CAND-01`.
- **Status:** **RESOLVED HYGIENE / NON-STABLE**. The fixture-precondition finding was valid but incomplete and was superseded by `WU3E-TB-R2-CAND-01`; R3 `31986277605 / 95261755062` closes the chain by passing both truthful split contracts and all 222 required-green identities without production semantic change.
- **Stable-count rationale:** no accepted-green retained behavior was lost, no production semantic code changed in R2-CB, and the historical witness had no accepted packaged green baseline. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## WU3E-TB-R2-CAND-01 — mandatory full-pipeline witness combines mutually exclusive authoritative phase-front and live seed paths — RESOLVED HYGIENE / NON-STABLE

- **Observed:** authoritative immutable R2 `31983608515 / 95254667604` passed preflight, exact selector ownership, independent discovery, every retained accepted surface, and immutable postflight, but required-green was **221/222**. The only failure was `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails`, whose only failed assertion was `sawRailSeed=false`. Result `9273120248 / 84c43db2e637b85d24b2e4175aafc4b97c2f109dde048b79707ca6932cb73edc`; log `9273120524 / cb4088085f9e42eafb537586ba769de2877c18c06063f67cfcb9364390ad3bb2`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; subtype: impossible combined witness / execution-path conflation.
- **Root cause:** accepted-D and current `build_surface_cell_network(...)` both return from the authoritative `phaseFront.is_produced()` path before `generate_deterministic_surface_seeds(...)`; rejected hard-feature phase fronts also return/fail closed. The direct `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` already passes and independently proves the typed `HardRailId` live-seed seam, while the R2 full-pipeline witness reaches arrangement with authoritative hard/boundary FlowRep and arrangement rail authority. No production regression is established.
- **R3 Code + Build correction:** exact source `c591f52280a4ed31fa77146aa994bbf24147f480` changes only `tests/SurfaceCellREPackageTests.cpp` and `cmake/DirectionalTests.cmake`. The retired identity has **0** source definitions. New `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement` and direct `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` each have **1** default-packaged definition with fail-closed split-responsibility guards. The full path retains strict produced-phase-front, typed FlowRep/arrangement rail membership, telemetry, and lineage assertions without live-seed responsibility; the direct path retains exact deterministic typed-seed assertions. `include/src` and the three inherited-red quotient bodies are byte-identical to R2.
- **Static evidence:** `31984982608 / 95258287604` PASS, result `9273468102 / 1839c95d72744867d7af9a0c2d9c75edf97071c1fa5d67ef3ab6bce6d7f1ea69`, log `9273468314 / 5de9c7bc49c4b33b5652144dad971d3dace5c8afef83ea1ee4407d140852ef34`; frozen **27/27/10**, E1 **6/6**, E2 **4/4**, route K=0, `runtimeExecution=false`.
- **Compile/package evidence:** `31984982608 / 95258331809` builds all eight approved targets with exit 0. Immutable package `9273490623 / 4f42e3a72bd447a6e943fabd815928a8579570fc8b5ff0161f7a2a9ef20db1de`, log `9273490809 / b037916c6e9e70462326479068188637174edbbec066cd5bdb6b62b34e74f3f3`; source archive `eca4f779170797034b9afed1ff9befc34fc43fbe0478fb0f72e28e9b60ff26fa` / 556 members; package 26/25; five clean snapshots; ccache 110/111; `runtimeExecution=false`.
- **R3 resolution / status:** **RESOLVED HYGIENE / NON-STABLE**. Artifact-only `31986277605 / 95261755062` consumes immutable `c591f52280a4ed31fa77146aa994bbf24147f480 / 9273490623`, substitutes only the retired Phase20 identity in the exact R2 222-identity required-green authority, and passes **222/222**. Both `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement` and `SurfaceCellTracingPhase14.InteriorHardRailSeedsBothIncidentFaceCharts` pass; every retained accepted group is green; immutable postflight proves package/executable/source state unchanged. Result `9273897699 / fe9c22936565603a3bee268f0860b7ff5e874300e5db4317ddc54ae60c385d78`; log `9273897936 / 6fe165df414ae6b2b6ab4a3b617ea918a91d0d75f968eb9f487c27cdc8504643`.
- **Controls:** `31984775825` was workflow-schema-invalid before any job; `31984837330 / 95257905406` stopped on patch hunk syntax before source mutation. Neither executed generated runtime or changes regression counts.
- **Stable-count rationale:** no accepted-green behavior was lost and no production semantic code changed. New stable events **0**, recurrences **0**. Historical totals at that checkpoint remained **36 / 14 / 22**; produced-witness debt remains **5**.

## WU3E-TB-R1-CAND-02 — broad R-E selector promoted three accepted-D-red quotient witnesses — CLASSIFIED NON-GATING / NON-STABLE

- **Observed:** R1 includes three additional `SurfaceCellTransitionQuotient` identities outside the retained accepted selector chain. Two stop at `torus pipeline producer failed: InvalidHardRailPairing`; one fails `foundSeamEquivalence=false`.
- **Accepted-baseline differential:** exact accepted-D artifact-only `31981144579 / 95248017736` reproduces all three exact failures with preflight/postflight PASS and no mutation. Result `9272364385` / `13e11dab13cdb6349524073ea8ea850ed5327f01985ebbc38f5fca72e8733290`; log `9272364628` / `c7b4c8e7f31eca3e881f88d8ca8d77132caa800311299185b503be930c2e7234`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; mechanism: acceptance-selector overreach. The two torus identities are coupled to deferred `G4-B002`; the quotient-lineage fixture lacks an accepted-green seam-equivalence precondition.
- **Disposition:** R2 and R3 execute all three separately from required-green and reproduce the exact accepted-D red states. R3 also verifies the quotient test source body matches R2. Keep them visible, bodies unchanged, and non-gating; they are not accepted-green Batch-E evidence.
- **Stable-count rationale:** exact same red states exist on accepted D, so Batch E did not lose accepted behavior. New stable events **0**, recurrences **0**; at that checkpoint totals remained **36 / 14 / 22**.

## WU2D-TB-CAND-01 — full-periodic materializer contracts depend on deferred nonzero-Z4 producer capability — RESOLVED HYGIENE / NON-STABLE

- **Observed identities:** `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` and `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` are the only red D contracts in corrected artifact-only `WU2D-TB` `31959655069 / 95195574819`. Both throw `cylinder winding field producer failed: PeriodicHolonomyMismatch` before reaching materialization or transform tampering. All other D contracts are **21/21**, and every retained accepted surface is green.
- **Accepted-baseline differential:** artifact-only `31960093048 / 95196635969` executes the exact two identities on accepted Batch-C source/package `d0f14508d59f4ea4d38b4db7b3904de239a6b555` / `9258953680` and reproduces the same **0/2** earliest `PeriodicHolonomyMismatch`. D1 package `9263684031` reproduces the same **0/2**. All differential package manifests/file-state hashes are unchanged post-execution.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; mechanism: deferred-blocker coupling. The fixture requests `make_committed_fixture("cylinder", true)`, whose winding field uses `fieldAngle = 0.25 * angle` and requires a produced nonzero periodic-Z4 phase front. `REORIENTATION_PLAN.md` explicitly assigns nonzero periodic Z4 production to `G4-B003`, owned by M5 and outside M1.
- **Root-cause bound:** the evidence proves the D materializer contracts are blocked by a producer precondition they do not own. It does **not** prove a D1/D2 product regression and does not authorize enabling `G4-B003` inside M1. The positive and negative materializer assertions have not yet been reached by these fixtures.
- **Disposition:** one planned same-batch remediation package retry may replace only this fixture dependency with directly constructed checked typed phase-front authority at the materializer boundary, carrying nonzero `QuarterTurn` plus nonzero lattice translation and preserving strict positive/tampered-negative assertions with reachability/non-vacuity guards. Production semantics remain unchanged unless separate evidence establishes a product defect.
- **Stable-count rationale:** accepted C already fails both identities at the same earliest precondition; no accepted-green behavior was lost. New stable events **0**, new recurrences **0**; historical totals at that checkpoint remained **36 / 14 / 22**.

**Resolution evidence — WU2D-TB-R1:** test-authority-only source `37adb93e66385b80199c3f748f4a2e9f1ded06dd` removed the two materializer contracts' dependency on deferred produced nonzero-Z4 while leaving `G4-B003` itself deferred. Immutable artifact-only `31964571034 / 95207639154` then passed both formerly blocked identities (**2/2**) and the complete Batch-D surface (**23/23**) with all retained accepted surfaces green and immutable preflight/postflight PASS. Result `9268218441 / e36c90dabeb51fea6c75d117588bf2386c5eac1e8a00be501a110945c47f08df`; log `9268218707 / b65242f578e6d454f9a01cb26489cf5e3c4fff284206318027c92041bdb8318e`. This closes the candidate as test-authority hygiene, not as a production-Z4 fix. No accepted-green product regression existed, so historical stable totals at that checkpoint remained **36 events / 14 categories / 22 recurrences** and produced-witness debt remained **3**.

## PR8-R035 / WU2C-R001 — recovery one-way component/sheet provenance export erased — RESOLVED STABLE / RECURRENCE

- **Original observed loss:** initial WU2C-TB `31925201569 / 95111570760` failed retained `MilestoneGP26.RecoveryPreservesComponentAndSheetProvenance`: source component `7` / sheet `11` were exported as `-1/-1` after C3 removed the representation boundary.
- **Accepted-baseline differential:** accepted Batch B `31925701879 / 95112819123` passed the identity and showed the checked typed-authority -> public integer provenance export.
- **Primary category:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** C3 conflated typed semantic authority with the required one-way public provenance representation and erased the latter.
- **Remediation:** exact source `09c4eb41ac2053bccca7e3f82454e3f30b72e956` restores only checked `SourceComponentId` / `IsolationSheetId` -> `SurfacePoint.component` / `.sheet` output export and classifies those two leaves as one-way exports; static audit remains K=0.
- **Resolution evidence:** artifact-only WU2C-TB-R1 `31928106481 / 95118691578` executes the unchanged retained recovery identity as part of R-C/R-G **67/67 PASS** with immutable preflight/postflight PASS. All retained A/B/R-A/R-B/F2 surfaces also pass. Result `9258540747` / `f38f21366d0f3b8f0831f97611127f8fdce72f4062d66db6153ebe57e29bc69a`.
- **Disposition:** **RESOLVED**. Resolution does not erase its historical stable event/recurrence; cumulative totals at that checkpoint were **36 / 14 / 22**.

## PR8-R036 / WU2C-R002 — reflected periodic test conflates current route topology with cross-fixture correspondence — RESOLVED STABLE / RECURRENCE

- **Initial observed loss:** WU2C-TB failed `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.ReverseObservedCycleUsesExactTransportInverse` before its inverse assertion because the reflected field lookup used pre-reflection `semanticTopology` instead of current reflected-mesh `topology`.
- **Accepted-baseline differential:** the exact identity passes on accepted Batch B under `31925701879 / 95112819123`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; secondary mechanism `RP-01 / AUTHORITY_DOMAIN_CONFLATION`.
- **R1 partial remediation evidence:** source `09c4eb41ac2053bccca7e3f82454e3f30b72e956` corrects the two reflected/current-field lookup seams. Artifact-only retry `31928106481 / 95118691578` proves transition authorship now succeeds, every forward/reverse per-step inverse matching assertion passes, both phase fronts are `Produced`, and both periodic holonomy rotations pass. The identity reaches its final route-topology equality instead of failing fixture setup.
- **Refined root cause:** the fixture carries two intentionally different domains. `step.topology` names an edge in the **current fixture mesh** and is remapped through `oldToNew` under reflection. `step.semanticTopology` retains the original pre-reflection edge only to correlate reflected steps with forward steps. Accepted Batch B's `periodic_route_topology` expected `step.topology`; C4 changed that output oracle to `step.semanticTopology`. The produced typed `CanonicalRoute` correctly reports current reflected-mesh source-edge topology, so R1 now fails only because the expected route sequence is in the correspondence domain.
- **R2 Code+Build remediation:** amended plan section 6.1 authorized the bounded 9/9/4 test-authority repair. Exact source `d0f14508d59f4ea4d38b4db7b3904de239a6b555` replaces the overloaded raw/typed pair with typed `currentTopology` and `correspondenceTopology`, makes current-fixture output/field uses typed and distinct from cross-fixture matching, removes both packed-key unpacks, and adds forward-equality/reflected-inequality non-vacuity. No production/validator source changed. Current audits PASS at master 199/199 and Batch C 64/64; package `31929794499 / 95122783913` is 120/120 with immutable artifact `9258953680` and `runtimeExecution=false`. R036 therefore remains OPEN STABLE until `WU2C-TB-R2` executes the exact contract.
- **Retry evidence:** corrected C required-green **68/69**, all retained authority green, immutable postflight PASS. Result `9258540747` / `f38f21366d0f3b8f0831f97611127f8fdce72f4062d66db6153ebe57e29bc69a`; log `9258540956` / `f7f07a1daebff58e3abe844e1f98b24eb094db3981aa34e2da3b6b23b57e3fe8`.
- **R2 resolution evidence:** exact source `d0f14508d59f4ea4d38b4db7b3904de239a6b555` separates typed `currentTopology` from `correspondenceTopology`, removes both packed-key unpacks, and proves the split non-vacuous without production/validator mutation. Artifact-only `WU2C-TB-R2` `31933702100 / 95132287981` executes `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.ReverseObservedCycleUsesExactTransportInverse` successfully as part of producer **27/27** and corrected Batch-C **69/69**, with immutable preflight/postflight PASS. Result `9260116329` / `0b9c1fe37a295c00183e1dfc34b042b660297f276b1918a09b19168adacc21bc`; log `9260116490` / `c22e480788e1c17124a1dd3efc09ee67c1a683274505eb18a6b5007d0d74cc29`.
- **Disposition:** **RESOLVED**. The accepted-green behavior lost during C4 is restored under the corrected typed test-authority domain split while production transport and the exact inverse assertion remain unchanged.
- **Stable-count rationale:** resolution is not a new event or recurrence and does not erase the historical recurrence already counted. New events **0**, new recurrences **0**; historical totals at that checkpoint remained **36 / 14 / 22**.

## WU2C-TB-CAND-01 — three MultiRail optimizer fixtures are inherited accepted-B red — OPEN HYGIENE / NON-STABLE

- **Observed identities:** `MultiRailChainReachesSelectedChartWithoutConsumingUnusedRelation`, `MultiRailChartReachabilityIsInvariantToSourceFaceRows`, and `MultiRailReciprocityMayBeCarriedOutsideTheSelectedFace` fail on C because the fixture's selected/original/resolved chart is invalid before the intended later assertion.
- **Accepted-baseline differential:** exact accepted-B replay reproduces all three same earliest invalid-chart failures.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root-cause bound:** the differential proves inheritance and that these fixtures lack an accepted-green chart-resolution precondition. It does not justify an optimizer production change or identify the deeper fixture cause.
- **Disposition:** exclude from C required-green proof and retain as explicit hygiene. Repair only after independently establishing a valid chart-resolution baseline while preserving the intended MultiRail assertions.
- **Stable-count rationale:** no accepted-green behavior is lost; stable totals are unaffected.

## WU2C-TB-CAND-02 — multi-orientation chart-numbering witness is inherited accepted-B red — OPEN HYGIENE / NON-STABLE

- **Observed:** `SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering` expects hard-authored chart IDs `1/2` on selected source faces while runtime publishes chart `0`.
- **Accepted-baseline differential:** exact accepted-B replay reproduces the same numbering mismatch.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root-cause bound:** evidence proves inheritance but does not establish whether the fixture oracle or produced authority is semantically correct. Renumbering production or changing expected constants would be unsupported.
- **Disposition:** explicit non-gating hygiene outside corrected C required-green proof.
- **Stable-count rationale:** inherited accepted-B red; stable totals are unaffected.

## WU2B-TB-CAND-01 — hard-rail region-copy witness blocked by front-boundary authority on accepted A and B — OPEN HYGIENE / NON-STABLE

- **Observed:** broad WU2B candidate `31915868952 / 95087448907` fails `SurfaceCellsPhase10.HardRailRegionCopiesPairReciprocallyBeforeQuotientMaterialization`: the region producer returns `Declined` with `InvalidFrontBoundaryAuthority` before the intended reciprocal hard-rail copy / quotient-materialization seam.
- **Accepted-baseline differential:** artifact-only `31916254483 / 95088352843` executes the exact same identity on accepted Batch-A source `5e1fed2545ac730c328f1ff475069874a84ec72a` and reproduces the same `InvalidFrontBoundaryAuthority` failure with immutable package/executable state unchanged.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — the fixture does not independently establish the front-boundary authority required to reach the semantic seam it claims to validate.
- **Root-cause bound:** evidence proves the red state is inherited and that the earliest failing precondition is front-boundary authority. It does **not** justify a production fix or a more specific deeper fixture cause without a separate Code + Build investigation.
- **Disposition:** non-gating hygiene. Repair or replace the fixture only after independently proving valid front-boundary authority; preserve the reciprocal-copy/materialization assertion. Result evidence: candidate `9254941118` / `28367d7c348f912f46692c57bbc1b2eed19e4dc8f9e720a1984f77a0d7dbd236`, baseline `9254968096` / `9f5f46f5429ddbdbb0c2da5bd36f8de481692980922bdcf0ed1b481ab5d571a2`.
- **Stable-count rationale:** the identity is red on the previously accepted package and no accepted-green behavior is lost. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## WU2B-TB-CAND-02 — permitted side-repair rollback witness blocked by ownership-registry/domain-identity precondition — OPEN HYGIENE / NON-STABLE

- **Observed:** `PatchDescriptorMilestoneE.PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion` fails in the broad B candidate with `completion.success=false` and `SuccessfulSubdivisionDomainIdentity;identityFailure=ownership-registry-mismatch`, leaving the expected completion descriptors/quads absent.
- **Accepted-baseline differential:** the exact same identity fails with the same ownership-registry/domain-identity path on accepted Batch-A source under `31916254483 / 95088352843`. This is related to, but distinct from, the existing `WU2A-TB-CAND-01` patch-domain hygiene lineage.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — the fixture's prerequisite successful authoritative subdivision/domain identity is not baseline-green, so it cannot prove later permitted-repair rollback semantics.
- **Root-cause bound:** current evidence establishes the earliest failing authority precondition, not the deeper reason that fixture/registry authority disagrees.
- **Disposition:** non-gating hygiene. Independently establish the ownership-registry/domain-identity precondition before re-promoting this rollback witness; do not weaken exact rollback assertions. Evidence: candidate `9254941118`, baseline `9254968096`.
- **Stable-count rationale:** inherited baseline red; no accepted-green behavior was restored then lost. Stable totals at that checkpoint remained **34 / 14 / 20**.

## WU2B-TB-CAND-03 — authoritative-cell-scope subdivision fixture expects unproven region identity — OPEN HYGIENE / NON-STABLE

- **Observed:** `PatchDescriptorMilestoneE.AuthoritativeCellScopeOverridesMultiScopeBoundaryDuringSubdivision` produces provenance `sourceTopologyRegion=9` where the fixture expects region `2` in both the broad B candidate and accepted-A differential.
- **Accepted-baseline differential:** `31916254483 / 95088352843` reproduces the exact region-9-versus-2 assertion failure on accepted Batch-A source with immutable postflight PASS.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — the expected source-scope identity is encoded by the fixture without an independently established accepted-green authority derivation.
- **Root-cause bound:** the differential proves inheritance but does not establish whether region 9 or region 2 is semantically correct; changing production or simply updating the expected constant would be unsupported.
- **Disposition:** non-gating hygiene. Re-derive the expected scope from canonical typed authority in a future Code + Build investigation and retain a discriminating assertion. Evidence: candidate `9254941118`, baseline `9254968096`.
- **Stable-count rationale:** exact same red state exists on accepted A; stable totals at that checkpoint remained **34 / 14 / 20**.

## WU2B-TB-CAND-04 — five simplification transaction/support witnesses lack baseline candidate preconditions — OPEN HYGIENE / NON-STABLE

- **Observed identities:** `SurfaceComplexSimplificationPhase17.ComplexRollbackPreservesHashOnRejectedTrial` (`removable=-1`); `CandidateExtractionIsDeterministicAndCarriesAuthoritativeSupport` (empty candidate set); `CandidateExtractionMarksProtectedSupportInsteadOfSilentlyDroppingIt` (`removable=-1`); `TransactionalMutationPreservesHardRailSupport` (`protectedHalfedge=-1`); `RequiredSingularityBridgeIsProtectedAndRollsBackExactly` (required healing candidate absent).
- **Accepted-baseline differential:** `31916254483 / 95088352843` reproduces all five failures with the same assertions on exact accepted Batch-A source. The two independently accepted simplification identity contracts remain green: `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` and `CanonicalSourceScopeIdentityIsRowIndependentWithNonVacuousCandidateBaseline`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — these five fixtures do not establish the removable/protected/healing candidate precondition required by their later rollback/support assertions.
- **Root-cause bound:** current runtime proves fixture reachability/precondition failure. It does not justify weakening candidate predicates or synthesizing a candidate in production.
- **Disposition:** non-gating hygiene. Any repair must use a genuinely production-feasible independently proven fixture and preserve strict transaction/rollback/support assertions. Evidence: candidate `9254941118`, baseline `9254968096`.
- **Stable-count rationale:** inherited baseline red across all five identities; stable totals at that checkpoint remained **34 / 14 / 20**.

## WU2B-TB-CAND-05 — FlowRep mandatory-cycle witness lacks successful-selection baseline — OPEN HYGIENE / NON-STABLE

- **Observed:** `FlowRepStrandsPhase15.ProposalRailSegmentsRemainMandatoryCycleEvidence` reaches `selectionSucceeded=false`, so it never establishes the successful sparse-selection precondition needed to credit the later mandatory-cycle evidence assertion.
- **Accepted-baseline differential:** `31916254483 / 95088352843` reproduces the same `selectionSucceeded=false` failure on accepted Batch-A source with immutable postflight PASS. Other selected FlowRep hard-rail provenance contracts are baseline-green and pass WU2B.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — the fixture is not a valid accepted-green selection baseline for the claimed cycle-evidence behavior.
- **Root-cause bound:** evidence proves precondition failure only; it does not justify modifying production selection or relaxing the mandatory-cycle requirement.
- **Disposition:** non-gating hygiene. Repair only with an independently demonstrated successful-selection proposal-rail scenario and keep the cycle-evidence assertion strict. Evidence: candidate `9254941118`, baseline `9254968096`.
- **Stable-count rationale:** inherited baseline red; stable totals at that checkpoint remained **34 / 14 / 20**.

## WU2A-TB-CAND-01 — side-subdivision canonical-domain witness is inherited baseline-red — OPEN HYGIENE / NON-STABLE

- **Accepted disposition:** WU2A Batch A is accepted on exact immutable source `5e1fed2545ac730c328f1ff475069874a84ec72a` by corrected artifact-only run/job `31908189133 / 95069151582`. Required-green Batch-A contracts are **43/43**, retained R-C/R-G **67/67**, retained R-B **20/20**, retained R-A **115/115**, F2 **4/4**, and both immutable postflights pass.
- **Observed raw supplemental failure:** semantic run/job `31907649560 / 95067860691` selected **44** dedicated Batch-A identities and reported **43 pass / 1 fail / 0 skip**. The sole failure was `PatchDescriptorMilestoneE.SuccessfulSideSubdivisionPreservesCanonicalDomainIdentity`: `audit_surface_cell_domain_identity` reported `ownership-registry-mismatch`, followed by an active descriptor ownership conflict.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — an inherited baseline-red supplemental witness was over-promoted into the required-green Batch-A selection without first establishing a green accepted baseline.
- **Accepted-baseline differential:** artifact-only diagnostic `31908053158 / 95068828434` consumed exact previously accepted R-C source `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb`, independently discovered the same exact identity once, and also reported **0/1 FAIL** with package state unchanged and no rebuild/repair. Result `9252888769` / SHA-256 `09cab334b30c2b2bd90162ad9786965b56496381d80123001d3ebb9672e8158d`; log `9252888883` / SHA-256 `7664f7ff97a7463494561101f8b23006aac25001afc6ea6fc2d7e190234535fc`. This proves WU2A did not introduce the red state; it does not prove the deeper pre-existing fixture/registry root cause, which remains open hygiene.
- **Test-authority correction:** the corrected acceptance harness kept the identity explicitly reported as inherited known-red but removed it from required-green proof. No immutable package, production source, packaged test, fixture, binary, or manifest was changed. Final result `9253004400` / SHA-256 `a330f275682192988786714e6c037874f1b720927f2324d38ddf72963a688f69`; log `9253004614` / SHA-256 `411be79d845e652677a9287a3eae347bfa388c5546a402e72bc8f170a3367a57`.
- **Orchestration-only catches:** initial WU2A run `31907576379` stopped before semantic execution because a retained audit wording marker changed; initial baseline diagnostic `31908004773` stopped before runtime on redirected artifact authentication. Neither is a semantic attempt or regression event.
- **Stable-count rationale:** the exact same test is red on the previously accepted package, while every retained accepted contract remains green on WU2A. No accepted production behavior was lost, restored, then lost again, so stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.
- **Follow-up:** repair or replace this fixture/oracle only after independently proving the intended ownership-registry precondition. Do not weaken its assertions or count it as required-green evidence until that precondition is established.

## R-C-TB2-CAND-02 — checked-Product runtime witness coverage — FULLY RESOLVED / NON-STABLE

- **Final resolution evidence:** immutable `31865263629 / 94965185949` on `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` passes all 17 exact runtime identities covering all 16 constructible Product error paths, while `InvalidSourceAuthority` remains the one schema-only case. R-C/R-G is **67/67** and immutable postflight passes. The source-audit-overcredit lineage is fully closed.

- **TB3 semantic evidence:** immutable run/job `31862829473 / 94959030721` on exact package source `79393ef49c8c3686ec0833cbc99f0c8f67d5c90b` passes preflight, discovery **17 / 265 / 183 / 84**, all ten newly added checked-Product tests **10/10**, recovery **6/6**, retained R-B **20/20**, F2 **4/4**, and immutable postflight. R-C is **65/67** and retained R-A **114/115**.
- **Resolved portion:** the ten witnesses added by the bounded Code + Build remediation all execute and pass, including `InvalidBoundedDiskRegion` and `DuplicateBoundedDiskRegion`. The original bounded-disk/package-ownership gap is therefore semantically resolved.
- **Superseded assumption:** `.agents/Directional/R_C_Product_Factory_Coverage_Audit.py` credited every pre-existing error-code token in default-built sources as a direct runtime witness. TB3 proves two of those six prior credits are not valid reachability evidence. The overall 16/16 semantic Product-error gate remains open under `R-C-TB3-CAND-01` and `R-C-TB3-CAND-02` below.
- **Artifacts:** result `9241186741` SHA-256 `363e270c5fbeebd2fcf1d366f8862bf4c9624b822062be13c81c1a7131867653`; log `9241187066` SHA-256 `2a2631216ce66f86f2a31469cd3ab4d6300de02fd1961a99d2562d1e7823b26e`.
- **Stable-count rationale:** this lineage remains acceptance-witness/test-authority work; no accepted production behavior is shown lost or restored then lost. Stable totals at that checkpoint remained **34 / 14 / 20**.

## R-C-TB3-CAND-01 — `InvalidCellRegion` replacement witness reaches `InvalidEdgeRegion` first — RESOLVED / NON-STABLE

- **Resolution evidence:** immutable `31865263629 / 94965185949` executes the repaired exact identity on source `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` and passes the intended `InvalidCellRegion` checked-factory guard. The absent typed region witness no longer reaches `InvalidEdgeRegion` first. No accepted product behavior was lost.

- **Observed:** `SurfaceCellAuthorityContractCutover.ConflictingCellRegionFailsBeforeMaterialization` fails in both R-C and retained-R-A selection. It expects `SurfacePhaseFrontProductErrorCode::InvalidCellRegion`; runtime returns `InvalidEdgeRegion`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — invalid replacement witness / wrong earliest guard.
- **Root cause:** the R-C replacement body changes the first cell from its current region to a *different region already present in the same `SourceTopologyRegions` authority*. Product cell-region membership is therefore valid. The unchanged incident edge retains the old region, so `SurfacePhaseFrontProduct::make` correctly reaches its later edge/cell region-consistency guard and returns `InvalidEdgeRegion`.
- **Accepted-baseline distinction:** the accepted pre-R-C test body did not require this new typed Product error; it mutated the then-public Product and required downstream materialization to fail `AuthoritativePhaseFrontSourceLabelMismatch`. R-C intentionally replaced public mutation with checked construction. The new exact `InvalidCellRegion` reason is an unaccepted replacement-witness requirement, while production remains fail-closed earlier than materialization.
- **Correction:** start from a valid Product, create a valid typed `TopologyRegionId` absent from source authority, assert absence, assign only that ID to one cell, reconstruct through the checked Product factory, and require `InvalidCellRegion`. Do not alter edges, production checks, or validators.
- **Code + Build remediation:** exact source `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` implements that absent-authority mutation and checked reconstruction; strengthened source audit pins the exact test body and forbids the prior existing-region replacement shape. Compile/package `31864421305 / 94963103637` is green. This is non-runtime evidence; the candidate remains open until the immutable retry reaches `InvalidCellRegion`.
- **Stable-count rationale:** no accepted product behavior is lost; the new replacement witness is malformed for the error it claims to isolate. Stable totals at that checkpoint remained **34 / 14 / 20**.

## R-C-TB3-CAND-02 — `MissingPeriodicRelationOwner` witness blocked by deferred torus failure — RESOLVED / NON-STABLE

- **Resolution evidence:** immutable `31865263629 / 94965185949` executes the repaired direct checked periodic Product witness on `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` and passes `MissingPeriodicRelationOwner` without entering `torus_fixture()` or deferred `G4-B002`. No accepted product behavior was lost.

- **Observed:** `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` throws `torus pipeline producer failed: InvalidHardRailPairing` before its periodic-owner mutation or checked Product construction.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` — baseline-red/deferred fixture dependency.
- **Root cause:** the test still depends on `torus_fixture()`, which is blocked by known deferred `G4-B002 InvalidHardRailPairing`. R-B already decoupled its periodic-owner reorder invariant from this fixture for the same reason.
- **Correction:** use `direct_periodic_owner_product()` or an equivalent direct checked Product baseline; prove a valid `PeriodicCut` owner exists, clear exactly one owner in copied pre-publication values, reconstruct through the Product factory, and require `MissingPeriodicRelationOwner`. Do not fix/bypass G4-B002 in M1.
- **Code + Build remediation:** exact source `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` uses `direct_periodic_owner_product()`, proves the selected owner exists in periodic relation authority, clears exactly one owner, and reconstructs through the checked helper; the strengthened source audit forbids `torus_fixture()` for this witness. Compile/package is green. This is non-runtime evidence; the candidate remains open pending immutable semantic proof.
- **Stable-count rationale:** this test is not part of accepted R-A/R-B semantics and never reaches the intended seam; no accepted product behavior is lost. Stable totals at that checkpoint remained **34 / 14 / 20**.

## R-C-TB1-CAND-01 — mandatory source-grid recovery witness absent from immutable package — RESOLVED AT PACKAGE/DISCOVERY

- **Resolution evidence:** TB2 `31859923303 / 94951357157` on exact package source `39ef87cf6d0e35a92b7721031adbbb763bd349fc` independently discovers the six required `MilestoneGP26` recovery identities in `directional_surface_cell_producer_tests`; `.agents/Directional/R_C_Recovery_Package_Coverage_Audit.py` is **6/6 PASS** and historical tests remain OFF.
- **Scope of resolution:** this closes the TB1 package/discovery defect. TB2 did **not** execute the recovery contracts because the later bounded-disk mandatory-coverage check stopped the semantic gate. No recovery semantic-pass claim is made yet.
- **Original evidence:** TB1 `31858506554 / 94947517720`, result/log `9239773538 / 9239773759`, discovered recovery **0** because the contracts were historical-target-only.
- **Stable-count rationale:** package-coverage candidates occur before checkpoint acceptance; neither TB1 nor TB2 demonstrated a failure of previously accepted semantic behavior. Stable totals at that checkpoint remained **34 / 14 / 20**.

## Current R-B-TB2-R3 runtime classification — R-B CLOSED

- **Status:** authoritative immutable `31851663979 / 94928457628` passes preflight, discovery **17 / 249 / 183 / 84**, mandatory identities **6/6 exact-once**, R-B **20/20/0/0**, retained R-A **115/115**, F2 **4/4**, and immutable postflight with zero orchestration failures.
- **Artifacts:** result `9237772411` SHA-256 `d757074a9c7589adbf4fb12168c5b74460efda1eea20d73d9f04a9ce13cbaf1c`; persistent log `9237772573` SHA-256 `d92a208199ae8360c3b10eb2eaf366bfdfb5dab0feef9ff8d56db7dd5a4938cb`.
- **Resolved candidate:** `R-B-TB2-R2-CAND-01 / RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. The strict simplification candidate-extraction companion is baseline-green on the closed periodic toroidal fixture; all row/support/chart identity contracts and retained R-A authority pass organically.
- **Stable-count rationale:** R2/R3 concerned an unaccepted acceptance-witness baseline. The corrected runtime does not demonstrate loss or recurrence of accepted product behavior. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.
- **Preliminary orchestration-only attempt:** `31851526497 / 94928068989` stopped before packaged discovery/runtime when the temporary harness transform searched for the wrong quote spelling of the expected-selection predicate. Static inspection had passed; result/log `9237663121 / 9237663340` SHA-256 `b13c34e7ef0e3dde3cae0c8e99ff6bb131fe9139495a41822cd8fb1a01c41be0 / 3e49a1dda7994c4148916280f5ac101980961b3e9e512855ad9169e49e4f54bc`. No generated semantic runtime occurred, so it is excluded from regression counts.
- **Next checkpoint:** work unit 2 Code + Build (R-D.4 + R-G.2, then R-D.5); preserve closed R-A/R-B/R-C authority.

## Current R-B-TB2-R2 runtime classification

- **Status:** R-B remains open. Preflight PASS; discovery **17 / 249 / 183 / 84**; mandatory identities **6/6 exact-once**; R-B **20/19/1/0**; retained R-A **115/115**; F2 **4/4**; postflight PASS.
- **Artifacts:** result `9236929073` SHA-256 `919867cffcee0f0a72c0f1656d8d6a1345fdbf8e21e295f0ca1d2996c710619c`; log `9236929343` SHA-256 `fd21461ad25d09322b5a3b67aab4fe9e337ae28d547b8750ae40f4327891527e`.
- **Observed failure:** only `SurfaceComplexSimplificationPhase17.CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` fails, at line 170 because no candidate from the one-triangle four-parallel-arc fixture satisfies the strict non-protected/topology-preserving/side-feasible predicate.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. The fixture was borrowed from an unselected historical candidate-recomputation test without current runtime proof. Production extraction explicitly treats exterior/boundary participation as protected and requires closed one-boundary-component affected cells for side feasibility; current runtime proves the reused fixture is not a valid acceptance baseline for the requested candidate class.
- **Counterevidence:** the three former R1 failures now pass, all other R-B contracts pass, and retained accepted R-A is fully green. No accepted behavior was restored then lost.
- **Stable-count rationale:** this is an unaccepted acceptance-witness baseline failure, not demonstrated product regression or recurrence. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.
- **Correction:** bounded Code + Build `R-B-TB2-R3-CB` must replace only the failing companion fixture with a genuinely production-feasible interior/closed or annular/cylindrical candidate topology, preserve the strict predicate and all current R-B/R-A greens, and execute no generated runtime.

## Rules

## Current R-B-TB2-R3 Code + Build classification — non-runtime

- **Status:** bounded test-authority Code + Build/source-control evidence only. Exact source `2e61dafa4da600608b5b1281d16085d04caeb135`; semantic source delta is one test file, production implementation/validators unchanged, and generated runtime was not executed.
- **Repair:** the failing candidate-extraction companion now uses a direct closed periodic 4x4 toroidal quad complex capable of representing non-boundary closed-cell neighborhoods while preserving the exact strict eligible-candidate predicate. The runtime-green direct canonical source-scope identity contract is unchanged.
- **Evidence:** source audit `31850731957 / 94925875034` PASS/self-tests PASS/**0 forbidden semantic-row findings**; compile `31850731957 / 94925898323` **119/119**, exit `0`, ccache **108/109**; static package inspection `31850731957 / 94926066113` PASS at **26 / 25 / 25**, zero symlinks, five clean source states, 536-member archive SHA-256 `f618a2bcbde5d62fc40fd5981ea9b722499d9e8a652ca43f220c11e0f871e501`.
- **Superseded build catches:** `31850400684` failed a caller static assertion before configure/compile. `31850504085 / 94925286182` reached **118/119** and rejected retired fixture field assignments; the correction removed the stale fields. Neither attempt executed generated runtime. These are orchestration/source-build catches in unaccepted remediation lineage, not semantic regression recurrences.
- **Runtime boundary:** `runtimeExecution=false`; Code + Build cannot resolve `R-B-TB2-R2-CAND-01 / RP-02`.
- **Stable-count rationale:** no accepted runtime behavior was exercised or lost. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**. The candidate remains pending the immutable R3 semantic retry.
## Current R-B-TB2-R1 remediation Code + Build classification — non-runtime

- **Status:** bounded test-authority Code + Build/source-control evidence only. Exact source `c188b6e82f76d317287dce11ebbffcf31582bb97`; no production source or validator was changed and no generated Directional runtime executed.
- **Repairs:** PatchDescriptor establishes current canonical ownership-registry validity before the unchanged baseline audit; simplification uses a six-strand non-vacuous production candidate baseline before direct scope identity; periodic owner reordering uses direct typed two-relation phase-front/product authority with explicit `PeriodicRelationId` owners and no torus producer/materializer. `G4-B002` remains revised-M4 work.
- **Source/build evidence:** source audit `31839978956 / 94894518575` PASS/self-tests PASS/**0 forbidden semantic-row findings**; compile `31839978956 / 94894518703` **119/119**, exit `0`; inspection `31840183002 / 94895146353` PASS at **26 / 25 / 25**, zero symlinks, five clean source states, 536-member byte-identical source archive. Exact artifact digests are retained in the R-B report/plan.
- **Observed non-runtime catch:** initial caller `31839952660` contained a mistyped full semantic source SHA. Both jobs failed at checkout; configure/build/runtime never began. Corrected exact-source caller `31839978956` supersedes it. This is orchestration/control-plane evidence, not a semantic regression.
- **Stable-count rationale:** Code + Build cannot resolve or create the runtime candidate. No accepted runtime behavior was exercised or lost, so stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**. `R-B-TB2-R1-CAND-01` remains pending the next immutable artifact-only retry.


- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence while a gate remains red is not a recurrence; recurrence requires restoration followed by later loss.
- Compile success never resolves runtime or architecture migration work.
- New migration code remains pending until immutable semantic acceptance.
- **Every Test + Benchmark turn MUST, before closure, categorize every observed regression in this tracker and record root-cause analysis.** If evidence is insufficient for a stable regression ID/count, record it explicitly as candidate/non-stable and state why historical totals do not change.
- Known-red/deferred product cases stay explicit and are never relabeled green/expected-failure to close architecture work.
- Focused/helper passes cannot close representative product intent.
- Before every turn review `RP-01` through `RP-09`; every touched pattern needs an exact invariant and counterexample/representative gate.
- Stale per-turn documents are not historical authority. Once their necessary facts are folded into this tracker/current report/audit inventory/changelog, they may be removed under `.agents/Directional/CLEAN_UP_POLICY.md` and `.agents/Directional/RETENTION_POLICY.md`.

## R-B-TB2-R2-CAND-01 — simplification non-vacuity companion acceptance fixture — RESOLVED

- **Status:** resolved by authoritative immutable TB2 R3 `31851663979 / 94928457628` on exact package source `2e61dafa4da600608b5b1281d16085d04caeb135`; R-B closes at **20/20 PASS** with retained R-A **115/115 PASS** and F2 **4/4**.
- **Resolution:** R3 replaced only the invalid one-triangle boundary/exterior baseline with a closed periodic 4x4 toroidal quad complex while retaining `!touchesHardFeature && !touchesBoundary && !touchesSingularity && !changesTopology && sideFeasible`. Production extraction and validators were unchanged. Runtime now finds the required eligible candidate and the companion passes organically.
- **Preservation:** all six mandatory R-B identities resolve exact-once and pass; kernel **3/3**, completion/consumer **7/7**, pipeline **5/5**, digest/periodic-owner **3/3**, validation **2/2**, retained R-A **115/115**, and F2 **4/4**.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`; the issue was an unaccepted acceptance-fixture baseline, not a production regression.
- **Stable-count rationale:** no previously accepted behavior was lost and no recurrence was established. Stable totals at that checkpoint remained **34 / 14 / 20**.
- **Evidence:** `9237772411 / 9237772573`, SHA-256 `d757074a9c7589adbf4fb12168c5b74460efda1eea20d73d9f04a9ce13cbaf1c / d92a208199ae8360c3b10eb2eaf366bfdfb5dab0feef9ff8d56db7dd5a4938cb`; immutable postflight unchanged.

## R-B-TB2-R1-CAND-01 — prior three-precondition candidate resolved/superseded by TB2 R2

- **Status:** resolved as a three-seam record by `31848878409 / 94920702419`. PatchDescriptor, direct canonical source-scope identity, and periodic owner reordering all pass at TB2 R2.
- **Remaining work:** moved to `R-B-TB2-R2-CAND-01`, which is only the new candidate-extraction companion fixture baseline.
- **Stable-count rationale:** R1 was never accepted and its resolution/supersession changes no stable count.

## R-B-TB2-CAND-01 — mandatory SurfaceArrangement closure witness is source-present but absent from packaged executables

- **Status:** **resolved** package/discovery test-authority record. The semantic retry packages the witness, discovers it exactly once, and it passes. This record remains excluded from stable historical event/recurrence totals.
- **Observed:** immutable TB2 run/job `31832455092 / 94871087169` consumed exact source `6e62ee91e041413b8ba596beab11a9bd67940989` compile/audit/inspection artifacts. Preflight and immutable postflight both PASS. Result `9231190722` SHA-256 `b384c868ac52087a0510dcbf3d2e0fcd5be04fa02a6fdcf25146b6e52492ab12`; log `9231191026` SHA-256 `323f8765a5fc864f4bdda63c96b8ea533ac646c5280a10ace5a3e925917f1b29`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Classification: **mandatory package/discovery coverage failure**, not a semantic production regression.
- **Discovery:** **17 authority-kernel / 249 producer / 181 completion / 84 validation**. Four mandatory TB2 identities resolve exactly once. `SurfaceArrangementPhase16.FaceInteriorSupportAndChartIdentityAreRowIndependentAndDiscriminating` resolves **0** times, which is an orchestration/package failure under the gate contract.
- **Root cause:** the exact packaged source contains both the SurfaceArrangement test file and mandatory contract, but `cmake/DirectionalTests.cmake` wires `tests/SurfaceArrangementPhase16Tests.cpp` only into `directional_surface_cell_historical_tests`. The immutable package records `DIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF`; the approved compiled-target list and package contain no historical test executable. Therefore Code + Build compiled the contract's source tree but did not package the mandatory runtime identity.
- **Execution boundary:** semantic R-B and retained R-A groups were **not executed** after mandatory discovery failed. This intentionally prevents zero-selected acceptance and preserves the artifact-only gate contract. No semantic pass/fail claim is made for TB2.
- **Immutability:** package manifest remains **25/25**, package/executable state is unchanged, zero symlinks, and `rebuild=false`, `packageRepair=false`, `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`.
- **Resolution:** completed on source `567c3bc216dd7e018579171257a6d521672b76f5`. The focused SurfaceArrangement witness is owned by `directional_surface_cell_completion_tests`, historical tests remain OFF, source package-membership audit passes, and retry `31837396234 / 94886624691` discovers all five mandatory identities exact-once; the SurfaceArrangement contract passes at runtime.
- **Stable-count rationale:** this package/discovery defect never represented loss of accepted product behavior. Its resolution changes no stable count. The semantic retry is classified separately as `R-B-TB2-R1-CAND-01`; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## Retained R-B-TB2 packaged-witness remediation Code + Build classification — non-runtime history

- **Status:** Code + Build/source-control evidence only; no semantic runtime executed, so this turn creates no stable regression ID/count and does not resolve the existing runtime candidates.
- **Exact final source:** `567c3bc216dd7e018579171257a6d521672b76f5`. The mandatory SurfaceArrangement identity is isolated into a focused default completion-test source; historical tests remain OFF. Production support/chart identity and validators are unchanged.
- **Source-only closure:** `31834855060 / 94878759530` PASS. Row audit self-test PASS with **0 forbidden semantic-row findings**; package-membership audit self-test PASS with exact contract present and one approved default owner. Artifact/log `9232075855 / 9232076284`.
- **Compile/package:** `31834855060 / 94878759748` completed approved targets **119/119**, exit `0`, ccache **108/109**. Result/log `9232100867 / 9232101220`. Package **26 / 25 / 25**, zero symlinks, five clean statuses, exact **536-member** archive `1dbe66ac9d8566ece8aab9b342d1ae480cea97bb867a8a03a7ccc8d3cf63504c`, runtime disabled.
- **Observed non-runtime catch:** first source `77aef16eb83d4d33c7ff799a72f24f09f636e551` wired the entire historical SurfaceArrangement test source into the default completion target. Compilation failed at **118/119** because unrelated historical tests still use retired arrangement/chart APIs. No generated runtime executed. This is a source/build packaging catch in unaccepted remediation lineage, not a semantic regression recurrence.
- **Correction:** package only the required current witness in focused `SurfaceArrangementRowIdentityTests.cpp` and guard exact default ownership source-only. The witness preserves the intended row-invariance and discrimination contract; the current optional resolver API is unwrapped explicitly.
- **Stable-count rationale:** no accepted runtime behavior was lost or executed. `R-B-TB2-CAND-01 / RP-02` and `R-B-TB1-CAND-01` remain pending the immutable semantic retry; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## Current R-B-TB1 remediation Code + Build classification — non-runtime

- **Status:** Code + Build/source-control evidence only; no semantic runtime executed and no stable regression ID/count is created or resolved by this turn.
- **Exact source:** `6e62ee91e041413b8ba596beab11a9bd67940989`. Baseline-green acceptance witnesses now cover PatchDescriptor row identity, direct SurfaceArrangement canonical support/chart identity, direct SurfaceComplexSimplification canonical scope identity with a non-vacuous candidate baseline, strengthened valid HardRail chart row invariance, and typed periodic owner/container reordering before the known M4 materialization blocker.
- **Source-only closure:** `31829422657 / 94861261003` PASS, self-test PASS, **0 forbidden semantic-row findings**; artifact/log `9230079391 / 9230079846`.
- **Compile/package:** `31829482881 / 94861462716` completed approved targets **118/118**, exit `0`, ccache **107/108**; result/log `9230130409 / 9230130756`. Independent inspection `31829747052 / 94862329932` PASS: **26 / 25 / 25**, zero symlinks, five clean statuses, exact **534-member** archive `d76cc034a8b3aed83d834fff3c2cdf419f56497a31343558e4f0bc9a50276aec`.
- **Observed non-runtime catches:** an initial malformed temporary payload failed before source mutation; intermediate source `41d5f795...` compiled only to **102/118** because new test code used stale test-side APIs (`SurfaceSimplificationCandidateSet`, `SourceChartTransitionGraph`, and `DomainResult` ingress); a superseded package-inspection attempt used a stale hardcoded archive-member count. Each was corrected before final evidence and before any generated runtime.
- **Classification:** orchestration/source-build catches in unaccepted remediation lineage, not losses of accepted product behavior and not semantic regression recurrences. `runtimeExecution=false` throughout Code + Build.
- **Stable-count rationale:** no new semantic runtime result exists. `R-B-TB1-CAND-01` remains open until TB2 executes the new package; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**. Immutable TB1 subsequently classified all runtime observations under `R-B-TB1-CAND-01`.

## R-B-TB1-CAND-01 — R-B closure selection uses baseline-red/deferred witnesses and misses direct changed-consumer discrimination

- **Status:** candidate/non-stable test-authority record; R-B remains open. Not included in stable historical event/recurrence totals.
- **Observed:** corrected immutable TB1 run/job `31824473557 / 94845218480` on exact source `d974d7dd378034d74da457b211149f7f052568dd`; preflight/discovery/postflight PASS, R-B **21 unique / 15 pass / 6 fail / 0 orchestration failures**, retained R-A **115/115 PASS**. Result `9228364900` SHA-256 `4b448c70765d0ee9e8a3b131029a7c269213661765bd648a4ba54bd95fb47fb0`; log `9228365456` SHA-256 `b601da218185a7da3c8bc89de3be330c0af22d941e35846eba6c4d055514b27b`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Unit-test review classification: **invalid acceptance witnesses / missing scenario coverage**, not a demonstrated production regression.
- **Six observations:** `MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` stops at known `InvalidHardRailPairing`; three PatchDescriptor witnesses start from invalid/no-repair authoritative state; the simplification witness produces no candidates; the multi-rail validator witness starts from an invalid source chart.
- **Baseline discrimination:** five of the six fail at the same earliest precondition/assertion on the exact accepted R-A retry-16 package/source before the R-B cutover. The torus relation-order witness reaches existing `G4-B002 InvalidHardRailPairing`, already assigned to revised M4. Therefore none is evidence that R-B lost accepted R-A behavior.
- **Escape mechanism:** the R-B package contains strong new kernel/pipeline/digest evidence, but the closure selector reused old PatchDescriptor/simplification/validator tests without first proving their baseline preconditions and used a later-milestone torus blocker as an ordering oracle. Changed SurfaceArrangement/SurfaceComplexSimplification canonical support/chart serialization is not covered by a clean direct packaged runtime witness starting from valid authority.
- **Correction:** Code + Build remediation is complete on exact source `6e62ee91e041413b8ba596beab11a9bd67940989`. `DomainIdentityIsIndependentOfSourceFaceRowOrder` now establishes a valid PatchDescriptor baseline; new direct arrangement/simplification contracts prove canonical row/order invariance and discrimination with valid/non-vacuous preconditions; the valid HardRail chart witness is strengthened; and `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` isolates typed relation-owner reordering before `G4-B002`. Production and validators were not weakened. Runtime resolution remains pending immutable TB2.
- **Preservation evidence:** R-B kernel **3/3**, pipeline **5/5**, benchmark digest **2/2**, selected completion/source-support **3/3**, selected validator **2/2**, source-only audit, and the complete retained R-A **115/115** gate are green.
- **Preliminary orchestration note:** run `31823694174 / 94842721246` reached the same R-B semantic **15/21** state and green executed R-A groups, then failed final evidence capture because the temporary harness searched for stale F2 source-token names. Corrected run `31824473557` changed only external evidence-token capture and completed immutable postflight; the preliminary run is orchestration-only evidence.
- **Stable-count rationale:** no previously accepted behavior is shown lost. Five failures predate R-B and one is an existing deferred blocker; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## Retained R-B Code + Build source/build classification — non-runtime history

- **Status:** retained Code + Build source/build history. These catches occurred before R-B runtime and created no stable regression ID/count; current runtime classification is `R-B-TB1-CAND-01` above.
- **Observed during Code + Build:** compile/source-audit iterations exposed incomplete semantic-row migration at remaining consumers, attempts to default-construct strong `SemanticId`-backed `SourceVertexId` arrays, and a benchmark semantic-record serialization typo. Each failure occurred during source-only audit or compilation before generated Directional runtime.
- **Correction:** final exact source `d974d7dd378034d74da457b211149f7f052568dd` passes the source-only R-B audit with **0 forbidden semantic-row findings** and compiles/packages approved targets **118/118**, exit `0`, in run/job `31821301314 / 94834955373`. Package metadata records `runtimeExecution=false`.
- **Classification:** these are implementation/build catches in an unaccepted R-B candidate lineage, not loss of previously accepted runtime behavior. They are excluded from semantic regression recurrence accounting.
- **Stable-count rationale:** this retained Code + Build turn had no semantic runtime evidence and therefore did not change counts. Immutable TB1 subsequently classified all runtime observations under `R-B-TB1-CAND-01`; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

## Historical PR-wide authority

- **39 distinct regression events**;
- **14 architectural categories**;
- **25 recurrences**;
- **115 regression-bearing result-document commits**.

T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, accepted M1b artifact `9042940168`, accepted M1c artifact `9043971772`, accepted M1d artifact `9046308272`, accepted M1e artifact `9049125645`, and accepted M1f artifact `9050850344` create no new production regression event or recurrence. M1f runtime authority is accepted. Accepted M1g artifact `9053047653` likewise creates no stable product regression event or recurrence; M1g semantic acceptance is complete. M1h artifact `9066967620` created no stable product regression event: its sole focused failure was classified as a test-authority witness defect while all entering product/preservation authority remained unchanged. Remediation artifact `9069186973` is now immutable accepted with focused **6/6**, required-green **187/187**, full entering preservation/direct-product authority, unchanged historical-red classes, and exact postflight. M1i implementation `b037157921094604f1b0c17f9c8b7076c7604b3b` is immutable accepted from artifact `9072101943`: focused **6/6**, required-green **193/193**, full entering preservation/direct-product authority, unchanged historical-red classes, bounded Bunny/Vase comparison, and exact postflight. No stable product regression event or recurrence is added. `PR8-R034 / G4-R007` remains active. M1j implementation `d5f681173600dc32dc7617de6105d9e584e593be` is immutable accepted from artifact `9076217893`: producer discovery **214**, focused **6/6**, required-green **199/199**, full entering preservation/direct-product authority, all eight historical-red classes unchanged, strict timing truthfully **0/10**, bounded Bunny/Vase comparison, and exact **67/67** postflight. No stable product regression event or recurrence is added. M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` is immutable accepted from artifact `9079318682` and runtime evidence `9080245848`: producer **220**, focused **6/6**, required-green **205/205**, full entering preservation/direct-product authority, all eight historical-red classes unchanged, Bunny/Vase dispositions preserved, and exact **68/68** postflight. Strict timing sampled **10/10** but remains the existing nondeterministic microbenchmark classification. The local extraction/harness anomalies and first remote evidence-upload-path failure are infrastructure only. No stable product regression event or recurrence is added. M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` is immutable accepted from artifact `9083262395` and runtime evidence `9083913766`: producer **226**, focused **6/6**, required-green **211/211**, full M1k-M1b/validation/M1a/T1/direct-product preservation, all eight historical/deferred red classes unchanged, strict timing truthfully sampled **10/10** while remaining deferred, Bunny/Vase dispositions preserved, and exact **56/56** postflight. The local first-process Cylinder stall did not reproduce remotely and is execution-plane only. No stable product regression event or recurrence is added.

Current R-A semantic runtime note: retry 16 `31808562013 / 94793328201` on exact source `588a58935b481943eea9f8424e9897d6a1a44454` completed **112 unique / 112 pass / 0 fail / 0 skipped / 0 orchestration failures**. Runtime result `9222292493` SHA-256 `fadb19ab943b0da904856a9499c69b6ddd4790528af7d4fc8e12f7a1c56227d3`; log `9222293094` SHA-256 `30449ebca6273ab751c8e6dc19feff1bbdc7defe692f0bf128c9d47af199780c`. Preflight, byte-identical REV-35, discovery, eight mandatory exact-once contracts, F2 **4/4**, and immutable postflight all pass. No semantic regression was observed. Preliminary run `31808413434 / 94792837677` is infrastructure-only: harness transformation failed before artifact download/runtime and is excluded from semantic counts.

Current R-A package-closure note: `R-A-R12-CAND-01 / RP-02` remains **resolved**; mandatory isolation selects exactly **1** and passes **1/1**.

Current R-A production-classification note: `R-A-R11-CAND-01` remains resolved at hard-feature/isolation-sheet classification, and `R-A-R13-CAND-01 / RP-01 + RP-05` remains resolved at aggregate-remap/final-oracle production. Retry-16 authority-contract cutover is **41/41**, feature chain **6/6**, and all strict retained product groups are green.

Current R-A test-authority note: `R-A-R14-CAND-01 / RP-02` remains resolved at its old unrelated phase-front-fixture seam. `R-A-R15-CAND-01 / RP-02` is now **resolved** by immutable retry 16: the repaired direct-remap identity selects exactly once and passes **1/1**, all six produced shared-HardRail-fixture diagnostics select exactly once and pass **6/6**, and the full gate is **112/112**. Product behavior remains strict and historical totals at that checkpoint were **34 / 14 / 20**.

### R-A-R15-CAND-01 — mandatory direct remap witness mixes global source topology with compact component-local topology

- **Status:** **resolved** candidate/non-stable test-authority record; retry-16 reaches and passes the intended direct typed-remap seam; excluded from stable historical event/recurrence totals.
- **Observed:** immutable retry 15 `31799783107 / 94764797160` on exact source `7b125ad318078477b83bb7a24c6dca89943ac724`; **106 unique / 105 pass / 1 fail / 0 skipped / 0 orchestration failures**. Result `9218898728` SHA-256 `9c2b4589e3714cde6eddc43ad56ab8b3fecbf0af09c772647fbab3d63e4fe560`; log `9218898992` SHA-256 `a034de5e60b5fe8bc2c8a39e245fd178a92c8fe104f2fb5fc2ef5d6eaef4f856`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Unit-test review classification: **invalid fixture / authority-domain mismatch**.
- **Symptom:** `ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain` selects exactly **1** and reaches direct setup, but fails at `ASSERT_TRUE(hardAwareDomain.has_value())` (`SurfaceCellTransitionQuotientTests.cpp:1686`). The previous `InvalidFrontBoundaryAuthority` producer exception is gone.
- **Root cause:** the test constructs `SourceTopologyRegions` from global `mesh.F` and global HardRail edges `(1,4)/(4,7)`, then supplies `components.front()` from `compact_face_components`. `compact_face_component` assigns local vertex IDs by first source-face encounter and rewrites `component.faces`; for this witness global face row 0 `(0,1,4)` becomes local `(0,1,2)`. `make_component_typed_authority_remap_domain(...)` correctly requires `sourceAuthority.matches_source_faces(component.faces, component.originalVertices.size())` and therefore returns `nullopt` before chart-domain semantics. The intended local HardRail chain is likewise `(local(1), local(4), local(7))`, not the unremapped global keys.
- **Product discrimination:** retry-15 cutover **41/41**, feature chain **6/6**, hard-rail transport **5/5**, direct materializer/local-sheet **2/2**, strict validators, rail authority, and F2 **4/4** all pass. Production aggregation supplies each compact component's own `componentResult.surfaceCellContext.sourceTopologyRegions`, so the helper's local-domain precondition is satisfied in the organically green product path.
- **Correction:** build the direct witness source authority from `component.faces`; derive original→local vertex IDs from `component.originalVertices`; remap original HardRail `(1,4,7)` into local edge keys; explicitly require `sourceAuthority.matches_source_faces(component.faces, component.originalVertices.size())`; then preserve **2 regions / 1 sheet**, barrier-sensitive chart evidence, hard-aware remap success, and explicit-barrierless fail-close. Do not modify production to accept mismatched authority.
- **Coverage amendment:** the six genuine produced consumers of the retry-15 shared `hard_rail_fixture()` were outside the authoritative R-A selection. Supplemental exact-package local diagnostics are **6/6**, but retry 16 must promote those six identities to package-specific mandatory discovery/runtime evidence.
- **Recurrence guard:** REV-35 must structurally pin component-local authority construction, local HardRail remap, exact source-face ownership precondition, mandatory identity uniqueness, and package membership of the six produced shared-fixture contracts.
- **Retry-16 Code + Build correction:** semantic test/static commit `de533350fb39886b21b85aa70ac0a0ddce2bd627` constructs `SourceTopologyRegions` from `component.faces`, remaps original HardRail `(1,4,7)` through `component.originalVertices`, explicitly asserts exact compact topology ownership plus **2 regions / 1 sheet**, and retains the hard-aware/barrierless oracle. REV-35 is **21 / 100 / 410 / PASS** with new guards **14/14**; exact clean source `588a58935b481943eea9f8424e9897d6a1a44454` compiles/packages **118/118**, exit `0`. No production/validator changed and no generated runtime executed.
- **Retry-16 runtime resolution:** authoritative run/job `31808562013 / 94793328201` passes the repaired mandatory remap **1/1**, all six changed produced shared-HardRail diagnostics **6/6**, and the full deduplicated gate **112/112** with zero orchestration failures. Result `9222292493` / log `9222293094`; F2 remains **4/4** and immutable postflight is clean.
- **Stable-count rationale:** this was a non-stable invalid-fixture candidate in unaccepted remediation lineage; retry16 restores the intended test seam without any loss of accepted product behavior. No new stable event or recurrence is created. Stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

### R-A-R10-CAND-01 — regional `FieldChartId` ordinal published as canonical source-chart identity

- **Status:** candidate/non-stable regression record; mandatory Test + Benchmark classification, not included in stable historical event/recurrence totals.
- **Observed:** R-A retry 10, exact source `b3dc5c3fc6a7d4d9e88873c026021ad955939cab`, runtime `31755283604 / 94629617727`, semantic **95/103 pass, 8 fail**.
- **Primary categories:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION` and `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`. Detection escaped through `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Symptom:** both direct authoritative materializer/local-sheet contracts fail. After the shared ownership closure, HardRail owners expose only one source-chart component/topology region while retaining cross-rail equivalence; strict source-authoritative validation rejects `LocalSheetMismatch`. Dependent feature/final-oracle contracts remain blocked, and the strengthened final-oracle negative correctly reports an unreached callback instead of crediting `mutated=false`.
- **Root cause:** `build_planar_phase_frame` assigns `LocalLatticeState::sourceChart` from a region-local chart ordinal (`legacyFaceChart`), while `SourceChartTransitionGraph` separately owns canonical chart identity over the full source-face domain with hard-feature barriers. Periodic and bounded regional producers also contain a local single-chart semantic writer. `build_authoritative_phase_front_mesh` legitimately treats producer `sourceChart` as semantic lineage, so a local ordinal can collide with a different canonical chart. The shared closure then correctly rejects the mismatched retained chart and exposes the upstream authority split.
- **Escape mechanism:** earlier contracts proved strong `FieldChartId` construction, closure placement, owner/route cardinality, and downstream strict validation, but did not assert at the **producer publication boundary** that each regional cell/segment chart equals the canonical full-source chart for its exact source face. A local ordinal could therefore survive compile/static checks until the direct retry-10 materializer contract exercised a multi-region HardRail collision.
- **Containment/correction:** establish one canonical `SourceChartTransitionGraph` authority domain from exact source faces/topology/hard-feature barriers; regional producers consume that exact face-to-chart identity. Keep branch rotation/parameterization as separate representation state. Remove local semantic chart writers; do not repair downstream, union unrelated charts, infer from output geometry, or renumber for a fixture.
- **Recurrence guard:** REV-30 must structurally forbid local chart writers and require canonical publication; a direct pre-materialization contract must compare every published regional `sourceChart` to `SourceChartTransitionGraph::chart(face)` and prove HardRail-separated regional copies carry distinct canonical identities where required. Existing post-materializer strict positives/negatives remain mandatory.
- **Stable-count rationale:** retry 10 is remediation-candidate evidence, not accepted-lineage evidence. It refines the already-open `LocalSheetMismatch` cluster rather than proving a newly lost accepted M1l behavior; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

### R-A-R11-CAND-01 — hard-feature rail barrier reused as isolation-sheet authority

- **Status:** candidate/non-stable regression record; mandatory Test + Benchmark classification, not included in stable historical event/recurrence totals.
- **Observed:** R-A retry 11, exact source `b75a2ee7aabd2478587ac80f2d5b6b671cbbb079`, runtime `31759986180 / 94644068840`, semantic **98/104 pass, 6 fail**.
- **Primary category:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION`. Detection escaped through `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Symptom:** the canonical writer contract and both direct materializer/local-sheet contracts pass, but the full rectangular feature-bearing production witness still fails `NotProductionReady:completion:LocalSheetMismatch`. The feature tamper test stops at completion instead of component merge, and three final-oracle feature contracts plus the strict HardRail final-oracle negative never reach their intended callbacks.
- **Root cause:** the full production path calls `classify_source_surface_labels(..., hardFeatureRailEdges, ...)` and publishes its `localSheetByFace` as `sourceFaceSheets`. In that classifier the supplied barrier set terminates local-sheet adjacency. Independently, `build_source_topology_regions(...)` already uses hard features as topology-region barriers, and `SourceChartTransitionGraph` uses them as chart barriers. The same hard rail is therefore incorrectly promoted into `IsolationSheetId` authority. `close_completion_lineage_source_authority(...)` correctly requires retained cross-HardRail charts to stay on the selected isolation sheet, so it rejects the opposite-side chart after production has assigned a different sheet and strict validation reports `LocalSheetMismatch`.
- **Escape mechanism:** the direct rectangular phase-front fixture sets `sourceFaceSheets` to one explicit sheet while supplying hard-feature edges separately. It therefore proves closure semantics under a valid same-sheet HardRail witness but does not exercise production source-label classification, allowing the hard-feature→sheet alias to survive while the direct writer/materializer tests turn green.
- **Containment/correction:** separate isolation-sheet classification from hard-feature rail authority. Hard rails remain topology-region/chart/rail/feature barriers; only actual isolation-sheet authority or an independently declared isolation-barrier set may split `sourceFaceSheets`. Preserve the shared closure's same-sheet requirement and strict `LocalSheetMismatch`; do not broaden closure across sheets or weaken validators. Add a production-path positive proving a hard rail does not automatically create an isolation sheet and a counterexample proving a genuine isolation barrier still does.
- **Code + Build correction:** exact compile source `8ea8dd944eea83fe830a51f68589c213c8f21f14` stops passing the full hard-feature rail set into production sheet classification, compiles a production **2-region / 1-sheet** witness and an explicit independent isolation-barrier sheet-splitting counterexample, and extends REV-31 to **20 / 85 / 388 / PASS** with all **10/10** prior convergence guards. Compile `31762721890 / 94652261378` is **118/118**, exit `0`; no generated runtime executed.
- **Recurrence guard:** REV-31 forbids direct aliasing of the full `hardFeatureRailEdges` set into production isolation-sheet classification and preserves all REV-30 guards. Runtime retry 12 must distinguish hard-feature region/chart separation from independent isolation-sheet separation and require the feature-bearing production witness to reach aggregation/final-oracle seams.
- **Retry-13 runtime proof:** intended seam corrected. Both rectangular feature components are `Produced`, each publishes **2 topology regions / 1 isolation sheet**, and `ComponentFeatureRailTamperRejectsAtAggregationSeam` now passes. The remaining failure is later aggregate chart remap, not `LocalSheetMismatch`.
- **Stable-count rationale:** retry 11 is remediation-candidate evidence, not accepted-lineage evidence. It refines the still-open R-A feature-chain cluster rather than proving newly lost M1l behavior; stable totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

### R-A-R12-CAND-01 — required isolation-barrier contract excluded from immutable R-A package

- **Status:** candidate/non-stable package-closure record; excluded from stable totals.
- **Observed:** `31764157297 / 94656475630` on `9205314649` / `8ea8dd944eea83fe830a51f68589c213c8f21f14`. Integrity/REV-31/discovery/postflight passed; semantic bodies were not started.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.
- **Root cause:** `SurfaceCellTracingPhase14.SourceClassifierExplicitIsolationBarrierSplitsOtherwiseConnectedSheet` exists in `tests/SurfaceCellTracingPhase14Tests.cpp`, but that source is only in `directional_surface_cell_historical_tests`; the package has `DIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF` and omits the target. Overall compile success was incorrectly used as proxy for contract-specific package membership.
- **Escape:** REV-31 guarded production authority but not newly declared contract → packaged-target closure.
- **Correction/guard:** place one authoritative isolation-barrier counterexample in an approved packaged R-A target and require every package-specific mandatory identity to resolve/select >0 before semantic execution. Prefer surgical producer-target placement over broad historical enablement.
- **Code + Build correction:** exact source `efe3c013b5deff4115b5f84d5c53e8f69163fdcd` moves the unchanged behavioral counterexample into `tests/SurfaceCellsPhase10Tests.cpp`, removes the historical duplicate, and adds REV-32 exactly-one/source-target/outside-historical-gate membership guards. REV-32 is **21 / 89 / 391 / PASS**, **10/10** retained convergence and **4/4** membership; compile `31766052818 / 94662111896` is **118/118**, exit `0`.
- **Retry-13 runtime proof:** **resolved at the package/test-authority seam**. Discovery is **14 / 247 / 180 / 84**; the mandatory identity selects **1** from `directional_surface_cell_producer_tests` and passes **1/1**.
- **Stable-count rationale:** `8ea8dd944eea83fe830a51f68589c213c8f21f14` was never runtime accepted and retry 12 ran no semantic body; no accepted M1l behavior loss is established. Totals at that checkpoint remained **34 / 14 / 20**.

### R-A-R13-CAND-01 — aggregate typed authority remap reconstructs canonical source charts without HardRail barriers

- **Status:** candidate/non-stable production-authority record, **runtime-resolved at its intended aggregate-remap/final-oracle seam by retry 14**; excluded from stable totals because the remediation lineage has not yet achieved full R-A acceptance.
- **Observed:** immutable retry 13 `31767176830 / 94665335666` on exact `efe3c013b5deff4115b5f84d5c53e8f69163fdcd`; **105 unique / 100 pass / 5 fail / 0 skipped / 0 orchestration failures**. Runtime result `9206797766` / log `9206797939`.
- **Primary categories:** `RP-01 / AUTHORITY_DOMAIN_CONFLATION` and `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY`. Detection escaped through `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` because producer/materializer chart convergence was covered before aggregate remap chart reconstruction was independently pinned.
- **Base failure:** `RectangularInternalHardFeatureProducesAuthoritativePhaseFrontPerComponent` organically satisfies its fixture/precondition facts — both components inspected, both producers `Produced`, **2 topology regions / 1 isolation sheet** — then fails `NotProductionReady:component-merge-authority:InvalidFinalValidationAuthorityRemap`.
- **Dependent failures:** `FinalOracleRejectsMissingForeignOrUncertifiedHardRailChartAuthority`, `FinalMergedOracleRejectsMissingRemappedFeatureAuthority`, `FinalMergedOracleRejectsChangedRemappedFeatureRailContent`, and `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority` all correctly fail their callback/non-empty-authority non-vacuity assertions because the base aggregate never reaches final validation/oracle. They are not four independent root causes and must not be weakened or credited as intended-oracle evidence.
- **Root cause:** component phase-front canonical chart writers construct `SourceChartTransitionGraph` with exact HardRail barriers. The graph otherwise unions incident faces in the same source component. Component final-validation capture retains the same hard-feature edge authority from `authoritativeRails`. Aggregate `make_component_typed_authority_remap_domain(...)`, however, reconstructs `SourceChartTransitionGraph(component.faces, sourceAuthority)` with no barrier set and publishes that second chart domain as `localChartsByFace`. `remap_component_typed_lineage_authority(...)` requires exact captured-lineage chart equality against that reconstructed domain, so valid hard-feature-aware lineage fails closed during final-validation authority remap.
- **Why this is production, not fixture:** the representative fixture now proves the intended component producer, region, and sheet preconditions organically; `ComponentFeatureRailTamperRejectsAtAggregationSeam` passes, proving the aggregation seam is reached; mandatory isolation, hard-rail transport, direct materializer/local-sheet, F2, completion, optimizer, rail, and source-validator groups remain green.
- **Correction:** validate captured component authority/rail equality before remap-domain construction; derive exact local hard-feature barriers from the captured authoritative HardRails; require the aggregate remap domain to build canonical charts with those same barriers. Do not infer from output geometry/options, silently default empty, merge chart domains, or weaken strict validators.
- **Recurrence guard:** REV-33 must require an explicit barrier input on aggregate typed remap, pin `SourceChartTransitionGraph(..., &hardFeatureEdges)`, require the caller's barriers to come from captured authoritative rails, and forbid a barrier-less production call. A focused positive/counterexample pair must validate the aggregate remap seam directly.
- **Retry-14 Code + Build correction:** exact source `fe6d88af0bad157f888c6d7352ea62d0745c626e` validates captured rail authority before remap, derives the aggregate barrier set from captured authoritative HardRails, makes `SourceChartTransitionGraph` barrier authority required by reference, uses explicit empty authority for genuine no-feature sites, and compiles a barrier-sensitive remap counterexample. REV-33 is **21 / 93 / 396 / PASS**, with construction-site closure **6/6**; compile is **118/118**. Runtime proof remains pending retry 14.
- **Retry-14 runtime proof:** exact source `fe6d88af0bad157f888c6d7352ea62d0745c626e`, run/job `31774574854 / 94687254679`: authority-contract cutover **41/41**, feature chain **6/6**, including the former base witness and all four dependent final-oracle contracts. The aggregate HardRail-aware remap correction therefore works organically through final oracle/publication. The sole retry-14 failure is an unrelated mandatory-test fixture defect recorded as `R-A-R14-CAND-01`.
- **Stable-count rationale:** `efe3c013b5deff4115b5f84d5c53e8f69163fdcd` is an R-A remediation candidate, not accepted-lineage authority. The five failures refine the continuous open R-A authority-convergence chain rather than proving a newly lost accepted M1l behavior. Historical totals at that checkpoint remained **34 events / 14 categories / 20 recurrences**.

| Cause category | Pattern | Events | Recurrences |
|---|---|---:|---:|
| `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | 7 | 6 |
| `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | 7 | 6 |
| `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | 4 | 3 |
| `NONTERMINATING_CUMULATIVE_WORK` | `RP-04` | 3 | 2 |
| `REPRESENTATION_DEPENDENT_IDENTITY` | `RP-05` | 2 | 1 |
| `STATE_CARDINALITY_GROWTH` | `RP-06` | 2 | 1 |
| `CYCLIC_TOPOLOGY_LINEARIZATION` | `RP-07` | 2 | 1 |
| `PRODUCER_DISPOSITION_CONFLATION` | `RP-08` | 2 | 1 |
| `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | 2 | 1 |
| five singleton categories | — | 5 | 0 |
| **Total** |  | **34** | **20** |

Singletons: `INTRINSIC_SUPPORT_OVERCONSTRAINT`, `INCOMPLETE_TRANSACTIONAL_ROLLBACK`, `SHARED_EDGE_ORIENTATION_INVERSION`, `INCOMPLETE_ORBIT_PUBLICATION`, `EXACT_SIMPLEX_CANONICALIZATION_LOSS`.


### R-A-R14-CAND-01 — mandatory aggregate-remap contract is blocked by a pre-existing non-producing hard-rail fixture

- **Status:** candidate/non-stable test-authority fixture record; sole retry-14 failure; excluded from stable historical event/recurrence totals.
- **Retry-15 resolution:** resolved at this old producer-fixture seam. The mandatory contract now reaches direct remap-domain construction; the remaining retry-15 failure is separately classified as `R-A-R15-CAND-01`.
- **Observed:** immutable retry 14 `31774574854 / 94687254679` on exact `fe6d88af0bad157f888c6d7352ea62d0745c626e`; **106 unique / 105 pass / 1 fail / 0 skipped / 0 orchestration failures**. Runtime result `9209439245` / log `9209439558`.
- **Primary category:** `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Unit-test review classification: **invalid fixture / wrong test level**.
- **Symptom:** `SurfaceCellTransitionQuotient.ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain` selects exactly **1** but throws `hard-rail rectangle producer failed: InvalidFrontBoundaryAuthority` in `hard_rail_fixture()` before either hard-aware or explicit-barrierless `make_component_typed_authority_remap_domain(...)` assertion executes.
- **Root cause:** the mandatory test is a direct typed-remap contract but obtains `SourceTopologyRegions` by running a full phase-front producer through `hard_rail_fixture()`. The shared 2x1 internal-HardRail helper calls `build_surface_cell_network(...)` and then `require_produced`; that setup does not produce and therefore cannot structurally exercise the remap contract. Exact source history shows the helper implementation predates retry 14 unchanged, so the failure is not introduced by the CB-05/CB-06 production repair.
- **Product discrimination:** retry-14 `SurfaceCellAuthorityContractCutover.*` is **41/41**, the previously red feature chain is **6/6**, direct materializer/local-sheet **2/2**, hard-rail transport **5/5**, and F2 **4/4**. `R-A-R13-CAND-01` is therefore green at the intended production seam while this new test fails earlier in unrelated setup.
- **Correction:** directly build the mandatory remap witness's source mesh, one-component/one-sheet `SourceTopologyRegions`, and explicit HardRail barriers using `build_source_topology_regions(...)`; require a barrier-sensitive chart witness; preserve hard-aware remap success and explicit-barrierless fail-closed semantics. Separately inventory all **9** shared `hard_rail_fixture()` consumers: direct authority tests should not invoke phase-front production, while genuine HardRail transport/materialization tests should use a known production-feasible internal-midline fixture and retain `require_produced`.
- **Code + Build correction:** retry-15 semantic test/static commit `70f7b9e0566f253d35c25517dacf0ced3c81820e` makes the mandatory remap witness direct/self-contained with explicit HardRail-aware source topology and barrierless counterexample, isolates the three direct typed tests from phase-front production, and moves the six genuine produced-network consumers to the known production-feasible 3x3 internal-midline HardRail fixture with explicit authoritative rail and `require_produced`. REV-34 is **21 / 96 / 399 / PASS** with custom guards **15/15**; clean source `7b125ad318078477b83bb7a24c6dca89943ac724` compiles **118/118**, exit `0`, into immutable result `9212050099`. No production implementation/validator changed and no generated runtime executed. Runtime retry 15 is required before resolving this candidate.
- **Recurrence guard:** REV-34/package authority must require the mandatory remap identity exactly once, forbid its coupling to `hard_rail_fixture()`/`build_surface_cell_network`, and keep explicit setup non-vacuity so a mandatory contract cannot be credited when it never reaches its intended seam.
- **Stable-count rationale:** retry 14 is still an unaccepted R-A remediation lineage, the sole failure is test authority rather than lost accepted product behavior, and M1l behavior remains intact. Stable totals at that checkpoint stayed **34 events / 14 categories / 20 recurrences**.
## Repeated coding-pattern catalog

### RP-01 — authority-domain conflation

```text
bad: one bare integer is reused as face/transition/chart/rail/etc.
good: semantic domains use strong IDs/certificates and explicit mappings.
```

Invariant: source face, transition, chart, rail, and stitch identity are never interchangeable.

Counterexample: permute one authority domain while preserving all others; the intended consumer rejects.

### RP-02 — test-authority coverage gap

```text
bad: helper-level green is used as product acceptance.
good: each authority has unit negatives plus representative product and final-oracle evidence.
```

Invariant: representative product verdict dominates focused/helper verdict.

Counterexample: helper passes while a direct product fixture carries the same authority and fails.

### RP-03 — policy/stage-state conflation

```text
bad: fallbackAllowed = stageAvailable;
good: requested policy and observed execution/completion state are separate fields.
```

Invariant: degraded output never reports certified production completion.

Counterexample: request fallback but inject production-stage failure; diagnostics must retain failure and degradation separately.

### RP-04 — cumulative work inside iterative stage

```text
bad:
for step in path:
    solve(all_faces_seen_so_far)

good:
precompute_static_system_once()
for step in path:
    update_incremental_state(step)
```

Invariant: append one equal-complexity step ⇒ measured work grows near-linearly.

Counterexample: doubled path length must not approach quadratic work.

### RP-05 — representation-dependent identity

```text
bad: semantic_id = iteration_index;
good: semantic_id = canonical_topology_key_or_checked_typed_identity;
```

Invariant: equivalent reorderings preserve semantic identity/certificate content.

Counterexample: reverse face/region ordering and compare semantic products, not raw traversal order.

### RP-06 — state/cardinality growth

```text
bad: state.push_back(transient) without retire/merge;
good: bound state by active topology and retire obsolete entries.
```

Invariant: tracked state cardinality is bounded by current active topology, not elapsed steps.

Counterexample: long synthetic trace with fixed active width keeps state bounded.

### RP-07 — cyclic topology linearized incorrectly

```text
bad: infer one terminal/cut from incidental order;
good: represent/verify the closed cycle directly.
```

Invariant: cyclic source topology has no arbitrary terminal unless the contract explicitly selects one.

Counterexample: cyclic permutation/reversal preserves cycle certificate/semantics.

### RP-08 — producer disposition conflation

```text
bad: unsupported/failed producer => empty success or unrelated fallback;
good: ProducerOutcome = Produced | Rejected(reason) | NotApplicable(reason).
```

Invariant: rejected authoritative input cannot be relabeled successful by a later generic path.

Counterexample: inject authoritative producer failure; final disposition remains rejection unless explicit degraded policy is selected.

### RP-09 — local consumption of global authority

```text
bad: component treats global field/region/rail identity as local arrays/indices;
good: explicit local<->global mapping preserves certificate meaning.
```

Invariant: component execution does not change global semantic ownership.

Counterexample: reorder/partition components and compare remapped global certificates.

## Test-authority defects

### TA-05 — indirect or stale helper authority

Current status: **resolved and preserved through accepted M1l**. Tests execute arbitrary extraction, reject injected field-count mismatch, reject invalid tetra topology, and validate direct products from immutable source artifacts. M1h additionally proved one new test-authority failure mode: occurrence coverage was incorrectly treated as producer-domain chart coverage. That assertion was corrected without changing producer behavior and the remediation is accepted.

Do not regress to source-tree symlink dependence, private-helper substitutes, cardinality-derived identity, exact raw numbering/hash assertions when semantic invariants suffice, or accepting regenerated/host source in place of packaged evidence.

## Current immutable migration authority

### M1h immutable accepted record

The initial M1h artifact `9066967620` compiled typed chart-owner source but exposed one test-authority defect. Corrected implementation `23efcc68289244056fe4a766588386bc487feb7f` is immutable accepted from artifact `9069186973`:

- focused: **6/6**;
- required-green: **187/187**;
- M1g/M1f/M1e/M1d/M1c/M1b focused preservation green; validation **77/77**; M1a **14/14**; T1 **29/29**;
- direct products green from arbitrary extraction with no fixture symlink; historical/deferred red classes unchanged;
- diagnosis: fixture samples lattice-corner chart IDs `{0,2}` while producer/segment authority still proves chart domain `{0,1,2}`; test incorrectly equates producer-domain and occurrence coverage;
- disposition: **test-authority defect, not stable product regression**; historical totals remain **34 / 14 / 20**; `PR8-R034 / G4-R007` remains active;
- historical next at this checkpoint was M1i; that consumed plan/report set has since been retired under `CLEAN_UP_POLICY.md`. Current next action is owned by the handoff and `TODO.md`.

### M1g immutable accepted pattern record

M1g implementation `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` migrates the periodic canonical-face-cycle whole-route accumulator to checked source vertices, canonical topology keys, checked compact transitions, `TransitionStep`, `CanonicalRoute`, and typed transport composition. It preserves current `PeriodicHolonomyMismatch` rejection for nonzero cycle rotation. `G4-B003` remains unresolved.

Immutable authority:

- build run/job `31362470744 / 93373936472`, **120/120**;
- result artifact `9053047653`, ZIP SHA-256 `296f3ed13f2f09143a14f63555171d013939c2525052a56b807ea7f00cf1bd0c`;
- log artifact `9053048092`, ZIP SHA-256 `c5c3d964d9210982bfb08d0cf46900308a2498cee9ea2e54879dd35e61cacbd9`;
- manifest **64/64**, SHA-256 `89beb0a12c1051a0fd4d55af6a8ee27e897c0f610045efa8b270a42dc09d51ae`;
- M1g **6/6**, required-green producer **181/181**, complete M1f/M1e/M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean;
- all eight historical/deferred red classes unchanged;
- Bunny known-red and Vase bounded safety-only under run `31394985769`;
- strict-validator characterization **1/10 pass, 9/10 fail**, retaining the existing nondeterministic performance-test defect;
- exact local and remote postflight passed;
- stale per-turn M1h evidence was subsequently consolidated into `.agents/Directional/CHANGELOG.md` and the tracker; the old report was retired under `CLEAN_UP_POLICY.md`.

No new stable regression event or recurrence is assigned. Historical totals at that checkpoint remained **34 / 14 / 20**.

### Historical M1h RP-01 / RP-05 boundary

Accepted-source inspection selected `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart` as the real field-chart owner. The producer created connected equal-orientation charts and carried their identity as bare integers. M1h adopted checked `FieldChartId` there while preserving chart partitioning/numbering and all behavior. The producer/segment authority still carried multiple chart IDs while some output occurrences did not sample every producer chart, which exposed TA-05 rather than a product defect.

## Historical M1h compile/package pattern record

M1h implementation `de4e2ba7c19d2e49931655dc22d758f50656d054` migrated the real field-chart owner `build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart` from bare semantic integers to checked `FieldChartId`, while numeric projection remained at then-existing leaf accesses. The deterministic chart partition/BFS numbering was unchanged. Missing typed lattice chart authority was fail-closed before aggregate front acceptance. Periodic and bounded-disk single-chart lattice states used checked chart zero. The final M1 cutover removes the stored numeric form.

Compile/package authority:

- run/job `31398571348 / 93487537918`, **120/120**;
- result artifact `9066967620`, ZIP SHA-256 `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03`;
- log artifact `9066968049`, ZIP SHA-256 `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816`;
- manifest **69/69**, SHA-256 `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9`;
- six focused M1h contracts compiled and unexecuted;
- all Code + Build runtime flags false;
- packaged sibling `../test-data` resolution correction compiled;
- subsequent test-authority remediation and immutable acceptance are retained in `.agents/Directional/CHANGELOG.md`; the superseded per-turn report was retired under `CLEAN_UP_POLICY.md`.

No new stable regression event or recurrence is assigned. `RP-01 / RP-05` and `RP-02 / TA-05` were subsequently accepted at M1h. `RP-07` remained preservation-only and unchanged.

## Single-authority strategy correction — 2026-08-11

- Review baseline: `fcba2fd9b8905802ca373e0cc88aeccbf38d608a`.
- Reviewed accepted source: M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` from artifact `9083262395`.
- The unimplemented one-field follow-up was rejected after source inspection showed that the remaining duplication spans certificate, topology-region, chart, support, route, periodic, rail, occurrence, quotient, and materializer contracts.
- M1 now ends with one Code + Build turn that installs the semantic model across the complete producer-to-materializer path and deletes every displaced numeric semantic field, reconstruction path, helper bridge, and associated test.
- The cutover must preserve G0–G3 invariants, truthful failure and disposition behavior, determinism, and the accepted M1l product evidence. Representation changes are evaluated by semantic invariants and behavior-oriented contracts, not by exact preservation of obsolete numbering, hashes, or iteration order.
- No generated Directional binary runs in the cutover turn. A following immutable Test + Benchmark turn discovers the resulting inventory, runs all entering gates plus the new semantic contracts, and determines acceptance.
- After immutable acceptance, M1 closes and the primary queue returns to G4 production work. Remaining architecture work is introduced only as a complete vertical contract needed by an active production blocker, not as another representation-only campaign.
- This strategy correction changes no historical regression count: totals at that checkpoint remained **34 / 14 / 20**.

### Current R-A closure review after REV-18 through REV-21

- Exact implementation/test source `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca` was reviewed at branch boundary `922c36b43b8d35af2d2ffdeccb8e0c2ef551c760`; later commits are documentation-only.
- Compile run/job `31625763711 / 94211611771` and artifacts `9153147035 / 9153147459` are authentic partial evidence: Release/static/Ninja/PRE_TEST **118/118**, manifest **25/25**, clean snapshots, and no generated runtime.
- `R-A-REV-22 / RP-02`: final aggregate validation omits strict boundary/feature/chart authority and supplies an empty expected boundary set to an unconditional cycle comparison.
- `R-A-REV-23 / RP-01 / RP-05`: aggregate rebuilding creates a second stitch-key schema, trusts cached kind, and does not prove generated-interior lineages remain consumable.
- `R-A-REV-24 / RP-01 / RP-02`: direct source-authoritative validation can traverse with null typed authority when local-sheet checking is disabled while claiming authority was used.
- `R-A-REV-21 / RP-02`: exact binding code is present, but the required mismatched-authority row-permutation negative and consistent-pair positive are absent.
- These are static migration findings, not stable accepted-product regression events. Totals at that checkpoint remained **34 / 14 / 20** and M1l remains immutable runtime authority.

### Retained prior R-A compile checkpoints and closure-gate review

- Historical REV-01-through-16 findings, remediations, and artifact identities remain in `CHANGELOG.md`.
- Current review inspected exact implementation/test source `1352f3d18eb3821ecda9d74ea5e439adb5bcb875` at branch boundary `356a0bc2733af41e15fad056161e526865c147c5`. The six later commits are documentation-only.
- Bounded REV-17 owner-certificate/canonical-cache remediation and REV-20 compatibility-path removal are retained as compile-valid progress. Run/job `31616904715 / 94181880684` succeeded Release/static/Ninja/PRE_TEST **118/118**; artifacts `9149834162 / 9149834634` remain partial compile evidence with no generated runtime.
- `R-A-REV-18`: the aggregate still has no global owning source-authority product and does not rebuild post-remap vertex/face identity caches. This remains an `RP-01 / RP-05` blocker.
- `R-A-REV-19`: publication remains non-transactional and cached per-component validation substitutes for a final merged-product oracle. This remains an `RP-01 / RP-02 / INCOMPLETE_TRANSACTIONAL_ROLLBACK` blocker.
- `R-A-REV-21`: `complete_for_face_count` and affected consumers accept a foreign same-extent authority because they never compare supplied source-face topology to `topology_for_row`. This is an `RP-01 / RP-02` authority-binding and counterexample-coverage gap.
- These are static review findings, not stable runtime regression events. Overall R-A remains open; M1l remains immutable runtime authority and totals at that checkpoint remained **34 / 14 / 20**.

### Architecture redesign mapping

- Pipeline B is the normative default; Pipeline A is optional and unscheduled.
- New M3 owns the field-aligned curve network.
- Prior M3 becomes M4 global conformity; `G4-B002` is therefore M4-owned.
- Prior M4 becomes M5 certificate-carrying relations.
- Prior M5 becomes M6 occurrence/embedding/verification.
- New M7 owns graded disposition and the declared degraded producer.
- Prior M6 becomes M8 operational hardening.
- Strict product gates require D0 Certified; D1-D3 are explicit product dispositions and never green substitutes.

## Current WU2C stable-ID mapping

| PR event | WU2C ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R035` | `WU2C-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | **resolved** |
| `PR8-R036` | `WU2C-R002` | `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | **resolved** |

## Current M2 stable-ID mapping

| PR event | M2 ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R037` | `M2-CP4-R001` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | **active** |

## Current M3 stable-ID mapping

| PR event | M3 ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R038` | `M3-CP1-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R039` | `M3-CP2-R001` | `CYCLIC_TOPOLOGY_LINEARIZATION` | `RP-07` | resolved |
| `PR8-R040` | `M3-CP2b-R001` | `REPRESENTATION_DEPENDENT_IDENTITY` | `RP-05` | resolved |
| `PR8-R041` | `M3-CP2b-R002` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | resolved |
| `PR8-R042` | `M3-CP4b-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R043` | `M3-CP4c2-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved (R7-REV, 355/355 with ordinal 305 green) |
| `PR8-R044` | `M3-CP4c2-R002` | `REPRESENTATION_DEPENDENT_IDENTITY` | `RP-05` | resolved (R7-REV, 355/355 with ordinal 310 green) |

## Current G4 stable-ID mapping

| PR event | G4 ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R028` | `G4-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R029` | `G4-R002` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | resolved |
| `PR8-R030` | `G4-R003` | `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | resolved |
| `PR8-R031` | `G4-R004` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R032` | `G4-R005` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | resolved |
| `PR8-R033` | `G4-R006` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | test-authority resolved |
| `PR8-R034` | `G4-R007` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | **active** |

`G4-R007` authority remains production artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. M1/M2 migration does not repair or reinterpret it.

## Persistent blockers

| ID | Blocker | Required gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | strict-valid torus 3/3 |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | shared positive rail schedule; revised M4 |
| `G4-B003` | Nonzero periodic Z4 production capability. | M5 relation certificate + representative product acceptance |
| `G4-B004` | Positive multi-isolation quotient witness. | M5/M6 focused + representative certificate evidence |

## Architecture enforcement register

| ID | State |
|---|---|
| `AR-01` | final M1 cutover installs exhaustive `ProducerOutcome<SurfacePhaseFrontProduct>` |
| `AR-02` | M1a through M1l **accepted**; complete R-A closure rejected; REV-18-through-REV-21 bounded compile progress retained; REV-22-through-REV-24 open |
| `AR-03` | final cutover closes strong identity from producer through materializer, including exact/existing stitch-identity validation and no compatibility bypass |
| `AR-04` | final cutover replaces remaining chart, support, route, periodic, rail, occurrence, quotient, and certificate numeric ownership |
| `AR-05` | after cutover, numeric projection is permitted only at a direct Eigen/vector storage or derived export leaf; it is never semantic authority |
| `AR-06` | final cutover installs the complete typed isolation-seam transport certificate; later relation-registry work must be driven by a production blocker |
| `AR-07` | revised M4 publishes one deterministic positive global conformity/flow plan before regional commits |
| `AR-08` | final cutover publishes one immutable producer-scoped phase-front product |
| `AR-09` | final cutover replaces `SurfacePointSourceSupport` with the typed resolved support contract end to end |
| `AR-10` | revised M3/M4/M5/M6/M7 contracts land vertically; module extraction/hardening closes in M8 |
| `AR-11` | normative architecture/status separation maintained |
| `AR-12` | T1 independent oracle/package accepted; T2–T6 expand authority |

## Test architecture register

| ID | State |
|---|---|
| `TA-01` | topology/lineage partial authority accepted; revised D0-D4 disposition and geometry/field/quality remain later gates |
| `TA-02` | T2 ten-case direct matrix pending |
| `TA-03` | metric definitions/baselines pending |
| `TA-04` | T3/T4 generation/shrinking/fuzz pending |
| `TA-05` | **test authority resolved and preserved through M1l** |
| `TA-06` | T1 mutation suite **29/29** accepted and preserved |
| `TA-07` | exact package/discovery authority accepted and preserved |
| `TA-08` | M1a-M1l entering authority accepted; REV-18-through-REV-21 compiled contracts retained only as bounded progress; strict final-oracle, canonical aggregate-identity, direct missing-authority, and permutation-pair contracts remain open |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | existing topology/lineage oracle foundation accepted; M3 network, M7 disposition, and T5 quality mutation evidence remain open |
| `TA-12` | `tests/TESTING_STRATEGY.md` normative only |

## Authoritative next step

Latest accepted runtime authority remains CP4c-1 **355/355**. Latest CP4c-2 semantic runtime is R8 run/job
`33288495471 / 99195869180`: inherited 355/355 PASS, ordinals 356-358 PASS, first red at 359; 360-365 not run.

Current immutable CP4c-2 build authority is CB8 semantic/test source
`05f9ef299ee54f8c9d50318fc9a37e5a5503740d`, GMP package **66** artifact `9726295440`
(`1017a2f40829c171a0ec066b16e1f9f5436588f5e2376742e340ce1617d2556f`), packaged source
`ec9b9b7929521e3f2cd1df4e21beb2f01012f97ff1907ffbf5ae2b35334fd20c`, compile run/job
`33292137782 / 99205507393`, runtime-free. Stable totals remain **44 / 14 / 30**, debt **5**, M3 packages **66**.

Historical next at this point was artifact-only `M3-CP4c-2-TB-X2-R9-EXEC` under the frozen R9 plan now
consolidated in `M3_CP4c_Consolidated_Record.md` §3.7. Run selector 365 from ordinal 1 with the
frozen first-semantic-red hard stop, no benchmark, and AH6 if ordinals 363-365 are reached. No rebuild/repair or
source/test/fixture/selector mutation is authorized.
