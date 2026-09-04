# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-04** at `M3-CP4c-3-TB24-REV` closeout.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.** TB24 is the latest valid semantic runtime authority; accepted authority remains 365/365.

| Authority | Current value |
|---|---|
| Latest semantic runtime authority | `M3-CP4c-3-TB24-EXEC` — 389 PASS / 12 RED, accepted 365/365 |
| Current runtime RED ordinals | 366, 367, 368, 369, 370, 374, 384, 385, 389, 390, 393, 398 |
| CB27 semantic source | `9c72fea8b666534b9e52fa42bbe8cbf8ae68ffe5` |
| CB27 immutable package | `9935929108`, SHA-256 `b5e11a2c97c110d2cf484d63bb3afe3b753e7f4769098ec927a5cf1692f5d881` |
| Current selector | selector 401, 401 identities, `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869` |
| Frozen prefix | selector 397, `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5` |
| CB27 compile evidence | run/job `33870767698 / 101015974984`; log `9935929698` |
| TB24 runtime evidence | run/job `33891467611 / 101083954177`; result `9944102469`; log `9944102936` |
| TB24 ledger | 389 PASS / 12 RED; SHA-256 `db6ca1c76373a0cc215096989acbd281852d25d6b5e7db703885d7a46cdd858b` |
| Exact next | `M3-CP4c-3-CB28` — Code + Build, runtime-free, GMP/GMPXX linked, under CH6–CH9 |

Stable accounting is **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3
package count **89**. `M3-CP4c-3-TB24-REV` adjudicated the ledger and added **no stable event**: accepted 1–365 is
365/365 with no accepted-green loss, and the four PASS→RED surfaces are **evidence-subject loss, not behaviour
loss**.

## 2. The current frontier — one ordering defect, seven surfaces, and a branch still undecided

**`M3-CP4c-3-TB24-REV` found a single cause.** `certify_actual_embedded_graph` (`SurfaceCutGraph.cpp:604–615`)
returns a `SurfaceCutGraphError` instead of a certificate whenever `build_source_face_ownership` cannot establish
ownership. `mechanical.cutGraph.has_value()` is therefore false, and every witness downstream of the certificate
loses its subject: ordinals **366, 384, 385, 389, 390, 393, 398** are **one defect on one fixture**. TB24's own
report proves it — each reaches `has_value()==false` *before its later evidence assertion*.

**The evidence CB27 built is complete, correct and unreachable.** `GlobalTopologyPlan.cpp:1122–1170` assembles the
component partition, `check_certified_source_face_owner_consistency`, the `ownerEvidence` census with component id,
face count, owner count, typed `seedState` and untruncated orbit ids, and then fails through
`UncutFaceComponentOrbitSeedNotUnique` naming the component and the conflicting owners — exactly DEFN-R3.2 and
discriminator D4. None of it runs. **Ordinal 400 proves the relocated guard works; ordinal 366 proves it is never
reached.**

**What CB27 got right, runtime-proved.** Ordinal **397 PASSes** its byte-identical expectation — fixed, not
relaxed. Ordinals **399/400/401 PASS**. Accepted **365/365**. The plan no longer seeds ownership.

**D3 was unmeasurable, and that was foreseeable.** It was defined to read the published owner map while the same
definition made publication conditional on the derivation succeeding, so it could only report when there was
nothing to decide: **0 observed / 191 unavailable**. `M3-CP4c3-TB21-CAND-01` stays **UNADJUDICATED**. What TB24 does
settle is negative and useful: the ambiguity is **not** an artefact of where the derivation lives — the relocated
code reproduced `[0,1,3]` at `(0,1,2)` exactly.

**One definition clause is withdrawn.** DEFN-R3.1's *decision* stands; its justification — "a publication decision,
not a new computation" — does not. The face walk's darts are darts of network and cut arcs, so only arc-incident
and trace-crossed faces have a directly readable orbit; every other face still needs propagation. Recorded as
`M3-CP4c3-TB24-REV-CAND-02`. **Definition authority otherwise remains `M3-CP4c-3-DEFN-R3`, Part VII.**

---

## 3. Exact next turn — `M3-CP4c-3-CB28`

Code + Build, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`, under **CH6–CH9** of
`Architecture_M3_CP4c3_TB24_Independent_Review_Record.md`.

- **CH6 — publication survives failure.** The certifier publishes the certificate with whatever ownership was
  established, each entry carrying an explicit status, and `proves_cellularity()` still returns false.
  DEFN-R3.1's proof obligation is **unchanged and not weakened**. Ordinal 399 must stay PASS.
- **CH7 — the consumer reaches its own census.** Build the partition and the consistency census before failing.
  Required outcome: 366 names component and conflicting owners; **384, 389, 390 return to PASS with no assertion
  changed**. If they do not, `M3-CP4c3-TB24-REV-CAND-01` is falsified.
- **CH8 — the certified-owner conflict census, falsification condition first.** Every non-barrier source edge whose
  two incident faces carry different established owners, each row naming the edge's **barrier class**. Class other
  than `none` ⇒ missing barrier, proven, edge named. All `none` ⇒ mis-attribution, proven. No rows but a
  zero-owner component ⇒ a third mechanism, named. No rows and one owner per component ⇒ the derivation succeeds.
  Exhaustive, and published on the failure path.
- **CH9 — selector 403**, keeping selector 401 as an exact 401-line prefix and 397 as the frozen prefix of that.
  New gating ordinals **402** (census publishes) and **403** (independent falsifiability). Ordinal **385**'s
  assertions replaced in place, retained and gating. Ordinal **398** stays gating and is **expected RED**.

**CB28 measures; it does not correct.** No barrier may be added, no attribution rule changed, no accepted identity
touched, and no Directional runtime executed.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB24-REV-CAND-01` | **NEW / ACTIVE / GATING / PRODUCT + EVIDENCE ORDERING** — the certifier returns an error instead of a certificate, moving the failure upstream of every witness that observes it. Owner: CH6/CH7. Falsified when 384/389/390 return to PASS unchanged and 366 names the component and owners. |
| `M3-CP4c3-TB24-REV-CAND-02` | **NEW / ACTIVE / ARCHITECTURAL / DEFINITION CORRECTION** — ownership of non-arc-incident source faces is a derivation, not a read; DEFN-R3.1's justification clause is withdrawn. Owner: CH8. |
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / ARCHITECTURAL / GATING / UNADJUDICATED** — neither branch selected; D3 was unmeasurable. **CH8 decides it exhaustively.** |
| `M3-CP4c3-TB23-R1-REV-CAND-02` | **ACTIVE / DIAGNOSTIC CONTRACT** — ordinal 393's replacement assertions are authored but **untested**, because the subject is absent. Owner: CH6/CH7, then TB25. |
| `M3-CP4c3-DEFN-R3-CAND-01` | **ACTIVE / ARCHITECTURAL / NON-GATING** — two independent constructions of one embedded topology; unresolved and still not load-bearing. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE / EVIDENCE INTEGRITY** — ordinal 393 still pins a contract no execution has exercised. Owner: CH6/CH7, then TB25. |
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
3. `Architecture_M3_CP4c3_TB24_Independent_Review_Record.md` — **CH0–CH9**, the adjudication and the frozen CB28 scope.
4. `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md` — current semantic runtime authority and exact immutable evidence.
5. `M3_CP4c_Frozen_Definitions.md` — prohibited lists and premise-bearing definitions; do not reinterpret them from failure names.
6. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
7. `Required_Green_Selector_Manifest.md` — selector counts, hashes, prefixes, current role.
8. `M3_CP4c_Consolidated_Record.md` — folded document index, including the three files folded at TB24-REV.

Exact next is `M3-CP4c-3-CB28` under CH6–CH9. **CB28 measures; it does not correct** — no barrier may be added and
no attribution rule changed before CH8 reports.
