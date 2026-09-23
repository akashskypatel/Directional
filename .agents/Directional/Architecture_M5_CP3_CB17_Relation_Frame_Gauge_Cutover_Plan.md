# M5-CP3-CB17 Relation-Frame Gauge Cutover Code + Build Plan

**Turn:** `M5-CP3-CB17`
**Boundary:** product + directly coupled focused test-contract correction; runtime-free Code + Build only
**Authority:** `Architecture_M5_Frozen_Definitions.md` §16.3 and `Architecture_M5_CP3_DEFN_R1_Same_Region_Nonzero_Z4_Gauge_Reconciliation_Definition_Record.md`
**Purpose:** implement the already-frozen semantic Forward-anchored relation gauge without reopening A3, fixture, field, selector or relation-identity authority

## 1. Allowed change

Implement exactly the frozen DEFN-R1 mapping:

```text
Q = G_R^-1 o A o G_F

Forward relation endpoint:
  branch = G_F^-1 o sourceBranch
  coord  = rawCutCoord

Reverse relation endpoint:
  branch = Q o (G_R^-1 o sourceBranch)
  coord  = rotate(Q, rawCutCoord)

T.rotation = Q
T.shift    = reverse.to.coord - rotate(Q, forward.from.coord)
```

The second endpoint map, reciprocal branch equations and transported-delta equation are validation only. Semantic reversal is exactly `T.inverse()`. Canonical storage may store `T` or `T.inverse()` but semantic resolution must return `T` from A3 roles.

## 2. Surgical implementation surface

Expected product surface only:

- `include/directional/geometry/SurfaceCellTracing.h`
- `src/geometry/SurfaceCellTracing.cpp`
- directly coupled internal state/hash plumbing only if a renamed relation-rotation field requires it (for example `src/pipeline/RemeshPipeline.cpp`)
- `tests/SurfaceCellTransitionQuotientTests.cpp` only for focused contracts that directly encode the corrected relation-frame semantics

Do not change:

- `benchmarks/fixtures/**`;
- raw torus field generation or row408 hard-edge authority;
- A3 boundary occurrence / generator-route selection;
- `PeriodicRelationId` definition;
- selector430 or any selector manifest bytes;
- unrelated validators, fallback/recovery behavior, M6 occurrence logic or benchmark code.

Prefer renaming any endpoint-state member that currently implies raw generator transport (for example `generatorRotation`) to a semantic relation-rotation name if and only if the existing name would remain materially false after the cutover. Do not create compatibility aliases merely to preserve an internal name.

## 3. Required implementation sequence

1. Resolve exact semantic Forward and Reverse A3 occurrences before relation endpoint construction.
2. Read raw directed A1 `A` only in semantic Forward -> Reverse direction.
3. Read `G_F` / `G_R` from the already-authored accepted cut-domain per-face gauge.
4. Construct `Q = G_R^-1 A G_F` once and make it the relation rotation authority.
5. Author both relation endpoint states using §16.3's Forward/Reverse normalization.
6. Construct translation from the Forward anchor only; validate the second endpoint without solving from it.
7. Publish one semantic action `T`; canonical storage inversion is representation-only.
8. Update directly coupled focused tests so raw source transport and relation rotation are compared through `Q`, not assumed identical in general.

## 4. Compile-time / static falsifiers

CB17 must add or preserve focused coverage proving all of the following at source/test-contract level:

- **Nonzero gauge adjustment:** a synthetic case with `G_F` or `G_R` nonzero proves `Q != A` when the algebra says so; deleting either gauge term must fail.
- **Concrete torus discriminator:** the committed source/A3 witness remains independently expected at relation-gauge `Q=3`; fixture/field bytes are unchanged.
- **Direction:** swapping semantic Forward/Reverse yields exactly `T.inverse()`; there is no best-of-two retry.
- **Translation anchor:** mutating the second endpoint cannot cause a new translation to be fitted; it must reject the correspondence.
- **Storage invariance:** canonical representation reversal preserves `PeriodicRelationId` and resolved semantic `T`.
- **Zero reduction:** `Q=0` keeps existing ordinary relation endpoint values and does not alter ordinary cell placement.
- **Stage ownership:** no A5/M6 state appears in the construction path.

Focused tests may use hand-authored exact states to falsify the algebra. They may not substitute for the later produced row4/5 gate.

## 5. Build boundary

This turn is compile-only. Use the repository's required GitHub Actions compile workflow with GMP/GMPXX linkage for the existing mandatory target set. No project test, benchmark, custom mesh executable, configure-time semantic probe or generated runtime is authorized.

Package exact source receipts and compile evidence according to the existing Code + Build workflow. Candidate remains unpromoted regardless of compile success.

## 6. Stop rules

Stop and return to definition/review if implementation would require any of:

- choosing `A`, `A^-1`, `Q` or `Q^-1` based on which passes;
- changing the semantic A3 Forward/Reverse occurrence roles;
- fitting translation from both partners or repairing endpoint state after mismatch;
- retuning the torus fixture, raw field, hard rails or source witness selection;
- changing selector bytes or weakening accepted validators;
- pulling M6 occurrence/embedding state backward;
- creating a second gauge anchor based on canonical storage order.

A compile failure caused only by the surgical cutover may be corrected within CB17; do not expand scope to runtime diagnosis.

## 7. Success criteria and exact next gate

CB17 is complete only when:

1. the frozen §16.3 algebra is represented directly in product code;
2. directly coupled focused contracts encode relation-gauge `Q`, including one case where `Q != A`;
3. fixture/A3/selector bytes remain unchanged;
4. all required compile/link targets pass with GMP/GMPXX;
5. package/source manifests and runtime-free receipts are complete;
6. no Directional binary was executed.

On compile-green completion, the only authorized successor is **`M5-CP3-TB1-R15-EXEC`**: fresh immutable artifact-only runtime of the corrected focused vector, produced rows1–6, selector430 and the carried R6 direction falsifier, followed by mandatory **`M5-CP3-TB1-R15-REV`**. The exact process count is frozen by that TB plan after CB17's final test inventory; do not guess it in Code + Build.
