# M4-CP-SCALE-TB5 Review Record

**Turn:** `M4-CP-SCALE-TB5-REV`
**Date:** 2026-09-15 UTC
**Boundary:** Review + successor planning only; runtime-free; no product/test/fixture/selector/benchmark/build-source mutation.
**Decision:** **APPROVE / PROMOTE PACKAGE `10407605295` / ACCEPT SELECTOR424 424/424 / DISCHARGE S2 PUBLICATION OBSERVATION / CP-SCALE OPEN**

## 1. Authority reopened

Review reopened the primary TB5 result/log bytes and the immutable CB6 package instead of accepting the EXEC narrative as authority.

- Candidate package: `10407605295`, provider SHA-256 `29f68b3880fb9d2d521aa74541112af9de5d35fdc982decfdbc8067305e747e5`.
- Semantic source: `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3`.
- TB5 run/job: `35002009539 / 104492480074`.
- TB5 result artifact `10410518189`: provider SHA-256 `7f9f9a4f9b18930255688e775691a21b92538c666a987f29101541aaec1ce3ac`.
- TB5 log artifact `10410672518`: provider SHA-256 `26d59ed6846effe4d38fdc5b2c27b23d95cdf0f6784e8b0ff5d49c212320cc7f`.
- Nested evidence ZIP: fresh SHA-256 `576104efb4aa5723a0384ec7aac0abe0fbc244b8dbb9417a198ea53041040bac`.
- Nested self-excluding manifest: fresh SHA-256 `1aabede920e5401187f8c8590a4969d26694b8fa43cee98c37f29f63b61ea208`, exactly **1298** entries; independent `sha256sum -c` verified **1298/1298**.

Review also materialized a fresh exact current-source snapshot through durable run `35011619748` at control event SHA `5ea774538567db82058067826e48b3ffc1fd97f2`, whose only change from pre-control semantic head `48369b5892827d84a94c19ffcd78747963485fe4` is the temporary snapshot marker. Snapshot artifact `10413618214` has provider SHA-256 `11234f5e3e220491d799dd06a05505a0c6c325f35fcdfbb9f45f132276ff29c0`; its source archive SHA-256 `a96b67bc6e59ea5590371a42763282ab8ef455435460864a0dae48af56536e79` verified all **5276/5276** listed files. This snapshot is static Review authority only and is not runtime/build evidence.

## 2. Selector and prefix authority independently re-derived

The packaged candidate source contains `Architecture_M4_CP_SCALE_CB6_Required_Green_Selector_424.txt` with:

- **424** unique nonblank LF rows;
- SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`;
- rows 1-423 byte-identical to accepted selector423, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- row424 exactly `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`.

A fresh source/CMake parse, independent of the TB5 owner map, resolves every selector identity uniquely and recomputes the owner partition as **30 authority-kernel / 278 producer / 75 completion / 41 validation**. Row424 resolves uniquely to producer target `directional_surface_cell_producer_tests`, source `tests/FieldAlignedCurveNetworkTests.cpp`.

GitHub comparison from previously accepted semantic source `905dabe390577d63ed6a9289e3f3d53aa4144936` to candidate source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3` shows no `src/`, `include/`, `tests/`, `benchmarks/`, `CMakeLists.txt`, or `cmake/` semantic change. Candidate code/test semantics are the already-reviewed TB4 semantics plus selector424 publication and documentation/control-plane history.

## 3. Runtime ledger independently adjudicated

The archived process ledger has exactly ordinals **1..424**, in selector order, with no duplicate or missing identity. Every row records:

- `exit=0`;
- `selected=1`;
- `ok=1`;
- `skipped=0`;
- `result=PASS`.

The execution owner census independently sums to **30 / 278 / 75 / 41**. Therefore the cumulative gate is **424/424 PASS**, with zero RED, SKIP, timeout, crash, selection mismatch, or unexecuted row.

Row424 is fresh TB5 execution, not imported TB4 credit. Its resource receipt preserves the exact command with `GTEST_FAIL_IF_NO_TEST_SELECTED=1` and an exact single-test `--gtest_filter`; raw stdout proves exactly one selected test and one PASS.

## 4. S2 non-vacuity and decision authority re-derived

The row424 test does not use the production comparator to author its expected answer. Its local oracle compares exact integer subject coordinates and maps the exact sign independently to the expected canonical owner. The six archived subjects cover:

| Subject | Exact relation | Oracle sign | Expected owner | Production route |
|---|---|---:|---|---|
| positive strict interior | `1 < 2` | `+1` | `0-1-3` | Filter |
| negative opposite order | `2 > 1` | `-1` | `0-2-3` | Filter |
| near boundary certified | `2^40 > 2^40-1` | `-1` | `0-2-3` | Filter |
| exact boundary | `1 = 1` | `0` | `0-1-3` | ExactFallback |
| tamper-base | `5 > 4` | `-1` | `0-2-3` | Filter |
| tamper-crossed | `3 < 4` | `+1` | `0-1-3` | Filter |

The tamper pair changes exact sign and owner; strict signs appear on both sides; the near-boundary case still certifies through the filter; exact equality defers to exact authority. Both `Filter` and `ExactFallback` therefore execute non-vacuously.

Source audit confirms the production comparator first asks the certified radical-sign filter and, only when it is inconclusive, invokes recursive exact algebraic sign authority; the filter cannot become semantic authority on an unresolved case. The test additionally proves the regular-star preconditions that previously invalidated TB2/TB3 candidates: right-handed face frames, `q4` winding `-1`, aggregate cycle effort approximately `-2*pi` in diagnostics, matching composition zero, no supplied center singularity, atlas success, and valid arrival ownership before the comparator result receives credit.

## 5. Immutable boundary re-derived

Both preflight and postflight verify the package `SHA256SUMS` **28/28**. Package, packaged-source and execution-view byte+mode census files are exact before/after matches; owner executables retain archived mode `0755`. Selector424 and its 423-row prefix are unchanged post-runtime. The execution prohibition receipt records all of:

`configureExecution=false`, `compileExecution=false`, `relinkExecution=false`, `repairExecution=false`, `generatedDiscovery=false`, `mutationExecution=false`, `benchmarkExecution=false`.

No evidence supports a hidden rebuild, repair, discovery, fixture mutation, or benchmark path. TB5 is valid immutable artifact-only evidence.

## 6. Review decision

**PROMOTE** candidate artifact `10407605295` / semantic source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3` as the current accepted M4 runtime authority under selector424 **424/424**. Selector424 is now the accepted/current required-green gate for M4.

**DISCHARGE `M4-CP-SCALE-TB4-REV-OBS-01`.** Its three required conditions are all independently proved: exact selector423-prefix publication, fresh cumulative selector424 424/424 runtime, and this Review. S2 vertex-star certified-filter equivalence now has cumulative selector credit.

No regression/candidate is observed. There is no accepted-green loss and no hidden orchestration invalidity. Stable accounting stays **49 events / 14 categories / 35 recurrences**; produced-witness debt stays **5**.

Promotion does **not** close CP-SCALE. S1 remains diagnostic with no authorized numeric threshold; S2 arrival exact fallback is still undefined; S3, S4 and S5 remain independently open. CP4 later still owns the three `G4-B002` produced-witness debts; two `G4-B003` debts remain M5-owned.

## 7. Prior obligations

| Obligation | Review disposition | Owner / falsifier |
|---|---|---|
| `M4-CP-SCALE-TB1-REV-OBS-01` | **CARRY** | S1 representative/stress calibration before any future numeric gate; no threshold may be guessed. |
| `M4-CP-SCALE-TB2-REV-OBS-01` | **DISCHARGED historically** | TB3 preserved selector423 423/423 unexecuted with exact postflight. |
| `M4-CP-SCALE-TB2-REV-OBS-02` | **CARRY / non-blocking** | Legitimate owner of `make_zero_transport_field` must prove/assert its flat-star precondition without conflating the distinct TB3 authored-winding mechanism. |
| `M4-CP-SCALE-DEFN-OBS-01` | **CARRY** | S2 arrival comparator exact fallback/owner still not frozen. |
| `M4-CP-SCALE-DEFN-OBS-02` | **CARRY -> exact next** | Dedicated exact full-state repeat must publish typed `LimitCycleTermination`; combinatorial recurrence/budget/proximity receive zero credit. |
| `M4-CP-SCALE-DEFN-OBS-03` | **CARRY** | S4 still lacks independent monotone incremental-vs-final oracle and reachable negative. |
| `M4-CP-SCALE-DEFN-OBS-04` | **CARRY** | S5 still lacks a retained genus>=2 produced witness; genus-1 torus receives zero credit. |
| `M4-CP-SCALE-TB4-REV-OBS-01` | **DISCHARGED HERE** | Selector424 exact-prefix publication + fresh 424/424 + independent Review all proved. |
| `M4-CP3-TB1-R1-REV-OBS-01` | **CARRY to M4-CP4** | Independent same-region multiplicity-2 oracle before cumulative CP4 acceptance. |
| `M4-CP3-CB4-REV-OBS-02` | **CARRY** | Legitimate row399 touch/provenance obligation remains with its existing owner. |
| `G4-B002` produced-witness debt | **CARRY 3** | M4-CP4. |
| `G4-B003` produced-witness debt | **CARRY 2** | M5. |

## 8. Exact successor — `M4-CP-SCALE-CB7`

The next bounded variable is S3 only. `Architecture_M4_CP_SCALE_CB7_S3_Exact_Repeat_Code_Build_Plan.md` freezes the implementation/test scope and falsifiers before any edit. CB7 is runtime-free Code + Build. It may implement the typed exact-repeat termination contract and author the frozen S3 identity, but it must not publish selector425 or touch S1/S2/S4/S5 semantics. A green CB7 packages the candidate for a fresh focused S3 + accepted selector424 artifact-only TB6-EXEC, followed by mandatory TB6-REV.

## 9. Consolidation disposition

Durable CP-SCALE facts from the consumed CB6 plan, superseded TB4-R1 report, superseded TB4 Review and consumed TB5 execution plan are preserved in `M4_Consolidated_Record.md` §2.53, this Review, the current TB5 runtime report, tracker/changelogs, frozen definitions and selector manifest. Those four superseded per-turn documents are folded under `CLEAN_UP_POLICY.md`; exact filenames/line counts/verdicts are indexed in §2.53. The current retained role set is one normative CP-SCALE definition record, selector424, the TB5 runtime report, this Review, the CB7 plan, consolidated record and durable project records.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector424 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`; first423 exact accepted selector423 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`. |
| Decisive claims independently re-derived | 1298-entry evidence manifest, exact 424-row process ledger/order/status, 30/278/75/41 owner partition from source+CMake, row424 exact oracle/route matrix, accepted-prefix hash, immutable pre/post censuses and no code/test semantic drift from entering accepted source. |
| Non-vacuity checked | Both strict signs, Filter and ExactFallback, near-boundary filtered case, exact-boundary fallback, owner-changing tamper pair, fresh row424 execution, and 424 exact one-selected processes. |
| Prior obligations discharged/carried | `M4-CP-SCALE-TB4-REV-OBS-01` discharged; every other CP-SCALE/CP3/debt item is explicitly listed in §7 with owner/disposition. |
| Stable accounting | **49 events / 14 categories / 35 recurrences**, debt **5**; accepted package `10407605295` / source `0d8e4aa...678d3` / selector424 **424/424**. |
| New candidates/obligations recorded | None. Tracker records the promotion/discharge and unchanged accounting. |
| ORIENTATION currency line | `M4-CP-SCALE-TB5-REV`, 2026-09-15 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated for selector424 promotion/S3-next; §4 reviewed unchanged because no retained production witness advanced; §8 reviewed with no new defect pattern/instance. |
| CHANGELOG | Root and Directional changelogs updated with Review promotion and exact successor. |
| ROADMAP | CP-SCALE advanced through accepted cumulative S2 selector424; checkpoint remains open; S3 is next. |
| Selector manifest | selector424 marked **CURRENT GATE / ACCEPTED M4 AUTHORITY** with exact selector423 prefix and TB5 promotion receipt; all historical selector files remain retained. |
| LESSONS | No new lesson; existing focused-vs-cumulative gate, exact-state-vs-combinatorial recurrence and one-variable control discipline apply. |
| Consolidation under CLEAN_UP_POLICY | CB6 consumed plan, TB4-R1 superseded report, TB4 superseded Review and TB5 consumed plan folded and indexed in `M4_Consolidated_Record.md` §2.53. |
| Successor frozen | Exactly `M4-CP-SCALE-CB7`; falsifiers/STOP rules are in `Architecture_M4_CP_SCALE_CB7_S3_Exact_Repeat_Code_Build_Plan.md`. |
| Turn boundary held | Yes — runtime-free Review; no product/test/fixture/selector/benchmark/build-source mutation. |
| review_check.py boundary | **GREEN / ALL CHECKS PASSED** on the exact prepared Review delta; no product/test/fixture/build or selector mutation; selector424 exact hash matched. |
| Pushed to origin, branch in sync | Final closeout requirement: after the Review patch and mandatory cleanup land, re-read branch authority and require the working branch to be at the cleanup result with no retained temporary turn state before declaring this turn COMPLETE. |
