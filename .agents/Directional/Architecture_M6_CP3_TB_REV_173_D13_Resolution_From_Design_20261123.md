# TB-REV-173 — D13 resolved from DESIGN (2026-11-23 UTC)

This record continues turn `M6-CP3-TB-REV-173-P13-SHARED-EDGE-ORACLE-FULL-GATE`, after the [independent review](Architecture_M6_CP3_TB_REV_173_Shared_Edge_Oracle_Independent_Review_20261123.md).

The turn was runtime-free. It used:
- reading DESIGN and the source;
- a Haiku read-only inventory of the code that assumes one trace per port;
- `git apply --check`;
- `clang++ -fsyntax-only`.

## Verdict

**Upheld:**
- The TB173 rejection: 989/996, with the same seven mechanical controls RED (445, 652, 653, 656, 658, 660, 786).
- The independent review's helper non-vacuity check, and its finding that nothing in production yet calls the oracle.

**Withdrawn: the blocker "the owner must decide D13".** I classified D13 as a user decision in TB-REV-172, and that was my error. DESIGN already decides it (E1). The user directed this turn to resolve the block. Option A is applied as DESIGN conformance, not as a change to a user-owned contract. The user may still override it.

**Withdrawn: the independent review's prose CB-195**, `…-ARRIVAL-PORT-OWNERSHIP-PROOF`, which would have wired the oracle into a producer witness. There are two reasons:
- Its measurement is already known. C1 proved the co-tracing (RA-235).
- It is prose, not an exact diff (RA-261).

**Replaced by:**
- the exact CB-195, an unwired retrace helper (E3);
- TB-EXEC-174;
- the wiring split decided in E2 and E4.

## Findings

**E1 — DESIGN decides D13 = A.**
- **Rule 1.** DESIGN §7.2 says that network reduction "may remove redundant traces but may not alter required … port topology" (invariant 8). It also says that "every required singularity port is owned exactly once" (invariant 1).
- **Rule 2.** DESIGN §7.2 says that "the architecture contains no … tiny-region collapse, post-`GlobalTopologyPlan` re-cut … adding one is a stop condition".
  - **D is excluded.** Dropping empty regions is tiny-region collapse.
  - **C is excluded.** Merging downstream repairs the immutable A2a product after the fact, in a later stage.
- **Rule 3.** The determinism requirement in DESIGN §10.1 excludes B. Under B the two traces stop head-on at a point that depends on processing order. The tracing is combinatorial, so it has no canonical midpoint.
- **A is what remains.** In a saddle connection traced from both ends, the two traces are the same separatrix. A keeps one of them. Its origin port is owned by its departure, and the other port is owned by its arrival. This is step 7's removal of a redundant trace, with the port topology unchanged.
- **B and A give the same topology.** Both produce one curve between the two singularities; B only adds a degree-2 node. So the choice between them was never a contract choice.

**E2 — A2a has no step-7 stage, and one trace per port is built into the code** (Haiku inventory, with lines spot-checked).
- `canonical_field_aligned_traces_and_events` creates trace *i* from port *i* (`SurfaceCellTracing.cpp:4305–4337`).
- `validate_field_aligned_candidate` rejects any trace count other than the canonical one (`:5828–5840`). It compares the whole candidate against `canonical_field_aligned_candidate` (`:5232`).
- The termination incidence records only `trace.port` (`:2350–2362`).
- These readers also assume one trace per port:
  - `EmbeddedGraphTopology.cpp:1793–1812` (`originByPort`);
  - `GlobalTopologyPlan.cpp:410` and `:2117–2121`;
  - `field_aligned_publish_origin_events` (`:3873–3899`).
- So applying A is a **new A2a step-7 selection** placed inside the canonical derivation, before validation. It must not touch the tracing loop. Because it sits inside the canonical derivation, the validator compares against the same selected product and stays a single writer. The selection has to be order-independent: remove trace Y when Y retraces trace X along edges, the two traces have swapped end singularities, and Y's origin port id is greater than X's.

**E3 — The exact CB-195 is the predicate that selection needs, unwired.**
- It adds `exact_source_paths_retrace_along_edges(a, b)` to `ExactSourcePath.h`. The function returns true only when all of these hold:
  - the ends of `b` are the ends of `a`, swapped;
  - every piece of both paths has an edge interval;
  - the merged per-edge coverage of the two paths is equal, regardless of carrier or where the pieces break.
- It reuses CB-194's `exact_source_piece_edge_interval`.
- **Scope is narrow on purpose (RA-251).** It does not recognise a retrace through a face interior. That is the only case C1 witnesses, so interior retrace stays unwitnessed and out of scope.
- **Tests:**
  - Positive: a chain run back on a different carrier, broken at a different point, in both argument orders.
  - Negatives: the same direction; swapped ends along another edge; an extra out-and-back stretch on which every piece lies on an edge; a face-crossing path.
  - A helper that only compares ends fails the third negative. A helper that only compares coverage fails the first negative.

**E4 — The wiring is split into three narrow CBs, each followed by its own TB.**
- **CB-196, arrival-port record.** Add the published field and fill it with the port of the terminal singularity whose `firstOutgoingCarrier` and start face the arrival retraces. No trace is removed, so the products are the same and only receipts change.
- **CB-197, step-7 selection.** Remove each retraced duplicate inside `canonical_field_aligned_candidate` and make every one-trace-per-port reader port-set-aware (E2 list). Add the assertion that every region owns at least one source face (C4).
- **Expected result.** The seven mechanical controls go green. Row 652's plan has 2 regions.
- **Before CB-197 is frozen**, its Review must grep every `trace.port` and `candidateTraces.size()` reader again (RA-247).

**E5 — The other A2a breach stays separate.** Dropped `CollinearOverlap`/`EndpointTouch` contacts and the per-grazing-edge count (§4.5) cover partial co-tracing, which no gate row witnesses. They are recorded as an obligation and are not on this path.

## TB-EXEC-174 rules (frozen)

1. **Manifest:** `gates/Architecture_M6_TB174_P13_Retrace_Oracle_Full_Gate_Case_Manifest.tsv`.
   - SHA-256 `f98436b2744dea6f9a0f1a490463d158ac657e9e7ed20343e0b89b188e9db8e7`, 998 rows.
   - The 491-row prefix hash `483f1101…038` and the 994-row prefix hash `704dcf6c…09c6` are unchanged.
   - Membership 1079.
2. **Required result:** 991 PASS. Rows 995–998 PASS, and the same 7 rows are RED.
3. **Comparison:** every other row must equal TB173 `14821438542` under N1–N3, plus any assertion-line moves the diff proves. The tests are appended at the end of the file, so no moves are expected. Any other difference means STOP and return to Review. No census.

## Turn sequence

1. CB-195: compile only.
2. TB-EXEC-174.
3. TB-REV-174: freeze CB-196 exactly.
4. CB-196, then TB-EXEC-175, then TB-REV-175: freeze CB-197.
5. CB-197, then TB-EXEC-176.
6. Then row 979, Branch A and CB-190, as before.

## Lessons

- Before asking the user to make a decision, check whether DESIGN's invariants and stop conditions already exclude all but one option.
- Before freezing a "remove a duplicate" repair, check whether the stage that DESIGN says removes it actually exists in code.
