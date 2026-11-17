# TB127 immutable guard and rotation-locus execution — in progress (2026-11-17 UTC)

**Canonical turn:** `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-EXEC`. This is an execution checkpoint, not a MATCH, MISMATCH, acceptance, or completed-turn record. Follow [RA-246 §5](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md#5-tb127-frozen). Do not start the successor or dispatch duplicate executions.

## Immutable authority and preflight

- CB146 semantic source `48e6f97d278b2226036f658ce9060a38b8a374b5`; package `14301616031`, [compile run 44022151247](https://github.com/akashskypatel/Directional/actions/runs/44022151247). ZIP SHA-256 `457a9d061cbfe290baa1cad0b3df29b085f81f639dd8ea7e829e38aea6458984`; all 28 internal hashes pass; GMP, runtime-free compile boundary, archived executable modes preserved.
- Executor snapshot `21309c49bb7fba212fdfa1ec27e923404916e131`, [snapshot run 44024046070](https://github.com/akashskypatel/Directional/actions/runs/44024046070), artifact `14302187146`; ZIP SHA-256 `3466a2af85c2ceebff31c69e2a5165692131150b3b4326734fd1a2c5179b077a`; 5,512/5,512 file hashes pass. Compare to semantic source shows only documentation/control changes. Both CB144B and CB146 exact changes and postimages verified.
- Frozen gate `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f` (951 rows), membership ledger `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 deferred), census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3 rows). Existing harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Both manifest self-checks pass.
- TB126 comparison authority: gate artifact `14294372593`, ZIP SHA-256 `c13a0f5e29ab961a6c6d7a31c2883cfaafbdc577d5727f291eb127e9cc8ea55e`, 1,910/1,910 hashes; census artifact `14294313207`, ZIP SHA-256 `79acdba05b737e6987a39d3908ce7bf3f9375f4c051b5c4a35566670b63eb95f`, 9/9 hashes. Raw ledger hash, selected-case binding, execution boundaries independently verified. TB126 gate 950/951, row 951 exception; census Cylinder PASS 288, BunnyRandom and Vase RED.

## Registered executions

| Work | Request event SHA | Actions run | Mailbox key |
|---|---|---|---|
| Full gate, 951 rows | `f5e23873d5ebccb83687388dd78330aa2c162802` | [44024527625](https://github.com/akashskypatel/Directional/actions/runs/44024527625) | `m6-cp3-tb127-gate-v1` |
| Census, 3 rows | `91ad92da0476dfda290ee8fe877488556f7dcb81` | [44024687415](https://github.com/akashskypatel/Directional/actions/runs/44024687415) | `m6-cp3-tb127-census-v1` |

Gate validation, parse, checkout and harness contract passed. Runtime job `133841749525` in progress; census pending behind the gate in the serialized dispatcher. Result artifacts, runtime verdicts and terminal suffix not yet observed. Both request event commits freeze their inputs; do not replace the pending census by another dispatcher request. No source/test/fixture/selector/manifest/build change and no successor work.

## Same-turn continuation

1. Read the two exact Actions runs and their immutable published mailbox records on ref `workflow-mailbox`. Do not trigger another gate or census merely because a run remains in progress.
2. Download both result artifacts once terminal, verify provider and internal hashes, all raw log bindings, and compare with TB126 against RA-246 §5. Gate: 951/951 and all 950 inherited substantive records, allowed elapsed/newline framing only; no inventory lines. Census: identical normalized non-terminal lines, exact earlier terminal prefixes, four equal BunnyRandom inventory lines, Cylinder PASS 288 and nonempty BunnyRandom rotationReason. Record the suffix verbatim. CB146 adds 61 source lines before the census assertions; report any resulting line-number differences explicitly, without broadening the frozen normalization.
3. Record exact classification, update the tracker (stable 66/17/49 and debt1, deferred81 unless evidence warrants a change), handoff, TODO and changelog. Keep C3/C5 unresolved until applicable adjudication. No CP3 promotion.
4. Clean only this turn's temporary snapshot trigger `.agents/connector-triggers/source-snapshot/tb127-20261117.txt` through the documented cleanup workflow after evidence collection; preserve the durable dispatcher, request slot, mailbox records, and PR #8 draft. Final STATUS only after durable closeout. Current turn stays TB127; route only on verified outcome and do not execute the successor in this turn.

## Bounded response yield (05:39 UTC)

The gate remains in progress and the census remains pending. Both exact request hashes and run identities are verified. The repository-applicable handoff/TODO delta is preserved, not applied: base `21309c49bb7fba212fdfa1ec27e923404916e131`; full SHA-256 `7b126ff10643f006b4946a1853415c8ccb3bbb4aa17c1152ff4ce2cd12ce299e`; diff body `33fe0a43877b9a7f3357809027c0eceb24141bf87dfe9600e7de09aeda903c9e`; 6,596 bytes; `git apply --check` and `git diff --check` passed. File Library `/Directional/Directional__M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-EXEC__base-21309c49bb7f__work-preservation.patch`; staged at Google Drive File ID `1amMuHSmPce0KjirLQ-X63qq2dmmKwYcD`, metadata checked. No drive_apply request while census remains pending: the serial dispatcher can replace a pending request. Reconcile the preserved patch on resume; if runtime evidence is ready, supersede it with a single verified final documentation delta rather than apply stale checkpoint text. Cleanup and result-dependent durable updates remain pending, not skipped. No change to stable regression accounting, accepted selectors or product verdict. Resume the same TB127; do not rerun or advance.

## Verified full-gate result (05:41 UTC)

Run [44024527625](https://github.com/akashskypatel/Directional/actions/runs/44024527625) completed successfully; mailbox attempt 1 confirms exact event and semantic source. Result artifact `14302887671`, ZIP SHA-256 `017ad5589ae533d4f428312bc59d92409906544f6cd1add1a3db0ccc80383050`; 1,910/1,910 internal checksums, all 951 raw log bindings, exact manifest identities. 951/951 PASS, 0 RED/skipped/missing/duplicate/abnormal, membership 1,032 (951 gated/81 deferred), postflight true, exit 0, no compile/relink/configure/benchmark. Row951 PASS without exception; no gate inventory lines. All 950 inherited substantive ledger rows match TB126; raw differences only permitted newline framing after elapsed-time normalization in rows 156/168/173/175/190/191/477/705. Gate criterion MATCH. Census run 44024687415 now in progress. Overall TB127 verdict pending. Do not rerun gate, promote selectors, close C3, or start successor. The staging patch remains unapplied; reconcile or supersede it when closing the turn.
