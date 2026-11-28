# CB-193 — along-edge visit region receipt, Code + Build (2026-11-23 UTC)

## Situation

TB-REV-171 rejected TB171 (987/994). CB-192 removed false chords from along-edge pieces; this removed face ownership evidence for trace-bounded lens orbits 1/3/4/5. The next accepted step was an exact diagnostic receipt, not a source repair.

## Background and authority

- Canonical turn: `M6-CP3-CB-193-P13-ALONG-EDGE-VISIT-REGION-RECEIPT`; branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 stays draft/open.
- Frozen review patch: `.agents/Directional/Architecture_M6_CP3_CB193_P13_Along_Edge_Visit_Region_Receipt_Exact.diff`; SHA-256 `5fdea657d79d6ae2b6e3e02c31c8efb59520309c444d069f22a90bd8cae55edc`, 4,897 bytes, +87/−0, test-only.
- Exact preimage blob `936e8269b6eeb24a795f40c9b740761aac43f0e9`; postimage SHA-256 `294a54f64b8a228dda05c17c342dc8da434275122da6582fb45ebdc43d2008f3` verified locally.
- Snapshot source `71494c38a0b7df5ead80a804f4f0119b64779181`; workflow 45146333566, artifact 14805005303, ZIP SHA-256 `72e8f2d7ed7aeaaaf55e63fdf01016819a77cf8668cb053d30f21e415f8b6a46`.
- Drive patch application [run 45146949324](https://github.com/akashskypatel/Directional/actions/runs/45146949324), result artifact `14804442621`, ZIP SHA-256 `dfe495f497c62c68c2202931792b19d44696f10ff2dbe807ab91d3cdfb1973c4`, emitted exact commit `587b8ba7b1a52409d2fd95cff99dbb9d1da8f881`, `runtimeExecution=false`. The owner deleted the temporary Drive patch after successful application.

## Assessment and compilation evidence

- Only `tests/FieldAlignedCurveNetworkTests.cpp` changed. The read-only `append_along_edge_visit_receipt` executes only for existing `RegionElectedCutComponentEmpty` exceptions. It prints the exact trace/arc/visit, visited source face, source edge, side/forward/reverse orbits, and opposite face; truncation reports at 160 entries. It cannot change acceptance or product behavior.
- Exact GMP/GMPXX compile source: `587b8ba7b1a52409d2fd95cff99dbb9d1da8f881`; durable dispatcher [run 45147339047](https://github.com/akashskypatel/Directional/actions/runs/45147339047). Immutable package artifact `14805640405`; ZIP SHA-256 `58a49461e3d6cdc0480c3a2ecd8a40ac038b48595b88eb2a0f9e7015b70fe2cb`.
- Compiled eight approved targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- `DIRECTIONAL_ENABLE_GMP=ON` and both `gmpxx` and `gmp` were confirmed by the reusable compile evidence; `exactArithmeticBackend=GMP`; `runtimeExecution=false`.
- No Directional binary, test, benchmark, discovery, full gate, fixture, selector, manifest, or activation was executed or changed in this CB. Compile success is not runtime acceptance.

## Recommendation — next turn only

`M6-CP3-TB-EXEC-172-P13-ALONG-EDGE-VISIT-REGION-RECEIPT-FULL-GATE` (separate artifact-only TB). Use unchanged TB171 994-row manifest, SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6`; membership 1075, 987 PASS and seven mechanical RED expected. Compare all rows against TB171 artifact 14799346720 under N1–N3 with zero allowance except new `alongEdgeVisit*` fields appended to `RegionElectedCutComponentEmpty` exception text. Report row652 receipt verbatim, and STOP to Review on any unrelated difference. Do not run the successor in this CB. Independent TB-REV-172 decides H-strip vs H-lens per orbit; no production acceptance or CP3/497/D0/H4 promotion in this turn. Stable historical 67/17/50, debt1, deferred81 unchanged.
