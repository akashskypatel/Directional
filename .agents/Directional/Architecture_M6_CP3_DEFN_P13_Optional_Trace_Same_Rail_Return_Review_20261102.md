# P13 arrangement sliver cells — same-rail support-return incidence audit

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (Review/Definition). **Unfinished**; this is a source and prior-evidence audit, not product implementation, formal CB, or TB.

## Authority and independent inputs

- Semantic CB76 authority `f59f92f889fc6fe22d689fd7559c024cd09c6c72`. Reused immutable full source snapshot event `898316210ab810daa10d2072db927f9ebe4b2a98`, archive SHA-256 `418579f76225ace51e940afbddcef2be12313058a971660421f1da0dfc2e7062`; **6,092/6,092** file hashes independently checked in this attempt. No fresh runtime or build.
- Independently read the prior nine-cell stdout/stderr provenance archive `directional-p13-sliver-nine-cell-review-evidence.zip`, SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2`, and ten-junction wedge archive `Directional_P13_Ten_Node_Wedge_Review_Evidence_20261102.zip`; SHA-256 of latter independently stored in the attached JSON receipt. The older cyclic-side geometry has a documented correction: **29 incorrect side labels, 24 family mismatches**. This new audit uses raw ordered halfedges, not the incorrect side label field.

## Verified five same-hard-rail returns

Each lens has exactly five directed cyclic halfedges partitioning into a continuous three-edge optional support-trace path and a continuous two-edge **mandatory rail 0** path. At *both* transitions the field trace meets the same rail in the **same source face**; the source-entity resolver identifies one source-edge contact and one source-vertex contact for every lens. At each contact the prior independent wedge ledger contains exactly three outgoing rays (two mandatory-rail rays, one support ray), a single source-entity wedge group, and three chosen successors.

| Lens cell | Optional support trace | Seed index / branch | Rail-source edge contact (node; source face) | Rail-source vertex contact (node; source face) |
|---|---:|---:|---|---|
| 26735 | 1037 | 259 / 1 | 56813; 2301 | 56385; 2321 |
| 26764 | 878 | 219 / 2 | 16998; 512 | 47581; 2151 |
| 26781 | 20 | 5 / 0 | 9928; 293 | 56412; 2262 |
| 26802 | 422 | 105 / 2 | 57415; 2364 | 53651; 2385 |
| 26812 | 612 | 153 / 0 | 57661; 2401 | 23821; 2400 |

**Independent 5/5 and 10/10 validation:** `p13_rail_return_audit.py` and `p13_rail_return_audit.json` in the evidence archive reparse the frozen logs, rederive the entire five-edge cycle, distinct source-arc family, original support trace ID, all transitions, same source-face contacts, all three outgoing rays, unique chosen successor IDs, and matching expected tip-node sets. It rejected four separately tampered *copies* of its input: missing hard-rail identity, support-trace strand mismatch, missing tip wedge, and broken boundary cycle. None of these is a formal product test.

## Source-path ownership and safeguards

1. `src/geometry/FlowRepStrands.cpp:608–719` creates optional anchored layout support from boundary/feature/singularity seeds when the trace has segments, begins off a rail, and ends with one of the listed embedded-anchor termination **labels**; it stops on the first authoritative rail suffix and deduplicates reversed whole paths. It does **not** reject all returns to the same hard rail at that creation point. In particular, the termination-label list includes `RepeatedState`; this alone is **not** proof the five traces terminated for that reason.
2. `include/directional/geometry/FlowRepStrands.h:74–121` defines `FlowRepArc::initiallyActive=true` and distinguishes `layoutSupport` from `mandatoryRail`. `FlowRepStrands.cpp:650–719` sets `startEmbeddedAnchor=true` and conditionally sets `endEmbeddedAnchor` only if the retained support path actually reaches the original trace terminal; explicit pre-rail prefixes cannot inherit a rail suffix's terminal anchor. These source safeguards must **not** be deleted or weakened.
3. The prior ten-node ledger independently found 30/30 recorded directed-wedge predecessors consistent and 10/10 matching published lens cell successors. The new cross-log identity audit confirms the retained support+rail network itself forms each two-sided lens. Accordingly the **observed incidence-producing path** lies upstream of pure-quad completion and should be diagnosed in traced support/FlowRep admission and retained network topology, not treated as a random wedge permutation. The upstream trace admission **cannot yet be declared invalid** under an exact source-authoritative requirement merely because the resulting lens is unsupported by completion.
4. `.agents/Directional/DESIGN.md` §4.5 requires exact source-edge grazing transits and continuity at tangency; this does **not** grant a numeric near-parallel suppression heuristic. The earlier lens polygon angles are not chart-transported field–rail tangents. Do not drop hard rail 0, snap near traces based on a world distance, increase `Sliver` area thresholds, accept two-sided patches as pure quads, or weaken the embedding fail-closed check.
5. The four needle cells remain separate: positive seed-owned proposal arcs dominate, some with optional support trace 815/487. Source-authoritative proposal ownership, source-sheet compatibility, and intrinsic corridor width remain unchecked. **No single repair for all nine cells is established.**

## Required next authorized Review action

Check the exact **tracing terminal reasons**, intrinsic start/end point keys, same-sheet rail intervals, transported field/rail tangent at each of the ten contacts, and whether a legitimate required separatrix/coverage/cycle obligation mandates retaining each return. Obtain that evidence without another Review runtime execution (normative `REVIEW_TURN_POLICY.md` §4 requires a runtime-free Review); any new probe must first be authorized under the correct CB/TB or policy exception. If all five are proven optional and nonessential, define a *bounded and falsifiable* source-owned candidate in the support-trace selection path; require a positive valid rail-return control, negative invalid control, reversed/permuted rail control, source-chart/sheet check, unchanged mandatory rails and accepted prefix, and no new singularity or coverage loss. Do not infer that arbitrarily deleting these exact five traces is correct.

## Review policy/boundary result and carry-forward

`python3 .agents/Directional/tools/review_check.py boundary` was executed on the **verified extracted archive**, exit **1**. It reported product/test/build and selector mutation checks PASS locally but four failures: durable rewrite baseline ancestry and three durable-source Git-history checks (`Future_Chat_Session_Handoff.md`, `ORIENTATION.md`, `Regression_Root_Cause_Tracker.md`). The extracted archive has no full repository Git ancestry; the `PASS` lines treating many selector files as "untracked, new this turn" are **not** credible turn-diff evidence. Do not report this as a green policy check or as a product regression. GitHub branch-diff inspection must separately establish the actual mutation boundary.

Preserve accepted CP2 **491/491**, candidate TB70 **880/880** with selector membership **961**, stable **66/17/49**, debt **1**, and no CP3 promotion. Continue the same Review/Definition turn; formal review closeout (ORIENTATION currency, CHANGELOG, root-cause tracker, exact successor falsifiers and repository-backed `review_check.py boundary`) remains unresolved. No new code/build/runtime/selector edits in the working branch are authorized by this report alone.

## Review closeout (interim, intentionally not a completed turn)

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no selector edited or promoted; accepted prefix still requires verification at formal closeout. |
| Decisive claims independently re-derived | 5 lens cycles, ten rail contacts, wedge counts and source identities independently reconstructed from two frozen raw logs; source admission statements checked against CB76 snapshot. |
| Non-vacuity checked | Four independently corrupted input copies rejected by new audit; this does not certify upstream tracing correctness. |
| Prior obligations discharged/carried | P13-i retained-return structure refined; carries exact trace admission/rail transit authority; P13-h2 needle proposal ownership and intrinsic width, P13-e, O23 remain. |
| Stable accounting | 66/17/49, debt 1, CP2 491/491; reported from prior durable authority, not independently re-counted here; TB70 880/880 and membership 961 remain unpromoted. |
| New candidates/obligations recorded | No proved new product defect; candidate falsifier for five same-rail optional trace returns documented in this report, not yet tracker-accepted. |
| ORIENTATION currency line | Not updated; turn unfinished, formal closeout outstanding. |
| ORIENTATION §3 / §4 / §7 / §8 | Not updated; checkpoint/witness state unchanged, pending formal review consolidation. |
| CHANGELOG | Not updated; interim review result, not a completed checkpoint. |
| ROADMAP | n/a — no accepted checkpoint transition. |
| Selector manifest | n/a — no selector change or promotion. |
| LESSONS | n/a — no new proven recurring defect; diagnostic provenance controls documented here. |
| Consolidation under CLEAN_UP_POLICY | n/a — this is new unique supporting evidence, not consolidation of historical files. |
| Successor frozen | No — not justified without trace-admission and needle-owner falsifiers; same Review continues. |
| Turn boundary held | This attempt ran no builds or product tests, changed no production/test/fixture/selector code; offline Python diagnostic only. Prior scratch Review runs remain an acknowledged policy deviation, not a precedent. |
| review_check.py boundary | FAIL exit 1 on extracted snapshot, Git-ancestry dependencies unavailable; 4 failures named above. |
| `STATUS` lifecycle maintained | Entry/resume beacon direct-written; final beacon must be direct-written after all other repository actions with original start preserved. |
| Pushed to origin, branch in sync | Connector writes update the remote branch directly. No local clone tracking branch exists in the extracted archive, so `git status -sb` cannot truthfully confirm synchronization. Independently inspect GitHub PR head and exact diff before final STATUS. |