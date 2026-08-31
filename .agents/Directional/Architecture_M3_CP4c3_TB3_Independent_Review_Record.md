# M3 CP4c-3 TB3 — Independent Review + Plan

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB3-REV`
Decision: **APPROVED WITH AMENDMENTS — PACKAGE-ONLY CODE + BUILD CORRECTION**

## 1. Review question

TB3 stopped before ordinal 1 because immutable package 71 extracted all six test/benchmark executables as mode `0644`. This review independently traces where executable-mode authority was lost and decides whether the correction requires a new compile or only a new immutable package. No Directional process, compile, package regeneration, or validation runtime was executed during this review.

## 2. Primary evidence and causal trace

### Raw CB3 compile artifact retains executable authority

CB3 raw compile artifact `9750227619` (`m3-cp4c3-package71-raw-result-33370966957`, Actions SHA-256 `b1cc9a989af2db84ddd2ad83babf9b2221396e45a165aa84927082e610c351c8`) contains the six runtime executables with ZIP Unix mode `100755`. Direct mode-preserving extraction restores each as `0755`. Their exact SHA-256 values are:

| binary | SHA-256 | raw mode |
|---|---|---:|
| `directional_benchmarks` | `971426cf6846af474df1652d4a64a4bacebcc090bf0c91ed1366ffbcf8720431` | `0755` |
| `directional_compiled_api_tests` | `9eee80431354ba7f6a8122f0755cce40a367219e4596f15be6ea5b891880c07b` | `0755` |
| `directional_surface_cell_authority_kernel_tests` | `319338df85e52036a2a38cf8a515236c13f3d18b205c3f830b3f58a46970be67` | `0755` |
| `directional_surface_cell_completion_tests` | `e895a6bf556a73fd213070095ec44a22a755d22a970208e929f45386cec15ea3` | `0755` |
| `directional_surface_cell_producer_tests` | `23acd5a3bba6355d1a35ab62c9fa817e410be10ee095bedcaada7995ddacf575` | `0755` |
| `directional_surface_cell_validation_tests` | `e8a9bc573c964d09ca24e8691ef4fe1eef93b270451e6f581aae474f820b98f7` | `0755` |

The raw package also carries exact semantic source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, the GMP compile evidence, command-boundary evidence, and source archive SHA-256 `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`.

### Mode loss occurs at the fixture-packaging materialization boundary

CB3 job `99423544681` materialized raw artifact `9750227619` with `actions/download-artifact@v4`, copied the immutable fixture tree into `test-data`, proved binary bytes unchanged, regenerated `SHA256SUMS`, then uploaded the materialized directory as final artifact `9750235004`. The final artifact contains the same six binary SHA-256 values but ZIP mode `100644`.

This is consistent with the official `actions/download-artifact@v4` limitation: Actions artifact download does not preserve file permissions; downloaded files are normalized to `0644`, and the documented preservation mechanism is to place permission-sensitive files inside an archive such as tar before artifact transport.

Therefore `M3-CP4c3-TB3-ORCH-01` is not an unexplained final-artifact defect. Its root cause is **permission metadata loss when the raw compile artifact is materialized by `actions/download-artifact@v4` during fixture packaging and that normalized directory is re-uploaded as the final package**. Binary bytes were never changed.

## 3. Adjudication

A replacement compile is **not justified**. CB3 already produced exact GMP/GMPXX compile evidence for semantic source `93ed2ff...`; raw artifact 9750227619 independently retains the intended executable mode and exact binary bytes. Recompiling would add unnecessary semantic/build variance to a transport-only correction.

A byte-identical **package-only Code + Build correction is valid and preferred**, provided it takes mode authority from the raw compile artifact, proves binary byte identity, and produces a mode-preserving immutable envelope. Package 71 must not be repaired in place and TB must not perform `chmod`.

## 4. Frozen successor — `M3-CP4c-3-CB4-PKG`

The next turn is a runtime-free package-only Code + Build correction. No product, test, benchmark, selector, fixture-content, or semantic source edits are authorized. No replacement compile is required.

### AO0 — immutable input authority

Consume only raw compile artifact `9750227619` with outer SHA-256 `b1cc9a989af2db84ddd2ad83babf9b2221396e45a165aa84927082e610c351c8`. Verify its complete internal manifest, semantic source `93ed2ff...`, source-archive digest `fb3080e...`, GMP/command-boundary evidence, all six exact binary hashes above, and mode `0755` after a mode-preserving extraction.

### AO1 — do not normalize the package directory

Do not use `actions/download-artifact` as the materialization path for the permission-sensitive package tree. Download the raw artifact ZIP as immutable bytes through the Actions artifact API, verify its outer digest, and extract it with a mode-preserving ZIP implementation. A failure to recover all six `0755` modes is a package-build failure.

### AO2 — fixture relocation only

Populate `test-data/benchmarks/fixtures` from the raw package's already-verified embedded source archive. Do not regenerate, edit, or fetch fixtures independently. Require the same 27-file fixture tree and the mechanical/prescribed-sphere assets.

### AO3 — byte identity

Hash every packaged executable before and after fixture relocation and require exact equality to the six frozen hashes above. Regenerate the package's self-excluding `SHA256SUMS` only after fixture relocation.

### AO4 — mode-preserving final envelope

Create a single `package72.tar.gz` containing the complete package tree. Before upload, extract that tarball into a fresh directory and re-prove: internal manifest; semantic source/source archive; GMP/command-boundary evidence; fixture tree; all six binary hashes; and all six modes `0755`. Record `runtimeExecution=false`, `benchmarkExecution=false`, `configure=false`, `compile=false`, `relink=false`, and all mutation flags false except the authorized packaging layout/metadata operation. Upload the tarball plus its digest/result metadata; do not rely on Actions artifact entry modes for files inside the tarball.

### AO5 — TB3 retry authority

On successful package-only closeout, freeze package 72 by artifact ID, Actions outer digest, tarball SHA-256, semantic source, source archive, selector 373 digest, and exact binary hashes. The successor TB3 retry must extract the tarball without repair, prove the six `0755` modes and all immutable authority, then execute the unchanged selector 373 from ordinal 1 under the existing one-identity-per-fresh-process / first-red contract.

## 5. Prohibitions

- Do not edit production/test/benchmark/selector semantics for ORCH-01.
- Do not rebuild merely to recreate executable bits.
- Do not mutate package 71 or claim it gained runtime authority.
- Do not use `chmod` or equivalent mode repair in TB.
- Do not infer green/red product semantics from the pre-runtime TB3 attempt.

## 6. Review disposition

`M3-CP4c3-TB3-ORCH-01` is **ROOT CAUSE ESTABLISHED / AWAITING PACKAGE-ONLY CORRECTION / NON-STABLE**. Stable regression accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt remains **5**, and semantic package accounting remains **70**.

Exact next: **`M3-CP4c-3-CB4-PKG`**.
