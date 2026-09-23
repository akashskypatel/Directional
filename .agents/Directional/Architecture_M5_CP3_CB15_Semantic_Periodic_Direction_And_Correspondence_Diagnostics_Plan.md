# M5-CP3-CB15 Semantic Periodic Direction + Correspondence Diagnostics Plan

**Turn:** `M5-CP3-CB15`
**Boundary:** Code + Build only / runtime-free / product correction plus diagnostic authority
**Input:** R12 Review cause proof on CB14 source `b8dc3e906dd03525861a1985ea574bad1ad5c69a`
**Compile successor on green:** `M5-CP3-TB1-R13-EXEC`

## Outcome — COMPLETE / COMPILE GREEN / R13 REQUIRED

CB15 completed the bounded product correction and diagnostic-authority work at exact semantic source `4dfe392d28d60b448e2f32253f7d170221ac57ec` (product commit `864d04f015db86a03f9ee54d8154308b1bdaf715`). The implementation preserves canonical `PeriodicRelationId`/storage and adds deterministic `resolve_periodic_relation_semantic_action(...)`: exact A3 Forward/Reverse roles and route identity select exactly one semantic representative, using the stored action when stored `cutRoute` is the Forward carrier and its exact inverse when the reversed stored carrier is Forward. No best-of-two validation search is present. Checked-product validation and authoritative materialization both consume that one semantic action.

The CB14 `periodic_action_for_pair(...)` Boolean collapse is replaced by a fixed-order typed result that reports endpoint-state availability, occurrence orientation, generator rotation, source-chart relation, boundary-occurrence relation, reciprocal scale, first/second branch correspondence, transported delta, and first/second endpoint mapping separately. Acceptance predicates and their order are preserved; `make_periodic_relation_endpoint_state(...)` and the CB14 nonzero gauge formula are unchanged. The new focused identity `M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse` compiles and exercises the inverse storage representative, stable relation ID/canonical bytes, deterministic semantic conversion, both endpoint maps, swapped semantic-role rejection, and transform-only typed rejection. It has **not run** in CB15.

Compile/package run/job `35811645725 / 107024364608` is GREEN through the mandatory reusable GMP/GMPXX workflow. Result/log artifacts `10730261023 / 10730111645` have provider ZIP SHA-256 `d124bf4456c11cc7d7eb2022a94391d9a8c6f1ebd368ad04403f1dc46d3f521d / 081ef836af579e8e428cfd12cb0b1aa83afcad77ec4e3ae134284cd8feeeff5b`. The result root manifest verifies **28/28** with SHA-256 `29e900f4a8e0d6ba814f9ed4efe3d9a3b2f0f499690c3562b51a28873efa2e6b`; packaged source archive SHA-256 is `9bb73290f341101f5b7009df52ff085ec256ac9702a6da5765aa330a5118a81d`. All eight required targets compile/link, all source-status receipts are empty, GMP/GMPXX link evidence is present, and `runtimeExecution=false`. No generated Directional binary, test, benchmark, discovery/list/help/version command, CLI, fuzzer, or custom input ran. Selector430 remains 430 rows at `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` and first427 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

CB15 earns compile evidence only: accepted runtime remains `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`, stable accounting remains **50 / 14 / 36**, produced-witness debt remains **3**, candidate promotion/debt discharge/selector publication remain prohibited. Exact successor is fresh artifact-only `M5-CP3-TB1-R13-EXEC`, followed by mandatory Review.

## Goal

Recover the ordinary-torus/ordinal408 regression caused by consuming storage-canonical relation orientation as semantic A3 direction, while adding enough typed observability to localize CB14's still-unresolved nonzero-Z4 correspondence failure. Do not guess or change the nonzero relation-endpoint gauge formula in this turn.

## Goal A — deterministic semantic orientation of canonical storage

Keep `PeriodicRelationId`, canonical relation storage, `canonicalize_periodic_holonomy(...)`, and relation-container ordering unchanged.

At every exact-A3 consumer that needs semantic Forward -> Reverse action (`SurfacePhaseFrontProduct::make(...)` and authoritative materialization), derive **one** semantic representative from exact carrier/A3 identity:

- semantic Forward edge is selected only by `sharedBoundaryInterval.orientation == Forward`;
- semantic Reverse edge is selected only by `... == Reverse`;
- if stored `cutRoute` equals the Forward carrier, semantic action is the stored action;
- if stored `cutRoute.reversed()` equals the Forward carrier, semantic action is the exact inverse of the stored action;
- any other carrier relation is typed rejection.

This is representation conversion, not an inverse retry. The route identity chooses one direction before endpoint validation. Never evaluate both directions and select the one that passes.

Use that one semantic action consistently when re-deriving periodic endpoint states, validating both branch/scale endpoint maps, and publishing selected materializer transport. Do not rewrite stored relation identity/value merely to match edge order.

### Goal-A falsifiers

Compile exactly one new focused identity, `M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse`, that constructs an exact-A3 Forward/Reverse pair whose relation is deliberately storage-canonicalized to the inverse representative and proves:

1. the stored relation remains canonical and its ID unchanged;
2. exact route identity deterministically recovers semantic Forward -> Reverse action;
3. the semantic action validates both endpoint-state maps;
4. swapping/inverting semantic roles without changing A3 orientation is rejected;
5. a transform-only tamper still rejects typed `NonReciprocalPeriodicRelation`.

Do not alter existing R12 identities, fixtures or selector bytes.

## Goal B — typed first-false correspondence diagnostics without semantic change

Refactor the CB14 `periodic_action_for_pair(...)` result into the smallest typed diagnostic result that distinguishes its fixed-order predicates. The diagnostic must identify at least:

1. occurrence orientation;
2. generator-rotation identity;
3. same-edge source-chart relationship;
4. same-edge/cross-edge boundary-occurrence relationship;
5. reciprocal scale;
6. first and second branch correspondence separately;
7. transported relation-gauge delta;
8. first and second exact endpoint mapping separately.

Preserve the current accept/reject Boolean semantics exactly. The first false predicate in the existing order is the diagnostic authority; do not reorder predicates in a way that changes behavior.

Carry that typed subreason through `SurfacePhaseFrontFailure` and pipeline diagnostics so a failing produced row emits it on the ordinary success/failure evidence surface. The next runtime must be able to identify the first false predicate without changing a test merely to print private state. Exact bounded operand receipts may be added only where needed to independently recompute that predicate; do not dump unrelated state.

**Prohibition:** Goal B may not change `make_periodic_relation_endpoint_state(...)`, the CB14 gauge formula, source field, fixture, A3 plan, relation pairing, generator route, action fitting, or validator acceptance semantics.

## Compile/build scope

Allowed semantic source paths are limited to the periodic relation/product and pipeline diagnostic surfaces plus the minimum focused test support needed for Goal A/diagnostic type compilation. No selector file may change.

Compile all existing required SurfaceCells targets through mandatory `.github/workflows/agent-compile-reusable.yml` with GMP/GMPXX. Package exact source and compile evidence with `runtimeExecution=false`. No generated Directional binary may run: no test, gtest discovery, benchmark, CLI/help/version, or other runtime command.

## Pre-build checks

Before mutation:

1. freeze exact CB14 base source and selector430/first427 hashes;
2. prove no field/fixture/A3/selector change is in the diff;
3. prove the semantic-direction conversion is chosen solely from exact route/A3 orientation and contains no best-of-two validation search;
4. prove Goal-B diagnostic changes do not alter the correspondence predicates or their acceptance result.

## Stop rules

Stop instead of broadening scope if:

- semantic direction cannot be determined uniquely from exact route/A3 identity;
- the proposed fix requires changing canonical relation storage/ID;
- any implementation tries action and inverse to see which passes;
- nonzero-Z4 correction would require guessing a gauge change before the first false predicate is observed;
- fixture, field, A3 plan, selector, routing or accepted-test semantics would need retuning;
- GMP/GMPXX compile authority cannot be established.

## R13 gate on compile-green

Fresh artifact-only `M5-CP3-TB1-R13-EXEC` executes the new focused semantic-orientation identity first and then reuses all **446** R12 semantic identities unchanged, for **447 fresh processes total**. Selector430 remains byte-identical. Primary falsifiers:

- `M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse` selects exactly once, skips zero, and PASSes all five Goal-A assertions;
- produced rows1/2/3/6 return PASS;
- protected selector ordinal408 returns PASS; 191/192/247 remain PASS;
- rows4/5 either pass fully or, if still RED, emit one exact typed correspondence subreason from Goal B;
- all 447 processes execute fresh, exact-one/zero-skip, with benchmark 0 and exact immutable postflight; the original 446 identities retain their exact prior ordering within their vector.

Any mechanically complete R13 routes to mandatory Review. CB15 itself grants no runtime recovery, debt, promotion or selector-publication credit.
