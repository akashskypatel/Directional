# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-04** after the pre-runtime orchestration-invalid `M3-CP4c-3-TB25-EXEC` attempt.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.** CB28 remains compile-green and semantically unaccepted. TB25's first formal attempt stopped
before Directional runtime because its temporary harness materializer failed, so TB24 remains the latest semantic runtime.

| Authority | Current value |
|---|---|
| Latest semantic runtime authority | `M3-CP4c-3-TB24-EXEC` — 389 PASS / 12 RED, accepted 365/365 |
| Current runtime RED ordinals | 366, 367, 368, 369, 370, 374, 384, 385, 389, 390, 393, 398 |
| CB28 final semantic source | `3d7f7f9a3afad3ed37fc615a206801cf6310f4ac` |
| CB28 immutable compile artifact | `9950303110`, SHA-256 `84c9cd0bdf5d8bef2288e1ca57d52bcec8d1503f368d82101ae10cfa14c49189` |
| Current selector | selector 403, 403 identities, `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007` |
| Frozen predecessor | selector 401, exact first 401 lines, `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869` |
| CB28 compile evidence | run/job `33907875533 / 101137084443`; log `9950303474` |
| TB24 runtime evidence | run/job `33891467611 / 101083954177`; result `9944102469`; log `9944102936` |
| Invalid TB25 attempt | run/job `33910913448 / 101146905061`; result/log `9951314815 / 9951315281`; 0 identities executed |
| Exact next | `M3-CP4c-3-CB29` — control-plane-only orchestration correction |

Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3
package count **90**. The invalid TB25 attempt adds **+0 stable events / +0 recurrences** because no Directional runtime
started and no semantic ledger exists.

## 2. Current frontier — discriminator compiled, runtime still unmeasured

CB28 compiles publication of embedded cellularity even when source-face ownership is incomplete, explicit per-face
ownership status, consumer-side owner consistency evidence, and a certified-owner conflict census with independent
barrier classification. The first TB25 attempt measured none of those surfaces: schema validation passed, then
`Materialize proven TB25 artifact-only harness` failed with `selector injection point missing`; the runtime step was
skipped and `ledger_available=false`.

`M3-CP4c3-TB25-ORCH-01` owns that control defect. The materializer left-shifts the historical YAML shell block by ten
columns, while its selector-authority insertion anchor still expects twelve leading spaces. It therefore fails closed
before writing the generated harness. This does not change any CB28 product or selector claim and does not adjudicate
`M3-CP4c3-TB21-CAND-01`.

## 3. Exact next turn — `M3-CP4c-3-CB29`

Perform a **control-plane-only orchestration correction**. Preserve failed run `33910913448` as invalid-attempt
provenance, correct the harness representation/materialization without touching product source, tests, fixtures,
selectors, or package bytes, and reuse artifact `9950303110` unchanged. CB29 executes no Directional runtime. After
its control is proven, the successor re-executes the unchanged frozen TB25 artifact-only plan from ordinal 1.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB24-REV-CAND-01` | **NEW / ACTIVE / GATING / PRODUCT + EVIDENCE ORDERING** — the certifier returns an error instead of a certificate, moving the failure upstream of every witness that observes it. CB28 implementation is compile-green; TB25/TB25-REV owns runtime adjudication. |
| `M3-CP4c3-TB24-REV-CAND-02` | **NEW / ACTIVE / ARCHITECTURAL / DEFINITION CORRECTION** — ownership of non-arc-incident source faces is a derivation, not a read; DEFN-R3.1's justification clause is withdrawn. CB28 CH8 instrumentation is compile-green; TB25/TB25-REV owns runtime adjudication. |
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / ARCHITECTURAL / GATING / UNADJUDICATED** — neither branch selected; D3 was unmeasurable. **TB25 records the CH8 census; TB25-REV decides it exhaustively.** |
| `M3-CP4c3-TB23-R1-REV-CAND-02` | **ACTIVE / DIAGNOSTIC CONTRACT** — ordinal 393's replacement assertions are authored but **untested**, because the subject is absent. CB28 publication path is compiled; TB25 owns runtime proof. |
| `M3-CP4c3-DEFN-R3-CAND-01` | **ACTIVE / ARCHITECTURAL / NON-GATING** — two independent constructions of one embedded topology; unresolved and still not load-bearing. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE / EVIDENCE INTEGRITY** — ordinal 393 still pins a contract no execution has exercised. CB28 publication path is compiled; TB25 owns runtime proof. |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / SYMPTOM RECORD** under `M3-CP4c3-TB21-CAND-01`. |
| `M3-CP4c3-TB21-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 391 passes with the sphere half explicitly skipped. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed at TB24-REV, all runtime-proved:** `M3-CP4c3-TB23-REV-CAND-01` (ordinal 401 PASS — fixtures fail
closed), `M3-CP4c3-TB23-REV-CAND-02` (corrected execution view, `execution_view_verified=true`, equal censuses),
`M3-CP4c3-TB23-R1-REV-CAND-01` (ordinal 397 PASS, byte-identical, fixed not relaxed). **Previously closed:**
`M3-CP4c3-TB21-CAND-02`, `M3-CP4c3-TB10-REV-CAND-01`, `M3-CP4c3-TB19-REV-CAND-02`, `M3-CP4c3-TB17-CAND-01`. The historical torus `UncutFaceComponentOrbitSeedNotUnique` record stays separate as the
genuine non-cellular case Part I proved.

---

## 5. Settled facts a successor must not reopen

- **`projectionFaithfulnessResidual = 0` is a structural zero** — the predicate is unsatisfiable by construction.
  It never ruled anything out and must not be cited as evidence.
- **The minority rows' certificate-face columns are the seed value re-printed.** Their agreement is a tautology.
- **Both branches of `M3-CP4c3-TB21-CAND-01` are live.**
- **The mechanical actual embedded complex is cellular** — `22 − 26 + 6 − 2 = 0`, all faces certified discs.
- **Part I §3 is an implication with a premise**; it says nothing about the source-face projection.
- **The certificate and the seed guard test different objects**; neither validates the other.
- **CB21 is not reverted**; only the formal Parts IV/V gap remains, owned by a DEFN turn.
- **371/372 and ordinal 391 are closed**; the atlas accessor is test-only and never product authority.
- **A universal chord non-crossing invariant is refuted**; `localFragmentCount` must not become a fatal oracle.
- The face walk is a validated total permutation; shared orbit ownership by the two sides of one arc is legitimate
  topology. **BS9-5 remains retired.**
- Identical typed error names across witnesses do not establish identical root cause.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.
- **A diagnostic gated on the success of the thing it diagnoses can never fire on the case it was built for.**
  D3 proved this at a cost of one full turn.
- **Relocating a derivation adds no information.** CB27 moved ownership into the certifier — the right authority —
  and got `[0,1,3]` at `(0,1,2)`, the same answer as before.
- **384/385/389/390 did not regress in behaviour.** They lost their subject. No assertion in any of them was
  evaluated and found wrong, which is why no stable event was added.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load only the minimum current authority:

1. `ORIENTATION.md` — read first; update it during the mandatory REVIEW closeout.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_TB25_Artifact_Only_Test_Benchmark_Plan.md` — unchanged runtime contract that CB29 must preserve for re-execution.
4. `Architecture_M3_CP4c3_CB28_Code_Build_Report.md` — final CB28 product/build evidence.
5. `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md` — current semantic runtime authority and exact immutable evidence.
6. `M3_CP4c_Frozen_Definitions.md` — prohibited lists and premise-bearing definitions; do not reinterpret them from failure names.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `Required_Green_Selector_Manifest.md` — selector counts, hashes, prefixes, current role.
9. `M3_CP4c_Consolidated_Record.md` — folded document index, including the three files folded at TB24-REV.

Exact next is `M3-CP4c-3-CB29`, control-plane-only orchestration correction. It must reuse immutable artifact `9950303110` unchanged and execute no Directional runtime; the corrected control then routes back to the frozen TB25 artifact-only gate.
