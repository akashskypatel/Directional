# M4-CP-COND-TB1 Review Record

**Turn:** `M4-CP-COND-TB1-REV`
**Date:** 2026-09-13 UTC
**Boundary:** Review + planning only; runtime-free; no product, test, fixture, selector, benchmark, CMake, or reusable-workflow semantic mutation
**Decision:** `M4-CP-COND-TB1-EXEC-CAND-01` **UPHELD / CANDIDATE ARTIFACT REJECTED AS TB-RUNNABLE / PACKAGE-CLOSURE OWNER-SET OMISSION / PRE-SEMANTIC / NON-STABLE**
**Exact successor:** `M4-CP-COND-CB2`

## 1. Reviewed authority

Review independently re-opened the frozen TB1 plan, the TB1 EXEC report, the immutable CB1 package and the TB1 result/log evidence rather than inheriting EXEC's interpretation.

- Accepted predecessor runtime authority remains CP3 CB10 artifact `10307919492` / semantic source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`, selector408 **408/408**.
- CP-COND candidate semantic source: `b576d061e23873b7b4193b158138d2097c75a728`.
- Immutable CB1 package: artifact `10312168742`, ZIP/provider SHA-256 `90c5e4c8bd41ced2311d11e1cb1e03cfd6dc71542c862981363aa31df2c03265`.
- Authoritative TB1 retry: run/job `34757021728 / 103723061754`.
- TB1 result artifact `10317417085`, SHA-256 `2886414c821790721a64c0a026444772e3eee44bf983f30b1d787c385cfcfb74`.
- TB1 log artifact `10317147479`, SHA-256 `80b38896305af1df6bd6602351733a0899b6a01bdcc9dd52ab72f0b41fac8668`.
- Review source snapshot: workflow `34767514250`, snapshot source/control SHA `052afd8d11e4e7e15b49506d44b2968027c1e61d`, artifact `10320524345`, provider ZIP SHA-256 `43725c20c1ddd47081005610d5ed1ce15e50eff5691600e9272bcd3738e54593`; semantic implementation bytes remain bound to `b576d061e...` by the compile package.

## 2. Independent selector and package re-derivation

The accepted selector was recomputed from repository bytes rather than copied from EXEC:

- `Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt`: exactly **408** LF rows, SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`.
- first 403 rows: SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`, byte-identical to the accepted selector403 predecessor.
- TB1 `identity-map.tsv` contains 408 rows and 408 unique identities. Recounting its executable owner column gives exactly **30 authority-kernel / 262 producer / 75 completion / 41 validation**.

The immutable CB1 package independently verifies its root `SHA256SUMS` (**24/24** entries), semantic source `b576d061...`, empty source-status receipts, `runtimeExecution=false`, and GMP/GMPXX linkage. Its compiled-target receipt contains only:

1. `directional_pipeline`
2. `directional_surface_cell_producer_tests`
3. `directional_compiled_api_tests`

Its `bin/` therefore lacks `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_completion_tests`, and `directional_surface_cell_validation_tests`. Those three owners account for **146** accepted selector identities (`30 + 75 + 41`). This is a package-completeness defect before any semantic test result can exist.

## 3. Execution-boundary re-derivation and non-vacuity

The frozen TB1 plan requires all selector-owner executables before any Directional process and requires the complete selector408 census; package mismatch is explicitly fail-closed. Review independently compared TB1 pre/post package, source, and execution-view censuses and found them byte-equal.

The authoritative boundary receipt records:

- `script_exit=91`, `stop_kind=PACKAGE_PREFLIGHT_RED`;
- `runtime_started=false`, `runtime_completed=false`;
- `processes_executed=0`;
- PASS/RED/SKIP/crash/selection-mismatch counts all zero;
- no configure, compile, relink, package repair, generated discovery, benchmark execution, or source/test/fixture/selector mutation.

This result is non-vacuous as a package gate: the owner map resolves all 408 accepted identities, the package physically lacks three named owner binaries, and the preflight distinguishes that omission before runtime. It is **not** non-vacuous semantic evidence for the conditioner: the 14 focused CP-COND gates, the one report-only boundary identity, and all 408 accepted selector processes did not execute and receive zero semantic credit.

The earlier `34756902324` attempt remains orchestration-only evidence: direct execution of a Contents-API `0644` harness stopped at exit 126 before the harness or any Directional runtime. The corrected retry changed only caller invocation to `bash` and is the authoritative mechanical execution.

## 4. Classification and root cause

`M4-CP-COND-TB1-EXEC-CAND-01` is **UPHELD** and classified **PACKAGE-CLOSURE OWNER-SET OMISSION / PRE-SEMANTIC / NON-STABLE**.

The defect is not presently a product, test, fixture, selector, A3/A4, conditioning-certificate, or runtime semantic defect. CB1's compile/package scope built the directly affected pipeline, producer tests and compiled API, while its frozen successor gate inherited a cumulative selector whose 408 identities are owned by four test executables. The semantic source can therefore be compile-green while the immutable package is not TB-runnable authority.

The mechanism is already established by `M2-CP1-TB-CAND-01`: an immutable candidate omitted a frozen-selector owner executable, so the corrective control was package closure from unchanged semantic source, not a semantic edit. Existing `LESSONS.md` **3** and **170** govern this turn: selector-owner completeness is part of artifact closure, and a control experiment must change only that packaging variable.

CB1 artifact `10312168742` is rejected **as the TB-runnable candidate package**. This does not reject or accept the conditioner semantics because no semantic process ran. CP-COND remains OPEN and semantically unadjudicated.

## 5. Stable-event accounting

No accepted selector ordinal transitioned PASS → RED: no Directional identity executed. This is therefore **non-stable** and opens no regression category or recurrence.

- stable events: **49**
- categories: **14**
- recurrences: **35**
- produced-witness debt: **5**
- accepted runtime authority: package `10307919492` / selector408 **408/408**

## 6. Prior obligations

No carried obligation is discharged by a pre-runtime package failure.

- `M4-CP3-TB1-R1-REV-OBS-01`: carried, non-blocking; first later independently falsifiable M4 test-authority owner before CP4.
- `M4-CP3-CB4-REV-OBS-02`: carried, non-blocking; next legitimate row399 touch.
- TB3 provenance warning: carried as a historical-claim bound.
- `G4-B002` produced-witness debt **3**: remains M4-CP4 gating.
- `G4-B003` produced-witness debt **2**: remains M5 gating.

Boundary-truncated separatrix remains report-only/non-selector because TB1 never reached it and its raw reachability precondition remains independently unproved.

## 7. Corrective successor — `M4-CP-COND-CB2`

`Architecture_M4_CP_COND_CB2_Code_Build_Plan.md` is the sole corrective plan. It freezes a package-closure control experiment over **exact unchanged semantic source `b576d061e23873b7b4193b158138d2097c75a728`**. CB2 must compile/package the existing pipeline/API plus all four selector-owner test executables and execute nothing.

The successor is intentionally narrower than a semantic correction. Any need to change product/test/fixture/selector/CMake/reusable-workflow semantics falsifies the package-closure diagnosis and stops the turn back to Review.

## 8. Durable-document disposition

- `ORIENTATION.md`: currency, §3, §7 and §8 updated; §4 witness table unchanged because no witness executed or changed state.
- `CHANGELOG.md`: TB1 Review entry added.
- `ROADMAP.md`: CP-COND state moved from DEFN/CB1-next to reviewed package preflight / CB2-next.
- `Regression_Root_Cause_Tracker.md`: candidate classification and recovery owner recorded.
- `TODO.md` and `Future_Chat_Session_Handoff.md`: exact next changed to CB2.
- Selector manifest: **n/a** — no selector was added, withdrawn, or accepted; selector408 remains byte-frozen.
- `LESSONS.md`: no new lesson added; existing Lessons 3 and 170 exactly cover this mechanism.
- Consolidation: **n/a** — CP-COND remains open and its current EXEC report, this Review record, and CB2 plan are live authority, not stale historical documents.

## 9. Turn-boundary and tool-use note

Review remained runtime-free: no Directional test, benchmark, configure, compile, relink, package repair, product/test/fixture/selector/CMake or reusable-workflow semantic edit was performed.

A tool-efficiency policy miss occurred during source-snapshot acquisition: after selecting `READ_MODE=snapshot`, two repository documents were read directly while the exact snapshot was still pending, and the tool-use policy was redundantly fetched once. Substantive cross-file review then stopped piecemeal connector inspection and used the verified snapshot/local analysis plane. This does not alter source or semantic evidence, but is recorded rather than normalized away.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; first403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` |
| Decisive claims independently re-derived | 408 unique selector identities; owner census `30/262/75/41`; 146 identities lack packaged owners; CB1 target/bin census; root checksums; stopped execution boundary; pre/post census equality |
| Non-vacuity checked | package closure is falsifiable and failed on three physical missing owners; semantic conditioner evidence is explicitly non-credit because zero Directional processes executed |
| Prior obligations discharged/carried | `M4-CP3-TB1-R1-REV-OBS-01`, `M4-CP3-CB4-REV-OBS-02`, TB3 provenance warning, G4-B002 debt3 and G4-B003 debt2 all carried; none discharged |
| Stable accounting | `49 / 14 / 35`, debt `5`; accepted package `10307919492` + selector408 `408/408` unchanged |
| New candidates/obligations recorded | `M4-CP-COND-TB1-EXEC-CAND-01` upheld/classified in tracker; recovery owner `M4-CP-COND-CB2` |
| ORIENTATION currency line | `M4-CP-COND-TB1-REV`, 2026-09-13 written |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7, §8 updated; §4 n/a because no witness executed or changed state |
| CHANGELOG | TB1 Review entry added |
| ROADMAP | CP-COND reviewed package-preflight state and CB2 successor recorded |
| Selector manifest | n/a — no selector added/accepted/withdrawn; selector408 remains byte-frozen |
| LESSONS | existing Lessons 3 and 170 cited; no new lesson needed |
| Consolidation under CLEAN_UP_POLICY | n/a — checkpoint remains open and current records are live authority |
| Successor frozen | exactly `M4-CP-COND-CB2`; falsifiers/STOP rules in `Architecture_M4_CP_COND_CB2_Code_Build_Plan.md` §6 |
| Turn boundary held | PASS — runtime-free; no product/test/fixture/selector/benchmark/CMake/reusable-workflow semantic mutation |
| review_check.py boundary | PASS — durable boundary check completed on prepared Review tree |
| Pushed to origin, branch in sync | PENDING FINAL PUBLICATION CHECK |
