# M3-CP4c-2-TB-X2-R6 Artifact-Only Test + Benchmark Plan

## Scope and authority

This plan is for **`M3-CP4c-2-TB-X2-R6-EXEC`** only. It consumes the immutable CB4 package, executes raw
artifact-only evidence gathering, performs unconditional postflight, updates the regression tracker for every
observed runtime regression/candidate, and then **stops at independent `M3-CP4c-2-TB-X2-R6-REV`**.

Immutable authority:

- source `cebc12082c6dbe4830095df08169797b7dab0c5c`
- prepackage run/job `33250503297 / 99095246849`
- full compile run/job `33250547011 / 99095357374`
- package `9714226920` / `sha256:931d422611a8144faf4efe3f9307b3a1a90bbce4cab6d8873eb95b32ca1b9f83`
- compile log `9714227128` / `sha256:95c8272db296dc0f74e4d33b389cbf51305bd042590420974111d9f63afe31da`
- source archive `3bb299730077cd7bbd46acd5e10f6f7fec1d0e131bc882710a5676163e36b021`
- exact arithmetic GMP/GMPXX
- CB metadata `runtimeExecution=false`
- M3 package count entering R6 **63**

No benchmark is authorized. `benchmarkExecution=false`.

## Frozen selectors

Preflight must recompute and require:

- 316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- 346 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`
- 353 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
- 355 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- 357 `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
- 358 `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`

357/358 are verification-only. `selected_r2_branch=NONE`, `selected_gate=NONE`,
`gate_execution_authorized=false`.

## R5-ORCH-01 correction

Postflight must execute even when semantic runtime returns nonzero. Do not permit top-level `set -e` to bypass
finalization. Equivalent required shape:

```bash
semantic_rc=0
run_authorized_semantic_sequence || semantic_rc=$?
run_immutable_postflight
postflight_rc=$?
preserve_all_evidence
if [ "$postflight_rc" -ne 0 ]; then exit "$postflight_rc"; fi
exit "$semantic_rc"
```

Semantic red never waives immutable postflight.

## R6-0 — immutable preflight

Before any Directional binary:

1. verify outer package digest and all internal `SHA256SUMS`;
2. require package source commit = exact source;
3. require `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`;
4. require both gmpxx and gmp in authoritative link evidence;
5. verify all eight packaged targets and executable modes;
6. verify/materialize the packaged source archive only; no repository checkout;
7. capture package/source byte-and-mode inventories;
8. recompute all six selector hashes.

Mismatch is orchestration/evidence stop. Do not repair/rebuild.

## R6-1 — accepted-prefix re-proof first

Execute every selected accepted identity in a **fresh process**, preserving stdout, stderr, exit code, and duration.
Do not select any identity twice.

Ordered proof:

1. first 316 → 316/316 PASS
2. suffix through 346 → cumulative 346/346 PASS
3. suffix through 353 → cumulative 353/353 PASS
4. suffix through 355 → cumulative 355/355 PASS

Hard stop on first accepted red: preserve first red, skip R6-2/3/4 and 357/358/cumulative gate, still execute
R6-5, update regression tracking, and hand off to R6-REV.

Ordinal 305 `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` receives no harness special case.

## R6-2 — independent actual-embedded-graph oracle

Only after 355/355 PASS, run exactly one fresh process selecting:

`ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating`

It is non-gating and gets zero accepted credit.

For `synthetic-two-ring`, `torus`, and `prescribed-sphere`, preserve:

- `complex=actualEmbeddedGraph`
- `oracleKind=independent-face-planar-rotation-seam-orbit`
- V/E, total orbits, excluded exterior/boundary orbits, counted F
- graph components `c`, source components `s`, source chi, corrected identity
- per-source-face fragment/orbit evidence
- cut provenance/admissibility class
- producer terms, independent-oracle terms, term-by-term comparison

The oracle must not define its result by calling shared `EmbeddedGraphTopology` or `SurfaceCutGraph`.

**Two-ring:** actual representation must derive, not encode, `V=9, E=11, F=3, chi=1`. Proxy `10/11/2`
certification or witness-specific constants are semantic red.

**Torus:** preserve actual observations. DEFN-R1 predicts `V=48`, `E=48`, `c=4`, initial non-cellularity,
zero traces, §8.1 admissible-cut completeness, and terminating cut progress. Predictions may not replace runtime.

**Prescribed sphere:** standing prediction is already cellular / zero cuts. If runtime instead reaches a
trace-crossed non-disc component with no admissible cut, require typed
`NoAdmissibleCutForNonDiscComponent` plus component locus. That activates DEFN-R1 §8.2: preserve evidence,
skip further semantic work, run R6-5, and return to definition. Never widen admissibility, mutate a trace, use
tolerance, or accept partial cuts.

## R6-3 — retained barrier diagnostic

After admissible R6-2, run the retained source-edge-barrier diagnostic once only if needed to prove publication
hygiene. Its record must explicitly state the compiled equivalent of:

- `complex=sourceEdgeBarrier`
- `cellularityOracle=false`
- `oracleIsCellularityOracle=false`

It is diagnostic-only. If exact identity resolution is needed, read packaged source text; do not execute test
discovery/listing commands.

## R6-4 — D2

Only after 355/355 PASS and admissible R6-2, run one fresh process selecting:

`GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`

Preserve complete publication. If historical `CellularityNotEstablished` sites are gone, publish actual path; do
not synthesize a historical locus. D2 is non-gating.

## R6-5 — unconditional immutable postflight

Run regardless of semantic exit:

1. recompute package/source byte-and-mode inventories;
2. require exact preflight equality;
3. reverify package/source hashes;
4. record `configureOccurred=false`, `compileOccurred=false`, `relinkOccurred=false`, `repairOccurred=false`,
   `generatedDiscoveryOccurred=false`, `mutationOccurred=false`, `benchmarkExecution=false`;
5. preserve raw stdout/stderr/exit code for every process;
6. preserve an ordered execution manifest proving no duplicate or unauthorized identity execution.

## Regression documentation gate

Every observed runtime regression/candidate must be entered/updated in
`.agents/Directional/Regression_Root_Cause_Tracker.md` before EXEC evidence is durably closed.

Entering stable accounting: **43 / 14 / 29**; produced-witness debt **5**. Stable totals change only if evidence
meets tracker criteria.

## Stop boundary

R6-EXEC gathers evidence; it does not accept CP4c-2. After raw evidence, postflight, and tracker updates are
durable, **stop**.

Exact next: **`M3-CP4c-2-TB-X2-R6-REV`**.

R6-EXEC may not select/run 357/358, authorize/run the cumulative gate, edit implementation, or begin CP4c-3.
