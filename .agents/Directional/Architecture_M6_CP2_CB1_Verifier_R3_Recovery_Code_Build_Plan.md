# Architecture M6 CP2 CB1 Verifier R3 Recovery Code + Build Plan

**Turn:** `M6-CP2-CB1-VERIFIER-R3`
**Authority:** `M6-CP2-TB1-VERIFIER-R1-REV` / RA-29b
**Boundary:** Code + Build only; compile/package, no Directional runtime.

## Goal

Remove the two Review-proved CP2 verifier false rejections without changing producer semantics or accepted gate authority:

1. make A7 HardRail/Periodic step verification respect the intentionally lossy/deduplicated A7 legacy projection and implement RA-29a's ambiguity fallback;
2. withdraw the invalid assumption that ingress `SourceComponentId` labels equal raw mesh connected-component IDs.

## Production implementation

### R3.1 — A7 relation-step binding

Change only verifier-side cross-stage logic in `src/pipeline/RemeshPipeline.cpp` unless compilation proves a minimal helper declaration is needed.

For each A7 `SelectedRelationPathCertificate`:

1. enumerate **all** A6 `QuotientSelectedPathCertificate` rows in the same quotient class with a `legacyProjection` whose non-value semantic identity equals the A7 path (support, start/end chart components/charts, ordered step typed owners/directions/chart endpoints);
2. zero candidates remains `MissingPublishedAuthority / a7:a5-relation-step`;
3. exactly one candidate: derive the HardRail/Periodic subsequence from that A6 row's exact `orderedRelations` and `traversalOrientations`; compare each A7 step against the exact A5 relation's `canonicalRelationValue`, orientation-adjusted;
4. multiple candidates: do **not** reject ambiguity. For each A7 step, collect all A5 relations in the class that share its typed rail or periodic owner ID. Require a non-empty set, present `canonicalRelationValue` on every candidate, and one identical canonical value across the set. Compare the A7 step's applied transport to that value, inverted for reverse direction. Any disagreement is `CertificatePayloadMismatch / a7:a5-relation-step`;
5. no first-match lookup and no selection by vector order;
6. do not add target identity to the legacy A7 product and do not change A5/A6/A7 producer semantics.

Keep the independent A6 selected-forest/path structure validation already added in R2.

### R3.2 — A0 component labels

Remove the verifier requirement that `component_for_row` equal raw face-edge connected components and remove the identity-2 component-merge negative that encodes that assumption.

Do not replace it with another inferred component-label rule. Current verifier inputs do not carry independent ingress `sourceFaceComponents`, so an expected component labeling is not independently observable. Preserve all other A0/A5 checks, including source-face topology, hard-feature-edge incidence, shared source-support resolution, wedge binding/sheet equality and isolation-seam incidence.

Accepted selector449 ordinal144 must remain unchanged and return green.

## Focused test changes

The CP2 focused-12 file stays byte-identical: same 12 names/order.

- **Identity 2:** keep the genuine source-face mismatch, support-resolver mismatch, wedge/sheet/seam checks. Delete only the disconnected-component merge sub-witness introduced by R2.
- **Identity 6:** require a clean baseline. Keep the always-bound A6→A5 transport tamper and >=2-step selected-path-structure tamper. Add a produced-authority assertion proving that the fixture used for the A7 binding portion contains at least two A6 selected paths with equal legacy projections after OrdinaryFront elision/deduplication; baseline verification must pass and then a value disagreement must fail at `a7:a5-relation-step`. If no existing produced fixture supplies this, stop for Review instead of forging records.

Do not modify focused30, selector449 or routing449 files.

## Static and compile checks

Before compile, verify locally from the exact snapshot/diff:

- no unique-target requirement remains on A7 legacy projections;
- no `a0:component-adjacency` exact raw-connectivity partition check remains;
- no producer/optimizer source changed;
- topology checks remain O(n log n) or better as frozen by RA-29a;
- `VerifiedSurfaceProducts` still owns contents and pipeline results still carry the verified report.

Compile/package all eight standard GMP/GMPXX targets through the reusable GitHub workflow. No generated Directional executable, test, benchmark, discovery command or ctest may run in R3.

## Required evidence

Record exact semantic source SHA, exact diff census, eight-target compile run/job, result/log artifact IDs and digests, package manifest count, GMP/GMPXX evidence, frozen focused30/focused12/selector/routing hashes, and `runtimeExecution=false`.

## Runtime successor

If and only if compile/package is green, exact successor is `M6-CP2-TB1-VERIFIER-R2-EXEC`.

That immutable TB turn must:

- consume only the R3 package;
- execute exactly focused30 + CP2-focused12 + selector449 = **491** fresh exact-filter processes;
- use the same `TURN_ID` source for harness output paths and workflow upload paths (no predecessor literal);
- execute zero benchmarks;
- perform immutable package/source/execution-view postflight;
- route to mandatory `M6-CP2-TB1-VERIFIER-R2-REV` regardless of green/red semantic outcome.
