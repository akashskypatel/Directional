# Directional Surface-Cell Reorientation Plan

**Status:** authoritative architecture-migration roadmap
**Normative design:** `.agents/Directional/DESIGN.md`
**Accepted authority:** M3 CP4ab source/package `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`, immutable TB-R3 `32758293793 / 97530833220` — **316/316 PASS**.
**Decision:** **M1 and M2 are CLOSED / ACCEPTED. M3 CP1, CP2, CP2b, CP3a, CP3b, and CP4ab are accepted at 316/316.** CP4c-0 remains OPEN. CB2 is build-green at `390e65b373063c667e3c3f5e78b74ed9d859093b / 9586196535`; TB-R2 re-proved the accepted 316 and prior 328 prefix, then hit a valid semantic red at correction identity 329 before Q8. Stable totals remain **42 / 14 / 28**, debt **5**, packages **41**.

**Updated 2026-08-26 after `M3-CP4c-0-TB-R2`.** Authoritative retry 1 `32914546494 / 98015432540` passed identities **1–328** and failed ordinal **329**, `ResolvedBranchCorrection.NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`. The immutable diagnostic shows numeric branch loci emitted as control characters because `FieldBranch::value()` is `std::uint8_t` and the test/witness stream inserts it directly as a character. Q8 was correctly **NOT RUN** because 338/338 was not green. Exact next is independent **`M3-CP4c-0-TB-R2-REVIEW-PLAN`**; no semantic rerun or correction precedes that review. The checkpoint map is `ROADMAP.md`.
**M1 exit gate:** retained in section 5.1 as the gate-authoring pattern. **Retry budget: ABOLISHED 2026-08-25.** A diagnosed orchestration defect may be corrected without consuming semantic authority; deterministic semantic red does not rerun inside TB. Cumulative package cost is reported, not gated; M3 has **41 packages**.
**Last updated:** 2026-08-26 UTC

Repository authority: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8. Keep the PR open, draft, and unmerged until separately authorized.

## 1. Migration objective

Replace representation-coupled surface-cell remeshing with the architecture defined in `DESIGN.md`: typed single-writer authority, closed stage products, field-aligned curve/network production, one global conformity plan, certificate-carrying quotient/embedding products, independent verification, and explicit disposition/degradation. Pipeline B is the scheduled product path. Pipeline A remains optional and unscheduled.

The migration is vertical. A milestone closes only when its relevant authority is produced, consumed, independently verified, and accepted on immutable runtime evidence. Lettered or representation-only slices are not substitutes for a complete milestone contract.

## 2. Durable migration rules

1. **One semantic authority per fact.** Numeric projections, caches, hashes, source labels, and debug products are representations, not competing semantic owners.
2. **Closed producer outcomes.** A producer publishes one complete immutable product or a typed rejection/not-applicable outcome. Partial rejected state is not consumable authority.
3. **Consumers validate/remap; they do not reconstruct semantics.** Aggregation may change representation domains but must not invent source support, rails, chart relations, or identities.
4. **Exact source ownership.** Matching matrix extent is insufficient; typed source authority must match source-face topology and ownership.
5. **Canonical identity reconstruction.** Derived caches are rebuilt only from canonical completion-owned authority and remain fail-closed on invalid lineage.
6. **Hard features and boundaries are mandatory topology authority.** They may not silently disappear during component remap, completion, aggregation, or validation.
7. **Independent verification.** Final acceptance cannot derive expected semantic state from the output being validated.
8. **Strict fixtures require Certified/D0.** Degraded dispositions cannot close strict product gates. **Enforceable from M7 onward**, which is where verifier-assigned dispositions D0-D4 are implemented (section 11). Before M7 this is a forward rule and must not be used as a gate criterion — no milestone may require a disposition tier that its own implementation does not yet have. Section 5.1 criterion 5 states the M1-available equivalent.
9. **Immutable cadence.** Code + Build compiles/packages without generated runtime; Test + Benchmark consumes that exact package without rebuild or source/test/fixture/package mutation.
10. **Tasklisted partial-CB exception for work units 2 and 3 and the M1 full-authority partials.** A user-authorized `P-CB` may advance directly to its named successor `P-CB` without TB only when `TODO.md` records that exact edge. Every partial remains runtime-free and semantically unaccepted. The final packaging partial in each batch creates the immutable package and must advance to that batch's TB; no batch or later milestone work advances before that TB is green.

## 2.1 Prohibited remediation moves — DURABLE, DO NOT DELETE

No milestone may answer a semantic failure with any of the following. Each is a way of making a gate report success without establishing the fact the gate exists to establish. Recovered from the retired G4 remediation record, where they were the original acceptance discipline; several have since been observed in practice, which is why they are retained rather than summarized.

- validator weakening;
- fixture special-casing;
- count/order/frequency-based ownership selection;
- generic-producer substitution after a typed `Rejected`;
- fallback or recovery paths standing in for absent authority;
- **positional sheet merging** — merging local sheets by container position rather than certified relation;
- **Euclidean periodic seam welding** — closing a periodic seam by geometric proximity instead of typed periodic relation authority;
- arbitrary subset search;
- synthetic topology correction;
- **post-hoc cycle/cell merging** — repairing a complex after production instead of producing it correctly;
- **timeout-as-correctness** — treating an elapsed-time cutoff as a passing or acceptable result.

## 2.2 Retained producer capability baseline — DURABLE, DO NOT DELETE

These producer capabilities were proven before the redesign and must survive it. They are stated as *capabilities*, not as representations: the redesign has legitimately changed how several are represented (typed IDs, checked factories, canonical chart authority), and that is not regression. Losing the capability is.

Use this as a non-regression checklist when M2-M8 rework the producer path.

- first-class `NotApplicable` / `Produced` / `Rejected` producer outcomes;
- no generic substitution after `Rejected`;
- reciprocal source-edge/source-vertex transport with source-route provenance;
- component and local-sheet isolation;
- topology-derived annulus applicability and intrinsic cut;
- periodic holonomy carrying rotation, translation, and an ordered source route;
- exact artificial-cut ownership and quotient;
- canonical source-strip breakpoints and per-strip subdivisions;
- reciprocal field-authoritative adjacent-ring correspondence with typed ambiguity rejection;
- canonical source-simplex chart endpoints;
- direct one-cell-to-one-quad materialization;
- strict source-authoritative validation.

## 3. Milestone sequence

| Milestone | Purpose | State |
|---|---|---|
| M0 | preserve evidence and accepted baselines | complete |
| M1 | single-authority contract cutover | **complete** |
| M2 | closed stage products and single writers | **complete** |
| M3 | field-aligned curve network | **active** |
| M4 | global conformity plan | pending |
| M5 | certificate-carrying chart/quotient relations | pending |
| M6 | occurrence, embedding, and independent verification | pending |
| M7 | disposition and graded degradation | pending |
| M8 | module boundaries and operational hardening | pending |
| Pipeline A | optional decomposed coordinate integration | unscheduled |

A later milestone must never be pulled into an earlier one merely to make a local test pass. Where an earlier milestone cannot prove something without a later capability, it records the limitation and the owning milestone carries the re-proof as an exit criterion.

## 4. M1 — CLOSED

M1 is closed on the immutable full-M1 artifact-only exit gate: source/package `8232216a66020d440e5a6400b61904ca0430b6c1 / 9293593175`, run/job `32055365696 / 95464163035`, **234/234 required-green**, static closure `K=0` in all eight domains, all six section-5.1 criteria PASS, immutable postflight clean.

The complete M1 history — the R-A/R-B/R-C/unit-2/unit-3 trajectory, the six-criterion gate evidence, the two criterion-5 authoring corrections, the declared limitations, and the durable lessons — is consolidated in **`M1_Closure_Record.md`**, which is the M1 authority. Per-checkpoint records and per-turn plans/reports are retired into it.

**Carried forward from M1 into later milestones:**

- **5 produced-witness debts** — 3 owned by `G4-B002`/revised M4 (section 8), 2 by `G4-B003`/M5 (section 9), each enforced as an exit criterion of the owning milestone.
- **Criterion-5 disposition re-proof** — owned by M7 (section 11).
- **`T5` threshold calibration** — gates the representative acceptance matrix, not any milestone gate yet.
- **Open hygiene** — the frozen exclusion register's 17 non-gating identities, 3 R-A hygiene records, and 4 R-F exclusions-by-design remain tracked in `TODO.md` and are never required-green evidence.

M1 claims authority correctness only. It makes **no production-quality claim**: representative meshes, quality thresholds, and resource budgets were explicitly excluded from its gate.


## 5. Checkpoint execution discipline — DURABLE, DO NOT DELETE

Derived from R-A's actual cost. R-A's decisive unblock was not a runtime cycle: it was one command enumerating all nine `SourceChartTransitionGraph` construction sites, which showed that exactly one of nine did not pass hard-feature barriers. Retries 5 through 13 discovered nothing that enumeration would not have produced before the first build. These rules exist so that cost is not paid again.

1. **Enumeration precedes edits.** Every unit opens with an inspection-only site-set enumeration of the authority under change: all constructors, factories, publication transitions, mutable accessors, and semantic consumers. For unit 2, each batch-opening `0` partial freezes the complete batch census and assigns every requiring-change path to a later partial before production edits; every later partial reconciles its sites against that census. The batch is not ready to mutate until the enumeration can state *N sites found, all N classified, K require change*. A partial or unbounded site set is a blocked checkpoint, not a startable one.

   **The gate must also report deferred-blocker exposure**: whether any contract the unit will add or touch depends on the produced torus, the periodic pipeline, or any other known-red fixture carrying a deferred defect. Ask this about the *blocker class*, not one representative artifact of it. Unit 1 learned this the expensive way — it was asked only whether it needed a closed-complex witness, correctly answered **NO**, and still collided with `G4-B002` at Test + Benchmark through the periodic/torus path, costing an attempt.
2. **Bound the class, not the instance.** When a defect is found, enumerate every site sharing its shape before repairing any of them. Pinning instances one at a time is what turns a one-defect checkpoint into a multi-retry loop.
3. **No defaulted authority.** A defaulted-optional parameter carrying authority, barrier, registry, or ownership input is a defect generator: it lets a call site silently omit mandatory semantics and still compile. Authority parameters are required parameters. Section 5.5 records the unit-1 sweep that closed the known instances; any newly defaulted authority input is a new defect.
4. **Retry budget with a declared stall rule.** Measured cost is R-A **16**, R-B **4**, R-C **4**, unit 2 **7 of an 8 ceiling**.

   **Cost tracks independent semantic domains per batch — not files, not lessons transferred.** Measured: R-A 16, R-B 4, R-C 4, unit 2 **7 of 8**, unit 3 **6 of 8**. The evidence is consistent across both decomposed units:

   | Batch | Independent semantic domains | Package attempts |
   |---|---:|---:|
   | unit-2 A, B, D | 1 each | 1-2 each |
   | unit-2 C (containers/kernels/optimizers/validators/pipeline/tests) | many | 3, after splitting into 5 partials |
   | unit-3 E (five typed-ID domains) | 5 | **4** |
   | unit-3 F, G | 1 each | **1** each |

   Unit 3 was decomposed by surface before starting, which was right — F and G passed first time. But Batch E grouped five ID domains under one label and cost 4 of unit 3's 6 attempts. **A batch is "one surface" only if it has one semantic domain.** Count domains when sizing a batch, and decompose before starting rather than after a red gate.

   A remaining monolithic unit is budgeted at **4 attempts**. For decomposed unit 2, only the four planned final batch packages submitted to TB consume that ordinary budget; intermediate partial source revisions and compile catches are documented but are not semantic attempts. A red batch remains on that batch and may receive at most one planned remediation package retry. Eight cumulative immutable unit-2 batch-package attempts is the hard ceiling; if unit 2 is unresolved at attempt 8, stop and restructure/review before any ninth attempt. The budget is declared before work starts so the decision to stop is not negotiated during a stall.

   **AMENDED for M3-M8 — cumulative ceilings retired, per-checkpoint attempts adopted.** Everything above is the measured M1/M2 record and remains the calibration evidence; it is not deleted. But those numbers were derived **entirely from cutovers**, where the behaviour already existed and cost tracked the count of semantic domains re-typed. M3-M8 build new capability, where a red checkpoint is usually a design defect and the number of attempts a design defect needs is not predictable from a domain count. M3's history confirmed the mismatch: the ceiling was amended under pressure every time it bound (11, `5 -> 6`, `6 -> 7`, `11 -> 12`, and a pending `12 -> 13`), which converts a stop rule into a recurring negotiation — the exact failure this section exists to prevent.

   The user has therefore authorized, for **M3 and all remaining milestones**:

   - **one attempt = one complete Code + Build -> immutable Test + Benchmark pair.** The pair is the unit. Neither half is an attempt on its own: there is no such thing as "a CB attempt" or "a TB attempt", and a CB and its TB are never counted as two. The attempt is **consumed when the pair completes** — when that CB's immutable package produces a valid gate result under its TB. A package that has been created but not yet submitted to its TB has consumed nothing yet; a TB re-run against the same package for harness reasons is not a second attempt; and a pair whose TB produces no valid gate result (infrastructure or harness failure rather than a semantic outcome) consumes nothing. Review turns, the mandatory exact-source pre-package compile, diagnostic gates (below), documentation/control-plane commits, and a CB that stops before packaging all consume nothing;
   - **a checkpoint may hold at most one un-submitted package at a time.** Creating a second package without submitting the first to its TB is a stop condition returning to Review. This preserves the pairing discipline: packages are not a queue to be reordered or cherry-picked, and the pair definition must not become a way to accumulate untested packages.
   - **3 attempts per checkpoint.** A third red TB forces a **mandatory independent Review** before a fourth attempt; no other turn type may authorize that attempt in its place;
   - a completed mandatory review restores **3 fresh attempts**, under an escalating **ratchet**: the second mandatory review on one checkpoint (6 red attempts) may not re-authorize the same approach unchanged — it must rescope or split the checkpoint, amend the design, or recommend stopping, and must say which; the third (9 red attempts) is a **hard stop** requiring explicit user authorization to continue;
   - **cumulative cost is reported, not gated.** Packages consumed per milestone remain recorded in `CHANGELOG.md` and the handoff so a runaway milestone stays visible, but no turn is blocked on the count and no cumulative-ceiling amendment is required again for M3-M8.

   **Diagnostic gates — new-contract-only, attempt-free.** A Code + Build turn is runtime-free by rule, so without this a new fixture's first execution is always inside an attempt-consuming TB. The project already forbids a package attempt being the first *compile* of new code; this is its missing counterpart for the first *execution* of a new fixture. That gap cost M3-CP2b three attempts, all of which died in fixture construction upstream of any semantic seam.

   - A checkpoint may run a **diagnostic gate** (`<checkpoint>-DG`) that executes **only the checkpoint's own new identities**. It **must not** execute the frozen predecessor selector, and it is therefore structurally incapable of producing an acceptance claim.
   - A diagnostic gate **consumes no attempt**. It runs artifact-only against a real immutable package under the same immutability flags as any TB: no checkout, rebuild, relink, repair, generated discovery, or source/test/fixture mutation, with byte-identical package postflight.
   - **The same package may serve a diagnostic gate and then its acceptance TB.** Executing packaged binaries does not mutate the package. A green diagnostic followed by that package's acceptance TB is therefore **one attempt in total** — the diagnostic purely de-risks it. If the diagnostic is red, the fixture is corrected, which changes source and requires a **new** package with a fresh mandatory pre-package compile; no attempt was consumed.
   - **What a diagnostic gate proves and does not prove.** It answers one question: *did these identities reach their intended semantic seams?* A green diagnostic means those identities passed **in isolation** — it is not acceptance, because the predecessor selector was never run and predecessor safety is therefore unproven. It may never be cited as evidence that a checkpoint contract is satisfied, and a checkpoint may never be advanced, closed, or unblocked on diagnostic evidence.
   - **The result must name the seam each red identity reached**, so the gate actually discharges its purpose rather than reproducing an opaque failure.
   - **Cap: at most 2 diagnostic gates per checkpoint per attempt window**, resetting with the window when a mandatory review restores attempts. Each must be followed by either an acceptance attempt or a Review — diagnostic runs may not chain indefinitely.
   - Diagnostic packages count toward the reported cumulative package total like any other. That total is reported, not gated; the trade is deliberate, because packages are cheap relative to semantic evidence.

   Every mandatory review must re-derive the failure from source rather than from the previous review's text, **check the checkpoint's fixtures against the contract's non-trivial domain**, state one falsifiable prediction the next attempt tests, and enumerate the checks standing behind the fix that the failure has been masking. **This section 5 item 4 is the normative statement of the M3-M8 attempt regime; `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md` section 1.1.3 mirrors it.**

   This relaxes budget and adds one attempt-free evidence route. Everything else is unchanged: the mandatory separate exact-source pre-package compile, package immutability, artifact-only acceptance TB against the **full** frozen selector, "compile-green is not acceptance", the prohibition on shrinking a frozen selector, and the prohibition on merging independent semantic checkpoints to save an attempt.

5. **Static and runtime halves of one surface ship together.** A schema/static assertion proving an API or raw projection is unavailable and a runtime contract proving the behavior is absent are two witnesses of one fact. Unit-2 partials may stage directly-owned audit and behavioral contract source, but those witnesses ship together in the final batch package and receive semantic acceptance only in TB. Batch C may aggregate already-accepted A/B inventories into the global R-G.2 audit, but it must not reimplement or weaken their semantic authority.
6. **Partial CBs are build checkpoints, not acceptance checkpoints.** The user-authorized unit-2 exception permits only the exact `P-CB` -> `P-CB` edges tasklisted in `TODO.md`. Every partial compiles approved affected targets with `runtimeExecution=false`, executes no generated binary, leaves clean build-green source, and records the batch as unaccepted. The final partial performs complete batch reconciliation and packaging and must be followed by TB. The planned maximum partial counts are A = 4, B = 4, C = 5, and D = 3; adding a partial requires a planning amendment before code.

## 5.1 M1 exit gate — retained as the gate-authoring pattern

Retained because M2-M8 gates are written against this pattern and because sections 8, 9, and 11 carry forward obligations that reference criterion 5 directly. The M1-specific completion sequence, the R-C-through-R-G item definitions, the work-unit batching, the defaulted-authority sweep record, and the closed-complex witness disposition are all historical and now live in `M1_Closure_Record.md`.



M1 completion has been referenced throughout the migration without stated acceptance criteria. An undefined exit gate cannot be built toward, and discovering its requirements after R-C through R-G complete would produce a stall at the least recoverable point. The gate was defined before unit 1 began and remains the acceptance authority for the eventual fresh complete M1 package.

The fresh complete R-A-through-R-G package is accepted as M1 when **all** of the following hold on one uninterrupted immutable artifact-only run:

1. **Retained authority.** Every accepted R-A, R-B, and closed work-unit contract passes on the fresh package. No contract from a closed checkpoint is dropped, renamed away, or moved out of the selected set to obtain green.
2. **Unit contracts.** All contracts introduced by units 1-3 pass, each non-vacuous by the standing rule: a negative proves the guard it actually reaches, and a mutation contract requires the intended callback reached and the intended mutation performed.
3. **Static closure.** The regenerated audit inventory passes with classifier self-tests green, zero unexpected raw-projection leaves, zero unclassified `.index()` uses, and every banned symbol absent as a probe.
4. **Package integrity.** Self-excluding recursive manifest complete, zero symlinks, clean source-status snapshots, exact source archive, `runtimeExecution=false` at Code + Build, and immutable postflight showing package/executable state unchanged.
5. **Structural fixtures succeed strictly at their own semantic stage.** The three named structural fixtures must each reach their own terminal semantic stage with strict success — no fallback, no recovery, no generic substitution, no relaxed predicate, no typed rejection — with evidence recorded **per fixture, not in aggregate**.

   The fixtures are **heterogeneous**: two are phase-front producer witnesses, one is a simplification-stage consumer witness. Criterion 5 therefore maps required evidence to each fixture's actual stage.

   | Fixture | Semantic stage | Required evidence |
   |---|---|---|
   | **F1** — disconnected rectangular internal-midline hard-feature pair | phase-front producer | (a) `SurfaceCellProducerDisposition::Produced` and `is_produced()`; (b) strict source-authoritative validators pass with no typed rejection; (c) no fallback/recovery/generic substitution, `sourceGridRecoveryUsed` false; (d) complete lineage to final validation |
   | **F2** — planar uniform / periodic-annulus / curved-bounded-disk producer chain | phase-front producer applicability chain | (a)-(d) as F1, **plus** the ordered chain is honoured: each declining producer records a typed `NotApplicable` with its decline diagnostic, and no decline falls through to generic tracing/completion |
   | **F3** — closed 4x4 toroidal complex | **simplification consumer** — a directly constructed `SurfaceCellComplex` consumed by `extract_surface_simplification_candidates` | (a′) checked construction succeeds; (b′) `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` passes against the **full unrelaxed** eligibility predicate `!touchesHardFeature && !touchesBoundary && !touchesSingularity && !changesTopology && sideFeasible`; (c′) no predicate relaxation and no fixture special-casing; (d′) the result is recorded explicitly as a **directly-constructed witness**, never reported as pipeline-produced |

   For F1 and F2 the conjunction (a)-(d) is the criterion; a bare `Produced`, a GTest pass, exact counts, or hashes do not satisfy it individually.

   **Why F3 carries no producer clause, and why that is not a weakening.** `SurfaceCellComplex` carries no `SurfaceCellProducerDisposition`; `closed_toroidal_candidate_complex()` never calls `build_surface_cell_network`, and its sole required-green consumer calls `extract_surface_simplification_candidates`. Demanding producer disposition of it would require inventing authority M1 does not have — structurally the same error as demanding D0. F3's strictness bar **at its own stage** is the unrelaxed eligibility predicate, which is precisely the R-B closing contract and is already required-green inside the frozen 234-selector. Nothing is exempted; the bar is stage-appropriate.

   **Declared limitation for F3 (unchanged).** F3 is one of the three `G4-B002` produced-witness debts. It proves the extractor yields a compliant candidate given a well-formed closed complex; it does **not** prove the pipeline emits such complexes. M4 owns the re-proof (section 8). **Do not** resolve this by making F3 pipeline-produced inside M1 — that is `G4-B002`/M4 work and would import M4 into M1.

   **Authoring correction history.** This criterion has now been corrected twice, and both defects were the same shape: naming authority the gated scope does not have.
   - It first required disposition `Certified`/D0, which is an **M7** deliverable absent from the M1 implementation — unsatisfiable by construction.
   - It then applied one **producer-specific** conjunction uniformly to three fixtures, one of which never reaches a producer — unsatisfiable for F3.

   **Rule for any future gate criterion applied to a set of fixtures or components: state it per member at that member's own semantic stage.** A conjunction naming one stage's authority may not be applied to members that never reach that stage. Verify every named concept exists for every named member before freezing a gate.

   **M7 forward obligation.** When M7 implements D0-D4, it must re-express this criterion in disposition terms and re-run all three fixtures under verifier-assigned `Certified`, including a stage-appropriate disposition for F3. Rule 8 of section 2 becomes enforceable at that point. M7 does not close until that re-proof is green (section 11).

6. **Regression accounting.** Every observed regression is classified in `Regression_Root_Cause_Tracker.md` with root cause, and any change to the current stable **36 / 14 / 22** totals is explicitly justified by evidence.

**Declared M1 limitation — directly-constructed witnesses.** M1 closes with **five** contracts proven on directly-constructed typed authority rather than pipeline-produced witnesses, because two deferred blockers are correctly owned by later milestones:

- **3 blocked by `G4-B002`** (produced torus / shared rail schedule, revised M4) — the periodic and closed-complex identity contracts;
- **2 blocked by `G4-B003`** (nonzero periodic Z4 production, M5) — the full-periodic materializer contracts from unit-2 Batch D.

This is a stated limit on what M1 evidence establishes, not an oversight. Those contracts prove the invariants hold and that consumers handle typed authority correctly; they do **not** prove the production pipeline emits such authority. Re-proof is carried as named exit criteria of the owning milestones — M4 in section 8, M5 in section 9.

**Explicitly outside the M1 exit gate.** Representative production meshes (Bunny, Vase), quality thresholds, and resource/runtime budgets are **not** M1 acceptance criteria. M1 is an authority-correctness milestone; it does not claim production quality. Those become gates when the milestone that owns them is scheduled, and asserting them at M1 would either block the milestone on unrelated product defects or force a threshold to be invented without calibration data.

**Open dependency — `T5` calibration.** The `T5` quality/resource thresholds remain uncalibrated. They are a dependency of the *representative* acceptance matrix, not of the M1 exit gate above, and this separation is deliberate: it keeps M1 closable on evidence that exists, while keeping the uncalibrated thresholds visible rather than silently assumed. `T5` must be calibrated from measured baselines before any milestone asserts a quality gate.

## 6. M2 — CLOSED

M2 is closed on `M2-CP4-TB-R2` `32183306224 / 95861164621`, exact source/package `9fda64e88ddc885ce993ff8da3ad6a51765724a4 / 9340456431`, **275/275 required-green** with regenerated static **K=0**: eight scheduled stage products closed over typed `ProducerOutcome<Product, Failure>`, direct semantic context references **zero**.

Full record — CP0 census, five-checkpoint trajectory, the 11-package cost, recorded caveats, the open fixture-authority remainder, and durable lessons — is **`M2_Closure_Record.md`**, the M2 authority.

**Carried forward:** three latent fixture-authority sites and the un-removed `complete_surface_cell_complex(..., options = {})` default remain open and tracked in `TODO.md`. `surfaceCellContext` survives as a declared diagnostic surface with 23 snapshot fields carrying no semantic authority; closure claims that, not its removal.

## 7. M3 — field-aligned curve network

**Status: CP0 is compile evidence only; CP1, CP2, CP2b, CP3a, CP3b, and CP4ab are CLOSED / ACCEPTED.** Latest accepted runtime is CP4ab `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`, TB-R3 `32758293793 / 97530833220`, **316/316**. The V0–V8 corrections and full predecessor interaction are accepted. M3 package cost is **34**, stable accounting **42 / 14 / 28**, debt **5**; `PR8-R042` is resolved stable. Exact next is `M3-CP4c-CB`; CP4c adds six C identities and later gates at 322.

- Construct typed singularity ports from field index.
- Treat source boundaries and hard features as mandatory graph edges.
- Trace branch-consistent field-aligned curves intrinsically across source triangles, combinatorially rather than by nearest-direction integration.
- Terminate only at typed network events; record intersections as explicit nodes.
## 8. M4 — global conformity plan

- Compute one strictly positive shared rail schedule globally before regional production.
- Use a deterministic polynomial graph/flow formulation for shared counts/constraints.
- Resolve `G4-B002` exact-torus `InvalidHardRailPairing` without post-hoc local pairing.
- Infeasible subsets become typed inputs to later disposition logic; they do not authorize ad-hoc local substitution.

**M4 exit criterion — inherited produced-witness debt.** M4 does not close until all **three** contracts decoupled from produced witnesses by `G4-B002` are re-proven on pipeline-produced witnesses:

1. `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` on a produced closed complex (from R-B);
2. `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` through the torus pipeline (from R-B);
3. `MissingPeriodicRelationOwnerIsRejected` on produced periodic authority rather than `direct_periodic_owner_product()` (from R-C).

This criterion exists because the debt was incurred by deferring `G4-B002` out of M1; recording it only as a task leaves nothing to enforce it. Re-proof means the contract's original intent is re-established on the produced witness, not that a passing assertion is produced by some other route.

**The `G4-B002` ledger stands at 3 and did not grow during unit 2.** The section 14 reopen trigger is therefore not fired.

### Produced-witness debt is tracked per blocker

The original stop rule — "a fourth debt reopens `G4-B002` scheduling" — was written when only one blocker was generating debt. It mis-fires as stated: unit 2 added two debts owned by **`G4-B003`**, and reopening `G4-B002` scheduling would do nothing for a `G4-B003`-blocked contract. The rule is corrected to operate **per blocker**, with each ledger enforced at the milestone that owns that blocker's remedy.

| Blocker | Owning milestone | Debt | Reopen trigger |
|---|---|---|---|
| `G4-B002` shared positive rail schedule | revised M4 | **3** | a 4th `G4-B002` debt reopens section 14 scheduling |
| `G4-B003` nonzero periodic Z4 production | M5 | **2** | a 3rd `G4-B003` debt reopens M5 scheduling |

**Total produced-witness debt: 5 contracts.** Work-unit-2 closure recorded this as unchanged at 3, which undercounted the two Batch-D decouplings. The count error did not affect any acceptance decision and no gate was mis-credited; it is corrected here. Detail in `Unit_2_Closeout_Record.md` — RETIRED at M1 closure; consolidated in `M1_Closure_Record.md` section 5.

Any turn that decouples a contract from a produced witness must add it to the owning blocker's ledger in the same turn. A decoupling that is individually correct is still debt.

## 9. M5 — certificate-carrying chart and quotient relations

- Retain selected relation paths, explicit owners, and independently verifiable certificates.
- Preserve nonzero periodic Z4 evidence where required.
- Produce positive multi-isolation quotient evidence where required.

**M5 exit criterion — inherited produced-witness debt.** M5 does not close until both contracts decoupled from produced witnesses by `G4-B003` are re-proven on pipeline-produced nonzero-Z4 periodic authority rather than `direct_full_periodic_materializer_draft()`:

1. `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` (from unit-2 Batch D);
2. `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` (from unit-2 Batch D).

Both currently prove the materializer **consumes** nonzero-Z4 authority correctly. Neither proves the producer **emits** it — that capability is `G4-B003`, which M5 owns. This criterion mirrors M4's and exists for the same reason: a debt recorded only as a task has nothing enforcing it.
- Separate certificate authority from compact numeric/index representations.

## 10. M6 — occurrence, embedding, and independent verification

- Separate occurrence, quotient, embedding, and verifier products.
- Establish a correct-by-construction injective region-interior baseline.
- Verify geometry, field alignment, topology, and quality from independent source/product authority.
- Do not make output hashes or emitted ordering the semantic oracle.

## 11. M7 — disposition and graded degradation

Implement verifier-assigned dispositions D0-D4:
- D0 Certified;
- D1 QualityRelaxed;
- D2 LocallyDegraded;
- D3 Partial;
- D4 DiagnosticOnly.

Strict fixtures require D0. The one declared degraded producer must be bounded, non-recursive, pure-quad, manifold, and conform to the unmodified boundary plan. `DESIGN.md` section 6.7 must consistently require a quality-degradation record when D1 is caused by missed quality gates.

**M7 inherits the criterion-5 forward obligation.** M1's exit gate could not require `Certified`/D0 because disposition tiers are implemented here, not there; M1 closes on the M1-available equivalent in section 5.1 criterion 5. When D0-D4 exist, M7 must re-express that criterion in disposition terms and re-run the three named M1 structural fixtures under verifier-assigned `Certified`. **M7 does not close until that re-proof is green.** This mirrors the produced-witness debt criteria in sections 8 and 9: an obligation deferred out of an earlier milestone is enforced as an exit criterion of the milestone that can discharge it.

## 12. M8 — module boundaries and operational hardening

- Stabilize product/module APIs around the accepted authority graph.
- Bound memory/runtime ownership and preserve deterministic scheduling-independent identity.
- Keep diagnostics/evidence sufficient to classify the earliest failing producer/consumer seam.
- Harden packaging, reproducibility, and representative acceptance matrices.

## 13. Pipeline A activation rule

Do not schedule decomposed coordinate integration until Pipeline B is Certified on the complete representative matrix with calibrated stable quality gates and evidence that integration would materially improve quality. Pipeline A is not an escape hatch for unresolved Pipeline B authority/topology defects.

## 14. Product blockers retained outside M1-M2

- `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch`.
- `G4-B002`: exact torus `InvalidHardRailPairing`; owned by revised M4. Scheduling reviewed and **confirmed deferred**, with the deferral priced — see below.
- `G4-B003`: nonzero periodic Z4 capability; owned by M5.
- `G4-B004`: positive multi-isolation quotient witness; owned by M5/M6.
- Bunny/Vase representative production and resource acceptance remain later product gates.

### `G4-B002` scheduling review — decision resolved before unit 2

`G4-B002` is nominally an M4 product defect, but it has now forced the same evasion in two consecutive R-B contracts, and the evasion cost is accruing inside M1 rather than M4:

- `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` had to be decoupled from `torus_fixture()` because that fixture throws `InvalidHardRailPairing`, and now proves its invariant on directly-constructed topology instead of a produced witness.
- `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` rests on a hand-constructed closed toroidal complex because no produced closed witness is reachable.

Both decouplings were individually correct — an identity invariant must not report an unrelated deferred defect. The concern is the pattern: every later checkpoint wanting a produced closed-complex witness will hit the same wall and take the same workaround, and each one converts a produced-witness contract into a directly-constructed one. A defect that repeatedly determines what evidence other milestones are able to produce is functioning as infrastructure, not as a deferred product defect.

**Resolved: keep `G4-B002` in revised M4, and price the deferral.** The scheduling question was opened as genuinely open; examining the recorded root cause closes it. Three pieces of evidence agree:

1. `Regression_Root_Cause_Tracker.md` line 469 records the remedy as **"shared positive rail schedule; revised M4."** The shared positive rail schedule is not incidental to M4 — it is M4's core deliverable (section 8).
2. Section 8 already requires resolving `G4-B002` **"without post-hoc local pairing."** A fix inside M1, where no global rail schedule exists yet, would almost certainly be the local pairing repair that constraint forbids.
3. `DESIGN.md` section 3's failure cycle is precisely this shape: a local repair made to turn a witness green becomes an authority the next milestone must dismantle. Pulling `G4-B002` into M1 to unblock two test witnesses is that cycle's first step.

`G4-B002` is also the wrong *kind* of defect for M1. M1 is authority-correctness; `G4-B002` is a product/algorithm defect requiring a global scheduling formulation — M4-sized work, not checkpoint-sized. Scheduling it ahead of unit 2 would either import M4 into M1 or produce a repair that M4 tears out.

What was genuinely wrong was not the deferral but its pricing: the debt was recorded in `TODO.md`, where nothing enforces it. Two amendments make the deferral honest:

- **Section 5.1 records the limitation explicitly.** M1 closes on directly-constructed witnesses for the periodic and closed-complex identity contracts. This is stated as an M1 limitation, not discovered at gate time.
- **M4 carries the re-proof as a named exit criterion** (section 8). M4 cannot close without re-proving both R-B contracts on pipeline-produced witnesses. The debt is attached to the milestone that can actually discharge it, so it cannot quietly evaporate.

If work unit 2 or unit 3 enumeration shows a new requirement for a pipeline-produced closed witness, that is new evidence and reopens this decision — but the two already-priced R-B witness debts are not sufficient cause to import M4 into M1.

Historical regression totals remain **34 events / 14 categories / 20 recurrences**.
