# M6-DEFN-R1 Seam-Incident Occurrence Sheet Authority — Definition Record

**Turn:** `M6-DEFN-R1`
**Type:** Definition amendment, runtime-free
**Predecessor:** `M6-CP1-TB3-REV` review-agent addendum A2–A7
**Successor:** mandatory `M6-DEFN-R1-REV`; only after Review acceptance may re-scoped `M6-CP1-CB4` begin
**Accepted runtime authority (unchanged):** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Candidate basis (unpromoted):** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`
**Static source authority for this Definition:** source-snapshot run/artifact `36091204501 / 10846121134`, exact source/event SHA `63330339b116c8a6a56740de5b1160e8b4195992`, provider artifact digest `194e16d68da52525c35ad70079bf929d69acaf1622ceef7c5aee9728e541be99`, embedded `source.tar.gz` SHA-256 `591afb01d4e02f06e5603f1c52886659866cc1c09ba1a6a44f94d016e341f077`.

This turn changes definitions, plans, and durable records only. It does not change product source, tests, fixtures, selectors, benchmarks, or build logic, and it executes no generated Directional runtime.

## 1. Static re-derivation

The exact snapshot confirms the TB3 Review addendum rather than the held CB4 repair model.

- `bounded_disk_chart_segment(...)` resolves a segment whose midpoint belongs to more than one source triangle by choosing the lexicographically smallest triangle. That is a representation tie-break, not semantic sheet authority.
- A5 currently obtains occurrence support/component/sheet from the outgoing-side start face, while `LocalLatticeState.sourceChart` and `branchRotation` still originate from the shared node's selected face. One occurrence can therefore mix two source-face authorities.
- `OrdinaryFront` carries no semantic owner in `OccurrenceRelationId`; HardRail and Periodic do. The materializer reconstructs isolation evidence later from front-edge boundary-path routes.
- The split-square fixture is the unit square cut by seam `(v0,v2)`, with face 0 below the diagonal on sheet 0 and face 1 above it on sheet 1, and target size 0.5. Its 2×2 cell lattice therefore contains seam-incident endpoint and center occurrences whose complete cell-interior corner wedges touch both sheets.

**Process observation recurrence, +0:** this ChatGPT Web turn repeated `M6-DEFN-OBS-01` by opening several small repository documents before explicitly freezing `READ_MODE=snapshot`. No semantic conclusion or repository mutation other than the required entry beacon was accepted from those reads; all decisive static conclusions above and below were re-derived from the verified exact snapshot. Existing conservation policy already covers the pattern, so this is not a new lesson or stable regression event.

## 2. Frozen decisions

### D1 — Occurrence sheet authority is a corner-wedge sheet set

Each occurrence publishes a canonical **`CornerWedgeSheetSet`**: the sorted, unique, non-empty set of `IsolationSheetId` values of source faces covered by that cell corner's interior wedge around the exact `SourceSupport`.

- At a face-interior support the set is the single incident sheet.
- At a source-edge support it contains the sheet(s) of the one or two source faces covered by the wedge.
- At a source-vertex support it contains the sheet(s) of the contiguous source-face fan arc covered by the wedge on the cell-interior side.
- At a non-seam corner it remains a singleton, preserving current behavior.

A single `IsolationSheetId` is rejected as incomplete authority at a seam-incident corner because choosing the shared-node face or outgoing-side face silently discards another sheet that belongs to the same semantic occurrence.

### D2 — Isolation certificates live on the geometric/topological object that crosses the seam

A corner occurrence publishes **`CornerWedgeIsolationEvidence`** consisting exactly of the checked `(TopologyRegionId, SourceEdgeTopologyKey)` isolation-seam certificate references crossed by its contiguous wedge fan, in canonical seam-key order. Each reference also records the wedge traversal orientation (`fromSheet -> toSheet`); the referenced M5 certificate remains the semantic certificate and is not copied or re-invented.

A directed side publishes **`DirectedSideIsolationEvidence`** for checked seam crossings that occur in the side interior or along a seam-collinear side. These are side facts, not `OccurrenceRelationId` owner fields.

Consequences:

- `OrdinaryFront` stays owner-less and `OccurrenceRelationId` is unchanged.
- HardRail and Periodic owner semantics are unchanged.
- At a seam vertex where two seam edges separate the same sheet pair, a wedge crossing both carries two distinct certificate references because the seam-edge key is part of identity. No search or arbitrary representative is required.
- Missing/duplicate/nonmatching required seam evidence is a typed A5 construction failure.

The held relation-owned CB4 model is rejected: the relation need not geometrically cross the seam that explains an endpoint wedge's multi-sheet authority, and assigning a seam certificate to such a relation would be convention rather than derivation.

### D3 — A6 ordinary-relation validation uses endpoint wedge membership plus side evidence

For a non-seam-collinear reciprocal `OrdinaryFront`, A6 validates each endpoint pair with the side-local near-endpoint sheet already fixed by the incident cell's directed side:

```text
sideSheet ∈ firstEndpoint.cornerWedgeSheets
AND
sideSheet ∈ secondEndpoint.cornerWedgeSheets
```

Both endpoint pairs must pass. Equality of one representative endpoint sheet is not authority.

If a directed side crosses one or more isolation seams away from its endpoints, A6 consumes only the ordered `DirectedSideIsolationEvidence` published by A5 and verifies each named checked M5 certificate exactly. It may not rediscover seam authority from raw boundary paths or scan global certificate inventory.

### D4 — Seam-collinear sides are supported without a representative face

A segment lying exactly on an isolation seam is not rejected and does not use the lexicographic-triangle tie-break as semantic authority.

For each incident cell, the directed side's **interior source-face authority** is the unique incident source face lying on that cell's interior side of the directed segment, determined by exact source-chart orientation and the cell's canonical cycle. Its sheet is the cell-side sheet.

For two reciprocal ordinary sides collinear with an isolation seam:

1. both directed sides name the same checked `(region, seam-edge)` certificate;
2. their interior-side sheets are the certificate's two distinct incident sheets, in the corresponding orientation;
3. each incident-side sheet belongs to its own endpoint corner-wedge sets; and
4. the certificate, carried by the collinear sides, is the explicit authority for quotient equality across the seam.

Thus disjoint singleton wedge sets on opposite sides of a seam are legal only through this side-carried checked certificate. The ordinary relation itself remains owner-less.

### D5 — A7 lineage is the union of complete occurrence authority

For a quotient class `Q`:

```text
sourceIsolationSheets(Q) = sorted_unique(union(member.cornerWedgeSheets))
```

A7 records the wedge and directed-side certificate evidence that A6 actually verified while establishing the quotient relation closure. A7 must not pick one member, face, or sheet as representative authority. The former wording “relation certificates establish equivalence” is replaced by “A5-published wedge/side certificates verified by A6 establish every cross-sheet step that requires certification.”

### D6 — Face-dependent provenance is per wedge/side; no mixed-face occurrence record

The exact `SourceSupport`, `CellId`, `canonicalCornerRole`, `TopologyRegionId`, lattice coordinate, phase, and scale level are occurrence-wide values. Face-dependent values are not occurrence-wide representatives.

A seam-incident occurrence publishes ordered **`CornerWedgeFaceBindings`** for the contiguous faces of its wedge. Each binding carries the source-face topology identity, isolation sheet, exact field-chart binding, and branch rotation for that face. If implementation retains a `LocalLatticeState` object, only face-independent values may remain single-valued there; `sourceChart`/`branchRotation` must be moved or repeated per wedge binding. The semantic record may not combine sheet/support from one face with chart/branch from another.

### D7 — Row140 compatibility belongs at the adapter; duplicate downstream ownership checks are removed

A5 owns occurrence/relation structural failures in the `Occurrence*` vocabulary. `HardRailOwnerMismatch` becomes externally named **`OccurrenceHardRailOwnerMismatch`**. The legacy row140 string `InvalidHardRailTransport` is preserved only at the transitional M5-compatible adapter boundary that maps the new A5 failure to the accepted legacy failure surface.

The following downstream checks are deleted when CB4 moves their structural responsibility into A5, rather than retained as a second semantic authority:

- `MissingHardRailRelationOwner`;
- the owner-presence/equality half of `InvalidPeriodicRelationOwner`;
- the boundary-kind compatibility half of `IncompatibleAuthoritativeFrontPair` already proven by the A5 relation kind/owner contract.

Downstream checks that validate transport content after the owner has been accepted remain. In particular, route reversal, non-zero periodic shift, checked periodic relation content, and exact transport/application checks are not removed.

### D8 — CB4/TB4 are re-scoped; the acceptance surface grows by one focused identity

`M6-CP1-CB4` implements D1–D7 and no broader semantic change. The exact new pre-registered focused identity is:

`M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`

It asserts the split-square endpoint occurrences at v0 and v2 each publish `{sheet0,sheet1}` and the expected wedge certificate reference/orientation. The existing six focused identities remain byte-unchanged. Selector449 and routing449 remain byte-frozen.

TB4 therefore executes **7 focused + selector449 = 456 fresh exact-filter processes**. Recovery-green is **456/456 PASS** with immutable postflight and no benchmark. A mechanically valid RED goes directly to `M6-CP1-TB4-REV`; no TB repair or rerun is authorized.

## 3. Independent worked example — split square

Assumptions independently re-derived from the exact fixture and tracer: uv=xy on `[0,1]^2`, target size `0.5`, cell corner order `BL, BR, TR, TL`, directed side `s` from corner `s` to `s+1`, face 0 `(v0,v1,v2)` below diagonal `(v0,v2)` on sheet 0, face 1 `(v0,v2,v3)` above it on sheet 1.

At a corner, the wedge is traversed from the last positive-length incoming side segment to the first positive-length outgoing side segment through the cell interior. This yields:

| cell | corner 0 | corner 1 | corner 2 | corner 3 |
|---|---|---|---|---|
| `c00=[0,½]^2` | `v0: {0,1}`, cert `e` `1→0` | `(½,0): {0}` | `(½,½): {0,1}`, cert `e` `0→1` | `(0,½): {1}` |
| `c10=[½,1]×[0,½]` | `(½,0): {0}` | `v1: {0}` | `(1,½): {0}` | `(½,½): {0}` |
| `c01=[0,½]×[½,1]` | `(0,½): {1}` | `(½,½): {1}` | `(½,1): {1}` | `v3: {1}` |
| `c11=[½,1]^2` | `(½,½): {0,1}`, cert `e` `1→0` | `(1,½): {0}` | `v2: {0,1}`, cert `e` `0→1` | `(½,1): {1}` |

The orientation follows directly from incoming/outgoing cell sides. For example, `c00.0` arrives along the left side in face/sheet 1 and leaves along the bottom side in face/sheet 0, hence `1→0`; `c00.2` arrives through sheet 0 and leaves through sheet 1, hence `0→1`.

Expected lineage authority is therefore:

- v0: `{c00.0}` with union `{0,1}`;
- center `(½,½)`: `{c00.2,c10.3,c11.0,c01.1}` with union `{0,1}`;
- v2: `{c11.2}` with union `{0,1}`;
- every other lattice vertex: singleton sheet authority.

The four interior reciprocal sides yield eight endpoint pairs. Each non-collinear pair has a unique incident side sheet contained in both endpoint wedge sets. Example: the lower horizontal/vertical adjacency endpoint pair `(c00.2,c10.3)` uses side sheet 0 and `0 ∈ {0,1} ∩ {0}`. The other seven follow identically by the exact cell position: left-of-center uses sheet 1, below/right-of-center uses sheet 0, and above-center uses sheet 1.

### Interior seam-vertex chain

Let seam edges `e_a=(v_a,v)` and `e_b=(v,v_b)` meet at source vertex `v` and separate sheets `s|t`. Because certificate identity includes the canonical seam-edge key:

- a wedge crossing neither edge has singleton `{s}` or `{t}` and no wedge certificate;
- a wedge crossing only `e_a` has `{s,t}` and exactly certificate `(R,e_a)`;
- a wedge crossing only `e_b` has `{s,t}` and exactly certificate `(R,e_b)`;
- a wedge whose contiguous fan crosses both has `{s,t}` and exactly the sorted pair `{(R,e_a),(R,e_b)}`, with each traversal direction derived from the fan order.

Even when both certificates encode the same unordered sheet pair, the set is unambiguous because `e_a != e_b`. This is the decisive counterexample to a relation-owned “one certificate for the sheet pair” model.

## 4. Frozen invariants and explicit non-goals

Unchanged: `OccurrenceId=(CellId,canonicalCornerRole)`, `CellId`, `QuotientClassId`, relation-only quotient equality, HardRail/Periodic semantic owners, no geometric welding, selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, existing tests/fixtures, accepted M5 runtime authority, stable accounting **54 / 16 / 38**, debt **1**.

No selector is published or accepted by this turn. No candidate is promoted. No runtime, compile, benchmark, fixture edit, or product/test-source edit is authorized.

## 5. Successor falsifiers

`M6-DEFN-R1-REV` must reject or amend this definition if independent re-derivation shows any of the following:

1. a corner wedge at source-edge or source-vertex support cannot be derived uniquely from the accepted A4 canonical cycle and exact source topology without choosing a representative face;
2. seam-collinear incident-cell side authority cannot be determined exactly from source-chart orientation and canonical cell interior;
3. the split-square v0/v2 sheet/certificate table is incorrect;
4. A6 would need to search global certificate inventory or infer equality from position/lattice coincidence;
5. the row140 adapter policy weakens an accepted M5 transport/content check rather than removing only duplicated structural ownership checks; or
6. any proposed implementation requires changing selector449/routing449, existing six focused identities, `OccurrenceId`, quotient equality, or HardRail/Periodic owner semantics.

## 6. Required closeout

| Review/Definition duty | M6-DEFN-R1 disposition |
|---|---|
| Accepted selector prefix re-hashed | selector449 LF SHA-256 `d4a0d1b7…d6414`; selector byte unchanged |
| Decisive claims independently re-derived | exact snapshot `63330339…`; split-square 2×2 geometry, mixed-face occurrence, relation owner shape, materializer seam reconstruction, seam-collinear representative tie-break |
| Non-vacuity checked | v0/v2 single-occurrence completeness gap and interior seam-vertex two-edge example |
| Prior obligations discharged/carried | TB3 addendum A7.1–A7.9 frozen here; stable accounting/debt carried unchanged |
| Stable accounting | **54 / 16 / 38**, debt 1 |
| New candidates/obligations recorded | no runtime candidate; CB4/TB4 re-scope and review falsifiers recorded |
| ORIENTATION currency line | updated to `M6-DEFN-R1`, runtime-free, Review next |
| ORIENTATION §3 / §4 / §7 / §8 | current state/open obligations/successor updated; no accepted runtime authority changed |
| CHANGELOG | agent and root changelogs updated |
| ROADMAP | M6 CP1 Definition interlock and successor updated; checkpoint acceptance unchanged |
| Selector manifest | n/a — no selector added/published/accepted |
| LESSONS | existing Lesson 179 applies; no new lesson |
| Consolidation under CLEAN_UP_POLICY | no destructive consolidation in this Definition turn; current plan retained for `M6-DEFN-R1-REV` to fold/index under standing Review authority |
| Successor frozen | `M6-DEFN-R1-REV` only; CB4 remains held until Review acceptance |
| Turn boundary held | runtime-free documentation/planning only |
| `review_check.py boundary` | **PASS** with declared selector449 SHA; no product/test/fixture/build or selector mutation; durable markers preserved |
| STATUS lifecycle maintained | entry beacon published first; final beacon is reserved as final repository write |
| Pushed to origin, branch in sync | **CONFIRMED.** Drive patch run `36092706709` / apply job `107938329647` / result artifact `10845388776` pushed definition commit `02143b8e1375bfdca939989af6a709f8b17c9468`; workflow reported owner cleanup required and owner-side Drive deletion succeeded. Temporary caller retirement commit `b1bc763ea3b45ccfd358c88f6a97429f15a174ee` preceded cleanup run `36092795885` / cleanup job `107938556572` / result artifact `10846695480`, which pushed cleanup commit `b184b202669c83b58bd6a3730a3d639d88d263b9` and removed both inventoried trigger paths. This closeout record write is repository-native on the target branch; final `STATUS` is the only remaining repository write. |
