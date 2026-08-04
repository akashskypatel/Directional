# Milestone G P5-CB117 through P5-CB125 Code/Build Report

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Disposition

The P5-CB117 through P5-CB125 source checkpoint and exact four-target
compile/package gate are complete. P5 remains open because runtime acceptance
has not been executed for this checkpoint and several planned producers remain
only partially corrected.

Exact checkpoint:

- implementation commit:
  `a8f8971766f55cf11828a1ae90daad3b98b50664`;
- exact compiled source, including the corrected compile workflow:
  `bc8ed616adfe59d4a3e0d5dca8ef7503d3c00e83`;
- reviewed patch SHA-256:
  `5657eb0b64aed76a5718d40a5db61e21d0c8fce60bb620e8abcf359062e873b9`;
- successful compile-only run: `30874916873`;
- compiled artifact: `8879272440`,
  `surface-cell-p5-cb125-github-source-linux-release`;
- artifact SHA-256:
  `bb9aca3881727093411f7f1012dbae9a65e1d62805a4c5a4900af58bd8f7fc76`;
- mandatory workflow-log artifact: `8879272815`;
- workflow-log SHA-256:
  `03c91d91cec65de1682d40af9a20dc9a2900e954de200ce4dbb793b1532fd6b5`.

The package records:

- empty source status;
- recursive checksums **40/40**;
- fixture files **26**;
- recursive submodule records **9**.

The workflow compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No test, benchmark, custom mesh, help/list/discovery command, or compiled project
binary was executed during this turn.

## Implementation summary

The implementation commit changes eight source/test files with 503 insertions
and 32 deletions.

### P5-CB117 — canonical rollback baseline

The manual partial-interface rollback fixture now enters the same canonical
ownership state used by production transactions before recording its committed
baseline. It still requires rejection, exact full structural identity, and
protected lineage preservation. Hashing and rollback validation were not
weakened.

This corrects the fixture precondition identified by P5-TB19. Runtime proof that
the transaction rejects and restores the canonical baseline remains a P5-TB20
gate.

### P5-CB118 — typed incidence audit

A typed `SurfaceCellIncidenceAudit` now reports the first invalid node,
halfedge, twin, next edge, cell, expected value, actual value, and failure kind.
The audit checks:

- node, halfedge, and cell ID consistency;
- endpoint validity and nondegenerate directed edges;
- twin validity and symmetry;
- next/predecessor endpoint and ownership consistency;
- closed cell cycles, minimum size, and disk-cell requirements;
- repeated cell halfedges and halfedge use counts;
- directed-edge and predecessor multiplicity;
- side metadata and canonical ownership-registry validity.

The cylinder regression now surfaces the typed incidence record instead of only
a boolean failure. The periodic open-cylinder DCEL producer itself is not
claimed repaired until runtime evidence identifies and closes the exact first
invalid entity.

### P5-CB119 and P5-CB120 — parity/subdivision transaction validity

Parity and side-repair results now retain typed domain-failure evidence.
Replacement cycles are audited before a subdivision is allowed to report
success. A proposal that repeats a boundary node or halfedge, or otherwise
creates a non-simple cycle, is rejected and rolled back rather than committed
as a successful invalid cell.

The shared-edge parity fixture is canonicalized before topology diagnostics are
recomputed. Runtime must establish whether the conforming two-cell transaction
now succeeds or merely fails earlier with better evidence. Likewise, rejecting
an invalid repeated-node subdivision closes the false-success defect but does
not by itself prove successful production completion.

### P5-CB121 — exact same-corner route ownership

Same-corner route arbitration now distinguishes geometric coincidence from
exact topological overlap. Two routes that project to the same corner sector may
remain a deterministic candidate when their canonical boundary intervals are
exact-disjoint. A shared exact interval remains fail-closed semantic overlap.

Actual cache lookup, validated rebind, and positive `reused > 0` and
`recomputed > 0` counters remain runtime gates. No counter is synthesized.

### P5-CB122 — pipeline lineage remains open

This checkpoint does not modify `RemeshPipeline.cpp`. The P5-TB19 failures in
injected optimization/validation ordering, original-failure preservation,
fallback selection, and `CompletedSurfaceCells` lineage therefore remain
explicit runtime/code gates. Completion validation must not be weakened to
close them.

### P5-CB123 — local completed-quad embedding

Pure-quad completion now validates every produced local quad before accepting a
patch result. It rejects:

- repeated quad vertices;
- missing or invalid vertex rows;
- nonfinite or degenerate Newell normals;
- zero projected area;
- bow-tie/opposite-edge crossings.

The failure is typed as
`InvalidCompletionQuadEmbedding;localQuad=<index>`. Initial completion now tries
only the existing bounded deterministic variant inventory when a variant fails
for this exact embedding reason, and stops on unrelated failures.

This prevents locally malformed patch quads from entering global stitching. It
does not yet prove that global non-adjacent intersections, duplicate stitched
faces, source-sheet leakage, or invalid cross-patch orientation are closed.

### P5-CB124 — remaining completion inventory is runtime-gated

The bounded variant selection may avoid a malformed local template, but this
turn does not claim closure of:

- the smooth-bunny duplicate stitched quad;
- torus or thin-tube incomplete complexes;
- authoritative ownership arbitration between independently completed patches.

Those require exact P5-TB20 runtime evidence before further producer changes.

### P5-CB125 — regression sources and compile/package gate

Compile-valid regression changes cover canonical transaction baselines, typed
incidence reporting, canonical shared-edge parity setup, typed domain evidence,
exact-disjoint same-corner routes, and local completion embedding rejection.

The requested same-sample memory-category expansion was not implemented in this
checkpoint. Existing ownership telemetry remains authoritative, and the 75%
reconciliation gate remains open.

## Compile evidence

Build target SHA-256 values:

- `directional_phase1_tests`:
  `9d3a231503422eb00fa7acdef39d8c4d18ad05a71334e927eb86ad514ccc1ca3`;
- `directional_benchmarks`:
  `57fa75fcc8126f81ccdbd48141303e1153eccc43a2337511051dedd920a6ad5d`;
- `libdirectional_core.a`:
  `d2a29a60331cf7e9bc78481d985f916a7fcd7ac94136d02c1c3027a89feb5c95`;
- `libdirectional_pipeline.a`:
  `2f5c58c62d4e888dbfe52d29ccdd0f986e89e348762ad8cfe817b29ff4a2009e`.

The clean Ninja Release configuration used `-O2 -DNDEBUG`, static libraries,
CLI/GUI disabled, and optional external solver backends disabled. All 131 Ninja
actions completed.

### Workflow correction

Run `30874823514` successfully verified, applied, committed, and pushed the
31,635-byte reviewed source patch, then stopped before compilation because the
workflow attempted to tee `configure.log` before creating its build directory.
The mandatory failure-log artifact was still uploaded as artifact `8879148483`
with SHA-256
`97728a2caca5a005cc1131f96099110930e5b40e7ed9c985dd63f20752144d6a`.

The workflow-only correction created the build directory before configuration.
Run `30874916873` compiled the exact descendant source
`bc8ed616adfe59d4a3e0d5dca8ef7503d3c00e83` successfully and packaged the
checkpoint. No project binary executed in either run.

## Runtime gates still open

Compilation does not establish:

- preservation of Phase 14–18 **235/235**;
- full-suite improvement from P5-TB19's **583/599**;
- a valid canonical open-cylinder DCEL;
- successful conforming shared-edge parity repair;
- successful repeated-node subdivision alternatives after invalid proposals are
  rejected;
- genuine positive completion reuse/recomputation;
- pipeline injection, fallback, and failure-lineage semantics;
- source-valid non-self-intersecting global output for any production fixture;
- smooth duplicate ownership resolution;
- torus/thin-tube completion;
- successful random-bunny output and determinism;
- at least 75% same-sample memory reconciliation.

## Required next turn

Proceed with **P5-TB20 artifact-only test and benchmark** using artifact
`8879272440` directly. Do not configure, rebuild, relink, patch, regenerate, or
modify source.

Execution order:

1. verify artifact SHA, exact source, implementation ancestry, empty status,
   checksums, submodules, fixtures, and packaged target hashes;
2. run focused canonical rollback, typed incidence, cylinder, parity,
   repeated-node, route/reuse, local embedding, global output, and pipeline
   lineage tests;
3. run Phase 14–18, Milestone D, Milestone E, GP23/GP24, Phase 20, and the full
   suite;
4. run the eight direct production fixtures with backend `SurfaceCells`, fallback
   `Fail`, and source-grid recovery disabled;
5. run one face-edge and one smooth random-bunny process first, repeating only
   after each remains within established resource limits;
6. preserve the earliest typed failing entity and write the next focused
   code/build plan without modifying source in the runtime turn.

P5 remains open. PR #8 remains open, draft, and unmerged.
