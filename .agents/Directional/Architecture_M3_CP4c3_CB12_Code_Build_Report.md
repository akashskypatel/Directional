# M3 CP4c-3 CB12 — Code + Build Report

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-CB12`
Status: **COMPLETE / BUILD GREEN / PRODUCT CORRECTION / RUNTIME NOT EXECUTED**

## Governing authority and boundary

`M3-CP4c-3-CB12` executed the frozen **BD0–BD9** measures from
`Architecture_M3_CP4c3_TB9_Independent_Review_Record.md`. The correction is narrowly product-owned at
`append_field_aligned_singularity_termination`: a terminal `BarrierAbsorbed` singularity is owned by its already
allocated network node rather than by the origin-port table that policy deliberately omits.

No Directional runtime test, benchmark, `ctest`, generated test discovery, CLI/help/version command, fuzzer, or
custom runtime input was executed. Compile and package boundaries record `runtimeExecution=false`.

## Exact source authority

- CB12 semantic base: `ec57a6a54ff18a172c66cca3dc3cf67d9697e58d`.
- Snapshot/control base used for the preserved patch: `73dd62c81bd4d13bf0fb9bca2d5682c7157d589e`.
- Product/test/selector correction commit and exact compile/package source:
  **`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`**.
- Work-preservation patch SHA-256:
  `67049c0d4569c2406bad74ab1861f4b1bbc7d078ab5991e23a083fd69e6dd257`.
- Patch diff-body SHA-256:
  `f05dedec37f5331d784284ad28592bdb8750ebb061154c7c6ab466f2e48a68ea`.

## BD0–BD9 implementation result

- **BD0 — frozen authority preserved.** Selectors 374/375/376 remain byte-identical at
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`,
  `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`, and
  `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`. The accepted 365 prefix is untouched.
  Mandatory GMP/GMPXX discovery and link evidence passed.
- **BD1 — barrier-absorbed arrival ownership corrected.** `append_field_aligned_singularity_termination` now reads
  the terminal singularity policy. `BarrierAbsorbed` resolves the owner from `candidate.nodes` by the singularity's
  support vertex and publishes the existing `FirstContact` + `SingularityTermination` pair at that node. The `Emit`
  path retains its port-based owner resolution and event publication.
- **BD2 — policy is explicit.** `FieldAlignedCurveNetworkCandidate` carries construction-only
  `singularityPortPolicies`; canonical construction populates it from atlas singularities. Empty ports are not used
  as a policy proxy, and the construction-only map is not added to semantic identity.
- **BD3 — fail-closed conditions remain distinct.** Existing
  `SingularityTerminationPortOwnershipMismatch` keeps its name/value/Emit behavior. New
  `SingularityTerminationBarrierAbsorbedNodeMissing` handles the genuinely inconsistent no-network-node case.
- **BD4 — production-reachable disjunct witnessed.** The direct Emit witness explicitly carries `Emit` policy and
  retains the established mismatch/incomplete checks. A new barrier-absorbed witness covers missing-node rejection
  and positive network-node termination without synthesizing a port.
- **BD5 — mechanical precondition encoded.** The new witness derives terminal vertex **v36**, requires its
  singularity to be `BarrierAbsorbed`, derives v36's candidate node and mandatory-barrier incidence, and requires
  termination publication at that node. Runtime truth is deferred to TB10.
- **BD6 — selector 377 appended.** Selector 377 is selector 376 plus exactly
  `ResolvedBranchCorrection.BarrierAbsorbedMechanicalTerminationUsesNetworkNodeWithoutPort`, has 377 unique lines,
  and SHA-256 **`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`**.
- **BD7 — prohibitions preserved.** No barrier-termination conversion, `VertexHit`/mandatory-edge reorder,
  synthesized port, policy-blind table, finalize/contact repair, fixture mutation, tolerance, float topological
  decision, sphere/370/saturation/folded-cone correction, or unrelated change was made.
- **BD8 — accepted-output audit.** The correction changes only terminal singularity ownership when the explicitly
  carried policy is `BarrierAbsorbed`; `Emit` remains on the old port path. Selectors 374–376 and the accepted 365
  prefix are byte-frozen. Runtime equivalence is not claimed from Code + Build.
- **BD9 — TB10 discriminators frozen.** TB10 must prove 1–365 remain 365/365; ordinal 366 must not repeat
  `SingularityTerminationPortOwnershipMismatch` at seed 47 / singularity 5; any remaining red must identify a
  different condition/locus/seed; the mechanical network must publish `SingularityTermination` at v36's node; and
  `M3-CP4c3-TB9-REV-CAND-01` closes only when the accepted prefix, changed ordinal-366 result, and v36-node witness
  all hold. No vertex-30 discriminator is introduced.

## Compile evidence

Run/job **`33581576670 / 100096794713`** compiled exact source
**`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`** through the mandatory reusable compile workflow.

All eight required targets compiled and linked:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

GMP/GMPXX discovery/link verification, compile preflight, full build, source-cleanliness checks, packaging manifest,
and compiler-cache boundary passed. `runtimeExecution=false`.

- compile result artifact **`9828721201`**, Actions SHA-256
  **`53b40433f2b63c551d07ee5fdf7dd9a67c278825b7c3f8b2a1aa0ca1b9194155`**;
- compile log artifact **`9828721582`**, Actions SHA-256
  **`680cbf8ec5b8632b1fcf0802c746fe87fe5a0d1d5407606bc78cce248faf4e0f`**.

## Immutable package 80

Package run/job **`33582280392 / 100098880900`** consumed compile artifact
`9828721201` without replacement compilation and without executing a Directional binary. It verified
source identity, compile manifest, GMP evidence, clean source state, selector 373–377 hashes/cardinalities/prefixes,
27 package-relative fixtures, six executable-mode binaries, and internal SHA-256 manifests before and after
deterministic extraction.

- package artifact **`9828786744`**, Actions SHA-256
  **`f4643d0535684f81de5afc9660ef40f2ffb941d1c540b91026225681314fe20e`**;
- package log artifact **`9828787020`**, Actions SHA-256
  **`c48c699d6422c4e8504a4b4708f73fb23bbbfc9e85b9d6a22fac1bdedfaf42f2`**;
- inner deterministic `package80.tar.gz` SHA-256
  **`4e8303489adb46528ae0a92c7ecf9dae65f0cbd57527740d845d318c65af02ce`**;
- packaged source archive SHA-256
  **`026a8b1efa2dc85fe2b474e0e64657bf8f997aee5b49f274c7c0c69d279fd18a`**.

Package metadata records `package=80`, `source_commit=a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`,
`selector=377`, `runtimeExecution=false`, `packageRepair=false`, `exactArithmeticBackend=GMP`, and
`modePreservingEnvelope=true`.

## Acceptance/accounting

CB12 is **build-complete**, not runtime acceptance. Accepted semantic authority remains **365/365** and CP4c-3
remains **OPEN**. Stable regression accounting remains **44 events / 14 categories / 30 recurrences**; produced-
witness debt remains **5**. Creation of package 80 advances the authoritative semantic M3 package count
**76 → 77**.

`M3-CP4c3-TB9-REV-CAND-01` remains **ACTIVE** at the build boundary. It may close only under the frozen BD9 TB10
runtime discriminators. The separate vertex-30 candidate, general exact-fallback/budget candidate, folded-cone
witness debt, sphere/saturation/ordinal-370 dispositions, and finalize/contact fall-through are unchanged.

## Exact successor

**`M3-CP4c-3-TB10` — artifact-only Test + Benchmark on immutable package 80, selector 377 from ordinal 1.** Use
`Architecture_M3_CP4c3_TB10_Artifact_Only_Test_Benchmark_Plan.md`. Do not rebuild or mutate package/source/test/
fixture/selector bytes in TB10. This CB12 closeout does not begin TB10.
