# M5-CP3-TB1-R8 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R8-EXEC`
**Boundary:** artifact-only Test + Benchmark
**Result:** **COMPLETE / MECHANICALLY COMPLETE / 444 PASS + 2 SEMANTIC RED / ROW6 WITNESS RECOVERY PASS / ROWS4-5 STOP AT `InvalidBoundedDiskChart` / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R8-REV`

## 1. Immutable candidate and execution authority

R8 consumed CB9 candidate artifact `10660365136` exactly as packaged from source
`1023eea6090a1f6c2d47ecaceb1099967c32e6c2`. Candidate provider/download SHA-256 is
`30333b2edbcd011ca52ae9e7e134884f72f4425a56103f179b6a3b6b3d1b0729`; root `SHA256SUMS` is **28/28** at
`9cfe8fac63bf730c59b271eec7ee5948debca285d73eec4b9cbc81396b58e464`; packaged source archive SHA-256 is
`38dff143f89ee882cd40f85d2344fb96b68f87eb864d52a352a5404e244a5bbc`. Compile-boundary authority remained
`runtimeExecution=false` with explicit GMP/GMPXX linkage.

Accepted routing/selector authority was reused unchanged: artifact `10592987234` at SHA-256
`352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, identity-map SHA-256
`7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, selector430 SHA-256
`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, and first427 SHA-256
`f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Authoritative runtime run/job is `35652063644 / 106506627509`, observer/event SHA
`da565dc038a28a1823974361d61d4ff03050ab19`. Result/log artifacts are
`10662697929 / 10662947670` at SHA-256
`7ad85812cba83c43d293e2c2eccb1fc7536d34115ec682e548c0911f7f643917 /
87a09731e884023d3d1504940c24a3db21587ec58a8a192fb90833656686b632`.

The historical orchestration template remains commit `1bc3ebcbd90997a9c4503ea2d2b7918556475b2a`, SHA-256
`752deb7e8d5d879047f1d4619fdb3c564e93e6d3d2e68b8affb9f19a47b997a3`. R8 materialized template SHA-256 is
`a148f4839fdeca91e493d2db50a100e9e6c09163c163d9ae5cb0691c9b90380c`; writer SHA-256 is
`d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`; rendered-driver SHA-256 is
`75b4e1483746dabf2b015e0be0484739e340083e7d9be28508d65f1e02bcdf08`.

## 2. Frozen 446-process execution result

All **446/446** planned fresh exact-filter processes executed to organic completion. Every row selected exactly one test and
skipped zero. Benchmark executions were exactly **0**. The frozen semantic vector is **444 PASS / 2 RED**:

| Gate | PASS | RED |
|---|---:|---:|
| reviewed mechanism | **9/9** | 0 |
| focused retained-value atlas control | **1/1** | 0 |
| produced torus | **4/6** | 2 — ordinals 4/5 |
| selector430 | **430/430** | 0 |

Produced ordinals 1–3 remain PASS, preserving the two already-reviewed production debts. Produced ordinal 6 now also PASSes,
so the corrected independently absent/unowned/unselected relation witness executes through materialization and invariance rather
than colliding before insertion. Accepted selector ordinal **408** and protected ordinals **191 / 192 / 247** remain PASS.
No accepted selector regression is introduced.

## 3. Produced rows 4–6 and the new runtime frontier

Rows 4 and 5 both reach the CB9 nonzero-field helper but fail before their relation/direction/tamper discriminators:

| produced ordinal | identity | exact observed boundary | raw SHA-256 |
|---:|---|---|---|
| 4 | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | exception: `torus nonzero-Z4 source witness producer failed: InvalidBoundedDiskChart` | `05d98e8e18a040311536ae0824940000625b75f0e9026859058a412a50230a7c` |
| 5 | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | same `InvalidBoundedDiskChart` exception before the intended tamper | `6cb85b651ef100116c4958fadb20b9201a1978046aaa4ad9dd8869e967cff917` |
| 6 | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` | **PASS** | `573c4fcd529496d2a8b0d0c7cf82751bef2c7d66058894c98a63bdd2471b2cdf` |

The helper's control flow reaches `require_produced(..., "torus nonzero-Z4 source witness")` only after finalizing the authored
field and finding at least one nonzero row408 hard-edge transition; R8 therefore advances beyond R7's “no genuine nonzero source
transition” precondition. It does **not** establish the later source/A3-selected directed witness, published relation, direction
agreement, materialization, or tamper discriminator because production returns `InvalidBoundedDiskChart` first. EXEC does not
infer whether that frontier is test-witness admissibility or a product defect. Mandatory Review owns that localization and may not
treat the unexecuted downstream assertions as evidence.

Row6 satisfies the runtime falsifier for `M5-CP3-TB1-R7-CAND-03`, but EXEC does not close that non-stable candidate; mandatory
Review owns its adjudication and any debt/observation disposition.

`M5-CP3-TB1-R6-REV-OBS-01` remains unadjudicated because rows4/5 never reach the directed product relation comparison. The two
M5 nonzero-Z4 debts likewise remain open in EXEC.

## 4. Immutable postflight and evidence integrity

Postflight is exact:

- package byte+mode census unchanged;
- packaged-source byte+mode census unchanged;
- execution-view byte+mode census unchanged;
- candidate root manifest remains **28/28** after execution;
- selector430, first427, and routing identity-map authority remain unchanged;
- `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`;
- configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters are all **0**;
- benchmark execution is **0**.

The final result artifact contains **913 files** including `SHA256SUMS`; the recursive self-manifest covers **912/912** other
files and verifies completely. `SHA256SUMS` itself hashes to
`f3ede0f999eb77b73abf71aa3729b5631fe627dffabc15c7755bc6faee9effcc`. Independent local closeout audit re-hashed all 446
raw logs against their ledger rows, re-counted all exact-one/zero-skip outcomes, and reverified the protected selector rows and
complete self-manifest.

No source, test, fixture, selector, package byte, executable mode, routing authority, or accepted runtime authority was mutated
in this Test + Benchmark turn.

## 5. Authority and accounting disposition

R8 is mechanically complete and semantically RED. EXEC records runtime progress on the existing non-stable witness-authority
work but does not classify the `InvalidBoundedDiskChart` frontier, promote the candidate, discharge debt, close observations,
or authorize selector publication.

Accepted runtime authority remains package/source
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Stable accounting remains
**50 events / 14 categories / 36 recurrences** and project produced-witness debt remains **3** pending mandatory Review.
Candidate `10660365136` remains **unpromoted**.

Exact successor is mandatory runtime-free **`M5-CP3-TB1-R8-REV`**. Review must independently re-derive the candidate/result
bytes and 444/2 vector, adjudicate the row6 recovery evidence, localize rows4/5's `InvalidBoundedDiskChart` frontier without
inventing a cause, decide the status of `M5-CP3-TB1-R7-CAND-02`, `M5-CP3-TB1-R7-CAND-03`,
`M5-CP3-TB1-R6-REV-OBS-01`, and `M5-CP2-TB1-REV-OBS-01`, and freeze the next bounded turn. No same-turn semantic repair,
promotion, debt discharge, or selector publication is authorized by EXEC.
