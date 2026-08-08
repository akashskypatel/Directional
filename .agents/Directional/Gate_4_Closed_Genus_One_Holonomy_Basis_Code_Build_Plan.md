# Gate 4 Closed-Genus-One Holonomy Basis — Code + Build Plan

## Turn boundary

This is **Code + Build only**. G3 periodic closure / holonomy is passed by exact artifact `9013161456`. Do not execute any generated Directional binary, test, benchmark, ctest/discovery command, CLI/GUI command, help/list command, or custom input during this turn.

Use the current branch source. Production source entering G4 remains runtime-proven `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`; the later evidence commit `117620ec2da2083ce11b205835e58fa404f163ef` changes only the corrected G3 unit-test witness.

## Required design declaration before editing

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: torus__surface_cells rejects at tracing/phase-front with InvalidPeriodicTopology after one authoritative periodic relation is already present
Missing design contract: the result-level phase-front authority can represent and consume only one SurfacePeriodicHolonomy, so a second compatible periodic sheet/topology relation is rejected before tracing even though closed genus-one topology requires retaining multiple nontrivial periodic relations
Smallest general implementation change: replace the singular result-level periodicHolonomy assumption with a deterministic source-topology/reciprocal-transport-derived collection of periodic relations, canonicalize and validate the collection without discovery-order ownership, and make hashing/diagnostics/materialization consume every retained compatible relation while preserving the one-relation annulus contract
Observable material-progress condition: the exact torus no longer rejects solely because a second authoritative periodic relation exists and advances under truthful multi-relation periodic authority, while all G0-G3 focused contracts and plane/seam/close-sheets/cylinder behavior remain unchanged regressions
Explicitly deferred work: prescribed-sphere singularity completion after the torus topology slice, G5 adaptive scale/hard-feature expansion beyond what is required to preserve current source barriers, G6 bunny/vase production, scheduler timing, historical completion/simplification failures unrelated to the active torus contract, validator changes, and unrelated optimization
```

## Exact evidence entering the turn

G3 closure artifact `9013161456`:

- artifact SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- source/test evidence `117620ec2da2083ce11b205835e58fa404f163ef`;
- runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- focused/retained contracts **17/17**;
- cylinder direct `Produced / CompletedSurfaceCells`, holonomy `r=0, t=(32,0)`, route 32, cut 4, 288 pure quads, 320 vertices, zero validation failures, output hash `32135be51d7a0a26`, deterministic 3/3, no fallback/recovery;
- plane/seam/close sheets retain their accepted direct deterministic hashes.

Current G4 observations from that exact artifact:

### Torus

- source: connected closed genus-one triangulation, 72 V / 144 F, Euler characteristic 0, no source boundary;
- runtime producer: `Rejected`;
- first invalid stage/reason: `tracing/phase-front / InvalidPeriodicTopology`;
- terminal: `NotProductionReady:tracing`;
- zero traces/arrangement/completion/output;
- no fallback/recovery;
- partial phase-front authority already reports periodic rotation `0`, translation `(24,0)`, route 24, cut 2.

### Prescribed sphere

- producer `NotApplicable`;
- 766 traces, 30 arrangement/simplified cells, zero completion;
- terminal `NotProductionReady:completion`;
- repeated-boundary-node / parity-alternative exhaustion at completion.

Sphere remains a later G4 slice because torus fails at the earlier tracing/phase-front contract.

## Source diagnosis

Current first-class representation:

- `SurfacePhaseFrontResult` contains exactly one `SurfacePeriodicHolonomy periodicHolonomy`;
- each `SurfacePeriodicHolonomy` carries source component/sheet, quarter-turn rotation, integer lattice translation, ordered source route, and cut route;
- `build_uniform_phase_front()` aggregates sheet-local producers;
- when `local.periodicHolonomy.enabled` and `result.periodicHolonomy.enabled` is already true, aggregation immediately returns typed `InvalidPeriodicTopology`;
- structural hashing serializes only that one relation;
- `materialize_phase_front_mesh()` looks up only that one relation for a sheet and supports a singular periodic-U quotient;
- diagnostics expose only that singular relation.

The first change must therefore be at the **authority representation and consumption boundary**, not a local bypass of the rejection branch.

Do not assume from the current torus failure alone that every observed local relation is an independent fundamental generator. The implementation must distinguish compatible, equivalent/dependent, and conflicting periodic relations from source topology and reciprocal field transport. Discovery order, source IDs, candidate count/frequency, or world-space proximity are not authority.

## Required implementation contract

### 1. First-class multi-relation periodic authority

Replace the singular result-level periodic assumption with one authoritative collection, e.g. a canonical `periodicHolonomies`/periodic-relation set owned by `SurfacePhaseFrontResult`.

Each retained relation must continue to carry:

- source component;
- source local sheet;
- quarter-turn rotation in Z4;
- integer lattice translation in Z2;
- ordered reciprocal source route;
- exact cut source edges.

Do not leave two competing sources of truth. If compatibility fields are retained temporarily for API/diagnostic stability, they must be derived views of the collection rather than independently mutable authority.

### 2. Canonical relation identity and equivalence

Define a deterministic canonical relation signature from existing source/transport authority. It must be invariant to face-row enumeration and local producer discovery order.

The signature/equivalence decision may use canonical source-route/cut topology, source component/sheet authority, transported branch rotation, and integral lattice translation. It must not select ownership by:

- source vertex numeric ID alone;
- lexicographic candidate discovery order;
- relation count/frequency;
- arbitrary subset search;
- Euclidean proximity or seam welding;
- fixture identity or expected torus cardinality.

Equivalent orientation-reversed descriptions of the same source cycle must canonicalize to one relation rather than becoming two accidental generators.

### 3. Compatibility / independence validation

When a new relation is aggregated:

- exact duplicates/equivalent reverse descriptions canonicalize deterministically;
- source-incompatible or reciprocal-transport-inconsistent relations fail closed with a typed periodic reason;
- relations whose lattice/rotation action conflicts with already retained source authority fail closed;
- multiple compatible relations are retained instead of rejected merely because one relation already exists.

If the source representation permits multiple relations for one source sheet, determine whether they are independent or dependent through source-route/topology plus integral transport authority; never choose one by ordering. A genuinely ambiguous basis must fail closed with a typed reason.

The initial G4 slice does not need a generic high-genus solver, but its representation must not structurally cap the result at one relation.

### 4. Every retained relation must be consumed

Update all first-class consumers together:

- `SurfacePhaseFrontResult` validation;
- structural hashing;
- diagnostics and deterministic state comparison;
- phase-front front-pairing/periodic event authority where relevant;
- `materialize_phase_front_mesh()` relation lookup and exact lattice quotient;
- provenance checks;
- expected vertex/boundary accounting.

A relation stored only for diagnostics does not count as material progress.

For a sheet with exactly one annulus relation, behavior must be bit/semantically equivalent to passed G3 authority.

For multiple relations, quotient only through exact source/phase/lattice identity. Do not weld by Euclidean position. Preserve genuine source boundaries; never turn an artificial cut into exterior output.

### 5. Preserve source-sheet authority

Multi-relation support must not weaken G2 local-sheet isolation. Different `(source component, source sheet)` relations remain separate unless exact source topology/feature/route authority establishes the required connection. Positional merging across sheets remains prohibited.

Do not solve the torus by deleting hard-feature/source-sheet barriers or by reclassifying all faces into one sheet merely to avoid the second relation. G5 feature expansion is deferred; current authoritative barriers must remain truthful.

## Typed failures

Add or refine typed periodic failure reasons only where the existing `InvalidPeriodicTopology` is too coarse to express a new fail-closed contract. Examples may include dependent/ambiguous periodic relation basis or incompatible periodic relation transport.

Do not create diagnostics solely to make tests pass. Any new reason must correspond to an actual producer invariant and remain first-invalid authority.

## Required compile-only regression tests

Add focused tests that compile but are **not executed** in this turn. Tests must exercise semantics rather than exact historical counts.

Required coverage:

1. **Multiple compatible periodic sheet relations are retained** — a topology/source setup producing more than one valid periodic relation must not reject merely because a prior relation exists; every relation has source/route/translation authority.
2. **Relation aggregation is invariant to face-row/sheet-work enumeration** — compare canonical source/topology relation signatures, not raw transient IDs.
3. **Equivalent/reversed relation descriptions canonicalize** — do not create duplicate generators from orientation reversal.
4. **Conflicting relation transport fails closed** — deliberately inconsistent reciprocal rotation/translation/route authority yields a typed periodic rejection.
5. **Ambiguous/dependent basis does not choose by order** — if no unique authoritative relation basis can be established, reject with typed authority rather than selecting `front()`/first/count/frequency.
6. **Single-annulus G3 authority is retained** — cylinder periodic relation, source-strip breakpoints, artificial-cut pairing, endpoint canonicalization, field-authoritative correspondence, and malformed-holonomy failures remain compile-covered.
7. **Passed G0-G2 contracts remain compile-covered** — plane, close-sheet isolation, source-vertex fan traversal, transition rejection, embedded-only relief behavior.
8. **Exact torus production-boundary regression** — add/retain a test that enters the real committed torus production preprocessing and checks the new multi-relation producer boundary without fixture-specific relation counts. The following artifact-only turn decides runtime success.

Do not hardcode current `(24,0)`, relation count, source face IDs, output quad count, or exact torus stage counts as acceptance constants.

## Compile gate

Compile the established seven approved targets in Release static / Ninja with compile-only-safe discovery behavior:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Execute no generated project binary.

Package immutable source authority, patch SHA, relevant final blobs, five executables, two project libraries, 27 fixture/input files, configure/build/toolchain logs, compile commands, `runtimeExecution=false`, and recursive checksums. Upload a separate detailed log artifact unconditionally.

Use at most one bounded workflow/payload. After exact source/build/log/artifact authority is verified, remove/disable the bounded workflow before deleting its trigger, then remove the payload. Final branch workflow state must again contain only durable `.github/workflows/agent-source-snapshot.yml`.

## Following artifact-only acceptance

The next Test + Benchmark turn must first verify artifact integrity, then rerun all **17/17 G3 focused/retained contracts** and direct plane/seam/close-sheets/cylinder regressions.

Then run exact torus.

### Material-progress acceptance for this first G4 slice

At minimum:

- torus must no longer reject solely because a second compatible periodic relation exists;
- the new periodic-relation collection must be populated, canonical, deterministic, and consumed by downstream authority;
- no retained relation may be selected by ID/order/count/frequency/proximity;
- no fallback/recovery;
- G0-G3 remain green.

A direct strict-valid torus `Produced / CompletedSurfaceCells` result is the preferred G4 topology closure outcome. If a new, deeper truthful torus invariant fails after the multi-relation contract is demonstrably live and consumed, classify that as material architectural progress and make that earliest invariant the next G4 slice. Do not call the whole G4 gate passed until required topology and singularity fixtures complete directly.

After torus topology is closed, return to the prescribed sphere's singularity/completion contract. Do not preempt the active torus slice with the ten historical completion/simplification failures unless exact G4 evidence proves one is the direct cause.

## Review decision

Optional Review is skipped (`review policy: never`). This plan is authoritative for the next Code + Build turn.
