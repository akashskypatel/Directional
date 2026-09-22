# M5-CP3-TB1-R10 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R10-EXEC`
**Boundary:** artifact-only Test + Benchmark / immutable candidate / no rebuild or repair
**Result:** **COMPLETE EXECUTION / 446/446 FRESH PROCESSES / 444 PASS + 2 SEMANTIC RED / POSTFLIGHT IMMUTABLE / RESULT SELF-MANIFEST CONTRACT VIOLATED / NO RERUN / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R10-REV`

## 1. Immutable candidate and runtime authority

R10 consumed only CB11 candidate artifact `10678487447`, semantic source
`53a21f550cf67e643e8c67a633bb63a20b055c6a`. Candidate provider/download SHA-256 is
`60c4a643cd4a56c70c5fd0674a0df110c501deffe32e244795213a33c96afc3c`; root `SHA256SUMS` verifies **28/28** at
`5f009791f3d237383a472bd1d5c4b50ca771b5f6e5d66295d99726cdd857e364`; packaged source archive SHA-256 is
`fcd122a41bdcf64010e3c732c1fba89624815b304803e31c114c56018c5dd6b8`. Preflight reverified exact executable modes,
clean source receipts, `runtimeExecution=false`, `exactArithmeticBackend=GMP`, and explicit GMPXX+GMP linkage before any
Directional runtime.

Accepted routing/selector authority was reused byte-for-byte: routing artifact `10592987234` at SHA-256
`352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, identity-map SHA-256
`7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, selector430 SHA-256
`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, first427 SHA-256
`f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Authoritative runtime run/job is `35691705806 / 106629921249`, observer/event SHA
`30442127abca653cec25149eaae09b801c40687f`. Original result/log artifacts are `10679167694 / 10678548342` with provider
and downloaded ZIP SHA-256
`e07be4438185a3deb1548799175d52ac24934649a7846015667fdecf2ecb4251 /
66e742acfec2e23558fb57443154080b295c682ac7fc00de254efe3f3eef77e2`.

The materialized R10 driver records template SHA-256
`8ec1d75206d857c0e31e70b8372df74dd6f7007e6ba8511d7185bc9d70bcf097`, orchestration writer SHA-256
`d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`, and rendered-driver SHA-256
`e32231b2f3382fa10c7da51b01c1444e2a9eddd6556a6a1f08591f834530fed9`.

## 2. Frozen 446-process execution

All **446/446** planned fresh exact-filter processes ran to organic completion. Every ledger row selected exactly one test,
skipped zero, and no row is `INVALID`. Benchmark executions were exactly **0**.

| Gate | PASS | RED |
|---|---:|---:|
| reviewed mechanism | **9/9** | 0 |
| focused retained-value atlas control | **1/1** | 0 |
| produced torus | **4/6** | 2 — rows 4/5 |
| selector430 | **430/430** | 0 |

Produced rows **1, 2, 3 and 6** remain PASS, satisfying the R9 Review's `R==0`-reduction runtime falsifier at the execution
surface. Protected selector ordinals **191, 192, 247 and 408** remain PASS, and selector430 remains **430/430**. No accepted
selector regression is observed.

## 3. Rows 4/5 remain at the R9 producer frontier

CB11 does not produce the planned downstream witness in this execution. Rows 4 and 5 both clear the authored CB10 pre-product
checks but still fail while requiring the real torus pipeline subject to be `Produced`:

| produced row | identity | observed boundary | raw SHA-256 |
|---:|---|---|---|
| 4 | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | `torus nonzero-Z4 source witness producer failed: PeriodicActionCorrespondenceMismatch` | `f2b6b31bcab3d46ece9f3c68f195d4e9424c947f95161a3784346850cbafdf1a` |
| 5 | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | same `PeriodicActionCorrespondenceMismatch` before intended tamper | `28b2a44e00336368457ce82854eedaeea75e44cdfec6b515787e9a215bc170f2` |
| 6 | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` | **PASS** | `fd5706ac1cc9b8a5113ee9e4a33a79a6aae1389f1be022c99ab9d4f408e370ff` |

The row4/5 logs are the same named failure frontier as R9. The planned source/A3-selected witness comparison therefore still
does not execute; row4 does not reach nonzero rotation+translation materialization or selected-certificate consumption, and
row5 does not reach action-only tamper or exact `NonReciprocalPeriodicRelation` rejection. EXEC records only this observable
frontier. It does **not** decide whether CB11 failed to alter the active production path, whether another exact correspondence
constraint rejects later in the same producer, or whether another authority issue remains. Those are mandatory R10 Review
questions. No debt, promotion, or stable-regression credit is assigned here.

## 4. Immutable postflight

The runtime itself completed the frozen postflight successfully:

- package byte+mode census before/after SHA-256 `18980e1f811e444897ba4db757139238040ba00c31e90193afee83a28ec536d1` — exact equality;
- packaged-source census before/after SHA-256 `91730708db4321a15d327ad8ae8e51b4eefb23a7b2df5c207bcc9e9cbf8e0736` — exact equality;
- execution-view census before/after SHA-256 `2bf119402afa6b3b3dd4a13d7e294f124acec848ebb5a34411c46295418a2b77` — exact equality;
- candidate root manifest remains **28/28** after runtime;
- selector430, first427 and routing identity-map bytes remain unchanged;
- `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false` in the frozen driver;
- configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters are all **0**;
- benchmark execution is **0**.

Thus the candidate/package/source/execution-view immutability boundary is intact and all 446 raw process results are preserved.

## 5. Result self-manifest contract violation

Independent closeout audit found a control-plane evidence-packaging defect that the workflow's success conclusion did not catch.
The original result artifact contains **913 files**. Its `SHA256SUMS` contains **911** self-excluding rows; all 911 listed rows
verify, and the manifest itself hashes to
`f9364f0c9945eaf4f71f05db9e02ed08109894261027ea4ae08b28f1a75747bc`. The two unlisted files are exactly:

1. `SHA256SUMS` itself — intentionally self-excluded; and
2. `driver-authority.txt` — **not allowed to be excluded by the R10 plan**.

`driver-authority.txt` independently hashes to
`37d0dc701fd5a788b892cb1c9b4f77d3a58c428b44b55bf2bdb55751d26cd3c5`, but the frozen plan requires the result to
self-manifest **all** evidence except the manifest itself. Expected self-manifest coverage was therefore **912/912**, not
911/912.

The orchestration cause is exact and bounded. The established R9 workflow copied `driver-authority.txt` into the result and then
ran a dedicated **Finalize R9 evidence manifest** step that regenerated and independently verified `SHA256SUMS`. The R10 caller
used the older historical driver wrapper shape, whose driver creates `SHA256SUMS` before returning; the workflow then copied
`driver-authority.txt` afterward and omitted R9's final post-copy manifest regeneration/verification. This diverges from R10
Plan §5 and the plan's explicit requirement to use the established R9 orchestration shape.

No evidence artifact is rewritten or repaired in EXEC. Because Directional runtime had already begun and ultimately completed,
R10 Plan §6 forbids silently restarting the immutable gate. The original result/log artifacts above remain the raw authority,
and this attempt is preserved as **runtime-complete but evidence-contract-invalid** for Review. Workflow conclusion `success`
means the driver exited zero; it is not acceptance of the missing self-manifest row.

## 6. Regression/accounting disposition

`M5-CP3-TB1-R10-EXEC-CAND-01` records the evidence-manifest orchestration defect above as **NON-STABLE / +0**, with exact root
cause and no same-turn repair or rerun. `M5-CP3-TB1-R10-EXEC-CAND-02` records the continued candidate-only rows4/5
`PeriodicActionCorrespondenceMismatch` as **CAUSE UNADJUDICATED / NON-STABLE / +0 / OWNER R10 REVIEW**.

Accepted runtime authority remains package/source
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Candidate `10678487447` remains
**unpromoted**. Stable accounting remains **50 events / 14 categories / 36 recurrences** and project produced-witness debt remains
**3**. The two M5 nonzero-Z4 debts and the M6 closed-complex debt remain open. Selector publication remains prohibited.

## 7. Exact successor

Exact successor is runtime-free **`M5-CP3-TB1-R10-REV`**. Review must independently reopen the CB11 candidate/source and
original R10 result/log artifacts; rederive the 444/2 process vector and immutable postflight; adjudicate whether the
self-manifest omission invalidates semantic credit or requires a later explicitly planned execution; localize the unchanged
`PeriodicActionCorrespondenceMismatch` without assuming it is the same root cause merely because the string matches R9; and
adjudicate `M5-CP3-TB1-R9-REV-CAND-01`, `M5-CP3-TB1-R9-REV-OBS-01-A`, `M5-CP3-TB1-R6-REV-OBS-01`,
`M5-CP2-TB1-REV-OBS-01`, candidate promotion, debt status and selector-publication eligibility.

EXEC performs no semantic repair, candidate promotion, debt discharge, selector publication, or runtime rerun.
