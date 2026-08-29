# Architecture M3 CP4c-2 — TB-X2-R7-EXEC Artifact-Only Evidence

- Phase: `M3-CP4c-2-TB-X2-R7`
- Subturn: `M3-CP4c-2-TB-X2-R7-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Semantic/test source: `755485865a7cf9c485d754f22b82a41ee151824b`
- Immutable GMP package: `9719216316`, `sha256:acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`
- Packaged source archive: `sha256:78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`
- Runtime execution plane: local immutable-artifact preflight in the ChatGPT container; **no Directional runtime process started**
- Raw evidence archive: `Directional__M3-CP4c-2-TB-X2-R7-EXEC__raw-evidence.tar.gz`, `sha256:b83172acc3519fc6fe3472e5844a48e0bfd938fe9e6a5d68d14e515371454cc7`
- Benchmark execution: **none**

## EXEC disposition

**COMPLETE AT R7-0 / HARD ORCHESTRATION STOP BEFORE DIRECTIONAL RUNTIME / FOUR FROZEN-SELECTOR HASH TRANSCRIPTION MISMATCHES / R7-1 THROUGH R7-5 NOT RUN.**

R7 obeyed its frozen preflight rule: *any preflight mismatch is a hard orchestration stop; do not repair the
package*. The immutable package itself is internally consistent and its selector bytes are unchanged. The defect is
in the exact hash constants written into the CB5 closeout report/R7 plan, not in the package selectors.
Consequently, no accepted identity, non-gating diagnostic, 357/358 candidate, cumulative gate, or benchmark was
executed. Accepted runtime authority remains CP4c-1 **355/355**, and the latest CP4c-2 semantic runtime evidence
remains R6-EXEC's ordinal-310 red.

`selected_r2_branch=NONE`, `selected_gate=NONE`, and `gate_execution_authorized=false` remain binding.

## R7-0 immutable preflight evidence

The following checks passed before the selector-hash comparison:

- outer artifact digest exactly `acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`;
- package internal `SHA256SUMS`: **28/28 PASS**;
- `metadata/source-commit.txt`: exactly `755485865a7cf9c485d754f22b82a41ee151824b`;
- packaged source archive: exactly `78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`;
- build boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and
  `exactArithmeticBackend=GMP`;
- GMP evidence contains both `gmpxx` and `gmp` on generated link evidence;
- all six packaged runtime binaries retain executable mode `0755`;
- preflight package/source byte-and-mode inventories were captured without repair or mutation.

The exact selector comparison then produced:

| selector authority | R7 plan expected SHA-256 | immutable package/source SHA-256 | result |
|---|---|---|---|
| accepted first 316 | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` | PASS |
| accepted first 346 | `20d3b0b1b942af39b1e105e06dc122cfc7d5c90102735de292aac4924ac3e46a` | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` | **MISMATCH** |
| accepted first 353 | `51ff96d7dd69051042213673ca1876a0fcf2a192aa69eae26fd31b0b958ac6a5` | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` | **MISMATCH** |
| accepted 355 | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` | PASS |
| frozen candidate 357 | `b896d0db98bdf3ea421d98df870867077114622e24558204490d2f17464dc70` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` | **MISMATCH** |
| frozen candidate 358 | `6eda3aadbeaa4b991726a6f6e2cc080d45ca5a8ab8a18a37e3fce986b64fbe62` | `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` | **MISMATCH** |

The immutable values match the already-published exact selector authority in `ORIENTATION.md` and the successful
R6-EXEC preflight. They also arise directly from the immutable package source: 316/346/353 are the corresponding
prefixes of `Architecture_M3_CP4c1_Required_Green_Selector.txt`; 355 is that complete selector; 357/358 are their
frozen candidate files. R7 did **not** substitute those values for the plan's constants because doing so would
silently rewrite executable authority during EXEC.

## Static localization of the orchestration defect

The wrong four full digests first appear in the CB5 closeout work-preservation patch in two places: the CB5 report's
AD0 audit and the new R7 plan's preflight table. R6-REV had recorded these hashes only in abbreviated form, while
`ORIENTATION.md` and R6-EXEC retained the exact values. The closeout text therefore expanded abbreviated digests to
incorrect full strings while correctly leaving the selector files themselves untouched.

This is recorded as **`M3-CP4c2-TB-X2-R7-ORCH-01`**, an orchestration/document-authority defect, **non-stable**:
it creates no product semantic event and no recurrence. Stable accounting remains **44 / 14 / 30**; produced-witness
debt remains **5**; authoritative M3 package count remains **64**.

## Frozen downstream disposition

Because R7-0 stopped before the first Directional process:

- accepted ordinals 1-355: **NOT RUN**;
- R7-2 two-ring semantic/provenance diagnostic: **NOT RUN**;
- R7-2 torus semantic/provenance diagnostic: **NOT RUN**;
- R7-3 independent actual-embedded-graph oracle: **NOT RUN**;
- R7-4 retained barrier diagnostic: **NOT RUN**;
- R7-5 D2 prescribed-sphere localization: **NOT RUN**;
- selector 357: **HASH CHECKED / NOT RUN**;
- selector 358: **HASH CHECKED / NOT RUN**;
- cumulative CP4c-2 gate: **NOT RUN**;
- benchmarks: **NOT RUN**.

No runtime disposition is inferred for R043, R044, the two CB5 diagnostics, the independent actual-complex oracle,
the retained barrier diagnostic, or D2.

## Integrity after preflight stop

R7-6's runtime postflight trigger was never reached because runtime never started. A post-preflight integrity
comparison nevertheless re-hashed and re-statted the materialized immutable package/source and re-ran the internal
manifest. It passed:

```text
runtimeStarted=false
postPreflightIntegrityCheck=PASS
packageModesEqual=true
packageHashesEqual=true
sourceModesEqual=true
sourceHashesEqual=true
internalManifestPass=true
configureOccurred=false
compileOccurred=false
relinkOccurred=false
repairOccurred=false
generatedDiscoveryOccurred=false
mutationOccurred=false
benchmarkExecution=false
```

## Regression/accounting state at EXEC close

- `M3-CP4c2-TB-X2-R7-ORCH-01`: **ACTIVE / ORCHESTRATION / DOCUMENT-AUTHORITY / NON-STABLE**; review must
  adjudicate the correct exact hash authority and correction scope before R7 is retried.
- `PR8-R043 / M3-CP4c2-R001`: unchanged — **RESOLVED AT LOCUS / CLOSURE PENDING FULL 355**; R7 did not run
  ordinal 305.
- `PR8-R044 / M3-CP4c2-R002`: unchanged — compiled correction remains runtime-unclosed; R7 did not run ordinal 310.
- Stable accounting: **44 events / 14 categories / 30 recurrences**; debt **5**; M3 packages **64**.

## Control-plane note

The turn selected `READ_MODE=snapshot`, but one handoff file was fetched before that mandatory choice. The policy
miss was recorded immediately, further piecemeal source/document reads stopped, and exact snapshot run
`33272198347` / job `99152614314` supplied artifact `9720433080`
(`sha256:5be1d8d9818b06e49c4329e4b3f9f44790b2874e430ea1721f70a9785c12c7f8`) for subsequent inspection. The
snapshot/control incident did not execute or mutate Directional semantics or the immutable package.

## Exact next state

**`M3-CP4c-2-TB-X2-R7-REV` — independent review/planning only.** It must adjudicate
`M3-CP4c2-TB-X2-R7-ORCH-01`, resolve exact selector-hash authority from committed selector bytes plus accepted
closure/R6 evidence, and decide the minimal documentation-only correction before any R7 runtime retry. It may not
run Directional runtime, modify product/test/fixture/selector semantics, compile/package, execute 357/358 or a
cumulative gate, benchmark, touch mechanical/C2, or begin CP4c-3.
