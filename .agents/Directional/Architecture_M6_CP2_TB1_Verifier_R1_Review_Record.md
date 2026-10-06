# M6-CP2-TB1-VERIFIER-R1-REV — Independent Review Record

**Disposition:** REJECTED FOR BOUNDED RECOVERY / CANDIDATE UNPROMOTED
**Reviewed candidate:** `11382000465 / 9c8478aec40bf07144ca7372c2aa58293cd42f5e`
**Runtime:** `37393554373 / 112044082007`, **462/491**
**Exact successor:** `M6-CP2-CB1-VERIFIER-R3`

## Review authority and evidence

Review used an exact source snapshot of semantic source `9c8478aec40bf07144ca7372c2aa58293cd42f5e`: workflow run `37395710753`, artifact `11383307041`, provider digest `sha256:ba5d6cc2b9f21d81fd90491586f0126ae0872200bce293f7181016f4868a34ae`, archive digest `c314fb145c5e9426cb02898af8e91216b11514e184eb8648f6f36abdb8b903b3`, 5454 files, `runtimeExecution=false`. The turn selected `READ_MODE=snapshot`; the mode was selected only after a few repository-document reads, which is a tool-policy miss. Static source review after that point used only the verified local snapshot.

Runtime evidence is the GitHub job log for `37393554373 / 112044082007` plus `.workflow-mailbox/m6-cp2-tb1-verifier-r1-exec/latest.json`. The harness completed all 491 exact-filter processes and immutable postflight. Result/log upload failed only afterward because the caller still named predecessor-turn output paths. No duplicate runtime is required or authorized.

Mechanical re-derivation is accepted: focused30 **26/30**, CP2 focused12 **11/12**, selector449 **425/449**, aggregate **462/491**, exact-one **491/491**, zero skips, benchmark 0. RED ordinals match the EXEC report.

## Finding R1-REV-01 — A7 exact-step verifier requires identity that A7 intentionally does not publish

**Severity:** High / production verifier false rejection.
**Disposition:** CONFIRMED; primary cause of the broad R1 RED cluster.

A6 publishes one `QuotientSelectedPathCertificate` for every non-root class member. Each certificate owns `root`, `target`, exact `orderedRelations`, orientations, and an optional legacy `SelectedRelationPathCertificate`. A7 deliberately projects only the legacy certificate values into each vertex, then sorts and deduplicates them. The legacy type contains support, start/end chart/component, ordered HardRail/Periodic steps and composed transport, but **no A6 target occurrence or path identity**.

R2's verifier reverses that lossy projection by scanning all A6 selected paths and demanding exactly one candidate whose legacy fields match the A7 path. On a second matching candidate it sets the selected candidate back to null and emits `MissingPublishedAuthority:a7:a5-relation-step`. That uniqueness is not published authority. Different A6 root→target paths can collapse to the same legacy path after OrdinaryFront steps are omitted, and A7 explicitly deduplicates those projections.

This is exactly the case RA-29a §3 anticipated: when positional correspondence cannot be established from published records, the verifier must use the same-ID relation-value fallback. R2 did not implement that fallback. It therefore turns representational ambiguity into missing authority and rejects accepted production rows.

The direct runtime signature is consistent with the static defect: focused30 ordinals 6/20/24 and selector ordinals 115/116/141/143/150/217/218/231/232/246/436/437/438/444/446/448 report `VerificationFailed:MissingPublishedAuthority:a7:a5-relation-step`. The other feature/flow/arrangement REDs fail because the pipeline stops earlier at `NotProductionReady`/`tracing` or never reaches their intended mutation/oracle seam. Focused30 ordinal25 similarly never reaches its expected produced arrangement.

### Required correction

For each A7 legacy path, collect all A6 selected-path certificates in that class whose `legacyProjection` has the same non-value semantic identity. Never require target uniqueness that A7 does not carry.

- **One matching A6 path:** use its exact HardRail/Periodic subsequence of `orderedRelations` and orientations; each A7 step must equal the exact cited A5 `canonicalRelationValue` after orientation.
- **Multiple matching A6 paths:** positional target correspondence is unobservable. Apply RA-29a's fallback: for each A7 step's typed HardRail/Periodic owner ID, collect every A5 relation in the class with that owner; require at least one, require `canonicalRelationValue` on every candidate, require all those values identical, and require the A7 step's `appliedTransport` to equal that common value (inverted when the published step direction is reverse). First-match lookup remains forbidden.
- **No matching A6 legacy path:** `MissingPublishedAuthority:a7:a5-relation-step` remains valid.

Do not add a target field to the legacy A7 type in this recovery; that would expand the frozen product contract. Do not change A5/A6 producers to make the verifier's reverse lookup unique.

## Finding R1-REV-02 — RA-29a component-partition requirement contradicts accepted A0 ingress semantics

**Severity:** High / review-specification error causing production false rejection.
**Disposition:** RA-29a §4 WITHDRAWN and replaced by RA-29b below.

R2 recomputes raw triangle edge-connected components and requires `SourceTopologyRegions::component_for_row` to induce exactly that partition. This assumes `SourceComponentId` is derivable from raw connectivity alone. The API does not provide that invariant: `build_source_topology_regions` receives `sourceFaceComponents` as ingress labels and may publish multiple disconnected topology regions carrying the same component label.

Accepted selector449 ordinal 144 (`MaterializerConsumesPublishedTopologyRegionsExactlyOnce`) deliberately constructs two disconnected squares, supplies `sourceFaceComponents = 0` for every face, obtains a valid produced phase-front product, and requires materialization to succeed. R2 rejects this accepted authority at `SourceIncidenceMismatch:a0:component-adjacency`. That is the mandatory RA-28 §7 Review stop.

The new identity-2 sub-witness makes the same invalid assumption in the other direction by merging component labels across a disconnected produced fixture and expecting rejection. Because the verifier receives only the already-published `SourceTopologyRegions` and raw mesh, not an independent copy of ingress component labels, there is no independent expected component labeling to reconstruct. Mesh connectivity cannot substitute for that missing authority.

### Required correction

Withdraw the exact mesh-connected-component equality check and remove the identity-2 component-merge sub-witness. Identity 2 continues to cover the real canonical source-face mismatch, shared `SurfacePointSourceSupportResolver` equality, wedge binding/sheet incidence, seam incidence and other A0/A5 elementary facts.

A future stronger component-label verifier would first need an independently published ingress-label certificate/input. CP2 R3 must not infer component IDs from connectivity and must not change accepted selector144 semantics.

## Finding R1-REV-03 — focused12 ordinal 6 baseline failure is part of R1-REV-01

The strengthened hard-rail identity now constructs a produced >=2-step A6 path, but its baseline `verify_m6cp2_records(pathRecords).verified()` is false before the intended path-structure tamper. Its source authority is connected and does not trigger the component-label issue. The baseline passes through the same A7 legacy-path reverse-binding code described in R1-REV-01. Treat this as the focused witness for that production false rejection, not as an independent regression class.

R3 must make the baseline green before the tamper, retain the >=2-step path-structure mutation, and add a non-vacuity assertion that the chosen produced fixture actually contains the projection ambiguity (two or more A6 selected paths collapsing to an equal legacy projection). If the existing hard-rail fixture does not expose that ambiguity after the production fix, use another already-produced fixture; do not forge unchecked authority.

## EXEC-OBS-01 — post-runtime artifact upload path defect

The runtime harness used `TURN_ID=M6-CP2-TB1-VERIFIER-R1-EXEC` and wrote under that turn-local path, but the workflow upload steps still used `M6-CP2-TB1-VERIFIER-EXEC`. Both uploads therefore failed after the harness had completed and postflight had passed. This is orchestration-only and does not invalidate the 491 runtime results.

The next TB caller must derive result/log upload paths from the same `TURN_ID` used by the harness, rather than duplicating a predecessor literal. Schema validation alone cannot catch this semantic path mismatch. No runtime retry is authorized merely to recreate R1 artifacts.

## Causal clustering and accounting

All 29 RED rows are explained by two bounded causes:

1. **R1-REV-01 A7/A6 reverse-binding false rejection** — the direct `a7:a5-relation-step` rows plus downstream pipeline/reachability rows, including focused12 ordinal6 and focused30 ordinal25;
2. **R1-REV-02 invalid A0 component-partition rule** — selector449 ordinal144.

Neither represents a newly discovered user-visible optimizer regression. Both were introduced by CP2 verifier recovery authority, and the component rule is specifically a review-agent specification error. The candidate remains rejected/unpromoted and the previously reviewed CP1 runtime remains authority.

Stable accounting remains **60 events / 16 categories / 44 recurrences**, architecture debt **1**. No stable repricing is made.

## Frozen recovery routing

RA-29b freezes one bounded recovery:

`M6-CP2-CB1-VERIFIER-R3` → `M6-CP2-TB1-VERIFIER-R2-EXEC` (**491**) → mandatory `M6-CP2-TB1-VERIFIER-R2-REV`.

R3 is Code + Build only. It may change the verifier and existing focused identities 2/6 as specified, but may not change optimizer source, A5/A6/A7 producer semantics, focused30 names/order, CP2 focused12 names/order, selector449/routing449 bytes, or gate size. Any accepted gate authority that still rejects after those two corrections returns to Review.
