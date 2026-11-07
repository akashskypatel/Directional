# RA-177 — TB52 independent five-binary full-gate Review (2026-10-30)

**Turn:** `M6-CP3-TB52-RP01-FULL-GATE-REV` (TB-REV, Review track). Read-only analysis of immutable primary evidence; no production/test/fixture/selector change, no native binary execution, compilation, relinking or benchmarking in this Review. Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8.

## Independent primary evidence and scope

- Reopened result artifact **13004891149** from [run 41100261157](https://github.com/akashskypatel/Directional/actions/runs/41100261157), independently recomputed ZIP SHA-256 **`ba18016515e810f8cecdd4da500a6026eefe973a11f9afe55879fd1ae948f684`** and 1,714/1,714 `SHA256SUMS` entries. The result contains 853 separate `raw/<row>.log` plus 853 resource logs. Checked ordered ledger keys, each log's ledger SHA-256, test-name presence, GoogleTest terminal one-test PASS, exit=0, selected/executed/passed=1 and no skipped tests, for all 853. No duplicate binary/test identities, no missing or extra raw logs.
- `execution-boundary.json` states immutable package **12918290481**, source **`7cf0857b4818186638ce77e4859adacbeebd288f`**, 853 planned/executed/passed, zero RED/ABNORMAL/missing/skipped/duplicate/control-bad/unexpected-PASS/later-positive-RED/site-bad, `postflight=true`, `exit=0`; `compile=false`, `relink=false`, `configure=false`, `benchmark=false`.
- Independently downloaded package 12918290481, ZIP SHA-256 **`89449f4f9c014c1d8c3235056c3dca2d2239ba136e09dd88e3e02710b253b5c1`**, verified **28/28** packaged hashes, source archive SHA-256 **`c02a0be4b25d64eca2c10e5681cd8721a465a848a3d17044275370eac132553b`**, packaged source commit equal to the result's source, and `runtimeExecution=false`, `exactArithmeticBackend=GMP` for Code+Build.
- Verified source snapshot run [41119061588](https://github.com/akashskypatel/Directional/actions/runs/41119061588), source/event SHA **`0052dedf535a330ec0ae1c00c9e1cb6905eee6e9`**, artifact 13007960839 ZIP SHA-256 **`3078bfdf48c35410132f0cdf31543e5170996311791673c02d65bf61be54b891`** and 5,998/5,998 source hashes, without using source snapshot as native runtime authority.

## Historical-prefix and five-binary membership review

- Frozen TB52 GATED manifest `Architecture_M6_CP3_TB52_RP01_Full_Gate_Case_Manifest.tsv` is **853** entries, SHA-256 **`95a7af662fd94306c92145050eff18fa0cc57de4eed19d1e4704938fc5532211`**. Its first 831 complete byte lines, including header, equal the frozen TB51 manifest, SHA-256 **`d6961b598a450dd17b818f316249ecacd0fdc73a91d8a1e4e7dca2fa537eb7b4`**. The archived TB51 831 rows retain identical kind/identity/test/binary order; TB51 execution result 12963899691 is still only a reviewed candidate baseline. Runtime log hashes are expected to differ between distinct executions and are **not** used as a selector-prefix identity test.
- Deferred ledger v2 is **86** rows, SHA-256 **`77c1d33b25f65837aa24c446b99657bfc1932fb8ab7636cc9c3ded598c38c78d`**; first 85 complete byte lines equal v1 SHA-256 **`6f7eb9137afda0fc8066883d73058d6e843158751e7356e1dd468bc891be6df5`**. Independently counted **50 FIXTURE / 7 PRODUCT / 24 OPEN / 5 RETIRE**, with the appended `apicensus:19` / census row 935 remaining a **FIXTURE**, not promoted to the gate.
- The actual package-listing preflight contains **939 distinct binary/test pairs**, partitioned exactly into **853 GATED + 86 DEFERRED**. Independently joined the 853 ledger binary/test pairs to the 853 membership GATED pairs: zero missing, extra or duplicates. The 22 new gated API entries (`apicensus:1–18,20–23`) all separately executed and passed. `apicensus:19` was *not* executed in TB52 and is still red in TB52C evidence.

## Non-vacuity, exclusions and disposition

**Decision: ACCEPT the TB52 result as the new independently reviewed, Linux/x86-64-specific 853/853 GATED *candidate*, superseding TB51's reviewed 831/0 candidate. REJECT selector497 promotion, RP-01 closure and CP3 acceptance.** This decision recognizes real selected-case executions and the independently verified five-binary membership boundary, not the correctness of deferred tests, the direct-production matrix, or platform-independent atlas semantics.

The 86 off-gate rows remain unexecuted here and unresolved, including terminal-path census rows **223** (FIXTURE), **225** (FIXTURE), **261** (OPEN), plus separate **O9** missing A4 junction-path witness. The package-membership omission **O14/P8** is discharged for this exact package/manifest census (all five test binaries included), but that does not discharge obligations represented by deferred rows. RA-174.3's RP-01 obligations are unchanged. Stable accounting remains **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**; no newly demonstrated accepted-green regression. CP2 **491/491** remains the last accepted semantic runtime. Selector497 stays frozen/unpromoted, PR #8 draft/unmerged, M6-CP3 active.

**O15 remains a major CP3-exit defect** under [RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md): atlas gauge/sector choices use `atan2` plus `1e-10` tolerance on exact ties; `mechanical_feature` differs with FMA/platform. Eighteen green TB52 selected rows exercise this input on Linux but **cannot prove platform-independent exactness**. RA-176's independent exact half-open result is 3 at vertices 10/35/47/71, and the row 935 stale negative atlas-rejection premise must be replaced by an independently valid witness only **after** exact predicates are repaired. Do not reinterpret row 935 as a producer regression without accepted-predecessor proof. O15 is a CP3-exit obligation, not an RP-01 gate.

The gate is non-vacuous as selection/own-test execution: 853 native GTest cases were actually invoked and logged, and P8 counted all 939 packaged tests rather than only the four original gate binaries. This **does not** establish that every positive test is a non-vacuous producer-path witness; no blanket production or D0-acceptance inference is made.

## Frozen successor and falsifiers

**Exactly one next canonical turn:** `M6-CP3-DEFN-RP01-TERMINAL-PATH-WITNESSES` (DEFN / Review track), as authorized by RA-174.3 and the current handoff. It must independently establish actual production reachability and necessary corrections for rows 223, 225 and 261, and rule on O9. Required positive controls must reach their producing stages; each negative must fail the intended guard on a valid preceding producer product. No CB, TB, test/fixture repair, selector change or promotion in DEFN. If source tracing disproves the proposed owner or the witness is unreachable, record the falsifier and re-define under Review instead of fabricating a green test. **Separate carried sequence:** `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` (O15) → CB55/CB56 → TB54 → TB54-REV, without allowing RP-01 closure to waive O15.

## Procedure limitations

The source/document read-mode decision was not made before the initial direct handoff/policy reads. The mistake was corrected by selecting snapshot mode and using one independently verified 5,998-file source snapshot for all subsequent source/document inspection. A complete per-tool call ledger was not initialized before the first invocation; exact call totals cannot be claimed. This does not change the native evidence disposition.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | No selector promotion. TB52 831-row historical manifest byte-prefix proven (`d6961b598a450dd17b818f316249ecacd0fdc73a91d8a1e4e7dca2fa537eb7b4`); ledger v2 85-row historical prefix proven (`6f7eb9137afda0fc8066883d73058d6e843158751e7356e1dd468bc891be6df5`). |
| Decisive claims independently re-derived | Result ZIP, 1,714 inner hashes, 853 native/ledger joins, 939 listing census, 853 GATED versus 86 DEFERRED, classes, historical prefixes, 28 packaged hashes and source identity. |
| Non-vacuity checked | All selected own-test GoogleTest cases ran; membership preflight proves package completeness. Individual semantic producer reachability beyond actual assertions not universally inferred. |
| Prior obligations discharged/carried | O14/P8 package-membership scope discharged for this frozen package; O9, RP-01 223/225/261, O15 and other CP3-exit conditions carried with named owners. |
| Stable accounting | 66/17/49, debt 1, CP2 491/491 last accepted, TB52 853/853 now reviewed candidate; selector497 frozen. |
| New candidates/obligations recorded | No new stable or candidate regression; tracker amended with this review disposition; existing O15 preserved. |
| ORIENTATION currency line | Updated to this Review and current candidate. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 unchanged because no witness changed; §8 unchanged because no new reusable defect pattern beyond RA-176. |
| CHANGELOG | RA-177 Review entry prepended. |
| ROADMAP | CP3 remains active; current reviewed candidate updated, no checkpoint status change. |
| Selector manifest | No selector added/accepted; frozen manifest and deferred ledger unchanged. |
| LESSONS | Existing **Gate membership is the proof boundary**, **Separate historical baselines, candidates, regressions, and accepted gates**, **Check completeness against what is built**, and **Check evidence chronology and scope** apply; no new lesson. |
| Consolidation under CLEAN_UP_POLICY | No superseded report removed: TB51 remains prefix-baseline authority, TB52 current gate evidence, RA-176 active exactness authority. No safe redundant document to fold without losing live provenance. |
| Successor frozen | `M6-CP3-DEFN-RP01-TERMINAL-PATH-WITNESSES`, falsifiers above; O15 sequence carried separately. |
| Turn boundary held | Read-only artifact/source inspection; no runtime, compile, test/production/fixture/selector mutation. |
| review_check.py boundary | Executed locally on the 5,998-file verified source snapshot with a synthetic Git baseline; selector hashes passed but overall exit 1 because the durable-rewrite ancestor/source checks require authentic Git history absent from this artifact. This is **not a boundary PASS**; exact touched-path and `git diff --check` inspection used as partial alternative. |
| `STATUS` lifecycle maintained | Entry/resume beacon established; final closeout beacon must be last repository action, preserving original started timestamp. |
| Pushed to origin, branch in sync | Not asserted by local snapshot; requires successful Drive patch application plus fresh remote comparison before final beacon. |
