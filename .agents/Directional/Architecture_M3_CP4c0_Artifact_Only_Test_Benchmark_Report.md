# M3-CP4c-0 Artifact-Only Test + Benchmark Report

- Phase: `M3-CP4c-0-TB-R3`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: artifact-only Test + Benchmark; no configure/build/relink/repair
- Semantic/package source: `b135e219ee9269a73eaee32992d80c3921318011`
- Runtime event/control SHA: `faf84aff4e7a64a3771e863199b82bd00425c318`
- Immutable build artifact: `9589508430`
- Immutable package SHA-256: `7bb4bd1a40af68ffd1e2ce06001490d61504e6ed0300505646c0abce97693015`
- Authoritative workflow run / Test + Benchmark job: `32921851098 / 98036868098`
- Result artifact: `9590143527`, SHA-256 `af4f5b28e509623af1fc93d55c4b766479362915e8517c741db4ae718d216604`
- Diagnostic-log artifact: `9590143871`, SHA-256 `ec9c29b7534053b023c8b6ba60fafb4c9d791e719caea3c37c3e2f742b08f5b7`
- Status: **COMPLETE / VALID SEMANTIC RED — 336/338 PASS; supplemental F3 2/2 PASS; Q8 NOT RUN**

## Plan execution and immutable preflight

TB-R3 consumed **only** CB3 package `9589508430`. Preflight re-hashed the package, verified all **27/27**
internal manifest entries, verified package source `b135e219ee9269a73eaee32992d80c3921318011`, and verified the
frozen selector and both retained prefixes:

- required selector: **338 unique identities**, SHA-256
  `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
- first 316: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- first 328: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.

The caller itself was SchemaStore-validated before runtime in run `32921817616`; the in-run schema job
`98036828551` was also green. Every required identity ran alone in a fresh process and in frozen order.
CB3's F6 continuation rule was honored: after the first semantic red, the runner executed the remaining
required identities as **non-crediting observations** instead of stopping the census.

## Integrity / artifact-only boundary

Pre/post package inventories, runtime-input inventories, selector hashes, and source status are identical.
The following all remained false: `packageMutation`, `sourceMutation`, `testMutation`, `fixtureMutation`,
`selectorMutation`, `configure`, `compile`, `relink`, `repair`, `generatedDiscovery`, and
`performanceBenchmark`. No build package was created by TB-R3.

## Frozen 338 gate

- Required / executed / passed: **338 / 338 / 336**
- Accepted predecessor prefix: **316/316 PASS**
- Prior CP4c-0 prefix: **328/328 PASS**
- Correction tail 329–338: **8/10 PASS**
- First semantic red: ordinal **333**,
  `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip`
- Additional non-crediting semantic red: ordinal **334**,
  `ResolvedBranchCorrection.ExactVertexSectorPartitionsAcceptedInteriorFans`
- Ordinals 335–338: PASS as non-crediting observations
- Identity 338, `AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections`: **PASS / NON-CREDITING**

The correction tail was therefore:

| Ordinal | Result | Credit | Identity |
| ---: | --- | --- | --- |
| 329 | PASS | crediting | `NetworkDiagnosticsPublishEveryRequiredLocusLosslessly` |
| 330 | PASS | crediting | `NetworkErrorsPublishExactEntryAndTrueFailureLocus` |
| 331 | PASS | crediting | correction identity |
| 332 | PASS | crediting | correction identity |
| 333 | RED | first / crediting red | `ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` |
| 334 | RED | non-crediting | `ExactVertexSectorPartitionsAcceptedInteriorFans` |
| 335–338 | PASS | non-crediting | remaining frozen correction identities |

A non-crediting green after ordinal 333 does not repair the frozen gate. The gate is **SEMANTIC RED**.

## Supplemental F3 falsifiers

Both class falsifiers added by CB3 ran separately in fresh processes and are green:

1. `ResolvedBranchCorrection.NetworkDiagnosticsContainNoControlCharactersForAnyCode` — PASS;
2. `ResolvedBranchCorrection.TracingPathNeverPublishesSeedIdentityAsFailureLocus` — PASS.

This is **2/2 PASS**, but supplemental checks do not change frozen-selector arithmetic and cannot override a
red required identity.

## Q8

Q8 was **not creditable and was not run**. The binding authorization condition is exact package integrity
plus **338/338** plus supplemental **2/2**. TB-R3 satisfied integrity and the supplementals but not 338/338.
Identity 338's non-crediting green is useful diagnostic evidence that the previous accepted-witness rejection
codes are absent under the CB3 package, but it is explicitly **not a Q8 substitute** and does not publish the
required sphere network, trace count, terminal intersection, or face-crossover observation.

Q8 remains frozen and unconsumed.

## TB-REVIEW findings for independent adjudication

### Candidate 1 — ordinal 333 appears to fail in witness construction before the product predicate

Runtime throws `compute_edge_quantities(): DCEL consistency check failed` from the test body. Static review
of the immutable package source shows the falsifier's search loop constructs a near-degenerate one-triangle
`TriMesh` and calls `mesh.set_mesh(vertices, faces)` **before** computing the determinant/admissibility check
that would reject such a candidate. A rejected search candidate can therefore throw from DCEL setup before
`direction_in_vertex_sector` is reached.

Classification for this TB: **test fixture/search-harness candidate, high confidence; non-stable; independent
review required**. The runtime does not establish a production semantic failure because the intended product
predicate may never execute. The review must define a deterministic capable lossy-roundtrip witness or an
admissible search construction without weakening the expectation.

### Candidate 2 — ordinal 334 appears to use a face-local branch label as a global direction identity

Runtime reports that the same numeric branch label is admitted by 0, 0, 1, and 3 faces rather than exactly one
for every branch. Static review shows `build_face_branch_frame` chooses a per-face canonical gauge from each
face's canonical topology reference edge. A semantic `FieldBranch` value is interpreted relative to that
face-local gauge. Consequently, reusing the same integer branch value independently in all four face frames
is not generally the same physical/world direction around the fan.

Classification for this TB: **test-oracle/authority candidate, high confidence; non-stable; independent review
required**. The prior review's hand calculation treated branch `+X` as identical across all face-canonical
frames; TB-R3 falsifies that assumption. The review must decide whether the valid oracle transports branch
authority across the fan or compares each face frame's published physical/exact direction. Production mutation
is not authorized unless independent source evidence proves a product defect.

### CB3 diagnostic corrections are runtime-reproved

Ordinal 329 PASS plus `NetworkDiagnosticsContainNoControlCharactersForAnyCode` PASS re-proves the F1 decimal,
lossless branch-locus formatter. Ordinal 330 PASS plus `TracingPathNeverPublishesSeedIdentityAsFailureLocus`
PASS re-proves F2's site-sourced failure-locus correction. Prior tracker candidates
`M3-CP4c0-TB-R2-CAND-01` and `M3-CP4c0-TB-R2-CAND-03` are therefore resolved non-stable.

## Regression / candidate accounting

TB-R3 adds two **non-stable candidates**, not stable regressions:

- `M3-CP4c0-TB-R3-CAND-01` — ordinal-333 fixture/search setup throws before the intended predicate;
- `M3-CP4c0-TB-R3-CAND-02` — ordinal-334 oracle conflates face-local branch labels with global direction.

The accepted **316/316** prefix remains green, CP4c-0 has never been accepted, and no accepted behavior is
shown to have regressed. Stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-
witness debt remains **5**. M3 package count remains **42** because TB-R3 consumed the existing CB3 package.

`M3-CP4c0-TB-CAND-01` receives only a partial non-crediting re-proof: identity 338 passes, but Q8 remains
blocked and unconsumed. It is not accepted closure evidence.

## Operational note — start-of-turn read-mode gate

The ChatGPT Web start-of-turn procedure requires choosing `READ_MODE` before any repository source/document
inspection. This turn performed initial direct handoff/policy reads before explicitly recording the choice,
then stopped piecemeal inspection and switched immediately to mandatory `READ_MODE=snapshot`. The exact
snapshot was then acquired and all subsequent static source analysis used that verified local materialization.
This is a control-plane process miss only; it did not change package, source, fixture, selector, runtime commands,
or semantic evidence. It must not be normalized as the preferred procedure for a later turn.

## Phase status / exact next

**M3-CP4c-0-TB-R3 is complete / valid semantic red.** CP4c-0 remains OPEN and unaccepted; latest accepted
runtime remains CP4ab **316/316**. Under the mandatory turn workflow, a red TB routes to independent
**`M3-CP4c-0-TB-R3-REVIEW-PLAN`**. Review/planning only is authorized next. No retry, Code + Build,
fixture edit, test-oracle edit, tolerance change, Q8 execution, or production mutation is authorized before
that independent adjudication.
