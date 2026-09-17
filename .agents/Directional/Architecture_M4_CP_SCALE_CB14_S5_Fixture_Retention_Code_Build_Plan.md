# M4-CP-SCALE-CB14 — S5 Fixture-Retention Orchestration Correction Code + Build Plan

**Turn:** `M4-CP-SCALE-CB14`
**Owner:** Code + Build
**Cause:** `M4-CP-SCALE-TB12-EXEC-CAND-01`
**Runtime:** forbidden (`runtimeExecution=false`)
**Expected successor if compile/package preflight is green:** `M4-CP-SCALE-TB12-R1-EXEC`

## 1. Purpose

Correct only the orchestration/source-retention defect exposed before TB12 semantic execution: the compiled S5 test references `benchmarks/fixtures/milestone-g/genus_two.obj` and `.rawfield`, but neither file exists in candidate source/package authority. This turn must retain and package the intended deterministic fixture pair so the already-authored focus can be executed artifact-only.

This is not a Review and does not adjudicate S5 semantics. It grants no S5 credit, does not execute the focus, does not publish selector427, and does not modify production behavior to force A3 reachability.

## 2. Frozen authority

- Accepted runtime authority: package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**.
- Selector426 SHA-256: `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; first425 prefix `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; owners **30/280/75/41**.
- Focus identity and owner stay frozen: `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology` / producer.
- Production `src/**` and `include/**` are frozen.
- `tests/FieldAlignedCurveNetworkTests.cpp` S5 test semantics are frozen unless an independently demonstrated impossibility in the stated fixture contract forces a Review; CB14 may not weaken its expectations.
- Stable accounting remains **49 / 14 / 35**, debt **5**.

## 3. Required fixture authority

Add a deterministic project-authored genus-two fixture through the existing milestone-G fixture generation authority rather than hand-editing opaque bytes.

Required retained paths:

- `benchmarks/fixtures/milestone-g/genus_two.obj`
- `benchmarks/fixtures/milestone-g/genus_two.rawfield`

Update `benchmarks/fixtures/generate_milestone_g_fixtures.py` so regeneration emits those exact files deterministically. Update `asset-manifest.json` and licensing/provenance metadata as required by `tests/TESTING_STRATEGY.md`.

Before compile, independently derive from the committed OBJ bytes:

- triangle input;
- `V=120`, `E=366`, `F=244`;
- exactly one connected face component;
- zero boundary loops;
- closed two-manifold edge/vertex links;
- orientability;
- Euler characteristic `-2`;
- genus `2`.

The raw field must be dimensionally valid for the 244 source faces and deterministic. CB14 must not claim field/atlas admissibility by filename or intent; the later artifact-only focus owns the independent admissibility/runtime proof. If static generation cannot satisfy the frozen fixture facts, stop instead of changing the topology expectations to match an arbitrary generated subject.

## 4. Scope prohibitions

CB14 must not:

- alter production topology/tracing/field/atlas/A3 semantics;
- change selector426 or create selector427;
- change owner mapping or CMake target ownership;
- weaken the focused test, topology oracle, field/atlas checks, or A3 requirement;
- execute any generated Directional binary, test, benchmark, discovery/list/help/version command, CTest, CLI, fuzzer, or custom runtime input;
- use fixture symlinks, runtime-generated fixture substitution, or package repair.

## 5. Compile/package contract

Use the durable reusable compile workflow with mandatory GMP/GMPXX and compile/package the standard eight targets. Package evidence must include exact source identity, clean source status, recursive manifest, generated binaries, source archive, GMP/GMPXX link evidence, and `runtimeExecution=false`.

In addition to normal compile evidence, verify from the packaged source archive that both `genus_two.obj` and `genus_two.rawfield` exist with the exact committed SHA-256 and expected mode. This check is compile/package inspection only; do not execute the focus.

## 6. Successor boundary

If and only if CB14 produces a clean immutable package containing the retained fixture pair, advance to `M4-CP-SCALE-TB12-R1-EXEC`. That fresh TB must rerun the original TB12 contract from preflight: one focused producer process plus selector426 as 426 fresh exact-filter processes, exact immutable postflight, no rebuild/repair/benchmark. A genuine focused RED after the fixture precondition is satisfied routes to Review; an orchestration failure does not.
