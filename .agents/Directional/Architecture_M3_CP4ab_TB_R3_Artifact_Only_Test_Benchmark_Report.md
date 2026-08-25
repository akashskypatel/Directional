# M3-CP4ab-TB-R3 — Artifact-Only Test + Benchmark Report

**Turn:** `M3-CP4ab-TB-R3`
**Date:** 2026-08-24 UTC
**Result:** **GREEN — 316/316; CP4ab ACCEPTED; acceptance attempt 1 of 3 consumed**
**Immutable package:** `9527801615`

## 1. Boundary and authority

This turn executed only the frozen cumulative CP4ab acceptance surface from the immutable CB-R11 package. It did **not** configure, rebuild, relink, repair, regenerate test discovery, or mutate product source, tests, fixtures, selectors, or package bytes.

- exact semantic source: `157bf784a9cdd2765018206ae0ac26729ed7a584`
- immutable package artifact: `9527801615`
- package ZIP SHA-256: `a8e03a2181ab4ce2de7386d6b38d66cd361a739f21aa33dde6091a6a2fa54557`
- exact-source archive SHA-256: `498cbb586c8b5dd1d49c3442364b9483d9f04e6d999432a93e72caa9cb4ab157`
- package self-excluding manifest: **27/27 PASS before and after runtime**
- packaged source-status snapshots: **all five empty / clean**
- schema validation: `32758229076 / 97530617094` — PASS
- acceptance execution: `32758293793 / 97530833220` — workflow/job PASS
- result artifact: `9531769503`, SHA-256 `1b4b3784d55f398d113b18c5bc84543cad9f03c48d329d91005598d63ed801fc`
- execution-log artifact: `9531770393`, SHA-256 `cff83f726fd9fa6dc762126a3632178e0d94abd3d17f4e57b287d0738cd69643`

The package source archive was materialized at the runner workspace **without stripping its recorded root layout**. The known `benchmarks/fixtures/milestone-g/plane.obj` fixture was present. A fresh second extraction was byte-identical both before and after runtime; both source diff files are zero bytes.

## 2. Frozen selector authority

No discovery command was executed. The accepted CP3b result artifact supplied the already-frozen 304-identity predecessor selector and its historical per-binary group selectors. TB-R3 appended only the frozen CP4ab twelve.

| Selector | Cardinality | SHA-256 |
|---|---:|---|
| accepted predecessor | 304 | `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666` |
| CP4ab | 12 | `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec` |
| cumulative gate | **316** | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |

The cumulative file contains **316 non-empty / 316 unique** identities. The accepted predecessor ran first. Each of the twelve CP4ab identities then ran in its own process on `directional_surface_cell_producer_tests`, preserving identity-scoped evidence.

## 3. Gate result

**Valid acceptance result: GREEN 316/316.**

- accepted predecessor: **304/304 PASS**, zero failures/errors/disabled
- CP4ab: **12/12 PASS**, zero failures/errors/disabled
- cumulative gate: **316/316 PASS**, zero failures
- orchestration errors: **0**
- acceptance attempt consumed: **1 of 3**

The 304 predecessor identities retained their accepted result. The twelve CP4ab identities all remained green after DG-R6 and under the full predecessor surface, so the focused diagnostic was not masking a cumulative interaction.

## 4. CP4ab review

The binding DG-R5 predictions and the DG-R6 de-risking are now confirmed by the actual acceptance gate rather than by a focused diagnostic:

- A1–A6 pass under the cumulative gate.
- B1–B6 pass under the cumulative gate.
- A5 reaches the intended source-face ownership validator rather than an earlier derived-consumer rejection.
- B2 reaches the single-boundary-walk owner rather than `region_orbit` shadowing it.
- B3 remains green after the validation-order correction.
- B4 remains green with the independently derived bounded-surface Euler oracle.
- the accepted CP3b predecessor remains 304/304 green, including U5/U6 as members of that predecessor surface.

No independent review is required: the acceptance result is complete, green, and contains no semantic residue requiring adjudication.

## 5. Immutability and command boundary

Preflight and postflight establish:

- package ZIP SHA-256 unchanged at `a8e03a2181ab4ce2de7386d6b38d66cd361a739f21aa33dde6091a6a2fa54557`;
- source archive SHA-256 unchanged at `498cbb586c8b5dd1d49c3442364b9483d9f04e6d999432a93e72caa9cb4ab157`;
- package manifest **27/27 PASS** both times;
- materialized source tree byte-identical to a fresh extraction before and after runtime;
- `configure=false`, `build=false`, `relink=false`, `repair=false`, `generatedDiscovery=false`;
- `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`, `selectorMutation=false`, `packageMutation=false`.

The only generated files were runner-local logs/JSON evidence and Actions artifacts outside the immutable package/source authority.

## 6. Regression and budget disposition

`PR8-R042 / M3-CP4b-R001` is **RESOLVED STABLE**. Its accepted-predecessor regressions are restored under the full 316 acceptance gate, not merely under focused diagnostics. Stable totals do not decrease when a stable event is resolved.

- stable accounting: **42 events / 14 categories / 28 recurrences**
- produced-witness debt: **5**
- cumulative M3 packages: **34**
- CP4ab acceptance: **1/3 consumed — GREEN / checkpoint closed**
- CP4ab diagnostics: **1/2 consumed** in the final user-reset window
- latest accepted runtime authority: **M3 CP4ab 316/316** on source/package `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`

## 7. Successor

**`M3-CP4ab` is CLOSED / ACCEPTED.** The blocking condition on CP4c is removed.

Exact next bounded implementation turn is **`M3-CP4c-CB`**, Code + Build only, under `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md` section 4A.3c and `Architecture_M3_CP4_DEFN_Frozen_Definitions.md` section 7.3. CP4c owns six frozen C identities and the cumulative **322 = accepted 316 + C1–C6** M3 exit gate. It has its own untouched 3-attempt acceptance budget and the plan allocates one diagnostic gate to it. No CP4c runtime is started by this closeout.

## 8. Process note

One connector tool-schema discovery call occurred before the mandatory `TOOL_USE_CONSERVATION_POLICY.md` read at the start of this turn. The policy was then read in full and `READ_MODE=snapshot` selected before repository source/document inspection, runtime execution, or semantic mutation. This ordering miss is process-only and has no package, runtime, acceptance-result, or stable-regression impact.
