# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP-COND-TB3-REV` COMPLETE / NEGATIVE-INDEX AUTHORITY ACCEPTED / SELECTOR-AUTHORITY GAP OPEN; `M4-CP-COND` OPEN; M4 OPEN
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP-COND-CB4`

## Current authority

- M1-M3 are CLOSED / ACCEPTED. M4-CP1/CP2 remain historical framed closures. M4-CP3 is CLOSED / ACCEPTED.
- Accepted M4 runtime authority remains CP3 package `10307919492` / source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`, selector408 **408/408** (`c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`).
- Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.
- CP-COND product semantics remain `b576d061e23873b7b4193b158138d2097c75a728`; corrected test authority is `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675`.

## TB3 Review result

Review independently re-opened artifact `10325879420`, the 423-process TB3 evidence and the packaged corrected negative-index test source. TB3 mechanics are accepted: focused **14/14 PASS**, boundary **1 expected report-only SKIP**, selector408 **408/408 PASS**, gating **422/422 PASS**, zero semantic RED/crash/timeout/actual selection mismatch, exact immutable postflight.

`M4-CP-COND-TB2-REV-CAND-01` is **CLOSED / TEST-AUTHORITY REPAIRED / RUNTIME-PROVED / NON-STABLE**. The corrected oracle exactifies actual raw binary64 bytes, derives the unique planar closed fan, proves branch admissibility, derives unique cross-face Z4 offsets `[3,3,3,3,3]` and signed numerator `-1`, and a one-LSB raw mutation invalidates the oracle. It does not read conditioner output to author the expected value.

CP-COND remains OPEN because frozen CP-COND §12 and M4's selector contract require checkpoint gate credit on a **cumulative append-only selector**. TB3 ran the fourteen CP-COND identities only as focused tests while selector408 remained unchanged. `M4-CP-COND-TB3-REV-CAND-01` is therefore **OPEN / SELECTOR-AUTHORITY / CP-COND GATING IDENTITIES OUTSIDE CUMULATIVE SELECTOR / NON-STABLE**. Artifact `10325879420` is not promoted as accepted checkpoint authority.

Review also records `M4-CP-COND-TB3-REV-OBS-01`: the TB3 evidence checksum manifest hashes its own initially empty output entry, so only that self-entry fails verification. All substantive entries verify and the outer evidence archive digest pins the bundle. TB4 must emit a non-self-referential checksum manifest.

## Exact next — `M4-CP-COND-CB4`

Selector/package-only Code + Build under `.agents/Directional/Architecture_M4_CP_COND_CB4_Code_Build_Plan.md`:

- preserve selector408 byte-for-byte as rows 1-408;
- append the existing fourteen CP-COND gating identities in frozen focused order as rows 409-422;
- keep the boundary-truncated identity report-only/non-selector;
- update selector manifest additively;
- change no product/test/fixture/CMake semantics;
- compile/package the complete seven-target owner set with GMP/GMPXX, `runtimeExecution=false`, no Directional runtime;
- freeze TB4 as selector422 422/422 + one expected report-only SKIP, followed by mandatory TB4 Review.

If any existing identity/name/owner/prefix must change, STOP and return to Review/DEFN.

## Context Load Plan

```yaml
load_next:
  - .agents/Directional/Architecture_M4_CP_COND_CB4_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP_COND_TB3_Review_Record.md
  - .agents/Directional/Architecture_M4_CP_COND_TB3_EXEC_Report.md
  - .agents/Directional/Architecture_M4_CP_COND_Frozen_Definitions.md
  - .agents/Directional/M4_Consolidated_Record.md
required:
  - .agents/Directional/ORIENTATION.md
  - .agents/Directional/ROADMAP.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
  - TODO.md
do_not_preload:
  - folded CP-COND per-turn records
  - M5/M6 implementation
  - CP-SCALE numeric thresholds
```

## Carried obligations

- `M4-CP-COND-TB3-REV-CAND-01`: selector-authority correction owned by CB4 -> TB4-EXEC -> TB4-REV.
- `M4-CP-COND-TB3-REV-OBS-01`: non-self-referential evidence checksum manifest owned by TB4 harness.
- `M4-CP3-TB1-R1-REV-OBS-01`: multiplicity-2 end-to-end oracle remains carried/non-blocking to the first later independently falsifiable M4 test-authority turn before M4-CP4.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` divergence tamper detector remains carried/non-blocking to the next legitimate row399 touch.
- TB3 provenance warning remains a historical-claim bound.
- `G4-B002` produced-witness debt (3) remains M4-CP4 gating; `G4-B003` debt (2) remains M5 gating.
