# Surface-Cell Test-Suite Independent Audit and Redesign Plan

**Status:** authoritative testing-audit decision and staged redesign plan  
**Review type:** documentation-only independent Review  
**Inspected implementation authority:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Planning baseline:** `a3fba7dc83d9d5b77cdbd10794e3c460de526dbc`  
**Repository:** `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8  
**Decision:** **redesign required; the current suite is a contributing part of the recurring-regression system, but it is not the sole cause**  
**Last updated:** 2026-08-10 UTC

> **Durable evidence-retention note:** this document is normative audit/redesign authority, not per-turn evidence. Current Test + Benchmark artifacts/results are retained only in the single current turn report plus durable live trackers. The mandatory cleanup policy in `.agents/Directional/Future_Chat_Session_Handoff.md` requires every Test + Benchmark turn to clean superseded checked-in evidence at start and replace it with current evidence at closeout. Historical per-turn report filenames in the PR audit inventory are provenance tied to cited commits and need not exist at the current branch head.

## 1. Executive decision

The suite is not empty, trivial, or wholly mechanics-only. It has substantial local contract coverage, production-path entry, fail-closed/fallback controls, and independent topology/lineage/disposition authority established by T1.

It remains incomplete proof of the final product because the broader representative matrix, independent field/feature/geometric quality gates, property/metamorphic generation, fuzz/shrinking, calibrated resource baselines, and full corpus hardening remain T2–T6 work.

The historical regression record identifies `TEST_AUTHORITY_COVERAGE_GAP` as six events with five recurrences. Test architecture therefore remains an active regression-control concern even though production architecture is the primary defect source.

## 2. Core testing rule

Every mandatory test or parameterized family must declare six facts:

1. **Intent:** user-visible or stage-boundary contract being proved.
2. **Proved precondition:** evidence the fixture actually enters the semantic state under test.
3. **Stimulus:** public production entry or named target stage.
4. **Independent oracle:** observable input/output relation, not the producer’s own success flag/decision procedure.
5. **Counterexample:** tamper, mutation, or negative fixture that the oracle must reject.
6. **Evidence identity:** fixture/corpus version, deterministic seed where relevant, executable, discovery name, artifact and resource budget.

Required layers are cumulative:

| Layer | Purpose | Examples |
|---|---|---|
| L0 type/schema | invalid states unrepresentable | non-convertible IDs, closed outcomes, schema tamper |
| L1 focused semantic | one relation with positive/negative witness | branch transport, hard rail, source support |
| L2 metamorphic/property | representation changes cannot change semantics | row reorder, reversal, cycle rotation, rigid transform |
| L3 direct representative | public production + independent oracle | plane, seam, close sheets, cylinder, torus, sphere, feature, bunny, vase |
| L4 quality/corpus | field/geometric/quality/resource thresholds | alignment, approximation, scaled Jacobian, RSS/work |

No lower layer may substitute for a required higher layer.

## 3. T0–T6 roadmap

### T0 — audit and authority separation

**Complete.** Established the redesign and separated focused/internal checks from representative product proof.

### T1 — independent oracle/package foundation

**Accepted and preserved through M1d; M1e preservation runtime pending.** T1 established:

- independent product-oracle executable/suite;
- topology/lineage/disposition checks independent of the producer decision;
- mutation/counterexample authority;
- immutable build-package/source/executable/fixture manifests;
- exact discovery and zero-selection rejection;
- artifact-only runtime/preflight/postflight discipline;
- independent oracle execution before fatal product-success assertion on known-red representatives.

M1e Code + Build artifact `9047295489` statically preserves the 29-test T1 oracle manifest and packages six new M1e transport contracts, but compile success is not preservation proof. The following immutable turn must re-establish exact T1 **29/29** and complete producer/direct authority.

### T2 — complete direct semantic matrix

**Pending.** Maintain a versioned semantic manifest and direct production authority for at least:

1. planar irregular triangulated disk;
2. multi-face seam / rotated field transport;
3. disconnected close sheets;
4. cylinder/annulus;
5. torus/genus-one;
6. sphere with prescribed singularity/index structure;
7. thin/anisotropic feature geometry;
8. hard-feature/boundary constrained patch;
9. `bunny_1k_random.obj` irregular triangle mesh;
10. vase-like production mesh.

Inputs must be triangles at the triangle-to-quad entry. Each case declares topology/field/feature preconditions, expected current disposition, independent oracle, resource guard and required-green/known-red/safety role.

### T3 — property/metamorphic generation and shrinking

**Pending.** Add deterministic generated families and shrinkers for row/vertex permutation, equivalent branch representation, route reversal + inverse transport, cycle rotation, component ordering, close-sheet gap variation, topology-preserving local retriangulation, rigid transform/scale and target-size perturbation.

### T4 — sanitizer fuzzing and minimized replay

**Pending.** Add bounded fuzz targets around preprocessing/source support, field metadata, trace/phase-front authority, route/certificate validation, occurrence/quotient materialization and direct-producer preconditions. Run sanitizer tiers with one global work/time/memory guard and deterministic minimized replay.

### T5 — calibrated representative quality/corpus gates

**Pending.** Independently define/calibrate cross-field alignment, source approximation, quad quality, feature adherence, adaptive-size error, singularity/topology preservation and semantic fingerprint metrics. Thresholds require baselines/rationale and cannot be invented inside a failing turn.

### T6 — CI/resource/oracle-adequacy hardening

**Pending.** Establish fast semantic tiers, representative matrix, sanitizer/fuzz replay, scheduled heavy Bunny/Vase/quality/resource runs, mutation adequacy and deterministic package/discovery audit.

## 4. Domain-specific test implications

The supplied Directional Fields, MIQ, QEx, QuadWild, Instant Meshes and FlowRep materials imply:

- field transport is algebraic/topological, so branch/quarter-turn/holonomy relations and their inverses/cycles require explicit tests;
- extraction depends on global topology and local geometry, so components, boundaries, Euler/genus, singularity/index budget, periodic seams, hard features and local-sheet separation require representative evidence;
- seamless/quotient relations are orientation-sensitive, so reversal, cycle rotation, row reordering and canonical-route metamorphisms are mandatory;
- exact/source-authoritative extraction must resist numeric coincidence, so close sheets, thin geometry, source vertices/edges and near-degenerate support require dedicated adversarial tests;
- global constraints precede local construction, so tests must observe shared global authority rather than only successful post-hoc pairing;
- robust meshing claims require varied/adversarial triangle inputs, property generation, shrinking/fuzz replay and representative real meshes.

## 5. Regression-pattern interlock

- `RP-01`: require domain-specific invalid-value/tamper tests and checked adapters.
- `RP-02`: require direct representative + independent oracle; proxy-only closure prohibited.
- `RP-03`: test producer outcome, stage outcome, policy and diagnostics as separate semantics.
- `RP-04`: generated/adversarial cases use one global monotone work/resource guard.
- `RP-05`: order/orientation metamorphisms prove identity independence.
- `RP-06`: resource/state-cardinality tests observe aggregate growth.
- `RP-07`: cyclic/route tests cover modulo representation, wrap, reversal and exact inverse/composition.
- `RP-08`: test `NotApplicable`, `Rejected`, and success as distinct closed outcomes.
- `RP-09`: representative tests distinguish global authority completeness from local witness consumption.

M1e specifically targets `RP-07` at ordered segment-route transport and packages six contracts covering multi-step composition, inverse route, modulo-equivalent signed quarter turns, provenance preservation, malformed authoritative metadata and legacy matching compatibility. The immutable turn must prove those tests establish their stated preconditions rather than weakening them if a fixture is inadequate.

## 6. Independent product oracle requirements

At minimum direct independent verification checks, as applicable:

- success implies non-empty pure-quad output;
- valid indices and finite coordinates;
- manifold/incidence expectations;
- connected components and boundary loops;
- Euler characteristic/genus;
- source support/output-origin and complete lineage requirements;
- terminal failure/disposition truthfulness;
- no fallback/recovery in strict direct mode.

T2/T5 later add independent field alignment, geometric approximation, feature adherence, adaptive-size and calibrated quality gates.

## 7. Oracle mutation adequacy

Mutation/counterexample authority must reject at least:

- empty output under claimed success;
- injected triangle/non-quad face;
- broken component/boundary/Euler topology;
- wrong output origin/fallback flag;
- corrupted source lineage/support;
- changed route transition identity without topology change;
- reversed route without transport inversion;
- corrupted periodic relation ownership;
- removed semantic relation while representation/count remains plausible.

An oracle that accepts the intended corruption is not adequate evidence.

## 8. Immutable Test + Benchmark procedure

Every Test + Benchmark turn:

1. begins with stale checked-in evidence cleanup under the mandatory handoff policy after accepted facts are folded into durable/live authority;
2. consumes exactly one immutable Code + Build artifact;
3. verifies artifact digest, manifest, every checksum, source blobs, executable hashes, fixtures and build metadata before runtime;
4. performs exact discovery and rejects zero selection;
5. runs focused contracts plus all required preserved independent/representative gates;
6. keeps every known-red case explicitly accounted for;
7. applies explicit process/resource guards to long-running cases;
8. uses artifact-only remote runtime only after exact artifact verification when authorized;
9. re-verifies artifact/package/executable authority postflight;
10. classifies pass/fail from raw test/oracle evidence, never workflow status alone;
11. ends by replacing stale evidence: commit the new current TB report plus exactly one next Code + Build plan, remove consumed/superseded turn evidence, and repair live references.

External Actions artifacts remain governed by retention policy; repository cleanup removes stale checked-in summaries, not immutable artifact history.

## 9. Acceptance hierarchy

```text
compile/link
< helper/mechanical unit relation
< focused production-path semantic test
< tamper/metamorphic contract
< complete target discovery/accounting
< independent product oracle
< representative real production fixture
< representative + independent quality/topology/field metrics
< generated/fuzzed adversarial corpus with deterministic replay
```

## 10. Current integration rule

Architecture migration M1–M6 and test redesign T2–T6 remain separate but interlocked axes. Each bounded architecture slice must preserve accepted T1 authority. New focused tests supplement but never replace complete producer accounting, known-red classification, direct product oracles and immutable package postflight.

The exact current action is never taken from this durable redesign plan. Read `.agents/Directional/Future_Chat_Session_Handoff.md` first.
