# M5-CP3-TB1-R9 Independent Review Record

**Turn:** `M5-CP3-TB1-R9-REV`
**Boundary:** **runtime-free independent Review**
**Verdict:** **R9 EVIDENCE UPHELD / CB10 WITNESS RECOVERY PROVED / NONZERO-Z4 SAME-REGION PAIRING CONTRACT INCONSISTENCY PROVED / R7-CAND-02 CLOSED / CB11 PRODUCT CORRECTION FROZEN**
**Exact successor:** `M5-CP3-CB11`

## 1. Independent authority and evidence re-opened

Review selected `READ_MODE=snapshot` before any repository source/document inspection beyond the mandatory root `STATUS` beacon. The review source snapshot run/job/artifact is `35683148294 / 106604294049 / 10676515060`; the downloaded snapshot ZIP hashes to `b2a756ea6d3b2636b6840ce7ead99efb8d06cab634900b027c669ce3946753fd`, its internal `source.tar.gz` hashes to `1353743fc295fcecd0feed01689ad5a4cc3002b722a1fef091673d3e952c9f6f`, snapshot/event SHA is `74358463bd5182b17ccc5f6bb13e2b5653ab00b8`, and `runtimeExecution=false`.

R9 consumed CB10 candidate artifact `10668437359` from exact packaged semantic source `9040f74a8de0849920973fd985b19db2539812ee`. Candidate ZIP SHA-256 is `c5deac0871004fbf9e7f318a124d599c7548641be2083419a0f465b503ff3206`; root `SHA256SUMS` remains **28/28** at `75b0241e3f5c340cd7d5e2369aa3ea632c98a56abc57fc342f656b59c436dee3`; packaged source archive SHA-256 is `3de9286684ff550b7377e9a7d383fe1640c2c9ec38910861c4a09f86a9f3c5b3`.

R9 runtime authority is run/job `35681652858 / 106599730829`, event SHA `6014e3eef038778fd66c3c38ca4b62968b74c801`. Result/log artifacts are `10675249976 / 10675328734`; independent downloads hash to `1f91df87d08ef2375caa463da12e7d8473e48afbf6163daab1fa18c923713e31 / 21deb021992fcfd2e9e631a37bcf1c47860eca3eaa10fa4d335db5e36043bb0c`. Review independently re-ran the recursive result manifest check: **912/912** entries verify, and `SHA256SUMS` itself hashes to `62269fc2b7f60f3195bbba6804c69ba991dd8c2b3dfba059277fc9a10915d975`.

The accepted routing/selector authority remains unchanged: routing artifact `10592987234` at SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, and first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

A byte comparison of `src`, `include`, `tests`, `benchmarks`, `cmake`, and root `CMakeLists.txt` between the exact candidate packaged source and the Review snapshot found **zero changed, zero missing and zero extra semantic/code paths**. In particular `tests/SurfaceCellTransitionQuotientTests.cpp` is byte-identical at SHA-256 `cc2111739205437f84ed748db32adcedd45a1bdd3b2644bb5df152913a6ed954`. Static Review findings therefore apply to the exact candidate executed by R9.

## 2. R9 mechanical evidence independently upheld

Review independently parsed all four ledgers and re-hashed every referenced raw process log. The independently upheld vector is:

| Gate | PASS | RED | Selection integrity |
|---|---:|---:|---|
| reviewed mechanism | **9/9** | 0 | 9 exact-one / 0 skipped |
| focused retained-value atlas | **1/1** | 0 | 1 exact-one / 0 skipped |
| CP3 produced | **4/6** | 2 — ordinals 4/5 | 6 exact-one / 0 skipped |
| selector430 | **430/430** | 0 | 430 exact-one / 0 skipped |
| **total** | **444/446** | **2** | **446 exact-one / 0 skipped** |

Benchmark execution is exactly **0**. Produced rows 1–3 remain PASS and preserve the two production debts already discharged at R7 Review. Produced row6 remains PASS on its recovery-proved independently absent/unowned/unselected relation witness. Protected selector ordinals **191 / 192 / 247 / 408** remain PASS.

Rows4/5 raw logs independently reproduce the exact exception `torus nonzero-Z4 source witness producer failed: PeriodicActionCorrespondenceMismatch`. Their raw SHA-256 values are respectively `e0119c26ff0f56cd79b1b67ba934e9981b648b7db76c0dc183e001d175a8eb16` and `ca229c60f411375b37b45adb11b5a36debe927bb33b8bc196f72ac4ab0b78535`. Row6 PASS raw SHA-256 is `194881948eef02381804b6806fcbbac4ebfdfdf9743daaceb1123a5ca28bc18b`.

Immutable postflight is independently upheld: package/source/execution-view censuses are byte-identical before/after at `25f32795d681dfd14f288ed8ddf3aefc46c93c7825e661e6ec23d8333242d470 / 913c28cbfed08d55863b6f9005b104a2f3f8a48be97be6465f8a4afa9e3beeed / 5b3e0549d52d3fd4bb1ba5b73c175ee87a965663e9301e0204ac33325bdb1ff0`; candidate root manifest remains **28/28**; selector/routing authority is unchanged; and configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters are all **0**.

## 3. CB10 no-tuning and chart-admissibility precommitment is independently upheld

`M5-CP3-TB1-R8-REV-OBS-01` is now independently decidable rather than inferred from R9 merely reaching a later failure.

Exact candidate source contains the authored field law exactly as precommitted:

```text
theta = atan2(centroid.y, centroid.x), normalized into [0, 2*pi)
delta(theta) = (pi - theta) / 6
x = cos(delta) * majorTangent + sin(delta) * minorTangent
y = -sin(delta) * majorTangent + cos(delta) * minorTangent
raw = [x, y, -x, -y]
```

The same divisor `6`, `pi` phase and normalization are independently re-derived again inside `validate_nonzero_z4_torus_chart_subject(...)`; no coefficient/phase search, candidate-angle loop or runtime-tuned fallback exists in the torus witness helper.

Review independently reimplemented the committed torus geometry, face tangent frames, piecewise-constant-face connection and `principal_matching` rule from exact source, then reconstructed the same hard-cut dual gauge and boundary classification without executing Directional. The exact committed `milestone-g/torus.obj` has 72 vertices / 216 edges / 144 faces and the frozen cut is exactly **18** unique hard edges:

- minor cycle `{0,3,25,37,49,61,0}`;
- major cycle `{0,1,4,6,8,10,12,14,16,18,20,22,0}`.

The independent reconstruction yields:

- all **144/144** faces connected in the non-hard cut-domain dual;
- **5** row408 hard carriers with nonzero finalized principal matching, all `+1 mod 4`, so the source subject is genuinely nonzero-Z4 before product inspection;
- minimum two-sided hard-boundary best-branch alignment **`0.7753279615208046 > 0.7`**;
- major forward/reverse global branches `0 / 2`, minor forward/reverse `1 / 3`;
- canonical runs exactly **`[0,1,2,3]`**;
- run lengths **`[13.355062727290072, 3.3000000000000007, 13.355062727290072, 3.3000000000000007]`**;
- signed quarter turns `[+1,+1,+1,+1]`, sum **`+4`**;
- orthogonal developed closure residual **`(0,0)`** in the oracle-equivalent repeated-length arithmetic, tolerance **`3.3310125454580146e-9`**.

The prior R8 static prediction's approximately `1.986e-15` closure residual and this exact repeated-length reconstruction are equivalent for the frozen bounded-closure predicate: both are overwhelmingly inside the same source-scale tolerance. R9 then dynamically advances beyond the chart oracle to `PeriodicActionCorrespondenceMismatch`, consistent with the independent static proof that every pre-product predicate is admissible.

**Disposition:** `M5-CP3-TB1-R8-REV-OBS-01` is **CLOSED / NO-TUNING PRECOMMITMENT UPHELD / CHART ADMISSIBILITY independently proved / NON-STABLE / +0**. The witness-authority defect tracked as `M5-CP3-TB1-R7-CAND-02 / RP-02 TEST_AUTHORITY_COVERAGE_GAP` is therefore **CLOSED / RECOVERY PROVED / NON-STABLE / +0**. The remaining RED is no longer attributable to that witness gap.

## 4. The nonzero-Z4 production contract is structurally self-inconsistent at same-region pairing

R9's dynamic frontier is `PeriodicActionCorrespondenceMismatch`. Review does **not** assume that the first failing runtime pair is a particular carrier or that its exact generator rotation was printed; R9 did not instrument that fact. Instead, exact source plus frozen definitions prove a stronger reachability defect: under the current same-region promotion rule, **no nonzero quarter-turn periodic relation can ever satisfy the required endpoint correspondence on a nondegenerate lattice edge**.

### 4.1 Exact current gates

Frozen §14.2 currently requires same-region promoted cut copies to have canonical-reverse routes, **matching `family` and opposing `advanceSign`**. Candidate source enforces the same raw condition before generator-route construction.

For every rectangular phase-front edge, implementation derives `family` and `advanceSign` directly from the exact unit lattice delta

```text
d1 = first.toLattice.latticeCoordinate - first.fromLattice.latticeCoordinate
```

where `d1` is one of `(+1,0)`, `(0,+1)`, `(-1,0)`, `(0,-1)`. Equal family plus opposite advance sign therefore requires the second directed edge delta to be

```text
d2 = second.toLattice.latticeCoordinate - second.fromLattice.latticeCoordinate = -d1.
```

Frozen §14.3 and `periodic_action_for_pair(...)` then require the authoritative generator rotation `R` to belong to one `GridAutomorphism` satisfying both reciprocal endpoint mappings:

```text
R(first.from) + t = second.to
R(first.to)   + t = second.from.
```

Subtracting eliminates translation and yields

```text
R(d1) = second.from - second.to = -d2 = d1.
```

A nonzero cardinal lattice vector is fixed by a quarter-turn only for `R = 0 mod 4`. Independent enumeration of all four cardinal deltas against all four Z4 rotations confirms the only satisfying rotation is identity in every case. Translation cannot change this conclusion.

Thus the existing raw family/sign condition and exact action correspondence jointly imply **zero Z4 rotation**. That contradicts frozen §8.2 debts 3/4 and §13.1's M5 exit theorem, both of which explicitly require a genuinely nonzero-Z4 produced relation, and it conflicts with §14.3's requirement that the relation action use the authoritative generator-route rotation.

### 4.2 Authority classification

The defect is not that exact action correspondence is too strict. That correspondence is the necessary quotient relation authority and must remain exact. The defect is comparing **untransported chart-local family/sign labels across a periodic seam before applying the seam's authoritative rotation**.

For a correct same-region periodic pair the exact invariant is

```text
R(d1) = -d2,
```

with `R` taken in the exact directed generator-route orientation. For `R=0`, this reduces to the old family-match/opposite-sign rule. For `R=1` or `R=3`, the paired local family necessarily rotates; for `R=2`, the sign relationship changes. Trying the inverse rotation as an alternative would destroy the still-open directed-source falsifier and is prohibited.

Cross-region HardRail pairing is a different semantic domain and keeps its existing local family/sign reciprocity rule unchanged.

**Disposition:** new candidate `M5-CP3-TB1-R9-REV-CAND-01` is **OPEN / IMPLEMENTATION + FROZEN-CONTRACT AUTHORITY / `RP-01 AUTHORITY_DOMAIN_CONFLATION` / UNTRANSPORTED LOCAL FAMILY-SIGN COMPARED ACROSS PERIODIC SEAM / NON-STABLE / +0 / OWNER CB11 -> R10 Review**.

The exact R9 `PeriodicActionCorrespondenceMismatch` is consistent with this structural impossibility, but Review does not claim the runtime log identifies which particular pair first hit it. The static impossibility is independently sufficient to prove that the current candidate cannot discharge either nonzero-Z4 production debt.

## 5. Frozen definition amendment — rotation-aware same-region periodic pairing

This Review adds frozen §16 to `Architecture_M5_Frozen_Definitions.md`. It amends only the family/sign portion of §14.2 for **same-region periodic promotion**:

1. exact reciprocal A3 interval identity, distinct boundary occurrences and canonical-reverse paired routes remain mandatory;
2. raw `family`/`advanceSign` equality/opposition may not be used as cross-seam authority before the generator rotation is known;
3. after the exact directed generator route produces rotation `R`, the exact lattice deltas must satisfy `rotate(R, d1) == -d2`, and the same `R` must satisfy both branch-rotation endpoint states and both integer endpoint mappings through one `GridAutomorphism`;
4. no inverse-direction fallback, best-of-two orientation search, relation-value tuning, floating path search or weakening of checked action correspondence is allowed;
5. cross-region HardRail pairing keeps the existing direct family-match/opposite-sign rule and remains HardRail.

This is a reconciliation of two already-frozen requirements, not a relaxation of quotient correctness: exact endpoint/action correspondence remains the final authority and is strictly stronger than raw local family labels.

## 6. Remaining observations, debts and authority

`M5-CP3-TB1-R6-REV-OBS-01` remains **OPEN**. Rows4/5 still fail in `require_produced(...)` before `select_torus_source_witness(...)`, so the exact source/A3 selected directed generator comparison never executes. CB11/R10 must preserve the no-inverse discriminator and reach it before this observation can close.

The two M5 nonzero-Z4 debts remain **OPEN**:

- `FullPeriodicRotationAndTranslationMaterialize` — row4 never reaches materialization or selected-certificate consumption;
- `TamperedFullPeriodicTransformIsRejected` — row5 never reaches the action-only tamper or exact `NonReciprocalPeriodicRelation` check.

`M5-CP2-TB1-REV-OBS-01` remains **OPEN**. R9 is semantic RED, so frozen §13.3 still forbids selector-publication precommitment. The M6 closed-complex produced debt remains **OPEN / M6-owned**.

Candidate `10668437359` remains **unpromoted**. Accepted runtime authority remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**.

R9 introduces no accepted-selector PASS→RED transition. The newly proved contract defect is exposed only on the unpromoted produced-debt surface, so it is recorded as a non-stable `RP-01` implementation/definition-authority candidate rather than a new stable event or recurrence. Stable accounting remains **50 events / 14 categories / 36 recurrences**. Project produced-witness debt remains **3**.

## 7. Bounded successor — `M5-CP3-CB11`

Review freezes exactly one runtime-free Code + Build correction under `Architecture_M5_CP3_CB11_Rotation_Aware_Periodic_Pairing_Correction_Plan.md`.

The sole product semantic path authorized is `src/geometry/SurfaceCellTracing.cpp`. CB11 must preserve all common same-region pairing authority, exact generator-route direction, `periodic_action_for_pair` endpoint/branch correspondence, CP2 checked relation creation, cross-region HardRail family/sign semantics, hard-feature nontraversability, tests, fixtures, selector430, CMake and benchmarks. It may only stop treating raw family/sign equality/opposition as same-region periodic seam authority before rotation is known, letting the exact directed generator rotation plus endpoint correspondence own that decision.

Mandatory compile/package remains all eight standard targets with GMP/GMPXX and `runtimeExecution=false`. If compile/package is green, exact successor is fresh `M5-CP3-TB1-R10-EXEC` over the unchanged **446** process identities and benchmark **0**, followed by mandatory Review whether green or RED.

The R10 load-bearing falsifier is not merely “no `PeriodicActionCorrespondenceMismatch`.” Rows4/5 must actually advance through source/A3 directed relation selection. Row4 must prove the produced relation carries the independently derived nonzero directed rotation plus nonzero translation, materializes successfully and is consumed by the selected certificate. Row5 must alter only that selected relation's action and reach exact checked `NonReciprocalPeriodicRelation`. Row6 must remain green and selector430 must remain **430/430**.

## 8. Review process and consolidation

Review used snapshot mode before substantive multi-file inspection and performed no Directional runtime, compile, benchmark, product/test/fixture/selector mutation or local build. Independent computation was limited to static source/geometry/algebra reconstruction.

Per REVIEW consolidation policy, durable facts from the superseded R8 runtime/Review, consumed CB10 plan/report and consumed R9 execution plan are folded into `M5_Consolidated_Record.md` and its folded-document index. The current R9 runtime report is retained as runtime authority; this R9 Review is the current Review authority; CB11 is the sole retained next-turn plan.

A new general lesson is recorded: **chart-local family/sign labels are not directly comparable across a quotient seam with nonzero transport; compare transported exact lattice deltas under the authoritative directed transition.**

## 9. Mandatory Review closeout table

| Obligation | Disposition |
|---|---|
| Selector prefix re-hashed | **PASS.** selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. |
| Decisive runtime claims independently re-derived | **PASS.** 446 ledgers re-counted; every raw log re-hashed; exact 444/2 vector and immutable postflight re-opened. |
| Candidate/source equivalence | **PASS.** zero semantic/code differences across `src/include/tests/benchmarks/cmake/CMakeLists.txt`; target test SHA matches exactly. |
| No-tuning/chart precommitment | **CLOSED / UPHELD.** Exact ramp and normalization match; independent geometry/matching reconstruction proves 18-edge subject, min alignment `0.7753279615208046`, `[0,1,2,3]`, `+4`, bounded closure and five nonzero hard carriers. |
| Prior witness candidate | `M5-CP3-TB1-R7-CAND-02` **CLOSED / RECOVERY PROVED / NON-STABLE / +0**. |
| New cause | `M5-CP3-TB1-R9-REV-CAND-01` **OPEN / RP-01 AUTHORITY_DOMAIN_CONFLATION / same-region periodic family-sign contract inconsistency / NON-STABLE / +0**. |
| Direction observation | `M5-CP3-TB1-R6-REV-OBS-01` **OPEN**; direction comparator still not reached. |
| Publication observation | `M5-CP2-TB1-REV-OBS-01` **OPEN**; semantic RED prohibits precommitment. |
| Produced debts | **3 total:** two M5 nonzero-Z4 OPEN; one M6 closed-complex OPEN. |
| Stable accounting | **50 / 14 / 36**, unchanged; accepted package remains `10601978228`; candidate `10668437359` unpromoted. |
| Frozen definitions | **Amended additively at §16** to rotation-aware same-region lattice-delta correspondence; exact action authority retained. |
| ORIENTATION | Updated currency/current M5 state, open successor and rotation-aware quotient lesson. |
| LESSONS | New lesson 173 records transported-coordinate comparison across nontrivial quotient transitions. |
| CHANGELOG / ROADMAP / TODO / tracker / handoff | Updated to R9 Review and exact CB11 -> R10 chain. |
| Consolidation | Superseded R8 runtime/Review, consumed CB10 plan/report and consumed R9 plan folded/indexed; current R9 report retained. |
| Successor frozen | Exactly `M5-CP3-CB11`, product-only/runtime-free; if compile green then unchanged 446-process R10 + mandatory Review. |
| Turn boundary held | **Yes.** Runtime-free Review; no product/test/fixture/selector/build/benchmark semantic mutation. |
| `review_check.py boundary` | Must PASS before publication with selector430 expected hash. |
| `git diff --check` | Must PASS before publication. |
| `STATUS` lifecycle | Start beacon published before substantive repository mutation; terminal COMPLETE beacon reserved as final repository mutation after durable publication and cleanup. |

---

## Independent verification addendum

### V1 — the R9 RED is later than R8 and the witness recovery is real

The exact source order matters. The fixture finalizes the source field, proves a nonzero row408 hard carrier, executes the chart oracle, runs the real pipeline, and calls `require_produced(...)`; only after production succeeds would it call `select_torus_source_witness(...)`. R9 reaches `PeriodicActionCorrespondenceMismatch`, so the prior `InvalidBoundedDiskChart` boundary is gone. Combined with the independent reconstruction above, the CB10 witness correction is genuinely recovery-proved rather than merely bypassed.

### V2 — the correspondence contradiction is translation-independent

The proof does not depend on an assumed offset. Two endpoint equations for one affine grid automorphism subtract to eliminate translation exactly. The contradiction is therefore about the linear Z4 part alone. No alternate translation can make a nonzero quarter-turn fix a unit cardinal edge vector.

### V3 — exact action correspondence is the guard to keep, not the guard to weaken

A tempting repair would be to accept either the generator rotation or its inverse, or to weaken endpoint equality. Both are prohibited. The authoritative directed A3/source path already owns orientation, and the still-open R6 observation exists specifically to detect accidental inverse equivalence. CB11 must remove only the premature untransported family/sign comparison for same-region periodic promotion; the one exact directed automorphism must remain mandatory.

### V4 — accounting remains stable

No accepted selector row regressed: selector430 is 430/430. The new defect is real product/definition authority work, but it is exposed only by candidate-only produced-debt identities. It therefore adds no stable event/category/recurrence under the current accounting rules. Historical `50 / 14 / 36` remains unchanged and the two M5 debts remain debts rather than being converted into regression credit.
