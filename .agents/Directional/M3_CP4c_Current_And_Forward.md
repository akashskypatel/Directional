# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in
`M3_CP4c_Frozen_Definitions.md` Part VI; selector files remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB19-EXEC`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime authority** | **`M3-CP4c-3-TB19`** — source `b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`, selector 384, run/job `33798040003 / 100790444711`, **376 PASS / 8 RED** |
| **Current runtime selector** | **384** — `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564` |
| **Immutable package** | compile run/job `33794307778 / 100778238374`, result artifact `9908695433`, ZIP SHA-256 `efb65c06cc6d73d233ee271a31fc82705d2575da313fb7f18b389a5196441fc5` |
| **TB19 artifacts** | result/log `9910078670 / 9910079341` |
| **TB19 ledger** | `e9ab64a8392aa1e16e30e03f440865914df846567e4b4fd12f3dce241841c04b`; reds 366/367/368/369/370/371/372/374 |
| **Package census** | pre/post identical: `c238668140634325a75dbb48ed23ce5659376cb5d2d7b79f3f3f46ab275e133d` |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **85** |

---

## 2. What TB19 proved

CB21's one-sided fragment-owner correction is now runtime evidence rather than compile evidence:

- accepted ordinals 1–365 remain **365/365 PASS**;
- ordinals **366/367/371/372** all clear `TraceCutFaceFragmentCountMismatch`;
- ordinal **384** `GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath` passes;
- face `(0,1,102)` retains owner/expected/deficit `1/2/1`, local fragment count 2, one non-crossing shared chord
  trace 1 / arc 15 / segment 4 / forward+reverse orbit `0/0`;
- production census is untruncated: 70 face rows, 26 arc rows, 12 trace rows; arc 15 `sharesOrbit=true`, trace 1
  `terminalSlit=false`, total/exterior/non-exterior orbit counts `6/0/6`;
- 368/369/370/374 retain the same terminal semantics as TB18.

The later mechanical frontier is now
**`UncutFaceComponentOrbitSeedNotUnique`, source face `(0,1,2)`**, reached by 366/367/371/372. The emitter rejects
an unlabeled face component unless the set of neighboring orbit seeds has exactly one element. TB19 retains the
affected face but not that component's seed count or seed rows, so **zero seeds versus multiple seeds is not yet
adjudicated**. Do not infer it from the global six-orbit census.

The full selector therefore remains red at **376 PASS / 8 RED**. CP4c-3 does not close.

---

## 3. Exact next turn — `M3-CP4c-3-TB19-REV`

Binding plan: `Architecture_M3_CP4c3_TB19_Independent_Review_Plan.md`.

This is **independent REVIEW + PLAN only**. No runtime, compile, package, product/test/fixture/selector mutation,
retry, or successor CB is allowed inside the turn.

The review must:

1. re-verify TB19 immutable authority and no code drift for any static source used;
2. determine whether the `(0,1,2)` component seed set is provably zero, multiple, or still unobservable;
3. compare the historical torus same-code stop without assuming same mechanism from the code name;
4. adjudicate the local-fragment non-crossing candidate: current mechanical evidence is 70/70 non-crossing and
   untruncated, but one witness is not automatically a universal theorem;
5. decide the continued 371/372 atlas-only shared-fixture coupling;
6. keep 368/369/370/374 under their existing owners unless evidence proves movement;
7. update regression accounting, `ORIENTATION.md`, and perform mandatory REVIEW-turn consolidation;
8. freeze exactly one smallest justified successor only after those measures are discharged.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the current index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / GATING / REVIEW-OWNED** — newly exposed unlabeled-component orbit seed set is not unique at `(0,1,2)`; zero-vs-many is not retained. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / EVIDENCE / REVIEW-OWNED** — TB19 mechanical witness has 70/70 locally evaluated non-crossing face arrangements; universal scope remains unproved. |
| `M3-CP4c3-TB10-REV-CAND-01` | **ACTIVE / TEST-COUPLING / DEFERRED** — 371/372 read only the atlas but still abort in the all-products fixture at the new downstream mechanical frontier. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374; no atlas invariant may be weakened for it. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract; still no vertex-30 discriminator. |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — zero-node / zero-arc closed-surface cut-graph behavior, ordinal 370; no correction authorized. |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

`M3-CP4c3-TB17-CAND-01` is **CLOSED BY TB19**: its runtime condition was that 366 move past the fragment-owner
low-side mismatch, and 366/367/371/372 all do so with accepted 365/365 preserved.

Closed candidates remain closed unless new immutable runtime evidence reopens them.

---

## 5. Settled facts a successor must not reopen

- The face walk is a validated total permutation; its orbits are its cycles. Shared orbit ownership by two sides of
  one arc is legitimate topology.
- `|global owners| = k+1` is not a valid universal invariant. CB21's low-side relaxation is runtime-proved; high-side
  owner overcount remains fatal.
- The current mechanical witness's 70 retained local chord arrangements are all evaluated and non-crossing, with no
  truncation. This is **witness evidence**, not yet a universal product invariant.
- `UncutFaceComponentOrbitSeedNotUnique` means an affected unlabeled component has seed cardinality other than one;
  TB19 does not say whether that cardinality is zero or multiple.
- Identical typed error names across witnesses do not establish identical root cause.
- BS9-5 remains retired.
- Accepted ordinals 1–365 remain the load-bearing authority.
- 368/369/370/374 are unchanged carried surfaces with separate owners.
- Vertex 30 and finalize/contact remain separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first and update during this REVIEW turn.
2. **this file** — current state and exact next turn.
3. `Architecture_M3_CP4c3_TB19_Independent_Review_Plan.md` — binding review measures CR0–CR8.
4. `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Report.md` — current immutable runtime authority.
5. `Architecture_M3_CP4c3_TB18_Independent_Review_Record.md` — current preceding review authority until TB19-REV
   supersedes it.
6. `M3_CP4c_Frozen_Definitions.md` Part VI — normative definitions and amendments.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `M3_CP4c_Consolidated_Record.md` — historical lineage and folded-document index.

**Review tooling.** `.agents/Directional/tools/` remains read-only helper authority.

**Document consolidation.** The exact next turn is REVIEW, so it must update `ORIENTATION.md` and perform the
mandatory review-turn consolidation before closeout.
