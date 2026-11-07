# M6 CP3 R4 — non-rail feature-curve source authority (2026-10-14)

Canonical turn `M6-CP3-CB1-ENTRY-R4`, Code + Build; remain in the same turn, do not start TB497 or successor. PR #8 remains draft/open. Runtime execution is prohibited here.

## Source-authenticated finding

In `src/pipeline/RemeshPipeline.cpp:build_authoritative_surface_cell_rails`, all feature-curve entries checked declared curve ownership and endpoint agreement. However, a *non-rail* member (e.g. `Soft`) could control the split between authentic hard-rail runs without its `incidentFaces` or source-component claim being authenticated against the real source edge. The `AdaptiveFeatureMapBuilder` obtains all such edges and incident faces from source mesh topology; accepting a forged non-rail member would therefore grant untrusted partition metadata.

The bounded fix validates the non-rail member's exact source edge incidence and connected source-face component, rejecting with the existing `InvalidFeatureEdge` and original feature-map index before any rail product is published. It neither changes the rail ABI nor the frozen selector. The existing `MilestoneBClosure.MixedFeatureCurveIsSplitIntoContiguousRailRuns` positive remains; the new negative forges face `{0}` instead of the true interior `{0,3}` for soft edge `(1,4)` and requires rejection at index 1.

## Reproducible provenance

- Fresh verified snapshot: workflow 38562208332, artifact 11892367092, event/source `dea48ec56ca0f6745cf3c6a501811294c063d06d`; outer SHA-256 `82773933308ea2e162bcc5e397f3ec9aa95e71d898a98f74ecadf1fce4280763`, inner archive verified, 5905/5905 individual source checksums passed.
- Two-file binary full-index patch: `/Directional/Evidence/Directional_M6_CP3_R4_Soft_Curve_Source_Authority_20261014.patch` in ChatGPT Library, SHA-256 `9046c95dc962431ed364a5b9146293946a32dfdcf7acd4e7b33e8be450257467`, diff-body SHA-256 `64eff14b895de61d1ebbf722e611b36c552307788ffc6ad2bd524e7680959883`, exact base as above. Local `git diff --check` and reverse `git apply --check` passed.
- Successful Drive patch workflow 38563422091, result artifact 11893053389 SHA-256 `ccd6d7fe80cf2fbff6f2849a1360c68f6d4f940cc8945567ca7489ab7d0dee57`. Result identifies exact patch, base and semantic source commit `56ca43b68ae295f495f6a1513255f5d77231d602`, `runtimeExecution=false`. Transient Drive File ID `151TH-TZq9MWCZBGnpcQY9EabxJSZeRaa` permanently deleted after successful push.
- Exact-source GMP/GMPXX eight-target compile requested via dispatcher commit `5eebeb863f572a8a9dcb4220082d0f45279d3af2`; mailbox `m6-cp3-r4-soft-curve-auth-compile`. **Compile now VERIFIED GREEN** (evidence below). No executable or test was run.

## Continuation

Verify compile evidence; do not run source tests, benchmarks or TB497 during this Code + Build turn. The separate independent RA-43.1/43.2 branch/filled-side attribution decision remains open, as do historical acceptance obligations and organic witness execution, which cannot be promoted from compile-only evidence. Preserve the frozen 497 selector, acceptance ledger, reusable workflow permissions and same-turn successor.

## Exact-source compile closeout — 2026-10-14 12:29 UTC

The [compile dispatcher run 38563721689](https://github.com/akashskypatel/Directional/actions/runs/38563721689) completed successfully (compile job `115851132683`, result artifact `11892769414`, outer ZIP SHA-256 `a33621c82ff5684617214ed3bb43526f58dbea8cd58fe6e725f7e65e08494fc8`). Verified source SHA `56ca43b68ae295f495f6a1513255f5d77231d602`, 28/28 internal manifest entries, 8/8 targets, preflight/build exits 0/0, five clean source-status checkpoint files, `exactArithmeticBackend=GMP`, `DIRECTIONAL_ENABLE_GMP` with actual GMPXX and GMP generated link, and `runtimeExecution=false`. Test + Benchmark job skipped. This establishes successful compilation **only**, not a runtime positive or negative regression result. Same R4 remains open; do not start TB497 or successor.
