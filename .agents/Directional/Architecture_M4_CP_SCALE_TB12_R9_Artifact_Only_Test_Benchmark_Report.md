# M4-CP-SCALE-TB12-R9-EXEC — Artifact-Only Test + Benchmark Report

**Disposition:** COMPLETE / VALID SEMANTIC RED / REVIEW REQUIRED / FAIL-FAST
**Authoritative run/job:** `35353935259 / 105628563418`
**Control/event SHA:** `c5375a4c4c453f23d3d3348d648d8dd76d8e8c11`
**Immutable candidate:** artifact `10548849094` / semantic source `ec348a1d13f96764da5674b66a3ce314a4a8c2cb`
**Frozen harness:** Drive `1QVKAZi47Gg2UpR7L2zU79FQrG9e8tU7T` / 18,479 bytes / SHA-256 `f7632ec246cbb0174ee3832adc77861f0d98c9dc66ef10cb24623f1d08cdfad7`
**Mandatory successor:** `M4-CP-SCALE-TB12-R9-REV`

## 1. Artifact-only boundary and preflight

R9 consumed only the immutable CB22 candidate. It performed no configure, compile, relink, generated discovery, package/mode repair, source/test/fixture/selector mutation, or benchmark execution. The frozen 436-row ledger was initialized before generated Directional runtime and the first valid semantic RED stopped all later rows.

Preflight reverified candidate artifact `10548849094` / `m4-cp-scale-cb22-result-35351112557` with provider/local ZIP SHA-256 `f63c20ab184e78fa0cabcd89df7844a6fdaeacdba31691f3d51b39fec9bb1aa5`, semantic source `ec348a1d13f96764da5674b66a3ce314a4a8c2cb`, packaged source archive SHA-256 `7f1639a93e7e7cec72b9150e7971363522fe7cbbf2db2a9e0d281a474f29accd`, and 28-entry root manifest SHA-256 `01183587ecef192a1343d24692fc4cee749a023e6be8f6b89078f0c9f281b3c8`; all 28 entries verified. Six packaged executables retained mode `0755`, two static libraries retained mode `0644`, and the package retains GMP/GMPXX compile/link authority with `runtimeExecution=false` from Code + Build.

Selector426 reverified as 426 rows with SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; first425 remains `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; static owner census remains **30 / 280 / 75 / 41**. The retained genus-two OBJ/rawfield/metadata hashes remain `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, and `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

## 2. Valid semantic RED and fail-fast ledger

Gate A0 row1 executed exactly once in a fresh process:

`FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle`

The process selected exactly one test, skipped zero, exited `1`, and failed `ASSERT_TRUE(built)` at `tests/FieldTransportAtlasTests.cpp:2612` with the exact product diagnostic:

```text
code=SingularityMismatch;sourceVertex=1;topologyRegion=1
```

The process stdout SHA-256 is `19c3fab3407ae3d0cd4af718922dd3a891807e67032cb5e4b759e00693c089d4`; stderr is empty with SHA-256 `e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855`.

Fail-fast leaves the complete ledger at **0 PASS / 1 RED / 0 orchestration / 435 UNEXECUTED**:

- Gate A0: 0 PASS / 1 RED / 4 UNEXECUTED;
- Gate A: 0 PASS / 0 RED / 4 UNEXECUTED;
- S5: 0 PASS / 0 RED / 1 UNEXECUTED;
- selector426: 0 PASS / 0 RED / 426 UNEXECUTED;
- benchmark execution: 0.

Final ledger SHA-256 is `254c0f2a6e89d5ebaad9c4534d5be699a34832dd7081a64c8b6476a9d528a41c`.

## 3. Immutable postflight

R9 records `orchestration_failure=false`, `semantic_red=true`, `runtime_started=true`, and `postflight_complete=true`. Prohibited-operation counters remain zero: configure, compile, relink, generated discovery, package repair, mode repair, mutation, and benchmark execution.

The exact pre/post censuses are byte-identical:

- package census SHA-256 `aebb0fc257d38aee38e593c0a207b3292ba36cf8c242c672cbfeee935dc0143e`;
- semantic-source census SHA-256 `21a4447052bb41f9ec5997e695f576661fc2fd6a25ddaa82d83de44e841040c1`;
- execution-view census SHA-256 `fe6efcc10eb9d07f20c0f6537bbfa43f93bbb18e37c497985d90b48fcaa93813`.

No package or execution-view byte or mode changed.

## 4. Evidence authority

Authoritative result artifact `10550642712` (`m4-cp-scale-tb12-r9-result-35353935259`) has provider/local ZIP SHA-256 `8a9bf09e1acc592c179cca2969419da242d44d7a1cba97b3d83410cc5702d650`. Authoritative workflow-log artifact `10550482686` has provider SHA-256 `3b953803a573daa7d6abe06f2d9af49b698c13d28ea95594695818ee3817b806`.

The result artifact's 16-entry manifest verifies 16/16 after download. Its nested evidence archive has SHA-256 `8ad81edde045dfba69a61d21f2849ebd78abc70c2364fcaa1a817c6801d72371`; the nested 16-entry manifest has SHA-256 `3e19e4cf6b96c61ff7852a5a27835716255bca9ef2d9b553f44c9678ece7c7fd` and verifies 16/16 after extraction.

The published execution caller and prevalidated draft share Git blob `471690649e03f69b9b8baecb2ef07d84d2f287b6`. The exact frozen harness was re-fetched before runtime as 18,479 bytes with SHA-256 `f7632ec246cbb0174ee3832adc77861f0d98c9dc66ef10cb24623f1d08cdfad7`.

## 5. Regression/accounting disposition

R9 establishes a new **non-stable semantic regression candidate** at `SingularityMismatch;sourceVertex=1;topologyRegion=1` in the producer-consistent CB22 direct control. EXEC does not classify the failure as product, test-authority, recurrence, or a new stable category. It also does not decide whether CB22's intended `RP-02` correction is recovery-proved. Those decisions belong exclusively to mandatory Review.

Because Gate A0 row1 is RED, S5 and selector426 did not execute. Production `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01` therefore remains OPEN and S5/A3 remain uncredited. Candidate artifact `10548849094` remains unpromoted. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**, and accepted runtime authority remains TB11 package `10473134357` / selector426 **426/426**.

## 6. Mandatory Review boundary

`M4-CP-SCALE-TB12-R9-REV` must independently reopen candidate artifact `10548849094`, result/log artifacts `10550642712 / 10550482686`, the exact raw row1 output, the complete 436-row fail-fast ledger, frozen harness/caller authority, package/source/selector/fixture preflight, and immutable postflight. Review must determine what `SingularityMismatch;sourceVertex=1;topologyRegion=1` means for the producer-consistent CB22 control and `RP-02`, whether it is product or test authority, its relationship to existing regression categories, and whether any definition stop or corrective turn is authorized. No corrective Code + Build turn, retry, package promotion, selector427, S5/A3 credit, or stable-accounting change is authorized before that Review.
