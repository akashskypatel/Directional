# RA-123 — TB24 seam-face harvest review (2026-10-21)

**Turn:** `M6-CP3-TB24-RP01-TORUS-A5-SEAM-FACE-HARVEST-REV`. **Verdict:** TB24 accepted as diagnostic evidence. The report's "consistent with B-fan" reading is **amended**: the site fits neither pre-registered branch. The owner is the A2 corner representative, which is chosen per node, not per occurrence (the RA-72.4 defect class). **No code is authorized.** DEFN-ISO is split into a census (A) and a contract (B).

## RA-123.1 Harvest verified independently

- Artifact `12364838156` (run 39641426480, head `840eccf1b`): the provider digest equals the local ZIP SHA-256 `dcf42df9…220d3`; expires 2026-10-28T17:12:14Z.
- `SHA256SUMS`: **14/14** OK (the report says 13; corrected here). Each raw log has exactly one `[ RUN ]` and no `SKIPPED`, and its SHA-256 equals the ledger. Rows 1–3 each carry one site, identical across the three; rows 4–9 carry none. `execution-boundary.txt`: no compile, relink or benchmarks; postflight true; runtime links `libgmpxx`/`libgmp`.
- The harness renders the TB23 harness under a pinned digest and drops TB23's root-manifest pin; the CB23 ZIP SHA-256 pin covers that manifest. Accepted.
- TB24 yielded with its documentation sync pending. This Review performs that sync, and TB24 counts as executed.

## RA-123.2 P1 and P2 held

All three A5 rows (W/P, T/P, T/D) emit one byte-identical site: the TB23 prefix plus
`;sel=121/0,121/0;support=vertex,vertex;wedge=120/0+121/0,97/2;spanOnly0=forward`. The guard `selector:447` and all five controls PASS without a site.

## RA-123.3 Decoded

- `fixture_probe --fixture torus`: vertex 61's fan in cyclic order is 142, 119, 118, 97, 120, 121; edge 60–61 has only rows 97 and 120; 121 ∉ fan(60). Both occurrences are therefore **the same grid node at vertex 61**.
- Occurrence (0,1) has wedge `120/0+121/0`, and its representative `121/0` lies **inside** that wedge, on its span's sheet.
- Occurrence (1,0) has wedge `97/2`, and its representative `121/0` lies **outside** that wedge, on the other sheet.
- `spanOnly0=forward`: without the face clauses, the side authority yields one forward certificate. That authority is `certified_seam_wedge_side` (RP:3855–3875), which already requires the span binding to be in the occurrence's wedge with the certified sheet. The face clauses (RP:3891–3892) are the only rejecting clauses.
- The representative is per node. The tracer copies one node point into every incident cell's corner (SCT:13404–13405) and sets that corner's `branchRotation`/`sourceChart` from the point's face (SCT:13410–13422). RP takes `selectedFace` from the same point (RP:4448–4458). This is RA-72.4's finding: one `SurfaceTracePoint::face` cannot be the authoritative face of every occurrence at a node.
- **Open premise:** 121 is the fan's *maximum* row, whereas RA-72.6's minimum-admissible-row rule predicts 97. How this node's face was chosen is unexplained.

## RA-123.4 Branch adjudication

Not B-across: the support is a vertex and `sel` ≠ 97/2. Not B-fan either: B-fan presumes each representative lies on its own occurrence's side, and occurrence (1,0) contradicts that. RA-121.6 routed on the first `sel` only. That under-specification was this Reviewer's; the report followed it faithfully and is not charged. Classification: **B-node**, a shared per-node representative used as per-occurrence chart authority.

## RA-123.5 Relaxing the face clauses is inadmissible

A6 (RP:5832–5877) requires gauge face = `selectedFace`, strips the face gauge from the corner lattice, and compares the result with the certificate's forward or reverse turn. That comparison presumes each occurrence's chart lies on its span's sheet, and the A5 face clauses are what guarantee it. For occurrence (1,0) the stripped value would be in sheet 0's frame but compared with a sheet 0→2 turn. Relaxing the clauses therefore either moves the reject to A6 (`RelationCertificateConflict`; RA-72.5: relocation is not repair) or admits a false pass when the turns coincide. B-fan's remedy is withdrawn. Requiring "representative ∈ own wedge, on the span's sheet" is sound, but alone it recovers nothing: it accepts (0,1) and still rejects (1,0).

## RA-123.6 Owner and unestablished premises

- **Owner:** A2 corner placement, which produces the occurrence representative and its lattice.
- **Enforcers known so far:**
  - A5: RP:3891–3892, the endpoint face gauge (RP:4669–4684) and hard-rail route endpoint attachments (RP:5051–5052);
  - A6: RP:5832–5877.

  A representative change also reaches hard-rail endpoints (controls `selector:217`, TB18 A#14).
- **Admissible shape (RA-72.4):** keep one canonical geometric node and give each occurrence a representative inside its own wedge.
- **Unestablished premises:**
  - (a) one representative per occurrence serves every consumer; a vertex wedge can span several faces (120 and 121) while each relation needs its span face;
  - (b) re-expressing the lattice at another face is exact from published witnesses. The corner `branchRotation` is the frame's per-face value (SCT:13419–13420), and the face-gauge table comes from that same frame (SCT:13579 → 13191; local path SCT:18434). If so, the stripped turn is identity by construction, and A6's seam-turn comparison must be re-derived, not assumed.
- **RA-78.10:** enumerate the enforcers before designing the rule. DEFN-ISO is therefore split into A (census) and B (contract).

## RA-123.7 Successor `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS`

Documents only: no `src`/`include`/`tests`/selector/workflow change, no compile, no runtime. Deliverable: `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md` (at most 80 lines). Anchor every answer to lines at HEAD (`src` identical to `e859175333`) and print the search commands verbatim.

1. **Enforcers:** every read of `placement.selectedFace`, `placement.lattice` (`branchRotation`, `sourceChart`), `cornerWedgeBindings` and the endpoint face gauges in `src/`, each with the frame it assumes (face, sheet or region).
2. **Frame semantics:**
   - which writer fills `sourceFaceBranchRotations` on the torus path (SCT:13579/13191 or SCT:18037/18434), and whether the corner `branchRotation` equals the gauge at the node face by construction;
   - what A6's stripped turn (RP:5859–5877) computes for two same-sheet occurrences and for two occurrences on the two certified sides;
   - whether TB24's relation could satisfy `seam.forward()` if (1,0)'s representative were `97/2`.
3. **Sufficiency:** for each consumer kind (seam and non-seam `OrdinaryFront`, hard-rail endpoint, periodic), the face the representative must equal, and whether one wedge face can serve them all or the gauge must be per (occurrence, side).
4. **Node face rule:** the rule that put vertex 61's node on row 121, set against RA-72.6's minimum-row prediction of 97.
5. **Reach:** which of the ten A5-ISO rows share this relation shape, and which of the five controls read a field that a representative change would touch.

**Non-goals:**
- no contract, rule or repair;
- no minimum-face rule (RA-79.4);
- no new producer certificate (RA-78.4);
- no clause relaxation.

**STOP:** if a question cannot be answered statically, say so and name the compile-only, rejection-only probe that would answer it. Do not guess.

## RA-123.8 Sequence and accounting

- **Sequence:** TB24-REV (this) → **DEFN-ISO-A** → DEFN-ISO-A-REV → DEFN-ISO-B (contract: per-occurrence representative, lattice re-expression, non-weakening, falsifiers) → DEFN-ISO-B-REV → corrective CB → CB-REV → TB → TB-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB21 449/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 14/14 manifest; 9 raw logs (one RUN, no skip, hash = ledger); site; fans and edge via `fixture_probe`; RP/SCT anchors above |
| Non-vacuity | The fields were emitted on three distinct identities; guard and controls selected and passed |
| Obligations | RA-121.4/121.6 and RA-122 discharged; RA-72.4 reopened for seam vertices; premises (a) and (b) carried to DEFN-ISO-A |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |
