# TB132 independent Review — 2026-11-17 UTC

## Situation

`M6-CP3-TB132-P13-CUT-BINDING-CONFLICT-RECEIPT-FULL-GATE-REV`. MATCH upheld independently under RA-253 S7. O45 closes narrowly for the consumer's common-carrier proxy defect (S4); neither new rejection is repaired. No CP3, selector497 or D0 promotion. TB131 literal MISMATCH remains historical. Exactly one successor: `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` (definition only).

## Background — immutable evidence

[Execution report](Architecture_M6_CP3_TB132_P13_Cut_Binding_Conflict_Receipt_Full_Gate_Execution_Report_20261117.md), [RA-253 S2–S8](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Independent_Review_20261117.md#ra-253--adversarial-re-review-of-this-review-2026-11-17-utc), [FC-7′](Architecture_M6_CP3_DEFN_P13_Carrier_Contact_Switch_Review_20261117.md), DESIGN Amendments 13/14. CB155 source `cce5be20ea7237f59f3c0acca25a4ba57813644e`, package `14357189158`; TB131 source `452eb3d789016e744e99d88811add0f7e0949165`, package `14347130681`. Review snapshot `357ca637d7c93100391c43fb5ca894f50bd708d8`, run `44161862776`, job `134317655837`, artifact `14364460367`, outer SHA-256 `da577f3034317a4a6598f23d8c929b3ca21a5f8a9dcd71e3b3fcb648177f1a6e`, 5537 internal hashes verified. GitHub comparison from CB155 to snapshot has no product/test/fixture/build changes. Frozen CB155 exact diff SHA-256 `2a9de80f6781caab9c741d450715627ebd136d5407778a2587e05afa3e0f7761`; reverse apply check against snapshot passed. Current review executes no project binaries or builds.

| Role | Result artifact | ZIP SHA-256 |
|---|---:|---|
| TB131 gate | 14349985217 | `3747ea473be4ff441acc9b8808ba2b3bdeb280ff8d38963ee2f1d2a825165824` |
| TB131 census | 14349666706 | `784df0aa5d6fd5f2e3cb5ba22a2aa42d7e712460a8447f4e27e3f4e725920b00` |
| TB132 gate | 14359654903 | `b2a9997c5f41ba760a75003d3edc7682cbd20dbd852f7df49bd8a90de6c2611e` |
| TB132 census | 14362615302 | `a44f41eb558fd9205d9725d85d9f83b8d754beef1b24a3d886b847f6e1d639a2` |

All four archives independently re-opened. 3846/3846 internal checksums pass. 1912 raw logs hash to their respective ledger rows. Exact manifest identity, test and binary match all 956 rows on each side. Every candidate raw log contains exactly one expected GoogleTest RUN identity. Membership byte-identical (1034: 953 gate + 81 deferred). Frozen gate `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`, census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` re-hashed. Gate postflight true, 952/953, row858 RED at SurfaceCellTracingDisplayTests.cpp:155, control_bad=1, exit90; no abnormal, missing, duplicate or skipped. Census postflight true, one PASS/two RED, exit0; Cylinder 288 quads, BunnyRandom and Vase RED. No compile/relink/configure/benchmark. These are retained results, not new runtime.

## Assessment — independent S7 and attribution

A fresh offline comparator checks all substantive fields except raw-log hash (each raw hash is separately verified), GoogleTest elapsed times and newline framing, complete prefix-split M3_CP4AB_FRAGMENT_DIAG record multisets (per gate row, stronger than gate-wide), ordered non-record remainder, census-only parameter-object bytes, and the two exact receipt prefixes. 956/956 MATCH. Mutations to an actual baseline record (delete, duplicate, alter), a non-record byte and a substantive ledger field are rejected, 5/5. Candidate receipts: 66 identical duplicate-cut lines in precisely rows 380,388,393,394,396,397,644,645,648,669,686,691,694,698,699,700,843,844,858; counts even (14×4,5×2). Two identical contact-cut lines only in BunnyRandom. No new receipt in comparator. Both frozen location controls pass. See preserved independent comparison script/JSON. Row648 sphere assertions remain unreached; the 858 test premise is not corrected here. No inferred promotion from MATCH.

### Sphere: missing network incidence on an exact edge crossing

Receipt: edge (0,2), t=0.12749386848657163 (printed double), 288 selected cut edges. Traces 4 and 6 each enter segment 7 of 8 at this crossing. Their *different* terminal contacts strike trace1 segment0 in (0,2,3) and trace0 segment0 in (0,1,2). All six printed terminal coordinates positive. Shared events: none. `EmbeddedGraphTopology.cpp:365–401` detects equal exact parameter on one selected edge from different traces, before any synthetic-node allocation. This is neither approximate coincidence nor a duplicate contact terminal. `SurfaceCutGraph.cpp:998–1018` starts with an empty cut set and returns on any topology failure: a zero-cut embedded build completed before the selected-cut rejection. This does not prove cellularity or valid final geometry.

Producer attribution: `SurfaceCellTracing.cpp:3105–3139` compares only segments in the same source face. The exact classifier `:2378–2494` distinguishes ProperCrossing, EndpointTouch and CollinearOverlap. Pending/pending `:4344–4349` and pending/committed wall `:4411–4417` discard everything other than ProperCrossing with a point. Segment-end handling `:4476–4525` commits and transports independently. Thus a common edge endpoint does not enter the canonical contact queue. Publication `:4153–4210` allocates a node and carries both trace incidences when a trace-trace contact is recognized. The receipt finds no such event shared by 4/6. No certified shared node on that edge is demonstrated; the missing producer-owned incidence/contact is the supported defect, not a license for A2a′ to weld two synthetic cut nodes. Whether the intended producer rule terminates one or both traces, or permits a certified continuation, requires the following definition. Separate orphan event records or a different supported contact kind must be checked by that definition, not inferred from this print.

### BunnyRandom: two producer nodes claim one exact struck-trace position

Receipt: trace82 segment0 at t=0.2305473011248014, node220 terminating trace43 and node222 terminating trace15, both face (21,72,273), both edgeless FirstContact/TraceIntersection pairs. `EmbeddedGraphTopology.cpp:780–850` collects exact terminalContact points and exact struck-segment positions. `:690–721` obtains canonical segment endpoints; `:533–556` rejects zero-length and off-segment points and requires exact 0<t<1. `EmbeddedGraphTopology.h:233–238` compares the rational key, not printed decimal coordinates. `:1296–1323` inserts both claims into one cut map, then fails if the same exact position has different node IDs. A nondegenerate straight segment is injective in its exact parameter: both claimed points are exactly equal in this face even though the receipt prints doubles. Both face-contact nodes qualify without FC-7′ proxy promotion. `SurfaceCellTracing.cpp:3014–3026,4153–4210` unconditionally allocates a new node for each accepted contact and publishes its pair of events. A single struck-trace position is therefore assigned two producer node identities. The supported defect is a missing producer-owned coincident-contact identity/incidence invariant; chronology and whether pre-CB154 H1 masked this same conflict remain unknown. Do not merge in the consumer, delete an incidence, or use world-space proximity. FC-1/FC-4 general proof stays open.

### S4 / O45

RA-253 S4's prospective criterion is met: all printed terminal-contact barycentric coordinates are strictly positive, for both sites and all replays. This is a finite witness, not a universal contact census. The canonical source also supports the proper-crossing premise: opposite exact orientation signs on both straight segments entail an intersection strictly inside each segment. For valid nonnegative face barycentric endpoints, a zero coordinate at a strict convex combination would force both segment endpoints onto that supporting edge. The other segment, confined to the same closed face, cannot straddle that edge, contradicting strict opposite signs. A wall's exact contact exit is inherited from the same proper-crossing publication. This argument is limited to canonical same-face proper crossings, not every constructed/malformed candidate or future edge endpoint. The legacy diagnostic finalizer is a separate path (`:5113`, `:5505`); it does not establish universal FC-1/FC-4 proof. FC-7′ corrects the observed consumer proxy misuse; close O45 under S4 and preserve all guards and producer proxy metadata. Future genuine edge contact needs its own certified locus classification and must not be sent to FC-7′ as if it were interior. No assertion that all future or noncanonical contact kinds satisfy the premise. H2 unobserved and not excluded.

## Recommendation — bounded next turn (not executed)

**Sphere first:** `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT`, definition/review only. Freeze an exact producer-side contact rule for a shared, strictly interior source-edge endpoint, after tracing canonical proposal/committed-wall event ordering and exact source-edge/face transport. Distinguish transverse meeting, same-direction touch, opposing continuation, collinear overlap, barrier, port, same trace, unrelated sheets and distinct exact parameters; specify admissible terminal/continuation roles and one certified node/locus per actual incidence. Prove arrival ordering and any segment truncation preserve source provenance, event/arc identities, digests, termination/limit-cycle guards and Amendments 13/14. Require a positive produced witness of the actual sphere site and independent exact endpoint-incidence oracle plus negatives for distinct points/sheets, normal single crossings, barriers/ports and interior FC-7′ contacts. Stop definition if source authority cannot distinguish these cases or if a proposed contact would suppress a valid trace or violate exclusive locus. Freeze a scoped Code + Build diff and later artifact-only gate criteria only in that DEFN; preserve accepted prefix, all gate identities, 81 deferred, three census rows and 858 permitted RED until its separately authorized correction. No new measurement, code or gate mutation now. A later sphere gate must eliminate duplicateCutCrossing only by certified producer incidence; absence of the receipt through earlier failure is not sufficient.

**Held, not authorized next:** `M6-CP3-DEFN-P13-COINCIDENT-CONTACT-NODE-IDENTITY`. Define the producer's exact identity for multiple incident traces at the same struck-trace segment and rational parameter, respecting canonical face/sheet, contact roles and ordering. Positive witness: trace82/0 nodes220/222 conflict becomes one certified contact incidence (or a defined fail-closed typed result if inadmissible); keep terminating traces 43/15 and struck incidence, with no lost event. Adversarial controls: different rational parameters with identical printed doubles, different faces/sheets, separate contact groups, self-contact/terminal pair, ports/barriers. Stop if no exact event ownership rule or if identity depends on insertion order or coordinate welding. Freeze no implementation in this Review. If sphere repair changes this locus, re-derive it before authorizing the held DEFN. Do not combine the two repair surfaces in one code turn.

Carry C5/O42/O43/O46, H2, FC-1/FC-4 broad producer proof, middle-piece direction and one produced-witness debt; narrow C3/O44/C1 and O45 (consumer proxy only) closed. CB145 parked (C4/exact grazing); FC-6, terminal-cut outcome and 858 face-witness correction held; 858 after sphere repair. Vase failure unchanged. Stable 66 events / 17 categories / 49 recurrences; 81 deferred; CP2 491/491 package 11391685901, TB125 scoped 950/950 accepted, CP3/selector497/D0 unpromoted. D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`. No new stable regression, debit or witness discharge.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`; selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`; all 491 identities in order PASS. |
| Decisive claims independently re-derived | 956/956 substantive and normalized log matches, exact rejection guards, finite S4 witness and canonical proper-crossing proof. |
| Non-vacuity checked | Real failing guards and receipt replay, 5/5 negative controls; row648 unreached, 858 premise RED. No inferred production acceptance. |
| Prior obligations discharged/carried | O45 narrow closure; others as above. |
| Stable accounting | 66/17/49, debt1, deferred81, CP2 accepted 491/491, package 11391685901; no promotion. |
| New candidates/obligations recorded | Two non-stable producer candidates tracked, one authorized DEFN, one held. |
| ORIENTATION currency line | Updated for TB132 Review 2026-11-17. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated evidence disposition, witness attribution, open priority, existing producer-ownership pattern. |
| CHANGELOG | Entry added. |
| ROADMAP | Currency updated; no checkpoint movement. |
| Selector manifest | n/a; no selector acceptance or changes. |
| LESSONS | Existing §§1–5 rules apply; no new generalized lesson. |
| Consolidation | Superseded TB132 execution continuation folded verbatim into Volume D3 and indexed; current execution/comparator/definition authority retained. |
| Successor frozen | `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` only; falsifiers above. |
| Turn boundary | Static inspection and offline artifact comparison only; no product/test/fixture/build/selector edits. |
| review_check.py boundary | Ran on scratch exact snapshot: product/test/build/fixture and selector checks pass; historical ancestry and three durable rewrite source checks fail because the snapshot lacks Git history. Do not claim a full PASS; verify historical authority separately. |
| STATUS lifecycle | Entry published; final COMPLETE only after verified application and cleanup; otherwise IN_PROGRESS, no successor execution. |
| Push and sync | Connector workflow must attest patch push and exact changed paths; local scratch is not origin checkout. |

Procedural limitation: initial direct document reads preceded mandatory snapshot selection; corrected by verified snapshot. Full start-policy reading and tool-call ledger not certified. No policy changes. This limits procedural certification, not the independent evidence above.

## RA-254 — adversarial re-review of this Review (2026-11-17 UTC)

### S0 — verdict

The MATCH, the 956/956 comparison, the guard locations and the S4 proof for canonical proper crossings are upheld. I re-checked the TB132 gate and census ZIP SHA-256 values against the table above. I read the producer at `SurfaceCellTracing.cpp:4330–4430` and the consumer helpers at `EmbeddedGraphTopology.cpp:520–556` and `:685–721`. The successor is **withdrawn**: `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` is replaced by a measurement, because the receipt cannot tell the two possible contact kinds apart and they need different repairs. My own RA-253 S3 called BunnyRandom "likely a producer node-identity issue". That was premature for the same reason, and I correct it here.

### S1 — what the producer actually drops

Pending/pending (`:4344–4349`) and pending/committed-wall (`:4411–4417`) both `continue` on every kind except `ProperCrossing`. That includes both `EndpointTouch` and `CollinearOverlap` (classifier `:2378–2494`). The Review names only the endpoint case. Either discarded kind can produce both receipts:

- **Sphere.** Trace 4 and trace 6 each enter segment 7 through edge (0,2) at one exact parameter, in opposite directions: trace 4 goes (0,1,2)→(0,2,3), trace 6 goes (0,2,3)→(0,1,2). Two readings are possible:
  - **(a) Transverse.** The traces cross each other exactly on the edge. Each face sees only a V-shaped `EndpointTouch`.
  - **(b) Head-on overlap.** The traces share one supporting line in opposite directions, so the classifier returns `CollinearOverlap`. This is a separatrix-connection-type event, whose cure is a joined or terminated pair. A contact node on an edge is the wrong cure for it.
- **Static arguments conflict.** Reading (b) would make trace 4 cross ray trace 0 at trace 6's terminal point without stopping. Reading (a) needs an exact rational coincidence on edge (0,2). Yet the mirror-image terminal contacts differ by about 1e-16, so the mesh is not exactly symmetric. Neither reading is established.
- **BunnyRandom.** Nodes 220 and 222 sit at one exact rational point on trace 82 segment 0. Two readings are possible:
  - **(a′) Genuine triple point.** Traces 43 and 15 arrive from different directions.
  - **(b′) Overlap.** Traces 43 and 15 overlap upstream, so they share the supporting line in face (21,72,273).

  In case (b′), the held `COINCIDENT-CONTACT-NODE-IDENTITY` cure, which makes the two contacts one node, would hide a doubled arc that bounds a zero-area region. The Review's statement that "the supported defect is a missing coincident-contact identity" goes beyond the evidence.

### S2 — O45 transfer

The S4 proof is correct for canonical same-face proper crossings, and O45 stays narrowly closed. However, reading (a) is exactly a contact on a mesh edge. Such a contact strikes the other trace at a segment boundary. The consumer's `face_chart_segment_parameter` (`:533–556`) requires the exact parameter to satisfy 0 < t < 1, and FC-7′ assumes the contact lies strictly inside a face. Both would reject or misplace it. New obligation **O47: edge-locus contact representation in the consumer.** Any edge-contact repair must state how the contact node relates to the struck trace's own edge crossing (one node, one event set). O47 is owned by whichever DEFN the data selects.

### S3 — measurement: CB156 (exact, print-only)

`.agents/Directional/Architecture_M6_CP3_CB156_P13_Same_Face_Segment_Pair_Receipt_Exact.diff`:
- SHA-256 `1246f12b3cc22f62aa70ea503cf14e1f8438b160995e85225ba26c8fb7bfc205`, 90 lines, numstat `65 0 src/geometry/EmbeddedGraphTopology.cpp`.
- It adds `print_same_face_segment_pairs`. For every segment pair of two traces in one source face, it prints:
  - the segment indices, the face and both branches;
  - four exact `face_chart_orientation` signs: second segment's entry and exit against the first segment's line, then the reverse;
  - which canonical ends coincide (`ee`/`ex`/`xe`/`xx`).
- It is called inside both existing RA-253 receipts. For the sphere it compares traces 4 and 6. For BunnyRandom it compares the first terminating trace of the existing node with that of the claimant node.

Checks done:
- `git apply --check` passes at HEAD `b53e7b2a2`.
- A `-fsyntax-only` compile succeeds, with 22 warnings at both HEAD and patched.
- A Haiku read-only audit found the patch print-only:
  - calls happen only inside the two already-rejecting branches, between the precision save and restore;
  - every optional dereference is guarded;
  - there is no undefined behaviour.

Known limits: a degenerate segment (entry equal to exit) gives zero signs, so read `eq=` before calling a pair collinear. Only the first terminating trace per node is printed.

### S4 — TB133 criteria (frozen)

- **Inputs.** Same gate `941287fa…`, census `3af1dc0d…`, deferred `fd433f54…` and harness `78b8002c…`. Comparator: TB132 gate `14359654903`, census `14362615302`.
- **Normalizations.** N1–N4 as in RA-253 S7. **N5′:** delete the field `sameFacePairs=…` up to (not including) ` sharedEvents=` or the line end. The rest of every receipt line must then equal TB132's line byte-for-byte, with the same per-row count (66 lines across the same 19 sphere rows; 2 on BunnyRandom).
- **MATCH** requires all of the following:
  1. Every substantive ledger equals TB132's.
  2. The logs are equal under N1–N4 plus N5′.
  3. Every new receipt line carries a `sameFacePairs=` field.
  4. Nothing else differs. Any other difference is a MISMATCH.
- **Field contents are data.** `none` or `unevaluated` is data, not a mismatch.
- **Classification for TB133-REV.** On the pairs whose `eq=` names the shared locus:
  - All four signs zero means overlap, which selects `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` for the sphere, or that DEFN's co-directional case for BunnyRandom.
  - Any nonzero sign at the shared edge point means a transverse meeting. That selects `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` (with O47) for the sphere, or `M6-CP3-DEFN-P13-COINCIDENT-CONTACT-NODE-IDENTITY` for BunnyRandom.
  - If both sites are overlaps, one DEFN covers both.
- **Mismatch route.** `M6-CP3-PLAN-P13-SEGMENT-PAIR-RECEIPT-STOP`. Infrastructure route: `M6-CP3-CB156A-P13-SEGMENT-PAIR-RECEIPT-ORCH`.

### S5 — turn sequence

1. `M6-CP3-CB156-P13-SAME-FACE-SEGMENT-PAIR-RECEIPT` (Code + Build, compile only).
2. `M6-CP3-TB133-P13-SAME-FACE-SEGMENT-PAIR-RECEIPT-FULL-GATE-EXEC`.
3. `M6-CP3-TB133-P13-SAME-FACE-SEGMENT-PAIR-RECEIPT-FULL-GATE-REV`, which classifies each site per S4 and freezes at most one DEFN per site.
4. The selected DEFN.

Held: FC-6, terminal-cut outcome, and the row 858 face-witness fix (after the sphere repair). CB145 stays parked.

### S6 — lesson

Before naming a repair for an exact coincidence, list every classifier outcome that the producer discards at that locus, and measure which one occurred. A coincidence receipt shows that a point is shared. It does not show how the curves meet there.
