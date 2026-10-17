# M6-DEFN-R5-R4-DIAG — exact carrier-incidence diagnostic-fidelity audit

**Disposition: complete, runtime-free static audit.** The alleged `front=13,131;edge[0]=1,2:faces=0,3` cross-contamination is **not substantiated**. Five such records originate in a **component-local vertex numbering** where local edge `(1,2)` corresponds exactly to original hard rail `(1,4)`, genuinely incident to source faces `{0,3}`. There is no demonstrated carrier/index contamination in any of the **38 records containing explicit carrier diagnostics**. The remaining **one** of the frozen 39 family contains no carrier/route receipt, so no assertion about an *observed* carrier can be made for that row. The independent design Review remains mandatory; the RA-41 candidates are **not frozen** by this audit.

## Authority and boundaries

- Source snapshot: `f1a893fae1a9a551c74046f60ec3f4fbbba4ee3f`, workflow `38038737771`, source artifact `11663934711`, outer ZIP SHA-256 `878cf5cc187e34bc98bedd183b92d3b791835083e78219a69518bc9ab7a038b2`.
- Exact archive `source.tar.gz` and all **5,837** snapshot file checksums verified locally. This is a static source analysis; no Directional runtime, compiler, tests, benchmarks, source, fixtures, producer semantics, or selector changed.
- Immutable R3 first-failure inputs: `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv`. The full 39-row extraction and namespace-specific classification are in `Architecture_M6_DEFN_R5_R4_DIAG_Failure_Carrier_Inventory.tsv` (same identities, no fabricated runs).
- Pre-existing accepted evidence unchanged: CP2 `491/491`; R3 `403/497`, `94 RED`, `39` carried A4 endpoint rows, `88` accepted CP2 identities lost; stable ledger `66 / 17 / 49`, debt `1`.

## 1. Direct fixture: 3×3 grid and original global vertex IDs

`tests/SurfaceCellTransitionQuotientTests.cpp:570–615` creates the eight triangle rows by iterating lower-left/lower-right/upper-right and lower-left/upper-right/upper-left for each square. `make_nonconstant_hard_rail_fixture` at `:761–836` repeats the same eight-row geometry, with only cross-field variation or an explicitly requested face-row reversal. The non-reversed source rows are:

```
0: (0,1,4)   1: (0,4,3)   2: (1,2,5)   3: (1,5,4)
4: (3,4,7)   5: (3,7,6)   6: (4,5,8)   7: (4,8,7)
```

The true source incidences are `(1,4) → {0,3}`, `(4,7) → {4,7}`, and original `(1,2) → {2}` (boundary). Source-geometry incidence was re-derived by enumerating all triangle edges rather than trusting the diagnostic. The 21 frozen `front=17,203` records and 12 frozen **noncompacted** `front=13,131` records print carrier `(1,4):faces=0,3` and agree with that construction. Their `faceEnds=0,2|0,3` values are trace-endpoint source-face rows, **not** independently certified terminal rail-side contacts.

## 2. Component fixtures: why local `(1,2)` legitimately owns `{0,3}`

`tests/SurfaceCellsPhase10Tests.cpp:223–271` builds *two disconnected copies* of the same eight-triangle grid, at z=0 and z=2, with global hard features `(1,4),(4,7)` and offset copies `(10,13),(13,16)`. Five frozen failures use the component pipeline (`remesh_surface_cell_components_from_cross_field_{counterfactual,final_validation_counterfactual}`); these call `remesh_surface_cell_components_from_cross_field_aggregate_impl` (`src/pipeline/RemeshPipeline.cpp:16928`) and then `compact_face_components`.

`src/geometry/MeshComponents.cpp:72–116` assigns local vertex IDs by **first encounter walking sorted face rows and their three corners**, not by preserving the original vertex numbering. In the first component the exact original→local mapping is:

```
original 0→local 0; 1→1; 4→2; 3→3; 2→4;
         5→5; 7→6; 6→7; 8→8.
```

Thus original hard rail `(1,4)` becomes **local `(1,2)`**, with local face rows `{0,3}`. Conversely original **boundary** `(1,2)` becomes local `(1,4)` with face row `{2}`. The second component uses the same local mapping relative to its nine-vertex offset. The published diagnostic `front=13,131;edge[0]=1,2:faces=0,3` in those five tests is therefore **correct in the component-local mesh**. Reading that local key against the un-compacted 3×3 fixture produced the apparent contradiction. The `front` indices themselves are only indices into a fixture's own `phaseFrontState.edges`; matching the same numbers between test fixtures does not establish a common mesh or globally shared edge identity.

## 3. Exhaustive 39-family static inventory

| Observed record group | Count | Mesh namespace | Carrier | Source incidence | Finding |
|---|---:|---|---|---|---|
| `front=17,203` | 21 | Direct original 3×3 | `(1,4)` | `{0,3}` | Matches |
| `front=13,131` | 12 | Noncompacted original 3×3 | `(1,4)` | `{0,3}` | Matches |
| `front=13,131` | 5 | Per-component compacted 3×3 | **local** `(1,2)` | `{0,3}` | Matches; original `(1,4)` |
| No carrier printed (`selector:150`) | 1 | Two-component 3×3 pair | N/A | All four configured global midline rails each have two incident faces | No observed carrier to compare |

**All 38 emitted carrier records are exactly two-face internal carriers.** The 39th is the failed `RectangularInternalHardFeatureProducesAuthoritativePhaseFrontPerComponent` expectation at `tests/SurfaceCellsPhase10Tests.cpp:6595–6640`: its first diagnostic only reports failed `produced[]` and `regionCounts[]` checks, not a route. Its configured rails have two source-face incidences each, but the omitted producer route cannot be reconstructed from that log. Do not claim 39/39 carrier receipts matched, and do not extrapolate from absence of a logged invalid carrier to an unseen front.

## 4. Diagnostic provenance and pre/post-validation boundary

`src/geometry/SurfaceCellTracing.cpp:18287–18362` counts actual source-edge incidences from the **current** `faces` argument; rejects an absent edge or edge with more than two incident faces; obtains two distinct incident rows and forward/reverse A3 transport before publishing `phaseFrontState.hardRailFieldTransitions`. Boundary one-face hard features are permitted as *boundary features* and publish no cross-edge transport. The paired crossing loop starts around `:18384`. The error detail at `:18406–18449` prints:

- `front=...` from the current `phaseFrontState.edges` pair;
- `faceEnds` directly from `first.from.face`, `second.to.face`, `first.to.face`, `second.from.face` (trace endpoints);
- `edge[i]` from `first.route.oriented_steps()[i].topology()`;
- `faces` from the matching published hard-rail transition's **source-topology keys**, resolved using the same current `network.sourceTopologyRegions`;
- `chi` from that transition's transported value.

That `edge[i]`/`faces` diagnostic is emitted **after A4's source-edge incidence and A3 carrier-transport checks and after local front construction**, but **on the rejection path before successful route-certificate publication and before the final `SurfacePhaseFrontProduct::make` checked factory**. Its displayed carrier incidence is not an independent proof of all semantic front attachments. Importantly, the print code does not select an arbitrary owner by `front` ordinal: it looks up the record by exact `entry.edge == route[i].topology()` and otherwise emits `owner=missing`. The five local `(1,2)` rows also independently match the component's source triangles. There is no evidence here of the hypothesized record-index cross-contamination.

`SurfacePhaseFrontProduct::make` (`:8037–8085`) permits a hard-feature edge with one source-face incidence **when no two-face transition is published**, and rejects 0 or >2 incidences; a **published hard-rail transition** does require exactly two faces and source/A3 matching. The separately written (not yet executed) `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences` test (`tests/SurfaceCellTransitionQuotientTests.cpp:1850–1975`) explicitly expects `EmptyCells` for a one-face boundary hard rail, `InvalidSourceAuthority` for absent/three-face rail, and an empty-cell gate for valid two-face rail. Therefore the earlier claim that *any* one-incident-face edge is forbidden as a hard feature is too broad. It is forbidden as an emitted two-face **cross-rail transition**, not as boundary authority.

## 5. Determination for mandatory R4 independent Review

1. **Correct the source-namespace premise** in the R4-next handoff and RA-41 D2 candidate: do not compare component-local `(1,2)` to the original fixture's `(1,2)`. The cited five records are valid local renumberings of original `(1,4)`; their printed `{0,3}` is independently confirmed.
2. **Retain the actual R3 failure.** `faceEnds=0,2|0,3` does not satisfy the current endpoint-carrier-face identity requirement for `(1,4):{0,3}` or compact local `(1,2):{0,3}`. The typed first predicate remains `endpoint-0`, and the producer terminates before acceptance. Nothing in this audit proves source-wedge contact, producer-owned terminal side, or the proposed RA-41.2 local-germ semantics. Do not wave the mismatch away merely because diagnostic carrier identity is correct.
3. **RA-41.2 stays candidate/unfrozen.** The Review should independently verify A2b/A3 producer-owned contact witnesses and gauge lineage before accepting/revising RA-41.1/.2 or releasing the held CB. The separately written four RA-40(C) supplemental tests stay unexecuted and outside the 497 gate. A new runtime case is not credited.
4. **No production mutation** (no fabricated face substitution, contact path, fixture change, loosened factory oracle, compilation, or test replay) is authorized by this diagnostic audit. The precise successor is `M6-DEFN-R5-R4-REV` after the final COMPLETE beacon.

**Static pass / scope pass:** source correlation and independently re-derived carrier incidences explain all 38 printed records; the single unprinted row is explicitly distinguished. This closes the bounded diagnostic-fidelity question, not the blocked semantic recovery plan.
