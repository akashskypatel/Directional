# M3-CP4c-0-TB-R4 — Independent Review and Corrective Planning Brief

Turn: **`M3-CP4c-0-TB-R4-REVIEW-PLAN`**. Review/planning only.

## Turn boundary

Interpret the immutable TB-R4 evidence and source only. **Do not execute Directional runtime, configure, compile, benchmark, repair, mutate product/test/fixture/selector/build logic, or consume Q8 again.** No Code + Build turn is authorized until this review independently classifies the concrete sphere rejection and freezes any corrective measures.

## Evidence authority

- CB4 semantic source: `de291a17d5e9bfb6f54918660320ecfa1d521be4`
- CB4 package: `9591540182`, ZIP SHA-256 `8a93b553df337bc8ad952e6a5b348a3eaac8b2304b50c1402f5184a8ce4c561f`
- embedded source archive SHA-256: `6077902a83b88d1ef839ab6d2bc285050f0c059511a71c9125b0324383d69a32`
- TB-R4 event/control SHA: `bb21207f288c631b1d4149b56b37e78080edade7`
- authoritative run/job: `32928381384 / 98055727654`
- result artifact: `9592385698`, SHA-256 `6ffe56ef5a86bf44dfd2ea4e2f44514d71b6037cc5c34067aeda571a70260643`
- diagnostic artifact: `9592386266`, SHA-256 `669e51f2d0c30573c751c43a4d49b737f8a4ddeba8be2236f9782c995f6ac3cb`
- frozen selector: 338 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`; first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.

Semantic facts to independently verify: gate **338/338 PASS**, accepted **316/316**, prior CP4c-0 **328/328**, F3 **2/2**, G5 PASS/non-gating, Q8 creditable/RED, 341 fresh processes, post-runtime immutability, and the later `first_red` reporting-shell failure.

## Exact G5 datum to adjudicate

```text
networkError=BranchTransportFlowDisagreement
sourceEdge=6-8
sourceFace=6-8-9
relatedSourceFace=6-8-97
branch=3
relatedBranch=1
exactValues=[-18030322293639185/4503599627370496,704682678286465/140737488355328,-4519523411527695/4503599627370496,-7261349426533623/2251799813685248,8560629902387487/2251799813685248,-162410059481733/281474976710656]
traceSeedVertex=0
traceSeedSingularity=0
```

The immutable source localizes the emitter to `src/geometry/SurfaceCellTracing.cpp:644-671`, `validate_field_branch_transport_flow`. It returns the error when carrier `6-8` belongs to the source pairing's `outgoingCarriers` but not the transported target pairing's `incomingCarriers`.

## Required review questions

### R1 — evidence classification before semantics

Re-hash immutable artifacts and inspect ledgers/inventories. Confirm 338/338, F3 2/2, G5, Q8 red, and post-runtime immutability are independently recoverable without `result.json`. Confirm the `first_red` name mismatch occurs only after valid semantic and integrity evidence exists. If any claim fails verification, stop and classify the control/evidence issue first.

### R2 — reconstruct exact edge-6-8 transport authority

From packaged source/fixture authority, reconstruct both `FieldBranchBoundaryPairing` objects and the `FieldBranchTransportAdjacency` used to move branch `3` on face `6-8-9` to branch `1` on face `6-8-97`. Account explicitly for per-face gauge and published `signedLift` under Amendment 7; do not compare bare numeric labels across faces. Determine from authority why carrier `6-8` is source-outgoing but not target-incoming, including the exact source/target direction signs or intervals that drive both classifications.

### R3 — adjudicate the mismatch category

Choose only what evidence supports: production semantic defect; authority-contract mismatch; fixture/admissibility issue; diagnostic/orientation false positive; or another precisely evidenced category. Do not prescribe a correction until the owning authority and invariant are identified. The frozen unit identity for `BranchTransportFlowDisagreement` proves the error family is intentional diagnostic behavior, not that this sphere rejection is correct or incorrect.

### R4 — relation to prior exactification

TB-R4 proves G1–G4/G6 test-side corrections green and identity 338 remains green, so the prior `BranchContinuationDegenerateEntry` / outside-outflow family is absent. Determine whether the new disagreement is a downstream condition newly exposed by E2–E5, an invariant E2–E5 should have guaranteed, or unrelated. Do not label recurrence without causal proof.

### R5 — Q8 and successor scope

Q8 criterion 2 is the binding red: the sphere has no network, so 24 traces and terminal-intersection evidence cannot exist. Freeze the minimum successor measure(s) required to settle or correct this rejection. Do not weaken the sphere fixture, T6, Q8, accepted 316 expectations, selector ordering, or Amendment 7. Do not enter CP4c-1/2/3 scope.

### R6 — control-plane correction, no semantic rerun

Record the postflight variable mismatch separately. A successor workflow may correct `first_red`/`first_red_ordinal` naming, but **must not rerun TB-R4 semantics merely to obtain a green workflow badge**.

## Regression-accounting guard

`M3-CP4c0-TB-R4-CAND-01` is **ACTIVE / NON-STABLE / PENDING INDEPENDENT REVIEW**. Accepted 316/316 remains green and CP4c-0 has never been accepted, so current stable totals stay **42 events / 14 categories / 28 recurrences**, debt **5**. `M3-CP4c0-TB-R4-CAND-02` is resolved orchestration/control and must not be conflated with Q8.

## Required review output

Produce `.agents/Directional/Architecture_M3_CP4c0_TB_R4_Review_Plan_Independent_Review.md` that independently verifies authority/control classification, answers R2–R4 from primary evidence, adjudicates candidate 01 without assuming production fault, freezes falsifiable successor measures/predictions if warranted, records stable accounting, and names exactly one next turn under `CB → TB → red → REVIEW + PLAN → CB`.

No runtime/build/test/fixture/selector/product mutation belongs in the review turn.
