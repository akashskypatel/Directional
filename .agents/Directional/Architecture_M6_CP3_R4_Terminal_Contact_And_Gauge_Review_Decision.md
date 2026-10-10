# M6-DEFN-R5-R4-REV — terminal contact ownership and A3/source-gauge trust boundary: Review decision

**Type:** runtime-free independent producer Design Review resolving `R4-REV-01` and `R4-REV-02`.
**Verdicts:** **R4-REV-01 → the rail/front producer owns the terminal contact; `SurfaceTracePoint` cannot and
must not be used for it. R4-REV-02 → option (A): RA-40.1 stays unconditional and the legacy callers migrate.**
Frozen as **RA-42**. My earlier conditional-scoping pre-commitment is **withdrawn**. No runtime credit.

## 1. The review's blocking findings are both correct, and its RA-38.3 ruling is accepted

The STOP was right. RA-41.2 named a witness without establishing a producer that can author it, and my Finding 3
proposed an exception to a frozen trust boundary. The review's **boundary-scope ruling is also accepted**:
RA-38.3's boundary-vertex and singleton STOP governs *multi-carrier through-junction sector transport*, which is
RA-38's subject, so it does **not** fire at a terminal contact vertex. That disposes of the hazard raised at
`M6-DEFN-R5-R4-DIAG-NEXT` without amending RA-38.

## 2. R4-REV-01 — the trace point carries no incidence at all

This is decisive and it is not a matter of interpretation:

```cpp
struct SurfaceTracePoint {
  int face = -1;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
};
```

(`include/directional/geometry/SurfaceCellTracing.h`.) There is **no source vertex, no source edge**, and `face`
is a **raw `int` row index**, not a `SourceFaceTopologyKey`. Two consequences:

- **The witness cannot be derived from a trace point.** Recovering "this endpoint is incident to source vertex 1"
  from `barycentric` means testing a `double` for exact zero. In a pipeline that exactifies binary64 inputs
  bit-for-bit (M4-CP-COND) and derives topology only from typed authority, inferring topological incidence from
  floating-point coordinates is an **RP-01 AUTHORITY_DOMAIN_CONFLATION**: typed authority derived from a
  non-authoritative representation. It is prohibited, not merely fragile.
- **The diagnostic is untyped.** `faceEnds=0,2|0,3` is a tuple of **raw row indices**. That is exactly why the
  component-local versus original numbering question arose at all, and why a contamination reading was plausible
  before `MeshComponents.cpp:72-116` settled it. The record must be re-emitted in typed
  `SourceFaceTopologyKey` terms.

**The authority already exists — on the rail producer, not the trace point.** `SurfaceCellRail` publishes
ordered `sourceVertices`, and `SurfaceCellRailSample` publishes `sourceFace`, `sourceEdge`, `parameter` and
`railParameter`. So the terminal source vertex (1 or 4 for carrier `(1,4)`) and the typed source incidence the
witness needs are **already computed and already published** one structure away from the consumer that cannot
see them.

This is the **fifth** occurrence of the same pattern — RA-34.3 (τ retained before the nontraversable marking),
RA-35 (per-wedge bindings before the sort/unique collapse), RA-38 (the star is traversed; only the cut was
missing), RA-40 (the atlas sits in options but not at the factory boundary), and now the rail's typed source
incidence sitting beside a consumer that reads an untyped trace point. The cure is the same: **publish or reach
what the producer already holds.** The germ itself needs no new input either: it is the arc of the A2b vertex
star after cutting the incident rails, and that star is already traversed at
`src/geometry/SurfaceCellTracing.cpp:18120-18206`.

## 3. R4-REV-02 — option (A), and my conditional exception is withdrawn

I proposed scoping RA-40.1's atlas mandate to products carrying A3-derived values, on the premise that a product
with no rails has "nothing A3-derived to authenticate." That premise does not survive inspection of what `make`
actually receives:

- `sourceFaceBranchRotations` is a plain `std::vector<int>` — a **raw, unauthenticated gauge input**, consumed by
  A6 seam logic. I flagged it as needing explicit treatment; it in fact **refutes** the premise, because a
  rail-free product still carries unauthenticated gauge.
- `SurfaceIsolationSeamTransportCertificate` and `SurfacePeriodicHolonomy` are factory-validated **classes** with
  their own `make`, so they are not field-fabricable like the plain-aggregate `SurfaceHardRailFieldTransition`.
  That is a genuine distinction, but it establishes internal consistency, **not A3 provenance** — the same
  gauge-invariance gap one level down.

So "nothing A3-derived" is not established for an arbitrary product, and I asserted it without verifying the
surface. **Withdrawn.**

The decisive consideration is where the exception would actually apply. The 34 failures arise because a
**production** path permits null-atlas ingress (the `CrossFieldResult` overload's legacy/raw acceptance, with
`SurfaceCellTracingOptions::fieldTransportAtlas` defaulting `nullptr`). A conditional exception would let that
production path keep building phase-front products with **no A3 binding at all** whenever they happen to carry
no rails — preserving in production the exact hole RA-40 was created to close, in order to accommodate legacy
callers. Accommodating the defect is not a trust boundary.

**Option (A).** RA-40.1 stays unconditional: `make` requires a `matches_source_faces`-bound atlas always, and the
legacy callers migrate. The atlas is already available at the A4 options level and the check is cheap, so the
migration is mechanical. Two consequences are accepted deliberately rather than worked around:

- The seven DCEL failures are **fixture defects to fix, not cases to exempt.** A test fixture that is not a valid
  mesh is not a valid source authority, which is RA-40's whole point.
- `sourceFaceBranchRotations` comes **inside** the boundary: it must be validated against published source
  authority (at minimum, cardinality equal to the source face count, and values matching what the authority
  publishes). It may not remain a raw unchecked vector under a rule whose purpose is authenticating A3-derived
  input.

## 4. RA-42 (frozen by this Review)

- **RA-42.1 — terminal contact ownership.** The terminal rail contact witness is authored by the **rail/front
  producer** from `SurfaceCellRail::sourceVertices` and the rail samples' typed `sourceFace`/`sourceEdge`, and
  published as typed authority on the endpoint certificate. The endpoint certificate must **stop reading**
  `from.face`/`to.face` for contact purposes.
- **RA-42.2 — no incidence from geometry.** Deriving source-vertex or source-edge incidence from
  `SurfaceTracePoint::barycentric`, or from any floating-point predicate, is **prohibited**. Absent typed
  incidence the certificate fails closed with a code naming that absence.
- **RA-42.3 — typed diagnostics.** Carrier, face and endpoint diagnostics are emitted in typed
  `SourceFaceTopologyKey` terms, never bare row indices. Raw-row records are not evidence of a topological claim.
- **RA-42.4 — germ derivation.** The germ is the arc of the A2b vertex star at the terminal vertex after cutting
  the incident hard rails, derived from the star traversal that already exists. Equality with the carrier's
  incident pair holds **at the contacts**, never at the trace endpoints — the exact locus of RA-39.1's error.
- **RA-42.5 — RA-40.1 unconditional.** The atlas mandate is **not** scoped or conditional. The prior conditional
  pre-commitment is withdrawn. Legacy and `CrossFieldResult` null-atlas ingress must be migrated, not exempted.
- **RA-42.6 — gauge inside the boundary.** `sourceFaceBranchRotations` must be validated against published
  source authority and may not remain unchecked.
- **RA-42.7 — RA-38.3 scope.** RA-38.3's boundary-vertex and singleton STOP governs multi-carrier
  through-junction sector transport only and does not fire at a terminal contact vertex.
- **RA-42.8 — no runtime credit.** Nothing here establishes a produced witness. The 39-row family remains one
  carrier configuration with **zero** multi-carrier instances, so RA-41.2's junction clauses stay unexercised,
  and R4's multi-carrier STOP is undischarged.

## 5. Verification limits

Re-read from source: `SurfaceTracePoint`, `SurfaceCellRailSample` and `SurfaceCellRail` field sets;
`make`'s parameter list including `sourceFaceBranchRotations`; that
`SurfaceIsolationSeamTransportCertificate` and `SurfacePeriodicHolonomy` are factory-validated classes.
Carried from earlier turns, independently re-derived there: the component-local vertex mapping, the germ splits
at vertices 1 and 4, and the one-step `(1,5)` contact walk. **Not** established: whether those two factory
classes' own `make` binds A3 — they are therefore treated as unproven for provenance, not as authenticated.
