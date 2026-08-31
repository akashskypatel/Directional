# M3 CP4c-3 TB3 — Artifact-Only Test + Benchmark Report

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB3`
Status: **COMPLETE / BLOCKED — PRE-RUNTIME PACKAGE EXECUTABLE-MODE CONTRACT FAILURE**

## Authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Immutable semantic/evidence source: `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`
- Immutable GMP package **71**: artifact `9750235004`
- Package Actions SHA-256: `bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`
- Packaged source archive SHA-256: `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`
- Frozen selector 373 SHA-256: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Authoritative preflight run/job: `33399144281 / 99510922630`
- Preflight result artifact: `9760518962`, SHA-256 `ec5bc5cccb99e38e4ce77533478c5864e756735b3511575d843bbafb328f4677`
- Preflight diagnostic log artifact: `9760519355`, SHA-256 `b803c9f81df4a5acbea642860d88f8c61f3df8f13d2204cf836344f6efb1016d`

No Directional process executed. Selector execution is **0/373**. No benchmark, configure, compile, relink, generated discovery, repair, package/source/test/fixture/selector mutation, or semantic adjudication occurred.

## 1. Preflight evidence

TB3 consumed package 71 exactly as frozen by CB3 and stopped before ordinal 1. The preflight independently proved:

- the downloaded Actions artifact SHA-256 is exactly `bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`;
- the complete internal `SHA256SUMS` manifest passes;
- `metadata/source-commit.txt` is exactly `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`;
- the packaged source archive is exactly `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`;
- the package-relative fixture payload is present, including the mechanical and prescribed-sphere assets;
- no runtime, benchmark, configure, compile, relink, generated discovery, repair, or mutation occurred during preflight.

The executable-mode check then found every packaged test/benchmark executable extracted from the immutable artifact as mode **`0644`**:

| Packaged binary | Extracted mode |
|---|---:|
| `bin/directional_benchmarks` | `0644` |
| `bin/directional_compiled_api_tests` | `0644` |
| `bin/directional_surface_cell_authority_kernel_tests` | `0644` |
| `bin/directional_surface_cell_completion_tests` | `0644` |
| `bin/directional_surface_cell_producer_tests` | `0644` |
| `bin/directional_surface_cell_validation_tests` | `0644` |

`non_executable_binary_count=6`; the recorded stop reason is `missing-archived-executable-mode`.

## 2. Boundary and classification

The frozen TB3 plan and `GitHub_Workflow_Policy.md` require artifact extraction to preserve archived executable mode bits and explicitly prohibit `chmod`, repacking, permission repair, package mutation, or replacement compilation inside artifact-only TB. Therefore repairing the binaries in place would invalidate package 71 as TB authority.

This is **not a semantic product red**. Runtime never began, no selector identity was selected, and none of Amendment 16/P2, the mechanical witness, the prescribed sphere, or ordinals 366–373 received runtime evidence.

The defect is recorded as **`M3-CP4c3-TB3-ORCH-01` — ACTIVE / BUILD-PACKAGING CONTRACT DEFECT / NON-STABLE**. The present TB evidence proves the final immutable Actions artifact lacks executable modes; it does **not** yet adjudicate the exact stage where mode authority was lost. That causal tracing belongs to the independent review.

## 3. Regression and accounting disposition

Because there is no semantic verdict and CP4c-3 remains unaccepted:

- stable regression accounting remains **44 events / 14 categories / 30 recurrences**;
- produced-witness debt remains **5**;
- authoritative semantic M3 package accounting remains **70**;
- package 71 remains the CB3 compile/package evidence artifact but has **no runtime gate credit**;
- all previously unproved checkpoint-local identities remain unproved.

`M3-CP4c3-TB2-ORCH-01` is not closed by this attempt: TB3 did not reach a valid runtime fixture-root selection because the packaged executables were not executable.

## 4. Disposition and exact successor

`M3-CP4c-3-TB3` is formally complete as **BLOCKED / PRE-RUNTIME / NO SEMANTIC VERDICT**. CP4c-3 remains **OPEN**.

Exact successor: independent **`M3-CP4c-3-TB3-REV` — REVIEW + PLAN**. The review must determine where executable-mode authority was lost across the raw compile package, fixture-packaging step, and final Actions artifact transport; decide whether a mode-preserving package-only correction can remain byte-identical to the compiled binaries or whether a new Code + Build package is required; and freeze the exact successor plan before any package regeneration, rebuild, or TB retry.

No product/test/build correction, package regeneration, `chmod`, rebuild, or selector runtime is authorized before that review.
