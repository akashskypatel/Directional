# TB-REV-184 adversarial continuation (2026-11-25 UTC)

This continues `M6-CP3-TB-REV-184`, after the [independent review](Architecture_M6_CP3_TB_REV_184_Slide_Entry_Pre_Staging_Independent_Review_20261125.md).

- **Method:** runtime-free. Source reading, plus Haiku read-only work:
  - a syntax-only check of CB-205 in a throwaway `CLAUDE_` worktree, since removed;
  - extraction of the helper and API facts CB-205 relies on;
  - a census of every gated test that builds a field-aligned network, by fixture and recipe.
- **Product and test bytes:** unchanged.

## Verdict

- **Upheld:** TB184 1005/1005, and CB-205 exactly as frozen.
  - Diff `d39216d2…f777f`; preimage `d4543d08…95c5` equals HEAD; `git apply --check` passes.
- **Corrected:** the reach population. Activation changes far more gated rows than the 14 readers that TB-REV-183 S4 classified (U2).
- **Reframed:** the digest receipt diagnoses which rows changed. Only the full gate decides acceptance (U3).
- **Unchanged:** no extra receipt turn is added.

## Findings

**U1 — CB-205 is sound and syntax-clean.**
- **Syntax check, which the independent review did not claim:**
  - Patched postimage `03abb0a6…d72d` matches.
  - `clang++ -std=c++20 -fsyntax-only -Wall -Wextra -include iterator`: HEAD has 0 errors and 45 warnings; patched has the same, 0 errors and 45 warnings.
  - No diagnostics at or after line 23887, and no new warnings. This is not compile evidence.
- **Facts verified against source:**
  - **Signatures and types:** every signature and field type used matches.
    - `make` and `diagnose_with_arrival_priority` both return `FieldAlignedCurveNetworkBuildResult` (`SurfaceCellTracing.h:605,625–630`).
    - `semantic_digest()` is a `std::uint64_t`.
    - `network_error_locus` is visible at the end of the file.
  - **Census helper:** `for_each_cp4c_census_witness` yields exactly four witnesses, so the receipt count is 3 + 2 + 4 + 4 = 13.
- **The sphere `EXPECT_EQ(4U, …)` is not a guess.**
  - The lambda is row 978's own `slideStops` predicate (`tests:18000–18007`).
  - Row 978 uses the same recipe (`observe_cp4c_witness`, sphere, `:17906`).
  - TB160 published `slideStops=4`.
- **The published-network binding is a real falsifier only for the pipeline recipes:**
  - `build_cp4c_pipeline_products_fixture` copies the pipeline's own snapshot (`RemeshPipeline.cpp:12919–12933`), built from the same rails, source and atlas.
  - For `observe`, the published network comes from the same `make` call on the same stored inputs (`tests:7484`). That equality is a tautology: harmless, but not evidence.
- **Runtime exposure:**
  - `produced_network()` returns at the first eligible fixture (`FieldAlignedNetworkPolylinesTests.cpp:52–99`).
  - Row 1006 runs all four production-default pipelines.
  - genus_two, close_sheets and cylinder do run in other gated rows, but under other recipes.
  - TB185 must record row 1006's elapsed time. A timeout is a TB stop, not a reason to weaken the test.

**U2 — Correction: activation reaches about 239 gated tests, not 14 readers.**
- **Census:** about 239 of the 1,000 distinct gated test names build a network through some path:
  - `make`, the observe, pipeline-products or census helpers, `produced_network`;
  - or a SurfaceCells remesh.
- **Rows per fixture family:**

  | Family | Gated rows | Coverage in CB-205's 13 recipes |
  |---|---|---|
  | sphere_prescribed | 32 | 4 recipes |
  | torus | about 50 | 3 recipes |
  | two-ring | about 40 | census recipe only |
  | mechanical_feature | about 25 | observe recipe only |
  | four-triangle-fan | 14 | census recipe |
  | genus_two | 6 | polyline recipe |
  | close_sheets | 4 | polyline recipe |
  | cylinder | 5 | polyline recipe |
  | plane, multi_face_seam | 9 | not measured |
  | synthetic builders | about 86 | not measured |

  The synthetic builders are `hard_rail_fixture`, `build_rectangular_hard_rail_phase_front`, `make_topology_fixture`, `make_square_topology_fixture`, `build_network` and `build_cp4c_trace_crossed_cut_fixture`.
- **Hard-rail fixtures carry rails, so slide entries are possible on them.** "Flat, therefore unchanged" is not proven.
- **Readers missing from S4:** the census also found sphere readers that S4 never listed:
  - 380, 388, 691, 698, 699, 700 (observe);
  - 688, 689, 695, 702 (census).

  They read recipes CB-205 does measure, so TB-REV-185 classifies them from the same receipts.
- **Correction to my own records:** TB-REV-182 R5 and TB-REV-183 S4 described a census of *sphere readers* as the activation's reach. That was wrong.
- **Status of the census itself:** it is static and approximate (a name-propagation scan). Counts are ±; rows are not individually verified.

**U3 — Reframing: digest equality is diagnostic, not acceptance.**
- A gated row that passes after activation is accepted on its own assertions, whether or not its network changed.
- The receipt's only job is to explain REDs and avoid a gate rejection whose causes cannot be told apart.
- A second receipt round over the remaining ~200 rows would cost a full CB, TB and Review cycle, and measure nothing the activation gate does not measure itself.
- **Decision:**
  - Keep CB-205 as frozen.
  - Do not add a CB-205B.
  - In TB-EXEC-186, every row on an unmeasured family runs STOP-on-RED against TB185, with full raw comparison.
  - Any RED is classified in TB-REV-186 from its own log. Each correction family then gets its own exact CB.
- **What TB-REV-185 must not claim:** "reach closed", or SAFE for any row whose fixture or recipe is outside the 13.

**U4 — Row 1006 after activation (an obligation on CB-206).**
- After the signature flip, `make` is the staged network. Every `production` versus `staged` column becomes identical, and `productionStagedDigestEqual` turns from 0 to 1 on the sphere.
- The only part still informative is the explicit-`false` sphere control (`EXPECT_NE`, 4 stops).
- CB-206 must freeze row 1006's exact transcript change, so the 1006 row log is an authorized difference, not a STOP.
  - If the row is reduced to the explicit control, CB-206 must state that and give the reason.
- Together with the `productionCut=` label in row 979, this is the second label CB-206 must adjudicate.

**U5 — Carried.**
- TB-REV-183 S1–S3 and S5 are carried. S4 is amended by U2 and U3.
- R1, R3, R4, R6, V5, V10 and V11 are carried.
- P1, D-U, J6, E5 and CB-190 are held.
- No CP3/497/D0/H4 promotion.

## Turn sequence (supersedes TB-REV-183 adversarial steps 3–5)

1. **`M6-CP3-CB-205-P13-SLIDE-ENTRY-ACTIVATION-REACH`:** exact; compile only.
2. **`M6-CP3-TB-EXEC-185`:**
   - 1006/1006, with the first 1005 rows N1–N3-equal to TB184.
   - Row 1006 has all 13 keys, and its elapsed time is recorded.
3. **`M6-CP3-TB-REV-185`:**
   - Classify the 13 recipes, and the readers on them (the S4 list plus the U2 additions).
   - Mark every other fixture family UNMEASURED.
   - Freeze **CB-206**:
     - the signature-default flip at `SurfaceCellTracing.cpp:5336`;
     - exact rows 648, 978 and 979;
     - the row 979 label and the row 1006 transcript (U4).
4. **CB-206 → `TB-EXEC-186`:**
   - V5 BunnyRandom.
   - Full raw comparison against TB185, STOP-on-RED.
   - A RED that comes only from activation is data, not a reason to roll back.
5. **`TB-REV-186`:**
   - Classify each RED or material difference by fixture family.
   - Freeze one exact correction CB for each family, in separate turns.
6. **Then, one turn each:** parameter deletion, V3b, R1, O48. CB-190 stays off the critical path.

## Lessons

- A census of the readers of one fixture is not the reach of a default flip. Census every gated path that calls the changed constructor, by fixture and recipe, before claiming reach.
- An equality between a "published" network and a reconstruction is evidence only if they are built along different paths. Rebuilding with the same call on the same inputs proves nothing.
- Use a receipt to explain a gate, not to replace one. Stop adding receipt rounds once the next gate would measure the same thing.
