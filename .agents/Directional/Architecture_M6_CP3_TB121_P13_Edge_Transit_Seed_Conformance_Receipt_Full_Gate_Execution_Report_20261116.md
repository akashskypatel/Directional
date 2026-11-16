# TB121 — edge-transit seed conformance receipt, full-gate execution (2026-11-16 UTC)

## Situation

**Scoped MATCH** under [RA-240 §6](Architecture_M6_CP3_DEFN_P13_Vertex_Transit_Outflow_Outcome_Review_20261116.md). The immutable CB140 artifact completed the 947-case gate and three-case production census. The single new diagnostic records an AX1 carrier-ray election difference at BunnyRandom vertex 137. It does not change the decision. This turn does not accept CP3 or promote selector 497. **Next, in a separate turn:** Review-only `M6-CP3-DEFN-P13-EDGE-TRANSIT-SEED-CONFORMANCE-OUTCOME`.

## Background — frozen authority

- Compiled source `6a293e4641a2160cb9f447322c9aa1d1d26f3838`; immutable CB140 package `14206223032`, outer SHA-256 `98acb75fbed52ab6909be65d165310ac8dfe0c75a5be5117aed473c4fd7db089` (28/28 source and binary checks, GMP/GMPXX, eight targets, compile-only in CB140).
- Executor snapshot commit `d5003476c4df52863eeb14b841a729653369bc9b`, [run 43827493361](https://github.com/akashskypatel/Directional/actions/runs/43827493361), artifact `14207441611`, outer SHA-256 `20edb79e01f5385b19b5597d42627e9a30176886d4340b5c17bae0447cf0cf4e`, 5,554/5,554 source files verified. Temporary trigger was removed.
- **Full gate:** [run 43827835396](https://github.com/akashskypatel/Directional/actions/runs/43827835396), event SHA `bd26a6c3a490106fe50a3a82ec4bc8c0019139eb`, result artifact `14208145885`, outer SHA-256 `6b51264d88b292d059aa3cc32a755f99e3b0920023683d5b85817e013b0c489a`. Original manifest `3aac432b9f466e5ce06601c90a08ad09c1886dfeb97c38b05e9bd46f51a1190b`, 947 cases, membership 1,028.
- **Census:** [run 43827920795](https://github.com/akashskypatel/Directional/actions/runs/43827920795), event SHA `4d7804ce57786f81e42162af98fc0987e88e865f`, result artifact `14208251561`, outer SHA-256 `f8f1fbfa66df17c62723af0713189d40b076a204bd4f57cb5d8a4f15dfa3ffab`. Original three-case manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- Both mailboxes on ref `workflow-mailbox` confirm their exact event SHAs, source SHA, artifacts, and success. Both execution boundaries show `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, `exit=0`, and `postflight=true`; no source/test/fixture/selector modification or rebuild.
- Independent TB120 comparison: gate artifact `14199814782` (SHA-256 `fd52e7909650c25466eab857e9473fd2c448b502a25ad99df1fca02530cf7206`); census artifact `14201142306` (SHA-256 `4d680693e516a34a68037d24028de2a215042f34f3f9e93f5aa87288b7b90aec`). Their internal checks were 1,902/1,902 and 9/9, respectively.

## Assessment — independent output comparison

| Item | TB121 result | Comparison with TB120 |
|---|---|---|
| Full gate | **947/947 PASS**, membership 1,028; 1,902/1,902 checksums; no R1 | 0 semantic ledger differences; no conformance lines |
| Census | Cylinder PASS; BunnyRandom RED; Vase RED; 9/9 checksums | 0 semantic ledger differences; verdicts 1 PASS, 2 RED |
| Existing diagnostic receipts | 23 R1/sector + 16 partition edgePort + 16 edgePortDeparture = **55 lines** | **55/55 exact string matches in order** |
| BunnyRandom terminal | `NotProductionReady:field-aligned-network / BranchContinuationDegenerateEntry` at vertex 137, edge (137,149), parameter 0/1 | Exact terminal and locus line matches |
| Vase terminal | `NotProductionReady:completion / AggregateCompletionValidationFailure`, 189462 trace segments, 26817 cells, 67750 quads | Exact terminal line matches |
| New seed receipt | Gate 0; census row 2 one `modeled=1`, no `modeled=0` | New diagnostic is measured, not an acceptance change |

All required gate cases were executed once; no missing, skipped, duplicate, abnormal, or unexpected pass. Gate raw `log_sha256` differs for 229/947 rows; census log hashes differ in all three rows. This does **not** establish a semantic change: after excluding log hashes, all ledger fields match, and the frozen receipt and terminal comparisons pass. We do not claim byte-identical raw logs.

**New diagnostic — observed verbatim, census row 2:**

```text
FieldAlignedCurveNetwork.edgeTransitSeedConformance singularity=12 sourceVertex=138 trace=51 step=0 vertex=137 carrierEnd=138 modeled=1 codeOwner=3 carrierOwner=4 carrierOnRadialRay=0 codeOwnerLeaves=0 carrierOwnerLeaves=1 sectors=6
```

The census contains exactly one `edgeTransitSeedConformance` line: row 2, `modeled=1`. No `modeled=0` reasons occur. Rows 1 and 3 contain no line. All 947 gate rows contain no line. Prediction Q1 (trace 51 at vertex 137, owner 3 versus 4, with carrier owner leaving) is observed. Prediction Q2 (no such line for traces 24 or 99) also holds. Q1 and Q2 remain predictions, not new requirements.

**Regression classification:** No new accepted regression is established. The first failure and the accepted gate remain unchanged. BunnyRandom's P13-e terminal remains a **non-stable candidate**. Its measured seed nonconformance is owned by O44; vertices 349 and 48 still require design decision D12. The stable ledger remains 66 events / 17 categories / 49 recurrences, produced-witness debt 1, deferred 81. Accepted CP2 stays 491/491; CP3/selector497 is not promoted. `chainRimSchedules=false`.

## Recommendation

Preserve the immutable artifacts and exact diagnostic text for independent Review `M6-CP3-DEFN-P13-EDGE-TRANSIT-SEED-CONFORMANCE-OUTCOME`. That Review decides whether to switch the AX1 seed and asks D12 again if pending. Do not implement D12, change the producer switch, or begin Review work in TB121. Carry O42/O43/O44, D11=A, D10 deferred, D6 pending, and the unchanged ledgers.
