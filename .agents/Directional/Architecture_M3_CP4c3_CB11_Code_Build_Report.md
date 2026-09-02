# M3 CP4c-3 CB11 — Code + Build Report

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-CB11`
Status: **COMPLETE / BUILD GREEN / DIAGNOSTIC-ONLY / RUNTIME NOT EXECUTED**

## Governing authority and boundary

`M3-CP4c-3-CB11` executed the frozen **BB0–BB9** measures from
`Architecture_M3_CP4c3_TB8_Independent_Review_Record.md`. The turn was diagnostic-only: it was permitted to add or
carry diagnostic state and compile it, but it was forbidden to repair the `terminalContact` fall-through or change
tracing, election, ownership, termination, fixture, or acceptance semantics.

No Directional runtime test, benchmark, `ctest`, generated test discovery, CLI/help/version command, fuzzer, or custom
runtime input was executed in this turn. Every compile/package boundary records `runtimeExecution=false`.

## Exact source authority

- TB8-REV planning/base authority: `1ad5d2191c65cd1af7443559a6446236ec499ecd`.
- Main CB11 diagnostic implementation commit: `d8eb6332e10804bd847d3b10911efbcb75c39688`.
- Compile-only linkage correction commit: **`803300698289e0d0f629eaa878add1aebc7193c1`**.
- Final semantic/evidence source for CB11 and package 79: **`803300698289e0d0f629eaa878add1aebc7193c1`**.

The linkage correction moved the diagnostic witness wrapper out of an anonymous namespace so that its header-declared
external symbol links. The wrapper body and diagnostic behavior are unchanged; the correction does not change any
product decision.

## BB0–BB9 implementation result

- **BB0 — frozen authority preserved.** Selector 374 remains
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`; selector 375 remains
  `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`; the accepted 365 prefix is untouched.
  Every authoritative compile used mandatory GMP/GMPXX linkage.
- **BB1 — production projection is lossless for the trace-scoped diagnostic group.** The production failure DTO and
  `network_failure_locus` now carry/render `traceSeedVertex`, `traceSeedSingularity`, bounded `traceHistory`,
  `traceSteps`, `traceStepBudget`, `traceCombinatorialVisits`, `traceCombinatorialVisitAllowance`, `singularity`,
  `rail`, `relatedSourceFace`, `relatedBranch`, `signedLift`, `parameter`, `exactValues`, `publishedEdges`, and
  `publishedFaces`. Exact values remain exact reduced strings. `traceHistory` is capped at eight entries with count
  and explicit truncation state.
- **BB2 — typed per-site discriminator added.** All twelve `InvalidNetworkTerminalOwnership` emission conditions have
  distinct `FieldAlignedCurveNetworkErrorCondition` values. The existing `InvalidNetworkTerminalOwnership` error
  enum name/value is unchanged.
- **BB3 — `publishedFaces` made honest.** The production error now carries the actually published face authority and
  the renderer reports its real count rather than an unassigned default.
- **BB4 — consumer audit widened by predicate.** The audit covered every network-error field without a production
  projection counterpart, including `publishedEdges`, which the frozen measure did not enumerate in its short list.
  Ordinal 329's losslessness coverage is re-aimed at the production projection/renderer rather than only the
  test-local `network_error_locus`.
- **BB5 — both surviving sites are statically reachable through the production renderer.** Dedicated witnesses drive
  the singularity-port ownership site and the finalize/contact fall-through site through the same production
  finalization/projection surface and require their distinct typed conditions plus trace context.
- **BB6 — selector 376 appended only for the demonstrated projection gap.** Selector 376 has exactly 376 identities,
  SHA-256 **`6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`**, and selector 375 is its unchanged
  375-line byte prefix. Identity 376 is
  `ResolvedBranchCorrection.NetworkTerminalOwnershipConditionsSurviveProductionFailureProjection` and has zero gate
  credit pending TB9 execution.
- **BB7 — semantic prohibitions preserved.** The `terminalContact` fall-through is diagnosed, not repaired. No
  tracing/election/ownership/termination decision, fixture, sphere/370/saturation/folded-cone behavior, or acceptance
  criterion was changed.
- **BB8 — accepted-output audit.** The accepted 365 prefix and the frozen 374/375 bytes are unchanged; the source
  changes add diagnostic fields/rendering/witness coverage only. Runtime equivalence is not claimed from a CB turn.
- **BB9 — TB9 discriminators published.** The frozen TB9 plan below names the five exact observations required before
  any product correction is authorized.

## Compile evidence

### First compile attempt — diagnosed deterministic link failure

Run `33573114762`, compile job `100071187094`, exact source `d8eb6332e10804bd847d3b10911efbcb75c39688`.
GMP preflight succeeded and no runtime executed, but linking `directional_surface_cell_producer_tests` failed with an
undefined reference to
`directional::geometry::surface_cell_tracing_detail::diagnose_finalize_field_aligned_events(...)`.

Cause: the new diagnostic wrapper was defined inside `SurfaceCellTracing.cpp`'s anonymous namespace while its header
declaration requires external linkage. The smallest correction moved that definition outside the anonymous namespace;
no body or control-flow change was made.

Failure log artifact: `9825824850`, SHA-256
`5cd3987a24e9c16ba5987a41ec7183247db4868886298d7957f01f56fee4d884`.

### Authoritative compile retry — PASS

Run/job **`33573956609 / 100073749252`** compiled exact source
**`803300698289e0d0f629eaa878add1aebc7193c1`** through the mandatory reusable compile workflow.

All required targets compiled and linked:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

GCC 13.3.0, GMP/GMPXX discovery/link verification, compile preflight, full build, source-cleanliness checks, and the
fixed compiler-cache contract all passed. The run records `runtimeExecution=false`.

- compile result artifact **`9825961944`**, Actions SHA-256
  **`d3e8a50d880e4f8f5179718b7c91288a50b6755e8ec0d6d94e29c3da1ead3b99`**;
- compile log artifact **`9825962219`**, Actions SHA-256
  **`8f2e44d981900265836e8fc139cc1327b8169e139d94ac7f38e82f3937a0a0b3`**.

## Immutable package 79

Package run/job **`33574167362 / 100074416093`** consumed compile artifact `9825961944` without executing any
Directional binary. It verified the exact source, compile manifest, GMP evidence, source cleanliness, all four
selector hashes/cardinalities/prefix relations, 27 package-relative fixtures, six executable-mode test binaries, and
internal SHA-256 manifests before and after deterministic extraction.

- package artifact **`9826005253`**, Actions SHA-256
  **`1f9c6e1d098a08eb375d415f2724185043de1c1d5d08cdce46cc716d57e3fa8a`**;
- package log artifact **`9826005535`**, Actions SHA-256
  **`3e38135aee557d1b24b99e09c68165d1d5529442f6c47c85318bc1c207eff5ad`**;
- inner deterministic `package79.tar.gz` SHA-256
  **`dfc197b50ea5b9b88468aa00665470af5aa0e2959de9c380fcd6aebdb978ec99`**;
- packaged source archive SHA-256
  **`61107e4fc90368793ebe97c3581cea6cb301effc74c6f39cc3259316066aa0f6`**.

Package metadata records `package=79`, `source_commit=803300...`, `runtimeExecution=false`, `packageRepair=false`,
`exactArithmeticBackend=GMP`, and `modePreservingEnvelope=true`.

## Acceptance/accounting

CB11 is **build-complete**, not runtime acceptance. Accepted semantic authority therefore remains **365/365** and
CP4c-3 remains **OPEN**. Stable regression accounting remains **44 events / 14 categories / 30 recurrences**;
produced-witness debt remains **5**. Creation of package 79 advances the authoritative semantic M3 package count
**75 → 76**.

`M3-CP4c3-TB8-REV-CAND-01` is closed at the implementation/build boundary: the missing production projection and the
mis-aimed losslessness witness were corrected and compiled. Runtime proof that identity 376 survives the immutable
production path is deliberately deferred to TB9. `M3-CP4c3-TB8-CAND-01` remains active/gating because only TB9 can
name which of the two proved ownership sites fires on ordinal 366.

## Exact successor

**`M3-CP4c-3-TB9` — artifact-only Test + Benchmark on immutable package 79, selector 376 from ordinal 1.** Use
`Architecture_M3_CP4c3_TB9_Artifact_Only_Test_Benchmark_Plan.md`. No product correction is authorized in TB9; a
valid semantic result routes to mandatory independent `M3-CP4c-3-TB9-REV`.
