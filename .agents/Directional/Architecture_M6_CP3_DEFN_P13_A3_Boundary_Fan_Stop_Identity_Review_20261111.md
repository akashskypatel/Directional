# RA-225 — Boundary fan stop identity (step 64B.18)

**Turn:** `M6-CP3-DEFN-P13-A3-BOUNDARY-FAN-STOP-IDENTITY` (Review). **Disposition: COMPLETE.** A corner stop needs no face-fan identity: the source vertex is a sufficient key (§3). The 16-row plan of the [audit-revision review](Architecture_M6_CP3_TB101C_Audit_Revision_Independent_Review_20261111.md) is replaced by two patch-and-gate pairs and two Review definitions (§9). `M6-CP3-CB121A-P13-A3-FAN-STOP-IDENTITY-RESOLUTION` is withdrawn before use. Runtime-free: syntax checks and a Python model only; no product or test source changed in the repository. Five read-only audits were delegated to subagents (§4).

## 1. What happened after RA-224

- **CB119 was applied as frozen. TB100 closed 937/938.** Row 938 asserted that the product on the hard-rail fixture is exactly the eight square corners. The product also reported the four rim ends of the hard rails, `{1, 7, 10, 16}`. The scoped equality in the same test (side starts equal the product at pass-through rim nodes) held, in both face-row orders.
- **CB119B** corrected that expected set and **TB100B** closed 938/938.
- **CB120 was applied in three slices** (CB120A stop set, CB120B factory, CB120C census), gated by TB101A, TB101B and **TB101C 940/940**.
- **TB101C `d4-corner` lines:** Plane `fieldCorners=4 chains=4/4`, MultiFaceSeam `4, 4/4`, CloseSheets `8, 8/8`, Cylinder `0, 2/2`. The product changes no chain on any gate fixture.
- **Four reviews of TB101C** then produced a 16-row conditional plan. Its first turn, CB121A, is an "arc-endpoint occurrence resolver" described in prose, with no exact patch.

## 2. Findings against RA-224 (my own record)

| # | Finding | Action |
|---|---|---|
| G1 | **Row 938's expected set was wrong.** The transport atlas has no transport across a hard-feature edge. At a rim vertex where a hard rail ends, the fan cannot be crossed, so the product reports the vertex as undecided. My Python model assumed a transport across every interior edge | Corrected by CB119B. Lesson recorded: a model must take its barriers from the code it models |
| G2 | **RA-224 F3 overclaimed.** "Every turn the line-angle test misses is a field corner" holds for an orthonormal cross on a flat fan. `cross_field_axes` copies the stored vectors without orthonormalizing them, and the turn is measured against the transported field | F3 is narrowed to that case. Agreement between scheduler and producer does not depend on it |
| G3 | **No gate fixture has a field corner that is not already a feature corner** (the TB101C census). RA-224's stop source was never seen changing a chain from derived corners | CB123 (§5): a derived, decided corner at a vertex geometry reads as smooth, through the real stop set and partition |
| G4 | **RA-224 C3 left the duplicated per-edge rule without a turn.** Two copies of a floating-point rule must agree exactly | CB124 (§7), frozen now: the producer calls the one rule |
| G5 | **The product's count includes vertices it could not decide.** On the hard-rail fixture `corners=12`, of which 4 are hard-rail ends | Harmless for chains: those nodes have three incidences. The typed Changed/Undecided split belongs to the exact-rule definition (§3 D3) |

## 3. Decision: the source vertex is the stop key

**D1. A join node has one fan.** The evidence, each step read from the code (§4):

1. The network holds one node per source vertex (`SurfaceCellTracing.cpp:4512–4516`).
2. A Boundary mandatory edge is a source edge with exactly one incident face.
3. A vertex shared by two face fans, each with two rim edges, is therefore one node with four Boundary incidences.
4. The D5 partition joins only at a node whose rotation has exactly two incidences (`GlobalConformityBaselineSupport.cpp:409`), and the arc-binding check rejects a chain through any other node (`:545–549`).
5. So a node that can join has two rim arcs, and both lie in one fan. The product starts its walk on that fan's entering rim edge and stays inside it.

A vertex-keyed stop therefore cannot stop another fan's chain: no chain passes a shared node at all. In production an A1 region is bounded only by rim and hard-feature edges, and both are rails, so the fan of a two-incidence rim node lies in one region.

**D2. The join rule is unchanged.** Joining two fans independently through one shared node would be a new D5 capability. No requirement asks for it, and DESIGN §7.4 defines a join by exactly two incidences.

**D3. The exact corner rule (O39) is due before the production switch, after there is one owner.** The switch makes A3's chain structure depend on this rule, and DESIGN §7.4 keeps floating tolerance out of A3. This withdraws RA-224's "not a precondition". An exact rule in the product alone would disagree with the floating producer at near-ties, so the order is: one owner (CB124), then a Review definition that changes that owner (`M6-CP3-DEFN-P13-A3-EXACT-RIM-ARITHMETIC`), then its CB and TB.

**D4. An undecided vertex remains a stop.** The producer rejects a region at a vertex it cannot classify, so no chain may contain one. For evidence the reviewers are right: a positive witness must be a decided turn. CB123's are (alignment 0.87 against 0.50).

**Findings on the 16-row plan.**

| # | Finding | Disposition |
|---|---|---|
| F1 | Rows 1–5 and 9–12 (occurrence resolver, per-incidence join pairs, fan-keyed producer, fan-scoped stop filter) address two fans at one node. By D1 that node never joins. The audit revision's own F2 states this ("neither fan joins") and then proposes changing the join rule so the problem can exist | Withdrawn |
| F2 | Rows 6–8 (exact rim arithmetic) are a real obligation placed before any evidence turn | Kept as one Review definition after CB124 (D3); its CB and TB are frozen by that definition |
| F3 | Rows 13–14 (derived-corner witness) need none of the earlier rows | Frozen now as CB123 → TB104 |
| F4 | Rows 15–16 (the producer reads the shared branch decision) | Frozen now, in floating point, as CB124 → TB105; the exact definition later changes the same function |
| F5 | CB121A was a prose obligation. The implementation agent works from exact patches only | Withdrawn before use |

## 4. Delegated audits (Haiku subagents, read-only)

| Audit | Result used |
|---|---|
| Network nodes and the join rule | One node per source vertex; a Boundary edge has exactly one face; a bow-tie vertex is admitted as one node with four Boundary incidences; a join needs exactly two incidences; a chain through any other node fails binding (D1) |
| What bounds an A1 region | In production only hard-feature edges, which are always rails. Sheet mismatches make isolation seams inside a region; relief barriers are not used. A direct API caller could pass mismatched component labels; production does not (D1) |
| Field axes and snapshots | `cross_field_axes` copies the stored vectors with no orthonormalization (G2). The axes reach the bounded-disk producer unchanged. The pipeline passes the atlas and the same cross field it snapshots. Snapshots survive a later pipeline failure when retention is on |
| The applied corner code | No defect. The helper matches the producer's loop operation for operation. A vertex with unchanged branches is reported only when a branch is undecided or the fan cannot be crossed (G5) |
| Existing fixtures | The curved-disk fixture (a lifted 3×3 square) is produced with 4 runs. The L-shaped fixture is rejected (`InvalidBoundedDiskFrontPairing`). No test or benchmark has a disc with a smooth rim |

## 5. CB123, frozen — the derived-corner witness (test only)

- [Patch](Architecture_M6_CP3_CB123_P13_A3_Derived_Field_Corner_Witness_Exact.diff): SHA-256 `332b3d3e5cd0fc435062d2cb8378c4364a1f39dd5cb58b66a6c74860e72c1199`, 110 lines, 2 single-space context lines. Numstat `99 0` `tests/GlobalConformityBaselineTests.cpp`. It applies at HEAD.
- **Test 941** `DerivedBoundaryFieldCornersSplitRimChains`. The mesh is an octagon fan whose rim turns by 30° at vertices 1, 3, 5, 7 and by 60° at vertices 0, 2, 4, 6. No pipeline runs and no stop is declared by hand.
  - Under a field along the axes the product is `{1, 3, 5, 7}`: the gentle turns, which a geometric corner test reads as smooth.
  - Under a field that follows each face's rim edge it is `{0, 2, 4, 6}`, through transports that are not the identity.
  - Turning every odd face's stored representative by a quarter leaves the first answer unchanged.
  - The rim's eight arcs then partition as `0R,7R|1F,2F|3F,4F|5F,6F` and `0F,1F|2F,3F|4F,5F|6F,7F`. With no stop every arc stays single (O34). Dropping the corner at vertex 1 merges two chains into `2R,1R,0R,7R`.
- **Test 942** `RimChainsNeverJoinAtANodeSharedByTwoFans`: two rim paths through one shared node never join, on one rail or two, with or without a stop there. The same paths through separate nodes join and stop separately. This is D1 as an executable control.
- **Non-vacuity.** Removing the transport from the product changes the second and third corner sets. Removing a derived corner changes the partition. Each corner is a decided turn.
- **Checks:** `-fsyntax-only` returns 0. A Python model of the product and of the partition returns every asserted value. The model's two assumptions were read from the code: transport between coplanar faces is the identity, and without an atlas the nearest branch is chosen.

## 6. TB104, frozen

- [Manifest](gates/Architecture_M6_TB104_P13_A3_Derived_Field_Corner_Witness_Full_Gate_Case_Manifest.tsv): 942 rows, SHA-256 `7b0b4545e607b138c03caab682c6d6b698639335fcf497fa8da71751bcea4b9e`. The 940 rows of the TB101 manifest (`8caccb92…`, the one TB101C ran) byte for byte, plus GUARD 941–942. `SELF_CHECK_PASS cases=942 deferred=81`; membership 1023.

| Outcome | Route |
|---|---|
| 942/942 PASS; the 7 platform-digest and 7 a3-coverage lines, the 4 `d4-rim`, 4 `d4-corner` and 2 `FIELD_CORNER_RECEIPT` lines identical to TB101C; the `DERIVED_CORNER_RECEIPT` line recorded verbatim | MATCH → `M6-CP3-CB124-P13-A3-SHARED-RIM-BRANCH-RULE` |
| Row 941 or 942 fails, any regression in 1–940, or any digest change | MISMATCH → `M6-CP3-TB104-P13-A3-DERIVED-FIELD-CORNER-WITNESS-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB104A-P13-A3-DERIVED-FIELD-CORNER-WITNESS-ORCH` |

## 7. CB124, frozen — the producer calls the one per-edge rule

- [Patch](Architecture_M6_CP3_CB124_P13_A3_Shared_Rim_Branch_Rule_Exact.diff): SHA-256 `5a39539eea26246f2758bd5bea40ca9ae339fce1b502ee98daf8c26630be7e1a`, 172 lines, 5 single-space context lines. Numstat `51 83` `src/geometry/SurfaceCellTracing.cpp`. It applies at HEAD and after CB123.
- **Change.** `boundary_edge_field_branch` moves in front of the bounded-disk producer, and the producer's own copy of the loop becomes one call. The rejection reason and its arguments are the same for both failure cases, as before. Arithmetic is unchanged operation for operation.
- **This is a production-path refactor.** Its test is the full gate: every bounded-disk row and every digest line must be unchanged.
- **Checks:** `-fsyntax-only` returns 0.

## 8. TB105, frozen

- [Manifest](gates/Architecture_M6_TB105_P13_A3_Shared_Rim_Branch_Rule_Full_Gate_Case_Manifest.tsv): 942 rows, the TB104 manifest byte for byte (same SHA-256). `SELF_CHECK_PASS cases=942 deferred=81`; membership 1023.

| Outcome | Route |
|---|---|
| 942/942 PASS; every line named in §6 and the `DERIVED_CORNER_RECEIPT` line identical to TB104; census unchanged | MATCH → `M6-CP3-DEFN-P13-A3-EXACT-RIM-ARITHMETIC` (**Review agent only**) |
| Any failure or any changed line | MISMATCH → `M6-CP3-TB105-P13-A3-SHARED-RIM-BRANCH-RULE-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB105A-P13-A3-SHARED-RIM-BRANCH-RULE-ORCH` |

## 9. Sequence and obligations

| Step | Turn | Owner |
|---|---|---|
| 64B.18 | `M6-CP3-DEFN-P13-A3-BOUNDARY-FAN-STOP-IDENTITY`: COMPLETE (this record) | Review |
| 64B.19 | `M6-CP3-CB123-P13-A3-DERIVED-FIELD-CORNER-WITNESS`: exact patch §5, test only, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-DERIVED-FIELD-CORNER-WITNESS-STOP`; infrastructure → `M6-CP3-CB123A-P13-A3-DERIVED-FIELD-CORNER-WITNESS-ORCH` | implementation agent |
| 64B.20 | `M6-CP3-TB104-P13-A3-DERIVED-FIELD-CORNER-WITNESS-FULL-GATE-EXEC` (§6) | implementation agent |
| 64B.21 | `M6-CP3-CB124-P13-A3-SHARED-RIM-BRANCH-RULE`: exact patch §7, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-SHARED-RIM-BRANCH-RULE-STOP`; infrastructure → `M6-CP3-CB124A-P13-A3-SHARED-RIM-BRANCH-RULE-ORCH` | implementation agent |
| 64B.22 | `M6-CP3-TB105-P13-A3-SHARED-RIM-BRANCH-RULE-FULL-GATE-EXEC` (§8) | implementation agent |
| 64B.23 | `M6-CP3-DEFN-P13-A3-EXACT-RIM-ARITHMETIC` (O39): exact inputs, tie and threshold rule, transport sign, and the typed Changed/Undecided result, for the one owner | **Review agent only** |
| 64D | `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION`; independent, may run alongside | **Review agent only** |
| later | The O36 switch definition: pipeline wiring of the corner product, O37, the digest plan, then the D5 and D4 switch CBs | Review, then implementation |

**Withdrawn before use** (never opened): `M6-CP3-CB121A-P13-A3-FAN-STOP-IDENTITY-RESOLUTION`, `M6-CP3-TB102A-P13-A3-FAN-STOP-IDENTITY-EXEC`, `M6-CP3-DEFN-P13-A3-FAN-INCIDENCE-CHAIN-JOINS`, `M6-CP3-CB121B-P13-A3-INCIDENCE-JOIN-PAIRS`, `M6-CP3-TB102B-P13-A3-INCIDENCE-JOIN-PAIRS-EXEC`, `M6-CP3-CB122A-P13-A3-EXACT-RIM-BRANCH-OWNER`, `M6-CP3-TB103A-P13-A3-EXACT-RIM-BRANCH-EXEC`, `M6-CP3-CB122B-P13-A3-FAN-KEYED-CORNER-PRODUCER`, `M6-CP3-TB103B-P13-A3-FAN-KEYED-CORNER-EXEC`, `M6-CP3-CB121C-P13-A3-FAN-SCOPED-STOP-FILTER`, `M6-CP3-TB102C-P13-A3-FAN-SCOPED-STOP-EXEC`, `M6-CP3-CB121D-P13-A3-DERIVED-CORNER-WITNESS`, `M6-CP3-TB102D-P13-A3-DERIVED-CORNER-EXEC`, `M6-CP3-CB122C-P13-A3-RIM-BRANCH-A4-CONSUMER`, `M6-CP3-TB103C-P13-A3-RIM-BRANCH-A4-EXEC`. The exact-rule CB and TB get their IDs from 64B.23.

**O36 preconditions after this record.**

| Condition | State |
|---|---|
| Mixed stage produces, or hard-feature rails chain (O35) | Met on the rectangular fixture (TB97) |
| Disc corners are stops (O38) | Product, stop set and factory applied (CB119, CB120A, CB120B); derived witness CB123 → TB104; pipeline wiring with the switch |
| One owner of the per-edge rule | CB124 → TB105 |
| Exact corner rule (O39) | **Precondition** (D3); definition 64B.23, then its CB and TB |
| Closed rims are cut (O34) | Wherever the field turns; a rim with no field corner and no other stop stays per arc |
| Breakpoints located in one pass (O37) | Open |
| The bounded-disk producer builds plain regions | Met on the two-square fixture (TB99). It rejects an L-shape. No smooth-rim disc has been tried: a pipeline receipt on one is owed by the switch definition |
| Switch TB pre-registers digest changes and amends the named tests | Open; TB98 shows sides going from 8 to 10 (Plane, MultiFaceSeam) and from 10 to 11 (CloseSheets) |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB104's rows 1–940 are the TB101 manifest byte for byte; TB105 equals TB104. Selector497/CP3 is unpromoted |
| Decisive claims re-derived | D1 steps 1–4 were read by a delegated audit and the join and binding conditions by me; the transport function and the no-atlas matching branch were read by me |
| Non-vacuity | §5 |
| Obligations carried | 64B.19–64B.23; 64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (narrowed); O35 (inherits the corner rule); O36; O37; O38; O39 (now a switch precondition); P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB101C 940/940, membership 1021; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 / handoff / TODO | Updated |
| Turn boundary | No product or test source changed in the repository |
