# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB13 tested artifact `8860409984` directly without rebuilding. P5 remains open.

- Exact source: `074ec5d125b531db03fcfbda9d6d3654bfc696b7`.
- Digest: `sha256:37c04eaa694a87ed9ab4f48b2123b54f52c0a0d16d8fb9672d367ebdfdbfcee3`.
- Source status empty; checksums **36/36**; fixture closure valid from an arbitrary path.
- Authoritative non-overlapping P5 tests: **301/306 passed**.
- Milestone D: **4/7 passed**; all three failures are invalid fixture preconditions.
- Full packaged disposition: **579/590 passed**, with 8 assertion failures and 3 deterministic signal-11 tests.
- Four random-bunny processes fail before descriptors.
- Wall range: **40.231057–44.680662 s**; all fail the `39.228299 s` gate.
- Maximum peak working set: **185,614,336 B**; below the formal memory cap.
- Next turn: **P5-CB67 through P5-CB74 code changes + compile-only build**.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB13_Rollback_Integrity_Test_Benchmark_Report.md`
4. `.agents/Directional/Milestone_G_P5_Successful_Subdivision_Identity_Code_Build_Plan.md`
5. `benchmark-results/p5-tb13-summary.json`
6. `.agents/Directional/Milestone_G_P5_Rollback_Integrity_Code_Build_Report.md`
7. `.agents/Directional/Milestone_G_P5_Rollback_Integrity_Code_Build_Plan.md`

## Primary production blocker

All four benchmark processes fail identically:

```text
InvalidArrangementDomainIdentity;firstPatch=2;secondPatch=-1
```

This is not the failed-transaction rollback path. Production side repair succeeds:

- infeasible cells `918 -> 0`;
- inserted vertices `8,074`;
- parity odd cells `1,860 -> 0`.

The successful subdivision output then contains an invalid canonical domain before descriptor acceptance. Add typed post-subdivision diagnostics that identify the exact invalid cell, halfedge, node, occurrence, source face, component, sheet, and identity subkind, then correct the producer.

## Other proven blockers

- Exact reusable products still report zero reuse because cache lookup is keyed by allocation-local `descriptor.cellId` before exact dependency equality.
- P5-CB63 removed default post-commit simplification candidate refresh, breaking two valid Phase 17 fixed-point tests.
- Authoritative rail metadata reaches embedded arrangement arcs but not arrangement halfedges.
- The two-interface and cylinder Milestone D fixtures do not construct their intended valid topology and must be corrected before production changes.
- GP26 aggregate, GP27 aggregate, and parameterized GP27 case `/7` all terminate with signal 11. Cases `0–6` and `8` pass. Case `/7` is `bunny_1k_random__surface_cells`.
- The benchmark executable returns a fail-closed JSON result for bunny, while the lifetime-isolation test crashes. Audit public result/context ownership, moved-from storage, debug artifacts, descriptor/product payloads, and result destruction.

## Required next turn

Implement P5-CB67 through P5-CB74 from the successful-subdivision identity plan.

Priorities:

1. Validate and repair the successful side-subdivision domain identity.
2. Add a real permitted failed-side-repair rollback regression; the current new test only covers direct subdivision rollback.
3. Replace `cellId` cache lookup with canonical semantic dependency lookup and exact collision-safe equality.
4. Restore deterministic dependency-bounded simplification fixed-point refresh by default.
5. Correct the invalid Milestone D fixtures and keep fail-fast topology preconditions.
6. Propagate rail identity and exact provenance to arrangement halfedges.
7. Eliminate the three random-bunny result/context lifetime crashes.
8. Preserve compact ownership and memory discipline; compile only the four required targets and run no binary.

Preserve all prohibitions: no final-face deduplication, positional merge, source-triangle pairing, fallback, recovery, validator weakening, arbitrary subset search, or production ID special case.

Workflow files under `.github/workflows` must be changed directly through the GitHub connector, never through a patch-applicator workflow.
