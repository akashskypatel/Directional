# M3-CP4c-3-TB37-EXEC — Artifact-Only Test + Benchmark Execution Report

**Turn:** `M3-CP4c-3-TB37-EXEC`
**Date:** 2026-09-07 UTC
**Scope:** Test + Benchmark EXEC, artifact-only; **benchmarks prohibited and not executed**.
**Semantic source under test:** `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`
**Immutable package:** artifact `10032277517` / `m3-cp4c3-cb42-result-34159743881`
**Selector:** 409 identities, SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`

## Verdict

TB37-EXEC is **mechanically valid and semantically RED**. Immutable package102 executed selector409 exactly once
per identity through the packaged artifact-only harness. The result reproduces TB36 exactly: **402 PASS / 7 RED**,
accepted **1–365 = 365/365 PASS**, RED `[366,367,368,369,370,374,398]`, every ledger row selected, zero selection
mismatch, zero timeout, and identical package/source/execution-view censuses before and after execution.

The CY6 measurement is complete on ordinals **366/367** and the two failures remain byte-identical. Both publish
`X=36`, `B_int=12`, split `0 + 20 + 16 = 36`, source-submesh boundary `20 edges / 20 vertices`,
`V_total/E_total/F/chiFull = 136/385/250/1`, and therefore **`D = X + B_int = 48`**. The frozen discriminator
classifies this raw evidence as **`CERTIFICATE_ARITHMETIC`**: the full source-submesh Euler characteristic is 1,
while the existing reduced certificate still publishes `100/353/250/-3`. EXEC records that discriminator only;
**independent TB37-REV owns semantic adjudication and any corrective plan**.

No product, test, fixture, selector, benchmark, build, package, definition, or reusable workflow was mutated by the
runtime execution.

## Execution provenance

- start-of-turn source snapshot run `34160990121`, artifact `10032589771`, provider digest
  `sha256:9d78070fe9ec9d8813804a5cdb2df066eb70757fd32542972799d0942449d1fb`;
- snapshot source archive SHA-256 `c869b805979fbeaadab5486d021801ef69bdd95ff41333254356f6c897b51248`;
- temporary measurement-verifier payload commit `6432401be97245b0f1a896e2fcf38b2ff928d4d8`;
- caller install commit `80387c0a1a68c035d690f6b49229c6505dcca5f9`;
- execution-trigger commit `6a915a4ed6e068c81940037f0811f9bf372a798f`;
- workflow run `34161464783`;
- schema-validation job `101864008369`: PASS before runtime;
- observer job `101864008219`: PASS; branch-file observer disabled;
- execute job `101864038796`: PASS;
- result artifact `10032812538` / `m3-cp4c3-tb37-exec-result-34161464783`, provider digest
  `sha256:53c7d8236c1eb3a196ece1091f5048e4ea7d04447af5f7f19c48dfdd95430f8e`;
- persistent log artifact `10032812978` / `m3-cp4c3-tb37-exec-log-34161464783`, provider digest
  `sha256:36f8296a6ee5d62e3e3cdc026ed3015628b6d91711027c88a69c86e00019a8de`.

The caller used the durable schema validator and entered runtime only after schema success. Runtime-job permissions
were `actions: read` and `contents: read`; reusable workflow permissions were unchanged.

### Control-plane procedural miss — semantic evidence unaffected

The turn initially created `.agents/connector-triggers/turn-cleanup/manifest.txt` during setup instead of deferring
it to closeout. The durable cleanup workflow is itself push-triggered by that path, so this caused premature cleanup
run `34161412687` before the TB37 caller/marker existed. Its cleanup and observer jobs completed successfully. The
run removed only then-inventoried temporary setup state and PR comments; it did not execute Directional, touch
package102, modify product/test/fixture/selector content, or participate in the TB37 runtime evidence. Subsequent
TB37 control commits were made after that run and the semantic execution remained bound to immutable package102.
The final closeout again uses workflow-first caller removal and only then publishes the cleanup manifest.

This is a control-plane process miss, not a product regression or stable event.

## Immutable artifact authority

Package102 was verified before the first Directional process:

- artifact/provider/downloaded-ZIP SHA-256:
  `ca33be401dba11b1007258bd127948e03168cf2cd42231307d54d506028dc5ee`;
- packaged source SHA: `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`;
- packaged source archive SHA-256:
  `84b2624f425d9870ff8079403a468bca41c584c139752e9f7e5e6b00758da42f`;
- packaged harness SHA-256:
  `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- selector409 SHA-256:
  `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector408-prefix SHA-256:
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- package `SHA256SUMS`: **28/28 PASS**;
- all six packaged runtime executables retained mode `0755`.

No configure, compile, relink, package repair, mode repair, generated discovery, source/test/fixture/selector mutation,
or benchmark execution occurred. Local analysis only extracted and inspected preserved artifacts; no Directional
binary was executed locally.

## Harness boundary and ledger integrity

`execution-boundary.txt` records `script_exit=0`, `runtime_started=true`, `runtime_completed=true`,
`preflight_completed=true`, `execution_view_verified=true`, `orchestration_failure=false`,
`selection_integrity=true`, `timeout_count=0`, and every mutation/build/benchmark flag false.

Evidence integrity:

- `ledger.tsv`: 409 rows, SHA-256 `058c54603bfe4663578d174531932fa9c9716e905f48a1b2feb1b26656171366`;
- `identity-map.tsv`: 409 rows, SHA-256 `f33cd349fd55e962f4bf22918abbccc04c8744205c62ddbe6122d8b50958290f`;
- `resource-summary.tsv`: 409 rows, SHA-256 `14f0e3df200cfb9aecf5e8fa7f089854bb4e0e7a3843f5df770d78158d11709a`;
- failure-detail digest table SHA-256:
  `2b6ca8d2a65966edef3682c7d84706190c336662c7a25b43c730d08c4b4968f3`;
- package census before/after SHA-256: both
  `1f00c184986db4394a0f8b172e7b11070596a876e1a9615945fb0611993b5e32`;
- source census before/after SHA-256: both
  `d3654b5e381585365939a2defb82358a4cf1831e36e18f66a1e31f1d1c45f688`;
- execution-view census before/after SHA-256: both
  `0740250cf4b82e14ad55f75ee1e05b6a31cfec74ff7d7ffeb9714a1a3d3bf6c7`.

Maximum recorded RSS is **18,564 KiB** at ordinal 147 (`0:14.92`). This is observation only; TB37 has no benchmark
or resource acceptance gate.

## Semantic result

| Measure | TB37 raw EXEC |
|---|---|
| selector | 409 |
| PASS / RED | **402 / 7** |
| RED ordinals | **366, 367, 368, 369, 370, 374, 398** |
| accepted prefix 1–365 | **365 / 365 PASS** |
| selection mismatch | none |
| timeouts | 0 |
| protected 312 | PASS |
| protected 390/393/404/406/407/408/409 | all PASS |
| certified ownership at ordinal385 | **300 / 0 / 0** (`established/unavailable/conflicting`) |
| retired `TraceArcDoesNotSeparateItsSides` | absent |
| retired `UncutFaceComponentOrbitSeedNotUnique` | absent |

Ordinal398 again publishes the unchanged mechanical owner map `sourceFaceCount=300;ownerMapCount=300;
provesCellularity=true`; torus publishes `144/144`.

### Ordinals 366 and 367 — the source-submesh discriminator is 48

Both failure-detail files have SHA-256
`d27c51793449568873c9a3af4d87735c6ff756280e6dae50eb3af60c41902034` and publish:

```text
detailCode=RegionEulerCharacteristicNotOne
regionBoundaryProvenance=FaceWalkOrbit
regionBoundaryCensusDomain=NetworkGraph
regionBoundaryNodeOccurrenceCountDerived=true
regionBoundaryArcOccurrenceCount=40
regionBoundaryDistinctArcCount=22
regionBoundaryNodeOccurrenceCount=40
regionBoundaryDistinctNodeCount=22
regionBoundaryRepeatedNodeOccurrenceCount=18
regionBoundaryStartRevisitBeforeEndCount=1
regionInteriorBarrierEdgeCount=12
regionExcludedVertexCount=36
regionExcludedMeshBoundaryVertexCount=0
regionExcludedBoundaryVertexCount=20
regionExcludedAllOwnedVertexCount=16
regionSubmeshBoundaryEdgeCount=20
regionSubmeshBoundaryVertexCount=20
regionVTotal=136
regionETotal=385
regionChiFull=1
vertexCount=100
edgeCount=353
faceCount=250
eulerCharacteristic=-3
```

The frozen checks all hold:

- exclusion split: `36 = 0 + 20 + 16`;
- full source-submesh Euler: `136 - 385 + 250 = 1`;
- TB36-REV identity: `X + B_int - 47 = 36 + 12 - 47 = 1`;
- discriminator: **`D = X + B_int = 48`**.

Therefore the pre-authored TB37 discriminator records **`CERTIFICATE_ARITHMETIC`**, not region construction and not
measurement inconsistency. The old reduced certificate remains `100 - 353 + 250 = -3`, so the measurement exposes a
four-point discrepancy between the full sub-mesh Euler characteristic and the reduced certificate. **EXEC does not
select or implement a correction.**

### Carried RED identities

The five separately owned failures remain RED at their prior surfaces: ordinal368 prescribed sphere
`CellularityNotEstablished / RotationSystemInconsistent / TraceEventPositionInvalid`; ordinal369 still selects
saturation where ordinary proposal is required; ordinal370 still returns the wrong typed empty-network code without
a source-face locus; ordinal374 still fails because `atlasBuild=false`; ordinal398 still cannot obtain the prescribed
sphere cut graph. They remain carried owners and are not re-owned by TB37.

## Regression classification before close

TB37 observed **no new RED ordinal and no accepted-prefix regression**. The seven RED identities map to existing
open records. In particular:

- 366/367 are raw measurement evidence for existing **`M3-CP4c3-TB36-REV-CAND-01`** and the re-scoped
  `M3-CP4c3-TB34-REV-CAND-03`; they publish `D=48` and the frozen `CERTIFICATE_ARITHMETIC` discriminator, but remain
  **REVIEW PENDING** until independent TB37-REV;
- 368/369/370/374/398 remain their prior carried owners and classifications;
- the premature cleanup run is classified as a non-semantic control-plane process miss and creates no regression
  event.

Because EXEC is not the independent review, it does **not** create, merge, close, or reprice a stable regression.
Stable accounting therefore remains **45 events / 14 categories / 31 recurrences**, produced-witness debt **5**,
and semantic package count **102** pending TB37-REV. TB36 remains current valid semantic runtime authority until
that review decides whether to promote the TB37 ledger.

## Required stop

TB37-EXEC raw evidence is preserved. Semantic RED remains, so the exact next boundary is **independent
`M3-CP4c-3-TB37-REV`**. That turn may adjudicate the `D=48` measurement, decide package102 semantic-authority
promotion, and freeze the next bounded measure. **No additional runtime, benchmark, compile,
source/test/fixture/selector mutation, or corrective implementation is authorized inside this EXEC turn.**
