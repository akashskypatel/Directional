# Gate 3 Periodic Cylinder / Holonomy — Artifact-Only Test + Benchmark Plan

## Turn boundary

This is an **artifact-only Test + Benchmark** turn.

Use exactly:

- artifact ID: `9001168379`
- artifact name: `g3-periodic-cylinder-code-build`
- artifact SHA-256: `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`
- source commit: `56f823273cad041a01ebb4d0772c3265ff248f4a`
- expected recursive checksum entries: **44/44**
- successful build run/job: `31196268841` / `92925122791`
- detailed log artifact: `9001167184`
- detailed log SHA-256: `fdd873fe4e0980ddf8613bd04b3be8f795730928bd73844cd92aec75c41031a4`

Do not configure, compile, relink, regenerate discovery, or edit source, tests, fixtures, manifests, validators, benchmark logic, or build logic. Runtime-only fixture symlinks are allowed only to expose packaged paths without modifying packaged bytes.

Timeout is failure, never correctness evidence.

## Pre-execution integrity

Before running any packaged project binary:

1. verify the outer artifact SHA-256 exactly;
2. extract into a fresh arbitrary directory;
3. verify all 44 recursive checksums;
4. verify five executables, two project libraries, and 27 fixture/input files;
5. verify source authority is `56f823273cad041a01ebb4d0772c3265ff248f4a`;
6. verify patch SHA-256 `d93cc65f86ea402111af3b409e73d08c72be37fdee1f2758538033fc7525802f`;
7. verify changed blobs:
   - `SurfaceCellTracing.h` `931669018a986096cf78d66a2aed9de5aa8e0fe1`;
   - `RemeshDiagnostics.h` `a51215982318e77581efa4fa7887d0406a9d4bf0`;
   - `SurfaceCellTracing.cpp` `b1a2c6d4051cc17b79e342170285d69552cad16d`;
   - `RemeshPipeline.cpp` `7674ed3fe40c5f43c668c931c01b59f6c7829df8`;
   - `DirectionalBenchmark.cpp` `18955ca8ef72812c9c70ed522bb578409e6a176f`;
   - `SurfaceCellsPhase10Tests.cpp` `bccd6abf3e31b8096c471c515b1949d08dcfde59`;
8. verify packaged command-boundary metadata says `runtimeExecution=false`;
9. verify exact cylinder fixture SHA-256 values:
   - `cylinder.obj` `59ed6d736410dbef6bc751136ba0eb1d557a43c9df63fb2a570daf85c79419ae`;
   - `cylinder.rawfield` `6e861e06fa5d3dd6ed84c48bf7d459df701acd7f6ab241cc2adbde66d829084d`;
10. verify exact plane, seam, close-sheet, bunny, and vase production fixtures are present.

If integrity fails, classify infrastructure invalid and stop. Do not repair packaged source or inputs.

## Focused periodic producer contracts first

Run these directly from the packaged producer-test executable:

1. `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`
2. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`
3. `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`
4. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`
5. `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`

Then run the retained passed-gate producer contracts needed to prove no G1/G2 regression, including:

- `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`
- `SurfaceCellsPhase10.UniformPhaseFrontPartitionsDisconnectedCloseSheetsBySourceAuthority`
- `SurfaceCellsPhase10.UniformPhaseFrontCloseSheetsIgnoresFaceRowEnumeration`
- the ordered source-vertex-fan and seam/transition contracts used by the G1/G2 artifact turns.

Record every exact result. Do not weaken or replace a failing contract.

## Direct acceptance order

Run each in a fresh bounded process using `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled:

1. plane — mandatory G1 regression;
2. multi-face seam — mandatory G2 cross-chart regression;
3. close sheets — mandatory G2 isolation regression;
4. cylinder — active G3 acceptance fixture;
5. randomized bunny — later production observation only;
6. vase — later production observation only.

Later fixtures cannot make G3 pass if cylinder fails. Torus/general-genus work is explicitly outside G3 and must not redirect the decision.

## G3 cylinder acceptance

G3 closes only if the exact production cylinder demonstrates all of the following:

- authoritative producer disposition `Produced`;
- direct `CompletedSurfaceCells` output;
- non-empty pure-quadrilateral output and zero non-quads;
- first-class periodic holonomy available;
- holonomy quarter-turn rotation is compatible with the singularity-free annulus and, for the committed cylinder, equals zero;
- integer periodic lattice translation is nonzero in exactly the periodic lattice direction and zero in the axial direction;
- ordered periodic source route and deterministic source cut are non-empty and source-authoritative;
- artificial cut front edges pair reciprocally through periodic ownership and are not emitted as output exterior seam edges;
- the two genuine source boundary loops remain the only annulus exterior boundaries;
- periodic quotient materialization creates no Euclidean/nearest-point seam welding;
- complete source provenance;
- zero strict source-authoritative validation failures;
- no fallback attempt/use;
- source-grid recovery disabled/unused;
- deterministic holonomy, producer/stage/structural, and output hashes across independent processes;
- plane, seam, and close sheets remain their already proven valid direct successes.

A cylinder improvement that regresses any passed G0–G2 gate does not close G3.

## Required observations per direct case

Record at minimum:

- producer disposition;
- terminal stage and reason;
- requested/executed backend;
- phase-front attempted/succeeded and typed failure context;
- authoritative phase-front cell/edge/event counts when available;
- periodic holonomy availability, rotation, translation, route-edge count, and cut-edge count;
- trace count;
- source component/local-sheet counts;
- arrangement, simplification, direct, completion, and output counts;
- output vertices, quads, and non-quads;
- output connected-component and boundary evidence when available;
- strict validation failure count and first invalid reason;
- fallback/recovery state;
- output origin;
- producer/stage/structural/output hashes;
- wall time and exit code.

For `Rejected`, verify generic producer substitution does not occur. For `NotApplicable`, record it separately; do not reinterpret it as success.

## Determinism

After first-pass direct acceptance:

- plane: 3 independent processes;
- seam: 3;
- close sheets: 3;
- cylinder: 3;
- bunny: at least 1 bounded process, second only if reasonable;
- vase: at least 1 bounded process, second only if the first completes within the runtime budget.

Compare producer dispositions, periodic holonomy tuple/route counts, stage counts, typed failure identities, structural hashes, and output hashes. Timeout remains failure only.

## Default suites

After the focused contracts and direct gate cases:

1. run the remaining producer suite excluding explicitly executed tests;
2. run completion/simplification suite;
3. run validation suite;
4. run compiled API suite.

Report direct gate acceptance separately from aggregate totals. Scheduler-sensitive timing checks remain closeout/performance evidence and cannot override functional gate results.

## Decision hierarchy

### G3 closure

Cylinder is direct deterministic strict-valid `Produced` output with correct periodic holonomy/seam closure and only genuine annulus boundaries, and plane/seam/close sheets remain valid. The next implementation gate becomes **G4 topology-distinct completion and singularities**.

### Material progress, G3 still open

Cylinder becomes applicable to the periodic producer and reaches a new exact typed `Rejected` periodic-holonomy/chart/front state with zero generic substitution, while G0–G2 remain green. The next Code + Build turn addresses only that exact general periodic rejection.

### No material progress or regression

Cylinder remains on the same generic `NotApplicable` path without a live periodic contract; the artificial cut appears as exterior output boundary; periodic pairing relies on proximity; `Rejected` falls through to generic work; or any plane/seam/close-sheet regression occurs. Keep G3 active and apply the no-progress rule when applicable.

## Required evidence

Preserve exact commands, raw stdout/stderr, fixture integrity, artifact digest/checksum verification, focused/default test results, benchmark JSON, periodic-holonomy records, determinism comparisons, machine-readable summary, and an evidence archive with SHA-256/recursive checksums.

## Prohibitions

- no rebuild or relink;
- no source/test/fixture/manifest/validator edits;
- no validator weakening;
- no fixture/ID/count/order special cases;
- no Euclidean or nearest-point periodic seam welding;
- no fallback/recovery substitution;
- no arbitrary subset search;
- no synthetic counters/Euler correction;
- no post-hoc cell merging;
- no timeout-as-correctness.
