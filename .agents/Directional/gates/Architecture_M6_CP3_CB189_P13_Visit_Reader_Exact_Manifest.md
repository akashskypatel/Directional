# CB-189 exact deferred source-change manifest (2026-11-23 UTC)

**This file is a review artifact. The diff is not applied to live product source.**

- Frozen semantic baseline: `486704038a6bf659a253a2e2f99edde5d03c7ffe` (compiled CB-187 package `14781561211`).
- For CB-189, the preimage is the **postimage of CB-188**, never the current live baseline.
- Patch: `Architecture_M6_CP3_CB189_P13_Corner_Visit_Reader_Exact.diff`; SHA-256 `35044eca7c56125240efc21f42e5dc32b653428c9338852f84b1e38b5c5fa679`; bytes `18085`.
- Source file `src/geometry/GlobalTopologyPlan.cpp`: expected preimage SHA-256 `5af71bc023c494a1a5a8ddeb3bb150c347941faa14e64e1e508b0113a8650aae`; postimage SHA-256 `7eff6f8825b87fabe69db0f9453aa4adf0467c399e2bf6d65d70868467c26b49`.
- Header `include/directional/geometry/GlobalTopologyPlan.h`: expected preimage SHA-256 `277cde20c20864e5d9e60d668aca5bf00ca37e41eeb9983e93ed8bdaafd38f19`; postimage SHA-256 `87831e100b5f05d2adcbf2a8aea89063d8b63a26939da314eb5896aeeacca16c`.
- Contract: C1–C4. One helper per counted-cut face; exact side-orbit keys including corner-free strips; face-level errors; zero-cut faces unkeyed.
- `git apply --check` against the exact preimage and `git diff --check` passed in a temporary preview; the stacked source passed C++20 `clang++ -fsyntax-only` with GMP defines. No build, linked binary, runtime test or benchmark was run in this review.
- Scope: do not edit tests, selectors, fixtures, benchmark data, CMake, or CI workflows as part of this frozen source diff. Any Code + Build turn needs its own compile-only evidence. TB work is separate and artifact-only.
- The retained 993-row TB168 manifest `gates/Architecture_M6_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Case_Manifest.tsv` remains unchanged. Exactly 81 deferred identities remain deferred; CP2 491/491 is unchanged.
- Strict stop: any mismatched preimage or source path, unplanned changed row, extra owner, or changed accepted result stops acceptance. Do not silently alter tests to recover green.
- TB170 decision: rows other than 979 stay unchanged under N1–N3; row979 either builds a staged plan or yields the next typed stage. Do not assume full output or product promotion from a helper pass.
- Public typed errors: `SourceFaceCutPartitionFailed` with a `FaceCutPartitionReason` and `sourceFace`, and `SourceFaceCutOrbitNotOwned` with `sourceFace`; neither attributes an arbitrary arc.
