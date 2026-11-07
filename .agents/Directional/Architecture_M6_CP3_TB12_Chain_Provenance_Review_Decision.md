# RA-87 — TB12 reviewed: U2 closed; a third RP-01 blocker has no unit; CB13 specified; selector census added

**Turn:** `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV`. **Subjects:** TB12 run `39103358061`, result `12127706461`, on CB12 package `12125223513`. **S** = `src/geometry/SurfaceCellTracing.cpp`, **P10** = `tests/SurfaceCellsPhase10Tests.cpp`, **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`.

## RA-87.1 TB12 adjudicated: every prediction held; U2 is closed

Independently re-verified from the result artifact:
- ZIP SHA-256 `1b6c3babd942cfc7fc7bbeff94774bf719297fdb9bc7ca3c0088e40110f2dfee`; 0 manifest mismatches; 6 executed, 0 missing; postflight passed.
- The harness differs from TB11's only in the RA-86.1 deltas.
- Gates #1 and #2 PASS.
- #3 and #4 are byte-identical to TB11's predicate.
- #5 and #6 carry `firstPredicate=`, and `PublishedProductRejected` occurs 0 times, so the CB12 falsifier is absent.

**Limit:** neither diagnostic reaches `make`, so the CB12 validator still has no runtime coverage on real data. It remains accepted on the construction argument of RA-86.2.

## RA-87.2 New finding: the full-pipeline RP-01 identities stop at an inexact I endpoint (B3)

#5 and #6 (`cp3entry:2` and `:6`) first fail at `endpoint-1`, locus 3 (`EndpointAttachment`), front 17/203, edge 1–4. The first failed condition is `not-same-interior-carrier-point`.
- The two sides are the same point, (1, 0.2) on edge 1–4.
- **Face 0's barycentric pair sums to exactly 1 + 2⁻⁵⁵** (checked with exact rationals); face 3's sums to exactly 1.
- `interior_carrier_parameter` (S:64-89) requires an exact unit sum, so face 0 is rejected before the two parameters are ever compared.

This is the RA-61.6 mechanism. R9B's I clause deliberately left it open: RA-76 measured 324 same-edge parameter pairs that differ by one ULP, and R9B forbids tolerances and requires "a separate independent exact producer-origin witness". RA-63.5 withdrew interval-only identity, because the interval pins the edge and not the point. **No unit in RA-85.5 addresses B3.**

## RA-87.3 Realignment

RP-01 has three blocker shapes:

| Shape | What blocks | Unit |
|---|---|---|
| **B1** | I–I fronts rejected by the anchor | U3 |
| **B2** | R endpoint at an interior rail vertex | U4/U5 |
| **B3** | inexact I parameter | none until now |

RA-85.5's end state, a Review after TB15, cannot close RP-01, because `cp3entry:2/6` stay RED at B3. **U6 is added:** an exact I-endpoint parameter, designed first in a documents-only DEFN. U6 constraints:
- no epsilon, rounding, or canonicalization from near-equality (RA-60.11, R9B);
- the parameter must come from producer-origin exact data;
- the rule must be checked for satisfiability against TB12's actual doubles (RA-61.7).

The frozen selector was last measured at R3, source `d82e34427`, 67 source commits ago. None of its 403 PASSes is a measured control today (LESSONS §2). A census follows TB13, on the same package, to give U4–U6 measured controls and to count how many records each blocker shape owns.

## RA-87.4 CB13 specification — `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` (U3)

1. **Helper.** Add a pure helper `surface_cell_tracing_detail::open_rail_route_interval_valid(steps, firstVertex, lastVertex, chain)`, where `steps` is the ordered `SourceEdgeTopologyKey`s and the endpoint vertices are `optional<SourceVertexId>`.
   - It returns true iff some start `s` and direction `d ∈ {+1, −1}` satisfy all of:
     - `e = s + d·|steps|` lies in `[0, n−1]`, with no wrap-around;
     - every `steps[k] = key(chain[s+d·k], chain[s+d·(k+1)])`;
     - `firstVertex` ⇒ `firstVertex == chain[s]` and `s ∈ {0, n−1}`;
     - `lastVertex` ⇒ `lastVertex == chain[e]` and `e ∈ {0, n−1}`.
   - Empty `steps` or `n < 2` returns false.
   - It replaces `open_rail_route_anchor_valid`, which is deleted along with its declaration.
2. **Factory** (S:8667-8679). For an open rail, look up `hardRailOpenChains`. A missing chain or a false result is `InvalidSourceAuthority`.
3. **Consumer** (S:20308-20315). The same helper runs over `routeSteps`. A missing chain or a false result is `invalid_route(TerminalCarrier, -1, -1, "open-rail-chain-interval")`.
4. **Entry validator** (S:8269). Delete the empty-map exemption, so a non-empty contact set requires an exact chain map. Empty contacts with empty chains stays valid.
5. **Comment.** Correct the factory I-branch comment (S:8764-8765): rail membership is witnessed by the chain interval checked above.
6. **Test plumbing** (RA-86.5.2/.3). Every hand-built input that carries terminal contacts must also carry the real open chains:
   - `build_fixed_plan_rectangular_hard_rail_network` (P10:6412-6440): when `contacts` is given, take the chains from `hard_rail_source_provenance_from_rails` over the same rails;
   - the P10:6394 rebuild, `PhaseFrontDraft`/`phase_front_draft()` (TQ:1775-1862), and every other direct `make` call with non-empty contacts (P10 :2542 :7208 :7247 :7432 :7457 :8999; TQ :350 :1991 :2673 :2783 :3105 :8871 :8973 :9120; `FlowRepStrandsPhase15Tests.cpp:103`) pass the chains from the product accessor or that projection;
   - a negative test may tamper only the input it names.
7. **Tests** (compiled, not run).
   - Replace `OpenRailRouteAnchorTruthTable` with `SurfaceCellAuthorityContractCutover.OpenRailRouteChainIntervalTruthTable` over chain `[1,4,7]`. True rows:
     - `[1-4]`: T1–I, I–T1, and I–I;
     - `[1-4, 4-7]`: T1–T7 and I–I;
     - chain `[1,4]`, step `[1-4]`: T1–T4.

     False rows:
     - `[1-4, 4-7]` with T7–T1;
     - ~~`[4-7, 1-4]`~~ — amended by RA-88.2: this is the valid reverse walk 7→4→1, so it is a true row;
     - `[1-4]` with first T7, and with first T4;
     - `[1-7]`;
     - an empty route.
   - In `OpenHardRailChainProvenanceIsSourceValidated`, the "optional legacy input" expectation flips to false, and an empty/empty case is added and expected true.
8. **Out of scope:** R or I admission (U4–U6); probes; selector, harness or workflow changes; running tests. GMP/GMPXX compile and package as before.

## RA-87.5 TB13 and TB13C

**TB13 (focused).** The harness is derived from TB12's, changing only sha, artifact, digest and identities.

| # | Identity | Role | Prediction |
|---|---|---|---|
| 1 | `OpenRailRouteChainIntervalTruthTable` | gate | PASS |
| 2 | `OpenHardRailChainProvenanceIsSourceValidated` | gate | PASS |
| 3, 4 | the P10 midline tests | diagnostic | RED, and the first failure is no longer front 29/147. Predicted: an endpoint (locus 3) at decoded vertex 4, i.e. B2 (RA-85.5). |
| 5, 6 | `cp3entry:2/6` | diagnostic | `first_failure` byte-identical to TB12's (B3) |

Falsifiers for U3:
- `open-rail-chain-interval` appears anywhere;
- #3 or #4 still names front 29/147.

If the new first failure is B3 rather than B2, U3 still holds and only the U4–U6 order changes.

**TB13C (census) — `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS`.**
- Run the unchanged `m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee…79dd`) on the CB13 package.
- Report the totals and every RED identity's first `predicate=`/`producer failed:` line, sorted into B1/B2/B3/other.
- List every identity that passed at R3 (result `11661044443`) and is RED now, with its first failure.
- No interpretation; the Review interprets.

## RA-87.6 Sequence

CB13 → TB13 → TB13C → Review, which orders U4/U5/U6 → `DEFN` U6 → … Each CB follows a reviewed TB. RA-86's record is folded; its live clauses are carried by RA-87.4.
