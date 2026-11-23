# TB-EXEC-171 — along-edge face-piece full gate (in progress; 2026-11-23 UTC)

## Situation

Canonical turn `M6-CP3-TB-EXEC-171-P13-ALONG-EDGE-FACE-PIECE-FULL-GATE` has dispatched exactly one artifact-only full gate. The runtime result is not yet available. Do not mark this gate green or red before collecting its immutable result.

## Background

- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Semantic source: `462010254fa90bf6c853768019bcfc9132b5c631`.
- CB-192 compile run: `45130510704`, package `14797941489`, outer ZIP SHA-256 `49824e664c79d13fc1b2ba047bd044303683f41b28df7a3344902e74d84b41cf`.
- Package root manifest SHA-256 `a917fa04222c0fd14adcdd157697b2555fd5d0ebf03d17164d11eadf8d3df0fb`; source archive SHA-256 `a85ce6f72e17a84c1d7963ba95c7fb49293a987121e9628b788415ad7fedbad6`.
- Frozen 994-row manifest `gates/Architecture_M6_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Case_Manifest.tsv`, SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6`. Its 993-row prefix is byte-identical to TB168, with only appended test `ArcFaceVisits.FacePiecesAlongOneEdgeReadAsSlides`.
- Deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 items.
- Frozen artifact-only harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Request commit `6445fdf3bcbae98d32e60c13aa8920cc830e7396`; mailbox key `m6-cp3-tb171-along-edge-face-piece-full-gate`. [Execution run 45133081384](https://github.com/akashskypatel/Directional/actions/runs/45133081384).
- Accepted comparator TB169 result `14787082075`, ZIP SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`; 993/993 PASS.

## Assessment

Dispatcher and reusable workflow schema validation passed; compilation was skipped; artifact-only runtime was active at the initial job query. No execution outcome or test count has been inferred from launch alone. Gate: 994/994 PASS, CP2 491/491, membership 1075; exact N1–N3 equivalence with accepted TB169 for rows other than 979 and 994. Seven mechanical rows 445/652/653/656/658/660/786 must pass and the 300 missing diagnostic records must return. Row979 is a non-promoting sphere-stage measurement. Stable historical accounting remains 67 events / 17 categories / 50 recurrences pending evidence.

## Recommendation

Resume this **same TB171 turn** from the mailbox on orphan `workflow-mailbox` ref at `.workflow-mailbox/m6-cp3-tb171-along-edge-face-piece-full-gate/latest.json`. When terminal, verify the exact job, result artifact, outer and internal SHA-256, full 994-row N1–N3 comparison, row979, package/source immutability, and regression classification. Complete this report and update handoff, TODO, tracker if needed, and changelog before final STATUS. Do not start TB-REV-171 within TB171, do not rebuild, edit source/tests/selectors, or run a census.
