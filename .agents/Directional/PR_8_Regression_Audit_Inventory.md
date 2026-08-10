# PR #8 Regression Audit Inventory

**Status:** durable historical regression-event inventory  
**Audited historical range:** `d8b4dba98747d3adf0ca24002642bcad9e9847db..8ef353034641c3a068095334ceea5e6ddb0c39c1`  
**Range size:** 1,790 commits  
**Last current-status alignment:** 2026-08-10 UTC

This inventory preserves the 34-event historical audit and the point-in-time code-pattern evidence that produced the nine repeated-pattern classes. It is durable and excluded from routine `.agents/Directional` cleanup. Superseded report filenames below are **historical commit-bound provenance**; they need not exist at the current branch head. Current artifact/runtime evidence belongs to the single retained turn report, while current stable pattern state belongs to `Regression_Root_Cause_Tracker.md`.

## Scope and counting rules

The original case-insensitive history audit found **114 commits** in the primary result-document corpus:

- **55** Test + Benchmark report introductions containing `regress*`;
- **34** machine-result or result-summary updates;
- **25** amendments, removals, or other report-lifecycle changes.

Plans, TODOs, handoffs, reviews, and Code + Build reports were corroborating evidence only. They could explain a runtime event but could not create one. The word *regression* in a passing test name also did not create an event.

An inventory event requires at least one of:

1. baseline-to-candidate loss in runtime or test authority;
2. newly invalid test/oracle contract;
3. newly exposed executable/artifact-coverage defect.

Consecutive artifacts showing the same unresolved cause are persistence, not a new event. A later loss after the affected authority was restored is a recurrence and receives a new `PR8-Rnnn` ID. Compile-only migration failures without loss of accepted runtime authority are not stable regression events.

## Category totals

| Category | Pattern | Events | Recurrences |
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
| `INTRINSIC_SUPPORT_OVERCONSTRAINT` | — | 1 | 0 |
| `INCOMPLETE_TRANSACTIONAL_ROLLBACK` | — | 1 | 0 |
| `SHARED_EDGE_ORIENTATION_INVERSION` | — | 1 | 0 |
| `INCOMPLETE_ORBIT_PUBLICATION` | — | 1 | 0 |
| `EXACT_SIMPLEX_CANONICALIZATION_LOSS` | — | 1 | 0 |
| **Total** |  | **34** | **20** |

## Repeated coding-pattern mapping

The nine repeated patterns cover **29 events** and all **20 recurrences**. The five other categories remain singletons.

| Pattern | Event mapping | Repeated finding |
|---|---|---|
| `RP-01` | `R007`, `R014`, `R019`, `R028`, `R031`, `R033` | Consumers guessed numeric/index domains or intersected local labels as if they were intrinsic authority. |
| `RP-02` | `R004`, `R013`, `R022`, `R024`, `R027`, `R030` | A proxy, raw ID, lifecycle observation, impossible witness, or nonpackaged test stood in for production semantic authority. |
| `RP-03` | `R006`, `R009`, `R011`, `R032` | One mode/flag/result encoded independent execution, policy, availability, or stage meanings. |
| `RP-04` | `R003`, `R010`, `R020` | Per-loop/depth limits did not bound recursive, nested, or process-cumulative work globally. |
| `RP-05` | `R016`, `R026` | Identity/emission order depended on role, traversal orientation, hash, or component enumeration. |
| `RP-06` | `R001`, `R008` | Complete shared ownership membership was duplicated per local consumer. |
| `RP-07` | `R017`, `R018` | Cyclic fan/sector relations were interpreted as a linear unique-neighbor sequence. |
| `RP-08` | `R021`, `R025` | Typed producer disposition collapsed into a boolean/default aggregate, enabling substitution after authoritative rejection. |
| `RP-09` | `R029`, `R034` | Complete global authority was required on one local face/path rather than globally validated and locally witnessed. |

## Event inventory

### PR8-R001 — ownership diagnostics multiply retained state

- Historical evidence: `8002ded548a685e2fec3374534bd5f0afb4b0db6`.
- Delta: random-bunny peak working set and completion time rose sharply.
- Cause: complete ownership identity/membership retained per completion object instead of shared compact storage.
- Category: `STATE_CARDINALITY_GROWTH`; first event.
- Disposition: resolved by later ownership compaction.

### PR8-R002 — stored chart face rejects valid intrinsic source support

- Historical evidence: `c46aa49ea6a0cb74221c1768790c28af7d203e96`.
- Delta: valid cylinder shared-boundary contracts regressed.
- Cause: scalar stored face was treated as complete intrinsic support for an edge/vertex-supported point.
- Category: `INTRINSIC_SUPPORT_OVERCONSTRAINT`.
- Disposition: resolved by intrinsic source-entity support checks.

### PR8-R003 — recursive whole-complex repair is nonterminating

- Historical evidence: `e8e1b3d15c1165aa4f242c70cd2519b5ba7b946d`.
- Delta: random-bunny processes hit guards at multi-GB memory despite focused green suites.
- Cause: recursive whole-complex copying/recomputation under only depth-local limits.
- Category: `NONTERMINATING_CUMULATIVE_WORK`; first event.
- Disposition: resolved by shared bounded controller/global candidate ledger.

### PR8-R004 — passing tests do not execute structural repair

- Historical evidence: same checkpoint as R003.
- Delta: focused inventory passed while the intended structural-repair production path was not executed/asserted.
- Category: `TEST_AUTHORITY_COVERAGE_GAP`; first event.
- Disposition: resolved by direct whole-complex budget/ledger fixtures and explicit preconditions.

### PR8-R005 — rejected side repair returns mutated rollback state

- Historical evidence: `760cd187a24005380058e6119db2b55e12e54d44`.
- Cause: failure path exposed a transactionally mutated complex instead of the committed prior state.
- Category: `INCOMPLETE_TRANSACTIONAL_ROLLBACK`.
- Disposition: resolved by exact committed-state rollback.

### PR8-R006 — simplification policy suppresses fixed-point refresh

- Historical evidence: `c960dc42101fe473cecd3f8416b8fba7a103609d`.
- Cause: internal policy/mode branch silently changed default explicit-candidate behavior.
- Category: `POLICY_STAGE_STATE_CONFLATION`; first event.
- Disposition: resolved by restoring dependency-bounded default refresh.

### PR8-R007 — component ownership conflated with local-sheet intersection

- Historical evidence: `84518e5d67c5e2ce2530556f33d073d1fe6e1411`.
- Cause: strict `(component, local-sheet)` intersection imposed across boundary provenance where adjacent traces legitimately crossed local chart labels.
- Category: `AUTHORITY_DOMAIN_CONFLATION`; first event.
- Disposition: resolved by canonical intrinsic ownership construction.

### PR8-R008 — ownership class membership duplicated quadratically

- Historical evidence: `6b75ee51a06a227ce36455e18e93bd5c067fba6d`.
- Cause: every cell serialized complete component-wide chart membership.
- Category: `STATE_CARDINALITY_GROWTH`; recurrence of R001.
- Disposition: resolved by interned membership registry + fixed-size keys.

### PR8-R009 — real completion validation preempts injected stage authority

- Historical evidence: `25f7ecc98c9860220c809d671d39d4a52e895161`.
- Cause: real producer validity and synthetic injected-stage policy shared one terminal-state path.
- Category: `POLICY_STAGE_STATE_CONFLATION`; recurrence.

### PR8-R010 — local candidate limits do not bound recursive repair work

- Cause pattern: nested/recursive work obeyed local limits while global cumulative work escaped bounds.
- Category: `NONTERMINATING_CUMULATIVE_WORK`; recurrence.

### PR8-R011 — fallback/public policy conflated with stage availability

- Cause pattern: one option/state encoded whether a stage executed, whether its product was public, and whether fallback was allowed.
- Category: `POLICY_STAGE_STATE_CONFLATION`; recurrence.

### PR8-R012 — shared-edge orientation contract inverted

- Cause: valid opposite traversal and invalid same-direction traversal were reversed.
- Category: `SHARED_EDGE_ORIENTATION_INVERSION`.

### PR8-R013 — requested validator contract absent from packaged executable

- Cause: source/test presence was treated as execution authority without package/discovery proof.
- Category: `TEST_AUTHORITY_COVERAGE_GAP`; recurrence.

### PR8-R014 — compact/full edge domains conflated

- Cause: consumer accepted or compared edge/transition indices across incompatible numeric domains.
- Category: `AUTHORITY_DOMAIN_CONFLATION`; recurrence.

### PR8-R015 — audited topology omitted before ownership publication

- Cause: a valid orbit/member set was incomplete when published downstream.
- Category: `INCOMPLETE_ORBIT_PUBLICATION`.

### PR8-R016 — source identity depends on traversal/emission representation

- Cause: semantic identity included orientation/emission details.
- Category: `REPRESENTATION_DEPENDENT_IDENTITY`; first event.

### PR8-R017 / R018 — cyclic topology linearized

- Causes: duplicate degree-two neighbor values and cyclic wraparound were rejected as if a fan were a linear unique sequence.
- Category: `CYCLIC_TOPOLOGY_LINEARIZATION`; R018 recurrence.

### PR8-R019 — region/local compact authority conflated

- Cause: consumer interpreted an integer in a different transition/region domain than its producer.
- Category: `AUTHORITY_DOMAIN_CONFLATION`; recurrence.

### PR8-R020 — bounded local loops still allow process-cumulative nontermination

- Cause: no one monotone global work ledger across repeated/nested producer activity.
- Category: `NONTERMINATING_CUMULATIVE_WORK`; recurrence.

### PR8-R021 — producer rejection reduced to success boolean

- Cause: `NotApplicable` / `Rejected` / `Produced` semantics collapsed into a generic success path.
- Category: `PRODUCER_DISPOSITION_CONFLATION`; first event.

### PR8-R022 — row-order test compares raw IDs

- Cause: metamorphic test itself used representation-dependent DCEL IDs as oracle.
- Category: `TEST_AUTHORITY_COVERAGE_GAP`; recurrence.

### PR8-R023 — tolerance-expanded construction leaks into exact simplex output

- Cause: numerical tolerance decision became published exact source-simplex identity.
- Category: `EXACT_SIMPLEX_CANONICALIZATION_LOSS`.

### PR8-R024 — impossible subdivision witness treated as oracle

- Cause: test fixture could not enter the semantic state its assertion purported to prove.
- Category: `TEST_AUTHORITY_COVERAGE_GAP`; recurrence.

### PR8-R025 — authoritative rejection permits generic substitution

- Cause: producer disposition collapsed before fallback/substitution policy.
- Category: `PRODUCER_DISPOSITION_CONFLATION`; recurrence.

### PR8-R026 — canonical order depends on hash/traversal

- Cause: hash or representation ordering entered semantic equality/order.
- Category: `REPRESENTATION_DEPENDENT_IDENTITY`; recurrence.

### PR8-R027 — torus authority depends on intermediate retention timing

- Cause: test read lifecycle/retention state as semantic product proof.
- Category: `TEST_AUTHORITY_COVERAGE_GAP`; recurrence.

### PR8-R028 — G4 boundary/interior transition domains conflated

- Cause: genuine source boundary topology was incorrectly forced through an interior transition-index authority.
- Category: `AUTHORITY_DOMAIN_CONFLATION`; recurrence.
- G4 mapping: `G4-R001`, resolved.

### PR8-R029 — local path required complete global isolation authority

- Cause: global relation/seam authority universally quantified over each local consumer path.
- Category: `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`; first event.
- G4 mapping: `G4-R002`, resolved.

### PR8-R030 — required quotient counterfactuals not executable

- Cause: source tests existed but were absent from default packaged execution authority.
- Category: `TEST_AUTHORITY_COVERAGE_GAP`; recurrence.
- G4 mapping: `G4-R003`, resolved.

### PR8-R031 — source/region transition identity conflated again

- Cause: compact/topology authority crossed another consumer boundary without typed domain conversion.
- Category: `AUTHORITY_DOMAIN_CONFLATION`; recurrence.
- G4 mapping: `G4-R004`, resolved.

### PR8-R032 — retention/policy/stage state conflated in G4 path

- Category: `POLICY_STAGE_STATE_CONFLATION`; recurrence.
- G4 mapping: `G4-R005`, resolved.

### PR8-R033 — test helper repeats authority-domain conflation

- Cause: test authority mirrored the same integer-domain ambiguity as production.
- Category: `AUTHORITY_DOMAIN_CONFLATION`; recurrence.
- G4 mapping: `G4-R006`, test-authority resolved.

### PR8-R034 — local face/path consumes global relation authority

- Cause: global relation completeness was required locally; focused single-relation tests did not represent chained/unused/off-face relation shapes.
- Category: `LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`; recurrence of R029.
- G4 mapping: `G4-R007`, **active**.
- Current durable product evidence remains direct torus 0/3 after 192 quads with 241 `LocalSheetMismatch` issues; historical exact torus remains `InvalidHardRailPairing`.

## Current relationship to M1 migration

M1a–M1d are immutable accepted without adding a stable regression event. M1e Code + Build artifact `9047295489` is compile/package complete and has not executed runtime. Its initial compile API correction and temporary workflow-syntax failures therefore do not change this inventory’s **34 events / 20 recurrences**.

Current pattern status, exact M1e artifact authority, and next immutable gate are maintained in `.agents/Directional/Regression_Root_Cause_Tracker.md` and `Future_Chat_Session_Handoff.md`.
