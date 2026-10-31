# CB28 — factory rejection diagnostics: Code + Build (2026-10-22)

- Turn: `M6-CP3-CB28-RP01-FACTORY-ERROR-DIAGNOSTICS`; RA-134.5 test-only message surface.
- Source commit: `19aeb3e60e2d762006d95dc4a5007af54f094ee7` (patch base `2d35c43ca091b7c6082e0ee892bca9a3f54d7f89`).
- Google Drive patch apply: [run 39861042377](https://github.com/akashskypatel/Directional/actions/runs/39861042377), result `12462420512`, exact patch SHA-256 `90c48711d454be0a5755e74e4ae9e4281afe2b849dd81a788cb2430370a95c3e`; 2 test files only (+126/-7).
- TQ and SP10: local `SurfacePhaseFrontProductError` diagnostic code and sourceAuthoritySite/edge/event/cell/region/periodicRelation loci; failed helper construction text and relevant assertion context. SP10 additionally reports `FieldAtlasBuildError` code/location.
- Source-line numbers cited by RA-134.5 (e.g., TQ:5158 and 5942) do not all identify the described clauses at this source revision; CB28 maps only actual authentic factory/A5 diagnostic sources; independent Review must adjudicate scope coverage.
- GMP/GMPXX eight-target compile: [run 39861294132](https://github.com/akashskypatel/Directional/actions/runs/39861294132), result artifact `12460974720`; ZIP SHA-256 `8f5c9a194bac611fbddf625a804ba371994b53aaa39765909a36a484a8133d6b`, packaged 28/28 verified.
- `runtimeExecution=false`; compile only. No unit tests, benchmark execution, runtime PASS or CP3 promotion claimed.
- Accepted CP2 remains 491/491; TB28 462/497 is candidate only, stable 66/17/49, witness debt 1, selector 497 frozen, RP-01 open, RP-02 unreached.
- Next gate: independent CB28-REV static review; canonical full Review ID not yet assigned. Do not start TB29 without Review disposition.
