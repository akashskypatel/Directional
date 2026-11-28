# M6-CP3-DEFN-P13-A2A-PARTIAL-COTRACE-REMOVAL — A2a partial co-trace removal (2026-11-27 UTC)

## Situation

This turn decides AP4: how A2a removes a port's trace when another trace's singularity arrival already realizes the same separatrix (O51).
- The rule is now DESIGN §7.2.1 **Amendment 35**: step 7 deletes the trace, with typed fail-closed conditions.
- It is staged behind an option that defaults off, measured by a witness, and activated by a later switch.
- Two compile-only CBs are frozen as exact diffs, together with the TB-EXEC-193 contract.
- Runtime-free; no build or test was run.

## PC1 — Decision: A0 deletion (Amendment 35)

- **Who decided.** The user was asked to choose between A0 (delete, typed fail-closed), A (suppress the claimed port and re-trace to a fixed point), or no rule. The answer was "Decide what fits best with the intended design". The decision below is taken against DESIGN on that instruction.
- **Why A0:**
  - §7.2 step 7 is a selection ("globally select and simplify"), and invariant 8 permits removing redundant traces.
  - D13's step-7 selection is already placed inside the canonical derivation without touching the tracing loop (TB-REV-173 E2).
  - Re-tracing would loop step 7 back into steps 3–5, which DESIGN does not describe.
  - Contacts are resolved by arc-length arrival (`field_aligned_contact_termination_decision`), so re-tracing is not monotone (TB-REV-192 adv. EE3), and §10.1 needs an order-independent result.
  - §5.2 gives A2a no degraded mode, so every case the deletion cannot handle is a typed failure, never a repair.
- **What the evidence settles** (TB-REV-192 adv.):
  - The claims are one-sided (EE2), so invariant 1 decides which trace goes.
  - No kept sphere trace stops on a claimed trace (EE3), so on the sphere deletion equals the fixed point: 14 traces, V12/E18/F8.
- **Not covered:** O52 (slivers 2/4, near-miss doubles). Removing either trace there would alter port topology. It goes to the corners DEFN.

## PC2 — Staging: why the rule ships off by default

- The TB192 gate logs show the identical sphere network (the same 10 radial-edge arrivals) in **27 gated rows**: 380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858, 963, 968, 971, 972, 978, 979 and 1006. That covers 12 of the 13 named controls.
- Switching the rule on by default would change every one of them. Per the TB-REV-182/184 adv. lessons, the reach of a default flip is every gated path, so the flip is its own change, made only after a measured witness.
- Face-interior arrivals cannot be seen in the logs, so this census is a lower bound. With the default off, the gate measures that bound directly: all 1010 inherited rows must stay N1–N3-equal.

## PC3 — CB-217 unique arrival classification (A2a, compile only, behaviour-neutral)

EE5 found three defects in the CB-216 classifier: it takes the first match, an unmatched arrival fails silently, and it is network-level only. CB-217:
- moves classification into one implementation that both the network and a pre-publication candidate can use;
- accepts a port only when exactly one slot matches;
- distinguishes no match from several matches as typed outcomes.

Requiring a unique slot also settles EE5(b), the branch check. A trace can only slide into `s` along a radial edge if its reverse branch's class straddles that edge, or if an edge-supported port lies on it. So when exactly one slot touches the edge, it is that trace's separatrix.

CB-217 adds no production caller.
- Exact diff, hashes and new tests: §PC6.

## PC4 — CB-218 claimed co-trace deletion (A2a, compile only, option off)

CB-218 implements Amendment 35 after `field_aligned_select_retraced_traces`, active only when a new canonical-derivation option is true. The option is threaded like `stopAtLaterSlideEntry` and defaults to false.

With the option on:
1. Read every claim from the traced candidate. A claim is an arrival whose unique port still has its own trace and whose `arrivalPort` is unset.
2. Delete the claimed traces and their event incidences, then delete any events and nodes left unreferenced.
3. Re-index node ids densely.
4. Set `arrivalPort` on each arriving trace.
5. Return a typed failure on:
   - an unmatched or ambiguous arrival at a singularity that publishes ports;
   - two claims on one port;
   - a claimed trace that is itself an arrival;
   - a kept trace whose terminal contact strikes a deleted trace.

The witness test asserts EE3 exactly on the prescribed sphere and asserts that the option-off build is unchanged.
- Exact diff, hashes and new tests: §PC6.

## PC5 — TB-EXEC-193 contract and predictions

- **Gate:** the 1010 inherited rows plus the new guard rows from §PC6, using the [exact manifest](gates/Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Exact_Manifest.md).
- **Inherited rows:** all 1010, row858 included, must be N1–N3-equal to TB192 `15195820651`. The default is off, and CB-217 keeps the public classifier's output wherever the match is unique. Any difference is STOP for review.
- **New rows** must PASS. The witness is decisive:
  - its failure falsifies EE3 or Amendment 35's sphere evidence;
  - record that failure, do not adapt it.

## PC6 — Frozen diffs

Exact identities and the TB-EXEC-193 contract are in the [exact manifest](gates/Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Exact_Manifest.md).

| CB | Diff | SHA-256 | Size | New gate rows |
|---|---|---|---|---|
| CB-217 | [`…CB217_P13_Unique_Arrival_Classification_Exact.diff`](Architecture_M6_CP3_CB217_P13_Unique_Arrival_Classification_Exact.diff) | `d3d3102e85a372d5b5cf4e999fef6caf0852efb3581336f4ba922f566626aff8` | 15,476 B, +190/−31 | 1011 `CandidateArrivalClassificationRequiresExactlyOnePortSlot` |
| CB-218 | [`…CB218_P13_Claimed_CoTrace_Deletion_Exact.diff`](Architecture_M6_CP3_CB218_P13_Claimed_CoTrace_Deletion_Exact.diff), on CB-217 | `b0be915a4fd5f967a96e354fb6fa2fb78eaba6849028b12014eb50bae98cfab5` | 32,417 B, +498/−12 | 1012 `PrescribedSphereClaimedCoTraceDeletionKeepsOneTracePerSeparatrix`, 1013 `…RejectsInadmissibleClaims` |

The 1013-row manifest is `b910f2a9…1d2fc2`. Its header plus rows 1–1010 equal TB192's `c9f6325e…e9f5`.

- **Authoring.** A sub-agent wrote both diffs to PC3/PC4. I reviewed the deletion against Amendment 35:
  - claims are read before any change;
  - all four rejection conditions are present, plus the ambiguous-match split;
  - a rejection leaves the candidate unchanged;
  - events keep only the incidences they require, and a dropped event that still has a kept terminal is rejected;
  - nodes are re-indexed in id order across nodes, ports, mandatory edges and events. Traces hold no node ids.
- **Verification.** An independent Haiku pass found:
  - both diffs apply and reverse exactly, and every hash matches;
  - `-fsyntax-only` (not compile evidence) gives 0 errors and identical location-stripped warning multisets before and after (40/42/24);
  - no plan identifier appears in the added code.
- **Carried risks:**
  - The uniqueness of the sphere and mechanical matches is inferred from partition records, not run (TB-EXEC-193 measures it).
  - With the option on, no `src/` reader outside `SurfaceCellTracing` reads `arrivalPort`. This must be censused at the switch DEFN.
  - The witness passes `stopAtLaterSlideEntry=true` explicitly, as production does.

## PC7 — Turn sequence

| Step | Turn | Boundary |
|---|---|---|
| 1 | `M6-CP3-CB-217-P13-UNIQUE-ARRIVAL-CLASSIFICATION` | Apply one exact diff; compile eight GMP/GMPXX targets; `runtimeExecution=false`. |
| 2 | `M6-CP3-CB-218-P13-CLAIMED-COTRACE-DELETION` | Exact diff on CB-217; compile only. |
| 3 | `M6-CP3-TB-EXEC-193` | Full gate per §PC5. |
| 4 | `M6-CP3-TB-REV-193` | Independent review; runtime-free. |
| 5 | `M6-CP3-DEFN-P13-A2A-COTRACE-DELETION-SWITCH` | Census of the 27 rows' premises; freeze the default flip and the re-derived expectations from the measured witness. |
| 6 | `M6-CP3-DEFN-P13-A4-DISC-CORNERS` + O52 | After the switch. |

## Closeout

| Duty | Answer |
|---|---|
| User decision | Delegated to the design; A0 recorded in Amendment 35 with the rationale above. |
| Prior obligations | AP4 decided; TB-REV-192 falsifiers mapped to Amendment 35 failure conditions; AP5/A4D5 and DD5 carried; O52 opened. |
| Boundary | Runtime-free; DESIGN amendment and frozen diffs only; no product/test/selector change applied. |
