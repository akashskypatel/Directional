# M4-CP-SCALE-TB4-EXEC Artifact-Only Test + Benchmark Report — orchestration-invalid attempt

**Status:** COMPLETE / ORCHESTRATION INVALID / NO SEMANTIC LEDGER / CANDIDATE UNPROMOTED / CP-SCALE OPEN
**Turn type:** Test + Benchmark EXEC only; immutable candidate artifact
**Run / job:** `34938070127 / 104280301940`
**Candidate:** artifact `10378808176`, semantic source `905dabe390577d63ed6a9289e3f3d53aa4144936`
**Exact successor:** `M4-CP-SCALE-CB5`

## 1. Disposition

TB4-EXEC is mechanically invalid because its runner-only execution view did not reproduce the packaged fixture path contract and its postflight receipt used an inconsistent census filename. This attempt therefore produces **no semantic ledger credit** under `Turn_Cadence.md` rule 5. The candidate package is not promoted, the focused S2 PASS is only an observation from the invalid attempt, and the 40 selector RED observations are not product regressions.

Accepted runtime authority remains package `10360085644` / semantic source `a359b981f9350139304bc5a654041dfba78609b6` / selector423 **423/423**. Stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

## 2. Immutable input and preflight

The execution consumed the exact CB4 package:

- artifact ID/name: `10378808176` / `m4-cp-scale-cb4-result-34923091581`;
- provider ZIP SHA-256: `a60fbbb7127b2fb36952cc9fef8d58cce366204ffbcbdcd7ace2de69ff7e488a`;
- semantic source: `905dabe390577d63ed6a9289e3f3d53aa4144936`;
- packaged source archive SHA-256: `e604279d0754e44d7aa02c7d1418e73cd23ec5fd5599b05b0bda929da248428d`;
- package manifest SHA-256: `b3364c9a0ce63f497a942b4ed8739403e4b4e9541ccf5b4faf13aab1a72f587f`, 28 self-excluding entries;
- selector423: 423 LF rows / `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- first422: `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- owner census: **30 authority-kernel / 277 producer / 75 completion / 41 validation**.

Preflight verified package checksums, source/compile metadata, clean source-status receipts, GMP/GMPXX evidence, exact source archive, selector lineage and all owner binaries before runtime. No configure, compile, relink, repair, generated discovery, benchmark or mutation occurred in this Test + Benchmark turn.

## 3. Focused S2 observation — PASS, but no semantic credit

Focused `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle` selected exactly one test and returned **1/1 PASS**. Its six receipts observed the intended regular folded-star invariants: independently reconstructed `q4` winding `-1`, wrapped phase sum approximately `-2*pi`, aggregate cycle effort approximately `-2*pi`, center cycle lift zero up to floating diagnostic roundoff, matching-cycle composition `0`, and both comparator routes (`Filter` and `ExactFallback`) across the positive/negative/near-boundary/exact-boundary/tamper subjects.

Because the same TB attempt later failed its mandatory immutable execution-view/postflight contract, this focused PASS is **not promoted or credited**. It is retained only as failed-attempt evidence for the exact retry.

## 4. Selector423 observation — 383 PASS / 40 RED, all invalidated by one fixture-layout defect

The frozen loop launched all 423 selector rows exactly once with no timeout, skip or selection mismatch:

- PASS: **383**;
- RED: **40**;
- SKIP: **0**;
- timeout: **0**;
- selection mismatch: **0**;
- UNEXECUTED: **0**.

Every one of the 40 RED logs contains the same runner-harness exception:

`Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/m4-cp-scale-tb4-exec/view/bin`

The first occurrence is ordinal 41, `MilestoneGP26.PrescribedSphereSingularitiesMatchRecoveredValence`. The payload copied packaged `benchmarks/fixtures` into `view/test-data/benchmarks`, yielding `view/test-data/benchmarks/<fixture-family>/...`, while `tests/TestFixturePaths.h` requires either sibling or legacy layout ending in `test-data/benchmarks/fixtures`. The required immutable fixture bytes were present; the runner-only directory shape was wrong. Therefore the 40 rows are one **orchestration/execution-view** failure class and receive no product-semantic or stable-regression credit.

## 5. Mandatory postflight failure — receipt basename mismatch

After selector execution, the payload re-verified the package `SHA256SUMS` successfully. It then failed the mandatory postflight census comparison with `FileNotFoundError` because preflight wrote `execution-view-before.tsv` while `postflight()` required `execution-view-census-before.tsv`. Final mechanical exit was `97`, `postflightPass=false`.

Independent evidence reconstruction shows the actual before/after censuses are byte-identical despite the failed receipt lookup:

- package census SHA-256 before/after: `2445ee8602cb38ce87aaa79bdecf89d70512a1bee1cecc813d9eb6ccde26ebe2`;
- source census SHA-256 before/after: `8b4676a77d47ee07414558a65fc447098b4b2a153a9b80a24aadafe6bfabfe33`;
- execution-view census SHA-256 before/after: `87f592f876dee801d6b5b4ed78954f38fea5dde1872cf50a848f217460efbd22`.

That proves the immutable inputs did not drift, but it does **not** retroactively satisfy the frozen postflight contract. The entire attempt remains orchestration-invalid.

## 6. Evidence identities

- workflow run: `34938070127`;
- execute job: `104280301940`;
- result artifact: `10384800591`, provider SHA-256 `3c6b5cc9ae54f8ebc0bfed9d4097003dbd0250f8cfc3053a89ad3ef95ca27065`;
- diagnostic log artifact: `10384696446`, provider SHA-256 `79abfc66e2d7883444a60fcccc81b904e11ca378b93f2bd94abebdd8e76d810b`;
- nested evidence ZIP SHA-256: `ee5948335006b10e4f00d295e181489a6b9352634df26952f4c52dacf7c8e0ca`;
- trigger/control commit: `1ecf5398a75ad4c8fdbc2aee9e57fdc37a424571`.

The evidence manifest verifies the stored focused log, complete 423-row process ledger/raw logs, resource receipts and pre/post censuses.

## 7. Regression/candidate classification

`M4-CP-SCALE-TB4-EXEC-CAND-01` — **OPEN / ORCHESTRATION / EXECUTION-VIEW FIXTURE LAYOUT / NON-STABLE**. Corrective owner: `M4-CP-SCALE-CB5`; materialize the packaged fixture subtree at the path contract required by `TestFixturePaths.h` without changing source/test/fixture/package bytes.

`M4-CP-SCALE-TB4-EXEC-CAND-02` — **OPEN / ORCHESTRATION / POSTFLIGHT RECEIPT-NAME MISMATCH / NON-STABLE**. Corrective owner: `M4-CP-SCALE-CB5`; make the execution-view census filenames internally consistent and fail closed before retry if the static contract is inconsistent.

Both candidates add **+0 events / +0 categories / +0 recurrences**. No accepted PASS became a semantic RED because this attempt is invalid before semantic accounting.

## 8. Cadence and exact next

The frozen TB4 execution plan named Review as the ordinary successor after a valid mechanical attempt. This attempt instead satisfies the durable `Turn_Cadence.md` orchestration-failure branch, which was user-authorized on 2026-09-04: **orchestration failures route to Code + Build control-plane correction, not semantic Review**.

Exact next is `M4-CP-SCALE-CB5`, runtime-free orchestration correction only. If CB5 statically verifies both harness fixes without changing the immutable candidate, exact next becomes a fresh full `M4-CP-SCALE-TB4-R1-EXEC` from process 1 on the same artifact `10378808176`. No semantic row or focused result from this invalid attempt may be reused as acceptance evidence.
