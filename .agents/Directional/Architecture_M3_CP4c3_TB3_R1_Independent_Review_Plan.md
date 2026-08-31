# M3 CP4c-3 TB3-R1 — Independent Review + Plan

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB3-R1-REV`
Status: **FROZEN NEXT-TURN PLAN / NOT EXECUTED**

## Review authority

Review only. Do not modify product/test/fixture/selector semantics, configure, compile, package, or execute Directional runtime.

Primary evidence:

- TB3-R1 report: `Architecture_M3_CP4c3_TB3_R1_Artifact_Only_Test_Benchmark_Report.md`;
- immutable package 72: artifact `9765247195`, outer SHA-256 `41ebe4dec4a3eb5c8194900a3f27a0377c3271212edd10fb952c48f55a6a2e6d`, inner tar SHA-256 `20630897aa432572d0929022abef3861fff80c2b5792c223071990dd2e3c6a73`;
- semantic source: `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`;
- TB run/job: `33416686424 / 99568970224`;
- first red: ordinal 366, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, `VertexTransitSectorUnresolved`;
- accepted prefix: 365/365 remains green;
- selector 373 stays byte-frozen at `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.

## Objective

Determine the exact semantic cause of the new network-stage first red without guessing from the lossy production exception. The review must distinguish **zero** versus **multiple** transit candidates, identify the exact source vertex/face/branch/arrival mode and reachable transported sector set, determine causality relative to Amendment 16/P2, and freeze a bounded correction/diagnostic plan only after those facts are established.

## Review measures

### AR0 — revalidate the evidence boundary

Confirm TB3-R1 is admissible semantic evidence: immutable package 72, 365 accepted-prefix identities green, exact first-red selection at 366, immutable postflight, and no prohibited build/repair/mutation activity. Do not re-run the gate.

### AR1 — reconstruct the exact transit algorithm

Trace `resolve_field_vertex_transit`, `direction_in_vertex_sector`, `FieldBranchTransportAdjacency`, branch transport composition, and both call modes (`FaceInterior`, `EdgeTransit`). State the invariant the function is intended to prove and every condition that can reduce or multiply the candidate set.

### AR2 — recover the missing locus before choosing a correction

The runtime error type already owns `sourceVertex`, `sourceFace`, `branch`, and `publishedFaces`; the production-harness path published only the code. Determine the minimal diagnostic surface needed to expose the exact failing locus and candidate cardinality on the mechanical witness. If static evidence alone cannot prove the locus/cardinality, freeze diagnostic-only CB work rather than a semantic correction.

### AR3 — audit the cut-domain interaction by assumption, not symbol

Determine whether vertex transit is supposed to walk one connected component of `star(v) ∖ B(R)` and whether the current traversal already enforces that through the transport-adjacency set. Explicitly test the two prohibited interpretations: crossing a hard-feature barrier to manufacture uniqueness, or closing an open cut fan by branch transport. Amendment 16 remains binding.

### AR4 — establish causality

Compare the transit and caller semantics before/after the Amendment 16/P2 change. Decide among at least:

- pre-existing and newly unmasked downstream defect;
- changed port/trace origin exposes a legitimate previously unreachable transit;
- P2 consumer mismatch;
- topology/branch-transport representation mismatch;
- exact sector predicate/election defect.

Do not label the red a regression merely because it follows CB3.

### AR5 — preserve accepted behavior and frozen selector authority

Any successor plan must preserve ordinals 1–365, keep selector 373 byte-identical, keep barrier transport prohibited, and keep the P2 decision unless measured evidence falsifies its premises. No weakening of the ordinal-366 contract or first-red rule is allowed.

### AR6 — adjudicate carried candidates

Record explicitly:

- `M3-CP4c3-TB2-CAND-01`: prior `MissingSingularityBranchTransport` locus is cleared but CP4c-3 remains red downstream;
- `M3-CP4c3-TB2-ORCH-01` and `M3-CP4c3-TB2-REV-CAND-01`: resolved;
- `M3-CP4c3-DEFN-R1-CAND-01` and ordinal 368–370 inherited candidates: still runtime-unproved because 367–373 did not execute;
- `M3-CP4c3-TB3-R1-CAND-01`: active until this review establishes cause and owner.

Stable accounting changes only if review evidence satisfies the regression tracker's stable criteria.

### AR7 — freeze one bounded successor

End with one falsifiable next-turn plan. If cause and correction are proven statically, issue a bounded Code + Build measure set. If the exact runtime locus/cardinality remains unknown, issue diagnostic-only Code + Build instrumentation first. No TB retry is authorized directly from review without a new immutable package produced by the required CB edge.

## Required review output

The review record must include:

1. exact failing transit invariant and full reconstructed candidate-selection path;
2. zero-vs-multiple candidate determination if evidence supports it, otherwise an explicit unresolved diagnostic question;
3. source vertex/face/branch/arrival mode and candidate faces when determinable;
4. causality classification relative to Amendment 16/P2;
5. regression-candidate adjudication and stable-count rationale;
6. exact bounded successor measures and prohibitions;
7. `ORIENTATION.md` update, as required for every REVIEW turn.

No runtime acceptance is possible in this review.
