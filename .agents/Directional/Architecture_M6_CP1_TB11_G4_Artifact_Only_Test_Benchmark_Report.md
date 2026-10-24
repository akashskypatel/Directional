# `M6-CP1-TB11-G4-EXEC` — Artifact-Only Test + Benchmark Report

## Disposition

**MECHANICALLY VALID RED / REVIEW REQUIRED / CANDIDATE UNPROMOTED.**

- Candidate package/source: `11308472138 / 582da20a925ba920c923bf5aacb9e0e56ef0723d`.
- Compile authority: `37216400150 / 111477707423`; package manifest **28/28**; GMP/GMPXX; `runtimeExecution=false`.
- Valid runtime run/job: `37225085141 / 111503003092` — terminal SUCCESS.
- Result artifact: `11312313559`, ZIP digest `sha256:7de4a3203720d170691ff0f1b3d1773736b56f857accd5e51ced5f92c5973add`.
- Log artifact: `11312890562`, ZIP digest `sha256:fba498373cfb726ffe091296561d18cb774230cea1cd4f341bf00529590ae681`.
- Result self-manifest: **973/973**, manifest SHA-256 `31a537f5d420b64e828fe75c8c5125e33ef3c1c3588efc9e531b6cca3ee61317`.
- Outcome: focused **26/28 PASS**, selector449 **449/449 PASS**, aggregate **475/477 PASS**.
- RED focused ordinals: **25, 28**. Exact-one selection: true. Zero skips: true. Benchmark execution: 0.
- Stable accounting remains **60 events / 16 categories / 44 recurrences**; project debt remains **1** pending mandatory Review adjudication.
- Candidate remains unpromoted; every mechanically valid outcome advances to `M6-CP1-TB11-G4-REV`.

## 1. Immutable candidate and execution boundary

The valid gate consumed artifact `11308472138` immutably. Provider/download digest matched `a4d178678bcbc9c29fc4003ffc9205ef220873bfb0e5247b21a453fffdc8d04d`; packaged `SHA256SUMS` remained **28/28** with SHA-256 `c6e691329dfe5599caf658b23e70d51d45ac76c090afc7d9cb86f3901df34468`; packaged source archive SHA-256 remained `c41200fefded7e8a60f57eb801c5de2476eebafe6822fe5ce5e4a2113971c768`.

Frozen authorities remained unchanged: focused28 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

The valid run executed exactly **477** fresh exact-filter processes in frozen order. Package, source, and execution-view censuses remained unchanged; no configure, compile, relink, generated discovery, benchmark, package repair, mode repair, source/test/fixture/selector mutation, or retry after runtime start occurred.

The earlier orchestration attempt `37222200420 / 111494663445` failed before a valid semantic gate because its harness preflight counted the focused vector incorrectly. The retry marker records this as an orchestration-only focused28-count correction before runtime; the valid run above is the sole semantic execution used here.

## 2. Runtime evidence

Focused identities 1-24, 26 and 27 PASS. The accepted selector449 remains **449/449 PASS**, so no accepted selector behavior regressed.

Focused ordinal 25, `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus`, is RED. The RA-21b oracle reports repeated disagreement between quotient-class-to-arrangement-node identity and between the two produced proposal-side provenance chains assigned to one A6 edge. Examples include class mappings `344 != 0`, `345 != 3`, and side-chain edge sets `{1200} != {980}`. This is direct evidence that the published A6 side-incidence pairing is not combinatorially equivalent to the produced torus provenance chains under the frozen degree-2-chain contraction oracle.

Focused ordinal 28, `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle`, is RED at the non-vacuity assertion: no extracted candidate satisfies the independent eligibility predicate. The test therefore does not reach its tampered hard-feature rejection subcheck. Because ordinal 25 already proves a closed-complex incidence discrepancy and the evidence does not establish whether ordinal 28 is a downstream consequence or an independent extraction defect, Review must adjudicate their relationship rather than merge them mechanically.

Ledger SHA-256 values: focused `3c5ca261c00a83c4d9cf672f8a71c6e441fc767dd59bb8edf8b23cc68891ce8f`; selector `4ad9490e0ea32512fc35221e1e3754bdb58b01c8fce4cb65f1ac513168fe3ead`; combined `1ec90202c74c65e6ad208ee5ef88853e0cff46271f66d2eb6745c44a764b28f0`; RED `89230baf2abc7a1c43881d306bfddd35f1f233ec82b4265a16a50cc2bb274856`.

## 3. Regression disposition

Two candidate/non-stable findings are recorded:

- `M6-CP1-TB11-G4-EXEC-CAND-01` — A6 side-incidence pairing disagrees with produced-torus provenance-chain / degree-2-contraction authority.
- `M6-CP1-TB11-G4-EXEC-CAND-02` — A6 candidate extraction has no independently eligible produced-torus candidate.

Neither changes stable history in EXEC. Both are new focused probes on an unpromoted candidate, while the accepted selector449 remains fully green. Stable accounting therefore remains **60 / 16 / 44**, debt **1**, until mandatory Review independently classifies root cause, relationship, recovery scope, and promotion eligibility.

## 4. Successor

EXEC makes no promotion, `G4-B002`, debt, or CP1-closure claim. Exact successor is mandatory runtime-free `M6-CP1-TB11-G4-REV`. `M6-CP1-CLOSE-REV` remains held until that Review.
