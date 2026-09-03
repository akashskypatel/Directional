# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in
`M3_CP4c_Frozen_Definitions.md` Part VI; selector files remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-CB21`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime authority** | **`M3-CP4c-3-TB18`** — source `57635e87306a416daabb8321e1f36fa9c788d208`, selector 383, run/job `33785382790 / 100748821924`, **375 PASS / 8 RED** |
| **Current runtime selector** | **383** — `a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c` |
| **CB21 semantic source** | **`b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`** — product correction complete, compile green, runtime-free |
| **TB19 selector** | **384** — `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`; 383 exact prefix; sole append `GlobalTopologyPlan.FragmentOwnerDeficitPublishesCorrectionEvidenceThroughProductionPath` |
| **TB19 immutable package** | CB21 run/job `33794307778 / 100778238374`, result artifact `9908695433`, ZIP SHA-256 `efb65c06cc6d73d233ee271a31fc82705d2575da313fb7f18b389a5196441fc5` |
| **TB18 ledger** | `a99c31d84200cb97e78bb399fa32c76bea1f3767092f29fc339c4cc9130604ed`; reds 366/367/368/369/370/371/372/374 |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **85** |

---

## 2. CB21 correction is built; runtime credit is pending

TB18 established that the fragment-owner equality was unsound for legitimate shared global ownership. CB21 has
implemented the authorized correction:

- the only semantic relaxation is `ownerCount != expected` → **`ownerCount > expected`**;
- the high-side mismatch remains fatal with the CB20 failure envelope unchanged;
- a low-side owner deficit is retained as typed evidence and no longer fails the validation site;
- exact local triangle-chord arrangement evidence publishes local fragment count and interior chord crossings;
- bounded per-arc shared-orbit, per-trace terminal-slit, and global orbit census evidence is published through the
  production path;
- selector 384 appends exactly one production-path contract to frozen selector 383.

The first compile exposed two local C++ construction/name-qualification defects and executed no runtime. The
surgical correction produced final semantic source `b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`. Authoritative compile-only
run/job `33794307778 / 100778238374` then built all eight standard targets green with GMP/GMPXX, clean source state,
28-entry package manifest, and `runtimeExecution=false`.

**Nothing in CB21 is accepted runtime behavior yet.** TB18 remains the current runtime authority until TB19-EXEC
consumes the immutable CB21 package.

---

## 3. Exact next turn — `M3-CP4c-3-TB19-EXEC`

Binding plan: `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Plan.md`.

TB19 must execute selector **384** from immutable artifact **`9908695433`**, one identity per fresh process, with
no configure/compile/link/repair/source/test/fixture/selector/package mutation. Mandatory discriminators:

1. ordinals **1–365 remain 365/365 PASS**;
2. ordinal **366** no longer stops at `TraceCutFaceFragmentCountMismatch`;
3. **367/371/372** move past that same validation site;
4. face `(0,1,102)` retains owner deficit **1**, local fragment count **2**, and shared chord
   `trace=1 / arc=15 / segment=4`;
5. the arc/trace/orbit census is published, including arc 15 shared-orbit state and trace 1 terminal-slit state;
6. carried surfaces **368/369/370/374** are compared against TB18 and must be reported without forcing an expected
   result.

Ordinal 384 is executed exactly once. TB19 must preserve an exact per-identity ledger and prove pre/post package
byte-and-mode census identity. A semantic RED is valid evidence and routes to review; no patch or later CB belongs
inside TB19.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the current index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB17-CAND-01` | **ACTIVE / CORRECTION IMPLEMENTED, RUNTIME UNVERIFIED** — equality owner proved at TB18-REV; CB21 changed only the low-side fatal predicate. Closes only when TB19 proves ordinal 366 moves past this site. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / EVIDENCE** — local-fragment invariant depends on non-crossing chord arrangement; CB21 now publishes local count/crossing evidence, but no fatal local assertion is authorized before runtime review. |
| `M3-CP4c3-TB10-REV-CAND-01` | **ACTIVE / TEST-COUPLING / DEFERRED** — 371/372 shared-fixture precondition; TB19 must observe their post-fragment frontier independently. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374; no atlas invariant may be weakened for it. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract; still no vertex-30 discriminator. |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — zero-node / zero-arc closed-surface cut-graph behavior, ordinal 370; no correction authorized. |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

Closed candidates remain closed unless new immutable runtime evidence reopens them.

---

## 5. Settled facts a successor must not reopen

- The face walk is a validated total permutation; its orbits are its cycles. Shared orbit ownership by the two
  sides of one arc is legitimate topology, not automatically a merge defect.
- `|global owners| = k+1` is not a valid universal invariant. CB21's only semantic correction is the low-side
  relaxation; **high-side owner count remains fatal**.
- CB21's local fragment count, chord-crossing state, shared-owner chord list, bridge/orbit census, and terminal-slit
  census are **observational**. No local-fragment fatal assertion is authorized yet.
- BS9-5 remains retired; do not enable its environment-gated duplicate text diagnostic in the artifact-only gate.
- Accepted ordinals 1–365 remain the load-bearing boundary. Compile success cannot advance that authority.
- CB12 through CB20 corrections stand; CB21 does not authorize unrelated sphere, saturation, ordinal-370,
  folded-cone, vertex-30, or finalize/contact work.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first.
2. **this file** — current state and exact next turn.
3. `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Plan.md` — **binding TB19 execution contract**.
4. `Architecture_M3_CP4c3_CB21_Code_Build_Report.md` — immutable CB21 source/package/selector authority.
5. `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Report.md` — comparison runtime authority.
6. `M3_CP4c_Frozen_Definitions.md` Part VI — normative definitions and amendments.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `M3_CP4c_Consolidated_Record.md` — only when historical lineage is required.

**Review tooling.** `.agents/Directional/tools/` remains read-only helper authority. Do not use it to mutate the
immutable TB19 package.

**Document consolidation.** This was a Code + Build turn, not a REVIEW turn. The current CB21 report and unconsumed
TB19 plan remain live documents and are not folded.
