# M3-CP4c-3-CB8 Code + Build Plan — Exact Single-Authority Vertex Transit

**Turn:** `M3-CP4c-3-CB8`
**Type:** Code + Build only
**Runtime boundary:** **NO Directional runtime.** No test, benchmark, discovery/list/help/version command, generated executable, or custom runtime input may execute in this turn.

## 1. Objective

Correct the single remaining gated mechanical cause established by `M3-CP4c-3-TB6-REV`:

> `resolve_field_vertex_transit` currently transports an exact branch **label** and then substitutes each target face's local `FieldBranchBoundaryPairing::direction` as `incomingDirection`. The election therefore still tests one representative per cell instead of one continuation datum against a partition.

CB8 must make the continuation a **single exact authority**, make all per-face sector tests certified views of that one datum, publish those views through the production failure diagnostic, strengthen the minimal regression witness, append that witness to a new selector 374, compile/package only, and freeze the next artifact-only TB plan.

Do not combine independent ordinal-370, sphere, saturation, or later-pipeline corrections.

## 2. Frozen invariants

1. Accepted ordinals 1–365 and their selector bytes/hashes are immutable.
2. Existing selector 373 is immutable.
3. `direction_in_vertex_sector` remains exact and half-open; no tolerance is introduced.
4. `FaceInterior` continues to exclude the arrival face.
5. Barrier absorption/incidence and fan reachability semantics do not change.
6. Atlas `signedLift` remains branch-correspondence authority. It must not be misrepresented as an exact continuous transport of an arbitrary geometric ray.
7. No value used in a topological decision may derive from world-space floating-point transport. Certified floating filters are allowed only if they either prove the exact result or defer to exact authority.
8. No candidate-order, identifier, angular-nearest, or magnitude tie-break is permitted.
9. Product and test failures remain fail-closed and typed.
10. Selector changes are append-only: new selector 374 = byte-identical selector 373 prefix + exactly one identity.

## 3. AW0 — source audit before editing

At the exact CB8 source:

- re-read `resolve_field_vertex_transit`, `FieldBranchBoundaryPairing`, `FieldBranchTransportAdjacency`, and `direction_in_vertex_sector`;
- enumerate every writer/reader of `incomingDirection` and transit audit fields;
- verify that current state transitions assign `incomingDirection = nextPairing->direction`;
- verify that atlas `signedLift` maps face-gauge branch labels but does not publish an exact arbitrary-ray transport;
- verify production diagnostic loss remains at `network_failure_locus` / `SurfaceCellFailureLocusDiagnostics`;
- verify the minimal witness identity exists and is absent from selector 373.

If any premise differs, stop semantic editing and reconcile it in the CB report before proceeding.

## 4. AW1 — introduce one exact transit datum

The continuation must have exactly one semantic writer at the arrival event. Every reachable fan state may hold a **projection/view** of that datum, but may not replace it with a local field representative.

The implementation may use an exact common vertex/fan chart or another exact representation that proves the same invariant. It must publish enough provenance to establish:

```text
one transit datum ID/value
    -> exact/certified state projection for face F0
    -> exact/certified state projection for face F1
    -> ...
```

Each state projection must be derivable from the single datum and source/atlas authority without an uncontrolled `double` round-trip.

### Required stop rule

If the existing source/atlas products cannot express an exact/certified projection of the same datum across the non-coplanar fan, **do not** fabricate transport from the target face's cross representative or from `signedLift`. Stop the semantic change, keep the build/runtime boundary intact, and report the missing authority precisely. A compile-green architectural-blocker report is preferable to a second false implementation of Amendment 17.

## 5. AW2 — election consumes only the single datum

`resolve_field_vertex_transit` must:

1. create the single transit datum once;
2. walk the same existing reachable `(face,branch)` fan states;
3. derive a state-local sector-query view from the one datum;
4. use that view for `direction_in_vertex_sector`;
5. retain each face's `pairing.direction` only as an audit/reference value;
6. deduplicate the same way as current source; and
7. still require exactly one elected continuation.

The old mechanism is explicitly falsified when a state can become eligible merely because its own local `pairing.direction` lies in its own sector.

## 6. AW3 — production transit audit survives the pipeline boundary

Close `M3-CP4c3-TB6-CAND-01` without changing topology semantics.

Extend the production diagnostics so ordinal 366 can serialize the transit audit currently retained only in `FieldAlignedCurveNetworkError::vertexTransitStates`. Avoid an include/dependency cycle: use a diagnostics-layer DTO or an equivalent serialized audit structure owned by the diagnostics API, not a geometry-header type embedded blindly in `RemeshDiagnostics.h`.

At minimum publish per examined state:

- source face and branch;
- typed state outcome;
- exact single-datum identity/value or stable exact digest;
- exact state projection used by the sector predicate;
- local representative direction for comparison/audit only;
- transport edge/path and composed quarter-turn;
- `eligibleForElection`;
- `representativeInSector`;
- `incoming/singleDatumProjectionInSector`;
- whether this state contributed the final candidate.

The production exception must be sufficient to distinguish "one datum projects to one unique sector" from "each face supplied its own datum" without re-running a test-only helper.

## 7. AW4 — strengthen the minimal regression witness

Keep the exact identity:

`ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState`

Strengthen its assertions so it is a real Amendment-17 regression identity. The fixture must be minimal, deterministic, and self-checking. It should establish a fan where:

- local per-face cross representatives are not all the same geometric ray;
- the chosen single transit datum has exactly one half-open sector owner;
- the resolver either produces that unique continuation or a typed failure whose audit proves the single-datum invariant;
- the test fails under the former `incomingDirection = nextPairing->direction` mechanism.

Do not weaken the test into "some diagnostic exists."

## 8. AW5 — selector 374 governance

Create `Architecture_M3_CP4c3_Required_Green_Selector_374.txt` by copying selector 373 **byte-for-byte** and appending exactly:

`ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState`

Requirements:

- old selector 373 remains untouched;
- ordinals 1–373 are byte-identical and in the same order;
- new identity is ordinal 374;
- record SHA-256 for 373 and 374 in CB evidence;
- selector 374 is future required-green authority; it does not retroactively alter TB6 or accepted selector 365.

## 9. AW6 — targeted static verification, no runtime

Before compile:

- search proves no topological decision path in vertex transit assigns the one transit datum from `nextPairing->direction`;
- search proves no world-space `double` conversion/transport feeds `direction_in_vertex_sector`;
- search proves every suppressing transit path still emits typed audit state;
- source diff proves no `FaceInterior`, barrier, sector-predicate, tolerance, sphere, cut-graph, saturation, or accepted-selector semantic edit;
- `git diff --check` passes.

These are source audits, not executable runs.

## 10. AW7 — compile/package contract

Use the mandatory reusable compile workflow with GMP enabled and its default eight standard targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Required evidence:

- `runtimeExecution=false`;
- `DIRECTIONAL_ENABLE_GMP=ON`;
- generated authoritative link evidence includes both GMPXX and GMP;
- all eight targets compile/link;
- source status clean;
- exact source archive and hashes packaged;
- no executable is invoked.

Construct the next immutable mode-preserving package from that exact compile artifact without replacement compilation or package repair. Preserve package-relative fixtures, executable modes, manifests, selector 374, and all source/evidence hashes.

## 11. AW8 — frozen next artifact-only TB contract

CB8 must draft the next immutable TB plan. It must:

1. consume only the new immutable package;
2. verify source/package/GMP/manifests/fixtures/executable modes and selector 374 before runtime;
3. run one exact identity per fresh process from ordinal 1;
4. hard-stop gate credit at the first red;
5. after the gate verdict is fixed, execute every remaining ordinal through **374** exactly once report-only with zero gate credit;
6. perform no rebuild, relink, package repair, source/test/fixture/selector mutation, generated discovery/list/help/version command, or benchmark;
7. preserve immutable postflight evidence.

### Required ordinal-366 discriminator

If 366 passes, record the next failure stage/locus. If 366 remains `VertexTransitSectorUnresolved`, production diagnostics must prove:

- the one exact transit datum authority;
- every state projection derived from it;
- the unique or non-unique sector result;
- the exact reason candidate cardinality is not one.

A mere `publishedFaceCount` is no longer sufficient evidence.

Ordinal 374 must execute even if first red remains 366, but then it is report-only and earns zero gate credit.

## 12. AW9 — closeout and explicit non-scope

CB8 report must state:

- whether the exact single-datum representation was successfully established or hit the AW1 stop rule;
- exact changed paths and source owner;
- selector 373/374 hashes and append-only proof;
- compile/package identities and GMP/runtime-free evidence;
- stable accounting remains **44 / 14 / 30** unless accepted-green behavior is actually lost in a later TB;
- produced-witness debt remains **5** unless a produced witness truly closes debt;
- ordinal 370 remains independently owned by `SurfaceCutGraph::canonical_candidate` and unmodified;
- sphere `NoCarrierMatch / SourceEdgeUnavailable` and saturation remain deferred and unmodified.

## 13. Explicit prohibitions

No Directional runtime in CB8. No first-candidate selection. No tolerance. No world-space float transport into topology. No per-face representative substitution. No `signedLift`-as-geometric-ray claim. No `FaceInterior` cardinality change. No barrier widening. No sphere fix. No ordinal-370 fix. No saturation change. No selector reorder/removal. No acceptance claim from compile/package evidence.
