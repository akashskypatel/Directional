# M6-CP3-CB39 — A3 source-edge tamper oracle re-home (Code + Build)

- **Authority:** RA-157.3; test-only and compile-only; turn `M6-CP3-CB39-RP01-A3-SOURCE-EDGE-TAMPER-REHOME`.
- **Source:** `c6cc82aa0aa8e5e46dc58cfc887050bf46a65963`; patch base snapshot `0b9f6cdadb0f0ebbf0d06a0000cd7d2a2b265106` (5,895/5,895 file checksums).
- **Changed path:** `tests/SurfaceCellsPhase10Tests.cpp` only, 50 additions/42 deletions.
- **Exact hunks:** `@@ -1623,31 +1623,35 @@` (selector204), `@@ -5053,32 +5057,36 @@` (selector191).
- **Full-index diff-body SHA-256:** `86efc135a93a5d39cb0343794b708f61231173da99c677ab890eadc13ff28853`.
- **Full work-preservation patch SHA-256:** `736651745f27c7a91a85546c11122a59d7a5dbc5ac094daaa66d97efcbe5dc68`.
- **204:** retains untampered A4 `Produced` and nonempty observations; independent all-zero A2 and untampered A3 success, then source-edge -1 mutation and exact A3 `NonReciprocalAdjacency`/edge-key check.
- **191:** periodic all-zero A2 and `balanced_periodic_route_field` untampered A3 success, then identical source-edge -1 tamper and exact A3 failure/edge-key check.
- **Both:** verify tampered key is an interior source edge; preserve fixture, helper, selector, suite and test names; remove unreachable tampered-input A4 negative blocks, no production change.
- **Patch application:** [run 40254231333](https://github.com/akashskypatel/Directional/actions/runs/40254231333), result `12621174333`; exact SHA256 `6d03c68634be86215d191a045444b343d81475d6bb75337a40c1854a0bba5caa`; applied commit `c6cc82aa0aa8e5e46dc58cfc887050bf46a65963`; Drive staging retired by owner.
- **Compile-only:** [run 40254362620](https://github.com/akashskypatel/Directional/actions/runs/40254362620), artifact `12621099926`, ZIP SHA-256 `0d2ad13c768a830d3f7a9954ee50effc72481706b89e1544684fd003f018089b`.
- **Verification:** eight required GMP/GMPXX targets, package integrity hashes and exact source/link evidence; `runtimeExecution=false`, no binary executed. Runtime behavior remains unmeasured.
- **Authority unchanged:** CP2 accepted 491/491; TB38 490/504 candidate; selector497 unpromoted; stable 66/17/49 debt1; RP-01 open.
- **Successor:** `M6-CP3-CB39-RP01-A3-SOURCE-EDGE-TAMPER-REHOME-REV` independently re-checks exact hunks, package, type/error-locus constraints and freezes TB41 191/204 rows. No successor work performed here.
