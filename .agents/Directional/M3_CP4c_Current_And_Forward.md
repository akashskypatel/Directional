# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-04** at `M3-CP4c-3-TB23-R1` closeout.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.** TB23-R1 is now the latest valid semantic runtime authority.

| Authority | Current value |
|---|---|
| Latest semantic runtime authority | `M3-CP4c-3-TB23-R1` — 389 PASS / 8 RED, accepted 365/365 |
| RED ordinals | 366, 367, 368, 369, 370, 374, **393, 397** |
| CB25 semantic/evidence source | `e12396d471c0754b112a40272a7992020ff49ced` |
| Immutable package | `9921914679`, SHA-256 `db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7` |
| Current selector | selector 397, 397 identities, `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5` |
| TB23-R1 formal evidence | run/job `33839673886 / 100919253449`; result `9924532894`; log `9924533267` |
| Ledger SHA-256 | `812241705ee5f0c467ce0272a15d4eed842dbe5c6004b1415f2432cbdedef314` |
| Exact next | `M3-CP4c-3-TB23-R1-REV` — independent REVIEW + PLAN only |

Stable accounting remains **provisionally 44 events / 14 categories / 30 recurrences** until review classifies the
new 393/397 RED surfaces; produced-witness debt **5**, semantic M3 package count **88**.

## 2. The current frontier — the ownership datum does not exist

**Current runtime authority — `M3-CP4c-3-TB23-R1`.** Source `e12396d471c0754b112a40272a7992020ff49ced`, package
`9921914679`, selector **397** (`d67e5fb7…9b4853ee5`), run/job `33839673886 / 100919253449`, ledger
`81224170…dedef314`: **389 PASS / 8 RED**, accepted **1–365 = 365/365**, reds
{366, 367, 368, 369, 370, 374, **393**, **397**}. All censuses equal.

**The orchestration correction is confirmed.** CB26's harness staged the execution view and verified it through the
consumer's own resolution rule; accepted returned to 365/365, proving the invalid attempt's 38 accepted-prefix
failures were fixture-open failures. `M3-CP4c3-TB23-REV-CAND-02` **closes**. First use of the new
`TB (orchestration-invalid) → CB (control-plane correction) → TB (re-execute)` routing, and it worked end to end.

**Both new REDs are the new witnesses working.** Ordinal **393** (production) REDs on
`m3Cp4c3CA3;examined=273;differing=0;witnessCount=64;truncated=true` and on `certifiedFaceDiffersFromSeed`, while
ordinal **396** (unit) PASSES — the "can versus does" split CA6 was written to create. Ordinal **397** REDs on a
**genuine defect**: CB25 appended `;cutCandidateCount=0` to the rendered locus of an **unrelated** error.

**`M3-CP4c-3-TB23-R1-REV` (CE0–CE8) proved why three diagnostic contracts have failed:**

- **CA2 is discharged; CA1 is not.** Both sides are filled by separate accessor calls, so CB24's aliasing is gone —
  but the edge-side path writes `walk.orbitByDart[dart]` (`GlobalTopologyPlan.cpp:487, 502–503`), the same quantity
  `edgeOrbitEvidence` records, so every available labeled certified face **equals its seed**.
- **All 191 component certified faces are `unavailable`.** `resolve_certificate_face_projection` assigns an owner
  only when a component's certified-face set has exactly one element
  (`GlobalTopologyCertificateDiagnostics.h:134–138`), and unites across every edge not in
  `embeddedGraphSourceEdges` — **mandatory and cut only**, omitting `traceTouchedEdges`. Its components are
  therefore **strictly coarser** than the seed guard's, so they collect several certified faces and every member
  resolves to `nullopt`. CA4's multiset is empty; **neither branch of `M3-CP4c3-TB21-CAND-01` fired**.
- **The datum does not exist.** `SurfaceCutGraphFaceCertificate` (`SurfaceCutGraph.h:53–63`) publishes `orbit`,
  `boundaryWalkCount`, `boundaryArcCount` and `discTopologyEstablished` — **no source-face membership, no boundary
  arc list**. No Code + Build turn can read what the contract does not publish, which is why every diagnostic has
  had to reconstruct the answer from the seed's own dart orbit. **This is a definition gap.**

TB22-REV's "no further diagnostic turn on this surface" prohibition is honoured: the successor is a **DEFN**.

---

## 3. Exact next turn — `M3-CP4c-3-DEFN-R3`, `CF0–CF9`

**DEFN absorbs `REVIEW + PLAN`**, so it freezes definitions, adjudicates inherited candidates and issues its
successor's measures in one turn. Full text in §8 of
`Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md`.

- **CF0** — accepted 365 untouched; selector 397 byte-frozen; **no runtime, no compile, no package**.
- **CF1** — decide what a certified face must publish so *"which certified face contains this source triangle"* is
  answerable; if it must not, say what else answers it and who owns that.
- **CF2** — decide whether the seed guard's premise is checkable at all; no weakening of
  `UncutFaceComponentOrbitSeedNotUnique` without a stated replacement.
- **CF3** — state the required barrier set for any certified-face projection, so `traceTouchedEdges` cannot be
  omitted again.
- **CF4** — adjudicate `M3-CP4c3-TB20-REV-CAND-02`: lift the Parts IV/V prohibition with reasons, or require CB21's
  restoration. Only a DEFN may resolve it.
- **CF5** — carry forward `proves_cellularity()`, accepted 1–365, the cellularity evidence, CB21, 371/372/391/392
  closure, and separate ownership of 367/368/369/370/374.
- **CF6** — record that both branches of `M3-CP4c3-TB21-CAND-01` were never discriminated, and what would
  discriminate them.
- **CF7** — disposition ordinals **393** and **397** explicitly; 397 must be **fixed**, 393 never silently deleted.
- **CF8** — freeze the successor CB's measures, including the fail-open `test_data_root()` and the
  unrelated-locus regression.
- **CF9** — prohibited list, including inventing a certificate field without naming its producer and proof
  obligation.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB23-REV-CAND-01` | **NEW / ACTIVE / TEST INFRASTRUCTURE / NON-GATING** — `test_data_root()` fails open, so a missing fixture tree produces a pseudo-ledger instead of one typed stop. Owner: the next Code + Build turn already changing source; **not** CB26. |
| `M3-CP4c3-TB23-REV-CAND-02` | **ACTIVE / ORCHESTRATION / RUNTIME RE-PROVED** — CB26's corrected execution view completed TB23-R1 successfully with `resolved_rule=sibling`; formal closure/classification belongs to TB23-R1-REV. |
| `M3-CP4c3-TB23-R1-REV-CAND-01` | **NEW / ACTIVE / PRODUCT** — CB25 appended `;cutCandidateCount=0` to an **unrelated** error's rendered locus, caught by ordinal 397. Must be **fixed**, not absorbed. Owner: the DEFN's successor CB (CF8). |
| `M3-CP4c3-TB23-R1-REV-CAND-02` | **NEW / ACTIVE / DIAGNOSTIC CONTRACT** — ordinal 393 encodes an expectation the production path cannot satisfy while certified ownership is underivable. **Do not delete or weaken it**; CF7 decides its disposition. |
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / ARCHITECTURAL / GATING / UNADJUDICATED** — valid TB23-R1 CA4 reports `observed=0, unavailable=191, distinct=0`, so the frozen one-versus-several discriminator did not fire. Owner: `M3-CP4c-3-TB23-R1-REV`. |
| `M3-CP4c3-TB22-REV-CAND-01` | **NEW / ACTIVE / EVIDENCE INTEGRITY** — two production diagnostics report values that cannot vary; ordinal 393 pins the vacuous contract as required-green. Owner: CA1–CA3 and CA6. |
| `M3-CP4c3-TB21-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 391 passes with the sphere half explicitly skipped. |
| `M3-CP4c3-TB20-REV-CAND-02` | **ACTIVE / FORMAL ONLY** — CB21 not reverted; Parts IV/V's written prohibition remains unlifted. Owner: a DEFN turn. |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / SYMPTOM RECORD** under `M3-CP4c3-TB21-CAND-01`. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed:** `M3-CP4c3-TB21-CAND-02`, `M3-CP4c3-TB10-REV-CAND-01`, `M3-CP4c3-TB19-REV-CAND-02`,
`M3-CP4c3-TB17-CAND-01`. The historical torus `UncutFaceComponentOrbitSeedNotUnique` record stays separate as the
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
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load only the minimum current authority:

1. `ORIENTATION.md` — read first; update it during the mandatory REVIEW closeout.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_TB23_R1_Artifact_Only_Test_Benchmark_Report.md` — current semantic runtime authority and exact immutable evidence.
4. `Architecture_M3_CP4c3_TB23_R1_Artifact_Only_Test_Benchmark_Report.md` — current immutable runtime authority.
5. `M3_CP4c_Frozen_Definitions.md` — prohibited lists and premise-bearing definitions; do not reinterpret them from failure names.
6. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
7. `Required_Green_Selector_Manifest.md` — selector counts, hashes, prefixes, current role.
8. `M3_CP4c_Consolidated_Record.md` — required during review to index the five per-turn files retired by TB23-R1.

Exact next is `M3-CP4c-3-TB23-R1-REV`. Review the valid semantic RED evidence; do not rerun Directional or patch source/tests before classification.
