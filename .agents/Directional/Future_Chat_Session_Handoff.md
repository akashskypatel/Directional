# Future Chat Session Handoff — Directional

**Status:** `M4-CP3-CB4-R1` COMPLETE / COMPILE GREEN / RUNTIME-FREE / EXACT NEXT `M4-CP3-TB2-EXEC`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP3-TB2-EXEC`, artifact-only Test + Benchmark execution

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- M4 package119 / selector394 **394/394** remains the accepted runtime authority.
- CB4-R1 semantic source `3f909a5a2cfd305d423faf7a260bc465c7b06892` is compile-green and publishes the reviewed §17.12 A2b exact-source-path authority plus the production A3 1:1 binder/single writer.
- Candidate package120 is artifact `10280703200` from run/job `34643014511 / 103407112799`, ZIP SHA-256 `3f0ae49f1549ff2f5c4f821ee1db5bc0314405f8f726c04cecaaf5fa3cdf80a4`.
- Selector403 has 403 rows, SHA-256 `e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802`; rows 1-394 are byte-identical to accepted selector394 (`6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`).
- Package120 contains all four selector-owner binaries plus core/pipeline/API/benchmark compile evidence; package manifest verified **28/28**, GMP/GMPXX is authoritative, and `runtimeExecution=false`.
- Stable regression accounting remains **47 events / 14 categories / 33 recurrences**. Produced-witness debt remains **5**. CB4-R1 executed no runtime, so it creates no runtime regression-accounting update.
- CP3 remains open. Package120 is candidate/unpromoted until TB2 review acceptance.

## What CB4-R1 changed

Normative §17.12 is now implemented at the A2b→A3 boundary:

1. every accepted `GlobalTopologyArc` publishes a canonical non-empty exact ordered source path;
2. split `Mandatory` and `Cut` arcs publish exact strict subintervals and `Trace` arcs publish exact ordered segment support;
3. A2b independently reconstructs/validates that support and includes it in semantic identity;
4. production A3 copies one A2b path 1:1 into one `ConformitySpanInput`, with no family/sign or floating reconstruction;
5. production constructs/independently validates exactly one `GlobalConformityBaselinePlan` immediately after A2b and publishes it as an immutable stage product;
6. A4 remains behaviorally unchanged and does not consume the new A3 product yet.

Nine focused identities were appended as selector rows 395-403. Their runtime proof is owned exclusively by TB2.

## Exact next — `M4-CP3-TB2-EXEC`

Execute `Architecture_M4_CP3_TB2_Test_Benchmark_Plan.md` exactly against immutable package120 artifact `10280703200`.

Required frozen gates:

- immutable artifact/source/manifest/GMP/mode/selector preflight;
- focused rows 395-403, pass A: **9/9** expected;
- focused rows 395-403, pass B: **9/9** expected and deterministic;
- accepted-prefix selector394 compatibility: **394/394** expected;
- cumulative selector403: **403/403** expected;
- immutable postflight with package manifest **28/28** again.

TB2-EXEC is runtime execution and raw-evidence preservation only. It must not compile, patch, repair, diagnose by editing, mutate selectors/fixtures/package bytes, or perform A4 cutover work. After the frozen matrix finishes or blocks, stop at `M4-CP3-TB2-REV`.

`M4-CP3-TB2-REV` is the independent diagnostics/review boundary. Only that review may promote package120 and authorize a later `M4-CP3-CB5` A3→A4 cutover.

## Evidence and planning authority

- normative definition: `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §§17 and 17.12
- CB4-R1 frozen plan: `.agents/Directional/Architecture_M4_CP3_CB4_R1_Code_Build_Plan.md`
- CB4-R1 report: `.agents/Directional/Architecture_M4_CP3_CB4_R1_Code_Build_Report.md`
- selector403: `.agents/Directional/Architecture_M4_CP3_CB4_R1_Required_Green_Selector_403.txt`
- TB2 frozen plan: `.agents/Directional/Architecture_M4_CP3_TB2_Test_Benchmark_Plan.md`
- semantic source: `3f909a5a2cfd305d423faf7a260bc465c7b06892`
- package120 run/job: `34643014511 / 103407112799`
- package120 artifact: `10280703200`
- package120 ZIP SHA-256: `3f0ae49f1549ff2f5c4f821ee1db5bc0314405f8f726c04cecaaf5fa3cdf80a4`
- compile log artifact: `10280878009`, SHA-256 `637255ac10f42363aed0a2af66b220ab436a0f4612b76ded61101f0cfbedb020`
- accepted predecessor: package119 / selector394 **394/394**

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/TB-EXEC.md
conditional_modules:
  - trigger: GitHub Actions artifact/runtime orchestration
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB2_Test_Benchmark_Plan.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R1_Code_Build_Report.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R1_Required_Green_Selector_403.txt
templates_when_producing:
  - turn-based-coding-agent/templates/TEST_BENCHMARK_REPORT.md
do_not_preload:
  - CB4 implementation details unless an execution preflight needs packaged-source ownership mapping
  - superseded CB4 plan details
  - unrelated historical milestone records
```
