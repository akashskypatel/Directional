# M4-CP-SCALE-TB12-R4-EXEC — Artifact-Only Corrected Gate-A → S5 Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB12-R4-EXEC`
**Disposition:** **COMPLETE / GATE A 4/4 GREEN / GATE B S5 SEMANTIC RED / FAIL-FAST STOP / REVIEW REQUIRED**
**Immutable candidate:** artifact `10527625935`, compile source `1b44d2b7b3173590db9837a1386eadbc9ac32981`
**Authoritative runtime run/job:** `35296853812 / 105451109821`
**Result/log artifacts:** `10528172684 / 10527643135`
**Mandatory successor:** `M4-CP-SCALE-TB12-R4-REV`

## 1. Immutable candidate preflight

TB12-R4 consumed CB17 artifact `10527625935` unchanged. Provider/local ZIP SHA-256 is `88e61b93328ff4617f6810077b9469602466c06e4059b23b7c0402aefbd80e93`; root `SHA256SUMS` verifies **28/28** and hashes to `d3a1ae00bc214397e23ca7a62b760566207990d108783d7355ca5cdc84224dd4`. Package metadata names exact compile source `1b44d2b7b3173590db9837a1386eadbc9ac32981`; the packaged source archive hashes to `636855d94efdb8cac3898b2f0a2dd020c2ff85c90cd61ee9006d3d0a671b267e`; compile preflight/build exits are `0/0`; all recorded source-status snapshots are empty; the compile boundary remains `runtimeExecution=false`; GMP/GMPXX link evidence is present.

All six packaged executables retain mode `0755`. Selector426 remains **426 unique LF rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, with exact first425 prefix `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` and owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**. No selector427 exists. Retained genus-two fixture hashes remain OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, rawfield `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

No configure, compile, relink, code generation, `chmod`, package repair, source/test/fixture/selector mutation, CTest, discovery/list/help/version command, or benchmark executed in the authoritative artifact-only run.

## 2. Gate A — corrected authority is 4/4 GREEN

The authoritative run is `35296853812` at event SHA `1aec9c4c2277a03d3fa999317322896fb6da6fc7`. Workflow SchemaStore validation completed GREEN before the execute job. Gate A then ran four fresh exact-filter processes in frozen order, each selecting exactly one test with zero skips:

1. `FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents` — **PASS**, exit `0`, stdout SHA-256 `64f28a1004c28570b3a1de89c5659d0b5f4a0cfa062d442c7871ee7f5ae51a33`.
2. `FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence` — **PASS**, exit `0`, stdout SHA-256 `7c05d2ff10dd84e9bd8b9a6f971d04ccef39cdc710f9c84e4701ebca133d3350`.
3. `FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper` — **PASS**, exit `0`, stdout SHA-256 `0e113347bcd71b23891fd60cd0b02c4b5ab6ad298ccfc00eba20c90e3a824c17`.
4. `FieldTransportAtlas.OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow` — **PASS**, exit `0`, stdout SHA-256 `3a89e9c9d27e8d50bd934383fc62dc6f4dc4630516dc9f9b07478a4fdb0527b0`.

This mechanically proves the CB17 replacement control executes and passes on the immutable candidate. EXEC does not close the prior `RP-02` test-authority candidate; mandatory Review owns that disposition.

## 3. Gate B — S5 RED at downstream singularity admissibility

Because Gate A reached **4/4**, the frozen plan authorized one fresh producer process for `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`. It selected exactly one test and failed semantically: **RED**, exit `1`, zero skips, stdout SHA-256 `5e84573491ed07c670749abbe4252c8d934544d78489344a29b9b191eb14c6e1`, empty stderr.

The structured runtime receipt reports the independently verified source topology unchanged as `V=120,E=366,F=244,components=1,boundaryLoops=0,closedTwoManifold=true,orientable=true,chi=-2,genus=2`. The retained cross field is present, but independent atlas construction now fails with `SingularityMismatch;sourceVertex=0`. Production reaches `source-labels` and terminates `InvalidFieldTransportAtlas / field-transport-atlas/SingularityMismatch;sourceVertex=0`; no field-transport atlas is published, `a3Produced=false`, `a3DebugCount=0`, and no A3 topology product exists.

This is a later semantic boundary than the previously observed `IncompleteCycleBasis / CycleOrderingFailed`: the corrected multi-component ordering controls are green and S5 now reaches singularity admissibility. EXEC does **not** adjudicate whether the new boundary is invalid retained-field test authority, a production singularity/admissibility defect, or another downstream authority mismatch. That fork is reserved to `M4-CP-SCALE-TB12-R4-REV`.

## 4. Frozen fail-fast stop and immutable postflight

Gate B RED requires immediate stop. Selector426 is therefore **0/426**, all 426 selector rows are explicitly `UNEXECUTED`, and benchmark execution is exactly **0**. The complete initialized execution ledger contains **431 rows**: 4 PASS, 1 RED, 426 UNEXECUTED; ledger SHA-256 is `939610cfbd015e0cc7f10dbf960b7ab978e5dc7e35a399c9ad3065caed6bf74a`.

Package, packaged-source and execution-view byte+mode censuses are identical before/after runtime: package census SHA-256 `a7c1d56e4e72869824289ec28c98b6826d5dabd52b5db10dcafea59c58f6d178`, source census `4c8df81904a501f77f1828fa13353f6078e4012e5d69d4c4bc94fc366d6c58f7`, execution-view census `f769d96c8caf264833fb25227f740e690912ca2616df06125d8e1cad1dc2e50c`. Result `SHA256SUMS` verifies **20/20**. `orchestrationFailure=false`, `postflightComplete=true`, and every prohibited build/repair/mutation/benchmark flag is false.

Result artifact `10528172684` has provider/local SHA-256 `969857f8ee3a94aac15b62ed6b9fb01723908c2b7df1ec3a865e94237394d06e`; log artifact `10527643135` has provider/local SHA-256 `f82a094a27e3ddef02deff71f22b3c51eef9c722b1c1220608b5696e1ea54a72`.

## 5. Regression/accounting disposition

`M4-CP-SCALE-TB12-R3-EXEC-CAND-01 / RP-02` receives direct corrected-control runtime evidence: its replacement Gate-A control is GREEN, but closure remains Review-owned. `M4-CP-SCALE-TB12-R1-EXEC-CAND-01 / RP-07` receives the required post-CB16 production retry: the old cycle-ordering failure no longer owns the observed boundary, but S5 is still RED at `SingularityMismatch`. EXEC therefore opens `M4-CP-SCALE-TB12-R4-EXEC-CAND-01` as **OPEN / S5 SINGULARITY-ADMISSIBILITY RED / REVIEW REQUIRED / NON-STABLE** without assigning a root-cause class or stable pricing before independent Review.

Accepted runtime authority remains package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. `M4-CP-SCALE-DEFN-OBS-04` remains open because the genus-two topology precondition is proved while admissible atlas authority and A3 reachability are still unproved.

## 6. Process-control note

Start-of-turn source reconciliation used exact snapshot artifact `10527943318` from run `35296152714`, resolving source SHA `46bbc62a1018b6278ddd8229b7d323681845fad6`; stale CB17 local scratch changes compared byte-identical to that authority, so no local-only WIP required Drive preservation. During startup, several repository reads occurred before the required explicit `READ_MODE=snapshot` policy gate, and the temporary runtime caller was first published before its SchemaStore validation job ran. After detection, source/document inspection stayed on the verified snapshot; the runtime workload was gated behind and executed only after its exact caller passed the reusable SchemaStore validator. These are control-plane process misses, not semantic evidence, and no retry or result substitution occurred.

Exact successor is runtime-free `M4-CP-SCALE-TB12-R4-REV`. No runtime retry, selector execution, benchmark, correction, package promotion, S5 credit, or stable repricing may precede Review.

## 7. Stale-evidence closeout

Per `CLEAN_UP_POLICY.md`, TB12-R4 retires the consumed R4 EXEC plan and superseded preceding CB17/R3 per-turn evidence only after their resume-critical facts are preserved in this report, the durable handoff, tracker, changelog, ORIENTATION/ROADMAP, `M4_Consolidated_Record.md` and git history. Retired current-head files are:

- `Architecture_M4_CP_SCALE_CB17_Code_Build_Report.md`;
- `Architecture_M4_CP_SCALE_CB17_Test_Authority_Repair_Code_Build_Plan.md`;
- `Architecture_M4_CP_SCALE_TB12_R3_Artifact_Only_Test_Benchmark_Report.md`;
- `Architecture_M4_CP_SCALE_TB12_R3_Review_Record.md`;
- `Architecture_M4_CP_SCALE_TB12_R4_Artifact_Only_Test_Benchmark_Plan.md`.

The retained per-turn role set is this TB12-R4 report plus `Architecture_M4_CP_SCALE_TB12_R4_Review_Plan.md`. Under `CLEAN_UP_POLICY.md`, the mandatory R4 Review must add folded-document-index entries for the five retired filenames, recovering their line counts from git history and confirming the durable retained home for each.
