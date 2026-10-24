# M6-DEFN-R5-R2 — CP3 Entry Recovery Definition Amendment (RA-34 candidate)

**Turn:** `M6-DEFN-R5-R2`, runtime-free Definition. **Predecessor:** independent `M6-DEFN-R5-R1-REV` rejected RA-33 as written; see its review addendum. **Status:** candidate only, not accepted implementation authority.

**Verified exact-source inspection:** SHA `f3ae67ade2ac37f00d2317d0de007aaf959f8969`, source-snapshot workflow `37717936915`, artifact `11524367318`, ZIP SHA-256 `ea7668b79705f0fa489b7b6f21a05d09b02a43b9b0545bfc900544396de7901d`. No source, test, fixture, selector, build or generated Directional runtime was modified or executed.

## Scope

Amend only RA-33.1 (D1, certified OrdinaryFront) and RA-33.3 (D3, HardRail cross-rail transport). RA-33.2 (D2 organic periodic odd-gauge), RA-33.4 (D4 real traced seam-collinear relation / D7) and RA-33.5 (D5 genuinely route-bearing ordinary carrier) remain unchanged, with no fabricated produced positives. Accepted routing authority remains RA-32. The sole `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md` remains **HELD** pending independent `M6-DEFN-R5-R2-REV`.

## D1 — bind certificate and all seam checks to one typed orientation (RA-34.1)

**Observed source contradiction.** In `src/pipeline/RemeshPipeline.cpp:4520-4551`, the `seam_transport_certificate` helper rejects lookup when the two spans' global `interiorBinding.sheet` labels compare equal, then evaluates both forward/reverse face-sheet matches but returns only a certificate on `(forward || reverse)`. At `:5400-5403`, a shared collinear source edge plus differing raw sheet labels can grant the special seam branch without the certificate. At `:5445-5505`, branch validation independently selects certificate orientation. Thus raw sheet labels both wrongly grant and deny admission, and different conjuncts can use different certificate orientations. Review finding: `M6-DEFN-R5-R1-REV-OBS-01`.

**Normative candidate:**

1. Recognize a candidate from **real reciprocal collinear side spans** with the same topology region, canonical source edge, and precise A4-published face/side incidence. Look up the A4-owned certified isolation-seam transport without comparing the raw/global endpoint sheet-label IDs. Neither equality nor inequality of those IDs grants, denies, or bypasses lookup.
2. The certificate's `firstSheet()/secondSheet()` must themselves describe **distinct** typed endpoint sheet authorities. Establish their ordered connection to the selected source faces through **independent A4-owned wedge/sheet-incidence or isolation-transition evidence**, not by assuming the raw labels are comparable or by inferring sheet identity from component, proximity, or the relation under examination. If A4 does not actually publish enough evidence, stop fail-closed and seek a producer-owned A4 contract amendment through independent Review. Do not manufacture an A6 mapping.
3. Return one *oriented* matched object `(certificate, Forward|Reverse)` (or a mechanically equivalent type) after checking source edge, endpoint faces, ordered certificate sheets and reciprocal side incidence. Reject missing, ambiguous, contradictory, duplicate or nonreciprocal matches with an owning typed error.
4. Use **that same orientation** for source-face transitions, endpoint/corner wedge sheets, coordinate transition, phase, scale, branch quarter-turn, and both reciprocal isolation-side checks. The reverse orientation must use `certificate.reverse()` consistently. A mismatch of face orientation and branch orientation is never rescued by selecting an independent opposite orientation for another conjunct.
5. Only a fully certified, same-orientation relation may enter the special cross-seam branch and waive the ordinary full representation-equality rule. Partial or contradictory purported seam evidence must fail closed rather than silently degrade to ordinary matching. A genuine non-seam OrdinaryFront preserves full source-chart, branch, phase, scale and sheet equality. A7 separately verifies its own disjoint-wedge-sheet obligations and cannot be presumed green from A6.

**Required falsifiers (later Code+Build / separately authorized immutable TB; not executed here):**

- A true tracer-produced reciprocal seam-collinear OrdinaryFront with an A4 certificate, A4 typed wedge-to-certificate sheet witness, correct bound orientation and independent A7 positive. Without that production, the positive remains unproven and the gate is RED.
- A mixed-orientation negative: certificate forward quarter-turn 1, reverse 3, relation faces/sheets match only Reverse, but branch strip is forward 1. Must reject (expected reverse 3). Tamper one selected face, reciprocal side transition, branch turn, coordinate, phase or scale at a time while preserving the other independent receipts.
- Unequal raw/global sheet labels and no certificate must **not** grant special matching. Equal labels must **not** suppress lookup; positive admission additionally requires A4's typed cross-sheet evidence. Noncollinear relations remain strict ordinary relations despite unequal labels.
- Reverse face order, source row order and scheduler permutations must preserve a deterministic typed orientation and verdict. Non-vacuity must be checked before downstream certificate assertions.

This is a Definition only. If the current immutable A4 product cannot supply the oriented sheet-incidence proof, the implementation must stop for Review rather than introduce an unsupported recovery heuristic.

## D3 — odd oriented τ discriminator for HardRail (RA-34.3)

**Retained source basis.** `src/authority/FieldTransportAtlas.cpp:2020-2047` stores `FieldTransportTransitionValue` before marking hard rail edges nontraversable. The exact A3 `transition_value` is oriented by source edge and ordered incident face pair. A4 must publish independently verified oriented `(sourceEdge,fromFace,toFace,matching)` entries as immutable product authority; A5 consumes them. Regional face gauges `F_a,F_b` are independent provenance, not a substitute for crossing transport `τ_ab`. For rail-vertex continuation, compose all admissible source-chart routes; disagreement, singularity or nonzero holonomy is a typed failure, not permission to take a mean/shortest route. Review finding: `M6-DEFN-R5-R1-REV-OBS-02`.

**Normative candidate:** For an actually produced reciprocal HardRail relation between oriented endpoint faces `f_a → f_b`, require

```text
(B_b - B_a - R_coord - τ_ab) mod 4 = 0
τ_ba = (-τ_ab) mod 4
```

and independent reversed-relation validation with inverse coordinate, branch and τ orientations. The produced, baseline-green witness must satisfy **both** `(F_b-F_a) mod 4 != τ_ab` and `τ_ab ∈ {1,3}`. `τ=0` or `τ=2` is self-inverse in Z4, so cannot test the orientation/sign of crossing τ.

**Algebraic counterexample, NOT produced evidence:** `F_a=0, F_b=3, τ_ab=1, τ_ba=3, R_coord=1, B_a=0, B_b=2`. Forward: `B_b-B_a = 2 = R_coord+τ_ab (mod 4)`. Substituting regional F yields `(B_b-F_b)-(B_a-F_a)=3 != R_coord=1`, and reversing τ while retaining coordinate orientation yields `R_coord+τ_ba=0 != 2`. The actual inverse relation has `B_a-B_b=2`, inverse coordinate 3, inverse τ 3, and `3+3=2 (mod 4)`. These calculations show discrimination **algebraically only**, not real-producer reachability.

**Produced-witness protocol (implementation/TB, not this Definition):** Extend the existing real nonconstant two-region HardRail fixture in `tests/SurfaceCellTransitionQuotientTests.cpp:684-749`. Deterministically bound a finite family of rail edges, raw-field quarter turns, face-root choices and face-row permutations. Run the real A1/A3→A4→A5 producer chain. Enumerate all actual reciprocal HardRail relations and select by stable source-edge/relation key only **after** verifying published endpoint gauges, exact oriented A3/A4 τ authority, the F/τ inequality, odd τ, baseline A5 coordinate and reciprocal validation and any required real A7 receipt. Record `sourceEdge, fromFace, toFace, relationId, F_a, F_b, τ_ab, τ_ba, R_coord, B_a, B_b`. Tamper only τ orientation/sign with the rest green; separately invert or permute source face order and require canonical results. If the bounded family produces no odd τ plus independent F/τ inequality, stop for independent Review; do not fabricate relation objects, weaken to self-inverse τ, or claim the gate passed.

**Algebraic limit:** Z4 is abelian. An equality cannot prove whether `R_coord` was composed before or after τ. Right-to-left composition order remains a *typed semantic convention*; numeric falsifiers prove signs, inversion and source-oriented domain only. Do not claim that a passing test proved composition order.

## Carried obligations and release gate

- RA-33.2: organic exact-A3 nonzero-period torus pair with a 90°/270° face-gauge difference; no produced positive yet.
- RA-33.4: actual tracer-produced seam-collinear OrdinaryFront with independent certificate and D7 disjoint endpoint wedge-sheet validation; no produced positive yet.
- RA-33.5: actual source-route-bearing OrdinaryFront carrier and protected-barrier negatives; no produced positive yet.
- Frozen exact entry gate **497 = focused30 30 + focused12 12 + selector449 449 + CP3-entry 6**; latest rejected candidate **482/497**. Stable accounting **63 events / 17 categories / 46 recurrences**; one M6 produced-witness debt. Reviewed CP2 package **11391685901**, source **5ce3132ec01748eff5b15f82be07a1abe2bd1af6**, 491/491.
- Next authorized turn: **independent runtime-free `M6-DEFN-R5-R2-REV`**, to accept/amend/reject RA-34 and independently verify whether A4's typed sheet incidence is sufficient. This Definition never releases R2 Code+Build or CB2. The held plan remains held until explicit Review approval; missing real-producer authority is a stop, not accepted evidence.
