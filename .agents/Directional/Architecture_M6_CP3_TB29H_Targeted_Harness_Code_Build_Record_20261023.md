# TB29H — reusable targeted artifact harness (2026-10-23)

- Turn: `M6-CP3-TB29H-RP01-TARGETED-ARTIFACT-HARNESS`; authority RA-137.3.
- Source snapshot: `b9b01ad9dcb7ee0e1279520f8327f58dc7b36287`, run `39884956201`, artifact `12471747863`, outer SHA-256 `36a4bcd68786ecb84c37b0fa1ac4de61ff1f4ce313a63c3dc95e01d70895a8c0`; 5,799/5,799 checksums verified.
- Added `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `be3db020d5292a7ecb3851d4e662cadb08696e4dd1befe0e159c920069b9b412`.
- Reusable environment-bound artifact/source/hash and case-manifest inputs; one strict GoogleTest process per reviewed case, multi-binary staging, typed failure text extraction, exact-one selection, fail-closed checks, immutable pre/postflight, and evidence-before-exit.
- Manifest: `Architecture_M6_CP3_TB29_Targeted_Case_Manifest.tsv` SHA-256 `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236` (44 unique identities/tests).
- Static validation: `bash -n` PASS; embedded Python `py_compile` PASS; `--self-check` 44 PASS; duplicate-test and unknown-kind copies rejected as required.
- Boundary: no Directional binary execution, build, compile, relink, configuration, benchmark, selector, manifest, source/test/fixture, or workflow change. Runtime result and semantic acceptance are NOT claimed.
- Required successor: independent `M6-CP3-TB29H-RP01-TARGETED-ARTIFACT-HARNESS-REV` before resuming TB29.
