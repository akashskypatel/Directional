# RA-102 — TB16C reviewed: B3 cleared on all 19; RP-01 has one blocker shape (I–R at rail vertex 4); CB17 (U4) specified (2026-10-19)

**Turn:** `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS-REV`. **Inputs:** HEAD `9386a1016`; TB16C [run 39295624822](https://github.com/akashskypatel/Directional/actions/runs/39295624822), result `12207970911` (ZIP SHA-256 `d10553f037a4ae92913db3c07b325636fe221335f79d955258d16b4671874fcb`) on CB16A package `12193816372`; baseline TB14A `12141843937`. **S** = `src/geometry/SurfaceCellTracing.cpp`, **H** = `include/directional/geometry/SurfaceCellTracing.h`, **P** = `src/pipeline/RemeshPipeline.cpp`, **P10** = `tests/SurfaceCellsPhase10Tests.cpp`, **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`. Lines are at `7cfa5b46`; HEAD's `src`, `include` and `tests` are identical.

## RA-102.1 Re-verification

- The ZIP hash matches, and the manifest checks 1019/1019. The dispatch used the unchanged harness `947a95ee…79dd` and exactly the five RA-100.4 inputs.
- 497/497 selected once, 0 skipped: **425 PASS / 72 RED** (focused30 15/30, focused12 10/12, selector449 400/449, cp3entry 0/6).
- Compared with TB14A's `combined-ledger.tsv`, the identities are the same and there are **0 status changes** in either direction.
- Review reclassified every RED from the raw logs: **B2 30, other 42**; B1, B3 and U6 0. This agrees with the agent's TSV (SHA-256 `9ea7c62e…acf`) on 72/72. No log contains `exact-witness-`.
- First failures compared with TB14A, after stripping the CB15/CB16 probe fields:
  - 43 are identical;
  - 19 are the B3 set, which changed by design;
  - 10 differ only by a P10 line number +1, caused by the single `#include <bit>` CB15 added at P10:12.

  Outside the B3 set nothing changed in substance, including selector 405 (`endpoint-0`, contact not published).

## RA-102.2 B3 is cleared; U6 is complete

All 19 RA-95.2 identities left B3 and are now B2. With RA-101.2, U6 is closed: the witness admits every measured I endpoint and rejects nothing that passed before. The factory's I rule still has no real-data coverage; it gains coverage when an open-rail front reaches `make`.

## RA-102.3 RP-01 has one blocker shape: an I–R front ending at rail vertex 4

All 30 B2 records follow one of two templates: 19 at front 97/283 (the former B3 set) and 11 at front 61/179. Both templates are:
- `predicate=endpoint-1`, locus 3, rail 2 (open chain [1,4,7]), on the one-step route [1-4];
- **endpoint 0 is I and passes.** It is the last interior sample on span 3, at p = 4/5 or 3/4.
- **endpoint 1 is vertex 4.** Both sides decode to the exact one-hot vertex 4, in faces (0,1,4) and (4,7,8). Vertex 4 is not a contact terminal (`ContactEndpointMember=0`), so the T branch rejects it (`carrier-orientation`, `no-exact-terminal-corner`).
- **the A3 star of vertex 4 has exactly one usable orientation.**
  - Orientation 0 has both side paths Unique and disjoint. Side 1 stays in (0,1,4); side 2 runs (4,7,8) → (4,5,8) → (1,4,5) over the non-hard edges 4–8 and 4–5.
  - Orientation 1 is Missing on both sides, because it would cross a hard spoke.

**Satisfiability (RA-61.7).** The fixture (TQ:585-640) is a 3×3 grid whose only user hard edges are 1–4 and 4–7, and vertex 4 is interior. Every R clause therefore holds on this data:
- R is strictly interior to the named chain;
- R has exactly two hard spokes, and the carrier 1–4 is one of them;
- R is the far vertex of the one-step interval;
- both sides are exact one-hot at R;
- exactly one orientation has Unique, disjoint paths.

These clauses are R10B §2 with RA-84.4 and RA-85.4. U4 and then U5 are the right next units, in the frozen order (factory first).

## RA-102.4 CB17 specification — `M6-CP3-CB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT` (U4)

The factory admits a typed R endpoint. The consumer emits none until CB18, so no `Produced` result changes.

1. **Field** (H:1495-1513). Append `std::optional<authority::SourceVertexId> railVertex;` as the **last** member of `SurfaceHardRailRouteEndpointCertificate`. Its comment: a strictly interior vertex of this route's published open chain; never a terminal; exclusive with `terminalVertex`. Appending keeps the consumer's positional construction (S:19664-19666) unchanged.
2. **Interval helper** (S:8249-8286; H:1569-1575). Add trailing parameters `firstRailVertex` and `lastRailVertex`, both defaulting to `std::nullopt`.
   - An end carrying both T and R returns false.
   - An R end must equal `vertices[start]` (or `vertices[end]`), and that index must lie strictly between 0 and n−1.
   - Extend the H comment accordingly. Existing callers and rows are unchanged.
3. **R eligibility helper** (new; pure; in `surface_cell_tracing_detail`, declared next to the interval helper). `open_rail_interior_vertex_valid(vertex, chain, hardFeatureEdges)` returns true iff:
   - the vertex occurs exactly once in the chain, at a position 0 < k < n−1; and
   - the hard-feature edges incident to it are exactly its two chain edges (RA-84.4.1).
4. **Factory star incidence** (S:8682-8687). Also seed every strictly interior vertex of every published open chain. The population pass and the evaluator are unchanged.
5. **Factory route check** (S:8764-8775). Pass each endpoint's `railVertex` to the helper.
6. **Factory endpoint branch** (S:8842-8925).
   - Both tags present → `InvalidSourceAuthority`.
   - The vertex is `terminalVertex`, else `railVertex`. With neither, the I branch runs, unchanged.
   - **T only:** the contact-endpoint clause, unchanged.
   - **R only**, all three required:
     - the vertex is not a contact endpoint;
     - `open_rail_interior_vertex_valid` holds against the rail's open chain;
     - the opposite carrier orientation does not also have both sides Unique. Evaluate `unique_terminal_star_path_checked(R, firstAttachment, carrier.secondFace)` and `(R, secondAttachment, carrier.firstFace)`.
   - **Both kinds, unchanged:** the carrier touches the vertex; the attachments are exact one-hot; each side's path is Unique; contact paths validate; the sectors are disjoint.
7. **Closed-rail branch** (S:8926-8932). Also reject `endpoint.railVertex`.
8. **Digest** (P:2123-2124). When `railVertex` is present, hash a distinct tag followed by its index; when absent, hash nothing. Every existing digest is unchanged.
9. **Tests** (compiled, not run).
   - In `OpenRailRouteChainIntervalTruthTable` (P10:7224), add R rows; the existing rows are unchanged. On chain [1,4,7]:
     - **true:** `[1-4]` last R4 (I–R, the measured shape); `[4-7]` first R4 (R–I); `[1-4]` first T1 and last R4 (T–R);
     - **false:**
       - `[1-4]` last R1 (a chain end);
       - `[1-4]` last R7 (not on the step);
       - `[1-4, 4-7]` first R4 (not the outer vertex);
       - `[1-4]` last both T4 and R4.

     On the chain [1,4] (n = 2), `[1-4]` last R4 is **false** (no interior vertex). On a new chain [0,1,4,7], `[1-4]` first R1 and last R4 is **true** (R–R).
   - Add `SurfaceCellAuthorityContractCutover.OpenRailInteriorVertexEligibilityTruthTable`, on chain [1,4,7] with hard edges {1-4, 4-7}:
     - **true:** R4;
     - **false:** R1; R7; R5; R4 with 4-5 added to the hard edges (a third spoke); R4 with only {1-4} hard (a missing spoke); R4 on chain [1,4]; R4 on chain [1,4,7,4] (repeated).
   - **No factory-level R test.** No open-rail fixture reaches `make` (RA-88.3), so a factory negative would fail earlier and be vacuous (RA-84.4.4). The factory R branch gains real-data coverage at TB18, when the consumer emits R on these 30 records.
10. **Out of scope:** consumer R emission (CB18); probes; any T, I or C behaviour; selectors, harnesses and workflow. Compile and package with GMP/GMPXX, as for CB16A. The record is 25 lines or fewer: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.

## RA-102.5 TB17 — `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT`

- **Harness:** the TB16A harness (`20b2ebd8…afea`). Change only sha, artifact, digest and labels, and append identity #13, `SurfaceCellAuthorityContractCutover.OpenRailInteriorVertexEligibilityTruthTable` (a gate), with the matching count.
- **Predictions:**
  - #1–#7 and #13 PASS (#7 now includes the R rows);
  - #8–#12 have `first_failure` byte-identical to TB16A, because the consumer is unchanged.
- **Falsifiers:** any other outcome. Each goes to Review.
- **No census:** CB17 changes no admission that any current fixture reaches. The TB18 census measures U4 and U5 together.

## RA-102.6 Sequence

CB17 → TB17 → TB17-REV (issues the CB18 U5 consumer spec) → CB18 → TB18 (focused run plus census) → TB18-REV → fixture debt (RA-96.6 order) → census → RP-01 Review. Each CB follows a reviewed TB. Accounting is unchanged: 66/17/49, debt 1, census 425/497, selector 497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
