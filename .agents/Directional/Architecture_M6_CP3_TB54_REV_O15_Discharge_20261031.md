# RA-181 — TB54 review: O15 discharged (2026-10-31)

**Turn:** `M6-CP3-TB54-O15-FULL-GATE-REV` (TB-REV, Review track), run locally.

**Independence is reduced.** The same session defined, built and ran O15's fix. To compensate:
- a Sonnet subagent did a read-only correctness review of the committed atlas;
- a Haiku subagent did the result audit and the mechanical run comparison;
- the decisive equivalence claim was recomputed from a separately configured FMA-free build of the exact CB55 source.

Variant builds are diagnostic only (GMP_COMPILE_POLICY).

## RA-181.1 Evidence re-verified

- **TB54 result** `build/local-evidence/TB54/result.zip` (`706f4ce7…`): 857 executed, 856 PASS, row 283 RED, membership 940, postflight true. The Haiku audit verifies 1,722/1,722 checksums and 857/857 manifest↔ledger↔log joins; the 940 membership pairs are exactly the manifest plus ledger v3. ([TB54 report](Architecture_M6_CP3_TB54_O15_Full_Gate_Local_Test_Report_20261031.md).)
- **FMA-free diagnostic** of source `04027167…` (atlas object with 0 FMA instructions): 857 rows give 856 PASS, with only 283 red. The verdicts equal TB54 row by row (0 mismatches). The 4,797 atlas partition records are byte-identical to TB54 (`65824e4b…`). Row 857 shows 3/3/3/3 at vertices 10, 35, 47 and 71 in both modes. Evidence: `build/local-evidence/TB54-REV/` (gitignored).
- **Source review (Sonnet):** T1, T2 and T3 at `04027167` are correct.
  - The gauge comparator is a strict weak order by counter-clockwise angle in [0, 2π), and its tie check means "same angle".
  - `u` and `v` solve the Gram system exactly.
  - The representative ratio order is monotone in angle, and the vertex indexing is consistent.
  - No float or tolerance decision is left at an exact topological tie; only conditioning guards and the near-integer lift check remain.

## RA-181.2 RA-176.3 discharge conditions

| Condition | Evidence | Met |
|---|---|---|
| Every A3 topological decision is exact, with a recorded tie rule | RA-180.2 rule; source review | Yes |
| `mechanical_feature` outcome is identical with `-ffp-contract` on and off | identical 3/3/3/3 and partitions on CB55's source | Yes |
| A failing-first witness fails before the patch on Linux-like arithmetic | row 856 FAILS on a pre-patch FMA-free atlas (RA-180.3) | Yes (Linux-like; CI not run) |
| An exact oracle test at vertices 10/35/47/71 | row 857 PASS | Yes |
| An outcome table for changed gate rows | RA-180.6, met by TB54 | Yes |

**Decision: O15 is DISCHARGED** on local evidence. A Linux CI confirmation is carried together with RP-01's (the first CI gate of this source or later must pass rows 856 and 857). TB54 (857, 856/1) is the reviewed local candidate. Row 283 stays **O2** (the same `segment_arrangement` signature). There is no new stable event: 66/17/49, debt 1. selector497 is not promoted and CP3 is not accepted.

## RA-181.3 Findings and carried items

- **F1 — O15c (new, carried; quantified risk, fail-closed).** Exact directions enlarge exact trace parameters. In row 669's census, the maximum trace-parameter width grew:

  | Witness | Before | After |
  |---|---|---|
  | genus_two | 107 bits | 217 bits |
  | sphere_prescribed | 429 bits | 1,531 bits |

  - The A4 continuation bound is 4,096 bits (`kFieldExactContinuationMagnitudeBits`). Beyond it, A4 declines with `BranchContinuationExactMagnitudeExceeded` and never picks a wrong topology.
  - The growth is intrinsic: the reduced exit point depends only on the exact component ratio, so rescaling the direction cannot shrink it.
  - Every gated and deferred row is within budget.
  - **Owner:** the P13 probe DEFN records the maximum continuation width on each design-matrix fixture.
  - **Falsifier:** any `BranchContinuationExactMagnitudeExceeded`, or a width above 50% of the bound, triggers a DEFN that chooses between a revised bound and a deterministic correctly-rounded direction with exact zero and sign handling.
- **F2 — vestigial code (noted, not changed; surgical-change rule):**
  - `canonicalDirections` values are now only size-checked;
  - `reference` is only a degeneracy guard;
  - the double `det` guard sits in front of the exact one;
  - the exact primary-versus-secondary tie reject is shadowed by the 1e-8 near-parallel guard.

  All of this is deterministic and harmless; it is cleanup material for a later refactor.
- **O15b** (the tie in the fields-stage matching argmin) stays carried to CP3-REV.

## RA-181.4 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| done | RA-180 → CB55 → TB54 → TB54-REV (RA-181) | DEFN, TB-REV / R; CB, TB local | O15 discharged |
| **NEXT** | `M6-CP3-DEFN-API-DISPLAY-VERTEX-STOP-WITNESS` | DEFN / R | Construct an input that a stage legitimately rejects with a source-vertex locus (RA-180.4), and freeze CB56 for row 935 |
| then | CB56 → TB55 → TB55-REV | CB, TB local; TB-REV / R | Row 935 moves to the gate (ledger v4, 82) |
| then | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (+ row 283) → P13 probe DEFN (Cylinder first; exact-atlas, route-step and **continuation-width (O15c)** checks) → slices → CP3-REV | per slice | CP3 exit |
| carried | Linux CI confirmation of TB53/TB54 (rows 854–857) | TB-EXEC / I | RP-01 and O15 falsifiers |
