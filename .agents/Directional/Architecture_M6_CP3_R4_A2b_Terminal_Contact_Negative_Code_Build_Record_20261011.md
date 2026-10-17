# R4 A2b missing/foreign terminal contact factory negatives — Code + Build record (2026-10-11)

**Scope:** `72615c7a0bf7ca4d3b9d3729c81eb47842278251`; source-verified snapshot run `38163820844`, event `278b900e30849d1c59b02ad170880a6d3bdf7c6c`, all 6,230 manifest entries verified, no runtime.

## Source/test delta

R4 factory-contact fail-closed regression extends unchanged `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm`: genuine produced A4/atlas baseline first accepted, then removing one typed open-rail terminal contact or substituting source vertex 0 (valid source vertex, no hard-feature incidence) must give `InvalidSourceAuthority`. One existing test source file only; source patch apply `38164373890` -> `48dacf19fecbc36b1f8d58a90ca9763e7dd9cbfe`; the first compile `38164492748` failed on newly authored misuse of `DomainResult<SourceVertexId>` dereference and was corrected with `.value()` in exact semantic source `72615c7a0bf7ca4d3b9d3729c81eb47842278251` by Drive apply `38164686585`. Both transient Google Drive stages owner-deleted; exact patches retained in `/Directional/Evidence/`. No production predicates, selector identities, or workflows changed.

The genuine `nonconstant_hard_rail_fixture` has source vertices 0–8 and hard edges `(1,4)` and `(4,7)`. The negative retains the existing source atlas, routing and closed-rail products, modifying only producer-owned contact authority in copies. It materializes the `hardFeatureEdges` container before taking iterator bounds. The original omit-one-side-step and forged A3 transport negatives remain unchanged. The newly authored `DomainResult` misuse was diagnosed from the exact failed compile log and corrected, with no policy or runtime workaround.

## Compile evidence

Exact eight-target mandatory GMP/GMPXX compile **GREEN**: workflow `38164832322`, job `114545168786`, semantic source `72615c7a0bf7ca4d3b9d3729c81eb47842278251`, preflight/build exit `0/0`, both GMP libraries linked, manifest `28/28` clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11711333843` ZIP SHA-256 `af09d91d99b3e0e3b0c3bac3161fd6e2d4fa9054cbfb7065f8f8de792c7e35c8`, log `11711413607` ZIP SHA-256 `dce3dc30b92f025fa63bb4c221a78c5e9c742a86fa75d50bf0c68f7309b61f54.

## Acceptance boundary and successor

No Directional generated binary, test, benchmark, discovery or frozen 497-case selector was executed. This is compile-only candidate evidence, not runtime acceptance or restoration of any R3 RED/CP2 case. The 39 endpoint, 34 Phase10, 7 DCEL, 88 accepted CP2 losses, six CP3 gates, real multi-carrier/odd-tau and independently reviewed dual-terminal-path obligation remain open. Canonical `M6-CP3-CB1-ENTRY-R4` remains `IN_PROGRESS`, successor `UNKNOWN`; no Test + Benchmark successor is authorized.
