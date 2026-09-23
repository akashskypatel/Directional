# M5-CP3-DEFN-R1 Same-Region Nonzero-Z4 Gauge Reconciliation Definition Record

**Turn:** `M5-CP3-DEFN-R1`
**Boundary:** runtime-free definition/review; no product, test, fixture, selector, benchmark, build-source, configure, compile or Directional runtime mutation
**Entering runtime:** R14 `446/448 PASS`, self-manifest `916/916`, selector430 `430/430`
**Entering candidate:** artifact/source `10733058003 / 6bad9eb5626e77a234ffb2c14f621195105e4ba1`, unpromoted
**Decision:** **DEFINITION FROZEN / CURRENT NONZERO WITNESS VALID / EXISTING RP-01 / +0**
**Exact successor:** `M5-CP3-CB17`

## 1. Result

DEFN-R1 resolves the under-specified authority seam proved by R14. There is one deterministic same-region quotient rotation and one deterministic relation-endpoint normalization. No inverse retry, gauge search, partner fitting, translation fitting, insertion-order choice, downstream success inspection, fixture/field retuning or M6 authority is required.

The four frames are distinct and are now frozen as follows:

| Frame | Symbol | Producer | Meaning |
|---|---|---|---|
| A1 source-face frame | `S_f` | `FieldTransportAtlas` / finalized cross field | Local Z4 branch basis on source face `f`; directed carrier transition is expressed here. |
| Cut-domain phase-front frame | `C` | accepted bounded-disk A4 construction | One cut-open integer/branch trivialization rooted and propagated only through retained dual adjacency; accepted cut carriers are absent from this propagation. |
| Relation endpoint gauge | `E_F`, `E_R` | same-region relation publication | Semantic A3 Forward is the anchor. Forward consumes cut-domain values unchanged; Reverse is normalized by the derived quotient turn before relation correspondence. |
| Canonical storage representation | `K` | periodic-holonomy checked factory / canonical insertion | Stores either semantic action or its exact inverse according to canonical representation; storage orientation is not semantic direction. |

`PeriodicRelationId` remains orientation-neutral carrier-content identity. The action is relation value, not identity.

## 2. Source-to-cut gauge and the unique quotient turn

For the exact A3 generator carrier, let:

- `F` be the exact semantic **Forward** boundary occurrence and `R` the exact semantic **Reverse** boundary occurrence;
- `f_F`, `f_R` be their exact source faces;
- `A : S_F -> S_R` be the exact directed A1 carrier transport returned by `FieldTransportAtlas::transition_value(carrier, f_F, f_R)`;
- `G_F : C -> S_F` and `G_R : C -> S_R` be the accepted cut-domain face gauges represented by `faceBranchRotation` at those exact occurrence faces.

The one quotient turn from Forward cut gauge to Reverse cut gauge is therefore

```text
Q = G_R^-1 o A o G_F
```

or, because the rotation group is Z4 and `QuarterTurn` composition is additive modulo four,

```text
q = -g_R + a + g_F  (mod 4).
```

This is forced by commutation of the existing producer-owned maps. A raw A1 turn `A` may equal `Q` only when the two cut-domain gauges happen to cancel. The relation rotation is therefore **`Q`, not raw `A` by definition**.

There is no free conjugation in Z4 and no permitted alternate direction. Semantic A3 Forward -> Reverse fixes `A`; the accepted bounded-disk producer fixes `G_F` and `G_R`; those three facts determine `Q` uniquely.

### Reverse semantic direction

Reversing semantic roles yields exactly

```text
Q_rev = Q^-1 = G_F^-1 o A^-1 o G_R.
```

This is algebraic inversion, not a second candidate. A consumer may never try Forward and Reverse and keep the one that passes.

## 3. Relation endpoint branch gauge

Let `B_f` be a branch label in source-face frame `S_f`. Its cut-domain branch component is

```text
c_f = G_f^-1 o B_f.
```

The relation endpoint states are authored in one semantic Forward-anchored convention:

```text
Forward endpoint branch: b_F = c_F
Reverse endpoint branch: b_R = Q o c_R
```

The cut-domain +U component is producer-owned and global within one accepted bounded-disk chart: current A4 authors `LocalLatticeState.branchRotation` as `G_f + chartUBranch` (or the equivalent zero-root form), so applying `G_f^-1` recovers the same `chartUBranch` on both reciprocal copies. A3 reverses the boundary occurrence, not that chart +U authority. Thus `c_F = c_R` before quotient transport, and the first branch equation becomes

```text
Q o b_F = b_R.
```

Equivalently in source-face authority,

```text
G_R o b_R = A o G_F o b_F,
```

because `G_R o Q = A o G_F`. This is the closure equation that was missing from §§16/16.1. The relation-endpoint branch is not allowed to copy a source-face branch label directly across this boundary.

## 4. Relation endpoint lattice gauge and translation

Ordinary A4 cell-placement coordinates remain in the accepted cut-domain integer grid and are unchanged. Call the raw endpoint coordinates `x_F` and `x_R` on the semantic Forward and Reverse copies.

The relation-owned endpoint coordinates are distinct authority and are normalized as:

```text
y_F = x_F
y_R = rotate(Q, x_R).
```

The asymmetric-looking convention is intentional and not a heuristic: semantic A3 Forward is already authoritative, so it fixes the relation gauge. Reverse is the only side re-expressed into that semantic convention. Re-anchoring on canonical storage order is prohibited. This also resolves the R11-R1 endpoint-coordinate contradiction rather than hiding it: the cut-open chart authors reciprocal raw boundary copies in one common integer basis, so before seam transport their matched boundary deltas are oppositely oriented (`d_R,raw = -d_F,raw`). Applying the same quotient turn to the Reverse relation-owned coordinate gives `d_R = rotate(Q,d_R,raw)`, hence `rotate(Q,d_F) = -d_R` exactly.

For a reciprocal pair with Forward endpoints `(F.from, F.to)` and Reverse endpoints `(R.from, R.to)`, A3 correspondence is

```text
F.from -> R.to
F.to   -> R.from.
```

The relation action in semantic Forward -> Reverse direction is

```text
T(p) = rotate(Q, p) + t
```

with translation **constructed from the semantic anchor, not fitted after a mismatch**:

```text
t = y_R,to - rotate(Q, y_F,from)
  = rotate(Q, x_R,to - x_F,from).
```

The second endpoint is a validation condition:

```text
y_R,from == rotate(Q, y_F,to) + t.
```

It is not another equation from which an alternate `t` may be solved. With

```text
d_F = y_F,to - y_F,from
d_R = y_R,to - y_R,from,
```

the two endpoint maps imply the frozen transported-delta relation

```text
rotate(Q, d_F) == -d_R.
```

Thus branch correspondence, delta correspondence and both integer endpoint maps are consequences of one named relation gauge and one anchored action; they are no longer independent knobs.

### Reverse action

The Reverse -> Forward semantic action is exactly

```text
T^-1 = (Q^-1, -rotate(Q^-1, t)).
```

No translation is recomputed from Reverse endpoints. This exact inverse is also what canonical storage uses if storage orientation is opposite semantic A3 direction.

## 5. Canonical storage

Canonical storage remains representation-only:

1. Determine semantic A3 Forward/Reverse roles and derive `T` first.
2. Determine `PeriodicRelationId` from the existing orientation-neutral canonical carrier content.
3. If canonical storage order agrees with semantic Forward -> Reverse, store `T` and the corresponding routes.
4. If canonical storage order reverses the representation, store `T^-1` and reverse the corresponding routes exactly.
5. `resolve_periodic_relation_semantic_action(...)` must recover `T` solely from semantic A3 orientation and canonical representation metadata.

The relation endpoint states remain authored in the semantic Forward-anchored relation gauge. A canonical storage swap must not cause those states to be regenerated in a different gauge.

## 6. Exact `Q == identity` reduction

The zero-rotation reduction is defined by the **relation-gauge quotient turn `Q`**, not by raw `A` alone.

If `Q == identity`:

```text
y_F = x_F
y_R = x_R
b_F = c_F
b_R = c_R
```

and the translation reduces to the existing exact integer offset between reciprocal endpoint copies. Ordinary A4 cell placement is byte-for-byte outside this definition change. The four already-green produced controls and accepted selector430 therefore retain their existing semantic contract.

## 7. Independent concrete nonzero witness — R14 Review observation discharged

`M5-CP3-TB1-R14-REV-OBS-01` required at least one independently derived concrete nonzero value before this model could be frozen. DEFN-R1 derives that value from the committed torus source fixture and the test's source/A3 witness selection, without reading downstream relation success.

The committed witness authority is:

- source fixture `benchmarks/fixtures/milestone-g/torus.obj`, V/E/F `72/216/144`;
- exact row408 hard-rail authority has 18 edges;
- the source witness scans the sorted nonzero hard carriers and selects canonical source edge `(0,3)` first;
- mandatory full-edge A2b paths are authored by `exact_edge_interval_path(edge,0,1)`, hence use the canonical `SourceEdgeTopologyKey` orientation. For carrier `(0,3)` the Forward path is exactly `0 -> 3`; source face `22 = (22,0,3)` owns that directed side and source face `1 = (0,2,3)` owns the Reverse `3 -> 0` side. The exact A3 Forward/Reverse occurrence faces are therefore `22 / 1`;
- static re-evaluation of the committed seam-ramp field through the same principal-matching algebra yields exactly **five** nonzero source-edge transitions out of all **216** torus edges: `(0,3)`, `(3,25)`, `(25,37)`, `(37,49)`, and `(0,61)`, each `+1` in its stored direction. Every one is in the exact 18-edge accepted row408 hard-cut set; every retained dual edge has Z4 transition zero;
- on `(0,3)` the stored transition is `+1` for face `1 -> 22`, hence exact semantic A3 Forward `22 -> 1` reads its inverse, **`A = 3 mod 4`**;
- A4's accepted-cut-domain propagation explicitly omits every accepted cut carrier. Since all remaining dual transitions are zero, `faceBranchRotation` is identically zero regardless of the deterministic root choice. Therefore the exact occurrence gauges are independently **`G_F = G_R = 0`**.

Therefore, independently of downstream periodic-relation construction,

```text
Q = G_R^-1 o A o G_F
  = 0^-1 o 3 o 0
  = 3 mod 4.
```

The current row4/5 source witness is consequently a **valid relation-gauge nonzero-Z4 witness**. Fixture bytes, field bytes and A3 source-route authority must not be retuned or replaced. The test's current assertion `witness.sourceRotation == relation.action().rotation` is not generally valid as a contract; for this concrete witness it happens to agree only because both occurrence gauges are zero.

The independently expected full action for any produced A4 endpoint states on this witness is then uniquely

```text
T = (3, rotate(3, x_R,to - x_F,from)),
```

with the second endpoint map as an independent equality check. This gives a concrete expected nonzero rotation and a non-fitted exact translation construction before downstream relation publication. `M5-CP3-TB1-R14-REV-OBS-01` is **DISCHARGED**.

## 8. Static falsifiers

All DEFN-R1 acceptance falsifiers pass by derivation:

| Falsifier | Result |
|---|---|
| Gauge closure | **PASS.** `Q = G_R^-1 A G_F`; every branch and relation coordinate is converted into the named relation convention before comparison. |
| Direction uniqueness | **PASS.** Forward -> Reverse gives `T`; Reverse -> Forward is exactly `T^-1`. There is no best-of-two direction choice. |
| Storage invariance | **PASS.** `PeriodicRelationId` stays orientation-neutral; canonical reversal stores `T^-1` but semantic resolution returns `T`. |
| Zero-rotation reduction | **PASS.** `Q=I` makes relation normalization identity and leaves ordinary cell placement unchanged. |
| Nonzero witness non-vacuity | **PASS.** Existing torus witness independently derives relation-gauge `Q=3` before relation publication. |
| Translation consistency | **PASS.** The same `Q` normalizes Reverse coordinates and constructs `t`; partner endpoints only validate. |
| Stage ownership | **PASS.** `A` exists at A1/A3, `G_F/G_R` and raw integer states exist by A4/CP3; no A5/M6 state is consumed. |

No stop rule fires. The model uses no free gauge choice after the semantic Forward anchor, no minimum/stable-region heuristic, no pair insertion order, no floating search, no downstream output inspection, no inverse retry, no partner fitting and no fixture tuning.

## 9. Successor implementation boundary

Exactly one successor is authorized: `M5-CP3-CB17` under `Architecture_M5_CP3_CB17_Relation_Frame_Gauge_Cutover_Plan.md`.

CB17 is not allowed to reopen the model. It may only implement the frozen mapping at the producer/checked-product seam and update directly coupled focused test expectations that currently encode raw-A1-equals-relation-rotation as a general rule. It is runtime-free Code + Build: compile/package only, no generated runtime. Fixture/field/A3 authority and selector430 remain byte-identical.

The next runtime owner after a compile-green CB17 is a fresh `M5-CP3-TB1-R15-EXEC` followed by mandatory independent `M5-CP3-TB1-R15-REV`; neither is executed in DEFN-R1.

## 10. Accounting and carried obligations

Stable accounting remains **51 events / 14 categories / 37 recurrences** and produced-witness debt remains **3**. No accepted selector row changed and no runtime ran, so DEFN-R1 creates no stable event.

- `M5-CP3-TB1-R14-REV-OBS-01`: **DISCHARGED** by §7's independent concrete `Q=3` derivation.
- `M5-CP3-TB1-R13-REV-OBS-01`: remains **DISCHARGED AS TRIGGERED**; its prohibition on `CB17` is satisfied because CB17 was not authorized until this definition completed.
- `M5-CP3-TB1-R6-REV-OBS-01`: **CARRIED to R15 Review**; produced row4 must independently confirm semantic Forward -> Reverse action and reject the inverse-pair alternative once it reaches that comparator.
- `M5-CP2-TB1-REV-OBS-01`: **CARRIED**; selector publication remains prohibited until a complete corrected CP3 pre-publication gate is green and independently reviewed.
- `M5-DEFN-REV-OBS-01`: **CARRIED** under its existing owner; DEFN-R1 does not consume M6 authority.
- two nonzero-Z4 M5 produced debts: **CARRIED to CB17 -> R15 runtime/Review** with the existing discriminators unchanged.
- broader endpoint-gauge `RP-01` chain: **definition ambiguity CLOSED here; product recovery remains OPEN** until R15 runtime proves the implementation.

## Definition closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 remains `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; no selector byte changed. |
| Decisive claims independently re-derived | Exact source-frame/cut-gauge algebra `Q=G_R^-1 A G_F`; reverse/inverse action; anchored translation; committed torus principal matching has exactly five nonzero transitions and all five are accepted cuts, so retained-dual gauge is identically zero; canonical `(0,3)` Forward/Reverse ownership is `22 / 1`; semantic `A=3`, hence relation-gauge `Q=3`. |
| Non-vacuity checked | Current row4/5 witness is relation-gauge nonzero before relation publication; its expected `Q=3` is derived without downstream pass/fail, so the new definition can be falsified by a wrong implementation. |
| Prior obligations discharged/carried | R14 observation discharged; R13 trigger remains discharged; R6 direction, CP2 publication, M5-DEFN observation, two nonzero debts and product recovery carried as §10 states. |
| Stable accounting | **51 events / 14 categories / 37 recurrences**, debt **3**; accepted runtime package/source `10601978228 / 0798547d...`, selector430 430/430; R14 candidate remains unpromoted. |
| New candidates/obligations recorded | No new stable candidate/category. Existing `M5-CP3-TB1-R14-CAND-01` definition ambiguity is resolved; implementation recovery is assigned to CB17/R15. Tracker updated. |
| ORIENTATION currency line | `M5-CP3-DEFN-R1`, 2026-09-23 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated for frozen gauge authority, valid torus `Q=3` witness, CB17 priority, discharged R14 observation and existing RP-01 instance. |
| CHANGELOG | Root and Directional changelogs updated with DEFN-R1 freeze and CB17 successor. |
| ROADMAP | M5-CP3 updated to DEFN-R1 complete / CB17 next. |
| Selector manifest | n/a — no selector identity, ordering, hash or acceptance state changed. |
| LESSONS | Existing authority-domain/gauge lesson cited; no new lesson number because this is another `RP-01` authority-domain instance. |
| Consolidation under CLEAN_UP_POLICY | **Not authorized in this Definition turn.** No durable plan/review document is folded or deleted; the existing Review-created folded-document index is left unchanged. DEFN-R1 adds §4.19 plus this Definition Record and one bounded CB17 plan. |
| Successor frozen | Exactly one successor: `M5-CP3-CB17`; falsifiers and stop rules are frozen in `Architecture_M5_CP3_CB17_Relation_Frame_Gauge_Cutover_Plan.md`. |
| Turn boundary held | Yes — runtime-free definition/review; no product/test/fixture/selector/benchmark/build source changed and no Directional runtime/configure/compile/relink executed. |
| `review_check.py boundary` | **PASS / ALL CHECKS PASSED** after the complete additive/corrective documentation patch. |
| `STATUS` lifecycle maintained | Entry beacon published for `M5-CP3-DEFN-R1`; terminal COMPLETE with successor `M5-CP3-CB17` is reserved for the final repository mutation. |
| Repository transport / cleanup | **Closeout precondition:** terminal `STATUS` may become COMPLETE only after this documentation patch is durably applied, temporary control state is cleaned, and final branch sync is verified. |
