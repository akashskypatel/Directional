# TB29H RP02 harness correction — Code + Build record (2026-10-23)

- **Turn:** `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION`; RA-138 and RA-139 authority.
- **Type/scope:** control-plane harness only. No Directional binary, compile, relink or benchmark executed (`runtimeExecution=false`).
- **Source:** one file `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` changed; exact applied commit `813d377ed5dec911766d18c2568d438121fb592d`.
- **SHA-256:** previous `be3db020d5292a7ecb3851d4e662cadb08696e4dd1befe0e159c920069b9b412`; corrected `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a` (Git blob `bb643b7689d21a834506d2db5bb0e30b052a1de9`, independently read back).
- **H1:** explicit PASS/RED/INVALID based on exact one RUN, terminal outcome, skip count and exit status; abnormal execution INVALID.
- **H2:** `--self-check <manifest> <expected-count>` and execute-time `EXPECTED_CASE_COUNT` enforce cardinality.
- **H3:** A5 cause extractor includes underscores and hyphens and optional site.
- **H4:** isolated process group per row, group kill and reap before reading a timed-out log.
- **H5:** resources written to `resources/<row>.time.txt`, included in final hashes.
- **H6:** typed reason and first failure confined to first failure block.
- **Validation:** `bash -n` PASS, embedded Python `py_compile` PASS, `--self-test` 12/12 PASS, frozen manifest `--self-check ... 44` PASS, all four invalid manifest copies rejected (1 row, 43 rows, duplicate, unknown kind).
- **Frozen manifest:** 44 rows, SHA-256 `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236`; unchanged.
- **Patch authority:** exact base `7e2e0895b98a928f84045bfa1f9ef1adfb46290b`, full SHA-256 `cd0217bb9a128438ec35eec8d8ab1d6f6433c877673744d662f15c3c41ca7e20`; diff body `541eaa8fb0abe0b1c4c4462a290a9e712191439583d27f255dc966225237182f`.
- **Application:** [run 39898696147](https://github.com/akashskypatel/Directional/actions/runs/39898696147), immutable result artifact `12477509369` ZIP SHA-256 `cb058b52f9f3873b61699a4b6740a37445e8d1013a31256663ac166472ec15b3`; apply job succeeded, `runtimeExecution=false`.
- **Transport:** Drive File ID `1gndGH85WzLSI2088vFN9KZEXXcZDwCm9` permanently deleted after verified push; chat/Library recovery copy retained.
- **Limits:** this is implementation/static verification, not independent Review, not TB29 runtime release; CP2 accepted 491/491, TB28 462/497 remains a candidate, stable 66/17/49, debt 1.
- **Authorized next turn:** `M6-CP3-TB29H-RP02-TARGETED-ARTIFACT-HARNESS-CORRECTION-REV` — independent Review re-runs exact static validations, adjudicates classifier and reasons before TB29 may resume.
