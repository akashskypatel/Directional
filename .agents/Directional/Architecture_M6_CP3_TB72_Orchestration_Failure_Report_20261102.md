# M6-CP3 TB72 — immutable gate orchestration failure (2026-11-02)

## Authority and disposition

- Current canonical turn: `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-EXEC`.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains draft.
- Normative TB72 specification: `.agents/Directional/Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md` §RA-199.5.
- **Classification: orchestration failure, not semantic RED.** Required successor: `M6-CP3-TB72A-P13-SUPPORT-CHORD-ORCH`. The attempted full gate has **no test evidence**.
- Immutable CB78 source: `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; package artifact `13181887585`, ZIP SHA-256 `076a19de16db5b0d7be3fb7d133c0324383dde319467afb22b3edc99922658e4`. Locally verified package root manifest `71492e14a774a4f012f84835ba0d746a0e72d724372436f066cedc15ef8ba9b5` and source archive `c8a13798d857c1bb7427d09a63cb5707d89ef6b792f6e08d06fd67bd14e1d357`.

## Failed full-gate attempt — primary evidence

- Dispatcher request: `m6-cp3-tb72-gate-20261102-v1`, event commit `ce3e4feedcd94781d489b574b6d38820d9e94087`.
- [Workflow run 41533361438](https://github.com/akashskypatel/Directional/actions/runs/41533361438), `test_benchmark / runtime` job `125579499288`: failure. Schema validation, request parsing and mailbox publication succeeded.
- Result artifact `13181824688` (ZIP SHA-256 `8c6d09236dada421699c0dcb96cc1d3187f5eba0df559cdbabcda196e1f6a6c0`); harness log artifact `13182204019` (ZIP SHA-256 `80d92cf7cc3d1be608347b2485382604bbb5ca31f17b6f796f017a52748e6237`).
- Harness boundary reports `ValueError: case manifest missing/unsafe`, exit 90, `planned=0`, `executed=0`, `passed=0`, `red=0`, `postflight=false`; `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. No semantic output may be interpreted.
- **Root cause:** request used executor SHA `90c0f28abc174627639f36553934b45d1f4f56ca` copied from TB71, before the newly registered TB72 883-case manifest existed in that executor checkout. Current verified source snapshot `923eae28df6386bec246f29c5032efac777c7ce6` contains `.agents/Directional/Architecture_M6_TB72_P13_Support_Chord_Full_Gate_Case_Manifest.tsv` at frozen SHA-256 `e9eabb064fba1aa625b20931f1b85cf3f441c0c877a81cccd49b73bb5ebd3031`. Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- This is a dispatch-authority selection mistake, not a product defect or a missing manifest in the project. No corrective execution was launched under this failed TB turn.

## Separate census request and limits

- Concurrently prepared census request `m6-cp3-tb72-census-20261102-v1`, event `9cfd1f56c28227016d4bb0f7ad01d5aff0554e86`, three-case census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- At the time of this report the census was not yet independently verified as complete. It is supplementary evidence only; neither it nor the CB78 scratch expectations can establish the failed full gate.
- Existing accepted CP2 `491/491`, unpromoted prior TB71 candidate `881/881`, stable accounting `66/17/49`, debt 1, and selector497 authority remain unchanged. No semantic regression ledger changes are supported by this attempt.

## Corrective task: TB72A orchestration turn

1. Use an exact **verified executor SHA that includes the frozen TB72 manifest**, e.g. snapshot SHA `923eae28df6386bec246f29c5032efac777c7ce6`, after checking harness bytes, manifest, ledger and dispatcher contract at that SHA. Do not alter frozen TB72 manifest or immutable CB78 package.
2. Dispatch the TB72 gate with the corrected executor and the same immutable source/package IDs, SHA-256 contracts and 883 identities. Treat the first run as an invalid attempt and retain its artifacts.
3. Retain the independent census request/result as evidence with its own provenance; diagnose whether a clean second census is necessary. Do not invoke a semantic rerun to bypass a real test failure.
4. Preserve ordinary CB → TB separation, publish normal authoritative gate/census evidence, and route semantic mismatches to the registered REVIEW turn.
5. Complete TB72 tracker/handoff/documentation closeout and maintain the root STATUS lifecycle without beginning Review work under TB72.

## Session housekeeping

- Source snapshot run `41533125112`, artifact `13181184921` verified. Temporary source snapshot trigger cleanup run `41533828130` succeeded, preserving mailbox and durable dispatcher slot.
- A conservation-policy read-mode violation occurred: initial direct multi-document fetches preceded mandatory snapshot selection. Subsequently switched to and verified the required exact source snapshot. This miss must not be treated as verified checklist completion.
- No local build or runtime, test-source modification, or product mutation was performed.
