# M4-CP-SCALE-TB12-R2-EXEC — Artifact-Only Cycle-Ordering Diagnostic Test + Benchmark Plan

**Turn:** `M4-CP-SCALE-TB12-R2-EXEC`
**Owner:** Test + Benchmark
**Immutable candidate artifact:** `10517300204`
**Exact compile source:** `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21`
**Provider/local package SHA-256:** `dceab12b7fe9ee8feccf972837455b89f6fe8b4bc30b44ee4947fc2343bd2711`
**Accepted runtime authority on entry:** package `10473134357` / selector426 **426/426**

## 1. Purpose

CB15 intentionally changed diagnostics only. TB12-R2 therefore has one semantic-runtime purpose: execute the frozen S5 focus exactly once from the immutable CB15 package and capture the cycle-row/class/support/failure-subtype discriminator that TB12-R1 lacked. It does not test a semantic repair and cannot grant S5 credit.

The focus is expected to remain RED at the same field-transport-atlas boundary. A different decision is evidence about diagnostic neutrality and routes to Review; it is not acceptance.

## 2. Immutable preflight

Before generated runtime, verify all of the following directly from artifact `10517300204` without repair:

- provider and local ZIP SHA-256 both equal `dceab12b7fe9ee8feccf972837455b89f6fe8b4bc30b44ee4947fc2343bd2711`;
- root self-excluding `SHA256SUMS` verifies **28/28**;
- exact source is `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21` and source archive SHA-256 is `14a1eccff69d402b72bf803f47b0ebf778f96d9f2da87baf46b74b1e49873ebc`;
- compile evidence shows preflight/build `0/0`, clean source status, `runtimeExecution=false`, `exactArithmeticBackend=GMP`, and authoritative generated link evidence for both GMPXX and GMP;
- producer executable is an archived executable without permission repair; expected package mode `0755` and SHA-256 `3c5ff0af1b1b3ba78781692b9661c8c59e167acc14793feae291104fcecd269c`;
- selector426 is exactly 426 unique LF rows, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, exact first425 prefix `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, owners **30/280/75/41**, and no selector427 exists;
- packaged S5 bytes are exact: OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, rawfield `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`;
- independently re-derive the retained OBJ topology from immutable bytes and require the established genus-two precondition (`V/E/F=120/366/244`, one connected closed orientable component, zero boundary loops, `chi=-2`, genus `2`).

Materialize the packaged source/runtime fixture view with its recorded path layout intact. No configure, compile, rebuild, relink, regeneration, `chmod`, fixture repair, package mutation, GTest discovery/listing, help/version invocation, CTest, CLI, fuzzer or custom input is permitted.

A pre-runtime orchestration failure is non-semantic: stop, preserve evidence, and route according to cadence. Do not repair the immutable package inside TB.

## 3. Exactly one focused process

Execute exactly one fresh producer process with exact filter:

`M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`

Require selection of exactly one test and preserve raw stdout, stderr, exit code and an explicit process receipt. No generated Directional process may precede it.

For the expected decision-neutral RED, require all old semantic facts to remain compatible with TB12-R1:

- independent/production atlas authority is not established before A3;
- production outer terminal code/stage remains `InvalidFieldTransportAtlas / field-transport-atlas/IncompleteCycleBasis`;
- `IncompleteCycleBasisReason` remains `CycleOrderingFailed`;
- A3 remains absent;
- the receipt now exposes `independentAtlasFailure` with one populated `cycleOrdering` discriminator including exact row, kind, support-edge count, unique-from-face count, reason, current face and source edge where applicable.

The diagnostic subtype must be one of the five CB15-authorized names: `DuplicateFromFace`, `MissingSuccessorFromFace`, `SupportEdgeReused`, `DirectedAdjacencyFaceMismatch`, or `OpenOrUnconsumedSupport`.

## 4. Frozen fail-fast for this diagnostic retry

Regardless of whether the single focus is RED or unexpectedly GREEN, execute **no selector426 process and no benchmark** in TB12-R2. This retry exists only to resolve the diagnostic discriminator after a Review-authorized diagnostics-only CB.

Expected runtime counts are therefore:

- S5 focus: exactly **1 fresh process**;
- selector426: **0/426**;
- benchmark: **0**.

Unexpected focus GREEN, changed old error code/reason, zero/multiple test selection, missing discriminator, process crash/timeout, or any immutable-byte/mode drift is a STOP condition. Do not reinterpret unexpected GREEN as S5 credit and do not publish selector427.

## 5. Immutable postflight

After the one focus process, re-hash the package/execution view, exact packaged source, selector426 and S5 fixture trio and re-check relevant modes. They must match preflight exactly. Generated runtime may create only the explicitly authorized raw receipt/evidence outside the immutable package tree.

## 6. Regression and closeout duties

Every observed semantic regression/candidate or orchestration candidate must be recorded in `.agents/Directional/Regression_Root_Cause_Tracker.md` before TB closes. The existing `M4-CP-SCALE-TB12-R1-EXEC-CAND-01` remains non-stable unless later Review changes its classification; TB12-R2 may narrow its exact failing subcondition but does not independently assign stable historical counts.

A mechanically valid focused RED with the new discriminator routes to mandatory runtime-free `M4-CP-SCALE-TB12-R2-REV`. A mechanically valid unexpected GREEN or changed old error/reason also routes to Review as diagnostic non-neutrality evidence. Pre-runtime orchestration failure follows the orchestration-correction edge and creates no semantic ledger. No semantic repair is authorized inside this turn.
