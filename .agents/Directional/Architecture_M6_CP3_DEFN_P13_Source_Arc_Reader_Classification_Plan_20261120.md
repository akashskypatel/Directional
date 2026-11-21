# M6-CP3 — source-arc reader classification: withdrawn as a turn, completed by RA-274 (2026-11-20 UTC)

## Situation

The TB151 Review froze `M6-CP3-DEFN-P13-SOURCE-ARC-READER-CLASSIFICATION` as its only successor. [RA-274](Architecture_M6_CP3_TB151_P13_Source_Piece_Counts_Full_Gate_Independent_Review_20261120.md#ra-274--adversarial-re-review-of-this-review-2026-11-20-utc) withdraws it for three reasons:
- **It repeated a frozen contract.** EPO-1 (RA-262) already defines the traversal and geometry layers.
- **It had no executing exit.** Its acceptance criteria were prose.
- **It inherited an inventory with two errors.** It listed Mandatory-only readers and missed the conformity span input.

RA-274 S3 holds the complete classification. Do not start the DEFN turn.

## What replaces it

| Order | Turn | Scope |
|---|---|---|
| NEXT | `M6-CP3-CB168O-P13-EDGE-PIECE-FACE-SIDE-HELPER` | [Exact diff](Architecture_M6_CP3_CB168O_P13_Edge_Piece_Face_Side_Helper_Exact.diff), SHA-256 `b8daffc93c26260e9ad7af464560fe24de38054db66b57fa866ab1deacfa0d34`. Adds the unwired `edge_piece_face_side` (O49 side rule, RA-274 S2.3) and row 967. Compile only, eight RA-245 GMP/GMPXX targets. |
| Then | `M6-CP3-TB152-P13-EDGE-PIECE-FACE-SIDE-FULL-GATE-EXEC` | [Manifest](gates/Architecture_M6_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Case_Manifest.tsv), SHA-256 `cab375d014112b6ab48fe468003b9a57b2918a717e6f56e7478f0417362c0204`: TB151 plus row 967, 967 + 81 deferred. STOP rules in RA-274 S4.2. No census. |
| Then | `M6-CP3-TB152-P13-EDGE-PIECE-FACE-SIDE-FULL-GATE-REV` | Freezes the thin O49 ownership wiring and the row 686 piece oracle (test-only) as exact patches |

## Prospective (dependency order, not permission to combine)

1. O49 wiring CB → TB.
2. Row 686 piece oracle CB (test-only) → TB.
3. Producer switch. Paths, counts, rays and ranks together (RA-261), with counts added to the digest. Frozen only after the RA-274 S5 checks.
4. TB.
5. Stop switch CB (`carrier_contact_slide_position`).
6. TB: row 686 χ2, rows 669/698, four nodes, and real-piece conformity on the sphere's first plan.
7. CB170 → CB171 → CB172 (O48).

Held: FC-6, TERMINAL-CUT-OUTCOME, row 858 DEFN. Parked: CB145. D11=A, D12=A. `chainRimSchedules=false`.
