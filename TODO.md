## Current — `M6-CP2-CB1-VERIFIER-REV` / RA-28b / exact next `M6-CP2-CB1-VERIFIER-R1` (2026-10-05)

- [x] Verify the stop report (all five points accurate); HEAD source == `3f40f04a`.
- [x] Root cause: RA-28a §7 over-tightened RA-26 §5(iii) (review-agent error).
- [x] Reject an A5 `selectedFace ∈ bindings` invariant and a class-wide optimizer check. Authoritative projection is confined to the seed scope, and that static property is certified by the completion guard, the verifier and final validation.
- [x] RA-28b: retain the optimizer self-check as non-authoritative; re-specify identity 12 as a confinement falsifier; note for DEFN-R5; lesson 202.
- [ ] **Exact next `M6-CP2-CB1-VERIFIER-R1`** (compile/package; no optimizer change).
- [ ] TB1 **491** → mandatory Review.

## Superseded stop — `M6-CP2-CB1-VERIFIER` RA-28a §7 (adjudicated by `M6-CP2-CB1-VERIFIER-REV`)

- [x] Re-audit the RA-28a §7 representative-face precondition on exact semantic source `8bc1f52b...`.
- [x] Establish that A5 selects `placement.selectedFace` independently of edge/vertex `cornerWedgeBindings`, phase-front closure does not require source-face identity, and A7 `sourceCharts` are binding-derived only.
- [x] Stop before applying the exploratory verifier WIP, compiling, or starting TB1, as RA-28a requires.
- [ ] Runtime-free Review must adjudicate the missing invariant and freeze a bounded correction/contract amendment.
- [ ] Successor is `UNKNOWN` until Review authority freezes it; 491-process TB1 remains held.

## Current — `M6-CP2-DEFN-REV` ACCEPTED with RA-28a / exact next `M6-CP2-CB1-VERIFIER` (2026-10-05)

- [x] Review the CP2 Definition (D1–D6, RA-26 §5(iii)) against frozen §6/§10 and exact source.
- [x] RA-28a:
  - exact-once/forest/spanning/cycle checks; A6 → A5 field table; A5 wedge/support vs A0;
  - dependency gating; drop two predicate-less codes; `VerifiedSurfaceProducts`;
  - `retained`-gated optimizer check; tamper precision; A0 tuple and failure string.
- [x] Release the CB1 plan; lesson 201.
- [ ] **Exact next `M6-CP2-CB1-VERIFIER`** (compile/package only; 12 identities; RA-28a stops).
- [ ] TB1 **491** → mandatory Review → (later) `M6-DEFN-R5` → CP3.

## Current — `M6-CP2-DEFN` COMPLETE / mandatory Definition Review next (2026-10-05)

- [x] Freeze D1 record-view negative seam and typed semantic finding identity.
- [x] Classify C4 accepted-defensive; verifier manifoldness owns the executed pinched-topology falsifier.
- [x] Freeze three mutant-killing wedge tampers without changing identity29.
- [x] Integrate A8 after A7 / before adapter projection; resolve RA-26 §5(iii) to class-wide optimizer chart membership.
- [x] Freeze CP2 focused-12 and gate **30 + 12 + 449 = 491**; standard eight GMP targets.
- [ ] **Exact next `M6-CP2-DEFN-REV`**. `M6-CP2-CB1-VERIFIER` remains held until Review.
- [ ] `M6-DEFN-R5` follows CP2; `G4-B002` debt remains 1.

## Superseded historical snapshots

## Current — `M6-CP1-CLOSE-REV` ACCEPTED / CP1 CLOSED / exact next `M6-CP2-DEFN` (2026-10-05)

- [x] Re-confirm no semantic-source advance from promoted `3f40f04a`.
- [x] Complete RA-26 current-HEAD provenance-consumer census: zero authority-deciding consumers.
- [x] Adjudicate all six frozen CP1 exit items PASS with focused-30 ordinals and source citations.
- [x] Classify C2/C4/RA-27a static-only branches with later owners; keep `G4-B002` open.
- [x] Close M6 CP1 mechanism-only; stable accounting remains **60 / 16 / 44**, debt 1.
- [x] Freeze `Architecture_M6_CP2_Definition_Plan.md`.
- [ ] **Exact next `M6-CP2-DEFN`** (runtime-free): freeze `SurfaceProductVerifier`, certificate-chain binding, RA-26 §5(iii), C4 witness, and appended wedge-rule tampers.
- [ ] `M6-DEFN-R5` follows CP2 and retains CP3-entry obligations.

## Superseded historical snapshots

## Current — `M6-CP1-TB12-CLOSE-R1-REV` + review-agent addendum / RA-27b / exact next `M6-CP1-CLOSE-REV` (2026-10-05)

- [x] Re-derive R1: 497/497, frozen-order ledgers, 479/479; all 479 raw-log hashes match; candidate `3f40f04a` == HEAD.
- [x] Confirm the RA-27a wedge rule (exact; fail-closed on malformed membership input), the C4 name and identity 29 on a consistent chain.
- [x] Record overclaims (runtime proves one wedge-rule dimension) and unowned defensive branches (C4, C2 empty-front) → RA-27b; lesson 200.
- [x] Amend the close plan: verbatim exit items, defensive-branch classification, `G4-B002` stays open, successor `M6-CP2-DEFN`.
- [ ] **Exact next `M6-CP1-CLOSE-REV`** (runtime-free).
- [ ] If CP1 closes → `M6-CP2-DEFN` (RA-27b §4), then CP2 CBs, then `M6-DEFN-R5` → CP3.

## Current — `M6-CP1-TB12-CLOSE-R1-REV` ACCEPTED / 479/479 promoted / exact next CP1 close Review (2026-10-05)

- [x] Independently re-derived R1 result manifest **497/497**, focused30 **30/30**, selector449 **449/449**, exact-one, zero skips, benchmark 0 and immutable postflight.
- [x] Accepted RA-27a exact wedge graph and consistent-chain identity29 falsifier; C4 name correction verified.
- [x] Closed `M6-CP1-TB12-CLOSE-EXEC-CAND-01` recovery-proved/non-stable; stable accounting remains **60 / 16 / 44**, debt 1.
- [x] Promoted `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` as current reviewed M6 runtime authority.
- [ ] **Exact next:** runtime-free `M6-CP1-CLOSE-REV` under `Architecture_M6_CP1_Close_Review_Plan.md`; CP1 remains ACTIVE until all six exit items and RA-26 current-HEAD audit pass.
- [ ] Later-owner obligations remain carried: RA-27a §6 / OBS-01 / OBS-02 / RA-26 §5 to M6-CP2 / DEFN-R5 / CP3 as frozen.

## Current — `M6-CP1-TB12-CLOSE-R1-EXEC` COMPLETE / 479/479 GREEN / mandatory R1 Review next (2026-10-05)

- [x] Immutable candidate `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`; exact **30 + 449 = 479** process gate.
- [x] Focused **30/30** + selector449 **449/449** = **479/479 PASS**; exact-one selection, zero skips, benchmark 0.
- [x] Identity29 recovery is GREEN; identity30 remains GREEN; selector449 remains fully GREEN.
- [x] Result self-manifest **497/497**, immutable package/execution-view postflight, no retry/repair/rebuild/mutation.
- [x] +0 new regression events/candidates; stable accounting remains **60 / 16 / 44**, debt 1.
- [ ] **Exact next:** mandatory runtime-free `M6-CP1-TB12-CLOSE-R1-REV`. Candidate remains unpromoted until Review; `M6-CP1-CLOSE-REV` remains held.

## Current — `M6-CP1-CB12-CLOSE-R2` COMPLETE / compile-package GREEN / exact next R1 EXEC (2026-10-05)

- [x] RA-27a exact A7 wedge sheet-graph connectivity; site `cross-sheet:wedge`.
- [x] C4 diagnostic name corrected to `QuotientClosedComplexStripContinuationMismatch`.
- [x] Identity29 recovered without stale A6 reuse: baseline accepts; wedge-only tamper; A5 republish; A6 re-produce/succeed; A7 rejects at wedge site.
- [x] Focused30 / selector449 / routing449 frozen bytes unchanged.
- [x] Compile/package GREEN: `11330703256 / 3f40f04a...`, run/job `37278068286 / 111659540374`, eight GMP/GMPXX targets, manifest 28/28, `runtimeExecution=false`.
- [ ] **Exact next:** `M6-CP1-TB12-CLOSE-R1-EXEC`, immutable **479** process gate, then mandatory `M6-CP1-TB12-CLOSE-R1-REV`.
- [ ] Stable accounting remains **60 / 16 / 44**, debt 1; candidate remains unpromoted until Review.

## Current — `M6-CP1-TB12-CLOSE-REV` + review-agent addendum / RA-27a / exact next `M6-CP1-CB12-CLOSE-R2` (2026-10-05)

- [x] Re-derive TB12: digests `da42bf2a`/`70880747`, 979/979, ledgers in frozen order, 478/479, ordinal 29 pre-tamper RED; candidate source == HEAD.
- [x] Review C2–C4. C2/C3 accepted; C4 fail-closed accepted but its name lacks the `Quotient` prefix and it has no executed falsifier.
- [x] Correct the CAND-01 cause: the fixture has no disjoint-sheet relation. Withdraw RA-27 §2–§3.
- [x] Find the reachable wedge proxy (`:6884-6895`) → RA-27a §2; the stale-A6 negative → RA-27a §5; OBS-01/02; lesson 199.
- [ ] **Exact next `M6-CP1-CB12-CLOSE-R2`**: wedge rule, C4 name, identity 29 consistent-chain witness; compile/package only.
- [ ] TB12-R1 **479**, then mandatory Review, then `M6-CP1-CLOSE-REV`.

## Current — `M6-CP1-TB12-CLOSE-REV` COMPLETE / exact next `M6-CP1-CB12-CLOSE-R2` (2026-10-05)

- [x] Re-derived TB12 mechanical evidence: 478/479; identity29 sole RED; no tamper reached.
- [x] Adjudicated CAND-01 as false rejection / test-fixture witness defect / non-stable. Production-selection defect not established.
- [x] RA-27 freezes test-only witness recovery; production C1 remains unchanged and candidate unpromoted.
- [ ] **Exact next:** `M6-CP1-CB12-CLOSE-R2` test-authority recovery + compile/package only.
- [ ] Then `M6-CP1-TB12-CLOSE-R1-EXEC` at unchanged **479**, mandatory R1 Review, then CP1 close if accepted.
- [ ] Stable accounting remains **60 / 16 / 44**, debt 1.

## Current — `M6-CP1-TB12-CLOSE-EXEC` COMPLETE / 478/479 / mandatory Review next (2026-10-05)

- [x] Immutable candidate `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`; exact 479-process gate.
- [x] Focused **29/30** + selector449 **449/449** = **478/479**, exact-one, zero skips, benchmark 0, immutable postflight, 979/979 result manifest.
- [x] CAND-01: non-stable / Review-owned; identity29 lacks a selected cross-sheet witness and fails before its C1 tamper. Stable accounting **60 / 16 / 44**, debt 1.
- [ ] **Exact next:** runtime-free `M6-CP1-TB12-CLOSE-REV`; `M6-CP1-CLOSE-REV` remains held.

## Current — `M6-CP1-CB12-CLOSE-R1` COMPLETE / exact next `M6-CP1-TB12-CLOSE-EXEC` (2026-10-05)

- [x] C1 exact A7 cross-sheet transition endpoint-sheet certification.
- [x] C2 distinct A5 missing-front / invalid-source / unavailable-chart diagnostics, including empty edges.
- [x] C3 `consumedInternalIsolationSeams` projected from A5 `validatedIsolationCertificateCount`; identity24 updated.
- [x] C4 RA-25 ambiguity now fails closed with `ClosedComplexStripContinuationMismatch`.
- [x] Identities 29/30 and focused-30 (`1e815443...a1d6`), exact focused-28 prefix.
- [x] C5 discharged by RA-26 §3; no optimizer/final-validator change.
- [x] Compile/package GREEN: `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`, run/job `37259524323 / 111603703243`, 28/28, GMP/GMPXX, `runtimeExecution=false`.
- [ ] **Exact next:** `M6-CP1-TB12-CLOSE-EXEC`, focused30 + selector449 = **479**, then mandatory Review and `M6-CP1-CLOSE-REV`.

## Current — `M6-CP1-CB12-CLOSE-REV` / RA-26 / exact next `M6-CP1-CB12-CLOSE-R1` (2026-10-05)

- [x] Confirm HEAD source == `8dd95821` (fetched by SHA after the squash); CB12 made no source change.
- [x] Adjudicate C5. `SurfaceMeshOptimizer.cpp:3015-3031` is not a provenance consumer and is test-only → OBS-01 (M8-CP2). Its "anchor-assuming" label is withdrawn.
- [x] Audit all 12 optimizer and validation provenance-face sites. No authority-deciding consumer exists. The optimizer energy/gradient and the final-validation field-metric fallback are reference-selecting → RA-26 §5 → `M6-DEFN-R5` / `M6-CP3`.
- [x] RA-26; CB12 plan header block; lesson 198.
- [ ] **Exact next `M6-CP1-CB12-CLOSE-R1`**: C1–C4; identities 29/30; focused-30; compile/package only; no optimizer change.
- [ ] TB12 **479**, then mandatory Review, then `M6-CP1-CLOSE-REV`, which also re-checks RA-26 §3.
- [ ] `M6-DEFN-R5`: add RA-26 §5 items (i)–(iv).

## Superseded stop — M6-CP1-CB12-CLOSE (adjudicated by `M6-CP1-CB12-CLOSE-REV`)

- C5 audit found **BLOCKER**: `SurfaceMeshOptimizer.cpp:3015-3031` picks the first incident source face, derives one component/sheet scope, and breaks; this is anchor-assuming.
- RA-22b / RA-25 / CB12 require Review; do not repair it inside CB12.
- C1-C4, identities 29/30, compile/package and TB12 were not started.
- Reviewed runtime remains 477/477; successor UNKNOWN pending Review.

## Current — `M6-CP1-TB11-G4-R1-REV` + review-agent addendum / RA-25 / exact next `M6-CP1-CB12-CLOSE` (2026-10-05)

- [x] Re-derive TB11-R1: digest `1082edce`, 973/973 manifest, focused-28 and selector449 ledgers in frozen order (477/477), ordinals 25/28 OK; HEAD == `8dd95821`.
- [x] Confirm the RA-24 production change (bounded) and the identity 25/28 oracles. M1: the continuation skips silently on ambiguity → RA-25 fail-closed.
- [x] Re-route the successor to close-out CB12 (the carried obligations need code). Write the CB12 plan; pre-audit `project_surface_cell_vertex_chart_authority` as class-wide. Lesson 197.
- [ ] **Exact next `M6-CP1-CB12-CLOSE`**: C1-C5; identities 29/30; compile/package only.
- [ ] TB12 **479**, then mandatory Review, then `M6-CP1-CLOSE-REV`.

## Superseded — `M6-CP1-TB11-G4-R1-REV` pre-addendum checklist
## Current — `M6-CP1-TB11-G4-R1-REV` ACCEPTED / candidate promoted / exact next `M6-CP1-CLOSE-REV` (2026-10-04)

- [x] Independently re-derive candidate **28/28**, runtime **973/973**, focused28 **28/28**, selector449 **449/449**, aggregate **477/477**, exact-one, zero skips, benchmark 0 and immutable postflight.
- [x] Discharge RA-24/CAND-02: edge-loop strip closure is bounded to the A6 view builder; identity28 independently proves produced-torus non-vacuity and hard-feature tamper rejection.
- [x] Discharge RA-21c/RA-21d/CAND-01: per-occurrence arrangement witnesses and typed relation authority are exact; equality is retained for Ordinary non-isolation relations and relaxed only at certified seams.
- [x] Promote `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` as current reviewed M6 runtime authority. Stable accounting remains **60 / 16 / 44**, debt 1.
- [ ] **Exact next `M6-CP1-CLOSE-REV`:** runtime-free close Review; complete A7 cross-sheet proxy, remaining provenance-face consumer audit, merged diagnostic-name closeout and `consumedInternalIsolationSeams` counter-source audit before any CP1 closure claim.

## Current — `M6-CP1-TB11-G4-R1-EXEC` COMPLETE / 477/477 GREEN / exact next `M6-CP1-TB11-G4-R1-REV` (2026-10-04)

- [x] Consume immutable R1 candidate `11316716869 / 8dd958217d...`; verify 28/28 package manifest, exact source, GMP/GMPXX compile receipts and frozen gate authorities.
- [x] Execute focused28 + selector449 as **477** fresh exact-filter processes: **28/28 + 449/449 = 477/477 PASS**, exact-one selection, zero skips, benchmark 0.
- [x] Confirm focused ordinals 25 and 28 both PASS; package/source/execution-view postflight immutable; no repair or retry after runtime start.
- [x] Record +0 new regression events/candidates; stable accounting remains **60 / 16 / 44**, debt 1.
- [ ] Next: mandatory runtime-free `M6-CP1-TB11-G4-R1-REV` independently verifies R1 recovery and adjudicates promotion. Do not begin CP1 close first.

## Current — `M6-CP1-CB11-G4-R1` COMPLETE / compile-package GREEN / exact next `M6-CP1-TB11-G4-R1-EXEC` (2026-10-04)

- [x] Implement RA-24 edge-loop strip closure as the sole production change.
- [x] Recover identity25 under RA-21d: exact chain/node equality only for Ordinary non-isolation relations; typed barrier seams remain per-side.
- [x] Recover identity28 on the produced torus with independent edge-loop partition/candidate checks, non-vacuous `ClosedLoop`, and hard-feature tamper rejection.
- [x] Apply exact two-file patch as semantic source `8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`; owner-side Drive cleanup complete.
- [x] Mandatory GMP/GMPXX compile/package run/job `37238936105 / 111543578349`: all eight targets GREEN; artifact `11316716869`; 28/28 manifest; clean receipts; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB11-G4-R1-EXEC`:** immutable focused28 + selector449 = **477** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB11-G4-R1-REV`; only then may `M6-CP1-CLOSE-REV` proceed.

## Current — `M6-CP1-TB11-G4-REV` + review-agent addendum / RA-24 / RA-21d / exact next `M6-CP1-CB11-G4-R1` (2026-10-04)

- [x] Re-derive TB11: digest `7de4a320`, 973/973 manifest; RED focused 25 and 28; selector449 449/449. Ordinal 28's log shows an empty candidate vector.
- [x] F2 overturned. R4 D3 rule-7 quad-opposite strips are rung sets, which the path-degree classifier always skips, so there are zero candidates on any closed complex and RA-23's synthetic torus would also fail. RA-24: edge-loop (strand) closure.
- [x] F1 confirmed; RA-21d keeps Ordinary non-isolation equality.
- [x] Re-scope the R1 plan (R1-0 production strip relation only; oracles). Lesson 196.
- [ ] **Exact next `M6-CP1-CB11-G4-R1`**: compile/package only.
- [ ] TB11-R1 **477**, then mandatory Review, then `M6-CP1-CLOSE-REV`.

## Superseded — `M6-CP1-TB11-G4-REV` pre-addendum checklist
## Current — `M6-CP1-TB11-G4-REV` COMPLETE / CB11 candidate rejected / exact next `M6-CP1-CB11-G4-R1` (2026-10-04)

- [x] Independently re-derive immutable TB11 evidence: candidate **28/28**, result **973/973**, focused **26/28**, selector449 **449/449**, aggregate **475/477**, exact-one, zero skips, benchmark 0, immutable postflight.
- [x] Adjudicate ordinal25 as a **false rejection / test-oracle + definition defect**: RA-21b incorrectly required quotient-equivalent cut occurrences to share physical arrangement nodes/chains. Freeze RA-21c per-occurrence/per-side subdivision witness semantics.
- [x] Adjudicate ordinal28 as a **definition/fixture-witness gap**, not a demonstrated extractor regression: the old arrangement `(family,strand)` witness never proved non-vacuity under quotient opposite-edge strip closure. Freeze RA-23.
- [x] Close `M6-CP1-TB11-G4-EXEC-CAND-01` as false-rejection/non-stable; reclassify `...-CAND-02` as non-stable definition-witness recovery work. Stable accounting remains **60 / 16 / 44**, debt **1**.
- [x] Publish `Architecture_M6_CP1_TB11_G4_Review_Record.md` and bounded `Architecture_M6_CP1_CB11_G4_R1_Recovery_Code_Build_Plan.md`. Candidate `11308472138 / 582da20a...` stays unpromoted; reviewed runtime remains `11299078582 / 96b456f9...`.
- [ ] **Exact next `M6-CP1-CB11-G4-R1`:** test-authority recovery only. Implement RA-21c in ordinal25 and RA-23 in ordinal28; preserve focused28/selector449 bytes and production A5/A6 semantics. Any semantic production change is STOP -> Review.
- [ ] Compile-green R1 -> immutable `M6-CP1-TB11-G4-R1-EXEC`, unchanged **28+449=477** -> mandatory `M6-CP1-TB11-G4-R1-REV`.
- [ ] `M6-CP1-CLOSE-REV` remains held until R1 Review succeeds.

## Completed predecessor — `M6-CP1-CB11-G4` compile-package GREEN / TB11 executed (2026-10-04)

- [x] Implement RA-20/RA-21/RA-21b A6 `SurfaceQuotientClosedComplexView`: canonical side-incidence edges, A6 relation labels, typed-source hard-feature protection, quotient lineage and opposite-edge strip closure.
- [x] Candidate extraction consumes only the A6 closed-complex view; no arrangement-authority dependency.
- [x] Freeze focused identities 25-28; focused-28 SHA-256 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`, exact focused-24 prefix.
- [x] Final semantic source `582da20a925ba920c923bf5aacb9e0e56ef0723d`; mandatory GMP/GMPXX compile/package run/job `37216400150 / 111477707423` GREEN for all eight standard targets; result/log `11308472138 / 11308317584`; package manifest 28/28; clean source receipts; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB11-G4-EXEC`:** immutable candidate `11308472138`, focused28 + selector449 = **477** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB11-G4-REV`; only then `M6-CP1-CLOSE-REV`. Code + Build makes no `G4-B002`, debt, runtime-promotion or CP1-closure claim.

## Current — `M6-CP1-TB10-A5V-R1-REV` + review-agent addendum / RA-21b / exact next `M6-CP1-CB11-G4` (2026-10-04)

- [x] Re-derive TB10-R1: digest `b9f2daed`, 965/965 manifest, focused-24 and selector449 ledgers in frozen order (473/473), focused 20/24 OK; HEAD == `96b456f9`.
- [x] Confirm the F1 reorder and binding in source, and the F2 oracle by a full struct-field census.
- [x] CB11 pre-analysis → RA-21b. The proposal key is positional (no `CellId`); `halfedge.proposalId` is only the primary entry; cell sides are per-face polylines, so a degree-2-contraction equivalence is needed. CB11 plan amended.
- [x] Record `consumedInternalIsolationSeams` sourcing for CP1 close. Lesson 195.
- [ ] **Exact next `M6-CP1-CB11-G4`** (RA-20/RA-21/RA-21b): compile/package only; focused 25-28.
- [ ] TB11 **477**, then mandatory Review, then `M6-CP1-CLOSE-REV`.

## Superseded — `M6-CP1-TB10-A5V-R1-REV` pre-addendum checklist
## Current — `M6-CP1-TB10-A5V-R1-REV` ACCEPTED / exact next `M6-CP1-CB11-G4` (2026-10-04)

- [x] Independently re-derive candidate/runtime evidence: 28/28 package, 965/965 result, focused24 24/24 + selector449 449/449 = **473/473**, exact-one, zero skips, benchmark 0, immutable postflight.
- [x] Discharge F1: publish A5 records first; moved helper validates the published complex and its certificate/cells.
- [x] Discharge F2: identity24 independently asserts every adapter-written result, mesh, vertex-lineage and face-lineage field.
- [x] Close CAND-01/CAND-02 as recovery-proved/non-stable; keep stable accounting **60 / 16 / 44**, debt 1.
- [x] Promote `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` as current reviewed M6 runtime authority.
- [ ] **Exact next `M6-CP1-CB11-G4`:** implement RA-20/RA-21 A6 closed-complex `G4-B002` boundary; Code + Build only.
- [ ] Compile-green -> TB11 **28+449=477** -> mandatory Review.
- [ ] `M6-CP1-CLOSE-REV` retains cross-sheet proxy, provenance-face audit and merged diagnostics; no CP1 closure yet.

## Current — `M6-CP1-TB10-A5V-R1-EXEC` runtime GREEN / mandatory Review next (2026-10-04)

- [x] Consume immutable R1 candidate `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea`.
- [x] Execute focused24 then selector449 as **473** fresh exact-filter processes.
- [x] Record focused **24/24**, selector **449/449**, aggregate **473/473 PASS**, exact-one selection, zero skips, benchmark 0.
- [x] Verify result self-manifest **965/965** and immutable package/source/execution-view postflight; package manifest remains **28/28**.
- [x] Record **+0 new regression events/candidates**; stable accounting remains **60 / 16 / 44**, debt 1. Existing TB10 Review CAND-01/CAND-02 remain Review-owned and open/non-stable.
- [x] Complete workflow-first temporary-state cleanup; the final EXEC beacon follows as the last repository action.
- [ ] **Exact successor `M6-CP1-TB10-A5V-R1-REV`:** independently verify R1 runtime/static evidence and adjudicate candidate promotion plus CAND-01/CAND-02.
- [ ] CB11 remains held until R1 Review.

## Superseded — prior `M6-CP1-CB10-A5V-R1` COMPLETE / compile-package GREEN / exact next `M6-CP1-TB10-A5V-R1-EXEC` (2026-10-04)

- [x] Restore RA-19a ordering: publish all A5 records first, then validate the published complex.
- [x] Rebind moved side/cell checks to `complex.certificate().directedSideCount` and `complex.cells()`.
- [x] Strengthen identity24 to the exact TB10 Review §J3 pure-projection field table without changing identity/list bytes.
- [x] Re-hash focused24/focused20/selector449/routing449 unchanged.
- [x] Patch applied as semantic source `96b456f925be00e00bad6645e6eb905a804c14ea`.
- [x] Compile run/job `37192727051 / 111408174395`: all eight GMP/GMPXX targets GREEN, artifact `11299078582`, manifest 28/28, clean receipts, `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB10-A5V-R1-EXEC`:** immutable focused24 + selector449 = **473** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB10-A5V-R1-REV`; then only if accepted proceed toward CB11. CB11 remains held.

## Superseded — prior TB10-A5V Review exact-next checklist

## Current — `M6-CP1-TB10-A5V-REV` + review-agent addendum / RA-19a / exact next `M6-CP1-CB10-A5V-R1` (2026-10-04)

- [x] Re-derive TB10: digest `109e98d6`, 965/965 manifest, focused-24 and selector449 ledgers in frozen order (473/473); HEAD == `7c56845d`.
- [x] Confirm F1 in source (`:4937` before `:4943`) and F2 (identity-24 field gaps). Accept shared `τ`, RA-22b and the thin adapter's mapping and serialization.
- [x] Verify move fidelity by normalized predicate diff: 28 identical; side count re-bound to the A4 input; 3 unpinned names merged.
- [x] RA-19a: bind the helper to the published complex; exact identity-24 field table (§J3). R1 plan amended. Lesson 194.
- [ ] **Exact next `M6-CP1-CB10-A5V-R1`**: R1 ordering + binding, R2 exact oracle, R3 static checks; compile/package only.
- [ ] TB10-R1 **473**, then mandatory Review. Then CB11 (477), then `M6-CP1-CLOSE-REV` (cross-sheet proxy, provenance-face audit, merged diagnostics).

## Superseded — `M6-CP1-TB10-A5V-REV` pre-addendum checklist
## Current — `M6-CP1-TB10-A5V-REV` REJECTED / exact next CB10-A5V-R1 (2026-10-04)

- [x] Independently verify TB10 result: result/log/candidate digests, 965/965 self-manifest, 28/28 candidate manifest, focused24 24/24 + selector449 449/449 = 473/473, exact-one, zero skips, benchmark 0, immutable postflight.
- [x] Re-hash focused24/focused20/focused12 and selector449/routing449.
- [x] Accept shared `tau` single-sourcing and RA-22b representative-face guard.
- [x] **F1:** reject promotion because moved category-(a) helper executes before pre-existing `publish_records_for_validation`, contrary to RA-19.
- [x] **F2:** reject promotion because identity24 under-compares the adapter serialization and is not yet the frozen full pure-projection falsifier.
- [ ] **Exact next `M6-CP1-CB10-A5V-R1`:** fix F1 ordering and strengthen identity24 only; compile/package, runtime forbidden.
- [ ] Compile-green -> `M6-CP1-TB10-A5V-R1-EXEC`, unchanged focused24 + selector449 = **473**, then mandatory `M6-CP1-TB10-A5V-R1-REV`.
- [ ] CB11 remains held. `M6-CP1-CLOSE-REV` retains A7 cross-sheet proxy + provenance-face consumer audit.

## Current — `M6-CP1-TB10-A5V-EXEC` COMPLETE / 473/473 GREEN / mandatory Review next (2026-10-04)

- [x] Consume immutable CB10 candidate `11295692493 / 7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`.
- [x] Execute focused24 then selector449 as **473** fresh exact-filter processes.
- [x] Record focused **24/24**, selector **449/449**, aggregate **473/473 PASS**, exact-one, zero skips, benchmark 0.
- [x] Verify result self-manifest **965/965** and immutable package/source/execution-view postflight; no runtime repair or retry.
- [x] Keep stable accounting **60 / 16 / 44**, debt 1; no new regression candidate and no promotion in EXEC.
- [ ] **Exact next `M6-CP1-TB10-A5V-REV`:** independently verify TB10 evidence and adjudicate candidate promotion.
- [ ] CB11 remains held until TB10 Review.

## Superseded — `M6-CP1-CB10-A5V` COMPLETE / TB10 next
## Current — `M6-CP1-CB10-A5V` COMPLETE / compile-package GREEN / exact next TB10-A5V 473 (2026-10-04)

- [x] Move RA-19 category-(a) phase-front semantic validation into A5 after all pre-existing A5 checks; preserve compatibility failure names and validation precedence.
- [x] Single-source accepted source-support tolerance `1.0e-8`; A5 and A7 consume one canonical accessor.
- [x] Restore RA-22b representative-face retained region/sheet reject-only guard and focused20 negative; preserve focused20 positive.
- [x] Freeze focused identities 21-24; focused24 SHA-256 `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`, exact focused20 prefix.
- [x] Prove the adapter static-thin contract: no phase-front semantic tolerance/selector remains; identity24 behaviorally matches independent A5/A6/A7 serialization on three fixtures.
- [x] Repair one compile-only Eigen row/column mismatch in identity24; final semantic source `7c56845d4fac7ccb28898bbf4c681fc509ff9c3b`.
- [x] Mandatory eight-target GMP/GMPXX compile/package GREEN at run/job `37182633770 / 111378124041`; candidate `11295692493`; 28/28 manifest; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB10-A5V-EXEC`:** immutable candidate `11295692493`, focused24 + selector449 = **473** fresh exact-filter processes, exact-one, zero skips, benchmark 0.
- [ ] Mandatory `M6-CP1-TB10-A5V-REV`; CB11 remains held until Review.
- [ ] `M6-CP1-CLOSE-REV` retains A7 cross-sheet certification proxy + provenance-face consumer audit.

## Superseded — `M6-CP1-TB9-A7-R1-REV` / CB10 next
## Current — `M6-CP1-TB9-A7-R1-REV` + review-agent addendum / RA-22b / exact next `M6-CP1-CB10-A5V` (2026-10-04)

- [x] Re-derive TB9-R1:
  - digest `a690ca39`, 970/970 manifest;
  - focused-20 and selector449 ledgers in frozen order, 469/469;
  - focused 20 OK (72 s);
  - HEAD == `584f80fe`.
- [x] Review the R1 diff: RA-22/RA-22a are implemented. **Found:** R1 deleted the A7 representative-face reject-only guard. RA-22b restores it in CB10 Goal T2, with a focused-20 negative; this is provably gate-neutral.
- [x] Record the provenance-face consumer audit for `M6-CP1-CLOSE-REV`. Lesson 192.
- [ ] **Exact next `M6-CP1-CB10-A5V`**: RA-19 + shared `τ` + RA-22b T2; focused 21-24; compile/package only.
- [ ] `M6-CP1-TB10-A5V-EXEC` **473**, then mandatory Review. Then CB11 (477), then `M6-CP1-CLOSE-REV` (cross-sheet proxy + consumer audit).

## Superseded — `M6-CP1-TB9-A7-R1-REV` pre-addendum checklist
## Current — `M6-CP1-TB9-A7-R1-REV` ACCEPTED / R1 promoted / exact next CB10-A5V (2026-10-04)

- [x] Independently re-verify result manifest **970/970**, focused **20/20**, selector449 **449/449**, aggregate **469/469**, exact-one, zero skips, benchmark 0 and immutable postflight.
- [x] Re-hash focused12/focused20 and prove the first12 byte prefix; re-hash selector449/routing449.
- [x] Re-open focused20 source/raw log and confirm non-vacuous production completion-ownership execution.
- [x] Accept RA-22/RA-22a recovery and promote `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c` as current reviewed M6 runtime authority.
- [x] Close `M6-CP1-TB9-A7-EXEC-CAND-01` as recovery-proved/non-stable existing `RP-01`; stable accounting stays **60/16/44**, debt 1.
- [x] Carry `τ` single-sourcing into amended CB10 plan; carry A7 cross-sheet proxy to `M6-CP1-CLOSE-REV`.
- [ ] **Exact next `M6-CP1-CB10-A5V`:** bounded A5 validation/thin-adapter migration + shared `τ`; compile/package only.
- [ ] Compile-green -> `M6-CP1-TB10-A5V-EXEC`: focused24 + selector449 = **473** fresh exact-filter processes -> mandatory Review.
- [ ] CB11 remains held until TB10 Review.

## Superseded — `M6-CP1-TB9-A7-R1-EXEC` COMPLETE / 469/469 GREEN / mandatory Review next (2026-10-04)

- [x] Consume immutable R1 candidate `11292072930 / 584f80fe27fe3fbe482f3b6db035651a3083257c`.
- [x] Execute focused20 then selector449: **469** fresh exact-filter processes, exact-one, zero skips, benchmark 0.
- [x] Record focused **20/20**, selector **449/449**, aggregate **469/469 PASS**; formerly failing focused20 now PASSes.
- [x] Verify 970/970 result manifest, immutable package/source/execution-view/fixtures, unchanged selector/routing, and zero tracked diagnostics.
- [x] Record prior non-stable `RP-01` candidate as recovery-proved in EXEC; stable accounting remains **60/16/44**, debt 1.
- [ ] **Exact next `M6-CP1-TB9-A7-R1-REV`:** independently verify R1 result and adjudicate candidate promotion.
- [ ] CB10 remains held until recovery Review.

## Current — `M6-CP1-CB9-A7-R1` COMPLETE / compile-package GREEN / exact next TB9-R1 469 (2026-10-04)

- [x] Implement RA-22 completion-consumer class authority only in `PureQuadCompletion.cpp`.
- [x] Derive A7 source-component singleton from retained charts; fail closed with `:component-singleton`.
- [x] Validate A7 selected destination by retained region/sheet membership plus singleton component; preserve legacy closure.
- [x] Emit RA-22a `:dest-unresolved`, `:dest-region`, `:dest-sheet`, `:dest-component` suffixes; no test/production exact-string consumer found.
- [x] Compile/package all eight standard GMP/GMPXX targets at `584f80fe27fe3fbe482f3b6db035651a3083257c`; run/job `37173519009 / 111351273790`; candidate `11292072930`; 28/28 manifest; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB9-A7-R1-EXEC`:** immutable candidate `11292072930`, focused20 + selector449 = **469** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB9-A7-R1-REV`; CB10 remains held until Review.

## Current — `M6-CP1-TB9-A7-REV` + review-agent addendum / RA-22a / exact next `M6-CP1-CB9-A7-R1` (2026-10-04)

- [x] Re-derive TB9: digest, 970/970 manifest, ledgers. Focused-20 order matches the frozen file and its prefix is byte-identical to focused-12. 468/469, sole RED focused 20.
- [x] Verify CB9 A7 against RA-18:
  - support from A5;
  - reject-only same-simplex guard;
  - the `1e-9` check removed;
  - no placement-transport read;
  - focused 15 asserts code plus site.
- [x] Deduce the failing subclause statically: destination sheet ≠ representative sheet. Confirm RA-22.
- [x] RA-22a: destination and component-singleton site suffixes (R1 G5).
- [x] Record the A7 cross-sheet proxy (owner: CP1 close) and `τ` single-sourcing (owner: CB10). Lesson 191.
- [ ] **Exact next `M6-CP1-CB9-A7-R1`**: completion seam only, compile/package only.
- [ ] `M6-CP1-TB9-A7-R1-EXEC`, **469**, then mandatory Review. Then CB10 (473), CB11 (477), `M6-CP1-CLOSE-REV`.

## Superseded — `M6-CP1-TB9-A7-REV` pre-addendum checklist
## Current — `M6-CP1-TB9-A7-REV` COMPLETE / completion authority defect proved / R1 recovery next (2026-10-04)

- [x] Independently re-open TB9 result `11288673996`: self-manifest **970/970**, focused **19/20**, selector449 **449/449**, aggregate **468/469**, exact-one, zero skips, benchmark 0, immutable postflight.
- [x] Confirm focused20 alone fails after successful materialization at real `validate_materialized_completion_domain_ownership` with `CompletionOwnershipInvalidSelectedRelationDestination`.
- [x] Uphold CB9 A7 producer: class-wide chart/region/sheet lineage and singleton component authority are published; representative `sourcePoint` is compatibility-only.
- [x] Prove completion-consumer authority-domain conflation and freeze **RA-22**: A7 destinations consume retained chart/region/sheet authority and a component singleton derived from retained charts; no representative-sheet/component semantic selection.
- [x] Adjudicate `M6-CP1-TB9-A7-EXEC-CAND-01` as cause-proved/non-stable existing `RP-01`; accounting stays **60 / 16 / 44**, debt 1.
- [x] Reject/unpromote `11287202960 / b8d27b63...`; reviewed runtime remains TB8 `11265967968 / 8e0818b1...`.
- [ ] **Exact next `M6-CP1-CB9-A7-R1`:** implement only RA-22 completion-consumer recovery; compile/package only, runtime forbidden.
- [ ] Compile-green -> `M6-CP1-TB9-A7-R1-EXEC`: unchanged focused20 + selector449 = **469** -> mandatory `M6-CP1-TB9-A7-R1-REV`.
- [ ] Keep CB10 held until recovery Review; do not change focused20, selector449, fixtures, A7 producer, RA-18 or relation/transport semantics.

## Current — `M6-CP1-TB9-A7-EXEC` COMPLETE / 468/469 semantic RED / mandatory Review next (2026-10-04)

- [x] Consume immutable candidate `11287202960 / b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`.
- [x] Execute focused20 then selector449: **469** fresh exact-filter processes, exact-one, zero skips, benchmark 0.
- [x] Record focused **19/20**, selector **449/449**, aggregate **468/469**.
- [x] Localize sole RED to focused20 real production completion ownership: `CompletionOwnershipInvalidSelectedRelationDestination` after materialization succeeds.
- [x] Record `M6-CP1-TB9-A7-EXEC-CAND-01` as Review-owned/non-stable candidate `RP-01`; stable accounting remains **60/16/44**, debt 1.
- [ ] **Exact next `M6-CP1-TB9-A7-REV`:** independently adjudicate the class-wide A7 relation authority vs representative-anchored completion destination predicate and candidate promotion/rejection.
- [ ] CB10 (RA-19, 473) remains held until TB9 Review explicitly authorizes it.

## Current — `M6-CP1-CB9-A7` COMPLETE / compile-package GREEN / exact next `M6-CP1-TB9-A7-EXEC` (2026-10-03)

- [x] Implement immutable A7 `SourceAttachedGeometryProduct` / producer and RA-18 typed support + reject-only same-simplex point guard.
- [x] Remove the adapter's old semantic `1e-9` point-coincidence check.
- [x] Add focused identities 13-20; focused-20 SHA-256 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2` and exact focused-12 prefix verified.
- [x] Compile/package all eight standard GMP/GMPXX targets at `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8` using run/job `37160018910 / 111311373537`; candidate artifact `11287202960`; `runtimeExecution=false`.
- [x] Diagnose and repair the two compile-only defects without executing Directional runtime.
- [ ] **Exact next `M6-CP1-TB9-A7-EXEC`:** immutable candidate `11287202960`, **20+449 = 469** fresh exact-filter processes.
- [ ] Mandatory `M6-CP1-TB9-A7-REV`.
- [ ] Then CB10 (RA-19, 473), CB11 (RA-20/RA-21, 477), `M6-CP1-CLOSE-REV`.
- [ ] `M6-DEFN-R5` remains the CP3-entry gate.

## Superseded — pre-CB9 routing

## Current — `M6-DEFN-R4-REV` COMPLETE / R4 accepted with RA-18 – RA-21 / exact next `M6-CP1-CB9-A7` (2026-10-03)

- [x] Review the R4 record, D4 census, CB9-11 plans and frozen amendment against exact source (HEAD == `8e0818b1` semantics).
- [x] Re-derive the D2 pinned-literal claim independently: only rows 212, 227/230 and 139/140/142.
- [x] F1 → RA-18. The `1e-9` check is the only cross-relation point-coincidence detector, so add a reject-only same-simplex point guard. Support comes from A5 `occurrence.support` only. Identity 15 renamed.
- [x] F2 → RA-20. Protection comes from source hard-feature authority. The torus's 18 hard edges are PeriodicCut carriers.
- [x] F3 → RA-21. Oracle key path `(proposalId, proposalSide)` → A4 `CellId`/side, with a stop rule.
- [x] F4/F5 → RA-19. Moved A5 checks go after existing A5 checks; identity 24 is behavioral; the source rule is a static check.
- [x] Amend the CB9/10/11 plans; lessons 189-190.
- [ ] **Exact next `M6-CP1-CB9-A7`** (RA-18 block governs): compile/package only.
- [ ] `M6-CP1-TB9-A7-EXEC`, **20+449 = 469**, then mandatory Review.
- [ ] Then CB10 (473), CB11 (477), `M6-CP1-CLOSE-REV`.
- [ ] `M6-DEFN-R5` (CP3-entry): include the A5 HardRail-route-only chart-barrier census item.

## Superseded — `M6-DEFN-R4` completion checklist

- [x] D4 complete consumer/frozen-assertion census: 1,189 exact-snapshot references, 666 production + 523 test/benchmark.
- [x] D1 freeze immutable A7 product, exact typed SourceSupport incidence, deterministic representative, lineage projection, RA-17 transport guard and typed A7 failures.
- [x] D2 classify all 55 direct adapter failures: 31 A5 + 4 A6 projection + 19 A7 + 1 serialization; freeze stage precedence and thin-adapter predicate.
- [x] D3 freeze A6 `SurfaceQuotientClosedComplexView`, exact HardRail/Periodic label derivation, topology-derived strip identity, produced-torus labeled-isomorphism demonstration and independent mechanism oracle; CP3 keeps direct `G4-B002` debt proof.
- [x] D5 freeze CB9/CB10/CB11 sequences and focused 20/24/28 gates: 469 / 473 / 477 processes, respectively.
- [x] Append the pending-Review R4 amendment to `Architecture_M6_Frozen_Definitions.md` and write CB9/CB10/CB11 plans.
- [x] Durability closeout: exact documentation patch applied by run `37144877459` as commit `0f3024732e2f16b35c8c2a787a519378af2b9591`; changed-path authority verified; `runtimeExecution=false`.
- [ ] **Exact next `M6-DEFN-R4-REV`:** mandatory runtime-free Review. No CB9 implementation before Review acceptance.

## Current — `M6-CP1-TB8-A6-REV` review-agent addendum: promotion confirmed / R4 bounded (RA-17) / R4 next (2026-10-03)

- [x] Re-derive TB8 independently:
  - result digest, 954/954 manifest and five ledgers;
  - selector449 order, focused 1-12 order, the focused-12 raw log;
  - HEAD semantic source == `8e0818b1`.
- [x] Review the CB8 diff against RA-16:
  - coordinate-rigid HardRail derivation from occurrence placements;
  - the `canonicalRelationValue` decoupling;
  - A5-owned route predicate;
  - focused 3 and focused 12(b) discriminate (12(b) would fail the RA-14 rule).
- [x] Correct TB8-REV §3's overclaim: selector446 replicates the completion comparator and does not run it. Pre-register the witness production-completion identity for the first A7 CB.
- [x] Freeze `Architecture_M6_CP1_Required_Green_Focused_12.txt` (SHA-256 `59a523ae...3d571c`) as a required-green prefix.
- [x] Freeze RA-17:
  - transport guard;
  - R4 bounded to CP1 exit;
  - gauge obligations → `M6-DEFN-R5` (CP3-entry).
- [x] Write `Architecture_M6_DEFN_R4_CP1_A7_Thin_Adapter_G4B002_Definition_Plan.md`. Order: D4 census first, then D1 A7, D2 adapter 55-site classification, D3 `G4-B002`, D5 CB sequencing.
- [x] Record lesson 188.
- [ ] **Exact next `M6-DEFN-R4`:** runtime-free; follow the plan.
- [ ] Mandatory `M6-DEFN-R4-REV`. Then the A7/adapter/G4 CBs per D5, each gated by focused-12 + new identities + selector449.
- [ ] `M6-DEFN-R5` (CP3-entry): periodic face-gauge witness and rule; HardRail branch certification; OrdinaryFront identity across isolation seams.

## Superseded — `M6-CP1-TB8-A6-REV` pre-addendum checklist (R4 scope replaced by the R4 plan and RA-17)

- [x] Independently re-hash candidate `11265967968`, verify 28/28 root manifest, source `8e0818b1...`, GMP command boundary, selector449/routing449 hashes and row counts.
- [x] Independently verify TB8 result `11273611682`: **954/954** self-manifest, focused 12/12, selector449 449/449, aggregate **461/461**, exact-one, zero skips, benchmark 0 and empty RED ledger.
- [x] Verify immutable postflight and zero diagnostic census; re-open critical focused/selector outcomes.
- [x] Adjudicate TB7 stable recovery: HardRail placement authority, route-validation precedence and lineage-value regressions are **RECOVERY PROVED**; historical accounting stays **60 / 16 / 44**, debt 1.
- [x] Promote `11265967968 / 8e0818b1...` as current reviewed M6 runtime authority under selector449 449/449.
- [ ] **Exact next `M6-DEFN-R4`:** runtime-free Definition for A7 representation/certificates, thin adapter, `G4-B002` A6-derived boundary, carried periodic unequal-face-gauge witness/rule, HardRail branch certification and OrdinaryFront seam identity.
- [ ] Mandatory `M6-DEFN-R4-REV` before any A7/G4 Code + Build implementation.
- [ ] CP1 closure remains held until the frozen A7 / thin-adapter / `G4-B002` boundary scope is implemented and freshly gated.

## Current — `M6-CP1-TB8-A6-EXEC` COMPLETE / 461/461 GREEN / mandatory Review next (2026-10-03)

- [x] Consume CB8 candidate `11265967968 / 8e0818b1...` immutably.
- [x] Execute focused 1-12 then selector449: **461 fresh exact-filter processes**, **461/461 PASS**, exact-one, zero skips, benchmark 0.
- [x] Focused12 and full TB7 RED-set recovery verified; focused6/10/11 and selector139/140/142/232/444/446/448/449 PASS.
- [x] Zero raw holonomy/corner-authority/HardRail-transport/relation-certificate diagnostics; self-manifest **954/954**; immutable postflight.
- [x] No new candidate or stable repricing; **60 / 16 / 44**, debt 1; candidate remains unpromoted.
- [ ] **Exact next `M6-CP1-TB8-A6-REV`:** independently verify evidence, adjudicate recovery/promotion and authorize next work.
- [ ] Keep R4/A7/G4 held until TB8 Review.

## Current — `M6-CP1-CB8-A6` COMPLETE / compile-package GREEN / TB8 next (2026-10-03)

- [x] Implement RA-16 coordinate-rigid HardRail placement transport from occurrence placements; no branch comparison.
- [x] Decouple `canonicalRelationValue` from `canonicalTransport`; selected lineage steps consume the former while A6 certificates retain the latter.
- [x] Move exact HardRail route-authority validation into A5 with shared `exact_interior_route_valid` and preserve `InvalidHardRailAuthority`.
- [x] Strengthen focused 3 and add focused 12, `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`.
- [x] Preserve selector446 / `PureQuadCompletion.cpp`, selector449 / selector448-prefix / routing449, fixtures and A7/R4/G4.
- [x] Complete the required pre-CB7 lineage proof for OrdinaryFront, HardRail, exact-A3 Periodic and non-A3 Periodic in `Architecture_M6_CP1_CB8_A6_Code_Build_Report.md`.
- [x] Apply source patch at `2b182f1c...`; diagnose the declaration-order-only test compile failure; apply bounded test-local repair at `8e0818b1...`.
- [x] Mandatory compile/package retry `37101997642 / 111143233041` GREEN on all eight GMP/GMPXX targets; candidate artifact `11265967968`; `runtimeExecution=false`.
- [ ] **Exact next `M6-CP1-TB8-A6-EXEC`:** focused 1-12 in order, then selector449 in file order with routing449 = **461** fresh exact-filter processes, benchmark 0.
- [ ] Recovery-green is **461/461** -> mandatory `M6-CP1-TB8-A6-REV`.
- [ ] Keep `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative half and direct-torus debt held until TB8 Review.

Stable accounting remains **60 / 16 / 44**, debt 1. Reviewed runtime authority remains TB5 `10879581622 / 82b86a28...` until TB8 Review.

## Current — `M6-CP1-TB7-A6-REV` review-agent addendum: RA-16 / CB8 amended / TB8 = 461 (2026-10-03)

- [x] Re-derive the TB7 evidence: digest, 953/953 manifest, three ledgers, selector order, 460 raw logs. Verify the downstream-row grouping in code (`RemeshPipeline.cpp:11912`, `:14302`).
- [x] Confirm Finding A's diagnosis: HardRail route steps carry identity transport (`SurfaceCellTracing.cpp:11670-11672`). Correct the remedy: RA-14's branch-derived `R` is off by the field matching across the rail, because `branchRotation` is face-gauged.
- [x] Overturn Finding C. Selector446 restates the production completion check (`PureQuadCompletion.cpp:1086-1132`, run at `RemeshPipeline.cpp:10705`); CB7 rewrote the M5 lineage step transport. CAND-03 becomes a stable RP-01 recurrence → **60 / 16 / 44**, debt 1.
- [x] Freeze RA-16:
  - coordinate-rigid HardRail placement transport from occurrence placements;
  - `canonicalRelationValue` decoupled from `canonicalTransport`;
  - A5-owned route validity;
  - RA-14 items 2-5 superseded; RA-13 item 1 withdrawn.
- [x] Amend the CB8 plan:
  - revoke the selector446 migration and the `PureQuadCompletion.cpp` edit;
  - add the A2 decoupling;
  - strengthen focused 3; add focused 12 (face-gauge relabel invariance plus the witness coordinate rule);
  - TB8 = 12+449 = 461.
- [x] Record lessons 186-187.
- [ ] **Exact next `M6-CP1-CB8-A6` as amended:** compile/package only; runtime forbidden.
- [ ] CB8 green -> `M6-CP1-TB8-A6-EXEC`: exactly **12+449 = 461** fresh processes -> mandatory `M6-CP1-TB8-A6-REV`.
- [ ] Carried to `M6-DEFN-R4`:
  - an exact-A3 periodic face-gauge witness (unequal corresponding-corner `faceBranchRotation`) with the coordinate-rule replacement;
  - cross-region branch certification for HardRail;
  - OrdinaryFront coordinate identity across isolation seams.

## Superseded — `M6-CP1-TB7-A6-REV` pre-addendum checklist (its CB8 scope is replaced by RA-16)

- [x] Independently re-open TB7 result `11262587435`, raw RED logs, 953/953 self-manifest and exact source; confirm mechanically valid **443/460** semantic RED.
- [x] Adjudicate CAND-01 as one stable `RP-01` recurrence: HardRail carrier route is not cut-domain placement transport; direct + downstream losses share one first mechanism.
- [x] Adjudicate CAND-02 as one stable `VALIDATION_ORDER_SHADOWING` recurrence: rows227/230 route-authority typing is pre-empted by earlier pair reciprocity.
- [x] Close CAND-03 as non-stable test authority: selector446 production recovers; stale assertion compares RA-13 placement transport to relation-endpoint semantic action.
- [x] Freeze RA-14 HardRail carrier/placement separation and RA-15 individual-route-before-pair validation; stable accounting **59 / 16 / 43**, debt 1.
- [x] Reject/unpromote `11257522199 / 40842caa...`; retain reviewed runtime `10879581622 / 82b86a28...`, selector449 449/449.
- [ ] **Exact next `M6-CP1-CB8-A6`:** implement RA-14/RA-15 and selector446 gauge-aware assertion migration, compile/package only, runtime forbidden.
- [ ] CB8 green -> `M6-CP1-TB8-A6-EXEC` exact **11+449=460** fresh processes -> mandatory `M6-CP1-TB8-A6-REV`.
- [ ] Keep `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative half and direct-torus debt held until TB8 Review.

## Current — `M6-CP1-TB7-A6-EXEC` COMPLETE / mechanically valid 443/460 RED / exact next `M6-CP1-TB7-A6-REV` (2026-10-03)

- [x] Consume candidate `11257522199 / 40842caa...` immutably; verify package/source/selector/routing/modes and construct the separate packaged-fixture execution view without repair.
- [x] Execute exact **11 focused + 449 selector = 460** fresh exact-filter processes: focused **11/11 PASS**, selector **432/449 PASS**, aggregate **443/460 PASS / 17 RED**; exact-one selection and zero skips hold.
- [x] Confirm CB7 target recoveries: focused6 PASS; rows139/142 reject correctly; row140 and 232/444/448/449 PASS; zero raw `QuotientHolonomyConflict` and zero `OccurrenceInvalidCornerAuthority`.
- [x] Record the 17 REDs in the regression tracker as three non-stable Review-owned candidate envelopes; keep stable accounting **57 / 16 / 41**, debt 1.
- [x] Preserve semantic RED without repair/rerun; no configure/compile/relink/discovery/benchmark/package/test/fixture/selector mutation occurred.
- [ ] **Exact next `M6-CP1-TB7-A6-REV`:** independently re-open result `11262587435`, adjudicate CAND-01 HardRail gauge authority, CAND-02 typed validation precedence, CAND-03 row446 RA-13 test authority, stable accounting and candidate promotion/rejection.
- [ ] Keep `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative half and direct-torus debt held until TB7 Review.

Candidate `11257522199 / 40842caa...` remains unpromoted. Reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 449/449.

## Review-agent addendum — `M6-CP1-TB6-A6-REV` (2026-10-02)

- [x] TB6 re-verified; Finding A upheld (fail-open guard loss); 57/16/41 with debt 1 upheld.
- [x] Finding B corrected: gauge mixing, not legitimate holonomy. Residual fallback revoked; RA-13 frozen; CB7 plan amended (§3 replaced, §4.2 revoked).
- [x] `M6-CP1-CB7-A6`: Goal A + RA-13 implemented and compile/package green at `11257522199 / 40842caa...`; runtime remains held for TB7.
- [ ] `M6-CP1-TB7-A6-EXEC` (460, same order; 446 and focused 6 must pass strict) → `M6-CP1-TB7-A6-REV`.

## Historical initial `M6-CP1-TB6-A6-REV` conclusion — superseded by the 2026-10-02 review-agent addendum

- [x] Reconcile both TB6-A6 Actions runs; authoritative run `36362570974` is mechanically valid at **456/460 PASS**.
- [x] Reject/unpromote candidate `10896307843 / a532f803...`; retain reviewed runtime `10879581622 / 82b86a28...`, selector449 449/449.
- [x] Reprice stable history to **57 / 16 / 41**, debt 1: selector446 = existing `RP-07` recurrence; rows139+142 = one `VALIDATION_ORDER_SHADOWING` recurrence.
- [x] Invoke and freeze R3 residual-holonomy fallback: cycle-closing A6 publishes exact `D`, `P`, `H=compose(P.inverse(),D)`; nonidentity residual alone is not `QuotientHolonomyConflict`.
- [x] Confirm focused row4 migration is runtime-green/value preserving; A6 focused8-11 all PASS.
- [ ] **Exact next `M6-CP1-CB7-A6`:** restore A5 HardRail reciprocal region/reversed-route validation; implement exact cycle residual evidence; strengthen A6 certificate-to-A5 authority validation; keep focused count 11.
- [ ] CB7-A6 compile/package only using standard eight GMP/GMPXX targets; `runtimeExecution=false`; no selector/fixture/A7/R4/G4 mutation.
- [ ] Compile-green -> `M6-CP1-TB7-A6-EXEC`, exact **11+449=460** fresh processes -> mandatory `M6-CP1-TB7-A6-REV`.
- [ ] Keep `M6-DEFN-R4`, A7, `G4-B002`, `G4-B004` representative half and direct-torus debt held until recovery Review.

## Superseded EXEC-only interpretation — mandatory Review found an authoritative second run

- [x] Re-verify candidate `10896307843 / a532f803...` immutably: ZIP/source hashes, root 28/28, selector/routing449, owner census and executable modes unchanged.
- [x] Record the execution error: package binaries were run without the standard separate adjacent `test-data/benchmarks/fixtures` execution view. Six completed tests failed only on that missing fixture package.
- [x] Stop invalid attempt after 149 completed exact-filter processes; do not rerun because the frozen plan forbids retry after runtime starts.
- [x] Record +0 regression/accounting disposition and preserve candidate immutability.
- [ ] `M6-CP1-TB6-A6-REV`: mandatory next turn; adjudicate zero semantic credit and explicitly authorize/name any fresh retry turn if warranted.
- [ ] Keep `M6-DEFN-R4`, A7 and `G4-B002` held until valid runtime evidence plus Review.

Accounting remains **55 / 16 / 39**, debt 1. Reviewed runtime authority remains `10879581622 / 82b86a28...`; candidate `10896307843 / a532f803...` is unpromoted.

## Superseded TB6-A6 pre-execution gate (review-agent reconciliation, 2026-09-28)

- [x] CB6-A6 COMPLETE (candidate `10896307843 / a532f803`); handoff consistent.
- [x] Froze the exact 460-process order now folded into `M6_Consolidated_Record.md` §24: focused 1-7 in TB5 order, new 8-11, then selector449; all focused route to the producer tests. Holonomy falsifiers are row232 and 444/446/448/449, with no `QuotientHolonomyConflict` allowed.
- [x] `M6-CP1-TB6-A6-EXEC` completed as orchestration-invalid / zero semantic credit → mandatory `M6-CP1-TB6-A6-REV`.

## Superseded — `M6-CP1-CB6-A6` COMPLETE; TB6-A6 attempt now closed invalid

- [x] A6 quotient-product extraction and legacy-field retirement are compile/package green at semantic source `a532f803bd2f0ef92342652ea3f1a9b64945ba69`.
- [x] Compile R1 `36212725707 / 108322509801` packages candidate `10896307843` (28/28, eight GMP/GMPXX targets, clean receipts, `runtimeExecution=false`). First compile `36212343902` failed on declaration clashes and was superseded only by the bounded `a532f803` compile fix.
- [x] CB report records RA-1 – RA-4 static compliance and the focused row4 `lattice` → `placement.lattice` value-identical migration. Prior CB6-A6 compile/snapshot temporary state was retired through cleanup run `36358568335`.
- [x] TB6-A6 EXEC attempted; orchestration invalid because the standard adjacent test-data execution view was not constructed. No semantic gate credit and no same-turn retry.
- [ ] Mandatory `M6-CP1-TB6-A6-REV` before any promotion, fallback, R4, A7 or `G4-B002` work.
- [ ] `M6-DEFN-R4` remains deferred until the A6 implementation/gate/Review sequence completes.

Accounting remains **55 / 16 / 39**, debt 1. Reviewed runtime authority remains `10879581622 / 82b86a28...`, selector449 449/449; candidate `10896307843 / a532f803` is unpromoted.

## Superseded historical checklist — `M6-DEFN-R3` definition closeout (Review now complete)

- [x] Freeze CP1 exit checklist, A6 member-set identity, exact-once joining/cycle-closing ledger, cycle transport consistency, selected-path ownership and A6 failure vocabulary.
- [x] Record analytic split-square / uniform hard-rail / ordinary-identity holonomy proof and pre-register produced cylinder row232 + torus rows444/446/448/449 as TB falsifiers.
- [x] Write `Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md` and the normative frozen-definition amendment.
- [x] Write the now-consumed CB6-A6 plan (folded into `M6_Consolidated_Record.md` §§23-25); four new focused identities; later gate = **11 + 449 = 460**.
- [x] Mark standalone legacy-field CB6 plan superseded/held; retirement is folded into A6 extraction.
- [x] **Historical exact next completed:** `M6-DEFN-R3-REV` accepted and authorized `M6-CP1-CB6-A6`.
- [ ] `M6-DEFN-R4` before A7 CB: freeze A7 product representation and exact `G4-B002` A6 stage boundary.

## Recovery — `M6-DEFN-R3` stalled after its start beacon; resume the same turn with the bounded scope (2026-09-25T21:13:47Z)

- [x] Recovery verified: only beacon `cd084a0d`; no record, snapshot or Drive patch. Beacon repaired to canonical form (it had `NONE` values).
- [x] DEFN-R3 plan bounded (§5): A6-only decisions plus the A6 CB plan. A7 and `G4-B002` deferred to `M6-DEFN-R4`. The holonomy static proof on produced fixtures is replaced by an analytic proof plus a TB falsifier.
- [ ] Resume `M6-DEFN-R3` (keep Started at 20:10:00Z; new Resumed at) → `M6-DEFN-R3-REV` → A6 extraction CB.

## Review-agent addendum — `M6-CP1-TB5-REV` (2026-09-25)

**TB5 recovery and promotion upheld; CP1 scope corrected; exact next `M6-DEFN-R3`.** See `M6_Consolidated_Record.md` §22 (TB5 Review/addendum) and `Architecture_M6_DEFN_R3_CP1_Product_Separation_Plan.md`.

- [x] `M6-DEFN-R3`: bounded A6 definition complete. A7 representation and exact `G4-B002` boundary intentionally deferred to `M6-DEFN-R4`.
- [x] `M6-DEFN-R3-REV` — accepted; bounded R3 record and A6 plan reviewed.
- [x] `M6-CP1-CB6-A6` — completed compile/package green; runtime gate remains 11 focused + selector449 = 460 -> mandatory Review.
- [ ] A7 extraction and adapter thinning CB, then TB, then Review.
- [ ] `G4-B002` A6 stage-boundary CB, then TB, then Review, then CP1 closure Review against the restated exit scope.
- [x] ~~CB6 standalone legacy-field retirement~~ — HELD and folded into the A6 CB.

## M6-CP1-TB5 Review complete — bounded CB6 product-surface cleanup next (2026-09-25)

**TB5 Review: RECOVERY ACCEPTED / runtime candidate PROMOTED / CP1 OPEN only on static A5 product shape. Exact next: `M6-CP1-CB6`.** Current reviewed runtime authority is `10879581622 / 82b86a28...` under selector449 **449/449**. Stable accounting remains **55/16/39**, debt **1**.

- [x] Independently re-open candidate package/source and TB5 result/log: package 28/28, result 933/933, exact 456/456 mechanics and immutable postflight upheld.
- [x] Formal recovery: TB1 iterator-range, TB3 RP-01 and TB4 RP-01 are RECOVERY PROVED; TB2 validation-order remains recovery-proved. Historical stable counts remain intact.
- [x] Promote CB5/TB5 package/source `10879581622 / 82b86a28...` as current reviewed runtime authority under unchanged selector449.
- [x] Correct stale TB4-REV debt: aggregated lineage `equivalences` are already sorted/de-duplicated after tuple remap in exact candidate source; no code change required.
- [ ] `M6-CP1-CB6`: remove unread public `SurfaceOccurrence.chart`, `.lattice`, `.isolationSheet` plus matching constructor/call-site arguments only; preserve every live A5 semantic field.
- [ ] CB6 compile/package standard eight GMP/GMPXX targets with `runtimeExecution=false`; no generated runtime.
- [ ] Compile-green -> `M6-CP1-TB6-EXEC`, unchanged **7 focused + selector449 = 456** -> mandatory `M6-CP1-TB6-REV`; only that Review may close CP1.

## Historical — M6-CP1-TB5 EXEC complete (2026-09-25)

**TB5 is COMPLETE / MECHANICALLY GREEN / 456/456 / CANDIDATE UNPROMOTED. Exact next: `M6-CP1-TB5-REV`.** Stable accounting remains **55/16/39** in EXEC, debt **1**; accepted M5 package `10814505512` / selector449 449/449 remains runtime authority pending Review.

- [x] Consume candidate artifact `10879581622` immutably; verify package/source/selector/routing and archived executable modes without repair.
- [x] Execute exactly **7 focused + selector449 = 456** fresh exact-filter processes: **456/456 PASS**, exact-one, zero skips/crashes/selection mismatches, benchmark 0.
- [x] Recover all 21 TB4 accepted-prefix losses and the carried torus falsifier (focused row6 + selector 444/446/448); keep rows5/7 and row140 green.
- [x] Record regression gate: **no new regression candidate / +0 stable accounting in EXEC**; formal recovery and promotion remain Review-owned.
- [x] `M6-CP1-TB5-REV`: recovery accepted and candidate promoted; CP1 held only by the static legacy-field precondition.
- [ ] Moved to exact successor `M6-CP1-CB6`: remove unread legacy `SurfaceOccurrence.chart`, `.lattice`, `.isolationSheet`; keep `point` and `chartComponent`.
- [x] Review correction: exact source already sorts/de-duplicates aggregated lineage `equivalences` after tuple remap; stale debt withdrawn.

## M6-CP1-CB5 complete — immutable TB5 next (2026-09-25)

**CB5 is COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE. Exact next: `M6-CP1-TB5-EXEC` → mandatory `M6-CP1-TB5-REV`.** Stable accounting remains **55/16/39**, debt **1**; accepted M5 package `10814505512` / selector449 449/449 remains runtime authority.

- [x] Correct A6 OrdinaryFront collinear/no-certificate spans to the non-seam same-sheet + both-wedges P2 predicate; preserve certificate-backed seam validation.
- [x] Implement RA-12 site-qualified legacy isolation diagnostics without changing tests or semantic failure prefixes.
- [x] Static audit: only `src/pipeline/RemeshPipeline.cpp` changed semantically; selector449/routing449 hashes remain frozen.
- [x] Compile/package the standard eight targets with GMP/GMPXX; run/job `36168827294 / 108183151046`, artifact `10879581622`, manifest 28/28, clean source receipts, `runtimeExecution=false`.
- [x] **TB5:** artifact `10879581622` consumed immutably; **7/7 focused + 449/449 selector = 456/456 PASS** with exact immutable postflight.
- [x] **TB5 Review:** 456/456 upheld; TB1/TB3/TB4 recovery proved; candidate promoted; CP1 remains open only on CB6 field retirement.
- [ ] Current owner `M6-CP1-CB6`: retire unread legacy `SurfaceOccurrence.chart`, `.lattice`, `.isolationSheet`; keep `point` and `chartComponent`.
- [x] TB5 Review correction: exact source already sorts/de-duplicates after tuple remap; no implementation owed.

## Review-agent addendum — `M6-CP1-TB4-REV` (2026-09-25)

**Upheld 55/16/39; exact next `M6-CP1-CB5` as amended.** See `M6_Consolidated_Record.md` §§19-20 (TB4 Review/addendum).

- [x] CB5: A6 collinear span with no certificate → non-seam P2 rule; certificate present → seam branch unchanged.
- [x] CB5: RA-12 site suffixes on every `Missing/InvalidIsolationSeamEquivalenceAuthority` emission (A5 adapter and the four A6 sites).
- [x] TB5 (456): **456/456 PASS**; there is no residual RA-12 failure to classify in EXEC. Formal recovery is Review-owned.
- [ ] CP1-acceptance precondition: remove or relabel the unread legacy `SurfaceOccurrence` fields `isolationSheet`, `chart` and `lattice` (`point` is live; `chartComponent` is legitimate).
- [ ] Minor: re-sort aggregated lineage `equivalences` after tuple remap.

## M6-CP1-TB4 Review complete — bounded CB5 next (2026-09-25)

**Review verdict:** TB4 mechanics are upheld; `M6-CP1-TB4-EXEC-CAND-01` is one new stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence. Stable accounting is **55 / 16 / 39**, debt **1**. Candidate `10871935178` stays unpromoted; accepted M5 package `10814505512` / selector449 449/449 remains authority.

- [x] Independently re-verify candidate package 28/28, TB4 result 932/932, accepted M5 result 911/911, exact 456-process mechanics and selector/prefix/routing hashes.
- [x] Prove root: A5's `collinearEdge` is generic source-edge support, while A6 incorrectly consumes every such edge as isolation-seam certificate authority.
- [x] Record one new stable RP-01 recurrence; totals **55/16/39**. Carry TB3 and TB1 formal recovery clauses; keep TB2 validation-order recovery closed.
- [ ] **Exact next `M6-CP1-CB5`:** one A6 OrdinaryFront P2 correction only — no certificate means non-seam same-sheet + both-wedges validation; exact certificate means existing seam face/sheet/reciprocal-evidence validation.
- [ ] CB5 compile/package only, standard eight GMP/GMPXX targets, `runtimeExecution=false`; no test/fixture/selector or A5/schema change.
- [ ] Compile-green → `M6-CP1-TB5-EXEC`, unchanged **7 + 449 = 456** exact processes → mandatory `M6-CP1-TB5-REV`.

## M6-CP1-TB4 EXEC complete — mandatory Review next (2026-09-25)

**TB4 is COMPLETE / MECHANICALLY VALID / SEMANTIC NON-GREEN / CANDIDATE UNPROMOTED.** Run/job `36157505252 / 108145613689` executed exactly 456 fresh exact-filter processes from immutable artifact `10871935178`: focused **6/7**, selector449 **425/449**, aggregate **431/456 PASS**.

- [x] Immutable artifact/package/source/selector/routing preflight and postflight; exact-one selection, zero skips, no watchdog, no build/repair/benchmark execution.
- [x] Seven focused + selector449 = 456 processes executed exactly once.
- [x] Record `M6-CP1-TB4-EXEC-CAND-01` for the 21 newly RED accepted-selector identities; stable accounting remains 54/16/38 in EXEC.
- [ ] **Exact next:** mandatory runtime-free `M6-CP1-TB4-REV`; independently adjudicate all 24 selector REDs and formal recovery status.
- [ ] Do not rerun TB4 or start a corrective Code + Build turn before Review.

## M6-CP1-CB4 complete — immutable TB4 next (2026-09-25)

**CB4 is COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE.** Semantic source `20f60bb1412424a6f1093fc8076884d1ea23f1c5`; candidate artifact `10871935178` is unpromoted.

- [x] Implement R2 + RA-1 – RA-11 complete wedge binding/isolation authority, relation-local selected-path charts, tuple-first remap, reciprocal side validation and the strengthened seventh focused identity.
- [x] Static frozen-gate audit complete; selector449/routing449 remain byte-identical (`d4a0d1b7...d6414` / `9c88a5ed...c5707`).
- [x] Compile/package all eight standard targets with mandatory GMP/GMPXX; run/job `36150253128 / 108121497728`, artifact `10871935178`; `runtimeExecution=false`.
- [x] `M6-CP1-TB4-EXEC` — mechanically valid immutable 456-process execution complete; semantic result 431/456 PASS, candidate unpromoted.
- [ ] Then mandatory `M6-CP1-TB4-REV`.

Stable accounting remains **54 / 16 / 38**, debt 1. Accepted runtime authority remains M5 package `10814505512`; no CB4 runtime credit/promotion.

## CB4 blocker resolved — RA-11 (2026-09-25, review agent)

**`M6-CP1-CB4` is UNBLOCKED; resume the same turn.** No consumer needs a per-face branch. Wedge bindings are `(face, sheet, chart)`, and the A4 corner lattice state is published as face-labelled placement provenance. See the blocker record's "Review-agent adjudication".

- [x] Blocker facts re-verified; RA-11 frozen (no A4 change, no raw field input, no representative branch).
- [ ] Resume `M6-CP1-CB4` (preserve `Started at 2026-09-25T06:19:30Z`) and implement R2 + RA-1 – RA-11; compile the eight GMP targets.
- [ ] `M6-CP1-TB4-EXEC` 7 + 449 = 456 → `M6-CP1-TB4-REV`.

## CB4 static blocker — per-face branch authority unavailable at A5 boundary (2026-09-25)

**`M6-CP1-CB4` stopped before production/test mutation and before compile.** Exact snapshot inspection shows D6/R2 requires a per-source-face `branchRotation` in every `CornerWedgeFaceBinding`, while immutable A4 `SurfacePhaseFrontProduct` exposes only corner-selected `LocalLatticeState.branchRotation`, side-segment branch data, and isolation-seam transport certificates. It does not preserve the builders' complete per-face branch table or an ordinary-edge field-transport atlas. An intermediate corner-wedge face can therefore have no derivable exact branch value at A5. See `M6_Consolidated_Record.md §16 (folded RA-11 blocker authority)`.

- [x] Per-face branch authority source resolved by review amendment RA-11 (no Definition turn needed).
- [x] CB4 re-authorized: resume the same turn under RA-1 – RA-11.
- [ ] TB4 remains held; no compile artifact or runtime credit exists for this CB4 attempt.

## Review — `M6-DEFN-R2-REV` (2026-09-25)

**ACCEPTED WITH REVIEW AMENDMENTS RA-1 – RA-10; exact next `M6-CP1-CB4`.** See `Architecture_M6_DEFN_R2_Review_Record.md`.

- [x] B1-B4 and P1-P4 re-derived; the orientation premise is proved in all three builders; consumer neutrality of `CornerWedgeIsolation` confirmed.
- [x] RA-1 – RA-10 frozen (boundary edges, P3/P4 predicates, row-invariant permutation checks, row3 `UnownedRelation`, wedge-union lineage, `crossesSheets` retirement, arc endpoints and direction, resolver tolerance, transitional `quotientClass`).
- [ ] `M6-CP1-CB4` under the amended plan → compile/package the eight GMP targets (no runtime). **Not yet started**: the aborted 05:40Z session produced nothing, so enter as a fresh turn (see handoff recovery note).
- [ ] `M6-CP1-TB4-EXEC` 7 + 449 = 456 → `M6-CP1-TB4-REV`.

## Definition amendment complete — `M6-DEFN-R2` (2026-09-25)

**RUNTIME-FREE / B1-B4 + P1-P4 frozen for Review / CB4 HELD / exact next `M6-DEFN-R2-REV`.** See `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`.

- [x] B1: freeze evidence-only `CornerWedgeIsolation` lineage equivalence with ordered exact `(region,seam,fromSheet,toSheet)` transitions; v0/center/v2 row5 semantics now satisfiable without invented relations.
- [x] B2: freeze complete occurrence binding signatures, relation-local selected-path charts/components, tuple-preserving remap, and union-of-all-bindings lineage charts.
- [x] B3: freeze exact `SourceSupport` collinearity + canonical cell-interior incident-face rule and prove its orientation premise for uniform, periodic-chart and bounded-disk builders.
- [x] B4: split A5 relation failures 1:1 and freeze compatibility-adapter mappings without weakening M5 semantic checks.
- [x] P1-P4 and frozen-test audit over focused rows 5/6, selector rows 186/214/239/444/446/448, and HardRail single-sheet assertions.
- [x] Re-scope CB4 implementation and strengthen the seventh focused identity; TB4 remains **7+449=456**.
- [ ] Mandatory `M6-DEFN-R2-REV`; only an accepted Review may authorize `M6-CP1-CB4`.

## Historical Review — `M6-DEFN-R1-REV` (2026-09-25)

**Core corner-wedge model UPHELD; not accepted as frozen; CB4 HELD; exact next `M6-DEFN-R2`.** See `Architecture_M6_DEFN_R1_Review_Record.md` and `Architecture_M6_DEFN_R2_Amendment_Plan.md`.

- [ ] B1: represent verified wedge/collinear-side evidence in `PureQuadVertexLineage::equivalences` (new equivalence kind); prove focused row5 passes at v0 and v2; the seventh identity also asserts lineage (v0/centre/v2 `{0,1}`, others singleton).
- [ ] B2: binding-selection rule for the transitional `QuotientDomainState`/`QuotientClassId` ordinal, `representative_key`, selected-path charts and chart components (rows 444/448), and lineage `sourceCharts`; `chartComponent` occurrence-wide with a fail-closed check.
- [ ] B3: collinearity by exact segment `SourceSupport`; one interior-face rule across `segment_on_source`, `periodic_chart_segment` and `bounded_disk_chart_segment`; prove per builder that cell orientation agrees with source winding.
- [ ] B4: split A5 relation failures 1:1 and map them at the adapter to legacy M5 names (or amend §4.6 explicitly).
- [ ] P1-P4, and a frozen-test audit over rows 5, 6, 186, 214, 239, 444, 446, 448 and the HardRail single-sheet rows.
- [ ] `M6-DEFN-R2-REV`, then the re-scoped `M6-CP1-CB4` → TB4 (7+449=456) → TB4-REV.

## Definition complete — `M6-DEFN-R1` (2026-09-25)

**RUNTIME-FREE / eight seam-incident authority decisions frozen / CB4 re-scoped but HELD / exact next `M6-DEFN-R1-REV`.** Occurrence isolation authority is now the complete corner-wedge sheet set with per-wedge face/chart/branch provenance; seam certificates live on the wedge or directed side that actually crosses/runs along the seam; `OrdinaryFront` remains owner-less; seam-collinear sides use exact incident-cell interior-face authority; A7 lineage unions member wedge sets; row140 legacy naming is adapter-only.

- [x] Freeze corner-wedge sheet/certificate authority and seam-vertex rule.
- [x] Freeze A6 ordinary relation membership/side-evidence checks with unchanged `OccurrenceRelationId`.
- [x] Freeze seam-collinear side semantics and per-wedge provenance.
- [x] Freeze A7 lineage completeness and row140 adapter/duplicate-check policy.
- [x] Re-scope CB4/TB4; new focused identity `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; gate **7+449=456**.
- [x] Mandatory `M6-DEFN-R1-REV`: core upheld; amendments B1-B4/P1-P4 routed to `M6-DEFN-R2`.
- [ ] Only after Review acceptance: re-scoped `M6-CP1-CB4` → `M6-CP1-TB4-EXEC` → `M6-CP1-TB4-REV`.

## Review-agent addendum — `M6-CP1-TB3-REV` (2026-09-25)

**Accounting upheld 54/16/38, debt 1. Root cause corrected; CB4 HELD; exact next `M6-DEFN-R1`.** CB3's outgoing-side occurrence sheet is a representative choice at seam-incident corners, where a cell's wedge spans two sheets. A relation-owned certificate is on the wrong object and is ambiguous at seam vertices. See the TB3 Review addendum A2-A7.

- [ ] `M6-DEFN-R1`: freeze occurrence sheet authority at seam-incident corners (recommended: corner-wedge sheet set).
- [ ] `M6-DEFN-R1`: freeze the certificate carrier (recommended: wedge certificates keyed by the seam edges the wedge crosses) and the rule at seam vertices.
- [ ] `M6-DEFN-R1`: A6 relation check (side sheet in both endpoint wedge sets); `OrdinaryFront` stays owner-less and `OccurrenceRelationId` is unchanged.
- [ ] `M6-DEFN-R1`: A7 lineage completeness (split-square v0 and v2 record {0,1}); single-face occurrence record; sides collinear with a seam.
- [ ] `M6-DEFN-R1`: policy for the row140 adapter mapping and the three unreachable duplicate M5 checks.
- [ ] `M6-DEFN-R1`: re-scope CB4/TB4; recommended new focused identity (7+449=456).
- [ ] `M6-DEFN-R1-REV`, then re-scoped `M6-CP1-CB4` → TB4 → TB4-REV.

## Latest Review turn — `M6-CP1-TB3-REV`

**COMPLETE / ONE NEW STABLE RP-01 RECURRENCE / CANDIDATE UNPROMOTED.** Independent Review upholds TB3 at focused **4/6** + selector449 **443/449** = **447/455 PASS** with exact immutable postflight. Accepted M5 result `10815911956` independently re-verifies **449/449 PASS**, confirming selector losses **186, 214, 239, 444, 446, 448** are accepted-prefix regressions.

All six plus focused multi-isolation/pair-swap stop at `MissingIsolationSeamEquivalenceAuthority`. Root cause is the missing frozen A5 relation-owned isolation-certificate reference for cross-sheet ordinary relations: the transitional consumer currently reconstructs semantic owner authority from front-edge boundary-path representation. This is one stable existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence. Stable accounting is **54 / 16 / 38**, debt **1**. Row140 recovery is proved; TB1 formal 449/449 recovery clause remains carried.

## HELD (re-scoped by `M6-DEFN-R2`) — `M6-CP1-CB4`

Runtime-free Code + Build, **not authorized until `M6-DEFN-R2-REV` accepts**. Implement complete wedge bindings/evidence, evidence-only `CornerWedgeIsolation` lineage projection, exact seam-collinear interior-face authority, the one-to-one A5 failure vocabulary/adapter, relation-local selected-path charts, tuple-preserving component remap, and P1/P2 reciprocal validation. Preserve occurrence/relation identity, relation-only quotient equality, tests/fixtures/selector449/routing449, Periodic/HardRail semantic owners and all M5 content/transport falsifiers.

Compile-green then advances to immutable `M6-CP1-TB4-EXEC` with seven focused + selector449 = **456** fresh exact-filter processes, then mandatory Review.

See `.agents/Directional/M6_Consolidated_Record.md §§10-16 (folded TB3 Review authority)` and `.agents/Directional/M6_Consolidated_Record.md §§12-18 (folded CB4 plan authority)`.

## Latest Code + Build turn — `M6-CP1-CB2`

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE ONLY.** Exact semantic source `724316a5b3f49e33dc8e649989bb413b3dc6b7c9` materializes the A5 region isolation-sheet vector once, eliminating the Review-proved cross-temporary iterator range without changing region/component/sheet/support/chart semantics. Whole-tree split-range scan is clean; selector449/routing449 and all six focused identities are unchanged.

Mandatory GMP/GMPXX compile run/job `36061049526 / 107839861958` packages all eight standard targets as artifact `10834642074`, SHA-256 `754cfeae794da3304b39a572ef6feb6250709f908d5688dcd21f387a071d0cb8`, with **28/28** root manifest, clean source receipts and `runtimeExecution=false`. Candidate remains unpromoted; accounting stays **52 / 15 / 37**, debt 1.

## Historical successor — `M6-CP1-TB2-EXEC` (completed)

Consume artifact `10834642074` immutably. Execute the unchanged six focused identities followed by selector449 as exactly **455 fresh exact-filter processes**, exact-one selection and zero skips, benchmark 0, then exact immutable postflight. Recovery of `M6-CP1-TB1-EXEC-CAND-01` requires no `OccurrenceInvalidCornerAuthority` anywhere plus selector449 **449/449**. A focused RED with a different first failure is a new candidate. Every mechanically valid outcome advances to mandatory runtime-free `M6-CP1-TB2-REV` with no TB repair/rerun.

Superseded TB2 plan/report/Review authority is folded into `.agents/Directional/M6_Consolidated_Record.md`; current retained runtime evidence is `.agents/Directional/M6_Consolidated_Record.md §§9-11 (folded TB3 runtime authority)`, with adjudication in `.agents/Directional/M6_Consolidated_Record.md §§10-16 (folded TB3 Review authority)`.

## Latest Code + Build turn — `M6-CP1-CB1`

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE ONLY.** Exact semantic source `ee8b8ac20571df5773f5f94bf9b382161f37a893` publishes semantic A5 occurrence identity/product authority and makes the transitional materializer consume `SurfaceOccurrenceComplex`. Final compile run/job `36038472933 / 107764451786` packages all eight standard GMP/GMPXX targets as artifact `10826090221` with 28/28 manifest, clean source receipts and `runtimeExecution=false`. Four new A5 identities compiled; TB1 has now executed the frozen six-test vector and selector449. Candidate runtime is semantic RED and unpromoted. Selector449 bytes remain exact `d4a0d1b7...d6414`; historical TB1 mechanics are Review-adjudicated at corrected stable accounting 52/15/37 and debt 1.

- [x] A5 `OccurrenceId=(CellId, canonicalCornerRole)` and immutable occurrence product/certificate extracted.
- [x] True source-face-row permutation test authored; A4 `CellId` semantics unchanged.
- [x] Endpoint-gauge dormant identity deleted; pair-swap identity retained for CP1 prepublication gate.
- [x] Focus vector frozen at six identities; accepted selector449 unchanged.
- [x] Final eight-target GMP/GMPXX compile/package green; no runtime.

## Latest Definition — `M6-DEFN-R2`

**COMPLETE / RUNTIME-FREE / B1-B4 + P1-P4 FROZEN FOR REVIEW.** Normative M6 semantics are the R2-amended `Architecture_M6_Frozen_Definitions.md`; CB4 remains HELD until `M6-DEFN-R2-REV` accepts.

## Latest Code + Build turn — `M5-CP4-CB2`

**COMPLETE / SELECTOR449 PUBLISHED / EIGHT-TARGET GMP COMPILE+PACKAGE GREEN / RUNTIME-FREE.** Publication source `e284fea7c101eb86650d1c87c92d0fefa66050e7`; compile run/job `36013904054 / 107681435506`; result/log `10814505512 / 10814141518`; package manifest 28/28; `runtimeExecution=false`. TB2 has now mechanically validated this exact package, but final acceptance remains Review-owned.

## Latest Test + Benchmark turn — `M5-CP4-TB1-EXEC`

**COMPLETE / 449 PASS + 0 RED / REVIEWED PREPUBLICATION EVIDENCE.** Run/job `35937669401 / 107438319768`; result/log `10784376393 / 10784391222`; exact-one selection, zero skips, benchmark 0, immutable postflight. TB1-REV accepts row449's producer proof but does not promote this package to accepted M5 runtime authority.

## Previous Code + Build turn — `M5-CP4-CB1`

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE.** Candidate artifact/source `10782841045 / 535ec760...`; mandatory GMP/GMPXX linkage, 26/26 package manifest, `runtimeExecution=false`. CB1 plan/report are folded by TB1 Review; immutable artifact evidence remains authoritative.

## Previous accepted Code + Build turn — `M5-CP3-CB20`

**COMPLETE / SELECTOR448 PUBLISHED / RUNTIME-FREE / COMPILE+PACKAGE GREEN.** At CB20, exact selector448 was published at 448 unique rows, 36,382 bytes, SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`, exact selector430 prefix, standard-owner census 32/300/75/41; routing receipt SHA-256 is `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`. Publication source is `cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1`. Compile run/job `35910024971 / 107347291148`, result/log artifacts `10771899191 / 10772810906`, root manifest 28/28; all eight GMP/GMPXX targets link and `runtimeExecution=false`. CB20 itself made no acceptance claim; `M5-CP3-TB2-REV` later accepts these exact bytes and promotes this package.

## Latest Test + Benchmark turn — `M5-CP3-TB2-EXEC`

**COMPLETE / MECHANICALLY GREEN / PUBLISHED SELECTOR448 448 PASS + 0 RED / REVIEW REQUIRED.** Fresh run/job `35913334490 / 107358491487` consumes CB20 artifact/source `10771899191 / cef1c6ee...` immutably and executes selector448 as **448 fresh exact-filter processes**: 448/448 PASS, exact-one selection, zero skips, owner census 32/300/75/41, protected 191/192/247/408 PASS, all appended 431-448 PASS, benchmark 0, result evidence 917/917 and exact immutable postflight. Result/log artifacts are `10775185139 / 10774217117`. No regression was observed; accounting stays 51 / 14 / 37 and project debt 1 M6-owned. EXEC grants no selector acceptance or M5 closure; exact successor is mandatory `M5-CP3-TB2-REV`.

## Previous Definition turn — `M5-DEFN-R1`

**COMPLETE / RUNTIME-FREE / DISPOSITION A — NOT ACCEPTED at `M5-DEFN-R1-REV`.** It proposed that M5 focused multi-isolation means ≥2 isolation sheets joined by a checked isolation-seam certificate, credited rows 186/239, and froze conjunct 8. The Review rejected that on chronology and redundancy grounds. The record is folded (git `d17aada2`).

## Previous semantic Code + Build turn — `M5-CP3-CB17`

CB17 is **COMPLETE / RUNTIME-FREE / COMPILE GREEN**, candidate `10742798135 / 1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`. It implements frozen §16.3 exactly: `Q = G_R^-1 A G_F`, Forward cut-domain branch/raw coordinate authority, Reverse `Q` normalization, and relation-owned checked-product validation. The new synthetic contract proves `Q != A` and fails if either accepted occurrence-gauge term is deleted. All eight mandatory GMP/GMPXX targets compile/link; no Directional runtime was executed. Candidate remains unpromoted pending R15.

## Previous control-plane Code + Build turn — `M5-CP3-CB18`

**COMPLETE / CONTROL-PLANE GREEN / RUNTIME-FREE / NO DIRECTIONAL COMPILE / NO REPACKAGE.** Canonical R15-R1 harness/caller are frozen at SHA-256 `7867e779...81b7 / 0f0a12f9...a15c`. Static run `35864475136` proves corrected literal GTest accounting `selected/passed/skipped=1/1/0`, historical parser `0/0`, skip probe `1/0/1`, and both workflow schemas green. No semantic input changed; accounting remains 51 / 14 / 37, debt 3.


## Current observations

- [x] `M5-CP3-TB1-R5-REV-OBS-01` — recovery proved by R7.
- [x] `M5-CP3-TB1-R2-REV-OBS-01` — successful atlas-owned value consumption proved at R7 while hard-feature nontraversal control remains green.
- [x] `M5-CP3-TB1-R8-REV-OBS-01` — **CLOSED / NO-TUNING + CHART ADMISSIBILITY INDEPENDENTLY UPHELD AT R9 REVIEW**.
- [x] `M5-CP3-TB1-R6-REV-OBS-01` — **DISCHARGED AT R16 REVIEW**. Independent source/A3 authority fixes semantic Forward -> Reverse `Q=3`; the accepted produced relation concretely stores the inverse quarter-turn `1`, and corrected row16 proves stored action/route differ before resolving back to the independent semantic authority.
- [x] `M5-CP2-TB1-REV-OBS-01` — **DISCHARGED BY R16 REVIEW PRECOMMITMENT**. The corrected pre-publication gate is independently accepted at 448/448 with complete evidence, and exact selector448 is precommitted under frozen §13.3; publication itself remains owned by `M5-CP3-CB20`.
- [x] `M5-CP3-TB1-R9-REV-OBS-01-A` — **DISCHARGED AT R10 REVIEW**; produced rows1/2/3/6 remain PASS under CB11, empirically upholding frozen §16's `R=0` reduction.
- [x] `M5-CP3-TB1-R13-REV-OBS-01` — **DISCHARGED AS TRIGGERED AT R14 REVIEW**; it forced DEFN-R1 before any CB17 semantic implementation.
- [x] `M5-CP3-DEFN-R1-REV-OBS-01` — **DISCHARGED AT R15-R1 REVIEW**. The `Q != A` mechanism identity passes in a complete mechanically valid ledger and falsifies omission of either occurrence gauge; mechanism-only, no produced-debt credit.
- [x] `M5-CP3-TB1-R14-REV-OBS-01` — **DISCHARGED AT DEFN-R1**; independent committed-torus source/A3 derivation yields relation-gauge `Q=3` before relation publication.
- [x] `M5-CP3-TB1-R15-REV-OBS-01` — **DISCHARGED / RUNTIME-PROVED AT R15-R1 REVIEW**. Frozen corrected parser accounts for all 448 exact-one/zero-skip processes in a complete valid ledger.
- [x] `M5-CP3-TB1-R15-R1-REV-OBS-01` — **DISCHARGED AT R16 REVIEW**. CB19 kept the expectation independent (hard-coded `Q=3`) while using the resolver only to normalize representation; R16 proves it at runtime.
- [x] `M5-CP3-TB1-R16-REV-OBS-01` — **DISPOSED AT TB2 REVIEW / NO M5 CREDIT.** The two CB14 identities were never executed, remain absent from selector448 and receive no M5 credit. `M6-DEFN` DISCHARGED this obligation: both are frozen for no-credit deletion as superseded at `M6-CP1-CB1`; accepted replacement identities are named in `Architecture_M6_Frozen_Definitions.md` §9.
- [x] `M5-CP3-TB2-REV-OBS-01` — **DISCHARGED AT `M5-CP4-TB2-REV`.** DEFN-R2 froze the same-region producer join; row449 proved it, selector449 was published and freshly executed 449/449, and final Review accepts conjunct8 and closes M5. The representative M6 half remains M6-owned.
- [ ] `M5-DEFN-R1-REV-OBS-01` — **RECORDED / process.** COMPLETE was published before the turn's durable work was on the branch. Every implementation turn must make COMPLETE its final write.
- [x] `M5-CP3-TB2-REV-OBS-02` — **RECOVERED.** Tracker overwritten at `ce9bf3cb` (9,837 → 21 lines) and restored verbatim (`LESSONS.md` 176).
- [x] `M5-CP3-TB2-REV-OBS-03` — **RECOVERED.** Agent CHANGELOG overwritten at `0043dd4c` (13,317 → 14 lines) and restored verbatim. The committed-history guard is `review_check.py ledgers --base <previous-review-commit>`. Every Review should run it.
- [ ] M6 closed-complex produced debt (`G4-B002`, `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous`): **OPEN / M6-owned.** M6-CP1 mechanism, M6-CP3 direct production. *(Restored. TB2-REV had dropped this open item.)*
- [ ] `M5-CP3-TB1-R16-REV-OBS-02` — **RECORDED / NOT FIRING**. Rows 446/447 pin inverse canonical storage. If it fires, classify as test-authority drift and keep the pin.
- [x] `M5-CP3-TB1-R16-REV-OBS-03` — **DISCHARGED AT TB2 REVIEW.** `M5_Consolidated_Record.md` now has one chronological unique §4.1-§4.31 sequence and live citations are repaired.

## Deferred hygiene

- [ ] **Repair `.github/workflows/agent-turn-cleanup.yml` comment handling and trigger safety.** The workflow still deletes **all** PR conversation and inline review comments before its observer step, and creating `.agents/connector-triggers/turn-cleanup/manifest.txt` auto-triggers it. Run `32591251950 / 97075340976` demonstrated 27 conversation-comment deletions. User commit `c359ea925b04471500575a9dcc17bdc6e4bb52d1` explicitly superseded the old prohibition by requiring the manifest/workflow at every turn closeout. Until the workflow is repaired, preserve durable repository evidence before publishing the closeout manifest and treat PR comments as non-durable.

Inherited baseline-red / non-gating fixtures remain frozen in the M1 exclusion register. None may become required-green evidence before its precondition is independently established.

- [ ] `WU2A-TB-CAND-01`: successful-side-subdivision ownership-registry precondition.
- [ ] `WU2B-TB-CAND-01`: hard-rail region-copy valid front-boundary-authority precondition.
- [ ] `WU2B-TB-CAND-02`: side-repair rollback ownership-registry/domain-identity precondition.
- [ ] `WU2B-TB-CAND-03`: authoritative-cell-scope subdivision source-scope reconciliation.
- [ ] `WU2B-TB-CAND-04`: five simplification fixtures need independently proven removable/protected/healing preconditions.
- [ ] `WU2B-TB-CAND-05`: FlowRep mandatory-cycle witness needs `selectionSucceeded=true` before later-cycle evidence is creditable.
- [ ] `RA-REV-23-F3`: dispatch stitch-kind audit through an explicit classifier field rather than probe-name text; add a negative self-test.
- [ ] `RA-REV-22-F6`: remove non-falsifiable validation-used assertions or set them where each gate actually executes.
- [ ] `RA-TB6-H1`: repair repeated `TriMesh::set_mesh` / `DCEL::init` stale halfedge-twin reinitialization outside the R-A fixture path.

## Milestone status

Checkpoint decomposition, per-milestone acceptance mapping, and the path to production-ready are in **`ROADMAP.md`**. Summary only:

- [x] **M0** preserve evidence  ·  [x] **M1** single-authority cutover  ·  [x] **M2** closed stage products
- [x] **M3 — field-aligned curve network.** **CLOSED / ACCEPTED at `M3-CP4c-3-TB48-REV`.** Package113/TB48 is reviewed authority at 405 PASS / 4 RED over the final audit surface, with accepted required-green selector365 at 365/365 and the AU0–AU9 mechanical-witness criterion met. Closure: `M3_Closure_Record.md`.

- [x] **M4** global conformity plan — **CLOSED / ACCEPTED at `M4-CP4-TB3-REV`**. Final runtime authority is package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**. Closure: `M4_Closure_Record.md`; CP4 closure: `M4_CP4_Closure_Record.md`. M4 handed four periodic/relation debts to M5 and one closed-complex debt to M6; R7 Review discharged two M5 debts and R16 Review discharges the remaining two nonzero-Z4 M5 debts. The sole remaining project debt is the M6 closed-complex subject.
- [x] **M5** certificate-carrying chart/quotient relations — **CLOSED / ACCEPTED at `M5-CP4-TB2-REV`.** Final authority is package/source `10814505512 / e284fea7...` under accepted selector449 **449/449**, SHA `d4a0d1b7...d6414`, owners 32/301/75/41. All §13.1 conjuncts 1-8 are accepted; M6 Definition is frozen and M6-CP1 recovery is now active.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [x] **CP4c-3 protected frontier census evidence:** Part XII was first runtime-proved in TB43: 390/393/406/407 executed the producer-owned census predicates and rejected same-domain corruption. `M3-CP4c3-TB40-EXEC-CAND-02` remains historically CLOSED / RUNTIME-PROVED / NON-STABLE. TB45 historically exposed the stale failure-required precondition; package113/TB48 now re-proves all four receipts non-vacuously through `PlanFrontier`.
- [x] **CP4c-3 protected Part XII success-path observability — CLOSED / RUNTIME-PROVED:** package111 ordinals 390/393/406/407 all PASS on `PlanFrontier`, execute the real census predicates, reject same-domain corruption and emit non-vacuous receipts.
- [x] **CP4c-3 ordinal367 independent oracle — CLOSED / RUNTIME-PROVED / NON-STABLE:** TB47/package112 PASSes ordinal367 under the frozen high-side-only rule; package112 is promoted. Accepted ordinal307 remains a separately recorded latent stale equality and is unchanged.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [x] **CP4c-3 ordinal 391 diagnostic dependency:** TB22 ordinal 391 PASSes; sphere is explicitly skipped with `reason=ordinal368-open` while mechanical/torus evidence runs. `M3-CP4c3-TB21-CAND-02` is CLOSED / runtime proved / non-stable.

- [x] **CP4c-3 ordinal370 empty closed network — CLOSED / RUNTIME-PROVED / NON-STABLE:** package113 ordinal370 PASSes under the frozen identity requiring `EmptyNetworkOnClosedSurface = 6` plus a non-empty `sourceFace` locus. TB48-REV promotes package113 and closes `M3-CP4c2-TB-X2-R8-CAND-02` without changing stable accounting.
- [ ] **CP4c-3 ordinal 374 (deferred, different owner):** the folded-cone AY5 witness declares a flat-star field (`effort ≡ 0`, no singularities) on a star with `Θ = 3π/2`, so the atlas rejects it with `CycleTransportMismatch`. Corrective is test-only — derive matching/effort/singularities with `directional::fields::principal_matching`, keep the exact expected-owner derivation, certify against the whole admissibility chain. Selector 374 stays byte-frozen and is **not** withdrawn. TB8 repeated this pre-classified stop; it adds no new product evidence.
- [ ] **Prescribed sphere A2a′ upstream error:** ordinal 368 is now repeatedly measured report-only at `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. AL4 still forbids a sphere semantic fix until separately reviewed.
- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch` (last measured 0/3 at artifact `9031804178`, pre-M1). **M6-DEFN disposition:** the original hard-rail→sheet root is absent from current source (production passes an empty isolation-barrier set). Carried as a direct-production evidence debt to **`M6-CP3`** (strict torus 3/3 re-proof). Unmeasured since then; do not weaken `LocalSheetMismatch`.
- [x] `G4-B002` main exact-torus hard-rail pairing blocker — **CLOSED / RECOVERY PROVED at M4-CP3-TB8-REV** on accepted package `10307919492` / selector408 **408/408**. The three produced-witness debts remain open: one closed-complex debt is M6-owned after DEFN-R2 and two periodic debts are M5-owned after DEFN-R1. This checkbox closes the blocker, not those debt items.
- [x] `G4-B003`: nonzero periodic Z4 production — **DISCHARGED at M5 R16 Review**; both direct-production debts are runtime/review proved.
- [ ] `G4-B004`: positive multi-isolation quotient witness. **M5 producer half ACCEPTED / DISCHARGED at `M5-CP4-TB2-REV`; M6 representative-consumption half OPEN.** Selector449 final authority proves the same-region producer join. `M6-DEFN` item 7 now owns representative exact-once materialization/consumption, embedding and independent verifier proof without weakening or reconstructing the producer fact.
- [ ] Bunny/Vase representative production and resource acceptance — later product gates.

## Design and calibration backlog

- [ ] Own the closed-rail cardinality contract once at the rail product boundary rather than re-guarding both closed representations at every consumer.
- [ ] Calibrate `T5` quality/resource thresholds from measured baselines before any milestone asserts a quality gate.
- [ ] Correct `DESIGN.md` section 6.7 invariant 2 so D1 `QualityRelaxed` consistently records missed quality gates.
- [ ] Define the M7 degraded producer algorithm and its fixed-boundary completion proof.
- [ ] **Audit every remaining `kBranchTopologyTolerance` comparison for dimensional coherence.**
  `direction_in_incident_vertex_sector` compares a Gram **determinant** — an area-squared quantity — to
  `1e-10`. After E2/E3 the surviving uses are admissibility guards only, but their scale is arbitrary and
  mesh-size dependent. Not a CP4c-0 measure; do not fold it into CB2.
- [ ] **Sweep for other tolerant-selector / exact-consumer seams.** CP4c-0 found the pattern three times
  in one subsystem (flow classification, vertex sector, cross-edge flow). The same audit is owed wherever
  an exact authority was introduced downstream of a `double` decision.

---

Current corrected totals are **55 events / 16 categories / 39 recurrences**, project debt **1** (M6 only). M4 and **M5 are CLOSED / ACCEPTED**. Final accepted M5 authority remains package/source `10814505512 / e284fea7...` under selector449 **449/449** (`d4a0d1b7...d6414`). `M6-CP1-CB5` is **COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE**; candidate artifact/source `10879581622 / 82b86a28...` is unpromoted. Exact next is immutable **`M6-CP1-TB5-EXEC`** over 456 processes, then mandatory `M6-CP1-TB5-REV`. PR #8 remains open, draft, and unmerged.
