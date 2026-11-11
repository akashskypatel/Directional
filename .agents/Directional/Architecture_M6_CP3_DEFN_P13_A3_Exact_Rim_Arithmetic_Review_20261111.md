# RA-226 — Exact rim arithmetic (step 64B.23, obligation O39)

**Turn:** `M6-CP3-DEFN-P13-A3-EXACT-RIM-ARITHMETIC` (Review). **Disposition: COMPLETE.** The rim branch rule is defined as an exact predicate on the stored doubles (§3). It is frozen as two patch-and-gate pairs: CB125 adds the exact rule beside the binary64 rule with a test and a per-fixture agreement receipt, and CB126 makes it the one owner (§5–§8). The transport sign and a vertex-level Changed/Undecided type get a decision and no code (§4). Nothing was built or run.

## 1. What happened after RA-225

- **CB123 was applied as frozen. TB104 closed 942/942.** Its receipt reads `DERIVED_CORNER_RECEIPT axis=0R,7R|1F,2F|3F,4F|5F,6F rim=0F,1F|2F,3F|4F,5F|6F,7F`, which is the value RA-225 §5 predicted.
- **CB124 was applied as frozen. TB105 closed 942/942**, with all 25 receipt lines byte-identical to TB104. The bounded-disk producer and the corner product now read one per-edge rule, `boundary_edge_field_branch`, so the "one owner" precondition of RA-225 D3 is met.
- Product and test sources are unchanged since the CB124 source `acffbffe7f8cb247f9d6118526f37f7d5a7cebad`.

## 2. Findings on the one owner

The rule projects the edge and each axis into the face, normalizes them, takes the largest of four dot products, rejects below `0.7`, and rejects when the best two are within `256 * epsilon * max(1, |best|)`.

- **F1. Its answer depends on things that are not geometry.** The model (§5) gives three cases. An axis with a component added along the face normal has the same in-plane direction, yet the rule answers "undecided" where it answered "branch 0" before. Coordinates scaled by `2^-600` make every squared length underflow, so every edge is undecided. A face with no area has a zero normal, so nothing is projected and the rule still returns a branch.
- **F2. The threshold is a skew guard, not a tie rule.** For two orthogonal in-plane axes the larger of `|cos X|` and `|cos Y|` is at least `cos 45° ≈ 0.7071`, which is above `0.7`. So the threshold can reject only a skewed frame. `cross_field_axes` copies the axes without orthonormalizing them, so skewed frames are possible. For an orthogonal frame the only undecided state is the tie.
- **F3. The tie band is the part one rounding unit can turn.** Two families within `5.7e-14` of each other are a tie, and a tie makes both ends of the edge corners and makes the producer reject the region. Which side of that band a near-diagonal edge falls on depends on how the dot products round.
- **F4. Two other copies of an alignment rule exist and are not readers of the owner.** The ring candidate scoring (`SurfaceCellTracing.cpp:14495–14515`, `score_equal` and `edge_direction_in_face`) has its own binary64 score and tolerance; it belongs to the annulus producer and is an input to 64D. The torus chart oracle in `tests/SurfaceCellTransitionQuotientTests.cpp:1384–1420` is an independent test-side copy; it rejects at exactly `0.7` where the owner accepts. It stays as it is: it is test evidence, and no stored value sits on that boundary.
- **F5. The carry across the fan is not where exactness is owed.** `resolve_branch_transition` takes the quarter-turn from the atlas and then keeps the oriented branch that continues forward, by the sign of a binary64 dot product. The field's matching is the principal matching (`CrossField.cpp:163`). For an orthogonal cross the carried branch is then within 45° of its target, so that dot product is at least `cos 45°`. One rounding unit cannot change its sign.

## 3. Definition (O39)

| Item | Definition |
|---|---|
| E1 Inputs | The stored binary64 values of the face's three vertex rows and of its two axis rows, each read as an exact rational. These are the arrays the atlas reads: `meshWhole.V`, and `crossFieldProduct` through `cross_field_axes`, which copies (`RemeshPipeline.cpp:12827–12829`, `13055–13057`). No derived double (a normal, a tangent, a normalized axis) is an input |
| E2 Construction | `N = (v1 − v0) × (v2 − v0)`, not normalized. The in-plane inner product of two vectors, times `|N|²`, is `g(p, q) = (p·q)(N·N) − (p·N)(q·N)`. For an axis `A` and the edge `E = v_b − v_a`: `cos² = g(A,E)² / (g(A,A) g(E,E))`, with the sign of `g(A,E)` |
| E3 Selection | The four branches have cosines `±cos X` and `±cos Y`. The family with the larger `cos²` wins and the sign of its `g(A,E)` picks the branch: 0 `+X`, 1 `+Y`, 2 `−X`, 3 `−Y` |
| E4 Tie | Equal `cos²` for the two families: undecided. There is no tolerance. A near-tie is decided by the stored values |
| E5 Threshold | The rational 7/10, inclusive: accepted when `100 g(A,E)² ≥ 49 g(A,A) g(E,E)`. The binary64 literal `0.7` is slightly below 7/10; the decimal is the intent |
| E6 Undecided inputs | A non-finite stored value, or `g(E,E) = 0` (a zero edge, a face with no area, or an edge normal to the face). A family with `g(A,A) = 0` has cosine zero and is not a candidate |
| E7 Carry | Unchanged: the atlas quarter-turn, then `resolve_branch_transition`'s forward continuation (§4) |
| E8 Result | `std::optional<int>`: a branch, or nothing when undecided. The corner product stays a sorted list of source vertices (§4) |
| E9 Owner | One function, `surface_cell_tracing_detail::exact_boundary_edge_field_branch`. The producer and the corner product read it. The binary64 rule is deleted at the switch |

The rule needs no square root and no division by a length, so it is a function of the in-plane directions alone: it does not change under any positive scaling of the coordinates or of either axis, under an added normal component of an axis, or under reversal of the face normal.

**What the switch changes.** A near-tie inside the old band is decided. A cosine within rounding of `0.7` is decided by 7/10. A face with no area is undecided. Underflow no longer makes an edge undecided. **Expectation:** none of these occurs on a gate fixture, so every digest and receipt line is unchanged. TB106 measures this on the four census fixtures before the switch, and TB107's full gate checks the rest.

## 4. Two scope items that get a decision and no code

- **Transport sign.** No change. An exact forward test needs the sign of `a + b√r`, because the hinge rotation carries the product of two normal lengths; that is a new primitive for a sign that has a 45° margin (F5). The alternative, reading the atlas quarter-turn with no forward test, is exact but adds a second path beside the test ingress and has no falsifier I can freeze without a runtime: it differs from today only on a matching that is not principal. **Residual, recorded:** for a skewed frame the 45° bound is not proved. The switch definition calls the product with the atlas, and may then replace the carry by the atlas read if a receipt shows a skewed fixture.
- **Vertex-level Changed/Undecided type.** Not added. A3 treats both as stops (RA-225 D4), and no consumer reads the difference. The undecided state is published where it arises, per edge, by E8; the census line `rim-branch … undecided=` reports it per fixture. This withdraws the "typed Changed/Undecided result" wording of RA-225 §9. If the switch definition needs a typed rejection, it adds the type with its reader.

## 5. CB125 — `M6-CP3-CB125-P13-A3-EXACT-RIM-BRANCH-RULE` (compile only)

[Exact patch](Architecture_M6_CP3_CB125_P13_A3_Exact_Rim_Branch_Rule_Exact.diff): SHA-256 `f257368a3c6848af144f730794e840a077204cef0dae979df8275f050d4f2e37`, 251 lines, keep 9 single-space context lines. Numstat: `12 0` `include/directional/geometry/SurfaceCellTracing.h`, `72 3` `src/geometry/SurfaceCellTracing.cpp`, `51 0` `tests/SurfaceCellDesignAcceptanceTests.cpp`, `62 0` `tests/SurfaceCellsPhase10Tests.cpp`. Base: CB124 source.

- **Product source.** Adds `exact_boundary_edge_field_branch` (E1–E6) with `authority::FieldExactRational`. Moves the binary64 `boundary_edge_field_branch` out of its anonymous namespace and declares both in the detail namespace, so a test can compare them. No caller changes: the exact rule is unwired.
- **Test `SurfaceCellAuthorityContractCutover.ExactRimBranchDecidesThresholdAndTiesOnStoredValues`** (row 943). One face, values chosen so that hand arithmetic decides them:

| Case | Inputs | Exact rule | Binary64 rule (model) |
|---|---|---|---|
| Threshold | Edge `(3,4,5)`, X `(1,1,0)`, Y `(29,22,−35)` in the face across the edge: `cos = 7/(√50 √2) = 7/10` | 0 | 0 |
| Threshold, X raised by `2^-600` | In-plane part turns toward the edge | 0 | 0 |
| Threshold, X lowered by `2^-600` | In-plane part turns away | undecided | 0 |
| Reversed edge | | 2 | 2 |
| X plus 7 normals | Same in-plane part | 0 | undecided |
| Coordinates and Y times `2^-600`, X times `2^300` | Same directions | 0 | undecided |
| Tie | Flat face, edge along x, X `(1,1,0)`, Y `(−1,1,0)` | undecided | undecided |
| Tie, Y's second component one unit up | `cos² X > cos² Y` | 0 | undecided |
| Tie, Y's second component one unit down | `cos² Y > cos² X`, along `−Y` | 3 | undecided |
| Y normal to the face | Y is not a candidate | 0 | 0 |
| Collinear face | No area | undecided | 0 |

  The binary64 rule cannot return the asserted values: it gives one answer for the three threshold cases and one for the three tie cases. So the test fails if the new function is the old rule under another name. It also fails if the threshold is exclusive, if a tolerance is added, if an axis is not projected, or if anything is normalized in binary64.
- **Receipt in `SurfaceCellDesignD4RimCensus`** (existing rows 932–935). For every source-boundary edge, in its face's direction, both rules are called. The test prints `rim-branch case=… rimEdges= decided= undecided=` and `rim-branch-agreement case=… same= exactOnly= binary64Only= differ=`. It asserts `rimEdges > 0` and `differ == 0`: where both rules decide, they name the same branch. `exactOnly` and `binary64Only` are measured, not asserted, because they are the two ways the rules may legitimately differ.

**Model.** A Python model with exact fractions reproduces every asserted value. It also compares the two rules on 12,000 random clear cases, including edges that leave the face plane: 12,000 agree. The model's binary64 column uses the same IEEE operations as the C++ rule but is not the build.

Mismatch → `M6-CP3-PLAN-P13-A3-EXACT-RIM-BRANCH-RULE-STOP`. Infrastructure → `M6-CP3-CB125A-P13-A3-EXACT-RIM-BRANCH-RULE-ORCH`.

## 6. TB106 — `M6-CP3-TB106-P13-A3-EXACT-RIM-BRANCH-RULE-FULL-GATE-EXEC`

Manifest `.agents/Directional/gates/Architecture_M6_TB106_P13_A3_Exact_Rim_Branch_Rule_Full_Gate_Case_Manifest.tsv`: 943 rows (the TB105 manifest plus row 943), SHA-256 `938836fc3326df11ccb3d475e0c6a3a4d629d8ac6e252436dcfac47286bfb651`, membership 1024, `SELF_CHECK_PASS cases=943 deferred=81`.

**MATCH** needs all of: 943/943; the 25 receipt lines of TB105 byte-identical; four `rim-branch` and four `rim-branch-agreement` lines recorded verbatim; `exactOnly=0` and `binary64Only=0` on each of the four. **Prediction:** `undecided=0` and `same=rimEdges` on Plane, MultiFaceSeam, CloseSheets and Cylinder, because their corner counts (4, 4, 8, 0) leave no room for an undecided edge, which would make both of its ends corners. A red row, a missing line or a nonzero count → `M6-CP3-TB106-P13-A3-EXACT-RIM-BRANCH-RULE-FULL-GATE-REV`. Infrastructure → `M6-CP3-TB106A-P13-A3-EXACT-RIM-BRANCH-RULE-ORCH`.

## 7. CB126 — `M6-CP3-CB126-P13-A3-EXACT-RIM-BRANCH-OWNER` (compile only)

[Exact patch](Architecture_M6_CP3_CB126_P13_A3_Exact_Rim_Branch_Owner_Exact.diff): SHA-256 `f5526f22d3f04a9c5e0120dd969c8586a79d247b9b5a0d2506f7a3e7b4c9bc25`, 174 lines, keep 5 single-space context lines. Numstat: `2 6` `include/directional/geometry/SurfaceCellTracing.h`, `13 53` `src/geometry/SurfaceCellTracing.cpp`, `1 23` `tests/SurfaceCellDesignAcceptanceTests.cpp`. Base: CB125 applied. It runs only after TB106 MATCH.

The binary64 rule and its declaration are deleted. The producer's one call and the corner product's two calls read `exact_boundary_edge_field_branch`. The census drops the comparison, because the compared function no longer exists, and keeps the `rim-branch` line. This is a production-path change: the bounded-disk producer's side starts now come from the exact rule.

Mismatch → `M6-CP3-PLAN-P13-A3-EXACT-RIM-BRANCH-OWNER-STOP`. Infrastructure → `M6-CP3-CB126A-P13-A3-EXACT-RIM-BRANCH-OWNER-ORCH`.

## 8. TB107 — `M6-CP3-TB107-P13-A3-EXACT-RIM-BRANCH-OWNER-FULL-GATE-EXEC`

Manifest `.agents/Directional/gates/Architecture_M6_TB107_P13_A3_Exact_Rim_Branch_Owner_Full_Gate_Case_Manifest.tsv`: the TB106 manifest byte for byte.

**MATCH** needs all of: 943/943; the 25 earlier receipt lines and the four `rim-branch` lines byte-identical to TB106; no `rim-branch-agreement` line; the three-case production census unchanged (Cylinder PASS, BunnyRandom and Vase registered RED). Otherwise → `M6-CP3-TB107-P13-A3-EXACT-RIM-BRANCH-OWNER-FULL-GATE-REV`. Infrastructure → `M6-CP3-TB107A-P13-A3-EXACT-RIM-BRANCH-OWNER-ORCH`. On MATCH, O39 is discharged and the turn closes with `Successor: M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION`.

## 9. Sequence and obligations

| Step | Turn | Owner |
|---|---|---|
| 64B.23 | `M6-CP3-DEFN-P13-A3-EXACT-RIM-ARITHMETIC`: COMPLETE (this record) | Review |
| 64B.24 | `M6-CP3-CB125-P13-A3-EXACT-RIM-BRANCH-RULE` (§5) | implementation agent |
| 64B.25 | `M6-CP3-TB106-P13-A3-EXACT-RIM-BRANCH-RULE-FULL-GATE-EXEC` (§6) | implementation agent |
| 64B.26 | `M6-CP3-CB126-P13-A3-EXACT-RIM-BRANCH-OWNER` (§7) | implementation agent |
| 64B.27 | `M6-CP3-TB107-P13-A3-EXACT-RIM-BRANCH-OWNER-FULL-GATE-EXEC` (§8) | implementation agent |
| 64D | `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION`; independent, may run alongside; F4 is an input | **Review agent only** |
| later | The O36 switch definition: pipeline wiring of the corner product, O37, the digest plan, a smooth-rim disc receipt, then the D5 and D4 switch CBs | Review, then implementation |

**Gaps, stated.** No test drives the bounded-disk producer through a near-tie; after the switch the evidence that it behaves as before is the unchanged gate. The carry's forward test stays binary64 (§4). The receipt covers four fixtures. The ring scoring keeps its own rule (F4).

**O36 preconditions after this record.**

| Condition | State |
|---|---|
| Mixed stage produces, or hard-feature rails chain (O35) | Met on the rectangular fixture (TB97) |
| Disc corners are stops (O38) | Product, stop set and factory applied; derived witness gated (TB104); pipeline wiring with the switch |
| One owner of the per-edge rule | Met (CB124, TB105) |
| Exact corner rule (O39) | Defined here; CB125 → TB106, CB126 → TB107 |
| Closed rims are cut (O34) | Wherever the field turns; a rim with no field corner and no other stop stays per arc |
| Breakpoints located in one pass (O37) | Open |
| The bounded-disk producer builds plain regions | Met on the two-square fixture (TB99). It rejects an L-shape. A pipeline receipt on a smooth-rim disc is owed by the switch definition |
| Switch TB pre-registers digest changes and amends the named tests | Open; TB98 shows sides going from 8 to 10 (Plane, MultiFaceSeam) and from 10 to 11 (CloseSheets) |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB106's rows 1–942 are the TB105 manifest byte for byte; TB107 equals TB106. Selector497/CP3 is unpromoted |
| Decisive claims re-derived | The owner, its three call sites, `resolve_branch_transition`, the atlas frame construction and the pipeline's inputs were read by me. Every test value was derived by hand and reproduced by the exact-fraction model |
| Runtime-free checks | `-fsyntax-only` returns 0 on `SurfaceCellTracing.cpp`, `SurfaceCellsPhase10Tests.cpp` and `SurfaceCellDesignAcceptanceTests.cpp` in both patch states. CB125 applies at HEAD and CB126 applies after it. Both manifests pass the harness self-check |
| Non-vacuity | §5: the asserted values cannot come from the binary64 rule |
| Obligations carried | 64B.24–64B.27; 64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (narrowed); O35; O36; O37; O38; O39 (defined, in execution); P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB105 942/942, membership 1023; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / DESIGN §7.4 / handoff / TODO | Updated |
| Turn boundary | No product or test source changed in the repository |
