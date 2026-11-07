# RA-176 — TB52C-REV audit and A3 atlas exactness (O15) (2026-10-30)

**Turn:** `M6-CP3-PLAN-A3-ATLAS-EXACTNESS` (PLAN, Review track). This record audits [RA-175](Architecture_M6_CP3_TB52C_REV_API_Binary_Census_Independent_Disposition_20261030.md). Native probes are diagnostic only (GMP_COMPILE_POLICY); they are not gate evidence. HEAD `4519ef19e`; `src/`, `include/`, `tests/` and CMake are identical to CB52 source `7cf0857b…`.

## RA-176.1 RA-175 evidence re-verified

- Result `12981972265`: ZIP SHA-256 `bab1be73…` matches, and the internal checksums verify 49/49. The ledger has 22 PASS and 1 RED (row 19, exit 1). `execution-boundary.json` shows 23 planned and 23 executed, with postflight true.
- Gate prefix: the first 831 rows of the TB52 manifest hash to `d6961b59…`, the TB51 manifest. Ledger v2's first 85 rows hash to `6f7eb913…`, ledger v1. The 22 appended API rows equal the census rows minus `apicensus:19`.
- Harness `78b8002c…`: `--self-test` reports 30 cases. `--self-check` of the TB52 manifest (853) with ledger v2 passes, deferred=86. `review_check.py boundary` passes all checks at HEAD.

## RA-176.2 Findings

- **F1 — RA-175's cause for row 19 is false (major).** RA-175 called row 19 a stale witness with an "unproven producer-change cause". No producer changed. The test was added in `6cc83fcc8` (2026-10-21) and was written and run on macOS. Between that commit and CB52, `FieldTransportAtlas.cpp` changed only in `f807c2b89`, which touches the error payload, not acceptance. The fixture files are unchanged since 2026-08-01. The red is caused by platform floating point:
  - A local arm64 build of the identical source passes row 19. The full API binary passes 23/23 there.
  - With default flags, the atlas rejects `mechanical_feature` with `SingularityPortClassCountMismatch` at vertex 35. It finds 4 incidences at vertex 10 and 2 at vertex 35.
  - Rebuilding only `FieldTransportAtlas.cpp` with `-ffp-contract=off` gives 3/3/3/3 at vertices 10/35/47/71. This matches the CI log line for line. The run then stops at `tracing/phase-front/UnsupportedSourceSheetTopology`.
  - So whether the atlas accepts depends on whether the compiler fuses multiply-adds.
- **F2 — the A3 atlas makes topological decisions in floating point at exact ties (O15, major).** This violates DESIGN Amendment 18 and §10.1.
  - `positive_oriented_angle` (`FieldTransportAtlas.cpp:118–124`) uses `std::atan2`. Two decisions are made from these angles with tolerance `kBranchTopologyTolerance = 1e-10` (`:44`):
    - face-gauge selection takes the least angle and rejects near-ties (`:276–296`);
    - corner-sector membership is `angle > sector + 1e-10` (`:517–521`).
  - Exact rational analysis of the stored doubles: at vertices 10 and 35, six face-branch pairs lie exactly on a star edge (determinant exactly 0). The exact half-open rule `[start, end)` gives 3 incidences at each singular vertex; the closed reading gives 6. The exact answer is to accept. Linux gets it right by luck; macOS gets it wrong.
  - Branches lying exactly on an edge are common. Faces with one: plane 24/24, multi_face_seam 32/32, close_sheets 36/36, cylinder 128/128, genus_two 196/244, mechanical_feature 252/300. Torus, sphere_prescribed and thin_bent_tube have none.
  - Eighteen gated rows run `mechanical_feature` through the atlas: 86, 396, 397, 445, 471, 649, 650, 653, 658, 660, 662, 665, 669, 687, 784, 786, 787 and 788. Their green results hold only for x86-64 rounding; row 445 already fails on macOS (RA-170 local run). Linux CI cannot see this defect.
- **F3 — row 935's class stays FIXTURE, for a different reason.** Under exact semantics `mechanical_feature` must pass the atlas, so the test's "atlas rejects at a vertex" expectation is invalid. The new witness must be rejected under the exact rule, so its repair is sequenced after the O15 CB. On the arm64 build without contraction, the other two stops in the test (genus_two at the phase front with a face; sphere_prescribed at the cut graph with a face) still hold. Ledger v2 and the TB52 manifest are unchanged.
- **F4 — RA-175's ORIENTATION §8 lesson was wrong.** It taught readers to rebuild the fixture when a stop moves. It is replaced: a result that differs by platform is a determinism defect, and the exact answer must be computed before classifying.

## RA-176.3 Closure-plan amendment (amends RA-174.3)

- **CP3 exit additionally requires O15:** every A3 atlas decision that is topological must be made by exact predicates on the stored doubles (GMP, or a certified filter that defers to exact), with a recorded deterministic tie rule. The `mechanical_feature` atlas outcome must be identical with `-ffp-contract=on` and `-ffp-contract=off`.
- O15 does not block RP-01; RP-01 is still rows 223/225/261 plus O9.
- O15's owner is `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` (DEFN, Review). It must deliver:
  - an inventory of every float- or tolerance-decided topology choice in A3 (at least `:276–296` and `:517–521`);
  - an exact, probe-verified patch;
  - a red-first witness that fails on Linux CI before the patch: a constructed exact-tie star where non-FMA double evaluation errs, found by searching with the same evaluation order;
  - an exact oracle test asserting 3 incidences at vertices 10/35/47/71 of `mechanical_feature`;
  - an outcome table covering any gate row that changes on Linux.
- The P13 probe DEFN first checks each matrix fixture's atlas decisions against the exact rule, because four of the six fixtures are tie cases on every face.
- Row 283 (legacy NFunctionMesher hash, also red only on macOS) is a likely sibling. It goes to O2 legacy retirement, not to O15.

## RA-176.4 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CP3-TB52-RP01-FULL-GATE-EXEC` | TB-EXEC / I | Unchanged from RA-175: gate `95a7af66…`, ledger v2 `77c1d33b…`, membership 939. |
| then | `M6-CP3-TB52-RP01-FULL-GATE-REV` | TB-REV / R | Independent disposition. |
| R∥ 1 | `M6-CP3-DEFN-RP01-TERMINAL-PATH-WITNESSES` → CB54 → TB53 → TB53-REV | DEFN / R; CB, TB / I | RP-01 closes. |
| R∥ 2 | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` → CB55 (exact predicates + red-first test) → CB56 (row 935 exact witness) → TB54 → TB54-REV | DEFN / R; CB, TB / I | O15 discharged; row 935 moves to the gate (ledger v3, 85). |
| then | P13 probe DEFN (Cylinder first; exact-atlas check first) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs → CP3-REV | per slice | RA-174.3 + RA-176.3. |

**TB52 outcome table:**
- 853/853 PASS, postflight true, `membership=939` → TB52-REV.
- P8 membership error before any native row → `M6-CP3-PLAN-RP01-MEMBERSHIP-STOP` (PLAN, R).
- Any non-PASS → TB52-REV classifies; no retry.
- Dispatcher failure → `M6-CP3-CB53A-RP01-ORCH`, then one retry.

## RA-176.5 Probe provenance

The scratch build was arm64 Release at HEAD with `DIRECTIONAL_BUILD_TESTS=ON` and GMP, built as `ninja -j2 directional_compiled_api_tests`. The probe calls `remesh_from_raw_cross_field` with the test's options. Exact analysis used Python `fractions` on the stored doubles; the scripts are reproducible from this text. No repository source, test, manifest, ledger or workflow changed.
