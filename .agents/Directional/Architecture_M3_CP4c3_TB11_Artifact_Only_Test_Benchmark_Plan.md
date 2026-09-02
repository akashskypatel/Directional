# M3-CP4c-3-TB11 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN successor plan from `M3-CP4c-3-CB13`.
**Turn boundary:** Test + Benchmark only; package 81 is immutable. No product/test/fixture/selector/build-logic edit or replacement compile is permitted.

## Immutable authority

- source: **`3070173894ee097f631b96c1c6d29f276df89a66`**;
- package artifact **`9834661539`**, Actions SHA-256 `10e18bc81c2f850a1e7bc3d4ce16830a5d5ebe7d1992cd728c1bb043dc71cb2f`;
- inner `package81.tar.gz` SHA-256 **`4f49b3de157e51aff05736f9ac4b210372eb4bfb4dec3ddc793869071b2f9d88`**;
- packaged source archive SHA-256 `752cb9da86dbae5fd4d0122f5a5538c8e6431be4c8e02c302a8a93e05c25a1bf`;
- package log artifact `9834661871`, Actions SHA-256 `b730ee97e1df872305b872e5a631226a71044dc240efe65a84fbf296ce0f0a76`;
- selector **377** SHA-256 `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`;
- frozen selector 374/375/376 hashes: `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`, `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`, `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`;
- accepted inherited authority: **365/365**.

## Immutable preflight — before any Directional runtime

1. Download package artifact `9834661539` directly and verify the Actions digest and inner tar digest above.
2. Extract with ordinary `unzip`/`tar` semantics that preserve archived executable mode bits. **Do not use Python `zipfile.extractall` for executable payloads** unless the archived modes are explicitly restored and verified. Do not `chmod`, repair, rebuild, regenerate, or relink the package.
3. Verify every internal `SHA256SUMS` entry; exact source commit/archive digest; clean source-status records; preflight/build exit codes `0`; `runtimeExecution=false`; `packageRepair=false`; `exactArithmeticBackend=GMP`; and link evidence containing both GMPXX and GMP.
4. Require exactly 27 package-relative fixture files and exactly six packaged `directional_*` executables with executable mode intact.
5. Recompute selectors 374–377 from packaged source and require the exact hashes/cardinalities/uniqueness/prefix relations frozen above.
6. Map every selector-377 identity to exactly one packaged executable before runtime. A zero-selected or duplicate-selected identity is orchestration failure, never semantic evidence.
7. Record a package-tree byte/mode census for postflight comparison.
8. No configure, compile, relink, generated discovery, source/test/fixture/selector mutation, package repair, or benchmark execution is permitted.

Any mismatch stops before runtime and is orchestration failure.

## Ordered execution — selector 377 from ordinal 1

Execute selector **377 from ordinal 1**, **one exact identity per fresh process**. Gate credit stops at the first semantic red. After the first red, execute every remaining identity through 377 exactly once as report-only evidence with zero gate credit. Do not use a repository elapsed-time watchdog on the complete selector execution and do not partition/retry/stitch continuations to manufacture completion.

Then execute **exactly once**, separately and with **zero gate credit**, the diagnostic identity:
`GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`.
It re-derives the mechanical cut-graph error from production inputs and supplies stage/terminal-event context. It is diagnostic-only and must never alter accepted count, first-red ordinal, or selector membership.

## Mandatory CB13 discriminators

1. **Ordinal 366 becomes readable.** Its failure message must contain `rotationSystemReason=<typed-condition>` where the value is not one of pre-CB13 values 0–8, plus every locus available at that producer. A repeat of TB10's bare `origin=RotationSystemInconsistent` is a failure of CB13 diagnostics, not new product evidence.
2. **The phase becomes decidable.** Map the reason to exactly one of `build_arcs`, `build_node_loci`, `build_rotation_system`, `walk_graph_faces`, `exterior_boundary_orbits` and state whether that is before/during/after fan-ray ordering.
3. **Certification attempt becomes decidable.** Record `certificationAttempt` and `certificationCutEdges`; identify attempt 0 as initial uncut certification and later values as proposal/saturation iterations.
4. **No semantic movement from a diagnostic patch.** Ordinals 1–365 must remain green and the first red must remain at ordinal 366. If the first red moves, classify CB13 itself as semantically defective and route to review without patching in TB11.
5. **Carried reds stay carried.** 367/371/372 must remain upstream-blocked by the same mechanical fixture stop. 368, 369, 370 and 374 must reproduce their previously classified surfaces unless exact emitted evidence demonstrates a genuine change; do not double-count or silently re-own them.
6. **The ranked hypothesis is falsifiable.** A reason in `walk_graph_faces` or `exterior_boundary_orbits` falsifies the review's fan-ray-order hypothesis and is a valid result. Do not reinterpret it to preserve the hypothesis.

## Regression/accounting review

Categorize every observed red in `Regression_Root_Cause_Tracker.md` before TB11 closes. `M3-CP4c3-TB10-CAND-01` remains non-stable until the runtime evidence names the actual producer/condition and justifies ownership. Preserve stable totals **44 / 14 / 30**, produced-witness debt **5**, and accepted authority **365/365** unless evidence meets the tracker criteria for a change. Package count is **78** and does not change during TB11.

## Immutable postflight

After all authorized runtime, rerun the internal manifest; recheck source archive, selector hashes, binary hashes and executable modes; compare the package byte/mode census; and prove configure/compile/relink/repair/generated-discovery/product/test/fixture/selector mutation and benchmark flags remain false. Any mismatch invalidates semantic authority.

## Stop/rerun rules

- Any red in ordinals 1–365 is a new gating regression: preserve it, stop gate credit, continue only report-only work authorized above, and route to review.
- Bare ordinal-366 `RotationSystemInconsistent` with no new typed reason is a CB13 diagnostic failure; do not rebuild or patch in TB11.
- A typed reason is evidence even when it falsifies the current hypothesis; preserve it verbatim before analysis.
- An orchestration-only failure may be retried only after its exact control defect is diagnosed, with package 81 unchanged. Never rerun an unchanged deterministic semantic failure merely to see whether it passes.

## Completion criteria

TB11 is complete only after immutable pre/postflight PASS, all 377 identities run in order under the gate/report-only rules, the non-gating diagnostic identity runs once, all six discriminators are recorded, and the regression tracker is updated. The next correction or independent-review boundary is chosen from that evidence; TB11 itself does not mutate source.
