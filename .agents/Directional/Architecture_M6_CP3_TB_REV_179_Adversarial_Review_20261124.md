# TB-REV-179 — adversarial continuation (2026-11-24 UTC)

This continues turn `M6-CP3-TB-REV-179` after the [independent review](Architecture_M6_CP3_TB_REV_179_Retraced_Trace_Selection_Independent_Review_20261124.md).

The review was runtime-free. It used:
- source reading;
- one Haiku read-only inventory of the ordinal-407 contract, the row and census structs, the row-786 test, census admission and the empty-region check;
- `git apply --check`;
- `clang++ -fsyntax-only` on the test TU with the new diff applied.

## Verdict

- **Upheld:** the TB179 rejection, 1002/1003. The six recovered controls and the row-652 advance support the CB-199B selection. Row 786 is the only RED.
- **Upheld:** L2. Row 786 fails on a test-local premise that the frozen contract does not state.
- **Withdrawn:** the prose CB-200 plan. It gave the implementation agent five bundled items as a description, which is the pattern RA-261, H1 and J4 withdrew.
- **Replaced by:** an exact one-file test diff (M2), with frozen TB-EXEC-180 rules.

## Findings

**M1 — L2 holds against both the source and the frozen contract.**
- **The contract.** Ordinal 407 (`M3_Closure_Record.md:8250–8258`) requires publishing each crossed face and "its component in each named partition where defined", with typed reasons for absent membership. It has no clause requiring an arc to cross the plan subject.
- **Where the arcs come from.**
  - The certifier admits every trace arc that meets *its own* component (`SurfaceCutGraph.cpp:821–828`).
  - The plan row copies that census unfiltered and adds only the `planComponent` labels (`GlobalTopologyPlan.cpp:800–815`).
- **Why the two partitions differ at the terminal faces.**
  - The certifier keeps an equal-orbit terminal segment as a TerminalSlit face in its NotTraceCut domain (`SurfaceCutGraph.cpp:576`).
  - The plan labels the same face with its edge-side orbit (`GlobalTopologyPlan.cpp:1200`), which removes it from the unlabeled plan domain (`:1513`).
  - So on traces 6 and 10 the plan subject is a strict subset of the certifier component, and `touchesPlanSubject` is false for a lawful census.
- **Why this is not a weakened test.** The intersection check is replaced by stricter checks (M3), not deleted.

**M2 — The CB-200 plan was prose and bundled five turns. It is replaced by one exact diff, with three items pruned.**
- **Exact diff.** `Architecture_M6_CP3_CB200_P13_Cross_Partition_Arc_Census_Oracle_Exact.diff`, SHA-256 `d4cba179…bb26`, +155/−19, test file only. It compiles: 0 errors and the same 9 warnings.
- **Pruned: "exact unique matching certifier arc / source-path face set from the plan arc."** The row's arcs are a verbatim copy of the certifier census (`:800–815`). Comparing a copy with its source decides nothing. The decision lies in the labels, which M3 checks against independently derived membership.
- **Withdrawn: C4, the every-region-owns-a-face test assertion.** Production already enforces it. `GlobalTopologyPlan.cpp:1618–1627` rejects any region draft that owns no face through its orbit, and that is exactly the `RegionElectedCutComponentEmpty` that rows 652 and 656 reported. A test re-assertion would read nothing new (H3 precedent). The original zero-area region failure stays covered by production failing closed, and by rows 652 and 656.
- **Pruned: corruptions conditioned on fixture shape.** "Inserted plan membership" and "wrong present plan membership when a positive exists" depend on which faces the fixture happens to have. They are replaced by corruptions that can always be built from the real witness (M4).

**M3 — The new oracle checks strictly more than the old one.** It returns the name of the first failed invariant:
- Membership for each partition is derived from that partition's own published component lists:
  - plan: `locus.regionFrontierComponents`, which must not be truncated;
  - certifier: `certificate().uncutComponentCensuses`, which must be published;
  - a face listed twice in either partition is rejected.
- The plan subject must equal its derived component.
- The certifier subject must contain it, and must equal it exactly when the row says `Exact`.
- Every crossed face's `planComponent` and `certifierComponent` must equal the derived labels, **including absence**. The projected labels never build the oracle.
- A crossed face listed twice in one arc is rejected.
- Each arc must cross the certifier subject, which mirrors the admission rule (`:821–828`).
- The typed reason is still required wherever a certifier label exists.

The projections use the same `vertices()` order on every side (`RemeshPipeline.cpp:154`, `:781`, `:600`), so the face keys are consistent.

**M4 — Six corruptions, each checked against the invariant it must trip.**

| Corruption | Must be rejected by |
|---|---|
| crossed-face count +1 | `arcFaceCount` |
| crossed face duplicated | `arcFaceDuplicate` |
| plan label toggled | `planLabel` |
| certifier label erased | `certifierLabel` |
| certifier label wrong | `certifierLabel` |
| reason cleared | `reason` |

- Every reported arc crosses the certifier subject, so each copy can always be built.
- A copy rejected for the wrong reason fails the map equality.
- The certifier-only terminal faces (36,38,39) and (66,67,120) are printed by the existing receipt, not asserted. They are a prediction, not a rule.

**M5 — Carried, not changed.**
- J6: the production struck-reference remap has no witness. The mechanical fixture has no contact terminations.
- K6: rename after the controls are green.
- E5, row 979, Branch A and CB-190 stay held.

## TB-EXEC-180 rules (frozen)

1. **Code:** the CB-200 exact diff on top of CB-199B source `5d9468d1…`. Compile only in the CB.
2. **Manifest:** TB179 unchanged, `2928fd31…f2724`: 1,003 rows, 81 deferred, membership 1,084.
3. **Required result:** 1003/1003 PASS. Row 786 PASSes with `m3Cp4c3PlanInteriorArcCensusCorruptions` showing all six expected rejecting invariants.
4. **Comparison:** compare against TB179 `14895572803` under N1–N3.
   - Only row 786 may change: its PASS verdict and its new receipt lines.
   - Test lines move +65 after 5585 and +136 after old 20108. A changed record that contains `FieldAlignedCurveNetworkTests.cpp:` means STOP.
   - Any other difference means STOP.

## Turn sequence

1. CB-200: compile only, exact diff.
2. TB-EXEC-180.
3. TB-REV-180: adjudicate the full green gate. That covers:
   - the closure of the TB170 recurrence;
   - acceptance of the seven controls;
   - a new accepted baseline, if every claim re-derives.
4. CB-201: digest-neutral rename of the exact piece helpers out of `embedded_graph_topology_detail` (K6), then a byte-identical TB.
5. Row 979 (`RegionContainsInteriorSingularity`, vertex 8), then Branch A, then CB-190.

## Lessons

- Before freezing a test correction, read the frozen contract text. A test-local non-vacuity check can encode a fixture shape the contract never required.
- Before freezing a "new" assertion, check whether production already fails closed on the same condition.
