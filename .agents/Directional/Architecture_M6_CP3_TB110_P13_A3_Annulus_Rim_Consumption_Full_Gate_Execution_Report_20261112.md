# TB110 — annulus rim consumption full-gate execution (2026-11-12 UTC)

## Situation

**COMPLETE / scoped MATCH.** The immutable CB129 package passed all 944 required cases (1,025 memberships). The three-case production census returned Cylinder PASS, with BunnyRandom and Vase at their previously registered non-gating RED outcomes. This is an unwired consumer test, **not** an O36 production-switch acceptance or CP3/selector497 promotion.

## Background

- Canonical turn: `M6-CP3-TB110-P13-A3-ANNULUS-RIM-CONSUMPTION-FULL-GATE-EXEC` (64D.7), artifact-only Test + Benchmark, following CB129 compile-only completion.
- Frozen source `4bef62be917318caad514768a316029e55c6c230`; immutable artifact `13922992326`, [CB129 compile run 43173104948](https://github.com/akashskypatel/Directional/actions/runs/43173104948). Source package ZIP SHA-256 `0f26e0e193c9ab414663ee686ea09ce0b68683dc95d5127f65bbcfa903b2db57`; 28/28 package checksums; eight GMP/GMPXX targets; `runtimeExecution=false` for compilation.
- Gate manifest SHA-256 `46e5c8a8ffb1a8d6337d782bef44fa852d3b17870e2f06ab037d55a8ea201f61` (944 cases, 1,025 memberships); frozen deferred ledger 81.
- [Gate run 43178827546](https://github.com/akashskypatel/Directional/actions/runs/43178827546), artifact `13926276289`, ZIP SHA-256 `b6df910d5659e7ff38d19a1cbeb3912f81ba460aca56cefc3b69b6b8809d63e7`, internal 1,896/1,896 checksums valid.
- [Census run 43178858839](https://github.com/akashskypatel/Directional/actions/runs/43178858839), artifact `13926577173`, ZIP SHA-256 `948cf3bdffdd594d420189667cdceedf3bdef83ee87d775a8b0e19e47b1af73d`, internal 9/9 checksums valid.
- Comparison reference: immutable TB111 full-gate artifact `13919949883` and census artifact `13920309303`. Reference ZIP checksums verified as 1,896/1,896 and 9/9 before comparison. Acceptance is RA-228 §7 as amended by RA-229 §5.

## Assessment

| Requirement | Observed evidence |
|---|---|
| Full gate | 944 planned, 944 executed, **944 PASS**, 0 RED, missing, skipped, abnormal, duplicate, or control failures; membership 1,025 |
| Census | Cylinder PASS, BunnyRandom P13-e RED, Vase completion RED; identical verdicts and substantive ledgers to TB111 |
| Packaging and process | Source/artifact binding exact; postflight true, exit 0; `compile=false`, `relink=false`, `configure=false`, `benchmark=false` on both runs |
| Gate substantive records | All 944 rows unchanged from TB111 except run-specific log hashes |
| Gate receipt changes | Exactly rows **729, 864, 935** change; every other receipt line byte-identical to TB111, including 12 `annulus-rim` and four `rim-branch` lines |
| Cylinder tracing | Only the `tracing` digest differs; its `/1728` count and every other platform digest field remain unchanged |
| Cylinder A3 coverage | `covered: 0→32`; `unrecorded: 81→49`; scheduled 81, partial 0 and foreign 0 unchanged |
| Cylinder rim record | 30 sides in identical order; 28 sides end `1:2/2/2/2`, 2 sides end `2:4/4/4/4`; total output/recorded 64 |

Verbatim row-729 receipt:

```text
annulus-read case=CommittedCylinder rimEdges=32 readable=32 equalOutput=32 outputRimEdges=64 recorded=64
```

Verbatim unchanged row-729 pair receipt:

```text
annulus-pair case=CommittedCylinder strips=16 paired=16 rimSources=16/16 planRims=32/32
```

The prior TB111 row-729 reader reported `equalOutput=24 outputRimEdges=56 recorded=0`. The CB129 consumer now records 64 output rim edges and 32 readable equal-output rim edges. The gate row 864 repeats the same Cylinder platform/coverage observations as the production census; both are explicitly permitted by RA-228 §7. The initial independent comparison script flagged row 864 because it handled that exception only in the census. After adding an exact field-by-field comparison for row 864, the independent verifier reported **MATCH / 0 issues**, without relaxing any result assertion or accepting any other receipt change.

**Regression disposition:** The two census RED verdicts were already registered before TB110. There is no accepted-green loss, no new failure locus, and no evidence for a new stable regression or candidate. Preserve CP2 **491/491** accepted, stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. O36 remains unwired; CP3 and selector497 are not promoted.

## Recommendation

Close TB110 **COMPLETE / scoped MATCH**. RA-228 §7 authorizes the O36 switch **definition as a separate Review turn**, not the production switch itself. The present handoff/plan does not assign a unique canonical ID to that Review: publish `Successor: UNKNOWN` until the authorized ID is defined; do not invent one or start that work in TB110. No source, fixture, selector, test, harness, A3 plan, or build changes were made in TB110. Do not use this gate to claim BunnyRandom/Vase direct production success.
