# RA-123.7 — DEFN-ISO-A seam-node representative census (2026-10-21)

Scope: documents-only at SHA `eedd535c6b6f6508da1d53e5d774c5b6b748ffc3` (semantic CB23 `e859175333f879273a75e3bfc321600e451048aa`); RA-123.7. RP=`src/pipeline/RemeshPipeline.cpp`, SCT=`src/geometry/SurfaceCellTracing.cpp`. Lines refer to frozen SHA; no new contract or repair.

## Reproducible exhaustive lexical searches (verbatim)

```sh
rg -n -F 'placement.selectedFace' src/
rg -n -F 'placement.lattice' src/
rg -n -F 'cornerWedgeBindings' src/
rg -n 'firstEndpointFaceGauge|secondEndpointFaceGauge|sourceFaceBranchRotations|endpoint_face_gauge' src/
rg -n 'point_on_periodic_chart|point_on_source|chartUBranch' src/geometry/SurfaceCellTracing.cpp
```

## 1. Producers and all named-field enforcers

- Publication: RP:4443–4458 picks `cell.corners[corner].face` as the occurrence's selected face; RP:4460–4654 builds typed incoming/outgoing wedge bindings and publishes `{selectedFace,lattice}`. SCT:13404–13422 and 17741–17768 copy one point per node into corners and derive per-corner lattice. Selection is per occurrence, not per side.
- **Selected-face reads, complete literal inventory:** RP:3891–3892 (A5 seam; face of each directed span must equal its occurrence face); RP:4678,4683 (endpoint gauge face-to-row lookup; face-local); RP:5051–5052 (hard-rail route endpoint must equal published attachment faces; route-side); RP:5312,5315,5347,5350 (rejection-site diagnostics; face-local); RP:5841–5842 (A6 evidence gauge face must equal each occurrence face; face-local). No other `placement.selectedFace` reads under `src/` in the above search.
- Lattice reads (exhaustive): RP:4990–4993 hard-rail pair state; 5056–5057 hard-rail branch transport; 5149–5153 periodic relation pair; 5721–5722 OrdinaryFront phase/coordinates/scale/chart/branch. RP:4798–4799 uses `placement` as lambda argument for *front-edge* periodic gauge, not `occurrence.placement.lattice`.
- Wedge reads (exhaustive): RP:3869–3871 A5 typed span face/sheet; 5363 rejection-site diagnostic; 5538–5539 ordinary same-sheet evidence; 7311 embedding priority key; 7371,7447 quotient sheet/face checks; 8190 source-authoritative wedge/support validation. Wedges are typed side sectors.
- Endpoint face gauges: RP:4669–4685 uses `sourceFaceBranchRotations[row_for_topology(placement.selectedFace)]`; RP:5235–5236 stores seam relation gauges; RP:5832–5842 verifies gauge-face=occurrence-face. RP:5825–5877 strips gauges. Distinct periodic endpoint gauge RP:4780–4830 derives automorphism from front-edge lattice and published periodic endpoint state.
- Gauge writers: SCT:13183–13194 publishes `state.faceBranchRotation`. Uniform: SCT:13579; curved bounded disk: SCT:18037; annulus candidate: SCT:14502. Driver SCT:18370–18385 tries uniform → annulus → curved disk on `NotApplicable`; SCT:18412–18434 merges row-wise and rejects conflicting entries. Actual torus producer branch is unproven.

## 2. Frame semantics and A5/A6 seam conditions

- Corner branch vs gauge: uniform `branchRotation=faceBranchRotation[face]` (SCT:13419–13422); curved disk `branchRotation=normalized_branch(faceBranchRotation[face]+chartUBranch)` (SCT:17752–17760). Therefore equality is not assured for curved disk unless `chartUBranch=0 mod 4`. `sourceChart` comes separately from canonical face chart (SCT:17760–17768).
- A6: RP:5832–5877 computes regional turns as `faceGauge^-1 ∘ cornerBranch` and `strippedTurn=regionalSecond ∘ regionalFirst^-1`; checks `seam.forward()`/`reverse()` as selected by A5. Identical chart offsets yield identity for same-sheet; opposite-sheet residual offsets versus seam turn are not statically proven, nor preserved by hypothetical face re-expression.
- TB24: seam 60–61 uses A4 faces `120/0` and `97/2`; both vertex-61 occurrences select `121/0`. Wedges: (0,1) `120/0+121/0`; (1,0) `97/2` (RA-123.3–123.6). Span-only direction is forward, but RP:3891–3892 rejects 121≠120 and 121≠97. Changing only (1,0) to `97/2` would fix its face and typed side, but leave (0,1) 121≠120 and A6 obligations. Therefore not sufficient for `seam.forward()`.

## 3. Representative sufficiency by consumer

- **Seam OrdinaryFront:** needs each selected face equal its own directed interior-span face with matching typed side membership (RP:3855–3907), plus per-face endpoint gauge equal the selected face and A6 residual-turn certificate (RP:5832–5877). A per-*node* representative spanning two sheets is insufficient at the TB24 site.
- **Non-seam OrdinaryFront:** needs lattice source charts and branch rotations equal, shared coordinates/scale/phase, and same-sheet witness from wedges or collinear bindings (RP:5720–5790). Equality in a *shared* frame is enforced; changing one representative or re-expressing its lattice may alter these controls.
- **Hard-rail endpoint:** needs the selected face equal the specific published route attachment at each endpoint and the transported branch relation (RP:5051–5065); a generic node face is insufficient when attachment faces differ.
- **Periodic:** published front-edge endpoint states supply an automorphism (RP:4780–4830); occurrence lattice pair is separately checked for stored periodic transport (RP:4990–4993,5149–5153). No single per-node source-face gauge rule is proved sufficient for both periodic and ordinary-front consumers. A future contract must account for *occurrence/side-specific* frame requirements, not select a new face by fiat (RA-78.10; RA-79.4).

## 4. Why source node 61 is represented on face row 121

- Planar producer's `point_on_source` scans sorted `activeFaces` and accepts its first geometrically admissible face (SCT:11838–11871, 13324); this is the historical minimum-row premise of RA-72.6. **It is not a general corner representative rule.**
- Curved chart picks lexicographically least *sorted source-vertex triple* among containing chart triangles (SCT:13743–13776; key SCT:17138). Torus OBJ vertex61 fan: face97 `[49,60,61]` key `[49,60,61]`; face120 `[61,60,1]` key `[1,60,61]`; face121 `[61,1,0]` key `[0,1,61]`. Thus 121 wins if sampled/admissible. SCT:17630–17661 can override boundary points from accepted conformity, so this is conditional, not proven node61 runtime provenance; do not adopt min-row repair (RA-79.4).

## 5. Reach, controls and remaining undecidable premises

- RA-121/TB23 reports identical A5-ISO site **prefix** for ten rows: `focused30:6,20,24,25,26,27,28` and `selector:444,446,448`; G4-B002 included. TB24 measured new typed suffix on **three selected A5 rows**, not independently on all ten. The ten share the seam-relation failure shape by prior evidence; identical new selectedFace/wedge suffix on the other seven remains unmeasured (RA-123.3–123.7).
- Potentially touched controls: `focused30:7` wedge/sheet; `selector:443` periodic pair RP:5149–5153; `selector:217`, `cp3entry:6`, TB18 A#14 hard-rail RP:4990–5065. `selector:447` is a guard. Other quotient consumers RP:5772–5790,7311,7371,7447,8190 also depend on affected representation; six passing TB24 controls prove no repair.
- **Undecidable statically:** actual torus region producer among SCT:18370–18385; whether node61 used chart sampling or accepted boundary override (SCT:17630–17661); actual residual rotations and `seam.forward()` on both certified sides after any hypothetical occurrence-specific face choice (RP:5832–5877); extent of new typed suffix over the seven unmeasured A5 rows. No proof that a single wedge face serves every occurrence-side consumer.
- Probe needed, not executed: rejection-only producer diagnostic for selected region producer, vertex61 candidate keys/sampled face/accepted-boundary override, typed occurrence/side span+wedge, local gauge/chartUBranch, stripped vs expected seam turn (SCT:17630–17661; RP:5832–5877). Separately TB would sample new site fields for all ten A5 rows. Compile-only alone cannot answer runtime questions. No code, test, selector, workflow edit or binary execution in this turn.

**Disposition:** census complete as a static inventory; runtime premises above remain explicit open evidence for `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS-REV`. No DEFN-ISO-B rule/contract is authorized by this record.