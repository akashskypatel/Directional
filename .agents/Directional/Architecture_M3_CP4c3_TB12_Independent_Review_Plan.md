# M3 CP4c-3 TB12 — Independent Review + Plan

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB12-REV`
Status: **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED**

## Authority

Review the valid TB12 artifact-only semantic result without rerunning it:

- semantic/package source `71ece3ca184e90858d9222fb014b37c16d292294`;
- immutable package **82** artifact `9855841174`, Actions SHA-256
  `4f597d260a6fb258767378489741326a6f6c2322522bdd60ef9fd071970c26ed`, inner tar SHA-256
  `58393e9927e80e894a753cafee074202fd6df8fec43d8cba244fe1404e23a5e1`;
- selector **378** SHA-256 `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`;
- TB12 run/job `33657062615 / 100338185825`;
- result artifact `9857275334`, SHA-256 `085b3de9ebf5a9a29cbcf883e4058c97855e11a1a7b2bc53f961c809dace9145`;
- log artifact `9857276091`, SHA-256 `89cac6cb1ea6444b8204d8b5ca9233daed7e0ff88986d8592af576e319cb4120`;
- accepted prefix **365/365**; first red ordinal **366** remains `RotationRayOrderKeyCollision` at source vertex 47,
  certification attempt 0 / 0 cut edges;
- retained collision operands: arc 20 / trace 6 / Forward / origin vertex 47 versus arc 23 / trace 9 / Reverse /
  origin vertex 71, with equal `primary=3`, `secondary=0`, face `(45,46,47)` and fan slot 1;
- fan census **5 / not truncated**; unmeasured `nonDiscComponentCount` and `remainingAdmissibleEdgeCount` absent.

## Objective

Adjudicate the semantic contract for the now-observed **distinct-ray same-sector collision**. TB12 removes the prior
missing-evidence ambiguity: the two rays are not the same arc/trace incidence and one ray's origin port belongs to
vertex 71 while the collision locus is vertex 47. What remains unresolved is whether two such rays are valid and
need deterministic tie/equivalence semantics, whether one incidence/provenance is invalid, or whether the witness
violates a prerequisite. Determine the earliest semantic owner before authorizing any product correction.

## Required measures — BI0–BI7

### BI0 — Re-establish immutable authority

Verify package/source/selector/run identities, 378 fresh selector processes, 365/365 accepted prefix, first-red 366,
all report-only results, selector-378 diagnostic PASS, separate non-gating diagnostic credit=0, and immutable
postflight. Control-plane commits after package 82 are not semantic evidence.

### BI1 — Prove the two runtime incidences end to end

Trace arc 20 / trace 6 / Forward and arc 23 / trace 9 / Reverse from their network construction through
`build_rotation_system` at locus vertex 47. Establish each arc's two network nodes, trace segment range, originating
port/singularity, terminating event/node, and why `trace_ray_face` maps both to face `(45,46,47)` / fan slot 1.
Determine whether each incidence is independently valid at vertex 47. Do not infer validity from distinct IDs alone.

### BI2 — Define the rotation collision/equivalence invariant

Reconstruct the intended contract between the full `RayOrderKey` comparator and the post-sort collision guard. The
runtime rays compare equal on `primary`/`secondary` but differ on arc, trace, orientation and origin vertex. Decide
which of these is semantically order-relevant at a vertex locus and whether two trace rays may legally occupy one
face/fan slot. Distinguish explicitly among:

1. invalid duplicate/stale incidence despite distinct IDs;
2. valid distinct rays collapsed by an under-discriminating collision-equivalence predicate;
3. valid geometrically coincident rays requiring an explicit deterministic tie/equivalence rule;
4. invalid witness/precondition that should fail before rotation construction.

Do **not** mechanically add `arc`, `trace` or `orientation` to the predicate/comparator as a fix unless the invariant
proves that ordering by identity is semantically correct.

### BI3 — Resolve origin-port locality

Prove the intended scope of `port->ordinal` at vertex rotation loci. TB12 observes the current ray at locus 47 with
`originPortOrdinal=0;originPortSourceVertex=71`. Determine whether origin-port ordinal is valid as a local
secondary rank for an arriving trace, whether arrival-side authority must be derived from the locus instead, or
whether this provenance itself proves an invalid incidence. Audit all vertex-locus trace-ray key construction paths,
not only the mechanical fixture.

### BI4 — Preserve certification and diagnostic honesty

Reconfirm attempt 0 / 0 cut edges means initial uncut-graph certification and `cutCandidateCount=450` is measured
there. Confirm the absence of `nonDiscComponentCount` / `remainingAdmissibleEdgeCount` is the correct behavior on
this path. Treat selector 378 PASS as diagnostic-projection evidence only, not semantic acceptance.

### BI5 — Adjudicate shared and carried reds without double counting

Confirm 367/371/372 abort at the same distinct-ray collision before their intended assertions. Preserve the deferred
371/372 coupling candidate unless independent evidence changes its status. Preserve sphere 368, saturation 369,
empty-network 370, folded-cone 374, vertex-30 and finalize/contact debt unchanged unless TB12 evidence changes an
owner. Record no duplicate stable event for the shared mechanical exception.

### BI6 — Audit accepted-boundary safety and freeze one successor

Prove any proposed semantic owner is compatible with accepted ordinals 1-365, closed CB12 terminal ownership,
selector immutability, and all other rotation/key consumers. If BI1-BI5 prove one root cause, freeze exactly one
minimal Code + Build successor with explicit positive/negative witnesses, eight standard GMP/GMPXX compile targets,
no runtime, and a falsifiable immutable artifact-only TB successor. If the semantic distinction still requires a
missing runtime datum, freeze only the minimum diagnostic successor and state why TB12's retained census is
insufficient.

### BI7 — Durable review closeout

Update `ORIENTATION.md` (mandatory REVIEW-turn update), `Regression_Root_Cause_Tracker.md`,
`M3_CP4c_Consolidated_Record.md`, `TODO.md`, `Future_Chat_Session_Handoff.md`, `ROADMAP.md`, and `CHANGELOG.md`;
close/transition `M3-CP4c3-TB11-CAND-01` only as proved. Preserve accepted authority **365/365**, stable accounting
**44 / 14 / 30**, debt **5**, and package count **79** unless policy-authorized evidence changes them.

## Prohibitions

No Directional runtime, benchmark, configure, compile, link, package, product/test/fixture/selector mutation,
unchanged TB12 retry, tolerance change, float-derived topological decision, opportunistic carried-debt repair, or
acceptance claim from report-only evidence.

## Completion criterion

The review closes only when both runtime ray incidences are traced to their construction/endpoint authority, the
vertex rotation equivalence invariant is stated, origin-port locality is adjudicated, the nearest alternatives are
falsified or retained explicitly, all TB12 reds are categorized without double counting, and exactly one bounded,
falsifiable successor is frozen.
