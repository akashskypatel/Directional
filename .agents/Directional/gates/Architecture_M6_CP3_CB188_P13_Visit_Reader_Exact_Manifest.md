# CB-188 exact deferred source-change manifest (2026-11-23 UTC)

**This file is a review artifact. The diff is not applied to live product source.**

- Frozen semantic baseline: `486704038a6bf659a253a2e2f99edde5d03c7ffe` (compiled CB-187 package `14781561211`).
- For CB-189, the preimage is the **postimage of CB-188**, never the current live baseline.
- Patch: `Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Exact.diff`; SHA-256 `5f06c14baca2c35874ae74d48ea98809fe7eeefb57276b0be94c918005d05944`; bytes `5171`.
- Source file `src/geometry/GlobalTopologyPlan.cpp`: expected preimage SHA-256 `e1e186541960dceffb596fc484386eb3a8cdbe7ca8ebd8a66a37c5a48a3db459`; postimage SHA-256 `5af71bc023c494a1a5a8ddeb3bb150c347941faa14e64e1e508b0113a8650aae`.
- Header `include/directional/geometry/GlobalTopologyPlan.h`: expected preimage SHA-256 `277cde20c20864e5d9e60d668aca5bf00ca37e41eeb9983e93ed8bdaafd38f19`; postimage SHA-256 `277cde20c20864e5d9e60d668aca5bf00ca37e41eeb9983e93ed8bdaafd38f19`.
- Contract: R1–R4. Exactly one shared per-arc visit list; cut-versus-edge-only ownership; keep all segment-based diagnostics/barriers and the excess ceiling.
- `git apply --check` against the exact preimage and `git diff --check` passed in a temporary preview; the stacked source passed C++20 `clang++ -fsyntax-only` with GMP defines. No build, linked binary, runtime test or benchmark was run in this review.
- Scope: do not edit tests, selectors, fixtures, benchmark data, CMake, or CI workflows as part of this frozen source diff. Any Code + Build turn needs its own compile-only evidence. TB work is separate and artifact-only.
- The retained 993-row TB168 manifest `gates/Architecture_M6_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Case_Manifest.tsv` remains unchanged. Exactly 81 deferred identities remain deferred; CP2 491/491 is unchanged.
- Strict stop: any mismatched preimage or source path, unplanned changed row, extra owner, or changed accepted result stops acceptance. Do not silently alter tests to recover green.
- TB169 prediction: row979 faces `6-8-9`, `16-20-21`, `32-33-34`, `40-45-46` each show `traceChordCount=4`, `expectedFragmentCount=5`, `ownerCount=5`; staged stop remains `SourceFaceCarriesMultipleTraceCuts` at `6-8-9`; rows other than 979 identical under N1–N3. An unexpected changed row is a stop, not a new accepted behavior.
