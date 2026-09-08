# M3-CP4c-3-TB40 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN BY CB45 / NOT EXECUTED
**Turn:** `M3-CP4c-3-TB40-EXEC`
**Execution input:** immutable package105 from CB45
**Source:** `0f09439893182235c382492583b82aa35f25045c`
**Package artifact:** `10057456162` / `m3-cp4c3-cb45-result-34229976475`
**Package ZIP SHA-256:** `c9cd0397d22b7cc0c343838a90fdcfe649137fa37a985453778c04731049b99e`
**Selector409 SHA-256:** `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`
**Artifact-only harness SHA-256:** `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`

## 1. Boundary

TB40 is an **artifact-only** Test + Benchmark execution. It may execute only the immutable binaries and
artifact-only harness packaged by CB45. It must not configure, compile, relink, regenerate, repair, mutate source,
tests, fixtures, selectors, package bytes, file modes, or the execution view.

No runtime result is assumed by this plan. TB40 records raw execution evidence; semantic promotion, stable-event
repricing, candidate closure, or a corrective successor belongs to the required review/adjudication edge.

## 2. Pre-execution package proof

Before starting any Directional process:

1. download package artifact `10057456162` once and verify provider/download SHA-256
   `c9cd0397d22b7cc0c343838a90fdcfe649137fa37a985453778c04731049b99e`;
2. verify package root `SHA256SUMS` **28/28** with no self-entry;
3. verify packaged source archive SHA-256
   `7d1cb457d1101e6addbadd732d783efdae956f61b9732b492c1b9063828a6472`;
4. verify `metadata/source-commit.txt` is exactly
   `0f09439893182235c382492583b82aa35f25045c`;
5. verify selector409, selector408-prefix, and harness hashes:
   - selector409 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
   - selector408 prefix `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
   - harness `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
6. census package/source/execution-view bytes and modes before runtime.

A failed pre-execution proof makes the attempt mechanically invalid. Do not repair the package inside TB40.

## 3. Execution contract

Run selector409 exactly once, in ordinal order, with **one identity per fresh process** through the immutable
artifact-only harness. Record selection identity, process exit, timeout status, observed PASS/RED, typed failure
code/stage, and required diagnostic rows.

Do not run generated test discovery, `ctest`, benchmark discovery, CLI help/version, or any unlisted executable
outside the frozen harness contract.

## 4. Hard gate requirements

TB40 must explicitly report these frozen conditions:

- accepted ordinals **1–365 = 365/365 PASS**;
- ordinal **312 PASS**;
- ordinal **409 PASS**;
- ordinals **390, 393, 404, 406, 407, 408 PASS**;
- certified source ownership **300 established / 0 unavailable / 0 conflicting** where published;
- retired-code silence for `TraceArcDoesNotSeparateItsSides` and `UncutFaceComponentOrbitSeedNotUnique`;
- selector409 bytes unchanged;
- separately owned RED surfaces **368/369/370/374/398** remain attributed to their existing owners rather than
  being absorbed by the region-disc correction.

Failure of accepted 1–365, 312, or 409 is a hard regression and must not be normalized by weakening the gate.

## 5. Actual-embedded face binding evidence

Every creditable A2b witness must publish a non-empty `M3_CP4C3_FACE_BINDING_CENSUS`.

For each complex, require exactly one `record=complex` row containing:

- `graphComponents`
- `sourceComponentCount`
- `exteriorSize`
- `boundaryLoops`
- `graphEuler`
- `sourceEuler`

For each emitted A2b region, require exactly one binding row. The region row must identify the independently
derived current face-walk orbit and the consumed upstream `SurfaceCutGraphFaceCertificate`, with no duplicate or
missing upstream orbit consumption.

The verifier must fail closed if:

- the census is empty;
- a creditable region lacks a row;
- a region binds zero or multiple upstream faces;
- an upstream non-exterior face is consumed zero or multiple times;
- copied/mutated candidate validation accepts a stale binding;
- the purported measurement is only a uniform constant/bit where the frozen field under test cannot disagree.

`boundaryWalkCount == 1` is structural, not independent evidence. `discTopologyEstablished` is the complex-level
cellularity conclusion and must not be counted once per face as independent proof.

## 6. Retired-proxy and diagnostic contract

Ordinals 366/367 must no longer be rejected **solely** by the retired A2b proxy producers
`RegionEulerCharacteristicNotOne` or `RegionInteriorDisconnected`. TB40 records whatever later legitimate frontier
they reach; it does not require them to become green unless another frozen gate says so.

Source-support connectivity, reduced/full Euler, split/barrier, and related projection values are diagnostic
domains only. A diagnostic mismatch may be reported, but it cannot silently re-establish a second region-disc
theorem.

## 7. Post-execution immutability proof

After all selector identities finish:

1. repeat package/source/execution-view byte and mode censuses;
2. prove pre/post censuses are identical;
3. prove selector409 and harness hashes are unchanged;
4. prove no configure, compile, relink, package repair, generated discovery, or source/test/fixture/selector mutation
   occurred.

## 8. Evidence output

Preserve at minimum:

- exact package/source/harness/selector identities;
- 409/409 execution ledger with one identity per fresh process;
- aggregate PASS/RED vector and accepted-prefix count;
- failure-detail table for every RED identity;
- binding-census table plus complex-level authority rows;
- certified ownership census and retired-code census;
- pre/post byte+mode census;
- result and persistent diagnostic-log artifacts with provider/download SHA-256.

TB40-EXEC does not promote itself. Its raw artifact-only evidence is handed to the required independent
review/adjudication turn.

**Do not execute TB40 from CB45.**
