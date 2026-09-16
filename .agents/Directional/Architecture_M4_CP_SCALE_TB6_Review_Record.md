# M4-CP-SCALE-TB6 Review Record — S3 focused proof accepted for selector publication

**Turn:** `M4-CP-SCALE-TB6-REV`
**Boundary:** Review only; runtime-free; no product/test/fixture/selector/benchmark/build-source mutation.
**Decision:** **ACCEPT / PROMOTE PACKAGE UNDER UNCHANGED SELECTOR424 / ACCEPT S3 FOCUSED CONTRACT FOR SELECTOR425 PUBLICATION / CUMULATIVE SELECTOR425 CREDIT STILL OWED.**
**Exact successor:** `M4-CP-SCALE-CB8` under `Architecture_M4_CP_SCALE_CB8_Selector425_Publication_Code_Build_Plan.md`.

## 1. Entering authority and reviewed candidate

Entering accepted M4 runtime authority was TB5 package `10407605295` / semantic source
`0d8e4aa3472fae26c22d49bc0d81acc5e98378d3` under selector424 **424/424**, selector SHA-256
`f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca` and exact selector423-prefix
SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`.

TB6 reviewed the CB7 candidate:

- candidate artifact `10418328122`, provider SHA-256
  `a9f33bce6029022495fccbc4680da9bdd25cf41aa5cc733b2c04335e156ac16e`;
- semantic source `153047c3f92e9b9b784e11eaee1ede2de5628470`;
- packaged source archive SHA-256
  `703dcc22f18ed565b623ef4eb43e117cd8acfd5d982ed0bde111d5cfdd56e0ff`;
- package-manifest SHA-256
  `d5e2e620f3e5a9e78f4b646be95f872dd78ab8cbee7fe726156abf8249d6d5ad`, **28/28**;
- authoritative runtime retry run/job `35036993863 / 104608250744`;
- result artifact `10423717019`, provider SHA-256
  `239886ce2918ce97416d01b8e7e390210c284acfc608c53b7531fc99a8854e8d`;
- log artifact `10424430214`, provider SHA-256
  `b1b8353968a496ff6e7673dba7209971b04f7b205f8316855e91e8e6ea0fa935`;
- nested evidence ZIP SHA-256
  `6e70e20405bb5d1ab605c0fb49636bffce15a970c10fe842bf9ce1a5759310e9`;
- self-excluding evidence-manifest SHA-256
  `3b05c4105cbdbe120e105bc0ca120e3fc46e98e102c4b5151e7c42fab4c0dfe7`, **1302/1302** entries independently verified.

## 2. Independent artifact and selector re-derivation

Review reopened the exact candidate/result/log bytes rather than accepting the EXEC report as authority.
The candidate provider digest, 28-entry package manifest, semantic-source marker and source archive all re-hash to the
values above. Package metadata independently confirms `runtimeExecution=false`, `exactArithmeticBackend=GMP`, and
GMP/GMPXX linkage.

Selector424 independently re-hashes to
`f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`; it has exactly **424 unique LF rows**.
Its first 423 rows re-hash to accepted selector423
`4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`; row424 is exactly
`M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`. The focused S3 identity is absent from
selector424. No selector425 exists in the reviewed source.

Review independently rebuilt target ownership from packaged source plus `cmake/DirectionalTests.cmake` and packaged
`TEST*` definitions. The 424 selector rows map one-to-one to **30 authority-kernel / 278 producer / 75 completion /
41 validation**. The S3 focused identity has exactly one packaged definition, in
`tests/FieldAlignedCurveNetworkTests.cpp`, owned by producer binary `directional_surface_cell_producer_tests`.

## 3. Independent runtime-ledger audit

The focused ledger contains exactly one process row. It selected exactly one S3 test, exited 0, passed 1/1, skipped
zero, and emitted the frozen receipt exactly once:

`m4CpScaleS3;exactRepeat=LimitCycleTermination;differentExactEntry=Advanced;loadBearingTamperCount=4;combinatorialRecurrence=TraceCombinatorialRecurrenceExceeded;stepBudget=TraceStepBudgetExhausted`

Review then independently compared all **424** selector process rows with selector424 in ordinal order. Every identity,
owner and packaged source definition matches the independently derived map. Every process has a unique raw stdout/stderr
path, exit 0, selected=1, passed=1, skipped=0 and result `PASS`. Review reopened every raw stdout and confirmed its exact
GoogleTest filter/RUN/OK/PASSED identity. Final totals are **424/424 PASS**, zero RED/SKIP/crash/timeout/selection
mismatch/unexecuted, plus the one separate focused process: **425 total runtime processes = 1 focused + 424 selector**.

Package census before/after is byte-identical; semantic-source census before/after is byte-identical; execution-view
census before/after is byte-identical. Both package checksum passes are 28/28. The execution receipt independently
confirms `configureExecution=false`, `compileExecution=false`, `relinkExecution=false`, `repairExecution=false`,
`generatedDiscovery=false`, `mutationExecution=false`, and `benchmarkExecution=false`.

The initial attempt `35036750841 / 104607489241` is not semantic evidence. Review reopened its job log and confirmed it
initialized `status=BLOCKED_PRE_RUNTIME` / `runtimeStarted=false`, completed immutable package/selector/owner preflight,
and exited during the over-broad all-owner direct-GMP `ldd` assertion before any `run_one` invocation. It produced no
semantic process ledger. The fresh retry is the sole TB6 runtime authority.

## 4. S3 source and non-vacuity audit

Comparison from entering accepted source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3` to candidate source
`153047c3f92e9b9b784e11eaee1ede2de5628470` finds only three code/test-surface changes:

1. `include/directional/geometry/SurfaceCellTracing.h`;
2. `src/geometry/SurfaceCellTracing.cpp`;
3. `tests/FieldAlignedCurveNetworkTests.cpp`.

No CMake target, benchmark fixture, accepted selector, or unrelated product surface changed. The remaining source-tree
differences are documentation/control-plane history.

The production key remains the exact typed
`FieldAlignedTraceTraversalState=(sourceFace, branch, incomingCarrier, FieldBoundaryPoint entryPoint)`. Its default
comparison includes exact `FieldBoundaryPoint` / `ExactUnitParameter` data. The existing guard still checks full-state
repeat first, then step budget, then position-free combinatorial recurrence. CB7 changes only publication: exact
`CycleDetected` stores/publishes typed `FieldAlignedLimitCycleTermination`; combinatorial recurrence still maps to
`TraceCombinatorialRecurrenceExceeded`; step budget still maps to `TraceStepBudgetExhausted`. The canonical trace loop
publishes `LimitCycleTermination` and no tolerance, epsilon, wall-clock, length or proximity rule enters semantic cycle
authority.

The focused test is non-vacuous. It proves a baseline exact state advances; same face/branch/carrier with a different
exact entry advances; only complete exact repeat terminates; one-at-a-time tampering of sourceFace, branch,
incomingCarrier and entryPoint each prevents credit until the original complete state repeats; separate forced
combinatorial recurrence and step-budget subjects preserve their distinct fail-closed errors. Removing the typed
publication, dropping any key field, or reclassifying either backstop would change a required assertion/receipt.

## 5. Review decision

**PROMOTE** candidate package `10418328122` / semantic source
`153047c3f92e9b9b784e11eaee1ede2de5628470` as current accepted M4 runtime authority under the still-byte-frozen
selector424 **424/424**. The focused S3 contract is **ACCEPTED FOR SELECTOR PUBLICATION**. This is the same bounded
control sequence used for S2: focused proof may justify publication, but it is not cumulative required-green selector
credit.

Accordingly:

- `M4-CP-SCALE-DEFN-OBS-02` is **DISCHARGED / FOCUSED EXACT-REPEAT WITNESS + TYPED OUTCOME REVIEW-PROVED / NON-STABLE**;
- new `M4-CP-SCALE-TB6-REV-OBS-01` is **OPEN / PUBLICATION + CUMULATIVE-SELECTOR ACCEPTANCE / NON-DEFECT**;
- selector425 must be exact selector424 bytes plus row425
  `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`;
- the resulting 425-row selector must hash to
  `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- expected static ownership after that append is **30 authority-kernel / 279 producer / 75 completion / 41 validation**;
- only a fresh immutable selector425 **425/425** TB followed by Review can discharge `M4-CP-SCALE-TB6-REV-OBS-01`
  and grant S3 cumulative selector credit.

No product-semantic regression or accepted-green loss was observed. Stable accounting remains **49 events / 14
categories / 35 recurrences**; produced-witness debt remains **5**. CP-SCALE remains OPEN: S1 calibration, S2 arrival,
S4 and S5 remain separately owned.

## 6. Prior-obligation disposition

| Obligation | Disposition |
|---|---|
| `M4-CP-SCALE-TB1-REV-OBS-01` | **CARRIED.** S1 representative/stress calibration remains required before any numeric gate. |
| `M4-CP-SCALE-TB2-REV-OBS-01` | **ALREADY DISCHARGED** by TB3 Review; no change. |
| `M4-CP-SCALE-TB2-REV-OBS-02` | **CARRIED.** Later dedicated audit of `make_zero_transport_field`; not an S3 owner. |
| `M4-CP-SCALE-DEFN-OBS-01` | **CARRIED.** S2 arrival exact-fallback owner remains undefined. |
| `M4-CP-SCALE-DEFN-OBS-02` | **DISCHARGED THIS REVIEW.** Exact full-state repeat, typed terminal, discriminator matrix and backstops independently proved. |
| `M4-CP-SCALE-DEFN-OBS-03` | **CARRIED.** S4 independent incremental oracle/reachable negative remains owed. |
| `M4-CP-SCALE-DEFN-OBS-04` | **CARRIED.** S5 genus>=2 produced witness remains absent; genus1 gets zero credit. |
| `M4-CP-SCALE-TB4-REV-OBS-01` | **ALREADY DISCHARGED** by TB5 Review; selector424/S2 cumulative credit remains accepted. |
| `M4-CP-SCALE-TB6-REV-OBS-01` | **OPENED THIS REVIEW.** Publication-only CB8 -> fresh selector425 TB7 -> Review. |
| `M4-CP3-TB1-R1-REV-OBS-01` | **CARRIED** to first later independently falsifiable M4 test-authority turn before CP4. |
| `M4-CP3-CB4-REV-OBS-02` | **CARRIED** to next legitimate row399 touch. |
| `G4-B002` / `G4-B003` produced-witness debt | **CARRIED:** 3 debts to M4-CP4 / 2 debts to M5. |

## 7. Successor — publication-only CB8

Exact next is `M4-CP-SCALE-CB8`. It may only publish selector425 as the exact accepted selector424 prefix plus the
reviewed S3 identity, update selector-authority documentation, and compile/package without Directional runtime. It may
not alter product/test/fixture/CMake semantics or publish selector426. The expected selector425 hash and owner census
above are frozen before the build. On GREEN compile/package the exact successor is `M4-CP-SCALE-TB7-EXEC`, which runs
selector425 **425/425** in fresh exact-filter processes, followed by mandatory `M4-CP-SCALE-TB7-REV`.

## 8. Review-start governance note

At turn start, the agent fetched `Mandatory_Start_Checklist.md` before completing the full policy reads and explicit
read-mode selection. This missed the ordering requirement in the checklist. The agent immediately switched to
`READ_MODE=snapshot`, froze branch authority at `b9ad3542543862e5138b36c067c29f258780df75`, acquired one exact source
snapshot, and performed semantic/document review from those snapshot bytes. No piecemeal repository reads or semantic
mutation followed the read-mode decision. The miss is recorded here as required; it did not affect candidate/runtime
evidence and creates no stable product event.

## 9. Review consolidation

Durable facts from superseded/consumed CP-SCALE turn records are preserved in `M4_Consolidated_Record.md`, this Review,
the retained TB6 runtime report, frozen definitions, tracker, selector manifest and changelogs. Review folds:

| Folded filename | Starting lines | Verdict / retained home |
|---|---:|---|
| `Architecture_M4_CP_SCALE_CB7_S3_Exact_Repeat_Code_Build_Plan.md` | 114 | **CONSUMED/FOLDED.** S3 single-variable semantics, selector424 freeze and TB6 contract are preserved in consolidated §2.54, frozen definitions and this Review. |
| `Architecture_M4_CP_SCALE_CB7_Code_Build_Report.md` | 88 | **SUPERSEDED/FOLDED.** Implementation/compile/package provenance is preserved in consolidated §2.54, TB6 report and this Review. |
| `Architecture_M4_CP_SCALE_TB5_Artifact_Only_Test_Benchmark_Report.md` | 90 | **SUPERSEDED/FOLDED.** Entering selector424/package authority remains indexed in consolidated §2.53 and this Review. |
| `Architecture_M4_CP_SCALE_TB5_Review_Record.md` | 181 | **SUPERSEDED/FOLDED.** S2 promotion and carried obligations remain preserved in consolidated §2.53, tracker and current Review. |
| `Architecture_M4_CP_SCALE_TB6_Test_Plan.md` | 134 | **CONSUMED/FOLDED.** Frozen 425-process focused+selector execution and mandatory Review contract are preserved in retained TB6 report, consolidated §2.54 and this Review. |

`Architecture_M4_CP_SCALE_TB6_Artifact_Only_Test_Benchmark_Report.md` is retained as the current runtime-authority
evidence report. This Review is the current Review record. `Architecture_M4_CP_SCALE_CB8_Selector425_Publication_Code_Build_Plan.md`
is the one exact next-turn plan.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector424 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`; first423 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`. |
| Decisive claims independently re-derived | Candidate/result/log hashes; 1302-entry evidence manifest; all 424 process rows/raw outputs; owner partition; focused receipt; source diff/S3 exact-state semantics; immutable pre/post censuses; failed attempt pre-runtime boundary. |
| Non-vacuity checked | Four one-field tamper controls, different exact entry, combinatorial recurrence and step-budget controls each discriminate the typed S3 terminal. |
| Prior obligations discharged/carried | `DEFN-OBS-02` discharged; new `TB6-REV-OBS-01` opened; all other CP-SCALE/CP3/debt obligations explicitly carried above. |
| Stable accounting | **49 / 14 / 35**, debt **5**; accepted package `10418328122` under selector424 **424/424**. |
| New candidates/obligations recorded | `M4-CP-SCALE-TB6-REV-OBS-01`; tracker updated. No product regression candidate. |
| ORIENTATION currency line | `M4-CP-SCALE-TB6-REV`, 2026-09-16 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a because no witness pipeline state changed; §8 n/a because no new recurring semantic defect pattern was found. |
| CHANGELOG | Root and agent changelogs updated. |
| ROADMAP | CP-SCALE state/current authority/next publication turn updated. |
| Selector manifest | Updated with package promotion under unchanged selector424 and pending exact selector425 publication contract. |
| LESSONS | n/a — no genuinely new recurring pattern; existing evidence/non-vacuity/source-of-truth controls suffice. |
| Consolidation under CLEAN_UP_POLICY | Five consumed/superseded CP-SCALE turn records folded with filename/line/verdict index in consolidated §2.54 and deleted from current role set. |
| Successor frozen | `M4-CP-SCALE-CB8`; falsifiers and stop rules are frozen in `Architecture_M4_CP_SCALE_CB8_Selector425_Publication_Code_Build_Plan.md`. |
| Turn boundary held | Review remained runtime-free; no product/test/fixture/selector/benchmark/build-source mutation. |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** — no product/test/fixture/build or selector mutation; all tracked selector hashes and durable markers passed. |
| Pushed to origin, branch in sync | Closeout requires the configured Drive/GitHub apply push plus post-push branch readback before turn termination; final confirmation is recorded without embedding the containing commit hash. |

---

## 11. Independent verification addendum (reviewing agent)

Runtime-free. **Upheld, no correction.** Accounting holds at **49 / 14 / 35**, debt **5**.

### V1 — the S3 non-vacuity construction is the strongest in this sequence

The frozen constraint entering this turn was that only equality of the complete exact state
`(sourceFace, branch, incomingCarrier, entryPoint)` may authorize limit-cycle credit, with budget, proximity and
combinatorial substitutes prohibited. §4 satisfies it in terms, and goes further than a single falsifier:

- **every field of the composite key is individually load-bearing** — one-at-a-time tampering of `sourceFace`,
  `branch`, `incomingCarrier` and `entryPoint` each prevents credit until the original complete state repeats,
  which is the published `loadBearingTamperCount=4`;
- the `differentExactEntry=Advanced` subject isolates the subtlest component: same face, branch and carrier with a
  different exact entry **advances** rather than terminating, so `entryPoint` cannot be dropped silently;
- both backstops keep **distinct** typed outcomes — `combinatorialRecurrence=TraceCombinatorialRecurrenceExceeded`
  and step budget → `TraceStepBudgetExhausted` — so neither can be mistaken for limit-cycle credit;
- §4 records that no tolerance, epsilon, wall-clock, length or proximity rule enters semantic cycle authority, and
  that CB7 changed **publication only**, leaving the guard's precedence order intact.

Applying the mutate-and-re-solve test to each field of a composite key, rather than to the key as a whole, is the
right generalisation of `LESSONS.md` 171 and worth citing as precedent when a future gate turns on a tuple.

### V2 — mechanics re-derived

Selector424 re-hashes to `f202a1720c0a5288…`, unchanged, and the promoted package re-proved the full accepted
prefix at **424/424** — the correct basis for promotion, not the focused S3 result. The declared row425 identity
`M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination` exists in source at
`tests/FieldAlignedCurveNetworkTests.cpp:14478` with exactly that suite and name, so CB8 has no name drift to hit.
The pre-declared ownership `30 / 279 / 75 / 41` sums to **425**, consistent with a single producer-owned append.

### V3 — the obligation split is correct, and the pre-declaration is a strong control

Discharging `M4-CP-SCALE-DEFN-OBS-02` while withholding cumulative credit could have left the gate untracked —
a semantic obligation closed with nothing owning the missing selector row. It does not, because
`M4-CP-SCALE-TB6-REV-OBS-01` is opened in the same breath as a publication/acceptance obligation, explicitly
non-defect, discharged only by a fresh immutable selector425 **425/425** plus Review. The semantic question (does
the witness exist and prove the contract) and the gating question (is it in the required-green set) are separated
cleanly, and neither is allowed to stand in for the other.

Worth recording as practice: this Review **pre-commits selector425's exact SHA-256 and expected owner census
before CB8 builds it**. That makes the publication turn falsifiable against a target fixed in advance rather than
self-reported after the fact — the same discipline as stating falsifiers before a build, applied at byte level to
an artifact. Any drift in CB8's output now fails against a number this Review already wrote down.

CP-SCALE remains correctly open: S3 joins S2 as semantically proved-but-ungated, while S1 calibration, the S2
arrival exact fallback, S4 and S5 remain separately owned. `DEFN-OBS-04` again restates the durable S5 rule in
terms — genus-1 receives zero credit — and `TB2-REV-OBS-02` keeps its scope bound, explicitly *not* an S3 owner.
