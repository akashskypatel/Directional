# Architecture M4-CP3-CB3 Code + Build Plan — test-authority recovery for the §17 parity baseline

**Status:** AUTHORITATIVE / FROZEN BY `M4-CP3-TB1-PLAN` / RUNTIME-FREE PLANNING
**Planning source authority:** `2a3dcd3cbfd4a862262f76efc10fbce975b7c154`
**Evidence source:** package118 semantic source `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`
**Accepted runtime predecessor:** package117 / selector382 **382/382**
**Candidate under recovery:** package118 / selector394 **387/394**, unpromoted
**Execution mode:** canonical Code + Build
**Exact next turn:** `M4-CP3-CB3`

## 1. Objective

Repair only the two non-stable test-authority defects adjudicated by `M4-CP3-TB1-REV` and independently upheld by the verification amendment at source `2a3dcd3c...`:

1. ordinals **386, 388, 389, 390, 391, 394** must reach their intended §17 baseline semantics on a DCEL-valid triangular-boundary disk rather than dying inside the one-face mesh helper;
2. ordinal **392** must exercise reverse-ordinal breakpoint consumption on a span whose final count is independently guaranteed to exceed one;
3. every previously blocked identity must emit a deterministic success-visible runtime receipt so a later green cannot be mistaken for a vacuous path.

This turn is a **test-authority recovery control experiment**. Product-source changes are exactly zero unless new compile evidence proves the frozen review diagnosis impossible; if that occurs, stop and return to review rather than broadening implementation scope.

## 2. Frozen scope

### Allowed source change

Only:

- `tests/GlobalConformityBaselineTests.cpp`

No production source, public API, selector, fixture file, benchmark source, CMake/build logic, workflow reusable, normative definition, or accepted selector382 row may change.

### Required unchanged authorities

- `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §17;
- selector394 identity names, order, and exact file bytes;
- selector394 first 382 rows byte-identical to accepted selector382 SHA-256 `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`;
- full selector394 SHA-256 `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- package117 / selector382 remains accepted authority until a later TB review promotes a successor.

## 3. Correction A — replace the invalid one-face triangle helper, not the DCEL contract

Keep the existing helper name and its six call sites, but replace the helper's internal mesh with the smallest DCEL-valid triangulated disk that preserves the same triangular outer boundary and exactly three source-boundary edges.

Use four vertices:

```text
v0 = (0,    0,    0)
v1 = (1,    0,    0)
v2 = (0,    1,    0)
v3 = (0.25, 0.25, 0)   // interior, binary-exact coordinates
```

and three consistently oriented faces:

```text
(0,1,3)
(1,2,3)
(2,0,3)
```

This preserves outer boundary edges `(0,1)`, `(1,2)`, `(2,0)`, gives every face interior adjacency, and therefore exercises the production topology/baseline path without weakening `TriMesh` validation or recognizing the test environment.

Do **not**:

- relax `DCEL::check_consistency`;
- add a test-only production bypass;
- skip `set_mesh()` or source-authority construction;
- replace the intended three-terminal topology with a square merely because the square helper already passes.

## 4. Correction B — make ordinal392's interior-breakpoint precondition independent of current output

Keep ordinal392's identity and permutation/reverse-ordinal assertions. Change only its target-size fixture from `0.5` to `0.25` for the unit-edge first span.

The precondition is independently derivable from frozen preferred-count authority, not from current implementation output:

- first span support is the unit edge `(0,1)` split into two equal support pieces;
- each half contributes `||Δ||² / h² = (1/4)/(1/16) = 4`;
- two pieces sum to `8` and support multiplicity `m_s = 2`, so exact `R_s = 16`;
- nearest-integer `sqrt(R_s)` gives preferred `d_s = 4`;
- §17.6 permits only final `x_s = 4` (no flip) or `x_s = 3` (flip), hence `x_s > 1` in either primary-optimal parity state.

Add an explicit fixture-precondition assertion that the selected entry has `preferredCount == 4`; keep `ASSERT_GT(entry.count, 1)` and all existing forward/reverse exact-ordinal and `localDenominator` assertions. Do not replace them with current-output constants.

## 5. Non-vacuity hardening and success-visible receipts

Add `<iostream>` only if needed for deterministic receipt emission. Receipt values must be read from live test objects after the intended assertions/calls have executed; do not hard-code a pass marker detached from the tested state.

Use one stable line prefix per corrected identity:

```text
M4_CP3_BASELINE_RECEIPT ordinal=<N> ...
```

Required receipt content and minimum assertion strengthening:

| ordinal | required success-visible evidence |
|---:|---|
| 386 | live component count, `hasExterior`, `exteriorDemandOdd`, terminal-span count after the existing exterior assertions |
| 388 | live exact count vector, minimum flip count, and lex-receipt count after the canonical lex assertions |
| 389 | explicitly assert/emit the preferred and final counts for both map cases: `1 -> 2` and `d>1 -> d-1`; use fixture-derived values, not a hard-coded success flag |
| 390 | extend the independent exhaustive-oracle helper with test-only counters for **all assignments examined** and parity-feasible assignments; assert the examined count equals `2^preferred.size()` and emit the actual comparison counts plus winning flips/count vector |
| 391 | count each of the nine existing tamper-validator calls as it is actually executed; assert/emit `tamperRows=9` only after all nine calls have run. Preserve every existing tamper assertion; do not merge families or weaken expected rejection |
| 392 | emit `preferredCount`, final `entry.count`, forward exact ordinal, reverse exact ordinal, and both live local denominators after the breakpoint assertions |
| 394 | emit live topology boundary-incidence count and produced baseline incidence count after the equality assertion; retain both compile-time structural-separation `static_assert`s unchanged |

For ordinal389, strengthen the preconditions so the name is proved rather than inferred: the chosen one-case entry must have preferred `1` and final `2`; the chosen larger-case entry must have independently fixture-derived preferred `2` and final `1`. If the canonical entry selected by the current test no longer has those fixture-derived preferred values after Correction A, select a span by its source/support identity rather than by an incidental vector position. Do not change production scheduling to satisfy the test.

For ordinal390, `assignmentsExamined` is the exhaustive mask count, not the number of times a best-so-far branch wins. This makes the receipt independently auditable and distinguishes a full oracle pass from an early/empty loop.

## 6. Compile/package verification — Code + Build only

The CB3 turn may author the test-only changes above and compile/package them, but must execute **no Directional runtime**: no generated test discovery, no test binary invocation, no CTest, no benchmark, no CLI/help/version probe.

Use the mandatory GitHub compile workflow with GMP/GMPXX linkage evidence. Compile the same approved package surface used by CB2 so the later artifact can prove both the accepted predecessor and the corrected selector:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Package a new immutable candidate only after compile success. The package number is assigned by the build; do not predeclare promotion or reuse package118.

CB3 compile acceptance requires:

- all approved targets link successfully with mandatory GMP/GMPXX proof;
- source status clean;
- package manifest internally verifies in full;
- command-boundary evidence states `runtimeExecution=false`;
- packaged source contains **no product-source differences** from `c8d8fc8...` attributable to CB3, only the planned test-source correction plus intervening documentation/control history;
- selector394 exact bytes/hash and selector382 prefix hash remain unchanged.

## 7. Deferred runtime validation — corrective TB only

CB3 does not claim recovery. Its successor must execute a new immutable artifact, tentatively `M4-CP3-TB1-R1-EXEC`, with no rebuild or repair.

The corrective TB must repeat the comparable gate on fresh processes:

1. rows 383-394 focused pass A;
2. rows 383-394 focused pass B, with identical ordered verdict vector;
3. accepted predecessor selector382, expected **382/382**;
4. cumulative selector394, expected **394/394**;
5. immutable package/source/execution-view pre/post censuses and full package manifest verification.

Additional acceptance requirement from the independent amendment: for each previously blocked ordinal **386, 388, 389, 390, 391, 392, 394**, each focused process must contain exactly one matching `M4_CP3_BASELINE_RECEIPT` line. The harness must reject missing or duplicate receipts and compare pass-A/pass-B receipt bytes for determinism. It must additionally parse and enforce:

- 390: nonzero oracle comparison counters and `assignmentsExamined == 2^spanCount`;
- 391: `tamperRows == 9`;
- 392: `preferredCount == 4`, `entryCount > 1`, forward ordinal `1`, reverse ordinal `entryCount-1`, both denominators equal `entryCount`.

A green selector without these receipts is **insufficient evidence** and must not promote the package.

## 8. Acceptance and stop conditions

If CB3 compiles/packages cleanly, stop at the Test + Benchmark boundary. Do not execute runtime in CB3.

If a planned test-only edit cannot compile without product-source changes, if selector bytes change, or if the prescribed fixture cannot instantiate the intended topology, stop and return to review with evidence. Do not opportunistically modify A3 implementation, A4 cutover code, DCEL validation, CMake, or the selector.

Also stop if ordinal390's oracle cannot be made faithful to §17.6 per §10 V4 — a fixture that instantiates correctly can still invalidate that oracle's single-XOR model, and no other stop rule in this plan catches it.

Package promotion and A3→A4 production cutover remain forbidden until the corrective TB and its review accept the new evidence.

## 9. Planning disposition

`M4-CP3-TB1-PLAN` requests **no additional independent Review**: the user supplied an independent verification amendment at `2a3dcd3c...`, both findings were upheld, and this plan incorporates its added non-vacuity/receipt obligations. This plan is therefore the authoritative successor Code + Build plan.

**Exact next:** `M4-CP3-CB3`.

---

## 10. Independent review addendum (reviewing agent, `M4-CP3-TB1-PLAN` review)

Runtime-free. The plan is **accurate and complete** on everything it covers, and the turn type is
right: repairing test source is Code + Build work, not artifact-only TB work. One unchecked
precondition is added to §5 as a required guard, because the fixture change in §3 can invalidate
ordinal390's oracle without tripping any stop rule in §8.

### V1 — Correction A verified

The replacement mesh is a valid DCEL disk and preserves exactly what the six identities depend on.
`V - E + F = 4 - 6 + 3 = 1` with edges `(0,1) (1,2) (2,0)` on the boundary and spokes `(0,3) (1,3)
(2,3)` interior; `v3 = (0.25, 0.25, 0)` is strictly inside the triangle (`x + y = 0.5 < 1`) and
binary-exact. Every face shares an edge with both others, so interior adjacency holds.

This matters concretely: ordinal386 hard-codes `ASSERT_EQ(1U, components.size())` and
`EXPECT_EQ(3U, component.terminalSpans.size())`. A fan triangulation adds interior vertices and
edges but **no new boundary edges**, so both survive. The "do not replace with a square" prohibition
is therefore not stylistic — a square would carry four terminals and break that assertion.

### V2 — Correction B verified against the implementation, not just restated

The derivation matches `derive_preferred_count_exact`
(`src/geometry/GlobalConformityBaselineSupport.cpp:191-237`) exactly. Per half-edge,
`squaredLength / midpointTarget² = 0.25 / 0.0625 = 4`; two pieces sum to `8`; the function then
multiplies by `supportPieces.size() = 2`, giving `energy = 16`. Rounding at a perfect square resolves
correctly: `floor = 4`, `odd = 9`, and `4·16 = 64 <= 81 = 9²·1`, so `nearest = 4`. Hence `d_s = 4`,
and §17.6 admits only `x_s = 4` (no flip) or `x_s = 3` (flip) — both `> 1` in either primary-optimal
parity state, so the precondition is genuinely independent of which branch the scheduler takes.

The unit-edge premise also holds: `make_square_mesh()` (`tests/GlobalConformityBaselineTests.cpp:53-65`)
places `v0 = (0,0,0)` and `v1 = (1,0,0)`, so the first span's carrier has length 1 and each half 0.5.

§5's instruction to select ordinal389's entries by preferred count rather than position is a second
quiet fix: that identity currently reaches its `1 -> 2` case through `exact_counts(...).back()`, which
the new span set would otherwise silently re-aim at a different span.

### V3 — pinned authorities verified

Hashed directly: full selector394 is
`6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`, matching §2 byte-for-byte, and its
first 382 rows remain accepted selector382 `1d59b1f7…`.

### V4 — REQUIRED ADDITION: ordinal390's oracle is only valid for single-incidence spans

`exhaustive_terminal_parity_oracle` (`:240-266`) reduces the whole feasibility question to **one
global XOR**: it accumulates `parity ^= count & 1` over every element of its input. That models §17.5
correctly only when each span contributes to exactly one region parity exactly once — true today,
because the one-face triangle yields three boundary terminals and nothing else. The helper's own name
says "terminal".

Ordinal390 does not filter. It builds `preferred` from **every** entry of `schedule()` (`:391-394`)
and passes the lot in. §3 adds three interior edges to the fixture. If any of them becomes a span, it
is incident to the single disk region twice, and §17.6 classifies it as a **self-loop with zero parity
effect** — production will correctly ignore it while the oracle XORs `count & 1` for it anyway.
Whenever an odd number of such spans carries an odd count, oracle and production disagree and
ordinal390 goes RED again for an entirely new reason.

Whether the interior edges actually become spans depends on `FieldAlignedCurveNetwork` / cut-graph
construction and is not statically decidable from the fixture, so this is a conditional risk — but the
plan currently leaves it to chance. §8's stop rule does not catch it: the fixture would instantiate
the intended topology perfectly and still break this identity. §5's receipt hardening does not catch
it either, since the oracle would run and count its assignments correctly while modelling the wrong
constraint.

**Required in CB3, before compile acceptance.** Make the oracle faithful to §17.6 rather than assuming
its input shape. Either is acceptable:

1. weight each span by its region-incidence multiplicity, contributing `(m_s · x_s) mod 2` — which is
   `x_s & 1` for `m_s` odd and `0` for `m_s` even, so same-region double incidences correctly vanish; or
2. keep the single-XOR oracle and **assert its precondition**: every span fed to it has exactly one
   boundary incidence, with the self-loop spans asserted separately to contribute zero.

Option 1 is preferred — it makes ordinal390 a real independent oracle for the general §17.5 rule
rather than one valid only for a hand-picked fixture, and it removes the coupling between this
identity and future fixture choices. Either way, emit the per-span multiplicities used in the
ordinal390 receipt so the model the oracle applied is auditable from the log.

If the fixture turns out to yield exactly three single-incidence spans, this change is still required:
it converts an unstated assumption into a checked one at negligible cost.
