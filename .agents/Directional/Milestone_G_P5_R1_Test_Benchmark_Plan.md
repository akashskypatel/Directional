# Milestone G P5-R1 Test and Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Next turn:** P5-TB23 artifact-only R0/R1 validation

## Authority

Execute artifact `8902050372`, `surface-cell-p5-r1-github-source-linux-release`, directly.

- exact compiled source: `e31e5abd52ca9e673d1718f47d088d19296d1d22`;
- workflow event commit: `233466e5b02c3762a3f2648518f5860a2a2fb014`;
- artifact SHA-256: `5d1e5ca4fa8bc74e0a30615725c79a8b491830ab1f4407152cf79bfe56f8880f`;
- reviewed R0/R1 patch SHA-256: `a3898a847c6722a1f2d9b0de48e71ae71f08fcc0bc82b3d9396d8c842d9cad61`;
- compile-fix patch SHA-256: `92162aa709134c86a355253416dc614817fecabebaeb60c58555061958d12162`;
- workflow-log artifact: `8902051026`;
- workflow-log SHA-256: `dee5e429cb9a57ee9b45db42d27b512c7b096aed875147a01364e5a757f4b5a6`.

Do not configure, build, relink, patch, regenerate, or modify source in P5-TB23.

## 1. Package authority

Before executing either packaged binary, verify:

- archive SHA-256;
- exact source commit and implementation ancestry;
- empty source status;
- recursive checksum manifest **41/41**;
- **43** packaged files;
- **26** fixture files;
- **9** recursive submodule records;
- all four packaged target hashes;
- source archive contains `SourceChartTransitions.h`, default-off recovery, distinct recovery origin, integration call sites, and focused test contracts.

Any authority mismatch terminates the turn before runtime execution.

## 2. Focused R0 contracts

Run the smallest named tests covering:

- default `SurfaceCells` requests cannot execute source-grid recovery;
- explicit recovery requires opt-in;
- explicit recovery reports `SourceGridRecovery`, not `CompletedSurfaceCells`;
- fallback policy `Fail` never executes legacy output;
- failed direct completion retains the existing typed failure and exact rollback;
- diagnostics do not claim direct surface-cell completion when recovery ran.

R0 passes only when recovery is observably non-authoritative and default-off.

## 3. Source-edge transition contracts

Run focused tests for two adjacent manifold source faces sharing one source edge.

Require:

- one canonical intrinsic edge identity;
- exact endpoint permutation;
- exact barycentric rebind in both directions;
- reverse transition is the canonical inverse;
- component and sheet labels are preserved;
- transition and canonical-entity hashes are deterministic under face-row permutation and source orientation reversal.

## 4. Source-vertex fan contracts

Run focused tests where charts share only a source vertex.

Require:

- charts in one intrinsic incident fan reconcile to one canonical source vertex entity;
- source boundaries split fans correctly;
- hard feature rails split otherwise adjacent fan sectors;
- component and local-sheet barriers split fans;
- nonmanifold sectors remain separated;
- disconnected or opposite close sheets never reconcile because positions are nearby.

## 5. Inconsistent-transition and rollback contracts

Run intended negative tests for:

- inconsistent source-edge winding;
- incompatible transition-cycle composition;
- conflicting component/sheet ownership;
- hard-rail crossing;
- unresolved canonical source entity.

Require failure before global quad commit, complete typed source-chart evidence, and exact rollback of output vertices, quads, lineage, provenance, and structural hashes.

Do not weaken validation or introduce positional fallback.

## 6. Arrangement and completion integration

Run the focused Phase 16 and completion/stitch tests affected by R1.

Require:

- arrangement-node identity uses canonical source entities;
- missing adjacent-face occurrence is rebound only through an exact transition;
- completion generated vertices retain the full provenance set;
- shared completed vertices and edges agree through canonical source entities;
- hard-feature barriers reach completion and validation;
- no duplicate or false merged stitched quad is introduced.

## 7. Source-authoritative validator scopes

Run focused Phase 22 and related validator tests.

Require:

- valid adjacent charts pass after exact transition reconciliation;
- hard-rail-separated charts remain distinct;
- close parallel sheets remain distinct;
- inconsistent transition evidence fails closed;
- diagnostics include the conflicting chart/entity set without using position as identity.

## 8. Analytic direct production gates

Run independently with backend `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled:

1. plane;
2. multi-face seam;
3. close sheets;
4. disconnected close sheets or the closest existing reduced contract.

Record:

- success and output origin;
- completed quad count;
- source-chart transition and canonical-entity hashes;
- all conflicting provenance when failure remains;
- component/sheet labels;
- fallback/recovery execution flags.

Acceptance target for R1 is direct valid completion of plane, seam, and close sheets with no cross-sheet leakage and no `LocalSheetMismatch`. A remaining failure must identify the earliest producer and cannot be hidden by recovery.

## 9. Regression scopes

After focused contracts, run only the analytic scopes needed to establish that R1 did not regress the existing front end:

- Phase 14–18 aggregate;
- Phase 16 independently;
- relevant completion and source-authoritative validation scopes;
- relevant Phase 20 fallback/recovery contracts;
- the complete suite once, with a process watchdog only as a safety mechanism.

A watchdog timeout is a termination failure, never a pass. Do not run the full bunny benchmark matrix solely because R1 changed.

## 10. Runtime decision

When R1 analytic gates pass, the next code/build turn is **P5-R2 directed wedge/incidence reconstruction**.

When any R1 gate fails, remain on R1 and record the earliest source-chart producer. Do not start R2, topology-distinct completion, repeated-node splicing, phase/front state, torus, cache, lineage, or memory work prematurely.

## Exit criteria

P5-TB23 closes R1 only when:

- package authority passes;
- R0 recovery authority is correct;
- focused edge, vertex-fan, hard-rail, disconnected-sheet, inverse, permutation, and rollback contracts pass;
- plane, multi-face seam, and close sheets complete directly without `LocalSheetMismatch` or leakage;
- required regression scopes terminate normally and do not introduce new failures.

Otherwise, keep P5 and PR #8 open and update the handoff with the earliest authoritative producer.
