# M5-CP4-CB2 selector449 publication Code + Build plan

**Turn:** `M5-CP4-CB2`
**Type:** Code + Build
**Boundary:** exact selector/routing publication plus mandatory compile/package only; **no Directional runtime**

## 1. Goal

Publish exactly the selector449/routing449 bytes precommitted by `M5-CP4-TB1-REV`, then compile/package the four standard selector-owner executables with mandatory GMP/GMPXX authority. Product/test/fixture/field semantics are frozen.

## 2. Precommitted immutable bytes

- predecessor selector: `Architecture_M5_CP3_CB20_Required_Green_Selector_448.txt`, 448 rows, SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`;
- selector449 path: `Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt`;
- selector449 exact SHA-256: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- selector449 rows1-448 must be byte-identical to selector448 and re-hash to `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`;
- appended row449: `M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion`;
- predecessor routing: `Architecture_M5_CP3_CB20_Selector_448_Static_Routing_Receipt.tsv`, SHA-256 `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`;
- routing449 path: `Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv`;
- routing449 exact SHA-256: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- exact row449 routing: `449<TAB>M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion<TAB>directional_surface_cell_producer_tests`;
- static owner census: **32 authority-kernel / 301 producer / 75 completion / 41 validation**.

Do not regenerate or reorder selector membership. Materialize the reviewed bytes exactly.

## 3. Authorized source change

Exactly two selector-publication files may be added. No C++ source, test source, fixture, raw field, benchmark input, CMake ownership, product semantics, accepted selector448, or earlier selector/routing bytes may change.

The selector manifest may be updated only after the selector449 file is actually published and its bytes independently re-hash to the precommit; this is documentation, not permission to alter selector membership.

## 4. Compile/package contract

Use `.github/workflows/agent-compile-reusable.yml` only. Mandatory backend is GMP:

- `DIRECTIONAL_ENABLE_GMP=ON`;
- CMake must discover GMP;
- generated link authority must contain both `gmpxx` and `gmp`;
- `exactArithmeticBackend=GMP` evidence is mandatory;
- compile/package all four selector owners:
  - `directional_surface_cell_authority_kernel_tests`;
  - `directional_surface_cell_producer_tests`;
  - `directional_surface_cell_completion_tests`;
  - `directional_surface_cell_validation_tests`.

Package the exact published selector449/routing449 and source authority needed by artifact-only TB2. Record `runtimeExecution=false`.

**Forbidden:** executing any generated Directional binary, GTest discovery/listing, `ctest`, benchmark, CLI/help/version command, or custom runtime input.

## 5. Verification

Before compile:

1. re-hash selector448 and routing448;
2. prove selector449 has 449 unique rows and exact selector448 prefix;
3. prove routing449 ordinals 1..449 are contiguous, rows1-448 exactly equal routing448, row449 exactly matches the reviewed routing, and owner census is 32/301/75/41;
4. prove changed semantic paths are exactly the two publication files.

After compile/package:

1. verify all four executables exist and preserve executable mode;
2. verify source/selector/routing hashes inside the package;
3. verify GMP/GMPXX linkage evidence;
4. verify recursive self-excluding package manifest;
5. verify clean source status and `runtimeExecution=false`.

## 6. Falsifiers and stop rules

Stop and return to Review if any condition fires:

1. selector449 SHA is not `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
2. first448 selector bytes do not hash to `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`;
3. routing449 SHA is not `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` or its prefix does not hash to `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`;
4. row449 identity/owner/order differs from the precommit or owner census differs from 32/301/75/41;
5. publication requires any product/test/fixture/field/CMake semantic change;
6. any accepted earlier selector/routing changes;
7. mandatory GMP/GMPXX compile authority is missing or falls back;
8. any required owner executable is absent from the package;
9. any generated Directional binary is executed.

No repair by selector weakening, identity substitution, fixture mutation, test semantic editing, owner remap, or runtime trial is authorized.

## 7. Successor

On exact publication + compile/package green, route to **`M5-CP4-TB2-EXEC`**. TB2 must consume the immutable CB2 package artifact-only and execute the **published** selector449 as 449 fresh exact-filter processes. `M5-CP4-TB2-REV` remains the only turn authorized to accept conjunct8 and close M5.

## 8. Reviewing-agent amendment (`M5-CP4-TB1-REV` review) — binding

1. **Compile all eight standard targets, not four.** Invoke `agent-compile-reusable.yml` **without overriding `targets`**, so it builds its durable default: `directional_core`, `directional_pipeline`, the four `directional_surface_cell_*_tests` owners, `directional_compiled_api_tests` and `directional_benchmarks`.
   - CB2's package becomes the **final M5 runtime authority** if TB2-REV accepts it. Every earlier milestone authority package was an eight-target build (M4 CB8, M5 CB19, CB20: 28/28 root manifest).
   - The CB1 prepublication package built only the four owners (26/26). That was authorized by the CB1 plan, whose narrowing the DEFN-R2 review missed, and it is acceptable for prepublication evidence. It must not become the closure standard.
   - TB2 still executes only the four owner executables. The other two must compile, link against GMP/GMPXX and be packaged.
   - **Falsifier 8 is extended:** any of the eight standard targets failing to compile or link, or being absent from the package, stops CB2.
2. **Resume discipline (`M5-CP4-TB1-REV-OBS-02`).** If this turn is resumed after any interruption, first re-derive its progress from the branch and Actions history. That means publication files present, compile run id and conclusion, and report written. Do not re-trigger a compile or re-arm any workflow when a green authoritative run already exists for the same source. Re-arming is allowed only if that run is shown orchestration-invalid, and the reason must be recorded.
