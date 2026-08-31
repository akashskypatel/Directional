# M3 CP4c-3 CB4-PKG — Package-Only Code + Build Report

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-CB4-PKG`
Status: **COMPLETE / PACKAGE GREEN / RUNTIME-FREE**

## Scope and authority

This turn executed TB3-REV measures AO0–AO5 only. It did **not** configure, compile, relink, execute Directional, run a benchmark, or edit product/test/selector/fixture semantics. The correction is packaging-only: recover the already-compiled executable modes from raw CB3 artifact authority, relocate fixtures from its embedded verified source archive, and place the complete package tree inside a mode-preserving tar envelope.

Frozen semantic/build authority remains:

- semantic source: `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`;
- raw CB3 artifact: `9750227619`, SHA-256 `b1cc9a989af2db84ddd2ad83babf9b2221396e45a165aa84927082e610c351c8`;
- embedded source archive SHA-256: `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`;
- frozen selector 373: `Architecture_M3_CP4c3_Required_Green_Selector_373.txt`, SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.

Package-only workflow authority:

- run: `33411346157`;
- package job: `99551438549` — **success**;
- trigger/control SHA: `157bf5f9bf871e66d8c128c6a11a0b225f446fcf`;
- package 72 artifact: `9765247195`, `m3-cp4c3-package72-33411346157`;
- Actions outer SHA-256: `41ebe4dec4a3eb5c8194900a3f27a0377c3271212edd10fb952c48f55a6a2e6d`;
- `package72.tar.gz` SHA-256: `20630897aa432572d0929022abef3861fff80c2b5792c223071990dd2e3c6a73`;
- package diagnostic artifact: `9765247674`, SHA-256 `95159ade3d83199a7cd0050f00982b2a9cea85e4817621946004ed158e25dea5`.

## AO0 — immutable input authority

The job downloaded artifact `9750227619` as raw Actions artifact bytes through the artifact API, not through `actions/download-artifact`. The downloaded ZIP SHA-256 reproduced exactly as `b1cc9a98…51c8`. Its original `SHA256SUMS` passed in full. `metadata/source-commit.txt` reproduced `93ed2ff…a9b4`; the embedded source archive reproduced `fb3080e5…812fb`; `metadata/command-boundary.txt` retained `runtimeExecution=false` and `exactArithmeticBackend=GMP`; and `metadata/gmp-evidence.txt` retained both `libgmpxx.so` and `libgmp.so` on the authoritative link line.

## AO1 — mode-preserving raw materialization

Before extraction, ZIP Unix attributes independently reported each required runtime binary as `0755`. Standard `unzip` extraction preserved those stored modes without a TB-side repair step. The six extracted modes all re-proved `0755` before fixture relocation.

## AO2 — fixture relocation only

The turn extracted only the raw package's already-frozen source archive and copied its `benchmarks/fixtures` tree to `test-data/benchmarks/fixtures`. The resulting package contains exactly **27 fixture files**, including the mechanical witness and prescribed-sphere assets. No fixture was generated, downloaded independently, or edited.

## AO3 — exact binary byte identity

The same six hashes were proved both before and after fixture relocation, and again after clean extraction of the final tarball:

| binary | SHA-256 | final mode |
|---|---|---:|
| `directional_benchmarks` | `971426cf6846af474df1652d4a64a4bacebcc090bf0c91ed1366ffbcf8720431` | `0755` |
| `directional_compiled_api_tests` | `9eee80431354ba7f6a8122f0755cce40a367219e4596f15be6ea5b891880c07b` | `0755` |
| `directional_surface_cell_authority_kernel_tests` | `319338df85e52036a2a38cf8a515236c13f3d18b205c3f830b3f58a46970be67` | `0755` |
| `directional_surface_cell_completion_tests` | `e895a6bf556a73fd213070095ec44a22a755d22a970208e929f45386cec15ea3` | `0755` |
| `directional_surface_cell_producer_tests` | `23acd5a3bba6355d1a35ab62c9fa817e410be10ee095bedcaada7995ddacf575` | `0755` |
| `directional_surface_cell_validation_tests` | `e8a9bc573c964d09ca24e8691ef4fe1eef93b270451e6f581aae474f820b98f7` | `0755` |

The final self-excluding `SHA256SUMS` has **55 entries** and verifies completely.

## AO4 — mode-preserving package 72 envelope

The complete package tree was archived as `package72.tar.gz`. The workflow then extracted that tarball into a fresh directory before upload and re-proved:

- all 55 internal manifest entries;
- semantic source and source-archive identity;
- GMP/GMPXX and command-boundary evidence;
- 27 package-relative fixture files;
- all six frozen binary hashes;
- all six executable modes `0755`.

The uploaded Actions artifact was then downloaded independently after workflow completion. Its outer SHA-256 reproduced `41ebe4de…2e6d`; its embedded tarball reproduced `20630897…6a73`; a second clean local extraction again passed the 55-entry manifest, source/source-archive checks, fixture count, GMP boundary, six exact hashes, and six `0755` modes.

Recorded boundary flags are `runtimeExecution=false`, `benchmarkExecution=false`, `configure=false`, `compile=false`, `relink=false`, `productMutation=false`, `testMutation=false`, `selectorMutation=false`, `fixtureContentMutation=false`, with only `packagingLayoutMutation=true` for the authorized relocation/envelope operation.

## AO5 — frozen TB3 retry authority

Package **72** is now the immutable runtime package for the TB3 retry. Package 71 remains immutable but unusable as runtime authority and was not repaired in place. `M3-CP4c3-TB3-ORCH-01` satisfies its closure condition and is **RESOLVED / PACKAGE CONTRACT CORRECTED / NON-STABLE**.

Stable regression accounting is unchanged at **44 events / 14 categories / 30 recurrences**, produced-witness debt remains **5**, and semantic M3 package accounting remains **70** because package 72 changes transport/layout metadata only and preserves the previously compiled semantic bytes.

## Successor

Exact next turn: **`M3-CP4c-3-TB3-R1` — artifact-only Test + Benchmark**. It must consume artifact `9765247195`, verify the outer artifact and inner tar authority without repair, extract `package72.tar.gz`, require all six `0755` modes and frozen hashes, then execute unchanged selector 373 from ordinal 1 under one-identity-per-fresh-process and first-red semantics.

No TB3 runtime was executed in this Code + Build turn.
