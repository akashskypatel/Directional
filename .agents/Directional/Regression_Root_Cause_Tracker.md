# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed historical event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; the current retained turn report owns current artifact/build/runtime detail.

Last updated: **2026-08-10 UTC** after M1e Code + Build artifact `9047295489` (**immutable runtime pending**).

## Rules

- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence while a gate remains red is not a recurrence; recurrence requires restoration followed by later loss.
- Compile success never resolves runtime or architecture migration work.
- New migration code remains pending until immutable semantic acceptance.
- Known-red/deferred product cases stay explicit and are never relabeled green merely to close architecture work.
- Focused/helper passes cannot close representative product intent.
- Before every turn review `RP-01` through `RP-09`; every touched pattern needs an exact invariant and counterexample/representative gate.
- Stale per-turn documents are not historical authority. Once their necessary facts are folded into this tracker/current report/audit inventory, they may be removed under the durable handoff cleanup policy.

## Historical PR-wide authority

- **34 distinct regression events**;
- **14 architectural categories**;
- **20 recurrences**;
- **114 regression-bearing result-document commits**.

Accepted T1/M1a/M1b/M1c/M1d artifacts create no new regression event or recurrence. M1e artifact `9047295489` is compile/package evidence only and therefore creates no stable runtime event. `PR8-R034 / G4-R007` remains active.

| Cause category | Pattern | Events | Recurrences |
|---|---|---:|---:|
| `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | 6 | 5 |
| `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | 6 | 5 |
| `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | 4 | 3 |
| `NONTERMINATING_CUMULATIVE_WORK` | `RP-04` | 3 | 2 |
| `REPRESENTATION_DEPENDENT_IDENTITY` | `RP-05` | 2 | 1 |
| `STATE_CARDINALITY_GROWTH` | `RP-06` | 2 | 1 |
| `CYCLIC_TOPOLOGY_LINEARIZATION` | `RP-07` | 2 | 1 |
| `PRODUCER_DISPOSITION_CONFLATION` | `RP-08` | 2 | 1 |
| `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | 2 | 1 |
| five singleton categories | — | 5 | 0 |
| **Total** |  | **34** | **20** |

Singletons: `INTRINSIC_SUPPORT_OVERCONSTRAINT`, `INCOMPLETE_TRANSACTIONAL_ROLLBACK`, `SHARED_EDGE_ORIENTATION_INVERSION`, `INCOMPLETE_ORBIT_PUBLICATION`, `EXACT_SIMPLEX_CANONICALIZATION_LOSS`.

## Repeated coding-pattern catalog

### RP-01 — authority-domain conflation

```text
bad: one bare integer is reused as face/transition/chart/rail/etc.
good: distinct semantic type + named checked adapter + typed failure.
```

- M1a strong-ID kernel: **accepted**.
- M1b source-face/source-vertex consumer: **accepted**.
- M1c field-transition consumer: **accepted**.
- M1d phase-front route source-vertex/interior-transition consumer: **accepted**.
- M1e ordered segment-route step domains: **compile-complete; immutable runtime pending**.

M1e now checks packed step endpoints through `LegacyAuthorityAdapters::source_vertex`, canonicalizes them with `SourceEdgeTopologyKey`, and checks compact source-edge provenance through `LegacyAuthorityAdapters::interior_transition` before constructing semantic `TransitionStep`s. Malformed-domain behavior must be proven fail-closed in the immutable turn.

### RP-02 — proxy/incomplete test authority

```text
bad: compile/helper/status/count claimed as product proof.
good: named semantic contract + independent oracle + direct representative evidence.
```

Accepted authority through M1d remains producer **178**, required-green **163/163**, M1d **6/6 + 3/3**, M1c **6/6 + 3/3**, M1b **6/6 + validation 77/77**, M1a **14/14**, T1 **29/29**, four direct oracle-clean cases, nine explicit historical/deferred reds, Bunny known-red, and Vase bounded safety-only.

M1e statically adds exactly six focused contracts and expects producer discovery **184** / required-green **169**. Those counts and all preservation authority are runtime-pending and may not be inferred from compile success.

### RP-03 — policy/stage state conflation

```text
bad: attempted/succeeded/disposition/debug retention are combined into mutable policy state.
good: closed producer outcome + single-writer stage product + derived diagnostics.
```

Untouched by M1a–M1e. M2 owns migration.

### RP-04 — nonterminating cumulative work

```text
bad: local bounds compose into globally unbounded cumulative work.
good: one shared work ledger + monotone progress + deterministic exhaustion failure.
```

Untouched by M1a–M1e. M1e adds no search/retry loop. Vase remains bounded safety-only evidence.

### RP-05 — representation-dependent identity

```text
bad: row/hash/traversal/allocation position becomes semantic identity.
good: semantic strong ID/key is authoritative; representation is compatibility only.
```

- M1a semantic ID/key kernel: **accepted**.
- M1b source semantic identity versus row representation: **accepted**.
- M1c canonical source-edge identity: **accepted**.
- M1d route identity versus packed route key/index: **accepted**.
- M1e ordered route-step identity/orientation: **compile-complete; immutable runtime pending**.

M1e stores semantic step identity as canonical `SourceEdgeTopologyKey` + checked `InteriorTransitionId`. `CanonicalRoute` owns canonical storage, while `oriented_steps()` restores the behaviorally observed route direction before transport composition. The immutable reverse-route and provenance contracts must prove representation independence.

### RP-06 — state-cardinality growth

```text
bad: copied mutable authority tables accumulate across stages/regions.
good: one immutable authority product/reference per semantic fact.
```

Untouched by M1a–M1e. M2/M4 own shared authority storage.

### RP-07 — cyclic topology linearization

```text
bad: quarter-turn/cyclic transport is accumulated as unrestricted signed integer arithmetic.
good: exact modulo-4 semantic algebra + explicit inverse/composition; raw integer only at compatibility boundary.
```

M1c individual edge transport is **accepted** through `QuarterTurn::from_integer` and exact inverse semantics.

M1e is the next direct `RP-07` slice and is **compile-complete/runtime pending**: `segment_on_source` no longer performs raw cumulative `totalMatching += transition.matching`. Each crossing is a zero-shift `GridAutomorphism` inside a `TransitionStep`; the observed steps form a `CanonicalRoute`; `oriented_steps()` is composed algebraically; only the final quarter-turn value is written to raw `current.matching`.

The separate periodic-holonomy accumulation remains outside M1e.

### RP-08 — producer-disposition conflation

Untouched. M2 owns migration.

### RP-09 — local consumption of global authority

Untouched by M1a–M1e. `G4-R007` remains active; M3/M4 own global conformity/certificate migration.

## M1e compile-only pattern record

| Pattern | State | Compile/package evidence | Immutable requirement |
|---|---|---|---|
| `RP-01` | **compile-complete** | checked source vertices + interior transitions | M1e exact 6/6 + preservation |
| `RP-05` | **compile-complete** | canonical step identity + observed orientation recovery | reverse/provenance semantic evidence |
| `RP-07` | **compile-complete** | typed route automorphism composition replaces raw cumulative matching | multi-step/equivalent/reverse route evidence |
| `RP-02 / TA-05` | **preservation pending** | accepted manifests and 6 new contracts packaged | exact 184 accounting + M1d/M1c/M1b/M1a/T1/direct authority |

M1e compile/package authority:

- final implementation `bb9cb63a36b64fe2f7c462ad864492c8352b65e8`;
- build run/job `31345475101 / 93326482946`;
- result artifact `9047295489`, SHA-256 `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f`;
- log artifact `9047295703`, SHA-256 `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52`;
- manifest **61/61**, SHA-256 `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e`;
- Release/static/Ninja **120/120**, `runtimeExecution=false`.

The first implementation `9edbef1fe34d60d2a507160aa4a27883cea36903` was compile-red due to incorrect `GridAutomorphism` API use (`Eigen::Vector2i` instead of `LatticeTranslation`, qualified hidden-friend `compose`). It was corrected inside the same Code + Build turn before any generated runtime. Two v2 workflow syntax failures created no jobs. These are not stable runtime regression events.

## Current G4 stable-ID mapping

| PR event | G4 ID | Category | Pattern | Status |
|---|---|---|---|---|
| `PR8-R028` | `G4-R001` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R029` | `G4-R002` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | resolved |
| `PR8-R030` | `G4-R003` | `TEST_AUTHORITY_COVERAGE_GAP` | `RP-02` | resolved |
| `PR8-R031` | `G4-R004` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | resolved |
| `PR8-R032` | `G4-R005` | `POLICY_STAGE_STATE_CONFLATION` | `RP-03` | resolved |
| `PR8-R033` | `G4-R006` | `AUTHORITY_DOMAIN_CONFLATION` | `RP-01` | test-authority resolved |
| `PR8-R034` | `G4-R007` | `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` | `RP-09` | **active** |

`G4-R007` authority remains production artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. M1 migration does not repair or reinterpret it.

## Persistent blockers

| ID | Blocker | Required gate |
|---|---|---|
| `G4-B001` | Direct torus final `LocalSheetMismatch`. | strict-valid torus 3/3 |
| `G4-B002` | Exact Phase10 torus `InvalidHardRailPairing`. | shared source-authoritative rail schedule; M3 |
| `G4-B003` | Nonzero periodic Z4 production capability. | staged M1/M4 adoption + product acceptance |
| `G4-B004` | Positive multi-isolation quotient witness. | focused + representative certificate evidence |

## Architecture enforcement register

| ID | State |
|---|---|
| `AR-01` | M2: closed producer outcomes |
| `AR-02` | M1a–M1d accepted; **M1e ordered step/transport adoption compile-complete/runtime pending** |
| `AR-03` | strong identity through M1d accepted; M1e typed step identity runtime pending |
| `AR-04` | `FieldChartId` exists; production chart migration later M1 |
| `AR-05` | representation boundaries through M1d accepted; M1e observed/canonical orientation runtime pending |
| `AR-06` | M4 relation registry/certificates |
| `AR-07` | M3 global conformity |
| `AR-08` | M2/M3 producer-scoped immutable output |
| `AR-09` | exact source-support rebinding M5 |
| `AR-10` | incremental responsibility modules |
| `AR-11` | normative architecture/status separation maintained |
| `AR-12` | T1 independent oracle/package accepted; T2–T6 expand authority |

## Test architecture register

| ID | State |
|---|---|
| `TA-01` | topology/lineage/disposition accepted; geometry/field/quality later |
| `TA-02` | T2 ten-case direct matrix pending |
| `TA-03` | metric definitions/baselines pending |
| `TA-04` | T3/T4 generation/shrinking/fuzz pending |
| `TA-05` | preserved through M1d; **M1e preservation runtime pending** |
| `TA-06` | T1 mutation suite 29/29 accepted; M1e preservation pending |
| `TA-07` | M1e exact package authority compile-complete; runtime discovery pending |
| `TA-08` | M1e six route-composition semantic/counterexample tests compiled; runtime pending |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | topology/lineage/disposition adequate; quality expansion later |
| `TA-12` | `tests/TESTING_STRATEGY.md` normative only |

## Authoritative next step

`.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

The next turn is **immutable Test + Benchmark only**. It consumes exactly artifacts `9047295489 / 9047295703`, rebuilds/edits nothing, requires producer discovery 184 / required-green 169, proves M1e route-composition semantics, and independently preserves M1d/M1c/M1b/M1a/T1/direct authority.