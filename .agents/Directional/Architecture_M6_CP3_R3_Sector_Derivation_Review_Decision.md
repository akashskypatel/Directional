# M6-CP3 R3 — source-topology sector derivation: independent producer Design Review decision

**Type:** runtime-free independent producer Design Review resolving the `M6-CP3-CB1-ENTRY-R3` preflight STOP.
**Decision:** **BLOCK RESOLVED — the two oriented sectors are well-defined and derivable from authority A4
already holds. Frozen as RA-38, implementing RA-37a correction (1); RA-37a is not replaced.**
**Two unsound validators are identified and must be corrected; they are distinct defects.**
No runtime credit; all RA-34.3 and RA-36.4/.5/.6 gates stand.

## 1. The STOP was correct and the preflight discipline held

`M6-CP3-CB1-ENTRY-R3` refused to proceed rather than guess a sector, a global face-star potential, a
first-by-row face, or a new τ. It changed no production source and attempted no compile. That was right: RA-37a
asserts the *existence* of two unique oriented sectors without giving the construction, and an implementation
turn must not invent one. This Review supplies the construction.

## 2. The sectors are the two arcs of the vertex-star cycle cut by the incident hard carriers

At a rail junction vertex `v` on an interior orientable manifold link, the faces of `v`'s star form a **cycle**
under the "share a spoke edge at `v`" relation. Exactly two hard carriers are incident to `v` on a
non-branching rail. **Cutting the cycle at those two carriers yields exactly two arcs — the two unique oriented
sectors — and each incident carrier contributes exactly one face to each arc.**

Derived mechanically on the reviewed 3×3 fixture
(`tests/SurfaceCellTransitionQuotientTests.cpp:694-740`), faces
`0=(0,1,4), 1=(0,4,3), 2=(1,2,5), 3=(1,5,4), 4=(3,4,7), 5=(3,7,6), 6=(4,5,8), 7=(4,8,7)`:

```text
star(v=4) faces          : {0, 1, 3, 4, 6, 7}
star cycle               : 0 → 1 → 4 → 7 → 6 → 3 → 0
cut at carriers (1,4),(4,7)
  sector A               : {0, 1, 4}
  sector B               : {3, 6, 7}
carrier (1,4) faces {0,3}: 0 ∈ A, 3 ∈ B      (exactly one per sector)
carrier (4,7) faces {4,7}: 4 ∈ A, 7 ∈ B      (exactly one per sector)
```

This reproduces exactly the two oriented radial chains the STOP record observed (`0→1→4`, `3→6→7`) and shows
they are not an artefact of the fixture: they are the two arcs of the cut star. **Each sector is therefore a
well-defined *side* of the rail polyline**, and within one sector the consecutive carriers' faces are connected
by a radial chain of **non-rail** A3 transitions. No carrier-to-carrier face identity is involved, which is why
the superseded RA-36.1 premise failed.

**Fail-closed cases, which coincide exactly with RA-37a's already-frozen domain:**

- **boundary vertex** — the star is a path, not a cycle; cutting at two carriers yields three arcs. Ambiguous →
  STOP.
- **more than two incident hard carriers** (rail branch/junction point) — more than two arcs; no unique pair →
  STOP.
- **exactly one incident carrier** — the rail terminates at `v`; there is no through-transport to certify.
- **non-manifold or singular star** — not a cycle → STOP.
- **foreign barrier inside an arc** — that sector is not a valid transport path → STOP.

RA-37a already restricts sectors to "connected orientable two-manifold links without foreign barriers, otherwise
fail closed." The construction above lives inside that domain; RA-37a needs no amendment.

## 3. Two distinct unsound validators, not one bug

`src/geometry/SurfaceCellTracing.cpp:8019-8118` contains **two independent** errors:

1. **Face-chaining across carriers** (~`:8078`): `previous.secondFace != transition.firstFace` → reject. This is
   the same primal/dual category error as the superseded RA-36.1, at a second site. For the reviewed rails it
   always fires, because `{0,3} ∩ {4,7} = ∅`. It must be replaced by **within-sector radial chaining**.
2. **Endpoint-path cardinality** (~`:8063`): `endpoint.orientedSteps.size() != expectedSteps.size()` ties the
   endpoint path length to the number of route carriers. That is unsound in general: the local path length is
   set by **fan valence at each junction**, not by carrier count.

**The second defect is hidden by the fixture.** The 3×3 case has two carriers and a radial chain of length two,
so the cardinality rule is satisfied *by coincidence*. A correction that fixes only the chaining and validates on
3×3 will pass while this rule remains wrong, and will fail on the first fixture whose fan valence differs. Both
must be corrected together.

A third ordering defect carries over: the A4-side gate at `:18312-18330` must not precede the sector/junction
logic, or the corrected path remains unreachable — the same reachability trap as `M5-CP3-TB1-R3-REV`.

## 4. Publish, do not invent — the third instance of this pattern

A4 already holds everything the construction needs. `railFanPotentials` already traverses the **whole** vertex
star (`:18120-18206`), and A4 already knows the hard carriers because it builds `hardRailFieldTransitions`. The
only missing step is the **cut** of the star cycle at those carriers, which is a local derivation over data A4
already owns.

That makes this the third occurrence of one shape in this milestone: **RA-34.3** (τ retained before the
nontraversable marking destroyed access), **RA-35** (per-wedge bindings retained before the sort/unique collapse),
and now **RA-38** (the star is already traversed; only the carrier cut is missing). In every case the cure is to
publish or reach authority the producer already computes — never to add new input or let a consumer infer.

**Explicitly forbidden:** a guessed sector; a global face-star potential used as ownership rather than as a
post-ownership cross-check; first-by-row face selection; a new τ definition; any A5-side path search or
inference from sheet/region labels. A5 consumes only the published immutable certificate.

## 5. What this decision does not establish

It settles that the sector decomposition is sound, derivable and within RA-37a's domain, and it names two
validator defects. It does **not** establish that a real A4-produced multi-carrier paired HardRail front exists —
the STOP record is right that a hand-authored input fixture is not a produced certificate. If the bounded
real-producer search yields no multi-carrier positive, the multi-carrier path remains **unexercised and must not
be cited as validated**, exactly as at `M5-CP3-DEFN-R1`.

All RA-34.3 R2-P3 stop gates stand unchanged — odd `τ ∈ {1,3}`, `F_b − F_a ≠ τ`, a sign-inversion negative,
reciprocal/face-permutation invariance — and an empty bounded search **stops for Review**. RA-36.4/.5/.6 remain:
singleton must not regress, uncertifiable routes reject with a typed code naming that cause, and no runtime
credit accrues.

## 6. Verification limits

Derived mechanically from repository bytes: the fixture triangulation; the star of vertex 4 and its cycle; the
sector arcs after cutting the two carriers; the one-face-per-sector split of each carrier. Re-read from source:
both validator defects at `:8019-8118`, the A4-side gate at `:18312-18330`, and `railFanPotentials`' whole-star
traversal at `:18120-18206`. Accepted as reported: the R2 artifact tallies and the source-snapshot hashes in the
STOP record.
