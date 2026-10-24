# M6-CP1-TB11-G4-EXEC — Artifact-Only Test + Benchmark Plan

**Owner:** `M6-CP1-TB11-G4-EXEC`  
**Type:** immutable artifact-only Test + Benchmark.  
**Candidate:** artifact/source `11308472138 / 582da20a925ba920c923bf5aacb9e0e56ef0723d`.  
**Candidate outer ZIP SHA-256:** `a4d178678bcbc9c29fc4003ffc9205ef220873bfb0e5247b21a453fffdc8d04d`.  
**Compile authority:** run/job `37216400150 / 111477707423`, manifest 28/28, GMP/GMPXX, `runtimeExecution=false`.

## Preflight

1. Download artifact `11308472138` exactly once in the runner.
2. Verify provider/download digest, packaged `SHA256SUMS` **28/28**, packaged source `582da20a...`, root-manifest SHA-256 `c6e691329dfe5599caf658b23e70d51d45ac76c090afc7d9cb86f3901df34468`, and source-archive SHA-256 `c41200fefded7e8a60f57eb801c5de2476eebafe6822fe5ce5e4a2113971c768`.
3. Preserve executable mode bits; do not repair the immutable package.
4. Do not configure, compile, relink, regenerate discovery/code, patch source, or alter fixtures/manifests.
5. Verify frozen authorities:
   - focused28: `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`;
   - focused24 exact prefix;
   - selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
   - routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Runtime gate

Execute exactly:
- focused28: **28** fresh exact-filter processes in frozen file order;
- accepted selector449: **449** fresh exact-filter processes in frozen routing order.

Total: **477** processes.

For every process require exactly one selected test and zero skips. Zero-selected filters are orchestration failure. Benchmark count remains zero. No retry or repair after runtime starts.

The four appended focused identities are:
25. `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus`
26. `M6CP1.A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels`
27. `M6CP1.A6ClosedComplexBoundaryPreservesQuotientVertexLineage`
28. `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle`

Identity 25 is the RA-21b degree-2-chain contraction oracle. Any semantic RED is evidence, not permission to mutate or rerun this package.

## Postflight and reporting

- Re-hash package, packaged source, execution view, focused/selector/routing authorities and root manifest after runtime.
- Record focused/selector/aggregate PASS/RED counts, exact-one selection, skips, benchmark count and immutable postflight.
- Categorize every observed regression in `.agents/Directional/Regression_Root_Cause_Tracker.md`; use candidate/non-stable disposition unless stable-history criteria are met.
- EXEC makes no promotion or closure claim.
- Every mechanically valid outcome advances to mandatory runtime-free `M6-CP1-TB11-G4-REV`.


## Execution closeout — COMPLETE evidence captured (2026-10-04)

The first orchestration attempt `37222200420 / 111494663445` was superseded before a valid semantic gate by the documented focused28-count preflight correction. The sole semantic execution used for this turn is valid artifact-only run/job `37225085141 / 111503003092`:

- focused **26/28 PASS**, RED ordinals **25, 28**;
- selector449 **449/449 PASS**;
- aggregate **475/477 PASS**;
- exact-one selection true, zero skips, benchmark 0;
- result/log artifacts `11312313559 / 11312890562`;
- result self-manifest **973/973**;
- immutable package/source/execution-view postflight passed.

The durable Test + Benchmark report and regression-tracker entries were committed by `4094d8ded473f0b8c1ba56cc1605e4546eebc75f`. TODO/handoff closeout was applied by workflow run `37231455438` at commit `f721255b9eb6ba928608e8d6630b5d7bcee57994`; its transient Drive staging file was owner-retired after successful push. `M6-CP1-TB11-G4-EXEC-CAND-01` and `...-CAND-02` remain separate, non-stable, Review-pending findings. Stable accounting remains **60 / 16 / 44**, debt **1**. The candidate remains unpromoted.

Exact successor after repository closeout is mandatory runtime-free `M6-CP1-TB11-G4-REV`; `M6-CP1-CLOSE-REV` remains held.


## Superseded Review WIP continuation — 2026-10-04

`M6-CP1-TB11-G4-REV` is in progress. Review independently re-derived the immutable 475/477 evidence and found both REDs are test/definition-authority defects rather than demonstrated A6 production regressions:

- ordinal25: RA-21b incorrectly equates quotient relation identity with physical arrangement node/chain identity across distinct cut occurrences; proposed RA-21c makes arrangement a per-occurrence/per-side subdivision witness and checks quotient pairing through A4 `oppositeEdge` + A5/A6 relation authority;
- ordinal28: the accepted M4CP4 non-vacuity witness uses arrangement `(family,strand)`, while R4 replaced that partition with quotient opposite-edge strips; proposed RA-23 keeps produced-torus strip/candidate universal checks but proves CP1 mechanism non-vacuity/tamper on a canonical closed 4x4 toroidal A6 view, with zero CP3 debt credit.

Exact verified WIP patch is staged at Google Drive `My Drive/Directional-CI/M6-CP1-TB11-G4-REV-WIP.patch`, file ID `12hlRs63rzZRXFGAExsThrgXJanU1tCKH`, full SHA-256 `b55b7a03eaad3e029d579d01524fb7c3ef0700502164d7e5a3135094859984c8`, base `48c4fbeb154fb8deeb26b970a13ad2ea652583b1`, diff-body SHA-256 `c371b87a3a51f7900139aa373cba276747d64663db2a33741e3b8382904b9a9e`. It contains the Review record, RA-21c/RA-23 frozen-definition amendment, tracker dispositions, and bounded `M6-CP1-CB11-G4-R1` recovery plan. It has passed `git apply --check` and `git diff --check`.

The current response also corrected a mandatory READ_MODE process miss: early repository reads preceded snapshot selection. Decisive conclusions were re-derived from verified source snapshot run/artifact `37233051478 / 11314264059` at `48c4fbeb154fb8deeb26b970a13ad2ea652583b1`, archive SHA-256 `986e3bc1ec98c681af537004def24d4bd165da417437f9c83268729c96d02c05`, 5348/5348 manifest rows. On continuation, apply the exact staged WIP patch first, then update TODO/handoff/ORIENTATION/ROADMAP/CHANGELOG/M6 consolidated record, retire temporary snapshot/patch state, and close Review only after those durable records agree. Do not start R1 while Review remains in progress.


## Review disposition — COMPLETE (2026-10-04)

The WIP above was consumed by `M6-CP1-TB11-G4-REV`. Authoritative disposition is `Architecture_M6_CP1_TB11_G4_Review_Record.md`: ordinal25 is a false-rejection oracle/definition defect resolved normatively by RA-21c; ordinal28 is a separate definition/fixture-witness gap resolved normatively by RA-23. The CB11 candidate remains unpromoted. Exact successor is bounded `M6-CP1-CB11-G4-R1`, then unchanged focused28 + selector449 = 477 and mandatory R1 Review.
