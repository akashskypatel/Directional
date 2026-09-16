# M4-CP-SCALE-CB10 — S4 Prerequisite Test-Authority Correction Code + Build Plan

**Date:** 2026-09-16 UTC
**Turn type:** Code + Build only
**Predecessor:** `M4-CP-SCALE-TB8-REV`
**Purpose:** correct the rejected CB9 S4 prerequisite test authority without changing production semantics or selector425.

## 1. Immutable accepted authority

CB10 begins from the accepted TB7 runtime authority, not from any claim that the CB9 candidate was promoted:

- accepted package `10425344367` / semantic source `01b1124af094044e32d6887ff0615881333d12ce`;
- selector425 **425/425 PASS**, SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- exact selector424 prefix `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`;
- stable accounting **49 events / 14 categories / 35 recurrences**, debt **5**.

CB9 semantic source `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf` is useful as the rejected test-authority starting point only. Its product bytes are unchanged from accepted authority, but its S4 prerequisite identity is not accepted evidence.

## 2. Root cause to correct — fixed before implementation

TB8 Review establishes that the focused subject is a production-reachable **torus** empty-cut candidate, but the test hard-coded the retained prescribed-sphere pre-cut **graph-count** tuple `V/E/F=18/30/18, c=1` while retaining torus `sourceChi=0`. Accepted torus authority is `V=48, E=48, c=4` with four annular complement components. The test also required equality between independent connected complement-component count and product face-walk-orbit-derived `certificate.faceCount` on a non-cellular state, where those representations need not coincide.

CB10 must correct both defects. Merely changing `18U` to `48U` is insufficient.

## 3. Authorized semantic change surface

CB10 may modify only `tests/FieldAlignedCurveNetworkTests.cpp` and only the S4 prerequisite test/helper logic needed for the correction below. It may update turn documentation and compile orchestration as normal.

Forbidden in CB10:

- any `src/**` or `include/**` product semantic change;
- any A2a' cut-selection/order/backtracking change;
- any final `SurfaceCutGraphCellularityCertificate` semantic change;
- fixture or benchmark-byte change;
- CMake semantic change except an unforeseen compile-only ownership necessity that must stop for Review rather than be assumed;
- selector425 mutation or selector426 creation;
- Directional runtime/test/benchmark execution.

## 4. M0 — re-establish the negative from accepted torus authority

The corrected focused identity remains `M4CPScaleS4Prereq.IndependentTopologyOracleIsReachableAndDecisionNeutral` unless changing the name is necessary to make the repaired contract truthful; if the name changes, stop and freeze the exact new identity before compile packaging.

For the empty-cut production-reachable torus state, the test must independently require:

- source `chi = 0`, source components `s = 1`;
- `network.nodes().size() = 48` and network edge authority `E = 48`;
- independent actual graph components `c = 4`;
- independent connected complement-component count `F_observed = 4`;
- every independently reconstructed component is non-disc annular authority: boundary cycles valid, `boundaryWalkCount = 2`, component Euler `0`;
- `b1 = E - V + c = 4`;
- `F_required = chi - s + b1 = 3`;
- `F_observed != F_required`, so the independent necessary-condition oracle rejects.

The test must not manufacture these values from the final product certificate. The already-accepted torus row356 and M3 frozen definitions are the cross-check for witness identity, not the computation mechanism.

## 5. M1 — pair the negative with final authority without representation conflation

The unchanged final product certificate must be available for the same empty-cut state and must **not** prove embedded cellularity. The paired safety statement is one-way:

> whenever the independent S4 necessary-condition oracle rejects a candidate in its covered class, the unchanged final certificate also rejects that same candidate.

For the non-cellular negative, do **not** require independent connected complement-component count to equal product face-walk-orbit `faceCount`; do not freeze a product Euler numeric constant solely to mimic the independent count. Semantically shared fields such as source Euler/source component identity may be compared when they are genuinely the same quantity.

## 6. M2 — positive accepted-cut falsifier

Using the production accepted cut set from the retained torus `SurfaceCutGraph`, the independent oracle must establish the known cellular state:

- `V=72`, `E=76`, connected complement components `F=4`;
- `c=1`, `s=1`, source `chi=0`;
- `b1=5`, `F_required=4`, therefore no early rejection;
- every independent complement component proves disc topology;
- unchanged final certificate proves embedded cellularity and its topology fields match the accepted production cut graph where the representations are semantically aligned.

This is the false-positive control: the repaired early oracle must not reject the known-good accepted state.

## 7. M3 — adversarial, enumeration and decision-neutral controls

Retain the deterministic one-selected-edge adversarial candidate. Its result is **not pre-declared**. Require:

- state identity differs from the empty and fully accepted cut states;
- if the independent oracle rejects, the unchanged final certificate does not prove embedded cellularity;
- lack of an early rejection does not imply the final certificate must pass, because S4 is a partial necessary-condition accelerator, not a replacement certificate.

Retain the reversed-cut enumeration control: reversing accepted-cut input order must reproduce the same canonical independent state, Betti number, required-face count and reject decision.

Retain decision-neutrality: after all test-side diagnostics, a fresh call to the unchanged production `SurfaceCutGraph::make` must reproduce the pre-diagnostic accepted cut edges, certificate, semantic digest and provenance digest exactly.

## 8. M4 — structured receipt and non-vacuity

The focused identity must emit a receipt only after all controls execute. It must include at least:

- `coveredClass=BettiFaceCountMismatch`;
- `reachableNegative=true`;
- negative state with `V=48,E=48,F=4,c=4,s=1,sourceChi=0`;
- `negativeBetti=4`, `negativeRequiredFaces=3`, `negativeObservedFaces=4`, `negativeReject=true`;
- positive state with `V=72,E=76,F=4,c=1,s=1`, `positiveBetti=5`, `positiveRequiredFaces=4`, `positiveReject=false`;
- adversarial state and both early/final boolean dispositions without asserting an unjustified biconditional;
- `enumerationInvariant=true`;
- `decisionNeutral=true`.

A test that can pass without the negative mismatch, the positive non-rejection, adversarial implication, enumeration check and production re-run is vacuous and must be rejected before compile closeout.

## 9. Build/package contract

CB10 is compile/package only. Use the mandatory reusable compile workflow and mandatory GMP/GMPXX backend. Compile the changed-owner preflight and then all standard targets required to package every accepted selector425 owner plus the focused producer identity. Package evidence must record `runtimeExecution=false`.

Before closeout require:

- changed semantic paths are within §3;
- selector425 re-hashes exactly to `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` and stays 425 unique LF rows;
- exact first424 prefix remains `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`;
- focused identity has exactly one source definition and remains owned by the producer test executable;
- all standard package owner binaries are present;
- package/source manifest and GMP receipts verify;
- no Directional runtime, test or benchmark process executes.

## 10. Stop rules

Stop and return to Review rather than broaden CB10 if any of the following occurs:

1. the production torus no longer statically agrees with accepted `48/48,c=4` authority;
2. the independent oracle cannot reconstruct four annular empty-cut components without reading final certificate outputs;
3. the correction would require a product semantic change, A2a' cut change, fixture change or selector change;
4. the positive accepted-cut state no longer statically matches retained `72/76/4` authority;
5. the one-way early-reject implication cannot be expressed without treating the partial oracle as the final certificate;
6. compile/package authority cannot be established under mandatory GMP/GMPXX.

## 11. Success criterion and next boundary

CB10 succeeds only when the corrected test authority compiles/packages under the frozen scope with selector425 unchanged and `runtimeExecution=false`. Compile success provides **zero** S4 prerequisite runtime credit.

The next expected turn after successful CB10 is `M4-CP-SCALE-TB9-EXEC`: immutable artifact-only focus first, then selector425 as fresh exact-filter processes only if focus is green, with explicit fail-fast remainder and immutable postflight. `M4-CP-SCALE-TB9-REV` is mandatory before any production S4 early-reject implementation or selector426 publication.

## Amendment — make the S4 subjects independently observable (TB8-REV §13 V3, reviewing agent)

Constraint 4 preserves the positive accepted-cut, adversarial, enumeration-invariance and decision-neutrality
controls, but preserving them is not the same as making them **observable**. TB8 learned about exactly one subject
because `TEST(M4CPScaleS4Prereq, …)` (`tests/FieldAlignedCurveNetworkTests.cpp:14128`) is a single identity holding
every subject, carrying 26 fatal `ASSERT_` against 17 non-fatal `EXPECT_` in its first ninety lines. One fatal
assertion aborts the body and blinds every later subject.

CB10 must therefore structure the S4 controls so a failure in one subject does not mask the others. Either:

1. split them into separate identities — each fails independently, and each can earn its own selector row later; or
2. keep one identity, reserving fatal `ASSERT_` for preconditions **within** a subject and using non-fatal
   `EXPECT_` at subject boundaries, with an end-of-test receipt enumerating every subject's outcome.

Without this, TB9 can spend another full cycle learning about exactly one subject. Same trade accepted at
`M4-CP3-TB7-REV` for the accepted prefix, and the same "passed versus did not run" discipline as `LESSONS.md` 160.

