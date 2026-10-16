## RA-71 — frozen definitions, M6 CP3 R6 corner-assignment authority (2026-10-16)

**Authority:** `.agents/Directional/Architecture_M6_CP3_R6_Corner_Assignment_Authority_Spec_Review_Decision.md`.
Adjudicates `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` (rung 10); **ACCEPTED** with
two charges. Semantic source unchanged at `a143af264bc8b33f0e1b2f8def16b2479b53d5fc`.

- **RA-71.1 Provenance re-derived.** Snapshot run `38837317846` `conclusion=success` at
  `c85bd3600`; artifact `12019178209` ZIP SHA-256 **recomputed**
  `37dab2b2f1292e7f0a530042b90be1d9813ee4e7eb4e76df7cd50226c2e98bdb`, matches; manifest
  **5,656 OK / 0 BAD**; `src`/`include`/`tests` **tree-identical at `c85bd3600`,
  `a143af264` and `HEAD`**. Documents only; no source, test, header, selector, workflow or
  benchmark change. Tree-object identity is the decisive statement: the specification read
  exactly the bytes compiled at rung 8 and measured at rung 9.
- **RA-71.2 RA-70.14 is WITHDRAWN, falsified on its own named falsifier (a).** The measured
  44 are rejections; `src/geometry/SurfaceCellTracing.cpp:19801-19803`
  (`if (network.phaseFront.is_rejected()) { return network; }`) returns before `:19814`'s
  `make_surface_cell_proposal`, so `:11269` and `:10479` are **unreachable on the measured
  path**, and `:19790` sits inside the `is_produced()` branch at `:19781`. The `:11269`
  reasoning remains true of that fallback and explains nothing about `RP-01`.
- **RA-71.3 The reviewer-supplied three-writer census was wrong by type conflation.**
  `include/directional/geometry/SurfaceCellTracing.h` declares an identically-typed
  `std::array<SurfaceTracePoint,4> corners` on **two different structs** — `:1719`
  `SurfacePhaseFrontCell` and `:2160` `SurfaceCellProposal`. All three nominated writers
  (`:10479`, `:11269`, `:19790`) write `proposal.corners`, i.e. **`SurfaceCellProposal`**,
  not the field A4 judges. The sole writer of `SurfacePhaseFrontCell::corners` is
  `:12986-12987` `cell.corners[corner] = points[nodeIds[corner]];`. An unfiltered census
  returns exactly four `corners` assignments in the file. **This is the error class charged
  at RA-67.13 and RA-70.8, committed by the reviewer one rung after freezing it.** The
  method was blind twice over: the first census grep excluded `cell\.corners\[static_cast`
  to filter reads, which removes the real write, and the "unfiltered" grep required
  `=[^=]` while `:12986` ends its line with `=`.
- **RA-71.4 LESSON — an enumeration is only as bounded as the filter that produced it.** A
  census presented as exhaustive inherits every blind spot of its query, and a reviewer who
  hands a successor a bounded list converts their own filter into the successor's search
  space. **State the query, not just its result**, so a successor can falsify the boundary
  rather than work inside it.
- **RA-71.5 Named locus, verified line by line.** The planar lattice point-to-source-face
  selection in `point_on_source` (`:11477-11509`), made authoritative for corner faces by
  `build_uniform_phase_front_for_faces` at `:12949-12958` and `:12986-12987`, with no
  reconciliation against `boundaryPaths`. Chain: planar producer called first at
  `:17884-17890` (annulus only on `NotApplicable`; the fixture is planar-and-rectangular);
  `point_on_source` loops `activeFaces` and on the **first** successful barycentric
  containment does `point.face = face; return true;`, with no reference to side, path, cell
  or route; `:12949-12958` fills `points[node_index(u,v)]` **once per lattice node**, so one
  face choice is shared by every side and cell touching that node and is made **before any
  path exists**; `:12986-12987` copies it into the corner; `:13012-13021` builds
  `boundaryPaths[side]` separately via `segment_on_source`; `:13033-13035` derives
  `edge.from`/`edge.to` from the corners. This explains the RA-70.7 asymmetry directly —
  `from` and `to` are **different lattice nodes**, each independently first-matched, and
  only the node on the shared junction vertex has more than one admissible face.
- **RA-71.6 This is an ordering dependency, not a tolerance defect.** `:11483` sets
  `constexpr double tolerance = 1.0e-10`, containment admits `[-tolerance, 1+tolerance]`,
  and `:11495-11501` snaps `|b| <= tolerance` to exactly `0` and `|b-1| <= tolerance` to
  exactly `1`. A lattice point lying **exactly on a shared source vertex** satisfies the
  test in **every incident face** — vertex 4 is a corner of `f0, f1, f3, f4, f6, f7` — so
  **the winner is decided purely by `activeFaces` iteration order**. Therefore **(a) no
  epsilon change can repair this**, because the vertex genuinely belongs to every incident
  face and only *near*-vertex ambiguity responds to tolerance; and **(b) the attribution is
  complete without identifying the winning face**, since any order-dependent corner face is
  the defect.
- **RA-71.7 The reconciler exists and is blind — third instance of the pattern.**
  `orient_and_validate_phase_front_cell` calls `validate_closed_boundary_paths` at `:12718`
  **and again** at `:12736`. Inside it (`:7319-7357`), `valid()` applies a **bounds** check
  `point.face >= 0 && point.face < faces.rows()` and never an identity check, while
  `close()` is a pure 3D distance test
  `(point_position(a) - point_position(b)).norm() <= tolerance`; the corner/path comparison
  is `close(start, corners[side])` and `close(end, corners[(side+1)%4])`. **A corner in
  `f7` and a path endpoint in `f3` at the same physical vertex pass at distance exactly 0.**
  The comparison that would have caught `RP-01` is made twice and cannot see the defect.
  **Generalization, now frozen:** at RA-68.3 the junction certificate existed but was
  ordered after the admission it would authorize; here the reconciler exists but compares
  position where identity is required — **when a missing authority is sought in this
  pipeline, look first for it existing in a form that cannot do the job.** Informational:
  `valid()` uses `faces.rows()` not `face_count()`, the RA-66.6 locus, unchanged.
- **RA-71.8 Falsifiers (c) and (d) settled, not assumed.** (c) does **not** hold — the only
  pre-A4 corner/path check is positional, per RA-71.7. (d) does **not** hold —
  `reverse_phase_front_cell_cycle(cell)` at `:12730` permutes the cycle and recomputes
  positions without rewriting any corner's `face`, and no other writer of
  `SurfacePhaseFrontCell::corners` exists. The attribution survives all four of its own
  named falsifiers.
- **RA-71.9 CHARGE — a mandated verification was omitted and not disclosed.** The turn was
  instructed to run **both** gates and report both; the closeout table carries a
  `review_check.py boundary` row and **no `ledgers` row**, and the absence was not declared.
  **RA-66.4 category — a mandated item silently dropped — therefore a repeat.** Both gates
  were run by this Review and both pass; the defect is the silence, not the state. Minor,
  not charged: `review_check.py` invoked without `-I`.
- **RA-71.10 CHARGE — the turn under-claims its own completed attribution, and this is now a
  pattern.** The specification calls the per-vertex choice "the reviewable attribution, not
  an executed new measurement", reading as a confession of incompleteness; its own evidence
  completes it per RA-71.6. **Third consecutive turn in this category** — RA-67.9 (harvested
  interval fields never examined), RA-70.7 (path identity and `hit_from` left unstated), now
  RA-71.10. **Recorded as a pattern, not an isolated lapse:** the measurements have
  repeatedly been stronger than the claims made about them. The failure mode is
  conservative, which is preferable to the opposite, but it costs a rung each time.
- **RA-71.11 Credits.** It **falsified a reviewer prediction and a reviewer-supplied census
  in the same turn**, on the merits, explicitly declining to name `:11269` "merely because
  it discards one of two corner walks" — **`RP-03` satisfied a seventh consecutive turn**.
  It stated **four explicit falsifiers** for its own attribution, all four settleable from
  source, which is what makes the attribution reviewable. It refused to claim a push it
  could not verify from inside a snapshot. Guidance, not a charge: the closeout `CHANGELOG`
  row names `.agents/Directional/CHANGELOG.md` while **root `CHANGELOG.md` is canonical** —
  practice is correct (the Review writes the root ledger), the row should name its file.
- **RA-71.12 `RP-01` state.** Advances from *producer locus localized* to **producer locus
  NAMED AND VERIFIED**: the corner's source face is selected per **lattice node** by
  first-match over `activeFaces` in `point_on_source` (`:11477-11509`), made authoritative
  for `SurfacePhaseFrontCell::corners` at `:12949-12958` / `:12986-12987`, while the
  designated reconciler `validate_closed_boundary_paths` (`:12718`, `:12736` →
  `:7319-7357`) compares corner against path by 3D position and is blind to face identity.
  **Code is still NOT authorized**, because the RA-65.5 producer test has not been applied
  to the repair family. `RP-02` remains **UNREACHED**.

### Rung 11 scope — `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC`, documents only

1. **Apply the RA-65.5 producer test to the repair family.** Enumerate every witness a
   repair needs and name its existing publisher. Already published: `activeFaces` plus the
   barycentric containment test yields the *admissible* face set at a node;
   `boundaryPaths[side]` segments carry `segment.face`. This may be the first repair family
   whose witnesses all already exist — state the outcome either way.
2. **Settle per-node versus per-side.** A lattice node is shared by up to four sides and
   four cells and `:12949-12958` makes **one** choice for all of them. If their traced paths
   lie in different faces, no single per-node face can satisfy every consumer and the repair
   is **structural** — a per-side corner face or an explicit reconciliation pass — not a
   selection-order fix.
3. **State what a face-identity check at `:12718` would and would not achieve.** It would
   **relocate** the failure from a late A4 `carrier-orientation` rejection to an honest
   cell-production rejection at the true producer. **It would not repair `RP-01`.** No later
   rung may mistake relocation for repair.

### Accounting

Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen selector **497** —
unchanged. `R4-VIN-01` remains armed at `a143af264`; artifacts `11994726341`,
`11996317553`, `12005034654`, `12010485442` and `12019178209` are **baselines, never
comparands**; the 44 RED are the baseline for `a143af264` alone, candidate / non-stable.
**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. Gate C SUSPENDED
(RA-65.5, RA-68.3) and moot for `RP-01` (RA-70.11).** `PROCESS-01` discharged.

---

## RA-69 and RA-70 — frozen definitions, M6 CP3 R5 route/path reconciliation (2026-10-16)

**Authority:** `.agents/Directional/Architecture_M6_CP3_R5_Route_Path_Reconciliation_Review_Decision.md`.
Adjudicates `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` (rung 8) and
`M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` (rung 9); **both ACCEPTED**.
Semantic source `a143af264bc8b33f0e1b2f8def16b2479b53d5fc`.

### RA-69 — the probe (rung 8)

- **RA-69.1** A diagnostic emission is decision-neutral only when neutrality is
  **structural**. Verified by brace accounting: rejection branch opens
  `src/geometry/SurfaceCellTracing.cpp:19360`, insertion sits at depth 2, branch closes
  `:19566`, junction construction resumes `:19567`. `42 0` on one file. No acceptance
  path can observe the probe.
- **RA-69.2** The only `return` statements in the insertion are lambda-local — the
  `std::find_if` predicate and the early exit of `append_traced_faces`. Nothing writes
  `phaseFrontState`, mutates a certificate, or constructs a rejection string.
- **RA-69.3** Absence is published as absence. `missing-cell`, `missing-side` and `none`
  are emitted as distinct sentinels and parsed as incomplete. **RA-66.4 is not repeated.**
- **RA-69.4** The compile chain is closed **by content**: packaged
  `src/geometry/SurfaceCellTracing.cpp` hashes to `16615b23581a7ab2…`, equal to the
  `a143af264` blob and to `HEAD`; packaged `tests/SurfaceCellsPhase10Tests.cpp` equals
  `HEAD` at `7c88a51373ca…`. Package `12015849679` ZIP SHA-256 recomputed `92a014a6d0bc…`,
  28/28 manifest, `source-commit.txt = a143af264…`, `runtimeExecution=false`,
  `exactArithmeticBackend=GMP`, preflight/build exits `0`/`0`, five `source-status-*`
  snapshots empty, eight targets, GMP and GMPXX both linked. Snapshot `48ba0b6b1` is
  tree-identical to `5be5e123e` on `src`/`include`/`tests`.
- **RA-69.5 CHARGE — chat-retained evidence is not provenance.** A non-standard source
  transport (Google Drive staging failed twice; GitHub Git-objects API fallback) is
  **settled harmless by content** at RA-69.4. What is charged is citing "a downloadable
  preservation patch retained in this chat" as a preservation store. Under RA-61.5 a claim
  is provenanced when it is re-derivable from repository bytes or an immutable artifact;
  a chat attachment is neither addressable nor hashable by a successor. The landed blob is
  the preserved object.
- **RA-69.6** Informational: the probe's `std::find_if` over `phaseFrontState.cells` is
  O(rejections x cells). Diagnostic-only, **not authorized for optimisation**, recorded so
  no later turn inherits it into a non-diagnostic path.
- **RA-69.7** The self-disclosed `READ_MODE` ordering defect is procedural; **credited as
  disclosure, not charged**, and establishes no semantic result.

### RA-70 — the harvest (rung 9)

- **RA-70.1** The instrument compares inside one index domain. `hit_to` is
  `sum(bool(t and e <= t) for e in edges)` — a **subset test of the route edge's vertex
  pair against the ToAttachment face's vertex triple**, the definition of edge-face
  incidence. Path faces are parsed as row indices and compared only to row indices.
  Carrier edges derive as `c & d` with `len(carrier)==2` asserted.
- **RA-70.2** Fail-closed via `if missing: raise SystemExit`, with `complete` requiring
  `n>0`, `len(actual)==n`, contiguous `indices==list(range(n))`, 2-element edges, all eight
  derived values present. **The RA-67.8 charge is discharged on the route fields** —
  every emission is collected and `occurrences_consistent` requires agreement; a
  `probe_occurrences` column now exists. The charge was consequential: dispatch
  `38831159326` is independently `conclusion=failure`, was refused and disclosed when the
  retry would have concealed it. **`RP-03` satisfied a sixth consecutive turn.**
- **RA-70.3** Residue, bounded then **measured**: `get()` is still first-match for the
  nine non-route fields, so `hit_to` mixes a first-match `t` with a consistency-checked
  `edges`. `probe_multiplicity=[(1,42),(3,2)]`; both multi-emission identities are
  **controls**, so no junction case is exposed; and in both logs the full probe payload is
  byte-identical across all three emissions. Harmless by measurement; **open as a
  narrowing to close.**
- **RA-70.4** Result artifact `12017109271`: ZIP SHA-256 recomputed `e394c4deab99…`,
  81,938 bytes, internal manifest **51 OK / 0 BAD**, `manifest-before` byte-identical to
  `manifest-after`, 44 raw logs. `execution-boundary.txt` =
  `planned=44 executed=44 red=44 missing=0 postflight=true exit=0`,
  `compile=false relink=false benchmarks=false selector497=false`; `immutability.txt` all
  `true`; harness SHA-256 `64a6bb67a02e…` equal at working tree and executor `c46615bcc`.
- **RA-70.5** Partition re-derived from the TSV: exactly three tuples, 44 rows, all
  `COMPLETE`, `routeStepCount=1` and `a2bProbeFailure=no-exact-terminal-corner` universal.
  23 controls `(route 1,4; toFace 3; path 0/3; hit_to 1)`, 15 junction
  `(route 1,4; toFace 7; path 0/3; hit_to 0)`, 6 junction
  `(route 1,2; toFace 7; path 0/3; hit_to 0)`. `hit_to` separates the populations
  **perfectly and without exception**.
- **RA-70.6** **RA-68.9 CONFIRMED; the named falsifier did not occur.** 21 of 21 junction
  cases have no route step incident to the `to` face; 23 of 23 controls do.
- **RA-70.7 CHARGE — the result is under-claimed, and the discarded half is the half that
  localizes it.** Unreported: `FirstPathFaces=0` and `SecondPathFaces=3` are **identical in
  all 44 rows**, and `hit_from=1` **universally**. Because path, route, step count, carrier
  edge and `from` corner are measurably identical across the populations that pass and fail
  incidence, the tracer, route publisher, carrier producer and `from` corner are all
  exonerated by the same measurement, isolating the defect to one field on one side.
  Same category as RA-67.9; **a repeat.**
- **RA-70.8 CHARGE — one edge printed in two index domains, one rung after that lesson was
  frozen.** The report tabulates two route topology keys `(1,4)` and `(1,2)`; its own
  `route-path-summary.txt` partitions into **two** tuples with the 21 undivided, and the
  RA-67.5 first-appearance compaction (`4→2, 2→4, 7→6, 6→7`) maps every measured triple
  exactly: `0,1,4↦0,1,2`, `4,7,8↦2,6,8`, carrier `1,4↦1,2`, route `1,4↦1,2`. Both
  populations are the same suite `SurfaceCellAuthorityContractCutover`. One phenomenon,
  two vertex index domains — **RA-67.5 independently corroborated on fields that did not
  exist when it was derived**, and **RA-67.13 not applied where it changes a reader's
  count.**
- **RA-70.9 Mechanism, re-derived from fixture bytes** (`tests/SurfaceCellsPhase10Tests.cpp:223-273`):
  `f0=(0,1,4) f1=(0,4,3) f2=(1,2,5) f3=(1,5,4) f4=(3,4,7) f5=(3,7,6) f6=(4,5,8) f7=(4,8,7)`;
  hard edges `(1,4)` and `(4,7)` share vertex 4; so edge `{1,4}` is incident to `{0,3}` and
  `{4,7}` to `{4,7}`. The route's single step is `{1,4}` and the traced paths visit exactly
  `{0}` and `{3}` — the two faces of the crossed edge. The corner declares `to` in
  `f7=(4,8,7)`, the far face of the **other** hard edge, sharing only vertex 4. So
  `oriented_carrier` is asked for `((0,1,4),(4,8,7))`, whose intersection is a lone vertex,
  not an edge; no edge-keyed carrier can exist (RA-67.6) and `carrier-orientation` fails
  first in all 21. In the controls `ToAttachment=1,4,5=f3` is the genuine second face, a
  carrier exists, and rejection falls through to `not-same-interior-carrier-point` in all
  23. **The corner walked around the junction; the path did not.**
- **RA-70.10** Shapes A and B are now **the wrong family, not merely unbuildable**. The
  publisher published a correct single-step route for the path it crossed; the consumer
  correctly refused a face pair sharing only a vertex. A repair at either locus would make
  the pipeline accept an endpoint that is simply wrong.
- **RA-70.11** Gate C gains a third and more basic ground: a vertex-star sector certificate
  at the consumer would authorize admission of a corner naming a face the path never
  visited. **No consumer-side authority can repair a wrong corner.** Gate C remains
  **SUSPENDED** and is additionally **moot for `RP-01`**. No vertex-star predicate may be
  implemented.
- **RA-70.12** `RP-01` advances to **producer locus localized**: the assignment of
  `SurfacePhaseFrontCell::corners[(side+1)%4].face`. `corners` is
  `std::array<SurfaceTracePoint,4>` (`include/directional/geometry/SurfaceCellTracing.h:1719`)
  and `SurfaceTracePoint` carries its own `int face` (`:90-93`), which is where
  `a2bProbeToFace=7` originates while `boundaryPaths` yields `{3}`. **Code NOT authorized.**
- **RA-70.13 LESSON** — **the controls' agreement is half the result.** A perfectly
  separating measurement says what differed and what did not; the second half performs the
  localization, because every column that agrees exonerates the producer behind it. State
  the null half explicitly.
- **RA-70.14 Rung-10 prediction, with falsifier and observation rung named.** At
  `src/geometry/SurfaceCellTracing.cpp:11258-11271` two walks reach one corner; the code
  keeps `xy.point`, discards `yx.point`, and reduces the disagreement to
  `closureError = max(closureError, (xyPosition - yxPosition).norm())` against
  `options.closureToleranceFactor * min(hx, hy)`. **Prediction:** a face-index disagreement
  is invisible to that test, because a position on the shared junction vertex is
  representable in several faces at zero positional error, so the corner silently takes the
  first walk's face. **Falsifier:** the rejected cells do not reach `:11269`, or a face
  comparison guards it — then `:10479` or `:19790` is the locus. **Observation rung:** rung
  10, by static reading. A prediction with provenance (RA-61.5) and its rung named
  (RA-64.12); it does **not** revive RA-64.6, which the publisher's exoneration refutes.

### Rung 10 scope — bounded corner-assignment authority

`src/geometry/SurfaceCellTracing.cpp` has exactly **three** producers of a cell corner
array: `:10479` the primary aggregate from four traced points; `:11269` the per-corner
override from a two-way closure walk; `:19790` the propagation copy. Rung 10 is a
**documents-only Definition turn** over these three loci and the `boundaryPaths` producer.

### Accounting

Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen selector **497** —
unchanged. **`R4-VIN-01` re-arms at `a143af264`**: every earlier artifact, including
`11994726341`, `11996317553`, `12005034654` and `12010485442`, is a **baseline, never a
comparand**; the 44 RED are the baseline for `a143af264` alone, candidate / non-stable.
`RP-01` producer locus localized, code NOT authorized. `RP-02` **UNREACHED**. `RP-03`
satisfied a sixth consecutive turn. `PROCESS-01` discharged. RA-61.9 WITHDRAWN, final.
RA-64.6 WITHDRAWN, final.

---

## RA-68 — `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC-REV`, 2026-10-15 (frozen)

Decision: `.agents/Directional/Architecture_M6_CP3_R5_Junction_Carrier_Authority_Spec_Review_Decision.md`.
Adjudicates `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC`: **ACCEPTED**. One understated-scope
charge, minor. No open REVIEW_BLOCKER. No promotion, no stable event, no regression recurrence, no
gate credit. **Neither repair shape is admitted; the turn reached the strongest outcome available by
refusing to pick one.**

- **RA-68.1** **The specification read the measured bytes, provable by tree object.** `src`,
  `include` and `tests` are **tree-identical at `5be5e123e`, the entry commit `825a04bc8` and HEAD**
  — `src=fd09300ba38b…`, `include=790328c2bc…`, `tests=cbef8d5ec4…`. The spec's "GitHub commit
  comparison" understates what the tree objects settle outright. The R5 snapshot verifies: artifact
  `12010485442` at `3d1b413a8` (run `38814059292`), **outer ZIP SHA-256 recomputed on the downloaded
  bytes as `020bc02980fb661d4b4bdc0f26de3b74c91887a6dad43a100ab3391bea4dc62e`, matching the provider
  digest; 5,648 manifest entries; `shasum -c` returns 5,648 OK, 0 BAD.** The RA-67.10 practice was
  carried forward unprompted.
- **RA-68.2** **Mandate 1 discharged — independent derivation, correct narrow scope.** The spec
  confirms RA-67.6 for the **first rejection** of the 21 measured junction identities, not for all 44
  REDs and not as a repair. Every cite verified: `tests/SurfaceCellsPhase10Tests.cpp:266-273` (two
  hard edges `(1,4)` and `(4,7)` sharing vertex 4), `:223-263` (faces `{0,3}` and `{4,7}`),
  `include/directional/geometry/SurfaceCellTracing.h:1481-1489` (edge-keyed, two face keys, one
  `QuarterTurn`), `src/geometry/SurfaceCellTracing.cpp:18939-18973` (producer), `:19097-19105`
  (`find_carrier` selects by edge), `:19106-19114` (`oriented_carrier` matches the complete pair in
  either order). The spec states unprompted that neither the sector, nor a truncated route, nor a
  correction is established, and that **RA-64.6 remains withdrawn**.
- **RA-68.3** **Mandate 2 discharged, and the producer test has real teeth — a sharper gate-C
  objection than the reviewer's.** `SurfaceHardRailRouteJunctionCertificate` **exists**
  (`SurfaceCellTracing.h:1512-1516`, `SourceVertexId junction` plus two `sectorPaths`; member of
  `SurfaceHardRailRouteCertificate` at `:1518-1526`) and is **ordered too late to authorize
  admission**: its construction at `src/geometry/SurfaceCellTracing.cpp:19525-19530` opens with
  `auto previous = firstEndpoint->terminalCarrier;` and its publication at `:19728-19731`
  dereferences `*firstEndpoint, *secondEndpoint`, both reachable only past the rejection branch at
  `:19352-19360`. At RA-65.5 the ground was that no producer publishes a vertex-star witness; the
  spec finds that a producer of something very like it **does** exist and is unusable by position.
  **Gate C stays SUSPENDED, now on ordering as well as nonexistence**, which survives the rebuttal
  that the junction certificate already exists.
- **RA-68.4** **Mandate 3 discharged — falsifiers concrete, populations exact.** Re-derived from the
  immutable TSV: junction indices `12-25, 34, 35, 36, 39, 40, 42, 43` = **21**; interior indices
  `1-11, 26-33, 37, 38, 41, 44` = **23**; historical ordinals 17 + 4 supplemental = 21. **The
  `routeLength=1` obstruction is real** — verified in the raw logs, with no other value anywhere. A
  one-step route carries a single carrier, so a mechanical split at its endpoint cannot manufacture a
  second carrier: the naive split-only variant of shape A is **falsified by measurement**.
- **RA-68.5 (CHARGE, minor — understated scope)** **`routeLength=1` holds for all 44, not only the
  21.** Two consequences the spec does not draw: the obstruction is **stronger** than claimed, since
  a one-step route is universal across the measured population; and the 23 **do not control for this
  property** — they stay valid negative controls for the attachment-membership partition, which is
  what they were nominated for, but a control sharing the property under test cannot discriminate on
  it. No later turn may cite the 23 as evidence that `routeLength=1` is junction-specific.
- **RA-68.6 (NEW)** **A boundary hard rail publishes no carrier at all.**
  `src/geometry/SurfaceCellTracing.cpp:18939-18941` skips any edge with `incident->second[1] < 0`, so
  a hard edge with one incident face yields **no `SurfaceHardRailFieldTransition`** and
  `find_carrier` returns `nullptr` rather than a non-matching record. Shape B must therefore treat
  carrier **absence** as a case distinct from carrier **mismatch**. The measured 21 are all interior
  junctions, so nothing in the harvest exercises it. Locus recorded; **no repair authorized**.
- **RA-68.7 (NEW)** **The published face pair is canonically ordered, closing the cheapest
  rebuttal.** `:18968-18970` sets `reverseCanonical = to < from` and pushes the smaller key first, so
  `record.firstFace` is always the lexicographically smaller face key. `oriented_carrier`'s two-branch
  test is therefore **complete** — no orientation case is unreachable and no ordering bug hides
  behind the refusal — and the measured `CarrierFirstFace=(0,1,4) < CarrierSecondFace=(1,4,5)` is the
  canonical form, confirming the harvest read the real published record.
- **RA-68.8** **Mandate 4 discharged without hedging, and `RP-03` holds a fifth turn.** §4 declines
  to select A or B, define a type, approve a route extension, authorize splitting, modify a
  predicate, classify sectors from rows, revive RA-64.6 or RA-61.9, resume gate C, treat the 21 as
  two mechanisms, promote `RP-01`, or claim `RP-02` reached. **Asked to apply a test both candidates
  could fail, it reported that both failed rather than softening.** It also absorbed RA-67.9 into its
  own §1 — "All 44 have reciprocal exact interval ordinals, proving that this condition does not
  distinguish the failures" — one rung after the charge, in its own analysis.
- **RA-68.9** **What the next measurement must settle, and why it precedes a producer definition.**
  Both shapes lack a producer, so a producer-definition turn is the obvious move and is **the wrong
  one**, because one cheap observation can still change which producer is needed. Put RA-68.4 beside
  **RA-65.10**: the route has **one** step, and the publisher cannot shorten a route — at a topology
  change `assign_open_front_boundary_authority` either publishes a second step (`:12642`) or
  hard-rejects (`:12645`, `:12669`) — so the traced path crossed exactly one source-edge topology.
  But the endpoints are **not taken from the path**: `edge.from = cell.corners[side]`,
  `edge.to = cell.corners[(side+1)%4]` at `:13034-13035`, `:14774-14775`, `:17345-17346`, and
  **nothing reconciles the corner array against the path's face set**. The measurement puts `to` in
  face 7, incident to `(4,7)`, `(7,8)` and `(4,8)` but **not** to `(1,4)`. **Prediction:** the
  route's step edge set will contain no edge incident to the `to` endpoint face — making this a
  **corner/path reconciliation defect at A4**, upstream of the consumer, for which neither shape A nor
  shape B is the right family. **Falsifier:** if the route's step edge set does contain an edge of
  face 7, the hypothesis is wrong, corner array and path agree, and the producer-definition turn
  becomes correct. Observation rung named: `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` then its
  harvest. **This does not revive RA-64.6** — that claimed the publisher *truncated* a route; this
  says the publisher may have published a correct route for its path and been handed an endpoint from
  elsewhere. Recorded as a prediction with provenance stated (RA-61.5) and its rung named (RA-64.12),
  **not as a finding**.
- **RA-68.10** **Beacon, documents and scope.** Documents only; `src`, `include`, `tests`,
  `benchmarks`, `cmake`, `.github` and every selector untouched. All five edited documents are **pure
  insertions, zero deletions** — handoff +12, `TODO.md` +8, `ORIENTATION.md` +6, root `CHANGELOG.md`
  +4, `.agents/Directional/CHANGELOG.md` +4. Beacon `COMPLETE`, six fields, `Successor: UNKNOWN`
  **with reasoning in the owning document** (spec line 60, repeated in `TODO.md`) — the RA-63.13
  shape, **no defect**; `Successor:` was not self-named while in progress, applying the RA-67.11
  correction. The tracker was not updated, which is **correct** for a definition turn; it is updated
  by this Review.
- **RA-68.11 accounting.** Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen
  selector **497** — unchanged. `R4-VIN-01` armed; `11976790988` and `11967601999` are baselines,
  never comparands; the 44 RED are the baseline for `16c3134c0` alone, candidate / non-stable.
  `RP-01` **measured, mechanistically derived, and now bounded on both repair families — code still
  unauthorized**; `RP-02` **UNREACHED**; `RP-03` satisfied a **fifth** consecutive turn;
  `PROCESS-01` discharged. **RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED
  (RA-65.5), now on ordering as well as nonexistence (RA-68.3).**
- **RA-68.12 (LESSON)** **An inadmissible answer is a result.** The turn was asked to apply a test
  both candidates could fail, and both failed. Its value is that it closed two doors without opening
  a third and said so plainly, rather than promoting the less-bad option. "Neither, and here is the
  witness each one lacks" advances the work further than a winner that cannot be justified.
- **RA-68 disposition.** Successor **`M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE`**, compile-only
  and rejection-only. The producer-definition turn is **deferred behind it**, because RA-68.9's
  observation can still change which producer is needed.

---

## RA-67 — `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST-REV`, 2026-10-15 (frozen)

Decision: `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Harvest_Review_Decision.md`.
Adjudicates `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST`: **ACCEPTED**. One latent instrument defect,
verified harmless for this measurement; one reporting omission. No open REVIEW_BLOCKER. No promotion,
no stable event, no regression recurrence, no gate credit.

- **RA-67.1** **The result package is closed by bytes.** Run `38782417387` `success`,
  `headSha 8e8cf1cfa`; result artifact `11996317553` (80,281 bytes). **ZIP SHA-256 recomputed on the
  downloaded bytes — `44df6e2fc1bdba1e15f81e11ddec7bbb6cc90e2d43adcda4f334d875d1dbd9c9` — matches
  the provider digest.** Manifest **re-verified, not read**: **51 OK, 0 BAD** across 52 files.
  `execution-boundary.txt`: `executed=44`, `red=44`, `missing=0`, `postflight=true`, `exit=0`,
  `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`. `ledger.tsv` 44 RED, no
  `NOT_SELECTED`, no `NOT_EXECUTED`. `manifest-before` ≡ `manifest-after` at 28 OK each — the
  immutable package was not mutated across execution. Note: `planned=44` is a **literal** in the
  harness `finish` printf (`:11`), true only because `:120` asserts it before `exit=0` is reachable;
  read `exit` before `planned`.
- **RA-67.2** **The harness pins the new package, and the old one was not reused.** Harness SHA-256
  independently recomputed as `5b13f121bd678ec975e9c4d00df3685e79893eff8f7f9f42f980402b9b955fab`,
  identical to the dispatch pin. It pins `11994726341` and `5be5e123e`; `11976790988` appears nowhere
  — the RA-66.11 hazard was avoided in fact. RA-61 standard intact and fail-closed: provider digest,
  recomputed ZIP digest, manifest hash and 28-count, source identity, GMP / `runtimeExecution=false`,
  packaged source hash, four frozen selector hashes, three before/after `cmp` inventories, postflight
  manifest, closing `executed==44 && missing==0 && postflight` assertion. Census inventory hash
  `de05a7bd…` re-verified, 39 rows, one ordinal `405` → 38 + 6 = 44. **The harness never asserts the
  verdict** — `red` is counted, never required; population fail-closed, outcome not. The two
  `Phase14` identities are not bundled (one comment occurrence, zero ledger rows).
- **RA-67.3** **The partition table re-derived independently and it holds.** Grouping
  `endpoint-chart-harvest.tsv` on the full tuple yields **exactly three** distinct rows, counts
  **23 / 15 / 6**, all RED, all COMPLETE: 23 interior `not-same-interior-carrier-point`, rows 0→3,
  (0,1,4)→(1,4,5), carrier (0,1,4)/(1,4,5), edge (1,4), **both** attachments, not swapped; 15
  junction `carrier-orientation`, rows 0→7, (0,1,4)→(4,7,8), carrier (0,1,4)/(1,4,5), edge (1,4),
  **one**; 6 junction, rows 0→7, (0,1,2)→(2,6,8), carrier (0,1,2)/(1,2,5), edge (1,2), **one**.
  Intersections check by hand. **The RA-66.7 first-order partition is settled: 21/21 exactly one,
  always the *from* attachment; zero neither, zero both, zero swapped, zero missing keys.**
- **RA-67.4** **RA-66.4 discharged correctly.** The carrier edge is a genuine two-element set
  intersection (`:172`) guarded on cardinality two (`:173`), and the instrument declares it derived
  in its own output — `chart-summary.txt` line 1, `not an emitted field`. Evidence is fail-closed:
  any junction case with an unresolvable key raises `SystemExit` (`:181-182`, `:196-197`).
- **RA-67.5 (NEW)** **The two junction groups are one phenomenon in two vertex-index domains.**
  `make_disconnected_rectangular_feature_pair_mesh`
  (`tests/SurfaceCellsPhase10Tests.cpp:223-263`) emits, per component at offset `k`,
  `f0=(k,k+1,k+4) f1=(k,k+4,k+3) f2=(k+1,k+2,k+5) f3=(k+1,k+5,k+4) f4=(k+3,k+4,k+7)
  f5=(k+3,k+7,k+6) f6=(k+4,k+5,k+8) f7=(k+4,k+8,k+7)`. Relabel a component's vertices by **order of
  first appearance in its face list** (`4→2, 2→4, 7→6, 6→7`) and the Junction-A keys become the
  Junction-B keys exactly: `f0 (0,1,4)→(0,1,2)`, `f3 (1,4,5)→(1,2,5)`, `f7 (4,7,8)→(2,6,8)`, carrier
  edge `(1,4)→(1,2)`, terminal vertex `4→2`. **Six independent confirmations of one mapping.** Face
  rows `0 → 7` coincide across both groups because the compaction relabels vertices and leaves face
  order untouched. The 21 are a single uniform phenomenon observed twice. The report's per-identity
  rows stay valid — membership is computed inside a row and is domain-consistent — but the table has
  no domain column, and a probe printing a `SourceVertexId` without naming its domain makes one
  object look like two. **`RP-01` reproducing inside the instrument built to measure it.**
- **RA-67.6 (DECISIVE)** **The mechanism, exhibited from bytes line by line, and it needs no
  sector.** (1) `add_rectangular_midline_hard_feature`
  (`tests/SurfaceCellsPhase10Tests.cpp:266-273`) inserts **two** hard edges sharing a vertex:
  `{offset+1, offset+4}` and `{offset+4, offset+7}` — component-local **(1,4)** and **(4,7)**,
  meeting at vertex **4**. (2) Edge (1,4) lies in faces **{0,3}**; edge (4,7) lies in faces
  **{4,7}**. (3) The measurement puts the endpoints at **face 0 and face 7** — one face of the first
  hard edge and one of the **second** — with both endpoints at vertex 4 (`fromV=toV=4`). (4) A
  carrier record is **edge-keyed by construction**: `SurfaceHardRailFieldTransition`
  (`include/directional/geometry/SurfaceCellTracing.h:1482-1489`) holds one `SourceEdgeTopologyKey`
  and exactly the two faces of that one edge. (5) `oriented_carrier`
  (`src/geometry/SurfaceCellTracing.cpp:19106-19114`) matches only when
  `{record.firstFace, record.secondFace} == {from, to}` in one order or the other. **Therefore, when
  a front edge's endpoint faces are drawn from two different hard edges, no carrier record can
  contain both and `oriented_carrier` cannot match in either orientation.** The refusal is
  structural, not numerical and not a tolerance. Every premise is a repository byte; the only
  measured input is the endpoint face pair. `RP-01`'s third expression is **demonstrated**, not
  merely located: an edge-keyed authority is being asked a question that is about a vertex.
  **Gate C stays suspended (RA-65.5)** — the measurement confirms the *shape* gate C reached for,
  and confirming that a witness would be apt is not finding its publisher. **No repair is chosen:**
  splitting the front edge at the junction vertex and making the consumer predicate vertex-aware are
  both admissible and differ in which authority gains an obligation. That is a definition question.
- **RA-67.7** **The row pair `{0,7}` does not vindicate the withdrawn RA-64.6.** The same pair arises
  in two index domains, so it is not one object; rows are the least informative field measured, since
  the predicate compares keys; and RA-64.6 claimed a **truncated route**, which nothing shows — the
  publisher cannot shorten a route at all, only reject
  (`assign_open_front_boundary_authority`, `:12481-12692`). A coinciding number is exactly what
  **RA-65.4** warns about. **RA-64.6 remains withdrawn, final.**
- **RA-67.8 (DEFECT, latent — verified harmless here)** **The first-match probe parse.** The
  harvester takes `re.search` over the whole log (`:164`), capturing the **first** emission and
  recording no occurrence count; the probe fires once per rejected edge. Checked rather than assumed:
  `27.log` and `41.log` emit **three** times, the other 42 once; **all three emissions in both are
  byte-identical**, and both belong to the interior 23, so no junction row is affected. Loss nil, the
  **narrowing undisclosed**. Successor instrument must record the per-log emission count and assert
  uniformity, or emit one row per emission.
- **RA-67.9** **Harvested but unanalyzed — and it confirms a struck conjunct.** All 44 show both
  intervals present, `FirstSpan == SecondSpan` (span 3 for the 23 and the 15, span 2 for the 6), and
  **reciprocal reversed ordinals** — `(0/1,1/1)` against `(1/1,0/1)` for the 23, `(3/1,4/1)` against
  `(4/1,3/1)` for the 21. That is **RA-65.6a measured**: the reciprocal-ordinal conjunct holds for
  all 44 **including every RED**, so it cannot discriminate. The strike is confirmed by measurement,
  not only argument. Integer ordinals re-confirm the RA-65.7 locus — the published object is the
  **index**, never the parameter. Charged lightly as **under-reporting**.
- **RA-67.10** **The long-file mutation was verified against an immutable pre-image.** The closeout
  took an exact source snapshot first — run `38805395498` `success` at `393d6c548`, artifact
  `12005034654` — and patched against it. Outer ZIP SHA-256 recomputed as
  `09a865c0e7b6398a2b1dcc6cc3ed839449dd1de0486e81dfb56b2bc6d759e96e`, matching the provider digest;
  inner `source.tar.gz` hashes to `adbc497359822d338a2831aade5e752a70907455f48932accb0783440fbd0225`,
  matching its sidecar and the metadata; **`shasum -a 256 -c SHA256SUMS` over the extracted tree
  returns 5,647 OK, 0 BAD.** **This is the RA-65.1 defect structurally eliminated, not reworded** —
  the snapshot now *contains* a 5,647-line per-file manifest, so the ratio is a real checksum
  verification. Preservation verifies too: the pre-image tracker is **exactly 13,512 lines**, HEAD is
  **13,524**, diff **+12 / −0**, trailing 13,512 lines **byte-identical**. Append-only proven against
  an artifact rather than asserted.
- **RA-67.11** **Beacon and documents.** `Status: COMPLETE`, six fields, `Resumed at:` and
  `Ended at:` populated, `Successor: UNKNOWN` **with reasoning in both the handoff and `TODO.md`** —
  the RA-63.13 shape, **no defect**. The self-reference present while `IN_PROGRESS` was removed at
  closeout and never appeared on a `COMPLETE` beacon, so **RA-64.10 is not charged**; noted only
  because a continuation beacon that names itself cannot be told from a stalled one — write
  `Successor:` empty while in progress. All four touched documents are **pure insertions, zero
  deletions**: tracker +12, handoff +8, root changelog +7, agents changelog +4.
- **RA-67.12** **Prohibitions honored; accounting unchanged.** No C++, compile, relink, new semantic
  source, selector change, 497, benchmark or fixture change; `src`, `include`, `tests`, `benchmarks`,
  `cmake`, `.github` and every selector untouched. No sector, mechanism, repair or root cause
  asserted by the turn — report line 29 and `sector_classification=NOT_INFERRED`. Ordinal 405
  excluded with its reason. `R4-VIN-01` correctly recorded **candidate / non-stable**; `5be5e123e` is
  a new semantic source, so `11976790988` and `11967601999` stay **baselines, never comparands**, and
  the 44 RED remain the baseline for `16c3134c0` alone. Ledger **66/17/49**, debt **1**, CP2
  **491/491**, R3 **403/497**, frozen selector **497** — unchanged. `RP-01` **measured and
  mechanistically derived, code still unauthorized**; `RP-02` **UNREACHED**; `RP-03` satisfied a
  **fourth** consecutive turn; `PROCESS-01` discharged. **RA-61.9 WITHDRAWN, final. RA-64.6
  WITHDRAWN, final. Gate C SUSPENDED (RA-65.5).**
- **RA-67.13 (LESSON)** **Two labels for one object are not two observations.** An identifier printed
  without its domain turns one phenomenon into two rows of a table, and the duplicate then reads as
  corroboration. A measurement must name the index domain of every identifier it prints, or it
  manufactures the appearance of independent confirmation.
- **RA-67 disposition.** Successor **`M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC`**, a definition
  turn, no code.

---

## RA-66 — `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE-REV`, 2026-10-15 (frozen)

Decision: `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Review_Decision.md`.
Adjudicates `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE`: **ACCEPTED**. One silent mandate deviation charged
and recoverable. No open REVIEW_BLOCKER. No promotion, no stable event, no regression recurrence, no
gate credit. **`R4-VIN-01` re-arms at the new semantic source `5be5e123e`.**

- **RA-66.1** **The compile chain is closed by bytes, end to end, and nothing is taken on report.**
  Snapshot run `38775481890` `success`, `headSha 4c114b248` (the pin commit), artifact `11993616345`
  present (24,114,547 bytes). Compile run `38776964197` `success`, `headSha 243a9feb7` (the
  dispatcher request commit), result artifact `11994726341` present (39,026,791 bytes). **ZIP SHA-256
  recomputed on the downloaded bytes —
  `b59dc16f4417693c4aec79025160da2054cfbca3a1589ef051ee3a171d3185bb` — is identical to the reported
  value.** The manifest was **re-verified, not read**: `shasum -a 256 -c SHA256SUMS` over the
  extracted package gives **28 entries, 28 OK, 0 BAD**. Eight targets exactly as claimed;
  `preflight-exit-code.txt` = **0** and `build-exit-code.txt` = **0**; `exactArithmeticBackend=GMP`,
  `runtimeExecution=false`; `source-commit.txt` = `5be5e123e14e2ddab8bb8c0db2a354a0a900435a`.
  **The decisive link:** `src/geometry/SurfaceCellTracing.cpp` *inside the manifest-verified package*
  hashes to `3833d8f4e204f6c202b1e9faa9b3e88da5c1e30a81ccd2b11f24d31408c3f91f`, **byte-identical to
  HEAD's**; the `src` tree is `fd09300ba38b10dfea728c8c3f7c4ed6b732c89c` at both `5be5e123e` and
  HEAD; `5be5e123e`'s parent is the pin commit. `include`, `tests`, `benchmarks`, `cmake`, `.github`
  and every selector untouched; no binary, test, benchmark or 497 executed.
- **RA-66.2** **Decision-neutral by construction, verified structurally rather than asserted.** The
  23 added lines sit at `:19439-19461`, inside the block opened at
  `:19360 if (!firstEndpoint || !secondEndpoint) {`, after the pre-existing `:19438` carrier lookup.
  Every added line declares a local or streams into `endpointEvidence`; no acceptance path can
  observe any of it, because the block is entered only once both certificates have returned. Ladder,
  predicates, `endpoint_certificate` and every rejection string unchanged.
- **RA-66.3** **The turn improved on the mandate in the right direction.** Raw rows were asked for;
  raw rows **and** the canonical attachment keys were delivered — `a2bProbeFromAttachment`,
  `a2bProbeToAttachment`, `a2bProbeCarrierFirstFace`, `a2bProbeCarrierSecondFace`, each a three-vertex
  `SourceFaceTopologyKey` triple. `oriented_carrier` (`:19106-19114`) compares
  `record.firstFace == from && record.secondFace == to` on exactly these keys, so the failing
  comparison is now observable **field against field**, with no row-to-key re-derivation at review
  time and no opening for the reviewer to supply the missing half from imagination. After RA-65.3 that
  is the correct instinct.
- **RA-66.4 (DEFECT, recoverable)** **A mandated field is absent and the omission is
  unacknowledged.** `a2bProbeCarrierEdge` was item 3 of five; `grep -c` returns **0**, and neither the
  record nor the handoff notes the deviation. **The information is not lost:**
  `SourceFaceTopologyKey::vertices()` returns `std::array<SourceVertexId, 3>`
  (`include/directional/authority/AuthorityIds.h:442`), and the carrier edge is the two-element
  **intersection** of the `CarrierFirstFace` and `CarrierSecondFace` triples. The substantive loss is
  nil; **the silence is the defect.** The successor must compute the intersection and say that it
  computed it, never print a carrier edge as though it had been emitted.
- **RA-66.5** **A new dereference, raised and discharged.** The probe adds
  `network.sourceTopologyRegions->topology_for_row(...)`, absent from the RA-63 probe. The enclosing
  function already dereferences that pointer unguarded at `:18967`, `:18968`, `:19048`, `:19050`,
  `:19076`, `:19136`, `:19138`, `:19154`, `:19196`, and `:19076` lies on **every path that reaches the
  probe**. No new crash surface. One divergence exists and it is an improvement: `:19134` requires
  **both** source faces to resolve before either is dereferenced, while the probe guards each
  independently, so a case in which exactly one resolves now reports the half that does.
- **RA-66.6** **The bounds idiom matches the surrounding code, and that idiom is unguarded.**
  `topology_for_row` is not bounds-safe — elsewhere callers test `face_count()` first (`:8941`) — and
  the probe bounds its row through `source_face_id(point.face, faces.rows())` exactly as
  `:19130-19133` does, on `faces.rows()` rather than `face_count()`. **No new hazard**; the
  pre-existing asymmetry between the two extents is a backlog locus and must not be repaired
  opportunistically.
- **RA-66.7** **What the measurement will decide, and what it will not.** The emitted set decides the
  **first-order partition** without inference: whether neither, exactly one, or both of
  `FromAttachment`/`ToAttachment` lie in `{CarrierFirstFace, CarrierSecondFace}`, and if both, whether
  they are swapped. It does **not** by itself decide the sector refinement RA-65.11 named, because the
  rail's *other* incident edges at the shared vertex are not emitted. For these 21 the rail edge set
  is byte-fixed in `tests/SurfaceCellsPhase10Tests.cpp:223-264`, so the refinement is derivable — but
  it must be **exhibited from those bytes, not asserted**. Asserting a sector from a merely consistent
  reading is RA-65.4 one level down.
- **RA-66.8** **The previous charge was absorbed in the turn's own words.** Record line 7 reads
  "5642 source files (**file count, not a checksum-verification ratio**)". RA-65.1 charged exactly
  that misdescription one rung earlier, and the correction appears unprompted inside the new turn's
  own evidence line.
- **RA-66.9** Documents: the handoff was **prepended**, the RA-65 section intact below, and the top
  section declares the one beneath it "preserved as historic pending state". Two CURRENT sections for
  one turn is a readability cost, not a defect, because the supersession is stated in text. `TODO.md`
  likewise prepended. The three commits sharing the message "close endpoint chart compile checkpoint
  with verified GMP evidence" touch **three different files**, so this is not the RA-64.9 retry
  pattern.
- **RA-66.10** Beacon: `Status: COMPLETE`, six fields, `Ended at:` populated, `Successor: UNKNOWN`
  **with reasoning carried in the record** — *"there is no authorized named successor at closeout"* —
  and reinforced in the handoff. The RA-63.13 shape. **No defect.**
- **RA-66.11** **`R4-VIN-01` re-arms, and the old harness must not be pointed at the new fields.**
  `5be5e123e` is a new semantic source and `11994726341` a new package; artifacts `11976790988` and
  `11967601999` are now **baselines, never comparands**, and the 44 RED remain the baseline **for
  `16c3134c0`** only. The record states the hazard about its own instrument before being asked: the
  pinned 44-case harness **pins the old package** and "must not be run against it to claim these new
  fields." Load-bearing — a harness silently measuring the old package would report every new field as
  absent and look like a clean negative.
- **RA-66 accounting.** Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen
  selector **497** — unchanged. `RP-01` located with three expressions, **one in question pending this
  measurement**, not repaired; `RP-02` **UNREACHED**; `RP-03` satisfied a third consecutive turn;
  `PROCESS-01` discharged. **RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED
  (RA-65.5).** Successor **`M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST`**.

---

## RA-65 — `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC-REV`, 2026-10-15 (frozen)

Decision: `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Authority_Spec_Review_Decision.md`.
Adjudicates `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC`: **ACCEPTED WITH AMENDMENT**. Gate C suspended;
gate A's reciprocity conjunct struck; **RA-64.6 withdrawn in full**; RA-64.4's illustration withdrawn,
its conclusion retained. No open REVIEW_BLOCKER. No promotion, no stable event, no regression
recurrence, no gate credit.

- **RA-65.1** Authority re-derived from the provider and from tree objects. Run `38765685488`
  (`Agent Source Snapshot`) `success`, `headSha e87b7a3ad`, matching the cited snapshot commit;
  artifact `11989475541` present (24,087,190 bytes); the log records
  `event_sha = snapshot_sha = final_sha = e87b7a3ad`, `snapshot_file_count=5640`,
  `archive_sha256=5195b468af2fe726f3f526d73a831d3d20813bd52b5635dda5ec7a972d0aaf8b`. **Tree
  identity:** `src` `76a12d4053a5…`, `include` `790328c2…`, `tests` `cbef8d5e…` and the blob
  `src/geometry/SurfaceCellTracing.cpp` `6605c9f9ee8d7fc7859260b389f7fa2de755306f` are
  **byte-identical at `16c3134c0`, at `e87b7a3ad` and at HEAD**, so the specification read exactly the
  bytes compiled into package `11976790988` and measured by the harvest. Two files changed in the
  whole turn — the specification and `STATUS`. **Charged under RA-61.5:** "5640/5640 source hashes" is
  a **file count** presented as a verification ratio; the log verifies no hashes.
- **RA-65.2** **ACCEPTED: the RA-64.6 answer is correct, and the bytes say it more strongly than the
  document does.** `assign_open_front_boundary_authority` cannot silently omit a carrier — `:12570`
  iterates every segment; `:12576-12591` derives the carrier from that segment's own face and
  unsupported corner; `:12594-12597` **requires the segment's face to be incident to that carrier**;
  `:12641-12644` flushes the run on a carrier change; `:12645-12647` rejects a nonconsecutive repeat;
  `:12669` flushes the tail; and **every** failure path returns `InvalidFrontBoundaryAuthority`. A
  two-carrier path yields two steps or no front. Declining to settle whether the *path itself* was
  complete is the correct residue.
- **RA-65.3 (PRINCIPAL)** **The endpoint faces `{0,7}` were never measured, and RA-64.6 is withdrawn
  in full.** The probe emits only `a2bProbeCarrierPresent`, `a2bProbeFailure`,
  `a2bProbeFirstFailedCondition`, `a2bProbeFromSourceVertex`, `a2bProbeToSourceVertex` and the two
  `append_interval` blocks — **no face anywhere in `:19395-19477`**. Source vertex 4 belongs to **six**
  fixture faces (`0,1,3,4,6,7`) and `carrier-orientation` fails for **any** attachment pair other than
  `(0,3)`/`(3,0)`, so `{0,7}` was one admissible reading among many, chosen without warrant and
  reported as measured. **RA-64.4's conclusion survives** — that a face-pair mismatch fires first for
  all 21 is what `carrier-orientation` *means*, and it was measured — **its illustration does not**.
  The specification caught this at its own line 15 and is credited; this is the second consecutive
  turn to correct the reviewer on the record.
- **RA-65.4 (new lesson)** **An explanatory instance is not a measurement: a mechanism that *would*
  produce the observed value is not the mechanism that *did*.** Fifth in the family after RA-61.5
  (provenance), RA-61.7 (satisfiability), RA-63.10 (event counting) and RA-64.12 (reachability):
  **uniqueness**. An explanation must state that no other explanation fits the same evidence, and name
  the measurement that separates them when others do.
- **RA-65.5 (DEFECT)** **Gate C names a witness no producer publishes.** It admits a non-incident
  chart "only through a source-attested, uniquely admissible vertex-star route". The A3 product is
  `SurfaceHardRailFieldTransition` (`include/directional/geometry/SurfaceCellTracing.h:1482-1489`) —
  one source **edge**, its two faces, one quarter turn. There is **no vertex-keyed transition record
  in `include/` or `src/`**; every `vertexStar*` symbol in the tree is a *diagnostics* field
  (`include/directional/diagnostics/RemeshDiagnostics.h:459-477`), not an authority product. That is
  the RA-61.7 satisfiability failure one level up, and precisely what RA-64.11 bound this rung to
  avoid. **Gate C is SUSPENDED** until a successor names the producer or withdraws it. **Gates A, B
  and D stand.**
- **RA-65.6 (DEFECT)** **Two vacuous conjuncts, immediately after RA-64.5 condemned the pattern.**
  (a) Gate A's "exactly reciprocal endpoint ordinals" **cannot be false**: `:17073-17079` mints the
  forward interval as `from_integer(ordinal)`/`from_integer(ordinal + 1U)` and `:17095-17101` the
  reverse as `from_integer(ordinal)`/`from_integer(ordinal - 1U)`, so reciprocity is a **construction
  identity** — stronger than RA-64.5's measured 44/44, because it would hold of any population.
  (b) "Identical … support piece" carries no information: `:17051` rejects any
  `supportPieceIndex != 0U`, so the piece is **0 in every surviving record**. The document warns
  against exactly this and then commits it twice. The one conjunct that works — independent
  per-endpoint exact parameter resolution — is kept; the two decorations are struck.
- **RA-65.7** **The "exposure" the contract asks for is a type change.** `:17047-17060` resolves an
  exact `FieldExactRational` edge parameter from `baseline.breakpoint_location(span, exactOrdinal)`
  (`GlobalConformityBaseline.h:181`, `:216` — the document's citation is **accurate**), and it is then
  destroyed twice: `:16791-16792` casts it to `double` into `SurfaceTracePoint`, whose entire
  definition is `{int face; Eigen::RowVector3d barycentric;}` (`SurfaceCellTracing.h:90-93`); and the
  published `SurfaceSharedBoundaryInterval` (`SurfaceCellTracing.h:1418-1428`) carries the **breakpoint
  index**, never the parameter. **No published type has a field that can receive it.** Recorded, not
  escalated: declining to design the type in a Definition turn was correct, but the successor must
  budget the type change as the substance of the work.
- **RA-65.8** **Reopened: a truncation mechanism sits inside the range the document cited.**
  `append_point` **silently drops** a point when its UV lies within `1.0e-10 * max(1, width, height)`
  of the previous one and returns **`true`** (`:17032-17036`), while the interval is pushed
  **unconditionally** (`:17081`, `:17103`). Points and intervals can desynchronize, and a dropped
  breakpoint can collapse a carrier run out of the path **upstream** of the publisher RA-65.2 cleared.
  **Not demonstrated for the measured 44** — exact integer ordinals on a unit grid — so the
  conclusion for the 44 stands; the general claim holds only of the A4 publisher, not of the pipeline.
- **RA-65.9 (scoped correction)** **`routeLength = 1` is exact only up to 1e-9.**
  `assign_open_front_boundary_authority` carries `constexpr double tolerance = 1.0e-9` (`:12507`) and
  decides in doubles which corner is unsupported and hence **which edge is the carrier**
  (`:12578-12579`), whether a run is long enough to publish (`:12539`), and whether consecutive
  segments connect (`:12655`); `canonical_retained_edge_parameter` returns a clamped `double`
  (`:12509-12531`). Harmless for the measured 44; it undercuts the framing in which the route is exact
  authority while only the endpoint half needs exactness. Backlog locus.
- **RA-65.10 (NEW structural locus)** **The endpoint points are not drawn from the front's own path.**
  `edge.from = cell.corners[side]` and `edge.to = cell.corners[(side + 1) % 4]` at `:13034-13035`,
  `:14774-14775` and `:17345-17346`; the route comes from `cell.boundaryPaths[side]`, whose every
  segment is forced incident to its carrier at `:12594-12597`. **Nothing reconciles the corner array
  against the path's face set.** That absent invariant — not the terminal-contact vocabulary — is where
  gate D's "endpoint incidence" must bite: at **corner-to-path** incidence.
- **RA-65.11** **The decisive measurement costs five integers and now outranks the RA-63.11
  deferral.** Whether `oriented_carrier`'s refusal is a granularity defect or a **correct refusal**
  turns on *which* faces the two corners are charted in — the one fact never measured. Same rail
  sector of the shared vertex ⇒ gate C has something to admit and `RP-01`'s third expression is real;
  opposite sectors ⇒ the endpoint is charted across the feature the rail protects, `oriented_carrier`
  was right, and the defect is **chart selection**, not vocabulary. `fromPoint`, `toPoint`,
  `probeCarrier` and the two compared attachment keys are already in scope in the post-decision block.
  The package at `16c3134c0` was preserved to protect a measurement whose central narrative has just
  been withdrawn; that argument no longer outweighs the measurement.
- **RA-65.12** Beacon: `Status: COMPLETE`, six fields, `Ended at:` populated, `Successor: UNKNOWN`
  **with reasoning carried in the document** — *"An implementation or independent Review successor
  requires separate explicit turn authority; no successor ID is invented here."* The RA-63.13 shape,
  not the RA-64.10 self-reference. **No defect.**
- **RA-65 accounting.** Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen
  selector **497** — unchanged. The 44 RED remain the **`R4-VIN-01` baseline** for `16c3134c0`, never a
  comparand against `11967601999`. `RP-01` located with three expressions, **one now in question**
  (RA-65.11), not repaired; `RP-02` **UNREACHED**; `RP-03` satisfied and exemplified a second
  consecutive turn; `PROCESS-01` tooling residual discharged. **RA-61.9 WITHDRAWN, final. RA-64.6
  WITHDRAWN, final.** Successor **`M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE`**.

---

## RA-64 — `M6-CP3-TB3-R4-PROBE-HARVEST-REV`, 2026-10-15 (frozen)

Decision: `.agents/Directional/Architecture_M6_CP3_R4_Probe_Harvest_Review_Decision.md`. Adjudicates
**two** turns, `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` and `M6-CP3-TB3-R4-PROBE-HARVEST`: **BOTH
ACCEPTED**. No open REVIEW_BLOCKER. No promotion, no stable event, no regression recurrence, no
gate credit. **RA-61.9 withdrawal confirmed by measurement and final.**

- **RA-64.1** Authority re-derived, not accepted. Harvest run `38756316813` `success`, artifact
  `11982824436` present (76,926 bytes); the harness SHA-256 recomputed on disk,
  `bec126c4b4fc835c92de2ae39c6e36295721227549aa6b4ca84178c88fea040a`, is **byte-identical to the
  reported value**, so the harness that ran is the harness committed. Measured against the
  pre-existing immutable package `11976790988` at semantic source `16c3134c0`, already proven
  byte-identical to HEAD's `src` tree at RA-63.1. No compile, relink, selector change, benchmark
  or 497. `src`, `include`, `tests`, `benchmarks`, `cmake`, `.github` untouched across both turns.
- **RA-64.2** **The content floor is implemented and verified by simulation, not by reading.** Four
  throwaway-worktree simulations, nothing committed: **(A)** equal-size whole-file overwrite with
  the marker retained and `## ` sections 302 → 1 — line floor passes `4502 >= 4502`, **heading
  floor FAILS `1 >= 304`: the RA-63.7 defect is CLOSED**; **(B)** legitimate prepend — passes;
  **(C)** three headings replaced by body lines with the **line count unchanged** — **FAILS
  `301 >= 304`**, stronger than specified, catching a partial deletion; **(D)** line *and* heading
  counts and all heading text preserved, body replaced — **passes, the honest residual.** All six
  observed integrity events (RA-63.10) collapsed the file and are caught by (A) or (C). Items 2–4
  landed: the tracker exemption is gone (`review_check.py:238`), both floors assert `> 0` against
  `history_valid` so a total read failure cannot pass vacuously (`:206-211`), the consumed Drive
  descriptor is a no-op. The implementation **improved on the specification** by deriving both
  floors from one blob read per revision. **`PROCESS-01`'s tooling residual is discharged for every
  observed failure mode**; shape (D) needs per-section content hashing and **this Review declines
  to mandate it** — the evidence does not support that scope. Recorded without repair: a durable
  file with no committed history now fails rather than passing as `(new file)`, which is the right
  default.
- **RA-64.3** **The reviewer's recorded prediction was half right and half wrong.** Subset A source
  vertex **`4/4` CONFIRMED** (15 cases); subset B **measured as `2/2`** (6 cases) — *measured, not
  assumed*, discharging the backlog item; but the predicted first failed condition
  `one-hot-carrier-junction` is **FALSIFIED** — all 21 report **`carrier-orientation`**. The error
  is the reviewer's: `one-hot-carrier-junction` is ladder rung 4 and all 21 stop at **rung 3**, so
  the prediction named a *value* without checking that execution would ever *reach* the rung
  producing it. The 23 interior identities report `not-same-interior-carrier-point`, so rung 3
  **passed** for them — the two subsets are separated by exactly one conjunct, independently
  corroborating the 23/21 partition from a direction RA-62 never used.
- **RA-64.4 (PRINCIPAL)** **The first gate to fail is a third expression of the same granularity
  error, re-derived from the fixture with no run.** `oriented_carrier`
  (`src/geometry/SurfaceCellTracing.cpp:19106-19114`) yields a value only when `{from, to}` **is**
  the carrier record's own face pair. Recomputing
  `make_disconnected_rectangular_feature_pair_mesh` (`tests/SurfaceCellsPhase10Tests.cpp:223-264`)
  gives edge `(1,4) -> faces {0,3}` and edge `(4,7) -> faces {4,7}`; the measured endpoint faces
  are **{0,7}**, so **face 7 is not incident to the carrier edge at all** — it belongs to the
  rail's *other* edge. `oriented_carrier` is **structurally unsatisfiable** for subset A, by the
  fixture's own face table, with no execution. **Three expressions of one error now sit in the same
  rejecting conjunction:** (1) rail-level terminal set ← carrier-edge question (RA-62.5, *never
  reached* for the 21); (2) edge-record interval ← endpoint question (RA-63.5, reached and
  satisfied by everything); (3) **single-carrier-edge face pair ← junction-straddling endpoint
  faces — the actual first failure for 21 of 44.** This **reorders the repair**: the
  terminal-contact set is *not* the first thing to fix, because the certificate's prior premise —
  that a front's two endpoint trace points lie in the two faces of **one** carrier edge — is false
  for every junction-terminated front, and no terminal vocabulary rescues a conjunction that has
  already returned `nullopt`.
- **RA-64.5** **The interval witness is satisfied 44/44, which is stronger than the type
  argument.** Both intervals present in all 44, **equal spans** (`3` in 38, `2` in 6), **exactly
  reciprocal ordinals** throughout — `0/1 → 1/1` against `1/1 → 0/1` for the 23, `3/1 → 4/1`
  against `4/1 → 3/1` for the 21 — lossless exact rationals as RA-63.4 required. RA-63.5 argued
  from the field list that this witness *cannot* pin the point; the measurement shows it **does not
  discriminate anything at all**. Stated without inflation: RA-61.9 kept strict interiority, which
  the 21 fail, so it would have admitted **the 23** — on a warrant equally true of the 21 it still
  rejects, with the work done by **interiority, a double comparison**, while an **exact rational**
  was presented as the justification. Worse than the dead gate, which at least failed closed and
  visibly. **RA-61.9 withdrawn, final.**
- **RA-64.6 (NEW)** **The route under-reports the front's extent, and the measurement does not say
  why.** RA-62.8 concluded `routeLength = 1` is a fact about the traced front; that needs
  refinement, because the **geometry already spans the junction** — the route reports **one** step
  (carrier `(1,4)`) while the endpoint faces `{0,7}` require **two** carrier edges. Two readings
  remain open and this measurement decides **neither**: **(i)** the A4 publisher cut a run that
  should have been one route of two steps, so the route is wrong and the trace points right —
  under which the RA-59 two-topology recipe may already be **latently satisfied by the geometry**;
  or **(ii)** a single-step route may legitimately carry endpoint trace points in faces outside its
  carrier, under which RA-64.4 is the whole defect. **Distinguishing them is the first question the
  specification rung must answer, from the publisher's own bytes, never inferred from the type.**
  Neither reading is authorized as a conclusion.
- **RA-64.7** Harness compliance verified against the RA-61 standard: pinned artifact id and source
  SHA, provider and artifact digests, manifest SHA with a 28-OK count, `source-commit.txt`
  identity, `exactArithmeticBackend=GMP` and `runtimeExecution=false` assertions, pinned packaged
  source hash, frozen selector hashes, pre-snapshots, census inventory pinned by SHA with **39
  identities and a duplicate assertion**, ordinal **405** excluded by an explicit `continue` with
  its reason (`:56`), `NOT_SELECTED` paths incrementing `missing` and continuing, `planned == 44`
  (`:120`), three `cmp` immutability checks plus a postflight manifest, and the closing
  `executed == 44 && missing == 0 && postflight == true` with `exit 0` (`:155-156`). 39 − 405 + 6 =
  **44**, matching 23 + 21. **Specific credit** to the extraction parser: it writes an empty string
  for an absent field and sets `probe_emitted = int(any(values))`, so a missing probe is **visible
  rather than synthesized**. Cosmetic residual, not worth a turn: the final `die` message still
  reads `'incomplete interior-witness measurement'`.
- **RA-64.8** **A contradicted prediction was reported plainly.** The harvest reported
  `carrier-orientation` for all 21 — contradicting the reviewer's recorded prediction — **without
  reconciling, hedging or relabelling it**, claimed nothing for the vertex result it did not
  license, kept 405 out of the 44 with its reason stated, called its own RED set an `R4-VIN-01`
  **baseline** rather than a regression, and said *"independent Review required before deciding an
  implementation successor."* This is the standard `RP-03` was opened to obtain; drawing the
  consequence of the contradiction is the Review's job, not the measuring turn's.
- **RA-64.9** The content-floor turn's authorized Drive transport failed
  (`container_session_unavailable`); it fell back to direct repository writes **and disclosed it**,
  volunteering that the downloadable patch's documentation bytes may differ from the written
  records. The three identical `Record R4 Python heading-floor verification…` commits are that
  retry sequence and are harmless. Disclosing a transport substitution and its exact consequence,
  unprompted, is the behaviour this process depends on.
- **RA-64.10** Beacon defect: closed `Status: IN_PROGRESS` with `Ended at:` blank and
  `Successor: M6-CP3-TB3-R4-PROBE-HARVEST` — **the turn naming itself as its own successor**.
  RA-64.1 establishes the measurement completed, so `IN_PROGRESS` is stale, and a self-referential
  successor is **worse than the reasoned `UNKNOWN` accepted at RA-63.13**, because `UNKNOWN`
  signals absence while this asserts a successor that cannot be executed. The report's own prose
  carries the correct content, so this is an **encoding** failure, not a reasoning failure. Closed
  with a named successor.
- **RA-64.11** **The specification is authorized; the code still is not.** Three measured
  expressions of one granularity error, a 44/44 population, two exactly-characterised subsets and
  one named open question are enough to write a specification and not enough to write code.
  `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` may produce a specification and nothing else — no C++,
  no compile, no tests, no instrument change. **Binding obligation, from RA-61.7 sharpened by
  RA-64.12: every proposed predicate must carry its satisfiability witness AND its reachability
  witness against the measured 44** — which identities it admits, which it still rejects, and at
  which rung each is decided. A predicate whose admitting set is not exhibited against this
  population is not a specification.
- **RA-64.12 (new lesson)** **A prediction must name the rung at which it will be observed, not
  only the value it will take.** Fourth member of the family after RA-61.5 (provenance) and
  RA-61.7 (satisfiability): **reachability**.
- **RA-64 accounting.** Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen
  selector **497** — unchanged. The 44 RED are the **`R4-VIN-01` baseline** for `16c3134c0`, never
  a comparand against `11967601999`. `RP-01` located with **three expressions**, not repaired,
  **specification authorized, code not**; `RP-02` **UNREACHED**; `RP-03` satisfied and exemplified;
  **`PROCESS-01` tooling residual discharged for every observed failure mode**, shape-(D) residual
  recorded and deliberately not escalated. Successor
  **`M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC`** — specification only.

---
## RA-63 — `M6-CP3-CB2-R4-PREDICATE-SEPARATION-REV`, 2026-10-15 (frozen)

Decision: `.agents/Directional/Architecture_M6_CP3_R4_Predicate_Separation_Review_Decision.md`.
Verdict **ACCEPTED**. No open REVIEW_BLOCKER. No promotion, no stable event, no regression
recurrence, no gate credit. **RA-61.9 is WITHDRAWN by RA-63.5.**

- **RA-63.1** Compile authority is re-derived from object hashes, never from the report. The
  `src` tree `76a12d4053a5c0798adcb0dce6d5eb8bf4e29623` and `include` tree
  `790328c2bcffe29db5366ea1193cf0ab6d8cba58` are byte-identical at the claimed semantic source
  `16c3134c0`, at the run's `headSha` `276fc267c`, and at `HEAD`; the only commit between them
  touches `agent-dispatch-request.json`. Run `38743048456` `success`, artifact `11976790988`
  present. `tests`, `benchmarks`, `cmake`, `.github`, `include` byte-unchanged from `700d6418f`.
  No binary executed; LESSON 160 holds.
- **RA-63.2** Decision-neutrality is established **by construction**, not by assertion: every
  added line lies inside the post-decision block (`src/geometry/SurfaceCellTracing.cpp:19360`),
  after both certificate calls (`:19354-19359`), and either declares a block-local or streams
  into `endpointEvidence`. No `return`, no predicate write, no epsilon, no relaxation. The
  null-dereference concern on `sourceTopologyRegions` is discharged: the real certificate
  dereferences the same pointer at `:19135-19138`.
- **RA-63.3** Item (b) satisfied. `exact_source_vertex` is exact one-hot with no tolerance and
  reports the vertex or `none`, retiring the RA-62.3 hand derivation permanently. Predicted
  subset-A emission `a2bProbeFromSourceVertex=4;a2bProbeToSourceVertex=4`, **provenance stated**:
  RA-62.3's fixture derivation (`tests/SurfaceCellsPhase10Tests.cpp:223-264`), per RA-61.5.
- **RA-63.4** Item (a) satisfied and lossless. `exact_numerator()`/`exact_denominator()`
  (`FieldTransportAtlas.h:516-517`) return `EInt` (`ExactNumber.h:24`), whose `to_string()`
  exists on both backends (`ENumberGMP.h:61` via `get_str()`, `BigInteger.h:401`). Emitted
  unconditionally, outside the ladder, so the ordinals survive the ladder's early exit.
- **RA-63.5 (PRINCIPAL)** **An edge-level witness cannot identify an endpoint.**
  `SurfaceFrontEdge` (`include/directional/geometry/SurfaceCellTracing.h:1545-1579`) carries two
  endpoints (`:1549-1550`) and exactly **one** `sharedBoundaryInterval` (`:1572`) and one
  `railId` (`:1568`); `endpoint_certificate` is called twice with `first`/`second` captured by
  reference and identical, so the interval-reciprocity conjunct **evaluates the same at both
  endpoints**. It pins the edge pair, never the point. RA-61.9 proposed resting endpoint identity
  on precisely this witness, which would leave the interior branch with no point-level exact
  evidence at all. **The dead gate fails closed; RA-61.9 would fail open.** RA-61.9 is
  **WITHDRAWN** — remedy and falsifier (ii) both — and no successor may implement it. Falsifier
  (ii) needed the record's field list, not a run.
- **RA-63.6** **`RP-01` is a recurring construction habit, not a single site.** Two granularity
  mismatches sit inside the one `if (!terminalVertex)` branch: rail-level terminal authority
  answering a carrier-edge question (RA-62.5, `SurfaceCellTracing.h:1530-1535` consulted at
  `:19213-19220`) and edge-record-level interval authority answering an endpoint question
  (RA-63.5). **Widening an existing published set cannot repair either.** The eventual repair must
  introduce vocabulary at the granularity the question is asked at — per-interval terminal
  contacts (rail intervals already exist and are consulted at `:12610`) and per-endpoint exact
  parameters. **No repair authorized.**
- **RA-63.7** The RA-62.2 integrity fix is a **real improvement that still fails its own
  acceptance test.** The floor is now `max` over committed history (`review_check.py:196-202`),
  so `boundary` **does** now detect a committed overwrite — the entire RA-62.2 hole, closed.
  Measured in an isolated worktree: a 4,468 → 21 truncation **FAILS** the gate (caught), but an
  **equal-size whole-file overwrite** — 4,468 lines of filler, marker retained, `## ` sections
  302 → 1 — returns **`ALL CHECKS PASSED`**. That is `ORIENTATION.md:1853` one level up: **a
  guard that counts lines does not protect content, for the reason a guard that counts markers
  does not.** The marker check was also softened from a count to a presence test (`:203-204`),
  correct in itself but leaving **no** committed check that examines content.
- **RA-63.8** The remedy, with satisfiability **proven before being mandated** (RA-61.7): add a
  `## `-heading high-water floor symmetric with the line floor. Measured — live == high-water
  today for every protected file (handoff **302/302**, ORIENTATION **105/105**, tracker
  **651/651**), it catches the equal-size overwrite (302 → 1), and it catches all three
  historical tracker destructions (`f7add683` 611→1, `0e1909d3` 629→1, `b90c0f84` 648→1).
  **Rejected alternative recorded so it is not re-proposed:** heading-*set* inclusion over all
  history is **unsatisfiable** (24 handoff / 3 ORIENTATION / 1 tracker headings differ, because
  superseded `## CURRENT …` headings are legitimately reworded), and per-step inclusion, while
  satisfiable today, turns red on the next rewording and would train a successor to disable the
  gate. A **count** floor tolerates rewording, rises on every prepend, and cannot be lowered.
- **RA-63.9** The tracker's exemption from zero-tolerance (`review_check.py:224`) is
  **unjustified and inverted**: it leaves the one file destroyed three times as the only
  protected file still permitting a silent ~1,300-line deletion. Measured: the tracker has had
  **zero** shrinks in the 0–10% band across its entire history (all three are >10%). The
  exemption is pure slack; remove it. An append-only ledger tolerates no shrink, and a genuine
  consolidation should fail loudly and be justified in the open.
- **RA-63.10 (new lesson)** **A count of recorded events is not a count of events.** RA-62 called
  the handoff overwrite the *fourth* integrity event; the bytes show at least **six** —
  `ce9bf3cb`, `0043dd4c`, `f7add683` (tracker 11,683 → 8, **recorded in zero durable
  documents**), `0e1909d3` (12,147 → 11, cited for content but never flagged as a destruction),
  `b90c0f84` (12,949 → 6) and RA-62's overwrite. The undercount is the reviewer's: **events that
  had been written down were counted instead of events in the bytes** — LESSON 171 turned on the
  reviewer's own ledger while mandating a content guard for everyone else. The remedy is not
  prose; RA-63.8 would have surfaced all three tracker destructions mechanically. Filed against
  the pre-existing **`PROCESS-01`**; does **not** increment the recurrence counter.
- **RA-63.11** The `a2bProbeFirstFailedCondition` ladder diverges from the real conjunction in one
  place: it checks `carrier-absent` before `invalid-source-face`, inverting `:19134` and `:19140`.
  Low severity — it misreports only when both fail, and `a2bProbeFailure` carries the real
  predicate on the same line, so the log cross-checks itself. The structural hazard is larger:
  **the ladder is an independent second transcription of the acceptance conjunction**, so a future
  edit to one and not the other makes the instrument report confidently about a reconstruction
  rather than about the decision — RP-03 aimed at the diagnostic instead of the reviewer. Verified
  faithful today condition by condition. **Reordering is deliberately deferred**: it is a C++ edit
  that would cost a fresh compile and invalidate the packaged one at `16c3134c0`.
- **RA-63.12** `one-hot-carrier-junction` is a good unrequested call: it names the RA-62
  junction-terminated mechanism inside the instrument, firing when `!same_interior_carrier_point`
  and both endpoints resolve to the same source vertex. Subset A is predicted to report it.
- **RA-63.13** `Successor: UNKNOWN` closed with a **reasoned defence** this time — that repository
  authority supplies no identifier and none may be invented. That reasoning is sound and correctly
  refuses to self-authorize, and naming the next turn is the Review Agent's prerogative. **No
  defect recorded**, unlike the two prior blank-field instances. Mandate amended: where no
  identifier is authorized, say so in the handoff rather than invent one.
- **RA-63.14** Hygiene: a **consumed** `drive_apply` descriptor remains committed at
  `.agents/Directional/agent-dispatch-request.json` (`base_sha 2d52eeb04`, live Drive `file_id`).
  A request channel whose descriptor stays live after consumption is not idempotent. Clear it next
  turn. Not an architecture finding, not a blocker.
- **RA-63 accounting.** Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen
  selector **497** — unchanged. `R4-VIN-01` applies: `16c3134c0` is a **new semantic source**, so
  artifact `11967601999` and every earlier measurement is a **baseline, never a comparand**.
  `RP-01` located and now known to be a pattern, **not repaired, repair not authorized**; `RP-02`
  **UNREACHED**; `RP-03` satisfied; **`PROCESS-01` open with a proven remedy**. Successor
  **`M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR`** (instrument-only, Python-only, no compile), then
  `M6-CP3-TB3-R4-PROBE-HARVEST` at `16c3134c0`.

---
## RA-62 — the junction-terminated front is a third shape with no certificate, and `RP-01` is located (2026-10-15, FROZEN)

Reviewer turn `M6-CP3-TB2-R4-CONJUNCT-EXTRACT-REV`. Decision document:
`.agents/Directional/Architecture_M6_CP3_R4_Terminal_Conjunct_Extraction_Review_Decision.md`.
Candidate/non-stable; no promotion, no stable event, no regression recurrence, no 497 execution.

- **RA-62.1 — extraction ACCEPTED, best-executed rung of this family.** Artifact-only from the pre-existing `11967601999` (ZIP SHA-256 `8b52373e…`, 50/50 manifest digests), run `38725063279`, semantic `570c5173…`; no dispatch, compile, execution or selector change. Partition matches RA-61's prediction **exactly**: **23** interior-shaped (indices 1–11, 26–33, 38–39, 42, 45), **21** one-hot (12–25, 34, 36–37, 40–41, 43–44), ordinal **405** (index 35). It delivered the three-conjunct truth table `RP-03` demands, **refused to over-claim** the vertex identity, kept 405 separate, and **named a successor** — ending two turns of `Successor: UNKNOWN`.
- **RA-62.2 — DEFECT, repaired: the handoff CURRENT section was overwritten in place** rather than superseded by prepending (4,419 → 4,411 lines); RA-61's 23-line section was deleted. **Neither gate catches it** — the handoff is not in `ledgers` coverage, and `boundary` reports `1 -> 1` because the durable-section heading survives below the replaced content. **This is `ORIENTATION.md:1799` verbatim** (recorded for `f6a784cf`). Fourth integrity event, second in two turns, on a **different file** from the one protected last turn: **protecting one file by name does not protect the class.** **And the remedy was already named, in exactly the form adopted at RA-61.3:** `ORIENTATION.md:1719` states that *"the effective guard is `review_check.py ledgers --base <previous-review-commit>`, which scans committed history"* and that the `boundary`-based guard *"was inert against committed overwrites"*; the same entry records that `ce9bf3cb` also overwrote the agent CHANGELOG (`0043dd4c`, 13,317 → 14 lines) and that **the first repair missed it**. `:1799` already supplies the decisive test — ***if deleting the protected content leaves the check green, the check does not cover that content*** — and already tracks the residual as **`PROCESS-01`** (`LESSONS.md` 172). This turn's handoff overwrite is a textbook instance, so the RA-62.2 mandate is filed against `PROCESS-01` rather than opened as new. No RA-61 finding was lost — the decision doc, Frozen Definitions, ORIENTATION, tracker and root CHANGELOG are byte-unchanged from `215698e0e` (verified). **Mandated, first item of the next Code + Build: add the handoff and ORIENTATION to `ledgers` coverage and replace `boundary`'s self-relative durable check with a monotone high-water floor.** Prose lessons have now failed three times.
- **RA-62.3 — the one-hot vertex is 4, derived exactly, with every measured truth value reproduced.** `make_disconnected_rectangular_feature_pair_mesh` (`tests/SurfaceCellsPhase10Tests.cpp:223-264`) gives face 0 = `(0,1,4)` and face 7 = `(4,8,7)`, so the probes `0:(0,0,1)` and `7:(1,0,0)` designate `faces(0,2) = 4` and `faces(7,0) = 4` — **both charts name vertex 4**. The rail is the chain **1–4–7** (`:6315-6318`), terminals `{1,7}`, **interior junction 4**. Recomputation reproduces `railEnd[1]=1, corner[1]=0,0` and `railEnd[7]=0, corner[7]=0,0` exactly. `railEnd[7]=0` is the first **measured** confirmation of **RA-60.6**.
- **RA-62.4 — mechanism named: a junction-terminated front, a THIRD shape with no certificate at all.** The front occupies one carrier edge `(1,4)` and ends at vertex 4: not a terminal front (no exact corner at 1 or 7), not an interior front (strictly one-hot). Both branches refuse, each correctly. RA-60.2 offered this configuration as reassurance that RA-41 stayed out of scope; it is **the actual failure mode of 15 of 44 identities**, and on the shared evidence shape almost certainly all 21.
- **RA-62.5 — PRINCIPAL: `RP-01` in its exact canonical form, rail-level authority answering a carrier-level question.** `SurfaceHardRailTerminalContacts` is keyed by **rail** with exactly two endpoints per rail (`include/directional/geometry/SurfaceCellTracing.h:1530-1535`), yet `endpoint_certificate` tests a **carrier-edge** endpoint against that rail-level set (`src/geometry/SurfaceCellTracing.cpp:19214-19217`). The conjunction can succeed only when the carrier edge contains a whole-rail terminal **and** the endpoint sits exactly on it, so for a **multi-edge rail** a front occupying one carrier edge **structurally cannot** satisfy it at the junction end. No per-interval terminal vocabulary exists although rail intervals are already consulted by the publisher (`find_rail_interval(railBuild.intervals, …)`, `:12610`). **Two authority domains conflated in one predicate** — located precisely, with a measured population, for the first time since `RP-01` was opened.
- **RA-62.6 — RA-59.9 picked the wrong shape for half the population; the error is the reviewer's.** "Half-terminal front" was directionally right, but the non-terminal end was identified as *interior to the carrier edge* when in 21 of 44 it sits *exactly at the carrier's other vertex*. RA-60 then specified and verified a certificate for the 23-case shape whose gate is dead (RA-61.6) while the 21-case shape got nothing. **Three shapes, three states:** interior-to-carrier = shape exists, gate dead; **junction-vertex = no shape at all**; ordinal 405 = no terminal contact published (`ContactPresent=0`), separate A2b defect.
- **RA-62.7 — the locus count collapses from ≤22 to 2.** All 23 interior cases record the **identical** probe pair and all 21 one-hot cases record the **identical** probe pair: 44 identities, **two** geometric configurations. RA-59.11's direction was right and the 39-corroboration framing wrong, but the bound was still an order of magnitude too generous. Subset **B** (6 cases, carrier `(1,2)`, candidates 1/6, indices 15–19 and 25) is the same mechanism in a different fixture on the identical evidence shape; **its vertex is not derived and must not be assumed.**
- **RA-62.8 — a hypothesis discarded before it entered the record.** That the publisher's run-cutting made `routeLength ≥ 2` impossible — and so RA-41 permanently unexercisable — is **false**: `observedSteps` is declared once before the segment loop (`:12505`), pushed inside it (`:12546`, `:12566`), checked after it (`:12672`) and assembled into one route at `:12684-12685`, collecting **one step per run across the whole front path**. A front spanning both `(1,4)` and `(4,7)` **would** give `routeLength = 2` and **would** exercise the junction loop (`:19096`). **The RA-59 recipe stands**, and `routeLength = 1` is a fact about the traced front, relocating the open question upstream to A1/A2a: why does the front stop at vertex 4? **Not authorized for probing** (RA-54.7).
- **RA-62.9 — the predicate-separation rung survives with shifted justification and re-ordered scope.** The extraction disambiguated the whole population from logs that already existed, so string separation is no longer primary. Two fields unobtainable from any existing artifact now dominate: **(b)** the **actual one-hot vertex identity**, which the probe never emits and whose absence forced the RA-62.3 hand derivation; **(a)** `sharedBoundaryInterval` presence and exact rational ordinals (RA-61.9 falsifier (i)). Name `M6-CP3-CB2-R4-PREDICATE-SEPARATION` **kept** (no rename for taste); scope ordered **(b), (a), then the string split**; strictly decision-neutral.
- **RA-62.10 — accounting unchanged.** Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. No accepted-green loss, no ledger credit. **`RP-01` located, not repaired and not authorized for repair**; `RP-02` still **unreached**; `RP-03` satisfied by this extraction. **RA-41's junction/sector clauses are no longer dormant** — they are the measured mechanism of 15–21 identities, recipe intact. Next rung `M6-CP3-CB2-R4-PREDICATE-SEPARATION` with the RA-62.2 gate-coverage fix as its first item.

---
## RA-61 — interior-witness measurement adjudicated: the acceptance path is unsatisfiable, the mechanism claim was over-general (2026-10-15, FROZEN)

Reviewer turn `M6-CP3-TB1-R4-INTERIOR-WITNESS-REV`. Decision document:
`.agents/Directional/Architecture_M6_CP3_R4_Interior_Witness_Measurement_Review_Decision.md`.
Candidate/non-stable; no promotion, no stable event, no regression recurrence, no 497 execution.

- **RA-61.1 — measurement ACCEPTED as execution evidence.** Run `38725063279`, result artifact `11967601999`, semantic `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`, harness SHA-256 `13a7e73ea17bff8c7b6a14bb2e3bc35712e05b8914a1546668108354fdb02e21`; `planned=45 executed=45 red=45 missing=0 postflight=true exit=0`; immutability `package/source/execution_view/selector=true`. Instrument compliant with RA-59.2/RA-57.8. **RA-60.12 obeyed**, no predicate relaxed, no epsilon added, successor name correctly refused rather than invented, ordinal 405 kept distinct.
- **RA-61.2 — REVIEW_BLOCKER, repaired: the append-only tracker was destroyed.** `b90c0f84e` cut `Regression_Root_Cause_Tracker.md` 12,949 → 6 lines, deleting 12,944 lines. Restored from `cef55bdd0`, measurement section retained, RA-61 prepended. **Floor frozen as data: never below 12,949 lines, 13 durable-marker occurrences, 648 `## ` sections.** Third occurrence (`tools/review_check.py:52-53`: `ce9bf3cb`/`0043dd4c`, 2026-09-22, restored at `M5-CP3-TB2-REV`). An **integrity** recurrence; does **not** increment the regression recurrence counter.
- **RA-61.3 — the reviewer was running the wrong gate.** `boundary`'s durable check is working-tree-vs-`HEAD` (`:184-196`, `live >= was`), so a committed truncation compares `0` to `0` and passes forever; `:48` documents this and names `ledgers`, which reports `[FAIL] … b90c0f84 12949->6`. **A check whose comparand is its own current state is not a check.** **FROZEN RULE: every Review turn runs `boundary` AND `ledgers --base <prior review commit>`.** Both lessons were **already written down and recurred anyway** — `ORIENTATION.md:1719` records `LESSONS.md` **176** for `ce9bf3cb` (same file, 9,837 → 21) and `:1799` records *"a guard that counts markers does not protect content"*, naming the `1 -> 1` pass mode. **A written lesson is not a control**, so the floor is recorded as countable numbers and the monotone high-water fix is mandatory, not advisory.
- **RA-61.4 — RA-60.10's prediction FALSIFIED; its decision rule held.** None of the 38 cleared `:19241`; 44/45 `no-exact-terminal-corner`, ordinal 405 `missing-terminal-or-closed-rail-provenance`; **branch (C)**, not (A) or (B). The premise was the reviewer's error: probes are 0.8/≈0.2 from `options.lengthRatio = 0.2` (`tests/SurfaceCellsPhase10Tests.cpp:6312`), not the asserted binary-exact 0.75/0.25. Prediction failed, decision rule worked.
- **RA-61.5 — LESSON (fourth of the RA-57.3 / RA-58.8 / RA-59.4 family): an expected value whose provenance is unstated is not a prediction.**
- **RA-61.6 — PRINCIPAL: the acceptance path is unsatisfiable, assumption-free for `fromPoint`.** Face 0's nonzero pair sums to `1 + 2^-55`; face 3's to exactly 1; the ≈0.2 weights differ by `2^-55`. `interior_carrier_parameter` (`:64-89`) returns `nullopt` for face 0 under **every** corner assignment, so `same_interior_carrier_point` fails at the first chart in all 23 and cross-chart equality is never consulted. The charts disagree on **admissibility**, not value.
- **RA-61.7 — the defect is the reviewer's specification; RA-60 verified the wrong property.** `first + second == one` over a traced barycentric demands closure doubles cannot guarantee; `from_double_exact` is exact about the **double**, preserving a rounding error and then testing it for equality. **FROZEN RULE: verify a predicate for satisfiability, not only for faithfulness.** "Fail-closed" is a virtue only when the closed state is reachable by legitimate input.
- **RA-61.8 — an exact witness already exists and was already wired.** `SurfaceTracePoint` (`include/directional/geometry/SurfaceCellTracing.h:90-93`) is `int face` + three doubles, so RA-59.9's exact parameter is unobtainable from it. `SurfaceSharedBoundaryInterval` (`:1418-1428`) carries `FieldExactRational firstOrdinal`/`secondOrdinal`, already required equal-span/reciprocal/equal-`railId` at `:19231-19238`. The check RA-60.2 "adopted as a strengthening" is the load-bearing one; the specified part is dead.
- **RA-61.9 — candidate remedy, NOT authorized (RA-54.7).** Keep strict-interiority classification; **drop** the closure gate and cross-chart double equality; rest identity on exact-rational `sharedBoundaryInterval` reciprocity. **No epsilon** — RA-60.11 honored. Falsifiers first: (i) is `sharedBoundaryInterval` set in these fixtures (`:1423-1425` permits unset); (ii) do span + reciprocal ordinals pin the point or the interval, derived from the producer.
- **RA-61.10 — RA-59.9's single-mechanism claim PARTIALLY FALSIFIED: ≥2 shapes, 23 + 21.** 21 probe one-hot (`0:0,0,1` vs `7:1,0,0`) — a vertex, not an interior point — rejected by both branches, so `terminalVertex` is absent although the endpoint is an exact corner. A separate, undiagnosed family the repair could not have fixed. **Corroborates RA-59.11**'s ≤22-loci bound; refutes the mechanism's breadth.
- **RA-61.11 — the deciding conjunct for the 21 is already captured and unreported.** The terminal loop (`:19213-19220`) is a three-way conjunction over the **same** vertex in **both** charts; the probe already emits `corner[v]=<from>,<to>` and `railEnd[v]=<bool>` per published terminal (`:19409-19416`). **No re-measurement required** — the evidence is inside `11967601999`. `RP-03` at instrument level.
- **RA-61.12 — accounting unchanged and next rungs.** Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497. `RP-02` still unreached. Next: **`M6-CP3-TB2-R4-CONJUNCT-EXTRACT`** (artifact-only extraction from the existing artifact; no dispatch, no compile, no code), then **`M6-CP3-CB2-R4-PREDICATE-SEPARATION`** (diagnostic-only, **now authorized** because branch (C) occurred; decision-neutral; also emit `sharedBoundaryInterval` presence/ordinals). The RA-61.9 remedy is authorized in neither.

---
## RA-60 — the interior-endpoint repair is faithful and the falsifier clears, but the new endpoint collapses onto the closed-chain encoding **FROZEN at M6-CP3-TB1-R4-REPAIR-REV** (2026-10-15)

Adjudicates `M6-CP3-CB1-R4-WITNESS-REPAIR`. The **compile is ACCEPTED**, the **implementation is ACCEPTED as faithful to RA-59.9**, the **Step 0 falsifier CLEARS** (on this Review's derivation, not the turn's), and **four defects plus one principal design finding** are recorded. **No runtime outcome has been observed and none is claimed** (LESSON 160). Full decision: [Architecture_M6_CP3_R4_Interior_Endpoint_Repair_Review_Decision.md](Architecture_M6_CP3_R4_Interior_Endpoint_Repair_Review_Decision.md).

**RA-60.1 — compile accepted, boundary held.** Eight-target GMP/GMPXX **GREEN**: run `38720128740`, exact semantic `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`, result artifact `11964478813` (outer SHA-256 `0e1e87a48ef090588c8675bd87bc8c7560a1ade5dbe44cac391c78e0cbe21ae5`), 28/28 packaged checksums, exits `0/0`, GMP ON, real `gmpxx`/`gmp`, `runtimeExecution=false`. Change surface independently confirmed: exactly **two** files, test change **purely additive** (zero deletions); Quotient and REPackage tests, `cmake/`, `benchmarks/` and every selector file **untouched**; **no fixture geometry changed** (RA-59.12).

**RA-60.2 — the implementation is faithful, and strengthens the specification.** All six RA-59.9 authentication requirements are met at `src/geometry/SurfaceCellTracing.cpp:19221-19241`: typed carrier key; **across-rail** attachments from `topology_for_row(source_face_id(·))` on both trace-point faces (`:19130-19138`) gated by `oriented_carrier`; exact shared intrinsic parameter; **no epsilon anywhere** in the new helpers; component/sheet carried by the topology keys; directed A3 transport carried from a record whose `reverse == forward.inverse()` was verified at construction. `interior_carrier_parameter` (`:61-89`) requires the third barycentric **exactly** `0.0`, converts exactly, and admits only `second ∈ (0,1)` **strictly** with `first + second == 1`. Three consequences: a forged terminal **cannot** be laundered through the interior branch; the parameter is **canonically oriented** (the weight at `edge.second()` of a canonical key), avoiding the orientation bug an along-rail parameterization would have had; and a front ending exactly at the rail's interior **junction vertex 4** is **rejected, not absorbed**, keeping RA-41's clauses outside this repair. Beyond spec, the branch also requires **`sharedBoundaryInterval` reciprocity** (equal `span`, cross-matched ordinals) — **adopted as a strengthening of RA-59.9**. No parallel certificate model: absence of a terminal is expressed through the existing `std::optional`.

**RA-60.3 — every prohibited invariant verified intact.** `exact_corner`/`no-exact-terminal-corner` unchanged and reachable only when `!terminalVertex`; closed-chain branch untouched (RA-58.5 torus PASS preserved); **at least one certified terminal endpoint still required** — at `:8572-8576` a both-interior certificate fails both `singleTerminalValid` disjuncts and is rejected, so a contact-less open rail remains impossible; `tests/SurfaceCellsPhase10Tests.cpp:7205` untouched and still satisfiable; ordinal **405**'s branch untouched; no `Produced` precondition weakened.

**RA-60.4 — Step 0 CLEARS, derived here rather than evidenced by the turn.** The record claims the falsifier *"was checked … as recorded in the continuation artifact"* but **states no finding, cites no anchor**, and the artifact is not in the repository; the only visible trace is a **rewritten contract comment** at `:18975-18978`. A claim of having checked is not a finding (LESSON 171). Derived from the publisher instead: `assign_open_front_boundary_authority` (`:12481`) accumulates runs from **traced segment barycentrics** via `canonical_retained_edge_parameter` (`:12509-12530`) and publishes a run when `lastTopology != topology` (`:12574-12579`) — **cut at source-edge topology changes, never at rail terminals**. Front extent is **field-determined**, so an interior front end is a legitimate product of the publisher's contract. **The amended comment is a CONSEQUENCE of the RA-59.9 selection and must never be cited as evidence for it** — doing so is circular and an `RP-01` shape.

**RA-60.5 — DEFECT: the new rejection is diagnostically indistinguishable from the old one.** Both the unchanged terminal loop and the new interior branch end at the same `reject("no-exact-terminal-corner")` (`:19241`), so a repeat of that predicate cannot separate *"interior branch never reached"* from *"interior branch refused"* — opposite consequences for the model. **Conditional fix, authorized only if RA-60.10 branch (C) occurs:** a distinct predicate (e.g. `no-interior-carrier-agreement`) on the existing diagnostic-only path, changing no decision. **Not** authorized pre-emptively — branch (C) is the unlikely one and a speculative rung is the RA-54.7 defect.

**RA-60.6 — the per-certificate terminal-coverage invariant was dropped, necessarily, with no aggregate replacement.** The original gate required `forward || reverse` (`:8544-8553`), i.e. **each accepted certificate's two endpoint carriers had to touch both published rail terminals** — a whole-rail span condition. At `routeLength=1` both endpoints share carrier `(1,4)`, which touches terminal **1** but not **7**, so `forward == reverse == false` and the original rejected unconditionally; dropping it for the interior case was **necessary, not gratuitous**. Nothing replaces it per rail or in aggregate. **Prediction, not speculation:** no front in these fixtures crosses `(4,7)`, so **terminal 7 can never be attached by any certificate**, and the repair necessarily yields open rails with one published terminal unattached. Whether A5/A6/A7 tolerate that is unmeasured; it is the most likely place for the failure to reappear downstream.

**RA-60.7 — PRINCIPAL DESIGN FINDING: the interior endpoint collapses onto the closed-chain encoding.** The new certificate is `{firstAttachment, secondAttachment, *oriented, std::nullopt, {}}` (`:19239-19241`), which is **exactly** the shape the checked factory's closed-chain branch requires at `:8729-8733` (no `terminalVertex`, empty `contactPaths`, carrier faces equal to the attachments). **An interior open-rail endpoint and a closed-chain endpoint are now structurally identical**; the only separator is which branch of `if (contact != hardRailTerminalContacts.end())` the **rail** takes — a property of the rail, not the certificate. The previously sound inference *"no terminal vertex ⇒ closed chain"* is now **false**. Severity, honestly: **latent, not active** — the only consumer outside this file is the structural fingerprint `hash_trace_network` (`src/pipeline/RemeshPipeline.cpp:2123-2124`), where both states alias to `-1`, and a fingerprint is not an authority. It is nevertheless an `RP-01 AUTHORITY_DOMAIN_CONFLATION` shape awaiting its first semantic reader. **Required before anything reads it semantically:** a **positive discriminator** on the endpoint — the attested interior parameter itself, or an explicit kind tag — so *"no terminal"* and *"interior carrier attested at parameter p"* become different states. Recorded, **not** authorized in a measurement rung.

**RA-60.8 — DEFECT: a comment asserts an invariant its own site does not enforce.** `:8662-8675` is introduced by *"the opposite endpoint must already carry an independently checked whole-rail terminal witness"*, but that site never inspects the opposite endpoint; the invariant is enforced at `:8572-8576`. Point the comment at the enforcing site or move the check.

**RA-60.9 — the first positive witness in this family, and four untested negatives.** `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard` (`tests/SurfaceCellsPhase10Tests.cpp:7148-7191`) is **nonvacuous**: it demands real production, then requires the producer to witness **one terminal and one interior** endpoint — per RA-59.8 the **first positive witness of the acceptance half ever authored**, subject to actually passing at runtime. Its negative half rejects via the **retained** `(!forward && !reverse)` condition rather than via the new predicate, so the name over-claims (corner exactness does not live in the factory at all); substance stands. Untested negatives on the new predicate, all of which the code rejects: differing interior parameters; non-empty `contactPaths` on an interior endpoint; carrier/attachment mismatch; and **both endpoints interior** — the contact-less-open-rail forgery the retained plan explicitly prohibits, and the cheapest of the four to author. Required in the next Code + Build touching this area; **not** inside a measurement rung.

**RA-60.10 — PRE-REGISTERED PREDICTION AND DECISION RULE.** Registered **before** the measurement so the result cannot be reinterpreted afterwards. The measured probes `0x1.8p-1` (`0.75`) and `0x1p-2` (`0.25`) are exactly representable, the third weight is exactly `0.0`, and `0.75 + 0.25 == 1.0` exactly in **both** charts; `singleTerminalValid(terminal 1, carrier (1,4))` holds; `:8662`'s attachment equality holds by construction of `oriented_carrier`. **Prediction: the 38 `endpoint-1` identities clear `:19241` and A4 accepts.** Binding interpretations: **(A)** `Produced` and the network-bound consumer reached → the repair works and `RP-02` is measurable for the first time, both halves required before any `RP-02` claim; **(B)** a new first failure strictly **downstream** (A5/A6/A7, most likely terminal coverage) → **does NOT falsify RA-59.9**, confirms RA-60.6, locates the next rung, record and do not chase (RA-54.7), do not fold into the hard-rail carrier; **(C)** the same `no-exact-terminal-corner` → **ambiguous** by RA-60.5, mandating that diagnostic-only fix before any re-measurement. **"Still RED" is not evidence against the model**, and no branch authorizes relaxing any predicate.

**RA-60.11 — residual: two arithmetic régimes meet at one endpoint.** The publisher admits run endpoints with `constexpr double tolerance = 1.0e-9`, an interval test on `[−tolerance, 1 + tolerance]` and `std::clamp(parameter, 0.0, 1.0)` (`:12509-12530`), stitching runs under `std::abs(*runEndParameter - *startParameter) > tolerance` (`:12655`); the certificate demands **exact** rational equality and **strict** interiority. Soundness is preserved — exact, epsilon-free, fail-closed, so no false acceptance — but this seam is where a one-ULP cross-chart disagreement would surface, as a **refusal**, observable as RA-60.10 branch (C). **No epsilon may be introduced into the certificate to close it.**

**RA-60.12 — correction: the handoff reinstated a retired stop rule.** The turn's handoff directs the next TB to run the remaining supplemental identities *"only until first RED"* — the pre-RA-57 rule retired by RA-57.8 and RA-58, and the exact mechanism that left the breadth turn unreported. **A measurement rung executes ALL its identities regardless of RED**, taking its verdict from `executed`/`missing`/`postflight` only. Under the RA-60.10 prediction a first-RED stop would also discard nearly everything the run could establish.

**Accounting.** Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected, frozen selector **30+12+449+6=497** — unchanged. No promotion, no stable event, no recurrence, no 497 execution, no gate credit. No source, test, selector, binary, harness, workflow or benchmark change in this Review. **`R4-VIN-01` applies with force: the repaired package is a NEW semantic source (`570c5173…`), so every prior measurement is a baseline, never a comparand.** **Successor:** `M6-CP3-TB1-R4-INTERIOR-WITNESS` (artifact-only Test + Benchmark on the new package), governed by the RA-60.10 pre-registration — replacing the `Successor: UNKNOWN` the repair turn left.

---
## RA-59 — the census closes the hypothesis set: pairing and truncation are eliminated from source, the certificate model is SELECTED as an interior-endpoint domain gap **FROZEN at M6-CP3-TB1-R4-CARRIER-REV** (2026-10-15)

Adjudicates `M6-CP3-TB1-R4-ENDPOINT39-CENSUS`. The **measurement is ACCEPTED**; its **interpretation is AMENDED and then CLOSED**. Full decision: [Architecture_M6_CP3_R4_Carrier_Review_Decision.md](Architecture_M6_CP3_R4_Carrier_Review_Decision.md); derived per-identity classification: `Architecture_M6_CP3_R4_Carrier_Review_Derived_Classification_20261015.tsv`.

**RA-59.1 — measurement accepted.** `executed=39 red=39 missing=0 postflight=true exit=0` on the same immutable package (compile `38664036225`, artifact `11939982141`, semantic `953f812ff1f431e3ad3af3b68a92284a7831c94a`), workflow `38687783618`, result `11950303475` (ZIP SHA-256 `3bce344f3a13403a830a2800fea4c47d1e7cdd53f6f3eac6629de57d70788b32`), 28/28 manifest before and after, all four frozen selector hashes matched. Re-derived independently: all **39/39** executed identities are members of the 94-row R3 RED register, and 117 field comparisons against that register yield **zero** mismatches.

**RA-59.2 — the instrument shape for every future census rung.** `tools/m6_cp3_r4_endpoint39_census_harness.sh` is RA-57.8 compliant (`:71-74` `NOT_SELECTED` + `continue`; `:91` verdict from `executed`/`missing`/`postflight` only; `:92` `exit 0`) **and** derives its scope from a SHA-256-pinned inventory (`:45-51`, `de05a7bd…`) with count and duplicate assertions. Transcribed census scopes are retired; a census scope is pinned, mapfiled and asserted.

**RA-59.3 — `step` is not data.** Emitted at `SurfaceCellTracing.cpp:19329-19332` as `firstMissing ? 0 : routeSteps.size() - 1U`; at `routeSteps.size()==1` **both** branches are `0`. `step` is `routeLength-1`, an echo in the same class as `faceEnds` (RA-56.1). `locus=3` is `EndpointAttachment` (`SurfaceCellTracing.h:1800-1811`), implied by the predicate name. Neither corroborates.

**RA-59.4 — hypothesis (c) route truncation is WITHDRAWN.** `first.route` is produced at `SurfaceCellTracing.cpp:12617` from runs assembled at `:12574-12579` — **one step per contiguous run of the front edge's own retained geometry on one source-edge topology**, `seenTopology` forbidding revisits. `routeLength` measures the **front edge's carrier extent**, not the rail's length; `routeLength=1` is its **correct** value for a front on one carrier edge, and `>1` is representable. The hypothesis rested on a field whose expected value was never established. **New standing rule: a measured value without its expected value is not a discriminator.**

**RA-59.5 — hypothesis (b) incorrect pairing is ELIMINATED.** The pairing precondition at `:19022-19025` returns immediately with predicate `nonreciprocal-pair` and locus `Pairing = 1`. All 39 report `endpoint-0`/`endpoint-1` with locus `EndpointAttachment = 3` from `:19329-19332`, so in all 39 the rail ids matched, the route was non-empty and `first.route == second.route.reversed()`. Two independent fields agree.

**RA-59.6 — the measured carrier is a HALF-TERMINAL FRONT.** Both certificates are evaluated on the pair's two spatial ends at `:19264-19269`: `(first.from, second.to)` and `(first.to, second.from)`. `endpoint-1` means `firstEndpoint` **returned a value**, so in 38 of 39 **one end was certified at an exact rail terminal source vertex** and the other failed at `:19152` at an interior parameter of the same carrier edge. Reproduced across 39 identities, 5 fixture builders, 2 rail ids, `chi=0` and `chi=3`, and both `remesh_from_raw_cross_field` pipeline entries — a **measured carrier** under RA-56.8.

**RA-59.7 — hypothesis (a) is SELECTED as a DOMAIN GAP, not a strictness dial.** `endpoint_certificate` (`:19049`) admits exactly two shapes: open rail with a published terminal contact (`:19144-19152`), or contact-free rail with an independently published typed closed chain (`:19072-19079`). A front end interior to the carrier edge of an **open** rail satisfies neither, and there is no third branch. This one mechanism re-explains RA-58.5 in full: the torus passes on branch 2 because its chain is **closed**; square and cylinder never enter the block; only open-rail fixtures reach branch 1 with an interior end.

**RA-59.8 — the acceptance half of the model has NO witness, and the junction loop is unreachable.** The five tests that assert a published hard-rail route certificate (`SurfaceCellsPhase10Tests.cpp:6922, :7104, :7148, :7189, :7248`) are all tamper/negative tests whose **first** assertion demands real production (`:7150-7152`), and all fail at that gate. No test, green or RED, has ever observed the producer publish an open-hard-rail route certificate from real source geometry. The junction loop at `:19335-19338` (`for index = 1; index < routeSteps.size()`) **cannot execute** at `routeLength=1`, so **no number of further `routeLength=1` measurements can exercise RA-41's junction/sector clauses.** Exercising them requires a fixture whose front spans **two** rail topologies — crossing both `(1,4)` and `(4,7)`. Recorded, **not** authorized (RA-54.7); the guards are **not** retired (RA-52.6). `RP-02` is localized to the unwitnessed acceptance half and **remains open**.

**RA-59.9 — SELECTED CERTIFICATE MODEL.** The open hard-rail route certificate gains a **second admissible endpoint shape — a source-attested interior carrier endpoint** — authenticated by the typed carrier key; **both incident source faces of that carrier edge (across-rail per RA-57.5, NOT along-rail interval or face-side ownership)**; the canonical exact intrinsic parameter on the **same** carrier edge shared by both paired trace points, with equivalent opposite-side barycentric representatives and **no** world-coordinate epsilon merging; source component/sheet agreement; the matching A2a mandatory network edge/rail identity; and the directed A3 transport between those two incident faces. Non-negotiable with the selection: `exact_corner`/`no-exact-terminal-corner` at `:19131-19152` stay **unchanged and fail-closed**; the closed-chain branch at `:19072-19079` stays **unchanged**, preserving the RA-58.5 torus PASS; an open rail must still publish **at least one certified terminal endpoint**, so contact-less open rails and forged closed-chain tokens remain impossible; and `endpoints[0].terminalVertex.has_value()` (`SurfaceCellsPhase10Tests.cpp:7157`) stays satisfiable, so **no existing test contract is weakened** — checked before selecting. **FALSIFIER, to be checked FIRST with a STOP:** the selection assumes a hard-rail front's extent is field-determined, so an end may legitimately fall interior to a carrier edge. If the front publisher is instead contracted to cut hard-rail fronts **only** at rail terminals, the half-terminal front is itself the defect, the repair belongs upstream of `:19264`, and this model is wrong. The comment at `:18908-18909` is evidence for the stricter reading and must be reconciled before any edit. If the publisher's contract cannot be established from source, **STOP and return to Review** — do not resolve it by whichever choice makes the 38 green.

**RA-59.10 — classification correction.** Of the 39: **37** reproduced **carried CP2 losses** (`CP2_ACCEPTED=true`), **2** reproduced **in-gate R3 REDs with no accepted CP2 baseline** (`CP2_ACCEPTED=false`, phase `cp3entry`), **0** baseline-free first measurements. The census TSV's blanket `reproduced_carried_loss=true` and the report's *"previously observed, unaccepted"* each flatten this. The two in the second class — `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` and `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` — are also the only `chi=3` rows and the only `nonconstant_hard_rail_fixture` rows, and they are **`cp3entry` members of the "+6" CP3 group, i.e. INSIDE the frozen 497.** "In no selector" is true of the three selector **files** only; it is the exact phrase under which RA-58.6 classified a baseline-free identity and must never be reused for an in-gate one. **All 39 census identities are inside the frozen 497.**

**RA-59.11 — RA-58.9 arithmetic, applied.** 19 identities had a **throwing** fixture singleton (17 `hard_rail_fixture`, `SurfaceCellTransitionQuotientTests.cpp:585, :771-772`; 2 `nonconstant_hard_rail_fixture`, `:776, :855-856`), so the test bodies never ran and those are **2** fixture-construction measurements, not 19. Upper bound on independent loci: **≤ 22**, not 39 — 1 + 1 + 12 `build_rectangular_hard_rail_phase_front` + 2 `remesh_from_raw_cross_field` + 6 direct. **"39 REDs" must never be cited as 39 corroborations**; the two singleton rows never count toward breadth.

**RA-59.12 — the authored rail is two edges, and the interior end is therefore structural.** `make_hard_rail_fixture` (`SurfaceCellTransitionQuotientTests.cpp:585`) inserts `{1,4}` at `:617` and `{4,7}` at `:618`; `make_nonconstant_hard_rail_fixture` (`:776`) at `:830-831`; `build_rectangular_hard_rail_phase_front` (`SurfaceCellsPhase10Tests.cpp:6298`) at `:6315-6322` per component. Every measured fixture authors a **two-edge open rail `1→4→7`**, interior junction **4**, terminals **{1,7}**, with the front on `(1,4)` only. The interior endpoint is not fixture degeneracy — it is what a field-determined front does to a rail with interior structure. **Repair by fixture change is forbidden** and self-defeating: a one-edge rail would retire the only fixtures that can ever exercise the junction clauses.

**Accounting.** Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried CP2 losses), frozen selector **30+12+449+6=497** — unchanged. No promotion, no stable event, no new recurrence, no 497 execution, no gate credit. No source, test, selector, binary, harness, workflow or benchmark change in this Review. **Successor:** `M6-CP3-CB1-R4-WITNESS-REPAIR` (Code + Build, compile-only), re-entered under RA-59.9 with its RA-57.5 vocabulary amendment and the RA-59.9 falsifier checked first.

---
## RA-58 — the true control answers the question, more strongly than reported: the carrier is bounded to OPEN hard-rail terminal certification **FROZEN at M6-CP3-TB1-R4-TRUE-CONTROL-REV** (2026-10-15)

Adjudicates `M6-CP3-TB1-R4-TRUE-CONTROL`. The **measurement is ACCEPTED**; **RA-57.8 is DISCHARGED**; the
report's **interpretation is AMENDED** (it understated its own result) and its **classification of one
torus RED is CORRECTED**; the **carrier is bounded**; the census is **AUTHORIZED** with one added column.
RA-57, RA-56, RA-55, RA-54, RA-53, RA-52 less .5, RA-51 … RA-37a and the RA-34.3 stop gates stand. No
promotion, no new stable event, no 497 run, **no gate credit**. Decision record
`.agents/Directional/Architecture_M6_CP3_R4_True_Control_Review_Decision.md`.

- **RA-58.1 — accepted on re-derived receipts.** Artifact `11948572472`, downloaded ZIP SHA-256
  `2b6ac34c34ea3f0dd384f5be7a55ca9c9028328639effed3c9cc3e3c9674917f` matching the report;
  `executed=4 red=2 missing=0 postflight=true exit=0`, `compile=false relink=false benchmarks=false
  selector497=false`, `package=true source=true execution_view=true selector=true`, manifest 28 OK → 28
  OK, harness SHA-256 `9d471c493b7d3c9c4fa5bf31916e37d9caa470a628da6c0e710f770f0c986162`. `git diff
  c2b3571bb..HEAD -- src include tests cmake benchmarks` **empty**. Each log has **exactly one**
  `: Failure` line, which is what makes the locus analysis sound: `ASSERT_*` is fatal, so every preceding
  assertion passed. The turn reported itself and closed `COMPLETE` with a named successor; RA-57.1's
  reconstruction problem does not recur.
- **RA-58.2 — RA-57.8 DISCHARGED, and discharged the right way.** In
  `tools/m6_cp3_r4_true_control_harness.sh`: non-selection records `NOT_SELECTED`, increments `missing`
  and **continues** (ii); the verdict is `[[ executed == 4 && missing == 0 && postflight == true ]] ||
  die` then `exit 0`, so the bare `[[ "$red" == 0 ]]` tail is gone and expected REDs no longer forge an
  orchestration failure (i), with `die 'incomplete breadth'` retained. Done in a **new one-off harness**
  rather than by editing the previously dispatched one whose SHA is pinned in RA-57.8's evidence — the
  correct call.
- **RA-58.3 — the decisive positive: A4 production is not universally down.** Both no-interior-hard-rail
  identities PASS, and **both are members of the frozen `selector449`**:
  `SurfacePhaseFrontProductFactoryAuthority.ReorderedCellStoragePreservesTypedEdgeOwnershipAtCheckedFactory`
  (`square_fixture`, no `userHardEdges`) and
  `SurfaceCellTypedTransportAuthority.ValidPeriodicCutRouteUsesTypedIdentity` (`cylinder_fixture` →
  `make_committed_fixture("cylinder", false)`, no `userHardEdges`) — the latter a **613 ms** full pipeline
  exercising `PeriodicCut` boundary authority. Neither is in the 94-row R3 RED set, so both were among the
  403 R3 PASS and **remain green on `953f812f`**: a positive `R4-VIN-01` datapoint. **No gate credit** —
  the frozen 497 did not run.
- **RA-58.4 — the closed-chain arm is informative and POSITIVE; the report stopped one step short.** Its
  premise is confirmed independently: **zero** occurrences of `no-exact-terminal-corner`,
  `InvalidHardRailRouteCertificate` or `endpoint-1` in either torus log, so refusing to conflate loci was
  right. But the loci themselves carry the finding. Identity 3
  (`tests/SurfaceCellTransitionQuotientTests.cpp:6018`) fails only at `:6023`
  `ASSERT_TRUE(run.surfaceCellContext.hasArrangement)`; the preceding fatal `:6022
  ASSERT_TRUE(run.surfaceCellContext.hasTraceNetwork)` **passed** — the trace network, where the phase
  front and hard-rail route certificates live, **was produced** on a closed-chain-hard-edge torus.
  Identity 4 (`:2773`) fails only at `:2807`; everything before passed, including `:2795
  ASSERT_NE(rotated, nullptr)`, which guards a `SurfacePhaseFrontProduct::make` fed
  `front.hardRailRouteCertificates()`, `front.hardRailTerminalContacts()` (`:2791`) and
  `front.hardRailClosedChains()` (`:2792`). **The checked factory ACCEPTED closed-chain hard-rail
  certificates and terminal contacts under a Z4 gauge rotation.** Both torus identities reached and
  cleared A4; they fail downstream, at arrangement and at A5.
- **RA-58.5 — CONCLUSION: the carrier is bounded to OPEN hard-rail terminal certification.** No hard rail
  → A4 green, PASS end-to-end (RA-58.3). Closed-chain hard rail → A4 green, certificates **accepted**, RED
  downstream (RA-58.4). Open hard rail with interior terminals → A4 **rejected** at
  `no-exact-terminal-corner`, four entries, one mesh (RA-57.2). This is RA-57's reading-grid case 1,
  established. It corroborates RA-57.5 from an independent direction: a **closed chain has no terminals**,
  so `exact_corner` and the terminal-contact path are never taken on the torus — and the torus A4 passes.
  The defect attaches to the **terminal-closing requirement on an open rail**, precisely the construct
  RA-57.5 showed being applied to two fronts meeting **across** the rail at an interior point. The three
  RA-57.7 hypotheses all survive; **none may be chosen.** The bound narrows where to look, not what is
  wrong.
- **RA-58.6 — classification CORRECTED: one torus RED is already in the 94, the other has no baseline.**
  Identity 3 is in `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` at `phase=focused30`,
  `ordinal=25`, `first_observable=OTHER_FIRST_PREDICATE`, `R2_RED=true`, **`CP2_ACCEPTED=true`**, candidate
  `R2-CAND-04`, recorded diagnostic `…:5775: Failure | Value of: run.surfaceCellContext.hasArrangement |
  Actual: false | Expected: true` — **the same assertion on the same value** as today's `:6023`, the line
  shifted +248 by source evolution. It is the **single** `OTHER_FIRST_PREDICATE` member of the 94: a
  **reproduced carried loss inside the frozen 497**, now re-measured on `953f812f` and still RED, so its
  vintage ambiguity is resolved. Identity 4 has **0 hits** in `focused30`, `focused12`, `selector449` and
  in the 94 — **no accepted baseline, therefore not a regression**, not ledger-eligible, a first-ever
  measurement. Tabulating the two as the same kind of RED flattens two very different accounting states.
- **RA-58.7 — a new, separate obligation: recorded, not chased.** Identity 4 shows A5
  `SurfaceOccurrenceComplexProducer::produce` returning its error alternative for a front that A4 produced
  and the checked factory accepted (`:2797-2799`, failing `:2807`); identity 3 shows arrangement absent on
  a produced torus trace network. Both belong to the **A5/A6/A7 backlog**, not the hard-rail carrier, and
  must not be folded into it. **No probe authorized** — chasing them now is the extra Code rung RA-54.7
  forbids. Guards untouched, fail-closed.
- **RA-58.8 — my reading grid was wrong; second instance of one error class.** RA-57's grid read "torus RED
  but square/cylinder PASS → the defect is **all** hard-rail routing." Applied to this run it yields the
  **opposite** of the truth, because both torus REDs sit downstream of a **successful** hard-rail A4. The
  grid conditioned on the **verdict**; the question was about the **locus**. Same class as RA-57.3, where
  the "control" fixture could not discriminate: in both cases the instrument's output did not answer the
  question it was built to answer. Recorded under `RP-03`. **LESSONS: condition an instrument on the locus
  of failure, not on the verdict.** A pass/fail grid over a staged pipeline is valid only if each branch
  also names the stage at which the verdict must appear. The executor's refusal to conflate loci was
  better than my grid and is upheld.
- **RA-58.9 — RA-57.11's blast radius did NOT fire, which changes the census column.** Both torus REDs
  hang off the same `static torus_fixture()` singleton — the RA-57.11 shape — but **the singleton
  succeeds** and the two tests fail at genuinely different downstream loci. A column recording merely
  *which* singleton an identity hangs off would have merged them as one defect, wrongly. The column must
  record **whether the singleton constructed successfully and the stage of the first failure**, not just
  its name. RA-57.11's merge rule applies only to a **throwing** singleton.
- **RA-58.10 — the census is authorized, scope unchanged, key extended.** `M6-CP3-TB1-R4-ENDPOINT39-CENSUS`
  proceeds as frozen in RA-57.12 plus RA-58.9: per identity record the **fixture singleton, whether it
  constructed, and the pipeline stage of the first failure**, alongside `routeLength`, `step`, `chi`, probe
  charts and parameters, `closedChainPresent`, and the full `faceEnds` (kept for the record, never read as
  corroboration). State carrier membership per identity against the 94-row R3 classification **and** all
  three selectors, so reproduced carried losses, in-gate REDs and baseline-free first measurements are
  never tabulated as one kind of thing again.

## RA-57 — the breadth measurement is accepted, the carrier is measured, my control was not a control, and RA-56.5 resolves to ACROSS-rail **FROZEN at M6-CP3-TB1-R4-WITNESS-BREADTH-REV** (2026-10-15)

Adjudicates `M6-CP3-TB1-R4-WITNESS-BREADTH`. The **measurement is ACCEPTED** and re-derived from the
immutable artifact, since no report was written. Its **turn state is CORRECTED** — the workflow concluded
`failure` on expected REDs; the measurement did not fail. The **control claim in the prior `NEXT_TURN` is
WITHDRAWN as false on the bytes**. **RA-56.5 is RESOLVED.** The repair stays **DEFERRED**. RA-56, RA-55,
RA-54, RA-53, RA-52 less .5, RA-51 … RA-37a and the RA-34.3 stop gates stand. No promotion, no new stable
event, no 497 run. Decision record
`.agents/Directional/Architecture_M6_CP3_R4_Witness_Breadth_Measurement_Review_Decision.md`.

- **RA-57.1 — accepted from the artifact, not from prose.** No TB report exists; the turn closed
  `IN_PROGRESS` with `Successor` pointing at itself (`63388be98`). Evidence taken from run
  `38676433923`, artifact `11946622500`, ZIP SHA-256
  `127c77580a9e77dafb1889575b8d69bdbe0271f7a3fc8041fc6c904e9918c6a3`: `executed=4`, `red=4`,
  `missing=0`, `postflight=true`, `compile=false`, `relink=false`, `benchmarks=false`,
  `selector497=false`; `package=true source=true execution_view=true selector=true`; manifest 28 OK
  before and 28 OK after. Harness SHA-256
  `db1aea68782f68196da0abf26be24f6648e9c565d305f3200ced09740aedd65a` matches its dispatch record and
  re-checks all four frozen selector hashes around execution. `git diff a44bbf534..HEAD -- src include
  tests cmake` is **empty**: the measurement rung edited no source, as required.
- **RA-57.2 — the carrier is now MEASURED, satisfying RA-56.8.** 4/4 RED across three files, three
  fixture builders, one focused-factory entry, two focused-producer entries and one full
  `remesh_from_raw_cross_field` pipeline entry — all at `tracing/phase-front`,
  `InvalidHardRailRouteCertificate`, `predicate=endpoint-1`,
  `a2bProbeFailure=no-exact-terminal-corner`, `edge[0]=1,4:faces=0,3`, `locus=3`, `rail=2`,
  `routeLength=1`, `step=0`, `vertex=-1`, `faceEnds=0,2|0,3`, `carrier=1 a3=1 contact=1 closedChain=0`.
  RA-56.3's `A4_ROUTE_CERTIFICATE_REJECTION` reading is confirmed by execution, not inferred from a
  static inventory. Measured rows frozen in
  `Architecture_M6_CP3_R4_Witness_Breadth_Measured_Predicates_20261015.tsv`.
- **RA-57.3 — WITHDRAWN: my own control was not a control.** The prior `NEXT_TURN` ordered
  `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm` first as "THE CONTROL, on a **different
  fixture**." `make_nonconstant_hard_rail_fixture`
  (`tests/SurfaceCellTransitionQuotientTests.cpp:776-853`) builds the same 3×3 planar grid as
  `make_rectangular_internal_hard_feature_grid` (`tests/SurfaceCellREPackageTests.cpp:46-75`) and
  inserts the identical `userHardEdges {1,4}` and `{4,7}` at `:830-831` — **same mesh, same hard
  feature, same rail chain `1→4→7`, same terminals `{1,7}`**. Different file, different builder,
  different field; not a different fixture in any sense that discriminates. The executor ran exactly
  what was ordered and ran all four per RA-56.4. The error is the reviewer's and is recorded under
  `RP-03` rather than amended silently.
- **RA-57.4 — bounded claim.** All four identities run on **one mesh** — the 3×3 unit planar grid with
  the `x=1` midline hard feature. The rung establishes that the defect is not entry-path-,
  fixture-helper- or focused-producer-specific. It establishes **nothing** about mesh generality and
  does **not** separate "all open hard-rail production is down" from "A4 production is down generally."
- **RA-57.5 — RA-56.5 RESOLVED: the geometry is ACROSS-rail.** Per the emitter at
  `src/geometry/SurfaceCellTracing.cpp:18948`, `faceEnds = first.from.face, second.to.face |
  first.to.face, second.from.face`. The measured `0,2|0,3` therefore means the first front begins and
  ends **inside face 0** and the second begins **in face 3** — and `face 0 = (0,1,4)`, `face 3 =
  (1,5,4)` are exactly the two faces of edge `(1,4)`. The probes confirm it: `a2bProbeFrom` in face 0,
  `a2bProbeTo` in face 3, both resolving to the same point on `(1,4)`. **The two fronts approach the
  rail from opposite faces and meet at a shared interior point of it.** They are not collinear intervals
  running along the rail. The retained repair plan's *"ordered rail interval/face-side ownership"*
  presumes the along-rail frame and **must be amended before `M6-CP3-CB1-R4-WITNESS-REPAIR` is
  re-entered**. This is the RA-45.2 category error RA-56.5 was raised to catch, caught before code.
- **RA-57.6 — the failure is field- and transition-independent.** Identity 1 runs a non-constant field
  and reports `chi=3` on edge `(1,4)`; identities 2–4 run a constant field and report `chi=0`. Identities
  1–2 pair at interior parameter `0.2`, identities 3–4 at `0.25`. **All four rejections are identical.**
  Any repair proposing a tolerance, a parameter special case or a transition-conditioned branch is
  already falsified. **Second-order hazard recorded, not chased:** identity 1/2's two charts report the
  shared third barycentric as `0x1.9999999999999p-3` and `0x1.9999999999998p-3` — one ULP apart — so a
  certificate demanding bit-exact cross-chart agreement would fail exactly as `exact_corner` does. The
  correct instrument is the exact rational parameter on the shared source edge.
- **RA-57.7 — three hypotheses remain and `routeLength=1` promotes a third.** (a) the certificate is too
  strict; (b) the pairing is wrong; (c) **the route is truncated** — `routeLength=1` with `step=0` in all
  four means every failing route is a single step, where a genuine route to a whole-rail terminal would
  generally be longer. (c) was not previously on the list. **None may be chosen before the census.**
  RA-57.5 removed a fourth, wrong, frame; it did not select among these three.
- **RA-57.8 — two harness design defects.** **(i)** A measurement rung must not fail its workflow on RED.
  `tools/m6_cp3_r4_witness_breadth_harness.sh:85` is a bare `[[ "$red" == 0 ]]` as the last statement, so
  four **expected** REDs set exit 1, the runtime job concluded `failure`, and the turn was left
  `IN_PROGRESS` with its product unreported despite `executed=4 missing=0 postflight=true`. The
  orchestration verdict must derive from `executed`, `missing` and `postflight` only; the RED count
  belongs in the ledger, where it already is. `:84`'s `die 'incomplete breadth'` is correct and stays.
  **(ii)** `:68` `die`s when `picked != 1`, aborting the whole loop — re-introducing stop-at-first-RED
  through a different door. It must record `NOT_SELECTED` for that ordinal and `continue`.
- **RA-57.9 — RA-52.6 now has a measured violation.** Identity 4 is the retained attempt RA-52.6's
  forward reading kept alive; it is RED at its `Produced` precondition
  (`tests/SurfaceCellsPhase10Tests.cpp:6506`), so the attempt **cannot run** and its guard is unexercised.
  Identity 1 is the same shape — the body throws inside `nonconstant_hard_rail_fixture()` on its first
  line, so the forged-germ rejection is never reached. Two guards are now known-unexercised for the same
  upstream reason. Both stay retained and fail-closed; nothing is retired.
- **RA-57.10 — a gtest suite name is not unique across targets.** `SurfaceCellPipelinePhase20` has
  members in `tests/SurfaceCellREPackageTests.cpp` (producer target, `cmake/DirectionalTests.cmake:83`)
  **and** `tests/SurfaceCellPipelinePhase20Tests.cpp` (historical target, `:571`). A bare `Suite.*`
  filter denotes different sets in different binaries. Obligations are cited by fully qualified
  `Suite.Name` only; a suite-level filter must never name one.
- **RA-57.11 — a throwing fixture singleton has a blast radius.** `nonconstant_hard_rail_fixture()`
  (`tests/SurfaceCellTransitionQuotientTests.cpp:855-858`) is a `static` function-local singleton; it
  throws, so **every** consumer goes RED with it — `:2837`, `:2863`, `:3890`, `:8813`, `:8858`, `:9112`,
  plus `make_nonconstant_hard_rail_fixture(true)` at `:2935`. Consistent with the carrier inventory's 19
  Quotient-owned members, and it predicts that one upstream repair clears them together. The census must
  record **which fixture singleton** each failing identity hangs off, or it will count one defect many
  times and read it as many defects.
- **RA-57.12 — the census design is amended, and a lesson is minted.** RA-56 said the along/across
  question would be decided "from `faceEnds`". RA-57.5 decided it and in doing so showed `faceEnds` is an
  **echo set** (RA-56.1) with low discriminating power: byte-identical across two mesh families, two
  fields, two transitions and two parameters. The census keys instead on fields that vary — `routeLength`,
  `step`, `chi`, the probe charts and parameters, the owning fixture singleton, and `closedChainPresent`
  — and `faceEnds` repetition is never read as corroboration. **LESSONS: a signal that never varies is
  not a measurement.** Four identical `faceEnds` looked like four confirmations and were one echo printed
  four times.

## RA-56 — the first RED is a live reproducer of the 39-identity `A4_ROUTE_CERTIFICATE_REJECTION` carrier, not a new candidate **FROZEN at M6-CP3-TB1-R4-WITNESS-REV** (2026-10-15)

Adjudicates `M6-CP3-TB1-R4-WITNESS-EXEC` and `M6-CP3-TB1-R4-WITNESS-REV`. The execution and its
root-cause localization are **ACCEPTED and independently re-derived**; the **classification is REJECTED
and corrected**; the proposed repair turn is **RETAINED but DEFERRED** behind two measurement rungs. No
runtime credit beyond the single executed identity. RA-55, RA-54, RA-53, RA-52 less .5, RA-51 … RA-37a
and the RA-34.3 stop gates stand. Decision record
`.agents/Directional/Architecture_M6_CP3_R4_First_RED_Carrier_Reclassification_Review_Decision.md`.

- **RA-56.1 — the root cause is CONFIRMED from bytes and from geometry I re-derived.** `exact_corner`
  (`src/geometry/SurfaceCellTracing.cpp:19131-19143`) demands a bit-exact one-hot barycentric for **both**
  paired points at the **same** terminal vertex, else `no-exact-terminal-corner` at `:19152`. The fixture
  (`tests/SurfaceCellsPhase10Tests.cpp:223-264`) is a 3×3 planar grid with `v1 = (1,0,0)`, `v4 = (1,1,0)`,
  `v7 = (1,2,0)`, face `0 = (0,1,4)`, face `3 = (1,5,4)`, hard feature `{1,4} ∪ {4,7}` (`:266-272`), so the
  rail is `1 → 4 → 7` with terminals `{1,7}`. Both probes resolve to **the same point**
  `0.75·v1 + 0.25·v4 = (1, 0.25, 0)`, interior to edge `(1,4)` at parameter `0.25` and equal to neither
  terminal. `corner[1]=0,0; corner[7]=0,0` is correct behaviour. **The co-signal is not a second defect:**
  `currentFace=0; expectedFace=2` are `failure.face`/`failure.targetFace` (`:18939-18940`) falling back to
  `first.from.face`/`second.to.face`, which `faceEnds=0,2|0,3` prints as the same values (`:18948`,
  `:18951-18952`). This is **not** an `RP-01` namespace recurrence and must not start one.
- **RA-56.2 — the classification is WRONG; `R4-TB-A-RP02-01` is not baseline-free.** All **21** other uses
  of `build_rectangular_hard_rail_phase_front` also open by asserting `Produced`, so the whole family is
  down, not one witness's precondition. Two of them — `ProductionA4PublishesAcceptedA2bA3ConformityReceipt`
  and `HardRailPairingIsFaceRowOrderInvariant` — sit **inside frozen `selector449`**
  (`Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt`, pinned at
  `tools/m6_cp3_entry_497_artifact_only_harness.sh:16`). `Entry_R3_Red_Classification.tsv` already carries
  the failure: the 94 R3 RED split into eight carriers whose largest is
  **`A4_ROUTE_CERTIFICATE_REJECTION` at 39**, with **37 `CP2_ACCEPTED = true`**; that set matches the
  long-carried "39 endpoint" backlog **39/39 with nothing unmatched on either side**
  (`Architecture_M6_CP3_R4_Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv`), and **37 of the 39
  lie inside the frozen 497** (26 `selector449`, 9 `focused30`, 2 `focused12`) — the same 37, i.e. **37 of
  the 88 carried CP2 losses**. Corrected: this is a **new, cheap entry point into an existing carrier with
  an accepted CP2 baseline**, and it is the most valuable result TB-A could have produced — an 8 ms,
  single-test, fully typed reproducer of **~42% of the carried CP2 losses**. The review undersold itself.
- **RA-56.3 — measure the carrier before repairing anything.** All **39** are owned by
  `directional_surface_cell_producer_tests`, the binary already inside the immutable package that ran
  TB-A (19 Quotient / 18 Phase10 / 2 REPackage), and every one is recorded
  `status = "STATIC ONLY — current result unknown"`. **38 of the 39 hint `endpoint-0`; TB-A observed
  `endpoint-1`.** A producer change driven by the single *minority* endpoint, while 38 majority instances
  sit unmeasured and reachable for one artifact-only run with no rebuild, is how the wrong thing gets
  fixed confidently.
- **RA-56.4 — RA-55.8's stop-at-first-RED rule was wrong for a triage run; my error, amended.** The rule
  is right **inside a repair loop**, to stop mass-patching; it is wrong for a **first measurement**, where
  breadth is the point. The executor followed it exactly and is not marked down. It cost the **control**
  (`M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm`, a *different* fixture — the one bit that
  separates "this fixture family is down" from "A4 production is down") plus three identities runnable
  from the same artifact. **Amended rule in force:** stop at first RED only **within a dependent chain**;
  independent identities are **all** run, each RED reported with its verbatim first predicate.
- **RA-56.5 — a third reading the repair plan excludes by vocabulary.** `faceEnds=0,2|0,3` decodes
  (`:18948`) as `first.from.face = 0`, `second.to.face = 2`, `first.to.face = 0`, `second.from.face = 3`:
  the first front lies **entirely inside face 0** and the second spans 3 → 2, both meeting at
  `(1, 0.25, 0)`. That is the signature of two fronts meeting **transversally across** the rail, not of
  intervals running **along** it. The plan's prescribed *"canonical intrinsic parameter on the same source
  edge, ordered rail interval/face-side ownership"* presumes along-rail intervals; if the event is a
  crossing, that abstraction is wrong and would freeze a mis-shaped certificate into the producer — the
  RA-45.2 category error again. **Do not choose the certificate model before the census says which shape
  dominates**; every failing pair prints its own `faceEnds`.
- **RA-56.6 — the repair plan is otherwise sound and is RETAINED, not discarded.** It refuses to pick a
  fix merely to satisfy the assertion, keeps `no-exact-terminal-corner` and the duplicate-contact,
  barrier, closed-chain and missing-contact guards fail-closed for genuine terminals, forbids weakening
  the RP-02 `Produced` precondition or its consumer receipt, bars fallback and source-grid recovery, and
  carries real stop conditions. Re-enter it **with the census in hand** and with RA-56.5 answered.
- **RA-56.7 — what remains true.** `RP-02` is **still open**: the run died before
  `assign_open_front_boundary_authority`, so no consumer receipt exists and the tamper half never ran.
  RA-55.3's non-vacuity finding is undisturbed, but non-vacuity is not liveness. `R4-OHF-02` stays
  recorded, guard retained, no probe. The two Phase14 identities need `DIRECTIONAL_BUILD_HISTORICAL_TESTS`
  (`cmake/DirectionalTests.cmake:556-574`) and belong to a separate packaging turn, not a measurement rung.
- **RA-56.8 — accounting.** Ledger **66 / 17 / 49**, debt **1**, selector **497** untouched, CP2
  **491/491** accepted, R3 **403/497** rejected with 94 RED and 88 carried losses, PR #8 draft/open —
  unchanged. `R4-TB-A-RP02-01` is reclassified as an entry point into the existing
  `A4_ROUTE_CERTIFICATE_REJECTION` carrier; **no new stable event, category or recurrence is minted**,
  since a recurrence needs a reviewed runtime adjudication the census has not yet supplied. No promotion.
  A compile is not a restoration (LESSONS 160); a census is not a witness (LESSONS 171); **and one
  measured identity is not a measured carrier.**

---

## RA-55 — R4 Code + Build authoring is CLOSED; Test + Benchmark AUTHORIZED in two rungs **FROZEN at M6-CP3-CB1-R4-RP02-WITNESS** (2026-10-15)

Adjudicates `M6-CP3-CB1-R4-OHF01-PROBE` and `M6-CP3-CB1-R4-RP02-WITNESS`. Both **ACCEPTED**; every
decisive claim re-derived from bytes at `1e0e13a38`. No runtime credit. RA-54, RA-53, RA-52 less .5,
RA-51, RA-50, RA-49, RA-48, RA-47, RA-46, RA-45, RA-44 less .2, RA-43, RA-42 corrected, RA-41 frozen
scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates stand. Decision record:
`.agents/Directional/Architecture_M6_CP3_R4_Authoring_Closeout_And_TB_Authorization_Review_Decision.md`.

- **RA-55.1 — OHF-01's answer (b) UNREACHABLE is CONFIRMED on the checked construction path.** G1:
  `include/directional/core/TriMesh.h:331-350` calls `compute_edge_quantities(verbose)` **unconditionally**
  at `:339`, before the injected-table comparison at `:340-350` that throws on mismatch — supplied
  `_EV/_FE/_EF` are a claim to be checked, never trusted input. G2: `check_consistency`'s signature at
  `include/directional/core/DCEL.h:1164-1169` places **`checkHalfedgeRepetition` second**, so
  `check_consistency(verbose, true, true, true)` at `TriMesh.h:159-163` enables it; section 5 at
  `DCEL.h:1453-1492` rejects the second appearance of a directed `(source, target)` pair, and three
  triangles on one undirected edge force a duplicate across only two directions — orientation-independent.
  G4: the atlas pin at `src/geometry/SurfaceCellTracing.cpp:8137-8145` precedes the census construction at
  `:8243-8266` and the emission at `:8270-8277`, and `FieldTransportAtlas::matches_source_faces`
  (`src/authority/FieldTransportAtlas.cpp:3090-3110`) binds `sourceFaces` row-by-row to the atlas's own
  construction faces. **G5 is correctly demoted**: the report declined to rest on the produced-path
  rejection because the factory is independently callable. That distinction is the one I asked for.
- **RA-55.2 — the retirement is CONDITIONAL; new finding `R4-OHF-02 / UNCHECKED_MESH_PROVENANCE`.** The
  soft link is **G3, not G1/G2**. `FieldTransportAtlas::make`
  (`src/authority/FieldTransportAtlas.cpp:1893-1912`) validates the edge tables **by shape only** and never
  re-runs `DCEL::check_consistency`; it then consumes `sourceMesh.EF(edgeIndex, 0..1)` as adjacency
  authority, so a third incident face is not rejected there — it is merely absent from a two-column table.
  Whether the downstream `MissingAdjacency`/`NonReciprocalAdjacency` checks would catch such a mesh is
  **not established and must not be asserted.** Unreachability therefore rests on the convention that every
  production `TriMesh` is built through `set_mesh`, not on a type-level invariant: `V`, `F`, `EV`, `EF` are
  public and mutable. Binding consequences: (1) the OHF factory-negative requirement is **RETIRED**, coupled
  to G1, G2, G4 **and** `R4-OHF-02`; (2) the guard at `SurfaceCellTracing.cpp:8270-8277` and the
  `OverfullHardFeatureIncidence` sub-code are **RETAINED** unchanged — the guard is the only thing between
  `R4-OHF-02` and a silently accepted non-manifold carrier, and it is fail-closed; (3) `R4-OHF-02` is
  **recorded, not chased** — probing it would be a seventh Code rung invented to avoid the execution
  boundary, which RA-54.7 forbids; (4) any change letting production code reach a `TriMesh` without
  `set_mesh`, or relaxing G1/G2/G4, **reopens reachability** and requires a non-vacuous witness before merge.
- **RA-55.3 — the RP-02 witness MEETS its anti-vacuity bar, structurally.** **Exactly one site in the
  translation unit assigns a `HardRail` boundary kind**: `edge.boundaryKind = *kind` with
  `edge.railId = railId` at `src/geometry/SurfaceCellTracing.cpp:12619-12620`, inside
  `assign_open_front_boundary_authority` (`:12414-12625`). The only other two `boundaryKind` assignments,
  `:14745-14746` and `:18629-18630`, write `PeriodicCut`. Reaching `:12619` requires surviving the
  network-bound `rail_interval_refs` at `:12425-12428` (`options.fieldAlignedNetwork`,
  `RequireTypedSource`), which returns `InvalidFrontBoundaryAuthority` at `:12429-12431` otherwise. A
  published `HardRail` edge **is itself the consumer's receipt**, so `ASSERT_NE(consumedRail, nullptr)`
  cannot pass if the consumer is skipped. None of the four prohibited shapes is present: it is not an A2a
  publication assertion, not a call the test makes itself, not a stage-injected run, not a factory-only
  rejection. The test goes further and resolves every consumed key through
  `fieldNetwork->find_mandatory_edge` with `EXPECT_EQ(rail->id, mandatory->rail)`, binding the receipt to
  the real network rather than to the edge's self-report.
- **RA-55.4 — the negative's anchor is discriminating, and quantified.** `InvalidFrontBoundaryAuthority` is
  emitted at **66** `set_phase_front_failure` sites in `src/geometry/SurfaceCellTracing.cpp`, of which
  **only 4** supply a cell/side (`:13052`, `:14784`, `:17439`, `:17448`); the helper defaults
  `cell = -1, side = -1` (`:11330-11335`) and is first-failure-wins (`:11336-11338`). The test's
  `EXPECT_GE(failure->cell, 0)` with `side ∈ [0,4)` therefore **excludes 62 of 66**, and the four anchored
  sites test owner-cell lookup and `filledSide` range, which a `sourceEdges` substitution does not perturb.
  **Caveat stated, not hidden:** the expectation is authored and compiled, never executed. If the forgery is
  caught earlier at runtime the test fails — the correct direction, and a TB finding, not an authoring defect.
- **RA-55.5 — the test-helper override weakens nothing.** One defaulted trailing parameter and
  `options.authoritativeRails = rails != nullptr ? *rails : fixture.rails;`. Every pre-existing call site is
  byte-identical in behaviour; no guard weakened, no counter added, no production API touched. Under RA-52.6
  read forward — *a retained guard needs a retained attempt* — a test-side affordance whose only purpose is
  to feed the guard a forgery is exactly right.
- **RA-55.6 — CORRECTION to RA-54.2, my own prior acceptance.** I wrote that the seven
  `SurfacePhaseFrontSourceAuthorityDetail` values "cover exactly the reachable predicates." With OHF-01
  answered (b) that is one too generous: the correct statement is **six reachable predicates and one
  fail-closed-only sub-code**. This does **not** reopen RA-51.7, which forbids *minting* a sub-code for a
  disjunct already known dead — when RA-46.6 minted this one its reachability was the open question OHF-01
  was commissioned to answer. The sub-code stays, per RA-55.2(2). Recorded rather than quietly amended,
  per `RP-03`.
- **RA-55.7 — R4 Code + Build authoring is CLOSED, verified rather than reported.** RA-54.7 left exactly two
  authoring items; both are discharged. No third item was left open and nothing outside the authorized scope
  moved — the interval's whole diff is `tests/SurfaceCellsPhase10Tests.cpp` (+89/-2), two evidence documents
  and the beacons. **The Implementation Agent's refusal to invent a further Code rung is correct and accepted.**
- **RA-55.8 — Test + Benchmark is AUTHORIZED, in two rungs, narrowly.** Withholding execution further would
  convert a boundary into a stall. **TB-A `M6-CP3-TB1-R4-WITNESS-EXEC`** executes **only** the
  authored-but-never-executed witnesses, as a named supplemental run **outside** the frozen 497, exactly as
  the four RA-40(C) supplementals sit outside it; the frozen selector files stay byte-identical, their
  hashes pinned at `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh:211-217` and
  re-checked at `:270-272`. It answers one question: **does roughly ten turns of authoring survive first
  contact with a running binary?** **TB-B `M6-CP3-TB1-R4-497-EXEC`**, only after TB-A, re-measures the frozen
  `30 + 12 + 449 + 6 = 497` gate to establish whether R3's 94 RED has moved. The two must not be folded
  together: a mixed run makes a supplemental failure indistinguishable from a selector regression.
  **Neither rung may edit source to obtain green** — a RED is a finding to report, and the fix is a
  separately authorized CB turn under Review.
- **RA-55.9 — no credit conferred.** No source, test, header, selector, harness, fixture, benchmark or
  ledger changed in this Review. Ledger **66 / 17 / 49**, M6 debt **1**, selector **497** untouched, CP2
  **491/491** accepted, R3 **403/497** rejected with 94 RED and 88 carried CP2 losses, PR #8 draft/open.
  A compile is not a restoration (LESSONS 160); a census is not a witness (LESSONS 171); an authored
  expectation is not a PASS.

---

## RA-54 — the six-rung ladder is ACCEPTED and CLOSED; the source-only vein is exhausted **FROZEN at M6-CP3-CB1-R4-RA434-DISPOSE** (2026-10-14)

Adjudicates the seven turns from `M6-CP3-CB1-R4-CARRIER-CUT-COMMENT` through `M6-CP3-CB1-R4-RA434-DISPOSE`.
Every decisive claim was re-derived from bytes and **CONFIRMED**; no report was taken on trust. No runtime
credit. RA-53, RA-52 less .5, RA-51, RA-50, RA-49, RA-48, RA-47 (**now fully discharged**, see RA-54.3/.4),
RA-46, RA-45, RA-44 less .2, RA-43 (**now fully discharged**, see RA-54.1/.5), RA-42 corrected, RA-41 frozen
scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates stand.

- **RA-54.0 — six consecutive no-op dispositions were audited, not accepted.** A ladder whose rungs all
  conclude "nothing to do" is the shape a rubber stamp takes, so each was checked independently. **All six
  are correct.** The single source change in the interval is one comment line
  (`src/geometry/SurfaceCellTracing.cpp:1457`), with the `continue` at `:1460-1467`, the `SourceBoundary`
  distinction and the RA-43.1 citation all intact — exactly the authorized scope and nothing else.
- **RA-54.1 — RA-48.3's residual is CLOSED.** The `FieldTransportAtlas` class comment no longer claims
  construction is the only validation seam; `include/directional/authority/FieldTransportAtlas.h:829-836`
  now states that construction validates source authority and that injected edge tables must come from a
  checked `set_mesh`. It was corrected before this interval, so the rung's "already done" report is accurate.
  **RA-48 is fully discharged.**
- **RA-54.2 — RA-46.6 is DISCHARGED; the typed sub-codes exist and honour RA-51.7.**
  `SurfacePhaseFrontSourceAuthorityDetail` (`include/directional/geometry/SurfaceCellTracing.h:1873-1881`)
  carries exactly seven values — `MissingTerminalA3Path`, `AmbiguousTerminalA3Path`, `AtlasSourceMismatch`,
  `MalformedSourceEdgeKey`, `AbsentHardFeatureIncidence`, `OverfullHardFeatureIncidence`,
  `MissingRailTerminalContact` — carried on `SurfacePhaseFrontProductError` and preserved through
  `publish_phase_front_result` onto `SurfacePhaseFrontFailure::publishedProductSourceAuthorityDetail`.
  **No sub-code was minted for `missing-or-nonreciprocal-terminal-A3`'s dead disjunct, for
  `overlapping-terminal-sectors`, for `nonmanifold-terminal-star-spoke` or for the refuted `R4-SID-02`.**
  The RA-51.7 constraint was honoured exactly.
- **RA-54.3 — RA-47.11 is DISCHARGED as a genuine zero-target.** All six surviving `source_edge_index` call
  sites in `tests/FieldAlignedCurveNetworkTests.cpp` (`:614`, `:912`, `:1032`, `:1744`, `:5585`, `:6413`)
  immediately index `mesh.EF(...)` or iterate `mesh.EV` rows. Each takes a **typed key as identity** and the
  returned int **only as a DCEL row**. RA-47 abolished the raw-int source-edge *namespace*, never the
  typed-key-to-row bridge. Migrating these would have been a fabricated change; declining was correct.
- **RA-54.4 — RA-47.12's `RP-02 TEST_AUTHORITY_COVERAGE_GAP` is ACCEPTED, and its decisive link confirmed.**
  The report's load-bearing claim is that `src/geometry/SurfaceCellTracing.cpp:10498-10502` is not reached on
  the produced path. **Confirmed:** `build_surface_cell_network` returns at `:19567` for a produced phase
  front, before `generate_deterministic_surface_seeds` and before any `trace_surface_field` call. The
  authoritative open-front consumer at `:12414-12428` is therefore the only network-bound ingress, reached
  conditionally from `:13058`, `:14790`, `:17412`. A static call route exists; **executed liveness does
  not.** The report correctly refused to claim either a PASS or unreachability, and its stated acceptance
  criterion — *the assertion must fail if the whole consumer is skipped* — is the correct anti-vacuity bar
  (LESSONS 171). RA-47 is otherwise fully discharged.
- **RA-54.5 — RA-43.4 is DISCHARGED; the residue census is complete.** Exactly two non-`rail_interval_refs`
  helpers carry authority-relaxing surface: `rail_sample_source_vertex` (`:5858-5886`) and
  `rail_sample_geometry_is_valid`'s `publishedSourceVertex = std::nullopt`
  (`include/directional/geometry/SurfaceCellTracing.h:2489-2492`). Independently re-scanned: no other
  declaration in that region takes a defaulted authority argument. **Retain both unchanged**, on the RA-52.6
  ground: a permitted bypass attempt is what makes the override demonstrably live. The RA-52.6 caller table
  was restated verbatim and is unchanged. **RA-43 is now fully discharged — .1 LANDED, .2 DISCHARGED,
  .4 DISPOSED.**
- **RA-54.6 — `R4-OHF-01 / UNTESTED_LIVE_DISJUNCT` (new, narrow).** `OverfullHardFeatureIncidence` is minted
  at `src/geometry/SurfaceCellTracing.cpp:8270-8277` when a hard-feature edge is incident to **three or more
  source triangles**, counted from `sourceTopologyRegions.regions()` rather than from any two-face cache
  (`:8246-8264`). Its sibling disjunct `AbsentHardFeatureIncidence` has a genuine factory witness
  (`tests/SurfaceCellTransitionQuotientTests.cpp:9171-9183`, a real mutated `hardFeatureEdges` set through
  `checked_with_routes_and_contacts`); the overfull disjunct has **none**. This is **not** an RA-51.7
  violation: the factory is independently callable, so the disjunct is plausibly live at the factory boundary
  even where `build_surface_cell_network`'s own guard (RA-46.9, `:18848-18857`) would reject first on the
  produced path. **Reachability must be settled before a fixture is written**, by the RA-51/RA-53 discipline:
  if a `SourceTopologyRegions` with a 3-incident hard-feature edge is constructible, author the mirror
  witness; if it is not, retire the disjunct coupled to the guards that prevent it and keep `:8270-8277`
  fail-closed. **Do not weaken the guard either way.**
- **RA-54.7 — the source-only vein is EXHAUSTED; what remains is authoring and execution.** With RA-43,
  RA-47 and RA-48 fully discharged and RA-46.6 closed, no Code + Build obligation remains that can be
  answered by reading source. Exactly two authoring items are left — `R4-OHF-01`'s resolution (RA-54.6) and
  the `RP-02` consumer-boundary witness RA-47.12 specified. **Everything else is execution**, which requires
  a separately authorized immutable-artifact Test + Benchmark turn: `R4-JCT-01`, RA-49.2's witness, the
  Phase10 network-override and Phase14 exact-corner negatives, the 39 endpoint / 34 Phase10 / seven DCEL /
  six CP3 identities, the **88** accepted CP2 restorations, the organic D1/D2/D3/D5 and A6/A7 witnesses and
  the odd-τ witness. **No further Code + Build rung may be invented to avoid that boundary.**
- **RA-54.8 — no credit.** Ledger unchanged **66/17/49**, debt **1**; CP2 **491/491** accepted; R3
  **403/497** rejected with **94** RED and **88** accepted losses carried. `R4-JCT-01` stays AUTHORED /
  COMPILED / NOT EXECUTED; RA-41's junction and sector clauses stay frozen **UNEXERCISED at runtime**. A
  compile is not a restoration (LESSONS 160); a census is not a witness (LESSONS 171).

---

## RA-53 — the R4-SID-02 probe is ACCEPTED; RA-52.5 is WITHDRAWN as a Review Agent error **FROZEN at M6-CP3-CB1-R4-SID02-PROBE** (2026-10-14)

Adjudicates `Architecture_M6_CP3_R4_SID02_Produced_Cell_Reachability_Probe_20261014.md`. The probe answered
**(b) UNREACHABLE** with a complete producer census and a correct guard chain; every decisive link was
re-derived from bytes and **CONFIRMED**. No runtime credit. RA-52 stands **less .5**; RA-51, RA-50, RA-49,
RA-48, RA-47, RA-46 (.5 per RA-51.5, .6 per RA-51.7), RA-45, RA-44 less .2, RA-43 (.1 LANDED, .2 DISCHARGED,
less .5), RA-42 corrected, RA-41 frozen scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates stand.

- **RA-53.0 — RA-52.5 is WITHDRAWN, not merely closed.** RA-52.5 asserted that
  `src/pipeline/RemeshPipeline.cpp:3562-3596` is "blind" to `corners[0]==corners[2] && corners[1]==corners[3]`
  and that the configuration dies only at A7. **Both halves were wrong**, and the error was mine: I read
  `trace_equal` as the load-bearing conjunct and treated `lattice_equal` as corroboration. `lattice_equal`
  (`:3312-3319`) compares `latticeCoordinate` with **`==` on exact integers**, plus `branchRotation`,
  `scaleLevel`, `sourceChart` and phase. Every producer assigns the four corners the four **distinct**
  integer pairs `(u,v)`, `(u+1,v)`, `(u+1,v+1)`, `(u,v+1)` (`src/geometry/SurfaceCellTracing.cpp:12940`,
  `:14636-14637`, `:17188-17212`), so side 0's lattice pair `((u,v),(u+1,v))` can never equal side 2's
  `((u+1,v+1),(u,v+1))`. **`:3562-3596` is the discriminator, with no tolerance dependence at all.**
  `R4-SID-02` is **REFUTED**; there was never a locus gap to repair, and no A5 guard is owed.
- **RA-53.1 — the producer census is complete and the rejection is pre-publication.** Exactly three
  region-build variants are dispatched, as a cascade on `NotApplicable`
  (`src/geometry/SurfaceCellTracing.cpp:17819-17833`). The uniform planar producer runs
  `orient_and_validate_phase_front_cell` (`:12627`, called `:12957`), which rejects **all six** distinct
  corner-position pairs closer than `max(1e-12, 1e-9 * target)` at `:12640-12649`, before the loop-normal
  test and before the append. The periodic-annulus (`:14682-14709`) and curved bounded-disk (`:17230-17262`)
  producers require `phase_front_loop_normal` finite with `squaredNorm() > 1e-24`; that function is
  `Σ p_i × p_{i+1}` (`:12354-12362`), which for an alternating `A,B,A,B` cycle is
  `A×B + B×A + A×B + B×A = 0` by anticommutativity. **All three reject before publication.**
- **RA-53.2 — the probe's own scope caveat is noted and DISSOLVED.** The probe correctly declined to extend a
  strict equal-point result to *near*-equality under `trace_equal`'s `1e-10` barycentric tolerance
  (`:3307-3310`), and correctly refused to construct a universal numerical theorem. That restraint was right
  discipline and is credited. The caveat is nevertheless **moot for `R4-SID-02`**: per RA-53.0 the
  discriminator is the exact integer lattice comparison, which no barycentric tolerance can defeat. **No
  follow-up turn is owed for the near-equality case.**
- **RA-53.3 — one guard the Review Agent missed is recorded.** `SurfaceQuotientProducer` rejects a classed
  cell with fewer than four distinct corner classes as `DegenerateClassedQuad`
  (`src/pipeline/RemeshPipeline.cpp:6343-6350`), at the **quotient** stage. RA-52.5's claim that A6's
  adjacent-only check (`:8446-8449`) and A7's `quad-degenerate` (`:7482-7486`) were the only downstream
  closures was therefore incomplete as well. Four independent closures exist; none is late.
- **RA-53.4 — the probe's conduct is the reusable shape, after RA-51.0.** It answered the one question asked,
  delivered the permitted verdict, declined to repair in the same turn, declined to amend a frozen clause
  itself, and bounded its own claim. **It also corrected the Review Agent**, which is the behaviour the
  adversarial cadence exists to produce. Recorded as the second instance of a correct feasibility answer, and
  the first in which the implementation side's argument was **stronger** than the reviewer's.
- **RA-53.5 — no credit.** Source-only inspection; no build, no executable, no test, no benchmark, no source
  mutation. Ledger unchanged **66/17/49**, debt **1**; CP2 **491/491** accepted; R3 **403/497** rejected with
  **94** RED and **88** accepted losses carried. `R4-JCT-01` stays AUTHORED / COMPILED / NOT EXECUTED;
  RA-41's junction and sector clauses stay frozen **UNEXERCISED at runtime**.

---

## RA-52 — the selected-branch join is REFUSED; the RA-43.4 opt-out is PRESERVED **FROZEN at M6-CP3-CB1-ENTRY-R4** (2026-10-14)

Adjudicates `Architecture_M6_CP3_R4_Source_Current_Review_Gate_20261014.md`. Basis:
`Architecture_M6_CP3_R4_Selected_Branch_And_Diagnostic_Optout_Review_Decision.md`. **The REVIEW_BLOCKER is
DISSOLVED; both offered options are REFUSED.** No runtime credit. RA-51, RA-50, RA-49, RA-48, RA-47
(.1–.10 implemented; .11/.12 open), RA-46 (.5 as amended by RA-51.5; .6 constrained by RA-51.7), RA-45,
RA-44 (less .2), RA-43 (less .2 DISCHARGED, less .5, and with **.1 now LANDED**), RA-42 as corrected,
RA-41 frozen scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates stand.

- **RA-52.0 — `R4-VIN-01 / STALE_FROZEN_VINTAGE`, the third graded failure of a feasibility STOP.** The gate
  demands Review of RA-43.2, which **RA-50.1 DISCHARGED** by bytes, without citing RA-50; and its option (B)
  receipt ends in `filled cell/side`, the exact object **RA-50.2 REFUSED**, without engaging the refusal; and
  it treats RA-43.1 as open when RA-43.1's sole outstanding element — the carrier cut — is **LANDED** at
  `src/geometry/SurfaceCellTracing.cpp:1457-1467`. The family is now graded: **RA-49.0 wrong stage**,
  **RA-50.0 wrong extent**, **RA-51.0 neither (correct shape)**, **RA-52.0 wrong vintage**. Standing rule for
  every future STOP: *before raising RA-N as a blocker, cite RA-N's most recent disposition and say why it
  does not apply.*
- **RA-52.1 — Review A answered: option (A) is REFUSED because the join would have no consumer.** Every use
  of `SurfaceTraceSegment::family` in `src/pipeline/RemeshPipeline.cpp` is a `hash_combine_i64` digest input
  (`:1989`, `:2204`, `:2264`, `:2350`, `:2473`, `:2574`, `:2631`) or a copy-through (`:10749`). Inside A4 the
  only gating reads are same-frame run-merge equalities against the immediately preceding segment
  (`src/geometry/SurfaceCellTracing.cpp:12111`, `:13533`). **No decision anywhere depends on the absolute
  value.** A digest cannot separate a correct branch selection from an incorrect one, because a
  wrong-but-consistent `family` hashes consistently; any regression asserting otherwise is **vacuous** in the
  LESSONS 171 sense.
- **RA-52.2 — option (B) is REFUSED as RA-45.2's category error, third instance.** RA-45.2 withdrew RA-44.2
  for "demand[ing] absolute authentication of a relationally-consumed quantity"; RA-50.2 refused the
  oriented-germ receipt adjacently. Minting a `FieldBranch` receipt would **manufacture** the consumer that
  does not exist, creating a fresh unsatisfiable obligation of exactly the kind RA-45, RA-50 and RA-51 have
  now retired three times. **No selected-branch receipt may be specified, authored or requested.**
- **RA-52.3 — the sixth namespace: A4 never consumes A2a trace segments.** The complete census of
  `options.fieldAlignedNetwork` in `src/geometry/SurfaceCellTracing.cpp` is singularity ports/vertices/index
  (`:5374-5375`, `:5382-5387`, `:5393-5399`, `:9955-9957`), mandatory edges (`:6137-6139`, `:6230-6232`) and
  the digest binding (`:5666-5676`). `FieldAlignedCandidateTraceSegment` — the sole carrier of
  `authority::FieldBranch` on the A2a side (`include/directional/geometry/SurfaceCellTracing.h:401-423`) —
  **is never read by A4**. The A2a network's authority over A4 is mandatory edges and singularities; trace
  identity is not part of that contract. Add as the **sixth namespace** beside RA-43.3's four and RA-50.2's
  fifth, and as the **tenth** publish/don't-invent instance and its **third** structural variant: *do not
  demand a join between two namespaces that have no data path, when neither side's consumer reads the
  quantity absolutely.*
- **RA-52.4 — filled-side provenance has a second, independent closure.** Beyond RA-50.4's
  `src/pipeline/RemeshPipeline.cpp:5003-5004` / `:5008-5012`, the block at `:3562-3596` requires
  `(filledCell, filledSide)` uniqueness, region agreement, `trace_equal(edge.from,
  owner.corners[filledSide])` and `trace_equal(edge.to, owner.corners[(filledSide+1)%4])`,
  `lattice_equal` on both lattice states, and `isolation_sheets_connected`. **Two independent closures stand
  where the gate asserts none.** RA-50.4's "there is no seam" is re-confirmed on bytes RA-50 did not read.
- **RA-52.5 — `R4-SID-02 / LATE_DEGENERACY_LOCUS` (new, bounded).** `:3562-3596` is blind to exactly one
  configuration: `corners[0]==corners[2]` **and** `corners[1]==corners[3]`, where sides 0 and 2 present an
  identical corner pair. A6's collapsed-edge guard tests **adjacent** corners only (`:8446-8449`). The case
  dies at A7 `:7482-7486` (`std::set<int>(certified.vertices).size() != 4U` → `quad-degenerate`). It is
  therefore **closed at the wrong locus**: a side-authority defect surfaces three stages downstream as a
  geometry degeneracy. **Diagnostic-locus finding, not a correctness hole.** Reachability must be established
  before any repair; if no produced cell can have equal opposite corners, record it unreachable and retire
  coupled to `:7482-7486`, per the RA-51 discipline. **No new producer, no new receipt, no new namespace.**
- **RA-52.6 — RA-43.4: the opt-out is PRESERVED, scoped and census-bound.** All three non-test callers of
  `rail_interval_refs` pass `RequireTypedSource` **explicitly**
  (`src/geometry/SurfaceCellTracing.cpp:10498-10502`, `:12426-12428`,
  `src/pipeline/RemeshPipeline.cpp:9630-9634`); the declared default is also `RequireTypedSource`
  (`include/directional/geometry/SurfaceCellTracing.h:2497-2510`), so omission is safe and the exception must
  be **named**. `fieldAlignedNetwork != nullptr` forces typed vertices and a published edge list regardless
  of mode (`:5975-5985`), and `:6137-6147` independently checks mandatory edge/rail/kind/component.
  **Removing the opt-out would make the override claim vacuous**: the Phase10 negative
  (`tests/SurfaceCellsPhase10Tests.cpp:6502-6595`) is the only artifact showing the override is load-bearing,
  and it can only be authored through the opt-out — the guard-coupled-retirement principle read **forward**,
  *a retained guard needs a retained attempt.* **Add no machinery**: no tag type, no builder, no separate
  header. The standing obligation is a **one-line census** restating the caller table whenever a
  `rail_interval_refs` caller is added, removed or re-moded; a production caller with
  `LegacyStandaloneDiagnostic` is a REVIEW_BLOCKER on sight. RA-43.4's residue is narrowed to the **other**
  untyped standalone geometry diagnostics, which the mode migration neither disposed of nor claimed to.
- **RA-52.7 — one comment is narrower than the code it describes.** `src/geometry/SurfaceCellTracing.cpp:1457-1459`
  says "certified incident hard-rail carriers"; `:1460-1467` cuts **every** incident
  `FieldTransportBarrierKind::HardFeature` barrier, carrier or not. **The code is correct** — A3 transport
  cannot cross a hard feature, so cutting only the route's own carriers would yield a germ the field cannot
  traverse. The hazard is a future reader "repairing" the code to match the comment. One-line comment
  correction; **the `continue` may not be touched**.
- **RA-52.8 — `R4-JCT-01`: the multi-carrier junction witness is AUTHORED, not executed.**
  `tests/SurfaceCellREPackageTests.cpp` now asserts `EXPECT_GT(authenticatedJunctions, 0U)` ("this fixture
  must reach an actual produced multi-carrier junction"), `EXPECT_GT(authenticatedContactSteps, 0U)` and
  `EXPECT_GT(authenticatedJunctionSteps, 0U)` over `certificate.junctions` of a **produced** phase front,
  and checks A1's commuting square per junction step. Status moves **UNEXERCISED → AUTHORED / COMPILED / NOT
  EXECUTED**. RA-41's junction and sector clauses stay **frozen UNEXERCISED at runtime**; no runtime credit
  accrues from a compile (LESSONS 160). The gate's own reading of `:736-766` — that the loop over
  `frame->branches` shows *existence*, not *selection* — is **accurate**, and per RA-52.1 it closes the
  question rather than opening one.
- **RA-52.9 — landed and verified since RA-51; no credit.** RA-49.2's duplicated-endpoint witness is
  **correctly shaped** (`tests/SurfaceCellsPhase10Tests.cpp:7061-7095`: real produced
  `endpoints[0].terminalVertex`, duplicated, rejects at `ambiguous-terminal-contact`, with the
  `EXPECT_EQ(npos, ...)` anti-assertion excluding `no-exact-terminal-corner`) — **compiled, not executed**.
  RA-46.9 landed fail-closed (`src/geometry/SurfaceCellTracing.cpp:18848-18857`). RA-43.1's carrier cut
  landed. New first-consumer guards landed before the checked factory:
  `closed-rail-component-mismatch`, `terminal-contact-component-mismatch`, `closed-rail-chain-not-simple`,
  `closed-rail-endpoint-edge-not-owned`, `closed-rail-chain-non-hard-edge`. `field_aligned_network_binding_valid`
  landed (`:5666-5676`, gated `:18800-18807`). `append_edge_interval` is **no longer architecturally inert**:
  `src/pipeline/RemeshPipeline.cpp` re-derives source components from shared-edge face connectivity
  independently of feature-map metadata and rejects alias records, `>2` claimed incidence and
  boundary-class edges with other than one face. Ledger unchanged **66/17/49**, debt **1**; CP2 **491/491**
  accepted; R3 **403/497** rejected with **94** RED and **88** accepted losses carried.

---

## RA-51 — both remaining RA-49.7 negatives are UNREACHABLE and RETIRED (coupled) **FROZEN at M6-CP3-CB1-ENTRY-R4** (2026-10-13)

Adjudicates `Architecture_M6_CP3_R4_RA465_Terminal_A3_First_Rejection_Review_Stop_20261013.md` (`R4-TA3-01`).
Basis: `Architecture_M6_CP3_R4_Terminal_A3_First_Rejection_Review_Decision.md`. **The REVIEW STOP is
DISSOLVED. RA-49.7's two unadjudicated negatives are now adjudicated and BOTH are RETIRED, coupled to named
guards; both guards are KEPT fail-closed.** No runtime credit. RA-50, RA-49, RA-48, RA-47 (.1–.10 implemented),
RA-46 with .5 amended only as stated below, RA-45, RA-44 (less .2), RA-43 (less .2 as DISCHARGED, less .5 and
less the superseded `sourceEdges` row of §4), RA-42 as corrected, RA-41 frozen scoped, RA-40, RA-39, RA-38,
RA-37a and the RA-34.3 stop gates stand.

- **RA-51.0 — the request is ACCEPTED in shape and confirmed in substance.** It stated a *conditional*
  inference, explicitly refused to claim universal unreachability ("Do not claim universal unreachability
  yet"), named its own counterexample class, and asked the one question that decides the matter. That is the
  correct form for a feasibility stop, and both of its provisional inferences are confirmed. Contrast RA-49.0
  (wrong stage) and RA-50.0 (wrong extent): this stop made neither error.
- **RA-51.1 — Review A: the ingress census is CLOSED at two variants.** The primary
  `build_surface_cell_network` (`src/geometry/SurfaceCellTracing.cpp:18743`) and the convenience overload
  (`:20011`), which computes axes from the cross field and **delegates to the primary on both branches**. The
  atlas gate at `:18771-18774` therefore dominates every path to the terminal loop. **No atlas built for a
  distinct source can pass it:** `FieldTransportAtlas::make` pins the regions to its own `sourceMesh.F` at
  `src/authority/FieldTransportAtlas.cpp:1909-1910` and stores `rowTopology_` from them at `:1926`, while the
  consume-side gate pins `rowTopology_` row-by-row to `faces` (`:3101-3108` with
  `include/directional/geometry/SourceTopologyRegions.h:151-188`), and `:18756-18764` **replaces** a
  non-matching supplied authority with one built from `faces` so no path carries inconsistent regions.
  Composing: `key(faces.row(r)) == key(sourceMesh.F.row(r))` for every `r`, hence an **identical undirected
  edge set with identical per-edge incidence**. There is no "same regions, different edges" atlas.
- **RA-51.2 — the distinction the request asked for: `NonTraversable` ≠ missing value.** In `make`'s edge
  loop a one-face edge is recorded `SourceBoundary` and `continue`s **before** any value is published
  (`:2008-2013`); a two-face edge without a cross-field transition fails `MissingAdjacency` (`:2016-2018`);
  wrong face ownership fails `NonReciprocalAdjacency` (`:2020-2027`); and `transitionValues.push_back` runs at
  **`:2039-2042`**, which is **before** the `HardFeature` (`:2043-2047`) and region/component
  `NonTraversable` (`:2048-2054`) categorizations. **A barrier classification never withholds a transition
  value.**
- **RA-51.3 — Review B: `missing-or-nonreciprocal-terminal-A3` (`:19099-19105`) is UNREACHABLE.** Six links:
  **H1** build-time pin (`FieldTransportAtlas.cpp:1909-1910`, `:1926`); **H2** consume-time pin
  (`SurfaceCellTracing.cpp:18756-18764`, `:18771-18774`; a null atlas rejects earlier and differently at
  `:19079`); **H3** the edge table is a function of `F` — RA-48.3 **landed** at commit `785dd7398` and
  `TriMesh::set_mesh` (`include/directional/core/TriMesh.h:331-351`) now derives **unconditionally** and then
  requires any supplied `_EV`/`_FE`/`_EF` to be **bit-identical** or throws; **H4** every two-face edge has a
  value unconditionally (RA-51.2), and the consumer has already skipped boundary and hard-feature spokes, so
  `!forward`/`!reverse` cannot fire; **H5** `reverse = forward.inverse()` is **computed** at `:2033-2034` and
  `directed_transition_value` (`:910-922`) serves both directions from that one immutable record, so the third
  disjunct compares `value.reverse` against `value.forward.inverse()` — **unrepresentable**, not merely
  unobserved; **H6** `make` is the sole producer, with no public constructor and no mutator
  (`include/directional/authority/FieldTransportAtlas.h:837-900`). **RETIRED coupled to H1–H6**; weakening any
  of them **revives** the obligation. The guard stays fail-closed as the only backstop for an atlas obtained
  other than through `make`.
- **RA-51.4 — Review C: `overlapping-terminal-sectors` is ALSO UNREACHABLE, by an unrelated argument.**
  **K1** the paired front edges are in different A2b regions (`:18892` dominates the certificate call);
  **K2** a front edge's trace faces lie in its own region — all three constructors take the enclosing traced
  region (`:12946`, `:14686`, `:17257`) and the per-region tracers reject foreign rows (`:12380`, `:14920`,
  `:17538-17539`); K1∧K2 ⟹ `firstAttachment != secondAttachment`. **K3** every face has degree ≤ 2 in
  `localStar` — `> 2` incidence rejects at `:19091` and boundary spokes `continue`, and each face carries
  exactly two spokes at the vertex, so **the star graph is a disjoint union of paths and cycles**. **K4** a
  cycle component yields `ambiguous-terminal-A3-path`, not overlap, because `path_to` requires `count == 1`
  (`:19137`). **K5** both orientations are tried (`:19143`). **Proof:** on a path component ordered
  `F1 … F2`, the un-reversed orientation's intervals `[p..F1]` and `[q..F2]` intersect iff `p` is at or after
  `q`; the reversed orientation's `[p..F2]` and `[q..F1]` intersect iff `p` is at or before `q`; both overlap
  **iff `p == q`**, excluded by K1∧K2. Distinct components give `missing-terminal-A3-path`. **RETIRED coupled
  to K1–K5**; weakening K1 or K3 **revives** it. Guard kept fail-closed.
- **RA-51.5 — RA-46.5 is amended only here, and only by removal.** The two retired negatives are struck from
  its required list. Every other RA-46.5 negative stands unamended, including `ambiguous-terminal-contact`
  (RA-49.1, **reachable**, still owed) and `no-exact-terminal-corner`. No new obligation is created.
- **RA-51.6 — RA-48.1's overfull obligation does NOT revive; it is held more tightly.** RA-48.3's landed form
  makes `compute_edge_quantities` run on **every** `set_mesh` call rather than only when no edge table is
  supplied, so guard **G1 is now unconditional** and the DCEL throw (`TriMesh.h:160-163`) is intact.
  R4-OVF-01 is **closed**. This is a strengthening, not the weakening RA-48.1's revival clause contemplated.
- **RA-51.7 — `R4-TA3-02 / DEAD_DISJUNCT` (architectural, no runtime credit).** Two reciprocity tests are
  dead by construction: `reverse->transport != forward->transport.inverse()`
  (`SurfaceCellTracing.cpp:19103-19104`, dead by H5) and `compose(forward, reverse) != QuarterTurn{}`
  (`FieldTransportAtlas.cpp:2035-2038`, dead for any correct `QuarterTurn::inverse`). Both are harmless
  fail-closed guards and **stay**. **Forward constraint on RA-46.6: a typed sub-code may not be minted for a
  disjunct that cannot fire.** Splitting `missing-or-nonreciprocal-terminal-A3` into "missing" and
  "nonreciprocal" sub-codes would manufacture a fresh unsatisfiable fixture obligation of exactly the kind
  retired twice here. Sub-codes separate **reachable** predicates only.
- **RA-51.8 — one hypothesis checked, no defect reported.** The consumer's `localStar` (`:19081-19110`)
  excludes only `hardFeatureEdges` and therefore **admits** steps across region/component seams the atlas
  classified `NonTraversable`. Had the factory used a different rule, a consumer-accepted certificate would be
  factory-rejected — a producer/validator disagreement. It does not:
  `unique_terminal_star_path` (`:8395-8430`) applies the identical rule. **Consumer and factory agree — the
  terminal star is cut by rails only.** Recorded as deliberate design so it is not re-raised as a defect.
- **RA-51.9 — the request's one framing error.** Its step 4 groups RA-48.3 with RA-49.7's unadjudicated list.
  RA-49.7 left two **feasibility** questions open; RA-48.3 was an **implementation** obligation and had
  already landed at the request's own snapshot (`785dd7398` is an ancestor of `0240d0f00`). Its landing is not
  a parallel open item — it **is** link H3, closing the forged-edge-table route. An implementation obligation
  discharges by code; a feasibility question discharges only by review. Its frozen-definition line citation
  (`:157-163`) also predates RA-50's prepend: **cite frozen clauses by RA number, never by line.**
- **RA-51.10 — no credit.** Retiring two unrealizable obligations is a definition correction, not a runtime
  regression. Ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, unchanged. Selector 497
  untouched; CP2 491/491 accepted; R3 403/497 rejected with 94 RED and 88 accepted CP2 losses. RA-41's
  junction/sector clauses remain frozen **UNEXERCISED**; the multi-carrier STOP stands undischarged.
  **RA-49.7 is now fully discharged: no RA-46.5 negative remains unadjudicated.**

---

## RA-50 — RA-43.2 is DISCHARGED; the oriented-side producer receipt is REFUSED **FROZEN at M6-CP3-CB1-ENTRY-R4** (2026-10-13)

Adjudicates `Architecture_M6_CP3_R4_RA432_Oriented_Germ_Producer_Boundary_Review_Request_20261013.md`. Basis:
`Architecture_M6_CP3_R4_Oriented_Terminal_Side_Authority_Review_Decision.md`. **The REVIEW_BLOCKER is
DISSOLVED.** No runtime credit. RA-49, RA-48, RA-47 (implemented, see RA-50.7), RA-46, RA-45, RA-44 (less .2),
RA-43 (less .5 and less the superseded `sourceEdges` row of §4), RA-42 as corrected, RA-41 frozen scoped,
RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates stand.

- **RA-50.0 — the request read RA-43.2 past its own scope limit.** RA-43.2 ends with the words "for contact
  purposes"; the *contact* is the typed terminal **vertex pair**. An *oriented source-face germ pair* and a
  *front-filled-side owner* appear in no clause of RA-43, RA-44, RA-45, RA-46, RA-47, RA-48 or RA-49. RA-45.7
  states the residue exactly — "the endpoint-certificate **consumption** (RA-43.2) … remain[s] open" — a
  consumption, not a new publisher. Scope inflation of a frozen clause, followed by an unsatisfiability
  finding against the inflated version, is **not** an architectural blocker. This is the inverse failure of
  RA-49.0: there, a guard was cited at the wrong **stage**; here, a clause is cited at the wrong **extent**.
- **RA-50.1 — RA-43.2 is DISCHARGED by bytes.** `src/geometry/SurfaceCellTracing.cpp:19013-19014` finds the
  contact by `*first.railId`; `:19064-19069` selects the terminal vertex from `contact->second.endpoints`;
  `from.face`/`to.face` reach no contact decision. Fail-closed on absence at `:19038-19043`
  (`missing-terminal-or-closed-rail-provenance`, typed closed chain the only contact-free route) and on
  ambiguity at `:19068`. The factory re-validates the same contact at `:8308-8325` (component against
  `SourceTopologyRegions`) and `:8474-8497` (endpoints against the carrier's first/last vertex). RA-43.1 and
  RA-43.4 remain separately open; **RA-43.2 does not.**
- **RA-50.2 — the requested receipt is REFUSED as a fifth-namespace category error.** `filledCell` is an
  `authority::CellId` and `filledSide` a side index in `[0,4)` of an **A4 quad cell**
  (`include/directional/geometry/SurfaceCellTracing.h:1555-1557`). Quad cells are minted by A4's own tracing
  and do not exist in the source domain, so a source-authored receipt binding a filled-side owner must
  **invent** the right-hand side of its own binding. No "minimal new producer output" may be specified, and
  none is owed: the deficiency is not missing upstream data, it is a downstream entity named upstream. Add to
  RA-43.3's four namespaces as the fifth; add to the publish/don't-invent family as its **ninth** instance and
  its second structural variant — *do not demand an attestation of something that does not yet exist.*
- **RA-50.3 — the oriented-side authority already exists and is independent.** The request's decisive claim
  cites `:8450-8467` and concludes from the absence of what follows it. `make` continues at `:8588-8637`
  under the comment "A2b uniqueness is checked from source topology, not asserted by the paths in the
  certificate being validated": `unique_terminal_star_path` required **Unique** for both
  attachment→carrier-side walks (`:8596-8608`, typed `MissingTerminalA3Path`/`AmbiguousTerminalA3Path`); every
  `contactPaths[side]` step re-validated against `hardFeatureEdges`, terminal-vertex incidence, chaining,
  face incidence, `matchesA3` and no repeated face (`:8613-8626`); each walk required to terminate exactly at
  `carrier.firstFace`/`carrier.secondFace` (`:8628-8632`); the two sectors required **disjoint**
  (`:8632-8637`). Upstream, `:19137-19173` tries **both** carrier orientations and keeps the one the sectors
  support, rejecting `ambiguous-carrier-orientation` (`:19166`) when both do. **The orientation is selected by
  source topology and A3, never copied from the trace.**
- **RA-50.4 — the front-filled-side ownership is closed at A5, where the filled side exists.**
  `src/pipeline/RemeshPipeline.cpp:5003-5004` requires `from->placement.selectedFace == firstAttachment` and
  `to->placement.selectedFace == secondAttachment`; `:5008-5012` requires
  `QuarterTurn::from_integer(toLattice.branchRotation - fromLattice.branchRotation) ==
  compose(*rigidRotation, published.attachmentTransport())`, with `attachmentTransport()` =
  `phi[1]^-1 ∘ carrier ∘ phi[0]` over the authenticated star walks
  (`include/directional/geometry/SurfaceCellTracing.h:1501-1509`). The chain is complete: producer owns the
  terminal vertex, source topology + A3 own the orientation, the trace owns the attachment identity, A5 owns
  the filled side, and all four must agree. **There is no seam.**
- **RA-50.5 — `R4-SID-01 / SIDE_AUTHORITY_LOCUS` (architectural, no runtime credit).** The certificate
  **alone** is side-symmetric: swapping `firstAttachment`/`secondAttachment` with the carrier reversed is
  internally consistent, because the orientation loop accepts whichever orientation the sectors support. The
  symmetry is broken only externally — `make :8458-8466` against the front-edge pairing fixed at `:8438-8447`,
  and A5 `:5003-5004` against occurrence placement. `attachmentTransport()` **inverts** under that swap, so
  A5's transport check at `:5008-5012` separates it **only when the composed τ is not self-inverse**; for
  τ ∈ {0, 2} the inverse equals itself and `:5003-5004` is the **sole** discriminator. That check is
  load-bearing: it may not be weakened, reordered, or described as redundant with `:5008-5012`.
  **Consequence (LESSONS 171 class):** any regression asserting that the certificate by itself determines the
  filled side is **vacuous** and may not be written or counted. A side negative must tamper at one of the two
  external pins and name which one rejected.
- **RA-50.6 — the request's three correct points are ACCEPTED.** (a) The **RA-46.5 double-counting warning
  stands**: `tests/SurfaceCellTransitionQuotientTests.cpp:9052-9071` is a genuine non-vacuous **factory**
  negative (a real produced non-hard spoke from `contactPaths[side]` inserted into the source barriers,
  asserting typed `MissingTerminalA3Path`) and is **not** the A4 **consumer** first-rejection predicate
  `missing-terminal-A3-path` at `:19175`; the two stages are distinct and the factory test may not be counted
  toward consumer coverage. (b) `append_edge_interval`'s first-in-range `edge.incidentFaces` row
  (`src/pipeline/RemeshPipeline.cpp:9289-9295`) is correctly observed and **architecturally inert**: it feeds
  only `make_surface_cell_rail_sample` geometry under the corner-membership guard at `:9301-9307`, and is
  never read as a side credential. No repair is owed. (c) RA-49.5 / `R4-CTC-01` is correctly preserved as a
  deferred Definition issue; both duplicate checks stay.
- **RA-50.7 — RA-47 is IMPLEMENTED and verified here.** `SurfaceCellRail::sourceEdges` is
  `std::vector<authority::SourceEdgeTopologyKey>` (`include/directional/geometry/SurfaceCellTracing.h:113`);
  the producer publishes typed keys at `RemeshPipeline.cpp:9365` and `:9512`; both provenance digests hash
  the typed key (`:2043-2047`, `:10013-10017`); and the component remap was **deleted and replaced**, not
  converted — `:18094-18108` rebuilds keys from the already-remapped `sourceVertices` chain and fails closed
  with `InvalidTypedRailSourceEdgeRemap`. RA-47.1–.10 are discharged. **RA-47.11 is NOT**: `source_edge_index`
  survives with six uses in `tests/FieldAlignedCurveNetworkTests.cpp`; its remaining uses must be reported as
  legitimate (an EV row genuinely wanted) or migrated. RA-47.12 liveness remains an open **report**.
- **RA-50.8 — citation drift, recorded once.** The RA-43.4 named-mode and network-override patches shifted
  `SurfaceCellTracing.cpp` by ≈ +16 lines. RA-49's `:18999`, `:19052`, `:19055`, `:19167`, `:19170`, `:19446`
  now read `:19015`, `:19068`, `:19071`, `:19183`, `:19186`, `:19462`. **RA-49.0's ordering is unchanged** —
  consumer at `:19183`/`:19186`, factory route at `:19462` — and no RA-49 conclusion moves. Re-anchor future
  citations by symbol, not by remembered line.
- **RA-50.9 — the general rule, third form.** An unsatisfiability finding must be derived from the **whole**
  predicate set on the path. RA-49.0 required establishing **execution order**; RA-50 requires establishing
  **extent of inspection**. Citing one of two contiguous blocks of a factory check and concluding from the
  absence of the other is the same defect wearing a different face.
- **RA-50.10 — no credit.** Discharging a frozen clause and refusing an inflated one are definition
  corrections, not runtime regressions. Ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**,
  unchanged. Selector 497 untouched; CP2 491/491 accepted; R3 403/497 rejected with 94 RED and 88 accepted
  CP2 losses. RA-41's junction/sector clauses remain frozen **UNEXERCISED**; the multi-carrier STOP stands
  undischarged. `overlapping-terminal-sectors` and `missing-or-nonreciprocal-terminal-A3` remain
  **unadjudicated** per RA-49.7.

---

## RA-49 — `ambiguous-terminal-contact` is REACHABLE; the retirement request is REJECTED **FROZEN at M6-CP3-CB1-ENTRY-R4** (2026-10-12)

Adjudicates `Architecture_M6_CP3_R4_RA465_Ambiguous_Terminal_Contact_Review_Stop_20261012.md`. Basis:
`Architecture_M6_CP3_R4_Ambiguous_Terminal_Contact_Feasibility_Review_Decision.md`. **RA-46.5 is NOT amended.**
No runtime credit. RA-48, RA-47, RA-46, RA-45, RA-44 (less .2), RA-43 (less .5 and less the superseded
`sourceEdges` row of §4), RA-42 as corrected, RA-41 frozen scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3
stop gates stand.

- **RA-49.0 — the request's conditional claim is true; its premise fails on the live path.** The deduction
  held only "for a valid **factory-admissible** producer receipt," and the sentence carrying it asserted that
  "a malicious duplicate terminal pair is rejected **earlier** by the checked factory." **The factory runs
  later.** `endpoint_certificate` is defined at `src/geometry/SurfaceCellTracing.cpp:18999` and **invoked** at
  `:19167`/`:19170`; the contact is read **unvalidated** at `:18997`; and `publish_phase_front_result` — the
  only route to `SurfacePhaseFrontProduct::make` and its distinctness check at `:8295-8299` — is called at
  **`:19446`**, after that loop closes, with the same options object. Ordering is **consumer first, factory
  second**, so `:19052` is the **first** rejecting predicate for a duplicated endpoint pair. This is a
  **stage-locus error**, the class corrected in RA-43.2.
- **RA-49.1 — the obligation STANDS.** The retirement request is **REJECTED**; RA-46.5's requirement for a
  negative at `ambiguous-terminal-contact` is unamended.
- **RA-49.2 — the impossibility the request found is real, sharper, and about something else.** Qualification
  at `:19049-19051` is a **conjunction**, and `exact_corner(fromPoint, ·)` (`:19034-19046`) settles it alone:
  `corner` is assigned only where `faces(point.face, i) == vertex.index()`, and the bit-exact one-hot test then
  forces `i` to the single position `c` with `barycentric[c] == 1.0`, so the only admissible vertex is
  `faces(fromPoint.face, c)` — **exactly one**, independent of `toPoint`, the carrier conjunct,
  `contact.component` and the factory. Two **distinct** vertices therefore cannot both qualify, and that needs
  no guard. The branch has exactly **one** reachable route: the same vertex qualifying **twice**.
- **RA-49.3 — the witness, named exactly.** `endpoints` is `std::array<authority::SourceVertexId, 2>`
  (`include/directional/geometry/SurfaceCellTracing.h:1532`) with no distinctness invariant, so a duplicate is
  representable by type. Supply `hardRailTerminalContacts[railId] = {component, {v, v}}` with `v` an endpoint
  of the carrier `edge` and both `fromPoint` and `toPoint` bit-exact one-hot at a corner holding `v`. Iteration
  1 sets `terminalVertex = v`; iteration 2 passes the identical conjunction and returns at `:19052`. The
  fixture must be verified to reject at `:19052` and **not** at `:19055`, `:8296`, or any earlier predicate.
  Nothing is fabricated or approximated. The request's refutation criterion ("two unequal typed terminal IDs")
  was too narrow — it excluded by assumption the only route the code admits.
- **RA-49.4 — prohibited routes to the witness.** Relaxing the one-hot comparison at `:19043` (RA-46.7's
  prohibition extends here); removing or weakening the factory distinctness check at `:8295-8299`; removing the
  carrier-membership conjunct at `:19049`; constructing the contact outside `build_surface_cell_network`. The
  witness requires none of these. A fixture attempting the two-distinct-vertices route is not a defect in the
  code and will not produce this predicate.
- **RA-49.5 — R4-CTC-01: validate-after-use.** `build_surface_cell_network` **uses** caller-supplied
  `hardRailTerminalContacts` for routing and certificate decisions from `:18997`, and validates them only at
  `:19446`. The duplicate condition is checked twice with different strictness and reporting — string predicate
  upstream (`:19052`), typed `InvalidSourceAuthority` downstream (`:8297`) — and the **upstream, weaker-reporting**
  one is the one that fires. The consumer's guards are therefore **load-bearing, not redundant defence**, and
  retiring this negative would remove coverage from the only check that runs before the data is consumed. The
  request's proposed substitute, "a reachable factory-first duplicate-contact negative," cannot exist on this
  path. Architectural repair — validate contacts against factory admissibility before first use, or route the
  consumer through the factory-validated product — is **not** authorized in Code + Build and is referred to a
  later Definition turn. Until then **both** checks are kept; neither may be removed as redundant.
- **RA-49.6 — what IS unrealizable: `nonmanifold-terminal-star-spoke`, RETIRED.** `:19066-19068` needs
  `sourceEdgeFaceCounts > 2`, i.e. a nonmanifold `faces`; the loop needs a non-null atlas (`:19056-19057`); and
  the network gate at `:18749-18757` requires
  `matches_source_faces(faces, *network.sourceTopologyRegions, vertexCount)`, which ties the atlas's
  `rowTopology_` to those exact face triples (`src/authority/FieldTransportAtlas.cpp:3090-3109`). The atlas must
  therefore have been built on that nonmanifold mesh, which throws by the RA-48.0 chain. Retired on RA-48's
  **already frozen** G1-G4 plus the network gate, with the guard **kept fail-closed**; no fixture, and none
  synthesized by relaxing manifold rules or passing a null atlas (which rejects earlier with
  `missing-source-A3`, a different predicate). Lapses with RA-48.1 if any guard weakens. **Note the inversion:**
  the request sought to retire the reachable predicate while leaving the unreachable one in force.
- **RA-49.7 — status of the remaining four.** `no-exact-terminal-corner` (`:19055`) is **reachable** — any
  contact whose endpoints are off the carrier, or whose trace points are not bit-exact one-hot, falls through
  the loop. `missing-terminal-A3-path` is **reachable** and keeps its obligation by RA-46.4, which retained the
  `pathCount == 0` branch as reachable from a foreign component. `overlapping-terminal-sectors` and
  `missing-or-nonreciprocal-terminal-A3` were **NOT examined** and keep their obligations **unadjudicated**;
  their feasibility may not be asserted in either direction on the strength of this decision.
- **RA-49.8 — the general rule, third application.** An obligation is settled by what the predicate can
  separate **on the path it actually sits on**, not by what a downstream guard would have prevented. RA-46
  asked this of a graph-theoretic condition, RA-48 of a source-construction condition, RA-49 of an **ordering**
  condition — and here the answer **inverted** the request, because the guard invoked to prove unreachability
  executes after the predicate it was said to protect. A feasibility argument must establish **execution
  order**, not merely a stricter check elsewhere.
- **RA-49.9 — no credit.** No binary built, no test executed. R4-CTC-01 is a source-level review finding,
  **not** a counted stable regression. Ledger stays **66 events / 17 categories / 49 recurrences**, debt **1**.
  CP2 **491/491** accepted, R3 **403/497** rejected, 94 RED, 88 accepted CP2 losses. RA-41 junction/sector
  clauses remain frozen **UNEXERCISED**; the seven two-face DCEL repairs remain compiled but **not executed**.
  **RA-47 remains entirely unimplemented.**

---

## RA-48 — overfull-A3 is unrealizable under four guards; the seam beneath it is a defect **FROZEN at M6-CP3-CB1-ENTRY-R4** (2026-10-12)

Adjudicates the carried independent overfull-A3 feasibility gate raised in
`Architecture_M6_CP3_R4_Factory_Incidence_Oracle_Source_Validity_Static_Audit_20261011.md`. Basis:
`Architecture_M6_CP3_R4_Overfull_A3_Feasibility_Review_Decision.md`. No runtime credit. RA-47, RA-46, RA-45,
RA-44 (less .2), RA-43 (less .5 and less the superseded `sourceEdges` row of §4), RA-42 as corrected, RA-41
frozen scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates stand.

- **RA-48.0 — the witness is unconstructible, and this is a theorem, not an unmeasured risk.** The A4 guard
  counts actual incidences from the A2b product (`src/geometry/SurfaceCellTracing.cpp:8177-8198`) and rejects
  `count == 0 || count > 2` (`:8202-8207`); to reach it a fixture must first pass the RA-40 atlas binding at
  `:8072-8079`. Chain: the atlas has exactly one construction seam and it takes a `TriMesh`
  (`include/directional/authority/FieldTransportAtlas.h:837-841`); it reads its edge table from `EV`/`EF`
  (`src/authority/FieldTransportAtlas.cpp:1016-1030`) and `EF` is 2-column by construction
  (`include/directional/core/TriMesh.h:165`), so overfullness has no representation in it; `set_mesh` runs
  `compute_edge_quantities` (`core/TriMesh.h:339-340`), which runs
  `dcel.check_consistency(verbose, true, true, true)` and **throws** on failure (`:160-163`); DCEL check 5
  rejects any repeated **directed** halfedge (`core/DCEL.h:1453-1492`), and three triangles on one undirected
  edge contribute three halfedges into two directions, so two coincide **by pigeonhole**, independent of
  orientation. An atlas built elsewhere cannot be swapped in: `matches_source_faces` ties `rowTopology_` to the
  exact face triples of `sourceFaces` (`FieldTransportAtlas.cpp:3090-3109`).
- **RA-48.1 — obligation RETIRED, coupled to four guards.** No fixture for the `count > 2` branch, and none
  synthesized by relaxing manifold or incidence rules. Retirement lapses automatically if any guard weakens:
  **G1** `set_mesh` runs `compute_edge_quantities` on the 2-argument form (`core/TriMesh.h:339-340`);
  **G2** that call passes `checkHalfedgeRepetition = true` and throws (`:160-163`);
  **G3** DCEL check 5 rejects repeated directed halfedges (`core/DCEL.h:1453-1492`);
  **G4** `FieldTransportAtlas::make` is the only construction seam and takes a `TriMesh`
  (`FieldTransportAtlas.h:837-841`). A dead negative is dead only relative to its guards.
- **RA-48.2 — the guard is KEPT, fail-closed.** `:8202-8207` is not dead code. It is the only check that can
  observe an incidence the atlas's 2-column `EF` cannot represent, and under R4-OVF-01 it is the sole backstop
  for an injected edge table. Removing or demoting it is prohibited. Its **`count == 0` branch keeps its
  obligation in full** — reachable, and a different predicate.
- **RA-48.3 — R4-OVF-01: `set_mesh`'s injection branch is an unvalidated authority seam.**
  `core/TriMesh.h:331-345` skips `compute_edge_quantities` entirely when `_EV.rows() != 0`, assigning
  caller-supplied `EV`/`FE`/`EF` with **no validation that they correspond to `F`**.
  `FieldTransportAtlas::make` then consumes that `TriMesh` as authoritative A1 topology, validating adjacency,
  cycles and singularities against a possibly fabricated edge table, and `matches_source_faces` cannot detect
  it because it compares face rows only. The seam must either validate the supplied tables against `F` or be
  removed; until then the injection form must not be used for any source handed to the atlas. **All 116
  existing `set_mesh` call sites use the 2-argument form** — which is why this was never noticed, and why
  RA-48.0's proof rests on a guard one argument away from being disabled. RP-01 at the bottom of the stack.
- **RA-48.4 — the atlas's own invariant comment is inaccurate and must be corrected.**
  `FieldTransportAtlas.h:830-834` asserts "Construction is the only validation seam." That holds only for a
  `TriMesh` whose edge table the atlas also derived. A doc comment asserting an invariant the code does not
  enforce is itself a defect, because later review relies on it.
- **RA-48.5 — R4-OVF-02: the oracle cannot separate the predicate.** Four distinct predicates in `make`
  return the identical bare `InvalidSourceAuthority`: the atlas gate (`:8077`), the malformed-edge-key branch
  (`:8190`), the incidence guard with **both** `count == 0` and `count > 2` collapsed into one site (`:8204`),
  and the terminal-contact presence check (`:8210`). Even had the witness been constructible, the obligation
  could not have been discharged non-vacuously. LESSONS-160, "passed versus did not run."
- **RA-48.6 — the collapse is now a PATTERN, and RA-46.6 becomes a PREREQUISITE.** Third site after
  R4-A3U-01's two (`unique_terminal_star_path`'s bare `bool` at `:8352`, collapsed at `:8527-8528`); the
  consumer side already shows the correct shape with three separated diagnostics at `:19071-19074`. A typed
  factory sub-code is required to distinguish atlas-gate, bad-key, zero-incidence, overfull-incidence and
  missing-contact rejections **before** any of them may be claimed as exercised. The `:8204` and `:8210` sites
  are added to RA-46.6's scope.
- **RA-48.7 — scope limits on what may be claimed.** Permitted: the overfull condition is unrealizable at the
  A4 factory under G1-G4, and the guard is retained as a fail-closed backstop. Prohibited: claiming the guard
  was exercised, that nonmanifold source handling was verified, or that A2b rejects malformed source first —
  A2b was not examined by this review and remains unestablished. The producer-side
  `overfull-nonmanifold-spoke` (`:19232`) and `overfull-hard-feature-edge` (`:18768`) paths are **separate**
  and are not adjudicated here; they keep their existing obligations.
- **RA-48.8 — beacon versus durable authority.** `STATUS` read `BLOCKED / Successor: UNKNOWN`, set by
  `6692ce457` ("record R4 transport blocker and preserved WIP"), which changed `STATUS` **only** — one line,
  recording no blocker, preserving no WIP, citing no finding, with no accompanying document. The four commits
  after the RA-47 freeze (`74170c022`, `4b5dc2c74`, `06a36e7e6`, `6692ce457`) contain **no source change and
  no decision record**. The claimed transport blocker is contradicted by its own receipt:
  `.workflow-mailbox/repo-source-snapshot/latest.json` records run `38249080586` `"result": "success"` at
  `2026-10-12T12:27:47Z`, before the beacon was set. **A beacon that contradicts durable authority without a
  recorded basis is not authority.** RA-47 implementation resumes unblocked. A future `BLOCKED` beacon
  requires a committed record naming the finding, or it may be overridden by Review on this precedent.
- **RA-48.9 — no credit.** No binary built, no test executed. R4-OVF-01 and R4-OVF-02 are source-level review
  findings, **not** counted stable regressions. Ledger stays **66 events / 17 categories / 49 recurrences**,
  debt **1**. CP2 **491/491** accepted, R3 **403/497** rejected, 94 RED, 88 accepted CP2 losses. RA-41
  junction/sector clauses remain frozen **UNEXERCISED**; the seven two-face DCEL repairs remain compiled but
  **not executed**.

---

## RA-47 — the raw-int source-edge namespace is abolished, not re-frozen **FROZEN at M6-CP3-CB1-ENTRY-R4** (2026-10-12)

Adjudicates `Architecture_M6_CP3_R4_Edge_Index_Namespace_Conflict_Review_Stop_20261012.md`. Basis:
`Architecture_M6_CP3_R4_Edge_Index_Namespace_Review_Decision.md`. Finding **R4-IDX-01 CONFIRMED**; both
proposed repairs **REJECTED**. No runtime credit. RA-46, RA-45, RA-44 (less .2), RA-43 (less .5 and less the
`sourceEdges` row of §4, superseded here), RA-42 as corrected, RA-41 frozen scoped, RA-40, RA-39, RA-38,
RA-37a and the RA-34.3 stop gates stand.

- **RA-47.0 — the conflation is real.** The producer indexes `featureMap.edges[entry.edgeIndex]` and stores
  **that same integer** in `rail.sourceEdges` (`src/pipeline/RemeshPipeline.cpp:9349-9359`; standalone path
  `:9502-9503`), so no reinterpretation is available. `featureMap.edges` is emitted by iterating a
  `std::map` keyed on the canonical vertex pair — lexical order (`include/directional/geometry/AdaptiveFeatureMap.h:181-207`).
  `TriMesh::EV` rows follow DCEL first encounter and are oriented, not canonical
  (`include/directional/core/TriMesh.h:160-172`). The consumer bounds-checks against `EV.rows()` and
  dereferences `EV` (`src/geometry/SurfaceCellTracing.cpp:4233-4245`). One face `(0,1,2)` separates the
  orders: `featureMap.edges` = `(0,1),(0,2),(1,2)`, `EV` = `(0,1),(1,2),(2,0)`; a rail on `(0,2)` is published
  as `1` and read back as `(1,2)`.
- **RA-47.1 — the field is retyped.** `SurfaceCellRail::sourceEdges`
  (`include/directional/geometry/SurfaceCellTracing.h:113`) becomes
  `std::vector<authority::SourceEdgeTopologyKey>`. RA-43 §4's row for this field is **SUPERSEDED** — it
  accurately recorded an observed defect, not a contract worth preserving. The other three rows of that
  inventory stand unchanged, `SurfaceCellRailSample::sourceEdge` included.
- **RA-47.2 — produced from the chain already validated.** Entries are built from `entry.startVertex`/
  `entry.endVertex` (`:9356-9360`) and `edge.vertices.first`/`.second` (`:9502-9503`) through the existing
  `surface_cell_source_edge_key` (`:3064`). No feature-map lookup, no `EV` scan, no new table. The
  `sourceVertices` continuity check at `:9346` remains the sole authority for chain validity.
- **RA-47.3 — diagnostic indices stay separate and explicit.** `failedEdgeIndex` and `coveredEdges` remain
  `featureMap.edges` positions sourced directly from `entry.edgeIndex`. `:9365`'s
  `fail_edge(rail.sourceEdges.back())` must carry the last feature index explicitly and must **not** be
  reconstructed from a typed key. Merging a diagnostic index space into a topological one is prohibited.
- **RA-47.4 — the component remap is DELETED, not converted.** `src/pipeline/RemeshPipeline.cpp:18106-18114`
  is removed; `:18093-18104` already remaps `rail.sourceVertices` through `component.originalVertices`, and
  the typed keys are rebuilt from the remapped chain immediately after. Rails' dependence on
  `globalEdgeByLocal` ends with it. This is what closes R4-IDX-02.
- **RA-47.5 — the consumer collapses to a typed equality.** `:4233-4245` compares the stored key against the
  key derived at `:4223-4225`; the `EV.rows()` bound and the `EV` dereference are removed.
  `InvalidRailGeometry` is retained and must not be weakened — it now fires on a genuine topological
  disagreement rather than on a namespace artefact.
- **RA-47.6 — the digest changes, and that is permitted.** `:2043` and `:10005` hash `first().index()` then
  `second().index()` per key, matching the barriers pattern at `:9576-9580`. No test pins a literal digest and
  `:9907`/`:10005` compare in-run products against each other, so no frozen identity depends on the old bits.
  A future comparison against a stored baseline must be re-derived, never back-fitted.
- **RA-47.7 — R4-IDX-02: the field carried THREE namespaces.** `:17471-17476` maps a typed key to a **global**
  `EV` row; `:17579-17593` indexes `globalEdgeByLocal` by **component-local** `EV` row; `:18106-18114` rewrites
  the field through it. The producer's value was a featureMap position. The digest at `:2043` hashed whichever
  was present, so the rail provenance digest was **path-dependent on component decomposition**. This is why
  freezing a single contract was rejected: it repairs the instance and preserves the class.
- **RA-47.8 — R4-IDX-03: the existing structural checks are vacuous.** `:4209-4212` and `:5937-5938` constrain
  only `sourceEdges.size()` against `sourceVertices.size()`. The RA-47.0 counterexample satisfies both, as
  does any foreign index vector of the right length. LESSONS-171. They may not be cited as a defence, and they
  survive the retype unchanged because they are size relations.
- **RA-47.9 — why no index contract was frozen.** Census of every consumer of the field shows **no genuine
  index consumer**: one value consumer that re-derives the typed key it already holds (`:4223-4245`), two
  cardinality checks, two hash terms, one self-equality (`:9907`), two feature-namespace diagnostics, one
  namespace translation. Every hand-authored fixture *derives* the field from the typed key by scanning `EV`
  (`source_edge_index` in `tests/GlobalConformityBaselineTests.cpp`, `tests/GlobalConformityPlanTests.cpp`,
  `tests/FieldAlignedCurveNetworkTests.cpp:492-494`), and `hard_feature_edge_keys_from_rails` (`:9588-9599`)
  already feeds A4 typed keys built from `sourceVertices` while ignoring `sourceEdges` entirely. The field is a
  round trip typed -> raw -> typed that adds one failure mode and zero information.
- **RA-47.10 — required non-vacuous coverage.** A positive fixture on a mesh where lexical feature order and
  DCEL `EV` order **differ**, carrying a rail on an edge whose two indices are unequal; the single face
  `(0,1,2)` with a rail on `(0,2)` is named as the minimum. A fixture confined to `(0,1)` is explicitly
  disallowed as evidence. Negatives, each verified at its **first rejecting predicate**: a foreign typed key
  with correct cardinality (which R4-IDX-03 proves the current code cannot reject); a key whose endpoints are
  not an edge of the source mesh; a closed rail whose final key does not close the chain; and a
  component-decomposed run whose remapped keys must equal the single-component run's keys for identical
  geometry — the direct R4-IDX-02 falsifier.
- **RA-47.11 — test migration.** `tests/SurfaceCellREPackageTests.cpp:292-298` becomes a typed equality and
  thereby non-vacuous for the first time. `tests/MilestoneBClosureTests.cpp:142`'s literal `{0, 1, 2, 3}` is
  re-derived from the fixture mesh's own vertex pairs; the test **identity** is preserved, the literal is not
  evidence. `source_edge_index` is deleted as an orphan of this change — the fixtures already hold
  `barrier.sourceEdge` and pass it directly. Frozen 497 identities are otherwise untouched.
- **RA-47.12 — liveness is OPEN and must be reported.** Whether `:4233-4245` currently rejects producer-built
  rails on the default path is **not established**. Two readings remain: the consumer is never reached with
  producer-built rails, or it is reached and rejects. RA-47 is correct either way, so the adjudication does not
  wait on it — but the implementing turn must report **which**, because a consumer that has never seen a
  producer-built rail is an RP-02 `TEST_AUTHORITY_COVERAGE_GAP` and a separate finding.
- **RA-47.13 — the eighth instance, and the dual.** The publish-don't-invent family (RA-34.3, RA-35, RA-38,
  RA-40, RA-42, RA-43 as relocated, RA-44.1) says *reach or publish what the producer already holds*. RA-47
  states its dual: *do not carry a second encoding of what you already publish.* Both reduce to one test — can
  the added datum separate anything the authoritative datum cannot? Here, demonstrably not.
- **RA-47.14 — no credit.** Nothing here is a runtime claim; no binary was built and no test executed.
  R4-IDX-01/02/03 are source-level review candidates, **not** counted stable regressions. Ledger stays
  **66 events / 17 categories / 49 recurrences**, debt **1**. CP2 **491/491** accepted, R3 **403/497**
  rejected, 94 RED, 88 accepted CP2 losses carried. RA-41's junction/sector clauses remain frozen
  **UNEXERCISED**; the seven two-face DCEL repairs remain compiled but **not executed**.

---

## RA-46 — terminal A3 path uniqueness is a theorem; the dual-path obligation is retired **FROZEN at M6-CP3-CB1-ENTRY-R4** (2026-10-11)

Adjudicates `Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Design_Review_Request_20261011.md`. Basis:
`Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Review_Decision.md`. No runtime credit. RA-45, RA-44 (less
.2), RA-43 (less .5), RA-42 as corrected, RA-41 frozen scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3
stop gates stand.

- **RA-46.1 — the lemma is CONFIRMED and holds WITHOUT the manifold premise.** Both counters build the same
  object: `localStar` (`src/geometry/SurfaceCellTracing.cpp:18979-19031`) and `adjacency`
  (`:8318-8352`), each from spokes at the terminal vertex only, rejecting incidence `> 2`, skipping
  hard-feature spokes and non-two-incident spokes, requiring reciprocal A3. **(a)** Adjacency exists only via
  spokes at `v`, every face in the graph has `v` as a corner, and a triangle has exactly two edges at a
  corner, so **maximum degree is 2** and every component is a simple path or cycle. **(b)** The carrier is a
  hard-feature edge containing `v` and hard spokes are excluded (`:8326`, `:18984`), so the component holding
  the carrier's incident faces lost an edge and is **acyclic**. **(c)** Every call site targets a
  carrier-incident face (`:8523-8526`, `:19044-19047`). **(d)** An acyclic component admits at most one simple
  path between an ordered pair, and a foreign component admits zero. Therefore **`pathCount >= 2` is
  unreachable for every input the preceding guards admit.**
- **RA-46.2 — the two gaps the manifold premise was covering are closed.** A **pinch/bowtie** vertex has all
  edge incidences equal to 2, so the `> 2` guard does not catch it and an untouched cycle survives; it still
  cannot yield two paths, because that cycle holds no carrier-incident face. A **doubled triangle** is the only
  structure that could give the consumer-side multigraph a 2-cycle; its two faces span the same vertex set, so
  its only two spokes at `v` are the parallel pair and the carrier is necessarily one of them. A counterexample
  therefore **does not exist**, rather than merely being absent from the fixtures.
- **RA-46.3 — the retirement is COUPLED to four conditions.** Unreachability is a theorem relative to its
  guards, so the retirement is valid only while all four hold, and weakening any one **revives** the
  obligation: (1) source faces are triangles, giving exactly two edges at a corner; (2) hard-feature spokes are
  excluded from the star graph; (3) the terminal carrier is a hard-feature edge containing the terminal vertex;
  (4) the DFS target is a carrier-incident face.
- **RA-46.4 — the literal two-admissible-path fixture obligation is RETIRED.** The `pathCount != 1` guard is
  **retained** as a fail-closed defence against malformed input, with **no fixture obligation** on its `>= 2`
  branch. The guard is **not** dead overall: its `== 0` branch is reachable and keeps its obligation.
- **RA-46.5 — replacement negatives, each at its actual first rejecting predicate.**
  `missing-terminal-A3-path`, `overlapping-terminal-sectors`, `no-exact-terminal-corner`,
  `ambiguous-terminal-contact`, `missing-or-nonreciprocal-terminal-A3`, `nonmanifold-terminal-star-spoke`, plus
  the typed factory sub-code required by RA-46.6. No frozen test identity changes; no runtime assertion in a
  Code + Build turn.
- **RA-46.6 — R4-A3U-01: the checked factory conflates zero with ambiguous.** `unique_terminal_star_path`
  returns `bool` (`:8352`) and both call sites collapse into a bare `InvalidSourceAuthority` (`:8527-8528`).
  The factory is the authoritative check, so under RA-42.3 it most needs the distinction: a genuine no-path
  rejection is today indistinguishable from the unreachable ambiguity branch. A typed sub-code is required.
  The consumer side is already correct — `:19048-19053` sets the ambiguity flag only on `> 1`, and
  `:19071-19074` selects among three distinct messages.
- **RA-46.7 — `exact_corner` is a CONFIRMING predicate and does not violate RA-42.2.** `:18957-18963`
  compares barycentric components bit-exactly with **no tolerance**; the vertex identity comes from the typed
  published contact (`:18966`, RA-44.1) and the geometry only confirms it. RA-42.2 forbids **deriving**
  incidence from geometry, not confirming it, and this predicate can only false-reject. **Introducing a
  tolerance here would be the violation** and is prohibited.
- **RA-46.8 — accepted: sector disjointness is enforced where it counts.** `:8552-8556` requires the two
  sides' used-face sets to be disjoint, and `:19055-19064` enforces the same consumer-side. This is RA-38's
  boundary-germ separation at A4 and is why the two contact walks cannot collude.
- **RA-46.9 — hardening, not a block.** `sourceEdgeFaceCounts.at(spoke)` (`:18983`) throws if the two maps are
  ever built from different sources; prefer a bounds-safe lookup that fails closed.
- **RA-46.10 — no credit.** Retiring an unrealizable obligation is a definition correction, not a runtime
  regression. Ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, unchanged. Selector 497
  untouched; CP2 491/491 accepted; R3 403/497 rejected. RA-41's junction/sector clauses remain frozen
  **UNEXERCISED**; the multi-carrier STOP stands undischarged.

---

## RA-45 — the +U gauge has no absolute consumer **FROZEN at M6-CP3-CB1-ENTRY-R4** (2026-10-10)

Resolves the RA-44.2 producer-compatibility STOP by **withdrawing the requirement**, not by constructing a
pin. Basis: `Architecture_M6_CP3_R4_Gauge_Consumption_Review_Decision.md`. No runtime credit.
**RA-44.2's absolute geometric pin is WITHDRAWN.** RA-44.1/.3/.4/.6/.7, RA-43 (less .5), RA-42 as corrected,
RA-41 frozen scoped, RA-40, RA-39, RA-38 and the RA-34.3 stop gates stand.

- **RA-45.1 — the gauge is consumed only relationally.** `RemeshPipeline.cpp:4605-4622` reads the gauge at an
  occurrence's `placement.selectedFace` and wraps it as `SurfaceOccurrenceEndpointFaceGaugeAuthority`; it is
  stored only as a **pair** on `SurfaceOccurrenceRelationEvidence`
  (`include/directional/pipeline/RemeshPipeline.h:865-869`, assigned `RemeshPipeline.cpp:5172-5173`);
  `:7300-7301` reads **presence only**; `:5613-5630` reads presence and the **face identity**; the single use
  of the value is the difference `compose(second, first.inverse())`
  (`tests/SurfaceCellTransitionQuotientTests.cpp:3152-3153`). `QuarterTurn` is Z4 and Z4 is abelian, so a
  uniform `+1 mod 4` cancels: `(g+1) o (g'+1)^-1 = g o g'^-1`. **No consumer's decision changes.**
- **RA-45.2 — RA-44.2's absolute pin is WITHDRAWN as a category error.** It demanded absolute authentication
  of a relationally-consumed quantity, which is why no construction exists for the annular producer
  (`score_ring_candidate`, `src/geometry/SurfaceCellTracing.cpp:13510-13704`, a best-fit minimisation) or the
  curved bounded-disk producer (`:15488-15556`, root value **0** by convention then transport BFS). The planar
  producer's `axisU` gate (`build_planar_phase_frame`, `:11143-11260`) is **that producer's own
  convention-selection rule**, not a property the gauge must have; freezing it as a universal requirement was
  a Review Agent error. All three producers are admissible without producer-specific pins.
- **RA-45.3 — the authentication is the relational A3 pin, already implemented.**
  `src/geometry/SurfaceCellTracing.cpp:8038-8080` builds typed `SourceEdgeTopologyKey` incidence from
  `topology_for_row`, skips single-incidence open boundary, and rejects unless
  `reverse->transport == forward->transport.inverse()` and `compose(forward->transport, first) == second`.
  With mandatory presence (`:8020`) and topology-derived keying this is **non-vacuous**: it rejects a
  one-face change, any subset change, a permuted gauge vector, an A3 mismatch, and an absent gauge while
  consumed.
- **RA-45.4 — balanced uniform tamper is RECLASSIFIED as a gauge transformation.** The earlier pre-committed
  negative "a balanced `+1 mod 4` on every face must be REJECTED" is **WITHDRAWN**: rejecting it would reject
  a legitimate convention and is unimplementable without a pin that does not exist. Its replacement is a
  **positive** obligation — a uniform rotation is **ACCEPTED** and must yield a **bit-identical A6 relation
  outcome**, testing gauge-invariance as a property rather than asserting a value no consumer reads.
- **RA-45.5 — validate, never rewrite.** `RemeshPipeline.cpp:2134-2144` folds the gauge into a provenance
  digest, so a uniform rotation is semantically inert but **not digest-inert**. The factory must not
  canonicalise or normalise the gauge — in particular it may not rotate it so a root face reads 0 — because
  that would change accepted CP2 provenance digests. Accept as produced.
- **RA-45.6 — RA-44.5's residual is dissolved for authentication.** A4's floating-point alignment predicate is
  no longer load-bearing for any check. It remains the planar producer's own selection rule and stays
  **untouched**; RA-44.5's prohibition on altering it continues to apply.
- **RA-45.7 — RA-44.1 accepted in shape.** `SurfaceHardRailTerminalContacts` =
  `std::map<authority::HardRailId, SurfaceHardRailTerminalContact>`
  (`include/directional/geometry/SurfaceCellTracing.h:1512-1517`), threaded into `make` (`:1882`) and readable
  at `:1930-1931`. The germ construction (RA-43.1), the endpoint-certificate consumption (RA-43.2) and the
  `rail_sample_source_vertex` replacement (RA-43.4) remain **open**.
- **RA-45.8 — no credit.** An over-strong requirement frozen in a review document is a review defect, not a
  runtime regression. Ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, unchanged.
  Selector 497 untouched; CP2 491/491 accepted; R3 403/497 rejected. RA-41's junction/sector clauses remain
  frozen **UNEXERCISED**; the multi-carrier STOP stands undischarged.

---

## RA-44 — terminal rail-contact binding and the +U gauge witness **FROZEN at M6-CP3-CB1-ENTRY-R4** (2026-10-10)

Resolves the R4 source-authority binding STOP. Basis:
`Architecture_M6_CP3_R4_Contact_Binding_And_Gauge_Witness_Review_Decision.md`. No runtime credit.
**RA-43.5 is WITHDRAWN by RA-44.2** as vacuous; RA-43.1/.2/.3/.4/.6/.7, RA-42 (as corrected), RA-40, RA-39,
RA-38 and the RA-34.3 stop gates stand.

- **RA-44.1 — the contact binding is a widening, not a new channel (option C).** The rails already reach this
  boundary: `hard_feature_edge_keys_from_rails` (`src/pipeline/RemeshPipeline.cpp:9576-9599`) consumes
  `rail.sourceVertices` and converts consecutive pairs to typed `SourceEdgeTopologyKey` via
  `surface_cell_source_edge_key` (`:3064`); its result becomes A4's `hardFeatureEdges`, and `:12173-12179`
  already stores `productSnapshots.authoritativeRails`. The terminal contact is the datum that reduction
  **discards**: which vertex is terminal, and the `HardRailId -> endpoint vertex` association. Required:
  a sibling reduction `hard_rail_terminal_contacts_from_rails(rails, vertexExtent)` publishing, per
  `HardRailId`, the typed terminal `SourceVertexId` pair from `rail.sourceVertices.front()`/`.back()`,
  skipping `closed` rails, carrying `rail.component`, using the existing typed conversion, threaded to `make`
  at the same three call sites (`:12176`, `:17031`, `:17721`). Keyed by `HardRailId` and component — never by
  raw-int equality and never by geometric closeness. Options (A) "pass the chain" and (B) "author a new A4
  certificate" are **rejected as heavier than the facts require**. Seventh occurrence of publish/reach.
- **RA-44.2 — WITHDRAWN by RA-45.2: the absolute geometric pin is a category error.** The gauge has no
  absolute consumer (RA-45.1), so there is nothing absolute to authenticate; the annular and curved producers
  have no `axisU` gate and need none. The relational A3 pin of RA-45.3 is the whole authentication. Retained
  below for the record only. Original text: _the +U gauge witness has two parts and neither suffices alone._ RA-43.5's oracle is withdrawn:
  `FieldFaceBranchFrame` (`include/directional/authority/FieldTransportAtlas.h:728-734`) publishes **all four**
  branches, so `find_frame(face)` cannot discriminate, and `make` (`SurfaceCellTracing.cpp:7969-7984`) holds
  no vertices or axes with which to re-derive. Required instead: **(a) an absolute geometric pin** — per face,
  the asserted branch's family/sign axis projected to the face normal aligns with the certificate's own
  `axisU` under the **identical** `1.0 - 1e-8` gate A4 uses at `:11034-11043`, with the `axisV` cross-check at
  `:11050-11054`; the frame axes and `faceAxisX`/`faceAxisY` therefore **travel with the gauge**, so the
  certificate carries its own derivation inputs; and **(b) a relational A3 pin** —
  `rotation[to] == rotation[from].rotated(transition_value(edge, from, to)->transport)` across every interior
  edge, reusing the accessor at `:7996-8009`. **Both are mandatory:** (b) alone is gauge-invariant and a
  balanced `+1 mod 4` on every face passes it, while (a) alone ignores the field entirely.
- **RA-44.3 — gauge presence and scope.** Keyed by `SourceFaceTopologyKey`, so row permutations cannot
  launder it. Presence is **mandatory whenever A6 seam logic consumes the gauge**; the only legal absence is
  **total** — no gauge and no consumer. The `!sourceFaceBranchRotations.empty() &&` guard at
  `src/geometry/SurfaceCellTracing.cpp:8015-8020`, which accepts an absent gauge, is closed. This does not
  reopen the RA-40 conditional hole, which concerned the atlas.
- **RA-44.4 — fixtures that assert hard features without a producer fail closed.** Under RA-44.1 a fixture
  supplying hard features through rails gets contacts for free; one hand-authoring `hardFeatureEdges` with no
  rail is asserting hard features with no producer and is **rejected**, on the same ruling RA-40 made for
  tests manufacturing route certificates without a source-bound atlas. The archived
  `Directional_M6_R4_source-owned-rail-WIP.patch` stays **unapplied**; RA-44.1 supersedes it.
- **RA-44.5 — recorded residual, not a block.** A4 selects an exact Z4 gauge with a `double` alignment
  predicate (`:11034-11043`). The factory must use the identical predicate or it would reject what A4
  accepted, so this is **not** tightened inside R4; the hard `>= 1 - 1e-8` gate is fail-closed, which is the
  correct structure. Tracked, not remedied here. Changing A4's selection rule would alter accepted CP2
  behaviour and is out of scope.
- **RA-44.6 — code accepted at this locus.** `publish_phase_front_result`
  (`src/geometry/SurfaceCellTracing.cpp:12240-12250`) now reports `PublishedProductRejected` and carries
  `publishedProductError`, ending the collapse of factory rejections into `InvalidFinalCellState`; this
  discharges RA-42.3 here. The opaque `enum class SurfacePhaseFrontProductErrorCode : int;` (header `:1689`)
  has a fixed underlying type, so it is complete and the `std::optional` member is well-formed; the
  `std::get` at `:12247` cannot throw given two alternatives (`:1846`) and the early return at `:12240`. The
  seven two-face DCEL fixture repairs compiled but **were not executed** — no restoration is claimed.
- **RA-44.7 — no credit.** A vacuous check frozen in a review document is a review defect, not a runtime
  regression. Ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, unchanged. Selector 497
  untouched; CP2 491/491 accepted; R3 403/497 rejected. RA-41's junction/sector clauses remain frozen
  **UNEXERCISED** and the multi-carrier STOP stands undischarged.

---

## RA-43 — producer locus for terminal contact, germ and face gauge **FROZEN at M6-DEFN-R5-R4-REV** (2026-10-10)

Discharges `R4-REV-01A`, `R4-REV-01B`, `R4-REV-02A`. Basis:
`Architecture_M6_CP3_R4_Producer_Locus_Review_Decision.md`. All three independent findings are ACCEPTED;
the producer-proof remedy they demand is discharged by exact symbol and line below. No runtime credit.
RA-34.3, RA-36.4/.5/.6, RA-38, RA-39, RA-40 and RA-42 (as corrected) stand.

- **RA-43.1 — the vertex-star producer, named.** `resolve_field_vertex_transit`
  (`src/geometry/SurfaceCellTracing.cpp:1257`). Its star loop at `:1452-1476` iterates
  `topology.transports()` filtered to adjacencies **incident to `sourceVertex`** (`:1453-1454`), steps
  face->face across `adjacency.sourceEdge` (`:1456-1462`), and accumulates a typed `transportPath` of
  `SourceEdgeTopologyKey` plus `composedSignedLift` = tau mod 4 (`:1473-1476`); frontier at `:1376`,
  `:1382`, `:1516`. Per-face sectors come from `vertex_star_sector` (`:1053`) returning `VertexStarSector`
  (`:1042-1051`) with typed `sourceFace`, `nextRadialVertex`, `previousRadialVertex`. **`railFanPotentials`
  is STRUCK: it never existed in `src/` or `include/`.** RA-38.5's and RA-42.4's substance is restored
  against this citation — only the carrier **cut** is missing, and it is a `continue` on carrier membership
  inside the `:1452` loop: no new state, no new tau definition, no A5-side search.
- **RA-43.2 — the terminal contact owner is the pipeline curve-network producer, not A4.**
  `SurfaceCellRail::sourceVertices` is authored at `src/pipeline/RemeshPipeline.cpp:9328-9356` from
  `OrderedCurveEdge::startVertex`/`endVertex` (`:9306`, assigned `:9401`), with continuity enforced at
  `:9335` and closure at `:9353`; single-edge rails at `:9491`. The chain is therefore **exact, not
  epsilon-derived**. Because it is authored in the pipeline stage, A4 **cannot reach it**: RA-42.1 is
  **relocated** — the typed terminal contact is a **required input bound at the A4 factory boundary** on the
  RA-40 precedent, fail-closed when absent or ambiguous. A4 may not derive it, and the endpoint certificate
  still stops reading `from.face`/`to.face` for contact purposes.
- **RA-43.3 — four namespaces, none interchangeable.** `SurfaceTracePoint::face` is a raw source-face row
  (header `:90-93`); `SurfaceCellRailSample::sourceEdge` is a **local corner index in [0,3)** (proved by its
  own guards at `src/geometry/SurfaceCellTracing.cpp:5824` and `:5841`); `SurfaceCellRail::sourceEdges`
  holds **feature-edge indices into `featureMap.edges`** (`RemeshPipeline.cpp:9348`); component meshes carry
  component-local renumbering (`MeshComponents.cpp:72-116`). Every binding states and converts its
  namespace explicitly. A raw `int` equality across two of these is **not** a topological claim.
- **RA-43.4 — `rail_sample_source_vertex` is an existing defect.**
  `src/geometry/SurfaceCellTracing.cpp:5820-5844` attributes a source vertex by
  `std::abs(value - 1.0) <= 1.0e-8` on barycentric coordinates and is live at `:5868` and `:5937-5938`.
  Under RA-42.2 this is prohibited. It is **replaced** by the exact chain of RA-43.2, never wrapped,
  tightened or re-toleranced. Scheduled for Code + Build; not implemented in a review turn.
- **RA-43.5 — WITHDRAWN by RA-44.2: the named oracle is vacuous.** `find_frame(face)` publishes all four
  branches and cannot discriminate; `make` holds no axes with which to re-derive. Superseded by RA-44.2's
  two-part witness. Retained below for the record only; the absent-gauge hole it identified is real and is
  closed by RA-44.3. Original text: _face-gauge authentication, constructible inside the RA-40.1 boundary._ `make` at
  `src/geometry/SurfaceCellTracing.cpp:8015-8020` checks only cardinality against `face_count()` and values
  in `[0,4)`; its leading `!sourceFaceBranchRotations.empty() &&` lets an **absent** gauge pass unchecked -
  the same optionality RA-40.1 removed for the atlas. Required: presence is **mandatory** whenever A6 seam
  logic consumes it, and each value is authenticated **per face** against
  `fieldTransportAtlas->branch_topology().find_frame(face)`
  (`include/directional/authority/FieldTransportAtlas.h:874`, `:800`, semantics `:52`) using the
  `matchesA3` shape already written at `:7996-8009`. **A caller's own gauge is never its own oracle.**
  Sixth occurrence of publish/reach after RA-34.3, RA-35, RA-38, RA-40 and RA-42.
- **RA-43.6 — RA-41 freezes, restricted.** The RA-41 review gate asked Review to accept a source-exact
  implementable authority path or return the candidate as an architectural blocker. RA-41.1 is satisfied by
  RA-43.5 and RA-41.2 by RA-43.1/.2, so **RA-41 is FROZEN scoped to the singleton terminal contact**. Its
  junction and sector clauses are frozen as **UNEXERCISED**: 38 printed rows are one physical singleton
  carrier and the 39th is receiptless, so they may not be cited as validated and R4's multi-carrier STOP
  stands undischarged.
- **RA-43.7 — no credit.** Review-evidence defects in architecture documents are not runtime regressions.
  Ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, unchanged. Selector 497 untouched;
  CP2 491/491 accepted; R3 403/497 rejected with 94 RED and 88 accepted CP2 losses. No promotion.

---

## RA-42 — terminal contact ownership and the A3/gauge trust boundary **ACCEPTED at independent R4-REV Design Review** (2026-10-10)

Resolves `R4-REV-01` and `R4-REV-02`. Basis:
`Architecture_M6_CP3_R4_Terminal_Contact_And_Gauge_Review_Decision.md`. No runtime credit; RA-34.3,
RA-36.4/.5/.6, RA-38, RA-39 and RA-40 stand.

**Decisive fact.** `SurfaceTracePoint` is `{int face; Eigen::RowVector3d barycentric;}` — **no source vertex, no
source edge**, and `face` is a **raw row index**, not a `SourceFaceTopologyKey`. The witness RA-41.2 requires
therefore cannot be authored from a trace point. Meanwhile `SurfaceCellRail` publishes ordered `sourceVertices`
and `SurfaceCellRailSample` publishes `sourceFace`/`sourceEdge`: the raw source-index provenance exists one structure
away, but its typed mapping to an oriented front terminal contact remains unproven — the **fifth** occurrence of the publish/reach pattern after RA-34.3,
RA-35, RA-38 and RA-40.

- **RA-42.1 — terminal contact ownership.** The terminal rail contact witness is authored by the **rail/front
  producer** from `SurfaceCellRail::sourceVertices` and the rail samples' raw `sourceFace`/`sourceEdge` after independently checked conversion to typed source entities and a unique front-contact association, and
  published as typed authority on the endpoint certificate. **Owner relocated by RA-43.2:** that chain is
  authored in the pipeline stage (`RemeshPipeline.cpp:9328-9356`), so A4 receives the contact as a required
  factory-boundary input rather than reaching for the rail. The endpoint certificate **stops reading**
  `from.face`/`to.face` for contact purposes.
- **RA-42.2 — no incidence from geometry.** Deriving source-vertex or source-edge incidence from
  `SurfaceTracePoint::barycentric`, or any floating-point predicate, is **prohibited** — it is RP-01
  authority-domain conflation, typed authority from a non-authoritative representation, in a pipeline that
  exactifies binary64 bit-for-bit. Absent typed incidence, fail closed with a code naming that absence.
- **RA-42.3 — typed diagnostics.** Carrier, face and endpoint diagnostics are emitted as typed
  `SourceFaceTopologyKey`, never bare row indices. A raw-row record is not evidence of a topological claim.
- **RA-42.4 — germ derivation.** The germ is the arc of the A2b vertex star at the terminal vertex after cutting
  the incident hard rails, from the traversal named in **RA-43.1** with the incident carriers cut. The formerly cited
  `src/geometry/SurfaceCellTracing.cpp:18120-18206` does **not** implement that construction: it contains
  isolation-seam certificate handling/diagnostics. The symbol `railFanPotentials` never existed in `src/` or
  `include/`; **RA-43.1** supplies the exact symbol, line range and typed source-entity linkage this clause
  required, so the obligation is discharged rather than outstanding. Equality with the carrier's incident pair holds **at the
  contacts**, never at the trace endpoints — the exact locus of RA-39.1's error.
- **RA-42.5 — RA-40.1 is unconditional.** The atlas mandate is **not** scoped. The earlier conditional
  pre-commitment is **withdrawn**: its premise that a rail-free product carries nothing A3-derived is refuted by
  `sourceFaceBranchRotations`, a raw unauthenticated gauge vector, and a conditional exception would preserve the
  production `CrossFieldResult` null-atlas ingress that RA-40 exists to close. Legacy callers **migrate**; the
  seven DCEL failures are **fixture defects to fix, not cases to exempt**.
- **RA-42.6 — gauge inside the boundary.** `sourceFaceBranchRotations` must be validated against published
  source authority — at minimum cardinality equal to the source face count and values matching what the
  authority publishes — and may not remain unchecked.
- **RA-42.7 — RA-38.3 scope.** RA-38.3's boundary-vertex and singleton STOP governs **multi-carrier
  through-junction sector transport** only and does **not** fire at a terminal contact vertex.
- **RA-42.8 — no runtime credit.** The 39-row family remains one carrier configuration with **zero**
  multi-carrier instances; RA-41.2's junction clauses stay unexercised and R4's multi-carrier STOP is
  undischarged.

**RA-42 independent re-review correction (M6-DEFN-R5-R4-REV):** RA-42 describes required future producer behavior,
not proof that this behavior already exists. `SurfaceCellRailSample::{sourceFace,sourceEdge}` are raw `int` values
(`sourceEdge` is local); the current front has no published typed terminal contact. Reject missing or ambiguous
producer-owned incidence rather than deriving it from barycentric epsilon predicates. The held R4 Code+Build plan
must retain the unconditional RA-40.1 atlas mandate. No runtime credit or implementation release; see
`Architecture_M6_DEFN_R5_R4_Independent_Review_Record.md`.

---

## RA-40 — A3 trust, CB/TB sequencing and excluded-test status **ACCEPTED at independent R3 A/B/C Review** (2026-10-10)

Resolves the `M6-CP3-CB1-ENTRY-R3` A/B/C block. Basis:
`Architecture_M6_CP3_R3_ABC_Review_Decision.md`. No runtime credit; RA-34.3, RA-36.4/.5/.6, RA-38 and RA-39
stand unchanged.

- **RA-40.1 — Decision A: factory-bound atlas re-derivation (A2 minimal). A1 rejected.** `make`
  (`src/geometry/SurfaceCellTracing.cpp:7969-7982`) currently accepts `hardRailFieldTransitions` and
  `hardRailRouteCertificates` as unauthenticated **data**. A balanced `+1 mod 4` on both paths leaves
  `χ_next ∘ φ_A == φ_B ∘ χ_prev` satisfied, because a consistency relation is gauge-invariant — so consistency
  can never substitute for authenticating values. `make` must therefore take an atlas bound by
  `FieldTransportAtlas::matches_source_faces` (`include/directional/authority/FieldTransportAtlas.h:893`) to the
  same source matrix, authority and vertex count, and **re-derive every A3-sourced value it is handed — each
  nonrail φ and each carrier χ — via `transition_value`, requiring exact equality including reverse orientation
  and reciprocity.** No new attestation schema is authorized or needed: the atlas is already
  `const authority::FieldTransportAtlas *` in options (`include/directional/geometry/SurfaceCellTracing.h:2186`)
  and A4 already derives through it; only the factory boundary lacks the binding. **Absent atlas → typed
  fail-closed**; there is no unauthenticated-but-accepted mode. A global per-face branch-gauge difference may not
  substitute for true A3 values (RA-31a). All twelve public factory call sites migrate explicitly — one
  production at `:12195`, eleven tests — with **no** default-null convenience overload. RA-39 endpoint-local
  single-terminal-carrier χ is unchanged and this is not a licence to reintroduce RA-37a fan detours.
- **RA-40.2 — Decision B: CB may close on authoring plus compile.** The binding plan forbids running Directional
  binaries in CB and places the **497** execution in a distinct TB, so a CB gate demanding produced runtime
  witnesses or the 47 accepted→RED recoveries is **unsatisfiable**. CB closes on complete source/test authoring
  and exact eight-target GMP/GMPXX compile/package evidence, with **nonvacuity enforced in compiled assertions**,
  claiming **no** produced positive. The authorized TB successor is named **before** root `STATUS` becomes
  `COMPLETE`. The 497 gate, all organic D1/D2/D3/D5 and A6/A7 witnesses, the odd-τ witness and the 47
  accepted→RED recoveries remain **TB** obligations; each TB RED is investigated individually and returned to a
  **new** authorized repair turn. Tool or time exhaustion is **not** `BLOCKED`.
- **RA-40.3 — Decision C: separately authorized, separately counted, diagnostic weight only.** The four excluded
  source-defined tests
  (`SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`,
  `M6CP3.HardRailPublishedTauRequiresIncidentSourceFaces`,
  `M6CP3.A6SeamDirectionRejectsForeignFaceAndWedgeBindings`,
  `M6CP3.A7TypedWedgeSheetMismatchRejectsCachedMembership`) must **not** be folded into the frozen 497, which
  would mutate a single-owned gate and imply they had run; nor left unrun, which makes four authored contract
  tests zero-evidence (`LESSONS.md` 171). They run in a **separate** artifact-only focused diagnostic turn,
  **counted separately**, with results carrying **diagnostic weight only and no acceptance credit**, until a
  Review folds them into a successor gate under the pre-commitment discipline.

---

## RA-39 — P0/P1 endpoint-local attachment and transport **ACCEPTED at independent R3 producer Design Review** (2026-10-08)

Resolves the remaining `M6-CP3-CB1-ENTRY-R3` STOP. Completes RA-37a's P0/P1 obligation; **RA-37a and RA-38 are
not replaced.** Basis: `Architecture_M6_CP3_R3_Endpoint_Attachment_Review_Decision.md`. No runtime credit.

**Key fact.** `src/geometry/SurfaceCellTracing.cpp:18271-18285` requires `first.route == second.route.reversed()`,
so `first.from`/`second.to` lie at the **same spatial end** and `first.to`/`second.from` at the other. Each
endpoint certificate is therefore a **cross-rail pair at one spatial end**, one face per side — not a traversal
of the polyline. The current walk-all-carriers accumulation at `:18297-18330` is the superseded RA-36.1
end-to-end shape reappearing at endpoint level.

- **RA-39.1 — attachment, no new authority.** For endpoint pair `j` the terminal carrier `C_j` is the route's
  first (`j=0`) or last (`j=1`) oriented step. The certificate is valid only if `{from_j, to_j}` equals
  `{C_j.firstFace, C_j.secondFace}` as an **unordered pair**, with `χ_j = C_j.firstToSecond` oriented by which
  face is `from_j`, read from the already-published `SurfaceHardRailFieldTransition`. Any other pair → typed
  fail-closed **no local attachment**. **No path walk at an endpoint.**
- **RA-39.2 — sector agreement.** Each endpoint pair must hold exactly **one face per RA-38 sector**. Both faces
  in one sector, or a face outside the junction star where a junction exists, fails closed.
- **RA-39.3 — transport belongs to the square.** A4 publishes, per junction and per sector, the **ordered
  non-rail A2b source-edge witnesses** of the within-sector radial chain joining consecutive carriers' same-side
  faces. They serve the square only and are never an endpoint crossing. On the reviewed fixture
  `φ_A : 0 → 1 → 4`, `φ_B : 3 → 6 → 7`. Path-independence and holonomy rejection carry over from RA-38.
- **RA-39.4 — the square compares, it does not compose.** Validation applies `χ_1 ∘ φ_A = φ_B ∘ χ_0` as a
  comparison **after explicit transport**. Blind composition of χ across carriers and any end-to-end
  `composedTurn` remain prohibited.
- **RA-39.5 — schema.** Replace `SurfaceHardRailRouteEndpointCertificate`'s `orientedSteps`/`composedTurn`
  (`include/directional/geometry/SurfaceCellTracing.h:1488-1493`) with the single terminal carrier and its
  oriented `χ_j` — the correction **removes** state — and add the RA-39.3 radial witnesses, for which the struct
  currently has no field. A5 consumes only this published immutable certificate: no path search, no sheet/region
  label inference, no first-step selection.
- **RA-39.6 — singleton degenerates correctly.** For a one-carrier route both endpoint pairs share that carrier,
  there is no junction, `φ_A`/`φ_B` are identity, and the square reduces to the reciprocity already required.
  Existing singleton behaviour must not change.
- **RA-39.7 — no runtime credit.** Existence of a produced multi-carrier paired front is **not** established; a
  hand-authored input fixture is not a produced certificate. All RA-34.3 R2-P3 stop gates and RA-36.4/.5/.6
  stand, and an empty bounded search stops for Review.

---

## RA-38 — constructive sector derivation **ACCEPTED at independent R3 producer Design Review** (2026-10-08)

Resolves the `M6-CP3-CB1-ENTRY-R3` preflight STOP. **Implements RA-37a correction (1); RA-37a is not replaced.**
Basis: `Architecture_M6_CP3_R3_Sector_Derivation_Review_Decision.md`. No runtime credit.

- **RA-38.1 — the sectors are the cut star arcs.** At a rail junction vertex `v` on an interior orientable
  manifold link, the faces of `v`'s star form a cycle under "share a spoke edge at `v`". **Cutting that cycle at
  the two incident hard carriers yields exactly two arcs — the two unique oriented sectors — and each incident
  carrier contributes exactly one face to each arc.** Mechanically verified on the reviewed 3×3 fixture: star
  cycle `0 → 1 → 4 → 7 → 6 → 3 → 0`; carriers `(1,4)`,`(4,7)`; sectors `{0,1,4}` and `{3,6,7}`; carrier `(1,4)`
  faces `{0,3}` split `0∈A / 3∈B`; carrier `(4,7)` faces `{4,7}` split `4∈A / 7∈B`.
- **RA-38.2 — φ is within-sector radial transport.** The endpoint-local path from one carrier's face to the next
  runs **inside one sector** along **non-rail** A3 transitions. A4 publishes, per endpoint pair and per junction,
  the ordered non-rail A2b source-edge witnesses of that chain. Carrier-to-carrier face identity is neither
  required nor permitted.
- **RA-38.3 — fail closed, matching RA-37a's domain.** STOP on: boundary vertex (star is a path; cutting yields
  three arcs); more than two incident hard carriers (branch junction; no unique pair); exactly one incident
  carrier (rail terminates — no through-transport); non-manifold or singular star; foreign barrier inside an arc.
- **RA-38.4 — two distinct validators must be corrected together.** In
  `src/geometry/SurfaceCellTracing.cpp:8019-8118`: (i) `previous.secondFace != transition.firstFace` is the
  superseded RA-36.1 category error at a second site and must become within-sector radial chaining; (ii)
  `endpoint.orientedSteps.size() != expectedSteps.size()` unsoundly ties endpoint-path length to carrier count,
  when the real length is set by **fan valence per junction**. The reviewed 3×3 fixture satisfies (ii) only by
  coincidence (two carriers, chain length two), so a correction that fixes only (i) and validates on 3×3 will
  pass while (ii) stays wrong. Additionally the A4-side gate at `:18312-18330` must not precede the
  sector/junction logic, or the corrected path stays unreachable.
- **RA-38.5 — publish, do not invent.** The original assertion that `railFanPotentials` traverses the whole star at
  `SurfaceCellTracing.cpp:18120-18206` is unsupported (that range handles isolation-seam certificates and
  diagnostics). The real producer is named by **RA-43.1** (`resolve_field_vertex_transit`, `SurfaceCellTracing.cpp:1257`, star loop `:1452-1476`), which restores this clause's substance; A4 already knows the hard carriers (it builds `hardRailFieldTransitions`); only the carrier **cut** is missing,
  and it is a local derivation over data A4 already owns. Forbidden: guessed sectors; a global face-star
  potential used as ownership rather than post-ownership cross-check; first-by-row face selection; a new τ
  definition; any A5-side path search or inference from sheet/region labels.
- **RA-38.6 — no runtime credit.** Existence of a real A4-produced multi-carrier paired HardRail front is **not**
  established; a hand-authored input fixture is not a produced certificate. If the bounded search finds none, the
  multi-carrier path is unexercised and must not be cited as validated. All RA-34.3 R2-P3 stop gates and
  RA-36.4/.5/.6 stand.

---

## RA-37a — ACCEPTED by `M6-DEFN-R5-R3-REV` with binding amendment (2026-10-08)

**`M6-DEFN-R5-R3-REV` ACCEPTS RA-37a as a *bounded, fail-closed source-topology contract*; this is not any new runtime promotion. Exact successor after final beacon: `M6-CP3-CB1-ENTRY-R3` Code + Build only, with mandatory source A4 two-sector and both endpoint-local path STOPs.** CP2 491/491 remains accepted; R2 rejected 444/497; 47 accepted-green losses; 64/17/47, debt 1. See `Architecture_M6_DEFN_R5_R3_Review_Record.md`. No organic D1/D2/D3/D5 positives or A6 recovery accepted.

**Normative corrections:** (1) oriented A2b topology and A4 hard-feature owner determine the unique two source-vertex fan sectors only for connected orientable two-manifold links, without foreign barriers; otherwise fail closed/STOP; (2) source-keyed nonrail radial A3 side paths and owner-rail crossings must prove reciprocity and a typed commuting square; (3) for each of the two distinct **spatial endpoint pairs** A4 publishes its own locally anchored cross-rail path and `τ_j` from trace-selected source faces, and the along-rail square **only compares** the two endpoint mappings after explicit transport. Do not blindly compose χ values across distinct carriers or treat a path reaching the opposite spatial endpoint as a local attachment. A5 consumes only this immutable certificate. All RA-36.4/.5/.6 singleton/fail-closed/noncredit obligations remain. Full proof boundary, falsifiers and no-implementation evidence in `Architecture_M6_DEFN_R5_R3_Review_Record.md`. Earlier candidate RA-37 section below is historical and superseded by this binding amendment; it is not a second active contract.

---

## RA-37 — proposed M6-DEFN-R5-R3 amendment (**CANDIDATE ONLY; NOT FROZEN**, 2026-10-08)

The independent `M6-CP3-TB1-ENTRY-R2-REV` rejected 444/497 R2 and established that RA-36.1's requirement for consecutive HardRail carrier edges to share an incident face is unsound for legal source feature paths. The earlier RA-36 text below remains historical frozen authority **under explicit architectural challenge**, not silently overwritten. The proposed replacement in `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Record.md` requires (1) A2b/A4-proven unique oriented left/right vertex-fan side sectors for each carrier junction, independent of face-row order, global sheet and Z4 potential; (2) directed, typed A3 transitions on every admissible side edge; (3) commuting square `χ_(i+1) ∘ φ_left = φ_right ∘ χ_i` with common source/target; (4) two separately well-typed A4 endpoint-pair certificates consumed, not inferred, by A5; (5) reciprocal/owner/fan/holonomy/missing-authority fail-closed behavior and unchanged singleton. **STOP if producer topology cannot establish unique side paths.** The concrete 3×3 input `(1,4),(4,7)` proves a source-topology counterexample, not produced A4 multi-edge success. No organic D1/D2/D3/D5 or A6 success is claimed. Frozen future TB unchanged 497=30+12+449+6; 47 formerly accepted CP2 identities must recover. Stable ledger **64/17/47**, debt 1. **Only `M6-DEFN-R5-R3-REV` may accept/amend this candidate and release the held R3 Code+Build plan.**

---

## Current independent Review HOLD — RA-36 face-sharing premise disputed (2026-10-08)

R2 runtime Review `M6-CP3-TB1-ENTRY-R2-REV` **REJECTS R2 444/497** and records an accepted-green A4 HardRail producer false rejection. Existing frozen RA-36.1 says consecutive rail edge carriers share a typed source face; legal fixture edges `(1,4)` and `(4,7)` meet at vertex 4 but have disjoint incident source-face sets `{0,3}` and `{4,7}`. This is a static topology counterexample to an assumed universal invariant, **not evidence that a two-edge route was produced in the R2 runtime**. RA-36 text below is preserved unchanged as historical frozen authority; **do not implement a silent weakening or regard the disputed premise as sufficient for a new CB**. Exact next: `M6-DEFN-R5-R3` proposes candidate RA-37 typed A3-side fan transport contract, then mandatory independent `M6-DEFN-R5-R3-REV` to freeze/reject an amendment. R2 candidate unpromoted. Full review `Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md`.

---

# M6 Frozen Definitions — Occurrence, Quotient, Embedding, Independent Verification

**Status:** FROZEN / M6-CP1 and M6-CP2 CLOSED / ACCEPTED. CP3 entry R1 candidate `11488700954 / 68000a95` **REJECTED** at 482/497 by RA-32; predecessor P1/T1 regressions recovered, prior `RP-01` seam-domain event remains open. Stable accounting **63 / 17 / 46**, debt 1. **EXACT NEXT = `M6-CP3-CB1-ENTRY-R2`** after independent `M6-DEFN-R5-R2-REV` accepted RA-34 as bounded Definition. R2 compile-only is released with strict A4 typed incidence and organic-witness stop gates; CB2/CP3 exit held. RA-1 – RA-32 normative as annotated, RA-34 accepted amendment supersedes RA-33.1/.3 only.
**Date:** 2026-09-25
**Definition authority:** this record is the normative M6 contract for A5 occurrence creation, A6 quotient construction/materialization, A7 source-attached geometry embedding, and the M6 structural portion of A8 independent verification. It refines `DESIGN.md` §14 M6 without changing accepted M5 producer semantics or pulling M7 disposition/degradation work forward.

This definition turn changes documentation/planning only. It changes no product source, test, fixture, selector, benchmark, or build source and executes no generated Directional runtime.

## 1. Entering authority

M6 enters only after final `M5-CP4-TB2-REV` acceptance:

- accepted package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`;
- accepted selector449: **449/449 PASS**, LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449 SHA-256 prefix `9c88a5ed...c5707`, owner census **32 / 301 / 75 / 41**;
- stable accounting **51 events / 14 categories / 37 recurrences**;
- produced-witness debt **1**, the M6-owned closed-complex `G4-B002` subject.

The Definition audit used exact source snapshot run/artifact `36026363482 / 10819439146` at source SHA `c9be476d75e6f5d6df11304ad6b926b27b36430f`; provider artifact SHA-256 `6331c1189591e0429128495719d6168c92827c9024175b2d121387706519d762`, embedded source archive SHA-256 `b57fe2df11bd0d988196b45dee8855581bff8cce942ce66c20b68ac8ee1b1b2e`, and all **5305/5305** source manifest rows verified. No generated Directional runtime executed.

**Process-only observation (`M6-DEFN-OBS-01`, +0):** several small repository documents were fetched directly before the turn fixed the mandatory `READ_MODE`. No semantic conclusion or mutation was accepted from that pre-snapshot inspection. The turn then froze `READ_MODE=snapshot`, acquired and verified the exact source authority above, and all decisive static adjudication used those verified bytes. Existing tool-conservation guidance already covers the pattern, so no new `LESSONS.md` rule is created.

The M5 `G4-B004` half is accepted and immutable: one **pipeline-produced** topology region is multi-isolation, owns a checked internal isolation-seam certificate, and owns a canonical periodic relation explicitly named by reciprocal `PeriodicCut` edges. M6 consumes that fact; it does not reconstruct, weaken, or reinterpret it.

## 2. Current implementation diagnosis

The current transitional function `build_authoritative_phase_front_mesh(...)` performs several future stages inline: it allocates corner occurrences, verifies relation ownership, performs quotient union, chooses quotient representatives, writes geometry, and publishes lineage into `PureQuadMesh`. This is precisely the stage coupling M6 must remove.

Two source facts constrain the cutover:

1. the production classifier now passes an explicit **empty isolation-barrier set** to `classify_source_surface_labels(...)`; hard-feature rails remain topology-region/chart/rail barriers and are not automatically `IsolationSheetId` barriers;
2. the transitional materializer still contains geometric representative consistency and output-lineage publication in the same procedure as quotient construction.

M6 therefore separates products rather than adding another downstream repair layer.

## 3. Stage A5 — `SurfaceOccurrenceComplex`

### 3.1 Sole producer and inputs

**Sole producer:** `SurfaceOccurrenceComplexProducer` (M6 A5).

**Typed inputs:** the complete immutable set of accepted A4 `RegionCellComplex` products plus the already-accepted M5 relation/certificate authority carried by those products. A5 does not consume output vertex rows, `PureQuadMesh`, world-space weld results, `SurfaceCellPipelineContext`, or diagnostic hashes as semantic authority.

### 3.2 Immutable output

```text
SurfaceOccurrenceComplex
  cells[]
    CellId
    cornerOccurrences[4] : OccurrenceId
    directedSides[4]
      from / to OccurrenceId
      exact incident-cell interior-side source authority
      ordered DirectedSideIsolationEvidence
  occurrences[]
    OccurrenceId
    CellId owner
    canonicalCornerRole
    exact SourceSupport
    TopologyRegionId
    CornerWedgeSheetSet              // sorted, unique, non-empty
    CornerWedgeFaceBindings[]        // ordered contiguous fan; per-face (face, sheet, chart); no branch (RA-11)
    CornerPlacementProvenance        // A4 corner LocalLatticeState verbatim + its selected-face label; placement only (RA-11)
    CornerWedgeIsolationEvidence[]   // exact (region,seam-edge) refs + traversal orientation
    face-independent lattice phase / coordinate / scale provenance
  ownedRelations[]
    OccurrenceRelationId
    relationKind          // OrdinaryFront | HardRail | Periodic | SingularityPort
    firstOccurrence
    secondOccurrence
    kind-specific owner   // none for OrdinaryFront; existing HardRail/Periodic authority unchanged
  OccurrenceComplexCertificate
```

Every accepted A4 cell appears exactly once and owns exactly four distinct corner occurrences and four directed sides. Every relation endpoint names an occurrence that exists in this product. A5 **does not union occurrences** and does not choose an output representative.

For a seam-incident corner, `CornerWedgeSheetSet` is the sheet set of the contiguous source-face fan arc covered by the cell interior between the last positive-length incoming side segment and first positive-length outgoing side segment. Edge support spans at most its incident faces; vertex support spans the exact contiguous fan arc. The corresponding wedge certificate references are exactly the checked seam edges crossed by that fan. At a non-seam corner the set is a singleton.

A seam-collinear directed side derives its incident-cell interior source face by exact chart orientation and canonical cell interior, never by source-face row or lexicographic triangle selection. Its side evidence names the exact checked seam certificate. Mid-side seam crossings are likewise published on the directed side.

Face-dependent field chart, branch rotation, and sheet provenance are per wedge binding/side. A seam occurrence must not combine sheet/support selected from one face with chart/branch selected from another. Face-independent lattice phase, coordinate, and scale remain value/provenance and are not identity.


**R2 exact side/binding law.** A directed side is partitioned in traversal order into maximal positive-length exact `SourceSupport` spans. A span is source-edge-collinear exactly when its open interior support is that `SourceEdgeSupport`. For an accepted `orientationValidated` A4 cell, the semantic incident-cell interior face of such a span is the unique incident source face selected by canonical directed-edge winding and the accepted cell-interior side; builder-local row/lexicographic representative-face tie-breaks are non-authoritative. The rule applies identically to uniform, periodic-chart, and bounded-disk builders. An occurrence's canonical binding signature is the complete ordered tuple set `(sourceFaceTopology, IsolationSheetId, SourceProjectionChart, branchRotation)`. Every admissible wedge stays within one topology region and one chart component and stops at source/region/hard-rail boundaries.

**R2 lineage evidence carrier.** Complete wedge/side isolation evidence is additionally projectable as lineage equivalence kind `CornerWedgeIsolation` with one or more ordered semantic transitions `(TopologyRegionId, SourceEdgeTopologyKey, fromSheet, toSheet)`. That kind is evidence-only: it is not an A5 `ownedRelation`, carries no HardRail/Periodic owner, selects no relation path, and never creates quotient equality.

### 3.3 Occurrence identity

`OccurrenceId` is the semantic pair:

```text
(CellId, canonicalCornerRole)
```

where `canonicalCornerRole` is the corner between two adjacent directed sides in the A4 cell's immutable canonical cycle. The cycle's orientation/rotation is fixed by A4 semantic authority before A5; storage row, vector position, scheduler order, output row, world-space position, lattice coordinate, representative face/sheet, hash, and cache index are excluded.

Two occurrences remain distinct even when all of these coincide:

- lattice coordinate;
- exact source support;
- chart-local coordinate;
- 3D position.

Only A6 may equate them, and only through a verified A5 owned relation.

**`CellId` basis (reviewing-agent note; the definition is unchanged).**
- **What `CellId` is today.** The accepted A4 `CellId` is `from_index(rank)` over the sorted set of `(TopologyRegionId, region-chart grid ordinal v*width+u)` (`SurfaceCellTracing.cpp:17060-17075`, `:7785-7793`). `TopologyRegionId` is itself a rank over regions sorted by `canonicalFaceTopology`, a key built from source-vertex IDs (`:8520-8575`, `:8687`). Its semantic content is therefore (region canonical face topology, canonical chart cell coordinate). The chart position is legitimate *cell* identity, and the §3.3 lattice-coordinate exclusion concerns equality **between** occurrences.
- **Invariance evidence.** Face-row invariance of region, chart and periodic-cut identity is already accepted: selector449 rows 129, 196, 213, 245 and 254.
- **Known limit.** Rank-based IDs **renumber when a cell is inserted or omitted anywhere**. M6 does not rely on stability across differing cell sets, but M7 omission bookkeeping will, and `M7-DEFN` must decide whether a content-keyed `CellId` is required then.
- **Consequence for CB1.** The A5 permutation test must permute **source face rows**, not only cell storage (row 213 already covers storage). If face-row permutation renames `OccurrenceId`s because of A4 `CellId`, that is the CB1 stop rule "changing A4 `CellId` semantics". It routes to Review/Definition and must not be satisfied by a storage-only test.

### 3.4 A5 certificate and failures

`OccurrenceComplexCertificate` proves:

- one A5 cell record per accepted A4 `CellId`;
- exactly four unique occurrence IDs per cell;
- the four directed sides form the cell's exact ordered cycle;
- every occurrence has exactly one cell/corner owner and one complete contiguous wedge authority;
- every required seam crossing on a wedge or directed side names exactly one matching checked `(TopologyRegionId, SourceEdgeTopologyKey)` certificate;
- every relation has two existing, distinct typed endpoints and satisfies its **kind-specific** owner contract: `OrdinaryFront` has no owner, HardRail/Periodic keep their accepted typed owners;
- no occurrence, wedge, side, or relation authority was inferred from geometric coincidence or global certificate search.

A5 owns fail-closed `OccurrenceConstructionFailure` codes for missing/duplicate cell ownership, missing/duplicate corner occurrence, invalid directed-side cycle, invalid/noncontiguous wedge authority, missing/duplicate/mismatched wedge-or-side isolation evidence, relation endpoint missing, duplicate relation declaration, unsupported singular/nonmanifold wedge, unsupported SingularityPort corner, unsupported hard-rail/seam wedge, and source-authority mismatch. Relation failures are **not** many-to-one: `OccurrenceHardRailOwnerMissing`, `OccurrenceHardRailOwnerMismatch`, `OccurrencePeriodicOwnerMismatch`, `OccurrenceRelationKindMismatch`, and `OccurrenceUnownedRelation` (genuinely unowned cases only) are distinct. The transitional compatibility adapter alone maps them respectively to the frozen M5-compatible names `MissingHardRailRelationOwner`, `InvalidHardRailTransport`, `InvalidPeriodicRelationOwner`, `IncompatibleAuthoritativeFrontPair`, and `UnownedRelation`. Structural endpoint/range defects remain structural failures rather than `UnownedRelation`. A rejected A5 product is not consumable.

## 4. Stage A6 — `SurfaceQuotientProduct`

### 4.1 Sole producer and inputs

**Sole producer:** `SurfaceQuotientProducer` (M6 A6).

**Typed inputs:** immutable A0 source authority plus exactly one complete `SurfaceOccurrenceComplex`. A6 may verify only typed M5 values referenced by A5 wedge/side evidence or by the existing kind-specific HardRail/Periodic relation owners. It may not search global certificate inventory, choose an alternative certificate, reconstruct semantic authority from raw boundary paths, or synthesize a missing one.

### 4.2 Immutable output

```text
SurfaceQuotientProduct
  classes[]
    QuotientClassId
    sorted member OccurrenceId set
  relationCertificates[] : QuotientRelationCertificate
  consumptionLedger[]
    OccurrenceRelationId
    firstOccurrence
    secondOccurrence
    exactlyOneConsumption
  topology
    quotient vertices identified by QuotientClassId
    one ordered quad per accepted CellId
  MaterializationCertificate
  QuotientCertificate
```

A6 is **topological**. It creates no source-attached 3D vertex representative and no geometric weld. One accepted A5 cell maps to exactly one output quad. An A5 relation becomes quotient authority only after the producer verifies that exact declared relation; an unrelated valid M5 relation remains decision-neutral.

### 4.3 Quotient identity and equality

`QuotientClassId` is the canonical, sorted, non-empty **set of member `OccurrenceId` values**. It is not the smallest member, a sequential class row, the union-find root, a representative sheet, a coordinate, or a hash.

Two classes are equal if and only if their complete member sets are equal. Relation application is deterministic over canonical relation identity, but union-find roots and traversal order are representation leaves only.

### 4.4 Exact-once relation ownership

The phrase **owned relation** means an `OccurrenceRelationId` explicitly published in A5 `ownedRelations`. Available but unreferenced M5 relation-table entries are not A5-owned relations and remain decision-neutral.

For every A5 owned relation, A6 must record exactly one `QuotientRelationCertificate` and exactly one consumption-ledger row. Zero consumption, duplicate consumption, conflicting endpoint use, relation substitution, or consumption by an unowned relation is typed failure. This is the M6 meaning of "every owned relation is consumed exactly once" and is consistent with M5's accepted unused-valid-relation contract.


### 4.5 Ordinary-front sheet/evidence validation

`OrdinaryFront` remains owner-less and `OccurrenceRelationId` is unchanged. Side validation is performed over the ordered maximal positive-length exact-support spans frozen by A5. For a non-seam-collinear near-endpoint span, reciprocal records must agree on the mapped incident-cell interior sheet and that sheet must belong to both endpoint `CornerWedgeSheetSet` values. Side-interior seam crossings are accepted only through the ordered `DirectedSideIsolationEvidence` published by A5 and exact verification of those checked certificates.

For a seam-collinear near-endpoint span, both reciprocal side records must name the same checked seam certificate/span; their exact incident-cell interior faces are the two incident source faces; their sheets are the certificate's two opposite incident sheets; and the ordered evidence lists are reverse-compatible with every sheet transition inverted. Disjoint singleton endpoint wedge sets are legal only in this explicit collinear case. Any disagreement is typed `QuotientReciprocalSideAuthorityMismatch`.

A6 records in its quotient relation certificate which wedge/side certificate references were actually verified. It never infers equality from a representative sheet. For selected HardRail/Periodic path steps, endpoint charts/chart-components come from the relation-side interior-face bindings; path start/end charts come from the first/last selected steps, never from a quotient representative face. `CornerWedgeIsolation` lineage evidence does not create a selected relation path.

### 4.6 A6 certificate and failures

`QuotientCertificate` proves the class partition is exactly the transitive closure of **verified A5 owned relations** and nothing else. `MaterializationCertificate` proves:

- every `CellId` maps to one and only one output quad;
- every output quad corner maps to the `QuotientClassId` containing that cell's corresponding `OccurrenceId`;
- every quotient class is non-empty;
- no class arose from coordinate/position equality;
- every A5 owned relation appears exactly once in the relation-consumption ledger;
- every cross-sheet union step has the exact A5-published wedge/side certificate evidence required by §4.5.

A6 owns fail-closed `QuotientConstructionFailure` codes for missing/duplicate/conflicting/nonreciprocal relation authority, invalid wedge/side sheet membership, missing/invalid seam-collinear certificate evidence, unowned relation use, zero/duplicate relation consumption, invalid class partition, missing occurrence member, degenerate classed quad, and non-bijective cell-to-quad materialization. M5's accepted typed relation failures remain unweakened. A5 owns the one-to-one semantic relation-failure vocabulary frozen in §3.4 and the compatibility adapter owns the legacy-name mapping. Once A5 certifies owner presence/equality and relation-kind compatibility, only those duplicate structural predicates may disappear from the transitional materializer; route reversal/content, periodic shift, exact relation value, exact transport application, source-support, and other M5 semantic checks remain live. M6 does not rename a valid M5 failure into success or an unrelated generic failure.

## 5. Stage A7 — `SourceAttachedGeometryProduct`

### 5.1 Sole producer and inputs

**Sole producer:** `SourceAttachedGeometryProducer` (M6 A7).

**Typed inputs:** immutable A0 source authority and one complete `SurfaceQuotientProduct`, with the A5 occurrence/source-support evidence referenced by the quotient certificates. A7 may not change A6 topology or quotient membership.

### 5.2 Immutable output

```text
SourceAttachedGeometryProduct
  topology                 // identical semantic A6 topology
  vertices[]
    QuotientClassId
    exact SourceSupport
    source-attached coordinates / barycentric representation
    intended component / isolation-sheet authority
  SourceSupportCertificate[]
  GeometryEmbeddingCertificate
```

The vertex's semantic identity remains its `QuotientClassId`. Position is a value derived from exact source support and cannot merge, split, or rename a quotient class.

A quotient class spanning multiple certified chart/sheet representations is legal only when A6's verified A5-published wedge/side evidence establishes every cross-sheet step that requires certification. `sourceIsolationSheets` is the sorted unique union of every member occurrence's `CornerWedgeSheetSet`. `sourceCharts` is the sorted unique union of every member `CornerWedgeFaceBinding.chart`. Component remapping first remaps complete binding tuples and ordered `CornerWedgeIsolation` transition tuples, and only then derives legacy region/sheet/chart projections; independent-set or cross-product validation is not semantic authority. A7 records the complete compatible source authority and the wedge/side certificate evidence referenced by the quotient certificates; it never selects a representative sheet/chart and silently discards the others.

### 5.3 A7 certificate and failures

For each quotient class, `SourceSupportCertificate` proves that every contributing occurrence is incident to the published exact support under the already-certified relation path and that the embedded value remains on the intended source component/sheet authority. `GeometryEmbeddingCertificate` proves topology is unchanged from A6 and every quotient vertex is embedded exactly once.

A7 owns fail-closed `GeometryEmbeddingFailure` codes for missing/ambiguous source support, support/certificate mismatch, cross-component or uncertified cross-sheet binding, missing quotient vertex embedding, duplicate embedding, non-finite geometry, and topology mutation. Nearest-position coincidence and epsilon welding are forbidden recovery mechanisms.

## 6. Stage A8-M6 — `VerificationReport`

### 6.1 M6 scope and M7 boundary

**Sole producer:** `SurfaceProductVerifier` (M6 structural A8).

**Typed inputs:** immutable A0, A5, A6, and A7 products and their certificates. The verifier outputs immutable `VerificationReport` only.

`OutputDisposition`, `DegradationCertificate`, tier assignment, omission, and degraded production remain **M7**. The full DESIGN A8 contract is completed in M7; M6 must not pull disposition/degradation forward merely because the verifier exists first.

### 6.2 What the verifier may recompute

The verifier may independently recompute only elementary facts from immutable inputs:

- source face/edge/vertex incidence and component adjacency from A0;
- exact incidence of a published `SourceSupport` using the shared source-support kernel;
- occurrence ownership counts and directed-side cycle incidence from A5;
- output quad incidence, edge incidence, connected components, boundary loops, Euler characteristic, and manifoldness from A6 topology;
- cell-to-quad and occurrence-to-class membership by reading the published A5/A6 IDs;
- exact composition/inversion of a **named** relation certificate's recorded transport;
- source-support incidence of an A7 embedded vertex;
- deterministic equality of immutable certificate payloads under semantic ordering.

Shared primitive value types and exact algebra are allowed. Reusing a producer's **decision procedure** is not independent verification.

### 6.3 What the verifier may never do

The verifier may never:

- create or renumber an `OccurrenceId` or `QuotientClassId`;
- union occurrences or choose a quotient representative;
- search a relation graph for a replacement route/path;
- infer a missing endpoint, route, owner, chart, sheet, source support, or relation;
- canonicalize malformed producer state into an acceptable form;
- substitute an equivalent relation or reverse relation not explicitly certified by the producer;
- weld by lattice coordinate, barycentric tolerance, 3D position, or proximity;
- repair a directed-side cycle, quad incidence, source attachment, or certificate;
- mutate A5/A6/A7 or emit a corrected product;
- invoke fallback/recovery or convert a producer rejection into a verified product.

On any violation it emits a typed `VerificationFailure` in the report. A report is successful only when the original immutable products verify as published.

### 6.4 Verification report identity

Findings are keyed and ordered by semantic stage/locus IDs, never by discovery order. The report may include representation indices as diagnostics, but changing source-row, output-row, or scheduler order cannot change the semantic finding set.

## 7. Product dependency and mutation law

The only M6 authority flow is:

```text
A4 RegionCellComplex set
  -> A5 SurfaceOccurrenceComplex
  -> A6 SurfaceQuotientProduct
  -> A7 SourceAttachedGeometryProduct
  -> A8-M6 VerificationReport
```

A later stage may reference earlier immutable IDs/certificates; it may not write into them. Aggregation is a new immutable output, never in-place normalization. `PureQuadVertexLineage`, `SurfaceCellPipelineContext`, diagnostics, hashes, output row numbers, and existing transitional materializer locals may be retained temporarily as compatibility/diagnostic surfaces, but none may become semantic stage authority.

## 8. M6 debt and blocker ownership

### 8.1 `G4-B002` closed-complex produced witness

The original contract remains unchanged: fail-closed `SurfaceCells`, recovery/fallback disabled, closed source, independently validated candidate eligibility, and a discriminating hard-feature/protection tamper. Synthetic/direct arrangement authority receives zero credit.

- **M6-CP1 mechanism owner:** establish the real A5 occurrence product and A6 stage boundary from which candidate extraction can consume closed-complex authority without `SurfaceCellPipelineContext::hasArrangement`.
- **M6-CP3 evidence owner:** re-prove the unchanged candidate-extraction eligibility oracle and hard-feature tamper on direct production after A5-A8 are complete.

CP1 mechanism evidence cannot close the production debt.

### 8.2 `G4-B001 / PR8-R034 / G4-R007`

**Disposition: not a currently demonstrated M6 implementation defect; carry as a direct-production evidence debt to `M6-CP3`.**

The historical root was a hard feature being promoted into `IsolationSheetId` authority, after which strict closure reported `LocalSheetMismatch`. Current production source explicitly separates those domains: `hardFeatureRailEdges` remain topology-region/chart/rail barriers while `classify_source_surface_labels(...)` receives an empty `sourceIsolationBarrierEdges` set. The original root condition is therefore not present at the current source boundary.

M6 must nevertheless preserve this separation:

- CP1/A5-A7 must not derive an isolation sheet from hard-rail membership;
- A7 may cross a chart/region boundary only under certified quotient relation authority and must preserve complete sheet evidence;
- CP3 owns the historical strict-valid torus **3/3** direct-production re-proof.

If CP3 reproduces `LocalSheetMismatch`, the new failure must be classified against the frozen A7 source-support/embedding contract; validators or sheet authority may not be weakened to obtain green output.

### 8.3 `G4-B004` M6 representative-consumption half

M6 closure requires the **same direct produced torus authority** accepted by M5-CP4, not a synthetic substitute. The proof chain is:

1. retain the accepted M5 same-region producer fact unchanged;
2. A5 materializes four explicit occurrences per cell and relation endpoints by occurrence ID;
3. A6 consumes every A5-owned relation exactly once and publishes quotient/materialization certificates;
4. A7 embeds the resulting quotient classes with complete source-support and multi-isolation evidence;
5. A8 independently verifies the same immutable A5-A7 products without reconstructing the M5 relation or isolation-seam fact.

Existing never-gated identities are disposed as follows:

- `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — **retain and gate during M6-CP1** as focused mechanism preservation only. It is not representative direct-production credit by itself.
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — **retain and gate during M6-CP3** as direct torus preservation. It is necessary but insufficient by itself for M6 closure because it does not independently prove the new A5/A6 exact-once ledger and A8 verification.

M6-CP3 must therefore add/use a dedicated representative M6 identity that binds the accepted M5 producer fact to A5 occurrence ownership, A6 exact-once consumption, A7 embedding, and A8 independent verification in one direct production result. No M6 evidence grants retroactive M5 credit.

## 9. Dormant CB14 identity disposition

`M5-CP3-TB1-R16-REV-OBS-01` is now fully resolved with **no M5 credit**: one deletion, and one retention with a named gating owner (see the re-adjudication below the table).

| Dormant identity | Disposition | Existing accepted replacement authority | First action owner |
|---|---|---|---|
| `M5CP3.PeriodicRelationEndpointGaugeIsIndependentAndExact` | **DELETE as superseded/redundant** | accepted `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges` covers the exact occurrence-gauge/branch rotation seam; accepted nonzero-Z4 production identities cover nonzero translation/materialization | `M6-CP1-CB1` test-source cleanup only |
| `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | ~~DELETE as superseded/redundant~~ → **RETAIN AND GATE in the first M6-CP1 prepublication gate** *(deletion stopped by the §9 precondition; see note below)* | ~~row 444 covers storage permutation~~. Row 444 reverses the **relation container** and row 432 resolves semantic direction. Neither permutes **edge storage**, and no selector449 row does. | `M6-CP1` prepublication gate (vector frozen by the CB1 report / TB1 plan) |

Deletion removes dormant, never-gated duplicate authority; it does not modify an accepted selector and cannot be cited as evidence for M5 or M6. If either accepted replacement ceases to cover the stated property, deletion must stop and be re-adjudicated before test source changes.

**Reviewing-agent re-adjudication of row 2.** The pair-swap identity swaps the reciprocal `PeriodicCut` edge pair **in `edges` storage**, remaps events and compares selected certificates after materialization, all on the nonzero-Z4 witness. Front-edge indices are a DESIGN §6.2 representation handle, and the A5 cutover must not depend on them. No accepted identity covers this permutation, so the precondition above fires. The identity is **retained untouched** and becomes a candidate in the M6-CP1 prepublication gate. Classification rules if it runs RED:
- if it is RED on the CB1 candidate, that is an edge-storage-order dependence, a §11 falsifier-1-class finding;
- its pre-cutover status is unknown, so Review must determine whether CB1 introduced the dependence.

It still carries **no M5 credit**. Row 1's deletion is upheld, because accepted row 446 checks `make_periodic_relation_endpoint_state` outputs against produced edges.

## 10. M6 checkpoint split

### M6-CP1 — product separation

Establish complete A5 occurrence, A6 quotient, and A7 geometry products in bounded Code + Build / artifact-only TB steps. Transitional `build_authoritative_phase_front_mesh(...)` may remain as a thin adapter during the cutover, but semantic occurrence/quotient/embedding decisions must move behind the stage-product APIs. CP1 also gates the focused multi-isolation mechanism identity and proves no coordinate/position weld.

### M6-CP2 — independent verifier

Introduce `SurfaceProductVerifier` consuming immutable A0/A5/A6/A7 products and certificates. It independently recomputes only §6.2 elementary facts and fails typed on every §6.3 malformed-authority class. It never calls producer repair/canonicalization/search routines.

### M6-CP3 — direct production exit

Fresh direct-production evidence must prove:

- equal coordinates/positions without a certified relation remain distinct;
- every A5-owned relation is consumed exactly once;
- source support is exact/shared, with no consumer-specific quantized identity;
- source-row, output-row, and scheduler permutation invariance;
- the unchanged `G4-B002` candidate-extraction + hard-feature tamper contract;
- `G4-B001` strict torus 3/3 re-proof;
- `G4-B004` representative same-produced-authority occurrence/quotient/embedding/verifier chain.

## 11. Frozen falsifiers

The M6 definition is falsified by any implementation that:

1. uses world-space position, lattice coordinate, vector row, output row, scheduler order, representative sheet, hash, or cache index as `OccurrenceId`/`QuotientClassId` equality;
2. lets A5 union occurrences or A7 change A6 quotient/topology;
3. consumes an A5 owned relation zero or more than once, or lets an unrelated valid relation affect the selected quotient;
4. lets the verifier search, infer, repair, substitute, canonicalize, weld, or mutate producer state;
5. credits CP1 mechanism evidence as the direct `G4-B002` or `G4-B004` production proof;
6. treats dormant CB14 identities as M5 evidence or deletes them without the replacement-authority precondition in §9;
7. re-promotes hard features into isolation-sheet authority or weakens `LocalSheetMismatch` to close `G4-B001`;
8. implements `OutputDisposition`/degradation before M7.

Any such result halts the current M6 checkpoint and returns to definition/review rather than being patched downstream.

## 12. Original `M6-DEFN` bounded successor (historical)

The original `M6-DEFN` authorized exactly one successor: **`M6-CP1-CB1`**. That consumed per-turn plan is now folded under `M6_Consolidated_Record.md` §2 and its folded-document index; the semantic CB1 boundary below remains the historical frozen authorization.

CB1 is intentionally limited to the first A5 seam: introduce content-semantic occurrence identity and a complete immutable `SurfaceOccurrenceComplex` producer, make the existing transitional materializer consume that product instead of allocating A5 occurrence authority inline, and perform the two §9 dormant-test deletions. It does **not** implement A6 quotient extraction as a new product, A7 embedding, A8 verifier, selector publication, runtime execution, or any G4 debt closure.

**Current amendment authority:** §M6-DEFN-R1 below supersedes only the seam-incident sheet/certificate portions of §§3–5 and freezes exact successor `M6-DEFN-R1-REV`; the historical CB1 authorization remains provenance only.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; unchanged |
| Decisive claims independently re-derived | current hard-rail/isolation classifier separation; current inline occurrence/quotient/geometry coupling; dormant CB14 selector absence and accepted replacement identities; M6/M7 sequencing |
| Non-vacuity checked | coordinate/position coincidence is explicitly excluded from identity; exact-once ledger can fail at zero/duplicate consumption; verifier repair/search/substitution are explicit falsifiers; direct production remains distinct from mechanism evidence |
| Prior obligations discharged/carried | `M5-CP3-TB1-R16-REV-OBS-01` discharged by §9 no-credit deletion disposition; M6 `G4-B002`, `G4-B001`, and `G4-B004` carried with checkpoint owners in §8 |
| Stable accounting | `51 / 14 / 37`; debt `1`; accepted package/source `10814505512 / e284fea7...`; selector449 accepted |
| New candidates/obligations recorded | M6 A5-A8 stage contract, `G4-B001` CP3 evidence owner, `G4-B004` CP1/CP3 gate split; tracker updated |
| ORIENTATION currency line | `M6-DEFN`, 2026-09-24 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated for M6; §4 unchanged because no witness ran; §8 no new recurring defect pattern |
| CHANGELOG | root and agent changelogs updated for `M6-DEFN` |
| ROADMAP | M6-DEFN marked complete; exact next `M6-CP1-CB1` |
| Selector manifest | n/a — no selector byte added, changed, published, or accepted |
| LESSONS | n/a — no genuinely new recurring process/product pattern; existing identity/authority and no-synthetic-success rules apply |
| Consolidation under CLEAN_UP_POLICY | consumed `Architecture_M6_DEFN_Occurrence_Embedding_Verifier_Plan.md` folded into the new M6 consolidated record/index; frozen definitions and one next-turn plan retained |
| Successor frozen | exactly `M6-CP1-CB1`; falsifiers in this record §11 and successor plan |
| Turn boundary held | runtime-free; no product/test/fixture/selector/benchmark/build mutation; no generated Directional runtime |
| review_check.py boundary | **PASS** — `review_check.py boundary --expect-selector 449=d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; no product/test/fixture/build or selector mutation; durable markers preserved |
| `STATUS` lifecycle maintained | `M6-DEFN / IN_PROGRESS` at entry; final COMPLETE beacon is the required last repository write |
| Pushed to origin, branch in sync | **CONFIRMED.** Verified Drive patch transport run/job `36028759747 / 107731931289` pushed exact patch SHA-256 `f8429d1f49adf9945b58ed2cf506f4477a5b9ef5872f0b49e3d1c8f7b9f8aab7` with schema validation PASS and `runtimeExecution=false`; owner-side Drive retirement succeeded. Turn-cleanup run/job `36028922947 / 107732420524` removed both M6-DEFN trigger markers; recursive tree verification at cleanup head found exactly the seven durable workflows and no connector-trigger/workflow-observation/turn-payload state. This isolated closeout-row update is applied against the current blob by exact SHA before the final STATUS beacon. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **UPHELD WITH AMENDMENTS.** The A5/A6/A7/A8-M6 product split, the exact-once owned-relation ledger, the verifier's recompute-only / never-repair boundary, the CP1/CP2/CP3 split, the M7 disposition boundary and the successor `M6-CP1-CB1` all stand.

**Verified:**
- **Clean process.** Docs landed (16:38Z) before the COMPLETE beacon (16:41:45Z), and nothing was written after it. `review_check.py ledgers --base 62b5ed26` PASSes, and no code surface changed.
- **§2/§8.2 `G4-B001` basis.** `RemeshPipeline.cpp:7862-7865` constructs an empty `sourceIsolationBarrierEdges` set and passes it to `classify_source_surface_labels`, as claimed. The last measurement of `G4-B001` is still pre-M1 (0/3 at artifact `9031804178`), so the CP3 re-proof is its first fresh measurement.
- **The `DESIGN.md` A8 row edit** is consistent with DESIGN §14 M7, which already introduces `OutputDisposition`. The dropped "computed, not asserted" wording survives as M7's "labeled by the verifier, never by a producer".

**Amendments:**
1. **§3.3 `CellId` basis was unstated.** `OccurrenceId = (CellId, role)` was declared free of representation handles without examining `CellId`. `CellId` is a canonical rank of (region canonical-face-topology rank, region-chart grid ordinal). Face-row invariance is accepted (selector449 rows 129, 196, 213, 245 and 254), so M6's permutation exclusions hold. The rank renumbers on insertion or omission, which is flagged for `M7-DEFN`. The CB1 permutation test must permute face rows. A note is added in §3.3, with the definition unchanged.
2. **§9 row 2 deletion stopped.** `ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` permutes **edge storage** on the nonzero witness. Its named replacement, row 444, permutes the relation container, and no selector449 row permutes edge storage. Front-edge indices are a DESIGN §6.2 representation handle that A5 must not depend on. Under §9's own precondition the identity is retained and proposed for the CP1 prepublication gate. The row-1 deletion stands.
3. **Tracker entries were buried.** This turn appended them at the end of `Regression_Root_Cause_Tracker.md`, below the 9,800-line restored history. They are moved above it, and a placement rule is added at the boundary. This is the third "append at end of a newest-first ledger" instance.
4. **Stale text.** The closed M5 frozen header still said "EXACT NEXT = `M6-DEFN`", and the TODO `G4-B001` item was stale. Both are fixed.

### Review closeout — reviewing-agent addendum

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7…`, 448 `70ff0860…`, 430 `1c412850…` via `boundary --expect-selector` |
| Decisive claims independently re-derived | `CellId` and `TopologyRegionId` construction from source; face-row invariance rows; the `G4-B001` classifier input; each dormant test against its named replacement's actual permutation; DESIGN M7 ownership of `OutputDisposition`; turn write ordering; `ledgers` |
| Non-vacuity checked | The CB1 permutation test is now required to permute face rows, because storage-only is row 213. The edge-storage witness is retained rather than deleted. |
| Prior obligations discharged/carried | R16 OBS-01 resolved: one deletion, plus one retention with a named gate owner. `G4-B002`, `G4-B001` and `G4-B004` are carried as frozen in §8. |
| Stable accounting | 51 / 14 / 37; debt 1 (M6); entry package `10814505512 / e284fea7…`; selector449 |
| New candidates/obligations recorded | Tracker addendum entry (moved M6-DEFN entries plus a placement rule) |
| ORIENTATION currency line | `M6-DEFN` (incl. reviewing-agent addendum), 2026-09-24 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §7 items 1 and 5 amended. §3, §4 and §8 are unchanged and correct. |
| CHANGELOG | Agent and root entries amended |
| ROADMAP | n/a — correct |
| Selector manifest | n/a |
| LESSONS | 176 and 178 cited; no new lesson |
| Consolidation under CLEAN_UP_POLICY | n/a — the M6 consolidated record exists and the DEFN plan is indexed |
| Successor frozen | `M6-CP1-CB1`, per its plan plus the binding reviewing-agent amendment |
| Turn boundary held | Runtime-free; no product/test/selector change |
| review_check.py | `boundary --expect-selector 449=d4a0d1b7… 448=70ff0860… 430=1c412850…`: **ALL CHECKS PASSED**. No product/test/build or selector mutation; durable markers 1→1, 3→3, 13→13. `ledgers --base 62b5ed26`: **ALL CHECKS PASSED**. |
| `STATUS` lifecycle | Resume beacon first; final `COMPLETE → M6-CP1-CB1` last |
| Pushed, in sync | Confirmed by `git status -sb` after the final push |
## M6-DEFN-R1 seam-incident authority amendment (2026-09-25, runtime-free)

This amendment supersedes only the earlier singular-sheet/relation-certificate wording described in §§3–5. It freezes the eight decisions in `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md`: corner-wedge sheet sets; wedge/side certificate carriers; owner-less OrdinaryFront membership validation; exact seam-collinear side authority; A7 union completeness; per-wedge face/chart/branch provenance; row140 adapter placement plus duplicate-check removal; and the re-scoped CB4/TB4 7+449 gate. Identity, accepted M5 authority, selector/routing bytes, HardRail/Periodic semantic owners, stable accounting **54 / 16 / 38**, and debt 1 are unchanged. Exact successor is mandatory `M6-DEFN-R1-REV`.

## M6-DEFN-R1-REV review note (2026-09-25, runtime-free)

**Core upheld; not accepted as frozen.** The amendment above is correct in model but incomplete in four blocking respects (`Architecture_M6_DEFN_R1_Review_Record.md` §3):

- **B1.** §5's union makes relation-free seam singletons multi-sheet, which violates frozen focused row5's non-empty-`equivalences` assertion unless wedge evidence is represented in lineage `equivalences`.
- **B2.** The per-binding provenance of §3.2 lacks a selection rule for each transitional consumer.
- **B3.** The §3.2 wedge endpoints must not come from tie-broken segment faces in any of the three side builders.
- **B4.** §3.4/D7 must be reconciled with §4.6.

CB4 must not start until `M6-DEFN-R2` resolves these and `M6-DEFN-R2-REV` accepts.

## M6-DEFN-R2 seam-incident authority amendment (2026-09-25, runtime-free)

`M6-DEFN-R2` resolves the four blockers and four precision items from `M6-DEFN-R1-REV`; normative detail is in `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md`.

- **B1:** lineage now has evidence-only `CornerWedgeIsolation` equivalences carrying ordered exact `(region,seam,fromSheet,toSheet)` transitions. They neither own nor select quotient relations. Split-square v0/center/v2 are therefore multi-sheet with non-empty lineage evidence without inventing v0/v2 relations.
- **B2:** every semantic consumer uses complete per-face wedge binding signatures. Transitional class keys cannot collapse to one sheet/chart; representatives are representation-only; HardRail/Periodic path charts are relation-side bindings; A7 chart/sheet/region projections derive from full binding tuples; remap preserves tuples before projection.
- **B3:** edge collinearity is exact `SourceSupport`, and the semantic incident-cell interior face is selected from canonical accepted cell orientation plus source-edge winding. Uniform, periodic and bounded-disk builders all establish the required orientation premise before A4 acceptance.
- **B4:** A5 relation failures are one-to-one and adapter-mapped to the frozen M5 names. Only duplicate owner/kind structural checks may move earlier; relation content/transport/support falsifiers stay live.
- **P1-P4:** ordered maximal support spans, reciprocal near-endpoint agreement, fail-closed unsupported singular/SingularityPort corners, and hard-rail/region wedge boundaries are explicit. HardRail-adjacent no-seam corners remain single-sheet.

The frozen-test audit covers focused rows 5/6, selector rows 186/214/239/444/446/448 and the Phase10 HardRail single-sheet assertions. No test/selector/routing byte changes. Stable accounting remains **54 / 16 / 38**, debt 1, +0. CB4 remains HELD pending mandatory independent `M6-DEFN-R2-REV`; if accepted, TB4 remains **7 + 449 = 456** fresh exact-filter processes.

## M6-DEFN-R2-REV review amendments RA-1 – RA-10 (normative, 2026-09-25, runtime-free)

`M6-DEFN-R2` is **accepted with the following amendments**. Where they conflict with earlier text in §§3–5, the DEFN-R1 record or the DEFN-R2 record, these govern. Rationale and evidence: `Architecture_M6_DEFN_R2_Review_Record.md` §3.

- **RA-1 — collinear-span interior face.**
  - Internal edge: the incident face whose source winding contains the side's directed edge.
  - Source boundary edge: the single incident face, which must satisfy the same winding test.
  - Hard-rail or topology-region-boundary edge: the winding-selected face, which must also lie in the cell's `TopologyRegionId`.

  Any failed test is a typed A5 failure.
- **RA-2 — `OccurrenceUnsupportedSingularWedge`.** Fires only when the RA-8 fan arc cannot be computed (nonmanifold vertex fan, or an arc not contained in one `TopologyRegionId` and one chart component). It never fires because of a vertex category (boundary, barrier, hard-rail or "excluded" support vertex). `OccurrenceUnsupportedSingularityPort` fires only for a corner that participates in a SingularityPort relation.
- **RA-3 — `OccurrenceUnsupportedHardRailSeamWedge`.** Fires exactly when the RA-8 arc would have to cross a hard-rail edge. For a validated cell this is a fail-closed assertion. A seam edge ending at a rail vertex inside an admissible arc is ordinary wedge evidence.
- **RA-4 — permutation checks in the seventh identity.** These compare only row-invariant semantic data:
  - `OccurrenceId`s;
  - per-occurrence `CornerWedgeSheetSet` and ordered `CornerWedgeIsolation` transitions;
  - per class (keyed by sorted member `OccurrenceId`s): lineage sheets and transitions.

  They never compare `hash_completion`, which hashes source-face rows and front-edge indices. One test-local split-square fixture helper with reversed face rows is permitted for this identity only.
- **RA-5 — `OccurrenceUnownedRelation` and enum `UnownedRelation`.** `OccurrenceUnownedRelation` keeps its current external name, with no legacy remap. The enum `UnownedRelation` continues to cover relation-identity/owner-encoding mismatch in `publish_records_for_validation`, as frozen focused row3 requires. The new owner/kind codes apply to the producer-side conditions only. An out-of-range opposite edge is `RelationEndpointMissing`.
- **RA-6 — lineage sheets.** `sourceIsolationSheets` is exactly the union of member `CornerWedgeSheetSet`s. Directed-side transitions are `equivalences` evidence only and add no sheets.
- **RA-7 — retire the endpoint-equality guard.** The transitional endpoint-sheet-equality guard (`crossesSheets` → `MissingIsolationSeamEquivalenceAuthority`) is removed and replaced by span-membership validation. At the adapter, missing seam evidence for a cross-sheet step maps to `MissingIsolationSeamEquivalenceAuthority`, and an absent or wrong named certificate maps to `InvalidIsolationSeamEquivalenceAuthority`. `QuotientReciprocalSideAuthorityMismatch` keeps its new name.
- **RA-8 — wedge arc.** The arc endpoints are the interior faces of the incoming side's last support span and the outgoing side's first support span: RA-1 for collinear spans, otherwise the face containing the span's open interior. The arc runs counter-clockwise in source winding from the outgoing face to the incoming face around the corner support. Recorded transition orientation stays incoming → outgoing (v0 `1→0`, v2 `0→1`).
- **RA-9 — span support.** Span support is defined by `SurfacePointSourceSupportResolver` (barycentric tolerance `1e-8`) applied to the span's open-interior midpoint and both endpoints. The span is collinear with an edge iff the midpoint resolves to that `SourceEdgeSupport` and the endpoints resolve within that edge's closure. The builder tie-break tolerance plays no part.
- **RA-10 — transitional `QuotientClassId`.** CB4 keeps the transitional ordinal in `lineage.quotientClass` and its hash unchanged in representation. Only the class-key tuple feeding it changes (complete binding signatures). The member-set `QuotientClassId` (§4.3) is realized at A6 extraction, not in CB4.

## RA-11 — per-face branch authority (normative, 2026-09-25, review-agent resolution of the CB4 blocker)

Rationale and evidence: folded RA-11 blocker authority in `M6_Consolidated_Record.md` §16 and git history. This amends D6, R2 §4.1-§4.3 and RA-10's class-key tuple.

1. `CornerWedgeFaceBinding` = `(sourceFaceTopology, IsolationSheetId, SourceProjectionChart)`. It has **no `branchRotation`**.
2. Each occurrence publishes `CornerPlacementProvenance`: the A4 corner `LocalLatticeState` verbatim (phase, coordinate, `branchRotation`, scale, `sourceChart`), labelled with the A4 selected corner face (`cell.corners[c].face` topology key).
   - It is placement provenance only, with builder-specific branch meaning; the periodic builder leaves it `0`.
   - No A5/A6/A7 rule may read it as the branch of any wedge face.
3. Transitional class key = region + complete ordered binding signatures + lattice coordinate + scale + labelled placement provenance `(selected-face topology, branchRotation, sourceChart)`. Representative key = exact support + binding signatures + `OccurrenceId`.
4. "No mixed-face record" means every face-dependent value is published together with the face it is expressed in. Pairing the selected face's `sourceChart` with another face's topology is forbidden.
5. Stop rule: any A5/A6/A7 consumer needing a wedge-face branch returns CB4 to Review. That consumer would trigger an A4 product amendment to publish per-face branch authority. That amendment is rejected for now: no consumer needs it, and the builders have no uniform meaning for the branch.

## RA-12 — site-qualified isolation-failure diagnostics (normative, 2026-09-25, `M6-CP1-TB4-REV` review-agent addendum)

This amends RA-7. The legacy M5 names `MissingIsolationSeamEquivalenceAuthority` and `InvalidIsolationSeamEquivalenceAuthority` are kept as **prefixes**, and each emission site appends a stable suffix:
- `:a5-wedge` / `:a5-side` — A5 `MissingIsolationEvidence` / `MismatchedIsolationEvidence`, raised during wedge-fan or side traversal;
- `:a6-side-evidence` — ordered whole-side evidence certificate lookup;
- `:a6-collinear-span` — collinear endpoint span with no certificate;
- `:a6-seam-span-transition` — seam branch missing the reciprocal span transition;
- `:a6-seam-faces` — certificate faces or sheets mismatch.

Diagnostic only: predicates, ordering and outcomes are unchanged. No test or production code compares these strings exactly (verified at `M6-CP1-TB4-REV`). Rationale: `M6_Consolidated_Record.md` §§19-20; full retired Review text is resolved by that record's folded-document index.

**RA-12 annotation (`M6-CP1-TB5-REV` review-agent addendum):** after CB5, an uncertified collinear span runs the non-seam P2 rule and fails as `QuotientReciprocalSideAuthorityMismatch`. The `:a6-collinear-span` suffix is therefore never emitted. The other suffixes are live.

## CP1 exit scope — restated (`M6-CP1-TB5-REV` review-agent addendum; no new semantics)

M6-CP1 cannot close until, on exact source plus a fresh green gate, all of the following hold:
1. The A5 product is conformant (§3), including retirement of the unread legacy `SurfaceOccurrence` `isolationSheet` / `chart` / `lattice`.
2. The A6 `SurfaceQuotientProduct` exists with member-set `QuotientClassId` (§4.3), one `QuotientRelationCertificate` and one ledger row per owned relation (§4.4), and `QuotientCertificate` / `MaterializationCertificate` (§4.6).
3. The A7 `SourceAttachedGeometryProduct` exists with its certificates (§5).
4. `build_authoritative_phase_front_mesh` is a thin adapter with no semantic decision (§10).
5. The `G4-B002` A6 stage boundary exists (§8.1).
6. There is no coordinate/position weld, and the focused multi-isolation identity is green (§10).

`M6-DEFN-R3` freezes the representation and sequencing decisions for items 2-5.

## M6-DEFN-R3 A6 quotient-product amendment (2026-09-25, runtime-free)

`M6-DEFN-R3` completes the bounded A6 decisions required before quotient extraction. Normative detail and rationale are in `Architecture_M6_DEFN_R3_A6_Product_Separation_Definition_Record.md`; where the points below conflict with the earlier conceptual A6 wording or RA-10, these govern.

- **CP1 exit checklist:** CP1 requires conformant A5 (including retirement of unread `chart/lattice/isolationSheet`), a complete immutable A6 product, later A7 product, thin adapter, no coordinate/position weld, the later `G4-B002` A6 boundary, focused multi-isolation preservation, and a fresh selector449 449/449 gate.
- **Semantic class identity:** A6 uses `pipeline::SurfaceQuotientClassId`, exactly the sorted unique non-empty member `OccurrenceId` vector. Equality and order are member-set semantic; no root/hash/support/lattice/chart/row/position/representative participates. `authority::QuotientClassId` remains an adapter-only ordinal assigned after lexicographic member-set sorting for legacy lineage projection.
- **Exact-once:** every A5-owned relation produces exactly one `QuotientRelationCertificate` and one `QuotientRelationConsumption` row. Disposition is `Joining` or `CycleClosing`; already-connected relations are never skipped.
- **[SUPERSEDED by RA-13 (2026-10-02 review-agent addendum; see end of document) — the residual fallback is revoked and the strict rule restored]** **Transport consistency (amended by TB6-A6 Review):** relation certificates carry one exact relation-oriented `GridAutomorphism`. Joining relations form the deterministic selected relation forest. For a cycle-closing relation, let direct canonical transport be `D : a -> b` and the exact composed selected-forest path transport be `P : a -> b`; publish the exact residual `H = compose(P.inverse(), D)`. `H == identity` is a valid observed case, **not** a universal acceptance precondition. A non-identity residual is exact holonomy evidence unless an independently frozen contract for that relation requires zero residual. `QuotientHolonomyConflict` is reserved for algebraically inconsistent direct/path/residual evidence or violation of such an explicit zero-residual obligation.
- **[SUPERSEDED by RA-13 (2026-10-02 review-agent addendum; see end of document) — the residual fallback is revoked and the strict rule restored]** **Analytical/runtime scope:** the split square, uniform hard-rail rectangle and ordinary-identity classes remain analytically identity-residual cases. Produced cylinder row232 and torus rows444/446/448/449 were pre-registered TB falsifiers. TB6-A6 selector446 plus focused pair-swap row6 triggered the documented fallback while 232/444/448/449 stayed green, proving the universal equality rule too strict for the accepted nonzero-Z4 periodic witness. This Review-authorized amendment preserves exact relation authority and changes only the treatment of cycle residual holonomy.
- **Selected paths:** selection is A6 authority. Each class roots evidence at its smallest semantic member; unique forest paths store ordered relation certificates, orientation, relation-local binding evidence and composed transport. A7 may project but not reselect. Legacy `selectedRelationPaths` projection remains limited to paths containing HardRail/Periodic selected steps, preserving split-square emptiness.
- **A6 errors:** semantic enum names are `SourceAuthorityMismatch`, `RelationEndpointMissing`, `RelationAuthorityConflict`, `RelationCertificateMissing`, `RelationCertificateDuplicate`, `RelationCertificateConflict`, `ReciprocalSideAuthorityMismatch`, `MissingIsolationEvidence`, `InvalidIsolationEvidence`, `InvalidHardRailTransport`, `InvalidPeriodicTransport`, `UnsupportedSingularityPort`, `UnownedRelationUse`, `RelationConsumptionMissing`, `RelationConsumptionDuplicate`, `RelationConsumptionConflict`, `HolonomyConflict`, `InvalidClassPartition`, `MissingOccurrenceMember`, `DegenerateClassedQuad`, `NonBijectiveMaterialization`. External A6 diagnostics use `Quotient` prefix; legacy-name mapping is adapter-only where frozen accepted behavior requires it, including RA-12 isolation prefixes.
- **First A6 CB:** after mandatory `M6-DEFN-R3-REV`, `M6-CP1-CB6-A6` extracts A6 and folds in the legacy A5 field retirement. Four new focused identities are frozen in its plan. Compile-green advances to an immutable gate of **11 focused + selector449 = 460** processes. The previous standalone legacy-field CB6 plan is superseded/held.
- **Deferred:** A7 product representation and the exact `G4-B002` A6 stage-boundary representation are owned by later `M6-DEFN-R4`; R3 records intent only and grants no implementation authorization for them.

Stable accounting remains **55 / 16 / 39**, produced-witness debt **1**, selector449/routing449 bytes unchanged. Exact successor is mandatory `M6-DEFN-R3-REV`; the A6 Code + Build remains held until Review.

## M6-DEFN-R3-REV A6 quotient-product review amendment (normative, 2026-09-25, runtime-free)

`M6-DEFN-R3` is **accepted with RA-1 – RA-4**. Where the R3 definition record or held A6 CB plan conflicts with these rules, these govern. Full evidence and rationale: `Architecture_M6_DEFN_R3_Review_Record.md`.

- **RA-1 — canonical relation-certificate direction.** Every `QuotientRelationCertificate` is oriented `relation.id.first -> relation.id.second`. The separately stored `relation.firstOccurrence` / `secondOccurrence` and `firstFrontEdge` / `secondFrontEdge` are representation provenance only and cannot determine semantic certificate direction. Any exact evidence obtained opposite the canonical direction is inverted before publication.
- **RA-2 — OrdinaryFront quotient transport.** Every accepted `OrdinaryFront` certificate has `GridAutomorphism::identity()` as its quotient relation transport. Checked isolation-seam quarter-turns remain source-chart/sheet validation evidence and are never reapplied as quotient transport.
- **RA-3 — A5 relation evidence completeness.** Frozen A6 still consumes A0 source authority plus one complete A5 occurrence complex. Therefore each A5-owned relation must carry/reference the immutable kind-specific evidence required to validate its RA-1 canonical transport without dereferencing representation-owned front-edge/global arrays. OrdinaryFront transport is identity; HardRail carries its exact accepted owner/route/transport; Periodic carries its exact semantic action plus required route/cut evidence; all non-identity evidence is normalized to canonical endpoint direction. This may enrich A5 relation evidence but may not change relation identity/equality/owner selection or the accepted relation set.
- **[SUPERSEDED by RA-13 (2026-10-02 review-agent addendum; see end of document) — the residual fallback is revoked and the strict rule restored]** **RA-4 — exact path-composition recurrence, with residual amendment.** Traverse from `a` to `b` with `path=identity`; for each certificate edge in traversal order choose its canonical transport or exact inverse according to traversal direction, then set `path=compose(T,path)`. For a cycle-closing relation publish that exact path transport together with the direct canonical transport and residual `H = compose(path.inverse(), direct)`. The path recurrence itself is unchanged.

### M6-CP1-TB6-A6-REV residual-holonomy and HardRail amendment (2026-09-29, runtime-free Review)

> **Residual-holonomy part SUPERSEDED by RA-13 (2026-10-02).** The HardRail reciprocity part below remains in force.

The pre-registered runtime falsifier fired. Mechanically valid TB6-A6 run `36362570974` executes all **11 + 449 = 460** processes and produces exactly four RED identities. Accepted selector446 plus focused pair-swap row6 fail only at `QuotientHolonomyConflict`, while cylinder232 and torus444/448/449 remain green. Review therefore invokes R3's evidence-only fallback: nonidentity `H` is preserved as exact cycle evidence rather than rejected merely for being nonidentity. A7 may later project this evidence but may not use it to change A6 quotient identity/topology. A6 must still prove every constituent certificate exactly matches immutable A5 relation authority in canonical relation direction; certificate tamper is not legitimized as residual holonomy.

The same gate exposes a separate accepted HardRail regression: selector139/142 unexpectedly succeed because A5 HardRail relation publication dropped the accepted reciprocal requirements `first.sourceTopologyRegion != second.sourceTopologyRegion` and `first.route == second.route.reversed()`. **That semantic guard remains frozen.** It belongs at A5 publication before relation evidence becomes immutable and continues to map to accepted `InvalidHardRailTransport`. A6 validates the published certificate against A5 authority; it does not become a duplicate relation-owner.

`M6-CP1-TB6-A6-REV` classifies selector446 as one stable `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION` recurrence and rows139+142 as one stable `VALIDATION_ORDER_SHADOWING` recurrence. Stable accounting is now **57 / 16 / 41**, debt **1**. Candidate `10896307843 / a532f803...` is rejected/unpromoted; reviewed runtime authority remains `10879581622 / 82b86a28...` under selector449 449/449. Exact next is bounded `M6-CP1-CB7-A6`, then a fresh **11 + 449 = 460** `M6-CP1-TB7-A6-EXEC` and mandatory Review. `M6-DEFN-R4`, A7 and `G4-B002` remain held.

## RA-13 — single-gauge relation transport; strict cycle rule restored (normative, 2026-10-02, `M6-CP1-TB6-A6-REV` review-agent addendum)

This supersedes the TB6-A6-REV residual-holonomy fallback. Rationale is preserved in `M6_Consolidated_Record.md` §§25/28 and lesson 184; the full retired Review text is resolved by the folded-document index.

1. **[Branch-matching mandate WITHDRAWN by RA-16 §1. `LocalLatticeState.branchRotation` is face-gauged, so cross-face branch comparison is valid only in a gauge A4 certifies.]** Every `QuotientRelationCertificate.relationTransport` is the transport between the endpoint occurrences' **placement (cut-domain `LocalLatticeState`) states**, in canonical `relation.id.first → second` direction. A5 publishes it in that gauge and verifies `action_matches(placement(first), placement(second), T)` (coordinate, branch, scale) before freezing the evidence. A mismatch fails closed with `InvalidPeriodicFrontTransport` or `InvalidHardRailTransport`.
2. **OrdinaryFront:** identity (RA-2).
   **Periodic, exact-A3:** `T = Γ_to⁻¹ ∘ g ∘ Γ_from`, with Γ derived from `make_periodic_relation_endpoint_state` as the single authority (Forward: identity in coordinates; Reverse: relation turn Q; branch normalization by `localFaceBranchRotation`). The semantic action `g` is in the PeriodicCut relation-endpoint gauge (`SurfaceCellTracing.h`, the note on `SurfacePeriodicRelationEndpointState`), which is a different authority domain from cut-domain placement (lesson 175).
   **Periodic, non-A3:** the existing cut-gauge action.
   **HardRail:** **[SUPERSEDED by RA-14 below]** the route composed transport, under the same placement check. The TB7 stop condition fired: the carrier route is not the placement-gauge authority.
3. **Strict cycle rule (RA-4):** a cycle-closing relation requires `relationTransport == pathTransport`, else `QuotientHolonomyConflict`. The failure string may carry the residual for diagnosis (`QuotientHolonomyConflict:residual=Q<k>,t=(x,y)`). Non-identity residuals are never accepted as evidence in CP1. A vertex-class cycle is a contractible vertex link, and the legitimate exception (cone singularity at a lattice node) is excluded because A5 fails closed on SingularityPort corners.
4. **[Selector446 prediction corrected by RA-16 §3: 446 also pins the M5 lineage relation value, which RA-13 never authorized changing.]** **Falsifiers (TB7):** selector 446 and focused 6 (nonzero-Z4 witness) PASS under the strict rule; rows 232/444/448/449 stay green. A remaining conflict is classified from its residual suffix by Review. The fallback may return only with a proof of genuine vertex cone holonomy.



## RA-14 — HardRail carrier route and placement transport are separate authorities (normative, 2026-10-03, `M6-CP1-TB7-A6-REV`)

This supersedes only RA-13 item 2's HardRail transport sentence. OrdinaryFront, exact-A3/non-A3 Periodic transport and RA-13 strict cycle equality remain unchanged. Rationale: `Architecture_M6_CP1_TB7_A6_Review_Record.md` §§3-3.3.

1. `PureQuadEquivalenceProvenance.route` is HardRail carrier/topology/transition provenance. Its structural validity, hard-feature ownership and exact reciprocal reversal remain required, but `route.composed_transport()` is not quotient placement authority merely because the route owns the carrier.
**[Items 2-5 SUPERSEDED by RA-16 §2-§3 (review-agent addendum). The branch-derived `R` is face-gauge dependent; publishing the placement map in `equivalence.action` or the selected step rewrites the M5 lineage contract. Items 1 and 6 stand.]**

2. HardRail `canonicalTransport` is the unique cut-domain `LocalLatticeState` transform in canonical relation direction. For placement states `a -> b`, require equal scale, derive `R = branch(b) ∘ branch(a)^-1`, `t = b.coord - rotate(R,a.coord)`, construct `T={R,t}`, and verify the existing exact `action_matches(a,b,T)`.
3. A HardRail relation independently derives this transform for both cross-endpoint pairs (`first.from -> second.to` and `first.to -> second.from`) and requires the two exact transforms to be equal. Any missing/unequal value rejects `InvalidHardRailTransport`.
4. A5 publishes that placement transform in `equivalence.action`, `canonicalTransport` and the canonical selected step while retaining `equivalence.route` separately. A6 consumes that A5 placement transform unchanged.
5. Completion/lineage validates HardRail selected-step transport against orientation-adjusted `equivalence.action`; it continues to validate the retained route independently for source hard-feature topology/components. A consumer may not substitute route-composed carrier transport for placement transport.
6. **Stop rule:** if the two endpoint pairs do not define one unique placement transform, or another current consumer requires route-composed transport to remain quotient placement authority, stop for Review rather than relaxing the endpoint check.

## RA-15 — individual route authority precedes relation-pair reciprocity (normative, 2026-10-03, `M6-CP1-TB7-A6-REV`)

Rows227/230 prove that a malformed individual HardRail route must retain its accepted `InvalidHardRailAuthority` diagnostic instead of being pre-empted by pair-level `InvalidHardRailTransport`.

1. The existing exact individual interior-route/source-transition validator is a single shared predicate and runs before A5 relation-pair publication. **[Location pinned by RA-16 §5: inside A5, not an adapter preflight.]**
2. Malformed HardRail route authority preserves `InvalidHardRailAuthority`; malformed Periodic route/cut authority preserves its existing `InvalidPeriodicCutAuthority` path.
3. Only individually valid routes reach A5 pair-level owner/region/reversed-route checks. Those pair-level failures remain `InvalidHardRailTransport` (including selector139/142).
4. Do not duplicate divergent route-validity semantics downstream; move/extract/reuse the existing predicate and remove or mechanically reuse the later copy.

**[Superseded by the RA-16 accounting line below.]** Stable accounting after TB7 Review is **59 / 16 / 43**, debt **1**. Candidate `11257522199 / 40842caa...` is rejected/unpromoted. Exact successor is `M6-CP1-CB8-A6`, then immutable `M6-CP1-TB8-A6-EXEC` **11+449=460** and mandatory Review.

## RA-16 — placement transport is a lattice-coordinate automorphism; the lineage relation value is a separate authority (normative, 2026-10-03, `M6-CP1-TB7-A6-REV` review-agent addendum)

**What this changes.**
- Supersedes RA-14 items 2-5.
- Withdraws the branch-matching mandate in RA-13 item 1.
- Locates RA-15 item 1.
- Still stand: RA-13 items 2 (OrdinaryFront, Periodic) and 3 (strict cycle rule); RA-14 items 1 and 6; RA-15 items 2-4.
- Rationale: `Architecture_M6_CP1_TB7_A6_Review_Record.md`, review-agent addendum §G2-§G6.

1. **Gauge rule.**
   - `LocalLatticeState.branchRotation` is face-gauged. It equals `faceBranchRotation[selected source face]` (propagated per region from that region's own root) plus the region chart branch (`SurfaceCellTracing.cpp:12094`, `:16324`, `:14920-14985`).
   - A5 must never derive or check a lattice rotation from the branch difference of two states whose selected source faces may differ, unless the comparison is in a gauge A4 certifies:
     - exact-A3 Periodic → the relation-endpoint gauge (published `SurfacePeriodicRelationEndpointState`);
     - non-A3 Periodic → the legacy A4 placement check;
     - HardRail → none in CP1, because A4 certifies no lattice relation across a rail.
2. **HardRail placement transport is coordinate-rigid.**
   - Source states: use the endpoint occurrences' `placement.lattice`, i.e. the cell corner states the relation unites. Do not use the `SurfaceFrontEdge` copies.
   - Pairing: `first.from → second.to` and `first.to → second.from`. Write `c(·)` for a lattice coordinate.
   - Checks and derivation:
     - all four `scaleLevel`s are equal;
     - `e = c(first.to) − c(first.from)` is nonzero;
     - `e' = c(second.from) − c(second.to)`;
     - `R` is the unique `QuarterTurn` with `rotate(R, e) == e'`. If none exists, fail `HardRailTransportMismatch` → `InvalidHardRailTransport`;
     - `t = c(second.to) − rotate(R, c(first.from))`;
     - `T = {R, t}`; verify `T` maps both coordinate pairs.
   - No branch comparison.
   - Publish `T`, in canonical direction, **only** as `canonicalTransport`. On every constant-field fixture this equals RA-14's map, since `τ = 0` and both are the unique rigid map.
3. **The lineage relation value is decoupled.**
   - A5 publishes `canonicalRelationValue` for each relation, in canonical direction:
     - OrdinaryFront: identity;
     - HardRail: `route.composed_transport()`;
     - exact-A3 Periodic: the semantic `g`, oriented `firstIsForward ? g : g⁻¹`;
     - non-A3 Periodic: the existing selected action.
   - `canonicalSelectedStep.appliedTransport = canonicalRelationValue`.
   - `equivalence.action`, `route` and `cutRoute` stay as in M5.
   - A6's HardRail/Periodic certificate checks compare the step's `appliedTransport` with `canonicalRelationValue`. `relationTransport = canonicalTransport`, which keeps the RA-13 strict cycle rule in the placement gauge.
   - The lineage selected-path projection must equal the pre-RA-13 projection on every accepted row.
   - The `PureQuadCompletion` relation-value checks (`:1086-1132`) and selector446 stay unchanged and must PASS.
4. **Exact-A3 Periodic stays as CB7 built it in CP1.**
   - CB7's derivation equals `rot(Q)⁻¹ ∘ g`, with `Q = g.rotation` by A4 convention, whenever it accepts.
   - Replacing its face-gauged final check with coordinate plus relation-gauge checks is an **[owner moved by RA-17 to `M6-DEFN-R5`]** obligation. It requires a witness whose corresponding corners have unequal face gauges.
5. **Location of route validity (RA-15 item 1).**
   - One extracted free predicate, derived from `exact_interior_route_valid`.
   - A5 applies it to both HardRail sides before any pair predicate. Failure code: `HardRailRouteAuthorityInvalid` → `InvalidHardRailAuthority`.
   - The adapter reuses the same function for unpaired and exterior edges. No adapter-wide preflight.
   - Exact-A3 periodic routes are already rejected upstream by A4 (`SurfaceCellTracing.cpp:8218-8225`).
6. **Falsifiers.**
   - Selector446 unchanged, PASS.
   - Selector115 (production completion-ownership check on a HardRail fixture), PASS.
   - New focused identity 12, `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` (CB8 plan amendment).
   - TB8 gate: **12 + 449 = 461**.
7. **Stop rules.** Stop for Review if:
   - an accepted fixture pair has no unique `R`;
   - decoupling would require changing `PureQuadCompletion.cpp`, selector446, `equivalence.action`/`route`, or the lineage relation values;
   - A4 visibly rejects the focused-12 relabelled draft.

Stable accounting after the TB7 Review addendum is **60 / 16 / 44**, debt **1**. The extra event is TB7 CAND-03, reclassified as a stable `RP-01` lineage-contract regression. Exact successor: `M6-CP1-CB8-A6` as amended → `M6-CP1-TB8-A6-EXEC` (**12+449=461**) → mandatory `M6-CP1-TB8-A6-REV`.

## RA-17 — transport guard; bounded R4; gauge obligations owned by `M6-DEFN-R5` (normative, 2026-10-03, `M6-CP1-TB8-A6-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB8_A6_Review_Record.md`, addendum §H2-§H3.

1. **Promotion.**
   - `M6-CP1-TB8-A6-EXEC` proves RA-16 recovery at **461/461**: focused 1-12 + selector449.
   - Candidate `11265967968 / 8e0818b1e2f8d12b86c64d8774a3572c5ed5266c` is the reviewed M6 runtime authority.
   - `Architecture_M6_CP1_Required_Green_Focused_12.txt` (SHA-256 `59a523ae2039e0cb537cee550aab6e54936353b8a60234a3915049dc0c3d571c`) becomes a required-green prefix of every later M6 gate, alongside selector449.
2. **Transport guard.**
   - A6 `canonicalTransport` / `QuotientRelationCertificate.relationTransport` has exactly one consumer: the strict cycle rule.
   - A7, the adapter, lineage, chart re-anchoring and completion must not consume it.
   - Lineage selected steps carry `canonicalRelationValue` (RA-16 §3).
   - A7 embeds from exact A5 source support only (§5).
   - A future consumer of placement transport requires a Definition amendment that first discharges item 4's obligations.
3. **Bounded R4.** `M6-DEFN-R4` decides only:
   - A7 representation and certificates, including an exact `SourceSupport` incidence predicate that replaces the adapter's epsilon position check as authority;
   - the thin-adapter classification of all 55 failure sites;
   - the `G4-B002` A6 boundary and its CP1 equivalence demonstration;
   - the consumer/frozen-assertion census;
   - CB sequencing.

   The full scope is in the R4 plan. The first A7 CB must register `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`.
4. **`M6-DEFN-R5` (CP3-entry gate) owns RA-16 §4 and the TB7 addendum §G5:**
   - the periodic unequal-face-gauge witness, plus the coordinate / relation-gauge rule;
   - HardRail cross-region branch certification;
   - OrdinaryFront coordinate identity across isolation seams.

   These do not block CP1 closure, because item 2's guard keeps them away from geometry. They must close before any CP3 direct-production TB.

Stable accounting **60 / 16 / 44**, debt 1. Exact next: `M6-DEFN-R4` → mandatory `M6-DEFN-R4-REV`.

## M6-DEFN-R4 A7 / thin-adapter / `G4-B002` boundary amendment (2026-10-03, runtime-free; **REVIEWED by `M6-DEFN-R4-REV`: accepted with RA-18 – RA-21, below**)

`M6-DEFN-R4` freezes the remaining CP1 product-boundary definitions. Full normative detail and rationale are in `Architecture_M6_DEFN_R4_A7_Boundary_Definition_Record.md`. This amendment is Definition authority but remains **HELD FOR `M6-DEFN-R4-REV`** before implementation.

1. **[Amended by RA-18: the support certificate adds a fail-closed same-simplex point-coincidence validation.]** **A7 is an immutable stage product.** `SourceAttachedGeometryProduct` publishes exactly one source-attached vertex per A6 `SurfaceQuotientClassId`, copies A6 classed-cell topology unchanged, and certifies class bijection, topology copy, complete support and no placement-transport consumption. Exact `SourceSupport` typed identity + source-face incidence replaces the adapter's `1e-9` position comparison as semantic authority. Cross-kind coercion is forbidden. The deterministic representation-only representative remains the lexicographic minimum of `(support, cornerWedgeBindings, OccurrenceId)`; it supplies compatibility point/position only, never semantic quotient identity.
2. **A7 lineage is class-wide A5/A6 authority.** Occurrence members, charts, wedge-union isolation sheets, topology regions, equivalences and selected paths are projected from immutable A5/A6 evidence. Selected relation steps retain `canonicalRelationValue`; A7 never consumes `canonicalTransport` / `relationTransport` for geometry, lineage, chart re-anchoring or completion input. No new A7 metadata enters existing completion/quality hashes.
3. **[Amended by RA-19: placement of moved checks inside A5; identity 24 made behavioral.]** **The legacy materializer becomes thin.** `build_authoritative_phase_front_mesh` may invoke A5/A6/A7, map already-produced typed errors and serialize immutable products. It may not perform semantic predicates, topology/quotient/support/representative selection, relation search, floating tolerance checks, welds or repair. The current 55 literal failure sites are partitioned **31 A5 + 4 A6 projection + 19 A7 + 1 serialization**; stage precedence is A5 -> A6 -> A7 -> serialization, preserving frozen `FalseAuthoritativeSourceBoundary`, `InvalidHardRailAuthority` and `InvalidHardRailTransport` behavior.
4. **[Amended by RA-20: protection comes from source hard-feature authority, not relation kind.]** **A6 owns a closed-complex candidate boundary.** `SurfaceQuotientClosedComplexView` is derived during A6 from A5/A6 authority, with member-set quotient vertices, classed quads, side-incidence edge identity, exact HardRail/Periodic owner labels and topology-derived opposite-edge strip identity. Candidate extraction consumes this boundary without `SurfaceCellPipelineContext::hasArrangement`; HardRail is protected, Periodic is an interior quotient seam, and no coordinate/hash equality defines identity.
5. **[Amended by RA-21: executable key path and stop rule. The torus's 18 user hard edges are carried by PeriodicCut relations, not A5 `HardRail` relations.]** **`G4-B002` CP1 mechanism proof.** On the existing produced closed torus fixture (`milestone-g/torus.obj` + `.rawfield`, same 18 HardRails), CB11 proves labeled combinatorial isomorphism to retained comparison authority: quad/edge incidence, exact HardRail/Periodic labels and sorted occurrence-member vertex lineage, all without positional matching. An independent candidate oracle proves one eligible path/loop candidate and a mechanism-only HardRail tamper removes that exact candidate. This **does not close the debt**; M6-CP3 retains the unchanged direct-production eligibility + hard-feature tamper proof.
6. **Frozen implementation sequence after R4 Review:** CB9 A7 (focused 13-20; gate **20+449=469**), TB9 + Review; CB10 A5-validation migration (focused 21-24; **24+449=473**), TB10 + Review; CB11 G4 boundary (focused 25-28; **28+449=477**), TB11 + Review; then `M6-CP1-CLOSE-REV`. The first A7 CB includes `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` executing the real production completion-ownership validator. Each successor focused list preserves the frozen focused-12 bytes and preceding list as an exact prefix; selector449 remains unchanged.
7. **R5 remains separate.** Unequal-face-gauge exact-A3 Periodic authority, HardRail cross-region branch certification and OrdinaryFront isolation-seam coordinate identity remain owned by `M6-DEFN-R5` as a CP3-entry gate. The RA-17 transport guard keeps them out of CP1 A7 geometry and the A6 closed-complex boundary.

Stable accounting remains **60 / 16 / 44**, produced-witness debt **1**. Exact successor from this Definition is mandatory `M6-DEFN-R4-REV`; no CB is authorized until that Review accepts or amends this record.

## RA-18 – RA-21 — `M6-DEFN-R4-REV` binding amendments (normative, 2026-10-03)

Rationale: `Architecture_M6_DEFN_R4_Review_Record.md` §2 (F1–F5).

### RA-18 — support authority and a reject-only point-coincidence guard (amends R4 D1 §2.2; supersedes RA-17 §3's "diagnostic only" wording for the old check)

1. **Authority.**
   - `SourceSupportCertificate.publishedSupport` and every member comparison use the A5 value `SurfaceOccurrence::support` only.
   - A7 never re-resolves support from a point.
   - A5's resolver barycentric tolerance (`SurfacePointSourceSupportResolver`, `1e-8`) is the single floating classification in the support chain, and it is A5-owned.
   - Typed equality and face incidence are exactly as R4 D1 §2.2 states, with no cross-kind coercion.
2. **Reject-only coincidence guard.** After typed equality holds, A7 checks that every member denotes the same point **in that simplex's own coordinates**:
   - vertex support: trivially the same point;
   - edge support `{a,b}` with canonical `a < b`: `t(o) = β_b / (β_a + β_b)`, computed from the member's own face barycentrics. All members must satisfy `|t(o) − t(rep)| ≤ τ`;
   - face-interior support `{f}`: the members' barycentrics in face `f` must agree per component within `τ`.

   `τ` is the A5 resolver barycentric tolerance (dimensionless). A violation fails closed with `SourceSupportPointMismatch` (`:support-point`).
3. **What the guard may do.** It may only **reject**. It never accepts, merges, splits, selects a representative or support, alters lineage, or sets a positive certificate bit. This is validation, not the recovery that §5.3 forbids.
4. **Replacement.** It replaces the adapter's `1e-9` relative position check (`QuotientGeometryConsistencyFailure`). The old check is removed only in the same Code + Build that installs this guard.
5. **Test identity.** Identity 15 becomes `M6CP1.A7RejectsSupportKindIdentityAndSameSimplexPointMismatches`. It adds two negatives that the typed rule alone would accept:
   - same edge support at different parameters;
   - same face support at different barycentrics.

### RA-19 — where moved validation goes inside A5, and identity 24 (amends R4 D2 §3.4 and D5 §5.2)

1. **Placement.** Category-(a) checks moved into A5 run **after every check A5 performs today**, in their current relative order, including the per-edge loop order. This preserves the observable precedence for rows 212, 227/230 and 139/140/142.
2. **Placement exception.** A moved check may run earlier only if the CB10 report shows, for each required test that can reach both checks, that the outcome is unchanged.
3. **Identity 24** becomes `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts`.
   - On at least the hard-rail, split-isolation and produced-torus fixtures, the adapter's mesh, provenance and lineage must equal an independent test-side serialization of the A5/A6/A7 products.
   - A stage-valid input must never be rejected by the adapter.
4. **Static check, not a test.** The rule "no semantic literal or tolerance in the adapter" is a static Code + Build / Review check recorded in the CB10 report: failure assignments only inside typed-error mapping, and no floating-point literal comparison. It is not a gtest that reads source text.

### RA-20 — candidate protection comes from source hard-feature authority (amends R4 D3 §4.1–§4.3)

1. **Two independent attributes per quotient edge.**
   - (i) `relationKind`, which is Ordinary / HardRail / Periodic, derived from A6 certificates exactly as R4 §4.2 states.
   - (ii) `hardFeatureProtected`, derived from **typed source hard-feature authority**: the authoritative HardFeature rail-edge set that production passes to completion as `hardFeatureRailEdges`. It must be supplied to A6 boundary construction as an explicit typed input.
   - An edge is protected iff every carrier route step lies in that set.
2. **Consistency.** A `HardRail` edge must be protected; a mismatch fails closed. A `Periodic` edge whose cut carrier lies on hard-feature edges **is protected**.
3. **Candidate extraction** maps `hardFeatureProtected` to `touchesHardFeature`, never `relationKind`.
4. **Barrier set.** The boundary must not reuse A5's chart-barrier set. That set is built from HardRail front routes only (`RemeshPipeline.cpp:3323-3331`). Whether that asymmetry matters for A5 charts is a recorded `M6-DEFN-R5` census item.
5. **Fixture correction.** On the produced torus, all 18 user hard edges are carried by PeriodicCut relations, because the torus is one region and A5 HardRail requires distinct regions. They must come out protected.

### RA-21 — an executable equivalence oracle, with a stop rule (amends R4 D3 §4.4)

1. **Key path.** Before writing identity 25, the CB11 author must establish statically, and record in the CB11 report, the map from arrangement halfedge `(proposalId, proposalSide)` via `network.proposals[proposalId]` to A4 `CellId` and side.
   - Arrangement nodes carry no occurrence members.
   - The vertex bijection is therefore induced from quad and side incidence through that map. A6-side member-set lineage is checked only on the A6 side (identity 27).
2. **Labels.** Compare `hardFeatureProtected` with the arrangement's `hardFeature`, and HardRail/Periodic owners where both sides publish them.
3. **Stop rule.** Stop for Review instead of weakening the oracle if any of these hold:
   - the map does not exist or is not injective;
   - the arrangement subdivides proposal cells (traced, non-proposal arcs);
   - the two complexes are not isomorphic.

   Review then chooses between a subdivision-equivalence oracle and a different comparison authority.
4. **No proximity matching.** Positions, epsilons and hashes still may not establish any bijection.

Gate sizes are unchanged: CB9 **20+449=469**, CB10 **24+449=473**, CB11 **28+449=477**. Stable accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB9-A7`.

## RA-22 — class-wide A7 completion destination authority (normative, `M6-CP1-TB9-A7-REV`, 2026-10-04)

Rationale and independent evidence: `Architecture_M6_CP1_TB9_A7_Review_Record.md`.

1. **Representative is not semantic destination authority.** When `PureQuadVertexLineage::sourceOccurrences` is nonempty, the lineage came from A7 occurrence-binding authority. `sourcePoint` remains compatibility/representation data only. Its face's topology region, isolation sheet and source component may not select or narrow relation-destination authority.
2. **Retained A7 sets are semantic authority.** `sourceCharts`, `sourceTopologyRegions` and `sourceIsolationSheets` are the complete class-wide A7 projections. A selected relation endpoint chart must be an exact retained chart; its region must be a retained region and its sheet must be a retained sheet. In particular, a destination sheet is **not** required to equal the representative face's sheet.
3. **Component is class-wide and singleton.** Completion derives the component set by resolving every retained A7 chart through `SourceChartTransitionGraph::source_component`. Every chart must resolve and the unique set must contain exactly one component; otherwise completion fails closed. A selected relation destination must belong to that singleton component.
4. **No semantic widening.** RA-22 authorizes no relation search, alternate path, endpoint substitution, chart rebind, tolerance weld, topology mutation or placement-transport consumption. Existing exact support, selected-path endpoint, path-continuity, relation-value and composed-transport checks remain unchanged.
5. **Legacy isolation.** Lineage with no A7 occurrence-binding authority (`sourceOccurrences.empty()`) keeps the established selected-face singleton closure. RA-22 changes only A7-lineage consumption.
6. **Recovery gate.** `M6-CP1-CB9-A7-R1` is limited to this completion integration seam. Its compile-green candidate must rerun the unchanged focused20 + selector449 = **469** artifact-only gate, then mandatory `M6-CP1-TB9-A7-R1-REV`. Focused-20, selector449, fixtures, A7 producer semantics and CB10/CB11 reserved identities remain frozen.

Stable accounting remains **60 / 16 / 44**, produced-witness debt **1**. CB9 candidate `11287202960 / b8d27b63...` is rejected/unpromoted; reviewed runtime remains TB8 `11265967968 / 8e0818b1...` until recovery Review.

## RA-22a — site-qualified completion diagnostics, and A7 gaps recorded (normative, 2026-10-04, `M6-CP1-TB9-A7-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB9_A7_Review_Record.md`, addendum §H2–§H4.

1. **Operative clause.** The TB9 failure is deduced statically: on the witness, the false clause is `candidateSheet != selectedSheet`. The end chart's resolution, region membership and component equality are all already enforced before the predicate.
   - RA-22 item 4 (sheet membership in the retained A7 sheets) is the operative repair.
   - Items 3 and 5 are kept as fail-closed restatements.
2. **Diagnostics.** R1 must suffix `CompletionOwnershipInvalidSelectedRelationDestination` by subclause: `:dest-unresolved`, `:dest-region`, `:dest-sheet` or `:dest-component`. The RA-22 item 5 failure is emitted as `CompletionOwnershipInvalidRetainedSourceAuthority:component-singleton`. No test or production code compares these strings exactly. No predicate changes.
3. **Recorded A7 gap — cross-sheet proxy (owner: `M6-CP1-CLOSE-REV`).**
   - A7's `UncertifiedCrossSheetBinding` accepts a crossing if *any* isolation evidence exists on the relation, or *any* `cornerWedgeIsolation` exists on either occurrence. It does not check that the evidence connects the two sheets crossed.
   - Before CP1 closes, the check must either become exact, or be removed with the certificate stating that A6 is the cross-sheet certifier. `relationEvidenceSufficient` must not claim more than is checked.
4. **Recorded A7 gap — `τ` single-sourced (owner: `M6-CP1-CB10-A5V`).** A5 support classification and the A7 point guard must read one shared tolerance constant or accessor. Today each builds its own default resolver.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB9-A7-R1`.

## RA-22b — the representative-face consistency guard stays, reject-only (normative, 2026-10-04, `M6-CP1-TB9-A7-R1-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB9_A7_R1_Review_Record.md`, addendum §I2–§I4.

1. **Restore the guard.** For A7 lineage (`sourceOccurrences` non-empty), completion requires `region_for_row(sourcePoint.face) ∈ sourceTopologyRegions` and `sheet_for_row(sourcePoint.face) ∈ sourceIsolationSheets`. Failure is `CompletionOwnershipInvalidRetainedSourceAuthority:representative-face`.
2. **It only rejects.** It never decides destination, component, chart or lineage; RA-22 item 1 is unchanged. R1 (`584f80fe`) removed it without authorization.
3. **Why this is safe.** All 469 TB9 processes on pre-R1 source satisfied it, so restoring it is gate-neutral.
4. **Owner and test.** Owner: `M6-CP1-CB10-A5V` Goal T2. Focused 20's body gains a negative: drop the representative face's sheet from a multi-sheet A7 vertex's `sourceIsolationSheets` and expect the `:representative-face` code. The identity name and the focused-20 list are unchanged.
5. **Audit obligation (owner: `M6-CP1-CLOSE-REV`).** Every remaining consumer that reads a `sourcePoint` or `vertexProvenance` face is classified as class-wide, representation-only or anchor-assuming:
   - final validator `resolve_compatible_chart`;
   - `project_surface_cell_vertex_chart_authority`;
   - optimizer source-point rebinding;
   - `BenchmarkQuality`.

   Any anchor-assuming consumer blocks CP1 closure.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB10-A5V`.

## RA-19a — after the reorder, moved checks bind to the published A5 complex; identity 24's exact oracle (normative, 2026-10-04, `M6-CP1-TB10-A5V-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB10_A5V_Review_Record.md`, addendum §J2–§J3.

1. **Binding.**
   - The category-(a) helper runs only after `publish_records_for_validation` has returned a valid `SurfaceOccurrenceComplex`, and it validates against that published complex.
   - The side-count predicate is `edgeByCellSide.size() == complex.certificate().directedSideCount`, with every `complex.cells()` side mapped, as before CB10.
   - The 28 other moved predicates stay verbatim; the normalized-diff verification is in §J2.
2. **Identity 24's oracle** is the exact field table in §J3.
   - In-contract fields are compared exactly against values derived from the stage products, or against fixed compatibility constants.
   - All other fields are compared against their defaults.
   - Discovering any other adapter-written field is a stop for Review.
3. **Recorded for `M6-CP1-CLOSE-REV` (not blocking).** CB10 merged three unpinned legacy literals into existing A5 codes (§J2 item 3). Two distinct causes now share `OccurrenceSourceAuthorityMismatch`; this is a lesson-181 diagnosability loss to resolve at CP1 close.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB10-A5V-R1`.

## RA-21b — the CB11 migration oracle is a provenance-chain, subdivision-equivalence check (normative, 2026-10-04, `M6-CP1-TB10-A5V-R1-REV` review-agent addendum; amends RA-21 items 1 and 3)

Rationale: `Architecture_M6_CP1_TB10_A5V_R1_Review_Record.md`, addendum §K3.

1. **Positional preconditions.** These must be asserted in the test before any use:
   - `network.proposals.size() == phaseFront.cells().size()`;
   - for every row `r`: `proposals[r].corners == cells[r].corners` and `proposals[r].boundaryPaths == cells[r].boundaryPaths`.

   Then the key is `proposalId r` → `phaseFront.cells()[r].id`. The proposal carries no `CellId` by design, so the positional map is valid only under these preconditions.
2. **Key: provenance entries, not `halfedge.proposalId`.**
   - For each A4 cell row `r` and side `s`, the **side chain** is every arrangement halfedge whose `provenance` contains an entry `(proposalId=r, proposalSide=s)`, ordered by `(proposalBoundarySegment, sourceT0)`.
   - `halfedge.proposalId` holds only the primary entry and must not be used as the key.
3. **Equivalence up to degree-2 contraction.**
   - Every interior node of a side chain must have exactly two distinct incident undirected edges, both in that same chain.
   - Contracting each chain to a single edge must give a labelled combinatorial isomorphism with the A6 closed-complex view. Its vertices are the chain end nodes ↔ the A6 classes of the cell's corner occurrences, its quads are the proposal cycles ↔ the A6 classed quads, and its edges are the chains ↔ `SurfaceQuotientEdgeId`.
   - The two cells sharing an edge must contribute the same chain, in opposite orientation, through two provenance entries.
4. **Labels.** Every halfedge in a chain must carry the same `hardFeature` value, equal to the quotient edge's `hardFeatureProtected` (RA-20). Disagreement within a chain is a stop.
5. **Stop rule (RA-21 item 3, narrowed).** Stop for Review instead of weakening the oracle if any of these hold:
   - a positional precondition fails;
   - an arrangement halfedge has no proposal provenance (a seed trace, separatrix or inserted rail arc);
   - an interior chain node has degree other than 2;
   - two cells' chains for a shared edge differ;
   - a sliver or extra cell exists;
   - the contracted complexes are not isomorphic.
6. **Unchanged.** Positions, epsilons and hashes still establish no bijection. Production candidate extraction still consumes the A6 view directly, never the arrangement.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB11-G4`.

## RA-21c / RA-23 — TB11 Review corrections to the CB11 migration oracle and CP1 mechanism witness (normative, 2026-10-04)

Rationale: `Architecture_M6_CP1_TB11_G4_Review_Record.md` §§2-4. TB11 ordinal25 proved RA-21b wrongly equated quotient identity with physical arrangement identity across relation seams; ordinal28 proved the old arrangement `(family,strand)` non-vacuity result did not transfer to the new quotient opposite-edge strip model.

### RA-21c — per-occurrence/per-side subdivision witness

RA-21b items 2-5 are amended. The arrangement comparison is a per-proposal-side subdivision witness only. Each `(proposalId, proposalSide)` provenance chain must be degree-2 and each A4 corner occurrence must be the unique node intersection of its adjacent side chains. A6 edge pairing is then verified from exact phase-front `(filledCell,filledSide)` reciprocal `oppositeEdge` authority plus A5/A6 endpoint relations and typed owners. Occurrences in one quotient class need not map to one arrangement node, and the two incident sides of one quotient edge need not be the same arrangement chain. Each side's chain endpoints must match its own occurrence-node witnesses. Per-chain hard-feature consistency remains exact. Position/epsilon/hash matching remains forbidden. Any missing provenance, non-degree-2 chain, non-unique occurrence intersection, non-reciprocal side ownership, relation/owner disagreement, per-side endpoint disagreement, or extra/sliver cell is a stop for Review.

### RA-23 — CP1 produced-boundary checks versus mechanism non-vacuity

**[Amended by RA-24 (review-agent addendum). Item 2's synthetic torus is WITHDRAWN as the non-vacuity requirement, because the CB11 extractor emits nothing on any closed quad complex under rule 7. Identity 28's non-vacuity and tamper return to the produced torus under edge-loop strips. Item 1's universal checks stay, applied to the edge-loop reconstruction.]**

R4 §4.4 no longer infers quotient-strip non-vacuity from the retained arrangement candidate test. On the produced torus, identity28 independently reconstructs opposite-edge strip closure and validates every emitted candidate, but an empty candidate set is not itself a CP1 failure. Mechanism-only non-vacuity and hard-feature filtering are proved on a canonical test-side closed `4 x 4` toroidal A6 view with two-sided edges, valence-four vertices and independently derived strip ordinals. It must emit an independently eligible closed-loop candidate, and marking one exact candidate edge `hardFeatureProtected=true` must remove that exact candidate. This synthetic mechanism witness grants zero `G4-B002` debt credit; M6-CP3 retains the unchanged direct-production non-vacuity + hard-feature-tamper obligation. Focused identity names/order and focused28 list bytes remain unchanged.

**[R1 scope superseded by RA-24: one bounded production change to the A6 strip relation is authorized.]** Exact next after this Review is `M6-CP1-CB11-G4-R1`, test-authority recovery only; semantic A5/A6 product changes are not authorized. Compile-green R1 -> `M6-CP1-TB11-G4-R1-EXEC` 28+449=477 -> mandatory `M6-CP1-TB11-G4-R1-REV`. Accounting remains **60 / 16 / 44**, debt 1.

## RA-21d and RA-24 — `M6-CP1-TB11-G4-REV` review-agent corrections (normative, 2026-10-04)

Rationale: `Architecture_M6_CP1_TB11_G4_Review_Record.md`, addendum §L2–§L4.

### RA-24 — quotient strip identity is edge-loop (strand) closure (supersedes R4 D3 §4.3 rule 7)

1. **Continuation rule.** At every quotient vertex `v` that is interior (all incident edges two-sided) and has quotient valence 4, each incident edge `e` continues to `opposite_v(e)`: the unique other incident edge at `v` that shares no classed quad with `e`. Union `e` with `opposite_v(e)`.
   - Boundary vertices and vertices of valence other than 4 continue nothing; chains terminate there.
   - The rule is derived only from the view's quads and side incidence. No geometry, position or hash is used.
2. **`stripOrdinal`.** Each resulting class is an edge loop or edge path. `stripOrdinal` is its deterministic ordinal, ordered by smallest `SurfaceQuotientEdgeId` as before.
3. **Unchanged.** Candidate classification (path degree), protection (`hardFeatureProtected` / boundary / valence-singularity), side feasibility, labels and every A5/A6/A7 rule.
4. **Why.** The quad-opposite relation of rule 7 yields rung sets (matchings), so every strip with two or more rungs has all vertices at degree 1, and the classifier rejects it. The retired arrangement extractor used `(family, strand)` curves split into connected components, i.e. edge chains. Edge-loop closure is the topology-derived analogue it intended.
5. **Witness.** Identity 28 uses the produced torus:
   - **Non-vacuity:** require at least one independently eligible `ClosedLoop`. Expected: loops parallel to, but not on, the two hard cycles.
   - **Tamper:** mark one edge of that exact candidate `hardFeatureProtected=true`. It must become independently ineligible and absent from extraction.
   - **Universal checks:** independently reconstruct the edge-loop partition from `view.quads` and side incidence, require every `stripOrdinal` to match it, and independently validate every emitted candidate.
   - If the produced torus still has no eligible candidate under RA-24, stop for Review.
   - This is still CP1 mechanism evidence and grants zero `G4-B002` debt credit; CP3 keeps the direct-production requirement.
6. **Production scope.** Only the strip relation inside `build_surface_quotient_closed_complex_view` changes. The extractor and everything else stay as they are.

### RA-21d — keep physical identity where no barrier exists (amends RA-21c items 3 and 5)

1. **Ordinary edges.** For a quotient edge with `relationKind == Ordinary` whose endpoint relations carry no isolation transition, the two incident sides' chains must be the **same undirected arrangement edge set**, holding two opposite-orientation provenance entries.
2. **Ordinary-linked occurrences.** Two occurrences joined by such an `OrdinaryFront` relation must have the **same** occurrence-node witness.
3. **Where relaxation applies.** The RA-21c per-side relaxation applies only to HardRail edges, Periodic edges, and Ordinary edges carrying isolation transitions, and to occurrence pairs joined through them.
4. **Stop rule.** Any Ordinary non-isolation disagreement is a stop for Review. It would mean the arrangement splits outside barriers.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB11-G4-R1`, re-scoped.

## RA-25 — fail-closed strip continuation and CP1 close-out routing (normative, 2026-10-05, `M6-CP1-TB11-G4-R1-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB11_G4_R1_Review_Record.md`, addendum §N2–§N3.

1. **Fail-closed continuation.** At an interior valence-4 quotient vertex, if an incident edge does not have exactly one incident edge sharing no classed quad with it, `build_surface_quotient_closed_complex_view` fails closed with `ClosedComplexStripContinuationMismatch`. A silent skip is not permitted. This refines RA-24 item 1.
2. **Close-out routing.** The CP1 carried obligations are executed in `M6-CP1-CB12-CLOSE` (`Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md`), not in a runtime-free close Review:
   - exact A7 cross-sheet certification through `CornerWedgeIsolationTransition.fromSheet/toSheet`;
   - distinct A5 phase-front source diagnostics;
   - the `consumedInternalIsolationSeams` counter sourced from A5;
   - item 1;
   - the provenance-face consumer audit.
3. **Gate and sequence.** `M6-CP1-TB12-CLOSE-EXEC` runs focused-30 + selector449 = **479**, followed by `M6-CP1-TB12-CLOSE-REV`. Then `M6-CP1-CLOSE-REV` verifies the six CP1 exit items against exact source and that fresh gate, and that every RA-19a/RA-22a/RA-22b/RA-25 obligation is discharged.
4. **Stop rule.** Any anchor-assuming consumer found by the audit, or any C1 rejection of a previously accepted row, is a stop for Review.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB12-CLOSE`.

## RA-26 — provenance-face consumer classes; CB12 C5 stop discharged (normative, 2026-10-05, `M6-CP1-CB12-CLOSE-REV`; amends RA-22b §5 and RA-25 §2)

Rationale: `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md` §2–§4.

1. **Subject.** A provenance-face consumer reads the face of an A7 representative point: `PureQuadVertexLineage::sourcePoint.face`, `vertexProvenance[v].face`, or optimizer `provenance[v].face` derived from them. A site that reads only source-mesh incidence is not one.
   - So `make_surface_optimization_overlay` (`SurfaceMeshOptimizer.cpp:3015-3031`, test-only) is outside RA-22b §5. Its source-row-order scope choice is `M6-CP1-CB12-REV-OBS-01`, owner M8-CP2.
2. **Classes** (replaces "anchor-assuming" in RA-22b §5):
   - **Authority-deciding:** the anchor face decides destination, component, sheet or chart membership, lineage, topology, certificate content, or a membership/consistency verdict. **This class blocks CP1 closure.**
   - **Reference-selecting:** the anchor face selects a continuous reference (normal, field, projection scope) for an energy or a quality metric. Positions stay on the class-common support and no certificate changes. **This class does not block CP1.** It is owned by item 5.
3. **Binding C5 record.** Review record §3, 12 sites. No authority-deciding consumer exists. The reference-selecting sites are:
   - optimizer energy (`:1470-1485`, `:1505`) and gradient (`:1957-1965`, `:2001`, `:2124`), which take their normal/field reference from quad corner 0's representative face;
   - the final-validation field metric's empty-common-chart fallback (`:2675`), which projects within the first endpoint's anchor scope.
4. **CB12 routing.** C5 is discharged by item 3.
   - `M6-CP1-CB12-CLOSE-R1` (a new turn) executes CB12 plan C1–C4 and identities 29/30 unchanged.
   - It makes **no optimizer or final-validation change**.
   - Gate: focused-30 + selector449 = 479.
   - `M6-CP1-CLOSE-REV` re-verifies at its HEAD that no authority-deciding provenance-face consumer exists.
5. **Re-homed obligations** (owner `M6-DEFN-R5` to define; `M6-CP3` to discharge under its permutation-invariance exit):
   1. a class-wide quad reference for optimizer energy/gradient normal and field, for example the `resolve_compatible_chart` chart used by `quad_reference_surface_point`, with a cost bound under finite differences and line search;
   2. a class-wide fallback for the final-validation field metric (the quad's resolved chart faces instead of the first endpoint's anchor scope);
   3. replace the vacuous `project_vertices` component/sheet checks (`:820-:880`, which compare the anchor with itself on the authoritative path) with membership in the class's `vertexChartAuthority` sheets, or retire them to the M6-CP2 verifier;
   4. falsifier: one produced fixture under a source-face row permutation **and** an output quad corner rotation that changes at least one multi-sheet class's representative face and at least one quad's corner 0. Optimized positions, all validation metrics and acceptance must be invariant, under the equality DEFN-R5 freezes.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CB12-CLOSE-R1`.

## RA-27 — selected-cross-sheet witness recovery (normative, 2026-10-05, `M6-CP1-TB12-CLOSE-REV`)

Rationale: `Architecture_M6_CP1_TB12_Close_Review_Record.md`.

1. **CAND-01 classification.** Identity29's TB12 RED is a false rejection caused by a fixture-witness assumption. `split_isolation_fixture()` is not required to place a cross-sheet relation in A6's selected spanning forest. The absence of such an edge is not a production-selection defect.
2. **C1 remains exact.** For every selected-forest edge whose endpoint wedge-sheet sets are disjoint, A7 requires a relation/endpoint `CornerWedgeIsolationTransition` whose `fromSheet/toSheet` connects the two endpoint sets. Otherwise it fails `UncertifiedCrossSheetBinding` at `cross-sheet`. No production amendment is authorized.
3. **Recovery witness.** Identity29 must use a valid production-derived A6 product with a non-vacuous selected cross-sheet edge, prove baseline A7 acceptance, then disconnect all relevant transition sheet endpoints and prove the exact C1 rejection. A fabricated invalid quotient product or a test that never reaches the tamper is forbidden.
4. **Routing.** Exact next `M6-CP1-CB12-CLOSE-R2`, test-authority recovery only. Compile-green -> immutable `M6-CP1-TB12-CLOSE-R1-EXEC`, focused30 + selector449 = 479 -> mandatory `M6-CP1-TB12-CLOSE-R1-REV`. Only that Review may promote and release `M6-CP1-CLOSE-REV`.
5. **Stop rule.** Any required production semantic change, C1 weakening, selected-forest algorithm change, selector/routing change, or inability to construct a valid production-derived witness stops for Review.

Accounting remains **60 / 16 / 44**, debt 1.

## RA-27a — the reachable cross-sheet path is wedge-level; RA-27 §2–§3 withdrawn (normative, 2026-10-05, `M6-CP1-TB12-CLOSE-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB12_Close_Review_Record.md`, addendum §P3–§P7.

1. **CAND-01 cause (replaces RA-27 §1's reason).** `split_isolation_fixture()` has **no** relation with disjoint endpoint wedge-sheet sets. Its diagonal seam crosses cell interiors, so every sheet crossing happens inside a bridge occurrence (`|cornerWedgeSheets| = 2`). A disjoint-sheet relation can arise only from a front edge collinear with an isolation seam, and A6 already certifies that case exactly (`RemeshPipeline.cpp:5292-5310`). CAND-01 stays non-stable (+0).
2. **Exact wedge rule (production; completes RA-22a §3 / C1).** A7 certifies a class member with `|cornerWedgeSheets| > 1` only if this graph is connected:
   - vertices: the member's `cornerWedgeSheets`;
   - edges: `{fromSheet, toSheet}` from its own `cornerWedgeIsolation`, keeping only transitions with `region == topologyRegion` and both sheets in the set.

   Otherwise it fails `UncertifiedCrossSheetBinding` at site `cross-sheet:wedge`. This replaces the non-empty proxy (`:6884-6895`). The edge rule (site `cross-sheet`) is unchanged.
3. **C4 name.** `surface_quotient_product_error_name(ClosedComplexStripContinuationMismatch)` returns `"QuotientClosedComplexStripContinuationMismatch"`.
4. **Identity 29** (name and focused-30 position unchanged). On `split_isolation_fixture()`:
   1. assert a class member with ≥ 2 wedge sheets exists;
   2. baseline A7 accepts;
   3. rewrite only that member's `cornerWedgeIsolation` sheets to a pair that does not connect its set (keep the transitions non-empty);
   4. republish through `publish_records_for_validation`, then **re-produce A6 from the tampered A5** with `SurfaceQuotientProducer::produce` and assert success;
   5. assert that A7 on (tampered A5, re-produced A6) returns `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`.
5. **Consistent-chain rule.** Every stage-level negative feeds downstream stages products re-produced from the tampered upstream records. A stale downstream product is forbidden.
6. **Deferred.** The edge rule's executed falsifier waits for the first produced seam-collinear fixture (owner `M6-DEFN-R5` → `M6-CP3`). Hand-built relation records are forbidden.
7. **Observations.**
   - `M6-CP1-TB12-REV-OBS-01`: A6 → A5 certificate binding is missing; owner `M6-CP2` via `M6-DEFN-R5`.
   - `M6-CP1-TB12-REV-OBS-02`: the edge rule ignores relation kind while sheet IDs are global labels; owner `M6-DEFN-R5`.
8. **Stop rules.** Stop for Review if:
   - any previously accepted row fails;
   - A6 rejects the item 4 tamper;
   - item 2 needs any change beyond its text;
   - any selector449 / routing449 / focused-list byte changes.

Gate: focused-30 + selector449 = **479** → `M6-CP1-TB12-CLOSE-R1-EXEC` → `M6-CP1-TB12-CLOSE-R1-REV` → `M6-CP1-CLOSE-REV`. Accounting **60 / 16 / 44**, debt 1.

## RA-27b — runtime-proof scope, defensive-branch owners, CP1 close-plan amendments (normative, 2026-10-05, `M6-CP1-TB12-CLOSE-R1-REV` review-agent addendum)

Rationale: `Architecture_M6_CP1_TB12_Close_R1_Review_Record.md`, addendum §Q2–§Q6.

1. **Runtime-proof scope.** Identity 29 runtime-proves one dimension of the RA-27a wedge rule: transitions entirely outside the sheet set are rejected while the list stays non-empty. These conjuncts are **static-only**: the region filter, connectivity versus "touches the set", and multi-sheet partial connectivity. Records must not claim them as runtime-proved.
   - Owner of the missing tampers: the first `M6-CP2` Code + Build, as new appended identities. Identity 29 stays unchanged. Tracked as `M6-CP1-TB12-R1-REV-OBS-01`.
2. **Defensive branches.**
   - C4 `ClosedComplexStripContinuationMismatch` is reachable only through a weld-pinched vertex. Its executed falsifier is owned by `M6-CP2-DEFN`: a weld-constructed malformed-authority witness, with the verifier's manifoldness recompute.
   - C2's empty-front A5 branch is accepted as defensive and unreachable (A4 rejects empty fronts first).

   Neither blocks CP1, because both fail closed.
3. **CP1 close-plan amendments** (binding on `M6-CP1-CLOSE-REV`):
   1. Check the six exit items against the frozen text verbatim ("CP1 exit scope — restated", this document §CP1 exit scope), on exact HEAD source and the promoted 479/479 evidence.
   2. Classify every defensive or static-only branch introduced in CP1 (C2 empty-front, C4, RA-27a static conjuncts, RA-27a §6 edge rule) as accepted-defensive with a named later owner, or as CP1-blocking.
   3. `G4-B002` debt stays **open**. CP1 closure is mechanism-only, and debt stays 1.
   4. If CP1 closes, the exact successor is **`M6-CP2-DEFN`**. If it does not, route to the smallest Definition or Code + Build owner.
4. **`M6-CP2-DEFN` scope** (bounded, runtime-free; CP2 entry):
   - the `SurfaceProductVerifier` contract (frozen §6, §10): its typed failure matrix for the §6.3 malformed-authority classes, its §6.2 recompute set, and its identity/gate plan;
   - **OBS-01** (`M6-CP1-TB12-REV-OBS-01`): a certificate chain binding A6 → A5 and A7 → A6/A5, verified by payload equality;
   - **RA-26 §5(iii)**: retire or replace the vacuous `project_vertices` sheet check;
   - item 2's C4 witness and item 1's appended tampers.

   **`M6-DEFN-R5` stays the CP3-entry gate** and follows CP2. It keeps: the gauge obligations, the A5 barrier-set census, RA-26 §5(i)(ii)(iv), RA-27a §6 and `M6-CP1-TB12-REV-OBS-02`.
5. **Observation.** `M6-CP1-TB12-R1-REV-OBS-02`: the adapter drops A7's cross-sheet site (`RemeshPipeline.cpp:7462`); owner M8-CP2.

Accounting **60 / 16 / 44**, debt 1. Exact next: `M6-CP1-CLOSE-REV`.

## RA-28 — `M6-CP2-DEFN` independent verifier candidate freeze (2026-10-05; pending mandatory Review)

`M6_Consolidated_Record.md` §51 preserves the reviewed CP2 Definition contract (historical source filenames resolve through its folded-document index):

1. malformed verifier witnesses use copy-by-value A5/A6/A7 **verification record views**; no unchecked product factory exists;
2. findings are typed and ordered by semantic stage/locus, never discovery/vector/output order;
3. the recompute surface is exactly §6.2; every §6.3 forbidden class rejects or is API-shape defensive, with no repair/search/substitution/mutation;
4. A6 certificates/consumptions bind byte-semantically to their exact A5-owned relation/evidence and A7 binds to exact A6 class/topology plus cited A5 evidence; equivalent unreferenced authority is not a substitute;
5. C4 remains accepted-defensive because no permitted production-derived A5 witness reaches it without forging relation authority; the executed pinched-topology falsifier is the verifier's independent manifoldness recompute over a tampered A6 record view;
6. the three RA-27a static-only tampers are wrong-region, one-endpoint-touches-without-connectivity, and three-sheet partial connectivity, with identity29 unchanged;
7. production A8 runs immediately after A7 and before adapter projection; any accepted focused30/selector449 rejection is a mandatory Review stop;
8. RA-26 §5(iii) remains an optimizer reject-only reference-safety obligation and switches to class-wide `vertexChartAuthority` membership; it is not semantic product authority;
9. CP2 gate architecture is focused30 + new CP2-focused12 + selector449 = **491** fresh exact-filter processes. Existing focused30, selector449 and routing449 bytes stay unchanged;
10. successor chain is `M6-CP2-DEFN-REV` → `M6-CP2-CB1-VERIFIER` → TB1 → Review. `M6-DEFN-R5` remains after CP2; `G4-B002` debt remains 1; M7 semantics remain forbidden.

Until `M6-CP2-DEFN-REV` accepts this candidate, RA-28 authorizes **no implementation**.

## RA-28a — CP2 verifier Definition accepted with binding amendments (normative, 2026-10-05, `M6-CP2-DEFN-REV`)

Rationale: `M6_Consolidated_Record.md` §51 (historical `Architecture_M6_CP2_DEFN_Review_Record.md` is indexed there). RA-28 is accepted as amended here; where they conflict, RA-28a governs. No new identities are added: each item is carried by the named identity from the CP2 focused-12 list, and the gate stays **491**.

1. **Exact-once, forest, spanning and cycle checks** (identities 3 and 6). Over published record views only, with no search:
   1. the A5-owned relation IDs, the A6 certificate relation IDs and the A6 consumption relation IDs are equal sets, each ID occurring **exactly once** in each;
   2. the `selectedForest` relation IDs equal the IDs of the `Joining` consumptions, and each forest edge's endpoints equal its certificate's `first`/`second`;
   3. for every class, its published forest edges have both endpoints in the class, number exactly `|members| − 1`, and connect all members (traversal over the *published* edges is a check, not producer union-find);
   4. every `CycleClosing` consumption has both endpoints in one class, and its certificate `relationTransport` equals the exact composition, along the class's published selected path, of the named certificates' transports with their orientations (RA-13 strict rule).

   Failures: `QuotientMembershipMismatch` for 1–3, `NamedTransportMismatch` for 4.
2. **Field-correspondence table for A6 → A5 binding** (identity 6). For certificate `c` citing A5 relation `r`:

   | A6 field | must equal |
   |---|---|
   | `c.relation` | `r.id` |
   | `c.first` / `c.second` | `r.id.first` / `r.id.second` |
   | `c.relationTransport` | `r.evidence.canonicalTransport.value()` (`MissingPublishedAuthority` if absent) |
   | `c.evidence` | `r.evidence.equivalence` |
   | `c.selectedRelationStep` | `r.evidence.canonicalSelectedStep` |

   - `r.firstFrontEdge` / `r.secondFrontEdge` are representation-only and are not compared.
   - **A7 → A6/A5:**
     - each A7 vertex's class equals one published A6 class (ID and member set);
     - its support equals the common A5 member support (RA-18);
     - A7 topology equals the A6 classed cells by IDs;
     - every A7 selected step's applied value equals the cited A5 relation's `canonicalRelationValue` (RA-16 §3).
   - No A6/A7 producer routine is called to derive an expected value.
   - **Stop for Review** if any A6/A7 field differs from its table entry on any accepted row, i.e. if a producer transforms rather than copies. Do not encode a transformation.
3. **A5 wedge and support evidence against A0** (identity 2). For every occurrence:
   - every `cornerWedgeBinding` face is incident to the occurrence's support;
   - `binding.sheet` equals A0's sheet for `binding.face`;
   - `cornerWedgeSheets` equals the sorted, unique set of binding sheets;
   - every `cornerWedgeIsolation` transition has `region == topologyRegion`, its `seam` is an A0 isolation seam of that region incident to the support, and its `{fromSheet, toSheet}` are A0's sheets of the seam's two faces;
   - the A5 occurrence support has exact A0 incidence through the shared source-support kernel (frozen §6.2).

   Failures: `SourceIncidenceMismatch` / `SourceSupportIncidenceMismatch`.
4. **Dependency gating** (identities 1 and 5). Checks are partitioned in the order A0 → A5 identity/indexing → A5 incidence → A6 identity/indexing → A6 ledger/forest/topology → A7 → cross-stage. A check runs only if every prerequisite partition produced no findings; skipped checks emit nothing. The finding set is therefore a function of the input records alone, and identity 1 asserts its invariance under record-order permutation.
5. **Code set** (identity 5). Remove `ForbiddenGeometricWeld` and `UpstreamFailureSubstitution` from the runtime `VerificationFailureCode`:
   - welds are detected combinatorially (item 1.3 → `QuotientMembershipMismatch`, or `NonManifoldTopology`);
   - upstream-failure substitution is excluded by API shape and pinned by a compile-time trait (no verifier overload accepts a producer error variant).

   No runtime code may be emitted without a frozen predicate.
6. **Order as a type invariant** (identity 11).
   - `SurfaceProductVerifier` returns `VerifiedSurfaceProducts`, which only the verifier can construct and only when there are no findings.
   - The adapter's projection entry accepts only `const VerifiedSurfaceProducts&`.
   - A8 runs in a stage function (`produce_verified_surface_products`, name frozen by CB1) called by the adapter, not inlined in the adapter body.
   - Identity 11 asserts:
     - a compile-time trait that projection is not invocable with raw A5/A6/A7 products;
     - behaviorally, that a pipeline result carries a verified report;
     - that a record-view failure maps to the frozen adapter failure string (item 9).
7. **Optimizer reference-safety gating** (identity 12). The class-wide membership check, "projected face ∈ faces of `vertexChartAuthority[v].sourceCharts`", applies **only when `vertexChartAuthority[v].retained`** (authoritative path, `RemeshPipeline.cpp:12868-12872`). Otherwise current behavior is unchanged. It only rejects.
   - **Precondition to prove in the CB1 report:** the representative `sourcePoint.face` belongs to the class's `sourceCharts` faces. Cite the `CornerPlacementProvenance.selectedFace` ∈ wedge-bindings derivation; if unprovable, stop for Review.
   - Identity 12 covers: accept for an in-class face; reject for an out-of-class face; non-authoritative path unchanged.
   - **Stop for Review** if any selector449 optimizer row changes outcome.
8. **Tamper precision** (identities 8–10). Each tamper republishes A5, re-produces A6 (asserting success), then runs A7, and asserts `UncertifiedCrossSheetBinding` at `cross-sheet:wedge`.
   - **Wrong-region:** a valid `TopologyRegionId` ≠ `topologyRegion`, with both sheets kept in the set.
   - **Touches:** **every** bridge transition becomes (in-set, out-of-set).
   - **Three-sheet:** insert a phantom sheet ID, not otherwise used, **in sorted position** in `cornerWedgeSheets`; the transitions still connect only the original two.
9. **A0 and the failure string** (identities 2 and 11).
   - A0 is the tuple (source vertices, source faces, `SourceTopologyRegions` (regions, components, sheets, isolation seams), source hard-feature edges).
   - The adapter maps a verifier rejection to `VerificationFailed:<code>:<site>` from the first finding in semantic order, preserving the site.

Successor: `M6-CP2-CB1-VERIFIER` (Code + Build; compile/package only) → `M6-CP2-TB1-VERIFIER-EXEC` (**491**) → `M6-CP2-TB1-VERIFIER-REV`. `M6-DEFN-R5` follows CP2. `G4-B002` stays open (debt 1). Accounting **60 / 16 / 44**.

## RA-28b — RA-28a §7 withdrawn; optimizer check retained as non-authoritative; identity 12 re-specified (normative, 2026-10-05, `M6-CP2-CB1-VERIFIER-REV`)

Rationale: `M6_Consolidated_Record.md` §52 (historical `Architecture_M6_CP2_CB1_Stop_Review_Record.md` is indexed there).

1. **Withdrawal.** RA-28a §7 is withdrawn: its face-membership predicate and its `selectedFace ∈ cornerWedgeBindings` precondition. A5/A7 do not publish that precondition, and RA-22b §2 keeps the representative face representation-only. **No A5 invariant is added.**
2. **RA-26 §5(iii) resolution.** The existing optimizer component/sheet self-check stays **unchanged**, classified as non-authoritative. On the authoritative path, `project_vertices` confines every projected provenance to its seed's own face (vertex/edge/face-interior supports) or scope (degenerate fallback), at `SurfaceMeshOptimizer.cpp:706-750` and `:786-797`. So an optimizer-side check can only re-test a static lineage property, and that property is certified elsewhere:
   - **before movement:** the frozen completion guard (`PureQuadCompletion.cpp:895-941`) and the CP2 verifier (RA-28a §3);
   - **after movement:** final validation (`SourceAuthoritativeMeshValidator.cpp:1232-1262`).

   **No `SurfaceMeshOptimizer` source change in CP2.**
3. **Identity 12.** `M6CP2.AuthoritativeOptimizerProjectionStaysOnRepresentativeScope` replaces `M6CP2.OptimizerProjectionUsesClassWideChartAuthority` at position 12.
   - **Setup:** authoritative-path constraints from a produced fixture. Non-vacuity requires at least one vertex-support and one edge-support seed. Those are the only kinds whose representative face can lie outside the wedge bindings. Face-interior seeds are asserted if present but not required.
   - **Action:** call `surface_optimizer_detail::project_vertices` with perturbed candidates.
   - **Assertions:**
     1. the projected `face` equals the seed `face` for every valid seed;
     2. `componentsOk` and `sheetsOk` are true;
     3. `sheet_for_row(seed.face)` ∈ the sheets of the `vertexChartAuthority[v].sourceCharts` faces for every retained `v`.
   - The identity count, order and gate (**491**) are unchanged.
4. **Later-owner note.** Representative faces can lie outside the wedge bindings for edge and vertex supports. `M6-DEFN-R5`'s RA-26 §5(i)/(ii) class-wide reference must not assume `selectedFace` ∈ the class's chart faces.
5. **Void.** The exploratory CB1 WIP's optimizer membership change is void. All other RA-28a sections are unchanged.

Successor: `M6-CP2-CB1-VERIFIER-R1` (new turn; Code + Build) → `M6-CP2-TB1-VERIFIER-EXEC` (491) → `M6-CP2-TB1-VERIFIER-REV`. Accounting **60 / 16 / 44**, debt 1.


## RA-29 — CP2 TB1 verifier recovery after independent Review (normative, 2026-10-05, `M6-CP2-TB1-VERIFIER-REV`)

`M6-CP2-TB1-VERIFIER-REV` rejects the `265c8fbb...` candidate for bounded recovery. The three runtime REDs are non-stable witness defects, but Review also finds four static RA-28a implementation gaps. Recovery is limited to the following:

1. identity 2 must create a real canonical source-face mismatch and must verify published occurrence support against A0 with the shared `SurfacePointSourceSupportResolver`;
2. identity 6 must use a non-vacuous always-bound A6→A5 payload tamper and the verifier must independently require every published selected path to equal the unique traversal of the published selected forest before transport composition;
3. identity 7 must construct a real weld-pinched record view from disjoint produced quotient-cell components and reach `NonManifoldTopology / a6:vertex-link`;
4. identity 8's wrong-region replacement must be an actual A0 region distinct from the occurrence region;
5. identity 11/full pipeline must carry the exact verified A8 report in the successful `AuthoritativePhaseFrontMeshResult`; projection remains gated by `VerifiedSurfaceProducts`;
6. no optimizer source change, no A5 semantic expansion, no selector/focused order change, and no reduction of the 491-process gate.

The three EXEC candidates are **FALSE REJECTION / NON-STABLE** and remain +0 to stable accounting. REV-OBS-01/03/04 are production/API verifier contract omissions; REV-OBS-02 is a latent test-witness authority defect. Candidate `11365308211 / 265c8fbb...` is not promoted.

Successor chain is frozen: `M6-CP2-CB1-VERIFIER-R2` → `M6-CP2-TB1-VERIFIER-R1-EXEC` (**491**) → `M6-CP2-TB1-VERIFIER-R1-REV`. `M6-DEFN-R5` remains after CP2. Stable accounting remains **60 / 16 / 44**, debt 1.

## RA-29a — verifier recovery amendments (normative, 2026-10-05, `M6-CP2-TB1-VERIFIER-REV` review-agent addendum; amends RA-29 and RA-28a §1.3/§8)

Rationale: `Architecture_M6_CP2_TB1_Verifier_Review_Record.md`, addendum §S1–§S3. RA-29 items 1–3, 5 and 6 stand. RA-29 item 4 is replaced by item 6 below. The following are added to `M6-CP2-CB1-VERIFIER-R2`. The identities, their order and the gate (**491**) are unchanged.

1. **Every relation is intra-class** (identity 3; amends RA-28a §1.3). Every A5-owned relation, whatever its disposition, must have both endpoints in one published class (`QuotientMembershipMismatch`, `a6:relation-class`). Also |`selectedForest`| = Σ over classes of (|members| − 1).
   - Identity 3 adds this witness: split a produced class at one forest edge into two classes, each still spanned by its own edges, and require `a6:relation-class`.
2. **Linear-time topology** (static; no identity). Edge → owning-cells and vertex → incident-edge maps are built in one pass. No per-edge cell scan, no per-vertex edge scan. The verifier's A6 topology partition must be O(n log n) in cells + edges. The R2 report states the complexity, with `file:line` evidence.
3. **Exact A7 step citation** (identity 6). Each A7 HardRail/Periodic selected step binds to the relation ID at the same position of the HardRail/Periodic subsequence of the class's A6 `QuotientSelectedPathCertificate.orderedRelations`. Its applied value must equal that exact relation's `canonicalRelationValue`, inverted for `Reverse`.
   - If R2 cannot establish that positional correspondence from the published records, it must instead require that every A5 relation sharing the step's rail or periodic ID carries an identical `canonicalRelationValue`, and record why the positional binding is unavailable.
   - First-match lookup is forbidden.
4. **A0 component adjacency** (identity 2; frozen §6.2). Recompute the connected components of A0 face edge-adjacency, and require `component_for_row` to induce exactly that partition (labels up to renaming). Failure: `SourceIncidenceMismatch`, site `a0:component-adjacency`.
5. **The token binds contents** (identity 11). `VerifiedSurfaceProducts` either **owns** the verified A5/A6/A7 products (moved in, or `shared_ptr<const>`) or is non-copyable and confined to the stage function's scope. Post-projection adapter counters read through the token, never through raw product pointers. Identity 11 adds a compile-time trait that pins the chosen property.
6. **Wrong-region witness** (identity 8; replaces RA-29 item 4; amends RA-28a §8). The replacement `TopologyRegionId` need only differ from `occurrence.topologyRegion`; A0 validity is **not** required, because the asserted site `cross-sheet:wedge` pins the region filter and nothing upstream checks region validity. Identity 8 adds an explicit inequality assertion. **No new fixture is required.**
7. **Precision.**
   - **Shared kernel coverage** (RA-29 item 1 / REV-OBS-03): the shared-kernel point ↔ support equality also applies to A7's class binding (`a7:class-binding`).
   - **Identity 7** changes **only** `classedCells` corner class IDs. It must assert pre-tamper disjointness and that the A6 ledger partition produces no findings; a class merge would trip gating before `a6:vertex-link`.
   - **Identity 6's path-structure tamper** uses a produced class with a ≥2-step selected path, with non-commuting transports where available.

Successor: `M6-CP2-CB1-VERIFIER-R2` → `M6-CP2-TB1-VERIFIER-R1-EXEC` (**491**) → `M6-CP2-TB1-VERIFIER-R1-REV`. Accounting **60 / 16 / 44**, debt 1.

## RA-29b — `M6-CP2-TB1-VERIFIER-R1-REV` bounded recovery amendment (normative, 2026-10-06)

R1 runtime (`37393554373 / 112044082007`) rejects the R2 candidate at **462/491**. Independent Review finds two bounded verifier-authority errors; candidate `11382000465 / 9c8478ae...` is not promoted.

1. **A7 legacy projection is not an A6 path identity.** A6 publishes root/target and exact relation paths; A7 intentionally projects only HardRail/Periodic legacy certificates and deduplicates equal values. Therefore multiple A6 root→target paths may lawfully map to one A7 legacy path. RA-29a §3's positional rule applies only when one published A6 path is identifiable from A7 data. When multiple A6 paths have the same legacy projection, R3 must use RA-29a's fallback: for each A7 step, every A5 relation in the class sharing that step's rail/periodic owner ID must publish the same `canonicalRelationValue`, and the A7 applied value must equal that common value after orientation. Ambiguity itself is **not** `MissingPublishedAuthority`. Zero matching A6 legacy projections still is. First-match selection remains forbidden.
2. **RA-29a §4 exact component partition is withdrawn as a review-agent error.** `SourceComponentId` is ingress authority and is not independently derivable from raw triangle connectivity in the current verifier API. `build_source_topology_regions` accepts published component labels and can publish multiple disconnected topology regions with the same component label. Accepted selector449 ordinal144 intentionally exercises this (`sourceFaceComponents` all zero on a disconnected square pair) and must remain green. Remove `a0:component-adjacency` raw-connectivity equality and the identity-2 component-merge sub-witness. Keep all other A0/A5 elementary incidence and shared-support checks. A future stronger component-label check requires independently published ingress-label evidence rather than inference from mesh connectivity.
3. **Focused12 identity 6** keeps its name/order and its >=2-step path tamper, but its baseline must be green. The identity must additionally prove a produced ambiguity witness (two or more A6 selected paths collapsing to an equal A7 legacy projection) so the fallback is non-vacuous. No unchecked authority may be forged.
4. **Runtime evidence upload:** the next TB caller must derive upload paths from the same `TURN_ID` used by the harness. R1's stale predecessor path is orchestration-only and does not authorize a duplicate R1 runtime.
5. No optimizer change, no A5/A6/A7 producer semantic change, no focused30/focused12/selector/routing order change, and no gate reduction.

Successor chain: `M6-CP2-CB1-VERIFIER-R3` → `M6-CP2-TB1-VERIFIER-R2-EXEC` (**491**) → mandatory `M6-CP2-TB1-VERIFIER-R2-REV`. Stable accounting remains **60 / 16 / 44**, debt 1.

## RA-29c — exact three-hop A7 relation-step binding (normative, 2026-10-06, `M6-CP2-TB1-VERIFIER-R1-REV` review-agent addendum; replaces RA-29b §1 and §3 and RA-29a §3)

Rationale: `Architecture_M6_CP2_TB1_Verifier_R1_Review_Record.md`, addendum §T3–§T5. RA-29b §2, §4 and §5 stand.

1. **Withdrawn.**
   - RA-29a §3's positional reverse lookup;
   - RA-29b §1's same-owner-ID fallback. It falsely rejects whenever relations sharing a rail or periodic ID carry inverse `canonicalRelationValue`s, which A5 produces whenever storage order is not canonical (`RemeshPipeline.cpp:4917-4921`);
   - RA-29b §3's produced ambiguity witness.

   R2's `a7:a5-relation-step` reverse lookup, including its per-A7-path scan of all A6 paths, is removed.
2. **Hop 1, A5 internal** (identity 6). For every A5 relation with `canonicalSelectedStep`: `canonicalRelationValue` is present, `step.appliedTransport == canonicalRelationValue`, and `step.direction == Forward` (A5 constructs exactly this, `:4936-4941`). Failure: `CertificatePayloadMismatch`, site `a5:selected-step-value`. This check runs in the A5 partition.
3. **Hop 2, A6 legacy projection** (identity 6). For every A6 `QuotientSelectedPathCertificate`, using only its own `orderedRelations` / `traversalOrientations` and the named certificates' `selectedRelationStep`:
   - `legacyProjection.has_value()` ⇔ the oriented step subsequence is non-empty;
   - `orderedSteps` equals that subsequence. A `Reverse` traversal inverts a step: invert `appliedTransport`, swap from/to chart and chart component, flip `direction`;
   - `composedTransport` is the composition of the steps' `appliedTransport`;
   - start/end chart and chart component come from the first/last step.

   Failure: `CertificatePayloadMismatch`, site `a6:legacy-projection`. A6's own publication construction is matched (`:5500-5548`, `:5935-5960`) using only §6.2 named-certificate inversion and composition.
4. **Hop 3, A7 projection** (identity 6). For every class: `vertex.selectedRelationPaths` equals the sorted, deduplicated list of the class's present `legacyProjection`s (A7 construction, `:6962-6970`). Failure: `CertificatePayloadMismatch`, site `a7:selected-paths`. Paths are grouped by class once, so the binding is O(P log P).
5. **Identity 6 witnesses** (same fixture as the ≥2-step path tamper). Keep the clean baseline, the `relationTransport` tamper and the path-structure tamper. Add (a) an A7 step `appliedTransport` tamper → `a7:selected-paths`, (b) an A6 `legacyProjection` step tamper → `a6:legacy-projection`, and (c) a `canonicalRelationValue`-only A5 tamper → `a5:selected-step-value`. Each asserts that its tamper changed the record before the verifier is called. **No ambiguity witness.**
6. **Identity 11.** Replace `static_assert(VerifiedSurfaceProducts::owns_products)`, which is self-declared and vacuous, with a behavioral check: the token's product addresses differ from the originals, and the token's record views equal the originals'. Remove the `owns_products` constant.
7. **Stop rules.**
   - Hop 1 or Hop 2 rejects any accepted focused-30 or selector449 row → stop for Review. Do not weaken the check.
   - Hop 2 needs any transformation other than §6.2 inversion and composition → stop for Review.

Successor: `M6-CP2-CB1-VERIFIER-R3` → `M6-CP2-TB1-VERIFIER-R2-EXEC` (**491**; upload paths derived from the harness `TURN_ID`) → mandatory `M6-CP2-TB1-VERIFIER-R2-REV`. Accounting **60 / 16 / 44**, debt 1.

## RA-29d — CP2 closure revoked; verifier binding and negative-coverage completion (normative, 2026-10-06, `M6-CP2-TB1-VERIFIER-R2-REV` review-agent addendum)

Rationale: `Architecture_M6_CP2_TB1_Verifier_R2_Review_Record.md`, addendum §U1–§U4.

1. **Status.** `11385836615 / c64baacd` remains **promoted** as reviewed runtime authority (491/491). "M6-CP2 CLOSED" is **revoked**: CP2 stays ACTIVE until `M6-CP2-CLOSE-REV`.
2. **A7 vertex binding** (implements RA-28a §2). For every A7 vertex `v` of class `C` with support certificate `s`, require:
   - `v.representative` ∈ `C.members`;
   - `v.sourcePoint` == the representative occurrence's published `point` (exactly);
   - `v.position` == `v.sourcePoint.position`;
   - `v.support == s.publishedSupport`.

   Failure: `SourceSupportIncidenceMismatch`, site `a7:vertex-binding`. A7 copies these fields verbatim (`RemeshPipeline.cpp:6985-6993`), so the check is gate-neutral.
3. **Dead codes.**
   - Remove `UncertifiedAuthoritySubstitution`.
   - `BoundaryOrEulerMismatch` is emitted for the recomputed components, boundary-loop count and Euler characteristic at `a6:components`, `a6:boundary-loops` and `a6:euler`, split out of `certificate:a7`.
4. **Negative coverage** (identities 2–5; names, order and gate **491** unchanged). Execute exact code+site witnesses for:
   - the RA-28a §1 ledger and forest predicates;
   - A5 ownership and directed sides;
   - A0 hard-feature edges;
   - A7 vertex binding, cover and topology copy;
   - the A5/A6 certificates;
   - `BoundaryOrEulerMismatch`.

   Identity 5 becomes a table-driven map with one row per frozen §6.3 class. Each row is either an executed record-view witness or an API-shape compile-time trait. Details: `Architecture_M6_CP2_CB2_Coverage_Code_Build_Plan.md` G3.
5. **Coverage table.** The CB report maps every §6.2 recompute category and every §6.3 class to its predicate (`file:line`) and its executed witness or API-shape classification. A missing row is a stop for Review.
6. **CP2 closure** happens only at `M6-CP2-CLOSE-REV`. It adjudicates frozen §10 M6-CP2 against that table and a fresh 491 gate, and writes `M6_CP2_Closure_Record.md`.
7. **Observations.**
   - `reverse_selected_relation_step` is a shared exact-algebra helper; acceptable under §6.2, recorded.
   - The by-value token copies the products on every run (owner M8-CP2).

Successor: `M6-CP2-CB2-COVERAGE` → `M6-CP2-TB2-COVERAGE-EXEC` (**491**) → `M6-CP2-CLOSE-REV` → `M6-DEFN-R5`. Accounting **60 / 16 / 44**, debt 1.


## RA-30 — CP3 entry authority, class-wide references and direct-exit gate (normative, 2026-10-06, pending `M6-DEFN-R5-REV`)

Rationale: `Architecture_M6_DEFN_R5_CP3_Entry_Definition_Record.md`. This amendment is a Definition candidate until mandatory independent `M6-DEFN-R5-REV` accepts it; it authorizes no implementation before that Review.

1. **Exact-A3 Periodic gauge rule.** Keep semantic periodic relation value in relation-endpoint gauge. Recompute published endpoint state from local placement + interval + relation rotation + face-gauge authority. Derive placement transport by exact conjugation `Γ_to^-1 ∘ g ∘ Γ_from`, require the two endpoint-derived transports equal, and validate canonical occurrence placements. Independently require `g` to map relation-gauge endpoint coordinate+branch states. Never compare face-gauged front-edge branches across unequal face gauges.
2. **HardRail branch certificate.** Coordinate-rigid HardRail `canonicalTransport` remains placement authority. Publish exact endpoint face-gauge evidence; strip it from placement branch labels and require the resulting regional branch difference to equal the coordinate-rigid transport rotation on both endpoint pairs. Different topology regions never compare raw branch labels.
3. **OrdinaryFront isolation seam.** OrdinaryFront quotient transport is always identity. Exact quotient identity requires lattice coordinate + scale equality. Across a collinear isolation seam, source-chart/face-gauge labels may differ only with the exact reciprocal checked isolation transition. Its seam quarter-turn is chart evidence, never extra quotient transport.
4. **A5 chart barriers.** A5 consumes the immutable typed source hard-feature edge authority directly. Barrier membership is not reconstructed from relation kind or HardRail routes. A PeriodicCut carrier is a barrier iff source hard-feature authority marks it; every HardRail carrier must be marked or A5 fails closed.
5. **Class-wide optimizer/final-validation reference.** Resolve one compatible chart from all four quad corners plus all four `vertexChartAuthority` sets. Use that quad-wide chart for optimizer normal/field reference, finite-difference gradient, line search and final edge-field metrics; freeze the resolved face set through one local evaluation. No first-corner/first-endpoint/representative-face narrowing and no assumption that `selectedFace` belongs to every class chart. Missing compatible authority is typed failure. Cost is linear in the four corners' published chart memberships with a fixed number of projections per evaluation.
6. **Permutation falsifier.** A direct-produced torus must be invariant under a consistent source-face-row permutation, output vertex/face-row permutation and deterministic nonzero quad-corner rotation that actually changes at least one class representative and one corner-0. Discrete products/decisions/digests are exact after semantic remap; continuous positions/metrics use `1e-12 * max(1, source_bbox_diagonal)`.
7. **A7 selected-edge sheets dispatch by relation kind.** HardRail cross-region edges validate each endpoint in its own partition plus the RA-30 branch certificate and never compare global sheet IDs. OrdinaryFront within one topology region requires shared sheet or one exact connecting isolation transition. Periodic uses that same rule within one topology region; a produced cross-region Periodic case is a mandatory Review stop. Unsupported kinds fail closed. The seam-collinear positive must be real-tracer produced and must have disjoint endpoint sheet sets.
8. **CP3 direct-exit evidence.** New identities are exactly: `PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority`, `HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`, `OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition`, `A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds`, `ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition`, `HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`, `ClassWideOptimizerReferencesAreSourceOutputAndCornerPermutationInvariant`, `DirectProductionKeepsCoincidentUnrelatedClassesDistinct`, `DirectProductionConsumesEveryA5RelationExactlyOnce`, `DirectProductionPublishesExactSharedSupportAndA8BindsIt`, `DirectProductionSchedulerPermutationIsSemanticNoOp`, `DirectProducedTorusCandidateEligibilityAndHardFeatureTamper`, and `DirectProducedTorusBindsA5A6A7A8RepresentativeChain`, all under suite prefix `M6CP3`.
9. **G4-B001 strict 3/3.** The CP3 current-source strict direct-torus identities are `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`, `MilestoneGP26.TorusCompletesEndToEnd`, and `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`. The parameterized P27 diagnostics-ownership row receives no strict-production credit because it does not require success. Historical artifact `9031804178` preserves only aggregate 0/3, not old exact names; do not fabricate historical mapping. No validator or sheet-authority weakening is allowed.
10. **Sequencing/gates.** CB1 owns only items 1-4 and 7 plus the first six identities; compile/package only. Its artifact-only entry gate is inherited `30 + 12 + 449 = 491` plus six = **497** fresh exact-filter processes, followed by mandatory Review. No CP3 direct-production acceptance TB may precede that Review. CB2 then owns items 5-6 plus the remaining seven identities. Final CP3 gate is 491 + 13 + G4-B001 3 = **507** processes. Existing focused30, focused12, selector449 and routing449 bytes remain frozen; do not fold or rewrite them in Definition.
11. **Selector449 stop rule.** If the class-wide optimizer/reference change alters any inherited selector449 optimizer/validator outcome, stop before direct-production TB. Do not edit the accepted expectation, remove the row, or substitute a replacement; return to independent Review with exact ordinals and source cause.
12. **Debt/accounting.** Stable accounting stays **60 / 16 / 44**, debt 1. `G4-B002` closes only on accepted CP3 direct-production evidence; mechanism evidence remains prerequisite only. M8-owned adapter/copy/hardening obligations and all M7 disposition semantics are outside RA-30.

Mandatory chain after acceptance: `M6-DEFN-R5-REV` → `M6-CP3-CB1-ENTRY` (compile/package only) → artifact-only 497-process entry TB → mandatory Review. The CB1 plan is held until Definition Review.

## RA-30a — CP3-entry Definition accepted with binding amendments (normative, 2026-10-06, `M6-DEFN-R5-REV`)

Rationale: `Architecture_M6_DEFN_R5_Review_Record.md` §2. RA-30 is accepted as amended; where they conflict, RA-30a governs. Gate counts are unchanged (497 entry, 507 final).

1. **D4 authority source** (amends RA-30 §4; CB1).
   - `SurfacePhaseFrontProduct` publishes the immutable typed source hard-feature edge set its tracer consumed (`SurfaceCellTracingOptions::hardFeatureEdges`, `SurfaceCellTracing.h:2089`), validated as source edges at A4 construction.
   - A5 builds its chart-barrier set **from that product field**. A5's `produce(V, F, phaseFront)` signature is **unchanged**.
   - The authoritative adapter fails closed if the pipeline's `hardFeatureRailEdges` differ from the A4-published set.
   - **Stop for Review** if any accepted focused-30 or selector449 test body would have to change.
2. **D2 non-trivial gauge witness** (CB1).
   - Identity `HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` must use a **produced** fixture built through `remesh_from_raw_cross_field` (SurfaceCells backend, fallback `Fail`, no source-grid recovery). The fixture has two topology regions separated by user hard edges, a **non-constant raw cross field**, and at least one cross-region HardRail relation.
   - **Non-vacuity, asserted first:** at least one endpoint pair has `F_a ≠ F_b`, and the difference is 90° or 270°, so that a wrong-direction stripping (`F ∘ B` instead of `F⁻¹ ∘ B`) is rejected.
   - The negative tampers may additionally run on the existing constant-field HardRail fixture.
   - If the produced fixture lacks the property at TB time, that is a test-authority RED for Review, not a production defect. Never hand-build records.
3. **D3 seam branch certification** (amends RA-30 §3; CB1).
   - **Non-seam OrdinaryFront:** keep the current full equality (`sourceChart`, `branchRotation`, coordinate, scale, and the `1e-10` phase check, kept reject-only) at `RemeshPipeline.cpp:5229-5236`.
   - **Across a certified collinear isolation seam:** require all of
     - coordinate and scale equality;
     - the exact reciprocal `CornerWedgeIsolationTransition` pair;
     - **face-gauge-stripped branch difference == the A5-validated `SurfaceIsolationSeamTransportCertificate` quarter-turn** (`forward()` or `reverse()` by direction; `SurfaceCellTracing.h:1341-1365`);
     - the phase check, kept reject-only.

     `sourceChart` may differ only in this case.
   - The quarter-turn is chart evidence, never quotient transport (RA-2).
   - Identity 3 adds a tamper on the stripped branch: rotate one endpoint branch by 90° while the seam evidence stays valid → reject.
4. **G4-B001 rows' build target** (amends RA-30 §9–§10; CB2).
   - CB2 adds `directional_surface_cell_historical_tests` (with `DIRECTIONAL_BUILD_HISTORICAL_TESTS=ON`) to its compile and package set. The TB executes only the two named filters from that target.
   - If the historical target fails to compile, or either filter is not discoverable, **stop for Review**. Do not edit historical tests to make them build, and do not substitute other rows without Review.
   - CB1 and the 497 entry gate are unaffected.
5. **D6 feasible equality** (amends RA-30 §6; CB2).
   - D5's implementation must accumulate optimizer energy, gradient and line-search sums in **canonical semantic order** (by quotient-class and cell identity, not row index). Exact discrete-decision invariance then holds by construction, and the `1e-12 · max(1, bbox)` positional tolerance is achievable.
   - If canonical ordering is not adopted, the equality must be relaxed: accept/reject and discrete validator outcomes stay exact; the continuous tolerance must be justified; iteration and line-search sequences are not required to be exact. **Stop for Review rather than choose silently.**
   - The output-row permutation seam is a test that calls `optimize_source_authoritative_surface_mesh` directly with permuted `(vertices, quads, provenance, vertexChartAuthority)` taken from a produced run. No production hook.
6. **Scheduler permutation defined** (CB2). `DirectProductionSchedulerPermutationIsSemanticNoOp` permutes:
   1. the A4 phase-front cell, edge and event container order, reconstructed through the validating A4 factory;
   2. the A5 owned-relation container order fed to A6.

   A5/A6/A7/A8 semantic products, certificates and decisions must be **exact** after semantic remapping.
7. **D1 witness** (CB1).
   - Candidate fixture: the produced nonzero-Z4 torus (carrier search at `SurfaceCellTransitionQuotientTests.cpp:1351-1363`).
   - **Non-vacuity:** a reciprocal exact-A3 pair whose `localFaceBranchRotation` differs by 90° or 270°, so a mutant using `Γ` instead of `Γ⁻¹` is rejected. A pair differing by 180° does not count.
   - A missing pair is a test-authority RED for Review.
8. **D2 site.** The branch-certificate failure keeps the external `InvalidHardRailTransport` with site suffix `:branch-certificate`.

Successor: `M6-CP3-CB1-ENTRY` (released; compile/package only) → `M6-CP3-TB1-ENTRY-EXEC` (**497**) → mandatory `M6-CP3-TB1-ENTRY-REV`. Accounting **60 / 16 / 44**, debt 1.

## RA-31 — CP3 entry recovery (normative, 2026-10-06, `M6-CP3-TB1-ENTRY-REV`; published by its review-agent addendum)

Rationale: `Architecture_M6_CP3_TB1_Entry_Review_Record.md`. Candidate `11411137781 / 912760f1` is rejected at 373/497. The partition is exact: CAND-01 110, CAND-02 9, CAND-07 1 (stable), and CAND-04 1, CAND-05 2, CAND-06 1 (non-stable). Accounting becomes **63 / 17 / 46**, debt 1.

Recovery `M6-CP3-CB1-ENTRY-R1` covers:
- **P1:** every successful A4 regional producer publishes the face gauge it already computes; no default, fallback or weakened merge check.
- **P2:** reciprocal isolation-side evidence applies only on the certified cross-sheet collinear OrdinaryFront seam path. Non-seam relations keep full equality.
- **T1:** focused-30 ordinal 12 relabels the explicit face gauges consistently.
- **T2:** the D1 produced witness.
- **T3:** the D2 produced witness.
- **T4:** the D4 oracle against typed barrier semantics.

No optimizer, validator, selector, routing or frozen-name change. TB **497**, then mandatory Review.

## RA-31a — HardRail branch certificate withdrawn pending definition; R1 scope amended (normative, 2026-10-06, `M6-CP3-TB1-ENTRY-REV` review-agent addendum; amends RA-30 §2, RA-30a §2 and §8, and RA-31 T2/T3)

Rationale: `Architecture_M6_CP3_TB1_Entry_Review_Record.md`, addendum §X2–§X3.

1. **Withdrawn.** RA-30 §2's certificate (`C = F⁻¹ ∘ B` with each endpoint's own region-relative F, requiring `C_b ∘ C_a⁻¹ = R_coord`) is **withdrawn as unproven**. The published F is region-relative: the planar frame axis (`SurfaceCellTracing.cpp:10723-10760`) or the curved region root (`:14933-14934`). TB7 §G2's derivation gives `C_b − C_a = R_true + τ − (F_b − F_a)`, with τ the cross-rail field matching. The certificate is therefore valid only if `F_b − F_a = τ`, which is not established.
2. **R1 production.**
   - Remove the `HardRailBranchCertificateMismatch` rejection from A5. Coordinate-rigid `canonicalTransport` stays the sole HardRail placement authority, as before CB1.
   - **Keep** publishing per-endpoint face-gauge evidence (`firstEndpointFaceGauge` / `secondEndpointFaceGauge`).
   - Remove the now-unemitted error code and its `:branch-certificate` name mapping (no dead codes).
3. **`M6-DEFN-R5-R1`** (bounded Definition; it follows the R1 Review) must:
   - derive the HardRail branch certificate in terms of the **cross-rail field matching τ(f_a→f_b) between the two selected faces**, with conventions and a path-independence argument at rail vertices (fail closed at field singularities);
   - name the producer that publishes τ (A4 holds the matchings; A5's inputs do not);
   - name a **discriminating produced witness** where `F_b − F_a ≠ τ`, so the withdrawn per-region rule would falsely reject and the τ rule accepts.
4. **Identity 2** (`HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge`).
   - In TB1-R1 it is **pre-registered RED**. Its non-vacuity premise (a produced cross-region HardRail with an endpoint gauge difference of 90° or 270°) and A5 production must pass. Its certificate-rejection assertions are expected to fail.
   - The test must **print the exact A5 error code, site and relation** on any A5 rejection.
   - Do not rename or retire it. It is completed under `M6-DEFN-R5-R1`.
5. **Identity 6** (`HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels`) must pass on the same produced fixture once the certificate rejection is removed. Any remaining A5 rejection, printed with its code, is a **stop for Review**: for example the RA-30a §1 carrier-membership rule, if the fixture's typed hard-feature set omits its rail.
6. **D1 stop rule (T2).** If no produced nonzero-Z4 torus pair has an endpoint gauge difference of 90° or 270°, **stop for Review**. Never hand-build records.
7. **TB1-R1 acceptance pattern.** 496 PASS, plus identity 2 RED with failures confined to the certificate-rejection assertions after its non-vacuity and A5-production assertions pass. Any other RED goes to Review as usual.

Successor: `M6-CP3-CB1-ENTRY-R1` → `M6-CP3-TB1-ENTRY-R1-EXEC` (**497**) → `M6-CP3-TB1-ENTRY-R1-REV` → `M6-DEFN-R5-R1` (D2) → the D2 CB. CB2 (D5/D6/D8) stays held until the CP3 entry is fully green. Accounting **63 / 17 / 46**, debt 1.

## RA-32 — CP3 entry R1 Review: failed seam-domain recovery and bounded Definition repair (normative, 2026-10-07, `M6-CP3-TB1-ENTRY-R1-REV`)

Rationale: `Architecture_M6_CP3_TB1_Entry_R1_Review_Record.md`. R1 candidate `11488700954 / 68000a95...` is mechanically valid at **482/497** but rejected/unpromoted. Stable accounting remains **63 / 17 / 46**, debt 1.

1. **P2 remains open.** The ten R1 A6/D7 REDs are continuation of the already-counted predecessor `RP-01 / AUTHORITY_DOMAIN_CONFLATION` event. The special OrdinaryFront seam path must be selected by relation/certificate-owned isolation-seam evidence; differing global sheet labels are not authority. Non-seam full representation equality and all certified-seam exact checks remain mandatory.
2. **D1 Definition repair.** Freeze an organic producer/search for a reciprocal exact-A3 90°/270° endpoint-gauge pair and a stop rule if none exists. Never hand-build the production record.
3. **D2 Definition repair.** RA-31a remains governing: derive the HardRail branch rule in the cross-rail field-matching `τ(f_a→f_b)` domain, name its publisher, prove rail-vertex path independence/fail-closed singularity behavior, and name a discriminating produced witness. Identity 2 keeps its name.
4. **D3/D7 witness authority.** The next Definition must specify a real-tracer fixture that actually produces a seam-collinear OrdinaryFront carrying the exact seam certificate; merely containing an isolation seam is insufficient. D3 and D7 keep distinct falsifiers.
5. **D4 witness authority.** The ordinary hard-feature falsifier must select/derive a route-bearing ordinary source carrier; `OrdinaryInterior` kind alone does not prove a non-empty route. Periodic/HardRail typed-source checks remain.
6. **Recovery status.** Predecessor `INCOMPLETE_AUTHORITY_PUBLICATION` and focused-relabel `RP-02` events are recovery-proved. The predecessor `RP-01` event remains open. No new event/category/recurrence is counted for R1.
7. **Routing.** Exact next is runtime-free `M6-DEFN-R5-R1`, followed by mandatory `M6-DEFN-R5-R1-REV`. Only accepted Definition Review may release one bounded R2 Code + Build. CB2 (D5/D6/D8) remains held until CP3 entry is fully green.


## RA-33 — M6-DEFN-R5-R1 CP3-entry Definition candidate (**NOT FROZEN; mandatory Definition Review required**, 2026-10-07)

**Candidate only.** This block is submitted for `M6-DEFN-R5-R1-REV` and has no implementation authority until independently accepted. Detailed formulas, source-line evidence, worked positive/negative examples and unresolved organic witness obligations: `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md`. RA-32 remains the accepted routing authority. In particular, a prescribed *search* is **not** proof that an organic witness exists.

1. **RA-33.1 A6 OrdinaryFront:** certified special isolation-seam path iff relation-owned reciprocal collinear side spans, matching region/source-face/sheet certificate, reciprocal side evidence and typed two-way isolation transitions all agree. Sheet ID inequality alone never grants special status. Partial special evidence fails closed; non-seam full chart/branch/phase/scale/sheet equality and all existing certified exact checks remain.
2. **RA-33.2 periodic D1:** select only among actual tracer-produced reciprocal source/A3-exact Periodic pairs from a bounded, deterministically enumerated nonzero-Z4 torus fixture with endpoint face-gauge delta `1` or `3 mod4`. Check source edge, selected faces, orientation, A3 matching, identical interval, reciprocal A4 edge identity and route before assertions. If none exists, return to Review; never fabricate records or accept an even delta.
3. **RA-33.3 HardRail D2:** `B_b ◦ B_a⁻¹ = R_coord ◦ τ(f_a→f_b)` in oriented Z4, where `τ` is an A3-verified cross-rail source-face matching, **not** a difference of region gauges. A4 owns publication of oriented τ into `SurfacePhaseFrontProduct`; A5 consumes the certificate. Check both endpoints, inverse orientation, rail-vertex path-independent composition, fail-closed nonzero singular holonomy and source barriers. Preserve published F as provenance only. Require a real-produced cross-region discriminant with `(F_b−F_a) != τ` before success. Identity 2 retains its existing name.
4. **RA-33.4 seam D3/D7:** prefer a seam-aligned real-tracer rectangle family and require actual OrdinaryFront collinearity, matching certificate, reciprocal side transitions, D7 disjoint endpoint wedge-sheet sets and real A5→A6→A7 positive chain. Distinct A6 branch-tamper and A7 evidence-tamper falsifiers. Input mesh seam alone is insufficient.
5. **RA-33.5 D4:** select only a *real produced* `OrdinaryInterior` A4 edge with nonempty route and an eligible actual source-chart carrier transition; its typed hard-feature injection must block that transition. Preserve independent Periodic/HardRail typed carrier checks. A boundary kind does not imply an A4 route.
6. **Release gate:** This Definition itself changes no production/test/fixture/selector/build/runtime logic. Frozen TB entry selection stays **497 = 30+12+449+6** (no renames). Stable **63/17/46**, debt **1**. `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md` is **HELD**. Only `M6-DEFN-R5-R1-REV` may accept and release R2; an unresolved organic witness is a **stop for Review**, not permission to weaken assertions.


## RA-34 — M6-DEFN-R5-R2 **ACCEPTED at independent R2 Review** (bounded Definition only; 2026-10-08)

Independent `M6-DEFN-R5-R2-REV` accepts these two narrow Definition corrections to rejected RA-33. No organic produced-witness existence or runtime result is accepted. Full source reasoning, falsifiers and typed producer-authority stop rules: `Architecture_M6_DEFN_R5_R2_CP3_Entry_Recovery_Definition_Record.md`. RA-32 remains accepted routing authority. Amend only RA-33.1 and RA-33.3:

- **RA-34.1:** An A4-certified isolation seam must be found without raw/global sheet-label equality **granting or denying certificate lookup**. Bind selected source-face, A4 typed wedge-to-certificate sheet incidence and certificate orientation to one `Forward|Reverse` match, used consistently for branch quarter-turn, coordinate, phase, scale, source-chart and reciprocal checks. Only the certificate's typed endpoint sheets must be distinct. Missing A4 typed incidence, ambiguity or mixed orientation fails closed. Non-seam OrdinaryFront retains full equality; A7 independently checks its own cross-sheet conditions.
- **RA-34.3:** A4 owns and publishes exact A3-oriented cross-rail `τ_ab`; A5 consumes it and uses `(B_b-B_a-R_coord-τ_ab) mod4=0` with reciprocal inverse and path independence. A real-produced baseline-green HardRail witness must have **both** `(F_b-F_a) mod4 != τ_ab` **and** `τ_ab ∈ {1,3}` and reject τ sign inversion. Algebraic example `F_a=0,F_b=3,τ_ab=1,R_coord=1,B_a=0,B_b=2` is not a produced witness. Z4 commutativity prevents numerical testing of composition order; maintain typed domain semantics.

RA-33.2 periodic odd-gauge, RA-33.4 tracer-produced seam-collinear and RA-33.5 route-bearing organic positives remain unchanged and **unproven**. Entry gate is **497=30+12+449+6**; reviewed rejected run **482/497**, stable accounting **63/17/46**, debt 1. R2 Review releases ONLY bounded compile-only `M6-CP3-CB1-ENTRY-R2`. Independent A4-owned typed wedge-to-certificate sheet incidence is mandatory; if insufficient, STOP for producer-owned A4 contract Review, never manufacture an A6 map. Real-produced D2/D3/D4/D5 positives remain unproven and stop-gated. CB2 and CP3 exit remain HELD. See `Architecture_M6_DEFN_R5_R2_Review_Record.md`.

## RA-36 — HardRail route transport certificate **ACCEPTED at independent R2-P3 Review** (2026-10-08)

Resolves the `M6-CP3-CB1-ENTRY-R2` RA-34.3 stop. Full basis:
`Architecture_M6_CP3_R2P3_HardRail_Route_Transport_Review_Decision.md`.

**Singleton-only route contract is REJECTED.** A4 has no step cap
(`src/geometry/SurfaceCellTracing.cpp:11712`), so no singleton invariant exists to document; adopting one would
narrow a legitimate domain (consecutive hard edges `(1,4)`/`(4,7)` are a real producer input), and it would not
avoid fixing the miscoded failure below.

**Diagnosed error.** A5's `rail_tau` (`src/pipeline/RemeshPipeline.cpp:4916-4957`) requires *every* route step's
`SurfaceHardRailFieldTransition` record to carry the same incident-face pair as the relation's two selected
faces. Because two distinct triangles share at most one edge, any route with ≥2 distinct edges is unsatisfiable
by construction and returns `HardRailTransportMismatch` — asserting a transport disagreement never evaluated. The
rule conflates **endpoint attachment** with **transport agreement** and applies both per step; τ along a path
composes, it does not repeat.

> **RA-36.1 STATUS — PROVEN UNSOUND at `M6-CP3-TB1-ENTRY-R2-REV` (2026-10-08); owner `M6-DEFN-R5-R3`.**
> The path-connectivity clause below (*"consecutive steps share exactly one typed source face"*) is **false for
> every polyline carrier pair**: two collinear feature edges meet at a **vertex**, not a face, since a triangle
> spanning them would be degenerate. Verified counterexample on the supported 3×3 fixture — edge `(1,4)` faces
> `{0,3}`, edge `(4,7)` faces `{4,7}`, intersection empty. Implemented at
> `src/geometry/SurfaceCellTracing.cpp:18312-18321` by threading a single `current` face, it caused **25**
> `InvalidHardRailRouteCertificate` false rejections of previously accepted-green evidence (+1 `RP-01` event,
> accounting now **64 / 17 / 47**) and made A4's already-written vertex-fan junction logic at `:18337-18342`
> **unreachable**.
>
> **SUPERSEDED (2026-10-08, status updated by the reviewing agent):** the reconciliation this annotation awaited
> has completed. **`RA-37a`, accepted by `M6-DEFN-R5-R3-REV`, is the binding contract** and replaces RA-36.1's
> path-connectivity and composition clauses. RA-36.1's text below is retained as **history only** and must not
> be implemented. RA-36.4/.5/.6 remain in force, as RA-37a itself states.
> RA-36's *rejection of the singleton-only contract* is **unaffected and strengthened** — polyline carriers are
> real supported input. RA-36.4/.5/.6 stand.

- **RA-36.1:** A4 publishes, per paired cross-region HardRail route, an ordered oriented certificate: the
  canonical-orientation step sequence; per step both typed incident `SourceFaceTopologyKey` values and the exact
  oriented A3 `firstToSecond` validated against `FieldTransportAtlas::transition_value`; the **endpoint
  attachment** faces for the `a` and `b` ends; and **path connectivity** — consecutive steps share exactly one
  typed source face.
- **RA-36.2:** A5 consumes only that certificate. It composes `τ_ab` as a typed fold along the published path
  (`Z4` addition, reversed steps negate), verifies both `placement.selectedFace` values equal the published
  endpoint attachment faces, and applies the frozen `(B_b − B_a − R_coord − τ_ab) mod 4 = 0` at **both** endpoint
  pairs. The reverse relation inverts coordinate, branch and τ orientations together; orientations may not be
  mixed. A5 may not infer path, attachment or τ from regional `F` gauges, sheet labels, proximity, arbitrary
  traversal, first-step selection, fabricated records or a new unreviewed switch.
- **RA-36.3:** Consecutive side transports come from A3 source-face transition authority and must satisfy the
  cross-rail square `χ_(i+1) ∘ φ_a = φ_b ∘ χ_i`. Compose as a typed path — never average, never demand equal τ
  per carrier. A4 rejects typed fail-closed on absent/ambiguous path, disconnected face star, nontrivial singular
  holonomy, nonreciprocal A3 transitions, or a mismatching hard-feature owner.
- **RA-36.4:** Singleton is the **degenerate case** — path length 1, attachment faces are that edge's two
  incident faces, composed τ is its `firstToSecond` — and existing singleton behaviour must not regress. The
  frozen `497 = 30 + 12 + 449 + 6` gate and all currently green identities are the guard.
- **RA-36.5:** A route A4 cannot certify rejects with a typed code naming *that* cause. Reusing
  `HardRailTransportMismatch` for an uncertifiable or unsupported route is prohibited.
- **RA-36.6:** This decision grants **no runtime credit**. Existence of a produced multi-edge route is not
  established; if the bounded search finds none, the multi-edge path is unexercised and must not be cited as
  validated. All RA-34.3 R2-P3 stop gates stand — odd `τ ∈ {1,3}`, `F_b − F_a ≠ τ`, sign-inversion negative,
  reciprocal/face-permutation invariance — and an empty search **stops for Review**.
