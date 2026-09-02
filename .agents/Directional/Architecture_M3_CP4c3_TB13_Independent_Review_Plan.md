# M3 CP4c-3 TB13 — Independent Review + Plan

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB13-REV`
Status: **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED**

## Authority

Review the valid TB13 artifact-only semantic result without rerunning it:

- semantic/package source `a2fd98eaa015ff5872890bb1945cf4e9e9493615`;
- immutable package **83** artifact `9861269273`, Actions SHA-256
  `1b8ce6a12edc8f7949deea3c43855e94e5755c0e73ed1cb603a2acd50901cab4`, inner tar SHA-256
  `c09d98ed35e9155805f759f27f54491b03643851650ce49dcb65c2191fc069ff`;
- selector **379** SHA-256 `ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`;
- TB13 run/job `33671968437 / 100387569925`;
- result artifact `9862995609`, SHA-256 `d7da71ea122a20225e6e3e7b9f2534fd3a7d8c1b1401ebc64b5f1191eb21bb8b`;
- log artifact `9862996106`, SHA-256 `b9a6288472f0ec204f93aa0f209b457c365e4c8ecf98e166c100c99bb3f6caf4`;
- accepted prefix **365/365**; 379 fresh selector processes produced **371 PASS / 8 RED**, first red 366;
- ordinal 366 moved from the old v47 collision to source vertex **10**, face `(8,10,11)`, reason
  `VertexTracePortOrdinalInvalid`, certification attempt 0 / 0 cut edges, `cutCandidateCount=450`;
- selector 379 PASS; the v47 five-ray/distinct-secondary discriminator was not reached;
- immutable package postflight passed.

## Objective

Adjudicate the earliest semantic owner of the newly reached vertex-10 failure before authorizing any product
correction. The retained reason name is not sufficient: package source reuses `VertexTracePortOrdinalInvalid` for
both a legacy port lookup/ordinal failure and failure of the new exact within-wedge parameter computation. Determine
which condition actually fires, whether that condition exposes a semantic error in CB15 or only insufficient
failure discrimination, and freeze exactly one bounded successor. Preserve the still-unproved v47 runtime
conjunction as an explicit later obligation.

## Required measures — BK0–BK8

### BK0 — Re-establish immutable authority

Verify package/source/selector/run identities, 379 fresh selector processes, 365/365 accepted prefix, first-red 366,
all report-only results, selector-379 witness PASS, separate non-gating diagnostic credit=0, and immutable postflight.
Control-plane commits after package 83 are not semantic evidence. Record TB13's start-of-turn `READ_MODE` process
order deviation as procedural only.

### BK1 — Enumerate every emitter behind the retained reason

Audit `build_rotation_system` and prove every condition that can emit `VertexTracePortOrdinalInvalid` in package 83.
At minimum distinguish the legacy singularity-port lookup/negative-ordinal branch from the new
`vertex_locus_secondary_parameter(...) == nullopt` branch. Do not plan a semantic fix from the error name. State
whether any other producer or projection can create the same rendered reason.

### BK2 — Trace the vertex-10 failing incidence statically

Trace every trace-ray incidence processed at locus vertex 10 far enough to identify the candidate arc, trace,
orientation, source face, segment slice, endpoint/terminal authority, and origin port for face `(8,10,11)`. Determine
which incidence can reach each BK1 failure condition. If more than one remains statically possible, state the exact
missing runtime datum rather than selecting one by plausibility.

### BK3 — Audit exact second-point/parameter semantics

Review `vertex_trace_ray_second_point` and `vertex_locus_secondary_parameter` against actual production arc slicing
and trace endpoint semantics for Forward and Reverse incidences, including boundary-transit exits, continuation to a
next segment, interior terminal contacts, terminal boundary points, face/locus membership, and exact denominator
validity. Determine whether CB15's helper contract covers every valid production incidence or whether a valid ray can
legitimately lack the represented second point. Keep all reasoning exact; no float/tolerance/trigonometric ordering
is authorized.

### BK4 — Separate diagnostics from semantics

If BK1-BK3 do not prove one semantic correction from static authority alone, freeze a **diagnostic-only** successor.
A sufficient diagnostic must distinguish the exact failing subcondition and retain at least locus vertex, source
face, arc, trace, orientation, segment bounds and the relevant endpoint/second-point availability state. Use distinct
typed reasons where semantically different conditions currently collapse. Do not broaden diagnostics beyond what is
needed to make the next runtime result decisive.

### BK5 — Re-evaluate CB15 without over-reverting

If one semantic defect is proved, bound the correction to the exact invalid helper/endpoint assumption and preserve
CB15's settled invariants: locus-relative exact within-wedge ordering, both orientations, interior-terminal support,
exact-coincidence fail-close, no arc/trace/orientation identity tie-break, unchanged edge-locus ranking, and unchanged
fan-slot/incidence/cut ownership unless the review independently proves one is the owner. Do not revert CB12 or CB14
diagnostic/terminal-ownership corrections.

### BK6 — Preserve accepted-boundary and carried-red ownership

Prove any successor is compatible with accepted ordinals 1-365 and selector-379 immutability. Keep 368 sphere, 369
saturation, 370 empty-network typed error, 374 folded-cone, 371/372 test coupling, vertex 30, and finalize/contact
fall-through under their existing owners. 367/371/372 currently share the vertex-10 upstream red and do not create
duplicate stable events.

### BK7 — Keep the v47 runtime obligation open

`M3-CP4c3-TB11-CAND-01` does **not** close from TB13 because the five-ray v47 rotation and distinct former-pair
secondary ranks were not published. `M3-CP4c3-TB12-REV-CAND-01` is only partially runtime discriminated. Any future
TB successor that clears vertex 10 must re-prove the original conjunction: 365/365 accepted prefix, old v47
collision absent, and full five-ray v47 rotation with distinct former-pair ranks. There is still no vertex-30
discriminator.

### BK8 — Freeze one successor and close review durably

If BK1-BK7 prove one semantic owner, issue exactly one minimal Code + Build successor with focused positive/negative
compile-time witnesses, the eight standard GMP/GMPXX compile targets, no runtime, and a falsifiable immutable
artifact-only TB successor. If the exact condition remains underdetermined, issue only the minimum diagnostic Code +
Build successor needed by BK4. Update `ORIENTATION.md` (mandatory REVIEW-turn update),
`Regression_Root_Cause_Tracker.md`, `M3_CP4c_Consolidated_Record.md`, `TODO.md`,
`Future_Chat_Session_Handoff.md`, `ROADMAP.md`, and `CHANGELOG.md` without altering stable accounting unless review
evidence authorizes it.

## Prohibitions

No Directional runtime, benchmark, configure, compile, link, package, product/test/fixture/selector mutation,
unchanged TB13 retry, identity-based ray-order tie-break, tolerance/float-derived topological decision, opportunistic
carried-debt repair, or closure of the v47 candidate without its missing runtime discriminator.

## Completion criterion

The review closes only when the exact set of `VertexTracePortOrdinalInvalid` emitters is established, the vertex-10
candidate incidence(s) and exact second-point/parameter contract are audited, semantic defect versus diagnostic
insufficiency is adjudicated without guessing, the v47 re-proof obligation remains explicit, all TB13 reds are
categorized without double counting, and exactly one bounded falsifiable successor is frozen.
