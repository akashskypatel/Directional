# M4-CP-COND DEFN Record

**Turn:** `M4-CP-COND-DEFN`
**Type:** Definition / review-plan only
**Disposition:** COMPLETE / DEFINITIONS FROZEN / CHECKPOINT OPEN
**Runtime:** none
**Product/test/fixture/selector/build mutation:** none
**Exact successor:** `M4-CP-COND-CB1`

## 1. Entering authority re-derived

M4-CP3 remains CLOSED / ACCEPTED. The immutable predecessor is package `10307919492` from semantic source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`, with selector408 **408/408** and LF SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`. Its first403 rows are byte-identical to predecessor selector403, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`.

TB8 Review remains accepted authority at 835/835 fresh PASS, empty accepted RED census and exact package/source/execution-view immutability. Stable accounting is **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. No runtime evidence is reclassified by this definition turn.

## 2. Why CP-COND is a real stage

Amendment 20 already says A0 has a predecessor and that value-changing conditioning is legal only once at the raw boundary. Static source re-derivation confirms the present implementation does not yet embody that contract as one certified product:

- `remesh_from_raw_cross_field(...)` currently constructs source authority and calls raw-field finalization directly;
- `remesh_from_mesh(...)` has an optional legacy `BoundedMeshPreconditioner`, but that utility uses double-valued geometric predicates/thresholds and publishes no certified raw-to-conditioned correspondence;
- `finalize_surface_cell_raw_cross_field` currently contains tolerant branch-norm and rounded-cycle-index acceptance checks (`1e-12`, `1e-6`).

Those facts do not make accepted CP3 invalid: CP3 tested the accepted predecessor semantics. They show why CP-COND must create a **new pre-A0 authority boundary** before broader production claims can be made. The legacy mechanisms are therefore explicitly non-authoritative for CP-COND rather than silently rebranded.

## 3. Frozen product and correspondence

`Architecture_M4_CP_COND_Frozen_Definitions.md` freezes one `ConditionedSourceProduct` single writer, exact raw/conditioned digests, one `ConditioningCertificate`, explicit exact policy identity, and independently checkable vertex/face/field/feature correspondence.

The first implementation deliberately uses a one-to-one face contract. Post-quantization exact-equality vertex merges are allowed only when exact combinatorial safety proves they do not collapse faces, conflate sheets/features or create contradictory incidence. The canonical owner is the minimum raw typed vertex ID. Otherwise conditioning rejects.

This makes correspondence falsifiable without solving a new topology reconstruction problem inside the conditioner.

## 4. Exact authority and permitted operations

Finite binary64 input becomes exact dyadic authority before semantic decisions. The operation list is closed:

1. canonical exactification;
2. one exact dyadic `k / 2^e` lattice quantization under an explicit integer-exponent policy with exact nearest/ties-to-even rounding;
3. exact-equality post-quantization merge with certified ownership/safety;
4. exact sliver **refusal** under an explicit rational policy predicate;
5. unique/canonical discrete `Z4` field reindex proved from exact transport evidence.

Topology-changing sliver repair, nearest-distance identity, branch-vector perturb-until-pass, repeated relaxed retries and any later-stage value changes are not frozen and therefore prohibited.

The refusal-first sliver contract is intentional: Amendment 20 permits repair **or refusal**. Freezing an unproved topology-changing repair would violate the correspondence requirement this checkpoint exists to establish.

## 5. A0/A1 authority correction without A3/A4 change

The old `DESIGN.md` wording that called A0 mollification the single sanitization boundary is superseded by Amendment 20 and this definition. CP-COND is the only value-changing boundary. A0 validates/canonicalizes/publishes authority from the immutable conditioned product; A1 derives transport and may reject, but neither may mutate values.

This is not an A3/A4 amendment. Counts, exact breakpoint identities, parity scheduling, hard-rail shared identity and A4-local family/advance-sign remain exactly as accepted by CP3.

## 6. Witness preconditions and non-vacuity

The frozen matrix refuses to convert named coverage into guaranteed-green tests:

- sliver/anisotropic is gating only when an independent exact rational shape oracle proves the fixture crosses its explicit exact policy; initial outcome is typed refusal;
- high valence is gating only after an integer valence census proves a witness beyond the current max-6 surface; high valence alone is not inadmissibility;
- negative-index singularity is gating only when an independent discrete cycle/index oracle derives the sign rather than reading production output;
- boundary-truncated separatrix is conditional: if A2a reachability cannot be independently proved, it remains an explicit blocker/non-selector rather than fabricated credit;
- deliberately inadmissible field is gating through an independent exact cycle/matching contradiction and typed refusal;
- correspondence integrity is gating only with non-empty authority in each exercised class and one-at-a-time tamper discrimination;
- idempotence requires both a clean Produced witness and a non-empty-operation Produced witness; the second pass must produce identical canonical bytes/digest and zero value changes;
- S6 same-cell perturbation becomes gating only after exact arithmetic proves both raw inputs map to the same lattice cells. Physical-distance metrics stay report-only until a later threshold review.

Deleting/swapping/corrupting correspondence, operation evidence or digests must change the independent validator outcome. This is the explicit non-vacuity condition.

## 7. Prior obligations and stable accounting

No new accepted regression event is created. No selector changes. Stable accounting remains **49 / 14 / 35**, debt **5**.

- `M4-CP3-TB1-R1-REV-OBS-01` — **CARRIED / NON-BLOCKING.** It is not naturally CP-COND coverage; retain the first later independently falsifiable M4 test-authority owner before CP4.
- `M4-CP3-CB4-REV-OBS-02` — **CARRIED / NON-BLOCKING** to the next legitimate row399 touch; CP-COND does not touch row399.
- TB3 row408 provenance warning — **CARRIED** as a historical-claim bound.
- `G4-B002` debt 3 remains M4-CP4 gating; `G4-B003` debt 2 remains M5 gating.

No new tracker candidate is opened. The tolerant raw-input seams found in source are the already-owned CP-COND implementation gap and are frozen directly in the product definition/CB1 plan, not counted as a PASS->RED regression.

## 8. Document/architecture disposition

The definition is recorded in a dedicated frozen CP-COND document and linked from the M4 frozen definitions. `DESIGN.md` is corrected so A0 is no longer described as a second value-changing sanitization owner. ORIENTATION, ROADMAP, TODO, handoff and CHANGELOG are advanced to `M4-CP-COND-CB1` without closing CP-COND.

No selector manifest edit is required because selector bytes/count/accepted authority do not change. No `LESSONS.md` edit is required: this turn instantiates existing exact-boundary, non-vacuity and tolerant-selector/exact-consumer lessons rather than discovering a distinct reusable defect pattern. No consolidation/folding is appropriate because CP-COND remains open and this record/definition/plan are current authority.

## 9. Exact successor

Exactly one successor is authorized: **`M4-CP-COND-CB1`**, Code + Build / compile-only, under `Architecture_M4_CP_COND_CB1_Code_Build_Plan.md`.

CB1 must implement the single-writer product/certificate/validator seam, author the frozen tests and an artifact-only TB plan, compile affected targets through GitHub Actions with GMP/GMPXX, execute no Directional runtime, preserve selector408, and STOP on any requirement to weaken exact/certified authority or alter accepted CP3 semantics.

---

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`; selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; selector408 first403 preserved |
| Decisive claims independently re-derived | PASS — Amendment-20 boundary, current raw entry flow, legacy `BoundedMeshPreconditioner` limitations, tolerant raw-field finalization seam, accepted CP3 predecessor and witness gaps were re-derived from the fresh exact snapshot |
| Non-vacuity checked | PASS — every prospective CP-COND gate has an independent raw precondition and a named tamper/removal discriminator; boundary-truncated reachability must remain blocked/non-selector if it cannot be proved |
| Prior obligations discharged/carried | PASS — multiplicity-2 observation, row399 divergence detector, TB3 provenance bound and five produced-witness debts retained with existing future owners |
| Stable accounting | UNCHANGED — **49 events / 14 categories / 35 recurrences**, debt **5**; no PASS->RED runtime event exists in this runtime-free turn |
| New candidates/obligations recorded | NONE — source seams are the already-owned CP-COND implementation gap, frozen in the definitions/CB1 plan rather than a new stable regression candidate |
| ORIENTATION currency line | PASS — advanced to `M4-CP-COND-DEFN`, CP-COND OPEN, exact next CB1 |
| ORIENTATION §3/§4/§7/§8 | PASS — §3 current checkpoint advanced; §4 unchanged because no witness runtime state changed; §7 reprioritized to CB1; §8 unchanged because no new recurring defect pattern was found |
| CHANGELOG | PASS — definition freeze and successor recorded |
| ROADMAP | PASS — CP-COND DEFN complete, CB1 next; witness gating/precondition language aligned to frozen contract |
| Selector manifest | N/A — no selector identity/count/hash changed |
| LESSONS | N/A — no new reusable pattern; existing exact-boundary/non-vacuity/tolerant-selector lessons govern this definition |
| Consolidation | N/A — CP-COND remains open; current definition/record/plan must remain directly readable |
| Successor frozen | PASS — exactly `M4-CP-COND-CB1`, compile-only |
| Turn boundary held | PASS — documentation/definition only; no product/test/fixture/selector/build/runtime mutation |
| `review_check.py boundary` | PASS — local exact-snapshot working tree reports ALL CHECKS PASSED; independent path hashes additionally prove selector403/selector408 and the first403 prefix exactly because the generic count-only helper has multiple historical 403-row names |
| Pushed to origin, branch in sync | PASS condition of publication — this record is applied only by the exact-base Drive patch workflow; turn closeout must verify the pushed branch/PR CAS before final comment, without embedding a commit hash in this record |
