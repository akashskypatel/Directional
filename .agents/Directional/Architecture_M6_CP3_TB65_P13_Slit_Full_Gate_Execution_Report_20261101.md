# TB65 — slit-cycle-basis immutable Linux full gate and P13 census (2026-11-01)

**Canonical turn:** `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC` (artifact-only Test + Benchmark). **The RA-192.6 pre-registered outcomes matched.** Full gate **869/869 PASS**, membership **950** (869 GATED + 81 DEFERRED). The independent, OBSERVE-only census returned **Cylinder PASS / BunnyRandom expected RED / Vase expected RED**. This is not CP3 acceptance, selector497 promotion, or a claim that BunnyRandom or Vase produces a valid quad mesh.

## Immutable authority and reproducibility

- Exact CB66 source: `911840c195b52ce1800b3ac7ff3ea7380137ad9c`.
- Compiled Linux Release/static GMP/GMPXX package artifact: `13067780359`; ZIP SHA-256 `b84539426a337c84396b74774a9cecefa7f97059fb4aa8499b45e9b1a2e8ac77`; root `SHA256SUMS` SHA-256 `a594107d611ab74ee5b5836664fb080abc4f5df2a3113934d5b95ee107cbe0b4`; source archive SHA-256 `434e85efafec48bca1d3e70ce12798d15e48a86acde38f697353c562bea613e1` (verified at CB66 compile/package, not rebuilt for TB65).
- Unmodified artifact-only harness: `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Full-gate manifest: `Architecture_M6_TB65_P13_Slit_Cycle_Basis_Full_Gate_Case_Manifest.tsv`, 869 rows, SHA-256 `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`; 81 deferred rows in v5 ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- Independent 3-row census: `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, no deferred ledger.
- Test runtime was launched by the durable operation dispatcher with exact immutable source/package and no configure, compile, relink, repair, mutation, or benchmark execution.

## Runs and verified results

| Evidence | 869-case gate | 3-case census |
|---|---|---|
| Request / mailbox key | `m6-cp3-tb65-slit-gate-20261101-v1` | `m6-cp3-tb65-slit-census-20261101-v1` |
| Event SHA | `53a6e4239a9588e38e2a719fae593963901efc57` | `f2d3d7a634cd81acc2be6fd0c20b49136a383fd4` |
| Workflow run | [41275216693](https://github.com/akashskypatel/Directional/actions/runs/41275216693) SUCCESS | [41275273919](https://github.com/akashskypatel/Directional/actions/runs/41275273919) SUCCESS |
| Runtime job | `124755980785` SUCCESS | `124758107868` SUCCESS |
| Result artifact | `13071357793` | `13071376917` |
| Result ZIP SHA-256 | `b9064cfa9172d3e2b30b6da401dec287e5ef40f63a55857d5619174d3ad638df` | `f8d6ed26819454ac313ccf687238d3e28304c776a04fe43526d49dedf602eebd` |
| Internal `SHA256SUMS` | **1746/1746 PASS** | **9/9 PASS** |
| Verdicts | **869 PASS, zero RED or abnormal** | **1 PASS, 2 pre-registered RED, zero abnormal** |
| Execution boundary | `postflight=true`, `exit=0`, membership `950` | `postflight=true`, `exit=0`, membership `0` |

Independent analysis after downloading each ZIP once: validated the ZIP archive, verified every `SHA256SUMS` entry, all 869+3 ledger-to-raw-log SHA-256s, every one-test GTest selection and corresponding passing/failing evidence, and all per-row `resources/*.time.txt` receipts. No missing, duplicate, skipped, unexpected pass, control failure, later positive RED or abnormal entry. Membership contains precisely 950 distinct `(binary,test)` names: 869 GATED and 81 DEFERRED. Deferred tests were not executed. Dispatcher jobs for compile and Drive apply were SKIPPED, while both test jobs, workflow validators and mailbox publishers completed successfully. Both mailbox pointers were independently read on orphan ref `workflow-mailbox`; source/event identity matches.

The new guards in rows 867–869 all PASS:
- `ra192:slit-two-sided` — `FieldTransportAtlas.IsolatedInteriorBarrierEdgeIsATwoSidedSlit`.
- `ra192:slit-with-arc` — `FieldTransportAtlas.SlitsAndABarrierArcShareOneCutTransportDomain`.
- `ra192:torus-slit` — `FieldTransportAtlas.TorusSlitKeepsBothHandlesOrFailsClosedAtTheSlit`.

## Independent P13 design-acceptance census

1. **Cylinder** `offgate:362`: PASS, source-authoritative direct pure-quad production test succeeded (12.82 s measured by resource receipt).
2. **BunnyRandom** `offgate:360`: expected RED. `terminal=InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`; topology region 0 reports `cutChi=-5`, `uncutBoundaryLoops=0`, `cutBoundaryLoops=7`. The former `CutTransportDomainIdentityMismatch` is absent. The test still rejects the absent quad output; the remaining P13-e port-count mismatch belongs to separate Review/Definition.
3. **Vase** `offgate:365`: expected RED. `terminal=NotProductionReady:completion`; `completion=SideSubdivisionRepair:InvalidInputIncidence`; `detail=None`; `traceSegments=192482`; output is not produced (3:02.47 measured). Remaining P13-d/O18 completion incidence belongs to separate Review/Definition.

These are pre-registered OBSERVE-only failures and **not** accepted-gate regression losses. They do not warrant stable-count increases or accepting either failing production fixture. No unregistered runtime signature change was seen.

## Accounting, boundary, and authorized next turn

Last accepted semantic runtime is still CP2 **491/491**. Stable regression accounting remains **66 events / 17 categories / 49 recurrences**, debt **1**. Selector497 remains unpromoted; CP3 design-acceptance is not granted. MacOS O16, O17, O18, O19, O6/O9, DR1/DR3, DR2/DR4, P13-d and P13-e remain separately owned or deferred per RA-192. No code, test, fixture, harness, selector or reusable-workflow mutation was performed by TB65. **No TB65-REV and no TB65A orchestration retry are triggered**, because the gate and census match the frozen outcomes.

The next independent turn per RA-192.7 ordering is `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (Review/Definition; P13-d with O18), followed by separate post-TB65 `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` for BunnyRandom vertex 49. Neither successor is started here.
