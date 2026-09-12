# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-TB2-R2-REV` COMPLETE / APPROVED / CORRECTED R4 ARTIFACT + SELECTOR403 ACCEPTED / CP3 OPEN
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Code + Build, `M4-CP3-CB5`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Corrected R4 artifact `10289601000` is the accepted M4-CP3 pre-cutover package authority at exact semantic source `58521f6d1c4fb5d625da7cde50e002cf4688beee`.
- Accepted selector403: `.agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt`, 403 rows, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`, runtime **403/403**.
- Its first394 is byte-identical to accepted predecessor selector394 at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`, runtime **394/394** on the same package.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.
- CP3 is OPEN. Production A3→A4 cutover is now authorized only under the CB5 guard; it has not yet happened.

## Accepted review evidence

Authority: `.agents/Directional/Architecture_M4_CP3_TB2_R2_Review_Record.md` plus retained raw execution report `.agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Report.md`.

```text
R4 package run/job      = 34665925501 / 103477693366
package artifact        = 10289601000
package SHA-256         = ef8c0d87f8dc8ed48269f833ec946f52189f7df63bcdf4c5df6c113f098992b9
package bytes           = 29,764,498
source archive SHA      = b8eb7a8352c587353c0aefda93243050a32f5cd123d6ce50e49a7ca9ce0912f0
manifest SHA / entries  = d6d3c5bbad41394177cf4ef7b522cef47660e47b6865eebb98a702df506dc43b / 28
TB2-R2 run/job          = 34666794115 / 103480225842
result artifact/SHA     = 10289088800 / 2e3bfb39d10c00008479ab5c4b42b428bcdc1b92808646fae23470c4a5704d4e
log artifact/SHA        = 10289438082 / ea2c9cc599e381a4ae5d63128e8dfcc33f8d476a9904aa0fcc6ded3df292058b
```

Review independently re-derived exactly **799/799 PASS**:

```text
row400 focused A       1/1
row400 focused B       1/1
selector394          394/394
selector403          403/403
RED/SKIP/timeout/mismatch = 0/0/0/0
```

Row400 is mutation-discriminating on raw source row `[3,0,4]`, canonical key `[0,3,4]`, canonical weights `[1/6,1/3,1/2]`, locus 4: correct remapped result `1/3`, historical positional defect `2/3`. Package/source/execution-view censuses are byte-identical before/after and manifests pass 28/28 twice.

Closed non-stable candidates: `M4-CP3-CB4-R2-REV-CAND-01`, `M4-CP3-TB2-REV-CAND-01`, `M4-CP3-CB4-R3-REV-CAND-01`.

Carried non-blocking: `M4-CP3-TB1-R1-REV-OBS-01` and `M4-CP3-CB4-REV-OBS-02`.

## Exact next — `M4-CP3-CB5`

Authority: `.agents/Directional/Architecture_M4_CP3_CB5_Code_Build_Plan.md`.

The first action is a **mandatory pre-mutation derivation guard**. For every shared A4 hard-rail segment the cutover will pair, derive exactly one A2b arc/A3 `ConformitySpanId`, exact consecutive breakpoint ordinals and orientation from accepted products alone. Tolerance/rounded geometry, local target/grid counts, synthetic-node allocation order and post-hoc partner agreement are forbidden identity sources.

If any mapping is ambiguous/missing or needs a new upstream semantic convention: **STOP before mutation and return to Review**.

If the guard passes, CB5 may:

1. thread accepted `GlobalTopologyPlan` + `GlobalConformityBaselinePlan` into production A4;
2. materialize accepted shared breakpoints unchanged and publish typed span+ordinal boundary identity;
3. remove floating `support_key` from shared-boundary semantic pairing authority;
4. preserve A4-local `family` / `advanceSign` semantics;
5. reject missing/contradictory schedule identity rather than repair/re-solve;
6. add focused deterministic tests and an accepted-prefix-preserving successor selector;
7. compile/package only through the reusable GMP/GMPXX workflow, with `runtimeExecution=false`.

No Directional runtime belongs in CB5. Exact-torus/fixed-plan acceptance belongs to a later artifact-only TB + Review.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
conditional_modules:
  - trigger: implementation design/correction and surgical source/test changes
    path: turn-based-coding-agent/modules/engineering-guidelines/MODULE.md
  - trigger: CB5 authors or reviews regression/unit tests
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: compile/package through GitHub Actions
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_CB5_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
  - .agents/Directional/Architecture_M4_CP3_TB2_R2_Review_Record.md
  - .agents/Directional/Architecture_M4_CP3_TB2_R2_Test_Benchmark_Report.md
  - include/directional/geometry/GlobalConformityBaseline.h
  - include/directional/geometry/SurfaceCellTracing.h
  - src/pipeline/RemeshPipeline.cpp
  - src/geometry/SurfaceCellTracing.cpp
do_not_preload:
  - unrelated CP3 observations OBS-01/OBS-02 unless the cutover naturally reaches them
  - M5/M6 implementation
  - any runtime/TB executor before CB5 build closeout
```
