# M5-CP3-TB1-R12 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R12-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark on CB14 candidate
**Disposition:** **MECHANICALLY COMPLETE / SEMANTIC RED / 439 PASS + 7 RED / CB14 RECOVERY FAILED / NEW ZERO-ROTATION CONTROL REGRESSION / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R12-REV`

## 1. Immutable authority

R12 consumes only CB14 candidate artifact `10725395682`, semantic source
`b8dc3e906dd03525861a1985ea574bad1ad5c69a`, accepted routing artifact `10592987234`, and byte-frozen selector430.
The candidate ZIP/provider digest is
`1995b8cf3de6190bff60f0e8d4ad74de90cc82327b80fd5c29f2fc0eb089d902`; root manifest SHA-256 is
`92fb6c0747db81514b2060ab195d3b7e68ede14c035c1b7f116a4e8a36679279` and verifies **28/28**. Packaged source archive SHA-256 is
`1bfd66e0a2c9a4b78dffe0280859130eed8bcd6e34032c07255bd0aaa83829bd`. Routing ZIP and identity-map SHA-256 remain
`352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce` and
`7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`; selector430 / first427 remain
`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 / f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Preflight confirms executable mode, clean source receipts, GMP/GMPXX linkage evidence, and `runtimeExecution=false`. No package repair,
mode repair, compile, relink, configure, generated discovery, source/test/fixture/selector mutation, or benchmark execution occurs.

## 2. Runtime and evidence contract

R12 run/job is `35802519951 / 106995887964`, event SHA `eaa54350b5cbd83182709d2e640ffaf6f12fbe7d`.
Schema validation and the runtime job conclude success; job success means orchestration completed, not that the semantic gate is green.

Result/log artifacts are:

- result `10726868409`, ZIP SHA-256 `3f5978b7e0753dccd68fa53ddc50e50b3a5d4d3ea61d2bbd6e9da688531877bc`;
- log `10726518857`, ZIP SHA-256 `146fa160681f012c10979eb8018f6b91e1ad41b2ce5ef5c02c70dc0f36a9d265`.

The result contains **912 actual non-manifest evidence files** and exactly **912 manifest rows**. Every row verifies; result
`SHA256SUMS` SHA-256 is `fd3ad48624f311feb1bfb5a19e00a9515dc00f231f90b2409bb9676677891524`.
`driver_exit=0`, `orchestration_failure=false`, and immutable package/source/execution-view postflight is exact.

Driver authority records template SHA-256
`f6509aa8e191db679ebe2ab983e00c735993d8899554856cdf1da4c6a350a4f5`, writer SHA-256
`d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`, and rendered-driver SHA-256
`3f518fe03adcd131fc3c59e41ba67ce62c8cc4249dae3edb2a195edecffb4936`.

## 3. Fresh 446-process semantic ledger

All **446/446** planned processes execute freshly, each selecting exactly one test with zero skips:

| Phase | PASS | RED | Total |
|---|---:|---:|---:|
| nine reviewed mechanism identities | 9 | 0 | 9 |
| focused atlas identity | 1 | 0 | 1 |
| produced identities | 0 | 6 | 6 |
| selector430 | 429 | 1 | 430 |
| **total** | **439** | **7** | **446** |

Produced rows **1/2/3/6**, which were PASS in R11-R1 and were frozen regression controls for R12, all reject during real torus
production with `InvalidFinalCellState` before their relation-owner/container-order discriminators execute.

Produced rows **4/5** remain RED at the same public frontier as R11-R1: both fail while constructing the nonzero-Z4 witness with
`PeriodicActionCorrespondenceMismatch`. Row4 therefore still does not reach relation materialization/certificate consumption, and row5
still does not reach its transform-only tamper or typed `NonReciprocalPeriodicRelation` assertion.

Selector ordinals **191, 192 and 247** remain PASS. Protected ordinal **408** regresses to RED at its required production assertion:
`SurfaceCellProducerDisposition::Produced` was expected but the phase-front disposition is rejected; its diagnostic surface reports
`NotProductionReady/tracing/None`. Selector430 is therefore **429/430**, not green. Benchmark count is **0**.

## 4. Regression categorization and bounded root-cause analysis

### `M5-CP3-TB1-R12-CAND-01` — failed recovery of existing nonzero-Z4 correspondence defect

**Status:** OPEN / PRODUCT SEMANTIC RED / EXISTING `RP-01 / AUTHORITY_DOMAIN_CONFLATION` RECOVERY NOT PROVED / NON-STABLE / +0 / OWNER `M5-CP3-TB1-R12-REV`.

CB14 does not move rows4/5 past `PeriodicActionCorrespondenceMismatch`. The new relation-owned endpoint state is therefore not yet
runtime-proved to satisfy the real produced nonzero-Z4 pair. EXEC cannot truthfully select the failing internal predicate because
`periodic_action_for_pair(...)` still collapses occurrence/orientation, chart, scale, branch-rotation, delta, and exact endpoint-map
conditions to one public reason and the produced witness emits no operands before throwing. Mandatory Review must re-derive those
predicates from source authority rather than infer them from the generic reason.

### `M5-CP3-TB1-R12-CAND-02` — CB14 introduces a zero-rotation/direct-production regression candidate

**Status:** OPEN / PRODUCT REGRESSION CANDIDATE / R11-R1 GREEN CONTROLS -> R12 RED / PROTECTED SELECTOR408 PASS -> RED / EXACT PRODUCT PREDICATE UNRESOLVED / NON-STABLE / +0 / OWNER `M5-CP3-TB1-R12-REV`.

R11-R1 proved produced rows1/2/3/6 and selector430 **430/430** green on CB12. R12 changes no gate identity, routing, selector, fixture,
or execution contract, yet all four produced controls now fail `InvalidFinalCellState` and protected ordinal408 becomes RED. The CB14
semantic delta adds relation-endpoint state plus an exact-A3 checked-product validation branch and changes same-region action construction.
The four zero-rotation controls do **not** stop at the producer's typed `PeriodicActionCorrespondenceMismatch`; they reach the later
generic `InvalidFinalCellState` surface. Current public failure reporting maps checked-product construction failure to that generic reason,
so EXEC cannot claim the exact failing validator predicate. Review must independently determine whether the new exact-A3 checked-product
endpoint-state checks are the first false predicate and whether the historical frozen `R=0` reduction remains semantically valid under
CB14.

The two candidates are kept distinct entering Review: row4/5 show **failed recovery** of the prior nonzero-Z4 target, while rows1/2/3/6
plus ordinal408 are a **new regression surface** introduced on previously green controls. Review may merge them only if one proved cause
owns both.

Stable accounting remains **50 events / 14 categories / 36 recurrences** in EXEC. This candidate is unpromoted and the exact new
regression cause/category has not yet been independently adjudicated; no stable ID/count is invented here. Produced-witness debt remains
**3**.

## 5. Immutable postflight

Postflight proves:

- package byte/mode census unchanged;
- packaged-source census unchanged;
- execution-view census unchanged;
- candidate manifest remains **28/28**;
- selector430 / first427 unchanged;
- routing identity map unchanged;
- benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters all **0**.

No rerun or repair occurred after runtime began.

## 6. Authority and successor

CB14 candidate `10725395682 / b8dc3e906dd03525861a1985ea574bad1ad5c69a` remains **unpromoted**. Accepted runtime authority remains
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Selector publication remains prohibited;
no M5 debt or inherited observation is discharged by EXEC.

The exact mandatory successor is runtime-free **`M5-CP3-TB1-R12-REV`**. It must independently re-open the R12 evidence and semantic
delta, adjudicate both candidates, determine whether the new zero-rotation regression is a new stable recurrence or continuation of the
existing `RP-01` event, and freeze exactly one corrective successor. Because row4 does not pass the second-endpoint correspondence path,
the reopened independent Forward -> Reverse observation remains open.
