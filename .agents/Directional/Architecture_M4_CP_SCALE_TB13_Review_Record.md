# M4-CP-SCALE-TB13-REV — independent Review record

**Turn:** `M4-CP-SCALE-TB13-REV`
**Type:** runtime-free independent Review
**Reviewed candidate package:** artifact `10565723112` / exact compiled source `6fe075f7d9397a561fe50b79517b4f714fb9eeef`
**Reviewed runtime:** run/job `35393657851 / 105757517161`
**Reviewed result artifact:** `10566648975`
**Decision:** **APPROVED / PACKAGE + SELECTOR427 PROMOTED / S5 CUMULATIVE CREDIT ACCEPTED / CP-SCALE CLOSED**

## 1. Evidence reviewed independently

Review did not accept the EXEC report as self-proving. It re-opened the immutable CB24 package, TB13 result bytes, selector source, test source and retained genus-two fixture without executing generated Directional runtime.

- GitHub confirms CB24 compile run `35391181281` completed successfully and artifact `10565723112` is `m4-cp-scale-cb24-result-35391181281`, provider ZIP SHA-256 `96e9e900e67777f31fbbf97d05efc44ed8c944d9f2bc031a5826e47602ea7bfa`. Review's downloaded ZIP re-hashes to that exact value.
- The package `SHA256SUMS` verifies **28/28**. Packaged source archive SHA-256 is `3b6b587efadf3b83082b11e5f7a9e1c06b5c8f1ce0671d82db707ffc7fac3bfd`; source metadata names exact compiled source `6fe075f7d9397a561fe50b79517b4f714fb9eeef`; six runtime binaries retain mode `0755`; compile receipts are clean and authoritative link evidence contains both GMPXX and GMP. Package boundary metadata records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`.
- GitHub confirms TB13 run `35393657851` completed successfully at control SHA `6df7419e2e7f910a93e985ebf0693ecc1644c6db`; result artifact `10566648975` has provider SHA-256 `3dd23c08cad9eccd49e61fae4cd14cb735bccc5a00ef23f2192af339aef1f366`, and log artifact `10567158604` has provider SHA-256 `f7987aa4219881b966f324dff939294585fb3992980ebf730d0dbb9889b1cda6`. The downloaded result ZIP re-hashes to the provider value.
- The result artifact's self-excluding manifest verifies **870/870** retained entries; manifest SHA-256 is `94f02091cfcbc672ab05679e91175fdf4a828efef013d935ad067af913c5bb93`.

## 2. Selector and ledger re-derivation

Review independently hashes the packaged selector rather than copying the report:

- selector427: **427 LF rows**, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- first426 bytes: SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, byte-identical to selector426;
- first425: SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- row427: exactly `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`;
- static ownership: **30 authority-kernel / 281 producer / 75 completion / 41 validation**.

The complete execution ledger re-hashes to `2a71510891fd7cc9c4e33483a908ce4505c4bcd315053ea6f72f7055322abfed`; `identity-map.tsv` re-hashes to `69756384783390b6eb5f0324dce006939e4b287f28c2b9313f9f889d42c8ebcf`. Independent parsing proves all **427 unique identities** occur in exact selector order with ordinals 1–427, every row is `PASS`, every row selected exactly one test, every row skipped zero, every process exits zero, and owner totals are **30/281/75/41**. Re-hashing every raw stdout/stderr file against its ledger receipt produces zero mismatches.

The resulting gate is therefore **427/427 PASS**, with zero RED, SKIP, crash, timeout, selection mismatch or unexecuted rows.

## 3. Immutable postflight and boundary audit

Review independently compares pre/post receipts:

- package census before/after: `1e48857b5810aa9520754d37c4d684e27a40eb494a46dd55d71256c2df2ca70c` / identical;
- packaged-source census before/after: `be93504b4d81a3c92c633389bce39c93aaaf968b14296df370bebeaaed75edf4` / identical;
- execution-view census before/after: `d2079a0b45e0f1a9c8df827d6a6fdfd78e1efa88d56310ce3d72be872a3d5b5a` / identical;
- package-manifest verification before/after: `3fab9b68ce79a2140bd963584a8be1b4ff06b3a421d3bb7fcaf481ad46d19721` / identical.

The evidence boundary records `orchestration_failure=false`, `semantic_non_green=false`, `runtime_started=true`, `postflight_complete=true`, `stop_reason=all_green`. Benchmark, configure, build, compile, relink, generated-discovery, repair, package-repair, mode-repair, source/test/fixture/selector mutation and generic mutation counts are all zero.

## 4. S5 non-vacuity and semantic review

Row427 is not a file-existence or reachability-only check. Its source reconstructs independent topology and field/atlas authority around the unchanged production run. Review separately re-censused the committed `genus_two.obj` bytes:

- `V=120`, `E=366`, `F=244`;
- one connected component, zero boundary edges/loops;
- closed two-manifold and orientable;
- `chi = 120 - 366 + 244 = -2`;
- `genus = (2 - chi)/2 = 2`.

The runtime receipt independently reports the same topology and requires independent/production atlas hashes to match at `6035809732721064170`. Production reaches A3 (`a3Produced=true`) with semantic/structural/debug hash `15065394778054153947`, 14 regions, 92 arcs and 76 rotations. The later typed `NotProductionReady` stop at tracing is outside the S5 A3-reachability contract and does not weaken it.

The fixture hashes remain `genus_two.obj = c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, `genus_two.rawfield = 7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, and fixture metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`. No Review runtime was executed.

## 5. Adjudication

Review **PROMOTES package `10565723112` / semantic source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` as current accepted M4 runtime authority under selector427 `427/427`**.

`M4-CP-SCALE-TB12-R10-REV-OBS-01` is **DISCHARGED / PUBLICATION + FRESH CUMULATIVE RUNTIME + INDEPENDENT REVIEW PROVED / NON-STABLE**. Its exact append-only falsifier was satisfied: selector427 preserves selector426 byte-for-byte, appends exactly the reviewed S5 identity, has the precommitted hash/owner census, and passes one fresh immutable 427-row cumulative execution with exact postflight.

S5 therefore receives **CUMULATIVE REQUIRED-GREEN SELECTOR427 CREDIT**. S2 vertex-star, S3, S4 and S5 are cumulative accepted; S1 remains deliberately diagnostic/non-gating. The separately unallocated S2-arrival exact-fallback observation remains open and is not silently converted into gate credit.

No accepted-green regression is observed and no new regression candidate is opened. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**.

The frozen CP-SCALE exit is now satisfied as scoped: all gating S2/S3/S4/S5 identities are cumulatively accepted and S1 is explicitly non-gating. **M4-CP-SCALE is CLOSED / ACCEPTED.** This does not close M4; cumulative `M4-CP4` remains the milestone exit.

## 6. Prior-obligation ledger

Review explicitly discharges or re-carries the obligations that earlier review addenda required not to disappear:

- `M4-CP-SCALE-TB12-R10-REV-OBS-01` — **DISCHARGED** by this Review.
- `M4-CP-SCALE-TB1-REV-OBS-01` — **CARRIED / NON-GATING**. S1 calibration still needs a separately frozen representative/stress domain before any numeric bound can become authority. `M4-CP4-DEFN` must either assign a bounded owner or explicitly re-home it without turning 429/4096 into a gate.
- `M4-CP-SCALE-DEFN-OBS-01` — **CARRIED / ARCHITECTURE PRECONDITION**. S2 arrival lacks a same-seam exact fallback. `M4-CP4-DEFN` must record whether it is an M4-exit conjunct or re-home it with an explicit later owner; filter-only or epsilon authority remains prohibited.
- `M4-CP-SCALE-TB2-REV-OBS-02` — **CARRIED / DEDICATED TEST-AUTHORITY AUDIT OWED**. The `make_zero_transport_field` helper still has an unchecked flatness precondition; `M4-CP4-DEFN` must schedule or explicitly re-home the dedicated audit rather than defer it by phrase again.
- `M4-CP3-TB1-R1-REV-OBS-01` — **CARRIED / M4-CP4 PRE-EXIT OWNER**. Same-region multiplicity-2 must be exercised end-to-end through binder + independent oracle before cumulative M4-CP4 closure.
- `M4-CP3-CB4-REV-OBS-02` — **CARRIED / NEXT LEGITIMATE ROW399 TOUCH**. Path/`sourceFaces` producer-divergence tamper remains owed; CP4-DEFN must not accidentally conflate it with a different control.
- `G4-B002` — **three produced-witness debts remain M4-CP4 gating**. Debt count stays five until actual runtime acceptance.
- `G4-B003` — **two produced-witness debts remain M5-owned**.

Previously discharged `M4-CP-SCALE-DEFN-OBS-02`, `...-OBS-03`, `...-OBS-04`, R8 RP-02 and R4/R9 RP-01 remain closed and are not reopened.

## 7. Engineering-guideline challenge

The simplest sufficient disposition is promotion plus checkpoint closure; no semantic correction is justified. The candidate changed only publication metadata relative to the already-reviewed S5 semantics, the cumulative execution is mechanically exact, and independent source/fixture inspection confirms the appended row remains non-vacuous.

No extra implementation work is folded into this Review. In particular, S1 calibration, S2-arrival design, the zero-transport helper audit, CP3 multiplicity/path observations and M4-CP4 debt work are not rewritten as reasons to reject a gate whose own frozen conjuncts are satisfied. They are carried to explicit owners instead.

## 8. Exact successor

Exact successor is **`M4-CP4-DEFN`**, runtime-free planning under `Architecture_M4_CP4_DEFN_Plan.md`.

That turn freezes the cumulative M4 exit surface from accepted selector427, the three produced-witness `G4-B002` re-proofs, work/bit-width/monotone-progress evidence, and the disposition/owner of every carried M4 observation before any CP4 Code + Build work. It may not create a second schedule writer, mutate accepted selector427, execute Directional runtime, or silently expire an observation.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; exact first426/selector426 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; first425 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` |
| Decisive claims independently re-derived | package/result provider hashes, 28/28 package manifest, 870-entry result manifest, 427-row exact ledger/order/owners/outcomes, raw-process hashes, immutable pre/post censuses, S5 topology/atlas/A3 receipts |
| Non-vacuity checked | row427 derives genuine genus-2 topology from fixture bytes, independently rebuilds atlas authority, requires atlas-hash equality and produced A3; exact append-only prefix would fail on any selector drift |
| Prior obligations discharged/carried | R10 OBS-01 discharged; S1 calibration, S2-arrival, zero-transport helper audit, CP3 multiplicity/path observations, G4-B002 and G4-B003 explicitly carried with owners above |
| Stable accounting | **49 / 14 / 35**, debt **5**; accepted package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427** |
| New candidates/obligations recorded | none; tracker updated to discharge R10 OBS-01 and re-owner carried observations without repricing |
| ORIENTATION currency line | `M4-CP-SCALE-TB13-REV`, 2026-09-18 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3 authority/checkpoint updated; genus-two witness in §4 promoted to cumulative accepted; §7 reordered to M4-CP4-DEFN and complete obligation ledger; §8 has no new pattern, existing RP-01 instance remains recovery-proved |
| CHANGELOG | TB13 Review promotion/CP-SCALE closure entry added |
| ROADMAP | CP-SCALE marked CLOSED/ACCEPTED; exact next M4-CP4-DEFN |
| Selector manifest | selector427 marked accepted current authority; selector426 remains historical exact prefix |
| LESSONS | no new pattern; existing lessons 167, 171 and focused-vs-cumulative publication rule apply |
| Consolidation under CLEAN_UP_POLICY | R10 runtime report (64 lines) and R10 Review record (158 lines) folded into `M4_CP_SCALE_Closure_Record.md`; all earlier CP-SCALE folds remain indexed by `M4_Consolidated_Record.md`; current TB13 report, this Review, closure record, frozen definitions, selectors and one next plan retained |
| Successor frozen | exactly `M4-CP4-DEFN` under `Architecture_M4_CP4_DEFN_Plan.md`; falsifiers/stop rules stated there |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/benchmark/build-source mutation; only static artifact/source inspection and planning/document updates |
| review_check.py boundary | **PASS** on the final prepared Review working tree with selector427 declared hash `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; no product/test/fixture/build or selector mutation detected |
| `STATUS` lifecycle maintained | entry beacon published for this turn with `Started at: 2026-09-18T21:30:03Z`; final COMPLETE beacon naming `M4-CP4-DEFN` is written only after documentation/cleanup and is the final repository mutation |
| Pushed to origin, branch in sync | Review documentation is published to the configured working branch; branch/temporary-state hygiene is re-verified before the final STATUS beacon |

## 9. Publication and hygiene evidence

Review documentation was published by Google Drive patch-transport run/job `35399850316 / 105777049355`. The verified preservation patch SHA-256 was `15fa259555cfd4320400fdb9fe57b457ad8a85d5e6ad813ad9da0f60d07a1b6d`, based at `e0b07852dca535628fa59c13ef670578d8a0a459`, and the reusable applied it at commit `05e697a0bc60c4ecda37aa191315916de387a13f` with `runtimeExecution=false`. Apply result artifact `10569908810` has provider ZIP SHA-256 `216207853f6ce2e36cc3645dc35748bbbbf33ddbc436d973b4990885c2d5412a`; the diagnostic log artifact `10569623797` has provider ZIP SHA-256 `d71243edd7627c11afb6651b31ab2f7ccd4b86e77358773894df1f16b87e95aa`. The workflow required owner-side Drive retirement, and the user-authorized control plane permanently deleted the staged patch after the push was authoritative.

The temporary Review caller was removed before marker cleanup. Mandatory cleanup run/job `35399988903 / 105777441000` completed GREEN and produced cleanup commit `8670d41783fa5fbd3621130e3822dabad2271904`. Cleanup result artifact `10569158778` has provider ZIP SHA-256 `452fc823d3f6d526f7e3268a4ac5eeef49077f652474901d64cdd356c8ab02c7`; it records `runtimeExecution=false`, removal of the Review apply marker and Review source-snapshot marker, deletion of three temporary PR conversation comments and zero inline comments, and zero remaining comments before its observer. Final hygiene verification found exactly the seven durable agent workflows and no connector-trigger, workflow-observation, or turn-payload directory.

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld. CP-SCALE closure is legitimate.** Accounting holds at **49 / 14 / 35**, debt **5**.
One symmetry gap is recorded for `M4-CP4-DEFN`.

### V1 — the third consecutive pre-commitment held

`M4-CP-SCALE-TB12-R10-REV` declared selector427's SHA-256 and owner census before CB24 built it. Verified against
the file: 427 rows, full digest `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` identical to
the pre-committed target, first 426 rows hashing to `41f4d559211375c1…` byte-identical to accepted selector426, and
row 427 exactly `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`.

That is three consecutive publication turns checked against byte-level targets fixed in advance — selector425, 426
and 427. The M4 chain now reads
**373 ⊂ 380 ⊂ 382 ⊂ 394 ⊂ 403 ⊂ 408 ⊂ 422 ⊂ 423 ⊂ 424 ⊂ 425 ⊂ 426 ⊂ 427**, every link verified byte-exact at the
turn that created it, with no accepted prefix shifting across CP1, CP2, CP3, CP-COND or CP-SCALE.

### V2 — the ledger repair landed in full

§6 opens by stating it discharges or re-carries "the obligations that earlier review addenda required not to
disappear", and all four items omitted at R10 are restored with owners: `TB2-REV-OBS-02`,
`M4-CP3-TB1-R1-REV-OBS-01`, `M4-CP3-CB4-REV-OBS-02` and `G4-B003`. Eight items, each with a disposition.

The `DEFN-OBS-01` handling is the part worth naming as precedent. S2-arrival still lacks a same-seam exact
fallback, and rather than deciding by omission whether that blocks M4 exit, the review assigns `M4-CP4-DEFN` to
**record whether it is an M4-exit conjunct**. Converting an unresolved question into an explicit recording
obligation is the right move at a checkpoint boundary — it is what keeps a closed checkpoint from silently
absorbing an open one.

### V3 — the closure follows the checkpoint's own frozen definition

Closing with S1 non-gating is not a convenience. `Architecture_M4_CP_SCALE_Frozen_Definitions.md` §2 states that
S1 "is diagnostic/non-gating until a later review has measurements from representative witnesses and freezes a
justified bound". The review closes on exactly that basis and carries `TB1-REV-OBS-01` with the correct trigger —
calibration is owed before any numeric bound becomes authoritative, not before closure.

§7's refusal to fold S1 calibration, S2-arrival design, the helper audit or the CP3 observations into a promotion
Review is also right, and consistent with how this sequence has handled bounded turns throughout.

### V4 — RECORD FOR `M4-CP4-DEFN`: S1 needs the same determination S2-arrival is getting

CP-SCALE closes with **two** non-gated surfaces, and only one of them receives a CP4-DEFN recording obligation.

The S1 census identity exists —
`M4CPScaleS1.ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral`
(`tests/FieldAlignedCurveNetworkTests.cpp:15767`, calling `diagnose_field_aligned_trace_scale_census`) — but it is
**absent from selector427**, verified by direct search. Its determinism and decision-neutrality are therefore not
re-proved on the accepted package; whatever measurements it published were published against earlier authority.

That is compatible with CP-SCALE's own exit, which makes S1 non-gating. It is not obviously compatible with the
frozen M4 exit clause, which speaks of **S1 measurements being published**. Whether that clause is satisfied by
measurements taken on superseded authority, or requires S1 to be re-published or gated at M4 exit, is precisely
the kind of question that should be decided explicitly rather than inherited.

**Recommend extending the §6 `DEFN-OBS-01` treatment to S1:** `M4-CP4-DEFN` should record whether S1 measurements
must be re-published on accepted authority, or gated, for M4 exit — the same determination it will make for
S2-arrival. Recorded in the tracker so the symmetry is not lost between checkpoints.

### V4 — WITHDRAWN at `M4-CP4-DEFN` review

V4 above is **withdrawn in full by its author.** The frozen M4 exit clause
(`Architecture_M4_DEFN_Frozen_Definitions.md:595`) requires that **S1 measurements are published** — not that S1
be gated or re-proved on the accepted package. They are published: `M4-CP-SCALE-TB1-EXEC` (2026-09-14) records
two-ring `9 / 105 / 107 / 107`, torus `0 / 0 / 0 / 0`, mechanical feature `60 / 1 / 1 / 1` and prescribed sphere
`186 / 429 / 429 / 429`, without threshold interpretation. V4 read a stronger clause than the one frozen and then
found the stronger clause unmet. The recommendation it made is void; no obligation passes to `M4-CP4-CB1`. See
`M4-CP-SCALE-TB13-REV-OBS-01` in the tracker for the full withdrawal. V1–V3 stand unchanged.
