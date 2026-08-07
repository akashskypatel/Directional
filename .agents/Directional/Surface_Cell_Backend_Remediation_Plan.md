# Surface Cell Backend Remediation Plan

## Current blocker

G0, G1 and G2 are closed. The production G3 periodic cylinder contract is now runtime-satisfied on artifact `9010838200`. Formal G3 closure is blocked only by one incorrect unit-test witness requirement, not by production behavior.

Current runtime authority: source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`, artifact `9010838200`.

Exact cylinder:

- `Produced` / direct `CompletedSurfaceCells`;
- holonomy `r=0`, `t=(32,0)`, route 32, cut 4;
- 1,728 traces;
- 290 arrangement / 290 simplified cells;
- 288 completed/output pure quads;
- 320 provenance/output vertices;
- validation failures 0;
- field P95 `8.537736463e-07°`;
- output hash `32135be51d7a0a26`, deterministic 3/3;
- exactly two true 32-edge annulus boundary loops;
- no fallback/recovery.

This restores periodic `Produced` authority from the preceding `InvalidPeriodicChart` cell-29 regression and improves the earlier 37.967° field-P95 failure to effectively zero.

## Proven producer foundation

Retain without redesign:

- first-class `NotApplicable / Produced / Rejected` authority;
- no generic substitution after `Rejected`;
- local phase/integer lattice state;
- reciprocal source-edge and ordered source-vertex transport;
- complete source-route provenance;
- component/local-sheet isolation;
- topology-derived singularity-free annulus applicability;
- deterministic intrinsic cut between true boundaries;
- periodic holonomy `(Z4 rotation, Z2 translation, ordered source route)`;
- explicit artificial-cut ownership and exact quotient identity;
- canonical source-strip breakpoints/per-strip target subdivisions;
- field-authoritative adjacent-ring correspondence with typed ambiguity rejection;
- canonical periodic-chart source-simplex endpoint representation;
- direct one-cell-to-one-quad materialization;
- strict source-authoritative validation.

Plane, seam and close sheets remain mandatory direct regressions and are green.

## G3 endpoint canonicalization — runtime proven

Artifact `9010838200` proves:

- tolerance-based chart ownership no longer emits tolerance-expanded source-geometry tails;
- exact source-simplex endpoint canonicalization contract passes;
- genuine overlap beyond a shared endpoint remains rejected by the unchanged strict predicate;
- all six nominal G3 periodic contracts previously blocked by `InvalidPeriodicChart` are restored;
- direct cylinder passes existing strict validation with zero failures.

Do not change `validate_closed_boundary_paths()` or `segments_intersect_beyond_shared_endpoint_2d()`.

## Formal closure blocker — test witness correction only

Raw focused result is **16/17**. The sole failure is `PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`, which reaches `Produced` and then asserts `exactInterRingEdges > 0`.

That expectation is invalid for its own target subdivision:

- source ring spacing `0.5`;
- target `0.25`;
- two V-family front steps per source inter-ring edge;
- no one front edge can have two distinct exact source-ring-vertex endpoints.

The fixture still creates the intended axial-versus-diagonal correspondence scenario and must be retained. The witness must become subdivision-invariant.

Required corrected test contract:

1. inspect nonzero source-attached V-family phase-front boundary-path segments;
2. require valid face+barycentric source provenance;
3. reconstruct source-space start/end positions;
4. reconstruct/project the local authoritative V cross-field axis in the same source face;
5. assert absolute directional alignment within a justified numerical tolerance;
6. require at least one qualifying segment;
7. ignore only truly zero-length segments;
8. retain the typed genuinely field-equivalent ambiguity test unchanged;
9. do not depend on source IDs, DCEL IDs, gridV, output counts, discovery order, or exact segment cardinality.

The known diagonal/sheared correspondence remains ~37.967° from the axial family and must fail this semantic contract.

## Required next turn

Execute `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Plan.md` as Code + Build only.

Expected production source change: none.

- Correct the invalid test witness only.
- Compile the same seven approved targets with Release static / Ninja / `PRE_TEST`.
- Execute no generated project binary.
- Package exact source/test/blob/patch/log/checksum authority.
- Remove temporary workflow/trigger/payload after verification.

The following artifact-only validation must rerun the 17 focused/retained contracts and exact plane/seam/close-sheet/cylinder direct cases. If the corrected test passes and cylinder retains the strict-valid runtime closure above, formally close G3 and activate G4.

## Supporting evidence

- focused/retained: 16/17 raw; sole failure incorrect expectation;
- bounded producer: 99/101, with only the incorrect witness and scheduler-sensitive validator-overhead performance check;
- completion/simplification: 154/164;
- validation: 60/60;
- compiled API: 8/8.

The current turn is material progress, so the no-progress counter resets and mandatory Review is not triggered.

## Deferred work

Do not broaden the formal G3 closeout into torus/general genus, G4 singularities/topology-distinct completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production/performance, scheduler timing, historical downstream completion/simplification repair, validator changes or unrelated diagnostics/optimization.

## Acceptance discipline

No validator weakening, fixture special cases, count/order/frequency ownership selection, generic-producer substitution, fallback/recovery, positional sheet merging, Euclidean periodic seam welding, arbitrary subset search, synthetic topology correction, post-hoc cycle/cell merging, or timeout-as-correctness is allowed.
