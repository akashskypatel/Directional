# M3 CP4c-3 TB10 — Independent Review + Plan

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB10-REV`
Status: **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED**

## Authority

Review the valid artifact-only TB10 semantic result, not a reconstructed rerun:

- semantic source: `a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`;
- immutable package **80** artifact `9828786744`, Actions SHA-256
  `f4643d0535684f81de5afc9660ef40f2ffb941d1c540b91026225681314fe20e`;
- selector **377** SHA-256 `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`;
- TB10 run/job `33584653692 / 100106147126`;
- TB10 result artifact `9829700900`, SHA-256
  `2e7d978dd3ad2a5f0667ef3eed15c291ed8c7b91bb7e2d323557a8bc40763572`;
- TB10 log artifact `9829701136`, SHA-256
  `89f445c5934c3493ccf966e39f0c106c8418719a32c5d206055cafa932cce17d`;
- accepted prefix **365/365**; first red ordinal **366** at
  `surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`;
- CB12 discriminators passed; `M3-CP4c3-TB9-REV-CAND-01` is closed; identity 377 passes at terminal v36 /
  `BarrierAbsorbed` / network node 7.

## Objective

Independently adjudicate the **moved** mechanical first red. TB10 proved the terminal-ownership correction and exposed
a later surface-cut-graph rotation-system rejection. The review must determine the exact failing invariant and its
owner before any new semantic correction is authorized. Do not treat movement of the first red as acceptance.

## Required measures — BE0–BE7

### BE0 — Re-establish immutable authority and scope

Verify TB10 package/source/selector/run identities, 365/365 accepted prefix, first-red ordinal 366, complete report-only
remainder, and immutable postflight. Verify no source/test/fixture/selector bytes changed between package 80 semantic
source and the reviewed source authority relevant to the failure. Reject any review conclusion based on later control-
plane-only commits as semantic evidence.

### BE1 — Recover the exact mechanical rotation-system failure

For ordinal 366, determine the exact `GlobalTopologyPlanErrorCode::RotationSystemInconsistent` subreason and every
available locus field: source vertex, source edge, source face, node, trace, trace event, position-pass/failure data,
and any rotation/fan certificate. Prefer retained TB10/package evidence if it already contains the data. Static source
may prove where data is dropped but may not invent the runtime value.

Package-80 source already establishes one diagnostic fact that review must verify: `SurfaceCutGraph::topology_error`
copies the originating rotation-system reason and locus fields into `SurfaceCutGraphError`, while the production
`RemeshPipeline.cpp` surface-cut-graph failure string renders only the cut-graph code and originating topology code.
Adjudicate whether an existing product snapshot exposes the full error without new runtime; otherwise classify the
projection loss and define the minimum diagnostic correction needed to name the runtime condition.

### BE2 — Classify the underlying defect before proposing a fix

Classify ordinal 366 using the project's categories: genuine product defect, invalid/stale witness precondition,
diagnostic insufficiency, or another proved category. If diagnostics are insufficient, do **not** infer a semantic
fix from the list of possible `RotationSystemInconsistent` producers. If the exact runtime subreason is recoverable,
prove its producer and invariant from source and fixture authority before assigning product ownership.

### BE3 — Adjudicate 367/371/372 without double counting

TB10 shows ordinals 367, 371 and 372 throw the same mechanical surface-cut-graph exception before their own assertions.
Prove whether they are strictly upstream-blocked by ordinal 366 or contain an independently reachable failure. Do not
create three duplicate product candidates from one upstream stop.

### BE4 — Preserve independent carried candidates

Record, without opportunistic correction:

- `M3-CP4c3-TB9-REV-CAND-01` — **CLOSED / RUNTIME PROVED** by TB10 BD9;
- `M3-CP4c3-TB6-CAND-01` — remains active; TB10 publishes no vertex-30 discriminator;
- `M3-CP4c2-TB-X2-CAND-04` — sphere remains `NoCarrierMatch / SourceEdgeUnavailable`;
- `M3-CP4c2-TB-X2-R10-CAND-01` — saturation remains `true`;
- `M3-CP4c2-TB-X2-R8-CAND-02` — ordinal 370 remains wrong typed error/no source-face locus;
- `M3-CP4c3-TB7-CAND-02` — folded-cone witness still fails `atlasBuild` precondition;
- `M3-CP4c3-DEFN-R2-CAND-01` and the separate finalize/contact fall-through remain unchanged unless the new exact
  evidence proves shared ownership.

Stable-count changes require accepted-green loss or other tracker-authorized evidence; TB10 supplies none.

### BE5 — Adversarially audit the nearest alternatives

For the proposed owner, falsify the nearest competing explanation. At minimum:

- distinguish a rotation-system construction defect from a production-rendering loss;
- distinguish a real mechanical witness violation from a precondition problem;
- prove whether the failure is before, during, or after vertex/fan ray ordering;
- confirm CB12's v36 termination correction cannot be the same old ownership failure under another string;
- confirm accepted ordinals 1–365 remain behaviorally untouched.

### BE6 — Freeze exactly one bounded successor

Issue one successor only after BE1–BE5 identify the earliest actionable owner.

- If runtime truth is still hidden, the successor is **diagnostic-only Code + Build**: project only already-existing
  typed/locus authority needed to discriminate the failing `RotationSystemInconsistent` producer; do not change the
  topology decision.
- If the exact product cause is independently proved, a bounded product Code + Build successor may be frozen with
  one positive witness, one boundary/negative witness, explicit prohibited alternatives, mandatory GMP/GMPXX compile
  targets, append-only selector handling, and an immutable artifact-only TB discriminator.

Do not combine sphere, saturation, ordinal 370, folded-cone, vertex-30, or finalize/contact work merely because those
surfaces appear in the same TB result.

### BE7 — Durable review closeout

Update `ORIENTATION.md` (mandatory for every REVIEW turn), `Regression_Root_Cause_Tracker.md`,
`M3_CP4c_Consolidated_Record.md`, `TODO.md`, `Future_Chat_Session_Handoff.md`, `ROADMAP.md`, and `CHANGELOG.md` with the
adjudication and exactly one successor. Preserve accepted authority **365/365**, stable accounting **44 / 14 / 30**,
debt **5**, and semantic package count **77** unless the review proves a policy-authorized change.

## Prohibitions

No Directional runtime, benchmark, configure, compile, link, package, product/test/fixture/selector mutation, unchanged
TB retry, candidate-order or tolerance repair, float-derived topological decision, acceptance claim from report-only
evidence, or correction of unrelated carried debt.

## Completion criterion

The review closes only when the exact ordinal-366 condition is either recovered or explicitly proved unavailable at
the current projection boundary, the earliest actionable owner is justified against alternatives, all TB10 reds are
adjudicated without double counting, and exactly one falsifiable successor is frozen.
