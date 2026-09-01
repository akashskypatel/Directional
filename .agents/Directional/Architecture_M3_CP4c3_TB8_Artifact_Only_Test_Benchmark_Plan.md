# M3 CP4c-3 TB8 — Artifact-Only Test + Benchmark Plan

Date: 2026-09-01 UTC
Turn: `M3-CP4c-3-TB8`
Status: **FROZEN SUCCESSOR PLAN / NOT EXECUTED**

## Validation identity

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Evidence source: `e2b59295c9920db5685239c2da188858839fa94f`.
- Final compile run/job: `33556556002 / 100018687726`.
- Raw compile artifact `9819595448`, Actions SHA-256
  `b520ecc8f760b29c909ed1fe122dc15b3a9999752f4b85e263a5eafaa15facee`.
- Immutable mode-preserving package **78**:
  package run/job `33557613904 / 100022216004`,
  artifact `9819958467`, Actions SHA-256
  `81414f18af71d5aacf50231a720b2774df71d88b223283c81ce747d13a977a51`.
- Inner `package78.tar.gz` SHA-256:
  `2cc3541cab1208781e234948228baa2d2b8d7bfdb12d855e6fd912cb30006591`.
- Packaged source archive SHA-256:
  `c1eadfdc4c1f118b34f9996aec00c2b51537e45e201ff52225b1d06b0d253d11`.
- Frozen gating selector 374 SHA-256:
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`.
- Diagnostic selector 375 SHA-256:
  `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`;
  selector 374 must be its unchanged 374-line byte prefix.
- Diagnostic identity 375:
  `ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries`.
- Benchmark: **none**; correctness/diagnostic validation only.

Package 77 is superseded and is not an authorized TB8 input.

## Objective

Consume CB10 without rebuilding it. Re-prove the accepted 365-prefix, test whether the corrected closed-wedge
arrival rule clears mechanical vertex 11, expose the next independent mechanical locus including vertex-star audit
data, preserve the pre-classified ordinal-374 witness stop without reinterpreting it as new product evidence, and
execute the new radial-arrival diagnostic identity with zero gate credit.

## Immutable preflight — before any Directional runtime

1. Download artifact `9819958467` directly and verify its Actions digest plus the exact inner tar digest above.
2. Extract `package78.tar.gz` preserving archived mode bits. Do not `chmod`, rebuild, regenerate, relink, or repair it.
3. Verify every internal `SHA256SUMS` entry, exact source commit/archive digest, clean source-status records,
   `runtimeExecution=false`, `packageRepair=false`, `exactArithmeticBackend=GMP`, preflight/build exit code `0`, and
   link evidence containing both GMPXX and GMP.
4. Require exactly 27 package-relative fixture files and exactly six packaged `directional_*` executables at
   executable mode.
5. Recompute selector 374 and 375 hashes/cardinality/uniqueness from the immutable packaged source. Require selector
   374 to contain exactly 374 unique identities, selector 375 to contain exactly 375 unique identities, and selector
   374 to be the unchanged byte prefix of selector 375.
6. Map every selector-374 identity and diagnostic identity 375 to exactly one packaged executable before runtime.
7. Record a package-tree byte/mode census for postflight comparison.
8. No configure, compile, relink, generated discovery, source/test/fixture/selector mutation, package repair, or
   benchmark is permitted.

Any mismatch is orchestration failure. Stop before runtime and do not count a semantic attempt.

## Ordered semantic gate — selector 374 only

Run selector **374 from ordinal 1**, one exact identity per fresh process. Each filter must select exactly one test.
Stop gate credit immediately at the first semantic red; zero-selected or duplicate-selected is orchestration failure.

Required closure result is **374/374 PASS**. However, ordinal 374 has a separately reviewed invalid-witness
precondition and is expected to remain red in this turn unless its bytes were independently corrected by a later
authorized test-side CB. That expected stop is pre-classified and does not by itself create a new review obligation.

Key discriminators:

- ordinals **1–365** must remain green;
- ordinal **366** must clear the TB7 source-vertex-11 seed-admissibility stop. If it still reports
  `VertexTransitSeedUnavailable` at vertex 11, CB10 is falsified;
- if the mechanical witness reaches vertex 30, the frozen Amendment-22 result is row **209** `(30,119,123)` when
  `α < θ₂₀₉`, otherwise row **208** `(30,31,119)`; row **41** `(25,30,31)` must never be elected;
- any vertex-transit failure must expose the seed/audit/state-row projection, including arrival radial identity when
  applicable;
- exact radial decisions remain exact-fallback/half-open-owner decisions, never tolerance or candidate-order rules;
- ordinals 367/371/372 either become green or publish their own independent first loci;
- ordinal 374 is expected to stop at `ASSERT_TRUE(atlasBuild)` with the already-classified
  `CycleTransportMismatch`. Record it but do not count it as a new regression/review trigger by itself.

Do not impose an arbitrary workflow elapsed-time cutoff and do not stitch partial successful runs into a synthetic
pass.

## Full report-only remainder pass — zero gate credit

After the first semantic red fixes gate credit, execute every later ordinal through **374** exactly once, one identity
per fresh process, in a report-only pass with zero gate credit. If the gating selector is fully green there is no
remainder pass.

The remainder pass must not alter `first_red_ordinal`, gate pass count, or acceptance.

## Diagnostic identity 375 — separate, zero gate credit

Execute
`ResolvedBranchCorrection.FaceInteriorRadialArrivalsAdmitBothClosedWedgeBoundaries`
exactly once from immutable package 78, in a fresh process, outside the gate count.

It must PASS both exact `FaceInterior` radial orientations and preserve the frozen expected owners from the CB10
report. Failure is diagnostic evidence about AZ6 and must be reported, but it cannot increase or decrease selector
374 gate credit.

## Regression/accounting review

Before TB8 closes, categorize every newly observed semantic red/candidate in
`Regression_Root_Cause_Tracker.md`. Do not promote a pre-classified ordinal-374 repeat merely because it repeats.
Promote stable totals only when tracker criteria are met; otherwise create/update a non-stable candidate and state why
the stable totals do or do not change.

CB10 compile/package activity and package orchestration failures are not semantic runtime events.

## Immutable postflight

After all authorized runtime, re-run the internal manifest; re-check source archive, selector hashes, binary hashes
and executable modes; compare the package-tree byte/mode census; and prove configure/compile/relink/repair/generated
discovery/product/test/fixture/selector mutation and benchmark flags remain false.

A postflight mismatch invalidates semantic authority and is orchestration evidence, not a product verdict.

## Stop/rerun rules

A newly valid semantic first red stops gate credit and, after the complete zero-credit remainder and immutable
postflight, routes to independent `REVIEW + PLAN` unless already pre-classified by the current review authority.
The known ordinal-374 invalid-witness stop alone does **not** consume another review turn.

An orchestration-only failure may be retried only after the exact control defect is diagnosed, with package 78
unchanged. Never rerun an unchanged deterministic semantic failure merely to see whether it passes. Do not rebuild
or mutate product/test/fixture bytes in TB8.

## Completion criteria

- **Green:** 374/374 gate PASS + diagnostic 375 recorded + immutable postflight PASS → CP4c-3 closes.
- **Red, new semantic evidence:** valid first semantic red + full zero-credit remainder + diagnostic 375 +
  immutable postflight PASS → CP4c-3 remains open and routes according to the turn workflow.
- **Only pre-classified ordinal-374 red:** preserve accepted prefix/gate accounting, record the known witness stop,
  run diagnostic 375 and postflight, and do not fabricate a new review obligation.
- **Blocked:** immutable/orchestration preflight or postflight invalid → repair only the control plane and retain
  package 78 unchanged.
