# M3-CP4c-3-TB37 — Independent Review Record

**Turn:** `M3-CP4c-3-TB37-REV` — independent review (absorbs REVIEW + PLAN).
**Status:** STATIC / EVIDENCE-ONLY / NO RUNTIME / NO COMPILE / NON-STABLE.
**Measures:** **CZ0–CZ6**.
**Adjudicated evidence:** `Architecture_M3_CP4c3_TB37_EXEC_Report.md`, immutable package102
`10032277517` / source `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`, selector409 run `34161464783`.
**Static-authority gate:** `review_check.py authority 89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d` — ALL CHECKS
PASSED.

---

## CZ0 — TB37 is mechanically valid and is promoted; packages advance to 102

All artifact-only preconditions hold: `script_exit=0`, `runtime_started/completed=true`,
`execution_view_verified=true`, `orchestration_failure=false`, `selection_integrity=true`, `timeout_count=0`,
every mutation/build/benchmark flag false; `ledger.tsv`, `identity-map.tsv` and `resource-summary.tsv` each **409
rows**; package, source and execution-view censuses byte-identical before and after; `SHA256SUMS` 28/28; the six
runtime executables retained mode `0755`; selector409 hashes to the frozen
`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.

**Result: 402 PASS / 7 RED, accepted 1–365 = 365/365, RED `[366,367,368,369,370,374,398]`** — identical to TB36.
Ordinals 312, 390, 393, 404, 406, 407, 408, 409 PASS; ownership `300 / 0 / 0`; both retired codes silent.

**`M3-CP4c-3-TB37` is promoted to current valid semantic runtime authority; package count advances to 102.**

---

## CZ1 — CB42's "diagnostics only" claim is proved by artifact, not asserted

CY6 required that CB42 change no behaviour at all, and the evidence proves it in the strongest available form:
**`ledger.tsv` and `identity-map.tsv` are byte-identical to TB36's** — `058c5460…` and `f33cd349…` — while the
**failure-detail digest table differs** (`2b6ca8d2…` vs TB36's `02734fd9…`), which is exactly what adding
diagnostic fields to an unchanged failure should produce.

This is the first turn in which the failure-detail digest table earns its keep in the **positive** direction. It
was introduced after TB32 and TB33 produced ledger hashes identical to their predecessors and the identity could
not be distinguished from a stalled turn (`LESSONS.md` 141). Here an identical ledger is the *desired* outcome, and
the second digest is what makes "identical pass/fail, changed evidence" a provable statement rather than an
ambiguous one. `LESSONS.md` 151.

CB42's pre-implementation grep also found **no test-source assertion** of `RegionEulerCharacteristicNotOne` — the
CY6.5 obligation discharged — and ordinal 312's and ordinal 409's test blocks stayed byte-identical
(`94724bef…`, `ea574dab…`).

---

## CZ2 — the discriminator resolved, and every independent check closes

TB36-REV derived, from four published numbers and the fact that source faces are triangles, that the frontier
reduced to one integer: **χ_true = X + B_int − 47**, with `X + B_int = 44` meaning the region is not a disc and
`= 48` meaning the reduced formula is wrong by exactly 4. CB42 published the terms and TB37 measured them.

```text
X = regionExcludedVertexCount        = 36   (= 0 mesh-boundary + 20 boundaryVertices + 16 allOwned)
B_int = regionInteriorBarrierEdgeCount = 12
regionSubmeshBoundaryEdgeCount       = 20
regionSubmeshBoundaryVertexCount     = 20
regionVTotal / regionETotal / F      = 136 / 385 / 250
regionChiFull                        = 1
reduced V_int / E_int / F / χ        = 100 / 353 / 250 / −3
```

Seven checks, each independent of the report's own arithmetic:

| Check | Value | Result |
|---|---|---|
| discriminator `D = X + B_int` | `36 + 12` | **48** |
| TB36-REV identity `χ_true = X + B_int − 47` | `48 − 47` | **1** |
| direct full Euler `V_total − E_total + F` | `136 − 385 + 250` | **1** |
| `V_total = V_int + X` | `100 + 36` | **136** ✓ |
| `E_total − E_int = B_int + E_one` | `385 − 353 = 32`, `12 + 20 = 32` | ✓ |
| TB36-REV incidence prediction `E_one = 44 − 2·B_int` | `44 − 24 = 20` | **= 20** ✓ |
| triangle incidence `2(E_int + B_int) + E_one = 3F` | `2·365 + 20` | **750** ✓ |

**Every check closes, including two that TB36-REV predicted before the numbers existed** — the value of `E_one` and
the incidence total. The derivation is confirmed on evidence it did not have.

---

## CZ3 — verdict: the region is a disc, and the reduced certificate is wrong by exactly 4

**The frontier is `CERTIFICATE_ARITHMETIC`.** The region's source sub-mesh is a genuine triangulated disc —
`V=136, E=385, F=250, χ=1`, and `sourceFacesConnected` is already established — while the certificate publishes
`χ = −3` and rejects it.

**And the diagnosis is sharper than "the premise is false".** The reduced formula drops the boundary terms on the
claim that `V_boundary == E_boundary`. Decomposing the 4-point gap:

> `(V_total − V_int) − (E_total − E_int) = 36 − 32 = (20 − 20) + (16 − 12) = 0 + 4`

**The premise is correct about the actual boundary.** The sub-mesh boundary proper — source edges with exactly one
incident face in the region — is 20 edges against 20 vertices, so it does cancel, exactly as the comment at
`GlobalTopologyPlan.cpp:2097–2098` claims. The entire error is in the residual: the certificate additionally
removes **12 interior barrier edges** from `E_int` (`:1848–1850`) and **16 further vertices** from `V_int` via the
`allOwned` test, and those two exclusions do not balance.

**Those 12 edges are interior to the sub-mesh, not boundary.** A barrier edge with both incident faces in the
region — a terminal slit is exactly that, and this fixture publishes ten — is a real interior cell of the counted
complex. The certificate misclassifies it as boundary, drops it, drops its endpoints, and the counts stop
agreeing. **The defect is not the cancellation premise; it is that the certificate's notion of "boundary" is the
network's barrier set rather than the sub-mesh's actual boundary.**

This retires the last remaining ambiguity in `M3-CP4c3-TB34-REV-CAND-03`, open since TB34.

---

## CZ4 — what the correction does **not** resolve, and must not be assumed to

`chiFull` is computed over the **whole-face sub-mesh**: `submeshVertices` and `submeshEdges` are accumulated from
`region.sourceFaces` (`GlobalTopologyPlan.cpp:2166–2176`), and `faceCount` is `region.sourceFaces.size()`.

But **the region the plan actually built is not that set.** Its boundary is the network walk, which includes
**trace arcs — chords through face interiors**, not source edges. A trace-cut face is assigned **wholly** to one
region, because `fragmentOrbits[face]` is rejected unless `certifiedFaceOrbits.size() == 1` (`:1405`, applied at `:1432`). So the
sub-mesh is the region **rounded to whole faces**, and `chiFull = 1` certifies that rounding — not the traced
region.

The 16 `allOwned`-excluded vertices are the visible symptom of the same tension: they are corners owned by another
orbit inside faces this region owns whole.

**This does not block the correction.** `V_int`, `E_int` and `F` are *already* whole-face sub-mesh quantities, so
moving to `chiFull` fixes the arithmetic **over the object the certificate already counts** and changes no
ownership convention. But the successor must say so normatively, or a later turn will read `χ = 1` as a statement
about the traced region. New candidate **`M3-CP4c3-TB37-REV-CAND-01`**.

---

## CZ5 — classification and accounting

| Ordinal | Classification | Owner |
|---:|---|---|
| 366 | **Frontier, now diagnosed.** `RegionEulerCharacteristicNotOne` with `D=48`; the region is a disc and the reduced formula is wrong by 4. | `M3-CP4c3-TB36-REV-CAND-01`, **decided**; correction owned by **CZ6** |
| 367 | **Same datum as 366** — failure detail byte-identical (`d27c5179…`), same region, same orbit. | as above |
| 368 | Carried, unchanged — prescribed sphere, `NoCarrierMatch / SourceEdgeUnavailable`. | AL4 / `M3-CP4c2-TB-X2-CAND-04` |
| 369 | Carried, unchanged — `saturationUsed=true` where ordinary proposal is required. | prior saturation owner |
| 370 | Carried, unchanged — empty closed-surface network, wrong typed code. | prior owner |
| 374 | Carried, unchanged — folded-cone witness, `atlasBuild` false; corrective is test-only. | prior deferred owner |
| 398 | Carried, unchanged — publishes `sourceFaceCount=300; ownerMapCount=300; provesCellularity=true`; torus `144/144`. | `M3-CP4c2-TB-X2-CAND-04` |

**No new RED ordinal, no accepted-prefix loss, therefore no stable event.** Totals remain **45 events / 14
categories / 31 recurrences**, produced-witness debt **5**; packages advance to **102**. CP4c-3 remains **OPEN**.

**A second consecutive EXEC process-order miss is recorded.** TB36 read documents before its `READ_MODE` choice;
TB37 created `.agents/connector-triggers/turn-cleanup/manifest.txt` during setup, and because the durable cleanup
workflow is push-triggered on that path it fired run `34161412687` before the TB37 caller existed. That run
completed, removed only then-inventoried temporary setup state and PR comments, executed no Directional binary and
did not touch package102 — so the semantic evidence is intact and this is control-plane only. **Two misses in two
turns is a pattern, not an incident:** in both cases a setup action reached a trigger before the turn's own
ordering gate. `LESSONS.md` 152.

**Candidate dispositions.**

- `M3-CP4c3-TB36-REV-CAND-01` — **DECIDED**. The two claims were mutually exclusive; the measurement chose. The
  certificate arithmetic is wrong; the region is a disc.
- `M3-CP4c3-TB34-REV-CAND-03` — **CLOSED**. Its Euler branch, open since TB34, is now diagnosed to the cell.
- **`M3-CP4c3-TB37-REV-CAND-01`** — new, **ACTIVE / ARCHITECTURAL**: the certified object is the region *rounded to
  whole faces*, not the traced region. Not blocking; must be stated before it is silently assumed.

---

## CZ6 — exact successor: `M3-CP4c-3-DEFN-R6`, appending **Part X**

**A definition turn, not a Code + Build turn.** The reason is specific, not procedural: the change alters a
**certificate acceptance criterion** — `proves_disc_topology()` depends on it — and this checkpoint has already
paid once for implementing a correction whose contract was not written first (CU4, one accepted-green event,
`LESSONS.md` 144). DEFN-R5.5 also named a *"later review/DEFN"* as the deciding authority and forbade correcting in
the measurement turn; this review supplies the finding, and Part X must supply the rule.

**Part X must decide, and no more:**

1. **The counted complex, named explicitly.** The region certificate counts the **whole-face source sub-mesh**:
   all distinct vertices and edges of `region.sourceFaces`, and `F = |region.sourceFaces|`. State that this is the
   certified object and that `χ = 1` is a claim about it, **not** about the traced region (CZ4).
2. **The Euler criterion.** `χ = V_total − E_total + F = 1` over that complex. **The reduction is withdrawn**, and
   the comment at `:2097–2098` must be deleted with it, not left to be re-derived.
3. **Why the reduction failed, so it is not reintroduced.** The boundary terms *do* cancel — 20 against 20. The
   error was classifying **interior barrier edges** as boundary and dropping them and their endpoints
   asymmetrically. State that a barrier edge with **both** incident faces in the region is an **interior** cell of
   the certified complex.
4. **The equivalence condition**, so the blast radius is bounded rather than guessed: reduced and full agree
   exactly when `X = E_one + B_int`, which holds for any region with no interior barrier edges and no
   ownership-excluded interior vertices. **Part X must require the implementing turn to prove this per region on
   every accepted fixture, not assume it.**
5. **What must not change.** Ordinals **312** and **409** byte-identical; selector **409** byte-frozen; accepted
   **1–365** untouched; no work on 368/369/370/374/398; no ownership, partition-unification, retired-guard,
   sphere, saturation, folded-cone or finalize/contact change; **no change to region construction** — CZ3 shows
   the region is correct and the certificate is not.

**Falsification, to be carried into the implementing turn `M3-CP4c-3-CB43`.**

- **Accepted prefix 365/365 and ordinals 312/409 PASS are stop conditions.** No accepted identity asserts
  `RegionEulerCharacteristicNotOne` (CB42's grep), so the risk is **not** a direct assertion — it is that a region
  which currently fails Euler will now pass and reach stages never previously executed on it.
- If 366/367 clear region certification, the correction is confirmed and the frontier moves to whatever stage they
  reach next. **That is expected, and a new failure there is a new frontier, not a regression of this one.**
- If 366/367 still fail Euler under the full count, the measurement and the implementation disagree and the turn
  halts.
- If any region on an accepted fixture changes verdict, condition 4 was false there and Part X's equivalence claim
  is refuted.

**Prohibited:** correcting region construction; changing ownership or the whole-face rounding while fixing the
arithmetic; forcing χ to 1 or special-casing a fixture; any accepted-identity or selector byte change; any
Directional runtime in the definition turn.

**Exact next turn: `M3-CP4c-3-DEFN-R6` — definition turn, static, appending Part X to
`M3_CP4c_Frozen_Definitions.md`.**
