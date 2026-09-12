# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-CB4-R2-REV` COMPLETE / RUNTIME-FREE / `rejected_and_replaced`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Code + Build, `M4-CP3-CB4-R3`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Package119 / selector394 **394/394** remains accepted M4 runtime authority.
- Package120 / historical old selector403 remains mechanically **403/403** but **unpromoted**.
- Historical old selector403 SHA-256 remains `e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802`; accepted first394/selector394 remains `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.
- CP3 is open. A3→A4 cutover remains unauthorized.

## Review disposition

Authority: `.agents/Directional/Architecture_M4_CP3_CB4_R2_Review_Record.md`.

The CB4-R2 STOP-GUARD is upheld: A2a contact coordinates are formed directly in canonical `SourceFaceTopologyKey` order and A2b exact-path publication copies them. The frozen CB4-R2 plan incorrectly required a raw-row→canonical producer remap that does not exist, so that plan is rejected rather than bypassed.

Independent review found the real basis seam in A2b rotation ranking. `build_source_index` preserves raw oriented `SourceFaceRecord::vertices`; boundary/vertex second-point branches return raw-order barycentrics, while the terminal-contact branch returns canonical `terminalContact->barycentric` unchanged. `vertex_locus_secondary_parameter` then indexes every returned array by raw-row positions.

Exact static falsifier on existing `make_four_triangle_fan()` row 3:

```text
raw row       [3,0,4]
canonical     [0,3,4]
canonical w   [1/6,1/3,1/2]
locus         4
correct exact secondary parameter = 1/3
unmapped positional result         = 2/3
```

New `M4-CP3-CB4-R2-REV-CAND-01` is PRODUCT / COORDINATE-BASIS AUTHORITY MISMATCH / NON-STABLE / SOURCE-PROVED, RUNTIME-UNPROVED. No accepted-green loss was observed.

`M4-CP3-TB2-REV-CAND-01` remains a valid test-authority finding, but its corrective subject is replaced: old row400 must be replaced with a regression for this actual A2b consumer seam, not a fictitious producer remap.

## Exact next — `M4-CP3-CB4-R3`

Authoritative plan: `.agents/Directional/Architecture_M4_CP3_CB4_R3_Code_Build_Plan.md`.

Bounded semantic scope:

- `src/geometry/EmbeddedGraphTopology.cpp`: terminal-contact branch of `vertex_trace_ray_second_point` only; remap canonical contact components by vertex identity into raw oriented `SourceFaceRecord::vertices` order expected by downstream ranking;
- `tests/FieldAlignedCurveNetworkTests.cpp`: replace old row400 with the exact noncanonical-row/distinct-weight `1/3` vs `2/3` discriminator;
- create a **new** 403-row R3 selector by replacing only old row400's test name; do not mutate historical selector403 in place;
- accepted first394 must remain byte-identical at `6c27b3a0...`; owner totals remain `30/257/75/41`;
- compile/package only through the mandatory GitHub reusable workflow with GMP/GMPXX; `runtimeExecution=false`.

Future artifact-only gate, if CB4-R3 packages successfully: replacement row400 twice + selector394 394/394 + successor selector403 403/403 = **799 fresh processes**, then review before promotion.

## Carried obligations

- `M4-CP3-TB1-R1-REV-OBS-01`: multiplicity weighting still only `[1,1,1]`; keep outside CB4-R3.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` consistency tamper remains outside CB4-R3.
- No A3→A4 cutover or exact-torus pairing work before corrected package acceptance.

## Review provenance

- reviewed semantic source: `190cb56e680dc02a91c743ccad61ca2ef10a6032`
- review start head: `9329d6610ffbfbb9fe3f638a2aae7ce3be368fa7`
- source drift `190cb56e..9329d661`: docs only; no product/test/build/selector drift
- source snapshot run/artifact: `34656852303 / 10286151896`
- snapshot provider SHA-256: `44ee51a6e08500b75d02dd6db31fefd9ed63729cc04084bb86f2be85ca4206ed`
- `runtimeExecution=false`

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
conditional_modules:
  - trigger: production/test correction design and implementation
    path: turn-based-coding-agent/modules/engineering-guidelines/MODULE.md
  - trigger: replacement row400 unit-test design/change
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector writes, compile workflow, artifacts and cleanup
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R2_Review_Record.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
templates_when_producing:
  - turn-based-coding-agent/templates/CODE_BUILD_REPORT.md
  - turn-based-coding-agent/templates/TEST_PLAN.md
do_not_preload:
  - A3-to-A4 cutover implementation
  - M4-CP3-TB1-R1-REV-OBS-01 fixture work
  - M4-CP3-CB4-REV-OBS-02 row399 work
  - runtime execution before Code + Build closeout
```
