# TB-REV-159 — independent slide-entry stop-predicate full-gate review (2026-11-22 UTC)

## Situation

**Qualified PASS of the immutable TB159 test gate; STOP on the proposed CB-177 producer switch.** This Review independently checks the accepted gate and census evidence. It does not create or execute producer events. An accepted receipt is not an authorization to change runtime topology. The single next turn is **`M6-CP3-DEFN-159A-P13-SLIDE-STOP-OWNERSHIP-AND-REACHABILITY`** (definition and plan only). Do not begin it inside this Review.

## Background — exact evidence and independent re-derivation

- Compiled semantic source `7c9517fd956bf72847688ee99146bd877137ceb7`, CB176 GMP/GMPXX package `14732005980`. The source snapshot at `42209c93afc5aff85dbba9495a038b596518cbb9` was verified against 5,702 individual file checksums and its source archive SHA-256 `788494daa311098ec575ac2256837074c83ddb043247f2172b91431e51df0310` (run `44972117747`, artifact `14734161168`). That source snapshot includes only later documentation/control commits and the Review entry beacon; no semantic source edit was made in this review.
- TB159 gate run `44968515856`, artifact `14732983057`: outer ZIP SHA-256 `f0fa3c481daf5b9ec8e121d0177ff5bd709672236a3514d41c7e074cd15d0aee`; 1,962/1,962 internal hashes verified. All **977 distinct tests passed**; CP2's 491 accepted cases passed. Postflight true. Source and package IDs match. Compile, configure, relink, benchmark flags are false.
- TB159 census run `44968542188`, artifact `14733451393`: ZIP SHA-256 `6ccc21f8803743d90ec0acba400a9a901f0edba6fe8438846af19844888d5152`, 9/9 hashes. Cylinder PASS; BunnyRandom and Vase retain their expected RED results. No new accepted regression.
- Independent baselines TB158 gate `14725784889` SHA-256 `b50d32d0892cbc8e19db5f827512cdda2cd2d3698e86335bd77d2da1296554e5` (1,960/1,960 internal hashes), census `14727495926` SHA-256 `5b3012ca2a3ca8e9f3e5d4d8bc84c27601fb455913d15b67393998e1f57eb8bc` (9/9).
- The 977-row selector SHA-256 independently recomputed to `993c663f5e916b4ab5a8d812ebfd658384cbec0b8356cd11e84ea76b0107d63b`. Its first 976 rows, including the header, are **byte-identical** to TB158 selector SHA-256 `6a37e4612a6b463eac3de4b5da4ed86f5bba52ac54bfbb1e472ca7508b7caf0f`.
- Compared 976 baseline and current gate raw logs independently after removing **only** the approved `slideContactArrival` suffix and runtime test-duration displays. The remaining non-receipt lines are equal. Independently compared all three census logs, also masking only the approved 16-byte `GetParam` presentation. All differences are approved receipt expansions and runtime/presentation values. The exact 980-row receipt TSV agrees with every raw log's count. No new `InvalidCutGraphBinding` or `InvalidNetworkEventBinding` in the 980 logs. The row 977 test executed and passed.

## Assessment — observed facts versus missing proof

**A1 — two roles are recorded.** The 24 gate rows contain **564** receipt lines in four contact groups, 141 each. All record `movingArrival=later`, `movingCommitted=0`, `wallCommitted=1`, `interior=1`, `stop=1`, and `stopRecord=1`. The census has **18** receipts, up from 15. BunnyRandom adds exactly three reversed-role receipts `moving=142:2 wall=87:0`; each has `wallCommitted=0`. All 18 census records also report interior=1, stop=1, stopRecord=1. Six records have `wallCommitted=0`: three for `26:1->99:0` and three for `142:2->87:0`. This discharges the earlier missing **observation** of reverse role (T2) and strict-internal measurement (T3) and moving stop-record constructibility (T4). It does not discharge producer safety.

**A2 — T5 is a real, still-unproved lifetime obligation.** A pending-wall receipt names the wall's proposed segment index. `stopRecord=1` checks constructibility of the **moving trace's** stop, not subsequent survival or commitment of the wall's segment. The unswitched BunnyRandom logs later commit wall traces 87 and 99. Those logs cannot prove the same segment survives **after** a new event changes the queue. An event that stops a pending wall before its proposed segment commits can leave the struck segment index without a valid owner. There are six observed pending-wall receipts, not zero. A switch must prove ownership and queue ordering, or exclude the unsafe case with a contract-level rationale. Do not infer validity from a clean unswitched run.

**A3 — V3b still lacks production reaching.** New row 977 is a helper/consumer acceptance test. No new source-edge Contact event is published in the tested production path. There is no observed call chain from a canonical producer event through `build_cut_node_bindings`, `build_arcs`, and `build_rotation_system` to a valid node with two opposite along-edge trace rays (composition `(0,2)`, primaries 0 and 2). The test must fail when the event is removed, and the same-direction mutation must reject as `RotationTraceRaysAlongSharedEdge`. Source line inspection of both tracing loops and the event publisher confirms the new receipt calls only classify; they do not enqueue the needed slide Contact. This proof belongs in a separately authorized code/build switch and following artifact-only gate.

**A4 — output topology change is not derivable from these observations.** Sphere row 686 still reports V18/E30/F18, Euler characteristic 6 versus source characteristic 2; four slide contacts have no producer-owned shared nodes. The receipt carries no constructed cut graph or post-switch cell inventory, so the proposed characteristic change 6→2 and any V/E/F deltas are unproved predictions, not an accepted result. The BunnyRandom terminal outcome after a switch is also unmeasured. No fabricated delta is frozen.

**A5 — scoped gate integrity remains accepted.** Independent log comparison and row counts support **977/977 PASS**, stable **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, deferred **81**, CP2 **491/491** accepted. No CP3 selector497, D0, H4, sphere, or product promotion. Amendment 14 remains an interim restriction. No production acceptance is claimed.

## Recommendation — STOP and one bounded definition successor

Authorize only **`M6-CP3-DEFN-159A-P13-SLIDE-STOP-OWNERSHIP-AND-REACHABILITY`**, a runtime-free Review + Plan/definition turn. It must not edit code, tests, selectors, fixtures or builds. It must produce a **source- and ownership-correct exact CB-177 patch proposal** only if it can derive all these preconditions and falsifiers:

1. For both pending-pair roles and the committed-wall loop, define one shared `Later` and strict-interior predicate and the exact existing Contact queue event with `carrierLocus`. Prove the event key is the later arrival. Earlier, Inconclusive and endpoint contacts stay unchanged.
2. Resolve T5 against source code and every `wallCommitted=0 stop=1` receipt. Show the wall's proposed segment either commits with the exact referenced index before publication, or the event is rejected/retimed without a dangling owner. Include a counterexample that would expose a premature wall stop, and state the exact accepted production behavior.
3. Freeze an independently falsifiable V3b test through the **actual canonical** network and rotation-system builder, not a hand-assembled substitute. The production test must reach composition `(0,2)`, primaries 0 and 2, an appropriate face ray and authoritative source-edge identity, and it must fail both after event removal and after same-direction mutation.
4. Give per-row predictions and independent grounds for the sphere cut graph's V/E/F and Euler result and BunnyRandom outcome. If exact topology deltas cannot be derived before execution, explicitly revise the test expectation and stop for a further review rather than inventing a value.
5. Preserve complete prior 977-row selector, CP2 prefix, unchanged census controls, existing fail-closed guards, Amendment 14 and all CP3/497/D0/H4 holds. No CP3 product promotion on diagnostics alone.

**Stop conditions:** any missing authoritative wall segment, invalid cut binding, missing or synthetic V3b event, same-direction edge rays accepted, unmeasured topology delta asserted as fact, change in an accepted gate identity, or cut/selector promotion without separate authority. Only after the definition resolves these conditions may CB-177 be frozen as a later **Code + Build** turn. Do not start CB-177 in this review.

## Review method and limitations

The independent review used downloaded immutable artifacts and an exact source snapshot. No binaries were executed; no production source, tests, fixtures, selectors, benchmark or build files were changed. A repository `.git` history is absent from the source snapshot, so full `review_check.py authority` and `review_check.py boundary` cannot give a full-history PASS in the local container. We verified the exact source and selector hashes, the changed-path set of this review patch, and ran the document-drift audit. The snapshot workflow and GitHub connector confirmed the working branch and PR #8 remained draft. A procedural read-order error occurred: some connector document reads preceded the mandatory snapshot-mode selection. This did not modify semantic evidence.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 976-row prefix byte-identical to TB158 SHA-256 `6a37e4612a6b463eac3de4b5da4ed86f5bba52ac54bfbb1e472ca7508b7caf0f`; full 977-row SHA-256 `993c663f5e916b4ab5a8d812ebfd658384cbec0b8356cd11e84ea76b0107d63b`. |
| Decisive claims independently re-derived | Four artifact outer digests and 3,940 internal digest entries; 977/977 gate; 3/3 unchanged census dispositions; 976-row normalized equality; all 980 receipt table rows; six pending-wall receipts. |
| Non-vacuity checked | Row 977 helper covers positive and negative predicate cases, but no canonical producer reaching; V3b remains unproved. |
| Prior obligations discharged/carried | T2 role observation, T3 measured strict-interior, T4 measured moving stop-record: observation discharged; T5 wall lifetime, V3b source reaching, RA281 F1–F3, RA275 S4a, O47/C5/O48/O49, sphere χ+4: carried. |
| Stable accounting | 66 / 17 / 49, debt 1, deferred 81, accepted CP2 491/491, CP3 selector497 unpromoted. |
| New candidates/obligations recorded | T5 unsafe wall-lifetime uncertainty and missing V3b event recorded in tracker and TODO under new definition successor; no new stable regression counted. |
| ORIENTATION currency line | Updated to TB-REV-159, 2026-11-22. |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §4 and §7 updated; §8 adds the same known T5 pattern, without a new lesson or new recurrence. |
| CHANGELOG | TB-REV-159 review entry added. |
| ROADMAP | M6 CP3 at-a-glance updated; milestone remains active. |
| Selector manifest | n/a — already frozen TB159 manifest remains byte-exact; no selector modification or CP3 promotion. |
| LESSONS | Existing **A claim about production must be observed in production** and **A witness must be capable of falsifying its assertion** applied; no new lesson. |
| Consolidation under CLEAN_UP_POLICY | No obsolete file was deleted or folded: TB159 report and TB-REV-158 record are still needed as source authority. Review facts remain in one owning record. |
| Successor frozen | `M6-CP3-DEFN-159A-P13-SLIDE-STOP-OWNERSHIP-AND-REACHABILITY` — exact requirements and falsifiers above. CB-177 not authorized. |
| Turn boundary held | Review-only evidence and documentation; no runtime or semantic source mutation. |
| review_check.py boundary | Full Git-history check unavailable on snapshot without .git; local document-drift, selector hash and intended changed-path checks performed; no full-history PASS claimed. |
| `STATUS` lifecycle maintained | Review entry beacon written on 2026-11-22 UTC; final beacon must be last repository action after durable document application. |
| Pushed to origin, branch in sync | Pending verified GitHub patch-application push and final current-ref check; do not claim if transport fails. |
