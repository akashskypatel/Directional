# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 periodic closure / holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Current runtime authority — artifact 9021175280

Exact artifact **`9021175280`** (`g4-polygonal-boundary-phase-code-build`) is runtime-proven artifact-only:

- implementation `085db9ec23ffaa509b1f5a29e72968229efa103d`;
- cleanup `c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`;
- workflow run/job `31254896323 / 93096734152`;
- ZIP SHA-256 `16191e84bcfcebb2cfc1401b4aae7d5d8de2a02444f189a54d68164c1327a646`;
- internal manifest SHA-256 `a8161eb579e1c06e63b5c7bc6203f610693f3e6259f56d8ce2c6ba78e424d3b5`;
- recursive checksums **48/48**.

Runtime contracts:

- generalized polygonal boundary phase **5/5**;
- source-sheet/isolation semantics **3/3**;
- retained non-torus curved-disk semantics **5/5**;
- sheet coverage **3/3**;
- G4 periodic relations **5/5**;
- retained G0-G3 **17/17**.

Direct three-process baselines remain unchanged:

- plane `730caeae49ec872c`, 64 quads / 81 V;
- seam `5bdf34d7802e9fb0`, 64 quads / 81 V;
- close sheets `89b052762f52a5af`, 200 quads / 242 V / two components;
- cylinder `32135be51d7a0a26`, 288 pure quads / 320 V, one periodic relation `r=0`, `t=(32,0)`, route 32, cut 4, exactly two genuine 32-edge exterior loops;
- zero strict-validation failures and no passing direct fallback/recovery.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Report.md`.

## Polygonal boundary-phase validation decision

The candidate's first-class polygonal representation is runtime-live on structural focused fixtures. The natural six-run/reflex-corner disk constructs the generalized phase/chart and fails only at the deliberately deferred front-pairing invariant; invalid turn, row-order invariance, rectangular fast path, and mixed periodic composition behave as designed.

Exact torus does not reach that authority. Three independent processes deterministically report:

- producer `Rejected`;
- stage `tracing/phase-front`;
- reason **`InvalidBoundedDiskBoundaryTurn`**;
- bounded-disk phase/run/polygon/chart counts all **0**;
- phase hashes empty;
- no output/fallback/recovery;
- canonical periodic authority remains live before rejection.

A changed typed reason without a retained phase record is not planned material progress. No-progress Code + Build count is now **1**.

## Active G4 blocker — topology region versus local isolation sheet

Read-only exact-source reconstruction shows the source classifier's close/opposing-sheet partition can split one source-topological hard-feature region into multiple local isolation labels. On the exact torus, two classifier-local disks reconnect through non-hard exact shared source edges into one annular region with two genuine hard-feature boundaries.

Therefore `sourceFaceSheets` must not serve simultaneously as:

- a geometric/proximity isolation label; and
- a producer-topology exterior-boundary label.

Required contract:

1. introduce first-class source-topological producer regions from exact source adjacency;
2. stop region adjacency at genuine hard/barrier/source-boundary authority, not merely local-sheet label changes;
3. retain local sheet labels for proximity/capture/projection isolation and provenance;
4. treat a valid non-hard exact-adjacent cross-sheet edge as an internal isolation seam when reciprocal field transport proves continuity;
5. keep hard features and true source boundaries authoritative;
6. keep unrelated/disconnected close sheets separate; never join by position/proximity;
7. group producer applicability/topology by topology region and retain each local sheet as provenance;
8. preserve exact-once aggregation and fail typed for malformed/nonreciprocal seam transport.

Do **not** fix the torus by allowing an invalid 180-degree boundary turn, weakening field alignment, demoting features, choosing local-sheet unions by counts/IDs/order/frequency, arbitrary subset search, or synthetic Euler correction.

## Bounded suites

- producer **119/121**: historical sub-millisecond validator-overhead threshold plus strengthened exact-torus advancement failure;
- completion/simplification **154/164**, unchanged historical ten failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **341/353**.

## Next turn

Execute `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Plan.md` as **Code + Build only**.

Prescribed sphere remains deferred until torus reaches direct strict-valid production. G5/G6 and historical completion/simplification repair remain deferred. Review policy remains `never`.

If the next Code + Build also fails to demonstrate material runtime progress in its following validation turn, mandatory design review or bounded producer-replacement proof is required.

Every completed turn ends with a new top-level PR #8 conversation comment after all other repository writes.