# Directional Surface-Cell Roadmap — accepted state to production-ready

**Purpose.** One forward-looking map from the current accepted gate to a production-ready
implementation of `DESIGN.md`. It exists because `DESIGN.md` §14 defines milestones **M0–M8** with
acceptance criteria but decomposes none of them into checkpoints, and only M3 had ever been decomposed
— inside a plan document, mid-milestone, under schedule pressure. Every prior milestone that started
without a checkpoint decomposition had to acquire one at cost.

**Authority.** `DESIGN.md` §14 owns *what* each milestone must prove; this file owns *how it is cut
into checkpoints*. If the two conflict, `DESIGN.md` governs and this file is corrected.
`TODO.md` owns the current open task list; this file is not a task list and must not accumulate one.

**Status date:** 2026-08-26 (CP4c-0 TB-R3 valid semantic red: 338 executed, 336 pass, reds at ordinals 333/334 — both test-side; independent review closed; exact next `M3-CP4c-0-CB4` under measures G0–G8).

---

## 1. Where the project actually is

| Milestone | State | Accepted authority |
|---|---|---|
| M0 | historical prerequisite | artifacts retained as regression/oracle evidence only |
| M1 | **CLOSED / ACCEPTED** | `M1_Closure_Record.md` |
| M2 | **CLOSED / ACCEPTED** | `M2_Closure_Record.md` |
| M3 | **in progress — 4 checkpoints remaining** | CP4ab **316/316**, `157bf784… / 9527801615` |
| M4–M8 | not started | — |

M3 checkpoint state: CP0 (compile evidence only), CP1, CP2, CP2b, CP3a, CP3b, **CP4ab** are closed.
`M3-CP4-DEFN` is complete. CP4a/CP4b are superseded into CP4ab.

**CP4c was split on 2026-08-25** by `Architecture_M3_CP4c_TB_R1_Independent_Review.md` after TB-R1
returned VALID RED 316/322. Its two committed witnesses are **closed surfaces** — torus χ = 0 genus 1,
mechanical χ = 2 sphere — while every witness that has ever validated A2b is a **bounded disc**, χ = 1.
Two of the three failure families are therefore scope gaps in *accepted* authority, not CP4c defects.

Cumulative gate has grown 304 → 316 and reaches 322 across four checkpoints — `M3-CP4c-0` was inserted on 2026-08-25 as a blocking predecessor to CP4c-1.

---

## 2. Trajectory check against `DESIGN.md` §14 M3

`DESIGN.md` §14 M3 lists six acceptance criteria. Current disposition, each traced to the identity that
owns it:

| DESIGN §14 M3 criterion | Owner | State |
|---|---|---|
| singularity ports derived from field index, owned exactly once | A1 / A2a | accepted at CP1/CP3 |
| traces branch-consistent and provably non-crossing | A2a | accepted at CP3a/CP3b |
| every trace terminates at a typed network event; no silent interior termination representable | A2a | accepted at CP3b; **completed** by CP4ab's terminal 0-cell correction, and re-proved by C5 |
| every emitted region carries a disc-topology proof | A2b | **accepted at CP4ab** (B1, B4) |
| network selection preserves mandatory topology under tamper | A2b | accepted at CP4ab (A4, A5) |
| tracing-order and start-port permutation invariance | A2b | accepted at CP4ab (A6) |

**Verdict: the trajectory is correct and the milestone is nearly discharged.** Every M3 criterion has
an owning identity and five of six are green under a cumulative immutable gate.

The one substantive gap is not a criterion but a *scope* of proof: all six are proven on **development
witnesses** (the two-ring skew disc and the four-triangle fan), not on production-representative
meshes, and — as the CP4c plan establishes — **A2b is not yet constructed by the production pipeline at
all**. That is exactly and only what CP4c exists to close. See
`Architecture_M3_CP4c_Code_Build_Plan.md` §0.

---

## 3. M3 exit — the remaining checkpoint

CP4c's production A2b wiring (CB1) and its two production-path fixtures (CB2) are **built and
compiled**, and TB-R1 proved the wiring regressed **nothing**: the accepted 316 are green in the same
immutable run. What remains is split into three checkpoints. Identity names are unchanged from DEFN
§7.3; only their allocation moved.

| Checkpoint | Domain | Gate | State |
|---|---|---|---|
| **`M3-CP4c-0`** | resolved interval pairing with propagated barycentric positions (`DESIGN.md` §4.5) | **338 = 316 + 12 + 10**, frozen by CB2 | **TB-R3 VALID SEMANTIC RED, 336/338, review closed** — all 338 executed under F6 continue-and-observe; accepted 316 and prior 328 prefixes green; reds at ordinals 333 (fixture builds a DCEL-invalid single-triangle mesh) and 334 (oracle assumed a portable branch label) — **both test-side, production correct at both sites**; identity 338 green confirms the degenerate-entry family is gone from the sphere; **the sphere still does not publish a network**, so Q8 is expected red next cycle; next `M3-CP4c-0-CB4` under G0–G8 |
| **`M3-CP4c-1`** | diagnosability, witness observability, event non-vacuity | **318 = 316 + C4 + C5** | **OPEN, blocked on CP4c-0** — TB-R2 VALID RED 316/318; next `M3-CP4c-1-CB3` under Z0–Z5 |
| **`M3-CP4c-2`** | closed / higher-genus region authority in A2b | **321 = 318 + C1 + C3 + C6** | needs `M3-CP4c-2-DEFN` first |
| **`M3-CP4c-3`** | closed-surface missing field-transport adjacency in A1, then the mechanical witness | **322 = 321 + C2** | needs `M3-CP4c-3-DEFN` first |

> **`M3-CP4c-0` exists because `DESIGN.md` §4.5 is half-implemented, and its definitions are now frozen**
> in `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`. §4.5 requires the inflow/outflow interval
> pairing to be *resolved* with **barycentric positions propagating in arbitrary precision**. Measured by
> the TB-R3 census: two-ring **50%** ambiguous, fan **25%**, torus **50%**, sphere **50%** — the exact
> signature of `dbary = {-u-v, u, v}` summing to zero, so a face is either `2×1` or `1×2` with no third
> case. **The gap is two missing data:** the entry position on trace segments, and the barycentric
> direction, which A1 computes and then discards. The DEFN freezes `FieldBoundaryPoint` (single writer
> A2a, canonical-edge parameter, exact rational), an exact minimum-ratio continuation with **no tolerance
> in any topological decision**, deletion of the Cartesian `connections`, and unification with the CP4ab
> barrier-terminus datum **without reopening CP4ab**. It proves that **no accepted witness's traces
> change**, because old and new rules agree on every `2×1` face and no accepted trace can ever have
> traversed a `1×2` one.

> **`M3-CP4c-2-DEFN` inherits a `DESIGN.md` §7.2 gap.** §7.2 derives the network from singularities,
> features, and boundaries; a closed surface with an index-free field has none of the three, so §4.6's
> motorcycle graph is empty — its size is `O(n)` in extraordinary nodes. Measured: the committed torus
> publishes **0 traces / 0 events**, and A2b then has no labeled face to seed region ownership from.
> Quad-remeshing a torus needs a **seam / cut graph the architecture cannot currently produce.** That
> DEFN must settle it before any genus > 0 code is written.

Historical CP4c turns, retained for provenance: `CB1` (wiring, W0–W5), `DG1` (the last diagnostic turn
this project will run), `CB2` (W7–W9), `TB-R1` (VALID RED 316/322).

CP4c-1's TB-R2 is **VALID RED 316/318** with the accepted 316 green in the same run. C4/C5 remain the only
required blockers and **stay gating**; demotion to non-gating was considered and rejected. They cannot pass
until CP4c-0 lands.

CP4c-0's artifact-only TB proves the exact-continuation focused gate **328/328**, but frozen Q8 is red:
the prescribed sphere reaches A1 then A2a rejects `BranchContinuationDegenerateEntry` before network
publication. CP4c-0 remains unaccepted and CP4c-1 blocked.

**CB2 → TB-R2 executed that correction, and `M3-CP4c-0-TB-R2-REVIEW-PLAN` closed on 2026-08-26**
(`Architecture_M3_CP4c0_TB_R2_Review_Plan_Independent_Review.md`). CB2 is build green at
`390e65b373063c667e3c3f5e78b74ed9d859093b` / package `9586196535` with the selector re-frozen at
**338 = 316 + 12 + 10**. TB-R2 re-proved the accepted **316/316** and the prior **328/328** prefix, then
failed at ordinal **329** on the first E1 correction identity: `FieldBranch::value()` returns
`std::uint8_t`, which stream insertion writes as a **character**, so `branch=1` emitted as `\x01`. Q8 was
correctly **NOT RUN**.

Review verdict: the failure is **solely** that formatting defect at two call sites — and it exposes a real
frozen gap, because Amendment 5 required a property of the emitted *value* and never constrained the
*mechanism*. A second defect of the same shape was found: ~15 trace-seed back-fills that E1c's
line-scoped wording never reached. Both are **class defects certified by instance falsifiers**, which is
the lesson of the cycle. E1–E9 were independently re-verified as correctly implemented; E2 and E3 in
particular are exactly as amended. **Amendment 6** now defines "observable" by mechanism. Exact next is
**`M3-CP4c-0-CB3`** under measures **F0–F8**. Identity **338** and **Q8** remain the open questions.

**CB3 → TB-R3 executed that correction, and `M3-CP4c-0-TB-R3-REVIEW-PLAN` closed on 2026-08-26**
(`Architecture_M3_CP4c0_TB_R3_Review_Plan_Independent_Review.md`). F1/F2 are runtime-proved and F6
worked — all 338 identities executed despite an early red, which is why this cycle returned a complete
picture rather than one bit. Two identities are red and **both are test-side**:

- **ordinal 333** throws `compute_edge_quantities(): DCEL consistency check failed` before the predicate
  under test runs. The fixture builds a **single-triangle** mesh, and `DCEL::check_consistency`'s
  `checkPureBoundary` rejects any face with no interior edge — so every candidate is invalid regardless
  of coordinates. The near-degenerate coordinate search is a red herring;
- **ordinal 334** is an oracle defect **originating in the reviewer's own E8 specification**.
  `FieldBranch` is **gauged per face** by `build_face_branch_frame`, so iterating one numeric label
  across four faces compares four different physical directions. The gauge model derived from source
  reproduces the observed `0, 1, 0, 3` admitted-face counts exactly.

**Production is correct at both sites** — `build_branch_transports` already corrects every lift by the
per-face gauge difference, and all three cross-face branch steps in production use it. **Amendment 7**
records that `FieldBranch` is not a portable identifier, and that a required falsifier may not assert
that a witness *fails*.

**The finding that outranks both reds:** the supplemental falsifier's passing `ASSERT_FALSE(networkBuild)`
proves **the prescribed sphere still does not publish a network**. Q8 is therefore expected to fail next
cycle even at 338/338, and nothing in the gate currently publishes the sphere's rejection code.
Measures **G4** and **G5** address both. Exact next is **`M3-CP4c-0-CB4`** under **G0–G8**, test-side only.

**`M3-CP4c-0-TB-REVIEW-PLAN` closed that adjudication on 2026-08-25**
(`Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md`). Verdict: **neither T6 nor Q8 is at
fault, and neither is weakened.** A1 decides the **sign of a barycentric direction coordinate** with a
`double` tolerance in three separate places and publishes those verdicts as topological ownership
(carrier-set membership, vertex-sector membership), while A2a's new continuation rule decides the same
sign exactly on the same published datum. Where they disagree — the band `|d| ≤ 1e-10`, widened further
by a lossy barycentric→world→barycentric round trip — A1 hands A2a a state A2a is correct to reject.
The defect is in the CP4c-0 frozen definitions, which asserted that surviving tolerance was harmless;
five amendments were issued. **CB2 is now BUILD GREEN** at `390e65b373063c667e3c3f5e78b74ed9d859093b` after a verification-first audit found E1–E9 already present; the required selector is **338 = 316 + 12 + 10**. Exact next is **`M3-CP4c-0-TB-R2`**, artifact-only runtime. After E2–E5, T6 is *provably unreachable* from any well-formed production state.

**No budget.** Attempt and diagnostic budgets and the `DG` turn type were abolished on 2026-08-25. Workflow is `CB → TB → (red) → REVIEW+PLAN → CB`; a red TB consumes nothing and mandatorily routes to review.

---

## 4. M4–M8 — proposed checkpoint decomposition

Not yet frozen. Each milestone below is cut by the rule this project has applied since M1: **one
checkpoint carries one independently testable semantic domain.** Gate arithmetic is cumulative —
every checkpoint carries the full accepted predecessor selector plus its own frozen identities.

Each milestone opens with its own `-DEFN` planning turn. That is not ceremony: CP4's DEFN was the
turn that caught an undefined disc-proof certificate before code was written against it, and M1 paid
twice for skipping the equivalent. **A `-DEFN` turn is planning only and runs nothing.**

**A `-DEFN` turn must now also state, for each witness it names, which product stage that witness has
been *proven* to reach** — not that its files exist. CP4c's failure was exactly this omission.

### M4 — global conformity plan (`DESIGN.md` §14 M4)

Entering gate **322**.

| Checkpoint | Semantic domain | Notes |
|---|---|---|
| `M4-DEFN` | freeze the schedule product, its rejection vocabulary, its independent oracle, and witness provenance | planning only |
| `M4-CP1` | shared-rail breakpoint/side-count **schedule product** with one writer | positive + tamper |
| `M4-CP2` | **assignment positivity certificate** and typed subset-scoped infeasibility | infeasible subsets must not fail the run |
| `M4-CP3` | producers **consume** the verified schedule; target-size variation cannot change breakpoints | invariance |
| `M4-CP4` | M4 exit gate — removes the exact-torus `InvalidHardRailPairing` blocker without post-hoc pairing; work/solver bounds reported with an explicit monotone measure | cumulative |

M4 owns `G4-B002`'s three produced-witness debts.

### M5 — certificate-carrying chart and quotient relations (§14 M5)

| Checkpoint | Semantic domain |
|---|---|
| `M5-DEFN` | freeze canonical relation IDs, path certificates, and the tamper matrix |
| `M5-CP1` | canonical relation ID domain and explicit path certificates, replacing verifier-side reachability reconstruction |
| `M5-CP2` | typed failure for missing / duplicate / conflicting / nonreciprocal / representation-renumbered relations |
| `M5-CP3` | M5 exit — torus lineage and quotient acceptance from direct production evidence; unused valid relations provably do not alter the selected certificate |

M5 owns `G4-B003`'s two produced-witness debts.

### M6 — occurrence, embedding, independent verification (§14 M6)

| Checkpoint | Semantic domain |
|---|---|
| `M6-DEFN` | freeze the four stage products and the verifier's recompute boundary |
| `M6-CP1` | separate occurrence creation / quotient construction / geometry embedding as complete stage products |
| `M6-CP2` | verifier consumes certificates and independently recomputes elementary incidence; **never repairs producer state** |
| `M6-CP3` | M6 exit — equal coordinates without a relation remain distinct; every owned relation consumed exactly once; source-row / output-row / scheduler permutation invariance |

### M7 — disposition and graded degradation (§14 M7)

Sequenced after M6 by explicit design decision in `DESIGN.md` §14: disposition is a statement *about*
the verified product, so implementing it earlier reproduces the silent-substitution failure §3
diagnoses. **Do not resequence this.**

| Checkpoint | Semantic domain |
|---|---|
| `M7-DEFN` | freeze `OutputDisposition`, `DegradationCertificate`, and verifier layer 7 as one vertical contract |
| `M7-CP1` | tier assignment by the **verifier only**, never a producer; tier cannot be raised mid-run |
| `M7-CP2` | declared degraded region producer — pure quads conforming exactly to the unmodified plan, cannot mutate upstream products |
| `M7-CP3` | M7 exit — unrecorded and fabricated degradation both fail typed; omitted-region bookkeeping reconciles with quotient relation consumption; tier/degraded/omitted invariant under every §10.1 permutation; **no strict fixture gate closes on a degraded result** |

### M8 — module boundaries and operational hardening (§14 M8)

| Checkpoint | Semantic domain |
|---|---|
| `M8-CP1` | target module layout; forbidden producer/verifier dependencies made unavailable; `construction/` cannot depend on `disposition/` |
| `M8-CP2` | diagnostics, resource accounting, packaging, CI hardening; no semantic equality includes execution handles or backend choice; diagnostics cannot feed semantic decisions |
| `M8-CP3` | **production-ready exit** — every `DESIGN.md` §2.1 certified-acceptance condition met on the full witness set, and **no architecture-debt item in `Regression_Root_Cause_Tracker.md` remains open** |

`M8-CP3` is the production-readiness definition. It is not met while any of `G4-B001`–`G4-B004` is
open.

---

## 5. Open product blockers, and who owns them

These are **not** M3 obligations and must not be claimed closed by M3 evidence.

| Blocker | Stage | Owner |
|---|---|---|
| `G4-B001` / `PR8-R034` / `G4-R007` | completion/materializer — hard rail promoted into `IsolationSheetId` authority, rejected by `close_completion_lineage_source_authority(...)` | M6 at the earliest; adjudicate at `M6-DEFN` |
| `G4-B002` | rail scheduling | M4 |
| `G4-B003` | quotient/chart relations | M5 |
| `G4-B004` | unassigned | adjudicate at `M4-DEFN` |

Produced-witness debt stands at **5** and is discharged by M4 (3) and M5 (2).

---

## 6. What "production ready" means here

From `DESIGN.md` §2.1, unchanged and not restated in full: a run is production-ready when the certified
acceptance conditions hold on the full witness set with no degraded result closing a strict gate, under
the §10.1 determinism requirements, with the §15 stop conditions never triggered.

Operationally, that is `M8-CP3`. The path is: **CP4c-0 → CP4c-1 → CP4c-2 → CP4c-3 → M4 (4 checkpoints) → M5 (3)
→ M6 (3) → M7 (3) → M8 (3)**, plus two CP4c `-DEFN` turns and five milestone `-DEFN` turns. Nineteen
checkpoints remain.

This decomposition is a **proposal until each milestone's `-DEFN` turn freezes it.** Gate arithmetic
beyond 322 is deliberately not fixed here — freezing identity counts before the domain is defined is
the failure `M3-CP4-DEFN` was created to prevent.
