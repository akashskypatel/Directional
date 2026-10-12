# M6-CP3-CB1-ENTRY-R4 — RA-47.12 default pipeline typed-rail liveness regression

**Boundary:** Same R4 Code + Build; source-authored test only. No Directional runtime, binary tests or benchmarks; no TB497 or successor.

## Exact authority and static call path

- Fresh source snapshot workflow `38322389269`, exact commit `1b096eee34f6c2c81f8cdf087dabcbbd4f38c513`, artifact `11779541076`, outer SHA-256 `4708bf8e20f1aadbc03a1ee0b8cb30faae29c297055e16b305a48fee52b642b2`. Verified all 6,565 source manifest hashes and `source.tar.gz` digest `1173355ae347cb5564b8e498f5bb01d1df8e614aa68252a1285b6c6ecf929091`.
- `src/pipeline/RemeshPipeline.cpp`: default production calls `build_authoritative_surface_cell_rails`, retains `railProduct->rails`, then calls `FieldAlignedCurveNetwork::make(meshWhole, sourceTopologyRegions, fieldTransportAtlas, authoritativeRails)` after upstream atlas validation. `src/geometry/SurfaceCellTracing.cpp`, `canonical_field_aligned_candidate`, iterates actual rail `sourceEdges`, re-derives keys from `sourceVertices` and checks typed equality, returning `InvalidRailGeometry` for a mismatched key.
- Static reachability is **not** runtime liveness. The existing `build_rectangular_hard_rail_phase_front` fixture makes an actual `remesh_from_raw_cross_field` call and retains the producer's original rails, typed source authority, atlas and published field-aligned network. The new separate `SurfaceCellAuthorityContractCutover.ProducedRailsReachTypedFieldAlignedConsumerOnDefaultPipelinePath` regression checks that the default producer reaches field-aligned publication with nonempty rails; every produced typed rail key is owned by a `FieldAlignedMandatoryEdge` under the matching rail ID and kind. It then substitutes a *different actual hard-feature topology key* into one interval and asserts that the **same checked consumer** rejects `InvalidRailGeometry`. It neither fabricates a network candidate nor relies on the one-edge `(0,1)` vacuous fixture.

## What this does not establish

- A new unexecuted test is **not** a PASS, and cannot resolve RA-47.12's observational question until an explicitly authorized artifact-only Test + Benchmark turn executes it with immutable evidence. In particular, it does not prove that historical R3 failure was triggered by the former integer-domain check.
- It does not repair RA-43.2 producer-owned oriented terminal side, globally retire RA-43.4's explicit standalone diagnostic opt-out, or complete first-rejection coverage/39+34+7+88+six/odd-τ multi-carrier recovery. All R4 obligations stay open.
- Existing frozen 497 test selectors and identities are unchanged. GMP/GMPXX eight-target compile must be verified separately against the exact semantic applied commit; source compilation alone cannot be runtime credit. Ledger remains 66/17/49, debt 1; CP2 491/491 accepted, R3 403/497 rejected, 94 RED and 88 CP2 losses.
