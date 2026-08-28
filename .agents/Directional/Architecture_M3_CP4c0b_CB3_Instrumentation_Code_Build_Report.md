# M3-CP4c-0b CB3-INSTR Instrumentation Code + Build Report

## Verdict

`M3-CP4c-0b-CB3-INSTR` is **COMPLETE / BUILD GREEN / RUNTIME-FREE**.

The independent T5 preflight review authorized one narrowly bounded instrumentation Code + Build under measures **V0–V7**. The turn remained inside that boundary: test-side and non-gating-selector-side observability only, zero production semantic change, the frozen 353 selector byte-identical, GMP/GMPXX linked, and no Directional runtime/test/benchmark/discovery/CLI/fuzzer execution.

Exact successor: **`M3-CP4c-0b-TB-T5`**, artifact-only on the immutable CB3 package. This report does not claim CP4c-0b acceptance.

## V0 — baseline and source authority

- pre-CB3 semantic production authority: `b2629040450c12507367c232f68a4d972b46450f`
- independent-review branch authority before instrumentation transport: `7fa64825cbf61c3e787075e9e5f5a44c96787426`
- instrumentation semantic/test commit: `93059089881c8715a168a61968a8d6874ee1a670`
- work-preservation patch: `Directional__M3-CP4c-0b-CB3-INSTR__base-7fa64825.patch`
- patch SHA-256: `5350cfeaeaaf5e4a6a7f26a6d7c3745867347c23116a2ef594e9fdc26f07f5e5`
- diff-body SHA-256: `f2991bd2df3665e6bc5d9bc579a37afc0e2a2c170cac8f3775782eb8b6cb8da3`
- changed semantic paths: exactly `tests/FieldAlignedCurveNetworkTests.cpp` and `.agents/Directional/Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt`
- `src/` and `include/`: unchanged

No accepted identity, fixture, product source, production header, guard allowance, tolerance, error bound, enum, or build configuration was changed.

## V1–V3 — bounded observability

The non-gating selector now deliberately contains exactly four identities:

1. `ResolvedBranchCorrection.ContactPredicateCensusIsPublishedNonGating`
2. `ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating`
3. `ResolvedBranchCorrection.FourTriangleFanTerminationCensusIsPublishedNonGating`
4. `ResolvedBranchCorrection.TwoRingContactPairingCensusIsPublishedNonGating`

V1 selected the already-compiled sphere A2a census before adding new code. That identity publishes the terminal-event-by-kind histogram, including `MandatoryBarrierTermination`, which supplies ordinal 13's second U3 term when the successor TB executes it.

V2 adds one non-gating fan census. It publishes, without asserting predicted values: build status and full typed error on failure; `railAuthority=AtlasDerived`; mandatory-edge and singularity counts; node count and T3-format node provenance; every trace's terminal-kind cardinality and terminal kind; barrier/contact/singularity terminating-trace counts; event-kind histogram; two-terminal-incidence event count; and N1/N2/N4 guard status.

V3 adds one non-gating two-ring event/pairing census. It publishes every event's kind, node, source face, source edge and incidence roles, and reports whether each `MandatoryBarrierTermination` has a `FirstContact` at the identical node/face/edge. It does not adjudicate the pairing; ordinal 12 remains the gating authority.

Because this is Code + Build only, CB3 records **capability**, not observed runtime values. U3/U4 values are produced only in the successor T5 run.

## V4–V5 — production and selector integrity

Frozen full selector after CB3:

- identities: **353**
- SHA-256: `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
- first 346 lines SHA-256: `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`

The 353 selector is byte-identical to CB2/T4. No identity was added, removed, reordered, or renamed in it. Ordinals 7 and 9 were not re-authored in CB3.

Enriched non-gating selector:

- identities: **4**
- SHA-256: `d42240028fb2586fa96a87cc7c058aeaa34279d5fc7b80508c4aa68472e2d9ad`
- duplicate identities: **0**
- collisions with the 353 selector: **0**

## V6 — authoritative GMP compilation and package

Authoritative compile-only workflow run: `33133572290`.

### Changed-owner preflight

- job: `98728445391` — **PASS**
- compile-result artifact: `9671181533` / `91fd484e0fc9b4031568fe2b57f902eba3c47811121a50efd25877ac79f4a880`
- compile-log artifact: `9671181736` / `e9c07b569cfc89c858cd7bcef1b233ba0d05f3cfc7fe5e6cca6d709991f0fd53`

### Eight-target immutable package

- job: `98728639650` — **PASS**
- package artifact: `9671190795`
- package ZIP SHA-256: `2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1`
- compile-log artifact: `9671190999` / `abea08419e8604a86e8866a00725ba84944c96221e79dfca34ef4195781894de`
- internal `SHA256SUMS`: **28/28 PASS**
- packaged source commit: `93059089881c8715a168a61968a8d6874ee1a670`
- source-status snapshots before/after configure/build/final: all empty
- preflight/build exit: `0 / 0`
- executable modes: six test/benchmark binaries `0755`; two static libraries `0644`
- `runtimeExecution=false`
- `turnBoundary=Code+Build-only`
- `exactArithmeticBackend=GMP`
- `semanticContracts=compiled-not-executed`
- out-of-tree build metadata preserved

Compiled targets are exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

`metadata/gmp-evidence.txt` records `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` in the generated link line. This satisfies the standing GMP compile requirement.

The immutable package increments the M3 package count from **54 to 55**. Stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**.

## V7 and process-control record

No prohibited production semantic change, accepted-identity edit, gate-credit promotion, guard widening, tolerance change, timeout, or CP4c-1/2/3 work occurred.

Three non-semantic process-control deviations from the initial CB3 session are retained for audit rather than hidden:

1. repository inspection began before the mandatory explicit `READ_MODE`/policy initialization;
2. the mandatory call-0 tool-ledger initialization was missed, so no exact total call count is claimed;
3. the first schema-validator bootstrap publication occurred before its validator run.

All three were corrected before any Directional runtime. No Directional runtime occurred anywhere in CB3. They do not change package semantics or build authority.

## Successor boundary

`M3-CP4c0b-T5-CAND-01` remains **ACTIVE / EVIDENCE-CAPABILITY / NON-STABLE** until the successor T5 actually publishes the required U3/U4 observations. CB3 supplies the missing capability; it does not by itself close the candidate.

The exact next turn is **`M3-CP4c-0b-TB-T5`**, consuming package `9671190795` directly with no rebuild, relink, repair, generated discovery, package/source/test/fixture/required-selector mutation, or inference in place of U3/U4. The frozen 353 selector remains `51ff96d7...ac6a5`; the non-gating selector is `d4224002...d9ad`. T5 must report `zeroSelected=0`; any non-zero zero-selected count is a stop because a named selector identity is absent from the binary.
