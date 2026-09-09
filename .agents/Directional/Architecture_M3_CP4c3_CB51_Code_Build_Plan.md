# M3-CP4c-3-CB51 Code + Build Plan

**Status:** FROZEN / EXACT SUCCESSOR / RUNTIME-FREE
**Turn:** `M3-CP4c-3-CB51`
**Authority:** `M3-CP4c-3-TB45-REV`, EG0–EG9
**Runtime authority entering:** TB45/package110/selector409 — **399 PASS / 10 RED / 0 SKIP**, accepted **365/365**
**Stable accounting:** **47 events / 14 categories / 33 recurrences**, debt **5**, packages **110**

## 1. Objective

Correct two stale test-authority dependencies exposed only after CB50 progressed the mechanical witness, and
discharge one previously missed diagnostic consistency audit. Keep topology semantics, fixtures, selector409 and
all carried RED owners frozen.

CB51 may edit only the minimum product diagnostic/test source required below, then compile/package. It executes no
Directional runtime.

## 2. Ordinal367 — preserve independence while correcting the retired terminal-slit rule

In `tests/FieldAlignedCurveNetworkTests.cpp`, correct `independent_fragment_partition()`.

The helper already derives each trace arc's forward/reverse face-walk orbit independently. For a final no-barrier
segment:

- skip it only when those independently derived forward/reverse orbits are equal (non-separating);
- retain it as a real fragment-separating segment when the independently derived orbits differ;
- when retained, preserve the existing `tracePieces`, touched-edge, fragment-orbit and edge-orbit evidence updates;
- do not query a product-owned fragment partition, product `FragmentCornerIncidence`, product region membership, or
  a helper whose result would make the oracle circular.

Update the stale comment that says every terminal slit is hypothetical. No fixture, expected region count, selector
identity, or production topology rule changes.

## 3. Protected 390/393/406/407 — producer frontier evidence must survive plan success

The mechanical fixture now lawfully produces a `GlobalTopologyPlan`. Remove the obsolete protected-test
precondition that requires `!mechanical.plan.has_value()`.

Make the **already-computed** producer frontier evidence observable on successful `GlobalTopologyPlan` publication:

- reuse `RegionBuildSuccess.frontier`; do not recompute `P_U`;
- factor/reuse the existing producer-side frontier-row construction used by
  `annotate_region_frontier_evidence()` so success and failure paths cannot drift;
- publish only diagnostic evidence needed to express the existing Part XII rows: partition identity/component
  faces, owner/census correspondence and existing interior-arc census references;
- carry the evidence through `GlobalTopologyPlanCandidate`/`GlobalTopologyPlan` immutably with its existing source,
  network and cut-graph bindings;
- do not let the diagnostic influence candidate validation, region construction, certificate acceptance, semantic
  digest, cut selection, owner election, or control flow.

Then update 390/393/406/407 to consume the successful plan's producer evidence and the existing cut-graph certifier
census. Each protected identity must still:

1. establish the real producer predicate;
2. mutate a same-domain copy;
3. prove the corrupted copy is rejected;
4. emit a non-vacuous Part XII receipt.

The tests must fail if successful-plan producer evidence is absent, empty, truncated where completeness is
required, in the wrong partition domain, or lacks correspondence to the certifier census.

Do not manufacture a production failure and do not switch to a synthetic fixture merely to recover the old
failure-locus branch.

## 4. Typed terminal-subject evidence after successful plan

The old terminal-failure subject branch is no longer the protected contract when the plan succeeds. For the
success path, receipt wording must name the authoritative successful-plan producer subject (for example
`terminalSubjectBranch=PlanFrontier`) rather than fabricating a failure `Region` or `SourceFace`.

Keep the existing Region/SourceFace fail-closed helper for actual failure-path tests. Do not claim
`regionFrontierSubjectDomainRelation=Outside` from an absent failure locus. The protected receipt must distinguish
success-path frontier evidence from failure-path subject evidence explicitly.

This supersedes CB50's frozen expectation that the four protected identities would necessarily remain on a
terminal failure path.

## 5. Discharge TB44 EG10.3 — fragment-incidence failure evidence

In `src/geometry/GlobalTopologyPlan.cpp`, the failure-only
`TraceCutFaceFragmentCountMismatch.fragmentIncidences` loop must match the already-authoritative fragment-count rule:

- a final no-barrier trace segment is omitted only when `forwardOrbit == reverseOrbit`;
- a separating terminal segment (`forwardOrbit != reverseOrbit`) is retained in `fragmentIncidences` and its count;
- this edit is diagnostic only and must not change `tracePieceCount`, `fragmentOrbits`, region construction,
  ownership, error selection, or any success/failure branch.

Leave `TraceTerminalSlitCensusDiagnostic::terminatesInTerminalSlit` as the syntactic final-no-barrier label. Its
role is trace-shape census; separation is already separately visible from per-arc forward/reverse orbit evidence.
Record this explicit adjudication in the CB51 report.

## 6. Frozen unchanged surface

CB51 must not change:

- selector409 bytes, any selector manifest, or gate membership;
- fixtures, meshes, fields, rails, seeds, benchmark inputs, or expected carried failures;
- Part VIII, Part XI/Part XI-A, or Part XII normative definitions;
- `P_U` membership/barrier semantics, `build_regions()` decisions, region IDs/boundaries, face-walk construction,
  cut selection, actual embedded graph construction, source authority, ownership policy, or certifier partitions;
- carried RED owners 368/369/370/374/398;
- accepted-prefix behavior 1–365;
- retired error/proxy behavior.

No drive-by refactor, new topology abstraction, fallback, repair, selector growth, test skip, or assertion weakening
is authorized.

## 7. Required static review before compile

Before compile, verify from source:

1. the independent oracle's terminal decision is based only on its independently derived forward/reverse orbits;
2. every retained separating terminal segment receives the same independent bookkeeping as other real trace pieces;
3. successful-plan frontier diagnostics are populated from `RegionBuildSuccess.frontier`, not reconstructed from
   the published expected result in tests;
4. success-path diagnostics are observation-only and cannot alter semantic digest or validation;
5. 390/393/406/407 still contain a real-data predicate and a deliberately corrupted same-domain negative;
6. the failure-only fragment-incidence diagnostic uses the separation conjunct while the syntactic terminal-slit
   census remains intentionally unchanged;
7. no fixture/selector/carry-owner source changed.

## 8. Build boundary

Compile/package using the durable GMP/GMPXX reusable workflow. The exact pushed semantic source is compile
authority. Approved compile may include affected production/test targets; it must execute **no** generated
Directional binary — no tests, benchmark, `ctest`, discovery/list/help/version command, CLI, fuzzer, or custom
input.

The accepted package must record exact source SHA, `runtimeExecution=false`, GMP/GMPXX link evidence, recursive
manifest verification and clean source status.

Package count advances only on an accepted new immutable package. Stable event/category/recurrence totals do not
change in CB51.

## 9. Freeze TB46 only after compile/package success

On accepted compile/package, author exactly one
`M3-CP4c-3-TB46-EXEC` artifact-only plan bound to that immutable package and unchanged selector409.

TB46 must execute all 409 identities exactly once in fresh processes and measure:

- ordinal367 reaches and executes the corrected independent partition/disc oracle without the retired
  unconditional terminal-slit skip;
- 390/393/406/407 execute successful-plan producer frontier evidence, their real Part XII predicates and
  same-domain corruption negatives; no early `ASSERT_FALSE(plan.has_value())` remains;
- accepted 1–365 = 365/365;
- carried 368/369/370/374/398 are reported without speculative merge/repricing;
- 311/312/314/315/356/357/404/408/409 remain PASS;
- ownership remains 300/0/0 and retired-code silence remains;
- immutable pre/post controls remain equal and no build/repair/mutation occurs.

Do not freeze an expected aggregate PASS/RED count. A later independent failure remains a review subject.

## 10. Exact successor on successful compile

**`M3-CP4c-3-TB46-EXEC` — Test + Benchmark / artifact-only**, under the plan frozen from the accepted immutable
CB51 package. If compile/package fails, remain inside the CB51 correction boundary.
