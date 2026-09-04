# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB22` closeout.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**. **CP4c-3 remains OPEN.** `M3-CP4c-3-TB22` is now the current runtime authority; its expected no-new-regression ledger closed exactly.

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime authority** | **`M3-CP4c-3-TB22`** — semantic source `d69729a69a40b020968ed6ef1fbc1bc788284518`, run/job `33826248118 / 100879465830`, **387 PASS / 6 RED** |
| **Current gate selector** | selector **393**, 393 identities, `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`; selector 391 remains an exact byte prefix |
| **Immutable package** | artifact `9919225745`, `sha256:7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`; compile run/job `33823590494 / 100871347582`; GMP/GMPXX |
| **TB22 result/log** | artifacts `9920122224 / 9920122598`; digests `862d3a4c…f0fab / 67a3e187…3a65a` |
| **Ledger / census** | ledger `4998ca25b1477c2a32299bc3eb3d552e3ea9b0e2ccbf0eb4894393964f29dbbe`; identical pre/post package census `7e0c552c79281f97b7553406acd44383ff867197f36da54cd306ac9258fa2b74` |
| **First RED** | ordinal **366**, `UncutFaceComponentOrbitSeedNotUnique`, component 0, 191 faces, `seedState=Multiple`, exact seed orbits `[0,1,3]` |
| **TB22 RED set** | **366, 367, 368, 369, 370, 374** |
| **Projection measurement** | `projectionFaithfulnessResidual=0`, zero retained witnesses, untruncated; minority edges `10-79` and `29-35` map certificate faces `3/3` and `1/1` and seed by `edgeOrbitEvidence` |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **87** |

Selector 391 remains byte-frozen at `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`. Ordinals 392/393 are the only appended identities and both PASS. Ordinals 371/372 remain closed/runtime-proved. Ordinal 391 now PASSes with the prescribed-sphere half explicitly skipped because ordinal 368 remains open.

---

## 2. The current frontier — seed evidence versus certified-face ownership

TB22 materially narrows `M3-CP4c3-TB21-CAND-01` without choosing a correction. The actual embedded graph remains certified cellular (`V=22,E=26,F=6,componentCount=1,sourceChi=2,residual=0`) while source-face component 0 still collects three seed orbits `[0,1,3]`.

CB24's projection-faithfulness measurement reports **residual 0**, no witnesses, and no truncation. The two minority rows are not evidence of adjacent uncut triangles crossing different certified faces: their component/labeled certificate faces are **3/3** and **1/1**. Both minority seeds instead arise from **`edgeOrbitEvidence`**.

Therefore the measured mechanical witness does not support the prior “missing barrier between different certificate faces” branch at the relation CB24 instrumented. The remaining live question is whether the current edge-orbit seed read is the correct representation for attaching an uncut source-face component to the certified region structure. Independent TB22-REV must validate the residual's semantics and derive that ownership rule from frozen invariants before authorizing any correction.

Ordinal 391's diagnostic dependency is resolved at runtime: mechanical/torus reporting runs and the prescribed-sphere half skips with `reason=ordinal368-open`. `M3-CP4c3-TB21-CAND-02` closes as runtime-proved/non-stable; the owned sphere surface at 368 remains unchanged.

---

## 3. Exact next turn — `M3-CP4c-3-TB22-REV`, independent static review

Execute `Architecture_M3_CP4c3_TB22_Independent_Review_Plan.md` under **BZ0–BZ8**. This is REVIEW + PLAN, STATIC ONLY. No product/test/fixture/selector/build mutation, configure, compile, link, runtime test, benchmark, package operation, or DEFN execution is authorized.

Load-bearing review questions:

- prove the zero residual measures the stated projection-faithfulness premise completely and has no false-zero path;
- reconcile the two minority rows with their same-certificate `3/3` and `1/1` attribution and `seedRule=edgeOrbitEvidence`;
- derive the correct component seed/ownership contract independently of current implementation output;
- choose Code + Build only if the contract is already clear and the seed read is wrong; choose DEFN only if the normative ownership rule is genuinely undefined;
- do not authorize a barrier-set change merely to force seed uniqueness if the measured projection is faithful;
- preserve accepted 365/365, 371/372, ordinal-391 decoupling, 392/393 evidence, and separate ownership of 368/369/370/374.

The review must stop after establishing one exact successor.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / NARROWED BY TB22 / ARCHITECTURAL / GATING / NON-STABLE** — projection residual is 0; both minority edges remain within one certificate face per side; minority seeds come from `edgeOrbitEvidence`. Interpretation/correction owner: independent TB22-REV. |
| `M3-CP4c3-TB21-CAND-02` | **CLOSED / RUNTIME PROVED / NON-STABLE** — ordinal 391 PASS; sphere half skips with `reason=ordinal368-open` while mechanical/torus evidence runs. |
| `M3-CP4c3-TB20-REV-CAND-01` | **WITHDRAWN** — load-bearing non-cellularity claim measured false. |
| `M3-CP4c3-TB20-REV-CAND-02` | **DOWNGRADED / FORMAL ONLY** — CB21 corrected real unsoundness and is not reverted; Parts IV/V formal prohibition remains owned by a future DEFN turn. |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / SYMPTOM RECORD** under `M3-CP4c3-TB21-CAND-01`; the guard is not relaxed. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED** — universal non-crossing is refuted; must not be promoted to fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — exact decision with no declared bound on input size. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract; no vertex-30 discriminator yet. |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370; no correction authorized. |
| finalize/contact fall-through | **ACTIVE** — separate owner. |

**Closed:** `M3-CP4c3-TB21-CAND-02` (runtime proved at TB22), `M3-CP4c3-TB10-REV-CAND-01` (runtime proved at TB21), `M3-CP4c3-TB19-REV-CAND-02`, `M3-CP4c3-TB17-CAND-01`.

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
- **Ordinal 391 dependency is CLOSED / RUNTIME PROVED at TB22**; its sphere half skips because the independently owned 368 surface remains open.
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
2. `Architecture_M3_CP4c3_TB22_Independent_Review_Plan.md` — exact next static review authority.
3. `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` — current runtime evidence.
4. `Architecture_M3_CP4c3_TB21_Independent_Review_Record.md` — preceding review/BY0–BY9 intent.
5. **this file** — current frontier, settled facts and candidate ownership.
6. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
7. `Required_Green_Selector_Manifest.md` — selector counts, LF hashes, prefix parents and roles.
8. `M3_CP4c_Frozen_Definitions.md` — required when deriving the ownership/seed contract.
9. `M3_CP4c_Consolidated_Record.md` only when historical lineage is needed.

**Review boundary.** TB22-REV is static-only. Do not execute generated binaries, configure, compile, test, benchmark, mutate product/test/selector/build logic, or begin its successor.

**Document consolidation.** TB22-REV owns the next REVIEW consolidation/ORIENTATION update under `CLEAN_UP_POLICY.md`; selector files remain independent byte-frozen witnesses.
