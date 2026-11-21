# TB129 independent Review — MISMATCH upheld (2026-11-17 UTC)

**M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-REV.** Runtime-free. 953/953 required cases passed, but the literal RA-250 §R6 comparison is MISMATCH. No accepted-green loss in the ledger. Neither the candidate package nor CP3 is promoted. H1 is established on the two measured witnesses, not on every contact. The review adjudicates the comparison; it does not retroactively change it.

## Evidence and independent reconstruction

Exact candidate source `c45e9abe5085f39c1f5bcb149ec07f95b719177e`, package `14327212608`; baseline `85f9c703c5de86fb2b401cf83c03499a1ce73a27`, package `14315237769`. [Execution report](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Execution_Report_20261117.md) retains all run, package, log and preflight identities. Re-opened the original result artifacts, not the previous comparison summary. All outer digests match the published records; internal hashes and row/log bindings were recomputed from the bytes. The original compile package was not downloaded again in this runtime-free review; the execution-boundary records bind the package/source and the compile record supplies its preflight.

| Artifact | ID | SHA-256 | Internal checks / raw rows |
|---|---:|---|---:|
| TB128-gate | 14318100443 | `e208416775f474f75d79ec76697ed19d643a121d8ad086cd37b8f3a330436e5d` | 1914 / 953 |
| TB128-census | 14317054197 | `cdf7dab92f0e8c2650db6e2e5ac015d7ab5f07e251b4acdd17e6ed511ee7ccf4` | 9 / 3 |
| TB129-gate | 14329895372 | `c67b07a15772f73afc87339526fd3849f8b870f9d9d3ee0330e0af5840ccb30c` | 1914 / 953 |
| TB129-census | 14328938547 | `9da50feb13375580b7e920ae6e1603b16837ee825202f0631f91efd7cce3a42b` | 9 / 3 |

Total **3,846/3,846 internal checksums, 1,912/1,912 row-to-raw-log bindings**; every ledger identity joins to the frozen manifest, and both complete membership files match byte for byte (953 gated, 81 deferred, 1,034 total). All four postflights valid. No compile/configure/relink/benchmark flags. TB129 gate 953/953, no missing, bad, abnormal, skipped or duplicate case; census one PASS and two registered RED. The 491 accepted prefix equals the concatenation of the 30, 12 and 449 blocks; the entire 950/951 inherited manifests are exact byte prefixes of the 953-row manifest. Hashes below.

- `Architecture_M6_TB128_P13_Face_Contact_Node_Full_Gate_Case_Manifest.tsv`: `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`.
- `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`: `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv`: `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- `Architecture_M6_TB125_P13_Edge_Terminal_Exact_Inventory_Full_Gate_Case_Manifest.tsv`: `9a112bd18c4f37248ae8c9fc2c942f9fd19cd67ca4a5236c13f5ed76f95a0290`.
- `Architecture_M6_TB126_P13_Edge_Terminal_Ordered_Split_Full_Gate_Case_Manifest.tsv`: `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`.
- `Architecture_M6_CP1_Required_Green_Focused_30.txt` (30): `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`.
- `Architecture_M6_CP2_Required_Green_Focused_12.txt` (12): `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`.
- `Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt` (449): `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.
- Concatenated 491 names, LF-terminated: `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`.

Independent source snapshot: `c696051657610733f071dea5c11b8ce3333352a5`, run 44091262116, snapshot job 134066742865, artifact 14330872941, ZIP SHA-256 `7526407e27a1f2b42068751790b8fe4a1f1b8cb78a08950f75917e4f6ee7c3dc`, inner tar SHA-256 `8f105d91b4e57ddb6d8e70d792c489e89ac5eba49b679d800837cbc838c38dba`, 5,524/5,524 file checks. Exact CB151-to-snapshot Git comparison: 21 commits ahead, zero behind, only docs/control/STATUS, no product/test/harness delta. Both frozen CB150/151 diff hashes match (`63a6bd0b95099f0be05b22ca5d0adb539569e5f5afa6b2d8950a6b2ab9e905ba`, `044529d63c2f9e82cad38fb95cad00d4fa299918c6bcd02ffb3c56cc1947b516`); reverse apply checks pass against snapshot source, proving the exact postimages are present. PR #8 open/draft/unmerged. No test binary executed.

## R1 — Strict comparison and non-vacuity

All 951 previously PASS ledger rows match except the raw SHA field; exactly rows 858 and 952 change RED to PASS. Row 858 now has the real face of the terminal event; row 952 reaches the retained exact near-ray assertions. These are recovered required controls, not proof of production acceptance. The exact CB150 diff alters the test witness, not the downstream assertions. CB151 is receipt/locus-only. 927/953 gate raw logs identical after elapsed-time normalization; five further differences are only newline framing (162/173/177/195/705; complete non-newline text equal), and row164 has six complete projection records on each side with equal line multisets. No value changed in those six rows. Row952 has the removed failure lines and no receipt. R6 explicitly excludes all other receipt-bearing rows outside 644/669/698. Receipt counts (complete lines):

| Count per row | Rows | Total |
|---:|---|---:|
| 4 | 644, 669, 698 | 12 |
| 4 | 380, 388, 393, 394, 396, 397, 686, 691, 694, 699, 700 | 44 |
| 2 | 645, 648, 843, 844, 858 | 10 |

**54 extra receipt lines on 16 forbidden rows**, so MISMATCH even if multiplicity were as predicted on the three named rows. Row644 changes `errorSourceFace=none` to `18-19-24`; rows669/698 publish the same trace 7/event29/edge18-24 and FaceRestricted candidate (7,7,Incoming) in their existing locus fields. The rejection remains `ArcTraceTerminalCutPositionMismatch`. BunnyRandom's non-receipt preterminal and postterminal text matches after permitted elapsed-time and parameter-object normalizations. Two added receipts (not one) and the exact locus fields; reason unchanged. Cylinder and Vase normalized entire logs match. No post-hoc widening of R6. Check can fail when receipt occurs at any extra row or BunnyRandom count differs from one; both fail in real data. Hash checks alone would not find these errors.

## R2 — Evidence of the actual owner, not a guess from a reason name

All 68 receipts meet the H1 predicate by parsing the exact printed fields. There are two distinct observed signatures, not 68 independent product defects:

```text
EmbeddedGraphTopology.terminalCutBeforeEnd trace=7 sourceVertex=21 segments=8 event=29 kind=TraceIntersection node=8 face=(18,19,24) edge=(18,24) position=7 pass=FaceRestricted candidate=[position=7 segment=7 Incoming] lastFace=(18,19,24) lastIncoming=(18,24) lastOutgoing=(19,24) terminal=contact face=(18,19,24) struckTrace=3 struckSegment=6
```
Occurrences: 66.

```text
EmbeddedGraphTopology.terminalCutBeforeEnd trace=1 sourceVertex=3 segments=15 event=117 kind=TraceIntersection node=206 face=(42,335,336) edge=(42,336) position=14 pass=FaceRestricted candidate=[position=14 segment=14 Incoming] lastFace=(42,335,336) lastIncoming=(42,336) lastOutgoing=(335,336) terminal=contact face=(42,335,336) struckTrace=21 struckSegment=4
```
Occurrences: 2.


Sphere: n=8, incoming position 7. BunnyRandom: n=15, incoming position 14. Both kind TraceIntersection, unique FaceRestricted candidate, selected proxy edge equals last incoming and differs from last outgoing, terminalContact face equals event/last face. No H2 (limit-cycle re-entry) or other receipt owner in these logs; absence does not disprove H2 elsewhere. The observed owner is A2a′ consumption of the producer proxy; the exact contact record is available but is excluded from this consumer branch.

Source trace (at the verified snapshot): `SurfaceCellTracing.cpp:2871–2899` computes intersection of the two segment carrier sets, chooses the first sorted common edge; `:4062–4210` commits the proposal and stores exact terminalContact face/point/struck trace/segment, then supplies the common edge to both contact events. `EmbeddedGraphTopology.cpp:631–636` excludes events with an edge from the exact face-contact collector; `:744–812` groups eligible contact nodes, resolves the terminating and struck traces from the exact record. `:147–204` maps an incoming carrier to i and outgoing to i+1. The face-restricted pass has one candidate; fallback cannot replace it. `:1189–1209` requires the terminal cut at segment extent and rejects earlier cuts. Thus FC-7's proxy cannot satisfy end-cut ownership whenever that chosen carrier is the incoming edge. It is not a tolerance, chart, rotation-order, source vertex or support problem. The stricter terminal guard is correct. The struck trace also needs its exact cut, not an artificial source-edge cut. Do not force all Terminal positions to n, remove the edge globally, widen a tolerance, invent a chart or relax validation. FC-1 strict interior and FC-4 exclusive locus proof remain open. Mutual-end and self-closure bindings need proof in any eventual switch.

## R3 — Receipt multiplicity and frozen comparator defect

`SurfaceCutGraph.cpp:1011–1021` calls `build_embedded_graph_topology` and on failure calls `annotate_failure_euler_census` with the same topology, published network and cut vector. The former calls `build_arcs` at `EmbeddedGraphTopology.cpp:2603`; the latter independently rebuilds bindings and calls the same `build_arcs` at `SurfaceCutGraph.cpp:204–214`. The same deterministic guard at `EmbeddedGraphTopology.cpp:1189–1209` prints one receipt and returns in **each invocation**. The diagnostic replay cannot create a second product failure. `RemeshPipeline.cpp:12919–12953` calls the cut graph once after network publication, returns rejected before GlobalTopologyPlan on failure. `SurfaceCellDesignAcceptanceTests.cpp:478–495` invokes this pipeline once for the direct BunnyRandom case. Therefore the two BunnyRandom lines are the construction and Euler-census replay of one rejection path, not two networks. The sphere rows may invoke more than one such path; four lines are consistent with two rejection paths, not proof of distinct network identities. Row644 also calls the independent oracle/withdrawn diagnostic before the explicit cut-graph call (`FieldAlignedCurveNetworkTests.cpp:10589–10634`); rows669 and 698 use shared fixture/reachability helpers, so their names do not delimit the path. There is no invocation/network identity in CB151's line and no proof that every receipt in those rows is a distinct network. Do not divide counts into unique networks without lineage. No need to change `build_arcs` or mute its diagnostic to make a historical comparison green.

**Criterion defect:** RA-250 froze one line per rejected network without tracing the diagnostic replay, and excluded other rows without tracing shared fixture consumers. This is a new non-stable diagnostic/comparison candidate, not a new stable behavioral regression. Retain the strict MISMATCH; for later neutral measurement compare against TB129 verbatim with only narrowly specified new measurement records removed, not the already observed receipts. This does not declare TB129 MATCH. Correct the future specification at its source; no case-name production filter or cached fake diagnostics.

## R4 — Required measurement before a semantic switch

Cylinder: PASS 288 accepted quads. BunnyRandom: RED zero accepted, source vertex 3 is origin; event face `(42,335,336)`, edge `(42,336)`, trace 1/event117. Vase: RED unchanged (189,462 segments, 26,817 cells, 67,750 internal quads, zero accepted output). These logs do not enumerate the actual contact bindings on Cylinder/Vase. No early terminal-cut rejection receipt is not a count of zero common-carrier contacts. The old `diagnose_field_aligned_contact_census` is not an authority: `SurfaceCellTracing.cpp:5099–5115` deliberately measures the predecessor tracer before the canonical queue. The retained canonical network is already assigned to `result.surfaceCellContext.productSnapshots.fieldAlignedCurveNetwork` before the cut graph (`RemeshPipeline.cpp:12919–12936`). The single-component rejected and produced paths call `clear_unrequested_intermediate_context` (`:12297–12327`), which clears later/intermediate products but not this network; multi-component aggregation can lack one snapshot. Measure the published network in the existing direct acceptance test immediately after the existing remesh call; no second remesh, no retention-option change, no product source change. Missing network on required Cylinder/Vase/Bunny is inconclusive and a stop, not zero. [Frozen next measurement plan](Architecture_M6_CP3_CB152_P13_Common_Carrier_Contact_Census_Plan_20261117.md).

The exact contact classification is the likely correct general remedy under DESIGN Amendment 13, but its coverage and guard effects on accepted fixtures are unknown until measured. FC-7's unconditional assertion is disproved and is qualified in its owning definition; no replacement semantic switch is authorized. O45 remains open, not retired. FC-6 and the MATCH-only outcome turn remain held. H2, O46, the middle-piece direction witness, FC-1/FC-4 and C5/O42/O43 stay carried; narrow C3/O44/C1 closed. CB145/C4 parked, D11=A, D12=A, D10 deferred, D6 pending, chainRimSchedules=false. No acceptance or debt debit: 66 stable events / 17 categories / 49 recurrences; debt 1, deferred 81, accepted CP2 491/491 (package 11391685901), scoped TB125 950/950, selector497 frozen unpromoted, CP3/D0 unpromoted.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Exact 30/12/449 blocks, 491-name prefix and 950/951 manifest prefixes; hashes above. |
| Decisive claims independently re-derived | Four result ZIP digests, 3,846 internal hashes, 1,912 raw-log bindings, all manifest identities/membership, ledger and raw diff, all 68 H1 signatures, exact source guard and replay route. |
| Non-vacuity checked | Real exclusions/count mismatch and prior two REDs; retained assertions; no guessed zero contacts. |
| Prior obligations discharged/carried | Row858/952 control recovery observed; H1 observed, H2 not observed. C5/O42/O43/O45/O46, FC-1/4 and direction witness carried. |
| Stable accounting | 66/17/49, debt1, deferred81, CP2 491/491 package 11391685901, TB125 scoped 950/950, selector497/CP3 unpromoted. |
| New candidates/obligations recorded | Non-stable receipt scope/multiplicity criterion; H1 confirms existing FC-7/O45 candidate; tracker updated. |
| ORIENTATION currency line | M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-REV (2026-11-17). |
| ORIENTATION §3 / §4 / §7 / §8 | Current evidence and witness states, priority and recurring pattern replaced/updated in place. |
| CHANGELOG | Review entry added. |
| ROADMAP | CP3 still active; latest evidence corrected. |
| Selector manifest | n/a — no selector published or accepted; bytes unchanged. |
| LESSONS | RA-250 guard-producer/replay extension: count invocation paths before freezing scope. |
| Consolidation under CLEAN_UP_POLICY | Superseded TB129 execution continuation preserved verbatim and indexed; current comparator, normative definition, exact diffs and package authority retained. |
| Successor frozen | M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS — test-observation only; plan defines falsifiers. No successor execution. |
| Turn boundary held | Runtime-free; documentation only. No product/test/fixture/build/selector or workflow source changes. |
| review_check.py boundary | Local script: product/test/fixture/build and selector checks PASS. The four history-dependent checks FAIL because the source snapshot has no historical Git objects. Independent GitHub comparison: rewrite base `8b7299b43764a6ba3444e5bc774a2f1b65e99731` is the merge base with snapshot `c696051657610733f071dea5c11b8ce3333352a5` (6,002 ahead, 0 behind). Direct reads of the three rewrite-base blobs establish 4/4 handoff, 1/1 orientation and 0/0 tracker protected headings retained. The history-dependent predicates are thus independently verified, not a claimed script PASS. Drift audit against the exact snapshot preimage: 0 errors, 3 authorized living-document warnings. |
| STATUS lifecycle maintained | Active M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-REV, start 2026-11-17T13:15:57Z, first entry, resume empty. On verified closeout final direct COMPLETE beacon names the frozen successor and actual UTC end; otherwise IN_PROGRESS, no end. |
| Pushed to origin, branch in sync | GitHub connector/dispatcher is the remote authority; verify successful applied commit and branch comparison before final beacon. Local snapshot is not an authenticated Git clone; no claim of local origin synchronization. |

## RA-251 — adversarial re-review of this Review (2026-11-17 UTC)

Runtime-free; `-fsyntax-only` only. **Upheld:** MISMATCH under RA-250 §R6; all 68 receipts are H1; R3's replay route (verified: `SurfaceCutGraph.cpp:1011–1016` → `annotate_failure_euler_census` → `build_arcs` at `:212`); rows 858/952 recovered. **Withdrawn:** the prose-only CB152 plan. Replaced by the exact CB153 diff below.

### S0 — my RA-250 errors

- §R6 froze "no other row contains `terminalCutBeforeEnd`" and "exactly one BunnyRandom line". I took the rows that *print* the reason (644/669/698) as the rows that *reach* the guard. 16 more rows build the same prescribed-sphere network without printing it. I also did not trace the failure replay, which runs `build_arcs` twice per rejection. The criterion was wrong; the measurement was right.

### S1 — the common carrier is the generic case, not an exception

Each segment's carriers are edges of its own face. A full crossing has two distinct ones. Two 2-subsets of a triangle's 3 edges always intersect, so `field_aligned_common_carrier` is empty only when a segment has no incoming carrier. That happens at the trace origin, after a vertex hit (`SurfaceCellTracing.cpp:3613–3667`) or after an edge transit (`:3822–3835`); the commit is at `:4523`. Consequences:
- The exact face-contact collector (CB148/CB149) covers only those contacts. Every other trace-trace contact uses the FC-7 proxy.
- If the proxy is the terminator's last incoming carrier, the trace ends at n−1 and is rejected (H1).
- If it is the last outgoing carrier, the trace passes the end guard but is still wrong. `build_node_loci` (`EmbeddedGraphTopology.cpp:1372–1403`) gives the node an **edge locus**, and the struck trace is cut at a segment boundary instead of at its exact interior parameter. That violates Amendment 13 in output that may already be accepted.
- So the switch is a conformance correction that can change accepted fixtures, not only a repair of failing ones. The Review's "Cylinder/Vase may have zero" framing is unlikely for any fixture with interior contacts. The decisive question is incoming vs outgoing, per row.

### S2 — a blanket classification would break barrier terminations

R4 calls exact contact classification "the likely general remedy". If that means dropping `!event.sourceEdge` from `is_face_contact_event`, it is wrong:
- Barrier terminations publish an edge-carrying `FirstContact` on an appended contact node (`:3925`), paired with `MandatoryBarrierTermination`. They have no trace-trace Terminal incidence, so the collector would fail them (`ends.empty()` → `FaceContactBindingInvalid`).
- `:2349` does the same at singularity port nodes.
- The correct predicate is **node-level**: a non-port node that carries a `TraceIntersection` or `TraceSelfClosure` event. Only `field_aligned_publish_contact` (`:4062–4210`) produces such nodes, and it always writes `terminalContact` for an active terminator.
- One exception, which the census must count: a Terminal incidence published for an already-inactive trace (`:4081`, `:4100`). It carries no record.

### S3 — wrong population and form for CB152

- **Wrong population.** CB152 observed only the direct acceptance test (gate rows 795/796/797/864 plus the three census cases). The switch affects every row that reaches A2a′ (RA-228).
- **Wrong form.** The plan was prose that the implementation agent would have to design, and it depended on a network snapshot that multi-component runs may not keep.
- **Replacement.** The census belongs at the switch predicate itself, inside the product, gate-wide. It also gets a dry run of the exact binding.

`build_embedded_graph_topology` is called from the SurfaceCutGraph certification loop (`SurfaceCutGraph.cpp:1011`) and from `GlobalTopologyPlan.cpp:2574`. Line counts therefore equal call counts and are not predicted.

### S4 — CB153 exact diff (diagnostic only)

`Architecture_M6_CP3_CB153_P13_Carrier_Proxy_Contact_Dry_Run_Exact.diff`: SHA-256 `c8b9bc2115c1bc40da9520f473949b50d52ad5866782e58cf09d1acdd205e350`, 171 lines, numstat `102 2 src/geometry/EmbeddedGraphTopology.cpp`, `7 2 src/geometry/EmbeddedGraphTopology.h`. Precheck `git diff --quiet c45e9abe5085f39c1f5bcb149ec07f95b719177e HEAD -- src include tests`.
- `carrier_proxy_contact_nodes`: a pure function returning the non-port nodes that carry an edge-carrying `TraceIntersection`/`TraceSelfClosure` event.
- `collect_face_contact_nodes(network, includeCarrierProxyContacts = false)`. Both production callers (`:1075`, `:1910`) use the default, so behaviour is unchanged.
- `report_carrier_proxy_contacts`, called once per `build_embedded_graph_topology` before `build_arcs`. It prints nothing when there are no proxy nodes. Otherwise it prints one atomic line (`ostringstream`): `EmbeddedGraphTopology.carrierProxyContacts nodes= terminals= exactRecords= lastIncoming= lastOutgoing= neither= unresolved= exactBinding=ok contactNodes=k | invalid face= trace=`. The dry-run binding uses the flagged collector.
- Check: `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` rc 0 with 22 warnings, the same as HEAD; SurfaceCutGraph/GlobalTopologyPlan rc 0. Gap: there is no unit witness, because hand-built networks are impossible (RA-248). The witnesses are the TB130 positive controls.

### S5 — TB130 frozen: `M6-CP3-TB130-P13-CARRIER-PROXY-CONTACT-FULL-GATE-EXEC`

Uses the same gate `941287fa…` (953 rows), census `3af1dc0d…`, deferred `fd433f54…` and harness on the CB153 package; the comparator is the four TB129 archives. **MATCH** requires all of the following:
1. Gate 953/953 PASS. Census: Cylinder PASS with 288 quads; BunnyRandom and Vase with the same RED dispositions.
2. After deleting only complete lines that begin `EmbeddedGraphTopology.carrierProxyContacts `, every raw log equals TB129 under TB129's normalizations (elapsed time, row164 complete-line multiset, newline framing). Substantive ledger fields equal.
3. Every `terminalCutBeforeEnd` line is unchanged per row.
4. Every census line is well formed, with `terminals = lastIncoming + lastOutgoing + neither + unresolved` and `nodes ≥ 1`.
5. Positive control: each of the 19 TB129 receipt rows and BunnyRandom has at least one census line with `lastIncoming ≥ 1`.

**Data, not criteria:**
- Which rows print census lines, and their values, including Cylinder and Vase.
- The `exactBinding` outcomes.
- Static predictions, where a violation goes to Review as data and is not a MISMATCH: `neither = 0` (S1); `exactRecords + unresolved = terminals`.
- A row without a line had no proxy contact node in any topology build, so the switch cannot change it at A2a′. That absence is a real zero here, because the line is computed from the exact network that the build consumes.

### S6 — Turn sequence

1. CB153 (compile only).
2. TB130.
3. Review `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH`, which freezes FC-7′ from the TB130 rows:
   - Contact nodes become face-contact nodes at `:1075`, `:1910` and in `build_node_loci` (`:1373`), using the S2 node predicate.
   - Barrier and port `FirstContact` events keep their edge locus.
   - The census print is removed.
   - The switch ships unstaged only if no accepted row prints `lastOutgoing > 0`; otherwise it ships behind an off-by-default option first (RA-230).
4. Switch CB, then TB.
5. `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, then FC-6.

Held: H2 (not observed), O46, middle-piece direction witness, FC-1/FC-4, C5/O42/O43. O45 becomes the S1/S2 carrier-proxy defect; it stays open until the switch TB. CB145 parked. D11=A, D12=A, D10 deferred, D6 pending.
