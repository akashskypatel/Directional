# M3 CP4c-3 TB21 — Artifact-Only Test + Benchmark Plan

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB21`
Type: **Test + Benchmark — ARTIFACT-ONLY**
Status: **FROZEN / NEXT AUTHORIZED TURN**

This plan consumes the immutable CB23 package only. It authorizes runtime evidence collection, not source/test/fixture/selector edits, compilation, relinking, package repair or product correction.

## 1. Immutable authority

- semantic source: **`fa5646106ccaa23770b84a935c6d1d6007928640`**;
- compile run/package job: **`33815475590 / 100847694307`**;
- immutable package artifact: **`9916511617`**, digest **`sha256:8378a108811740cff5fd1a0fc9db66f9e3334d7048ea9e7c7d6e8e1cbd852050`**;
- compile log artifact: `9916511915`;
- current gate selector: `Architecture_M3_CP4c3_Required_Green_Selector_391.txt`, **391 identities**, SHA-256 **`f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`**;
- predecessor selector 385: 388 identities, SHA-256 `164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca`, exact prefix of 391;
- accepted selector 365: SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`, exact accepted prefix;
- preceding runtime authority: TB20, `33809177155 / 100826787667`, **380 PASS / 8 RED**, accepted **365/365**.

## 2. Execution boundary

1. Verify package artifact identity, semantic source, executable modes, internal compile/GMP evidence and selector hashes before runtime.
2. Record a recursive byte+mode package census before execution.
3. Execute all **391 selector identities**, exactly one identity per fresh process, with every mutation/repair flag false.
4. Do not configure, compile, relink, regenerate discovery, mutate source/test/fixtures/selectors, repair the package, change modes, or add runtime probes.
5. Record every identity's exact exit result and produce a complete 391-row ledger. Do not stop at the first semantic red; the frozen purpose includes downstream 371/372 and appended 389–391 diagnostics.
6. Record the same recursive package census after execution and require byte+mode identity with preflight.
7. Update `Regression_Root_Cause_Tracker.md` for every observed red/new surface before TB21 closes. A 371/372 result reached only because of the authorized test-only decoupling is **new evidence**, not automatically a regression.

## 3. Six binding BW9 discriminators

### D1 — accepted boundary

Ordinals **1–365 must remain 365/365 PASS**. Any accepted-prefix red is an immediate accepted-authority regression and must be reported separately from the CP4c-3 frontier.

### D2 — ordinal 366 semantic immutability

Ordinal **366 must still terminate at `UncutFaceComponentOrbitSeedNotUnique`** with the TB20 branch facts intact: component `0`, `seedState=Multiple`, seed count `3`, seed orbits `[0,1,3]`. Movement to another production frontier falsifies BW8 and requires independent review before any correction.

### D3 — cellularity is decided by the embedded graph's own arithmetic

For the mechanical failure publish and retain:

- embedded graph `V`, `E`, `F`;
- embedded-graph connected-component count;
- source `χ(S)`;
- `V − E + F − χ(S)` residual;
- census-complete authority bit.

The values must come from the production failure locus introduced by CB23, not from the historical fragment-owner trace-arc subset. Compare them to the available `SurfaceCutGraph` certificate fields. The result must be sufficient to adjudicate whether the mechanical embedding is cellular without inference from the seed error name.

### D4 — failing-component boundary attribution

For ordinal 366 retain the failing component's bounded per-orbit boundary attribution: orbit id, contributing boundary-edge count, total orbit-row count and truncation status. Do **not** demand more raw boundary rows than the existing retention limit.

### D5 — 371/372 own assertions

Ordinals **371 and 372 must reach and execute their existing assertions** through the CB23 atlas-scoped fixture accessor. Record each real result exactly. Their assertions, selector membership and ordinals are frozen; no runtime workaround or product mutation is authorized. A red at the assertion is new contract evidence, not by itself an accepted-prefix regression.

### D6 — carried surfaces and appended diagnostics

- co-reacher **367** and carried surfaces **368, 369, 370, 374** retain their independently owned behavior unless immutable evidence proves otherwise;
- appended identities **389–391** execute and publish the mechanical Euler census, boundary-orbit attribution, and torus/prescribed-sphere comparison respectively;
- do not broaden any result into sphere, saturation, ordinal-370, folded-cone, vertex-30 or finalize/contact corrections inside TB21.

## 4. Required closeout evidence

TB21 does not close without all of the following:

- exact run/job ids and result/log artifact ids plus SHA-256/digests;
- complete 391-row identity ledger and its SHA-256;
- accepted-prefix count and full red set;
- D2's exact typed failure/locus fields;
- D3 Euler census and residual;
- D4 per-orbit boundary attribution;
- 371/372 assertion outcomes;
- appended 389–391 outcomes;
- pre/post byte+mode package census equality;
- explicit zero configure/compile/relink/repair/discovery/source/test/fixture/selector mutation statement;
- complete regression/candidate classification in `Regression_Root_Cause_Tracker.md`.

## 5. Successor boundary

TB21 is expected to remain semantically red because ordinal 366's guard is normative and intentionally unchanged.

- **If D3 confirms non-cellularity**, the exact successor is **`M3-CP4c-3-DEFN`**. `DEFN` absorbs `REVIEW + PLAN`; it owns the cut-graph construction contract and `M3-CP4c3-TB20-REV-CAND-02` (CB21's weakening of a prohibited invariant). No Code + Build turn may intervene.
- **If D3 conflicts with the expected non-cellularity conclusion or any BW8 immutability discriminator fails**, stop at **`M3-CP4c-3-TB21-REV`** for independent evidence adjudication. Do not force the definition conclusion from a contradictory ledger.
- A fully green 391/391 gate would close CP4c-3 under the standing workflow, but that outcome must be established by runtime rather than assumed.
