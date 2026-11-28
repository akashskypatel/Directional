# CB-174 — slide-contact cut binding (Code + Build only)

## Situation
The exact frozen three-file cut-binding diff was applied at source `5190b0e759146342998e3f380f7e5fe4eabd1714` and all eight GNU Multiple Precision (GMP/GMPXX) compilation targets were packaged. No tests or benchmarks ran. Runtime acceptance is not claimed.

## Background
- Turn: `M6-CP3-CB-174-P13-SLIDE-CONTACT-CUT-BINDING`; authority: [TB-REV-157 adversarial Review](Architecture_M6_CP3_TB_REV_157_Adversarial_Review_20261121.md).
- Frozen [exact diff](Architecture_M6_CP3_CB174_P13_Slide_Contact_Cut_Binding_Exact.diff) SHA-256 `236290050270f19b56d849915cfb727a87551477d0be726ac294fd0603fe1c44`.
- [Source snapshot 44949862239](https://github.com/akashskypatel/Directional/actions/runs/44949862239), source `36917d2cabc1dad49bef54c86bba0df1235c3b58`, 5690/5690 file checksums; [Drive apply 44950083696](https://github.com/akashskypatel/Directional/actions/runs/44950083696), patch SHA-256 `c19b5bebd7d47342b70149c7edacd0fcf1917cdc2cc56fedd62c52cd27f19690`, applied commit `5190b0e759146342998e3f380f7e5fe4eabd1714`. The temporary Drive patch was deleted after successful push.
- [GMP compile 44950215403](https://github.com/akashskypatel/Directional/actions/runs/44950215403), artifact `14724824631`, ZIP SHA-256 `d97f3c7ee36a7cec12ede2c73955b1348c3320951e5dbdce71aed5a4db5de205`; all eight targets, GMP/GMPXX linkage, 28/28 packaged checksums and `runtimeExecution=false` verified.

## Assessment
The only source/test changes were `src/geometry/EmbeddedGraphTopology.h`, `src/geometry/EmbeddedGraphTopology.cpp`, and `tests/FieldAlignedCurveNetworkTests.cpp`. `carrier_contact_cut_position` resolves segment entry or slide interior and records `CarrierContactBinding::struckParameter`; `build_arcs` cuts at the struck segment parameter; a slide on a selected cut fails closed under interim Amendment 14. One new test was added as gate row 976 but not executed. The withdrawn CB-174 v3 stop helper was not applied. Tracer, producer, selector, and workflow files were not changed.
TB157 remains the last accepted runtime gate: 975/975, census 3/3, CP2 491/491. Stable 66/17/49, debt 1, deferred 81; sphere χ6 versus χ2, producer stop switch, V3b, and CP3/497/D0/H4 remain unresolved.

## Recommendation
Run only `M6-CP3-TB-EXEC-158-P13-SLIDE-CONTACT-CUT-BINDING-FULL-GATE` in the next separate Test + Benchmark turn against immutable artifact `14724824631`. Require manifest 976/976 PASS, CP2 491/491, rows 1–975 MATCH TB157 artifact `14719149475` under N1–N3 with empty allowance, census 3/3 MATCH TB157 artifact `14719268782` under N1–N4, and zero new `InvalidCutGraphBinding`. Stop on failure; independent TB-REV-158 then reviews results and may freeze CB-175.
