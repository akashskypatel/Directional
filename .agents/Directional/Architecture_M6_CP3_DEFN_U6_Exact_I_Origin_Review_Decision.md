# RA-95 — DEFN-U6 stopped without a deliverable; Review locates the exact I-endpoint origin; DEFN-U6A narrowed (2026-10-18)

**Turn:** `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER-REV`. **Inputs:** HEAD `73a014c4e`. `src`, `include` and `tests` are identical to CB14A `2ee499a3`, so every `S:` line below is valid there. TB14A result `12141843937` raw logs. **S** = `src/geometry/SurfaceCellTracing.cpp`. **Amends:** RA-94.5 (order) and RA-94.6 (spec). RA-96 (the DEFN-U6A review) is appended and amends RA-95.4/95.6. RA-97 (the TB15 review) is appended and withdraws RA-95.3's "p ≠ 1/5". RA-98 (the TB16 review) is appended and amends RA-97.4 item 5 and RA-97.5/97.6. RA-99 (the CB16A patch review) is appended; it fixes the CB16A compile source. RA-100 (the CB16A review) is appended; it accepts CB16A and pins the TB16A and TB16C inputs. RA-101 (the TB16A review) is appended; it pins the TB16C deliverables. RA-102 (the TB16C review, `Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md`) closes U6: B3 is cleared on all 19.

## RA-95.1 Turn state

- DEFN-U6 began (`acba9a334`) and requested a source snapshot (`df3458d23`; run `39148463200` succeeded). It then stopped with STATUS `IN_PROGRESS` and itself named as successor (`73a014c4e`).
- No deliverable and no document change exist, so there is nothing to adjudicate.
- RA-94.6 asked one turn to search a 21k-line file for an unlocalized origin, and to answer six items besides. That was too wide (LESSONS §6). Review localized the origin (RA-95.3) and narrows the turn (RA-95.5).

## RA-95.2 The 19 B3 identities are one shape (measured)

Every one of the 19 TB14A raw logs (focused30 3/12/14/15/17/18/22/23/24; focused12 5/6; selector 211/217/219/227/230/231; `cp3entry` 2/6) shows the same shape:
- `predicate=endpoint-1`, front 17/203, edge 1–4, faces 0/3, first failed condition `not-same-interior-carrier-point`;
- span 3 on both front records, with reciprocal ordinals `0/1→1/1` and `1/1→0/1`;
- face 0's barycentrics sum to exactly 1 + 2⁻⁵⁵, and face 3's to exactly 1.

Only `chi` differs: 0 in the 17 focused and selector identities, 3 in `cp3entry`. Satisfiability is therefore one template, and per-identity rows add nothing.

## RA-95.3 Exact origin located (Review trace; U6A verifies)

1. `append_arc_schedule` (S:17020-17046) reads the arc's single source-path piece and computes `first`/`second` with `exact_edge_parameter` (S:44-59), which takes the `ExactSourceEdgePoint::parameter` as a `FieldExactRational`. The span is the arc id (`ConformitySpanId::from_network_arc`), so both sides of span 3 share one arc and one schedule.
2. `location_parameter(ordinal)` (S:17205-17218) returns `first + local·(second − first)`, where `local` is the exact `breakpoint_location(span, ordinal)`. It is exact, computed at one site, keyed by (span, ordinal), and expressed in edge orientation (`edge.first` → `edge.second`).
3. **The exact value is lost here.** `append_point` (S:17177) calls `boundary_trace_point` (S:16944-16972):
   - `canonical = to_double(p)`;
   - `alpha = forward ? canonical : 1.0 − canonical`;
   - `bary[first] = 1 − alpha` and `bary[second] = alpha`.
4. The lattice-boundary override (S:17406-17421) places `acceptedBoundary[side].points[k]` at the boundary node. Cell corners copy `points[nodeIds]` (S:17500-17502), and the front edges copy the corners (S:17589-17590). The links onward to the three checkers are **not traced by Review**.

**Model check.** Take `c = to_double(p) = 0x1.9999999999999p-3`. Face 0, forward, then gives (`0x1.999999999999ap-1`, `0x1.9999999999999p-3`) with sum 1 + 2⁻⁵⁵. Face 3, reversed, gives (`0x1.999999999999ap-1`, `0x1.9999999999998p-3`) with sum exactly 1. Both observed triples match bit for bit. `a2bProbeBoundarySourceEntities` shows the same two parameters at region 0 node (5,1) and region 1 node (0,1). ~~Because `to_double(1/5) = 0x1.999999999999ap-3`, p ≠ 1/5~~ — withdrawn by RA-97.2: the GMP conversion truncates, and TB15 measured p = 1/5. The exact value of p is not logged.

**Consequence:**
- The one-ULP pair is orientation-dependent rounding at a single site, applied to one producer-origin exact rational that both sides share by construction.
- RA-94.6's "no exact origin" branch is answered: an origin exists. It is the "single canonical parameter" that R9B:29 anticipated.
- The rule stays exact equality, never a tolerance.
- **RA-63.5 still binds.** The endpoint's (span, ordinal) is endpoint-level, unlike the record-level conjunct that RA-61.9 used, but it is not bound to geometry. The design must bind p to each side's doubles; otherwise a forged ordinal pairs different points.

## RA-95.4 Order (amends RA-94.5)

- The DEFN-first rationale (feasibility) is largely discharged by RA-95.3. A narrow documents-only U6A is kept to close link 4 and choose the representation.
- DEFN-U6A-REV then:
  - issues the CB15 (U4) specification;
  - issues the U6 CB specification, or DEFN-U6B if the design is still open;
  - schedules the fixture debt.
- The planned code order U4 → U5 → U6 is unchanged. U6 has no dependency on U4/U5, and DEFN-U6A-REV may reorder them with a reason.

## RA-95.5 DEFN-U6A — `M6-CP3-DEFN-U6A-I-ENDPOINT-EXACT-ORIGIN-TRACE` (documents only)

Deliverable `Architecture_M6_CP3_DEFN_U6A_I_Endpoint_Exact_Origin_Trace_20261018.md`, 80 lines or fewer, citing `file:line` at `2ee499a3`.

1. **Verify or refute** RA-95.3 steps 1–3. A refutation names the line.
2. **Link 4:** list every writer from `acceptedBoundary[side].points[k]` to the compared points at the factory (S:8750-8773), the consumer (S:19480) and the probe (S:20065). Include the corner copy, `reverse_phase_front_cell_cycle`, and any cross-region pairing. State whether any arithmetic touches the doubles after `boundary_trace_point`.
3. **Endpoint to (span, ordinal):** show how each side's `sharedBoundaryInterval` first/second ordinals and `orientation` map to `from`/`to`, and show that the template resolves to span 3, ordinal 1 on both sides.
4. **p itself:**
   - its formula in terms of the arc's `ExactSourceEdgePoint` and `breakpoint_location`;
   - whether p lies strictly in (0, 1);
   - the existing field that would print it, or else the minimal probe a CB would add (named, not written).
5. **Representation.** Compare these candidates:
   - (a) a per-endpoint exact `ExactSourceEdgePoint` on `SurfaceFrontEdge`, set only by the accepted-boundary producer;
   - (b) recomputing p at the checkers from (span, ordinal), stating whether the baseline plan reaches `make` and the consumer;
   - (c) any other candidate.

   For each, state:
   - what reaches all three checkers;
   - how p binds to the doubles, e.g. bit-equality with `boundary_trace_point(p)` for that face and orientation;
   - that an I endpoint from any other producer carries no exact point and stays rejected (fail closed).

   Recommend one.
6. **CB outline** of 10 lines or fewer, applying RA-94.6 items 3 and 5 (rule and negatives) to the recommendation. Include TB predictions:
   - the 19 move past `endpoint-1` of front 17/203;
   - only those of RA-76's 324 one-ULP pairs that share an exact origin are accepted.

   Include falsifiers. Review writes the CB specification.

**Out of scope:** code, builds, runs, probes, U4/U5, fixture debt, selector or harness. **If RA-95.3 is refuted:** say where and stop. Never a tolerance. **Gates:** `document_drift_audit.py --root .`.

## RA-95.6 Sequence

DEFN-U6A → DEFN-U6A-REV → CB15/TB15 (U4) → CB16/TB16 (U5) → U6 CB/TB → RP-01 Review. Each CB follows a reviewed TB, and a RED TB goes to Review. Accounting unchanged: 66/17/49, debt 1, CP2 491/491, R3 403/497, census 425/497.

## RA-96 — DEFN-U6A reviewed: trace accepted; representation amended; U6 first as CB15/CB16 (2026-10-18)

**Turn:** `M6-CP3-DEFN-U6A-I-ENDPOINT-EXACT-ORIGIN-TRACE-REV`. **Subject:** `Architecture_M6_CP3_DEFN_U6A_I_Endpoint_Exact_Origin_Trace_20261018.md` (`636970568`; closeout `e99f49748`). `src`, `include` and `tests` are unchanged since `2ee499a3`. **B** = `src/geometry/GlobalConformityBaseline.cpp`; **H** = `include/directional/geometry/SurfaceCellTracing.h`.

### RA-96.1 Verification

- **Items 1–3 confirmed independently:**
  - with one support piece, `breakpoint_location` (B:740-766) gives `j/count` for 0 < j < count and `1/1` at j = count;
  - forward and reverse intervals own `from = p(j)` and `to = p(j±1)` (S:17219-17262);
  - `reverse_phase_front_cell_cycle` only permutes corners (S:12535-12546);
  - nothing writes a barycentric between S:17400 and S:20400.
- **Accepted finding:** the UV-proximity dedup (S:17190-17194) is a tolerance merge. The side's own invariant needs it (`intervals + 1 == points`, S:17289-17290), so any witness must pass through it exactly.
- **Item 4 was not delivered:** p cannot be printed from existing data. CB15 measures it instead. The interiority argument also misses j = count (where p is the arc's `second`); A1 makes interiority structural.
- The factory cannot authenticate (span, ordinal) → p, because `make` has no baseline plan. (b) is rejected for that reason, and RA-96.2 A4 states the trust root.

### RA-96.2 Amendments to representation (a)

- **A1 — canonical form.** The witness is built only through `canonical_exact_source_edge_point(edge, p)` (`ExactSourcePath.h:47-55`). It is kept only when the result is an `ExactSourceEdgePoint`:
  - so 0 < p < 1 holds by construction;
  - p ∈ {0, 1} carries no I witness, because the exact vertex gates already cover it.
- **A2 — the DEFN's dedup rule is defective.** Consecutive edges of one side meet at a shared vertex: p = 1 on edge 1–4, then p = 0 on edge 4–7, at the same chart occurrence (S:17149-17152, S:17185-17189). Applied to every sample, "reject unless edge and p agree" would make the producer reject every multi-edge side.
  - **Replacement:** when the dedup fires and the two witnesses differ (including one present and one absent), clear the kept point's witness.
  - No rejection and no behavior change. The endpoint falls back to the legacy exact gate, so U6 fails closed.
- **A3 — placement.** The witness lives inside `SurfaceTracePoint` (H:90-93) as `std::optional<authority::ExactSourceEdgePoint> exactEdgePoint`, not per endpoint on `SurfaceFrontEdge`.
  - Link 4 shows every hop is a copy of a `SurfaceTracePoint`, so in-point storage reaches every hop unchanged. (a) as written needs parallel arrays in three structures plus the reversal permutation.
  - A stale copy cannot bind (A4).
  - Cost: the type becomes non-trivially copyable. Benchmarks are not a gate (Gate C suspended). If a compile-time constraint forbids the change, CB15 stops and reports.
- **A4 — binding and trust root.** There is one rounding definition: `boundary_trace_point` (S:16944-16972) is moved unchanged into a detail helper that also sets the witness (A1). A witness binds iff:
  - its edge is the carrier edge;
  - the point's face contains both edge vertices;
  - the point's three doubles equal the helper's output, bit for bit, for one of the two orientations.

  The trust root is the producer, as in RA-84.2. The checkers cannot detect a forgery that is equal on both sides and consistent with both sides' doubles, and no stronger claim is made.

### RA-96.3 Order and renumbering (amends RA-95.4/95.6)

U6 goes first, in two units:
- **CB15** adds the witness with no admission change. Its TB measures satisfiability on real data before any rule changes (RA-61.7).
- **CB16** makes the checkers use the witness.

U4 and U5 follow as CB17 and CB18. Reasons for this order:
- the U6 design is complete and verified now;
- the U4 spec (RA-84, ten rungs old) has to be re-derived against today's factory;
- the units have no dependency on each other.

IDs are renumbered so turn numbers keep increasing.

### RA-96.4 CB15 — `M6-CP3-CB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` (compile only; no admission change)

1. **H:** `SurfaceTracePoint` gains `std::optional<authority::ExactSourceEdgePoint> exactEdgePoint;` with a one-line comment: producer-origin provenance, never identity unless bound. Include `ExactSourcePath.h`.
2. **Detail helpers**, declared beside H:1557:
   - `accepted_boundary_trace_point(faces, face, firstVertex, secondVertex, p, edge)`: the S:16944-16972 arithmetic unchanged, plus A1. The lambda becomes a call to it.
   - `exact_interior_witness_binds(point, faces, edge)`: A4.
3. **Dedup** (S:17190-17194): A2.
4. **Probe:** after the `railEnd` loop (S:20092-20100), append `;a2bProbeFromExact=<lo,hi@n/d|none>;a2bProbeFromExactBinds=<0|1>;a2bProbeToExact=…;a2bProbeToExactBinds=…` for `fromPoint` and `toPoint`, formatted like the ordinals (S:19858-19864). Nothing else changes.
5. **Unchanged:** S:64-97, factory S:8773, consumer S:19480, the probe condition at S:20065, and every other producer (no witness).
6. **P10 tests** (compiled, not run). Use p₁ = `from_double_exact(0x1.9999999999999p-3)` on edge (1, 4):
   - `SurfaceCellAuthorityContractCutover.AcceptedBoundaryRoundingReproducesTemplatePair`: the forward and reversed outputs equal TB14A's face-0 and face-3 triples bit for bit and carry equal witnesses; p = 0 and p = 1 carry none.
   - `SurfaceCellAuthorityContractCutover.ExactInteriorWitnessBindsOnlyItsOwnRounding`: both outputs bind. Rejected: a one-ULP barycentric tamper; edge (4, 7); p₂ = `from_double_exact(0x1.9999999999998p-3)` on the face-0 point; a face without the edge; an absent witness.
   - `SurfaceCellAuthorityContractCutover.OneUlpDistinctCrossingsKeepDistinctWitnesses`: p₁ and p₃ = `from_double_exact(0x1.999999999999ap-3)` each bind only to their own output, and the witnesses are unequal.
7. **Build and record:** GMP/GMPXX compile and package. Record of 25 lines or fewer: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.

### RA-96.5 TB15 — `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER`

The harness is derived from `m6_cp3_r10_open_rail_chain_interval_truth_table_harness.sh`, changing only sha, artifact, digest, labels and identities.

| # | Identity | Prediction |
|---|---|---|
| 1–3 | the three CB15 tests | PASS |
| 4 | `SurfaceCellAuthorityContractCutover.OpenRailRouteChainIntervalTruthTable` | PASS (control) |
| 5, 6 | the two P10 midline tests (B2, front 61/179) | RED. First failure identical to TB13A once the four new fields are removed. New fields: `none`, binds 0 (vertex 4). |
| 7, 8 | `cp3entry:2/6` | RED. Identical once the four new fields are removed. `FromExact` = `ToExact` = `1,4@n/d` with the same n/d; both binds 1; 0 < n/d < 1; ~~nearest~~ converted double `0x1.9999999999999p-3` (RA-97.2). |
| 9 | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` (selector 217, chi 0) | as #7/#8 |

Falsifiers, each sent to Review:
- any byte change outside the four fields (CB15 changed behavior);
- a witness on #7–#9 that is absent, unbound or unequal (the U6 design is wrong).

No census.

### RA-96.6 Fixture debt and sequence

- **Sequence:** CB15 → TB15 → TB15-REV (issues the CB16 spec) → CB16 → TB16 → TB16-REV (issues the CB17 spec) → CB17 (U4) → TB17 → CB18 (U5) → TB18.
- **Fixture debt** (RA-92.3, RA-93.3) follows TB18. These are test-only CB/TB pairs in the order 242 → 174 → 250 → adjacent-sheet helper → 191 family → 442. Then one census, then the RP-01 Review.
- Accounting unchanged.

---

# RA-97 — TB15 reviewed: the witness is p = 1/5, bound on both sides; CB15 accepted; CB16 rule specified (2026-10-18)

**Turn:** `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER-REV`. **Inputs:**
- CB15 source `e4785d734e35d2f01ca3ee8099772f6ab5257f4c` (HEAD `src/include/tests` identical) and package `12150973440`;
- TB15 result `12152685129`.

`S:` lines below are at `e4785d73`. **Amends:** RA-95.3 (last sentence), RA-96.5 (#7 wording) and RA-96.6 (sequence).

## RA-97.1 Re-verification

- **CB15 package.** ZIP `7f56c6a5…c073` reproduced; 28/28; build exit 0; source status empty. The packaged S, H and P10 are byte-identical to `e4785d73` and to HEAD.
- **CB15 diff from `2ee499a3`.** H +10, S +138/−27, P10 +119; nothing else under `src/include/tests`.
  - `accepted_boundary_trace_point` is the old lambda body moved verbatim, plus the A1 witness. The lambda now forwards to it.
  - Unchanged: the checkers (S:148-182), the factory call (S:8857) and the consumer call (S:19545).
  - Dedup follows A2. The probe fields follow the `railEnd` loop.
- **TB15.** ZIP `2536c38b…f748` reproduced; 13/13 manifest; 9/9 selected, 0 missing.
  - Harness `b3aa46de…` differs from TB13A's only in the pin and the identity list.
  - #1–#4 PASS.
  - #5/#6: `none`, binds 0.
  - #7–#9: `1,4@1/5` on both sides, binds 1/1.
- **Byte comparison.** With only the four new fields removed, #5–#8 are byte-identical to TB13A cases 3–6, and #9 to TB14A `raw/selector/ordinal-217.log`. Every RA-96.5 prediction held, and no falsifier fired.
- **The B3 record passes every later consumer condition:** A3 present, span 3 on both sides, reciprocal ordinals 0→1 / 1→0, rail 2. The only failing condition at front 17/203 is `same_interior_carrier_point`.

## RA-97.2 Owned Review error: p = 1/5

- **The error.** RA-95.3 inferred "p ≠ 1/5" from `to_double(1/5) = 0x1.999999999999ap-3`. That premise is false in the GMP build.
  - `FieldExactRational::to_double` calls `mpq_class::get_d()` (`include/directional/numerics/ENumberGMP.h:147`), which truncates toward zero. So `to_double(1/5) = 0x1.9999999999999p-3`.
  - RA-96.5's "nearest double" repeats the error. The agent's wording correction (`c03f31baa`) is accepted.
- **The measured value.** p = 1/5 = j/count, with j = 1 and count = 5.
  - The record's other accepted samples (2/5, 3/5, 4/5) are truncated the same way.
  - Truncation is the source of the 2⁻⁵⁵: face 0 stores trunc(1/5) beside round(1 − trunc(1/5)).
  - The rest of RA-95.3 stands.
- **Consequence for the design.** The bit binding is specific to the backend's conversion.
  - Producer and checkers share one binary and one helper, and the witness is never serialized, so they agree.
  - Any future persistence of the witness must not bind across backends.

## RA-97.3 CB15 accepted; binding proves consistency, not identity

- **Accepted.** CB15 makes no admission change.
- **Binding proves consistency, not identity.** `to_double` is many-to-one, so two distinct rationals with equal conversions bind the same doubles. One example: 1/5 and `from_double_exact(0x1.9999999999999p-3)`.
  - Identity therefore comes only from comparing the exact witnesses.
  - A bound pair must decide **both ways**. Otherwise the legacy rule, which compares doubles, accepts two distinct crossings whose rounded doubles coincide. That happens in the reversed form, which has an exact unit sum.
- **No later writer to check.**
  - Nothing rewrites a witnessed point: S:13602 is the periodic-chart locator in another producer, and S:20903 seeds streamlines.
  - No product digest covers `SurfaceTracePoint`.
- **One predicate serves all three sites.** `same_interior_carrier_point` (S:175-182) is called by the factory (S:8857), the consumer (S:19545) and the probe (S:20130). Changing it alone keeps all three in lockstep.
- **Limit.** The factory call still has no real-data coverage until a fixture reaches `make`.

## RA-97.4 CB16 specification — `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`

1. **Rule.** Change `same_interior_carrier_point` only:
   - (a) If either point carries a witness for which `exact_interior_witness_binds(point, faces, edge)` is false, return false. A witness that contradicts its doubles is corruption, so this fails closed.
   - (b) If both points carry witnesses, which by (a) are bound, return `*first.exactEdgePoint == *second.exactEdgePoint`. The legacy parameter is not consulted.
   - (c) Otherwise (no witness, or exactly one), apply the legacy rule unchanged. Cross-producer and witness-cleared pairs keep today's rule; nothing is weakened.
2. **Declaration.** Declare `same_interior_carrier_point` in H beside the CB15 helpers. Its signature does not change.
3. **Probe label** (S:20130-20133), inside the existing branch only:
   - `exact-witness-unbound` when (a) rejects;
   - `exact-witness-mismatch` when (b) rejects;
   - the existing labels otherwise.
4. **Unchanged:**
   - `interior_carrier_parameter`, the CB15 helpers, dedup and every producer;
   - every other guard at the three sites: orientation, A3, intervals, rail, contact paths and the terminal branches.
5. **Tests** (P10; compiled, not run). Let p = `from_ratio(1,5)` and q = `from_double_exact(double(p.to_double()))`, and assert q ≠ p.
   - `ExactWitnessIdentifiesTemplateInteriorPair`:
     - the face-0 forward point and face-3 reverse point built from p give true;
     - with both witnesses reset they give false, which reproduces B3.
   - `ExactWitnessRejectsDistinctValuesWithEqualDoubles`:
     - face-3 reverse points built from p and from q have bit-equal doubles and both bind, yet give false;
     - with both witnesses reset they give true. This is the hole the rule closes.
   - `ExactWitnessUnboundFailsClosedAndMixedKeepsLegacy`. Each of these gives false:
     - a `nextafter` applied to one witnessed point;
     - a witness on edge 4–7 checked against carrier 1–4;
     - the forward point with its witness against the reverse point without one.

     A pair of identical reverse points with one witness reset gives true.
6. **Build.** GMP/GMPXX compile and package. Record of 25 lines or fewer.

**Out of scope:** U4/U5, fixtures, selector, harness, and running tests.

## RA-97.5 TB16 and TB16C

**TB16** — `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`. The harness is the TB15 harness, changing only sha, artifact, digest, labels and identities. Twelve identities, in this order:

| # | Identity | Prediction |
|---|---|---|
| 1–3 | the CB16 tests | PASS |
| 4–6 | the CB15 tests | PASS |
| 7 | `OpenRailRouteChainIntervalTruthTable` | PASS |
| 8, 9 | the P10 midline B2 tests | Byte-identical to TB15 #5/#6. They fail at `carrier-orientation`, before the predicate. |
| 10–12 | `cp3entry:2/6`, selector 217 | The first failure is no longer `endpoint-1` at front 17,203. Record it verbatim and classify it by RA-90.4 with RA-91.2. Expected, not required: B2 at a later front. A PASS is admissible and is recorded. |

Falsifiers, each sent to Review:
- any change in #1–#9;
- any of #10–#12 still failing at `endpoint-1`, front 17,203;
- any `exact-witness-` label;
- `open-rail-chain-interval` anywhere.

**TB16C** — `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS`, run only if TB16 holds.
- **Run:** the unchanged `m6_cp3_entry_497_artifact_only_harness.sh` (`947a95ee…`) on the CB16 package, given only through its environment inputs.
- **Deliverables:** as RA-90.5, compared against TB14A (`12141843937`) instead of R3.
- **Predictions:** every TB14A PASS stays PASS, and each of the 19 B3 identities leaves B3.
- **Falsifiers:** any PASS → RED, any `exact-witness-` label, or any B1. Each goes to Review.
- **Why a census now:**
  - CB16 changes production admission at every I–I endpoint, and RA-61.7 requires a measurement before the next rule change.
  - U4/U5 need their measured population: RA-96.3 found that their spec must be re-derived.

## RA-97.6 Sequence

CB16 → TB16 → TB16C → TB16C-REV (re-derives and issues the CB17 U4 spec from the census) → CB17 → TB17 → CB18 → TB18 → fixture debt (RA-96.6 order) → census → RP-01 Review. Each CB follows a reviewed TB, and a falsifier goes to Review. Accounting is unchanged.

---

# RA-98 — TB16 reviewed: CB16 code accepted; the #3 falsifier is a Review spec defect; B3 cleared on the measured identities; CB16A corrects one row (2026-10-19)

**Turn:** `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV`. **Inputs:**
- CB16 source `1c45e89ae0ca7a072c5140aea2b95be6387ec078` (HEAD `src/include/tests` identical) and package `12154623660`;
- TB16 result `12183498229`.

**Amends:** RA-97.4 item 5 (one row) and RA-97.5/97.6 (sequence; TB16C runs on the CB16A package).

## RA-98.1 Re-verification

- **CB16 package.** ZIP `821edfc6…9956` reproduced; 0 manifest mismatches; `source-commit` `1c45e89a`; build exit 0. The packaged S, H and P10 are identical to the commit and to HEAD.
- **CB16 diff from `e4785d73`.** It touches only S, H and P10.
  - The rule (S:175-191) follows RA-97.4 item 1 line for line.
  - The declaration is at H:1565-1568.
  - The two labels sit inside the existing probe branch (S:20139-20153).
  - No other guard or call site changed.
- **TB16.** ZIP `8a329317…2dc32` reproduced; 16/16; 12/12 selected, 0 missing.
  - **#3** fails exactly twice, at P10:9463-9464, on the `corrupted` row. Its other five assertions hold.
  - **#8/#9:** the complete first-failure records are byte-identical to TB15 #5/#6. RA-97.5's "fail at `carrier-orientation`" names `a2bProbeFirstFailedCondition`; the predicate is `endpoint-1`.
  - **#10–#12:** the first failure moved to `endpoint-1` at front 97/283. Both ends are one-hot at vertex 4 (face 0 `(0,0,1)`, face 7 `(1,0,0)`), with `a3ProbeDecodedVertex=4`, `ContactEndpointMember=0` and `ContactPublished=1`. The ordinals on span 3 are 4→5 / 5→4, and there is no witness. That is **B2** by RA-90.4 with RA-91.2, the RA-97.5 expectation.
  - No `exact-witness-` label and no `open-rail-chain-interval` appear.

## RA-98.2 The #3 falsifier is an owned Review spec defect; the checker is right

- **What the mutation does.** Face 3 is (1, 7, 4). From p = 1/5 the helper gives:
  - reverse image: (`0x1.999999999999ap-1`, 0, `0x1.9999999999998p-3`);
  - forward image: (`0x1.999999999999ap-1`, 0, `0x1.9999999999999p-3`).

  `nextafter(slot 2, 1.0)` turns the reverse image into the forward image exactly.
- **Why the checker is right.** A4 (RA-96.2) binds to "one orientation" on purpose: the producer emits either image, depending on side traversal, and both represent p. The mutated point is therefore a valid image of its own witness, not a corruption, and `binds = true` and `same = true` are both correct.
- **Where the defect is.** RA-97.4 item 5 said "a `nextafter` applied to one witnessed point". It named no point, slot or direction, and Review did not check the mutation against both images. CB15's own row survives only because forward slot 2 toward 1.0 gives `…9ap-3`, which matches neither image. The localization in the TB16 report is confirmed.
- **No code change.** Swapping one valid image for the other changes no identity, because identity is the exact witness (RA-97.3).
- **Not weakening.** The replacement keeps the row's intent with a genuine corruption, and pins the measured image swap as an accepted property.

## RA-98.3 CB16 accepted; B3 status

- **CB16 accepted.**
- **B3 is cleared on the three measured identities.** They now stop at B2 at vertex 4, the same shape as the P10 midline tests at front 61/179.
- **The other 16 B3 identities** share the template (RA-95.2) and are predicted to move the same way. TB16C measures it.
- **Limit.** The factory call still has no real-data coverage.

## RA-98.4 CB16A — `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW` (test-only)

In `ExactWitnessUnboundFailsClosedAndMixedKeepsLegacy` (P10:9444; the `corrupted` row is at P10:9461-9464):

1. Let `forwardInFace3 = accepted_boundary_trace_point(faces, 3, 1, 4, *p, edge)`, and assert it is present.
2. Change the mutation to `std::nextafter(corrupted.barycentric[2], 0.0)`, which gives `0x1.9999999999997p-3`. Before the two existing `EXPECT_FALSE` rows, assert that the corrupted slot 2 differs bit for bit from slot 2 of both `*reverse` and `*forwardInFace3`. Keep both `EXPECT_FALSE` rows.
3. Add the accepted property. Let `otherImage = *reverse` with `otherImage.barycentric = forwardInFace3->barycentric`, keeping the witness. Then:
   - `EXPECT_TRUE(exact_interior_witness_binds(otherImage, faces, edge))`;
   - `EXPECT_TRUE(same_interior_carrier_point(*reverse, otherImage, faces, edge))`.

No other row, test or production line changes. GMP/GMPXX compile and package. Record of 25 lines or fewer: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.

## RA-98.5 TB16A and TB16C

**TB16A** — `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`.
- **Harness:** the TB16 harness, changing only sha, artifact, digest and labels. The same 12 identities, in the same order.
- **Predictions:** #1–#7 PASS. #8–#12 have first-failure records byte-identical to TB16.
- **Falsifiers:** any other outcome. Each goes to Review.

**TB16C** — `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS`, as RA-97.5 but on the **CB16A** package, and only if TB16A holds.
- **Predictions:**
  - every TB14A PASS stays PASS;
  - all 19 B3 identities leave B3. They are expected, not required, to become B2.
- **Falsifiers:** unchanged from RA-97.5.

## RA-98.6 Sequence

CB16A → TB16A → TB16C → TB16C-REV (re-derives and issues the CB17 U4 spec from the census) → CB17 → TB17 → CB18 → TB18 → fixture debt (RA-96.6 order) → census → RP-01 Review. Accounting is unchanged.

## RA-99 — CB16A patch reviewed: it conforms; the compile has not run; resume authorized (2026-10-19)

**Turn:** `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW-PATCH-REV`. **Inputs:** HEAD `0fdc5e9c9`; patch commit `7cfa5b4612ed67ec0bbddb747edbc6c53076b781` (drive-apply [run 39256723348](https://github.com/akashskypatel/Directional/actions/runs/39256723348), patch SHA-256 `437fc495…b74a`). STATUS is CB16A `IN_PROGRESS`, successor itself.

- **RA-99.1 The patch conforms.** `git diff 1c45e89a 7cfa5b46 -- src include tests` touches only P10 (+13/−1), and those lines are exactly RA-98.4 items 1–3. No production line changed. `<bit>` and `<cstdint>` are already included (P10:12, P10:15).
- **RA-99.2 Static evaluation, in exact arithmetic.** This predicts TB16A #3; it is not a runtime claim.
  - `to_double(1/5)` truncates to `…99p-3`. Face 3 reproduces slot 2 as `…98p-3` (reverse) and `…99p-3` (forward). The mutation gives `…97p-3`.
  - The binding compares the three barycentrics with those two reproductions (S:125-143). `SurfaceTracePoint` has only `face`, `barycentric` and the witness (H:91-96), so `otherImage` is the forward image in full.
  - Therefore both `EXPECT_NE` rows hold; `corrupted` binds to neither image, so both `EXPECT_FALSE` rows hold; `otherImage` binds and carries the same witness, so both `EXPECT_TRUE` rows hold.
- **RA-99.3 The turn is incomplete, not failed.** No compile request follows the patch; the latest dispatcher run is the drive-apply. CB16A is not accepted until its package is verified.
- **RA-99.4 Resume, compile only.** Same turn ID. Do not re-apply or edit the patch. The compile request uses `source_sha` `7cfa5b4612ed67ec0bbddb747edbc6c53076b781`, the eight CB16 targets and the prefix `directional-m6-cp3-cb16a`. The record (25 lines or fewer) gives the package ID, ZIP SHA-256, source SHA and `runtimeExecution=false`. TB16A, TB16C and the sequence are unchanged (RA-98.5/98.6).

## RA-100 — CB16A accepted; TB16A inputs pinned (2026-10-19)

**Turn:** `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW-REV`. **Inputs:** HEAD `abe261709`; compile [run 39266100202](https://github.com/akashskypatel/Directional/actions/runs/39266100202), package `12193816372`; record `Architecture_M6_CP3_CB16A_Exact_I_Witness_Unbound_Row_Code_Build_Record_20261019.md`.

- **RA-100.1 Re-verification.**
  - ZIP SHA-256 `113a5d8d783dc77f6b60a4da7c338478b3bd753a7e342b01169e4115dc77b2a3` matches.
  - Root manifest 28/28 OK (SHA-256 `f5ebf229a8ac9fad6a8797aefb36d8acb34a7e7441bb8dd9edb9858b4dfbf556`). Source archive SHA-256 `85d487e45086eb0a111207f790e67dcf7069517f1f06f3b3620573d56e29106b`. `source-commit` is `7cfa5b46`.
  - Preflight and build exit 0; the eight targets; `DIRECTIONAL_ENABLE_GMP=ON`, gmp/gmpxx linked; `runtimeExecution=false`; all five source-status files empty.
  - The packaged `src`, `include`, `tests` and `CMakeLists.txt` are byte-identical to git `7cfa5b46`. The compile request differs from CB16's only in its id, mailbox, source SHA and prefix.
- **RA-100.2 CB16A is accepted.** No source line changed after the RA-99 review.
- **RA-100.3 TB16A** (`M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`; refines RA-98.5).
  - **Harness:** the TB16 harness (SHA-256 `f8db713e…769b`), with only lines 7–9 changed (`sha` `7cfa5b4612ed67ec0bbddb747edbc6c53076b781`, `artifact` `12193816372`, `digest` `113a5d8d…b2a3`) and the `TB16_` output labels renamed `TB16A_`. The four pinned selector hashes (lines 49–52) stay unchanged; they still match at `7cfa5b46`. The same 12 identities, in the same order.
  - **Predictions:** #1–#7 PASS. #8–#12 RED, with `first_failure` byte-identical to TB16 result `12183498229`.
  - The 13 inserted P10 lines cannot move that field. It is the first runtime `predicate=` or `producer failed:` line, which carries no `file:line`, and the two P10 diagnostics (P10:7268, P10:7316) sit above the insertion.
  - **Falsifiers:** any other outcome goes to Review. A RED #3 also falsifies RA-99.2.
- **RA-100.4 TB16C**, only if TB16A holds: the unchanged census harness (`947a95ee…79dd`), run with `--execute` and:
  - `CANDIDATE_ARTIFACT_ID=12193816372`;
  - `EXPECTED_SOURCE_SHA=7cfa5b4612ed67ec0bbddb747edbc6c53076b781`;
  - `EXPECTED_CANDIDATE_ZIP_SHA256=113a5d8d783dc77f6b60a4da7c338478b3bd753a7e342b01169e4115dc77b2a3`;
  - `EXPECTED_ROOT_MANIFEST_SHA256=f5ebf229a8ac9fad6a8797aefb36d8acb34a7e7441bb8dd9edb9858b4dfbf556`;
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=85d487e45086eb0a111207f790e67dcf7069517f1f06f3b3620573d56e29106b`.

  Deliverables, classification and predictions are as in RA-97.5/RA-98.5, compared with TB14A.
- **RA-100.5 Sequence** (unchanged): TB16A → TB16C → TB16C-REV (CB17 spec) → CB17 → TB17 → CB18 → TB18 → fixture debt → census → RP-01 Review.

## RA-101 — TB16A reviewed: every prediction held; the U6 gates are closed; TB16C deliverables pinned (2026-10-19)

**Turn:** `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV`. **Inputs:** HEAD `28b55522e`; TB16A [run 39277232731](https://github.com/akashskypatel/Directional/actions/runs/39277232731), result `12198063461`; harness `m6_cp3_tb16a_exact_i_endpoint_witness_checkers_harness.sh` (SHA-256 `20b2ebd8…afea`); report `Architecture_M6_CP3_TB16A_Exact_I_Witness_Checkers_Harvest_Report_20261019.md`.

- **RA-101.1 Re-verification.**
  - ZIP SHA-256 `7f8769edbddc8439662526ca9520919ad78888b31a12abdd9548d476edd06cba` matches; manifest 16/16. Immutability: package, source, execution view and frozen selectors all true. 12 planned, 12 executed, 0 missing; compile, relink, benchmarks and selector497 all false.
  - The harness differs from TB16's only in lines 7–9 and the two labels.
  - #1–#7 PASS. The #3 log runs the corrected test, reports `OK`, and has no failure line.
  - #8–#12: the ledger `first_failure` fields match TB16's, but the ledger truncates at 600 characters. The full first predicate lines in the raw logs (6,972–9,565 bytes) are also byte-identical to TB16's.
- **RA-101.2 The U6 gates are closed.** All six U6 tests and the U3 truth table pass on one package. B3 status is unchanged from RA-98.3: cleared on the three measured identities, with 16 left for the census. The factory rule still has no real-data coverage; that needs an open-rail fixture that reaches `make`.
- **RA-101.3 TB16C can run.**
  - No test identity was removed since CB14A (1,231 → 1,237; the six new ones are CB15's and CB16's tests).
  - All 491 selector-file names exist at `7cfa5b46`. The selector files and the census harness are unchanged since TB14A.
  - The baseline is TB14A's `combined-ledger.tsv` in artifact `12141843937` (ZIP `1b06e43e…d455`), which **expires on 2026-11-01**. TB16C therefore commits its comparison as a TSV, so the baseline survives the artifact.
- **RA-101.4 TB16C deliverables** (refines RA-97.5, RA-98.5 and RA-100.4). The run is as RA-100.4.
  1. `Architecture_M6_CP3_TB16C_Selector_497_Red_Inventory.tsv`, one row per TB16C RED, with columns `phase, ordinal, identity, owner, exit, raw_sha256, class, first_failure (≤200 chars), TB14A (PASS/RED), TB14A_first_observable`.
  2. **Classification:** RA-90.4 with RA-91.2, applied to each RED's first `firstPredicate=` text, or its first gtest failure line when there is none. Class **U6** for any `exact-witness-unbound` or `exact-witness-mismatch`.
  3. A report of 30 lines or fewer giving:
     - totals per phase (30/12/449/6) and the count per class;
     - the TB14A PASS → RED list and the TB14A RED → PASS list;
     - the class of each of the 19 RA-95.2 B3 identities, by name;
     - the TSV's SHA-256.

     No interpretation.
  - **Predictions:** every TB14A PASS stays PASS, so there are at least 425 PASS. Each of the 19 leaves B3; becoming B2 is expected, not required.
  - **Falsifiers:** any PASS → RED, any U6 class, any B1, or any of the 19 still in B3. TB16C-REV follows in every case.
- **RA-101.5 Sequence:** TB16C → TB16C-REV (re-derives and issues the CB17 U4 spec from the census) → CB17 → TB17 → CB18 → TB18 → fixture debt → census → RP-01 Review.
