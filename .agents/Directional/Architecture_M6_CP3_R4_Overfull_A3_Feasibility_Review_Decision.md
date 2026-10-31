# M6-CP3-R4 — overfull-A3 feasibility, and the authority seam beneath it: Review decision (RA-48)

**Turn:** `M6-CP3-R4-OVERFULL-A3-FEASIBILITY-ARCH-REV` (independent Review).
**Adjudicates:** the carried "independent overfull-A3 feasibility Review" gate, raised in
`Architecture_M6_CP3_R4_Factory_Incidence_Oracle_Source_Validity_Static_Audit_20261011.md` and restated in
`Architecture_M6_CP3_R3_A3_Trust_CB_TB_Gate_Review_Request.md` §§ on the `overfull-hard-feature-edge` guard.
**Also resolves:** the beacon/durable authority inconsistency over the already-frozen RA-47.
**Verdict:** the witness is **unconstructible through every existing call site**; the obligation is
**CONDITIONALLY RETIRED** coupled to named guards; the A4 guard is **KEPT fail-closed**; and two new findings
are frozen — **R4-OVF-01** (an unvalidated authority seam beneath the atlas's documented "only validation
seam") and **R4-OVF-02** (the oracle cannot separate the predicate it is supposed to exercise).
**Method:** re-derived from repository bytes at `6692ce457`. No binary built, no test executed, no runtime credit.

---

## 1. What the obligation actually requires

`SurfacePhaseFrontProduct::make` counts, for every published hard-feature edge, the **actual** source-face
incidences taken from the A2b product — `sourceTopologyRegions.regions()` → `region.faces()` →
`member.topology.vertices()` (`src/geometry/SurfaceCellTracing.cpp:8177-8198`) — and rejects
`count == 0 || count > 2` (`:8202-8207`). The guard deliberately does **not** consult the lossy two-face
adjacency cache, so it is the one place in the stack that can observe a third incident triangle.

To discharge the `> 2` branch non-vacuously a fixture must reach `:8202` with a count of 3. The gate it must
first pass is the RA-40 atlas binding at `:8072-8079`: a **non-null** `FieldTransportAtlas` that satisfies
`matches_source_faces(sourceFaces, sourceTopologyRegions, sourceVertexCount)`.

---

## 2. The witness is unconstructible through every existing call site

The chain is closed and does not depend on orientation choices:

1. **The atlas has exactly one construction seam, and it takes a `TriMesh`.**
   `include/directional/authority/FieldTransportAtlas.h:837-841` — `static FieldTransportAtlasBuildResult
   make(const TriMesh &sourceMesh, ...)`. There is no other constructor, no friend, no test seam. Its own
   class comment (`:830-834`) states "Construction is the only validation seam."
2. **The atlas's edge table is read from `sourceMesh.EV`/`EF`.** `src/authority/FieldTransportAtlas.cpp:1016-1023`
   builds `sourceEdgeRow` by scanning `EV` rows, and `:1029-1030` reads `EF(sourceEdge, 0)`/`(.,1)`.
   `EF` is **2-column by construction** (`include/directional/core/TriMesh.h:165`), so the overfull condition
   has no representation in the atlas at all.
3. **`TriMesh` construction throws on a three-face edge.** `set_mesh` calls `compute_edge_quantities`
   (`core/TriMesh.h:339-340`), which runs `dcel.check_consistency(verbose, true, true, true)` and **throws
   `std::runtime_error`** on failure (`:160-163`). The second argument is `checkHalfedgeRepetition`.
4. **Check 5 rejects it, by pigeonhole.** `core/DCEL.h:1453-1492` fails on any repeated **directed** halfedge.
   Three triangles sharing one undirected edge contribute three halfedges along it, each directed one of two
   ways; at least two therefore coincide in direction. The rejection is independent of how the three faces are
   oriented.
5. **The DCEL could not have represented it either.** `core/DCEL.h:3029-3048` finds twins through a
   `std::set` keyed on the directed pair, and an equivalent-key insert is a no-op, so a third halfedge never
   acquires a twin and would receive its own `edges` entry — the overfull edge would appear as *two or three
   distinct edge rows*, not one row with three faces. The atlas's `sourceEdgeRow.emplace` (`:1022`) would then
   silently keep the first and drop the rest.
6. **The atlas cannot be built elsewhere and swapped in.** `matches_source_faces`
   (`src/authority/FieldTransportAtlas.cpp:3090-3109`) ties `rowTopology_.size()` to `sourceFaces.rows()` and
   each `rowTopology_[row]` to `sourceAuthority.topology_for_row(face)`. The stored row topologies *are* the
   face vertex triples, so an atlas built on a manifold mesh cannot match an overfull `sourceFaces`; and an
   identical triple set is the identical mesh, with identical incidences.

**Therefore the `> 2` branch at `:8204` is unreachable with a non-null source-matched atlas, through every one
of the 116 existing `set_mesh` call sites.** This is the RA-46 shape: a negative-test obligation carried for a
condition that is structurally unrealizable. It is **retired** — conditionally, per §4.

**Corollary, and a correction to the prior audit's framing.** The static audit worried that the fixture "may
still pass at the wrong first predicate" or that `set_mesh` "throws for this nonmanifold source," and called
both unobserved. The second is not a risk to be measured — it is a **theorem** of checks 3-5 above. And the
existing `AdaptiveFeatureMapPhase11.BoundaryAndNonManifoldAreClassified` three-triangle edge is not a latent
witness: `AdaptiveFeatureMap` works on raw `V`/`F` and records `hasNonManifold` (`AdaptiveFeatureMap.h:220-224`)
without ever constructing a `TriMesh`, which is exactly why that source can be classified yet can never reach
A3 or A4.

---

## 3. R4-OVF-01 — the unvalidated authority seam beneath the "only validation seam"

`set_mesh` does **not** always validate. `include/directional/core/TriMesh.h:331-345`:

```
if (_EV.rows() == 0) { compute_edge_quantities(verbose); }
else { EV = _EV; FE = _FE; EF = _EF; }
```

When a caller supplies an edge table, `compute_edge_quantities` — and with it `dcel.init` and
`check_consistency` — is **skipped entirely**. Nothing then checks that the injected `EV`/`FE`/`EF` correspond
to `F`. `FieldTransportAtlas::make` consumes that `TriMesh` as authoritative A1 source topology.

Two consequences:

- **The atlas's documented invariant is inaccurate as written.** "Construction is the only validation seam"
  (`FieldTransportAtlas.h:830-834`) holds only for a `TriMesh` whose edge table it also derived. Handed an
  injected one, the atlas validates adjacency, cycles and singularities against a **fabricated** edge table,
  and `matches_source_faces` cannot detect it because it compares face rows only (`:3094-3108`).
- **§2's unreachability rests on a guard one argument away from being disabled.** The entire proof above runs
  through step 3, and step 3 is conditional on the 2-argument form.

**No current caller uses the injection form.** All 116 `set_mesh` call sites across `src/`, `include/` and
`tests/` pass `(V, F)` only — which is precisely why this seam has never been noticed, and why it must be named
now rather than discovered by the first fixture that reaches for it to build the §2 witness.

This is RP-01 `AUTHORITY_DOMAIN_CONFLATION` at the bottom of the stack: a derived table accepted as authority
without validation against the datum it is derived from. It is also the eighth-family pattern again — the atlas
*reaches for* `EV`/`EF` rather than deriving what it needs from `F`, so it inherits whatever the caller put
there.

---

## 4. RA-48 — FROZEN

**RA-48.1 — the obligation is RETIRED as unrealizable, conditionally.** No fixture is to be built for the
`count > 2` branch at `src/geometry/SurfaceCellTracing.cpp:8204`, and none may be synthesized by relaxing
manifold or incidence rules. Retirement is **coupled** to four guards; if any is weakened the obligation
revives automatically and this clause lapses:
  - **G1** `set_mesh` runs `compute_edge_quantities` on the 2-argument form (`core/TriMesh.h:339-340`);
  - **G2** `compute_edge_quantities` passes `checkHalfedgeRepetition = true` and **throws** on failure
    (`core/TriMesh.h:160-163`);
  - **G3** DCEL check 5 rejects repeated directed halfedges (`core/DCEL.h:1453-1492`);
  - **G4** `FieldTransportAtlas::make` is the only construction seam and takes a `TriMesh`
    (`FieldTransportAtlas.h:837-841`).

**RA-48.2 — the guard itself is KEPT, fail-closed.** `:8202-8207` is **not** dead code to be removed. It is
the only check in the stack that can observe an incidence the atlas's 2-column `EF` cannot represent, and under
R4-OVF-01 it is the sole backstop for an injected edge table. Removing it, or demoting it to a comment, is
prohibited. Its **`count == 0` branch keeps its obligation in full** — that branch is reachable and is a
different predicate.

**RA-48.3 — R4-OVF-01 is a defect, and the seam must be closed.** `set_mesh`'s injection branch must either
validate the supplied `EV`/`FE`/`EF` against `F`, or be removed. Until one of those lands, the injection form
must not be used to construct any source handed to `FieldTransportAtlas::make`. The atlas's "only validation
seam" comment must be corrected in the same change — a doc comment asserting an invariant the code does not
enforce is itself a defect, because later review will rely on it (this review nearly did).

**RA-48.4 — R4-OVF-02: the oracle cannot separate the predicate.** Four distinct predicates in `make` return
the identical bare `InvalidSourceAuthority`: the RA-40 atlas gate (`:8077`), the malformed-edge-key branch
(`:8190`), the incidence guard — **both** `count == 0` and `count > 2` collapsed into one site (`:8204`) — and
the terminal-contact presence check (`:8210`). An `InvalidSourceAuthority` result therefore proves nothing
about *which* check fired. Even had the §2 witness been constructible, the obligation could **not** have been
discharged non-vacuously. LESSONS-160, "passed versus did not run."

**RA-48.5 — the diagnostic collapse is now a PATTERN, not an instance.** This is the third site after
R4-A3U-01's two (`unique_terminal_star_path`'s bare `bool` at `:8352`, collapsed at `:8527-8528`). The
consumer side already demonstrates the correct shape, with three separated diagnostics at `:19071-19074`.
**RA-46.6's typed factory sub-code is hereby a PREREQUISITE** for any future incidence-guard coverage, not an
independent item: a sub-code is required to distinguish atlas-gate, bad-key, zero-incidence, overfull-incidence
and missing-contact rejections before any of them can be claimed as exercised. Extending it to the `:8204`
and `:8210` sites is added to that work.

**RA-48.6 — what may and may not be claimed.** It may be said that the overfull condition is unrealizable at
the A4 factory under G1-G4, and that the guard is retained as a fail-closed backstop. It may **not** be said
that the guard was exercised, that nonmanifold source handling was verified, or that A2b rejects malformed
source first — A2b's behaviour was not examined by this review and remains unestablished. The
`overfull-nonmanifold-spoke` guard at `:19232` and the `overfull-hard-feature-edge` predicate at `:18768` are
**separate** code paths on the producer side and are **not** adjudicated here; they keep whatever obligations
they already carry.

**RA-48.7 — no credit.** No binary built, no test executed. R4-OVF-01 and R4-OVF-02 are source-level review
findings, **not** counted stable regressions: ledger stays **66 events / 17 categories / 49 recurrences**,
debt **1**. CP2 **491/491** accepted, R3 **403/497** rejected, 94 RED, 88 accepted CP2 losses. RA-47, RA-46,
RA-45, RA-44 (less .2), RA-43 (less .5 and less the superseded `sourceEdges` row), RA-42 as corrected, RA-41
frozen scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates all stand unchanged.

---

## 5. Authority reconciliation: the beacon had no recorded basis

The second half of the reported block is a straightforward contradiction, resolved on the evidence:

- Every durable document says RA-47 is adjudicated and `M6-CP3-CB1-ENTRY-R4` may resume with successor
  `M6-CP3-TB1-ENTRY-R4` — `Architecture_M6_Frozen_Definitions.md` (RA-47 head), `Future_Chat_Session_Handoff.md`,
  `ORIENTATION.md`, and the RA-47 decision, all frozen at `1350a2a79`.
- `STATUS` said `BLOCKED / Successor: UNKNOWN`, set by `6692ce457` ("record R4 transport blocker and preserved
  WIP"). That commit changed **`STATUS` only** — one line. It records no blocker, preserves no WIP, and cites
  no finding; no accompanying document exists.
- The four commits since the RA-47 freeze (`74170c022`, `4b5dc2c74`, `06a36e7e6`, `6692ce457`) contain **no
  source change and no decision record**: a STATUS flip, a snapshot trigger file, a mailbox report, and a
  second STATUS flip.
- The "transport blocker" is contradicted by its own receipt: `.workflow-mailbox/repo-source-snapshot/latest.json`
  records run `38249080586` with `"result": "success"` at `2026-10-12T12:27:47Z`, **before** the beacon was set
  to `BLOCKED`.

A beacon that contradicts durable authority **without a recorded basis is not authority**; the frozen
documents are. The beacon is corrected to `COMPLETE` for this review turn with successor
`M6-CP3-CB1-ENTRY-R4`, and RA-47 implementation resumes unblocked. Nothing in the reported external incident
bears on this: no evidence connects it to any repository state, and the one transport receipt in evidence is a
success.
