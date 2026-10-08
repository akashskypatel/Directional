# M6-CP3-TB1-ENTRY-R2-REV — Independent Review

**REJECT R2 (444/497, 53 RED).** The full independent Review report is preserved in personal Library `/Directional/Evidence/M6-CP3-TB1-ENTRY-R2-Independent-Review.md`. The 53-identity classification is committed as `Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv`; immutable test artifact `11545716507` (run `37767144537`), outer SHA256 `d6469bea1b4ef6fb3b142d05a97d01dbab98331cfc91d930c7bc30da555ec0ca`.

Independent CP2 / R1 / R2 comparison: accepted CP2 491/491, rejected R1 482/497 and rejected R2 444/497; 47 accepted CP2 identities are RED in R2; 38 R1 PASS→R2 RED, zero recoveries. Seven evidence groups: typed A4 InvalidHardRailRouteCertificate 25, Phase10 downstream 12, periodic odd real-producer witness absent 5, torus A5/A6 downstream 6, D3/D7 seam-aligned tracer positive absent 2, D5 ordinary route baseline absent 1, RE-package terminal mismatch 2.

**New stable event:** A4 HardRail certificate false-rejection of prior accepted-green source fixture: +1 event in existing `RP-01/AUTHORITY_DOMAIN_CONFLATION`, +1 recurrence; total **64/17/47**, debt 1. RA-36.1's consecutive-edge common-face premise is unsound on the supported 3×3 two-HardRail-edge fixture: edge (1,4) faces {0,3}, edge (4,7) faces {4,7}; no common incident face. A4 implementation `src/geometry/SurfaceCellTracing.cpp:18260–18372` uses direct face equality without side-fan transport. This is a static supported-input counterexample, **not** proof of a produced two-edge route; first rejecting predicate remains unlocalized. Preserve RA-36 until revised Definition independently reviewed; do not silently relax it.

**Disposition:** Product R2 candidate UNPROMOTED; CP2 remains accepted. Organic D1/D2/D3/D5 positives unproved; older A6 RP-01 event still open; no RB/CB2/CP3 exit work authorized. **Exact successor:** `M6-DEFN-R5-R3` runtime-free Definition to propose RA-37 with typed vertex-fan-side A3 transports and preserve all false-rejection, witness and 497-process regression gates; mandatory `M6-DEFN-R5-R3-REV` before a new Code+Build turn. Prescriptive full plan `/Directional/Evidence/M6-DEFN-R5-R3-CP3-Entry-Recovery-Plan.md`. No product, test, fixture, selector or workflow change or execution in this Review.

## Exact mechanical reconstruction and accepted-green comparison

Independent artifact fetches verified three immutable results: accepted CP2 `37419256039 / 11393198123` SHA-256 `0e4e550a09e4fb38b58bfcef2e57db6dcea865a1c46b384b5a288d5c491606bb` with 1005/1005 manifest; rejected R1 `37645974118 / 11495166428` SHA-256 `5ee8380ee7bb557a58274ef0b7cefa47e1abf1ef549650afcb7fff1330f161a6` with 1019/1019; rejected R2 `37767144537 / 11545716507` SHA-256 `d6469bea1b4ef6fb3b142d05a97d01dbab98331cfc91d930c7bc30da555ec0ca` with 1019/1019. All 491 CP2 case names and phase+ordinal positions **exactly match** the corresponding R2 cases. R2: focused30 15/30, focused12 10/12, selector449 419/449, CP3entry 0/6. Exact-one 497/497, no skips/benchmarks, unchanged package/source/execution-view before/after and no configure/build/retry. **47/491** previously accepted GREEN cases now RED; relative to R1 **38 newly RED, 0 recovered**, all 15 R1 RED remain.

### Exhaustive 53-row classification (independent Review, not mere log keyword totals)

- **CAND-01: 25 direct A4 HardRail typed rejects**. `InvalidHardRailRouteCertificate` on the originally accepted two-edge 3x3 hard-feature fixture, Phase10 and source typed route examples, plus new identity6 and already-R1-red identity2. The root family is a distinct new product false rejection introduced in A4 by R2. There are 23 previously green CP2 cases within this group (22 newly failing vs R1 plus previously red focused30 ordinal24). This is one stable event, not 25. Failure-site predicate within `invalid_route()` is not exposed by the log; below is a static topology falsifier, **not** identification of the runtime step that failed.
- **CAND-02: 12 dependent Phase10 production failures.** Selection/test first needs `SurfacePhaseFrontProduct::Produced` but receives `Rejected` or cannot reach the expected feature authority or final oracle. Selector ordinals 116,122,130,132,134,137,139,140,142,143,406,407. Likely A4-origin cascades, independently unlocalized. Keep diagnostics and do not assign a second stable event.
- **CAND-03: 5 periodic odd witness absences.** Focused30 ordinals 6/20, selector 446/447, CP3entry 1. R2 `make_nonzero_z4_torus_witness_fixture()` enumerates source/A3 candidates, filters by selected-face delta 1 or 3 and then requires a real reciprocal tracer-produced PeriodicCut pair/cut route. R1's helper called weaker `select_torus_source_witness()`, with no same bounded odd-producer test. Selector447's newly failed status is **test-authority tightening**, not by itself a production feature regression.
- **CAND-04: 6 existing torus A5/A6/arrangement RED**. Focused30 25–28, selector444/448 all already R1 RED; inherited failed recovery of separately counted old A6 RP-01. No claim R2 A6 repaired these. No new count.
- **CAND-05: 2 D3/D7 organic seam-collinear fixture gaps.** CP3 identities 3 and 5 produce no fully certified reciprocal cross-sheet OrdinaryFront on the bounded axis-aligned fixture. Their intended A6/A7 certified-seam positive/tamper checks are never reached; non-stable fixture/witness gap.
- **CAND-06: 1 D5 ordinary source-route oracle gap.** CP3 identity4 fails at `baseline != nullptr`; typed barrier mutation is not reached. Non-stable test-oracle/producer-reachability gap.
- **CAND-07: 2 RE-package terminal mismatches.** Selector176/201 observe `NotProductionReady` instead of expected `InjectedStageFailure`. Review cannot assign them independently of A4/A5 first failure from the existing logs; keep provisional dependent status and do not count twice.

The authoritative *one row per failing identity* receipt includes CP2 and R1 prior state, extracted R2 first diagnostic and immutable raw log path: `Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv`. All seven buckets sum 25+12+5+6+2+1+2=53 without overlap. The preserved full raw result is in personal Library `/Directional/Evidence/M6-CP3-TB1-ENTRY-R2-EXEC-result-37767144537.zip` as well as GitHub artifact `11545716507` (expires 2026-10-22).

## Static architectural counterexample and limits

Frozen RA-36.1 states **consecutive feature carriers share exactly one typed incident source face**. In supported 3×3 rectangle fixture, source edges (1,4) and (4,7) are consecutive and share vertex4, but their source face pairs are respectively `{0: (0,1,4), 3: (1,5,4)}` and `{4: (3,4,7), 7: (4,8,7)}`. Their intersection is empty. This disproves the **universal face-sharing premise for supported input polylines**, not the existence of a produced two-edge paired route. The implementation `SurfaceCellTracing.cpp:18300–18321` requires each successive rail carrier's two incident faces to contain its `current` face, even though its vertex-star `railFanPotentials` graph can contain non-rail A3 transitions connecting two otherwise distinct side faces. A valid typed vertex-fan transfer may exist without direct carrier-pair face equality. Frozen RA-36.3 already calls for independently derived `φ_a`, `φ_b` side transports and commuting `χ_(i+1) ∘ φ_a = φ_b ∘ χ_i`; present code cannot reach that check if it rejects the missing face identity first. A naked fold of cross-rail `χ_i` also requires domain/target proof; the two crossing maps need not compose as if they were a path along one side.

**Important evidentiary distinction:** existing runtime logs do **not** reveal which specific check inside `invalid_route()` failed for each typed source. A later approved Code+Build must add diagnostic-first-locus information without changing production semantics and then prove any corrected path with *real-produced* positive and negative artifacts. The independent R3 Definition must reconcile RA-36 itself; this Review flags the frozen premise but does not silently amend it. Singular/disconnected fan, nonreciprocal atlas, foreign rail owner, route ambiguity and mixed orientation must continue typed fail-closed. Singleton case (one edge, exact incident faces and `firstToSecond`) must remain accepted.

## Accounting and exact next gate

**New stable event +1 in existing `RP-01/AUTHORITY_DOMAIN_CONFLATION`** for A4 rejecting accepted-green HardRail features using an inapplicable face-adjacency surrogate. Its pattern/category recurs: `63 events / 17 categories / 46 recurrences → 64 / 17 / 47`, debt 1. This newly counted source-transport event is **distinct** from old open A6 seam-domain RP-01 (CAND-04); dependent CAND-02/CAND-07 and non-stable organic gaps do not spawn extra event IDs. R2 is REJECTED and UNPROMOTED. Only authorized successor **`M6-DEFN-R5-R3`** (runtime-free Definition, candidate RA-37 with typed source-face-star side transport, full odd/wedge/seam/ordinary organic requirements) may proceed after formal STATUS completion; mandatory independent **`M6-DEFN-R5-R3-REV`** before Code+Build. No test execution or source mutation occurred in this Review. Full prescriptive plan: `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Plan.md` and its expanded durable Library version.

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld in full. The RA-36.1 falsifier is correct, and the unsound clause is mine.** Accounting
**64 / 17 / 47**, debt **1**, is right. I decline to amend RA-36 here; reasoning in V5.

### V1 — the counterexample is exact, and it generalizes beyond the fixture

Verified independently from `tests/SurfaceCellTransitionQuotientTests.cpp:694-740`. The 3×3 grid triangulates
per quad as `(lowerLeft, lowerRight, upperRight)` then `(lowerLeft, upperRight, upperLeft)`, giving
`0=(0,1,4), 1=(0,4,3), 2=(1,2,5), 3=(1,5,4), 4=(3,4,7), 5=(3,7,6), 6=(4,5,8), 7=(4,8,7)`. Hence:

- edge `(1,4)` → faces **{0, 3}**
- edge `(4,7)` → faces **{4, 7}**
- intersection **∅** — exactly as reported.

This is not a fixture accident. Two **collinear** edges meeting at a vertex can never share a face, because a
triangle containing `1, 4, 7` would be degenerate. So RA-36.1's clause *"consecutive steps share exactly one
typed source face"* is false for **every** polyline carrier pair in a proper triangle mesh, not merely this one.

### V2 — the clause was self-defeating

RA-36 rejected the singleton-only contract **on the grounds that polyline hard features are legitimate** — citing
these very edges `(1,4)`/`(4,7)` as a real producer input — and then froze a connectivity clause that polylines
structurally cannot satisfy. The falsifier therefore *strengthens* the singleton-only rejection (polylines are
real and must work) while destroying the premise I attached to it. That is my error, not the producer's, and the
25 `InvalidHardRailRouteCertificate` rejects on previously accepted-green evidence are its direct consequence.
Recording it as **+1 event / +1 recurrence in existing `RP-01/AUTHORITY_DOMAIN_CONFLATION`** is the correct
classification: a rule asserted authority over a domain it had not established.

### V3 — the error is a primal/dual category mistake, and the fold is wrong in kind

Connectivity "share exactly one face" is the **dual** notion: a face-to-face transition path, where consecutive
steps cross different edges *of the same triangle* and so do share a face. But a HardRail route's steps are
**primal** rail carriers — collinear feature edges — which meet at a **vertex**. The connecting structure is
therefore the **vertex fan**, never a shared face.

The Review is also right that the composition is wrong in kind, not just the connectivity: *"the two crossing
maps need not compose as if they were a path along one side."* My "typed fold" wording implied walking one side
and accumulating χ. The correct form alternates cross-rail and along-side transport,

```text
τ_ab = χ_n ∘ φ_{n-1} ∘ … ∘ φ_1 ∘ χ_1
```

with RA-36.3's square `χ_(i+1) ∘ φ_a = φ_b ∘ χ_i` as the consistency condition and path-independence required
across admissible fan paths. RA-36.3 half-anticipated this; RA-36.1/.2 contradicted it.

### V4 — the authority already exists in A4, and my clause made already-written code unreachable

This is the part worth adding to the Review's evidence. A4 **already computes** per-vertex fan potentials:
`railFanPotentials` is declared at `src/geometry/SurfaceCellTracing.cpp:18120`, populated at `:18206`, and
**already consumed by junction logic** at `:18337-18342`, which resolves `a0, a1, b0, b1` potentials at a
`junction` vertex. So the φ authority and the junction handling both exist.

Two defects follow, neither of which needs new invention:

1. `railFanPotentials` has **zero header references** — it is a local, unpublished value, so A5 cannot consume it
   even though RA-36.2 requires A5 to validate published evidence only.
2. My face-identity gate at `:18312-18321` threads a single `current` face and rejects when a carrier's incident
   pair contains neither — which, per V1, is the generic polyline case. It therefore rejects **before** the
   junction logic at `:18337` can run.

So the clause did not merely over-constrain: it rendered correct, already-written fan handling **unreachable** —
the same pattern diagnosed at `M5-CP3-TB1-R3-REV`, where CB4's valid seam re-validation never executed because
its guard was deterministically false. And the cure is the one RA-34.3 and RA-35 already established twice in
this milestone: **publish the authority the producer already holds**, rather than add new computation or let a
consumer infer it.

### V5 — I decline to amend RA-36 myself, and the Review was right to flag rather than relax

Precedent exists for a Review withdrawing a false frozen clause — RA-31a withdrew `C = F⁻¹∘B` on exactly this
basis. I am not taking it here, for two reasons. The only authorized successor is a **runtime-free Definition
turn** (`M6-DEFN-R5-R3`) chartered to reconcile RA-36 into RA-37, so there is no window in which a Code + Build
turn implements against the unsound clause. And amending my own frozen rule outside the turn chartered to
reconcile it would fragment authority in precisely the way this project has repeatedly been bitten by.

What must not happen is a reader treating RA-36.1 as sound in the interim, so I annotate its **status** —
unsound, counterexample recorded, owner R3 — without relaxing its content. That matches the Review's
instruction to *"preserve RA-36 until revised Definition independently reviewed; do not silently relax it."*

### V6 — what this Review got right, and it is not small

It recorded a **new stable event against a reviewer's own frozen premise** rather than softening the number to
protect it — 64 / 17 / 47 with the false-rejection attributed to RA-36.1 by name. It kept the singleton case
accepted, preserved every RA-34.3 stop gate, left the R2 candidate unpromoted with CP2 still accepted, and
declined to infer the replacement contract from a static counterexample. It also noted that the runtime logs do
**not** reveal which predicate inside `invalid_route()` fired first, and required diagnostic-first-locus before
any corrective change — the instrumentation-before-guessing discipline that ended fifteen turns of static
guessing in M5-CP3. Routing to R3 for RA-37 with typed vertex-fan-side transports is the right successor.

### V7 — verification limits

Re-derived from repository bytes: the fixture triangulation and both edges' incident face sets; the degeneracy
argument for collinear carriers; the single-`current`-face threading at `:18300-18321`; `railFanPotentials`'
declaration, population, junction consumption and absence from any header. Accepted as reported: the 444/497
tally, the seven evidence groups, the 38 R1→R2 transitions and the per-group RED classification, which are
runtime facts of the reviewed artifact.
