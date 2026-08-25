# M3-CP4c-0-CB2 — Code + Build Report

**Status:** COMPLETE / BUILD GREEN
**Turn boundary:** Code + Build only; no Directional runtime execution
**Evidence / semantic source:** `390e65b373063c667e3c3f5e78b74ed9d859093b`
**Exact next:** `M3-CP4c-0-TB-R2`

## Verification-first result

Per the turn instruction, the branch was audited against the frozen E0–E10 corrective series before any implementation edit. The exact source snapshot showed that **E1–E9 were already present** at semantic source `390e65b373063c667e3c3f5e78b74ed9d859093b`. This turn therefore did not duplicate or rewrite those changes; it performed the remaining E10 compile/package verification and closeout only.

Static verification found:

- **E1:** failure diagnostics publish the existing exact loci losslessly and trace-seed identity is separate from failure-site identity;
- **E2:** A1 flow classification uses the exact published `FieldBranchDirection` sign rather than `kBranchTopologyTolerance`;
- **E3:** one exact vertex-sector rule survives, both production callers consume it, and the lossy world-direction round trip is absent;
- **E4:** a single-minimizer exact endpoint dispatches `VertexHit` rather than `EdgeExit`;
- **E5:** cross-edge flow agreement is asserted before adopting transported entry authority and reports `BranchTransportFlowDisagreement` on mismatch;
- **E6:** trace traversal identity includes the exact entry point, explicit cycle/budget failures are typed, and a bound/cycle stop cannot be published as a clean terminus;
- **E7:** impossible-from-valid-authority guards retain fail-closed checks with reachability annotations;
- **E8:** exactly ten `ResolvedBranchCorrection.*` falsifiers exist for the corrective measures;
- **E9:** the selector is already frozen at **338 = 316 accepted + 12 prior CP4c-0 + 10 correction identities**.

No production source, test source, fixture, selector, benchmark definition, or build configuration was changed by this verification turn.

## E3 digest-risk precheck

The mandatory precompile search found no accepted identity binding an absolute atlas digest. The accepted digest checks are relative/self-consistent (equality under equivalent reorder/relabel, inequality under semantic relabel, independently recomputed digest, or nonzero checks). No expectation edit was required or authorized.

## Frozen selector authority

- required identities: **338**, unique/non-empty;
- selector SHA-256: `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
- accepted 316-prefix SHA-256: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- prior 328-prefix SHA-256: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`;
- final ten identities: the ten `ResolvedBranchCorrection.*` falsifiers required by E8.

The accepted prefix is byte-identical to the frozen 316 authority. The prior CP4c-0 328 prefix is also byte-identical to its previous frozen selector.

## Compile/package verification — E10

Authoritative compile-only workflow run **`32909482352`**, job **`98000623070`**, built exact semantic source `390e65b373063c667e3c3f5e78b74ed9d859093b` through the durable compile reusable. Caller schema validation passed before compile.

All eight standard targets compiled/linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Immutable package authority:

- result artifact **`9586196535`** — `m3-cp4c0-cb2-result-32909482352`;
- GitHub artifact ZIP SHA-256 **`9f74856149909bc1fbcaffe638fd64b4719cddcb8ed8d92972dd52289362003f`**;
- diagnostic-log artifact **`9586197038`** — SHA-256 **`7c3e56dbdea97b318bbfe10f11c48679293838fcf1f6f94cd66793302f986e2b`**;
- packaged self-excluding `SHA256SUMS`: **27/27 PASS**;
- `runtimeExecution=false` throughout.

No generated Directional binary, test, benchmark, discovery command, `ctest`, CLI/GUI entry point, fuzzer, help/version command, or custom runtime input was executed.

## Frozen Q8 for the successor TB

Q8 is unchanged and binding. It is **not creditable unless E6 is present in the immutable package**; this source audit confirms E6 is present, but runtime credit belongs only to `M3-CP4c-0-TB-R2`.

The successor plan restates Q8 verbatim from the frozen definitions and must not weaken T6, Q8, any accepted expectation, or the prescribed-sphere fixture.

## Mandatory Test + Benchmark plan

Plan: `.agents/Directional/Architecture_M3_CP4c0_CB2_Artifact_Only_Test_Benchmark_Plan.md`.

Validate immutable artifact `9586196535` only. Execute the full 338 required identities, exactly one identity per fresh process, then perform frozen Q8 observation from the same immutable package. Do not configure, compile, relink, repair, mutate source/tests/fixtures/selectors/package, or run performance benchmarks.

A red accepted-prefix identity is an immediate stop/finding for review. A green 338 gate does not by itself close CP4c-0: frozen Q8 must also pass.

## Disposition

`M3-CP4c-0-CB2` is **COMPLETE / BUILD GREEN**. This turn claims compile/package evidence only; latest accepted runtime remains CP4ab **316/316** until runtime validation proves the corrected CP4c-0 package.

**Exact next:** `M3-CP4c-0-TB-R2` — artifact-only Test + Benchmark on semantic source `390e65b373063c667e3c3f5e78b74ed9d859093b`, package `9586196535`, required gate **338/338** plus binding Q8.
