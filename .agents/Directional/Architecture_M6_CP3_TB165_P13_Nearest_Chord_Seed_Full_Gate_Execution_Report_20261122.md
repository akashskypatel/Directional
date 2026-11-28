# TB165 — Nearest-chord seed full gate: immutable Test + Benchmark execution (STOP)

## Situation

**The full gate was 984/984 PASS, but the frozen TB165 acceptance gate FAILED rule 3.** The row-979 nearest-chord seed census emitted **37** records instead of the frozen **16**. All 37 published `status=0`, while the frozen rule predicted `status=2`; 21 records belong to components 0, 2, 3 and 4, outside the two target components. Per TB-REV-164 rules 1–5, the required disposition is typed STOP and independent Review. No source, test, selector, manifest, or recovery changes are authorized here.

## Background — immutable authority

- Canonical turn: `M6-CP3-TB-EXEC-165-P13-NEAREST-CHORD-SEED-FULL-GATE`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8.
- Authority: [TB-REV-164 adversarial Z1–Z6](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md) and [TB-REV-163 Y1–Y7](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md).
- Compiled GMP/GMPXX semantic source `5b5cdf15a670236635d74a15f3791422b182ffe0`; CB-184 artifact `14760674864`, ZIP SHA-256 `e1717c5959346978cff3fee531fb387c26a296572cdee6698c2017e973b9bec3`. Binary and fixture content was not rebuilt or repaired.
- Frozen 984-row manifest SHA-256 `8d56ee1d911daa1bd3cab9f824e79131ce9f75bd7a57b31b5882d3f4f52b1e69`; census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- Full gate [run 45041398551](https://github.com/akashskypatel/Directional/actions/runs/45041398551), result artifact `14762295772`, ZIP SHA-256 `67b5e27d6f2029a0cfa8a78a94e51e1b8e9da82de104fa6693f92a76e3bc92d5`, log artifact `14762280877`, SHA-256 `15ffd37f80d221575d31e7e1a10e5c3c0d6ecbc0f29490ae56064c7ec95c44f9`.
- Census [run 45041524093](https://github.com/akashskypatel/Directional/actions/runs/45041524093), result artifact `14762602145`, ZIP SHA-256 `892bd5cc658abe1f3a3fdcd99ff0f31f35978c917791f303fc63b4101495fc1b`, log `14763235234`, SHA-256 `d90803105c600198a356c2609a8179b17197e13d41b06e0e80f3d7d22ac74554`.
- Baseline TB164 full artifact `14757020531` (SHA-256 `176ab6229182826ecf43d44346e63960c4a40007dde44d6661af9e891c192611`) and census artifact `14757007212` (SHA-256 `69ef085dae88be19d9737eee8e2b7b9c68f9dc00e8929383d6c29cbbaa05465f`).

## Assessment — independent immutable evidence

| Frozen rule | Measured result | Gate disposition |
|---|---|---|
| 1. Full gate and CP2 prefix | **984/984 PASS**, CP2 **491/491 PASS**; no missing, skipped, duplicate, abnormal, or control failures; membership **1065 = 984 + 81 deferred** | PASS |
| 2. Rows 1–978 and 980–982 under N1–N3 | **981/981** normalized log and non-hash ledger equivalence; no differing lines, including the permitted 662 and 788 exceptions | PASS |
| 3. Row979 seed/owner/cellularity | 37 rather than 16 seed records, all `status=0` rather than expected `status=2`. Other changes match the removal of old uncut receipts; owners 192/192; cellularity=1 | **FAIL — STOP** |
| 4. Three-case census under N1–N4 | **3/3 equivalent** to TB164, no exception: Cylinder PASS; BunnyRandom RED at `SurfaceCellDesignAcceptanceTests.cpp:493`, Vase RED at the same assertion, both typed `reason-not-observed` | PASS |
| 5. Stop on any failure | Rule 3 failed; do not modify immutable inputs, recompile, promote selectors or trigger activation | **STOP / Review** |

- Recursive internal SHA-256 verifications: TB165 full **1976/1976**, TB165 census **9/9**, TB164 full **1972/1972**, TB164 census **9/9**; each ledger raw-log hash also matches.
- All **1750/1750** interleaved N3 diagnostic record counts remain equal across TB164/TB165 predecessor rows. The comparison uses N1 elapsed-time, N2 line-ending and N3 record-boundary normalizations; census also uses the authorized N4 opaque 16-byte parameter display normalization.
- The new seed census splits by uncut component: `component 0: 4`, `1: 8`, `2: 4`, `3: 7`, `4: 6`, `5: 8` (total 37). The target 16 edges of components 1 and 5 have the expected orbits **6 and 12**, respectively, but each has `status=0`, not 2. The remaining **21** seed lines are outside those components. All 37 lines are retained verbatim in [the raw evidence file](evidence/Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Raw_20261122.txt).
- Row979 removed the prior 16 `SphereStagedOwnerViolation`, 2 `SphereStagedUncutCensus`, 16 `SphereStagedUncutBoundary` and 16 `SphereStagedUncutSideOwner` records. `SphereStagedOwners`: `sourceFaces=192 owners=192 established=192 unavailable=0 conflicting=0 ... noOrbit=0 violations=0`; `SphereStagedCutGraph`: `sourceFaceCellularity=1`. All arc, trace and slide receipts remain unchanged under N1–N3.
- The **measured**, not predicted, plan outcome advanced from `UncutFaceComponentOrbitSeedNotUnique` at face `2-5-12` to:

```text
SphereStagedPlan outcome=SourceFaceCarriesMultipleTraceCuts sourceFace=6-8-9 sourceEdge=- trace=- secondTrace=- chi=- V=- E=- F=- fragmentOrbits=- tracePieces=- expectedFragments=-
SphereStagedPlanFaceOwner face=6-8-9 status=0 orbits=0,1,2,6,7,8 sides=0:6:r:1,0:6:r:2,0:6:f:0,3:0:r:7,3:0:f:6,4:0:r:6,4:0:f:0,9:6:r:7,9:6:f:8
```

The **complete 34,400-character `SphereStagedPlanLocus` record is preserved verbatim** in the raw evidence file alongside the plan and face-owner records. Production cut search remains `CutSearchExhaustedBeforeCellularity` and output production has not been accepted.

## Regression classification and root-cause limits

**TB165-F1 — non-stable acceptance-falsifier candidate.** The switch writes nearest-chord seeds for four additional uncut components and publishes status zero for all selected edges; this differs from the frozen expected witness of 16 status-two lines. It is a reproducible discrepancy in the CB-184 diagnostic/seed path, not a demonstrated new production regression or proof that the additional owners are geometrically invalid. The site-C branch may legitimately apply more broadly than the frozen prediction; the source meaning of status zero and any downstream validity impact require independent TB-REV-165 source-backed adjudication. Do not silently revise the frozen oracle to fit runtime. No PASS-to-RED gate rows, no new census failure and no evidence to allocate a new stable regression ID. Stable accounting remains **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, deferred **81**. CP3/497/D0/H4 remain unpromoted.

## Recommendation — frozen STOP and Review

Keep the canonical TB165 execution turn blocked on the failed rule-3 acceptance condition. **Route the evidence to `M6-CP3-TB-REV-165-P13-NEAREST-CHORD-SEED-FULL-GATE`** for independent adjudication of all 37 seed lines, their reported statuses, source provenance, Z2/Z3/Z5 and Z6, and the new `SourceFaceCarriesMultipleTraceCuts` plan locus. No Code + Build, activation CB-185, revised manifest, selector change, or promotion is authorized by this execution.
