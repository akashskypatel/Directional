# Future Chat Session Handoff

> **EXPLICIT USER AUTHORIZATION REQUIRED** to modify or delete this file; unauthorized changes must be reverted during documentation drift audit. This rewrite was expressly requested on 2026-10-16.</br>
> Edits to this document must follow the format laid out in `.agents/Directional/Future_Chat_Session_Handoff_Template.md`.

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical information required to continue safely. Architecture belongs in `DESIGN.md`; tasks in `TODO.md`; completed history in `CHANGELOG.md`; lessons in `LESSONS.md`; roadmap in `ROADMAP.md`; exact runtime evidence in retained reports/closure records and the regression tracker. Do not add transcripts, chronological tool history, tool/policy/procedural failures, copied old artifact tables, obsolete selections, or procedure owned by policy/skill files. Concision never authorizes deleting durable information.

This section is durable and must be preserved. The displaced chronological handoff remains in Git history, **not** as instructions to replay.

All instructions and sections prefixed `[ChatGPT Web]` are mandatory for `ChatGPT Web` sessions. Non-`ChatGPT Web` agents (`ChatGPT Work`, `Codex`, `Claude`, etc.) can ignore instructions/sections bearing that prefix.

## Policies - Read first at start of every turn - DURABLE, DO NOT DELETE

Policies cannot be deleted or modified without explicit user authorization. The list uses verified existing paths (three old template filenames were outdated).

| Policy | File |
|---|---|
| Turn Cadence | `.agents/Directional/Turn_Cadence.md` |
| Agent Policy | `.agents/Directional/AGENT_POLICY.md` |
| Mandatory Start Checklist | `.agents/Directional/Mandatory_Start_Checklist.md` |
| Clean up Policy | `.agents/Directional/CLEAN_UP_POLICY.md` |
| Handoff Policy | `.agents/Directional/Durable_Handoff_Policy.md` |
| GitHub Workflow Policy | `.agents/Directional/GitHub_Workflow_Policy.md` |
| GMP Compile Policy | `.agents/Directional/GMP_COMPILE_POLICY.md` |
| Retention Policy | `.agents/Directional/RETENTION_POLICY.md` |
| Review Turn Policy | `.agents/Directional/REVIEW_TURN_POLICY.md` |
| Tool Use Conservation Policy | `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md` |
| Patch Application Strategy | `.agents/Directional/Patch_Application_Strategy.md` |
| Mandatory End Checklist | `.agents/Directional/Mandatory_End_Checklist.md` |

## Current immutable authority — replace in place

| Field | Exact value / evidence owner |
|---|---|
| Currency | 2026-10-27, after immutable TB47 500/4 verified expected-RED execution ([TB47 report](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md)); CB47 exact-patch COMPILE GREEN ([record](Architecture_M6_CP3_CB47_RP01_Endpoint_Witnesses_Code_Build_Record_20261027.md)); predecessor [RA-166](Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md) (CB47-REV). The CB47 E3 conflict is confirmed and resolved: RA-33.5 and the DEFN-E E3 witness demanded a nonempty `route` on `OrdinaryInterior` sides, which A5 forbids (`RP:3643–3650`) and A4 never writes. D5 is re-homed to boundary-path `entryRoute` crossings on `transition_domain_fixture()`. The D2 junction is re-homed to rail-vertex R-adjacency, because R-split is the canonical A4 representation (scratch sweep). The compiled E1 commit `dabb0970e` is defective; the exact probe-verified patch [RA-166.8 embedded patch](Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md#ra-1668-exact-cb47-patch-authoritative-bytes) (`2de51be6…24c1`) replaces it. RA-164.3 P1–P6, RA-165.2 F1/F2 and RA-166.6 F6/F7 bind. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | CB47 exact test-only source `08d41626e3487f3cba2e8fed5fe1f2185da8ac9f`; compile-only run `40501143033`/job `122178978133`, package `12732383172` (ZIP `c2bf478d…5d910e`), eight GMP/GMPXX targets, SHA256SUMS 28/28 and `runtimeExecution=false`; **candidate only, now executed as TB47 500/4**. TB46 re-run **498/6** valid expected-RED ([report](Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md), result `12719412600`). [CB47A](Architecture_M6_CP3_CB47A_Harness_Manifest_Pins_Code_Record_20261027.md): manifest-driven pins, offline replay 504/504. CB47 E1 compile run `40489392387` (artifact `12728075441`) is superseded for gating ([interim](Architecture_M6_CP3_CB47_Endpoint_Witnesses_Interim_Investigation_20261027.md)). TB47 [run 40504055818](https://github.com/akashskypatel/Directional/actions/runs/40504055818), result `12734719880` (`f03efe3c…6b04d`), 1,014 checksums / 504 raw joins, four pinned REDs. Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. [TB47 manifest](Architecture_M6_CP3_TB47_Full_Gate_Case_Manifest.tsv) **v2** `488a20b6…5955`, **measured 500/4**: RED `focused30:12` `:5581`, `selector:442`, cp3entry:1 `:2916`, cp3entry:2 `:3154`; 201 and cp3entry:4 POSITIVE. cp3entry:2's rewrite goes to Review-owned exact-patch turn E2-PATCH. Carried: O1, O2 (post-RP-01, + RA-161 T2), O6, O7, **O8** (producer `InvalidFrontBoundaryAuthority` at `lengthRatio=0.29`), **O9** (A4 junction path unwitnessed, no consumer), DIAG-RETAIN, RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` — EXACT NEXT

- **Authority:** valid immutable [TB47 report](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md), [RA-166.5](Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md), existing CB47 artifact and frozen manifest v2.
- **R27 current finding:** The A5 hard-rail consumer checks both selected-face identities against its published A4 route attachments before its branch-transport equation. This narrows R21’s conditional, but does not establish a source-produced G2 reindex or authorize CB48/TB48. R26 remains the separate A4 gauge-pin guard finding.
- **R28 G1 measured-control-flow correction:** TB47 `selector:442` has its sole native failure at fatal `seamBuilt` before 26 later assertion macros; the 7 hard-rail row-permutation assertions never ran. Preserve earlier measured hard-rail positives, split them into an independently selected real positive, and assign the fabricated two-face component-split to a strict typed-boundary negative rather than false NonTraversable success. Re-home any native non-hard barrier coverage explicitly; no CB48 hunks/TB48 manifest yet.
- **R29 review-only G1 candidate:** Exact one-file *unapplied* test source preview (`9916b743…`) retains original and row-reordered HardFeature positive checks, separately makes the malformed split-component square a typed `SingularityMismatch` negative with original `(2,3)` locus; native scratch/test execution, manifest-prefix review and true non-hard producer witness are still REQUIRED before any CB48 authorization. G2/G3 remain open.
- **R30 G2 existing source-input candidate:** Constant 3x3 `make_hard_rail_fixture()` and right-half +1 raw-arm cyclic `make_nonconstant_hard_rail_fixture()` already use the same source mesh, hard rails, direct producer, and fallback-disabled options. Static eight-face comparison confirms identical unordered cross arms and 4/4 right-side source reindex; **native paired A3/A4/A5/A6 covariance and tamper are not yet demonstrated**. Prefer this existing source pair for a future authorized native scratch proof before creating another fixture. [R30 evidence](Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md).
- **R31 G2 hard-carrier locality:** A separate eight-interior-edge topology/arm model finds that the right-half +1 input reindex changes directed matching *only* on the two hard edges `(1,4)` and `(4,7)`; six non-hard interior transitions remain unchanged. Source-row reversal and three falsifiers pass offline, not natively. The future G2 positive must compare independently published native A3 signed hard carriers to A4 endpoints and A5/A6 under possible 90° regional chart-frame change; do not count ordinary gauge-pin checks as a hard-rail witness. G1/G3 still open.
- **R32 G2 canonical correction and owner split:** Source-only independent probe computes baseline gauges `[0,1,0,1,0,1,0,1]` and reindexed `[0,1,3,0,0,1,3,0]`, establishing equality of `raw matching + gauge(from) - gauge(to)` on all eight source interior edges. **Hard** carrier raw transitions are retained in A3 `transitionValues` but excluded from A3 ordinary `branch_transports`; A4 consumes and publishes them separately. In a native paired test independently inventory two hard directed A3 transitions/inverses, A4 route attachments/certificates, A5/A6 geometry-normalized quotient and first-owner signed tamper. This analysis is **not** native admission; G1/G3/E2 remain open.
- **R33 G2 owner-specific native oracle requirement:** For each topology-keyed hard `(1,4)` and `(4,7)`, independently observe **raw A3** directed `transition_value` (source-model constant `0`, right-half +1 reindex `3`, inverse `1`) and **A4** published carrier/endpoint certificate. The unchanged gauge-corrected physical value (`3` on both runs) is an external model, NOT an emitted hard `branch_transports` record. A4 checked `rail-transition-a3` and A5 selected-source-face precede A5 signed endpoint branch equality. Native paired admission and A5-specific cell-only signed tamper with real restored positive required; static 256-case model does NOT discharge G2/G1/G3 or authorize CB48/TB48.
- **R34 recovered existing native G2 admission:** Immutable TB47 `cp3entry:6`/row 497 PASS executes the nonconstant right-half-reindexed raw-source fixture through A4→A5→A6→A7, including an A6 selected cross-region HardRail relation. This corrects any R30–R33 wording implying *zero* native shifted admission; still NO paired constant-vs-reindexed G2 gauge covariance or A5 first-guard signed tamper proof. Separate `cp3entry:2`/row 493 RED fails at line 3154 expecting a nonexistent combined two-step rail and masks its later reversed-source-row assertions; E2 owns that failure, not G2. R34 evidence recorded in the same Review. No CB48/TB48 authority.
- **R36 historical-protection partial audit:** GitHub authenticated the rewrite-base ancestor (`8b7299b43…`, `behind_by=0`) and returned exact baseline durable files. Current Review/handoff/ORIENTATION/tracker Git blobs match verified snapshot+R35 bytes; all **five** rewrite-protected headings remain present, with deliberate heading-removal falsifiers. This is not a full authentic Git-history `review_check.py boundary` or per-commit ledger nonshrinkage PASS; the full audit and G1/G2/G3 native evidence remain open. No CB48/TB48 authorization.
- **R35 existing-test selection boundary:** A source-to-frozen-manifest audit reconfirms 504 unique TB47 identities (500 PASS/4 RED). The measured `cp3entry:6` shifted G2 fixture never constructs its constant-field partner. An existing baseline A5 `HardRailTransportMismatch` test is *not selected* in TB47 and is not a native paired relabel. Three existing `OddAtlas*` tests are also *not selected* and exercise synthetic checked A4 factory drafts, not native torus production. Reuse mechanisms only with a new independent producer-valid witness; do not count static source presence as paired G2 or G3 acceptance. Source-backed R35 evidence is in the active DEFN-G Review; G1/G2/G3 remain unresolved; no successor.
- **Review scope:** Independently decide gauge cluster G (`selector:442`, `focused30:12`, `cp3entry:1`) against source-authoritative A3/A5 producer and consumer invariants; perform scratch probes before authorizing any new test oracle (RA-166.6 F6/F7). Emit exact approved hunks and the TB48 manifest; preserve cp3entry:2 E2 for separately authorized independent Review. No premature CP3/selector497 promotion.
- **Frozen result:** TB47 504/504, 500 PASS / four precisely pinned RED; run `40504055818`, result `12734719880`, ZIP SHA256 `f03efe3c2f75b113ac9e05329799955e4306d611feb4d83c38a2cd672be6b04d`.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB46 re-run → DEFN-E → CB47A → CB47 (BLOCKED on E3) → RA-166 | E3/D2 witness definitions re-homed; E1 defect fixed by exact patch. |
| 1 — complete | `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES` | RA-166 patch applied, exact two-file diff; eight-target GMP compile and package `12732383172`; no runtime. |
| 2 — complete | `M6-CP3-TB47-RP01-FULL-GATE` | Verified artifact-only 504/504, 500 PASS / four registered RED at frozen pins, exit0, no control violations; candidate only. |
| 3 — next | `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review, probe-backed) | Absorbs TB47; decides G (442, `focused30:12`, cp3entry:1); emits exact hunks + TB48 manifest. |
| 4 | `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH` (Review, probe-backed) | Exact cp3entry:2 rewrite to RA-166.3 D2; junction tamper sections disposed per O9. |
| 5 | `M6-CP3-CB48-…` (G) → `M6-CP3-CB48E-RP01-E2-RAIL-VERTEX-ADJACENCY` → `M6-CP3-TB48-RP01-FULL-GATE` | Exact patches only. |
| 6 | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review) → CB49 → TB49 | O4, O5, P1-a/P1-b, RA-162 C1, H2 A5 reachability. |
| 7 | Green full gate → RP-01 Review | O6 scope; O7/O8/O9 owners. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT`, then `DIAG-RETAIN` | RA-160.4 + RA-161 T2. |
| rule | RA-164.3 P1–P6; RA-165.2 F1/F2; RA-166.6 F6/F7 | A Review scratch-probes every oracle it authorizes and hands CBs exact patches; witness definitions are checked against the producer and consumer invariants. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER** — independent, probe-backed Review of TB47 gauge REDs (`focused30:12`, `selector:442`, `cp3entry:1`) using valid immutable [TB47 report](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md) and RA-166.5. Separately preserve E2 (`cp3entry:2`) for the frozen E2-PATCH Review; no CB48 work until the Reviews freeze evidence. Last accepted CP2 491/491; stable 66/17/49 debt1; selector497 frozen, CP3 candidate.

## Resume-critical lessons — DURABLE, DO NOT DELETE

The substantive lessons live in `LESSONS.md`; use the relevant section rather than copying incident accounts.

| Section | Read it before |
|---|---|
| 1. Evidence, acceptance, and scope | Interpreting results, claiming acceptance, changing gates/selectors or classifying regressions. |
| 2. Witnesses, tests, and independent oracles | Designing fixtures, tests, invariants or independent checks. |
| 3. Semantic ownership, identity, and dataflow | Modifying semantic IDs, representations or producer-consumer contracts. |
| 4. Geometry, topology, and mathematical obligations | Changing geometric algorithms, topology or exact predicates. |
| 5. Diagnostics, classifiers, and causal investigation | Instrumentation, rejecting predicates or root-cause hypotheses. |
| 6. Contracts, planning, reviews, and durable records | Requirements, plans, reviews, authorization or documentation. |
| 7. Build, artifact, workflow, and tool mechanics | Compilation, packaging, CI, artifacts or repository operations. |

New lessons belong in `LESSONS.md`, not here.

## Maintenance — one live handoff

At authorized closeout, **replace** current authority, next action, conditional successor and context **in place**. Keep the durable purpose/policy/load/lesson sections. Archive completed changes in `CHANGELOG.md`, evidence in reports/tracker, tasks in `TODO.md`. Never append a second `CURRENT` section, a transcript or old turn ladder. The mandatory end checklist and `Durable_Handoff_Policy.md` govern `STATUS` closeout.
