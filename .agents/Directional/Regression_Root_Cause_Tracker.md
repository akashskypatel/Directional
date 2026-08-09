# Surface-Cell Regression Root-Cause Tracker

This is the permanent regression index for the production surface-cell
implementation. Turn reports retain detailed evidence; this tracker keeps one
stable entry per regression so repeated architectural causes remain visible.

## Rules

- Assign a stable ID when accepted behavior, test authority, packaging, or a
  public contract regresses relative to an exact baseline.
- Do not create a second entry when the same regression reappears. Update its
  `last_seen`, evidence, and recurrence count.
- Record the earliest evidenced cause, not only the terminal failure string.
- Link every entry to one primary architectural cause family. Add contributing
  families only when independently evidenced.
- Mark a regression resolved only after a later immutable artifact proves the
  affected acceptance gate. Compile success alone is `fix_pending_runtime`.
- Keep persistent blockers that are not regressions in the separate table so
  they are not accidentally reported as changes caused by the latest patch.

## Status vocabulary

| Status | Meaning |
|---|---|
| `active` | Reproduces in the current runtime authority. |
| `fix_in_progress` | An authorized Code + Build turn is implementing a correction. |
| `fix_pending_runtime` | The correction compiles, but immutable runtime acceptance has not run. |
| `resolved` | A later immutable artifact passes the affected gate. |
| `test_authority_resolved` | The regression was in a test/oracle and corrected runtime evidence accepts the intended contract. |

## Architectural cause families

| Cause family | Definition | Regression IDs | Recurrence signal |
|---|---|---|---|
| `AUTHORITY_DOMAIN_CONFLATION` | Distinct topology, validation, or serialization identities share an untyped numeric representation and are consumed interchangeably. | `G4-R001`, `G4-R004`, `G4-R006` | **Repeated three times across production and tests.** Architectural review required before another numeric authority is added. |
| `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | Complete retained authority is incorrectly required to appear in, or be consumed by, one local face/path rather than validated globally and witnessed only where selected. | `G4-R002`, `G4-R007` | **Repeated twice.** Review ownership and consumption boundaries together. |
| `EXECUTABLE_COVERAGE_GAP` | Required counterfactual contracts compile outside the default immutable artifact or are not independently discoverable. | `G4-R003` | Single occurrence; retain artifact-closure checks. |
| `POLICY_STATE_CONFLATION` | Internal execution state and caller-visible policy use one mutable flag. | `G4-R005` | Single occurrence; keep internal lifetime and public retention separate. |

## Regression entries

### G4-R001 — genuine source boundaries rejected by transition quotient

| Field | Value |
|---|---|
| Classification | product implementation regression |
| First detected | artifact `9024549134`, implementation `7f486632b154a303789df6c4dd44f602c8c71281` |
| Baseline / symptom | Previously accepted plane, seam, close-sheets, and cylinder all failed `3/3` at `InvalidFrontBoundaryAuthority`; producer fell from `124/127` to `99/128`. |
| Root cause | `assign_open_front_boundary_authority()` required an `edge_matching_indices()` entry before classifying a one-face edge, although that index contains only two-face interior edges. Canonical boundary topology and optional interior transition identity were treated as one authority. |
| Cause family | `AUTHORITY_DOMAIN_CONFLATION` |
| Corrective guard | Genuine one-face boundaries carry canonical topology without an invented interior index; two-face transitions retain their separate index authority. |
| Resolution | `resolved` by artifact `9026181778`; direct multi-face seam and the focused boundary/certificate contracts passed. |
| Evidence | `Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Transition_Quotient_Runtime_Regression_Independent_Design_Review_Report.md` |

### G4-R002 — internal isolation seams required as cell-boundary crossings

| Field | Value |
|---|---|
| Classification | product/contract regression |
| First detected | artifact `9024549134`, implementation `7f486632b154a303789df6c4dd44f602c8c71281` |
| Baseline / symptom | Torus phase-front was `Produced` but stopped at `UnconsumedAuthoritativeIsolationSeam`; all `4/8/4` region/seam/relation authority remained unconsumed. |
| Root cause | Seam consumption was inferred only from `SurfaceTraceSegment::transitionSourceEdges` on output cell-boundary paths. Internal isolation seams are region transport authority and need not cross a selected cell side. |
| Cause family | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` |
| Corrective guard | Validate reciprocal seam certificates globally; require a certificate only when cross-sheet transport is selected; never consume by presence or counts. |
| Resolution | `resolved` by the boundary/isolation certificate and canonical-transition artifacts; direct torus later consumed all `4/8/4`. |
| Evidence | `Gate_4_Transition_Quotient_Runtime_Regression_Independent_Design_Review_Report.md`; `Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R003 — required quotient counterfactuals absent from immutable artifact

| Field | Value |
|---|---|
| Classification | build/test packaging regression |
| First detected | artifact `9024549134` |
| Baseline / symptom | Required semantic-digest tests existed only in the disabled historical target; several reviewed quotient and retention contracts were not independently discoverable. |
| Root cause | Coverage was added to a target excluded by the default build instead of a packaged executable, and artifact closure was not verified against the review test list. |
| Cause family | `EXECUTABLE_COVERAGE_GAP` |
| Corrective guard | Every mandatory contract must be independently named, discovered in a default packaged executable, and listed during artifact preflight. |
| Resolution | `resolved` in artifact `9026181778`, which exposed all 33 reviewed transition-quotient contracts. |
| Evidence | `Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R004 — full-`EF` and compact transition indices serialized as one domain

| Field | Value |
|---|---|
| Classification | product implementation regression |
| First detected | artifact `9026181778`, implementation `82151bf51bce9af9859282b2a03e295a0ee5a309` |
| Baseline / symptom | Plane and close sheets failed `InvalidAuthoritativeTransitionSourceEdge`; cylinder and torus failed `InvalidPeriodicCutAuthority`; only seam remained direct-valid. |
| Root cause | One `int` route field alternated between a full `mesh.EF` row, a source-wide compact two-face index, and potentially a region-local compact index. Materialization always interpreted it as the source-wide compact domain. |
| Cause family | `AUTHORITY_DOMAIN_CONFLATION`; recurrence of `G4-R001` |
| Corrective guard | Store canonical topology separately, validate CrossField authority in its full-`EF` domain, and serialize only the source-wide compact pair beside topology. Never use region-local numbering. |
| Resolution | `resolved` by artifact `9028103772`, implementation `edc14d38f862b94941b249f564050e2e1f8f5287`; plane, seam, close sheets, and cylinder became `3/3`, torus consumed `4/8/4`. |
| Evidence | `Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R005 — internal failure-injection retention leaked into public context

| Field | Value |
|---|---|
| Classification | public contract regression |
| First detected | artifact `9026181778` |
| Baseline / symptom | `retainIntermediateGeometry=false` still returned trace authority whenever deterministic failure injection needed internal state. |
| Root cause | One computed flag controlled both temporary execution lifetime and the caller's public retain/release request. |
| Cause family | `POLICY_STATE_CONFLATION` |
| Corrective guard | Keep `retainForExecution` separate from `retainRequested`; every terminal path publishes context only when requested. |
| Resolution | `resolved` by artifact `9028103772`; the true/false counterfactual reached the same injected failure and retained iff requested. |
| Evidence | `Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R006 — canonical transition tests retained obsolete numeric-domain authority

| Field | Value |
|---|---|
| Classification | test-authority regression |
| First detected | artifact `9028103772` |
| Baseline / symptom | Three new canonical tests selected topology absent from serialized routes; two Phase10 tests used compact values as `mesh.EV` or full-`EF` rows. Their intended materializer assertions were unreachable or invalid. |
| Root cause | Test helpers repeated the production domain conflation and did not prove a real serialized witness before tampering it. |
| Cause family | `AUTHORITY_DOMAIN_CONFLATION`; recurrence of `G4-R001` and `G4-R004` |
| Corrective guard | Record an actual serialized cell/side/segment/route slot, pair compact values with canonical topology, and resolve full-`EF` validation identity only through reciprocal incident faces. |
| Resolution | `test_authority_resolved` by artifact `9029584083`; all seven canonical contracts passed individually. |
| Evidence | `Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md`; `Gate_4_Canonical_Transition_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Report.md` |

### G4-R007 — single-relation face-chart projection over-rejects torus

| Field | Value |
|---|---|
| Classification | product implementation regression |
| First detected | artifact `9030700527`, implementation `8f37612148f34bac63cf294000c17c7de2e03b41` |
| Baseline / symptom | Direct torus remained `0/3`; `LocalSheetMismatch` increased from 74 under artifact `9029584083` to 165, rejecting 91 additional faces. Plane, seam, close sheets, and cylinder remained `3/3`. |
| Root cause | The resolver treats a quotient vertex's complete relation graph as a direct star around one scalar representative, requires every retained relation to be consumed by each incident face, and requires a reciprocal peer on that face. The focused two-quad fixture carried only one relation per shared vertex and missed chained and unused production authority. |
| Cause family | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`; recurrence of `G4-R002` |
| Corrective guard | Validate complete relation structure and reciprocity globally, derive exact vertex-local graph reachability, and require only the selected face's witness path. Add chained, unused, off-face-peer, missing-link, tamper, ambiguity, isolation, and row-order counterfactuals. |
| Status | `fix_in_progress` under `Gate_4_Torus_Multi_Rail_Chart_Reachability_Code_Build_Plan.md`. |
| Evidence | `Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Artifact_Only_Test_Benchmark_Report.md` |

## Persistent blockers that are not current-patch regressions

| ID | Blocker | Reason kept separate | Current gate |
|---|---|---|---|
| `G4-B001` | Baseline torus `LocalSheetMismatch` (74 issues) | This surfaced after upstream route/quotient repair; it was not introduced by the rejected projection. One scalar `SurfacePoint` loses the complete chart/equivalence authority retained by its quotient class. | Multi-rail reachability must reduce this to strict-valid torus `3/3`; reduced issue count is not acceptance. |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing` | This is an earlier target-size-dependent scheduling defect, not the direct final-validator regression. Independently generated region fronts do not share one source-authoritative hard-rail breakpoint schedule. | Deferred scheduling slice; still gates prescribed sphere. |
| `G4-B003` | Nonzero periodic `Z4` rotation | The producer rejects nonzero accumulated branch matching and hard-codes rotation zero. This is missing capability, not caused by the chart resolver. | Deferred G4 slice. |
| `G4-B004` | Positive multi-isolation quotient witness | The current fixture accepts certificates but does not create a quotient class spanning multiple local sheets. This is missing test authority unless a valid fixture proves production lineage loss. | Deferred focused fixture/implementation slice. |

## Architectural review triggers

An architectural review should be requested when any of these occurs:

1. A cause family reaches two regressions.
2. A resolved regression reappears in a later immutable artifact.
3. A fix moves the same failure downstream without restoring the entering
   accepted matrix.
4. Focused tests pass while a representative direct fixture regresses for a
   state shape absent from those tests.
5. A new bare numeric field carries topology, source-row, compact-index,
   ownership, or semantic identity authority without a typed domain.

`AUTHORITY_DOMAIN_CONFLATION` and `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`
already satisfy trigger 1. The next independent architectural review must
examine these families even if the immediate torus correction passes.
