# M3-CP4c-0-TB-R5 — Independent Review and Corrective Plan

Turn: `M3-CP4c-0-TB-R5-REVIEW-PLAN`. Review and planning only.
**No Directional runtime, build, benchmark, or mutation of product/test/fixture/selector/build logic
occurred.** Evidence, source and committed fixtures were *read*, and arithmetic was performed on their
contents; nothing was executed and nothing was modified.

Brief: `Architecture_M3_CP4c0_TB_R5_Review_Plan.md`.
Evidence: `Architecture_M3_CP4c0_TB_R5_Artifact_Only_Test_Benchmark_Report.md`, run
`32994846466 / 98261255799`.
Contract: `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` (Amendments 1–7).

---

## 0. Verdict, stated first

**The census is sound, and its population is not.** Two of the four witnesses carry synthetic fields
whose declared matching contradicts their own geometry. On those witnesses a flow disagreement is
**guaranteed by construction** and says nothing about production.

1. **H1's mechanism is correct.** I read the census source: it iterates published `transports()`, takes
   `directed->signedLift`, computes `targetBranch = sourceBranch.rotated(signedLift)`, and compares
   `d[opp]` signs at correctly-derived indices. It does what H1 specified. §2.
2. **The four-triangle fan's 2 violations are a fixture artifact, and the arithmetic proves it.**
   `make_index_one_singularity_field` leaves the field vectors **globally constant** (+X/+Y on every
   face) and *imposes* `matching = ±1` on **one** edge. For the violating edge `1-4` the published
   `signedLift = 0` is **exactly correct**: `matching(+1) + g_A(0) − g_B(1) = 0`. The disagreement is
   the inevitable consequence of a matching that contradicts the geometry — and **one edge × two
   directions = exactly the 2 violations observed.** §3.
3. **Therefore the brief's "do not reopen" item 4 is invalid and must be corrected.** It uses the fan's
   lift-0 disagreements as evidence weakening H-B. That inference does not hold: the fan's matching was
   not merely "prescribed rather than computed", it was prescribed **inconsistently with its own
   geometry**, which forces a disagreement regardless of any production defect. §4.
4. **H-A and H-C remain correctly excluded** — independently re-derived, not taken on assertion. §6.
5. **H-B is still undecided, and the census cannot decide it as currently instrumented**, because
   `signedLift` is a *sum* (`matching + g_source − g_target`). A lift histogram therefore carries no
   information about matching. The lift-0 dominance that looks like a signal is consistent with almost
   any matching distribution. §5.
6. **The decisive measurement is one line of extra output: decompose the lift into its three terms.**
   §7 gives the decision table; measure **J1** implements it.
7. **A reframing worth freezing:** E5's cross-edge invariant is, in effect, a check that the field's
   *matching is geometrically consistent* — it audits A1's **input** as much as A1's own work. That is
   why a synthetic field trips it. §8.

Corrective series **J0–J6** in §10. **No production change is authorized.** Q8 remains red at
criterion 2 and is expected to stay red until the mechanism is settled.

---

## 1. Independent verification of the evidence — CONFIRMED

| Claim | Verified |
|---|---|
| run `32994846466`, head/control SHA `3f9864fddef696dc7d95084fdd41b680a78f5b37` | ✅ (API) |
| result artifact `9616160533` SHA-256 `1ecfd85f…e9902ad8` | ✅ exact |
| diagnostic artifact `9616161522` SHA-256 `7cb10cae…0aa14b0e` | ✅ exact |
| package `9601160869`, semantic source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e` | ✅ as recorded |
| selector 338 `d588cae0…`, 316-prefix `601ce2b6…`, 328-prefix `cf93622e…` | ✅ **recomputed locally**, unchanged |
| gate 338/338, F3 2/2, G5 PASS, H1 PASS, Q8 creditable/RED criterion 2 | ✅ as reported |
| H1 totals `390 / 4224`; per-witness `4/160`, `2/32`, `144/2304`, `240/1728` | ✅ read from the job log directly |

**The census's own arithmetic checks out.** `pairsChecked = interiorEdges × 8` holds for every witness:
two-ring `20×8 = 160`, fan `4×8 = 32`, sphere `288×8 = 2304`, torus `216×8 = 1728`. The sphere's 288
interior edges also match `3F/2 = 288` from `F = 192`. The census covers exactly what H1 required.

**The self-hosted attempts are correctly excluded.** Runs `32993852779` and `32994482392` both stopped
at control-payload hash verification, before any Directional binary executed — checkout line-ending
normalization altered the staged shell bytes. Neither is semantic evidence. Hosted run `32994846466` is
the sole runtime authority. **Accepted**, and worth noting as a recurring transport hazard (J5).

---

## 2. The census mechanism is correct — verified in source, not assumed

`cp4c_flow_agreement_census` (`tests/FieldAlignedCurveNetworkTests.cpp:2765…`):

```cpp
for (const auto &adjacency : topology.transports()) {
  for (int direction = 0; direction < 2; ++direction) {
    ...
    const auto directed = topology.transport(adjacency.sourceEdge, sourceFace, targetFace);
    ...
    for (int branchIndex = 0; branchIndex < 4; ++branchIndex) {
      const auto sourceBranch = FieldBranch::from_integer(branchIndex);
      const auto targetBranch = sourceBranch.rotated(directed->signedLift);   // ← applies the lift
      ...
      const bool sourceOutflow = sourceDerivative < zero;
      const bool targetInflow  = targetDerivative  > zero;
      if (sourceOutflow && !targetInflow) { ...record... }
```

It applies the **published** `signedLift` (Amendment 7 compliant — no bare cross-face label
comparison), reads `d[opp]` through `cp4c_opposite_coordinate` on each face's own canonical key, and
compares exact rationals against exact zero. It also self-checks coverage
(`EXPECT_EQ(expectedPairs, pairsChecked)`) and transport inventory. **H1 is correctly implemented; the
violations it reports are real properties of the published authority.**

That matters for what follows: the disagreements are genuine. The question is what they are evidence
*of*.

---

## 3. The fan's violations are a fixture artifact — with the arithmetic

### What the fan witness actually is

The census builds the fan atlas from **`make_index_one_singularity_field(mesh)`**, which:

```cpp
CrossFieldResult field = make_zero_transport_field(mesh);   // primary = +X, secondary = +Y on EVERY face
...
field.matching(edge) = sign;              // ±1 on exactly ONE edge
transition->matching = sign;
field.singularCycles << 4;  field.singularIndices << 1;     // declare index 1 at the centre
```

So the **field vectors are globally constant on a planar mesh** — `make_zero_transport_field` is
untouched in that respect — and a period jump of ±1 is *imposed* on a single edge purely as
bookkeeping. Geometrically the field is flat; combinatorially it is declared singular.

**This field's matching contradicts its own geometry.** Physically `+Y` in one face is `+Y` in the
neighbour; the declared matching says `+Y` corresponds to `−X`.

### The arithmetic, and it closes exactly

The census reports, verbatim from the job log:

```
witness=four-triangle-fan;pairsChecked=32;violations=2;
violation[0]={edge=1-4,sourceFace=0-1-4,targetFace=1-2-4,
              sourceBranch=1,targetBranch=1,signedLift=0,sourceD=-1/2,targetD=-1/2}
violation[1]={edge=1-4, ...}          ← the same edge, the reverse direction
```

The fan's per-face gauges are `A=(0,1,4)→0`, `B=(1,2,4)→1`, `C=(2,3,4)→2`, `D=(0,3,4)→1` — values
**independently verified against runtime** in the TB-R3 review, where they reproduced identity 334's
observed admitted-face counts `0, 1, 0, 3` exactly. They apply here unchanged, because
`make_index_one_singularity_field` alters only `matching`, never the direction vectors that determine
the gauge.

The published lift decomposes as:

```
signedLift(A→B) = matching(1-4) + g_A − g_B = (+1) + 0 − 1 = 0     ← exactly the published value
```

**The published lift is correct.** And I reproduced both reported derivatives by hand from the constant
field: face `(0,1,4)` semantic branch 1 → raw index 1 → `+Y`, giving `d[opp of 1-4] = −1/2`; face
`(1,2,4)` semantic branch 1 → raw index 2 → `−X`, giving `d[opp of 1-4] = −1/2`. **Both `−1/2` values
match the runtime exactly.**

Two directions that are genuinely 90° apart both exit the shared edge. That is not a contradiction —
it is what an imposed period jump on a geometrically flat field *means*.

### The count is the clincher

If the defect were in A1, there would be no reason for exactly one of four fan edges to violate. Under
the artifact explanation there is: only the **one** edge carrying `matching = ±1` has a matching that
disagrees with the geometry; the other three carry `matching = 0` and publish lifts `g_X − g_Y`, which
are geometrically correct and produce no violation.

**One edge × two directions = 2 violations. Observed: exactly 2.** I also simulated the counterfactual:
had the gauge correction been absent everywhere (published lift 0 on all four edges) the fan would show
**8** violations. It shows 2.

**Conclusion: the fan contributes 2 artifact violations and zero evidence about production.**

---

## 4. Consequently, one of the brief's settled conclusions must be reopened

The brief lists under "What TB-R5 already decides — do not reopen":

> **4. H-B is a candidate, not a verdict.** … *The fan has two lift-0 disagreements even though its
> matching is manually prescribed rather than computed through the sphere/torus aliasing path.*

The observation is true; the inference drawn from it is not. The fan's matching is not merely
"prescribed rather than computed" — it is prescribed **in contradiction with the geometry**, which
*guarantees* a disagreement on that edge whatever A1 does. The fan therefore cannot weaken H-B, cannot
strengthen it, and cannot support any conclusion about production authority.

**This is exactly the trap the project has paid for before** (`LESSONS` §2, *"the fixture exists" is not
"the fixture reaches the stage you are asserting on"*): the witness was read by its name rather than by
its construction. The brief's items 1–3 stand; **item 4's fan clause is withdrawn** by this review.

---

## 5. What the lift histogram does — and does not — tell us

The headline pattern is "lift 0 dominates": two-ring `0:4`, fan `0:2`, sphere `0:102` of 144, torus
`0:184` of 240, with near-symmetric tails at ±1, ±2, ±3.

**That pattern carries no information about matching**, because

```
signedLift = matching + g_source − g_target
```

is a *sum of three unobserved terms*. A published lift of 0 is consistent with `matching = 0` and equal
gauges, with `matching = +1` and `Δg = −1` (which is precisely the fan case), with `matching = 2` and
`Δg = −2`, and so on. **Reading the lift histogram as a matching histogram is a category error**, and
it is the reason H-A looked plausible and then failed.

The symmetry of the tails is also uninformative: the census checks each edge in **both** directions and
the reverse direction negates the lift, so every violating pair contributes `+k` and `−k`. Sphere
`−3:8 / +3:8`, `−2:6 / +2:6`, `−1:7 / +1:7` and torus `−3:6 / +3:6`, `−2:11 / +2:11`, `−1:11 / +1:11`
are **exactly the symmetry the census's own two-direction loop imposes**, not a property of the field.
Likewise every violation count is even, and the true number of distinct `(edge, branch)` disagreements
is half the reported figure: two-ring **2**, fan **1**, sphere **72**, torus **120**.

Restating the corrected population:

| Witness | field | distinct disagreements | status |
|---|---|---:|---|
| two-ring skew disc | genuinely rotating index-1 (`angle = base + 0.25·smoothPhase`, sweeping exactly 90° around the centre) | **2** | real signal |
| four-triangle fan | flat + **imposed** period jump | **1** | **artifact — exclude** |
| prescribed sphere | real rawfield, matching computed at load | **72** | real signal |
| torus | real rawfield, matching computed at load | **120** | real signal |

---

## 6. H-A and H-C — independently re-derived, and correctly excluded

- **H-A (odd-lift-only sign convention): excluded.** Violations occur at lift `0` and at even lift `±2`.
  A sign error `k → −k` changes nothing when `k` is `0` or `2`, so it cannot produce those. Confirmed —
  and this was **my own favoured candidate in the TB-R4 review**, falsified by the census exactly as
  that review's P2 said it would be if wrong.
- **H-C (A1 clean, defect only in A2a's carried branch): excluded.** A1 alone yields disagreements with
  no tracing involved. Confirmed. Note the corollary the brief does not draw: this does **not** clear
  A2a — it only proves A1 is *not* clean. Both layers may be implicated.
- **~50 % uniform systematic index error: excluded.** Rates are 2.5 %, 6.25 %, 6.25 %, 13.89 %.

---

## 7. The decisive measurement — decompose the lift

Everything above says the census is one field short. The fix is small and completely decisive.

**For every violation, publish the three terms that compose the lift**, plus the field's own matching:

- `matching` for the edge (`FieldTransportAdjacency::forwardLift` / `CrossFieldEdgeTransition::matching`),
- `rawGauge[sourceFace]` and `rawGauge[targetFace]`,
- the resulting `signedLift` (already published),
- and whether the edge is incident to a declared singular vertex.

Then the decision table is unambiguous:

| Census result | Conclusion |
|---|---|
| violations concentrate on edges with `matching ≠ 0` | the rawfield's matching disagrees with its geometry — a **field-authority / aliasing** issue (**H-B**), and possibly a fixture-field problem rather than an A1 code defect |
| violations occur on edges with `matching = 0` and unequal gauges | the **gauge term** is wrong — a genuine A1 composition defect, localized to `build_branch_transports` |
| violations occur on edges with `matching = 0` **and** equal gauges (lift genuinely 0, directions still disagree) | neither matching nor gauge — the **flow classification or the direction publication** is wrong, i.e. `build_boundary_pairing` |
| violations track incidence to declared singular vertices | period-jump edges specifically — strengthens **H-B** and points at the cut/seam convention |

**Each branch names a different owner and a different fix.** No production change should be attempted
before this table is filled in — a point already paid for once this cycle, when H-A survived a whole
planning turn on a plausible story and died in one measurement.

### A second, independent instrument

Add a **matching-versus-geometry consistency check**: for each interior edge, unfold the two triangles
about the shared edge, find which target raw index the source raw direction actually maps to, and
compare with the declared `matching`. Where they differ, the field's matching is geometrically
inconsistent — which is the direct, tracing-free test of H-B, and which would have flagged the fan
witness immediately.

---

## 8. A reframing that should be frozen

E5's cross-edge invariant is usually described as an A1 *output* invariant. The fan proves it is more
than that: **it is a check that the field's matching is geometrically consistent with the field's
directions.** It audits A1's **input** — the `CrossFieldEdgeTransition::matching` A1 consumes — as much
as A1's own composition.

That has three consequences worth recording normatively:

1. A witness whose matching is imposed rather than derived from its directions **will** trip the
   invariant, correctly, and must be excluded from any population used to reason about production.
2. The invariant firing is therefore *not* by itself evidence of an A1 code defect. It is evidence that
   one of {input matching, gauge composition, flow classification} is inconsistent — and only the
   decomposition in §7 says which.
3. Because it audits an input, this invariant belongs in A1's **admissibility** checks as well as at
   A2a's point of use. A field whose matching contradicts its geometry is not a field the pipeline
   should accept silently and then fail on three stages later.

---

## 9. Falsifiable predictions

- **P1.** With J1's decomposition, **the fan's single distinct disagreement shows `matching = +1`,
  `g_source = 0`, `g_target = 1`, `signedLift = 0`** — confirming §3 exactly. If instead it shows
  `matching = 0`, my analysis is wrong and the fan *is* an A1 defect; either outcome is decisive.
- **P2.** The sphere's and torus's violations do **not** all show `matching = 0`. If a large fraction
  show `matching ≠ 0`, H-B is confirmed and the investigation moves to field authority.
- **P3.** The distinct-disagreement counts are exactly half the reported violation counts — two-ring 2,
  fan 1, sphere 72, torus 120 — because the census checks both directions. J1 should report distinct
  pairs explicitly so this stops needing inference.
- **P4.** With the fan excluded, the corrected population is **388** violations / **194** distinct
  disagreements across three legitimate witnesses.
- **P5.** The 338 gate, F3 and G5 stay green through J1–J4; they touch no production semantics.
- **P6.** **Q8 stays red at criterion 2.** Do not plan the next TB as a Q8 close. This is the third
  consecutive cycle in which that must be said explicitly.

---

## 10. Corrective measures — series **J**, one Code + Build turn (`M3-CP4c-0-CB6`)

**J0 — binding preconditions.**
Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Code + Build only; compile all eight
standard targets; **execute nothing**. **No production semantics change is authorized** — the mechanism
is still undetermined and §7's table is not yet filled in. Do not weaken T6, Q8, accepted expectations,
the sphere fixture, selector ordering, or Amendments 1–7. Do not retune `kBranchTopologyTolerance`. Do
not enter CP4c-1/2/3. The frozen 338 selector and its three hashes stay unchanged.

**J1 — decompose the published lift (the measure that matters).**
Extend H1's violation record with, per violation: `matching` (the field's own edge matching as A1
consumed it), `rawGauge[sourceFace]`, `rawGauge[targetFace]`, the already-published `signedLift`, and a
boolean for whether the edge is incident to a declared singular vertex. Also report, per witness, the
count of **distinct** `(edge, branch)` disagreements alongside the directed count, and a histogram of
`matching` over violations. Amendment 6 applies: named `*_locus` formatters, printable ASCII, lossless
exact rationals. Non-gating, no credit, written rationale, this measure as owner.

**J2 — quarantine the synthetic-field witness.**
The four-triangle fan under `make_index_one_singularity_field` has a matching that contradicts its
geometry (§3). Either (a) exclude it from the census population and state why in the emitted report, or
(b) keep it and record its expected artifact violation explicitly, so a future reader cannot mistake it
for signal. **Do not "fix" the fan field** — it is a legitimate combinatorial fixture for other
identities. What must change is how the census *classifies* it.

**J3 — matching-versus-geometry consistency check.**
Add a non-gating identity that, per interior edge, unfolds the two triangles about the shared edge,
determines the raw-index correspondence the geometry implies, and compares it with the declared
`matching`. Report agreement rate per witness and every disagreement with both raw indices. This is the
direct, tracing-free test of H-B and it is independent of the flow invariant, so the two cannot fail
together for a shared reason.

**J4 — record matching provenance per witness in the report.**
State explicitly, for each census witness, whether its `matching` is **imposed by the fixture** or
**computed at load** (`finalize_surface_cell_raw_cross_field`), and which code path produced it. H4
asked for this last cycle; the TB-R5 report does not carry it, and its absence is precisely what let
the fan artifact be read as signal.

**J5 — control-plane: stabilize the staged-payload transport.**
Two self-hosted attempts failed at control-payload hash verification because checkout line-ending
normalization altered the staged shell bytes. Add a `.gitattributes` rule (or equivalent) pinning those
payload files to `-text`/LF so the staged bytes survive checkout. This is orchestration hygiene, not
semantics, and it must not trigger any semantic rerun.

**J6 — documentation hygiene: the brief/review name collision.**
The brief is `Architecture_M3_CP4c0_TB_R5_Review_Plan.md` and this review record is
`Architecture_M3_CP4c0_TB_R5_Review_Plan_Independent_Review.md`. J6 restores the convention: briefs are
`…_TB_Rn_Review_Plan.md`, review records are `…_TB_Rn_Review_Plan_Independent_Review.md`. A name that
lies about a document's status is a routing pointer that rots (`LESSONS` §1).

**J7 — successor TB-R6 plan.**
Rerun the unchanged 338 selector in exact order, fresh processes, F6 continue-and-observe; then F3's two
supplementals; then G5, H1 (with J1's decomposition) and J3, all reported and uncredited. Q8 becomes
creditable only at exact package integrity, 338/338 and supplemental 2/2. **State in the plan that Q8 is
expected to remain red (P6)** and that the cycle's deliverable is §7's filled-in decision table.

---

## 11. Risk register

| # | Risk | Mitigation |
|---|---|---|
| 1 | The 390 figure is quoted as "390 production defects" | §3/§5: the fan's 2 are artifacts, and every count is doubled by the two-direction loop. Corrected population is 388 directed / 194 distinct |
| 2 | A production fix is attempted on the strength of lift-0 dominance | **J0 prohibits it.** §5 shows the lift histogram is uninformative about matching — it is a sum of three unobserved terms |
| 3 | The fan artifact is "fixed" by editing the fan field | **J2 forbids it.** The field is a legitimate combinatorial fixture; the census's classification is what is wrong |
| 4 | H-B is adopted because the classifier string says `H-B_OR_OTHER` | The brief itself warns against this, and §4 removes the only fan-based evidence that appeared to bear on it. J1/J3 decide it on data |
| 5 | J1 shows `matching = 0` on the fan, refuting §3 | That is **P1's** alternative branch and is equally decisive — it would make the fan a minimal A1 reproducer, which is a *better* outcome, not a worse one |
| 6 | Q8 red read as stalling | Three hypotheses have been tested and two killed by measurement in two cycles. That is convergence, not drift |

---

## 12. Review record

- **R1 (evidence):** independently verified; all digests match, all three selector hashes recomputed
  locally, census pair counts re-derived from mesh topology. Self-hosted attempts correctly excluded.
- **R2 (census validity):** mechanism **correct**, verified in source — it applies the published lift
  per Amendment 7 and reads the right coordinates.
- **R3 (population validity):** **not homogeneous.** The four-triangle fan's 2 violations are a
  **fixture artifact** proved by arithmetic (`matching(+1) + g_A(0) − g_B(1) = 0`, both `d = −1/2`
  reproduced by hand, and the observed count of exactly 2 predicted by the explanation). Corrected
  population: **388 directed / 194 distinct** over three legitimate witnesses.
- **R4 (hypotheses):** H-A **excluded** (independently re-derived; it was this reviewer's own favoured
  candidate in TB-R4 and the census falsified it). H-C **excluded**, with the corollary that A2a is
  *not* thereby cleared. H-B **undecided**, and the brief's fan-based clause against it is **withdrawn**.
- **R5 (why undecided):** `signedLift` is a sum of three unobserved terms, so no lift histogram can
  decide matching. The tail symmetry is an artifact of the census's own two-direction loop.
- **Contract reframing:** E5's invariant audits the field's **input matching** as much as A1's
  composition; a witness with imposed matching will trip it correctly (§8).
- **Successor:** `M3-CP4c-0-CB6`, measures **J0–J7**, Code + Build, **diagnostic-only**.
- **Stable accounting:** unchanged at **42 events / 14 categories / 28 recurrences**; produced-witness
  debt **5**. The sphere/A1 candidate remains ACTIVE/NON-STABLE with its population corrected and its
  decision table frozen.
- **Mutation statement:** this review executed no runtime, build or benchmark, and changed no product
  source, test source, fixture, selector, or build configuration. Fixtures and test source were read and
  arithmetic performed on their contents; nothing was modified. Its only writes are to durable
  documentation under `.agents/Directional/`.
