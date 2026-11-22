# TB-REV-161 — adversarial continuation after handover (2026-11-22 UTC)

Continues `M6-CP3-TB-REV-161-P13-STAGED-SLIDE-ENTRY-STOP-DOWNSTREAM-RECEIPT-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_161_Staged_Slide_Entry_Stop_Downstream_Receipt_Independent_Review_20261122.md). Runtime-free: source reading, the TB161 report and [row 979 raw receipt](evidence/Architecture_M6_CP3_TB161_Staged_Slide_Downstream_Receipt_Raw.md), Haiku read-only audits, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **TB161 PASS upheld.** The independent byte, log and census re-derivation stands. Production activation stays held.
- **`M6-CP3-DEFN-161A-P13-SOURCE-FACE-OWNER-CONSISTENCY` is WITHDRAWN** (W3). In its place is the exact test-only `M6-CP3-CB-179-P13-STAGED-PLAN-OWNER-EVIDENCE-RECEIPT`, which prints owner evidence the product already computes. Activation moves to CB-181.

## Findings

**W1 — the first broken invariant is measured upstream of the plan, at the cut-graph certificate.**
- Row 979 already printed `sourceFaceCellularity=0`, which is `certificate.proves_cellularity()` (`SurfaceCutGraph.cpp:1127–1153`).
- `SurfaceCutGraph::make` accepts on `proves_embedded_cellularity()` alone (`:1074`). `proves_cellularity()` is first checked in plan validation (`GlobalTopologyPlan.cpp:2679`), after `build_regions`.
- The plan consumes the certificate's total owner map directly. Its component partition is only a consistency guard (`GlobalTopologyPlan.cpp:1544–1547`). So the single writer of source-face ownership is `build_source_face_ownership` (`SurfaceCutGraph.cpp:428–870`).
- `UncutFaceComponentOrbitSeedNotUnique` is the consumer reporting it. The independent review's question "which stage is earliest?" is answered by data already published: the certificate. A repair belongs there, or in the shared domain rule (W5 H2), not in the plan guard.
- Residual: `proves_cellularity()` can also fail on an owner-count, key-order or side-orbit check. The CB-179 receipt separates these cases.

**W2 — the owner evidence already exists and is already formatted.**
- For this code, the plan error carries the following:
  - the uncut component's seed count and state, its full face list, the partition identity and face-set digest;
  - the matching certifier census component and subset flags;
  - interior arc incidences;
  - certified-face observations with unavailable, distinct and multiset counts (`annotate_uncut_face_component_seed_evidence`, `GlobalTopologyPlan.cpp:950–1070`);
  - `fragmentOwnerEvidence` (`:2616–2623`). None of these is gated by `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS`.
- The certificate publishes `sourceFaceOwners` (status, orbits, trace sides), `certifiedOwnerConflictCensus` and `uncutComponentCensuses` (`SurfaceCutGraph.h:276–283`).
- The test file already formats the whole projected locus: `production_global_topology_plan_error_locus` (`tests:6967`) through `append_cp4c_failure_locus` (`tests:4495`).
- Correction to the independent review: "the plan result exposes none of the already computed ownerEvidence" is wrong. The error carries all of it; only row 979's print left it out.

**W3 — DEFN-161A has no reachable exit (U1, V2).**
- Item 1 needs per-face owner records and partition rows from a live run. A runtime-free definition turn cannot produce them, and the published receipt does not contain them.
- Its fallback ("diagnostic-only Code + Build, then TB") is a Review followed by a Review, and it frames the work as new instrumentation, which is not needed (W2).
- Withdrawn. Its outputs come from CB-179 and TB-EXEC-162, and TB-REV-162 decides.

**W4 — correction of my own TB-REV-160 V8.**
- I said v2 "carries the plan error locus". It hand-picked 11 generic fields, and for this error code all but `sourceFace` are empty.
- It missed the uncut-component evidence that the existing formatter prints in full. That omission produced TB-REV-161's ambiguity and costs one CB/TB cycle.
- Lesson: receipt a stage's error through the pipeline's own locus formatter, never a hand-picked field list.

**W5 — hypotheses and their discriminating CB-179 lines.**

| Hypothesis | Receipt signature | Owner of the repair |
|---|---|---|
| H1: no direct owner | `SphereStagedPlanFaceOwner … status=1 orbits=-`; `unavailable>0` | certificate producer, `directOwners` |
| H2: domain mismatch (certificate counts the face as trace-cut through segment sides; the plan leaves it unlabeled through arc pieces) | `sides≠-` on a face in the plan component; locus partition identity or census-match flags differ | the shared domain rule (`UncutComponentPartitionDomainRule` `NotTraceCut` vs `EmptyFragmentOrbits`), single source |
| H3: two face orbits claim one uncrossed face | `status=2`, two or more orbits, `sides=-`; `multiUncrossed>0` | certificate producer at split wall arcs |
| H4: every owner valid, but one component has two orbits | `violations=0`, locus `uncutFaceComponentSeedState=Multiple` | plan partition barrier set |

Since `sourceFaceCellularity=0`, H4 alone is unlikely unless the summary shows `owners≠sourceFaces`. The four stops split wall arcs mid-segment (`SphereStagedSlidePiece … pieces=2` then `pieces=1` at nodes 12–15), so H2 and H3 near those nodes are the leading candidates. That is a prediction, not a finding.

**W6 — a minor product inaccuracy, recorded and not fixed.**
- `sourceFaceLocusKind` is always `FirstUnlabeledFaceInIterationOrder`, even when `sourceFace` is the component's `invalidFace` (`GlobalTopologyPlan.cpp:1606–1609`).
- Changing it would alter the locus output of other rows. The CB-179 `SphereStagedPlanFaceOwner` line disambiguates instead. Carried to the owner repair CB.

**W7 — design question, deferred to TB-REV-162 with data.**
- The cut search never tries to restore source-face ownership, because acceptance is embedded cellularity only.
- Whether ownership should be a cut-search acceptance predicate depends on H1–H4. Changing it now would alter cut selection on accepted fixtures.

**W8 — all TB-REV-160 obligations carried unchanged:** V3/V4 (rows 648 and 393), V5 (BunnyRandom stop-ON falsifier), V6 (V3b), V10 (row 971 STOP-on-red), V11 (single-source flag), RA-281 F1–F3, W3/W4 and RA-275 S4a.

## Frozen artifact

| Artifact | SHA-256 | Notes |
|---|---|---|
| `Architecture_M6_CP3_CB179_P13_Staged_Plan_Owner_Evidence_Receipt_Exact.diff` | `5069145783b7f57eaeee7b28e895abd9178f8ab4e338568b92c24e93c189d493` (5,346 B) | tests only, +100/−0, inserted after row 979's `SphereStagedPlan` print. Preimage = CB-178 postimage `d8b1413cde9561a00ed17bbe8d2fc34b0833ee82bbdd7dd2a447d25619ae63f3`; postimage `98154a1fdffecf748d52fc3bef1c3923b3e350794a8c367ddafeeaa29ef9665e` (recomputed independently). `git apply --check` OK; `-fsyntax-only` 0 errors, with the same 9 warnings as HEAD (none in the insertion). It prints `SphereStagedPlanLocus` (the existing `production_global_topology_plan_error_locus`), one `SphereStagedOwnerViolation` per owner that breaks a `proves_cellularity()` per-owner rule, `SphereStagedPlanFaceOwner`, `SphereStagedOwnerConflict` rows and a `SphereStagedOwners` summary. |

The TB162 gate manifest is the TB161 manifest, unchanged (`e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a`, 979 rows). Row 979 keeps its name and assertions and gains print lines only.

## TB162 rules (STOP unless all hold)

1. 979/979 PASS; CP2 491/491.
2. Rows 1–978 raw logs equal TB161 artifact `14743677304` under N1–N3, with a zero allowance.
3. Row 979 raw log equals TB161 row 979 under N1–N3 after deleting only lines that start with `SphereStagedPlanLocus`, `SphereStagedOwnerViolation`, `SphereStagedPlanFaceOwner`, `SphereStagedOwnerConflict` or `SphereStagedOwners`. All 41 TB161 receipt lines must reappear verbatim.
4. No census: product source is unchanged (RA-242). Census authority stays TB161 `14741883606`.
5. Publish verbatim every new line plus the 41 old ones. Informational prediction: `violations≥1` or `owners≠sourceFaces`.
6. Any failure means STATUS BLOCKED and a return to Review. Do not edit tests or the manifest.

## Turn sequence

1. CB-179: test-only owner-evidence receipt, compile only.
2. TB-EXEC-162.
3. TB-REV-162: classifies H1–H4 and freezes the exact owner repair CB-180, with an independent positive and negative oracle, at the single writer W1 names.
4. CB-180.
5. TB-EXEC/REV-163: staged plan reaches `built`, or the next measured stage.
6. CB-181: activation (V3/V4/V5/V10/V11).
7. TB-EXEC/REV-164.
8. CB-182: V3b.
9. R1, then RA-275 S4a, then O48.

## Lessons

- When a receipt shows a downstream guard failing, first read the upstream certificate flag the same receipt already printed.
- Receipt a stage's error through the existing pipeline locus formatter.
- Before freezing "diagnostic instrumentation", grep the error struct and the test helpers for fields that already exist.
