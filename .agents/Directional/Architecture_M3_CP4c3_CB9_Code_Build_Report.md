# M3 CP4c-3 CB9 — Code + Build Report

Date: 2026-09-01 UTC
Turn: `M3-CP4c-3-CB9`
Type: **Code + Build only / runtime-free**
Governing authority: `Architecture_M3_CP4c3_DEFN_R2_Frozen_Definitions.md` measures **AY0–AY9**
Verdict: **PASS — implementation compiled and packaged; semantic acceptance remains pending TB7**

No Directional runtime, test executable, gate, or benchmark was executed as valid CB9 evidence. The earlier local compile
performed during an interrupted continuation violated project procedure and is explicitly excluded from authority.

## 1. Immutable authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Frozen semantic base: `095461e2a749e39c4b344805748b1e3bd870a063`
- CB9 implementation source commit: `e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a`
- Accepted authority remains selector **365** until TB7.
- Selector 373 remains byte-identical:
  `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.
- Selector 374 is the single AY6 append:
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`,
  exactly 374 unique identities, with selector 373 as an unchanged byte prefix.
- `selected_gate=NONE`; `gate_execution_authorized=false`.

## 2. AY1–AY7 implementation

CB9 replaces candidate-local vertex-transit election with the frozen Amendment-22 authority:

- `VertexStarRaySeed` stores one immutable exact arrival ray per arrival event, in the arrival face chart, pointing
  away from the source vertex back along the incoming trace.
- The admissible incident fan is walked in source-topology order and developed from that single seed. Candidate-local
  cross representatives remain audit data only.
- `signedLift` is used only for branch-label correspondence; it is not used as arbitrary geometric-ray transport.
- Election uses the frozen straightest-geodesic continuation `β = α + Θ/2` and preserves the existing exact
  half-open sector ownership convention.
- The numeric path is a certified filter plus a reachable exact radical-elimination fallback. The published exact
  fan-length budget is **16** and over-budget input fails closed as `VertexStarExactBudgetExceeded`.
- The other frozen typed states are implemented and published:
  `VertexStarTruncatedBeforeContinuation` and `VertexStarDegenerateSector`; exact radial ownership is represented by
  `onRadialRay` plus the radial-ray identity.
- Diagnostics are written before fail/skip disposition, and the complete AX8 seed/kernel/development/election/failure
  contract is projected through `RemeshPipeline.cpp::network_failure_locus` into `RemeshDiagnostics`.
  This closes the implementation/projection debt `M3-CP4c3-TB6-CAND-01`; runtime validation is still owned by TB7.

## 3. AY5 falsifying folded-fan witness

The committed witness is `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection`
with two companion exact-boundary cases.

Geometry is the rational three-sector cone

- center `O=(0,0,0)`;
- radial vertices `(1,0,0)`, `(0,1,0)`, `(0,0,1)`;
- three consistently oriented incident faces.

Each incident angle has exact `D=0, P=1, Q=1`, hence each sector is exactly `π/2` and the cone angle is

`Θ = 3π/2 != 2π`.

The star is non-coplanar. For the strict-interior seed, `α=atan(1/2)` and Amendment 22 gives
`β=α+3π/4`, strictly inside face `(0,2,3)`. The old mechanism is evaluated independently from the published
candidate-local representatives and accepts **two** eligible target sectors. The frozen one-ray authority elects
exactly **one** owner, with no candidate ordering or tie-break.

The deliberate continuation-boundary instance has `α=π/4`, so `β=π` exactly. It therefore reaches the
`ExactFallback` route and the unchanged half-open convention owns the radial ray with exactly one sector.
A third instance seeds exactly on an arrival radial ray and verifies the exact half-open arrival convention.

This is the required semantic discriminator that vertex 30 alone could not provide. AY5 therefore legitimately
authorizes the one-line selector-374 append.

## 4. AY8 assumption audit

The audit was performed statically against the exact packaged source and deliberately names sites outside those
enumerated by DEFN-R2.

### `M3-CP4c3-CB9-AUDIT-01` — consumer re-expression seam

`src/authority/FieldTransportAtlas.cpp::build_boundary_pairing` computes barycentric `u/v` in `double`
(lines 114–127 in the CB9 source), converts those computed values with
`FieldExactRational::from_double_exact`, then uses the resulting exact-coordinate signs to classify
`FieldBoundaryFlow::Inflow/Outflow` and populate incoming/outgoing carriers.

That matches the audit predicate **“a value reaching a topological decision was re-expressed by its consumer.”**
It predates the CB9 vertex-star authority and is outside AY1–AY7's bounded semantic change. It is retained as an
explicit follow-up candidate; CB9 does not broaden scope to repair the atlas.

### `M3-CP4c3-CB9-AUDIT-02` — generic exact input-size contract

`include/directional/authority/FieldTransportAtlas.h::FieldExactRational::integer_sqrt_floor`, reached through
`rational_square_root` / `sqrt_bounds`, performs exact integer Newton iteration whose work scales with arbitrary
`EInt` bit width. It has an implementation overflow guard but no published reusable bit-width budget.

The CB9 vertex-star path remains within DEFN-R2's frozen contract: its source values originate in finite IEEE-754
mesh storage and the load-bearing algebraic growth parameter, fan length, is explicitly capped at 16 with a typed
fail-closed state. The generic exact utility nevertheless satisfies AY8's second search predicate and is recorded as
a separate hardening candidate rather than silently treated as universally bounded.

Both AY8 findings are static audit findings, not runtime regression events. Stable event/category/recurrence totals
therefore remain **44 / 14 / 30**.

## 5. Authoritative compile evidence

Two valid GitHub-hosted compile-only runs exist for the same semantic source; the second is the package source of
record.

Changed-owner compile:

- run `33534474873`, compile job `99945346068` — **success**;
- targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_producer_tests`;
- exact source: `e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a`;
- `runtimeExecution=false`.

Final package-producing compile:

- run `33535836292`, compile job `99949862868` — **success**;
- raw result artifact `9811669562`,
  Actions SHA-256 `b5049004f2687eb48abfd40398c87606224cda1b7892bc22d7a2901d6dab16d2`;
- raw log artifact `9811670265`,
  Actions SHA-256 `b0eb4af74dac2f412b419a0f63dc7d8547d395f545f1a89b0064c3c09c0c7c7c`;
- all eight standard targets compiled and linked:
  `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`,
  `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`,
  `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, and `directional_benchmarks`;
- preflight exit `0`, build exit `0`, final source status clean;
- exact backend `GMP`; link evidence contains both `libgmpxx.so` and `libgmp.so`;
- `runtimeExecution=false`.

No executable from either compile was run.

## 6. Immutable package 76

Package workflow run `33536818075`, package job `99953090803` — **success**.

- package artifact `9811964367`, Actions SHA-256
  `5c7d27996aa43ef798aa8110df756fc34bbcb6d490356bdfaea249c3953cc949`;
- package log artifact `9811965163`, Actions SHA-256
  `7c13dd619de35ac9647417278682d0684bcd46c669b586871b801310aa37194f`;
- inner deterministic `package76.tar.gz` SHA-256
  `a940ee61c29a1c4e25040dad6353ad54152a0d6181da3450a8fe771dfc170f8e`;
- packaged source archive SHA-256
  `71b86aafae465b5dcb1763cc3e0250b4310b188d8f2d6e34ac8d7b8c6c74f6ea`;
- exactly 27 package-relative fixture files;
- six packaged `directional_*` executables retain executable mode;
- internal recursive `SHA256SUMS` verified before upload and again after extraction;
- selector 373 and selector 374 hashes verified from the packaged source;
- package boundary: `runtimeExecution=false`, `packageRepair=false`,
  `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`.

Package 76 is the sole immutable runtime input authorized for the successor TB7. CB9 itself assigns it no semantic
gate credit.

## 7. Process deviations retained as material evidence

CB9 crossed several procedural boundaries during interrupted continuations. They are not hidden or converted into
acceptance evidence:

1. repository workflow source was initially inspected before the mandatory conservation-policy read/READ_MODE
   selection; the turn corrected to exact snapshot mode immediately afterward;
2. the first two exact-source snapshot callers failed at workflow startup (`33473454497`, wrong reusable inputs;
   `33473620983`, insufficient caller contents permission) before the successful snapshot run `33473668720`;
3. coherent WIP was allowed to remain local past the mandatory work-preservation barrier, and a local GMP compile was
   run even though Code + Build compilation is required to run through GitHub Actions. That local compile is
   **invalid process evidence and excluded**;
4. after the user correction, WIP2 and then complete WIP3 were emitted user-visible and staged in Drive before remote
   orchestration; WIP3 was applied by the durable Drive workflow to produce semantic commit `e5d6ed76...`;
5. the first authoritative compile caller run `33534164649` had a workflow-startup permission failure and ran no
   jobs. The corrected caller then produced the valid runs above;
6. package-76 workflow publication was subsequently performed through the required pre-publication draft schema
   validation (`33536357034`) before installation.

These failures do not alter semantic accounting because none executed Directional runtime.

The exact whole-turn tool-call total cannot be reconstructed after multiple platform context compactions without
fabricating a number. That ledger loss is itself retained as a process deficiency. The closeout response must report
the reconstructable current-continuation count separately and must not invent the historical total.

## 8. Disposition and successor

CB9 is **Code + Build PASS**: AY0–AY9 are discharged at the implementation/build/package boundary. CP4c-3 remains
**OPEN** because no semantic runtime was authorized in this turn. CP4c-2 remains **CLOSED / ACCEPTED at 365/365**.

Stable accounting remains **44 events / 14 categories / 30 recurrences** and produced-witness debt remains **5**.
The semantic M3 package count advances **73 → 74** with package 76.

The mandatory successor is `M3-CP4c-3-TB7`, artifact-only, against immutable package 76 and selector 374. TB7 must
run the cumulative selector from ordinal 1, one identity per fresh process, with every mutation/build/repair flag
false. A complete **374/374 PASS** closes CP4c-3; any valid semantic red routes to independent REVIEW + PLAN after
the required report-only remainder pass and immutable postflight.
