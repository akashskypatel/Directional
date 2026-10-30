# TB52C independent API-binary census Review — RA-175 (2026-10-30)

**Turn:** `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-REV`. Independent evidence disposition (review-only). Current working branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft. No native binary, compile, test, benchmark or code/fixture/selector source was executed or changed in this Review.

## Independent evidence and scope

- Exact CB52 semantic package SHA `7cf0857b4818186638ce77e4859adacbeebd288f`, artifact `12918290481` SHA-256 `89449f4f9c014c1d8c3235056c3dca2d2239ba136e09dd88e3e02710b253b5c1`; archived source identity retained. 28/28 packaged checksum entries independently verified.
- Executor original SHA `f9625d7d1cd1f1a072ffc02e126f266696736895`; source snapshot 5,992/5,992 checksums verified. Harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` is the existing P8 membership implementation, not run with `MEMBERSHIP_LEDGER` in this OBSERVE census.
- Frozen TB52C manifest SHA-256 `81395065279e6ae6590c6feea30b719d661a328ecd90bea7ad8ef0f3a3a474ed`; independent manifest-to-result row/identity/test/binary joins: 23/23 exact. Every case has one own-test GTest run/terminal marker; all 23 raw log bytes hash to their ledger SHA-256. Cases have unique names/identities, zero missing/skipped/abnormal/control-bad, and `execution-boundary.json` has postflight true.
- TB52C [run 41064596683](https://github.com/akashskypatel/Directional/actions/runs/41064596683), immutable result artifact `12981972265`, ZIP SHA-256 `bab1be73ce6ad4718fe2b4dc0c2a16d6ada43faf167737414fb6f7294605d845` and 49/49 internal checksums; result ledger independently sums to **22 PASS / 1 RED**. Diagnostic artifact `12982352433` ZIP SHA-256 `b482fc2ecf06c101596fc3dbd5bcb9a0dca7985bc0759a7ad02f0db81bf68b0a`. Workload job `124092773852` completed success because one RED is permitted by OBSERVE; it is not 23/23 test success.
- The 22 PASS cases have `exit=0`, one native own-test `[ RUN ]`, `[ OK ]` and terminal `1 test` markers. The RED `apicensus:19` has `exit=1`, `[ FAILED ]`, and first assertion at `tests/SurfaceCellTracingDisplayTests.cpp:107`; raw log SHA-256 `c1ff3c3e0e681b630cc9d33577bb3965dd2e46f32e4f2909c76e837939ff3354`.

## Row 19 classification and falsifier

`SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported` includes three stage-specific fixture contracts. Its `mechanical_feature` subsection asserts `terminalFailureLocus.sourceVertex.has_value()` and comments that the *field-transport atlas* should reject that fixture at a vertex. The observed native diagnostic instead states `tracing` and has no vertex locus. The atlas-specific premise of this test fixture is therefore **not established on the immutable package**. Classification: **API-DISPLAY, FIXTURE (candidate, non-stable)**, with an unproven underlying producer-change cause. Do **not** relabel this as a successful GUI stop-location test or disable its vertex assertion. A subsequent Code + Build owner must establish an independently stage-reachable atlas vertex rejection witness for the display contract, or justify an explicitly changed contract with a newly independently meaningful test; then a separate TB must validate it. If tracing now represents a different valid later-stage stop, preserve it as a separate independent display test, not as a substitute for the required atlas witness. Falsifier: a source-produced mechanical atlas rejection with a vertex locus under the exact test inputs, or evidence that a regression to a previously accepted green API test occurred; neither is present in TB52C.

Stable **66 events / 17 categories / 49 recurrences**, debt **1**, unchanged: row19 was not in an accepted required-green selector or accepted gate; this is not accepted-green loss. CP2 **491/491** remains last accepted; TB51 **831/831** remains reviewed candidate; selector497 and CP3 unpromoted.

## Five-binary TB52 freeze (not runtime acceptance)

- New manifest [`Architecture_M6_CP3_TB52_RP01_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB52_RP01_Full_Gate_Case_Manifest.tsv): **853 rows** = frozen TB51 831-byte-identical prefix plus 22 observed PASS API cases appended in original census order. SHA-256 `95a7af662fd94306c92145050eff18fa0cc57de4eed19d1e4704938fc5532211`; original 831-row manifest SHA-256 `d6961b598a450dd17b818f316249ecacd0fdc73a91d8a1e4e7dca2fa537eb7b4`. New API rows are `GUARD`, expected PASS, `asserted_site=-`; none silently asserts a new topology/semantic contract.
- New deferred ledger [`Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v2.tsv`](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v2.tsv): **86 rows** = original 85-byte-identical prefix plus `apicensus:19` (global packaged-test census row 935), categorized API-DISPLAY/FIXTURE. SHA-256 `77c1d33b25f65837aa24c446b99657bfc1932fb8ab7636cc9c3ded598c38c78d`; original 85-row ledger SHA-256 `6f7eb9137afda0fc8066883d73058d6e843158751e7356e1dd468bc891be6df5`.
- Static uniqueness and disjointness: 853 gated + 86 deferred = **939 distinct (binary,test)** pairs across the five shipped binaries, no overlaps or omissions relative to the 831+85+23 source-bound declarations. Class counts **50 FIXTURE / 7 PRODUCT / 24 OPEN / 5 RETIRE**. Exact P8 `MEMBERSHIP_LEDGER` preflight must independently list actual packaged binary tests at TB52 before any native row runs; the static join does not replace that dynamic check.
- **TB52 execution falsifiers:** P8 listing reveals unexpected/unpackaged/stale/duplicate tests, any historical 831-prefix drift, manifest/ledger hash mismatch, any of 853 test cases non-PASS, unexpected extra source/test edits, incomplete or nonclean postflight. Do not bypass or weaken any check. Full-gate success remains candidate-only until separate TB52-REV.
- Retain RA-174 RP-01 closure blockers rows 223/225/261 plus O9. The 86 off-gate rows block CP3 exit, not each other’s immediate review. P13 design matrix, O7 oracle binary and CP3 product obligations remain unresolved.

## Authorized successor

Exactly one next turn: **`M6-CP3-TB52-RP01-FULL-GATE-EXEC`** (TB-EXEC, implementation track): run the frozen 853-row gate against unchanged immutable CB52 artifact `12918290481`, using executor P8 with `MEMBERSHIP_LEDGER=.agents/Directional/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v2.tsv` and exact `MEMBERSHIP_LEDGER_SHA256=77c1d33b25f65837aa24c446b99657bfc1932fb8ab7636cc9c3ded598c38c78d` and gate manifest `.agents/Directional/Architecture_M6_CP3_TB52_RP01_Full_Gate_Case_Manifest.tsv` SHA-256 `95a7af662fd94306c92145050eff18fa0cc57de4eed19d1e4704938fc5532211`. No build/relink/reconfigure/fixture repair, no observations masked as PASS, no selector/CP3 promotion. The following separate Review is `M6-CP3-TB52-RP01-FULL-GATE-REV` conditional on a valid TB result.

## Transport verification

Initial apply run `41093137786` rejected comma-delimited intended paths; corrected semicolon-delimited header retained the identical diff body and succeeded in run `41093583465`. Both consumed Google Drive staging files were owner-deleted. No test, code or runtime was changed.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: selector497 unchanged and not promoted; TB51 831-row gate prefix independently byte-identical, SHA-256 `d6961b598a450dd17b818f316249ecacd0fdc73a91d8a1e4e7dca2fa537eb7b4`. |
| Decisive claims independently re-derived | 23 native log/manifest joins, 22/1 outcomes, 49/49 hashes, new 853/86 membership/disjointness. |
| Non-vacuity checked | 22 separate successful GTests; RED row19 proves the vertex-locus assertion is reached and fails, not a green surrogate. P8 must still run dynamically at TB52. |
| Prior obligations discharged/carried | RA-174 F1 API census covered; O14 P8 implemented but needs TB52 runtime; RP-01 223/225/261/O9 and CP3 obligations carried. |
| Stable accounting | 66/17/49, debt 1, CP2 491/491 accepted; TB51 831/831 candidate, selector497 frozen. |
| New candidates/obligations recorded | API-DISPLAY/FIXTURE `apicensus:19`; tracker and deferred ledger v2. |
| ORIENTATION currency line | `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-REV`, 2026-10-30. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 refreshed; §4 witness status updated via API display row19; §8 new example of stale stage-specific witness, prior stale next-step statements replaced. |
| CHANGELOG | 2026-10-30 RA-175 entry. |
| ROADMAP | M6 CP3 still in progress; no milestone status change, n/a for status migration. |
| Selector manifest | n/a: frozen required-green selector497 not modified or promoted; separate TB52 case manifest created. |
| LESSONS | Existing non-vacuous, stage-reachability and accepted-green classification principles reused; no new general rule. |
| Consolidation under CLEAN_UP_POLICY | No superseded CP3 report folded: TB52C is current immutable census evidence, TB51 is prior accepted-candidate gate baseline, RA-174 is active closure authority; deleting any would discard still-live evidence. Consolidated family record unchanged. |
| Successor frozen | `M6-CP3-TB52-RP01-FULL-GATE-EXEC` with listed P8, native, prefix and postflight falsifiers. |
| Turn boundary held | Review-only; no executable test/benchmark, rebuild, production/test/selector mutation. New case-manifest/ledger are scheduling metadata, not code or runtime results. |
| review_check.py boundary | Static tool executed on synthetic snapshot Git baseline: failed durable-rewrite ancestor/source checks because the authentic remote commit ancestry is absent; not a verified boundary PASS. Scope verified by exact changed-path inventory and unchanged production/test/selector files. |
| `STATUS` lifecycle maintained | Started at 2026-10-30T16:21:59Z, resumed at 2026-10-30T16:43:37Z; final root beacon follows closeout. |
| Pushed to origin, branch in sync | Patch pushed at `254b0c72`; subsequent cleanup `997a6089` removed only two temporary files; remote compare verified. `git status -sb` cannot verify the connector-only workspace; not claimed. |
