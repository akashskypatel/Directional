# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-CB23`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime authority** | **`M3-CP4c-3-TB20`** — source `c5d3c65936e14e1c3e2c8afcffbc4236f37aa131`, run/job `33809177155 / 100826787667`, **380 PASS / 8 RED** |
| **Current semantic source** | **`fa5646106ccaa23770b84a935c6d1d6007928640`** — CB23 diagnostic/test-only source, runtime not yet executed |
| **Current gate selector** | `Architecture_M3_CP4c3_Required_Green_Selector_391.txt`, **391 identities**, `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`; selector 385 (388 identities) and accepted 365 exact prefixes |
| **Compile/package authority** | run `33815475590`, package job `100847694307`, artifact `9916511617`, digest `sha256:8378a108811740cff5fd1a0fc9db66f9e3334d7048ea9e7c7d6e8e1cbd852050`, GMP/GMPXX, `runtimeExecution=false` |
| **TB20 artifacts** | result/log `9914226104 / 9914226799` |
| **TB20 ledger** | `0a4d8b17abd4e397bb80ff0fa92b70bc50e971589e368d1cdf2ecef85868203a` — 380 + 8 = 388 |
| **First runtime red** | ordinal **366**, `UncutFaceComponentOrbitSeedNotUnique`, component **0**, `seedState=Multiple`, seed count **3**, seed orbits **`[0,1,3]`** |
| **TB20 red set** | 366, 367, 368, 369, 370, 371, 372, 374 |
| **TB20 package census** | pre/post identical, `f0b1beec127dacbec9b356630ce8d9e7364de55a5b014598ee67fcdab653c5b0` |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **86** |

> **Selector naming.** Every selector file 357–384 is named by its identity count. The frozen file named **385**
> is the one historical exception and contains **388** identities; do not rename it or derive a count from its
> filename. CB23 restores the convention: selector **391** is named by its **391** identities.
> `Required_Green_Selector_Manifest.md` indexes counts, LF hashes, prefix parents, appended identities and roles.
> **Selector files are never consolidated** (`RETENTION_POLICY.md`).

---

## 2. The current frontier — the guard is normative and there is nothing to fix at it

TB20 confirms CB21 remains settled: accepted 1–365 are 365/365, the red set is unchanged, ordinal 384 stays green,
and 366/367/371/372 still reach the component-seed frontier rather than `TraceCutFaceFragmentCountMismatch`.
CB22's four diagnostic identities 385–388 all pass.

**The branch is measured.** Ordinal 366's retained production evidence gives `uncutFaceComponent=0`,
`seedCount=3`, `seedState=Multiple`, `sourceFaceLocusKind=FirstUnlabeledFaceInIterationOrder`, and the component
census `faceCount=191, seedOrbits=[0,1,3], seedOrbitsTruncated=false`; the global census has 9 rows, untruncated.
The retained 64-row boundary window splits 46 `none` (all seeding: 44 × orbit 0, 1 × orbit 1, 1 × orbit 3) and 18
`traceTouched` (all skipped); owner counts 47 × 1 and 17 × 2; 64/97 boundary rows and 64/191 face rows retained and
marked truncated.

**`M3-CP4c-3-TB20-REV` adjudicated it under CW0–CW9**
(`Architecture_M3_CP4c3_TB20_Independent_Review_Record.md`):

- **Normative authority already ruled on this exact line, and ruled it correct.**
  `M3_CP4c_Frozen_Definitions.md` **Part I §3**: the rule "requires each resulting component to receive **exactly
  one** orbit seed from its labeled neighbours … **The error code is correct and the producer is behaving
  correctly. There is no bug at that line.** It is reporting a missing input." The missing input is that **the
  field-aligned network is not a cut graph of its surface**. **Parts IV and V** prohibit relaxing
  `proves_cellularity()`, the fragment-count invariant, or this guard; **Part VI** is vertex-star scoped and lifts
  none of them. **No correction is authorized at the guard.**
- **New information: the class now appears on a genus-0 witness.** Part I proved it for the torus from `χ = 0` and
  `E = V = 48`. The mechanical witness is closed with **χ = 2**, where that argument does not apply, and reaches
  the same class by an unmeasured route.
- **The bounded boundary evidence is sufficient; the missing datum is different and far smaller.** The 33
  unretained rows cannot change the disposition — `seedOrbitCount=3` is explicitly untruncated and more rows could
  only add orbits. What is missing is the **embedded graph's own `V`, `E` and connected-component count**, which
  decide cellularity by `V − E + F = χ` exactly as Part I decided the torus. TB19's "26 arcs" is the fragment-owner
  trace-arc census, not the graph's `E`. **No further boundary retention is warranted.**
- **The torus and mechanical occurrences stay separate candidates**, linked as two instances of one architectural
  class.
- **Escalated for a definition-level turn:** `M3-CP4c3-TB20-REV-CAND-02` — CB21 weakened the fragment-count
  invariant, which Parts IV and V prohibit, and TB18-REV authorized it without consulting those lists. **Not
  reverted** here; CW5 binds this review's successor to preserve CB21.

---

## 3. Exact next turn — `M3-CP4c-3-TB21`, artifact-only

CB23 is closed by `Architecture_M3_CP4c3_CB23_Code_Build_Report.md`. The executable contract is frozen in
`Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Plan.md`.

- consume only immutable package `9916511617` from semantic source `fa5646106ccaa23770b84a935c6d1d6007928640`;
- verify selector 391 `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`, predecessor 385 and accepted 365 before runtime;
- execute all **391 identities one per fresh process**; no configure/compile/relink/discovery/package repair/source-test-fixture-selector mutation;
- require accepted **1–365 = 365/365 PASS**;
- require ordinal 366 to stay on the same normative `Multiple(3)` seed-uniqueness frontier;
- retain the mechanical embedded-graph `V/E/F/componentCount/χ/residual` and per-orbit boundary attribution;
- make 371/372 execute their existing assertions through the atlas-only fixture and record whatever they actually prove;
- execute appended 389–391 and preserve torus/prescribed-sphere comparison evidence;
- preserve byte+mode package identity and classify every observed red before closeout.

If the Euler residual confirms non-cellularity, the next decision turn is **`M3-CP4c-3-DEFN`** — `DEFN` absorbs
review+plan and owns both the cut-graph construction requirement and `M3-CP4c3-TB20-REV-CAND-02`. A contradictory
Euler result or movement of ordinal 366 routes to **`M3-CP4c-3-TB21-REV`** instead. No Code + Build successor is
pre-authorized.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB20-REV-CAND-01` | **NEW / ACTIVE / ARCHITECTURAL / GATING** — the field-aligned network is not a cut graph of its surface, on a **genus-0** witness. Second instance of the class Part I proved for the torus, by a route that proof does not cover. Owner: BW1–BW3, then a definition-level turn. |
| `M3-CP4c3-TB20-REV-CAND-02` | **NEW / ACTIVE / GOVERNANCE** — CB21 weakened the fragment-count invariant, which Parts IV and V prohibit; TB18-REV authorized it without consulting those lists. Not reverted. Owner: the definition-level turn. |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / SYMPTOM RECORD** — branch resolved as `Multiple(3)`; reclassified under `M3-CP4c3-TB20-REV-CAND-01`. The guard is correct and must not be relaxed. |
| `M3-CP4c3-TB10-REV-CAND-01` | **TRIGGER FIRED / DECOUPLING AUTHORIZED** under BW7. Closes when TB21 measures 371/372's own contracts. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED** — a universal non-crossing invariant is refuted by `TraceIntersection` contact nodes; closure requires `localFragments = k + 1 + interiorCrossings` on a crossing witness. **Must not be promoted to fatal.** |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. No atlas invariant may be weakened for it. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared bound on its input size. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed:** `M3-CP4c3-TB19-REV-CAND-02` (satisfied at TB20 — CB22 retained the discriminator and
`sourceFaceLocusKind`), `M3-CP4c3-TB17-CAND-01`. The historical torus
`UncutFaceComponentOrbitSeedNotUnique` record is **linked, not merged**, as the genus-1 instance of
`M3-CP4c3-TB20-REV-CAND-01`. Other closed candidates remain closed unless new immutable runtime evidence reopens
them.

---

## 5. Settled facts a successor must not reopen

- **`M3_CP4c_Frozen_Definitions.md` Part I §3 is normative and directly on point:** the seed-uniqueness guard is
  correct, the producer is behaving correctly, there is no bug at that line, and multiple seeds report a **missing
  input**. **Parts IV and V prohibit relaxing** `proves_cellularity()`, the fragment-count invariant, or that
  guard; Part VI lifts none of them. **Read the prohibited lists before authorizing any correction.**
- **Cellularity is decided by `V − E + F = χ` per connected component of the embedded graph.** Part I settled the
  torus with `V = E = 48`, `χ = 0` ⇒ `F = 0`. The mechanical witness has `χ = 2` and `F = 6`; its `V`, `E` and
  component count are the missing datum.
- **The current mechanical branch is `Multiple`, not `None`:** component 0, 191 faces, seed orbits `[0,1,3]`.
- **The reported `sourceFace` is an iteration artifact**, now explicitly typed as such.
- **A universal chord non-crossing invariant is refuted**; `localFragmentCount` must not become a fatal oracle
  without the crossing derivation and a crossing witness.
- The face walk is a validated total permutation; its orbits are its cycles. Shared orbit ownership by the two
  sides of one arc is legitimate topology. **BS9-5 remains retired.**
- Identical typed error names across witnesses do not establish identical root cause.
- **CB21 is preserved by this review's successor**, but its authorization is formally in question under
  `M3-CP4c3-TB20-REV-CAND-02`; only the definition-level turn may resolve it.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first.
2. **this file** — current state, frozen successor, candidate index.
3. `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Plan.md` — **exact TB21 execution contract**.
4. `Architecture_M3_CP4c3_CB23_Code_Build_Report.md` — current semantic/build authority; then
   `Architecture_M3_CP4c3_TB20_Artifact_Only_Test_Benchmark_Report.md` for the preceding immutable runtime authority.
5. `M3_CP4c_Frozen_Definitions.md` — **Part I §3** (the normative adjudication of this guard and the cut-graph
   theorem), **Parts IV and V** prohibited lists, **Part VI** for vertex-star definitions.
6. `GMP_COMPILE_POLICY.md` — mandatory for every compile.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed; its **folded document index**
   resolves every folded or retired per-turn plan, report and record.
9. `Required_Green_Selector_Manifest.md` — when any selector's count, hash, prefix parent or role is in
   question.

**Review tooling.** `.agents/Directional/tools/` holds read-only helpers: `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes and ordinal ↔ identity lookups, and
`fixture_probe.py` for fixture topology, dihedrals and vertex fans. See `tools/README.md` for the caveats — in
particular that geometric sharpness is not the product's barrier set, and that the singularity reconstruction is
corroboration only.

**Document consolidation.** Every REVIEW turn folds its superseded per-turn documents into
`M3_CP4c_Consolidated_Record.md`'s folded document index under `CLEAN_UP_POLICY.md` §"Document consolidation —
every REVIEW turn", **and indexes anything a CB or TB turn's stale-evidence cleanup retired between reviews**.
Preserve durable facts in a retained record first; never fold current authority, normative definitions, policies
or selector files.
