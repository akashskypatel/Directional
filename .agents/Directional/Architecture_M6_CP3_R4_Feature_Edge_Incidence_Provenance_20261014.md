# M6 CP3 R4 — Exact source-edge incident-face provenance (2026-10-14)

Canonical **M6-CP3-CB1-ENTRY-R4** remains IN_PROGRESS Code + Build. PR #8 is draft and open; TB497, runtime execution, frozen selector 497, accepted counts, and successor remain untouched.

## Source finding and correction

`src/pipeline/RemeshPipeline.cpp::build_authoritative_surface_cell_rails` previously accepted a feature edge's first valid claimed incident face if its source component matched. An additional foreign or omitted incident face remained undetected. This allows mutually coherent feature-edge/curve labels to hide incorrect source support.

The producer now compares the **complete** claimed `incidentFaces` multiset, sorted without dependence on input ordering, against the source mesh's independently enumerated edge-to-face incidence before emitting any rail interval. Missing, duplicated or foreign support rejects with the existing `InvalidFeatureEdge` and original edge index. No schema/ABI or status changes.

The existing mandatory `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` test now includes a genuinely disconnected two-face source with one edge's `incidentFaces={0,1}` forged: face zero supports that edge; face one does not. It demands first-edge rejection. Existing valid two-component rail cases remain unchanged.

## Evidence

Verified source-snapshot workflow [38553375138](https://github.com/akashskypatel/Directional/actions/runs/38553375138) at `36e2594106e8eb8bbbd5b69f9eb465c6ca38fd6d`, outer digest `7bc996717c5b2a8e3a2700314ca0aa414753234f60b3c6e439b8a4818e310692`; inner tar verified, 5,884/5,884 manifest files verified. No local build/test.

Initial patch apply [38554338954](https://github.com/akashskypatel/Directional/actions/runs/38554338954) failed after download/hash verification in expected-path inventory: its `intended_paths` used a comma, but dispatcher uses semicolons. No source commit pushed. Corrected self-describing exact-source patch SHA-256 `8b1c33109f757d2af07bc06edc4cf627ffffdb9f6fdb3b6f4e24665a845c7119`, body SHA-256 `da1c4a681735d29e18bcef764398409ec93b0d8cc2a4b929cd2e496d119b0338`. It passes `git diff --check` and reverse `git apply --check`. Backup: ChatGPT Library `/Directional/Evidence/Directional_R4_Exact_Source_Incidence_Corrected_20261014.patch`.

Corrected [apply 38554647517](https://github.com/akashskypatel/Directional/actions/runs/38554647517) is SUCCESS, exact result artifact `11887709322`, SHA-256 `d33a0226abf90e68938c70bd6934e12b2231d87b772f919b28345e9094ee3b5f`, source semantic commit **`df4221ba68f7a398413cdb4a0f9be42c485bb527`**, `runtimeExecution=false`.

Eight-target GMP/GMPXX **compile requested** through durable dispatcher at event commit `557ba216eebdeb15fb68ea9a6d020796414f828d`, mailbox `m6-cp3-r4-source-rail-incidence-compile`; do **not** claim GREEN until immutable artifact and job verification. Compile exact semantic source `df4221ba68f7a398413cdb4a0f9be42c485bb527`. Test/BM execution prohibited in this turn.

## Carry forward

RA-43.1/RA-43.2 A4-selected A1-admitted source branch and filled-side receipt needs independent Review; do not invent field-branch identity. Remaining RA-43.4 source consumers, RA-47.12 executed liveness, 39 endpoints, 34 Phase10, seven DCEL, 88 CP2 accepted, six CP3, D1/D2/D3/D5/A6/A7 and organic odd-τ multicarrier require source evidence and separately authorized TB. Maintain canonical R4, frozen 497 and no successor.