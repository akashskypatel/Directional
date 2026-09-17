# M4-CP-SCALE-TB12-R2 Review Record

**Turn:** `M4-CP-SCALE-TB12-R2-REV`
**Date:** 2026-09-17 UTC
**Boundary:** runtime-free REVIEW + PLAN
**Verdict:** **FOCUSED RED UPHELD / MULTI-COMPONENT ALGEBRAIC CYCLE SUPPORT MIS-HANDLED / EXISTING RP-07 / NON-STABLE / S5 UNACCEPTED**
**Exact successor:** `M4-CP-SCALE-CB16`

## 1. Scope and independent evidence

This Review does not execute a generated Directional binary, build, benchmark, CTest, discovery/list/help/version command, mutate a product/test/fixture/selector, or publish selector427. It independently re-opens immutable CB15 artifact `10517300204`, exact source `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21`, the TB12-R2 report/receipt, the retained genus-two fixture and the relevant atlas/cycle-basis source.

The candidate ZIP independently re-hashes to `dceab12b7fe9ee8feccf972837455b89f6fe8b4bc30b44ee4947fc2343bd2711`; its recursive manifest verifies **28/28**, metadata names exact source `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21`, source archive SHA-256 is `14a1eccff69d402b72bf803f47b0ebf778f96d9f2da87baf46b74b1e49873ebc`, preflight/build are `0/0`, source-status snapshots are clean, `runtimeExecution=false`, and GMP/GMPXX both occur in authoritative link evidence. The producer executable remains mode `0755`, SHA-256 `3c5ff0af1b1b3ba78781692b9661c8c59e167acc14793feae291104fcecd269c`.

Selector426 independently re-hashes to **426 LF rows / 426 unique**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; its exact first425 prefix remains `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, owners remain **30 authority-kernel / 280 producer / 75 completion / 41 validation**, and no selector427 exists. Retained genus-two fixture hashes remain OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, rawfield `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

The TB12-R2 runtime evidence remains exactly one focused process, **0 PASS / 1 FAIL**, with selector426 **0/426** and benchmark **0**. Outer production semantics remain `InvalidFieldTransportAtlas / field-transport-atlas/IncompleteCycleBasis / CycleOrderingFailed`, A3 absent. The diagnostic receipt is:

```text
cycleOrdering={row=14,kind=BoundaryLoop,supportEdges=34,uniqueFromFaces=34,reason=SupportEdgeReused,currentFace=0,sourceEdge=0-72}
```

## 2. Row-14 mechanism re-derived from source

`FieldTransportAtlas` derives one `DirectedCycleEdge` for every non-zero coefficient of a sparse `bundle.cycles` row, using only coefficient sign plus local edge/face topology. Before any quarter-turn composition, `order_cycle_steps` sorts those directed edges by `(fromFace,toFace,sourceEdge)`, rejects duplicate `fromFace`, chooses the least `fromFace` as `start`, then repeatedly follows the unique edge whose `fromFace` equals the current face.

The observed `supportEdges=34` and `uniqueFromFaces=34` independently exclude duplicate outgoing origins. The helper's first edge therefore starts at the least source face. The reported reuse is at `currentFace=0`; source-face IDs are non-negative, so this is the helper's canonical start face. `SupportEdgeReused` can only fire after the walk has returned to a `fromFace` whose outgoing edge is already marked used. Because the loop is bounded by all 34 support edges and fails on the reuse before successful full consumption, the first successor orbit closes back at face `0` while support remains unconsumed. The receipt is therefore **not evidence of a duplicated sparse edge**; it is evidence that one algebraic row contains more support than the first closed successor orbit.

The row classification is also independently consistent with the source. The failing region has fourteen interior local vertices and one boundary loop; the atlas assigns rows `[0,14)` to `LocalVertex` and the next row to `BoundaryLoop`, so row `14` is the first boundary-loop row.

## 3. Ownership: algebraic support is valid; the one-loop representation assumption is not

`directional::dual_cycles` builds an algebraic cycle basis. Vertex one-ring incidences are assembled first. A boundary row is then formed by summing the one-ring rows of all vertices in that boundary loop, after which rows/columns are sliced to retained inner support. This construction promises an algebraic cycle, not that every non-zero edge of the resulting row belongs to one simple connected face loop.

For the observed row, unique outgoing origins plus premature return to the start show that the existing single-loop walker has consumed only one successor orbit. The algebraic cycle invariant supplies balanced directed incidence, so the remaining valid support is represented by additional closed successor component(s), not by a duplicate origin that may be discarded. Replacing the row with only the first component, changing `dual_cycles` to erase support, or editing the retained raw field would change the algebraic object whose exact lift is being certified and is not an admissible repair.

The production defect owner is therefore the `FieldTransportAtlas` **single-simple-loop representation assumption**. This is a concrete instance of existing `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION`: a valid cyclic algebraic object is forced through one incidental linear walk.

## 4. Corrective semantic contract

The smallest correction keeps `bundle.cycles`, row partitioning, exact turning lifts, fixture bytes and field authority unchanged and generalizes only row-support ordering:

1. Require the same unique `fromFace` condition and the same valid directed adjacency for every support edge.
2. Partition the directed successor relation into **all closed components**. Starting from the least unused directed-edge tuple, walk until that component returns to its own start; then begin the next least unused component. Missing successors, duplicate origins, invalid adjacency, an open component, or any unconsumed edge remain typed failure.
3. Canonicalize each component from its least directed-edge tuple and order components by that canonical first tuple. Flatten the canonical components into the existing `FieldCycleWitness::steps` vector; no new semantic source/support is invented.
4. Compose every step exactly once. `QuarterTurn` composition is integer addition modulo four, so component ordering cannot change the algebraic total; the published `composedTransport` must still equal the exact row `turningLift mod 4`.
5. Preserve the exact sequence for every already-valid single-component row. Existing accepted one-loop witnesses must therefore remain digest/semantic equivalent.

The independent validator in `tests/FieldTransportAtlasTests.cpp` currently repeats the same one-contiguous-loop premise by requiring every next `step.fromFace` to equal the previous `toFace`. It must be corrected in the same Code + Build turn to validate multiple closed components independently: a discontinuity is legal only after the current component has closed, every component must close, the complete published support must match the independently derived row, and every support edge must be consumed exactly once.

## 5. Regression classification and accounting

`M4-CP-SCALE-TB12-R1-EXEC-CAND-01` remains:

**OPEN / PRODUCTION FIELD-TRANSPORT CYCLE-BASIS ORDERING DEFECT / `RP-07 CYCLIC_TOPOLOGY_LINEARIZATION` / NON-STABLE.**

TB12-R2 does not create a new candidate or stable event. There is no accepted-green loss: the S5 focus has never entered an accepted selector and TB12-R2 intentionally executed selector426 zero times. Accepted runtime authority remains package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

`M4-CP-SCALE-DEFN-OBS-04` remains open. Genus-two topology is proved, but admissible atlas authority and A3 reachability remain unproved. The next owner is `M4-CP-SCALE-CB16`; no selector427 or S5 credit is authorized by this Review.

Other carried CP-SCALE obligations remain unchanged: `M4-CP-SCALE-TB1-REV-OBS-01` (S1 calibration), `M4-CP-SCALE-TB2-REV-OBS-02` (zero-transport helper audit) and `M4-CP-SCALE-DEFN-OBS-01` (S2 arrival exact fallback). `G4-B002`/`G4-B003` debts retain their milestone owners.

## 6. Exact bounded successor

Exact successor is `M4-CP-SCALE-CB16` under `Architecture_M4_CP_SCALE_CB16_Multi_Component_Cycle_Support_Code_Build_Plan.md`.

CB16 is one semantic correction only: make `FieldTransportAtlas` consume a valid algebraic cycle row as one or more canonically ordered closed successor components and update the independent atlas validator/direct tests for that same contract. It may not change `dual_cycles`, the sparse row coefficients, exact lift derivation, raw field, retained fixtures, S5 focus assertions/preconditions, CMake/benchmark semantics, selector426 or publish selector427. It must compile/package all eight standard targets through the GMP/GMPXX reusable workflow with `runtimeExecution=false` and execute no generated Directional runtime.

Primary falsifiers are: any already-valid single-component row changes its ordered step sequence; any sparse support edge is dropped/duplicated; a component can terminate open; a directed adjacency mismatch becomes accepted; row14 support/lift is modified instead of represented; the S5 fixture/focus or selector426 changes; or generated runtime executes. Any such observation stops CB16 rather than broadening it.

## 7. Consolidation

This Review folds the superseded TB12-R1 semantic-RED report/Review and indexes the CB15 plan/report plus TB12-R2 plan already retired by intervening CB/TB cleanup. Their durable facts are preserved in `M4_Consolidated_Record.md` §2.62, this Review, the current TB12-R2 report, frozen definitions, tracker/changelog and git history. Current retained CP-SCALE roles are: normative frozen definitions; accepted TB11 runtime authority evidence; current TB12-R2 semantic-RED report; this Review; exactly one next plan (CB16); selector426 and historical selectors; consolidated record and durable trackers.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector426 = `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; exact first425 = `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` |
| Decisive claims independently re-derived | candidate ZIP/28-entry manifest/source/GMP/modes; selector426/prefix/owners; fixture hashes; row14 class; exact `order_cycle_steps` reuse semantics; `dual_cycles` boundary-row construction; independent validator's one-loop premise |
| Non-vacuity checked | diagnostic distinguishes duplicate-origin from premature orbit closure: 34 support edges and 34 unique origins exclude duplicate outgoing source faces, while reuse at canonical start face 0 proves the first orbit closes before all support is consumed |
| Prior obligations discharged/carried | `DEFN-OBS-04` carried to CB16; S1 calibration, zero-transport helper audit, S2-arrival fallback and inherited produced-witness debts retain owners; no obligation silently discharged |
| Stable accounting | **49 events / 14 categories / 35 recurrences**, debt **5**; accepted package `10473134357` / selector426 **426/426** unchanged |
| New candidates/obligations recorded | no new candidate; existing TB12-R1 candidate narrowed to multi-component algebraic-support/single-loop-representation defect; CB16 corrective owner/falsifiers recorded |
| ORIENTATION currency line | `M4-CP-SCALE-TB12-R2-REV`, 2026-09-17 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | S5 state, genus-two witness, top-priority owner and existing RP-07 instance rewritten to the reviewed multi-component mechanism; superseded CB15 wording removed |
| CHANGELOG | TB12-R2 Review adjudication and bounded CB16 successor recorded |
| ROADMAP | M4 CP-SCALE state advanced through TB12-R2 Review; CB16 is next |
| Selector manifest | n/a — no selector appended or promoted; selector426 remains byte-identical accepted authority |
| LESSONS | existing `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION` applies; no new recurring category added |
| Consolidation under CLEAN_UP_POLICY | CB15 plan/report and TB12-R2 consumed plan indexed; superseded TB12-R1 report/Review folded; durable facts retained in §2.62/current records |
| Successor frozen | exactly `M4-CP-SCALE-CB16`; allowed surface, semantic contract, stop rules and falsifiers are in the CB16 plan |
| Turn boundary held | yes — runtime-free Review; no generated Directional runtime/build/benchmark/product/test/fixture/selector mutation |
| review_check.py boundary | `PASS` on the final local Review diff; product/test/fixture/build/selector bytes unchanged |
| `STATUS` lifecycle maintained | Review entry/resume beacon maintained; final COMPLETE beacon reserved as the last repository mutation after durable patch transport and cleanup |
| Pushed to origin, branch in sync | durable Review patch is transported by the standard Drive workflow; final branch fetch/compare is required after cleanup before the COMPLETE beacon |

---

## 8. Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** Accounting holds at **49 / 14 / 35**, debt **5**; accepted package `10473134357` /
selector426 **426/426** unchanged. One requirement added to CB16.

### V1 — the mechanism is confirmed by an independent derivation

§2's two observations settle the diagnosis more tightly than they state. `supportEdges=34` with
`uniqueFromFaces=34` means every support edge has a distinct outgoing origin, so the directed successor relation
on that row's support is a **permutation** of 34 directed edges. A permutation decomposes uniquely into disjoint
cycles, and a single-loop walker started anywhere traverses exactly one of them. Premature return to the start
with support edges left unconsumed is therefore the precise signature of a permutation with more than one cycle —
which is what was observed.

That also identifies §4's "all closed components" as exactly the cycle decomposition of that permutation, not a
new construct. §3's ownership split follows: `dual_cycles` produced a valid algebraic row, and the defect is the
atlas assuming that row's support forms one simple loop.

§4's soundness argument holds as stated: `QuarterTurn` composition is integer addition modulo four, which is
commutative and associative, so composing the same multiset of steps in any component order yields the same
total. Canonical ordering therefore buys determinism and reproducibility, not correctness of the algebraic
result — which is precisely why requirement 5, preserving the exact sequence for already-valid single-component
rows, is what protects the accepted atlas identities in selector426 rather than the ordering rule itself.

### V2 — REQUIRED: the validator must be generalized independently, not relaxed into agreement

§4's closing paragraph notes that the independent validator repeats the same one-contiguous-loop premise. That is
the most consequential line in the record and deserves to be a requirement rather than an observation, because the
obvious repair is the wrong one.

Confirmed in source: `tests/FieldTransportAtlasTests.cpp:1526-1529` seeds `start`/`current` from the first emitted
`step.fromFace` and then rejects any step whose `fromFace` differs from the running `current` — it validates the
**producer's emitted ordering** for contiguity. The cheap generalization is to relax that check so a discontinuity
is tolerated whenever the current component closes. **That would make the oracle self-authorizing**: it would
accept whatever decomposition the producer emitted, by construction, and could no longer detect a dropped,
duplicated or mis-ordered component.

The validator already reads `bundle.cycles` and its coefficients, so it has what it needs to avoid that. CB16 must
have it **derive the expected component decomposition independently from the sparse row's support and adjacency**,
then compare the producer's flattened sequence against that derivation — the same producer-independence rule
applied to the CP-COND negative-index oracle, where deriving the expectation from the producer's output was
explicitly forbidden.

A concrete falsifier to add alongside the three in §6: perturbing the producer's component **order** while leaving
the step multiset unchanged must be detected by the validator. If it is not, the canonical-ordering requirement is
unenforced and only the algebraic total is being checked — which §4 item 4 already shows is order-invariant, and
therefore proves nothing about ordering.

### V3 — classification, and what S5 has already bought

The accounting is correct under the durable criterion: the S5 focus has never entered an accepted selector, no
accepted ordinal transitioned PASS → RED, and selector426 is preserved, so this is a candidate-side production
defect rather than a stable event. Carrying it under existing `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION` rather than
opening a new category is right — the pattern is the same linearization assumption, in a new place.

`DEFN-OBS-04`'s partial statement is precise and worth keeping in that form: **genus-two topology is proved**,
while admissible atlas authority and A3 reachability remain unproved. Partial credit recorded exactly, with
neither half borrowed from the other.

Worth recording plainly, since S5 remains unaccepted and the sequence could otherwise read as pure cost: the
genus-two witness has already earned its construction. It surfaced a real production defect in
`FieldTransportAtlas` that no genus-1 fixture could expose, because a single-simple-loop assumption is only
falsified by a cycle row whose support decomposes into several components. That is exactly what a coverage witness
is for, and it did it before being gated.
