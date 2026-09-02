# M3 CP4c-3 TB11 — Independent Review + Plan

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB11-REV`
Status: **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED**

## Authority

Review the valid TB11 artifact-only semantic result without rerunning it:

- semantic/package source `3070173894ee097f631b96c1c6d29f276df89a66`;
- immutable package **81** artifact `9834661539`, Actions SHA-256 `10e18bc81c2f850a1e7bc3d4ce16830a5d5ebe7d1992cd728c1bb043dc71cb2f`, inner tar SHA-256 `4f49b3de157e51aff05736f9ac4b210372eb4bfb4dec3ddc793869071b2f9d88`;
- selector **377** SHA-256 `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`;
- TB11 run/job `33611378451 / 100187075757`;
- result artifact `9839236420`, SHA-256 `1f803fc725ecf5bcfd66891cdd70e1746e1cb28faf7bfebc5284f38c988e734a`;
- log artifact `9839236880`, SHA-256 `fb9350c7b8e1d464f6802cdb1da59c34dab5e264925fccd1c63b6ed8e255ab74`;
- accepted prefix **365/365**; first red ordinal **366** at `RotationRayOrderKeyCollision`, sourceVertex 47, certification attempt 0, certification cut edges 0.

## Objective

Independently adjudicate the now-localized rotation-order collision. TB11 proves the exact producer condition and phase, but does **not** prove whether the collision represents invalid product incidence, an insufficient ray-order key, genuine coincident rays that require a defined tie rule, or an invalid/stale witness. Determine the earliest semantic owner before authorizing any product correction.

## Required measures — BG0–BG7

### BG0 — Re-establish immutable authority

Verify package/source/selector/run identities, fresh-process count, 365/365 accepted prefix, first-red ordinal 366, all report-only results, non-gating diagnostic credit=0, and immutable postflight. Control-plane commits after package 81 are not semantic evidence.

### BG1 — Reconstruct the exact collision without new runtime

From package-81 source plus retained TB11 evidence, locate the unique `RotationRayOrderKeyCollision` emitter and reconstruct its data contract. Confirm that it fires in `build_rotation_system` after key construction and sorting, before `counterClockwise` publication, only when two vertex-locus trace incidences have equal `RayOrderKey.primary` and `.secondary`. Recover, where static retained authority permits, the two trace arcs/incidences at source vertex 47 and the values used to produce their equal keys. If those identities/values are not retained, explicitly prove the missing datum rather than inventing it.

### BG2 — Classify the semantic condition by falsifying alternatives

Adjudicate at least these alternatives separately:

1. two genuinely duplicate outgoing trace incidences entered the rotation system;
2. two distinct valid trace rays collapse because the order key omits a discriminator;
3. the two rays are geometrically/coherently coincident and the architecture requires an explicit deterministic tie/equivalence rule;
4. stale or duplicated source/network provenance created an invalid incidence;
5. the mechanical witness violates a precondition that should have been rejected earlier.

Do not choose a fix until the evidence distinguishes these cases. The existence of a collision is not itself proof that ray ordering is wrong.

### BG3 — Use certification context correctly

Prove what `certificationAttempt=0` and `certificationCutEdges=0` mean in `SurfaceCutGraph::make`/`certify_actual_embedded_graph`. Reconcile `cutCandidateCount=450`, `nonDiscComponentCount=0`, and `remainingAdmissibleEdgeCount=0` with that phase. Determine whether the failure occurs on initial uncut embedded-graph certification before any cut proposal is evaluated. Do not infer cut-search or cellularity semantics beyond what the control flow proves.

### BG4 — Adjudicate shared and carried reds without double counting

Confirm 367/371/372 abort at the same ordinal-366 collision before their own intended assertions. Preserve `M3-CP4c3-TB10-REV-CAND-01` as deferred unless review proves a need for independent test-only decoupling now. Preserve unchanged sphere 368, saturation 369, empty-network 370, folded-cone 374, vertex-30, finalize/contact and other carried candidates unless exact TB11 evidence changes ownership.

### BG5 — Audit accepted-boundary safety

Prove any proposed owner is compatible with accepted ordinals 1–365, selector immutability, and the closed CB12 terminal-ownership correction. Search for other `RayOrderKey` consumers/producers and existing deterministic ordering invariants so a local repair cannot silently change unrelated fan ordering, topology, cut admissibility, or gauge behavior.

### BG6 — Freeze exactly one bounded successor

If BG1–BG5 prove a semantic root cause, freeze one minimal Code + Build successor with explicit positive/negative boundary witnesses, prohibited alternatives, eight standard GMP/GMPXX compile targets, no runtime, and an immutable artifact-only TB discriminator. If root cause remains underdetermined because the colliding arc identities/key data are not retained, freeze diagnostic-only instrumentation instead. Do not combine sphere/saturation/370/folded-cone/371-372 debt with the collision owner.

### BG7 — Durable review closeout

Update `ORIENTATION.md` (mandatory REVIEW-turn update), `Regression_Root_Cause_Tracker.md`, `M3_CP4c_Consolidated_Record.md`, `TODO.md`, `Future_Chat_Session_Handoff.md`, `ROADMAP.md`, and `CHANGELOG.md`; close or transition `M3-CP4c3-TB11-CAND-01` only as proved; preserve accepted authority **365/365**, stable accounting **44 / 14 / 30**, debt **5**, and package count **78** unless policy-authorized evidence changes them.

## Prohibitions

No Directional runtime, benchmark, configure, compile, link, package, product/test/fixture/selector mutation, unchanged TB retry, tolerance change, float-derived topological decision, opportunistic carried-debt repair, or acceptance claim from report-only evidence.

## Completion criterion

The review closes only when the two colliding trace incidences/key values are recovered or their absence is proved, the semantic category is justified against the nearest alternatives, certification-attempt context is established, all TB11 reds are adjudicated without double counting, and exactly one falsifiable successor is frozen.
