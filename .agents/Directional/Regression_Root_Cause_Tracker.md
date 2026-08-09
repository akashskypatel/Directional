# Surface-Cell Regression Root-Cause Tracker

Permanent stable-ID regression, repeated-pattern, architecture, and test-authority index for PR #8. Detailed event evidence remains in `.agents/Directional/PR_8_Regression_Audit_Inventory.md`; dated turn reports retain artifact/runtime detail.

Last updated: **2026-08-09 UTC** after immutable accepted M1b artifact `9042940168`.

## Rules

- Assign a stable regression ID only when previously accepted behavior/test/package/public authority is lost.
- Persistence while a gate remains red is not a recurrence; recurrence requires restoration followed by later loss.
- Compile success never resolves runtime or architecture migration work.
- New migration code remains pending until immutable semantic acceptance.
- Known-red/deferred product cases stay explicit and are never relabeled green/expected-failure to close architecture work.
- Focused/helper passes cannot close representative product intent.
- Before every turn review `RP-01` through `RP-09`; every touched pattern needs an exact invariant and counterexample/representative gate.

## Historical PR-wide authority

- **34 distinct regression events**;
- **14 architectural categories**;
- **20 recurrences**;
- **114 regression-bearing result-document commits**.

T1 artifacts `9040549377 / 9041289209`, accepted M1a artifact `9041930767`, and accepted M1b artifact `9042940168` create no production regression event or recurrence. `PR8-R034 / G4-R007` remains active.

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

**M1a kernel:** immutable accepted, 14/14.

**M1b first production adoption:** **immutable accepted** at `provenance_supports_interval_sheet`.

Accepted invariant:

- legacy source-face validation occurs before named `source_face` conversion;
- source vertices reject negative legacy values before `source_vertex` conversion;
- `source_face_contains_vertex` consumes `(SourceFaceId, SourceVertexId)` and compile-time assertions reject a domain swap;
- typed IDs return to legacy integers only at explicit matrix/vector representation access.

Accepted counterexamples: invalid faces, wrong source-face incidence, component/sheet mismatch, compile-time face/vertex interchange rejection. Evidence: focused **6/6**, full validation **77/77**, M1a **14/14**, T1 **29/29**, required direct products preserved.

**M1c next boundary:** authoritative `CrossFieldEdgeTransition` consumption in `resolve_branch_transition`. Source/target faces and transition source-edge vertices must cross checked adapters before semantic comparison.

### RP-02 — proxy/incomplete test authority

```text
bad: compile/helper/status/count claimed as product proof.
good: named semantic contract + independent oracle + direct representative evidence.
```

`RP-02 / TA-05` remains **test-authority resolved** by T1 artifact `9041289209` and was independently preserved by M1b:

- validation discovery exactly 77 and full **77/77**;
- M1b focused **6/6** individually;
- M1a exact 14 discovery and **14/14**;
- T1 exact 29 discovery and **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder remain green and independent-oracle clean;
- Bunny remains known-red with independent oracle before fatal product-success assertion;
- Vase remains bounded 60-second safety-only evidence.

M1c focused transition tests may not replace this authority. Its following immutable turn must repeat the named preservation gates.

### RP-03 — policy/stage state conflation

Untouched by M1a/M1b and not part of M1c. M2 owns closed producer-outcome migration.

### RP-04 — nonterminating cumulative work

Untouched by M1a/M1b. Vase remains a known 60-second bounded nonreturn; this is safety evidence only. M1c introduces no search/retry/work loop.

### RP-05 — representation-dependent identity

```text
bad: row/hash/traversal/allocation position becomes semantic identity.
good: semantic strong ID/key is authoritative; row/hash is an explicit compatibility representation only.
```

**M1a kernel:** accepted.

**M1b first production adoption:** **immutable accepted**. Source-face/source-vertex rows become semantic IDs before incidence logic; legacy row indexing occurs only after semantic identity has been established.

**M1c next boundary:** authoritative field-transition source-edge identity. `SourceEdgeTopologyKey` must canonicalize typed endpoints before comparison to the existing `uint64_t` lookup key. Endpoint reversal must preserve semantic identity; do not add another hash/key authority.

### RP-06 — state-cardinality growth

Untouched by M1a/M1b/M1c. M2/M4 own shared authority storage.

### RP-07 — cyclic topology linearization

```text
bad: quarter-turn/cyclic relation handled as unrestricted signed integer arithmetic.
good: exact modulo-4 semantic algebra + explicit inverse; legacy integer is compatibility representation only.
```

**M1a kernel:** exact `QuarterTurn`/automorphism/reversal algebra accepted.

**M1c next boundary:** authoritative `CrossFieldEdgeTransition.matching` consumption in `resolve_branch_transition`. Semantic target-branch transport must use `QuarterTurn::from_integer` and `.inverse()` for reverse traversal. The existing signed `BranchTransitionResult.matching` field stays legacy-compatible in this slice. Required counterexamples include `+5 == +1` semantically and forward/reverse composition to identity modulo four.

### RP-08 — producer-disposition conflation

Untouched. M2 owns migration.

### RP-09 — local consumption of global authority

Untouched by M1a/M1b/M1c. `G4-R007` remains active; M4 owns certificate/global-local relation migration.

## M1b immutable pattern record

| Pattern | Result | Evidence |
|---|---|---|
| `RP-01` | **first production seam accepted** | focused 6/6 + compile-time domain boundary + validation 77/77 |
| `RP-02` | **preserved** | exact 14/29 discovery, 14/14 + 29/29, direct oracle evidence |
| `RP-05` | **first representation boundary accepted** | typed incidence contracts + direct preservation |
| `RP-03/04/06/07/08/09` | untouched | bounded source diff + preserved aggregate/direct behavior |

M1b report: `.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

## M1b runtime/orchestration notes

Authoritative immutable artifact: `9042940168`, SHA-256 `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b`.

Long-running Bunny/Vase used an artifact-only GitHub Actions runner under explicit user authorization:

- run `31332383845`;
- Bunny job `93292577409`, evidence `9043307980`, SHA-256 `c2e7776a9b68ffeeecc7471a3718a2c1bc90fae4556c7d7c05084b5ae8d8fb2d`;
- Vase job `93292577420`, evidence `9043307204`, SHA-256 `1726deb422a3eea238ab3895108a423f6fb6e932cabcc6b215916cc969e87105`.

The runner verified immutable package/executable content before execution. `actions/download-artifact` stripped executable mode; restoring `+x` after hash verification changed no content. A previous run that returned `126 Permission denied` before generated-binary execution is non-authoritative orchestration evidence, not a regression. Temporary workflow/trigger files were removed before closeout.

Standing procedure: future Bunny/Vase immutable runs may use the same ephemeral artifact-only pattern to avoid local execution-tool timeout limits; no rebuild/content mutation is permitted and the underlying test result, not workflow success, determines disposition.

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

`G4-R007` authority remains production artifact `9031804178`: direct torus 0/3 with 241 `LocalSheetMismatch` issues after 192 quads, complete lineage, `4/8/4`, `1/0/0`. M1 migration work does not repair or reinterpret this event.

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
| `AR-02` | M1a strong-ID/route kernel accepted; **M1b first production consumer accepted; M1c field-transition consumer next** |
| `AR-03` | M1a domain-key core accepted; M1b source identity adopted; M1c source-edge key adoption next |
| `AR-04` | `FieldChartId` exists; production chart/snapshot migration remains after bounded M1 consumers |
| `AR-05` | M1a identity/orientation core accepted; M1b first representation boundary accepted; M1c source-edge representation boundary next |
| `AR-06` | M4 relation registry/certificates |
| `AR-07` | M3 global conformity |
| `AR-08` | M2/M3 producer-scoped immutable output |
| `AR-09` | tagged source-support representation exists; exact production rebinding remains M5 |
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
| `TA-05` | **test-authority resolved by T1 and preserved through M1b** |
| `TA-06` | T1 mutation suite 29/29 accepted and preserved |
| `TA-07` | exact package/discovery authority accepted and preserved |
| `TA-08` | T1 metamorphism + M1a typed-route metamorphism accepted; M1c adds field-transition algebra counterexamples |
| `TA-09` | coherent resource/work gate pending |
| `TA-10` | T2 semantic fixture manifest pending |
| `TA-11` | topology/lineage/disposition adequate; quality expansion later |
| `TA-12` | `tests/TESTING_STRATEGY.md` normative only |

## Authoritative next step

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Code_Build_Plan.md`.

M1c is **Code + Build only**. It migrates only authoritative `CrossFieldEdgeTransition` consumption inside `resolve_branch_transition` to checked source IDs, canonical `SourceEdgeTopologyKey`, and typed `QuarterTurn` transport while preserving raw compatibility result/fallback storage and all producer/product policy. Its following immutable turn must prove focused transition semantics plus M1b/M1a/T1/direct preservation before another consumer may migrate.
