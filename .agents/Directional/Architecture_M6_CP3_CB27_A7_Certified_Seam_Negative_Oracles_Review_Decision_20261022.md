# CB27-REV — independent A7 certified-seam negative-oracle review (2026-10-22)

**Canonical turn:** `M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES-REV`.

**Decision: REJECT full CB27 negative-oracle adequacy.** Three negatives are discriminating under static source reasoning, but the outside-wedge negative can pass with the exact wedge-membership requirement removed. This is a test-oracle defect, **not** evidence of a production-code regression. Runtime execution is deferred to an authorized TB turn; none occurred in this Review. Same-side omission is conditionally justified for the present D7 producer witness.

## Exact evidence and independent derivation

- Exact reviewed semantic source: `175c70e44d2c162d72812c842149f30c53c1fa25`; CB27 changed only `tests/SurfaceCellTransitionQuotientTests.cpp` relative to its pre-CB27 semantic source; neither selector nor product/fixture/build code was changed by CB27.
- Compile run [39815137854](https://github.com/akashskypatel/Directional/actions/runs/39815137854): compile job successful, test/benchmark skipped. Artifact `12443015113`, externally reported and independently recomputed SHA-256 `b1e7cfedc8546c8559592bb8aa6c902c00a47a488d441510ebfd89403172b0de`. Package file manifest **28/28** verified; source archive SHA-256 `ed7ef40b3298333beda991c521bf601b4f2a79fb529cf69e28603f6d7d01a6c8`; packaged source identity matches. Preflight/build exit codes zero, eight targets recorded, GMPXX/GMP verified in linker evidence; `runtimeExecution=false` and clean package source status. These attest **compilation only**.
- Original A6 selected forest is saved and reused for A7 invocation in TQ `check_d7_certified_seam_negative` (TQ:4065–4154). The unaltered producer-positive A5/A6/A7 witness must first succeed; a tampered A5 is independently republished and A6's expected outcome is asserted, then A7 receives tampered A5 with original A6. This correctly distinguishes A6's earlier guards from the A7 decision *if* the tamper isolates that decision.
- **Unrelated-seam** (TQ:4156–4194): retains at least one sheet-set connecting transition while changing all relation evidence transitions away from `certificate.seam()`. The A7 check at RP:7602–7618 requires the certificate's exact seam. A weakened any-connecting-transition check would accept. Statics support non-vacuity, not runtime reachability.
- **No-certificate** (TQ:4196–4238): removes certificate and three relation transition lists, independently requires A6 rejection and demands `cross-sheet:no-certificate` in A7 (RP:7622–7649). Statics support non-vacuity, not runtime reachability.
- **Lattice-coordinate** (TQ:4240–4264): ensures identical endpoint support, selected face and coordinate before mutation, then changes only `latticeCoordinate.x`. Shared-node identity at RP:3878–3884 requires all three equal; the A7 direction at RP:7587–7594 then rejects. Statics support the intended guard, but only TB can establish no earlier rejection masks it.
- **Outside-wedge — NOT A VALID WEDGE-MEMBERSHIP ORACLE** (TQ:4266–4286): copies `secondEndpointSpan->interiorBinding` *as a whole* into the first span. The first binding then equals the second binding. The preconditions establish that the substitute belongs to a certificate face but not to the first wedge; they do **not** preserve opposite seam sides. RP:3855–3875 checks membership, while RP:3912–3925 independently demands opposite `CertifiedSeamSide` values. **Deleting the `std::find(occurrence.cornerWedgeBindings, binding)` membership check still leaves both sides equal and the function returning `nullopt`, so A7 still returns `cross-sheet:seam-direction`.** The test cannot distinguish a correct wedge guard from a weakened one. A superficial expected-code/site match must not be called verification.
- **Same-side omission:** D7 has disjoint endpoint wedge-sheet sets and a certificate with distinct first/second sheets; putting both ends on one certificate side while preserving both wedge memberships is not realizable with the D7 witness. The side-opposition branch already rejects it. Omitting a contrived same-side test is warranted for this witness; the distinct outside-wedge guard remains unproved.

## Bounded successor — `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION`

**Type:** Code + Build, **test-only**. Owner: `tests/SurfaceCellTransitionQuotientTests.cpp` only; leave production code, other tests, selectors, benchmark fixtures, CI workflows and existing D3/D7 controls unchanged. **Stop** instead of widening scope if the following mutation cannot be produced from a valid source-produced D7 witness.

1. Correct the outside-wedge mutation to preserve first-span certificate face **and sheet**, the opposite-side relation to the untouched second span, and every non-membership precondition; change only the binding identity excluded from the first occurrence's `cornerWedgeBindings`. Do not assume a synthetic chart or malformed source binding is A5-publishable.
2. Assert (a) original/substituted side are identical, (b) side-opposition still holds, (c) substitute is absent from the first wedge and present on a certificate side, (d) republished A5 is structurally valid, and (e) A7 with original A6 rejects specifically due to the tested membership condition. Provide independently checkable counterfactual evidence that **removing just membership** would make the constructed tamper admissible, without modifying production code or weakening tests. If the witness cannot isolate this condition, record a precise unfulfilled oracle obligation and request a new witnessed design in a separate authorized definition turn; do not fake coverage.
3. Preserve the unrelated-seam, no-certificate and lattice negatives unchanged. Compile all eight established targets with GMP/GMPXX using the durable compile workflow; `runtimeExecution=false`. No runtime test/benchmark in CB.
4. Independent CB27A-REV must inspect source, non-vacuity and compiled artifact before CB28 is authorized. CB28 message-only diagnostics and TB29 remain **conditional, not current**.

**Falsifiers:** an unchanged pass under removal of the membership condition; same-side/sheet mismatch independent of wedge membership; republished A5 rejected before A7; A7 rejection from an unrelated earlier guard; compiler or GMP/GMPXX failure; edits to unapproved paths or changing test assertions to obtain green. **STOP**, preserve evidence, and do not promote to CB28 or TB29.

## Project accounting and carried obligations

Stable: **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, accepted CP2 **491/491**; frozen CP3 selector 497, TB28 **462/497 candidate only**, not promoted. `RP-01` OPEN, `RP-02` UNREACHED, Gate C suspended. RA-134.4 three additional preconditions are statically present. RA-132.6 periodic negative is still deferred under RA-130.7 pending a valid source-produced periodic witness. RA-134.5 CB28 and TB29 stay queued behind corrected independent oracle review. This review creates no new stable regression event. Existing A7 coverage defect is an unpromoted test-authority obligation.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — CB27 Review adds/accepts no selector; frozen 497 and accepted CP2 491/491 retained; source-side selector files unchanged by CB27 |
| Decisive claims independently re-derived | Exact packaged SHA-256, 28/28 manifest, source/build boundary and actual TQ/RP predicate/control-flow inspection; the membership-deletion counterexample proved statically |
| Non-vacuity checked | Three guarded negatives have targeted static discrimination; outside-wedge case **fails** due to independent same-side rejection |
| Prior obligations discharged/carried | RA-134.4 three preconditions present; RA-132.6 four negatives still require adequate fourth witness; same-side omission justified for D7 only; RA-130.7 periodic witness carried; RA-134.5 CB28 pending |
| Stable accounting | 66/17/49, debt 1, CP2 491/491 accepted, TB28 462/497 candidate, frozen selector 497 |
| New candidates/obligations recorded | CB27A wedge-membership negative repair; no stable production regression |
| ORIENTATION currency line | Updated to CB27-REV and CB27A as next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 adjusted; §4 unchanged (no witness changes); §8 existing vacuous-oracle pattern applies |
| CHANGELOG | Review rejection and successor recorded |
| ROADMAP | No checkpoint status change; no update required |
| Selector manifest | n/a — no selector mutation or acceptance |
| LESSONS | Existing independent non-vacuity / vacuous witness lesson applies; no novel lesson |
| Consolidation under CLEAN_UP_POLICY | No historical document folded without complete retained index; exact compile report and TB28 evidence remain current authority |
| Successor frozen | `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION`; above falsifiers and STOP rules |
| Turn boundary held | Review-only; no runtime, product/test/fixture/selector/build mutation |
| review_check.py boundary | Git metadata absent from packaged archive, so full Git-based command cannot be honestly certified; exact package, GitHub branch comparison and changed-path evidence used as bounded alternative |
| `STATUS` lifecycle maintained | Final beacon published separately as last repository action |
| Pushed to origin, branch in sync | Verify after documentation patch application against GitHub head; local archive has no .git, so `git status -sb` cannot be truthfully claimed |
