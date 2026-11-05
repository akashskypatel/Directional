# TB82 — immutable source-vertex fan-seed full gate: in-flight execution (2026-11-05)

**Current canonical turn:** `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-EXEC` (Test + Benchmark, artifact-only Linux). This is an **in-progress transport/execution record, not a runtime result, acceptance or closeout**.

## Frozen authority and independently verified package preflight

- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8.
- Semantic source `d9921cdd5a174bbb00b68387082cf08df80f97c5`; CB92 compile [run 42052009404](https://github.com/akashskypatel/Directional/actions/runs/42052009404), immutable package artifact `13427203329`.
- Downloaded package ZIP SHA-256 `fb547adcc5bede25d3df2a79f6656ec83cf142907ce77cb5a5a4a3f287a5c2ca`, independently verified; ZIP CRC PASS; all 28/28 packaged `SHA256SUMS` entries matched their raw bytes.
- Root `SHA256SUMS` SHA-256 `8c321c9e2f886766a65e235d931d371589478ea3b309276343e9b2b9ccb09636`; embedded source archive SHA-256 `812a45d787a03655b4457d0a1456bc5c17afd4820ace05d81bec9175d187b66d`.
- All six packaged executables have ZIP Unix mode `100755`; source-commit metadata matches. Packaged GCC GMP/GMPXX link evidence names `libgmpxx.so` and `libgmp.so`; runtime dynamic-library resolution remains a runner-side preflight.
- Existing harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`, verified from exact packaged source archive.
- 901-case manifest SHA-256 `9fbf329167cbe84698d5a08eda6e5374200c7729a5f0f1e4292836227902f878`; 81-entry deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; three-case census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.

## Submitted immutable jobs — no rebuild

1. **Full gate:** [run 42057136562](https://github.com/akashskypatel/Directional/actions/runs/42057136562); trigger commit `464f4aa18119335085ce40421fe11df735003905`; request/mailbox key `m6-cp3-tb82-gate-20261105-v1`; 901 cases, expected membership 982. Initially in-progress; runtime job `127348730851` reached `Execute immutable artifact-only gate`.
2. **Production census:** [run 42057191097](https://github.com/akashskypatel/Directional/actions/runs/42057191097); trigger commit `1cbc6fb13aa1c75ae1cea687bb11c9104abed78e`; request/mailbox key `m6-cp3-tb82-census-20261105-v1`; Cylinder/BunnyRandom/Vase. Initially pending behind the serialized dispatcher.

Both requests pin executor commit `12341865b2176c4f97d36e96219132f7b7688e0e`, semantic source `d9921cdd5a174bbb00b68387082cf08df80f97c5`, the verified harness hash, package and manifest hashes. The durable dispatcher request slot now contains the **census** request; each workflow uses its own frozen triggering event commit, so do not redispatch either as a discovery mechanism.

## Exact continuation

- Observe the two specific runs, preferentially using `ref=workflow-mailbox` at `.workflow-mailbox/m6-cp3-tb82-gate-20261105-v1/latest.json` and `.workflow-mailbox/m6-cp3-tb82-census-20261105-v1/latest.json`. Confirm event commits and `test_benchmark / runtime` job results. The initial absence of a mailbox while jobs run is not a failure.
- Once terminal, fetch job/artifact metadata once, download each result artifact once, verify outer ZIP digest, internal `SHA256SUMS`, `execution-boundary.json` and all raw logs/ledger entries; compare rows 795/796/797/864 and census Cylinder/Bunny digest lines to the exact TB81 report; Vase prefix through `global-conformity-baseline` must match TB81.
- Apply RA-207 §5: 901/901 gate, membership 982, Cylinder PASS, BunnyRandom P13-e RED, Vase `SelfIntersectingFace` RED under 600 seconds with counts recorded, all pinned digests. Do **not** pin downstream Vase counts or promote CP3/selector497.
- On MATCH: next separate Review `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (RA-207.6). Semantic mismatch: `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-REV`. Orchestration failure: `M6-CP3-TB82A-P13-SOURCE-VERTEX-FAN-SEED-ORCH`.
- Before COMPLETE, record results in a final TB82 report, regression tracker (including an explicit no-new-stable-event verdict if applicable), TODO, handoff and CHANGELOG; complete end-checklist/drift audit; publish final repository-root STATUS last. Do not begin successor work in this turn.

**Unchanged accepted authority:** CP2 491/491, stable 66/17/49, debt 1. TB81 899/899 remains the latest fully verified candidate until TB82 evidence is adjudicated.
