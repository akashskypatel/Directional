# M3 CP4c-3 TB4 — Independent Review + Plan

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB4-REV`
Status: **FROZEN NEXT-TURN PLAN / NOT EXECUTED**

## Review authority

Review only. Do not modify product/test/fixture/selector semantics, configure, compile, package, or execute
Directional runtime.

Primary evidence:

- TB4 report: `Architecture_M3_CP4c3_TB4_Artifact_Only_Test_Benchmark_Report.md`;
- immutable package 73: artifact `9773591345`, outer SHA-256 `8f3a8f0d6a3ad0931db89cb3e94c33d1d7e8a0d9e1aba27a6ad2690ec9c402a0`, inner tar SHA-256 `fc939abc4110f4a658d80932b395f59c9fd7cecbbcde7caac0ba7b6a41d1aca1`;
- semantic source: `2d22ef293363058cfdca96d01158a93d2c0200f8`;
- TB run/job: `33436492493 / 99634138202`;
- result/log artifacts: `9774693166` (`056f86df2e387391227bcf52f59ba932dd64a5d02923a8ff688cd8e315ff8a7e`) / `9774693946` (`d2acc62037d0bce07ef98bb77a7cb42ee90758d8b72477d9d8516da2fa0afcb6`);
- semantic first red: ordinal 366, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`;
- exact locus: `VertexTransitSectorUnresolved`, source vertex 30, face `(24,30,32)`, branch 1, region 0, `FaceInterior`, two candidate faces `(25,30,31)` / `(30,31,119)`, `BarrierAbsorbed=false`, `barrierIncident=false`;
- accepted prefix: **365/365 green**;
- AP6 diagnostics 367–373: **1 PASS / 6 RED / zero gate credit**;
- selector 373 remains byte-frozen at `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.

## Objective

Establish the semantic cause of the **two-candidate FaceInterior continuation** at vertex 30 without weakening the
exact sector election, crossing a barrier, or treating the AP6 report-only pass as gate credit. The review must also
adjudicate what the newly observed 368–373 diagnostics do and do not prove, then freeze exactly one bounded successor.

## Review measures

### AQ0 — revalidate the evidence boundary

Confirm TB4 is admissible semantic evidence: immutable package 73, accepted 365-prefix green, exact first-red
selection at 366, AP6 zero-credit separation, immutable postflight, and no prohibited build/repair/mutation. Record
the first attempt's sidecar-name failure as resolved orchestration only; do not treat it as semantic evidence.

### AQ1 — classify vertex 30 from source authority

Determine whether source vertex 30 is a prescribed singularity, ordinary regular vertex, feature vertex, or another
typed atlas category. Reconcile that classification with the runtime census vertices 10/35/47/71 and with
`barrierAbsorbed=false` / `barrierIncident=false`. Do not infer singularity from candidate multiplicity alone.

### AQ2 — reconstruct both continuation candidates exactly

For arrival `(face=(24,30,32), branch=1, mode=FaceInterior)`, enumerate the reachable `(face, branch)` states and the
transport-adjacency path to each published candidate face `(25,30,31)` and `(30,31,119)`. For both candidates, state:

1. transported branch;
2. exact adjacency/quarter-turn composition used to reach it;
3. exact `direction_in_vertex_sector` predicate inputs and why it passes;
4. whether the candidate is topologically distinct or an alias of one semantic continuation represented twice.

The review must explain **why cardinality is 2**, not merely restate it.

### AQ3 — adjudicate M1/M2/M3 without overclaiming

TB4 falsifies M1's zero-candidate prediction and direct M3's `BarrierAbsorbed`-vertex prediction at the failure
locus. Decide whether M2's singular-holonomy explanation is actually true after AQ1/AQ2, or replace it with the
measured mechanism. Preserve the possibility that P2 changed reachability/trace origin and merely unmasked an
unchanged consumer defect; `barrierAbsorbed=false` does not by itself prove causal independence from CB3.

### AQ4 — audit the FaceInterior exclusion rule

The transit search does not test the arrival face as a candidate in `FaceInterior` mode. Re-derive that rule from the
producer contract and determine whether it interacts with the two-candidate state. Do not change the rule merely to
make cardinality one. Any proposed correction must identify the semantic owner of continuation before choosing an
election change.

### AQ5 — adjudicate AP6 diagnostics separately from the gate

Record each report-only result with zero gate credit:

- **367/371/372:** same mechanical blocker; no independent downstream cause may be inferred.
- **368:** sphere reaches A2a′ and reproduces `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2 / event 30; **AL4 remains binding** and no sphere correction is designed here unless prior authority explicitly schedules it after the mechanical review.
- **369:** intended assertion reached; `saturationUsed=true` directly reconfirms `M3-CP4c2-TB-X2-R10-CAND-01`. Decide whether its already-frozen AK4 correction becomes part of the next bounded successor or remains deferred behind the mechanical gate.
- **370:** intended empty-network cut-graph contract was not reached because `FieldTransportAtlas::make` returned false. Inspect the exact atlas error and classify `M3-CP4c3-TB4-DIAG-CAND-01` as witness/precondition, changed product contract, or legitimate fail-closed behavior before any test/product correction.
- **373:** synthetic barrier-arc binding is green; decide what additional evidence is still required to close `M3-CP4c3-DEFN-R1-CAND-01`'s mechanical zero-unbound condition.

### AQ6 — preserve frozen architecture and accepted behavior

Any successor must preserve ordinals **1–365**, selector 373 bytes and prefix hashes, Amendment 15, Amendment 16/P2,
barrier non-traversability, exact no-tolerance sector predicates, error-enum numbering, and first-red semantics unless
this review proves a prior premise false. No `pick first`, tolerance, face-order, or barrier-crossing shortcut is
admissible.

### AQ7 — regression accounting and causality

Update every active candidate touched by TB4. Stable counts change only if accepted behavior loss satisfies the
tracker's stable criteria. The accepted 365-prefix stayed green and CP4c-3 was already open, so the default evidence
supports **+0 stable events / +0 recurrences** unless AQ1–AQ5 uncover contrary accepted-path evidence.

### AQ8 — freeze exactly one successor

End with one falsifiable bounded plan. If AQ1–AQ4 establish the semantic defect and a uniquely justified correction,
issue one Code + Build measure set with explicit negative prohibitions and frozen verification predictions. If cause
remains underdetermined, issue diagnostic-only Code + Build instrumentation rather than a semantic correction. Do
not route directly to another unchanged TB run.

## Required review output

The review record must include:

1. exact classification of source vertex 30;
2. both candidate `(face, branch)` states and their transport paths;
3. exact reason both sector predicates pass;
4. M1/M2/M3 disposition and causality relative to P2;
5. independent adjudication of diagnostic ordinals 368, 369, 370 and 373;
6. candidate/stable-accounting updates;
7. one bounded successor and its falsifiable predictions/prohibitions;
8. required `ORIENTATION.md` update for the REVIEW turn.

No runtime acceptance is possible in this review.
