# M4-CP-SCALE-TB3-REV — Independent Review Record

**Status:** COMPLETE / CANDIDATE REJECTED / TEST-AUTHORITY PRECONDITION FAILURE / DUPLICATE KNOWN ROOT / NON-STABLE
**Review role:** runtime-free independent re-derivation and corrective planning only
**Exact successor:** `M4-CP-SCALE-CB4`

## 1. Review decision

Review **rejects** candidate package `10375799491` / semantic source `ba6e204d9daef39bfc6c168b659fc1b94f2b5b9b` and closes `M4-CP-SCALE-TB3-EXEC-CAND-01` as **TEST-AUTHORITY PRECONDITION FAILURE / DUPLICATE ROOT / NON-STABLE**.

TB3 did not expose a product comparator defect. The focused S2 identity failed before comparator credit because the CB3 folded-star field still does not satisfy the already-frozen regular-center field-index invariant. On the three-right-angle cone, the center angle is `Theta = 3*pi/2`, so curvature defect is `K = pi/2`. Production `principal_matching` faithfully derives the authored cross-field transport. For a regular center the oriented field cycle must contribute aggregate effort `-4K = -2*pi`; the CB3 witness instead derives aggregate effort `0`, hence center lift

`(sum effort + 4K) / (2*pi) = (0 + 2*pi)/(2*pi) = 1`.

The atlas therefore correctly reports the center as singular and rejects the supplied regular-center precondition with `CycleTransportMismatch`. This is the same semantic root already recorded by `M3-CP4c3-TB7-CAND-02`, `M4-CP-SCALE-TB2-REV`, and `LESSONS.md` 22r: **on a non-flat star, asking production to derive matching/effort is not itself proof that the authored field has regular zero-index transport**.

CB3 also introduced an S2-local fixture defect: face 2 hand-authors a secondary direction opposite to the right-handed tangent complement of its primary (`normal dot (primary x secondary) < 0`), while faces 0/1 are right-handed. Correcting only this handedness is insufficient: independent source-equation reconstruction still gives aggregate cycle effort `0` and center lift `1`. It is therefore a secondary fixture-authority defect inside the same corrective owner, not a distinct stable regression.

## 2. Primary evidence independently re-opened

TB3 run/job `34917763195 / 104219037828` is the frozen artifact-only execution authority. Result artifact `10376198415` has SHA-256 `1dff929087652a6bc6928d378e43d638b93fd6ec0fae83e64ae7d5a2e69bbb86`; diagnostic log artifact `10376118600` has SHA-256 `226d4dd8a54fa3f99b44e4231c4ee8b8177047e1c071b7983b5c3ba4cc8671e8`; the nested evidence archive has SHA-256 `cbbf645a8572d07a1b91caabcc1dbead771eddc06254dcc093ced8271bfd72a2`.

The focused identity `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle` is exactly **1 selected / 0 OK / 0 skipped / exit 1**. The first subject stops at four pre-comparator authority assertions:

- center cycle lift: expected `0`, observed `1`;
- matching-cycle quarter-turn: expected `0`, observed `2`;
- supplied center singularity: expected false, observed true;
- typed atlas construction: expected success, observed `CycleTransportMismatch`.

No Filter/ExactFallback equivalence receives runtime credit.

The frozen failure-path control is valid: selector423 executed **0/423**, all **423/423** rows are explicitly `UNEXECUTED`, owner census is **30 authority-kernel / 277 producer / 75 completion / 41 validation**, selection integrity is true, timeout/crash counts are zero, and package/source/execution-view postflight is byte-exact. `M4-CP-SCALE-TB2-REV-OBS-01` is therefore **DISCHARGED**. Unexecuted rows receive no semantic selector credit.

## 3. Candidate and accepted authority

Candidate package `10375799491` remains **rejected/unpromoted**. Its compile/package facts remain valid build evidence only: compile run `34915185539` was GREEN with `runtimeExecution=false`, provider ZIP SHA-256 `60e84d9b630a8a59574b330e83f80120000973f91a011272a743ce6bdbac5379`, root manifest SHA-256 `2f52b377f0a26bd1d474ed64e41a2fd5096b5ad102c4ff802691dd1969246cfb` verifying 28/28 entries, and source archive SHA-256 `4ec9c7888621fbb0b51cff7173a8ef678c6351a5f3a88988fc0d1b590aee1e2d`.

Accepted runtime authority remains TB1 Review package `10360085644` / semantic source `a359b981f9350139304bc5a654041dfba78609b6` / selector423 **423/423**, selector SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`, first422 SHA-256 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`.

No accepted-green identity regressed. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. The TB3 candidate is non-stable and does not increment the recurrence count.

## 4. Independent source diagnosis

`make_m4_cp_scale_s2_regular_folded_field(...)` in `tests/FieldAlignedCurveNetworkTests.cpp` does use the intended production derivation path: it builds a raw cross field, calls `finalize_cross_field_result(..., includeDiagnostics=true)`, and then independently reconstructs center lift and matching composition. That mechanism is sound as a *measurement path*, but the authored per-face directions do not satisfy the measured invariant.

`make_raw_cross_field(...)` projects and normalizes supplied directions; it does not repair cross handedness or invent the missing topological winding. `finalize_cross_field_result(...)` calls `principal_matching`, which correctly reports the nonzero index encoded by those directions. Therefore weakening atlas validation, suppressing the singularity, or hand-authoring matching/effort would be product/test cheating and is prohibited.

A source-equation reconstruction demonstrates that a bounded test-only regular construction is feasible without product changes. One admissible family gives the three face-primary angles a net cross-field phase winding of `-1` around the center (for example, primary-angle offsets `0, -pi/6, -pi/3` relative to the first face, with every secondary derived as the right-handed tangent complement). Its wrapped `q4` phase differences sum to `-2*pi`, satisfying `sum effort = -4K`; the resulting independent center lift is zero and matching composition is zero for the six retained integer-seed subjects. This is **static planning evidence only**, not Directional runtime proof, and CB4 is not required to hard-code that one formula if an equivalent independently certified construction is used.

## 5. Corrective owner — `M4-CP-SCALE-CB4`

CB4 is bounded **test-authority-only Code + Build**. The semantic edit surface is only `tests/FieldAlignedCurveNetworkTests.cpp`. Its normative target is not a particular angle formula; it is the independently checkable regular-star invariant:

- every face cross is tangent, orthogonal, normalized and consistently right-handed;
- the authored cross field has an independently reconstructed `q4` winding of `-1` around the known cone center, equivalently aggregate production-derived cycle effort `-2*pi` for `K=pi/2`;
- independent center lift is exactly zero and composed matching is zero modulo four;
- production finalization supplies no center singularity;
- typed atlas construction succeeds and a valid arrival frame/branch exists before comparator use;
- the existing six-subject positive/negative/near-boundary/exact-boundary/tamper oracle remains independent and non-vacuously exercises both `Filter` and `ExactFallback`.

CB4 must compile/package only with GMP/GMPXX and `runtimeExecution=false`; selector423 remains byte-identical and S2 remains outside it until runtime + Review. Product/API/CMake/fixture semantics, historical ordinal374, S1, S3/S4/S5, CP4 and unrelated observations are frozen.

## 6. Prior obligations

- `M4-CP-SCALE-TB2-REV-OBS-01` — **DISCHARGED** by TB3's complete 423-row UNEXECUTED failure-path ledger plus immutable postflight.
- `M4-CP-SCALE-TB2-REV-OBS-02` — **CARRIED** to a later dedicated helper-audit owner; the remaining `make_zero_transport_field` callers are not CB4 scope.
- `M4-CP-SCALE-TB1-REV-OBS-01` — **CARRIED**; S1 representative/stress calibration remains required before any numeric gate.
- `M4-CP-SCALE-DEFN-OBS-01..04` — **CARRIED** unchanged: arrival exact fallback, S3 exact-repeat witness, S4 independent incremental oracle/reachability, S5 genus>=2 coverage.
- `M4-CP3-TB1-R1-REV-OBS-01`, `M4-CP3-CB4-REV-OBS-02`, row408 provenance warning, `G4-B002` debt 3 and `G4-B003` debt 2 — **CARRIED** under their existing owners.

## 7. Control-plane process observation

This Review installed its temporary source-snapshot caller before the current-turn GitHub workflow policy had been fully re-read. The caller was path-gated, self-validated successfully against SchemaStore before its snapshot workload, and executed no Directional runtime, so this did not affect semantic evidence. It is nevertheless another **setup-order / `LESSONS.md` 152 control-plane process miss** and receives no normalization by success.

The handoff also referenced `references/turns/REVIEW.md` and `modules/github-connector/MODULE.md`, neither of which exists in the exact repository snapshot. Those stale pointers are removed from the handoff context-load plan; the durable in-repository Review and GitHub workflow policies remain authority.

## 8. Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector423 remains `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`; first422 remains `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`; no selector edit occurs. |
| Decisive claims independently re-derived | Re-opened TB3 raw evidence and candidate source; recomputed cone `K=pi/2`, zero authored cycle effort -> lift 1, production matching behavior, face-2 handedness defect, and a feasible `-2*pi` regular-star winding construction from source equations. |
| Non-vacuity checked | TB3 fails before comparator, so no comparator credit is granted. CB4 is frozen to require atlas/regularity preconditions plus both Filter and ExactFallback, both signs, near-boundary and tamper discrimination. |
| Prior obligations discharged/carried | OBS-01 discharged; OBS-02, S1 calibration, DEFN OBS-01..04, CP3 observations and debt ledgers explicitly carried in §6. |
| Stable accounting | 49 events / 14 categories / 35 recurrences; debt 5; accepted package `10360085644` / selector423 423/423 unchanged. |
| New candidates/obligations recorded | `M4-CP-SCALE-TB3-EXEC-CAND-01` closed duplicate-root/non-stable; no new stable candidate or obligation. Face-2 handedness is folded into the same CB4 corrective owner. |
| ORIENTATION currency line | `M4-CP-SCALE-TB3-REV`, 2026-09-15 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Current authority/open-problem ordering and recurring defect pattern updated; witness table unchanged because no retained production witness changed state. |
| CHANGELOG | Root and Directional changelogs updated with this Review disposition. |
| ROADMAP | CP-SCALE status advanced to TB3 candidate rejection / CB4 next. |
| Selector manifest | n/a — no selector row was added, removed, mutated or accepted. |
| LESSONS | No new lesson; existing 22r (non-flat regular-star cycle consistency) and 152 (setup-order control) are cited. |
| Consolidation under CLEAN_UP_POLICY | TB2 Review record, CB3 plan, TB3 EXEC plan and TB3 EXEC report folded into `M4_Consolidated_Record.md` after their durable facts were preserved; frozen definitions and accepted TB1 report remain retained. |
| Successor frozen | Exactly `M4-CP-SCALE-CB4`; falsifiers and STOP rules are in `Architecture_M4_CP_SCALE_CB4_Code_Build_Plan.md`. |
| Turn boundary held | Yes — runtime-free Review; no product/test/fixture/selector/benchmark/build-source mutation. |
| review_check.py boundary | **GREEN / ALL CHECKS PASSED**: no product/test/fixture/build mutation, no selector mutation, durable markers preserved, selector423 independently matched `4e67e4dc...d89343`. |
| Pushed to origin, branch in sync | Confirmed only at final closeout by the apply/cleanup control plane and final branch-authority check; no commit hash is embedded here. The turn must not close if that confirmation fails. |

---

## 9. Independent verification addendum (reviewing agent)

Runtime-free. **Upheld on substance.** Rejecting candidate `10375799491` is correct, the diagnosis is sound,
§5's target list is the right shape, and establishing feasibility before freezing CB4 is the discipline that
keeps the successor from stopping for want of a construction. Accounting holds at **49 / 14 / 35**, debt **5**.
One classification correction below.

### V1 — the checkable arithmetic confirms

The internal chain was recomputed. With three exact right-angle sectors the centre carries `K = π/2`, so
`−4K = −2π`, matching the stated wrapped-phase sum; substituting into the atlas lift gives
`(Σeffort + 4K) / 2π = (−2π + 2π) / 2π = 0`. Centre lift zero, no supplied singularity, composed matching zero
modulo four — the target state §5 requires.

The §4 hedge is also correct and worth preserving: the specific offset triple `0, −π/6, −π/3` is labelled
**static planning evidence only**, and CB4 is explicitly not required to hard-code it. That matters, because
whether those particular offsets produce the stated effort sum depends on production matching and cycle
conventions that no static reading settles. §5 already requires CB4 to *independently reconstruct* the winding
from the authored field rather than assume the example works, which is the correct guard.

### V2 — CB3's precondition guard worked; that is why this RED is useful

Worth recording, because three consecutive rejections invite the reading that nothing is advancing. TB2 failed
with an opaque atlas refusal. TB3 fails with a named, quantified precondition report — centre lift expected 0
observed 1, matching quarter-turn expected 0 observed 2, supplied singularity expected false observed true,
typed construction expected success observed `CycleTransportMismatch`. That is §8's "prove the precondition
before invoking the comparator" doing exactly its job: the failure now describes itself instead of requiring a
diagnosis turn.

`M4-CP-SCALE-TB2-REV-OBS-01` is likewise genuinely discharged rather than waived — selector423 appears as a
complete 423-row `UNEXECUTED` ledger, so the turn's silence about the accepted prefix is now *recorded* silence.

### V3 — CORRECTION: this is the same invariant, not the same root

The status line reads **DUPLICATE KNOWN ROOT**. That conflates two distinct mechanisms under one label, and the
distinction is load-bearing.

- **TB2** failed inside `make_zero_transport_field` — zero effort declared on a vertex that is not intrinsically
  flat. An *invalid helper precondition*.
- **TB3** does not use that helper at all. Verified directly: `make_m4_cp_scale_s2_regular_folded_field` contains
  no call to `make_zero_transport_field`. It builds through `make_raw_cross_field` and
  `finalize_cross_field_result`, which measure correctly; what fails is that the *authored per-face directions do
  not carry the required winding*. A fixture-construction defect on a **valid measurement path**.

Both violate the same invariant — `Σeffort = −4K` at a cone vertex — but by different causes, and CB3 did not
repeat CB2's mistake. It replaced an invalid helper with a correct production derivation path, which is why the
diagnostics improved from opaque to quantified. Recording this as a plain duplicate invites a later reader to
conclude the turn regressed, when it advanced.

**Consequence for scope.** `M4-CP-SCALE-TB2-REV-OBS-02` — asserting the flatness precondition inside
`make_zero_transport_field` — addresses the **TB2** mechanism and **would not have caught TB3**. It remains worth
doing on its own merits (35 call sites, two historical failures), but the helper-audit owner should not be
briefed as though it prevents this class, and should not be widened to cover authored-winding defects. The
tracker entry is annotated accordingly.

### V4 — obligations and process disclosure

All carried items keep named owners, with `OBS-02` correctly held out of CB4 scope. §7's self-report — a
temporary caller installed before the workflow policy was fully re-read, and a handoff citing two paths absent
from the snapshot — is the right kind of disclosure: process defects recorded by the turn that committed them
cost far less than the same defects found later by someone reconstructing what happened.
