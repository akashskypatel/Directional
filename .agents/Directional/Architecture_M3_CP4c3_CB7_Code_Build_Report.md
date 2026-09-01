# M3 CP4c-3 CB7 — Amendments 18/19 Code + Build Report

Date: 2026-09-01 UTC
Turn: `M3-CP4c-3-CB7`
Status: **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE**

## Authority

- Review authority: `Architecture_M3_CP4c3_TB5_Independent_Review_Record.md`, measures **AU0–AU9**.
- Starting semantic source: `5ac1d0ba8b965ed14318f5883d88ec84ca2d9c7a`.
- Final semantic/evidence source: `e926ada023bc51220628be550bbe9a87f98d7067`.
- Patch-apply run: `33455395648`; exact staged patch SHA-256 `943ca5fa2d0f47ff185d88f04c86b351cdd6c9bb70a9367b6992dbfba3a6e668`.
- Authoritative compile run/job: `33455549602 / 99694672138`.
- Raw compile result artifact `9781459057`, Actions SHA-256 `e66ff9cbb04a586a8862ceb40ee9e0651741a4588ab8fcd8caf2fc2a8c1fcbba`.
- Raw compile log artifact `9781459549`, SHA-256 `5fea70b8a6bed7190eadeda827cafcee6e160b76a6508b83b349e3e31149c2b9`.
- Packaged source archive SHA-256 `64e5189f3c9f22d648e496c50b4093e842a0fad25a885dca65778d7a110b629a`.
- Mode-preserving package **75**: run/job `33456115934 / 99696350077`, artifact `9781487311`, Actions SHA-256 `547f2441b026b68d2bef10e7c7694faf994be473a1d2db68a6375d06b1e654b8`.
- Inner `package75.tar.gz` SHA-256 `8814b700a5c07290ce099ce1f719f01b2fbd5bcfd80f36037fe5bafc600f7896`.
- Package log artifact `9781487686`, SHA-256 `ad8327ca35a27c3ddde0930f36f17e144198550f1f3d9a6e0ba6d5ebfcf19a2a`.
- Frozen selector **373** remains byte-identical at `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.

No generated Directional executable, test, benchmark, discovery/list/help/version command, CLI, fuzzer, custom input, or gate identity executed in CB7. Compile/package evidence records `runtimeExecution=false`.

## AU0 — frozen authority and boundary

Only `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, and `tests/FieldAlignedCurveNetworkTests.cpp` changed in the semantic commit. No selector byte changed. Retained predecessor hashes remain:

- 357 `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
- 358 `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` — exact-hash/cardinality/set-subset authority, not a byte-prefix relation
- 361 `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`
- 365 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- 367 `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`
- 370 `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525`

`selected_gate=NONE`; `gate_execution_authorized=false`.

## AU1 — every transit exit is typed and reportable

`resolve_field_vertex_transit` no longer has a silent seed/drop path. Two appended error codes distinguish the cases the review required without renumbering any existing value:

- `VertexTransitSeedUnavailable = 31` — the first exact state could not be constructed;
- `VertexTransitWalkUnexamined = 32` — a seed existed but no state reached the sector predicates.

`FieldVertexTransitStateOutcome` records typed reasons before every conditional that can suppress a state: missing/mismatched seed frame, missing/ambiguous pairing, non-barycentric exact direction, duplicate state, missing/mismatched state authority, unavailable source-face row, missing directed transport, and missing/mismatched/ambiguous/non-barycentric target transport state. `FieldVertexTransitStateDiagnostic` now permits absent directions where no direction exists, carries the offending transport edge, path and composed quarter-turn, and is attached to every typed failure.

This closes the specific reportability defect that made TB5's vertex-11 stop look like a sector election even though no state was examined. Runtime disposition is deliberately deferred to TB6.

## AU2 / AU3 / AU4 — exact transit datum; Amendment 17 measurable, not accepted

The world-space round-trip helpers were removed from the transit decision path. The seed carries the arrival pairing's exact `FieldBranchDirection`. For each adjacency, the atlas's exact `signedLift` rotates the branch label; the target frame's corresponding exact rational branch direction becomes the continuation datum for that transported state. No value reaching either `direction_in_vertex_sector` call has passed through a `double`.

Each evaluated state publishes:

- transported branch label;
- exact representative and incoming `FieldBranchDirection` values;
- transport path and composed quarter-turn;
- `eligibleForElection`, `representativeInSector`, and `incomingInSector`.

Election still uses `incomingInSector` exactly as Amendment 17 specified. CB7 does **not** add a tie-break, select the first candidate, reorder faces, alter the half-open sector convention, change `FaceInterior`, or introduce a tolerance. Therefore Amendment 17 is now measurable again but remains **unaccepted until TB6**. Its falsifier remains binding: equal elected directions at a multi-candidate locus route to review.

## AU5 — assumption-driven audit

Both required predicates were searched outside `resolve_field_vertex_transit`.

1. **“A value reaches a topological decision after floating point.”** `field_aligned_compare_arrivals` is an outside-site example deliberately using floating point as a **certified interval filter**: it orders only when the two error intervals are disjoint and otherwise returns `Inconclusive`. That is compliant with Amendment 18 because the filter cannot manufacture an approximate ordering. By contrast, the transit path had no such proof/defer contract, so its double round-trip was removed rather than retained as a filter.
2. **“A producer can exit without recording a typed reason.”** `field_aligned_next_face` is an outside-site optional helper whose empty result can represent no/ambiguous adjacency, but the canonical trace producer immediately converts that result into trace-scoped `InvalidCandidateTraceTransport` with face/branch/carrier provenance. The helper is not itself the typed product boundary; the producer exit is reportable. This contrast is the standard CB7 now applies inside vertex transit itself.

No broader refactor was made from the audit; the findings were used to test the two assumptions rather than to expand scope.

## AU6 — sphere binding evidence only

The CP4c witness report now publishes, on cut-graph/event-position failure:

- the claimed `sourceEdge` or `none`;
- whether the claimed trace exists;
- counts of that edge on the trace's incoming and outgoing segment carriers;
- whether the claimed edge is available anywhere on that trace;
- the already-published trace-event-position pass/reason.

No sphere semantic correction was designed or applied. TB6's report-only pass must consume these fields before any successor definition turn settles the binding contract.

## AU7 — ordinal-370 witness only

`SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` no longer constructs the invalid globally-constant zero-transport torus field. It loads the existing `milestone-g/torus.rawfield` fixture and finalizes it through the production raw-cross-field path before atlas construction. The witness intent remains unchanged: closed surface, empty rails and empty network, so the product's intended typed empty-network rejection can finally be measured. The atlas's `NonIntegralCycleLift` rejection was not weakened.

## AU8 — cadence and minimal witness

A small `ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState` source test was added and compiled. It uses the existing four-triangle fan and exact synthetic field, calls the transit routine directly, and requires a real decision or a typed, non-empty evaluated diagnostic state rather than the old silent seed/walk failure.

The successor TB6 plan also implements the cadence change: after the first-red verdict is fixed, **every remaining ordinal through 373** executes exactly once report-only with zero gate credit, rather than only 367–373.

## AU9 / compile and immutable package verification

The reusable compile built and linked all eight standard targets with `preflight-exit-code=0` and `build-exit-code=0`. The exact evidence package records `exactArithmeticBackend=GMP`; generated link evidence contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`. Source status is clean and the source archive is the exact semantic commit above.

Package 75 was constructed from raw artifact `9781459057` without replacement compilation. Its self-excluding manifest verifies **57** files, exactly 27 package-relative fixtures are present, all six test/benchmark executables clean-extract at mode `0755`, and the envelope records `modePreservingEnvelope=true`, `packageRepair=false`, `runtimeExecution=false`.

No prohibited selector, barrier, sector, tolerance, atlas-rejection, sphere-fix, Amendment/P2, runtime, gate, or benchmark change occurred.

### Process-conservation note

At the start of CB7, one policy file was fetched before `READ_MODE=snapshot` was explicitly frozen. Execution stopped at that point, the exact source-snapshot path was then established, and all source derivation/patching used the verified snapshot. This is preserved as a process miss rather than normalized away; it did not alter semantic source or runtime evidence.

## Accounting and verdict

No Directional runtime executed, so stable regression accounting remains **44 events / 14 categories / 30 recurrences** and produced-witness debt remains **5**. CB7 advances authoritative semantic M3 package accounting **72 → 73**; package label **75** is the new immutable semantic package envelope.

`M3-CP4c-3-CB7` is **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE**. CP4c-3 remains open because Amendments 17–19, the repaired ordinal-370 witness, sphere binding publication, and the minimal transit witness have not yet been consumed by runtime.

## Mandatory successor

Execute **`M3-CP4c-3-TB6`**, artifact-only on immutable package **75**, under `Architecture_M3_CP4c3_TB6_Artifact_Only_Test_Benchmark_Plan.md`. Start the frozen selector at ordinal 1 with first-red hard stop. After the gate verdict is fixed, execute **every remaining ordinal** through 373 once report-only with zero gate credit. Do not repair, rebuild, relink, mutate package/source/test/fixture/selector bytes, or benchmark inside TB6.
