# TB104 — derived field-corner witness full gate (2026-11-11 UTC)

## Situation

**COMPLETE / MATCH within the frozen 942-case gate.** The immutable CB123 package passed **942/942** with membership **1023**. A separate three-case production census returned **1 PASS / 2 registered RED / 0 abnormal**. No CP3/selector497 promotion follows.

## Background

- Exact turn `M6-CP3-TB104-P13-A3-DERIVED-FIELD-CORNER-WITNESS-FULL-GATE-EXEC` (artifact-only Test + Benchmark); CB123 compiled source `dcfc9494830b150af944b057eb7003a69806085a`, [compile 43046771206](https://github.com/akashskypatel/Directional/actions/runs/43046771206), immutable artifact `13867931016`, outer ZIP SHA-256 `c1c5a80fa4d20fa84c7a09c0709ec664858deb42a07891fb0ff17088d4aa9b40`. Package **28/28** hashes checked. Preflight source archive SHA-256 `aa08afb5eec2043bbce5955c8fe9ac80478cd94ad77884388acdfad743b07769`.
- Frozen manifest `.agents/Directional/gates/Architecture_M6_TB104_P13_A3_Derived_Field_Corner_Witness_Full_Gate_Case_Manifest.tsv`: 942 rows, SHA-256 `7b0b4545e607b138c03caab682c6d6b698639335fcf497fa8da71751bcea4b9e`, membership 1023; the same standard artifact-only harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- [Full-gate run 43054464177](https://github.com/akashskypatel/Directional/actions/runs/43054464177), request/event `8b012af0f85d186c738188ef90c34859be345925`, result artifact `13870434562`, outer ZIP SHA-256 `674c06fa8f7277ed22cda5c5b189be39f078adaa6ce85e229778194b9e52d8a7`. All **1,892/1,892** recursive SHA256SUMS records passed. The execution boundary records 942 planned/executed/passed; 0 RED, abnormal, missing, skipped, duplicates, control errors, unexpected passes or site errors; membership 1023; exit 0; postflight true.
- [Census run 43054723909](https://github.com/akashskypatel/Directional/actions/runs/43054723909), request/event `30b7aaf521f3cb78adcdcefee9bf04884365439c`, result artifact `13869789726`, outer ZIP SHA-256 `1de0e3838c738e26c07233209a0b2a0936c2123232bc71600db26c8b80c2d09f`. All **9/9** recursive checksums passed. Three planned/executed, Cylinder PASS; BunnyRandom and Vase existing registered RED, 0 abnormal/control errors, exit 0, postflight true.
- Both boundaries confirm exact source `dcfc9494830b150af944b057eb7003a69806085a`, immutable artifact `13867931016`, and `configure=false`, `compile=false`, `relink=false`, `benchmark=false`. No code, test, fixture, selector, workflow or package mutation occurred inside execution.
- Verified read-only snapshot: event/source `fe1f733a3d792c8c5cbf2600c858b73c10561b05`, run `43053850484`, artifact `13871445618`, outer ZIP SHA-256 `f25415511bdd81feecaa0a03ea55d175f38592acb2186c2817387379e5c2c0cb`, **5,472/5,472** source hashes. This snapshot is inspection authority, not compiled source authority.

## Assessment

- All **940 inherited TB101C gate rows** agree on `row`, `kind`, `identity`, `test`, `binary`, `verdict`, `exit`, `run`, `passed`, `skipped` and `typed_reason`. The two appended GUARD rows 941–942 both PASS: `DerivedBoundaryFieldCornersSplitRimChains` and `RimChainsNeverJoinAtANodeSharedByTwoFans`.
- Seven `platform-digest` and seven `a3-coverage` raw records (four gate + three census of each), all four `d4-rim`, all four `d4-corner`, and both `FIELD_CORNER_RECEIPT` lines match the TB101C artifacts **byte for byte**; no observed cross-platform or prior-receipt drift.
- New record, **verbatim**:

```text
DERIVED_CORNER_RECEIPT axis=0R,7R|1F,2F|3F,4F|5F,6F rim=0F,1F|2F,3F|4F,5F|6F,7F
```

- The census REDs at `offgate:360` BunnyRandom and `offgate:365` Vase are existing production failures, not newly introduced accepted-green regressions. Their first failed assertion remains `SurfaceCellDesignAcceptanceTests.cpp:273`; the census does not establish a new typed cause. The accepted CP2 result is **491/491**; stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81** unchanged. O34/O35/O36/O37, D6, and O39 remain open; the O36 production switch is not authorized by this narrow test gate.

## Recommendation

Mark TB104 **COMPLETE / scoped MATCH** and advance **only in the next turn** to `M6-CP3-CB124-P13-A3-SHARED-RIM-BRANCH-RULE` (64B.21, exact compile-only source patch from RA-225). Do not start CB124 during this TB104 turn. Preserve the exact artifact and evidence references above; do not promote CP3/selector497.
