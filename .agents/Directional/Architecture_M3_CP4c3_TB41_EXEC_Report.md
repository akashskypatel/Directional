# M3-CP4c-3-TB41-EXEC — Artifact-Only Test + Benchmark Report

**Status:** COMPLETE / MECHANICALLY VALID / SEMANTIC GATE RED / REVIEW PENDING / NOT PROMOTED
**Date:** 2026-09-08
**Turn:** `M3-CP4c-3-TB41-EXEC`

## 1. Immutable authority and execution boundary

TB41 executed only the immutable CB46 package106 authority:

- semantic source: `4cdffe5514ab9f747da38e74c57663ee8806efa6`;
- package/result artifact: `10066942690` / `directional-m3-cp4c3-cb46-result-34253044050`;
- package ZIP/provider SHA-256:
  `aae9da4b2b237c7ebda82af2d7153c0e766f24455f1a45ab4a2685e9961a3d24`;
- packaged source archive SHA-256:
  `d355ea6bb13ee0d7e174edc214070cfbd81cf278ce44ad7a4f77bacc17bee004`;
- selector409: 409 LF rows, SHA-256
  `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- artifact-only harness SHA-256:
  `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`.

Authoritative runtime run/job is **`34256568679 / 102164030279`**. The result artifact is
`10068290377` / `m3-cp4c3-tb41-result-34256568679`, provider digest
`sha256:eb17cdef825ec62421641baef26ecb9a9d0d2052e8a08e21d2abf3c0a853fd3f`. The persistent log artifact is
`10068291332` / `m3-cp4c3-tb41-log-34256568679`, provider digest
`sha256:ae65f4d7a93d2ba56b30000078423d7962e9043d454c3a9d677d78d2273935ac`.

Preflight verified the package root manifest **28/28**, exact source/archive/selector/harness authority, empty
packaged source status, GMP compile evidence, and the actual producer-test runtime dependency on `libgmp.so`.
Execution reports:

```text
runtime_started=true
runtime_completed=true
preflight_completed=true
execution_view_verified=true
orchestration_failure=false
selection_integrity=true
timeout_count=0
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
mode_repair=false
source_test_fixture_selector_mutation=false
```

No package, product, source, test, fixture, selector, build, or benchmark bytes were changed.

### Invalid control-plane attempts retained as provenance

Two earlier control-plane attempts are **not semantic runtimes** and are not authority:

1. run `34256050160` stopped before runtime because the caller parsed the committed selector SHA with its trailing
   prose period; log artifact `10067894576`;
2. run `34256247287` completed the immutable harness preflight but stopped before runtime because an extra caller
   check incorrectly required `libgmpxx.so` to survive the linker/runtime dependency graph; the authoritative
   compile evidence already records GMP/GMPXX linkage, while the producer binary's resolved dynamic dependency is
   `libgmp.so.10`; log artifact `10067979042`.

Attempt 3 changed only control-plane checks and reused package106 unchanged.

## 2. Mechanical selector result

All **409/409** selector identities executed exactly once in selector order, each with `selected=1`, zero selection
mismatch and zero timeout.

- **398 PASS / 11 RED**
- **accepted 1–365 = 365/365 PASS**
- RED ordinals:
  **`[366,367,368,369,370,374,390,393,398,406,407]`**
- ledger SHA-256:
  `5b1e663e2855d453cf461847ed463b7539f9d0e945b4c40468eab64ae3e57a99`
- failure-detail table SHA-256:
  `82b7a0e8be0cbf70646b9e08be5199029383a7aee2bcb9c2bb1eea92f7a9c380`

Because the frozen TB41 plan requires protected ordinals 390/393/406/407 to recover, this is a **semantic gate RED**
runtime. EXEC records that fact but does not adjudicate or promote it.

## 3. Frozen witness checks

### 3.1 Accepted content-anchor repair recovered

Ordinals **311 / 314 / 356 / 357 all PASS**.

The immutable 311 body derives `canonical_cycle_anchor(...)`, requires the region certificate to carry that anchor,
and independently requires exactly one upstream face certificate with the same anchor. Ordinal 314 passes the
independent disc-proof oracle over the same frozen package.

Ordinals 356 and 357 each publish one complex row and four non-vacuous region rows. The region rows are:

```text
region 0: independent=(arc 0, Reverse) certificate=(arc 0, Reverse) orbit=1 upstream=1 arcs=26/26 disc=true field=true
region 1: independent=(arc 0, Forward) certificate=(arc 0, Forward) orbit=0 upstream=1 arcs=50/50 disc=true field=true
region 2: independent=(arc 12, Reverse) certificate=(arc 12, Reverse) orbit=2 upstream=1 arcs=50/50 disc=true field=true
region 3: independent=(arc 24, Reverse) certificate=(arc 24, Reverse) orbit=3 upstream=1 arcs=26/26 disc=true field=true
```

All four oriented anchors are unique; all `upstreamMatchCount` values are 1; region/certificate boundary-arc counts
match; disc topology and field regularity are established. The content field is non-uniform. This mechanically
recovers the four accepted losses from TB40 without changing the production orbit-keyed binding.

### 3.2 Binding falsifiers preserved

Ordinals **312 / 315 / 409 PASS**. The immutable 315 body replaces one region's
`actualEmbeddedFace.orbit` with a distinct published orbit and requires
`InvalidRegionCertificateBinding`; 312 and 409 continue to reject synthetic multi-walk candidate boundaries.

### 3.3 Frontier evidence correction did not recover protected identities

Ordinals **390 / 393 / 406 / 407 are RED**, all at the same frozen assertion:

```text
Expected: regionFrontierComponentCount > 0
Actual:   0
```

Thus CB46's broader collection of frontier locators did **not** make a frontier component available on these
production-failure paths. The runtime-local mechanism is established; the source-level owner/correction remains
for independent review.

### 3.4 Ownership controls preserved

Ordinals **404 / 408 PASS**. The certified-owner publication remains:

```text
sourceFaceCount=300
established=300
unavailable=0
conflicting=0
conflictRowCount=0
```

### 3.5 Mechanical missing-fragment measurement is now specific

Ordinals **366 / 367 remain RED** at
`RegionSourceFaceOwningFragmentMissing / RegionCertification`, as intended for measurement rather than repair.
Both publish:

```text
sourceFace=10,11,79
regionOwningFragmentOrbit=1
regionFrontierComponentCount=0
fragmentOwnerFaceCount=74
fragmentOwnerFacesTruncated=false
```

The row for the failing source face is `fragmentOwnerFace[11]` and reports:

```text
localFragmentCount=3
ownerCount=3
expectedFragmentCount=3
ownerDeficit=0
traceChordCount=2
chordsCrossInside=false
localArrangementEvaluated=true
sharedOwnerChordCount=0
```

So the observed rejection is **not explained by a simple owner-count deficit on the named source face**. EXEC does
not infer the missing fragment-to-orbit relation; TB41-REV owns that adjudication.

### 3.6 Carried owners and retired-code silence

The remaining RED identities are carried without repair:

- 368: prescribed sphere still stops at
  `CellularityNotEstablished / RotationSystemInconsistent / TraceEventPositionInvalid`,
  `NoCarrierMatch / SourceEdgeUnavailable`;
- 369: ordinary proposal still observes `saturationUsed=true`;
- 370: empty-network closed-surface typed error/locus contract remains RED;
- 374: folded-cone witness still fails atlas construction;
- 398: prescribed sphere prevents the total-ownership production-fixture oracle from reaching a cut graph.

Across all raw logs there are **zero** occurrences of
`RegionEulerCharacteristicNotOne`, `RegionInteriorDisconnected`,
`TraceArcDoesNotSeparateItsSides`, or `UncutFaceComponentOrbitSeedNotUnique`.

## 4. Regression accounting and promotion boundary

TB41 mechanically closes the runtime-pending portion of
`M3-CP4c3-TB40-EXEC-CAND-01`: accepted 311/314/356/357 are recovered. The historical stable
`RP-05 / REPRESENTATION_DEPENDENT_IDENTITY` event remains counted; recovery does not erase it.

`M3-CP4c3-TB40-EXEC-CAND-02` remains **ACTIVE / GATING / NON-STABLE / REVIEW REQUIRED** because
390/393/406/407 remain RED with `regionFrontierComponentCount=0` after the CB46 correction. This EXEC evidence does
not by itself justify a new stable event/category/recurrence. Stable accounting therefore remains
**47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, packages **106**, pending independent
review.

**TB39 remains the current promoted semantic runtime authority** until review: package104 / selector409,
**402 PASS / 7 RED**, accepted **365/365**. TB41-EXEC does not promote itself.

## 5. Exact successor

Stop at independent **`M3-CP4c-3-TB41-REV`**. That review must adjudicate the protected frontier failure and the
new missing-fragment/orbit measurement, decide promotion/accounting, update review-owned durable orientation, and
issue the next bounded corrective plan if required. It must not execute another runtime or compile before that
adjudication.
