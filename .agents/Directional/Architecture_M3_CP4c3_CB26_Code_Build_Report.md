# M3-CP4c-3-CB26 — Code + Build Report

- Phase: `M3-CP4c-3-CB26`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Turn type: Code + Build, **orchestration correction only**
- Binding review: `Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` §7, **CD0–CD8**
- Orchestration implementation commit: `cd8e9d75d3facab3710dc51127ca3bd4f9e17c9a`
- Corrected harness: `.agents/Directional/tools/m3_cp4c3_tb23_r1_harness.sh`
- Harness LF SHA-256: `fdc335ddffe1fbaeb45783a24bfaf45b17ba0843a65df8b22950b29980cc16d7`
- Immutable semantic/package source: `e12396d471c0754b112a40272a7992020ff49ced`
- Immutable package: `9921914679`, SHA-256 `db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7`
- Selector 397: 397 identities, LF SHA-256 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`
- Runtime execution: **none**
- Compile/relink/repackage: **none** — explicitly prohibited by CD0/CD6

## Result

CB26 corrects only the TB23 execution harness and frozen execution-plan layout. The immutable CB25 package is reused byte-for-byte. A GitHub-hosted `--preflight-only` run proved that the staged executable path resolves the fixture tree through the same two-candidate rule used by `tests/TestFixturePaths.h`, while every Directional runtime/build/mutation flag remained false.

CB26 does **not** promote the orchestration-invalid TB23-EXEC ledger, does not claim semantic runtime acceptance, and does not fix the separate fail-open `test_data_root()` source defect. Authoritative semantic runtime therefore remains TB22 at **387 PASS / 6 RED, accepted 365/365**.

## CD0–CD8 discharge

### CD0 — immutable package and semantic bytes preserved

The correction changes only the artifact-only execution harness and its frozen plan. No product source, test source, fixture, selector, CMake/build logic, package byte, or package mode changed. Package `9921914679` and semantic source `e12396d...` remain the TB input.

### CD1 — corrected execution view

The harness builds an isolated execution view without mutating either immutable tree:

```text
<execution-view>/
  bin/<six packaged executables>
  test-data/benchmarks/fixtures/...
```

The six packaged executables are hard-linked into `execution-view/bin`; the fixture tree is copied from the immutable packaged source into `execution-view/test-data/benchmarks/fixtures`.

### CD2 / CD3 — consumer-rule verification, fail closed

Before any Directional runtime, the harness reproduces `test_data_root()`'s exact candidate order for a staged executable:

1. `executableDirectory.parent_path() / "test-data"`;
2. `executableDirectory / "test-data"`.

The preflight selected candidate 1 (`resolved_rule=sibling`) and verified the mechanical and prescribed-sphere fixtures through that resolved path. If neither candidate contains `benchmarks/fixtures`, the harness exits as orchestration failure before setting `runtime_started=true`.

### CD4 — hidden layout dependency made explicit

`Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md` now binds TB23-R1 to the execution-view layout, candidate order, fail-closed precondition, and immutable package/source census authorities. The harness exposes only explicit `--preflight-only` and `--execute` modes; omitted/unknown modes fail.

### CD5 — invalid attempt remains provenance only

The invalid attempt is retained unchanged:

- run/job `33833497955 / 100901221113`;
- result artifact `9922540133`;
- log artifact `9922540522`;
- raw ledger SHA-256 `839e95feea68bdff35c8c9b11ca22f486f3452413f82017888f17ffc76e85e8d`.

Its 342 PASS / 55 RED ledger is **not semantic authority** and none of its rows are promoted.

### CD6 — fail-open resolver remains out of scope

`tests/TestFixturePaths.h` is unchanged. CB26 does not repair its fail-open fallback because that would be a source/test change requiring a rebuilt package and would violate immutable-package reuse.

### CD7 — immutable-census audit

The GitHub preflight reproduced the preserved census authorities exactly:

- package census SHA-256 `9c7b12f4beba6f64e4ab1af3980554ba7b9f46af535ec2d2f2a9650f0359a927`;
- packaged-source census SHA-256 `e7bec1591154b4d9d79cd64ad27871305f54a51ba15946dc2042b55f6d2d8654`;
- package/source/execution-view pre/post equality: **PASS**.

### CD8 — TB23-R1 obligations frozen

`M3-CP4c-3-TB23-R1` must execute all 397 identities from the same package and publish the frozen discriminators: accepted 1–365 = 365/365; ordinal 366 unchanged at component 0 / `Multiple` / seed orbits `[0,1,3]` / 191 faces; non-zero examined-pair count plus differing-pair count; independent certified faces on both minority-edge sides with seed shown alongside; failing-component certified-face multiset; 394–397 results; 367/368/369/370/374 unchanged; 371/372/391/392/393 PASS.

## Work-preservation and patch application

- Complete full-index work-preservation patch emitted before remote orchestration: `Directional__M3-CP4c-3-CB26__base-9df9da68e911__work-preservation.patch`.
- Patch SHA-256: `57f9fdad7dc78db0b1077c9e5af76f70e6505f1c612fc271875c493d0410f767`.
- Drive File ID: `18j30qYJoKfKeqL5HWym7goVrMIVFfBva`.
- Drive-apply run: `33837931920`, SUCCESS.
- Drive-apply result artifact: `9923919562`, SHA-256 `f84d48a70159c3d2e1c6cf23bf1cbe178fe8b763c3a260948a4f1cd8464aa327`.
- Applied implementation commit: `cd8e9d75d3facab3710dc51127ca3bd4f9e17c9a`.
- The service identity could not trash the Drive file (`drive_file_retirement_required=true`); the owner-authorized Drive connector permanently deleted it after the successful push.

## GitHub orchestration-preflight evidence

- Trigger/source-control SHA: `1166ceac31aa737c536354a9fb6279dfeaae1d5c` (implementation plus temporary control marker/caller only).
- Run/job: `33838073812 / 100914602406`, **SUCCESS**.
- Result artifact: `9923955664`, SHA-256 `d41efb94efee51c94f24c52a3ccb896fdcc3355aa8aec365ce72e11a753bcd9e`.
- Diagnostic-log artifact: `9923956087`, SHA-256 `c385a4e39d1ff1d3b26104c99c2b09f6d534e1a402b269b7b041d071b0abf430`.
- `script_exit=0`, `mode=--preflight-only`.
- `preflight_completed=true`, `execution_view_verified=true`.
- `runtime_started=false`, `runtime_completed=false`, `benchmark_execution=false`.
- `configure_execution=false`, `compile_execution=false`, `relink_execution=false`, `generated_discovery=false`.
- `package_repair=false`, `mode_repair=false`, `source_test_fixture_selector_mutation=false`.
- No `ledger.tsv` exists in the preflight result artifact, confirming no selector runtime was started.

The result also re-proved selector 365/393/397 hashes and exact-prefix relations, static ownership of all 397 identities, immutable artifact digest, GMP/GMPXX package provenance, and the resolved fixture path under the staged execution view.

## Build boundary

There is deliberately **no compile result for CB26**. CD0 freezes the exact CB25 package and forbids rebuild/repackage; compiling would create a different package authority and defeat the correction's purpose. The GitHub action in this turn is a control-plane preflight only, not a product build or runtime gate.

## Next boundary

CB26 is **COMPLETE / ORCHESTRATION CORRECTION VALIDATED / RUNTIME-NOT-EXECUTED / NO REBUILD**. Exact successor: **`M3-CP4c-3-TB23-R1`**, artifact-only execution of the corrected frozen plan against package `9921914679`. The successor after TB23-R1 is independent **`M3-CP4c-3-TB23-R1-REV`**. CP4c-3 remains OPEN.
