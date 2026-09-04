# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-04** at `M3-CP4c-3-CB27` closeout.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.** TB23-R1 remains the latest valid semantic runtime authority; CB27 is the latest compile
authority and does not change acceptance.

| Authority | Current value |
|---|---|
| Latest semantic runtime authority | `M3-CP4c-3-TB23-R1` — 389 PASS / 8 RED, accepted 365/365 |
| Runtime RED ordinals entering TB24 | 366, 367, 368, 369, 370, 374, 393, 397 |
| CB27 semantic source | `9c72fea8b666534b9e52fa42bbe8cbf8ae68ffe5` |
| CB27 immutable package | `9935929108`, SHA-256 `b5e11a2c97c110d2cf484d63bb3afe3b753e7f4769098ec927a5cf1692f5d881` |
| Current selector | selector 401, 401 identities, `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869` |
| Frozen prefix | selector 397, `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5` |
| CB27 compile evidence | run/job `33870767698 / 101015974984`; log `9935929698` |
| Exact next | `M3-CP4c-3-TB24-EXEC` — immutable artifact-only runtime |

Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3
package count **89**. CB27 ran no Directional runtime, so these runtime totals are unchanged by construction.

## 2. The current frontier — ownership is now published; runtime proof is next

**Runtime authority — `M3-CP4c-3-TB23-R1`.** Selector 397, 389 PASS / 8 RED, accepted 1–365 = 365/365. The
mechanical actual embedded complex is certified cellular: `V=22, E=26, F=6, componentCount=1, χ=2, residual=0`.

**Definition authority — `M3-CP4c-3-DEFN-R3`, Part VII of `M3_CP4c_Frozen_Definitions.md`.** CB27 implements its
CG0–CG9 successor contract. The certifier now publishes the total source-face owner map from its own embedded
topology and face walk, `proves_cellularity()` requires total owner/orbit provenance, and `GlobalTopologyPlan` uses
that map as authority instead of rebuilding seed ownership. The old uniqueness guard is relocated to certified
owner consistency. The CB25 unrelated-locus regression is fixed without relaxing ordinal 397; ordinal 393 is
replaced in place by the owner-map contract. `test_data_root()` is fail-closed.

Selector 397 remains byte-identical and is the exact prefix of selector 401. New gating ordinals 398–401 cover the
production owner-map contract, owner-orbit tamper rejection, independent consistency-rule falsifiability, and
fail-closed package/fixture resolution. No runtime has yet established whether component 0's 191 certified owners
are all equal.

---

## 3. Exact next turn — `M3-CP4c-3-TB24-EXEC`

Artifact-only runtime against immutable CB27 package `9935929108`. Execute the frozen selector-401 plan
from `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Plan.md`. No rebuild/relink/repair/mutation.

Mandatory outputs: accepted 1–365 count; owner-map totality on mechanical; complete 191-face component-0 owner
multiset and all-equal discriminator; relocated ordinal-366 guard evidence; green 393/397; carried-surface report;
and independent 398–401 results. EXEC does not diagnose semantic REDs.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB23-REV-CAND-01` | **IMPLEMENTED / RUNTIME UNPROVED / TEST INFRASTRUCTURE / NON-GATING** — CB27 makes `test_data_root()` fail closed; ordinal 401 is the runtime witness. Owner: TB24. |
| `M3-CP4c3-TB23-REV-CAND-02` | **ACTIVE / ORCHESTRATION / RUNTIME RE-PROVED** — CB26's corrected execution view completed TB23-R1 successfully with `resolved_rule=sibling`; formal closure/classification belongs to TB23-R1-REV. |
| `M3-CP4c3-TB23-R1-REV-CAND-01` | **IMPLEMENTED / RUNTIME UNPROVED / PRODUCT** — CB27 removes the unrelated `;cutCandidateCount=0`; frozen ordinal 397 must prove it at TB24. |
| `M3-CP4c3-TB23-R1-REV-CAND-02` | **IMPLEMENTED / RUNTIME UNPROVED / DIAGNOSTIC CONTRACT** — CB27 replaces ordinal 393 in place with the published owner-map contract; the ordinal stays gating. |
| `M3-CP4c3-DEFN-R3-CAND-01` | **MITIGATED / RUNTIME UNPROVED / ARCHITECTURAL / NON-GATING** — CB27 makes the certifier-published map authoritative to the plan, so independent reconstruction is no longer ownership authority; runtime proof is TB24. |
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / ARCHITECTURAL / GATING / UNADJUDICATED** — CB27 now exposes the authoritative owner map. TB24 must report all 191 component-0 owners as all-equal or not-all-equal; review owns classification. |
| `M3-CP4c3-TB22-REV-CAND-01` | **NEW / ACTIVE / EVIDENCE INTEGRITY** — two production diagnostics report values that cannot vary; ordinal 393 pins the vacuous contract as required-green. Owner: CA1–CA3 and CA6. |
| `M3-CP4c3-TB21-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 391 passes with the sphere half explicitly skipped. |
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

Exact next is `M3-CP4c-3-TB24-EXEC`; execute the immutable CB27 package under the frozen artifact-only plan and stop at the review boundary on semantic RED.
