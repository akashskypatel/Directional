# M3-CP4c-0b CB2 Code + Build Report

Date: 2026-08-27
Turn: `M3-CP4c-0b-CB2`
Status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**

## Scope and authority

This turn implements the independent `M3-CP4c-0b-DG-REV` T0-T3 correction after the first seven-identity diagnostic gate returned 6/7. It is a Code + Build turn only. No Directional runtime, test, benchmark, discovery, CLI, fuzzer, or custom-input executable was run.

- inspection/control snapshot: `48352cb2cb88a16d4a66104eadcc9b700f3e449f`
- semantic source: `b2629040450c12507367c232f68a4d972b46450f`
- semantic paths changed: exactly three
  - `.agents/Directional/Architecture_M3_CP4c0b_Diagnostic_Gate_Selector.txt`
  - `.agents/Directional/Architecture_M3_CP4c0b_Required_Green_Selector.txt`
  - `tests/FieldAlignedCurveNetworkTests.cpp`
- production `src/` and `include/` bytes: unchanged
- stable regression accounting: **42 events / 14 categories / 28 recurrences**
- produced-witness debt: **5**

## T0 and T1 — discriminating rail-authority result

All T0 preconditions remained true before the failing identity was edited: accepted CP4c-0 remained 346/346; network nodes were still created structurally from singularities and mandatory-edge endpoints before tracing; zero-singularity/zero-trace construction had no independent node allocator; S1 still used atlas-derived rails while the pipeline witness used authoritative pipeline rails; and the pre-correction selectors were still the reviewed 7/353 sets.

T1 selected the **first row** of the independent review's binding decision table. The torus figures are:

| rail authority | mandatory edges | kinds | singularities | structural nodes | traces | events | node provenance |
| --- | ---: | --- | ---: | ---: | ---: | ---: | --- |
| `atlas-derived` | 0 | none | 0 | 0 | 0 | 0 | none |
| `pipeline-authoritative` | 48 | 48 `HardFeature` | 0 | 48 | 0 | 0 | every node is a mandatory-edge endpoint; zero contact nodes |

The same-authority production-witness construction path was audited and no second rail-authority divergence was found. The observed non-empty pipeline torus node set is therefore lawful structural state that predates tracing. No node without lawful provenance and no contact allocation with zero traces was found.

**Decision:** `M3-CP4c0b-DG-CAND-02` is **TEST-SIDE OVER-SPECIFICATION / NON-STABLE**. T2 is authorized; no S2-S6 product defect is established and stable totals do not change.

## T2 — exact identity correction

The identity had never been accepted. It was corrected in flight from a total node-count assertion to the relational no-contact contract owned by CP4c-0b.

Before:

```cpp
TEST(TraceTerminationCorrection,
     TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit) {
  const Cp4cReachabilityObservation torus =
      observe_cp4c_witness("torus", "torus");
  ASSERT_TRUE(torus.sourceAuthority.has_value()) << torus.report;
  ASSERT_TRUE(torus.atlas.has_value()) << torus.report;
  ASSERT_TRUE(torus.network.has_value()) << torus.report;
  EXPECT_TRUE(torus.network->candidate_traces().empty());
  EXPECT_TRUE(torus.network->nodes().empty());
  EXPECT_TRUE(torus.network->events().empty());
```

After:

```cpp
TEST(TraceTerminationCorrection,
     TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded) {
  const Cp4cReachabilityObservation torus =
      observe_cp4c_witness("torus", "torus");
  ASSERT_TRUE(torus.sourceAuthority.has_value()) << torus.report;
  ASSERT_TRUE(torus.atlas.has_value()) << torus.report;
  ASSERT_TRUE(torus.network.has_value()) << torus.report;
  EXPECT_EQ(Cp4cRailAuthority::PipelineAuthoritative, torus.railAuthority);
  EXPECT_TRUE(torus.network->candidate_traces().empty());
  ASSERT_FALSE(torus.network->nodes().empty());
  for (const auto &node : torus.network->nodes()) {
    const unsigned int provenance =
        cp4c_node_provenance(*torus.network, node.id);
    EXPECT_TRUE(cp4c_has_node_provenance(
        provenance, Cp4cNodeProvenance::MandatoryEdgeEndpoint));
    EXPECT_FALSE(
        cp4c_has_node_provenance(provenance, Cp4cNodeProvenance::Contact));
  }
  for (const auto &trace : torus.network->candidate_traces()) {
    EXPECT_FALSE(trace.terminalContact.has_value());
  }

  std::map<directional::geometry::FieldAlignedNetworkEventKind, std::size_t>
      eventKindHistogram;
  for (const auto &event : torus.network->events()) {
    ++eventKindHistogram[event.kind];
  }
  EXPECT_EQ(0U,
            eventKindHistogram[directional::geometry::
                                   FieldAlignedNetworkEventKind::TraceIntersection]);
  EXPECT_EQ(0U, eventKindHistogram[directional::geometry::
                                      FieldAlignedNetworkEventKind::
                                          SingularityPortJunction]);
  EXPECT_TRUE(torus.network->events().empty());
```

The fan suffix remains an excluded, non-creditable structural witness exactly as before.

## T3 — census self-description

The shared CP4c witness support now carries an explicit `Cp4cRailAuthority` tag. The S1 census reports:

- `railAuthority=atlas-derived`;
- `mandatoryEdgeCount`;
- `singularityCount`;
- existing node/contact/event figures under that named authority.

The pipeline witness reports `railAuthority=pipeline-authoritative`, and the corrected torus identity explicitly asserts that authority before consuming its node figure. A node count can no longer be imported across an unnamed rail-authority boundary.

## Re-frozen selectors

The identity rename changes selector bytes but not cardinality.

| selector | identities | SHA-256 |
| --- | ---: | --- |
| accepted CP4c-0 predecessor | 346 | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| CP4c-0b T4 diagnostic gate | 7 | `d28bbeeb74ed8e07810b06d870bdaf470bab1f294bbfe810deaa4f63276e245c` |
| CP4c-0b full required-green | 353 | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` |

The first 346 full-selector identities remain the accepted predecessor. No accepted identity was added, removed, reordered, or edited by CB2. The CP4c-1 318 selector is unchanged.

## Patch application

The complete three-file semantic patch was preserved before remote application and transported through `My Drive/Directional-CI`.

- work-preservation patch: `M3-CP4c-0b-CB2.patch`
- patch SHA-256: `c297a55afb1b04c9fb2b854b91f8aa4883c6ec8a3e33a22d5655998115713be9`
- diff-body SHA-256: `7273fa0a7034e21f0af94f1ee61e647a4753edeb3d7a6f5c573dd06c417f09f7`
- Drive apply run/job: `33126083845 / 98704498145` — **PASS**
- applied semantic commit: `b2629040450c12507367c232f68a4d972b46450f`
- apply result/log artifacts: `9668402304 / 9668402668`
- Drive service identity could not trash the staged file; owner-authorized Drive control-plane deletion completed afterward
- `runtimeExecution=false`

## Authoritative GMP compilation

Compile-only run `33126178643` built the exact semantic source `b2629040450c12507367c232f68a4d972b46450f`.

### Changed-owner precompile

- job: `98704812754` — **PASS**
- target: `directional_surface_cell_producer_tests`
- result artifact: `9668474512` / `754e6868e82e90f6258dbee32a76f1d63bbaec5f44fd11bbb81091718743538f`
- compile log artifact: `9668474965` / `83995d5a72b7d6570fdc620cf7c6f384c5f55e5a2a631c965b44c1c119926d5d`

### Eight-target package

- job: `98705144144` — **PASS**
- immutable package: `9668492827`
- package ZIP SHA-256: `e0661e66cfc12ce8945962a18b8a8f6fc8aa5a1213b3ad4d2409054573dce0b8`
- compile log artifact: `9668493344` / `f596c69c6bbdbe21d00cdbfd92d5a708480236971ba065ebc74c4d40fad5de4a`
- package manifest: **28/28 verified**
- preflight/build exit: `0 / 0`
- source-status snapshots: clean
- packaged executables: mode `0755`
- `runtimeExecution=false`
- `turnBoundary=Code+Build-only`
- `exactArithmeticBackend=GMP`
- generated link evidence contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`

Compiled targets are exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

The authoritative package increments the M3 package count to **54**. The changed-owner precompile is compile evidence, not an additional package.

## Executable successor plan — T4 then T5

### T4 — `M3-CP4c-0b-DG-T4-EXEC`

Consume immutable package `9668492827` directly. Do not rebuild, repair, mutate package/source/test/fixture/selector bytes, or perform generated discovery.

Execute only the seven identities in `Architecture_M3_CP4c0b_Diagnostic_Gate_Selector.txt`, one identity per fresh process, selector SHA-256 `d28bbeeb74ed8e07810b06d870bdaf470bab1f294bbfe810deaa4f63276e245c`.

Required T4 evidence:

- 7 identities selected exactly once;
- **7/7 PASS**;
- zero escaping C++ exceptions;
- no repository timeout;
- immutable byte-and-mode pre/postflight PASS;
- no compile/relink/repair/package/source/test/fixture/selector mutation;
- GMP runtime available for the dynamically linked binaries.

If any identity is red, stop before T5 and route the evidence to DG review. A green T4 advances only to its DG review/diagnostic adjudication boundary; it does not itself grant CP4c-0b acceptance.

### T5 — full required-green acceptance, blocked until T4 is green and reviewed

On the same immutable package and without rebuild, execute full selector `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`.

Required acceptance:

- accepted baseline: **316/316**;
- CP4c-0 predecessor: **346/346**;
- CP4c-0b full gate: **353/353**;
- exactly the two S1-review-authorized accepted re-authorings remain the only accepted expectation edits;
- zero escaping exceptions/timeouts;
- immutable pre/postflight PASS and no mutation/rebuild/repair.

Any other accepted expectation requiring an edit is a stop condition.

## Closeout

`M3-CP4c-0b-CB2` is **COMPLETE / BUILD GREEN / RUNTIME-FREE**. No runtime acceptance is claimed. `M3-CP4c0b-DG-CAND-02` is resolved non-stable/test-side with **+0 stable events / +0 recurrences**. Exact next turn is **`M3-CP4c-0b-DG-T4-EXEC`**.
