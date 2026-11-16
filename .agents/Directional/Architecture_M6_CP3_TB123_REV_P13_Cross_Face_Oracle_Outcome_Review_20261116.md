# TB123-REV — independent cross-face oracle outcome (2026-11-16 UTC)

## Situation

Review turn `M6-CP3-TB123-REV-P13-CROSS-FACE-ORACLE-OUTCOME`. **Decision: accept the corrected oracle's static contract for the next independent full gate, not a full-gate or production outcome.** The focused TB123 report records two selected tests passing; the raw local execution archive is not available in the current repository snapshot or accessible Library. Consequently, the reported 2/2 process outcome is *reported evidence*, not an independently re-counted raw-log result of this Review. This is an explicit limitation, not an inferred pass.

## Background and source identity

- Immutable CB142 package: compiled semantic source `57b28b737fd92b083d24d882152dea186211f735`, artifact `14224898790`, reported outer SHA-256 `98f448f9e5b5ebcacbd1884ad4e62415d7c10d5878da0ccf1438654b4aeaf52b`; CB142 reported 28/28 internal hashes and eight GMP/GMPXX targets.
- TB123 [focused report](Architecture_M6_CP3_TB123_P13_Cross_Face_Oracle_Focused_Execution_Report_20261116.md) records row 948 and corrected row 949 each executed once, passed, zero skips, no timeout, no rebuild and unchanged package hashes. Its four negative cases are internal assertions of row 949, not four additional test executions. Neither a new GitHub Actions gate nor independent raw local logs is provided by that report.
- Reviewed source snapshot `400991ef178d728eee3a2f8f81d53cd6fa7dc86f`, workflow `43872284890`, artifact `14228207731`: downloaded ZIP SHA-256 `0a6da1cb3563b5e2c95fc9dd6cca7e10dee34d4d24d149f1e489b29ce2591fb2`; source TAR and 5,564/5,564 file hashes verified. GitHub compare from CB142 to this snapshot lists only documentation, the dispatcher request, STATUS, and a snapshot marker: **no code or test file changed**. Compare to the current review trigger commit likewise finds only STATUS and its new snapshot marker.

## Assessment — independent static oracle derivation

1. The mesh in `tests/FieldAlignedCurveNetworkTests.cpp:88–104` has centre `(0,0)` and radial faces `top=(2,3,4)` and `right=(1,2,4)`. The cross-case top primary direction `(3,1)` crosses the common radial edge `(2,4)` toward the right sector (right/down from the top); the right primary `(2,1)` lies strictly inside the right wedge, with nonzero outward advance from the centre. This geometric result does not depend on the follow result or face-local branch numbering.
2. At `tests/FieldAlignedCurveNetworkTests.cpp:12354–12405`, the oracle reads A1 signed transport from `top` to `right`, validates reverse transport, obtains the owner direction, enumerates the right-face A1 branches and independently counts the **one** strictly outward destination field pairing. For this face the exact barycentric derivative must be negative at the centre and positive at each of the other two corners. The test compares both `rotated(sourceBranch, signedLift)` and `follow.continuation.nextBranch` with that independently selected pairing. It does not use the follow result to select the expected destination branch.
3. Non-vacuity at `:12406–12443`: `accepts` is true for the observed continuation and independent outward pairing. A one-quarter-turn wrong candidate cannot equal the unique outward branch; a lift increment cannot equal the transported branch; negating the ray changes its outward signs; setting a noncentre barycentric component to zero violates strict sector admission. Each `EXPECT_FALSE` therefore rejects its intended tamper for the **local assertion helper**. The negatives do **not** mutate the production follow operation or prove end-to-end tracing; they must not be counted as separately executed tests.
4. The unchanged producer in `src/geometry/SurfaceCellTracing.cpp` returns a `Cross` continuation from the target sector's own `(face,branch)` when `targetStep==0`. The source-field/wedge check is independent of that return value, so a mistaken destination branch would fail the two positive comparisons. This is a meaningful static oracle, not mere deletion of the old equality.
5. **Evidence limit:** this Review did not execute a Directional binary (required Review boundary). The original TB123 local raw log and postflight archive could not be re-opened from repository or available Library. Thus no independent count, checksum, elapsed-time or exit-code claim is made for those original processes. A full 949-row immutable run and direct census are still necessary. The TB122 948/949 mismatch remains its historical recorded outcome and is not rewritten as green.

## Prior obligations and disposition

- **C1 (cross-face branch oracle):** corrected test construction reviewed as meaningful; no remaining face-number equality error in row 949. Scoped oracle is ready for an immutable full-gate test. The historical TB122 RED is retained.
- **C2 / D12=A:** two stages remain distinct: geodesic owner election and post-election field follow, without owner re-election. The field-follow physical direction is supported by this constructed Cross witness, not by complete product traces.
- **C3 / F2:** BunnyRandom mandatory edge `(241,251)` multi-terminal exact equivalence/order remains unresolved. No A2a-prime cut-graph mutation authorized in this Review.
- **C4:** `Unresolved` follow propagation before invalid segment publication is not exercised by row 949; retain the separate later falsifier.
- **O42/O43/O44:** open. **O41/Vase** and D10/D6 remain separate. D11=A and D12=A persist. No new stable event or promotion: stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**; accepted CP2 **491/491**. Selector 497 and CP3 remain unaccepted; `chainRimSchedules=false`.

## Recommendation — one conditional successor only

Authorize **`M6-CP3-TB124-P13-CORRECTED-FULL-GATE-AND-CENSUS`** as a *separate* immutable Test + Benchmark turn. Use CB142 artifact `14224898790`, verify its exact source, full package hashes and binary identity before and after. Execute the existing **949** named gate tests and the three-case census; independently capture raw logs, exact selected/skipped counts, all **947** inherited rows, row 948 and row 949, receipts and manifest identity. Stop on any nonzero test failure, source/binary mismatch, absent negative assertion, missing raw evidence or new unexpected production result. Do not recompile, repair tests, change selectors or assert product acceptance. `M6-CP3-TB124-REV-P13-FULL-GATE-OUTCOME` must independently classify any RED and the outstanding O44/trace-level and BunnyRandom terminal evidence. Do not start TB124 in this Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change or acceptance; accepted CP2 491/491 and frozen CP3/497 carried, byte-frozen files unmodified. |
| Decisive claims independently re-derived | Right-face sector geometry and strict barycentric sign test, A1 transport comparison, four negative-helper falsifiers, and no code/test changes from CB142 via GitHub compare. Original TB123 raw logs unavailable; their results not independently re-counted. |
| Non-vacuity checked | A wrong Cross branch, lift, inward ray or radial ray fails `accepts`; production branch mismatch fails independent positive comparisons. This covers the assertion helper, not an end-to-end producer mutation. |
| Prior obligations discharged/carried | C1 static oracle accepted; C2/D12=A preserved; C3, C4, O41/O42/O43/O44, D10/D6 carried to existing owners. |
| Stable accounting | 66/17/49; debt 1, deferred 81; CP2 491/491; CP3/selector497 frozen; no package promotion. |
| New candidates/obligations recorded | No new stable candidate. Tracker carries raw-log evidence limit and the next full-gate falsifiers. |
| ORIENTATION currency line | Updated to TB123-REV, 2026-11-16. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 current priority corrected. §4 unchanged: no new representative-census result. §8 unchanged: existing independent-oracle pattern, no new defect type. |
| CHANGELOG | TB123-REV review entry added. |
| ROADMAP | n/a: M6 CP3 still active; no milestone/checkpoint acceptance changed. |
| Selector manifest | n/a: no selector mutation or acceptance. |
| LESSONS | Existing independent-oracle and fixed-variable lessons 170/171 apply; no new pattern. |
| Consolidation under CLEAN_UP_POLICY | n/a: review report and current focused result are still live evidence. |
| Successor frozen | Exactly TB124 immutable full-gate+census, with hash, selector, count and stop rules above. |
| Turn boundary held | Review-only source inspection and document edits; no product/test/fixture/selector/build mutation or Directional executable run. |
| review_check.py boundary | Local synthetic snapshot check: many selector checks passed; durable rewrite ancestry check failed because extracted snapshot has synthetic `.git`, not original repository ancestry. No false complete pass claimed. |
| `STATUS` lifecycle maintained | Entry beacon opened current Review. Final completion beacon must be last remote repository mutation. |
| Pushed to origin, branch in sync | Pending exact Drive apply and independent remote confirmation; must update before formal complete claim. |
