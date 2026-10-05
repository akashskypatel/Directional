## 2026-10-05 — `M6-CP2-TB1-VERIFIER-EXEC` COMPLETE: 488/491, three non-stable Review-owned candidates

- Artifact-only retry `37368784487 / 111962223674` consumed immutable `11365308211 / 265c8fbb...`.
- Gate result: focused30 **30/30**, CP2 focused12 **9/12**, selector449 **449/449** = **488/491**; exact-one, zero skips, benchmark 0, immutable postflight PASS.
- RED ordinal 2 is a source-face permutation no-op because `SourceFaceTopologyKey::make` sorts vertices.
- RED ordinal 6 resets a certificate field already reset for `OrdinaryFront`; no payload mismatch is created.
- RED ordinal 7 fails fixture non-vacuity before verifier execution because the square fixture has no disjoint classed-cell pair.
- All three are active non-stable Review-owned candidates; no accepted-green row regressed. Stable accounting remains **60 / 16 / 44**, debt 1.
- Candidate remains unpromoted. Exact next: mandatory `M6-CP2-TB1-VERIFIER-REV`.

## 2026-10-05 — `M6-CP2-CB1-VERIFIER-R1` COMPLETE: independent verifier compile/package GREEN

- Implemented copy-by-value A5/A6/A7 verification records, independent A0/A5/A6/A7 recomputation, deterministic dependency-gated findings, exact relation/certificate-chain binding, `VerifiedSurfaceProducts`, and verifier placement after A7 / before adapter projection.
- Added frozen CP2 focused-12: semantic-order/permutation, independent A0/A5/A6/A7 checks, forbidden-repair rejection, chain binding, weld-pinched manifoldness, three wedge tampers, pipeline placement, and RA-28b representative-scope confinement. No `SurfaceMeshOptimizer` production change.
- Drive patch apply retry `37355062298 / 111915359845` produced semantic commit `3cc00697...`; the first apply attempt lost an agent-caused control-plane branch race and was not force-pushed.
- First compile run `37357362493` exposed only a new-test `DomainResult` dereference typo; bounded correction `265c8fbb...` changed `.value()` access only.
- Compile/package retry `37358279504 / 111926243775` passed all eight standard GMP/GMPXX targets. Result/log `11365308211 / 11365537617`; package **28/28**; `exactArithmeticBackend=GMP`; `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next: immutable `M6-CP2-TB1-VERIFIER-EXEC`, **491** fresh processes, then mandatory Review. Accounting remains **60 / 16 / 44**, debt 1.

## 2026-10-05 — `M6-CP2-CB1-VERIFIER-REV`: RA-28a §7 stop discharged; RA-28b; successor `M6-CP2-CB1-VERIFIER-R1`

- **Stop report verified.** A5 picks `selectedFace` from the canonical corner face; edge/vertex wedge bindings are built independently; A7 `sourceCharts` come only from bindings.
- **Root cause:** RA-28a §7 over-tightened RA-26 §5(iii) (sheet → face membership) and required an unpublished precondition. Review-agent error, owned.
- **RA-28b:**
  - no A5 invariant (the representative face stays representation-only);
  - no optimizer change: authoritative `project_vertices` is confined to the seed scope, and that static property is certified by the completion RA-22b guard and verifier RA-28a §3 before movement, and by final validation after;
  - identity 12 re-specified as a confinement falsifier (gate 491 unchanged);
  - a note for DEFN-R5 that the class-wide reference must not assume `selectedFace` ∈ class chart faces.
- **Docs:** new `Architecture_M6_CP2_CB1_Stop_Review_Record.md`; CB1 plan RA-28b block; lesson 202; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §52. Accounting 60 / 16 / 44.

## 2026-10-05 — `M6-CP2-CB1-VERIFIER` stopped for Review on RA-28a §7

- Re-derived the representative-face precondition on exact semantic source `8bc1f52b...` and found it is not certified by current A5/A7 semantics.
- A5 derives `placement.selectedFace` from the canonical corner face but edge/vertex wedge bindings from side-span/wedge traversal; no membership invariant connects them. Phase-front closure is positional, not source-face-identical. A7 `sourceCharts` are the union of wedge-binding charts.
- RA-28a's conditional stop therefore fired before repository implementation or compile/package. The exploratory verifier WIP remains unapplied and is evidence only.
- Added `Architecture_M6_CP2_CB1_Verifier_Code_Build_Report.md`; TB1 is held; runtime authority and accounting are unchanged. Successor remains UNKNOWN pending Review.

## 2026-10-05 — `M6-CP2-DEFN-REV`: CP2 verifier Definition accepted with RA-28a; CB1 released

- **Accepted:** the record-view negative seam; C4 accepted-defensive with a verifier-manifoldness falsifier; three wedge tampers; A8 after A7 and before projection; gate 491.
- **RA-28a, design fixes** before implementation:
  - exact-once / forest / spanning / cycle checks (the binding was one-directional);
  - an exact A6 → A5 field table (A6 copies verbatim; stop if a producer transforms);
  - A5 wedge, binding, sheet, seam and support checks against A0 (the evidence was self-declared);
  - dependency gating;
  - two predicate-less codes removed;
  - a `VerifiedSurfaceProducts` type invariant (the placement test was unobservable);
  - the optimizer check gated on `retained` (non-authoritative callers would regress);
  - tamper precision;
  - the A0 tuple and failure string.
- **Docs:** new `Architecture_M6_CP2_DEFN_Review_Record.md`; CB1 plan released; lesson 201; handoff / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §51. Accounting 60 / 16 / 44.

## 2026-10-05 — `M6-CP2-DEFN` froze the independent verifier candidate contract

- Defined tamperable verification record views instead of unchecked products and froze typed semantic finding identity/order.
- Froze exact A5→A6→A7 certificate-chain binding and the §6.2/§6.3 recompute/reject matrix.
- Classified C4 accepted-defensive; verifier manifoldness owns the pinched-topology falsifier.
- Added three planned wedge-rule negatives, production A8 placement, and class-wide optimizer chart-membership ownership.
- Planned CP2 focused-12; first TB gate **491**. Exact next `M6-CP2-DEFN-REV`; no implementation/runtime changed.

## 2026-10-05 — `M6-CP1-CLOSE-REV` accepted; CP1 closed mechanism-only

- Checked the six frozen CP1 exit items verbatim on current semantic source and the promoted 479/479 runtime; all pass.
- Re-ran the RA-26 provenance-consumer census: no authority-deciding consumer exists; reference-selection/permutation obligations remain later-owned.
- Kept `G4-B002` open and debt at 1; stable accounting remains **60 / 16 / 44**.
- Added `Architecture_M6_CP1_Close_Review_Record.md`, `M6_CP1_Closure_Record.md`, and the bounded `Architecture_M6_CP2_Definition_Plan.md`.
- Exact next: `M6-CP2-DEFN`; `M6-DEFN-R5` follows CP2.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-R1-REV` review-agent addendum: promotion confirmed; RA-27b; close plan amended

- **Re-derived independently:** result `11333591947` (`ef5dba11`) and log `11333547162` (`dd782961`); 497/497; focused-30 and selector449 ledgers in frozen order; 479/479; all 479 raw-log hashes match their ledgers. Candidate `3f40f04a` == HEAD.
- **Confirmed:** the RA-27a wedge rule (fixed-point reachability; region and in-set filters; fails closed on unsorted or duplicated input), the C4 `Quotient` name (required by DEFN-R3), and identity 29 on a consistent chain.
- **Corrected:**
  - the runtime proof covers one dimension of the wedge rule; the region filter and connectivity versus "touches" are static (OBS-01 → first CP2 CB);
  - C4 has no executed falsifier (→ `M6-CP2-DEFN`);
  - the C2 empty-front branch is accepted as defensive;
  - the adapter drops A7's cross-sheet site (OBS-02 → M8-CP2).
- **RA-27b:** the close plan now requires verbatim exit items, defensive-branch classification, and `G4-B002` staying open, with post-closure successor `M6-CP2-DEFN`. `M6-CP2-DEFN` absorbs the A6 → A5 binding and RA-26 §5(iii). `M6-DEFN-R5` follows CP2.
- **Docs:** close-plan review-agent block; lesson 200; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §49. Accounting 60 / 16 / 44.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-R1-REV` accepted R1 recovery and promoted 479/479 runtime

- Independently re-derived runtime `37280517630 / 111667316992`, result/log `11333591947 / 11333547162`, result manifest **497/497**, focused30 **30/30** + selector449 **449/449** = **479/479 PASS**, exact-one, zero skips, benchmark 0 and immutable postflight.
- Accepted RA-27a: exact member-local wedge connectivity and the consistent-chain identity29 falsifier are both runtime-proved; C4 diagnostic name is exact.
- Closed `M6-CP1-TB12-CLOSE-EXEC-CAND-01` as recovery-proved/non-stable; no stable repricing. Accounting stays **60 / 16 / 44**, debt 1.
- Promoted package/source `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` as current reviewed M6 runtime authority.
- Exact next: runtime-free `M6-CP1-CLOSE-REV`; CP1 remains active until its six exit items and current-HEAD close obligations are independently discharged.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-R1-EXEC` COMPLETE — 479/479 GREEN

- Candidate `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`; runtime run/job `37280517630 / 111667316992`.
- Result/log artifacts `11333591947 / 11333547162`, provider SHA-256 `ef5dba1131f25025bc536ba160475191629cc8bffed0465a087dd72fc4d1474b / dd78296134b6e71d2080ab2b1b6623841f75725e6a43deffe6ec2ad50dd46e53`.
- Focused30 **30/30** and selector449 **449/449** = **479/479 PASS**; exact-one, zero skips, benchmark 0. Result self-manifest **497/497** (`9d7f244f...a4bd67`); immutable postflight PASS.
- Identity29 RA-27a recovery and identity30 both GREEN. Zero RED rows; no new regression candidate/event; stable accounting remains **60 / 16 / 44**, debt 1.
- EXEC grants no promotion. Exact next is mandatory runtime-free `M6-CP1-TB12-CLOSE-R1-REV`; CP1 close Review remains held.

## 2026-10-05 — `M6-CP1-CB12-CLOSE-R2` COMPLETE: RA-27a recovery compiled and packaged

- Replaced A7's per-occurrence `has any isolation transition` wedge proxy with exact member-local sheet-graph connectivity over region-matching `cornerWedgeIsolation`; rejection site is `cross-sheet:wedge`.
- Corrected C4 diagnostic name to `QuotientClosedComplexStripContinuationMismatch`; selected-forest cross-sheet edge semantics remain unchanged.
- Recovered identity29 with baseline A5→A6→A7 acceptance, bridge-wedge-only tamper, A5 republish, fresh A6 production/success, then exact A7 wedge rejection. No stale A6 is reused.
- Verified frozen focused30 / selector449 / routing449 hashes unchanged.
- Drive patch apply run/job `37277892065 / 111658980414` produced semantic source `3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`; owner-authorized Drive deletion completed.
- Compile run/job `37278068286 / 111659540374` passed all eight standard GMP/GMPXX targets. Result/log `11330703256 / 11330837905`; package 28/28; clean source receipts; `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next: immutable `M6-CP1-TB12-CLOSE-R1-EXEC` at 479 processes, then mandatory R1 Review. Accounting remains **60 / 16 / 44**, debt 1.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-REV` review-agent addendum: RA-27 withdrawn → RA-27a; R2 re-scoped

- **Re-derived independently:** result `11326949864` (`da42bf2a`) and log `11328055226` (`70880747`); 979/979; focused-30 and selector449 ledgers in frozen order; 478/479; ordinal 29 fails before its tamper. Candidate `02149f15` source == HEAD.
- **Code review:** C2 and C3 accepted. C4 fails closed, but its name lacks the `Quotient` prefix and the branch has no executed falsifier.
- **CAND-01 cause corrected:** the split-isolation fixture has no disjoint-sheet relation (the diagonal seam crosses cells; crossings happen inside bridge corners), so forest selection is irrelevant. RA-27 §2–§3 are withdrawn.
- **High:** C1 left the reachable per-occurrence wedge proxy (`RemeshPipeline.cpp:6884-6895`) in place, and neither A5 publication nor A6 checks it. **RA-27a** requires:
  - an exact wedge rule (site `cross-sheet:wedge`);
  - the C4 name fix;
  - identity 29 on a bridge-member tamper with A6 re-produced (consistent chain).

  The edge-rule falsifier is deferred.
- **Observations:** OBS-01 (A6 has no binding to its A5) and OBS-02 (relation-kind-agnostic edge rule).
- **Docs:** R2 plan review-agent block; lesson 199; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §47. Accounting 60 / 16 / 44.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-REV`: identity29 is a fixture-witness false rejection; RA-27 recovery

- Independently re-derived TB12 478/479 and exact ordinal29 failure before the C1 tamper.
- The split-isolation fixture is not contractually required to put a cross-sheet relation in A6's selected spanning forest; absence of that selected edge is not a production-selection defect.
- CAND-01 -> **FALSE REJECTION / TEST-FIXTURE WITNESS DEFECT / RECOVERY REQUIRED / NON-STABLE**. Candidate remains unpromoted; C1 negative runtime proof remains outstanding.
- RA-27 authorizes test-only `M6-CP1-CB12-CLOSE-R2`; no production change. Recovery gate remains focused30 + selector449 = 479, then mandatory R1 Review. Accounting 60 / 16 / 44, debt 1.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-EXEC`: mechanically valid 478/479; identity29 witness non-vacuity RED

- Runtime `37266239234 / 111623615471`: focused30 **29/30**, selector449 **449/449**, aggregate **478/479**, exact-one, zero skips, benchmark 0, 979/979 evidence and immutable postflight.
- Sole RED identity29 has no selected cross-sheet forest edge; its C1 tamper is never reached.
- Recorded non-stable Review-owned CAND-01; stable accounting **60 / 16 / 44**, debt 1. Candidate unpromoted; exact next `M6-CP1-TB12-CLOSE-REV`.
- Earlier run `37264751953` was startup-invalid with zero jobs due unquoted YAML colon; corrected and schema-validated before runtime.

## 2026-10-05 — `M6-CP1-CB12-CLOSE-R1`: C1–C4 compile/package GREEN; TB12 next

- Implemented exact A7 cross-sheet isolation-transition connectivity, distinct A5 source diagnostics, A5-owned validated isolation-certificate accounting, and RA-25 fail-closed strip-continuation ambiguity.
- Added identities 29/30 and focused-30 (`1e815443...a1d6`) with exact focused-28 prefix. C5 remains discharged by RA-26; optimizer/final validation unchanged.
- First compile-only run `37259162318` exposed one pointer member-access typo; bounded one-line correction produced final source `02149f1518fc6a753acf3235f7dcdc6fcdf59f24`.
- Compile/package run/job `37259524323 / 111603703243` GREEN for all eight GMP/GMPXX targets; result/log `11324028392 / 11323679468`, 28/28 manifest, clean source, `runtimeExecution=false`.
- Exact next: immutable artifact-only `M6-CP1-TB12-CLOSE-EXEC`, gate **479**, then mandatory Review.

## 2026-10-05 — `M6-CP1-CB12-CLOSE-REV`: CB12 C5 stop discharged; RA-26; successor `M6-CP1-CB12-CLOSE-R1`

- **Source authority:** HEAD source is byte-identical to the reviewed runtime `8dd95821` (both fetched by SHA after the history squash).
- **Flagged site reclassified:** `SurfaceMeshOptimizer.cpp:3015-3031` reads source-mesh incidence, not a provenance face, and is test-only (`make_surface_optimization_overlay` has no production caller). OBS-01 → M8-CP2.
- **Full audit** of 12 optimizer and final-validation sites: no authority-deciding consumer.
  - Optimizer energy/gradient (corner 0's representative face for normal and field) and the field-metric fallback are reference-selecting.
  - **RA-26** re-homes them to `M6-DEFN-R5` / `M6-CP3`, with a representative-permutation falsifier.
- **CB12 plan:** gains an RA-26 header block. C5 is discharged; R1 runs C1–C4 and identities 29/30 with no optimizer change.
- **Docs:** new Review record `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md`; lesson 198; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0, OBS-01/02) / consolidated §44. Accounting 60 / 16 / 44.

## 2026-10-05 — Workflow mailbox becomes authoritative run-discovery process

- Added durable `.github/workflows/workflow-mailbox-publisher.yml` from the approved GitHub connector workflow-mailbox protocol.
- Updated ChatGPT Web workflow, tool-conservation, cleanup, retention, start/end, handoff, agent and compile policies so `.workflow-mailbox/<workflow-key>/latest.json` is the authoritative completed-run rendezvous; immutable per-attempt records remain under `runs/`.
- PR run-observer comments are now fallback-only. Repository-wide recent-run discovery and the legacy branch-file observer remain secondary/tertiary fallback paths when mailbox publication is absent or fails.
- Updated source-snapshot and turn-cleanup workflows to publish mailbox records after their artifacts; observer fallback executes only when mailbox publication fails.
- Smoke validation: source-snapshot run `37251013709` published `repo-source-snapshot/latest.json` for exact source/event SHA `3d3ddcef4b7cb60d72dc5aee6a2c774dce8b04f2`; validate, snapshot and mailbox jobs all succeeded; fallback observer was skipped.

## 2026-10-05 — `M6-CP1-CB12-CLOSE` stopped at C5 audit

- Found an anchor-assuming optimizer consumer at `SurfaceMeshOptimizer.cpp:3015-3031`: first incident source face -> one component/sheet scope -> break.
- RA-22b / RA-25 and the CB12 plan require Stop for Review and forbid fixing it inside CB12.
- No C1-C4 code/test edits, identities 29/30, compile/package, or runtime started. Reviewed runtime stays 477/477; accounting 60 / 16 / 44, debt 1.

## 2026-10-05 — `M6-CP1-TB11-G4-R1-REV` review-agent addendum: promotion confirmed; RA-25; successor `M6-CP1-CB12-CLOSE`

- **TB11-R1 re-derived independently:** result `11316968568` digest `1082edce...`, 973/973 manifest, focused-28 and selector449 ledgers in frozen order (477/477), ordinals 25/28 OK; HEAD == `8dd95821`.
- **Confirmed:** the RA-24 production change (vertex-incident edge-loop continuation; nothing else changed) and the identity 25/28 oracles.
- **M1:** the continuation drops non-unique opposites silently (`RemeshPipeline.cpp:6305`). **RA-25** makes it fail closed.
- **Successor re-routed** to close-out CB12, because the CP1 carried obligations need code:
  - exact A7 cross-sheet certification through `fromSheet/toSheet`;
  - distinct A5 diagnostics;
  - A5-sourced isolation counter;
  - RA-25;
  - provenance-face consumer audit.

  New plan `Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md`; gate 479.
- **Docs:** lesson 197; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §43. Accounting 60 / 16 / 44.

## 2026-10-04 — `M6-CP1-TB11-G4-R1-REV` accepted recovery and promoted R1 runtime

- Independently re-derived candidate `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` and runtime `37240414090 / 111547976292`: package 28/28, result 973/973, focused28 28/28 + selector449 449/449 = **477/477**, exact-one, zero skips, benchmark 0, immutable postflight.
- RA-24 is discharged: production strip closure is edge-loop continuation at interior valence-4 quotient vertices; identity28 independently reconstructs the partition, validates emitted candidates, requires a produced eligible closed loop and reaches tamper rejection.
- RA-21c/RA-21d is discharged: identity25 uses per-occurrence arrangement witnesses, exact reciprocal phase-front/relation authority and barrier-only relaxation; Ordinary non-isolation chain/node equality remains exact.
- Closed CAND-01 as recovery-proved false-rejection/non-stable and CAND-02 as recovery-proved production-definition defect/non-stable; no stable repricing. Accounting remains **60 / 16 / 44**, debt 1.
- Promoted `11316716869 / 8dd958...` as current reviewed M6 runtime authority. Authorized exact successor `M6-CP1-CLOSE-REV`; CP1 is not yet closed.

## 2026-10-04 — `M6-CP1-TB11-G4-R1-EXEC`: 477/477 artifact-only recovery gate GREEN

- Executed immutable candidate `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` at run/job `37240414090 / 111547976292`.
- Focused28 **28/28**, selector449 **449/449**, aggregate **477/477 PASS**; exact-one selection, zero skips, benchmark 0, header-only RED ledger.
- Ordinals 25 and 28 both PASS under the strengthened R1 identities.
- Result/log artifacts `11316968568 / 11317493022`; result self-manifest **973/973**; package/source/execution-view and frozen gate authorities unchanged.
- No configure/compile/relink/discovery/repair/mutation/retry occurred in EXEC. +0 new regression events/candidates; stable accounting remains **60 / 16 / 44**, debt 1.
- Candidate remains unpromoted. Exact next after cleanup is mandatory `M6-CP1-TB11-G4-R1-REV`.

## 2026-10-04 — `M6-CP1-CB11-G4-R1` COMPLETE: RA-24 / RA-21d recovery compiled and packaged

- Replaced quad-opposite rung-set strip closure with RA-24 edge-loop continuation at interior valence-4 quotient vertices; no other production behavior changed.
- Identity25 now uses per-occurrence arrangement witnesses and retains exact shared chain/node equality only for Ordinary non-isolation edges; HardRail, Periodic and isolation seams are validated per-side.
- Identity28 independently reconstructs the produced-torus edge-loop partition, validates every emitted candidate, requires an eligible `ClosedLoop`, and keeps hard-feature tamper rejection.
- Pre-apply static review caught a missing `<numeric>` include and corrected it before repository application.
- Patch apply run/job `37238821980 / 111543246587` produced semantic source `8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`; owner-side Drive cleanup succeeded.
- Mandatory compile run/job `37238936105 / 111543578349` passed all eight standard GMP/GMPXX targets. Result/log artifacts `11316716869 / 11316583672`; package manifest 28/28; clean receipts; `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next is `M6-CP1-TB11-G4-R1-EXEC`, focused28 + selector449 = **477**, then mandatory Review. Accounting remains **60 / 16 / 44**, debt 1.

## 2026-10-04 — `M6-CP1-TB11-G4-REV` review-agent addendum: F2 overturned (RA-24 edge-loop strips); RA-21d; R1 re-scoped

- **TB11 re-derived independently:** result `11312313559` digest `7de4a320...`, 973/973 manifest; RED at focused 25 and 28; selector449 449/449.
- **F2 overturned.** Ordinal 28's `extracted.candidates` is empty, not "no eligible emitted candidate".
  - R4 D3 §4.3 rule 7's quad-opposite closure (`RemeshPipeline.cpp:6289-6291`) yields rung sets.
  - The path-degree classifier (`:6343-6436`) skips them, so there are zero candidates on any closed quad complex.
  - RA-23's synthetic 4×4 torus would fail identically, and the test-only R1 was doomed.
  - **RA-24:** edge-loop (strand) closure, the topology analogue of the retired `(family, strand)` connected curves. The produced torus is expected to yield eligible loops parallel to its hard cycles.
- **F1 confirmed.** RA-21d keeps arrangement chain and node equality across Ordinary non-isolation edges; relaxation applies only across barrier seams.
- **R1 plan re-scoped:** R1-0 changes the production strip relation only; identity 25 per RA-21c/d; identity 28 uses the produced torus.
- **Accountability:** R4 D3 rule 7 was accepted by R4-REV (review agent). Lesson 196.
- **Docs:** handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §41. Accounting 60 / 16 / 44.

## 2026-10-04 — `M6-CP1-TB11-G4-REV` rejects CB11 candidate; RA-21c / RA-23 recovery frozen

- Independently re-derived TB11: candidate 28/28, result 973/973, focused **26/28**, selector449 **449/449**, aggregate **475/477**, exact-one, zero skips, benchmark 0 and immutable postflight.
- Ordinal25 is a false rejection: RA-21b conflated quotient identity across distinct relation-cut occurrences with physical arrangement-node/chain identity. RA-21c replaces the oracle with per-occurrence/per-side degree-2 arrangement witnesses plus reciprocal A4 and A5/A6 relation authority.
- Ordinal28 is a definition/fixture-witness gap, not a demonstrated extractor defect. The old arrangement `(family,strand)` candidate does not prove non-vacuity under quotient opposite-edge strip closure. RA-23 separates produced-torus universal checks from CP1 mechanism-only non-vacuity/tamper on a canonical closed 4x4 toroidal A6 test view.
- `M6-CP1-TB11-G4-EXEC-CAND-01` closed false-rejection/non-stable; CAND-02 reclassified non-stable definition-witness recovery. Stable accounting remains **60 / 16 / 44**, debt 1.
- Candidate `11308472138 / 582da20a...` remains unpromoted; reviewed runtime remains `11299078582 / 96b456f9...`. Exact next is `M6-CP1-CB11-G4-R1` (test-authority recovery only), then unchanged 477 TB gate and mandatory R1 Review.

## 2026-10-04 — `M6-CP1-CB11-G4` COMPLETE: A6 closed-complex boundary compiled and packaged

- Implemented the RA-20/RA-21/RA-21b A6 `SurfaceQuotientClosedComplexView`, including canonical side-incidence edges, certificate-derived relation labels, explicit typed-source hard-feature protection, quotient lineage and opposite-edge strip closure.
- Candidate extraction now consumes the A6 closed-complex view directly and does not require retained arrangement authority.
- Added focused identities 25-28. Focused28 SHA-256 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`; focused24 is its exact prefix.
- First compile exposed only test/API compile-contract defects. A bounded runtime-free correction produced semantic source `582da20a925ba920c923bf5aacb9e0e56ef0723d`.
- Final compile run/job `37216400150 / 111477707423` passed all eight standard GMP/GMPXX targets. Result/log artifacts `11308472138 / 11308317584`; 28/28 manifest; clean source receipts; `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next is `M6-CP1-TB11-G4-EXEC`, focused28 + selector449 = **477**, then mandatory Review. Accounting remains **60 / 16 / 44**, debt 1.

## 2026-10-04 — `M6-CP1-TB10-A5V-R1-REV` review-agent addendum: promotion confirmed; RA-21b readies CB11

- **TB10-R1 re-derived independently:** result `11300407906` digest `b9f2daed...`, 965/965 manifest, focused-24 and selector449 ledgers in frozen order (473/473), focused 20/24 OK; HEAD == `96b456f9`.
- **R1 confirmed:** publish first, then the moved checks on the published complex (`RemeshPipeline.cpp:4937-4951`, `:3467`, `:3603`).
- **Identity 24 confirmed** to assert every field of the result, mesh and both lineage structs.
- **CB11 pre-analysis:**
  - proposals map positionally to `phaseFront.cells()` with no `CellId` (`SurfaceCellTracing.cpp:17901-17916`);
  - `halfedge.proposalId` is the primary entry only (`SurfaceArrangement.cpp:2426`; the provenance groups are at `:2701-2709`);
  - cell sides are per-face polylines.
- **RA-21b:** positional preconditions, provenance side chains, degree-2-contraction equivalence, chain `hardFeature` labels; RA-21's stop rule kept for every other kind of subdivision. CB11 plan amended.
- **Docs:** lesson 195; handoff live section (it still said CB10-R1) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §39. Accounting 60 / 16 / 44.

## 2026-10-04 — `M6-CP1-TB10-A5V-R1-REV` accepted recovery and promoted R1 runtime

- Independently re-derived candidate `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` and runtime `37194004252 / 111411987330`: package 28/28, result 965/965, focused24 24/24 + selector449 449/449 = **473/473**, exact-one, zero skips, benchmark 0, immutable postflight.
- F1/RA-19 is discharged: A5 publication precedes moved validation and the helper consumes the published complex certificate/cells/occurrences.
- F2 is discharged: identity24 independently covers every adapter-written result/mesh/vertex-lineage/face-lineage field.
- Closed TB10 Review CAND-01/CAND-02 as recovery-proved/non-stable; no stable repricing. Accounting remains **60 / 16 / 44**, debt 1.
- Promoted `11299078582 / 96b456...` as current reviewed M6 runtime authority. Authorized exact successor `M6-CP1-CB11-G4`; TB11 is 28+449=477 then mandatory Review.

## 2026-10-04 — `M6-CP1-TB10-A5V-R1-EXEC`: 473/473 artifact-only gate GREEN

- Executed immutable R1 candidate `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` at run/job `37194004252 / 111411987330`.
- Focused24 **24/24**, selector449 **449/449**, aggregate **473/473 PASS**; exact-one selection, zero skips, benchmark 0, header-only RED ledger.
- Result/log artifacts `11300407906 / 11300542138`; result self-manifest **965/965**; package/source/execution-view and frozen gate authorities unchanged; package manifest remains **28/28**.
- No configure/compile/relink/discovery/repair/mutation/retry occurred in EXEC.
- +0 new regression events/candidates; stable accounting remains **60 / 16 / 44**, debt 1. Existing TB10 Review CAND-01/CAND-02 remain open for mandatory R1 Review.
- Candidate remains unpromoted. Exact next after EXEC cleanup is `M6-CP1-TB10-A5V-R1-REV`; CB11 held.

## 2026-10-04 — `M6-CP1-CB10-A5V-R1` COMPLETE: RA-19a ordering / full projection oracle; compile-package GREEN

- Restored RA-19a validation precedence: `publish_records_for_validation` now precedes moved phase-front checks, and the helper consumes the published `SurfaceOccurrenceComplex`, including certificate-directed side count and published cells.
- Strengthened `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` to the TB10 Review §J3 exact field-table oracle using independent A5/A6/A7/A4-derived expectations and fixed/default compatibility values.
- Preserved focused24/focused20/selector449/routing449 hashes exactly: `6bcc8a...067bf / 15d04a...827d2 / d4a0d1...d6414 / 9c88a5...6c5707`.
- Drive patch `d1880a55...faeb` applied in run/job `37192632740 / 111407894004`, producing semantic commit `96b456f925be00e00bad6645e6eb905a804c14ea`; owner-side Drive deletion succeeded.
- Mandatory compile run/job `37192727051 / 111408174395` passed all eight standard GMP/GMPXX targets. Candidate artifact `11299078582` (`sha256:142bac1b...5afd`), log `11299068422` (`sha256:1ede0d09...b6c50`), manifest 28/28, clean source receipts, `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next is `M6-CP1-TB10-A5V-R1-EXEC`, focused24 + selector449 = **473**, then mandatory Review; CB11 held.

