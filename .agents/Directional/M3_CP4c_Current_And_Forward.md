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

## 2. The current frontier — valid TB23-R1 runtime exposes two additional RED surfaces

The corrected CB26 execution view is runtime-proved operational. Formal TB23-R1 run `33839673886` passed the
fixture-resolution preflight (`resolved_rule=sibling`), executed all 397 identities, and preserved package/source/
execution-view censuses exactly. No benchmark, configure, compile, relink, discovery, package repair, mode repair or
source/test/fixture/selector mutation occurred.

**Accepted authority remains 365/365.** Ordinal 366 retains the exact carried
`UncutFaceComponentOrbitSeedNotUnique` component-0 / `Multiple` / `[0,1,3]` / 191-face locus. Carried REDs
367/368/369/370/374 remain RED; 371/372/391/392 remain PASS.

**Ordinal 393 is newly RED in valid semantic evidence.** Its production diagnostics are:

- CA3 `examined=273`, `differing=0`, `witnessCount=64`, `truncated=true`;
- two CA2 minority rows, both component certified faces `unavailable`; labeled certified faces `3` and `1`, equal
  to the shown seeds;
- CA4 `observed=0`, `unavailable=191`, `distinct=0`, empty multiset.

The test also reports `certifiedFaceDiffersFromSeed=false`. This TB records the facts only; review owns whether they
implicate the projection, the witness contract, or another cause.

**Ordinals 394–396 PASS. Ordinal 397 is newly RED.** Its exact unrelated-locus assertion expected
`;sourceFace=2,4,6` and received `;sourceFace=2,4,6;cutCandidateCount=0`. Ownership of that byte difference is
unclassified until review.

The CA4 result does not realize the frozen one-versus-several branch discriminator because 191/191 certified-face
observations are unavailable. `M3-CP4c3-TB21-CAND-01` therefore remains unadjudicated pending independent review.

The earlier TB23-EXEC raw 342/55 ledger remains invalid-attempt provenance only. It is superseded as runtime
authority by this valid TB23-R1 ledger and must never be mixed into regression accounting.

---

## 3. Exact next turn — `M3-CP4c-3-TB23-R1-REV`, independent REVIEW + PLAN

Static review only. Do not rerun Directional or patch source/tests before review. The review must verify the
immutable evidence, diagnose/classify 393 and 397, adjudicate the unavailable CA2/CA4 evidence against the live
architectural candidate, formally dispose the corrected-harness candidate, update stable accounting only where
justified, perform mandatory REVIEW consolidation plus `ORIENTATION.md`, and authorize at most one bounded
successor.

TB23-R1 stale-evidence cleanup retired five superseded per-turn records; the review must index them in the CP4c
consolidated folded-document index with their line counts: TB22 report 112, CB25 report 115, CB26 report 111,
consumed TB23 plan 200, invalid TB23-EXEC report 100.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB23-REV-CAND-01` | **NEW / ACTIVE / TEST INFRASTRUCTURE / NON-GATING** — `test_data_root()` fails open, so a missing fixture tree produces a pseudo-ledger instead of one typed stop. Owner: the next Code + Build turn already changing source; **not** CB26. |
| `M3-CP4c3-TB23-REV-CAND-02` | **ACTIVE / ORCHESTRATION / RUNTIME RE-PROVED** — CB26's corrected execution view completed TB23-R1 successfully with `resolved_rule=sibling`; formal closure/classification belongs to TB23-R1-REV. |
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
4. `Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` — current review authority until TB23-R1-REV replaces it.
5. `M3_CP4c_Frozen_Definitions.md` — prohibited lists and premise-bearing definitions; do not reinterpret them from failure names.
6. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
7. `Required_Green_Selector_Manifest.md` — selector counts, hashes, prefixes, current role.
8. `M3_CP4c_Consolidated_Record.md` — required during review to index the five per-turn files retired by TB23-R1.

Exact next is `M3-CP4c-3-TB23-R1-REV`. Review the valid semantic RED evidence; do not rerun Directional or patch source/tests before classification.
