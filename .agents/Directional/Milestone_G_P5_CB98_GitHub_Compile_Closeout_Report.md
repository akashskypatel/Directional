# Milestone G P5-CB98 GitHub Compile Closeout Report

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes + compile-only build closeout

## Disposition

The previously incomplete P5-CB91 through P5-CB98 GitHub-source compile gate is now closed.

GitHub Actions run `30864341083` completed successfully from exact pushed source commit
`680d81c6946f45b1daed9dd477cfde565f8ac7a2`. The checked-out local SHA and remote branch SHA matched exactly, source status was empty before and after compilation, all required submodules were shallowly resolved at their pinned revisions, and the four required targets compiled and linked.

No test, benchmark, custom mesh, help/list command, discovery command, or compiled project binary was executed.

Runtime closure remains pending for P5-TB17, which must consume the packaged artifact without rebuilding.

## Workflow correction and logging policy

The initial closeout workflow revision was malformed because workflow-level `env` referenced the step-only `runner.temp` context. The workflow was corrected to use fixed `/tmp` paths for persistent logs.

Repository policy is now recorded in `.agents/Directional/GitHub_Workflow_Policy.md`:

- detailed activity and command output must be retained on success and failure;
- logging must initialize before other fallible work;
- a dedicated log artifact must be uploaded under `if: always()`;
- failed workflows must be diagnosed from that artifact rather than abbreviated step summaries;
- secrets and credentials must never be exposed by command tracing;
- compile-only turn boundaries remain enforced.

The corrected run uploaded its detailed log artifact successfully.

## Successful workflow evidence

- Workflow: `.github/workflows/agent-build-recovered-p5.yml`
- Run ID: `30864341083`
- Job ID: `91852874765`
- Conclusion: `success`
- Exact source commit: `680d81c6946f45b1daed9dd477cfde565f8ac7a2`
- Started: `2026-08-04T00:04:00Z`
- Compile step completed: `2026-08-04T00:09:12Z`
- Compiler: GNU C++ `13.3.0`
- CMake: `3.31.6`
- Ninja: `1.13.2`
- Build type: Release, `-O2 -DNDEBUG`
- Static libraries; CLI and GUI disabled
- GMP, PARDISO, SuiteSparse, cuDSS disabled
- Build parallelism: `-j 4`

The only log warnings were Eigen repository redirects. No compile or link warning/error was reported by the closeout log.

## Required target results

| Target | Result | Executed |
|---|---|---|
| `directional_core` | compiled and linked | no |
| `directional_pipeline` | compiled and linked | no |
| `directional_phase1_tests` | compiled and linked | no |
| `directional_benchmarks` | compiled and linked | no |

The build completed all `131/131` Ninja actions.

## Compiled artifact

- Artifact ID: `8875627676`
- Name: `surface-cell-p5-cb98-github-source-linux-release`
- Archive size reported by GitHub: `11,603,127 B`
- Archive SHA-256: `b9560c9438289e90e6acca3a0f4b7f1d46a5ad34663693c1243bf4176056c165`
- Retention expiration: `2026-08-18`
- Packaged checksum entries: **38/38 verified** after removing the archive-time `artifact/` prefix from manifest paths
- Packaged fixture files: **26**
- Packaged source status: empty
- Packaged source commit: `680d81c6946f45b1daed9dd477cfde565f8ac7a2`

### Built target hashes

| Artifact | Bytes | SHA-256 |
|---|---:|---|
| `directional_phase1_tests` | 10,853,888 | `c4db631272d5a29a8a88a4fbd26112efb191a5c72017a2f2e9713d2a74276f17` |
| `directional_benchmarks` | 4,865,376 | `153f29beebaa61d9da6f6104eef22271bfd1ba80376a8863d7053ed14ac2a341` |
| `libdirectional_core.a` | 9,446,970 | `acaeeb97672b9956e125b6b40cf16e42dc4e2506518812b4478b292d27afa7f5` |
| `libdirectional_pipeline.a` | 2,906,420 | `6c0c31499a2cd718f117c18abaf02e306aa2408746dc79b9fffafe0363402615` |

## Dedicated workflow log artifact

- Artifact ID: `8875628150`
- Name: `surface-cell-p5-cb98-workflow-logs-30864341083`
- GitHub-reported size: `5,588 B`
- Archive SHA-256: `f31e7d57d137399634187edbac5902732e0226172bc80248c1abf41ff61513e8`
- Uncompressed activity log: `31,765 B`
- Retention expiration: `2026-09-03`

The log records run metadata, exact source/remote equality, tool versions, complete shallow submodule resolution, configure output, all build actions, packaging activity, target hashes, exit code, final source status, and disk usage.

## Dependency revisions

- Eigen: `769c72fd8019e389810d1de1e7c243521a43b594`
- googletest: `3940de91897160fea4815998e08d0fa3c2fb077e`
- polyscope: `59da72df6517cab8379865899bdffdbc96171301`
- GLFW: `e2c92645460f680fd272fd2eed591efb2be7dc31`
- GLM: `0af55ccecd98d4e5a8d1fad7de25ba429d60e863`
- happly: `88f79725d32d78e0e637ebf42d8432d519e1c7d0`
- ImGuizmo: `fb5dec9a5f5c9bb45d908ac3e92c8d26ca105fdc`
- imgui: `922a11f0847fe1a7907345c31a22e0e77a43829c`
- implot: `3da8bd34299965d3b0ab124df743fe3e076fa222`

## Next authority

The next turn is **P5-TB17 artifact-only test and benchmark** using artifact `8875627676` without rebuilding.

P5 remains open until runtime evidence closes parity scope, exact reuse, invalid-midpoint rollback, cylinder topology/output, remaining production outputs, random-bunny pure-quad output, determinism, and peak-RSS ownership reconciliation.
