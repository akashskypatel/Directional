# CB-183 — Nearest-chord seed decision helper (Code + Build)

## Situation

The exact frozen CB-183 patch was applied and compiled. The helper remains unwired. No Directional test, benchmark, or compiled program was executed.

## Background

- Authority: `Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md` Z1–Z6.
- Frozen exact diff SHA-256: `5230d0973376639ff49ff844f198314a0294729000695101682a3174303377b9`, +77/−0.
- Source snapshot: `7712f3faaeef55d92544777884945b24e6936f5f`, run `45034857796`, artifact `14758958452`.
- First patch application attempt [run 45035101950](https://github.com/akashskypatel/Directional/actions/runs/45035101950) failed before commit. The transport patch metadata used comma-delimited `intended_paths`; the reusable expects semicolons. The semantic diff was unchanged. The corrected transport patch SHA-256 was `916835ba99aa61833254d500c20325fa1bb562a62f843587417d094bcbe4e7bc`.
- Successful [patch application run 45035319039](https://github.com/akashskypatel/Directional/actions/runs/45035319039) committed semantic source `639f665942906d02f0dbc4b826ef4d56e3829d5a`.
- Exact postimage SHA-256: `src/geometry/ThirdEdgeSideOwner.h` `2887ed0c80610ab20835a7f0cdc22c182fb840bdbf25dc92353d195738ae6265`; `tests/FieldAlignedCurveNetworkTests.cpp` `0a752b82ad20c836c0109a477bcac624c2f7259c51537e8b59d0cdd3556d9592`.
- [Compile run 45035527412](https://github.com/akashskypatel/Directional/actions/runs/45035527412), artifact `14758973225`, ZIP SHA-256 `4ac5ea648239ded2f752574cdea8d067f2c1b583c87bdb3e28a81e1bf4fcffca`. All eight required targets compiled with GMP and GMPXX. `runtimeExecution=false`.

## Assessment

The pure helper selects a unique nearest chord only if it is the outermost candidate, its orbit is certified in the recorded side set, and the face has no unordered segment. The two tests are compiled but not executed. There is no production seed switch, selector change, test-manifest change, runtime claim, or CP3 acceptance promotion. TB164 remains latest runtime: 982/982 and census 3/3. CP2 remains 491/491; stable 66/17/49, debt1, deferred81.

## Recommendation

Proceed only in a separate turn to `M6-CP3-CB-184-P13-NEAREST-CHORD-SEED-SWITCH`. Apply its exact stacked diff `fe9576d84e79d125712b847cd345bfe4308ba26a0c88b9ff48e9291c1a6f758a` and compile only. Then TB-EXEC-165 owns the 984-case gate and the three-case census. Do not begin successor code in CB-183.
