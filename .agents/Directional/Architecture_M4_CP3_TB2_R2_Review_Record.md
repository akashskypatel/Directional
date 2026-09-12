# M4-CP3-TB2-R2 Review Record — corrected row400 and exact-path/A3 publication acceptance

**Status:** COMPLETE / APPROVED / CORRECTED R4 PACKAGE ACCEPTED / SELECTOR403 ACCEPTED / CP3 OPEN
**Turn:** `M4-CP3-TB2-R2-REV`
**Date:** 2026-09-12 UTC
**Execution mode:** runtime-free Test + Benchmark review + successor planning
**Prior accepted runtime authority:** package119 / selector394 **394/394**
**Promoted runtime authority:** corrected R4 package artifact `10289601000` / selector403 **403/403**
**Exact next:** `M4-CP3-CB5`

## 1. Review boundary and exact evidence authority

This review independently reopened the frozen TB2-R2 plan, corrected R4 package, raw TB2-R2 result/log evidence, package-owned source, current review-head source and the exact deleted execution caller. It executed no Directional binary, test, benchmark, GTest discovery/listing, configure, compile, relink or package repair and made no product/test/fixture/selector/build-source mutation.

Reviewed evidence:

```text
semantic/build source   = 58521f6d1c4fb5d625da7cde50e002cf4688beee
package artifact        = 10289601000
package provider/ZIP    = ef8c0d87f8dc8ed48269f833ec946f52189f7df63bcdf4c5df6c113f098992b9
package bytes           = 29,764,498
source archive SHA      = b8eb7a8352c587353c0aefda93243050a32f5cd123d6ce50e49a7ca9ce0912f0
manifest SHA            = d6d3c5bbad41394177cf4ef7b522cef47660e47b6865eebb98a702df506dc43b
TB2-R2 run/job          = 34666794115 / 103480225842
TB2-R2 result artifact  = 10289088800
result artifact SHA     = 2e3bfb39d10c00008479ab5c4b42b428bcdc1b92808646fae23470c4a5704d4e
TB2-R2 log artifact     = 10289438082
log artifact SHA        = ea2c9cc599e381a4ae5d63128e8dfcc33f8d476a9904aa0fcc6ded3df292058b
accepted selector394    = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
successor selector403   = c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
```

A fresh review snapshot independently froze branch source `a4227d090f93d5c28056d68a9237d3a63bca083a` in run/job `34667452675 / 103482184180`. Snapshot artifact `10289089414` has provider ZIP SHA-256 `971d54ea586cb9fa8a81f2734d403d42fd6a0ff1460f20f9b16e953147010e17`; its inner source archive hashes to `6566fab4d4e32721773b65020d4550e4ae3b65a34411063cf786f3e03ba3eede`, and **5263/5263** published file hashes verify. Comparison of review-head `src/`, `include/`, `tests/`, `benchmarks/`, `cmake/` and root `CMakeLists.txt` against package-owned source finds **387/387 files byte-identical**. Later documentation/control-plane commits therefore introduce no code/test/build drift relative to the reviewed semantic source.

## 2. Package provenance and immutable boundary are independently green

The corrected R4 package independently re-verifies:

- exact semantic source `58521f6d1c4fb5d625da7cde50e002cf4688beee`;
- `SHA256SUMS` has exactly **28** entries, manifest SHA `d6d3c5bb...`, every entry verifies, and the manifest path set exactly equals all package files excluding the self-excluded manifest;
- packaged source archive SHA `b8eb7a83...`;
- clean source-status records;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`;
- GMP/GMPXX evidence;
- four owner binaries mode `755` with exact SHA-256 values preserved by the R4 report.

The TB2-R2 postflight is also independently rechecked from raw evidence: package, extracted-source and execution-view pre/post census files compare byte-for-byte identical; both manifest passes contain **28/28 OK**; and postflight records `configure=false`, `compile=false`, `relink=false`, `generated_discovery=false`, `package_repair=false`.

## 3. Selector lineage and ownership re-derived

The package-owned selector files independently establish:

```text
selector394 rows/SHA = 394 / 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
selector403 rows/SHA = 403 / c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
selector403 first394 = byte-identical to selector394
row400               = EmbeddedGraphTopology.TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking
```

Static ownership was independently reconstructed from `cmake/DirectionalTests.cmake` and the actual `TEST*` definitions rather than copied from EXEC. All 403 identities resolve exactly once with no missing/ambiguous owner. Selector394 partitions **30 authority-kernel / 248 producer / 75 completion / 41 validation**; selector403 partitions **30 / 257 / 75 / 41**. Replacement row400 has one definition in `tests/FieldAlignedCurveNetworkTests.cpp` and is uniquely producer-owned.

## 4. Exact 799-process runtime evidence is trustworthy

`process-ledger.tsv` contains exactly **799** data rows and the result artifact contains exactly **799** raw per-process logs. Re-derived phase shape is exactly:

```text
focused-A   ordinal 400 only =   1/1 PASS
focused-B   ordinal 400 only =   1/1 PASS
selector394 ordinals 1..394  = 394/394 PASS
selector403 ordinals 1..403  = 403/403 PASS
total                         = 799/799 PASS
```

Every ledger row has exit `0`, `timeout=false`, `run_count=1`, `ok_count=1`, `skip_count=0`, `verdict=PASS`, and an exact `--gtest_filter=<identity>`. Selector-phase identity order matches the frozen selector bytes exactly and every ledger owner matches the independently reconstructed owner map. Every raw log independently contains exactly one `[ RUN ]`, the intended identity once, exactly one matching `[ OK ]`, no skip and no failure. Focused A/B raw logs are byte-identical. No blocker file exists. The terminal summary records preflight/runtime/postflight all `success` and `799 == 799` planned/observed.

The deleted caller was reopened at exact event SHA `1bfecc580c41f7ffa2bcdc4b48f9fe143e46a894`; it pins artifact/hash/size/source/manifest/GMP/binary/selector authority, starts one fresh exact-filter process per frozen row, rejects zero/multiple selection or skip/nonzero exit, and repeats immutable postflight. No hidden compile or benchmark path exists.

## 5. Row400 is now non-vacuous and mutation-discriminating

The replacement regression exercises the real authority-domain seam rather than the decorative seam rejected by the earlier TB2 review.

Package-owned source establishes:

```text
raw oriented source face row = [3,0,4]
canonical topology key       = [0,3,4]
canonical weights            = [1/6,1/3,1/2]
locus source vertex          = 4
correct raw-basis parameter  = 1/3
wrong positional parameter   = 2/3
```

`SourceFaceRecord::vertices` preserves raw row orientation. The terminal-contact branch carries barycentrics in canonical topology-key order. The corrected `vertex_trace_ray_second_point` remaps components by `SourceVertexId` into raw `SourceFaceRecord::vertices` order before `vertex_locus_secondary_parameter` indexes corners. For raw `[3,0,4]`, the canonical tuple remaps to raw `[1/3,1/6,1/2]`; locus 4 therefore gives `(1/6)/(1/3+1/6) = 1/3`. Omitting the remap and interpreting the canonical tuple positionally gives `(1/3)/(1/6+1/3) = 2/3`.

The test asserts the correct exact `1/3` and explicitly rejects `2/3`. Removing the remap therefore changes the observable outcome and makes the regression RED. The earlier `M4-CP3-TB2-REV-CAND-01` test-authority gap is closed by a real discriminator, not by weakening the assertion or inventing an upstream conversion seam.

## 6. Findings, package disposition and stable accounting

**Decision: APPROVED.** The corrected R4 package artifact `10289601000` is promoted as the current accepted M4-CP3 pre-cutover runtime authority, and `Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt` at SHA `c3f509af...70cb7` is accepted at **403/403**. Accepted predecessor selector394 remains byte-identical and runtime-green **394/394** on the promoted package.

Prior obligations:

- `M4-CP3-CB4-R2-REV-CAND-01` — **CLOSED / RECOVERY PROVED / NON-STABLE**. The canonical→raw terminal-contact coordinate-basis mismatch is corrected, compile/package-proved, and row400 plus cumulative runtime now prove the corrected path.
- `M4-CP3-TB2-REV-CAND-01` — **CLOSED / RECOVERY PROVED / NON-STABLE**. The decorative old row400 is replaced by a real mutation-discriminating consumer-seam regression and executes green twice plus cumulatively.
- `M4-CP3-CB4-R3-REV-CAND-01` — **CLOSED / RECOVERY PROVED / NON-STABLE**. R4 changed only the stale mandatory CMake identity and produced the immutable green package.
- `M4-CP3-TB1-R1-REV-OBS-01` — **CARRIED / NON-BLOCKING**. Multiplicity weighting still has only live `[1,1,1]`; next owner is the first later independently falsifiable test-authority turn before CP3 closure, not CB5 unless its cutover tests naturally create an `m=2` incidence without confounding the cutover variable.
- `M4-CP3-CB4-REV-OBS-02` — **CARRIED / NON-BLOCKING**. Row399 still lacks a direct `sourcePath`/`sourceFaces` producer-divergence tamper; next owner remains the next legitimate row399 touch.

No accepted-green behavior was lost. All three recovered candidates arose on unpromoted authority, so they add no stable event/category/recurrence. Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.

CP3 remains **OPEN**. This review accepts the exact-path publication/A3 binder and licenses the production A3→A4 cutover; it does not itself perform that cutover or prove the exact-torus A4 exit.

## 7. Successor planning — one bounded production cutover

The exact successor is `M4-CP3-CB5` under `Architecture_M4_CP3_CB5_Code_Build_Plan.md`.

The first CB5 action is a mandatory pre-mutation derivation guard. It must prove from accepted `GlobalTopologyPlan` + `GlobalConformityBaselinePlan` authority that each shared A4 hard-rail boundary segment being paired can be assigned exactly one A3 `ConformitySpanId` and exact consecutive ordinal interval, with orientation, without using floating geometry, tolerance/quantization, synthetic-node allocation order, local target/grid counts or post-hoc agreement. If that exact mapping cannot be established from current accepted products, CB5 **STOPS before semantic mutation** and returns to Review.

Only if the guard passes may CB5 wire typed accepted A3 schedule authority into A4, materialize shared breakpoints unchanged on both sides, remove floating `support_key` from shared-boundary pairing authority, retain A4-local `family`/`advanceSign`, and compile focused/cumulative coverage. Any need to alter accepted A3 counts/breakpoints, §17.12 source-path semantics, selector403 bytes, or to add local breakpoint renegotiation is a stop condition.

## 8. Review boundary conclusion

No new recurring defect pattern was discovered. This turn closes existing instances of the non-vacuity/authority-domain and stale packaged-identity patterns already captured by `LESSONS.md` 171 and 49. No new `LESSONS.md` entry is warranted.

The review performed documentation consolidation after durable facts were preserved. Superseded R2/R3/R4 plans/guards/reviews, the superseded package119 runtime report, the consumed TB2-R2 plan and the earlier TB2 review are folded into `M4_Consolidated_Record.md`; selector files remain immutable and the current TB2-R2 runtime report is retained.

## 9. Independent verification addendum (reviewing agent)

Runtime-free. The review is **upheld**: promotion of the corrected R4 package and acceptance of
selector403 at **403/403** are justified, CP3 is correctly left OPEN, and the closeout block is complete
with concrete values. Accounting stays **47 / 14 / 33**, debt **5**.

### V1 — decisive claims re-derived independently

- **Selector lineage.** All three `Selector_403` files in the tree were hashed. The promoted one is the
  CB4-R3 variant, `c3f509afc823cd73…`, and its first 394 rows hash to
  `6c27b3a0fc7259c5…` — byte-identical to accepted selector394. The superseded CB4-R1 variant
  (`e8f4fe72cfbbd458…`) shares that same prefix and correctly remains historical rather than accepted, and
  the unrelated M3-era `Selector_403` (`60ff6daa…`) is a separate milestone namespace, not a collision.
- **Process composition.** The 799-row ledger decomposes exactly as the `M4-CP3-CB4-R3-REV` successor
  contract predicted: 394 accepted-prefix ordinals + 403 cumulative ordinals + the replacement row400 run
  twice. A prediction frozen before the build and met to the process is stronger evidence than a matching
  total alone.
- **The configure blocker raised at `M4-CP3-CB4-R3-REV` §11 V4 is resolved.** At this head the retired
  identity has 0 definitions under `tests/` and 0 entries in `cmake/DirectionalTests.cmake`, while the
  replacement has exactly 1 in each. The mandatory packaged-test contract is consistent and the branch
  configures again.

### V2 — the mutation-discrimination claim is analytic, and should be labelled as such

§5 states that removing the remap "changes the observable outcome and makes the regression RED". That is
correct and this reviewer re-derived it: with canonical weights `[1/6, 1/3, 1/2]` on key `[0,3,4]` and raw
row `[3,0,4]`, the vertex-4 ray parameter is `w(v0)/(w(v3)+w(v0)) = 1/3`, and reading the canonical tuple
as raw-row ordered yields `2/3`. Both values are asserted in the identity.

The distinction worth recording: this is established by **exact arithmetic**, not by an executed mutation
trial. No run against unfixed code was performed, and none is required — the values are exact, the
identity asserts both, and running a deliberate mutation is a runtime act outside this turn's boundary.
Stating it this way keeps a later turn from citing §5 as an empirical demonstration that the unfixed code
was observed producing `2/3`. The defect itself remains source-proved; what the runtime now proves is the
corrected behaviour and the identity's ability to discriminate.

### V3 — obligations and classification

All five outstanding items carry a disposition: `CB4-R2-REV-CAND-01`, `TB2-REV-CAND-01` and
`CB4-R3-REV-CAND-01` closed as recovery-proved; `TB1-R1-REV-OBS-01` and `CB4-REV-OBS-02` carried
non-blocking with named next owners. The accounting reasoning is correct — all three recovered candidates
arose on **unpromoted** authority, so no accepted-green was lost and no stable event, category or
recurrence is added.

### V4 — forward note for `M4-CP3-CB5`

CB5 is the fourth attempt at this cutover region: CB1, CB4 and CB4-R2 each halted on a pre-mutation
derivation guard, and CB4-R3 halted at configure. Making the guard mandatory and spanning both sides of
the seam is the right response, and the plan does that.

One pattern from those four halts is worth building into the guard rather than rediscovering. Every halt
traced to one of two causes: an authority that **existed but was unpublished** (the split-cut sub-interval
loci), or a **registry that named something the turn changed** (the mandatory packaged-test identity). CB5
removes floating `support_key` shared-boundary authority, and the CB4 census counted **10** hard-rail
grouping/pairing/`support_key` consumer sites of which **7** require change. The guard should therefore
enumerate not only what A4 needs from A3, but every registry, contract list or build-level name that
refers to the symbols CB5 retires — and authorize those edits in the same turn. A plan that removes a
registered thing while forbidding the registry edit is unsatisfiable rather than merely incomplete, which
is what cost `M4-CP3-CB4-R3` its turn.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector394 `6c27b3a0...ba68`; selector403 `c3f509af...70cb7`; first394 byte-identical to selector394 |
| Decisive claims independently re-derived | 28-entry package/path manifest; source/binary provenance; 403-row ownership; 799-row ledger/raw logs; phase order; row400 exact `1/3` vs `2/3`; pre/post immutable censuses; 387/387 review-head code/test/build drift check |
| Non-vacuity checked | row400 fails under identity/no-remap because exact expected `1/3` differs from wrong positional `2/3`; focused A/B each select only that identity |
| Prior obligations discharged/carried | `CB4-R2-REV-CAND-01`, `TB2-REV-CAND-01`, `CB4-R3-REV-CAND-01` closed recovery-proved/non-stable; `TB1-R1-REV-OBS-01`, `CB4-REV-OBS-02` explicitly carried |
| Stable accounting | **47 / 14 / 33**, debt **5**; accepted authority advances to R4 artifact `10289601000` / selector403 **403/403** |
| New candidates/obligations recorded | none; tracker updated to close three candidates and carry two observations |
| ORIENTATION currency line | `M4-CP3-TB2-R2-REV`, 2026-09-12 written |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7 updated; §4 unchanged because no witness state changed; §8 existing recovery-pattern instances updated, no new pattern |
| CHANGELOG | review/promotion entry added |
| ROADMAP | CP3 moved from acceptance recovery to authorized A3→A4 cutover, still OPEN |
| Selector manifest | R3 selector403 marked accepted and TB2-R2 review receipt added |
| LESSONS | existing 49 and 171 cited; no new pattern |
| Consolidation under CLEAN_UP_POLICY | superseded CP3 R2/R3/R4 and consumed TB plans/reviews folded into `M4_Consolidated_Record.md`; selectors/current runtime report retained |
| Successor frozen | exactly `M4-CP3-CB5`; falsifiers/stop rules in `Architecture_M4_CP3_CB5_Code_Build_Plan.md` |
| Turn boundary held | runtime-free review/planning/docs only; no product/test/fixture/selector/build-source mutation |
| review_check.py boundary | **ALL CHECKS PASSED** on the verified snapshot-local working tree; no product/test/fixture/build or selector mutation; durable markers preserved |
| Pushed to origin, branch in sync | connector-mode publication/cleanup confirmation required after patch apply; final PR summary records the verified remote head |
