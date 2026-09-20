# M5-CP2-CB1 Typed Relation Failure Matrix Code + Build Plan

**Turn:** `M5-CP2-CB1`
**Turn type:** Code + Build / compile-package only
**Entering accepted authority:** package `10600353027` / source `8a86710dd33d7b6cb9a077aef738577e4075b5f7` / selector430 **430/430**
**Normative authority:** `Architecture_M5_Frozen_Definitions.md` §6 and §9 `M5-CP2`
**Runtime:** forbidden; `runtimeExecution=false` required
**Selector publication:** forbidden; selector430 bytes remain frozen

## 1. Goal

Complete the frozen five-class periodic-relation failure matrix at the checked phase-front relation boundary, with independent negative-oracle tests, without weakening CP1 identity/certificate semantics or importing CP3 production evidence.

The five required classes are exactly:

1. **missing** → `SurfacePhaseFrontProductErrorCode::MissingPeriodicRelationOwner`;
2. **duplicate** → `SurfacePhaseFrontProductErrorCode::DuplicatePeriodicRelationId`;
3. **conflicting** → add `SurfacePhaseFrontProductErrorCode::ConflictingPeriodicRelation`;
4. **nonreciprocal** → add `SurfacePhaseFrontProductErrorCode::NonReciprocalPeriodicRelation`;
5. **representation-renumbered** → add `SurfacePhaseFrontProductErrorCode::RepresentationRenumberedPeriodicRelation`.

Existing numeric enum values must not be silently repurposed. New codes are appended unless a separately proved ABI/source constraint requires another compatible placement.

## 2. Current-source gap that authorizes the turn

At CP1 accepted source the phase-front error enum has `DuplicatePeriodicRelationId`, `MissingPeriodicRelationOwner`, and broad `InvalidPeriodicRelationOwner`, but not the three frozen CP2 classes. `SurfacePhaseFrontProduct::make(...)` currently maps a repeated canonical relation ID to duplicate without distinguishing equal payload from conflicting value, and an edge that references no table owner to broad invalid-owner rather than the frozen missing-owner condition. CP2 must make those frozen distinctions explicit.

This is a typed-failure mechanism turn. It does **not** authorize produced periodic relations, torus CP3 work, nonzero-Z4 production evidence, occurrence-complex work, selector publication, or milestone closure.

## 3. Authorized semantic edits

Primary authorized surfaces:

- `include/directional/geometry/SurfaceCellTracing.h` — append the missing typed error codes and only the minimal checked-boundary API required by the frozen matrix;
- `src/geometry/SurfaceCellTracing.cpp` — classify the five relation failures at `SurfacePhaseFrontProduct::make(...)` or one narrowly factored helper owned by that checked boundary;
- `tests/SurfaceCellTransitionQuotientTests.cpp` — independent negative-oracle coverage for every class and representation/container permutation where relevant.

Touch another product/test file only if compilation proves the checked boundary is declared/owned there; record why before editing. No fixture, selector, benchmark, CMake, workflow, M4 closure, or CP1 accepted-test semantic change is authorized.

## 4. Required failure semantics and negative oracles

### 4.1 Missing

A `PeriodicCut` edge with no owner, or one whose referenced ID is absent from the relation table, rejects as `MissingPeriodicRelationOwner` at that edge locus. The test starts from a valid direct relation/product, removes exactly the owner/reference condition, and proves no fallback owner is substituted.

### 4.2 Duplicate

Publishing the same canonical `PeriodicRelationId` with an identical immutable value payload more than once rejects as `DuplicatePeriodicRelationId`. Reversing container order must not change the code or locus.

### 4.3 Conflicting

One canonical relation identity published with a different action/transport/value rejects as `ConflictingPeriodicRelation`, not duplicate and not a second identity. The negative witness independently derives the expected carrier identity from source/path content, leaves carrier identity unchanged, mutates only value, and requires the conflict code.

### 4.4 Nonreciprocal

A paired periodic/front representation whose reverse side does not bind the exact reversed carrier/endpoints and exact inverse transport rejects as `NonReciprocalPeriodicRelation`. The oracle first constructs/derives the correct reverse independently, then tampers exactly one reverse-side fact. If current product state lacks a semantic reciprocal pair boundary, add only the minimal checked representation required by the frozen contract; do not infer reciprocity from vector adjacency.

### 4.5 Representation-renumbered

A declared/reference ID that differs from the canonical ID independently derived for the same semantic carrier locus rejects as `RepresentationRenumberedPeriodicRelation`. The witness must preserve carrier/value content and perturb only the declared/reference mapping. **Do not reintroduce index-backed `PeriodicRelationId`, ordinal offsets, or test-only unchecked constructors to make this case expressible.** If the current API cannot express a declared/reference mismatch through a checked boundary, STOP and return to Review/DEFN with that representation gap rather than inventing ordinal semantics.

For all five classes, the independent oracle derives semantic carrier identity from route/source content and may not call the production identity factory merely to obtain the expected answer. It may reuse primitive typed source IDs and compare against production output after its independent answer is fixed.

## 5. Required preservation controls

The Code + Build diff must preserve:

- `PeriodicRelationId` carrier-content identity and its exclusion of action/transport/storage order;
- CP1 aggregation behavior with no `periodicRelationOffset` or ordinal renaming;
- exact selected relation-path certificate publication/validation;
- same-region distinct relation coexistence;
- unused-valid-relation invariance;
- accepted selector430 bytes and first427 prefix bytes;
- the four M5 production debts and their §8.2 discriminators.

No failure may be repaired by sorting, reassignment, first-wins/last-wins, relation dropping, alternate-path search, or front-edge substitution.

## 6. Static acceptance and compile/package gate

Before compile, statically prove:

- all five enum names/conditions exist exactly once at the intended boundary;
- each negative test has a one-fact tamper and an independent expected-identity derivation;
- duplicate versus conflicting are distinguished by value equality under one canonical ID;
- representation/container order cannot choose the failure class;
- no production `PeriodicRelationId::from_index`, `periodicRelationOffset`, new ordinal relation alias, semantic BFS/DFS certificate substitute, or selector edit appears.

Then perform the mandatory GitHub Actions GMP compile/package through `.github/workflows/agent-compile-reusable.yml` only. Compile the standard Directional package targets and require explicit GMPXX+GMP link evidence, clean source-status receipts, recursive package manifest, exact source archive, and `runtimeExecution=false`.

No generated Directional binary may execute: no tests, benchmarks, discovery/list/help/version, CLI/GUI, `ctest`, fuzzers or custom runtime input.

## 7. Falsifiers and stop rules

Stop the turn and report rather than broadening scope if any of these occurs:

- a frozen failure class cannot be represented without reintroducing ordinal relation identity or an unchecked test-only backdoor;
- a test's expected identity depends on calling the same production identity factory being tested;
- distinguishing nonreciprocal or representation-renumbered would require CP3 produced-torus work or M6 occurrence authority;
- the implementation needs relation sorting/reassignment/drop/substitution to obtain the expected typed result;
- an accepted CP1 focused/selector semantic contract would need weakening;
- selector430, fixtures, benchmarks, or unrelated CMake semantics would need modification;
- mandatory GMP compile/package fails for a semantic source error after the bounded allowed fixes are exhausted.

A compile failure may be corrected inside this Code + Build turn only when the fix remains inside the frozen CP2 scope and no Directional runtime executes.

## 8. Successor if compile/package is green

Freeze exactly one artifact-only Test + Benchmark successor: `M5-CP2-TB1-EXEC`. It must execute a focused five-class positive/negative matrix plus selector430 in fresh exact-filter processes with exact-one/zero-skip discipline and immutable postflight. Benchmark execution remains zero unless a later Review explicitly authors a benchmark need. Semantic acceptance remains Review-owned after that execution.
