# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-04** at `M3-CP4c-3-TB25-REV` closeout.

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
| Exact next | `M3-CP4c-3-CB30` — Code + Build, runtime-free, GMP/GMPXX linked, under CJ6–CJ9 |

Stable accounting is **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3
package count **90**. `M3-CP4c-3-TB25-REV` adjudicated the ledger and added **no stable event**: accepted 1–365 is
365/365 with no accepted RED ordinal, 384/385 recovered, and every remaining RED is named below.

## 2. Current frontier — the seed rule is starved, and the question has been re-posed about the object

**Ten REDs, four causes.** 366/367 are the one open product problem. **398 is the honest gate** —
`proves_cellularity()` is false because ownership genuinely is incomplete. **389/390/393 are collateral**: each
identity's own subject is green and each additionally asserts `proves_cellularity()`, which DEFN-R3.1 coupled to
ownership totality. 368/369/370/374 are unchanged carried surfaces with separate owners.

**CH6/CH7 worked.** Ordinals **384 and 385 return to PASS** and the production ownership publication is readable
for the first time in seven turns: `300 source faces — 74 established, 226 unavailable, 0 conflicting`, conflict
census published with **0 rows**. Component 0: **191 faces, 97 boundary edges, seedCount 0, seedState None**.

**The diagnosis.** CB28's certifier seed rule admits **one** seed source where the pre-CB27 plan rule admitted
**two** — a labeled neighbour with a single fragment orbit, or unique per-edge evidence; only the second survived
the move. On component 0's 97 boundary edges the old rule attributed **83** (orbit 0 → 81, orbit 1 → 1, orbit 3 →
1) and the new rule attributes **0**. Neither rule is derived from the certificate.

**`M3-CP4c3-TB21-CAND-01` is CLOSED as ill-formed.** Both branches refuted; both recorded predictions wrong. The
same fixture and the same certified complex give **3 owners under one rule and 0 under another** — that is a
question about the heuristic, not about the geometry.

**What replaces it — a dichotomy about the object.** Certified faces are orbits of the face walk, and only arcs can
separate them. **If no arc meets an uncut component's interior, that component lies in exactly one certified face.**
So either component 0 has a single certified owner — making `3` wrong, `0` starved, and 81/1/1's majority the answer
— or the barrier set fails to mark a separating arc. The only identified mechanism for the second horn is a **trace
transiting a source vertex**, which a partition of source faces over source edges cannot express.

**CH8's conflict census was vacuous.** It emits a row only when both incident faces have an established singleton
owner, and all 191 of component 0's faces are `Unavailable`. `conflictRowCount=0` is a structural zero over exactly
the region under investigation — the third such zero in this checkpoint. `LESSONS.md` 122.

## 3. Exact next turn — `M3-CP4c-3-CB30`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`, under **CJ6–CJ9** of
`Architecture_M3_CP4c3_TB25_Independent_Review_Record.md`.

- **CJ6 — three censuses per uncut component**, published on the failure path and **never gated on an established
  owner**: (1) boundary edges with independently derived barrier class and side-owner presence, untruncated for
  component 0's 97; (2) **interior arc-incidence** — every arc whose dart lies on a component face, with kind and
  both dart orbits; (3) **vertex-transit census** — every vertex a trace enters through `SourceVertexSupport`, its
  incident uncut faces, and whether any pair is adjacent across a non-barrier edge. Outcomes are mutually exclusive
  and jointly exhaustive, and each names a locus.
- **CJ7 — restore the second seed source**, exactly as the pre-CB27 rule had it. A restoration, not a new
  heuristic. Multi-seed components publish `Conflicting` with the full multiset; `proves_cellularity()` stays false.
  **No winner is chosen among disagreeing seeds.**
- **CJ8 — one contract per gate.** 389/390/393 assert `proves_embedded_cellularity()`; 390's
  `ASSERT_GT(distinctCount, 1U)` is replaced in place by the contract it owns. **398 is untouched and remains the
  sole gate on ownership totality.**
- **CJ9 — selector 405** with 403 as an exact prefix; gating ordinals **404** (censuses published and complete) and
  **405** (independent vertex-transit falsifiability witness).

**No barrier may be added or removed and no attribution rule changed beyond the CJ7 restoration before CJ6
reports.**

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB25-REV-CAND-01` | **NEW / ACTIVE / GATING / PRODUCT** — the certifier's seed rule admits one source where the rule it replaced admitted two; component 0 goes from 83 attributed boundary edges to 0. Owner: CJ6/CJ7. |
| `M3-CP4c3-TB25-REV-CAND-02` | **NEW / ACTIVE / GATING / ARCHITECTURAL** — *is component 0 contained in a single certified face?* Posed about the object. Yes unless a separating arc meets its interior; the only mechanism that can hide one is a trace transiting a vertex. Owner: CJ6. |
| `M3-CP4c3-TB25-REV-CAND-03` | **NEW / ACTIVE / GATING / TEST AUTHORITY** — ordinals 389/390 gate on assertions their identities do not own, and 390's `ASSERT_GT(..., 1U)` encodes a refuted hypothesis. Owner: CJ8. |
| `M3-CP4c3-TB23-R1-REV-CAND-02` | **ACTIVE / DIAGNOSTIC CONTRACT** — ordinal 393's replacement assertions are authored but **untested**, because the subject is absent. CB28 publication path is compiled; TB25 owns runtime proof. |
| `M3-CP4c3-DEFN-R3-CAND-01` | **ACTIVE / ARCHITECTURAL / NON-GATING** — two independent constructions of one embedded topology; unresolved and still not load-bearing. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE / EVIDENCE INTEGRITY** — ordinal 393 still pins a contract no execution has exercised. CB28 publication path is compiled; TB25 owns runtime proof. |
| `M3-CP4c3-TB24-REV-CAND-02` | **CONFIRMED / ACTIVE / ARCHITECTURAL** — ownership of non-arc-incident faces is a derivation, not a read. TB25-R1 shows the derivation is what is broken. |
| `M3-CP4c3-TB21-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 391 passes with the sphere half explicitly skipped. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed at TB25-REV:** `M3-CP4c3-TB21-CAND-01` (**ill-formed / superseded** — its answer was set by which seed heuristic ran), `M3-CP4c3-TB19-CAND-01` (symptom record of the same ill-formed question), `M3-CP4c3-TB24-REV-CAND-01` (**runtime proved** — 384/385 recovered; the failure no longer sits upstream of the evidence), `M3-CP4c3-TB25-ORCH-01` (control fix runtime proved). **Closed at TB24-REV, all runtime-proved:** `M3-CP4c3-TB23-REV-CAND-01` (ordinal 401 PASS — fixtures fail
closed), `M3-CP4c3-TB23-REV-CAND-02` (corrected execution view, `execution_view_verified=true`, equal censuses),
`M3-CP4c3-TB23-R1-REV-CAND-01` (ordinal 397 PASS, byte-identical, fixed not relaxed). **Previously closed:**
`M3-CP4c3-TB21-CAND-02`, `M3-CP4c3-TB10-REV-CAND-01`, `M3-CP4c3-TB19-REV-CAND-02`, `M3-CP4c3-TB17-CAND-01`. The historical torus `UncutFaceComponentOrbitSeedNotUnique` record stays separate as the
genuine non-cellular case Part I proved.

---

## 5. Settled facts a successor must not reopen

- **`projectionFaithfulnessResidual = 0` is a structural zero** — the predicate is unsatisfiable by construction.
  It never ruled anything out and must not be cited as evidence.
- **The minority rows' certificate-face columns are the seed value re-printed.** Their agreement is a tautology.
- **Both branches of `M3-CP4c3-TB21-CAND-01` are REFUTED, and the question is closed as ill-formed.** Do not re-pose it. The successor question is whether component 0 lies in a single certified face — asked about the object, not about a rule.
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
- **384/385 recovered at TB25-R1; 389/390 remain RED for a named, separate reason** — each carries an assertion its identity does not own. No accepted behaviour was ever lost.
- **A census over established values is vacuous where nothing is established.** CH8's `rowCount=0` proved this at a cost of one turn.
- **Only arcs separate certified faces.** An uncut component whose interior no arc meets lies in exactly one certified face. This is a proof, not a measurement.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load only the minimum current authority:

1. `ORIENTATION.md` — read first; update it during the mandatory REVIEW closeout.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_TB25_Independent_Review_Record.md` — **CJ0–CJ9**, the adjudication and the frozen CB30 scope.
4. `Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md` — current semantic runtime authority.
5. `Architecture_M3_CP4c3_CB28_Code_Build_Report.md` — immutable product/package build authority.
6. `M3_CP4c_Frozen_Definitions.md` — prohibited lists and premise-bearing definitions; do not reinterpret them from failure names.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `Required_Green_Selector_Manifest.md` — selector counts, hashes, prefixes, current role.
9. `M3_CP4c_Consolidated_Record.md` — folded-document resolver, including the five documents indexed at TB25-REV.

Exact next is `M3-CP4c-3-CB30` under CJ6–CJ9. **CB30 measures and restores one dropped seed source; it chooses no
winner and moves no barrier.**
