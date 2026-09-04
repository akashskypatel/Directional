# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB21-REV`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime authority** | **`M3-CP4c-3-TB21`** — source `fa5646106ccaa23770b84a935c6d1d6007928640`, run/job `33818038269 / 100854435211`, **384 PASS / 7 RED** |
| **Current gate selector** | selector 391, **391 identities**, `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`; selector 385 (388 identities) and accepted 365 exact prefixes |
| **Compile/package authority** | run `33815475590`, job `100847694307`, artifact `9916511617`, `sha256:8378a108811740cff5fd1a0fc9db66f9e3334d7048ea9e7c7d6e8e1cbd852050`, GMP/GMPXX, `runtimeExecution=false` |
| **TB21 artifacts** | result/log `9917317234 / 9917317654` |
| **TB21 ledger** | `8606fb7ba5673e6d3b45b5055f7744559b29a79d5caa8d0df76da85920aa6f77` — 384 + 7 = 391 |
| **First red** | ordinal **366**, `UncutFaceComponentOrbitSeedNotUnique`, component **0**, 191 faces, `seedState=Multiple`, seed orbits **`[0,1,3]`** |
| **TB21 red set** | 366, 367, 368, 369, 370, 374, **391** |
| **Mechanical Euler census** | `V=22, E=26, F=6, componentCount=1, χ=2, residual=0` — complete actual-complex authority, **cellular** |
| **Package census** | pre/post identical, `e15a8ababed2d6580d36abe9e2421a9d573bd29fb5fe36fb08ab844f80161897` |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **86** |

> Selector 385 remains the historical filename/count exception (388 identities). Selector 391 contains 391.
> Selector files remain byte-frozen and are **never consolidated**; `Required_Green_Selector_Manifest.md` indexes
> counts, LF hashes, prefix parents and roles.

**371 and 372 now PASS**, reaching their own assertions for the first time after the test-only atlas decoupling.
`M3-CP4c3-TB10-REV-CAND-01` is **CLOSED / RUNTIME PROVED**.

---

## 2. The current frontier — a projection, not a missing cut graph

### The correction this turn owes

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
class and seed all captured, then summarized into counts by the report. **No new measurement is required**, only
retention and projection by *distinctness*. Raising the 64/97 cap would be the wrong fix.

### Ordinal 391

A **self-inflicted diagnostic RED**: its prescribed-sphere half needs `sphere.cutGraph` and hits the already-owned
368 surface, because TB20-REV's BW4 required one census witness to span all three witnesses. BY7 re-scopes it. It
touches no sphere product surface and creates no new stable category.

---

## 3. Exact next turn — `M3-CP4c-3-CB24`, diagnostic-only, `BY0–BY9`

Full text in §10 of `Architecture_M3_CP4c3_TB21_Independent_Review_Record.md`. Not a DEFN (there is no normative
conflict) and not a correction (the two readings imply opposite fixes).

- **BY0** — accepted 365 untouched; **selector 391 byte-frozen** and republished unchanged; eight standard compile
  targets with **mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BY1** — **retain boundary rows by distinctness, not position**: at least one row per distinct seed orbit and
  per distinct `noSeedReason` before filling the budget in order. Cap and truncation marker kept.
- **BY2** — publish the **minority-orbit rows in full**, including **which rule produced each seed**
  (owner-shortcut at `:1131` versus `edgeOrbitEvidence` at `:1134`).
- **BY3** — attribute each minority edge's **two sides to certificate faces**.
- **BY4** — publish the **projection faithfulness residual**: adjacent uncut triangle pairs in different
  certificate faces whose shared edge is not in `componentBarriers`. **Zero means the seed read is at fault;
  non-zero names the barrier set.**
- **BY5** — one witness per new field through the production path, plus an unrelated-error regression witness.
- **BY6** — append the next selector **named by its resulting identity count**; 391 stays an exact prefix;
  regenerate the selector manifest with `tools/selector_manifest.py`.
- **BY7** — **re-scope ordinal 391** so the mechanical and torus halves report independently of the sphere half.
- **BY8** — **no product semantic change**: the guard, `componentBarriers`, the partition, `seedOrbits`, the seed
  rule, `edgeOrbitEvidence`, `add_fragment_orbit`, the `exteriorOrbits` filter, `is_terminal_slit`, the face walk,
  the rotation system, region drafts, CB21's comparison, `proves_cellularity()` and the certificate stay
  untouched; `localFragmentCount` stays non-fatal. **No revert of CB21.**
- **BY9** — six `M3-CP4c-3-TB22` discriminators, chiefly: 1–365 stay 365/365; ordinal 366 **unchanged**; both
  minority rows published in full; the **faithfulness residual published**; and **391 no longer RED**.

The successor after TB22 is an independent `M3-CP4c-3-TB22-REV`. **A DEFN turn becomes correct only if BY4's
residual is non-zero and the barrier-set contract must be restated**; it is not scheduled in advance.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB21-CAND-01` | **NEW / ACTIVE / ARCHITECTURAL / GATING** — the source-face component construction is an **unvalidated projection** of a certified cellular complex. Two readings, opposite corrections. Owner: BY1–BY4, then TB22-REV. Supersedes `M3-CP4c3-TB20-REV-CAND-01`; absorbs `M3-CP4c3-TB19-CAND-01` as its symptom record. |
| `M3-CP4c3-TB21-CAND-02` | **ACTIVE / DIAGNOSTIC DEPENDENCY** — ordinal 391's sphere half blocked by the owned 368 surface. Owner: BY7. Not a stable category. |
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
2. **this file** — current state, frozen successor, candidate index.
3. `Architecture_M3_CP4c3_TB21_Independent_Review_Record.md` — the frozen **CB24** scope, §10 BY0–BY9.
4. `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Report.md` — current immutable runtime authority.
5. `M3_CP4c_Frozen_Definitions.md` — **Part I §3 is an implication with a premise**; Parts IV/V prohibited lists;
   Part VI for vertex-star definitions. **Read the prohibited lists before authorizing any correction, and carry
   each finding's premise, not just its conclusion.**
6. `GMP_COMPILE_POLICY.md` — mandatory for every compile.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `Required_Green_Selector_Manifest.md` — selector counts, LF hashes, prefix parents, roles.
9. `M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed; its **folded document index**
   resolves every folded or retired per-turn plan, report and record.

**Review tooling.** `.agents/Directional/tools/` holds read-only helpers: `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py`, `selector_manifest.py`, and `fixture_probe.py`. See
`tools/README.md` for the caveats — in particular that geometric sharpness is not the product's barrier set, and
that the singularity reconstruction is corroboration only.

**Document consolidation.** Every REVIEW turn folds its superseded per-turn documents into
`M3_CP4c_Consolidated_Record.md`'s folded document index under `CLEAN_UP_POLICY.md`, **and indexes anything a CB or
TB turn's stale-evidence cleanup retired between reviews**. Preserve durable facts in a retained record first;
never fold current authority, normative definitions, policies or selector files.
