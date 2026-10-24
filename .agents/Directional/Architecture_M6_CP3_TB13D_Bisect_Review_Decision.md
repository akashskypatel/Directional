# RA-92 — TB13D bisect reviewed: none of the 8 new REDs is a production regression; curved-disk control restored first (2026-10-18)

**Turn:** `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT-REV`. **Inputs:**
- P1 run `39132801755`, result `12138931233` (ZIP `0de1f10c334e6a2a3c1aef8be8b2f87f0b842ccf76426ee7842f260c5b112e03`);
- P4 run `39132921344`, result `12138633102` (ZIP `fba5def74ddbdc87be703d21d62d553888f5b8eb6ac3fd9efeb9903b77d62699`).

**Amends:** RA-91.3 (curved-disk status) and RA-91.4 (U4–U6 hold). RA-93 (the CB14A review) is appended and amends RA-92.7. **S** = `src/geometry/SurfaceCellTracing.cpp`; **P10** = `tests/SurfaceCellsPhase10Tests.cpp`.

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

*The predictions and the report list are replaced by RA-93.4.*

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

## RA-93 CB14A accepted; TB14A predictions sharpened (2026-10-18)

**Turn:** `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE-REV`. **Input:** CB14A source `2ee499a3403c07be05e8084a669f30c1c735f04a`, package `12140756646` (run `39138385869`). **Amends:** RA-92.7 (predictions only).

- **RA-93.1 Re-verification.** ZIP `eee92aeb…d906`, 28/28, root manifest `495cf0b5…b2d1`, source archive `f414dce2…45a2`, `source-commit` `2ee499a3`. All 351 `src`/`include`/`tests` files are byte-identical to the commit; only P10 differs from CB13A (+78/−7), and ccache missed exactly 1 of 129 calls. Build and preflight 0, GMP, `runtimeExecution=false`.
- **RA-93.2 Code accepted (RA-92.6).** Class `Hard` is right. The boundary positive in `RailBuildRejectionCarriesFailureWithoutConsumableRails` is itself `Hard` with one incident face. Both projections skip non-`HardFeature` rails (`RemeshPipeline.cpp:9707`, `:9732`), so `Boundary` would yield no chains and hit the guard. Statically, the builder emits one closed rail from this loop (explicit closing vertex, one source face per edge, component 0, one kind; `RemeshPipeline.cpp:9456-9545`). The guard is stricter than specified (non-empty closed chains), which is accepted.
- **RA-93.3 Finding — derived fixture (RA-92.6 omission, owned).** `make_curved_disk_with_adjacent_source_sheet` (P10:2670) starts from the changed fixture, erases edge 0–1 from `hardFeatureEdges` and adds faces that make 0–1 interior. It keeps the 8-edge closed rail and chain, so its rail provenance now contradicts its own hard edges. Its census users 237/253/254 call only `build_source_topology_regions`, `source_faces_compatible` and `source_edge_is_authoritative_local_boundary`, and none of them reads a rail field (S:5733-5807, S:9382-9739). No status change is predicted, but they now run the new guards. No test reaches `make` on this fixture. Recorded as fixture debt: the helper must rebuild or clear provenance before any `make` use.
- **RA-93.4 TB14A predictions (replace RA-92.7's; harness, single dispatch, package and deliverables are unchanged):**
  - 235/236/294/299 PASS;
  - 237/253/254 PASS. RED means a base-fixture guard threw (P10:2531/2541/2552), and Review reads the message;
  - 199 stays RED, and its first failure leaves P10:5395, the bounded disk on the same path as 236. It is expected at P10:5428 (the cylinder half; RED at R3 with `A4_INVALID_FINAL_CELL_STATE`). A first failure still at 5395 alongside a 236 PASS is a falsifier;
  - 250 is unchanged: RED at P10:3597 with `PublishedProductRejected`. Its composite builds its own options with the disk boundary as hard edges and no provenance (P10:3580-3593), the same stale-fixture cause. It was RED at R3 for another reason, so it joins the fixture debt;
  - every other identity keeps its TB13C status.

  The report gives status, and the first failure line and reason for each RED, for these 9 identities, plus every other divergence.
- **RA-93.5 Sequence.** TB14A → TB14A-REV. TB14A-REV adjudicates TB14A, issues DEFN-U6 and sets the U4/U5 order. It also schedules the fixture debt: 174, the 191 family, 242, 442, 250 and the adjacent-sheet helper.
