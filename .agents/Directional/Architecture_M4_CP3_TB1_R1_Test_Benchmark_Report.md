# M4-CP3-TB1-R1 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP3-TB1-R1-EXEC`
**Status:** **COMPLETE / MEASURED GREEN / IMMUTABLE POSTFLIGHT GREEN / REVIEW PENDING / PACKAGE119 UNPROMOTED**
**Date:** 2026-09-11 UTC
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`

> **R1-REV evidence correction (2026-09-11):** the immutable result artifact is authoritative over copied closeout prose. Review re-opened the raw receipt ledger and census files and corrected three transcription classes below: ordinal390 `regionSpanMultiplicities=[1,1,1]`, ordinal394 incidence counts `3/3`, and the package/source/execution-view census-file SHA-256 values. These corrections do not change any GTest verdict, frozen-plan predicate, immutability conclusion, or process count. Package119 is promoted only by the separate `M4-CP3-TB1-R1-REV` record; this EXEC report retains its historical no-self-promotion boundary.

## 1. Frozen authority

This execution consumed the unchanged post-CB3 candidate package119 frozen by `M4-CP3-CB3`:

- semantic source: `fd532c2f768d0ff6493260deb670cb34b6757712`;
- package119 artifact: `10185370005`, `m4-cp3-cb3-package-result-34564069513`;
- package ZIP/provider SHA-256: `9fdfe9a1c8f92d52669a82da0ddfca75d58fd8dc7317d5100faff5a85c820fc8`;
- package byte size observed by the authoritative runtime: `28928367`;
- candidate selector394 SHA-256: `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- accepted selector382 prefix SHA-256: `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`;
- candidate owner partition: **30 authority-kernel / 248 producer / 75 completion / 41 validation**;
- accepted predecessor owner partition: **30 / 236 / 75 / 41**.

Package117 / selector382 **382/382** remains the latest accepted M4 runtime authority until review decides package119 disposition. Package118 remains historical unpromoted TB1 evidence at **387/394**. Package119 is runtime-proved by this EXEC turn but remains **unpromoted** because promotion/disposition belongs to `M4-CP3-TB1-R1-REV`.

No configure, compile, relink, generated discovery, package repair, permission repair, source/test/fixture/selector mutation, benchmark execution, package promotion, or production A3→A4 cutover was authorized or performed.

## 2. Orchestration provenance

Three earlier R1 attempts carry **no semantic credit** and did not mutate package119 or its source:

- run `34595005258`: GitHub Actions startup failure before semantic execution;
- run `34595297697`, execute job `103249598769`: pre-runtime artifact/source orchestration failure;
- run `34595465352`, execute job `103250130582`: pre-runtime orchestration failure while correcting source-archive discovery.

The bounded harness corrections changed orchestration only. The authoritative fourth run re-executed the complete frozen plan from immutable package119.

## 3. Authoritative execution evidence

- workflow run/job: `34595754914 / 103251084987`;
- workflow event SHA: `ab745d04b8f8c340d072eb1844d480ccbfc5849a`;
- result artifact: `10262063263` (`m4-cp3-tb1-r1-result-34595754914`), SHA-256 `736303476b9287c61534da406ec5ba788df72c95165e08dac5fdb7e91b5d4acc`;
- diagnostic-log artifact: `10262438089` (`m4-cp3-tb1-r1-log-34595754914`), SHA-256 `81bbb54cdf08bed7957c6e374f7927455099597b64d60e4e90026f4881a99be2`;
- exact runtime classification: `MEASURED_GREEN`;
- first failure: `none`;
- runtime started: `true`;
- preflight complete: `true`;
- postflight complete: `true`;
- immutable package preflight: **28/28** checksums green;
- immutable package postflight: **28/28** checksums green;
- exact fresh test-process count: **800** = 12 focused-A + 12 focused-B + 382 predecessor + 394 cumulative.

The harness reached normal completion of every planned process and immutable postflight.

## 4. Focused recovery gate — rows 383-394 twice

Both focused phases executed the same twelve identities in selector order, one fresh process per identity:

- focused-A: **12 PASS / 0 RED**;
- focused-B: **12 PASS / 0 RED**;
- ordered verdict vectors: **byte-identical**;
- zero skips, timeouts, second-test executions, or selection mismatches.

All seven corrected identities emitted exactly one success-visible receipt per focused process, and the receipt bytes were identical between focused-A and focused-B.

| Ordinal | Live receipt invariant proved |
|---:|---|
| 386 | `components=1`, `hasExterior=1`, `exteriorDemandOdd=1`, `terminalSpans=3` |
| 388 | `counts=[1,1,2]`, `minimumFlipCount=1`, `lexReceipts=3` |
| 389 | `onePreferred=1`, `oneFinal=2`, `largerPreferred=2`, `largerFinal=1` |
| 390 | `spanCount=3`, `assignmentsExamined=8`, `parityFeasibleAssignments=4`, `winningFlips=1`, `winningCounts=[1,1,2]`, `regionSpanMultiplicities=[1,1,1]` |
| 391 | `tamperRows=9` |
| 392 | `preferredCount=4`, `entryCount=4`, `forwardOrdinal=1`, `reverseOrdinal=3`, both denominators `4` |
| 394 | `topologyBoundaryIncidences=3`, `baselineIncidences=3` |

This closes the specific runtime-evidence holes identified after package118: the exterior-terminal fixture reaches its intended predicate, the lex-prefix schedule is live, both parity-flip mappings are live, the independent exhaustive oracle evaluates region-incidence multiplicity, all nine validator tamper rows execute, the reverse-breakpoint interior case is real, and production/framed structural separation reaches its runtime identity.

## 5. Accepted predecessor compatibility gate

The unchanged accepted prefix executed completely:

```text
selector382 = 382 PASS / 0 RED
owner totals = 30 / 236 / 75 / 41
```

No accepted-prefix semantic regression was measured. Package117 / selector382 **382/382** therefore remains accepted authority pending review; this EXEC turn does not itself promote package119.

## 6. Cumulative candidate gate

Selector394 executed in order, one fresh process per identity:

```text
selector394 = 394 PASS / 0 RED
accepted predecessor = 382/382
new CP3 rows = 12/12
owner totals = 30 / 248 / 75 / 41
```

No semantic RED, skip, timeout, owner-map ambiguity, or selection mismatch occurred.

## 7. Immutable postflight

The required censuses are byte-identical before and after execution:

- package census SHA-256: `3fd9e6bbfdc077933a66b9ee5942479887b58db9ba4493451aa5b4648c3ebbd0` before / same after;
- source census SHA-256: `70834cfc5482b0639f2154125c05c5cb5e430b9e98ec452d591178c65846e790` before / same after;
- execution-view census SHA-256: `97449c614ac3fb5eb67312dead3dca7474ad441ccafb8b05a17fc6ff529b48d1` before / same after.

`sha256sum -c SHA256SUMS` verifies **28/28** both before and after runtime; the byte-identical manifest file itself hashes to `9861b442670f013a9a9e8d34298cdff0630d64dfca9bdeed6f10300f59846440`. Package source, tests, fixtures, selectors, binaries, metadata, manifest, modes, sizes, and contents remained unchanged.

## 8. Benchmark plan

**Applicable:** no. No benchmark was executed. CB3 changed test authority only and the frozen R1 plan defined no performance/resource acceptance metric.

## 9. Turn boundary and exact successor

`M4-CP3-TB1-R1-EXEC` is complete because every frozen execution gate reached its organic terminal outcome and raw evidence was preserved. The measured result is **GREEN**. This turn does not adjudicate candidate promotion, stable-regression classification, production cutover, or follow-on implementation.

Stable accounting therefore remains **47 events / 14 categories / 33 recurrences** and produced-witness debt remains **5** at EXEC closeout.

**Exact next turn: `M4-CP3-TB1-R1-REV`.** It is runtime-free evidence review. It must consume immutable package119 plus result artifact `10262063263` and diagnostic-log artifact `10262438089`, independently re-derive the decisive process/receipt/selector/immutability facts, decide package119 disposition, update any regression-candidate records made obsolete by the green corrective proof, and freeze any justified successor plan. No compile, rerun, source/test mutation, package repair, package promotion, or A3→A4 cutover precedes that review.
