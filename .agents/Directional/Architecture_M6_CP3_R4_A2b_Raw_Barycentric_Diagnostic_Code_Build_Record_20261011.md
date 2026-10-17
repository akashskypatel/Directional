# R4 source-owned A2b rejected endpoint barycentric observability — Code + Build record (2026-10-11)

Canonical current turn: `M6-CP3-CB1-ENTRY-R4`, `IN_PROGRESS`, successor `UNKNOWN`. PR #8 draft. No Test + Benchmark or Directional generated runtime executed.

## Exact source and scope

Verified source snapshot workflow `38146355008`, event/source `e209af5e0d23a01db517e7024562b68e72b25d59`, artifact `11704922127`, outer SHA-256 `5a8da6fb88726b15df348d4f0cd72ddb665dfac557a87ce8ba43b25530c4f1ec`, inner source.tar.gz SHA-256 `5d8864fa2b124c3e4225e02f05eb951ce4dac781ab28eb0fe5c52e956300d264`, self-manifest **6,174/6,174** verified, `runtimeExecution=false`. Semantic code commit `5650747e75703d644ba7f7b888981fe32fbce542`, applied in workflow `38146992456` with result `11704933167`, log `11704783988`; patch SHA-256 `b81de782cf37e758037c73a2961d20c942d810d559d4d509b5256d7f525e564e`, exact base `2a84b23815315fb8b524b4a6be0371f1f2db19de`, one changed path `src/geometry/SurfaceCellTracing.cpp`. Drive stage owner-deleted after verified commit. Patch backup in ChatGPT Library `/Directional/Evidence/Directional_M6_CP3_R4_Endpoint_Raw_Barycentric_Diagnostic.patch`.

## Finding and bounded correction

The existing rejected `endpoint_certificate` branch in `build_surface_cell_network` already reported `a2bProbeFailure`, carrier/contact/A3 presence and boolean exact-corner coincidence, but not the actual failing points' barycentrics. This prevented direct identification of source-face attachment coordinates in historical 31 common hard-rail terminal fingerprints. The added `a2bProbeFrom=<face-row>:<b0>,<b1>,<b2>` and `a2bProbeTo=...` fields are appended **only after** the existing endpoint invalid-route decision; the three stored double values are written via `std::hexfloat` without rounding in the diagnostic. They never change terminal selection, source-face/vertex, source-star adjacency, A3 transitions, accepted certificate or typed first failure. Existing `endpoint-0`/`endpoint-1` and `InvalidHardRailRouteCertificate` remain unchanged. No test or selector change.

**Interpretation caution:** `point_on_periodic_chart` canonicalizes barycentrics within `1e-10` before storing `SurfaceTracePoint`. Thus the new diagnostic preserves the *published stored* values, not pre-canonicalization UV/source provenance. It can classify non-exact stored corners and identify faces but cannot independently prove a snapped exact-corner value came from a genuinely exact geometric source point. Any change to chart snapping/source ownership requires separate Definition/Review; do not silently relax A2b exact-corner checks or fabricate a contact.

## Compile evidence (no runtime)

Exact-source mandatory GMP/GMPXX eight-target compile GREEN: workflow `38147128884`, job `114492802921`, source `5650747e75703d644ba7f7b888981fe32fbce542`, all eight requested targets, preflight/build exit `0/0`, generated gmpxx/gmp link, `exactArithmeticBackend=GMP`, 28/28 checksums, clean source, `runtimeExecution=false`. Result artifact `11704508997` ZIP SHA-256 `0e0ca6e366f57b5fbc5a573e858f5f3c27a17ca6a8c223c93a56d9128b8af097`; diagnostic artifact `11704633682` ZIP SHA-256 `95133c2ccee59fddc1059e8398812f60d64db2dfd96b0652a3584b33cad88427`. **Compilation only: none of the generated Directional binaries was executed.**

## Remaining authority

This diagnostic does not restore a frozen R3 RED to PASS. Accepted CP2 remains `491/491`; R3 rejected `403/497` with 94 RED. The 39 endpoint, 34 Phase10, seven DCEL, 88 previously accepted CP2 losses, six CP3 gates, authentic multi-carrier/odd-τ, and independent terminal dual-path source-topology Review are outstanding. Separate immutable artifact-only 497 TB is *not authorized* by Code + Build. The next independent observation must compare actual first rejection and published endpoint points under the separately authorized runtime boundary, not infer success from compile.
