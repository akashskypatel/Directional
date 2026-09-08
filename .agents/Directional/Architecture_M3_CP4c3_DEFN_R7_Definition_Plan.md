# M3-CP4c-3-DEFN-R7 Definition Plan — Rebind Region Disc Authority to the Actual Embedded Face

Date frozen: 2026-09-08 UTC by `M3-CP4c-3-TB39-REV`
Turn type: **Definition / Review + Plan / static / NO RUNTIME / NO COMPILE**
Exact turn: `M3-CP4c-3-DEFN-R7`

## 1. Inherited authority

- Current runtime: TB39, package104, selector409 **402 PASS / 7 RED**, accepted **365/365**, RED
  `[366,367,368,369,370,374,398]`.
- Stable accounting: **46 / 14 / 32**, debt **5**, packages **104**.
- A2a′ `SurfaceCutGraph` is already required to prove a cellular **ActualEmbeddedGraph** before canonical A2b
  region derivation.
- A2b regions are built from non-exterior face-walk orbits of that same embedded graph.
- TB39 supplied 513 non-vacuous reduced/full diagnostic rows; the torus/mechanical discrepancy changes sign, so
  neither source-support proxy is a universal region-disc criterion.
- TB39-REV established that CB44's third-complex publication is diagnostic/projection data, not an authoritative
  per-region actual-embedded cell decomposition.

## 2. Definition question

Freeze the exact semantic contract by which a `GlobalTopologyRegion` proves disc topology **without independently
re-deriving the topology of a different source-support proxy**.

The definition must distinguish three roles:

1. **topology authority:** the matching actual-embedded face-walk orbit and upstream
   `SurfaceCutGraphFaceCertificate`;
2. **source support / ownership:** `region.sourceFaces`, certified source-face ownership, `fragmentCorners`, and
   related mappings used to attach source data to that face;
3. **diagnostics:** reduced/full source-submesh Euler counts, split-fragment/source-edge censuses, and failure-detail
   publication.

A role-2 or role-3 datum may not silently become role-1 authority.

## 3. Required frozen decisions — R7.1–R7.9

### R7.1 — withdraw the proxy as region-topology authority

Record explicitly that DEFN-R6.3/R6.4 are superseded for **region disc topology**. Preserve their measurements as
historical/projection diagnostics where useful. Do not replace reduced with full or vice versa.

### R7.2 — name the actual object

A canonical topology region is the non-exterior face-walk orbit of the A2a′ certified
`ActualEmbeddedGraph` from which `build_regions()` derives it. Its disc-topology authority is the matching
`SurfaceCutGraphFaceCertificate` for that orbit.

### R7.3 — freeze the provenance/binding relation

Specify the exact relation that binds a region to one upstream face certificate. The relation must be derivable from
current authoritative structure and must fail after a copied candidate mutates its boundary. At minimum freeze:

- exact boundary equality with one current face-walk orbit;
- non-exterior orbit membership;
- exactly one matching `SurfaceCutGraphFaceCertificate` with the same orbit;
- `proves_disc_topology()` on that face certificate;
- current source/network/cut-graph semantic bindings remain valid.

Do not authorize a stored “trusted at construction” boolean as the sole proof.

### R7.4 — redefine the downstream certificate around one semantic object

Choose one contract for `GlobalTopologyRegionDiscCertificate` that cannot mix complexes. Preferred direction:
make it a **binding/consumption certificate** for the upstream actual-embedded face proof, while keeping
`interiorSingularityFree` and boundary-singularity data as separately owned field-regularity evidence.

If V/E/F are retained as semantic fields, they must count the **same actual embedded face complex**. Otherwise
rename/retain them as diagnostics and remove them from `proves_disc_topology()`.

### R7.5 — preserve independent tamper falsifiers

Ordinals 312 and 409 are immutable provenance-overreach falsifiers. A copied/mutated region must not inherit a stale
disc guarantee merely because it originated from a canonical plan. Freeze the expected failure surface before
implementation.

### R7.6 — freeze diagnostic-domain names

`regionFullEulerCharacteristic` may never receive the reduced value. Freeze whether the later implementation:

- binds it to `totalVertexCount - totalEdgeCount + faceCount` as explicitly source-submesh diagnostic data; or
- replaces it with a more explicit domain-named field.

Do the same audit for every reduced/full/split/barrier field so a label cannot claim a stronger domain than its
producer computes.

### R7.7 — enumerate consumers before changing representation

Name every product field, validator, semantic digest, failure translation, test oracle, diagnostic emitter and
serialization surface that consumes the region disc certificate or its Euler fields. The successor Code + Build
must not discover consumers by compiler error alone.

### R7.8 — preserve unrelated authorities

No change to region construction, face-walk creation, source-face ownership, `fragmentCorners`, A2a′ cut selection,
selectors, or the separately owned RED surfaces 368/369/370/374/398. No sphere or empty-network semantic fix.

### R7.9 — freeze successor and falsifiable gate

Freeze one bounded runtime-free Code + Build successor (expected next ordinal name: `M3-CP4c-3-CB45`, unless the
definition proves a different repository-consistent successor ID is required). Its later TB must preserve:

- accepted **365/365**;
- ordinals 312/409 PASS;
- protected 390/393/404/406/407/408 PASS;
- ownership 300/0/0 and retired-code silence;
- 368/369/370/374/398 unchanged in ownership;
- a non-vacuous assertion that canonical regions bind one-to-one to upstream disc face certificates;
- tampered synthetic candidates fail that binding rather than inheriting it.

## 4. Prohibited in DEFN-R7

- no Directional runtime, compile, benchmark or package operation;
- no product/test/fixture/selector implementation;
- no selection of reduced/full/split proxy merely because it agrees on one fixture;
- no post-region topology repair or re-cut;
- no sticky provenance flag that survives a copied/mutated candidate;
- no weakening of accepted or protected identities;
- no reclassification of 368/369/370/374/398 without new independent evidence.

## 5. Exit

DEFN-R7 closes only when the normative definitions, consumer inventory, falsifiable predictions, exact successor,
and implementation prohibitions are frozen in `M3_CP4c_Frozen_Definitions.md` (and required durable indexes are
updated). It stops before implementation.
