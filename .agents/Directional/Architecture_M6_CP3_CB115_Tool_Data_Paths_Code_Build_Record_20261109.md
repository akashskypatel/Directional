# M6-CP3-CB115 tool-data fixed-path repair — Code + Build record

## Authority and scope

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains draft/unmerged.
- Exact snapshot base: `2c38f451d664778ddb237c8488ec78aefb11ad05`; verified 5,402 source file checksums and exact source metadata.
- Frozen patch: `Architecture_M6_CP3_CB115_Tool_Data_Paths_Exact.diff`, SHA-256 `d4b79b8cb2837ce64502d5b263331168ada3b469c584561f9668294b6078be85`.
- The five pre-relocated TSV files in `.agents/Directional/tools/data/` were not changed. The patch only alters 13 fixed path string literals in 13 existing `.sh` harnesses, each once. Net 13 insertions and 13 deletions. No workflow, implementation, gate, selector or fixture mutation.

## Verification

- Exact patch applied cleanly against the verified source snapshot; Git full-index patch generated and checked.
- `bash -n`: 13/13 affected shell files PASS (local static verification).
- Specified grep for old `R4_Historical_R3_A4_39` or `TB34`–`TB37` root-level path references in `.agents/Directional/tools`: zero matches.
- `git diff --check`: PASS. No Directional binary execution, benchmark, test, compile or package was attempted in this static-only data-path repair.
- Durable `drive_apply` dispatcher [run 42677764349](https://github.com/akashskypatel/Directional/actions/runs/42677764349), exact request commit `87fd1519961de3ba87a2a632eecc7bcd01887779`, successfully verified and applied patch SHA-256 `c4792aeb2d2d8bf4e7a9649068c9a81e4404980442da96dfec22f87861a6752d` to commit **`6a5f11a47358443979e8ebbd1c78283f36f6dc2b`** (`runtimeExecution=false`; result artifact `13702110870`). Owner-side Google Drive staging-file deletion succeeded.

## Outcome and successor

**COMPLETE (static-only scope).** There was no semantic Test + Benchmark turn, and accepted CP2 remains 491/491; stable 66/17/49, debt 1, deferred 81, selector497/CP3 unpromoted. The authorized successor, for a separate turn, is `M6-CP3-CB110-P13-A3-MANDATORY-CHAIN-PARTITION` (compile-only); then TB93.
