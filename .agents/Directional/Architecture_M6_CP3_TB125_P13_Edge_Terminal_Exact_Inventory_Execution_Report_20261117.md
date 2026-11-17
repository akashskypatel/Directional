# TB125 — exact mandatory-edge terminal inventory execution (2026-11-17 UTC)

## Situation

**Scoped MATCH under RA-243 §4.** The immutable CB143 package passed all **950/950** full-gate cases, including newly executed row 950. The separately executed three-case census reproduced the expected Cylinder PASS and BunnyRandom/Vase RED outcomes. The BunnyRandom inventory contains exactly two distinct offending source edges; their parameter values are pairwise different on each edge. TB125 is Test + Benchmark only, not a correction, selector promotion, or independent Review.

## Background — exact immutable authority

- **Review and acceptance rules:** [RA-243](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Inventory_Review_20261117.md) §4. Frozen CB143 source `6857c66b788841f8e400151b6068b2f23be25167`, immutable package artifact `14287742226`, outer ZIP SHA-256 `c35f4dd6c61441794999a55b0068fb41b3ab298d1b473c8ab60048d9b20bdab9`; packaged 28/28 hashes verified, root manifest SHA-256 `ed223aa24e2fd1890c65d8b99970d596c8dd4e6a36cf55d76e54828e9353f95a`, source archive SHA-256 `1c1aa54a35c14370cc9ac76381362e16752cb1e9ebae5e458886ac236894988f`, GMP/GMPXX exact backend, compile-only package (`runtimeExecution=false`). No package repair.
- **Executor source snapshot:** event SHA `544b79edde45290b96c9b6132f794cddceb8da27`, [run 43993303661](https://github.com/akashskypatel/Directional/actions/runs/43993303661), artifact `14287299024`, ZIP SHA-256 `2a0b6b15c8c16c1d5c4eaaaaec2459fe3139769a3ef910050625936a8f33274f`, 5,571/5,571 source checksums valid; source archive SHA-256 `4657952c1ace3d58eed07f43036811f75134455b25dfc5b9954ba7a2564412b0`.
- **Harness:** `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Gate manifest SHA-256 `9a112bd18c4f37248ae8c9fc2c942f9fd19cd67ca4a5236c13f5ed76f95a0290` (950 cases; 1,031 membership and 81 deferred); census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3 cases).
- **Gate:** request event `79c7c661c3a239ca181bc56a95b355e8d4e1551b`, mailbox `m6-cp3-tb125-gate-v1`, [run 43993702283](https://github.com/akashskypatel/Directional/actions/runs/43993702283), runtime job `133740624103` success, result artifact `14289730737`, ZIP SHA-256 `c1754245b4ecbde49ba9bbaf9103cbb7975fdb34d40cae57b4e25b7ac56061c8`, **1,908/1,908** checksums; log artifact `14289951218` SHA-256 `f6573545d321947ecf0d50ae6a04f3aff434a202631d8b0fb8b069716f11be0b`.
- **Census:** request event `c0f4bbc175292ab30c1fd45053f889ff04bb1789`, mailbox `m6-cp3-tb125-census-v1`, [run 43993748585](https://github.com/akashskypatel/Directional/actions/runs/43993748585), runtime job `133744740334` success, result artifact `14289927334`, ZIP SHA-256 `2f5a4b511d1fac710338acba368b3a892f05e5621eb5e0c89dcbb5143e3ff8d6`, **9/9** checksums; log artifact `14290016230` SHA-256 `2365eda2ccd0007d6747ef01aef874ee25f219a710b8c0ecde7e86148db4a584`.
- **Baselines:** TB124 gate artifact `14283755675` ZIP SHA-256 `016b9528c330d60a3202d8594d0d6f37b6c0eb76415cab2f0c93ecc965d30d42` (1,906/1,906 checksums); TB122 census artifact `14217871018` ZIP SHA-256 `91c7273f140fc779e02949a47b9eed6e2da49119910021ff041ab04f4220ebb5` (9/9). All four result ZIPs were independently verified from their SHA256SUMS files.

## Assessment — required checks

| Requirement | Evidence |
|---|---|
| Full gate | 950 planned/executed/passed, 0 RED, 0 missing/skipped/duplicate/abnormal, 1,031 membership, `postflight=true`, `exit=0` |
| Inherited ledger | Rows 1–949 identical to TB124 in **every substantive field**; only log SHA changes where raw diagnostic output varies |
| New inventory test | Row 950 `MandatoryEdgeTerminalInventory.OrdersCutsExactlyAndClassesEqualParameters` PASS, one execution, zero skips |
| Gate inventory | Zero `mandatoryEdgeTerminalInventory` lines in 950 raw logs |
| Raw gate comparison | After normalizing only GoogleTest elapsed times, six rows differ: 164, 173, 175, 176, 195, 477. Differences are only ordering/line joining of `M3_CP4AB_FRAGMENT_DIAG`; exact per-row diagnostic record multisets match. Removing those prints leaves **949/949** inherited logs equal. No semantic output difference is hidden. |
| Census | Cylinder PASS; BunnyRandom RED; Vase RED; zero abnormal, missing, skipped and duplicate; `postflight=true`, `exit=0` |
| Census receipts and terminals | All three substantive ledgers equal TB122 except raw-log SHA. After removing the new inventory lines, and normalizing GoogleTest elapsed times and the process-dependent `GetParam()` object bytes, **3/3** complete raw logs equal TB122; required `FieldTransportAtlas.partition edgePorts`, `FieldAlignedCurveNetwork.vertexOutflowFollow`, `switch-run`, `platform-digest`, and typed terminal receipts are unchanged. |
| Runtime boundary | Gate and census `compile=false`, `relink=false`, `configure=false`, `benchmark=false`; neither executed an unapproved build or modified the immutable package |

**BunnyRandom observed inventory** (`SurfaceCutGraph.mandatoryEdgeTerminalInventory`):

| Source edge | Exact sort order (trace, node, printed t) | Cuts | Distinct parameters | Equal parameters share node |
|---|---|---:|---:|---|
| `(241,251)` | `(107,149,0.29728465697386852)`, `(38,178,0.6954898086630259)` | 2 | 2 | true |
| `(251,278)` | `(92,184,0.24658061360047423)`, `(41,162,0.26252359514325541)` | 2 | 2 | true |

The four printed inventory lines contain **two distinct edges**, each observed twice with identical details. Unique inventoried edges = **2**; unique edges with `distinctParameters < cuts` = **0**. These are **observations only** under RA-243 (P4/P5), not additional MATCH gates. The `equalParametersShareNode=true` value is vacuous for each edge because it has no equal-parameter pair. The decimal `t` values are diagnostic display values; equality and order are derived by the program's exact rational comparisons, not by these decimal strings. Do **not** infer that duplicates are generally impossible or that CB144 is already proven valid.

**Census rejection:** BunnyRandom remains `MandatoryEdgeTerminalOrderUnresolved` at source edge `(241,251)` and fails closed; Vase retains its previous non-mandatory-edge failure; Cylinder remains green. The inventory precedes the existing rejection and does not change output connectivity. No accepted-green loss, new first-failure locus, unexpected control result, or stable regression is established. C3 remains an open non-stable P13-e candidate with newly bounded cause data; O42/O43 remain open. O44/C1 are closed. Stable events/categories/recurrences remain **66/17/49**, debt **1**, deferred **81**, CP2 accepted **491/491**. CP3 and selector497 remain unpromoted; `chainRimSchedules=false`; D11=A, D12=A, D10 deferred, D6 pending.

## Recommendation — strict turn boundary

TB125 is **MATCH** under RA-243 §4. The next **separate Review-only** turn is `M6-CP3-DEFN-P13-EDGE-TERMINAL-EQUIVALENCE-DECISION`. It must use the exact inventory to decide the source owner and safe topology correction before authorizing CB144. The present turn does **not** select, code, compile, test or run the CB144 successor; it does not revise fixtures, selector membership, existing assertions, baseline regressions or PR metadata.
