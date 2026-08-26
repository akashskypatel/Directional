# M3-CP4c-0-CB3 Code + Build Report

## Status

**COMPLETE / BUILD GREEN.** This was a Code + Build turn only. No generated Directional executable, runtime test, benchmark, discovery/listing command, `ctest`, CLI/GUI entry point, fuzzer, help/version command, or custom runtime input was executed.

## Exact authority and evidence

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Semantic source SHA: `b135e219ee9269a73eaee32992d80c3921318011`
- Compile workflow event/control SHA: `950d158c333622f59ed9d26c53b2028706954275`
- Compile run: `32919909928`
- Focus compile job: `98031291970` — `directional_surface_cell_producer_tests` — **GREEN**
- Authoritative eight-target compile job: `98031548435` — **GREEN**
- Authoritative immutable result artifact: `9589508430`
- Artifact ZIP SHA-256: `7bb4bd1a40af68ffd1e2ce06001490d61504e6ed0300505646c0abce97693015`
- Authoritative diagnostic artifact: `9589508670`, SHA-256 `2c29c76b2b0ac9d700ca9f68ec671969d85065b210ec2eb59bb11ddd9293c92f`
- Internal self-excluding `SHA256SUMS`: **27/27 PASS**
- Embedded semantic source archive: `source-b135e219ee9269a73eaee32992d80c3921318011.tar.gz`, SHA-256 `1bcc6420190be927e5fca962ba5280bb2e340e892ce81a40fcb5a17a3d432681`
- `runtimeExecution=false`; source status was clean before configure, after configure, after build, and at final status.

The workflow first compiled the changed-owner target by itself. Only after that job succeeded did the second reusable compile job package all eight standard targets. The authoritative package contains:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

## F0 — frozen authority

The CP4c-0 selector remains byte-for-byte unchanged at **338 unique, non-empty identities**. Recomputed from the immutable CB3 source archive:

- full 338 SHA-256: `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`
- accepted first-316 prefix SHA-256: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- prior first-328 prefix SHA-256: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`

No selector identity was reordered, replaced, or appended. T6, Q8, all accepted expectations, the prescribed-sphere fixture, `kBranchTopologyTolerance`, and E2–E6 semantics remain unchanged.

## F1 — branch diagnostic serialization

`tests/FieldAlignedCurveNetworkTests.cpp` now defines the named formatter:

```cpp
std::string branch_locus(const directional::authority::FieldBranch branch) {
  return std::to_string(static_cast<unsigned int>(branch.value()));
}
```

Both `branch=` and `relatedBranch=` in `append_network_error` route through `branch_locus`. There is no inline stream cast. `FieldBranch::from_integer(0)` therefore serializes as printable decimal `0`, not NUL, and the mechanism now matches Amendment 6's named-formatter rule.

## F2 — tracing-path failure-site audit

The complete `FieldAlignedCurveNetworkError` construction surface in `src/geometry/SurfaceCellTracing.cpp` was audited. The correction is locus-population only: **no control flow, error code, rejection condition, tolerance, or branch-selection semantics changed**.

Disposition:

- Port-local `InvalidCandidateTraceBinding` rejections keep the port vertex/singularity because the failure genuinely occurs at the port/binding authority.
- Downstream transport failures now use `trace_scoped_field_aligned_error`, which publishes the available failure-site face/edge/vertex/branch and records the original seed only through `traceSeedVertex` / `traceSeedSingularity`.
- Continuation, vertex-transit, traversal-cycle/budget, and cross-edge-flow errors already carry their own site; these paths now only call `annotate_field_aligned_trace_seed` to add seed provenance.
- Terminal/event construction failures now use the trace-scoped helper rather than back-filling the seed into failure-locus fields.
- Candidate-validation (`make_from_candidate`) errors were audited separately. Their candidate-owned source vertex is the object being validated, not an implicit live-trace seed substitution, so those legitimate validation loci remain unchanged.

Representative corrected downstream sites cover `InvalidCandidateTraceTransport`, `InvalidNetworkEventBinding`, and `InvalidNetworkTerminalOwnership`, including singularity termination, next-face/directed-transport resolution, contact-node materialization, mandatory terminal ownership, and repeated-state termination.

## F3 — class falsifiers

Two new `ResolvedBranchCorrection` identities compile into `directional_surface_cell_producer_tests`:

- `ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode`
- `ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus`

The first enumerates all 28 `FieldAlignedCurveNetworkErrorCode` values, populates every applicable field including branch zero, emits the complete diagnostic, and rejects every byte outside printable ASCII. The second exercises the production prescribed-sphere tracing failure path and rejects downstream reuse of trace-seed identity as failure locus while requiring explicit trace-seed provenance.

These identities intentionally do **not** alter the frozen 338 selector or its hashes. The successor TB plan executes them explicitly as mandatory supplemental corrective falsifiers. They confer no selector-gate credit; a red result is nevertheless a semantic blocker for CP4c-0 acceptance.

## F4/F5 — emitter sweep and stable ordering

`append_atlas_error`, `append_network_error`, and `append_plan_error` were audited as one diagnostic surface. Source face/edge/rational values use named locus formatters; branch values now do as well. The only other narrow accessor identified by the independent review, `GridAutomorphism::value()`, remains unexposed by these diagnostic emitters. No emitter field was reordered to hide a fragile value.

## F6 — successor execution policy

The successor artifact-only TB plan changes **observation flow only**, not credit semantics. Every frozen selector identity still executes in a fresh process and the selector remains ordered exactly as frozen. After the first semantic red, the runner continues through the remaining required identities and records those later results as **non-crediting observations**. The gate remains RED once any required identity is red and can be GREEN only at **338/338 PASS**.

The two F3 supplemental identities are also executed in fresh processes and recorded separately from the frozen selector count.

## F7 — semantic SHA versus workflow control SHA

This report records both semantic source and compile event/control SHA. The prior CB2 report was corrected retroactively to record its compile workflow control SHA `bd4ddf26296c72f3796d6d3f5d1a26c244620a1e`, resolving the provenance recording gap without changing semantic authority.

## F8 — Q8 remains verbatim frozen

The successor must evaluate this exact frozen Q8 text only after the package/integrity gates and the full required gate permit it:

1. Accepted **316/316** green, zero expectation edits.
2. The prescribed sphere reaches A2a and publishes a network — **24 traces**, from 8 index-1 singularities × 3 ports.
3. At least one sphere trace terminates on a trace/trace contact, producing a terminal `TraceIntersection` — which unblocks CP4c-1's C4/C5.
4. Face `1-2-5` with incoming `1-2` resolves to exactly one of `{1-5, 2-5}`, and the exit edge **flips** when the entry parameter is moved across the crossover.
5. The torus still publishes 0 traces; the mechanical still fails A1. Unchanged — they are not in scope.

**Identity 338 green is not a substitute for Q8.** Identity 338 only rules out two rejection codes; it does not prove that the prescribed sphere publishes a network.

## Disposition

`M3-CP4c-0-CB3` is **COMPLETE / BUILD GREEN** on exact semantic source `b135e219ee9269a73eaee32992d80c3921318011`. This turn claims compile/package evidence only. Latest accepted runtime remains CP4ab **316/316**; CP4c-0 remains open until artifact-only runtime validation proves the frozen gate, the two supplemental class falsifiers, and binding Q8.

**Exact next:** `M3-CP4c-0-TB-R3` — artifact-only Test + Benchmark using immutable package artifact `9589508430` only.
