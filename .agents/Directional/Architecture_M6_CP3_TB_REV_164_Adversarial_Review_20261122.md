# TB-REV-164 — adversarial continuation after handover (2026-11-22 UTC)

Continues `M6-CP3-TB-REV-164-P13-THIRD-EDGE-SIDE-OWNER-CENSUS-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_164_Third_Edge_Side_Owner_Census_Independent_Review_20261122.md). Runtime-free: source reading, the [TB164 raw receipt](evidence/Architecture_M6_CP3_TB164_P13_Third_Edge_Side_Owner_Census_Raw_20261122.txt), the TB162/TB163 receipts, Haiku read-only audits, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **TB164 PASS and the independent adjudication of Y1–Y5 are upheld.** All 16 measured lines match the Y3 oracle (`nearest=6` on component 1, `nearest=12` on component 5).
- **The frozen successor is withdrawn and replaced.** It was a prose contract ("may connect the helper to the site-C seed"). That breaks the standing rule that the implementation agent gets exact diffs only, and read against the source it permits two wrong seeds (Z2, Z3). It is replaced by two exact compile-only CBs:
  - CB-183, a pure seed-decision helper with tests;
  - CB-184, stacked wiring of that helper into the seed, plus a row-979 witness print.
- One TB covers both.

## Findings

**Z1 — prose successor withdrawn.**
- The independent review's CB-183 lists outcomes and falsifiers, but no code.
- It leaves open which keys may seed, whether uncertified chords count, and how the rule is tested off-fixture. Hand-built networks cannot reach the wired path (RA-248), so the decision has to live in a pure, tested helper.

**Z2 — my CB-182 collection drops uncertified chords (correction of my own work).**
- In CB-182, site C pushed a chord candidate only when its third-edge orbit was certified.
- `third_edge_side_owner` then never sees an uncertified outermost chord (an exterior boundary orbit on a disc), and returns the next inner chord as a unique owner. Wiring that, as the prose contract allowed, would seed a wrong orbit.
- No harm has occurred yet: the field is census-only, and the sphere has no exterior orbit.
- CB-184 collects every chord. CB-183 seeds only when the selected orbit is among the recorded edge-side orbits, and `add_owner` records only certified orbits.

**Z3 — keys with other writers must not be decided by the chord order. This turns Y7 into an exclusion now, not just a carried obligation.**
- Site D (`SurfaceCutGraph.cpp:658–681` at HEAD) writes the two edges at its entry vertex.
- A vertex-to-opposite-edge segment can lie nearer such an edge than every site-C chord. Example in triangle (v0, v1, v2) with c = 0:
  - The D segment runs from v0 to a point p on edge 1.
  - A non-crossing C chord with third edge 0 must meet edge 1 between p and v2. It therefore sits beyond the D segment, as seen from edge 0.
  - The nearest-chord rule would then pick a chord that does not border edge 0.
- Site C also records nothing for:
  - turn-backs (incoming carrier = outgoing carrier);
  - local-index failures;
  - segments with no incoming carrier that do not enter at a vertex.
- So CB-184 marks a trace-crossed face *unordered* whenever any segment in it is not a site-C chord, and CB-183 refuses to seed across that face's edges.
- This is conservative (it may leave an edge unseeded) and exact (it never guesses).
- Terminal slits whose two sides lie in one orbit stay excluded, as today: they sit inside one region.

**Z4 — scope of the switch, read from source (corrects the scope part of my Y6).**
- (a) **The cut search is unaffected.** `canonical_candidate` (`:1052`) accepts a candidate on `proves_embedded_cellularity()` (`:1120`), which reads no owner (`:1161–1171`).
  - Ownership only fills the certificate. Its sole error return is an uncertified orbit, which `add_owner` makes unreachable.
  - So production cut outcomes, including row 979's `ASSERT_FALSE(productionCut)` at `tests:17808`, cannot change.
- (b) **`GlobalTopologyPlan` reads the owners** (`GlobalTopologyPlan.cpp:1561–1608`). Plan outcomes and owner prints can change for any fixture whose uncut component is Unavailable today and becomes decided.
- (c) **Premise rows, from the Haiku audit:**
  - Row 662 (`tests:13857`) requires no failure; every ownership status passes.
  - Row 788 (`:19399`) requires only that a component-0 census exists. The partition is unchanged, so that holds.
  - Row 979 asserts the production cut failure, staged embedded cellularity and χ2, and no plan outcome.
  - `CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures` is DEFERRED and RED. The independent review was right that it is not a premise row; my Y6 listing was wrong.
- (d) **The new branch fires only when the face-owner and singleton edge-side branches gave no seed.** Adding a seed never removes an owner. Possible per-component changes are Unavailable → Established, Unavailable → Conflicting, and Established → Conflicting (the last two are falsifiers).

**Z5 — residual, recorded and not fixed: the existing singleton `EdgeSideOwner` branch has the Z2 hazard.**
- That branch fires when exactly one certified orbit was recorded, even if an uncertified outer chord exists.
- It is left unchanged: there is no observed instance, and it is outside this switch.
- TB-REV-165 checks it with the census fields (`thirdEdgeChordOrbits` now includes uncertified chords).

**Z6 — an interpretation risk stays open.**
- Components 1 and 5 contain the 8-face stars around source vertices 12 and 37 (the TB162 violation faces).
- Seeding them puts those vertices inside cells 6 and 12. If either vertex is a field singularity, the real defect is a missing separatrix upstream, and the owner repair would only move the failure.
- No published evidence decides this.
- TB-REV-165 reads the next plan outcome for that signature. Any singularity, index or valence failure at these faces reopens Z6 before activation.

All TB-REV-163 Y1–Y7 obligations are carried; Y7 is narrowed by Z3. Also carried: TB-REV-162 X1–X6 (X4/H5 is an open lead), TB-REV-161 W6–W8, TB-REV-160 V3–V11, RA-281 F1–F3, RA-275 S4a, Amendment 14, O47/C5/O48/O49 and sphere χ+4.

## Frozen artifacts

| Artifact | SHA-256 | Content |
|---|---|---|
| `Architecture_M6_CP3_CB183_P13_Nearest_Chord_Seed_Decision_Helper_Exact.diff` | `5230d0973376639ff49ff844f198314a0294729000695101682a3174303377b9` | 5,000 B, +77/−0. Adds `nearest_chord_edge_side_seed(recorded, chords, unorderedFace)` to `src/geometry/ThirdEdgeSideOwner.h` (unwired) and two tests. The tests fail if the helper ignores the unordered flag, accepts an unrecorded outermost orbit, guesses on a tie, crossing or missing placement, or returns the smallest recorded orbit. Postimages: test `0a752b82ad20c836c0109a477bcac624c2f7259c51537e8b59d0cdd3556d9592` (from `f70a9f8c…383c`); header `2887ed0c80610ab20835a7f0cdc22c182fb840bdbf25dc92353d195738ae6265` (from `7a055f24…2efb02`). |
| `Architecture_M6_CP3_CB184_P13_Nearest_Chord_Seed_Switch_Exact.diff` | `fe9576d84e79d125712b847cd345bfe4308ba26a0c88b9ff48e9291c1a6f758a` | 9,696 B, +71/−29, stacked on CB-183. Contents: enum `NearestThirdEdgeChord = 2` with its printer case; census field `oppositeFaceHasUnorderedSegment`; `unorderedSegmentFaces` marked at site C's turn-back exit and at every segment without an incoming carrier; chords collected regardless of certification; and a third seed branch that runs after the face-owner and singleton edge-side branches. Row 979 adds ` unordered=` to `SphereStagedUncutSideOwner` and prints one `SphereStagedNearestChordSeed` line per seed from the new rule. Postimages: test `fea486ed3e01e795945b62cb9e04b27a8fb8ebae4814577c62b0c3b377a68e27`; `SurfaceCutGraph.cpp` `e387a0592f842d68e8f6f6514b4b3c4ec410775131c1e67ad850a09c22f39d2e` (from `1fb1ae21…f1a5`); `SurfaceCutGraph.h` `ce13e2a69ef289bda3fea9d5c8bdfe100046d3045c2d3ff1ab2b85e2283008bf` (from `07ceeb17…c927`). |
| `gates/Architecture_M6_TB165_P13_Nearest_Chord_Seed_Full_Gate_Case_Manifest.tsv` | `8d56ee1d911daa1bd3cab9f824e79131ce9f75bd7a57b31b5882d3f4f52b1e69` | 984 rows. Rows 1–982 are byte-equal to TB164 `ed615c22…517b`; rows 983–984 are the CB-183 tests. Expected membership: 1065 = 984 gated + 81 deferred. Census manifest unchanged. |

Checks (Haiku, worktree at `e7c046d30`): all four preimages match. `git apply --check` passes for CB-183 and then for CB-184, and every postimage hash above was recomputed. `-fsyntax-only` (clang, C++20, `-Wall -Wextra`, GMP defines) gives 0 errors in `SurfaceCutGraph.cpp` and in the test TU at each of the three states, with warning sets (27 and 42) identical to HEAD. Nothing was built or run.

## TB165 rules (STOP unless all hold)

1. **Pass counts:** 984/984 PASS, and CP2 491/491.
2. **Rows 1–978 and 980–982** must equal TB164 artifact `14757020531` under N1–N3. The only allowance is lines in rows 662 and 788 (mechanical owner and seed publications), and the report must list each differing line verbatim. A difference in any other row, or in any other line, means STOP.
3. **Row 979**, compared with TB164 row 979 under N1–N3. Predicted:
   - **removed:** the 16 `SphereStagedOwnerViolation` lines, the 2 `SphereStagedUncutCensus` lines, 16 `SphereStagedUncutBoundary` lines and 16 `SphereStagedUncutSideOwner` lines;
   - **added:** 16 `SphereStagedNearestChordSeed` lines;
     - component 1: edges 2-5, 2-10, 5-7, 7-13, 10-15, 13-18, 15-17 and 17-18, each with `orbit=6 status=2`;
     - component 5: edges 27-29, 27-36, 29-31, 31-38, 36-41, 38-43, 41-42 and 42-43, each with `orbit=12 status=2`;
   - **changed** `SphereStagedOwners` line: `established=192 unavailable=0 noOrbit=0 violations=0`;
   - **changed** `SphereStagedCutGraph` line: `sourceFaceCellularity=1`;
   - **measured, not predicted:** the `SphereStagedPlan`, `SphereStagedPlanLocus` and `SphereStagedPlanFaceOwner` lines (publish them verbatim);
   - **unchanged:** every arc, trace and slide line.
4. **Census:** 3/3 equal TB164 census `14757007212` under N1–N4 with zero allowance (Cylinder PASS; BunnyRandom and Vase RED with the same first failure). Any difference means STOP, and the report publishes the first-failure fields.
5. Any failure means STATUS BLOCKED and a return to Review. Do not edit tests, manifests or predictions.

## TB-REV-165 decision map

| Signature | Decision |
|---|---|
| Rule 3 holds and the plan reaches a new stage | Read that stage against Z6. With no singularity signature at the vertex 12/37 stars, freeze the activation CB (V3/V4/V5/V10/V11). Recheck Z5. |
| Some edge of components 1/5 is not seeded, with `unordered=1` | Z3 was too conservative there. Freeze a receipt that names the unordered segment's kind; no relaxation without it. |
| Any `orbit` ≠ 6/12, `status=3`, or a component changing on another fixture | The rule is falsified: typed STOP; reopen X4/H5 and Z2/Z3 with that edge. |

## Turn sequence

1. CB-183: pure seed-decision helper and 2 tests (compile only).
2. CB-184: seed switch and row-979 witness, stacked (compile only).
3. TB-EXEC-165: 984 rows plus the 3-case census.
4. TB-REV-165: decision map above.
5. CB-185: activation (V3/V4/V5/V10/V11), frozen by TB-REV-165.
6. TB-EXEC/REV-166.
7. CB-186: V3b.
8. R1, then RA-275 S4a, then O48.

## Lessons

- A seed rule that reads one writer's record must exclude keys that another writer can reach, or prove that the two cannot nest.
- A certification filter applied before a geometric selection changes what the selection sees. Select over all of the geometry, then require the result to be certified.
- Before scoping an owner switch, check whether the producer's search predicate reads owners. Here it does not, so only the plan consumer moves.
