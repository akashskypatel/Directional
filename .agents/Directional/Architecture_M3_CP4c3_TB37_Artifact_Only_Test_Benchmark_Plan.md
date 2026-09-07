# M3-CP4c-3-TB37 Artifact-Only Test + Benchmark Plan

**State:** FROZEN / EXECUTABLE NEXT PLAN
**Next turn:** `M3-CP4c-3-TB37-EXEC`
**Boundary:** Test + Benchmark / artifact-only; no configure, compile, relink, regeneration, repair, source/test/fixture/selector mutation
**Benchmarks:** prohibited for this gate; compiled benchmark presence is package evidence only

## 1. Immutable authority

TB37 consumes exactly CB42 package102 and nothing rebuilt from later documentation/control commits.

| Authority | Exact value |
|---|---|
| evidence source | `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d` |
| CB42 build run/job | `34159743881 / 101858898702` |
| package artifact ID | `10032277517` |
| package artifact name | `m3-cp4c3-cb42-result-34159743881` |
| provider / ZIP SHA-256 | `ca33be401dba11b1007258bd127948e03168cf2cd42231307d54d506028dc5ee` |
| packaged source archive SHA-256 | `84b2624f425d9870ff8079403a468bca41c584c139752e9f7e5e6b00758da42f` |
| selector | 409 identities |
| selector409 SHA-256 | `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e` |
| selector408-prefix SHA-256 | `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6` |
| artifact-only harness SHA-256 | `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3` |
| accepted prefix | ordinals 1-365 |

`M3-CP4c-3-TB36` remains the current valid semantic runtime authority until TB37 is reviewed: selector409, **402 PASS / 7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`, ownership **300/0/0**.

## 2. Objective

Execute the full selector409 exactly once from immutable package102 and determine, without changing semantics:

1. whether CB42 preserved every TB36 outcome exactly;
2. whether ordinals 366/367 publish the complete source-submesh measurement contract;
3. whether the new fields are arithmetically self-consistent;
4. which already-frozen discriminator branch `X + B_int` selects;
5. whether package/source/selector/fixture/binary/mode/execution views remain immutable.

TB37 records evidence only. It does not correct the Euler formula, region construction, disc acceptance, fixtures, or tests.

## 3. Required execution environment

Bind these exact values before execution:

```text
TURN_ID=M3-CP4c-3-TB37-EXEC
ARTIFACT_ID=10032277517
EXPECTED_ARTIFACT_NAME=m3-cp4c3-cb42-result-34159743881
EXPECTED_PROVIDER_DIGEST=sha256:ca33be401dba11b1007258bd127948e03168cf2cd42231307d54d506028dc5ee
EXPECTED_ZIP_SHA256=ca33be401dba11b1007258bd127948e03168cf2cd42231307d54d506028dc5ee
EXPECTED_SOURCE_SHA=89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d
SELECTOR_RELATIVE_PATH=.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt
EXPECTED_SELECTOR_COUNT=409
EXPECTED_SELECTOR_SHA256=eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e
ACCEPTED_PREFIX_COUNT=365
```

After preflight, execute exactly:

```bash
bash .agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh --execute
```

The packaged harness, selector, and binaries are execution authority. Do not run generated test discovery/list/help commands.

## 4. Fail-closed preflight

Before the first Directional process starts, prove all of the following. Any failure is orchestration failure, not semantic RED/PASS.

1. Artifact ID/name/provider digest/downloaded ZIP SHA-256 match §1.
2. `metadata/source-commit.txt` equals `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`.
3. Root `SHA256SUMS` verifies **28/28 PASS** and excludes itself.
4. Command-boundary metadata records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`.
5. GMP evidence contains both GMPXX and GMP linkage.
6. All eight compiled targets are present; six runtime executables retain packaged hashes and modes.
7. Selector count/hash, selector408-prefix hash, and harness hash exactly match §1.
8. Establish pre/post package, source-view, and execution-view byte+mode censuses.
9. Every selector identity maps to exactly one fresh process; zero selection is orchestration failure.

No configure, compile, relink, generated discovery, repair, chmod fix, package rewrite, source checkout mutation, fixture mutation, or selector rewrite is permitted.

## 5. Execution contract

Run all 409 identities in selector order, one identity per fresh process. Preserve raw stdout/stderr/exit code, the complete structured ledger, resource accounting, failure-detail digests, ownership census, retired-code checks, and pre/post censuses.

Do not retry a semantic RED. Do not partition/stitch the gate to evade elapsed runtime. Timeout or zero-selected invocation is orchestration failure.

## 6. Behavioral hard gate — CB42 must be observational only

TB37 must reproduce TB36's semantic result exactly:

- **402 PASS / 7 RED**;
- RED ordinals exactly `[366,367,368,369,370,374,398]`;
- accepted ordinals **1-365: 365/365 PASS**;
- protected **312, 390, 393, 404, 406, 407, 408, 409: PASS**;
- ownership exactly **300 established / 0 unavailable / 0 conflicting**;
- retired `TraceArcDoesNotSeparateItsSides` and `UncutFaceComponentOrbitSeedNotUnique` remain absent.

Any outcome movement is a CB42 scope falsifier. Preserve it and route to independent review; do not patch or retry.

The separately owned 368/369/370/374/398 surfaces must not move under CB42 ownership.

## 7. Decisive measurement — ordinals 366 and 367

Both witnesses must remain:

```text
detailCode=RegionEulerCharacteristicNotOne
regionBoundaryProvenance=FaceWalkOrbit
regionBoundaryCensusDomain=NetworkGraph
regionBoundaryNodeOccurrenceCountDerived=true
```

They must retain the previously published provenance/network fields and `vertexCount`, `edgeCount`, `faceCount`, `eulerCharacteristic`, while additionally publishing every CB42 field:

- `regionInteriorBarrierEdgeCount` (`B_int`);
- `regionExcludedVertexCount` (`X`);
- `regionExcludedMeshBoundaryVertexCount`;
- `regionExcludedBoundaryVertexCount`;
- `regionExcludedAllOwnedVertexCount`;
- `regionSubmeshBoundaryEdgeCount`;
- `regionSubmeshBoundaryVertexCount`;
- `regionVTotal`;
- `regionETotal`;
- `regionChiFull`.

Missing fields are an evidence-contract failure.

### 7.1 Arithmetic consistency checks

For each 366/367 row, verify from the published values:

```text
X =
  regionExcludedMeshBoundaryVertexCount
+ regionExcludedBoundaryVertexCount
+ regionExcludedAllOwnedVertexCount

regionChiFull = regionVTotal - regionETotal + faceCount
```

For the frozen mechanical witness when `faceCount=250`, also verify the TB36-REV identity:

```text
regionChiFull = X + B_int - 47
```

An arithmetic mismatch is a CB42 measurement defect. Preserve all raw fields and stop at review.

### 7.2 Frozen discriminator

Compute only from the published source-submesh measurements:

```text
D = X + B_int
```

Classify, without implementing a correction:

- **D = 44:** the cancellation premise holds; the full source-submesh χ is `-3`; the region is not a disc under the current construction. The next review owns the region-construction frontier.
- **D = 48:** the full source-submesh χ is `1`; the current reduced certificate is missing the non-cancelling boundary contribution by four. The next review owns the certificate arithmetic/cancellation premise.
- **D is neither 44 nor 48:** the frozen derivation and new measurement disagree. The next review first diagnoses the exclusion/barrier census; no Euler or construction correction is authorized.

Do not decide this discriminator from network arc/node counts. `regionBoundaryCensusDomain=NetworkGraph` explicitly prevents that inference.

## 8. Required focused evidence

The final result artifact must make these ordinals directly inspectable:

`312, 366, 367, 368, 369, 370, 374, 390, 393, 398, 404, 406, 407, 408, 409`.

Also preserve:

- complete 409-row ledger;
- exact PASS/RED ordinal lists;
- selected-count, timeout, and process-exit accounting;
- complete 366/367 old and new diagnostic fields;
- computed `X`-split equality, `regionChiFull` equality, and `D=X+B_int` classification;
- failure-detail digest table;
- ownership census and retired-code silence checks;
- resource summary;
- pre/post package/source/execution-view byte+mode censuses;
- exact run/job/source/artifact IDs and digests.

## 9. Stop and next-state rules

- **Orchestration failure:** promote no semantic ledger; preserve invalid-attempt provenance and route only the control-plane correction permitted by project policy.
- **Any semantic outcome movement:** preserve evidence and stop at independent `M3-CP4c-3-TB37-REV`; no retry or patch.
- **Expected 402/7 result:** preserve the complete measurement evidence and stop at independent `M3-CP4c-3-TB37-REV`, which owns the discriminator adjudication and next corrective plan.
- **Unexpected all-green result:** this violates CB42's measurement-only scope; preserve it and stop at review rather than attributing a correction that CB42 did not authorize.
- **Benchmarks:** do not execute `directional_benchmarks`.

Every observed regression/candidate must be categorized in `Regression_Root_Cause_Tracker.md` before TB37 is durably closed, per project policy.

**TB37-EXEC is the single exact next turn.**
