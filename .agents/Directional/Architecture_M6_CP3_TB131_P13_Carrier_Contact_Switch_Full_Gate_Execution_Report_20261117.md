# TB131 — carrier-contact switch full gate (2026-11-17 UTC)

## Situation

`M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-EXEC` — **MISMATCH** under [RA-252 §6](Architecture_M6_CP3_DEFN_P13_Carrier_Contact_Switch_Review_20261117.md#6-tb131-frozen--m6-cp3-tb131-p13-carrier-contact-switch-full-gate-exec). The immutable CB154 gate ran 953/953 cases: 952 PASS and one permitted premise RED. Both executions have valid postflight. Three unaffected gate logs and the Vase log differ under the literal frozen normalizations. Both new sphere/BunnyRandom terminal loci are data, not proof of closure. Independent Review is next; no successor work in TB131.

## Immutable authority and preflight

- CB154 semantic source and executor `452eb3d789016e744e99d88811add0f7e0949165`; package `14347130681`, ZIP SHA-256 `f768d7dc97fb6cf7f345f45fe6e52e681c6d7c21b6436ff3239ef44cec382489`, root manifest `c3e3504b14a94a3315ca997ae80da3d926b30ac77923a80aa29891bfaff5dc4f`, source archive `715e5f1f1fd9d06179dd5360561cee55d757cd99cf3872ebbe704ed7befdcee6`. All 28 checks, six executable modes and eight GNU Multiple Precision GMP/GMPXX target links verified; clean source, compile boundary `runtimeExecution=false`. [CB154 record](Architecture_M6_CP3_CB154_P13_Carrier_Contact_Node_Switch_Code_Build_Record_20261117.md).
- Existing harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`; frozen [gate](gates/Architecture_M6_TB128_P13_Face_Contact_Node_Full_Gate_Case_Manifest.tsv) `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962` (953), [census](gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv) `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3), [deferred](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv) `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81). Both harness self-checks pass. No repair, configuration, rebuild, relink, benchmark, source, harness, fixture, test, manifest, workflow or selector edit. No local project binary execution.
- [TB130 comparator](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb130_p13_carrier_proxy_contact_full_gate_execution_report_20261117md): CB153 source `95f082b144f2bbe145d764cbf6b3d10d123a6514`, package `14338920906`; gate `14338844806`, ZIP `d93a644f800e2c4e641fdc31051556d62f4a55541ef74009c2b86aaedf927fcc`, census `14339793522`, ZIP `c21ce302c41839542015b03bb6c18618798ed1e8dde74b40925c1693785532ca`. Both digests and all internal checks pass.
- Exact source snapshot `60fe83ec4b92789d82ef76b79df2c0ccb1accc65`, [run 44126305830](https://github.com/akashskypatel/Directional/actions/runs/44126305830), job `134191160877`, artifact `14346764128`, ZIP `a38c2b511ad585748281838e1955f2c44ad3b1f5ee0d9a5706812cd20de0acbd`, inner archive `a11dc82a3d4b5dacd970355fb9b21d5cd63a590b8d7dc3589cfa00af651a392e`, 5532/5532 checks. All 371 source/include/test files and all four frozen inputs equal the packaged source. Snapshot-to-resume comparison at `fda3eb1db11741e680fe4a43665ceb0c47e19459` confirms seven intervening commits change only STATUS, dispatcher slot, temporary marker removal and the historical TB131 continuation record. Intended report/tracker/TODO/handoff/CHANGELOG preimages are unchanged. Prior continuation commit `ca67f29bc8169ea57ff4d1b1c29a57fd70b5d105` is history, not instructions to dispatch again. Cleanup run `44127558439`, artifact `14347363910`, ZIP `dd93831dfe7c26cbc21d481c456196acde30df778272ff2ce39a27bd636e7af0`, removed only the TB131 marker at commit `5b9aff7c1e502d1db0c936161d4e4b1d1363a271`.

## Execution and evidence

| Work | Request event SHA / request SHA-256 | Run / runtime job | Mailbox key (attempt 1) |
|---|---|---|---|
| Gate | `75f05b0c6cdbcd8ace3acdd7cd3086b97057b196` / `ab3188e6b45b2cbe59a8a7cc19f071b32b353fcae99b74c20f202d362cb27576` | [44127005835](https://github.com/akashskypatel/Directional/actions/runs/44127005835) / `134193746662` | `m6-cp3-tb131-gate-v1` |
| Census | `f3847240f183da5e25c2c89a18b9046052fa1d7a` / `668c80d411500faa1fe404078ae8ca5711605fe6bb27a2a8cffcccbe610f91f0` | [44127493046](https://github.com/akashskypatel/Directional/actions/runs/44127493046) / `134203138670` | `m6-cp3-tb131-census-v1` |

Both mailbox records on `workflow-mailbox` match event, source and request digests. Validation, parse and mailbox jobs succeeded in both runs. Compile, Drive apply and noop jobs were skipped. Gate runtime job failed because the completed gate returned exit 90 (`required controls failed`); the census runtime returned 0. Gate `control_bad=1` is row 858, permitted by RA-252 §6. Do not suppress the harness failure or change a test premise in this turn. No duplicate dispatch. All six archive digests match the mailbox:

| Artifact | ID | SHA-256 |
|---|---:|---|
| Gate result | 14349985217 | `3747ea473be4ff441acc9b8808ba2b3bdeb280ff8d38963ee2f1d2a825165824` |
| Gate log | 14348103635 | `5950a15dca840e3e708ef10c195282a0b9473bc72b2ba1ac2acc8b0270db117c` |
| Gate reusable log | 14347579636 | `a0d65c64cceb0ef6ba9dbe46a6446158c55adab74c746f74737d6065938e4ebc` |
| Census result | 14349666706 | `784df0aa5d6fd5f2e3cb5ba22a2aa42d7e712460a8447f4e27e3f4e725920b00` |
| Census log | 14348344163 | `7ad8bd847f6e3f85d5b84b371b663a8d57ac4d6b5612cbc57835131359d92ad5` |
| Census reusable log | 14349771481 | `2f483f54b459ab6c23fcc6cc6cdf130c7b430be89a3244699cf36fe8466ec778` |

All 1914 gate and 9 census internal checks (1923) pass in both candidate and comparator. All 956 raw-log hash bindings in each archive pass. Each row selects exactly its declared test, owning binary and frozen identity; 956/956 candidate rows reconcile directly to the on-disk frozen manifests. Exact membership is 1034 (953 gated, 81 deferred), equal to TB130 and to the frozen manifest union. Gate: 953 executed, 952 PASS, 1 RED, `control_bad=1`, zero abnormal/missing/skipped/duplicate/unexpected_pass/later_positive_red/red_site_bad. Census: 3 executed, 1 PASS, 2 RED, no bad controls or abnormal/missing/skipped/duplicate. Both `postflight=true`, `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. Reusable logs bind both executor and semantic source to CB154, harness digest and exact event SHA. The gate's harness exit 90 is an organic result after complete execution, not orchestration failure.

## Assessment — RA-252 §6

| Frozen criterion | Observation |
|---|---|
| 934 unaffected gate rows and Cylinder/Vase equal TB130 | **FAIL**: 927 gate logs match after elapsed-time normalization, four by newline framing (175/177/191/477), three differ (174/176/179). All 934 substantive ledgers equal. Cylinder matches; Vase's substantive ledger and terminal match but raw log differs under the three explicitly listed rules. |
| No retired proxy census or H1 trace-trace terminal-cut receipt | PASS: zero across all 956 raw logs. TB130 had 34 census lines and 68 H1 receipts. This is absence in this measured execution, not a proof for unexecuted inputs. |
| 17 neutral rows PASS | PASS 17/17. |
| Premise rows 648 and 858 PASS or permitted RED | PASS: 648 PASS, sphere assertions not reached (SKIPPED branch inside test, not harness skip); 858 RED at `SurfaceCellTracingDisplayTests.cpp:155` only (`faceLocus.sourceFace.has_value()` false, expected true). The gate harness retains its bad-control indication. |
| BunnyRandom terminal data, no H1 | PASS criterion; RED production, new reason below. |
| No other changed row, RED or raw log | **FAIL**. No additional substantive ledger change; four unexpected log differences under literal frozen comparison. |

All 952 unaffected-or-neutral/PASS substantive gate records and all three census records equal their TB130 records except `log_sha256`. The sole substantive gate ledger change is row 858. Strict frozen comparator returns MISMATCH for gate and census. Preserve the exact result even if independent Review later determines that a difference is only diagnostic scheduling or parameter presentation. Do not widen the rules in this execution turn.

### Unexpected log differences (candidate findings, not adjudicated regressions)

| Row / identity | Test | Exact observation |
|---|---|---|
| Gate 174 / `selector:132` | `SurfaceCellAuthorityContractCutover.FinalMergedOracleRejectsChangedRemappedFeatureRailContent` | Six complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records, same complete-line multiset; different order. |
| Gate 176 / `selector:134` | `SurfaceCellAuthorityContractCutover.FinalMergedOracleRejectsMissingRemappedFeatureAuthority` | Six complete diagnostic records, same complete-line multiset; different order. |
| Gate 179 / `selector:137` | `SurfaceCellAuthorityContractCutover.FinalOracleRejectsMissingForeignOrUncertifiedHardRailChartAuthority` | 24 diagnostic prefixes on each side; two records are concatenated in the candidate and an empty line remains. Raw complete-line multiset differs. Separating at the diagnostic prefix yields the same 24 complete diagnostic record multisets; order differs. |
| Census 3 / `offgate:365` | `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase` | Two `GetParam() = 16-byte object` dumps differ; replacing only those parameter bytes in a forensic copy yields equality after elapsed-time normalization. The original core evidence and both RED assertions match. |

The three gate logs fail the explicitly frozen row164-only complete-line-multiset rule. The Vase difference is a strict comparison failure under RA-252's explicit list (elapsed, row164 multiset, newline framing); the TB129 independent Review also mentions parameter-object normalization for BunnyRandom. That precedent and its scope are for independent Review to adjudicate, not an extension of the frozen gate. Even if Vase is treated as equivalent, three gate rows still falsify the literal MATCH criterion. The forensic record/parameter checks are non-gating observations only; no semantic regression is established from a log-order or parameter-byte difference alone.

## Diagnostic data (not acceptance criteria)

- **Sphere row 644**: `surfaceCutGraphStatus=error`, `surfaceCutGraphError=InvalidNetworkBinding`, `errorSourceFace=none`, `originatingTopologyError=InvalidCutGraphBinding`, `originatingRotationSystemReason=none`. Previous reason was `ArcTraceTerminalCutPositionMismatch`, face 18-19-24. The source-edge barrier proxy oracle remains non-authoritative.
- **Sphere row 698**: `NotProductionReady/surface-cut-graph/InvalidNetworkBinding/origin=InvalidCutGraphBinding`, furthest stage `field-aligned-network`; no topology-plan snapshot, rotation reason `none`, trace 4, claimed edge 0-2 (incoming/outgoing matches both 1; trace present and available). Network remains 24 traces, 60 events, 12 terminal intersections. Do not infer why the new binding failure occurs from the locus alone.
- **Sphere row 648**: torus `V=72,E=76,F=4,componentCount=1,sourceChi=0,residual=0`; sphere `status=SKIPPED,reason=ordinal368-open,terminalFailureCode=NotProductionReady`. The later premise assertions did not engage. Row 858's prior face requirement now fails because no face locus is present; its source assertion is unchanged.
- **BunnyRandom**: `NotProductionReady/surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`, rotation reason `TraceEventPositionNodeConflict`, trace 82, face (21,72,273), history 0, zero accepted faces. Previously `ArcTraceTerminalCutPositionMismatch`, trace 1/event117, face (42,335,336), edge (42,336), vertex 3. New log supplies no event index/edge/vertex for the new locus. No causal repair or production acceptance claimed.
- **Cylinder**: PASS, 288 accepted quads, A3 coverage 81 scheduled / 32 covered / 0 partial / 49 unrecorded / 0 foreign; normalized log and ledger equal. **Vase**: RED, zero accepted faces; `NotProductionReady:completion`, `AggregateCompletionValidationFailure`, 189462 trace segments, 26817 arrangement cells, 67750 internal quads; no accepted output. Same terminal as TB130.

The raw archives, immutable boundary records, exact request copies, offline comparator and comparison JSON are retained in `Directional_TB131_verified_evidence.zip`. The strict script's negative controls on TB130 reject the old proxy/H1-bearing population. The new comparison checks every row and does not modify the archive or execute a project binary. The earlier comparator regex timeout was corrected before using candidate data. All substantive changes and new loci go to Review; do not treat disappearance of H1 as closure of O45 on a MISMATCH.

## Recommendation — next separate turn

After TB131 STATUS is COMPLETE, only `M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-REV` is authorized. Independently adjudicate the literal mismatch, diagnostic-only hypotheses, permitted premise RED, new sphere/BunnyRandom data and whether FC-7′ satisfies its locality argument. Do not repair tests, classify stable regressions, modify FC-6/H2, or promote CP3 in this execution turn. No stable event or debit: 66/17/49, debt 1, deferred 81; CP2 491/491 accepted, CP3/selector497/D0 unpromoted. C5/O42/O43/O45/O46 open, narrow C3/O44/C1 closed; FC-1/FC-4 producer proof and middle-piece direction witness remain open; D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`; CB145 parked.
