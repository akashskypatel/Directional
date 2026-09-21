# M5-CP3-CB10 Chart-Admissible Nonzero-Z4 Witness Correction Plan

**Turn:** `M5-CP3-CB10`
**Boundary:** **Code + Build only / runtime-free / test-authority-only**
**Owner:** `M5-CP3-TB1-R8-REV`
**Exact successor if compile/package green:** `M5-CP3-TB1-R9-EXEC`

## 1. Goal

Repair only the remaining test-witness admissibility defect proven by R8 Review. CB9 successfully authored a genuine nonzero row408 hard-edge source transition, but its global quarter-winding field fails the bounded-disk chart closure before periodic relation publication. CB10 must replace that field with the precommitted chart-admissible seam ramp and add a source/geometry-owned pre-product chart-admissibility falsifier.

The production implementation is **not** authorized to change. The sole semantic path is:

- `tests/SurfaceCellTransitionQuotientTests.cpp`

Do not modify `src/**`, public headers, committed `.obj/.rawfield` fixtures, selector files, CMake target membership, frozen definitions, routing authority, benchmark semantics, or accepted expectations.

## 2. Entering evidence

R8 candidate `10660365136` / source `1023eea6090a1f6c2d47ecaceb1099967c32e6c2` completes all **446/446** immutable processes at **9/9 mechanism + 1/1 focused atlas + 4/6 produced + selector430 430/430**. Produced row6 now passes. Rows4/5 both fail before their relation-specific discriminators with exact `InvalidBoundedDiskChart`.

R8 Review independently reconstructs CB9's field and proves the failure is witness-owned:

- frozen row408 cut graph: 18 hard edges;
- CB9 field `alpha(theta)=theta/4` yields boundary branches `[0,3,0,1,2,3]`;
- minimum hard-edge branch alignment `0.7110184804059094 > 0.7`;
- turn sum `+4`;
- developed closure residual norm `4.666904755831214` versus tolerance about `3.3310125454580146e-9`.

The failure precedes `select_torus_source_witness(...)`, relation direction comparison, materialization and tamper. Product source is therefore not a correction owner in CB10.

## 3. Goal A — replace the global quarter winding with the frozen seam ramp

Keep the existing committed torus geometry and deterministic geometry-derived tangent frame. Replace only the CB9 angular rotation law with:

```text
delta(theta) = (pi - theta) / 6
```

where `theta = atan2(centroid.y, centroid.x)` normalized to `[0, 2*pi)`.

The face cross must remain:

```text
x = cos(delta) * majorTangent + sin(delta) * minorTangent
y = -sin(delta) * majorTangent + cos(delta) * minorTangent
raw = [x, y, -x, -y]
```

Do not search a family of ramp angles. Do not tune the coefficient or phase after compile/runtime results. This exact ramp is precommitted by Review from source/geometry analysis.

### Static precommitment

Independent Review predicts on the unchanged 18-edge cut graph:

- minimum branch/hard-edge alignment across both incident faces `0.7753279615208046 > 0.7`;
- four boundary runs `[0,1,2,3]`;
- run lengths approximately `[13.35506272729, 3.3, 13.35506272729, 3.3]`;
- turns `[+1,+1,+1,+1]`, sum `+4`;
- closure residual norm `1.9860273225978185e-15`, below the source-scale tolerance used by production.

These values are falsifiers, not expectations to weaken after runtime.

## 4. Goal B — add an independent pre-product chart-admissibility oracle

Before calling the product pipeline for rows4/5, prove the authored source subject has the bounded-disk chart preconditions that CB9 omitted.

The oracle must derive only from committed source geometry, the exact frozen 18 hard edges, and the authored/finalized source field. It may reuse test-local geometry helpers but may not inspect `product.periodicHolonomies()`, product failure codes, produced relation actions, or downstream materialization output to define the expected answer.

At minimum fail closed unless all of these hold:

1. the exact row408 hard-edge set is unchanged and contains 18 unique source edges;
2. each boundary segment admits the required field branch with alignment strictly above production's `0.7` threshold, checked on both incident source faces where the branch can bind;
3. collapsing the cut boundary into branch-constant runs yields exactly the precommitted four-run sequence `[0,1,2,3]` up to only the explicitly canonical global quarter-turn convention used by the oracle;
4. signed quarter-turn sum is `+4` under the canonical boundary orientation;
5. intrinsic orthogonal development closes within the same source-scale tolerance class as the production bounded-disk chart check;
6. normal/source-frame construction remains finite, normalized, deterministic and consistently handed;
7. after normal cross-field finalization, at least one exact row408 hard-edge generator carrier has a nonzero directed Z4 transition before product inspection.

Prefer a compact independent oracle over copying the full product implementation. The test should expose enough diagnostic state to identify which precondition failed without loosening any one of them.

**Stop rule:** if the frozen ramp cannot satisfy these source-owned predicates without changing production, fixtures, hard-edge authority or the frozen threshold/closure semantics, stop CB10 and return to Review. Do not tune the field or weaken the oracle.

## 5. Goal C — preserve the existing source/A3 direction oracle and rows4/5 debts

Do not replace or relax CB9's source/A3 witness selection. Once the chart-admissibility oracle passes, the existing witness must still:

- select the carrier/occurrence pair from exact source/A3 identity before product relation inspection;
- derive directed source faces from accepted boundary occurrences and canonical source-path orientation;
- require the finalized source transition to be nonzero;
- require retained atlas value to agree with the source transition;
- distinguish forward from inverse direction.

### Row4 — `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`

Retain all existing requirements: the corresponding produced relation must preserve the independently derived generator route and directed quarter-turn, carry nonzero rotation and nonzero translation, materialize successfully, be consumed by the selected certificate, and yield `consumedPeriodicHolonomies > 0`.

### Row5 — `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`

Retain the exact same independently selected relation. Change **only** its action value, prove action changed while semantic ID/carriers did not, and require exact typed `NonReciprocalPeriodicRelation`. Failure to reach the tamper is RED.

No test may accept either transition direction as equivalent.

## 6. Goal D — preserve row6 exactly unless a compile-only mechanical adjustment is unavoidable

`M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` is runtime recovery-proved by R8 Review. Its independent absent/unowned/unselected preconditions and invariance assertions are now load-bearing authority. Do not simplify, reframe, weaken or replace them.

If a shared helper signature mechanically changes because the rows4/5 field helper changes, keep row6 on its currently proven source/fixture semantics unless the frozen Review plan explicitly requires otherwise. Any semantic row6 change is out of scope and requires Review.

## 7. Scope guard

Explicitly prohibited:

- product/source implementation edits;
- public API/header edits;
- committed fixture-byte edits;
- selector430 or selector-manifest edits;
- CMake/test-owner changes;
- relation identity/factory/atlas semantics changes;
- frozen-definition changes;
- accepted identity expectation changes;
- runtime execution, test listing/discovery, `ctest`, generated CLI/fuzzer/help/version execution, or benchmarks.

Use the smallest surgical test-local diff that replaces the field and proves its missing precondition.

## 8. Code + Build verification

After the test-only patch is statically complete:

1. run `git diff --check` and normal source/static checks;
2. compile/package all eight standard targets through durable `agent-compile-reusable.yml` with mandatory GMP/GMPXX:
   - `directional_core`
   - `directional_pipeline`
   - `directional_surface_cell_authority_kernel_tests`
   - `directional_surface_cell_producer_tests`
   - `directional_surface_cell_completion_tests`
   - `directional_surface_cell_validation_tests`
   - `directional_compiled_api_tests`
   - `directional_benchmarks`
3. require exact source archive, root manifest, GMP evidence, clean source-status receipts and `runtimeExecution=false`;
4. execute **no** Directional runtime or benchmark.

A compile failure may be corrected in CB10 only when the edit remains within this exact test-only scope. Runtime-derived adjustment is impossible in Code + Build.

## 9. Frozen R9 gate

If CB10 compiles/packages green, `M5-CP3-TB1-R9-EXEC` must consume that exact candidate immutably and execute the same **446** fresh exact-filter processes:

- 9 reviewed mechanism identities;
- 1 focused retained-value atlas control;
- 6 CP3 produced identities;
- selector430: 430 identities.

Benchmark execution remains **0**. Required all-green vector is **9/9 + 1/1 + 6/6 + 430/430** with exact-one selection and zero skips.

Specific R9 falsifiers:

- rows4/5 pass the new pre-product chart-admissibility oracle;
- finalized source authority still proves at least one exact nonzero row408 hard-edge carrier;
- row4 reaches and passes the source/A3-directed relation, nonzero rotation+translation, materialization and selected-certificate consumption requirements;
- row5 reaches the action-only tamper and exact `NonReciprocalPeriodicRelation` rejection;
- inverse direction remains RED;
- row6 remains green with its recovery-proved absence/invariance predicates;
- selector430 remains 430/430;
- immutable package/source/execution-view postflight and all prohibited-operation counters remain exact/zero.

Any semantic RED is preserved and routed to mandatory `M5-CP3-TB1-R9-REV`; EXEC may not repair it. Even an all-green R9 does not promote the candidate, discharge the two remaining M5 debts, close the direction observation, or precommit selector publication until mandatory independent Review re-derives those claims.
