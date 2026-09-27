# `M6-CP1-CB6-A6` — A6 quotient-product extraction — Code + Build report

## Disposition

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE UNPROMOTED.**

- Semantic source: `a532f803bd2f0ef92342652ea3f1a9b64945ba69`.
- A6 extraction commit: `faca79e3`; bounded compile fix: `a532f803`.
- Candidate package: `10896307843`.
- Reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 449/449.
- Stable accounting remains **55 events / 16 categories / 39 recurrences**; project debt remains **1**.
- No generated Directional binary was executed in this Code + Build turn.

This report closes only the authorized A6 Code + Build turn. It does **not** accept A6 semantics, promote the candidate, close CP1, discharge `G4-B002`, or authorize A7/R4 work. Those decisions remain behind immutable TB6-A6 and mandatory Review.

## Implemented scope

CB6-A6 extracts the frozen A6 quotient product from the A5 `SurfaceOccurrenceComplex` and retires the unread representative fields that the reviewed product boundary no longer permits. The implementation provides:

- semantic `SurfaceQuotientClassId` membership identity;
- `QuotientRelationCertificate` for every owned relation;
- `QuotientRelationConsumption` with joining versus cycle-closing disposition;
- deterministic selected-forest and selected-path certificates;
- `QuotientCertificate` and `MaterializationCertificate` validation records;
- typed A6 failure vocabulary including `HolonomyConflict`;
- exact cycle-closing relation consumption instead of the prior `if (!unite(...)) continue;` omission.

`SurfaceOccurrence::{chart,lattice,isolationSheet}` are retired. A7 geometry-product representation and the `G4-B002` stage boundary remain intentionally deferred to `M6-DEFN-R4`.

## RA-1 – RA-4 compliance

The static source closeout confirms all four amendments accepted by `M6-DEFN-R3-REV`:

1. **RA-1 — canonical certificate direction.** `QuotientRelationCertificate` is created from `relation.id.first` to `relation.id.second`; representation/storage order does not select semantic direction.
2. **RA-2 — OrdinaryFront identity transport.** An accepted `OrdinaryFront` relation requires identity canonical transport, and the published quotient relation transport remains identity. Isolation-seam evidence is validating evidence, not an additional quotient transform.
3. **RA-3 — evidence-complete A5 boundary.** A6 consumes `SurfaceOccurrenceRelationEvidence::canonicalTransport`, canonical selected-step and kind-specific evidence from the owned A5 relation. `SurfaceQuotientProducer::produce` contains no `firstFrontEdge` or `secondFrontEdge` dereference; those representation handles are not used to reconstruct quotient transport.
4. **RA-4 — explicit noncommutative path composition.** Forward traversal composes `path = compose(T, path)`; reverse traversal first inverts `T`. Cycle-closing relations are checked against the selected-forest path, and direct/path mismatch is typed `HolonomyConflict`.

These are compile-time/static conformance statements only. The produced cylinder row232 and torus rows444/446/448/449 remain the frozen runtime falsifiers for TB6-A6.

## Focused identity and selector checks

Static inspection at `a532f803` verifies:

- all planned A6 types and error codes exist;
- the three retired `SurfaceOccurrence` fields are absent;
- the prior cycle-closing skip is absent;
- exactly the four pre-registered new A6 focused identities are present;
- selector449 remains `d4a0d1b7...d6414`;
- routing449 remains `9c88a5ed...c5707`.

### Focused row4 mechanical migration

One frozen focused test source required a mechanical field-path migration that the earlier “zero readers” census missed. `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct` changed:

```text
a.lattice.latticeCoordinate
→
a.placement.lattice.latticeCoordinate
```

This is value-identical by construction: both values originate from the same `cell.lattice[cornerIndex]`. No production reader of the retired field existed. The migration is recorded explicitly rather than hidden; `M6-CP1-TB6-A6-REV` must independently confirm that row4's semantic meaning is unchanged.

## Compile evidence

### Attempt 1 — superseded compile failure

- Run/job: `36212343902 / 108321392040`.
- Conclusion: compile failure.
- Failure: conflicting declarations in `RemeshPipeline.cpp:4188-4197` after the A6 extraction.
- Diagnostic log artifact: `10896545227`, digest `sha256:3474648f4325cb5be8ec707826f9b7a2eb5a50125d77941d625d625c6783b8f6`.
- No Directional runtime executed.

The repair was bounded to the compile defect: the conflicting `firstSide`/`secondSide` locals were renamed and the materializer used the A6 product's class count. No A6 contract, selector, fixture or runtime expectation was weakened.

### Compile R1 — authoritative Code + Build package

- Run/job: `36212725707 / 108322509801` — **success**.
- Result artifact: `10896307843`, digest `sha256:54eb770889822ef265053494e55e25af79616f77305d1ac6900f2f8969f56b7e`.
- Log artifact: `10896347611`, digest `sha256:d0d70351dff0197182a28449361127862d6df404cc6a35d42ace519a9817c98b`.
- Exact packaged source: `a532f803bd2f0ef92342652ea3f1a9b64945ba69`.
- Source archive: `source-a532f803bd2f0ef92342652ea3f1a9b64945ba69.tar.gz`, SHA-256 `e48ad4a919e450ccd9809083af0c02e2260b7c040d40ee94741aa79428fc9a45`.
- Root manifest: **28/28 verified**.
- Preflight/build exit: **0 / 0**.
- All five packaged source-status receipts are empty.
- Boundary metadata: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`.

Compiled targets:

```text
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
directional_compiled_api_tests
directional_benchmarks
```

GMP/GMPXX linkage is explicit in package evidence (`libgmpxx.so`, `libgmp.so`), satisfying the universal exact-arithmetic compile requirement.

## Closeout and hygiene

The stalled-session recovery performed no source/test edits and no rebuild. It re-opened the immutable compile evidence, verified the package manifest/source archive locally, and inspected the exact source through runtime-free snapshot run/artifact `36358391103 / 10944138788`.

Prior CB6-A6 compile/snapshot control state was retired in workflow-first order. Cleanup run `36358568335` completed successfully; cleanup result/log artifacts are `10944648742 / 10944479721` with digests `sha256:3eb1685e7f4ea5bfc6a2be80eddadeb58c9d9354e1c8bead9ca5911fe58be613` and `sha256:e6b20c203d74b8cd01a8e1bd1754d43d88f2e80224cf1c3e3acbcb223226b44a`.

A process-only closeout observation is recorded at +0: repository authority/document reads preceded the explicit `READ_MODE=snapshot` declaration on the resume. The session corrected the ordering before semantic source inspection and used the verified snapshot thereafter. No semantic evidence or product mutation depends on the pre-declaration reads.

The documentation patch transport used for this report is control-plane-only and must be retired before the final `STATUS` write; its control artifacts are not Code + Build evidence.

## Successor gate

Exact successor: **`M6-CP1-TB6-A6-EXEC`**.

TB6-A6 consumes candidate `10896307843` immutably and executes **11 focused + selector449 = 460** fresh exact-filter processes, benchmark 0. It must not configure, compile, relink, regenerate, repair fixtures/manifests, or alter packaged binaries. Cylinder row232 and torus rows444/446/448/449 remain the pre-registered holonomy falsifiers. Mandatory `M6-CP1-TB6-A6-REV` follows before any promotion, R4/A7 work or `G4-B002` boundary work.
