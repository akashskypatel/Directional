# RA-91 — TB13C census reviewed: RP-01 owns 30 of the 497; 8 new REDs since R3; retained-package bisect next (2026-10-18)

**Turn:** `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV`. **Input:** TB13C run `39127652521`, result `12136761296` (ZIP SHA-256 `92d9c9bd4d05ac7bf4ef06e402fa0b44fbeeb46d27a0b4c0b1994236632bf545`) on CB13A package `12132184878`. **Amends:** RA-90.4 (B2 rule). **Amended by:** RA-92 (`Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`), covering RA-91.3's curved-disk status and RA-91.4's U4–U6 hold. **S** = `src/geometry/SurfaceCellTracing.cpp`.

## RA-91.1 Closeout and re-verification

- TB13C stopped after its dispatch, leaving STATUS `IN_PROGRESS` with itself as successor and no inventory, report or docs. The run itself had completed. As in RA-89, Review verifies the run and closes the turn out; no implementation work remains.
- The ZIP hash equals the provider digest; `SHA256SUMS` 1019/1019 OK. The harness was `947a95ee…` with exactly the RA-89 inputs. 497 executed, `orchestration_failure=false`, `selection_integrity=true`, package/source/execution-view censuses unchanged, 28/28 after; compile, relink and benchmarks false.
- Totals: focused30 15/30, focused12 10/12, selector449 395/449, cp3entry 0/6 → **420/497 PASS, 77 RED** (R3: 403/497).

## RA-91.2 Classification

- Review built `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv` from the raw logs (77 rows, SHA-256 `8d2b02b7de6b807784bd42921394e86f6d3b274ac07978e4aa4e937c20afa47d`). Every raw-log hash matched the red ledger.
- **Rule correction (owned Review defect).** RA-90.4's B2 rule also matched selector 405, whose fixture publishes no terminal contact (`a3ProbeContactPublished=0`, `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`). There, "not a contact endpoint" is vacuously true. B2 now also requires `a3ProbeContactPublished=1`, and 405 is `other`.
- Counts:
  - B1 0 (falsifier absent);
  - B2 11, all at front 61/179 with decoded vertex 4;
  - B3 19, all at front 17/203;
  - B2+B3 0;
  - other 47.

  The prediction held: `cp3entry` 2 and 6 are B3.
- **RP-01's measured footprint is 30 identities.** All are on rail 2 of the midline-rectangle family, and all were RED at R3 (`A4_ROUTE_CERTIFICATE_REJECTION`). Each blocker is one shape: U4/U5 (B2) can move 11, and U6 (B3) can move 19. The 19 are 9 in focused30, 2 in focused12, `cp3entry` 2 and 6, and 6 in selector449.

## RA-91.3 Against R3

- **25 R3 RED → PASS** are accepted as measured PASS controls. Twenty of them had their test bodies edited after R3. The dominant edit is 21 tests switching from `build_surface_cell_network` to `build_phase10_with_source_atlas`, which binds a source A3. No assertion was removed: every count is equal or one higher.
- **8 R3 PASS → RED** are new and are CANDIDATE / NON-STABLE until attributed:

| Sel | Identity (abridged) | First failure | Test changed since R3? | Status |
|---|---|---|---|---|
| 235, 236 | `CurvedBoundedDisk{IsInvariantToFaceRowEnumeration, PreservesAuthoritativeHardBoundary}` | pipeline `Rejected`, `PublishedProductRejected` | No. The bodies, `make_curved_disk_fixture` and `bind_curved_disk_atlas` are unchanged. | ~~Production regression~~. *Amended by RA-92.4: a stale fixture after the deliberate factory contract change in `c7cb5d68b`/`715fe2d66`.* |
| 294, 299 | `{Duplicate,Foreign}BoundedDiskRegionRejectsAtCheckedFactory` | the same, at the first `ASSERT`, before the post-R3 edits run | Only after the failing line | The same regression |
| 242 | `NonReciprocalSourceAdjacentIsolationSeamFailsClosed` | `Produced`; the test expects `Rejected` | Yes. `8df105b56` (2026-10-12) bound an untampered source A3. | **Test-specification defect** (below) |
| 174 | `RailBuildRejectionCarriesFailureWithoutConsumableRails` | `compute_edge_quantities(): DCEL consistency check failed` | Yes, by about ten compile-only R4 CBs | Unattributed |
| 191 | `MalformedAuthoritativeCrossingProvenanceFailsClosed` | `periodic-route fixture source A3 unavailable`, as for its R3-RED siblings 189/190/192–195 | Yes (R4, 2026-10-11) | Unattributed |
| 442 | `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeature…` | FTA:2856 `seamBuilt` false | Yes, `7e8f7cd93` (2026-10-14) | Unattributed |

- **242 is not a production fail-open.** When an atlas is present, every transport consumer reads transitions only from it:
  - `authoritative_edge_transition_lookup` (S:5389-5397);
  - its call sites at S:11757-11765, S:12310, S:15967 and S:17826.

  The test tampers `crossField.edgeTransitions`, which none of them reads, so the product correctly reflects its authority. The R3 duty, that non-reciprocal transport fails closed, now belongs to A3 construction, and this test no longer measures it. The repair is test-only and waits on attribution.
- **The curved-disk failure is the first real-data run of the checked factory on a hard-feature product, and the factory rejects it.** The typed code is kept in the failure (`publishedProductError`, S:12943-12948), but no test prints it.

## RA-91.4 Why a bisect comes before U4–U6

- U4–U6 widen acceptance. A fixture that U4 brings to `make` would meet the same unexplained factory rejection, which would confound every TB that follows.
- The 68 source commits since R3 were mostly compile-only R4 turns, so a static trace is impractical. Retained compiled packages allow an artifact-only bisect with the unchanged harness.
- Review verified all four packages below:
  - the ZIP hash equals the provider digest;
  - the root manifest checks 28/28, the backend is GMP, `runtimeExecution=false`, and all six binaries are present;
  - all 497 identities exist exactly once in their routed binaries, and the six `cp3entry` identities exist;
  - the four frozen gate files are byte-identical to HEAD;
  - the benchmark fixture is present.

| Pkg | Artifact | Source (src commits since R3) | ZIP SHA-256 | Root manifest SHA-256 | Source archive SHA-256 | Expires |
|---|---|---|---|---|---|---|
| P1 | `11805220540` | `007585f8eac57a74e89e62a416a844e21c15fe35` (+32) | `e564eed3ea3636f1b36262dc91c29e9a65af6c229efc74e58d7935da0c07ddca` | `9da84df9cbae6152aaa06302f8a849a91bf538d29250a2959bc5be1ca63d706e` | `6519c6d4a886d09bdb915de5de0d94b7cf1edc58bfae430c521b9dea2ea19b1d` | **2026-10-20T10:36Z** |
| P2 | `11939982141` | `953f812ff1f431e3ad3af3b68a92284a7831c94a` (+54) | `2d5d1fc3f75b573307cae8af3c837da3dde2302ffdb4fe0ef3dd34d2aafeed7a` | `6c5938b9bc19377041649ce0546b86b2e6c6e2c9d6969fe01639da7baf4af203` | `3d0bf938f0bf2828ef407ceeb092254b003682336c97e83f88867efa2c3c38e9` | 2026-10-22 |
| P3 | `12121016836` (CB11) | `9432aa05ef4719cbea912ae0feb2c5508c4e497a` (+66) | `e92158729bf4cfc13432678e8a05cffba4d922feca6e902d8154a535ab1f2676` | `2c00fd10667fab2ba54c00b358281e892676cfd05186fa60d45b4fc8c75ee488` | `ed45af9cbba9a07a568f7291bb13663aebed5f333574966633fe9deb08abc64b` | 2026-10-25 |
| P4 | `12125223513` (CB12) | `b1b02d5bed43898af0708d76dcd70ada96aeecc9` (+67) | `c98ed3a509e9d1ccc1df83eaeb6112b8636bc0e7ee63b73140d789c32f38eeb6` | `6f90d5ffbdd4e4dbe1f9c5f8b010666e67a59b49abb0eff71020eef4f06782e0` | `3b131c687171ad336fc1dedb390e358ee5ce081da9107f828f54f4e97b1bffb0` | 2026-10-25 |

How the cut points split the 68 commits:
- P1 is the oldest retained package.
- P2 sits after the 2026-10-13/14 R4 fix wave and before `570c51733` (+55). By title, commits +56 to +65 are diagnostics.
- P3/P4 separate CB12 from CB13. CB13A (+68) is TB13C itself.

## RA-91.5 TB13D specification — `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT`

- **Run.** Run the unchanged harness `947a95ee…` with `--execute`, four times: one dispatch per package, in the order P1, P2, P3, P4, each with that package's inputs from RA-91.4. In the dispatch request, keep `operation`, `harness_path` and `harness_sha256`. Set `turn_id` to `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT` and `semantic_source_sha` to that package's source. Change `request_id`, `mailbox_key`, `artifact_prefix`, `executor_sha` and `environment` per dispatch.
- **Failures.** Each package run is independent. A run that fails orchestration is recorded, rule 5 applies to that run only, and the next package still runs.
- **Deliver** a report of 25 lines or fewer. For each package, give:
  - the run ID, result artifact ID and ZIP SHA-256;
  - `orchestration_failure`;
  - totals per phase;
  - PASS or RED for each of the eight RA-91.3 identities.

  No inventory, classification or interpretation: Review builds the attribution matrix.
- **Predictions:**
  - 242 is RED at all four, because `8df105b56` and the atlas routing both precede P1;
  - the 30 B2/B3 identities are RED at all four.

  Falsifier: 242 PASS at any package, which reopens the fail-open question.
- **Out of scope:** compile, any source, test, fixture, selector or harness change, and rerunning CB13A.

## RA-91.6 Sequence

TB13D → TB13D-REV. That Review attributes the eight regressions and specifies narrow repair turns. It then orders U4/U5/U6 using this census (B3 owns 19 and B2 owns 11) and issues DEFN-U6. Each CB follows a reviewed TB.
