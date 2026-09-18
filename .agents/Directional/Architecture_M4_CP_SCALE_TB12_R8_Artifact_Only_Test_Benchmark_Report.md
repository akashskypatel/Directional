# M4-CP-SCALE-TB12-R8-EXEC — Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB12-R8-EXEC`
**Type:** immutable artifact-only Test + Benchmark
**Status:** **COMPLETE / SEMANTIC RED / FAIL-FAST AT GATE A0 ROW 1 / NON-STABLE**
**Candidate package:** `10542249210` / semantic source `ea7b15f53e5e92cb034c855d52c17eaa2d8928d1`
**Authoritative run/job:** `35338412117 / 105578569562`
**Exact next:** `M4-CP-SCALE-TB12-R8-REV`

## 1. Result

R8 is a valid semantic execution of the immutable CB21 candidate. Exact package preflight completed, the first frozen Gate A0 identity executed exactly once, and the test advanced past the R7 `SingularityMismatch;sourceVertex=8` seam before returning a different semantic RED:

```text
FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle
exit=1
selected=1
skipped=0
code=SingularityPortClassCountMismatch;sourceVertex=16;topologyRegion=1
```

The product diagnostic additionally records `incidences=4`, `classes=4`, `expectedClasses=5` for singularity 1 at source vertex 16 / topology region 1. The direct test fails at `tests/FieldTransportAtlasTests.cpp:2666` on `ASSERT_TRUE(built)` after its independent region-relative-lift/global-index mismatch precondition has already been established.

Fail-fast stopped the gate immediately. The remaining **435/436** rows stayed `UNEXECUTED`: Gate A0 **0 PASS / 1 RED / 4 UNEXECUTED**, Gate A **0/4 executed**, S5 **0/1 executed**, selector426 **0/426 executed**, benchmark **0**. Exact package/source/execution-view postflight reproduces preflight byte-for-byte, so this is semantic evidence rather than package or mutation failure.

EXEC does not decide whether CB21 has recovery-proved the prior `RP-01` owner-domain defect and exposed a new product seam, whether the new class-count RED is test-authority/precondition behavior, whether it is another recurrence of an existing defect family, or whether the frozen third-distinct-product-root-cause definition stop now applies. Those decisions belong to mandatory Review.

## 2. Control-plane provenance

- R8 entry `STATUS` was published at commit `422d03c2939b603e28fa43c4b6d7f46fede4900e` before other turn mutations.
- Verified source snapshot run/job `35337572126 / 105575917285` captured event/snapshot SHA `57f6ee928cd0778f1bf3e01ac4c16e01ffe186fc`; snapshot artifact `10543038823` has provider SHA-256 `be5569fbaf4fb67441cea19fe1f9fb2f1fb485438bcbe397ade22d3c5cccc4fb` and nested source archive SHA-256 `41e0c9f2366f0a5a1a7f77a94f926d948e58e1e31e997b45680cd91445218119`.
- Frozen R8 caller install authority is commit `885114fd96b6d1b5866d53572fc3455668e1869e`; the runtime event sees caller blob `cd09acf60e9ac7b4da524afe546a7a59cca5f454`, 4,850 bytes.
- The caller permission union is `actions: read`, `contents: write`, `id-token: write`, `issues: write`, `pull-requests: write` and uses durable schema validation plus run observation.
- R8 execution marker/event SHA is `2161f46960e40b73c205ff5ba2c79ffc255bf935`. The observer reported matching run `35338412117`.
- Schema validation job `105578533617` and observer job `105578533804` are GREEN. Workload job `105578569562` completes successfully at the workflow level because the frozen harness records a valid semantic RED, completes postflight/evidence, then exits zero by design.

## 3. Frozen harness and immutable candidate preflight

R8 consumed only frozen harness Drive file `1clwXAJ_7tyx-ytUJ5Lq47FlcmzxRNKoG`, **18,479 bytes**, SHA-256 `917294ec05e5ad1ec6be990150b9a45931538209489830c4cd03610e1c0f3f9e`. The workflow log re-verifies that exact digest before runtime. The harness is the R7 structure with only the R8 turn/candidate authority literals changed; it retains the nounset-safe sequential `stem` / `dir` / `work` initialization.

Candidate package authority is CB21 artifact `10542249210` / semantic source `ea7b15f53e5e92cb034c855d52c17eaa2d8928d1`. Preflight re-proves:

- artifact provider/local ZIP SHA-256 `a64352a9524c4f114865948bb84226a317eaa1affa2e7a7fcfeea62352c7ef6c`;
- source archive SHA-256 `7a8c8f9c866dfc51580975d64e6dda5001291780e666d1491a6aee2a39a858e7`;
- package manifest SHA-256 `88e3f454c963af481df96b5fea4b5450b904c707a6dc5ad1f9299d87ae55611c`, **28/28 PASS**;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and authoritative GMP/GMPXX linkage;
- six executable modes `0755`, two static-library modes `0644`, and clean packaged source-status receipts;
- selector426 **426 LF rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, first425 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, no selector427;
- genus-two OBJ/rawfield/metadata SHA-256 `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3` / `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e` / `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`;
- selector owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**.

No configure, compile, relink, generated discovery, package repair, mode repair or mutation occurred.

## 4. Semantic ledger and fail-fast boundary

The harness initialized all **436** frozen rows as `UNEXECUTED`; initial ledger SHA-256 is `61fd0f8c26c8c2266794efbf8de1c37617a81b2436e027c3e31c0b02d08b92df`. Final ledger SHA-256 after row 1 is `a9aea1a0ba92f6889f2c50268c34b29b71c643e23a3a20ba8ff2844986b573e2`.

Row 1 records:

```text
phase=A0
phase_ordinal=1
identity=FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle
binary=directional_surface_cell_authority_kernel_tests
status=RED
exit=1
selected=1
skipped=0
stdout_sha256=81e2e8b2fcff560a144653e326077cfde4597211da8f690d01166990a0565ac6
stderr_sha256=cc2e27e481217c82d97820a6eceb2714b6d3bdd7c8ce68583bb59ebea8560f62
```

The stdout reports `built=false` and `code=SingularityPortClassCountMismatch;sourceVertex=16;topologyRegion=1`. Stderr preserves the exact partition census and six fan-adjacency signed lifts. No later row executes.

Observed execution boundary:

```text
orchestration_failure=false
semantic_red=true
runtime_started=true
postflight_complete=true
stop_reason=semantic_red:A0:1:FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle
benchmarkExecuted=0
configureExecuted=0
compileExecuted=0
relinkExecuted=0
generatedDiscovery=0
packageRepair=0
modeRepair=0
mutationPerformed=0
```

The ledger's convenience `raw_prefix` terminal field is absent from the executed row because the inherited harness forwards only the six semantic result fields after the ordinal into `update_row`. This does not remove plan-required execution evidence: the uploaded result artifact contains deterministic `raw/001-A0-001/stdout.txt` and `stderr.txt`, and their exact SHA-256 values match the ledger. Review should retain this as a control-plane evidence-format observation rather than infer product semantics from it.

## 5. Immutable postflight and evidence

Preflight and postflight are byte-identical:

- package census SHA-256 `b1c748ebe6c0df8a47a9b23b15daecab19208dc284885322650869e3790a8838` before and after;
- source census SHA-256 `cea2c7e7675197198ce862f4ca6b3586839132fdc8deae15859a084e9f48a31e` before and after;
- execution-view census SHA-256 `7bd6d8f29a9b290eb415c0ff8ef54c0249482d6f2379cc9dbf979d30de39eac1` before and after.

Evidence artifacts:

- result artifact `10543544280`, provider/local SHA-256 `4fbbd1b1163067115b4a738c64b57c6e6a986474302813b6e1c7f3453aaf8db6`;
- persistent log artifact `10544295647`, provider/local SHA-256 `b9d8370ac5b95560e751e6dba64694435149c8dec160d161397476aa1abcff5a`;
- nested evidence archive SHA-256 `f239d1bf345f342fe0680c4b9e018d2b4c50dad9a7d5c69c2c1ee56181038981`;
- evidence `SHA256SUMS` SHA-256 `30d468bdcfb425f132010eb5d07c9348f50b6c4cead65d100fd131852357010f`; every listed record verifies;
- `package-manifest-check.txt` SHA-256 `eac29c5d77eedaaa33f953415415494106d7a83af5b35ac701e50c7d03460c8d`.

The workflow log again contains `tar: .: file changed as we read it` while creating the optional nested evidence tar. The uploaded result directory itself is complete, its checksum manifest verifies, all required raw evidence is present, and exact immutable postflight had already completed. As in R7, the warning is not the semantic stop reason.

## 6. Classification and authority

`M4-CP-SCALE-TB12-R8-EXEC-CAND-01` is **OPEN / SEMANTIC RED / GATE-A0 SEPARATING-HARD-FEATURE DIRECT CONTROL / REVIEW REQUIRED / NON-STABLE**. EXEC assigns **+0 stable events / +0 categories / +0 recurrences** because mandatory Review owns root-cause classification/pricing and selector426 did not execute.

The diagnostic boundary has advanced from R7's `SingularityMismatch;sourceVertex=8` to `SingularityPortClassCountMismatch;sourceVertex=16;topologyRegion=1`, but R8 does not self-adjudicate what that advancement proves. In particular, it does not close/reprice `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01`, does not declare a third distinct product root cause, and does not grant S5/A3 credit.

Accepted M4 runtime authority remains package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**, owner census **30/280/75/41**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. CB21 candidate `10542249210` remains unpromoted; S5/A3 remain uncredited.

## 7. Recovery/process notes

The turn initially began broad source/document reads before the mandatory exact source snapshot was materialized. The miss was detected, piecemeal inspection stopped, and verified snapshot `35337572126` was materialized before source-dependent runtime preparation. No semantic result depends on the premature reads.

A later context-resume path did not surface that authoritative R8 run `35338412117` had already completed. Recovery created an unused repository-local copy of the already-frozen harness and replaced the temporary caller, but did **not** update the existing execution marker and therefore did not trigger a second runtime. Repository authority then exposed the completed run; the duplicate control-plane files are cleanup-only and carry no semantic evidence.

The turn-local tool-call ledger crossed context compaction/resume boundaries and is therefore **PARTIAL/UNKNOWN** rather than reconstructed by spending additional calls.

## 8. Exact next

Per the frozen R8 plan and cadence, exact next is runtime-free **`M4-CP-SCALE-TB12-R8-REV`**.

Review must independently audit candidate/package/harness provenance, the direct test's independently established mismatch precondition, the boundary advance from R7 `SingularityMismatch;sourceVertex=8` to R8 `SingularityPortClassCountMismatch;sourceVertex=16;topologyRegion=1`, partition-class semantics, immutable postflight and the evidence-format observation above. It must decide whether CB21 recovery is proved, whether the new RED is product or test authority, whether any existing RP category/recurrence applies, and whether the third-distinct-product-root-cause definition stop fires. No corrective Code + Build turn, retry, selector execution, benchmark, package promotion, selector427 publication or S5 credit is authorized before that Review.
