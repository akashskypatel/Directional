# CB-192 — along-edge face-piece classifier, Code + Build (2026-11-23 UTC)

## Situation

The TB-REV-170 adversarial review found that the `arc_face_visits` adapter classified a face piece whose endpoints lie on one closed source-face edge as an interior cut. This led to `CutAlongOneEdge` on mechanical source face `(1,4,139)`. TB170 986/993 is rejected; TB169 993/993 is the latest accepted gate.

## Background and exact authority

- Canonical turn: `M6-CP3-CB-192-P13-ALONG-EDGE-FACE-PIECE-CLASSIFIER`. Only the frozen reviewed source/test diff was authorized; CB-191 was withdrawn without execution.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8 remains draft and unmerged).
- Base source snapshot: `b340a80622182e26d744a0c86051361fd01a5f07`; snapshot workflow 45129838848, artifact 14797152622, ZIP SHA-256 `764d441512e4ebc390bbd1bed5138cce5bbb4f3a65b3c79b976b0a67788ca273`.
- Reviewed patch: `.agents/Directional/Architecture_M6_CP3_CB192_P13_Along_Edge_Face_Piece_Classifier_Exact.diff`, SHA-256 `527dd0b82db1b6d9539a04ef5c7f09c88867f069ba3c2dadd9dd38b5bba0d7e6`, 7,105 bytes, +100/−6.
- Local `git apply --check`, `git diff --check`, exact diff-body hash, and the two postimage hashes matched before application. Remote patch apply run 45130166655, result artifact 14797132998, ZIP SHA-256 `51917ce2070b45b1590cf817d807b2aa4f26768d6de84aa0d1c491b765ceb36a`, reported `job_status=success`, `runtimeExecution=false`, and semantic commit [`462010254fa90bf6c853768019bcfc9132b5c631`](https://github.com/akashskypatel/Directional/commit/462010254fa90bf6c853768019bcfc9132b5c631). Google Drive patch transport retired by the user-authorized connector after successful application.
- Exactly two source paths changed: `src/geometry/ArcFaceVisits.h` and `tests/FieldAlignedCurveNetworkTests.cpp`. No selector, manifest, region/corner reader, partition helper, production activation, or unrelated source change.

## Assessment and compilation evidence

- `along_edge_face_side` uses `on_one_closed_edge` to distinguish an along-edge visit from an interior cut. `arc_face_visits` publishes the corresponding `edgeSideOrbit`, not `FaceCutPiece`. The new falsifier `ArcFaceVisits.FacePiecesAlongOneEdgeReadAsSlides` covers both face windings, both directions, edge corners/interior positions, and a true opposite-edge cut control.
- Exact compilation source SHA: `462010254fa90bf6c853768019bcfc9132b5c631`.
- Durable dispatcher compile [run 45130510704](https://github.com/akashskypatel/Directional/actions/runs/45130510704); immutable package artifact `14797941489`, ZIP SHA-256 `49824e664c79d13fc1b2ba047bd044303683f41b28df7a3344902e74d84b41cf`.
- Eight approved targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- `DIRECTIONAL_ENABLE_GMP=ON`; GMP and GMPXX linkage must be verified by the compile evidence; `runtimeExecution=false`.
- **No Directional runtime binary, test, benchmark, discovery or census was executed in CB-192.** A successful compile is not a passing gate. New falsifier remains unexecuted.

## Recommendation and next turn

Only `M6-CP3-TB-EXEC-171-P13-ALONG-EDGE-FACE-PIECE-FULL-GATE` is authorized next, in a new turn. Use `gates/Architecture_M6_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Case_Manifest.tsv`, SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6`: require 994/994 PASS, CP2 491/491, membership 1,075, all rows other than 979 and 994 equal TB169 `14787082075` under N1–N3 with no allowance. Row 979 is a measurement against TB170 `RegionContainsInteriorSingularity sourceVertex=8`; any other difference returns to Review. Do not run the test here or start the successor. Stable regression accounting remains 67/17/50, one produced-witness debt and 81 deferred; CP3/497/D0/H4 remain held.
