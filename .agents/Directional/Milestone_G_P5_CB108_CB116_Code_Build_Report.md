# Milestone G P5-CB108 through P5-CB116 Code/Build Report

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Disposition

The P5-CB108 through P5-CB116 source checkpoint and exact four-target
compile/package gate are complete. P5 remains open because runtime acceptance
has not been executed for this checkpoint.

Exact checkpoint:

- implementation and compiled source:
  `9bff7d352f2751228d10ce72e2860c899f90de80`;
- reviewed source patch SHA-256:
  `e35e2afc376e2cc34fe552f0e76bd7a7628f67255da4f5c44ab369830e0181cd`;
- successful compile-only run: `30871579432`;
- compiled artifact: `8878170954`,
  `surface-cell-p5-cb116-github-source-linux-release`;
- artifact SHA-256:
  `c82a27122aaa3f3cc96f6cb3621248ed8eed4bdaf92df503b0f8deb06ec8f5d6`;
- mandatory workflow-log artifact: `8878171276`;
- log artifact SHA-256:
  `9f1531b930be97ceb674eb4f0f788cd5271673fbc77fc600df1f0768d36d28e6`.

The package records an empty source status, 26 fixture files, and 40/40
recursive packaged checksums. The workflow compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No test, benchmark, custom mesh, help/list/discovery command, or compiled project
binary was executed during this turn.

## Source changes

### P5-CB108 — compact exact ownership registry

`SurfaceCellComplex` now owns one sorted exact ownership registry. Each registry
record stores:

- the connected source component;
- a face-row-independent canonical membership signature derived from sorted
  source-triangle vertex identities and chart labels;
- the exact source-face chart records used for runtime lookup.

Cells retain only a fixed-size `{source component, class ordinal}` key and their
own incident chart map. The full component/class membership is no longer copied
into every cell.

Registry lookup, validation, canonicalization, structural hashing, rollback
identity, logical payload accounting, retained-capacity accounting, copies, and
transactional restoration now account for the registry once per complex.
Exact equality remains collision-free; no bare hash is treated as authority.

### P5-CB109 — unlabeled intrinsic ownership

When complete explicit component/sheet labels are absent, arrangement building
now derives source-face connected components from intrinsic source-edge
adjacency and installs deterministic default local charts. Explicit complete
labels remain authoritative when supplied.

Derived component numbering is based on intrinsic sorted triangle signatures,
not face-row order. Partial label arrays do not create a mixed implicit/explicit
state; the absent contract is derived consistently. Interior non-exterior cells
without valid registry ownership now fail validation rather than passing through
an empty registry.

### P5-CB110 — ownership canonicalization through simplification

Arrangement, simplification, feasibility repair, descriptor construction, and
rollback now share the registry-backed ownership model. Simplification
canonicalizes valid legacy/manual complexes at transaction boundaries, removes
ad-hoc `{component, sheet}` ownership fallbacks, permits merges only within one
canonical class, unions exact incident cell charts, and keeps hard-rail lineage
independent.

### P5-CB111 — typed prepared-domain audits

Domain identity auditing now distinguishes:

- repeated boundary node;
- repeated boundary halfedge;
- non-simple boundary;
- missing source chart;
- ownership registry mismatch.

Ordered boundary audits validate exact registry membership and incident chart
support. Descriptor early returns now retain a typed domain audit instead of
leaving failure kind `None`. This establishes precise next-runtime evidence for
prepared cells that still fail after parity or side repair.

### P5-CB112 — completion dependency groundwork

Completion/domain identities consume compact canonical ownership and exact
incident chart maps rather than expanded class payloads. This removes the
identity amplification that prevented practical cache/product storage.

The same-corner route producer and genuine positive completion reuse are not
claimed closed by this compile-only turn. They remain explicit P5-TB19 runtime
gates.

### P5-CB113 — malformed midpoint precondition

The malformed-midpoint fixture now replaces only the intended target
occurrence/chart coordinates and preserves unrelated chart occurrences on
shared endpoint nodes. Exact occurrence selection includes face, component,
sheet, source arc, and provenance identity. The separate missing-common-chart
contract remains intact.

Whether the fixture reaches `InvalidMidpointEmbedding` after temporary mutation
and rolls back bit-exactly remains a runtime gate.

### P5-CB114 — cylinder topology support

The canonical cylinder closure fixture now supplies explicit consistent
component/sheet labels so its topology contract is not preempted by classifier
ambiguity. Registry/default ownership changes also remove the previous unlabeled
scope failure from cylinder and legacy topology paths.

A complete cylinder DCEL runtime closure is not claimed. Incidence, stitching,
orientation, disk cells, Euler characteristic, connected components, boundary
loops, and strand preservation must be evaluated in P5-TB19.

### P5-CB115 — preserve valid completed checkpoints

The pipeline now validates the completed mesh before optimization. A valid
completed checkpoint is retained as the rollback authority. Invalid completion
is reported at `completion/output-validation` with the earliest issue and patch
mapping. Accepted optimizer output must validate; otherwise the last valid
completed checkpoint is preserved rather than returning a newly invalid mesh.

This is the producer/rollback correction required by P5-TB18 evidence. It does
not prove that plane, cylinder, seam, close-sheets, sphere, mechanical, torus,
thin-tube, or bunny now return valid production output.

### P5-CB116 — regression and compile/package gate

Compile-valid regression sources now cover:

- unlabeled intrinsic ownership derivation;
- class membership stored once under repeated cells;
- ownership membership invariance under source-face row order;
- adjacent per-face chart equivalence;
- disconnected close-sheet separation;
- malformed-midpoint target-occurrence preservation;
- cylinder ownership preconditions.

The clean Ninja Release configuration used `-O2 -DNDEBUG`, static libraries,
CLI/GUI disabled, and optional external solver backends disabled. Recursive
submodules were shallow-initialized and recorded. The source was clean before
configuration and again before packaging.

## Compile evidence

Build target SHA-256 values:

- `directional_phase1_tests`:
  `ace36493a6e06723a3e766b900eff2e094b4bded472d0275c0812293278b8ab9`;
- `directional_benchmarks`:
  `d7cbf63527c43aec1b9940fc5b0173282c99beead35638f63c2ee39b1d1e9d51`;
- `libdirectional_core.a`:
  `96026aa9ad7061783529ab65c9ee2176e2d87d63c8cab87ffd80506950450d68`;
- `libdirectional_pipeline.a`:
  `2f5c58c62d4e888dbfe52d29ccdd0f986e89e348762ad8cfe817b29ff4a2009e`.

The first workflow attempt, run `30871152190`, failed before patch application
because a single large comment transport had a gzip CRC mismatch. It did not
modify source. The patch was retransmitted in checksum-verified chunks and the
successful run applied exactly 64,427 patch bytes, committed 10 files with 882
insertions and 134 deletions, pushed the source checkpoint, compiled all 131
Ninja actions, packaged the results, and uploaded the mandatory success log.

## Runtime gates still open

Compilation does not establish:

- Phase 14–18, Milestone D, Milestone E, Phase 20, or complete-suite closure;
- route repair or positive exact completion reuse;
- malformed-midpoint failure after valid common-chart setup and bit-exact
  rollback;
- canonical cylinder DCEL validity;
- nonempty valid manifold pure-quad output for the production matrix;
- random-bunny face-edge or smooth completion and determinism;
- established wall/RSS limits;
- at least 75% categorized simultaneous ownership against the same peak-RSS
  sample.

P5-CB112, the complete runtime disposition of P5-CB114/P5-CB115, and
quantitative memory closure therefore remain open.

## Required next turn

Proceed with **P5-TB19 artifact-only test and benchmark** using artifact
`8878170954` directly. Do not configure, rebuild, relink, patch, regenerate, or
modify source in that turn.

Run focused ownership/topology/domain/midpoint/reuse/output tests first, then the
Phase 14–18 and milestone scopes, then the production fixture matrix, direct
random-bunny face-edge and smooth paths, deterministic repetitions only after a
single run completes within resource limits, and same-sample ownership/RSS
reconciliation. Preserve the earliest typed invalid producer for every unmet
gate.
