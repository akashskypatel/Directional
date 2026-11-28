# TB-REV-187Q adversarial continuation (2026-11-26 UTC)

Continues `M6-CP3-TB-REV-187Q` after the [independent review](Architecture_M6_CP3_TB_REV_187Q_QF1_Behaviour_Preservation_Independent_Review_20261126.md). Runtime-free: source reading, plus Haiku read-only work (close_sheets options and gating, harness modes, quotient product API) and a syntax-only check of one exact diff in a throwaway `CLAUDE_` worktree, since removed. Product and test bytes unchanged.

## Verdict

- **Upheld:** TB187Q 1006/1006 as a behaviour-preservation gate for CB-207A/B. Static re-read agrees: A keeps the total-order insert and the DFS; B's bucket predicate equals the old two-endpoint test.
- **Upheld:** CB-206 as the next turn (diff `e1be85e0…9cdb`; both preimages still equal HEAD; `git apply --check` passes).
- **Gap closed:** the review named TB-EXEC-186T but froze no executable plan for it. The only bounded observer cannot run it (Y2). Its census manifest is frozen now.
- **Contingency frozen:** QF1 A/B leave a per-class O(M²) search (Y3). Exact CB-207D is frozen but applied only if TB-REV-186T sees a cutoff.

## Findings

**Y1 — TB187Q proves preservation, not efficacy; the scale evidence makes the 0.02 rows the risk.**
- Row 1006: 51.56 s versus 52.17 s. No gated row runs a quotient large enough to show QF1.
- close_sheets passes the full pipeline in gated rows 795 (`SurfaceCellDesignAcceptance…/CloseSheets`) and 934 (`SurfaceCellDesignD4RimCensus…/CloseSheets`) at lengthRatio 0.18 (`milestone_g_manifest.json:102–111`). It stalled only at 0.02 (TB185T). So the cost grows with resolution.
- Activated sphere rows at 0.02: 843 and 844 (`produced_network()`, options identical to row 1006 polyline-defaults), 858 (`SurfaceCellTracingDisplayTests.cpp:22–57`, defaults), and the row 1006 polyline recipe. Rows 648 and 979 run at 0.2.

**Y2 — TB-EXEC-186T had no harness path. The census mode is the right one.**
- Diagnostic mode (`m6_cp3_targeted_artifact_harness.sh:784–788`, `:832`) observes only `cases[-1]` and reads `raw/1006.log`, so it is single-row by construction.
- Census mode (all rows `OBSERVE`, no ledger; `:698`, `:800`) runs each row with a 600 s cap and records `HARNESS_TIMEOUT`. That works without any harness change.
- Frozen: a six-row OBSERVE manifest, SHA-256 `80970f59…eefc`, and the [report contract](gates/Architecture_M6_CP3_TB186T_CB207D_Activated_Sphere_Termination_Exact_Manifest.md).
- If a stack sample of a non-1006 row is ever needed, that needs a harness change, which is out of scope here.

**Y3 — CB-207A/B do not touch the one-huge-class branch (TB-REV-185T adv. W4).**
- The producer's final class paths (`RemeshPipeline.cpp:6118–6123`), the publication check (`:6547`) and the verifier A6 check (`:8587`) each search from the class root once per member. Each search allocates a new parent map.
- That is O(M² log M) for a class of M members: the same order as the rebuild A removed, once K is small.
- **CB-207D** splits the search from the parent walk and caches the exhaustive per-root parents. The output is identical by construction, for any graph: parents are assigned once, at first discovery, and stopping early only truncates.
  - Diff `8d76d42c…61a3`, `5da1fcc9…dd03` → `955d794c…29a0`, +65/−17.
  - `git apply --check` passes at HEAD.
  - Syntax-only: 0 errors and 31 warnings at both HEAD and patched; the warning sets are identical once line numbers are stripped. Not compile evidence.
- **Contingent.** It is applied only after a measured cutoff, which follows the QF1 manifest rule "measure, not more cost fixes".

**Y4 — There is an irreducible output term.**
- Every non-root member publishes its full root→target `orderedRelations` (`RemeshPipeline.h:1115`, pushed at `:6184`). That output is Σ depth.
- For deep classes no traversal fix helps, which makes it a representation and design question.
- The size receipt (CB-207C) is feasible as test-only: `productSnapshots.quotientProduct` is retained when `retainIntermediateGeometry` is set (`RemeshPipeline.h:359`; accessors `:1292–1340`). It is frozen only if TB-REV-186T needs it.

**Y5 — Carried.** X1–X5, S/U/W/R/V obligations, V5 BunnyRandom, the row 858 premise (X2), J6/E5/CB-190 and CP3/497/D0/H4 held. QF1 is not stable. No new stable event.

## Turn sequence

1. `M6-CP3-CB-206-P13-SLIDE-ENTRY-ACTIVATION` — exact, compile only.
2. `M6-CP3-TB-EXEC-186T` — six-row OBSERVE census on the CB-206 package, 600 s per row, frozen manifest; no gate credit.
3. `M6-CP3-TB-REV-186T` — classify:
   - **All six finish:** adjudicate row 858 and the CB-206 receipts, then go to step 6.
   - **A row hits the cap:** go to step 4.
4. `M6-CP3-CB-207D-QF1-ROOTED-CLASS-PATH-SEARCH-ONCE-PER-ROOT` (exact, contingent) → `M6-CP3-TB-EXEC-186U`, the same census.
5. `M6-CP3-TB-REV-186U`. If a row still hits the cap, freeze the CB-207C size receipt; no more cost fixes until sizes are known.
6. `M6-CP3-TB-EXEC-186` (full gate + V5, STOP-on-RED; any CB-207D included and compared under N1–N3) → `M6-CP3-TB-REV-186`.
7. Then parameter deletion, V3b, R1, O48. CB-190 stays off the critical path.

## Lessons

- When a review names a bounded diagnostic, it must also freeze the harness mode and the case manifest. A diagnostic that needs a harness change is not executable.
- A fixture that passes at a coarse resolution and stalls at a fine one is evidence of scaling. Check which readers run at the fine resolution before you trust a coarse gate.
