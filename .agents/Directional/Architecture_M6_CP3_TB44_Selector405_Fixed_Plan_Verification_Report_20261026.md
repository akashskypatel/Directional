# TB44 — selector405 fixed-plan verification (2026-10-26)

**Turn:** `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY`. **Execution result:** 4/4 distinct single-case processes executed; **3 PASS, 1 RED**. This is a valid focused semantic outcome, **not a four-case acceptance**. The positive selector405 is PASS, with off-gate guards 7614/7414 PASS and 8219 RED. Independent `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY-REV` must review before any corrective turn. There is no selector497/CP3 promotion.

## Immutable authority and execution

- Source: `c256671115c92f7dd55fea5d680feeac3cbb5190`; compile run [`40373930737`](https://github.com/akashskypatel/Directional/actions/runs/40373930737), package artifact `12674401457`, ZIP SHA-256 `38d88bbda3b6b768f1d243b9b121db6233a740d3b296ccd35a58a9d1e5932bd3`; 28/28 compile checksums already independently accepted in CB44-REV; GMP/GMPXX, `runtimeExecution=false` in the package.
- Frozen four-row manifest: `Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Case_Manifest.tsv` SHA-256 `f410b55091cd8cc4fec743e141d4277662165f4feb6aa82de0590d716e5a6a8a`.
- Artifact-only dispatcher commit `9eef47208c66da64bc2c844fe97d03f8343747b2`, source executor `e901e67fe2147bb71a096741550b85f327af1088`, [run `40387240269`](https://github.com/akashskypatel/Directional/actions/runs/40387240269). Schema validation and dispatch parse passed; compiled/Drive/noop operations skipped. Runtime job returned a nonzero harness verdict because one required guard was RED.
- Result artifact `12680557878`, ZIP SHA-256 `f1b300067c4020f0fd156b772785ee7a54b1e5deecdfcda91fb16afe3376b986`; log artifact `12680372908`, ZIP SHA-256 `4b647e282c7a14e891369bfb721a22fa98730dbc9ead68c9f983b03e6b0f1b98`.
- Local independent check: result archive's 10/10 `SHA256SUMS` members match, and all four raw logs match their ledger `log_sha256`. Each selected GTest ran once, none skipped or duplicated; postflight `true`. Execution boundary reports **no configure, compile, relink or benchmark**. Recorded `control_bad=1` reflects the semantic guard failure, **not package/orchestration corruption**. No test or fixture was modified in this TB turn.

## Frozen selection results

| Row | Identity | Result | Raw log SHA-256 |
|---|---|---|---|
| 1 POSITIVE | `selector:405` | **PASS** | `e50d6c65c20efd06d1e4086366917978ee043d949871935042077d27cb5d8085` |
| 2 GUARD | `phase10:7614` | **PASS** | `18830e7ea83575056c584308df40d6ce7b633fd5c31310c671a7cb182b302edf` |
| 3 GUARD | `phase10:7414` | **PASS** | `1cc9f33753e49a420ccd4ede47c9f06b118949f9c1bbbc0d4e8110ae7db1b65a` |
| 4 GUARD | `phase10:8219` | **RED** | `8d06f6ddd7867230d7f274c24d006bf893db3e14aa6a52fe61242db10e4171d8` |

**8219 observed failure:** `tests/SurfaceCellsPhase10Tests.cpp:8236` required the diagnostic substring `a2bProbeFailure=missing-terminal-A3-path`; actual output contains `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`. The trace records `a2bProbeCarrierPresent=1`, `a2bProbeA3Present=1`, `a2bProbeContactPresent=0`, `a2bProbeClosedChainPresent=0`, `a3ProbeContactPublished=0`, and `a3ProbeContactEndpointIds=none`. The case calls `build_fixed_plan_rectangular_hard_rail_network` with a hard-edge override but **without explicit terminal contacts or closed chains**, unlike the CB44-corrected 405 positive. This supports a **candidate fixture-authority/root-cause hypothesis**, not a proven production regression; independent Review must verify the expected negative condition is reachable after full rail provenance is supplied and check 7414's discriminating power. Do not weaken assertions, modify frozen selector, or claim the expected 8219 rejection occurred.

## Disposition and continuation

- The corrected 405 positive now passes, which is useful focused evidence against the previous fixture-only RED. It remains a candidate pending independent review, not a retrospective selector or CP3 promotion.
- The off-gate guards cannot substitute for positive acceptance. RA-161 P1 is **not discharged**: 8219 RED and 7414 non-vacuity need TB44-REV disposition.
- No new stable regression event established: the negative guard never supplied the complete production A2b rail provenance and no accepted-green loss was demonstrated; stable **66 events / 17 categories / 49 recurrences**, debt 1; last accepted CP2 **491/491**. Nine historical TB38 REDs have not been rerun as a complete selector and must not be retrospectively counted as recovered.
- Pending independent Review: rehash published evidence; inspect raw 7414 and 8219 sites, assess fixture provenance and reachability independently; determine targeted corrective action, if any. Do not run tests/build or touch code within the Review boundary.
- Procedural disclosure: before the exact snapshot was acquired, initial repository policy/handoff reads used direct connector inspection before the mandatory snapshot pre-read gate, contrary to the conservation policy. An exact source snapshot was later obtained and verified for local inspection; this does not retroactively eliminate the procedural miss. Tool invocation ledger was not retained exactly from the first call and is therefore **partial/unknown**, not an invented count.
