# EC1 — inert carrier locus and entry-coincidence receipt (frozen Code + Build)

## Situation

Exact authorized successor `M6-CP3-CB168A-P13-ENTRY-COINCIDENCE-RECEIPT` follows only after `M6-CP3-TB142-P13-TRACE-PIECE-PATH-HELPER-FULL-GATE-REV` is complete. Do not start EC2, EC3, CB168 or H4 cutover. Frozen patch [Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Exact.diff](Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Exact.diff), SHA-256 `539fd774a2a90dc713eaa957bb48e82dc67dedb3cf35e048c3bcbc07595bd7f4`, three paths, +74/-0. Patch is **not applied** by this Review; `git apply --check` against snapshot `0e79a4be5722967a1dce39885e9bf7448364d007` passed. No compilation or generated test run in Review. Before application, verify patch checksum, three preimage blobs, branch authority and no intervening product/test drift.

## Background — exact change

- `include/directional/geometry/SurfaceCellTracing.h`: add `std::optional<authority::FieldBoundaryPoint> carrierLocus` to `FieldAlignedTerminalContact`, default absent. Existing four-argument aggregate initializers preserve legacy behavior.
- `src/geometry/SurfaceCellTracing.cpp`: hash a fixed domain and exact carrier edge+parameter **only when** the field has a value. In the two existing producer candidate-comparison loops, report identical exact source-carrier entry parameters only for **different traces**, common edge and strict 0 < parameter < 1. Deduplicate unordered (trace,segment) pairs across queue passes; keep the earlier actual contact classification and event scheduling unchanged. Output includes exact rational numerator/denominator and both trace/segment IDs, not rounded coordinate comparison.
- `tests/FieldAlignedCurveNetworkTests.cpp`: assert default absence, exact presence, different locus identity and unchanged existing face-contact fields. The full-gate comparison and new receipt census are required additional independent runtime gates in the separate Test + Benchmark turn; a type-only assertion does not by itself prove hash behavior.

## Assessment — falsifiers and stop rules

1. Compile only the eight existing required targets using `agent-compile-reusable.yml` through the durable dispatcher. GMP/GMPXX must link. Do not run any test or benchmark here. Record exact source/package SHA, link evidence and checksums.
2. Static checks: only the three patch paths; old terminal digest branch must hash exactly its old bytes when optional is absent; receipt logger must have no effect on queue, field topology or candidate data; no same-trace, vertex-only, different-edge, distinct-parameter or replay count. Review the shared source semantically before applying and halt on discrepancy.
3. In subsequent independent Test + Benchmark (not this Code + Build), start from the exact frozen prior gate/census and add one focused field test. Require the entire earlier 962-record comparison to be identical except the **new diagnostic lines**, which may be removed for comparison only by one newly frozen, narrowly prefixed normalization rule; old N1–N6 still apply. Report each new receipt in raw form with fixture, trace, segment, edge and exact parameter; independently deduplicate count and verify the 4/6 sphere locus in every applicable sphere gate row. Any other fixture's receipts must be listed rather than silently suppressed. Preserve old row858 RED and row648 reach, no new earlier BunnyRandom error, no changed raw N5/N6 lines. No graph publication or contact scheduling expected.
4. Stop if static exact patch check, compile, package hash, 491 required-green prefix, new receipt non-vacuity, or old fail-closed semantics fails. Do not weaken validators, overwrite tests, reclassify RED, alter source recovery, or implement contact scheduling. EC2 is separate.

## Recommendation

Apply only after this Review's COMPLETE beacon. The next Test + Benchmark identity and selector append must be frozen under the Code + Build / Test + Benchmark cadence, not inferred from a green compile. RA-263 S3 remains the contract; if new EC1 receipts occur outside sphere, enumerate those cases and require their predicted EC3 outcomes before freezing the EC3 producer switch.
