# M6 CP3 R8 — accepted-boundary / chart-face authority specification

**Source:** exact verified snapshot e8db3859bce155218a64d83c30e87c57354be7ec; run 38868534647, artifact 12032341939, digest ae817b332a1fb8e862f036578c22211d8a9c194bfaf8d9796a5f94b1d638d0be. This is a documents-only Definition of RA-74's four questions; no code, runtime, tests, compile, selector or acceptance change. Independent Review is mandatory.

## 1. `acceptedBoundary` authority

In `src/geometry/SurfaceCellTracing.cpp:14983-14998`, `useAcceptedConformity` requires accepted global topology and conformity-baseline plans; `useAcceptedCutDomain` *additionally* requires a hard-feature source edge, so the two flags are not coextensive. Accepted boundary subdivisions (`:16817-17192`) derive from mandatory source-edge runs, topology arc, baseline subdivision/breakpoint schedule, exact edge parameters and a source-edge incident-face row; cut-domain mode additionally checks accepted orientation/span. They control grid interval counts and boundary UV (`:17204-17253`). At `:17266-17281` the complete accepted point replaces the chart sample on a grid boundary.

Authority proved: accepted ordered source-edge boundary occurrence/position/subdivision parameter with coherent face-relative barycentric representation. Not proved: its `.face` must equal the independently sampled chart's face, be the unique incident face, or be the correct face of both incoming/outgoing *directed-side* carriers. The accepted boundary face is chosen from run source faces (`:17117-17118`, `:17139-17140`), not via chart's minimum-face selector. Never replace only `.face` without transporting barycentrics.

## 2. Guard and measured cohorts

The actual predicate (`:17266-17280`) is `v==0 || u==gridU || v==gridV || u==0` under accepted conformity; it selects every grid-boundary node and knows nothing about the 21 failures/23 historical controls. A changed published face at 21 `SecondFrom` endpoints (sampled 3, published 7) confirms a boundary substitution there but cannot exhaust all boundary nodes; an unchanged `FirstTo` face 0 may also have been replaced. The newest TB7 has *27* `producer=none` control occurrences (54 endpoint records) whose `(u,v)` and override state were not measured; the older R5 controls numbered *23*. Without cross-vintage identity mapping, neither “21 exactly boundary” nor “23/27 exactly interior” is established. Do not code to these cohort counts.

## 3. Owning face

**Proposed binding authority, subject to independent Review:** accepted conformity owns the published source-edge point and its face-relative location; chart sampling owns interior samples and the preliminary competing representation at a boundary. Face 7 versus sampled face 3 can represent the same source vertex (faces 3/6/7) and is not itself a producer fault. But **neither face is a unique directed-side carrier certificate**. The current producer lacks exact source-entity/component/sheet equivalence between sampled and overwritten points and per-directed-side incidence proof with chart/entry route. Published side paths already contain individual face, barycentrics, source chart and entry route (`:17376-17406`); positional-only closure check (`:7319-7366`) does not prove their relation.

Reframe RP-01 as missing boundary-point-to-directed-side carrier reconciliation, NOT a proven downstream-only bug. If accepted/chart points are different source entities/sheets, reject the invalid upstream override; if they denote the same point but raw face equality is demanded, repair the consumer representation contract. Neither branch has a runtime proof; RP-01 remains open.

## 4. RA-65.5 and RA-72.5 admissibility

| Candidate | Decision |
|---|---|
| Replace accepted boundary with preliminary sample, or force its face to minimum | Unauthorized: may discard schedule/edge/orientation authority; no equivalence certificate. |
| Require raw face equality at override or side consumer | **Relocation only (RA-72.5):** rejects same 21 earlier, creates no successful cell and can reject legitimate incident-face alternatives. |
| Force face 3 while retaining face-7 barycentrics | Invalid: face-relative coordinates not transported. |
| Preserve accepted edge placement and reconcile exact canonical source-entity/sheet and side-specific face/chart/route using existing producer records | **Admissible *shape* only, not implemented.** Accepted edge/baseline schedule, `SourceChartTransitionGraph`, and source-attached directed-side paths exist; association and consistency still need independent proof. |
| Publish separate directed-side face/chart/entry route rather than one corner face for both sides | **Admissible shape only** with verified side incidence, not an invented authority. |
| Invent a vertex-star route for nonincident face | Forbidden under RA-65.5: vertex-keyed producer absent; Gate C suspended. |

**Independent falsifiers, not executed:** F1 cross-entity/sheet merge; F2 reject a valid alternative incident face; F3 treat raw face inequality/equality as identity proof; F4 admit wrong side-carrier/orientation/region; F5 only relocate 21 RED without output; F6 perturb accepted boundary order, hard rails or subdivision; F7 regress deterministic/accepted selector behavior. Future repair needs reviewed Definition first, separate Code+Build, immutable Test+Benchmark and Review; no success is claimed here.

**Frozen:** ledger 66/17/49, debt1; CP2 491/491 accepted; CP3 R3 403/497 rejected; selector497 fixed; prior R7 44/44 RED candidate baseline; RP-01 open, RP-02 unreached. **Next:** independent static `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC-REV`. No repair implementation authorized before approval.
