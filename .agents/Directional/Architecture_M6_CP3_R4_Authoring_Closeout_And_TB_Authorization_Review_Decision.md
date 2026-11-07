# RA-55 — R4 Code + Build authoring CLOSED; Test + Benchmark authorized, narrowly

**Turn:** `M6-CP3-R4-AUTHORING-CLOSEOUT-ARCH-REV` (Architecture Review only).
**Adjudicates:** `M6-CP3-CB1-R4-OHF01-PROBE` and `M6-CP3-CB1-R4-RP02-WITNESS`.
**Disposition:** both **ACCEPTED**. Every decisive claim re-derived from repository bytes at `1e0e13a38`;
no report taken on trust. **No runtime credit is conferred by this Review.**

The interval's entire diff is one test file (`tests/SurfaceCellsPhase10Tests.cpp`, +89/-2), two evidence
documents, and the handoff / CHANGELOG / TODO / STATUS beacons. No production source, no header, no
selector, no harness, no ledger. That is exactly the authorized scope.

---

## RA-55.1 — OHF-01's answer (b) is CONFIRMED on the checked construction path

The probe answers **(b) UNREACHABLE**, which is the answer I warned must not be fabricated. It was not.
Each link was re-derived:

- **G1 — `set_mesh` cannot skip derivation.** `include/directional/core/TriMesh.h:331-350`:
  `compute_edge_quantities(verbose)` is called **unconditionally** at `:339`, before the injected-table
  comparison at `:340-350`, which throws `"set_mesh(): injected edge topology disagrees with faces"` on any
  mismatch. Supplied `_EV/_FE/_EF` are therefore a *claim to be checked*, never an input that is trusted.
- **G2 — the repeated-directed-halfedge check is enabled, and the pigeonhole is exact.**
  `compute_edge_quantities` calls `dcel.check_consistency(verbose, true, true, true)` at
  `TriMesh.h:159-163`, throwing on failure. The signature at `include/directional/core/DCEL.h:1164-1169`
  places **`checkHalfedgeRepetition` second**, so that call enables it; the two omitted trailing
  parameters also default to `true`. Section 5 at `DCEL.h:1453-1492`, guarded by `if (checkHalfedgeRepetition)` at `:1456`, keys a `std::map` on
  `(source, target)` and returns `false` on the second appearance. Three triangles incident to one
  undirected edge contribute three directed halfedges across only two possible directions, so two must
  coincide. The rejection is orientation-independent. **Sound.**
- **G4 — the atlas pin genuinely precedes the census.** `SurfacePhaseFrontProduct::make` rejects with
  `AtlasSourceMismatch` at `src/geometry/SurfaceCellTracing.cpp:8137-8145`; the `railIncidenceCounts`
  construction is at `:8243-8266` and the overfull/absent emission at `:8270-8277`. Ordering confirmed.
  `FieldTransportAtlas::matches_source_faces` (`src/authority/FieldTransportAtlas.cpp:3090-3110`) requires
  `sourceAuthority.matches_source_faces(sourceFaces, sourceVertexCount)` **and** compares `rowTopology_`,
  `rowRegions_` and `rowComponents_` row-by-row against that authority, so `sourceFaces` must be the
  atlas's own construction faces. A foreign-mesh atlas cannot authenticate the input.

**G5 is correctly demoted.** The report explicitly declines to rest on `build_surface_cell_network`'s
own `sourceIncidences > 2` rejection, on the ground that the factory is independently callable. That is
the right reasoning and it is the distinction I asked for.

## RA-55.2 — the retirement is CONDITIONAL, and the condition is sharper than the report states: `R4-OHF-02 / UNCHECKED_MESH_PROVENANCE`

The probe's own caveat — *"public `TriMesh` matrices are mutable, so this source-only conclusion covers
the documented checked construction path"* — is honest and is the reason the answer is accepted rather
than disputed. I record the condition precisely, because the retirement is coupled to it:

**G3 is the soft link, not G1/G2.** `FieldTransportAtlas::make`
(`src/authority/FieldTransportAtlas.cpp:1893-1912`) accepts a `const TriMesh &` and validates the edge
tables **by shape only** — `EV.cols() != 2 || EF.cols() != 2 || EV.rows() != EF.rows()`. It never re-runs
`DCEL::check_consistency`, and it consumes `sourceMesh.EF(edgeIndex, 0..1)` as the adjacency authority,
so a third incident face is not *rejected* at that read — it is simply absent from a two-column table.
Whether the downstream `MissingAdjacency` / `NonReciprocalAdjacency` checks would then catch such a mesh
is **not established by this Review and must not be asserted**.

Therefore the unreachability of `OverfullHardFeatureIncidence` rests on the convention that every
production `TriMesh` is built through `set_mesh`, not on a type-level invariant: `V`, `F`, `EV`, `EF` are
public and mutable, and no constructor forbids assembling one directly.

**Consequences, all binding:**

1. The requirement to author a factory negative for `OverfullHardFeatureIncidence` is **RETIRED**,
   coupled to G1, G2, G4 **and** to `R4-OHF-02`.
2. The guard at `SurfaceCellTracing.cpp:8270-8277` and the `OverfullHardFeatureIncidence` sub-code are
   **RETAINED** unchanged. The guard is the only thing standing between `R4-OHF-02` and a silently
   accepted non-manifold carrier, and it is fail-closed.
3. `R4-OHF-02` is **recorded, not chased.** Probing it would be a seventh Code rung invented to avoid the
   execution boundary, which RA-54.7 forbids. The risk is contained by (2).
4. Any change that makes a `TriMesh` reachable by production code without `set_mesh`, or that relaxes
   G1/G2/G4, **reopens reachability** and requires a non-vacuous witness before merge.

## RA-55.3 — the RP-02 witness MEETS the anti-vacuity bar; here is the decisive byte

The bar I set was: *the assertion must fail if the whole consumer is skipped.* It does, and the reason is
structural rather than circumstantial:

**Exactly one site in the entire file assigns a `HardRail` boundary kind.** `edge.boundaryKind = *kind`
and `edge.railId = railId` at `src/geometry/SurfaceCellTracing.cpp:12619-12620` sit inside
`assign_open_front_boundary_authority` (`:12414-12625`). The only other two `boundaryKind` assignments in
the translation unit — `:14745-14746` and `:18629-18630` — write `PeriodicCut` and nothing else. Reaching
`:12619` requires surviving the network-bound `rail_interval_refs` call at `:12425-12428`
(`options.fieldAlignedNetwork`, `RailIntervalAuthorityMode::RequireTypedSource`), which returns
`InvalidFrontBoundaryAuthority` at `:12429-12431` on any non-`Valid` status.

So a published `SurfaceFrontEdge` with `boundaryKind == HardRail` **is itself the consumer's receipt**.
`ASSERT_NE(consumedRail, nullptr)` cannot pass if the consumer is skipped, and it is not an A2a
publication assertion, not a call the test makes itself, not a stage-injected run, and not a factory-only
rejection. All four prohibited shapes are avoided.

The test strengthens this beyond the minimum: every consumed `sourceEdges` key is independently resolved
through `fixture.fieldNetwork->find_mandatory_edge(key)` with `EXPECT_EQ(rail->id, mandatory->rail)`, and
`edge.filledCell` is required to resolve to a published cell. That binds the receipt to the *real*
network rather than to the edge's own self-report.

## RA-55.4 — the negative's anchor is genuinely discriminating, and I quantified it

`InvalidFrontBoundaryAuthority` is a heavily shared reason code, so `EXPECT_EQ` on it alone would prove
almost nothing. The test does not rely on it alone. A full scan of
`src/geometry/SurfaceCellTracing.cpp` finds **66** `set_phase_front_failure` sites naming that reason, of
which **only 4** supply a cell/side (`:13052`, `:14784`, `:17439`, `:17448`); `set_phase_front_failure`
defaults `cell = -1, side = -1` (`:11330-11335`) and is first-failure-wins (`:11336-11338`).

The test's `EXPECT_GE(failure->cell, 0)` with `side ∈ [0,4)` therefore **excludes 62 of the 66** literal
sites outright. Of the four anchored ones, `:13052` and its siblings test owner-cell lookup and
`filledSide` range — conditions a `sourceEdges` substitution does not perturb — leaving the consumer's
own propagation (`:13063-13067`, and the matching wrappers at `:14790`, `:17412`) as the live locus. The
anchor is doing real work.

**Caveat, stated rather than hidden:** the negative's expectation is *authored and compiled, never
executed*. If at runtime the forgery is caught by an earlier stage, this test fails — which is the
correct failure direction, and is a TB finding, not an authoring defect.

## RA-55.5 — the test-helper override is minimal and weakens nothing

`build_fixed_plan_rectangular_hard_rail_network` gains one defaulted trailing parameter
(`const std::vector<SurfaceCellRail> *rails = nullptr`) and one line
(`options.authoritativeRails = rails != nullptr ? *rails : fixture.rails;`). Every pre-existing call site
is byte-identical in behaviour. No guard was weakened, no counter added, no production API touched. Under
RA-52.6 read forward — *a retained guard needs a retained attempt* — a test-side affordance whose only
purpose is to feed the guard a forgery is exactly the right construction.

## RA-55.6 — CORRECTION to RA-54.2 (my own prior acceptance)

In RA-54.2 I wrote that `SurfacePhaseFrontSourceAuthorityDetail`'s seven values "cover exactly the
reachable predicates." With OHF-01 answered **(b)**, that is now one value too generous:
`OverfullHardFeatureIncidence` is **not reachable on the checked construction path**. The correct
statement is **six reachable predicates and one fail-closed-only sub-code**.

This does **not** reopen RA-51.7, which forbids *minting* a sub-code for a disjunct already known dead.
When RA-46.6 minted this one, its reachability was an open question — the question OHF-01 was
commissioned to answer. The sub-code stays, for the reason in RA-55.2(2). The correction is recorded
rather than quietly amended, per `RP-03`.

## RA-55.7 — R4 Code + Build authoring is CLOSED, verified rather than reported

RA-54.7 left exactly two authoring items. Both are discharged: OHF-01 by a coupled retirement, RP-02 by a
witness that meets its bar. I confirmed by inspection that no third item was left open and that nothing
outside the authorized scope moved. **The Implementation Agent's refusal to invent a further Code rung is
correct and is accepted.**

## RA-55.8 — Test + Benchmark is AUTHORIZED, in two rungs, narrowly

The source-only vein is exhausted and the authoring vein is now exhausted too. Continuing to withhold
execution would convert a boundary into a stall, so execution is authorized — but not as one monolith.

**TB-A, first and small — `M6-CP3-TB1-R4-WITNESS-EXEC`.** Execute **only** the authored-but-never-executed
witnesses, as a named supplemental run **outside** the frozen 497, exactly as the four RA-40(C)
supplementals sit outside it. The frozen selector files stay byte-identical; the harness pins their
hashes at `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh:211-217` and re-checks
them at `:270-272`. This rung answers one question: **does roughly ten turns of authoring survive first
contact with a running binary?** Nothing larger is worth measuring until it does.

**TB-B, only after TB-A — `M6-CP3-TB1-R4-497-EXEC`.** Re-measure the frozen `30 + 12 + 449 + 6 = 497`
gate against current HEAD, to establish whether R3's 94 RED has moved. This is the milestone-bearing
measurement and it must not be folded into TB-A: a mixed run makes a supplemental failure
indistinguishable from a selector regression.

**Neither rung may edit source to obtain green.** A RED in TB-A is a finding to report, not a defect to
patch inside the same turn; the fix is a separately authorized CB turn under Review. A RED in TB-B is the
R4 recovery measurement and is expected to be nonzero.

## RA-55.9 — no credit conferred

No source, test, header, selector, harness, fixture, benchmark or ledger changed in this Review. Ledger
**66 / 17 / 49**, M6 debt **1**, selector **497** untouched, CP2 **491/491** accepted, R3 **403/497**
rejected with 94 RED and 88 carried CP2 losses, PR #8 draft/open — all unchanged. A compile is not a
restoration (LESSONS 160); a census is not a witness (LESSONS 171); an authored expectation is not a PASS.
