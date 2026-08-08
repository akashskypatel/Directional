# Surface-Cell Testing Strategy

## Mandatory direct matrix

Run in order: plane, multi-face seam, close sheets, cylinder, randomized `bunny_1k_random`, vase. Run all six even after failure when the active turn budget permits a bounded execution; later fixtures cannot pass an earlier gate. A bounded timeout is failure only and does not synthesize a result.

Every direct success requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

Topology/singularity gate fixtures such as torus and prescribed sphere are run additionally when their gate is active. They do not replace the production matrix above.

## Fixture integrity

- bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`: 502 vertices, 1,000 triangles, closed, one component;
- vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`: 1,274 vertices, 2,404 triangles, one boundary loop and 142 boundary edges.

Both use generated smooth fields through production extraction. Replacing, simplifying, bypassing, or special-casing either fixture is prohibited.

## Latest executed runtime authority

Exact artifact `9013161456`, source/test evidence `117620ec2da2083ce11b205835e58fa404f163ef`, runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`.

G0-G3 are passed.

- focused/retained G0-G3 contracts: **17/17**;
- plane: `Produced / CompletedSurfaceCells`, 64 pure quads, hash `730caeae49ec872c`, deterministic 3/3;
- seam: `Produced / CompletedSurfaceCells`, 64 pure quads, hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close sheets: `Produced / CompletedSurfaceCells`, 200 pure quads / two components, hash `89b052762f52a5af`, deterministic 3/3;
- cylinder: `Produced / CompletedSurfaceCells`, periodic `r=0`, `t=(32,0)`, route 32, cut 4, 288 pure quads / 320 vertices, zero validation failures, field P95 `8.537736463e-7°`, output hash `32135be51d7a0a26`, deterministic 3/3;
- bunny: `NotApplicable`, 80,862 traces, no output, terminal `NotProductionReady:completion`, no fallback/recovery;
- vase: current bounded 45-second observation produced no complete result; timeout carries no correctness inference.

Bounded suites: producer **100/101** (only `StrictValidatorOverheadStaysBelowFivePercent` timing check), completion/simplification **154/164**, validation **60/60**, compiled API **8/8**.

## Current producer-authority contracts

The source distinguishes:

```text
NotApplicable
Produced
Rejected
```

Mandatory behavior:

- applicable valid plane/seam/cylinder may reach `Produced`;
- applicable invalid metadata reaches `Rejected`, not `NotApplicable`;
- `Rejected` generates no generic substitute work and remains terminal for the requested backend;
- typed rejection remains first-invalid authority;
- non-embedded relief guidance does not veto transport;
- embedded relief barriers block according to the existing relief contract;
- ordinary shared-edge and ordered source-vertex fan transport remain covered;
- reversed face ordering preserves structural results;
- malformed/duplicate/nonreciprocal transition data fails closed;
- source component/sheet identity prevents unrelated capture;
- one accepted authoritative cell maps to exactly one quad;
- periodic source identity, field-authoritative ring correspondence, canonical source-simplex endpoints, exact cut quotient, and artificial-cut non-exterior behavior remain G3 regressions.

Producer disposition and typed rejection identity must be present in deterministic diagnostic/structural evidence.

## Active G4 topology contract

The exact torus is connected, closed, genus one (Euler characteristic 0, no boundary). Artifact `9013161456` rejects at `tracing/phase-front` with typed `InvalidPeriodicTopology` after partial diagnostics already retain one periodic relation.

Source authority currently stores only one scalar `SurfacePeriodicHolonomy` at result level and rejects a second enabled local relation. The active G4 test strategy therefore requires:

- first-class deterministic multi-relation periodic authority;
- canonical source-topology/reciprocal-transport relation identity;
- no ID/order/count/frequency/proximity ownership choice;
- equivalent/reversed relation canonicalization;
- typed fail-closed conflict/ambiguity;
- every retained relation consumed by hashing, diagnostics, provenance and exact quotient materialization;
- single-annulus G3 behavior retained exactly.

The next Code + Build turn adds compile-only semantic regressions; the following artifact-only turn must prove the exact torus advances beyond the singular-relation rejection while all 17 G3 focused contracts remain green.

The prescribed sphere is a later G4 singularity/completion case. Its current direct failure is at completion (`repeated-boundary-node` plus parity-alternative budget exhaustion), so it does not preempt the earlier torus tracing contract.

## Contract tests versus production authority

Narrow synthetic/reconstructed fixtures isolate invariants but are not acceptance authority for the real pipeline. Exact committed fixture tests must enter the production preprocessing/remesh path and must not inject convenient labels, transitions, target counts, or output cardinalities.

Tests must verify semantic source/topology/transport identities instead of raw DCEL/source numeric IDs or historical discovery order.

## Default suites

Report direct acceptance separately. Explicitly executed focused/direct tests must be excluded from remaining aggregate totals so counts are non-overlapping. Run completion, validation, and compiled API suites after the direct gate decision. Scheduler-sensitive wall-clock ratios are benchmark/closeout evidence only and cannot override semantic gate authority.

## Turn boundaries

Code + Build may edit active-gate implementation and valid producer-level regression tests and compile approved targets, but executes no generated project binary. GitHub workflow compilation is permitted under the workflow policy. Test + Benchmark uses one exact immutable artifact and performs no rebuild or source/test/fixture/validator edit. Review turns do not edit production source/tests.

## Validity and prohibitions

Tests must encode real production contracts and valid scenarios. Never weaken assertions to fit behavior. No validator weakening, fixture special cases, fallback/recovery substitution, generic-producer substitution after authoritative rejection, positional sheet merging, count/order/frequency ownership selection, arbitrary subset search, synthetic topology correction, Euclidean periodic seam welding, post-hoc cell merging, or timeout-as-correctness.
