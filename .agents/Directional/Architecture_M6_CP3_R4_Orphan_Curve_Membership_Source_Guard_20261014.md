# R4 orphan curve-membership guard — Code + Build record (2026-10-14)

**Canonical turn:** `M6-CP3-CB1-ENTRY-R4` remains IN_PROGRESS. No TB497, runtime test, benchmark, successor, frozen-selector modification, or acceptance promotion is authorized in this record.

## Source and defect

Verified source snapshot [38582206240](https://github.com/akashskypatel/Directional/actions/runs/38582206240), source `e5247330cc71ea1747050a80416868425d3a30cb`, artifact `11903506903`, ZIP SHA256 `20918994757c633cf557d36b00db1ae61c2d7cbd5a201acda7a01a75780bd1d4`, inner archive SHA256 `09b16758aa77e933156252c84d731bba8ec80a3e23d9dd9adabf52560f6393e9`, **5947/5947** source checksums.

The feature-map builder records curve membership as an ordered `AdaptiveFeatureCurve.edges` list and assigns `AdaptiveFeatureEdge.curve`. The first producer `build_authoritative_surface_cell_rails` validated *listed* curve members but later emitted every uncovered rail edge individually, copying `edge.curve` into `rail.curveId` without checking membership. An externally supplied edge that claimed a real curve yet was omitted from its list could publish a wrong-curve standalone rail. This is an input-integrity defect established by static source analysis, not an observed runtime production regression.

## Correction

- `src/pipeline/RemeshPipeline.cpp`: before standalone emission, reject `edge.curve >= 0 && curveMemberEdges.count(edgeIndex) == 0` as `InvalidFeatureEdge`, preserving exact `failedEdgeIndex`. Legitimate unassigned edges (`curve == -1`) remain eligible for standalone rails.
- `tests/SurfaceCellREPackageTests.cpp`: extend the existing standard producer test `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` with a real source-valid standalone positive and a one-field forged curve-claim negative at index 1. Existing test identity and source fixtures retained.
- Exactly two files, **+6/+22** lines; no ABI, status enum, selector, workflow, or other behavior changed.

Full-index patch base `e5247330cc71ea1747050a80416868425d3a30cb`; complete patch SHA256 `0587889c81b6a73e07c961e269675cd91d00ee8d3d110735dab6f275d4042049`; body SHA256 `c6dde7b50b86bcf3e684a6b54a481508058847b69601616acd4cd1fa8c7c3941`. Local diff check, forward apply check, reverse apply check passed; no local builds.

## Remote apply and compile boundary

Drive apply request `6a14638c3e119383d83fa0a4f4485118ea909414`; [workflow 38586594177](https://github.com/akashskypatel/Directional/actions/runs/38586594177) SUCCESS; result artifact `11905487091`, ZIP SHA256 `7fcd63d084b79d9ed450ba7e96c54c9ee01265242a63aee21a75843957754740`; receipt exact patch and base hashes, `runtimeExecution=false`. Applied semantic [f026512e](https://github.com/akashskypatel/Directional/commit/f026512e4599eb9982c1f9afd4292ed429a82eae). Independent compare confirms only the two intended files. Owner-authorized deletion of transient Drive staging file `1xR5Sy4fu1_ebKthlMvAfVRmW5KYTIgXC` succeeded.

Mandatory pinned eight-target GMP/GMPXX compile was **requested**, source `f026512e4599eb9982c1f9afd4292ed429a82eae`, dispatcher commit `ae662ff21811f4b5909d023f44891a966e686598`, mailbox `m6-cp3-r4-orphan-curve-compile`. Its outcome and immutable artifact must be independently reconciled before claiming compile-green. No runtime pass is claimed.

## Carried obligations

RA-43.1 selected A4/A1 branch needs independent Review; RA-43.4 standalone diagnostic first-failure preservation remains unresolved; RA-47.12 observed liveness, historical 39/34/7/88/six, organic D1/D2/D3/D5/A6/A7 and genuine odd-τ multi-carrier remain for separately authorized artifact-only TB. Current canonical turn is unchanged.

---

## Exact-source compile reconciliation — 2026-10-14

The earlier **requested/pending** compile above is superseded by terminal evidence. The pinned [workflow run 38586952664](https://github.com/akashskypatel/Directional/actions/runs/38586952664) completed successfully: compile job `115931534878`, immutable result artifact `11905148938`, ZIP SHA-256 `f4a10d548631ad44a3ec8a4a1fedb59c4f90186471f7503037e232fcc7f7ead1`. Verified exact `source-commit.txt=f026512e4599eb9982c1f9afd4292ed429a82eae`, 28/28 packaged SHA256SUMS, all eight required targets, `preflight-exit-code=0`, `build-exit-code=0`, `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, actual generated linker command with `libgmpxx.so` and `libgmp.so`, five empty source-status snapshots, `runtimeExecution=false` and `turnBoundary=Code+Build-only`. The packaged exact source contains the new orphan guard and existing-test extension. Workflow validation, compile, and mailbox jobs succeeded; test/benchmark execution was skipped.

**Disposition:** Code + Build checkpoint for this narrow guard is compile-GREEN only. No runtime result, acceptance change, frozen 497-selector edit, RA-43.1/RA-43.2 Review bypass, or successor advancement. Continue the same canonical R4 turn; the previously enumerated independent Review and future artifact-only runtime obligations remain open.
