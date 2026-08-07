# Surface Cell Backend Remediation Plan

## Current blocker

G0, G1, and G2 are closed. G3 periodic authority is now live on the exact production cylinder, but G3 remains incomplete at **completed output validation**.

Exact artifact `9001168379` from source `56f823273cad041a01ebb4d0772c3265ff248f4a` produces:

- authoritative `Produced`;
- periodic holonomy `r=0`, `t=(29,0)`, route 32 edges, cut four edges;
- 2,163 source-attached traces;
- zero generic arrangement cells;
- 290 completed direct quads;
- 319 provenance vertices;
- no fallback/recovery;
- deterministic 3/3.

The completed checkpoint then reports exactly two validation failures at `completion/output-validation:AggregateCompletionValidationFailure`. Final output is therefore correctly withheld. The benchmark record does not expose the two individual failed validation fields, so no threshold-specific diagnosis is authoritative yet.

## Proven producer foundation

Retain without redesign:

- first-class `NotApplicable / Produced / Rejected` authority;
- no generic substitution after `Rejected`;
- local lattice phase/integer coordinates;
- reciprocal ordinary-edge and ordered source-vertex transport;
- complete source route provenance;
- component/local-sheet isolation;
- topology-derived singularity-free annulus applicability;
- deterministic intrinsic source cut;
- periodic holonomy `(Z4 rotation, Z2 translation, ordered source route)`;
- explicit `PeriodicFrontMerge` ownership;
- exact periodic quotient identity;
- direct one-cell-to-one-quad materialization;
- fail-closed source-authoritative validation.

Plane, seam, and close sheets remain mandatory direct regressions and are green in the G3 artifact.

## Active structural correction

Execute `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Plan.md`.

### Source-strip-conforming periodic lattice

The current periodic chart may choose a global target-size column count whose lattice columns do not coincide with every canonical source-ring corner. Direct straight-sided cell materialization can therefore shortcut a source strip boundary even when the corresponding phase-front route remains source-attached.

Correct this upstream:

1. use the canonical annulus ring/strip ordering already derived from topology;
2. make every source-ring strip boundary a mandatory intrinsic lattice breakpoint;
3. compute a positive deterministic subdivision count independently for each strip from intrinsic strip length and target size;
4. accumulate those subdivisions into the periodic lattice coordinate so holonomy translation remains integral and source-topology-compatible;
5. preserve cut duplicates and periodic ownership through exact lattice identity;
6. ensure each output side lies inside one source strip or terminates at a canonical strip breakpoint;
7. keep one accepted cell → one quad.

Do not special-case the committed cylinder's source-ring count, the observed translation `29`, or expected output counts. Do not repair the result after materialization.

### Row-order regression correction

`PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` compares raw DCEL edge IDs even though DCEL edge numbering depends on face-row traversal. Artifact evidence proves the ordered source-edge endpoint routes/cuts are identical after canonical mapping.

During the next Code + Build turn, change the test to map each mesh's route/cut edge IDs through its own EV table to `(min(v0,v1), max(v0,v1))` and compare those ordered key sequences. Preserve grid, rotation, translation, cardinality, and route-order assertions. Production code must not be changed merely to stabilize incidental DCEL IDs.

## Verification sequence

The next turn is Code + Build only:

1. make the minimum source-strip-conforming producer correction;
2. correct the structurally invalid raw-ID test expectation;
3. preserve existing G0–G3 authority and cylinder acceptance assertions;
4. configure with `PRE_TEST` and compile the seven approved targets;
5. execute no generated project binary;
6. package the exact artifact for the following artifact-only Test + Benchmark turn;
7. remove temporary workflow/trigger/payload after artifact/log verification.

## G3 acceptance

G3 closes only if the following artifact-only validation proves exact cylinder is direct deterministic strict-valid `Produced` `CompletedSurfaceCells` pure-quad output with correct periodic quotient, complete provenance, zero validation failures, no fallback/recovery, and retained plane/seam/close-sheet success.

## Deferred work

Do not broaden the active correction into:

- torus/general genus;
- singularities or G4 topology-distinct completion;
- adaptive 2:1 transitions;
- hard-feature expansion;
- bunny/vase production/performance;
- scheduler timing;
- historical downstream completion/simplification repair;
- broad diagnostics or validator changes unrelated to G3 structural correctness.

## Acceptance discipline

No validator weakening, fixture special cases, generic-producer substitution, fallback/recovery, positional sheet merging, Euclidean periodic seam welding, arbitrary subset search, synthetic topology correction, post-hoc cycle/cell merging, or timeout-as-correctness is allowed.