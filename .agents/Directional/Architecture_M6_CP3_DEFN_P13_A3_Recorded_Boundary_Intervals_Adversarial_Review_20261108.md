# RA-215 — Step 61 (D9 recorded boundary intervals) re-entered: exact CB104, falsifiers re-bound, D4 owned

**Turn:** `M6-CP3-DEFN-P13-A3-RECORDED-BOUNDARY-INTERVALS` (adversarial re-entry of the [step-61 decision](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_A3_Recorded_Boundary_Intervals_Review_20261108.md")). Runtime-free (`REVIEW_TURN_POLICY.md` §4.3). Product and test sources are CB103 `000752d8…`, unchanged at HEAD. I read the TB86 gate-result artifact `13613643740` as evidence, in an isolated scratch directory; nothing was built or run. Patch authoring used `-fsyntax-only`, which produced no object file and is not evidence.

## 1. Verdict

The core contract of the step-61 decision stands. The producer and factory change is correct, and the consumer census is accurate. But the decision does not deliver a CB104 the implementation agent can execute:

- It rejects, on a false premise, the one existing fixture that witnesses the change.
- It then hands test design to CB104, with a "stop if no fixture exists" clause.
- Three of its TB87 falsifiers name outcomes that no predicate produces, or that no rim fixture can construct.
- Its digest expectations amount to rebaselining after the fact.

RA-215 freezes an exact CB104 (core plus test) and an exact TB87. It also gives the open D4 gap (uniform and annulus producers ignore A3) an owner.

## 2. What stands

- **Producer** (`SurfaceCellTracing.cpp:17628`, `:18186`). Curved-disk already subdivides every rim edge by A3 ordinals. Recording `hardFeature || sourceBoundary` and requiring presence on `HardRail || GenuineSourceBoundary` is consistent:
  - `edgeAuthority.sourceBoundary` (`:16877`) and the `GenuineSourceBoundary` classification (`:13124-13126`) use the same full incidence map (`:15540`).
  - An interior non-hard edge never reaches the check: it is rejected at `:13148`.
- **Factory** (`:9386`). It admits a present interval on a `GenuineSourceBoundary` edge only when the edge is exterior and has no twin. An absent rim interval stays legal, because the receipt is minted for every producer (D8), and the uniform and annulus producers publish rims without intervals. The requirement that HardRail intervals be present is unchanged.
- **Consumers.** Every product reader is kind-gated or needs both sides:
  - `RemeshPipeline.cpp:4832` and `:5109`;
  - `SurfaceCellTracing.cpp:8252`, `:9464`, `:19064-19141` and `:19950`;
  - `RemeshPipeline.cpp:2285` hashes the interval, and `:9674` is the CB103 report.

  A single-sided rim interval is therefore inert everywhere except in the digest and the coverage report. Test readers are also safe:
  - `FieldAlignedCurveNetworkTests.cpp:17320` (any interval ⇒ PeriodicCut) runs on the closed torus, which has no `GenuineSourceBoundary` edges.
  - The quotient-test readers are kind- or span-gated.
  - GUARD 909's assertions are relative (`≥`, `−1`).
- **Upheld.** The withdrawn draft test was wrong to expect the generic factory to reject an absent rim interval.

## 3. Findings

| # | Severity | Finding | Evidence | Disposition |
|---|---|---|---|---|
| F1 | high | **The witness was rejected on a false premise.** The decision says `build_rectangular_hard_rail_phase_front` "does not establish a curved-disk A3-consuming non-hard rim". It does. With an A3 plan, the uniform and annulus producers return NotApplicable for any region that touches a hard edge (`:13432-13435`, `:14243-14246`). Every region of that fixture touches the rail, so curved-disk produces all of them in cut-domain mode (`:15549-15553`). Their outer rims are physical, non-hard and A3-scheduled: every run edge needs a mandatory schedule, or the run is rejected (`:17421-17491`). The fixture is a single global run (`parallelizeComponents=false`, `RemeshPipeline.h:246`), and GUARD 909 already shows it is Produced. | static | Test frozen on this fixture (§4) |
| F2 | high | **CB104 was not exact.** The implementation agent was asked to author "the smallest non-vacuous" test and to stop if no fixture could be found. That is test design inside a compile-only turn: it breaks the exact-patch rule, and its success could not be checked before TB87. | step-61 §"Required CB104 test repair" | Replaced by an exact patch (§4) |
| F3 | medium | **Claimed validation does not exist.** The decision says the factory validates "source attachment" of present rim intervals. Nothing checks it: the factory holds only the receipt digests, never the A3 plan. TB87 falsifier 2 ("corrupt … source attachment", "foreign span") therefore names no rejecting predicate. | `:9383-9425`; receipt `SurfaceCellTracing.h:1505` | Attachment becomes a test oracle in CB104 (carrier = route step = physical edge). A foreign or cross-span tamper is visible only to the CB103 report. The factory-side gap is registered as **D9c**, owned by step 65 (reciprocal trace intervals need span-to-carrier authority) |
| F4 | medium | **One falsifier cannot be built.** Falsifier 3 asks for "same-source cross-region rim occurrences sharing a NetworkArcId". A physical edge has exactly one incident face, so one region and one A3 incidence. No rim can satisfy it. | `:16871-16877` | Moved to step 65 (trace seams) |
| F5 | medium | **Digest expectations were left open.** "Register any changed curved-disk digests as expected candidate differences" rebaselines after the fact. Statically, all seven pinned lines run on producers CB104 does not touch: the four gate cases record no interval at all (TB86 covered=0), so none runs curved-disk with a rail; Cylinder is annulus; BunnyRandom fails before A4; Vase has observed=0. | TB86 report | **Prediction:** all 7 `platform-digest` and 7 `a3-coverage` lines byte-identical to TB86; any change → REV |
| F6 | low | **Unlisted behaviour change.** A physical edge listed in `hardFeatureEdges` is now accepted. Before, it recorded an interval and was classified GSB, and the presence check rejected it. The pipeline derives hard edges from HardFeature-kind rails only (`RemeshPipeline.cpp:10023-10046`), so production is unlikely to reach this. | static | Intended (GSB precedes HardRail at `:13124`). TB87 guards against row flips |
| F7 | low | **Comment lost facts.** The core patch's header comment dropped "required for production HardRail pairing" and "periodicRelation remains the quotient owner". | core diff | Restored in the exact patch |
| F8 | trajectory | **D4 has no owner.** The uniform and annulus producers ignore A3 entirely (`:13410-13413`), yet they produce every observed gate case under a receipt. That is DESIGN §2.1 item 7 ("every region's construction consumed the certified global plan unmodified") failing on all produced fixtures. CB104 changes none of them. | TB86: 4/4 covered=0; RA-213 boundary counts (non-accepted) | New step **64A** DEFN, after D7 |

## 4. CB104, frozen exact

[`Architecture_M6_CP3_CB104_P13_A3_Source_Rim_Intervals_Exact.diff`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB104_P13_A3_Source_Rim_Intervals_Exact.diff"):

| Property | Value |
|---|---|
| SHA-256 | `dfacc5cbc535b16b8b387431a4078c3db3120acbee2ab7e2eac71b044364bb0c` |
| Size | 227 lines |
| Single-space context lines to keep | 2 |
| Numstat | `3 1` `SurfaceCellTracing.h` / `10 5` `SurfaceCellTracing.cpp` / `147 0` `SurfaceCellsPhase10Tests.cpp` |
| Base | product = CB103 `000752d8…` (HEAD) |
| `git apply --check` | clean |
| `-fsyntax-only` | 0 errors in both translation units; the only warnings are 5 pre-existing ones in `PCFaceTangentBundle.h` |

It contains the step-61 core unchanged except for the F7 comment. The superseded `…_Core.diff` (`916c591a…`) must not be applied on its own.

**New test** `SurfaceCellAuthorityContractCutover.A3SourceRimIntervalsAreRecordedSingleSidedAndValidated` (GUARD 910). It runs the rectangular hard-rail fixture in both face-row orders. For every `GenuineSourceBoundary` edge it checks:
- the edge is exterior, has no twin, and has an interval;
- the span's single support carrier is a physical edge (one incident face);
- the route has exactly one Boundary step on that carrier, with the interval's orientation.

Plan-side completeness, independent of the product:
- every A3 span on a physical edge is recorded;
- coverage shows `partial=0` and `foreign=0`;
- every rim span is covered.

Factory checks, forward order only:
- the unchanged product is re-accepted;
- a dropped rim interval is accepted by the factory, while coverage loses exactly one span;
- a stretched interval, an orientation against the ordinal sign, and an interior (`exterior=false`) rim are each rejected with `InvalidSharedBoundaryInterval` at that edge.

**Non-vacuity.**
- On the pre-change source, the first rim edge has no interval, so the test fails.
- With factory admission only, the same assertion fails.
- With producer recording but no factory admission, the fixture is not Produced.
- If the `exterior`/twin clause is omitted, the "interior rim" tamper is accepted, so the test fails.

**CB104 routes:** apply exactly, run the eight-target GMP compile, package, and run nothing.
- mismatch → `M6-CP3-PLAN-P13-A3-RECORDED-BOUNDARY-INTERVALS-STOP`;
- infrastructure → `M6-CP3-CB104A-P13-A3-RECORDED-BOUNDARY-INTERVALS-ORCH`.

## 5. TB87, frozen

`M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-EXEC` runs on the CB104 package.

| Property | Value |
|---|---|
| Manifest | [`Architecture_M6_TB87_P13_A3_Source_Rim_Intervals_Full_Gate_Case_Manifest.tsv`](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB87_P13_A3_Source_Rim_Intervals_Full_Gate_Case_Manifest.tsv"): TB86's 909 rows plus GUARD 910 |
| SHA-256 | `c435519f6304fdcedb794e45187c8c4645e0bb36d32ec567e7979d292fb245bf` |
| Harness self-check | `SELF_CHECK_PASS cases=910 deferred=81` |
| Ledger | v5 `fd433f54…` |
| Membership | 991 |
| Census | unchanged, 3 rows `3af1dc0d…` |

**Expected results:**
- The gate is 910/910, and GUARD 909 and 910 both PASS.
- For rows 795, 796, 797 and 864, both the `platform-digest` and the `a3-coverage` lines are byte-identical to TB86: `observed=1 covered=0 partial=0 foreign=0`, scheduled 24/16/14/81.
- For the census, the Cylinder, BunnyRandom and Vase `platform-digest` and `a3-coverage` lines are byte-identical to TB86. The outcomes are Cylinder PASS, BunnyRandom P13-e RED, and Vase legacy RED.

**Routes:**
- mismatch → `M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-REV` (Review, runtime-free);
- infrastructure → `M6-CP3-TB87A-P13-A3-RECORDED-BOUNDARY-INTERVALS-ORCH`.

No test repair happens inside the TB.

## 6. Realigned sequence

| Step | Turn | Owner |
|---|---|---|
| 61 | this re-entry (RA-215) | Review, runtime-free — COMPLETE |
| **62** | **`M6-CP3-CB104-P13-A3-RECORDED-BOUNDARY-INTERVALS`** (exact §4) | implementation agent, compile only |
| 63 | `M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-EXEC` (§5) | implementation agent |
| 64 | `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC` (D7, then D5; DESIGN §7.4) | Review, runtime-free |
| 64A | `M6-CP3-DEFN-P13-A3-UNIFORM-ANNULUS-CONSUMPTION` (D4). The uniform and annulus producers must adopt A3 rim and cut breakpoints and record them, or else decline honestly under an A3 plan. After 64, because D7 changes counts. Independent of 65; required before CP3 promotion. | Review, runtime-free |
| 65 | `M6-CP3-DEFN-P13-A4-A2B-DISC-DOMAIN`: plan-trace edge kind with reciprocal intervals, D9c span-to-carrier authority, and the old falsifier 3 | Review, runtime-free |
| 66+ | per-disc boundary and corners (D6) → fill → dispatch | one DEFN → CB → TB each |

## 7. Corrections to the step-61 decision

- Its §"Required CB104 test repair", its "Frozen CB104 scope", and its TB87 falsifiers 2–4 are superseded by §4 and §5.
- Its "source attachment" validation claim is withdrawn (F3).
- Its tracker sentence saying the rectangular fixture is not a natural-rim witness is withdrawn (F1).

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edited or accepted |
| Decisive claims independently re-derived | Producer dispatch, rim classification, factory order and every interval reader were read in source. The TB86 artifact confirmed GUARD 909 PASS; its RecordProperty values are not in the raw log, so the test pins relations, not counts |
| Non-vacuity checked | §4: pre-change, partial-implementation and missing-clause variants each fail the new test |
| Prior obligations discharged/carried | D9 rim → CB104/TB87; D9 seam and D9c → 65; D7/D5 → 64; D4 → 64A; D8 caveat stands; D6 user decision pending; P13-e, O30b, O31 (legacy), O32b–e, O33, O27–O29 carried |
| Stable accounting | CP2 491/491; stable 66/17/49; debt 1; 81 deferred; TB86 candidate 909/909, membership 990; selector497/CP3 unpromoted |
| New candidates/obligations recorded | D9c and the D4 owner in the tracker; no stable ID |
| ORIENTATION currency line | updated |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a; §8 dispatch-before-witness pattern added |
| CHANGELOG | entry added |
| ROADMAP | n/a |
| Selector manifest | n/a |
| LESSONS | one lesson added |
| Consolidation under CLEAN_UP_POLICY | `…_Core.diff` retained as provenance; superseded banner on the step-61 decision |
| Successor frozen | CB104 exact (§4), then TB87 (§5) |
| Turn boundary held | no product, test, selector or build mutation; nothing executed |
| `review_check.py boundary` | **ALL CHECKS PASSED** (51 PASS, 10 documents) |
| STATUS lifecycle maintained | IN_PROGRESS beacon pushed at entry (`Resumed at 2026-11-08T12:57:36Z`); COMPLETE is the final write |
| Pushed to origin, branch in sync | yes: the docs commit and the final STATUS commit were pushed; `git status -sb` shows the branch tracking origin with nothing ahead or behind |
