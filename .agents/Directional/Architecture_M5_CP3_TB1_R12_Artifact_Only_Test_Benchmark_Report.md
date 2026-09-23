# M5-CP3-TB1-R12 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R12-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark on CB14 candidate `10725395682 / b8dc3e906dd03525861a1985ea574bad1ad5c69a`
**Disposition:** **MECHANICALLY COMPLETE / SEMANTIC RED / 439 PASS + 7 RED / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R12-REV`

## 1. Immutable authority

R12 consumes only the compile-green CB14 candidate and the previously frozen routing/selector authority:

- semantic source `b8dc3e906dd03525861a1985ea574bad1ad5c69a`;
- compile run/job `35798853372 / 106984376759`;
- candidate artifact `10725395682`, ZIP SHA-256 `1995b8cf3de6190bff60f0e8d4ad74de90cc82327b80fd5c29f2fc0eb089d902`;
- root package manifest SHA-256 `92fb6c0747db81514b2060ab195d3b7e68ede14c035c1b7f116a4e8a36679279`, **28/28**;
- packaged source archive SHA-256 `1bfd66e0a2c9a4b78dffe0280859130eed8bcd6e34032c07255bd0aaa83829bd`;
- routing artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- routing identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Preflight verified provider/download digest equality, executable modes, clean packaged source receipts, GMP/GMPXX evidence, `runtimeExecution=false`, exact selector/routing identity and the frozen owner census. No package repair or permission repair occurred.

## 2. Runtime and complete evidence contract

R12 run/job is `35802519951 / 106995887964`, event SHA `eaa54350b5cbd83182709d2e640ffaf6f12fbe7d`. Workflow schema validation and the runtime job both conclude success; runtime-job success means orchestration completed, not semantic green.

Result/log artifacts are:

- result `10726868409`, ZIP SHA-256 `3f5978b7e0753dccd68fa53ddc50e50b3a5d4d3ea61d2bbd6e9da688531877bc`;
- log `10726518857`, ZIP SHA-256 `146fa160681f012c10979eb8018f6b91e1ad41b2ce5ef5c02c70dc0f36a9d265`.

The result contains exactly **912 actual non-manifest evidence files** and **912 manifest rows**. Every row verifies. Result `SHA256SUMS` SHA-256 is `fd3ad48624f311feb1bfb5a19e00a9515dc00f231f90b2409bb9676677891524`. The execution boundary records `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`, and all prohibited-operation counters at zero.

Driver authority records template SHA-256 `f6509aa8e191db679ebe2ab983e00c735993d8899554856cdf1da4c6a350a4f5`, writer SHA-256 `d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`, and rendered-driver SHA-256 `3f518fe03adcd131fc3c59e41ba67ce62c8cc4249dae3edb2a195edecffb4936`.

## 3. Fresh 446-process semantic ledger

All **446/446** planned processes execute freshly. Every process selects exactly one test and skips zero tests.

| Phase | PASS | RED | Total |
|---|---:|---:|---:|
| nine reviewed mechanism identities | 9 | 0 | 9 |
| focused atlas identity | 1 | 0 | 1 |
| produced identities | 0 | 6 | 6 |
| selector430 | 429 | 1 | 430 |
| **total** | **439** | **7** | **446** |

Protected selector ordinals **191, 192 and 247 PASS**. Protected ordinal **408 REDs**. Benchmark count is **0**.

The seven RED identities split into two distinct runtime fronts.

### 3.1 New regression front: produced rows 1/2/3/6 plus selector ordinal408

Produced rows 1/2/3/6 all fail while constructing the ordinary torus production fixture with:

```text
torus pipeline producer failed: InvalidFinalCellState
```

Those same four produced controls were PASS in authoritative R11-R1 runtime. Selector ordinal408,
`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, also changes from PASS in R11-R1 to RED in R12. It reaches the retained trace network but observes `phaseFront.disposition()==Rejected` instead of `Produced`; the pipeline surface reports `NotProductionReady/tracing/None`.

This regression happens before rows 1/2/3/6 reach their relation-specific assertions, so none of their previously discharged debt/control claims may be re-used as R12 PASS evidence.

### 3.2 Failed recovery front: produced rows 4/5

Rows 4/5 remain RED at the exact pre-CB14 public frontier:

```text
torus nonzero-Z4 source witness producer failed: PeriodicActionCorrespondenceMismatch
```

Row4 still does not reach relation materialization, selected-certificate consumption, or `consumedPeriodicHolonomies > 0`. Row5 still does not reach its transform-only tamper or typed `NonReciprocalPeriodicRelation` assertion. CB14 therefore does **not** runtime-prove recovery of `M5-CP3-TB1-R11-R1-CAND-01`.

## 4. Bounded root-cause analysis for mandatory Review

### 4.1 `M5-CP3-TB1-R12-CAND-01` — exact-A3 checked-product representation/gauge mismatch candidate

**Status:** OPEN / PRODUCT SEMANTIC REGRESSION / NON-STABLE / REVIEW ADJUDICATION REQUIRED / +0.

The four ordinary produced rows report `InvalidFinalCellState`. In the candidate source, `publish_phase_front_result(...)` overwrites the public reason with `InvalidFinalCellState` specifically when `SurfacePhaseFrontProduct::make(...)` rejects the completed build state. This localizes the new regression after phase-front construction and before a checked product is published.

CB14 changed that checked-product path for exact A3 periodic pairs. It now binds `forwardEdge`/`reverseEdge` from A3 occurrence orientation and validates their new `periodicFromLattice` / `periodicToLattice` states against the stored relation's `action()` and `cutRoute()`.

A concrete static authority hazard exists immediately before that validation: `insert_periodic_holonomy(...)` calls `canonicalize_periodic_holonomy(...)`, which is allowed to replace a relation with `inverseAction`, `route.reversed()` and `cutRoute.reversed()` when the inverse representation has the lower canonical action key. `PeriodicRelationId` is orientation-neutral, while the already-authored edge endpoint states and A3 Forward/Reverse occurrence labels are not rewritten after this canonicalization. The checked-product branch then compares those semantic A3-directed endpoint states against the storage-canonical relation representation.

That is a bounded, source-supported `RP-01`-class authority-domain candidate: **semantic A3 direction / endpoint gauge may be conflated with storage-canonical relation orientation**. EXEC does not claim the canonicalizer definitely inverted the failing torus pair because the final public failure drops the `SurfacePhaseFrontProductError` subcode and no operand receipt was emitted. Mandatory Review must prove or reject this candidate before assigning stable recurrence credit or authorizing a code change.

### 4.2 Existing R11-R1 endpoint-gauge candidate remains unrecovered

Rows4/5 still stop at `PeriodicActionCorrespondenceMismatch`. CB14 refactored `periodic_action_for_pair(...)` to consume four typed endpoint states, but the public reason still merges `action == nullopt` with route/action rotation disagreement. A returned action is built with the supplied generator rotation, so the remaining runtime evidence strongly localizes to action construction, but the helper now contains several new predicates and R12 emits none of their operands. EXEC therefore does not invent a first-false subpredicate.

`M5-CP3-TB1-R11-R1-CAND-01` remains OPEN as a failed recovery of existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`. The reopened `M5-CP3-TB1-R6-REV-OBS-01` also remains OPEN because row4 still does not pass the correspondence comparator; neither independent Forward -> Reverse agreement nor inverted-pair rejection executes.

### 4.3 Accounting

Stable accounting remains **50 events / 14 categories / 36 recurrences** and produced-witness debt remains **3**. R12 exposes a real accepted-selector-row regression at ordinal408, but this candidate is unpromoted and the exact recurrence/category assignment is reserved for mandatory Review. No stable count is changed in EXEC.

## 5. Immutable postflight

Postflight is exact:

- candidate package byte/mode census unchanged;
- packaged-source census unchanged;
- execution-view census unchanged;
- candidate manifest still **28/28**;
- selector430 and first427 unchanged;
- routing identity map unchanged;
- benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters all **0**.

No rebuild, configure, relink, generated discovery, source/test/fixture/selector mutation, package mutation, permission repair, rerun, or evidence stitching occurred.

## 6. Authority and successor

CB14 candidate `10725395682 / b8dc3e906dd03525861a1985ea574bad1ad5c69a` remains **unpromoted**. Accepted runtime authority remains `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. The two nonzero-Z4 M5 debts remain open and selector publication remains prohibited.

The mandatory runtime-free successor is **`M5-CP3-TB1-R12-REV`**. It must independently re-open R12 evidence, adjudicate `M5-CP3-TB1-R12-CAND-01`, split the surviving row4/5 correspondence frontier as far as evidence permits, decide stable accounting, and issue exactly one bounded successor plan. No retry or Code + Build is authorized before that Review.
