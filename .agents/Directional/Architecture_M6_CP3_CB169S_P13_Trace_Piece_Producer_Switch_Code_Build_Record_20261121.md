# CB169S — trace-piece producer switch Code + Build record (2026-11-21 UTC)

## Situation

Code + Build source cutover was committed and compiled; no runtime was executed. The future immutable Test + Benchmark turn has not started. This record is not production acceptance.

## Background

- Canonical turn: `M6-CP3-CB-169S-P13-TRACE-PIECE-PRODUCER-SWITCH`.
- Source snapshot base: `c3c945947c0e330d5b518b344e8241df2800b707`.
- Exact semantic source commit: `ee0f478ad95debeb3ab5a14010a7b24ea78757f6`.
- Four-path verified patch: `M6_CP3_CB169S_P13_Trace_Piece_Producer_Switch.patch`; 27,172 bytes, SHA-256 `7a6daa009357db3ccd0ac62cad5e996f3165f037c682cf0cb24d921bb1369514`; diff-body SHA-256 `1a43b3d1222d880871add48ee91807a2e15f1d900d82daa9ffaa3970e76c3538`.
- Patch apply: workflow run `44888097941`, output commit `ee0f478ad95debeb3ab5a14010a7b24ea78757f6`, verified patch SHA and paths; `runtimeExecution=false`. Drive transport object deleted by owner-authorized connector after successful push.
- Compile: [run 44888239711](https://github.com/akashskypatel/Directional/actions/runs/44888239711), artifact `14700703142`, ZIP SHA-256 `ef80c6ddda75b0a3466e1395e0d0e7d1a508bba55ce51d53f9c1b579280f2b06`, eight required targets, GMP/GMPXX linkage, `runtimeExecution=false`. Downloaded ZIP SHA-256 verified against GitHub; internal SHA256SUMS 28/28 pass, source commit matches, preflight/build exit codes 0, four source-status files empty, GMPXX/GMP link proof present.

## Assessment

- `build_arcs` now publishes `exact_trace_piece_path_between` and per-segment `sourcePieceCounts`, with exact structure binding. Mandatory/cut arcs are unchanged.
- Vertex and edge rotation readers now consume the stored initial/terminal path pieces and the CB169 piece-ray helpers. Edge-carried rays are ordered by exact source-edge direction; unsupported source ownership fails closed. Candidate digest includes per-segment piece counts and the existing source path.
- The accepted source-count test now validates per-segment counts instead of assuming one face chord for every segment. Its count mutations and false replay remain rejecting controls. The fixed prescribed sphere ray test now asserts the ten expected edge carriers/terminal vertices, along-edge type, full source-slide coverage, ordinary-ray preservation, collision absence, and actual source-piece counts. It retains the existing test identity.
- Compile-only evidence does not prove those assertions pass or that production geometry improved. TB154 remains the last executed immutable gate (971/971 PASS); CP2 491/491 accepted remains historical evidence, not a new test result. Sphere χ6 versus χ2 and four missing contacts remain unresolved.
- Source snapshot-mode pre-read procedure was initially violated by direct policy/document reads; corrected before source inspection and recorded to avoid a false compliance claim.

## Recommendation

The following *separately authorized* Test + Benchmark turn must run an immutable full gate and a representative census against this exact source/package; record every accepted-row deviation with independent source-path/face-side/rotation evidence, including opposite-face edge support, all-edge-only cases, count-only digest mutation, and the first slide-bearing conformity path. A RED requires independent Review; do not run the stop switch or promote CP3, selector 497, D0 or H4 in this turn. No Directional runtime, test, benchmark or fallback was run by CB169S.
