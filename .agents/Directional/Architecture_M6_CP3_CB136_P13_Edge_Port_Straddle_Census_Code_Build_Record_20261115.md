# CB136 Code + Build — exact edge-port straddle census

**Turn:** `M6-CP3-CB136-P13-EDGE-PORT-STRADDLE-CENSUS` — complete. P13-e.4; implementation and compile only.

## Situation

The report-only patch in [RA-236](Architecture_M6_CP3_DEFN_P13_Singularity_Port_Owner_Review_20261112.md) is committed and compiled. The full runtime gate remains unexecuted and belongs to TB117.

## Background

- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 remains unmerged.
- Frozen source snapshot: `024d66b817cc9fbd7581ebb76652ec8108d2a39a` (run [43772194170](https://github.com/akashskypatel/Directional/actions/runs/43772194170), artifact `14184627393`, 5,534/5,534 source checksums verified).
- [Exact RA-236 patch](Architecture_M6_CP3_CB136_P13_Edge_Port_Straddle_Census_Exact.diff): SHA-256 `cca1ce4cc55aa3e9173ba548cf2d0faaa4bda42c1aad72978daf8a6356740dc4`; 59 additions, no deletions; only `src/authority/FieldTransportAtlas.cpp`.
- Patch application [43772565839](https://github.com/akashskypatel/Directional/actions/runs/43772565839) succeeded, result artifact `14185365577`, verified SHA-256 `2a1e47a379332bc41addcbddc2ad325003e758510006e1961c3b17f717fcc87b`. Semantic source commit: [`1d5c9514b8ec479d90e059107dd627656e37d15f`](https://github.com/akashskypatel/Directional/commit/1d5c9514b8ec479d90e059107dd627656e37d15f). Applied patch SHA-256 `60a471eca89e27d97780d0d9ea88e7a2150f0e05468202afc5965944e2c60458`.

## Assessment

- Compile [run 43772905298](https://github.com/akashskypatel/Directional/actions/runs/43772905298) succeeded. Immutable package artifact `14184697141`; outer ZIP SHA-256 `e0b781baffb3057eae1197d5539f7850221269042393def73ae17c06abe1bc7a`.
- All eight required targets compiled and the package checksum manifest passed; GMP and GMPXX both appear in the generated link line, with exactArithmeticBackend=GMP and runtimeExecution=false.
- The atlas now prints one exact `FieldTransportAtlas.partition edgePorts` diagnostic for each singularity. It counts radial-edge straddles and compares `classes + edgePorts` with `4 − index`. Existing attachment and count behavior is unchanged.
- No Directional binary, test, benchmark, or census was executed in this turn. No runtime PASS is claimed.
- Latest inherited runtime remains TB116's scoped 945/945 PASS. Accepted CP2 491/491; stable 66 events / 17 categories / 49 recurrences; debt 1; deferred 81. No CP3/selector497 promotion. `chainRimSchedules=false`; D10 remains defer.

## Recommendation

**Next separate turn:** `M6-CP3-TB117-P13-EDGE-PORT-STRADDLE-CENSUS-FULL-GATE-EXEC`. Execute only the immutable CB136 package with TB117's exact 945-case manifest and production census. Require every `partition edgePorts` line to have `identity=1`, with BunnyRandom singularity 6 / sourceVertex49 reporting `classes=4 edgePorts=1 expectedClasses=5 straddles= (0,1,48-49)`, and all others `edgePorts=0`. Preserve prior TB116 receipts and verdicts. Route any semantic mismatch to the named Review turn, not a direct correction.
