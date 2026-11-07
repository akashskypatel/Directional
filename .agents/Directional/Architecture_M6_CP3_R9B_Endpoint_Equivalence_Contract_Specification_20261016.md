# M6 CP3 R9B — endpoint equivalence contract (Definition)

**Turn:** `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` (rung 19b). **Scope:** static, documents-only definition. **Authority:** accepted R9A census / RA-78, `TODO.md`, and the frozen M6 constraints. **Inspected source:** `src/geometry/SurfaceCellTracing.cpp`, exact snapshot commit `6eda761ddb5ecaea5a8c2c25794ef166843a41a8`, workflow 38901551349, artifact 12047105604, outer ZIP SHA-256 `74a2ea191e777cd186ceeb0d272e4b7ccae6e2112477a95934b9b04f90abbc57`, 5,676/5,676 file hashes verified. The working algorithm's semantic source remains `f0d7240455b10237af47de58c035cd4c576d889a`. No code or runtime evidence is newly generated here.

## 1. Exact scope and source authority

The relevant objects are **two opposite directed hard-rail front-edge endpoints**, their `SurfaceTracePoint` face/barycentric representations, the published canonical rail edge and ordered A3 carrier face/transport record, the open-rail terminal-contact authority (when present), and their **per-side** source-chart attachments. The *representation face* is a valid chart for decoding source identity; it is not itself the carrier-side identity. Conversely, a common source vertex is **not** a certificate of common sector or correct carrier orientation.

No direct `fromPoint.face == toPoint.face` comparison exists. The constructor's `oriented_carrier` requires the ordered carrier faces to match endpoint-derived attachments (`:19253-19261`, `:19332-19334`, `:19372-19388`); its vertex `path_to` takes those representative attachments as A3 path starts (`:19425-19494`). The independent checked-product verifier (`:8621-8736`) separately validates the published carrier and each contact path; its nonvertex branch still imposes literal attachment/carrier equality (`:8662-8674`) and exact rational edge-position identity (`:91-97`). A change to only one checker is explicitly **not** a repair.

## 2. Proposed authoritative contract (to be reviewed before implementation)

The contract is a *branch-specific equality plus connectivity predicate*, not a blanket equivalence relation on arbitrary face rows. Resolve the two endpoint representations through their actual source-face corners, exact barycentrics, source topology/region and the published carrier. Preserve their original chart rows as provenance. Then classify the endpoint under exactly one of these cases:

### V — open-rail terminal vertex, existing consumer-side relation

1. An independently published `hardRailTerminalContacts[rail]` exists. Its component agrees with both endpoints' actual source components; the terminal source-vertex ID is **one of its published endpoints** and an endpoint of the named carrier's canonical source edge. The selected vertex must be unique (not an ambiguous terminal-contact match).
2. **Each** `SurfaceTracePoint` decodes the **same** `SourceVertexId` from an incident source triangle, with **bit-exact one-hot barycentrics** in its own face. Zero-distance 3D proximity, an inferred face, a rounded barycentric, or the rail-edge ID alone is not equivalent. Preserve original `firstAttachment` and `secondAttachment` from those faces; do not force either representative face to the carrier face.
3. The carrier is the published edge/ordered face pair and matches the actual A3 quarter-turn (or its verified inverse), with correct rail, route, reciprocal side, component and interval authority. For each side, independently compute a **unique admissible** non-hard-feature A3 source-vertex-star path from its *actual attachment face* to the corresponding **oriented** carrier face. A zero-step path is valid only where the attachment equals that carrier face. Every nonzero step must be incident to the same source vertex, use valid manifold spoke incidence and reciprocal A3 transport, avoid hard rails, and preserve visited-face uniqueness.
4. Both oriented carrier choices must be evaluated, with **exactly one admissible orientation**. The two directed-side face sets (including starts and steps) must be disjoint; neither can consume the other's sector. Require the same no-repeated-face, hard-edge exclusion and A3 evidence when reconstructing and when independently checking the product. Publish the two exact path sequences and their original attachment keys; no synthetic producer-side vertex-star certificate is introduced.
5. `Unique` is necessary **for each side**, but not sufficient by itself: published carrier identity, distinct sectors, non-overlap, correct orientation, paired interval/route, terminal authority, source sheet/component and the other existing gates remain independent conjuncts. `Missing`, `Ambiguous`, `Invalid`, nonreciprocal A3 and competing valid carrier orientations are all fail-closed.

**Source precedent / producer test:** The checked-product verifier already enforces exact terminal attachment at `:8649-8660`, published carrier and `matchesA3` at `:8621-8644`, consumer-computed `unique_terminal_star_path` at `:8452` and `:8685-8699`, every claimed contact step and disjoint sectors at `:8701-8728`. The constructor already reads original source-point faces, topology, field atlas, `sourceEdges`, `sourceEdgeFaceCounts`, `hardFeatureEdges` and published terminal contacts (`:19265-19494`); it computes its own `path_to` and disjointness. These are **existing producers/inputs**, not speculative new witnesses. The implementation must align their **acceptance** and preserve independent recomputation; copying an unchecked proposed path into the product is insufficient. The existence of this valid *contract shape* is not a proof that any of the 21 observed failing endpoint pairs satisfies all its conjuncts.

### I — open-rail interior carrier point, deliberately NOT relaxed

If no exact published terminal vertex matches both points, the accepted alternative remains **strict**: both endpoints must decode to strictly interior points on the *same published canonical carrier source edge*; the parameters obtained by `interior_carrier_parameter` must each exist and be **exactly equal as `FieldExactRational`**, with barycentric sum exactly one and the opposite barycentric exactly zero. The paired side attachments must match the carrier's ordered face pair (or the verified inverse); the contact paths must be empty, reciprocal shared-boundary interval/ordinals and other already-enforced conditions remain mandatory. The independent verifier must enforce the same (`:8662-8674`). A front endpoint that is at a nonterminal vertex, off-edge, foreign-sheet or face-interior point cannot enter this branch by reclassification.

**Explicit limitation:** RA-76 measured 324/324 boundary/chart edge-parameter pairs on the same edge differing by exactly one ULP; `same_interior_carrier_point` (`:91-97`) returns false for any unequal exact rationals. This specification **does not** authorize accepting those pairs, a tolerance, rounding, moving points, or canonicalization from near equality. Whether they represent the same intended geometric point requires a separate independent exact producer-origin witness or a separately reviewed reconstruction of a single canonical parameter; neither has been established for this definition turn. A candidate that changes this must return for review. The 21 currently localized cases are vertex observations, not evidence to relax the interior gate.

### C — contact-free closed rail, deliberately NOT promoted to V

Absent an open-rail terminal contact, the producer must present an independently published simple cyclic source-vertex chain with source-component agreement, complete source-owned hard edges and ownership of the endpoint carrier (`:19288-19339`). It retains its existing *literal* attachment/carrier orientation check. The independent verifier's no-contact branch (`:8729-8735`) likewise requires no terminal vertex/paths and literal attachment/carrier agreement. **Do not invent terminal-vertex authority for a closed rail.** A future closed-chain attachment generalization requires separately published cyclic-sector authority and a separate review. This branch does not license a V-style path today.

## 3. Two-checker correspondence (mandatory acceptance proof)

| Obligation | A4 endpoint certificate (construction) | Checked-product verifier (independent) |
|---|---|---|
| Source contact and face attachments | `:19265-19367`: valid face rows, canonical topology, exact contact/corner, component | `:8390-8452`, `:8590-8684`: re-derive actual attachment rows, contact component, exact corner |
| Carrier orientation | `:19244-19261`, `:19332-19388`, `:19455-19494`: only a published carrier, one oriented choice | `:8621-8644`, `:8685-8699`: `published_carrier`, `matchesA3`, both directed faces |
| Vertex-star path | `:19393-19450`: real non-hard-spoke A3 adjacency; unique path | `:8452-8490`: recompute `unique_terminal_star_path`, reject `Missing`/`Ambiguous`/`Invalid`; `:8701-8728` validates every published step |
| Side separation | `:19467-19494`: disjoint face sectors; no competing orientation | `:8701-8728`: no repeated face, hard-rail crossing or intersection between side sectors |
| Interior position | `:19372-19388`, `:91-97`: exact carrier edge parameters and interval evidence | `:8662-8674`, `:91-97`: empty paths, literal carrier faces, exact parameter equality |
| Closed chains | `:19288-19339`: independent chain, hard-edge, component ownership | `:8729-8735` plus earlier certificate checks: no synthetic terminal and strict faces |

The implementations are not literally identical: for example constructor `path_to` checks reciprocal atlas steps whereas the independent verifier also calls `matchesA3`. **Pass/fail equivalence is a goal subject to implementation Review and independent tamper oracles, not an asserted fact.** Preserve the verifier as an independent oracle; do not make it accept merely because a certificate constructor returned non-null.

## 4. Non-weakening counterexamples and stop rules

| Counterexample | Required disposition |
|---|---|
| Same 3D position but different canonical source vertex / sheet or wrong component | Reject before path search (exact vertex/source authority). |
| Same source vertex encoded by a different incident triangle, but **no** admissible non-hard-feature A3 path to carrier face | `MissingTerminalA3Path`; no acceptance by vertex equality. |
| Same vertex with **two** admissible distinct simple star paths | `AmbiguousTerminalA3Path`; do not choose lexicographic shortest, first, or average. |
| A3 transition absent, nonreciprocal, mismatched field transport, nonmanifold spoke or hard rail crossed | Reject invalid/missing authority; no guessed transition. |
| Both sides individually unique but face sectors overlap, or both carrier orientations admissible | Reject overlap/orientation ambiguity; unique sides are not enough. |
| A contact vertex not on named carrier edge, not a published terminal, non-onehot point or nonmatching endpoint vertices | Reject; no inferred or near-corner terminal. |
| Interior points on same canonical edge but rational parameters differ by one ULP | Reject under I until a separately reviewed exact authority exists; no epsilon. |
| One point is strictly interior to a face, belongs to a different edge, or has nonunit/off-edge barycentrics | Reject; cannot borrow an unrelated face chart. |
| Missing open-rail contact represented as a closed rail without real simple cyclic hard-chain ownership | Reject; cannot synthesize closed-chain/terminal evidence. |
| Invalid reciprocal interval/rail ID/route, A3 mismatch or foreign hard edge even when geometric point matches | Reject under unchanged independent validators. |

**Falsifiers before any code:** (F1) a known vertex witness has `Unique` in one checker but `Missing`/`Ambiguous` in the other; (F2) a vertex witness's accepted face has no component-preserving A3 path to the actual published carrier; (F3) retaining exact edge parameter rejects the intended later interior production case, requiring separate evidence rather than silent relaxation; (F4) an altered carrier orientation or overlapping sectors passes either checker; (F5) a no-contact closed rail is accepted through an invented open-terminal route. Any F1/F2/F4/F5 defeats this contract shape; do not implement as a blanket rule.

## 5. RA-65.5 producer feasibility and RA-72.5 repair classification

| Candidate | Publisher/authority and classification |
|---|---|
| **V: consistently use existing consumer A3 path for exact open-terminal shared-vertex attachments** | `SurfaceTracePoint` face/one-hot barycentrics, typed terminal contacts and component, published carrier/field atlas, source incidence/hard-edge maps already exist before construction; checked product independently recomputes uniqueness. **Admissible repair specification conditional on both-checker proof.** No new producer-authored star witness. |
| **I: preserve exact interior parameters and aligned carrier attachments** | Already enforced in both active checkers. **Retain existing contract; not a fix** for one-ULP edge discrepancies. |
| **C: preserve independently certified closed-chain carrier and literal face agreement** | Existing closed-chain producer/checked verifier. **No extension authorized.** |
| Force the endpoint's representative face to the carrier face, reuse barycentrics unchanged, use 3D/epsilon snapping, or discard accepted boundary placement | Not justified by exact source authority; can alter true location or cross source sheets. **Forbidden/unsound.** |
| Add a raw face-equality guard at boundary producer or route validator; reject the same 21 earlier | Supplies **no passing cell**, does not reconcile source entities or sectors; **rejection relocation only** (RA-72.5), not repair. |
| Add a new producer-side rail-scoped vertex-star certificate to license a foreign face | No existing upstream publication at the needed stage (RA-65.5); **Gate C SUSPENDED**, disallowed. |
| Select a carrier orientation, star route or corner representative by minimum face index alone | Changes an underdetermined decision into arbitrary acceptance; **inadmissible**, may weaken `Missing`/`Ambiguous`. |
| Normalize unequal interior parameters or adopt tolerance | No exact shared-point witness published; **not authorized**. |

## 6. Independent future implementation/verification boundary

A subsequent code turn is **not yet authorized**. First, independent Review must adjudicate the V/I/C contract, exact comparison directions, closed-chain boundary, source-producer feasibility, F1–F5, and whether the existing constructor/verifier graph semantics can be aligned **without weakening**. If accepted, a *separately authorized* code/build turn may implement the smallest common semantic correction while retaining independent verification. It should have negative fixtures for every counterexample above plus positives where the same terminal vertex is represented in different incident face charts with a **single A3 path**, both orientations and boundary row permutations. Require no binary execution in that code/build turn; runtime belongs to a separately authorized artifact-only Test+Benchmark turn. Runtime success must be source-authoritative and fail-closed; no selector promotion or accepted-green claim follows from this definition.

No source/test/fixture/build/selector/harness/workflow mutation, compile, test, benchmark, generated binary, stable-accounting increment or `R4-VIN-01` rearm occurred in R9B. `RP-01` remains open; `RP-02` remains UNREACHED; Gate C stays suspended. Frozen 66 events / 17 categories / 49 recurrences, M6 debt 1, CP2 491/491 accepted, R3 403/497, selector 497 unchanged. PR #8 remains draft/open. The exact next **review turn name is not yet supplied by authority**; successor remains `UNKNOWN`, and no implementation successor is inferred.
