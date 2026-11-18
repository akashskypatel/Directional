# TB135 independent Review — edge-transit entry (2026-11-18 UTC)

## Situation

`M6-CP3-TB135-P13-EDGE-TRANSIT-ENTRY-FULL-GATE-REV`: **MATCH upheld, 956/956** under [RA-256 S5](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md#ra-256--adversarial-re-review-of-this-review-2026-11-18-utc). This verifies the measurement, not a behavioural repair, geometry acceptance or promotion.

## Background — immutable authority

- [TB135 execution](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Execution_Report_20261118.md); [CB158 compile record](Architecture_M6_CP3_CB158_P13_Edge_Transit_Entry_Record_Code_Build_Record_20261118.md). Candidate source `5bdc7c092a8935faeab75cf7a739928fd8ddca46`, package `14397197316` (package digest inherited from compile and execution records; package not downloaded/executed in Review). Comparator CB157 `a8d1cc9603f9a556564f0b741692217ec6a791ef`, package `14389450751`.
- Snapshot source `b8c1afe92aa128213e2ac0ba7ed88b55829b39b8`, run 44244721106, job 134600899367, artifact 14401535644, ZIP SHA-256 `abcb6635da7d2d645a1ff7b3a1ddc5f8d774c012807a2fead904d31c5496ccd0`, source archive `99498d95622c6806da4e3bc4a883d8ec374177260f18972ee92257dca531150a`, 5547/5547 internal checks. Remote comparisons show CB157 to CB158 only +11/-0 product delta on the three frozen paths, CB158 to snapshot no code/test/fixture/build/gate/selector/tools/workflow drift. Frozen CB158 diff SHA-256 `17dd9ac558f9d2e24bd4d5010262b9d3092c9414c8d9d9bfbbbfa3b4ef12822f`; three postimage blobs `bdf947602a2d559491e6d3451f7aed832a13d65e`, `2ccad3f4a961e951cf32237f67c24cf46d84175a`, `e5b15ec57302d413f4dfb3aca6abeb33bbe104ff` match the compile record. Both writers store `decision.exitPoint` (SurfaceCellTracing.cpp:2784,3764); receipt prints the optional field (EmbeddedGraphTopology.cpp:1053–1055). No behavioural reader added in CB158.
- Candidate mailbox gate run 44239014989 (failure, permitted row858) and census run 44239053464 (success), both exact source and result digests match. Archive digests independently re-hashed:

| Archive | Artifact ID | SHA-256 |
|---|---:|---|
| TB134 gate | 14390702505 | `532ae16d7872c5699a85c0bc11d819856660fb22b1fcaae99f454db714bf0640` |
| TB134 census | 14391390784 | `dcf867473ebc5bd0310ff5249644d4c4cd4a8cf6214cdca9942f2b0ec52fe149` |
| TB135 gate | 14398029488 | `4cc06b817c8ecfb20b7316b7017337fd2cfc9ab81c15f0360f2d2ef8f7ccc394` |
| TB135 census | 14398329619 | `8840f1d0bf9b303a7364a1346d2f5be88f31f23eab8e73d8ae391e6308ad5453` |

## Assessment — independent verification

All four archives pass 3,846 internal checksum checks. All 1,912 raw-log SHA-256 bindings match independently. Every row has exactly one matching RUN line, the expected manifest row/kind/identity/test/binary, an actual ledger verdict and no skip. Exact raw-file inventory matches each ledger. Gate membership 1,034 identities (953 gated, 81 deferred) is byte-identical. All four boundary records have immutable postflight=true, compile/relink/configure/benchmark=false. Both gates exit90/control_bad1 for row858 (`SurfaceCellTracingDisplayTests.cpp:155`), 952 PASS, one RED. Both census exits 0: Cylinder PASS/288, BunnyRandom/Vase RED at `SurfaceCellDesignAcceptanceTests.cpp:493`. Row648 sphere assertions remain unreached. No changed RED site or stable regression.

| RA-256 S5 criterion | Independent result |
|---|---|
| 1. Ledger identity | 956/956 substantive fields identical; raw hashes verified against each archive separately rather than expecting changed diagnostic bytes to have equal hashes. |
| 2. Normalized logs | 956/956 exact retained comparison under N1–N4/N6. Gate M3 diagnostic multiset 1,738 complete records with prefix count equal to parsed count (three joined pairs in candidate, paired extra newline framing); remaining lines in order. Census M3 lines compared in order; mask only GoogleTest elapsed suffixes, census parameter object bytes, and ` slide=` tokens. No retained path byte change. |
| 3. Slide/transit adjacency | Each slide immediately precedes its transit within the same parsed segment; equal counts per receipt line. |
| 4. Sphere scope | 66 receipts on 19 rows (380,388,393,394,396,397,644,645,648,669,686,691,694,698,699,700,843,844,858); zero slide tokens. |
| 5. BunnyRandom scope | Both row2 census receipts agree: exactly 43:11, 43:13, 15:19; each slide and transit carrier equals its segment `to=` carrier. The starts on (94,210) lie strictly within (0,1). |
| 6. Frozen ratio | Independently computed below; relative error 1.30866869981189e-15, less than 1e-12. |

| Trace : segment | Carrier | Start parameter | Transit |
|---|---|---:|---|
| 43:11 | (60,290) | 0.079930581417586133 | 1=v290 |
| 43:13 | (94,210) | 0.26324148596788688 | 0=v94 |
| 15:19 | (94,210) | 0.93470265131543506 | 0=v94 |

With the stored edge parameter measured from the first vertex, both traces go toward zero on (94,210). Thus t43 < t15 and the shared closed interval is [0,t43], from v94 to X43. Decimal arithmetic at 80-digit precision gives `(1-t15)/(1-t43) = 0.08862788476947118401546127165782492786761290030018710149457744249`; relative deviation from `0.0886278847694713` is `1.3086686998118918e-15`. This confirms RA-256 S1's predicted onset against the measured starts. The ratio also agrees with the prior independent entry parameter on (210,290), `0.088627884769471255`. Arrival seniority (43 first) is carried from the independent bounded arc-length proof in TB134/RA-256, not re-derived from decimal parameters or trace IDs. Expected later-trace stop is X43. The displayed decimals are not an exact cut identity: use exact source-authoritative representation in the subsequent definition.

Independent offline parser negative controls (10) reject removed/duplicated/altered M3 records, changed retained text, missing slide, changed carrier, changed ratio, nonadjacent slide/transit, extra slide, and out-of-scope parameter masking. Positive controls (2) accept elapsed-time suffix and CRLF framing differences. No product/test binary ran. The original execution report's 17 negative and 5 positive controls are inherited, not counted as independent runs.

## Recommendation — freeze only the authorized successor

`M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` (Review definition; ID retained, actual scope co-directional slide overlap). Use RA-256 S3/S6, measured starts, shared edge-locus representation (parallel `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT`), exact directed interval ordering and arrival seniority with its inconclusive outcome. H3 remains unverified: classifier recomputation may differ from the traced exit on slide segments. Freeze unwired helpers CB with unit tests, then separate wiring CB. Preserve falsifiers from TB134 Review: distinct/disjoint intervals, opposite direction, different compatible occurrence/region, isolated endpoint touch, reversed/inconclusive seniority, or no prior wall. No guessed cut, coordinate merge, guard relaxation or D12 change. No successor work in TB135 Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491/491. Focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, 449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; ordered concatenation `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`; all 54 selector-directory files match the snapshot manifest. |
| Decisive claims independently re-derived | Four archive digests, 3,846 internal checks, 956 substantive ledger/log comparisons, 1,912 binding checks, 66 sphere + 2 BunnyRandom receipts, ratio and six criteria above. |
| Non-vacuity checked | Ten negative and two positive offline controls. Permitted RED site and unreached assertion not accepted as PASS. |
| Prior obligations discharged/carried | RA-256 S4 compile evidence retained, S5 six-criterion measurement discharged. S2 record omission resolved by CB158, classifier/consumer representation open. S3 shared definition parallel (O47), overlap successor (O48), H3 unverified. C5/O42/O43/O46/O47/O48, H2, FC-1/FC-4 and middle-piece direction witness open under existing owners. FC-6, terminal-cut and row858 held; O45 consumer proxy and C3/O44/C1 narrow closures retained. D11=A, D12=A, D10 deferred, D6 pending; CB145 parked; chainRimSchedules=false. |
| Stable accounting | 66 events/17 categories/49 recurrences, one produced-witness debt, 81 deferred. CP2 491/491 package 11391685901; 497 CP3 identities frozen, not accepted. |
| New candidates/obligations recorded | No new stable event; O48 and H3 remain open, exact source representation required. Tracker includes falsifiers and owner. |
| ORIENTATION currency line | Updated to TB135 Review and date. |
| ORIENTATION §3 / §4 / §7 / §8 | In-place update of evidence, witnesses, next definition and recurrence; no stale TB135 execution priority. |
| CHANGELOG | Added distinct TB135 Review entry. |
| ROADMAP | Updated current TB135 evidence; no checkpoint promotion. |
| Selector manifest | No selector added, changed or accepted. |
| LESSONS | Existing TB134 and RA-256 rules (lines 736–737 in snapshot) apply; no new pattern. |
| Consolidation under CLEAN_UP_POLICY | TB134 is direct comparator and RA-256 normative owner; retain it and CB158/TB135 current compile/runtime records. No active authority folded. |
| Successor frozen | Exact overlap DEFN as above; separate sphere definition remains parallel. |
| Turn boundary held | Offline read-only evidence review; documentation patch only; no runtime, build, product, test, benchmark, fixture, workflow or selector change. |
| review_check.py boundary | Snapshot has no historical Git objects. Unmodified script exit 1 solely due to unavailable rewrite history; local product/selector mutation checks, 39 numbered selector hashes and three durable file-presence checks PASS. Historical rewrite ancestor and protected headings independently checked via GitHub (`8b7299b43` ahead comparison, 4/4 handoff, 1/1 orientation, 0/0 tracker). No literal historical local PASS. Drift audit 0 errors, protected navigation warnings only; authorization is the standing Review policy plus owner request. |
| STATUS lifecycle maintained | Entry 2026-11-18T05:29:58Z, successor as above; final end time only after verified documentation push and cleanup. |
| Pushed to origin, branch in sync | Closeout requires exact remote patch application, changed-path/blob comparison, staging retirement and cleanup before final COMPLETE beacon. The local Git index is snapshot-only, not an origin checkout. |

Procedure deviations: initial source/policy reads preceded explicit snapshot-mode selection; some mandatory startup reads were not confirmed in full before snapshot dispatch. Subsequent inspection used one verified snapshot. The reminder timer used a shell instead of Python; absolute 20-minute bound retained. These are procedure limitations, not a relaxation of the product evidence rules.

## RA-257 — adversarial re-review of this Review (2026-11-18 UTC)

### S0 — verdict

MATCH 956/956 is upheld. The source delta CB157→CB158 hashes to the frozen diff `17dd9ac5…`, and the ratio check is reproduced (relative error 1.3e-15). This confirms that RA-256 S1's onset at X43 (t43 = 0.26324148596788688 on (94,210)) is right. Two defects follow.

### S1 — H3 was decidable statically and is real

Two code paths disagree:
- **What the tracer does.** When a segment departs along an edge, either as an edge-port seed (`trace.segments.empty()`) or as a `vertexSlide` after a vertex transit (`SurfaceCellTracing.cpp:3569–3580`), the face-exit decision is `resolve_field_edge_port_departure` (:2168–2189). Its exit point is the departure vertex itself. The entry is the same vertex (:4258, :3825–3836). So the traced face piece has zero length, and the whole segment is a slide (non-slide continuation is rejected at :3719–3730).
- **What the classifier checks.** `field_aligned_segment_exit_point` (:3087–3102) always recomputes `resolve_field_branch_continuation` from the vertex entry. That call never returns the entry vertex. It returns either an error, which becomes Unevaluated and is skipped, or an exit on the opposite edge.

So for departure segments, the classifier tests a chord that was never traced. That can produce a phantom ProperCrossing, while the real slide is never checked. A Haiku audit agrees: the result is "No, in general".

The BunnyRandom segments are grazing slides from interior entries. For those, the recomputation equals the traced decision, so H3 does not explain O48. It is a separate latent defect on the same representation. Now that CB158 has landed, the fix is to read the stored `edgeTransitEntry` rather than recompute. That fix changes behaviour, so it needs a measuring receipt first (the RA-222/RA-224 pattern).

### S2 — the successor again had no implementation turn

The Review's recommendation names only a Review DEFN. That repeats RA-256's routing defect. The shared-carrier computation is needed under any ownership rule:
- O48: a slide against a slide or a slide start;
- O47: a crossing point against a crossing point on one edge key.

So its exact, unwired helpers can land now, while the DEFNs proceed in parallel.

### S3 — CB159 (frozen)

- **Patch.** `.agents/Directional/Architecture_M6_CP3_CB159_P13_Carrier_Occupancy_Helpers_Exact.diff`, SHA-256 `756bd652b4f188398fe2b652b078f61aa34123b7748f71f5a7bb0d303cffa266`, 192 lines. Numstat: `31 0` `SurfaceCellTracing.h`, `51 0` `SurfaceCellTracing.cpp`, `80 0` `FieldAlignedCurveNetworkTests.cpp`.
- **What it adds** (in `surface_cell_tracing_detail`):
  - `FieldAlignedCarrierOccupancy {carrier, from, to}`: exact parameters measured from `carrier.first()`, in the direction of travel.
  - `first_shared_carrier_parameter(moving, wall)`: the first parameter along `moving` that also lies in `wall`'s closed interval.
  - `field_aligned_segment_entry_occupancy`: the crossing point on the incoming carrier.
  - `field_aligned_segment_slide_occupancy`: `edgeTransitEntry`→`edgeTransitExit` on the outgoing carrier.
  - Nothing calls them yet.
- **Unit test.** `FieldAlignedCarrierOccupancy.FirstSharedParameterFollowsTheMovingTraceAlongOneCarrier`:
  - Positive cases: the BunnyRandom shape (both orders give the inner slide start, never the vertex), ascending and descending pairs, an exact point-point crossing (the sphere shape), and an endpoint touch.
  - Near misses: intervals one hundredth apart, distinct points, and another carrier.
  - Segment extraction: an exit without an entry, and an entry off the carrier, both give no occupancy.
- **Checks.**
  - Precheck: `git diff --quiet 5bdc7c092a8935faeab75cf7a739928fd8ddca46 HEAD -- src include tests`.
  - `git apply --check` passes.
  - `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` on `SurfaceCellTracing.cpp` and `FieldAlignedCurveNetworkTests.cpp` returns 0, with the same warning counts as HEAD (43 and 42).
  - A Haiku read-only audit worked every expectation by hand and found all pass. It confirmed the code sits in the non-anonymous `surface_cell_tracing_detail` block (header :733–1301; cpp :373–5640), with no name collisions, dangling references or production callers, and that the patch is purely additive.

### S4 — TB136 criteria (frozen)

- **Package.** CB159 (CB158 plus the helpers).
- **Gate manifest.** `gates/Architecture_M6_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Case_Manifest.tsv`, SHA-256 `dac17a50bccea4999a5482620793bffe42de61d585d69d53724ae0d59055ebc2`. It is the 953-row manifest `941287fa…` byte for byte, plus row 954 (`ra257:carrier-occupancy-first-shared-parameter`, the test above, `directional_surface_cell_producer_tests`, PASS). `SELF_CHECK_PASS cases=954 deferred=81`; membership 1,035.
- **Unchanged inputs.** Census `3af1dc0d…`, deferred `fd433f54…`, harness `78b8002c…`.
- **MATCH** requires all of the following:
  1. Rows 1–953 and the 3 census rows have the same ledger fields as TB135 (gate `14398029488`, census `14398329619`), and logs are equal under N1–N4.
  2. Receipts, including ` slide=` and ` path=`, are byte-identical.
  3. Row 954 is PASS.
  4. Nothing else differs.
- **Routes.** Mismatch: `M6-CP3-PLAN-P13-CARRIER-OCCUPANCY-HELPERS-STOP`. Infrastructure: `M6-CP3-CB159A-P13-CARRIER-OCCUPANCY-HELPERS-ORCH`.

### S5 — DEFN obligations (Review track)

1. **H3 measurement first.** Freeze a receipt over departure segments. It records whether the recomputed exit differs from `edgeTransitEntry` and whether any such segment produced a published ProperCrossing. Only then switch the classifier to the stored exit.
2. **Slide-piece contact.**
   - Build the moving proposal's slide occupancy and each wall's entry and slide occupancies, keyed by carrier rather than face, so walls in both incident faces are included.
   - Take `first_shared_carrier_parameter`, and decide the later trace by the existing arrival rule and its inconclusive outcome.
3. **Trace termination inside a slide.** Define the terminal record and consumer cut position on the slide piece: `TraceCutPosition` ordering is the face piece, then the slide piece by carrier parameter. Define the struck position at a slide start (X43 on 43:13).
4. **The sphere (O47)** uses the same entry-occupancy equality on edge (0,2), per RA-255 S2.
5. **Staging.** Each obligation gets an unwired helpers CB and then a wiring CB, each with its TB.

### S6 — turn sequence

- **Implementation track:**
  1. `M6-CP3-CB159-P13-CARRIER-OCCUPANCY-HELPERS` (compile only).
  2. `M6-CP3-TB136-P13-CARRIER-OCCUPANCY-HELPERS-FULL-GATE-EXEC`.
  3. Then the CBs frozen by the DEFNs.
- **Review track** (parallel):
  1. `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT`, covering S5.3–S5.4 and the H3 receipt (S5.1).
  2. `M6-CP3-TB136-P13-CARRIER-OCCUPANCY-HELPERS-FULL-GATE-REV`.
  3. `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` (S5.2).
- **Held:** FC-6, the terminal-cut outcome and row 858. **Parked:** CB145. D11=A and D12=A are unchanged.

### S7 — lessons

- When two code paths compute the same quantity (traced exit versus recomputed exit), compare their dispatch conditions before calling the difference unverified. A branch that only one of them takes is a defect, not a hypothesis.
- A Review whose only successor is another Review stalls the implementation agent. Land the computation every outcome needs as unwired helpers while the definition proceeds.
