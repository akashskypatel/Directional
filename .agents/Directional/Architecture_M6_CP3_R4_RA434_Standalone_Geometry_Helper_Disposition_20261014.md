# RA-43.4 — standalone geometry helper disposition (source-only)

**Turn:** `M6-CP3-CB1-R4-RA434-DISPOSE`. **Decision: retain both existing helpers unchanged.** The scope is the two identity-related standalone geometry helpers from the preceding census, not the already-frozen `rail_interval_refs` policy. This is a no-op implementation disposition, not an acceptance or execution result.

## Verified authority and evidence

Exact read-only source: `fa230b2a00e698eee9478fc06b3490cba5a86a11`, snapshot workflow [38656142605](https://github.com/akashskypatel/Directional/actions/runs/38656142605), artifact `11937071668`, outer SHA-256 `cd52018d8830d3dc63c563446d5ad4e9faa48d5072f004fb9cd5aedab5e52bd9`, inner tar `a017ec98c9bcffc73c19583002856bab7412c51182f960aa2c38827f1350e796`, **5603/5603** source digests verified. Source and test inspection only; `runtimeExecution=false`. PR #8 remained draft/open at turn entry.

- `rail_sample_source_vertex` (`src/geometry/SurfaceCellTracing.cpp:5858-5886`): returns a vertex only from a finite, exact one-hot barycentric coordinate in a real source face, excluding the sample's opposite edge corner. Returns `-1` otherwise. It is used at `:5922` as the no-published-ID geometric fallback inside `rail_sample_geometry_is_valid`, and at `:6058-6059` only for rail intervals lacking producer-published vertices. It does **not** authenticate a producer's vertex ID and must not become production authority.
- `rail_sample_geometry_is_valid` (`:5889-5930`; header `include/directional/geometry/SurfaceCellTracing.h:2487-2492`): the optional no-ID argument permits exact-corner geometry diagnostics, but supplying a typed vertex requires **actual source-face corner membership and bit-exact one-hot coordinates** at `:5909-5916`, then independently verifies 3D position. Its actual production call sites (`:6046,6049`) explicitly provide `startVertex` / `endVertex` when typed vertices are present. The direct Phase14 test calls also supply a vertex ID. There are no independent production calls omitting the argument in this snapshot.
- `rail_interval_refs` rejects missing published vertices and source-edge keys on both strict and network-bound paths (`:5971-5985`), matches typed vertices to local source topology (`:6014-6044`), and permits inferred vertices (`:6058-6059`) only in the named `LegacyStandaloneDiagnostic` mode without a network. The same network-bound path checks mandatory edge/rail/kind/component (`:6137-6147`). Thus the optional no-ID helper default is **not** an independent production ingress or a demonstrated bypass. It would be incorrect to conflate a low-level geometric predicate with an authenticated rail source receipt.

## Frozen RA-52.6 caller census — unchanged

| Production caller | Network argument | Mode |
| --- | --- | --- |
| `src/geometry/SurfaceCellTracing.cpp:10498-10502` | `options.fieldAlignedNetwork` | `RequireTypedSource` |
| `src/geometry/SurfaceCellTracing.cpp:12426-12428` | `options.fieldAlignedNetwork` | `RequireTypedSource` |
| `src/pipeline/RemeshPipeline.cpp:9630-9634` | `nullptr` | `RequireTypedSource` |

**No code change is justified.** Removing `rail_sample_source_vertex`, dropping the geometry helper's optional diagnostic argument, introducing a wrapper/tag/builder, or retiring `LegacyStandaloneDiagnostic` would only remove a permitted diagnostic capability, alter existing helper/test contracts, or harden against an unobserved caller. Frozen RA-52.6 specifically preserves a non-vacuous bypass attempt so that the real network override can reject it. Future production use of either helper as an identity oracle, or any production caller passing `LegacyStandaloneDiagnostic`, requires independent Review before implementation; the latter is an immediate `REVIEW_BLOCKER` under RA-52.6.

## Limits / next authority

No production, test, build-system or workflow source changes. No unchanged-source compilation, executable tests, benchmarks, TB497, or runtime PASS. Prior source-authored Phase10 network-override and Phase14 exact-corner tests remain **unexecuted in this turn**; this record is source evidence only. `RP-02 TEST_AUTHORITY_COVERAGE_GAP`, wider R4 Code + Build, 39/34/7/88/six historical obligations, organic/A1 and multi-carrier/odd-τ runtime gates remain. Selector 497, CP2 accepted 491/491, R3 rejected 403/497 (94 RED, 88 prior accepted losses), ledger 66/17/49 and debt 1 unchanged. This is the final authorized rung of the frozen six-step ladder; no further named successor is established by the checked handoff, so do not invent one. Resume wider R4 work only when its next exact turn is independently authorized.

**Process note:** Initial handoff/TODO/source-census connector reads occurred before the `READ_MODE=snapshot` gate was explicitly selected. Subsequent source analysis used only this verified immutable snapshot. This procedural deviation did not change test or production source and confers no verification credit.
