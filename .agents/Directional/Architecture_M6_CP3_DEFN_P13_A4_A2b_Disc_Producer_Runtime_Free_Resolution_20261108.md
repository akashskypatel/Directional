# RA-214 — `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER` resolved runtime-free; first A4→A3 slice frozen (2026-11-08)

**Turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER` (step 58), resumed from `BLOCKED` (Review/DEFN, Claude). **Subject:** the blocker raised by the same turn's earlier attempt ([WIP index](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Review_WIP_20261108.md"), [execution-authority record](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_A4_A2b_Exact_Support_Export_Execution_Authority_Review_20261108.md")) and the scope [RA-213](Architecture_M6_CP3_DEFN_P13_Vase_Producer_Path_Adversarial_Review_A2b_Disc_Construction_20261108.md) §4 gave this turn. **Verdict:** the blocker is valid, and the fault is RA-213 §4 (mine). This turn completes **runtime-free**. Runtime facts move to the TBs of narrow product slices. The first slice, **CB103**, is frozen as an exact patch, and **TB86** is frozen as a 909-row manifest.

**Evidence base:** HEAD `07d1a2207`. Product sources are unchanged since compiled CB101 `23e35798…` (`git diff --stat 23e35798..HEAD -- src include tests` is empty). Static source reading only. No Directional binary was built or executed. The one compile-tool use is a `-fsyntax-only` check of the frozen patch, which emits no object file (§6).

## 1. The execution-authority block

1. **The conflict is real, not procedural.** Three documents say a Review or DEFN is runtime-free: `REVIEW_TURN_POLICY.md` §4.3 ("A REVIEW is runtime-free"), `AGENT_POLICY.md` ("A same-agent DEFN remains planning/runtime-free") and `Turn_Cadence.md` item 1 (only CB compiles, only TB executes).
   - `ORIENTATION.md` and the handoff have nonetheless carried a "Review track (Claude, scratch build)" convention, which no policy authorizes.
   - RA-200 and RA-201 called the same ChatGPT blocker "procedural". Under the written policy that was wrong, and RA-213 §4 repeated the error.
2. **RA-213 §4 was also mis-scoped.** It asked a Review for three things:
   - a per-disc A4 prototype on Vase;
   - every gate measured on that prototype;
   - an A3 re-solve.

   That is producer implementation plus TB work inside a Review, so it is a monolithic implementation turn in disguise. The 38 WIP commits show the result: the turn could not converge without becoming a CB and a TB.
3. **Resolution, needing no policy edit and no exception:**
   - Step 58 closes runtime-free.
   - Every fact that needs execution becomes the TB evidence of the smallest *product* slice that needs it. Each such slice adds code the architecture keeps: an oracle, a representation or a producer stage. It is never a diagnostic-only CB.
   - The Review authors exact patches from source. It may syntax-check them off-branch, which is neither a build nor runtime, and that check is not evidence.
4. **Suspended:** the "Claude, scratch build" track label on steps 44, 44A, 44B and 44C. Each is re-scoped runtime-free when it is next opened, or waits for the user.
   - Earlier probe results (RA-165 to RA-213) stay as non-accepted information. None was ever promoted, so no accepted state changes.
   - **User decision, optional:** an explicit amendment to `REVIEW_TURN_POLICY.md` §4.3 permitting off-branch, non-accepting Review probes would make probes faster. Policy files are not edited here, and the sequence below does not depend on that decision.

## 2. Adjudication of the earlier attempt's findings

| Claim | Disposition |
|---|---|
| A3 preferred count and breakpoints depend on how the arc is split into support pieces (F1) | **Confirmed** (`GlobalConformityBaselineSupport.cpp:192-239`; `GlobalConformityBaseline.cpp:739-767`). The scope is wider than stated; see D7 |
| Production A3 is `GlobalConformityBaselinePlan` (`SurfaceCellTracing.h:2350`) | **Confirmed** |
| Ordinary A2b Trace seams cannot use the HardRail/PeriodicCut path; front cells carry no A2b owner | **Confirmed**; made precise as D9 |
| The receipt cannot establish A4 consumption | **Confirmed**; the receipt actually overclaims (D8) |
| Topology-only witness puts the +3 irregularity on the three trace arms | **Rejected as a target.** Trace-arm vertices are interior surface vertices. Valence 3 there means unprescribed singularities (§2.1 item 3). See §4 |
| Source-attached 7,212-quad surrogate and synthetic three-disc cuts | Not compliant witnesses. No further use |
| Read-only A2b/A3 exporter and Python oracle | **Withdrawn.** CB103's census and the disc-domain slice publish these facts as product output |
| `GitHub_Workflow_Policy.md` compile route | Applies to workflow compiles, not to a runtime-free Review. Moot |
| The `BLOCKED` beacon | It carried two non-schema fields (`Durable_Handoff_Policy.md` item 15 allows exactly six). Repaired at resume |

## 3. New static findings

- **D7: the A3 metric depends on how the arc is split.**
  - **Count.** `count = round(√(m·Σλᵢ²))` with λᵢ = lᵢ/h̄ᵢ. By Cauchy–Schwarz this is ≥ L = Σλᵢ, with equality only for equal pieces. Example: pieces λ = (0.1, 3.9) give L = 4 but a count of 6.
  - **Breakpoints.** They are placed uniformly in piece *index*. In the example, 3 of the 6 edges land in the 0.1-long piece.
  - **Scope.** This already affects every A2b arc that crosses face interiors, Vase's three trace arcs included (counts 10/4/9, unverified). It is not only a hazard of future chain aggregation. DESIGN §7.4 names a "target-size objective" without fixing the formula, so the fix is a §7.4 amendment.
- **D8: the conformity receipt overclaims.**
  - The comment at `SurfaceCellTracing.h:1500` says it proves "which accepted A2b/A3 plans A4 consumed".
  - In fact it is minted at `SurfaceCellTracing.cpp:18375`, after only digest and support-identity checks and before any regional producer runs. It is hashed (`RemeshPipeline.cpp:2091-2096`).
  - Plane, MultiFaceSeam, CloseSheets and Cylinder carry it without consuming A3, which is a §2.1 item 7 exposure.
- **D9: A3 consumption is unrecordable off rails and cuts.**
  - The product validator admits `sharedBoundaryInterval` only on `HardRail` and `PeriodicCut` edges (`:9386-9387`).
  - Curved-disk *does* subdivide every A2b arc by A3 ordinals (`:17577-17616`), but records an interval only when `shared = hardFeature` (`:17557`). Its rim consumption is therefore real but invisible.
  - No edge kind exists for an A2b Trace seam between two discs of one source region.

## 4. Decisions

- **D6, Vase success criterion. Recommendation: (ii), expected tier D1 `QualityRelaxed`. Not registered until the user approves.**
  - Each of the three discs gets four corners: the port corner, the two trace–rim junctions, and one rim corner placed at an existing A3 breakpoint where the rim has turned 90° against the field.
  - Items 1–9 of §2.1 then hold, disc interiors stay singularity-free, and A3 is unmodified. The only miss is three boundary-valence mismatches under item 10, which DESIGN §2.2 defines as D1.
  - (i), field-derived boundary-valence targets, is an item-10 calibration change. Open it only if the user wants Vase Certified.
  - (iii), a boundary-aligned field, changes the A1 input. Not recommended.
- **D5 waits for D7.** Merging the per-source-edge Mandatory arcs under today's metric would inflate counts (the falsifier in the earlier attempt). The order is therefore: D7 metric first, then maximal Mandatory chains in A2b. Both go in one DEFN with a DESIGN §7.4 amendment, and both change A3 plans and digests on several fixtures.

## 5. Realigned sequence

| Step | Turn | Owner | Depends on |
|---|---|---|---|
| 58 | this turn (RA-214) | Claude, runtime-free | COMPLETE |
| **59** | **`M6-CP3-CB103-P13-A3-SPAN-COVERAGE-RECEIPT`** | implementation agent, compile only | §6 |
| 60 | `M6-CP3-TB86-P13-A3-SPAN-COVERAGE-FULL-GATE-EXEC` | implementation agent | CB103 |
| 61 | `M6-CP3-DEFN-P13-A3-RECORDED-BOUNDARY-INTERVALS` | Review, runtime-free | CB103 source |
| 62–63 | CB104 → TB87 | implementation agent | step 61 |
| 64 | `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC` (D7, then D5) | Review, runtime-free | — |
| 65 | `M6-CP3-DEFN-P13-A4-A2B-DISC-DOMAIN` | Review, runtime-free | steps 61 and 64 |
| 66+ | per-disc boundary and corners (needs D6) → fill (§4.9) → aggregator dispatch with honest `Declined` flags (D3) | one DEFN → CB → TB each | — |

What each later Review freezes:
- **Step 61** audits every consumer of `sharedBoundaryInterval`, then freezes CB104:
  - the validator accepts a single-sided unit interval on `GenuineSourceBoundary` edges;
  - curved-disk records intervals on every A3-subdivided boundary arc.

  The consumers to audit include `RemeshPipeline.cpp:2285`, `:4832` and `:5109`, and `SurfaceCellTracing.cpp:19882`. **Prediction:** only the curved-disk fixtures change digest, and their boundary spans go from unrecorded to covered.
- **Step 64** freezes the partition-stable A3 metric (D7) and then maximal Mandatory chains (D5), with the DESIGN §7.4 amendment.
- **Step 65** freezes the A2b plan-trace edge kind (reciprocal intervals) and a disc-domain builder that publishes, per disc, the A2a′ fragments, the oriented walk and the A3 breakpoints. Its TB measures Vase's 3 discs and is the first place the D7 trace-count prediction is tested.

The singularity veto stays until the per-disc producer exists. Not scheduled: legacy tuning (O31, P13-n1/2/3), CB102.

## 6. CB103 and TB86, frozen

**CB103 is behaviour-neutral.** It adds a pure, report-only `summarize_a3_span_coverage(edges, baseline)`: for each A3 span, do the recorded unit intervals tile [0, count] once per A3 incidence?

Its outputs:
- Six `RemeshDiagnostics` counters, filled where the product and the A3 plan coexist (`RemeshPipeline.cpp`), summed across components.
- A separate `a3-coverage case=…` census line, so the pinned `platform-digest` lines stay byte-identical.
- The D8 comment correction.
- One test using the rectangular hard-rail fixture: rail spans are covered, the partition is complete, and two mutations (a dropped interval, a stretched interval) each turn exactly one span partial.

No disposition reads the counters, and nothing is hashed.

**Patch:** [`Architecture_M6_CP3_CB103_P13_A3_Span_Coverage_Receipt.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB103_P13_A3_Span_Coverage_Receipt.diff"), base `07d1a2207`.

| Property | Value |
|---|---|
| Size | 292 lines |
| SHA-256 | `0982bd4ae02d98c876ee42c53b19b7f9452cc90708db991d9ee415609db531ec` |
| Numstat | `8 0` RemeshDiagnostics.h / `36 1` SurfaceCellTracing.h / `71 0` SurfaceCellTracing.cpp / `22 0` RemeshPipeline.cpp / `11 0` SurfaceCellDesignAcceptanceTests.cpp / `63 0` SurfaceCellsPhase10Tests.cpp |
| Context lines to keep | 8 single-space context lines |
| Pre-freeze checks | `git apply --check` clean. Four touched translation units pass `-fsyntax-only` under the `bld55n` configuration, with no new warnings. GCC/GMP compile authority remains with the CB |

**CB103 stop rule:** apply exactly. If the patch hash, numstat or compile does not match, stop with `M6-CP3-PLAN-P13-A3-SPAN-COVERAGE-RECEIPT-STOP`. Infrastructure failure routes to `M6-CP3-CB103A-P13-A3-SPAN-COVERAGE-RECEIPT-ORCH`.

**TB86** runs on the CB103 package.

- **Manifest:** [`Architecture_M6_TB86_P13_A3_Span_Coverage_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB86_P13_A3_Span_Coverage_Full_Gate_Case_Manifest.tsv"). It has 909 rows: TB85's 908 plus GUARD 909, `SurfaceCellAuthorityContractCutover.A3SpanCoverageObservesRecordedHardRailIntervalsAndTheirLoss`.
  - SHA-256 `3573ffbf6cba47592489c34f2177988c1b66871db4cd983577694dbb9dcabe76`
  - `SELF_CHECK_PASS cases=909 deferred=81`
  - membership 990
  - ledger v5 `fd433f54…`
  - census manifest unchanged, 3 rows `3af1dc0d…`
- **Falsifiers, stated before the build:**
  - The gate is 909/909.
  - Rows 795, 796, 797 and 864 and the Cylinder, BunnyRandom and Vase census `platform-digest` lines are byte-identical to TB85.
  - Every `a3-coverage` line shows `partial=0` and `foreign=0`, and covered + unrecorded = scheduled.
  - Plane, MultiFaceSeam, CloseSheets and Cylinder show `observed=1`, with covered spans only where `HardRail` intervals exist.
  - Vase shows `observed=0`, because it reaches no A4 product.

  This records D4 on Linux as TB evidence.
- **Routes:**
  - mismatch → `M6-CP3-TB86-P13-A3-SPAN-COVERAGE-FULL-GATE-REV` (Review, runtime-free);
  - infrastructure → `M6-CP3-TB86A-P13-A3-SPAN-COVERAGE-ORCH`.

## 7. Corrections to RA-213 (mine)

- §4 is withdrawn: it put runtime and prototype work in a Review (§1).
- Its "Claude scratch" labels are suspended.
- Its closeout table omitted most of the `REVIEW_TURN_POLICY.md` §5 rows. This record carries the full block.
- D5 treated per-source-edge arcs as the only cause of over-refinement. D7 adds a second cause on face-crossing arcs.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB85 manifest re-hashed `ec088eb1…` (908). TB86 = those 908 rows byte-identical + row 909. Selector497/CP3 unpromoted, so no accepted-selector change |
| Decisive claims independently re-derived | Policy clauses; receipt mint site and hash; validator interval kinds; curved-disk `shared` flag; A3 count and breakpoint formulas, with the D7 worked example; product source unchanged since CB101 |
| Non-vacuity checked | CB103's test has two mutations, each of which must flip exactly one span. TB86 pins byte-identical digest lines, so any behaviour change in CB103 is caught |
| Prior obligations discharged/carried | RA-213 D1–D3 stand. D4: CB103/TB86. D5: step 64 after D7. D6: user decision pending. RA-213 §4 withdrawn. Earlier-attempt obligations 1–4 superseded by §5. Carried: P13-e, O30b, O31 (legacy only), O32b–e, O33, O27–O29 |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; 81 deferred; TB85 908/908 latest; selector497/CP3 unpromoted |
| New candidates/obligations recorded | D7, D8, D9 and the review-runtime governance item; tracker updated |
| ORIENTATION currency line | RA-214, 2026-11-08 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 next turn updated; §4 n/a (no witness state changed); §7 Vase bullet replaced and the governance item added; §8 pattern updated |
| CHANGELOG | Entry added |
| ROADMAP | n/a: checkpoint status unchanged (CP3 open, nothing promoted) |
| Selector manifest | n/a: no selector added or accepted. TB86 gate manifest committed |
| LESSONS | New lesson (runtime-needing Review → product-slice TB) |
| Consolidation under CLEAN_UP_POLICY | The earlier attempt's 8 WIP records are kept as provenance. The index carries a superseded banner |
| Successor frozen | Exactly one: CB103 (§6), falsifiers in §6 |
| Turn boundary held | Runtime-free. No product, test, selector or workflow mutation in the repository. Patch and manifest committed as artifacts only |
| review_check.py boundary | Recorded in the CHANGELOG entry |
| `STATUS` lifecycle maintained | `IN_PROGRESS` at resume (`Started at` 05:47:31Z preserved, `Resumed at` 09:15:13Z); `COMPLETE` with successor CB103 as the final write |
| Pushed to origin, branch in sync | Confirmed by `git status -sb` after the final push |
