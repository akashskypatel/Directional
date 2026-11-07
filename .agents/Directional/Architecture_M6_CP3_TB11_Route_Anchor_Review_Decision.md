# RA-85 — TB11 reviewed: the RED is RP-01, not U1; I–I must be admitted; plan realigned

**Turn:** `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR-REV` (Review + Plan after a red TB, Turn_Cadence rule 4). **Subjects:**
- CB11 source `9432aa05e`, compile artifact `12121016836`;
- TB11 run `39092477302`, result `12123605663`.

**S** = `src/geometry/SurfaceCellTracing.cpp` at HEAD.

## RA-85.1 U1 implemented to specification

- **Helper equivalence:** `open_rail_route_anchor_valid` is a faithful extraction. The old rejection condition `(both && (!fwd && !rev || !pair)) || (!both && !(single0 || single1))` is the exact negation of the helper's result.
- **Same inputs:** the consumer looks up the same rail key (`*first.railId`) and passes the same two endpoint certificates that it pushes and that `make` re-checks.
- **Test evidence:** the truth table passed at runtime.
- **Factory forgery test:** `CheckedFactoryRejectsOpenRailWithClearedTerminalAnchor` was never reached, so it is not evidence either way.

## RA-85.2 The RED predates CB11 — Review error owned

The "control" `ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard` has never been `Produced`:
- The R4 interior-witness TB of 2026-10-15 measured its precondition failing upstream with `no-exact-terminal-corner`.
- The midline fixtures are in the RP-01 RED set (e.g. `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`, R4 endpoint census row 38).

RA-83.4, R10B §5, RA-84 and the CB11 specification all called it an unchanged `Produced` control without citing a run. That premise was false. TB11 is a valid semantic run that measured an already-RED test; **no regression**.

## RA-85.3 New finding: the first failure is now an I–I front

TB11 locus: `open-rail-route-anchor`, rail 2, front 29/147, route length 1, edge 1–4, faces 0|3. Deduction:
- Both endpoint certificates exist, otherwise the locus would be the endpoint.
- Vertex 1 is a contact terminal touching edge 1–4, so neither endpoint is T. Vertex 4 is not a contact.
- The consumer's I branch requires a strict interior point.
- Therefore both ends are I.

In the fixture (3×3 grid, rail 1–4–7, edge 1–4 between faces 0 and 3), iso-lines cross the rail part-way along edges. Middle segments of a subdivided rail are therefore **I–I by construction**. Before CB11 the consumer pushed this front and failed later, at vertex 4. U1 now stops at it first.

**Consequence:** RA-84's matrix row "I–I: reject in both" would keep every subdivided open rail RED even with R admitted. RA-84.5 would have ended at a RED TB14. **RA-84.1's I–I clause and R10B §3's I–I rejection are withdrawn.**

## RA-85.4 Corrected route rule: open-chain interval

The factory's "at least one published terminal" (S:8576-8615, now the helper) was a stand-in for rail membership; the open chain witnesses membership directly. Closed rails already admit local routes without any terminal, by chain contiguity alone (`make`, closed-chain branch). Open rails get the same rule, non-cyclic:
- the route's ordered step edges are a contiguous interval of the named rail's published open chain, in either direction;
- each endpoint passes its own T, R or I predicate;
- a T endpoint is the chain end at its side, and that chain end is the end of the interval.

Effect:
- T–T and T–I fronts that follow the rail are unchanged. The junction check (`hardSpokes == 2`) already confines them to the rail.
- I–I is admitted. T–R, I–R and R–R stay conditional on the RA-84.4 R clauses.
- Shapes that are not a contiguous interval, or that end at a misplaced T, are rejected by both checkers.

Trust root as RA-84.2.

## RA-85.5 Realigned unit order (supersedes RA-84.5)

| Unit | Turn | Scope |
|---|---|---|
| U1 | CB11/TB11 | Done; kept as the single route-rule site. |
| U2 | `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | RA-84.5 U2 scope. No `Produced` open-rail fixture exists, so validation is a pure, directly tested helper, and the positive case uses the real rail builder. |
| U3 | `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` | RA-85.4 in the shared helper, for both checkers. |
| U4 | `M6-CP3-CB14-R10-FACTORY-RAIL-VERTEX-ENDPOINT` | Was U3. |
| U5 | `M6-CP3-CB15-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` | Was U4. |

Each CB is followed by its TB; a red TB goes to Review.

**Falsifiable predictions:**
- **TB12:** the TB11 locus is unchanged (no behaviour change).
- **TB13:** front 29/147 passes, and the first failure moves to a vertex-4 endpoint (`no-exact-terminal-corner`).
- **Falsifier:** 29/147 still fails, or any T–T/T–I truth-table row changes.

Only U2 is authorized.

## RA-85.6 Documentation

- The TB11 tracker section's "rejects retained Produced control" is corrected in place.
- One lesson added to `LESSONS.md` §2.
- TB11 left STATUS `IN_PROGRESS`; this Review closes it.

Accounting unchanged: 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
