# CB-192 exact source-change manifest (2026-11-23 UTC)

**This file is a review artifact. The diff is not applied to live product source.**

- Authority: [TB-REV-170 adversarial continuation](../Architecture_M6_CP3_TB_REV_170_Adversarial_Review_20261123.md) A1–A4. Replaces the withdrawn CB-191 reason receipt (`aa2ff185…792f`, never executed).
- Baseline: the live branch source after CB-189 (compiled source `178f17dd59aa9c61c2e6462e2378e3a42b0ee4f7`).
- Patch: `Architecture_M6_CP3_CB192_P13_Along_Edge_Face_Piece_Classifier_Exact.diff`, SHA-256 `527dd0b82db1b6d9539a04ef5c7f09c88867f069ba3c2dadd9dd38b5bba0d7e6`, 7,105 bytes, +100/−6.
- `src/geometry/ArcFaceVisits.h`:
  - Git preimage `d8320652ed891953b9dc7077edaf71307551c978`.
  - Postimage SHA-256 `0838e637c620252886ec75a6c85bdcd036b623e5cd7c2f405adcec5000028a9e`.
- `tests/FieldAlignedCurveNetworkTests.cpp`:
  - Git preimage `6d3711ec463436fea2d550775175e5320b2bb505`.
  - Postimage SHA-256 `5d0493dd5d979672dc68c1df4ae0cafb2f6cadc61ecf1425ceede5ce40b493fd`.
- Change:
  - Adds the pure `along_edge_face_side`.
  - `arc_face_visits` reads a face piece whose two ends lie on one closed face edge as an along-edge visit: no cut, `edgeSideOrbit` set.
  - Adds test `ArcFaceVisits.FacePiecesAlongOneEdgeReadAsSlides`.
  - No other file. No change to `partition_face_corners`, the corner reader, the region reader, validators or selectors.
- TB manifest: `gates/Architecture_M6_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Case_Manifest.tsv`, SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6`. It is TB168's 993 rows plus row 994. Deferred ledger unchanged (81).
- Strict stop: a preimage mismatch or compile failure → BLOCKED, return to Review.
