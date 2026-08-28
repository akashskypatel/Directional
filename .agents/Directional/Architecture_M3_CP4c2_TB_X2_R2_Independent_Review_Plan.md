# M3-CP4c-2 TB-X2-R2 — Independent Review / Planning Stop

**Turn:** `M3-CP4c-2-TB-X2-R2-REVIEW-PLAN`
**Type:** independent review + planning only
**Incoming:** `M3-CP4c-2-TB-X2-R2` planned control stop
**Runtime authority:** run/job `33215632118 / 98998526420`, result/log artifacts `9703233161 / 9703233545`
**Evidence source/package:** `232ac459b13657529e064272a75c5583770a5963 / 9702321260`
**Gate state:** `selected_r2_branch=NONE`, `selected_gate=NONE`, cumulative runtime not authorized

## Purpose

Re-adjudicate the authority behind the failed Y4 torus control before any diagnostic correction, runtime retry,
Y5 branch selection, or product CB. The review must distinguish a stale frozen theorem from a diagnostic that
constructed a different named witness. It must also audit the prescribed-sphere D1 global Euler terms, because
R2 published every complement component as a disc while its aggregate terms gave `chi=6` against source `2`.

No Directional runtime, compile, package, benchmark, source/test/fixture/selector mutation, or cumulative gate is
permitted in this review.

## Mandatory evidence

1. `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Report.md` — raw R2 result and findings.
2. `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Plan.md` — binding Y1-Y5 stop rules.
3. `Architecture_M3_CP4c2_TB_X2_Plan.md` — frozen Branch A/B/C predicates and sequencing.
4. `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` — especially §2, §3, X1, and the `48/48` theorem authority.
5. `tests/FieldAlignedCurveNetworkTests.cpp` — D1 `cp4c_network_only_fixture`, `rails_from_atlas`, and global
   oracle accounting; compare with the pre-existing production observer.
6. `src/pipeline/RemeshPipeline.cpp` / public pipeline helpers — production feature-map and authoritative-rail
   construction before A2a.
7. `Regression_Root_Cause_Tracker.md` — new R2 candidate plus prior X2 CAND-03/CAND-04.
8. `LESSONS.md` fixture/witness and oracle sections — especially the rule that differently produced objects are
   distinct witnesses until equivalence is proven and every census must name its authority.

## Questions the review must settle

### R1 — Is frozen X1 stale, or did D1 construct the wrong torus witness?

Re-derive the provenance of the 48 mandatory HardFeature rails / 48 structural nodes. Establish whether those
counts belong to the production `authoritativeRails` product and whether D1's `rails_from_atlas` path can be
proved equivalent. Do not accept matching witness names as equivalence.

### R2 — Does D1's global Euler equation use one complex?

For the prescribed sphere, D1 published 18 disc complement components but `18 - 30 + 18 = 6`, not source `2`.
Identify exactly what its `networkV`, `networkE`, and `networkF` count and whether Euler's equation may combine
those three quantities. If source-edge/intersection subdivisions or connectivity corrections are required, name
them mathematically; do not tune counts to the expected answer.

### R3 — What remains valid from R2?

Preserve raw D1 evidence but decide which clauses are admissible after the control failure. D2/Y2/Y3 were not run
and must remain unavailable. `M3-CP4c2-TB-X2-CAND-04` must remain unlocalized unless independent static evidence
legitimately changes its classification without pretending runtime occurred.

### R4 — What correction, if any, is authorized?

If R1 confirms diagnostic witness mismatch and R2 identifies a bounded oracle-count correction, authorize only a
test/diagnostic `M3-CP4c-2-CB2-DIAG-R1`. It must preserve D1's independence from `SurfaceCutGraph`, publish the
rail/count authority explicitly, keep production and frozen selectors unchanged, compile under GMP/GMPXX, and
route to an artifact-only R2 retry. **Do not call that correction CB3**: frozen CB3 is reserved for a Y5 Branch
A/B product correction, and no Y5 branch exists yet.

If X1 itself is stale or the correction requires changing a frozen definition, stop and amend/review definition
authority first. Do not work around the discrepancy.

## Proposed conditional CB2-DIAG-R1 scope — not authoritative until this review accepts it

- `tests/FieldAlignedCurveNetworkTests.cpp` only unless review proves a small test-support owner is required;
- loaded production sphere/torus use the same pre-A2a feature-map/rail authority as production without invoking
  `SurfaceCutGraph`;
- Y1 publishes `railAuthority` and mandatory rail count;
- the independent global cellularity equation uses one explicitly named embedded complex;
- two-ring retains its intended direct-control semantics;
- no production behavior, no selector change, no cumulative runtime, no C2/mechanical/CP4c-3 work;
- Code + Build only, exact GMP/GMPXX compile/package;
- future TB first requires torus `V=48`, `E=48`, source `chi=0`, non-cellular, then may proceed to D2.

## Exit

Publish one verdict:

- **AUTHORIZE `M3-CP4c-2-CB2-DIAG-R1`** with exact bounded measures and future R2 retry criteria; or
- **DEFINITION/ORACLE AUTHORITY RE-ADJUDICATION REQUIRED** with the exact unresolved contradiction.

In either case `selected_r2_branch=NONE`, `selected_gate=NONE`, and cumulative 355/357/358 gate runtime remains
blocked until a valid R2 later completes Y1-Y5.
