# M5-CP3-TB1-R11-R1 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R11-R1-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark / fresh retry after orchestration-invalid R11
**Disposition:** **MECHANICALLY COMPLETE / SEMANTIC RED / 444 PASS + 2 RED / ORCHESTRATION CORRECTION RUNTIME-CONFIRMED / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R11-R1-REV`

## 1. Immutable authority

R11-R1 consumes only unchanged CB12 candidate artifact `10713410215`, semantic source
`8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`, plus accepted routing artifact `10592987234` and selector430. No semantic row,
verdict or acceptance credit is imported from orchestration-invalid R11.

Verified authorities are unchanged:

- candidate ZIP SHA-256 `faf4def9e6823f718e56091876bb97047f5e91a8bfb561ca40d91d70d2af61ce`;
- root `SHA256SUMS` SHA-256 `352f7553e2f0dc627ada385d78327bcb93d4f3b66125f4faf540d6965a1c2c33`, **28/28**;
- packaged source archive SHA-256 `506e9d75976802f7045b95344ef8cc0ff1e4d39b8343bdaddaa009a58e04a673`;
- routing ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

The retry workflow is the exact schema-validated CB13 blob `1080a415f3382bf562d49e5e7909160f55033a5f`, restored from historical
commit `789e442aa86278eab1821e5c6aef3ad33678505c` before the trigger. The turn-local source snapshot was run
`35777589896`, artifact `10716494203`, provider/download ZIP SHA-256
`500c90f33fc3ab357f0fd3c3528168e73fb48ecc01fbdd6af2108047d8332ec5`; its internal source archive SHA-256 is
`04b5aa27a536148f7e3d01e3b1e8aeda7a25b948d31c591859a505af6ed792e2` and its recursive manifest verifies **5298/5298**.

## 2. Runtime and complete evidence contract

R11-R1 run/job is `35778555375 / 106917917282`, event SHA
`750a11cf0edeaee1e7f7246c52145f7117b935a8`. Workflow schema validation and the runtime job both conclude success; the
runtime job's success means **orchestration completed**, not that every semantic row passed.

Result/log artifacts are:

- result `10717297354`, provider/download ZIP SHA-256 `d76dff757919a0c8bb139b6aa4d54840f5344fc9bf0b88f57a5d9629d3807656`;
- log `10717921412`, provider/download ZIP SHA-256 `c09c1c5797640e85ed485d5b6a034970a266c36fb0bbf488441be1674aff0cd0`.

The corrected finalizer is runtime-confirmed. The result contains **912 actual non-manifest evidence files** and exactly **912
manifest rows**. Every row verifies; result `SHA256SUMS` SHA-256 is
`16dfe18019afee726ce2d2d1845187619c27c74bfa9ff238904237c7de3ab589`. The log records
`result_manifest_rows=912`, `result_non_manifest_files=912`, and `driver_exit=0`. `orchestration-failure.txt` is absent.
This closes the CB13 self-manifest correction as mechanically effective on the full runtime evidence shape.

Driver authority records template SHA-256
`18510ce514d26ed305491ea5df082a8cca035d5ff0b9c5fce50f117da7b43f9a`, writer SHA-256
`d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`, and rendered-driver SHA-256
`fac8b35f9f6443292e648175d91138a9a1a0fddab2e4c69e6a7c7f1767b555cd`.

## 3. Fresh 446-process semantic ledger

All **446/446** planned processes execute freshly, each selecting exactly one test with zero skips:

| Phase | PASS | RED | Total |
|---|---:|---:|---:|
| nine reviewed mechanism identities | 9 | 0 | 9 |
| focused atlas identity | 1 | 0 | 1 |
| produced identities | 4 | 2 | 6 |
| selector430 | 430 | 0 | 430 |
| **total** | **444** | **2** | **446** |

Produced rows **4/5** alone are RED:

1. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`;
2. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`.

Both select once, skip zero, exit `1`, and fail while constructing the nonzero-Z4 source witness with the exact exception
`torus nonzero-Z4 source witness producer failed: PeriodicActionCorrespondenceMismatch`. Row4 therefore does not reach relation
materialization/certificate assertions, and row5 does not reach its transform-only tamper or typed
`NonReciprocalPeriodicRelation` assertion.

Protected selector ordinals **191, 192, 247 and 408** are each PASS. Benchmark count is **0**.

## 4. Immutable postflight

Postflight is exact:

- package byte/mode census unchanged;
- packaged-source census unchanged;
- execution-view census unchanged;
- candidate manifest remains **28/28**;
- selector430 and first427 remain unchanged;
- routing identity map remains unchanged;
- benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation
  counters are all **0**.

No package repair, executable-mode repair, rerun, source/test/fixture/selector/routing mutation, compile, relink or generated
runtime discovery occurs.

## 5. Regression categorization and bounded root-cause analysis

Open `M5-CP3-TB1-R11-R1-CAND-01` as:

**OPEN / PRODUCT SEMANTIC RED / PERIODIC ACTION CORRESPONDENCE FRONTIER / FAILED RECOVERY / ROOT-CAUSE SUBPREDICATE UNRESOLVED / NON-STABLE / OWNER `M5-CP3-TB1-R11-R1-REV` / +0.**

The runtime narrows the failure more strongly than invalid R11 could. Exact candidate source contains CB12's semantic
Forward-occurrence -> Reverse-occurrence binding before `generator_route_for_span(...)` and `periodic_action_for_pair(...)`.
Because the observed typed reason is `PeriodicActionCorrespondenceMismatch`, runtime has already passed same-region pair shape,
distinct occurrence, semantic Forward/Reverse selection and generator-route availability. It stops at the subsequent action
correspondence guard.

That guard deliberately coalesces two outcomes:

```text
!periodic_action_for_pair(directedForward, directedReverse, generatorRotation)
OR
generatorRoute.rotation != action.rotation
```

and `periodic_action_for_pair(...)` itself can reject missing chart authority, scale mismatch, branch-rotation correspondence,
or either exact lattice endpoint mapping. Current PASS-path evidence does not publish those operands, and the produced test throws
before its independent witness values are emitted. Therefore EXEC can prove the exact **frontier**, but cannot honestly choose the
failing subpredicate or decide whether CB12 is an insufficient fix of the R10 `RP-01` candidate versus a distinct latent
product/test-authority defect. That adjudication belongs to mandatory Review.

Diagnostic comparison only: after removing timing text, fresh R11-R1 row4/5 raw logs are byte-identical in content to invalid
R11's row4/5 logs. This comparison is not semantic carry-forward; R11-R1's own complete evidence is the authority.

Stable accounting remains **50 events / 14 categories / 36 recurrences** because this candidate is non-stable pending Review and
does not establish a new accepted-green -> red transition. Produced-witness debt remains **3**. The two nonzero-Z4 M5 debts remain
open.

`M5-CP3-TB1-R11-EXEC-CAND-01` closes as **ORCHESTRATION CORRECTION RUNTIME-CONFIRMED / NON-STABLE / +0**: CB13's external
temporary manifest produces a complete **912/912** result on the full retry.

## 6. Authority and successor

CB12 candidate `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188` remains **unpromoted**. Accepted runtime authority remains
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Selector publication remains
prohibited; no M5 debt or inherited observation is discharged by EXEC.

The mandatory runtime-free successor **`M5-CP3-TB1-R11-R1-REV`** has completed; its retained authority is
`Architecture_M5_CP3_TB1_R11_R1_Review_Record.md`, with exact successor `M5-CP3-CB14`. The consumed Review plan resolves through
`M5_Consolidated_Record.md` §5 and git history.

## 7. Operational process note

At turn entry, the required `STATUS` beacon was published first. A single batched connector read of six repository documents was
then issued before the turn-local `READ_MODE` choice was explicitly recorded, violating the conservation policy's pre-read gate.
The miss was stopped immediately: `READ_MODE=snapshot` was selected, exact snapshot run `35777589896` was acquired and verified
**5298/5298**, and all subsequent source/document analysis before remote mutation used that local snapshot. No Directional runtime
or immutable-candidate evidence depends on the premature document read, so it does not affect the semantic ledger; it is recorded
here rather than normalized away.
