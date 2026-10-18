# RA-92 — TB13D bisect reviewed: none of the 8 new REDs is a production regression; curved-disk control restored first (2026-10-18)

**Turn:** `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT-REV`. **Inputs:**
- P1 run `39132801755`, result `12138931233` (ZIP `0de1f10c334e6a2a3c1aef8be8b2f87f0b842ccf76426ee7842f260c5b112e03`);
- P4 run `39132921344`, result `12138633102` (ZIP `fba5def74ddbdc87be703d21d62d553888f5b8eb6ac3fd9efeb9903b77d62699`).

**Amends:** RA-91.3 (curved-disk status) and RA-91.4 (U4–U6 hold). **S** = `src/geometry/SurfaceCellTracing.cpp`; **P10** = `tests/SurfaceCellsPhase10Tests.cpp`.

## RA-92.1 Closeout and re-verification

- TB13D dispatched P1–P4 and then stopped with STATUS `IN_PROGRESS` and no report. Review closes it out.
- **P2 (`39132852758`) and P3 (`39132886994`) were cancelled while pending.** The dispatcher's concurrency group (`agent-operation-dispatcher-${ref}`, `cancel-in-progress: false`) holds one pending run, so each later push replaced the queued one. They are not rerun, because RA-92.3 attributes both window cases statically.
- P1 and P4 each verify:
  - `SHA256SUMS` 1019/1019, 497 executed, `orchestration_failure=false`;
  - harness `947a95ee…` with exactly the RA-91.4 inputs.

## RA-92.2 Results

- P1 (+32) 422/497. P4 (CB12) 420/497. CB13A (TB13C) 420/497.
- **P4 equals CB13A on all 497**, so CB13 (U3) changed no outcome on the frozen selector.
- P1 and P4 differ only at 174 and 442. All 25 R3 RED → PASS already pass at P1.
- Predictions held: 242 and all 30 B2/B3 identities are RED at P1 and P4.

## RA-92.3 Attribution: test debt, no production regression

| Sel | First RED | Cause | Class |
|---|---|---|---|
| 235, 236, 294, 299 | by P1 | `c7cb5d68b` (commit 2 after R3) made `make` reject hard features that lack producer-owned rail provenance (now S:8479-8483, which fires first here). `715fe2d66` (commit 3) then requires that, when there are no contacts, the closed chains cover every hard edge (S:8529-8534). `make_curved_disk_fixture` (P10:2438) passes 8 bare boundary edges with no rails, contacts or chains. | Stale fixture after a deliberate contract change |
| 242 | by P1 | `8df105b56` tampers raw transitions that no consumer reads once an atlas is bound (RA-91.3) | Test-specification defect |
| 191 | by P1 | `7ccdcd527` (2026-10-11) routes the test through `build_periodic_route_network_with_source_atlas` (P10:4248-4268). That builder throws when `FieldTransportAtlas::make` fails, and drops the build error. The six siblings, RED at R3, fail at the same throw. | Fixture defect; the atlas error code is unknown |
| 174 | after P1, by P4 | `18357617a` (2026-10-14) adds a source mesh where three faces share edge (0,1) and calls `TriMesh::set_mesh`, which throws the DCEL consistency exception | Test-fixture defect |
| 442 | after P1, by P4 | `b9f70f3fe` (2026-10-13) adds a seam block that has never run. It fails at its first `ASSERT` with `SingularityMismatch` at source edge (2,3). `src/authority` is unchanged between P1 and P4. | An assertion added without ever being run; whether the claim is actually required is undecided |

## RA-92.4 Correction to RA-91.3 (owned)

RA-91.3 called the curved-disk failures a production regression because the test and fixture were unchanged since R3. That inference missed the deliberate contract change: since `c7cb5d68b`/`715fe2d66`, `make` rejects these inputs by design. The class is now *stale fixture*. Confirmation is still pending, because no test prints the typed factory code. CB14A prints it.

## RA-92.5 Consequences

- RA-91.4's hold on U4–U6 is discharged. The factory rejection is explained, and the RP-01 fixtures already supply rail provenance.
- The curved disk is the only selector coverage of `make` accepting a hard-feature product, and U4 changes `make`. Restoring it as a control is a narrow test-only turn that should come before U4.
- The other repairs (174, the 191 family, 242, 442) are test debt. They are scheduled later, and none blocks U4–U6.

## RA-92.6 CB14A specification — `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE` (test-only)

1. **Rails.** In `make_curved_disk_fixture` (P10:2438), after the 8 boundary hard edges are set, build the rails with the producer.
   - Call `pipeline::build_authoritative_surface_cell_rails(TriMesh, AdaptiveFeatureMap)`. The precedent is `OpenHardRailChainProvenanceIsSourceValidated`, REPackage:184-212.
   - Each feature edge carries its actual single incident face from the fixture mesh. Use one closed curve over the 8 edges.
   - Choose the edge class following the REPackage boundary positive in `RailBuildRejectionCarriesFailureWithoutConsumableRails`, and record the choice.
2. **Provenance.** Set `options.authoritativeRails`, `hardRailTerminalContacts`, `hardRailClosedChains` and `hardRailOpenChains` from `pipeline::hard_rail_source_provenance_from_rails(rails, vertexCount)`.
   - Throw if the build is not `Produced`, if the provenance is empty, or if the union of rail edges is not exactly the 8 boundary edges.
   - Hand-built chains, contacts or edge lists are not allowed.
   - The `reverseFaceRows` variant follows the same procedure on its own faces.
3. **Diagnostics.** In 235, 236, 294 and 299, the first `ASSERT_EQ(Produced, …)` message prints:
   - the rejection-reason name;
   - `publishedProductError` and `publishedProductSourceAuthorityDetail`, as integers, when present.

   Use one small helper for this.
4. **Out of scope:** any assertion or production change, other fixtures, selector or harness changes, and running tests. Compile and package with GMP/GMPXX as before. The CB record is 25 lines or fewer.

## RA-92.7 TB14A specification — `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS`

- Run the unchanged census harness `947a95ee…` with `--execute` on the CB14A package. It is one dispatch, and its five inputs come from the CB14A record.
- **Predictions:**
  - 235, 236, 294 and 299 PASS;
  - every other identity keeps its TB13C status, except 199 and 250 (curved-disk users that were RED at R3 and at TB13C), which are observed only.
- **Falsifiers:**
  - any of the four is RED (Review reads the printed code);
  - any other identity changes status.
- **Deliver** a report of 25 lines or fewer: the run and result IDs, ZIP SHA-256, totals per phase, the status of 235/236/294/299/199/250, and every other identity whose status differs from TB13C. Review re-derives the full comparison.

## RA-92.8 Sequence

CB14A → TB14A → TB14A-REV. That Review adjudicates TB14A, then issues DEFN-U6 and sets the U4/U5 order. The test-debt repairs for 174, the 191 family, 242 and 442 are scheduled separately. Each CB follows a reviewed TB. A turn that dispatches several runs waits for each to start before pushing the next.
