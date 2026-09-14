# M4-CP-COND-CB5 — Code + Build Report

**Turn:** `M4-CP-COND-CB5`
**Disposition:** **COMPLETE / COMPILE + PACKAGE GREEN / SELECTOR423 CANDIDATE / RUNTIME NOT EXECUTED**
**Checkpoint:** `M4-CP-COND` remains **OPEN** pending immutable TB5 execution and mandatory review.
**Successor:** `M4-CP-COND-TB5-EXEC`

## Authority

CB5 preserves the accepted M4 runtime authority from TB4 Review:

- accepted package: `10327643907`;
- accepted selector422: **422/422**, SHA-256 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- stable accounting: **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

CB5 adds compile-only candidate authority:

- semantic implementation commit: `a3653af2e47723bbe2396b27a6da9f2f2db203f0`;
- authoritative compile/package source: `07984711db59eaa228820e7d44e5552a652edadf`;
- selector423: `.agents/Directional/Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt`;
- selector423 SHA-256: `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`.

No CB5 compile evidence promotes selector423 or replaces the accepted selector422 runtime authority.

## Implemented test authority

CB5 adds exactly one gating identity:

`InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`

The test constructs an open five-face fan directly from raw mesh/field bytes. Before invoking `condition_surface_cell_input`, a test-local exact/discrete oracle:

1. independently derives the nonzero raw singularity index (`cycleNumerator = -1`) at center vertex `0`;
2. identifies a genuine source-boundary carrier by exact edge incidence (`{1,2}` has incidence `1`);
3. converts input IEEE-754 values exactly to GMP rationals and performs exact cross/dot ray-versus-boundary-edge intersection;
4. derives the concrete route/locus `sourceFace=0`, `fieldBranch=0`, boundary edge `{1,2}`, including exact ray and boundary parameters.

The oracle does not call the conditioner, A0/A1/A2a trace products, or production trace functions to discover the expected event.

A load-bearing raw mutation replaces raw field row `0` with the cross at angle `2π/9`. The independent oracle still identifies the same singularity/source face/boundary carrier but derives a different exact boundary parameter, so the complete oracle result no longer equals the original. This falsifies any interpretation that the oracle is detached from the raw field bytes.

The test then runs frozen `ConditioningPolicy::production_identity()`, requires `Produced`, validates the conditioned product, reconstructs a raw view solely through the emitted certificate/correspondence, and reruns the same independent oracle. The reconstructed result must equal the pre-production raw result exactly.

## Scope audit

The semantic work is surgical and within the CB5 freeze:

- `tests/InputConditionerTests.cpp` — independent oracle/witness, mutation falsifier, certificate reconstruction, one new gate;
- `cmake/DirectionalTests.cmake` — explicit packaged owner for the new test identity;
- `Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt` — new frozen candidate selector;
- `Required_Green_Selector_Manifest.md` — additive selector423 index/receipt.

There is no `src/` or `include/` production semantic change, no external fixture/benchmark change, and no accepted selector422 row mutation.

## Selector423 static gate

Static publication checks establish:

- exactly **423 LF rows**;
- rows 1-422 are byte-identical to accepted selector422;
- first422 SHA-256 remains `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- row423 is exactly the new CB5 identity and is unique;
- selector423 SHA-256 is `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- packaged ownership is **30 authority-kernel / 277 producer / 75 completion / 41 validation = 423**.

The old report-only `BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` placeholder is not appended to selector423. The new independent gate is the candidate replacement authority.

## Patch application evidence

The semantic work-preservation patch was staged through the authorized Google Drive transport and applied by the reusable Drive workflow:

- patch SHA-256: `2ee65f4c80ca1789795a5ecdef1ecd9accb6575d14fdffe86929e8ad96dbef6a`;
- Drive-apply run: `34800736105`;
- result artifact: `10330753571`, digest `sha256:7f936d9a442d142b672824ee6e8da41282c019759e4a89a9c96948fffa2ef402`;
- diagnostic artifact: `10330509388`;
- applied semantic commit: `a3653af2e47723bbe2396b27a6da9f2f2db203f0`.

The consumed Drive staging file was permanently retired after successful push/evidence capture.

## Compile/package evidence

Authoritative compile workflow run `34800916761` completed GREEN using the durable GMP compile reusable.

Changed-owner prepackage compile:

- target: `directional_surface_cell_producer_tests`;
- result artifact: `10330748821`;
- artifact digest: `sha256:be50cc6f9f1d0803ca1182047bdca1240afbf41f3465e31b6c6802c377503a74`.

Seven-target package compile:

- source: `07984711db59eaa228820e7d44e5552a652edadf`;
- result artifact: `10331193451`;
- artifact ZIP/digest SHA-256: `3f23572a4869e469a6f3ba1082af8a7836c29d9566d143e1a395950d8a94230b`;
- diagnostic artifact: `10331322922`;
- compiled targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_benchmarks`;
- preflight exit: `0`; build exit: `0`;
- exact arithmetic: `GMP`, with authoritative link evidence containing both `libgmpxx.so` and `libgmp.so`;
- packaged `SHA256SUMS`: **27/27 verified**, self excluded;
- all five source-status receipts are empty;
- packaged test binaries retain executable mode;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

No Directional test, benchmark, discovery, help/version command, or other produced runtime executed during CB5.

## Runtime boundary and successor

Selector423 is a **compile candidate only**. Artifact-only `M4-CP-COND-TB5-EXEC` must consume immutable artifact `10331193451` without configure/build/relink/repair and execute all 423 selector identities as fresh exact-filter processes in file order. It must then hand the evidence to mandatory `M4-CP-COND-TB5-REV` for independent adjudication and any CP-COND closure/promotion decision.
