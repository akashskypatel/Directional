# RA-172 — Off-selector coverage disposition; TB51 gate frozen (2026-10-30)

Turn `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (DEFN, Review). At the user's direction, Review took the turn over from the implementation agent after about 7 h of runtime-free audits that did not close it. Authority for the disposition of each row is this record and the frozen ledger. The [working inventory](Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Working_Inventory_20261029.md) is retained as the per-row source evidence for the repair slices.

## RA-172.1 Why the DEFN stalled (Review defect)

RA-171.5/.6 gave one DEFN two jobs: causal proof and exact patches for all 85 non-PASS rows (14 groups), and a TB51 that depended on that work. It also allowed only two states, gated or retired. About a third of the groups can be settled only by native probes, which the implementation track cannot run, and most of the rest need a fixture redesign each. The turn had no reachable exit. The agent's audits are sound but unbounded (P01–P14, ~148 commits), and its 916-row manifest could not be executed. Fix: this turn does the *disposition*, which is bounded. *Repair* happens later, one slice per group. Rows that are not repaired yet get a third state, DEFERRED.

## RA-172.2 Evidence re-verified

- **TB50C-R2 result `12941320247`:**
  - ZIP `a18758bd…`; 822/822 internal checksums.
  - Ledger and manifest join 408/408 on row, identity, test and binary.
  - Boundary 323 PASS / 83 RED / 2 ABNORMAL / 0 INVALID, postflight true; source `7cf0857b…`, package `12918290481`.
- **Inventory spot-checks (source reads), all confirmed:**
  - P01: the four `FAIL()` calls are unconditional (`tests/FieldAlignedCurveNetworkTests.cpp:10494/10500/10506/16392`).
  - P03: `TriMesh::compute_edge_quantities` appends to `boundaryLoops` (`TriMesh.h:241`) and nothing clears it, so a second `set_mesh` duplicates the loops and corrupts `numGenerators` (`:356`).
  - P04a: seven 1×3-face fixtures fail the DCEL pure-boundary check (`DCEL.h:1546–1567` via `TriMesh.h:159`).
  - P08: 13 tests call `build_surface_cell_complex` without `sourceAuthority`, giving `SourceTransitionUnavailable` (`SurfaceArrangement.cpp:1721`).
  - P12c: row 314 asserts `validationSeconds < remeshSeconds * 0.05` on wall-clock time.

## RA-172.3 Disposition contract (amends RA-171.5)

Every test in the four gate binaries has exactly one state:

- **GATED:** a row in the TB51 manifest; it must PASS.
- **DEFERRED:** a row in the frozen deferred ledger with a group and a class. It is excluded from the gate and re-enters only through its group's repair slice, which moves the row from the ledger to the gate manifest.
- **RETIRED:** deleted from the binary by a CB, for the reason given in RA-172.4.

**Accounting:** TB51 = 508 + 323 = **831**. Gate ∪ ledger = 916, the full test list of the four binaries at CB52 (RA-170 enumeration), with no overlap.

**Classes:**

| Class | Meaning | Rule for its repair |
|---|---|---|
| FIXTURE | Test input or oracle proven wrong; production not implicated | Test-only. Never weaken an assertion or inject authority. Rows marked *confirm* first need a probe of the typed first rejection. |
| PRODUCT | Production defect proven from source | CB whose new or repaired test fails at HEAD. |
| OPEN | First cause not established | A Review probe DEFN must come before any patch. |
| RETIRE | The test cannot verify anything | Deleted by a CB. |

O11 (off-gate TQ failures) and O13 (row 265) are inside P11a/P11b, so both close as separate carried items.

## RA-172.4 Group disposition (census rows)

| Group | Rows | Class | Evidence | Repair slice |
|---|---|---|---|---|
| P01 | 182 191 196 197 | RETIRE | unconditional `FAIL()` observation probes | Retire CB. Stage reports stay in the inventory; P09b owns the sphere stage. |
| P12c | 314 | RETIRE | wall-clock ratio, which depends on the machine; performance budgets belong to M8-CP3 | Same retire CB. |
| P04a | 22 28 33 34 38 39 43 | FIXTURE | single-triangle source mesh rejected as pure boundary | Valid two-face disks that keep the face-0 geometry. |
| P04b | 354 | FIXTURE | same rejection, in the one-incidence control | Separate witnesses for 1, 2 and 3 incidences. |
| P05 | 8 16 48 | FIXTURE (confirm) | input arcs stamped `TopologyRegionId(3)`; the true region is 0 | Correct the region; print the typed result. |
| P06 | 15 17 35 | FIXTURE (confirm) | same substitution; typed rejection not printed | Same slice as P05. |
| P07a | 54 57 61 | FIXTURE | wrong `invalid` tuple (54); invalid ownership registry (57); unchecked variant access (61) | One slice. |
| P08 | 95 96 97 100 101 103 106 107 109 112 114 118 119 | FIXTURE | no `sourceAuthority`, so the producer returns an invalid complex before simplification | Face-bound `SourceTopologyRegions`; re-derive assertions once preflight passes. |
| P10 | 235 236 237 241 243 | FIXTURE (confirm) | cone matching {2,2,0} contradicts the +π/2 lift; row 243 has an inadmissible arrival seed | Probe the first A3 guard, then fix the fixtures. |
| P11a | 223 225 265 324 331 | FIXTURE | stale or over-broad oracles: error label (324), endpoint class (225), cross-representation equality (265), isolation evidence (331), cover-invalid negative (223) | One slice. |
| P12a | 276 279 296 317 | FIXTURE | stale negative and chart-numbering oracles | One slice. |
| P14a | 373 401 406 407 408 | FIXTURE | no boundary authority (373, 401); multi-rail chart fixture order (406–408) | One slice. |
| P03 | 157 163 313 | PRODUCT (confirm) | `boundaryLoops` never cleared on a repeated `set_mesh` | Reset the cache in `compute_edge_quantities`; reuse test; probe ties each row to it. |
| P09a | 175 | PRODUCT | singularity dropped by the diagnostic projection | One CB. |
| P14b | 375 385 390 | PRODUCT | `SourceProjectionCache::project` omits component/sheet labels (375, 385); size gradient omits the projection Jacobian (390) | Two CBs. |
| P02a | 24 37 45 46 | OPEN | A3 atlas: 2 of the 3 required outgoing incidences | Probe DEFN. |
| P02b | 303 | OPEN | forward A3 build throws; typed cause unknown | Probe DEFN. |
| P07b | 52 58 60 64 65 66 68 69 | OPEN | registry mismatch (58, 66); the other assertions are never reached | Probe DEFN (typed first rejection). |
| P09b | 192 344 350 | OPEN | carrier-less incidence on `sphere_prescribed` (192, 344); AK4 ordinary proposal excluded (350) | Probe DEFN; AK4 owns 350. |
| P11b | 261 | OPEN | A2b terminal provenance missing | Probe DEFN. |
| P12b | 277 283 286 | OPEN | producer candidates | Probe DEFN. |
| P13 | 360 362 365 | OPEN | Bunny A3 cut Euler identity is −3 where −5 is expected; Cylinder and Vase hit the 600 s timeout | Probe DEFN. |
| P14c | 399 | OPEN | metric fallback contract | Probe DEFN. |

Totals: FIXTURE 49, PRODUCT 7, OPEN 24, RETIRE 5, together 85.

## RA-172.5 Obligations for `M6-CP3-PLAN-RP01-CLOSURE`

- **RP-01 blockers.** A deferred group blocks RP-01 if and only if its first failure lies in A1–A3 source or transport authority on a pipeline-produced fixture. By that rule P13 and P12b block by default. The PLAN rules on P02a, P02b, P03, P09b and P11b. FIXTURE, RETIRE, P09a and P14 are scheduled repair slices, not blockers.
- **O14 (new): gate completeness.** The 408 tests drifted off-gate because the manifests list tests and nothing checks the binaries for tests that are not listed. Owner: the PLAN. Candidate fix: a harness preflight that fails when `--gtest_list_tests` ⊄ manifest ∪ deferred ledger.
- **Slice order.** The retire CB goes first. FIXTURE/PRODUCT slices follow the pattern exact patch (R) → CB (I) → TB on the gate plus the group's rows (I) → REV (R). OPEN groups start with a probe DEFN (R).

## RA-172.6 Frozen artifacts

- **[TB51 manifest](Architecture_M6_CP3_TB51_Full_Gate_Case_Manifest.tsv):** SHA-256 `d6961b598a450dd17b818f316249ecacd0fdc73a91d8a1e4e7dca2fa537eb7b4`, 831 rows.
  - Rows 1–508 are byte-identical to TB50 `eef8855e…`.
  - Rows 509–831 are the 323 census PASS rows in census order, as `GUARD`/`PASS`/`-` with identity `offgate:<census row>`, built from the immutable ledger.
  - Harness `600c6455…`: `bash -n` OK, self-test 21, `--self-check … 831` PASS (830 rejected as a control).
- **Timing:** the promoted rows take 30 min serially. The longest is row 361 at 391 s, under the 600 s case timeout. TB50-R2 took 47 min for 508 rows, so TB51 should take about 80 min, far below the 6 h job cap.
- **[Deferred ledger](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger.tsv):** SHA-256 `6f7eb9137afda0fc8066883d73058d6e843158751e7356e1dd468bc891be6df5`, 85 rows (census row, identity, test, binary, verdict, exit, group, class, first failure).
- **Folded documents:** the continuation WIP log and the non-executable 916-row proposal (see the `M6_Consolidated_Record.md` folded index).

## RA-172.7 Turn sequence and outcome tables

| # | Turn | Type / track | Gate |
|---|---|---|---|
| 1 | `M6-CP3-TB51-RP01-FULL-GATE-EXEC` | TB-EXEC / I | CB52 package, harness `600c6455…`, manifest `d6961b59…`, 831 cases |
| 2 | `M6-CP3-TB51-RP01-FULL-GATE-REV` | TB-REV / R | Verify the ledger; 831/0 becomes the reviewed candidate gate; gate ∪ ledger = 916 |
| 3 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN / R | RA-172.5 rulings; O6 scope; owners for O7–O10, O12 and O14; slice order |
| 4+ | Repair slices per RA-172.5 | per slice | Each moves its rows from the ledger to the gate |

**TB51-EXEC.** Dispatch with the RA-170 package environment (`12918290481`, ZIP `89449f4f…`, root `6ae4eb5b…`, source archive `c02a0be4…`, source `7cf0857b…`) and these values:
- `harness_sha256=600c6455…`
- `CASE_MANIFEST=.agents/Directional/Architecture_M6_CP3_TB51_Full_Gate_Case_Manifest.tsv`
- `CASE_MANIFEST_SHA256=d6961b59…`
- `EXPECTED_CASE_COUNT=831`

Report the counts, plus the `first_failure` of any non-PASS row. Make no classification.

| Result | Successor |
|---|---|
| Postflight true and 831 ledger rows, whatever the exit code | TB51-REV. On this unchanged package, any non-PASS is evidence of nondeterminism for the REV; do not re-run. |
| Preflight or manifest error | `M6-CP3-PLAN-RP01-GATE-STOP` (PLAN, R) |
| Dispatcher or runner failure before the harness starts, or cancellation | `M6-CP3-CB53-RP01-GATE-ORCH` (CB, I), then one TB51-EXEC retry |
