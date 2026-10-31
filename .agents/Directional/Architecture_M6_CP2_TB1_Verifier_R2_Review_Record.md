# M6-CP2-TB1-VERIFIER-R2-REV — Independent Review Record

**Disposition:** ACCEPTED / R3 CANDIDATE PROMOTED / M6-CP2 CLOSED
**Promoted package/source:** `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20`
**Reviewed runtime:** `37403703032 / 112076464024`, **491/491**
**Result/log artifacts:** `11387562709 / 11387233341`
**Exact successor:** `M6-DEFN-R5`

## Review authority

This Review selected `READ_MODE=snapshot` before repository source/document inspection. Exact current review snapshot authority is source/event SHA `b26f19d934dd67e6eae26166200b923a86879e14`, workflow run `37409151437`, artifact `11388097916`, provider digest `sha256:b0154733104278a8963878292789677134a7567be911ab41ae8083c0786f3d3b`, archive digest `8f2736d20f8d75d0b5665d0a0f54d05826c7bd846b3df32e0b4c18d8e0a79ad0`, 5476 files, `runtimeExecution=false`.

The immutable candidate package was independently rechecked from artifact `11385836615`. Its ZIP SHA-256 is `40ea2966011865090ce49382300885ee132e82655fba4f98575f326b53ca2ea4`; root `SHA256SUMS` verifies 28/28; semantic source is exactly `c64baacd6c767c4ba053b6963651c0aa6eceed20`; its source archive SHA-256 is `fb7f08f193aa335944c5a3ff460ef481ec9f1dec6cefba676a563d374305bce9`; the command boundary records `runtimeExecution=false` and `exactArithmeticBackend=GMP`; the eight standard targets and GMP/GMPXX link evidence are present; captured source-status receipts are empty.

The current review snapshot's `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/`, and root `CMakeLists.txt` are byte-identical to the candidate's packaged source on those code surfaces. Static review therefore applies to the exact tested semantic candidate.

## Independent runtime re-derivation

The R2 result ZIP matches `dada6a755d4ec6d695ab2b11b13c6d92452d4b1599e9ebda0e6bee751b23fdcf`; the log ZIP matches `5a6950535ec39f20e776759b0c0f1d241ee5228c346ea4d2afc3fe9fcf0b3c39`. The result self-manifest verifies **1005/1005** and hashes to `82943861e169fcdc8589bf13f0e068a663b837997792c454d7a6efb6b5788d7f`.

Independent ledger/raw-log checks establish focused30 **30/30**, CP2-focused12 **12/12**, selector449 **449/449**, aggregate **491/491**, exact-one **491/491**, zero skips and zero REDs. Every ledger `raw_sha256` matches its raw log; frozen identity/order/owner authority matches; `benchmark_execution=false`; configure/compile/relink/discovery/repair/mutation/retry flags are false; package/source/execution-view censuses are unchanged; postflight manifest remains 28/28.

Frozen hashes remain focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Static adjudication of RA-29b/RA-29c recovery

The implementation is faithful to the frozen recovery and introduces no new Review finding.

1. `a0:component-adjacency` and its disconnected-component identity-2 witness are absent; no replacement rule infers ingress component labels from raw connectivity. Accepted selector449 ordinal144 is green.
2. A5 relations carrying `canonicalSelectedStep` require `canonicalRelationValue`, equal step transport, and `Forward` at `a5:selected-step-value`.
3. A6 reconstructs each path's selected-step subsequence from its own ordered relations/orientations and named certificates, using only step inversion and exact composition, and verifies optionality, ordered steps, composed transport and endpoints at `a6:legacy-projection`. The A6→A5 table still exact-binds `selectedRelationStep`.
4. A7 expected paths are grouped once by class from A6 `legacyProjection`s, sorted/deduplicated, and compared exactly at `a7:selected-paths`. The rejected reverse lookup/fallback, target-uniqueness assumption and per-A7 all-path scan are gone; complexity is O(P log P).
5. Relation-class, forest-size/spanning, selected-path reconstruction and map-based topology obligations remain intact.
6. Shared support authority, carried verification report and verified-token downstream reads remain intact.
7. `VerifiedSurfaceProducts` owns A5/A6/A7 values; the self-declared trait is gone. Identity 11 proves address inequality plus record-view equality.
8. Identity 6 retains baseline, relation-transport and >=2-step structure tampers and adds record-changing A7-step, A6-legacy-step and A5-value-only tampers at the three RA-29c sites. All focused12 rows are green.

No A5/A6/A7 producer semantic change was introduced by R3.

## Prior finding closure

- **R1-REV-01:** CLOSED / RECOVERY PROVED — lossy A7→A6 reverse lookup removed; formerly affected accepted rows are green.
- **R1-REV-02:** CLOSED / RECOVERY PROVED — invalid raw-connectivity component rule removed; selector144 is green.
- **R1-REV-03:** CLOSED / RECOVERY PROVED — focused12 identity 6 baseline/tamper chain is green.
- **EXEC-OBS-01:** CLOSED / ORCHESTRATION RECOVERY PROVED — R2 uses its own `TURN_ID`; both result/log artifacts exist and verify.
- **RA-29c T3/T5:** CLOSED — fallback and O(V·P) scan are absent; ownership is behavioral.

These were non-stable recovery/specification defects. No new regression candidate or architecture-debt item is created. Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**.

## Promotion and routing

Candidate `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` is **PROMOTED** as reviewed M6-CP2 authority. M6-CP2 is closed. The exact successor is **`M6-DEFN-R5`**; that turn is not begun inside this Review.

---

## Review-agent addendum (2026-10-06, resumed `M6-CP2-TB1-VERIFIER-R2-REV`)

**Disposition:**
- **Promotion of `11385836615 / c64baacd` as reviewed runtime authority: CONFIRMED.** 491/491, every R1 recovery item is closed, and no false rejection remains.
- **"M6-CP2 CLOSED": REVOKED. CP2 stays ACTIVE.** The frozen CP2 exit (§10: "independently recomputes … §6.2 elementary facts and fails typed on **every** §6.3 malformed-authority class") is not met:
  - one RA-28a §2 A7 binding is unimplemented (U1);
  - most verifier predicates have no executed negative witness, and identity 5 tests one of ten §6.3 classes (U2);
  - two runtime codes are dead (U3).
- **RA-29d** routes a bounded completion: `M6-CP2-CB2-COVERAGE` → TB (491) → `M6-CP2-CLOSE-REV`, with a closure record.
- Accounting **60 / 16 / 44**, debt 1.

### U0. Independent re-derivation (confirmed)

- Result `11387562709`: ZIP `dada6a75...`. Log `11387233341`: ZIP `5a695053...`.
- `SHA256SUMS` (`82943861...`) verifies **1005/1005**.
- focused-30 (`1e815443`), focused-12 (`2aa57aac`) and selector449 (`d4a0d1b7`) ledgers are each in exact frozen order. Every row has exactly one selection, zero skips and PASS. **All 491 raw-log hashes match.**
- Candidate `c64baacd` source == HEAD. The R3 diff from `9c8478ae` touches the verifier and tests only (−2 header lines).
- **RA-29c is implemented as specified:**
  - `a5:selected-step-value`;
  - `a6:legacy-projection`, reconstructed along each path's own relations;
  - `a7:selected-paths`, grouped by class and sorted-unique.

  The reverse lookup, fallback and O(V·P) scan are gone, and identity 11's ownership check is behavioral.

### U1 (High) — RA-28a §2's A7 vertex binding is not implemented

RA-28a §2 requires that "each A7 vertex's class equals one published A6 class (ID and member set); **its support equals the common A5 member support (RA-18)**". The A7 partition (`RemeshPipeline.cpp:8157-8222`) checks:
- `sourceOccurrences == members`;
- `vertex.support == resolve(vertex.sourcePoint)` (shared kernel);
- that every member's support equals the **support certificate's** `publishedSupport` (`:8204`).

It **never** checks:
- `vertex.support == publishedSupport` (or == the members' common support);
- `vertex.representative ∈ members`;
- `vertex.sourcePoint ==` the representative occurrence's published `point`;
- `vertex.position == vertex.sourcePoint.position`.

**Witness:** move one class's A7 vertex to an unrelated but self-consistent source point (any other face, with its kernel-resolved support). Every A7 check passes. This is the geometric weld that A7 and CP1 item 6 rule out. The verifier, the only independent certifier, cannot see it.

This is an implementation omission against frozen text. TB1-REV, R1-REV, R2-REV and my own addenda all missed it.

### U2 (High) — CP2's exit criterion has no executed negative coverage

**Counts.** Of about 56 verifier failure sites, about 14 are referenced by any test. By failure code:

| Production sites | Codes | Test references |
|---|---|---|
| 4 | `OccurrenceOwnershipMismatch` (§6.2 occurrence ownership counts) | **0** |
| 5 | `MissingPublishedAuthority` (the §6.3 "infer missing endpoint/owner/…/relation" class) | **0** |
| 19 | `QuotientMembershipMismatch` | 2 |

**Untested negatives** (sites with no test anywhere):
- the RA-28a §1 core: `a6:exact-once-ledger`, `a6:forest-joining-set`, `a6:forest-cardinality`, `a6:forest-endpoints`, `a6:duplicate-certificate` / `-consumption`;
- A5: `a5:corner-owner`, `a5:exact-corner-ownership`, `a5:directed-side-cycle`;
- A7: `a7:support-cover`, `a7:class-cover`, `a7:topology-copy`;
- certificates: `certificate:a5`, `certificate:a6`.

**Identity 5** (`VerifierRejectsEveryForbiddenRepairClassWithoutMutation`, `tests/…:7647-7663`) applies **one** tamper: a duplicated class member → `SemanticIdentityMismatch`, plus a non-mutation check. The Definition (§1.4) claimed every §6.3 class "has a reachable record-view witness or is classified defensive". That was never demonstrated, and my DEFN-REV accepted the identity on its name (owned).

**Why 491/491 doesn't settle this.** It proves the verifier does not falsely reject valid products. It does **not** prove detection. A wrongly compared set in, for example, the exact-once ledger would still be green on valid data.

### U3 (Medium) — two runtime codes are dead

`UncertifiedAuthoritySubstitution` (`RemeshPipeline.h:1504`) and `BoundaryOrEulerMismatch` (`:1499`) are **never emitted**. The recomputed boundary loops, components and Euler characteristic (`:8306`) are reported only as `CertificatePayloadMismatch:certificate:a7` (`:8314`), while the Definition matrix (§1.3) maps them to `BoundaryOrEulerMismatch`. RA-28a §5's rule ("no runtime code without a frozen predicate") applies in reverse: a code with no emitting predicate is a dead diagnostic.

### U4 (Medium) — CP2 was closed without a closure record or exit adjudication

CP1 closed through a dedicated Review against a frozen checklist, with `M6_CP1_Closure_Record.md`, and every M4/M5 checkpoint has a closure record. This Review declared CP2 closed inside a TB Review, with no per-criterion mapping and no closure record. That is how U1–U3 went unnoticed.

### U5 (Low; no change required) — inversion is shared with the producer

Hop 2 calls the producer helper `reverse_selected_relation_step` (`:7904`). It is pure exact algebra on a value type (flip direction, swap charts and components, invert the transform), which §6.2 permits. But the verifier and A6 share one definition, so an error there is invisible to both. Recorded. An independent five-line inversion is optional.

### U6 (Low; owner M8-CP2) — the token copies all three products on every run

`VerifiedSurfaceProducts` copies A5/A6/A7 per pipeline run. Moving them in would avoid the copy. Recorded for resource accounting.

### U7. Closeout

| Duty | Result |
|---|---|
| Evidence | Re-derived: 1005/1005; frozen order; 491/491; all raw hashes match. |
| RA-29c | Implemented as specified; R1 findings closed. |
| Promotion | **Confirmed** (runtime authority `c64baacd`). |
| CP2 closure | **Revoked**: U1 (High), U2 (High), U3, U4 → RA-29d. |
| Gate | 491. Identity names and order unchanged; bodies of identities 2–5 strengthened; no new identity. |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 205. |
| Successor | `M6-CP2-CB2-COVERAGE` → `M6-CP2-TB2-COVERAGE-EXEC` (491) → `M6-CP2-CLOSE-REV`. `M6-DEFN-R5` follows CP2 closure. |
