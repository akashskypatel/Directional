# `M6-CP1-TB11-G4-R1-REV` — Independent Recovery Review Record

**Turn:** `M6-CP1-TB11-G4-R1-REV`
**Reviewed candidate:** `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`
**Reviewed runtime:** `37240414090 / 111547976292`
**Disposition:** **ACCEPTED / RECOVERY PROVED / CANDIDATE PROMOTED**
**Exact successor:** `M6-CP1-CLOSE-REV`

## 1. Independent evidence re-derivation

The R1 recovery gate is mechanically sound and independently re-derived from immutable artifacts without executing Directional binaries in Review.

- Compile candidate ZIP SHA-256: `35f865b1016a0ec6f0d30b80dd0c33d7a01f9fbfcbb420ee43225398cf75415c`; root manifest SHA-256 `4bf0ca5cd9caae58626b0660eb77466fa88eadf604aaeb657c502e1bbb63598d`, **28/28**; packaged source archive SHA-256 `b0c70a127e1a262761ff0519dd0d0d4d28511f276bfe38f71d2e72249c2b631b`; exact source `8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`; compile boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, GMP/GMPXX and clean source receipts.
- Runtime result/log ZIP SHA-256: `1082edce080e373c062b5c8dc398158d2d4ab92ded669c191b4c6bd9e5668b6e` / `bfaf91db3602fa1535c984afba1378cd47c3090b1658c7cf16b24ce990e19308`.
- Result self-manifest SHA-256 `47d3e333899321da8e8a351849df5abe10407cd1af1864578ac9528c6e6c86d6`, **973/973**.
- Focused ledger: **28/28 PASS** in exact focused-28 order; selector ledger: **449/449 PASS** in exact selector449 order; aggregate **477/477**. Every process selected exactly one test, zero skips, benchmark 0. Raw logs independently contain **477 RUN / 477 OK / 0 SKIP**; RED ledger is header-only.
- Postflight records package/source/execution-view census equality, unchanged focused/selector/routing authority and package manifest **28/28**. Execution boundary records no configure, compile, relink, generated discovery, package/mode repair, source/test/fixture/selector mutation or retry after runtime start.
- Focused ordinals 25 and 28 each select once and pass. Their raw logs show organic completion at 113.979 s and 57.511 s respectively.
- Frozen hashes re-derived: focused28 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

Review source authority is snapshot run/artifact `37244642521 / 11319125271`, event/source `d75dada25389d15ff7caf75e0b99a599a96df486`, provider ZIP SHA-256 `0d7112e0ceb9968f2944fd98f8dbeeab7f63dc26b40d8e7831ebacae4d0b2392`, embedded archive SHA-256 `99772c123df8cab3287265a06ac88143af67cb193ae166b80a749ef94b457f10`, **5353/5353** source-file manifest checks and `runtimeExecution=false`. The first local manifest verification attempt used the wrong extraction root and failed before source inspection; correcting the local extraction layout yielded the authoritative 5353/5353 result without any remote retry or repository mutation.

## 2. RA-24 / CAND-02 — edge-loop strip definition recovery

**DISCHARGED / RECOVERY PROVED.** The exact R1 production delta replaces only the invalid quad-opposite rung-set relation in `build_surface_quotient_closed_complex_view`.

Static re-derivation confirms:

1. the builder constructs the four incident quotient edges at each quotient class;
2. boundary and valence-!=4 vertices are not joined;
3. at an interior valence-4 vertex, each edge is united only with an incident edge sharing no classed quad, which is the RA-24 edge-loop continuation;
4. strip canonicalization still orders components by their smallest `SurfaceQuotientEdgeId` and assigns deterministic ordinals;
5. candidate extraction, protection labels, A5, A6 class/relation construction and A7 are untouched by R1.

The pre-R1-to-R1 semantic source diff is confined to `src/pipeline/RemeshPipeline.cpp` and `tests/SurfaceCellTransitionQuotientTests.cpp`; the production file's R1 blob is `ad46e264a60f0cd0218aa305a19caf8aa336c3e1`. No other `src/` or `tests/` path differs from the frozen pre-R1 snapshot.

Identity 28 independently reconstructs the edge-loop partition from edge incidence and classed-quad ownership rather than calling production strip construction. It checks every emitted candidate against independently derived strip membership, edge existence, global valence, boundary, hard-feature, side-cell, periodic-relation and path-degree facts; it requires a produced-torus eligible `ClosedLoop`; and a one-edge `hardFeatureProtected=true` tamper makes that loop independently ineligible and absent. The immutable runtime PASS therefore reaches both the non-vacuity and tamper falsifiers that failed before RA-24.

`M6-CP1-TB11-G4-EXEC-CAND-02` is closed as **RECOVERY PROVED / PRODUCTION-DEFINITION DEFECT / NON-STABLE**. Its earlier RA-23 “definition-witness gap” wording is superseded by the TB11 Review addendum and this recovery evidence.

## 3. RA-21c/RA-21d / CAND-01 — arrangement/quotient oracle recovery

**DISCHARGED / RECOVERY PROVED.** Identity 25 now preserves arrangement evidence without conflating physical arrangement identity with quotient identity across certified seams.

Static re-derivation confirms the strengthened oracle:

- one provenance chain is built per `(proposalId, proposalSide)` and checked as a degree-2 subdivision with two endpoints and uniform hard-feature state;
- each A4 corner occurrence gets its own arrangement-node witness from the unique intersection of adjacent side-chain node sets; witnesses are not collapsed by quotient class;
- A6 side IDs map to exact phase-front edges by `(filledCell, filledSide)` and reciprocal `oppositeEdge` ownership is required;
- the two A6 relation certificates must encode exactly the reversed endpoint-occurrence pairs and their typed owner must match OrdinaryFront, HardRail or Periodic authority;
- each side chain's endpoints must equal its two occurrence-node witnesses and chain hard-feature state must equal `hardFeatureProtected`;
- exact chain equality and crossed occurrence-node equality are retained only for `Ordinary` relations with no relation-side/span isolation evidence; HardRail, Periodic and isolation seams are the only relaxation cases.

The test uses exact identities and exact source/authority fields; it does not infer quotient equality from geometry, tolerance or hashes. Focused ordinal25 passes organically in the immutable R1 runtime, discharging the RA-21b false rejection while retaining RA-21d's discriminator on non-barrier Ordinary edges.

`M6-CP1-TB11-G4-EXEC-CAND-01` remains a **FALSE REJECTION / TEST-ORACLE DEFECT / NON-STABLE**, now recovery-proved under RA-21c/RA-21d.

## 4. Scope, regression and authority disposition

The exact R1 patch SHA-256 is `49eb272c5433de5520fadced9615347d93f158f58e6e4ba627b0a549ccddd8ca`; its declared base is `d8b1aff8c12364ed587e61fddb8b3716dd9a57c3`, diff-body SHA-256 `4a13bc081b94335c83e7affcaff1d774a05498677f981247c45f79e53880ad9b`, and intended paths are exactly the two files above. Current file Git blobs match the patch destinations: production `ad46e264...` and tests `4549e1a1...`.

No new runtime RED, orchestration defect, stable event, recurrence, category or debt was observed. Stable accounting remains **60 events / 16 categories / 44 recurrences** and project debt remains **1**.

Candidate `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` is promoted as the current reviewed M6 runtime authority under focused28 **28/28** + selector449 **449/449** = **477/477**.

## 5. Successor and carried obligations

The accepted R1 Review releases the held CP1-close checkpoint. Exact successor is runtime-free `M6-CP1-CLOSE-REV`.

That close Review still owns the previously carried obligations and must not silently discharge them from this gate:

- A7 cross-sheet certification proxy;
- remaining provenance-face consumer audit against multi-sheet A7 classes;
- merged diagnostic-name closeout;
- `consumedInternalIsolationSeams` counter-source audit.

`M6-DEFN-R5` remains the CP3-entry gate for the deferred gauge obligations and A5 barrier-set census. This Review does not close CP1 or discharge project debt; it only promotes the recovered G4 runtime and authorizes the dedicated close Review.

## 6. Review closeout checklist

| Duty | Result |
|---|---|
| Immutable compile/runtime evidence independently re-derived | PASS — 28/28 candidate manifest; 973/973 runtime manifest; 477/477 exact-filter gate |
| RA-24 edge-loop production change | PASS / bounded to the strip relation |
| Identity 28 independent non-vacuity + tamper oracle | PASS / reaches both falsifiers |
| RA-21c/RA-21d arrangement oracle | PASS / barrier-only relaxation retained |
| R1 source/test scope | PASS — exactly one production file + one test file |
| Regression candidates | CAND-01 false rejection recovery-proved; CAND-02 production-definition recovery-proved; both non-stable |
| Stable accounting | 60 / 16 / 44, debt 1 |
| Runtime authority | promote `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` |
| Turn boundary | runtime-free Review; no source/test/fixture/selector/build mutation |
| Successor | `M6-CP1-CLOSE-REV` |

---

## Review-agent addendum (2026-10-05, resumed `M6-CP1-TB11-G4-R1-REV`)

**Disposition:**
- **Acceptance and promotion: CONFIRMED.** Candidate `11316716869 / 8dd95821...` is the reviewed runtime authority (477/477).
- **One fail-closed gap** in the RA-24 implementation (M1).
- **Successor re-routed** from `M6-CP1-CLOSE-REV` to a bounded close-out Code + Build, **`M6-CP1-CB12-CLOSE`**. A runtime-free close Review cannot discharge the carried obligations, because most of them need code (M2).
- Accounting 60 / 16 / 44, debt 1.

### N1. Independent re-derivation (confirmed)

- I downloaded result `11316968568` again. Its ZIP SHA-256 is `1082edce...8b6e`, and `SHA256SUMS` verifies **973/973**.
- The focused ledger is 28/28 PASS in exact focused-28 order (`9154a986...`). The selector ledger is 449/449 PASS in exact selector449 order. No anomalies.
- Raw logs: ordinal 25 `[ OK ]` (114 s), ordinal 28 `[ OK ]` (57.5 s).
- HEAD `src/`, `include/`, `tests/` and `cmake/` are byte-identical to `8dd95821`.

**RA-24 code (confirmed).**
- R1 replaces the quad-opposite union with vertex-incident continuation (`RemeshPipeline.cpp:6278-6311`).
- It skips vertices that are not interior with valence 4, unites each edge with the unique incident edge that shares no classed quad with it, and keeps the ordinal rule.
- Nothing else in production changed.

**Identity 28.** Its independent reconstruction asserts that the opposite edge is unique at every interior valence-4 vertex. It then requires an eligible produced-torus `ClosedLoop`, checks that the one-edge tamper makes it ineligible and absent, and validates every emitted candidate.

**Identity 25** implements RA-21c with RA-21d. Equality is kept on Ordinary edges without isolation evidence.

### N2. M1 — RA-24's production continuation does not fail closed (Low–Medium)

RA-24 defines continuation as "the **unique** other incident edge … that shares no classed quad". When more than one candidate exists, the production code drops the continuation silently (`opposite.reset(); break;`), and when none exists it silently does nothing.

In a valid closed manifold quad complex, the opposite edge at an interior valence-4 vertex is always unique, so ambiguity means the complex is malformed. Silently truncating strips there:
- hides the malformation from every view consumer;
- yields misleading open-strip candidates;
- the extractor can be called on an A6 view without A7's vertex-fan checks.

The test's reconstruction asserts uniqueness, so the produced torus is covered, but production must not depend on a test. **Fix:** a typed A6 error, `ClosedComplexStripContinuationMismatch`, emitted when an interior valence-4 vertex lacks a unique opposite. Owner: CB12-CLOSE (C4).

### N3. M2 — CP1 close needs a close-out Code + Build before the close Review

Successor `M6-CP1-CLOSE-REV` is runtime-free. Its carried obligations:

| Obligation | Needs code? |
|---|---|
| (a) A7 cross-sheet proxy: make it exact, or remove it and state that A6 certifies — RA-22a §3 | yes |
| (b) provenance-face consumer audit — RA-22b §5 | analysis; any defect found → code |
| (c) the three merged A5 diagnostics — RA-19a §3 | yes |
| (d) `consumedInternalIsolationSeams` counter source | yes |
| (e) N2 / M1 | yes |

A runtime-free close Review would therefore immediately authorize a close-out CB. Routing straight to **`M6-CP1-CB12-CLOSE`** saves a turn, and leaves CLOSE-REV as pure verification on a fresh gate.

**Static facts that make CB12 bounded.**
- **(a)** `CornerWedgeIsolationTransition` carries `region`, `seam`, `fromSheet` and `toSheet` (`PureQuadCompletion.h:195-198`). The exact check is feasible: a cross-sheet forest edge needs a transition (relation evidence ∪ either occurrence's `cornerWedgeIsolation`) whose `{fromSheet, toSheet}` maps one endpoint's sheet set onto the other's. Today any transition is accepted (`RemeshPipeline.cpp:~6850-6872`).
- **(b) partial pre-audit.** `project_surface_cell_vertex_chart_authority` (`:8061-8127`) consumes class-wide `lineage.sourceCharts` → **class-wide, safe**. Still to classify:
  - `SourceAuthoritativeMeshValidator::resolve_compatible_chart` (`SourceAuthoritativeMeshValidator.cpp:1210-1262`);
  - the optimizer's source-point rebinding (`SurfaceMeshOptimizer.cpp:2576`, `:3020`);
  - `BenchmarkQuality` (`:1490-1503`).
- **(c)** A5 emits `SourceAuthorityMismatch` for the empty-phase-front and source-shape cases (`:3769`) and `InvalidChartAuthority` for chart transitions (`:3785`). Distinct codes or sites can restore the three legacy names.
- **(d)** The adapter sets the counter from the A4 input count (`:7544`). A5 should publish its validated isolation-certificate count.

### N4. Closeout

| Duty | Result |
|---|---|
| Primary evidence | Digest, 973/973 manifest, both ledgers in frozen order, ordinals 25/28 OK, HEAD == `8dd95821`. |
| RA-24 / RA-21c/d | Confirmed in code and tests. M1: production ambiguity is silent (fix in CB12). |
| Successor | Re-routed: `M6-CP1-CB12-CLOSE` → `M6-CP1-TB12-CLOSE-EXEC` (30+449 = 479) → `M6-CP1-TB12-CLOSE-REV` → `M6-CP1-CLOSE-REV`. |
| Plan | `Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md` written. |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 197 — route a Review successor to the turn type its obligations need. |
