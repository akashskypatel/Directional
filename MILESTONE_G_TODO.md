# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → **G3 cylinder / periodic holonomy [active; chart endpoint canonicalization blocker]** → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Latest G3 artifact-only result

Exact tested authority:

- artifact `9008118764`, `g3-periodic-ring-correspondence-code-build`;
- source/test commit `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- artifact SHA-256 `11e9e50e59aaf71149594f791c5f4c6465ab452111427760cb2f0c9065fea562`;
- recursive checksums **44/44**;
- build run/job `31214404170 / 92984429773`;
- build log artifact `9008117677`, SHA-256 `a4cd22bb4662edc290ad558d76e09af4b34a440f5803a5474af5dc68421a1a77`;
- artifact-only execution; no rebuild or source/test/validator/build changes.

Focused/retained producer contracts: **9/15**. All seven retained G1/G2 contracts and the new typed ambiguous-correspondence contract pass. Six nominal G3 periodic contracts now reject with `InvalidPeriodicChart` before their intended assertion.

## Direct gate result

- plane: `Produced`, 352 traces, 64 strict-valid quads, hash `730caeae49ec872c`, deterministic 3/3;
- seam: `Produced`, 256 traces, 64 strict-valid quads, hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close sheets: `Produced`, 1,104 traces, 200 strict-valid quads, 242 output vertices, two isolated components, hash `89b052762f52a5af`, deterministic 3/3;
- cylinder: **`Rejected/InvalidPeriodicChart`**, failure stage `tracing/phase-front`, cell 29, zero traces/arrangement/completed quads/output, no terminal holonomy, no fallback/recovery, deterministic 3/3;
- bunny: later-gate `NotApplicable`, 80,862 traces, bounded completion in 41.61 s;
- vase: later-gate 45 s bounded timeout; failure only.

G3 therefore remains active and this result is **regression/no-progress**, not material runtime progress. The prior artifact `9004509871` had reached periodic `Produced` and completed output validation; restoring the old diagonal correspondence is not permitted because it was the proven `37.9670987281°` field-alignment defect.

## Exact next defect

Independent immutable-source reconstruction reproduces the cylinder's first rejection at **cell 29**.

`periodic_chart_segment()` uses approximately `1e-10` tolerance to decide triangle coverage, but its emitted barycentric interval endpoints retain tolerance-expanded values. Two boundary sides that mathematically meet at the same source vertex therefore contain microscopic tails on the same source face. The unchanged strict shared-endpoint/self-intersection predicate sees those tails as overlap beyond the exact shared endpoint and rejects the cell as `InvalidPeriodicChart`.

Required principle: **coverage tolerance may choose ownership, but emitted geometry must be canonical source geometry**.

## Required next turn

Execute `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Code_Build_Plan.md` as Code + Build only.

Required bounded change:

1. preserve reciprocal field-authoritative adjacent-ring correspondence and typed `InvalidPeriodicRingCorrespondence` / `AmbiguousPeriodicRingCorrespondence` behavior;
2. canonicalize `periodic_chart_segment()` endpoint barycentrics near exact simplex boundaries;
3. renormalize valid barycentrics and reject materially invalid values;
4. preserve exact shared breakpoint identity across consecutive intervals;
5. drop zero-length/tolerance-only emitted segments;
6. leave strict self-intersection/closed-boundary validators unchanged;
7. add compile-valid endpoint/shared-breakpoint/real-overlap regressions without weakening the six currently failing G3 contracts;
8. compile/package the seven approved targets with `PRE_TEST`, execute no generated project binary;
9. retain G0-G2 and no fallback/recovery.

This is the first runtime-no-progress Code + Build result since the prior material-progress turn. The mandatory two-consecutive-Code+Build review rule is not yet triggered. If the next Code + Build also fails its following artifact-only acceptance without material progress, the following turn must be a design review or bounded producer replacement proof.

## Suite evidence

- bounded producer: **91/99**;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- bounded aggregate: **313/331**.

Direct gate status outranks aggregate totals. Review policy remains `never`. Every completed turn ends with a new top-level PR #8 comment after all other repository writes.
