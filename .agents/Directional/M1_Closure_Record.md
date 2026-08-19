# M1 Closure Record — Single-Authority Contract Cutover

**Status:** **CLOSED** on the immutable full-M1 artifact-only exit gate.
**Accepted exact source / package:** `8232216a66020d440e5a6400b61904ca0430b6c1` / `9293593175` (SHA-256 `f68f76d3fd40216e5f7bb5ce8a666b58053c0383f64c77e493c2dd5e9fba917b`)
**Accepting runtime:** run/job `32055365696 / 95464163035` — **234 / 234 required-green PASS**, owner partition **19 authority / 138 producer / 36 completion / 41 validation**
**Runtime evidence:** result `9296299890` SHA-256 `0b3fe72d1a06524e21516dff6d120f9526c0a699b1169a24d8bf5db14fc260f8`; log `9296300150` SHA-256 `00617936d5628942febdb24616afb373d7610960fda25ec637d55e51d5069aa4`
**Frozen selector:** 234 identities, SHA-256 `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687`
**Stable regression totals at closure:** **36 events / 14 categories / 22 recurrences**
**Produced-witness debt carried forward:** **5** (`G4-B002` = 3 → M4; `G4-B003` = 2 → M5)

This is the single durable historical record for M1. It supersedes the per-checkpoint closeout records and all per-turn M1 plans and reports.

## 1. What M1 required

Replace representation-coupled authority with typed single-writer authority: one semantic authority per fact; closed producer outcomes; consumers that validate or remap but never reconstruct semantics; exact source ownership; canonical identity reconstruction; hard features and boundaries as mandatory topology authority; and independent verification that never derives expected state from the output being validated.

## 2. Checkpoint trajectory

| Checkpoint | Surface | Accepted source | Runtime | Result | Attempts |
|---|---|---|---|---|---:|
| **R-A** | single-authority transport/cutover | `588a58935b481943eea9f8424e9897d6a1a44454` | `31808562013 / 94793328201` | **112/112** | 16 |
| **R-B** | row-independent face/support/chart identity | `2e61dafa4da600608b5b1281d16085d04caeb135` | `31851663979 / 94928457628` | **20/20** | 4 |
| **R-C + R-G.3/G.4** | closed published products and certificates | `ec8b3125a62a02f4106599f089d12e7d1c0ccfcb` | `31865263629 / 94965185949` | **67/67** | 4 |
| **Unit 2** (R-D.4+R-G.2, R-D.5) | numeric-projection closure, typed `GridAutomorphism` | `37adb93e66385b80199c3f748f4a2e9f1ded06dd` | `31964571034 / 95207639154` | **23/23** (D) | 7 of 8 |
| **Unit 3** (R-E, R-F, residual R-G) | typed owners, compile contracts, audit closure | `8d8e0673929349919b6bea9022772b2a6831f892` | `32037616872 / 95411065157` | **234/234** | 6 of 8 |
| **M1-FULL** | fresh complete package + six-criterion exit gate | `8232216a66020d440e5a6400b61904ca0430b6c1` | `32055365696 / 95464163035` | **234/234** | 1 |

**Cost calibration — the durable planning output.** Cost tracks **independent semantic domains per checkpoint**, not files, not lessons transferred. Single-domain batches (unit-2 A/B/D, unit-3 F/G) cost 1-2 attempts. Multi-domain batches cost 3-4 even after mid-flight splitting: unit-2 Batch C spanned six layers and cost 3; unit-3 Batch E grouped five typed-ID domains and cost 4 of that unit's 6. Size checkpoints by domain count and decompose **before** starting.

## 3. Final gate — six criteria, all PASS

1. **Retained authority / exact selector.** All eleven accepted required-green sets independently reconstructed from immutable checkpoint artifacts; `union(all eleven) == accepted Batch-G 234-set == frozen selector`, 0 missing.
2. **Unit contracts / non-vacuity.** 234 selected, executed, passed; 0 fail/skip/missing; all four owner processes exit 0. Non-vacuity remained owned by the contract bodies, not replaced by aggregate counts.
3. **Regenerated static closure.** `K=0` across all eight domains: R-A cuts, R-B row identity, R-C products, unit-2 numeric projection, unit-2 `GridAutomorphism`, R-E typed owners, R-F obligations, Batch-G source-edge/residual R-G.

### Live audit authority — `C-R2-06` packed source-edge key disposition

Retained here because later static closures must respect it. Batch G closed `C06-01`..`C06-12` as forbidden. The two survivors are **classified allowed leaves, not deferred debt**:

| Site | Classification | Basis |
|---|---|---|
| `C06-13` — periodic route compact-ID oracle (`packedCurrentTopologyForCompactId`, `compactByTopology` in `tests/SurfaceCellsPhase10Tests.cpp`) | `LOCAL_REPRESENTATION_LEAF` | assigns/looks up an independent compact integer oracle only; never compared to produced typed route authority, never decoded into semantic ownership |
| `C06-14` — one-way determinism hashing of the raw boundary-run topology payload (`SurfaceCellTracing.cpp` boundary hash, `RemeshPipeline.cpp` context hash) | `ONE_WAY_EXPORT_LEAF` | hash consumption is one-way diagnostic/export and does not recover source-edge authority; the underlying persistent raw field is separately forbidden by `C06-04` |

**Any evidence that either leaf decodes back into authority or persists as a competing owner requires a planning amendment before mutation.**
4. **Package integrity.** 26 files / 25 self-excluding manifest entries, 550-member source archive, five clean source snapshots; postflight `package_mutated=false`, with `rebuild`/`relink`/`packageRepair`/`sourceMutation`/`testMutation`/`fixtureMutation` all false.
5. **Structural fixtures succeed strictly at their own semantic stage.** See section 4.
6. **Regression accounting.** Every observed red was pre-semantic orchestration (`M1-FULL-TB-CAND-02` corrupted control transfer; `-CAND-03` auth forwarded through an artifact cross-host redirect). No product regression; totals unchanged.

## 4. Criterion 5 — corrected twice, and why it matters

Criterion 5 was authored defectively **twice**, both times the same shape: **naming authority the gated scope does not have.**

- **First defect:** it required disposition `Certified`/D0. `DispositionTier` and `OutputDisposition` exist nowhere in the M1 implementation; D0-D4 are an M7 deliverable. The criterion was unsatisfiable by construction and would have deadlocked M1 permanently.
- **Second defect:** the restatement applied one **producer-specific** conjunction uniformly to three heterogeneous fixtures. The closed 4x4 toroidal complex is a directly constructed `SurfaceCellComplex` consumed by `extract_surface_simplification_candidates`; it has no `SurfaceCellProducerDisposition` and never calls `build_surface_cell_network`, so the producer clause was unsatisfiable for it.

Both times `M1-FULL-TB` stopped **fail-closed pre-semantic** rather than reinterpret evidence — the correct behaviour, and the reason neither defect became a false green.

Final accepted form is **per fixture, at each fixture's own semantic stage**:

- **F1** disconnected rectangular internal-midline hard-feature pair — *producer stage*: disposition `Produced` + `is_produced()`, strict validators with no typed rejection, no fallback/recovery/substitution, complete lineage. **PASS.**
- **F2** planar uniform / periodic-annulus / curved-bounded-disk chain — *producer applicability chain*: as F1 plus ordered typed `NotApplicable` control with decline diagnostics and no generic fallthrough. **PASS**, all five named contracts.
- **F3** closed 4x4 toroidal complex — *simplification consumer stage*: checked construction, `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` against the **full unrelaxed** predicate `!touchesHardFeature && !touchesBoundary && !touchesSingularity && !changesTopology && sideFeasible`, no relaxation or special-casing, and `pipeline_produced_claim=false` recorded explicitly. **PASS.**

**Rule extracted:** a gate criterion applied to a set of members must be stated **per member at that member's own semantic stage**; a conjunction naming one stage's authority cannot apply to members that never reach it. Verify every named concept exists for every named member before freezing a gate.

## 5. Declared limitations — what M1 closure does *not* claim

1. **Five contracts are proven on directly-constructed typed authority, not pipeline-produced witnesses.** Three blocked by `G4-B002` (produced torus / shared rail schedule → revised M4), two by `G4-B003` (nonzero periodic Z4 production → M5). They prove the invariants hold and that consumers handle typed authority correctly; they do **not** prove the pipeline emits such authority. Re-proof is enforced as named exit criteria of M4 and M5.
2. **Criterion 5's disposition form is deferred to M7**, which must re-express it under verifier-assigned `Certified` for all three fixtures and cannot close until that re-proof is green.
3. **No production-quality claim.** Representative meshes (Bunny, Vase), quality thresholds, and resource budgets were explicitly excluded from the M1 gate. M1 is an authority-correctness milestone. `T5` thresholds remain uncalibrated and gate the representative acceptance matrix, not M1.
4. **Open hygiene remains open.** The frozen exclusion register retains 17 executable non-gating hygiene identities, 3 non-selector R-A hygiene records, and 4 R-F exclusions-by-design. None is required-green evidence, and each stays tracked in `TODO.md`.

## 6. Durable lessons

- Compile and static success are never semantic acceptance.
- A negative proves only the guard it actually reaches; a mutation contract is evidence only when the intended seam is reached and the intended mutation provably occurs.
- Verify the *mechanism* before naming a root cause. A plausible symptom explanation is not a diagnosis.
- **A defaulted-optional parameter for mandatory authority is a defect generator.** Repairing one signature does not close the class — enumerate every site sharing the shape.
- **Prefer site-set closure over retrospective probes.** R-A's decisive unblock was one command enumerating nine construction sites, after nine retries of instance-by-instance discovery.
- **Enumerate before editing, and bound the class before repairing any instance.**
- One member carrying two semantic domains is a single-authority violation, even inside a test fixture.
- A typed migration can turn a contract red with no production defect; check whether the typed member means the same thing as the raw one it replaced before touching either.
- Consolidating scattered raw conversions into one checked fail-closed converter beats deleting them individually — one auditable boundary instead of N sites.
- **An audit passing means the family was in scope, not that the family is closed.** Record out-of-scope projection families as explicit decisions.
- TB retries against the same immutable package are not package attempts; orchestration failure has a signature (mass failure of unrelated tests from one shared cause).
- Excluding a failing identity from required-green needs a three-part proof: the checkpoint did not change it, it was already red for a recorded independent reason, and its static migration evidence is retained.
- **A milestone-crossing obligation belongs to the milestone that can discharge it, as an exit criterion** — not to a task list, which has nothing enforcing it.
- **Do not author a gate criterion in terms the gated milestone's implementation cannot express.**

## 7. Superseded by this record

`R_A_Closeout_Record.md`, `R_B_Closeout_Record.md`, `R_C_Closeout_Record.md`, `Unit_2_Closeout_Record.md`, `Unit_3_Closeout_Record.md`, `Architecture_M1_Full_Static_Closure_Report.md`, `Architecture_M1_Full_Selector_Reconciliation_Report.md`, `Architecture_M1_Full_Package_Freeze_Report.md`, `Architecture_M1_Full_Artifact_Only_Test_Benchmark_Report.md`, `Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md`, `Architecture_M1_RB_Row_Identity_Artifact_Only_Test_Benchmark_Plan.md` and `..._Report.md`, `Architecture_M1_RC_Artifact_Only_Test_Benchmark_Report.md`, `Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md`, and `Architecture_Redesign_and_M1_RA_Independent_Review_Report.md` are retired into this record.

Live artifacts retained outside it: the frozen selector `M1_Full_Required_Green_Selector.txt`, the durable auditor `tools/audit_m1_full_static_closure.py` and companion audit tools, `Regression_Root_Cause_Tracker.md`, `CHANGELOG.md`, and immutable GitHub artifact history.
