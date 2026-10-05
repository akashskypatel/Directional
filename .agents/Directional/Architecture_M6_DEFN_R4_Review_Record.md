# M6-DEFN-R4-REV — Independent Review of the A7 / Thin-Adapter / `G4-B002` Definition

**Turn:** `M6-DEFN-R4-REV` (runtime-free Review)

**Reviewed:**
- `Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md`
- `Architecture_M6_DEFN_R4_D4_Consumer_Census.md`
- the CB9/CB10/CB11 plans
- the R4 amendment in `Architecture_M6_Frozen_Definitions.md`

**Source authority:** branch HEAD at review start (`e73ea19a`). Its semantic source is byte-identical to the promoted `8e0818b1`, which is also R4's snapshot basis (`c7deb092`).

**Disposition:** **ACCEPTED WITH FOUR BINDING AMENDMENTS (RA-18 – RA-21).**
- `M6-CP1-CB9-A7` is authorized under RA-18.
- CB10 and CB11 stay sequenced and held behind their predecessor Reviews; RA-19 – RA-21 amend them now.
- Accounting stays **60 / 16 / 44**, debt 1.

## 1. What R4 got right (verified)

- **D4 census.** 1,189 exact reference sites (666 production, 523 test/benchmark); a conservative superset, built from a grep. §1.2–§1.3 correctly name the frozen readers that bound A7: focused 7/12, and selector rows 73/86/87/96/97/100/102/103/250/436/437/438/448/449/241.
- **D2 literal-pin claim.** I re-derived it by scanning every required test body (focused-12 + selector449) for each of the adapter's 47 distinct failure literals. Exactly three are pinned:
  - `FalseAuthoritativeSourceBoundary` — row 212;
  - `InvalidHardRailAuthority` — rows 227/230;
  - `InvalidHardRailTransport` — rows 139/140/142.

  R4 §3.4 is accurate.
- **D1 projection and transport guard.**
  - A7 publishes one vertex per A6 class, copies A6 topology, and derives lineage fields class-wide from A5/A6.
  - Selected steps carry `canonicalRelationValue`; RA-17 stays an A7 construction invariant.
  - No new hash field.
  - The representative key `(support, cornerWedgeBindings, OccurrenceId)` is frozen explicitly, as D4 required.
- **D2 partition** (31 / 4 / 19 / 1) and the A7-now / A8-later ownership of the (c) checks are sound.
- **D5 sequencing.** CB9 → TB9 → REV → CB10 → TB10 → REV → CB11 → TB11 → REV → `M6-CP1-CLOSE-REV`. Each gate is the prior focused list plus new identities plus selector449, and focused-12 must stay a byte-exact prefix.

## 2. Findings

### F1 (High, D1) — R4 deletes the only check that united occurrences are the same source point

Code facts:
- Neither the A4 product validator (`SurfacePhaseFrontProduct::make`, `SurfaceCellTracing.cpp:7965-8395`), A5 relation construction (`RemeshPipeline.cpp:3284-4500`), nor A6 compares the positions of relation-paired occurrences.
- The adapter's `QuotientGeometryConsistencyFailure` (`:6118-6127`) is the **only** cross-relation point-coincidence detector in the chain.

D1 §2.2 replaces it with typed support **identity**. But equal `SourceEdgeSupport{a,b}` or `SourceFaceInteriorSupport{f}` only means "on the same simplex". Two members on the same edge at different parameters, or in the same face at different barycentrics, pass D1 and are published as one vertex. An A4/A5 mis-pairing that the current code rejects would become a silent weld of distinct points: a fail-open regression on CP1 exit item 6.

Two more corrections to D1's wording:
- **The support is not tolerance-free.** A5 resolves each occurrence's `SourceSupport` with `SurfacePointSourceSupportResolver`, which snaps barycentrics within `1e-8` (`SurfacePointSupport.h:110-175`). "Exact typed identity" is therefore exact comparison of A5's tolerance-classified values. That is legitimate as A5-owned authority, but A7 must read `occurrence.support` and never re-resolve support from points.
- **Accountability.** The `M6-CP1-TB8-A6-REV` addendum, the R4 plan and RA-17 §3 (review agent) said the float check could survive "only as a non-authoritative diagnostic". They conflated *authority*, which decides, selects or merges, with *fail-closed validation*, which can only reject. §5.3 forbids proximity as a **recovery** mechanism; it does not forbid a reject-only consistency check. R4 followed the plan. The error is the review agent's.

**RA-18** fixes this (frozen definitions).

### F2 (High, D3) — protection labels come from relation kind, so hard edges carried by periodic cuts lose protection

D3 §4.2/§4.3 label a quotient edge `HardRail`, and only those become `touchesHardFeature`. `Periodic` is "not automatically a hard feature".

The named CP1 fixture contradicts this:
- The produced torus (`milestone-g/torus.obj` + `.rawfield`) declares 18 user hard edges, a minor and a major cycle (`SurfaceComplexSimplificationPhase17Tests.cpp:520+`, `make_torus_pipeline_fixture`). They cut the torus into **one** topology region (ORIENTATION witness table; DEFN-R1).
- A5 accepts a HardRail relation only across **different** regions (`RemeshPipeline.cpp:4210`).
- The torus materializes green, so its hard edges are carried by **PeriodicCut** relations (`SurfaceCellTracing.cpp:13858-13868`, `route = cutRoute`), not HardRail ones.

Consequences:
- Under D3, all 18 hard-feature edges would be labeled `Periodic` and left **unprotected** for candidate extraction.
- The arrangement marks them `hardFeature` (`arc.hardFeatureRail`, `RemeshPipeline.cpp:7983`).
- So test 26 fails, or candidate extraction may simplify across hard features, which is the very `G4-B002` property being proved.
- R4's "same 18 HardRails" wording conflates user hard-feature edges with the A5 `HardRail` relation kind.

Related observation, for the R5 / CB11 census: A5 builds its chart-barrier hard-feature set only from HardRail front routes (`RemeshPipeline.cpp:3323-3331`). Hard features carried by PeriodicCut carriers are therefore absent from A5's barrier set, but present in completion's (`hardFeatureRailEdges`). CB11 must not reuse A5's set as protection authority.

**RA-20** fixes the labeling.

### F3 (High, D3) — the CP1 equivalence oracle is not executable as specified

D3 §4.4 keys the vertex bijection "by the sorted occurrence-member set". The comparison side is the retained arrangement `SurfaceCellComplex`, and its nodes carry no A5 `OccurrenceId` members (`SurfaceArrangement.h:319+`). So the key cannot be computed there.

The arrangement is also built from FlowRep arcs: traced arcs plus accepted `network.proposals` boundary paths (`FlowRepStrands.cpp:782+`). Isomorphism with the A6 classed quads is asserted, never shown. Traced arcs can subdivide the proposal cells.

The only available combinatorial key path is:
- halfedge `(proposalId, proposalSide)` → `network.proposals[proposalId]` → A4 `CellId` and side.
- R4 does not establish that this path exists.

**RA-21** fixes the oracle.

### F4 (Medium, D2) — "precedence frozen by stage" misses the order within A5

Today the effective order is: existing A5 checks → adapter (a) checks, in edge-loop order → A6 → mesh checks. Moving 31 (a) checks "into A5" without saying **where** inside A5 can put them ahead of A5's existing relation checks. Those relation checks own the pinned rows 139/140/142 and 227/230.

**RA-19** fixes the placement.

### F5 (Medium, D5) — identity 24 is a source-text test

`M6CP1.ThinAdapterPerformsNoSemanticValidationOrSelection` is specified as a "source-structure" test. A gtest that inspects source text is fragile and has no behavioral content.

**RA-19** replaces it with a behavioral projection identity plus a static Code + Build / Review check.

### F6 (Low) — the census is a grep dump

Declarations are labeled "consumer/read". That is acceptable as a superset, and the decision-bearing analysis lives in record §1.2–§1.5. A future R5 census should separate declarations, producers and readers.

## 3. Amendments (normative; full text in `Architecture_M6_Frozen_Definitions.md`)

| Amendment | What it fixes | Effect on identities |
|---|---|---|
| **RA-18** (F1) | `SourceSupportCertificate` gets typed exact common support, read from A5 `occurrence.support` (authority), **plus** a fail-closed same-simplex point-coincidence validation in dimensionless simplex coordinates. The validation can only reject; it never accepts, merges, selects or chooses the representative. It replaces the `1e-9` position check. | Identity 15 is renamed and widened. |
| **RA-19** (F4, F5) | Moved (a) checks go inside A5, **after** every existing A5 check, keeping their current relative order. | Identity 24 becomes behavioral; the source rule becomes a static CB/Review check. |
| **RA-20** (F2) | A quotient edge gets a separate `hardFeatureProtected` attribute derived from typed source hard-feature authority. The relation-kind label stays. Candidate protection reads `hardFeatureProtected`. | — |
| **RA-21** (F3) | The oracle key path is defined explicitly, with a stop rule. | — |

Gate sizes are unchanged: 469 / 473 / 477.

## 4. Closeout

| Duty | Result |
|---|---|
| Record, census, plans, frozen amendment | Read in full; claims checked against exact source. |
| D2 pinned literals | Independently re-derived: exactly rows 212, 227/230, 139/140/142. |
| D1 | Accepted with RA-18. Fail-open weld gap closed; support-tolerance provenance stated. Review-agent plan error owned. |
| D2 | Accepted with RA-19. Intra-A5 placement rule; identity 24 behavioral. |
| D3 | Accepted with RA-20 (protection from source hard-feature authority) and RA-21 (executable oracle key path, stop rule). |
| D5 | Accepted. Identities 15 and 24 renamed; counts unchanged. |
| Lessons | 189 (reject-only guards vs authority); 190 (a source property cannot be inferred from the relation kind that carries it). |
| Accounting | 60 / 16 / 44, debt 1. |
| Successor | `M6-CP1-CB9-A7` under its plan plus RA-18. |
| Turn boundary | Runtime-free; no generated Directional executable run. |
