# Milestone G P5-CB91–P5-CB98 Code and Build Report

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes + compile-only build

## Disposition

P5-CB91 through P5-CB98 are implemented in source commit
`34edce9e508fd81e28bbd6b68a064a2a57bacf03` and compile successfully for the
four required targets. No test, benchmark, custom mesh, help/list command, or
compiled binary was executed. Runtime closure remains intentionally pending for
the next artifact-only test and benchmark turn.

The implementation changes 14 files with 1,780 insertions and 137 deletions.

## P5-CB91 — authoritative parity scope

- `SurfaceArrangementCell` now persists one exact `sourceComponent` and
  `sourceSheet` ownership scope independent of its multi-face support.
- Boundary subdivision derives the authoritative scope from the committed
  pre-transaction cell before moving or mutating the complex.
- A cell with no exact scope shared by every oriented boundary record fails
  before mutation.
- Replacement cells, oriented halfedges, twins, provenance entries, and node
  occurrences are rebound to the committed scope before validation.
- Typed failure evidence records original/replacement cell, halfedge/twin,
  selected scope, available scopes, and mutation phase.
- Rejected transactions retain the existing exact rollback identity proof.

## P5-CB92 — exact completion reuse

- Completion reuse identity is derived from authoritative source-domain
  dependencies rather than allocation-local identifiers.
- Identity covers source domain, side subdivision, boundary source
  coordinates, rail/curve support, singularity requirements,
  backend/variant, and topology template.
- Cyclic and reversed boundary presentations are canonicalized without
  discarding orientation-sensitive intervals.
- Cache lookup occurs before regenerated local IDs are assigned.
- Cached products are rebound and revalidated transactionally.
- Per-field mismatch vectors distinguish hash miss, exact mismatch, and failed
  rebind validation; reuse/recompute counters are derived from actual cache
  outcomes.

## P5-CB93 — invalid midpoint contract

- The missing-common-chart regression remains a separate precondition test.
- The invalid-midpoint fixture supplies explicit compatible endpoint
  occurrences and finite malformed barycentrics whose midpoint cannot be
  normalized.
- Failure is expected after temporary subdivision state exists and must return
  bit-exact committed input counts and identity.

## P5-CB94 — canonical cylinder fixture

- The open-cylinder fixture now creates one canonical intrinsic crossing entity
  per source edge and stitches chart-local segments by source-edge parameter.
- Duplicate coincident per-face arcs were removed.
- The fixture asserts incidence, embedding, orientation, disk cells, Euler
  characteristic 0, one connected component, and two boundary loops before
  simplification candidate extraction.

## P5-CB95 — producer/output contracts

- Source-chart derivation uses authoritative vertex provenance rather than
  inferred final positions.
- Output lineage preserves component, sheet, source-face support, provenance,
  rail, and boundary ownership.
- Invalid optimized output rolls back to the completed surface-cell mesh rather
  than being accepted or replaced by fallback/recovery output.
- First-invalid producer diagnostics identify the earliest stage and entity.
- Pure-quad assembly continues to reject degenerate and non-convex templates.

## P5-CB96 — memory ownership evidence

- Diagnostics distinguish logical payload, retained capacity, stage peak, and
  estimated simultaneous ownership for tracing, FlowRep, arrangement,
  simplification, and completion.
- Accounting includes Eigen storage, associative containers, nested occurrence
  and provenance capacities, endpoint queues/maps, retained debug products,
  and capacity remaining after clear/move.
- An acquire/release timeline records stage, action, logical bytes, retained
  bytes, and simultaneous bytes.
- Release flags are paired with retained-capacity evidence.
- Benchmark JSON emits the new ownership and reconciliation fields.

## P5-CB97 — regression source changes

Regression sources cover:

- exact pre-transaction parity scope and typed first-invalid evidence;
- positive exact completion reuse and mismatch-vector reporting;
- missing-chart versus invalid-midpoint distinction with rollback identity;
- canonical cylindrical open-strand topology;
- first-invalid output producer evidence;
- populated memory ownership timeline and retained-capacity accounting.

No regression executable was run in this turn.

## P5-CB98 — compile-only gate

### Configuration

- Generator: Ninja
- Compiler: Clang/Clang++ 17.0.0
- Build type: Release (`-O2 -DNDEBUG`)
- C++ standard: GNU++20
- Static libraries: `BUILD_SHARED_LIBS=OFF`
- CLI/GUI: disabled
- Tests/benchmarks: enabled
- GMP, PARDISO, SuiteSparse, cuDSS, MKL: disabled
- Global unity batch: 4
- Test and benchmark targets used temporary target-local unity batch 1 to avoid
  pre-existing anonymous-namespace symbol collisions. The temporary CMake edit
  was removed after the build and is not part of the source commit.

### Required targets

| Target | Result |
|---|---|
| `directional_core` | compiled and linked |
| `directional_pipeline` | compiled and linked |
| `directional_phase1_tests` | compiled and linked; not executed |
| `directional_benchmarks` | compiled and linked; not executed |

The only diagnostics were the existing Clang missing-`override` warnings in
`PCFaceTangentBundle`; no new compile or link error remains.

### Built artifacts

| Artifact | Bytes | SHA-256 |
|---|---:|---|
| `libdirectional_core.a` | 9,295,474 | `b23bbb8658fd52970cd46f74732be2fec3ecf446046b1cb9d35ebbc8a4b2760e` |
| `libdirectional_pipeline.a` | 2,879,090 | `9f4f90e739299d6a3c36cd7fc2681c88be1ff436175686882b974d23bd9fde60` |
| `directional_phase1_tests` | 10,282,632 | `29b1b312be74d29553247e5e9a26e4c79c74a74de937efefb73274c383ceab1a` |
| `directional_benchmarks` | 5,394,400 | `2cefa3896fdf24a9d40a2ee937f9b91312dd9dcb9a27cd816b6bec03925e6ece` |

## External source snapshots

The compile workspace used the same dependency revisions as the preceding
artifact:

- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`
- googletest `3940de91897160fea4815998e08d0fa3c2fb077e`
- polyscope `59da72df6517cab8379865899bdffdbc96171301`

## Runtime status

This turn makes no runtime claim. In particular, the following gates must be
measured from the packaged binaries in the next turn:

- all ten P5-TB16 assertion failures;
- positive exact reuse on both intended scenarios;
- typed `InvalidMidpointEmbedding` after a valid common-chart precondition;
- valid cylinder simplification and production output;
- plane, seam, torus, mechanical-feature, and Phase 20 cylinder output;
- face-edge and smooth-field random-bunny determinism and nonempty pure-quad
  output;
- stage-owned memory reconciliation against peak RSS.

P5 remains open until artifact-only runtime evidence closes these contracts.
