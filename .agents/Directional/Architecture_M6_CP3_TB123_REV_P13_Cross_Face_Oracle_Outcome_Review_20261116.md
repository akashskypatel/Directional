# TB123-REV — independent cross-face oracle outcome (2026-11-16 UTC)

## Situation

Review turn `M6-CP3-TB123-REV-P13-CROSS-FACE-ORACLE-OUTCOME`. **Decision: accept the corrected oracle's static contract for the next independent full gate, not a full-gate or production outcome.** The focused TB123 report records two selected tests passing; the raw local execution archive is not available in the current repository snapshot or accessible Library. Consequently, the reported 2/2 process outcome is *reported evidence*, not an independently re-counted raw-log result of this Review. This is an explicit limitation, not an inferred pass.

## Background and source identity

- Immutable CB142 package: compiled semantic source `57b28b737fd92b083d24d882152dea186211f735`, artifact `14224898790`, reported outer SHA-256 `98f448f9e5b5ebcacbd1884ad4e62415d7c10d5878da0ccf1438654b4aeaf52b`; CB142 reported 28/28 internal hashes and eight GMP/GMPXX targets.
- TB123 [focused report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb123_p13_cross_face_oracle_focused_execution_report_20261116md) records row 948 and corrected row 949 each executed once, passed, zero skips, no timeout, no rebuild and unchanged package hashes. Its four negative cases are internal assertions of row 949, not four additional test executions. Neither a new GitHub Actions gate nor independent raw local logs is provided by that report.
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
| Pushed to origin, branch in sync | GitHub drive_apply run 43974781511 succeeded; result artifact 14280916016 verified and exact six-path commit comparison confirmed. Staged Drive file retired. No local tracking branch exists in this ChatGPT Web snapshot, so `git status -sb` could not confirm local ahead/behind state; remote change confirmed through GitHub. |

**Process audit:** Before selecting mandatory `READ_MODE=snapshot`, four repository source/document files were read directly through the connector. This was a tool-use-policy violation; it was disclosed during this session. The rest of the review used verified snapshot material. Tool-call ledger was not reliably maintained from the first invocation; exact call totals and family counts are unknown, not estimated. The snapshot's synthetic Git history did not support the rewrite-ancestry check.

## Owner-requested adversarial re-review (RA-242, 2026-11-16 UTC)

Same canonical turn, reopened at 23:08:50Z. The source was read at HEAD `6dea7ec10`. `git diff --quiet` shows no change in `src include tests` from CB142 `57b28b737` to HEAD, and no change in `src include` from CB141 `2dedeb097` to CB142. CB142 changed the test file only, so the product code is identical across CB141, CB142 and HEAD. No binary was run.

### What the first pass got right
- **The oracle is correct.** The fan is `make_four_triangle_fan`, with centre vertex 4 at (0,0); top is (2,3,4) and right is (1,2,4).
  - The top primary (3,1), at about 18°, lies outside top's 45°–135° wedge. It crosses the radial (2,4), so it does not leave the vertex.
  - The right primary (2,1), at about 27°, lies strictly inside the right wedge (−45° to 45°).
  - The test therefore fails if the producer returns the untransported label: TB122 observed elected 2 and continuation 3, which means lift +1.
- **The negative controls only test the test's own `accepts` lambda.** They are not product evidence, and the first pass says so.

### Corrections to the first pass
1. **The census evidence was ignored.** The TB122 BunnyRandom receipts (`evidence/Architecture_M6_CP3_TB122_Verbatim_Required_Receipts_20261116.txt`) confirm RA-241's predictions S1–S3 exactly:
   - vertex 48: `outcome=Slide elected=(48,271,272) continuation=(48,271,272) branch=3 carrier=(48,271)`;
   - vertex 349: `outcome=Cross elected=(5,102,349) continuation=(5,306,349) branch=2`;
   - vertex 137: no follow line and no `edgeTransitSeedConformance` line, so the carrier seed alone resolved it.

   The network stage then completed. The first terminal moved past the network stage to the cut graph. "Supported only by the constructed witness" understates this. The Cross and Slide continuations were consumed without a network-stage error. Their segment geometry is still unverified, because the cut graph rejects first and no segments are output.
2. **O44 closes now.** It was the AX1 carrier-seed nonconformance. The evidence:
   - row 948, the carrier-seed test, passed on CI in TB122;
   - the 947 inherited rows are unchanged;
   - Cylinder and Vase are unchanged;
   - vertex 137 is resolved, with no conformance line.

   Row 949 tests the D12 follow, not O44, so keeping O44 open conflated two contracts.
3. **The TB124 census is redundant.** The product source is byte-identical to CB141's, so the TB122 census is CB142's census. Only the CI gate is new evidence: TB123's 2/2 local run has no committed raw log. TB124 is narrowed to the gate only.
4. **C4 is a coverage gap, not a regression risk.** `Unresolved` returns `keep(transit)`, so both call sites (`SurfaceCellTracing.cpp:3647`, `:3816`) behave exactly as before CB141. Before CB141 that path failed closed, as at TB120's vertex 137.

   It still violates the DESIGN supplement, which says `Unresolved` "is a typed non-success". The consumer ignores `follow.kind`, and fail-closed comes only from a later check. The fix is a small, receipt-neutral change: no gate or census run has printed an `Unresolved` line. It is parked as its own CB.
5. **The DESIGN supplement and the producer disagree on grazing.**
   - `crossing()` returns 0 ("leaves") when one radial coordinate is exactly zero, so the producer accepts a field running exactly along a radial edge.
   - Row 949's oracle requires strict outflow.
   - Neither DESIGN nor a test says which is right for a grazing target sector. With exact arithmetic this needs exactly-aligned input, but such input is reachable on regular meshes.

   Parked with the C4 item: one test-only boundary turn.
6. **The DESIGN demand to "preserve the original owner" is met at helper level only.** `follow_field_vertex_transit_outflow` takes the election and returns the continuation, and row 949 checks both. The trace retains only the continuation, plus the diagnostic line. No product field is needed unless a consumer reads the owner. None does, so no change is made.
7. **My own error, in RA-241.** I froze row 949 with `EXPECT_EQ(elected.nextBranch, follow.continuation.nextBranch)` for the Cross case, comparing branch labels across two face frames. That caused TB122's only RED. CB142's transported-label oracle is the correct fix.

### Trajectory
CP3 progress is sound: each P13-e step moved BunnyRandom's first terminal one stage later. The next blocker is a construction limit, not a numerical defect: `build_arcs` (`EmbeddedGraphTopology.cpp:483–491`) rejects any mandatory edge with two or more terminal cuts. It also reports only the first such edge in map order, so the census hides how many exist.

The exactly-one split (`:494–558`) generalizes directly to strictly ordered distinct exact parameters. Equal parameters are the only case that needs a decision. Inventory comes before the cure: RA-210 says to census every contact a first-failure validator hides, and RA-225 says to check that a defect can occur before designing its cure. The inventory must cover every edge in all three fixtures, not only the first.

### Realigned sequence (each turn is one bounded change or one evidence gate)
| # | Turn | Owner | Goal / stop |
|---|---|---|---|
| 1 NEXT | `M6-CP3-TB124-P13-CORRECTED-FULL-GATE-EXEC` | Test + Benchmark (artifact only, GitHub Actions) | CB142 package `14224898790`, manifest `a56ad00c…` (949 rows, membership 1,030). No census. See the MATCH criteria below. |
| 2 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-INVENTORY` | Review | Accept TB124 (closes C1 and the scoped D12 follow), then freeze the exact CB143 `.diff`. |
| 3 | `M6-CP3-CB143-P13-EDGE-TERMINAL-EXACT-INVENTORY` | Code + Build (compile only) | Diagnostic only: one line per edge with ≥2 terminal cuts (trace, node, exact parameter, equal-parameter class) for every such edge. The rejection is unchanged. |
| 4 | `M6-CP3-TB125-P13-EDGE-TERMINAL-EXACT-INVENTORY-EXEC` | Test + Benchmark | Full gate plus three-case census on the CB143 package. Gate receipts must be unchanged. |
| 5 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-EQUIVALENCE-DECISION` | Review | Classify every cut. Freeze CB144: N+1 sub-arcs for distinct ordered cuts, and a decided rule for equal parameters (a user decision if it is a contract choice). |
| 6 | `M6-CP3-CB144-P13-EDGE-TERMINAL-OWNER-CORRECTION` | Code + Build | One class only, with a positive and a negative fixture. |
| 7 | `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-EXEC` | Test + Benchmark | Full gate plus census. |
| 8 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` | Review | Read the next BunnyRandom terminal. |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | Code + Build, then TB and Review | Typed fail-closed on `Unresolved` at both call sites (C4); one exact-grazing target test (finding 5). Receipt-neutral. Scheduled after step 8, or earlier if a gate shows an `Unresolved` line. |

**TB124 MATCH** requires all of the following:
- 949/949 PASS and 0 skipped;
- package hashes 28/28 before and after;
- rows 1–948 receipt lines identical to TB122;
- row 949 PASS, with its four `EXPECT_FALSE` controls present in the source at `57b28b737`;
- no `vertexOutflowFollow` or `Unresolved` line in the gate.

**Routes:**
- TB124 mismatch → `M6-CP3-TB124-P13-CORRECTED-FULL-GATE-REV` (Review).
- TB124 infrastructure failure → `M6-CP3-TB124A-P13-CORRECTED-FULL-GATE-ORCH`.

**Carried, unchanged:** O42 and O43 open; O44 **closed** by this re-review; C3 open (the cut graph). D11 = A, D12 = A, D10 deferred, D6 pending. Stable 66/17/49, debt 1, deferred 81; CP2 491/491; CP3 and selector497 unpromoted; `chainRimSchedules=false`. DESIGN.md unchanged.
