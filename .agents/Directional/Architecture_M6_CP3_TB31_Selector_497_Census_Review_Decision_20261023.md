# RA-145 — TB31 independent selector-497 census Review (2026-10-23)

**Turn:** `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS-REV`. **Verdict:** TB31 is independently verified as an accurate, regression-free *candidate*, **not** CP3 gate acceptance. Exactly 472/497 PASS, 25 inherited RED, 0 INVALID. The ten TB28 RED→PASS improvements and zero PASS→RED are independently re-derived. This Review does not authorize source, test, fixture, selector or runtime changes.

## Primary evidence and independent re-derivation

- Fetched immutable GitHub result `12506242253` (run `39959505758`); outer ZIP SHA-256 `97828fac57a63b5d8ca85ef0e5fd35fb7d5ed71c2b2579cd463bacc20d5e947b`; **1,000/1,000** internal manifest digests passed. Rehashed all **497 raw logs** against `ledger.tsv`. Original 497-row Review-owned manifest SHA-256 `b1c135d429f8c659e190f648b8678669cb7c14d393e0db9069568ea3838aa43e` matched, field by field, all row numbers, kinds, identities, test names, owning binaries, expected verdicts, and observed verdicts. All rows ran once with no skips; exits and verdicts agree.
- Independently joined by `phase:ordinal` to committed TB28 `Architecture_M6_CP3_TB28_Selector_497_Full_Ledger.tsv` (SHA-256 `44c8a6ac427a8ff501fe21b9218836dec0dce6a75d8b6302ed1225cdcb21c360`): TB28 462 PASS/35 RED; TB31 472 PASS/25 RED; 487 outcome-unchanged rows and **only ten** verdict changes: `focused30:3,22,23`, `selector:139,140,142,211,219,227,230` (all RED→PASS). There are no PASS→RED. `133` raw log digests differ; changed log bytes alone are not a verdict regression or evidence of a new cause.
- `execution-boundary.json`: 497 planned/executed, 472 PASS, 25 RED, 0 missing/skipped/duplicate/control-bad/unexpected-pass; `postflight=true`, `exit=0`, `compile=false`, `configure=false`, `relink=false`, `benchmark=false`. The same CB29 package `12492950387` and source `2602e7398cdc6f1281abe11a758de35166b6590c` were reused without rebuild.
- Frozen component SHA-256: focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`; selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing receipt `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. No new selector was added; accepted-prefix extension check is not applicable.

## The 25 inherited REDs: evidential limits and owners

| Count | Exact identities | Independent first-failure evidence | Assigned owner and immediate falsifier |
|---:|---|---|---|
| 6 | `selector:220,221,296,302,304,439` | All logs throw at construction of direct periodic-owner fixture with `sourceAuthoritySite=face-gauge-missing`, `code=0`. Test-level factory precondition, **not proof of a product gauge defect**. | **FG01** definition: independently reconstruct legal face-gauge-producing input; falsifier is a valid generated product with matching gauges where the factory still rejects, or evidence that fixture violates a frozen contract. |
| 7 | `selector:189–195` | Exception says `periodic-route fixture source A3 unavailable;code=CycleTransportMismatch;topologyRegion=0`. A3 code appears in exception metadata; **the route-level error locus is not independently isolated**. | A3 cycle-locus diagnostic first; falsifier: exact source-side transport/cycle mismatch independently located and reproducible before fixture abort. |
| 7 | `selector:174,201,204,242,247,250,405` | No authoritative typed reason. `174` aborts with `DCEL consistency check failed`; `201` missing terminal vertex; `204,242,247` expected rejection but got produced; `250,405` expected produced but got rejected. | Seven per-row producer-versus-oracle classifications, including RA-92.3/93.3 fixture debt for 174/242/250; require source-side first-failure pin and independent witness. |
| 1 | `focused30:12` | A5 `OccurrenceHardRailTransportMismatch` observed in raw log. | A5 relation transport owner; test rigid/face-gauge invariance and source-of-label before any rewrite. |
| 1 | `cp3entry:4` | `open-rail-chain` site with missing produced front. | A4 open-chain producer owner; first prove actual paired chain produced rather than assuming input rail implies output. |
| 1 | `selector:442` | A3 `SingularityMismatch;sourceEdge=(2,3)`, `seamBuilt=false`. | A3 singularity/fixture definition; compare expected singularity and source-edge transport before modifying the code. |
| 2 | `cp3entry:1/2` | D1 gauge-delta test found **zero odd** pairs among five; D2 found no actual A4 two-carrier certificate. | DEFN-T1 witness construction, not an accepted runtime failure of the intended later condition. |

Each row occurs exactly once; group counts sum to **25**. The above is first-failure ownership and explicit uncertainty, not a declaration of seven product root causes. RA-144.2's owner list is retained, with A3 `CycleTransportMismatch` explicitly qualified as a fixture-construction exception.

## Decision, sequencing and exclusions

- **Non-vacuity:** all 472 `GUARD` rows are independently observed PASS with real `exit=0`; all 25 pre-registered RED rows execute and fail as predicted. Ten formerly-RED rows now pass, including four RA-142 clause-precedence oracles; this is behavioral evidence but not a proof of CP3 direct-output acceptance. There are zero newly observed accepted-green losses; classify as candidate/non-stable, not a new stable regression event.
- **Carry RA-144.2/144.3:** immutable census prediction discharged; owners above remain open. Frozen stable **66 events / 17 categories / 49 recurrences**, produced witness debt **1**, last accepted CP2 **491/491**, rejected R3 **403/497**; TB28 462/497 is superseded by **TB31 472/497 candidate**, CP3 still unaccepted, RP-01 open, RP-02 UNREACHED, Gate C suspended. No witness promoted.
- **Exactly one successor:** `M6-CP3-DEFN-FG01-RP01-PERIODIC-FACE-GAUGE-FACTORY-CONTRACT` — **Definition only**, initially the six `face-gauge-missing` factory rows. Examine current factory and fixture construction against frozen gauge contracts, disambiguate fixture debt vs producer contract, write a finite signed decision and testable predictions before authorizing any CB. Stop if independent source and contract evidence cannot select an unweakened option; refer to a separate Review, not speculative implementation. Subsequent A3 cycle, untyped seven, A5, open-rail, selector442 and DEFN-T1 remain *planned, not authorized*; `DIAG-RETAIN`, `DEFN-SEAM-NZ`, Periodic remain deferred by existing gates.
- **Boundary:** evidence review and documentation only; no Directional runtime, compile, source, test, harness, workflow, selector or benchmark mutation. Review was independently re-derived from archived bytes, not the prior TB31 narrative.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Frozen 30, 12, 449 and 449 receipt hashes above; no added selector, so no new prefix comparison |
| Decisive claims independently re-derived | Outer ZIP, 1,000 file hashes, 497 logs, 497 manifest joins, 497 TB28 joins, transitions and RED inventory |
| Non-vacuity checked | 472 control exits and ten independently changed RED→PASS outcomes; all 25 failures reproduced |
| Prior obligations discharged/carried | RA-144.3 census discharged; RA-144.2's 25 cases carried to seven groups; RP-01 and produced witness debt retained |
| Stable accounting | 66 / 17 / 49, debt 1; CP2 491 accepted; TB31 472/497 candidate; frozen 497 selector |
| New candidates/obligations recorded | No stable regression; A3 fixture exception distinction and FG01 owner recorded in tracker |
| ORIENTATION currency line | Updated to RA-145 and 472/497 candidate |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 no witness state change; §8 no new recurring pattern |
| CHANGELOG | RA-145 entry added |
| ROADMAP | CP3 current boundary updated; checkpoint not promoted |
| Selector manifest | No new selector or promotion; byte-frozen inputs unchanged |
| LESSONS | Existing source/evidence/non-vacuity lessons apply; no general new rule |
| Consolidation under CLEAN_UP_POLICY | No superseded per-turn files deleted; TB31 report, RED inventory and manifest remain live source of this review; earlier retained evidence still required for historical comparison |
| Successor frozen | `M6-CP3-DEFN-FG01-RP01-PERIODIC-FACE-GAUGE-FACTORY-CONTRACT` with objective and falsifiers above and in handoff |
| Turn boundary held | Review-only; no binaries executed or product/tests/selectors edited |
| review_check.py boundary | Executed locally: exit 1 because the source snapshot uses synthetic, single-commit Git history without `8b7299b43` or its blobs; **not** an authoritative PASS. Independent live GitHub comparison proves `8b7299b43764a6ba3444e5bc774a2f1b65e99731` is ancestor (`ahead_by=1063`, `behind_by=0`); baseline heading preservation verified 4/4 handoff, 1/1 orientation, 0/0 tracker; frozen selector/allowed-path checks passed separately. Exact-script real-history execution remains unverified. |
| `STATUS` lifecycle maintained | Entry beacon published; final beacon is written after document publication, preserving initial Started at |
| Pushed to origin, branch in sync | Workflow 39996844160 `drive_apply` succeeded; applied commit `464ec90fe8a40be4295078ac0b0c6f03fa6ced71` verified from immutable result artifact SHA-256 `0840f2598ce4f8b27acd29d7c13bec4d1623a9c4d1a4cb8ac8cee47895b12382`; GitHub compare confirms exactly seven authorized document paths; branch report readback verified. No local `git status -sb` claim (source archive is synthetic). Drive patch removed after push. |
