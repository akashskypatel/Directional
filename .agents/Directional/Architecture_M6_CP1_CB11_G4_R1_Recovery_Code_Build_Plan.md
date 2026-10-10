# `M6-CP1-CB11-G4-R1` — Oracle Recovery Code + Build Plan

> **Review-agent re-scope (RA-24, RA-21d; `M6-CP1-TB11-G4-REV` addendum §L2–§L4) — binding; it OVERRIDES the body where they conflict, including the body's "no production change" rule.**
>
> **Why.** Goal R1-2's synthetic `4 x 4` torus cannot work. The CB11 extractor emits **zero** candidates on any closed quad complex: strips are quad-opposite rung sets (`RemeshPipeline.cpp:6289-6291`), and the path-degree classifier (`:6343-6436`) skips every rung set with two or more rungs.
>
> **Goal R1-0 (production, the only production change authorized).** In `build_surface_quotient_closed_complex_view`:
> - Replace `stripUnite(edgeIndices[0], edgeIndices[2]); stripUnite(edgeIndices[1], edgeIndices[3]);` with the RA-24 edge-loop closure. At each interior valence-4 quotient vertex, unite each incident edge with the unique incident edge that shares no classed quad with it. Do nothing at boundary or valence-≠-4 vertices.
> - Keep the ordinal rule (smallest `SurfaceQuotientEdgeId`).
> - Do not touch `extract_surface_quotient_simplification_candidates`, protection, labels or anything in A5/A6/A7.
>
> **Goal R1-1 (identity 25).** Implement RA-21c **with RA-21d**:
> - require equal undirected chain sets and equal occurrence-node witnesses across Ordinary, non-isolation edges and relations;
> - relax only across HardRail, Periodic and isolation-seam edges.
>
> **Goal R1-2 (identity 28), replaced.** Use the produced torus throughout:
> - reconstruct the edge-loop partition independently and require every `stripOrdinal` to match it;
> - validate every emitted candidate independently;
> - require at least one independently eligible `ClosedLoop`;
> - tamper one edge of it to `hardFeatureProtected=true`; it must become ineligible and absent.
>
> The synthetic torus is optional extra coverage, not a requirement.
>
> **Stop for Review if:**
> - the produced torus yields no eligible candidate under RA-24;
> - any Ordinary non-isolation chain or node disagreement appears;
> - any change beyond R1-0 is needed in production.
>
> Gate unchanged: focused-28 + selector449 = **477**; the focused-28 bytes stay unchanged.

**Owner:** `M6-CP1-CB11-G4-R1`
**Type:** Code + Build, compile/package only.
**Authority:** `Architecture_M6_CP1_TB11_G4_Review_Record.md` RA-21c / RA-23.
**Production semantic source:** retain CB11 A5/A6 behavior unless this plan's stop rule fires.

## Goal R1-1 — replace ordinal25's quotient/arrangement identity conflation

Modify only the focused-test/helper implementation needed by `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus`:

- retain proposal/cell positional preconditions and provenance-chain construction;
- validate every `(proposalId, proposalSide)` chain independently as a degree-2 subdivision;
- derive one arrangement-node witness per A4 corner **occurrence** from the unique intersection of its adjacent side chains;
- map each A6 `SurfaceQuotientSideId` to the exact phase-front edge by `(filledCell, filledSide)` and require the two sides of each closed A6 edge to be reciprocal `oppositeEdge` owners;
- require the exact A5/A6 endpoint relations and relation owner to certify the reversed quotient-class pairing;
- require each side chain's endpoints to equal that side's two occurrence-node witnesses;
- keep chain hard-feature uniformity/equality to `hardFeatureProtected` and typed owner checks;
- delete the invalid requirements that all members of one quotient class map to one arrangement node and that the two incident side chains of an A6 edge have identical edge/end-node sets.

Do not use positions, epsilons, hash equality, `halfedge.proposalId` primary-only identity, or arrangement geometry to infer quotient equality.

## Goal R1-2 — make ordinal28 independently validate strip semantics and test mechanism non-vacuously

Keep the identity name/order unchanged.

### Produced-torus portion

- independently rebuild edge-by-side from `view.edges`;
- independently union opposite edges `(0,2)` and `(1,3)` for every `view.quads` entry;
- canonicalize strips by lexicographically smallest `SurfaceQuotientEdgeId` and deterministic ordinal;
- require every production `edge.stripOrdinal` to equal this independent reconstruction;
- for every emitted production candidate, independently check: one strip, edge existence, two-sided incidence on the closed fixture, no hard-feature protection, no boundary, no quotient-valence singularity, non-empty side cells, and open-path/closed-loop degree;
- do not require the produced torus to emit a CP1 candidate.

### Mechanism-only toroidal view

Add a test-side canonical **4 x 4 periodic quad-grid** `SurfaceQuotientClosedComplexView` helper:

- 16 logical quotient vertices; represent each vertex class by the sorted occurrence IDs of its four incident quad corners;
- 16 classed quads with periodic indexing in both directions;
- every edge has exactly two canonical `SurfaceQuotientSideId`s and reversed class endpoints;
- every vertex has quotient valence four;
- every edge begins `Ordinary`, unprotected, with no hard/periodic owner;
- compute strip ordinals independently from opposite-edge closure, not by calling production candidate extraction.

Require at least one extracted `ClosedLoop` candidate and independently validate it. Clone the view, set exactly one edge of that candidate `hardFeatureProtected=true`, confirm the original candidate is independently ineligible, then require the exact `(type, edge-id set)` candidate to be absent. This is mechanism evidence only and must state it grants no CP3 debt credit.

## Goal R1-3 — freeze unchanged gate authority

- Do not edit `.agents/Directional/Architecture_M6_CP1_Required_Green_Focused_28.txt`; its SHA-256 remains `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`.
- Do not edit selector449 or routing449.
- Do not change production A5/A6 source. If compilation forces a non-semantic test-access/API adjustment, record it explicitly. Any semantic production behavior change is a **STOP -> Review**.
- Compile/package through mandatory reusable GMP/GMPXX workflow only; all eight standard targets must be green; package manifest must be complete; `runtimeExecution=false`.

## Goal R1-4 — successor runtime gate

On compile-green R1, authorize only `M6-CP1-TB11-G4-R1-EXEC`:

- immutable new package;
- focused28 + selector449 = **477** fresh exact-filter processes;
- exact-one selection; zero skips; benchmark 0; complete result self-manifest; immutable postflight;
- no repair/retry after semantic runtime begins;
- mandatory successor `M6-CP1-TB11-G4-R1-REV` for any mechanically valid outcome.

`M6-CP1-CLOSE-REV` remains held.
