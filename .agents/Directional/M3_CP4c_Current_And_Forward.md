# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB21`.

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
| **TB21 red set** | 366, 367, 368, 369, 370, 374, 391 |
| **Mechanical Euler census** | `V=22,E=26,F=6,componentCount=1,χ=2,residual=0`, complete actual-complex authority |
| **Package census** | pre/post identical, `e15a8ababed2d6580d36abe9e2421a9d573bd29fb5fe36fb08ab844f80161897` |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **86** |

> Selector 385 remains the historical filename/count exception (388 identities). Selector 391 contains 391.
> Selector files remain byte-frozen and are never consolidated.

---

## 2. Current frontier — actual-complex cellularity and source-face seed uniqueness disagree

TB21 preserves the ordinal-366 branch exactly: component 0 has 191 faces and three untruncated seed orbits
`[0,1,3]`. However the complete production census from the same mechanical path reports the actual embedded graph
as `22-26+6=2`, one graph component, residual 0. `SurfaceCutGraph::canonical_candidate` returns that cut graph only
after its actual-complex certificate passes `proves_cellularity()`.

The prior review's load-bearing interpretation — that three seeds prove this certified actual complex is
non-cellular — is therefore contradicted by the evidence it requested. TB21 does not decide whether the source-face
component partition is a legitimate coarser projection, is missing post-cut barrier authority, or reflects a
normative mismatch. That is the exact review question.

Component-0 aggregate boundary attribution is complete despite bounded raw rows: orbit 0→81, orbit 1→1, orbit
3→1, 3 rows untruncated, 83/97 edges attributed; the remaining 14 are barrier/no-seed.

371/372 now both PASS their own unchanged atlas assertions, closing their test-coupling candidate. 389/390 PASS.
391 REDs only when its prescribed-sphere half finds no `sphere.cutGraph`; that co-reaches the existing 368 sphere
surface and is not merged into the mechanical contradiction.

---

## 3. Exact next turn — `M3-CP4c-3-TB21-REV`, static independent review

The execution record is `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Report.md`; the frozen review
contract is `Architecture_M3_CP4c3_TB21_Independent_Review_Plan.md` under **BX0–BX8**.

The review must reconcile the actual embedded graph certificate with the source-face seed partition, adjudicate the
scope of Part I §3 / Parts IV–V against actual-complex authority, account for the three seed-attribution rows,
revisit the CB21 governance candidate only after that relation is settled, close 371/372, and keep ordinal 391's
sphere dependency separate. No Code + Build, DEFN execution or runtime is pre-authorized.

---

## 4. Open candidates

| Candidate | State |
|---|---|
| `M3-CP4c3-TB21-CAND-01` | **NEW / ACTIVE / ARCHITECTURAL / GATING** — certified cellular actual complex coexists with a three-orbit source-face seed component. Owner: TB21-REV BX1–BX4. |
| `M3-CP4c3-TB20-REV-CAND-01` | **ACTIVE / CONTRADICTED IN ITS ACTUAL-COMPLEX NON-CELLULARITY INFERENCE** — retain until review reconciles definition scope. |
| `M3-CP4c3-TB20-REV-CAND-02` | **ACTIVE / GOVERNANCE** — CB21 weakened an invariant Parts IV/V prohibit weakening; no silent revert or preservation decision. |
| `M3-CP4c3-TB21-CAND-02` | **NEW / ACTIVE / DIAGNOSTIC DEPENDENCY** — 391 sphere half co-reaches existing 368 `CellularityNotEstablished`. |
| `M3-CP4c3-TB10-REV-CAND-01` | **CLOSED / RUNTIME PROVED AT TB21** — 371/372 both reach and PASS. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED** — universal non-crossing fragment formula is not valid. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — exact decision with no declared bound on input size. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. |
| finalize/contact fall-through | **ACTIVE** — separate owner. |

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
3. `Architecture_M3_CP4c3_TB21_Independent_Review_Plan.md` — **exact next review contract**.
4. `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Report.md` — current immutable runtime authority; compile/package authority is retained in this file and the changelog.
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
