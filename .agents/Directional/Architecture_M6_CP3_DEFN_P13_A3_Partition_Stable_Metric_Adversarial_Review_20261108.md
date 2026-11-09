# RA-216 — Step 64 (D7) re-entered: an implementable exact count, placement split out, exact CB106 and CB107

**Turn:** `M6-CP3-DEFN-P13-A3-PARTITION-STABLE-METRIC`, re-entered · 2026-11-08 · Claude Review, runtime-free (`REVIEW_TURN_POLICY.md` §4.3). Nothing was built or run. The two patches were checked with `-fsyntax-only` only, and every expected count was recomputed by hand in exact fractions. Product source = CB105 `d96df38e5…`, unchanged at HEAD.

Reviewed: the [D7 decision](Architecture_M6_CP3_DEFN_P13_A3_Partition_Stable_Metric_Review_20261108.md) and its DESIGN §7.4 amendment.

## 1. Verdict

The diagnosis is right, and so is the density model. The decision then freezes a count rule and a breakpoint rule that the exact kernel cannot decide. It bundles a production-affecting change with a production-inert one, and it hands CB106 a design job instead of a patch. CB106's stop rule would therefore have been its likely exit.

RA-216 makes four changes:
- it replaces the unimplementable parts with exact integer rules;
- it splits D7 into a count (now) and placement (D7b, before D5);
- it freezes exact CB106 and CB107, with TB89 and TB90;
- it corrects DESIGN §7.4.

## 2. What stands

- **Root cause.** `GlobalConformityBaselineSupport.cpp:192-239` computes `round(√(m·Σλ²))`. `GlobalConformityBaseline.cpp:739-767` places ordinal j in piece `⌊m·j/n⌋`, and `GlobalConformityBaselineValidator.cpp:845-875` mirrors that.
  - With λ=(0.1, 3.9) the count is 6 against 4.
  - At count 4, the interior ordinals land at x = 0.05, 0.1 and 2.05 instead of 1, 2 and 3.
- **Density model.** ρ = interpolated 1/h is the right choice. Because ρ is affine on each simplex, the trapezoid rule `L·(ρ₀+ρ₁)/2` is exact and additive under collinear subdivision. The alternative, 1/(interpolated h), integrates to a logarithm.
- **Other rules that stand:** canonicalizing contiguous collinear pieces while keeping genuine vertices; halves round down; the minimum count is one; positivity, parity, the T-join, lex-prefix refinement and the single writer are unchanged; D5, D4 and D8 stay separate.

## 3. Findings

- **F1 (high): the count rule cannot be decided as frozen.**
  - A bent path's metric is `Σ_k r_k·√q_k`, and rounding it exactly is the sum-of-square-roots decision.
  - The rational kernel decides one root. The legacy code takes a single root of a squared energy for exactly that reason.
  - The only multi-radical machinery, `vertex_star_algebraic_sign_at_precision` (`SurfaceCellTracing.cpp:944`), enumerates 2^k monomials of its radical basis. A face-crossing trace with k bends would need 2^k.
  - The decision's stop rule ("stop if exact algebraic comparison cannot be implemented within existing limits") was therefore CB106's predictable exit: a DEFN with no reachable success exit (RA-172).
  - **Correction:** each maximal same-direction run has a rational squared metric `S²/|u|²`. Each run contributes ⌊2⁶⁴·metric⌋ by integer square root (`FieldExactRational::sqrt_bounds` already provides this), and the count rounds the sum once, halves down.
    - This is an exact integer function. It is deterministic and invariant to collinear re-splits, reversal and face rows.
    - It lies at most `runs·2⁻⁶⁴` below the exact integral, and always below it, which is consistent with rounding halves down.
  - "Do not approximate, quantize" is withdrawn. DESIGN §7.4 makes target size an *objective with permitted deviation*. A defined exact integer function is neither floating optimization nor tolerance matching.
- **F2 (high): exact metric-inverse breakpoints conflict with the architecture.**
  - Within a straight segment ρ is affine, so the cumulative metric is quadratic, and its inverse is a square root nested over a total that is itself a sum of roots.
  - DESIGN §7.4 requires "a canonical ordered breakpoint sequence in exact source-rail coordinates". Every downstream identity is rational: `boundary_trace_point` takes a `FieldExactRational` edge parameter, and both `exactEdgePoint` and the `SurfaceSharedBoundaryInterval` ordinals are rational.
  - Item 5 handed CB106 an unreviewed representation replacement (a "certified algebraic/implicit witness").
  - **Correction (D7b, §8):** across runs, place ordinals by metric. Within a run, place them linearly in length. The existing (piece, local rational) representation then encodes every location exactly, and for a single-run span the location is today's j/n.
- **F3 (high): a production-affecting change was bundled with an inert one.**
  - The only caller of `breakpoint_location` is curved-disk (`SurfaceCellTracing.cpp:17641`). It accepts only Mandatory arcs with `sourcePath.size()==1` on one source edge (`:17448-17473`), and it rejects `supportPieceIndex != 0`.
  - Counts reach production through parity on every span. Multi-piece placement reaches no output until a multi-piece consumer exists (D5 chains or 65C traces).
  - **Correction:** the count lands now (CB106 → CB107), and placement (D7b) lands before 64B.
- **F4 (medium): three frozen copies were left out of scope.**
  - The same count formula also sits in `GlobalConformityPlan.cpp:36`, `GlobalConformityValidator.cpp:188` and `GlobalConformityCP2Validator.cpp:42`, and piece-index placement sits in `GlobalConformityPlan.cpp:49`. These are framed CP1/CP2 evidence.
  - Production calls only `build_global_conformity_baseline` (`RemeshPipeline.cpp:13018`).
  - D7 changes the baseline only. Changing the framed copies would perturb the accepted CP2 491/491 evidence.
- **F5 (medium): the single-piece effect was not stated, and the digest outcome was left open.**
  - Production target sizes are adaptive per vertex (`RemeshPipeline.cpp:12598-12612`).
  - On one piece the metric moves from `L·2/(h₀+h₁)` to `L·(1/h₀+1/h₁)/2`, which is never smaller (AM–HM). Counts therefore change wherever h varies, even on single-edge spans; with uniform h the two agree.
  - The pipeline's `global-conformity-baseline` debug product hash can therefore change. Because the `tracing` hash embeds `receipt.baselinePlanDigest` (`RemeshPipeline.cpp:2095`), the change carries into later product hashes too.
  - "Preserve pinned digests unless independently justified by the later TB" is not an outcome table. TB89 and TB90 below are.
- **F6 (medium): CB106 was monolithic and not exact.** It bundled the metric, a new breakpoint representation, a validator rewrite and "prescribed focused tests", with no patch. That is the RA-215 F2 defect again.
- **F7 (low): `breakpoint_location` sees no geometry.**
  - `GlobalConformityBaselinePlan::breakpoint_location(span, j)` reads only the schedule entry, so it cannot compute a metric placement.
  - `ConformityScheduleEntry` is shared with the framed plan (`GlobalConformityPlan.h:67`), so widening it would touch frozen types.
  - Owner: the D7b DEFN.
- **F8 (low): two falsifiers were unbound.**
  - "A genuine kink is not equivalent" cannot be tested on a count, because a bent path and a straight path of equal metric rightly share one. It is bound as follows: a direction change starts a new run, so counts add across runs, and a fold-back is not a cancellation. In D7b, a bend vertex bounds a run for placement.
  - "The validator derives independently" is already true: the baseline validator recomputes counts from the input through the shared function (`GlobalConformityBaselineValidator.cpp:360`). The independent oracle is the hand-computed tests. No second implementation is needed.

## 4. Corrected D7 contract (replaces decision items 3–5; DESIGN §7.4 amended)

1. **Runs.** A run is a maximal sequence of consecutive valid support pieces along one direction `u`: same direction means `(d·u)² = |d|²|u|²` and `d·u > 0`. A direction change, including a reversal, starts a new run. Continuity, carrier membership, distinct endpoints and positive finite h are checked exactly as today; any failure gives `DegenerateConformityPath`.
2. **Run metric.** `S = Σ (d·u)(ρ(a)+ρ(b))/2`, where ρ is the barycentric interpolation of exact vertex reciprocals. The run's metric is `S/|u|`, and its square `S²/|u|²` is rational.
3. **Count.** `F = Σ_runs ⌊2⁶⁴·√(S²/|u|²)⌋` by integer square root, and `n_preferred = max(1, ⌊F/2⁶⁴⌋ + [2·(F mod 2⁶⁴) > 2⁶⁴])`. The count is an objective; the existing exact scheduling decides final counts.
4. **Placement (D7b, §8).** Ordinals are spaced by metric across runs and linearly in length within a run, as exact rational source points in the existing representation.
5. **Scope.** The production baseline only.

## 5. Exact CB106 — the D7 count, not yet wired, plus its falsifiers

[Diff](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB106_P13_A3_Partition_Stable_Count_Exact.diff"):
- SHA-256 `2ee8401442bed8e1df7f5f92de199acc18477df3e7e10ed36e56b4d715afb777`, 382 lines; keep its 7 single-space context lines.
- Numstat `86 0` `GlobalConformityBaselineSupport.cpp`, `7 0` `.h`, `238 0` `GlobalConformityBaselineTests.cpp`. It applies cleanly to HEAD.
- `-fsyntax-only` passes for both `.cpp` files. That is a syntax check, not a build.

It adds `derive_partition_stable_preferred_count_exact` (§4.1–4.3) and the helper `exact_reciprocal_target`. The scheduler still uses `derive_preferred_count_exact`, so production output is unchanged.

Three GUARD tests, each value hand-computed:

| Test | Binds | Discriminates |
|---|---|---|
| `D7PreferredCountIsInvariantToSupportSplitsAndReversal` | A length-4 edge as 1, 2, 2, 4 and 7 pieces, each also reversed, gives 4; an irrational face-interior run, whole, cut or reversed, gives 11 | Legacy gives 6 for λ=(0.1, 3.9), 5 for (0.5, 3.5), and 13 for the uneven face cut |
| `D7PreferredCountIntegratesInterpolatedReciprocalTargetAdditively` | With ρ from 1 to 2 over length 4, the count is 6 for cuts {}, {½}, {⅓} and {⅛, ⅝}, and reversed | Legacy midpoint-h gives 5 whole and 6 halved |
| `D7PreferredCountRoundsOnceKeepsDirectionChangesAndFailsClosed` | Metric 4.5 gives 4, whole or cut; 4.5+2⁻³⁹ gives 5; 0.25 gives 1; a 1+4 bend gives 5; the fold-back 0→3→1 gives 5; six malformed spans give no count | Legacy gives 6 on the bend; a sign-blind run merge would give 1 on the fold-back |

Without the product half the tests do not compile. With a wrong metric they fail on the listed values.

Routes:
- mismatch → `M6-CP3-PLAN-P13-A3-PARTITION-STABLE-METRIC-STOP`;
- infrastructure → `M6-CP3-CB106A-P13-A3-PARTITION-STABLE-METRIC-ORCH`.

## 6. TB89 — CB106 full gate

- [Manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB89_P13_A3_Partition_Stable_Count_Full_Gate_Case_Manifest.tsv"): 913 rows, `8a4a6fef2a8b8b6e3c81ef1aa11de8f71dab883ee2d1d43b653f0ab129811ef8`. It is TB87/TB88's 910 rows plus GUARD 911–913. `SELF_CHECK_PASS cases=913 deferred=81`; membership 994; ledger v5 `fd433f54…`; census `3af1dc0d…`.
- **Expected:** 913/913. All 7 `platform-digest` and all 7 `a3-coverage` lines are byte-identical to TB88, because the new function has no production caller.
- Routes: mismatch → `M6-CP3-TB89-P13-A3-PARTITION-STABLE-METRIC-FULL-GATE-REV` (Review, runtime-free); infrastructure → `M6-CP3-TB89A-P13-A3-PARTITION-STABLE-METRIC-ORCH`.

## 7. Exact CB107 — make the D7 count the scheduler's objective — and TB90

[Diff](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB107_P13_A3_Partition_Stable_Count_Switch_Exact.diff"):
- SHA-256 `c1caefb973f8157823018dbd6fcb2d4ff2f47bcf79f41d3ef77d0b216ab9aa5f`, 217 lines; keep its 10 single-space context lines.
- Numstat `2 56` / `1 1` / `52 22`. It applies **only on top of CB106**. Precondition: TB89 MATCH.
- `-fsyntax-only` passes.

The change:
- `derive_preferred_count_exact` delegates to the D7 count, so the producer and the validator both use it.
- The legacy body and its orphaned `exact_target` are removed.
- The CB106 assertions on the former formula now expect D7 values (6→4, 5→4, 13→11, 5→6, 6→5).
- New GUARD 914, `D7PreferredCountIsTheSchedulerObjectiveForEverySplit`: a built and validated plan prefers 4 for one unit edge at h=¼, whole, cut at ⅛ (formerly 5) and halved. All three schedule identical counts.

Routes:
- mismatch → `M6-CP3-PLAN-P13-A3-PARTITION-STABLE-COUNT-SWITCH-STOP`;
- infrastructure → `M6-CP3-CB107A-P13-A3-PARTITION-STABLE-COUNT-SWITCH-ORCH`.

**TB90** `M6-CP3-TB90-P13-A3-PARTITION-STABLE-COUNT-SWITCH-FULL-GATE-EXEC`:
- [Manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB90_P13_A3_Partition_Stable_Count_Switch_Full_Gate_Case_Manifest.tsv"): 914 rows, `45dfbb533ed3668f48a0146a3ce6800f57a2221368380c31c8e60a7974c64607`. `SELF_CHECK_PASS cases=914 deferred=81`; membership 995.
- Expected outcomes:
  - 914/914;
  - all 7 `a3-coverage` lines byte-identical to TB88;
  - census verdicts unchanged: Cylinder PASS, BunnyRandom RED `SingularityPortClassCountMismatch`, Vase RED `AggregateCompletionValidationFailure`.
- `platform-digest`, per line:
  - every token through `global-topology-plan=` is byte-identical;
  - the `/count` suffix of `global-conformity-baseline` is identical;
  - if its hash is unchanged, the whole line is byte-identical;
  - if its hash changed, later product hashes may change (the tracing hash embeds the baseline digest). For the four gate cases and census Cylinder, which uniform or annulus produce (`covered=0`), every later `/count` and `validationIssues` must stay identical. Vase's later tokens are recorded.
- Record every changed baseline hash as the registered D7 rebaseline.
- Routes: mismatch → `M6-CP3-TB90-P13-A3-PARTITION-STABLE-COUNT-SWITCH-FULL-GATE-REV`; infrastructure → `M6-CP3-TB90A-P13-A3-PARTITION-STABLE-COUNT-SWITCH-ORCH`.

## 8. D7b placement — semantics for step 64.5

The step-64.5 DEFN `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT` freezes exact CB108 and TB91.

**Placement rule.** Use the runs and run values `F_r` of §4, the total `F`, and prefix sums `C_r`.
- Ordinals 0 and n stay at the endpoints.
- For 0<j<n:
  - let `T = j·F/n`, and take the run with `C_r ≤ T < C_r+F_r`;
  - set `t = (T−C_r)/F_r`; the point is `a_r + t·(b_r−a_r)`;
  - its piece is the one with `τ_i ≤ t < τ_{i+1}`, where `τ_i = ((a_i−a_r)·u)/((b_r−a_r)·u)`;
  - its local fraction is `(t−τ_i)/(τ_{i+1}−τ_i)`.
- For a single-piece span this is j/n, so curved-disk output is unchanged.

**Questions the DEFN must decide:**
- where the run profile lives. The recommendation is a baseline-only per-span profile that the validator recomputes. Do not widen the shared `ConformityScheduleEntry`.
- whether the single-piece local fraction keeps today's unreduced `(j, n)`, which leaves the width receipts unchanged.
- the matching changes to `observe_compact_breakpoint_widths`, to its validator twin, and to the endpoint and denominator checks at `GlobalConformityBaselineValidator.cpp:845-875`.
- `GlobalConformityPlan.cpp:49` stays frozen.

**Falsifiers:**
- the λ=(0.1, 3.9) edge at count 4 puts its breakpoints at x = 1, 2, 3 (legacy: 0.05, 0.1, 2.05);
- two runs of different density are spaced by metric, and a single run by length (a documented deviation);
- a reversed span maps j→n−j to the same point;
- a collinear re-split gives identical points;
- the single-piece spans that curved-disk consumes are unchanged.

## 9. Sequence

| Step | Turn | Owner | Depends on |
|---|---|---|---|
| 64 | this Review (RA-216) | Claude, runtime-free | COMPLETE |
| **64.1** | **`M6-CP3-CB106-P13-A3-PARTITION-STABLE-METRIC`** | implementation agent, compile only | §5 |
| 64.2 | `M6-CP3-TB89-P13-A3-PARTITION-STABLE-METRIC-FULL-GATE-EXEC` | implementation agent | CB106 |
| 64.3 | `M6-CP3-CB107-P13-A3-PARTITION-STABLE-COUNT-SWITCH` | implementation agent, compile only | TB89 MATCH |
| 64.4 | `M6-CP3-TB90-P13-A3-PARTITION-STABLE-COUNT-SWITCH-FULL-GATE-EXEC` | implementation agent | CB107 |
| 64.5 | `M6-CP3-DEFN-P13-A3-METRIC-BREAKPOINT-PLACEMENT` (D7b) → CB108 → TB91 | Review, runtime-free | TB90 |
| 64B | `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SCHEDULING` (D5); its consumer must accept multi-piece spans | Review | D7b |
| 64C / 64D | uniform / annulus A3 consumption (D4) | Review | 64B |
| 65A–65D | D9c carrier binding, reciprocal trace, A4 disc domain, D8 receipt | Review each | in order |
| 66+ | per-disc corners (D6, user), fill, dispatch | DEFN → CB → TB each | 65D |

## 10. Corrections to the D7 decision

- Items 3 and 5: the exact sum-of-roots rounding and the algebraic inverse are superseded by §4.
- The successor paragraph is superseded by §5–§7, and the stop rule is withdrawn.
- The falsifier rows "genuine kink" and "independent verifier" are rebound by F8. The "two sides share one span" row moves to D7b and D5.
- The decision's closeout claimed handoff currency. Its `load_next` still named TB88; it is corrected here.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change |
| Decisive claims re-derived | Read the count, placement, validator, consumer and framed-copy sites; computed every expected test value in exact fractions (legacy and D7) |
| Non-vacuity | Each test asserts a legacy value that differs from D7; CB107 turns those into D7 values plus a wiring test that fails on CB106 |
| Obligations carried | D7b → 64.5; D5 64B; D4 64C/64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB88 910/910, membership 991; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 | Updated |
| Turn boundary | No product or test source changed in the repository; syntax checks only |
