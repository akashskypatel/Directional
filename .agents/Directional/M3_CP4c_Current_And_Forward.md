# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-CB24` closeout.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.** CB24 is compile-green and runtime-free; TB21 therefore remains the current runtime authority.

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime authority** | **`M3-CP4c-3-TB21`** — source `fa5646106ccaa23770b84a935c6d1d6007928640`, run/job `33818038269 / 100854435211`, **384 PASS / 7 RED** |
| **Current gate selector** | selector **393**, **393 identities**, `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`; frozen selector 391 exact byte prefix |
| **Compile/package authority** | **CB24** source `d69729a69a40b020968ed6ef1fbc1bc788284518`; run/job `33823590494 / 100871347582`; artifact `9919225745`, `sha256:7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`; GMP/GMPXX; `runtimeExecution=false` |
| **Compile log artifact** | `9919226113`, `sha256:a9efadb18ace1feb1e1df156d561573da4cdfead642d168cc88eb7c09c5b05a9` |
| **Packaged source archive** | `34d938298466d4be9b73a6034d1ed21230104c6634a1dfaa82b2ab71f81fa704` |
| **TB21 artifacts / ledger** | result/log `9917317234 / 9917317654`; ledger `8606fb7ba5673e6d3b45b5055f7744559b29a79d5caa8d0df76da85920aa6f77` |
| **First red** | ordinal **366**, `UncutFaceComponentOrbitSeedNotUnique`, component **0**, 191 faces, `seedState=Multiple`, seed orbits **`[0,1,3]`** |
| **TB21 red set** | 366, 367, 368, 369, 370, 374, 391 |
| **Mechanical Euler census** | `V=22, E=26, F=6, componentCount=1, χ=2, residual=0` — actual embedded complex is certified **cellular** |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **87** |

Selector 391 remains byte-frozen at `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0` and is an exact
byte prefix of selector393. Ordinals 392/393 are the only appended identities. Selector files remain independent
byte-frozen witnesses and are never consolidated.

**371 and 372 remain closed/runtime-proved by TB21.** CB24 did not execute them or any other runtime identity.

---

## 2. The current frontier — a projection, not a missing cut graph

### The prior review correction that remains binding

**`M3-CP4c-3-TB20-REV` concluded the mechanical network is not a cut graph. That conclusion is WITHDRAWN.** The
Euler census it ordered proves the actual embedded complex is **cellular**: `V=22, E=26, F=6, componentCount=1,
sourceChi=2, residual=0`, with every face certified a disc by `proves_cellularity()`.

`M3_CP4c_Frozen_Definitions.md` **Part I §3 is an implication with a premise**: it establishes non-cellularity for
the torus independently, from `V = E = 48` and `χ = 0` forcing `F = 0`, and only then concludes "not a cut graph."
TB20-REV applied the conclusion without carrying the premise. **There is no normative conflict between documents** —
the conflict was with a misreading, and `proves_cellularity()`, the fragment-count invariant and the seed guard are
not weakened by this review.

### What survives, stated correctly

**The two constructions count different objects, and neither validates the other.**

- `certify_actual_embedded_graph` + `proves_cellularity()` (`SurfaceCutGraph.cpp:451,478`) count nodes, arcs and
  face-walk orbits of the **embedded graph on the surface**. Its faces are regions bounded by arcs running through
  triangle interiors, and every one must satisfy `proves_disc_topology()`.
- `GlobalTopologyPlan.cpp:1102–1165` joins whole **uncut source triangles** across source edges not in
  `componentBarriers = mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`.

The second is a **coarsening/projection** of the first, faithful only under a condition neither states nor checks:

> Every pair of adjacent uncut source triangles lying in **different** certificate faces must be separated by an
> edge in `componentBarriers`.

Cellularity does not imply it. **That unvalidated projection is the real defect surface** —
`M3-CP4c3-TB21-CAND-01`.

### Two readings, opposite corrections

Component 0's complete, untruncated boundary attribution over **97** edges: orbit 0 → **81**, orbit 1 → **1**,
orbit 3 → **1**, plus **14** barrier/no-seed. One dominant orbit and two single-edge outliers. Either those two
edges genuinely separate certificate faces and the barrier set is missing them, or two seed reads are wrong at
`:1130–1140`.

**The deciding rows already exist in the artifact.** TB20's first-64 window showed 44/1/1 and TB21's complete
census shows 81/1/1, so **both minority rows lie inside the retained window** — edge key, owner count, barrier
class and seed all captured, then summarized into counts by the report. **No new geometric witness or wider cap is required.** CB24 implemented retention/projection by *distinctness* and TB22 now re-executes the same production path through that diagnostic schema. Raising the 64/97 cap remains the wrong fix.

### Ordinal 391

A **self-inflicted diagnostic RED**: its prescribed-sphere half needs `sphere.cutGraph` and hits the already-owned
368 surface, because TB20-REV's BW4 required one census witness to span all three witnesses. CB24 BY7 re-scoped it. TB22 must prove the mechanical/torus halves no longer RED solely because the sphere half lacks `cutGraph`. It touches no sphere product surface and creates no new stable category.

---

## 3. Exact next turn — `M3-CP4c-3-TB22`, artifact-only

Execute `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Plan.md` against immutable CB24 artifact
**9919225745** and selector393. The turn is runtime validation only: no source/test/fixture/selector/build mutation and
no configure, compile, relink, regeneration, package repair, generated binary discovery or benchmark execution.

Load-bearing checks:

- run all **393** identities in ordinal order, one fresh process per exact identity;
- accepted ordinals 1–365 must remain **365/365 PASS**;
- ordinal 366 must remain the same seed-state surface and publish both full minority rows, seed rules and certificate
  side attribution;
- publish the exact **projection-faithfulness residual** and witness rows without assuming zero or non-zero;
- ordinal 391 must no longer RED solely because the prescribed-sphere `cutGraph` is absent; capture its explicit skip;
- 371/372 remain PASS and 367/368/369/370/374 retain their carried identity unless evidence proves otherwise;
- appended 392/393 are expected PASS; the no-new-regression total is **387 PASS / 6 RED** with RED set
  `366,367,368,369,370,374`;
- preserve the exact 393-row ledger/hash and an identical pre/post recursive package byte+mode census.

The successor after TB22 is independent **`M3-CP4c-3-TB22-REV`**. That review owns interpretation of BY4 and the next
correction owner. No correction or DEFN execution is pre-authorized by CB24/TB22.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB21-CAND-01` | **NEW / ACTIVE / ARCHITECTURAL / GATING** — the source-face component construction is an **unvalidated projection** of a certified cellular complex. Two readings, opposite corrections. CB24 instrumentation COMPLETE; runtime owner: TB22; interpretation/correction owner: TB22-REV. Supersedes `M3-CP4c3-TB20-REV-CAND-01`; absorbs `M3-CP4c3-TB19-CAND-01` as its symptom record. |
| `M3-CP4c3-TB21-CAND-02` | **ACTIVE / DIAGNOSTIC DEPENDENCY** — ordinal 391's sphere half blocked by the owned 368 surface. CB24 re-scope COMPLETE; TB22 must prove 391 green for this dependency. Not a stable category. |
| `M3-CP4c3-TB20-REV-CAND-01` | **WITHDRAWN** — load-bearing non-cellularity claim measured false. |
| `M3-CP4c3-TB20-REV-CAND-02` | **DOWNGRADED / FORMAL ONLY** — CB21 corrected a real unsoundness and is **not reverted**; the substantive concern is withdrawn. Parts IV/V's written prohibition remains unlifted. Owner: a DEFN turn. |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / SYMPTOM RECORD** under `M3-CP4c3-TB21-CAND-01`; the guard is not relaxed. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED** — a universal non-crossing invariant is refuted by `TraceIntersection` contact nodes; closure needs `localFragments = k + 1 + interiorCrossings` on a crossing witness. **Must not be promoted to fatal.** |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. No atlas invariant may be weakened for it. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared bound on its input size. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed:** `M3-CP4c3-TB10-REV-CAND-01` (runtime proved at TB21), `M3-CP4c3-TB19-REV-CAND-02`,
`M3-CP4c3-TB17-CAND-01`. The historical torus `UncutFaceComponentOrbitSeedNotUnique` record stays separate and is
now understood as the genuine non-cellular case Part I proved.

---

## 5. Settled facts a successor must not reopen

- **The mechanical actual embedded complex is cellular** — `22 − 26 + 6 − 2 = 0`, all faces certified discs. Do not
  re-derive non-cellularity from the seed error.
- **Part I §3 is an implication with a premise.** It licenses "not a cut graph" only where the complex is
  independently shown non-cellular, as on the torus. It says nothing about the source-face projection.
- **The certificate and the seed guard test different objects**; neither validates the other, and the projection's
  faithfulness condition is stated by neither.
- **CB21 is not reverted**, and TB20-REV's argument against it is withdrawn; only the formal Parts IV/V gap
  remains, owned by a DEFN turn.
- **371/372 are closed and their fixture accessor is test-only** — never product authority.
- **Ordinal 391's RED is a dependency on the owned 368 surface**, not a new mechanism.
- **A universal chord non-crossing invariant is refuted**; `localFragmentCount` must not become a fatal oracle
  without the crossing derivation and a crossing witness.
- The face walk is a validated total permutation; shared orbit ownership by the two sides of one arc is legitimate
  topology. **BS9-5 remains retired.**
- Identical typed error names across witnesses do not establish identical root cause.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first.
2. `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Plan.md` — exact next execution authority.
3. `Architecture_M3_CP4c3_CB24_Code_Build_Report.md` — exact source/package/selector authority.
4. **this file** — current frontier, settled facts and candidate ownership.
5. `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Report.md` — comparison runtime authority.
6. `Architecture_M3_CP4c3_TB21_Independent_Review_Record.md` — BY0–BY9 intent and mandatory independent-review boundary.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`; TB closeout must categorize every observed regression.
8. `Required_Green_Selector_Manifest.md` — selector counts, LF hashes, prefix parents and roles.
9. `M3_CP4c_Frozen_Definitions.md` only for normative classification of observed runtime evidence; do not pre-authorize
   a correction from TB.
10. `M3_CP4c_Consolidated_Record.md` only when historical lineage is needed.

**Review tooling.** `.agents/Directional/tools/` remains read-only support. Generated Directional binaries may not be
executed for discovery/list/help/version in artifact-only TB. Resolve identity-to-binary mapping statically.

**Document consolidation.** Every REVIEW turn folds superseded per-turn documents under `CLEAN_UP_POLICY.md`; CB24
closeout does not consolidate selector files or current authority.
