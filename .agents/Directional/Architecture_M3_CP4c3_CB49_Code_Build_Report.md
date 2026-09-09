# M3-CP4c-3-CB49 Code + Build Report

**Status:** COMPLETE / COMPILE-GREEN / RUNTIME-FREE
**Turn:** `M3-CP4c-3-CB49`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Turn entry authority:** `715ac42e6ed33c54d517252313fc248eb634017c`
**Work-preservation patch base:** `59f935aecb4629d9011126b25a2a62bb21ec1ade`
**Built evidence commit:** `cf969597bda5c49e734b98db0c0165b421c4ee12`
**Execution mode:** canonical Code + Build
**Runtime executed:** no

## Implemented

CB49 repairs only the predicate drift proved by TB43-REV in
`build_fragment_corner_incidence()`.

The consumer already derived `forwardOrbit` and `reverseOrbit`. CB49 now excludes a
terminal no-barrier segment only when those certified sides share one orbit:

```cpp
if (is_terminal_slit(*trace, segmentIndex) &&
    forwardOrbit == reverseOrbit) {
  continue;
}
```

A terminal segment whose certified sides are distinct orbits is retained as separating
`FragmentCornerIncidence` ownership. No new orbit derivation, source-face enumeration,
graph traversal, partition, topology rule, or runtime special case was introduced.

The adjacent comment was corrected so it no longer claims that `build_regions()` uses the
former unconditional terminal-slit predicate.

## Three-site separation-rule audit

TB43-REV EF10.1 required the CB49 report to enumerate every known site of the frozen
separating-arc barrier rule.

1. **`SurfaceCutGraph.cpp` — source cut graph (CB34).** The code derives
   `separatesCertifiedFaces = forwardOrbit != reverseOrbit` and discards a terminal slit
   only when `terminalSlit && !separatesCertifiedFaces`.
2. **`GlobalTopologyPlan.cpp::build_regions()` — region construction (CB36).** The code
   derives the same certified-side relation and skips only
   `is_terminal_slit(...) && !separatesCertifiedFaces`.
3. **`GlobalTopologyPlan.cpp::build_fragment_corner_incidence()` — corner-owner
   projection (CB49).** `forwardOrbit`/`reverseOrbit` were already available. CB49 now
   skips only `is_terminal_slit(...) && forwardOrbit == reverseOrbit`.

All three therefore agree on the same semantic decision: equal-orbit terminal slits are
non-separating; distinct-orbit terminal sides are separating ownership.

## Engineering-guideline review

- **Material assumption:** `forwardOrbit` and `reverseOrbit` at the corner-incidence site
  are already certified face-walk orbit values. TB43-REV proved that no additional
  derivation is required.
- **Smallest sufficient correction:** one conjunct change at the existing skip site plus
  the directly stale comment.
- **Why no smaller change suffices:** changing only the comment leaves the owner-row loss;
  weakening `RegionSourceFaceOwningFragmentMissing` would hide the defect instead of
  correcting its producer.
- **Unrelated refactors/style drift:** none.
- **Test-source mutation:** none. Selector409 and accepted/control test bytes were frozen;
  ordinals 366/367 are the existing runtime witness for TB44.
- **Every semantic changed line traces to the objective:** yes.

## Files changed semantically

- `src/geometry/GlobalTopologyPlan.cpp` — 5 additions / 5 deletions.

No test, fixture, benchmark, build-system, selector, definition, region-construction,
`fragmentOrbits`, `region_orbit`, embedded-graph, cut-selection, or partition semantics
changed.

## Domain invariants

- `RegionSourceFaceOwningFragmentMissing` remains fail-closed and unchanged.
- `RegionInteriorVertexCornerOwnerMissing` and all later guards remain unchanged.
- Same-orbit terminal-slit behavior remains non-separating.
- Distinct-orbit terminal sides now survive into the orbit-keyed corner-owner projection.
- Part VIII R4.1/R4.2, Part XI/Part XI-A and Part XII remain definition authority.
- Selector409 remains SHA-256
  `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.
- TB43 remains semantic runtime authority until TB44 is executed and independently
  reviewed.

## Generalization review

The change depends only on the certified relationship between the two sides of a terminal
segment. It contains no ordinal, fixture, source-face, orbit-number, geometry, or mesh-name
condition. It therefore applies to every valid corner-incidence construction that reaches
the same producer state.

The principal regression risk is over-retaining a same-orbit terminal slit. That side of
the rule is explicitly preserved by the conjunct and is a TB44 scope invariant. The other
risk is exposing a later legitimate certification guard after the missing owner row is
restored; that is a valid measured outcome and must be preserved for independent review,
not repaired inside CB49.

## Build

**GitHub Actions run:** `34292599472`

### Changed-owner compile

- Job: `102282187127` — `changed-owner / compile` — **SUCCESS**
- Target: `directional_surface_cell_producer_tests`
- Result artifact: `10081923013` /
  `m3-cp4c3-cb49-owner-result-34292599472`
- Artifact SHA-256:
  `2f4f8eddb5ce328e47e036db0c2d2633fecee6fcea40f92437583f9e9e764c09`
- Diagnostic log artifact: `10081923410`
- Diagnostic log SHA-256:
  `7d9be7956c74b02587cac9895af978790e564cae8aeae987ac718fe37691682d`
- Compile exit: `0`
- `runtimeExecution=false`

### Package compile — package109

- Job: `102282385344` — `package / compile` — **SUCCESS**
- Result artifact: `10081938891` /
  `m3-cp4c3-cb49-result-34292599472`
- Artifact SHA-256:
  `285ee15784ea29468c367fa9e4778fd835f1e9582370fdcb26a5050a15c4d617`
- Diagnostic log artifact: `10081939181`
- Diagnostic log SHA-256:
  `9393bca8cc668aca2841b34b75a1eacc9f1a752349f165c7400eedcd36261456`
- Exact packaged source:
  `cf969597bda5c49e734b98db0c0165b421c4ee12`
- Packaged source archive SHA-256:
  `7dead808562e8faf0a90e242532e2965bc9260f24505958eb5f242c19b1273ca`
- Recursive self-excluding package manifest: **28/28 PASS**
- Source status: clean before configure, after configure, after build, and final.
- Exact arithmetic backend: **GMP**
- Authoritative link evidence contains both `libgmpxx` and `libgmp`.
- Compile boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`.
- No Directional test, benchmark, discovery/list/help/version command, `ctest`, CLI,
  fuzzer, or custom runtime input executed.

Packaged standard targets:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

The full package compile restored the fixed compatible ccache namespace and reported
116/116 cache hits. Cache behavior is performance evidence only and is not semantic
authority.

## Work preservation

The exact source-change work-preservation patch was emitted before remote orchestration:

- `Directional__M3-CP4c-3-CB49__base-59f935aecb46__work-preservation.patch`
- SHA-256:
  `280a5497647d83036d3628e46bf967f4a6670918b9da10317494c62ba552948f`

The Drive staging copy was consumed by the verified apply workflow and permanently retired
after successful application. The downloadable File-Library/chat copy remains recovery
material only.

## Known risks

CB49 has compile evidence only. It does not claim 366/367 are recovered. Runtime may:

- make 366/367 PASS;
- advance either identity to a later legitimate guard, including
  `RegionInteriorVertexCornerOwnerMissing`; or
- reproduce the exact TB43 owner-missing locus, which falsifies CB49.

The five separately owned RED identities 368/369/370/374/398 must not move under this
change. TB44 measures that claim.

## Mandatory Test + Benchmark plan

Exactly one successor plan is retained:

`Architecture_M3_CP4c3_TB44_Artifact_Only_Test_Benchmark_Plan.md`

It is bound to immutable package109 artifact `10081938891`, exact source
`cf969597bda5c49e734b98db0c0165b421c4ee12`, and frozen selector409. It restores the
generic harness's 180-second per-identity timeout control while preserving the no-outer-
elapsed-cutoff full-gate requirement.

## Next turn

**Type:** Test + Benchmark
**Exact subturn:** `M3-CP4c-3-TB44-EXEC`

CB49 is complete. Do not execute TB44 inside this turn.
