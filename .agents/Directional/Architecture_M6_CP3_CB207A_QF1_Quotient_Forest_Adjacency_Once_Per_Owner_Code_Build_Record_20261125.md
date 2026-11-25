# CB-207A — quotient forest adjacency once per owner (2026-11-25 UTC)

## Situation

`M6-CP3-CB-207A-QF1-QUOTIENT-FOREST-ADJACENCY-ONCE-PER-OWNER` meets the compile-only gate. The exact reviewed product change is committed. The package is a compile candidate, not runtime acceptance. The only next turn after the completion beacon is `M6-CP3-CB-207B-QF1-VERIFIER-FOREST-EDGES-BY-CLASS`.

## Background

[Adversarial review X1](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md) and the [exact manifest](gates/Architecture_M6_CP3_CB207_QF1_Quotient_Forest_Cost_Exact_Manifest.md) govern the change. One sorted forest adjacency index per owner replaces repeated construction at path searches. The producer updates its own index on successful forest insertion. Publication validation and the verifier construct their own indices from the supplied forest. Path traversal, errors, record order and owner independence remain unchanged in the reviewed difference. No runtime behaviour or termination claim is made.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed difference | 7,279 bytes, SHA-256 `afcbe25b77152e29f6221b77053b9d3420dab116555a32376ef28aaaf775cfc7`; `src/pipeline/RemeshPipeline.cpp` only, +45/−21. Preimage `57c2251135637beff46a6bf26ada735a2ec3f296b251a32a3445a8bec2fb4a02`; postimage `e52e8dc4ff81fc0ab2fa01c2e6c50020563c6da95d27ed9b98cf42d7839c38d4`. |
| Verified snapshot | [Run 45717707331](https://github.com/akashskypatel/Directional/actions/runs/45717707331), job `139568011879`, source `887a75739c85cbe408710c2eb60658fb0d2c2e38`, artifact `15071210464`, ZIP SHA-256 `32b6550e47c1b0b12870de6cea396ae5e4c8a90735470582955d6e54d01fdc2e`, archive SHA-256 `9647b0da7250a25885605781c0cfed0c7c62b5d0c5c6d271b33f737561326571`, 5844/5844 member checks. |
| Source application | [Run 45718052264](https://github.com/akashskypatel/Directional/actions/runs/45718052264), job `139569326249`, request `2370ad4749291bfa4751c8a614abb0058cbdc27b`, semantic source `db1353d8154f684db9270a856423fee8cdab4f5a`. Transport SHA-256 `f6667ae8d294550e7c4bc6a27b8fd9d6b116cf3af1403ce99c4ce27f3ad80435`. Result `15071081734` ZIP SHA-256 `199d7e637bfc99a5b7f15542de809007d3787c219e892c0ce4d85aa7b62c2664`; log `15070407602` ZIP SHA-256 `6dad05b6e6f0ab0adcd3d68f2f7556e80f95fb248ef8b40086b7ad3666e11fa0`. Apply/push exit 0; staged Drive file retired. |
| Compile | [Run 45718286539](https://github.com/akashskypatel/Directional/actions/runs/45718286539), job `139570111862`, request `1da44e14dcb3d3109e685ba07d101f8a297da3c5`, source `db1353d8154f684db9270a856423fee8cdab4f5a`. Configure, preflight and build passed; runtime skipped. |
| Candidate package | [15070039696](https://github.com/akashskypatel/Directional/actions/runs/45718286539/artifacts/15070039696), ZIP SHA-256 `e52a5f04660a7d1426e26c386cb9f692321687b56d5a5c987c862a13c5b32e90`, 28/28 member checks, root SHA256SUMS SHA-256 `a708feb4d17c8c4de16dacc6497c775ee7da29c42a098064bc9d397be9d69cc0`, source archive SHA-256 `aedee25256c4cd077f6eec5579020e959151f7a58884ff6c2ba48ade5086c59c`. Expires 2026-12-02T23:06:01Z. |
| Compile log | [15071615495](https://github.com/akashskypatel/Directional/actions/runs/45718286539/artifacts/15071615495), ZIP SHA-256 `2e7d0fa6e6073738ca7c22f60fecd6d690e0961c73d480e1ea8b61f4747ac138`. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, source-status files empty, preflight/build exit 0, `DIRECTIONAL_ENABLE_GMP=ON`; GMP and GMPXX link evidence. Two libraries and six executables; executable mode bits preserved. |

`git apply --check` and `git diff --check` passed. Remote application changed one path. The package contains the exact postimage. All 1162 archived regular files match the verified snapshot with the product change applied, except expected control files: `.agents/Directional/agent-dispatch-request.json` only. No local compilation, Directional runtime, test discovery, tests or benchmarks. Compiler cache: 142/143 hits (99.30%).

TB185V remains independently accepted 1006/1006 preactivation. TB184 1005/1005 and CP2 491/491 remain historical accepted results. Stable 67 events / 17 categories / 50 recurrences, witness debt1/deferred81. P1 supported, D-U carried; QF1 remains non-stable. No activation, CP3/497/D0/H4 promotion or J6/E5/CB-190 repair.

### Closeout checks

- [Cleanup run 45718841005](https://github.com/akashskypatel/Directional/actions/runs/45718841005), job `139571806031`, result `15070607932` ZIP SHA-256 `bcb9a7a98fa7e516fd274e6ce2e5179d759a691fb4f69c554e71b047300acc7b`, log `15070493129` ZIP SHA-256 `4d71f7e2eb3e40f8b11a37f035d74cd94cff18afbe9b96ddb722ada34cdb510a`, cleanup commit `af62dd24844fa9dd7e28cfda3b687cf4dbc60a84`. Only the snapshot marker and cleanup manifest were removed; ten durable workflows, request slot and mailbox history preserved. No PR comments were deleted.
- Documentation drift audit: zero errors; existing ORIENTATION size warning. Live navigation reconciled with reviewed order; no normative changes.
- Process limitations: early repository reads preceded full snapshot selection; full mandatory pre-work policy/LESSONS review is not established. Exact tool ledger not retained through compaction. No successor work performed.

## Recommendation

After the completion beacon, start only `M6-CP3-CB-207B-QF1-VERIFIER-FOREST-EDGES-BY-CLASS` in a separate turn. Use the frozen exact CB-207B difference, with the CB-207A postimage as its preimage. The full behaviour-preservation gate TB-EXEC-187Q follows both compile turns and must remain independent.
