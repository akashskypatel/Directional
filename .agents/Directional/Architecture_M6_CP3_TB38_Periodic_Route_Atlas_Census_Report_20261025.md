# TB38 — periodic route atlas census, artifact-only (2026-10-25)

**Turn:** `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS`. **Disposition:** 504-case execution valid, predicted **490 PASS / 14 inherited RED** observed; candidate census only, pending independent `…-REV`. No CP3/selector or stable acceptance promotion.

## Frozen authority and execution

- RA-154.4 manifest: `Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Case_Manifest.tsv`, SHA-256 `b27eecb6b4f6f32fd060b8510a0cabf71f86b8fe1028dbb10c36003867dcf8c2`; 504 rows. Original TB32 500 identities/test owners/order unchanged, except five RED→GUARD expectations at rows 231, 232, 235, 236, 237; four appended GUARD rows.
- Unmodified harness: `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`.
- Frozen CB36 binary package `12590917524`, source `038ae7fd7c290731c28225d2693a3e13866e325a`, ZIP SHA-256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`; packaged 28/28 SHA checks, GMP/GMPXX, `runtimeExecution=false` at build boundary.
- [Workflow 40185527486](https://github.com/akashskypatel/Directional/actions/runs/40185527486), dispatcher event `c706279579ab65f80e468e6218c0ea41a4f4352f`, runtime job `121145448280` success; skipped compile/drive/noop jobs, mailbox key `m6-cp3-tb38-periodic-route-atlas-census` on orphan `workflow-mailbox`.
- Immutable result artifact `12597140251`, ZIP SHA-256 `0cdfe445fbc5388b8e95331f87c4a291001645f30458001bb5426244022a9870`; independently verified **1,014/1,014** recursive SHA256SUMS entries and **504/504** raw log-to-ledger SHA256 joins.
- Exact manifest row/order, kind, identity, owning binary, test name, expected verdict: **504/504 matched**; distinct identities 504/504; each row executed one fresh process with no skips or missing cases. `execution-boundary.json`: `planned=504`, `executed=504`, `passed=490`, `red=14`, `missing=skipped=duplicate=control_bad=unexpected_pass=0`, `postflight=true`, `exit=0`. `configure=compile=relink=benchmark=false`.

## Residual comparisons — no unapproved credit

- The unchanged 497-selector subset measured **483 PASS / 14 RED**; TB32 measured **478 PASS / 19 RED**. Exactly five formerly RED cases (`selector:189/190/193/194/195`) are now GUARD/PASS as RA-154 predicted. Four appended guards (`tb36:quarter-monodromy`, `tb36:half-monodromy`, `tb36:directed-published-route`, `cb34:face-gauge-invariance`) PASS.
- **Unchanged assertion families versus independently verified TB32 artifact `12534679588` (1,006/1,006 SHA checks):** `focused30:12`, 174, 201, 204, 242, 247, 405, 442, `cp3entry:1/2/4`. `cp3entry:2` differs only in nondeterministic pointer address bytes, not assertion/expected or actual predicate.
- **191/192:** TB32 failed earlier with `periodic-route fixture source A3 unavailable; code=CycleTransportMismatch`. TB38 now reaches the intended `Rejected` assertion and observes **Produced / reason None**. This difference is explicitly predicted in RA-154.4, is not evidence of a newly passing oracle, and remains RED pending re-homing definition.
- **250:** remains `Produced` expected, `Rejected / PublishedProductRejected` observed (typed 68); no change in first asserted predicate. Its checked-factory sub-site is still unmeasured. RA-154.5 permits a separate diagnostic turn if this persists; **no diagnostic/test edits here**.
- No other first-failure assertion drift, GUARD loss, unexpected RED pass or manifest/hash/postflight integrity failure detected. All 14 RED are still defects/oracle debts, not accepted greens.

## Gate and handoff

The RA-154.4 **STOP → independent TB38-REV** boundary is satisfied as an evidence-only stop: no source, test, harness, manifest, selector, runtime package, or accepted stable ledger mutation is authorized. Independent Review must inspect raw witnesses and decide whether the observed 191/192 move constitutes the predicted oracle-ingress consequence. Carry stable **66 events / 17 categories / 49 recurrences**, debt **1**; CP2 **491/491 accepted**; TB32 **481/500 candidate**; selector **497 frozen**; RP-01 open, RP-02 unreached. The next turn is `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS-REV` only after this report and repository closeout are durable.
