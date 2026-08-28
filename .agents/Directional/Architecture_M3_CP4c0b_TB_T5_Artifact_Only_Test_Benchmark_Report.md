# M3-CP4c-0b TB-T5 Artifact-Only Test + Benchmark Report

## Verdict

`M3-CP4c-0b-TB-T5` is **COMPLETE / GATE GREEN 353/353 / CHECKPOINT CLOSED / ACCEPTED**.

The authoritative retry consumed immutable CB3 GMP package `9671190795` from semantic/test source
`93059089881c8715a168a61968a8d6874ee1a670` artifact-only. U0, U3/U4, the ordered 353-identity gate,
and immutable postflight all passed. No configure, compile, relink, repair, generated discovery, timeout
addition, or package/source/test/fixture/required-selector mutation occurred.

This green TB closes `M3-CP4c-0b` under the project workflow. Exact successor is
**`M3-CP4c-1-CB3` under Z0-Z5**. This report does not enter that turn.

## Authority

- authoritative T5 run/job: `33136084757 / 98736295227` — **PASS**
- package artifact: `9671190795`
- package ZIP SHA-256: `2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1`
- semantic/test source: `93059089881c8715a168a61968a8d6874ee1a670`
- exact arithmetic backend: **GMP**, with GMP/GMPXX runtime present
- required-green selector: **353**, SHA-256 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
- accepted CP4c-0 prefix: **346**, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`
- accepted CP4ab prefix: **316**, SHA-256 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- non-gating selector: **4**, SHA-256 `d42240028fb2586fa96a87cc7c058aeaa34279d5fc7b80508c4aa68472e2d9ad`
- result artifact: `9672113006`, GitHub artifact digest `sha256:7f582a03a3e1cd63d988d1db249b71bfc44d68e76507c3cacbec043179c1af53`
- persistent log artifact: `9672113408`, GitHub artifact digest `sha256:91754edb40c3889111b5947aa4451875781d5b5232d060db87a6263be1aea458`

## U0 — immutable preflight

U0 is **PASS**. Package SHA-256, 28-entry internal manifest, packaged source commit, source-status snapshots,
GMP/GMPXX linkage, executable inventory/modes, full 353 selector hash, first-346 prefix hash, first-316
prefix hash, and four-identity non-gating selector all matched the frozen authority. `zeroSelected=0`.

## U3/U4 — required non-gating evidence

All four non-gating identities selected exactly once and passed with zero gate credit.

### Four-triangle fan

- reached under `railAuthority=atlas-derived`;
- **3 traces**, terminal-kind cardinality **3/3 exactly one**;
- **3 barrier-terminating**, **0 contact-terminating**;
- **8 nodes** with per-node provenance published;
- event-kind histogram published;
- mutual-termination events: **0**;
- inconclusive arrival comparisons observed: **0**;
- N1/N2/N4 guard firings: **0/0/0**.

### Two-ring

- reached under `railAuthority=atlas-derived`;
- **3 traces**, terminal-kind cardinality **3/3 exactly one**;
- **3 barrier-terminating**, **0 contact-terminating**;
- **9 nodes** with per-node provenance published;
- **3 MandatoryBarrierTermination** events;
- FirstContact pairing at identical node/face/edge: **3/3**;
- event ledger and histogram published;
- mutual-termination events: **0**;
- inconclusive arrival comparisons observed: **0**;
- N1/N2/N4 guard firings: **0/0/0**.

### Prescribed sphere and contact census

The prescribed sphere publishes `fieldAlignedCurveNetwork=true`, **24 traces**, and a terminal-event summary.
The contact-predicate census publishes all four intended witness lines. U3/U4's frozen predictions are therefore
**met** and the result records `materialNewEvidence=false`.

`M3-CP4c0b-T5-CAND-01` is consequently **RESOLVED / EVIDENCE-CAPABILITY / NON-STABLE**: CB3 supplied the
missing publishers and this T5 supplied the missing observations.

## U1/U2 — full ordered gate

The full selector ran in order, one identity per fresh process:

- accepted CP4ab prefix: **316/316 PASS**;
- accepted CP4c-0 prefix: **346/346 PASS**;
- full CP4c-0b gate: **353/353 PASS**;
- failures: **0**;
- first red ordinal: **none**;
- escaping `C++ exception with description`: **0**.

Watched ordinals all passed without re-authoring:

| Ordinal | Identity | Result |
|---:|---|---|
| 7 | `FieldAlignedCurveNetwork.DeclaresTraceIntersectionsAsTypedNetworkEvents` | PASS |
| 9 | `FieldAlignedCurveNetwork.IndependentCompositionOracleValidatesTraceEventGraph` | PASS |
| 12 | `FieldAlignedCurveNetwork.PublishesTypedFirstContactAndTerminationEvents` | PASS |
| 13 | `FieldAlignedCurveNetwork.PublishesTypedSingularityPortsAndMandatoryGraph` | PASS |

The previously identified S2-S6 accepted-authority exposure is therefore discharged. In particular ordinal 12
proves the FirstContact↔MandatoryBarrierTermination pairing contract and ordinal 13 remains green at its binding
8-node fan count.

## U5 — cost and immutable postflight

`postflight=PASS`. Package, extracted source, fixtures, selectors, and executable bytes/modes are unchanged.
The run records `configure=false`, `compile=false`, `relink=false`, `repair=false`,
`generatedDiscovery=false`, and `mutationOccurred=false`.

No repository timeout or per-identity timeout was added. The historical max passing identity was 16,397 ms;
the review's small-multiple threshold was 65,588 ms. No identity crossed that threshold. The slowest gate
identity was ordinal 137, `SurfaceCellAuthorityContractCutover.FinalOracleRejectsMissingForeignOrUncertifiedHardRailChartAuthority`,
at 16,976 ms; it passed. The slowest non-gating identity was the sphere A2a census at 3,600 ms.

## Control-plane attempts before the authoritative run

These are retained as orchestration evidence and grant no semantic credit:

1. A cleanup manifest was staged prematurely; cleanup run `33135477355` removed the then-staged temporary
   snapshot/control state before the execution payload was published. No Directional runtime was involved.
2. Schema-caller run `33135693069` failed at workflow startup because the caller did not grant the reusable
   observer sufficient permissions. It executed no Directional runtime. The caller was corrected before execution.
3. Initial execution run `33135877807` passed U0 and ran the four non-gating diagnostics, but the control parser
   expected `railAuthority=AtlasDerived` while the publisher emits `railAuthority=atlas-derived`. The 353 gate
   remained **0/353**. Immutable postflight passed. Result/log artifacts are `9672002477 / 9672002723`, digests
   `3daf013e4414e0379627b2dfc41658b4bbf8e5077cd3cf246231a88ec31fed46 /
   62fd1cd706638fc1d626068cc2294d3b7284fc079ca0c8553e6a47c7d09b852c`.
4. The normalization-only correction was SchemaStore-validated in run `33136024237` before authoritative retry
   `33136084757`.

These are **RESOLVED / ORCHESTRATION / NON-STABLE**. No package/test/product/fixture/required-selector semantic
byte changed between attempts.

## U6 — regression accounting

`M3-CP4c0b-P03-CAND-01` is **RESOLVED / PRODUCT SEMANTICS / PRE-EXISTING**: S2-S6 landed the six owned
corrections and this full accepted-authority re-proof is green. `M3-CP4c0-TB-R8-CAND-01` is also
**RESOLVED / NON-STABLE / PRODUCTION PERFORMANCE-TERMINATION** for the CP4c-0b-owned circulating-trace
condition: the prescribed sphere now publishes the required 24-trace network without N1/N2/N4 firing in the
accepted T5 authority.

No accepted-green identity regressed during T5. No evidence justifies a new stable regression event/category or
recurrence. Stable accounting therefore remains **42 events / 14 categories / 28 recurrences**, produced-witness
debt remains **5**, and M3 package count remains **55**.

## Acceptance and successor

All acceptance terms are met: green U1 353/353, accepted 316/316, CP4c-0 346/346, U3/U4 predictions met,
and U5 clean. **`M3-CP4c-0b` is CLOSED / ACCEPTED.**

The next checkpoint is `M3-CP4c-1`. Its two checkpoint-local required identities C4/C5 are not in the accepted
353, so the set union is **355 unique identities**; exact cumulative selector order/hash belongs to the successor
Code + Build and is not frozen by this TB closeout. Exact next turn is **`M3-CP4c-1-CB3` under Z0-Z5**.
