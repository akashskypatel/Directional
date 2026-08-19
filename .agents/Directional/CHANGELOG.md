# Changelog

### Changed — M3 CP2 package 9 compile-green; immutable 287/287 candidate frozen

- Exact semantic source `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff` implements the frozen eight-file typed `FieldAlignedCurveNetwork` CP2 slice; the final compile correction is one namespace qualification in the typed seed path.
- Mandatory pre-package `32279124852 / 96153441513` was green on the literal source with `runtimeExecution=false`; result/log `9375262215 / 9375262622`.
- Package 9 `32279806492 / 96155630834` compiled and packaged the identical source. Package/log `9375452692 / 9375453342`; package outer SHA-256 `6f8865a3d3c28ea803a40cc9929f22de5a1d313f4810541f6474bbfba9b8ef79`; packaged source archive SHA-256 `5b1f047a986e9d58058b09efdf362112674ba63fe255230f5d2f4db2c0872870`, 549 members, zero symlinks; 28 files / 27 self-excluding manifest entries / five empty source-status snapshots.
- No generated runtime executed; stable totals remain **38 / 14 / 24**, produced-witness debt **5**. M3 is **9/12**. Exact next is immutable `M3-CP2-TB` at **287/287**; CP3a is blocked until CP2 acceptance.
- `tmp-lowlevel-test` contains zero unique work and remains disposable because the connector exposes no branch-delete operation.

### Changed — M3 CP1 accepted: exact-zero cycle support correction restores full frozen gate

- Immutable `M3-CP1-TB-R3` `32263614534 / 96102598799` consumed exact `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` artifact-only and passed **281/281**: A1 **6/6**, retained M2 **275/275**, retained M1 producer **138/138**. Result/log `9369359878 / 9369360425` have outer SHA-256 `829f51e1510ba6aab2eb6f6eed716bd736dcd662b1932b05a6fe16d6223917fd / b624982cd6f5479cd167124c3897725533c6ce460fb6ce96751dfcfcfb18572c`; `failedIdentities=[]`.
- Package/source postflight remained byte-identical. No repository checkout supplied semantic source; no rebuild, relink, package repair, source/test/fixture mutation, generated discovery, or benchmark execution occurred.
- `PR8-R038 / M3-CP1-R001` is resolved: exact algebraic-zero sparse cycle entries had polluted curvature support while typed transport already ignored them. R5 canonicalizes exact zero before iterator-visible curvature/support semantics, restoring one semantic support for exact lift/index and composed transport. `M3-CP1-TB-CAND-01` is also resolved at A1 6/6.
- Resolution adds no new historical incidence. Stable totals remain **38 events / 14 categories / 24 recurrences**; produced-witness debt **5**.
- CP1 is **ACCEPTED**, package budget **7/7**; M3 consumption is **8/11**. Exact next is planning-only `M3-POST-CP1-ALLOC-REPLAN`; CP2 remains blocked until three remaining packages are reconciled against four currently planned later Code + Build checkpoints.

### Changed — M3 CP1 R5 package 7 compile-green; immutable TB-R3 candidate frozen

- `M3-CP1-CB-R5` exact semantic source `9f7e222bab6c930a12d1369fa2aee869f5c0dcff` changes exactly two files: `MeshTopology.cpp` canonicalizes exact algebraic-zero final cycle-basis storage before curvature iteration, and the existing relative-boundary square test independently proves zero semantic support, identity transport, lift `4`, and oracle agreement. A1 congruence and the hard production gate remain intact.
- Mandatory external pre-package `32256978633 / 96080841350` passed **91/91** on literal `9f7e222bab6c930a12d1369fa2aee869f5c0dcff` with `runtimeExecution=false`; result/log `9366688695 / 9366689453`. It consumed no package.
- Authorized package 7 `32257160818 / 96081424766` compiled the identical source across the full approved owner closure **123/123**, producing package `9366752046` SHA-256 `5d779d578f900597053527e2edf7e61f3382de94a1852e94e2fdb712460595a7` and log `9366752647` SHA-256 `6d664f0bcc767958f4dbfddcba808f7e86fede6515595b9c5265414298dee3a9`. Package manifest/source status self-verification passed; source archive SHA-256 `50566ca66d26b92db4a008ce735a1164b061eb273206d10800b554af236d8c73`, 554 members, zero symlinks.
- No generated Directional runtime/test/benchmark/discovery/CLI executed. CP1 is **7/7**, M3 **8/11**, but CP1 remains NOT ACCEPTED. Regression totals remain **38 / 14 / 24**, produced-witness debt **5** because Code + Build observes no runtime.
- Exact next is immutable `M3-CP1-TB-R3` on `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` at unchanged **281/281** acceptance. Any red stops for Review; if green, successor is `M3-POST-CP1-ALLOC-REPLAN` before CP2.

### Changed — M3 CP1 A1 rescope: asserted cycle-transport congruence disproven; design amendment recommended

- `M3-CP1-A1-RESCOPE` completed as Review/planning only. No runtime observed, no package consumed, no product, test, fixture, or build input mutated. Owning document is `Architecture_M3_CP1_A1_Rescope_Review.md`.
- The first failed premise in the prior F5 derivation is the congruence itself. `effort_to_indices` (`src/fields/FieldMatching.cpp:5-21`) builds the cycle index from `effort` and `curvature`, and `FieldTransportAtlas.cpp:720-726` reproduces that formula exactly, so `turningLift` **is** the accepted index. `principal_matching` (`src/fields/FieldMatching.cpp:123-125`) makes `matching` an integer branch offset `round((currEffort - effort)/2π)` from a principal angle and an N-branch unwrapped sum. The two quantities come from different inputs; no congruence between `Σ matching (mod 4)` and the index follows from either definition.
- Hand-derived failing-valid cycle: any interior vertex cycle on a curved, non-singular region has `index = 0`, `curvature ≠ 0`, hence `Σ ±effort = −N·curvature ≠ 0`, per-edge `matching ≠ 0`, and `composed ≠ 0 = normalized_quarter_turn(0)` → `CycleTransportMismatch` on a valid cycle. Reversal negates both sides and `−x ≢ 0 (mod 4)` whenever `x ≢ 0`, so both orientation branches fail on identical cycles. This is why six packages of sign searching could not repair it.
- Prediction verified against evidence: `tests/FieldTransportAtlasTests.cpp:51-68` places all four `make_square_mesh` vertices at `z = 0.0`. A1's fixtures are planar, so curvature and every `matching` are zero and the congruence holds trivially `0 ≡ 0`. This explains the exact observed split — A1 **3/6** on degenerate fixtures while 20 retained M1 producer identities on curved production meshes are preempted by A1's hard gate at `src/pipeline/RemeshPipeline.cpp:6573-6583`. With the F4 oracle read-back, the checkpoint had no mechanism capable of falsifying its own central invariant.
- Recommendation: explicit A1 design amendment. Remove the congruence as a construction-time precondition with no replacement congruence, corrected sign, inequality, or tolerance — A1 re-deriving the index is authority duplication under migration rule 1. Amended A1 consumes the index, publishes it typed, and asserts typed transport completeness, reciprocity `κ(f→g) = −κ(g→f)`, index fidelity against `effort_to_indices`, non-traversable classification, and certificate binding by digest.
- `Architecture_M3_CP1_A1_Derivation_Review_Report.md` is retained as history with its `Z4` relation marked DISPROVEN; the superseded durable lesson asserting `turningLift ≡ sum(s_e*matching_e) (mod 4)` is corrected in place rather than deleted.
- `PR8-R038 / M3-CP1-R001` and `M3-CP1-TB-CAND-01` are unchanged; a review turn observes no runtime. Stable totals remain **38 / 14 / 24**, produced-witness debt **5**.
- CP1 remains **NOT ACCEPTED**, **6/6**; M3 **7/11**. This review authorizes no package. Exact next is planning-only `M3-CP1-PLAN-AMEND`, which must record the design amendment, state the quadrangulability certificate's honest scope, and amend the allocation **CP1 6 → 7 / M3 → 8/11** with explicit notice that CP2-CP4 then share 3 packages. CP2+ remain blocked.

### Changed — M3 CP1 package-6 immutable R2 reproduces A1 cycle mismatch; rescope required

- `M3-CP1-TB-R2` `32226787294 / 95987961593` consumed exact source/package `95006048225df765b5b9c31e235fed82330a1469 / 9354456191` artifact-only. Result/log `9355788148 / 9355788629` outer SHA-256 `0aa97b371e0081c094791ed568117685e1c8cfe79b8488fe8c0b28d3e6dd00b8 / 9097f7f3859676c6130ab1dc1c8015beae909008af90c325cfcd673292b6040e`; package/source postflight was byte-identical and no rebuild, relink, repair, source/test/fixture mutation, generated discovery, or benchmark execution occurred.
- All **281/281** frozen identities selected. Gate remains **258/281 FAIL**: A1 **3/6**, retained M2 **255/275**, retained loss isolated to M1 producer **118/138**; all other retained partitions are green. The same three A1 baselines and same twenty retained producer identities remain red behind `CycleTransportMismatch` or dependent early-rejection effects.
- R4's fixed cycle-row orientation, immutable expected lift, and independently source-derived cycle oracle therefore do not establish the prior F5 relation on the valid baseline. The abstract-to-repository convention mapping must be reopened rather than patched by another sign search, invariant weakening, or A1 bypass.
- `PR8-R038 / M3-CP1-R001` remains the same open stable recurrence and `M3-CP1-TB-CAND-01` remains the same non-stable three-test candidate. R2 adds no new stable event or recurrence; totals remain **38 / 14 / 24**, produced-witness debt **5**.
- CP1 remains **NOT ACCEPTED**, **6/6**, M3 **7/11**. No package 7 is authorized. Exact next is Review/planning-only `M3-CP1-A1-RESCOPE`; CP2+ remain blocked.

### Changed — M3 CP1 R4 package 6 compile-green; immutable TB-R2 candidate frozen

- User authorization amended CP1 local cap **5 -> 6**. Exact semantic source `95006048225df765b5b9c31e235fed82330a1469` changes exactly `src/authority/FieldTransportAtlas.cpp` and `tests/FieldTransportAtlasTests.cpp` (+425/-50): production removes whole-cycle orientation/sign search and immutable `turningLift` is checked once; the oracle independently derives source connection/matching/effort, cycle support/orientation, curvature, and exact lift.
- Required external owner pre-package `32222508189 / 95975565518` passed **91/91** on the literal source. Result/log `9354405173 / 9354405691` outer SHA-256 `d86c8b1b13be1f3f62a956b334a65221a4a4def6f0060202bc2cbd4604f78036 / 329fbe1c638396a1e15f522f15c8f1cf0bfe17dd5c23f78de69b1dc104532e71`. It consumed no package and recorded `runtimeExecution=false`.
- Authorized package 6 `32222669309 / 95976032350` compiled the identical source across the complete approved target set **123/123**. Result/package `9354456191` SHA-256 `da1b4e111642c4b637746c81df1f7d24eb56d47dda9ac3de0a69b5d126313c18`; log `9354456667` SHA-256 `2a1b91ff7667b8071e5647bbe9f3004f1fe34851f8ed917fea90a8ef0f1a6d97`. Manifest/source-status verification passed; `runtimeExecution=false`; no generated Directional test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- CP1 is **6/6**, M3 **7/11**, but CP1 remains **NOT ACCEPTED**. M2 remains accepted at **275/275 + K=0**. Stable regression totals remain **38 / 14 / 24**, produced-witness debt **5**; Code + Build does not resolve the historical R1 reds.
- Exact next is immutable `M3-CP1-TB-R2` consuming `95006048225df765b5b9c31e235fed82330a1469 / 9354456191` without rebuild or mutation at unchanged **281/281** acceptance. CP2+ remain blocked; no CP1 package 7 is authorized.

### Changed — M3 CP1 A1 cycle relation derived; final repair narrowed

- Independent `Architecture_M3_A1_Implementation_Review.md` correctly localized the residual package-5 failure to whole-cycle orientation search, publication of a searched `turningLift`, and an oracle that reads that published value back. Planning-only `M3-CP1-A1-DERIVATION` independently reviewed those findings; no product/test/build source, compile, package, or generated Directional runtime was authorized or executed.
- The missing F5 relation is now written explicitly from accepted repository conventions: for the signed `dual_cycles` row, `turningLift = (sum(s_e*effort_e) + 4*K_C)/(2*pi)` and **`turningLift ≡ sum(s_e*matching_e) (mod 4)`**. `QuarterTurn` composition is therefore the correct `Z4` comparison. The invariant is retained; semantic orientation may not be searched or adjusted until it passes.
- The independent review's C1 persistent staging recommendation is narrowed. `DESIGN.md` §7.5 requires A1 before topology planning, so CP1 cannot be accepted by bypassing A1 and postponing the hard gate. The twenty retained reds must be restored by making valid predecessor inputs satisfy A1.
- Final bounded repair scope is one semantic domain in two files: `src/authority/FieldTransportAtlas.cpp` (single fixed row orientation, immutable derived lift) and `tests/FieldTransportAtlasTests.cpp` (independent source-derived cycle index/oracle). `RemeshPipeline.cpp`, headers, fixtures, and build contracts are outside the final repair.
- CP1 remains **NOT ACCEPTED**, **5/5**, M3 **6/11**; M2 remains accepted at **275/275 + K=0**. Stable totals remain **38 / 14 / 24**, produced-witness debt **5**. No package 6 is authorized. Exact successor `M3-CP1-CB-R4` is BLOCKED pending explicit CP1 local-cap **5 -> 6** authorization; if authorized, a true external pre-package compile must precede package 6.

### Changed — M3 CP1 package-5 immutable R1 narrows but does not resolve A1 transport regression

- `M3-CP1-TB-R1` `32211699382 / 95945506893` consumed exact source/package `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667 / 9350420635` artifact-only. Result/log `9350958978 / 9350959164` outer SHA-256 `eb43ba06e63ba230cf9c77bcdf1efc5e856b2adb660b04ce5fac8e3378286793 / a5346129311c70d084124b342f59f3c2c0097e198606ff14dca69a1f4ed6c03e`; package/source postflight unchanged; no rebuild, relink, repair, source/test/fixture mutation, discovery, or benchmark execution.
- All **281/281** frozen identities selected. Gate is **258/281 FAIL**: A1 **3/6**, retained M2 **255/275**, retained loss isolated to M1 producer **118/138**; all other retained partitions remain green.
- R3 restores `FieldTransportAtlas.ClassifiesHardFeaturesAsNontraversableCuts` and retained `HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped`. Three A1 positives/oracles and twenty retained producer identities remain red. Surviving earliest diagnostics are `InvalidFieldTransportAtlas:field-transport-atlas/CycleTransportMismatch`; downstream variant exceptions and unreached mutation/oracle seams are dependent failures.
- `PR8-R038 / M3-CP1-R001` remains the single open stable recurrence; R1 is partial repair/refinement, not a new stable event. `M3-CP1-TB-CAND-01` narrows from four to three new A1 reds and remains non-stable. Totals stay **38 events / 14 categories / 24 recurrences**; produced-witness debt **5**.
- CP1 remains **NOT ACCEPTED**, **5/5**, M3 **6/11**. M2 remains accepted runtime authority. No package 6 is authorized. Exact next is Review/planning-only `M3-CP1-RUNTIME-REPLAN-R2`; CP2+ remain blocked.

### Changed — M3 CP1 R3 package 5 compile-green; immutable TB candidate frozen

- User authorization raised CP1 local cap from 4 to **5** while retaining the M3 hard ceiling of **11**. Exact semantic source `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667` was unchanged from the green external pre-package compile.
- Full package run/job `32209993498 / 95940623789` compiled the authority-kernel owner **91/91** then the remaining approved closure **32/32**, for **123 build actions**. Result/log `9350420635 / 9350421043` have outer SHA-256 `553da343e6400ed1acee2272acadafd5f61f59e4d1b8bdf51c3552cb339cc370 / b26965cb859c8c3cfaacbf0fc7a3e574b0fa8dacf887aee119bdc8d45725075e`; result manifest self-verification is **27/27** across 28 uploaded files and source status is clean.
- `runtimeExecution=false`; no generated test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Post-package source audit confirms every branch change after `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667` is documentation/control-plane only. CP1 is **5/5**, M3 **6/11**, no package 6 is authorized. `PR8-R038` and `M3-CP1-TB-CAND-01` remain open until immutable runtime evidence.
- Exact next is `M3-CP1-TB-R1` consuming `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667 / 9350420635` without rebuild or mutation.

### Changed — M3 CP1 runtime replan retains A1; bounded R3 correction pre-package compile-green

- Independent runtime replan retained the CP0 A1 contract and refined the failed-TB diagnosis: `dual_cycles` includes the required cycle families, but explicit sparse algebraic zero storage was treated as semantic support, while valid one-face relative-boundary regions were forced through a generic local `TriMesh` representation that can reject a single triangle.
- Exact source `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667` changes only `src/authority/FieldTransportAtlas.cpp` (+56/-2): ignore near-zero stored coefficients before strict nonzero `±1` support validation; directly publish the checked trivial one-face relative-boundary witness. Tests, fixtures, header, build contract, and semantic-domain count are unchanged.
- External owner-prepackage run/job `32208365044 / 95935875386` passed **91/91** for `directional_surface_cell_authority_kernel_tests` on literal `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667`. Result/log `9349870579 / 9349870841` SHA-256 `b206228343ccee32e05f12d782443a93488a858f4a8ef2ebcce5dc1ac98cca02 / 4cec8b2164044e0a07d6e2b4db0dfeea930f156df862a279ec0453449d81f948`. `runtimeExecution=false`; no generated Directional runtime/test/benchmark/discovery/CLI executed.
- This pre-package evidence is mechanics-only and consumes no CP1 package. CP1 remains **4/4**, M3 **5/11**, and `PR8-R038 / M3-CP1-R001` remains open until immutable runtime acceptance. Stable totals stay **38 / 14 / 24**; produced-witness debt **5**.
- Exact next is `M3-CP1-CB-R3-PACKAGE`, blocked pending explicit user authorization for CP1 package 5 / local cap 4 -> 5.

### Changed — M3 CP1 immutable runtime gate rejects atlas authority

- `M3-CP1-TB` consumed exact `9f54c77ae92161226e833cf313bf38e516aa276c / 9347879320` without rebuild/relink/repair/source-test-fixture mutation or discovery; package/source postflight unchanged.
- Run/job `32204335734 / 95924452913`; result/log `9348592210 / 9348592414`; all **281/281** selected; result **256/281**, with A1 **2/6** and retained M2 **254/275**.
- `PR8-R038 / M3-CP1-R001` records one stable RP-01 recurrence: reconstructed local tangent-bundle cycle/binding representation is promoted to canonical A1 source authority, causing valid retained paths to reject early. Four new A1 baseline-construction reds are non-stable `M3-CP1-TB-CAND-01`.
- CP1 is NOT ACCEPTED; M2 remains runtime authority at **275/275 + K=0**. Stable totals become **38 events / 14 categories / 24 recurrences**; debt remains **5**.
- CP1 is 4/4, M3 is 5/11, no package 5 is authorized. Exact next is Review/planning-only `M3-CP1-RUNTIME-REPLAN`.

### Changed — M3 CP1 R2 package compile-green after true pre-package gate

- The user explicitly authorized the CP1 local-cap amendment from 3 to **4** while retaining M3's hard cumulative ceiling of **11**. Exact semantic source `9f54c77ae92161226e833cf313bf38e516aa276c` changes only `tests/FieldTransportAtlasTests.cpp` by importing `directional::authority::FieldCycleId`; production atlas blobs remain `0c0dc968672c19887a9d0af2b84fe61056fac21c / 7d50b8567396e79938071dbc3473ec28482a960a`.
- A true external pre-package compile ran before package 4: `32201791916 / 95916966789` compiled only `directional_surface_cell_authority_kernel_tests` on the literal semantic source and passed **91/91**. Mechanics-only result/log artifacts `9347775163 / 9347775370` have outer SHA-256 `99d91c0cbcb10abfee2d7ffed42b159e517eb3a6b85b323cc0e13f949f141268 / 1a6d9a5ea7e4ec698da4b0c41ef96dd0ec892e393ac4b5b2d7856b3fe04c175e`; this result is not TB authority.
- Post-preflight source audit reconfirmed the frozen CP1 slice, one-line source delta, unchanged production bytes, and unchanged source-derived independent-oracle semantics. No product/test/build source changed after preflight.
- Full package `M3-CP1-CB-R2` ran as `32201987864 / 95917547662` on the identical literal source SHA. Authority-kernel preflight was 91/91 and the remaining approved closure 32/32, for **123 build actions**. Result artifact `9347879320` has outer SHA-256 `213cc0dfd06370da71e964271f36e49494bf31633a70c1ae9bfe6bba1b8bcb4a`; log `9347879687` has outer SHA-256 `d5ab6b1f7f771b480277f9d298cd4af71e5174be04bc5c0b2f67c4c1eb021b89`.
- Package verification is **27/27** self-excluding manifest entries across 28 regular files, zero package/archive symlinks, six owner executables, two libraries, five empty source-status snapshots, nine dependency revisions, and a 548-member source archive SHA-256 `68173e8cb0d765debde49086256ea8511175b656908ef68eb24e7b44b9492b45`. `runtimeExecution=false`; no generated test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- R2 temporary state was removed workflow-first then marker for both pre-package (`46b65cfb876ca7ea22cec90bc402a21e52e7ff6b / 6ba2aa3523caba947721cb602a9955d5227f4b67`) and full package (`97884f05154d3fba6aa163fd7b7b88c1ae9f7702 / 057c8bcede001799b6ec4ac4546b9a268647c515`). A runtime-free documentation-source snapshot used only for exact closeout-document transfer ran as `32202383138`; its temporary caller/marker were removed by `74153aa00c194a44dfc8f8096ff95344917a281d / 0021a27c9434cba77d194dfad5549b84026eb8dc`.
- CP1 is now **4/4**, M3 **5/11**, and there is no package 5. This remains compile evidence only: M2 is still the latest accepted semantic runtime authority. Historical stable totals remain **37 events / 14 categories / 23 recurrences**, produced-witness debt **5**. Exact next is immutable `M3-CP1-TB` against source/package `9f54c77ae92161226e833cf313bf38e516aa276c / 9347879320`.

### Changed — M3 CP1 final repair package stops for process replan

- The user-authorized `M3-CP1-CB-R1` consumed CP1 package 3/3 and cumulative M3 package 4/11. Repair revision `86fa44473b05f78e76f1737e33e3a168070efa4a` fixed the reviewed hidden-friend/Eigen diagnostics, strengthened the source-derived oracle/tamper matrix, and preserved production atlas blobs `0c0dc968672c19887a9d0af2b84fe61056fac21c / 7d50b8567396e79938071dbc3473ec28482a960a`.
- Exact marker-source `5ce79f39f60186098c271b5810496d627e6504c2` ran in `32199666445 / 95910558538`. The standalone authority-kernel owner preflight stopped at `tests/FieldTransportAtlasTests.cpp:743` because the newly added `FieldCycleId` map value type was not imported or qualified. Core/pipeline linked; `preflight_exit=1`; the full target set was skipped; no result artifact exists.
- Verified log artifact `9347043139` has outer SHA-256 `20ff3e58f258f82225e9c167a35c41cf9a66fef822775fd87fbfb7fcf3a06ecc`; its sole 15,665-byte activity log has SHA-256 `2f2d0931099d5cbd817cc1aa075c37bab6253bcc8010d4cb9faa8ebb21b21953`.
- `runtimeExecution=false`: no generated binary, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input ran. This mechanics failure adds no runtime regression; stable totals remain **37 events / 14 categories / 23 recurrences**, produced-witness debt **5**.
- Cleanup passed caller-first (`cec9759fa6b07283a5be9f211630690427f7ffbb`) then marker (`c1b747e70ac89048039073832e22ad058c21f928`). Only the three durable workflows remain; trigger/observation/payload directories are absent.
- Independent guidance §6 forbids a fourth CP1 package after another mechanics failure. CP1 is **BLOCKED / NOT COMPLETE / NOT ACCEPTED** at 3/3; exact next is Review/planning-only `M3-CP1-PROCESS-REPLAN`. CP1-TB and CP2 remain blocked.

### Changed — M3 CP1 stops for replan after its second package

- The user-authorized CP0-only cadence exception remains **OMITTED / NOT EXECUTED / NOT ACCEPTED**; final M2 remains semantic runtime authority.
- CP1 package 1 implemented the frozen ten-file A1 atlas/certificate/pipeline boundary at semantic commit `4dad58a66c439c152560cb685f96a178f0902542`. Exact marker-source `cec8dfad2c4aba2330865d5664d7cb873db37a42` compiled/package green in run/job `32192286177 / 95889006356` at **123/123**, `runtimeExecution=false`. Result artifact `9344803199` has outer SHA-256 `79a99a2addc84fd0f004897c08a7e71ca1363c86008d4e3ca4349a4df136ccd8`.
- Package-1 closeout source audit found the frozen contract incomplete: its independent oracle did not cover complete cycles/singularities/admissibility/certificate tampering, explicit source/atlas digests were absent, and the full holonomy signature omitted handle-cycle lifts. The compile-green artifact is therefore not a CP1 acceptance candidate.
- CP1 package 2 revision `c2d6a76337aa2fb6be62ae57b89a202e5f4c2cd9` stayed within three existing slice files and attempted the full digest/oracle/tamper closure. Exact marker-source `d2006209c2be9d6da64afddeb5c99350f9ede0b4` failed compiling `tests/FieldTransportAtlasTests.cpp` in run/job `32194456711 / 95895504105` at step 101/123: two qualified calls could not find the hidden-friend `compose`, and an Eigen `cross()` used dynamically sized row expressions. Core and pipeline libraries linked, but no result artifact was produced.
- Package-2 log artifact `9345461584` has verified outer SHA-256 `1ada8f90d485c40e9e44e16e8d4504108eb9d7a8eda9b25c92d4a8f5d1d50e86`; its sole 20,938-byte `activity.log` has SHA-256 `06bd142dcbdf20991d43c06a6ce8a37d6162b52f2aa04d788830c93aa1d45e4e`.
- No generated Directional runtime, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed in either package. No runtime regression/candidate was observed; historical totals remain **37 events / 14 categories / 23 recurrences**, produced-witness debt **5**.
- Package-2 cleanup passed caller-first (`62323b7ad895c62142ba16ad03efc79eabbfd424`) then marker (`af93d376f50104bfde6274416fa1250364687554`). Only the three durable workflows remain, with no connector trigger, observation, or payload directory.
- CP1 has consumed its frozen **2/2** package allocation and is **BLOCKED / NOT COMPLETE / NOT ACCEPTED**. Exact next is Review/planning-only `M3-CP1-REPLAN`; CP1-TB and CP2 remain blocked.

### Changed — M3 CP0 authority census frozen and runtime-free package completed

- `M3-CP0-CB` completed without M3 semantic production/test implementation. Added `Architecture_M3_CP0_Authority_Census.md` and retained Code + Build report.
- Frozen the 457-blob predecessor inspection, 173-file review corpus, 21-file semantic count surface, current A1/A2a/A2b representation classifications, missing contracts, and exact ten-file CP1 vertical slice.
- Defined the conservative `FieldTransportAtlas` / `FieldQuadrangulabilityCertificate` boundary and independent factory-free tamper oracle. The Shen gcd condition is treated as sufficient, not necessary; boundary components require their own constructive relative witness.
- Split CP3 into CP3a combinatorial tracing and CP3b contact/event graph. `M3-CP3b-TB` now owns the explicit trace/decomposition composition proof.
- Declared a hard 11-package M3 ceiling: CP0 1; CP1/CP2/CP3a/CP3b/CP4 2 each, with no third checkpoint attempt and no package 12.
- Runtime-free compile/package authority is exact source/artifact `f51b7d7fc5b63c9efeeffabdf286a897119d75d9 / 9343406869`, run/job `32188666437 / 95878012079`. Eight approved targets completed **121/121** Ninja steps; `build_exit=0`; `compile_status=0`.
- Result/log artifacts are `9343406869 / 9343407254` with outer SHA-256 `edf7be6e739cc769758f232b4f9dafc36018de6935e91788965423be35e5c7e4 / bfbad6d15b70373fc425954ba361f57ba97aa21bef535c7d2d11cd0399310f96`.
- Package integrity passed at **25 manifest entries / 26 files**, zero symlinks, five clean status snapshots, nine dependency revisions, all six owner executables and both libraries. `runtimeExecution=false`; no generated Directional binary, test, discovery, benchmark, or custom input executed.
- Cleanup order passed: temporary workflow removed first (`e6495b881eee227c03414709a680d46fae180b1a`), trigger marker second (`0952f76fe58317b68c023050bf46f9021815cc40`). Only the three durable workflows remain.
- No runtime regression/candidate was observed; historical totals remain **37 events / 14 categories / 23 recurrences** and produced-witness debt remains **5**.
- Exact next turn is artifact-only `M3-CP0-TB` under `Architecture_M3_CP0_Code_Build_Report.md`. CP1 remains unauthorized until that census gate accepts.

### Changed — M2 closure verified and consolidated; M3 plan reviewed

- Documentation-only Review turn. No production, test, or build change.
- **M2 closure verified and upheld.** Branch head byte-identical to accepted source `9fda64e8…`; gate `32183306224 / 95861164621` at **275/275** with static **K=0** — eight products closed, direct semantic context references zero, CP3 forbidden reads zero.
- **Both prescribed CP4 remediations landed exactly.** `RemeshPipeline.cpp:11532` now uses `std::find_if` and publishes `surfaceCellFirstInvalidProducerCell` **after** `reject_merge_authority` — the ordering matters, since that helper resets diagnostics and an earlier assignment would have been silently wiped. The rail witness is stronger than specified: proven grid substrate, `incidentFaces = {-1}` retained as the mutation, and assertions pinning both the typed `InvalidFeatureEdge` kind and `failedEdgeIndex == 0`.
- **`M2_Closure_Record.md` created**, consolidating and retiring the M2 plan, the CP4 TB report, and the fixture-authority inventory. The inventory's live remainder — three latent sites, the un-removed `= {}` generator, and the ungated-file idiom — is preserved in its section 6 and carried into `TODO.md`.
- **Durable documents trimmed.** `REORIENTATION_PLAN.md` section 6 reduced to a closure pointer; milestone table now M2 complete, M3 active; the retry-budget line records M2's **actual 11 packages** rather than the nominal ceiling. `TODO.md` rewritten forward-looking around M3.
- **M3 plan independently reviewed — correctly aligned and adequately decomposed.** Verified clean on the defect that cost M2 a cycle: `FieldTransportAtlas`, `FieldQuadrangulabilityCertificate`, `FieldAlignedCurveNetwork`, and `GlobalTopologyPlan` have **zero occurrences** in `src/`, `include/`, `tests/`, so "introduce" is the correct verb.
- **Three gaps recorded for CP0 to close before CP1.** (1) The **A1 certificate construction and independent tamper oracle** is an open design-backlog item that plan sections 2 and 3 already depend on — building against an undefined certificate is the criterion-5 shape that cost M1 two corrections. (2) The **composition-validation obligation** — `DESIGN.md` warns sound ingredients do not compose into a sound composite, CP3 implements exactly that composition, and no checkpoint owns the proof. (3) **No retry budget is declared**, which section 5 requires before work starts. CP3 sizing also likely splits into two domains.
- **Cost-model caveat recorded:** M3 is new capability, not a cutover. M1/M2 re-typed existing behaviour validated against an accepted baseline throughout; M3 has no prior correct behaviour for its new parts, so the domains-per-checkpoint calibration is advisory rather than predictive and a red checkpoint is more likely a design defect than a migration defect.
- Stable totals remain **37 / 14 / 23**; produced-witness debt remains **5**. No runtime evidence claimed.

### Changed — M2 closes at 275/275 + static K=0 after CP4 R1 immutable TB

- Immutable `M2-CP4-TB-R2` `32183306224 / 95861164621` accepts exact semantic source/package `9fda64e88ddc885ce993ff8da3ad6a51765724a4 / 9340456431`. TB result/log `9341623741 / 9341624025` have SHA-256 `a3a2beb4fec4d9576c2539e166c4a268d4e723624ed3ff5b183efbf4d77f7ab1 / 75097ec6cca7c00cacb25904d6aca2c28921dc1b413b9903ae3c63f56cbc2174`.
- Required-green is **275/275 PASS**: frozen M1 **234/234** (19/138/36/41), CP1 **5/5**, CP2 **34/34**, CP4 **2/2**, exact combined selector SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`.
- Independently regenerated static M2 closure is **K=0**: eight closed products, 23 diagnostic snapshot fields, 62 lexical snapshot refs, direct semantic context refs **0**, CP3 forbidden reads **0**.
- Package/source/manifest/status/dependency/owner preflight and postflight package immutability pass. Rebuild, relink, package repair, semantic-source checkout, source/test/fixture mutation, generated discovery, and benchmark execution are all false.
- `PR8-R037 / M2-CP4-R001` is resolved by restoring the accepted failing-patch diagnostic from declared product authority; it remains in historical stable counts. `M2-CP4-TB-CAND-01` is resolved non-stable after the repaired rail witness reaches and passes the typed `InvalidFeatureEdge` rejection seam. No new regression/candidate is observed; stable totals remain **37 / 14 / 23**, produced-witness debt **5**.
- **M2 is CLOSED / ACCEPTED.** Exact next is runtime-free `M3-CP0-CB`, inventory/census + compile only, under `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md`.

### Changed — M2-CP4 R1 bounded remediation compiles green and re-proves static K=0

- After independent `M2-CP4-REPLAN`, the user explicitly authorized one additional bounded CP4 package. Exact semantic source `9fda64e88ddc885ce993ff8da3ad6a51765724a4` changes only `src/pipeline/RemeshPipeline.cpp` and `tests/SurfaceCellREPackageTests.cpp` (**7 insertions / 7 deletions**): the declared-product invalid-completed-patch guard now preserves the offending patch index diagnostic via `std::find_if`, and the CP4 rail rejection witness uses the known-good rectangular grid substrate while retaining `edge.incidentFaces = {-1}` and the strict typed `InvalidFeatureEdge` assertions. No semantic context read, product shape, compatibility alias, validator contract, or frozen assertion was weakened/restored.
- Bounded source-application control `32179683587 / 95849539548` verified exact old/new Git blobs and committed semantic source `9fda64e88ddc885ce993ff8da3ad6a51765724a4`; result/log artifacts `9340305741 / 9340306119`. `runtimeExecution=false`.
- Runtime-free compile/static run `32180027413` completed all eight approved targets at **121/121** with `build_exit=0` and **109/111 ccache hits**. Immutable result/package `9340456431` / SHA-256 `3ea977fae1467952571f7176668a3ba2e8498dcb0e43f9e1968f8012f334fb94`; persistent compile log `9340456763` / SHA-256 `6a3e69d9bd1f5487d035f574e7b8d2e4817bb1969fafaebd5635e49733bf65da`. Five source-status snapshots are clean and the 25-entry recursive self-excluding manifest verifies.
- Static closure job `95850612342` produced artifact `9340415023` / SHA-256 `0f0e18f0f961e5328cf429cd412c983b79ea75e1beaa43405fd9c4f9b6fa1168`: all **8/8** scheduled products remain closed, diagnostic product domains **23**, lexical snapshot refs **62**, direct semantic context refs **0**, CP3 forbidden reads **0**, final M2 static **K=0**. No generated test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Code + Build cannot resolve the runtime records: `PR8-R037 / M2-CP4-R001` remains open stable/recurrence and `M2-CP4-TB-CAND-01` remains open non-stable test-authority pending immutable runtime proof. Stable totals remain **37 events / 14 categories / 23 recurrences**; produced-witness debt remains **5**; latest accepted semantic runtime remains CP3-R1 at **273/273**.
- The explicitly authorized eleventh M2 package is consumed. Exact next is immutable **`M2-CP4-TB-R2`** on package `9340456431`, requiring frozen M1 **234/234** + CP1 **5/5** + CP2 **34/34** + CP4 **2/2** = **275/275** at selector SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b` plus independently regenerated static M2 **K=0**. If TB-R2 misses the full gate, stop/restructure; no twelfth package.

### Changed — M2-CP4 immutable TB passes static K=0 but rejects runtime candidate at 273/275

- Corrected immutable `M2-CP4-TB-R1` `32175491853 / 95836337325` consumed exact source/package `8cd82a63f00bd53aee3c7e01f4bef0c258b21ef3 / 9336162929` with no rebuild, relink, package repair, repository checkout for semantic source, source/test/fixture mutation, generated discovery, or benchmark execution. Result artifact `9338923657` / SHA-256 `8c25a2564b5df7df0fdeaefc3086800fc7f6af720fcb1117802c6ee2b224ff44`; persistent log `9338924194` / SHA-256 `5b46568b2e05323ec7e86ec06966390bd6b44f7387d99f540a91adde35df5b55`. Package outer digest, recursive manifest, exact source metadata, five clean source-status snapshots, and postflight immutability all passed.
- The independently regenerated static M2 closure is **K=0**: all eight scheduled stage result products are closed over typed `ProducerOutcome<Product, Failure>`; the frozen CP0 product-shaped context fields are contained in diagnostic-only `SurfaceCellDiagnosticProductSnapshots`; direct semantic context reads are zero; and the CP3 forbidden-read family remains zero.
- Runtime required-green is **273/275**: frozen M1 authority/producer/completion/validation **19/19 + 137/138 + 36/36 + 41/41 = 233/234**, accepted CP1 **5/5**, accepted CP2 **34/34**, CP4 closed-product witnesses **1/2**. The 275-name non-overlapping selector reconstructs exactly at SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`.
- Stable `PR8-R037 / M2-CP4-R001` is a recurrence of `RP-03 / POLICY_STAGE_STATE_CONFLATION`: the CP4 declared-product invalid-patch precheck correctly replaces the legacy context-shadow read but returns before canonical aggregate identity rebuild and preserves only `AggregateIdentityInvalidPatchMetadata`, dropping the accepted failing-patch index diagnostic (`surfaceCellFirstInvalidProducerCell=-1`). The correction must preserve declared-product authority and exact patch-index diagnostics; restoring context semantic authority is forbidden. Stable totals become **37 events / 14 categories / 23 recurrences**; produced-witness debt remains **5**.
- Non-stable `M2-CP4-TB-CAND-01 / RP-02` is a test-authority fixture-precondition defect: `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` throws a DCEL consistency error in its one-triangle `TriMesh::set_mesh` setup before reaching the typed rail-rejection seam, so the new witness is non-evidence rather than an accepted-green product regression. Initial control `32175260213 / 95835604030` also exposed `M2-CP4-TB-CAND-02`, a resolved orchestration-only owner-binary mapping error; authoritative R1 corrected only that mapping.
- CP4 is **NOT ACCEPTED** and M2 remains **OPEN**. Latest accepted runtime authority stays CP3-R1 `0a06127555405abef474af501e2bd09de3320c1b / 9328335558` at **273/273**. All ten currently authorized M2 Code + Build packages are consumed; exact next turn is **`M2-CP4-REPLAN` review/planning-only** to bound the two corrections and decide whether to explicitly authorize an additional remediation package.

### Changed — M2-CP4 Code + Build closes terminal products and packages the final M2 candidate

- Exact semantic source `8cd82a63f00bd53aee3c7e01f4bef0c258b21ef3` completes the CP4 write-side cutover: product-shaped `surfaceCellContext` observations are contained under the explicitly diagnostic `SurfaceCellDiagnosticProductSnapshots`; `RemeshResult` and `SurfaceCellRailBuildResult` publish typed `ProducerOutcome<Product, Failure>` outcomes; downstream/test consumers use the closed product/rejection APIs rather than restored compatibility aliases.
- The compile loop exposed only migration/build-contract defects in the CP4 change surface: the R-E CMake authority marker still named the pre-migration `context.traceNetwork` path; initial terminal wrappers used the closed-outcome symbols through the wrong namespace and one call site lacked its local `crossFieldAccepted`; stale quotient/test consumers still addressed removed open `RemeshResult` payload fields. Each was corrected surgically without weakening an assertion, restoring a semantic context read, or adding a legacy alias. Hosted-runner stalls before configure/compile were treated as infrastructure only and did not change semantic source.
- Final runtime-free compile `32167688494 / 95811322355` checked out exact source `8cd82a63f00bd53aee3c7e01f4bef0c258b21ef3`, configured cleanly, and completed the eight approved targets in **121/121** Ninja steps with `build_exit=0`; ccache recorded **109/111 hits**. Five source-status checkpoints were clean and the packaged recursive self-excluding manifest verified.
- Result/package `9336162929` / SHA-256 `67a776f290e3ab6fe6682138f3ae36184357cf27563e9c2be1e5413824ebfd38` and persistent log `9336163241` / SHA-256 `a99ea905ffc900b2f7d81959d6a3eed4ae4d13071eb52b64631055290c7a3b9e` are the immutable CP4 Code + Build evidence. `runtimeExecution=false`; no generated Directional test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- `M2-CP4-CB` is **COMPLETE / PACKAGE-COMPLETE / COMPILE-GREEN**, but it is not semantic acceptance. Latest accepted runtime authority remains CP3-R1 at **273/273** on `0a06127555405abef474af501e2bd09de3320c1b / 9328335558`. CP4 consumes the final planned package in the effective ten-package allocation; no additional remediation package is authorized. Exact next turn is immutable artifact-only **`M2-CP4-TB`** on package `9336162929`.

### Changed — M2-CP3 TB-R1 accepts declared-product read cutover at 273/273

- Immutable artifact-only `32150796184 / 95755876548` consumes exact R1 source/package `0a06127555405abef474af501e2bd09de3320c1b / 9328335558`. Result/log `9329750748 / 9329751478` have SHA-256 `a663a9f49396ed4c41c6dccba379c12d1b5f4ca09e288faf7c3ff72581754824 / 3f4a36fcfe626ee14814d989ef790478c682cfcc97795ac0f212ed837a816d98`; package outer digest, recursive manifest, exact source, clean status snapshots, owner blobs, and postflight immutability all pass.
- The three formerly red frozen counterfactual contracts pass explicit focused **3/3** and then pass again inside M1 producer **138/138**. Full required-green is frozen M1 **234/234** + CP1 **5/5** + CP2 **34/34** = **273/273 PASS** at combined selector SHA-256 `91f4b470fefffa162d15a0a216a4bbe7d9e044f5525461dd780280c9bd0f5dbb`.
- CP3 static read elimination remains green with `forbiddenRemaining=0`; 31 remaining aggregate component-context refs are diagnostic/memory or explicit shadow guards. The counterfactual seam is now the declared `SurfaceCellComponentStageProducts` consumed by aggregation; no context-to-product semantic backflow or assertion weakening is used.
- Boundary remained no rebuild/relink/package repair/source-test-fixture mutation/generated discovery/repository checkout/benchmark. `M2-CP3-TB-CAND-01` is **RESOLVED / NON-STABLE**; no regression was observed, stable totals remain **36 / 14 / 22**, produced-witness debt **5**.
- `M2-CP3` is **CLOSED / ACCEPTED**. `0a06127555405abef474af501e2bd09de3320c1b / 9328335558` is the latest accepted M2 semantic runtime authority; exact next is `M2-CP4-CB`.

### Changed — M2-CP3 R1 counterfactual-authority remediation compiles green

- After CP3 TB rejected the first candidate at **270/273**, the user explicitly authorized one bounded remediation package. Exact compiled source `0a06127555405abef474af501e2bd09de3320c1b` migrates `ComponentAggregationInputMutator` from `RemeshResult &` only to the exact declared `SurfaceCellComponentStageProducts` sidecar consumed by disconnected aggregation. All 11 existing counterfactual callbacks use the new signature; exactly the three rejected frozen contracts mutate declared stage-product authority. No production consumer reconstructs semantic products from `surfaceCellContext`, and no frozen assertion was weakened or deleted.
- Runtime-free compile `32147101079 / 95743427238` completed the seven approved targets at **117/117**, `build_exit=0`. The fixed compiler cache key restored exactly; ccache was **95/108 hits**, **13/108 misses**.
- Result/package `9328335558` / SHA-256 `8f75d835e4461ba1dabda91793a88f265e9c00de752a17ec8906943f70f9ced2` and persistent log `9328336222` / SHA-256 `687d395877d92f940cd4f1dd477846ffcc5b6a1f31d39c2546044ea32140a04b` passed exact-source, recursive manifest, source archive, five clean source-status snapshots, and command-boundary verification. `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- A doubled callback-close punctuation error introduced by the static source transform was detected and corrected before the compile/package attempt by runtime-free control `32146707321 / 95742099492`; no package was consumed by that pre-build correction.
- Compile success is not semantic acceptance. Latest accepted runtime remains CP2 at **273/273**; tracker candidate `M2-CP3-TB-CAND-01` remains open/non-stable pending immutable `M2-CP3-TB-R1`. Exact next is artifact-only package `9328335558`; CP4 remains blocked. Stable totals remain **36 / 14 / 22** and produced-witness debt remains **5**.

### Changed — M2-CP3 TB rejects candidate at 270/273 on unmigrated counterfactual authority seam

- Immutable artifact-only `32139341913 / 95718023464` consumes exact `dc837f7ac529c55aa7ba4775621e3b681f74d36b / 9322254546` with result/log `9325322211 / 9325322646` (`db12e52c5b6236c9db1e823ef93988d94b0cd0fae13b9bd961231795a6caa9bd / 2e78d926ffc24d4881064428db4d1ad7175aeff7ce30347575d404fcb77360b7`). Package/source/manifest immutability passes; rebuild/relink/package repair/source-test-fixture mutation/generated discovery/repository checkout/benchmark are all false.
- CP3 static read elimination remains green (`forbiddenRemaining=0`, 31 remaining component-context refs classified diagnostic/memory or explicit shadow guards). CP1 is **5/5**, CP2 **34/34**, and frozen M1 is **231/234**, giving **270/273** required-green.
- The three reds are `SurfaceCellAuthorityContractCutover.DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches`, `SurfaceCellAuthorityContractCutover.AggregateIdentityRebuildReportsInvalidPatchMetadataSubInvariant`, and `SurfaceCellAuthorityContractCutover.FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing`. They were green in accepted CP2. CP3 moved aggregation semantics to `ComponentRun::stageProducts`, but the frozen `ComponentAggregationInputMutator` still mutates only `RemeshResult`/legacy context after sidecar capture, so the negative injections no longer target the authority production aggregation consumes.
- Tracker candidate `M2-CP3-TB-CAND-01` classifies this as **TEST-AUTHORITY / MIGRATION-SEAM / NON-STABLE PENDING AUTHORIZED REMEDIATION**. Stable totals remain **36 / 14 / 22**; produced-witness debt remains **5**.
- CP3 is **NOT ACCEPTED** and CP4 remains blocked. A truthful counterfactual-seam remediation requires an additional Code + Build package, so execution is blocked until the user explicitly reopens the M2 package ceiling. No test weakening or context-to-stage-product semantic backflow is authorized.

### Changed — M2-CP3 semantic context-read cutover compiles green

- Exact semantic source `dc837f7ac529c55aa7ba4775621e3b681f74d36b` (`RemeshPipeline.cpp` blob `922f50a9ffaf797f469803fbf87b9ba3387eedab`) moves production semantic consumers from mutable `surfaceCellContext` state to declared local/component stage products. Context writes remain only for the CP4-owned cleanup surface; diagnostic/memory reads and explicit shadow-integrity guards remain intentionally.
- Post-transform static census `32130834052 / 95691389992` inspected the exact source, reported `forbidden_remaining=0`, and executed no generated runtime.
- Runtime-free compile `32131095060 / 95692198141` built the seven approved targets through the durable reusable compiler and completed **117/117** Ninja steps with `build_exit=0`. Fixed cache key `directional-ccache-Linux-gcc-13.3.0-release-static-pretest-v1` was an exact hit; ccache was **107/108** hits.
- Result/package `9322254546` / SHA-256 `26326fff9ae0c590a4bc7cb03990e265446217c84229d8e99515693d2259658d` and log `9322255075` / SHA-256 `49bb0eb367233b87fd67e8f373c00a9844ad0399a8848c32da18af5dc2bf124f` passed packaged source, recursive manifest, source-status, and command-boundary verification. `runtimeExecution=false`; no generated test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- `M2-CP3-CB` is complete but not semantically accepted. Exact next is immutable `M2-CP3-TB`; CP4 remains blocked. Stable regression totals remain **36 / 14 / 22** and produced-witness debt remains **5**.

### Changed — M2-CP2 TB accepts completion-stage closed products at 273/273

- Final immutable run/job `32119584283 / 95656737849` accepts exact source/package `61273efa3f2f2e6bbfb1592f40a29e3f7b7f4cef / 9316462253`. Result/log `9318077877 / 9318078273` have SHA-256 `53c30fc6265cbe53709b756111fd765611d2c8cb1f3dbecea24ffaf7759fd460 / cdcf7e6dcdd37755747db9efcda7590bfa4a452b1cd9a5c5a9cd85a08aef7c2e`.
- Required-green is **273/273 PASS**: frozen M1 **234/234** (19/138/36/41), accepted CP1 **5/5**, and CP2 **34/34** at selector SHA-256 `53f5bf57a2edb1c68260186b85964022cd034a899a51bcbf740a37d1c4815c0d`. Static closure and package immutability passed.
- Broad changed-block control `32118066037` exposed 12 candidate reds; accepted-CP1 differential `32118624560` reproduced the exact same **12/12** reds on package `9309981828`. They remain inherited/non-gating. No test or fixture was weakened or mutated.
- `M2-CP2-TB-CAND-01/02` are resolved non-stable orchestration/test-authority findings. Stable totals remain **36 / 14 / 22**; produced-witness debt remains **5**.
- Boundary remained no rebuild/relink/package repair/source-test-fixture mutation/generated discovery/benchmark. CP2 is **CLOSED / ACCEPTED**; exact next is `M2-CP3-CB`.

### Changed — M2-CP2 initial Code + Build stops on one test-helper compile omission

- CP2 semantic implementation source `440f6bb4ac662ab9d2f899206e04e2c29b97a082` closes the three planned completion-stage public results over the existing `ProducerOutcome` abstraction, cuts their consumers to typed exhaustive handling, removes the default completion-options argument, and adds the authority-carrying completion test idiom.
- Runtime-free compile run/job `32105325228 / 95613458781` configured successfully and reached **104/117**. `directional_core` and `directional_pipeline` linked; the only observed compile stop is `PatchDescriptorMilestoneETests.cpp:317`, where the new test helper calls `canonicalize_surface_cell_ownership(complex)` instead of the required `(complex, F)`. Build exit `1`; no result/package artifact was produced. Log artifact `9313019727`, SHA-256 `7f7ba3bc8018fabddab3b9ed55d5cef4c6303bcc2acc00c990dd4d528ec9f29e`.
- No generated Directional runtime, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed. This is compile-time test-helper wiring evidence, not a runtime/product regression.
- Exact correction is one test-only argument addition: `canonicalize_surface_cell_ownership(complex, F)`. No retry is executed because the active M2 plan explicitly requires the standing **8-attempt ceiling to be reopened** before any additional Code + Build retry.

### Changed — M2-CP1 TB-R3 accepts CP1 at 239/239; CP2 unblocked

- Immutable R3 source/package `65183336d092d8fe165b6ed4709c4759a0b7fe33 / 9309981828` was accepted by artifact-only run/job `32101777174 / 95603538759`. Result/log artifacts `9311843660 / 9311843967` have SHA-256 `1f7639af848e8eb8432febd54793d2f2e325a3b08b3c645766d9e08ca58aa748 / a79d9351f426b95ede367bad221352519742976a0a886277db18170451a3e182`.
- Exact frozen M1 remains **234/234 PASS** with owner partition **19/138/36/41** and selector `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687`; all five CP1 contracts pass, so the combined gate is **239/239 PASS**.
- `SharedEdgeParityRepairConforminglyCompletesTwoOddCells`, the sole TB-R2 red, now reaches and passes completion after the fixture independently constructs canonical two-face source authority and passes it via `SurfaceCellComplexCompletionOptions::sourceAuthority`. R2 preconditions and strict assertions remain intact; production `include/**` / `src/**` are unchanged from CP1 semantic source.
- Preflight/postflight verified the exact package digest, **24/24** manifest entries, **25** package files, five clean source snapshots, seven-target package, exact R3 test blob, source archive, and `package_mutated=false`. Boundary remained rebuild/relink/packageRepair/sourceMutation/testMutation/fixtureMutation/generatedDiscovery/benchmarkExecution all false.
- No regression was observed. `M2-CP1-TB-R2-CAND-01` is **RESOLVED / NON-STABLE**; stable totals remain **36 / 14 / 22**, produced-witness debt remains **5**. The standard working-branch push-marker + reusable observer path was directly successful for this turn.
- `M2-CP1` is **CLOSED / ACCEPTED**. Exact next turn is `M2-CP2-CB`: completion-stage closed products only; CP3/CP4 remain blocked.

### Changed — fixture-authority omission class scanned repo-wide before `M2-CP1-CB-R3`

- Review/inspection-only turn. No production, test, or build change.
- **Class identified:** an options-struct member carrying mandatory authority defaulted to `nullptr`, reached through an API that defaults the whole options struct — `complete_surface_cell_complex(..., const SurfaceCellComplexCompletionOptions &options = {})` at `PatchDescriptor.h:427` with `sourceAuthority = nullptr` at `:271`, rejected by the strict guard `completion_ownership_face_matches_authority` (`PureQuadCompletion.cpp:1223`). This is the **struct-member form** of the class closed at unit 1 as `R-C-CB-01b`, which closed the function-parameter form and explicitly deferred this one as "a different and weaker shape." It was not weaker; it cost two CP1 checkpoints.
- **Inventory:** 10 defaulted authority members across 6 options structs. Completion family is **8/8 authority-unset** — 1 proven live (`PatchDescriptorMilestoneETests.cpp:826`, the R3 target), **3 latent** (`:1220`, `:1260`, `:1811`, defaulted options asserting success, passing only because their complexes never reach boundary-ownership resolution, and none in the frozen 234-selector so nothing gates them), 1 benign negative (`:1244`, pinned to `IncompleteSurfaceCellComplex`).
- **Assessed and cleared:** tracing (121 raw hits), arrangement, optimizer, and validator families are not defects. `SurfaceCellTracingOptions` documents `sourceFaceComponents`/`sourceFaceSheets` as the ingress path from which `sourceAuthority` is constructed; their consumers carry no equivalent strict guard. Raw counts are a candidate set, not a defect count.
- **Structural cause recorded:** only 3 of `PatchDescriptorMilestoneE`'s contracts are in the frozen selector and none is a completion test, so that file's prevailing idiom is authority-free completion and a new gated CP1 contract inherited it. Fixing `:826` alone leaves the idiom intact.
- **Follow-ups scheduled:** a test-support helper making authority-carrying completion options the local idiom (recurrence prevention), and removal of the `= {}` default on the authority-consuming overload so omission stops compiling — a production change, scheduled for CP2/CP4, out of R3's fixture-only scope. The three latent sites are a named CP2 re-check.
- Stable totals remain **36 / 14 / 22**; produced-witness debt remains **5**. No runtime evidence claimed.

### Changed — M2-CP1 TB-R2 preserves M1, reaches completion, and isolates one final fixture-authority omission

- Artifact-only run/job `32092820628 / 95578263202` consumed exact R2 package `9308369859` from source `aba6639a122e7fd9ddb8aeb72138f1c075d01312`; result/log `9309632210 / 9309632882` have SHA-256 `a26a0b9b126f55a8308447175db54786922a08f8ccc16f7a1177ad46d9aebc5 / 727049f36d80bea97dc50778ca9f7d87d45523c50afdb084ea6f74fe2135e307`.
- Frozen M1 remains **234/234 PASS**; CP1 is **4/5**. `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` now reaches completion and performs parity repair, but `complete_surface_cell_complex` rejects with `CompletionOwnershipComponentSheetMismatch` because the fixture's default `SurfaceCellComplexCompletionOptions` does not provide required `SourceTopologyRegions` through `sourceAuthority`.
- The previously red side-fallback witness now reaches the intended rollback-like `Produced` path and passes. No frozen M1 regression or production defect was observed; the sole remaining red is a **test-fixture authority omission**. No stable regression ID/count change is justified.
- Package/source/manifest integrity passed; `package_mutated=false`; no rebuild/relink/package repair/source-test-fixture mutation/generated discovery/benchmark occurred. `M2-CP1` remains unaccepted; exact next is fixture-only `M2-CP1-CB-R3` after repository-wide audit of the same omission class.

### Changed — M2-CP1 R2 fixture-only correction compiles green

- Exact R2 source `aba6639a122e7fd9ddb8aeb72138f1c075d01312` changes only `tests/SurfaceCellREPackageTests.cpp`: the shared-edge parity fixture now supplies a canonical two-face source scope with explicit ownership, preserves boundary vertices 0..5, and exposes `sourceFaces` separately from semantic `sourceFaceScopes` in the local helper.
- Production `include/**` / `src/**` remain identical to CP1 semantic source `3be733a72330ce688013687f11cd3098ed6c849f`.
- Runtime-free compile `32091161263 / 95573431125` built all seven approved targets through `.github/workflows/agent-compile-reusable.yml`, completed **117/117** Ninja steps with `build_exit=0`, and executed no generated Directional binary/test/benchmark/discovery/CLI/GUI/fuzzer/help/version/custom input.
- Result/package `9308369859` / SHA-256 `304f6489e347f8f8ee0bb0a717b823fb477bfdfc54c2c1a84e76b1bc37a34b2e` and persistent log `9308370117` / SHA-256 `95f391908091423b05709171366286768891228fc116e647621c9b70aadac1f8b` passed recursive self-excluding manifest, source archive, exact source commit, five clean status snapshots, and command boundary.
- The trigger lifecycle used the standard two-commit working-branch pattern with reusable observer; no temporary branch was created. Compile success is not semantic acceptance; exact next is `M2-CP1-TB-R2` against package `9308369859`.

### Changed — M2-CP1 TB-R1 preserves M1, exposes two invalid/non-vacuous CP1 witnesses

- Artifact-only run/job `32075576934 / 95527922027` consumed exact corrected package `9302765681` from unchanged CP1 semantic source `3be733a72330ce688013687f11cd3098ed6c849f`.
- Frozen M1 is **234/234 PASS**; CP1 is **3/5**. `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` reproduces `MissingCellSourceScope` on the accepted M1 package as well as CP1, so the fixture is inherited-invalid for the intended completion witness; `SideRepairNonconvergencePublishesConsumableRollbackProduct` aborts on `ownership-registry-mismatch` before `repair_surface_cell_sides` reaches the fallback branch, so it is non-vacuous failure evidence rather than product failure evidence.
- No stable product regression is observed. `M2-CP1-TB-CAND-01` is resolved as a packaging/orchestration finding after corrected package availability; new candidate findings `M2-CP1-TB-CAND-02/03` are non-stable test-authority defects pending fixture-only correction.
- No rebuild/relink/package repair/source/test/fixture mutation/generated discovery/benchmark occurred. Exact next is fixture-only `M2-CP1-CB-R2`; production CP1 semantics remain frozen.

### Changed — M2-CP1 package completeness corrected without semantic source change

- `M2-CP1-TB` preflight proved initial package `9300782872` cannot execute the frozen M1 gate because `directional_surface_cell_authority_kernel_tests` is missing: exactly **19/234** identities are unrunnable. No generated Directional runtime or discovery/listing was executed; this is pre-semantic packaging evidence, not a code regression.
- `M2-CP1-CB-R1` recompiles **unchanged semantic source** `3be733a72330ce688013687f11cd3098ed6c849f` through the durable reusable compiler with the missing owner target included. Run/job `32074026365 / 95523174425` completed **117/117** Ninja steps with `build_exit=0` and `runtimeExecution=false`.
- Corrected result/package `9302765681` / SHA-256 `3d61880290415f9c2a4e6d635b00064ca15cb34b11262f65335005293e84c66f` and persistent log `9302765964` / SHA-256 `123b14ba9d711b0dc99f2d655ad4fb50c30de74288c492471e0dfacaf2f30dc3` passed recursive manifest, exact source, five clean status snapshots, seven-target inventory, and command-boundary verification. All four frozen-selector owner executables are packaged; frozen selector remains 234 / `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687`.
- Compile success is not semantic acceptance. Exact next is immutable `M2-CP1-TB-R1` consuming corrected package `9302765681`; CP2-CP4 remain blocked.

### Changed — M2-CP1 closed repair-product candidate compiles green

- Exact semantic source `3be733a72330ce688013687f11cd3098ed6c849f` generalizes the existing `ProducerOutcome` over failure type without adding a parallel wrapper, closes the three CP1 repair products (`SurfaceCellSubdivisionResult`, `SurfaceCellParityRepairResult`, `SurfaceCellSideRepairResult`), and migrates immediate consumers to typed exhaustive handling. A rollback-like side nonconvergence that remains consumable is represented as `Produced`, not recovered from text or a legacy success flag.
- Five focused CP1 contract tests were added/adjusted to prove subdivision production, parity production, side rollback production, typed rejection without payload, and unchanged phase-front semantics; no runtime was executed in the Code + Build turn.
- Final runtime-free compile `32068329967 / 95505511477` built the six approved targets in **115/115** Ninja steps with `build_exit=0`; ccache recorded **106 hits / 1 miss**. Package/log `9300782872 / 9300783399` have SHA-256 `12b5df2e4653e0f3aa2179b231ac6ebc419a2a6dfacd1b297ba536e6e746bf0e / 10414bc8eae0f4badfaadd4dba86c261af0de865403e3826b5efe4076baa405d`. Manifest verification and all source-status snapshots are clean.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed. Compile success is not semantic acceptance; exact next is immutable artifact-only `M2-CP1-TB` on `9300782872` plus frozen M1 234-selector.

### Changed — M2-CP0 TB accepts frozen census; corrects CP1 premise before implementation

- `M2-CP0-TB` consumed immutable runtime-free result/log `9297625996 / 9297626384` from exact source `79f078cd33db031269ed47d779872da24712f4e5` with no rebuild, relink, source/test/fixture mutation, generated Directional binary execution, or benchmark execution.
- Independent artifact-only reconstruction exactly matched both frozen candidate sets: stage results **33 found / 33 classified / K=8**, context mutations **290 found / 290 classified / K=62**. Deferred-blocker exposure remains none; stable totals and produced-witness debt are unchanged.
- TB found one **planning mismatch** before CP1 code: accepted `ProducerOutcome<T>` already exists but hard-codes `SurfacePhaseFrontFailure`, so CP1 must generalize that existing abstraction over failure type before using it for repair products. This is `M2-CP0-TB-CAND-01`, non-stable and resolved by updating the plan; no product regression is recorded.
- `M2-CP0-CB` and `M2-CP0-TB` are complete. Exact next is `M2-CP1-CB`; no CP2-CP4 or deferred-blocker work is authorized.

### Changed — M2-CP0 frozen census packaged; M2 implementation not yet started

- `M2-CP0-CB` inspected exact semantic source `79f078cd33db031269ed47d779872da24712f4e5` without product/runtime execution. Frozen stage-result surface is **33 found / 33 classified / K=8**, covering the eight cross-stage products allocated across CP1, CP2, and CP4. Frozen context-mutation surface is **290 found / 290 classified / K=62** semantic mutation sites across **23** top-level fields; the remaining **228** are declared product/diagnostic publications or stage-local whole-context resets. No deferred-blocker exposure was found.
- Runtime-free compile `32058370298 / 95473008362` built `directional_core`, `directional_pipeline`, four split frozen-selector owner test targets, and `directional_benchmarks` with `build_exit=0` using `.github/workflows/agent-compile-reusable.yml`. `runtimeExecution=false`; no generated Directional binary/test/benchmark/discovery/CLI/GUI/fuzzer/help/version/custom input executed.
- Immutable result/log artifacts `9297625996 / 9297626384` have SHA-256 `5c54fc3ed998a05eb06dc747783639044bfb3f38b9ac49b750bb6395bab930c22 / b0033674b8627f1739246978f5fa7c35dfbce8ceda147d3ab3d53764dc20910`; package includes exact source archive, recursive manifest, clean source-status snapshots, dependency revisions, configure/build logs, census files, and the required binaries/libraries.
- CP0 compile success is **not M2 semantic acceptance**. Exact next is artifact-only `M2-CP0-TB`, which must independently reconstruct both frozen candidate sets and reject any mismatch before CP1 begins.

### Changed — M1 closes on 234/234 required-green with K=0; M2 unblocked

- Final immutable `M1-FULL-TB` gate `32055365696 / 95464163035` consumed exact source/package `8232216a66020d440e5a6400b61904ca0430b6c1 / 9293593175` with result/log `9295592429 / 9295592776`. All four frozen selector-owner groups pass: authority **19/19**, producer **138/138**, completion **36/36**, validation **41/41**, total **234/234**.
- Static cutover proof passes **K=0** for all eight forbidden-authority domains. The final summary records acceptance criteria **1 through 6 all PASS** after the documented M1 criterion-5 architectural correction: F1/F2 require `Produced` at their actual simplification semantic stage, F3 requires producer `Produced`; later verifier-assigned `Certified` disposition is a forward M7 obligation, not an M1 state the implementation can express.
- `M1_Closure_Record.md` is the durable closure record; it includes the exact criterion mapping, artifact authority, regression/debt ledger, and the corrected non-vacuity/fixture applicability rationale. No legacy behavior was removed and no product output changed in the M1 closeout itself.
- M1 is **CLOSED**; M2 is unblocked. Exact next is `M2-CP0-CB` under `Architecture_M2_Closed_Products_Single_Writers_Code_Build_Plan.md`. Stable regression totals remain **36 / 14 / 22**; produced-witness debt remains **5**.

### Changed — M1-FULL-CB compile-green candidate packaged; immutable M1-FULL-TB is next

- Exact M1-FULL-CB candidate source `8232216a66020d440e5a6400b61904ca0430b6c1` records six retained criterion-5 fixtures as the revised application set: F1/F2 require `Produced` at the simplification semantic stage, F3 requires producer `Produced`; later verifier-assigned `Certified` disposition remains a forward M7 obligation and is not backfilled into M1.
- Runtime-free compile `32049943157 / 95447146667` completed **117/117** Ninja steps across `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, and `directional_benchmarks`; `build_exit=0`; ccache recorded **95 hits / 13 misses**.
- Result/package `9293593175` / SHA-256 `80856361002f568296423374236650645969f85beff19eff3a3faf647c9f70c8ec` and persistent log `9293593561` / SHA-256 `8bf4797f8614268e39ef18f82ea8aee89530fe9a50bd37dd030a525996903a46` passed exact source archive, recursive manifest, five clean source snapshots, dependency revisions, command boundary, and approved-target inventory. `runtimeExecution=false`; no generated Directional runtime, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version, or custom input executed.
- M1-FULL-CB is compile-complete but **not semantically accepted**. Exact next is immutable artifact-only `M1-FULL-TB` on package `9293593175`; do not start M2 before acceptance.

### Changed — M1 criterion-5 gate corrected to milestone-available semantics

- Review rechecked `REORIENTATION_PLAN.md`, `DESIGN.md`, `M1_Closure_Record.md`, the retained M1-FULL-CB report, the full 234-selector, exact source `b2ba93208f300add446884f8ef5cd30d8f1b7b3d`, and the accepted R-C package/report. The original M1 criterion 5 is **unsatisfiable by construction** in two independent ways: it requires verifier-assigned `Certified`/D0 before M7 defines any disposition product, and it requires a producer disposition for the directly-constructed F1 simplification fixture that has no producer stage.
- The M1 gate is corrected as an architecture amendment, not an implementation workaround: F1/F2 require `Produced` at the simplification semantic stage, F3 requires producer `Produced`; exact-count checks remain unchanged. The stronger verifier-assigned `Certified` requirement moves to **M7**, which is the first milestone capable of discharging it, as an explicit exit criterion and TODO obligation.
- No frozen selector identity is removed or weakened, no production/test/build/runtime source changes, and no acceptance is claimed. M1 remains open pending a fresh compile package and uninterrupted artifact-only full TB under the corrected criteria.
- Resume-critical rule added: a gate criterion applied to a fixture set must name concepts that exist for every member at that member's actual semantic stage; milestone-crossing obligations belong to the milestone that can discharge them.

### Changed — M1-FULL-TB-CAND-01 resolved as unsatisfiable gate; reopen M1-FULL-CB

- Immutable M1-FULL-TB candidate `32031854705 / 95392087424` consumed exact source/package `b2ba93208f300add446884f8ef5cd30d8f1b7b3d / 9285533569`. Result/log artifacts `9287686929 / 9287687545` have SHA-256 `7357b7aed155e2e0c4cf112deab9ab804cfe77a1bc50dfb007365dd38c8c2f70 / 303b3e6144cc07fc88431be454fdc3e7ee377af0a44f29cfbfae2d2d65ae988e`.
- Criteria 1, 2, 3, 4, and 6 pass; the full frozen selector is **234/234**, and static cutover is **K=0** across all eight domains. Criterion 5 is the only failure, and artifact-only diagnostic `32039560638 / 95416273389` proved the implementation exposes no disposition enum/product/string/token at all outside the criterion-5 script, while `REORIENTATION_PLAN.md` schedules D0-D4 disposition for M7. Therefore M1's criterion-5 demand for verifier-assigned `Certified` is unsatisfiable by construction, not a product regression.
- Tracker candidate `M1-FULL-TB-CAND-01` is **RESOLVED / GATE-DESIGN / NON-STABLE**. Stable totals remain **36 / 14 / 22**; produced-witness debt remains **5**. No test or fixture is weakened, and no implementation change is authorized until the criterion itself is corrected at the architecture level.
- M1 remains open. Exact next is `M1-FULL-CB` for an architecture/gate correction that maps M1 criterion 5 to milestone-available semantics while keeping the stronger `Certified` obligation as an explicit M7 exit criterion.

### Changed — M1-FULL-TB candidate passes 234/234 and K=0; criterion 5 blocks acceptance

- Immutable M1-FULL-TB run/job `32031854705 / 95392087424` consumed exact source/package `b2ba93208f300add446884f8ef5cd30d8f1b7b3d / 9285533569`. Result/log artifacts are `9287686929 / 9287687545`, with SHA-256 `7357b7aed155e2e0c4cf112deab9ab804cfe77a1bc50dfb007365dd38c8c2f70 / 303b3e6144cc07fc88431be454fdc3e7ee377af0a44f29cfbfae2d2d65ae988e`.
- Criteria **1/2/3/4/6 PASS** and full frozen selector is **234/234 PASS**: authority 19/19, producer 138/138, completion 36/36, validation 41/41. Static cutover is **K=0** across all eight domains.
- Criterion 5 is **FAIL / undecidable as authored**. Its F1/F2/F3 script explicitly says disposition is unavailable, infers `Produced` from runtime facts, then returns failure because it cannot prove verifier-assigned `Certified`. `DESIGN.md` requires strict fixtures to be D0, while `REORIENTATION_PLAN.md` schedules disposition D0-D4 for M7, not M1.
- No stable implementation regression is evidenced; `M1-FULL-TB-CAND-01` is a non-stable gate-design/architecture candidate pending review. Stable totals remain **36 / 14 / 22** and produced-witness debt remains **5**. M1 is not closed and M2 remains blocked.

### Changed — M1-FULL-CB closes final typed-owner partials and packages full gate

- R-A was 5/5 complete on accepted source `a7fc3a494ebf1eb6914ed5977d43a60b03a455a1`; R-B was 3/3 complete on accepted source `24f439655640b024efb886e6148fe16c759ffdac0`; R-C was 4/4 complete on accepted source `b2ba93208f300add446884f8ef5cd30d8f1b7b3d`.
- M1 final code edge migrated global output support/lineage ownership and optimization provenance off raw semantic face IDs onto typed `SourceFaceId`, cut final producer/materializer/validator consumers to typed authority, and made remaining raw face rows diagnostic/serialization leaves only.
- Final semantic source is exact commit `b2ba93208f300add446884f8ef5cd30d8f1b7b3d`. Static post-migration census found zero forbidden raw-identity semantic patterns across the M1 surface.
- Runtime-free compile run/job `32018743501 / 95353464856` completed **117/117** Ninja steps across `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, and `directional_benchmarks`; `build_exit=0`; ccache recorded **107 hits / 1 miss**.
- Result/package `9285533569` / SHA-256 `fe5b3ec999019d2f91b4f310403149577095dc7b36f067d2943fe73f1db28d43` and log `9285534196` / SHA-256 `4e0defda358b63d64266d8c3b34ebc71bec3eac965569e62b78acfeee08fc0f6` passed recursive manifest, source archive, five clean source-status snapshots, dependency revisions, command boundary, and approved target inventory.
- `runtimeExecution=false`; no generated Directional runtime/test/benchmark/discovery/CLI/GUI/fuzzer/help/version/custom input was executed. M1-FULL-CB is compile-complete but **not semantically accepted**. Exact next is immutable artifact-only `M1-FULL-TB` on package `9285533569`.

### Changed — M1 R-C Product Outcomes completes 4/4 partials; full M1-FULL-CB is next

- **P-CB-01a:** exact source `fc20f91144fa992bba4a34a4cf00c537d6bc0d76`; compile `31996034281`; result/log `9278201278 / 9278201621` (`d50ba5d5b37289c937192798b529ca96533934621406e5120abe752b61f3258fe / 23b986d886f6217beb95425031488432e8478eca396ac79fe0dac962473912d77`). Added typed phase-front `ProducerOutcome`, internal single phase-front writer, typed tracing publication and exhaustive downstream consumption.
- **P-CB-01b:** exact source `d2e857371942033d7ff7c54f458d7d759ec44c1e`; compile `32001126621`; result/log `9279757246 / 9279757611` (`15057696856799103c0acee68b3641d5aba10eae1ccd943af13c7e7e922bc715 / b7ec4a5f7f27d31db09cf1c776198ef734e9d5475970725645633fff7a1d3a03`). Removed default arguments from tracing APIs so production callers must provide explicit source authority; no legacy aliases restored.
- **P-CB-01c:** exact source `fda0bd13c0ddfca61320bcb7b63bc3b31fa7d6f9`; compile `32005669861`; result/log `9281323136 / 9281323512` (`3a0e2b999205d172623471548648876ab0602b6c425194499a05ee67bd80fb368 / 4eb625ca8e25fab99a14623f4dc234f16aa2f680648a730359f897b629d3f5a7`). Tightened frozen tracing tests so explicit authority is required and missing/tampered authority fails closed. Frozen owner slices remain compilable; no test runtime executed.
- **P-CB-01d:** exact source `b2ba93208f300add446884f8ef5cd30d8f1b7b3d`; compile `32011529523`; result/log `9283272908 / 9283273412` (`6d274841fe9cc0e7d0bc4da5e2d82351615d0a84840eaab0da416e590255888e / 9442ead72d134f18d3b25c08bd543496b11a6d3183e9378b506108a39cd2adfa`). Audited and removed the last general tracing overload that still defaulted source authority; retained only explicit `SourceTopologyRegions` entry. Final R-C static contract: one closed phase-front output, one semantic writer, no success/emptiness outcome reconstruction, no default authority ingress.
- All four partials are runtime-free Code + Build only; no generated Directional test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed. The user-authorized R-C partial edge is now complete; exact next is M1-FULL-CB, then full artifact-only M1-FULL-TB before M2 may start.

### Changed — M1 R-B Public API completes three runtime-free partials

- R-B's bounded inventory fixed the public semantic surface at **31** API symbols: **27** approved domain-preserving row/value leaves, **2** approved serialization-boundary adapters, and **2** legacy semantic entry points requiring deletion (`make_source_topology_regions(F, componentByFace, localSheetByFace)` and `build_surface_arrangement(...sourceFaceComponents/sourceFaceSheets...)`). No additional raw semantic surface is authorized.
- `P-CB-01a` removed the public raw `make_source_topology_regions` overload and migrated all production/tests/benchmarks to typed `SourceSurfaceLabels` ingestion; exact source `765112ef4d385d712c9c2b2cfe1163d0a7148389`, runtime-free compile `31974430461`, result/log `9271307315 / 9271307898` (`69a7d64155ad7132718cb142512819dc5245b649c5d4b1f2d04a51233160243f / 9b99bacf0a1b91881be0399a08239d3cf1c16ec7a773d03f9b4c5c7b07f47159`).
- `P-CB-01b` removed the public arrangement raw-label overload, introduced one canonical `build_surface_arrangement(..., const SourceTopologyRegions&, ...)` entry point, and migrated callers to typed authority; exact source `5a38492e2fa9bbe50b88d03f829cfac9c7fc59a8`, compile `31979076197`, result/log `9272759103 / 9272759567` (`f056219b4769218de129eac91f72aeb5da74a818340a2a0d90c40131076dc11d / 398ae7b0baf82b8105d5174183544548df3654923d5e429d8a538bc488043b9bd`).
- `P-CB-01c` re-audited all 31 symbols: the two legacy K entries are now deleted, all 29 approved leaves/adapters remain semantically one-way, and no new raw semantic entry point was introduced. Exact source `24f439655640b024efb886e6148fe16c759ffdac0`, compile `31983393037`, result/log `9274072410 / 9274072877` (`d5e60d6332375045bb521bb8090585683961334ced43117635df35b1e6c6a0dd / 7645ca72328286032cf74f2a14c0c03cbc87bd61b891458d7288ebdb9c8c9bc2`).
- R-B is **3/3 partials complete** and semantically unaccepted until M1-FULL-TB. All three partials built only the approved seven targets through the reusable compiler with `runtimeExecution=false`; no generated test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed. Exact successor is `M1 R-C Product Outcomes P-CB-01a`.

### Changed — M1 R-A Internal Semantics completes five runtime-free partials

- **P-CB-01a — canonical authority kernel:** introduced `include/directional/authority/AuthorityKernel.h` plus implementation, migrated source-face → region/component/sheet storage and arrangement ownership to typed authority, and added authority-kernel contract tests. Exact source `46675d180b7d8b7b67692950b4aab57ab66aa77b`; compile `31956183285`; result/log `9265640685 / 9265641021` (`54f5251e50a054ae0bc8f60db85d1a7815294aa6cddf3d06859bef7093698cbf / c1ba1d3fc87c2211a929f6d62683c5d2c990522cb16043d52e218a40c9854328`).
- **P-CB-01b — tracing/FlowRep identity families:** added typed source-entity/trace/rail/FlowRep IDs and migrated semantic identity assignment/storage while preserving explicit row projections at API/diagnostic leaves. Exact source `007d0bc3279776e464396139c40276d56234ce6b`; compile `31961310219`; result/log `9267278282 / 9267278596` (`6cbd77f63847b79018518521739038c76602b20bfbc3991a4412c25dfd9c2348 / 052029e727d449476053bc8c3b4d51614bbf08113655ae88e3408582eb96c061c`).
- **P-CB-01c — completion domain and generated lineage:** migrated completion domain identity and generated-vertex parent/source provenance to typed authority, including all completion validity and lineage consumers. Exact source `8d653208318e5e5223a49abe63ca2d96591027a4`; compile `31965670525`; result/log `9268668087 / 9268668403` (`9021b26d739f87c8b89b98e4b146e7eae3de5181523e1fef8d2c1c8720cf0573 / c3d121e36361990acc48419e808540b81591878c4a81c7127ce683376132b4fc6`).
- **P-CB-01d — transitions, quotient classes, and periodic owners:** migrated transition, quotient, periodic relation, and canonical quotient ownership to typed authority without changing physical transition algebra. Exact source `6af87c665c108847f78229653023f48023a9f9ba5`; compile `31970025102`; result/log `9269978752 / 9269979254` (`f0af3e8014032e182a9749024235da3512401097d8c899743d18d4cc0b5c67e0 / ece9c767def908206509321bba5037ac8832f75a71b73704f14735cb3ee2f9549`).
- **P-CB-01e — terminal output support/lineage:** migrated final output face support, generated output lineage, optimization provenance, and final source-authoritative validation owners to typed authority; exact source `a7fc3a494ebf1eb6914ed5977d43a60b03a455a1`; compile `31974548353`; result/log `9271346569 / 9271347000` (`e0f51249425beb37df355646303933afcde630278091c87c61045a1da9cf25462 / c34c7b306362f659b85454b95c17693349363eeea5358ff431c84cdf37af5f84`).
- All five partials were compile/package-only with `runtimeExecution=false`; no generated tests, benchmarks, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version commands, or custom input were executed. R-A is complete at the compile boundary and remains semantically unaccepted until the final M1 full TB. Exact successor is `M1 R-B Public API P-CB-01a`.

### Changed — M1 R-A Internal Semantics P-CB-01c completes typed completion-domain and lineage identities

- Exact source `8d653208318e5e5223a49abe63ca2d96591027a4` extends the M1 R-A typed-authority migration from tracing/FlowRep into the completion surface: `SurfaceCellDomainId` replaces raw completion domain indices, generated vertices carry typed `SourceFaceId` parents, and canonical surface point / `PureQuadVertexSource` source-face identity is typed. Completion ownership validation, provenance audits, and lineage propagation consume those typed identities directly.
- Runtime-free compile `31965670525 / 95202247940` built the seven approved targets through the durable reusable compiler and completed **117/117** Ninja steps with `build_exit=0`; ccache was **102/108 hits**, **6/108 misses**.
- Result/package `9268668087` / SHA-256 `9021b26d739f87c8b89b98e4b146e7eae3de5181523e1fef8d2c1c8720cf0573` and persistent log `9268668403` / SHA-256 `c3d121e36361990acc48419e808540b81591878c4a81c7127ce683376132b4fc6` passed recursive self-excluding manifest verification, five clean source-status snapshots, exact source archive, dependency revisions, configure/build logs, and command-boundary verification.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Source scope was bounded to `AuthorityKernel.h`, `SurfacePoint.h`, `FlowRepStrands.h`, `PureQuadCompletion.h/.cpp`, `PatchDescriptor.h/.cpp`, `RemeshPipeline.cpp`, `SurfaceCellProductOracle.cpp`, and directly affected frozen owner tests. No R-A-01d transition/quotient migration or R-A-01e terminal output-support migration leaked into this partial.
- This partial remains semantically unaccepted until the final M1 full TB; exact successor is M1 R-A P-CB-01d.

### Changed — M1 R-A Internal Semantics P-CB-01b completes typed tracing/FlowRep identity families

- Exact source `007d0bc3279776e464396139c40276d56234ce6b` extends the M1 R-A typed-authority kernel from source-face region identity into tracing/FlowRep semantic families: `SurfaceCellRail::id` and rail references use `HardRailId`, trace identity uses `SurfaceCellTraceId`, FlowRep arc identity uses `FlowRepArcId`, and source-entity canonical identity is a typed value rather than a raw row/index convention.
- Runtime-free compile `31961310219 / 95189093593` built the seven approved targets through `.github/workflows/agent-compile-reusable.yml` and completed **117/117** Ninja steps with `build_exit=0`; ccache was **104/108 hits**, **4/108 misses**.
- Result/package `9267278282` / SHA-256 `6cbd77f63847b79018518521739038c76602b20bfbc3991a4412c25dfd9c2348` and persistent log `9267278596` / SHA-256 `052029e727d449476053bc8c3b4d51614bbf08113655ae88e3408582eb96c061c` passed recursive self-excluding manifest verification, five clean source-status snapshots, exact source archive, dependency revisions, configure/build logs, and command-boundary verification.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Source scope was bounded to `AuthorityKernel.h`, `SurfaceCellTracing.h`, `FlowRepStrands.h`, `SurfaceArrangement.h`, `SurfaceCellTracing.cpp`, `FlowRepStrands.cpp`, `SurfaceArrangement.cpp`, `RemeshPipeline.cpp`, direct consumers, and affected frozen owner tests. No R-A-01c completion-lineage migration or later R-A work leaked into this partial.
- This partial remains semantically unaccepted until the final M1 full TB; exact successor is M1 R-A P-CB-01c.

### Changed — M1 R-A Internal Semantics P-CB-01a introduces canonical typed authority kernel

- Exact source `46675d180b7d8b7b67692950b4aab57ab66aa77b` introduces `include/directional/authority/AuthorityKernel.h` / `src/authority/AuthorityKernel.cpp`, the one typed authority kernel named by the M1 plan. `SourceFaceId`, `SourceComponentId`, `LocalSheetId`, `SourceTopologyRegionId`, `SurfaceCellDomainId`, `GeneratedLineageId`, `HardRailId`, `SurfaceCellTraceId`, `FlowRepArcId`, `SurfaceCellOccurrenceId`, `TransitionClassId`, `QuotientClassId`, `PeriodicRelationId`, and `OutputSupportId` are now explicit distinct semantic identity domains instead of interchangeable raw ints.
- `SourceTopologyRegions` now lives in the authority kernel, and source-face-to-component/sheet/region mappings store typed identities. `SurfaceArrangementCell` carries a typed domain ID; region/component/sheet compatibility and cell-source scope validation consume typed authority directly, with raw rows remaining one-way access/projection leaves only.
- Runtime-free compile `31956183285 / 95173249097` completed **117/117** Ninja steps across the seven approved targets with `build_exit=0`; ccache recorded **87 hits / 21 misses**.
- Result/package `9265640685` / SHA-256 `54f5251e50a054ae0bc8f60db85d1a7815294aa6cddf3d06859bef7093698cbf` and persistent log `9265641021` / SHA-256 `c1ba1d3fc87c2211a929f6d62683c5d2c990522cb16043d52e218a40c9854328` passed exact source archive, recursive self-excluding manifest verification, five clean source-status snapshots, dependency revisions, configure/build logs, and command-boundary verification.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- This is **partial 1/5** of M1 R-A and remains semantically unaccepted until the final M1 full TB. Exact successor is M1 R-A P-CB-01b; no Test + Benchmark may intervene on this user-authorized partial edge.

### Changed — M1 R-A Internal Semantics compile plan split into five bounded partials

- The previously planned one-turn M1 R-A Internal Semantics unit is too large for one Code + Build turn. It is now explicitly split into five sequential partial Code + Build turns: `P-CB-01a` typed authority kernel/region identity, `P-CB-01b` tracing/FlowRep identities, `P-CB-01c` completion-domain and lineage identities, `P-CB-01d` transition/quotient/periodic ownership identities, and `P-CB-01e` terminal output-support/lineage identities.
- This split is covered by the user's standing partial-CB cadence exception for the exact M1 full-authority task listed in `TODO.md`: only the declared `P-CB -> P-CB` edges may omit intervening TB, every partial remains runtime-free and semantically unaccepted, and no later M1 unit may start before all five R-A partials compile cleanly.
- Each partial owns only the named semantic family plus directly affected tests/fixtures/docs, uses the existing durable reusable compile/cache workflow, and must preserve frozen M1 authority behavior without introducing new raw semantic identity domains. Full artifact-only `M1-FULL-TB` remains the first semantic acceptance point for M1.

### Changed — M1-S4-CB compile-green candidate packaged; M1-S4-TB next

- Exact implementation source `d4af2b940bed2bf3d451f279385025b4bb33e3f83` removes legacy public array/vector authority for current cross-stage consumers, retaining only direct row/value accessors and verified container/diagnostic leaves. Completion consumers use source-row accessors into the typed `SourceTopologyRegions` object; optimizer-to-validator seam now passes independent input-derived `SourceTopologyRegions` rather than output-derived `SourceCellOwnershipRegistry`.
- Runtime-free compile run/job `31920545993 / 95066197476` completed **117/117** Ninja steps with `build_exit=0`; ccache was **107/108 hits**, **1/108 miss**.
- Result/package `9254345974` / SHA-256 `6ba220180921423712611aa857d1737879624080e6332b57612942839b901278a` and persistent log `9254346306` / SHA-256 `a0a608f3839306c90b5d0ccd5f4143f387671387564ac508060a74c341d7fd17` passed recursive self-excluding manifest verification, five clean source-status snapshots, source archive, dependency revisions, configure/build logs, and command-boundary verification.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Exact next is immutable artifact-only `M1-S4-TB` on package `9254345974`; no M1-S5 or later implementation is authorized before that gate.

### Changed — M1-S3-TB accepts stage-result boundary cutover at 273/273

- Immutable artifact-only gate `31909418131 / 95032193025` consumed exact source/package `cb7e2b48ed50c6420015ac32cad7b73227b4905a / 9250721294` and passed **273/273** required-green: frozen M1 **234/234** + CP1 **5/5** + CP2 **34/34**. Static closure remained green for CP1/CP2/CP3 domains; no rebuild/relink/package repair/source-test-fixture mutation/generated discovery/repository checkout/benchmark occurred.
- `M1-S3-TB` is **PASS / ACCEPTED**. `cb7e2b48ed50c6420015ac32cad7b73227b4905a / 9250721294` becomes the latest accepted runtime authority; exact next is `M1-S4-CB`.

### Changed — M1-S3-CB compiles typed stage-result boundary cutover

- Exact semantic source `cb7e2b48ed50c6420015ac32cad7b73227b4905a` moves stage-result authority to closed `ProducerOutcome` values at the public seam, removes boolean/emptiness reconstruction from consumers, and preserves diagnostics as non-authoritative observation only.
- Runtime-free compile `31906214457 / 95022514178` completed the approved targets with `build_exit=0`; packaged result/log authority is `9250721294 / 9250721625`.
- No generated runtime executed. Exact next is immutable `M1-S3-TB`.

### Changed — M1-S2-TB accepts typed authority migration

- Immutable artifact-only gate `31899452289 / 95001658256` consumed exact source/package `76b8304d63de40119b0859c23560932a0099d6f4 / 9248471449`, passed the frozen predecessor and focused typed-authority contracts, and confirmed static K=0 for the scheduled S2 domains.
- `M1-S2-TB` is **PASS / ACCEPTED**. Exact next is `M1-S3-CB`.

### Changed — M1-S2-CB compiles typed authority migration

- Exact semantic source `76b8304d63de40119b0859c23560932a0099d6f4` introduces the scheduled typed authority identities and migrates the bounded consumer set without changing product behavior.
- Runtime-free compile/package succeeded; no generated runtime executed. Exact next is immutable `M1-S2-TB`.

### Changed — M1-S1-TB accepts single-writer authority cutover

- Immutable artifact-only gate `31890924116 / 94975631668` consumed exact source/package `bf1104757ea1dccadcf679eaac0cb2691c525e35 / 9245682941`, passed frozen predecessor and focused S1 authority contracts, and confirmed no duplicate semantic writer remains in the bounded domain.
- `M1-S1-TB` is **PASS / ACCEPTED**. Exact next is `M1-S2-CB`.

### Changed — M1-S1-CB compiles single-writer authority cutover

- Exact semantic source `bf1104757ea1dccadcf679eaac0cb2691c525e35` cuts the first scheduled duplicated authority surface to one writer, preserves diagnostic mirrors as one-way observation, and compiles the required targets without runtime execution.
- Exact next is immutable `M1-S1-TB`.

### Changed — M1 architecture correction adopted

- `Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md` became the active implementation plan after independent architectural review found the prior milestone decomposition permitted duplicate mutable semantic authority to survive across stage boundaries.
- M1 is explicitly about one semantic authority per fact, typed identities, closed product outcomes, and eliminating mutable cross-stage context reads. Later product work remains blocked until M1 closes.

### Changed — R-C-REV-21 closure accepted

- Independent review closed the final R-C review item after verifying `ProducerOutcome` use, explicit source authority ingress, exhaustive consumer handling, and absence of newly introduced legacy semantic aliases.
- R-C review findings are retained in the independent review/report authority; exact next followed the M1 plan.

### Changed — R-C runtime package accepted

- The final R-C package passed its immutable artifact-only gate; focused contracts and frozen predecessor selectors were green, and no validation weakening was used.

### Changed — R-B closure accepted

- R-B removed the remaining scheduled public raw authority entry points and passed its immutable validation gate.

### Changed — R-A closure accepted

- R-A completed the typed authority migration across the planned internal semantic families and passed the corresponding immutable runtime gate.

### Changed — M1 reorientation plan adopted

- `REORIENTATION_PLAN.md` was updated to make single semantic authority, typed identity, closed products, and stage-local ownership prerequisites for later surface-cell production work.

### Changed — Gate 4 review incorporated

- The Gate 4 topology-region design review was incorporated into the active architecture, including source-authority requirements, quotient/periodic ownership obligations, and deferred blocker ledgers.

### Changed — regression audit normalized

- `Regression_Root_Cause_Tracker.md` and `PR_8_Regression_Audit_Inventory.md` were normalized around stable event/category/recurrence counts while retaining candidate/non-stable findings separately.

### Changed — direct surface-cell path remains fail-closed

- Direct `SurfaceCells` requests continue to fail rather than silently executing the legacy integer backend when direct production cannot establish the required invariants.

### Changed — source-grid recovery made explicit and default-off

- Source-grid recovery is default-off and cannot satisfy direct production acceptance unless a future gate explicitly authorizes it as a distinct product path.

### Changed — retained evidence and handoff policy established

- Durable project authority, cleanup/retention rules, and mandatory handoff start/end checklists were established under `.agents/Directional/`.
