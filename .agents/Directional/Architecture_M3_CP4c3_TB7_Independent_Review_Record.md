# M3-CP4c-3-TB7 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB7-REV`
**Type:** independent REVIEW + PLAN. Static only.
**Governing scope:** `Architecture_M3_CP4c3_TB7_Independent_Review_Plan.md`, measures **AW0–AW7**.
**Runtime/build boundary honoured:** no Directional runtime, compile, link, package, benchmark, or
product/test/fixture/selector mutation was executed or authored in this turn. Every derivation below is a static
reading of the exact packaged source `e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a` and of committed fixture bytes.

---

## 1. Executive adjudication

**Both TB7 reds are now explained, and they have different owners.**

1. **Ordinal 366 is a CB9-introduced product defect, not a recurrence of TB5.** CB9's `AY1` seed construction added a
   **fifth** seed guard that did not exist in the source TB6 ran: the reversed arrival ray must satisfy the
   **half-open** sector predicate `direction[next] > 0 ∧ direction[previous] ≥ 0` in the arrival face. That predicate
   is an *ownership* convention — it partitions a fan by deliberately excluding one of the two radial rays — and CB9
   reuses it as an *admissibility precondition on an incoming ray*. An arrival ray that lies exactly on the excluded
   radial ray is therefore declared invalid, although it is a perfectly ordinary arrival: it is what a trace running
   along a mesh edge produces. §3 proves from the committed fixture that this is exactly what happens at source
   vertex 11.
2. **Ordinal 374 is an invalid witness precondition with a legitimate product rejection — AW4 classification 1.**
   The folded-cone fixture has cone angle `Θ = 3π/2` at its center, hence angle defect `K = π/2`, while its field
   helper declares **zero effort on every edge and zero singularities**. Discrete Gauss–Bonnet then forces the
   center's cycle lift to `1`, which contradicts both the declared matching (which composes to `0`) and the declared
   singularity set (empty). `FieldTransportAtlas::make` is right to refuse it. §5 derives the exact failing check.

**Neither red licenses the repair the other needs.** The plan's own instruction therefore governs the successor:
freeze the earlier gating owner and defer the second. §8 freezes **`M3-CP4c-3-CB10`** under measures **AZ0–AZ9**,
a product correction; §5.5 records the ordinal-374 corrective as a specified but unauthorized deferral.

**Amendment 22 and Amendment 23 survive intact.** Nothing in this review requires a new semantics. The seed
contract in `DEFN-R2` §AX1 never imposed the guard CB9 added, and `DEFN-R2` §AX7 §7.2 item 5 *required* a seed
"placed exactly on a radial ray" to be supported. CB9 made that case unreachable in `FaceInterior` mode and then
wrote its third AY5 instance in `EdgeTransit` mode to route around its own restriction. §6.

**Accepted authority is unchanged at 365/365. Stable accounting is unchanged at 44 / 14 / 30, debt 5, semantic M3
packages 74.** This review is static and loses no accepted-green behaviour: **+0 events / +0 recurrences**.

---

## 2. AW0 — immutable evidence re-established

### 2.1 Independently recomputed from committed bytes

Selector authority was recomputed locally from `Architecture_M3_CP4c3_Required_Green_Selector_374.txt`, not copied
from prose, per the standing rule that a transcribed digest is not evidence.

| quantity | recomputed value | agrees with frozen record |
|---|---|---|
| selector 374 SHA-256 | `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f` | yes |
| selector 374 line count / unique identities | 374 / 374 | yes |
| `head -316` | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` | yes |
| `head -346` | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` | yes |
| `head -353` | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` | yes |
| `head -355` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` | yes |
| `head -357` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` | yes |
| `head -361` | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` | yes |
| `head -365` | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` | yes |
| `head -367` | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` | yes |
| `head -370` | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` | yes |
| `head -373` | `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834` | yes |

Every value is exactly 64 lowercase hex characters. Selector **373 is byte-frozen as a prefix of 374**, and every
accepted predecessor prefix still reproduces its own frozen hash, so `first_red_ordinal` remains comparable across
the whole CP4c arc.

### 2.2 Semantic-source identity

The working-branch tree at review time is **byte-identical to CB9's semantic source
`e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a`** across `src/`, `include/`, `tests/`, `benchmarks/` and
`CMakeLists.txt` (`git diff --stat` is empty for those paths). Every static derivation below therefore reads the
same bytes package 76 was built from. No branch-head build product and no locally rebuilt binary was used; nothing
was compiled.

### 2.3 TB7 runtime authority consumed as evidence only

Package 76 `9811964367`, run/job `33541437165 / 99968443127`, result `9813862211`
(`814157162acfb95e785d4f5af3c886696534a0972942ac1f685d64b1c04086f0`), log `9813862640`
(`188d02d98928ccaf29d2e899918e487c35c186b96550044ac0138d48defea1a4`). Ordinals **1–365 PASS**, first red **366**,
report-only 367–374 **1 PASS / 7 RED**, immutable pre/postflight PASS with every configure/compile/relink/repair/
generatedDiscovery/mutation/benchmark flag false. The review re-uses these facts; it does not re-derive them and it
did not rerun anything.

---

## 3. AW1 — the source-vertex-11 arrival and seed authority, reconstructed exactly

### 3.1 What CB9 changed

`resolve_field_vertex_transit` in the **pre-CB9** source (`e5d6ed76^`, the source TB6 ran) has exactly **four**
seed guards: frame present, component/region match, unique branch pairing, `direction.is_barycentric()`. CB9 added
a **fifth**, `src/geometry/SurfaceCellTracing.cpp:1289-1300`:

```
arrivalRay = −currentPairing->direction                      // exact negation, correct per AX1
currentRow = field_face_row(sourceMesh, currentFace)
if (!currentRow || !direction_in_vertex_sector(sourceMesh, *currentRow, sourceVertex, arrivalRay))
    → SeedDirectionNotBarycentric → VertexTransitSeedUnavailable
```

`direction_in_vertex_sector` reduces to `direction_in_incident_vertex_sector`
(`src/authority/FieldTransportAtlas.cpp:404-426`), whose whole body is the **half-open** predicate

```
direction[nextIndex] > 0  ∧  direction[previousIndex] ≥ 0
```

with the source comment stating its purpose: *"Exact half-open fan partition: include the next-vertex ray and
exclude the previous-vertex ray."* It is a partition rule for assigning **one owner** among the fan's sectors. CB9
applies it to decide whether the **arrival** is admissible at all.

### 3.2 When the new guard can fail — exhaustively

Let the arrival face's canonical key be `(v_a, v_b, v_c)` (`SourceFaceTopologyKey::make` sorts, and every index in
both `pairing.direction` and `direction_in_incident_vertex_sector` is resolved **by vertex identity**, so the two
agree). Let `d` be the branch direction, `Σd = 0`, `d ≠ 0`.

- **`|M| = 2` (the ordinary T2 vertex transit).** The hit vertex is the index *not* in `M`, so `d[hit] > 0` and both
  others are `< 0`. Then `arrivalRay = −d` has `next > 0` and `previous > 0`: **the guard always passes.**
- **`|M| = 1` with a vertex landing (Amendment 3).** `resolve_field_branch_continuation` returns `VertexHit`
  whenever an `|M| = 1` exit point's `source_support()` is a vertex. That is possible only when some coordinate `k`
  satisfies `d[k] = 0` **exactly** and `p[k] = 0` at entry — i.e. the trace runs along the mesh edge opposite `v_k`
  and lands on its far endpoint. Then `arrivalRay[k] = 0`, and the guard **fails precisely when `k` is the `next`
  vertex** of the hit corner and passes when it is the `previous` vertex.

`field_face_row` cannot be the failing half: the arrival face reached A2a through the atlas and is row-indexed by
construction. Guards 1–3 are also unreachable here — the caller already resolved the frame and this exact pairing
before calling (`SurfaceCellTracing.cpp:2175`), frames always publish exactly four branches (one per semantic
index, `build_face_branch_frame`), and the mechanical witness has a single topology region `0` over all 300 faces,
which is the region TB7 published. Guard 4 is likewise unreachable: `build_boundary_pairing` fails the whole atlas
with `BranchDirectionNotBarycentric` if the exact direction is not barycentric, and a zero coordinate does not make
it non-barycentric (`is_barycentric()` requires only `Σ = 0` and `≠ 0`).

**So the fifth guard is the only guard that can fail at this arrival, and it fails only on an Amendment-3
edge-collinear landing whose back-ray is the arrival face's excluded radial ray.**

### 3.3 The exact proof at source vertex 11

Computed from the committed fixture bytes
`benchmarks/fixtures/milestone-g/mechanical_feature.{obj,rawfield}`, reproducing
`build_face_branch_frame` / `build_boundary_pairing` step for step.

- The face `(8,10,11)` is mesh **row 8**, with corner order `F(8,·) = [8, 10, 11]`.
- Its four canonical branch directions, in canonical-key order `(v8, v10, v11)`:

| branch | `d[v8]` | `d[v10]` | `d[v11]` | exact zeros |
|---:|---:|---:|---:|---|
| 0 | `−3.47222222222222321` | `+3.47222222222222321` | `0.0` | `v11` |
| **1** | **`0.0`** | `−2.77777777777777857` | `+2.77777777777777857` | **`v8`** |
| 2 | `+3.47222222222222321` | `−3.47222222222222321` | `0.0` | `v11` |
| 3 | `0.0` | `+2.77777777777777857` | `−2.77777777777777857` | `v8` |

  `d[v8] = 0.0` is an **exact IEEE zero**, so `FieldExactRational::from_double_exact` yields exact rational `0` and
  every downstream predicate sees an exact zero. No tolerance is involved anywhere in this chain.

- **Branch 1 is the branch TB7 published.** `N = {v10}`, so `|M| = 1` with minimizer `v10`; the exit edge is the one
  opposite `v10`, namely `(8,11)`. The direction is exactly tangent to edge `(10,11)` — the edge opposite `v8`,
  whose derivative is the exact zero — and that edge is classified `Tangent`, so it is neither an incoming nor an
  outgoing carrier.
- **The entry is therefore the vertex itself.** With entry barycentric `p = e_{v10}` (an entry point published at a
  vertex, which is exactly what `field_boundary_point_at_vertex` emits), `t* = 1 / 2.777… > 0`, and
  `p + t*·d = (0, 0, 1) = v11`. Vertex **10 is one of the four singularities that emit ports** on this witness, so
  this is the first segment of a port trace: it leaves singular vertex 10 and runs **along mesh edge 10→11**.
- **The arrival ray is exactly the radial ray v11 → v10.** `arrivalRay = −d = (0, +2.777…, −2.777…)`.
- **At corner `v11` in row 8, `next = F(8,0) = v8` and `previous = F(8,1) = v10`.** So
  `arrivalRay[next] = 0`, and the half-open predicate's first clause `next > 0` is **false**.

`direction_in_vertex_sector` returns `false`; the guard records `SeedDirectionNotBarycentric` and returns
`VertexTransitSeedUnavailable` with `sourceVertex=11`, `sourceFace=(8,10,11)`, `branch=1`, `topologyRegion=0`,
`arrivalMode=FaceInterior`, `publishedFaceCount=0`, `barrierAbsorbed=false`, `barrierIncident=false`.

**That is TB7's published locus, field for field.** The cause is established, not inferred.

### 3.4 The ray is owned — by the neighbour, not by the arrival face

The same computation over the other face incident to edge `(10,11)`, row **109** `F = [79, 11, 10]`, gives at corner
`v11`: `next = v10`, `previous = v79`. Its branch-0 arrival ray satisfies `next > 0 ∧ previous ≥ 0` and **passes**
the same guard.

So the half-open convention is doing its job correctly: the radial ray `v11 → v10` belongs to **exactly one** sector
of the fan. CB9's guard does not test whether the ray is owned; it tests whether the **arrival face** is the owner —
a different and unwarranted question. A trace arriving along a shared edge is, by construction, on the boundary
between two sectors, and the arrival face has a 50% chance of being the non-owning side purely by mesh orientation.

### 3.5 AW1 verdict — same locus, different mechanism

| | TB5 | TB7 |
|---|---|---|
| typed code | `VertexTransitSectorUnresolved` | `VertexTransitSeedUnavailable` |
| diagnostic rows | **zero** — nothing was examined | **one** — the seed guard recorded before it skipped |
| mechanism | CB6's conditional BFS seed silently dropped, an *unreportable exit* (Amendment 19) | a *newly added* admissibility precondition rejects a legitimate arrival and says so |
| authority in between | CB7 removed the float round-trip and TB6 **passed** this arrival, first-redding later at vertex 30 | CB9 re-blocked it |

**TB7 is not TB5 reintroduced.** The shared locus is a consequence of trace order — the port trace out of singular
vertex 10 is early — not of a shared defect. `M3-CP4c3-TB5-REV-CAND-01` is **not** reopened and TB7 adds **no**
recurrence. Amendment 19 worked exactly as intended: the same region of code that once returned a false name now
returns a true one, and the review could read the cause instead of recovering it by elimination.

---

## 4. AW2 — the CB9 seed/certificate and AX8 projection path

Traced statically from `resolve_field_vertex_transit` → `FieldAlignedCurveNetworkError` →
`RemeshPipeline.cpp::network_failure_locus` → `SurfaceCellFailureLocusDiagnostics` →
`tests/FieldAlignedCurveNetworkTests.cpp::append_cp4c_failure_locus`, which is the printer the ordinal-366 identity
actually uses.

### 4.1 What exists before the failure

| AX8 field group | populated at the ordinal-366 failure? | why |
|---|---|---|
| `vertexTransitStates` rows (one per examined/skipped state) | **yes**, exactly one row, outcome `SeedDirectionNotBarycentric` | AY4 was honoured for the rows |
| `VertexStarRaySeed` (`audit->seed`) | **no** | the audit object is constructed *after* all five guards |
| fan/sector/kernel/owner/`onRadialRay` fields | **no** | same |
| `vertexStarState` | **no** | same |

### 4.2 Three distinct projection defects, all static and all provable

1. **The audit object is built after the guards.** `audit = VertexStarTransitAudit{}` and `audit->seed = …` are
   assigned only once the fifth guard has passed (`SurfaceCellTracing.cpp:1302-1305`). Every seed failure therefore
   leaves `error.vertexStarTransit == std::nullopt`. Amendment 19's rule — *record the diagnostic before any
   conditional that can skip the state* — was applied to the `diagnostics` rows and **not** to the audit object it
   also governs.
2. **`VertexStarTransitState::SeedUnavailable` is dead by construction.** `network_failure_locus` maps that enum
   value to the string `"SeedUnavailable"`, but the entire projection block is guarded by
   `if (error.vertexStarTransit.has_value())`, and by (1) that is never true on a seed failure. A declared state
   that no execution can reach is unexecuted authority.
3. **No consumer reads the new fields.** CB9 added 26 `vertexStar*` fields to
   `SurfaceCellFailureLocusDiagnostics` and populated them in `network_failure_locus` — exactly what AY7 ordered —
   but `append_cp4c_failure_locus`, the only renderer the CP4c identities use, prints **none** of them, and there is
   no projection of `vertexTransitStates` outcomes at all. So even a *post-seed* failure would publish nothing new.

### 4.3 Disposition of `M3-CP4c3-TB6-CAND-01`

CB9's report claims this candidate closed. It did not. AY7 asked for the typed fields *and* for a reader, "so the
rows have a reader"; the producer→DTO half was delivered and the DTO→report half was not. The candidate stays
**ACTIVE**, and its cause is now **established statically** rather than merely unmeasured. The implementation is
**not** "correct but unreached": one half of the ordered change is missing, and (1) and (2) are outright defects in
the delivered half.

This is the **third consecutive turn** in which a measurement was ordered, built, and then discarded at a stage
boundary — AS1, AU1/AU3, and now AY7. The pattern has moved one layer outward each time. `LESSONS.md` 75 already
names the two authoring-time controls; §9 adds the one they were missing.

---

## 5. AW4 — ordinal 374's atlas stop, recovered and classified

### 5.1 The witness

`make_three_right_angle_cone_fan()` — `V = {(0,0,0), (1,0,0), (0,1,0), (0,0,1)}`,
`F = {(0,1,2), (0,2,3), (0,3,1)}`; three consistently oriented faces around the origin, outer boundary the triangle
`1-2-3`. Vertex 0 is the only interior vertex; `V−E+F = 4−6+3 = 1`, one boundary loop.

The field is `make_folded_cone_vertex_field(mesh, ·)`, which starts from `make_zero_transport_field(mesh)` —
**`effort ≡ 0` on every edge, `singularCycles` and `singularIndices` empty** — then overwrites only the per-face
primary/secondary directions and the per-edge `matching` (`(0,1) → 2`, `(0,2) → 2`, `(0,3) → 0`, boundary edges
`0`). It never touches `effort` and never declares a singularity.

### 5.2 The atlas arithmetic, recomputed

Frames build cleanly on all three faces: `|primary · secondary| ≈ 10⁻¹⁷`, gauge unique with a minimum angular
separation of `π/2` against a `10⁻¹⁰` tolerance. So `InvalidBranchTopology` / `AmbiguousBranchTopology` do **not**
fire, and `build_boundary_pairing` succeeds.

The three corner angles at vertex 0 are each exactly `π/2` (mutually orthogonal axis legs), so

```
Θ(v0) = 3π/2        K(v0) = 2π − Θ = π/2
```

`dual_cycles` emits the inner-vertex cycle first, and its `cycleCurvature` is *"simply the Gaussian curvature"*.
`FieldTransportAtlas::make` then computes

```
exactLift = (cycles · effort + 4 · cycleCurvature) / 2π
          = (0 + 4 · π/2) / 2π
          = 1          exactly
```

- integral, so `NonIntegralCycleLift` does **not** fire; `turningLift = 1`;
- `compose_cycle` composes the branch transports, which are `QuarterTurn::from_integer(raw.matching)`
  (`FieldTransportAtlas.cpp:1807`). Around vertex 0 those are `2, 2, 0`, and `±2 ± 2 ± 0 ≡ 0 (mod 4)` under every
  sign assignment, so `composed.value() = 0`;
- `0 ≠ normalized_quarter_turn(1) = 1`.

**`atlasBuild.error().code == FieldAtlasBuildErrorCode::CycleTransportMismatch`**, raised at
`FieldTransportAtlas.cpp:2098`, with only `topologyRegion` populated.

A second, independent contradiction sits immediately behind it: at `:2150-2163` an interior cycle with
`turningLift ≠ 0` and no supplied singularity is `SingularityMismatch`. The witness declares no singularities at
all, so it fails that check too. Whichever ordering a future build takes, the witness is refused for the same
reason.

### 5.3 Classification — AW4 category 1

**Invalid folded-cone test/field precondition with legitimate product rejection.** The atlas is enforcing discrete
Gauss–Bonnet / Poincaré–Hopf consistency between mesh curvature, declared transport effort, declared matching and
declared singularities. It is correct. **No atlas invariant may be weakened, and no product repair is warranted.**

### 5.4 The root cause, and it is reusable

`make_zero_transport_field` carries an **unstated precondition: the mesh must be intrinsically flat at every
interior vertex.** With `effort ≡ 0` and no declared singularity, `exactLift = 4K/2π`, which is `0` only when
`K = 0`. Every previous consumer satisfied it by accident — `make_four_triangle_fan`, for instance, is entirely
planar (`z = 0` at all five vertices), so `K = 0` at its center and the helper is consistent there.

`AY5` required the project's **first non-flat star** — `DEFN-R2` §7.2 item 3 asks for "at least one non-coplanar
hinge", and §7.1 explains why: vertex 30 is intrinsically flat, so it cannot separate `β = α + Θ/2` from
`β = α + π`. The witness author supplied the required non-flatness and inherited the flat-only helper unchanged.

**The deeper constraint `DEFN-R2` §7.2 did not state.** Production terminates a trace at a singular vertex
(`field_aligned_singularity_at` is checked *before* `resolve_field_vertex_transit` at both call sites), so
vertex-star transit only ever runs at a **regular** vertex. A regular vertex has cycle lift `0`. Therefore any AY5
witness that is both non-flat and reachable by vertex-star transit must satisfy

```
Σ_cycle effort = −4 · K ,   with the declared matching composing to the same lift 0,
```

and must additionally satisfy the boundary-index correction the atlas applies on a region with a boundary loop.
Nothing in §7.2's five enumerated properties says this. That is the familiar failure mode — an enumeration inside a
measure read as exhaustive — and it produced a witness that could never execute the path it exists to test.

### 5.5 Corrective shape — specified, deferred, not authorized here

The correction is **test-side only**:

1. give the folded cone a field whose per-edge `effort` and `matching` are **derived**, not declared — the
   production authority `directional::fields::principal_matching` (`include/directional/fields/FieldMatching.h:57`)
   computes matching, effort and singularities from a raw field and is the single writer for exactly this;
2. choose the per-face representatives so the derived lift at the center is **`0`** (the center must be regular) and
   the required "more than one candidate accepts its own representative" property of §7.2 item 4 still holds;
3. carry the exact expected owner derivation forward unchanged — `Θ = 3π/2`, per-sector `D = 0, P = 1, Q = 1`,
   `β = α + 3π/4` — since that geometry is correct and is what makes the witness discriminating;
4. state the admissibility derivation in the report, so the witness is certified against the atlas's whole chain
   (lift integrality, transport composition, singularity declaration, boundary index correction) rather than
   discovered by a failed run.

**Selector 374 stays byte-frozen and is not withdrawn.** The identity's name, intent and gate membership are right;
only the fixture and field inside its body are invalid, and repairing them changes no selector byte. Withdrawing it
would be adding leniency to a frozen gate after its evidence arrived, which this project has explicitly ruled out —
and it would delete the only discriminator CP4c-3 has for Amendment 22's `Θ/2`.

**Ordinal 374 will therefore still be red in the next TB.** That is expected, pre-classified, and carries no new
information; it must not consume a review turn.

---

## 6. AW3 — Amendments 22 and 23 adjudicated

**Both remain internally valid, and no new semantics is substituted.**

- **`DEFN-R2` §AX1 imposes no such guard.** It fixes what the seed *is* — "the exact direction, in `arrivalFace`'s
  chart, of the ray from the vertex back along the incoming trace" — its sign, its writer, and its lifetime. It says
  nothing that requires the arrival face to own that ray under the half-open convention. CB9's fifth guard is an
  **implementer-invented precondition**.
- **`DEFN-R2` §AX7 §7.2 item 5 requires the opposite.** It orders "a seed placed strictly inside its arrival sector,
  plus a second instance placed exactly on a radial ray, so the boundary-ray case and the exact fallback are both
  exercised", and Amendment 23 records that the exact fallback "is the only path that can decide a continuation
  lying exactly on a radial ray". On-radial arrivals were anticipated and mandated, not overlooked.
- **The unchanged half-open predicate keeps exactly one job.** Amendment 22 applies it *to developed sectors* to
  elect one owner. That job is untouched by this review and must stay untouched: §3.4 shows it partitions the fan
  correctly at vertex 11. What must change is the separate question CB9 asked with the same predicate.

### 6.1 The same conflation, a second time, further downstream

`SurfaceCellTracing.cpp:1531-1540` rejects an arrival whose developed angle `α` is exactly on a radial ray:

```
if (arrivalMode == FaceInterior && alpha->crossSquared == 0)   → VertexTransitSeedUnavailable
if (alpha->crossSquared == 0 && alpha->dot ≤ 0)                → VertexTransitSeedUnavailable
```

`α` is measured from the arrival sector's `nextRadialVertex`, so `crossSquared = 0` means the arrival ray is
collinear with that radial ray. The two guards are complementary halves of one rule:

- the arrival ray on the **previous** radial ray → rejected by the fifth seed guard (§3.3, vertex 11);
- the arrival ray on the **next** radial ray → passes the fifth guard, then rejected here whenever the mode is
  `FaceInterior`.

**Together they make every Amendment-3 edge-collinear vertex arrival unresolvable in `FaceInterior` mode**, which is
the mode `resolve_field_branch_continuation` always publishes for a `VertexHit`. Correcting only the fifth guard
would move the failure, not remove it. Both must be corrected in one change.

### 6.2 The witness was shaped to the invented constraint

CB9's third AY5 instance is `FoldedConeRadialArrivalSeedUsesExactHalfOpenArrivalConvention`, and its own comment
reads: *"EdgeTransit is the admissible arrival mode for that exact radial seed."* The author met §7.2 item 5 by
choosing the one arrival mode their guards permit, rather than by supporting the case the definition required. That
is why the production defect survived CB9: **the witness that would have caught it was written around it.** It is
also why the two companion instances are, correctly, not in the gate — only
`FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection` is ordinal 374 — so no gated identity covers
the boundary-ray or radial-arrival cases at all today.

### 6.3 What is *not* admissible as a repair

Unchanged from the frozen prohibitions, and restated because the temptation here is real: no candidate-local
representative, no `signedLift` used as arbitrary geometric-ray transport, no tolerance, no nearest-angle rule, no
candidate ordering, no invented owner, and no floating point anywhere in the decision chain. The correction below
adds **no** new decision — it removes two preconditions that were never frozen and routes the case to the exact
fallback the architecture already owns.

---

## 7. AW5 — report-only disposition, no gate credit borrowed

| ordinal | TB7 result | disposition after review |
|---|---|---|
| 367 `RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | RED | **retained as upstream-blocked** by the vertex-11 stop. No independent evidence of a separate failure; do not classify its contract. |
| 368 `PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath` | RED | **preserved unchanged.** `NoCarrierMatch / SourceEdgeUnavailable`, trace 2 / event 30. No sphere semantic correction is authorized; AL4 stands. |
| 369 `OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation` | RED | `M3-CP4c2-TB-X2-R10-CAND-01` **remains ACTIVE**; `saturationUsed=true` is deferred quality/coverage debt. |
| 370 `EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` | RED | `M3-CP4c2-TB-X2-R8-CAND-02` **remains ACTIVE** as a genuine product red. Its owner is `SurfaceCutGraph`, shares no code and no datum with vertex-star transit, and its fix must not be combined with this successor. |
| 371 `NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` | RED | **retained as upstream-blocked.** Amendment 15's barrier-cycle contract remains **unmeasured, not falsified**. |
| 372 `CutTransportDomainSatisfiesTheEulerCutIdentity` | RED | **retained as upstream-blocked.** Euler-cut contract remains unmeasured. |
| 373 `PrescribedSingularityOnABarrierArcRemainsBoundToACycle` | PASS | **synthetic pass only.** `M3-CP4c3-DEFN-R1-CAND-01` stays open until production publishes `unboundSingularityCount = 0`. |
| 374 `FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection` | RED | **classified** in §5 as an invalid witness precondition; deferred with its corrective specified. |

CB9's `AY8` findings `M3-CP4c3-CB9-AUDIT-01` (the `build_boundary_pairing` `double`→`from_double_exact`
re-expression seam) and `M3-CP4c3-CB9-AUDIT-02` (unbounded `integer_sqrt_floor` input size) remain **static audit
debt**. TB7 converts neither into a runtime event.

One observation worth recording rather than leaving as a field value: **AUDIT-01 is the mechanism that produced the
exact zero this whole review turns on.** `build_boundary_pairing` computes `u, v` in `double` and exactifies them,
and it is precisely because the mechanical field is exactly axis-aligned there that `d[v8]` lands on an exact IEEE
`0.0` rather than a tiny nonzero. The re-expression is real and is correctly recorded as debt; but note that on this
witness it produced the *right* answer — the field genuinely is tangent to edge `(10,11)` — so AUDIT-01 is **not**
the cause of ordinal 366 and must not be repaired as if it were.

---

## 8. AW7 — one bounded successor: `M3-CP4c-3-CB10`, measures **AZ0–AZ9**

**Owner:** product. Exact source owner `src/geometry/SurfaceCellTracing.cpp::resolve_field_vertex_transit`, plus the
failure-reporting contract that function feeds (`src/pipeline/RemeshPipeline.cpp::network_failure_locus` and every
consumer of `SurfaceCellFailureLocusDiagnostics`, including the test-side renderer). This is one owner, not a
combination: §4 shows the projection half is the undelivered remainder of the already-ordered AY7, on the same
datum and the same failure path.

**Explicitly NOT in this successor:** the ordinal-374 witness (different owner, §5), the prescribed sphere, ordinal
370, saturation coverage, mechanical zero-unbound debt, and both AY8 audit candidates.

### AZ0 — preconditions

Selector **374 byte-frozen** and recomputed at authoring and at preflight; selector 373 unchanged as its prefix;
accepted 365 untouched; `selected_gate = NONE`; `gate_execution_authorized = false`; Code + Build is runtime-free;
GMP/GMPXX linkage mandatory and proved in the link evidence (`GMP_COMPILE_POLICY.md`); no gate, no benchmark, no
package repair.

### AZ1 — separate the ownership convention from the admissibility test

The arrival ray's admissibility in the arrival face is that it lies in that face's **closed** wedge at the vertex:
`next ≥ 0 ∧ previous ≥ 0 ∧ ¬(next = 0 ∧ previous = 0)`, exact against zero. `direction_in_vertex_sector` — the
half-open predicate — **must not change and must not be used for this test**; it keeps exactly one job, electing one
owner among developed sectors (Amendment 22, AY2). Introduce the closed-wedge predicate as a separate, named,
exact function next to it, so the two questions can never again be answered by the same call.

### AZ2 — support the on-radial-ray arrival, in both orientations

Remove the two rejections of §6.1. An arrival ray lying exactly on either radial ray of the arrival sector is a
**legitimate `FaceInterior` arrival** — it is what an Amendment-3 edge-collinear vertex landing produces — and its
developed angle is exact and well defined: `α = 0` on the `next` radial ray, `α = θ(arrival sector)` on the
`previous` radial ray. Both must reach the development and be decided by the unchanged half-open convention and the
exact fallback, which Amendment 23 already names as the only path able to decide a ray-exact case. Publish
`onRadialRay` and the radial-ray identity for the **arrival** as well as for the continuation.

### AZ3 — one typed name per condition

The fifth guard currently reuses `SeedDirectionNotBarycentric` for three distinct conditions: a non-barycentric
direction, a missing arrival-face row, and a ray outside the arrival wedge. Split them into three outcomes, each
with its own locus. Before adding any name, apply the standing check: read the site that sets it and count the
distinct conditions that reach it, and record the count in the report.

### AZ4 — Amendment 19 applied to the audit object, not only to the rows

Construct the `VertexStarTransitAudit` and its `VertexStarRaySeed` — as far as each is derivable — **before** the
first conditional that can return. Every seed failure must publish a populated audit with
`VertexStarTransitState::SeedUnavailable`, which today is unreachable by construction. A declared typed state that
no execution can reach is a defect, and the report must demonstrate reachability for each of the four states.

### AZ5 — give the rows a reader, by search

Extend the projection so `SurfaceCellFailureLocusDiagnostics`' AX8 fields **and** the `vertexTransitStates`
outcomes are rendered wherever that struct is rendered for human or gate consumption. Find the consumers **by
search against the predicate — "any site that renders `SurfaceCellFailureLocusDiagnostics` into a report, message,
or assertion"** — not by copying this measure's list, and name in the report at least one consumer that this
measure did not name. `append_cp4c_failure_locus` in `tests/FieldAlignedCurveNetworkTests.cpp` is known to be one
of them; it is a starting point, not the scope. This closes `M3-CP4c3-TB6-CAND-01`.

### AZ6 — the falsifying witness, and conditional selector governance

Derive and commit a witness for the on-radial-ray `FaceInterior` arrival with exact rational coordinates, whose
expected owner is derived from Amendment 22 **before** the code is written and never read off the implementation.
The mechanical vertex-11 star is the recommended starting geometry: its coordinates are already committed, the
arrival is already proved exact (§3.3), and it is the configuration production actually produces. Both radial
orientations must be instantiated, since §6.1 shows they fail through different guards. The witness must be shown
to **fail** under CB9's guards and **pass** under the correction, quoted side by side.

Selector **374 keeps every byte**. Ordinal **375** may be appended — exactly one line, nothing above it moving,
respelled or removed — **only if** that falsification is demonstrated. If it is not demonstrated, do not create
selector 375: report and stop.

### AZ7 — prohibited

Weakening or re-tuning `direction_in_vertex_sector`; using it for admissibility; any tolerance or float-derived
topological decision; `signedLift` as arbitrary geometric-ray transport; candidate ordering, nearest-angle, or
tie-breaks; deciding from a candidate's own representative; re-introducing floating point anywhere in the decision
chain; repairing `build_boundary_pairing` (AUDIT-01) as if it caused ordinal 366; touching the ordinal-374 witness,
the sphere, ordinal 370, or the atlas's admissibility invariants; any selector byte change other than the
conditional AZ6 append.

### AZ8 — audit by assumption

Two predicates, each discharged by search, each with at least one named site **outside** those this record names:

- *"a convention that assigns ownership among alternatives is used as a validity precondition on a single
  alternative"* — the defect class of §3 and §6.1;
- *"a typed state or diagnostic field is declared but no execution path can populate it"* — the defect class of
  §4.2 (2).

### AZ9 — expected next-TB discriminators, falsifiable in advance

1. **Ordinal 366 clears source vertex 11.** The trace out of singular vertex 10 along edge `(10,11)` transits vertex
   11 and continues, and the first red — if any — moves to a *different* locus. If ordinal 366 still fails at vertex
   11, the correction is wrong, not incomplete.
2. **The next vertex-transit failure, wherever it lands, publishes a full seed and audit.** Any future
   `VertexTransitSeedUnavailable` must arrive with `vertexStarState`, `vertexStarArrivalRay`, and the per-state
   outcome rows visible in the identity's own output. A repeat of TB7's field set is a failure of AZ4/AZ5.
3. **Vertex 30 becomes reachable again, and DEFN-R2's exact answer becomes testable.** With vertex 11 cleared, the
   mechanical witness should reach vertex 30, where the frozen prediction is already exact: owner row **209**
   `(30,119,123)` if `α < θ₂₀₉`, else row **208** `(30,31,119)`, and row **41** `(25,30,31)` unreachable. A vertex-30
   result contradicting that falsifies Amendment 22 at the measured locus and is materially different evidence.
4. **Ordinal 374 remains red at `ASSERT_TRUE(atlasBuild)` with `CycleTransportMismatch`.** Pre-classified in §5;
   carries no new information and must not re-open a review.
5. **367 / 371 / 372 either go green or produce their own first independent loci.** Whichever happens is new
   information about contracts that have never executed.

**Compile targets:** the eight standard targets, GMP/GMPXX linked, `runtimeExecution=false`, one package, and the
successor is artifact-only `M3-CP4c-3-TB8` running selector 374 from ordinal 1, one identity per fresh process,
with every mutation/build/repair/benchmark flag false.

---

## 9. Prohibited shortcuts and lessons retained

- **A convention that partitions a set is not a precondition on a member of it.** The half-open sector rule exists
  to make ownership unique. Asked of one face in isolation it answers a different question, and its deliberate
  asymmetry — include the `next` ray, exclude the `previous` one — becomes an arbitrary orientation-dependent
  rejection. This is the same family as the rails and cycle-basis instances already recorded, at a new level: not
  two authorities for one datum, but **one correct rule reused for a question it was not written to answer.**
- **A fixture helper's silent precondition surfaces the first time a witness stops being degenerate.**
  `make_zero_transport_field` is only valid on an intrinsically flat star, and every witness before AY5 happened to
  be flat. The project's own standing note — that the same degenerate-fixture class has now cost several
  checkpoints — gains its next instance, and the counter-control is the one CP3a already demonstrated: make the
  helper assert its own precondition, so the next author cannot inherit it silently.
- **A measure that orders a projection must name the consumer that renders it, not only the struct it fills.** AY7
  said "extend the projection in the same change" and was implemented exactly; the field set grew and no reader
  appeared. The scope has to be written as a predicate over consumers the implementer must find, not as the
  producer-side artefact.
- **Record the diagnostic before the guard means the whole diagnostic, including its container.** AY4 was honoured
  for the rows and missed for the audit object, and the result was a typed state no execution can reach.
- **A witness written around an implementation's restriction cannot falsify that restriction.** CB9's radial-arrival
  instance chose `EdgeTransit` because `FaceInterior` was blocked; the block was the defect.
