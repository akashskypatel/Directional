# TB109 — annulus rim-edge schedule full-gate execution (2026-11-12 UTC)

## Situation

**COMPLETE / scoped MATCH.** The immutable CB128 package completed the 944-case gate with **944/944 PASS** and **1,025** memberships. Its three-case production census had Cylinder **PASS** and BunnyRandom/Vase **registered RED**, unchanged from TB108. This is test/benchmark evidence only, not promotion of CP3 or selector497. CB129 is **not authorized** because the row-729 equal-output condition fails.

## Background

- **Canonical turn:** `M6-CP3-TB109-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE-FULL-GATE-EXEC` (64D.5), artifact-only; no source, test, fixture, selector, harness, compilation, relink, configuration or benchmark changes.
- **Immutable CB128 source:** `739e79e240f75ac1c24e659004b13b425803081b`.
- **Compiled package:** [run 43150206247](https://github.com/akashskypatel/Directional/actions/runs/43150206247), artifact `13913578057`, ZIP SHA-256 `1eb3f762034dff9cf31f1ba45362a9f1b371eda35986fc062f3bd521e679f394`, 28/28 package checksums and eight GMP/GMPXX targets built; compile record confirms `runtimeExecution=false`.
- **Full-gate manifest:** `.agents/Directional/gates/Architecture_M6_TB109_P13_A3_Annulus_Rim_Edge_Schedule_Full_Gate_Case_Manifest.tsv`, SHA-256 `46e5c8a8ffb1a8d6337d782bef44fa852d3b17870e2f06ab037d55a8ea201f61`, 944 rows, 1,025 memberships, deferred ledger 81.
- **Full gate:** [run 43155345821](https://github.com/akashskypatel/Directional/actions/runs/43155345821), event `85478405d12b5c9fadfe92c504b3ccbbb7bcce40`, artifact `13916127330`, ZIP SHA-256 `b5757bf58343f31d47df024405ce92510323eafccecc16ac32ec83c7df55885d`.
- **Production census:** [run 43155374160](https://github.com/akashskypatel/Directional/actions/runs/43155374160), event `27513cf95e6d93f850b7f1eefe0a00c245ba0521`, artifact `13915439007`, ZIP SHA-256 `4147c5e2afa15d8deb08dfa26abaf3b47b7e5fc1a2648c1519be309e141ba1d0`.
- **Prior comparison:** TB108 gate `13908358480` (ZIP SHA `ac6a9232e0924e2cb973c11c5c96cb679cf0f7c37a404dc7034f7b4b7a1f6bd1`) and census `13908514778` (ZIP SHA `a136ff56e27bf08297cf9b6dc7ba6c1ca1ba7d1b3568b838428a43c3a8d1dece`).

## Assessment — independent artifact validation

| Control | Verified result |
|---|---|
| Full case ledger | 944 planned / 944 executed / **944 PASS**; zero RED, skipped, abnormal, missing, duplicates, unexpected PASS, control failure, or later-positive RED |
| Membership | 1,025; row 944 is the new annulus rim reader test |
| Full-gate SHA256SUMS | **1,896/1,896** entries valid |
| Inherited case records | First 943 substantive ledger rows match TB108, excluding per-process log digests |
| Full-gate inherited receipts | 19/19 unchanged, plus 4/4 `rim-branch` and 12/12 `annulus-rim` lines unchanged |
| Census result | Cylinder PASS; BunnyRandom and Vase registered RED; no unexpected changes |
| Census SHA256SUMS | **9/9** entries valid |
| Census inherited receipts | Six lines unchanged: three `platform-digest`, three `a3-coverage`; all substantive ledger rows unchanged |
| Total receipt equivalence | **41/41** unchanged (19 gate + 6 census + 4 rim-branch + 12 annulus-rim) |
| Execution boundary | Both report exact CB128 source/package, postflight true, exit 0, and `compile=false`, `configure=false`, `relink=false`, `benchmark=false` |

The new row-729 receipt is **verbatim**:

```text
annulus-read case=CommittedCylinder rimEdges=32 readable=32 equalOutput=24 outputRimEdges=56 recorded=0
```

RA-228 §5 requires `recorded=0` and `outputRimEdges>0`, both met. Its **conditional permission for CB129 fails**: `readable=32`, but `equalOutput=24` differs from `rimEdges=32`. This is a pairing/count-consistency design issue to resolve in a separate Review. This result is not a reason to change the existing test oracle or claim production acceptance.

The existing production failures are unchanged: BunnyRandom stops with `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch`, and Vase with `NotProductionReady:completion` after 189,462 traces, 26,817 arrangement cells and 67,750 partial completion quads. Their two RED verdicts are already registered as non-stable candidate limitations and do not add a new stable regression event.

Stable accepted CP2 remains **491/491**; regression accounting remains **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. O36 remains unwired. CP3/selector497 remain unpromoted; PR #8 remains draft/open/unmerged.

## Recommendation

Close TB109 as **COMPLETE / scoped MATCH**, with the *next separate Review-only* `M6-CP3-DEFN-P13-A3-ANNULUS-RIM-PAIRING` (RA-228 §5). It must determine how A3 maintains equal paired rim counts at row 729 before any CB129 implementation. The implementation agent must **not** apply the frozen CB129 patch, begin TB110, modify O36, or promote CP3/selector497 in this turn.

Verification was performed from downloaded raw ZIP artifacts and an independent read-only Python checker. The previous session's repository read-mode sequencing miss was a procedural issue and did not change the immutable runtime evidence. No fresh build was run.
