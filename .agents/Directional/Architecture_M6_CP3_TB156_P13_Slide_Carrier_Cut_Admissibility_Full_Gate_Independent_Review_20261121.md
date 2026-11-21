# TB156 independent review — slide-carrier cut admissibility

**Canonical turn:** `M6-CP3-TB-REV-156-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY-FULL-GATE` · 2026-11-21 UTC. **Verdict: qualified PASS of TB156; no CP3 or D0 promotion.** The review uses the packaged source and immutable original gate/census outputs, not a reconstructed run. No runtime, build, source, test, fixture, selector, or benchmark execution/change occurred.

## Situation

TB155 failed its formerly accepted row858 and emitted the prohibited shared-edge guard. CB-172B removed cut candidates from the ten source edges that support exact trace slides. TB156 runs on the immutable CB-172B package with the exact prior selector plus one independent slide-carrier classification check.

## Background — immutable source and integrity

- Compile package: source `23c43e6fa01a132b23553302a083d41b01130710`, run `44919774599`, artifact `14713691307` (not rebuilt by this review).
- TB156 gate artifact `14715014772` ZIP SHA-256 `0bfac9c0eaf626408d666a5bd298b681236e7f54c69bfd25340b6064aa8d1e9b`; 1,952/1,952 indexed internal checksums match.
- TB155 gate artifact `14704220616` ZIP SHA-256 `e4e08a887f2d9b1ccddb174cba19e78d71df1934e603a51e7e57431a06f46358`; 1,950/1,950 indexed checksums match.
- TB154 gate artifact `14696380156` ZIP SHA-256 `ce172d892dbf3f52084eaf3a148ec03443bc19c06ec9e5262f89e35c89b648c0`; 1,950/1,950 indexed checksums match.
- TB156 census artifact `14716036015` ZIP SHA-256 `847b88f3e95881ed2044c6ed9cd49bce9eba1e89a567a95bb202d3fbe8bd1680` and TB151 census `14621727104` ZIP SHA-256 `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611`; both 9/9 indexed checksums match.
- TB156 frozen manifest SHA-256 `cbba9e76fa436f1e2e6ef34d50bb377b931c19fc4780660412a9f6072128dc6a`, 972 test records. Its exact first 971 rows match the 145,526-byte TB154 manifest, SHA-256 `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305`. TB155/TB156 first 971 ledger identities, binaries, and test names match.

## Assessment — independently derived findings

1. **Full-gate counts:** TB154 971/971 PASS; TB155 970/971 PASS, row858 RED; TB156 972/972 PASS, with no missing, duplicate, or skipped cases. The accepted CP2 prefix is 491/491 PASS. This does not promote the additional frozen 497 identities.
2. **Normalized gate differences:** TB156's 960/960 non-A records match TB154 exactly under frozen N1–N3. A set is 644, 645, 648, 669, 686, 698, 858, 963, 966, 968, 971. Only row966 differs from TB154, by one additional `SourcePieceCountOracle traceArcs=3 segments=9 transitSegments=0` line. Row686 stays the real-piece oracle and stays at V18/E30/F18 (Euler χ=6) against source χ=2. Other A rows normalize to TB154. No unauthorized normalization was applied.
3. **Census:** TB156 matches TB151 in all three representative cases under frozen N1, N2, N4. Cylinder PASS; BunnyRandom RED and Vase RED at their existing sites. Pointer-object display is masked only by N4; platform digests remain equal and unmasked. This is a **3/3 baseline match**, not 3/3 production successes.
4. **Regression guard:** No gate or census log contains `RotationTraceRaysAlongSharedEdge`, `RayRunsAlongLocusEdge`, or `FirstPieceNotLeavingLocusIntoFace`. Row858 now passes its original accepted source-face assertion; no assertion was removed.
5. **New row972 is non-vacuous within its scope.** It independently gathers non-mandatory slide-carrier source edges from real trace segments, requires a nonempty set, matches every `TraceSlideCarrier` certificate to that set, and rejects any selected slide carrier. Actual receipt: `carriers=10 classified=10 selected=0 outcome=CutSearchExhaustedBeforeCellularity`. Deleting classification or allowing a carrier in the cut plan would fail this check. **Limitation:** it does not prove an alternative cut exists, that the later stop switch works, or that the sphere is cellular.
6. **Actual producer boundary:** The sphere still exhausts cut search at rows644/669/698, and row686 χ+4 remains. The four slide-interior contacts remain without shared graph events. No false production success is claimed.
7. **RA-280 STOP criteria:** All TB156 gate/census/non-A/forbidden-guard preconditions pass; no observed regression requires re-opening CB-172B. The next step may be authorized in a separate turn. RA-281 Amendment 14 R2 stays an **interim** restriction, not the completed total-cut-set guarantee.

## Prior obligations and disposition

| Obligation | Disposition and evidence / next owner |
|---|---|
| RA-279-C1 saturated cut along a slid carrier | **Discharged only for this regression:** row972 shows all ten held out; no shared-edge guard. Does not repair the final graph. |
| RA-279-C2 row858 early stop loses a source face | **Discharged only for the accepted regression:** unchanged row858 assertion PASS in TB156. |
| RA-280 D1/D2, R2 and D3 | Root cause upheld; CB-172B validated. Withdrawn CB-172A remains withdrawn. R2 remains interim. |
| RA-281 F1, F2 | **Carried:** Amendment 14 restriction must be removed only after source-attached slide-start cut subdivision is valid; owner later separate CB after stop-switch gate. |
| RA-281 F3 | **Carried to `M6-CP3-CB-173-P13-STOP-SWITCH-RAY-HELPERS`:** along-locus-edge ray key and rank required before wiring a stop switch. |
| RA-275 S4a and O47/C5/O48/O49, H4 | **Carried:** later piece-aware plan, contact ownership, χ+4; do not substitute face-chord cut parameters for slide parameters. |
| RA-277-NV1, row971 ten-ray controls | Row972 independently covers membership and selected exclusion; further ordinary-ray/collision negative controls stay with the helper/stop-switch gate, not assumed complete. |
| Stable regression ledger / produced witness debt | Unchanged **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. CP2 491/491 accepted; CP3/selector497/D0/H4 unpromoted. |

## Recommendation — one frozen successor

Authorize only `M6-CP3-CB-173-P13-STOP-SWITCH-RAY-HELPERS` as a **Code + Build, compile-only** turn. It may implement and compile a reusable, **unwired** edge-locus ray key/helper with exact orientation, no-ray distinction, and independent positive/negative proof controls. The helper must preserve CB-171 strict equal-edge coincidence rejection and real edgeRayCount ranking. Full stop-switch wiring, slide-start subdivision, cut repair, or production acceptance is forbidden in that turn. The bounded design, independent falsifiers and stop rules are in [Architecture_M6_CP3_CB173_P13_Stop_Switch_Ray_Helpers_Code_Build_Plan_20261121.md](Architecture_M6_CP3_CB173_P13_Stop_Switch_Ray_Helpers_Code_Build_Plan_20261121.md).

**Process note:** At this review's start, five direct source/document reads preceded the explicit snapshot-mode choice, contrary to the mandatory conservation pre-read gate. This was reported, direct piecemeal inspection stopped, and the source review continued from the verified exact snapshot `1dc0ca9834ef202606e5d24da2afa352a4be6da2`, 5,677/5,677 source hashes. This process error did not change product or test bytes; it is not represented as a successful policy read-mode sequence.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB156 manifest `cbba9e76fa436f1e2e6ef34d50bb377b931c19fc4780660412a9f6072128dc6a`; 971-row prefix = TB154 SHA-256 `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305`. |
| Decisive claims independently re-derived | Five ZIP digests and indexed content hashes; 972 gate outcomes; 960/960 non-A match; one A-row difference; 3/3 normalized census; row686 χ=18−30+18=6. |
| Non-vacuity checked | Row972 counts actual ten carriers and compares exact membership and rejection; it does not prove sphere success. |
| Prior obligations discharged/carried | RA-279-C1/C2 narrowly discharged; RA-280 D1/D2/R2 upheld; RA-281 F1/F2/F3, RA-275 S4a, O47/C5/O48/O49/H4, debt and controls carried. |
| Stable accounting | 66/17/49; debt1; deferred81; accepted CP2 491/491, package `11391685901`; CP3/497/D0 held. |
| New candidates/obligations recorded | No new stable candidate; RA-281-F3 assigned successor; tracker updated. |
| ORIENTATION currency line | `M6-CP3-TB-REV-156-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY-FULL-GATE` 2026-11-21 updated. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 current gate and limited promotion, §4 row858/972 witness, §7 obsolete CB-172A warning replaced; §8 no novel mechanism, existing pattern retained. |
| CHANGELOG | One TB-REV-156 entry. |
| ROADMAP | M6/CP3 corrected to TB156 qualified green without milestone promotion. |
| Selector manifest | n/a: no selector added or accepted; 972-case manifest remains unpromoted. |
| LESSONS | Existing single-writer / accepted-prefix / non-vacuous oracle principles apply; n/a new number, no novel pattern. |
| Consolidation under CLEAN_UP_POLICY | n/a: no historical record superseded for deletion; TB156, RA-280/281 remain live evidence. |
| Successor frozen | `M6-CP3-CB-173-P13-STOP-SWITCH-RAY-HELPERS` in [Architecture_M6_CP3_CB173_P13_Stop_Switch_Ray_Helpers_Code_Build_Plan_20261121.md](Architecture_M6_CP3_CB173_P13_Stop_Switch_Ray_Helpers_Code_Build_Plan_20261121.md) with falsifiers and stop rules. |
| Turn boundary held | Review-only, no runtime or product/test/fixture/selector/benchmark/build-source mutation. |
| review_check.py boundary | Local snapshot check: product/test/selector boundary PASS; historical rewrite ancestry and three baseline-source checks cannot pass because the exact snapshot excludes Git history and rewrite base `8b7299b43`. This is an unverified document-history check, not a clean full PASS. |
| `STATUS` lifecycle maintained | Entry beacon set for `M6-CP3-TB-REV-156-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY-FULL-GATE` with preserved start; final direct write after document/cleanup workflow and final state decision. |
| Pushed to origin, branch in sync | Pending verified GitHub patch transport; if not confirmed, this review remains IN_PROGRESS and its exact patch is preserved. |
