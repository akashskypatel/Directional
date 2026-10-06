# M6-CP2-TB1-VERIFIER-R2-REV — Independent Review Record

**Disposition:** ACCEPTED / R3 CANDIDATE PROMOTED / M6-CP2 CLOSED
**Promoted package/source:** `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20`
**Reviewed runtime:** `37403703032 / 112076464024`, **491/491**
**Result/log artifacts:** `11387562709 / 11387233341`
**Exact successor:** `M6-DEFN-R5`

## Review authority

This Review selected `READ_MODE=snapshot` before repository source/document inspection. Exact current review snapshot authority is source/event SHA `b26f19d934dd67e6eae26166200b923a86879e14`, workflow run `37409151437`, artifact `11388097916`, provider digest `sha256:b0154733104278a8963878292789677134a7567be911ab41ae8083c0786f3d3b`, archive digest `8f2736d20f8d75d0b5665d0a0f54d05826c7bd846b3df32e0b4c18d8e0a79ad0`, 5476 files, `runtimeExecution=false`.

The immutable candidate package was independently rechecked from artifact `11385836615`. Its ZIP SHA-256 is `40ea2966011865090ce49382300885ee132e82655fba4f98575f326b53ca2ea4`; root `SHA256SUMS` verifies 28/28; semantic source is exactly `c64baacd6c767c4ba053b6963651c0aa6eceed20`; its source archive SHA-256 is `fb7f08f193aa335944c5a3ff460ef481ec9f1dec6cefba676a563d374305bce9`; the command boundary records `runtimeExecution=false` and `exactArithmeticBackend=GMP`; the eight standard targets and GMP/GMPXX link evidence are present; captured source-status receipts are empty.

The current review snapshot's `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/`, and root `CMakeLists.txt` are byte-identical to the candidate's packaged source on those code surfaces. Static review therefore applies to the exact tested semantic candidate.

## Independent runtime re-derivation

The R2 result ZIP matches `dada6a755d4ec6d695ab2b11b13c6d92452d4b1599e9ebda0e6bee751b23fdcf`; the log ZIP matches `5a6950535ec39f20e776759b0c0f1d241ee5228c346ea4d2afc3fe9fcf0b3c39`. The result self-manifest verifies **1005/1005** and hashes to `82943861e169fcdc8589bf13f0e068a663b837997792c454d7a6efb6b5788d7f`.

Independent ledger/raw-log checks establish focused30 **30/30**, CP2-focused12 **12/12**, selector449 **449/449**, aggregate **491/491**, exact-one **491/491**, zero skips and zero REDs. Every ledger `raw_sha256` matches its raw log; frozen identity/order/owner authority matches; `benchmark_execution=false`; configure/compile/relink/discovery/repair/mutation/retry flags are false; package/source/execution-view censuses are unchanged; postflight manifest remains 28/28.

Frozen hashes remain focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Static adjudication of RA-29b/RA-29c recovery

The implementation is faithful to the frozen recovery and introduces no new Review finding.

1. `a0:component-adjacency` and its disconnected-component identity-2 witness are absent; no replacement rule infers ingress component labels from raw connectivity. Accepted selector449 ordinal144 is green.
2. A5 relations carrying `canonicalSelectedStep` require `canonicalRelationValue`, equal step transport, and `Forward` at `a5:selected-step-value`.
3. A6 reconstructs each path's selected-step subsequence from its own ordered relations/orientations and named certificates, using only step inversion and exact composition, and verifies optionality, ordered steps, composed transport and endpoints at `a6:legacy-projection`. The A6→A5 table still exact-binds `selectedRelationStep`.
4. A7 expected paths are grouped once by class from A6 `legacyProjection`s, sorted/deduplicated, and compared exactly at `a7:selected-paths`. The rejected reverse lookup/fallback, target-uniqueness assumption and per-A7 all-path scan are gone; complexity is O(P log P).
5. Relation-class, forest-size/spanning, selected-path reconstruction and map-based topology obligations remain intact.
6. Shared support authority, carried verification report and verified-token downstream reads remain intact.
7. `VerifiedSurfaceProducts` owns A5/A6/A7 values; the self-declared trait is gone. Identity 11 proves address inequality plus record-view equality.
8. Identity 6 retains baseline, relation-transport and >=2-step structure tampers and adds record-changing A7-step, A6-legacy-step and A5-value-only tampers at the three RA-29c sites. All focused12 rows are green.

No A5/A6/A7 producer semantic change was introduced by R3.

## Prior finding closure

- **R1-REV-01:** CLOSED / RECOVERY PROVED — lossy A7→A6 reverse lookup removed; formerly affected accepted rows are green.
- **R1-REV-02:** CLOSED / RECOVERY PROVED — invalid raw-connectivity component rule removed; selector144 is green.
- **R1-REV-03:** CLOSED / RECOVERY PROVED — focused12 identity 6 baseline/tamper chain is green.
- **EXEC-OBS-01:** CLOSED / ORCHESTRATION RECOVERY PROVED — R2 uses its own `TURN_ID`; both result/log artifacts exist and verify.
- **RA-29c T3/T5:** CLOSED — fallback and O(V·P) scan are absent; ownership is behavioral.

These were non-stable recovery/specification defects. No new regression candidate or architecture-debt item is created. Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**.

## Promotion and routing

Candidate `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` is **PROMOTED** as reviewed M6-CP2 authority. M6-CP2 is closed. The exact successor is **`M6-DEFN-R5`**; that turn is not begun inside this Review.
