# M4-CP-SCALE-CB20 — Frozen Harness Orchestration Correction Code + Build Report

**Turn:** `M4-CP-SCALE-CB20`
**Type:** Code + Build / control-plane-only orchestration correction
**Status:** **COMPLETE / CONTROL PLANE GREEN / ZERO GENERATED DIRECTIONAL RUNTIME / NO BUILD**
**Candidate retained unchanged:** artifact `10532133889`, semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`
**Exact next:** `M4-CP-SCALE-TB12-R7-EXEC`

## 1. Result

CB20 corrects only the shell-orchestration defect proved by R6. It does not modify or rebuild production source, tests, fixtures, selector files, CMake/build logic, benchmark logic, candidate-package bytes, or accepted runtime authority.

The original retained harness was re-fetched from Drive file `1WnSzFMBLSu5OdFjZTGbkgym8D-ikUdVC` and re-proved at **18,459 bytes**, SHA-256 `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`. It remains unchanged evidence.

The corrected successor harness changes exactly the R6-failing `run_row` declaration:

```diff
-  local stem="$(printf '%03d' "$ledger_ord")-${phase}-$(printf '%03d' "$phase_ord")" dir="$RESULT/raw/$stem" work="$RUNTIME/$stem"
+  local stem dir work
+  stem="$(printf '%03d' "$ledger_ord")-${phase}-$(printf '%03d' "$phase_ord")"
+  dir="$RESULT/raw/$stem"
+  work="$RUNTIME/$stem"
```

No other harness line changes. `bash -n` passes. A non-Directional `set -u` micro-proof derives exactly:

```text
stem=001-GATEA0-001
dir=/tmp/result/raw/001-GATEA0-001
work=/tmp/runtime/001-GATEA0-001
```

The corrected bytes are **18,479 bytes**, SHA-256 `04f3e8dd49b5521f5850d4bfc2eea4b8f04b4c4f4ef839974b55cd3b1c7e7cdf`, frozen under new Drive file `1Q1h9-W7AKuS1VP-IXJ__v4nqvmiNpNGV`. Owner-side re-fetch reproduced the same byte count and SHA-256. The original Drive file was not overwritten.

## 2. Start-of-turn source authority and reconciliation

CB20 entry `STATUS` was published before other repository mutation. `READ_MODE=snapshot` then used source-snapshot run `35322982060`, event/snapshot SHA `081f5a17795bbe5533ebecffcf22ff2a7a20e2a5`. Snapshot artifact `10537144446` has provider SHA-256 `0f3be40f8afbfa425e11184eeef754a090b711467a17f3e80088ff8533eafa35`; its nested source archive SHA-256 is `a92311aaf871e738105c8fb1c798642616b67a991676a0d06409f4f32901faa3`, with 5,283 files / 95,938,966 bytes.

The pre-existing local R6 worktree had seven dirty documentation paths. Each path was byte-identical to the fresh source snapshot, proving that the apparent dirty state was already-pushed prior-turn work and that no local-only/unpushed change required preservation before CB20 authoring.

The first durable-document patch application later stopped safely because concurrent R6 closeout cleanup had changed `CHANGELOG.md` and `Future_Chat_Session_Handoff.md` after the initial CB20 snapshot. No patch bytes were applied. CB20 therefore refreshed source authority with run `35324574392`, event/snapshot SHA `5e8a5ea470a851afdce8c07d0eeda20ce7c1d974`, artifact `10538042160`, provider SHA-256 `0db7329c34a99303f18c98cde2961985a082aae4ba93bdaf17d32b059958ee29`, and nested source archive SHA-256 `4de3536ff3718bf431b6874c2a453d82440418b51e50c10b77a545b47c8b01c4`. The CB20 documentation was rebased onto that exact authority while preserving both concurrent R6 cleanup edits before the corrected patch was regenerated.

## 3. Corrected R7 caller

The fresh R7 caller was derived from the exact validated R6 caller bytes. The only caller changes are:

- outer R6 → R7 workflow/log/result naming;
- marker/observer/validation path `m4-cp-scale-tb12-r7-exec-20260918.txt`;
- corrected harness Drive ID `1Q1h9-W7AKuS1VP-IXJ__v4nqvmiNpNGV`;
- corrected harness SHA-256 `04f3e8dd49b5521f5850d4bfc2eea4b8f04b4c4f4ef839974b55cd3b1c7e7cdf`.

Its permission union remains exactly:

```yaml
permissions:
  actions: read
  contents: write
  id-token: write
  issues: write
  pull-requests: write
```

The draft was authored outside active workflows at `.agents/Directional/turn-payloads/m4-cp-scale-tb12-r7-exec.yml`. The harness digest was materialized through `write_orchestration_payload.py` from an `@@SHA256:R7_HARNESS@@` placeholder. Exact rendered caller identity is **4,870 bytes**, SHA-256 `d2f8fe25701023bdad4843cfa6f608f2fed44980006bd73db699915728288279`, Git blob `a9705992bf85bfe8cc0caca7e8b6a94e099d89d5`.

Schema validation run `35323555381`, event SHA `a51ae01554c169809b5bf6b9f02bc2ec34f34dd5`, completed GREEN:

- validation-workflow self-check job `105531304516`: success;
- exact R7 draft validation job `105531346862`: success;
- exact R7 validation artifact `10537559842`, SHA-256 `7393e133591f77b481f55a19f350c5adcaa959715740deec354dfb5f9c79fb87`;
- `validation_outcome=success`, `valid=true`, checked-out/event SHA exact.

The byte-identical caller was published in commit `df3a476bcdb1851ec033f96cad2357b764d327d8`. Re-fetch reproduced Git blob `a9705992bf85bfe8cc0caca7e8b6a94e099d89d5`. The R7 execution marker remained absent throughout CB20, so the semantic gate was not triggered.

## 4. Build/runtime boundary

CB20 generated no Directional runtime and no build evidence:

```text
configureExecuted=false
compileExecuted=false
relinkExecuted=false
repackageExecuted=false
generatedDirectionalRuntime=false
testExecution=false
benchmarkExecution=false
discoveryExecution=false
packageRepair=false
```

Candidate `10532133889`, source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`, selector426, genus-two fixture authority, accepted package `10473134357`, and all stable accounting remain unchanged.

## 5. Disposition

CB20 is **CONTROL PLANE GREEN**. It closes the bounded nounset-harness correction only. `M4-CP-SCALE-TB12-R6-EXEC-CAND-01` remains a non-stable orchestration provenance record; no stable event/category/recurrence is added.

Accepted M4 runtime authority remains package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**, owner census **30/280/75/41**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. CB18 candidate `10532133889` remains unpromoted and S5/A3 remain uncredited.

Exact successor is immutable artifact-only `M4-CP-SCALE-TB12-R7-EXEC` under `Architecture_M4_CP_SCALE_TB12_R7_Artifact_Only_Test_Benchmark_Plan.md`. R7 must reinstall the exact published caller bytes from commit `df3a476bcdb1851ec033f96cad2357b764d327d8` / blob `a9705992bf85bfe8cc0caca7e8b6a94e099d89d5`, verify caller SHA-256 `d2f8fe25701023bdad4843cfa6f608f2fed44980006bd73db699915728288279`, and only then create its execution marker in a separate commit.
