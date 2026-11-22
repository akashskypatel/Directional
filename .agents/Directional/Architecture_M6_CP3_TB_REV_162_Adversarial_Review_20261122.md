# TB-REV-162 — adversarial continuation after handover (2026-11-22 UTC)

Continues `M6-CP3-TB-REV-162-P13-STAGED-PLAN-OWNER-EVIDENCE-RECEIPT-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_162_Staged_Plan_Owner_Evidence_Receipt_Independent_Review_20261122.md). Runtime-free: source reading, the [TB162 raw receipt](evidence/Architecture_M6_CP3_TB162_P13_Staged_Plan_Owner_Evidence_Receipt_Raw_20261122.txt), Haiku read-only audits, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **TB162 PASS upheld. H1 is upheld:** 16 source faces are `Unavailable` (`status=1 orbits=- sides=-`), and they form uncut components 1 and 5, eight faces each, with `seedCount=0`. H3 and H4 are falsified.
- **The prose `M6-CP3-CB-180-P13-SOURCE-FACE-ORBIT-OWNER-CERTIFICATION` is WITHDRAWN** (X2). In its place is the exact test-only `M6-CP3-CB-180-P13-STAGED-UNCUT-OWNER-CENSUS-RECEIPT`. TB-REV-163 freezes the exact owner repair from it, split into a helper CB and a wiring CB.

## Findings

**X1 — what the receipt already fixes.**
- `sourceFaces=192`, of which `traceCrossed=103`, `singleUncrossed=73` and `unavailable=16`; `conflicting=0`; 14 orbits, none exterior.
- Seeded components take orbits {1, 3, 8, 9}.
- Component 1 is the whole star of source vertex 12 plus faces `5-7-13` and `10-15-17`. Component 5 is the star of vertex 37 plus `29-31-38` and `36-41-42`. They are a symmetric pair.

**X2 — the frozen CB-180 is monolithic, has no rule, and leaves a runtime decision to a compile-only turn (RA-261, RA-280).**
- It bundles four jobs:
  - tracing oriented topology;
  - designing a new owner derivation;
  - three oracle families;
  - judging its own stop rule ("if the published graph contains no source-authoritative proof … stop").
- It names no predicate, site or diff, so the implementer would invent an owner rule. The stop rule needs exactly the per-edge census nobody has printed, and a Code + Build turn cannot produce it.
- Its positive oracle ("construct a small exact source-attached uncut disk") requires a hand-built canonical network, which is impossible (RA-248). Wired-path arithmetic must sit in pure helpers.
- Withdrawn.

**X3 — the mechanism, narrowed from code (`SurfaceCutGraph.cpp::build_source_face_ownership`, `:428–874`).**
- Uncut faces get owners from two places only:
  - (A) mandatory or cut arc sides (`:504–519`);
  - the component boundary seed (`:736–756`).
- The seed requires a boundary edge with `!barrierPresent && oppositeFaceTraceCut`, plus one of:
  - a unique owner on the opposite face. This is never true for a chord-crossed face, because site B adds both orbits (`:592–605`);
  - a unique edge-side owner. That record is written only by sites C (`:607–621`, the third edge when an incoming carrier exists) and D (`:624–647`, corner edges).
- Trace carriers become barriers (`:588–590`). The chord-side orbit facing a carrier is stored only on the crossed face; nothing passes it to the component side.
- So a component bounded only by barriers, or reaching trace-cut faces only through edges that sites C/D do not record, is `Unavailable` by construction. That is a rule gap, not proof that the geometry is ambiguous.
- Two different repairs follow, and which one applies depends on the per-edge rows. CB-180 prints them:
  - **R-a:** record an edge-side owner across the edge the component touches;
  - **R-b:** correct the barrier or terminal-slit classification (X4).

**X4 — a candidate soundness defect in the terminal-slit rule (H5, a hypothesis).**
- Terminal-slit segments do not insert their carrier as a barrier, and their face is not trace-cut (`:563–575`). That is sound only if the terminal piece is a free slit, with one orbit on both sides.
- The receipt contradicts that for trace 0. Its terminal arc `[6,7)`, nodes `(12,1)`, has `forwardOrbit=0 reverseOrbit=2` (`fragmentOwnerArc[1]`). Node 1 is also trace 9's end (`SphereStagedSlidePiece trace=9 … nodes=(16,1)`). Two terminal pieces meet there, so they bound different orbits.
- Ten traces publish `terminalSlit=true` and `end=point`.
- If H5 holds, the partition merges faces across an orbit boundary while also withholding their seeds. Any owner derived for components 1 and 5 would then be wrong, and R-a would hide the defect.
- CB-180 prints every arc's end nodes and the components' interior arcs, so TB-REV-163 can decide.

**X5 — H2 framing corrected.**
- The certificate census hard-codes `domainRule=NotTraceCut` and sets all barrier flags true (`:689–693`). So "distinct published domain labels" is a labelling artifact, not evidence.
- The real difference: the certificate's `barriers` set leaves out mandatory edges, while the plan's includes them. The six face-set digests agree on this fixture, so H2 is still not the cause.

**X6 — constraints for any owner repair (kept from the independent review where sound):**
- leave the 103 trace-crossed and 73 established owners unchanged;
- never take a lowest or first orbit;
- keep ambiguous and missing evidence typed;
- do not loosen `proves_cellularity()`;
- do not let the plan accept missing owners.

All TB-REV-161 W6–W8 and TB-REV-160 V3–V11 obligations are carried.

## Frozen artifact

| Artifact | SHA-256 | Notes |
|---|---|---|
| `Architecture_M6_CP3_CB180_P13_Staged_Uncut_Owner_Census_Receipt_Exact.diff` | `b5161a4659f8a68bfaea6a6e982462e6e8f007de93bf373936859f22776d2b32` (4,527 B) | tests only, +68/−0, row 979 only. Preimage = CB-179 postimage `98154a1fdffecf748d52fc3bef1c3923b3e350794a8c367ddafeeaa29ef9665e`; postimage `fedadbd318ad4754e7790c4232ccca055d8f97c64159c908dc7475aab7e82ef1` (recomputed independently). `git apply --check` OK; `-fsyntax-only` 0 errors, with the same 9 warnings as HEAD (none in the insertion). For each certificate uncut census not `Established` it prints `SphereStagedUncutCensus`, every `SphereStagedUncutBoundary` (with the opposite face's owner record), `SphereStagedUncutInteriorArc` and `SphereStagedUncutVertexTransit`. It also prints one `SphereStagedArc` (kind, trace, segments, end nodes) per embedded arc. |

The TB163 gate manifest is the TB161 manifest, unchanged (`e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a`, 979 rows).

## TB163 rules (STOP unless all hold)

1. 979/979 PASS; CP2 491/491.
2. Rows 1–978 raw logs equal TB162 artifact `14746794132` under N1–N3, with a zero allowance.
3. Row 979 equals TB162 row 979 under N1–N3 after deleting only lines that start with `SphereStagedUncutCensus`, `SphereStagedUncutBoundary`, `SphereStagedUncutInteriorArc`, `SphereStagedUncutVertexTransit` or `SphereStagedArc`. All 60 TB162 row 979 lines must reappear verbatim.
4. No census: product source is unchanged. Census authority stays TB161 `14741883606`.
5. Publish every new line verbatim. Informational predictions:
   - two `SphereStagedUncutCensus` lines (components 1 and 5, `status=1`, `seedAttributions=0`, `truncated=0`);
   - 30 `SphereStagedArc` lines.
6. Any failure means STATUS BLOCKED and a return to Review. Do not edit tests or the manifest.

## TB-REV-163 decision map

| Signature | Repair to freeze |
|---|---|
| Boundary edges `barrier=0 oppositeTraceCut=1 sideOwner=0`, and the opposite owner's `sides` name one chord whose orbit faces the edge | R-a: an edge-side owner record at site B for the edge the component touches. Exact pure helper with tests first (CB-181), then wiring (CB-182). |
| Every boundary edge `barrier=1`, with terminal-slit arcs sharing end nodes (`SphereStagedArc`) | H5: the terminal-slit classification is wrong for meeting terminal pieces. Fix the classification at its single source before any owner derivation. |
| A component's interior arcs with `forward≠reverse` | H5 confirmed inside the component; R-a is forbidden. |
| None of the above | Typed STOP with the exact missing obligation. No owner is invented. |

## Turn sequence

1. CB-180: test-only census receipt, compile only.
2. TB-EXEC-163.
3. TB-REV-163, which freezes CB-181 (pure helper with positive and negative tests, unwired) and CB-182 (wiring).
4. CB-181.
5. CB-182.
6. TB-EXEC/REV-164: staged plan `built`, or the next measured stage.
7. CB-183: activation (V3/V4/V5/V10/V11).
8. TB-EXEC/REV-165.
9. CB-184: V3b.
10. R1, then RA-275 S4a, then O48.

## Lessons

- Before freezing an owner derivation, list every site that writes the owner map and every gate on its seed path. "Unavailable" can be a rule gap rather than real ambiguity.
- Check that a "free slit" assumption matches the orbits the receipt prints on both sides of the piece.
- A published "domain label" that is hard-coded is not evidence of a domain difference.
