# M4-CP-SCALE-TB8-REV — Independent Review Record

**Date:** 2026-09-16 UTC
**Verdict:** **REJECT CB9 S4 PREREQUISITE TEST AUTHORITY / TEST-ONLY CORRECTION REQUIRED / ACCEPTED TB7 RUNTIME AUTHORITY UNCHANGED / CP-SCALE OPEN**
**Authorized successor:** `M4-CP-SCALE-CB10`

## 1. Scope and boundary

This is a runtime-free Review + Plan turn. It does not modify product, test, fixture, selector, benchmark, build or package source and does not execute Directional runtime. The reviewed candidate is CB9 package `10428779988` / semantic source `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf`; the runtime evidence is TB8 run/job `35053875774 / 104659839191`.

Accepted M4 runtime authority remains TB7 package `10425344367` / semantic source `01b1124af094044e32d6887ff0615881333d12ce` under selector425 **425/425 PASS**. No selector426 is authorized.

## 2. Evidence independently reopened

Review reopened the exact candidate package/source and the TB8 evidence rather than relying on the TB8 prose summary:

- candidate artifact `10428779988`, provider SHA-256 `7470947abba0ca2dc1e8bccd0caba8efdaa53abeaa3b1ae5130a550a3b462bd6`;
- candidate semantic source `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf`, packaged source archive SHA-256 `cd0d0c7e084bbf86fbac4086eb076ad987f55d389b5e5c63ec95fcd4724cde55`;
- TB8 result/log artifacts `10430235842 / 10430201060`, provider SHA-256 `1728a1f5a2b0c250eb328de4dde78a9076bd77b450cb0e4164e1f92e1b2ac5c8 / 229b343047c64d2f9259d791fdd4e323ad753e7b0cc549304dd8603bc2fbefbc`;
- nested evidence ZIP SHA-256 `373fd6291ae215606a4f12e47688155277afdfc330111f166b971f68e46df1ce`; its retained 29-entry manifest verifies;
- focused raw stdout and process ledger: exactly one selected/executed process, exit `1`, first failure at `tests/FieldAlignedCurveNetworkTests.cpp:14164`, expected `18U`, observed `negativeInvariant->vertexCount = 48`;
- fail-fast ledger: selector425 **0/425 executed / 425/425 explicitly UNEXECUTED**;
- immutable postflight: package/source/execution-view censuses equal and every configure/compile/relink/repair/generated-discovery/mutation/benchmark flag false.
- accepted TB7 result artifact `10426872680`, provider SHA-256 `676f6f5adab0992a8d334c5952fc133c3d0b3fa4eb93dd5128180ee4705f02b2`; nested evidence SHA-256 `436ef2722c176e92aca64c4d052d7953b979ead0e23bda33e16eb5d317a41c4d`, with **1298/1298** `SHA256SUMS` entries independently reverified. Raw selector ordinal356 reports `networkV=48`, `networkE=48`, `preCutComponentCount=4`, `preCutNonDiscComponentCount=4`, and all four components at `chi=0 / boundaryWalkCount=2 / boundaryCyclesValid=1`.

The accepted selector was independently re-hashed from the review snapshot: selector425 is exactly **425 LF rows / 425 unique**, SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; its first424 rows hash to `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`. Row356 is `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath`; row425 is the accepted S3 identity.

## 3. Finding 1 — TB8 is a valid semantic/mechanical RED, not orchestration failure

The focused executable was reached, selected exactly one identity, executed that identity, and failed a test assertion. The harness then obeyed the frozen first-anomaly stop, preserved the entire selector remainder as `UNEXECUTED`, ran immutable postflight, and returned a result artifact. That is valid semantic/mechanical RED evidence. There is no basis for a control-plane retry of the same candidate.

The workflow job's success means evidence capture completed; it does not convert the failed identity into a pass.

## 4. Finding 2 — the empty-cut torus negative is genuinely production-reachable

CB9's reachability premise is upheld. In `SurfaceCutGraph::canonical_candidate`, after source/atlas/network binding validation, `cuts` is initialized as an empty `std::set<SourceEdgeTopologyKey>` and `certify_actual_embedded_graph(...)` is called on that state before any proposal mutation. The focused test obtains the standard production torus through `remesh_from_raw_cross_field`, requires retained source/atlas/network/cut-graph products, then evaluates the independent oracle on an empty cut vector.

Therefore the subject itself is not synthetic: **the production cut search really visits the empty-cut torus candidate first**. The Review rejects the authored expected numbers, not this reachability proof.

## 5. Finding 3 — the raw S4 oracle is structurally separate, but the CB9 paired test contract is not acceptable

`cp4c_independent_actual_embedded_graph_oracle(...)` reconstructs source topology, network/cut crossings, polygon fragments, seam gluing, complement-component topology and graph connectivity without calling `SurfaceCutGraph` or the product cellularity predicate. Its S4 wrapper derives

`b1 = E - V + c`

and the necessary cellular face count

`F_required = chi(source) - s + b1`,

which is algebraically equivalent to the corrected Euler condition when each complement component is a disc. As a **necessary-condition oracle**, a mismatch between independently counted complement components and `F_required` is a sound early rejection: if the embedding were cellular, the equality would have to hold.

The separate `m4_cp_scale_s4_product_certificate_view(...)` does use product embedded-graph machinery. That is acceptable as the *paired final-authority comparator*, not as independent derivation. CB9 becomes unsound where it requires the independent complement-component count to equal the product face-walk-orbit-derived `certificate.faceCount` on a known non-cellular state. A connected complement component can have multiple boundary walks; before cellularity is established, **connected complement components and face-walk orbits are not interchangeable face-count representations**. That equality must not be an acceptance premise for the negative.

## 6. Finding 4 — the decisive `18/30/18, c=1` tuple belongs to the prescribed sphere, not the torus

The failed `18` assertion exposes a witness-identity error, not a product change.

Accepted torus authority already exists inside selector425. Review reopened TB7 raw ordinal356, `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath`: its accepted receipt reports **`networkV=48`, `networkE=48`, `preCutComponentCount=4`, `preCutNonDiscComponentCount=4`**, and each of the four components has `chi=0`, two boundary walks and valid boundary cycles — exactly four annuli. The retained M3 CP4c frozen definitions independently predict the same topology. `ORIENTATION.md` records the same pre-cut `48/48` network and accepted post-cut `72/76/4` result.

By contrast, `M3_CP4c_Consolidated_Record.md` records the prescribed-sphere independent pre-cut actual-graph oracle as **`V=18, E=30, F=18, c=1, chi=6, sourceChi=2`**. CB9 copied those sphere **graph counts** into a test whose constructed subject is `build_cp4c_pipeline_products_fixture("torus", "torus")`, while retaining the torus source Euler characteristic `0`. The resulting expected state was therefore a hybrid: sphere `V/E/F/c = 18/30/18/1` plus torus `sourceChi=0`, from which the test derived `b1=13 / requiredFaces=12 / observedFaces=18`.

The runtime `48` therefore agrees with the already-accepted torus identity and contradicts CB9's hard-coded witness label. This is the existing defect family described by `LESSONS.md`: **read a witness by its construction, not by its name; an absolute count is a hidden function of the semantics that produce it; test your own hypothesis before writing it into the record**.

## 7. Independent corrected torus arithmetic

Using the retained torus authority, the empty-cut necessary-condition arithmetic is:

- `V = 48`;
- `E = 48`;
- graph components `c = 4`;
- source components `s = 1`;
- source Euler characteristic `chi = 0`;
- independently reconstructed complement components `F_observed = 4`, each an annulus (`chi=0`, two boundary walks), not a disc;
- `b1 = E - V + c = 48 - 48 + 4 = 4`;
- `F_required = chi - s + b1 = 0 - 1 + 4 = 3`;
- `F_observed != F_required`, so the necessary-condition oracle rejects the empty-cut state.

This is consistent with the older direct theorem `E=V` on the genus-one pre-cut network: a union of closed cycles cannot cellularize the torus. It also explains why simply replacing `18` with `48` is insufficient; CB10 must correct the whole expected tuple and the off-domain representation comparison.

## 8. Finding 5 — positive/adversarial/enumeration/decision-neutral controls received zero runtime credit

The first negative assertion failed before the receipt site. Consequently the positive accepted-cut subject, one-edge adversarial subject, reversed-cut enumeration check and product re-run decision-neutrality check were **not executed in TB8**. Their source exists and compiles, but compile-valid source is not runtime proof.

Review therefore does not accept `M4-CP-SCALE-DEFN-OBS-03`. CB10 must repair the test-only authority and a later fresh artifact-only TB must execute all controls before any production S4 code is authorized.

The positive accepted-cut target remains well-founded as a falsifier: retained authority is `V/E/F=72/76/4`, `c=s=1`, hence `b1=5`, `F_required=4`, and the unchanged final certificate succeeds. For the adversarial subject, CB10 must test the one-way safety implication required by S4 — **if the early necessary-condition oracle rejects, the unchanged final certificate must also reject** — rather than imposing a biconditional that would falsely require this partial oracle to explain every final-certificate rejection.

## 9. Candidate and observation disposition

`M4-CP-SCALE-TB8-EXEC-CAND-01` is **CLOSED / TEST-AUTHORITY WITNESS-NUMERIC TRANSPLANT / NON-STABLE / CORRECTIVE CB10 REQUIRED**.

Root cause: CB9 bound prescribed-sphere pre-cut actual-graph constants to a torus negative and additionally compared two face-count representations outside the cellular domain where their equality is not guaranteed. The first wrong constant stopped the test before its remaining controls.

This does **not** open a stable product regression: candidate `10428779988` was never promoted, the failed identity is outside selector425, selector425 did not execute in TB8, and there is no accepted PASS→RED transition. Stable accounting stays **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

`M4-CP-SCALE-DEFN-OBS-03` remains **OPEN / TEST-AUTHORITY CORRECTION + FRESH RUNTIME + REVIEW OWED / NON-STABLE**. Its immediate owner chain is `M4-CP-SCALE-CB10 -> M4-CP-SCALE-TB9-EXEC -> M4-CP-SCALE-TB9-REV`.

## 10. Authorized successor — `M4-CP-SCALE-CB10`

CB10 is a bounded **test-authority correction + compile/package only** turn under `Architecture_M4_CP_SCALE_CB10_S4_Test_Authority_Correction_Code_Build_Plan.md`.

It may change only the S4 prerequisite test/helper authority needed to:

1. bind the empty-cut negative to the accepted torus `48/48, c=4, s=1`, four-annulus authority and independently derive `b1=4`, required faces `3`, observed complement components `4`;
2. remove the invalid negative equality between independent complement-component count and product face-walk-orbit count;
3. pair an early rejection only with the required one-way implication that the unchanged final certificate also rejects;
4. preserve and later runtime-prove the positive accepted-cut, adversarial, enumeration-invariance and decision-neutrality controls;
5. keep product source, A2a' cut selection, final certificate semantics, fixtures, CMake and selector425 unchanged.

CB10 executes **no Directional runtime** and publishes no selector426. If the corrected prerequisite cannot be stated without changing production semantics or weakening the final certificate, CB10 must stop and return to Review.

After a successful compile/package, the only expected runtime successor is fresh artifact-only `M4-CP-SCALE-TB9-EXEC`, focus first and then exact selector425 under the normal fail-fast and immutable-postflight rules, followed by mandatory Review.

## 11. Prior obligations

- `M4-CP-SCALE-TB1-REV-OBS-01` — **CARRIED**: representative/stress S1 calibration before any numeric gate.
- `M4-CP-SCALE-TB2-REV-OBS-02` — **CARRIED**: dedicated remaining `make_zero_transport_field` caller audit.
- `M4-CP-SCALE-DEFN-OBS-01` — **CARRIED**: S2 arrival exact-fallback authority absent.
- `M4-CP-SCALE-DEFN-OBS-02` — **DISCHARGED previously** by TB6 Review.
- `M4-CP-SCALE-DEFN-OBS-03` — **CARRIED / RE-SCOPED TO TEST-AUTHORITY CORRECTION** as §9.
- `M4-CP-SCALE-DEFN-OBS-04` — **CARRIED**: genus>=2 production/reachability absent.
- `M4-CP-SCALE-TB4-REV-OBS-01` — **DISCHARGED previously** by TB5 Review.
- `M4-CP-SCALE-TB6-REV-OBS-01` — **DISCHARGED previously** by TB7 Review.
- `M4-CP3-TB1-R1-REV-OBS-01`, `M4-CP3-CB4-REV-OBS-02`, `G4-B002`, `G4-B003` — **CARRIED** with their existing owners unchanged.

## 12. Consolidation

This Review folds the superseded/consumed CB9/TB8 turn documents into `M4_Consolidated_Record.md` §2.56 after preserving their exact evidence and disposition there:

- `Architecture_M4_CP_SCALE_CB9_S4_Oracle_Reachability_Code_Build_Plan.md` — 126 lines;
- `Architecture_M4_CP_SCALE_CB9_Code_Build_Report.md` — 91 lines;
- `Architecture_M4_CP_SCALE_TB7_Review_Record.md` — 113 lines;
- `Architecture_M4_CP_SCALE_TB8_Artifact_Only_Test_Benchmark_Plan.md` — 133 lines;
- `Architecture_M4_CP_SCALE_TB8_Artifact_Only_Test_Benchmark_Report.md` — 115 lines.

The current accepted runtime report remains `Architecture_M4_CP_SCALE_TB7_Artifact_Only_Test_Benchmark_Report.md`; this Review becomes the current Review; CB10's plan becomes the single next-turn plan. Frozen definitions, selector files, tracker, changelogs, closure records and consolidated records remain retained authority.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector425 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; first424 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`; 425/425 unique rows |
| Decisive claims independently re-derived | Reopened CB9 package/TB8 result+log+nested evidence and accepted TB7 result/nested evidence; raw TB7 ordinal356 re-proves `48/48` with four annuli; re-read exact focus source and `canonical_candidate`; re-derived torus `48/48,c=4,s=1,F=4 -> b1=4,F_required=3`; traced `18/30/18,c=1` graph counts to retained prescribed-sphere authority |
| Non-vacuity checked | Negative is genuinely first production candidate; focus actually executed and failed; remaining controls received zero credit because the first assertion stopped them; accepted row356 already distinguishes the torus numbers |
| Prior obligations discharged/carried | §11 lists every active CP-SCALE/CP3/debt obligation; none silently expired |
| Stable accounting | **49 / 14 / 35**, debt **5**; accepted package `10425344367`, selector425 **425/425** |
| New candidates/obligations recorded | `TB8-EXEC-CAND-01` closed non-stably as test-authority witness-numeric transplant; `DEFN-OBS-03` carried to CB10 -> TB9 -> Review; tracker updated |
| ORIENTATION currency line | `M4-CP-SCALE-TB8-REV`, 2026-09-16 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated to CB10; §4 unchanged because no product witness state changed; §8 adds this as an existing witness/count-authority pattern and removes stale “current Review” wording from the older setup-order entry |
| CHANGELOG | Root and Directional changelogs updated with this adjudication |
| ROADMAP | CP-SCALE status advanced through TB8 Review; exact next CB10 |
| Selector manifest | n/a — no selector added, changed or accepted; selector425 remains accepted unchanged authority |
| LESSONS | No new category; existing lessons cited: “Read a witness by its construction, not by its name”, “An absolute count is a hidden function of the semantics that produce it”, and “Test your own hypothesis before you write it into the record” |
| Consolidation under CLEAN_UP_POLICY | Five superseded/consumed CB9/TB8 documents folded into `M4_Consolidated_Record.md` §2.56; current TB7 runtime report retained |
| Successor frozen | `M4-CP-SCALE-CB10`; falsifiers and stop rules are frozen in `Architecture_M4_CP_SCALE_CB10_S4_Test_Authority_Correction_Code_Build_Plan.md` |
| Turn boundary held | runtime-free; documentation only; no product/test/fixture/selector/benchmark/build mutation |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** — `review_check.py boundary --expect-selector 425=e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` reports no product/test/fixture/build mutation, no selector mutation, all committed selector hashes preserved, durable markers preserved, and the declared selector425 hash matches |
| Pushed to origin, branch in sync | **PASS AT TURN CLOSEOUT** — durable Review/plan/consolidation bytes are required to land on the configured working branch, temporary control state is then removed workflow-first, and final branch authority is re-read before the mandatory final PR summary comment; no local-only semantic work may remain |
