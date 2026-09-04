# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-04** after valid immutable `M3-CP4c-3-TB25-R1` completed selector 403.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.** TB25-R1 is the latest semantic runtime: **393 PASS / 10 RED**, accepted **365/365**.
The first TB25 attempt remains pre-runtime-invalid provenance; CB29's control correction is now runtime-proved.

| Authority | Current value |
|---|---|
| Latest semantic runtime authority | `M3-CP4c-3-TB25-R1` — 393 PASS / 10 RED, accepted 365/365 |
| Current runtime RED ordinals | 366, 367, 368, 369, 370, 374, 389, 390, 393, 398 |
| CB28 final semantic source | `3d7f7f9a3afad3ed37fc615a206801cf6310f4ac` |
| CB28 immutable compile artifact | `9950303110`, SHA-256 `84c9cd0bdf5d8bef2288e1ca57d52bcec8d1503f368d82101ae10cfa14c49189` |
| Current selector | selector 403, 403 identities, `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007` |
| Accepted prefix | selector 365, exact first 365 lines, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| Frozen predecessor | selector 401, exact first 401 lines, `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869` |
| TB25-R1 runtime evidence | run/job `33919389753 / 101173990222`; result `9954531868`; log `9954532357` |
| Invalid first TB25 attempt | run/job `33910913448 / 101146905061`; result/log `9951314815 / 9951315281`; 0 identities executed |
| CB29 control proof | run/job `33915621191 / 101162027243`; result/log `9953038617 / 9953039237`; runtime started false |
| Exact next | `M3-CP4c-3-TB25-REV` — independent REVIEW + PLAN only |

Stable accounting remains **44 events / 14 categories / 30 recurrences** pending TB25-REV; produced-witness debt
remains **5**; semantic M3 package count remains **90**.

## 2. Current frontier — discriminator measured; review owns interpretation

TB25-R1 completed all 403 identities from immutable artifact `9950303110` with no rebuild/repair/mutation and equal
package/source/execution-view censuses. Relative to TB24, ordinals **384 and 385 recover RED → PASS**; the remaining
RED set is **366, 367, 368, 369, 370, 374, 389, 390, 393, 398**. New ordinals **402 and 403 PASS**.

The production ownership publication is now measurable. Ordinal 385 reports **300 source faces: 74 established,
226 unavailable, 0 conflicting**, with the conflict census published and **0 rows**. Ordinal 402 also reports the
production conflict census published with **rowCount=0**; ordinal 403 PASSes its bounded non-barrier differing-owner
witness. Ordinals 366/367 report component 0 with **191 faces, 0 certified observations, 191 unavailable, 0 distinct,
seedState=None**. These facts are deliberately not converted into the missing-barrier/mis-attribution/third-mechanism
decision here; the unchanged frozen TB25 plan assigns that interpretation to TB25-REV.

`M3-CP4c3-TB25-ORCH-01` is **CLOSED / CONTROL FIX RUNTIME PROVED / NON-STABLE**: corrected preflight passed and
the full fresh-process gate completed. The first invalid attempt remains provenance only.

## 3. Exact next turn — `M3-CP4c-3-TB25-REV`

Perform **independent REVIEW + PLAN only** over the immutable TB25-R1 evidence. Do not rerun Directional, rebuild,
relink, repair, mutate product/tests/fixtures/selectors/package bytes, or reinterpret the first invalid attempt as
semantic evidence. Review owns the 10-RED classification, the 384/385 recoveries, the production zero-row conflict
census with 226 unavailable source faces, the long-open ownership branch adjudication, stable accounting, mandatory
`ORIENTATION.md` update, and mandatory REVIEW document consolidation. Authorize at most one bounded successor.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB24-REV-CAND-01` | **NEW / ACTIVE / GATING / PRODUCT + EVIDENCE ORDERING** — the certifier returns an error instead of a certificate, moving the failure upstream of every witness that observes it. CB28 implementation is compile-green; TB25/TB25-REV owns runtime adjudication. |
| `M3-CP4c3-TB24-REV-CAND-02` | **NEW / ACTIVE / ARCHITECTURAL / DEFINITION CORRECTION** — ownership of non-arc-incident source faces is a derivation, not a read; DEFN-R3.1's justification clause is withdrawn. CB28 CH8 instrumentation is compile-green; TB25/TB25-REV owns runtime adjudication. |
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / ARCHITECTURAL / GATING / REVIEW PENDING** — TB25-R1 measured production `conflictRowCount=0` with 226/300 source faces unavailable and component-0 191/191 certified owners unavailable. **TB25-REV owns the branch adjudication.** |
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

**Closed control candidate at TB25-R1:** `M3-CP4c3-TB25-ORCH-01` (corrected preflight and full 403-process gate completed). **Closed at TB24-REV, all runtime-proved:** `M3-CP4c3-TB23-REV-CAND-01` (ordinal 401 PASS — fixtures fail
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
- **384/385/389/390 did not regress in accepted behaviour.** TB25-R1 now returns 384/385 to PASS; 389/390 remain RED.
  Stable classification remains owned by review.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load only the minimum current authority:

1. `ORIENTATION.md` — read first; update it during the mandatory REVIEW closeout.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md` — current semantic runtime authority.
4. `Architecture_M3_CP4c3_CB28_Code_Build_Report.md` — immutable product/package build authority.
5. `M3_CP4c_Consolidated_Record.md` — resolver for retired per-turn records; the next REVIEW must index the TB24 runtime report, consumed TB25 plan, and CB29 control report retired by TB25-R1 stale-evidence cleanup.
6. `M3_CP4c_Frozen_Definitions.md` — prohibited lists and premise-bearing definitions; do not reinterpret them from failure names.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `Required_Green_Selector_Manifest.md` — selector counts, hashes, prefixes, current role.
9. `M3_CP4c_Consolidated_Record.md` — folded document index, including the three files folded at TB24-REV.

Exact next is `M3-CP4c-3-TB25-REV`, independent REVIEW + PLAN over the valid 403-process TB25-R1 evidence.
