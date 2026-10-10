# M6-DEFN-R5-R4-REV — independent definition review (runtime-free)

## R5/R4 re-review after RA-42 Design Review — authoritative correction (2026-10-10T11:07Z)

**Disposition remains REVIEW_BLOCKER: RA-42 is acceptable as a prospective *design obligation*, but the assertion that the source-attached producer already supplies independently authenticated terminal incidence is not supported.** This re-review inspects the exact GitHub source snapshot `0bc8080366757a2285a8265599255475ef8525b2` (workflow `38046815459`, source artifact `11666644778`, outer SHA-256 `c2b548b123ee38e0daef5d1299693d9d7b586caf7639bd1347e690abf479c237`, **5851/5851** internal checksums). All snapshot jobs passed. No Directional binaries, compiles, tests, or benchmarks executed. This latest section supersedes older descriptions of which architecture decisions remain undecided, but preserves the historical independent analysis below.

**R4-REV-01A — rail samples are not typed topology credentials.** `include/directional/geometry/SurfaceCellTracing.h:90-116` declares `SurfaceCellRail::sourceVertices` and `SurfaceCellRail::sourceEdges` as `std::vector<int>` and `SurfaceCellRailSample::sourceFace`/`sourceEdge` as raw `int`, with `sourceEdge` a local face-edge index. These can be useful inputs to a checked mapping; they are not `SourceFaceTopologyKey`, `SourceEdgeTopologyKey`, or a typed *front endpoint-to-rail contact*. No contract proves that a particular `SurfaceFrontEdge::from/to` belongs to a particular rail sample, a unique local source-vertex occurrence, or a specific side germ. `src/geometry/SurfaceCellTracing.cpp:18384-18515` still constructs the endpoint certificate from the raw trace-point face rows. A downstream conversion to typed IDs without producer-owned contact and uniqueness proof would only repackage that gap. **Required:** name the exact producer symbol and source-line path, publish a source-authenticated vertex/edge/face occurrence plus rail sample/interval and filled-side mapping, certify both endpoint germs and uniquely ordered nonrail A2b/A3 continuation, reject missing/ambiguous assignments. A route discovered by geometry/barycentric proximity is not authority.

**R4-REV-01B — false reuse-location claim.** Frozen RA-42.4 and the cited Design Review identify `SurfaceCellTracing.cpp:18120-18206` as an already-existing source-vertex-star traversal. That range actually handles an isolation seam certificate call and diagnostic formatting, **not** the purported vertex-star-cut contact producer. Existing other star-related helpers cannot be presumed to implement this mapping. Corrected the normative reference; a real symbol and line-level dataflow proof remain mandatory. The helper `rail_sample_source_vertex` (`SurfaceCellTracing.cpp:5810-5852`) infers vertex membership from barycentric epsilon checks and therefore cannot establish typed incidence under RA-42.2.

**R4-REV-02A — unconditional A3 decision retained; held plan contradicts it.** RA-42.5 explicitly preserves RA-40.1's unconditional `FieldTransportAtlas::matches_source_faces` boundary. `SurfacePhaseFrontProduct::make` (`SurfaceCellTracing.cpp:7989-8020`) enforces the matched atlas but only range-checks `sourceFaceBranchRotations`; there is no independent source-bound equality check for that caller-supplied gauge. This remains work for Code + Build *after* the review gate. Worse, the HELD R4 plan's implementation items 2 and 5 explicitly still allow a null atlas and an “empty-A3 conditional positive”, contradicting the frozen RA-42.5 decision. Corrected those instructions without running or authorizing implementation. Never use a caller's own gauge as an independent gauge oracle.

**Not discharged / review STOP.** RA-42.7's separation of singleton terminal contact from multi-carrier through-junction is logically consistent with the observed 3×3 source star and retained. However, 38 printed rows remain one physical singleton carrier and the 39th has no carrier: **zero genuine produced multi-carrier A3 witnesses**. No RA-41 freeze, R4 Code + Build release, runtime promotion, or new successor is authorized. A further independently reviewed, source-exact producer proof is required *within this same canonical Review turn* before it may close. Prior R3 runtime remains 403/497 with 94 RED; accepted CP2 491/491, 88 accepted-green losses; stable ledger **66/17/49**, debt **1**; selector 497 and four supplemental tests untouched.

---


**Disposition: NOT ACCEPTED FOR IMPLEMENTATION / REVIEW_BLOCKER.** RA-41.2's observed source-star *possibility* is independently verified, but the current material does not demonstrate producer-owned terminal-contact authority. RA-41.1's atlas-null exemption conflicts with binding RA-40.1 and lacks independently checkable gauge provenance. Do **not** freeze RA-41, rewrite the frozen RA-38/RA-39/RA-40 contract, release `M6-CP3-CB1-ENTRY-R4`, run binaries, or change tests/producer. This turn remains blocked on explicit source-domain architecture decisions; it does not invent a successor. Review baseline snapshot SHA `91cd585f2cfd5457bb9fddae8357554a32c898ad` (snapshot run `38042697991`, artifact `11665329905`, ZIP SHA-256 `3915c6739ca3b22df14e86c15347e8700a9ed303f11004415aac636244495f02`, embedded tar SHA-256 `492a59c7c211e0375b480fa12eba509c13ba902378e97d4f32545b2e54d6ece1`). All three snapshot jobs passed; no Directional executable, compile, test or benchmark ran in this review.

## Independent topology proof — exactly one observed carrier

Reconstructed `tests/SurfaceCellTransitionQuotientTests.cpp:575–602` from the nine grid vertices and eight oriented face rows:

```
face 0=(0,1,4), 1=(0,4,3), 2=(1,2,5), 3=(1,5,4)
face 4=(3,4,7), 5=(3,7,6), 6=(4,5,8), 7=(4,8,7)
rail carriers: (1,4)->{0,3}; (4,7)->{4,7}
nonrail spoke (1,5)->{2,3}
star(1): {0,2,3}, remove rail (1,4) => {0} | {2,3}
star(4): {0,1,3,4,6,7}, remove rails (1,4),(4,7) => {0,1,4} | {3,6,7}
```

For the 38 carrier-bearing first failures in `Architecture_M6_DEFN_R5_R4_DIAG_Failure_Carrier_Inventory.tsv`, the reported endpoint faces `0,2|0,3` **can** represent opposite rail-side germs at both endpoints of original carrier `(1,4)`. At boundary vertex 1, the face-2 trace sample is on `{2,3}` and has a one-step A2b nonrail candidate `2 -> 3` via `(1,5)`; its partner face 0 is already in `{0}`. At interior vertex 4, face 0 and face 3 are directly on opposite sides. The proposed contact pair is therefore `{3,0}` at vertex 1 and `{0,3}` at vertex 4. This disproves the universality of RA-39.1's **trace-sample row equality** but does not prove a producer-owned contact route or a valid A3 φ value. The 39th selector-150 failure has **no printed carrier** and must remain without contact-credit. `MeshComponents.cpp:72–116` maps original (1,4) to component-local (1,2), so the five compacted entries are not false carrier diagnostics. All 38 diagnosed entries are manifestations of one physical carrier configuration, **zero multi-carrier producer witnesses**.

**Boundary-scope ruling.** Frozen RA-38.3's boundary-vertex and singleton STOP is correct for *multi-carrier through-junction sector transport*, the subject of RA-38. It must not be applied indiscriminately to a **terminal one-carrier contact**: boundary vertex 1 supplies two oriented side germs. The pending RA-41 amendment must explicitly separate these domains. This does not authorize allowing a boundary vertex at an invalid through-junction or removing any source/nonmanifold/rail barrier check. RA-39.6's singleton junction φ is identity only for the absence of junctions; a trace-sample-to-contact step may have nonzero separately proven A3 φ.

## Blocking finding R4-REV-01 — terminal contact source authority has not been constructed

At `include/directional/geometry/SurfaceCellTracing.h:1500–1545`, the front edge holds `from/to` trace points, filled cell/side, opposite edge and route. It does not publish a contact endpoint source occurrence, admissible source-vertex wedge, ordered nonrail transport path or independently established side germ. `src/geometry/SurfaceCellTracing.cpp:18384–18515` still uses the trace-sample `from.face` / `to.face` as the carrier attachment; `SurfacePhaseFrontProduct::make` then checks exact row equality at `:8090–8118`. The topology proof above shows one possible contact route, not that producer direction, barycentric endpoint support, front-side incidence and competing wedges uniquely select it. A checked factory cannot reconstruct that choice from arbitrary face adjacency or merely trust a supplied contact face.

**Required architectural disposition:** specify and statically prove which existing upstream producer entity binds the trace point to source vertex 1 or 4, selects the oriented filled-side germ, and publishes its ordered A2b **nonrail** route with actual source-edge incidence, source-face topology, A3 forward/reverse `transition_value`, and reciprocal front ownership. Require a uniqueness/ambiguity denial independent of source-row order. Prove on the observed singleton and a true **produced** two-carrier route; treat absent route or zero produced instances as a STOP, not as a passing test. Decide whether the existing product can carry this as an immutable, source-authenticated value or needs an explicit schema amendment. No fabricated `2 -> 3` substitution is authorized by this review.

## Blocking finding R4-REV-02 — conditional null-A3 exception conflicts with frozen trust boundary

RA-40.1, `.agents/Directional/Architecture_M6_Frozen_Definitions.md:1–22`, explicitly requires `FieldTransportAtlas::matches_source_faces` at the checked `SurfacePhaseFrontProduct::make` boundary and states **absent atlas must fail typed, with no unauthenticated accepted mode**. RA-41.1 proposes accepting A3-independent products with a null atlas. That is a normative amendment, not a mere implementation detail; it is currently **not** accepted. `SurfaceCellTracing.cpp:7989–7993` enforces atlas presence unconditionally; `:8015–8020` only checks `sourceFaceBranchRotations` length/range. Independently sourced `faceAxisX/Y` and local branch selection (`:11019–11056`) are upstream producer logic, but the checked factory currently receives no source/cross-field certificate allowing a caller-provided gauge to be re-derived. Further, periodic and isolation relation products may depend indirectly on field gauge/transport even when rail arrays are empty (`:17965–18060` illustrates periodic branch-dependent publication).

**Required architectural disposition:** choose explicitly between (A) preserving RA-40.1 unconditional source-matched independent atlas and migrating the legitimate ordinary/legacy producers and fixtures, or (B) a formally reviewed RA-40.1 amendment with a complete typed A3-dependency census, a separately authenticatable source/cross-field/gauge lineage, nonrail/isolation/periodic dependency classification, fail-closed negative tests, and a proof that data removal cannot bypass authentication. A length/range check, empty rail arrays, default identity atlas, trust-me certificate or user-selected flag is insufficient. Do not derive independent A3/gauge from the A4 values being validated. The 34 Phase10 errors are presently 22 untyped-not-produced plus 12 generic final-state assertions, not 34 demonstrated null-atlas roots; instrument typed first rejection before asserting a full recovery path.

## Other findings, unchanged obligations and disposition

- **D3:** The proposed consistent two-face disk is a valid way to remove the seven synthetic single-triangle `DCEL::check_consistency` setup errors without weakening DCEL. The original six periodic-owner negative oracles and one FlowRep truncation oracle must still be reached and retained. This proposal does not discharge R4-REV-01/02.
- **A3/χ invariants:** The preexisting one-terminal carrier χ, reciprocal inverse, verified nonrail φ, and nonzero multi-carrier A3 commuting square must be preserved; do not treat geometric reachability as transported field equality.
- **Runtime authority:** CP2 accepted 491/491; R3 rejected 403/497, 94 RED (39/34/7/14), 88 accepted CP2 losses, zero claimed restorations. Stable regression ledger remains 66 events /17 categories/49 recurrences and M6 debt 1; no new runtime regression classified. Frozen 497=30+12+449+6 and separate four RA-40(C) diagnostics untouched.
- **Code/build gate:** `M6-CP3-CB1-ENTRY-R4` remains HELD; no compile/test or source edit authorized by this review. When both architecture blockers are independently discharged, a subsequent formal Review decision must freeze the exact RA-41 amendment and its single next-turn authority before any implementation begins.

## Review consolidation audit

Examined active R4 Definition plan, candidate record, DIAG audit/39-row inventory, held CB plan, R3 independent Review and normative definitions. **No R4 per-turn document is eligible for safe folding now**: the diagnostic inventory remains unique immutable source evidence; the candidate and held plan remain load-bearing until the architectural STOP is resolved. Historical project authority and selectors were not folded or deleted. Consolidation obligation cannot justify deleting current evidence; the family consolidated record indexes this review decision. No cleanup is necessary to make this review decision source-authoritative.

## Resume-required exact next actions

1. Obtain a reviewed producer-owned terminal side-germ/contact proof including actual trace-support incidence (R4-REV-01).
2. Choose and freeze the source-matched A3/gauge trust-domain boundary explicitly (R4-REV-02), preserving RA-40 unless a reviewed amendment supersedes it.
3. Only then adjudicate complete RA-41, update the held CB plan, and release the single Code + Build successor in a separate authorized turn. Until then the current `M6-DEFN-R5-R4-REV` is **BLOCKED / REVIEW_BLOCKER**, with no successor authorized.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: frozen 497 selector not changed; no acceptance decision made, historical 491 accepted authority carried |
| Decisive claims independently re-derived | Raw `SurfaceTracePoint`, rail/sample and front types; real source at `18120-18206`; factory atlas/gauge validation; contradictory HELD plan; snapshot 5851/5851 hashes |
| Non-vacuity checked | A carrier sample's raw face/edge does not identify an oriented front contact; one ambiguous or missing incidence must fail, not create a proof; zero produced multi-carrier cases yields zero credit |
| Prior obligations discharged/carried | R4-REV-02 normative *choice* A accepted; R4-REV-01A/01B producer proof and R4-REV-02A gauge authentication open; 39/34/7/14 first-locus, 88 accepted losses, D1/D2/D3/D5/A6/A7, periodic and four supplementals carried |
| Stable accounting | 66 events / 17 categories / 49 recurrences; debt 1; CP2 491/491 accepted; R3 403/497 unpromoted |
| New candidates/obligations recorded | R4-REV-01A, R4-REV-01B, R4-REV-02A added to TODO and regression tracker as review obligations, not new stable runtime regressions |
| ORIENTATION currency line | M6-DEFN-R5-R4-REV 2026-10-10 correction prepended |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 superseded priority annotated; §4 witnesses unchanged because no runtime; §8 adds verified authority conflation recurrence |
| CHANGELOG | Re-review correction prepended without rewriting historical RA-42 decision |
| ROADMAP | n/a: M6 checkpoint state unchanged, R4 remains held |
| Selector manifest | n/a: selector unmodified, 497 gate unchanged |
| LESSONS | Existing durable source-authority vs geometry and evidence non-vacuity lessons applied; no new general class |
| Consolidation under CLEAN_UP_POLICY | n/a: active RA-41/RA-42 Decision, prior Review, DIAG inventory, and HELD plan remain load-bearing; no safe deletion |
| Successor frozen | UNKNOWN: architecture producer proof gate blocks lawful successor; no fabricated successor |
| Turn boundary held | Runtime-free Review; no product, test, fixture, selector, benchmark or build source mutation |
| review_check.py boundary | PASS: no product/test/selector/build changes, all checked selector SHA digests and durable marker counts preserved |
| `STATUS` lifecycle maintained | Entry `M6-DEFN-R5-R4-REV`, 2026-10-10T10:58:35Z; final BLOCKED, successor UNKNOWN, no terminal timestamp |
| Pushed to origin, branch in sync | Exact Drive-apply push evidence to be verified; no local tracking branch (snapshot inspection only) |
