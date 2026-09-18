# M4-CP-SCALE-TB12-R7-EXEC — Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB12-R7-EXEC`
**Type:** immutable artifact-only Test + Benchmark
**Status:** **COMPLETE / SEMANTIC RED / FAIL-FAST AT GATE A0 ROW 1 / NON-STABLE**
**Candidate package:** `10532133889` / semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`
**Authoritative run/job:** `35326420329 / 105540445909`
**Exact next:** `M4-CP-SCALE-TB12-R7-REV`

## 1. Result

R7 is a valid semantic execution of the unchanged CB18 candidate under the corrected CB20 harness. Immutable package preflight completed, the first frozen Gate A0 identity executed exactly once, and that identity returned a semantic RED:

```text
FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle
exit=1
selected=1
skipped=0
code=SingularityMismatch;sourceVertex=8
```

Fail-fast then stopped the semantic gate. The remaining **435/436** rows stayed `UNEXECUTED`: Gate A0 **0 PASS / 1 RED / 4 UNEXECUTED**, Gate A **0/4 executed**, S5 **0/1 executed**, selector426 **0/426 executed**, benchmark **0**. Exact package/source/execution-view postflight reproduced preflight byte-for-byte, so this is semantic evidence rather than orchestration or integrity failure.

EXEC does not decide whether the CB18 ownership correction is falsified, whether the `sourceVertex=8` locus is the same `RP-01` mechanism previously reviewed at R4, or whether a distinct authority defect is present. Those decisions belong to mandatory Review.

## 2. Control-plane provenance

- R7 entry `STATUS` was published before other turn mutations at commit `55da9899244de4d87085252ebe90832335bf00f9`.
- Verified source snapshot run/job `35325918930 / 105538870484` captured event/snapshot SHA `7a31e0ca755a890cce605e9ee949a51ba016fa8c`; snapshot artifact `10539158349` has provider SHA-256 `6740e578d23d6901e0914de082865739cc3c01803ac52b5ff0d9a4ad5dd78eaf` and nested source archive SHA-256 `ffa9ddb40a23f4a81f607cab440fcff00ac8131318e423cb20d953f3230897f6`.
- Exact CB20-published R7 caller was reinstalled from publication commit `df3a476bcdb1851ec033f96cad2357b764d327d8`, blob `a9705992bf85bfe8cc0caca7e8b6a94e099d89d5`, in install commit `7b15fe72d8786d05a0bfc6e5ecae1e24eb7ee7f0`. Re-fetch reproduced the same blob and 4,870-byte content.
- The permission union remained exactly `actions: read`, `contents: write`, `id-token: write`, `issues: write`, `pull-requests: write`.
- R7 execution marker commit/event SHA is `a5b4bc4ef6f84ac0c2ad20043eb6e7e973cf263f`. The observer reported matching run `35326420329` before evidence was accepted.
- Schema validation job `105540405381` and observer job `105540405607` were GREEN. Workload job `105540445909` completed successfully at the workflow level because the harness intentionally records a valid semantic RED and exits zero after evidence/postflight completion.

## 3. Corrected harness and immutable candidate preflight

R7 consumed only corrected frozen harness Drive file `1Q1h9-W7AKuS1VP-IXJ__v4nqvmiNpNGV`, 18,479 bytes, SHA-256 `04f3e8dd49b5521f5850d4bfc2eea4b8f04b4c4f4ef839974b55cd3b1c7e7cdf`. The workflow log re-verifies that exact digest. No harness regeneration or repair occurred in R7.

Candidate package authority remained CB18 artifact `10532133889` / semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`. The packaged manifest check is **28/28 PASS**, including all six executables, two libraries, build metadata and packaged source archive. Existing frozen package/source authorities remain:

- artifact provider SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`;
- source archive SHA-256 `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`;
- package manifest SHA-256 `44fd665474f12d79b916eacb77df9dfc07cf7478503e82a8c1ac7f80c64da5bd`, 28/28;
- selector426 SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114` with owner census **30/280/75/41**;
- retained genus-two OBJ/rawfield/metadata SHA-256 `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3` / `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e` / `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

No configure, compile, relink, generated discovery, package repair, mode repair or mutation occurred.

## 4. Semantic ledger and fail-fast boundary

The harness first initialized all **436** frozen rows as `UNEXECUTED`; initial ledger SHA-256 is `61fd0f8c26c8c2266794efbf8de1c37617a81b2436e027c3e31c0b02d08b92df`. After row 1 executed, final ledger SHA-256 is `b223e343890ef18a7ab728f59f5945fd83263b603926907e93c70d7b5a0b043a`.

Row 1 is:

```text
phase=A0
phase_ordinal=1
identity=FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle
binary=directional_surface_cell_authority_kernel_tests
status=RED
exit=1
selected=1
skipped=0
stdout_sha256=999dc96ac83ed8786e34863024428242db4e9d6aaac337b812544884133dd137
stderr_sha256=e3b0c44298fc1c149afbf4e8996fb92427ae41e4649b934ca495991b7852b855
```

The test reaches `tests/FieldTransportAtlasTests.cpp:2572`, where `built` is false and the diagnostic is exactly `code=SingularityMismatch;sourceVertex=8`. No later row executes.

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

The corrected harness intentionally retains historical internal turn label `M4-CP-SCALE-TB12-R5-EXEC`; the outer R7 workflow/run/artifact provenance above is the turn authority.

## 5. Immutable postflight and evidence

Preflight and postflight are byte-identical:

- package census SHA-256 `08b25da4f16092e5ed77a886da51f2346868a6d0e6f35daf687db51bf84f8866` before and after;
- source census SHA-256 `d199eacce8b9275de2e56df005f36621aef4eb8b8e64aabbab67e61d10576f50` before and after;
- execution-view census SHA-256 `b9fb5e93b15d6fc4a746202b191f9a9495b948bb57c4552b0c5120bed9b5be04` before and after.

Evidence artifacts:

- result artifact `10538264057`, provider SHA-256 `12d79ff15e3990a340ed70021901f2c7f23d52eec9c581d0b09e1e34509e1aa8`;
- persistent log artifact `10538428912`, provider SHA-256 `d2890bbd40ba3919c2b234065d30860afb42e27e62637d92c951d6e647ece2e3`;
- nested evidence archive SHA-256 `0a2270bf8e8cb0453a36bf572dfe1392580e8e052f003e7b2e98009400aec643`;
- evidence `SHA256SUMS` SHA-256 `e178d7857d5f4bcbd7338eeb236594e71bd8577370e8df11f42fef4c624495af`; every listed record verifies;
- `package-manifest-check.txt` SHA-256 `6de94a5de805dee7b61e23710767bc4d59311f13ed06f0796880eae738cae7e8`.

The workflow log contains a `tar: .: file changed as we read it` warning while packaging the evidence directory. It occurs after the exact semantic result and postflight were materialized; the harness exits `0`, the uploaded evidence archive is readable, and its included checksum manifest verifies. It is not the semantic stop reason and does not invalidate the result.

## 6. Classification and authority

`M4-CP-SCALE-TB12-R7-EXEC-CAND-01` is **OPEN / SEMANTIC RED / GATE-A0 SEPARATING-HARD-FEATURE OWNERSHIP CONTROL / REVIEW REQUIRED / NON-STABLE**. It adds **+0 stable events / +0 categories / +0 recurrences** in EXEC because row 1 is outside accepted selector execution and mandatory Review owns root-cause classification/pricing.

R7 resolves the R6 orchestration candidate operationally: the corrected harness reaches generated Directional runtime and exact postflight. It does not itself close/reprice `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01`. Review must compare the valid R7 `sourceVertex=8` RED against the CB18 correction contract and the prior R4 `sourceVertex=0` evidence.

Accepted M4 runtime authority remains package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**, owner census **30/280/75/41**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. CB18 candidate `10532133889` remains unpromoted; S5/A3 remain uncredited.

## 7. Exact next

Per the frozen R7 plan and cadence, exact next is runtime-free **`M4-CP-SCALE-TB12-R7-REV`**.

Review must independently audit the valid row-1 RED, CB18's separating-hard-feature ownership correction and direct controls, the locus shift from R4 `sourceVertex=0` to R7 `sourceVertex=8`, and whether this is a falsification/recurrence of `RP-01`, a distinct product defect, or an authority/test issue. No corrective Code + Build turn, retry, selector execution, benchmark, package promotion, selector427 publication or S5 credit is authorized before that Review.
