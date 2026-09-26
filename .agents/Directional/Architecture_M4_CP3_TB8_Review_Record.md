# M4-CP3-TB8 Review Record

**Turn:** `M4-CP3-TB8-REV`
**Date:** 2026-09-13 UTC
**Disposition:** **APPROVED / PACKAGE + SELECTOR408 PROMOTED / CP3 CLOSED**
**Runtime in Review:** none

## 1. Review question and independent evidence boundary

This Review adjudicates the mechanically green `M4-CP3-TB8-EXEC` evidence against the frozen CP3 exit. It does not execute Directional, compile, relink, repair, mutate a package, alter product/test/fixture/build source, or edit selector bytes.

The Review independently reopened:

- candidate semantic source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`;
- immutable candidate package artifact `10307919492` (`m4-cp3-cb10-result-34727247774`), provider/download ZIP SHA-256 `8988a12fa8b2e6476bf3fd91a6a6936eaef8a9ab7c73837b74ea2e980d29b2ec`;
- authoritative TB8 run/job `34729562893 / 103649745950`;
- TB8 result artifact `10309365777`, SHA-256 `a8d91cd62cb2c633ed46ab963a13060e903a5043d3941fdea6aaec9c77091c04`;
- TB8 log artifact `10309009858`, SHA-256 `c7a7cf9e32269b85afde621c18799f49f9ad815ed9b7fb2eedd066f102275772`;
- fresh Review source snapshot run/artifact `34733318398 / 10310382720`, snapshot ZIP SHA-256 `fc8830dd7bdfd3d719ff654c16ed29ea6fda9cde432734eb8087dd01d1a93620`, exact snapshot SHA `e272b02ad5e905ecb5fed98eceb008ef2b2095bf`.

The snapshot head differs from candidate semantic source only by later control/documentation state on the reviewed critical code/test/selector surfaces. Exact byte comparison re-proved equality for `tests/SurfaceCellTransitionQuotientTests.cpp`, `tests/SurfaceCellPipelinePhase20Tests.cpp`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, selector403 and selector408.

## 2. Package and selector authority re-derived

Package root `SHA256SUMS` independently verifies **28/28**. Packaged source commit is exactly `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`, packaged final source status is empty, GMP/GMPXX evidence is present, and the packaged source archive SHA-256 is `1ff187c6c08d13f5be5e6481f5323541e48fc93e6ffc0ada78af73a7926c205d`.

The six packaged executable owners retain executable mode and the package was not repaired in Review. Selector authority re-hashes to:

- selector403: **403** LF rows, `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- selector408: **408** LF rows, `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`;
- selector408 rows 1-403 are byte-identical to selector403.

The static owner partition remains **30 authority-kernel / 262 producer / 75 completion / 41 validation**, with all 408 identities uniquely owned.

## 3. Mechanical execution re-derived from raw evidence

`process-ledger.tsv` independently hashes to `2700e511a12505dbaf87b87d00bed7f2d2b73e65dd38adb1934682cb72abf63d`. It contains exactly **835 unique sequences**, all `PASS`, with one selected identity and one OK line per process, zero skipped lines, zero RED, zero crash and zero selection mismatch.

Phase census:

| Phase | Processes | Result |
|---|---:|---|
| six shared-fixture identities A | 6 | 6 PASS |
| six shared-fixture identities B | 6 | 6 PASS |
| accepted ordinal138 A/B | 2 | 2 PASS |
| row408 A/B | 2 | 2 PASS |
| rows404-407 A/B | 8 | 8 PASS |
| accepted selector403 complete census | 403 | **403/403 PASS** |
| cumulative selector408 | 408 | **408/408 PASS** |
| **Total** | **835** | **835/835 PASS** |

The accepted-prefix semantic RED census is empty. The frozen requirement added by TB7 Review — run selector403 to completion without semantic fail-fast — is therefore discharged rather than merely stopping after the repaired ordinal211.

Preflight and postflight both completed. `package_census_equal=true`, `source_census_equal=true`, and `execution_view_census_equal=true`. The execution boundary records no configure, compile, relink, generated discovery, package repair, benchmark, or source/test/fixture/selector mutation.

Three earlier shell-orchestration attempts failed before Directional runtime and remain excluded from semantic credit. The private local attempt from the EXEC turn is likewise excluded; no stitching is used here.

## 4. CB10 test-authority recovery is non-vacuous

The repaired `make_hard_rail_fixture()` preserves the 3x3 mesh and user hard edges `(1,4)` / `(4,7)`, but now obtains its network through `remesh_from_raw_cross_field(..., SurfaceCells)` with fallback `Fail`, source-grid recovery disabled and retained intermediate geometry. Before exposing the fixture it requires retained source topology, `GlobalTopologyPlan`, `GlobalConformityBaselinePlan`, authoritative rails and the trace network, then requires a `Produced` network.

That precondition is load-bearing. Under the pre-CB10 fixture the production CB5 cutover could not populate exact A3 `sharedBoundaryInterval` identity and ordinal211 failed before its intended tamper oracle. Under candidate bytes all six consumers pass A/B:

- ordinal211 `AmbiguousHardRailCounterpartIsRejected`;
- ordinal217 `ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- ordinal219 `MissingHardRailCounterpartIsRejected`;
- ordinal227 `DuplicateSemanticRouteTopologyFailsClosed`;
- ordinal230 `RouteTopologyTransitionMismatchFailsClosed`;
- ordinal231 `ValidHardRailRouteUsesTypedIdentity`.

The bodies remain distinct and behaviourally discriminating: they prove positive stitching/typed-route consumption or deliberately tamper opposite-edge/route topology and require typed failure. Their green result is not a fixture-construction-only receipt.

`M4-CP3-TB7-REV-CAND-01` therefore closes **RECOVERY PROVED / STABLE EVENT RETAINED**. The historical accepted ordinal211 PASS->RED event remains counted; recovery never decrements the stable ledger.

## 5. Product strictness and CP3 exit re-derived

The production hard-rail binder still fails closed when a candidate hard rail is already paired, non-exterior, regionless, routeless, or lacks `sharedBoundaryInterval`. Pair formation still requires exact A3 span identity, reversed consecutive ordinals/orientation, compatible route/rail authority and A4-local family/advance-sign compatibility before assigning `oppositeEdge`. No floating `support_key` or no-plan fallback was restored.

The five appended CP3 witnesses are all green A/B and cumulative:

- row404 proves production A4 publishes an accepted A2b/A3 conformity receipt and non-empty exact shared intervals;
- row405 runs the same fixed accepted conformity plan at target sizes `0.5` and `2.0`, requires both Produced, requires equal plan receipts, requires non-empty shared intervals, and requires those interval sets equal;
- row406 deletes or tampers exact shared interval identity and requires `InvalidSharedBoundaryInterval`, explicitly forbidding unchanged floating geometry from restoring identity;
- row407 proves the A3 cutover leaves A4-local family/advance-sign authority intact;
- row408 proves the constructed exact torus production path publishes typed shared-boundary identity and is green twice focused plus once cumulative.

This satisfies the frozen CP3 exit: A4 consumes accepted A3 authority; fixed-plan target/grid perturbation cannot change shared breakpoints; post-hoc floating support pairing is not authority; and the exact-torus production witness completes without `InvalidHardRailPairing`.

The historical-provenance bound is retained: row408 is a **constructed** production torus witness. It proves the exit conjunct; it is not evidence that the exact same path historically emitted `InvalidHardRailPairing` before CP3.

## 6. Promotion and checkpoint decision

**APPROVED.** Candidate package `10307919492` and selector408 become the accepted current M4 runtime authority at **408/408**. Corrected R4 package `10289601000` / selector403 remains the accepted predecessor authority and historical recovery baseline.

**M4-CP3 is CLOSED / ACCEPTED.** Closure is recorded in `M4_CP3_Closure_Record.md`.

The main exact-torus `G4-B002` `InvalidHardRailPairing` blocker is **CLOSED / RECOVERY PROVED at CP3**. This does **not** discharge its three inherited produced-witness debts. Frozen M4 §11.1 keeps those three gates for cumulative `M4-CP4`; total produced-witness debt therefore remains **5**.

## 7. Stable accounting and candidate disposition

No accepted identity transitions PASS->RED in TB8. No new stable event or category is created.

Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

- `M4-CP3-TB7-REV-CAND-01` — **CLOSED / RECOVERY PROVED / STABLE EVENT RETAINED**.
- CB9 applicability correction remains recovery-proved and retained.
- CB8 occurrence-domain correction remains recovery-proved and retained.
- selector408 is promoted; there is no open CP3 candidate after this Review.

## 8. Prior obligations

- `M4-CP3-TB1-R1-REV-OBS-01` — **CARRIED / NON-BLOCKING.** The required end-to-end multiplicity-2 fixture was not folded into CB10 because that turn's evidential value depended on changing only the stale hard-rail fixture. Re-owner to the first later independently falsifiable M4 test-authority turn before cumulative `M4-CP4`; `M4-CP-COND` may own it only if the fixture is naturally independent, otherwise use a dedicated bounded test-only turn before CP4.
- `M4-CP3-CB4-REV-OBS-02` — **CARRIED / NON-BLOCKING.** Add the sixth row399 path/`sourceFaces` divergence tamper only on the next legitimate row399 touch.
- TB3 provenance warning — **CARRIED as a historical-claim bound**, not as a product defect.

None blocks CP3 closure because none is a frozen CP3 exit conjunct and each retains an explicit future owner.

## 9. Document consolidation

CP3 is now closed. Durable facts from superseded per-turn records were preserved here, in `M4_CP3_Closure_Record.md`, `M4_Consolidated_Record.md`, the tracker, selector manifest, ORIENTATION, ROADMAP and CHANGELOG before folding. The closure record indexes the final closure-time folds with exact filenames and line counts. Current TB8 runtime report and this Review record are retained as current authority; selectors, frozen definitions, policies and closure records are never folded.

## 10. Exact successor — `M4-CP-COND-DEFN`

Exactly one successor is authorized: **runtime-free `M4-CP-COND-DEFN`**, under `Architecture_M4_CP_COND_DEFN_Plan.md`. It freezes the checkpoint-local Amendment-20 conditioner contract before any implementation.

Definition-turn falsifiers/STOPs are frozen before any later build:

1. STOP if conditioning becomes an A3 semantic precondition, changes the accepted A3/A4 authority contract, or creates a second writer for accepted source identity.
2. STOP if raw->conditioned correspondence is inferred by tolerance/geometry instead of an immutable certified relation, or if correspondence cannot be independently falsified.
3. STOP if an inadmissible raw field is silently repaired until accepted rather than producing the frozen typed inadmissibility outcome.
4. STOP if sliver, high-valence, negative-index singularity, boundary-truncated separatrix, deliberately inadmissible-field, correspondence-integrity or idempotence witness preconditions cannot be independently established; record the missing precondition instead of authoring a guaranteed-green gate.
5. STOP if CP-SCALE numeric thresholds, genus>=2 scale acceptance, M5/M6 relation work, or the three CP4 produced-witness debts are pulled into CP-COND.
6. The DEFN turn itself is documentation/normative-definition only: no runtime, product/test/fixture/selector/build mutation.

---

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`; selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; first403 byte-identical and re-hashes exactly to selector403 |
| Decisive claims independently re-derived | PASS — package 28/28/source authority, exact selector bytes/prefix, 835-row unique process ledger, 835/835 classification and phase partition, empty accepted RED census, raw focused identities, production hard-rail strictness, and package/source/execution-view immutability were independently reopened from bytes |
| Non-vacuity checked | PASS — repaired fixture requires production A2b/A3/rails/trace + Produced before six distinct positive/tamper oracles; row405 uses two different target sizes and non-empty intervals; row406 destroys/tampers exact identity and must fail; row408 reaches constructed production torus A4 authority |
| Prior obligations discharged/carried | `M4-CP3-TB7-REV-CAND-01` CLOSED recovery-proved/stable-event-retained; `M4-CP3-TB1-R1-REV-OBS-01` and `M4-CP3-CB4-REV-OBS-02` carried with explicit future owners; TB3 provenance warning carried |
| Stable accounting | UNCHANGED — **49 events / 14 categories / 35 recurrences**, debt **5**; accepted package `10307919492` + selector408 **408/408** |
| New candidates/obligations recorded | None — no TB8 RED/change creates a new candidate; only existing non-blocking obligations are re-carried |
| ORIENTATION currency line | UPDATED to `M4-CP3-TB8-REV`, 2026-09-13 |
| ORIENTATION §3 / §4 / §7 / §8 | UPDATED — package/selector408 promotion and CP3 closure; torus witness accepted; CP3 defects removed from open list; CP-COND made next; recovered RP-02 instance recorded without a new pattern |
| CHANGELOG | UPDATED with TB8 Review promotion/closure and exact successor |
| ROADMAP | UPDATED — CP3 CLOSED/ACCEPTED; exact next `M4-CP-COND-DEFN`; main G4-B002 exact-pairing blocker closed while three CP4 debts remain |
| Selector manifest | UPDATED — selector408 promoted as accepted M4-CP3 authority; hashes/prefix and TB8 acceptance receipt recorded; selector bytes unchanged |
| LESSONS | No new entry — TB8 is recovery evidence for existing `RP-02`/non-vacuity/hold-one-variable lessons; no new defect pattern appeared |
| Consolidation under CLEAN_UP_POLICY | Final superseded CP3 per-turn plan/report/review records folded/indexed into `M4_CP3_Closure_Record.md`/`M4_Consolidated_Record.md`; current TB8 runtime report, current TB8 Review, selectors and frozen definitions retained |
| Successor frozen | PASS — exactly `M4-CP-COND-DEFN` under `Architecture_M4_CP_COND_DEFN_Plan.md`; falsifiers/STOPs are stated in §10 before any later build |
| Turn boundary held | PASS — runtime-free Review; no product/test/fixture/selector/benchmark/build source mutation |
| review_check.py boundary | PASS — plain `boundary` returned `ALL CHECKS PASSED` on the documentation-only Review delta. The helper's count-only selector lookup is milestone-ambiguous for row-count 403 and resolves the M3 selector, so the M4 selector403 expectation was not delegated to that ambiguous lookup; the exact M4 selector path was independently re-hashed to `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`, while the helper independently accepted selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`. |
| Pushed to origin, branch in sync | PASS — final reviewed documentation/closure bytes and cleanup were published on the working branch; final branch authority was re-read after cleanup before the final PR summary comment |

---

## 11. Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** CP3 closure, promotion of the package and selector408, and the accounting are all
sound, and both requirements this reviewer carried into the turn were honoured.

### V1 — the TB7 no-fail-fast requirement was implemented and it validated the closure

The phase census decomposes exactly: `6 + 6 + 2 + 2 + 8 + 403 + 408 = 835`, all PASS. The accepted prefix ran
**to completion** — `accepted selector403 complete census 403/403` — and the accepted-prefix semantic RED
census came back **empty**.

That is the strong positive outcome the requirement existed to obtain. The five static at-risk consumers named
at TB7 all pass, and because the whole accepted prefix ran rather than halting at a first casualty, CP3 closes
on a complete census rather than on the absence of a first failure. Had the requirement not been added, this
closure would have rested on a fail-fast run that stopped at the first green-through point and could not have
excluded further latent cutover breakage.

### V2 — the provenance bound is honoured exactly

§5 states that row408 is a **constructed** production torus witness — it proves the exit conjunct and is not
evidence that the exact torus was historically observed to fail at `InvalidHardRailPairing` — and §8 carries
the TB3 warning as a historical-claim bound rather than a product defect. That is precisely the form required
at `M4-CP3-TB3-REV` §9 V2 and restated at TB5. §7's scoping is also right: closing the blocker does not
discharge the three inherited `G4-B002` produced-witness debts.

### V3 — lineage and accounting re-derived

The M4 selector408 (`Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt`) has 408 rows, hashes to
`c689c0cd8a51f9a8…`, and its **first 403 rows hash to `c3f509afc823cd73…`**, byte-identical to accepted
selector403. Accounting correctly holds at **49 / 14 / 35**, debt **5**, since no accepted ordinal transitioned
PASS → RED in TB8.

**Minor hazard worth recording:** `Selector_408` now names two unrelated files — the M3-era
`Architecture_M3_CP4c3_Required_Green_Selector_408.txt` and this M4 one. A glob-based hash check hits the M3
file first and yields a prefix that matches nothing. The same collision already exists at `Selector_403`.
Future selector verification should address the file by its full milestone-qualified name, not by ordinal.
