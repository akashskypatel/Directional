# `M6-CP2-DEFN-REV` — Independent Review of the CP2 Verifier Definition

**Turn:** `M6-CP2-DEFN-REV` (runtime-free Review)

**Reviewed:**
- `Architecture_M6_CP2_Definition_Record.md`;
- RA-28;
- the held `Architecture_M6_CP2_CB1_Verifier_Code_Build_Plan.md`;
- against frozen §6 (A8-M6), §10, RA-17, RA-26 and RA-27a/b, and exact source.

**Source authority.** Branch HEAD at review start. Its `src/`, `include/` and `tests/` are byte-identical to the reviewed runtime `3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` (479/479).

**Disposition: ACCEPTED WITH BINDING AMENDMENTS (RA-28a).**
- The overall architecture is sound:
  - a record-view negative seam with no unchecked factory;
  - C4 accepted-defensive, with verifier manifoldness as its falsifier;
  - three targeted wedge tampers;
  - A8 after A7 and before projection;
  - gate 30 + 12 + 449 = 491;
  - a mandatory Review chain.
- **But:**
  - the verifier as defined cannot detect a non-exact-once ledger or an unsupported union;
  - its certificate binding is undefined at the field level;
  - it trusts self-declared A5 wedge evidence;
  - and three API/test designs would be vacuous or would regress accepted rows.
- RA-28a fixes all of these **without new identities**, so the gate stays **491**.
- `M6-CP2-CB1-VERIFIER` is authorized under RA-28 + RA-28a.
- Accounting **60 / 16 / 44**, debt 1.

## 1. What the Definition got right (verified)

- **D1 seam.** Products are built only through private, validating construction. A5 `publish_records_for_validation` (`RemeshPipeline.cpp:3628-3766`), A6 (`:5572+`) and A7 each validate before construction. Copy-by-value record views with no view→product conversion are the right seam: they make §6.3 negatives reachable without weakening producers.
- **D2.** A6 recomputes the class partition from owned relations (`:5810-5890`) and builds the closed-complex view only after base validation (`:6368-6380`). So C4 (`:6302-6333`) is unreachable without forging a relation. Accepting C4 as defensive, and falsifying pinched topology through verifier manifoldness on a record view, is correct.
- **D3.** All three tampers target conjuncts that identity 29 does not pin. I confirmed statically that **no stage between A5 publication and A7's wedge rule** cross-checks `cornerWedgeSheets` against `cornerWedgeBindings`, or checks `transition.region`. So the tampers reach `cross-sheet:wedge` and are not shadowed.
- **D4 placement** (after A7, before projection) matches frozen §6: A8 consumes A0/A5/A6/A7. The stop rule (any accepted 479 row rejected → Review) is right.
- **D5 arithmetic:** 30 + 12 + 449 = 491. The prefixes stay byte-exact, and the identities are enumerated.

## 2. Findings

### F1 (High) — the verifier cannot detect a non-exact-once ledger or an unsupported union

§2's binding is one-directional: "every A6 certificate/consumption must cite one exact A5-owned relation". Nothing requires:
- (a) every A5-owned relation to have **exactly one** certificate and **exactly one** consumption;
- (b) the selected forest to be exactly the `Joining` consumptions;
- (c) each class to be **spanned** by its own published forest edges;
- (d) each `CycleClosing` relation to be closed by its class path (RA-13's strict rule).

Without (a), a dropped relation passes. Without (c), the §6.3 row "union occurrences → `QuotientMembershipMismatch`" has **no detection predicate**: a class that merges two components with no forest edge is read "by published IDs" and accepted.

These are the central M6 invariants (frozen §4.4; CP3 exit "every A5-owned relation is consumed exactly once"). All four are elementary ID/set checks over published records. Checking that a *published* forest spans a class is verification; it is not the producer's union-find selection.

**Fix:** RA-28a §1.

### F2 (Medium–High) — "byte-semantic payload equality" is undefined at the field level

A6 certificates hold A6-typed fields (`relationTransport`, `evidence`, `selectedRelationStep`; `RemeshPipeline.h:1029-1045`). "Equal the A5 relation" doesn't say which fields correspond. An implementer would either compare unlike types (always false) or reproduce A6's construction (forbidden by §6.2).

The source shows the correspondence is **verbatim**: A6 copies `id`, `id.first`/`id.second`, `evidence.equivalence`, `evidence.canonicalSelectedStep` and `evidence.canonicalTransport` (`:5219-5224`, `:5338`, `:5365`), and its own publication checks the same equalities (`:5770-5795`).

**Fix:** freeze the exact field table in RA-28a §2. Representation-only fields (front edges) are excluded.

### F3 (Medium–High) — A5 wedge evidence is self-declared; the verifier must cross-check it against A0

RA-27a's exact wedge rule checks connectivity over each occurrence's **own** `cornerWedgeSheets` and `cornerWedgeIsolation`. No stage checks that:
- those sheets are the sheets of the wedge's binding faces;
- each transition's seam is an A0 isolation seam between those sheets.

A record with a phantom sheet plus a matching phantom transition therefore passes every stage. The A5 producer derives these correctly by traversal (`:4395-4470`), but the CP2 verifier is the only independent certifier, and its matrix omits them. Frozen §6.2 also lists "exact incidence of a published `SourceSupport`" generally, but the matrix applies it only to A7.

**Fix:** RA-28a §3.

### F4 (Medium) — the finding set isn't determined for dependent failures

§1.2 allows multiple findings and forbids repair, but says nothing about checks whose prerequisites failed. Example: a missing occurrence makes every later lookup undefined. The finding set, and identity 1's permutation invariance, would then depend on implementation order.

**Fix:** freeze dependency gating (RA-28a §4).

### F5 (Medium) — two failure codes have no valid predicate

- `ForbiddenGeometricWeld` would need the verifier to tell that a collapse was *caused* by geometry. That requires consulting geometry, which §6.3 forbids. A weld shows up combinatorially as F1(c) (class not spanned) or as `NonManifoldTopology`.
- `UpstreamFailureSubstitution` is unreachable by API shape (§1.4 says so).

Runtime codes with no reachable or definable predicate are dead diagnostics (lesson 181 family).

**Fix:** RA-28a §5.

### F6 (Medium) — identity 11 cannot observe placement at runtime

Valid products always verify. "Verifier ran before projection" therefore cannot be falsified behaviorally without an injection hook, and identity 11 would drift into a source-structure test (rejected precedent: `M6-DEFN-R4-REV` F5). Placing A8 *inside* the transitional adapter body also couples it to code M8 will remove.

**Fix:** make the order a **type invariant** (RA-28a §6).

### F7 (Medium) — the RA-26 §5(iii) optimizer change regresses non-authoritative callers unless gated

`SourceVertexChartAuthority` has a `retained` flag (`SourceAuthoritativeMeshValidator.h:63-67`). It is populated only on the authoritative path (`RemeshPipeline.cpp:12868-12872`, `:15548-15551`). Non-authoritative optimizer callers (selector rows in Phase19/21/22) have no class authority, so an unconditional membership check would reject every projection.

The class-wide membership test also assumes the representative `sourcePoint.face` is one of the class's `sourceCharts` faces. That is unproven: it depends on `CornerPlacementProvenance.selectedFace` lying in the wedge bindings.

**Fix:** RA-28a §7.

### F8 (Low) — tamper specifications need precision to avoid another CAND-01

- **"Touches":** **every** bridge transition must become (in-set, out-of-set). A single surviving connecting transition makes the test vacuous.
- **Three-sheet:** the phantom sheet must be inserted **in sorted position**, because `wedge_contains_sheet` uses `binary_search` (`:5045-5049`). Otherwise the rejection can come from the sort precondition rather than from connectivity.
- **Wrong-region:** use a valid `TopologyRegionId` different from `occurrence.topologyRegion`, and keep both sheets in the set, so that only the region filter can reject.

**Fix:** RA-28a §8.

### F9 (Low) — A0 and the adapter failure string are unspecified

`verify(A0, …)` names no concrete A0 type. The adapter mapping of a `VerificationFailure` is unspecified, and the adapter has already dropped A7 sites once (`M6-CP1-TB12-R1-REV-OBS-02`).

**Fix:** RA-28a §9.

## 3. Amendments

Full text is in `Architecture_M6_Frozen_Definitions.md` RA-28a. Each amendment folds into an existing identity, so the count stays 12.

| RA-28a § | Finding | Identity that carries it |
|---|---|---|
| §1 exact-once / forest / spanning / cycle | F1 | 3, 6 |
| §2 field table | F2 | 6 |
| §3 A5 wedge and support vs A0 | F3 | 2 |
| §4 dependency gating | F4 | 1, 5 |
| §5 code set | F5 | 5 |
| §6 `VerifiedSurfaceProducts` | F6 | 11 |
| §7 optimizer gating | F7 | 12 |
| §8 tamper precision | F8 | 8, 9, 10 |
| §9 A0 type and failure string | F9 | 2, 11 |

## 4. Closeout

| Duty | Result |
|---|---|
| Definition read in full | D1–D6 and RA-26 §5(iii) checked against frozen §6/§10 and exact source. |
| Source facts re-derived | Product construction seams; the A6 partition check and the post-A6 view (C4 unreachable); verbatim A6 certificate copies and their publication check; no sheet/binding/region check before the wedge rule; `retained` gating of class chart authority. |
| Disposition | ACCEPTED WITH RA-28a; CB1 authorized; gate **491**, unchanged. |
| Owned review-agent items | None new. RA-27b correctly routed these decisions to the Definition. |
| Accounting | 60 / 16 / 44, debt 1. |
| Lesson | 201 — a verifier's binding must be bidirectional, and an exact rule over self-declared evidence needs an independent cross-check against source authority. |
| Successor | `M6-CP2-CB1-VERIFIER` (Code + Build) → `M6-CP2-TB1-VERIFIER-EXEC` (491) → `M6-CP2-TB1-VERIFIER-REV`. |
