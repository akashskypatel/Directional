# M3-CP4c-3-TB48 Independent Review Record

**Status:** COMPLETE / APPROVED WITH AMENDMENTS / PACKAGE113 PROMOTED / ORDINAL370 CLOSED / CP4c-3 CLOSED / M3 CLOSED / M4-DEFN FROZEN
**Turn:** `M3-CP4c-3-TB48-REV`
**Boundary:** independent REVIEW + PLAN; evidence/static only; no Directional runtime or compile
**Date:** 2026-09-09
**Runtime evidence reviewed:** TB48 run/job `34409262512 / 102659650326`
**Immutable evidence source:** `6dae3f6959551f6dcdd81f153aedb5f38411a96b`, package113 artifact `10125000895`, selector409

## 1. Decision

**Decision: `approved_with_amendments`.**

TB48 is mechanically valid and package113/TB48 is promoted as the current reviewed semantic runtime authority:

- **405 PASS / 4 RED / 0 SKIP** over selector409;
- accepted required-green prefix **365/365 PASS**;
- RED `[368,369,374,398]`;
- all 409 identities selected and executed exactly once in ordinal order, one fresh process per identity;
- zero selection mismatches and zero timeouts;
- package/source/execution-view pre/post censuses are equal;
- all configure/compile/relink/discovery/repair/mutation/benchmark flags are false;
- ownership remains **300 established / 0 unavailable / 0 conflicting**.

The amendments are documentary/routing corrections, not reinterpretation of raw evidence: distinguish the frozen
**M3 accepted required-green boundary (365)** from CP4c-3's broader 409-identity audit surface, apply the already
restored AU0-AU9 mechanical-witness exit criterion, and correct the stale M4 entering baseline from 322 to 365.

## 2. Primary-evidence verification

Independent review re-opened the retained TB48 result/log artifacts and verified their provider/download hashes:

- result `10126711178`, SHA-256 `07961a2339204b80f83feac8916e93578176363f9bdf0317ea85bdc095de5747`;
- log `10126711588`, SHA-256 `1aab2f5f9b0d23f41ffd04a1467894f572604774ee2ee6ce9e42ee4b8f6dbd7d`.

`semantic-summary.txt` records 409 total, 405 PASS, 4 RED, accepted 365/365 and exactly `[368,369,374,398]` RED.
`execution-boundary.txt` records runtime started/completed, preflight/execution-view verification true,
`orchestration_failure=false`, `selection_integrity=true`, timeout 0 and every prohibited build/repair/mutation flag
false. `immutability.txt` records all three pre/post censuses equal. Artifact authority is package113 with the exact
frozen SHA-256 `e5fb50f92bbf4c4ffae5afeb203d6738490f6410b3a7e49245607e1b2e7835e9`; selector409 is 409 rows with LF SHA-256
`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.

No evidence gap prevents adjudication.

## 3. Ordinal370 — targeted product correction is runtime-proved and closes

Ordinal370 `SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` selected exactly once and PASSed.
The frozen identity independently establishes a closed torus, an atlas-valid empty rail/network construction, then
requires `SurfaceCutGraph::make` to fail with existing `EmptyNetworkOnClosedSurface = 6` and a non-empty
`sourceFace` locus.

Static package113 source matches that contract exactly in `SurfaceCutGraph::canonical_candidate()`: after
source/atlas/network binding validation and before mandatory-edge/trace classification, a truly empty network
(`nodes`, `mandatory_edges`, `candidate_traces`) queries exact source boundary-loop authority; malformed topology
remains `NonManifoldSource`; a closed non-empty source returns code 6 with deterministic first-source-face locus.
No selector/test/fixture/enum/certifier/proposal change is involved.

Therefore:

- `M3-CP4c3-TB48-EXEC-CAND-01` is **CLOSED / RUNTIME-PROVED PRODUCT-CORRECTION RECOVERY / NON-STABLE**;
- `M3-CP4c2-TB-X2-R8-CAND-02` is **CLOSED / RUNTIME-PROVED PRODUCT CORRECTION / NON-STABLE**;
- stable accounting changes by **+0 events / +0 recurrences** because the candidate was never accepted authority and
  its closure is a status change, consistent with the tracker convention.

## 4. Four remaining REDs remain separate carried owners

The raw red list is not the CP4c-3 exit condition. Each remaining red reproduces a previously classified surface:

1. **368** — prescribed sphere, `M3-CP4c2-TB-X2-CAND-04`: `RotationSystemInconsistent -> TraceEventPositionInvalid`,
   trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. The sphere semantic fix remains separately governed.
2. **369** — `M3-CP4c2-TB-X2-R10-CAND-01`: ordinary trace-crossed proposal still requires saturation. This is the
   separately owned proposal-quality/coverage surface.
3. **374** — `M3-CP4c3-TB7-CAND-02`: folded-cone identity still fails its atlas precondition because the hand-authored
   flat-star field is invalid on the non-flat star. Its future correction is test-fixture authority, not M3 closure.
4. **398** — prescribed-sphere owner-map identity remains downstream of 368 because the cut graph is absent.

No new failure surface appears, no owner is merged, and none of these four may be repaired by weakening M3's
accepted authority. They remain open under their existing future owners.

## 5. Protected controls remain non-vacuous

Ordinals 390/393/406/407 all PASS through the successful `PlanFrontier` evidence branch. Their runtime receipts say
`branch=UncutCensus`, `censusPredicateExecuted=yes`, `sameDomainCorruptionRejected=yes`,
`terminalSubjectBranch=PlanFrontier`, and `planFrontierEvidenceBranchExecuted=yes`; supporting BW3/owner-map/
partition/interior-arc evidence is non-empty. Ordinal385 publishes **300/0/0** ownership. Accepted/protected 307,
367, 404, 408 and 409 also PASS.

This rules out a vacuous recovery and confirms CB54 did not bypass Part XII or accepted-prefix authority.

## 6. CP4c-3 exit criterion and formal closure

The retained ROADMAP explicitly states: **“CP4c-3 closes on the mechanical witness under AU0–AU9, unchanged.”**
`M3_CP4c_Current_And_Forward.md` restores AU0–AU9 in durable form and adjudicates each measure MET. TB48 preserves
that state and adds the last required evidence-hygiene step after CB54:

- accepted 365/365 remains green;
- mechanical ordinals 366/367 are green;
- protected 390/393/406/407 remain non-vacuously green;
- all 409 rows execute report-only after first RED with zero gate credit;
- exactness/reportability and all AU9 prohibitions remain intact;
- CB54's sole targeted product change, ordinal370, is now runtime-proved without collateral movement.

**Formal `M3-CP4c-3` state is therefore CLOSED / ACCEPTED.** The four carried REDs do not falsify its exit condition;
continuing to chase them inside CP4c-3 would violate the checkpoint's own frozen ownership and `LESSONS.md` 167.

## 7. M3 milestone closure

CP4c-3 was the final remaining M3 checkpoint. With it closed, the `DESIGN.md` §14 M3 acceptance surface is complete:

- typed singularity-port ownership and branch-consistent/non-crossing tracing were established by the earlier M3
  checkpoints and retained accepted prefix;
- typed network termination is accepted through CP4c-0b;
- actual embedded-graph region/disc proof authority is accepted through CP4ab/CP4c-2;
- mandatory topology/tamper and permutation controls remain green;
- CP4c-3 supplies the closed mechanical witness and its exact/reportable continuation evidence under AU0–AU9.

**M3 is CLOSED / ACCEPTED.** The durable M3 closure record is `M3_Closure_Record.md`.

The accepted required-green selector entering M4 remains **365**. Selector409 is the final CP4c-3 execution/audit
surface and remains retained byte-for-byte; its four carried reds are not silently promoted or deleted.

## 8. Promotion and accounting

Package113/TB48 supersedes TB47/package112 as reviewed semantic runtime authority. Stable totals remain **47 events /
14 categories / 33 recurrences**; produced-witness debt remains **5**; ownership remains **300/0/0**; accepted
package count is **113**. Closing non-stable ordinal370 changes status, not historical counts.

## 9. Mandatory REVIEW consolidation

Durable facts from the superseded documents below are preserved first in this review, `M3_Closure_Record.md`,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md`, `CHANGELOG.md`, ROADMAP and
the M4 definition plan. Their exact bytes remain recoverable from Git history.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB47_EXEC_Report.md` | 148 | superseded runtime authority — package112 404/5, accepted 365/365 |
| `Architecture_M3_CP4c3_TB47_Independent_Review_Record.md` | 252 | superseded review authority — package112 promotion and CB54 freeze |
| `Architecture_M3_CP4c3_CB54_Empty_Network_Typed_Rejection_Code_Build_Plan.md` | 138 | consumed AK5 product-correction build contract |
| `Architecture_M3_CP4c3_CB54_Code_Build_Report.md` | 103 | consumed package113 compile/build authority; runtime-proved by TB48 |
| `Architecture_M3_CP4c3_TB48_Artifact_Only_Test_Benchmark_Plan.md` | 132 | consumed immutable package113/selector409 execution contract |

**Folded this review: 5 documents / 773 lines. Running total: 161 documents / 30,025 lines.** No intervening
per-turn document had already been retired outside the prior folded index.

Retained current family authority after consolidation is exactly `Architecture_M3_CP4c3_TB48_EXEC_Report.md`, this
review record, `M3_Closure_Record.md`, `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`,
`M3_CP4c_Consolidated_Record.md`, `Required_Green_Selector_Manifest.md`, every byte-frozen selector, and the single
successor plan `Architecture_M4_DEFN_Definition_Plan.md`.

## 10. Exact successor

**Exact next: `M4-DEFN` — definition/review-plan, runtime-free.**

`Architecture_M4_DEFN_Definition_Plan.md` freezes its scope. M4-DEFN must reconcile the currently proposed
conditioning/scale checkpoints with the global-conformity CP1–CP4 decomposition, freeze the schedule product and
its rejection vocabulary/oracle/witness provenance, carry the three `G4-B002` produced-witness debts, and issue the
first M4 Code + Build plan. It may not run Directional runtime or compile and may not reopen accepted M3 authority.

## 11. Integrity confirmation

- Production code changed: **no**.
- Test or benchmark logic changed: **no**.
- Build configuration changed: **no**.
- Selector bytes changed: **no**.
- Directional tests or benchmarks executed in review: **no**.
- Compile/build executed in review: **no**.
- Review decision is based on retained primary TB48 evidence plus static package113/source inspection.
