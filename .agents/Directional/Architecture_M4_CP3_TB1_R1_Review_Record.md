# M4-CP3-TB1-R1 Independent Review Record

**Phase:** `M4-CP3-TB1-R1-REV` / runtime-free Review
**Decision:** **APPROVED WITH AMENDMENTS**
**Disposition:** **PACKAGE119 PROMOTED / SELECTOR394 ACCEPTED 394/394 / CP3 REMAINS OPEN**
**Date:** 2026-09-11 UTC
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Review-entry head:** `2596c5b18ef5bba56281cbcebab9822b4055fe51`
**Validated semantic source:** `fd532c2f768d0ff6493260deb670cb34b6757712`

## 1. Review boundary and independence

This review is runtime-free. Same-agent review is user-authorized; independence is established by reopening the immutable package/result/log bytes, recomputing hashes/counts from raw files, and re-reading the exact semantic source instead of treating the EXEC report as self-proving authority. No production/test/benchmark/build logic was changed, no compile occurred, and no Directional binary was executed.

Primary evidence:

- package119 artifact `10185370005`, `m4-cp3-cb3-package-result-34564069513`, ZIP SHA-256 `9fdfe9a1c8f92d52669a82da0ddfca75d58fd8dc7317d5100faff5a85c820fc8`, semantic source `fd532c2f768d0ff6493260deb670cb34b6757712`;
- authoritative artifact-only run/job `34595754914 / 103251084987`, event SHA `ab745d04b8f8c340d072eb1844d480ccbfc5849a`;
- result artifact `10262063263`, SHA-256 `736303476b9287c61534da406ec5ba788df72c95165e08dac5fdb7e91b5d4acc`;
- diagnostic artifact `10262438089`, SHA-256 `81bbb54cdf08bed7957c6e374f7927455099597b64d60e4e90026f4881a99be2`;
- frozen execution plan `Architecture_M4_CP3_TB1_R1_Test_Benchmark_Plan.md` and production baseline definition `Architecture_M4_DEFN_Frozen_Definitions.md` §17.

The earlier attempts `34595005258`, `34595297697 / 103249598769`, and `34595465352 / 103250130582` remain orchestration-only/no-credit history. They did not mutate package119 or its source.

## 2. Mechanical evidence re-derived from raw artifacts

The package and selector authority independently re-verify:

- package manifest: **28/28**;
- selector394: **394 LF rows**, SHA-256 `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- selector382 prefix: SHA-256 `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`;
- candidate owner partition: **30 authority-kernel / 248 producer / 75 completion / 41 validation**;
- accepted-prefix owner partition: **30 / 236 / 75 / 41**;
- every selector identity has one static definition.

The raw process ledger contains exactly **800** fresh processes and no second-test execution:

| Phase | PASS | RED | timeout/skip/selection mismatch |
|---|---:|---:|---:|
| focused A, rows383-394 | 12 | 0 | 0 |
| focused B, rows383-394 | 12 | 0 | 0 |
| predecessor selector382 | 382 | 0 | 0 |
| cumulative selector394 | 394 | 0 | 0 |

Focused A/B verdict-vector bytes are identical, SHA-256 `41d3dd33f8caf7b79417957e80b4655c6b25009aa3b0843e4bd6b70011bbc4c5`. The receipt ledger contains exactly 14 rows — seven corrected ordinals in each focused phase — with byte-identical A/B receipt lines and no receipt error.

## 3. Authoritative success receipts

Raw receipt bytes prove:

| Ordinal | Re-derived live receipt |
|---:|---|
| 386 | `components=1 hasExterior=1 exteriorDemandOdd=1 terminalSpans=3` |
| 388 | `counts=[1,1,2] minimumFlipCount=1 lexReceipts=3` |
| 389 | `onePreferred=1 oneFinal=2 largerPreferred=2 largerFinal=1` |
| 390 | `spanCount=3 assignmentsExamined=8 parityFeasibleAssignments=4 winningFlips=1 winningCounts=[1,1,2] regionSpanMultiplicities=[1,1,1]` |
| 391 | `tamperRows=9` |
| 392 | `preferredCount=4 entryCount=4 forwardOrdinal=1 reverseOrdinal=3 forwardDenominator=4 reverseDenominator=4` |
| 394 | `topologyBoundaryIncidences=3 baselineIncidences=3` |

The previously committed EXEC report and formal PR closeout copied stale values for ordinal390 (`[2,2,1]`) and ordinal394 (`4/4`). The raw artifact is decisive. The report is corrected in this review. These were documentation transcription defects only: the frozen ordinal390 gate requires a nonempty live multiplicity matrix plus exhaustive/pass invariants, and ordinal394 requires the two incidence counts to be equal. The actual raw values satisfy those contracts.

## 4. Immutable postflight re-derived

The raw census files are byte-identical before/after with these file SHA-256 values:

- package census: `3fd9e6bbfdc077933a66b9ee5942479887b58db9ba4493451aa5b4648c3ebbd0`;
- source census: `70834cfc5482b0639f2154125c05c5cb5e430b9e98ec452d591178c65846e790`;
- execution-view census: `97449c614ac3fb5eb67312dead3dca7474ad441ccafb8b05a17fc6ff529b48d1`;
- manifest file pre/post: `9861b442670f013a9a9e8d34298cdff0630d64dfca9bdeed6f10300f59846440`, with **28/28** checksum verification both times.

The prior EXEC report copied different census hashes. Those narrative values are superseded by the raw-file hashes above. The command-boundary evidence still proves artifact-only execution: no configure, compile, relink, generated discovery, package/permission repair, semantic-input mutation, benchmark, package promotion, or A3→A4 cutover.

## 5. Test-authority recovery review

Exact-source inspection confirms the seven corrected receipts occur only after the intended assertions/calls have executed. In particular:

- ordinal386 reaches the component-local exterior/terminal predicate on the valid three-face disk;
- ordinal388 reaches the live minimum-cardinality/lex-prefix result;
- ordinal389 independently finds and asserts both `1 -> 2` and `2 -> 1` mappings;
- ordinal390 runs all `2^3 = 8` assignments, finds four parity-feasible assignments, and compares the winning live schedule;
- ordinal391 executes all nine validator-tamper rows before its receipt;
- ordinal392 independently establishes preferred count four, then consumes forward/reverse interior ordinals `1/3` with denominator four;
- ordinal394 reaches the structural separation identity and compares live topology/baseline incidence counts.

No product algorithm was modified by CB3. The green R1 gate therefore recovery-proves the exact evidence holes created by the package118 test-authority defects without weakening DCEL, parity, validator, breakpoint, or structural-separation contracts.

## 6. Regression-candidate disposition

`M4-CP3-TB1-REV-CAND-01` and `M4-CP3-TB1-REV-CAND-02` are **CLOSED / RECOVERY PROVED / NON-STABLE**. The frozen CB3 corrections are present in the exact semantic source and R1 supplies the missing non-vacuous runtime evidence.

No accepted behavior was lost, and the candidates were test-authority defects on unaccepted package118. Stable accounting therefore remains **47 events / 14 categories / 33 recurrences**. Produced-witness debt remains **5**.

## 7. Package119 disposition

Package119 is promoted as the accepted runtime authority for the §17 production-baseline A3 semantic proof surface:

- accepted package authority: **117 -> 119**;
- accepted M4 required-green selector: **382 -> 394**;
- accepted runtime result: **394/394** with predecessor **382/382** preserved;
- package118 remains historical unpromoted evidence at **387/394**.

This does **not** rewrite historical framed CP1/CP2 closures. It replaces their superseded production-sufficiency role with accepted §17 family/sign-free parity-baseline evidence. It also does **not** close M4-CP3: production still does not construct/pass the accepted A3 plan into A4.

## 8. Static production-cutover finding

Source review identifies the next missing authority handoff rather than a defect in package119's accepted baseline solver:

1. `RemeshPipeline.cpp` constructs A2a, A2a′ and `GlobalTopologyPlan`, records that A2b product, then calls `build_surface_cell_network(...)` without constructing or passing a `GlobalConformityBaselinePlan`.
2. `SurfaceCellTracingOptions` carries source, field-transport and A2a network authority, but no A2b/A3 plan authority.
3. A4 regional work is still keyed by `SourceTopologyRegions` / `TopologyRegionId`, while the accepted baseline contract is defined over A2b `GlobalTopologyPlan` regions and `NetworkRegionId`. The cutover must establish an explicit verified mapping or rebase the regional work domain; it may not silently substitute the older source-topology partition.
4. A4 producers still select local `gridU/gridV` or strip subdivisions from target size. Local interior resolution may remain A4-owned only after shared A3 boundary breakpoints are fixed; it may not choose shared seam subdivision.
5. hard-rail pairing still groups chart copies by a floating/tolerance `support_key` (`1e-9`, `1e12`) plus route metadata and rejects on `InvalidHardRailPairing`. Frozen §17.11 assigns the shared-boundary conjuncts to A3 exact breakpoint authority; A4-local `family` / `advanceSign` remain separate local field-frame checks and are not removed merely because A3 is family/sign-free.

The smallest sufficient next change is therefore a production A3→A4 authority cutover, not another baseline-solver or test-authority repair.

## 9. Decision

**APPROVED WITH AMENDMENTS.** The raw R1 execution is upheld and package119/selector394 is promoted. The amendments correct stale copied receipt/census values in durable documentation and narrow the successor to the actual missing production authority handoff.

No additional runtime is required before implementation. No production cutover is performed in this review.

## 10. Exact successor

**Exact next: `M4-CP3-CB4` — canonical Code + Build / runtime-free — under `Architecture_M4_CP3_CB4_Code_Build_Plan.md`.**

CB4 must production-wire one validated immutable §17 baseline plan between A2b and A4, make exact span/breakpoint identity the shared-boundary owner, retire floating `support_key` as semantic hard-rail pairing authority, preserve A4-local field family/sign checks, add focused production-cutover contracts, and compile/package only. Runtime acceptance remains a later artifact-only TB against the exact CB4 package.

## 11. Integrity confirmation

- production source changed in Review: **no**
- test/benchmark/build logic changed in Review: **no**
- Directional compile/runtime executed in Review: **no**
- raw package/result/log evidence independently re-opened: **yes**
- EXEC narrative transcription corrected: **yes**
- package119 promoted by Review: **yes**
- CP3 closed: **no**
- production A3→A4 cutover performed: **no**

---

## 12. Independent verification addendum (reviewing agent)

Runtime-free. The decision is **upheld**: package119 promoted, selector394 accepted at 394/394,
CP3 correctly left OPEN. Authorities re-derived here rather than read — selector394 hashes to
`6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`, unchanged from what the CB3 plan
pinned, and its first 382 rows remain accepted selector382 `1d59b1f7…`. Accounting stays
**47 / 14 / 33**, debt **5**.

### V1 — the unproven-surface ledger from `M4-CP3-TB1-REV` §11 is discharged

All seven previously blocked identities now execute and publish receipts placed after their intended
assertions. The independent oracle (390), the validator tamper matrix (391) and the lex-prefix
scheduler (388) — the three §17.7 non-vacuity instruments — now have runtime evidence, as does the
production/framed separation guarantee (394). The ledger is closed.

Ordinal390's receipt is not merely present; it is internally consistent under independent
re-derivation. With `regionSpanMultiplicities=[1,1,1]` and preferred counts all 1, each unflipped
span contributes an odd count and each flipped span an even one, so feasibility requires an odd flip
count: `C(3,1) + C(3,3) = 4`, exactly the reported `parityFeasibleAssignments=4` out of
`assignmentsExamined=8 = 2³`. Minimum odd flip count is 1, and among the three one-flip solutions
`[1,1,2]` is lexicographically least — exactly `winningFlips=1 winningCounts=[1,1,2]`. The identity
demonstrably computed the right thing rather than merely reaching its end.

### V2 — the §10 V4 oracle requirement was implemented, and the risk it guarded did not fire

CB3 took the preferred generalization: `exhaustive_terminal_parity_oracle` now takes the topology and
span ids, builds `regionSpanMultiplicities[region][span]` from the actual region boundary walks, and
tests `Σ_s (m_{r,s} · x_s) mod 2 == 0` for **every** region rather than one global XOR. That is a
faithful model of §17.5, and same-region double incidences vanish automatically through even `m`.

Stated plainly: the conditional risk did **not** materialize. The receipt shows `spanCount=3` and
`regionSpanMultiplicities=[1,1,1]`, so the fan triangulation's interior edges did not become spans and
the original single-XOR oracle would have remained valid here. The hardening still paid for itself,
but for the secondary reason given when it was raised — the multiplicity model the oracle applied is
now published and auditable from the log instead of being an unstated assumption, and the identity no
longer silently depends on a fixture property nobody checks.

### V3 — carried obligation: the multiplicity weighting is currently inert

Applying the standard this project applied to `CAND-04`, to a change this reviewer asked for. With
every multiplicity equal to 1, replacing `(multiplicities[span] * counts[span]) & 1` with
`counts[span] & 1` would change no test outcome. The generalization is structurally present and
behaviourally unexercised.

Ordinal385 does not close this. It calls `minimum_t_join_cardinality` directly on a synthetic
`ParityGraphProblem` whose single edge is the self-loop `{0,0,0}`
(`tests/GlobalConformityBaselineTests.cpp:359-376`), proving the **T-join solver** treats a self-loop
as zero-effect. Nothing exercises the end-to-end path — a same-region double **boundary incidence**
producing `m_s = 2`, the production binder's region parity correctly ignoring it, and the independent
oracle agreeing.

**Obligation, non-blocking.** This does not affect package119's promotion: 394/394 is real, and §17.5's
self-loop rule has genuine partial coverage at the solver level. Discharge it in the next turn that
touches test source — **explicitly not `M4-CP3-CB4`**, whose evidential value depends on being a
production-wiring turn and nothing else. The discharge is one identity appended to the selector: a
fixture carrying a same-region double incidence, run through both the production binder and the
independent oracle, asserting agreement and emitting a `regionSpanMultiplicities` receipt containing a
`2`. If no such fixture is constructible from current A2b authority, report that instead — it would
mean same-region double incidence is not production-reachable in available fixtures, which is itself
worth recording against §17.5.

### V4 — §8's cutover finding corroborates frozen §17.11

§8 item 5 independently reports that hard-rail pairing still groups chart copies by a
floating/tolerance `support_key` (`1e-9`, `1e12`) plus route metadata before rejecting on
`InvalidHardRailPairing`. That is exactly the A3-owned half of the pairing predicate identified in
§17.11, reached by a separate source reading. It confirms the division recorded there: CB4's job on
that gate is to replace floating `support_key` agreement with exact span/breakpoint identity, while
A4's own `family`/`advanceSign` conjuncts stay A4-derived and untouched.
