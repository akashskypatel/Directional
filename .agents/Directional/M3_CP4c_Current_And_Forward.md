# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in
`M3_CP4c_Frozen_Definitions.md` Part VI; selector files remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB20`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime authority** | **`M3-CP4c-3-TB20`** — source `c5d3c65936e14e1c3e2c8afcffbc4236f37aa131`, run/job `33809177155 / 100826787667`, **380 PASS / 8 RED** |
| **Current gate selector** | **385** — `164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca`, 388 identities, selector 384 and accepted 365 exact prefixes |
| **Compile authority** | run/job **`33805683152 / 100815534364`**, result artifact **`9912976409`**, ZIP SHA-256 `b4cbcbf5304ff94bd815790264ac360fa1275f23b3af2080cffda381a698a851`, GMP/GMPXX |
| **TB20 artifacts** | result/log **`9914226104 / 9914226799`** |
| **Ledger** | `0a4d8b17abd4e397bb80ff0fa92b70bc50e971589e368d1cdf2ecef85868203a` — 380 + 8 = 388, closes |
| **First red** | ordinal **366**, `UncutFaceComponentOrbitSeedNotUnique`, component **0**, `seedState=Multiple`, seed count **3**, seed orbits **`[0,1,3]`** |
| **Red set** | 366, 367, 368, 369, 370, 371, 372, 374 |
| **Package census** | pre/post identical, `f0b1beec127dacbec9b356630ce8d9e7364de55a5b014598ee67fcdab653c5b0` |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **85** |

---

## 2. The current frontier — three-seed `Multiple` branch measured

TB20 confirms CB21's one-sided fragment-owner correction remains settled: accepted 1–365 are 365/365, the red set
is unchanged, ordinal 384 remains green, and 366/367/371/372 still reach the later component-seed frontier rather
than `TraceCutFaceFragmentCountMismatch`.

The mechanical `UncutFaceComponentOrbitSeedNotUnique` branch is no longer ambiguous. Immutable production evidence
at ordinal 366 reports component **0**, component face count **191**, seed count **3**, typed state **`Multiple`**,
and exact untruncated seed orbits **`[0,1,3]`**. `sourceFace=(0,1,2)` remains explicitly typed as the first
unlabeled face in iteration order and therefore remains a non-discriminating locus. The historical torus occurrence
is still the distinct zero-seed branch and is not merged with the mechanical candidate.

Boundary evidence is bounded by contract: 64/97 boundary rows and 64/191 face rows are retained and marked
truncated. The retained boundary window has 46 seed-contributing rows (44×orbit 0, 1×orbit 1, 1×orbit 3) and 18
barrier skips. It contains no `edgeOrbitEvidenceNotUnique` skip row, but that absence cannot be generalized to the
33 unretained rows. Ordinal 386 separately proves that the projection preserves that reason when it exists.

TB19 and TB20 are two consecutive TB turns with 371/372 stopped by the same downstream mechanical frontier. The
standing trigger in `M3-CP4c3-TB10-REV-CAND-01` is therefore factually satisfied; the next independent review must
adjudicate the previously specified test-only atlas-scoped decoupling.

---

## 3. Exact next turn — `M3-CP4c-3-TB20-REV`, independent REVIEW + PLAN

Run `Architecture_M3_CP4c3_TB20_Independent_Review_Plan.md` under **CW0–CW9**, planning-only.

The review must independently re-verify TB20 provenance/immutability; prove the `Multiple`/count-3/component-0
branch from immutable evidence; trace orbits 0, 1 and 3 back through the component/barrier/neighbor seed producer;
keep the torus zero-seed case separate; decide whether the bounded 64/97 boundary evidence is sufficient for one
semantic correction or whether one smallest additional evidence contract is genuinely unavoidable; preserve CB21
and accepted 365/365 authority; adjudicate the now-triggered 371/372 test-coupling action; keep 368/369/370/374
under their existing owners; and freeze exactly one bounded successor.

No implementation, test/fixture/selector mutation, compile, benchmark, or runtime is authorized during TB20-REV.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / GATING / BRANCH RESOLVED: MULTIPLE / SEMANTIC OWNER PENDING** — TB20 measures component 0, seed count 3, orbits `[0,1,3]`; owner is TB20-REV CW1–CW4. |
| `M3-CP4c3-TB19-REV-CAND-02` | **CLOSED / SATISFIED EVIDENCE CONTRACT** — CB22 retained the discriminator and TB20 runtime-proved it. Reopen only if CW4 identifies one concrete missing field necessary to choose the next correction. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED** — a universal non-crossing invariant is refuted by `TraceIntersection`; `localFragmentCount` remains non-fatal. |
| `M3-CP4c3-TB10-REV-CAND-01` | **ACTIVE / TEST-COUPLING / STANDING TRIGGER REACHED** — TB19 and TB20 leave 371/372 at the same downstream mechanical frontier; TB20-REV must adjudicate the test-only atlas-scoped decoupling. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. No atlas invariant may be weakened for it. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared bound on its input size. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368, `CellularityNotEstablished` originating `RotationSystemInconsistent / TraceEventPositionInvalid`, trace 2 / event 30. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — zero-node / zero-arc closed-surface cut-graph behaviour, ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

`M3-CP4c3-TB17-CAND-01` remains CLOSED. The historical torus `UncutFaceComponentOrbitSeedNotUnique` record remains
separate from the mechanical three-seed candidate.

Other closed candidates remain closed unless new immutable runtime evidence reopens them.

---

## 5. Settled facts a successor must not reopen

- **CB21's correction is runtime-proved** and must not be reverted. `|global owners| = k+1` is not a valid
  universal invariant; the low-side relaxation stands and high-side owner overcount remains fatal.
- **The reported `sourceFace` of `UncutFaceComponentOrbitSeedNotUnique` is an iteration artifact**, and the torus
  stop of the same name is a different mechanism.
- **The current mechanical branch is `Multiple`, not `None`:** component 0 has exactly three retained seed orbits `[0,1,3]`.
- **A universal chord non-crossing invariant is refuted**; `localFragmentCount` must not become a fatal oracle
  without the crossing derivation and a crossing witness.
- The face walk is a validated total permutation; its orbits are its cycles. Shared orbit ownership by the two
  sides of one arc is legitimate topology.
- **BS9-5 remains retired.**
- Identical typed error names across witnesses do not establish identical root cause.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first.
2. **this file** — current state, candidate index, exact successor.
3. `Architecture_M3_CP4c3_TB20_Artifact_Only_Test_Benchmark_Report.md` — current immutable runtime authority.
4. `Architecture_M3_CP4c3_TB20_Independent_Review_Plan.md` — exact next plan, CW0–CW9.
5. `Architecture_M3_CP4c3_TB19_Independent_Review_Record.md` — current prior review authority and frozen CB22 rationale.
6. `M3_CP4c_Frozen_Definitions.md` Part VI — normative definitions and amendments.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed; its folded document index resolves folded per-turn records.

**Review tooling.** `.agents/Directional/tools/` holds read-only helpers: `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes and ordinal ↔ identity lookups, and
`fixture_probe.py` for fixture topology, dihedrals and vertex fans. See `tools/README.md` for caveats.

**Document consolidation.** TB20-REV must perform the mandatory REVIEW-turn consolidation before closeout under
`CLEAN_UP_POLICY.md`, after preserving every durable fact in retained authority.
