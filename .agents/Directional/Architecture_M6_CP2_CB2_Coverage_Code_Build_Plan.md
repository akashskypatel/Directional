# `M6-CP2-CB2-COVERAGE` — CP2 Verifier Binding + Negative-Coverage Code + Build Plan

**Owner:** `M6-CP2-CB2-COVERAGE`
**Type:** Code + Build only; compile/package; runtime forbidden.
**Authority:**
- RA-29d;
- `Architecture_M6_CP2_TB1_Verifier_R2_Review_Record.md`, review-agent addendum §U1–§U4;
- frozen §6.2, §6.3 and §10 (M6-CP2);
- RA-28a §1–§2 and §5.

**Entering runtime authority:** `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` (491/491).
**Accounting:** 60 / 16 / 44, debt 1.

## Goals (exactly these)

### G1 — A7 vertex binding (RA-28a §2; production verifier)

In the A7 partition, for every A7 vertex `v` of class `C` with support certificate `s`, require all of:
- `v.representative` ∈ `C.members`;
- `v.sourcePoint` == the published `point` of occurrence `v.representative`, with exact equality of face, barycentric and position;
- `v.position` == `v.sourcePoint.position`;
- `v.support == s.publishedSupport`.

Together with the existing check `member.support == s.publishedSupport`, this binds every vertex to the class-common support. Failure: `SourceSupportIncidenceMismatch`, site `a7:vertex-binding`. Use exact equality only; no tolerance.

**Stop for Review** if any accepted row would fail. A7 copies these fields verbatim (`RemeshPipeline.cpp:6985-6993`), so the check should be gate-neutral.

### G2 — dead codes (RA-28a §5 in reverse)

- **Remove** `UncertifiedAuthoritySubstitution` from `VerificationFailureCode` and its name table.
- **Give `BoundaryOrEulerMismatch` its predicate.** Split the recomputed connected-components, boundary-loop-count and Euler-characteristic comparisons out of `certificate:a7` into separate findings: `BoundaryOrEulerMismatch` at `a6:components`, `a6:boundary-loops` and `a6:euler`. The remaining certificate-field checks stay under `certificate:a7`.

### G3 — negative coverage (identities 2–5; names and order unchanged; bodies strengthened)

Each witness:
- starts from a verified produced record view;
- asserts that its tamper changed the record;
- asserts the **exact code and site**.

| Identity | Witnesses (code / site) |
|---|---|
| 2 (A0/A5) | `a0:hard-feature-edge` (an edge not in A0); `a5:exact-corner-ownership` or `a5:corner-owner` (duplicate a corner owner) — `OccurrenceOwnershipMismatch`; `a5:directed-side-cycle` (permute one directed side) — `DirectedSideCycleMismatch`; `a5:wedge-isolation` (a transition seam that is not an A0 isolation seam) |
| 3 (A6) | `a6:exact-once-ledger` (drop one consumption); `a6:duplicate-certificate`; `a6:forest-joining-set` (flip one `Joining` to `CycleClosing` with no forest change); `a6:forest-cardinality` or `a6:forest-spanning` (remove one forest edge); `a6:edge-manifoldness` (a third cell on one edge, if constructible from records; else classify); and from G2, `BoundaryOrEulerMismatch` at `a6:boundary-loops` / `a6:euler` (tamper the A7 certificate counts so they disagree with the recompute) |
| 4 (A7) | **G1** `a7:vertex-binding` — four witnesses: (a) a non-member representative, (b) a moved `sourcePoint` with self-consistent support, (c) a `position` mismatch, (d) `v.support ≠ publishedSupport`. Also `a7:support-cover` (drop one support certificate), `a7:topology-copy` (alter one A7 cell), `certificate:a5`, `certificate:a6`. |
| 5 (§6.3 coverage map) | A table-driven body with one row per frozen §6.3 class (`Architecture_M6_Frozen_Definitions.md` §6.3, 10 rows). Each row is either a runtime record-view witness with exact code and site (it may reuse witness helpers from identities 2–4 and 6–7, but **must execute** the witness here), or an API-shape row pinned by a compile-time trait: no mutating overload; no overload accepting a producer error variant. Keep the existing non-mutation assertion. Required rows: create/renumber IDs; union / replacement representative (G1 a); search or replace a route (path structure); infer missing authority (`MissingPublishedAuthority` at `a6:a5-relation` or `a6:a5-transport` or `a6:selected-path-certificate`); canonicalize (non-mutation); substitute an equivalent or reverse unreferenced relation (a certificate citing the reverse or an unowned relation → its exact resulting code/site); weld (pinched-topology witness and G1 b); repair (directed side / quad / support / certificate tamper); mutate (API trait); upstream failure (API trait). |

### G4 — CB report coverage table

The CB report must contain a table mapping every §6.2 recompute category and every §6.3 class to:
- its production predicate (`file:line`);
- its executed witness (identity plus code/site), **or** its API-shape classification with a reason.

Any row without either is a **stop for Review**.

## Forbidden

- Producer (A5/A6/A7) semantic changes.
- Any `SurfaceMeshOptimizer` change.
- Any focused-30, focused-12, selector449 or routing449 byte or order change.
- New identities. The gate stays **491**.
- Tolerances.
- Unchecked product factories.

## Static and compile gate

- `git diff --check`.
- A diff census separating production from tests.
- Frozen hashes: focused-30 `1e815443…`, focused-12 `2aa57aac…`, selector449 `d4a0d1b7…`, routing449 `9c88a5ed…`.
- Mandatory reusable GMP/GMPXX workflow, standard eight targets, `runtimeExecution=false`.

## Successor

Compile-green → `M6-CP2-TB2-COVERAGE-EXEC`: focused-30 + focused-12 + selector449 = **491** fresh exact-filter processes, with upload paths derived from the harness `TURN_ID` → mandatory **`M6-CP2-CLOSE-REV`**.

`M6-CP2-CLOSE-REV` adjudicates the frozen CP2 exit (§10) against the G4 coverage table and the fresh 491 gate, and writes `M6_CP2_Closure_Record.md`. If CP2 closes → `M6-DEFN-R5`.
