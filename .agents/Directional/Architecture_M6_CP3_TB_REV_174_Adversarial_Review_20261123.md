# TB-REV-174 — adversarial continuation (2026-11-23 UTC)

This continues turn `M6-CP3-TB-REV-174-P13-RETRACE-ORACLE-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_174_Retrace_Oracle_Independent_Review_20261123.md).

The review was runtime-free. It used:
- source reading;
- two Haiku read-only inventories (trace-id references, and readers that assume one trace per port);
- `git apply --check`;
- `clang++ -fsyntax-only`.

## Verdict

**Upheld.** TB174 is rejected for promotion at 991/998.
- The same seven mechanical controls are RED.
- Rows 997 and 998 PASS.
- The other 996 rows equal TB173 after N1–N3 normalization.
- This was the predicted outcome, because CB-195 only adds a helper that nothing calls yet.

**Withdrawn.** The independent review's prose CB-196 `…-ARRIVAL-PORT-OWNERSHIP-RECEIPT` is withdrawn, for three reasons (F1).
- It is prose, not an exact diff (RA-261).
- Most of the data it would print is already decided.
- It does not call the predicate of the switch it is meant to prepare (RA-264).

**Replaced.** The new successor is an exact CB-196, a pure selection helper (F2). TB-EXEC-175 follows it. The wiring scope is also corrected (F3, F4).

## Findings

**F1 — The arrival port is the removed trace's own origin port.** Under D13 = A, take a duplicate pair (X, Y), where Y retraces X backwards along edges with swapped ends.
- X arrives at Y's origin singularity, along the direction Y left by.
- The port that X's arrival owns is therefore `Y.port`. No geometric matching of ports to carriers is needed. My earlier TB-REV-173 E4 plan matched against `firstOutgoingCarrier`, which is unnecessary, and I withdraw it.
- Row 652's pairs are already decided by elimination (TB-REV-172 C1). A census of every arrival across the gate would print evidence that the switch never reads.
- The only receipt worth adding is one that calls the selection helper itself, per fixture. Whether to add one is a TB-REV-175 decision (F4).

**F2 — The exact CB-196 helper.** It adds `ExactSourceRetracedTrace{kept, removed}` and `exact_source_retraced_traces(paths)` to `ExactSourcePath.h`.
- For each later path, it pairs that path with the first earlier path that is not removed and that it retraces (using the CB-195 predicate). A kept trace is therefore never removed.
- The index is the port order, which is canonical. So the rule does not depend on the order in which traces were traced. That is the determinism D13 = A relies on (DESIGN §10.1).
- **Positive test:** two saddle connections, each traced from both ends on different carriers, interleaved with a face-crossing trace. The expected result is the pairs {0,3} and {2,4}. Reversing the input order keeps the earlier trace.
- **Negative tests:** a same-way copy, a reverse path along another edge, an empty path, an empty list and a single path all return nothing.
- **Mutation check:** a helper that removes both members of a pair, or keeps the later one, fails the positive test. A helper that ignores direction fails the same-way negative.

**F3 — Removing a trace after tracing leaves dangling references to it.** These references are written while the traces are traced, on the production path (`canonical_field_aligned_traces_and_events`):
- `field_aligned_publish_contact` (`SurfaceCellTracing.cpp:4108–4284`) writes `terminalContact.struckTrace = Y.id` on any trace Z that stops on the duplicate Y.
- It also emits `FirstContact` and `TraceIntersection` incidences that name Y.

So CB-197 cannot just delete Y. It must remap every reference to Y onto X:
- `struckTrace`;
- each event incidence, re-deriving its role from X, since the contact point lies inside X;
- the origin and termination events of both ports.

This is safe for two reasons:
- X and Y are the same curve, so every contact point on Y is also on X.
- A collinear contact between X and Y is never classified as a contact, so X and Y never stop on each other.

The `finalize_field_aligned_events` path runs only for the diagnostic contact census (`:5494–5501`), not in production.

**F4 — The wiring needs two CBs: the selection itself, then the readers that assume one trace per port.** The selection must not be split from the reference remapping, or the network refers to a trace that no longer exists.
- **CB-197 (A2a):** call `exact_source_retraced_traces` inside `canonical_field_aligned_candidate`, after tracing and before validation. Build each trace's path with the piece-accurate builder `exact_trace_segment_pieces` (`EmbeddedGraphTopology.cpp:955`), not `exact_trace_path` (`:325`). The latter turns an edge slide into a single face piece, which is wrong for traces that slide.
  - That builder lives in the embedded-graph layer. Per RA-276 it must first move to the lower layer, so CB-197a is an extract-only refactor whose products stay the same.
  - CB-197b then removes each retraced trace, remaps the references (F3) and records which port each kept arrival owns (`Y.port`).
  - The validator then compares against the same selected product, so it is not a second writer.
- **CB-198:** make the one-trace-per-port readers use the port set:
  - `EmbeddedGraphTopology.cpp:1793–1812`;
  - `GlobalTopologyPlan.cpp:410`, `:2117–2121`;
  - `field_aligned_publish_origin_events`.

  CB-198 also adds the every-region-owns-a-face assertion (TB-REV-172 C4).
- Before CB-197b is frozen, a test-only receipt should report `exact_source_retraced_traces` per mechanical fixture. Row 652 is predicted to give 4 pairs. TB-REV-175 decides whether that receipt is needed or whether CB-197b's test reaches it directly.

**F5 — Gaps the independent review did not record.**
- It did not check that the helper's empty-path and face-interior negatives make sense for production paths. A path builder that fails returns `nullopt`, so CB-197b must fail closed on a missing path and must not treat it as "no retrace".
- It did not carry the dropped-`CollinearOverlap` obligation (TB-REV-173 E5).

## TB-EXEC-175 rules (frozen)

1. Manifest: `gates/Architecture_M6_TB175_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv`.
   - SHA-256 `e1d77fd2a10b67e71ecbc6712a92eec48713e91e0006c7282652dc2391b43e35`, 1000 rows.
   - Prefixes unchanged: 491 rows `483f1101…038`, 994 rows `704dcf6c…09c6`, and 998 rows = the TB174 manifest `f98436b2…8e7`.
   - Membership 1081.
2. Required result: 993 PASS. Rows 995–1000 PASS. The same 7 rows are RED.
3. Every other row equals TB174 `14833644440` under N1–N3, plus assertion-line moves that the diff proves. None are expected, because the tests are appended. Any other difference means STOP and return to Review. No census.

## Turn sequence

1. CB-196: compile only.
2. TB-EXEC-175.
3. TB-REV-175: freeze CB-197a (path-builder extract, same products). Decide whether a per-fixture selection receipt is needed.
4. CB-197a, then TB.
5. TB-REV, then CB-197b (selection, remap and arrival-port ownership, with a fail-closed missing path), then TB.
6. CB-198 (port-set readers and the region-owns-face assertion), then TB. Mechanical controls green; row 652 has 2 regions.
7. Row 979, Branch A, CB-190.

## Lessons

- When a removal follows a decision, ask what the removed object's identity already determines (here, the arrival port = `Y.port`) before receipting geometry.
- Before removing a record after the stage that wrote references to it, list every field that names it (here, `struckTrace` and event incidences).
