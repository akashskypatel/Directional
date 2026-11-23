# TB169 — region-visit reader immutable full gate (execution pending)

## Situation

Canonical turn `M6-CP3-TB-EXEC-169-P13-REGION-VISIT-READER-FULL-GATE` remains **IN_PROGRESS**. The existing artifact-only GitHub Actions run [45104059492](https://github.com/akashskypatel/Directional/actions/runs/45104059492) was triggered by dispatcher request commit `9cd25dea9cd0101998d7c298d8c255a119d7ab6e`. At last observation, `test_benchmark / runtime` was in progress. There is no result or acceptance claim yet.

## Background

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 is draft, open and unmerged.
- Immutable semantic source: `b2e976f204fa5b2988a9cbe5a77defd106a96aad`.
- CB188 GMP/GMPXX compile run `45101939539`; tested package artifact `14786260085`, ZIP SHA-256 `d877a0ea4c05cfe93275506823652abb6b0e012dd3a5925103606e28e69625a5`. The package and its internal SHA256SUMS were verified before dispatch. Do not rebuild it.
- Frozen 993-case manifest: `.agents/Directional/gates/Architecture_M6_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Case_Manifest.tsv`, SHA-256 `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436`. Deferred membership ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- Executor commit `8cd169210fee847bc608e87ee8af4d797983c64a`, harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Dispatcher mailbox key `m6-cp3-tb169-region-visit-reader-full-gate` on ref `workflow-mailbox`. Read that key's `latest.json` after publication; do not trigger a second run merely because the mailbox is pending.
- Prior TB168 gate result `14781634158` ZIP SHA-256 `db2f8f2981c7c2ac914f59598a1e40c553ea8b94b21a23e41b84e74dd1aafb09`, verified with its 1,994 recorded internal checksum entries. TB168 baseline: 993/993 PASS; CP2 491/491; membership 1,074.
- Exact control-plane source snapshot run `45103651288`, artifact `14786099035`, event/source SHA `554c29a8327dd3f41b79e293c68aeeac086713b2`; its archive and 5,776 files passed checksum verification. It was for read-only inspection, not compilation.

## Assessment

The frozen TB169 decision requires 993/993 PASS, CP2 491/491, membership 1,074, no rebuild/census, and zero comparison differences against TB168 except four exact row-979 face-count corrections. Faces `6-8-9`, `16-20-21`, `32-33-34`, `40-45-46` must each read `traceChordCount=4`, `expectedFragmentCount=5`, `ownerCount=5`, `ownerDeficit=0`. The typed outcome must remain `SourceFaceCarriesMultipleTraceCuts sourceFace=6-8-9`. All other row-979 text must remain unchanged. Other rows compare under N1 Google Test elapsed-time, N2 line endings and N3 complete diagnostic-record multiset only, with no further allowance.

A read-only independent comparator was preserved in **ChatGPT Library** at `/Directional/Recovery/TB169_Independent_Comparator_20261123.py`, SHA-256 `7dcba90852123763f4647cee5d68ee7baab421ac20af471c08a164f056939b3d`. It takes extracted TB168 gate directory, extracted TB169 gate directory and report JSON path. It checks whole checksums, per-case hashes, ledger fields, membership, normalized raw records, row-979 four-face limits, and immutable execution fields. The comparator is unexecuted against TB169 until its result arrives; syntax was checked. It does not execute Directional binaries.

The exact snapshot was selected under the source-read policy, but several direct document/source reads were mistakenly made before materialization; this is a tool-use policy miss. Source inspection was corrected to the verified snapshot. It did not alter semantics, selectors, package or runtime.

Stable regression account remains unmodified pending evidence: 66 events / 17 categories / 49 recurrences; witness debt 1; deferred 81. No product or CP3/497/D0/H4 promotion is claimed.

## Recommendation

1. Recover result only from **existing run 45104059492**, using the matching orphan-mailbox record (fallback: exact run jobs/artifact inventory).
2. Verify both ZIP and internal checksums. Execute the independent **offline comparator** on the two immutable evidence directories. No local Directional binary, rebuild or relink is authorized.
3. If full gate matches, publish TB169 execution report, update regression tracker/hand-off/TODO/CHANGELOG, clean only temporary source snapshot trigger, and publish final repository-root STATUS `COMPLETE` with exact successor `M6-CP3-TB-REV-169-P13-REGION-VISIT-READER-FULL-GATE`. Do **not** begin successor work in the TB169 turn.
4. If evidence is incomplete at response closeout, keep `STATUS: IN_PROGRESS`, preserve the same canonical turn and its original start time. Resume this run without duplicate execution.
