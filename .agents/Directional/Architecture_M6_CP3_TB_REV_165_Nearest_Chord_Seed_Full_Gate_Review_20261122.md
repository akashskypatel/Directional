# TB-REV-165 — nearest-chord seed full gate review (2026-11-22 UTC)

Review of `M6-CP3-TB-EXEC-165-P13-NEAREST-CHORD-SEED-FULL-GATE` ([report](Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Full_Gate_Execution_Report_20261122.md), [raw receipt](evidence/Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Raw_20261122.txt)). Runtime-free: source reading, the TB162–TB165 receipts, Haiku read-only checks, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **TB165's typed STOP was correct, and it is resolved against my oracle, not against the product.** Rule 3 was wrong in two places, both mine (TB-REV-164 adversarial):
  - **F1a — encoding.** I wrote `status=2` for Established. `SurfaceCutGraphSourceFaceOwnershipStatus` encodes Established as 0 and Conflicting as 2 (`SurfaceCutGraph.h:84–86`). So `status=0` on every line is the predicted outcome, and `status=2` would have meant failure. The decision-map entry `status=3` named a value that does not exist.
  - **F1b — count.** The print I froze lists nearest-chord seeds "whatever the component's resulting status", yet I predicted only the 16 seeds of components 1 and 5. The other 21 lines are seeds on edges of components 0, 2, 3 and 4. Those components were Established in TB164, so they already had a non-nearest seed, and the branch order leaves those seeds unchanged. Their census still says Established, which means one owner orbit (`SurfaceCutGraph.cpp` ownership status). So each of the 21 new seeds **agrees** with an owner fixed by another rule. That is 21 passed falsification checks, not noise.
- **Every decisive prediction held:**
  - the 16 component-1/5 seeds carry exactly orbit 6 or 12;
  - `established=192 unavailable=0 conflicting=0`;
  - `sourceFaceCellularity=1`;
  - rows 1–978 and 980–982 are unchanged, including 662 and 788;
  - the census is unchanged at 3/3;
  - production cut search is unchanged, as Z4 required.
- **The nearest-chord seed switch (CB-183/CB-184) is accepted** as the owner repair for the measured sphere components. No re-run is required: all 37 lines are published verbatim, and the corrected reading needs no allowance.
- **Activation stays held** (realignment below). The staged plan now stops at the next stage, `SourceFaceCarriesMultipleTraceCuts` at face `6-8-9`, so there is no "built" staged plan to activate.

## Findings

**G1 — Z6 is closed by published evidence.**
- The staged arcs show 8 singularity nodes (0–7), and each starts exactly 3 traces: 24 traces in all (`SphereStagedArc` table).
- A port singularity at vertex 12 or 37 would start traces inside its face star. The whole star of each lies in component 1 or 5, and both report `interiorArcs=0 vertexTransits=0`.
- So neither vertex is a port singularity, and seeding them inside cells 6 and 12 hides nothing.

**G2 — the new stop is the plan's fragment-corner reader, which assumes at most one cut per face.**
- `build_fragment_corner_incidence` (`GlobalTopologyPlan.cpp:458–676`) allows each source face either one full chord or a fan of rays from corners. A second visit raises `SourceFaceCarriesMultipleTraceCuts` (`:531–537`).
- At face `6-8-9`, the failing arc is 1: trace 0 from node 12 to node 1 over segments [6,7), a single edge piece (`SphereStagedSlidePiece … pieces=1`).
- Arc 0 has already visited segment 6 (face piece, then edge piece) and set `hasFullChord`.
- Node 12 is where trace 17 strikes trace 0's slide along edge (6,8) (`struck=0:6 carrier=(6,8)`). Node 1 is a singularity where traces 0 and 9 end by sliding (`end=point`) and traces 3 and 4 start (rays in `6-8-9`).
- So this face holds a singular corner with two departing rays, two slide arrivals, and one segment split at a node into two arcs.

**G3 — the corner reader reads whole segments, not each arc's own pieces (an RA-275 S4a site).**
- For each arc visit it uses the segment's `incomingCarrier` and `outgoingCarrier`, even when the arc owns only the edge piece of a slide. An edge-only piece cuts no face interior.
- The TB152 review already listed this reader as one that RA-275 did not switch (`TB152 independent review:143`).
- Fixing only the double visit would not be enough. The 16 opposite faces of components 1 and 5 each carry two nested chords (Y3), and they would raise the same error next. The reader needs a general rule for one face: nested chords ordered by carrier position, rays from corners, slide arrivals at corners, and edge-only pieces.

**G4 — the next step is to measure, not define.**
- Defining that general rule now would be guessing. Only one face's configuration is published, and the plan stops at the first face in arc order.
- The lesson from RA-235/RA-239 applies: enumerate every configuration that reaches the failure before designing the cure.
- The data already exists in row 979 (arcs, source pieces, segments). A test-only receipt costs one compile-only CB and one TB, with no product change and no census (product source unchanged, RA-242).

**G5 — the activation order is realigned.**
- Activation (V3/V4/V5/V10/V11) needs a staged plan that builds. Activating now would only move the production sphere's failure from cut search into the plan.
- Order: multi-cut receipt → corner-reader rule (helper, then switch) → staged plan built → activation.
- S4a (slide-plan conformity) moves ahead of activation; R1 and O48 follow as before.

Carried: Y7 (narrowed by Z3), Z5 (not witnessable on the sphere, since it has no uncertified orbit; it stays an obligation for disc fixtures), X4/H5 elsewhere, TB-REV-159-U3/V3–V11, W3/W4/W6/W7, RA-281 F1–F3, Amendment 14, O47/C5/O48/O49 and sphere χ+4. Accounting is unchanged: 66/17/49, debt1, deferred81. TB165-F1 is reclassified as a defective review oracle, with no product defect.

## Frozen artifacts

| Artifact | SHA-256 | Content |
|---|---|---|
| `Architecture_M6_CP3_CB185_P13_Staged_Multi_Cut_Face_Receipt_Exact.diff` | `77e025a862f82348765765d64c8af89a0c5d42c99e4375a2b1b1d6ea8ba7159d` | 4,210 B, +81/−0, test-only (row 979). For every source face reached by two or more trace-arc segment visits, it prints one `SphereStagedMultiCutVisit` line per visit: face, arc, trace, segment, the visit's own pieces (`F`/`FE`/`E`), incoming and outgoing carrier, slide edge, entry support (`v<id>` or edge) and whether the segment is the trace's last. It then prints one `SphereStagedMultiCutFaces` summary. Test `fea486ed…7e68e27` → `d417d635e1bcd887d4f3eefce27513464ff6e316c38525e26ed41e76ad960e0d`. |
| Gate manifest | `8d56ee1d911daa1bd3cab9f824e79131ce9f75bd7a57b31b5882d3f4f52b1e69` | The TB165 984-row manifest, reused unchanged (no new test). |

Checks (Haiku, worktree at `38c5905f0`): the preimage matches. `git apply --check` and `git apply` pass, and the postimage hash above was recomputed. `-fsyntax-only` (clang, C++20, `-Wall -Wextra`, GMP defines) gives 0 errors and 42 warnings before and after, with identical normalized warning sets. Nothing was built or run.

## TB166 rules (STOP unless all hold)

1. 984/984 PASS; CP2 491/491; membership 1065.
2. Rows 1–978 and 980–984 equal TB165 artifact `14762295772` under N1–N3, with zero allowance.
3. Row 979 equals TB165 row 979 under N1–N3 after deleting only the `SphereStagedMultiCutVisit` and `SphereStagedMultiCutFaces` lines.
4. Publish every new line verbatim. Decisive predictions:
   - face `6-8-9` is listed with visits from arcs 0 (segment 6, `FE`), 1 (segment 6, `E`), 5 (trace 3, segment 0, entry `v…`), 6 (trace 4, segment 0, entry `v…`) and 12 (trace 9, segment 6, `FE`);
   - each of the 16 component-1/5 opposite faces (`1-2-5`, `2-3-10`, `4-5-7`, `7-13-14`, `10-11-15`, `13-18-19`, `15-17-22`, `17-18-23`, `26-27-36`, `27-28-29`, `29-30-31`, `31-38-39`, `35-36-41`, `38-43-44`, `41-42-47`, `42-43-48`) is listed with at least two visits.
5. No census: product source is unchanged.
6. Any failure means STATUS BLOCKED and a return to Review.

## TB-REV-166 decision map

| Signature | Decision |
|---|---|
| Rule 4 holds | Classify every listed face into nested chords, corner fan (rays and slide arrivals), edge-only piece, or mixed. Freeze an exact pure corner-partition helper for the classes present, with tests, and a stacked switch of `build_fragment_corner_incidence` to read arc pieces. Ambiguous orders keep a typed rejection. |
| A listed face has a visit shape not covered by these classes | Freeze that class's exact rule separately, or a typed rejection; no guess. |
| A rule-4 prediction fails | My model of the face is wrong: re-read that face from the receipt before any rule. |

## Turn sequence

1. CB-185: test-only multi-cut face receipt (compile only).
2. TB-EXEC-166: 984 rows; row-979 receipt; no census.
3. TB-REV-166: freezes the corner-partition helper (CB-186) and the plan reader switch (CB-187).
4. CB-186, then CB-187 (compile only).
5. TB-EXEC/REV-167: staged plan built, or the next measured stage.
6. CB-188: activation (V3/V4/V5/V10/V11).
7. TB-EXEC/REV-168.
8. CB-189: V3b.
9. R1, then O48.

## Lessons

- Before writing a numeric status into a prediction, read the enum's values. Name the expected outcome, not just a number.
- When a frozen print covers every component, predict every line it can print: agreeing seeds on already-established components are evidence, not surplus.
- When an owner repair lets the plan advance, check whether the next reader still assumes the configuration the repair just admitted (here, one cut per face).
