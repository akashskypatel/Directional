# M3-CP4c-3-TB46 EXEC Report

**Status:** COMPLETE / ORCHESTRATION FAILURE / PRE-RUNTIME / NO SEMANTIC LEDGER / PACKAGE111 UNEXECUTED
**Turn:** `M3-CP4c-3-TB46-EXEC`
**Boundary:** Test + Benchmark, artifact-only
**Date:** 2026-09-09

## 1. Immutable authority entering the attempt

TB46 was authorized to consume only immutable CB51 package111 and selector409:

- semantic source: `4f0663ef3468996abce6f59109f1c67f5be5f604`;
- package111 result artifact: `10112532452`, `m3-cp4c3-cb51-package111-result-34372482691`;
- provider/download SHA-256: `62ae325186ef31d2936e1a797c55cef43f8aef62449b33a26e29cb1ecd9185da`;
- packaged source archive SHA-256: `813d375e8ca38e65b01ea54a668cd067033def144eefe2f375b98a1a29ae0c37`;
- package manifest: 28/28 verified before this turn;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, 409 rows;
- accepted-prefix count: 365;
- generic artifact-only harness SHA-256:
  `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`.

No semantic package byte, selector byte, source/test/fixture byte, or executable was changed by TB46.

## 2. Control-plane execution evidence

The temporary TB46 caller was schema-validated successfully and triggered exactly one authoritative attempt:

- workflow run/job: `34374946991 / 102545334482`;
- event SHA: `b44c936e799f08cc72fe1c36a52f4eef45a880ce`;
- schema validation: success;
- frozen harness hash verification: success;
- execute job conclusion: failure;
- retained log artifact: `10113449239`,
  `m3-cp4c3-tb46-log-34374946991`, provider SHA-256
  `7910fbe8fa6c0c397dfcef37aeaac0abd398d2a41dc527a9e3c2afe231bc6b42`;
- result artifact: **absent** because the harness exited before its result directory existed.

The outer workflow log prints the exact frozen harness SHA and then the nested harness returns exit code `1`. The
harness emits none of its own environment/preflight records, creates no `execution-boundary.txt`, and leaves no
result directory for the result-upload step. The persistent log upload succeeds; the result upload fails with
`No files were found with the provided path: .../M3-CP4c-3-TB46-result`.

## 3. Exact failure surface

This is a **pre-runtime orchestration failure**, not a RED semantic result.

The failure is bounded to the generic harness bootstrap **after** the caller verifies the exact harness bytes and
**before** the harness installs its own `finish` trap / publishes its first environment record. The retained evidence
does not localize which bootstrap command returned `1`; claiming a more specific root cause would be unsupported.

Consequently:

- artifact API download/preflight was not reached by the harness;
- package111 was not materialized by the harness;
- selector409 identity mapping was not produced;
- **0/409** selector identities executed;
- no Directional test, benchmark, CLI, fuzzer, or custom input executed;
- no semantic PASS/RED ledger exists;
- no accepted-prefix measurement exists;
- no ordinal367 or 390/393/406/407 semantic measurement exists;
- no carried-RED remeasurement exists;
- no benchmark executed;
- no configure, compile, relink, package repair, mode repair, generated discovery, or source/test/fixture/selector mutation occurred.

This attempt is `M3-CP4c3-TB46-ORCH-01`, orchestration-only and non-stable.

## 4. Semantic authority and accounting

TB46 produces **no semantic credit and no semantic regression**. TB45/package110 remains the promoted semantic
runtime authority:

- **399 PASS / 10 RED / 0 SKIP**;
- accepted prefix **365/365 PASS**;
- RED `[367,368,369,370,374,390,393,398,406,407]`;
- stable accounting **47 events / 14 categories / 33 recurrences**;
- produced-witness debt **5**;
- ownership **300 established / 0 unavailable / 0 conflicting**.

Package111 remains the immutable build/package authority and accepted package count remains **111**. The failed
orchestration attempt does not increment semantic package accounting.

## 5. Routing

The frozen TB46 semantic plan remains unconsumed because no Directional runtime started. No independent semantic
review is authorized: there is no semantic ledger to review.

**Exact next:** `M3-CP4c-3-CB52` — bounded orchestration-correction Code + Build / control-plane-only where possible,
under `Architecture_M3_CP4c3_CB52_Orchestration_Correction_Plan.md`.

CB52 must localize and correct only the pre-trap harness bootstrap/control-plane defect, preserve package111 and
selector409 byte-for-byte, execute no Directional runtime, and prove the corrected artifact-only preflight before
routing to `M3-CP4c-3-TB46-R1`.

## 6. Closeout, preservation, and cleanup

TB46 closeout was preserved before remote application as
`Directional__M3-CP4c-3-TB46-EXEC__base-8722285baa14__work-preservation.patch`, SHA-256
`f884bf12934e880fcc1424ebb12db4c852d8b4af0ae70f4398c58e66335325f9`; its diff-body SHA-256 is
`605edc8eefddd96fe9211e0597152dfca3b1c5f317fd6ef2063deeebc1715e25`. Local `git apply --check` and
`git diff --check` both passed before transport.

The verified closeout patch was applied through the durable Google Drive patch workflow:

- apply run/job: `34376266662 / 102549814675` — success;
- applied closeout commit: `e91c192fcaecd04eb859430945ca8e8fd04962da`;
- the workflow independently verified the patch, base, diff-body digest, intended-path isolation and `git diff --check`;
- the Drive service identity could not trash the staged file, so owner-authorized control-plane cleanup permanently
  deleted it after successful application;
- temporary closeout caller deletion commit: `0c2922295e84eb817e0f617995c6e971f4d71f47`.

Final repository cleanup then ran through the durable turn-cleanup workflow:

- cleanup run/job: `34376416343 / 102550244200` — success;
- cleanup commit: `8e8f28e14f4a4067a19ea38ed109a413e3688211`;
- durable workflow inventory validated as exactly the seven allowed workflows;
- the source-snapshot, TB46-exec and closeout-apply trigger markers plus cleanup manifest were removed;
- PR conversation/review comments were verified empty before the cleanup observer republished its run marker;
- cleanup recorded `runtimeExecution=false`.

No closeout or cleanup operation changes TB45 semantic runtime authority, package111 bytes, selector409 bytes, stable
regression accounting, or the exact next boundary above.
