# Architecture M3 CP4c-1 — TB-R2 Review + Plan

**Turn:** `M3-CP4c-1-TB-R2-REVIEW-PLAN`
**Type:** Review + Plan only — no product, test, fixture, selector, or build mutation; no compile, package, or runtime
**Evidence under review:** TB run/job `32851859581 / 97814494564` on immutable package `9553525746`, semantic source `2888dbdcf5aaf27fd629a5d29cbd57bc7d63e4f0`
**Result under review:** **VALID RED 316/318** — accepted prefix 316/316 PASS, C4 and C5 FAIL
**Binding workflow:** `CB → TB → (red) → REVIEW+PLAN → CB`. This red consumes nothing.

---

## 0. Dispositions

| # | Subject | Disposition |
|---|---|---|
| **F1** | Y2 (mechanical discriminator) | **Delivered.** Resolved to `fieldTransportAdjacencyExists=false` with valid `EF` rows — missing adjacency, not a negative row. |
| **F2** | Y5 prediction 1 (sphere reaches A1) | **CORRECT.** The sphere establishes source topology and the atlas. |
| **F3** | Y5 prediction 2 (sphere reaches A2a with 24 traces) | **FALSIFIED.** A2a rejects `InvalidCandidateTraceTransport`. |
| **F4** | The cause | **Production defect in A1, provable from source without running anything.** `FieldBranchBoundaryPairing.connections` is the **Cartesian product** of inflow × outflow carriers. It is not a pairing. §3. |
| **F5** | Scope of the defect | **Generic, not witness-specific.** The three barycentric derivatives sum identically to zero, so ~half of all faces on **every** mesh carry an ambiguous continuation. It is latent in accepted authority. §3.4. |
| **F6** | Against DESIGN | **`DESIGN.md` §4.5 already specifies the correct mechanism and half of it was never implemented** — barycentric positions are not propagated, so the pairing cannot be resolved. §4. |
| **F7** | Witness-side vs production-side (the mandated question) | **Production-side, unambiguously.** No change to the sphere's field, ports, or branches can fix it. §5. |
| **F8** | CP4c-1 | **Cannot close.** A new predecessor checkpoint `M3-CP4c-0` is required. **Do not demote C4/C5 to non-gating.** §6. |

Accepted authority is untouched: **316/316 PASS in the same immutable run.** Stable accounting stays **42 / 14 / 28**; produced-witness debt stays **5**.

---

## 1. Evidence — independently verified

Verified against the GitHub Actions API:

| Check | Result |
|---|---|
| Run `32851859581`, head `c13661c7d352be482bcb727eb70b15d42752b607` | matches |
| Result artifact `9564681836` | `sha256:2febb8c314323009853a5cbdcaa8cd1000692f886654da2fba7039173a987df0` — exact |
| Control artifact `9564682452` | `sha256:d990338a12c40770fe33a0ef66a55456d74430dadca153643867ffc62e0f44a7` — exact |
| Schema validation ran before execution | `32851669919`, plus in-run validator artifacts |

**321 fresh processes** — 318 required plus 3 non-gating — one identity each, zero orchestration errors, every mutation/build flag false, byte-identical pre/post source and package inventories, `SHA256SUMS` 27/27 both times. **Clean VALID RED.**

---

## 2. What Y1–Y3 delivered

**Y2 worked exactly as designed.** The mechanical A1 failure was ambiguous between two sites after TB-R1; the extended observation now reports `fieldTransportAdjacencyExists=false` with `globalEF=1,158` and `localEF=1,158` both valid, and `localBoundaryEdges=0`. That is **candidate 1** — a missing `FieldTransportAdjacency` — and **not** the negative-`EF` candidate. One measurement, question closed. That evidence is now CP4c-3's input and is not re-litigated here.

**Y1 and Y3 also worked.** The sphere was admitted to the union with a guarded pattern and a self-precondition; the precondition stopped the test honestly rather than letting a vacuous pass through. C4/C5 fail for a truthful reason.

**My Y5 prediction 2 was falsified, and the falsification is the most valuable result in this run.** I predicted the sphere would publish 24 traces. It publishes none — A2a rejects before any network exists. Chasing the prediction would have been wrong; the evidence points somewhere better.

---

## 3. F4 — the root cause, proven from source

### 3.1 Where the rejection comes from

`canonical_field_aligned_traces` (`src/geometry/SurfaceCellTracing.cpp:352-420`) emits `InvalidCandidateTraceTransport` at four sites. Three of them carry a non-null `sourceEdge`, which the observation shows as `1-2`:

| Site | Condition | `sourceEdge` reported |
|---|---|---|
| `:367-371` | branch pairing not found for the frame | `std::nullopt` — **excluded by the evidence** |
| `:379-383` | `field_aligned_outgoing_carrier` returned `nullopt` | `incomingCarrier` |
| `:394-399` | `field_aligned_next_face` found no unique opposite face | `outgoingCarrier` |
| `:402-407` | `topology.transport(...)` returned `nullopt` | `outgoingCarrier` |

The first step of a trace has `incomingCarrier == std::nullopt`, so a **non-null** `sourceEdge` at `:379` proves the trace completed **at least one segment** before failing. That single fact already refutes "the sphere's port attachment is malformed" — the attachment worked.

### 3.2 The pairing is a Cartesian product, not a pairing

`build_branch_boundary_pairing`, `src/authority/FieldTransportAtlas.cpp:145-170`:

```cpp
const double derivative = dbary[static_cast<std::size_t>(opposite[index])];
FieldBoundaryFlow flow = FieldBoundaryFlow::Tangent;
if (derivative > kBranchTopologyTolerance) {
  flow = FieldBoundaryFlow::Inflow;
  pairing.incomingCarriers.push_back(*edge);
} else if (derivative < -kBranchTopologyTolerance) {
  flow = FieldBoundaryFlow::Outflow;
  pairing.outgoingCarriers.push_back(*edge);
}
…
for (const SourceEdgeTopologyKey &incoming : pairing.incomingCarriers) {
  for (const SourceEdgeTopologyKey &outgoing : pairing.outgoingCarriers) {
    pairing.connections.push_back(
        FieldBranchBoundaryConnection{incoming, outgoing});
  }
}
```

**`connections` is every inflow paired with every outflow.** It records which edges are inflow and which are outflow; it does **not** record which outflow edge a trace entering through a given inflow edge actually reaches.

A2a then demands a unique answer — `field_aligned_outgoing_carrier`, `SurfaceCellTracing.cpp:270-281`:

```cpp
for (const FieldBranchBoundaryConnection &connection : pairing.connections) {
  if (connection.incomingCarrier == *incomingCarrier) {
    outgoing.push_back(connection.outgoingCarrier);
  }
}
std::sort(outgoing.begin(), outgoing.end());
outgoing.erase(std::unique(outgoing.begin(), outgoing.end()), outgoing.end());
return outgoing.size() == 1U
           ? std::optional<SourceEdgeTopologyKey>{outgoing.front()}
           : std::nullopt;                       // ← two outflow carriers ⇒ failure
```

So: **a face with one inflow edge and two outflow edges makes the continuation ambiguous, and A2a fails.**

### 3.3 The geometry says the continuation genuinely is not determined

A straight line entering a triangle through one edge exits through exactly one of the other two — and **which one depends on where along the entry edge it enters**. The pairing carries no entry position. It therefore *cannot* determine the continuation, and the Cartesian product is an honest representation of the information it holds. The defect is that the information was never captured.

### 3.4 F5 — this is generic, not a sphere quirk

`src/authority/FieldTransportAtlas.cpp:118`:

```cpp
const std::array<double, 3> dbary{-u - v, u, v};
```

**The three barycentric derivatives sum identically to zero, by construction.** For any non-degenerate branch direction, that forces exactly one of them to have one sign and the other two the opposite sign. Combined with the build's own requirement that a face have at least one inflow and one outflow (`:156-162`, else `InvalidBranchBoundaryFlow`), every non-tangent face is one of:

- **2 inflow / 1 outflow** — each incoming carrier maps to exactly one outgoing → fine;
- **1 inflow / 2 outflow** — the single incoming carrier maps to **two** outgoing → `nullopt` → `InvalidCandidateTraceTransport`.

**Roughly half of all faces, on every mesh in the repository, are in the failing configuration.** This is a latent defect in accepted A1/A2a authority.

It has stayed hidden for a precise, checkable reason: on the accepted witnesses — the two-ring skew disc and the four-triangle fan, both bounded discs — **every trace terminates on a mandatory boundary barrier within one or two segments** and never traverses an ambiguous face. The torus never reaches it either, because it publishes zero traces. The prescribed sphere is the first witness whose traces run far enough to meet one.

---

## 4. F6 — measured against `DESIGN.md` §4.5, half the primitive is missing

`DESIGN.md` §4.5, normative for A2a:

> Ray and Sokolov … trace field-aligned polylines that provably cannot cross or merge. Each triangle boundary is decomposed into inflow and outflow intervals; **the pairing is resolved by a guaranteed combinatorial algorithm, and barycentric positions propagate in arbitrary precision** rather than by numerical integration.
>
> … positions are **exact barycentric values compatible with `SourceSupport`** …

Against the implementation:

| §4.5 requirement | Implemented? |
|---|---|
| boundary decomposed into inflow/outflow intervals | **Yes** — `pairing.intervals`, `FieldBoundaryFlow` per edge |
| pairing **resolved** by a combinatorial algorithm | **No** — replaced by the Cartesian product |
| **barycentric positions propagate** | **No** — no position field exists anywhere on a trace |
| positions are exact values compatible with `SourceSupport` | **No** |

`FieldAlignedCandidateTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:194-213`) carries `sourceFace`, `branch`, `incomingCarrier`, `outgoingCarrier`, `entryTransport` — and **no position of any kind**. This is the same missing datum recorded during the CP4ab DG-R4 review, where its absence was correctly established for the terminus question. **One missing datum, two symptoms:** the terminus could not be located along its barrier edge, and the interval pairing cannot be resolved.

**The pairing cannot be resolved without the positions.** They are the same work.

---

## 5. F7 — the mandated question, answered

TB-R2's report asks the review to decide whether the smallest valid correction is **witness-side** (field / port / branch validity) or **production-side** (tracing/transport semantics).

**Production-side, and no witness change can help.** Three independent reasons:

1. **The trace completed at least one segment** (§3.1), so the attachment, the start face, the first outgoing carrier, and the branch were all valid. The witness's field and ports work.
2. **The failing configuration is a property of triangle geometry, not of the field's quality.** `dbary` sums to zero for *any* direction, so no better field removes 1-inflow/2-outflow faces.
3. **The accepted witnesses have the same ambiguous faces**; they merely never traverse one. Changing the witness only changes *when* the defect is met.

**Explicitly rejected alternatives**, each of which would be a worse outcome than an open checkpoint:

- **Resolving the ambiguity inside A2a** — prohibited. A2a would become a second writer of transport semantics, violating `DESIGN.md` §7.3 single-writer authority and §15's stop conditions.
- **Picking one outflow carrier by any tiebreak** — identifier order, container order, larger derivative magnitude, nearest direction. All are the "nearest-direction heuristic" §4.5 exists to forbid, and all silently produce a wrong trace rather than a typed failure.
- **Choosing a different witness** — the defect is generic; a different witness relocates the symptom.
- **Weakening C4/C5** — prohibited three reviews running, and still prohibited.

---

## 6. F8 — CP4c-1 cannot close; insert a predecessor

CP4c-1's domain is *diagnosability, witness observability, event non-vacuity*. Its gate is **318 = 316 + C4 + C5**. C4/C5 cannot pass until a witness produces a terminal `TraceIntersection`, and no witness can until the pairing is resolved.

### 6.1 Do not demote C4/C5 to non-gating

It is tempting: the non-gating register exists, the workflow allows it, and CP4c-1 would go green.

**Reject it.** Demotion here would let CP4c-1 close on work that is not its stated purpose — event non-vacuity is the *whole* point of the checkpoint, and a green gate that excludes it would misreport the project's state. The M1 inherited-baseline-red register is not a precedent: there the blocked preconditions are owned by *later* milestones, whereas here the precondition is owned by an **immediate predecessor** that is about to be scheduled. Under the abolished-budget workflow an open checkpoint costs nothing, so there is no pressure to close it.

C4/C5 stay **gating** and CP4c-1 stays **open**.

### 6.2 New checkpoint `M3-CP4c-0`

Inserted **before** CP4c-1 as a blocking predecessor.

| Checkpoint | Domain | Gate |
|---|---|---|
| **`M3-CP4c-0`** | **resolved interval pairing with propagated barycentric positions in A1/A2a** — `DESIGN.md` §4.5 | 316 + its own identities, frozen by its DEFN |
| `M3-CP4c-1` | diagnosability, witness observability, event non-vacuity | 318, **blocked on CP4c-0** |
| `M3-CP4c-2` | closed / higher-genus region authority in A2b | 321, needs its DEFN |
| `M3-CP4c-3` | closed-surface missing field-transport adjacency in A1, then the mechanical witness | 322, needs its DEFN |

**Gate arithmetic for CP4c-0 is deliberately not fixed here.** Freezing an identity count before the domain is defined is the failure `M3-CP4-DEFN` was created to prevent. Its DEFN freezes it.

---

## 7. Corrective measures — series **Z**

### Z0 — binding preconditions

Each is a stop condition; if one does not hold, stop and return to review.

- **Z0.1** Confirm from the packaged source that `pairing.connections` is built as the full Cartesian product of `incomingCarriers` × `outgoingCarriers` (`FieldTransportAtlas.cpp:164-169`) and that `field_aligned_outgoing_carrier` requires exactly one match (`SurfaceCellTracing.cpp:270-281`). If either differs, **stop** — §3 is wrong.
- **Z0.2** Confirm `dbary` is constructed as `{-u - v, u, v}` (`FieldTransportAtlas.cpp:118`), so the three derivatives sum to zero. If not, **stop** — §3.4's genericity argument fails.
- **Z0.3** Confirm `FieldAlignedCandidateTraceSegment` carries **no** position field (`SurfaceCellTracing.h:194-213`). If a position field exists, **stop** — §4 is wrong.
- **Z0.4** Do **not** modify C4, C5, the witness union, or any accepted expectation.
- **Z0.5** Do **not** attempt the pairing fix in this turn. Z1–Z3 are **measurement and planning only**.

### Z1 — measure the ambiguity, on every witness, as a non-gating identity

Add one **non-gating** identity:

- `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique`

For each witness whose atlas is published — two-ring, four-triangle fan, torus, mechanical (if it ever reaches A1), prescribed sphere — iterate **every** `FieldFaceBranchFrame` and every `FieldBranchBoundaryPairing`, and report:

- total frames and pairings inspected;
- the distribution of `(incomingCarriers.size(), outgoingCarriers.size())`;
- the **count and percentage** of pairings where some incoming carrier has **more than one** distinct outgoing carrier — i.e. where `field_aligned_outgoing_carrier` would return `nullopt`;
- for the prescribed sphere specifically, whether the failing face is among them, with its `sourceFace`, its inflow/outflow edge sets, and the multiplicity for incoming carrier `1-2`.

This uses only **published authority**; it changes no product and constructs nothing. It settles §3.4 for every witness at once, including the accepted ones.

**This is the whole point of the turn.** If the accepted witnesses show ambiguous pairings that their traces simply never traverse, the defect is proven latent in accepted authority and CP4c-0 is justified on measurement rather than on my reading of the source.

### Z2 — pin the sphere's failure site exactly

Extend the prescribed-sphere reachability observation to report which of the three candidate sites fired:

- the number of segments the trace completed before failing (≥1 proves the attachment was valid);
- whether the failing call was `field_aligned_outgoing_carrier` (`:379`), `field_aligned_next_face` (`:394`), or `topology.transport` (`:402`) — report the site, not just the code;
- whether a `FieldBranchTransportAdjacency` exists for edge `1-2`;
- the current face at failure, and its inflow/outflow classification.

Non-gating. **Do not fix anything.**

### Z3 — author `M3-CP4c-0-DEFN` as the next planning turn's charter

Record, for the DEFN to freeze — do **not** decide these now:

1. **The position representation.** §4.5 requires *"exact barycentric values compatible with `SourceSupport`"*. The DEFN must decide the exact type, its ID domain, its single writer, and whether `SourceSupport` is reused or a new typed value is introduced. Note the CP4ab precedent: the network's 0-cells are combinatorial identities, and adding positions must not turn `NetworkNodeId` into a coordinate.
2. **The resolution algorithm.** Ray–Sokolov's guaranteed combinatorial pairing, stated precisely enough to implement, with its typed rejection vocabulary and named loci.
3. **The transport contract change.** Whether `FieldBranchBoundaryPairing.connections` becomes a function (one outgoing per incoming, given a position) or is replaced, and what happens to the existing `intervals`.
4. **The re-proof surface.** Which accepted CP1/CP2/CP2b/CP3a/CP3b/CP4ab identities can change, and why reopening them is unavoidable. **This is the item most likely to be underestimated** — A1's semantic digest almost certainly changes, and every relative digest assertion must be re-examined.
5. **Witness stage reachability**, per the rule added at CP4c-1: for every witness the DEFN names, which product stage it has been **proven** to reach.
6. **Whether the terminus datum is unified with this work.** The CP4ab terminal 0-cell and this pairing failure are the same missing barycentric position. The DEFN should state explicitly whether CP4c-0 also supersedes the amendment-11 combinatorial terminus, or leaves it untouched.

### Z4 — no gate change in this CB

CP4c-1's required gate stays **318**. Non-gating identities go from 3 to **5** (torus, mechanical, sphere, Z1's pairing census, and Z2's site-pin if authored separately). C4/C5 remain gating and remain red. **The next TB is expected to return 316/318 again** — that is the correct outcome, and it is not a failure of this plan.

### Z5 — falsifiable predictions

1. Z1 reports **more than 0%** of pairings ambiguous on the two-ring witness and on the four-triangle fan. *If accepted witnesses show zero ambiguous pairings, §3.4's genericity argument is wrong and the defect is witness-specific — return to review.*
2. The ambiguous fraction is **near half** on every witness with a non-degenerate field.
3. Z2 reports the sphere's failure at **`field_aligned_outgoing_carrier` (`:379`)**, with **≥1** completed segment and multiplicity **2** for incoming carrier `1-2`. *If it reports `:394` or `:402` instead, the cause is a missing branch transport rather than an unresolved pairing — that is a different defect, closer to the mechanical one, and the review must be redone.*
4. The accepted **316 remain green** — Z1/Z2 are observation-only.
5. C4/C5 remain red for the unchanged reason.

Prediction 3 is the one that decides CP4c-0's charter. **Do not adjust it to match the observation.**

---

## 8. Accounting and exact successor

- accepted runtime authority: **M3 CP4ab 316/316**, source/package `157bf784… / 9527801615`
- CP4c-1 gate: **318**, unchanged; **C4/C5 stay gating**; CP4c-1 stays **open**
- non-gating diagnostics: 3 → **5**
- budgets: none; this red consumed nothing
- stable regression accounting: **42 / 14 / 28** — unchanged, no accepted identity regressed
- produced-witness debt: **5**
- M3 package count: **38** before the next CB
- new checkpoint **`M3-CP4c-0`** inserted as a blocking predecessor to CP4c-1
- `M3-CP4c-2-DEFN` and `M3-CP4c-3-DEFN` remain blocked

**Exact next: `M3-CP4c-1-CB3`** — Code + Build only, runtime forbidden. Execute Z0's preconditions, then Z1, Z2, Z3, Z4. **Observation and planning only: no production translation unit may change.** Compile and package; execute nothing. Then `M3-CP4c-1-TB-R3` on the **318** gate plus five non-gating identities, expecting **316/318** with the pairing census as its deliverable.

`M3-CP4c-0-DEFN` follows once Z1/Z2 confirm the charter.
