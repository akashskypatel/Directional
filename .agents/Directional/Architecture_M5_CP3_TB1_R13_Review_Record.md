# M5-CP3-TB1-R13 Independent Review Record

**Turn:** `M5-CP3-TB1-R13-REV`
**Boundary:** runtime-free Review; no product/test/fixture/selector/build-source mutation
**Reviewed runtime:** `M5-CP3-TB1-R13-EXEC` run/job `35814092644 / 107031820541`
**Reviewed candidate:** artifact/source `10730261023 / 4dfe392d28d60b448e2f32253f7d170221ac57ec`
**Verdict:** **SEMANTIC RED UPHELD / ORDINARY RECOVERY PROVED / FIRST-BRANCH AUTHORITY DEFECT CAUSE-PROVED / EXISTING RP-01 / +0**
**Exact successor:** `M5-CP3-CB16`

## 1. Independent evidence re-open

Review re-opened the immutable R13 result bytes rather than accepting the EXEC summary as proof. Result artifact `10730508643` re-hashes to `0c93f72b3a73752002567dd1a39e19a30ff5c5be352a15cb6e4318f519ab6c01`; its self-manifest hashes to `29cebe48a81c4bd243dc3949f9caf11baed6d991c3e96a34078bd8729bc440a7` and verifies **914/914** non-manifest files. The runtime ledger independently yields semantic+mechanism **10/10**, focused **1/1**, produced **4/6**, selector430 **430/430**, total **445 PASS / 2 RED** across all **447** planned exact-filter processes with one selection and zero skips each. Benchmark count and every prohibited-operation counter are zero; package/source/execution-view postflight is byte/mode exact.

Selector authority was independently re-hashed from the exact Review snapshot: selector430 is `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 is `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. Protected ordinals **191/192/247/408** are PASS.

Review source snapshot run `35816253879` materializes exact branch authority `57ee61865b4c22ad8eb14308ffbc46445b9b06ea`; its source archive verifies **5298/5298** files at SHA-256 `a3e76626818637edc73d3176cce64103e34cb87f0cd81360587f51f5fe07cde3`. GitHub comparison from tested semantic source `4dfe392d28d60b448e2f32253f7d170221ac57ec` to that snapshot reports **no changes under `src/`, `include/`, `tests/`, or `benchmarks/`**, so static inspection is valid evidence about the tested code.

## 2. CB15 ordinary recovery is proved

The new independent identity `M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse` PASSes. Produced rows1/2/3/6 all recover from R12 `InvalidFinalCellState`, and selector ordinal408 recovers from R12 RED to PASS while the protected prefix remains green.

Static inspection agrees with the runtime discriminator. `resolve_periodic_relation_semantic_action(...)` requires exact A3 Forward/Reverse interval roles and reversed carriers, returns the stored action only when the stored cut route already represents semantic Forward, returns the exact inverse only when the reversed stored carrier is semantic Forward, and rejects every other representation. The checked factory and authoritative materializer consume this single deterministic semantic representative; there is no try-both or pass-selected inverse search.

`M5-CP3-TB1-R12-CAND-01` is therefore **CLOSED / RECOVERY PROVED / NON-STABLE / +0**. The R12 storage-canonical-vs-semantic-direction defect remains a historical instance of existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`; CB15 recovers it on fresh runtime evidence.

## 3. Rows4/5: first branch mismatch cause is proved

Both surviving REDs now fail at the same typed first-false predicate:

```text
PeriodicActionFirstBranchMismatch
```

The helper reaches that predicate only after exact occurrence orientation, generator-rotation identity, same-edge source-chart authority, occurrence identity/distinctness and reciprocal scale all pass. It then requires

```text
compose(R, firstFrom.branchRotation) == secondTo.branchRotation
```

where `R` is not an arbitrary chart rotation. `generator_route_for_span(...)` derives `R` from `FieldTransportAtlas::transition_value(...)` in the exact **Forward boundary occurrence carrier face -> Reverse boundary occurrence carrier face** direction, using `acceptedCutBoundaryFaceAuthority[{occurrence, span, carrier}]` for both sides.

The endpoint state's branch component is authored in a different authority domain. `make_periodic_relation_endpoint_state(...)` copies `LocalLatticeState::branchRotation` directly. That local branch was constructed from the **cell corner's selected trace-point face** as

```text
faceBranchRotation[cellCorner.face] + chartUBranch
```

and the endpoint-state constructor receives the A3 occurrence ID only as metadata; it never uses the accepted occurrence carrier face that owns `R`. Thus the helper directly compares a branch expressed at a cell-placement/trace-point face against a transport whose endpoints are occurrence-carrier faces, with no deterministic gauge bridge between them. R13's typed first-branch failure is the runtime falsifier that this implicit equivalence does not hold on the genuine nonzero-Z4 produced subject.

The precise root is therefore **relation endpoint branch authority conflation**: the relation-owned branch component (and the nonzero relation lattice gauge that rotates by that component) is still authored from raw local cell/trace-face branch authority rather than from the endpoint's exact accepted A3 occurrence-carrier branch gauge. This is a further **existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` continuation**, not a new stable event/category.

This conclusion does **not** assert that generator direction is inverted, does not authorize trying `R.inverse()`, and does not infer a free translation. The generator direction is independently fixed by exact A3 occurrence carrier faces. The first false predicate identifies the branch authority seam; later transported-delta and endpoint-map predicates have not executed and are not pre-judged.

`M5-CP3-TB1-R13-CAND-01` is reclassified **CAUSE PROVED / PRODUCT / EXISTING RP-01 CONTINUATION / RELATION ENDPOINT BRANCH AUTHORITY CONFLATION / NON-STABLE / OWNER `M5-CP3-CB16` / +0**. `M5-CP3-TB1-R11-R1-CAND-01` remains OPEN as the broader failed endpoint-gauge recovery chain, now narrowed to this proved branch-authority correction before any later predicate may be adjudicated.

## 4. Non-vacuity and observations

The failure is non-vacuous. The same candidate passes the CB15 semantic-orientation identity, all ordinary produced controls, all 430 selector identities, and every predicate preceding first-branch correspondence on rows4/5. The nonzero source witness still fails closed before relation publication; therefore rows4/5 receive **no** materialization/certificate/tamper credit.

`M5-CP3-TB1-R6-REV-OBS-01` remains **OPEN**. Row4 still does not reach the independent Forward -> Reverse source/A3 comparator or inverted-pair rejection. Path direction in source is not substituted for that runtime observation.

`M5-CP2-TB1-REV-OBS-01` also remains **OPEN**. R13 restores selector430 to 430/430, but frozen §13 requires the first **independently green corrected CP3 pre-publication gate**, not merely a green selector sub-vector inside a 445/447 semantic-RED gate, before selector-publication precommitment. No selector bytes are added or changed here.

## 5. Accounting, promotion and debt

No stable counter change is justified. R13's surviving defect is another manifestation inside the already-open RP-01 endpoint-gauge recovery chain, and the ordinary R12 candidate closes recovery-proved without adding a stable event. Stable accounting remains **50 events / 14 categories / 36 recurrences**.

Produced-witness debt remains **3**: both M5 nonzero-Z4 debts remain open because rows4/5 stop before their discriminators, and the separate closed-complex debt remains M6-owned. Historical relation-owner/container-order and missing-owner debt discharges remain valid.

Accepted runtime remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Candidate `10730261023 / 4dfe392d28d60b448e2f32253f7d170221ac57ec` remains unpromoted. Selector publication remains prohibited.

## 6. Frozen corrective successor

Exactly one successor is authorized: runtime-free Code + Build **`M5-CP3-CB16`** under `Architecture_M5_CP3_CB16_Occurrence_Branch_Gauge_Authority_Correction_Plan.md`.

CB16 must correct only the proved relation-endpoint branch authority seam. For each exact A3 PeriodicCut endpoint it must deterministically re-express the local chart +U branch in the exact accepted occurrence-carrier face gauge before authoring `SurfacePeriodicRelationEndpointState`. The relation-owned coordinate gauge must use that same relation-owned branch component for nonzero `R`, while `R==0` preserves raw cut-domain coordinates exactly. The correction may use exact face-branch/occurrence authority already owned by A3/A4; it may not fit to the partner, search a rotation/translation, try the inverse direction, rewrite endpoints after mismatch, or alter field/fixture/A3/selector authority.

CB16 must add one focused independent branch-authority identity that distinguishes local trace-face branch from accepted occurrence-carrier branch, proves the deterministic bridge and wrong-authority rejection, then compile/package all eight mandatory GMP/GMPXX targets without executing generated Directional runtime. Compile green routes to a fresh artifact-only R14 gate containing that new identity plus the unchanged R13 **447** identities (**448 fresh processes total**) and mandatory Review. The minimum runtime falsifier is that rows4/5 progress beyond `PeriodicActionFirstBranchMismatch`; ordinary rows1/2/3/6 and selector430, especially 191/192/247/408, must remain green.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. |
| Decisive claims independently re-derived | R13 result self-manifest **914/914**, 447-process ledger **445/2**, immutable boundary and selector hashes independently reopened; source comparison proves no tested-code drift; branch/generator authority domains traced independently in source. |
| Non-vacuity checked | New semantic-orientation identity, produced rows1/2/3/6 and selector430 PASS; rows4/5 pass all predicates before exact first-branch correspondence and alone RED. |
| Prior obligations discharged/carried | `R12-CAND-01` CLOSED recovery-proved; `R13-CAND-01` cause-proved existing RP-01; broader R11-R1 endpoint-gauge chain OPEN; R6 direction observation OPEN; CP2 publication observation OPEN; two M5 nonzero debts OPEN. |
| Stable accounting | **50 events / 14 categories / 36 recurrences**, debt **3**; accepted runtime unchanged; R13 candidate unpromoted. |
| New candidates/obligations recorded | No new stable event/category. R13 candidate precisely owned as occurrence-carrier branch-gauge authority conflation; CB16 must correct only that seam and add an independent branch-authority falsifier. |
| ORIENTATION currency line | `M5-CP3-TB1-R13-REV`, 2026-09-23 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated for R13 recovery, branch-authority root, open observations/debts and CB16 successor. |
| CHANGELOG | Root and Directional changelogs updated with Review adjudication and CB16 successor. |
| ROADMAP | M5 CP3 status updated to R13 Review complete / CB16 next. |
| Selector manifest | n/a — no selector added, changed or accepted; publication observation remains open. |
| LESSONS | No new entry; this is a direct new instance of existing RP-01 / authority-domain and relation-gauge lessons. |
| Consolidation under CLEAN_UP_POLICY | R12 report/Review, consumed CB15 plan and consumed R13 EXEC plan folded/indexed into `M5_Consolidated_Record.md`; current R13 report, this Review, one CB16 plan, frozen definitions and selectors retained. |
| Successor frozen | Exactly one successor: `M5-CP3-CB16`, runtime-free Code + Build with explicit branch-authority derivation, prohibitions, focused falsifier and R14 stop rules. |
| Turn boundary held | Yes — Review executed no Directional runtime and changed no product/test/fixture/build/selector byte. |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** with declared selector430/selector427 hashes; no product/test/fixture/build or selector mutation. |
| `STATUS` lifecycle maintained | Entry beacon published; terminal COMPLETE/CB16 beacon reserved for the final repository write. |
| Publication / branch sync | Review documentation must be pushed, temporary control state cleaned, and terminal `STATUS` written last before closeout. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Diagnosis upheld; accounting corrected.** The R13 cause analysis is careful and the carried
obligations are handled correctly. But the stable-accounting disposition inherited from `M5-CP3-TB1-R12-REV` and
restated here is **wrong**: accounting moves to **51 events / 14 categories / 37 recurrences**. Debt remains
**3**.

### V1 — CORRECTION: R12 regressed an accepted ordinal *after* its recovery was proved. That is a new event.

The R12 evidence is explicit in `M5_Consolidated_Record.md` §4.12: selector430 ran **429/430**, "Protected
ordinals 191/192/247 PASS while **accepted ordinal408 REDs**", and "Rows1/2/3/6 and ordinal408 **newly
regress**". Seven REDs reconcile exactly as six produced rows plus ordinal 408.

The durable criterion fires on an ordinal inside the accepted selector prefix transitioning PASS → RED. The only
reason R2-R6 were not separate events is the continuation doctrine I affirmed at `M5-CP3-TB1-R2-REV`, and that
doctrine rests on one stated condition: ordinal 408 **"has not transitioned again, having never returned to PASS
in between."** That condition is false here.

Ordinal 408 was PASS on five consecutive candidates — R7, R8, R9, R10 and R11-R1, each at selector430 **430/430**
— and R7's recovery was not incidental but the headline verdict of that turn, **"R1 `RP-01` RECOVERY PROVED"**.
R12 then drove it RED again from a **different cause**: `InvalidFinalCellState` at
`SurfacePhaseFrontProduct::make(...)`, arising from CB14's exact-A3 endpoint-gauge validation interacting with
relation-insertion canonicalization — not R1's exact-span transport defect.

**The two claims cannot both stand.** If R12 is a continuation of the R1 event, then R7's "recovery proved" was
not a recovery. If R7's recovery was real — and it was, verified at the time across a full gate — then R12 is a
fresh PASS → RED transition of an accepted ordinal and must be recorded. Intervening recovery plus distinct root
cause point the same way.

The usual grounds for non-stable do not apply and have already been ruled out in this project: the candidate
being unpromoted was ruled invalid at `M4-CP-SCALE-TB6-REV` (it would make the rule unfirable), and recovery not
decrementing was fixed as precedent at R7 — a regression that is later repaired stays in the historical ledger.
R13 repairing R12 is exactly that case.

**Corrected accounting: 51 events / 14 categories / 37 recurrences.** `M5-CP3-TB1-R12-CAND-01` is classified
`RP-01`-class representation/gauge authority, an existing category, so categories stay at 14 and recurrences
move 36 → 37. Its disposition changes from `CLOSED / RECOVERY PROVED / NON-STABLE / +0` to **CLOSED / RECOVERY
PROVED / STABLE EVENT RECORDED / `RP-01` recurrence**. Nothing else moves: candidate unpromoted, accepted
authority unchanged, debt 3, and R13's own surviving defect remains correctly non-stable since it exposes no
accepted-prefix transition.

### V2 — what R13 gets right, and it is not little

The reopened direction observation is **honoured, not quietly re-closed**. §60 states plainly that row 4 still
does not reach the Forward → Reverse comparator or inverted-pair rejection, so `M5-CP3-TB1-R6-REV-OBS-01`
remains OPEN. After I reversed that discharge last turn, the easy path was to re-argue it; this Review instead
states what is not yet decidable.

The §3 diagnosis shows comparable restraint: it names relation endpoint branch authority conflation as the
cause, identifies `make_periodic_relation_endpoint_state(...)` copying `LocalLatticeState::branchRotation`
across authority domains while the constructor receives the A3 occurrence ID only as metadata — and then
explicitly declines to assert that generator direction is inverted, declines to authorize trying `R.inverse()`,
and declines to infer a free translation. Refusing three tempting adjacent conclusions is the discipline this
checkpoint learned the expensive way.

Non-vacuity is argued rather than assumed, `M5-CP2-TB1-REV-OBS-01` correctly stays OPEN under §13's requirement
for the first *independently green* pre-publication gate, and manifest coverage is complete.

### V3 — the convergence question now needs a stated trigger, not another attempt

Since the genuine fix at R7, rows 4/5 have consumed R8, R9, R10, R11-R1, R12 and R13 — six further turns, each
finding a *distinct* authority or gauge defect in the same seam: chart admissibility, the family/sign rule
implying zero rotation, raw local-gauge pre-veto, insertion-order pair ordering, storage-canonical versus
semantic direction, and now occurrence-carrier branch gauge. Every individual diagnosis has been sound, and each
failure has moved deeper, which is why I have called this convergence three times.

That reading is now near its limit. Six consecutive *distinct* gauge-authority defects concentrated in one seam
is weak evidence of six independent bugs and stronger evidence of a **missing coherent gauge model** for
same-region nonzero-Z4 promotion — the frozen design specifying what must be true without fixing which authority
domain owns each quantity, so each fix relocates the inconsistency rather than removing it. R12 is corroboration:
a correction that fixed its target *regressed an accepted ordinal*, which is what happens when a change lands in
a seam whose ownership rules are underdetermined.

This project has the right precedent: `M4-CP4-DEFN-R1` and `DEFN-R2` stopped and reconciled definitions rather
than iterating implementations, and both produced durable progress.

**Recorded as `M5-CP3-TB1-R13-REV-OBS-01`: if `M5-CP3-CB16` does not bring produced rows 4 and 5 green, the next
turn must be a definition reconciliation — not `CB17`.** That turn should establish, for the same-region
nonzero-Z4 seam, a single explicit statement of which authority domain owns the branch component, the lattice
gauge, the endpoint states and the canonicalized storage form, and where each is permitted to be read. Stating
the trigger now, while CB16 may still succeed, is what keeps it from becoming a judgement made under fatigue
after the fact.

### V4 — verification limits

Re-derived from repository bytes: selector430's rows and hash, and the R12 evidence recorded in
`M5_Consolidated_Record.md` §§4.12-4.13 (429/430, ordinal 408 RED, 439 PASS / 7 RED, 912/912). R7's ordinal-408
recovery is taken from the durable record of that turn, which this reviewer verified at the time across a full
gate. Accepted as reported: R13 artifact hashes, the 914/914 manifest, gate tallies, and the runtime predicate
outcomes underlying the first-false-predicate analysis.
