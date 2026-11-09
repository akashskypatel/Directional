# Mandatory boundary-chain scheduling — D5 Review/Definition WIP (2026-11-09)

**Canonical turn:** `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SCHEDULING` (64B). **Not complete. No successor implementation is approved.** This is runtime-free review evidence, not a code/test change, scheduler acceptance or product promotion.

## 1. Exact authority and existing evidence

- Immutable compiled source CB109 `3f64cbf2c79ab580bbf97509142df1d5415c4404`. Predecessor TB92 918/918 PASS, membership 999, seven A3 receipts, registered Cylinder PASS / BunnyRandom RED / Vase completion RED. Accepted CP2 491/491; stable 66/17/49 debt1; 81 deferred; selector497/CP3 unpromoted.
- Initial D5 source snapshot `8619797108487b7de8206a8a95f1560fbbf6420d` (workflow 42549408358, 6,282/6,282 file hashes) and later `18102b6249068f440dcb2150dfb2e014a9aa225c` (workflow 42551485386, artifact 13645093415, inner source.tar.gz SHA-256 `079f70dfdda1c5f0a4b8b63608be266b5b586d6aa6000488c2f2bc92ec20a50f`, 6,283/6,283 checksums verified in this continuation). GitHub compare after the latter snapshot found only D5 Review docs, a removed trigger marker and root `STATUS`; no source/test/fixture/selector/benchmark/workflow files changed.
- Prior independently inspected TB92 Vase census artifact 13643067924 (9/9 inner hashes) exposes aggregate counts but no complete per-original-arc oriented walks, source carriers, fan stops or child-to-breakpoint maps. The reported 145 Mandatory, 3 Trace, 164 exterior subdivisions, regional totals 70/94/46 and hypothetical 62/64 scheduling outcomes **do not prove any admissible joined chain**. No real Vase chain-compression result is claimed.

## 2. Source-derived obstacle and conservative contract

`EmbeddedGraphTopology.cpp:497–557` produces original Mandatory A2b arcs, including splits at exact Trace contacts; `:384–414` can synthesize topology nodes absent from the original field network. `RemeshPipeline.cpp:1005–1016` creates an A3 span for **every original arc**. `GlobalConformityBaseline.cpp:279–456` validates exact span/arc bijection, original region-boundary occurrence identities and parity. `SurfaceCellTracing.cpp:17449–17641` still consumes single-piece positive per-arc Mandatory schedules. DESIGN §7.4 explicitly demands positive counts for each full A2b arc. Simply replacing the spans with chain units or inserting fake zero-count children is invalid; scheduling must not change before its own normative amendment and producer/validator/consumer design.

A chain is a **view over immutable original A2b arcs**, seeded by prevalidated ordered `SurfaceCellRail::sourceEdges/sourceVertices/closed` (`SurfaceCellTracing.h:108–117`; validation at `SurfaceCellTracing.cpp:4369–4414,4587`). Map ordered source-edge keys to Mandatory network edges, then to original A2b child arcs, accounting for Trace-terminal splits. Do not build a second rail graph or use spatial welding. Only join adjacent children after independently verifying identical component, **side-specific sheet ownership**, and `HardRailId`, exact endpoint equality, matching ordered region/exterior incidences, unique unbranched rotation, and no Trace/Cut, port, corner or terminal. Closed uncut rails, same-region loops and ambiguous continuations stay singleton. Distinct `NetworkEdgeId`s may share a rail. Record typed rejections.

Store each chain's **ordered, oriented original child IDs only**; recover exact carriers, owner occurrences and component/sheet/rail lineage from unchanged validated stage inputs through checked lookups. Do not introduce redundant parallel copies. D7 metric runs and D7b rational placement remain authoritative. A later scheduling switch must independently expand each unit interval to all original region incidences, including children without interior breakpoints; reversal maps `j ↔ n-j`. The independent validator recomputes child/occurrence coverage without trusting producer flags or hashes.

Related current-source seam: [retained partition product/validator WIP](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Retained_Product_Seam_WIP_20261109.md).\n\nSee [incidence proof gates](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Incidence_Proof_Gates_20261109.md) for detailed parity conditions and [evidence recovery](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Evidence_Recovery_20261109.md) for the exact production/view/TB route.

## 3. RA-214 authority correction and smallest next slice

RA-214 §1.3/§2 prohibits diagnostic-only Code + Build slices: runtime-derived Review facts may only be measured by an immutable Test + Benchmark turn exercising **a retained product representation, oracle or producer**. The previous idea to add a test-only Vase exporter is withdrawn; do not implement it. The next candidate product is a **certified Mandatory boundary-chain topology partition** plus independent validator, with original A2b and A3 scheduling unchanged. It is intended for later A3 consumption, not a digest/log sidecar. Before CB authorization this Review must freeze exact source/test patches, true independent falsifiers, accepted selector protection and a single bounded successor.

The product must partition every original Mandatory arc exactly once, retain signed children/owners/carriers and typed rejected joins, and validate from original A2b/network/source-region facts. The **non-vacuity gate** for its later artifact-only TB is at least one real production Vase unit containing two or more **different original Mandatory arc IDs**, with independently derived source/region/rail/sheet proof; otherwise route to Review without claiming a chain reduction. Required negatives: Trace terminal, different component/side-sheet/rail/region, branch/port/corner, self-loop/cycle, missing/duplicate/reordered child, reversed boundary owner, foreign carrier, gap/overlap, and wrong source-support endpoint. Source-row permutation, exact path segmentation and chain reversal must preserve physical meaning.

Only after such measured evidence may a separate count/placement and A4-consumer switch amend DESIGN §7.4 and recompute exact chain parity. Keep D4 uniform/annulus, D9c factory carrier, reciprocal Trace, A4 disc, D8 and D6 user decision separate. **A first product view that adds no valid join is not a successful D5 behavior change.**

## 4. Current blockers to Review completion

1. The exact production type and attachment location, independently implemented validation seam, source/test diff and immutable TB artifact oracle are **not frozen**. A conceptual view without a later consumer or independent failing tests is not an adequate successor.
2. Actual production-derived Vase arc/region/source-support incidence sufficient to prove at least one admissible pair does not appear in existing checked census output; runtime may occur only in a separately authorized TB of a retained product.
3. No per-unit-positivity normative amendment, approved multi-child consumer or complete source-to-region parity equivalence proof exists. They cannot be silently delegated to implementation.
4. Handoff/TODO/ORIENTATION/CHANGELOG/ROADMAP and the Review §5 final closeout have not been updated to claim a completed D5 definition. The next session must remain in this exact turn rather than starting 64C.

**Boundary checker (actually executed in this continuation):** `python3 .agents/Directional/tools/review_check.py boundary` on the verified source snapshot exited **1**. Product/test/fixture/build and selector mutation checks printed clean, but history-based ancestor and durable rewrite checks fail because the archive has no `.git`. Selector “untracked/new” labels are artifacts of the history-free archive, not evidence of current-branch selector changes. An authenticated Git-history-level pass remains outstanding.

## Review closeout — open obligations, **not a final acceptance**

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a this attempt: no selector change; exact-head comparison found no selector paths; history-based checker remains unverified |
| Decisive claims independently re-derived | Source bijection/parity/source-path/rail access checked against verified snapshot; snapshot 6,283/6,283 hashes |
| Non-vacuity checked | Existing aggregate Vase figures cannot prove a joined chain; positive and tamper controls are mandated but not run |
| Prior obligations discharged/carried | RA-214 diagnostic-only withdrawal discharged; RA-216/217 D7/D7b reused; 64B chain proof, D4 64C/64D, D9c 65A, Trace 65B, A4 65C, D8 65D, D6 decision carried |
| Stable accounting | No accepted loss; CP2 491/491, stable 66/17/49 debt1, 81 deferred, selector497/CP3 unpromoted |
| New candidates/obligations recorded | Candidate production chain partition/independent validator in evidence-recovery companion; tracker closeout pending |
| ORIENTATION currency line | Pending final review resolution; currently still identifies 64B as immediate next |
| ORIENTATION §3 / §4 / §7 / §8 | Pending; no witness or accepted status change; open D5 obligation persists |
| CHANGELOG | Pending final definition closeout |
| ROADMAP | n/a checkpoint change: 64B remains active; review before final closeout |
| Selector manifest | n/a no selector change or acceptance |
| LESSONS | Existing lessons on non-vacuity and runtime-free Review apply; no new lesson claimed |
| Consolidation under CLEAN_UP_POLICY | Older source-audit supplements consolidated into this WIP/companion files; no durable history deleted |
| Successor frozen | **No**; one exact product source/test patch plus TB falsifiers still required |
| Turn boundary held | Runtime-free; no product/test/fixture/selector or workflow mutation in this Review |
| review_check.py boundary | Exit 1 in history-free archive; cannot claim full pass |
| `STATUS` lifecycle maintained | Entry/resume beacon written; final same-turn beacon required as last repository action |
| Pushed to origin, branch in sync | Connector writes land remotely; final PR/head verification required; local `git status -sb` cannot prove origin sync from a source tarball |
