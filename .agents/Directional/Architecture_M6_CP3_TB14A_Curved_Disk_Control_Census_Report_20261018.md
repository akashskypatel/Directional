# M6-CP3 TB14A — curved-disk control census (2026-10-18)

- Turn: `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS` (artifact-only, unchanged harness).
- Run: [39143325285](https://github.com/akashskypatel/Directional/actions/runs/39143325285), terminal `success`; result artifact `12141843937`; ZIP SHA-256 `1b06e43e87f416e7b44dce65059f1789301f402dd9d43d71fcabf2a3c604d455`.
- Source/package: `2ee499a3403c07be05e8084a669f30c1c735f04a`, compile package `12140756646` with provider/ZIP SHA-256 `eee92aeb38ce098c8580a199f340ec65f3bf650df6464d5a3f2b7dfee5add906`.
- Harness SHA-256: `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`; frozen selector count 497; 1019/1019 result checksums verified.
- Execution: 497/497 selected once; zero skipped; `orchestration_failure=false`; pre/postflight and package/source/execution-view parity passed; no configure, compile, relink, discovery, benchmark, mode repair, source/test/fixture/selector mutation or retry.
- Focused30: **15 PASS / 15 RED**. Focused12: **10 PASS / 2 RED**. Selector449: **400 PASS / 49 RED**. CP3-entry: **0 PASS / 6 RED**.
- Aggregate: **425 PASS / 72 RED**, up from TB13C **420 PASS / 77 RED**; **five** status changes, all RED→PASS; no new RED.
- Selector 199: **PASS** (unexpected; RA-93.4 predicted RED moving off P10:5395 to P10:5428). This is the sole prediction falsifier and requires independent Review.
- Selector 235: **PASS** (expected); 236: **PASS** (expected); 294: **PASS** (expected); 299: **PASS** (expected).
- Selector 237: **PASS** (unchanged); 253: **PASS** (unchanged); 254: **PASS** (unchanged).
- Selector 250: **RED**, first `SurfaceCellsPhase10Tests.cpp:3597: Failure`, `PublishedProductRejected` (unchanged).
- All other 488 identities retain their TB13C status; exact identity+phase+ordinal census is in the immutable `combined-ledger.tsv` result artifact.
- **Classification:** restored curved-disk positive controls are measured; the unpredicted 199 PASS is a candidate contract/fixture-interaction discrepancy, not independently adjudicated acceptance. No new stable regression ID; **66 events / 17 categories / 49 recurrences**, debt **1**, unchanged. R3 403/497 remains rejected; M6 CP2 491/491 remains last accepted runtime.
- **Next:** `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV`, mandatory independent evidence review and plan. No next implementation or TB turn authorized here.
