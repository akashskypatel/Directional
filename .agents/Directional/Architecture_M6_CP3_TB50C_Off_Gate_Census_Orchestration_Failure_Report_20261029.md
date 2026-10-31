# M6-CP3-TB50C — off-gate census orchestration S5 (2026-10-29)

**Disposition:** 0/408 native cases executed; no semantic verdict and no new stable regression. Frozen harness/manifest cannot be edited during this TB-EXEC. Separate independent Review authority required; exact successor UNKNOWN — STOP.

## Verified CI evidence
- Workflow: https://github.com/akashskypatel/Directional/actions/runs/40952631880; event commit 0450ce8bf6f9051a64674356ae58a0d84ea8b300. Schema validation, dispatcher parsing, mailbox publication succeeded; runtime job 123724944405 failed.
- First failure: ValueError: row 360: invalid gtest name. Exit 90. Execution boundary: planned=0, executed=0, passed=0, red=0, postflight=false; compile/relink/configure/benchmark all false. Native package never downloaded.
- Result artifact 12931689114 ZIP SHA256 8f4c77b4b38ade37573c9c2418c418af275c19cfe8d63bf02ebb424c63fd496f; diagnostic log 12932571127 ZIP SHA256 4b57abcb8ddc7eefdf9287da711fef7b352df2300295af8f14dc223c9a2cf8d7. Downloads match, internal result checksums 2/2 PASS.
- Frozen 408-case manifest Architecture_M6_CP3_TB50C_Off_Gate_Census_Case_Manifest.tsv SHA256 800e7f26d7ef89357ae07002439f418f867e686c48471f9ef581fb676b88e005. Rows 360–365 contain valid slash-qualified parameterized GoogleTest names UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/{BunnyRandom,CloseSheets,Cylinder,MultiFaceSeam,Plane,Vase}.
- Unchanged harness .agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh SHA256 142321061c57d130a9c73548ce93f52147ebeaeb4c45d3d1c48830e72e2ef93d only accepts unparameterized Suite.Test names. Local harness-only --self-check reproduced row-360 rejection; --self-test passed 12 harness cases; neither executed native tests.
- Additional static-only latent incompatibility: the harness marks every GUARD RED as unexpected-control-failure while RA-170 authorizes off-gate REDs as observation data. Not claimed as a CI runtime observation.
- Immutable CB52 source 7cf0857b4818186638ce77e4859adacbeebd288f, package 12918290481 unchanged; prior selected TB50-R2 508/508 candidate and CP2 491/491 accepted unchanged. Regression totals 66/17/49, debt1 unchanged. No CP3 promotion.

## Required decision
Independent Review/plan must freeze a distinct orchestration-only correction and named rerun. It must accept exactly valid parameterized names, observe PASS/RED/crash/timeout without suppressing evidence, still reject missing/duplicate/skipped or incorrectly selected cases, and preserve all 408 identities, assertions, source/package, and prior full gate. No correction or next turn ID is currently authorized; do not rerun identical request or start TB50-REV. The stop is a review/authorization prerequisite, not a connector safety-check or Drive transport failure.
