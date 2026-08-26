# M3-CP4c-0-TB-R6 — Artifact-Only Test + Benchmark Report

**Status:** COMPLETE / VALID SEMANTIC RED
**Turn boundary:** Test + Benchmark, artifact-only. No build, repair, source/test/fixture/selector mutation, acceptance rewrite, or performance benchmark.

## 1. Immutable authority

| Authority | Value |
|---|---|
| Semantic source | `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6` |
| Immutable package artifact | `9619352525` |
| Package ZIP SHA-256 | `b45306c3c5b3b9ff094131be8073aed5c6180533fdbe0b04f220ca929b4dd672` |
| Packaged source archive SHA-256 | `308e02580033b5a319e08d7916afc921693d2b15f645813c2cdbaed336320093` |
| TB control SHA | `a9ae307590b0cc23080452c4a5013674efc48fc2` |
| Hosted run / job | `33006282429 / 98300813772` |
| Result artifact | `9620769314`, ZIP SHA-256 `fe6a73175399b764f7cbb3ea2963a8deb40d6d0b5afcc3e9a603102ee4936684` |
| Diagnostic artifact | `9620770049`, ZIP SHA-256 `ce87da5a919e31f7e36a8d904dfaad7c7d9c92b9bebf36a494de096e7cb691cb` |

The package internal `SHA256SUMS` verifies **27/27** before runtime. `metadata/source-commit.txt`, build/preflight exit codes, empty source-status files, `runtimeExecution=false`, selector hashes, source archive hash, fixtures, packaged source and executable inventory all match CB6 authority. Postflight reports `PASS` with package/source/test/fixture/selector mutation all false.

## 2. Frozen selector and fresh-process gate

The packaged selector is unchanged:

- 338 SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
- first 316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- first 328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.

All **338 identities executed in exact selector order, one identity per fresh process**. Result: **338/338 PASS**, accepted prefix **316/316 PASS**, first-328 **328/328 PASS**, `first_red_ordinal=0`. F3 then executed both supplementals in fresh producer-test processes and is **2/2 PASS**. G5, decomposed H1, and J3 each executed in their own fresh producer-test process and remain explicitly **non-gating / uncredited**. Total fresh semantic processes: **343**.

## 3. G5 — live sphere failure is unchanged

G5 is PASS/non-gating. The prescribed sphere still reaches A1 and fails before network publication:

- `networkError=BranchTransportFlowDisagreement`;
- source edge `6-8`;
- source face `6-8-9`, branch `3`;
- related face `6-8-97`, branch `1`;
- `signedLift=2`;
- seven ordered trace-history steps from `0-1-2` branch 0 through `6-8-9` branch 3.

This is the same binding Q8 condition as TB-R4/TB-R5.

## 4. J1/H1 — decomposed A1 flow-agreement census

H1 is PASS/non-gating and reproduced the independent review's corrected population exactly.

| Witness | Population | Pairs | Directed violations | Distinct disagreements | Singular-incident directed violations | Matching histogram over violations |
|---|---|---:|---:|---:|---:|---|
| two-ring | included | 160 | 4 | 2 | 4 | `0:4` |
| four-triangle-fan | **excluded fixture artifact** | 32 | 2 | 1 | 2 | `-1:1, 1:1` |
| prescribed sphere | included | 2304 | 144 | 72 | 48 | `-3:12, -1:12, 0:96, 1:12, 3:12` |
| torus | included | 1728 | 240 | 120 | 0 | `0:240` |
| **legitimate total** | included only | **4192** | **388** | **194** | **52** | — |

The fan prediction is exact: 2 directed / 1 distinct on edge `1-4`, with forward decomposition `matching=1`, `rawGaugeSource=0`, `rawGaugeTarget=1`, `signedLift=0`. It remains excluded from production reasoning.

Across the legitimate 388 directed / 194 distinct disagreements, the frozen decision-table terms split as follows:

| J1 concentration | Directed | Distinct | Interpretation before J3 |
|---|---:|---:|---|
| `matching != 0` | 48 | 24 | possible matching authority / aliasing |
| `matching = 0`, unequal raw gauges | 86 | 43 | A1 gauge-composition branch |
| `matching = 0`, equal raw gauges, lift 0 | 254 | 127 | A1 flow classification / direction publication |
| `matching = 0`, equal raw gauges, nonzero lift | 0 | 0 | absent |

Only **52/388** legitimate directed disagreements are singular-incident, so the census is not primarily a singular/cut-seam concentration.

### Live Q8 locus

The exact H1 reciprocal pair for sphere edge `6-8` is decisive under the frozen table. Forward direction:

`sourceFace=6-8-9`, `targetFace=6-8-97`, `sourceBranch=3`, `targetBranch=1`, `matching=0`, `rawGaugeSource=1`, `rawGaugeTarget=3`, `signedLift=2`, singular-incident=true.

Thus the live Q8 failure is in the **`matching=0` + unequal-gauge** class, not the matching-nonzero class.

## 5. J3 — matching-versus-geometry census

J3 is PASS/non-gating and independently derives raw-index correspondence by unfolding the two incident source triangles about each shared edge. It does not use tracing, H1 flow classification, or published branch transport.

| Witness | Population | Interior edges | Agreements | Disagreements |
|---|---|---:|---:|---:|
| two-ring | included | 20 | 20 | 0 |
| four-triangle-fan | **excluded fixture artifact** | 4 | 3 | 1 |
| prescribed sphere | included | 288 | 288 | 0 |
| torus | included | 216 | 216 | 0 |
| **legitimate total** | included only | **524** | **524** | **0** |

The fan's sole J3 mismatch is exactly edge `1-4`: declared raw target `1` / declared matching `1`, geometry raw target `0` / geometry matching `0`. That independently confirms the fan exclusion.

For all **524 legitimate interior transitions**, declared matching agrees with geometry. Therefore the current H-B field-matching/edge-aliasing hypothesis is **not supported on any legitimate witness in this census**. Combined with J1, the live sphere edge `6-8` selects the frozen decision-table row for **A1 gauge composition in `build_branch_transports`**. The much larger equal-gauge/lift-0 residual is a separate A1 flow-classification/direction-publication class associated with `build_boundary_pairing`; independent review must determine whether it shares a lower common invariant or requires separate treatment.

## 6. Frozen Q8 evaluation

Q8 is **creditable** because package integrity is exact, gate is 338/338, and F3 is 2/2. Frozen criteria remain unchanged:

| Criterion | TB-R6 result |
|---|---|
| 1. accepted 316/316 green | **PASS** |
| 2. prescribed sphere publishes 24 traces | **RED** |
| 3. at least one terminal `TraceIntersection` | **NOT_EVALUABLE** |
| 4. face `1-2-5` crossover choice/flip | **PASS** |
| 5. torus mechanical A1 failure unchanged | **CARRIED_UNCHANGED_NOT_RERUN** |

Binding reason: `criterion2_sphere_network_not_published`. This red was expected because CB6 was diagnostic-only and J0 prohibited a production fix.

## 7. Postflight integrity and orchestration disposition

Authoritative run `33006282429` completes with `orchestrationErrors=0`, postflight `PASS`, and all mutation/build flags false. No configure, compile, relink, repair, generated discovery, or performance benchmark occurred.

A prior control attempt `33006048971 / 98300014224` is **orchestration-only and non-semantic**. Its Python `zipfile.extractall` path materialized the package without executable mode bits, so the first attempted binary launch failed with `PermissionError` before any Directional binary executed. The retry replaced only the extraction mechanism with ordinary `unzip`, which preserves archived modes; it did **not** chmod/repair package contents. Package/source/selector authority remained identical. Result artifact `9620573488` / `07f0ae4f33a85274fc92784c52722defa3f9502237dc805bdc10d2f9a2f26195` and log artifact `9620573957` / `228c141b73240a57cc7eb6596718580e3eb480059233c0387130d7caae961935` retain that failed-control evidence only.

## 8. Regression accounting and successor

TB-R6 continues `M3-CP4c0-TB-R4-CAND-01`; it does not create a stable regression because accepted CP4ab authority remains **316/316** and CP4c-0 has never been accepted. Stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt **5**; M3 packages **45**.

**Exact successor:** `M3-CP4c-0-TB-R6-REVIEW-PLAN`, independent review/planning only. The review must adjudicate the evidence-supported live-Q8 owner (`build_branch_transports` gauge composition) against the separate 254-directed / 127-distinct equal-gauge flow-classification residual, prove the lowest common invariant or split them explicitly, and freeze exactly one bounded successor. Do not retry TB-R6, patch production, or enter CP4c-1/2/3 before that review.
