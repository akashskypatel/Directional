# CB168M — source-piece binding helper Code + Build record (2026-11-20 UTC)

Turn: `M6-CP3-CB168M-P13-SOURCE-PIECE-BINDING-HELPER`. **Compile-only PASS; tests not executed.**

- Frozen exact diff `.agents/Directional/Architecture_M6_CP3_CB168M_P13_Source_Piece_Binding_Helper_Exact.diff`, SHA-256 `f65b470dfa00dfedd808a3d6db9a602e77147b77747771826c78f662f30abf91`.
- Baseline `041bde764365710e6d5148c43751da91205ffd35`; exact source snapshot event `150074bcc2d55dcdae99039b42d9d262234b9e46`, run `44704745332`, artifact `14614446429`: 5,638/5,638 source hashes and outer ZIP digest verified. No `src/include/tests` changes between baseline and snapshot.
- `git apply --check`, `git diff --check`, exact changed-path set and patch replay passed. GitHub source commit `0d925e4e5e8324a51ebcd2728bde43015ee38ccd` via [apply run 44705402990](https://github.com/akashskypatel/Directional/actions/runs/44705402990); no other source/test/fixture/selector changes.
- Frozen diff numstat: `48 4` in `EmbeddedGraphTopology.cpp`; `26 3` in `.h`; `133 0` in `FieldAlignedCurveNetworkTests.cpp`.
- Standard eight-target GMP/GMPXX [compile run 44705720371](https://github.com/akashskypatel/Directional/actions/runs/44705720371): **SUCCESS**, package artifact `14615216674`, ZIP SHA-256 `87f1d08c808cea12b6e81475275bc86a5809ea2cfdd6fc77cfa48f527f9fba2d`; 28/28 internal package checksums verified; `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- New unwired `source_piece_binding_failure` validates segment ownership of one- or two-piece paths. `exact_trace_piece_path_between` optionally reports per-segment counts only after success. New row 965 covers valid clipping, invalid counts/partitioning, wrong face, wrong edge, vertex endpoint, and failure non-mutation.
- No Directional test, benchmark, or compiled binary ran. Row 965 is **compile-valid only**, not runtime verified. The original production face-chord path and digests are unchanged.
- TB150 remains the latest runtime authority: 964/964 gate, 963/963 prior rows MATCH, accepted CP2 491/491, census 3/3 MATCH. Stable 66/17/49, one witness debt, 81 deferred; no CP3/selector497/D0 promotion.
- **Authorized successor, not executed:** `M6-CP3-CB168N-P13-SOURCE-PIECE-COUNTS-FIELD`, exact diff SHA-256 `eddf8000ad40251a3b8a60b3d197229f8f8b5406b2789998e9c3d96ce4e37dc2`.
