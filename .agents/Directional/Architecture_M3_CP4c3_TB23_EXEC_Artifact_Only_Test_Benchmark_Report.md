# M3-CP4c-3-TB23-EXEC — Artifact-Only Test + Benchmark Execution Report

- Turn: `M3-CP4c-3-TB23-EXEC`
- Boundary: immutable runtime execution + raw evidence preservation only
- Semantic/evidence source under test: `e12396d471c0754b112a40272a7992020ff49ced`
- Immutable package artifact: `9921914679` / `m3-cp4c3-cb25-package-result-33831662949`
- Package SHA-256: `db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7`
- Frozen plan: `Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md`
- Selector 397: 397 identities, LF SHA-256 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`

## Verdict

**TB23-EXEC terminates as ORCHESTRATION-INVALID / NO AUTHORITATIVE SEMANTIC LEDGER.**

The immutable CB25 package itself verified byte-for-byte, but the frozen runtime preflight required a known committed fixture to exist at the exact path resolved by the packaged test executables before Directional runtime began. The execution harness checked the extracted source workspace instead of that executable-relative runtime path. Runtime then began and 397 fresh processes were executed even though the packaged binaries could not resolve their required `test-data` fixture tree.

Per the frozen stop rule, those process results are preserved as raw execution evidence but are **not** promoted to semantic product/test results. No package repair, fixture relocation, rebuild, relink, replacement artifact, or diagnosis-driven probe was performed after runtime began.

The latest authoritative semantic runtime therefore remains **M3-CP4c-3-TB22: 387 PASS / 6 RED with accepted prefix 365/365**. CP4c-3 remains OPEN.

## Attempt inventory

### Attempt 1 — pre-runtime orchestration failure

- Run: `33833432331`
- Outcome: workflow orchestration failed before Directional runtime because the temporary caller's permission ceiling was too narrow for the reusable observer.
- Semantic result consumed: **none**.
- Correction: control-plane permission only; no source/test/build/package mutation.

### Attempt 2 — preserved but orchestration-invalid runtime

- Run/job: `33833497955 / 100901221113`
- Event/source control SHA: `cfbc42c9a352fd3829ed6750ebfb60eb449d6527` (temporary orchestration state only)
- Result artifact: `9922540133` / `m3-cp4c3-tb23-exec-result-33833497955`
  - Actions/downloaded ZIP SHA-256: `cd439a2646fc215252594a2bf5c3ae83e201d3bad252506d5c77e800ed600f3a`
- Diagnostic log artifact: `9922540522` / `m3-cp4c3-tb23-exec-log-33833497955`
  - Actions SHA-256: `6fc1d7ae0e742b28c5e1484bc8735212fa11f5c179693f905bc069697549e9df`

The workflow job itself completed successfully because the harness intentionally records semantic REDs without failing the job. That workflow success does **not** override the frozen-plan preflight violation.

## Static authority checks that passed

Before runtime, the harness verified:

- artifact ID/name and outer SHA-256;
- packaged `SHA256SUMS`;
- exact source commit `e12396d471c0754b112a40272a7992020ff49ced`;
- compile/preflight exit codes `0`;
- command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`;
- mandatory GMP/GMPXX evidence;
- all eight required compiled targets;
- archived executable modes;
- selector 365/393/397 counts and hashes;
- selector 365 and 393 exact-prefix proofs against selector 397;
- static identity-to-binary ownership: exactly one owner for each of 397 identities.

Static identity map SHA-256: `f0a5d494dbb4fb1d2faaa9cc82f3b6d064d96d0dc37e05ba53b15365d7165213`.

## Preflight defect that invalidates runtime

The frozen plan requires source fixtures to be materialized at the exact runtime path the packaged binary resolves before any Directional process runs. The packaged tests resolve the fixture tree relative to the executable under `package/test-data/...`; artifact `9921914679` contains no `test-data` tree. The harness instead verified fixtures under the extracted source workspace, so its `preflight_completed=true` flag is not a valid proof of the frozen requirement.

The preserved raw logs then show fixture-open failures at the missing executable-relative package path, including accepted-prefix identities. This is sufficient to classify the attempt as orchestration-invalid; TB23-EXEC does not interpret any downstream product behavior from that invalid launch.

## Raw invalid-attempt ledger — preserved, not semantic authority

The invalid attempt nevertheless completed all 397 selector identities one fresh process each:

- raw PASS: **342**
- raw RED: **55**
- raw accepted-prefix PASS: **327/365**
- raw ledger SHA-256: `839e95feea68bdff35c8c9b11ca22f486f3452413f82017888f17ffc76e85e8d`
- ordinals 394–397: `PASS, PASS, PASS, RED`
- D2 named-detail count: `0`
- CA2/CA3/CA4 row counts: `0 / 0 / 0`

These numbers are retained only to make the invalid attempt independently auditable. They are **not** regression accounting and do not supersede TB22's semantic ledger.

## Immutability and prohibited-operation evidence

The invalid attempt still proves the immutable artifact was not modified:

- package pre/post census SHA-256: `9c7b12f4beba6f64e4ab1af3980554ba7b9f46af535ec2d2f2a9650f0359a927` — equal;
- extracted source pre/post census SHA-256: `e7bec1591154b4d9d79cd64ad27871305f54a51ba15946dc2042b55f6d2d8654` — equal;
- `benchmark_execution=false`;
- `configure_execution=false`;
- `compile_execution=false`;
- `relink_execution=false`;
- `generated_discovery=false`;
- `package_repair=false`;
- `mode_repair=false`;
- `source_test_fixture_selector_mutation=false`.

No benchmark executed.

## Closeout boundary

TB23-EXEC has exhausted its permission to execute or repair. The preserved evidence must now be handed to **`M3-CP4c-3-TB23-REV`** for independent diagnostics/review and next-step adjudication. TB23-EXEC does not authorize a replacement package, fixture staging workaround, additional runtime probe, or corrective Code + Build turn.

`Regression_Root_Cause_Tracker.md` is intentionally unchanged in EXEC because no new authoritative semantic regression was established; the raw invalid-attempt REDs are execution-integrity evidence for TB23-REV, not stable regression events.
