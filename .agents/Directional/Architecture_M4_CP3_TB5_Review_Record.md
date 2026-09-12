# M4-CP3-TB5 Review Record — valid fixture reaches A4; cut-open topology authority is dropped at producer applicability

**Turn:** `M4-CP3-TB5-REV`
**Status:** COMPLETE / CANDIDATE REJECTED / PRODUCT-SEMANTIC A4 AUTHORITY-DOMAIN DEFECT / NON-STABLE
**Canonical turn:** Test + Benchmark Review
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Reviewed semantic source:** `dbcc2f1fe07b611ce7360cd00e31ae4e6cd157c8`
**Reviewed candidate artifact:** `10293750596` / SHA-256 `f95decac9b059bcc7c7b341ecda1e95e8a5b0028211eaa7f902144a196c60831`
**Accepted authority retained:** corrected R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**TB5 execution:** run/job `34680334158 / 103517743371`
**TB5 result artifact:** `10293432317` / SHA-256 `6ac55290bfe17972db9a03c650065485c422955b53898e07ecf73964338615a3`
**TB5 log artifact:** `10293122816` / SHA-256 `6c7d650112a790ac22d8a946a12c4815abdfdea2d0f0150704ffa1a5f1cb613d`

## 1. Verdict

**Reject candidate artifact `10293750596` / selector408 for promotion.** TB5 is a valid artifact-only semantic RED, not an orchestration failure. CB7 successfully repaired the prior fixture-authority composition defect: row408 now reaches the intended A4 producer with exactly the frozen 18 hard-feature source edges and with A1/A2a/A2b/A3 authority retained. The new failure is therefore materially different from TB3/TB4.

`M4-CP3-TB5-REV-CAND-01` is classified:

> **OPEN / PRODUCT-SEMANTIC / A4 CUT-OPEN TOPOLOGY AUTHORITY-DOMAIN + APPLICABILITY DRIFT / NON-STABLE**

The A4 regional producer decides bounded-disk applicability from the **uncut raw source-face submesh**. For the row408 torus that submesh remains `V/E/F = 72/216/144`, `chi=0`, even though the accepted hard-feature cut graph gives a **cut-open disc support** with `V/E/F = 91/234/144`, `chi=1`, one boundary loop. Uniform and periodic producers deliberately defer when accepted A3 authority and hard rails are present; the curved bounded-disk producer then also returns `NotApplicable` because it evaluates the uncut torus Euler characteristic. The aggregate regional dispatcher consequently rejects the hard-feature region as `UnsupportedSourceSheetTopology` before any A3 shared-boundary interval can be materialized.

No accepted-green package lost a required-green identity. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**. `G4-B002` and M4-CP3 remain OPEN.

## 2. TB5 mechanics independently re-derived

The frozen plan required 821 fresh exact-filter processes with fail-fast beginning at row408. Independent review of the raw result, ledger and logs establishes:

- candidate artifact/provider authority is `10293750596` / `f95decac...60831` from source `dbcc2f1f...57c8`;
- immutable preflight completed successfully;
- package root `SHA256SUMS` passed **28/28** before runtime;
- selector403 is exactly **403** LF identities at `c3f509af...70cb7`;
- selector408 is exactly **408** LF identities at `c689c0cd...484`, with its first403 hashing exactly to selector403;
- static owner partition is unchanged at **30 authority-kernel / 262 producer / 75 completion / 41 validation**, row408 producer-owned;
- process 1 selected exactly one identity, row408 `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, from `directional_surface_cell_producer_tests`;
- process 1 exited `1`, classification `RED`, with zero skip/crash/timeout/selection mismatch;
- frozen fail-fast correctly stopped phases B-E after **1/821** processes;
- immutable postflight completed and package/source/execution-view censuses remained byte/mode-identical;
- no configure, compile, relink, generated discovery, benchmark execution, package repair, or source/test/fixture/selector mutation occurred in TB5.

The result ZIP re-hashes independently to `6ac55290...615a3`; the log ZIP re-hashes to `6c7d6501...b613d`.

## 3. Row408 advanced beyond every prior fixture blocker

The raw process reaches the assertion at `tests/FieldAlignedCurveNetworkTests.cpp:15198`:

```text
Expected: SurfaceCellProducerDisposition::Produced
Actual:   SurfaceCellProducerDisposition::Rejected
NotProductionReady/tracing/None
```

Everything before that line passed in the exact same process. In particular row408 already proved:

1. authoritative rail snapshot exists;
2. the effective `HardFeature` source-edge set equals the exact frozen **18-edge** torus cut graph by identity;
3. source topology authority exists;
4. field-aligned network authority exists;
5. `GlobalTopologyPlan` exists;
6. `GlobalConformityBaselinePlan` exists;
7. the retained trace network exists.

This discharges the TB4 fixture-composition/reachability finding. `M4-CP3-TB4-REV-CAND-01` is **CLOSED / RECOVERY PROVED / NON-STABLE** by CB7 + TB5: the valid 18-edge witness now reaches A4. Its package remains historical and rejected; closure of the finding does not promote any package.

The test still does not reach the later receipt/shared-interval assertions, so the CB5 exact A3→A4 pairing cutover remains runtime-unaccepted.

## 4. Exact A4 failure mechanism re-derived from product bytes

The failure is deterministic from the reviewed source plus the already-proved row408 fixture state; no hidden runtime assumption is needed.

### 4.1 Uniform producer intentionally defers

`build_uniform_phase_front_for_faces(...)` returns `NotApplicable` before planar materialization whenever both conditions hold:

- `options.globalConformityBaselinePlan != nullptr`, and
- the active source region contains a hard-feature edge.

Row408 passed both plan/baseline existence and exact 18-edge effective-hard assertions, so this branch is forced. The code comment states that accepted A2b/A3 shared hard rails must be materialized from the exact breakpoint schedule and delegates that cutover to the bounded curved producer.

### 4.2 Periodic-annulus producer intentionally defers

`build_periodic_annulus_phase_front_for_faces(...)` contains the same accepted-plan + hard-feature guard and returns `NotApplicable`. Its comment explicitly says the periodic producer does not publish accepted A3 shared-boundary interval provenance and therefore defers to the bounded curved producer rather than recreating identity from local geometry.

Thus neither earlier producer is a fallback candidate for row408; this is intended control flow.

### 4.3 Curved bounded-disk producer tests the wrong topology domain

`build_curved_bounded_disk_phase_front_for_faces(...)` constructs:

```cpp
const auto incident = edge_faces(faces, activeFaces);
...
const int euler = activeVertices.size() - incident.size() + activeFaces.size();
if (euler != 1) return result;
```

`edge_faces(faces, activeFaces)` is the **uncut source-face incidence**. It does not duplicate hard-rail sides or remove hard-feature adjacency from the Euler support. For row408 the active face set is the full one-region torus, so the exact arithmetic is:

```text
V = 72
E = 216
F = 144
V - E + F = 0
```

The producer therefore returns `NotApplicable` before constructing any authoritative bounded-disk boundary phase.

This is not evidence that the intended A2b/A3 domain is non-disc. The runtime itself emits twice:

```text
interior_barrier_edges_both_sides=18
support_V_int=55
support_E_int=198
support_V_total=72
support_E_total=216
support_F=144
support_chi_reduced=1
support_chi_whole_source_faces=0
whole_minus_reduced_euler=-1
```

That is the exact mismatch: the accepted reduced/cut support is a disc (`chi=1`), while the producer applicability test reverts to whole-source-face Euler (`chi=0`). CB7's independent guard also re-derived the cut-open support as `V/E/F = 91/234/144`, `chi=1`, one 36-edge degree-2 boundary loop.

### 4.4 Aggregate dispatcher converts the mismatch into a typed rejection

`build_uniform_phase_front_state(...)` tries, in order, uniform, periodic-annulus, then curved bounded-disk production for the same region. With all three `NotApplicable`, `firstUnsupportedRegion >= 0`. Because row408 has nonempty `options.hardFeatureEdges`, the dispatcher deliberately forbids legacy fallback and sets:

`SurfacePhaseFrontFailureReason::UnsupportedSourceSheetTopology`.

`publish_phase_front_result(...)` consequently publishes `SurfaceCellProducerDisposition::Rejected`, exactly matching TB5's failing assertion. The top-level pipeline then reports `NotProductionReady/tracing`. The row408 fixture prints `terminalFailureDetailCode`, which is `None`; that omission does not make the nested cause ambiguous because the source-level dispatch is forced by the independently established topology and guard conditions.

## 5. Root cause and architectural boundary

The defect is **not** “Euler should be 1 instead of 0” and must not be repaired by changing one conditional. The same curved producer subsequently derives its boundary from raw one-sided source edges and stores chart UV by global source-vertex index. A nonseparating torus cut has two virtual sides for each hard rail and repeated source-vertex occurrences (the two generators share source vertex `0`). Merely overriding Euler would immediately leave boundary construction and chart occurrence identity in the same wrong uncut domain.

The authority already exists upstream:

- A2b `GlobalTopologyPlan` publishes exact oriented graph-face boundaries and per-region disc certificates;
- A3 `GlobalConformityBaselinePlan` binds exact schedules/breakpoints to those arcs;
- CB5 already made A4 consume those A3 schedules **after** a bounded-disk boundary exists.

The missing operation is to enter A4 through a **cut-open occurrence domain** derived from accepted A2b/A3 authority, rather than infer a physical boundary from the raw source-face submesh.

A product fix that reconstructs cut topology from floating geometry, duplicates raw vertex ids ad hoc, lowers topology checks, filters hard rails downstream, or changes row408 fixture authority would violate the single-writer contract and is prohibited.

## 6. Non-vacuity

TB5 is non-vacuous for the new finding:

- row408 exact-filter selected exactly one test and reached production;
- the effective 18-edge authority assertion passed, so removing CB7's fixture isolation would change the reached path;
- A1/A2a/A2b/A3 products all exist before the failure;
- the failure occurs exactly at the A4 phase-front disposition assertion;
- the reduced-vs-whole Euler diagnostic discriminates the intended cut-open support from the domain A4 actually tests.

TB5 is **not** proof of the exact shared-boundary cutover itself because no produced phase front exists and the receipt/interval assertions remain unreached.

## 7. Candidate and prior-obligation disposition

### `M4-CP3-TB5-REV-CAND-01`

**OPEN / PRODUCT-SEMANTIC / A4 CUT-OPEN TOPOLOGY AUTHORITY-DOMAIN + APPLICABILITY DRIFT / NON-STABLE.**

**Falsifier:** a corrected A4 entry path must consume accepted A2b disc-boundary occurrence authority for the valid 18-edge torus cut graph without reconstructing topology from raw source-face incidence. Row408 must then reach `Produced` with exact A3 shared-boundary intervals. Existing physical-boundary bounded-disk controls must remain green.

**Owner:** `M4-CP3-CB8` under the separately frozen Code + Build plan.

**Prohibited:** treating raw whole-face Euler as the authoritative cut-open region topology; merely forcing `euler=1`; manufacturing duplicated boundary vertices without typed occurrence identity; changing the row408 18-edge witness; weakening hard-rail pairing or A3 schedule checks; editing selector403/408 bytes as part of the product repair.

### Prior obligations

- `M4-CP3-TB4-REV-CAND-01`: **DISCHARGED / CLOSED / RECOVERY PROVED / NON-STABLE** by CB7 + TB5 exact 18-edge runtime precondition and advancement through retained A3 authority to A4.
- `M4-CP3-TB1-R1-REV-OBS-01`: **CARRIED / NON-BLOCKING**. TB5 does not exercise the multiplicity-2 end-to-end oracle path.
- `M4-CP3-CB4-REV-OBS-02`: **CARRIED / NON-BLOCKING**. TB5 does not touch row399's path/`sourceFaces` divergence tamper seam.
- TB3 provenance warning: **CARRIED.** Row408 is a constructed production torus witness; it is not evidence that `InvalidHardRailPairing` was historically observed. CP3 may later claim only that the exact constructed hard-rail path completes without that failure once runtime-proved.

## 7A. Independent verification addendum (reviewing agent)

Runtime-free. The review is **upheld**: rejecting candidate `10293750596` / selector408 is correct, the A4
authority-domain defect is real and correctly classified as product-semantic, and §5's refusal of the
one-conditional fix is the right architectural call. Accepted authority remains the corrected R4 artifact /
selector403 **403/403**; accounting stays **47 / 14 / 33**, debt **5**.

### V1 — the `M4-CP3-TB4-REV` §12 V3 obligation is discharged, and it paid off immediately

Row408 now builds `effectiveHardFeatureEdges` from the actual rail product — iterating `fixture.rails`,
filtering `kind == HardFeature`, walking each rail's vertices including the closed-loop wraparound — and
asserts set equality against the 18 expected edges **by identity**, fatally
(`tests/FieldAlignedCurveNetworkTests.cpp:15160-15182`). That is exactly the requirement, implemented well.

Worth stating because it is the point of the exercise: TB5 advancing *past* that assertion is what converts
CB7's threshold change from a configuration hope into a proven fact. Had the 179/180 suppression not
produced exactly the intended 18-edge authority, the run would have stopped there with a self-describing
message instead of failing later for a reason requiring another diagnosis turn.

### V2 — the published Euler receipt is arithmetically self-consistent

The runtime's twice-emitted receipt was recomputed rather than read:

- whole source faces: `72 − 216 + 144 = 0` — a torus, which is why the producer's `euler != 1` test rejects;
- reduced/cut support: `support_V_int − support_E_int + support_F = 55 − 198 + 144 = 1` — a disc;
- `support_E_int = 198 = 216 − 18`, consistent with `interior_barrier_edges_both_sides=18`;
- `whole_minus_reduced_euler = 0 − 1 = −1`, as published.

All four numbers are mutually consistent. The diagnosis is therefore **observed**, not inferred: the
producer and the accepted support disagree about the domain, and the runtime itself publishes both sides of
that disagreement.

### V3 — this sequence is monotone progress, not thrashing

Recorded because three consecutive rejections invite the opposite reading. The row408 subject moved
strictly forward each turn: TB3 could not reach it at all (no hard-rail authority, `NotApplicable`); TB4
reached production but under an uncontrolled 66-edge composite; TB5 reaches A4 with the intended 18-edge
authority proved at runtime and exposes a genuine product defect. Each rejection removed a distinct
obstruction, and the assertion required at TB4-REV locks the gain so the fixture cannot silently regress.
The four fixture-control turns were the cost of making this seam observable at all.

### V4 — REQUIRED: the frozen exact-torus claim is now positively contradicted, and the file still carried it

`M4-CP3-TB3-REV` §4 stated that it corrected the frozen reachability claim, and this reviewer recorded at
`M4-CP3-TB3-REV` §9 V2 that the claim cited no evidence. Neither updated the normative file:
`Architecture_M4_DEFN_Frozen_Definitions.md:508` still asserted that the exact torus **"already reaches
regional phase-front aggregation and fails at the current post-hoc `InvalidHardRailPairing` seam"**.

TB5 now supplies positive evidence, not merely absence of evidence. With the intended hard-rail authority
proved at runtime, the torus stops at the curved bounded-disk producer's applicability test — `chi_whole=0`
against a required `1` — **before any boundary phase is constructed**. It therefore never reaches hard-rail
pairing, and the frozen claim is false in both of its parts.

That row is corrected in this turn, striking the false reachability statement, citing runs `34671972132`
and `34680334158`, and leaving the semantic obligation intact and unweakened: CP3 still owes a production
torus witness that carries shared hard-rail authority and completes without `InvalidHardRailPairing`, and
may not report it as reproducing a historically observed failure.

The process lesson is small and worth carrying: a review that finds a normative claim false must edit the
normative file, not only record the correction in its own record. `REVIEW_TURN_POLICY.md` §3.2 lists
closure records but does not name the frozen definitions; it is amended accordingly.

### V5 — obligations

`TB4-REV-CAND-01` is correctly discharged; `TB1-R1-REV-OBS-01` and `CB4-REV-OBS-02` are carried with honest
statements that TB5 exercised neither; the TB3 provenance warning is carried and correctly bounds what CP3
closure may claim.

## 8. Package / selector / milestone decision

- Candidate artifact `10293750596`: **REJECTED FOR PROMOTION**.
- Candidate selector408 `c689c0cd...484`: **UNPROMOTED**.
- Accepted runtime authority remains R4 artifact `10289601000` / selector403 `c3f509af...70cb7` at **403/403**.
- Stable accounting remains **47 / 14 / 33**, debt **5**.
- `G4-B002`: OPEN.
- M4-CP3: OPEN.
- No closure or accepted-selector expansion is licensed by this Review.

## 9. Exact successor

`M4-CP3-CB8` is frozen by `Architecture_M4_CP3_CB8_Code_Build_Plan.md`.

Its first action is a runtime-free pre-mutation proof that the row408 failure is exactly the three-producer dispatch described above and that an occurrence-keyed cut-open A2b/A3 boundary can be bound without inventing a second topology authority. If that proof fails, CB8 stops before mutation and returns to Review/definition work. Only after the guard passes may CB8 change the minimum A4 product surface needed to consume that authority. No runtime belongs to CB8.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`; selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; first403 independently re-hashes exactly to selector403 |
| Decisive claims independently re-derived | PASS — result/log ZIP digests, 1-process ledger/fail-fast, selector counts/hashes, immutable censuses, row408 assertion order, and exact uniform→periodic→curved→aggregate rejection path were recomputed from raw evidence/source bytes |
| Non-vacuity checked | PASS — exact 18-edge effective authority and A1/A2a/A2b/A3 retention all pass before A4 rejection; reduced `chi=1` versus uncut `chi=0` distinguishes the defective authority-domain choice |
| Prior obligations discharged/carried | TB4 candidate CLOSED recovery-proved; `TB1-R1-REV-OBS-01`, `CB4-REV-OBS-02`, and TB3 provenance warning carried explicitly |
| Stable accounting | UNCHANGED — 47 events / 14 categories / 33 recurrences; debt 5; accepted R4 artifact `10289601000` + selector403 403/403 |
| New candidates/obligations recorded | `M4-CP3-TB5-REV-CAND-01` recorded with root cause, falsifier, owner and prohibitions |
| ORIENTATION currency line | UPDATED to `M4-CP3-TB5-REV`, 2026-09-12 |
| ORIENTATION §3 / §4 / §7 / §8 | UPDATED — valid row408 reaches A4; torus witness, open blocker and recurring authority-domain instance reconciled; superseded TB4 fixture warning marked discharged |
| CHANGELOG | UPDATED with TB5 EXEC + Review outcome |
| ROADMAP | UPDATED — CP3 remains open; CB8 is exact next product correction |
| Selector manifest | UPDATED — selector408 remains byte-frozen/unpromoted and now has TB5 1/821 RED review disposition |
| LESSONS | No new number — this is a concrete instance of the existing single-authority/semantic-domain rule; no duplicate lesson added |
| Consolidation under CLEAN_UP_POLICY | TB5 durable facts folded into `M4_Consolidated_Record.md`; superseded TB4 review, CB7 plan/compile record and consumed TB5 plan are indexed there and folded from current head; current review + exactly one CB8 plan retained |
| Successor frozen | PASS — exactly `M4-CP3-CB8`, with pre-mutation falsifiers in `Architecture_M4_CP3_CB8_Code_Build_Plan.md` |
| Turn boundary held | PASS — Review/Plan runtime-free; no product/test/fixture/selector/benchmark/build semantic mutation |
| review_check.py boundary | PASS — `ALL CHECKS PASSED` on the staged documentation-only review delta; selector403/408 hashes match baseline and no code/test/build/selector path is modified |
| Pushed to origin, branch in sync | PASS criterion — review patch is published only through the branch-checked Drive apply path; final branch head and temporary-state cleanup are re-read after publication, with no unpushed local repository state in this Web session |
