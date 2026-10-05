# M6-CP1-CB12-CLOSE-R2 — WIP continuation

This is a bounded-response continuation record for the incomplete Code + Build turn `M6-CP1-CB12-CLOSE-R2`. It is not acceptance evidence and does not authorize successor work.

## Frozen authority

- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Governing plan: `.agents/Directional/Architecture_M6_CP1_CB12_Close_R2_Oracle_Recovery_Code_Build_Plan.md`
- Normative override: RA-27a review-agent block at the top of that plan.
- Exact source snapshot authority: `272efc96a9d9e0fb809bf8547955846587ac00a3`.
- Snapshot run/artifact: `37275405125 / 11330161215`.
- Snapshot artifact digest: `sha256:dbf443ccb08efb7402b698322c96e0572200a717a1dc799c77dc53e88f70b73c`.
- Snapshot source archive digest: `f121b47ccbd977a2f9aaf67aec4a55d7764081440ade8a4850d081f0dcf71f9a`.
- Reviewed runtime authority remains `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`.
- TB12 candidate `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24` remains unpromoted at 478/479.
- Stable accounting remains 60 / 16 / 44; debt 1.

## Local implementation prepared but not applied remotely

Exactly two paths are changed in the verified work-preservation patch:

1. `src/pipeline/RemeshPipeline.cpp`
   - C4 error name becomes `QuotientClosedComplexStripContinuationMismatch`.
   - The A7 per-occurrence multi-sheet wedge proxy is replaced by the RA-27a exact connectivity rule: build an undirected graph over that occurrence's `cornerWedgeSheets` from its own `cornerWedgeIsolation`, filtering to the occurrence's `topologyRegion` and endpoints in the member sheet set; require the graph to be connected.
   - Failure remains `UncertifiedCrossSheetBinding`, with the new wedge-specific site `cross-sheet:wedge`.
   - The existing selected-forest cross-sheet edge rule and its `cross-sheet` site are unchanged.

2. `tests/SurfaceCellTransitionQuotientTests.cpp`
   - Identity 29 `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition` keeps its name/order.
   - Baseline A5 -> A6 -> A7 must accept.
   - A single bridge occurrence with at least two `cornerWedgeSheets` is selected.
   - Only that occurrence's `cornerWedgeIsolation` endpoints are rewritten to unrelated sheet IDs while the transition list stays non-empty.
   - A5 is republished; A6 is re-produced from the tampered A5; A6 must still succeed.
   - A7 must reject with `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`.
   - No stale A6 is reused and no selected disjoint-sheet A6 relation is constructed.

Static checks completed locally against the exact snapshot originals:
- patch `git apply --check`: PASS
- resulting `git diff --check`: PASS
- touched paths: exactly 2
- diff: +48 / -54
- focused30 SHA-256 unchanged: `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`
- selector449 SHA-256 unchanged: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`
- routing449 receipt SHA-256 unchanged: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`

## Work-preservation patch

- Filename: `Directional__M6-CP1-CB12-CLOSE-R2__base-272efc96a9d__work-preservation.patch`
- Full patch SHA-256: `694f89a68c4a0610d9061764d920db09554748d32d6b32c551a61d9de4133840`
- Diff-body SHA-256: `b95ff29818d60bfe86dcf2a6947e937d2d10f63620b8614d1254657906b490e4`
- Base SHA: `272efc96a9d9e0fb809bf8547955846587ac00a3`
- Intended paths: `src/pipeline/RemeshPipeline.cpp;tests/SurfaceCellTransitionQuotientTests.cpp`
- Google Drive staging file ID: `1Zyk_jYMdU3Q1_0meqw_IKT6XH9o78c_a`
- Google Drive folder: `Directional-CI`
- State: staged externally, **not yet applied to GitHub**.

The exact patch was also emitted as a user-visible chat download before remote orchestration.

## Exact continuation

Resume this same turn. Do not begin `M6-CP1-TB12-CLOSE-R1-EXEC`.

1. Re-read current branch authority and this continuation record.
2. Use the already-staged Drive file above; do not regenerate a semantically equivalent patch unless authority drift makes the exact patch unusable.
3. Apply it through the durable `agent-google-drive-reusable.yml` transport, preserving the exact base/hash/intended-path checks.
4. Verify the pushed code commit and retire the Drive staging file with the owner-authorized Drive connector if workflow-side trash is unavailable.
5. Compile/package the standard eight targets only through `agent-compile-reusable.yml`, with mandatory GMP/GMPXX evidence and `runtimeExecution=false`.
6. Execute no generated Directional binary, test discovery, test, benchmark, CLI, or custom input in this Code + Build turn.
7. If compile/package is green and all RA-27a static/packaging gates hold, close this turn with exact successor `M6-CP1-TB12-CLOSE-R1-EXEC`; otherwise preserve the actual compile/orchestration defect and remain in this turn.
8. Clean temporary caller/marker state workflow-first and retain mailbox history.

## Process note

At this attempt's start, three repository authority files were fetched directly before the mandatory read-mode gate was noticed. The turn then stopped piecemeal inspection, selected snapshot mode, obtained the exact verified snapshot above, and performed all source analysis locally. Treat this as a process/conservation miss only; it did not alter semantic source or runtime evidence.
