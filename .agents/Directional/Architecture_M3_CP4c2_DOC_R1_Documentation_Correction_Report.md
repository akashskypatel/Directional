# M3-CP4c-2 DOC-R1 Documentation Correction Report

## Status

**COMPLETE / DOCUMENTATION GREEN / RUNTIME-FREE / PACKAGE-UNCHANGED**

Authorized by `M3-CP4c-2-TB-X2-R7-REV` measures AE0–AE9 and the user's explicit request to consolidate historical
documents not relevant to the current checkpoint. No Directional runtime, configure, compile, relink, package,
product/test/fixture/selector mutation, 357/358 gate, benchmark, mechanical/C2, or CP4c-3 work occurred.

Immutable authority remains semantic/test source `755485865a7cf9c485d754f22b82a41ee151824b`, GMP package `9719216316` /
`sha256:acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`, packaged source archive
`sha256:78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`.

## AE0 — independent byte derivation

| authority | source | derivation | SHA-256 |
|---|---|---|---|
| 316 | `Architecture_M3_CP4c1_Required_Green_Selector.txt` | `head -n 316 <file> \| sha256sum` | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
| 346 | same | `head -n 346 <file> \| sha256sum` | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| 353 | same | `head -n 353 <file> \| sha256sum` | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` |
| 355 | same | whole file: `sha256sum <file>` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 | `Architecture_M3_CP4c2_Required_Green_Selector_357.txt` | whole file: `sha256sum <file>` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 358 | `Architecture_M3_CP4c2_Required_Green_Selector_358.txt` | whole file: `sha256sum <file>` | `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` |

These values were computed from selector bytes in the verified exact source snapshot, not copied from prose.

## AE1 / AE2 — correction and repository sweep

Exactly four wrong values were corrected in each of the two current-authority documents: the CB5 AD0 audit and the
R7 preflight plan. The three selector files' whole-byte SHA-256 values remained `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`,
and `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` before and after editing; the 316/346/353 prefix derivations likewise remained unchanged.

The `.agents/Directional/**` sweep audited **77** occurrences of the six authoritative selector values and the four
known fabricated variants. Before editing it found **16 fabricated-token occurrences** representing the same four
unique wrong constants: 8 current-authority occurrences were corrected; 4 explicit historical `Plan values`
occurrences remain in `Regression_Root_Cause_Tracker.md` because rewriting them would destroy the incident record;
and 4 mismatch-table occurrences disappeared only because the superseded R7-EXEC evidence file was consolidated and
retired. No fifth fabricated selector value was found.

## AE3–AE5 — durable authoring controls

`LESSONS.md` 22n already carries the required rule: a cryptographic digest is written in full or replaced by a file
reference plus `recompute`; historical abbreviated prose was not retro-edited. The authoring-format check ran over
every selector digest value and every literal introduced after `sha256:` in the corrected CB5 report and R7 plan;
all expected digest values are exactly 64 lowercase hexadecimal characters. The R7 preflight table now records source
file, derivation, and value for every selector authority.

## AE6–AE9 — current-state and sequencing preservation

`ORIENTATION.md` remains durable and its current checkpoint pointer was advanced to the DOC-R1 closeout/R7 retry;
its selector table was not changed. R7's hard-stop-on-preflight-mismatch, no-self-heal rule, and integrity evidence
are preserved. AE8 is safe for this immutable artifact-only plan because R7-2..R7-5 are non-gating, each runs in a
fresh process, shares no mutable state with the accepted-prefix processes, and grants no gate credit; their earlier
publication cannot change what R7-1 accepts or rejects. The full 355 gate and its stop/closure conditions are
unchanged. All AE9 prohibitions were respected.

## Historical consolidation

The six superseded CP4c-2 per-turn records listed in `M3_CP4c_Consolidated_Record.md` §8.3 were retired only after
their durable facts were reconciled into that record, `CHANGELOG.md`, this report, and the regression tracker. No
normative definition, selector, closure record, durable cross-cutting policy, or current build/execution authority was
removed.

## Successor

Exact next is artifact-only **`M3-CP4c-2-TB-X2-R7-EXEC` retry** on unchanged package `9719216316`, using
`Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Plan.md`. Stable accounting remains **44 / 14 / 30**, produced-
witness debt **5**, authoritative M3 packages **64**; `selected_r2_branch=NONE`, `selected_gate=NONE`,
`gate_execution_authorized=false`.
