# TB149 — slide-contact arrival full gate: independent Review and comparison-authority ruling (RA-271, 2026-11-20 UTC)

Turn: `M6-CP3-TB149-P13-SLIDE-CONTACT-ARRIVAL-FULL-GATE-REV`. TB149 EXEC stopped as `REVIEW_BLOCKER`: "census strict raw comparison is 1/3 MATCH TB147; BunnyRandom and Vase GetParam object bytes differ outside frozen N1–N3". No TB149 execution report was written; this Review read the immutable archives directly.

## S1 — Evidence (independently re-derived)

| Item | Value |
|---|---|
| Gate | [run 44681234039](https://github.com/akashskypatel/Directional/actions/runs/44681234039), result artifact `14604413703`, ZIP SHA-256 `b9d0ff8746070c2d0928f8ac0647aa5bc0f5add542691b51932a6d85c0c1a621`; harness `planned 963, passed 963, red 0`, membership 1,044, postflight true |
| Census | [run 44683688761](https://github.com/akashskypatel/Directional/actions/runs/44683688761), artifact `14606235652`, ZIP SHA-256 `20534de76bd51ffa22bd5cb478b869adb760959139ef025cbf0e53cc531a5f94`; Cylinder PASS, BunnyRandom/Vase RED at `SurfaceCellDesignAcceptanceTests.cpp:493` |
| Baselines | TB148 gate `14598534659` (`dac729fa…294c4e`), TB147 census `14591964172` (`0c2e4843…498ac`); both SHA-256 equal to their recorded values |

A read-only comparator (a Haiku sub-agent, spot-checked by the Review against raw diffs) deleted every `FieldAlignedCurveNetwork.slideContactArrival` line and applied N1 (time), N2 (newlines), and N3 (M3 records as a counted multiset with ordered remainder).
- **Gate:** 963/963 MATCH TB148, ledgers equal except `log_sha256`, 491/491 PASS, 1,738 M3 records, none malformed.
- **Census:** all three ledgers equal TB147. Raw logs: Cylinder MATCH. BunnyRandom and Vase differ **only** in the two `[  FAILED  ] … where GetParam() = 16-byte object <…>` lines each.
- **Negative controls** (record removed, record duplicated, non-record byte changed, census byte changed outside the mask): all MISMATCH.

## S2 — Comparison-authority ruling

**N4 applies; census 3/3 MATCH TB147.** N4 ("only in the census parameterized rows, the bytes of `GetParam() = 16-byte object <…>` are masked") was frozen by the [TB131 Review S7](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Independent_Review_20261117.md) and applied by every census comparison since (TB142, TB144 and onward).
- The bytes are two `const char*` fields of `DesignAcceptanceCase` (`tests/SurfaceCellDesignAcceptanceTests.cpp:26–29`). They print as process addresses (`0x55…`, ASLR) and only on RED rows, which is why Cylinder never shows them.
- They carry no fixture or product value.

**Fault: the Review's freeze, not the executor.** RA-270 S3 wrote "rows 1–963 MATCH TB148 under the frozen rules (N1–N3) … census 3/3 MATCH TB147 after the same deletion".
- It copied the gate-only rule list from the TB148 report and dropped N4 for the census.
- The executor was right not to add a normalization on its own authority.
- Corrected prospectively: a census criterion always cites **N1–N4** (gate N1–N3). No other rule changes.

**TB149 verdict: PASS.** Gate 963/963 MATCH, 491/491, census 3/3 MATCH under N1–N4 with the frozen deletion.

## S3 — Receipts read against the prediction

The sphere prediction held exactly. Twenty sphere rows (380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858) plus row 963 printed 504 lines. They contain four distinct records, 126 times each:

```
moving=17:8 wall=0:6  wallCommitted=1 movingArrival=later
moving=20:8 wall=1:6  wallCommitted=1 movingArrival=later
moving=5:8  wall=21:6 wallCommitted=1 movingArrival=later
moving=8:8  wall=22:6 wallCommitted=1 movingArrival=later
```

BunnyRandom (census row 2, not gated) printed five more, each three times, all `later`:
- `26:1/99:0 wallCommitted=0`
- `152:2/148:0`
- `126:4/148:0`
- `33:3/24:1`
- `151:8/101:0`

Two facts matter for the repair:
- The struck slide can be on a **non-last** wall segment (indices 0 and 1).
- The wall can still be **pending**.

These are recorded for O48; the sphere switch below stays limited to committed walls.

## S4 — Realignment: the repair needs real slide pieces in the production graph

RA-270's table said "all later" → (a) a cut position on a slide piece, (b) the oracle reading pieces, (c) the stop switch, (d) a TB. Checking (a) against the arc builder shows that RA-270 S2.3 was right but incomplete. **The production graph has the same chord limitation as the row 686 oracle.**
- `build_arcs` takes every trace arc's path from `exact_trace_path_between` (`EmbeddedGraphTopology.cpp:1798`). That path writes each segment as one face chord from its entry to `exact_trace_segment_end`, which is the slide end (`:276–279`).
- The four sphere walls are `kind=faceThenEdge` (TB149 `committedSlide`). Their chord from entry to slide end leaves the edge, so it cannot pass through the contact point, which lies on the edge strictly inside the slide.
- `exact_trace_piece_path_between` already follows the real pieces, but it is unwired until the H4 cutover.
- The arc validator still requires one piece per segment. EPO-3 replaces that rule with `sourcePieceCounts`, and that work is not frozen either.
- **Consequence:** the stop switch (c) can't produce a valid struck arc until EPO-3 and the CB169 cutover are in place. RA-263's ordering ("O47 before H4") held for entry crossings on straight segments (CB168F/G). It does not hold for slide contacts.
- **EPO-5 amended:** a cut strictly inside a traversed slide is allowed on the edge piece in the piece path only. The production chord path still fails closed (`exact_trace_interior_point` needs a straight exit).

**Frozen now: CB168L.** It is (a) as an unwired helper, needed on every route and independent of EPO-3.

| Turn | Patch | SHA-256 | Numstat |
|---|---|---|---|
| `M6-CP3-CB168L-P13-SLIDE-INTERIOR-CUT-POSITION` | [diff](Architecture_M6_CP3_CB168L_P13_Slide_Interior_Cut_Position_Exact.diff) | `26401a6beb41aca02b0096c7079016a493b99444c0d92decd5d3b499f5ca8f3a` | `61 2 EmbeddedGraphTopology.cpp; 18 2 EmbeddedGraphTopology.h; 118 2 tests/FieldAlignedCurveNetworkTests.cpp` |

- **Representation.** `TraceCutPosition` gains no field. On a segment with a slide, `parameter` is the fraction along the edge piece from the slide start to the slide end.
  - That keeps the defaulted order equal to trace order even when the slide runs against the edge's orientation (sphere wall 22 slides 1543926228998011/2^51 → 0).
- **`carrier_contact_slide_position(struck, record)`.** Returns `{struckSegmentIndex, (p − from)/(to − from)}` when the locus is on the struck segment's slide edge and strictly inside it. It reuses `field_aligned_segment_slide_occupancy`.
  - It returns nothing for an empty slide (which also guards the division), the slide's ends, a point past the slide, another edge, another trace, an index past the end, or a straight segment.
  - It is disjoint from `carrier_contact_struck_position`.
- **`exact_trace_piece_path_between`.** It now cuts the edge piece of a traversed slide.
  - The earlier arc ends at the cut point, keeping the face piece before it.
  - The later arc starts on the edge piece at the cut.
  - It fails closed when the slide is not traversed (terminal contact before the slide) or `t ∉ (0,1)`.
  - Straight-segment clipping is unchanged.
- **Tests.**
  - Row 960 changes its two slide-cut assertions from fail-closed to exact paths, as the EPO-5 amendment requires: the edge (0,1) at 5/8, and the edge-only departure at 1/2. It also adds an untraversed-slide negative.
  - New row 964 `FieldAlignedCarrierOccupancy.CarrierContactInsideASlideCutsTheStruckEdgePieceOnly` covers:
    - a reversed slide, with exact pieces before and after the cut;
    - two cuts on one slide;
    - the bounds;
    - a production chord path that still fails closed;
    - nine record negatives.
- **Inert.** No production caller. `build_arcs` still uses `exact_trace_path_between`.
- **Precheck and syntax.**
  - Precheck: `git diff --quiet 0955d28e37a4f17f2488f0f4dd196a2d24aa3c11 HEAD -- src include tests`; `git apply --check` passes at `cae4fdd77`.
  - Preimages (SHA-256): `EmbeddedGraphTopology.cpp` `7cad07e8…7be9`, `.h` `d8e130e3…85a3`, tests `967a150b…a224`.
  - `-fsyntax-only -Wall -Wextra -include iterator`: 22 / 42 / 24 (`GlobalTopologyPlan.cpp`) warnings, all equal to HEAD, 0 errors.

**Frozen TB150** `M6-CP3-TB150-P13-SLIDE-INTERIOR-CUT-POSITION-FULL-GATE-EXEC`.
- Inputs: the immutable CB168L package, and manifest [`gates/Architecture_M6_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Case_Manifest.tsv`](gates/Architecture_M6_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Case_Manifest.tsv), SHA-256 `bce554e6723dfaa77f54d070aab7edc6508cd3aaf69a6120871e21b349b78926`. That is the TB148 manifest byte-for-byte plus row 964: 964 gated + 81 deferred.
- STOP on failure:
  - rows 960 and 964 PASS;
  - rows 1–963 MATCH TB149 under N1–N3 (no deletion: the receipt lines are retained and compared raw), with 491/491;
  - census 3/3 MATCH TB149 under **N1–N4**.
- Row 960's log may differ only through its changed assertions. A PASS prints no assertion lines, so its log is expected to MATCH.

## S5 — Sequence

CB168L → TB150 → TB150-REV, which freezes the exact EPO-3 binding CB: `sourcePieceCounts` on `ArcDraft`/`GlobalTopologyArc`, an exact validator, and all-ones from the producer (inert) → its TB → REV, which freezes the CB169 H4 cutover:
- paths, counts, rays and rank together (EPO-2/3/4/6);
- the O49 decision for edge-only segments;
- row 686 oracle reading pieces.

After the cutover TB, two exact CBs follow: the wall-loop stop switch, in which the moving trace ends at its entry with `carrierLocus`, and `build_cut_node_bindings` takes the struck cut from `carrier_contact_slide_position`. Then a TB with these falsifiers: row 686 χ = 2, rows 669/698 past exhaustion, and four Terminal/Interior events on four nodes.

Then CB170 → CB171 → CB172 (O48, which includes the BunnyRandom pending and non-last-segment slide contacts). Held: FC-6, TERMINAL-CUT-OUTCOME, the row 858 DEFN. Parked: CB145. D11=A, D12=A.
