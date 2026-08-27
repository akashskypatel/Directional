# M3-CP4c-0b TB-S1-EXEC Artifact-Only Test + Benchmark Report

**Status:** COMPLETE / EXECUTION GREEN / ROUTE TO TB-S1-REV
**Turn:** `M3-CP4c-0b-TB-S1-EXEC`
**Evidence source:** `4bb467806df99c70889394a323c17c13bc185ca3`
**Immutable package:** artifact `9655632444`, SHA-256 `c22e9b020e533ca8fc558bcafc3e138a062702a59bee68a097958b432d70bc5f`
**Boundary:** Test + Benchmark / TB-EXEC only; no configure, compile, relink, repair, generated discovery, or source/test/fixture/selector mutation.

## 1. Execution authority

The approved S1 execution plan from `Architecture_M3_CP4c0b_CB1_S1_Code_Build_Report.md` was executed against the exact GMP package above. The package preflight verified its recursive `SHA256SUMS`, source commit, archived executable modes, clean build-source status, `runtimeExecution=false`, and `exactArithmeticBackend=GMP`; the runner provisioned the GMP runtime libraries before executing the packaged binaries.

The temporary execution caller was schema-validated successfully before its workload was allowed to run. No repository timeout/watchdog was configured for the complete 346-identity gate; every gating identity ran in a fresh process to its organic result.

| Evidence | Identity |
|---|---|
| workflow run | `33097182476` |
| execute job | `98605092984` |
| trigger/event SHA | `77832e1b789eb5735c0b393f21476fbd7e73676b` |
| schema-validation artifact | `9656857388`, SHA-256 `3b12cceafeb6cfb3ada110d7dfed7e0700c7694cb97dc0e7e27b490bb843b670` |
| schema-validator log | `9656857856`, SHA-256 `3cc007df1fd9dbad6571b2e0cf3ea1292173b56f1fe00d171940c027fea98403` |
| raw TB result | `9656967036`, SHA-256 `dd1f8aa8f2346612beb445d7e5d6a8768a438e36c543e0b4d407b444523d85a4` |
| TB diagnostic log | `9656967437`, SHA-256 `667b9c54ad24e9e33855d3fd47a322593c4522bde4984177dfa593a1df7f6bb8` |
| observer log | `9656859884`, SHA-256 `b988cfce44017606058458fc563a256f985c89066f20b18b4d402490ce20ba3d` |

The downloaded raw-result artifact re-hashed locally to `dd1f8aa8f2346612beb445d7e5d6a8768a438e36c543e0b4d407b444523d85a4`, matching GitHub's recorded artifact digest.

## 2. Frozen 346 gate

The unchanged gating selector `.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt` retained SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` and exactly 346 unique identities.

- executed: **346**;
- selected exactly once: **346/346**;
- PASS: **346/346**;
- escaping C++ exceptions: **0**;
- repository-imposed timeouts: **0**;
- package/source/test/fixture/selector mutations: **0**;
- postflight immutable-package comparison: **PASS**.

Target distribution in the raw ledger was 200 producer identities, 75 completion identities, 41 validation identities, and 30 authority-kernel identities. This re-proves the frozen gate on the S1 diagnostic-only semantic source; it does not by itself accept any S2-S6 semantic correction.

## 3. S1 non-gating contact census

The separate non-gating selector retained SHA-256 `2550b9305284986c0af26677a881396bbeb61fd58304cdbbaac432c81da12806` and selected only `ResolvedBranchCorrection.ContactPredicateCensusIsPublishedNonGating`. It selected exactly once, exited 0, and contributed **zero gate credit**. All four `m3Cp4c0bS1` records are preserved verbatim in artifact `9656967036` as `s1-census-lines.txt` and structurally in `s1-census.json`.

| witness | population | status | contacts | proper / non-proper / unevaluated | requiresReview | A/B/C | nodes / source vertices | prior terminal kinds | event histogram |
|---|---|---|---:|---|---:|---|---|---|---|
| `two-ring` | included | reached | 0 | 0 / 0 / 0 | 0 | 1/0/0 | 9 / `[0]` | none observed because there were no shared-face contacts | `SingularityPortOrigin=1, FirstContact=3, TraceIntersection=1, MandatoryBarrierTermination=3` |
| `four-triangle-fan` | **excluded** fixture artifact | reached | 0 | 0 / 0 / 0 | 0 | 1/0/0 | 8 / `[4]` | none observed because there were no shared-face contacts | `SingularityPortOrigin=1, FirstContact=3, TraceIntersection=1, MandatoryBarrierTermination=3` |
| `sphere_prescribed` | included | **unreached** | **not reported** | **not reported** | **not reported** | **not reported** | **not reported** | **not reported** | **not reported** |
| `torus` | included | reached | 0 | 0 / 0 / 0 | 0 | 0/0/0 | 0 / `[]` | none observed because there were no shared-face contacts | empty |

The prescribed sphere stopped during tracing with the expected N1 typed rejection `TraceCombinatorialRecurrenceExceeded`: `traceSteps=65`, `traceStepBudget=9216`, `traceCombinatorialVisits=3`, `traceCombinatorialVisitAllowance=2`. Because the post-hoc census was never reached, **no zero-contact claim is made for the sphere**.

For every **reached included** accepted witness, `nonProperCrossingCount=0`, `unevaluatedCrossingCount=0`, and `requiresReview=0`. The diagnostic emitted no unexpected witness/status/error classification and its machine-readable `requiresIndependentReview` routing flag is false.

## 4. Stop-rule disposition

TB-EXEC records only the mechanical execution outcome and prescribed routing; interpretation belongs to TB-REV.

- The 346 gate is green.
- No timeout, escaping exception, package mutation, or unexpected diagnostic error occurred.
- No reached included witness triggered the S1 independent-review stop rule.
- Therefore the **only next state** under the pre-authored plan is evidence-only `M3-CP4c-0b-TB-S1-REV`.
- S2-S6 remain prohibited until TB-S1-REV reviews this evidence and plans the successor.

No new regression or regression candidate was observed. Stable regression accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt remains **5**, and the M3 package count remains **52** because TB consumed an existing immutable package rather than creating one.
