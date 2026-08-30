# M3-CP4c-3-TB1 — Phase-1 Artifact-Only Test + Benchmark Report

Date: 2026-08-30 UTC
Turn type: **Test + Benchmark, artifact-only**
Status: **COMPLETE / VALID SEMANTIC RED / REVIEW REQUIRED**

## 1. Scope and immutable authority

This turn consumed the immutable `M3-CP4c-3-CB1` package directly and executed phase-1 runtime evidence only. It did
not configure, compile, relink, repair, regenerate, mutate product/test/fixture/selector/package bytes, author a
phase-2 fix, or execute a performance benchmark.

Immutable authority:

- semantic source: `48dd011c4aa689a245b74527ed9df0900ada9bf3`
- package **68** artifact: `9739919234`
- package SHA-256: `127c7b086a8849de7f0c14928f2c5d762c3bf71711821d0a1fabfefda889d11c`
- packaged source archive SHA-256: `f1fce7f720718c8ac974d0d5f77ca1fee4244b10c710d2b505a1af162e4f937f`
- frozen selector **367** SHA-256:
  `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`
- frozen prefix hashes:
  - 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
  - 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
  - 361: `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`
  - 365: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`

Authoritative runtime run/job: **`33340448381 / 99335020672`**.

Result authority:

- result artifact `9740416876`, SHA-256
  `713d4e6853adde54e17738d6d25e5a310a5f88ff8e4232abf67bb73c7a8cbdc0`
- diagnostic log artifact `9740417020`, SHA-256
  `8302f6ae50a8d5d29f92952aed0f144eb78bda3f070612f3dec67a63701debc0`
- immutable preflight: **PASS**
- immutable postflight: **PASS**
- `packageImmutable=true`
- `sourceImmutable=true`
- `zeroSelected=0`
- `configure=false`, `compile=false`, `relink=false`, `repair=false`,
  `generatedDiscovery=false`, `benchmarkExecution=false`, `mutationOccurred=false`

## 2. Required selector result

The frozen selector executed from ordinal 1, one identity per fresh process, with first-red hard stop:

- required executed: **366**
- required PASS: **365**
- required RED: **1**
- first red ordinal: **366**
- first red identity:
  `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`
- ordinal 367 was correctly **not executed** after the first red
- escaping C++ exceptions: **1**, the ordinal-366 test-body failure carrying the AK1/AK2 diagnostic; this is semantic
  evidence, not orchestration failure.

The accepted **365/365 prefix is therefore re-proved green** on package 68. CP4c-3 remains open because its first
checkpoint-local identity is red.

## 3. AK1/AK2 — mechanical witness measured cause

Ordinal 366 and the mechanical non-gating publisher independently report the same A1 failure:

`IncompleteCycleBasis → CycleTransportAdjacencyMissing`.

Exact failing locus/evidence:

- topology region: `0`
- source edge: `0-3`
- `fieldTransportAdjacencyExists=false`
- `globalEF=1,158`
- `localEF=1,158`
- local boundary edges: `0`

AK2 publishes the sole region row:

`V=152, E=450, F=300, χ=2, boundaryLoops=0, genus=0, interiorLocalVertices=152,
expectedCycles=152, cycleRows=152, cycleCurvatures=152, innerAdjacencies=450,
localMeshAvailable=true, bundleInitialized=true`.

The measured discriminator is therefore the exact AK1 site that lacks a `FieldTransportAdjacency` for a cycle edge;
the count/dimension checks themselves agree. This turn records the measurement only. **The independent phase-1
review owns causal interpretation and the AK6 corrective design.**

## 4. AK3 — prescribed sphere measured cause

The frozen sphere diagnostic reaches source topology, atlas, and network, then fails in `SurfaceCutGraph` through the
existing lossy outer code:

- `surfaceCutGraphError=CellularityNotEstablished`
- `originatingTopologyError=RotationSystemInconsistent`
- **`originatingRotationSystemReason=TraceEventPositionInvalid`**
- source topology regions: available, count `1`
- atlas: available
- network: available, **24 traces / 56 events**
- terminal trace intersections: `10`
- furthest stage: `field-aligned-network`
- global topology plan: unavailable

AK3 therefore localizes the previously nine-way rotation-system collapse to **`TraceEventPositionInvalid`**. The
independent pre-cut non-cellularity evidence from CP4c-2 remains separately true; this TB does not infer that the two
causes are the same.

## 5. Frozen non-gating diagnostics

All three frozen report-only identities executed once in fresh processes. They contribute zero gate credit:

| identity | result | classification |
|---|---:|---|
| `GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable` | RED | existing downstream `tracing` failure; reaches `GlobalTopologyPlan` with 4 regions; outside CP4c-3 ownership |
| `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` | RED | reproduces the gated AK1/AK2 `CycleTransportAdjacencyMissing` evidence |
| `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable` | RED | publishes AK3 `TraceEventPositionInvalid` |

The torus still publishes `surfaceCutGraph=true`, `globalTopologyPlan=true`, `cutEdgeCount=28`, actual-graph
`V/E/F=72/76/4`, and four χ=1 regions before the downstream tracing stop. This does not weaken the accepted CP4c-2
365/365 authority.

## 6. Non-semantic orchestration controls

Three earlier attempts stopped in preflight before any Directional runtime and are not semantic authority:

- `33340136751` — control-script `pipefail` interaction in the `strings | grep -q` preflight probe;
- `33340220758` — over-strict runtime-library preflight expected dynamic `libgmpxx` even though package/link evidence
  already proved GMP/GMPXX authority;
- `33340336194` — packaged-source archive SHA-256 was transcribed as a malformed 63-hex value.

Only orchestration/preflight code changed between attempts. Package 68, source, selectors, tests, fixtures and runtime
semantics remained byte-identical. Run `33340448381` corrected those control-plane defects and is the sole semantic
TB1 authority.

## 7. Regression/candidate classification and accounting

This TB creates **no stable regression event or recurrence**:

- the accepted 365 prefix remains fully green;
- ordinal 366 belongs to the previously unaccepted CP4c-3 gate and measures the already-known mechanical failure;
- the sphere and torus diagnostic reds are already tracked/non-gating;
- the three rejected attempts are orchestration-only and executed no Directional runtime.

Stable accounting remains **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**.
Authoritative M3 package count remains **68**.

Tracker dispositions updated by this turn:

- `M3-CP4c3-DEFN-CAND-01`: **MEASURED / REVIEW REQUIRED** — AK1 is
  `CycleTransportAdjacencyMissing`, with the AK2 region/locus row above.
- `M3-CP4c2-TB-X2-CAND-04`: remains **ACTIVE / NON-STABLE**, now AK3-localized to
  `TraceEventPositionInvalid`.
- `M3-CP4c2-TB-X2-R4-CAND-03`: unchanged **ACTIVE / OUT-OF-SCOPE**, re-observed by the torus report-only identity.
- `M3-CP4c3-TB1-ORCH-01`: **CLOSED / ORCHESTRATION / NON-STABLE** for the three pre-runtime controls.

## 8. Disposition and exact successor

`M3-CP4c-3-TB1` is complete as a **valid semantic red**. It does not close CP4c-3 and does not authorize an immediate
retry or a phase-2 patch.

The exact next turn is the **independent CP4c-3 phase-1 TB review / planning turn**. That review must interpret the
measured `CycleTransportAdjacencyMissing` and `TraceEventPositionInvalid` causes, update `ORIENTATION.md` as required
for review turns, and order the bounded AK4–AK7/phase-2 work. No phase-2 product correction begins before that review.
