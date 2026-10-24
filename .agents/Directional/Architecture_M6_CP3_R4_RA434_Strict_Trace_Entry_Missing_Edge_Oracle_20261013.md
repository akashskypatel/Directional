# M6 CP3 R4 — RA-43.4 strict default trace ingress edge-key oracle (2026-10-13 UTC)

**Canonical authority:** `M6-CP3-CB1-ENTRY-R4` Code + Build; no Test + Benchmark, no TB497. The independent RA-50 decision discharged RA-43.2 and prohibits inventing filled-side source authority.

## Exact source inspection authority

Verified GitHub source snapshot `fc22e74ec72570d401a14f7146cda8a8a82ffaec` (workflow `38356618714`, artifact `11792609717`, outer archive SHA-256 `d9c754c32bcc13b4567d393f72974011c2676c3737217257dae3e76a6d29cfbd`, source tar SHA-256 `28aba92f1dcf531136e2f8692d29cab83a34705f8ace2a90e3f6a00b493d57ae`, 5,603 source manifest entries), `runtimeExecution=false`. The prior no-network production helper edge-list strictness was applied and compile-GREEN at source `52389f6749e90e9fdc9c9f2b711ea0c339e323ca` in workflow `38355543522`; do not duplicate its helper tests.

## Distinct source-only regression

The existing `SurfaceCellTracingPhase14.ProducedRailEndpointsRequireExactSourceVertexIncidence` verifies `rail_interval_refs` rejects an empty edge-key list while an explicit standalone diagnostic accepts it. The production-level `trace_surface_field` test at the end of that case covered **untyped** rails but had no positive/negative for a **typed vertex list with published source-edge keys removed**.

Within the existing test identity, add a complete typed rail + valid trace entry positive (`termination != FieldMetadata`), then remove only `sourceEdges` on the trace options rail and require `termination == FieldMetadata`. Hold mesh, axes, seed, samples, typed vertices, rail ID and production no-network options constant. This pins the public/default strict entry rather than merely the shared helper, and avoids a vacuous negative from any unrelated baseline metadata failure. Preserve the separate helper, wrong-key, near-corner, malformed-sample first-rejection tests and the explicitly named standalone diagnostic exception.

This is **test-only source**. No production predicate, ABI, reusable workflow, test name, frozen selector, or snapshot authority changed. Static source and compile acceptance do not prove runtime success.

## Mandatory bounded checks

Generate a complete one-patch change from the verified snapshot, check exact-base forward/reverse apply and whitespace, stage by authorized Drive File ID in `Directional-CI`, submit one durable `drive_apply` dispatcher request, verify immutable receipt and semantic commit, then compile eight specified targets on pinned semantic SHA using the durable GMP/GMPXX GitHub Actions reusable. Verify 8/8 targets, 28/28 archive hashes, generated GMPXX/GMP link, clean source, `runtimeExecution=false`, then update this record. No local compilation, tests, benchmarks, discovery or TB497.

Remaining: global RA-43.1/43.4 disposition, RA-46.5 first-rejection cases, RA-47.12 executed liveness, 39/34/7/88/six historical obligations, and genuine odd-τ multi-carrier witnesses. No successor advancement.

## Applied source and verified immutable compile (2026-10-13 UTC)

- Exact verified patch `a60c744045af8580f645444ee75b5820491199ce812d0a6dcd44913f7e3eeda4` applied via Drive workflow `38357410100` (GREEN) to semantic commit `f1fbf8561d3d6d77f6807d0178263fa0a9ba11ef`. Receipt `11794065395` archive SHA-256 `55f32bf8f452f175bae5d1f9199cbc0e040db8e1a79989a4d105cfc326e0045e`. Exactly four changed files verified; owner-deleted Drive file `1u4VAVTKPcP8NQAnIv1rhPc19md7KNUVD`; source snapshot trigger removed in commit `4019472ccd81a0d0d52bc8dbcfc10dcd23242565`.
- Required eight-target GMP/GMPXX compile GREEN in workflow `38357644503`, source pin `f1fbf8561d3d6d77f6807d0178263fa0a9ba11ef`, event `d694e40e89e65223c48e982131409af1eb773732`, package artifact `11794145793` outer SHA-256 `fe1504fbfe0e387ee966aefac839e6758481e3cc8d52788286a1b8e6f76acb36`; diagnostic artifact `11794060971` SHA-256 `35617ac86f06e96cdb24e5be851c0b5ea2f54551e42e34c858fcd806352868df`. Independently verified 28/28 manifest entries, all eight requested targets, preflight/build `0/0`, actual `gmpxx` and `gmp` generated link, five clean source-status records, exactArithmeticBackend=GMP, `runtimeExecution=false`.
- The Phase14 test remains **unexecuted**. This is compile-only acceptance, not runtime PASS. The canonical R4 Code + Build turn remains IN_PROGRESS, all larger RA-43/46/47, historical and odd-τ obligations open, and TB497/successor unauthorized.
