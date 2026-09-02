# M3 CP4c-3 TB14 — Independent Review + Plan

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB14-REV`
Status: **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED**

## Authority

Review the completed user-authorized package-84 TB14 replacement run; do not rerun any identity:

- semantic/package source `6808c090f2dd229a48550d758f459bfd156da4b6`;
- immutable package **84** artifact `9867334959`, Actions SHA-256
  `67f1ea7012f3b0e06a1dd60e87d40c7e593e5260703cab425c9021cb0c2ebd55`, inner tar SHA-256
  `8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff`;
- selector **380** SHA-256 `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`;
- authoritative replacement run/job **`33689875040 / 100445977571`**;
- result artifact **`9869697113`**, Actions SHA-256
  `a96d8ff82b467c0cfd89c1437fc0a146461ab18d4850e04515acc562070b975a`;
- diagnostic-log artifact **`9869697543`**, Actions SHA-256
  `5e961520a3844d5b01ab77d4b85b5117c4124bfa03d4993812270e4563deb5f2`;
- corrected semantic ledger SHA-256
  `0b42866471ce0ad5939ab2d3c2d5c82f4efebb93c0a56ca7a60e295fad07397b`, derived from immutable per-process
  exit codes and terminal GoogleTest logs after the reporting-only exact-line parser defect was identified;
- complete selector result **371 PASS / 9 RED**, accepted **1-365 = 365/365 PASS**, first red **366**;
- ordinal 366: `RotationSystemInconsistent -> EdgeTraceSecondaryRankInvalid`, source edge `25-31`, source face
  `(25,30,31)`, attempt 0 / zero cut edges / 450 candidates;
- selector 379 PASS; selector 380 RED at its final production assertion because attempt-0 rotation returns
  `EdgeTraceSecondaryRankInvalid`;
- non-gating mechanical diagnostic RED with the same edge/reason and zero gate credit;
- immutable 58-file postflight equal to preflight; no build/configure/relink/repair/discovery/mutation/benchmark.

The earlier local-host interruption is superseded by this complete replacement and is infrastructure history only.
`M3-CP4c3-TB14-ORCH-01` and the reporting-only `M3-CP4c3-TB14-ORCH-02` are resolved non-stable orchestration
candidates and are not product owners.

## Objective

Determine the exact semantic cause of the new **edge-locus trace secondary-rank** failure without guessing from the
reason name, then freeze one bounded Code + Build successor if and only if source/fixture evidence proves a real
contract defect. Preserve the accepted 365 boundary, the v47 five-ray/distinct-rank obligation, and all independent
carried surfaces. This review may revise planning records only; it executes no Directional runtime and changes no
implementation/test/fixture/selector/build logic.

## Required measures — BM0–BM8

### BM0 — Re-establish immutable and corrected evidence authority

Verify package/source/selector hashes, run/job/artifact identities, all 380 exact fresh-process selections, corrected
371/9 ledger reconstruction, 365/365 accepted prefix, non-gating diagnostic, and byte/mode-identical postflight.
Independently prove the runner's exact-line `[ OK ]` parser defect was reporting-only: execution order, exit codes,
logs and package bytes must not depend on the corrected labels. Record that no semantic rerun is authorized or
needed for this evidence correction.

### BM1 — Enumerate every `EdgeTraceSecondaryRankInvalid` producer and projection path

Audit `build_rotation_system`, `edge_locus_secondary_rank`, error rendering/projection, and every caller. Establish
how many emitters can produce this exact reason, what preconditions return `nullopt`, which locus fields survive to
TB14, and whether any downstream translation can fabricate or collapse the same reason. Do not infer the cause from
the enum alone.

### BM2 — Trace the exact failing edge incidence

For source edge `25-31` / face `(25,30,31)`, identify the exact network arc, trace, orientation, segment interval,
contact carrier, candidate `other` carrier, source vertex and side rank that reach `edge_locus_secondary_rank`.
Determine which specific `nullopt` branch fires: missing trace-ray face, missing source face, contact edge not in the
face, invalid/missing opposite carrier, coincident local edge index, or the source-vertex fallback failing to bind.
Use existing package source/fixtures and retained runtime evidence only; no runtime probe is allowed in REVIEW.

### BM3 — Decide whether the rejected incidence is semantically valid

Establish the intended edge-locus rotation contract from the frozen topology definitions and actual trace
provenance. If the incidence is valid, derive the exact rank that should exist and prove why it is canonical,
locus-relative, orientation-correct and enumeration-invariant. If the incidence is invalid/stale, identify the
earlier producer invariant that should reject or repair it instead of manufacturing a rank in rotation assembly.
Reject fixture-specific index rules and id/order tie-breakers.

### BM4 — Audit the whole edge-locus rank construction, not only the failing branch

Review `edge_locus_secondary_rank` for Forward and Reverse rays, ordinary incoming/outgoing carrier pairs, direct
source-vertex first/last segments, both canonical edge orientations, both incident face sides, and any endpoint
coincidence. Prove the returned rank integrates correctly with `key.primary`, `sideRank`, mandatory/cut edge rays,
and collision detection. Any correction must preserve exact topology semantics and fail closed on true ambiguity.

### BM5 — Prove accepted-boundary and generalization safety

Explain why the proposed correction, if any, cannot alter accepted ordinals 1-365 except by preserving their already
observed outputs. Identify the invariant enforced, the complete class of valid inputs affected, potential regressions,
and negative cases that must remain rejected. Freeze focused compile-time/test contracts that are semantic rather
than fixture-index-specific. Do not weaken an assertion to make ordinal 366 green.

### BM6 — Preserve and adjudicate the v47 obligation

`M3-CP4c3-TB11-CAND-01` remains open until production publishes the full five-ray v47 rotation and distinct secondary
ranks for the former pair (arc 20 / trace 6 / Forward and arc 23 / trace 9 / Reverse). Selector-379 PASS and absence
of `RotationRayOrderKeyCollision` are necessary but insufficient. Decide whether
`M3-CP4c3-TB12-REV-CAND-01`, `M3-CP4c3-TB13-CAND-01`, and `M3-CP4c3-TB13-REV-CAND-01` can close, partially close,
or remain runtime-open under the exact TB14 evidence. There is still no vertex-30 discriminator.

### BM7 — Keep carried surfaces independently owned

Confirm TB14's report-only reds do not get folded into the new edge-rank owner:

- 368 remains prescribed-sphere `TraceEventPositionInvalid` / `NoCarrierMatch`;
- 369 remains saturation/ordinary-proposal coverage;
- 370 remains the empty-network typed-code/locus surface;
- 371/372 are test-coupled through the shared mechanical fixture and inherit the 366 upstream stop only;
- 374 remains the pre-classified folded-cone `atlasBuild=false` fixture surface;
- finalize/contact and vertex 30 remain separate.

Update regression ownership only where the evidence actually discriminates a mechanism.

### BM8 — Freeze exactly one bounded successor

If BM2-BM5 prove a product defect, freeze one `M3-CP4c-3-CB17` Code + Build plan with surgical production/test
changes, compile-only acceptance, GMP/GMPXX, selector-prefix preservation, and a following immutable TB plan. If the
failure is fixture/test authority instead, freeze the correspondingly bounded test-only CB correction. If evidence
is insufficient, freeze the minimum diagnostic CB necessary to make the missing incidence observable rather than
speculating. In every case:

- no REVIEW runtime, benchmark, configure, compile, link, package, product/test/fixture/selector mutation;
- no accepted-boundary weakening or fixture special-case;
- update `ORIENTATION.md` as required for every REVIEW turn;
- stable accounting remains **44 / 14 / 30** unless review proves a distinct historical stable event under tracker
  rules;
- accepted authority remains **365/365**, debt **5**, packages **81** until a later CB creates a new immutable
  package.

## Exit gate

The review closes only when BM0-BM8 are discharged, every candidate has an explicit owner/disposition, the exact
edge-locus failure branch and semantic validity are determined or a minimum diagnostic gap is proved, and exactly one
bounded successor is frozen. No product correction is authorized merely because `EdgeTraceSecondaryRankInvalid`
exists; the mechanism must be proved first.
