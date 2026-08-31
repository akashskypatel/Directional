## 2026-08-31 — `M3-CP4c-3-TB5`: 365-prefix green; first red moves to zero-candidate vertex 11

TB5 is **COMPLETE / VALID SEMANTIC RED** on immutable package **74** / semantic source
`49536cf7b4b261bd52f36a91c861b6459db356a4`. Authoritative run/job `33448925069 / 99674216849` passed immutable
package/source/GMP/27-fixture/six-`0755`/selector preflight, ran exactly one identity per fresh process, re-proved
**365/365**, then first-red ordinal **366** at `VertexTransitSectorUnresolved`: source vertex 11, face `(8,10,11)`,
branch 1, region 0, `FaceInterior`, zero candidate faces, no barrier absorption/incidence, and no serialized
`vertexTransitState` rows. This differs from TB4's two-candidate vertex-30 locus and requires independent review;
Amendment 17 is not accepted merely because the old locus was not reached. AP6 367–373 ran once report-only with
zero gate credit: **1 PASS / 6 RED**. Sphere 368 now proves `NoCarrierMatch / SourceEdgeUnavailable`; 369 again
reports `saturationUsed=true`; 370 publishes `NonIntegralCycleLift;topologyRegion=0`, classifying its constant-zero-
field torus setup as an invalid diagnostic witness/precondition; 371/372 are upstream-blocked; 373 passes
synthetically only. Result artifact `9779114492` is `a4d9239e…ca55`; postflight PASS and every build/repair/mutation
flag false. Two earlier control attempts produced no semantic evidence: one reusable-permission startup failure and
one pre-runtime selector-358 lineage check corrected from byte-prefix to exact-hash/set-subset continuity. Stable
accounting remains **44 / 14 / 30**, debt **5**, semantic packages **72**. Exact next:
`M3-CP4c-3-TB5-REV` independent REVIEW + PLAN; no unchanged retry or semantic patch before review.

## 2026-08-31 — `M3-CP4c-3-CB6`: one-datum transit authority compiled; package 74 frozen

CB6 is **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE** under
`Architecture_M3_CP4c3_TB4_Independent_Review_Record.md` AS0–AS9. Final semantic/evidence source is
`49536cf7b4b261bd52f36a91c861b6459db356a4`: vertex transit captures one arrival-face direction and transports
that same datum through the reachable fan while signed-lift branch labels remain separate authority. The exact
half-open sector rule, barrier semantics and `FaceInterior` exclusion are unchanged. New state diagnostics retain
the old representative and transported incoming direction side-by-side. AS3 makes ordinal 370's typed atlas error
visible without witness repair; AS5 identified and left untouched the independent singularity-port
per-cell-representative pattern in `FieldTransportAtlas.cpp`; AS6 publishes
`NoCarrierMatch / SourceEdgeUnavailable` on the sphere no-source-edge path while AL4 remains binding.

The first compile-only attempt stopped on one mechanical `DomainResult<SourceVertexId>` access error. The only
correction was `rowVertex.value()`. Authoritative GMP/GMPXX retry `33445894845 / 99664857496` compiled all approved
targets with `runtimeExecution=false`; artifacts `9778128771` (`64ff0422…996c`) and `9778129236`
(`cc9019d9…0490`). Mode-preserving package **74**, run/job `33446658075 / 99667201075`, is artifact `9778267541`
(`bad0ade7…767d`), inner tar `c8d51676…5d8e`, source archive `5afa250d…c931`, 27 fixtures, six executables at
`0755`, selector 373 unchanged. Stable accounting stays **44 / 14 / 30**, produced-witness debt **5**; semantic
packages advance **71 → 72**. Frozen successor is artifact-only `M3-CP4c-3-TB5`; no CB6 runtime occurred.

## 2026-08-31 — `M3-CP4c-3-TB4-REV`: all three enumerated mechanisms falsified; Amendment 17 declared

Independent review, definition and planning under the frozen `Architecture_M3_CP4c3_TB4_Independent_Review_Plan.md`
(**AQ0–AQ8**). Nothing executed, compiled, packaged or benchmarked; no gate selected or run; **no product, test,
fixture, selector or build-logic byte changed**. Measures issued: **AS0–AS9**. Full record:
`Architecture_M3_CP4c3_TB4_Independent_Review_Record.md`. Normative record: `DESIGN.md` §7.2.1 **Amendment 17**.

**Verified independently (AQ0).** Working tree byte-identical to packaged source
`2d22ef293363058cfdca96d01158a93d2c0200f8`; selector **373** and all six predecessor prefixes recomputed from
committed bytes and reproducing exactly; 57-entry manifest, 27 fixtures, six executables at `0755` without repair,
accepted **365 prefix green**, AP6 pass separated with zero gate credit, every mutation/build flag false. **CB5
honoured AP3 exactly**: its only change to `resolve_field_vertex_transit` is two additive lines populating
`topologyRegion` and `vertexArrivalMode` — no behaviour changed, which is what makes TB4's locus comparable to
TB3-R1's.

**AP4 did its job, and it saved a wrong fix.** The previous review named M3 — a P2 consumer mismatch at a
`BarrierAbsorbed` vertex — as the leading suspicion and forbade designing against it. TB4 measured
`barrierAbsorbed=false`, `barrierIncident=false` at source vertex **30**. The leading suspicion was wrong; so were
the other two.

**All three mechanisms are falsified.** M1 (barrier truncation → zero candidates): cardinality is **2**. M3 (P2
consumer mismatch at an absorbed vertex): the vertex is neither absorbed nor barrier-incident. M2 (singular-vertex
holonomy): **vertex 30 is regular** — reproduced from the committed fixture as six incident faces forming one
closed, consistently oriented fan, with Poincaré–Hopf accounting for all eight index-`+1` singularities elsewhere
(`4χ = 8` on this `χ = 2` witness), so no others can exist, and A1 would have rejected the atlas at
`SingularityMismatch` had any interior vertex's turning lift disagreed.

**A proof replaces the enumeration (AQ2).** The election predicate `direction[next] > 0 && direction[prev] >= 0` is
an **exact partition** of the full turn around the vertex: adjacent wedges share exactly one ray, owned by the face
where it is `next`, with no overlap, no gap and no tolerance. The two candidates are **fan-adjacent** — steps 2 and
3 of a six-face fan whose step 0 is the excluded arrival face — sharing ray 30→31, which `(25,30,31)` owns and
`(30,31,119)` excludes. A single direction can therefore elect **at most one** of them. Two were elected.
**Therefore two geometrically distinct vectors were tested**, and the boundary-case explanation is dead. Answering
AQ2's sharpest question: the candidates are **two representations of one semantic continuation**, not two
continuations.

**The surviving mechanism, named and not promoted.** **M4 — election by per-cell representative:** the routine
asks, for every reachable `(face, branch)` state, whether *that face's own* representative of the transported
branch is admissible in *that face's* wedge, and a cross field's per-face representatives are related by transport,
**not equal as vectors**. **M5** is retained: the representative may not be the trace's continuation at all, making
multiplicity generic rather than a boundary effect. **AS1** publishes both direction vectors and falsifies both if
they are equal.

**Causality relative to P2 (AQ3):** the M4 mechanism involves no barrier, no port and no singularity, and
`resolve_field_vertex_transit` is untouched in behaviour by CB3 and CB5 — but `barrierAbsorbed=false` does **not**
prove causal independence, since P2 changed which traces exist and where they start. The correct statement is **a
pre-existing, P2-independent defect reached by a trace set P2 may have changed**; the correction is the same either
way.

**Amendment 17 declared**: an election among candidate cells is decided from a **single datum**, never one
representative per cell — a partition disambiguates one point among cells and cannot disambiguate one point per
cell. Prohibited, each removing the symptom rather than the cause: picking the first candidate or ordering faces;
widening or narrowing the sector convention; any tolerance in a predicate that is exact today; and changing the
`FaceInterior` exclusion to alter cardinality. **Left open pending AS1**, because it is a single-writer question:
*which* single datum — the incoming direction transported into each candidate, the ray's geometric exit from the
star, or a continuation owner published upstream by A1.

**AP6's report-only pass paid for itself immediately (AQ5)**, converting a three-turn blackout into four findings:
**369** gives the first *runtime* confirmation of `saturationUsed=true`, corroborating `R10-CAND-01` and staying
deferred behind the mechanical gate; **370** stops at `ASSERT_TRUE(atlasBuild)` before its own contract and the
cause is unreadable because the assertion **discards the typed error it holds** — the same anti-pattern AP1 just
fixed on the product side, now at the test boundary, so classification is deferred to **AS3** rather than guessed;
**373** passes on a **synthetic** fixture only, so `M3-CP4c3-DEFN-R1-CAND-01` is **partially** discharged and the
mechanical zero-unbound count is still owed (**AS7**); and **367/371/372** are **blocked upstream**, which means
Amendment 15's Euler-cut identity and barrier-exclusion contracts remain **unmeasured, not falsified** — a
distinction this record makes explicitly so a later turn cannot misread it. Ordinal **368** reproduces the sphere's
`TraceEventPositionInvalid` at trace 2 / event 30 for the third time **without ever publishing AL3/AM7's
`NoCarrierMatch` versus `AmbiguousCarrierMatch` discriminator**; **AS6** determines whether the instrumentation is
not reaching the report or was never wired. **AL4 remains binding.**

**Owned: four consecutive turns, four scopes of mine too narrow** — by **symbol** (AM2), by **enum** (AN1), by
**stage** (Amendment 16), and now by **enumeration of mechanisms**. Recorded as `LESSONS.md` **70**: enumerate
mechanisms to design the measurement, never to bound the answer, and state which observation would fall outside
every listed mechanism. `LESSONS.md` **71** records the reusable technical form: a partition test disambiguates one
point among cells, not one point per cell.

Gate **373** stays frozen and unselected. Accounting unchanged: **44 / 14 / 30**, debt **5**, semantic packages
**71**, **+0 events / +0 recurrences**.

Exact next: **`M3-CP4c-3-CB6`** — Code + Build, runtime-free, GMP/GMPXX linked, under AS0–AS9.

## 2026-08-31 — `M3-CP4c-3-TB4`: exact two-candidate transit locus measured; AP6 diagnostics executed

TB4 is **COMPLETE / VALID SEMANTIC RED** on immutable package **73** / semantic source `2d22ef293363058cfdca96d01158a93d2c0200f8`. Authoritative run/job `33436492493 / 99634138202` passes immutable package/source/GMP/27-fixture/six-`0755`/selector preflight, re-proves **365/365**, then first-reds ordinal **366** at `VertexTransitSectorUnresolved`. CB5's typed locus exposes source vertex **30**, face `(24,30,32)`, branch 1, region 0, `FaceInterior`, exactly two candidate faces `(25,30,31)` / `(30,31,119)`, `BarrierAbsorbed=false`, `barrierIncident=false`: M1's zero-candidate prediction and direct M3 are falsified, while M2's singular-holonomy cause remains unproved. AP6 then runs 367–373 once report-only with zero gate credit: **1 PASS / 6 RED**; 368 reproduces sphere `TraceEventPositionInvalid` trace 2/event 30, 369 reports saturation still used, 370 stops at `atlasBuild=false`, 373 passes. Result/log `9774693166` (`056f86df…8a7e`) / `9774693946` (`d2acc620…fcb6`); immutable postflight PASS and all build/repair/mutation flags false. Earlier `33436283363 / 99633462747` is resolved pre-runtime orchestration only: the runner expected `package73.tar.gz.sha256` instead of actual `package73.sha256`; control commit `41a7a8b…dde7b` corrected only that lookup. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **71**. Exact next: independent `M3-CP4c-3-TB4-REV`; no unchanged TB retry or semantic correction before review.

## 2026-08-31 — `M3-CP4c-3-CB5`: typed failure locus compiled; package 73 is runtime-ready

CB5 is **COMPLETE / BUILD + PACKAGE GREEN / DIAGNOSTIC-ONLY / RUNTIME-FREE** on source `2d22ef293363058cfdca96d01158a93d2c0200f8`. AP1 replaces
stage-by-stage locus loss with shared `SurfaceCellFailureLocusDiagnostics`; all four typed stage errors now preserve
their available locus through `fail_surface_cells`. AP2 adds the ordinal-366 discriminator: arrival mode, candidate
cardinality/faces, `BarrierAbsorbed`, barrier incidence/degree and transport-star component count. Runtime did not
execute, so **M1/M2/M3 remain unadjudicated** and AP4 still forbids designing against M3.

AP8 found independent typed-data-loss sites at `surfaceCutGraphBuild.error()` and `globalTopologyBuild.error()`.
AP6 is adopted for the successor: after the ordinary first-red verdict is recorded, frozen ordinals **367–373**
run once as a separate **non-gating diagnostic pass** with zero gate credit. Selector 373 remains `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.

Changed-owner compile `33431349204 / 99617230353` passed. Final full compile `33433309655 / 99623694545` compiled all
eight standard GMP-linked targets; raw result/log artifacts are `9773522237 / 9773523017`. Its first
temporary package step had an orchestration-only fixture-root typo after compile success. Package-only retry
`33433718709 / 99625035344` reused those exact bytes and produced immutable mode-preserving package **73** artifact
`9773591345` (Actions SHA-256 `8f3a8f0d6a3ad0931db89cb3e94c33d1d7e8a0d9e1aba27a6ad2690ec9c402a0`), inner tar `fc939abc4110f4a658d80932b395f59c9fd7cecbbcde7caac0ba7b6a41d1aca1`, source archive `36451a2473a8858225cf9eabb181a58a5397f400f7f0a99995a1b8da37a2cb4f`, with 27
package-relative fixtures and six `0755` test/benchmark executables. No Directional binary ran.

Stable accounting remains **44 / 14 / 30**, debt **5**, +0 stable events/+0 recurrences; semantic M3 package count
advances **70 → 71**. Exact next: **`M3-CP4c-3-TB4` artifact-only** on package 73.

## 2026-08-31 — `M3-CP4c-3-TB3-R1-REV`: A1 is clear; the cause of the A2a red is deliberately not assigned

Independent review and planning under the frozen `Architecture_M3_CP4c3_TB3_R1_Independent_Review_Plan.md`
(**AR0–AR7**). Nothing executed, compiled, packaged or benchmarked; no gate selected or run; **no product, test,
fixture, selector or build-logic byte changed**. Measures issued: **AP0–AP9**. Full record:
`Architecture_M3_CP4c3_TB3_R1_Independent_Review_Record.md`.

**Verified independently rather than accepted (AR0).** The working tree is byte-identical to packaged semantic
source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, and selector **373** plus **all six** predecessor prefixes (355,
357, 361, 365, 367, 370) were recomputed from committed bytes and reproduce exactly. TB3-R1 is admissible semantic
evidence: immutable package 72 consumed directly, 55-entry manifest PASS, 27 package-relative fixtures, six
executables at mode `0755` **without repair**, one identity per fresh process, first-red hard stop, and every
mutation/build flag false.

**Headline: Amendment 16 with policy P2 works, and A1 is now clear end to end.**
`MissingSingularityBranchTransport` is gone. The mechanical witness clears the cut transport domain, the tangent
bundle, the cycle basis, index accounting **and** singularity port attachment, and first-reds for the first time in
**A2a**. **Ordinals 1–365 stayed green** through this second invasive A1 change, as they did through the first.
CB3 chose P2 on measured evidence — 8 prescribed singularities, 4 barrier-incident, all `InteriorArc` with
`d_B(v)=2` and a 2-component star — and that census **statically confirms DEFN-R1's Theorem 2**: the barrier graph
is a four-component forest, `n=16`, `m=12`, `c=4`, `χ(B)=4`, **no cycles**.

**The failing invariant, reconstructed (AR1).** `resolve_field_vertex_transit`
(`SurfaceCellTracing.cpp:557-640`) resolves where a trace continues after arriving at a vertex. It BFS-walks
`(face, branch)` states, expands **only** through `topology.transports()` — the barrier-free set — elects
candidates by an **exact** half-open sector predicate (`direction[next] > 0 && direction[previous] >= 0` over
`FieldExactRational`; **no tolerance**), and requires `candidates.size() == 1`. Cardinality is therefore a
topological fact, not a numerical accident. Zero can arise from a barrier-truncated expansion; **multiplicity is
structurally expected at a *singular* vertex**, because non-trivial holonomy makes one face reachable with
different branches and the dedup on `(face, branch)` keeps them distinct.

**The traversal already complies with Amendment 16 (AR3)** — it cannot cross a barrier, because the transport set
has none. **What it lacks is a response to truncation:** it reports "sector unresolved" rather than "blocked by a
barrier", although the network already models `MandatoryBarrierTermination` as a frozen terminal kind. A missing
case, not a violation — so the fix must not be "make it cross". Both prohibited interpretations are restated and
refused: no branch transport for a barrier edge, and no manufacturing uniqueness by widening the walk.

**Amendment 16's scope widened from "every A1 derivation" to every stage** (`DESIGN.md` §7.2.1). Its reasoning was
never A1-specific and A2a already complies by accident of consuming the atlas's transport set; stating the
obligation prevents a later turn from closing this red by widening a traversal across a barrier.

**Causality NOT established, and deliberately so (AR4).** CB3's entire diff to `SurfaceCellTracing.cpp` is 8
insertions and 1 deletion in two hunks inside `canonical_field_aligned_candidate`; `resolve_field_vertex_transit`
is **untouched**. But P2 changed which traces exist and where they start, so unchanged code reached with a changed
trace set can fail for a genuinely new reason. Three mechanisms are enumerated, **none promoted**, and one
measurement discriminates all three: **M1** barrier truncation with zero candidates; **M2** multiple candidates
from singular-vertex holonomy; **M3** a P2 consumer mismatch — a vertex that is a singularity in A1's facts but has
no port in A2a is invisible to A2a paths keyed on ports, and terminal ownership *is* port-keyed
(`SurfaceCellTracing.cpp:832-839` raises `InvalidNetworkTerminalOwnership` when no port matches). M3 is the leading
suspicion and **AP4 forbids designing against it**. The red is not called a regression merely because it follows
CB3, nor pre-existing merely because the function is untouched.

**The locus was recoverable and was thrown away at a boundary, for the third turn running (AR2).**
`error.publishedFaces` already distinguishes zero from multiple, and `continuation_error` carries `sourceVertex`,
`sourceFace` and `branch`. `RemeshPipeline.cpp:6673-6678` reads only `.code` and lets the object die at the
`return`; `fail_surface_cells` (`:6146-6163`) takes only `(SurfaceCellFailureCode, stage string)` and **has no
locus parameter at all**, so every stage loses everything but its name. TB1, TB2 and TB3-R1 have each answered with
a bespoke per-code channel — one call site had already grown a hand-rolled one by concatenating
`"field-aligned-network/" + code`. **AP1 fixes the funnel instead:** a typed locus payload, all four stage call
sites converted in one change. Opened as `M3-CP4c3-TB3-R1-REV-CAND-01`; recorded as `LESSONS.md` **69**.

**Owned: three consecutive measures of mine were scoped one level too narrowly** — AM2 by **symbol**, AN1 by
**enum**, Amendment 16 by **stage** — each satisfied exactly, each narrower than the reasoning that produced it.
Recorded as `LESSONS.md` **68**: when a witness is advancing stage by stage, scope the measure to the pipeline, and
prefer a predicate a reader can apply to code you have not read over an enumeration of the code you have.

**Resolved and runtime-proved (AR6):** `M3-CP4c3-TB2-ORCH-01` (package-relative fixture authority; the absolute
compile-time source-root fallback is gone), `M3-CP4c3-TB2-REV-CAND-01` (CB3 compared the package 69/70 binary
digests), and `M3-CP4c3-TB3-ORCH-01` (the mode-preserving tar envelope held). **Still unproved:** ordinals 367–373
have been blocked by a first red at 366 in **three consecutive TB runs**, so Amendment 15's three self-checks, the
prescribed sphere, the ordinary proposal and the empty-network rejection have never executed. **AP6** proposes a
frozen **non-gating** diagnostic pass that runs them report-only after the first red — no selector byte and no gate
semantics change — and requires a written rationale if declined.

The successor is **diagnostic-only** by the frozen plan's own rule: with locus and cardinality unknown, no semantic
correction is authorized. Gate **373** stays frozen and unselected. Accounting unchanged: **44 / 14 / 30**, debt
**5**, semantic packages **70**, **+0 events / +0 recurrences**.

Exact next: **`M3-CP4c-3-CB5`** — Code + Build, diagnostic-only, runtime-free, GMP/GMPXX linked, under AP0–AP9.

## 2026-08-31 — `M3-CP4c-3-TB3-R1`: valid semantic first red moves from atlas to vertex transit

TB3-R1 is **COMPLETE / VALID SEMANTIC RED** on immutable package **72**. Run/job `33416686424 / 99568970224` passed package/tar/source/GMP/27-fixture/six-hash/six-`0755`/selector preflight and executed selector 373 from ordinal 1 as one exact identity per fresh process. Ordinals **1–365 passed**; ordinal **366** `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` first-red with `NotProductionReady/field-aligned-network/VertexTransitSectorUnresolved`; 367–373 were not executed. Immutable postflight passed and no benchmark/configure/compile/relink/repair/generated discovery/mutation occurred. Result/log artifacts: `9767376410` (`7f2c9492d2dae96dfcf1732c320e772be05538a3552ce6a673bd83eb9189824e`) / `9767376976` (`492d19f1e08fd339f130a07dfcf891a3b7bbaaf537483fb54af6e9b96095ad72`). The prior `MissingSingularityBranchTransport` stop is cleared; the witness reaches network construction. New non-stable gating candidate `M3-CP4c3-TB3-R1-CAND-01` records the unresolved exact vertex-sector candidate cardinality/locus. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**. Exact next: independent `M3-CP4c-3-TB3-R1-REV`; no unchanged retry or implementation before review.

## 2026-08-31 — `M3-CP4c-3-CB4-PKG`: package 72 restores executable-mode transport authority

CB4-PKG is **COMPLETE / PACKAGE GREEN / RUNTIME-FREE**. Package-only run/job `33411346157 / 99551438549` consumed raw CB3 artifact `9750227619` (`b1cc9a989af2db84ddd2ad83babf9b2221396e45a165aa84927082e610c351c8`) through the Actions artifact API, re-proved all six frozen binaries as byte-identical `0755`, copied exactly 27 fixtures only from embedded source archive `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`, regenerated the 55-entry manifest, and emitted mode-preserving package **72** without configure/compile/relink/runtime/benchmark. Artifact `9765247195` has Actions SHA-256 `41ebe4dec4a3eb5c8194900a3f27a0377c3271212edd10fb952c48f55a6a2e6d`; inner `package72.tar.gz` is `20630897aa432572d0929022abef3861fff80c2b5792c223071990dd2e3c6a73`. Independent post-download clean extraction re-proves source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, GMP authority, 27 fixtures, 55/55 manifest, and six exact hashes/modes. `M3-CP4c3-TB3-ORCH-01` is resolved non-stable; stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**. Exact next: artifact-only `M3-CP4c-3-TB3-R1` on package 72 and unchanged selector 373 from ordinal 1.

## 2026-08-31 — M3-CP4c-3-TB3-REV traces ORCH-01 and freezes package-only correction

- Independent review proved raw CB3 artifact `9750227619` preserves all six exact runtime binaries with mode `0755`; final package 71 has identical binary hashes but `0644`.
- Root cause is the CB3 fixture-packaging `actions/download-artifact@v4` materialization boundary, which normalizes artifact files to `0644` before final re-upload. No product semantic defect was observed.
- Decision: **approved with amendments**. Exact next is runtime-free `M3-CP4c-3-CB4-PKG`, starting from raw compile authority and emitting a mode-preserving `package72.tar.gz`; no replacement compile or TB-side permission repair.
- Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**.

## 2026-08-31 — `M3-CP4c-3-TB3`: blocked pre-runtime by package-71 executable modes

TB3 is **COMPLETE / BLOCKED — PRE-RUNTIME / NO SEMANTIC VERDICT**. Run/job `33399144281 / 99510922630` verified exact immutable package **71** (`9750235004`, `bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`), its complete internal manifest, semantic source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, source archive `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`, and packaged fixtures, then stopped before ordinal 1 because all six packaged test/benchmark executables extracted as mode `0644`. Artifact-only policy prohibits `chmod`, repacking, repair, mutation, or replacement compilation. Result/log artifacts: `9760518962` (`ec5bc5cccb99e38e4ce77533478c5864e756735b3511575d843bbafb328f4677`) / `9760519355` (`b803c9f81df4a5acbea642860d88f8c61f3df8f13d2204cf836344f6efb1016d`). Selector execution **0/373**; no runtime, benchmark, configure, compile, relink, generated discovery, repair, or mutation occurred. New `M3-CP4c3-TB3-ORCH-01` is **ACTIVE / BUILD-PACKAGING CONTRACT DEFECT / NON-STABLE**; exact mode-loss stage is deferred to independent review. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**. Exact next: independent `M3-CP4c-3-TB3-REV` — no repackage/rebuild/mode repair/TB retry before review.

# Changelog

## 2026-08-31 — `M3-CP4c-3-CB3`: Amendment 16/P2 build green; package 71 portable

CB3 is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`. Static AN1 measurement found four barrier-incident mechanical singularities, all degree-2 interior-arc facts with two transport-star components, selecting Amendment 16 **P2 (`BarrierAbsorbed`, no ports)**; no illegal hard-feature transport and no sphere-specific fix were introduced. Atlas/pipeline diagnostics now publish complete failure loci and barrier-singularity census/classification. AN2 independently proves package 69/70 binaries byte-identical. AN3 removes compile-time absolute fixture-root authority and package 71 carries 27 fixtures at `test-data/benchmarks/fixtures`. Run `33370966957` compiled all eight required targets with GMP/GMPXX and no runtime. Immutable package **71** is artifact `9750235004` (`bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`), source archive `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`; fixture contract and binary-byte invariance pass. Selector 373 remains frozen/unexecuted. Stable accounting stays **44 / 14 / 30**, debt **5**, semantic packages **70**. Exact next: artifact-only `M3-CP4c-3-TB3`.

## 2026-08-31 — `M3-CP4c-3-TB2-REV`: Amendment 15 confirmed at runtime; Amendment 16 declared

Independent review, definition and planning in one turn under the standing cadence, with the user's authorization
to combine a DEFN where one is needed. Nothing executed, compiled, packaged or benchmarked; no gate selected or
run; **no product, test, fixture, selector or build-logic byte changed**. Measures issued: **AN0–AN9**. Full
record: `Architecture_M3_CP4c3_TB2_Independent_Review_Record.md`. Normative record: `DESIGN.md` §7.2.1
**Amendment 16**.

**Verified independently rather than accepted.** The working tree is byte-identical to packaged semantic source
`005512f20ed56edc793f4d6505f3d2b4c2999c71`, so every source claim describes the binary that ran. Selector **373**
was recomputed from committed bytes — 373 lines, 373 unique identities,
`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834` — and **all six** predecessor prefixes (355,
357, 361, 365, 367, 370) reproduce exactly from `head -n` of that file, so `first_red_ordinal` stays comparable
across the whole CP4c arc. AM8's append is exactly as specified at ordinals 366–373.

**The headline result: Amendment 15 works.** The mechanical witness **advanced past `IncompleteCycleBasis`** —
TB1's stop is gone. The cut transport domain is constructed, the tangent bundle initializes, the cycle basis is
built and validated, index accounting completes, and execution reaches a later stage of the same producer. And
**ordinals 1–365 are green**, so a deeply invasive change to A1's local mesh construction regressed nothing in the
accepted gate. CB2 also implemented the endpoint rule *better than the amendment specified it*: rather than
applying the formula `copies(v) = d_B(v)`, `make_local_region_mesh` (`:1030-1104`) implements the **definition** —
it flood-fills the star's face-adjacency graph with barrier edges removed and creates one local copy per component
— so tips, branch vertices and boundary vertices all fall out with no special case and a formula error is
impossible.

**New first red at ordinal 366: `MissingSingularityBranchTransport`, the same disagreement one consumer later.**
`build_singularity_attachments` (`:597-618`) walks the ordered one-ring fan of a singular vertex and demands a
branch transport on **every** radial edge; `ordered_incident_fan` (`:351-402`) builds that fan from the **global**
`sourceMesh.F` and **requires it to close**; and `branchTransports` (`:304-342`, built at `:1827` from
`adjacencies`) **excludes every barrier by construction**. A singular vertex incident to a hard feature therefore
fails by construction. Established by the same elimination as TB1: the failing radial edge is not `SourceBoundary`
(the domain is closed, `globalEF = localEF = 1,158`, `boundaryLoops = 0`) and not `NonTraversable` (one region over
all 300 faces), so it is `HardFeature`.

**It is pre-existing and merely unmasked — decisively, not by argument.** Call order is `build_branch_transports`
`:1827` → cycle-basis loop `:1865` → `build_singularity_attachments` `:2384`, so the cycle failure fired first at
TB1; and CB2's diff to that file begins at old line **842**, leaving all three functions untouched. Not a
regression, not a side effect of the cut, and not a defect in Amendment 15's implementation — the witness simply
got further.

**Amendment 16 declared**, generalizing 15 from the cycle basis to **every** A1 derivation that walks transport:
a barrier is never traversed, never supplied with a branch transport, and never required to have one; a closed ring
is replaced by the fan of one connected component of `star(v) ∖ B(R)`, which is open when the vertex lies on a
barrier. A degree-1 tip is **not** exempt — its star is not split, but the ring walk still straddles the single
barrier ray. The amendment fixes the frame and the prohibition and **deliberately leaves the port-emission policy
open**: per-sector ports versus absorbing the index into the slit boundary cycle and emitting none differ in
product-visible behaviour — the second means no traces start at that singularity — and the choice needs a measured
census of barrier-incident singularities that does not exist. **AN4** forbids designing across that gap. CB2 has
already created the contradiction the amendment forbids in miniature: AM4 binds a barrier-incident singularity to a
**slit boundary cycle** while the port derivation still demands a **closed transportable ring** for the same vertex.

**Owned: measure AM2 was under-specified.** It required auditing every consumer of `globalVertexByLocal` *by
search, not by copying the list*. That search was performed faithfully and correctly found nothing about
`build_singularity_attachments`, which touches neither that map nor the local mesh nor the cut — and holds the
invalidated assumption anyway. The instruction to search was right and the **predicate** was wrong: the audit was
scoped by symbol when the thing to audit was an assumption. Third instance of the family `LESSONS.md` 59/61 record,
and the first where the enumeration discipline was honoured and the scope still missed. Recorded as `LESSONS.md`
**66**, with **AN8** requiring the CB to name at least one consumer that holds the assumption without touching the
changed data structures.

**Also recorded, `LESSONS.md` 67:** the typed error at `:613-616` carries four locus fields — radial `sourceEdge`,
`sourceFace`, `sourceVertex`, `topologyRegion` — and the harness published only `code/stage`
(`tests/FieldAlignedCurveNetworkTests.cpp:5283-5285`), so the locus had to be recovered by elimination. AK1/AK2
fixed exactly this one turn earlier, in the same producer, scoped to the neighbouring code. **Instrument the
stage's error surface, not the site that is failing.** Owned by **AN1**.

**Two procedural findings.** `M3-CP4c3-TB2-ORCH-01` is **reopened and reclassified** from resolved orchestration to
a **build/packaging contract defect**: `tests/TestFixturePaths.h:51-64` falls back to the compile-time absolute
`DIRECTIONAL_TEST_SOURCE_DIR`, the build machine's own source directory — off the builder a guaranteed miss, on it
a success by coincidence of path — and package 69 ships no fixture tree (28-entry manifest against package 70's
55). Every future artifact-only TB needs the same out-of-band remedy until a CB fixes it, and a gate that depends on
a runner's directory layout is environment-dependent authority (**AN3**). And the package-70 substitution is
**accepted** — it relocates fixture bytes that were already inside the immutable source archive whose digest
matched, with no configure, compile, relink or source edit — but its load-bearing claim
`semanticBinariesUnchanged=true` is asserted by the same orchestration that produced package 70, and the manifests
are not comparable line for line; opened as `M3-CP4c3-TB2-REV-CAND-01` and owned by **AN2**. Separately, the frozen
TB2 plan's rerun rule keys on *"executed no Directional runtime"* when it means *"produced no semantic verdict"*;
R4's restart after 40 green harness-blocked processes was right and the rule was wrong (**AN7**).

**What is still unproved.** First-red at 366 left ordinals **367–373 unexecuted**, so Amendment 15's own three
self-checks — barrier exclusion from the cycle basis, the Euler cut identity, and unbound prescribed singularities
= 0 — have **never run**, and AM1's barrier decomposition, though computed by the implementation, is absent from
the TB2 report. Every DEFN-R1 prediction remains unverified, including the falsifier "a measured cycle in `B(R)`
reopens the amendment". The amendment is effective and unverified at the same time, and both halves are recorded.

Gate **373** stays frozen and unselected; `selected_gate=NONE`, `gate_execution_authorized=false`. Accounting
unchanged: **44 / 14 / 30**, debt **5**, semantic packages **69**, **+0 events / +0 recurrences**.

Exact next: **`M3-CP4c-3-CB3`** — Code + Build under AN0–AN9, runtime-free, GMP/GMPXX linked.

## 2026-08-31 — `M3-CP4c-3-TB2`: orchestration remediated; valid semantic first-red moves to ordinal 366

Following explicit user authorization, the fixture-root defect from the initial TB2 attempt was corrected without changing semantic source or binaries. Fixture-only package **70** (artifact `9744461475`, SHA-256 `4265079b78af1a95300eebdaa5f2b2643030aa1ad2f51b70f904d88b16de7fe5`) adds the immutable packaged fixture tree at sibling `test-data`; package-69 semantic binaries were proven byte-identical. R1–R3 exposed only orchestration mapping/preflight defects and carry no gate authority.

R4 run `33355714664` reproduced package/source/GMP/selector authority and the exact static 227/30/75/41 target map, then ran selector 373 one identity per fresh process. Ordinals **1–365** selected exactly once and exited green. Ordinal **366**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, selected once and failed with `InvalidFieldTransportAtlas/field-transport-atlas/MissingSingularityBranchTransport`; ordinals **367–373** were not executed under first-red semantics. Postflight proved package/source/selector/mapping unchanged and no compile/relink/repair/generated-discovery/benchmark occurred.

`M3-CP4c3-TB2-ORCH-01` is resolved as non-stable orchestration debt. New `M3-CP4c3-TB2-CAND-01` records the valid semantic first-red and routes to independent **`M3-CP4c-3-TB2-REV`**. Stable accounting remains **44 events / 14 categories / 30 recurrences**, debt **5**, authoritative semantic packages **69**. No product correction or TB retry is authorized before review.

## 2026-08-31 — `M3-CP4c-3-TB2`: blocked by packaged-binary fixture-root authority after runtime began

Artifact-only TB2 consumed immutable GMP package **69** / artifact `9742715856` and reproduced package/source/GMP/selector preflight. Selector 373 began one identity per fresh process: ordinals **1–40** selected once and exited green; ordinal **41**, `MilestoneGP26.PrescribedSphereSingularitiesMatchRecoveredValence`, selected once but threw before product adjudication because `TestFixturePaths` fell back to the producer binary's compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR` (`/home/runner/work/Directional/Directional`) and could not open `benchmarks/fixtures/milestone_g_manifest.json` there. The exact manifest exists in the immutable packaged source; the artifact-only harness had materialized that source at another root and package 69 contains no sibling `test-data` fallback.

This is **`M3-CP4c3-TB2-ORCH-01` — ORCHESTRATION / NON-STABLE**, not a semantic red. The frozen TB2 plan permits a control-plane restart only when no Directional runtime executed; 41 test processes had already run, so no corrected-root retry was authorized. Ordinals **42–373**, including checkpoint-local 366–373, remain unexecuted and the 40 preceding passes receive no gate authority. Postflight re-proved package SHA, **28/28** manifest, source archive, selector 373, executable modes and source-tree immutability; no configure/compile/relink/repair/generated-discovery/benchmark or source/test/fixture/selector/package mutation occurred.

Stable accounting remains **44 events / 14 categories / 30 recurrences**, debt **5**, packages **69**. `LESSONS.md` 76a now requires preflight to prove the runtime fixture root actually selected by the packaged binary, not merely archive layout. CP4c-3 remains **OPEN**. Exact successor: independent **`M3-CP4c-3-TB2-REV` — REVIEW + PLAN**; no product/test/build correction, rebuild or gate retry before that review.

## 2026-08-30 — `M3-CP4c-3-DEFN-R1`: Amendment 15 — a region's transport domain is the region cut along its barriers

Combined definition + review turn under the standing cadence, discharging **AL2**. Nothing executed, compiled,
packaged or benchmarked; no gate selected or run; **no product, test, fixture, selector or build-logic byte
changed**. Measures issued: **AM0–AM9**. Full record:
`Architecture_M3_CP4c3_DEFN_R1_Frozen_Definitions.md`. Normative record: `DESIGN.md` §7.2.1 **Amendment 15**.

**Two theorems settle the scope, and both are forced by construction rather than observed on one witness.**

*Theorem 1 — the defect class is exactly `B(R) = { e ∈ hardFeatureEdges : both incident faces ∈ R }`.*
`FieldTransportAtlas::make` (`:1456-1491`) routes every edge through four ordered buckets. A `SourceBoundary` edge
has one incident face and a `NonTraversable` edge has its faces in different regions or components, so each has at
most one face in any region and is therefore **already a local boundary edge**, never interior; a bucket-4 edge has
an adjacency and cannot raise the failure at all. Only a hard feature can be non-traversable *and* interior.
Corollary, and it bounds the fix: an **isolation seam** — same region, same component, different sheet, not a hard
feature (`SurfaceCellTracing.cpp:6837-6851`) — falls through to bucket 4 and **does** get a transport adjacency, so
seams are not part of this class and must not be swept into the correction.

*Theorem 2 — cutting along `B(R)` never disconnects `R`.* A region *is* a connected component of the face graph
built while skipping every hard-feature edge (`:6715-6741`), so cutting along `B(R)` leaves that graph untouched
and the cut mesh is connected, for every region and every barrier set. It follows that **no subset of `B(R)`
separates `R`** — and hence, on a region with `χ = 2, b = 0` where every closed curve separates, that every
component of `B(R)` is a **tree**. The mechanical witness's barrier set is a forest.

**Decision — Amendment 15, option A in its derived-view form (A′).** A region's face set and its published
`euler_characteristic()` / `boundary_loop_count()` are facts about the **uncut** source complex and are unchanged.
A1 instead derives its tangent bundle, cycle basis and index quantities from the region's **transport domain**: the
region cut along `B(R)`. Three reasons. The region product **cannot express an open slit** —
`build_source_topology_regions` requires every region-boundary vertex to have exactly two boundary neighbours
(`:6905`) and fails the entire `SourceTopologyRegions` product otherwise, and an arc's tip would have one; so
adding `B(R)` to `region.boundaryEdges` breaks A0/A2 for every witness with an open feature arc. It is the
**Amendment 14 precedent** — an immutability guarantee constrains the writer, not a derived view. And it makes the
two disagreeing classifications agree **by construction** rather than by an unwritten assumption, which is the
corrective form `RP-01` prescribes.

**The endpoint rule, derived — AL2's hard part.** A vertex `v` incident to `B(R)` is duplicated into one copy per
connected component of `star(v) ∖ B(R)`: `copies(v) = d_B(v)` for `v` interior (a disc cut by `d` radial rays has
`d` sectors, including `d = 1`, where one ray does not disconnect it), and `d_B(v) + 1` for `v` on the region's
boundary (a path cut at `d` points has `d + 1` pieces). **An open arc's tip is therefore not duplicated** — the cut
surface genuinely touches itself there — but it becomes a boundary vertex with a single fan. The result is a
manifold with boundary, geometry does not move, and `TriMesh::set_mesh` re-derives `EV`, `EF`, `isBoundaryVertex`
and `boundaryLoops` from the rewritten face array with no further bookkeeping.

**The arithmetic, shown rather than asserted.** `ΔV = (2|B| − |V(B)|) + ∂`, `ΔE = |B|`, `ΔF = 0`, giving the
identity **`χ(R_cut) = χ(R) − χ(B) + ∂`** with `χ(B) = |V(B)| − |B|`. Checked against four independent cases:
sphere + one arc → disc; torus + one non-separating loop → annulus; disc + arc to the boundary → disc; disc + arc
between two boundary points → two discs. For the mechanical witness this fully determines the outcome without
measuring it: `χ' = 2 − c`, `b' = c`, `genus' = 0` for **every** `c`, `interiorVertices' = 152 − |V(B)|`,
`expectedCycleCount' = 152 − |V(B)| + c`, `innerAdjacencies = 450 − |B|`. Cross-checked against the dual cycle
space dimension `151 − |B|`, the cycle matrix's **rank deficiency stays exactly 1** — the same value it has on the
uncut mesh — so nothing downstream that tolerates today's single dependency newly breaks. And because
`dual_cycles`' columns are **inner edges only**, a barrier edge becomes structurally incapable of raising
`CycleTransportAdjacencyMissing`; the code survives, correctly, only for a genuinely missing adjacency on a
traversable edge.

**Three costs, all required work, none visible at the failing line.** (1) The `:1654` local-mesh-versus-region
cross-check must be **replaced** by the cut identity under a new appended error code, not deleted — it is the only
tie between the local mesh and the region authority, and the replacement is strictly stronger, constraining three
derived quantities instead of two. (2) A slit region moves from the closed `ClosedShenSufficient` index
**equality** (`:1872`) to the boundary-corrected `RelativeBoundary` branch (`:1878-1898`), which absorbs any
multiple of 4 into the first boundary cycle — correct Gauss–Bonnet, but a real weakening that must appear in
evidence rather than be discovered later. (3) Every vertex on a barrier loses its inner-vertex cycle, so
`:1843-1851`'s prescribed-index agreement check stops running for it — and the global reconciliation does not catch
the gap, because `:1557` partitions by the **global** mesh's `isBoundaryVertex` and the interior path
(`:1980-1990`) leaves a missing owner as an empty `std::optional` and continues while the boundary path
(`:1960-1976`) fails closed.

That third item is opened as **`M3-CP4c3-DEFN-R1-CAND-01`**: a pre-existing latent gap at HEAD, **not** introduced
by the amendment but made reachable by it, and owned by **AM4**. Landing the cut without it trades a red gate for
an unverifiable certificate. Recorded as `LESSONS.md` **65**: *when one obligation is discharged by two paths, diff
their failure behaviour, not their success behaviour* — and be most suspicious when the split key belongs to a
different object than the thing being reconciled.

Option **C** stays prohibited. Option **D** — fail closed with a precise appended typed reason — is retained as the
frozen fallback with an explicit declared trigger, at the stated cost that criterion **C2** cannot then close.

Six falsifiable predictions are recorded, including that `B(R)` will contain **no cycles** on the mechanical
witness (a measured cycle falsifies Theorem 2 and reopens the amendment) and that region 0's witness kind will
change from `ClosedShenSufficient` to `RelativeBoundary`.

Gate **367** stays frozen and unselected; `selected_gate=NONE`, `gate_execution_authorized=false`. The append point
is defined but not executed: AL7's three identities give **370**, and Amendment 15's three
(`NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis`, `CutTransportDomainSatisfiesTheEulerCutIdentity`,
`PrescribedSingularityOnABarrierArcRemainsBoundToACycle`) give **373**, with all five predecessor prefixes
re-verified at CB2's freeze. Accounting unchanged: **44 / 14 / 30**, debt **5**, packages **68**,
**+0 events / +0 recurrences**.

Exact next: **`M3-CP4c-3-CB2`** — Code + Build under AM0–AM9, runtime-free, GMP/GMPXX linked.

## 2026-08-30 — `M3-CP4c-3-TB1-REV`: mechanical cause established; the sphere's is one level short

Independent review and planning only. Nothing executed, compiled, packaged or benchmarked; no product, test,
fixture, selector or build-logic byte changed. Measures issued: **AL0–AL9**. Full record:
`Architecture_M3_CP4c3_TB1_Independent_Review_Record.md`.

**TB1 execution ACCEPTED as a valid semantic red.** Immutable package **68** artifact `9739919234` consumed
directly; preflight/postflight PASS; `packageImmutable=true`, `sourceImmutable=true`, `zeroSelected=0`; configure,
compile, relink, repair, generated discovery, benchmark execution and mutation all false; one identity per fresh
process from ordinal 1 with a first-red hard stop. The working tree is byte-identical to the packaged semantic
source `48dd011c4aa689a245b74527ed9df0900ada9bf3` (`git diff --stat … -- tests/ src/ include/` empty), so every
source claim in the review describes exactly what ran. Selector **367** and all four of its prefixes were
recomputed from committed bytes and match the DEFN freeze. **The accepted 365 prefix is green on package 68**, so
CP4c-2's closure is undisturbed. The single escaping exception at ordinal 366 is the test body's own failure
carrying the AK1/AK2 diagnostic, not an orchestration fault. CB1 delivered AK1–AK3 exactly as specified: an
enumerated eight-value reason populated at all eight sites, additive, with no mapping changed and no enum value
renumbered.

**Mechanical witness — CAUSE ESTABLISHED, and it is an architectural disagreement rather than a bug at a line.**
Edge `0-3` is a `HardFeature` **barrier**, established by elimination over `FieldTransportAtlas::make`'s four
adjacency buckets: `SourceBoundary` is excluded by `globalEF=1,158` (two incident faces), `NonTraversable` by a
region count of 1 over all 300 faces, and `adjacencies` by the measured `fieldTransportAdjacencyExists=false`; the
loop iterates every row of `mesh.EV`, so the edge was certainly classified. It entered the cycle basis anyway
because `build_source_topology_regions` (`src/geometry/SurfaceCellTracing.cpp:6655-6737`) skips hard-feature edges
when flood-filling regions, and **skipping an adjacency disconnects nothing unless the removed edges separate**.
They did not: region 0 is all 300 faces with `boundaryLoops=0`, so `make_local_region_mesh`
(`src/authority/FieldTransportAtlas.cpp:850-895`) sees the edge as interior (`localEF=1,158`, 0 local boundary
edges), `PCFaceTangentBundle` counts it among the 450 inner adjacencies, and the transport walk asks
`find_adjacency_in(adjacencies, edge)` for an adjacency the atlas deliberately withheld. **The region decomposition
and the traversability classification disagree about the same edge**; A1's cycle-basis machinery assumes region
boundaries and non-traversable edges coincide, which is true for source boundaries and *separating* feature curves
and false otherwise.

**Why that is forced, not incidental.** Region 0 has `χ=2`, `genus=0`, `boundaryLoops=0` — a sphere — and every
closed curve on a sphere separates it. Since the features demonstrably did not separate, the mechanical witness's
feature set **necessarily contains at least one open arc**. The torus succeeds only because its 48 hard-feature
edges form four closed loops that **do** separate it into four annuli, putting them on region boundaries where they
never enter a local mesh's inner set. The first witness with an open feature arc was always going to hit this, and
`ROADMAP.md`'s "closed-surface missing field-transport adjacency in A1" was pointing at this site all along — now
confirmed at ordinal 366 rather than assumed.

**Prescribed sphere — the measurement is one level short; phase 2 NOT authorized for it.** AK3 collapsed nine sites
to `TraceEventPositionInvalid`, but that name is *itself* a two-way collapse: `trace_event_position`
(`src/geometry/EmbeddedGraphTopology.cpp:138-173`) returns `std::nullopt` from a single
`if (positions.size() != 1U)`, where `positions.empty()` is a network/event **binding** defect and
`positions.size() > 1` is an **ambiguity** — the position is not determined by `sourceEdge` alone — and the two need
**opposite** fixes. The function also runs a face-restricted pass and then, only if that found nothing, a widening
fallback over all segments ignoring the face, which can turn "no match in the right face" into "several matches
across the trace" and so manufacture the ambiguous case. Ambiguity is the live **suspicion** (24 traces, 56 events,
10 terminal trace intersections; a trace crossing one source edge twice yields exactly `size() == 2`) and is
explicitly **not promoted to a finding**. If ambiguous, the stronger key already exists and costs nothing to
consult: `segment.entryPoint` / `edgeTransitExit` publish the exact crossing point.

**The two causes do not share a locus** — A1 `FieldTransportAtlas` cycle-basis construction versus A2a′
`EmbeddedGraphTopology::trace_event_position` / `build_arcs`, no shared code and no shared datum — answering the
question the DEFN left open and allowing them to be worked independently.

**Disposition.** Phase 2 is authorized for the **mechanical witness only**. A DEFN revision is required before its
fix lands, because the corrective changes what a topology region *is* when a feature does not separate — a
normative question `DESIGN.md` §7.2/§7.2.1 owns that a CB may not settle by implementation. Options: **A** cut the
local region mesh along the non-separating barrier arc so it becomes real boundary (recommended; the hard part is
the arc's endpoints, where the cut surface touches itself); **B** build the cycle basis over the traversable
sub-complex only (converges on A, since `PCFaceTangentBundle::init` takes a mesh, not a barrier set); **C** give
barrier edges a transport adjacency — **PROHIBITED**; **D** fail closed with a precise typed error, the frozen
fallback if A exceeds CP4c-3, at the cost of C2 not closing.

Tracker dispositions: `M3-CP4c3-DEFN-CAND-01` → **CAUSE ESTABLISHED**; `M3-CP4c2-TB-X2-CAND-04` → **ACTIVE / ONE
LEVEL SHORT**; `M3-CP4c2-TB-X2-R10-CAND-01` and `M3-CP4c2-TB-X2-R8-CAND-02` unchanged and unblocked;
`M3-CP4c3-TB1-ORCH-01` closed but escalated. That orchestration control transcribed a packaged-source SHA-256 as a
**63-hex** value — the **third** occurrence of `R7-ORCH-01`, which `LESSONS.md` 22n and measure AE4 exist to
prevent — so **AL8** moves the 64-lowercase-hex validation into the payload authoring path itself: a rule that has
failed to prevent its own defect twice needs a mechanism, not another reminder.

`LESSONS.md` **64** added: *when instrumenting a collapsed error, check whether the reason you are adding is itself
a collapse before declaring the layer done.* This is `LESSONS.md` 57 for the third time in this project, one level
deeper each turn.

Gate **367** stays frozen and byte-identical; `selected_gate=NONE`, `selected_r2_branch=NONE`,
`gate_execution_authorized=false`. No accepted-green behaviour was lost — ordinal 366 belongs to a gate that has
never been accepted and the accepted 365 prefix went green in the same run — so **+0 events / +0 recurrences**.
Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **68**.

Exact next: **`M3-CP4c-3-DEFN-R1`**, a combined definition + review turn under the standing cadence settling AL2's
normative question, then **`M3-CP4c-3-CB2`** under AL3 and AL5.

## 2026-08-30 — `M3-CP4c-3-TB1`: accepted 365/365 re-proved; ordinal 366 valid red localizes mechanical A1

Artifact-only Test + Benchmark execution. Authoritative run/job `33340448381 / 99335020672` consumed immutable
package **68** artifact `9739919234` directly. Result artifact `9740416876` has SHA-256
`713d4e6853adde54e17738d6d25e5a310a5f88ff8e4232abf67bb73c7a8cbdc0`; diagnostic artifact `9740417020` has
SHA-256 `8302f6ae50a8d5d29f92952aed0f144eb78bda3f070612f3dec67a63701debc0`. Preflight/postflight and package/source
immutability passed; configure/compile/relink/repair/generated discovery/benchmark/mutation were all false.

Frozen selector **367** remained byte-identical. The run re-proved accepted ordinals 1–365 **365/365 PASS**, then
hard-stopped at ordinal **366**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`.
Required result: **366 executed / 365 PASS / 1 RED**; ordinal 367 was correctly not executed after the first red.

**AK1 measured the previously collapsed A1 cause:** `IncompleteCycleBasisReason=CycleTransportAdjacencyMissing`.
**AK2** localizes it to topology region `0`, source edge `0-3`, with `fieldTransportAdjacencyExists=false`;
the region itself is internally count-consistent at `V/E/F=152/450/300`, χ=2, boundary loops=0, genus=0,
interior vertices=152, expected cycles=152, cycle rows=152, cycle curvatures=152, inner adjacencies=450.
**AK3** localizes the prescribed sphere's `RotationSystemInconsistent` to
`RotationSystemInconsistencyReason=TraceEventPositionInvalid`; the sphere still reaches source topology, atlas and
network (24 traces / 56 events) before the cut-graph failure.

All three frozen non-gating diagnostics executed report-only (**0 PASS / 3 RED**). The torus reaches a valid
`SurfaceCutGraph` and `GlobalTopologyPlan` with 4 regions before its known downstream `tracing` failure; mechanical
and sphere reproduce the AK1–AK3 measurements. Three earlier workflow attempts stopped in preflight before any
Directional runtime and are closed as orchestration-only controls.

No stable event/recurrence is added: accepted 365 remains green and CP4c-3 has never been accepted. Stable accounting
remains **44 / 14 / 30**, produced-witness debt **5**, packages **68**. Full retained report:
`Architecture_M3_CP4c3_TB1_Artifact_Only_Test_Benchmark_Report.md`.

Exact next: **independent CP4c-3 phase-1 TB review / planning**. No phase-2 product correction is authorized before
that review interprets the measured causes and orders AK4–AK7.

## 2026-08-30 — `M3-CP4c-3-DEFN`: gate 367 frozen, the sphere gated, and A1's seven-way error collapse found

Definition, review and planning in one turn. **Cadence change, user-authorized 2026-08-30:** when `DEFN` is the next
step in the chain it **is** the review-and-plan turn for its checkpoint — one turn freezes definitions, adjudicates
inherited candidates, decides gate membership, and issues the successor's measures. Only the `REVIEW+PLAN → DEFN`
edge collapses; a red TB with no `DEFN` ahead of it still gets its own review turn. Recorded additively in the
durable turn-workflow sections of `TODO.md` and `Future_Chat_Session_Handoff.md`.

No Directional runtime, build, compile, package, benchmark, or product/test/fixture change. One selector authority
file was **created**; no existing selector byte was modified. Measures issued: **AK0–AK9**. Full record:
`Architecture_M3_CP4c3_DEFN_Frozen_Definitions.md`.

**The finding — `IncompleteCycleBasis` is a seven-way collapse, and the mechanical witness has never been
diagnosed.** `ORIENTATION` had recorded only "no atlas — stops in A1 at `IncompleteCycleBasis`". Read at source,
`src/authority/FieldTransportAtlas.cpp` returns that one code from **eight sites** — `:1597, :1613, :1673, :1682,
:1688, :1700, :1751, :1818` — for **seven distinct conditions**, and **five of them publish nothing but a region
id**. Site `:1682` is literally "no `FieldTransportAdjacency` for a cycle's edge", the phrase `ROADMAP.md` uses for
CP4c-3's parent responsibility, so the roadmap points at one site among seven that has never been confirmed. This is
`LESSONS.md` 57 recurring in A1, and CP4c-2 paid **eight turns** for the identical pattern at `topology_error`. AF0's
additive-provenance fix is the direct template, applied by **AK1**; **AK2** additionally publishes the
local-region-mesh shape per region, because `:1613`, `:1751` and `:1818` all derive their expectations from it and
the site alone will not explain a count mismatch. **No mechanism is promoted** — the candidate readings are
hypotheses, and AK1/AK2 exist so the next turn reports a measurement rather than adopting one.

**The prescribed sphere is IN CP4c-3's gate.** AJ2 required this decided explicitly. It has sat outside two
consecutive frozen gates, and `LESSONS.md` 64w plus the `AF5` finding record that a witness outside every gate is
how a defect survives — the sphere's own eight-turn misdiagnosis is the proof. It is also the only remaining witness
that cannot reach A2b at all, and A2b is what M4 builds on; and its problem (b) is directly coupled to
`R10-CAND-01`, which CP4c-3 already owns. Adding a gated **witness** is not reallocating a **criterion**:
`ROADMAP.md`'s C1/C3/C6→CP4c-2, C2→CP4c-3 allocation is untouched, and which witnesses a checkpoint's identities
bind is a DEFN decision.

**`R8-CAND-02` decided rather than deferred a third time.** An empty network on a closed surface is **rejected with
a typed error**. A2a′'s contract is to add cuts to an existing network; cutting from scratch would make it the
producer of the entire embedded graph, which is A2a's single-writer authority, and a "certified" plan from a witness
with no field-aligned content is the vacuous-green shape `LESSONS.md` 64r warns about. The new code is **appended**,
never renumbered, since accepted identities consume the existing values.

**Gate 367 frozen.** `Architecture_M3_CP4c3_Required_Green_Selector_367.txt`, whole-file SHA-256
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` — accepted 365 plus ordinal 366
`GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` (criterion **C2**) and ordinal
367 `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` (criterion **C3**'s full
torus-and-mechanical form, honouring DEFN-R2 §7.3's commitment to move the mechanical half here). `head -355`,
`head -357`, `head -361` and `head -365` all reproduce their frozen hashes. Both appended identities are **red
today**, which is correct for a required-green selector. Three further identities are named for append under
**AK7**, producing gate **370**: the sphere's production-entry-path identity, an ordinary-proposal-without-saturation
identity, and the empty-network rejection identity.

**Two phases, one gate.** Phase 1 instruments (AK1–AK3) and fixes nothing; phase 2 fixes on measured causes
(AK4–AK6), with its internal ordering left to the phase-1 review because the measured causes may share a locus — as
the torus and sphere did. **AK6 states it plainly: a fix whose report cannot name the measured site is not
authorized.** **AK8** requires every "every site / every region / every consumer" measure to be discharged by the
implementer's own search, with the DEFN's eight-site table used only as an after-the-fact cross-check —
`LESSONS.md` 59 and 61 exist because a copied enumeration inherits the author's omissions.

Stable accounting unchanged: **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **67**.
CP4c-2 remains CLOSED / ACCEPTED at 365/365. Exact next: **`M3-CP4c-3-CB1`** under AK0–AK3.

## 2026-08-30 — `M3-CP4c-2-TB-X2-R10-REV`: **`M3-CP4c-2` CLOSED / ACCEPTED at 365/365**

Independent review and planning only. No runtime, build, compile, package, benchmark, or product/test/fixture/
selector mutation. A green gate closes a checkpoint, so this review verified rather than accepted: the working tree
was confirmed byte-identical to packaged semantic source `57444781af7bdc460e38cc68930a9a8c8199eeea`, all four
selector-365 authorities were recomputed from committed bytes, and **the whole CB8→CB9 product diff was audited line
by line**. Measures issued: **AJ0–AJ9**. Full record:
`Architecture_M3_CP4c2_TB_X2_R10_Independent_Review_Record.md`.

**Accepted authority.** Source `57444781af7bdc460e38cc68930a9a8c8199eeea`; GMP package `9736088354`, SHA-256
`78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`; packaged source archive
`2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`; run/job `33331453506 / 99310594268`;
result/log artifacts `9737796927 / 9737797177`; selector **365** SHA-256
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`; **365/365 PASS**, first red none, immutable
pre/postflight green, every mutation and benchmark flag false, one identity per fresh process from ordinal 1.

**What CP4c-2 delivers.** Criteria **C1**, **C3** and **C6** green. A2a′ `SurfaceCutGraph` is a certified
pre-region authority: the closed genus-1 torus goes from a non-cellular network to a certified cellular embedding
with 28 cut edges, A2b derives 4 regions from it, and producer and independent oracle agree term for term
(actual graph `V/E/F = 72/76/4`; `76 − 48 = 28`). Cellularity is certified in the **actual embedded graph**
(Amendment 13); trace-crossed source edges are admissible cuts with proved completeness (Amendment 14); semantic
and provenance identity are separate digests, proved on a bounded *and* a closed witness; enumeration invariance is
proved rather than asserted.

**The green is not vacuous — CB9 audited.** `arcIndices.size() != 1U` became `arcIndices.empty()`, dropping only
the upper bound and **retaining a typed `InvalidCutGraphBinding` for zero arcs**; the per-face body now runs once
per sub-arc with both existing guards retained; and the stale "ordinary embedded source-edge barriers" comment was
replaced with one that **explicitly names the canonical-direction dependency** the dart formula rests on. The
`boundaryVertices` fix **tightens**: it resolves each sub-arc endpoint through the shared `NodeLocus` authority,
inserts a source vertex only for a node with a `vertex` locus, and adds a typed error for an unresolvable node —
and because `boundaryVertices` is a skip list it can only create reds, never manufacture a pass. None appeared.
`build_node_loci` is now computed once and threaded to both consumers, removing a pre-existing redundant recompute.
**Nothing in the diff weakens a check**, and AI8's exclusions were respected in full.

**AI2's reconciliation is proved by the product, not merely published.** `GlobalTopologyPlan.cpp:679-687`
unconditionally rejects unless `fragmentOrbits[face].size() == tracePieceCount[face] + 1` for every face, and CB9
left that guard untouched; ordinal 363's pass therefore proves R9-REV's geometric argument on every face, including
those incident to a promoted trace-crossed edge. The 178 retained diagnostic rows are corroboration; **AJ3** still
requires them read and compared.

**`R9-CAND-01` CLOSED**, and with it the first runtime proof of two long-pending contracts: ordinal **364**, the
degree-four two-Cut/two-Trace edge-locus rotation — the single genuine code gap DEFN-R2 named, compiled and
unexecuted for three turns — and ordinal **365**, the saturation last resort, which publishes its fields while
cellularity remains independently proved by the certificate afterwards.

**`AH6` fired, and its cause is the reviewer's.** R10 published
`ordinary_proposal_selected_trace_crossed_edge=no` with `saturation_used=yes`: the only route by which a
trace-crossed edge enters the cut set is saturation. The mechanism is in the committed loop —
`barriers = mandatory ∪ traceCrossed ∪ cuts`, so a trace-crossed edge **bounds** a proposal component instead of
lying inside one, and a tree–cotree search draws from a component's interior edges. DEFN-R2 §4.5 removed the
*filter* but permitted the conservative *barrier set* on the reasoning that over-separation "costs extra cuts,
never correctness" — true about correctness, wrong about coverage. Amendment 14's **representation** is fully
proved regardless, since ordinals 363/364 assert on an actually-promoted crossed edge whichever path selected it;
what is at stake is cut-graph **quality**. Opened as `M3-CP4c2-TB-X2-R10-CAND-01`, owned by **AJ4**, corrective
identified: model trace crossings as **per-face chords** in the proposal — heuristic-only, so Amendment 14 is not
reopened.

**This did not withhold closure, and the reasoning is recorded because the temptation ran the other way.** Gate 365
was frozen at CB7 under AG7 before any of this was known, every identity passed, and the run is valid. Adding a
coverage condition after the evidence arrived would be the goalpost-moving this project corrected twice — including
at R7-REV, when the new information favoured being *strict* and `PR8-R044` still closed on its frozen condition.
The discipline has to hold when it favours leniency too.

**What CP4c-2 does not deliver**, recorded so the closure is not read as more than it is: the **prescribed sphere**
still fails before cut selection (`originatingTopologyError=RotationSystemInconsistent`, source face `25-27-28`) and
is independently non-cellular pre-cut (`V/E/F = 18/30/18`, `chi=6` vs `sourceChi=2`) — it sat outside the gate by
recorded decision, so **CP4c-2 closes with one of its three witnesses unable to reach A2b at all**; Amendment 14's
ordinary proposal path is unexercised; and `R8-CAND-02` is unresolved. All three carry to CP4c-3.

**Lesson adopted:** `LESSONS.md` **63** — a green gate proves exactly what it enumerates, so name what it did not
cover in the same breath; and once a gate is frozen, do not add conditions to it, whether the new information
favours strictness or leniency.

Stable accounting unchanged: **44 / 14 / 30**, debt **5**, authoritative M3 packages **67**. Selector 365 becomes
accepted authority. Exact next: **`M3-CP4c-3-DEFN`** under AJ0–AJ9; CP4c-3 is unblocked.

## 2026-08-30 — `M3-CP4c-2-TB-X2-R10-EXEC`: valid immutable 365/365 green execution; review pending

Artifact-only runtime/raw-evidence subturn. Run/job `33331453506 / 99310594268` consumed CB9 package `9736088354` directly and completed successfully. Result artifact `9737796927` has SHA-256 `b02022367785d6a4790549ad127bff69f831404b6ea525f426b707794f71649b`; diagnostic artifact `9737797177` has SHA-256 `0a374b6b240877049eacfec2c70be944c39ce3cc4e5a6c461c358a1b206e78c8`. Immutable preflight/postflight passed; configure/compile/relink/repair/generated discovery and all package/source/test/fixture/selector mutation flags were false; `benchmarkExecution=false`.

Three frozen non-gating identities executed once each (**2 PASS / 1 RED**). The required-green selector re-proved accepted ordinals 1-355 **355/355 PASS** and passed every tail ordinal 356-365, including 363, 364 and 365, for **365/365 GREEN** with no first red. Ordinal 363 published AI2 evidence in the same process: 50 fragment-reconciliation and 128 cut-edge-orbit rows. AH6 is applicable; raw publication records `ordinary_proposal_selected_trace_crossed_edge=no`, `saturation_used=yes`, and a saturation-reached state. EXEC performs no candidate classification or acceptance decision. Exact next is `M3-CP4c-2-TB-X2-R10-REV`, which owns tracker updates, R9-CAND-01 disposition, AI2/AH6 interpretation, and CP4c-2 acceptance eligibility. Stable accounting remains **44 / 14 / 30**, debt **5**, M3 packages **67** pending review.

## 2026-08-30 — `M3-CP4c-2-CB9`: both stale Amendment-14 consumers corrected; package 67 build-green

Code + Build only. Semantic/test source `57444781af7bdc460e38cc68930a9a8c8199eeea` implements R9-REV AI0-AI9 without selector, sphere, crossing-producer, error-enum, invariant, or benchmark widening. AI1 independently re-derived the full Cut/cut-edge consumer set; exactly two A2b consumers were stale. Region binding now iterates every derived Cut sub-arc under the canonical source-edge direction invariant, and region-certificate `boundaryVertices` now uses the existing shared `NodeLocus` authority so only actual sub-arc source-vertex endpoints enter the skip list. AI2 fragment/orbit diagnostics were added, ordinal 359 is recorded beside the semantic-digest rationale, and both typed-error helpers stop before `built.value()` fall-through.

Compile-only run `33325344311`: changed-owner prepackage job `99294371782` compiled `directional_surface_cell_producer_tests` **105/105**; package job `99294619815` compiled all eight standard targets through `agent-compile-reusable.yml` with GMP/GMPXX. Immutable package **67** is artifact `9736088354` (`78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`); packaged source archive `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`; internal manifest **28/28 PASS**; `runtimeExecution=false`. Stable totals remain **44 / 14 / 30**, debt **5**. Exact next: `M3-CP4c-2-TB-X2-R10-EXEC`, artifact-only under the now-consolidated R10 frozen plan (`M3_CP4c_Consolidated_Record.md` §3.8); R10-REV owns diagnostics/disposition after EXEC.

## 2026-08-30 — `M3-CP4c-2-TB-X2-R9-REV`: four closures, and A2b's stale one-arc-per-cut-edge binding

Independent review and planning only. No runtime, build, compile, package, benchmark, or product/test/fixture/
selector mutation. Static analysis ran against a working tree verified byte-identical to packaged semantic source
`05f9ef299ee54f8c9d50318fc9a37e5a5503740d`; selector-365 and accepted-355 hashes recomputed from committed bytes.
Measures issued: **AI0–AI9**. Historical review record consolidated in `M3_CP4c_Consolidated_Record.md` §3.7.

**Four long-running items closed by R9** (run/job `33319911575 / 99279955697`, CB8 package `9726295440`; accepted
prefix 355/355 and ordinals 356–362 green):

- **`M3-CP4c2-TB-X2-R8-CAND-01` CLOSED.** Its frozen condition — 359 and 361 both green in a run reaching 361 — is
  satisfied. AH2 was the right correction: rebuilding both identities on one production feature authority (rails,
  hard-feature edges, component and sheet labels) made the closed-torus witness constructible, confirming the
  vacuous-rail-set diagnosis by the fix working.
- **Measure `AD3` RESOLVED.** Ordinal 359 reached and passed its enumeration-invariance comparison for the first
  time, so consuming the raw `face.orbit` index in `candidate_semantic_hash` is now proved by test rather than by a
  code comment — after three turns.
- **Criterion `C3` GREEN** at ordinal 362, after seven deferrals; DEFN-R2's decision to split it (torus half gated,
  mechanical half to CP4c-3) is vindicated. **C1, C3 and C6 all now hold on the produced torus.**
- **`PR8-R044`'s single-witness residual discharged** — the semantic/provenance split passes on a disc (360) and a
  closed genus-1 surface (361).

**Ordinal 363 — the first genuine product defect in this arc.** The witness proved an exact trace/source-edge
crossing, built a **cellular** `SurfaceCutGraph`, and selected a `TraceInteriorCrossing` candidate; A2b then
rejected the plan with `InvalidCutGraphBinding`.

- **The producer is correct**, verified line by line. `EmbeddedGraphTopology.cpp:503-545` implements DEFN-R2
  §§4.1-4.2 exactly: exact `ExactUnitParameter` ordering, coincident crossings **rejected not merged**, and every
  sub-arc emitted in the canonical `cutEdge.first() → cutEdge.second()` direction (`ArcDraft` `:175-178` stores
  endpoints verbatim). That third property is what keeps the correction small.
- **The consumer is stale.** `GlobalTopologyPlan.cpp:479-516` encodes *one source cut edge ⇒ one derived Cut arc*
  and still calls cuts "ordinary embedded source-edge barriers", while the trace block eighteen lines below already
  reasons in **chords and fragments**. **Amendment 14 made cut arcs chord-like and A2b still treats them as
  whole-edge barriers** — the whole-edge-versus-arrangement error that `PR8-R043` and Amendment 13 fixed one layer
  up, recurring at the cut/region seam.
- **The correction is provably small.** `forward` comes from the source edge and every sub-arc runs in that same
  canonical direction, so `interiorDart = 2·id + (forward ? 0 : 1)` stays valid per sub-arc. The fragment-count
  invariant survives: for edge `e` shared by `A`/`B` and crossed at `p`, sub-arcs `(v₁→p)` and `(p→v₂)` lie on
  opposite sides of the trace chord and border different fragments, so `A` gains exactly two orbits and
  `tracePieceCount[A]+1 = 2`.
- **A second consumer fails *silently*, and EXEC did not reach it.** `GlobalTopologyPlan.cpp:1239-1242` inserts the
  whole source edge's two endpoints into `boundaryVertices` for a sub-arc whose own endpoints may be a source
  vertex and a crossing node — or two crossing nodes, touching no source vertex at all. `boundaryVertices` is a
  **skip list** (`:1341-1344`), so over-inserting **suppresses** the interior-vertex ownership check with no error
  and no diagnostic: a certificate that validates less than it claims. **Fixing only the loud site would trade a
  red gate for a quiet weakening.**
- **Already correct, needing no change:** `edge_ray_points_to_second_endpoint` (`EmbeddedGraphTopology.cpp:815-828`)
  orders a Cut ray by exact `cut_node_parameter` of its **own** endpoints, so CB7's AG2 generalization is
  sub-arc-correct; and the `cutEdges` barrier sets in `GlobalTopologyPlan` are edge-keyed by intent.

**Cause of the omission — the reviewer's, owned.** DEFN-R2 §4 itemized Amendment 14 as five producer-side changes
under "what must actually be built, itemized", and AG1 said "land §§4.1–4.5 as one conversion — a partial
conversion is the defect this checkpoint is correcting". The itemization omitted A2b's cut-arc binding. CB7 and CB8
implemented all five items correctly and completely. Second consecutive turn in which an enumeration inside a
measure was read as exhaustive when it was illustrative; **AI1 is written to be self-correcting**, requiring the
implementer to produce the audit by search rather than copy the review's table.

**Still unexecuted:** ordinals **364** (the degree-four two-Cut/two-Trace edge-locus rotation — the one code gap
DEFN-R2 named) and **365** (the saturation last resort), for a third turn. **`AH6` remains not-applicable** and
carries forward. The prescribed sphere's non-gating publisher is still red with
`originatingTopologyError=RotationSystemInconsistent`; `CAND-04` unchanged.

**Lessons adopted:** `LESSONS.md` **61** ("convert every consumer" must ship with the enumeration, or say who owes
it — and require the successor to search rather than copy) and **62** (a representation change breaks consumers in
two ways; the loud one gets fixed and the quiet permissive one becomes the real defect — classify consumers by
failure mode, not by whether they compile).

Stable accounting unchanged: **44 / 14 / 30**, debt **5**, M3 packages **66**. Noted for the record: ordinal 363 is
a **product** defect, non-stable only because CP4c-2 has never been runtime-accepted. Exact next:
**`M3-CP4c-2-CB9`** under AI0–AI9; AI1 runs first and needs no build.

## 2026-08-30 — `M3-CP4c-2-TB-X2-R8-REV`: the torus is done; ordinal 359's red is a two-identity witness defect

Independent review and planning only. No runtime, build, compile, package, benchmark, or product/test/fixture/
selector mutation. Static analysis ran against a working tree verified byte-identical to the packaged semantic
source `4f0f3ca74a88ba260a20c019437bc4995f2056e0`, and all four selector-365 authorities were recomputed from
committed bytes. Measures issued: **AH0–AH9**. Historical review record consolidated in `M3_CP4c_Consolidated_Record.md` §3.6.

**What R8 established, and it is a great deal.**

- The inherited accepted prefix survived a large A2a′ rewrite: **355/355 PASS**, plus ordinals 356, 357, 358.
- **The torus is done.** Ordinal 356 publishes `networkV=48`, `networkE=48`, `cutEdgeCount=28`,
  `torusRegionCount=4`; the independent oracle publishes actual graph `V/E/F = 72/76/4`. `72 − 48 = 24` added
  vertices and `76 − 48 = 28` added edges — **28 is exactly the producer's cut-edge count**, so producer and oracle
  agree term for term. A2a′ takes a closed genus-1 surface from a non-cellular network to a certified cellular
  embedding and A2b derives four regions. Criteria **C1** and **C6** hold on the produced torus.
- **AF0 confirmed R7-REV's static derivation exactly.** The sphere prints
  `originatingTopologyError=RotationSystemInconsistent` at source face `25-27-28` with `producerCutEdgeCount=0`.
  R7-REV derived that from the nine `sourceFace`-carrying error sites in `EmbeddedGraphTopology.cpp` and refused to
  promote it without the printed code; the code matches. The sphere still fails before cut selection, so
  Amendment 14 is not an account of it.
- **AF2's repaired D2 executes** (`oracleIsCellularityOracle=false`), resolving `R7-CAND-03`. **AG3's two
  completeness-theorem conditions hold on all three witnesses** (`traceEndpointsAttached`, `noDegreeZeroNodes`) —
  DEFN-R2 §5.2's premises are now runtime-verified. **AF6 was honoured**, unlike in R7.

**The red at ordinal 359 — a witness defect, scope exactly two identities.**

`SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` fails at `FieldAlignedCurveNetworkTests.cpp:2381`
before any comparison. The mechanism is **fourfold**, not the single rail mismatch EXEC identified:

- `make_source_authority(mesh)` (`:181-191`) supplies **no** authoritative rails, **no** hard-feature edges, and
  all-zero `sourceFaceComponents` / `sourceFaceSheets`. Production (`RemeshPipeline.cpp:6377-6394`) runs
  `featureMap → build_authoritative_surface_cell_rails → hard_feature_edge_keys_from_rails → SourceTopologyRegions
  + FieldTransportAtlas`. **The test inverts an acyclic dependency**: production derives hard features *from* rails;
  the test derives rails *from* an atlas built without them.
- `rails_from_atlas` (`:229-252`) keeps only `SourceBoundary` and `HardFeature` edges. On a **closed** torus with
  `hardFeatureEdges = {}` there are neither, and uniform labels leave no `NonTraversable` edge — so the rail set is
  **empty by construction**, and with zero singularities the network is empty.
- **R8's own pass/fail split proves it.** The discriminator is closed-versus-bounded, not torus: ordinal 358 uses
  the identical construction on `make_square_mesh` and **passes**; 359 is the only one executed on a closed
  witness. Ordinal 361 shares it and is predicted to fail identically. Ordinals 356/357/362 use the production
  fixture and 363–365 thread features correctly, so **the corrective scope is ordinals 359 and 361 only**.
- `rails_from_atlas` is **not** the defect — it is correct when the atlas was told about the features first, which
  is exactly what CB7's own `build_cp4c_trace_crossed_cut_fixture` and `observe_cp4c_witness` do.

**Cause of the incomplete migration — an under-specified measure, owned by the reviewer.** R7-REV's AF3 said
"build its baseline from the production torus authority — *the same `torus.rawfield`-derived field*". CB7
implemented that exactly and correctly, including permuting raw-field rows alongside mesh rows. The parenthetical
narrowed a four-product authority to one product. This is the fifth `RP-01` in the subsystem and the first
introduced by a corrective measure written to prevent it.

**An evidence gap that must be closed before code is written.** The build lambda's `ADD_FAILURE()` calls are
non-fatal and it then returns a **default-constructed** `SurfaceCutGraphError`, so atlas / network / cut-graph
failures all arrive at one fatal `ASSERT_TRUE` and the reported locus identifies none of them. A default-constructed
error reads as `InvalidSourceBinding`, so the obvious repair — printing `error().code` there — would emit a
**fabricated locus**. AH1 requires the ordinal-359 stdout to be read from retained artifact `9725240893`, with no
new runtime.

**Still unexecuted:** ordinals 360–365 — the two-ring and closed-witness digest splits (so `PR8-R044`'s fix remains
runtime-proved on one witness), **criterion C3 deferred a seventh time**, and Amendment 14's subdivision,
degree-four rotation and saturation. **Measure `AD3` is unresolved for a third turn.**

**Records:** `M3-CP4c2-TB-X2-R8-CAND-01` adjudicated and given a closure condition; `R7-CAND-01` marked
**superseded** by it; `R7-CAND-03` resolved; `R8-ORCH-01` closed; `CAND-04` unchanged. Lessons adopted:
**59** (a measure naming an authority must enumerate its products), **60** (a helper that cannot assert must not
synthesize the product error it failed to obtain), **64z** (a construction lawful on bounded witnesses can be
vacuous on closed ones — bind the precondition to the class).

Stable accounting unchanged: **44 / 14 / 30**, debt **5**, M3 packages **65**. Exact next:
**`M3-CP4c-2-CB8`** under AH0–AH9, correcting exactly two test identities; AH1 runs first and needs no build.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R8-EXEC`: 355 accepted green; selector 365 red at ordinal 359

Artifact-only R8 consumed immutable GMP package `9724864897` from semantic source `4f0f3ca74a88ba260a20c019437bc4995f2056e0`. Authoritative run/job `33288495471 / 99195869180` passed immutable preflight, executed every identity in a fresh process, re-proved **355/355**, passed 356-358, then stopped at ordinal **359** `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration`. The failure occurs at baseline cut-graph construction before the invariance comparison: the gated test still uses test-local `rails_from_atlas(...)` while the passing production torus path consumes pipeline `authoritativeRails`. 360-365 and benchmarks were not run. AF0 now publishes the sphere's originating `RotationSystemInconsistent`; AF2 and AG3 diagnostics pass. Postflight is green with no build/repair/mutation. Result/log artifacts `9725240893 / 9725241013`; raw evidence SHA-256 `9da936add8204f35832acd0646a395b17bb71b58c56820dd5d1e52f8dcda7aa3`. Stable accounting remains **44 / 14 / 30**, debt **5**, packages **65**. Exact next: independent `M3-CP4c-2-TB-X2-R8-REV`; no retry or corrective CB first.

## 2026-08-29 — `M3-CP4c-2-DEFN-R2`: Amendment 14 makes trace-crossed cuts admissible and proves completeness; gate 361 frozen

Definition and planning only. No Directional runtime, build, compile, package, benchmark, product, test, or fixture
change. One selector authority file was **created** — the output `AF5` explicitly deferred to this turn type — and
no existing selector byte was modified. Supersedes `…DEFN_R1…` **§6 case 2** and **§8** only; Amendment 13 and
DEFN-R1 §§4, 5, 7, 9 stand unchanged, as does Amendment 12. Measures issued: **AG0–AG9**.

**Why the definition reopened.** `M3-CP4c-2-CB6` obeyed AF1, read the prescribed sphere's independent oracle row
from retained artifact `9721564203` — `V/E/F = 18/30/18`, `c=1`, `chi=6`, `sourceChi=2`,
`excludedBoundaryOrbits=0`, `surfaceCutGraphCallsInsideOracle=0` — and refuted the seven-turn standing prediction:
`V − E + F ≥ χ` with equality iff cellular, and `6 ≠ 2`, so the sphere's pre-cut graph is **not** cellular. With 24
traces and zero mandatory edges its cuts must be trace-crossed, which is exactly DEFN-R1 §8.3's trigger. **Two
independent sphere problems now stand together and must not be conflated:** the producer fails early through
`topology_error`'s lossy `default:` bucket (R7-REV, still owned by AF0), *and* the network genuinely needs cuts
(CB6, owned by Amendment 14). The oracle bypasses the producer entirely, so neither finding weakens the other.

**Amendment 14 — trace-crossed source edges are admissible cuts.** DEFN-R1 excluded them on the ground that
promoting one "would subdivide the trace — mutating an immutable upstream product". Three verified facts falsify
the premise:

- `build_arcs` (`EmbeddedGraphTopology.cpp:344-408`) already emits **one trace arc per network event**, so a trace
  is `k+1` arcs, not one — this is how the accepted 355 has been green all along;
- `build_arcs` (`:281-329`) already splits a **mandatory source edge** into two arcs at a trace terminal, one
  `NetworkEdgeId`, two arcs, a shared node interior to the source edge;
- the crossing point is already published **exactly** as `segments[i].entryPoint` (a `FieldBoundaryPoint`), at a
  segment position the subdivision machinery already keys on, and `trace_crossed_source_edges` already tests strict
  interiority exactly.

Arcs are a derived representation; the network is untouched either way. Amendment 12 forbids A2a′ *repairing* an
upstream product, not A2a′'s arrangement placing a node where the network already says two curves meet. The
admissible cut set is now **every source edge that is not already a graph arc**;
`SurfaceCutCandidateClass::TraceInteriorCrossing` is retained as provenance and removed as an exclusion.

**Completeness is proved, and DEFN-R1 §8.2 closes.** The complement of the source 1-skeleton is the open triangles,
each a disc; trace sub-arcs cut discs into discs; therefore `network ∪ (source 1-skeleton)` is a cellular embedding,
a sufficient cut set always exists, and at most `|E_source|` promotions are ever required. Consequences:

- `NoAdmissibleCutForNonDiscComponent` can no longer describe a real configuration and is retired as an outcome
  (verified: **no test consumes it** — only the raise site, the name function, and the enum declaration);
- a distinct `CutSearchExhaustedBeforeCellularity` reports "the heuristic made no progress", and **saturation** —
  promoting the component's remaining admissible edges — is the defined last resort, published with locus and
  count, never silent;
- DEFN-R1 §10 **Option B is withdrawn**: its single trigger was "no admissible cut set exists", which §5.3 proves
  cannot happen. The accepted path keeps A2a′ wired in, and therefore keeps the detector that caught `PR8-R043`.

**The one real code gap:** at an edge-locus node, `build_rotation_system` (`:833-935`) handles `Mandatory` rays
only at exactly degree three and requires everything else to be a `Trace` — a `Cut` ray there is an unhandled
shape, and a crossing node is two collinear `Cut` rays plus two `Trace` rays. The existing four-sector cyclic model
generalizes to it; a second ordering routine is prohibited.

**AF5 resolved — CP4c-2's gate is selector 361, frozen.** Created as
`Architecture_M3_CP4c2_Required_Green_Selector_361.txt`, whole-file SHA-256
`61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`, computed from the created bytes and validated
as 64 lowercase hex per AE4.

- All **four** `SurfaceCutGraph.*` identities are **GATING**, each with a written rationale. Two enter red pending
  AF3/AF4 — deliberate, since a required-green selector states what must hold for the checkpoint to close.
- **357 superseded** (incomplete, not wrong; both its identities are retained). **358 withdrawn** — its sole
  addition binds `cp4c_mechanical_fixture()`, which throws when no atlas is retained, and the mechanical witness
  is out of CP4c-2 scope. Both files retained as historical authority.
- `head -355` and `head -357` of the 361 file reproduce `e9d88f11…5afeaa` and `b896d0db…64dc70` exactly, so
  `first_red_ordinal` stays comparable across the whole CP4c arc. (Candidate 358 had broken this by *inserting* at
  line 357 rather than appending.)
- **Criterion C3 is split, not withdrawn:** `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness`
  is created and gated; the mechanical half moves to CP4c-3 / C2.
- `selected_gate=NONE` and `gate_execution_authorized=false` are unchanged — freezing a gate's bytes is not
  selecting it.

**`DESIGN.md` §7.2 gained a normative amendment record (§7.2.1).** Amendments 12, 13 and 14 had been declared in
DEFN documents and **never written into `DESIGN.md`** — `ORIENTATION.md` §9 pointed cold-start readers at
"§7.2 region derivation with Amendments 12 and 13" that were not there. The subsection is additive; nothing above
it was withdrawn.

**Lessons adopted:** `LESSONS.md` **58** (an immutability guarantee constrains the writer, not the derived view —
read the representation's existing consumers before ruling it out), **64x** (extend a gate by appending so every
earlier prefix hash still reproduces; inserting destroys `first_red_ordinal` comparability), **64y** (a gate must
not bind a witness its own checkpoint declares out of scope — split the identity instead).

Stable accounting unchanged: **44 / 14 / 30**, debt **5**, M3 packages **64**. Exact next remains
**`M3-CP4c-2-CB6`** under AF0–AF4; `M3-CP4c-2-CB7` then implements Amendment 14 under AG1–AG6.
## 2026-08-29 — `M3-CP4c-2-CB6`: AF1 refutes pre-cut sphere cellularity; frozen definition stop triggers

Code + Build turn **stopped before implementation** at its required-first retained-evidence measure. No product,
test, fixture, selector, build-configuration, or semantic source byte changed; no compile, package, Directional
runtime, test, benchmark, discovery, or custom input executed.

AF1 extracted the prescribed-sphere `m3Cp4c2ActualGraphOracle` row already published in R7 result artifact
`9721564203`: `complex=actualEmbeddedGraph`, `V=18`, `E=30`, `F=18`, `c=1`, `chi=6`, `sourceChi=2`,
`excludedBoundaryOrbits=0`, `surfaceCutGraphCallsInsideOracle=0`, while the live producer remained
`error / CellularityNotEstablished`. The standing prediction that the sphere is already cellular pre-cut is
therefore **REFUTED**. This is an independent oracle finding and does not reinterpret the producer's earlier lossy
error translation as a cellularity verdict.

The result activates `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` §8.3: DEFN-R1 proves cut completeness
for trace-free components, explicitly leaves the trace-crossed non-disc case unproved, and requires CP4c-2 to
return to definition if the prescribed sphere proves non-cellular. The sphere has 24 retained traces, so the gap is
now live. CB6 therefore deferred AF0/AF2/AF3/AF4 rather than implementing across a frozen definition stop; AF5 is
owned by the successor definition. This stop does **not** claim that no admissible cut exists.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **64**.
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`; 357/358 remain unrun. CB5
package `9719216316` remains build authority and R7 remains latest semantic runtime.

**Exact next:** `M3-CP4c-2-DEFN-R2`, definition/planning only. Re-open trace-crossed non-cellular cut completeness,
discharge AF5 gate membership, and re-adjudicate AF0/AF2/AF3/AF4 before any implementation resumes.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R7-REV`: R043/R044/ORCH-01 closed; the sphere's "cellularity" failure is a collapsed typed error

Independent review and planning only. No runtime, build, benchmark, or product/test/fixture/selector mutation.
Static analysis was performed against the working tree, verified byte-identical to the packaged semantic source
(`git diff --stat 755485865a HEAD -- tests/ src/ include/` is empty), so every source claim below describes exactly
what R7 executed. Measures issued: **AF0–AF9**. Full record:
`Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md`.

**Closures.**

- **`PR8-R043 / M3-CP4c2-R001` — CLOSED.** Measure AD8's frozen condition (ordinal 305 green in a run reaching the
  full 355/355) is met exactly, with no prefix promotion. The defect is gone at the locus, not masked:
  `proves_cellularity()` now *requires* `SurfaceCutGraphComplexKind::ActualEmbeddedGraph`, so the withdrawn
  whole-source-face proxy cannot re-enter a certificate by construction.
- **`PR8-R044 / M3-CP4c2-R002` — CLOSED.** Ordinal 310 green in the same full run. The fix was re-verified at
  source as a correct application of the `M3-CP3a-DG-CAND-02` template: `candidate_semantic_hash` excludes
  `atlasDigest`, `candidate_hash` retains it for tamper rejection exactly as AD1 required, the consumer at
  `GlobalTopologyPlan.cpp:1630` was converted, and R7-2's two-ring run confirms equal semantic / unequal provenance
  digests at runtime. Stated explicitly: the split is runtime-proved on **one** witness, which is what the frozen
  condition asked for; the torus counterpart is a separate record, not a reason to move a closure condition after
  the evidence arrives.
- **`M3-CP4c2-TB-X2-R7-ORCH-01` — CLOSED** on its frozen condition, a green R7-0 across all six recomputed selector
  derivations. All six hashes were independently re-derived again in review and match.
- Stable totals are **unchanged at 44 / 14 / 30**; closing an event changes its status, never the cumulative count.
  Debt **5**; M3 packages **64**.

**The decisive finding — `M3-CP4c2-TB-X2-CAND-04` re-localized, cellularity framing withdrawn.**

- `SurfaceCutGraph::topology_error` (`src/geometry/SurfaceCutGraph.cpp:50-67`) maps 39
  `GlobalTopologyPlanErrorCode` values onto three `SurfaceCutGraphErrorCode` values; three survive as themselves and
  **36 collapse into `CellularityNotEstablished`**, carrying `sourceFace` through.
- It is the **only** producer of that code on the `make` path that sets a `sourceFace` — `cut_error` (`:44-48`) sets
  only `code`. R7-5 published `errorSourceFace=25-27-28`, so the sphere took the `topology_error` path.
- Its two call sites (`:240`, `:243`) both enter `src/geometry/EmbeddedGraphTopology.cpp`. Across that file's 58
  error constructions, every code that both survives the collapse and carries a `sourceFace` is
  **`RotationSystemInconsistent`** — 44 of 58, and all nine `sourceFace` assignments.
- Neither call site evaluates cellularity; that happens later at `proves_cellularity()` in the cut loop (`:323`) and
  the `:250` orbit guard. **The sphere never reached a cellularity decision.** A2a′ did not change the sphere's
  pre-existing `RotationSystemInconsistent`; inserting it upstream **renamed** it through a `default:` case, and
  eight turns of planning reasoned about cuts and complexes for a mechanism that never ran.
- The standing prediction ("the sphere is already cellular pre-cut") is **not** thereby confirmed — only its
  principal counter-evidence has evaporated. It is settled by the sphere's actual-graph oracle row, which
  **R7-3 already published and the R7 report omitted**; it is in retained result artifact `9721564203`, and AF1
  extracts it with no new runtime.

**Other findings.**

- **`R7-CAND-01` adjudicated** — the torus digest diagnostic builds its atlas from a locally synthesized
  zero-transport field, not the production `torus.rawfield`. That witness has no production counterpart and had
  never been shown constructible; the zero-effort cycle lift is integral on a flat mesh and generically
  non-integral on a curved closed surface. `ASSERT_TRUE(baselineAtlas)` discarded a typed error the process already
  held. A witness-construction defect, not a defect in the CB5 split.
- **New `R7-CAND-03`** — the D2 localization harness compares the actual embedded graph against the **withdrawn**
  source-edge-barrier proxy, through a helper named `cp4c_producer_rederivation` that models a pre-CB4 producer, and
  classifies with labels (`419-`, `437-`, `474-`) that are line numbers in a file 344 lines long.
  `localizationConsistent=false` is false by construction. `RP-01` at the diagnostic layer.
- **New `R7-CAND-04`** — **no `SurfaceCutGraph.*` identity appears in the accepted 355, in 357, or in 358.** Both
  candidate gates would accept a new pipeline stage while requiring none of that stage's own witnesses, and the
  prescribed sphere is in neither gate — the structural reason its failure survived eight turns. Selector 358's sole
  addition binds the mechanical witness, which this checkpoint declares out of scope and which has no atlas; if that
  holds, 358 is a guaranteed red. Never probed.
- The historical frozen CP4c-2 non-gating selector (consolidated in `M3_CP4c_Consolidated_Record.md` §3.3) named one identity and R7 ran four others,
  without recording why.
- Retention check: the deleted predecessor R7-REV record was retired compliantly — AE0–AE9, `LESSONS.md` 22k/22m/22n
  and the review arc are all preserved in the DOC-R1 report, the tracker, the changelog and
  `M3_CP4c_Consolidated_Record.md` §§6.1-6.7.

**Lessons adopted:** `LESSONS.md` **22p** (a diagnostic loop's value is per-witness; a one-row summary withholds
evidence already paid for), **22q** (a synthesized witness needs its own executed precondition; prefer production
authority), **57** (a `default:` in an error-translation switch is a lossy channel, and a bucket that asserts a
semantic verdict is a fabricated finding — carry the originating code), **64v** (a frozen non-gating selector must
be run or its skips justified per identity), **64w** (a new stage needs gated identities of its own, and check what
each candidate gate's added identities *bind*).

**Gate selection deliberately not made.** `selected_r2_branch=NONE`, `selected_gate=NONE`,
`gate_execution_authorized=false`. Exact next: **`M3-CP4c-2-CB6`**, a bounded diagnostic and witness-repair
Code + Build under AF0–AF4 with the AF9 prohibitions; AF1 runs first and requires no build.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R7-EXEC` retry: accepted 355/355 restored; non-gating torus diagnostic stops at baseline atlas

Artifact-only Test + Benchmark execution on unchanged GMP package `9719216316` / semantic source
`755485865a7cf9c485d754f22b82a41ee151824b`. Authoritative run/job `33276039911 / 99162853852` is GREEN at the
workflow level and preserves the frozen distinction between accepted-gating and non-gating evidence. No configure,
compile, relink, repair, generated discovery, source/test/fixture/selector/package mutation, or benchmark occurred.

- R7-0 immutable preflight passed: package/source authority, **28/28** manifest, GMP/GMPXX boundary, modes, and all
  six corrected selector derivations. This is runtime proof of the DOC-R1 selector-transcription correction.
- R7-2 two-ring semantic/provenance diagnostic passed; torus R7-2 selected exactly once and failed non-gating at
  `baselineAtlas == true` before any torus digest comparison. It is recorded as non-stable `R7-CAND-01`; no
  accepted-count debit or root-cause adjudication is taken in EXEC.
- R7-3 independent actual-embedded-graph oracle, R7-4 retained barrier diagnostic, and R7-5 prescribed-sphere
  localization diagnostic all passed. R7-5 finally publishes D2 with `localizedSite=474-global-certificate` and
  `localizationConsistent=false`, reserved for review interpretation.
- R7-1 re-proved the frozen accepted predecessor in **355 fresh processes: 355/355 PASS**. Ordinal 305 (R043 locus)
  and ordinal 310 (R044 locus) are both green in that same full run. EXEC records that their runtime closure
  conditions are mechanically satisfied but leaves stable status/count adjudication to independent R7-REV.
- R7-6 postflight passed; package/source byte+mode inventories are unchanged and every mutation/build flag is false.
- Selector 357, selector 358, cumulative CP4c-2 gate, and benchmarks remain **NOT RUN**;
  `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.
- Result artifact `9721564203` / `sha256:a854e562facfd616f9f61eddf653dc9e5814c3b932661993b2b2861b2bdab8db`;
  log artifact `9721564377` / `sha256:8edd56072491aa4267e3cd0d2c0942b0910a3e5a01f15e6bc21164bd0fbef3ec`;
  raw evidence SHA-256 `933190d3591aa7633fd3ebb6c1a119c1ad7d0b04cc2ca4254a8c325d3c7f1200`.

Stable accounting remains **44 / 14 / 30** pending review, debt **5**, M3 packages **64**. Exact next:
**`M3-CP4c-2-TB-X2-R7-REV`**, independent review/planning only.

## 2026-08-29 — `M3-CP4c-2-DOC-R1`: selector-hash authority corrected; superseded CP4c-2 records consolidated

Documentation-only closeout under R7-REV measures AE0–AE9 plus the user's historical-consolidation instruction.
No Directional runtime, configure, compile, relink, package, product/test/fixture/selector mutation, 357/358 gate,
benchmark, mechanical/C2, or CP4c-3 work occurred. Immutable GMP package `9719216316`, semantic/test source
`755485865a7cf9c485d754f22b82a41ee151824b`, and all selector bytes remain unchanged.

- AE0 independently recomputed the six authorities from committed bytes: 316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`, 346 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`, 353 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, 355 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, 357 `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`, 358 `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`.
- AE1 corrected the same four mistranscribed constants in each of the two current-authority documents (8 occurrences total: four in the CB5 AD0 audit and four in the R7 preflight plan); no selector file was touched.
- AE2 audited **77** occurrences of the six selector-authority values plus the four known fabricated variants across `.agents/Directional/**`. There were **16** fabricated-token occurrences before editing: **8 current-authority occurrences corrected** (four in CB5, four in the R7 plan), **4 historical Plan-values occurrences deliberately retained** in the regression tracker, and **4 historical R7-EXEC mismatch occurrences retired with that superseded evidence file**. No additional unique fabricated selector value was found.
- AE3 was already durable as `LESSONS.md` 22n; it was not duplicated or retroactively expanded in historical prose. AE4's 64-lowercase-hex authoring validation passed for every selector value and every `sha256:` digest literal in the two corrected current plan/report documents. AE5 adds source file + derivation to every R7 preflight selector row.
- AE7's hard-stop/no-self-heal/preflight-integrity behavior is unchanged. AE8 reorders only publication: after green R7-0, non-gating R7-2..R7-5 run first in fresh processes, then the unchanged full accepted 355 gate.
- Six superseded CP4c-2 per-turn records were retired into `M3_CP4c_Consolidated_Record.md` §8.3; stale provenance narratives were removed from `TODO.md` and the handoff. Durable definitions, selectors, closure records, trackers, `ORIENTATION.md`, CB5 build authority, and the current R7 retry plan remain.

Exact next: artifact-only **`M3-CP4c-2-TB-X2-R7-EXEC` retry** on unchanged package `9719216316`. Stable accounting remains **44 / 14 / 30**, debt **5**, M3 packages **64**; `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R7-REV`: four fabricated hashes, one of them 63 characters

Independent review and planning only. No Directional runtime, compile, package, benchmark, or product/test/fixture/selector change. Record: `Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md`. `selected_r2_branch` and `selected_gate` both remain **NONE**.

- **R7-0's stop was correct and is credited as such.** Faced with a preflight mismatch it refused to substitute the observed values for the plan's constants — which would have silently rewritten executable authority mid-run — stopped before the first Directional process, left the immutable package untouched, and ran a post-preflight integrity check even though runtime never started. **AE7 preserves all three behaviours.**
- **All six selector hashes were recomputed from bytes in review** and match the immutable package, R6-EXEC and `ORIENTATION.md` exactly. **The selector bytes never changed and the accepted authority chain is intact.**
- **The defect is fabricated constants in documentation, and the proof is arithmetic:** the R7 plan's expected value for selector 357 is **63 characters**. SHA-256 is 64 hex characters, so a stale digest or a digest of the wrong file would still be 64 — a value of the wrong length can only have been assembled by hand, and nothing in the authoring path checked its length. It travelled from the CB5 closeout report into the R7 plan and was caught a full turn later at byte comparison.
- **Mechanism:** every failing constant shares the **first eight** hex characters and the **trailing** characters with the truth and differs only in the middle — the signature of an abbreviated digest of the form `PREFIX…SUFFIX` expanded back to full length by inventing the interior. The two that passed, 316 and 355, are the two whose full values were readily to hand.
- **Part of the cause is the reviewer's, stated plainly.** `M3-CP4c-2-TB-X2-R6-REV` measure AD0 wrote all six hashes in abbreviated form inside a measures table that reads like a value table. Full values existed elsewhere so the abbreviation did not force the error, but it supplied the template. **Lesson 22n adopted: a cryptographic digest is written in full or replaced by a file reference plus "recompute" — never as `PREFIX…SUFFIX` where a value is expected.**
- **The deeper design point:** a transcribed constant cannot distinguish the two causes of a preflight mismatch — selector drift versus mistranscription — and R7 spent an entire turn establishing it was the latter. Future preflight tables must record the **source file and derivation** (`head -N <file>` or whole file) and derive the constant by computing it at authoring time. **AE4** additionally requires every expected digest to be validated as exactly 64 lowercase hex at authoring; that alone would have caught the malformed value a turn earlier for almost nothing.
- **`M3-CP4c-2-DOC-R1` is AUTHORIZED, documentation-only, under AE0–AE9.** AE0 recompute independently rather than copy — including from the review's own table; AE1 correct exactly the four constants and touch no selector file; **AE2 sweep `.agents/Directional/**` for the same defect and report counts even if zero**, since a silent sweep is not evidence a sweep happened; AE3 record the rule; AE4 format validation; AE5 plans name their derivation.
- **One narrow sequencing change (AE8).** After the correction, R7 retries unchanged in content except that the **non-gating** diagnostics R7-2..R7-5 run **before** the accepted-prefix gate and publish regardless of its outcome. They grant no credit and mutate nothing, so this reorders publication rather than authority. It addresses an eight-turn drought: `CAND-04` has been scheduled and not run in R2, R3, R4, R5, R6 and R7 — every stop individually correct, and every one upstream of the measurement.
- **`ORIENTATION.md` is now DURABLE and must be updated at every REVIEW turn**, at the user's instruction: marked in the document itself, added to the handoff's durable policy as item 12, and to the mandatory end-of-turn checklist as item 7. It stays substance-only. This turn's evidence is the argument for the rule — R7-EXEC used it as corroborating hash authority and was right to.
- `PR8-R043` unchanged (RESOLVED AT LOCUS, closure pending a full 355/355); **`PR8-R044`'s CB5 correction is compiled but runtime-unproved**. Stable accounting **44 / 14 / 30**, debt **5**, M3 packages **64**.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R7-EXEC`: immutable preflight hard-stops before runtime on four plan hash transcriptions

Artifact-only EXEC reached **R7-0 only**. Package `9719216316` remains internally valid and unchanged: outer
`acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`, source
`755485865a7cf9c485d754f22b82a41ee151824b`, source archive
`78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`, manifest **28/28 PASS**, GMP/GMPXX
proven, and six runtime binaries executable. The frozen R7 plan's expected exact digests for 346, 353, 357, and
358 disagree with the unchanged selector bytes; 316 and 355 match. R7 therefore honored its hard-stop rule and
executed **no Directional process**. R7-1 through R7-5, 357/358 execution, cumulative gate, and benchmarks are NOT
RUN. Raw archive `Directional__M3-CP4c-2-TB-X2-R7-EXEC__raw-evidence.tar.gz` hashes to
`b83172acc3519fc6fe3472e5844a48e0bfd938fe9e6a5d68d14e515371454cc7`.

The immutable values match `ORIENTATION.md` and R6-EXEC exact authority; the wrong full strings were introduced in
CB5 closeout report/plan text, not by selector mutation. Tracked as non-stable orchestration defect
`M3-CP4c2-TB-X2-R7-ORCH-01`; stable accounting remains **44 / 14 / 30**, debt **5**, M3 packages **64**. R043/R044
receive no new runtime evidence. Exact next: independent **`M3-CP4c-2-TB-X2-R7-REV`**; no runtime or corrective
implementation is authorized in review.

## 2026-08-29 — sixth CP4c historical consolidation

Documentation-only consolidation under explicit user authorization. No product, test, fixture, selector, build,
package, or runtime semantics changed. `M3_CP4c_Consolidated_Record.md` was rewritten as the concise durable
history for the CP4c family and updated through R6 review. Thirty-five superseded CP4c per-turn plans, reports,
execution records, and reviews were retired after their durable facts were reconciled into the consolidated record,
this changelog, the regression tracker, frozen definitions, and closure records. `TODO.md` and the handoff were
trimmed back to forward-looking/current authority only. Normative frozen definitions, frozen selectors, closure
records, the current CB4 build authority, current R6 EXEC evidence, and current R6 review remain retained.
Historical filenames in older changelog entries are provenance tied to their original commits/runs and may no
longer exist at HEAD; see `M3_CP4c_Consolidated_Record.md` §8 for the retirement manifest.


## 2026-08-29 — `M3-CP4c-2-TB-X2-R6-REV`: one regression resolved at its locus, one confirmed with its fix already on file

Independent review and planning only. No Directional runtime, compile, package, benchmark, or product/test/fixture/selector change. Records: `Architecture_M3_CP4c2_TB_X2_R6_Independent_Review_Record.md` and the new `ORIENTATION.md`. `selected_r2_branch` and `selected_gate` both remain **NONE**.

- **`PR8-R043 / M3-CP4c2-R001` is RESOLVED AT ITS LOCUS.** Accepted ordinal 305 passes on CB4 package `9714226920`: DEFN-R1's actual-embedded-graph complex did what it was defined to do, and CB4 delivered `src/geometry/EmbeddedGraphTopology.{h,cpp}` as the single shared authority AC1 required, satisfying the structural half of `LESSONS.md` 22e. **Closure is deliberately deferred to a full 355/355** — R6 executed 309 of 355 accepted identities, and recording closure on a 309-ordinal prefix would be exactly the partial-evidence promotion this project has already corrected twice.
- **`PR8-R044 / M3-CP4c2-R002` is confirmed and independently re-localized**, and the EXEC classification is correct in every particular. `GlobalTopologyPlan.cpp:1511-1519` consumes `candidate.cutGraphDigest`; `SurfaceCutGraph.cpp:263-265` builds that digest from gauge-dependent `atlasDigest`; `canonical_candidate` stores `network.atlas_digest()` there. **A2b states the rule in a comment, obeys it on the line the comment guards, and is defeated two lines earlier** — the atlas hash enters through the back door.
- **The error is a domain conflation, not a hashing bug.** `candidate_hash` is a **provenance** hash and is correct as such: `make_from_candidate` needs `atlasDigest` to reject a candidate built against a foreign or tampered atlas. The defect is a second consumer reading a provenance hash as **semantic** identity — one digest serving two incompatible domains.
- **The corrective template already exists in this repository, and this is the third occurrence of the pattern.** `PR8-R040 / M3-CP2b-R001` stabilized it; `M3-CP3a-DG-CAND-02` fixed it for `FieldAlignedCurveNetwork` by making semantic identity consume the gauge-invariant digest while retaining the full atlas hash separately for binding and provenance. **AD1 gives `SurfaceCutGraph` the same split — add a `semantic_digest()`, leave `candidate_hash` unchanged. Removing `atlasDigest` from it is prohibited**, since that would trade a semantic defect for weakened tamper rejection one level down.
- **A hazard the EXEC did not reach, and it survives the obvious fix.** `SurfaceCutGraph.cpp:258` keys each certificate face by the **raw orbit index** into `faceWalk.orbits` — an enumeration artifact, not a face identity — and `candidate_hash` consumes it. Ordinal 310 asserts invariance to enumeration order **and** branch relabeling, so removing `atlasDigest` alone leaves a latent instance of the same pattern that may simply not fire today. **AD3** requires it settled by proof or by a content-derived key; "it passes now" is not an answer.
- **`M3-CP4c2-TB-X2-R5-ORCH-01` is RESOLVED.** R6's postflight ran unconditionally after the semantic red and passed with exact package and source byte-and-mode equality. That path must be preserved.
- **`M3-CP4c2-TB-X2-CAND-04` remains unlocalized for the seventh consecutive turn.** D2 has been scheduled and correctly skipped in R2, R3, R4, R5 and R6, each time because an upstream gate failed first. The review raises, without deciding, whether the non-gating sphere diagnostic should be sequenced independently of the accepted-prefix outcome.
- **`M3-CP4c-2-CB5` is AUTHORIZED under measures AD0–AD9**, with six falsifiable predictions. AD8 fixes both closure conditions: `PR8-R043` closes only at 355/355 with ordinal 305 green, and `PR8-R044` only with ordinal 310 green in the same run.
- **New durable document: `ORIENTATION.md`** — a cold-start context pack covering the architecture, pipeline stages, current position and selector authority, the three witnesses, the CP4c-2 theorem, the normative complex and its two conventions, open problems in priority order, the four recurring defect families, and source pointers. It deliberately contains **no procedural information**, so it complements rather than duplicates the handoff and the policy documents.
- Stable accounting **44 / 14 / 30**, produced-witness debt **5**, M3 packages **63**.

## 2026-08-29 — `M3-CP4c-2-CB4`: actual embedded-graph authority compiles green

Code + Build only; **no Directional runtime, test, or benchmark executed**.

- Source `cebc12082c6dbe4830095df08169797b7dab0c5c` implements DEFN-R1 AC0–AC9: one shared actual-embedded-graph
  owner, actual-complex cellularity terms, disconnected/boundary conventions, exact trace-crossing cut
  admissibility, typed `NoAdmissibleCutForNonDiscComponent`, all consumers converted together, and a non-gating
  independent actual-complex oracle. Retained `sourceEdgeBarrier` evidence is diagnostic-only.
- Implementation WIP patch SHA-256 `e0621b9c9a801c0af322e5f541082f457952f415a407bc440c63e032197c4d58`
  was emitted before remote orchestration and applied through the durable Drive workflow; selectors did not change.
- Required ordering is re-proved on the same source: changed-owner prepackage `33250503297 / 99095246849` PASS,
  then fresh eight-target GMP package `33250547011 / 99095357374` PASS.
- Authoritative package `9714226920` /
  `sha256:931d422611a8144faf4efe3f9307b3a1a90bbce4cab6d8873eb95b32ca1b9f83`; log `9714227128` /
  `sha256:95c8272db296dc0f74e4d33b389cbf51305bd042590420974111d9f63afe31da`; source archive
  `3bb299730077cd7bbd46acd5e10f6f7fec1d0e131bc882710a5676163e36b021`. Manifest 28/28, source clean,
  all eight targets present, GMP/GMPXX link evidence present, `runtimeExecution=false`.
- Earlier full-package run `33246515627` is retained only as ordering-invalid mechanics evidence, not R6 authority.
- Stable accounting remains **43 / 14 / 29**, debt **5**, authoritative M3 packages **63**. Accepted runtime
  authority remains CP4c-1 355/355; CP4c-2 is not accepted.
- Exact next: artifact-only `M3-CP4c-2-TB-X2-R6-EXEC` on package `9714226920`, then hard stop at independent
  R6-REV. 357/358, cumulative gate, mechanical/C2, and CP4c-3 remain blocked.


> **Provenance note — CP4c document names.** Entries preceding the **2026-08-29 sixth consolidation** may cite CP4c
> per-turn plans, reports and independent reviews by their original filenames. Those documents were
> retired into `M3_CP4c_Consolidated_Record.md` on 2026-08-26 and 2026-08-27 under explicit user
> authorization; the filenames below are retained as **historical provenance tied to the cited runs and
> commits**, per `CLEAN_UP_POLICY.md`. Every evidence identity, amendment, finding, reviewer error and
> disposition they carried is preserved in that record — §2–§3 for evidence, §3b for the review arc,
> §3c for where each class of information now lives, and §5 for the exact retirement inventory.


### 2026-08-29 — `M3-CP4c-2-DEFN-R1`: the actual embedded graph, and a withdrawn reviewer ruling

Definition-only. No Directional runtime, build, compile, package, benchmark, or product/test/fixture/selector change. Record: `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md`. `selected_r2_branch` and `selected_gate` both remain **NONE**.

- **Amendment 13 freezes the normative complex as the actual embedded graph** of `FieldAlignedCurveNetwork ∪ cutEdges` — vertices are network nodes plus cut-created nodes, edges are network arcs plus cut arcs, faces are the **dart orbits** under the node rotation system. DEFN §5.4's whole-source-face construction guidance is **withdrawn** as cellularity authority and survives only as a cut-proposal heuristic and diagnostic provenance. §§5.1–5.3, Amendment 12, and §3's torus theorem all remain binding.
- **Nothing new is invented.** `GlobalTopologyArc`, `GlobalTopologyOrientedArc`, `GlobalTopologyNodeRotation` and `walk_graph_faces(arcs, rotations)` already exist in A2b and already compute this complex. The corrective is a **lift into one shared pre-region authority**, consumed by both A2a′ and A2b. **A second implementation is prohibited** — `LESSONS.md` 22e — and a second implementation is precisely how this checkpoint arrived here.
- **A reviewer error is owned precisely.** The R2 review declared the source-edge barrier complex normative on three grounds that were each individually true and collectively wrong: the traversal it cited (`GlobalTopologyPlan.cpp:1694-1704`) is a **seeding fallback**, not A2b's region authority; the frozen commitment to source-edge *cuts* says nothing about the certification *complex*; and `V − E + F = χ` holding inside the proxy is exactly what a coherent computation over the wrong object looks like. `PR8-R042 / M3-CP4b-R001` had already adjudicated the same representation question on the same two-ring witness, and lessons **22d** and **22e** recorded the answer. Reading `LESSONS.md` in full is mandatory start-of-turn step 5: **the control existed and was not applied.**
- **Verified independently rather than accepted:** actual embedded graph `9 − 11 + 3 = 1 = χ`; source-edge-barrier proxy `10 − 11 + 2 = 1 = χ`; the producer mixes them as `9 − 11 + 2 = 0 ≠ 1`. The actual `F = 3` is corroborated by retained CP4ab evidence — `walk.orbits.size() = 4` with exactly one exterior, `drafts.size() = 3` — so it is a measured product quantity, not a reconstruction.
- **Two conventions must be derived, not guessed**, and they are where a plausible guess yields a wrong certificate: the **exterior-orbit exclusion** on surfaces with boundary, and the **disconnected-graph correction term** — the torus's 48 arcs over 48 degree-2 nodes form **four components**, so unqualified `V − E + F = χ` is false there before any cut is considered, and mistaking that for non-cellularity would be right for the wrong reason.
- **A new frozen constraint:** a cut is a source edge promoted to a graph arc, so **a source edge crossed by a trace at an interior point is not an admissible cut** — promoting it would subdivide an immutable trace, which Amendment 12 forbids.
- **Completeness is split honestly rather than papered over.** Provable for trace-free non-disc components, which covers the torus entirely since it has zero traces; **not proved** for trace-crossed ones, where a typed `NoAdmissibleCutForNonDiscComponent` stop is required and hitting it is a **return to definition**, never a widened admissibility or a partial cut set.
- **Option A is frozen for the accepted regression** `PR8-R043 / M3-CP4c2-R001`: fix the certificate, because ordinal 305 is correctly detecting a real defect. Decoupling A2a′ from the accepted path is retained only as a contingency with one stated trigger.
- **AA1 must not be reverted.** R5 §9 shows the regression predates it; AA8's "reverts AA1" clause was overbroad and is withdrawn — **prefix re-proof is a detection boundary, not a blame boundary.**
- Lessons **22k** and **22m** added; 22-series labels de-duplicated after a collision.
- Stable accounting **43 / 14 / 29**, debt **5**, M3 packages **62**.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R5-REV`: R5 accepted red is stable RP-01 regression; whole-face cellularity authority withdrawn

**Independent review/planning only. No Directional runtime, compile, package, benchmark, product/test/fixture/selector mutation, or gate execution.** Review record: `Architecture_M3_CP4c2_TB_X2_R5_Independent_Review_Record.md`.

- R5 run/job `33232106030 / 99046593525` is admissible for semantic diagnosis: immutable package/source/GMP/six-selector preflight passed, ordinals 1-304 passed, and accepted ordinal 305 selected once and failed first at `SurfaceCutGraph::make(...)=CellularityNotEstablished`. The missing postflight remains a real orchestration limitation and is not inferred; no AA2/D1/D2/357/358 result is attributed to R5.
- The accepted two-ring provides the root-cause proof. CP4ab's retained fragment/orbit evidence gives **3 actual interior embedded-graph faces**; current network authority has **V=9, E=11**, so `9-11+3=1=source χ`. R4's independent `sourceEdgeBarrier` proxy is separately self-consistent at **V=10, E=11, F=2**. `SurfaceCutGraph` computes network V/E but uses the proxy's whole-source-face component count as F, producing **`9-11+2=0`** and rejecting at the final global certificate.
- This is not repairable by swapping in proxy V/E. Trace carrier source edges are provenance/support, not the actual embedded trace arcs; the proxy per-component disc certificates also describe a different complement. CP4ab had already proven whole-source-face ownership insufficient and closed `PR8-R042` by moving to fragments/orbits. CP4c-2's DEFN §5.4 step 1 reintroduced that representation.
- Stable `PR8-R043 / M3-CP4c2-R001` is opened **ACTIVE / PRODUCT / AUTHORITY_DOMAIN_CONFLATION / RP-01**. Stable accounting advances **43 events / 14 categories / 29 recurrences**; debt remains **5**, M3 packages **62**.
- R2's prior claim that `sourceEdgeBarrier` is the normative complex, with carrier-edge coarsening only a quality concern, is **withdrawn**. `R2-CAND-02` remains ACTIVE as **TEST-AUTHORITY / WRONG SEMANTIC COMPLEX** until an independent oracle measures the actual embedded graph/fragment complement through a different mechanism.
- R4 AA2 is independently discharged: the two prescribed-sphere lines in artifact `9707662462` are each **468 bytes**, each SHA-256 `84f9ca015ab63093086981cbd29256526159329c64537dfb52fba9e89d9fd078`, and byte-identical. AA5 runtime publication remains pending because R5 never reached D1. AA1 sphere-snapshot retention also remains runtime pending, but AA1 is **not causal**: `SurfaceCutGraph.cpp` predates AA1 unchanged, and ordinal 305 fails before pipeline snapshot publication is relevant.
- New non-stable `R5-ORCH-01` records the `set -e` leakage that suppressed postflight. The next runtime harness must guarantee finalization/postflight even on semantic red.
- `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` §5.4.1 now preserves a narrow R5 correction: §§5.1-5.3 remain binding, while whole-source-face/source-edge-barrier complement construction is withdrawn as cellularity authority pending redefinition.
- **Exact next:** `M3-CP4c-2-DEFN-R1`, definition/replanning only, measures **AB0-AB9**. It must freeze one pre-region exact actual embedded-graph complement representation, candidate-cut update/certification, termination/completeness argument, and independent same-semantic-complex oracle before any later CB. `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.

## 2026-08-29 — `M3-CP4c-2-CB3-DIAG`: snapshot retention and publication hygiene compile green

Code + Build only. **No Directional runtime, test, benchmark, selector gate, or acceptance attempt executed.** Semantic/test source `76d757aab0ce18df09ce2823302d2dc224965187` implements only R4-review measures AA1/AA5 plus the required lesson.

- `RemeshPipeline.cpp` now retains source-topology, atlas, network, cut-graph, and global-plan snapshots immediately after each product succeeds. The old all-at-end snapshot block is removed; fail calls/codes/stages, control flow, and product construction order are unchanged. This is the only `src/` edit.
- D1 publication now emits one full Y1 record per witness, counts publications, emits `m3Cp4c2PublicationCounts`, and limits the final assertion message to witness names/statuses so it cannot duplicate a complete Y1 record.
- `LESSONS.md` records the R4 review lesson that a premise-discharging result must be reported as a finding even if another contract makes the turn semantic red.
- All six frozen selector hashes recompute unchanged: 316 `601ce2b6…0193c`, 346 `20d3b0b1…3e46a`, 353 `51ff96d7…ac6a5`, 355 `e9d88f11…afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…4fbe62`.
- Compile run `33230423139` is GREEN under GMP/GMPXX: changed-owner result `9708313428`, then all eight standard targets in immutable package `9708324052` / `48e01cea66817525766566a1145b92beb22dbb847e4211629fe4c3373d23ff7a`; compile log `9708324292` / `d200b4210a1adc204fd2fd90df07727c73c8c35c65110d99233ea44d9bd5d0fd`; source archive `f1614161…a0a9a2d`; `runtimeExecution=false`; manifest/source-status checks PASS.
- Runtime candidates remain unadjudicated. Stable accounting stays **42 / 14 / 28**, debt **5**; M3 packages advance to **62**. `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.
- Exact next: artifact-only `M3-CP4c-2-TB-X2-R5-EXEC` under `Architecture_M3_CP4c2_TB_X2_R5_Artifact_Only_Test_Benchmark_Plan.md`; accepted prefixes 316/346/353/355 must pass first. After EXEC, independent `R5-REV` is the stop boundary.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R4-REV`: the torus derives a plan, and the sphere's invisibility is a product defect

Independent review and planning only. No Directional runtime, compile, package, benchmark, or product/test/fixture/selector change. Record: `Architecture_M3_CP4c2_TB_X2_R4_Independent_Review_Record.md`. `selected_r2_branch` and `selected_gate` both remain **NONE**.

- **The evidence contained an unremarked success that reframes the checkpoint.** The torus published `pipelineCutGraphAvailable=true` **and `pipelinePlanAvailable=true`**. `products.globalTopologyPlan` is assigned at exactly one site — `RemeshPipeline.cpp:6634`, reachable only after `GlobalTopologyPlan::make` returns success — and the file's two other snapshot sites cannot produce a plan snapshot. **The torus now derives a topology plan; `UncutFaceComponentOrbitSeedNotUnique`, the failure that defined CP4c-2, is gone.** D1 independently confirms the other half: torus network-only cellularity is **false**, exactly as the frozen theorem requires. **The DEFN's cut graph is measured working end to end on its own witness.** Recorded as `M3-CP4c2-TB-X2-R4-CAND-03`; its residual `terminalFailureStage=tracing` is downstream of A2b and out of scope.
- **The prescribed sphere's "all snapshots unavailable" is a product observability defect, fully localized — not a test defect and not a missing product.** The record is self-contradictory on its face: `terminalFailureStage=surface-cut-graph/CellularityNotEstablished` with atlas and network both `false`, although failing *at* A2a′ requires dereferencing all three products at `RemeshPipeline.cpp:6602-6605`. Mechanism: lines 6576-6612 are a chain of early `return fail_surface_cells(...)` and lines 6626-6634 assign all five snapshots **after every one of them**, so any pre-A2b failure discards products that were built successfully and are alive in local variables. The torus reaches 6626 and retains everything; the sphere fails at 6607 and retains nothing.
- **A reviewer error is owned.** Measure **Z11** — consume `productSnapshots`, stop reconstructing the pipeline — was right in principle and took the torus from `field-transport-atlas-unavailable` to a clean 48/48 in one turn, but it assumed snapshots survive a failure. They do not, and the product never promised they would. Z11 is unimplementable as written for the one witness whose pipeline fails at A2a′ — the prescribed sphere, the decision witness for Branch A. Same error class this arc keeps producing: **an instruction written from what an authority is supposed to expose rather than from what it exposes on the failing path.**
- **`M3-CP4c-2-CB3-DIAG` is AUTHORIZED under measures AA0–AA9**, and it is the first turn in this arc to touch `src/`: **AA1** publishes each snapshot immediately after its product is built, changing no `fail_surface_cells` call, failure code, stage string, control flow, or build ordering. **AA8 prices it** — the successor TB must re-prove accepted prefixes **316/346/353/355**, and a regression in any of them is a stop that reverts AA1.
- **The `STOP_EVIDENCE_CONFLICT` was procedurally correct, and the evidence is nonetheless admissible.** The duplicate sphere record is byte-identical, so exactly one *distinct* record exists per witness and nothing is indeterminate. The contract is **amended, not waived** — exactly one *distinct* record per witness — and the ruling is **conditional on AA2** confirming byte-identity from `d1-records.txt`; if the lines differ in any byte, the stop stands and the R4 evidence is void. The distinction from the CP4c-1 C5 case is stated explicitly: there the rule was wrong in substance, here only its response to a benign violation is disproportionate.
- **Closed:** `R2-CAND-01` (torus now `pipeline-authoritative` at 48/48 **from authority**, not an encoded constant), `R3-CAND-01` (reconstruction removed for loaded witnesses), `R3-CAND-02` (the sphere failed and the torus and two-ring were still published — Z13 works). **`R2-CAND-02` remains ACTIVE**: torus and two-ring are self-consistent under `complex=sourceEdgeBarrier` and R2's exact-by-4 contradiction did not recur, but the sphere has never been measured. **`CAND-04` remains UNLOCALIZED for a fifth consecutive turn; AA4 exists to end that.**
- A lesson is recorded for the successor to add to `LESSONS.md` §1: **a result that discharges a checkpoint's premise must be reported as a finding, not left as a field value.** The torus's plan availability — the most consequential fact this arc has produced — appeared only as one boolean in a list, under a verdict of "semantic red".
- Stable accounting unchanged: **42 / 14 / 28**, debt **5**, M3 packages **61**.

## 2026-08-29 — `M3-CP4c-2-CB2-DIAG-R2`: published-product diagnostics compile green; all-witness publication restored

Code + Build only. **No Directional runtime, test, or benchmark executed.** The R3 independent review authorized a bounded test/diagnostic correction under Z10-Z19; semantic/test source `5ad711e5d4ced95f38e103b993139a6307ba2cee` changes only `tests/FieldAlignedCurveNetworkTests.cpp`.

- Loaded torus/sphere D1 witnesses now consume the pipeline's retained `productSnapshots` rather than rebuilding cross field, feature map, rails, atlas, and network. A relaxed pipeline-products fixture tolerates absent cut graph/global plan; the strict accepted production fixture is not weakened. Synthetic two-ring remains explicitly constructed/AtlasDerived.
- D1 now emits one success/failure record for every witness and asserts once after the loop. `witnessConstruction`, construction success, pipeline atlas/network/cut-graph/plan availability, terminal code/stage, and typed atlas/network errors are preserved. The former `cp4c_build_rail_authority` reconstruction helper is removed. Z2/Z3/Z4/Z5/Z7 remain unchanged.
- Static closeout inspection found a material Z12 risk: production currently copies atlas/network into `productSnapshots` only after cut graph and global plan both succeed. Because the torus is known to stop at `SurfaceCutGraph`, R4 may observe absent atlas/network snapshots despite their earlier successful construction. That is a **review stop**, not a 48/48 mismatch or product-fix authorization.
- Changed-owner precompile run `33226421754` passed. Final authoritative GMP compile run/job `33226609913 / 99031482464` passed on exact semantic source `5ad711e5d4ced95f38e103b993139a6307ba2cee`. Immutable package `9707091209` / `sha256:e6852141847a23b77245887f66b11d411d7cffc414ae91c1a829eb93c8712f63`; compile log `9707091377` / `sha256:0188b2926df2d77b5885a6560ba358f325d709d3b57f326b3a2abf5473bfe3b2`; source archive `9a9dbfb5c6aede1618d41323109cb336f978f75434bef216472557121df2fb11`. All eight required targets compile/link with gmpxx/gmp, manifest and source-status checks pass, and `runtimeExecution=false`.
- No runtime candidate is closed by compilation. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**; M3 packages advance to **61**. `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.
- Exact next: artifact-only `M3-CP4c-2-TB-X2-R4-EXEC` on package `9707091209`, followed by evidence-only R4-REV. R4 must publish all three D1 witness records before any control decision; absent torus atlas/network snapshots trigger Z12 STOP before D2. Plan: `Architecture_M3_CP4c2_TB_X2_R4_Artifact_Only_Test_Benchmark_Plan.md`.


## 2026-08-28 — `M3-CP4c-2-TB-X2-R3-REV`: a third idiom for one job, and one witness that silenced the rest

Independent review and planning only. No Directional runtime, compile, package, benchmark, or product/test/fixture/selector change. Record: `Architecture_M3_CP4c2_TB_X2_R3_Independent_Review_Record.md`. `selected_r2_branch` and `selected_gate` both remain **NONE**.

- **The R3 stop is upheld and `M3-CP4c2-TB-X2-R3-CAND-01` is LOCALIZED** as test-side with high confidence, rather than left unlocalized. `cp4c_build_rail_authority` under `PipelineAuthoritative` diverges from production in two demonstrable ways: **the cross field** — it computes `finalize_surface_cell_raw_cross_field(mesh, raw)` while production and the working observer use the pipeline's published `products.crossField` — and **the hard-feature edge set** — it recomputes one from a locally built feature map while the working observer passes `tracingOptions.hardFeatureEdges`. **The torus is the one witness whose rails originate in the feature map**, so it is the one witness where that set is non-empty and the divergence can bite. Two further divergences (processed `meshWhole`, and `build_source_topology_regions` with face components/sheets populated) are recorded as plausible and unmeasured so the correction does not fix two and trip over the others.
- **Why test-side:** production reaches A2a on the torus — that is the origin of the frozen `48/48` — so its atlas construction succeeds, and a reconstruction that fails where the original succeeds is a reconstruction defect. **Measure Z12 requires this confirmed by publication, not assumed**; if the pipeline's own torus atlas is also unavailable the classification flips to a product finding and the frozen theorem is re-adjudicated.
- **The structural cause is a third idiom for one job.** The test file now builds the same witness three ways: `cp4c_production_fixture` consumes `products.*` and is faithful; `observe_cp4c_witness` rebuilds but from pipeline inputs and works on the torus; `cp4c_network_only_fixture` rebuilds everything locally and fails. Each new idiom has introduced a defect — its first version used `rails_from_atlas` (R2 CAND-01), its second diverges on field and feature map. **This is the fourth incident in one authority-divergence family.** Z4 fixed which authority is *named*; **Z11** fixes how it is *obtained*: consume `productSnapshots` and stop reconstructing the pipeline. A critical detail is recorded with it — `cp4c_production_fixture` also demands `surfaceCutGraph` and `globalTopologyPlan` and throws without them, and the torus has neither, so a relaxed variant is required and the strict one may not be weakened.
- **The defect that cost R3 its evidence, recorded as `M3-CP4c2-TB-X2-R3-CAND-02`.** The D1 identity calls `ASSERT_TRUE` **inside** the witness loop, and the torus is element 0 — so the identity ended after 14 ms with **zero** publications. The prescribed sphere, the decision witness for Branch A and therefore for the 357/358 selector, was never measured despite nothing being known to be wrong with it. **Third appearance of one anti-pattern:** X2 gated every publication behind `SurfaceCutGraph::make`; `CellularityNotEstablished` collapsed three mechanisms behind one code with no locus; now one witness's precondition failure suppresses all others. **Z13** requires one record per witness including a typed failure record, with a single assert after the loop; **Z17** makes per-witness publication unconditional.
- **A typed error was flattened where the type was the evidence.** `cp4c_build_rail_authority` discards `atlas.error().code` in favour of the bare string `field-transport-atlas-unavailable`, although `append_atlas_error(...)` and `append_cp4c_atlas_failure_diagnosis(...)` already exist in the same file. Same class as `CellularityNotEstablished`. **Z14.**
- **CB2-DIAG-R1's work is affirmed and carried forward unchanged (Z16):** Z2's named complex, Z3's self-consistency assertion, Z4's explicit rail-authority argument with no default, Z5's no-encoded-answers rule and Z7's two-ring re-derivation were all implemented correctly and must not be re-litigated.
- R3 establishes nothing about cellularity, the producer, or A2b; it does not touch the frozen `48/48` theorem; and `M3-CP4c2-TB-X2-CAND-04` remains **ACTIVE / UNLOCALIZED** because **D2 has still never executed on any package**.
- `M3-CP4c-2-CB2-DIAG-R2` is **AUTHORIZED** under measures **Z10–Z19**, with six falsifiable predictions. Stable accounting unchanged: **42 / 14 / 28**, debt **5**, M3 packages **60**.

## 2026-08-28 — `M3-CP4c-2-CB2-DIAG-R1`: one Euler complex, explicit rail authority, Z6 torus-first order compile green

Code + Build only. **No Directional runtime, test, or benchmark executed.** The independent R2 review authorized a bounded test/diagnostic correction under Z0-Z9; final semantic/test source `c552a5a4a318063cde2564c40773ec7edaf064f6` changes only `tests/FieldAlignedCurveNetworkTests.cpp`.

- D1 now declares rail authority explicitly: torus and prescribed sphere use production `pipeline-authoritative` rails; constructed two-ring uses `atlas-derived` rails. One no-default authority path is published as `railAuthority=` with `mandatoryRailCount=`.
- D1 now counts one named `sourceEdgeBarrier` complex: `E=|B|`, `V=` unique source vertices incident to `B`, `F=` source-face components after removing barrier-edge adjacency. It publishes definitions plus mandatory/incoming/outgoing carrier provenance.
- Mandatory Z3 self-consistency is fail-closed: each witness publishes/asserts `oracleSelfConsistent`, requiring all-discs iff `barrierV-barrierE+barrierF == sourceChi`.
- Z5 is preserved: no 48/48, sphere outcome, branch result, or witness-name expected-value table is encoded.
- Static closeout review caught one Z6 ordering defect in the first compile-valid R1 revision: sphere still preceded torus. A surgical test-only patch reordered D1 to **torus -> prescribed sphere -> two-ring**. Apply run/job `33220234369 / 99012579536` passed; result/log artifacts `9704883058 / 9704883330` with digests `81854c89ba1c037af380a14b8db91c4d32ff6b752b1ac6491d1eb7b6811ee3db / af74e95c9e0c97045b014d57a62ba6678bcd991414d5db542fdde203e037c12a`. The transient Drive staging file was retired after push.
- Final authoritative compile run/job `33220315294 / 99012815358` is **PASS** on `c552a5a4a318063cde2564c40773ec7edaf064f6`. Immutable package `9704935112` / `sha256:dcb96ce4e37b2bc58ef69f2146723624575c32c090429ba00e6612b07938133f`; compile log `9704935373` / `sha256:1fc2250c00dd57e8cbd6385bde11857bc92126dfddfdf969ba188a67709651c0`; packaged source archive `e533669daa7ac0219bc6ca6bd7d72db2901af32937848c3f37f02b772345ae02`. All eight standard targets compiled, package manifest verified, source-status snapshots empty, both gmpxx/gmp linked, and `runtimeExecution=false`.
- No runtime candidate is closed by this build. CAND-01 and CAND-02 remain active until corrected D1 runtime satisfies their closure conditions; CAND-04 remains active/unlocalized until authorized D2 evidence. Stable accounting remains **42 / 14 / 28**, debt **5**; M3 packages advance to **60**.
- Exact next: artifact-only `M3-CP4c-2-TB-X2-R3-EXEC` on package `9704935112` under `Architecture_M3_CP4c2_TB_X2_R3_Artifact_Only_Test_Benchmark_Plan.md`, followed by evidence-only `TB-X2-R3-REV`. D1 must pass torus 48/48 first and Z3 on all three before D2 may run. Selector 355/357/358 and cumulative gate remain forbidden.

## 2026-08-28 — `M3-CP4c-2-TB-X2-R2-REVIEW-PLAN`: the oracle inherited the error it was built to detect

Independent review and planning only. No Directional runtime, compile, package, benchmark, or product/test/fixture/selector change. Record: `Architecture_M3_CP4c2_TB_X2_R2_Independent_Review_Record.md`. `selected_r2_branch` and `selected_gate` both remain **NONE**.

- **The R2 control stop is upheld and its Finding 1 confirmed.** `cp4c_network_only_fixture` builds rails with `rails_from_atlas`, while the frozen `48/48` torus authority comes from `AdaptiveFeatureMapBuilder::build` → `build_authoritative_surface_cell_rails`. D1 answered a different question correctly; the theorem is untouched because D1 never tested it. **Why it stayed invisible:** on the closed sphere and the two-ring both rail authorities agree — which is why the sphere's 24 traces / 56 events match production — so the substitution is detectable only on the one witness whose rails originate in the feature map.
- **Adjudicated the second defect R2 declined to judge, and it is the one that matters most.** D1's prescribed-sphere publication is **internally self-contradictory, by exactly 4**: it reports all 18 complement components as discs *and* `18 − 30 + 18 = 6` against source `χ = 2`. If every component is a disc the embedding is cellular by definition and Euler is an identity, requiring `E − V = F − χ = 16`; the publication reports 12. At least one of the disc verdicts, the counts, or the face count is false. **This blocks Y5 independently of the torus control** and bears directly on Branch A. New record `M3-CP4c2-TB-X2-R2-CAND-02`.
- **The oracle inherited the very error it was built to detect.** The X2 plan required independence from `SurfaceCutGraph`, which D1 satisfied — it never calls the producer — but not independence from the **counting convention**, which is the actual suspect. `F` counts source-face components separated by whole barrier edges while `V` and `E` count the network's abstract graph, whose arcs cross face interiors. Two complexes, so Euler's identity does not hold between them; and because barriers cut along whole edges the partition over-cuts, with over-cutting a disc yielding two discs — which is why the contradiction surfaces as a surplus rather than a failed disc test.
- **The normative complex is settled: the source-mesh barrier complex** — `E = |B|`, `V =` source vertices incident to `B`, `F =` components of source faces after removing `B`. It is what A2b consumes at `GlobalTopologyPlan.cpp:1694-1704`; the frozen DEFN §5.2 already committed to source-edge-only cuts; and in it `V − E + F = χ` is a genuine identity rather than a coincidence.
- **Third recurrence of the rail-authority divergence**, after the CP4c-0b DG review and CB2's T1/T3. Measure **Z4** fixes it structurally — one named rail accessor with an explicit authority argument and **no default**, plus `railAuthority=` on every diagnostic record — instead of repairing one call site.
- **The two-ring's passing result is uninformative, not corroborating.** Under a defective convention an agreeing result is a coincidence, and the two-ring has 3 traces against the sphere's 24 — where the coarsening effect would be smallest. **Z7** requires it re-derived rather than carried forward.
- **`CB2-DIAG-R1` is AUTHORIZED with amendments** under measures **Z0–Z9**, item by item: the report's proposal item 3 is the load-bearing one and was under-specified, and item 4 is right for a reason the report did not give — the two-ring is a *constructed* witness whose atlas-derived rails are legitimate, so the rule is "each witness declares its authority", not "leave the two-ring alone".
- **Z3 is the single most valuable line in the correction:** a mandatory per-witness assertion that *all components are discs* iff `V − E + F == χ`, failing closed. It would have caught this automatically rather than leaving it to a reader.
- A design concern is recorded and explicitly deferred: cutting along whole carrier edges is coarser than the traces themselves, so A2b's regions are coarser than field-aligned regions ideally would be. That is a quad-quality question for a later checkpoint; it does not affect CP4c-2's correctness obligation, and the cut model may not be refined in this correction.
- Stable accounting unchanged: **42 / 14 / 28**, debt **5**, M3 packages **59**.

## 2026-08-28 — `M3-CP4c-2-TB-X2-R2`: planned Y4 control stop; diagnostic witness authority is invalid

Artifact-only Test + Benchmark run/job `33215632118 / 98998526420` consumed immutable GMP package
`9702321260` from semantic/test source `232ac459b13657529e064272a75c5583770a5963`. Package/source/GMP/selector
preflight passed. D1 executed exactly once and produced exactly three `m3Cp4c2Y1` records; no rebuild, relink,
fixture mutation, generated discovery, or benchmark occurred.

- Prescribed sphere raw D1: source `chi=2`; network `V/E/F=18/30/18`, reported `chi=6`; 24 traces / 56 events;
  all 18 complement components individually reported disc topology. This is retained as raw control-invalid
  evidence, not a Y5 conclusion.
- Torus fixed control: source `chi=0`, non-cellular, but network `V/E=0/0` rather than required `48/48`.
  **Y4 FAIL / required STOP.**
- Two-ring raw control: network `V/E/F=9/11/3`, `chi=1`, three disc components, cellular.
- D2 was correctly skipped after Y4 failed; therefore Y2/Y3 are unavailable and
  `selected_r2_branch=NONE`. `selected_gate=NONE`; no cumulative gate runtime occurred.
- Static review identifies the torus mismatch as test authority: D1 uses `rails_from_atlas`, while production and
  frozen X1 use feature-map-derived `authoritativeRails`. New non-stable candidate
  `M3-CP4c2-TB-X2-R2-CAND-01` records the structurally invalid control fixture. The sphere's global Euler terms
  also require independent authority review before any correction.
- Result/log artifacts: `9703233161 / 9703233545`, digests
  `6b13e0bcddc3ffeba93077b6b1115bc8a400b9b9a6051d83df01ac11bec191f7 /
  19975ef0fc0e154e02326827287fd60a3a7813b10cda1fe20840e60a072d3c1b`.
- Stable accounting stays **42 / 14 / 28**, debt **5**, M3 packages **59**. Existing X2 CAND-04 remains
  active/unlocalized because D2 did not run.
- Exact next: runtime-free `M3-CP4c-2-TB-X2-R2-REVIEW-PLAN`; no CB3 or 355/357/358 gate is authorized.

## 2026-08-28 — `M3-CP4c-2-CB2-DIAG`: independent cellularity/localization diagnostics compile green

Code + Build only. **No Directional runtime, test, or benchmark executed.** Source evidence `232ac459b13657529e064272a75c5583770a5963` changes only `tests/FieldAlignedCurveNetworkTests.cpp` (+1,396 / -0) and adds the two non-gating D1/D2 identities required by `Architecture_M3_CP4c2_TB_X2_Plan.md`.

- D1 `GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable` independently constructs the exact network complement for prescribed sphere, torus, and two-ring, publishing source/network `V/E/F/chi`, per-component boundary/Euler/disc evidence, and `networkOnlyCellular`. Its oracle has zero `SurfaceCutGraph` calls/reuse and does not define cellularity from the product's cut set.
- D2 `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable` test-side re-derives current producer accounting to distinguish sites 419/437/474 and publishes its terms beside the independent oracle and actual product error/locus. During review its added-vertex accounting was corrected to match production's cut-endpoint-only rule; no product behavior changed.
- Source patch apply: run/job `33212827595 / 98989820033`, exact preserved patch SHA-256 `377328dc7e82c5e60e12a1b9b0f566d1bd21d3db6b7a07cb6c1b431926afce9f`.
- Authoritative GMP compile: run/job `33212932401 / 98990159075` — PASS. Immutable result artifact `9702321260` / `sha256:05237f108a65c73df81b6b125d6fcecad10ad9b5af4104ecce3c6bb9f6642035`; diagnostic log `9702321551` / `sha256:236458a4146ebec93638065a0f55500e8bb77dbf216d1d7b942f667be4070ab3`; packaged source archive `986db8b91d06eab4284f3a0e49c1d8c9ad2676df61fdfdd4a94e56ba34a5644f`. All eight required targets present, manifest verified, preflight/full build exit `0`, all source-status snapshots empty, both gmpxx/gmp linked, `runtimeExecution=false`, `exactArithmeticBackend=GMP`.
- Accepted selector 355/prefixes 316/346/353 and frozen candidates 357/358 remain byte-identical. `selected_gate=NONE`; cumulative gate runtime remains blocked.
- Stable accounting unchanged **42 / 14 / 28**, debt **5**; M3 packages **59**.
- Exact next: artifact-only `M3-CP4c-2-TB-X2-R2`, beginning with `TB-X2-R2-EXEC` against artifact `9702321260`. It publishes Y1/Y2, adjudicates Y3/Y4, and selects exactly one frozen Y5 corrective branch or stops; it does **not** run 355/357/358 or authorize the cumulative gate.

## 2026-08-28 — `M3-CP4c-2-TB-X2-PLAN`: the oracle may not be the mechanism under test

Planning-only. No Directional runtime, compile, package, benchmark, or product/test/fixture/selector change. Record: `Architecture_M3_CP4c2_TB_X2_Plan.md`. `selected_gate` remains **NONE**; both frozen candidates remain byte-frozen (**357** `b896d0db…64dc70`, **358** `6eda3aad…b64fbe62`).

- **The structural cause of the unusable X2 is named.** `observe_cp4c_witness` calls `SurfaceCutGraph::make` first and gates every downstream publication behind it, so a failing A2a′ yields one error code and nothing else. And `networkAlreadyCellular` was defined as `cutGraph.cut_edges().empty()` — a restatement of the producer's own decision rather than a measurement of the network's complement, i.e. an oracle built on the mechanism it tests. **The successor's oracle may not call, link against, or reuse any part of `SurfaceCutGraph`.**
- **A deliberate asymmetry is recorded so it is not read as a contradiction.** DEFN measure X3 told the *producer* to reuse A2b's component traversal rather than duplicate it; this plan tells the *oracle* to implement its own. Divergence is the risk in the first case; independence is the requirement in the second.
- **Localization is decidable without a product change.** `CellularityNotEstablished` returns from three reachable sites — `SurfaceCutGraph.cpp:419`, `:437`, and `:474`, the last with **no locus attached**. If the independent oracle finds every component is a disc, then `alreadyCellular` is true, the cut set is empty, 419 and 437 are unreachable by construction, and the failure is **necessarily 474**.
- **A leading hypothesis for 474, issued as refutable rather than as a finding.** `V` and `E` are counted in the network's abstract graph, whose arcs cross face interiors, while `F` counts source-face components separated by `network_barriers` — **whole source edges**. Different complexes, so `V − E + F == χ` is not an identity between them. The defect is invisible on the torus, which has zero traces and therefore no coarsening; the prescribed sphere, with 24 traces, is the first witness with traces to reach A2a′. **The witness the design reasoned about is not the witness that exercises the code** — the same shape as the ordinal-13 trap and the C5 torus recurrence.
- **A standing prohibition on the tempting repair.** `proves_cellularity()` must not be relaxed to get past 474: the certificate condition is correct, and if the counts do not satisfy it the counts are wrong. Widening it would convert an accounting defect into a silently-wrong certificate and destroy the only guarantee A2a′ exists to provide.
- **The post-certificate A2b observation is scheduled conditionally, and honestly.** It is reachable only once a certified cut graph exists, so the plan sets three branches with actions fixed in advance and **prohibits a test-only injection path** into A2b or any weakening of `make_from_candidate`, which is a tamper-rejection path. If the observation is unreachable, it must be reported unreachable — an honestly unreachable measurement is worth more than a reachable fiction.
- **Sequencing that may not be collapsed:** `CB2-DIAG` → `TB-X2-R2` → `CB3` → `TB-X2-R3` → `TB-GATE-EXEC`, under measures **Y0–Y9**, with five falsifiable predictions. Prediction 1 — that the sphere network is already cellular — carries the frozen decision and is the same proposition as DEFN prediction 5, still unadjudicated.
- Stable accounting unchanged: **42 / 14 / 28**, debt **5**, M3 packages **58**.

## 2026-08-28 — `M3-CP4c-2-TB-X2-REV`: evidence fits neither frozen branch; gate remains unselected

Review-only. No Directional runtime, compile, benchmark, package regeneration, source/test/fixture/selector/build
logic mutation, or corrective implementation design occurred. Record:
`Architecture_M3_CP4c2_TB_X2_Review_Record.md`.

Authoritative X2 evidence remains run/job `33199227974 / 98944212158` on immutable GMP package `9696201700`.
The execution evidence is trustworthy, but it is insufficient for the frozen binary scope decision. Static
re-derivation shows `observe_cp4c_witness` calls `SurfaceCutGraph::make` before publishing the fields intended to
measure network cellularity; on the observed `CellularityNotEstablished` failure it returns immediately. The
field named `networkAlreadyCellular` is emitted only after a successful cut graph and is merely an empty-cut-set
check, not an independent network-only `V/E/F/χ` certificate. The same early return prevents observation of
whether `RotationSystemInconsistent` persists or disappears after a certified embedding is supplied. The report
also publishes only the shared cut-graph error code, not enough localization to distinguish its multiple product
return sites.

Therefore **357 is not established and 358 is not established**. `selected_gate=NONE` and cumulative
`TB-GATE-EXEC` is blocked by the frozen stop rule. `M3-CP4c2-TB-X2-CAND-03` is resolved as a
**test-authority / measurement-incomplete / non-stable** defect. New `M3-CP4c2-TB-X2-CAND-04` retains the real
but currently unlocalized product evidence that the valid prescribed sphere reaches A2a′ and
`SurfaceCutGraph` fails `CellularityNotEstablished`. Stable accounting remains **42 / 14 / 28**, debt **5**,
M3 packages **58**.

Exact next: **`M3-CP4c-2-TB-X2-PLAN`**. No selector choice or cumulative gate runtime is authorized first.


## 2026-08-28 — `M3-CP4c-2-TB-X2-EXEC`: frozen report-only X2 evidence preserved

Artifact-only X2 execution is complete on immutable GMP package `9696201700` from semantic/test source
`93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`. Authoritative run/job `33199227974 / 98944212158` verified
the package manifest, frozen selector identities/hashes, GMP provenance, compiled fixture source root, and
pre/post byte-mode inventories. Exactly one frozen X2 identity executed; no C1/C3/C6 or cumulative gate identity
ran. Configure, compile, relink, repair, generated discovery, and mutation were all false.

The report-only process exited 1 and published exactly one raw `m3Cp4c2X2` record. The complete publication is
retained verbatim in `Architecture_M3_CP4c2_TB_X2_EXEC_Artifact_Only_Evidence.md`; this EXEC turn makes no
357/358 branch decision. Result/log artifacts are `9697052371 / 9697052810`, digests
`524534f76d99500c91e921d81d9d38bc6f8607f379500cd976d0c9fa8600f22b /
916fa2478d9bd3fc5ba42e3dd670c7373ed3e26a6fcc721a733063da42161719`.

Two preceding controls were non-semantic orchestration failures: `33198406913` failed at startup because the
reusable observer's static permission union was not granted, and `33198586715 / 98942044412` materialized
packaged source outside the absolute fixture root embedded in the binary, yielding only `fixture-load-failed`.
Both are resolved/non-stable in the regression tracker. Stable accounting remains **42 / 14 / 28**, debt **5**,
M3 packages **58**.

Exact next is **`M3-CP4c-2-TB-X2-REV`**, evidence review only. No cumulative 357/358 gate runtime has started.


## 2026-08-28 — `M3-CP4c-2-CB1`: certified A2a′ cut-graph authority compiled green

`M3-CP4c-2-CB1` is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic/test source
`93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`. The turn implemented `SurfaceCutGraph` between A2a and A2b,
made `GlobalTopologyPlan` consume its certified source-edge cuts, shared the complementary-face partition
traversal, updated `RemeshPipeline`, applied Amendment 12 to `DESIGN.md`, and authored X1/X2/X5/X6/X7
checkpoint observations including the independent annulus measurement required by prediction 2. No post-region
repair/re-cut, geometry insertion, tolerance-based topology decision, or `GlobalTopologyPlan` dependency was
added to A2a′.

Both X2-conditioned successor selectors are frozen without manufacturing a Code+Build runtime conclusion:
**357** / `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` and **358** /
`6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`; the X2 report-only selector is
**1** / `88af227b7c7ca78d2a6247624b3a5f860026cf50fd3c2bd6a215756b086dafc8`. Accepted 355 and its 316/346/353
prefix hashes remain unchanged.

Final compile run `33196876096` is green: changed-owner job `98936191472` and eight-target package job
`98936799976` both PASS. Immutable GMP package `9696201700` has artifact digest
`af3ebe2efaab66fed70de8d954cb5615abd9428f401ea974dffe1e14577c8097`, source archive
`8694f0fb85d101e3c5862e5a6a8a8a3ed241c723fd229eb44f83844b30321687`, clean source-status snapshots,
verified manifest, gmpxx/gmp linkage, and `runtimeExecution=false`. Two compile-only defects were corrected
during the turn; no Directional runtime was executed. Stable accounting stays **42 / 14 / 28**, debt **5**;
the immutable package advances M3 packages to **58**.

Exact next is artifact-only **`M3-CP4c-2-TB-X2-EXEC`**, followed by X2 review and then the selected 357/358
gate execution/review. Report: `Architecture_M3_CP4c2_CB1_Code_Build_Report.md`; plan:
`Architecture_M3_CP4c2_TB_Artifact_Only_Test_Benchmark_Plan.md`.


## 2026-08-28 — `M3-CP4c-2-DEFN`: the torus network provably cannot bound discs; `SurfaceCutGraph` frozen

Definition-only. No Directional runtime, build, compile, package, benchmark, or product/test/fixture/selector change. Record: `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md`.

- **CP4c-1's closure was independently re-verified first**, from the repository rather than the report: the 355 selector `e9d88f11…5afeaa` and all three accepted prefixes (`601ce2b6…`, `20d3b0b1…`, `51ff96d7…`) recomputed identical; the 3-entry non-gating selector `537a8010…ffcd6a` confirmed with both W5-retired identities absent; `src/` and `include/` unchanged across CB4 with `tests/FieldAlignedCurveNetworkTests.cpp` the only code file touched; W1's precondition deleted cleanly, W2's `ASSERT_FALSE(producedTerminalKinds.empty())` in place with both named checks surviving. **The closure claim is upheld.**
- **A theorem, not a conjecture.** For a cellular embedding, `F = E − V + χ`. The measured torus network has `V = 48`, `E = 48`, and `χ = 0`, giving `F = 0` — impossible, since the complement is non-empty. At least one complementary component is not a disc. Generalized: a disjoint union of closed curves always has `E = V`, so **no disjoint union of closed curves can ever be a cut graph of the torus**. The gap is architectural, not a property of the committed fixture, and cannot be fixed by choosing better feature curves.
- **`UncutFaceComponentOrbitSeedNotUnique` at `GlobalTopologyPlan.cpp:1741` is correct behaviour.** A cylindrical component touches labeled faces on both boundary circles, collects two seeds, and fails. The producer is reporting a missing input; there is no bug at that line.
- **`DESIGN.md` §7.2 is defective and is amended (Amendment 12).** Its claim that invariant 7 — every region has disc topology — "holds by construction" is provably false on closed surfaces; termination-on-contact makes traces well-defined but says nothing about whether the graph is a cut graph. Step 8, "extract the faces of the embedded graph", is undefined for a non-cellular embedding. §4.6's motorcycle-graph decomposition guarantee is amended to name its condition: it applies only when the field has a singularity or the surface has a boundary.
- **The decision: one new authority, `SurfaceCutGraph` (stage A2a′)**, produced after A2a and consumed by A2b, guaranteeing the complement is a disjoint union of open discs — source-edge cuts only, cellularity certificate, mandatory preservation, exact and deterministic, idempotent on already-cellular input, fail-closed.
- **The stop condition is narrowed to its intent, not waived.** Repairing, collapsing, re-cutting, or re-typing a region *after* derivation remains a stop. Supplying cuts as a typed input *before* derivation, from a separate single-writer authority, is permitted. The operative test: if the cut decision can be made without looking at a produced `GlobalTopologyPlan` region it is a precondition; if it needs to see one it is a repair.
- **Scope: C1 + C6. C3 deferred pending measure X2.** The sphere's `RotationSystemInconsistent` is a different failure — `χ=2`, 24 traces, 56 events, a different code, unmeasured — and designing for it unmeasured would repeat the CP4c-0/0b dependency inversion. **The gate is 357 or 358 and is deliberately not frozen**; X2 decides it.
- **A vacuity trap is closed.** C3 and C6 are quantified over "produced witnesses" and no witness currently produces a plan, so both would pass vacuously — the same defect class as CP4c-1's C5. C1 is the non-vacuity anchor and X7 makes it reportable: a green C6 over zero regions is a red result.
- Measures **X0–X9** issued, with five falsifiable predictions including the deliberately-uncertain one that the sphere is already cellular.
- Defect recorded and repaired: the tracker's `CAND-03` entry cited the CB4 report, retired in the fifth consolidation; the citation now names the consolidated record.
- Stable accounting unchanged: **42 / 14 / 28**, debt **5**, M3 packages **57**.

## 2026-08-28 — M3-CP4c-1 TB-R5 — 355/355 green, checkpoint closed / accepted

`M3-CP4c-1-TB-R5` is **COMPLETE / GATE GREEN 355/355 / CHECKPOINT CLOSED / ACCEPTED**. Authoritative
artifact-only run/job `33161644741 / 98817323175` consumed immutable CB4 GMP package `9675666067`
(`63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`) from semantic/test source
`b1ce8ad65952bd2bd76238f6dfc55523f6a24747`. Prefixes 316/346/353 all passed, C4 ordinal 354 passed, C5
ordinal 355 passed, all 355 selected exactly once, and zero C++ exceptions escaped.

W3's previously masked `TraceIntersection` and `MandatoryBarrierTermination` membership checks executed and
passed. The observed union exactly matched the independent review prediction:
`{TraceIntersection(2), MandatoryBarrierTermination(3), SingularityTermination(4)}`, contributed by prescribed
sphere / two-ring / prescribed sphere; torus contributed zero kinds and mechanical remained at
`IncompleteCycleBasis`. The explicit two-ring report identity passed. The three frozen historical diagnostics
remained intentional report-only reds with zero gate credit, and both W5-retired inverted diagnostics were absent,
resolving `M3-CP4c1-TB-R4-CAND-03` as non-stable test-side inverted-precondition evidence.

Immutable package/source postflight passed with configure/compile/relink/repair/discovery/mutation all false.
Result/log artifacts are `9681960334 / 9681960615`, digests
`b8be035ed728b5d6f8efe65e260f9557a9aa8cad0e82b94d11107aab44187a5d /
55ad320aaf810bb5b02fbfccdd7662f4a47333586bdb30397d624d701710439b`. Stable accounting stays
**42 / 14 / 28**, debt **5**, M3 packages **57**. Closure authority:
`M3_CP4c1_Closure_Record.md`; retained immutable report:
`Architecture_M3_CP4c1_TB_R5_Artifact_Only_Test_Benchmark_Report.md`. Exact next: definition-only
`M3-CP4c-2-DEFN`; no CP4c-2 implementation/runtime is authorized by this closeout.


## 2026-08-28 — M3-CP4c-1 CB4 — reviewed C5 test-side correction compiled green

`M3-CP4c-1-CB4` is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic/test source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`. Under W0-W7, C5 no longer requires every witness to produce a trace and no longer freezes the produced terminal-kind union to cardinality two; it retains the per-trace terminal contract, non-vacuity, and both named-kind membership checks. W4 was not used because no independent frozen allowed terminal vocabulary was established. Both mandatory W5 sphere-failure diagnostics were retired with surviving-cover rationale; W5b's three report-only publishers remain. `src/` and `include/` are unchanged.

Frozen required authority is unchanged: **355** identities / `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, with byte-identical 316/346/353 prefixes and C4/C5 at ordinals 354/355. The non-gating selector is now **3** / `537a8010033452a16be5f6a80926ea61c065f7f7f443b5b2950f73c8b8ffcd6a`.

Authoritative compile run/job `33145657048 / 98766007030` PASS after a startup-only first attempt `33144909546` exposed a caller permission-ceiling error before compile. Schema validation job `98765978208` PASS. Immutable eight-target GMP package `9675666067` has ZIP digest `63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`, manifest **28/28**, source archive `baead768e6f05acc7b09177a1571139262a514056cfc4fa281b8933135b6fc84`, clean source status, and `runtimeExecution=false`; no test or benchmark ran. Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **57**. Exact next: immutable artifact-only `M3-CP4c-1-TB-R5`; any deviation from the independent review's §8 prediction routes back to review.

## 2026-08-28 — `M3-CP4c-1-TB-R4-REVIEW-PLAN`: both C5 clauses are test-side; line 131 is normative

Independent review and planning only. No Directional runtime, build, benchmark, or product/test/fixture/selector/build-configuration change. Record: `Architecture_M3_CP4c1_TB_R4_Independent_Review_Record.md`.

- **`M3-CP4c1-TB-R4-CAND-01` is RESOLVED / TEST-SIDE OVER-SPECIFICATION / NON-STABLE.** Both C5 failures are test authority. A bounded test-side correction, `M3-CP4c-1-CB4`, is **AUTHORIZED** under measures **W0–W7**. `+0` events / `+0` recurrences; totals remain **42 / 14 / 28**, debt **5**, M3 packages **56**.
- **The authority tension is adjudicated: plan line 131 is normative.** C5 requires that every trace terminate at an actually produced typed kind with both named kinds non-vacuously represented — a property, with no cardinality. Line 101's "exactly the required terminal event-kind set" is a TB reporting instruction and cannot enlarge a frozen definition; "including" is membership language, not exhaustion.
- **The failing assertion contradicts its own message.** `ASSERT_EQ(2U, producedTerminalKinds.size()) << "terminal-kind witness union must be non-vacuous; …"` — non-vacuous is non-emptiness, not two. The two checks that carry the real requirement sit at lines 6712 and 6717 and, because the assert is fatal, **have never executed on any run**. Measure W3 requires the successor TB to report them individually rather than promote them silently to "passed".
- **A two-cardinality reading forbids correct behavior.** `SingularityTermination` is a frozen terminal kind; under `size()==2`, C5 goes red *because* a trace correctly terminated at a singularity. The third kind is the repair of the exact gap lesson **64e** names — declared since CP3b, emitted nowhere — finally reaching a producer and a witness.
- **Clause 1 is a recurrence of `M3-CP4c0b-DG-CAND-02`.** The pipeline-authoritative torus was over-specified as *empty* one checkpoint ago and as *non-empty* now, while accepted identity `TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded` — green in the same run — requires zero traces. Line 131 is universally quantified over produced traces, so a zero-trace witness satisfies it vacuously.
- **The product passed the part that matters.** The run produced exactly two assertion failures, so every per-trace assertion held: on two-ring and the prescribed sphere, every produced trace terminated at exactly one typed terminal event whose kind was actually published.
- **Falsifiable prediction issued:** C5 green, gate 355/355, union exactly `{TraceIntersection, MandatoryBarrierTermination, SingularityTermination}`, torus contributing zero kinds, lines 6712/6717 executing and passing. Any deviation is new product evidence and routes back to review, not to another correction.
- **Two of the five non-gating diagnostics have inverted**, and now carry `M3-CP4c1-TB-R4-CAND-03` (ACTIVE / TEST-SIDE INVERTED PRECONDITION / NON-STABLE). `BranchBoundaryPairingContinuationIsUnique` and `PrescribedSphereCandidateTraceTransportFailureSiteIsObservable` assert that sphere network construction *fails*; accepted authority now publishes that network, so both assert the opposite of accepted reality. This is the anti-pattern `LESSONS.md` already names — *"a test that asserts a witness currently fails will invert the day you fix it"* — written down before the failure that repeated it. Measure **W5 is mandatory**: CB4 must re-author or retire each, naming the disposition per identity. Non-gating status is explicitly not a reason to defer, since a permanently-red diagnostic contradicting accepted authority misleads the next reader and masks any genuine future red in the same identity. Only W5b, the three report-only publishers, is discretionary.
- Lessons **64s**, **64t**, **64u** added; lesson labels de-duplicated after a collision.

## 2026-08-28 — `M3-CP4c-1-TB-R4`: accepted 353 prefix green, C4 pass, C5 semantic red

**Test + Benchmark / COMPLETE / VALID SEMANTIC RED 354/355.** Artifact-only run/job
`33141046678 / 98751794167` consumed immutable GMP package `9673249952` from semantic source
`66a065b5e07910568a317e24f0fc6b93d890d104`. Accepted prefixes re-proved **316/316, 346/346,
353/353**. C4 ordinal 354 passed; C5 ordinal 355 alone returned red. All 355 required identities
selected exactly once, zero escaping C++ exceptions, and immutable pre/postflight passed. Result/log
artifacts `9674006723 / 9674006927`, digests `d8c02733475e93f10b0868507e0ce2d4398b93d24bdec6a5076febbd6fd0a514 /
19e9a0398bc400dfaf16f4601d181389940c2de8438240b7cb3a5e25c0aec5c8`.

C5 fails two clauses: its helper requires the zero-trace pipeline torus to have non-empty candidate
traces, and its terminal-kind union expects 2 while observing 3. Both named required kinds are present;
the sphere additionally publishes kind 4 (`SingularityTermination`). `M3-CP4c1-TB-R4-CAND-01` is
**ACTIVE / REVIEW REQUIRED / NON-STABLE** because frozen authority contains an interpretive tension over
whether “exactly the required terminal event-kind set” forbids that additional lawful typed kind.
The five historical diagnostics all returned trustworthy report-only reds with zero gate credit.

A process-order miss in this ChatGPT Web turn is separately recorded as resolved
`M3-CP4c1-TB-R4-CAND-02`: initial repository inspection preceded the mandatory per-turn snapshot/read-mode
gate. The turn switched to snapshot mode during closeout; source-snapshot run `33141471428` / artifact
`9674093771` captured control head `7e5d30854e0d776bae5bad282c5aad1a45bbae45`. It does not alter the
immutable TB evidence.

Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **56**. CP4c-1 stays open.
**Exact next: mandatory `M3-CP4c-1-TB-R4-REVIEW-PLAN`; no retry or correction first.**

## 2026-08-28 — `M3-CP4c-1-CB3`: cumulative 355 selector frozen, GMP compile green

**Code + Build / COMPLETE / RUNTIME-FREE.** CP4c-1 was rebased onto accepted CP4c-0b authority without
re-authoring C4/C5. The required selector is now **355** /
`e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`: first 353 are byte-exact
accepted CP4c-0b selector `51ff96d7…ac6a5`, first 346 `20d3b0b1…3e46a`, first 316 `601ce2b6…0193c`,
and ordinals 354/355 are C4/C5. The five-identity non-gating selector remains unchanged
`9f4f287e…fb130`. No product implementation, test body, fixture, accepted expectation, or Q8 ownership changed.

Selector apply run/job `33138991496 / 98745369305` produced applied commit
`a12a171e347d0c1c7cd88df604e907a603223d58`. Exact compiled evidence source is
`66a065b5e07910568a317e24f0fc6b93d890d104`. Authoritative compile run/job
`33139188595 / 98746005796` passed all eight standard targets with GMP/GMPXX linkage, 28/28 internal
manifest, clean source status, and `runtimeExecution=false`. Immutable package/result artifact
`9673249952` has GitHub digest `17a3f8da793fc20562e5ec2f0ab441d39f795dd146171e989fb952e6f942d2ea`;
compile log `9673250286` has digest `cffa6fc4a72c0d60fa2199131cdd6073c7a8c7f15482a0e48af98cb3dadf32b9`.

Control-plane only: first compile caller `33139114617` ended in startup failure because its permission
ceiling was below the reusable observer graph; zero compile/runtime occurred. The caller permission alone
was corrected before the authoritative run. Stable accounting remains **42 / 14 / 28**, debt **5**,
M3 packages **56**. Accepted runtime remains CP4c-0b T5 353/353. **Exact next: artifact-only
`M3-CP4c-1-TB-R4` against package `9673249952`; required gate 355, five diagnostics zero-credit.**

## 2026-08-28 — `M3-CP4c-0b-TB-T5`: 353/353 green, CP4c-0b closed / accepted

Authoritative artifact-only retry run/job `33136084757 / 98736295227` consumed immutable GMP package
`9671190795` (`2901926c…5c1`) from semantic/test source `93059089881c8715a168a61968a8d6874ee1a670`.
U0 and immutable postflight passed; required selector **353/353**, accepted prefixes **316/316** and **346/346**,
`zeroSelected=0`, zero escaping C++ exceptions, and no identity crossed the review's 65,588 ms slow threshold.
Watched ordinals 7, 9, 12 and 13 all passed without re-authoring. Four non-gating U3/U4 identities passed with
zero gate credit: fan nodes 8 / barrier traces 3 / contact 0 / mutual 0 / inconclusive 0 / guards silent;
two-ring nodes 9 / barrier events 3 / FirstContact pairing 3/3 / contact 0 / mutual 0 / inconclusive 0 / guards
silent; prescribed sphere publishes 24 traces. Result/log artifacts `9672113006 / 9672113408`, digests
`7f582a03…c1af53 / 91754edb…1aea458`. `T5-CAND-01`, `P03-CAND-01`, and the transferred TB-R8 circulating-trace
candidate are resolved with no stable-count change. Stable accounting remains **42 / 14 / 28**, debt **5**,
packages **55**. **CP4c-0b closes / accepts. Exact next: `M3-CP4c-1-CB3` under Z0-Z5.**

Control-plane history retained without semantic credit: premature cleanup `33135477355`; schema startup failure
`33135693069`; first execution `33135877807` stopped at 0/353 because its parser expected `AtlasDerived` while
the publisher emitted `atlas-derived`; normalized payload was SchemaStore-green in `33136024237` before the
authoritative retry. No semantic byte changed between attempts.

## 2026-08-28 — `M3-CP4c-0b-CB3-INSTR`: bounded non-gating observability build green

CB3-INSTR is **COMPLETE / BUILD GREEN / RUNTIME-FREE** under independent-review measures V0-V7. Exact source `93059089881c8715a168a61968a8d6874ee1a670` changes only `tests/FieldAlignedCurveNetworkTests.cpp` and the CP4c-0b non-gating selector; `src/`, `include/`, fixtures, accepted identities, and the frozen 353 selector are unchanged. V1 selects the existing sphere A2a census; V2 adds a fan termination/guard census; V3 adds a two-ring FirstContact↔MandatoryBarrierTermination pairing census. Required selector remains 353 / `51ff96d7…ac6a5` with first-346 `20d3b0b1…3e46a`; non-gating selector is 4 / `d4224002…d9ad`. Authoritative compile run `33133572290`, jobs `98728445391 / 98728639650`, produced immutable GMP package `9671190795` (`2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1`), internal manifest 28/28 PASS, clean source status, GMP/GMPXX link evidence, `runtimeExecution=false`. Stable accounting stays **42 / 14 / 28**, debt **5**, M3 packages **55**. Exact next: artifact-only `M3-CP4c-0b-TB-T5`; `T5-CAND-01` remains active until U3/U4 are actually published.

## 2026-08-28 — `M3-CP4c-0b-TB-T5-PREFLIGHT-REV`: U3/U4 found unsatisfiable, a bounded instrumentation CB authorized

Independent review and planning only. No Directional runtime, build, benchmark, or product/test/fixture/selector/build-configuration change. Record: `Architecture_M3_CP4c0b_TB_T5_Preflight_Independent_Review_Record.md`.

- **A bounded instrumentation Code + Build, `M3-CP4c-0b-CB3-INSTR`, is AUTHORIZED under measures V0–V7**, with a hard boundary: test-side and non-gating-selector-side only, zero production semantic change, and **the 353 selector `51ff96d7…ac6a5` must not change by one byte** — U0.2 verifies it and the 346-line ordered prefix is what keeps `first_red_ordinal` comparable.
- **The authorization corrects this reviewer's own prior turn. U3 and U4 were issued unsatisfiable.** They name observations that no selected identity produces, on a package that cannot be changed without a CB. The defect is in the measures, not the package.
- **The fan is built twice inside the 353 and observed zero times.** Accepted `ResolvedBranchCorrection.FieldAlignedCurveNetworkIsAClosedProducerOnEveryReachableWitness` (line 6348) wraps the build in `EXPECT_NO_THROW` and discards it; DG#7 `TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded` (line 7044) discards it and calls `SUCCEED()` unconditionally. **A fan build that failed closed on `N1`/`N2`/`N4` passes both.**
- **Six of the seven `...IsPublishedNonGating` census identities are selected by nothing.** `PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating` already computes the terminal-event-by-kind histogram that is ordinal 13's second term, and no selector runs it. `ContactPredicateCensusIsPublishedNonGating` already covers the fan and two-ring under `rails_from_atlas` and is the single entry in the non-gating selector.
- **No production instrumentation is needed or authorized.** The observation channel already exists: `diagnose_field_aligned_contact_census` threads a census pointer through the producer's own pass and fills it from the producer's own candidate (`src/geometry/SurfaceCellTracing.cpp:2890`).
- **The risk ranking inverts: ordinal 12 now outranks ordinal 13.** `PublishesTypedFirstContactAndTerminationEvents` requires a `FirstContact` event paired at the identical node, face and edge to every `MandatoryBarrierTermination` (lines 1333–1341). **Nothing in the DG seven asserts that pairing**, and it is exactly what S5's relocation of the termination stage could break. Both remain STOP on red.
- **Withdrawn: "mutual termination is the least-exercised path."** DG#5 line 6939 does not merely permit it on the sphere — it *requires* it, and T4 measured it green. Ordinal 13's predicted green at 8 is instead re-grounded on the census being an in-band observer of the producer's own candidate, so S1's fan count of 8 was the producer's own.
- **Option B — amending U3/U4 down to what the frozen package can answer — was considered and rejected**, on the cost asymmetry once ordinal 12 is priced in, and because narrowing a frozen measure under gate pressure is the habit `LESSONS.md` §6 exists to prevent.
- Lessons **64q** and **64r** added: write a measure from the selector rather than the design intent, and a `(void)`-discarded build is not an observation. (Labelled `64h`/`64i` when first written; relabelled on 2026-08-28 to resolve a collision with the pre-existing lessons of those names.)
- Stable accounting unchanged: **42 / 14 / 28**, debt **5**, M3 packages **54**.

## 2026-08-28 — `M3-CP4c-0b-TB-T5`: pre-gate observability gap, 353 not run

T5 is **BLOCKED / PRE-GATE OBSERVABILITY GAP / 353 NOT RUN**. U0 static authority is valid on immutable GMP package `9668492827` and full selector `51ff96d7…ac6a5`, including exact first-346 prefix `20d3b0b1…3e46a`, but U3 requires a before-gate fan/two-ring terminus census that the immutable package cannot fully publish. Its compiled census surfaces omit required per-trace terminus/barrier and arrival-comparison/mutual-tie telemetry, and U4 lacks a dedicated per-witness N1/N2/N4 silence publisher. U7 forbids adding instrumentation or compiling inside T5, so the only valid action was to fail closed before runtime: **0/353 identities executed**, no compile/relink/repair/discovery/mutation/timeout/guard widening. Exact source-snapshot audit `33130565916 / 98718854457`, artifact `9670081197` (`58403bc8…3023a284`). Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **54**. `T5-CAND-01` is active evidence-capability/non-stable; the cleanup-trigger race `T5-CAND-02` is resolved orchestration/non-stable. Exact next: independent `M3-CP4c-0b-TB-T5-PREFLIGHT-REV`.

## 2026-08-28 — `M3-CP4c-0b-DG-T4-REV`: T4 verified, T5 authorized, and the accepted-authority risk mapped

Independent review and planning only. No Directional runtime, build, benchmark, or product/test/fixture/selector/build-configuration change. Record: `Architecture_M3_CP4c0b_DG_T4_Independent_Review_Record.md`.

- **T4 is valid and T5 is authorized.** `M3-CP4c-0b-DG-T4-EXEC` is EXECUTION GREEN **7/7** on immutable GMP package `9668492827` from semantic source `b2629040450c12507367c232f68a4d972b46450f`, run/job `33128261911 / 98711506300`, with clean byte-and-mode postflight and independently re-hashed result and log artifacts.
- **Independently re-verified, not taken from the report:** DG selector **7** / `d28bbeeb…e245c`; full selector **353** / `51ff96d7…ac6a5`; every accepted identity present in the 353; all seven DG identities inside it; and — stronger than the report claimed — **the first 346 lines of the 353 selector hash exactly to the accepted CP4c-0 selector** `20d3b0b1…3e46a`. The accepted prefix is preserved **in order**, so `first_red_ordinal` remains comparable with every prior CP4c-0 run. U0.2 now requires verifying both hashes.
- **The DG review's one flagged inference is closed.** That review explicitly marked "every pipeline-torus node is a mandatory-edge endpoint" as inferred rather than measured. T1 measured it: atlas-derived rails give 0/0/0/0/0; pipeline-authoritative rails give **48 `HardFeature` mandatory edges / 0 singularities / 48 structural endpoint nodes / 0 traces / 0 events, zero contact provenance**. First decision row. **`M3-CP4c0b-DG-CAND-02` is RESOLVED / TEST-SIDE OVER-SPECIFICATION / NON-STABLE.**
- **T2 and T3 verified line-by-line against the DG review's specification, with no shortfall** — the corrected identity is in fact stronger than required, asserting lawful provenance on every node as well as the absence of contact provenance.
- **What T4 does not establish is the whole of T5.** The seven DG identities have never been accepted and are a strict subset of the 353; **not one accepted identity has executed against S2–S6.** The review maps the exposure to four accepted identities inside the 316 prefix — ordinals **7** and **9** (authorized to change for the site-A vocabulary split), and ordinals **12** and **13** (**not authorized; a red there is a stop**).
- **Ordinal 13 is the one to watch.** `FieldAlignedCurveNetwork.PublishesTypedSingularityPortsAndMandatoryGraph` asserts `EXPECT_EQ(8U, nodes().size())` on the **four-triangle fan**, and that 8 decomposes — per its own comment — as `5` structural nodes plus `3` terminal 0-cells, **one per barrier-terminating trace**. It is therefore a direct function of the termination semantics S2–S6 rewrote, on the witness CP4c-0b repeatedly and correctly declared *excluded*. **Excluded from reasoning is not excluded from the gate.** Predicted green at 8, because S1 measured the fan at zero shared-face contacts under the same rail authority and proper-crossing is a strict subset of shared-face; the residual risk is **S5's relocation**, not S3's predicate, since a symmetric fan can produce simultaneous barrier arrivals and the mutual-termination tie policy is the least-exercised path in the checkpoint.
- **Measures U0–U7 issued** for `M3-CP4c-0b-TB-T5`, including **U3**'s fan/two-ring terminus census published whether or not the gate is green, and **U4**'s guard-silence census — the DEFN requires an identity proving N1/N2/N4 do not fire, and it is **not among the seven**.
- **Fourth CP4c consolidation.** Three superseded documents retired into `M3_CP4c_Consolidated_Record.md` with their durable content inlined verbatim: the S1 review record (its census table, the fan's load-bearing `nodes = 8`, and the two authorized accepted re-authorings), the CB1 S2–S6 build report, and the first DG report (its 6/7 red and the resolved `DG-CAND-01` `tar | grep` orchestration failure). All inbound references repaired.
- Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **54**.
- **Exact next: `M3-CP4c-0b-TB-T5` under U0–U7.**

## 2026-08-27 — `M3-CP4c-0b-DG-REV`: DG red adjudicated as test-side; rail-authority divergence identified; CP4c docs consolidated

Independent review and planning only. No Directional runtime, build, benchmark, or product/test/fixture/selector/build-configuration change. Record: `Architecture_M3_CP4c0b_DG_Independent_Review_Record.md`.

- **`M3-CP4c0b-DG-CAND-02` resolves as a test-side over-specification.** No S2–S6 contract breach is established. The failing assertion — `torus.network->nodes().empty()` — asserts a **total** property where the checkpoint owns a **relational** one, and it imported a figure measured under a different construction.
- **The cause is a rail-authority divergence that nothing had named.** S1 measured the torus with `rails_from_atlas` and reported `nodeCount=0`; the DG identity built it with the production pipeline's `authoritativeRails`. Different rails give different mandatory edges, hence different `nodeVertices`, hence different node sets. **Both figures are correct; they answer different questions.**
- **Nodes are structural and unchanged by S2–S6.** They are built before tracing from singularity vertices and mandatory-edge endpoints (`SurfaceCellTracing.cpp:3046-3110`), and the diff between the S1 and S2–S6 sources does not touch that block. With zero singularity ports the new integrated path allocates no node at all — consistent with the observed zero traces and zero events.
- **Independently computed from the committed fixture:** the torus has **zero singularities** and **zero boundary vertices**; the same per-vertex fan-holonomy method reproduces the prescribed sphere's eight singularities exactly, which validates it. Every torus node is therefore a mandatory-edge endpoint.
- **Measures T0–T7 issued.** **T1 is the discriminating measurement and nothing may precede it**: per rail authority and per witness, publish mandatory-edge count and kind, singularity count, node count, and **per-node provenance**. Its decision table is binding and can route back to review — a node with contact provenance, or with none, would be a real defect and T2 would be wrong. **T2** corrects the identity only after T1 confirms: drop the count assertion, keep zero-trace and zero-event, and add that no node has contact provenance. **T3** makes the census self-describing so a figure can never again be asserted across an unnamed boundary. **T4** re-runs the DG seven; **T5** is the first measurement of S2–S6 against accepted authority.
- **Recorded as not established:** S2–S6's effect on accepted authority remains unmeasured; only the seven never-accepted identities have run. `PrescribedSpherePublishesTwentyFourTracesAndCorrectedContactEvents` passing is the first live evidence that S5's relocation works and Q8 criteria 2 and 3 are reachable, but it is one identity on one witness.
- **Third CP4c consolidation.** Five superseded documents retired into `M3_CP4c_Consolidated_Record.md` with every evidence identity inlined: the TB-R10 and TB-R11 focused verification reports, the CB1 P0 preflight record, the CB1 S1 build report, and the TB-S1-EXEC report. The consolidated record gains the full CP4c-0 closure chain (CB-R10/TB-R10, CB-R11/TB-R11, TB-R9 acceptance) and the CP4c-0b chain (P0 stop, S1, TB-S1-EXEC, S2–S6, DG including the resolved `DG-CAND-01` orchestration failure). The S1 review record is **retained as live authority** because it is the only document authorizing the two accepted re-authorings measure T5 must honour.
- Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **53**.
- **Exact next: `M3-CP4c-0b-CB2` under T0–T7**, beginning with T0's preconditions and then T1's rail-authority measurement.

## 2026-08-27 — `M3-CP4c-0b-TB-S1-REV`: S1 stop discharged; S2-S6 authorized with a bounded migration surface

Evidence review and successor planning only. No Directional runtime, build, benchmark, package creation, product/test/fixture/selector/build-configuration semantic change, or acceptance attempt. Durable record: `Architecture_M3_CP4c0b_TB_S1_Review_Record.md`.

- Raw TB-S1 result artifact `9656967036` was independently re-hashed as `dd1f8aa8f2346612beb445d7e5d6a8768a438e36c543e0b4d407b444523d85a4` and re-read. It confirms package source `4bb467806df99c70889394a323c17c13bc185ca3`, GMP, **346/346 PASS**, S1 selected exactly once/PASS with zero gate credit, no mutation/rebuild/repair, and immutable postflight PASS.
- **S1's mandatory non-proper-contact stop does not fire.** Reached included witnesses have site B = 0: two-ring `A/B/C=1/0/0`, torus `0/0/0`; the excluded fan is `1/0/0`. Thus S3 removes no currently selected site-B contact on reached accepted authority. The zero denominator is not misreported as a live proper-crossing proof.
- **Sphere remains explicitly unreached, not zero-contact.** N1 reports 65 steps, budget 9216, visits 3, allowance 2. The non-trivial proper-contact basis remains the frozen independent sphere measurement: every one of the six circulating traces has many proper crossings and a first available crossing at own step 0.
- **S2's predecessor change is positively predicted by S1.** Two-ring site A = 1 and its sole `TraceIntersection` is the overloaded singularity junction. `DeclaresTraceIntersectionsAsTypedNetworkEvents` and `IndependentCompositionOracleValidatesTraceEventGraph` are explicitly authorized for site-A vocabulary re-authoring. Any unrelated accepted expectation edit remains a stop.
- `M3-CP4c0b-P03-CAND-01` remains ACTIVE; S1 discharges only its routing/re-proof-risk measure, not D1-D6. No new candidate/regression. Stable totals remain **42 / 14 / 28**, debt **5**, M3 packages **52**.
- **Exact next: `M3-CP4c-0b-CB1-S2-S6`**, one complete runtime-free GMP Code + Build continuation implementing the already frozen S2-S6 semantics atomically. The resulting immutable package first runs new-contract-only attempt-free `M3-CP4c-0b-DG`; only a green DG advances the same package to the full `346 + n` acceptance TB.

## 2026-08-27 — `M3-CP4c-0b-P0.3-REVIEW-PLAN`: P0.3 withdrawn as false; crash-on-contact already exists, defectively

Independent review and planning only. No Directional runtime, build, benchmark, or product/test/fixture/selector/build-configuration change. Record: `Architecture_M3_CP4c0b_P0_3_Independent_Review_Record.md`; Amendment **A1** at the head of the CP4c-0b frozen definitions.

- **`M3-CP4c-0b-CB1` stopped at binding precondition P0.3 before any implementation, and the stop was correct.** It spent no build, no runtime and no product change discovering a false premise that had survived four documents and one accepted checkpoint. That is what P0 is for.
- **P0.3 was false, and not narrowly.** It required `FieldAlignedNetworkEventKind::TraceIntersection` to be declared and produced by nothing. It has been produced since CP3b — and more than that, **A2a already implements crash-on-contact**: `finalize_field_aligned_events` truncates a trace at its first contact with an earlier trace, allocates a contact node, and emits `FirstContact` + `TraceIntersection`. The CP4c-0b DEFN's §2 and §7 are withdrawn as false. **CP4c-0b is a correction and relocation of accepted authority, not a greenfield addition.**
- **Six defects in the accepted mechanism, each verified from source.** The contact predicate is *"the two segments are in the same face"* with no crossing test (`SurfaceCellTracing.cpp:1278-1307`); priority is trace index order, which is the `TraceSeniority` metric the DEFN ranks worst; the contact node is placed at the face's lowest-numbered vertex rather than at the contact (`:1310-1318`); the pass runs **after** tracing completes (`:1804-1817`) and is therefore unreachable for a trace that never finishes, which is why the prescribed sphere circulates and TB-R8 ran 853 s; `TraceIntersection` is overloaded across origin junction, crash-on-contact and self-closure; and truncation **erases** a legitimate `terminalSingularity` or `terminalBarrier`.
- **The re-proof surface is materially larger than the DEFN estimated.** Correcting the predicate from shared-face to proper crossing strictly reduces the contact set, so any accepted trace currently truncated by a non-crossing contact would continue — changing its segments, terminus, events, node set and every downstream digest. CP3b's `PublishesTypedFirstContactAndTerminationEvents`, CP3a trace content, and CP4ab's node counts and `network_digest` are all in scope. **None of it can be estimated; it must be measured.**
- **Measures P0–P9 superseded by S0–S8**, with **S1, the contact census, mandatory before any semantic change** and empowered to route back to review: if any current contact is not a proper crossing on an accepted witness, correcting the predicate changes accepted authority, which is a plan decision rather than a CB decision.
- **Q8 criterion 3 must be re-stated.** Sites B and C already produce `Terminal` incidences, so as frozen the criterion could be reported satisfied by a shared-face truncation that is not a crossing. It must require a contact produced by the corrected predicate on the prescribed sphere — a clarification of the outcome it always meant, not a weakening.
- **Reviewer error owned.** The false premise came from carrying a true fact about `SingularityTermination` (genuinely produced by nothing, per CP4-DEFN §3.3) across to `TraceIntersection` without checking, and from auditing `canonical_field_aligned_traces` — the tracing loop — and concluding from the mechanism's absence *there* that it was absent everywhere. Crash-on-contact is one function further down the same file, in the finalize pass. One `grep` for the enum value would have falsified it.
- New candidate **`M3-CP4c0b-P03-CAND-01`**: the accepted contact mechanism's six defects. Product semantics, pre-existing, latent behind small accepted witnesses; owned by S1–S6. Stable accounting remains **42 / 14 / 28**, debt **5**.
- **Exact next: `M3-CP4c-0b-CB1`, resumed under S0–S8**, beginning with S0's corrected preconditions and then S1's census.

## 2026-08-27 — complete `M3-CP4c-0-TB-R9` re-proof GREEN 346/346; CP4c-0 CLOSED / ACCEPTED

At explicit user instruction, the branch was freshly recompiled after both TB-R9 test-side fixes and the **complete unchanged frozen 346-identity TB-R9 gate** was rerun artifact-only.

- **Fresh compile authority:** semantic source `7bbc0480d9ab5954329b940992ef41a9223102ed`; run/job `33079499974 / 98542697746`; immutable GMP package `9649395432`, ZIP SHA-256 `557207bf8f668884295258690e3bd31485cbd7709f0be47aa98daea0c53b3e2e`; source archive `f58cfdc0d1886af11328f9b7dfaab8be1bd92d0220549a97d5954944ff7ac68f`; compile log `9649395842 / 45c6c92fc92a6085780bd0b2f56e7ffb80bc3a4ecf8f2cda4744caf8de151179`. All eight standard targets compiled/linked, GMP/gmpxx verified, build/preflight exit 0, `runtimeExecution=false`.
- **Frozen test authority unchanged:** selector remains 346 lines at SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`. TB made no source/test/fixture/selector mutation and no configure/build/relink/repair.
- **Whole-gate authority:** artifact-only run/job `33079817998 / 98543736213` returned **346/346 PASS**, first-316 **316/316**, first-328 **328/328**, Q8 criteria 1/4/5 PASS, zero timeouts, zero escaping C++ exceptions, zero orchestration errors, immutable pre/postflight PASS. Result `9649625534 / 6cd4e3c21dc46fd7e0d6df2209ee5a382531d768f50ae52d190302e05bec02af`; log `9649626115 / 3ba381cd12ec1188bd9ae36020d35bdaa458271ea2c7b1163aac31a9a474d7f9`.
- **Candidate closure:** both formerly RED identities now pass in the complete frozen gate. CAND-01 remains resolved/non-stable/test-side GMP portability; CAND-02 remains resolved/non-stable/test-side fixture-precondition. The skipped TB-R9 review remains skipped/not completed historically.
- **Acceptance/accounting:** **CP4c-0 CLOSED / ACCEPTED**. Stable totals remain **42 / 14 / 28**, debt **5**; fresh package advances M3 packages to **51**. Latest accepted runtime is this TB-R9 re-proof **346/346**.
- **Boundary:** `M3-CP4c-0b-CB1` is next eligible under frozen P0–P9 but is **not automatically authorized** by this closeout.

## 2026-08-27 — `M3-CP4c-0-CB-R11` + `M3-CP4c-0-TB-R11`: CAND-02 fixture defect corrected and focused re-proof PASS

The remaining TB-R9 candidate was diagnosed as test-side. On face `(0,1,2)`, the old positive control entered on `(0,1)` at parameter `1/2`, hence barycentrics `[1/2,1/2,0]`; direction `{-1,2,-1}` treated the already-zero third coordinate as outflow, giving exact winning exit time zero. Production correctly returned `BranchContinuationDegenerateEntry`.

- **CB-R11 correction:** only `tests/FieldAlignedCurveNetworkTests.cpp` changed. The positive-control direction is now `{-2,1,1}`, producing a positive exact `1/4` exit through `(1,2)`. The test explicitly asserts `EdgeExit`, outgoing `(1,2)`, and exact exit point `1/4`. The oversized exact-magnitude rejection remains unchanged; no production or GMP arithmetic semantics changed.
- **Build authority:** semantic source `267272d22f7de67ce7d8e368a53cc78a37ca3e8f`; compile run/job `33077493539 / 98535503386`; immutable GMP package `9648550565`, ZIP SHA-256 `1f0275e96fa75b7fc6fb447eaffb79b414c94230823da7897a4f2d91df33615c`; log `9648551415 / c7e4c83c6727117af6cdfc5874762d70dc4a8633cfe7e241e1e36ec001a83e2b`. All eight standard targets compiled/linked, preflight/build exit 0, gmpxx/gmp verified, clean source, `runtimeExecution=false`.
- **Focused TB-R11:** artifact-only run/job `33077761701 / 98536455697` consumed only package `9648550565`. The repaired identity selected **1/1 PASS**, exit 0, failures/errors 0, 39 ms harness elapsed; immutable package preflight/postflight PASS; no configure/compile/relink/repair/generated discovery/performance benchmark. Result `9648618375 / 469cab3ee5a541a5faa29fcdac2a6ff213ca202c8ff38522e131b0a9a4ba6113`; log `9648618836 / c15831693911134a4ab3eba6fa8060af8b95e85eac679d5374c632fcecdc908d`.
- **Disposition:** `M3-CP4c0-TB-R9-CAND-02` is **RESOLVED / NON-STABLE / TEST-SIDE FIXTURE-PRECONDITION**. Both TB-R9 candidates are now individually resolved. Stable totals remain **42 / 14 / 28**, debt **5**; M3 packages become **50**.
- **Boundary:** the last whole frozen 346 gate remains TB-R9 at **344/346**. Focused TB-R10/TB-R11 do not retroactively accept it; CP4c-0 remains OPEN pending whole-gate re-proof. No successor or CP4c-0b-CB1 entry is authorized automatically.

## 2026-08-27 — `M3-CP4c-0-CB-R10` + `M3-CP4c-0-TB-R10`: GMP portability defect corrected and focused re-proof PASS

At explicit user instruction, `M3-CP4c-0-TB-R9-REVIEW-PLAN` was **skipped, not completed**, and the turn proceeded directly to a bounded correction of `M3-CP4c0-TB-R9-CAND-01` only. The unrelated zero-time fixture candidate `CAND-02` was left unchanged.

- **CB-R10 correction:** only `tests/FieldAlignedCurveNetworkTests.cpp` changed. The `ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` test no longer depends on backend-specific `ENumber::to_double(18)` behavior; it constructs the intended exact `1/7` witness and performs an explicitly lossy numerator/denominator-to-double round trip inside the test before exercising the unchanged production exact predicate. No GMP/product arithmetic semantics changed.
- **Build authority:** semantic source `30ef2792e2915e0016dfd11f5fa2b3727e5503c0`; compile run/job `33067140968 / 98499967674`; immutable GMP package `9644214591`, ZIP SHA-256 `b9e7729fb557eddc203e38a1c11564bab3ad180982e10740d4374fe06748a390`; log `9644214963 / d88c8ff55082db4c27d377688af5400d08f40b329ec305b6538aacc1899201c2`. All eight standard targets compiled/linked, preflight/build exit 0, GMP 6.3.0 and both gmpxx/gmp link libraries verified, all source-status snapshots empty, `runtimeExecution=false`.
- **Focused TB-R10:** artifact-only run/job `33067370314 / 98500728780` consumed only package `9644214591`. The exact repaired identity selected **1/1 PASS**, exit 0, failures/errors 0, 5 ms harness elapsed; immutable package preflight/postflight PASS; no configure/compile/relink/repair/generated discovery/performance benchmark. Result `9644274456 / 4d80bc1ca8e9d0f624e709eb7c467e5b1c2c880d6a1619f1f8ced95151305693`; log `9644274922 / 2c8922ccf03e356db0e78fbe07a4a22bb99019009e4e40669f58bba16fcdd122`.
- **Disposition:** `M3-CP4c0-TB-R9-CAND-01` is **RESOLVED / NON-STABLE / TEST-SIDE GMP PORTABILITY**. Stable totals remain **42 / 14 / 28**, debt **5**; M3 packages become **49**.
- **Boundary:** focused TB-R10 is corrective evidence, not the full frozen 346-gate acceptance run. `M3-CP4c0-TB-R9-CAND-02` remains active and CP4c-0 remains OPEN. No further turn, including CP4c-0b-CB1, is authorized automatically by this closeout.

## 2026-08-27 — `M3-CP4c-0-TB-R9`: GMP artifact-only re-proof is VALID RED 344/346; independent review required

`M3-CP4c-0-TB-R9` executed the frozen 346-identity CP4c-0 gate from immutable GMP package `9634245265` (source `66325345567106fe7de8560ee2aee5f07ca665de`, package SHA-256 `4ef834465ee8db3110f40f7882cde4a39f94821b6bc0daba3ae0b0e04d7e5629`). Authoritative run/job `33048964354 / 98439563813`; result artifact `9636849182` SHA-256 `b485c1cfe5f929600bae382b1a01954b319dd4d1904e1dd1675cb2ad02771c57`; diagnostic artifact `9636849748` SHA-256 `9a23f1e9f8de5bb36086ed2ea1e20900cbb9cf53a940bc7c336a4ab2516d4023`.

- Frozen result: **344/346 PASS**, accepted first-316 **316/316**, first-328 **328/328**, Q8 criteria **1/4/5 PASS**, zero timeouts, zero escaping C++ exceptions, zero orchestration errors, immutable postflight PASS.
- The former TB-R8 pathological identity now passes in **102 ms** under CB9's deterministic cost guard.
- Ordinal 333 is recorded as `M3-CP4c0-TB-R9-CAND-01`, a non-stable **test-side GMP portability** candidate: its `to_double(18)` witness search depends on legacy decimal-digit truncation, whereas GMP uses `get_d()` and ignores the digit argument, so the test fails `found` before exercising production behavior.
- Ordinal 344 is recorded as `M3-CP4c0-TB-R9-CAND-02`, a non-stable **test-side fixture/precondition** candidate: the supposed narrow positive control has an exact zero-time exit, for which production correctly returns `BranchContinuationDegenerateEntry`.
- A preliminary control run `33048777701` failed only temporary payload digest verification before runtime; it is orchestration-only and carries no semantic credit.
- CP4c-0 remains **OPEN** because the full frozen gate is red despite its owned Q8 criteria being green. Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **48**.
- **Exact next:** independent `M3-CP4c-0-TB-R9-REVIEW-PLAN` only. No rerun, correction, or automatic CP4c-0b-CB1 entry before that review freezes the smallest corrective scope.

## 2026-08-27 — CP4c documentation consolidation: 28 documents to 9, no durable information removed

Documentation only. No product, test, fixture, selector, build-configuration, runtime or gate change; the CP4c-0 selector remains **346** with SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`.

Performed under explicit user authorization ("consolidate and cleanup CP4c historical docs and make sure information is deduplicated and retained in appropriate locations"), following `RETENTION_POLICY.md`'s required order: inventory the information at risk, define the exact authorized scope, verify the resulting diff against it.

- **19 documents retired into `M3_CP4c_Consolidated_Record.md`.** Tier 1 — 11 per-turn plans and reports (CB8, TB-R5/R6/R7/R8), whose evidence identities are now inlined in §3: package artifacts, ZIP and source-archive SHA-256s, run/job IDs, gate counts, and the exact TB-R8 failure (ordinal 338 at **853.437 s**, ordinal 343 incomplete, **342/343** completed, accepted prefix **316/316**). Tier 2 — the 7 independent reviews and the discharged D0–D5 DEFN charter, digested in a new **§3b** that preserves each review's finding, the amendment it produced, and the reviewer errors it owned.
- **The deduplication that made Tier 2 retirable:** each review's normative output is an amendment, and Amendments 1–11 are stated in full in `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` §10 — that document, not the review, is their authoritative home, so retaining both was duplication. Lessons had already moved to `LESSONS.md`; evidence identities are in §2–§3.
- **New §3b also carries a withdrawn-prediction table** — seven estimation errors across the arc, each with the turn that made it and the turn that falsified it — so the cost of each stays visible rather than being lost with the document that owned it.
- **New §3c maps every class of CP4c information to its single authoritative location**, matching `DESIGN.md` §1's authority table.
- **§5 rewritten** as a two-date retirement inventory with an explicit "retained, and why" table for the 9 surviving documents.
- **All inbound references repaired.** Live documents (`TODO.md`, `ROADMAP.md`, `Regression_Root_Cause_Tracker.md`, both frozen-definition records, the CP4c CB plan) now point at `M3_CP4c_Consolidated_Record.md` §3b. The CP4c-0 frozen definitions' amendment header, which had pointed at the retired review for the full amendment text, now correctly points at its own §10. `CHANGELOG.md` gained a provenance note identifying pre-2026-08-27 CP4c filenames as historical, which `CLEAN_UP_POLICY.md` permits.
- **Retained:** the three frozen-definition contracts (continuation, grazing, termination), the CB9 corrective record as current authority, all four selectors including the parent CP4c 322 selector that records which identities constitute C1–C6, and this consolidated record.
- **Verified after the edit:** every document in `RETENTION_POLICY.md`'s durable set is present; all seven `DURABLE, DO NOT DELETE` sections in the handoff are intact; no amendment, lesson, stable regression ID, artifact identity, unresolved blocker or acceptance criterion was removed.

## 2026-08-27 — `M3-CP4c-0b-DEFN`: checkpoint split; trace termination frozen; CP4c-0 freed to close

Independent definition/review/planning only. No Directional runtime, build, benchmark, or product/test/fixture/selector/build-configuration change. Record: `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md`.

- **CP4c-0 is split.** It was carrying two unrelated obligations under one gate — *how a trace continues* and *how a trace stops*. The first is finished and proved; the second was never scoped, was delegated to a citation whose assumptions do not hold here, and is what blocked TB-R8. **CP4c-0** keeps continuation and closes at gate **346** against Q8 criteria 1, 4 and 5. **CP4c-0b** opens and owns trace/trace contact, arrival priority, the contact node and event, and retirement of the CB9 stand-in guards.
- **Amendment 11** moves Q8 criteria **2** (24-trace sphere network) and **3** (terminal `TraceIntersection`) to CP4c-0b **together and unweakened** — they are one piece of work, since the six circulating traces are simultaneously what blocks 2 and what satisfies 3. Nothing green stays in limbo: CP4c-0 closes on its own evidence. `GrazingTraceSegmentsPublishExactEndpointSupport`, made non-gating by CB9's N7, becomes gating again in CP4c-0b's selector.
- **`DESIGN.md` §4.6 amended.** The motorcycle graph's termination guarantee assumes motorcycles walking edge chains of an *existing quad mesh*, where every step consumes an edge and non-termination is impossible by counting. A2a traces a piecewise-constant field on a triangle mesh with exact interior positions — a one-dimensional system that does admit limit cycles, one of which is exhibited on the sphere with an exactly contracting first-return map. Crash-on-contact still terminates it, but because the **perpendicular branch family** crosses it, not because the state space is finite. Also recorded: self-contact cannot be the stopping rule (same-branch segments are parallel by construction), and no mesh-derived **length budget** may terminate a trace (the longest correctly-terminating trace and one lap of a never-terminating trace measure the same length to four decimal places; and truncation leaves an arc that bounds no region).
- **Contact predicate frozen and it is not a design choice:** proper transversal crossing of two segments in one face, exact rational barycentric arithmetic, no new number type and no tolerance, tested against every segment already laid in that face by any trace including the trace's own. Shared singularity origins excluded; endpoint touches and collinear overlaps are typed observations rather than contacts.
- **Arrival priority frozen as `ArcLengthFiltered`** — double arc length with a **computed** forward error bound; a literal epsilon anywhere in that path is a stop condition. Exact arc-length comparison is excluded on complexity (comparing sums of *k* radicals is exponential in *k*, and *k* is the segment count), not on cost; the earlier cost objection is withdrawn because comparisons happen per event, not per step.
- **Ties need no arbitrary rule.** Same arrival at different points are independent events whose order cannot matter; same arrival at the same point means **both traces terminate there**, one node, canonical. This matters because the sphere's singularities are cube corners, so exact ties are *systematic* on symmetric input rather than rare. Port ID, lexicographic world coordinates, branch index and typed-rejection tie-breaks are each explicitly rejected with their defects recorded.
- **Alternatives harness retained but constrained.** `FieldTraceArrivalPriority { ArcLengthFiltered, StepCount, BarycentricTime, TraceSeniority }` preserves future performance/quality comparison, but `ArcLengthFiltered` is the only value the production entry path can produce: production takes no priority argument, alternatives are reachable only from a diagnostic entry point, an identity asserts production yields the default, and the choice is digest-bound. A production-reachable priority argument is a second writer of network topology and a stop condition.
- **CB9's N1/N2/N4 are demoted to backstops that must not fire**, with a per-witness identity. N1's allowance is calibrated on one witness and would trip where a legitimate separatrix winds several times; it retires only when an identity proves no witness reaches it.
- **Operator prerequisite recorded:** GMP is linkable in the current CMake configuration but is not fetched automatically on Linux; it must be installed and its root passed to CMake. CB1 must record which exact backend the package was built against.
- **Exact next: `M3-CP4c-0-TB-R9`** at gate 346 to close CP4c-0, then **`M3-CP4c-0b-CB1`** under measures **P0–P9**. The two are independent.

## 2026-08-27 — `M3-CP4c-0-TB-R8-REVIEW-PLAN` + `M3-CP4c-0-CB9`: non-terminating traces diagnosed; deterministic guards landed

TB-R8 was **INCOMPLETE / BLOCKED** — ordinal 338 failed after **853.437 s** with `gcd(): while running too long!`, and ordinal 343 never returned before user cancellation. Adjudicated and corrected in one turn at explicit user instruction. Record: `Architecture_M3_CP4c0_TB_R8_Review_And_CB9_Corrective_Record.md`, measures **N0–N7**. No Directional runtime, test, or benchmark was executed; compilation was verified per translation unit.

- **Root cause is three compounding defects, not a packaging flaw.** (1) Six of the prescribed sphere's separatrices **circulate forever** in a closed 32-state circuit — CB8's grazing transit correctly retired `BranchTransportFlowDisagreement`, which had been aborting the network at the first grazing edge and incidentally stopping every trace before any could circulate. (2) **Neither guard could see it**: the cycle guard keys on a state containing the exact position, which drifts every lap, and the step budget authorised **1,775,616** steps the arithmetic could never survive. (3) Exact values grow **~1.12 base-1e9 limbs per step** without bound and the fallback bignum answers by **throwing**; at ~step 205 Euclid passed its fixed 10,000-iteration cap and raised `std::runtime_error` out of a closed producer.
- **Reproduced from the committed fixtures alone**, no product code: of 48 candidate ports (a superset of production's 24), **42 terminate at a singularity** in ≤32 steps at ≤49 limbs, entering each `(face, branch, incoming carrier)` **exactly once**; **6 circulate**, lapping a 32-state circuit indefinitely. The two populations separate completely, with no overlap to threshold.
- **N1 — position-free combinatorial recurrence guard**, allowance **2** against a measured terminating maximum of **1**. New typed rejection `TraceCombinatorialRecurrenceExceeded` (29) publishing visit count and allowance. It is the weakest combinatorial form of crash-on-contact and is explicitly a stand-in.
- **N2 — deterministic exact-magnitude policy**, `kFieldExactContinuationMagnitudeBits = 4096`, checked before any exact arithmetic on the entry parameter. New typed rejection `BranchContinuationExactMagnitudeExceeded` (30). Not a tolerance: the producer declines to answer rather than answering approximately, and the width is a size that never enters a comparison. `magnitude_bits()` added to both `EInt` backends.
- **N3 — the bignum's three fixed `10000` iteration caps replaced by bounds derived from the algorithms' own worst cases** (Lamé for `gcd`, digit count for `trim`, range width for the quotient-digit search), so they fire only on a real implementation fault, never on a large legitimate operand.
- **N4 — the step budget becomes a provable envelope of N1**: `max(64, branchStates × 6 × allowance)`, six position-free entry modes per branch state. Sphere: **1,775,616 → 9,216**.
- **N5 — `FieldAlignedCurveNetwork::make` is closed against any escaping exception.** A2a is a closed producer (`DESIGN.md` §6.5) including against its dependencies' failure modes.
- **N6 — four falsifying identities**; **N7 — `GrazingTraceSegmentsPublishExactEndpointSupport` becomes non-gating** because it requires a published sphere network this checkpoint cannot deliver; its transit contract stays proved by three gating unit identities.
- **Simulated result:** 42/42 legitimate traces unchanged with the same terminal singularities; 6/6 runaways stopped at step 65; worst exact width **19,460 bits → 2,684 bits**.
- **Selector 343 → 346**, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`. Accepted first-316 and first-328 prefix hashes recomputed and **byte-identical**.
- **`DEFN-2` §9.2's cube-graph prediction is WITHDRAWN.** It predicted every sphere trace terminating at a singularity; 42 of 48 do and 6 circulate. A cube-symmetric singularity set does not force every separatrix to run corner-to-corner. §9.3's Q8-criterion-3 response is unaffected.
- **Dependency inversion recorded.** Crash-on-contact — `DESIGN.md` §4.6's structural termination guarantee — is **not implemented** by A2a. It is C4/C5 in CP4c-1, which is blocked on CP4c-0, so **Q8 criterion 2 is not reachable within CP4c-0 as scoped.** `M3-CP4c-0-DEFN-3` must choose between reordering C4/C5 and re-scoping the 24-trace network.
- New candidate **`M3-CP4c0-TB-R8-CAND-01`** (non-terminating traces, product semantics, guarded but unresolved). Stable accounting remains **42 / 14 / 28**, debt **5**, packages **47**.
- **Exact next: `M3-CP4c-0-TB-R9`** on the 346 selector, then **`M3-CP4c-0-DEFN-3`**.

## 2026-08-27 — `M3-CP4c-0-CB8`: frozen grazing-edge transit implemented; compile-only BUILD GREEN

`M3-CP4c-0-CB8` is **COMPLETE / BUILD GREEN**. Code + Build only; no Directional runtime, GoogleTest identity, semantic benchmark, performance benchmark, generated discovery, CLI, fuzzer, or custom input executed.

- Semantic source `19ba8e9c5e58f9c33c14b309841165d3f0401db5` implements only frozen DEFN-2 L0–L9: exact target-face `Inflow/Tangent/Outflow` classification, one-hop grazing edge transit, typed ambiguous-slide failure, `FaceInterior`/`EdgeTransit` arrival mode, scale/arrival invariance coverage, non-gating multiplicity census, exact `edgeTransitExit`, bounded selector migration, and corrected K2 production continuation walk. L9 prohibitions are preserved.
- Authoritative compile-only run `33025705457`: preflight job `98366398970` and full package job `98367264215` both succeeded. All eight standard targets compiled/linked; preflight/build exit 0; source-status snapshots empty; `runtimeExecution=false`.
- Immutable package `9628445643` / `869e06a3524ecdb7fd901e2583d5ba5c60309cce3085e2e1996a37ddd780bce6`; packaged semantic-source archive `98e7db71647a54f41edfd93aea56ef7f50e014989bbc3c617edc179791380d5d`; compile log `9628446136` / `562bb275fccb61629a3a60bfd1f71c3cb8332a239674dab660ebcd1626f33d27`.
- CP4c-0 required-green selector is now **343** / `63ca177e8c0f22a83085cfb1028915b444db67bf2bb3da79555e4a3033a74d09`. Accepted first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` and prior first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600` are preserved. One retired flow-rejection identity was reauthored and five new L2/L3/L4/L6 identities added; the old 338 full-file hash is therefore not claimed preserved.
- No CB8 runtime semantics or Q8 criterion are claimed. Latest accepted runtime remains CP4ab **316/316**. Stable accounting remains **42 / 14 / 28**, debt **5**, packages **47**.
- **Exact next:** artifact-only `M3-CP4c-0-TB-R8` on package `9628445643` under `Architecture_M3_CP4c0_TB_R8_Artifact_Only_Test_Benchmark_Plan.md`.

## 2026-08-26 — `M3-CP4c-0-DEFN-2`: the `DESIGN.md` §4.5 grazing gap is closed; grazing edge transit frozen

`M3-CP4c-0-DEFN-2` is **COMPLETE**. Independent definition/review/planning only: no Directional runtime, build, benchmark, configure, compile, relink, generated discovery, or product/test/fixture/selector/build-configuration change. Committed fixtures and source were read and arithmetic was performed on their contents; nothing was executed and no product artefact was modified.

- **Chosen model: grazing edge transit** (`Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md`, now normative §4–§11). A carrier's relation to the face a trace is about to enter is a **three-way classification** read from that face's published `direction` at the coordinate opposite the carrier — `> 0` `Inflow`, `== 0` `Tangent`, `< 0` `Outflow` — never from carrier-set membership, which cannot separate `Tangent` from `Outflow`. `Outflow` on both sides means the trace neither crosses nor stops: it **transits along the edge** to the endpoint both faces drive the published parameter toward, then re-enters the existing T2/T3 vertex dispatch.
- **The transit target is an exact sign predicate on already-published authority.** With `e` canonical and `β` the index of `e.second()` in each face's sorted key vertices, the rates are `r_X = d_X[β_X]` and `r_Y = d_Y[β_Y]` — literally the rates at which each face drives the `FieldBoundaryPoint` parameter, because `field_boundary_point_from_barycentric` builds that parameter as exactly that coordinate. Both positive selects `e.second()`, both negative selects `e.first()`, anything else is the new typed rejection `BranchGrazingSlideDirectionAmbiguous`. No tolerance, threshold, or magnitude comparison participates.
- **The choice was decided on structure, not on cost data.** DEFN-2 §5.4 proves the rule is the **unique continuous extension of Amendment 3**: at exact tangency the frozen rule already slides along the edge and selects the same endpoint by the same expression. A grazing terminus would be discontinuous across a measure-zero configuration and would forfeit Q8 criterion 2; a refinement precondition would reject every non-degenerate witness the project owns, two of them already accepted; a general edge-following mode is unnecessary because the directions are constant per face, so the transit provably completes in **one hop**.
- **`BranchTransportFlowDisagreement` is retired from production emission**; enum value 25 is retained and never reused. `Tangent` carriers must now enter the target face and reach Amendment 3's vertex exit — the present membership test mis-rejects them alongside grazing.
- **A1 is not touched.** Every datum the rule reads is already published, `branch_topology_digest` does not move, and the grazing relation is derived on demand and never stored. T6 stays frozen and stays unreachable. No new `FieldAlignedNetworkEventKind` is added, so CP3b's terminal-kind exhaustivity assumption is untouched.
- **Evidence re-derived independently from the committed fixtures alone** — no product code: prescribed sphere **72** grazing configurations on **72 distinct** edges, torus **120** of 864 `(edge, branch)` pairs; ratio median `0.021788` / max `0.200424` and `0.074604` / `0.102869` respectively, matching TB-R7's runtime K1 figures to six decimal places. **Slide-direction ambiguity: 0 of 192** — zero sign disagreements, zero zero-rates.
- **The live locus resolves.** Sphere edge `6-8`, source `(6,8,9)`, target `(6,8,97)`: both parameter rates positive, transit to **vertex 8**, which the fixture's `fieldmeta` lists as a **singularity** — the trace terminates by **T3 `SingularityTermination`**. The eight singularities are exactly the corners of an inscribed cube, `(±1, ±1, ±1)/√3`, with **3** grazing edges each; the grazing edges lie in narrow corridors along the field's separatrices.
- **Q8 is NOT amended.** Criterion 2 is expected to pass. Criterion 3 (`TraceIntersection`) is predicted **not** satisfiable on the prescribed sphere, because a cube-corner separatrix network pairs singularities and never self-contacts. §9.3 pre-commits the response — do not weaken the criterion, do not relabel a termination as a contact, do not add a witness to CP4c-0 — and re-homes the question to **CP4c-1**, which needs a witness whose separatrices do not pair singularities.
- **K2's null result is explained and voided.** `cp4c_sphere_grazing_cost_census` walks traces with the **retired Cartesian carrier lookup** deleted by `M3-CP4c-0-DEFN` §5.1, carries no position, and stops on the first `1×2` face — which on a 50%-`1×2` witness is step 1 for all 24 traces. Recorded as `M3-CP4c0-DEFN2-CAND-01`, test-side, non-stable, owned by measure L8. It supplies no evidence about any grazing model.
- **`DESIGN.md` §4.5 extended** with the grazing paragraph and its four load-bearing properties; **Amendment 10** added to `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`; four durable lessons added to `LESSONS.md`.
- Stable accounting remains **42 / 14 / 28**, debt **5**, packages **46** — this turn executed nothing. Frozen CP4c-0 gate remains **338**; CB8 recomputes it as `338 + n`. The CP4c-1 **318** selector is unchanged.
- **Exact next: `M3-CP4c-0-CB8`** — Code + Build only, runtime forbidden, measures **L0–L9**. Then `M3-CP4c-0-TB-R8`.

## 2026-08-26 — `M3-CP4c-0-TB-R7`: artifact-only evidence valid; near-tangency reproduced; DEFN-2 next

`M3-CP4c-0-TB-R7` is **COMPLETE / VALID SEMANTIC RED**. Authoritative control/run/job `3d1ef24d6bcccb7e4e821d713a21860bc0598bd0 / 33019554121 / 98346293968` consumed only CB7 package `9625495708`. Result artifact `9626003625` hashes to `61994abc1e67fc55bc1d48d38a521598b6b56e458972d948ebcae112fa27eaaa`; diagnostic log `9626004016` hashes to `9f6307b90b93ba557af7643c5a2d4a021969708b2a77e74fc546ae4f263e441c`.

- K6 preflight used ordinary `unzip`/`tar`, preserved all six executable modes at `0755`, attempted no permission repair, and re-verified all 27 package hashes, exact semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c`, the three frozen selector hashes, and sphere fixture identity.
- Frozen gate **338/338 PASS**, accepted **316/316**, first-328 **328/328**, F3 **2/2**; 345 fresh processes; zero orchestration errors; postflight immutable.
- K1 reproduces the near-tangency regime. Sphere: 144/2304 disagreements, median min-ratio `0.021788`, max `0.200424`, agreeing median `0.915773`; all legitimate disagreements on sphere/two-ring/torus have both opposite coordinates ranked smallest. No material falsification of the independent-review prediction occurred.
- K2 is non-decisive: **0/24** traces reach a grazing observation, every trace reports one traversed edge, and no consecutive grazing evidence exists. This misses P3 but is a diagnostic limitation, not a product regression, and provides no basis to choose among the four frozen grazing models.
- J3 is correctly relabeled as a principal-matching implementation cross-check and remains legitimate **524/524**. Independent K3 vertex-fan holonomy covers **176/176 complete fans with 0 mismatches**.
- G5 remains the same sphere `BranchTransportFlowDisagreement`; Q8 is **CREDITABLE / RED at criterion 2**; criterion 3 not evaluable, criterion 4 pass, criterion 5 carried unchanged.
- Stable accounting remains **42 / 14 / 28**, debt **5**, packages **46**. Exact next is definition-only **`M3-CP4c-0-DEFN-2`**; no production fix or CP4c-1/2/3 entry is authorized.

## 2026-08-26 — `M3-CP4c-0-CB7`: K-series grazing diagnostics implemented; compile-only BUILD GREEN

`M3-CP4c-0-CB7` is **COMPLETE / BUILD GREEN**. This was Code + Build only; no Directional runtime, GoogleTest identity, semantic benchmark, performance benchmark, generated discovery command, CLI, or fuzzer executed.

- Final semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c` implements only review-authorized **K0–K7** diagnostic/contract-control work: K1 publishes exact per-face tangency ratios, dyadic angle proxy and opposite-coordinate rank distributions; K2 publishes the prescribed-sphere grazing continuation-cost census; K3 relabels J3 as a principal-matching implementation cross-check and adds the independent vertex-fan holonomy census; K4 removes owner labels from H1's grazing classification; K5 records the piecewise-constant discretization assumption; K6 freezes mode-preserving artifact extraction; K7 freezes TB-R7 → `M3-CP4c-0-DEFN-2`. **No production semantics, fixture, selector, tolerance, T6, or Q8 contract was changed.**
- One compile-only diagnostic implementation defect was found on source `6341b13c708f98208eece40dcccea5806a97b0c7`: `DomainResult<SourceVertexId>` was dereferenced with `*sourceVertex` even though the wrapper exposes `.value()`. The bounded one-line repair produced final semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c`; no diagnostic meaning changed.
- Authoritative compile-only run/job `33018117005 / 98341565781` compiled and linked all eight standard targets from exact source `077462da156c3e2dfbbc6867fc10d3e4442d853c`. Preflight and full build exit codes are `0`; every packaged source-status snapshot is empty; the package records `runtimeExecution=false` and `turnBoundary=Code+Build-only`.
- Immutable result/package artifact `9625495708` has GitHub ZIP SHA-256 `dc07d4288b9a529ca71c06f96e0277b168d2e5a28c5a9eeba3fdf7341a33237a`. Its packaged source archive has SHA-256 `6ecafbc5a5904568780e6518f39b9d4b1336c94e08a53f7fc0c31d8926e26344`. Compile-log artifact `9625496280` has ZIP SHA-256 `e42240c280738fd70e8eddc09bc9899537cac53f477e3d3f88d26f6b4a0a978f`.
- Frozen selector hashes are unchanged: 338 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`, first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`, first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.
- Stable regression accounting remains **42 / 14 / 28**; produced-witness debt **5**; M3 packages **46**. Latest accepted runtime remains CP4ab **316/316**.
- **Exact next:** artifact-only `M3-CP4c-0-TB-R7` on package `9625495708`. Q8 is still expected to remain red at criterion 2; after a valid TB-R7, the frozen successor is `M3-CP4c-0-DEFN-2`.

## 2026-08-26 — `M3-CP4c-0-TB-R6-REVIEW-PLAN`: root cause identified — near-tangency, not an A1 defect; Amendment 9

**Independent review and planning only. No runtime, build, benchmark, product source, test source,
fixture, selector, or build-configuration change.** Evidence, source and fixtures were *read* and
arithmetic performed on their contents; nothing was executed and nothing was modified.

- **Evidence independently verified:** TB-R6 run `33006282429 / 98300813772`, control SHA `a9ae3075…`,
  result `9620769314` / `fe6a7317…`, diagnostic `9620770049` / `ce87da5a…`, CB6 package `9619352525`,
  semantic source `8b8d1897…`. All three selector hashes recomputed locally. **Both TB-R5-review
  predictions confirmed to the digit**: the fan artifact at 2 directed / 1 distinct, and the corrected
  legitimate population at 388 / 194.
- **Root cause identified: a near-tangency discretization phenomenon.** The review reproduced the
  sphere's census from the committed `.obj` and `.rawfield` alone — no product code — and obtained
  **exactly 144 directed disagreements**, matching runtime. Tangency ratio `min(|d_opp| / max|d|)`:
  disagreeing **median 0.0218, max 0.2004** (n=144); agreeing **median 0.9233** (n=1008). A 42×
  separation. The direction runs nearly parallel to the shared edge; the field's rotation across it
  (≈ 23°) flips the small perpendicular component; **both faces correctly compute "outflow"**.
- **Every published term at the live locus is correct**, each independently verified: `matching = 0` is
  geometrically right (nearest target raw index **23.7°**, next **66.3°** — not aliasing);
  `0 + 1 − 3 ≡ 2` reproduces the published lift; both gauges map to raw index 0; both `dbary` triples
  reproduce **to 10 decimal places**; all 288 interior edges are normal adjacency, none folded.
  **There is nothing in A1 to fix.**
- **`Amendment 4` / measure `E5` is the defect.** It asserts a **continuum** property that a
  piecewise-constant field does not satisfy near edge tangency. **Amendment 9** corrects it:
  `BranchTransportFlowDisagreement` is a **typed grazing observation**, not an invariant violation; no
  production correction may be authorized from it; **no tolerance may be used to classify grazing** (the
  distributions overlap); and every cross-stage invariant on discrete data must state its discretization
  assumptions.
- **The substantive open question is a model gap:** `DESIGN.md` §4.5 does not define what a trace does at
  an edge the neighbouring face's direction also exits. Four candidate models are framed and **none
  chosen** — that is a `-DEFN` obligation.
- **Three prior readings withdrawn.** The live locus does **not** indict `build_branch_transports`
  (its composition is arithmetically correct); there are **not two classes** (the unequal-gauge and
  equal-gauge/lift-0 populations are one phenomenon — the "lowest common invariant" the TB report asked
  for); and **J3's 524/524 does not exclude H-B**, because `independent_edge_measurement` re-implements
  **principal matching**, the algorithm H-B suspects. H-B is excluded, but by direct measurement.
- **Reviewer errors owned:** the TB-R4 "geometrically impossible" claim and its magnitude-versus-ratio
  reasoning; the J3 specification, which named principal matching as its own oracle; and the TB-R5
  decision-table rows that attached owners to one geometric regime.
- Corrective series **K0–K7** frozen for **`M3-CP4c-0-CB7`**, **diagnostic-only**, followed by
  **`M3-CP4c-0-DEFN-2`**. K1 establishes the tangency separation at runtime; K2 measures each candidate
  model's cost; K3 retires J3's aliasing claim and adds a holonomy oracle; K4 strips the misleading owner
  labels; K6 fixes the staged-payload transport, which has cost two consecutive cycles.
- **Q8 remains RED at criterion 2** — fourth consecutive cycle, but for the first time the reason is a
  known contract gap rather than an unknown defect.
- Stable accounting unchanged at **42 / 14 / 28**; produced-witness debt **5**; M3 packages **45**.
- Record: `Architecture_M3_CP4c0_TB_R6_Independent_Review_Record.md`.

## 2026-08-26 — `M3-CP4c-0-TB-R6`: 338/338 green; J3 clears legitimate matching; Q8 remains semantic red

`M3-CP4c-0-TB-R6` is **COMPLETE / VALID SEMANTIC RED**. Artifact-only Test + Benchmark; no configure, compile, relink, repair, generated discovery, performance benchmark, or source/test/fixture/selector/package mutation.

- Sole semantic run/job `33006282429 / 98300813772`, control `a9ae307590b0cc23080452c4a5013674efc48fc2`, consumed immutable CB6 package `9619352525` at semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`. Result `9620769314 / fe6a73175399b764f7cbb3ea2963a8deb40d6d0b5afcc3e9a603102ee4936684`; diagnostic `9620770049 / ce87da5a919e31f7e36a8d904dfaad7c7d9c92b9bebf36a494de096e7cb691cb`; postflight PASS.
- Frozen selector **338/338 PASS**, accepted **316/316**, first-328 **328/328**, F3 **2/2**. G5/H1/J3 PASS/non-gating. Q8 is CREDITABLE / RED at criterion 2; sphere still rejects `BranchTransportFlowDisagreement` at edge `6-8`, branch `3→1`, lift 2.
- H1/J1 reproduces corrected legitimate population **388 directed / 194 distinct**, excluding the fan's 2/1 fixture artifact. Legitimate decomposition: matching-nonzero 48/24; matching-zero unequal-gauge 86/43; matching-zero equal-gauge lift-zero 254/127.
- J3 independently proves **524/524 legitimate interior transitions agree with geometry**; only the excluded fan edge `1-4` disagrees. Thus current legitimate H-B matching aliasing is not supported. Live edge `6-8` has `matching=0`, raw gauges `1→3`, lift 2, selecting the frozen A1 gauge-composition row; the 254/127 equal-gauge residual selects the boundary-pairing flow-classification row.
- First control attempt `33006048971 / 98300014224` is resolved orchestration/non-stable: Python ZIP extraction lost executable modes and the first binary launch failed before Directional runtime. Retry changed only extraction to ordinary `unzip`; no chmod/package repair.
- Stable regressions remain **42 / 14 / 28**, debt **5**, M3 packages **45**. Exact next: independent `M3-CP4c-0-TB-R6-REVIEW-PLAN`; no production correction before review.

## 2026-08-26 — `M3-CP4c-0-CB6`: J-series diagnostics implemented; compile-only BUILD GREEN

`M3-CP4c-0-CB6` is **COMPLETE / BUILD GREEN**. This was Code + Build only; no Directional runtime, GoogleTest identity, semantic benchmark, or performance benchmark executed.

- Semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6` implements only review-authorized **J0–J7** diagnostics/hygiene. J1 decomposes H1 disagreements into declared matching + source/target raw gauges + published lift and records singular incidence/distinct counts; J2 explicitly excludes the synthetic fan from production-reasoning totals without editing its field; J3 adds an independent matching-versus-geometry census; J4 publishes matching provenance; J5 pins staged payload bytes against line-ending normalization; J6 restores review naming; J7 freezes TB-R6. **J0's no-production-semantics-change rule is preserved.**
- Authoritative compile-only run/job `33002848081 / 98288918300` compiled and linked all eight standard targets from exact source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`. Preflight and build exit codes are `0`; every packaged source-status snapshot is empty; the package records `runtimeExecution=false` and `turnBoundary=Code+Build-only`.
- Immutable result/package artifact `9619352525` has GitHub ZIP SHA-256 `b45306c3c5b3b9ff094131be8073aed5c6180533fdbe0b04f220ca929b4dd672`. Its packaged source archive has SHA-256 `308e02580033b5a319e08d7916afc921693d2b15f645813c2cdbaed336320093`. Compile-log artifact `9619353059` has ZIP SHA-256 `1b2a0ffc9889305ca6a2efa847a2442c941583df01ad94c4c12226aea47be4c4`.
- Frozen selector hashes are unchanged: 338 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`, first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`, first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.
- Stable regression accounting remains **42 / 14 / 28**; produced-witness debt **5**; M3 packages **45**. Latest accepted runtime remains CP4ab **316/316**.
- **Exact next:** artifact-only `M3-CP4c-0-TB-R6` on package `9619352525`. Its purpose is to fill the frozen J1/J3 owner decision table; Q8 is expected to remain red at criterion 2.


## 2026-08-26 — `M3-CP4c-0-TB-R5-REVIEW-PLAN`: the census is sound, its population is not; Amendment 8

**Independent review and planning only. No runtime, build, benchmark, product source, test source,
fixture, selector, or build-configuration change.** Evidence, source and fixtures were *read* and
arithmetic performed on their contents; nothing was executed and nothing was modified.

- **Evidence independently verified:** TB-R5 run `32994846466 / 98261255799`, control SHA `3f9864fd…`,
  result `9616160533` / `1ecfd85f…`, diagnostic `9616161522` / `7cb10cae…`, CB5 package `9601160869`,
  semantic source `cd2ffb74…`. All three selector hashes recomputed locally and unchanged. The census's
  own coverage arithmetic (`pairsChecked = interiorEdges × 8`) was re-derived from mesh topology for all
  four witnesses and is correct.
- **H1's mechanism is correct**, verified in source: it iterates published `transports()`, applies
  `directed->signedLift` through `sourceBranch.rotated(...)` (Amendment 7 compliant), and compares exact
  `d[opp]` against exact zero on each face's own canonical key.
- **H1's population is not.** The **four-triangle fan's 2 violations are a fixture artifact**, proved by
  arithmetic. Its census field is `make_index_one_singularity_field`, which leaves the direction vectors
  **globally constant** (+X/+Y on every face) and merely *imposes* `matching = ±1` on one edge. For the
  violating edge `1-4` the published lift is **exactly correct** — `matching(+1) + g_source(0) −
  g_target(1) = 0` — and the disagreement is forced by a matching that contradicts the geometry. One edge
  × two directions predicts **exactly the 2 observed**; both reported `−1/2` derivatives were reproduced
  by hand; and a counterfactual with the gauge correction absent would give **8**, not 2.
- **The standing inference that the fan weakens H-B is withdrawn.** The fan's matching is not merely
  "prescribed rather than computed" — it is prescribed **inconsistently with its geometry**, so it bears
  on nothing about production.
- **The lift histogram is uninformative about matching.** `signedLift = matching + g_src − g_tgt` is a
  sum of three unobserved terms. Further, the ±1/±2/±3 tail symmetry is **imposed by the census's own
  two-direction loop**, not by the field, so every count is doubled. **Distinct disagreements: two-ring
  2, fan 1 (artifact), sphere 72, torus 120 — corrected population 388 directed / 194 distinct** over
  three legitimate witnesses. The two-ring's field genuinely rotates 90° around its centre and is a
  legitimate witness.
- **H-A and H-C independently re-confirmed excluded**; the ~50 % uniform-index branch unsupported.
  **H-B undecided and undecidable as currently instrumented.** (H-A was the TB-R4 reviewer's own favoured
  candidate; the census falsified it — the discipline of measuring before fixing paid for itself.)
- **Amendment 8** issued: the cross-edge flow invariant **audits A1's input matching** as much as its
  composition; its firing implicates one of {input matching, gauge composition, flow classification} and
  is **not by itself evidence of an A1 code defect**; a witness with imposed matching must be excluded
  from or explicitly classified within any production-reasoning population; and a two-direction census
  must publish distinct counts alongside directed ones.
- Corrective series **J0–J7** frozen for **`M3-CP4c-0-CB6`**, Code + Build, **diagnostic-only**. **J1**
  decomposes the lift into its three terms so the review's §7 decision table names the owner
  unambiguously; **J2** quarantines the synthetic-field witness without editing it; **J3** adds an
  independent matching-versus-geometry check; **J5** pins the staged control payload to LF so the
  self-hosted transport stops failing on line-ending normalization; **J6** restores the brief/review
  naming convention. **J0 forbids any production semantics change.**
- **Q8 remains RED at criterion 2** and is expected to stay red — third cycle in which that must be said
  explicitly.
- Stable accounting unchanged at **42 / 14 / 28**; produced-witness debt **5**; M3 packages **44**.
- Record: `Architecture_M3_CP4c0_TB_R5_Review_Plan_Independent_Review.md`.

## 2026-08-26 — `M3-CP4c-0-TB-R5`: 338/F3 green; H1 proves sparse A1 disagreement; Q8 remains red

Artifact-only TB-R5 is **COMPLETE / VALID SEMANTIC RED**. Sole semantic authority is hosted run/job `32994846466 / 98261255799`, control `3f9864fddef696dc7d95084fdd41b680a78f5b37`, consuming immutable CB5 package `9601160869` (`143cab907b4086a3f3bfc6f29dfdbb103919c9429698b0cce0757ae16f36cefb`) at semantic source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e`. Result `9616160533` has ZIP SHA-256 `1ecfd85f06b40466f0e8193d1603950cd93b120723568024a1b50595e9902ad8`; diagnostic `9616161522` has `7cb10caee2f1e861368da3098e320f10bee3b13d51439bc868e1e3c60aa14b0e`.

- Frozen selector **338/338 PASS**, accepted prefix **316/316 PASS**, first-328 **328/328 PASS**, `first_red_ordinal=0`; F3 **2/2 PASS**; G5 PASS/non-gating.
- H1 PASS/non-gating: **390/4224** A1-only cross-face pair disagreements (**9.23295%**), classifier `H-B_OR_OTHER_SPARSE_REVIEW_REQUIRED`. Witnesses: two-ring `4/160` (2.5%, all lift 0), fan `2/32` (6.25%, all lift 0), sphere `144/2304` (6.25%; lift 0 dominates 102), torus `240/1728` (13.8889%; lift 0 dominates 184). Sphere/torus also have symmetric ±1, ±2 and ±3 violations.
- **H-A excluded:** disagreements are not odd-lift-only and are mostly `signedLift=0`. **H-C excluded:** A1 census is not zero. The ~50%/uniform systematic-index branch is unsupported. H-B matching aliasing remains plausible but is **not yet proved**, especially because the manually prescribed fan has two lift-0 disagreements despite computed matching aliasing not being live there.
- G5 still publishes the sphere `BranchTransportFlowDisagreement` at edge `6-8`, source face `6-8-9` branch 3 → target `6-8-97` branch 1, `signedLift=2`; H3 now preserves the seven ordered trace steps leading there.
- Q8 is **CREDITABLE / RED at criterion 2**; criterion 1 PASS, criterion 3 NOT_EVALUABLE, criterion 4 PASS, criterion 5 carried unchanged/not rerun. This is the expected persistence of the same CP4c-0 candidate after a diagnostic-only CB5, not a new stable regression.
- Postflight package/source/fixture/selector/producer-executable inventories are byte-identical and manifest-post is 27/27. No configure, compile, relink, repair, generated discovery, package/fixture/selector mutation, or performance benchmark occurred. Fresh semantic processes: **342**.
- GitHub-hosted Actions outage caused delayed control triggers. Owner-authorized self-hosted attempts `32993852779` and `32994482392` failed before runtime at immutable payload SHA verification because checkout line-ending normalization changed shell bytes. They are orchestration-only; hosted `32994846466` is the sole TB-R5 authority.
- Stable accounting unchanged at **42 / 14 / 28**; produced-witness debt **5**; M3 packages **44**. Exact next: independent **`M3-CP4c-0-TB-R5-REVIEW-PLAN`**, review/planning only.


## 2026-08-26 — `M3-CP4c-0-TB-R4-REVIEW-PLAN`: gate green, Q8 creditable and red; symptom proved, mechanism withheld; CP4c docs consolidated

**Independent review and planning only. No runtime, build, benchmark, product source, test source,
fixture, selector, or build-configuration change.** Committed fixtures were *read* and arithmetic was
performed on their contents; nothing was executed and nothing was modified.

- **Evidence independently verified:** TB-R4 run `32928381384 / 98055727654`, head SHA `bb21207f…`,
  result `9592385698` / `6ffe56ef…`, diagnostic `9592386266` / `669e51f2…`, CB4 package `9591540182`,
  semantic source `de291a17…`. All three selector hashes **recomputed locally** and unchanged.
- **Four programmes demonstrably worked.** The frozen gate is **338/338 GREEN**, F3 **2/2**, G5 **PASS**,
  and **Q8 became creditable for the first time**. E2–E5 removed the degenerate-entry family (identity
  338 green); E1/F1–F3/G5 made the sphere's rejection observable; F6 continue-and-observe produced a
  complete picture; and E5's `BranchTransportFlowDisagreement` typed the condition. **The failure moved
  from a symptom to a cause** — and it is exactly **route A**, which the first CP4c-0 review named and
  found entirely unasserted.
- **Q8 RED at criterion 2**, as predicted (TB-R3 review P4). The sphere publishes no network.
- **Symptom proved exactly.** Decoding the six exact rationals in the G5 payload: source face `6-8-9`
  has `d[2] = −1.0035357904` for edge `6-8` ⇒ **Outflow**; target face `6-8-97` has
  `d[2] = −0.5769964399` ⇒ **also Outflow**. Both triples sum to exactly zero. **A continuous direction
  cannot exit a shared edge from both sides.** Magnitudes ~1.0 and ~0.58 are three orders above any
  epsilon here, so the tolerance-band explanation is **excluded**. The physically correct target branch
  is **`3`** (`d[2] = +0.5769964399`, Inflow) — the published lift is off by **2, a full reversal**.
  The source face is a genuine `1×2`, so CP4c-0's min-ratio rule chose the exit edge correctly.
- **Mechanism deliberately not guessed, and a tempting hypothesis refuted.** Per-face canonical-normal
  parity was formed, tested and **refuted**: the two faces do have opposite canonical parity, and parity
  mismatch covers **86.8 %** of the sphere's interior edges (torus 92.6 %, mechanical 90.2 %) — but the
  gauge is an **index shift** and cancels in `matching + g_X − g_Y` regardless of frame. Two supporting
  assumptions were also excluded: the `{primary, secondary, −primary, −secondary}` reconstruction
  reproduces the stored rawfield ordering **exactly**, and `v1` is `+90°` CCW from `v0` about the mesh
  normal in **all 192** faces. The refutation is recorded so it is not re-derived.
- **Three candidates survive** — matching sign/direction convention (fits an off-by-2 exactly; edge
  `6-8` touches singular vertex 8), matching aliasing (`DESIGN.md` §4.1), or a wrong branch carried by
  A2a — **and one measurement separates all three**: a non-gating cross-face flow-agreement **census**
  over A1 authority alone.
- **Durable caveat recorded:** a green accepted **316** is **not** evidence that cross-face transport is
  correct. No accepted identity asserts that invariant — E5 created it in CB2. If the census returns
  violations at a material rate, some accepted traces may be wrong and were never checked: a
  pre-existing defect newly detectable, not a CP4c-0 regression.
- Corrective series **H0–H7** frozen for **`M3-CP4c-0-CB5`**, Code + Build, **diagnostic-only**. **H5
  makes "do not change production" an explicit measure** — a sign flip on one failure site with the
  census unrun would be a fixture-shaped guess at global authority. The `first_red` postflight defect is
  control-plane only and must not trigger a semantic rerun (H6).
- **CP4c documentation consolidated** under explicit user authorization: twenty-four per-turn execution
  documents and superseded review briefs retired into **`M3_CP4c_Consolidated_Record.md`**, preserving
  every evidence identifier — source SHAs, run/job IDs, package and artifact digests, selector hashes,
  and gate results — for CP4c parent, CP4c-0 and CP4c-1. **33 CP4c documents → 12.** Retained live: the
  CP4c-0 DEFN charter and frozen definitions, the five independent reviews (Amendments 1–7; series
  E/F/G/H), and all selector `.txt` files. Every citation naming a retired document was repointed at the
  consolidated record — **retired provenance, not lost authority**. CP4c-0 and CP4c-1 remain **OPEN**;
  the record is historical and closes nothing.
- Stable accounting unchanged at **42 / 14 / 28**; produced-witness debt **5**; M3 packages **43**.
- Record: `Architecture_M3_CP4c0_TB_R4_Review_Plan_Independent_Review.md`.

## 2026-08-26 — `M3-CP4c-0-TB-R4`: 338 gate green; creditable Q8 exposes sphere flow disagreement

Artifact-only TB-R4 is **COMPLETE / VALID SEMANTIC RED** on run/job `32928381384 / 98055727654`, consuming immutable CB4 package `9591540182` (`8a93b553…c561f`) at semantic source `de291a17…`. The unchanged frozen selector is **338/338 PASS**, accepted **316/316 PASS**, prior CP4c-0 **328/328 PASS**, F3 **2/2 PASS**, and G5 **PASS / non-gating**. Ordinals 333/334 are green under the prescribed test-side corrections, closing the TB-R3 fixture/oracle candidates with no production change.

Q8 is creditable and **RED at criterion 2**. G5 publishes the prescribed sphere's exact A2a outcome: `BranchTransportFlowDisagreement` on edge `6-8`, source face `6-8-9` branch `3`, related face `6-8-97` branch `1`, trace seed vertex/singularity `0/0`. This confirms P4's predicted remaining Q8 red while replacing the prior observability gap with a concrete non-stable semantic candidate for independent review.

Result `9592385698` has SHA-256 `6ffe56ef…60643`; diagnostic `9592386266` has `669e51f2…ac3cb`. A postflight reporting shell used `first_red` instead of persisted `first_red_ordinal` after semantic execution and integrity inventories, so the workflow badge is red; preserved pre/post inventories compare equal and manifest-post is 27/27. The control failure is orchestration-only and does not authorize semantic rerun. Stable accounting remains **42 / 14 / 28**, debt **5**, packages **43**. Exact next: independent **`M3-CP4c-0-TB-R4-REVIEW-PLAN`**; no corrective CB before adjudication.

## 2026-08-26 — `M3-CP4c-0-CB4`: test-side oracle correction build green

`M3-CP4c-0-CB4` is **COMPLETE / BUILD GREEN** at semantic source
`de291a17d5e9bfb6f54918660320ecfa1d521be4`. The TB-R3 independent review's G0–G8 series was implemented
**test-side only**: ordinal 333 now constructs a DCEL-valid two-triangle witness and screens before
`set_mesh`; ordinal 334 carries branches through published `signedLift` with the per-face gauge premise
recorded; a local-holonomy identity covers the independent gauge invariant; the seed-provenance falsifier
uses a constructed failure and makes the live sphere conditional; and G5 adds an always-publishing
non-gating sphere A2a diagnostic (`credit=none`, owning measure G5). No `src/` or `include/` file changed;
T6, Q8, accepted expectations, sphere fixture, tolerance, E2–E6, and the frozen 338 selector remain unchanged.

The first compile-only attempt `32925647275 / 98047893444` exposed two invalid `DomainResult<T>` dereferences
inside the new fan helper; commit `de291a17…` changed only `*edge` to `edge.value()`. Authoritative run/job
`32926004147 / 98048909565` then compiled all eight standard targets green with `runtimeExecution=false`.
Immutable package `9591540182` has ZIP SHA-256
`8a93b553df337bc8ad952e6a5b348a3eaac8b2304b50c1402f5184a8ce4c561f`, internal manifest **27/27 PASS**,
and embedded source SHA-256 `6077902a83b88d1ef839ab6d2bc285050f0c059511a71c9125b0324383d69a32`.
Compile event/control SHA is `baf7ed2ea9381ad47b3ae807d00d61bee0f0dcfe`. Selector hashes were
recomputed unchanged: 338 `d588cae0…a8116`, first-316 `601ce2b6…0193c`, first-328 `cf93622e…3600`.
Stable accounting remains **42 / 14 / 28**, debt **5**; M3 packages advance to **43**.

Exact next: artifact-only **`M3-CP4c-0-TB-R4`** on package `9591540182`: unchanged 338/fresh-process census
with F6 continuation, F3 supplemental 2/2, then G5 non-gating publication. Q8 is creditable only after those
gates and is **expected RED by P4**; preserve G5's rejection/outcome and route a red Q8 to review.

## 2026-08-26 — `M3-CP4c-0-TB-R3-REVIEW-PLAN`: both reds are test-side; Amendment 7; the sphere still does not publish

**Independent review and planning only. No runtime, build, benchmark, product source, test source,
fixture, selector, or build-configuration change.**

- **Evidence independently verified**: TB-R3 run `32921851098 / 98036868098`, head SHA `faf84aff…`,
  result `9590143527` / `af4f5b28…`, log `9590143871` / `ec9c29b7…`, package `9589508430` / `7bb4bd1a…`,
  semantic source `b135e219…`. All three selector hashes (338 `d588cae0…`, 316-prefix `601ce2b6…`,
  328-prefix `cf93622e…`) **recomputed locally** and matching; the four audited files are
  **byte-identical to the packaged semantic source**. Runtime counters read from the job log directly:
  `executed=338 passed=336 prefix316_passed=316 prefix328_passed=328 correction10_passed=8`.
- **F6 is runtime-proved and it paid for itself immediately.** Continue-and-observe executed all 338
  identities despite a red at ordinal 333 — the only reason 334's red, 335–338's greens, and identity
  338's pass are known. F1 and F2 are also runtime-proved: ordinals 329–332 green, both supplementals
  green. The `std::uint8_t` and seed-back-fill defect classes are closed.
- **Ordinal 333 — test fixture defect, diagnosed from primary evidence.** The job log shows an uncaught
  `C++ exception with description "compute_edge_quantities(): DCEL consistency check failed"` at **0 ms**;
  the predicate under test never ran. The sharper truth than the standing hypothesis: the near-degenerate
  coordinate search is a **red herring** — the fixture builds a **single-triangle** mesh, and
  `DCEL::check_consistency`'s `checkPureBoundary` rejects any face with no interior edge, so **every**
  candidate is invalid regardless of coordinates. The determinant screen runs *after* `set_mesh`.
- **Ordinal 334 — oracle defect, originating in this reviewer's E8 specification.**
  `build_face_branch_frame` assigns each face a **gauge** against that face's canonical reference edge
  and canonical-order normal, so semantic branch `s` means `raw[(gauge+s) mod 4]` and **the same numeric
  `FieldBranch` is a different physical direction on different faces**. The gauge model derived from
  source reproduces the observed admitted counts **`0, 1, 0, 3` exactly**, including the one fan face
  whose canonical normal is anti-parallel to mesh orientation; branch 1's pass was coincidence.
- **Production is correct at both sites and the source proves it.** `build_branch_transports` already
  corrects every lift by `rawGauge[first] − rawGauge[second]`, and the trace loop,
  `resolve_field_vertex_transit`, and the singularity fan partition all rotate by that corrected
  `signedLift`. **No production measure is authorized by either red.**
- **Amendment 7** issued: `FieldBranch` is a **per-face gauged label, not a portable direction
  identifier**; cross-face comparison is valid only through the published `signedLift`; such an oracle
  must be paired with an independent gauge check (local holonomy); and **a required falsifier may not
  assert the existence of a current production failure.**
- **The finding that outranks both reds.** The supplemental falsifier
  `TracingPathNeverPublishesSeedIdentityAsFailureLocus` contains `ASSERT_FALSE(networkBuild)` and it
  **passed** — direct runtime proof that **the prescribed sphere still does not publish a network**. So
  **Q8 will fail on the next TB even at 338/338**, which neither the TB report nor the review brief
  surfaces; and that assertion will **invert at exactly the moment CP4c-0 succeeds**. Measure **G4**
  de-encodes it before then.
- **Standing observability gap, now closed by plan.** Nothing in the frozen gate or either supplemental
  publishes the sphere's *current* rejection code — known only by exclusion. This is the **third
  consecutive cycle** in which the sphere's decisive datum was computed and not published. Measure
  **G5** adds a non-gating identity that always reports it.
- **Identity 338 passed** (non-crediting), confirming E2–E5 removed the
  `BranchContinuationDegenerateEntry` family from the sphere — genuine progress. It is not gate credit
  and not Q8; it only rules out two codes.
- **The previous review's P2 prediction was falsified** at 333 and 334 and is owned in review §5. Both
  misses share one root: auditing what an identity asserts without auditing the authority it consumes to
  reach the assertion. Correctly predicted: 330, 331, 332, 335, 336, 337, both supplementals, both
  accepted prefixes, and identity 338 (P3).
- Corrective series **G0–G8** frozen for **`M3-CP4c-0-CB4`**, Code + Build, **test-side only**. Stable
  accounting unchanged at **42 / 14 / 28**; produced-witness debt **5**; M3 packages **42**.
- Record: `Architecture_M3_CP4c0_TB_R3_Review_Plan_Independent_Review.md`.

## 2026-08-26 — `M3-CP4c-0-CB3`: diagnostic class correction build green

`M3-CP4c-0-CB3` is **COMPLETE / BUILD GREEN** at semantic source `b135e219ee9269a73eaee32992d80c3921318011`. F1 routes branch diagnostics through named `branch_locus`; F2 removes downstream trace-seed back-fill from failure loci while preserving legitimate port-local binding loci; F3 compiles two class falsifiers; F4/F5 audit emitter formatting/order; F6 freezes continue-and-observe semantics after a required red; F7 records semantic and control SHA; F8 compiles the producer target and all eight standard targets. Authoritative compile run `32919909928`, event/control SHA `950d158c333622f59ed9d26c53b2028706954275`, package `9589508430` (`7bb4bd1a40af68ffd1e2ce06001490d61504e6ed0300505646c0abce97693015`), manifest **27/27 PASS**, `runtimeExecution=false`. Frozen 338 selector and hashes are unchanged (`d588cae0…`, first-316 `601ce2b6…`, first-328 `cf93622e…`). Q8 remains verbatim frozen and unconsumed; identity 338 is not a Q8 substitute. Exact next: artifact-only `M3-CP4c-0-TB-R3` using package `9589508430`.

## 2026-08-26 — `M3-CP4c-0-TB-R2-REVIEW-PLAN`: identity 329 adjudicated; Amendment 6; a second class defect found

**Independent review and planning only. No runtime, build, benchmark, product source, test source,
fixture, selector, or build-configuration change.**

- **Evidence re-verified independently** against the GitHub API and git, not taken from the reports:
  TB-R2 run `32914546494` head SHA `26c55d13…`, result `9587747391` / `89d72a42…`, log `9587747654` /
  `2b43c3bd…`, CB2 package `9586196535` / `9f748561…`, CB2 log `9586197038` / `7c3e56db…`. Selector
  (**338**, `d588cae0…`) and the 316-prefix (`601ce2b6…`) recomputed locally; the 316-prefix is
  **byte-identical to the accepted authority**. All matched. The four audited files are **byte-identical
  (SHA-256) to the packaged semantic source `390e65b3…`**, so the source findings below are findings
  about the immutable package, not about later drift.
- **Two structural checks no prior turn had made.** The always-red probe
  `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable` is confirmed **absent** from
  the 338 selector, so the gate is achievable. And CB2's compile run reports `head_sha = bd4ddf26…` —
  the *control* commit, twelve minutes after semantic source `390e65b3…`; reconcilable, but CB2 is the
  only report in the sequence that omits its control SHA (measure F7).
- **CB2's E1–E9 verification claim was independently re-verified and is accurate.** Each of the nine was
  checked against the packaged source rather than accepted on assertion. E2 and E3 are implemented
  exactly as the previous amendments specified, including vertex-identity indexing; the lossy
  `field_branch_world_direction` round trip is absent from the entire tree; exactly one sector rule
  survives with two production callers. **E2–E6 are correct and are not in the successor's scope.**
- **Identity 329's cause is solely the `std::uint8_t` defect, at exactly two call sites.** Established by
  exhaustive audit of every token the identity asserts: face/edge/published-set loci use `index()`
  (`std::size_t`); `parameter`/`exactValues` use canonical GMP `numerator/denominator` strings;
  `traceSteps`/`traceStepBudget` are `std::optional<std::size_t>`; the empty-set special cases are
  present. Only `branch=` and `relatedBranch=` can fail. A repository-wide sweep confirms those are the
  **only** two stream insertions of a narrow-integer accessor, and `GridAutomorphism::value()` — the
  codebase's only other `std::uint8_t` accessor — is never streamed.
- **It also exposes a real frozen gap, and the gap is the reviewer's.** Amendment 5 required a property
  of the emitted *value* and never constrained the *mechanism*, so the one locus bypassing the `*_locus`
  formatter convention was unconstrained — while the correct idiom already existed in the same
  subsystem at `FieldTransportAtlas.cpp:673`. **Amendment 6** now defines observability by mechanism:
  formatted through a named helper, printable ASCII only, parseable, and site-sourced at every emission
  site.
- **A hazard recorded for the first time.** `FieldBranch::from_integer(0)` emits **NUL**; `branch` is
  emitted *before* `parameter`; and `parameter` is the single datum that discriminates the sphere's
  failure route. At any C-string boundary that NUL truncates exactly what measure E1 exists to publish.
  `std::string` is NUL-safe, which is the only reason identity 329 caught this instead of a log silently
  losing it — luck of field ordering, not design.
- **A second defect of the same shape found.** Measure E1c named *one line*; CB honoured it exactly, and
  ~15 other emission sites in `SurfaceCellTracing.cpp` still back-fill `error.sourceVertex` from the
  trace seed — the pattern that made TB-R1's `sourceVertex=0` misleading. **Both defects in this cycle
  are class defects certified by instance falsifiers.** Amendment 6 now requires class falsifiers.
- **Identities 330–337 statically audited and predicted green** after the fix; identity **334** verified
  by exact hand computation (the fan's field directions sit at sector *bisectors*, all coordinates
  exactly ±1/2, no rounding participates). Recorded alongside it: 334 therefore does **not** exercise the
  hard case its name implies — a direction on or near a fan ray, where the faces sharing that ray round
  their own directions independently. That residual is unproven in either direction and is explicitly
  out of the successor's scope.
- **Identity 338 is not a Q8 substitute** — it forbids two codes under `if (!sphereNetwork)`, so it is
  green whenever the sphere fails with any other code. **338 and Q8 remain the open questions.**
- Corrective series **F0–F8** frozen for **`M3-CP4c-0-CB3`**, including **F6**: on a semantic red the TB
  runner continues executing the remaining required identities and reports them as non-crediting
  observations. Each identity already runs in a fresh process, so a two-character formatting defect at
  ordinal 329 should never again hide the results of nine identities including 338.
- Stable accounting unchanged at **42 / 14 / 28**; produced-witness debt **5**; M3 packages **41**.
- Record: `Architecture_M3_CP4c0_TB_R2_Review_Plan_Independent_Review.md`.

## 2026-08-26 — M3-CP4c-0-TB-R2 valid red at correction identity 329

- Authoritative artifact-only retry 1 `32914546494 / 98015432540` consumed immutable CB2 source/package `390e65b373063c667e3c3f5e78b74ed9d859093b / 9586196535` and the frozen 338 selector.
- Identities **1–328 PASS**: accepted predecessor **316/316** and prior CP4c-0 **328/328** are re-proved. Ordinal **329**, `ResolvedBranchCorrection.NetworkDiagnosticsPublishEveryRequiredLocusLosslessly`, is the first semantic red; execution stopped there and identities 330–338 received no credit.
- Immediate evidence: `FieldBranch::value()` returns `std::uint8_t`; the test/witness `append_network_error` helper streams that byte directly, producing control characters instead of decimal `branch=1` / `relatedBranch=3` tokens. The typed error fields remain populated. This is recorded as a non-stable test/diagnostic-observability candidate pending independent review, not repaired inside TB.
- Q8 **NOT RUN** because the complete 338 gate was not green, even though E6 was verified present. Package/source/test/fixture/selector pre/post inventories are identical and all build/mutation flags are false.
- Result artifact `9587747391` SHA-256 `89d72a42b07bb879f2ba35b18b3771359d522e3c0f444e33e79ce0214d8fc5a3`; log artifact `9587747654` SHA-256 `2b43c3bda84edffe7ea23cd9763fa3c96858285b785624102f202d4e72479dab`.
- Retry 0 `32914435964 / 98015089869` was orchestration-only: identity 1 passed, then a temporary shell helper returned its bookkeeping predicate status. Retry 1 changed only that helper return and is the sole diagnosed retry; no semantic rerun follows the deterministic red.
- Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **41**. Latest accepted runtime remains CP4ab **316/316**. Exact next: independent `M3-CP4c-0-TB-R2-REVIEW-PLAN`.

## 2026-08-25 — Drive patch retirement no longer emits deterministic ownership 403s

- Removed the permanent Google Drive `DELETE` request from `agent-google-drive-reusable.yml`. After a successful repository push the reusable now reads `capabilities.canTrash`; it issues only `files.update(..., trashed=true)` when that capability is true, otherwise it skips the known-failing mutation and reports owner-authorized retirement as still required.
- Preserved the prior changed-path correction for newly created patch targets: the verifier combines tracked `git diff --name-only` paths with `git ls-files --others --exclude-standard`, so intended new files participate in exact-scope verification before `git add`. The failed CB2 closeout attempt proved the missing paths were two intentional new durable report/plan files, not generated junk; `.gitignore` therefore remains unchanged rather than hiding legitimate new patch targets.
- This is control-plane/policy hardening only. CB2 semantic/build authority is unchanged and the exact next runtime turn remains artifact-only `M3-CP4c-0-TB-R2`.

## 2026-08-25 — M3-CP4c-0-CB2 verification-first build green

CB2 is **COMPLETE / BUILD GREEN** at semantic source `390e65b373063c667e3c3f5e78b74ed9d859093b`. The required pre-edit audit found E1–E9 already implemented on the branch, so this turn made no duplicate production/test/fixture/selector change. E10 compiled all eight standard targets on `32909482352 / 98000623070` with `runtimeExecution=false`; immutable package `9586196535` (`9f74856149909bc1fbcaffe638fd64b4719cddcb8ed8d92972dd52289362003f`), manifest **27/27 PASS**. Required selector is **338 = 316 + 12 + 10**, SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`; first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`. T6/Q8, the prescribed sphere fixture, and `kBranchTopologyTolerance` remain unchanged. Exact next: artifact-only `M3-CP4c-0-TB-R2` on 338/338 plus binding Q8. Stable accounting **42 / 14 / 28**, debt **5**, M3 packages **41**.

## 2026-08-25 — `M3-CP4c-0-TB-REVIEW-PLAN`: the T6/Q8 conflict adjudicated; five DEFN amendments

**Independent review and planning only. No runtime, build, benchmark, product source, test source,
fixture, selector, or build-configuration change.**

- **Evidence re-verified independently against the GitHub API**, not taken from the TB report: run
  `32891161394` (`run_attempt=1`, `failure`), head SHA `9779f223…`, result artifact `9579600371`
  SHA-256 `fe472587…`, log artifact `9579600958` SHA-256 `7ddfe4c8…`, schema job `97943166744` success.
  **All matched exactly.** The TB job's step ledger independently corroborates "valid red": step 4
  `Execute frozen TB plan` *succeeded* over 3 m 32 s and only step 8 `Fail closed on red gate or Q8`
  failed. Retry 0's step 4 failed after **12 seconds**, which cannot contain a 328-identity gate —
  pre-semantic, confirmed by wall clock rather than by assertion.
- **Verdict: neither T6 nor Q8 is at fault, and neither is weakened.** Root cause: A1 decides the
  **sign of a barycentric direction coordinate** with a `double` tolerance in three separate places and
  publishes those verdicts as topological ownership — carrier-set membership and vertex-sector
  membership — while A2a's new continuation rule decides the same sign **exactly on A1's own published
  datum**. Where they disagree, A1 hands A2a a state A2a is correct to reject.
- **The seam is proved algebraically, with no runtime.** In `direction_in_incident_vertex_sector`,
  `alpha = d[next]` and `beta = d[prev]` identically, so `alpha > tol && beta >= -tol` *is* the exact
  entry predicate at `tol = 1e-10`. Two disagreement bands are characterized: `d[prev] ∈ [−tol, 0)`
  admits a face the direction exits (→ the observed `t* = 0`), and `d[next] ∈ (0, tol]` drops a face the
  direction enters. `field_branch_world_direction`'s barycentric→world→barycentric round trip — a
  cancelling sum over `Σ d_i = 0` — widens the first band well past `tol`.
- **The specific failure route is deliberately not guessed.** `sourceVertex=0` / `singularity=0` in the
  TB report are the trace **seed**, back-filled at `SurfaceCellTracing.cpp:818-819`, not a locus. Only
  `sourceEdge=6-8` is genuine, and it cannot separate the three candidate routes. The discriminating
  datum — the exact entry parameter — **was computed and discarded** by `append_network_error`, which
  emits four fields and drops `sourceFace`, `parameter`, `exactValues`, and `publishedEdges`. CB1
  populated them correctly in production; the DEFN never required the witness emitter to print them.
- **Five amendments issued to `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`**, all defects of this
  reviewer's own frozen text: §4.3's tolerance-harmlessness claim retracted; §4.4's "partition" claim
  retracted; §4.4's T1 dispatch made exhaustive over exact vertex landings; §9 gains cross-edge flow
  agreement as a published A1 invariant; §10 requires loci to come from the failure site and to be
  **observable**, and gains `BranchTransportFlowDisagreement`.
- **Three theorems freeze the sufficiency argument**: after exactification, T6 cannot fire on a vertex
  transit, `BranchContinuationOutsideOutflowSet` cannot fire on a vertex-originated exit, and T6 cannot
  fire on an interior edge entry through a genuine incoming carrier. **T6 becomes provably unreachable
  from any well-formed production state** while keeping its exact frozen wording.
- **Reachability audit:** under `Σ d = 0, d ≠ 0`, `|N| ∈ {1,2}` always, so T4, T5, the `|M| > 2` guard,
  and `InvalidBranchBoundaryFlow` are **unreachable from valid authority**. Correct as fail-closed
  assertions; annotated so their green falsifiers are never miscredited as production coverage.
- **Two further defects found, neither in CB1's frozen scope:** T1 publishes an exact vertex landing as
  an `EdgeExit`, so `VertexHit` and `EdgeExit` can represent the same event; and the `visited` cycle
  guard keys on `(face, branch, incoming carrier)` with no position, which under D0 truncates a
  legitimate re-entry at a different exact parameter and publishes a **spurious clean terminus** — Q8's
  trace count and terminal event are not creditable until that is corrected.
- Corrective series **E0–E10** frozen for **`M3-CP4c-0-CB2`** (Code + Build only). Stable accounting
  unchanged at **42 / 14 / 28**; produced-witness debt **5**; M3 packages **40**.
- Record: `Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md`.

## 2026-08-25 — ChatGPT Web patch transport moved to Google Drive File-ID workflow

- Replaced repository-staged compressed/Base64 patch payloads and fragments with the standard transport: exact source snapshot -> locally generated/verified downloadable backup patch -> Google Drive `My Drive/Directional-CI` staging -> File-ID application by durable `agent-google-drive-reusable.yml` -> post-push Drive retirement -> temporary caller/marker cleanup.
- Preserved direct GitHub connector writes for genuinely minor changes within the observed per-write safety ceiling.
- `agent-google-drive-reusable.yml` verifies patch/base/diff-body/path authority, applies and pushes source/documentation patches, rejects workflow-file patch edits, and performs post-push Drive retirement without a permanent-delete request.

## 2026-08-25 — M3-CP4c-0-TB complete / VALID RED after green 328 gate

- Authoritative artifact-only run/job `32891161394 / 97943220460` consumed package `9577900736` from semantic source `e784e44ce86e458b250b04689288f5f365ca507b`.
- Required gate **328/328 PASS** = accepted **316/316** + CP4c-0 **12/12**; no accepted regression.
- Binding Q8 **RED**: sphere reaches A1 then A2a rejects `BranchContinuationDegenerateEntry` at singularity 0 / source vertex 0 / edge 6-8; no network, so 24 traces / terminal `TraceIntersection` / face `1-2-5` crossover are not observable.
- Result artifact `9579600371` SHA-256 `fe472587aba74c2face26a2f65c0706439232bec2e5cc594d81711a26773b399`; log artifact `9579600958` SHA-256 `7ddfe4c8e48b1b618c7a60ad6cf900a767ff954309a1c3cc52a8896306d98039`.
- Retry 0 `32890863928` infrastructure-only before package verification/identity execution; retry 1 is the single diagnosed retry. No semantic rerun.
- Artifact-only integrity exact; all build/mutation flags false; no performance benchmark. Stable accounting **42 / 14 / 28**, debt **5**, M3 packages **40**.
- Exact next independent `M3-CP4c-0-TB-REVIEW-PLAN`; no CB/further TB until T6 versus Q8 is adjudicated.


### 2026-08-25 — `M3-CP4c-0-CB1`: exact branch continuation compiled and packaged

**Code + Build only / BUILD GREEN.** Semantic source `e784e44ce86e458b250b04689288f5f365ca507b`;
authoritative run/job `32886067534 / 97927044884`; `runtimeExecution=false`.

A1 now publishes exact barycentric `FieldBranchDirection` and no longer publishes Cartesian
`connections`. A2a carries canonical-edge `FieldBoundaryPoint` positions, resolves continuation with
exact cross-multiplied exit-time ordering, reuses `direction_in_vertex_sector` for regular vertex
transit, produces `SingularityTermination` at singular vertices, and preserves the A1 outgoing-carrier
containment invariant. No A2b, torus, mechanical, C4/C5, `k >= 2` terminus-ordering, or tolerance change
was made.

Exactly **12** falsifying/rejection identities were added, freezing CP4c-0 at **328 = 316 + 12**.
Selector SHA-256 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`; accepted
316-prefix SHA-256 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`.
The eight standard compile/package targets are `PASS / all 8 compiled and linked`; immutable package artifact
`9577900736` has ZIP SHA-256 `b9c597584177f31fd2d923b622a4b20fbb243c7bd007b37cced8ff128e349f31` and package manifest
`27/27 PASS`. No Directional binary, test, or benchmark was executed.

Exact next: `M3-CP4c-0-TB`, artifact-only **328/328**. The first 316 identities perform Q6's unchanged
migration re-proof; the final 12 prove the new exact continuation contract.

Stable regression accounting remains **42 / 14 / 28**, produced-witness debt **5**; M3 package count **39 → 40**.

### 2026-08-25 — `M3-CP4c-0-DEFN`: resolved branch continuation, frozen

**Independent definition / review / planning only.** No product, test, fixture, selector, build,
package, or runtime. Binding output: `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`, §3–§10 **FROZEN**.

**The charter's stop condition did not fire.** `M3-CP4c-1-TB-R3` (`32872112507 / 97881418987`, package
`9570940997`, 323 processes, accepted **316/316**) confirmed every assumption. Z1's census — two-ring
**50%** ambiguous, four-triangle fan **25%**, torus **50%**, prescribed sphere **50%** — is exactly the
signature predicted from `dbary = {-u-v, u, v}` summing identically to zero: a face is either `2×1`
(resolvable) or `1×2` (ambiguous), with no third case. Z2 pinned the sphere to
`field_aligned_outgoing_carrier` after **one** completed segment, face `1-2-5`, incoming `1-2`, outgoing
`{1-5, 2-5}`, multiplicity **2**, transport adjacency present.

**The DEFN's own finding: the gap is two missing data, not one.** The entry position is absent from
`FieldAlignedCandidateTraceSegment`, **and** the barycentric direction is computed at
`FieldTransportAtlas.cpp:118` and then **discarded** — `FieldBranchBoundaryPairing` publishes `branch`,
`intervals`, carriers and `connections`, but no direction. A consumer holding an exact position still
could not resolve the continuation. `connections` is a Cartesian product because it is the most A1 could
say with what it kept.

**Frozen answers.**

- **D0** — `FieldBoundaryPoint{edge, exact parameter}`. **`SourceSupport` is not sufficient**:
  `SourceEdgeSupport` records which edge, never where. The parameter runs `first()`→`second()` on the
  canonical edge key, which `AuthorityKernel.cpp:19-28` guarantees is ordered — so the value is
  **face-independent with nothing to convert across a boundary**, and it projects onto `SourceSupport`
  (0 → vertex, 1 → vertex, else edge). **Single writer: A2a.**
- **D1** — exact minimum-ratio exit. **No tolerance decides any topological outcome**: every IEEE double
  is a dyadic rational, so `t_i < t_j` is decided by exact integer cross-multiplication
  `p_i·(−d_j) < p_j·(−d_i)`, never by dividing doubles. Seven exhaustive cases T1–T7, each with a
  required falsifying witness. **T2** reuses the existing `direction_in_vertex_sector`; a second sector
  rule is a stop condition. **T3** finally gives `SingularityTermination` — declared since CP3b and, per
  CP4-DEFN §3.3, produced by nothing — its producer.
- **D2** — `connections` and `FieldBranchBoundaryConnection` are **deleted**, not demoted; A1 publishes
  `FieldBranchDirection` with a `Σ = 0` construction check. Carriers, intervals, transport adjacency, and
  port attachments are untouched — which is why the sphere completed exactly one segment: step 1 always
  had a resolution rule via `firstOutgoingCarrier` and `direction_in_vertex_sector`, steps ≥ 2 never did.
- **D3** — **no accepted witness's traces change**, proven rather than hoped: old and new rules agree
  whenever `|N| = 1`, and a `1×2` face returns `nullopt` under the old rule, so no accepted trace can
  ever have traversed one or the accepted 316 would not be green. Only shapes and digests move, and every
  digest assertion in the suite is relative. Per-checkpoint matrix for CP1 → CP4ab included, with **no
  expectation edit expected anywhere**.
- **D4** — measured witness table: two-ring and fan reach A2b; **the prescribed sphere is the only
  witness that can prove T1**; torus (0 traces) and mechanical (fails A1) are deferred to CP4c-2/3.
- **D5** — the barrier terminus and the continuation are **one datum**, unified under
  `FieldBoundaryPoint`. **CP4ab is not reopened**: the combinatorial 0-cell stays and `NetworkNodeId` does
  not become positional. `k ≥ 2` terminus ordering stays fail-closed **even though the datum now exists**.

Measures **Q0–Q8**; Q3 must deliver the exact comparator **and its exactness identity in the same turn**,
Q5 freezes the identity count in the CB report so the gate is `316 + n`, Q6 re-runs the accepted 316.
**A red at Q6 is a stop-and-review, never an expectation edit.** Accounting unchanged: stable
**42 / 14 / 28**, debt **5**, packages **39**, accepted runtime **M3 CP4ab 316/316**. Exact next:
`M3-CP4c-0-CB1`.

### 2026-08-25 — `M3-CP4c-1-TB-R3`: VALID RED 316/318 confirms CP4c-0 blocking predecessor

**Artifact-only Test + Benchmark / COMPLETE.** Authoritative run/job `32872112507 / 97881418987`
consumed immutable semantic source/package `51f510861a02377d1f45607908191f2fdebdcd33 / 9570940997`. Result
artifact `9572545977` has SHA-256 `06941e750b8c88b295cf43b7d5c27b060321f693f7715eb650128f125d9b4a8c`.
Exactly **323 fresh processes** executed with zero orchestration errors: required **316/318**, accepted prefix
**316/316 PASS**, C4/C5 **0/2**, plus five deliberately failing non-gating observations. Package/source
pre/post inventories are identical; all configure/compile/rebuild/relink/repair and mutation flags are false.

**Z1 confirmed generic unresolved continuation authority.** Two-ring is **30/60 = 50%** ambiguous,
four-triangle fan **4/16 = 25%**, torus **288/576 = 50%**, prescribed sphere **384/768 = 50%**.
The sphere failing face `1-2-5` is ambiguous with incoming `1-2`, outgoing `1-5,2-5`, multiplicity **2**.

**Z2 confirmed the production site.** The sphere fails exactly at `field_aligned_outgoing_carrier` after
**1 completed segment**, face `1-2-5`, source edge `1-2`, multiplicity **2**, with field-transport
adjacency present. This confirms the TB-R2 review's A1→A2a Cartesian-relation/missing-position diagnosis;
`field_aligned_next_face` and `topology.transport` are ruled out for the observed failure.

The first control run `32871811711` is invalid pre-runtime: `tar|grep -q` under `pipefail` produced a
broken-pipe preflight failure after a successful match and executed **0 identities**. Corrected orchestration
produced the authoritative result above. Stable accounting stays **42 / 14 / 28**, debt **5**, M3 packages
**39**. Exact next is **`M3-CP4c-0-DEFN`**, review/definition/planning only; no implementation is authorized
before it freezes the position/continuation contract and re-proof surface.

### 2026-08-25 — `M3-CP4c-1-CB3`: branch-pairing measurements compiled and packaged

**Code + Build only / BUILD GREEN.** Semantic source `51f510861a02377d1f45607908191f2fdebdcd33`;
authoritative run `32867889140`. No production translation unit changed and `runtimeExecution=false`.

Z1 adds the non-gating branch-pairing census across accepted and prescribed witnesses. Z2 adds the
non-gating prescribed-sphere candidate-transport site pin. Z3 authors the planning-only
`Architecture_M3_CP4c0_DEFN_Charter.md`. The required selector remains **318**; diagnostics expand
3 → **5**, selector SHA-256 `9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`.

Schema validation, exact patch application, producer compile, and full package compile all passed.
Immutable package artifact `9570940997` has ZIP SHA-256
`23876c55e51b94ca3a1e5bcfb727a4c0cebce3294fcd2fbda21336b57ae1de16`; package manifest **27/27 PASS**.
No Directional runtime executed. M3 package count **38 → 39**; stable regression accounting
**42 / 14 / 28** and produced-witness debt **5** unchanged.

Exact next: `M3-CP4c-1-TB-R3`, artifact-only, **318 required + 5 non-gating = 323 fresh processes**.
Expected required result remains **316/318**; Z1/Z2 decide whether `M3-CP4c-0-DEFN` is confirmed as the
next planning turn.

### 2026-08-25 — `M3-CP4c-1-TB-R2` review: the branch pairing is a Cartesian product

**Review + Plan only.** No product, test, fixture, selector, build, package, or runtime. Binding output:
`M3_CP4c_Consolidated_Record.md`. Under the current workflow this red consumed nothing.

**Evidence independently verified** against the GitHub API: run `32851859581`, head `c13661c7…`, and both
artifact digests exact. **VALID RED 316/318** — 321 fresh processes, accepted prefix **316/316 PASS**,
only C4/C5 red, zero orchestration errors, every mutation flag false.

**Y2 delivered.** The mechanical A1 failure resolved to `fieldTransportAdjacencyExists=false` with valid
`EF` rows — a missing adjacency, not a negative row. Question closed; owned by CP4c-3.

**The sphere prediction was falsified, and the falsification found the real defect.** The prescribed
sphere reaches A1 but A2a rejects `InvalidCandidateTraceTransport` at `sourceEdge=1-2`.

**Root cause, proven from source with no runtime.** `FieldBranchBoundaryPairing.connections` is built as
the **full Cartesian product** of `incomingCarriers` × `outgoingCarriers`
(`src/authority/FieldTransportAtlas.cpp:164-169`). It is not a pairing — it records which edges are
inflow and which are outflow, never which outflow edge a trace entering through a given inflow edge
actually reaches. A2a demands exactly one match (`src/geometry/SurfaceCellTracing.cpp:270-281`) and
returns `nullopt` whenever a face has two outflow edges. The continuation genuinely is not determined by
the data held: which outflow edge a straight line reaches depends on **where along the entry edge it
enters**, and no entry position is captured.

**Generic, not witness-specific.** `dbary = {-u - v, u, v}` sums identically to zero, so for any
non-degenerate direction exactly one derivative has one sign and the other two the opposite. With the
build requiring at least one inflow and one outflow, every face is either 2-in/1-out (fine) or
**1-in/2-out (ambiguous)** — roughly **half of all faces on every mesh**. Latent in accepted authority,
hidden only because the accepted disc witnesses' traces terminate on a boundary barrier within one or two
segments and never traverse an ambiguous face; the torus publishes zero traces.

**`DESIGN.md` §4.5 already specifies the fix and half of it was never implemented.** §4.5 requires the
inflow/outflow interval pairing to be *resolved* by a guaranteed combinatorial algorithm with
**barycentric positions propagating in arbitrary precision**, as exact values compatible with
`SourceSupport`. No trace segment carries a position of any kind. This is the **same missing datum** the
CP4ab DG-R4 review identified for the barrier terminus — one gap, two symptoms, and the same work.

**The mandated question is answered: production-side, unambiguously.** The trace completed at least one
segment before failing, so the sphere's field, ports and branches are valid; no witness change can help.
Explicitly rejected: resolving the ambiguity inside A2a (second writer of transport semantics), any
tiebreak by identifier, container order, derivative magnitude or nearest direction, witness substitution,
and weakening C4/C5.

**New blocking predecessor `M3-CP4c-0`** — resolved interval pairing with propagated barycentric
positions — inserted before CP4c-1. Its gate is 316 + its own identities, **frozen by its DEFN, not fixed
now**. **C4/C5 stay gating and CP4c-1 stays open**: demotion to non-gating was considered and rejected,
because event non-vacuity is the checkpoint's whole purpose and an open checkpoint costs nothing under
the abolished-budget workflow.

Corrective measures **Z0–Z5**, observation and planning only. Z1's pairing census over every published
frame of every witness proves or refutes the genericity claim on the **accepted** witnesses; Z2 pins the
sphere's failure to one of three candidate call sites; Z3 authors the `M3-CP4c-0-DEFN` charter, whose
hardest item is the re-proof surface across accepted A1/A2a. Gate unchanged at **318**; non-gating
identities 3 → 5; **the next TB is expected to return 316/318 again, and that is correct.** Accounting
unchanged: stable **42 / 14 / 28**, debt **5**, packages **38**, accepted runtime **M3 CP4ab 316/316**.
Exact next: `M3-CP4c-1-CB3`.

### 2026-08-25 — `M3-CP4c-1-TB` review: the crash-on-contact primitive has no witness

**Review + Plan only.** No product, test, fixture, selector, build, package, or runtime. Binding output:
`M3_CP4c_Consolidated_Record.md`. Under the current workflow this red consumed nothing.

**Evidence independently verified** against the GitHub API: run `32800374361`, head `e678b98c…`, and all
three artifact digests exact. **VALID RED 316/318** — 320 fresh processes, accepted prefix **316/316
PASS**, only C4/C5 red, zero orchestration errors, every mutation flag false, digests stable pre/post.
The non-gating mechanism introduced by the 2026-08-25 workflow change worked on its first use: two
diagnostic identities executed, reported, failed, and were excluded from the gate count — with no turn
type and no budget required to obtain the evidence.

**X1 vindicated.** `GlobalTopologyPlanErrorCode` went from one overloaded `RegionCutComponentCountDeficit`
to **18** condition-specific codes, and the torus failure localized immediately to
`UncutFaceComponentOrbitSeedNotUnique` at `sourceFace=0-1-2` — a code that did not exist before the
split. **X3 vindicated**: the C4/C5 witness union is correct and fails for the intended reason.

**Two prior predictions corrected.**

- **Torus — the prior `TraceArcDoesNotSeparateItsSides` prediction was WRONG.** The torus publishes
  **0 traces / 0 events**, so the predicted per-arc check is unreachable. Poincaré–Hopf forces
  Σ index = 0 on a closed genus-1 surface; the committed field is singularity-free; a closed surface has
  no `Boundary` mandatory edges. The network is **entirely empty**, so A2b's ownership seeding
  (`GlobalTopologyPlan.cpp:1695-1747`) has no labeled face to seed from and rejects on the first
  unlabeled face. The observed locus is exactly what that mechanism predicts.
- **Mechanical — the prior `expectedCycleCount` cardinality hypothesis is WITHDRAWN.** The locus
  `source edge 0-3` proves an edge-specific site (`FieldTransportAtlas.cpp:1628-1630` or `:1633-1637`),
  not the cardinality check at `:1556-1562`, which passes no edge locus. The failure may therefore be
  **mesh-specific rather than closed-surface-class-wide**, and the closed genus-1 torus passing A1
  supports that.

**The real blocker, and it is bigger than CP4c-1.** No committed witness exercises **crash-on-contact** —
the primitive `DESIGN.md` §4.6 names as the region-decomposition guarantee. `TraceIntersection` events
are produced at multi-port singularities, but none has ever carried a **`Terminal`** incidence, so
`field_aligned_first_trace_contact`'s branch appears unexercised across the entire accepted 316.

**The fix: `sphere_prescribed`, structurally forced rather than hopeful.** Closed χ = 2 ⇒ no barriers
exist ⇒ the mandatory-barrier branch is unreachable ⇒ every trace must terminate by contact or loop
closure. Its committed metadata declares 8 index-1 singularities summing to 2 = χ (Poincaré–Hopf
exactly), giving 24 traces on 192 faces. It is named in `DESIGN.md` §12's verification matrix, so this is
reuse, not authoring. A full topology census of all nine committed `.obj` witnesses is recorded in the
review.

Corrective measures **Y0–Y5**, test-side only. Gate unchanged at **318 = 316 + C4 + C5**; non-gating
diagnostics go 2 → 3. **Escalated and not absorbed:** `DESIGN.md` §7.2 has no closed-surface cut-graph
clause — a torus needs a seam the architecture cannot produce — owned by `M3-CP4c-2-DEFN`. Accounting
unchanged: stable **42 / 14 / 28**, debt **5**, accepted runtime **M3 CP4ab 316/316**. Exact next:
`M3-CP4c-1-CB2`.

### 2026-08-25 — `M3-CP4c-1-TB`: VALID RED 316/318; event-witness review required

Artifact-only TB run/job `32800374361 / 97659929298` consumed immutable package `9545473837` from
semantic source `18101c05d3d5fd982a61446c0b9df9f97e6ceed5`. Exactly **320 fresh processes** executed:
318 required identities and two non-gating diagnostics. Required result is **316/318 PASS** with the
accepted predecessor **316/316 PASS** and unchanged C4/C5 **0/2**. Zero orchestration errors; package,
source, and selector postflight hashes are exact; all configure/build/relink/repair and mutation flags
are false.

C4/C5 prove the authorized witness union still lacks a terminal `TraceIntersection`: torus reaches
A2a with 0 traces / 0 events, mechanical fails A1, and the two-ring witness contributes only
`MandatoryBarrierTermination`. Non-gating torus evidence localizes A2b to
`UncutFaceComponentOrbitSeedNotUnique` at `sourceFace=0-1-2`, falsifying the prior typed-code
prediction; mechanical confirms `IncompleteCycleBasis` with closed-surface facts 0 boundary loops,
genus 0, 152 interior local vertices. Stable accounting remains **42 / 14 / 28**, debt **5**.

Exact next is `M3-CP4c-1-TB-REVIEW-PLAN`; no retry or patch before review. Report:
`M3_CP4c_Consolidated_Record.md`.

### 2026-08-25 — `M3-CP4c-TB-R1` review: attempt budget and `DG` abolished; CP4c split

**Independent Review / planning only.** No product, test, fixture, selector, build, package, or runtime.
Binding output: `Architecture_M3_CP4c_TB_R1_Independent_Review.md`.

**Workflow change, user-authorized and binding.** The per-checkpoint 3-attempt acceptance budget,
attempt counters/ratchets/resets/reset-windows, the mandatory-review-on-third-red trigger, the
2-diagnostic cap, and the **`DG` turn type** (with its `DG-EXEC`/`DG-REV` split) are **abolished**. The
workflow is `CB → TB → (red) → REVIEW+PLAN → CB`. A red TB consumes nothing and mandatorily routes to
review. DG's one legitimate use is preserved as **non-gating diagnostic identities** that TB executes
and reports but the gate count excludes.

**Answered from evidence: `DG` never executed a different runtime surface than `TB`.** DG1's 316
identities were a strict subset of TB-R1's 322 — identical predecessor/CP4ab selector SHAs, the
cumulative selector's first 316 entries byte-identical to accepted authority, identical
one-identity-per-fresh-process isolation, identical `runtimeExecution`/mutation flags, identical
evidence shape. The only differences were the identity subset and the result label. Empirically, DG1
cost two turns and returned 316/316 green about exactly the hazard — fail-closed production A2b
construction — that then materialised on the witnesses its selector could not contain.

**TB-R1 independently verified** against the GitHub API: run `32791027809`, head `21eee9af…`, and all
three artifact digests exact. **VALID RED 316/322**, zero orchestration errors, all mutation flags
false. **The accepted 316 are green in the same immutable run**, so CB1's production A2b wiring
regressed nothing.

**All six reds adjudicated.**

- **C1/C3/C6 (torus) — frozen-definition scope gap in accepted A2b, not a witness defect.**
  `build_fragment_corner_incidence` rejects any trace arc whose two darts share one face-walk orbit
  (`src/geometry/GlobalTopologyPlan.cpp:1267-1273`) — a genus-0, bounded-surface assumption. Computed
  from the committed `.obj` files: torus **χ = 0, 0 boundary edges** (closed, genus 1); mechanical
  **χ = 2, 0 boundary edges** (closed sphere); every witness that has ever validated A2b is a
  **bounded disc, χ = 1**. A non-separating cycle sharing one face on both sides is what makes a
  surface a torus.
- **C2 (mechanical) — accepted A1 authority failing upstream of A2a.** `FieldTransportAtlas::make`
  rejects `IncompleteCycleBasis`; its `expectedCycleCount = interiorVertices + boundaryLoops + 2·genus`
  cannot hold on a closed mesh where every vertex is interior. Not CP4c-scope.
- **C4/C5 — authored against a witness that provably cannot satisfy them.** All three of the two-ring
  witness's traces terminate on mandatory barriers, so only one terminal event kind is ever produced.
- **Root cause common to all three:** the CP4c witness-adequacy claim verified file existence and a
  legacy-product pipeline call, never stage reachability. DEFN §8.1 said "verified this turn"; the CP4c
  plan's W0.4 repeated it. Fifth instance of the `LESSONS.md` §2 class. **CB2 is not at fault** — it
  implemented the plan correctly, including reading the new `globalTopologyPlan` slot.

**Diagnosability finding.** `RegionCutComponentCountDeficit` is emitted at **18 distinct sites** for 18
conditions, four inside the loop that rejected the torus, so the failure cannot be localized at all.
Splitting it is corrective measure **X1** and a precondition of any torus fix.

**CP4c split**, frozen 322 reopened, identity names unchanged: `M3-CP4c-1` at **318 = 316 + C4 + C5**;
`M3-CP4c-2` (closed / higher-genus region authority) at **321**; `M3-CP4c-3` (closed-surface cycle
basis, then the mechanical witness) at **322**. CP4c-2 and CP4c-3 each require their own `-DEFN`.
Corrective measures **X0–X5**. Accounting unchanged: stable **42 / 14 / 28**, debt **5**, packages
**36**, accepted runtime **M3 CP4ab 316/316**. Exact next: `M3-CP4c-1-CB`.

### 2026-08-24 — `M3-CP4c-CB1`: production A2b wiring and authoritative package PASS

**Code + Build only; W0–W5 complete.** All six binding static preconditions passed before mutation.
The accepted-predecessor selector contains 304 identities, and exactly five accepted identities reach
`remesh_from_raw_cross_field` with surface cells enabled and Fail fallback. No independent-review
boundary fired.

Semantic source `428e0ecb6f769b501c99405ae2a90c24d5401cca` constructs `GlobalTopologyPlan` exactly once,
immediately after A2a, from the prescribed four inputs. It chooses fail-closed policy (a), publishes
the product into diagnostic and per-component snapshots, and records identity/hash/count. The
production diff is 27 insertions confined to `src/pipeline/RemeshPipeline.cpp` and
`include/directional/pipeline/RemeshPipeline.h`. No `GlobalTopologyPlan.cpp`, tracing, fixture,
selector, test, identity, error-code, cache, shared-plan, or second-construction change; no C1–C6
identity; W6 not run.

Changed-owner compile `32770533316 / 97569642420` PASS; result `9536072497` SHA-256
`4c9545b9ccce2c80c61e644fc4fa6f21c58fc562192231cd6ecc4e617b1853d7`. Authoritative package compile
`32771584396 / 97572920008` PASS; immutable package `9536499549` SHA-256
`4c64c0c3ea872dbf889c4de398ed40f9e0193fce534ee6117348e3b7a5514660`; log `9536500171` SHA-256
`86c4ab983bba5bcf1a57213aa73ee6f6db48b7cfbe2c89a9487194e46e905732`; source archive SHA-256
`33e546764b3b3017fbb043cfd91a4366a3ae27244861ade457743fcf10cf49ac`; manifest 27/27; five
source-status snapshots empty; `runtimeExecution=false`. One earlier compile-only 25/25 package is
retained as non-authoritative process evidence and excluded from package accounting.

M3 packages **34 → 35**. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**,
CP4c acceptance **0/3**, diagnostics **0/2**. New exact records:
`M3_CP4c_Consolidated_Record.md` and
`M3_CP4c_Consolidated_Record.md`. Exact next is split-ready
`M3-CP4c-DG1-DG-EXEC`, artifact-only 316 identities one process each, followed by mandatory DG-REV;
diagnostic 1/2, no acceptance attempt, no configure/build/relink/repair/discovery/mutation.

### 2026-08-24 — `M3-CP4ab` closure review: claim VERIFIED; CP4c decomposed; roadmap defined

**Independent Review / planning and documentation only.** No product, test, fixture, selector, build,
package, or runtime; no acceptance attempt and no diagnostic consumed.

**The CP4ab closure claim is VERIFIED**, on three independent sources rather than the closing turn's
self-report. From the GitHub Actions API: run `32758293793` completed with `conclusion: success`, and
both artifact digests match exactly (`9531769503` → `1b4b3784…d801fc`, `9531770393` → `cff83f72…d69643`);
package `9527801615` is `m3-cp4ab-cb-r11-result-32747790694` at `a8e03a21…54557`. From the run's own
machine JSON: `gate 316/316/0`, predecessor `304/304/0`, CP4ab `12/12/0`, `orchestrationErrors=0`, every
configure/build/relink/repair/discovery and every mutation flag `false`, pre/post package and source
digests equal, `manifest_post_count=27`. From the accepted source tree at `157bf784`: all four V-series
corrections are present where the binding Review specified — V1's single-walk hoist at
`GlobalTopologyPlan.cpp:2440` above `region_orbit` at `:2444`, V2's guarded canonical ownership
comparison at `:2686-2747`, V4's exterior-orbit exclusion at
`tests/FieldAlignedCurveNetworkTests.cpp:1896-1900`, and V5's typed `IndependentDiscProofResult` at
`:1879`. A green gate proves a package passed; the source check proves it implements what was required.

**Trajectory confirmed against `DESIGN.md` §14 M3.** All six M3 acceptance criteria have owning
identities and five of six are green under a cumulative immutable gate. The remaining gap is scope of
proof, not criteria: everything is proven on development witnesses, and CP4c exists to close exactly
that.

**Two defects introduced by the closing turn's consolidation, both repaired.**

1. The retirement of 34 CP4-era documents (~6,300 lines) left **twelve normative attribution lines in
   DEFN and two in the M3 Code + Build Plan citing files that no longer exist**. The retirement itself
   was sound — DEFN amendments 1–12 were re-read and confirmed to inline everything they froze, so DEFN
   remains self-contained implementation authority for CP4c. Each citation is now annotated as
   retired-provenance, with a standing note at the head of DEFN.
2. **Every current routing pointer named "section 4A.3c", which has never existed.** CP4c's content was
   the `#### M3-CP4c` subsection of §4A.3 — a scope statement, not a decomposition.

**CP4c is materially larger than any plan recorded**, and this is the substantive finding of the review:
**`GlobalTopologyPlan` is constructed nowhere in `src/pipeline/RemeshPipeline.cpp`.** A2a is wired
(`:6587`, published `:6604-6605`, per-component `:8603`); A2b is not, and neither
`SurfaceCellDiagnosticProductSnapshots` (`RemeshPipeline.h:306`) nor `SurfaceCellComponentStageProducts`
(`:1165`) has a plan slot. C1/C2's "…DerivesRegionsThroughProductionEntryPath" therefore cannot be
satisfied by fixtures alone. Compounding it, `make_torus_pipeline_fixture()` — which DEFN §8.1 directs
the implementer to copy — reads the **legacy** `productSnapshots.traceNetwork`, a different product.

**New: `M3_CP4c_Consolidated_Record.md`**, binding, decomposing CP4c into four turns and work
items W0–W9 without reopening the frozen `322 = 316 + C1–C6` gate or the DEFN §7.3 identity names:
CB1 (wiring, W0–W5) → DG1 (W6, the accepted 316 surface unchanged against the wired package, pass
condition 316/316) → CB2 (W7–W9, two witnesses and C1–C6) → TB (322). The diagnostic is allocated
because W1 introduces a new fail-closed production path that can regress accepted authority, and
discovering that at TB would cost an acceptance attempt. W0.6 bounds the wiring to two files and makes
exceeding it a stop-and-split condition.

**New: `ROADMAP.md`**, added to `DESIGN.md` §1's authority table. `DESIGN.md` §14 defined milestones
M0–M8 with acceptance criteria but decomposed none into checkpoints; only M3 had ever been decomposed,
mid-milestone. The roadmap proposes seventeen checkpoints plus five `-DEFN` planning turns from M3 exit
to `M8-CP3`, the production-ready exit, and records which milestone owns each open product blocker.
Gate arithmetic beyond 322 is deliberately left unfrozen.

**`TODO.md` reduced from 258 to 103 lines** by removing ~170 lines of closed-checkpoint narrative
already recorded in the closure records and this changelog. All open work is retained verbatim: the M2
and M1 carried-forward items, produced-witness debt, deferred hygiene, the inherited baseline-red
register, active product blockers, and the design/calibration backlog. A stale package count (33 → 34)
was corrected.

**Documentation pruning assessed and declined.** Every surviving `.md` under `.agents/Directional/` is
either marked DURABLE, named in `DESIGN.md` §1's authority table, a closure record, or live CP4c
authority. Nothing further is safe to delete; the aggressive pruning had already happened, and this
review's job was to repair what it broke.

Accounting unchanged: M3 packages **34**, stable **42 / 14 / 28**, produced-witness debt **5**, accepted
runtime authority **M3 CP4ab 316/316**. CP4c acceptance **0/3**, diagnostics **0/2**. Exact next:
`M3-CP4c-CB1`.

### 2026-08-24 — M3 CP4 historical-document consolidation after CP4ab acceptance

User-authorized documentation cleanup after `M3-CP4ab-TB-R3` accepted the cumulative **316/316** gate. A recursive review of `.agents/Directional` found the retained current/latest M3 CP4 authority below plus **37** superseded standalone/history/evidence files. Before retirement, this entry maps every retired path to its exact pre-cleanup SHA-256 and preserves its material decision/outcome. Existing turn-level entries in this changelog remain the detailed run/job/artifact/attempt history. Exact retired bytes remain recoverable from pre-cleanup repository authority `7060c97550935336438d439db485eb56f9f8338e`.

**Retained current/latest M3 CP4 documents — byte-for-byte unchanged by this cleanup:**

- `Architecture_M3_CP4_DEFN_Frozen_Definitions.md` — SHA-256 `878bdb1f813cd70ffccfd6eb290bf26f1c5cc855379c16945d68d0e18700fb9e`
- `Architecture_M3_CP4ab_TB_R3_Artifact_Only_Test_Benchmark_Report.md` — SHA-256 `8bfb445795259cbd6fd5ddd70b92b0481b2a7211d63bb66d7887f4d6b20fc2b6`
- `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md` — SHA-256 `6545af24c9f47292e0046fa1af22d3619ea7ac7c00815e37984c7b5a7887b13b`
- `M3_CP4ab_Closure_Record.md` — SHA-256 `e20a0bd90a6feff8bfad404973435f15169f7e38f538485fe32d0df0a206515a`

**Historical standalone records retired after consolidation:**

| Retired path | Bytes | SHA-256 | Archived material fact |
|---|---:|---|---|
| `Architecture_M3_CP4ab_CB_R5_Package_Independent_Review.md` | 16515 | `887278654357be901b3df5787841baafba84146c8d51c42b2e8aeb35b663fec4` | Independent package review verified the runtime-free/default-off CB-R5 instrumentation package but denied DG-R3 because fragment-corner reconstruction and per-identity evidence were not lossless. |
| `Architecture_M3_CP4ab_CB_R6_Static_Authority_Independent_Review.md` | 20197 | `a203d5dbb485c7ca37069c2495462b834b70a668c87302659430510362bf1825` | Independent review upheld the R6 static stop, derived lawful fan-order authority from existing products, and authorized the bounded R7 route without reopening an earlier product. |
| `Architecture_M3_CP4ab_CB_R6_Static_Authority_Independent_Review_Plan.md` | 5191 | `fe12168736e6ec320b5bfa2d20229d4bab5be6378f5475652162daa8d47b1238` | Review plan that froze the R6 authority questions, prohibited invented contact ordering, and required a single lawful owner before any later diagnostic. |
| `Architecture_M3_CP4ab_CB_R7_Precondition_Independent_Review.md` | 13001 | `9be6f8c902c246b7aea15683222ddde5f3bf0adb378b1d7a3c241a9490afb8d6` | Rejected the prior orbit-side chaining construction as circular; moved the single writer for cyclic singularity-port order to A1 localSlot, transported through A2a ordinal, then consumed by A2b. |
| `Architecture_M3_CP4ab_CB_R8_S0_Independent_Review.md` | 11694 | `80e8fecc6f6938da2edc2972911ed73101a6e2c4bbe7ff466a254278e0077958` | Confirmed the S0 boundary inconsistency was caused by mandatory edges not being split at trace terminal points and authorized the R9 mandatory-arc terminal split. |
| `Architecture_M3_CP4ab_CB_R8_S0_Static_Precondition_Stop_Report.md` | 5253 | `548af27e808cc88d20831e440fed2dc130164ce88ca55231e37543bd5e0ce3cb` | Static precondition stop: a region reached the mesh boundary while its boundary walk lacked the corresponding mandatory boundary arc; implementation stopped before mutation and routed to Review. |
| `Architecture_M3_CP4ab_DG_Artifact_Only_Test_Benchmark_Report.md` | 9106 | `ab0b371989e951cf257bb8eac729d4212c7b5b4f8a777b154ba12fb2da3332ac` | DG-R1 measured 4 walk orbits / 3 region drafts versus 2 whole-face cut components; all ten reds first hit RegionCutComponentCountDeficit, confirming the fragment-ownership finding and routing K2R→K3R→K4. |
| `Architecture_M3_CP4ab_DG_R2_Independent_Review.md` | 25383 | `a716d843c170a534621ea123297d3b323397813aeefc219f66a34c087e3310b1` | Binding review localized support-face-corner conflation in V_int, kept ownership/connectivity settled, identified the latent B4 boundary issue, and selected instrumentation rather than another semantic patch. |
| `Architecture_M3_CP4ab_DG_R3_Artifact_Only_Diagnostic_Report.md` | 7834 | `2cea170be6eeb750fea1a3425100739e4e86787dff319bd9003c306864a7e3f8` | Valid 12-identity diagnostic: 2 PASS / 10 FAIL, A4/B6 green, all ten reds first RegionEulerCharacteristicNotOne; focused cyclic-order sanity was 3/3 green. |
| `Architecture_M3_CP4ab_DG_R3_Independent_Review.md` | 15593 | `3ba24e6aee08f0b70764896d1283b1271e7d2a91fd6e4b2cc28ea8e0542ba40a` | Adjudicated the DG-R3 Euler/vertex-incidence residue, froze the next bounded correction and S0 precondition route, and kept previously settled ownership/connectivity seams closed. |
| `Architecture_M3_CP4ab_DG_R3_Independent_Review_Plan.md` | 7253 | `037d75def672768704232d6957386b85f8ce18c16f686e37d41e651145745f09` | Independent-review plan for the DG-R3 2/12 evidence, including the required Euler/fragment-incidence questions and stop conditions before another semantic change. |
| `Architecture_M3_CP4ab_DG_R4_Artifact_Only_Diagnostic_Report.md` | 6736 | `dae757219d90f2ba48311b2e82bb3f9f8bc1097263dc71b94543559c7da35ccc` | Valid 12-identity diagnostic: 2 PASS / 10 FAIL, A4/B6 green, all ten reds first InvalidNetworkBinding before region construction. |
| `Architecture_M3_CP4ab_DG_R4_Independent_Review.md` | 28457 | `faa96566f175673ebbabdc1f872a912e09edb4f2a3bc11509e4c166fd1a25517` | Binding review proved the missing barrier terminus was an A2a network-0-cell authority defect, froze U0–U8, and authorized the CB-R10 terminal-node publication correction. |
| `Architecture_M3_CP4ab_DG_R4_Independent_Review_Plan.md` | 3411 | `f8793d510910652c110c279775c2227a62b8f4520f1753ceecd28b7120c843f0` | Independent-review plan for the DG-R4 InvalidNetworkBinding baseline and terminal-position authority question. |
| `Architecture_M3_CP4ab_DG_R5_Artifact_Only_Diagnostic_Report.md` | 7186 | `1faef7e0aecdec95760ae06254f5615fe89af6f6df946ffaf875994a3e2fcb4e` | Valid focused diagnostic improved the frozen surface to 9/12; terminal binding cleared while A5, B2, and B4 remained as typed residue requiring Review. |
| `Architecture_M3_CP4ab_DG_R5_Independent_Review.md` | 28361 | `b1f96907090d7dcee6778c40add9f93eee1120e56a0d566f30e38684be685c50` | Binding review classified A5/B2 as validation-ordering defects, B4 as bounded-surface Euler-oracle arithmetic, noted U5/U6 were outside the CP4ab selector, froze V0–V8, and authorized CB-R11. |
| `Architecture_M3_CP4ab_DG_R5_Independent_Review_Plan.md` | 5158 | `5d3d8211bb7c8481d450c34fb2ad30ffa99d194f20a4250e37bc60b7d9e8fb59` | Review plan for the 9/12 DG-R5 residue, including accepted-authority U5/U6 re-proof and the validation-order/oracle decision. |
| `Architecture_M3_CP4ab_DG_R6_Artifact_Only_Diagnostic_Report.md` | 5759 | `ee92ae03764d264ba3dfcd09b0cb3e15dd520448164b31fc6233a09c9c43fffc` | Focused immutable diagnostic passed 12/12 CP4ab plus 2/2 accepted CP3b U5/U6 (14/14) with package/source integrity preserved; routed to TB-R3. |
| `Architecture_M3_CP4ab_K5_Routing_Independent_Review_Plan.md` | 19120 | `bcd9819ecd7e376f11e84c9c2e4e4814a882606896ebc5622683128ee88938ff` | Plan plus binding routing result that corrected the initial K5-only route, restored K3 fragment ownership as the semantic correction, and prescribed the DG-R1 measurement / K2R→K3R→K4 sequence. |
| `Architecture_M3_CP4ab_R10_Terminal_Zero_Cell_Code_Build_Report.md` | 5312 | `3c156171c00925fc244595245d0dec162573a28a8679f65835de4f8d0d0b15f8` | Runtime-free CB-R10 published an A2a network 0-cell for barrier terminal events, compiled/package-passed, and created the package later used by DG-R5. |
| `Architecture_M3_CP4ab_R11_Validation_Ordering_Code_Build_Report.md` | 7756 | `2ab9afb1dcf3b514549ad0744c4f72e987b34c7557bb53cc071c0f6a49525309` | Runtime-free CB-R11 hoisted structural validation before consumers and corrected the bounded-surface Euler oracle; package 9527801615 became the immutable source of DG-R6 and accepted TB-R3. |
| `Architecture_M3_CP4ab_R2_Code_Build_Plan.md` | 8503 | `ea2948991762f74db51082b88be8e8833b2a1d5f93c9ed0ba2dd3655825a5ed6` | Bounded runtime-free K2R→K3R→K4 implementation plan following DG-R1, freezing fragment ownership before construction and strengthening A3 without weakening B1–B5. |
| `Architecture_M3_CP4ab_R2_Code_Build_Report.md` | 4832 | `49f63b42005db9f325c3dee1e9ac6d06f2b44af290050a224b1c5e70406ccd88` | K2R→K3R→K4 compile/package PASS, runtime-free; produced immutable package 9485452946 and routed to TB-R1. |
| `Architecture_M3_CP4ab_R4_Code_Build_Report.md` | 10690 | `ad0c8a06b7d1d73941bc89ef1fbdd7b5221be357475d1e4d18aabf9046914ac7` | Runtime-free correction of the fragment Euler proof / validation seam after TB-R2 Review; compile/package PASS and optional DG-R2 instrumentation route selected. |
| `Architecture_M3_CP4ab_R5_Instrumentation_Code_Build_Report.md` | 17504 | `a98176d6d6686d1ed056293bb28e67d4cf0cb4a6c31c094d4a5175cda53fd479` | Default-off diagnostics-only fragment/orbit instrumentation compiled and packaged successfully without changing product semantics or executing runtime. |
| `Architecture_M3_CP4ab_R6_Static_Authority_Code_Build_Report.md` | 8203 | `1ea1ddc75b3c97839b476cf348a04ef13d0bc4faa5bd5bcabb199988fc7ba380` | Static authority gate stopped before semantic mutation/build/package because a lawful distinct-contact order could not be invented inside R6. |
| `Architecture_M3_CP4ab_R7_Cyclic_Port_Order_Code_Build_Plan.md` | 9230 | `b99d572d2abf39b54ea467cc26a599e67bd7e15bb71f185665cbd3a877b637d6` | Runtime-free plan for A1 fan-anchored cyclic port order, A2a ordinal transport, A2b consumption, invariant/tamper checks, and subsequent DG-R3 adjudication. |
| `Architecture_M3_CP4ab_R7_Cyclic_Port_Order_Code_Build_Report.md` | 12764 | `ba6a9081b57a0e4b08a413f891cb29aedf8d0f482f275854b4b01b6970cf730a` | CB-R7 cyclic-port-order implementation and six-target package passed runtime-free; exact semantic source bd362ab5… / package 9502422252 advanced to DG-R3. |
| `Architecture_M3_CP4ab_R9_Mandatory_Arc_Split_Code_Build_Report.md` | 6099 | `a7f70da42460cfe367be74da383d28b331f1f8e9a7f5429ec7190f79b0924e40` | Runtime-free CB-R9 split mandatory arcs at trace terminal nodes, compile/package-passed, and routed immutable package 9505724200 to DG-R4. |
| `Architecture_M3_CP4ab_TB_R1_Independent_Review.md` | 16759 | `dd313c0f4f75e069ac2fa998dff45b6bc76bb6255e53a1ca5125f2f74b2267ca` | Independent review found the ownership correction was working, froze the fragment-complex N1–N6 representation, and routed the remaining disc-certificate representation correction; its original Euler clause was later withdrawn. |
| `Architecture_M3_CP4ab_TB_R2_Artifact_Only_Test_Benchmark_Report.md` | 9340 | `86f0359b37300a3137663e2a9c39f89c8aaf657e4366e38cfad2ddfd5e96447a` | Valid immutable 316 gate returned 306/316 with accepted predecessor 304/304; connectivity cleared while the remaining nine-identity Euler baseline plus B3 ordering required Review. |
| `Architecture_M3_CP4ab_TB_R2_Independent_Review.md` | 18336 | `82ef31006eff6c1cc70392962821cce0e091703131b55a81c6b948657a50991a` | Binding review proved the nine-identity baseline was a false rejection from the wrong F−E_int formula, established that the witness regions were genuine discs, and froze P1–P7 / CB-R4. |
| `Architecture_M3_CP4ab_TB_R2_Independent_Review_Plan.md` | 6315 | `ae5797010d0ea4de458b15e40c41e2a68ef4a0e67cba86371e5fa7703beb8373` | Review plan for the 306/316 TB-R2 result; its questions and stop rules were discharged by the binding TB-R2 independent review and retained only as provenance. |
| `Architecture_M3_CP4b_Mandatory_Independent_Review_Plan.md` | 20932 | `9f79f71b35a79c3c767f307d32fdc33b715be237d2026fb33b808c7aaf41bec0` | Plan containing the binding mandatory-review result: CP4a flood-fill region ownership was prohibited/vacuous, CP4b rewrote accepted authority, the face/component equality was self-referential, K1–K7 were frozen, and CP4a+CP4b were rescoped to CP4ab at gate 316. |
| `evidence/M3_CP4ab_DG_R2/README.md` | 1253 | `938853be5f03662ae8f4e080c3bea84c864916b9db3e7053823f50a98d01af15` | Repository-side raw-evidence index for DG-R2; recorded exact source/package provenance and why stdout/stderr were retained without rerun. |
| `evidence/M3_CP4ab_DG_R2/stderr.txt` | 12059 | `9c1d492558fec0a4f85094c25d649223a69bf175c1884e5d9fc8fdcc57a50b6b` | Raw DG-R2 stderr retained the first typed Euler rejections and follow-on diagnostic/helper output used by the independent review. |
| `evidence/M3_CP4ab_DG_R2/stdout.txt` | 6937 | `4cec3efdeeda65c1e6d0c7c9384541659ee9dacbad55b095dec7548d7dd09d9e` | Raw DG-R2 stdout retained the exact selected identities and semantic execution transcript used by the independent review. |

The retired review plans/reports are no longer resume authority. Binding semantics they introduced remain frozen in `Architecture_M3_CP4_DEFN_Frozen_Definitions.md`; accepted CP4ab outcome/evidence remains in `M3_CP4ab_Closure_Record.md` and `Architecture_M3_CP4ab_TB_R3_Artifact_Only_Test_Benchmark_Report.md`; CP4c execution authority remains in `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md`. No source, test, fixture, selector, build, package, or runtime authority is changed by this documentation consolidation.


### 2026-08-24 — `M3-CP4ab-TB-R3`: cumulative 316 acceptance GREEN; CP4ab closed

**Artifact-only acceptance attempt 1 of 3 — GREEN.** Immutable CB-R11 source/package `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615` executed the unchanged **316 = accepted 304 + CP4ab 12** selector in run/job `32758293793 / 97530833220`. The accepted predecessor is **304/304 PASS** and CP4ab is **12/12 PASS**, for **316/316** with zero failures/errors/disabled and zero orchestration errors. Selector digests: predecessor `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`, CP4ab `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec`, combined `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`.

Result artifact `9531769503` SHA-256 `1b4b3784d55f398d113b18c5bc84543cad9f03c48d329d91005598d63ed801fc`; log artifact `9531770393` SHA-256 `cff83f726fd9fa6dc762126a3632178e0d94abd3d17f4e57b287d0738cd69643`. Package manifest is **27/27 PASS pre/post**; all five source-status snapshots remain empty; package ZIP and source archive retain their CB-R11 digests; materialized source is byte-identical to a fresh extraction before and after runtime. No configure/build/relink/repair/generated discovery or source/test/fixture/selector/package mutation occurred.

`M3-CP4ab` is **CLOSED / ACCEPTED** and `PR8-R042 / M3-CP4b-R001` is **RESOLVED STABLE**. Stable totals remain **42 / 14 / 28**, debt **5**, M3 packages **34**. CP4ab closes after acceptance 1/3 and diagnostic 1/2 in the final reset windows. Latest accepted runtime is now **M3 CP4ab 316/316**. Exact next: `M3-CP4c-CB`, Code + Build only; CP4c has its own fresh 3-attempt budget and cumulative gate **322 = 316 + C1–C6**.

### 2026-08-24 — `M3-CP4ab-DG-R6`: focused 14-identity diagnostic GREEN

**Artifact-only diagnostic; no acceptance attempt.** On immutable CB-R11 source/package `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`, valid run/job `32752282917 / 97511776522` executed the frozen twelve CP4ab identities plus exactly the two Review-required accepted CP3b U5/U6 identities, one process each. Result: **12/12 + 2/2 PASS (14/14)**. A5, B2, B3 and B4 are green; U5 passes the compiled `8U` fan-node-count assertion and U6 passes the first-contact/termination-event assertion.

Evidence artifact `9529473067` SHA-256 `04f094317a49fef949b26175a61e9336597836132b315d9fa85d27bdbf091140`; frozen-selector SHA-256 `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec`; 14-id selector SHA-256 `b8d1f3b7dd3b5fa68213cf11af79ee9d6ca6dbd929fe791649d6ff0611c3f944`. Package manifest **27/27 pre/post**, five source-status snapshots empty, outer ZIP/source archive unchanged. Schema validation `32752015806 / 97510921275` passed before runtime.

The binding DG-R5 Review reset diagnostics to 0/2; this valid DG-R6 consumes **1/2**. Acceptance remains **0/3**; M3 packages **34**; stable **42 / 14 / 28**; debt **5**. Exact next: `M3-CP4ab-TB-R3`, immutable artifact-only acceptance attempt 1/3 on the unchanged frozen 316 gate. CP4c remains blocked.

### 2026-08-24 — `M3-CP4ab-CB-R11`: validation ordering and bounded-surface oracle correction compile/package PASS

**Code + Build only; runtime forbidden and not executed.** Binding Review V0–V8 landed on exact semantic source `157bf784a9cdd2765018206ae0ac26729ed7a584`. V1/V2 validate single-walk and guarded canonical fragment ownership before their derived consumers. V4/V5 use `V_g - E_g + F_g^interior = χ(S)` by excluding independently-derived exterior orbits and replace B4's bare boolean result with a typed failure clause. No fixture, frozen selector, tracing code, `build_arcs()`, U5/U6 assertion, or invariant was weakened.

Run `32747790694`: apply `97497335157` PASS; six-target compile `97497441516` PASS. Package `9527801615` SHA-256 `a8e03a2181ab4ce2de7386d6b38d66cd361a739f21aa33dde6091a6a2fa54557`; compile log `9527802126` SHA-256 `bce655502f46e042c81ab6c706d44bd9ac7999137361e05d6ea8c860cb798f6f`; apply log `9527752362` SHA-256 `bf05c1a7f810d7c1838c2f020df7f3282fd447079817b76fec10dae2646109a3`; source archive `498cbb586c8b5dd1d49c3442364b9483d9f04e6d999432a93e72caa9cb4ab157`; manifest 27/27; five status snapshots empty; `runtimeExecution=false`. Earlier `32744897749` and `32745218945` were invalid pre-mutation patch-transport failures and consume no budget.

M3 packages **34**; acceptance **0/3**; diagnostics **1/2 consumed**; stable **42 / 14 / 28**; debt **5**. Exact next: `M3-CP4ab-DG-R6` using frozen twelve + U5/U6 as a diagnostic-only widened selector. TB-R3 remains blocked.

### 2026-08-24 — `M3-CP4ab-DG-R5-INDEPENDENT-REVIEW`: A5 and B2 are one ordering defect; B4 is off by the boundary count

**Independent Review / planning only. No product, test, fixture, selector, build, package, or runtime;
no acceptance attempt and no diagnostic consumed.** Output:
`Architecture_M3_CP4ab_DG_R5_Independent_Review.md`, binding.

**R1 — the U-series terminal-0-cell subcause is RESOLVED.** DG-R5 moved the gate **2/12 -> 9/12** with
zero `InvalidNetworkBinding`. The DG-R4 Review's static predictions (`9/11/9/3`, fan `8`) are discharged
**in substance** rather than by telemetry: A2 pins `rotation_system().size() == network.nodes().size()`
with exact per-node incidence agreement, A1 derives regions as graph faces, A3 pins exact-once fragment
coverage, A4 pins mandatory-edge preservation across pieces, and B1 pins `boundaryWalkCount == 1`,
`sourceFacesConnected`, and `χ == 1` for **every** region. No mis-split satisfies that conjunction, and a
degree-zero spurious node is rejected at `GlobalTopologyPlan.cpp:788-792`. **No count telemetry is
authorized.**

**Residue that changes the successor plan.** U5 (`5U -> 8U`) and U6 (the terminus-vs-endpoint assertion)
live in `TEST(FieldAlignedCurveNetwork, ...)`. The frozen CP4ab selector is exactly the twelve
`TEST(GlobalTopologyPlan, ...)` identities, so **DG-R5 structurally could not execute either**. The
U-series' own accepted-authority re-proof is compiled and unverified.

**R2/R3 — A5 and B2 are one product validation-ordering defect.** In both, a consumer of a structure
rejects before the check that owns that structure's well-formedness.
- **A5**: the stage-1 `RegionSourceFaceUnowned` check (`:2660-2680`) is a *global support* check by
  documented design, and the erased face is crossed so it stays covered; `build_region_certificates`
  (`:2682`) then dies at `χ = 0` (`:2372`, `:2379-2393`) before the canonical fragment-ownership
  comparison at `:2789-2801`, which already emits exactly `RegionSourceFaceUnowned` with the region and
  missing face for exactly this tamper.
- **B2**: `region_orbit` (`:1166-1175`) elects the orbit whose dart cycle *equals* `region.boundary`; a
  doubled boundary matches none, so `:2441-2445` returns `RotationSystemInconsistent` with only `region`
  set — the observed no-arc payload. `validate_single_boundary_walk` (`:1815-1864`) would return
  `RegionBoundaryNotSingleWalk` with `error().arc == secondWalkArc`, exactly as B2 asserts, but runs
  later inside `build_region_certificate` (`:2115`).
- Decisive: the χ code's own comment (`:2373-2374`) names the single-walk validation as the reason the
  boundary terms cancel, while that validation is evaluated after the path that consumes it. Third
  instance of the class after B3's P4 hoist. **Neither tamper may be weakened to recover an enum.**

**R4 — B4 is a test-oracle arithmetic defect.** A dart-orbit face walk yields the faces of the **capped**
surface, so for a source surface with `b` boundary components `V_g − E_g + F_g^all = χ(S) + b`. The
oracle compares the all-orbits count to `χ(S)`: `9 − 11 + 4 = 2 ≠ 1` on the two-ring witness, and
`6 − 8 + 4 = 2 ≠ 1` before CB-R10 — so the defect **predates and is independent of** the terminal fix.
The exterior orbits are already derived lawfully from `SurfaceCellRailKind::Boundary`
(`tests/FieldAlignedCurveNetworkTests.cpp:1647-1652`) but only after the Euler check. B4 must also stop
being a bare bool, or a red costs a diagnostic to localize.

Corrective measures **V0–V8**, with V2's guard designed specifically to keep B3 green. DEFN amended a
twelfth time: validation ordering, the bounded-surface cellularity identity, and typed oracle failures.
Predicted: A5 green on `RegionSourceFaceUnowned`, B2 green on `RegionBoundaryNotSingleWalk` with
`secondWalkArc`, B3 still green, B4's Euler clause fixed with any residue localized — **11/12 or 12/12**
plus 2/2 on the added CP3b identities. Both counters user-reset: acceptance **0/3**, diagnostics **0/2**.
M3 packages **33**; stable **42 / 14 / 28**; debt **5**; accepted runtime CP3b **304/304**. Exact next:
`M3-CP4ab-CB-R11`, Code + Build only. **TB-R3 remains blocked.**

### 2026-08-24 — `M3-CP4ab-DG-R5`: terminal binding clears; valid diagnostic is 9/12 RED

Valid artifact-only run/job `32695156248 / 97335775412` executes the frozen **12/12/12** selector one identity per process against immutable CB-R10 source/package `6604c27282464b783faedded654ee92ab19e4a6e / 9507735791`. Evidence/log artifacts `9508567626 / 9508567865` have SHA-256 `eee25d1e6b4d4f4a902e5fd43f0ef0ea1025a4fe7d6350ddf75822454d5dee46 / 50481cd41026b0276cbdd72fdab701563da8feeeced8cff2fcec24c447a643dc`. Package manifest is **27/27 PASS** before/after, five source-status files remain empty, and no rebuild/relink/repair/discovery or packaged source/test/fixture/selector mutation occurs.

Semantic result **9 PASS / 3 FAIL**. A1/A2/A3/A4/A6/B1/B3/B5/B6 pass; A4/B6 remain green; the DG-R4 `InvalidNetworkBinding` barrier is absent. A5's unowned-source-face tamper now receives `RegionEulerCharacteristicNotOne` instead of `RegionSourceFaceUnowned`; B2's duplicated-walk tamper receives raw `RotationSystemInconsistent` with no arc payload instead of `RegionBoundaryNotSingleWalk`; B4's positive independent oracle returns false, consistent with its already-queued latent boundary-equation defect. Valid DG consumes diagnostic **1/2**, no acceptance attempt; stable totals remain **42 / 14 / 28**, debt **5**, packages **33**.

Preliminary run `32694960195` failed stale package metadata path assumptions before runtime and executed zero identities, so it consumes nothing. Its corrected retry exposed one reporting pitfall: the machine TSV's B2 first-rejection grep captured the expected enum before the actual enum; raw streams are authoritative. Exact next is `M3-CP4ab-DG-R5-INDEPENDENT-REVIEW`; TB-R3, B4 correction, and CP4c remain blocked. Exact report/plan: `Architecture_M3_CP4ab_DG_R5_Artifact_Only_Diagnostic_Report.md`, `Architecture_M3_CP4ab_DG_R5_Independent_Review_Plan.md`.

### 2026-08-24 — `M3-CP4ab-CB-R10`: publish barrier terminal 0-cells; compile/package PASS

**Code + Build only; no generated Directional runtime.** U0/U4 static preconditions passed on both accepted witnesses before mutation. Exact semantic source `6604c27282464b783faedded654ee92ab19e4a6e` makes the single U1 product correction in A2a: the mandatory-barrier branch calls the already-authoritative `field_aligned_append_contact_node(...)`, retains the same typed failure payload, and binds both `FirstContact` and `MandatoryBarrierTermination` to the fresh node. CB-R9 `GlobalTopologyPlan::build_arcs()` and its endpoint rejection are unchanged. The accepted test surface changes only `5U -> 8U` and strengthens the existing termination identity to require a published node distinct from both mandatory-edge endpoints.

Changed-owner compile `32692398892 / 97328305141` PASS; result artifact `9507700639` digest `a4bedc89a33ae51cf2237689b09712a301127324fd6e1fbe86f8089310f0d95c`. Six-target package compile `32692557352 / 97328729432` PASS; immutable package `9507735791`, digest `025cc6585de3165a4da6a562e0b5114947e3f88325bbe6d12571e782475058d6`; exact-source archive `fb2610e2236b0465ffcd7d302094406a401944705310e8fd899f0561edae28fe`; manifest **27/27 PASS**; five source statuses empty; `runtimeExecution=false`. M3 packages **33**; acceptance **0/3**; diagnostics **0/2**; stable **42 / 14 / 28**; debt **5**; latest accepted runtime remains CP3b **304/304**.

Exact next is artifact-only `M3-CP4ab-DG-R5` on package `9507735791`, frozen selector **12/12/12** one process each. It must test the derived U-series counts/degree and absence of the prior terminal-binding first rejections without rebuild/relink/repair/discovery/mutation; a valid run spends diagnostic **1/2**, no acceptance attempt. Exact report: `Architecture_M3_CP4ab_R10_Terminal_Zero_Cell_Code_Build_Report.md`.

### 2026-08-24 — `M3-CP4ab-DG-R4-INDEPENDENT-REVIEW`: the missing terminus is an A2a authority defect

**Independent Review / planning only. No product, test, fixture, selector, build, package, or runtime;
no acceptance attempt and no diagnostic gate consumed.** Output:
`Architecture_M3_CP4ab_DG_R4_Independent_Review.md`, binding.

**Disposition: A2a / product authority defect.** A2a is the single writer of network 0-cells. Its
transport loop has exactly one exit primitive and it returns an edge (`field_aligned_outgoing_carrier`,
`SurfaceCellTracing.cpp:257-282`), and termination occurs when that carrier is mandatory (`:385-390`), so
a barrier terminus is **always interior** to the mandatory edge by construction of A2a's own model.
`finalize_field_aligned_events` nevertheless publishes a fresh 0-cell for the trace/trace contact case
(`:614-615`) and the loop-closure case (`:688`) while binding the barrier case to `mandatory->firstNode`
(`:657-669`). The terminus is therefore never published, and CB-R9's endpoint rejection
(`GlobalTopologyPlan.cpp:374-381`) — which is **correct and retained** — fires deterministically on every
barrier-terminating trace.

**An A2b-only fix is disproved from source.** A2b would have to mint a `NetworkNodeId` absent from
`network.nodes()`; identity A2 requires `plan.rotation_system().size() == network.nodes().size()`
(`tests/FieldAlignedCurveNetworkTests.cpp:1957`) and both `build_node_loci` (`:506`) and
`build_rotation_system` (`:774`) enumerate the network's node vector.

**Decisive finding.** A2b's edge-locus rotation branch already implements the complete geometry-free model
of a trace ending inside a mandatory edge: it requires exactly two mandatory rays at degree three
(`GlobalTopologyPlan.cpp:897-909`) and orders the three darts strictly — `primary 0`/`2` for the two
pieces by endpoint direction (`:938-950`), the trace ray at `2·sideRank + 1` (`:983-986`) — with no
identifier, container, or coordinate tie-break. That branch is **dead code** under the current A2a
product. `build_node_loci` further discards a node's `sourceEdge` once it has a vertex locus (`:554`),
which is precisely how the endpoint substitution destroys the terminus location.

**Why CP3b accepted it.** The correction is **Euler-neutral** (+1 node, +1 arc), so B4's global
cellularity identity (`tests/FieldAlignedCurveNetworkTests.cpp:1818-1826`) is invariant and structurally
blind to the omission; and `validate_field_aligned_candidate` (`SurfaceCellTracing.cpp:1144-1301`) is
**recompute-and-compare**, which proves reproducibility rather than correctness. No accepted assertion
binds the terminal node's identity.

**Re-proof surface: one accepted numeric constant.** `EXPECT_EQ(5U, network.nodes().size())`
(`tests/FieldAlignedCurveNetworkTests.cpp:471`) becomes **8**, plus a strengthening of
`PublishesTypedFirstContactAndTerminationEvents` requiring the terminal node to differ from both
endpoints. Gate stays **316 = 304 + A1–A6 + B1–B6**.

Corrective measures **U0–U8**. DEFN amended an eleventh time; amendment 10's A2b-locality claim is
withdrawn and its arc rule retained. Predicted on the successor package: nodes `6 -> 9`, arcs `8 -> 11`,
regions `3` unchanged, and **no identity may first-reject `InvalidNetworkBinding` from `build_arcs()`**.
Both counters user-reset: acceptance **0/3**, diagnostics **0/2**. M3 packages **32**; stable
**42 / 14 / 28**; debt **5**; accepted runtime CP3b **304/304**. Exact next: `M3-CP4ab-CB-R10`,
Code + Build only.

### 2026-08-24 — `M3-CP4ab-DG-R4`: valid artifact-only diagnostic stops at missing terminal-position authority

Corrected immutable diagnostic `32688281757 / 97317236929` consumed CB-R9 package `9505724200` with selector **12/12/12**, one identity per process, and unchanged 27/27 package/source postflight. Result **2 PASS / 10 FAIL**: A4/B6 pass; all ten reds first `InvalidNetworkBinding` before region construction. Evidence `9506393233` (`72a4429f...`), log `9506393632` (`d18d6ded...`). Diagnostic **1/2** consumed; acceptance **0/3**.

Static localization: the network publishes only the terminal barrier edge key and binds `MandatoryBarrierTermination` to `mandatory->firstNode`; no sub-edge terminal coordinate/ordinal exists in the candidate trace segment. CB-R9 A2b rejects endpoint split nodes, so the prior Review's assumed interior terminal graph node is absent and the predicted Euler seam is not reached. Preliminary run `32688050369` used the wrong package test binary, selected zero tests, and is invalid harness-only with no budget cost. Exact next: `M3-CP4ab-DG-R4-INDEPENDENT-REVIEW`.

### 2026-08-24 — `M3-CP4ab-CB-R9`: split mandatory arcs at trace terminal nodes; package PASS

**Code + Build only; no generated Directional runtime.** Binding S0 Review T0-T6 completed on semantic source `7a9e174e9375dd917ea00989f9801eaf61b725dc`. T0 mapped trace 0 -> `(6,7)`, trace 1 -> `(8,9)`, trace 2 -> `(6,10)`, each `k=1`, so no multi-terminal stop fired. A2b now splits a parent mandatory edge at its barrier terminal graph node, preserves parent-edge provenance, types unresolved `k>=2` ordering as `MandatoryEdgeTerminalOrderUnresolved`, guards owned mesh-boundary edges with `RegionOwnedBoundaryEdgeMissingFromWalk`, and then applies the reviewed mesh-boundary `V_int` exclusion. A4's oracle was updated to recognize preserved parent edges through their plan-arc pieces; tests were compiled, not executed.

Affected-owner compile `32686030291 / 97311178306` PASS. Six-target package compile `32686147560 / 97311520663` PASS; immutable package `9505724200`, artifact digest `d5967c204844980a7c2563409335429c3a250bc874bebb8107b4ac9041809b2f`, source archive `46bda0d3dcce8649a9a71c7b0e17710f9cef73aa21faf021a26b22d2b24da42d`, manifest **27/27 PASS**, source clean, `runtimeExecution=false`. M3 packages **32**; acceptance **0/3**; diagnostics **0/2**; stable **42 / 14 / 28**; debt **5**. Exact next: `M3-CP4ab-DG-R4` on package `9505724200`; TB-R3/B4/CP4c remain blocked. Exact report: `Architecture_M3_CP4ab_R9_Mandatory_Arc_Split_Code_Build_Report.md`.


### 2026-08-24 — `M3-CP4ab-CB-R8-S0-INDEPENDENT-REVIEW`: mandatory arcs are never split at trace terminal points

**Independent Review / planning only. No product, test, fixture, selector, build, package, or runtime;
no acceptance attempt and no diagnostic gate consumed.** Result:
`Architecture_M3_CP4ab_CB_R8_S0_Independent_Review.md`, binding.

**`M3-CP4ab-CB-R8`'s S0 stop was correct and its derivation is upheld in full**, re-derived
independently this turn from the witness definition. It consumed nothing and prevented S1 from making
the Euler count green while masking a real structural defect.

- **Verdict: case (i) confirmed, cause found.** A mandatory edge on which a trace terminates must be
  split into two arcs at that terminal point, and the frozen arc set never splits it. The defect is
  **DEFN section 4.1's arc definition** — not ownership, not the certificate, and **not upstream of A2b**.
- **The mechanism.** Section 4.1 defined "one mandatory arc per `FieldAlignedMandatoryEdge`" while
  subdividing trace arcs at every incident event node. A trace with `terminalBarrier` set reaches a point
  **interior** to that edge — a genuine 0-cell separating its two pieces into different graph faces.
  Unsplit, the whole arc lands in at most one orbit's walk and is absent from the other's, which is
  exactly why region 2 owns fragments in faces incident to `(6,7)` and `(6,10)` yet records
  `mandatory_boundary_endpoints=[]`.
- **Region 2 mapped.** Its six fragments are the complete fan of inner-ring vertex 1 — `T₄, T₀, B₀, A₀,
  B₄` — plus `A₄`. Vertex 1 is genuinely interior; vertex 6's three incident faces are all owned, which
  is why `allOwned` admitted it, but vertex 6 carries two mesh-boundary edges.
- **Third instance of one class.** Source faces atomic in ownership (fixed, amendment 4) →
  non-mandatory edges atomic in adjacency (fixed, amendment 5) → **mandatory edges atomic in the arc
  set** (amendment 10). Section 4.1 was written in the original CP4-DEFN turn and never revisited while
  sections 4.4 and 6 were amended three times underneath it.
- **A2b-local; CP3b not reopened.** `terminalBarrier`, `FieldAlignedMandatoryEdge`, `incidentFaces`, and
  the trace darts' orbits are all already published, and the arc set is built in
  `GlobalTopologyPlan.cpp`. Reopening A2a would force re-proof of the accepted 304 surface and is not
  warranted.
- **`k = 1` needs no ordering** — the two pieces run from each edge endpoint to the terminal point, and
  each piece's region comes from the terminating trace's dart orbit on that side. **`k ≥ 2` is a typed
  rejection** with `SourceEdgeTopologyKey` and competing `TraceId` loci, never an identifier tie-break.
  **On the accepted witness `k ≤ 1` everywhere**: three traces terminate on five distinct boundary edges.
- **A4 is the canary.** It has been green throughout and asserts mandatory-edge preservation, so A4
  turning red would mean the split *lost* a mandatory edge rather than subdividing it. Parent-edge
  provenance must survive on every piece.
- **Corrective measures T0–T7**, with T0 — the terminal-barrier inventory — a precondition of writing
  code, stopping to Review if any edge shows `k ≥ 2`. DG-R3's **S1** and **S2** are then applied
  unchanged, with S2 now expected satisfiable rather than firing.
- **Prediction.** Region 2's `mandatory_boundary_endpoints` becomes **non-empty** for the first time;
  with S1 region 2 reports `V_int=1 E_int=6 F=6 chi=1` and B3 reports `V_int=0 E_int=1 F=2 chi=1`; the S2
  and T3 codes do not fire; **A4 stays green**; **B3 returns to green**; all three prior baseline codes
  absent. Expected **316/316** or a B2 typed rejection. If `mandatory_boundary_endpoints` is still empty
  after T1–T2, the diagnosis is wrong — return to Review.

Budget unchanged and no reset claimed: acceptance **0/3**, diagnostics **0/2**. M3 packages **31**,
stable **42 / 14 / 28**, produced-witness debt **5**, `PR8-R042` active stable, latest accepted runtime
authority **CP3b 304/304**. DG-R4, TB-R3, B4 correction, and CP4c remain blocked. Exact next is
`M3-CP4ab-CB-R9`.


### 2026-08-23 — `M3-CP4ab-DG-R3-INDEPENDENT-REVIEW`: the Euler baseline is a false rejection; `V_int` omitted the mesh boundary

**Independent Review / planning only. No product, test, fixture, selector, build, package, or runtime;
no acceptance attempt and no diagnostic gate consumed.** Result:
`Architecture_M3_CP4ab_DG_R3_Independent_Review.md`, binding.

**Verdict: `V_int` over-counts by exactly one in both baselines, because the interior rule the planning
agent froze omitted the mesh boundary. CB-R7 implemented that rule faithfully — the rule is the defect.**

- **DG-R3 paid for itself.** It executed 12/12/12 one process each with per-identity evidence and
  published the **actual integers** — the first gate in this checkpoint to return numbers rather than
  only a code, which is why the defect localizes to one missing condition instead of another hypothesis.
- **The measurements.** Region 2 / orbit 3: `V_int=2 E_int=6 F=6 chi=2`. B3 four-triangle fan:
  `V_int=1 E_int=1 F=2 chi=2`. Both off by exactly **+1** on structurally unrelated fixtures.
- **`E_int` and `F` are correct.** A fragment-dual graph with `F=6`, `E_int=6` has cycle rank 1, so
  exactly one interior vertex is possible; `V_int=2` is internally inconsistent with the region's own
  adjacency count. B3's `F=2`, `E_int=1` gives cycle rank 0, so `V_int` must be 0. Corrected:
  `1−6+6 = 1` and `0−1+2 = 1`.
- **The over-counted vertex is outer-ring vertex 6.** DG-R3 records region 2's interior vertices as
  `[1, 6]`, and `make_cp3a_two_ring_skew_disc()` asserts `isBoundaryVertex != 0` for `6..10`.
- **Why the rule is wrong.** The TB-R2 Review verified `χ = V_int − E_int + F` computing `V_int` as *all
  source vertices minus mesh-boundary vertices* — the whole-witness row is literally `11 − 5 = 6` — then
  froze the rule in terms of arcs on the region's walk. Those coincide only when every mesh-boundary edge
  touching a region appears as a mandatory arc on that region's own walk. **The verification table and
  the rule text used different definitions.** Fourth prescription defect in this chain, second of this
  exact shape.
- **The `allOwned` fan test cannot substitute.** A mesh-boundary vertex's fan is a half-disc, so "every
  incident face owned" is satisfiable while the vertex is still on the region's topological boundary.
- **A second inconsistency.** Region 2 reaches vertex 6 yet records **zero mandatory boundary
  endpoints** — its walk contains no mandatory arc. Either ownership and walk disagree about where the
  region ends, or the corner assignment that admitted vertex 6 is wrong. **S1 alone would mask it**, so
  **S0** requires the next turn to decide by hand on the witness before implementing, and **S2** adds a
  typed ownership/walk consistency rejection so the fix cannot hide it.
- **Corrected rule (DEFN amendment 9).** Interior iff **(a) not a mesh-boundary vertex** *(new — the
  fix)*, **(b)** not a singularity-port `sourceVertex` whose trace bounds the region, **(c)** not an
  endpoint of a mandatory arc on that boundary *(still required — catches interior hard-feature rails)*,
  **(d)** every incident fragment owned. Mesh-boundary-ness is derivable combinatorially from
  `incidentFaces.size() == 1`: file-local, no `TriMesh`, no geometry, no public widening.
- **Settled by DG-R3 and closed:** `RegionCutComponentCountDeficit` absent, `RegionInteriorDisconnected`
  absent, R7 cyclic-order sanity **3/3 PASS**, A4/B6 green. **DEFN amendment 8 stands** — it correctly
  withdrew the earlier `orbitByDart` order source as circular and placed ray order in A1 `localSlot`.
- **Prediction.** Region 2 reports `V_int=1 E_int=6 F=6 chi=1`; B3 reports `V_int=0 E_int=1 F=2 chi=1`;
  the Euler code disappears; the two prior baseline codes stay absent; the S2 code does not fire; **B3
  returns to green**. Expected **316/316** or a B2 typed rejection. If `V_int` for region 2 is anything
  other than 1 after S1, the diagnosis is wrong — return to Review.

**Budget — user-authorized reset of both counters.** CP4ab acceptance **0/3**, diagnostic gates **0/2**.
Prior valid REDs and DG-R3 remain historical cost; the ratchet resets with them.

Unchanged: M3 packages **31**, stable **42 / 14 / 28**, produced-witness debt **5**, `PR8-R042` active
stable, latest accepted runtime authority **CP3b 304/304**. TB-R3, B4 correction, and CP4c remain
blocked. Exact next is `M3-CP4ab-CB-R8`.


### 2026-08-23 — `M3-CP4ab-DG-R3`: valid immutable diagnostic RED; cyclic-order sanity green, Euler consequence still false

**Artifact-only diagnostic / attempt-free. No rebuild, relink, patch, regeneration, source/test/fixture/selector/package mutation, or acceptance attempt.** Exact CB-R7 source/package `bd362ab5e7bb50ebb1fcf7bb50c99697923ad4e4 / 9502422252`; diagnostic run/job `32677922186 / 97289321776` is a valid harness PASS. Package manifest is **27/27 PASS** before/after and materialized source is byte-identical to fresh extraction.

Frozen CP4ab surface executed **12/12/12**, one identity per process in frozen order: **2 PASS / 10 FAIL**. A4/B6 pass; every red first rejects `RegionEulerCharacteristicNotOne`. Nine repeated first-Euler records agree on region `2`, orbit `3`, `V_int=2 E_int=6 F=6 chi=2`; B3 records `V_int=1 E_int=1 F=2 chi=2`. The Review-approved R7 cyclic-order sanity surface is **3/3 PASS**, proving the focused A1 slot / equivalent-Z4 / A2a enumeration-invariance seams execute but not the downstream fragment-corner/Euler result.

Evidence artifact `9503250049` (`70e1bd40ae6018640a740dc9179b23f05f0a9242f5290d8012ba438dd7a7c8c9`), log artifact `9503250349` (`1a9830ba15b81eaefe88f2cd1b220acbe66db9a114a3bc3655badc8efa3e9a50`), machine packet SHA-256 `69429f3e328cc4ac8170ec93dde09bd9f1b3fc06bbac4c076e8133b7ced67388`.

Diagnostic accounting advances **0/2 -> 1/2**; acceptance stays **0/3**; packages stay **31**; stable accounting stays **42 / 14 / 28**, debt **5**. `PR8-R042` remains active; no restoration-then-loss occurred. Exact next is **`M3-CP4ab-DG-R3-INDEPENDENT-REVIEW`**. TB-R3, B4 correction, and CP4c remain blocked.


### 2026-08-23 — `M3-CP4ab-CB-R6-STATIC-AUTHORITY-INDEPENDENT-REVIEW`: option (1) proved; no earlier product reopened

**Independent Review / planning only. No product, test, fixture, selector, build, package, or runtime;
no acceptance attempt and no diagnostic gate consumed.** Result:
`Architecture_M3_CP4ab_CB_R6_Static_Authority_Independent_Review.md`, binding.

**Mandated question answered: OPTION (1).** Fragment-corner incidence **is** uniquely reconstructible
from existing accepted authority **without any carrier-contact order**. **No earlier semantic stage is
reopened.** Option (2)'s owner and re-proof boundary are specified as the authorized fallback, live only
if the Q1 proof obligation fails.

- **The R6 stop is upheld in full.** It changed no source byte, ran no compile, created no package, and
  consumed no budget — the third time in this checkpoint that stopping before mutation was cheaper than
  a wrong package. Its enumeration of forbidden tie-breakers is complete and correct.
- **F1 — the gap localized to one line.** `build_rotation_system(...)` already resolves the oriented fan
  via `build_vertex_fan_slots(...)` (`GlobalTopologyPlan.cpp:490-540`), assigning every incident face and
  edge a fan slot. Trace rays then take `key.primary = 2*faceSlot + 1`, so **two rays leaving one vertex
  inside the same face tie**, separated only by `kind`/`trace`/`arc`/`orientation` — all identifiers. The
  fan order exists and is exact; only the intra-wedge order of co-facial rays was missing.
- **F2 — the taxonomy that makes it provable**, derived from `SurfaceCellTracing.cpp`. A source face
  carries **at most one full chord**: `field_aligned_first_trace_contact(...)` (`:496-527`) terminates
  any later trace entering an occupied face. **Terminal segments are slits, not cuts** — the trim at
  `:608-613` retains the contacting segment, so its non-optional `outgoingCarrier` names an edge the
  trace never reaches and **must never be read as a chord exit**. The **shared-origin exemption**
  (`:513-518`) is the only way one face holds several separating cuts, and it is live on the accepted
  witness: CP2b established that skew-fan face 0 carries two ports at branches 2 and 3, both leaving
  through the same opposite edge.
- **F3 — the construction.** A single chord separates the corner **shared by `incomingCarrier` and
  `outgoingCarrier`**. Co-facial rays resolve by **orbit-side chaining**: walk the oriented fan carrying
  a running orbit label; a non-mandatory fan edge does not end the sector, a mandatory arc does, and
  inside a face holding *k* rays the next ray is **the unique one carrying the running label on a side**.
  The rays' order is never read — it is forced. Uses only `walk.orbitByDart` and the oriented fan: no ID,
  no container position, no coordinate, no distance.
- **Residual ambiguity is a typed rejection** with `SourceVertexId`, `SourceFaceTopologyKey`, and the
  competing `NetworkArcId` loci. Never a tie-break. If it fires, Review section 8 becomes live.
- **Two alternatives rejected and recorded.** Branch index gives only a cyclic order with no anchor — the
  anchor needs `effort`/geometry not published to A2b. `entryTransport` records a Z4 branch change, not a
  position.
- **Option (2), if Q1 step 2 fails.** Owner is **A2a (the CP3b event graph)** — never A2b, which would
  create a second writer for contact authority. Minimum relation is a per-contact ordinal along each
  carrier, oriented with the canonical edge key. Re-proof boundary is bounded in advance: the CP3b
  semantic digest and its six identities re-run unchanged in name; the 298 preceding identities and the
  A2b surface stay untouched; the CP4ab gate stays **316**.
- **DEFN amendment 7** freezes the taxonomy, the construction, and the rejection. Corrective measures
  **Q1–Q7**, with Q1 — a four-part hand derivation recorded in the CB-R7 report — a **precondition of
  writing any code**, because two consecutive prescriptions in this checkpoint already failed for want
  of a falsifying check.

**Budget — user-authorized reset of both counters.** CP4ab acceptance is **0/3** and diagnostic gates are
**0/2**. Prior valid REDs remain historical cost and the ratchet resets with them. Spending one restored
diagnostic on the CB-R7 package before TB-R3 is recommended — the orbit-side chaining is the first
genuinely new mechanism in this checkpoint.

Unchanged: M3 packages **30**, stable **42 / 14 / 28**, produced-witness debt **5**, `PR8-R042` active
stable, latest accepted runtime authority **CP3b 304/304**. DG-R3, TB-R3, B4 correction, and CP4c remain
blocked. Exact next is `M3-CP4ab-CB-R7`.


### 2026-08-23 — `M3-CP4ab-CB-R5-PACKAGE-INDEPENDENT-REVIEW`: Insufficient Evidence; DG-R3 denied

**Independent Review / planning and evidence only.** Output:
`Architecture_M3_CP4ab_CB_R5_Package_Independent_Review.md`. No product, header/API, test,
helper, fixture, selector, build/workflow, or normative-definition change; no compile, package,
generated binary, test, benchmark, DG, TB, diagnostic, or acceptance execution.

Exact semantic diff `ae13180a188a72c4e19c614052ee56370162f1af..6450360bc4039add124a401241224f305b6aeac8`
changes only `src/geometry/GlobalTopologyPlan.cpp`. Exact default-off gating, deterministic sorting,
transient-evidence lifetime, first-Euler emission, and semantic/product/certificate/digest
non-interference pass. Package `9499550845`, outer SHA-256
`5f2848aea90a76c59ceaad34f22e26d95d976d01eb993a158e9dfc986cceaa30`, log
`9499551061 / b0320effee6b8c7409fe7a77e8e9cb715189fdf61f9fbe2711978be83e4871e1`, source archive
`07ccbe7177d4c8171fc289eb3a4c4920fe09ed77b96856bef9813d53e69b5a0d`, manifest **27/27**,
six binaries/two libraries, five empty statuses, and `runtimeExecution=false` are independently verified.

Decision is **Insufficient Evidence** because canonical face/edge keys erase orientation/contact
order, set-valued edge/orbit evidence collapses multiplicity, and no explicit or equivalently lossless
`(source face, owning orbit) -> incident source vertices` partition exists. The proposed combined
12-identity gtest command also cannot produce per-identity process exits/raw streams or provable
Euler-record association. DG-R3 is not authorized.

Exact next recorded, not executed:
`M3-CP4ab-CB-R6-INSTRUMENTATION-SCHEMA-CORRECTION`, runtime-free and diagnostics-only in the same
sole `.cpp`, followed by another independent package Review. B4 remains latent for a later semantic
CB and is neither executed nor fixed now. Accounting stays packages **30**, diagnostics **1/2**,
acceptance **0/3**, stable **42/14/28**, debt **5**.


### 2026-08-23 — `M3-CP4ab-CB-R5-INSTRUMENTATION`: gated fragment/orbit diagnostics package PASS

**Runtime-free diagnostics-only Code + Build.** Exact semantic source
`6450360bc4039add124a401241224f305b6aeac8` changes only
`src/geometry/GlobalTopologyPlan.cpp`. Exact
`DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1` gating exposes deterministic
`M3_CP4AB_FRAGMENT_DIAG` exterior-orbit, trace-segment, and first-Euler
records, including region/orbit/support, fragment/edge-orbit evidence,
trace-piece counts, current candidate/boundary/interior sets, and V/E/F/chi.
Off mode skips evidence collection/emission. File-local diagnostics do not
enter returns, comparisons, branches, counts, certificates, products, digests,
ABI, or public API. No semantic rule, test/helper/fixture/selector/B4,
adjacency, ownership, network, validation order, or build configuration
changed.

Affected-owner compile `32664082502 / 97254664604` passed. Exact six-target
package `32664193497 / 97254938156` passed: result artifact `9499550845`,
outer SHA-256
`5f2848aea90a76c59ceaad34f22e26d95d976d01eb993a158e9dfc986cceaa30`;
activity log `9499551061`,
`b0320effee6b8c7409fe7a77e8e9cb715189fdf61f9fbe2711978be83e4871e1`;
source archive
`07ccbe7177d4c8171fc289eb3a4c4920fe09ed77b96856bef9813d53e69b5a0d`;
manifest **27/27**, five empty source statuses, six binaries/two libraries,
`runtimeExecution=false`. No generated binary, discovery, diagnostic, test,
benchmark, or acceptance body ran.

Package count advances exactly once **29 -> 30**. Diagnostics remain **1/2**,
acceptance **0/3**, stable **42/14/28**, debt **5**. Exact next is
`M3-CP4ab-CB-R5-PACKAGE-INDEPENDENT-REVIEW`; only it may approve the retained
`M3-CP4ab-DG-R3-EXEC` plan. TB-R3 and CP4c remain blocked.

### 2026-08-23 — `M3-CP4ab-DG-R2-REV`: support-face `V_int` conflation isolated; instrumentation-only CB-R5 selected

**Independent Review / planning only.** No product, test, fixture, selector, build configuration,
compile, package, generated runtime, test, benchmark, acceptance attempt, or diagnostic gate executed.
Binding output: `Architecture_M3_CP4ab_DG_R2_Independent_Review.md`.

DG-R2 is valid semantic diagnostic evidence on exact CB-R4 source/package
`ae13180a188a72c4e19c614052ee56370162f1af / 9498456436`: exact producer binary and frozen
12-selector, **12/12/12**, **2 PASS / 10 FAIL**, exit 1; A4/B6 pass; all ten reds first report
`RegionEulerCharacteristicNotOne`. It consumes diagnostic **1/2**, no acceptance attempt. Exact raw
stdout/stderr are retained under `.agents/Directional/evidence/M3_CP4ab_DG_R2/` without rerun. The
semantic result is post-hoc provenance-valid but the historical packet lacks complete common paired
pre/postflight and machine-readable identity records; that process finding remains separate.

The current `vertexCount` is not binding `V_int`: it unions all three source corners of every support
face even when a trace divides that face into different orbit fragments. Support-face membership was
substituted for fragment-corner incidence. `faceCount`, `edgeCount`, N1 adjacency, K2R/K3R ownership,
mandatory endpoint authority, trace-port authority, and contact-node exclusion remain correct/settled.
The later `std::get` exception is all-ten helper fallout after typed rejection, not a B3 product fault.

B4 is structurally non-mirror but its compiled global equation incorrectly includes the exterior
face-walk orbit as a source-disc 2-cell. The later semantic correction must preserve the independent
oracle and use `V_g-E_g+(F_all-F_exterior)=chi(source)`.

Decision: **insufficient evidence for a semantic patch** because exact fragment-corner evidence is
discarded before certificate construction. Exact next is runtime-free
`M3-CP4ab-CB-R5-INSTRUMENTATION`, limited to environment-gated deterministic diagnostics in
`GlobalTopologyPlan.cpp`; then the last diagnostic 2/2 may execute the unchanged 12-selector with full
evidence and must return to Review. TB-R3 is blocked. Accounting remains M3 packages **29**, acceptance
**0/3**, stable **42 / 14 / 28**, debt **5**, `PR8-R042` active stable, latest accepted runtime CP3b
**304/304**, CP4c blocked.

### 2026-08-23 — `M3-CP4ab-CB-R4` corrected Euler proof compile/package PASS; DG-R2 selected

**Runtime-free Code + Build.** P1 passed before semantic mutation on all four falsifying cases:
`(V_int,E_int,F,chi) = (0,1,2,1), (1,5,5,1), (1,6,6,1), (6,20,15,1)`.
Exact semantic source `ae13180a188a72c4e19c614052ee56370162f1af` changes only the region
certificate header/implementation, B4 independent oracle, CB-R4 report, TODO, and live handoff.
`vertexCount` now means exact `V_int`; `edgeCount` and `faceCount` are unchanged; chi is
`V_int-E_int+F`; the singularity guard runs before orbit resolution; B4 asserts global cellularity.
Adjacency, K2R/K3R ownership, network, fixture, and B1-B5 semantics are unchanged.

Authoritative run/job `32659894873 / 97244335107` compiled the authorized six targets and packaged
PASS. Immutable result `9498456436` has ZIP SHA-256
`9c6009a4d1600cd0a34c8fee4476d8080a8f7ff85c7a0f83b1baee32968aa3e2`, recursive manifest 27/27,
five empty source-status snapshots, and exact-source archive SHA-256
`6d392c54db79f6253dc2eaaf48e8d393990527b934e9957e3a005369c325d9f0`. Persistent log
`9498456592` has SHA-256 `1ec44df3993d9bc17738332fa14f3ce9295a1115707d7de4de5758803d9d0689`.
No generated Directional binary, test, benchmark, discovery, help/list/version command, acceptance
body, or diagnostic gate executed; `runtimeExecution=false`.

M3 packages 28 -> **29**. Acceptance remains **0/3**, diagnostics **0/2**, stable accounting
**42 / 14 / 28**, produced-witness debt **5**, `PR8-R042` active stable, latest accepted runtime CP3b
304/304. Exact next is selected optional diagnostic `M3-CP4ab-DG-R2`; then TB-R3. CP4c blocked.

### 2026-08-23 — `M3-CP4ab-TB-R2-INDEPENDENT-REVIEW`: the Euler baseline is a false rejection; `F − E_int` withdrawn

**Independent Review / planning only. No product, test, fixture, selector, build, package, or runtime;
no acceptance attempt and no diagnostic gate consumed.** Result:
`Architecture_M3_CP4ab_TB_R2_Independent_Review.md`, binding.

**Verdict: the nine-identity `RegionEulerCharacteristicNotOne` baseline is a FALSE REJECTION caused by a
formula the planning agent prescribed. The regions are genuine discs.** CB-R3 implemented the
specification faithfully; the specification was wrong.

- **Two results settled by runtime and not to be revisited.** `RegionInteriorDisconnected` is **gone**,
  which is only possible if the fragment BFS now reaches every fragment — so the N1 / amendment-5
  fragment-adjacency rule is **correct**. `RegionCutComponentCountDeficit` has been absent across two
  consecutive gates — so K2R/K3R ownership is **not** reopened.
- **F1 — `χ = F − E_int` is mathematically wrong.** The reduction holds only when the fragment-dual
  graph is acyclic, which is the property the disc proof exists to test. The faces around an interior
  source vertex of valence `n` form an `n`-cycle, giving `F − E_int = 0` for a patch that is plainly a
  disc. Computed on the accepted CP3a two-ring witness this turn: **`F − E_int = −5`** where
  `V − E + F = 11 − 25 + 15 = 1`. A pentagon fan gives **0** against a true `1`. The only case checked
  when the formula was frozen — two triangles glued on an edge — is the degenerate one where the error
  vanishes, which is why it survived review.
- **F2 — second consecutive specification error, pattern named.** The prior Review under-specified
  ("computes on fragments"); this one supplied a compressed formula verified only against a
  non-falsifying case. Both times a shortcut replaced the exact construction. Corrective measure **P1**
  therefore makes counterexample verification a **binding precondition of the Code + Build turn**.
- **F3 — the corrected reduction is `χ = V_int − E_int + F`**, derived by cancelling `V_bd = E_bd` for a
  single closed walk with no pinch — both preconditions already validated upstream by
  `validate_single_boundary_walk(...)` and `validate_no_region_fragment_pinch(...)`. Verified on two
  glued triangles (1), a pentagon fan (1), a hexagon fan (1), and the whole witness mesh (1). **`F` and
  `E_int` in the current code are already correct**; only `vertexCount` must become `V_int`, under an
  interior-vertex rule that must not read `FieldAlignedCurveNetworkNode::sourceVertex`.
- **F4 — B3's red is a validation-ordering seam.** `region_orbit(...)` now runs before
  `build_region_certificate(...)`, so B3's tamper hits `RotationSystemInconsistent` before the
  interior-singularity check can fire. Both guards are correct; the ordering shadows one. Hoist the
  singularity check ahead of orbit resolution — it needs neither the orbit nor the pinch result.
- **F5 — B4 is still a mirror; N4 was not discharged.** Two gates have passed with the oracle
  structurally unable to detect a defect it shares. It must assert the **global cellularity identity**
  `V_g − E_g + F_g = χ(source surface)`, which shares no code path with the per-region certificate.
- **DEFN amendment 6** withdraws amendment 5's Euler clause and freezes the corrected reduction.
  Amendment 5's other three clauses — barrier vs crossing, fragment adjacency, pinch rejection — are
  unaffected and proven correct.
- **Corrective measures P1–P7** with a falsifiable prediction: the Euler code disappears, the two prior
  baseline codes stay absent, **B3 returns to green**, and the expected outcome is **316/316** or a B2
  typed rejection — B2 has still never executed its intended seam.

**Budget — user-authorized reset of both counters.** CP4ab acceptance is **0/3** and diagnostic gates are
**0/2**. TB-R1 and TB-R2's valid REDs remain in the record as historical cost and the ratchet resets with
them. Spending one restored diagnostic on the CB-R4 package before TB-R3 is recommended but optional.

Unchanged: M3 packages **28**, stable **42 / 14 / 28**, produced-witness debt **5**, `PR8-R042` active
stable, latest accepted runtime authority **CP3b 304/304**, CP4c blocked. Exact next is
`M3-CP4ab-CB-R4`.


### 2026-08-23 — `M3-CP4ab-TB-R2` valid RED 306/316; connectivity clears, Euler/ordering Review is exact next

Artifact-only reset-window acceptance attempt **1 of 3** consumed immutable package `9496035583` / exact semantic source `6dc70fd54a412802c1000cefa6fbc982de0017e7` with the frozen **316 = accepted 304 + A1-A6 + B1-B6** selector. The valid gate executed **316/316 unique** and returned **306 PASS / 10 FAIL** while the accepted predecessor remained **304/304 PASS**. A4/B6 pass. Nine common-baseline identities now first-reject `RegionEulerCharacteristicNotOne`; B3 expects `RegionContainsInteriorSingularity` but receives `RotationSystemInconsistent`.

The R3 falsifiable connectivity prediction succeeded: `RegionInteriorDisconnected` is absent and `RegionCutComponentCountDeficit` remains absent. Static analysis therefore advances the seam to a connected cyclic fragment-dual graph under amendment 5's `chi = F - E_int` reduction. Because frozen Section 6 still defines exact closure Euler as `V-E+F` and says its content is unchanged, the runtime does not by itself decide whether the region is genuinely non-disc or whether legal 0-cell incidence was lost by the dual reduction. B3 separately exposes that `region_orbit(...)` now rejects its tampered candidate before the frozen interior-singularity check runs. Exact next is `M3-CP4ab-TB-R2-INDEPENDENT-REVIEW`; no local CB-R4 patch is authorized first.

Package postflight remains 27/27 and source/package byte-identical. User-visible runtime evidence `Directional__M3-CP4ab-TB-R2__runtime-evidence.zip` SHA-256 `9bea780b13632a917262dd64f6cf51fd9787082fc4ed5ce412cf4d3a1dc9c018`. Two invalid controls are retained but excluded: an externally terminated incomplete full-gate launch, and a complete control whose packaged-source extraction incorrectly stripped the archive root and manufactured 26 missing-fixture predecessor reds. Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **28**, diagnostics **2/2 exhausted**, `PR8-R042` active stable, latest accepted runtime CP3b **304/304**, CP4c blocked.


### 2026-08-23 — `M3-CP4ab-CB-R3` fragment-disc correction compile/package PASS; next TB-R2

**Code + Build only; no generated Directional runtime executed.** Exact semantic source `6dc70fd54a412802c1000cefa6fbc982de0017e7`;
authoritative run/job `32650465002 / 97221126733` PASS. Immutable package `9496035583` SHA-256
`c0816cf4deda253c7fba733b2712ea41507458d41e55be1e72016b1d6b888c63` verifies 27/27, embeds exact-source archive `c92d94bdc6a15eca75546e180e42c5d5aa18f440e3708fb50727c6331a4cfd7c`, has preflight/build
exit codes 0/0 and five empty source statuses, and records `runtimeExecution=false`.

M3 packages 27 -> **28**; acceptance remains **0/3** under the user reset; diagnostics **2/2 exhausted**;
stable accounting **42 / 14 / 28**, debt **5**, `PR8-R042` active stable, latest runtime CP3b 304/304.
Exact next is `M3-CP4ab-TB-R2`, package `9496035583`; valid completion consumes attempt **1/3**. CP4c blocked.

### 2026-08-23 — `M3-CP4ab-TB-R1-INDEPENDENT-REVIEW` complete; fragment-complex definitions frozen; attempts user-reset

**Independent Review / planning only. No product, test, fixture, selector, build, package, or runtime;
no acceptance attempt and no diagnostic gate consumed.** Result:
`Architecture_M3_CP4ab_TB_R1_Independent_Review.md`, binding. Verdict: **the correction is working; do
not reopen ownership.**

- **TB-R1 was progress, not a stall.** 307/316 with the accepted predecessor 304/304 green.
  `RegionCutComponentCountDeficit` is **absent** — the routing Review's falsifiable K2R/K3R prediction
  held exactly. Nine reds now share **one** typed cause instead of a seven-way umbrella; **B3 is newly
  green at its own `RegionContainsInteriorSingularity` seam**, the first B-layer identity ever to reach
  its intended seam; and A3 was genuinely rewritten under K4 to assert that the two darts of an interior
  trace enclose distinct graph faces. The `M3-CP4ab-DG-R1` measurement (`drafts = 3`,
  `cutComponents = 2`, all five singular-fan faces in component 0) also stands corroborated.
- **F1 — the proofs were never converted to fragments.** Confirmed at source:
  `build_region_certificate(...)` keys connectivity by whole `SourceFaceTopologyKey` and vetoes any edge
  in `network_cut_edges(...)`, which unions mandatory edges **and every trace-crossed edge**
  (`GlobalTopologyPlan.cpp:1432-1445`); and it computes `V/E/F` by unioning **complete source triangles**
  (`:1470-1489`). The B4 oracle carries the identical model
  (`FieldAlignedCurveNetworkTests.cpp:1488-1511`). That is exactly why nine identities stop at
  `RegionInteriorDisconnected`.
- **F2 — the recurring class is atomicity, one level down each time.** Faces atomic (fixed by K2R/K3R),
  edges atomic (open, causing the current reds), vertices/edges atomic in χ (open, not yet reached
  because connectivity stops execution first). **N1–N3 must land in one package** or CB-R3 buys one
  identity and returns with a χ failure.
- **F3 — the prior DEFN amendment under-specified this.** "The disc proof now computes on fragments" was
  a handwave over a non-trivial definition: it never said how two fragments are adjacent, or what
  `V`, `E`, `F` mean for a fragment complex. The implementation reasonably left the whole-face code in
  place. This is a correction to the planning turn, not a finding against the implementation.
- **Frozen definitions (DEFN amended a third time).** *Barrier vs crossing* — a mandatory
  `Boundary`/`HardFeature` edge is a true barrier; a trace crossing is a subdivision point that removes
  no interval and blocks no adjacency by itself. *Fragment adjacency* — `(F1, o1)` and `(F2, o2)` sharing
  edge `e` are adjacent **iff `e` is not mandatory and `o1 == o2`**; fully combinatorial, no geometry, no
  interval ordering, because the orbit *is* the graph face. *Euler characteristic* — `χ = F − E_int`,
  never a whole-triangle union; `edgeCount` redefined to `E_int`, `vertexCount` leaves χ. *Pinch
  rejection* — fragments sharing a 0-cell but no 1-cell get their own frozen code with both source-face
  loci.
- **F4 — B4 is a mirror, not an independent oracle.** It reads the published `region.sourceFaces`,
  re-runs the same model, and compares six certificate fields one by one, so it can only ever agree with
  a wrong implementation — which is the current state, both sides sharing the whole-edge model.
  `REORIENTATION_PLAN.md` section 2 rule 7 forbids deriving expected state from the output being
  validated. **N4** requires B4 to re-derive the *partition* from the network and rotation system, assert
  the dual graph is a **tree** (`E_int == F − 1`), and drop the `vertexCount` comparison.
- **Corrective measures N1–N6**, N1–N3 together. N5 forbids reopening ownership; N6 requires stopping
  before widening the public API if a needed datum is unpublished.
- **Falsifiable prediction.** `RegionInteriorDisconnected` disappears; `RegionCutComponentCountDeficit`
  stays absent; expect green or a B1/B2 typed rejection naming a region; A4/B3/B6 stay green and the
  predecessor stays 304/304. If `RegionInteriorDisconnected` survives N1, the adjacency rule is wrong and
  the work returns to Review rather than being patched.

**Budget — user-authorized reset.** The user explicitly authorized resetting acceptance attempts to
zero. CP4ab acceptance is now **0/3 consumed**; TB-R1's valid RED remains in the record as historical
cost and the mandatory-review ratchet resets with it. **Diagnostic gates remain 2/2 used** — the
authorization named attempts and was not extended further — so CB-R3 advances directly to
`M3-CP4ab-TB-R2`, which will be the first evidence.

`Architecture_M3_CP4ab_R3_Code_Build_Plan.md` is upheld and **completed** by this Review, which governs
where they differ. M3 packages remain **27**, stable accounting **42 / 14 / 28**, produced-witness debt
**5**, `PR8-R042` active stable, latest accepted runtime authority **CP3b 304/304**, CP4c blocked. Exact
next is `M3-CP4ab-CB-R3`.


### 2026-08-23 — `M3-CP4ab-TB-R1` valid 316 gate is RED 307/316; fragment-disc certificate is exact next

**Artifact-only acceptance attempt 1 of 3.** Immutable CB-R2 package `9485452946` from exact semantic source `8fe9e5429a840d52c426ce04aec1b783f980fbbe` executed the frozen **316 = accepted 304 + A1–A6 + B1–B6** selector. The accepted predecessor is **304/304 PASS**. A4/B3/B6 pass; A1/A2/A3/A5/A6/B1/B2/B4/B5 fail, all first typed `RegionInteriorDisconnected`. The prior `RegionCutComponentCountDeficit` seam is absent, satisfying the binding routing Review's K2R/K3R prediction.

Static analysis localizes the residual defect to disc-proof representation continuity under `PR8-R042 / RP-01`: production `build_region_certificate(...)` and the independent B4 oracle still compute connectivity and `V/E/F` over whole source-face / whole trace-crossed-edge incidence even though DEFN requires the unchanged proof on `(SourceFaceTopologyKey, orbit)` fragments. Package manifest remains **27/27** and package/source postflight is byte-identical; no rebuild, repair, discovery regeneration, source/test/fixture/selector mutation, or new package occurred.

Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **27**; CP4ab acceptance is **1/3 consumed**, diagnostics **2/2 exhausted**, latest accepted runtime remains CP3b **304/304**, and CP4c remains blocked. Exact next is `M3-CP4ab-CB-R3`, runtime-free fragment-disc certificate/independent-oracle completion.

### 2026-08-23 — `M3-CP4ab-CB-R2` completes K2R → K3R → K4; compile/package PASS; next is TB-R1 316

**Code + Build only; no generated Directional runtime executed.** K2R was narrowed and frozen at `c0e351925811de2fb6301a88689c44c36945ef63` after the
first documentation write was detected as overbroad before semantic mutation. Exact semantic source `8fe9e5429a840d52c426ce04aec1b783f980fbbe` removes
the old whole-face cardinality construction seam, makes non-exterior graph-face orbits primary, derives fragment support
from oriented `walk.orbitByDart` evidence, keeps `network_cut_edges(...)` as connectivity evidence only, and strengthens
A3 with an enclosure-based ownership/flood-fill negative. B1–B5 remain unchanged in content.

Run `32610711102` passed producer preflight (`97123244876`) and six-target package compile (`97123358116`). Immutable
package `9485452946` SHA-256 `4943797205271739583d56592ac2ec72ead407203cb429d4df794d54e3c2d00c` verifies 27/27, embeds exact source `8fe9e5429a840d52c426ce04aec1b783f980fbbe` and source archive
SHA-256 `b2fc8801bc9ba028a455f4bcf682c692b377a162ecf60adb78ec94909aa6cef5`, carries five empty source-status snapshots, and records `runtimeExecution=false`,
`turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`. Package log `9485453202` SHA-256
`190a4d62437195c4a350231512ad91c92e9ef6282ba2c7cbfed683e012b239fa`. M3 package count advances **26 → 27**; acceptance attempts remain **0/3** because this was runtime-free;
diagnostics remain exhausted **2/2**; stable accounting remains **42 / 14 / 28**, debt **5**, and `PR8-R042` remains active
until runtime evidence closes it. Latest accepted runtime authority remains CP3b 304/304.

Exact next is `M3-CP4ab-TB-R1`, artifact-only on package `9485452946`, frozen full gate
**316 = 304 + A1–A6 + B1–B6**; only 316/316 accepts. CP4c remains blocked.

### 2026-08-22 — `M3-CP4ab-DG-R1` confirms fragment-ownership finding by measurement; next is K2R → K3R → K4

**Artifact-only measurement diagnostic 2 of 2; no source/build/package mutation and no acceptance attempt.**
Immutable K1 package `9478766432` measured the accepted two-ring witness at
`drafts.size() = 3`, `cutComponents.size() = 2`, `walk.orbits.size() = 4`, with exactly one exterior
orbit (`1`). The five singular-fan source faces all remain in cut component 0; component 1 contains only
`(1,5,6)` and `(1,6,7)`. This directly confirms binding routing Review Part A §A.3: whole-source-face
connectivity cannot represent graph-face/orbit ownership when trace arcs cross face interiors.

The exact ten prior-red identities executed 10/10 uninstrumented and remain first-rejection
`RegionCutComponentCountDeficit`, which is expected for this measurement gate. Package postflight remains
27/27 with unchanged ZIP `d2568ff62c07f2b8e50ee26643cbe394ca906d81bdf7ab2363d5fc3cc929bd74`
and exact-source archive `54d3645ede2e1188974350c20ee3041b5612493989eab62b659cfb6bb670314b`.
Review §A.3 is therefore confirmed and the exact successor is `M3-CP4ab-CB-R2`, ordered K2R → K3R → K4.
Diagnostic budget is now 2/2 used; CP4ab acceptance remains 0/3, M3 packages 26, stable accounting
42 / 14 / 28, debt 5, and latest accepted runtime authority CP3b 304/304. CP4c remains blocked.

Two resolved non-stable process/orchestration candidates are recorded in the regression tracker: the
start-of-turn read-mode/stale-evidence cleanup sequencing miss, and one discarded exploratory ptrace probe
that resumed past a breakpoint without RIP rewind. Neither affects product/package/runtime authority.


### 2026-08-22 — `M3-CP4ab-K5-ROUTING-REVIEW` complete; routing corrected to K3; DEFN 4.4 amended to fragment ownership

**Independent Review / planning only. No product, test, fixture, selector, build, package, or runtime;
no acceptance attempt and no diagnostic gate consumed.** Result is Part A of
`Architecture_M3_CP4ab_K5_Routing_Independent_Review_Plan.md` and is binding. Decision: **Option C**,
an ordered K2R/K3R bundle preceded by one measurement gate.

- **The DG routing was wrong.** `RegionCutComponentCountDeficit` routes to **K3, not K5**. The `-> K5`
  table was authored inside `M3-CP4ab-CB`, a turn scoped to K1 diagnosability with **no semantic
  change**; assigning corrective-measure ownership is a planning act and cannot override the binding
  mandatory Review, whose §A.7 already assigned the cardinality precondition to K3. **Durable rule
  recorded: an implementation turn may name and localize conditions but may not assign or re-assign
  corrective families; any routing table it produces is a hypothesis for the next Review.**
- **`M3-CP4ab-CB-R1` was right to stop and is upheld in full.** Its §2.3/§2.4 reasoning is correct.
  Stopping consumed no attempt, no diagnostic, and no package, and it kept a K3-shaped ownership change
  from entering the product under a K5 label.
- **The decisive finding goes beyond F5.** `network_cut_edges(...)` cuts the edges a trace *crosses*
  while ownership is a set of **whole** source faces — but trace arcs run through face interiors and a
  source face is atomic. On the accepted two-ring witness, traces leave the centre singularity through
  the edge *opposite* it, so the **spoke** edges are never cut; the fan faces stay adjacent across those
  uncut spokes and the flood fill keeps the whole fan as **one** cut component, while
  `walk_graph_faces(...)` correctly reports **one orbit per sector**. `cutComponents.size() ==
  drafts.size()` is therefore **unsatisfiable on any witness carrying a singularity port** — not a
  tuning accident. No K3 edit keeping whole-face ownership can satisfy it, and no K5 edit ever could.
  This explains why three CP4b attempts, the DG, and CB-R1 all stopped in the same place.
- **DEFN section 4.4 amended.** A region owns **face fragments** keyed `(SourceFaceTopologyKey, orbit)` —
  the portion of one source face lying in one graph face. A face crossed by no trace arc has exactly one
  fragment. Every source face's fragments partition it, a **stronger** exact-once rule than the withdrawn
  whole-face wording. Derived ownership refinement only: no geometry, no added vertices, `TriMesh`
  untouched, `src/pipeline/RemeshPipeline.cpp` still frozen.
- **B1–B5 unchanged; K5 satisfied.** The frozen disc proof is unchanged in content and now computes on
  fragments. **B2 (`RejectsRegionWithMultipleBoundaryWalks`) has never executed its intended seam** and
  becomes reachable for the first time: a two-walk region now reaches
  `validate_single_boundary_walk(...)` instead of aborting construction six hundred lines earlier. That
  is the strongest evidence fragment ownership is the intended architecture rather than a workaround.
- **Corrective measures K2R/K3R** supersede the K5 route; K1, K4, K5, K6, K7 unchanged. K2R freezes the
  fragment ownership contract in writing with the K2 prohibited inputs restated verbatim. K3R deletes
  both cardinality aborts, builds fragments from `walk.orbitByDart`, makes orbits primary, re-points
  `RegionCutComponentCountDeficit` at the genuine defect (a fragment set that does not partition its
  face) with a `SourceFaceTopologyKey` locus, and leaves `network_cut_edges(...)` as interior-connectivity
  evidence rather than the ownership oracle.
- **Measurement gate first.** `M3-CP4ab-DG-R1` spends diagnostic **2 of 2** on the existing immutable
  package `9478766432` — no new package, no source change, no acceptance attempt — and must emit
  `drafts.size()`, `cutComponents.size()`, the per-orbit/per-component breakdown, whether all
  singular-fan faces landed in one cut component, and the exterior-orbit count. If the fan did not
  collapse, the finding is falsified and the work returns to Review. Three CP4b attempts were spent
  implementing without measuring; the last diagnostic buys the two numbers.
- **Falsifiable prediction.** After K2R/K3R the ten identities must stop reporting a count-deficit code —
  expect green, or a B1/B2 typed rejection naming a specific region. A third count-deficit appearance
  falsifies this Review and returns to Review rather than being patched.

Rejected alternative recorded: coarsening a region to a whole cut component is representable and exact,
but a region would then be a union of graph faces, the fan would not be a disc, B1 would typed-reject,
and A2b would produce no plan. It also falsifies identity A1 as named.

No accounting change: **26 packages**, stable **42 / 14 / 28**, produced-witness debt **5**, `PR8-R042`
active stable, CP4ab acceptance **0/3 consumed**, diagnostics **1/2 used**. Latest accepted runtime
authority remains **CP3b 304/304**. Exact next is `M3-CP4ab-DG-R1`.


### 2026-08-22 — M3 CP4ab CB-R1 static-stop closeout safety incident — resolved process/non-stable

- The K5-only Code + Build remained stopped before semantic mutation, but closeout mistakenly created `.agents/connector-triggers/turn-cleanup/manifest.txt`. Because that path automatically triggers the known-unsafe durable `agent-turn-cleanup.yml`, run/job `32591251950 / 97075340976` executed despite the safety override.
- Cleanup result `9480378725` (SHA-256 `6a2eeb4add3f4a4ae655f175a9df597849b6c4b878bd41bda13df4bc351c594d`) records **27 PR conversation comments deleted, 0 inline review comments deleted**, with zero remaining before the observer. Cleanup commit `9b7dde66aa4263a1dd0557b2318246bed4d4a914` removed the source-snapshot marker and manifest. Log `9480378867` SHA-256 `10808e35932c52a8eb85e3351c33046cde3b020b2b317fa0f13642f453c4bb6d`; `runtimeExecution=false`.
- Classified `M3-CP4ab-CB-R1-CAND-02`, **RESOLVED PROCESS / NON-STABLE**. No semantic source/test/fixture/selector/build/package change, no package creation, no acceptance attempt, and no diagnostic gate. Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **26**, CP4ab attempts **0/3**, diagnostics **1/2**.
- Durable prevention rule strengthened: until the cleanup workflow is repaired, never create its manifest trigger path and never invoke it. Use a turn-local inventory plus narrow connector deletion after workflow-first retirement.
- A separate closeout control-plane error, `M3-CP4ab-CB-R1-CAND-03`, occurred when a placeholder `update_file` connector mutation unexpectedly created one-byte path `dummy` in `620e20710de8f4d89194d63464718fa6dc249af0`. It was removed immediately in fast-forward Git-data staging commit `509047a2be81f4c3e3b24cbc2eff3c5186b24f32` before schema validation or workflow activation. No semantic/document/build/package authority changed. Mutating connector calls must never be used as capability probes or with placeholder arguments.

### 2026-08-22 — M3 CP4ab CB-R1 stops before mutation: K5 route conflicts with binding K3 definition; independent Review required

- `M3-CP4ab-CB-R1` completed the active plan's mandatory pre-mutation static proof and **did not edit product source**. K1 `GlobalTopologyPlan::build_regions()` returns `RegionCutComponentCountDeficit` when `cutComponents.size() < drafts.size()` before boundary-side matching, unique region/component binding, region materialization, or B1–B5 certification. The construction also requires a unique perfect matching from every boundary-orbit draft to a distinct whole source cut component.
- Mandatory Review Part A §A.6/F5 already classifies the underlying `cutComponents.size() == drafts.size()` requirement as a self-referential precondition that prevents non-cellular/non-disc topology from reaching certification. Part A §A.7 assigns removal/replacement of that equality precondition to **K3**; **K5 only freezes B1–B5 against weakening**. Therefore the DG's frozen `RegionCutComponentCountDeficit -> K5` routing cannot authorize the needed semantic correction without contradicting the binding Review.
- Exact ownership proof blocks a K5-only workaround: with fewer components than drafts, one-to-one whole-component ownership is impossible; sharing one cut component's source faces across regions violates exact-once ownership, while grouping/refining boundary orbits and cut components changes the K2/K3 region-construction contract. No prohibited order/BFS/proximity/A0/fallback authority was introduced.
- No semantic source/test/fixture/selector/build-configuration bytes changed; no prepackage/package compile was needed because no new semantic source exists; no generated Directional runtime ran. M3 packages stay **26**; CP4ab acceptance stays **0/3**; diagnostic budget stays **1/2**; stable accounting stays **42 / 14 / 28**, debt **5**; `PR8-R042` remains active; CP4c remains blocked.
- Exact next is independent Review **`M3-CP4ab-K5-ROUTING-REVIEW`** under `Architecture_M3_CP4ab_K5_Routing_Independent_Review_Plan.md`. It must reconcile the DG routing with mandatory Review K3 and publish exactly one replacement Code + Build plan or stop decision. No second DG or acceptance attempt is authorized before that Review.

### 2026-08-22 — M3 CP4ab attempt-free DG localizes all ten prior reds to `RegionCutComponentCountDeficit`; K5 selected

- `M3-CP4ab-DG` consumed immutable K1 source/package `82fdbbdceccfa736c8b12bbe6018465664d920ef / 9478766432` with no checkout/configure/build/relink/repair/generated discovery/source/test/fixture/selector/package mutation. Correct package SHA-256 is **`d2568ff62c07f2b8e50ee26643cbe394ca906d81bdf7ab2363d5fc3cc929bd74`**; embedded source archive **`54d3645ede2e1188974350c20ee3041b5612493989eab62b659cfb6bb670314b`**; package log `9478766646` **`c0d71bb10ca49f419129acb3c6730752866bf010d9a3720be774b38d1ed94b63`**. The preceding K1 docs had transcribed different values; GitHub artifact metadata, downloaded bytes, 27/27 internal manifest, and exact source identity establish these corrections as documentation/provenance only.
- Frozen diagnostic surface: exactly **10 required / 10 executed / 10 unique**, the prior A1/A2/A3/A5/A6/B1–B5 reds, directly filtered on the packaged producer without generated discovery. Semantic silhouette remains **0 PASS / 10 FAIL**. Every first typed product rejection is **`RegionCutComponentCountDeficit`**; none report the old umbrella `RegionCoversNoSourceFace` or any competing K1 predicate. Later variant exceptions remain helper fallout.
- K1 has one count-deficit emission site and it always carries structured `region` locus. The test helper prints the code rather than numeric locus, but there is no multi-site predicate ambiguity. Package tree, outer package ZIP, and exact materialized source all remain byte-identical postflight.
- Frozen routing selects **K5**. Exact next is **`M3-CP4ab-CB-R1`**, K5 family only; preserve B1–B5 unchanged and stop for Review if a concrete K5-only product correction cannot be justified without K2/K3/K4. CP4ab remains **NOT ACCEPTED**; latest accepted authority remains CP3b 304/304; CP4c stays blocked.
- Accounting unchanged: **26 M3 packages**, stable **42 / 14 / 28**, debt **5**, CP4ab acceptance **0/3 consumed**. Diagnostic budget is now **1/2 used**.
- Process evidence: authority/tool-schema inspection preceded the mandatory full tool-conservation policy read, though source/docs remained blocked until `READ_MODE=snapshot`; initial local snapshot-manifest check used the wrong cwd and was corrected before runtime; stale per-turn evidence was not retired before DG runtime despite the TB start-cleanup rule and is retired only in closeout after durable preservation. None changes semantic/runtime/package/attempt evidence.

### 2026-08-22 — M3 CP4ab K1 diagnostic-only Code + Build complete; immutable DG package created

- Mandatory Review Option B is now in execution: CP4a-reopened + CP4b are `M3-CP4ab`, latest accepted runtime authority remains CP3b **304/304**, and K1 was deliberately limited to diagnostics. Exact semantic source **`82fdbbdceccfa736c8b12bbe6018465664d920ef`** changes only `Architecture_M3_CP4_DEFN_Frozen_Definitions.md`, `GlobalTopologyPlan.h`, and `GlobalTopologyPlan.cpp`; tests/fixtures/selectors/build configuration and `RemeshPipeline.cpp` are unchanged.
- K1 separates the prior overloaded region-construction failures into locus-bearing condition-specific diagnostics (`EmbeddedGraphHasNoInteriorFace`, `RegionCutComponentCountDeficit`, `RegionBoundaryEvidenceMissing`, `RegionElectedCutComponentEmpty`, plus existing locus-compatible `RegionBoundaryArcNotOwnedByNetwork` / `RegionInteriorDisconnected`) without changing the ownership decision graph. Source apply `32584584055 / 97058936866` passed; result/log artifacts **`9478695000 / 9478695144`**, SHA-256 **`dda6eb5775a074613c25245564e4cecaa037eaf4a671791ac89dc113d3e5d8fa / 4a8bb48462a43bd3c550766959b0e2bf2ca44ad46e97f53318d25148243b92a4`**.
- Mandatory exact-source prepackage compile **`32584734389 / 97059298696`** passed. Result/log artifacts **`9478747641 / 9478747865`**, SHA-256 **`0fa882c012cf25d5cd563ccb7a1cd2432eef1fe806be314b0f03d30fce659304 / 26365ed79b1405b9da876f83860be55a3fd0b3bec7a0ade77ccfdf8f0baf56f1`**. Source status stayed clean and `runtimeExecution=false`.
- Authoritative eight-target package compile **`32584830483 / 97059531420`** passed. Immutable package/log artifacts **`9478766432 / 9478766646`**, SHA-256 **`d2568ff62c07f2b8e50ee26643cbe394ca906d81bdf7ab2363d5fc3cc929bd74 / c0d71bb10ca49f419129acb3c6730752866bf010d9a3720be774b38d1ed94b63`**. The package self-excluding manifest verifies **27/27**; embedded exact-source archive SHA-256 is **`54d3645ede2e1188974350c20ee3041b5612493989eab62b659cfb6bb670314b`**; build/preflight exits are 0, source status is clean, and metadata records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`.
- No generated Directional binary executed: no tests, benchmarks, discovery/list, help/version, fixtures, CLI, fuzzer, or custom input. K1 package creation consumes **0** acceptance attempts and **0** diagnostic gates. M3 package count advances **25 -> 26**; stable accounting remains **42 / 14 / 28**; produced-witness debt remains **5**; `PR8-R042` remains the same active stable event.
- Temporary K1 workflows were retired workflow-first; their triggers/payloads and inherited obsolete CP4b schema temporary state were then removed. Recursive-tree hygiene at **`70f80d0754c98ceb2e28cfc62863c67051fa1878`** shows exactly the six durable `agent-*` workflows and no connector-trigger/turn-payload/workflow-observation residue. The tasklisted unsafe comment-deleting cleanup workflow was not executed.
- Cleanup batching note: a preferred Git-data multi-file deletion was prepared, but the connector safety layer blocked the non-forced ref update. Its commit remained unattached and never became branch authority; cleanup proceeded through safe compare-and-swap deletions with no semantic source impact.
- Process-order evidence: this continued turn's first tool invocation was connector tool-schema discovery before the mandatory `TOOL_USE_CONSERVATION_POLICY.md` read. The policy was read immediately afterward and before repository/workflow-state inspection; `READ_MODE=snapshot` then governed repository inspection. Record as a process miss with **no semantic/build evidence impact**.
- Exact next is **`M3-CP4ab-DG`** on immutable package `9478766432`. It is an artifact-only, attempt-free diagnostic Test + Benchmark gate. It must select one K2/K3/K4/K5 family from condition-specific failure evidence; it cannot accept CP4ab. The first 316-identity combined acceptance attempt remains later and CP4c stays blocked.

### 2026-08-22 — `M3-CP4b-MANDATORY-INDEPENDENT-REVIEW` complete; CP4a superseded, CP4b rescoped to `M3-CP4ab`

**Review / planning only. No product, test, fixture, selector, build, package, or runtime; no attempt
consumed.** Result is Part A of `Architecture_M3_CP4b_Mandatory_Independent_Review_Plan.md` and is
binding. Decision: **Option B — rescope.** A fourth CP4b attempt is not authorized.

**Verdict: CP4b was not the defective checkpoint. CP4a was.** All findings derived statically from the
exact packaged sources `bb11d833a4120a40230ab66ca639c9cae8d25d36` (accepted CP4a) and
`b7d4fcf48f53bbe7b87643a898263aa53d06d020` (CP4b R2).

- **F1 — accepted CP4a's ownership rule is a prohibited remediation move.** `build_regions(...)` seeds
  each region with the first unclaimed face in container order, falls back to the first unclaimed face
  anywhere in `topology.faces` map order, then assigns every remaining face by BFS hop-count
  nearest-seed-wins. That is three separate prohibitions in `REORIENTATION_PLAN.md` section 2.1 and M3
  plan section 7 — order-based ownership selection, arbitrary subset search, and proximity as graph
  identity.
- **F2 — `CoversEverySourceFaceExactlyOnce` is unfalsifiable under that rule.** It asserts non-empty
  regions, total coverage, and single ownership; a BFS flood fill guarantees all three by construction.
  The test cannot fail for any input. It never asserts that a face's owner is the region whose boundary
  encloses it — the only claim with semantic content. A1 is green for the same structural reason. CP4a's
  310/310 gate is valid, but **A1 and A3 are not semantic evidence** and CP4b was never obliged to
  preserve them.
- **F3 — CP4b rewrote accepted authority instead of extending it.** +1186/−137 across three files, 870
  lines inside `GlobalTopologyPlan.cpp`; `network_cut_edges`, `cutComponents`, and `componentByFace`
  appear nowhere in accepted CP4a. That is why five accepted identities regressed. The instinct —
  deriving ownership from the network cut — was correct and is preserved.
- **F4 — the diagnosability collapse repeated.** `RegionCoversNoSourceFace` is emitted at **seven sites
  for seven distinct conditions** (`:1188`, `:1256`, `:1354`, `:1369`, `:1378`, `:1483`, `:1901`), which
  is why three immutable gates localized nothing and why the R2 report lists five subcases it cannot
  distinguish. DEFN section 6.3 had already frozen thirteen locus-bearing codes to prevent this, with
  `RegionSourceFaceUnowned`, `RegionInteriorDisconnected`, `RegionBoundaryArcNotOwnedByNetwork`, and
  `RotationSystemInconsistent` available and unused. Two of three attempts were spent blind.
- **F5 — `cutComponents.size() == drafts.size()` is asserted, not derived.** Faces of an embedded graph
  equal complement components only for a cellular embedding of a connected graph; an annular face breaks
  it, and an annular face is exactly what B2 exists to detect. The construction cannot require every
  region to already be a disc while the checkpoint's purpose is to prove disc-ness. Information
  sufficiency is **not** the blocker.

**Corrective measures K1–K7**, K1 first and alone: split the collapsed code with loci populated, no
semantic change, so the first diagnostic gate is a pure localization instrument. Then K2 freeze the
ownership contract in writing with prohibited inputs restated; K3 remove the equality abort; K4 make
A1/A3 falsifiable with a negative that fails under a flood fill; K5 do not weaken B1–B5; K6 close
`PR8-R042` only under the corrected A1/A3; K7 record the durable lesson.

**Rescope.** CP4a-reopened and CP4b merge into **`M3-CP4ab`** at the unchanged gate
**316 = 304 + A1–A6 + B1–B6**. No identity is removed or renamed; A1/A3 are strengthened. The split was
the structural cause — region derivation and the disc proof are not independent domains, and placing an
accepted predecessor between them obliged CP4b to preserve a wrong partition. `M3-CP4-DEFN` made that
split and is amended with three withdrawals.

**Authority reverts to CP3b 304/304** (`611b3f8f3926792baee9d1078d6677d22006a6c4 / 9456073195`, gate
`32515222447 / 96875297990`), untouched and green in all three CP4b gates. CP4a's
`32540801792 / 96950302793` remains valid evidence of what it ran, no longer accepted authority for
region ownership.

**Budget.** First mandatory review on this work; three attempts restored and reallocated to `M3-CP4ab`
at attempt 1 of 3 with 2 diagnostic gates. CP4b's three consumed attempts remain historical cost. CP4c
keeps its own budget and stays blocked.

No accounting change: **25 packages**, stable **42 / 14 / 28**, produced-witness debt **5**,
`PR8-R042` still active. Exact next is `M3-CP4ab-CB`, K1 only.


### 2026-08-22 — M3 CP4b R2 immutable attempt 3 valid RED 306/316; mandatory Review activated

- Local artifact-only `M3-CP4b-TB-R2` consumed the exact immutable Code + Build source/package **`b7d4fcf48f53bbe7b87643a898263aa53d06d020 / 9472814830`**, package ZIP SHA-256 **`5508396a417c1b05131b712abafb44b2b5a33f4bf11b97a60ec348a862696f5a`**. The frozen gate reconciled **316 required / 316 executed / 316 unique**, zero skips and zero orchestration errors, and returned **306 PASS / 10 unique FAIL**. Package/source postflight and the outer package digest remained byte-identical; no checkout/configure/build/relink/repair/source/test/fixture/selector mutation or generated discovery occurred.
- All **304** accepted identities through CP3b remain green. CP4a remains **1/6** with A4 green; CP4b remains **1/6** with B6 green. The same CP4a A1/A2/A3/A5/A6 and CP4b B1–B5 identities are red as R1, and the exact earliest typed producer rejection remains **`RegionCoversNoSourceFace`**. Later `std::get: wrong index for variant` output remains secondary helper fallout after that typed rejection.
- R2 proves the oriented trace-dart side oracle is **insufficient**: it removed R1's unsigned whole-trace `sourceFaces` owner intersection but did not restore graph-face ↔ network-cut source-component ownership. `PR8-R042 / M3-CP4b-R001` remains the same active stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` event; R2 adds no second stable incidence or recurrence. `M3-CP4b-TB-CAND-01` remains active/non-stable behind the same invalid positive baseline.
- First local control `M3-CP4b-TB-R2-CAND-01` was externally terminated by the surrounding execution tool while inside the long retained M1 producer partition, before a complete gate/postflight existed. No semantic claim was taken from it. The immutable package was restored unchanged and the same gate reran to natural completion; the control is **RESOLVED ORCHESTRATION / NON-STABLE / attempt-free**.
- User-visible local evidence bundle `Directional__M3-CP4b-TB-R2__evidence.tar.gz` has SHA-256 **`6d05ce8a424f046301094537fc8e955201605893835665522afe09cceef25446`**; contained `acceptance-result.json` SHA-256 is **`68505554226ffeb2e6d801791f664cea3ec0aef1af6784f4a82cadcf13e09509`** and `execution-map.json` SHA-256 is **`ff59bd42ad2b1386cc67ea635993493f39de7e485b6673b5a22ab80085702ff1`**. This is local artifact-only evidence, not a GitHub Actions result artifact.
- CP4b acceptance attempt **3/3 is consumed RED**. M3 packages remain **25**; stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**. The third-red mandatory-review ratchet is active. Exact next is Review/planning-only **`M3-CP4b-MANDATORY-INDEPENDENT-REVIEW`** under `Architecture_M3_CP4b_Mandatory_Independent_Review_Plan.md`; no fourth CP4b package or CP4c work is authorized before Review.

### 2026-08-22 — M3 CP4b corrective CB-R2 compile-green; final acceptance package created

- `M3-CP4b-CB-R2` completed as **Code + Build only / runtime-free** on exact semantic source
  **`b7d4fcf48f53bbe7b87643a898263aa53d06d020`**. The production delta is confined to `src/geometry/GlobalTopologyPlan.cpp` and replaces R1's
  unsigned whole-trace `GlobalTopologyArc::sourceFaces` ownership intersection with exact oriented trace-dart
  side evidence derived from carrier incidence/transport. Exact DEFN 6.1 network-cut components, mandatory-edge
  side evidence, unique typed binding, frozen B1–B6, and the disc-proof certificate remain unchanged;
  `src/pipeline/RemeshPipeline.cpp` remains frozen.
- Standalone prepackage compile **`32561033323 / 97002499767`** passed for
  `directional_surface_cell_producer_tests`. Result/log artifacts **`9472788701 / 9472788952`** have
  SHA-256 **`7cba41f4aa809ce167d818ae0866eabb5fdea97b48367a9106fbe462981006a1 / d9846cee631e64757e9fea36ebcc748dc80fe26a67abea45d211302fcff25f5e`**.
- Authoritative eight-target package compile **`32561138330 / 97002743537`** passed. Immutable result/log artifacts
  are **`9472814830 / 9472815068`**, SHA-256 **`5508396a417c1b05131b712abafb44b2b5a33f4bf11b97a60ec348a862696f5a / e770d1fffc3abb5a0cc449704ae71dea2ac6f4d2959d1d4f44f35b54fd0f4a35`**. The package verifies
  **27/27** self-excluding manifest entries; exact-source archive SHA-256 is **`84a4d90a0e1352da1987779851ad308f3640bac555caecf7961e47dd3a7ce85e`**; source status
  is clean and metadata records `runtimeExecution=false` / `semanticContracts=compiled-not-executed`.
- No generated Directional binary was executed: no tests, benchmarks, discovery/list, `ctest`, CLI, fuzzer,
  help/version, or custom input. Package creation consumes no acceptance attempt.
- M3 package count advances **24 -> 25**. Stable accounting remains **42 / 14 / 28**; produced-witness debt **5**.
  `PR8-R042 / M3-CP4b-R001` remains active pending runtime proof; CP4b remains **2/3 attempts consumed RED**.
- Exact next is immutable artifact-only **`M3-CP4b-TB-R2`** on package `9472814830`, unchanged gate
  **316 = accepted 310 + B1–B6**, acceptance attempt **3/3**. CP4c remains blocked until CP4b accepts.

### 2026-08-22 — M3 CP4b corrective retry valid RED 306/316; attempt 2/3 consumed; R2 required

- Valid immutable `M3-CP4b-TB-R1` **`32554121666 / 96985517239`** consumed exact corrective source/package
  `0c795e85fedf16c29ac8045a0205ca63776a2182 / 9469873048`, package SHA-256
  `b01d48afcc2af8d6c635690f189801f393020f67635c02c5c4d80834a71fd10f`. The frozen gate executed
  **316/316 unique** identities with zero skips/orchestration errors and returned **306 PASS / 10 unique FAIL**.
  Result/log artifacts are `9470953271 / 9470953461`, ZIP SHA-256
  `30090af539ae565ad08a0e9e192c77f49472eebf9bac811a7189237c4b00b4c0 /
  0943ee6f04f1c740816930835857ef86177e8a58536cdd59873bfae1072714f9`.
- Artifact-only invariants hold: `generatedDiscovery=false`, `rebuild=false`, `relink=false`, `repair=false`,
  `runtimeExecution=true`; package/materialized-source postflight are byte-identical and the outer package digest matches.
  Therefore CP4b acceptance attempt **2/3 is consumed RED**. Latest accepted runtime remains CP4a 310/310.
- The same ten identities remain red: CP4a A1/A2/A3/A5/A6 and CP4b B1–B5. A4 and B6 remain green. Under R1,
  positive plan construction consistently stops at typed `RegionCoversNoSourceFace`; later `std::get: wrong index for variant`
  remains secondary helper fallout.
- `PR8-R042 / M3-CP4b-R001` remains the same active stable `RP-01` event. R1 correctly removed A0
  `TopologyRegionId`/component and region-zero fallback ownership and retained exact network-cut components, but its replacement
  intersects component support from every trace arc on a face boundary. `GlobalTopologyArc::sourceFaces` is the unsigned list of
  all source faces traversed by that trace arc, not evidence for the side selected by an oriented boundary dart. The intersection
  can therefore eliminate the correct cut component and yield `RegionCoversNoSourceFace`.
- First control `32553858009 / 96984855424` is resolved orchestration/non-stable: artifact download returned HTTP 401 before
  runtime (`executedCount=0`, `runtimeExecution=false`, `acceptanceAttemptConsumed=false`). Replacing the compact `urllib`
  redirect path with proven `curl --location` semantics passed SchemaStore at `32554064933 / 96985375922` and enabled the valid run.
- Stable accounting remains **42 / 14 / 28**; produced-witness debt **5**; M3 package count **24**. Exact next is
  runtime-free **`M3-CP4b-CB-R2`**: preserve network-cut components/frozen B1–B6 and `RemeshPipeline.cpp`, replace whole-trace
  support ownership with oriented boundary-side/dart evidence, and typed-fail absent/ambiguous bindings. A compile-green package
  advances to unchanged 316 artifact-only `M3-CP4b-TB-R2` as acceptance attempt **3/3**. CP4c remains blocked.

### 2026-08-22 — M3 CP4b corrective CB-R1 compile-green; immutable retry package created

- `M3-CP4b-CB-R1` corrected `PR8-R042 / M3-CP4b-R001` at exact semantic source
  **`0c795e85fedf16c29ac8045a0205ca63776a2182`**. The production change is confined to `src/geometry/GlobalTopologyPlan.cpp`: exact network-cut
  source-face components are bound uniquely to embedded-graph face orbits; broad A0 `component` / `TopologyRegionId`
  compatibility and the region-zero fallback no longer substitute for CP4 `NetworkRegionId` ownership.
  `src/pipeline/RemeshPipeline.cpp` remained frozen and B1–B6 were not changed.
- Corrective source apply **`32550295688 / 96975815357`** changed exactly one path and preserved clean source state.
  Mandatory prepackage compile **`32550356995 / 96975989686`** passed `directional_surface_cell_producer_tests`;
  result/log artifacts **`9469853868 / 9469853997`**, SHA-256
  `c507a50260da74fa3cfc511fb3e34a8ea7ad3c08c93330c714c9cb831f5f4e73 / acc0443a44a55ee9a454f9919b56f541b827a002d005a8cf511cb5eb290d356d`.
- Authoritative eight-target package compile **`32550420660 / 96976157263`** passed on the same literal semantic source.
  Immutable package **`9469873048`**, ZIP SHA-256 **`b01d48afcc2af8d6c635690f189801f393020f67635c02c5c4d80834a71fd10f`**; log artifact **`9469873300`**, SHA-256
  **`3bd7af87fbadbea265e676a56f019dd0395a7e6724ebdf04f2af535010711888`**; embedded source archive SHA-256 **`446199b8c98233f69b087542a0cd9c79a956d6ea62dd2ece1532c17ef93b2cd8`**. All 27 internal manifest entries
  verified, source status remained clean, and metadata records `runtimeExecution=false`,
  `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`.
- One orchestration-only control was caught before semantic apply: prepared tree
  `9c1613990fd572a076035fe1c6751ede25601743` landed older CP4b caller blobs in `837f0c9ed2ceefa981db7a8d2f1bb6a8813f294b`. No source trigger or
  generated runtime had run. Corrected caller bytes were independently SchemaStore-green in **`32550244247`** before
  activation. Tracked as `M3-CP4b-CB-R1-CAND-01`, resolved non-stable, zero acceptance/stable impact.
- M3 cumulative packages advance **23 -> 24**. Stable accounting remains **42 events / 14 categories / 28
  recurrences**; produced-witness debt remains **5**. CP4b acceptance remains **1/3 consumed RED** because package
  creation is attempt-free; latest accepted runtime authority remains CP4a at 310/310.
- Exact successor is immutable artifact-only **`M3-CP4b-TB-R1`** on package `9469873048`, unchanged gate
  **316 = accepted 310 + B1–B6**. A valid retry consumes attempt **2/3**; only 316/316 accepts CP4b. CP4c remains
  blocked until CP4b accepts.


### 2026-08-22 — M3 CP4b immutable attempt 1 is valid 306/316 RED; corrective Code + Build required

- Immutable `M3-CP4b-TB` run/job **`32546409286 / 96965543865`** consumed exact Code + Build semantic source/package
  **`ba42e17e0a298e56f961d2f898b77cfee3a70395 / 9468126906`**, package ZIP SHA-256
  **`95811d184185ae81d225f44145fd86bb9c51698d419f5d0e3e0e8110033a7841`**. Accepted predecessor selector is the
  exact CP4a 310-selector SHA-256 `4ac603a100f2f18eae050d79386b3e03c5e471d3f62f80536bb845e29f9b4240`;
  CP4b six-selector SHA-256 is `37835b792409382a9bac5a1a9f02461dcc338b2a3cb9ebd101865a0613123011`; combined
  316-selector SHA-256 is `d5fed28dce026137bcf4516122e9a45338e0675d66af8d362df559f5242f5518`.
- The gate is **valid semantic RED, not harness failure**: expected/executed/unique are **316/316/316**, zero skips,
  zero orchestration errors, package postflight identical, materialized package-source postflight identical, and outer
  package digest unchanged. Result/log artifacts are **`9468673884 / 9468674168`**, SHA-256
  `2925e09dd10db4e535369385a5dbb0d29c2152dd626d82f5ff51ff385080ddc7 /
  b1694374bd7d5792cc86c8198f09d0860a18782962791e8502539a1088ee3231`.
- Semantic result is **306 PASS / 10 unique FAIL**. All **304** accepted identities through CP3b remain green. CP4a is
  **1/6**: `PreservesMandatoryBoundaryAndHardFeatureEdges` passes while A1/A2/A3/A5/A6 fail at canonical plan construction
  with `RegionInteriorDisconnected`. CP4b is **1/6**: B1/B2/B4/B5 fail with `RegionInteriorDisconnected`, B3 fails
  with `RegionCoversNoSourceFace`, and structural B6 passes. The later `std::get: wrong index for variant` from the
  non-fatal plan helper is secondary fallout after the typed producer error and does not invalidate the gate.
- Static accepted-source comparison identifies **`PR8-R042 / M3-CP4b-R001`**, an **`RP-01 /
  AUTHORITY_DOMAIN_CONFLATION` recurrence**. CP4b correctly introduces DEFN 6.1's network-crossing cut adjacency, but
  `build_regions()` assigns newly disconnected cut components using only broad A0 source `component` /
  `TopologyRegionId` compatibility and finally defaults to graph region zero. DEFN 3.1 explicitly separates that A0
  input authority from CP4 `NetworkRegionId`. The fallback can therefore give one graph face multiple disconnected cut
  components or leave another graph face with no source face; the new certificate correctly rejects the invalid product.
- B1–B5 first-acceptance failures are tracked as `M3-CP4b-TB-CAND-01`, non-stable evidence of the same product defect;
  they add no second stable incidence. Stable totals advance **41 -> 42 events / 14 categories / 27 -> 28 recurrences**.
  Produced-witness debt remains **5** and M3 package count remains **23**.
- CP4b acceptance attempt **1/3 is consumed RED**. Exact successor is **`M3-CP4b-CB-R1`**, corrective Code + Build
  only: preserve the frozen cut relation and B1–B6, replace A0 fallback ownership with exact network-cut-component →
  embedded-graph-face binding, remove the region-zero semantic fallback, keep `src/pipeline/RemeshPipeline.cpp` frozen,
  and execute no generated runtime. A new package then advances to `M3-CP4b-TB-R1` at the unchanged 316 gate; a valid
  retry consumes attempt **2/3**. CP4c remains blocked until CP4b accepts.

### 2026-08-22 — M3 CP4b Code + Build compile-green; immutable package advances to 316 acceptance

- `M3-CP4b-CB` completed as **Code + Build only** on exact semantic source
  **`ba42e17e0a298e56f961d2f898b77cfee3a70395`**. Prepackage compile **`32544598940 / 96960776288`**
  passed for `directional_surface_cell_producer_tests`. The authoritative eight-target package compile
  **`32544684790 / 96960997959`** passed for `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, and `directional_benchmarks`.
- Immutable package result artifact is **`9468126906`**, ZIP SHA-256
  **`95811d184185ae81d225f44145fd86bb9c51698d419f5d0e3e0e8110033a7841`**. Package log artifact is
  **`9468127064`**, SHA-256 **`8f837da258023f370f5f162e19d3ef280e0258a1f4cf312b397d1ecf96363d00`**.
  The embedded exact-source archive `source-ba42e17e0a298e56f961d2f898b77cfee3a70395.tar.gz` has SHA-256
  **`ed769f51b3c1119b46526df650a8dbee034161642429acf188e1d15ab75a7b69`**. Recursive package
  `SHA256SUMS` verified and source status remained clean.
- Evidence boundary is exact: `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
  `semanticContracts=compiled-not-executed`, out-of-tree runner-temp build. No generated Directional test,
  benchmark, discovery/list/help/version command, `ctest`, CLI, fuzzer, or custom input executed.
- Frozen B1–B6 implementation landed only in `GlobalTopologyPlan.h`, `GlobalTopologyPlan.cpp`, and
  `FieldAlignedCurveNetworkTests.cpp`; `src/pipeline/RemeshPipeline.cpp` remained frozen. The six exact CP4b
  identity names are compiled but **not executed** in this turn.
- Three bounded orchestration controls were resolved without stable incidence: large connector payload byte-identity
  risk was eliminated by compressed small-chunk transport; initial apply `32544180699 / 96959666188` failed before
  patch application because push-event marker discovery returned empty and was corrected to `git diff-tree`; initial
  preflight `32544368400 / 96960154204` failed before compile because a shallow checkout lacked the exact semantic
  source object and was corrected to explicit exact-SHA fetch. Corrected apply `32544331458 / 96960060239`, schema
  validation `32544553093`, preflight compile `32544598940`, and package compile `32544684790` are green.
- M3 cumulative package count advances **22 -> 23**. Stable accounting remains **41 / 14 / 27**;
  produced-witness debt remains **5**. CP4b has **0/3 acceptance attempts consumed**; package creation is not acceptance.
- Latest accepted runtime authority remains CP4a at **310/310**. Exact successor is immutable artifact-only
  **`M3-CP4b-TB`** on package `9468126906`, gate **316 = accepted 310 + frozen B1–B6**. DEFN allocates no CP4b
  diagnostic gate; a valid gate consumes acceptance attempt 1/3 and only 316/316 accepts/closes CP4b.


### 2026-08-21 — M3 CP4a accepted 310/310; CP4b Code + Build is next

- Immutable `M3-CP4a-TB` run/job **`32540801792 / 96950302793`** consumed exact semantic source/package
  `bb11d833a4120a40230ab66ca639c9cae8d25d36 / 9463170801`, package SHA-256
  `bca28f520b919684ad68ac94e19dfd4ee4613019fd4ef270677723c50464044b`.
- Exact frozen gate is **310/310 PASS**: accepted predecessor **304/304** plus CP4a **6/6**, 310 unique identities,
  zero failures. Accepted predecessor selector SHA-256 is
  `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`; CP4a selector SHA-256 is
  `2a8e33b2366c5f8c2411a32042273cfdccdc3b0749e4b6a8a48e1ced799ece32`; accepted combined 310-selector
  SHA-256 is `4ac603a100f2f18eae050d79386b3e03c5e471d3f62f80536bb845e29f9b4240`.
- Result/log artifacts are **`9466987823 / 9466988005`**, SHA-256
  `9306a84ddd14ccba68b50b6cd46151079670d9a822d30205238d10e44e727fe7 /
  60418f931abd384ba85795a957516b873873fe866b75ae95d892b350ada043e1`. Package and materialized
  package-source pre/post hashes are byte-identical. `artifactOnly=true`, `generatedDiscovery=false`,
  `rebuild=false`, `relink=false`, `repair=false`; no source/test/fixture mutation or later-turn implementation occurred.
- `M3-CP4a-TB-CAND-01` is resolved orchestration/non-stable. Earlier control
  `32540367870 / 96949075003` selected all 310 identities but lost 26 accepted M1 producer identities only because
  fixture files were absent at the precompiled binaries' embedded source root `/home/runner/work/Directional/Directional`;
  CP4a was already **6/6**. The same immutable package/source archive was materialized at that compiled source root for
  the valid rerun. The invalid harness result consumes **no acceptance attempt**.
- CP4a acceptance attempt **1/3** is consumed and green. CP4a is **CLOSED / ACCEPTED**. Stable accounting remains
  **41 / 14 / 27**; produced-witness debt remains **5**; M3 package count remains **22**.
- Exact successor is **`M3-CP4b-CB`**, Code + Build only. Implement frozen B1–B6 disc-proof/certificate contracts,
  keep `src/pipeline/RemeshPipeline.cpp` frozen, and execute no generated runtime. DEFN allocates no CP4b diagnostic
  gate; a compile-green CP4b package may proceed directly to immutable acceptance at **316 = 310 + 6**.

### 2026-08-21 — M3 CP4a diagnostic gate green; immutable package advances to 310 acceptance

- Attempt-free `M3-CP4a-DG` run/job **`32531334891 / 96923772256`** consumed exact immutable
  source/package `bb11d833a4120a40230ab66ca639c9cae8d25d36 / 9463170801` and executed **only** the six frozen
  CP4a identities from DEFN section 7.1. Result is **6/6 PASS**, one selected identity per invocation,
  zero skips/failures; accepted-predecessor execution and generated discovery were both false.
- DG result artifact `9463944965` has ZIP SHA-256
  `783f11366796070d63ca29a6ef318f6620e49d4db561022f33da4c92d9d9fa5a`; diagnostic log artifact
  `9463945337` has ZIP SHA-256
  `c94af029455b561a0b55edb163a7ded788bfc39a28b6fe6f3d7aff69e3e52b3a`. Result evidence records
  `artifactOnly=true`, `generatedDiscovery=false`, `acceptedPredecessorExecuted=false`,
  `acceptanceAttemptConsumed=false`, `executedIdentityCount=6`, `passedIdentityCount=6`, and `outcome=green`.
- Package pre/post recursive hashes are byte-identical and the outer package digest remains exactly
  `bca28f520b919684ad68ac94e19dfd4ee4613019fd4ef270677723c50464044b`; semantic source remains exactly
  `bb11d833a4120a40230ab66ca639c9cae8d25d36`. No configure, compile, relink, package repair, benchmark,
  CLI/fuzzer/help/version command, custom input, or source/test/fixture mutation occurred.
- Workflow draft passed independent SchemaStore validation in run/job `32531161103 / 96923272579`;
  validation artifact `9463890857` has SHA-256
  `122e5c625ed9a0872a2885b2508ba4d5a26799786b7dd8698d8ec853d5fb1510` and records `valid=true`.
- `M3-CP4a-DG-CAND-01` is resolved orchestration/non-stable: the first schema marker commit
  `5ca259958330af8196cd639026ba7f683eec2a24` predated caller installation because its prepared caller
  commit was not moved onto the working-branch ref. No workflow/runtime occurred. Corrected caller install
  `821e99ed182692ba15da804230e14e6d538060c4` plus separate trigger
  `0cc0ad0651d58e5f1f31cd5d0532021f517ddf9c` produced the green schema evidence above.
- Stable accounting remains **41 / 14 / 27**; produced-witness debt remains **5**; M3 package count remains
  **22**. CP4a now has **1/2 DG used** and **0/3 acceptance attempts consumed**. Green DG is not acceptance.
- Exact successor is immutable artifact-only **`M3-CP4a-TB`** at **310 = accepted 304 + CP4a 6**, using the
  same package `9463170801`. A valid TB gate consumes CP4a acceptance attempt 1/3; only 310/310 accepts CP4a.

### 2026-08-21 — M3 CP4a Code + Build compile-green; immutable package advances to diagnostic gate

- `M3-CP4a-CB` completed as **Code + Build only** on exact semantic source/package
  `bb11d833a4120a40230ab66ca639c9cae8d25d36 / 9463170801`. Full package compile run/job
  `32528377599 / 96916373880` is green; prepackage compile job `96915268655` is also green.
- Package result ZIP SHA-256 is
  `bca28f520b919684ad68ac94e19dfd4ee4613019fd4ef270677723c50464044b`; package log artifact
  `9463171179` has ZIP SHA-256
  `58d5805ddf05c3f9714fc4b810943b646cd7f1cafe0c364bc74188d384c8a98d`. The result artifact's
  recursive self-excluding `SHA256SUMS` verified every listed file, including source archive
  `source-bb11d833a4120a40230ab66ca639c9cae8d25d36.tar.gz` at SHA-256
  `09b779018bc7e1fddb78b632efbfb012d1aafaff3c95ce339a538bbae7f3f1fd`.
- Evidence boundary is exact: `metadata/source-commit.txt` is the semantic source SHA; preflight/build
  exits are 0; all source-status snapshots are empty; `metadata/command-boundary.txt` records
  `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `semanticContracts=compiled-not-executed`.
  No generated Directional binary, test, benchmark, discovery/list/help/version command, `ctest`, CLI,
  fuzzer, or custom input executed.
- The first corrected-caller run `32527880907` stopped compile-only in `GlobalTopologyPlan.cpp` because
  non-default-constructible typed semantic IDs were default-initialized in a `std::array`, `ArcDraft`,
  and `RayOrderKey`. No package or generated runtime resulted. A bounded same-turn correction replaced
  those default constructions with explicit typed initialization; no accepted CP3a/CP3b authority was
  changed. This compile-only defect does **not** alter stable regression accounting.
- M3 cumulative package count advances **21 -> 22**. Stable accounting remains **41 / 14 / 27**;
  produced-witness debt remains **5**. CP4a has **0/2 DG used** and **0/3 acceptance attempts consumed**.
  Package creation is not acceptance.
- Exact successor is attempt-free **`M3-CP4a-DG`**, running only the six frozen CP4a identities from
  DEFN section 7.1 against this exact immutable package. Green DG is not acceptance; it advances the
  same package to immutable `M3-CP4a-TB` at **310 = 304 + 6**.
- **Process evidence:** on this continuation, exact packaged source/docs were inspected before the
  mandatory full `TOOL_USE_CONSERVATION_POLICY.md` read and explicit `READ_MODE` declaration. That
  violated the policy's start-of-turn ordering. The miss was detected and recorded; the turn switched
  immediately to `READ_MODE=snapshot`, reused the already-verified package source archive for all
  subsequent source/document inspection, and performed no piecemeal connector source reads.

### 2026-08-21 — `M3-CP4-DEFN` complete; CP4 definitions frozen

**Planning / Review only. No product, test, build, package, or runtime; no attempt consumed.**

Output: `Architecture_M3_CP4_DEFN_Frozen_Definitions.md`. All seven required items are frozen; it is
the implementation authority for CP4a/CP4b/CP4c and supersedes M3 plan section 4A.3 wherever the two
differ. Every type, line, enum value, and fixture it cites was read at its cited location this turn.

- **Embedded graph defined.** Arcs are mandatory arcs (one per `FieldAlignedMandatoryEdge`) plus trace
  arcs (each `FieldAlignedCandidateTrace` cut at every incident event node). Nodes are exactly
  `network.nodes()`. A region is one face of that graph plus its covered source faces.
- **Disc proof frozen** as single boundary walk + interior connectivity + `χ = 1`, claimed **necessary
  and sufficient** with the reasoning stated — deliberately not copying A1's conservative-sufficient
  hedge, because these are exact integer combinatorics. The no-interior-singularity requirement is
  separated out as a distinct **field-regularity** condition rather than folded into the topological
  claim, so one certificate does not attest to two things under one name.
- **Thirteen rejection reasons**, each with named locus fields, plus a required
  `..._error_code_name(...)` and a rule that every negative asserts the exact code. This is the direct
  control for CP2b's diagnosability collapse.
- **Independent factory-free oracle** specified: re-walks faces, recomputes `χ`, re-checks boundary
  components and connectivity, never calls the production validator.
- **New `NetworkRegionId` domain** with the exact `AuthorityIds.h` recipe, because the existing
  `TopologyRegionId` is A0 *source* region authority and must not acquire a second meaning.
- **Eighteen identity names frozen**; gates **CP4a 310 / CP4b 316 / CP4c 322**, plus a section 2
  criterion→identity map to be re-walked before freezing each package — the direct control for the
  CP3b defect where prose obligations and the frozen selector were never reconciled.
- **Witness provenance settled.** `torus.obj/.rawfield` and `mechanical_feature.obj/.rawfield` are
  already committed under `benchmarks/fixtures/milestone-g/`, and
  `make_torus_pipeline_fixture()` (`tests/SurfaceCellTransitionQuotientTests.cpp:512-541`) already
  drives the torus through the production entry path in the same CMake target. Reuse, do not author.
  Five per-witness runtime preconditions are frozen, following the accepted CP3a fixture's pattern.

Three findings changed scope:

- **`G4-B001` is a non-collision.** The tracker (`:1043`, `:1045`, `:734`) places it at the
  completion/materializer stage — `LocalSheetMismatch` after 192 quads, caused by
  `classify_source_surface_labels(...)` promoting a hard rail into `IsolationSheetId` authority. That
  is downstream of A2b, and the torus already reaches trace-network authority intact. CP4c's witnesses
  stop at regions and disc proofs, claim no `G4-B001` progress, and plan section 8's prohibition stands.
- **Rotation-system derivation is a CP4a prerequisite, not CP4c debt.** Faces of an embedded graph
  cannot be computed without a cyclic arc order per node. `M3_CP3_Closure_Record.md` section 6 had
  placed it in CP4c; that placement is corrected. CP4a publishes it (A2), CP4c proves it on produced
  witnesses (C3).
- **B6 rescoped away from D4 machinery.** `FieldTransportUnestablished` is a D4 disposition and the
  D0–D4 tier is M7 work; building it in M3 would repeat the M1 criterion-5 defect that made M1
  unclosable. The atlas already rejects with `FieldAtlasBuildErrorCode::UnestablishedAdmissibility`, so
  M3's equivalent is the structural negative: no plan is producible from an unestablished certificate.

Two latent defects in accepted code recorded for CP4 to work around, not to repair:
`FieldAlignedCurveNetworkNode::sourceVertex` is `sourceFace.vertices().front()` for contact nodes — an
arbitrary face vertex, never a location — and `FieldAlignedNetworkEventKind::SingularityTermination`
is declared at `SurfaceCellTracing.h:243` and produced nowhere, though plan section 2 criterion 5
requires it. C5 owns the latter.

No accounting change: **21 packages**, stable **41 / 14 / 27**, produced-witness debt **5**. Exact next
is `M3-CP4a-CB`.

### 2026-08-21 — M3 CP3a/CP3b closure verified and consolidated; CP4 split into four turns

**Independent Review turn. No product, test, build, package, or runtime; no attempt consumed.**

- **Both closure claims VERIFIED** from source and CI evidence rather than from the closing reports.
  Verified: both semantic source SHAs exist as commits; both acceptance runs/jobs exist with
  `conclusion=success`; neither job's step list contains a configure/compile/rebuild step, so
  artifact-only holds structurally and not only by assertion; each run's trigger SHA matches its
  declared event SHA; CP3b's result and log artifact SHA-256 digests match the report exactly
  (`c88f8505…`, `18a5cfb0…`); all twelve frozen CP3a/CP3b identity names exist in source as frozen;
  `tests/FieldTransportAtlasTests.cpp`, `tests/support/`, and `RemeshPipeline.cpp` stayed frozen
  across CP3a's corrective work and all of CP3b; gate arithmetic 292+6=298 and 298+6=304 holds.
- Corrective measures J1–J6 confirmed landed in source: the two-ring skew disc witness, the
  producer-derived field with independently reconstructed index `+1` and interior-filtered
  singularity assertion, the two non-vacuity `ASSERT_`s, the digest split consuming
  `branch_topology().semantic_digest()` while retaining the full atlas hash for binding, and the
  foreign-atlas negative asserting gauge-invariance of the semantic digest against gauge-dependence
  of the raw hash. Both previously-vacuous CP3a passes now carry cardinality guards.
- New consolidated record `M3_CP3_Closure_Record.md`; registered durable in `RETENTION_POLICY.md`.
  Retired: `Architecture_M3_CP3a_Artifact_Only_Test_Benchmark_Report.md`,
  `Architecture_M3_CP3b_Artifact_Only_Test_Benchmark_Report.md`,
  `Architecture_M3_CP3b_Artifact_Only_Test_Benchmark_Plan.md`,
  `Architecture_M3_CP3b_Code_Build_Report.md`.
- **Finding — two CP3b prose obligations have no owning identity and are unproven.** The frozen
  six-identity selector is narrower than plan section 4A.2's six-item list: the independent oracle
  performs no rotation-system/face-walk check (item 5), and no negative tampers a `TraceIntersection`
  crossing (item 6). The gate is legitimately green; these were simply never asked. Both carry into
  `M3-CP4c` against section 2 criteria 5 and 9. Not grounds to reopen an accepted gate.
- **Finding — CP4 was oversized and is split.** It carried three semantic domains plus witness
  production plus the cumulative exit gate. Replaced by `M3-CP4-DEFN` (planning), `M3-CP4a`
  (topology derivation and region product), `M3-CP4b` (disc proof and catastrophic precondition),
  and `M3-CP4c` (representative witnesses and the M3 exit gate), each implementation checkpoint
  holding its own 3-attempt budget.
- **Finding — the per-region disc-topology proof has no frozen definition.** Section 2 criterion 6
  and section 3 A2b both require one. This is the same undefined-certificate shape section 1.1.2
  records M1 paying for twice, which CP0 discharged for the A1 certificate before CP1 began.
  `M3-CP4-DEFN` must freeze its construction, exhaustive locus-naming rejection reasons, and an
  independent factory-free tamper oracle before any CP4 code.
- **Finding — CP4c's required torus witness collides with the open `G4-B001` blocker** on the same
  production path, while plan section 8 forbids claiming its closure by unrelated network green.
  Never reconciled; DEFN must decide explicitly rather than let the exit gate discover it.
- Plan amended: stale CP2b-era status line replaced; the falsified "reuse the CP2b skew-fan witness"
  instruction removed with its correction retained; retired CP2b/CP3a/CP3b task lists collapsed to
  closure-record pointers; sections 4A.3/4A.4/4A.5 rewritten. `TODO.md` and the handoff advanced to
  `M3-CP4-DEFN`. `LESSONS.md` gained the fourth degenerate-fixture instance and three lessons
  (witness capability is contract-specific; prose obligations vs frozen selector; define a proof
  before coding against it).
- No accounting change: **21 packages**, stable **41 / 14 / 27**, produced-witness debt **5**.

### 2026-08-21 — M3 CP3b accepted 304/304; CP4 topology-plan derivation is next

- Immutable `M3-CP3b-TB` run/job `32515222447 / 96875297990` consumed exact source/package `611b3f8f3926792baee9d1078d6677d22006a6c4 / 9456073195`, package SHA-256 `6126acc44121ae6ca05f8b01f075bd26ce72e4f08851c80d09209c2a225a3c31`.
- Exact frozen gate **304/304 PASS**: accepted predecessor **298/298** plus CP3b **6/6**, 304 unique identities, zero failures. Predecessor selector SHA-256 `44dede9235fb53b486e351c02f87d4f8d5044e50ec77df6d7befbf072dfb5a25`; CP3b selector `4e9bc4a9697ab86f13a85effccbf20eb3c4debdd11fa4920c4b3213479b0ba8d`; combined selector `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`.
- Result/log artifacts `9458599611 / 9458599992`, SHA-256 `c88f85050a38dcefe87cedbfda9b5bc6ca196d3a74bcd9d5cd35574c71db9f65 / 18a5cfb0617aa503ab9014b1e41f5ea4c7419761bc488dc3cdca2fb093421bea`. Package and materialized source are byte-identical pre/post; no rebuild/relink/repair/generated discovery/benchmark/CLI/custom input or semantic mutation occurred.
- First schema control `32513439436` exposed malformed-YAML transport before runtime, and subsequent large payload repair controls failed byte identity. Both are resolved orchestration/non-stable/attempt-free. Compact workflow blob `7a604bedc113b5b1c2f89038a18e22cd26c9b34e` was independently schema-green in `32515108310` and passed in-run validation `96875257718` before the 304 gate.
- First documentation closeout `32516236265 / 96878457696` stopped before commit because its changed-path oracle omitted the newly added untracked report. This is resolved closeout orchestration/non-stable and does not alter the accepted gate.
- CP3b acceptance attempt **1/3 is consumed and green**; CP3b is **CLOSED / ACCEPTED**. M3 remains **21 packages**; stable accounting remains **41 / 14 / 27** and produced-witness debt **5**.
- Consolidated at closure into `M3_CP3_Closure_Record.md`; the per-turn report is retired.
- Acceptance closeout orchestration candidates `M3-CP3b-TB-CAND-01` through `-04` are resolved non-stable; the final two were documentation-only changed-path/payload-transport controls and did not alter the green 304/304 gate.

### 2026-08-21 — M3 CP3b Code + Build complete; immutable package advances to 304 acceptance gate

- Final exact CP3b semantic source is `611b3f8f3926792baee9d1078d6677d22006a6c4`, confined to `SurfaceCellTracing.h/.cpp` and `FieldAlignedCurveNetworkTests.cpp`. Exactly six frozen CP3b identities and the independent test-only composition oracle compile; no accepted CP3a test body or frozen witness was modified.
- Initial source `233b8e83be338e9a590c4aa5dfb220e9aa2119f2` exposed one compile-only non-default-construction defect in shrink-only `vector::resize()` at `32507150872 / 96849810459`; bounded `erase()` correction `32507540808 / 96851028033` produced final source `611b3f8...`. A broad caller glob also caused metadata-only run `32507540724`; compile was skipped. Both are resolved/non-stable and executed no generated runtime.
- Corrected-source mandatory pre-package compile `32507660499 / 96851404185` is green: core **75/75**, remaining phase **28/28**, result/log `9455956709 / 9455957273`, SHA-256 `25f6e69a8ba6e32c2dcbaf54eeeeec277ff5b2329b768dba39aa15caac78acac / d240b2858a25e2b32f47681299babba4314740e7ce3f30e192cbedd3faf0aa3f`.
- Eight-target package build `32508124000 / 96852846743` is green on the same source. Immutable package **`9456073195`**, ZIP SHA-256 **`6126acc44121ae6ca05f8b01f075bd26ce72e4f08851c80d09209c2a225a3c31`**; log `9456073672`, SHA-256 `52a79592efd091788bd21242d8c12229411d01ee2e4dcdb5d42b572fad765c92`. Internal manifest 27/27, zero symlinks, source clean, six executables/two static libraries, `runtimeExecution=false`.
- M3 packages advance **20 -> 21**. CP3b attempt **1/3 remains unconsumed**; stable accounting remains **41 / 14 / 27** and produced-witness debt **5**. Package `9456073195` is TB-eligible but not accepted. Exact next is immutable `M3-CP3b-TB` at **304 = accepted 298 + six CP3b identities**, with generated discovery prohibited.

### 2026-08-21 — M3 CP3a accepted 298/298; typed CP3b contact/event graph is next

- Immutable `M3-CP3a-TB` run/job `32485441510 / 96780835699` consumed exact source/package `558a35c67919d54899c53de11dc9c69b6dfc9519 / 9435408599`, package SHA-256 `8d31055edb7fbdbcaed1ad168dc9e1b9e2493d577429d88989589715f6009c94`. Corrected caller bytes were SchemaStore-validated by `32485281333`; the runtime's own schema job `96780792237` also passed.
- Exact frozen gate **298/298 PASS**: accepted predecessor **292/292** plus CP3a **6/6**, 298 unique identities, zero failures. Predecessor selector SHA-256 `fc6bfc2b90c8a39512ee89e73106f2592fd4664aa90929c8c970e3ef0455245e`; CP3a selector `fa9bab1118b80f4727fb1ca7361b2967061d95d8a9e7de667d3648599e3b227b`; combined selector `44dede9235fb53b486e351c02f87d4f8d5044e50ec77df6d7befbf072dfb5a25`.
- Result/log artifacts `9447743880 / 9447744442`, SHA-256 `85ab373bcdf3d5a2af6d5c1742c41ec598afff3ae03a0a4f5e078a7f0e737429 / 37930f3bc8b86d3a46b324c4460ecfbcabc60b83f6c67fb5b13d1166f91cf24c`. Package and materialized source are byte-identical pre/post; `artifactOnly=true`, `generatedDiscovery=false`, no rebuild/relink/repair/benchmark/CLI/custom input or semantic mutation.
- CP3a acceptance attempt **1/3 is consumed and green**; CP3a is **CLOSED / ACCEPTED**. M3 remains **20 packages**; stable accounting remains **41 / 14 / 27** and produced-witness debt **5**.
- Four CP3a-TB orchestration candidates are resolved/non-stable: workflow registration/activation produced no observed TB runtime; the caller permission ceiling was corrected before authoritative runtime; the first docs-closeout stale-reference guard incorrectly inspected temporary workflow control text; and closeout retry `32494245284 / 96808854595` hit a compressed-payload transport CRC/length error before the transform ran. None changes accepted runtime evidence or stable accounting.
- Current authoritative report is `Architecture_M3_CP3a_Artifact_Only_Test_Benchmark_Report.md`. Exact next is `M3-CP3b-CB` under `Architecture_M3_CP3b_Code_Build_Plan.md`; CP3b starts with attempt **1/3 unconsumed**, runtime-free Code + Build, and frozen successor **304 = accepted 298 + six CP3b identities**.

### 2026-08-21 — M3 CP3a final diagnostic gate green 6/6; same immutable package advances to 298 acceptance gate

- Final attempt-free `M3-CP3a-DG-R1` run/job `32463985548 / 96716645034` consumed exact corrected source/package `558a35c67919d54899c53de11dc9c69b6dfc9519 / 9435408599`, package SHA-256 `8d31055edb7fbdbcaed1ad168dc9e1b9e2493d577429d88989589715f6009c94`. Schema validation job `96716598767` passed before the diagnostic workload.
- Exactly the six frozen CP3a identities executed once and passed **6/6** in 4 ms. Result artifact `9439973724`, SHA-256 `c745a1ecdd59761a9f563175f66963f3092eda2bb3be061b1bb52738b3952385`; log artifact `9439974320`, SHA-256 `fb9cc86e74eb986963daafe6e01bbc1b136901b15173a8bf0727079f26be99f1`.
- Immutable-package controls passed before and after runtime: outer package digest matched, internal `SHA256SUMS` passed, exact semantic source matched, and the whole package inventory was byte-identical postflight. `artifactOnly=true`, `generatedDiscovery=false`, `acceptanceAttemptConsumed=false`; no accepted predecessor identity, checkout as semantic authority, configure/build/relink/repair, benchmark, CLI, custom input, or source/test/fixture mutation ran.
- The two prior non-stable CP3a candidates are **resolved**: the two-ring witness now reaches the required non-vacuous traversal/transport seams, and equivalent branch relabeling is semantically invariant while foreign/tampered atlas binding still rejects. Stable totals remain **41 / 14 / 27** and debt **5**.
- M3 packages remain **20**. CP3a DG usage is now **2/2 exhausted**; acceptance attempt **1/3 remains unconsumed**. Diagnostic green is not acceptance. Package `9435408599` is now TB-eligible and exact next is immutable `M3-CP3a-TB` at **298 = 292 + 6** on the same package.

### 2026-08-21 — M3-CP3a-CB-R1 complete: corrected traversal witness and semantic binding compile/package green

- Independent DG Review J1-J6 was implemented within the reduced three-file CP3a semantic surface. Initial reviewed source `8d764d67d71927eb70aae4cdcce897da593cb4a4` hit one compile-only test-witness defect at `32449480083 / 96675120134` (`DomainResult<SourceEdgeTopologyKey>` dereferenced instead of `.value()`); no package or generated runtime occurred.
- A bounded one-line correction in `tests/FieldAlignedCurveNetworkTests.cpp` produced final semantic source **`558a35c67919d54899c53de11dc9c69b6dfc9519`**. Corrected-source mandatory pre-package compile `32449873710 / 96676314494` passed the exact two required targets; result/log `9435349212 / 9435349672`, SHA-256 `fd2eabf9741bbf54dead5d3ed2326afd6275cb7ca8bb50361f04e9e65db07ede / 46fe50986a8c016613b6b90cb9039175e1dda3adf9c6de61b18f38676f764357`.
- Exact eight-target package compile `32449873710 / 96676759594` passed on the same source. Immutable package **`9435408599`**, outer SHA-256 **`8d31055edb7fbdbcaed1ad168dc9e1b9e2493d577429d88989589715f6009c94`**; log `9435408871`, SHA-256 `db1286d9e211e39ab55885542ddb43fcd0fbb3f38a5bab85a74e9321dfc55fef`. Internal manifest **27/27**, source clean, zero symlinks, `runtimeExecution=false`.
- M3 packages advance **19 -> 20**; CP3a acceptance attempt **1/3 remains unconsumed**, DG remains **1/2 used**, stable accounting **41 / 14 / 27**, produced-witness debt **5**. Package `9435408599` is DG-eligible but **not TB-eligible**. Exact next is the second/final six-identity CP3a diagnostic gate; green then same-package 298 TB, red then Review with no DG remaining.

### Changed — M3 CP3a DG review: witness reds are a topological impossibility; digest carries two domains; J1-J6 authorize CB-R1

- `M3-CP3a-DG-REVIEW` completed as Review/planning only. No product, test, fixture, selector, or build edit; no compile, package, DG, or generated Directional runtime. Result: **`the retained CP3a DG-review history in `CHANGELOG.md``**. Decision: **AUTHORIZE `M3-CP3a-CB-R1`** with the witness replaced and the semantic surface reduced. **The traversal implementation is not implicated by any of the four reds.**
- **F1 — the three witness reds are a topological impossibility, not an attachment choice.** The DG report attributes them to "current … attachment choices"; that wording is too weak and acting on it would have wasted the last diagnostic gate. `build_singularity_attachments(...)` defines each attachment's first outgoing carrier as the edge **opposite** the singular vertex in that fan face. `make_skew_four_triangle_fan()` is `(0,1,4) (1,2,4) (2,3,4) (3,0,4)` with centre `4`, so those edges are `(0,1) (1,2) (2,3) (3,0)` — each belonging to exactly one face and therefore an **outer boundary edge**, while the radial edges are the only interior ones and are never a first outgoing carrier. Every centre-port candidate meets a barrier on its first step, and **no attachment choice can change it**: the witness is structurally incapable of the traversal CP3a must prove.
- **This corrects the CP3a plan authored by the same reviewer.** Plan section 6.5 claimed a multi-face traversal was "achievable on" the skew fan; it is not. The plan correctly mandated the non-vacuity assertions and correctly required a proven witness, but did not check that the reused mesh could satisfy the assertion it mandated. The assertions caught it at diagnostic cost rather than acceptance cost — the control working — but the check belonged in planning. `the retained CP3a Code + Build plan history in `CHANGELOG.md`` section 6 is now marked **SUPERSEDED**, with its text retained as the record of what was planned and why it was wrong.
- **F2 — the fourth red is one digest carrying two semantic domains.** `src/geometry/SurfaceCellTracing.cpp:749-753` folds `atlasDigest` into the network semantic digest, and `make_from_candidate()` binds that to `field_transport_atlas_hash(...)`, which consumes the **raw** adjacency transport (`src/authority/FieldTransportAtlas.cpp:1060-1074`) and is gauge-dependent. The DG closes it empirically: under an equivalent Z4 relabel the branch-topology digests and `candidate_traces()` compare **equal** while the network digests differ, and `sourceDigest` is mesh-only, so `atlasDigest` is the only gauge-dependent ingredient. Semantic identity must be gauge-invariant; provenance/binding identity is legitimately representation-dependent. **The frozen identity 6 is right and the digest composition is wrong** — identity 6 must not be weakened.
- **F3 — two of the four "passes" are vacuous on this witness.** `CandidateTraceStopsAtMandatoryBarrierWithoutCrossing` passes *because* every candidate stops at a barrier immediately, so it cannot distinguish correct barrier handling from inability to move; `CandidateTraceOrderingIsInvariantToPortEnumeration` passes over single-segment candidates. Both are reached-and-passing, not proven, and may legitimately fail on the corrected witness — that would be information, not regression.
- **Corrective measures J1-J6.** **J1** replace the witness with a **two-ring** skew planar disc so the inner-ring chords serving as first outgoing carriers are interior; one witness serves all six identities since the outer boundary supplies the barrier. **J2** build the field the proven way — author only per-face directions, derive matching/effort/index through `finalize_cross_field_result(...)`, and assert the interior-filtered index distribution; hard-code no face-pair order, matching, effort, or cardinality, and if the directions do not yield a single interior `+1`, adjust the directions rather than the conventions. **J3** keep the two non-vacuity `ASSERT_`s ahead of the contract assertions. **J4** split the digest so semantic identity consumes the gauge-invariant `branch_topology().semantic_digest()` while the full atlas hash is retained separately for binding/provenance, with every `InvalidAtlasBinding` check still comparing full atlas identity. **J5** pin J4 with a negative proving a foreign or tampered atlas is still rejected, without which J4 is indistinguishable from deleting a check. **J6** reduce the surface to **three files**.
- **Surface reduced from five files to three.** The shared-header extraction specified in CP3a plan sections 6.3-6.4 is **withdrawn** — under a different witness mesh there is nothing to share — which also removes the risk of perturbing an accepted CP2b test file. `tests/FieldTransportAtlasTests.cpp` and `tests/support/` are now **frozen**, and touching them is a stop condition. `src/pipeline/RemeshPipeline.cpp` remains excluded; a fourth semantic file remains a stop condition. The pre-package compile set correspondingly drops `directional_surface_cell_authority_kernel_tests`.
- **`LESSONS.md`** section 2 gains two lessons: *a non-vacuity requirement is only as good as the check that the witness can satisfy it* — reusing a proven witness proves it was non-degenerate for **its** contract, not the next one — and *green identities on a degenerate witness are not evidence either*, so the passes must be re-audited whenever the failures are attributed to the witness. Subsequent lessons renumbered; none removed or weakened.
- **Candidate dispositions.** `M3-CP3a-DG-CAND-01` remains **ACTIVE / NON-STABLE** with its cause **sharpened** from an attachment choice to a topological property of the one-ring fan. `M3-CP3a-DG-CAND-02` remains **ACTIVE / NON-STABLE**, re-classified as one digest carrying two semantic domains.
- Exact next is `M3-CP3a-CB-R1`, then the **second and final** CP3a diagnostic gate; a green DG lets that same package advance to `M3-CP3a-TB` at **298 = 292 + 6** consuming acceptance attempt 1 of 3, and a red DG stops for Review because no gate would remain. No package, acceptance attempt, or diagnostic gate was consumed by this Review. M3 remains **19 packages**, reported only; **CP3a attempt 1 of 3 unconsumed, DG 1 of 2 used**. Stable accounting remains **41 / 14 / 27**; produced-witness debt **5**. CP2b remains the accepted runtime authority at **292/292** and package `9432965083` is not TB-eligible.

### 2026-08-21 — M3 CP3a diagnostic gate valid RED 2/6; Review required before correction

- Artifact-only `M3-CP3a-DG` run/job `32445011345 / 96662902496` consumed immutable source/package `350d94642655a97c34f6434e1b049a1dbcbf5e61 / 9432965083`, verified the package outer digest and internal manifest, selected exactly the six frozen CP3a identities once, and produced **2 PASS / 4 FAIL**. Package hashes were byte-identical after runtime; no predecessor identity, rebuild, relink, repair, generated discovery, benchmark, CLI, or custom input ran.
- Result artifact `9433754731`, SHA-256 `57b2af3445e8647c4dc2cb030390e2051b499bca4463e0d6d009fcfb5a7f6297`; log artifact `9433754999`, SHA-256 `766a33b47aefcf8cd41b98739894b73a542fd3252cdb34542ab48c96bb0f11a3`. `acceptanceAttemptConsumed=false`.
- Three red identities stop at fixture/non-vacuity setup: the current skew-fan attachments produce no multi-face candidate, no crossed adjacency, and therefore no `entryTransport` for the atlas-binding tamper. The fourth red reaches the network semantic-digest seam: equivalent relabeling preserves branch-topology semantic digest and candidate traces but changes the enclosing network digest (`14630329552257752498` vs `16578924514341813520`).
- Non-stable candidates `M3-CP3a-DG-CAND-01` (`RP-02`) and `M3-CP3a-DG-CAND-02` (`RP-05`) record the two root-cause classes. Stable totals remain **41 / 14 / 27**; produced-witness debt remains **5**; M3 packages remain **19**; CP3a DG usage is **1/2**, and attempt **1/3 remains unconsumed**.
- Exact next: `M3-CP3a-DG-REVIEW`. Package `9432965083` is not TB-eligible. Exact evidence: `the retained first CP3a DG history in `CHANGELOG.md``.

### 2026-08-21 — M3 CP3a Code + Build complete; exact-source compile and immutable package green

- `M3-CP3a-CB` completed **runtime-free / not accepted** on exact semantic source `350d94642655a97c34f6434e1b049a1dbcbf5e61`. Direct semantic comparison contains exactly the frozen five files: `SurfaceCellTracing.h`, `SurfaceCellTracing.cpp`, `FieldAlignedCurveNetworkTests.cpp`, mechanical `FieldTransportAtlasTests.cpp`, and new shared `tests/support/SkewSingularFieldWitness.h`; `src/pipeline/RemeshPipeline.cpp` is untouched.
- CP3a publishes typed branch-consistent candidate traces consuming CP2b branch frames, pairings, typed transport, and singularity-port attachments without raw-field semantic fallback. The six frozen CP3a identity names remain unchanged. The accepted skew witness is extracted once to the shared header; `ASSERT_`-level non-vacuity requires a multi-face candidate and a mandatory-barrier termination.
- Mandatory exact-source pre-package compile `32441366150 / 96652587987` passed `directional_core`, `directional_surface_cell_producer_tests`, and `directional_surface_cell_authority_kernel_tests`; result `9432630013` SHA-256 `e7a44304e668fe89b61c867e7186a108f5e03602febdcaea262930fac1d42a13`; log `9432630251` SHA-256 `dc5163f65fa3e4408a5903eae0f3d675e3bb1188862df5dd76aa80bdf309023d`; `runtimeExecution=false`.
- Full established eight-target package compile `32442515042 / 96655880784` passed on the same literal semantic source and produced immutable package **`9432965083`**, SHA-256 **`bf9a8da0d4d245e2783fe19effd511117bec6586311fa7543ef99508365425b3`**; log `9432965286`, SHA-256 `533b222c41431011415f5898f4b46bedc2409ecd14a1dcb3f89cc5a40d1ca5b9`; `runtimeExecution=false`.
- M3 cumulative packages advance **18 -> 19**, reported only. CP3a acceptance attempt **1/3 remains unconsumed** because package creation is not a valid acceptance gate result; CP3a DG usage remains **0/2 used**. Stable totals remain **41 / 14 / 27** and produced-witness debt **5**.
- Exact next is artifact-only **`M3-CP3a-DG`** on package `9432965083`, six new identities only, attempt-free and without rebuild/source mutation/generated discovery. Green DG is not acceptance; the same package then advances to `M3-CP3a-TB` at **298/298**.
- Durable CB evidence: `the retained initial CP3a Code + Build history in `CHANGELOG.md``.

### Changed — M3 CP3a replan complete; self-contained CP3a Code + Build plan authored; witness reachability defect found

- `M3-CP2b-ACCEPTANCE-CLOSEOUT-CP3a-REPLAN` completed as Review/planning only. No product, test, fixture, selector, or build edit; no compile, package, DG, or generated Directional runtime. **No CP3a acceptance attempt consumed.** Turn result: section 8 of ``M3_CP2b_Closure_Record.md` / retained changelog history`.
- **Output: `the retained CP3a Code + Build plan history in `CHANGELOG.md``**, authored to be **self-contained**. Every type, accessor, file path, target name, and identity string an implementation turn needs is stated explicitly with source line references, assuming no prior knowledge of CP2b or of the retired CP3a plan. All eight of the replan plan's required-review items are discharged, plus the binding section 7 added at CP2b closure verification.
- **Material finding — the accepted CP2b witness is not reachable from CP3a's test file.** CP3a's six identities are `FieldAlignedCurveNetwork.*` in `tests/FieldAlignedCurveNetworkTests.cpp`, owned by `directional_surface_cell_producer_tests` (`cmake/DirectionalTests.cmake:68-87`); the accepted non-degenerate witness `make_skew_four_triangle_fan` / `make_skew_index_one_singularity_field` lives in `tests/FieldTransportAtlasTests.cpp`, owned by the **different** executable `directional_surface_cell_authority_kernel_tests` (`:308-312`). The CP3a file's local fixtures are a **regular** planar fan with four equal 90° sectors — the shape that produced vacuous evidence three times in M3. Resolution: extract the witness into header-only `tests/support/SkewSingularFieldWitness.h` and include it from both files, following the existing `tests/TestAuthorityIds.h` / `tests/support/SurfaceCellProductOracle.*` convention with **no CMake change**. The extraction modifies an accepted CP2b test file, so the risk is made falsifiable: **the 292 predecessor staying green in the CP3a gate is the proof it was behaviour-preserving.** A second copy of the witness anywhere is a stop condition.
- **Scope reduced: `src/pipeline/RemeshPipeline.cpp` is removed** from the retired plan's four-file surface. CP3a publishes candidate segments inside the A2a product and no production consumer reads them until CP3b; including the pipeline would add a production-cutover domain to a checkpoint that already has a traversal domain — the unit-3 Batch E error that cost four of six attempts. Needing it is now an explicit stop condition. Net surface is **five files**, one of them a mechanical-only edit.
- **The six frozen CP3a contract names were affirmatively re-checked**, as required by replan section 7.2, and **all six remain valid unchanged** under the narrowed consumer scope; plan section 5.1 records each verdict and its reason. None was renamed, dropped, or weakened.
- **Traversal shape frozen** (plan section 8.2): start from `FieldSingularityPortAttachment`'s `startFace` and `branch`; per face use `find_frame(...)`, then the pairing for the current branch, then its outgoing carrier; check the carrier against the atlas barrier set and stop before crossing if it is one; otherwise call `branch_topology().transport(carrier, from, to)` and rotate by `signedLift`. Prohibited: raw `CrossFieldResult`, `primaryDirections`/`secondaryDirections`, face-axis geometry, `family`/`sign`, nearest-direction selection, raw face rows, container order, and — called out explicitly because it is easy to get wrong — `FieldAlignedSingularityPort::ordinal` as a branch, since it is allocated by a plain counter and carries no branch meaning.
- **Binding non-vacuity requirement:** the witness must produce at least one candidate crossing more than one source face and at least one terminating on a mandatory barrier, both asserted at `ASSERT_` level as explicit preconditions before the contract assertions.
- **Mechanics frozen:** pre-package compile on `directional_core`, `directional_surface_cell_producer_tests`, `directional_surface_cell_authority_kernel_tests`, verified from `CMakeLists.txt:174` and `cmake/DirectionalTests.cmake`; package over the established eight-target closure; `runtimeExecution=false` throughout. Successor gate is **298 = 292 + 6**, with `M3-CP3a-DG` recommended first — attempt-free, 2 available, and a green DG plus that same package's TB is one attempt total.
- Exact next is `M3-CP3a-CB`, attempt **1 of 3** with **2 diagnostic gates unused**. M3 remains **18 packages**, reported only. Stable accounting remains **41 / 14 / 27**; produced-witness debt **5**; `CAND-01` and `CAND-02` remain resolved non-stable.

### Changed — M3 CP2b closure independently VERIFIED; consolidation confirmed; CP3a implementation shape decomposed

- Closure-verification Review, planning only. No product, test, fixture, selector, or build edit; no compile, package, DG, or generated Directional runtime.
- **The CP2b acceptance claim is VERIFIED**, re-derived from source and artifact evidence rather than accepted from the closeout report. Record: `M3_CP2b_Closure_Record.md` **section 6**. The gate reached **292/292** across ten partitions at exact cardinality with the predecessor at **287/287** and CP2b at **5/5**; the GTest JSON census independently reports 292 tests / 0 failures / 292 unique identities; selector digests are unchanged; immutability flags are clean with byte-identical postflight and `harness-postflight.txt` PASS.
- **Verified from source rather than from the report.** **H5** — `git diff 9fdb928f…1d2417c9 -- src/ include/` is **empty**, so `src/authority/FieldTransportAtlas.cpp` was genuinely frozen across CB-R7/TB-R5, and the tests diff is exactly one file at `+133/-3`. **H1** — `independent_face_gauge(...)` (`tests/FieldTransportAtlasTests.cpp:642-702`) computes the oracle's **own** per-face gauge, `:1316` forms `canonicalLift = sourceMeasurement.matching + firstGauge − secondGauge` from its own measurement, `:1322` applies its own canonical-orientation rule, and `:1324` reduces mod 4; **no `rawGauge*` symbol is read anywhere in the tests**, so the correction is a re-derivation and not a relaxation. **H4** (`:2506-2530`) — a `+1` displacement rejects with `NonReciprocalAdjacency` while a `+4` displacement is accepted, pinning congruence without pinning representative choice. **H3** — pairing, attachment, and duplicate-identity tampers all still reject with specific codes, so the oracle did not become permissive. The Part F/G predictions are confirmed: 5 incidences / 3 classes, the two face-0 incidences sharing `startFace=(0,1,4)` and carrier `(0,1)` with branches `2` and `3` in distinct classes `0` and `1`.
- **On the first closure claim.** CP2b was reported closed once before this record existed, with the TB-R5 gate **triggered** and no result recorded anywhere. That claim was **rejected**: a control-plane commit is never runtime evidence, and no closure record was written and no per-turn document retired, because the documents a closure record must consolidate are the evidence it is made of. The second claim supplied the gate result and passed verification. Rejecting the first claim cost one turn; accepting it would have put a fabricated acceptance into the durable record.
- **Consolidation verified.** All CP2b per-turn documents are retired, `M3_CP2b_Closure_Record.md` is the consolidated record and is now **registered in `RETENTION_POLICY.md`'s durable set**, the accepted ``M3_CP2b_Closure_Record.md` / retained changelog history` is correctly retained as current immutable authority, and temporary control-plane state is clean. The M3 plan's section 4A.1 was trimmed of superseded CP2b-era per-attempt narrative, which remains in this changelog.
- **Forward planning verified, and one gap closed.** ``M3_CP2b_Closure_Record.md` / retained changelog history` is adequate as a *freezing procedure* — eight required-review items, seven stop conditions, five required outputs, and a correct `298 = 292 + 6` successor gate. It gains a binding **section 7**: **7.1** freeze a **non-vacuity requirement for the CP3a witness**, not only an implementation prediction — one candidate crossing more than one face and one terminating on a barrier, reusing the accepted CP2b skew-fan witness, since three M3 checkpoints have already been lost to trivially-satisfied fixtures; **7.2** **affirmatively record** that each of the six frozen CP3a contract names still describes the narrowed consumer scope, or correct it in planning, since those names were authored when CP3a still owned the work that became CP2b; **7.3** stay consistent with the implementation shape.
- **The CP3a implementation shape was missing and is now decomposed** as `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md` **section 4A.1b**. CP3b and CP4 received task lists at CP2 closure; CP3a did not, because its Code + Build plan was retired when the census stop reclassified its authority work as CP2b. The task list covers consuming frames/pairings/attachments rather than re-deriving them, seeding from the attachment's checked start face and branch, stepping combinatorially from the face pairing, updating branch identity only through atlas transport, recognizing barriers before crossing, publishing candidate segments only, and preserving order and equivalent-Z4 relabel invariance — with the binding non-vacuity requirement and a pre-package re-check of the six frozen contract names. The replan plan owns the freezing procedure; 4A.1b owns the shape.
- **`LESSONS.md`** section 1 gains two lessons: *never treat a documentation or control-plane commit as runtime evidence* is extended with the triggered-versus-recorded distinction and the CP2b provenance, and *consolidation follows verification; it never precedes it* is added. Subsequent lessons renumbered; none removed or weakened.
- Exact next is `M3-CP2b-ACCEPTANCE-CLOSEOUT-CP3a-REPLAN`, Review-planning only, whose required output is one bounded `the retained CP3a Code + Build plan history in `CHANGELOG.md`` or an explicit stop/architecture-amendment finding. M3 is **18 packages**, reported only; CP2b's window is **3 of 3 consumed with attempt 3 accepted** and DG **2 of 2 exhausted**; **CP3a attempt 1 of 3 remains unconsumed** with its own 2 diagnostic gates. Stable accounting remains **41 / 14 / 27**; produced-witness debt **5**; `CAND-01` and `CAND-02` are both resolved non-stable.

### 2026-08-21 — M3 CP2b accepted: TB-R5 passes 292/292 on the final restored-window attempt

- Immutable `M3-CP2b-TB-R5` `32434684618 / 96633374819` consumes exact source/package `1d2417c90970db81f8b49dd6e0961868cac32369 / 9428451548` and passes **292/292**: predecessor **287/287**, CP2b **5/5**, 292 required / executed / unique, zero failures/disabled/errors.
- Result artifact `9430381177` has ZIP SHA-256 `41292ffef7231ef7010bd416aa6b730fd6022694933bc0c4b538abadb64bf8be`; log artifact `9430381560` has ZIP SHA-256 `a789a6567c865e119deef69c295894078ce2621f7972912666c726b1b6b886a4`. Package and materialized source are byte-identical pre/post; no checkout as semantic authority, rebuild/relink/repair/mutation/discovery/benchmark/custom input occurred.
- The Part-G prediction is fully adjudicated: equivalent-Z4 relabel invariance passes, the strict independent tamper identity passes, canonical branch frames/pairings and checked port attachments pass, and ambiguous/incomplete topology rejection passes. The non-degenerate partition remains **5 incidences / 3 classes** with same-face/same-carrier branches 2 and 3 in distinct classes.
- `M3-CP2b-TB-R1-CAND-01` is **RESOLVED / TEST-AUTHORITY / NON-STABLE**; `CAND-02` remains resolved architecture-product/non-stable. No accepted predecessor regressed; stable totals remain **41 / 14 / 27**, debt **5**.
- This valid gate consumes restored-window attempt **3/3** and **accepts/closes CP2b**. M3 remains **18 packages**, CP2b DG **2/2 exhausted**. CP3a attempt **1/3 remains unconsumed**.
- Exact next is static `M3-CP2b-ACCEPTANCE-CLOSEOUT-CP3a-REPLAN` under ``M3_CP2b_Closure_Record.md` / retained changelog history`; CP3a is not implemented in the TB-R5 turn.

### 2026-08-20 — M3-CP2b-CB-R7 complete: independent canonical-Z4 oracle corrected and final-attempt package created

- Part-G Review's **TEST-AUTHORITY** classification was implemented in exactly `tests/FieldTransportAtlasTests.cpp`; semantic edit `9316cc5a7c323ba6cf5235a9f89fc32be3cf96f0`. Product `src/authority/FieldTransportAtlas.cpp` remained frozen.
- H1/H2 re-derive canonical transport independently from mesh/field gauge, canonical topology orientation, and Z4 normalization rather than equating raw gauge-dependent matching with published canonical lift. H3 preserves the established tamper rejection matrix. H4 pins `forwardLift +1` as `NonReciprocalAdjacency` while accepting `+4` as the same Z4 representative. H5 product freeze held.
- Exact fixed source for both compiles is **`1d2417c90970db81f8b49dd6e0961868cac32369`**. Mandatory pre-package compile `32428966894 / 96616580277` passed the required three targets; result/log `9428424692 / 9428425124`, outer SHA-256 `a02a50ff88bc8d3ff0a9114d652bdc9913b53328a18c220163711257c5961480 / e36fb00362483adc80891cf3fef04e06295eee812b4dcaa72be2e77a7016bfce`; `runtimeExecution=false`.
- Full eight-target package compile `32429076886 / 96616902117` passed on the same source and produced immutable package **`9428451548`**, outer SHA-256 **`20dc884a38d865f34a14be66780ab7827cead4855a26cf0c1f945cee67131427`**; package log `9428451949`, SHA-256 `dd61c51b3f4ddbb42caabf4b0f84c2f45d35b8ff2f184278a9a9235aa0772241`. Recursive manifest verified; source clean; no generated runtime.
- M3 packages advance **17 -> 18**. Restored CP2b acceptance remains **2/3 consumed** because package creation is attempt-free; DG remains **2/2 exhausted**; stable accounting **41 / 14 / 27**, debt **5**. `CAND-01` is **ACTIVE / TEST-AUTHORITY / NON-STABLE** pending runtime; `CAND-02` remains resolved.
- Exact next: artifact-only **`M3-CP2b-TB-R5`** on package `9428451548`, frozen 292/292, restored-window attempt **3 of 3 (LAST)**. A valid red triggers the second mandatory CP2b Review.

## 2026-08-23 — M3-CP4ab-CB-R7 cyclic singularity-port order / runtime-free package PASS

- Completed the binding R7 pre-mutation proof gates before semantic mutation. The accepted skew witness and equivalent-Z4 relabel admit the same strict fan-anchored cyclic port order without ID/container/source-row tie-breaking.
- Semantic source `bd362ab5e7bb50ebb1fcf7bb50c99697923ad4e4` changes only the reviewed authority surface: A1 writes fan-anchored CCW `FieldSingularityPortAttachment::localSlot`; A2a transports it through `FieldAlignedSingularityPort::ordinal`; A2b consumes that ordinal before face walking; fragment-corner incidence derives `V_int`; terminal `nullopt` traces are slits only for that incidence derivation. Frozen `F`, `E_int`, K2R/K3R ownership, fragment adjacency, witness geometry, P4 validation order, and B4 scope are unchanged.
- Preserved patch application run/job `32674751505 / 97280895899` passed after schema validation `32674685112`; changed exactly the two product files, two focused test files, and the R7 report; `runtimeExecution=false`.
- Affected-owner compile `32674930745 / 97281329245` passed for `directional_surface_cell_authority_kernel_tests` and `directional_surface_cell_producer_tests`.
- Exact six-target package compile `32675070264 / 97281667664` passed from the same semantic SHA. Immutable package artifact `9502422252`, ZIP SHA-256 `c5faaf76fc2029210dfa305f8856a3a2e97e2efcec5f46ad1b6cb4eb235ded97`, source archive SHA-256 `3af19ac021d3315ecc8e62b674a33b0f69e9c6704d33d7b70ec876702d34c3f7`, manifest **27/27 PASS**, source status clean, `runtimeExecution=false`.
- No generated Directional binary, test, benchmark, discovery command, ctest, CLI, fuzzer, help/version command, or custom input executed during CB-R7.
- M3 package count advances **30 -> 31**. Acceptance remains **0/3** and diagnostics **0/2**; stable accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**.
- Exact next: `M3-CP4ab-DG-R3`, immutable artifact-only and attempt-free on artifact `9502422252`, frozen 12 identities one process each with identity-scoped raw streams/exits/durations/typed diagnostic association. TB-R3, B4 correction, and CP4c remain blocked pending the required predecessor work.

## Changed — M3 CP2b TB-R4 semantic review: the failing identity is internally contradictory; oracle is the defect; H1-H5 authorize the final windowed attempt

- `M3-CP2b-TB-R4-SEMANTIC-REVIEW` completed as Review/planning only. No product, test, fixture, selector, or build edit; no compile, package, DG, or generated Directional runtime. Result is **Part G** of `Architecture_M3_CP2b_TB_R4_Semantic_Review_Plan.md`.
- **Part F's prediction was confirmed exactly.** G1 reported **5 incidences / 3 classes / expected 3**, with the two face-0 incidences sharing carrier `(0,1)` and differing by branch `2` versus `3`, **in different classes `0` and `1`** — Reading A, as predicted from the frozen geometry. G3 was satisfied, G2 was correctly authorized, and `PublishesCheckedSingularityPortAttachments` now passes with the three-field key and G4's exact duplicate rejection. **`CAND-02` is properly resolved.**
- **The sole remaining red is an internally contradictory identity.** `BranchTopologyIsInvariantToEquivalentZ4Relabeling` (`tests/FieldTransportAtlasTests.cpp:2248-2295`) requires three things that cannot hold together: raw matching **must change** under `gauge_relabel_field(..., {0, 1, 3, 2})` (`EXPECT_TRUE(matchingChanged)`); published transports **must not change** (`EXPECT_EQ(baseline...transports(), relabeled...transports())`); and raw matching **must equal** the published lift, via the oracle's `transition.matching != typed.forwardLift` at `:1229`. If the first two hold, the third cannot hold both before and after the relabel. The identity's own name states which two are the contract — **invariance** — so the oracle assertion is the defect.
- **The oracle comparison is wrong on three independent axes.** `src/authority/FieldTransportAtlas.cpp:292-318` derives the published lift by adding the per-face **gauge** (`+ rawGauge[first] - rawGauge[second]`), applying **canonical orientation** (negated when `firstFaceTopology > secondFaceTopology`), and **normalizing into `[0,3]`** — with an in-source comment stating that CP2b publishes Z4 branch transport and deliberately stores the unique canonical representative rather than leaking the raw gauge representative into equality and semantic hashing. Raw `transition.matching` carries none of the three. They coincide on the baseline for this fixture, and the relabel breaks the gauge axis — which is exactly what the relabel exists to do.
- **The product is not at fault.** Matching is a Z4 quantity, the cycle index is computed from `effort` rather than matching magnitude, and `QuarterTurn` composition is modular throughout. The canonicalization is the only way the identity's invariance requirement can hold, and the validator already compares mod 4 two lines earlier at `:1219-1221`.
- **Two further comparisons of the same shape stand behind the fix** and are recorded rather than left to be discovered: `sourceMeasurement.matching != transition.matching` (`:1230`), where `independent_edge_measurement` returns a principal value while `gauge_relabel_field` writes an unnormalized sum — the most likely next failure if only the reported comparison is corrected; and `QuarterTurn::from_integer(sourceMeasurement.matching) != typed.forward` (`:1232`), which is mod-4 on the left but applies neither gauge nor orientation. All three belong in one correction.
- **Corrective measures H1-H5, test-only.** **H1** — the oracle must **re-derive** the canonical Z4 representative independently: its own per-face gauge from the mesh reference edge and field directions, its own canonical-orientation rule, reduced mod 4, never reading `rawGaugeByRow` or any product-side gauge. **H2** — fix all three comparisons in one change. **H3** — prove the oracle still rejects at every existing tamper call site (`:1842`, `:1914-1924`, `:2121`, `:2172`, `:2259`, `:2346`) and report each explicitly; an oracle that stops rejecting is a worse outcome than the current red. **H4** — add a negative pinning the new comparison: perturbing a published `forwardLift` by `+1` must reject while `+4` must be accepted, which pins congruence without pinning representative choice and proves H1 did not become vacuous. **H5** — **do not change the product**; `src/authority/FieldTransportAtlas.cpp` is frozen and any product edit is a stop condition returning to Review.
- **Falsifiable prediction:** with H1 and H2 the validator accepts both the baseline and relabeled snapshots, the identity goes green, and the gate reaches **292/292** with the accepted predecessor still at **287/287**, every tamper site still rejecting and H4's `+1`/`+4` behaving as specified. A **different** oracle comparison failing means the correction was incomplete rather than wrong; a **tamper site ceasing to reject** means H1 was implemented as a relaxation rather than a re-derivation, and must be reverted.
- **Exact next is `M3-CP2b-CB-R7` then `M3-CP2b-TB-R5`**, with a semantic surface of **exactly one file**, `tests/FieldTransportAtlasTests.cpp`. **Attempt accounting is now the binding constraint:** the restored window is **2 of 3 consumed**, so this is the last attempt before the **second** mandatory CP2b review, which under the ratchet may not re-authorize the same approach unchanged and must rescope or split the checkpoint, amend the design, or recommend stopping. The Review states explicitly that this is not a reason to widen scope — the correction is one file, three comparisons, and one negative.
- **`LESSONS.md`** gains three section-3 lessons: *a test that asserts both invariance and raw equality is internally contradictory — check the identity against itself before blaming either side*; *a canonicalized representative and a raw representative are different quantities — compare them modulo the canonicalization, or not at all*; and *fixing an over-strict oracle means re-deriving, never relaxing*. Subsequent lessons renumbered; none removed or weakened.
- **`CAND-02`** is **RESOLVED** and runtime-proven. **`CAND-01`** is re-classified from unadjudicated-semantic to **ACTIVE / TEST-AUTHORITY / NON-STABLE**: seven turns in, the relabel seam is finally reached, the cause is an oracle-side representation conflation rather than a product-side branch-lift defect, and the canonical `[0,3]` normalization it once questioned is now **positively supported** by the passing invariance assertions.
- No package created and no acceptance attempt consumed by this Review. M3 remains **17 packages / 3 historical rejected CP2b acceptance attempts**; restored window **2 of 3 consumed**; **DG usage 2 of 2 exhausted**. Stable accounting remains **41 / 14 / 27**; produced-witness debt **5**. No accepted predecessor regressed at TB-R4; CP2 remains the latest accepted runtime authority at **287/287**; CP3a remains blocked.

## 2026-08-20 — M3-CP2b-TB-R4 valid immutable gate reaches relabel seam: 291/292, predecessor 287/287

`M3-CP2b-TB-R4` executed exact R6 source/package `9fdb928fe872190b27aa6022b43608eeccf329e4 / 9422702053` artifact-only under SchemaStore-validated control. Runtime `32418067075 / 96583693356` selected **292 required / 292 executed / 292 unique**, producing **291 PASS / 1 FAIL**: accepted predecessor **287/287 PASS**, CP2b **4/5**. Result/log artifacts `9424720052 / 9424720589`, outer SHA-256 `ac1a5d3309b3347e2f851c91a624e13fab55cbbb9bcd3adc9c35f0ce78a1b29a / 46ca00bff9bcd64b8d2539dc5c58e20bcd162fb889f69c572c2b7bef71e54eee`. Package and materialized source remain byte-identical; no checkout, build, relink, repair, mutation, generated discovery, benchmark, CLI, fuzzer, or custom input occurred.

G1 confirms the semantic structure exactly in five emitted centre-singularity blocks: **5 incidences / 3 classes / expected 3**. Face 0 contributes two incidences with the same `startFace=(0,1,4)` and `firstOutgoingCarrier=(0,1)`, branches `2` and `3`, and different classes `0` and `1`; faces 1-3 contribute one incidence each. G4 is green: `PublishesCheckedSingularityPortAttachments` proves the legitimate branch-disambiguated pair and rejects an exact three-field duplicate. `M3-CP2b-TB-R1-CAND-02` is therefore **RESOLVED / ARCHITECTURE-PRODUCT / NON-STABLE**.

The sole red is `BranchTopologyIsInvariantToEquivalentZ4Relabeling`. Both baseline and relabeled atlas builds succeed; only the independent snapshot validator rejects the relabeled snapshot at `FieldTransportAtlasTests.cpp:2290`. The assertion is non-fatal, and every later direct production invariance check passes: frames, transports, canonical `[0,3]` lifts, reciprocal reverse transport, attachments, semantic digest, and nonzero transport. `CAND-01` is narrowed to **ACTIVE / INDEPENDENT-VALIDATOR RELABEL SEAM / NON-STABLE** pending static independent Review. No stable predecessor regressed, so totals remain **41 / 14 / 27**, debt **5**. Restored-window attempt **2/3** is consumed; packages remain **17**; DG remains **2/2 exhausted**; CP2b remains unaccepted and CP3a blocked. Exact next is `Architecture_M3_CP2b_TB_R4_Semantic_Review_Plan.md`.

## 2026-08-20 — M3-CP2b-CB-R6 complete: branch-disambiguated singularity representatives compiled and packaged

`M3-CP2b-CB-R6` is **COMPLETE / COMPILE-GREEN / RUNTIME-FREE / UNACCEPTED**. Post-TB-R3 Review Part F authorized G1-G5. Exact semantic source `9fdb928fe872190b27aa6022b43608eeccf329e4` changes only `src/authority/FieldTransportAtlas.cpp` and `tests/FieldTransportAtlasTests.cpp` (88 insertions / 5 deletions). G1 publishes the complete incidence/class partition and adjacency `signedLift` values before later rejection. G3 is discharged statically because TB-R3's old duplicate-port guard is explicitly cross-class after representative election. G2 widens deterministic representative identity/order to `(startFace, branch, firstOutgoingCarrier)` without changing incidence generation or the union-find equivalence. G4 independently pins a legitimate same-face/same-carrier/different-branch pair and an exact three-field duplicate rejection. G5 retains the valence-3 `+1` production exposure without claiming new runtime evidence.

Mandatory pre-package compile `32412343121 / 96565426102` succeeded on the exact three required targets; result/log artifacts `9422629376 / 9422629735`, SHA-256 `a0bd2c4c488758e4e6629ccbce3c305501fc0a1a3723c8fb1666343ca92c1f8d / 4f4a89152ab3aeef72cf412e081d0a1523132db22055331e81d329ca4973356e`. Full package compile `32412530989 / 96566049645` succeeded on all eight owner targets. Immutable package **`9422702053`**, ZIP SHA-256 **`de9bf071ebc2a62437dbafc47f55ae4989b5bbad70d064a4f7a2d77afc21fcff`**; log `9422702677`, SHA-256 `4f2aa7268a640cbee8b137c2f63eeec63914e3d72d387bce653653fec31229e8`. Downloaded outer ZIP and all 27 internal manifest payload files reverified; all source-status evidence is clean. No generated Directional binary or benchmark executed.

M3 cumulative package count becomes **17**. Restored CP2b acceptance usage remains **1/3** until a valid TB-R4 gate; DG remains **2/2 exhausted**; stable totals remain **41 / 14 / 27**, produced-witness debt **5**. Exact next is artifact-only `M3-CP2b-TB-R4` on `9422702053 / 9fdb928fe872190b27aa6022b43608eeccf329e4`, frozen 292/292, acceptance attempt 2 of 3, then independent Review.

### Changed — M3 CP2b TB-R3 semantic review: port uniqueness key is rank-one and production-relevant; G1-G5 require the partition before the fix

- `M3-CP2b-TB-R3-SEMANTIC-REVIEW` completed as Review/planning only. No product, test, fixture, selector, or build edit; no compile, package, DG, or generated Directional runtime. Result is **Part F** of `Architecture_M3_CP2b_TB_R3_Semantic_Review_Plan.md`.
- **F1/F2 worked.** TB-R3 named the guard and locus: `DuplicateSingularityPortRepresentative; sourceEdge=(0,1); sourceFace=0; sourceVertex=4; topologyRegion=0`, with the accepted predecessor preserved at 287/287 and the gate at 288/292 as predicted.
- **The collision was reproduced by hand from the frozen fixture geometry**, not observed at runtime. Vertex-4 sector angles are face 0 **115.647°**, face 1 85.477°, face 2 93.350°, face 3 65.526°, summing to exactly 360.000° as a planar fan must. Each face's branch frame is four rays 90° apart at phase `0.862 + 0.3 * face`. Face 0's sector is **wider than the 90° branch spacing**, so it contains **two** of its own rays (raw 2 at 229.39°, raw 3 at 319.39°) while faces 1-3 contain one each. **Five incidences must collapse to `4 - 1 = 3` classes.** Both face-0 incidences are constructed with `startFace = 0` and `firstOutgoingCarrier = (0,1)`, differing **only in `branch`** — exactly the reported locus.
- **The uniqueness key is structurally rank-one.** Within a singularity's fan, `startFace` **determines** `firstOutgoingCarrier` — the fan face is a triangle, the singular vertex holds one corner, and the opposite edge is unique — so `(startFace, firstOutgoingCarrier)` carries exactly what `startFace` carries alone. It cannot express two ports passing through one face, and `FieldSingularityPortAttachment` already carries the field that would distinguish them, `branch`, which the key omits. This is not a tolerance or half-open-convention artifact: a 115.647° sector holds two 90°-spaced rays under any boundary convention.
- **The defect is production-relevant, not a fixture artifact.** The trigger is an incident sector wider than `2*pi/N`, which is ordinary on irregular meshes. The sharpest case is canonical: an interior **valence-3** vertex is exactly the `+1` cone (`valence = 4 - index`) and its three sectors average **120°**, every one wider than 90° — so the most common `+1` singularity shape in production would trip this guard. The fixture is simply the first witness non-degenerate enough to reach it.
- **What the evidence does not settle.** The gate reports the guard and locus but **not the class partition**, and with 5 incidences and 3 required classes several partitions satisfy `classes.size() == 3`. Two readings remain open and demand opposite corrections: **Reading A** — the two face-0 incidences are distinct ports, the key is too coarse, and they should be in different classes (if they are in the same class the equivalence is *also* under-merging); **Reading B** — they are one port counted twice, so incidence generation over-generates and widening the key would split one port into two behind a green gate. `classes.size() == 3` passing is evidence a count matched, not that the structure is right.
- **Corrective measures G1-G5.** **G1** — publish the partition *before* changing the rule: the full per-singularity incidence list (`fanIndex`, `startFace`, `branch`, `firstOutgoingCarrier`), the resulting class assignment, and the per-adjacency `signedLift` used to merge, emitted unconditionally. **G2** — widen the key to `(startFace, branch, firstOutgoingCarrier)`, retaining the carrier for locality even though it is currently implied. **G3** — G2 is authorized **only** together with G1 and **only if** G1 shows the two face-0 incidences in *different* classes; same class means **stop and return to Review**, because the defect is then in the equivalence or the incidence generation and widening the key would let a wrong partition reach green. **G4** — a negative pinning the widened key: two incidences agreeing in `(startFace, carrier)` but differing in `branch` must not be rejected, while three-field duplicates must be. **G5** — record the valence-3 exposure in the CB report as a named open exposure if no cheap production-shaped witness can confirm it.
- **Falsifiable prediction:** G1 names **five** incidences for the centre singularity — two on face 0 with branches one quarter turn apart, one each on faces 1, 2, 3 — and a three-class partition. The count and per-face distribution are **arithmetic predictions from the frozen geometry**; a different runtime distribution means the Review's model of `direction_in_vertex_sector` is wrong and the correction must be re-derived before proceeding.
- **Exact next is `M3-CP2b-CB-R6` then `M3-CP2b-TB-R4`** (acceptance attempt 2 of 3, frozen 292/292). Semantic surface is exactly `src/authority/FieldTransportAtlas.cpp` (G1 always, G2 only under G3) and `tests/FieldTransportAtlasTests.cpp` (G4 only, alongside G2). If G3 cannot be settled without running, **ship G1 alone** — an attempt that returns the partition is a successful attempt even with the gate still red. Frozen: no third semantic file and **no change to `ordered_incident_fan`, `direction_in_vertex_sector`, the union-find merge rule, the fan geometry, the mesh, or the field**; changing the equivalence in the same turn as the key is a stop condition because it destroys the differential between the two readings.
- **`LESSONS.md`** gains two section-3 lessons: *a uniqueness key whose fields are functionally dependent is a one-field key wearing two*, and *a matching count is not a matching structure*. Subsequent lessons renumbered; none removed or weakened.
- **`CAND-02`** narrows again, to a **named product defect** — the rank-one port uniqueness key at `src/authority/FieldTransportAtlas.cpp:511-525`. Its fixture-authority causes are runtime-discharged and its diagnosability cause is discharged by F1/F2; it stays **ACTIVE / NON-STABLE** until the partition is published and the correction proven, because the equivalence relation is not yet cleared. **`CAND-01`** remains **ACTIVE / UNADJUDICATED SEMANTIC / NON-STABLE** — six turns in, the relabel/equality/digest seam has still never executed; report it as unreached, not approached.
- No package created and no acceptance attempt consumed by this Review. M3 remains **16 packages / 3 historical rejected CP2b acceptance attempts**; restored window **1 of 3 consumed**; **DG usage 2 of 2 exhausted**. Stable accounting remains **41 / 14 / 27**; produced-witness debt **5**. CP2 remains the latest accepted runtime authority at 287/287 and CP3a remains blocked.

### Changed — M3 CP2b TB-R3 valid instrumented gate rejects 288/292 at one named representative guard

- `M3-CP2b-TB-R3` consumed exact R5 source/package `7dc188aea3d43307c8bf0688d9df8a1758548274 / 9416963557` artifact-only and executed the frozen **292/292 unique** identities. Result is **288/292**: CP2b **1/5**, accepted predecessor **287/287**. Package and materialized source postflight are byte-identical; no repository checkout, configure/build/relink/repair, source/test/fixture mutation, generated discovery, benchmark, CLI, or custom input occurred.
- All four red CP2b positives identify the same exact earliest product rejection and locus: `DuplicateSingularityPortRepresentative; sourceEdge=(0,1); sourceFace=0; sourceVertex=4; topologyRegion=0`. F1/F2 diagnostics therefore succeeded and the Part D prediction was confirmed exactly at **288/292**. The green ambiguous/incomplete negative remains reached-and-passing rather than established while the valid positive baseline rejects.
- Exact-source analysis shows the final guard fires **after** `classes.size() == expected == 3` succeeds and after one representative per class is elected; two representatives from distinct classes share `(startFace, firstOutgoingCarrier)`. This rules out the ranked H1 class-count mismatch as the earliest cause and bypasses the earlier carrier/frame/cycle hypotheses. Review must now decide whether the uniqueness key is too coarse, the branch-orbit equivalence is incomplete, representative election is wrong, or another source-supported mechanism applies. No semantic correction was made in the TB turn.
- `M3-CP2b-TB-R1-CAND-01` remains active/unadjudicated because baseline construction still masks relabel/equality/digest. `CAND-02` narrows to **ACTIVE / ARCHITECTURE-PRODUCT / NAMED-GUARD / NON-STABLE**. Accepted predecessor preservation means no stable event/recurrence is added; totals remain **41 / 14 / 27**, debt **5**.
- The first local control stopped before generated runtime because the harness used Bash's special `GROUPS` variable. Renaming it to `RUN_GROUPS` was an orchestration-only correction; the failed control consumed no attempt. Corrected harness SHA-256 `93d197608efce08001d4ecf76991bd70c45299a9a2d265434e4d0d38a8446131`; deterministic summary SHA-256 `ee208e6da3ab4df3634d51b448baf7cb7652d4c1a43d8827fa50773a4159c665`.
- The user-identified source-snapshot workflow defect is resolved: the invalid snapshot-job condition was removed and `32402429191 / 96533520462` succeeded, producing verified snapshot artifact `9418990883` (`sha256:24963071b798be6726ad16930194c17fbe48075b7d6d9071bbb1d08dec96d9c0`).
- This valid red gate completes the R5 CB -> TB pair and consumes restored-window **attempt 1 of 3**. M3 remains **16 packages**; DG usage **2/2 exhausted**. Exact next is **`M3-CP2b-TB-R3-SEMANTIC-REVIEW`**, planning only, under `Architecture_M3_CP2b_TB_R3_Semantic_Review_Plan.md`. CP3a remains blocked.
- The superseded per-turn `Architecture_M3_CP2b_R5_Code_Build_Report.md` is retired at TB closeout after its exact source/package/run/artifact facts are folded into the TB-R3 report and durable changelog. Older changelog references to that filename are historical provenance, not current-head authority.

### Changed — hard pre-read mode gate adopted; M3 CP2b CB-R5 closeout completed and TB-R3 package frozen

- The user identified that the prior CB-R5 turn violated `TOOL_USE_CONSERVATION_POLICY.md` Step 2 by beginning piecemeal connector source inspection before choosing the read mode even though the work already implied cross-file/repeated inspection. Policy commit `1c091955a088f76d342951e56367a02449f67825` makes Step 2 a **mandatory pre-read gate**: one turn-local `READ_MODE=direct|snapshot` must be selected before the first repository source/document read; three-or-more-file/checklist, cross-file, repository-wide, iterative, or materially uncertain cases require `snapshot`; starter connector reads are forbidden once the threshold is knowable; and snapshot acquisition failure must follow the explicit Step-3 fallback rather than silently downgrading to piecemeal line-range access. The handoff start checklist now repeats this requirement so future turns cannot satisfy the policy read while skipping the decision gate.
- This closeout selected `READ_MODE=snapshot` before broad repository inspection. Durable snapshot run `32398299828` at event SHA `d0c9ad6a6a1fca32bb704fb6ec2a5b8a0e7292c7` instantiated the observer while the snapshot workload was skipped. The failure is recorded as a control-plane defect in `TODO.md`; the turn used Step 3's explicit exact-file/blob fallback after bulk-download/local-fetch alternatives were unavailable. The fallback is not promoted to normal procedure.
- Review of `.github/workflows/agent-turn-cleanup.yml` found that its current implementation deletes all PR conversation and review comments. That conflicts with retained semantic-review/decision evidence and `TOOL_USE_CONSERVATION_POLICY.md` section 10, so the workflow is not used for this closeout. `TODO.md` now carries a repair item; this turn uses narrowly scoped direct deletion only for its known snapshot trigger marker.
- `M3-CP2b-CB-R5` is **COMPLETE / COMPILE-GREEN / RUNTIME-FREE / UNACCEPTED**. Exact semantic source is `7dc188aea3d43307c8bf0688d9df8a1758548274`; the authorized three-file diagnostics-only surface held. Guard-specific `FieldAtlasBuildErrorCode` values/loci and positive assertion diagnostics were added without changing guard predicates, fixture/field semantics, selectors, expected outcomes, or assertion pass/fail behavior. Exact evidence owner is `Architecture_M3_CP2b_R5_Code_Build_Report.md`.
- Mandatory exact-source pre-package compile `32396157539 / 96513418824` passed on `directional_core`, `directional_pipeline`, and `directional_surface_cell_authority_kernel_tests`; result/log artifacts `9416810310 / 9416810685`, ZIP SHA-256 `052aab767c9ffa8f6e785d6a8c17b50d8cfa6a222f70a78a22f667bdab03328f / 87a2e41a95469f2aa615f140a7642fa0e49a46aaf1bbab7e3d5684092cae511f`.
- Full owner package compile `32396542492 / 96514642447` passed all eight approved targets on the same semantic source and produced immutable package **`9416963557`**, ZIP SHA-256 **`0874e72342e0d3483d2c7a8314da63e242a810b8a0188c293a0e32d4f9fe9110`**; log `9416964086`, ZIP SHA-256 `2e4959f5da1103faf60ae8c9a7cca4a5dcd8baf568b417a7871a76eb46e32221`. Manifest/source status passed and `runtimeExecution=false`; no generated Directional test, benchmark, discovery, `ctest`, CLI, fuzzer, help/version command, or custom input executed.
- M3 cumulative package count is now **16**; historical rejected CP2b acceptance attempts remain **3**; the mandatory-review-restored window remains **0 of 3 consumed** because package creation alone is not an attempt; DG usage is **2 of 2 exhausted**. Stable accounting remains **41 / 14 / 27** and produced-witness debt **5**. `CAND-01` and `CAND-02` remain active/non-stable; R5 improves diagnosability but supplies no new runtime semantic evidence.
- Exact next is immutable artifact-only **`M3-CP2b-TB-R3`**, frozen **292/292**, on source/package `7dc188aea3d43307c8bf0688d9df8a1758548274 / 9416963557`. A valid semantic gate consumes restored-window attempt 1 of 3; it must preserve accepted predecessor **287/287**, report the exact named guard and strongest populated locus for every CP2b red, and update the regression tracker for every observed regression/candidate. Planning expectation remains **288/292**, but is not evidence. Return to Review with the result; do not patch toward green inside TB.

### Changed — M3 CP2b R5 implementation-preflight Review amends diagnostics file surface and reconciles live status

- Reviewed independent Part D against current source before mutation. The diagnosability diagnosis and F1-F5 are retained, but D.7 contained an implementation contradiction: F2 requires named `FieldAtlasBuildErrorCode` extensions while that enum is declared in `include/directional/authority/FieldTransportAtlas.h`, outside D.7's two-file freeze, and D.7 explicitly made a required third file a stop condition.
- Added **Part E** to `Architecture_M3_CP2b_Witness_Rescope_Review_Plan.md`: CB-R5 is authorized for exactly three diagnostic files — the public header for appended named error codes only, `FieldTransportAtlas.cpp` for guard-specific error+locus propagation only, and `FieldTransportAtlasTests.cpp` for actionable positive build diagnostics only. Existing error meanings/numeric values, every guard condition, fixture/field semantics, selector identities, and expected outcomes remain frozen.
- Corrected turn sequencing: exact next is **`M3-CP2b-CB-R5` Code + Build only**. A separate later `M3-CP2b-TB-R3` runs the frozen 292 gate and consumes restored-window attempt 1 of 3 only if it yields a valid semantic result. No third DG is permitted.
- Reconciled stale status in handoff, TODO, regression tracker, reorientation roadmap, and M3 plan to final DG-R4 `32380986195 / 96463857157`: **1/5**, helper cleared for all five, package/source immutable, DG usage **2/2 exhausted**, package count **15**, restored window **0/3**. `CAND-01` remains active/unadjudicated; `CAND-02` is active architecture-product with fixture-authority causes runtime-discharged. Stable accounting remains **41 / 14 / 27** and produced-witness debt **5**.
- This Review/preflight amendment changes documentation/planning only. No product/test/build-configuration edit, compile, package, Directional runtime, acceptance attempt, or DG occurred.

### Changed — M3 CP2b DG-R4 semantic review: first real product evidence; blocker is diagnosability; F1-F5 authorize one instrumented acceptance attempt

- `M3-CP2b-DG-R4-SEMANTIC-REVIEW` completed as Review/planning only. No product, test, fixture, or build edit; no compile, package, DG, or generated Directional runtime. Result is **Part D** of `Architecture_M3_CP2b_Witness_Rescope_Review_Plan.md`. Decision: **AUTHORIZE ONE ACCEPTANCE ATTEMPT, INSTRUMENTED FIRST — and do not request a third DG.**
- **R4 produced CP2b's first genuine semantic evidence about its own product.** The helper's producer-derived preconditions all hold at runtime — non-degenerate orthonormal per-face directions, mesh-owned transition orientation, independently reconstructed matching and effort agreeing with the producer, four interior transitions, centre oriented effort `2*pi`, exact centre index `+1`. **E1/E3 are runtime-discharged**: the producer-derived interior singular subset is exactly one entry, the centre vertex at `+1`. `RejectsAmbiguousOrIncompleteBranchTopology` is **green at its intended negative seam**. The Part C.8 prediction was partially confirmed — the helper clears and the fan is valid; the positives do not construct.
- **The blocking problem is diagnosability, not the failure.** All four reds fail identically: `FieldTransportAtlas::make(...)` returns false on the **valid baseline** before any intended seam — one cause, four symptoms, since every positive builds the same baseline first. The runtime cannot name the guard for two independent reasons: the tests assert only `ASSERT_TRUE(built)` and discard `built.error().code`; and `build_singularity_attachments(...)` collapses **14 distinct `return std::nullopt` sites** into the single `InvalidSingularityPortAttachment` (`src/authority/FieldTransportAtlas.cpp:1646-1648`), with `build_face_branch_frame(...)` adding **7 more**, both discarding the locus fields `FieldAtlasBuildError` already carries (`include/directional/authority/FieldTransportAtlas.h:76-84`). Fixing the tests alone would print one code covering 14 causes; **the second layer is a product defect**. The R4 report was correct to refuse to name a cause.
- **The green negative is not yet creditable.** `RejectsAmbiguousOrIncompleteBranchTopology` checks specific rejection codes, which is stronger than a bare rejection, but its discriminating power is unproven while the valid baseline also fails — nothing yet shows it separates tampered from sound input rather than rejecting both. Report it as reached-and-passing, never as an established contract, until the positives construct.
- **Ranked hypotheses for the single cause, none asserted:** **H1** port-class count mismatch (`:508`, `classes.size() != expected`) — the claim CP2b exists to make, that four branches transported around a `+1` cone yield `4 - 1 = 3` orbits, never executed, highest prior; **H2** sector/carrier disagreement (`:436-438`) coupling the half-open geometric sector test to the combinatorial interval assignment; **H3** `CycleTransportMismatch` on the boundary cycle carrying a nonzero lift (`:1503-1507`) — CP1's congruence, untested at nonzero lift, where arithmetic suggests it holds (`requiredIndexSum = 4 * chi = 4`, interior `+1`, boundary `+3`, `correction = 0`) but rests on `dual_cycles` sign conventions this Review did not exhaustively verify; **H4** branch-frame or transport construction. F1+F2 discriminate all four in a single run.
- **Corrective measures F1-F5.** **F1** — the positives must publish the build error code and locus on every `ASSERT_TRUE(built)`; mandatory, because without it the next run repeats this one. **F2** — give `build_singularity_attachments(...)` and `build_face_branch_frame(...)` distinct typed error codes with the locus fields populated, extending `FieldAtlasBuildErrorCode` and its name function; small, mechanical, and permanently improves diagnosability for CP3a, CP3b, and CP4. **F3** — do not credit the green negative as a proven contract yet. **F4** — change nothing else: no fan, field, sector predicate, union-find, or guard-logic change, because altering a guard while instrumenting it destroys the differential. **F5** — spend the acceptance attempt and **do not request a third diagnostic gate**: DG usage is 2 of 2 exhausted, the cap was authorized one turn earlier, and renegotiating it the first time it binds is precisely the failure the per-checkpoint regime replaced; the acceptance window is 0 of 3 and exists so that an instrumented red attempt is informative.
- **Exact next is `M3-CP2b-CB-R5` then `M3-CP2b-TB-R3`** (acceptance attempt 1 of 3). Semantic surface is exactly `src/authority/FieldTransportAtlas.cpp` (F2 only, no guard-logic changes) and `tests/FieldTransportAtlasTests.cpp` (F1 only, no fixture/mesh/field changes), plus the new code names. Mandatory exact-source pre-package compile; no DG available; frozen **292/292** gate. Expected result **288/292** with one named guard identical across all four positives and the predecessor at 287/287. A red that still cannot name the guard means F1/F2 were not implemented as specified — a process failure, not a semantic one. Return to Review with the evidence; do not patch toward green in the same turn.
- **`LESSONS.md`** gains two section-3 lessons: *a positive assertion over a compound builder proves nothing about which guard rejected* (with diagnosability framed as a product property, not a test convenience), and *a negative is not credited while the valid baseline also fails*. Subsequent lessons renumbered; none removed or weakened.
- **`CAND-02`** — the fixture-authority half is **runtime-discharged** by R4; the remaining architecture/product half narrows to the unidentified valid-baseline rejection plus the diagnosability defect. Keep **ACTIVE / NON-STABLE** until the cause is named. **`CAND-01`** remains **ACTIVE / UNADJUDICATED SEMANTIC / NON-STABLE** — R4 did not reach the relabel/equality/digest seam, which five turns in has still never executed.
- No package created and no acceptance attempt consumed by this Review. M3 remains **15 packages / 3 historical rejected CP2b acceptance attempts**; restored window **0 of 3**; **DG usage 2 of 2 exhausted**. Stable accounting remains **41 / 14 / 27**; produced-witness debt **5**. CP3a remains blocked.

### Changed — M3 CP2b R4 reconciles boundary singularity aliases, aligns CP2 range, and creates immutable second-DG package

- `M3-CP2b-CB-R4` completed as Code + Build only under Part C of `Architecture_M3_CP2b_Witness_Rescope_Review_Plan.md`. Exact semantic source is `93f55536727dbf76504aa29f7835edc8cebaee0c`; semantic diff is exactly `src/authority/FieldTransportAtlas.cpp` and `tests/FieldTransportAtlasTests.cpp`. Apply run/job `32364392476 / 96410650337`; no generated Directional runtime.
- **E1/E2 product correction:** A1 reconciles aliased legacy boundary-vertex singularity entries against the already-authoritative typed `FieldCycleKind::BoundaryLoop` witness before excluding them from interior CP2b singularity facts, rejecting disagreement as `SingularityMismatch`; `build_singularity_attachments(...)` now adopts accepted CP2's `3 <= expected <= 6` admissible range rather than a divergent CP2b-only range.
- **E3/E4 test correction:** the skew producer-derived helper asserts the source-topology-derived interior singularity subset and checks the centre entry against its independently reconstructed exact index rather than dictating global producer cardinality; a boundary-alias mutation negative pins E1's reconcile-before-drop contract.
- Mandatory separate exact-source pre-package compile `32364729385 / 96411669497` passed on `directional_core`, `directional_pipeline`, and `directional_surface_cell_authority_kernel_tests`. Result/log `9404863121 / 9404863529` have ZIP SHA-256 `c34b0dd0b4e80cc0cac5e6efda6585873a6f8fd4685128c6ee95417b17a0541f / c9018b7129e8a5fff69cc3454c0921bc4b741ba131e01bd3768a4c39000c1c9e`; `runtimeExecution=false`.
- Full owner package compile `32365047582 / 96412634149` passed and produced immutable package **`9404970614`**, outer ZIP SHA-256 **`e0d93bf06eea1cd27cc82a41962346c845aa0379b4a88c3f53ea7a3bebba7476`**. Package log `9404971153` has ZIP SHA-256 `b031792dfb01ddbd11ff3b3024ed1d6939ad5089155091007e12b956f1e906bb`. Source status and recursive manifest passed; all eight approved owner targets compiled; `runtimeExecution=false`.
- Exact evidence owner: `Architecture_M3_CP2b_R4_Code_Build_Report.md`. Package creation alone consumes no acceptance attempt. M3 is now **15 packages / 3 historical rejected CP2b acceptance attempts**; restored window **0 of 3**; DG usage remains **1 of 2** until the second diagnostic executes; stable accounting **41 / 14 / 27**; produced-witness debt **5**.
- `CAND-01` remains ACTIVE / UNADJUDICATED SEMANTIC / NON-STABLE. `CAND-02` remains ACTIVE / NON-STABLE; fixture-authority subcauses are corrected and the architecture/product correction awaits runtime evidence.
- **Exact next is the second and final `M3-CP2b-DG`** against package `9404970614` unchanged, executing exactly the five frozen CP2b identities. Green DG makes the same package eligible for a separate `M3-CP2b-TB-R3` 292/292 acceptance turn; helper-precondition red stops CP2b for explicit user direction; genuine branch-topology red returns to independent Review.

### Changed — M3 CP2b witness rescope review: RESCOPE WITHIN CP2b; defect located in the product; E1-E6 replace D1-D5

- `M3-CP2b-WITNESS-RESCOPE-REVIEW` completed as Review/planning only. No product, test, fixture, or build edit; no compile, package, DG, or generated Directional runtime. Result is **Part C** of `Architecture_M3_CP2b_Witness_Rescope_Review_Plan.md`. Decision is the plan's required output **option 1 — RESCOPE WITHIN CP2b**. No new checkpoint and no M3 ownership amendment.
- **The witness family is kept; the defect is in the product.** A1 already owns boundary-loop index correctly as a typed `FieldCycleKind::BoundaryLoop` witness carrying `turningLift`, recorded in `witness.boundaryCycles` and reconciled under an enforced Poincaré-Hopf check (`src/authority/FieldTransportAtlas.cpp:1489-1508`). Separately `:1194-1206` ingests **every** `singularCycles` entry as a distinct vertex-keyed `FieldSingularityFact`, and `vertex2cycle` (`src/geometry/MeshTopology.cpp:282-287`) maps every boundary vertex of a loop to the **same** cycle row — so one boundary-loop index arrives as N aliased per-vertex facts. That is a second owner of a quantity A1 already owns.
- **R1 settled from source.** `singularCycles` is normatively a list of singular **vertices** despite the member name `singLocalCycles`; the mapping is faithful for interior vertices and aliased for boundary vertices. The aliasing is expected inherited behaviour of the accepted many-to-one cycle basis, not an upstream defect — it becomes a defect only where a consumer treats each entry as an independent semantic singularity.
- **R2 settled from CP2b's own code.** `ordered_incident_fan(...)` (`:311-361`) requires a closed cyclic fan — three or more incident faces and a walk returning to its start — so a boundary vertex can never have port attachments built. Boundary singularities are structurally not CP2b inputs.
- **Correction to the previous D3, recorded rather than silently replaced:** filtering only the fixture assertion does **not** work. `singularCycles` would still carry five entries, A1 would still ingest all five, and `build_singularity_attachments` would still return `nullopt` on the first boundary vertex, failing the whole atlas build. D3 must be paired with the product change.
- **Latent production hazard identified.** `build_singularity_attachments` aborts the entire atlas build on any non-closed fan, and A1 is a hard production gate; production populates `singularCycles` whenever `computeMatching` is set (`principal_matching` calls `effort_to_indices` at `src/fields/FieldMatching.cpp:130`; `finalize_cross_field_result` copies it at `src/fields/CrossField.cpp:100-107`). The first production mesh with a nonzero boundary-loop index would fail A1 outright under CP2b's current code. **Honest limit:** TB-R2 kept the predecessor at 287/287 with this code present, so the path is evidently not reached by today's fixtures; the Review did not determine why and does **not** assert a live production defect — but that green is evidence the path was not reached, not that it is correct.
- **Second product defect found in the same function.** `build_singularity_attachments` admits index numerator `[1, 3]` (`:414-417`) while accepted CP2's `canonical_field_aligned_candidate` requires `[-2, 1]` (`src/geometry/SurfaceCellTracing.cpp:383-390`). The two accepted stages disagree in **both** directions: a valid index `-1` singularity is accepted by CP2 and rejected by CP2b. Neither range has ever been exercised because no accepted fixture carried a nonzero index.
- **Corrective measures E1-E6 supersede D1-D5.** **E1** — A1 ingests only interior-vertex singular entries and **reconciles rather than silently drops** the rest: each boundary entry must equal the `turningLift` of its owning `BoundaryLoop` witness, disagreement rejected as `SingularityMismatch`. **E2** — adopt the accepted CP2 index range `3 <= expected <= 6`; do not invent a third. **E3** — the fixture asserts the interior subset **derived**: filter `isBoundaryVertex(v) == 0`, require one entry at `centerVertex` with index equal to the `exactIndex` already computed at `:1691-1696`, with no hard-coded cardinality. **E4** — add a negative pinning E1, so the reconciliation is falsifiable rather than an unproven filter. **E5** — no closed-mesh witness this attempt; Poincaré-Hopf forbids a lone `+1` at `N = 4` on a closed surface, so the cheapest closed witness is a torus `+1 / -1` pair, recorded as additive follow-on once E2 admits negatives. **E6** — record in the CB report whether production meshes can carry a nonzero boundary-loop index, so the hazard is answered rather than resolved by accident.
- **Witness alternatives evaluated (R3).** Closed-manifold witness **rejected as the primary fix** — it hides the defect, leaves the hazard live, and is not cheap. Open witness with architecture-owned boundary semantics **selected**. Produced-witness-from-accepted-path **already achieved by C1** and retained. The five frozen CP2b identities remain valid unchanged, and `CAND-01` becomes reachable for the first time.
- **Exact next turn is `M3-CP2b-CB-R4`**, Code + Build, semantic surface exactly `src/authority/FieldTransportAtlas.cpp` (E1, E2) and `tests/FieldTransportAtlasTests.cpp` (E3, E4), with the mandatory exact-source pre-package compile, then the **second DG (2 of 2)**. Green DG means submitting that exact package to `M3-CP2b-TB-R3` at 292/292 as one attempt. A fourth consecutive helper-precondition failure escalates to the plan's option 3 — STOP CP2b with explicit user direction — rather than another rescope. A red at a genuine branch-topology seam is CP2b's first real semantic evidence and returns to Review rather than being patched toward green.
- **`LESSONS.md`** gains two section-4 lessons: *a legacy representation that aliases one fact across many keys must be collapsed at the typing boundary, not carried through it* (with reconcile-before-discard), and *two stages that validate the same quantity must share one admissible range*. Subsequent lessons renumbered; none removed or weakened.
- **`CAND-02`** remains ACTIVE / NON-STABLE and is now **split by cause**: the fixture-authority half is closed by C1 and E3, the remainder re-classified as architecture/product (A1's duplicate ownership plus the index-range divergence). **`CAND-01`** remains ACTIVE / UNADJUDICATED SEMANTIC / NON-STABLE — reviewed by source only, not runtime-accepted.
- No package created, no acceptance attempt consumed, no DG consumed. M3 remains **14 packages / 3 historical rejected CP2b acceptance attempts**; restored window **0 of 3**; **DG usage 1 of 2**. Stable accounting remains **41 / 14 / 27**; produced-witness debt **5**. CP3a remains blocked.

### Changed — M3 CP2b DG reviewed; boundary-vertex index aliasing identified; corrective measures D1-D5 replace C1-C5

- `M3-CP2b-DG` review completed as Review/planning only. No product, test, fixture, or build edit; no compile, package, or generated Directional runtime. Findings amend `Architecture_M3_CP2b_Witness_Rescope_Review_Plan.md` as its **Part B**, which pre-answers that plan's R1 from source.
- **The diagnostic gate did its job.** It isolated the failing seam for the cost of a package instead of an acceptance attempt and named it exactly (`tests/FieldTransportAtlasTests.cpp:1699`). Under the previous regime this would have been the fourth consumed attempt.
- **C1 is discharged, proven by the DG.** Every assertion ahead of `:1699` passed — producer-derived transition agreement (`:1662-1663`), four interior transitions with nonzero matching (`:1670-1673`), signed centre-cycle oriented effort `2*pi` (`:1695`), and independently reconstructed centre index `+1` (`:1696`). The mesh-owned transition-orientation defect that killed attempts 1-3 is resolved and must not be reopened.
- **Root cause verified, and it is not a cardinality assumption.** `effort_to_indices(CartesianField&)` (`src/fields/FieldMatching.cpp:28-56`) iterates **per vertex** over `local2Cycle`, and `vertex2cycle` (`src/geometry/MeshTopology.cpp:282-287`) maps **every boundary vertex of a loop to the same cycle row**. A single nonzero boundary-loop index is therefore emitted once per boundary vertex — four aliased copies of one fact, not four singularities. Poincaré-Hopf at `N = 4` on a disc (`chi = 1`) fixes total index `4`; the centre carries `+1`, so the boundary loop carries `+3`, giving `1 + 4 = 5` exactly as the producer returned. **`singularCycles.size() == 1` is unsatisfiable by construction on any bounded mesh with a nonzero interior index**, not merely wrong about this fan.
- **Product question exposed.** `src/authority/FieldTransportAtlas.cpp:1194-1206` ingests every `singularCycles` entry as a distinct `FieldSingularityFact` keyed by vertex, so the four aliased boundary vertices become four singularities; accepted CP2 then computes `expectedValence = 4 - indexNumerator` and rejects unless `3 <= valence <= 6` (`src/geometry/SurfaceCellTracing.cpp:383-390`), so a boundary-loop index of `+3` yields valence `1` and is rejected. **That path has never executed** — every prior A1 and CP2 fixture used the planar zero-transport field where all indices are zero and no singularity fact is created. Third form of the degenerate-fixture blind spot.
- **Corrective measures D1-D5 supersede the mandatory review's C1-C5.** C1/C3/C4 discharged, C2 withdrawn, C5 superseded. **D1** — do not patch the count to `5`; it hard-codes a `vertex2cycle` aliasing artifact and is not authorized. **D2** — decide and record CP2b's singularity domain, recommendation interior-only, justified against `DESIGN.md` rather than by what makes the fixture pass. **D3** — assert the interior subset **derived**: filter `isBoundaryVertex(v) == 0`, require one entry at `centerVertex` with index equal to the `exactIndex` the helper already computes at `:1691-1696`, adding no new hard-coded number. **D4** — the product question is in scope: A1 collapses or omits boundary-loop facts, or CP2/CP2b classify rather than reject boundary singularities, or it is a tracked defect with a named owning checkpoint — not the last option by default because it is cheapest. **D5** — a closed-mesh witness is not the easy escape, since Poincaré-Hopf forbids a lone `+1` at `N = 4` on a closed surface and the cheapest closed witness is a `+1 / -1` pair on a torus.
- **Updated falsifiable prediction:** with D2 recorded and D3 applied, all five identities clear the shared helper and resolve on branch-frame, pairing, port-attachment, relabel/digest, or negative-guard grounds, producing the first genuinely semantic evidence about `FieldBranchTopology`. Verify with the **second DG (usage 1 of 2)** before spending an acceptance attempt; a third consecutive helper-precondition failure means CP2b's contract, not its fixture, must be rescoped.
- Still unproven and standing behind the fix: `CAND-01` branch-lift normalization, the never-reached `RejectsAmbiguousOrIncompleteBranchTopology` rejection seam, and the never-exercised independence of `IndependentOracleRejectsBranchPairingOrPortAttachmentTamper`.
- **`LESSONS.md`** gains one lesson in section 2 — *a producer's output shape is part of the convention a fixture must consume, not just its values* — recording that CP2b derived the values correctly and still failed by dictating cardinality. Subsequent lessons renumbered; none removed or weakened. All cross-document references to lessons were converted from numbers to **section plus short title**, and the file now states that rule, because numeric citations rot silently whenever a lesson is inserted.
- No acceptance attempt was consumed. M3 remains **14 packages / 3 historical rejected CP2b acceptance attempts**; restored window **0 of 3**; **DG usage 1 of 2**. Stable accounting remains **41 / 14 / 27**; produced-witness debt **5**. `CAND-02` is refined again, from the resolved orientation defect to the boundary-loop index aliasing; `CAND-01` remains active/unadjudicated. CP3a remains blocked. Exact next is `M3-CP2b-WITNESS-RESCOPE-REVIEW`.

### Changed — M3 CP2b R3 diagnostic gate exposes open-witness singularity-domain mismatch and forces rescope

- Attempt-free `M3-CP2b-DG` `32344594021 / 96350536107` consumed immutable package/source `9395219896 / c608f77588a43c388bed81295d6cde0977b1c8cd` directly, with no rebuild, relink, repair, checkout, discovery, benchmark, or source/test/fixture/package mutation. Result/log artifacts `9397542956 / 9397543470` have ZIP SHA-256 `8d13044700113f84f19da4136e3ff183664cea2ba4efeceaf1979cd98e5742ab / 4f5c1f2c54ff8d4add5b03a4865135dbac62ff3a994103611c0b743e7a499214`.
- The frozen CP2b selector reconciled exactly **5 required / 5 executed / 5 unique**, no missing/extras/duplicates, and was **0/5**. This was new-contract-only diagnostic evidence: predecessor 287 was not executed, acceptance=false, attemptConsumed=false.
- All five identities fail at `tests/FieldTransportAtlasTests.cpp:1699`: producer `field.singularCycles.size()` is 5, while the open-fan fixture asserted 1. Crucially, this assertion is after the C1 producer-derived transition checks, nonzero matching, signed center-cycle `2*pi` effort, and independent center index `+1`; C1 therefore fixes the former mesh-orientation defect and proves the intended center index before exposing the next witness assumption.
- Source reconstruction shows `dual_cycles(...)` maps boundary vertices to the aggregate boundary cycle and `effort_to_indices(CartesianField&)` emits each local vertex whose mapped cycle index is nonzero. The fixture incorrectly equated one intended interior index-one center with a globally singleton producer singularity list. `FieldTransportAtlas` later consumes every published singular entry while singularity-port construction expects a closed incident fan, so boundary handling is an architecture/witness-domain question, not a size-assertion patch.
- `M3-CP2b-TB-R1-CAND-01` remains active/unadjudicated because the relabel/equality/digest seam is still masked. `M3-CP2b-TB-R1-CAND-02` remains active/persisted; its old orientation sub-cause is resolved and its active cause is refined to producer singularity-domain/cardinality mismatch on the open witness. Stable totals remain **41 / 14 / 27** and debt **5**.
- The binding mandatory-review B.5 prediction fired: a repeat helper-precondition failure requires **decision 2 — rescope**. Exact next is Review-only `M3-CP2b-WITNESS-RESCOPE-REVIEW` under `Architecture_M3_CP2b_Witness_Rescope_Review_Plan.md`. No second DG, `M3-CP2b-TB-R3`, successor package, fixture/product patch, or CP3a work is authorized before Review.
- M3 remains **14 packages / 3 historical rejected CP2b acceptance attempts**; restored acceptance window remains **0 of 3 consumed**; DG usage is **1 of 2**.

### Changed — M3 CP2b R3 rebuilds the skew singularity fixture from accepted field producers and packages exact source

- `M3-CP2b-CB-R3` completed as Code + Build only. Exact semantic source is `c608f77588a43c388bed81295d6cde0977b1c8cd`; the semantic diff is only `tests/FieldTransportAtlasTests.cpp`; `src/authority/FieldTransportAtlas.cpp` remained frozen and no product/authority implementation file changed.
- The mandatory-review C1 strategy replaced hand-authored matching/effort/singularity data. The skew witness now authors only non-degenerate per-face cross directions, constructs the accepted raw field, derives `CrossFieldResult` through `finalize_cross_field_result(..., false, true)`, independently checks mesh-owned transition orientation/measurements, reconstructs signed center-cycle effort from the bundle cycle row, and asserts a producer-derived center index of `+1` before the five CP2b semantic contracts run. The negative fixture is rebuilt from that valid producer-derived precondition before mutation.
- Turn-specific compile caller schema validation `32337439375 / 96329607611` passed; result/log artifacts `9395126374 / 9395126830`, ZIP SHA-256 `8f149eefc6751886d7cd391b4023ca3b4a39577928659be600d1b55132e24cf3 / 814331c33189be34e4dd8febb44357c59ece92c5ce9ccaa081fa1eb55d6443a6`.
- Mandatory separate pre-package compile `32337587239 / 96330016806` passed all eight owning targets on exact source `c608f77588a43c388bed81295d6cde0977b1c8cd`; result/log artifacts `9395192887 / 9395193126`, ZIP SHA-256 `4bdd8a06cdd95e7f28b3a12277844c887624af273b701d6e4199543388ac66a6 / e0e4bc7905b35c40d874063c0c9d22dee46900e233036dce4527390e06e01826`.
- Immutable package compile `32337694391 / 96330313932` passed the same eight targets on the same exact semantic source. Package **`9395219896`** has ZIP SHA-256 **`45657120b692a937034c26d218871c7729d392cbfff95873da4ac323a4be11af`**; activity log `9395220309` has ZIP SHA-256 `da8776c6f2b634bff16a09cbdd4d5b6a5b92df52ee3d5e3c843d4db738d5b149`. Packaged checksums and source status are clean; `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command, or custom mesh input ran.
- All temporary schema/compile callers, markers, and payloads were retired; exactly the five durable workflows remain and temporary trigger/payload directories are empty. No temporary branch was used.
- No runtime evidence exists yet, so stable accounting remains **41 / 14 / 27**, produced-witness debt **5**, CAND-01 remains active/unadjudicated, and CAND-02 remains active/persisted. M3 cumulative package count is now **14**; restored CP2b acceptance attempts remain **0 of 3 consumed** because package creation alone is not an attempt.
- Exact next is attempt-free `M3-CP2b-DG` on package `9395219896`, executing only the five frozen CP2b identities without rebuilding. Green -> same package immutable `M3-CP2b-TB-R3` 292-identity acceptance gate; red -> bounded correction/repackage with no acceptance attempt consumed. CP3a remains blocked.

### Changed — attempt redefined as a CB+TB pair; new-contract-only diagnostic gate authorized

Both changes are user-authorized amendments to the M3-M8 attempt regime. Normative statement:
`REORIENTATION_PLAN.md` section 5 item 4; `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md`
section 1.1.3 mirrors it; `Architecture_M3_CP2b_Mandatory_Review_Plan.md` section B.8 records the
authorization and applies it to CP2b.

- **An attempt is now one complete Code + Build -> immutable Test + Benchmark pair.** The pair is the unit. Neither half is an attempt on its own — there is no "CB attempt" or "TB attempt", and a CB and its TB are never counted as two. Consumption moves from package creation to **pair completion**: the attempt is spent when that CB's immutable package produces a valid gate result under its TB. Consequences made explicit: a created-but-unsubmitted package has consumed nothing; a harness re-run against the same package is not a second attempt; and a pair whose TB yields no valid gate result (infrastructure or harness failure rather than a semantic outcome) consumes nothing.
- **Anti-accumulation rule:** a checkpoint may hold **at most one un-submitted package at a time**. Creating a second before the first reaches its TB is a stop condition returning to Review, so the pair definition cannot become a way to bank untested packages.
- **New-contract-only diagnostic gates (`<checkpoint>-DG`) are authorized and attempt-free.** A DG executes **only** the checkpoint's own new identities and **must not** execute the frozen predecessor selector, making it structurally incapable of producing an acceptance claim. It runs artifact-only against a real immutable package under the same immutability flags as any TB, with byte-identical package postflight.
- **The same package may serve a DG and then its acceptance TB** — executing packaged binaries does not mutate the package. A green DG followed by that package's acceptance TB is therefore **one attempt in total**; de-risking is free. A red DG means correcting the fixture, which changes source and requires a new package with a fresh mandatory pre-package compile, at **no attempt cost**.
- **What a DG proves.** One question only: *did these identities reach their intended semantic seams?* A green DG means those identities passed **in isolation**; it is **not acceptance**, because the predecessor selector was never run and predecessor safety is therefore unproven. No checkpoint may be advanced, closed, or unblocked on DG evidence. The result **must name the seam each red identity reached**, so the gate discharges its purpose rather than reproducing an opaque failure.
- **Cap: 2 diagnostic gates per checkpoint per attempt window**, resetting with the window when a mandatory review restores attempts; each must be followed by an acceptance attempt or a Review, so DG runs cannot chain indefinitely. Diagnostic packages count toward the reported cumulative package total — deliberate, since packages are cheap relative to semantic evidence.
- **Reporting changed:** attempts and packages are now separate numbers and must be reported separately, since under the pair definition they are no longer the same quantity. Current M3 cost is **13 packages / 3 CP2b attempts**, reported only; CP2b's window is restored to **0 of 3** with both diagnostic gates unused.
- **Rationale.** A Code + Build turn is runtime-free by rule, so without a DG a new fixture's first execution is always inside an attempt-consuming TB. The project already forbade a package attempt being the first *compile* of new code; there was no counterpart for the first *execution* of a new fixture. That gap cost M3-CP2b its entire 3-attempt budget, all three dying in fixture construction upstream of any semantic seam and leaving `CAND-01` unadjudicated.
- **Applied to `M3-CP2b-CB-R3`:** run `M3-CP2b-DG` over the five CP2b identities against the CB-R3 package before the acceptance gate; green means submit that exact package to `M3-CP2b-TB-R3` as attempt 1, red means re-package at no attempt cost. After three consecutive fixture-precondition failures, going straight to the acceptance gate is a deliberate choice to risk the attempt and is not recommended. Only the full immutable **292/292** gate accepts CP2b, and CP3a may not begin on diagnostic evidence.
- **`LESSONS.md`** gains two lessons in section 8 — 57 (an attempt is a CB->TB pair, never either half) and 58 (a package attempt must not be the first *execution* of a new fixture; the DG's purpose and its limits) — and lesson 56 now points at the DG as the control for attempts lost to test scaffolding. Prior section-8 lessons renumbered 59-62; no lesson was removed or weakened.
- Everything else is unchanged: the mandatory separate exact-source pre-package compile, package immutability, artifact-only acceptance TB against the **full** frozen selector, "compile-green is not acceptance", the prohibition on shrinking a frozen selector, and the prohibition on merging independent semantic checkpoints to save an attempt.

### Changed — M3 CP2b mandatory review authorizes a bounded fourth attempt; durable lessons consolidated into LESSONS.md

- `M3-CP2b-MANDATORY-REVIEW` completed as Review/planning only. No product, test, fixture, or build edit; no compile, package, or generated Directional runtime. Result recorded as Part B of `Architecture_M3_CP2b_Mandatory_Review_Plan.md`. **Decision: AUTHORIZE BOUNDED FOURTH ATTEMPT**, ratchet satisfied, CP2b restored to a fresh 3-attempt window, conditional on a mandatory fixture-strategy change.
- **Root cause confirmed from source and sharpened.** `make_skew_index_one_singularity_field(...)` hard-codes four ordered face pairs including `3 -> 0` (`tests/FieldTransportAtlasTests.cpp:1634-1639`) and requires an exact `(firstFace, secondFace)` match (`:1641-1646`), while `make_zero_transport_field` publishes each transition with mesh-owned `EF(e,0) / EF(e,1)` orientation (`:117-121`), so the closing seam is never populated. The sharper statement: the helper **assigns** by hard-coded face pair but **verifies** by the signed cycle-row coefficient (`:1671-1690`) — two orientation authorities inside one helper, violating the pre-existing durable lesson that the signed cycle row is the one orientation authority.
- **Primary finding: three attempts bought zero semantic evidence.** All five CP2b identities died upstream of the seams they exist to exercise; `M3-CP2b-TB-R1-CAND-01` (the `[0,3]` branch-lift normalization) is still unadjudicated after three attempts; `FieldBranchTopology`, branch frames, boundary pairings, and port attachments have never executed against a valid non-degenerate witness. The Review therefore treats the fixture strategy, not the product, as the fourth attempt's primary deliverable. CP2b needs a non-degenerate index-1 singular cross field and no accepted M3 fixture provides one — the atlas tests hold only `make_zero_transport_field` and the failing skew helper, and the accepted CP1 A1 gate runs on zero transport.
- **Binding corrective measures.** C1 (preferred): author only the per-face directions and let the accepted producers derive matching/effort/index via `finalize_cross_field_result(...)` (`include/directional/fields/CrossField.h:82`, calling `principal_matching` at `src/fields/CrossField.cpp:61`), then assert the center-cycle index is 1 rather than dictating the values that produce it. C2 (bounded fallback): locate the closing adjacency topologically, read the published direction from the transition itself, and take the sign from the cycle coefficient `s_e` the verification half already uses — **the naive unordered-lookup fix keeping `matching = 1, effort = 2*pi - 3.6` yields index −1 when `s_e = −1` and is explicitly not authorized**. C3: one orientation authority in the helper. C4: `ASSERT_` on helper preconditions so a fixture defect reports at its own line. C5: `src/authority/FieldTransportAtlas.cpp` frozen this attempt, since CAND-01 cannot be adjudicated without a valid witness.
- **Falsifiable prediction frozen:** all five identities reach their intended semantic seams and pass or fail on branch-topology grounds rather than fixture preconditions. A repeat helper-precondition failure is decisive evidence that the witness design is wrong and forces decision 2 (rescope) rather than a fifth attempt.
- Recorded as unproven and standing behind the fix: CAND-01, the never-reached `RejectsAmbiguousOrIncompleteBranchTopology` rejection seam, and the never-exercised independence of `IndependentOracleRejectsBranchPairingOrPortAttachmentTamper`.
- **Workflow amendment recommended but NOT authorized** (Part B section B.8): a Code + Build turn is runtime-free, so a new fixture's first execution is always inside an attempt-consuming immutable TB. The project forbids a package being the first *compile* of new code but has no equivalent for the first *execution* of a new fixture — the gap that cost CP2b three attempts. Proposal is a new-contract-only diagnostic gate that consumes no attempt, never touches the frozen predecessor selector, never accepts anything, capped at two per checkpoint. `M3-CP2b-CB-R3` proceeds under current rules regardless.
- **Durable lessons consolidated.** By explicit user authorization the handoff's "Resume-critical lessons" section moved to new durable `.agents/Directional/LESSONS.md`: 61 entries deduplicated to 60 across eight sections — evidence and acceptance; fixtures and witnesses; negatives and oracles; single authority and representation; cross-field/cycle/orientation conventions; gate and criterion authoring; budget/attempts/stop rules; build/package/workflow mechanics. Merges combined duplicate claims only; no distinct claim was dropped and provenance was kept where it carries the evidence. The handoff section remains present as a durable pointer with a section index. `RETENTION_POLICY.md` lists `LESSONS.md` in the durable set and records that new lessons go there, never back into the handoff.
- **New mandatory start-of-turn step 3:** review `LESSONS.md` in full and re-read the governing sections before authoring any plan, fixture, gate criterion, or corrective measure — not satisfied by having read it in a prior turn. Prior steps 3-7 renumbered to 4-8.
- CP2 remains the accepted runtime authority at **287/287**; CP2b remains unaccepted; stable accounting remains **41 / 14 / 27** and produced-witness debt **5**; M3 cumulative package count remains **13**, reported only. CP3a attempt 1 of 3 remains unconsumed and blocked. Exact next is `M3-CP2b-CB-R3`, attempt 1 of 3 in the restored window.

### Changed — M3 CP2b immutable attempt 3 rejected at 287/292; mandatory Review activated

- Authoritative `M3-CP2b-TB-R2` `32331037070 / 96311550091` consumed exact immutable source/package `90c737e11c340061dd0167eaf59fec66afa0c8ba / 9392366234` and executed **292/292 identities exactly once**. Gate is **287/292**: CP2b **0/5** and accepted predecessor **287/287**. Result/log artifacts `9393063460 / 9393063700` have ZIP SHA-256 `04e9e2f58ccab65a66faf8e307f7a48fdfda32b378a1ebac86967ae22e4cdbf3 / b25aec3f833ae437a067bb0bb4d000ffb34529d71b2e236c85cf5e857e49d560`.
- Exact-once reconciliation has no missing, extra, expected-duplicate, or executed-duplicate identity. Package/materialized-source pre/post inventories are byte-identical; checkout/rebuild/relink/repair/source/test/fixture mutation/generated discovery/benchmark execution/package mutation/materialized-source mutation are all false.
- All five reds share one first-acceptance fixture-precondition cause: R2 hard-codes the nonzero closing transition as `3 -> 0`, but transition orientation is mesh-owned and that shared edge is published in reverse. The closing seam is never populated, leaving matching sum `0`, oriented effort `3.6`, and independent index `0.57295779513082257`. `M3-CP2b-TB-R1-CAND-02` remains active/persisted with this refined orientation cause. `M3-CP2b-TB-R1-CAND-01` remains active/unadjudicated because the fixture fails before branch-transport relabel equality/digest is reached.
- No accepted predecessor identity regressed; stable totals remain **41 / 14 / 27**, produced-witness debt **5**. CP2 remains latest accepted runtime authority at **287/287**.
- CP2b attempts **1-3 of 3 are consumed/rejected**; M3 package cost remains **13**, reported only. The third red TB activates the mandatory-review ratchet. Exact next is `M3-CP2b-MANDATORY-REVIEW` under `Architecture_M3_CP2b_Mandatory_Review_Plan.md`; no fourth package or CP3a work is authorized before Review.

### Changed — M3 CP2b R2 Code + Build creates immutable attempt-3 package

- `M3-CP2b-CB-R2` changed exactly `FieldTransportAtlas.cpp` + `FieldTransportAtlasTests.cpp`. Semantic commit `f46d48143b45c94f6f2956733ad90e54de9933c5`; clean exact package source `90c737e11c340061dd0167eaf59fec66afa0c8ba`. Nested CP2b integer lift is now the canonical Z4 representative; the skew index-1 field is independently self-consistent before atlas/tamper assertions.
- Mandatory prepackage compile `32328724472 / 96305097736` passed all eight owner targets. Result/log `9392291968 / 9392292196`, ZIP SHA-256 `37f8449acbad9929948da6e44d59e4a34e6d85da7bc9243c43291ed4ad2773c9 / 28d7af705ae90c7d924760c51a826a3190917381f29c8b6e5c35f241a07e95c8`; manifest/source archive SHA-256 `ab3d2321c58a87246d759caa709ba95701cd1f2bdaeb692df2ba6ce1f3576795 / b30bf000ee9a2ed40f1a2f5b5ea038a613e3433fe16d5194b633778f1ca8a548`; `runtimeExecution=false`.
- Immutable attempt-3 package `9392366234` was created by `32328961263 / 96305777687`; package/log ZIP SHA-256 `249230199de898e7be2053050e10894e20c557fc9dccd12c3b930e4d95d0f36d / 23ad6a9323f365d241a2f72bb48bda7f9279c8a813a805cda6316eefcbf965d4`. Package `SHA256SUMS` / embedded source archive SHA-256 are `2ecd1726d06430d41d369b60fe4f2e96cc0d745f5c133bb2cc9b88ac138c5799 / b30bf000ee9a2ed40f1a2f5b5ea038a613e3433fe16d5194b633778f1ca8a548`; all source-status snapshots and recursive manifest verification are clean.
- Package creation consumes CP2b attempt **3 of 3** and raises M3 cumulative package cost to **13**, reported only. No generated runtime occurred, so R1 CAND-01/CAND-02 remain active pending TB-R2; stable totals remain **41 / 14 / 27**, debt **5**.
- Exact next is immutable `M3-CP2b-TB-R2` on unchanged **292** identities / selector SHA-256 `fc6bfc2b90c8a39512ee89e73106f2592fd4664aa90929c8c970e3ef0455245e`. A red TB-R2 forces mandatory independent Review before any fourth package.

### Changed — M3 CP2b R1 immutable attempt 2 rejected at 289/292; bounded R2 attempt 3 planned

- Authoritative `M3-CP2b-TB-R1` `32324880480 / 96294021816` consumed exact immutable source/package `bcf45fe28468b950987d52119548e06f411e4f19 / 9390283890` and executed **292/292 identities exactly once**. Gate is **289/292**: CP2b **2/5**, accepted CP2 **6/6**, accepted CP1 A1 **6/6**, retained M2 **41/41**, retained M1 **234/234** including producer **138/138**. Exact reds are `FieldTransportAtlas.BranchTopologyIsInvariantToEquivalentZ4Relabeling`, `FieldTransportAtlas.IndependentOracleRejectsBranchPairingOrPortAttachmentTamper`, and `FieldTransportAtlas.PublishesCanonicalBranchFramesAndBoundaryPairings`.
- Result/log artifacts `9391045438 / 9391045681` have ZIP SHA-256 `7dd9ea3f92a5e4a8233a01688d6d8c6a9013d688e8d14078980f577b5c702e6e / 610155a4e60970d6ac1b931174937072bc14687d186c0b0c3b0a70cb281816ff`. Package/materialized-source pre/post inventories are byte-identical; checkout/rebuild/relink/repair/source/test/fixture mutation/generated discovery/benchmark execution/package mutation/materialized-source mutation are all false.
- `PR8-R040 / M3-CP2b-R001` and `PR8-R041 / M3-CP2b-R002` are **RESOLVED**: the complete accepted predecessor set is restored to **287/287**, and the new three-attachment positive is green. Historical stable totals remain **41 / 14 / 27**, debt **5**.
- Remaining first-acceptance evidence is split into two non-stable candidates. `M3-CP2b-TB-R1-CAND-01` (`RP-05`) is an unnormalized CP2b integer branch lift that changes by `4*k` under equivalent Z4 gauge relabel while QuarterTurn stays equal. `M3-CP2b-TB-R1-CAND-02` (`RP-02`) is the skew index-1 fixture's manually injected matching/effort being inconsistent with its identical coplanar face directions, so independent baseline validation fails before two intended tamper seams.
- CP2b attempts **1-2 of 3 are consumed/rejected**; M3 package cost remains **12**, reported only. Exact next is `M3-CP2b-CB-R2`, attempt **3 of 3**, frozen to `FieldTransportAtlas.cpp` + `FieldTransportAtlasTests.cpp`. A red attempt-3 immutable TB would force mandatory independent Review before a fourth package.

### Changed — M3 CP2b R1 Code + Build creates immutable attempt-2 package

- `M3-CP2b-CB-R1` repaired the two attempt-1 root causes in exactly `FieldTransportAtlas.cpp` and `FieldTransportAtlasTests.cpp`; semantic source is `bcf45fe28468b950987d52119548e06f411e4f19`. The rejected four-label singularity-port identity path is replaced by typed incident-fan equivalence under branch transport with topology-only representative/slot order; independent-oracle singularity facts now precede dependent attachment validation while dedicated pairing/attachment tamper checks remain strict.
- Mandatory full-owner pre-package compile `32322365847 / 96286951903` passed with result/log `9390213978 / 9390214237`, ZIP SHA-256 `6c5659a78c9e03ca1fbb1f16ab8e7eac991f394f862b667df5fcb035faf58625 / 0f302f90263414983b77ae9417dd0e5d85682f26b866a908a21e79e1e0a2d4dc`; `runtimeExecution=false`.
- Immutable full-owner package `9390283890` was created by `32322601532 / 96287590677`; package/log `9390283890 / 9390284226`, ZIP SHA-256 `621e679a8f3bb147a3acd43774f79cd68495b773ce52cc42df9bebf8018ded56 / dbc5aafeb745d4ff4d04dedf97816a1c079b6c6b2ded9fdca1816a8d3c9e38fd`. `SHA256SUMS` / embedded source archive SHA-256 are `a61075a57c68fd586dcea89fb8bcb8d1b1f0db6a45c9bf50f481caee9fc36bac / 1adae727de58cc854a7ffa1896ebd6158ee6716bbf849ddd56e4a083c4374b60`; all source-status snapshots and recursive manifest verification are clean.
- Package creation consumes CP2b attempt **2 of 3** and raises M3 cumulative package cost to **12**, reported only. No generated runtime occurred, so `PR8-R040`/`R041` remain active and stable totals remain **41 / 14 / 27**, debt **5**.
- Exact next is immutable `M3-CP2b-TB-R1` on unchanged **292** identities / selector SHA-256 `fc6bfc2b90c8a39512ee89e73106f2592fd4664aa90929c8c970e3ef0455245e`.

### Changed — M3 CP2b immutable attempt 1 rejected; bounded R1 attempt 2 planned

- Authoritative corrected `M3-CP2b-TB` `32317745051 / 96274463944` consumed exact package `740f0cca2f052d6274a7b24361bd33143f8c11f6 / 9388213803` and executed **292/292 identities exactly once**. Gate is **285/292**: CP2b **1/5**, accepted CP2 **4/6**, accepted CP1 A1 **5/6**, retained M2 groups **41/41**, retained M1 **234/234** including producer **138/138**. Result/log `9388855559 / 9388855833`, SHA-256 `b6f31868406f3b063c53bc2f0fdbcb5e45709950485e18f4aeee4206ef8d3413 / 7c2b42ed0cc5b692e78d060d7077607745c4358fceb59ff45192d867be2b9255`.
- Package/source postflight remained byte-identical; checkout/rebuild/relink/repair/source/test/fixture mutation/generated discovery/benchmark execution/package mutation/materialized-source mutation were all false.
- `PR8-R040 / M3-CP2b-R001` is **ACTIVE STABLE / RECURRENCE**, `RP-05`: local singularity ports compute normative `4-index` but seed all four branch labels and rely on representation-level deduplication. Two accepted CP2 network identities regress. `PR8-R041 / M3-CP2b-R002` is **ACTIVE STABLE / RECURRENCE**, `RP-03`: dependent port-attachment validation masks accepted singularity mismatch diagnostic in one CP1 A1 oracle. Stable totals become **41 / 14 / 27**; produced-witness debt remains **5**.
- Initial TB control `32317379701 / 96272468253` additionally lost 26 M1 producer identities because embedded fixtures were materialized away from the binaries' compiled source root. `M3-CP2b-TB-CAND-01` is **RESOLVED ORCHESTRATION / NON-STABLE** after the same-package control retry restored M1 producer **138/138**. `M3-CP2b-TB-CAND-02` tracks the four new CP2b first-runtime reds as **ACTIVE SEMANTIC / NON-STABLE**, sharing R040's root cause.
- Exact next is `M3-CP2b-CB-R1`, attempt **2 of 3**, under `Architecture_M3_CP2b_R1_Code_Build_Plan.md`. Requiring-change set narrows to `FieldTransportAtlas.cpp` + `FieldTransportAtlasTests.cpp`; the five CP2b names and exact **292** successor selector remain unchanged. No mandatory Review is due after one red package attempt.

### Changed — M3 CP2b Code + Build packages canonical A1 branch-topology authority

- `M3-CP2b-CB` held the Review-frozen three-file semantic/test surface and implemented additive canonical branch-frame, branch-boundary pairing/transport, and local singularity-port attachment authority inside `FieldTransportAtlas`; accepted predecessor raw-gauge `transport()` semantics were preserved. Semantic commit `dea28dd3fbeea55ad1ebc7000400aa539afa1fa8`; clean immutable package source `740f0cca2f052d6274a7b24361bd33143f8c11f6`.
- Final exact-source pre-package compile `32316219818 / 96268927018` passed. Full-owner package compile `32316219818 / 96269062793` passed and created artifact **`9388213803`**; package/log ZIP SHA-256 `0e8dbebc48a8390e6ca4ca83a4c98e4f137ba0e8728f87c6bf496a834578c279 / 6217fc5a76bb3b716c535abe4766c5fb91891b03d6e3ece5ff0f772e63613c42`. Embedded source archive SHA-256 `72d2cf0bae338482483fb1ddc6658347891b5111f64ed8763d1cbac176ea9410`; package manifest SHA-256 `698dbe11e196bbf9bb2fb72256e40cae5382474346de090ed1e9a8e52085d15c`; all source-status snapshots empty and manifest self-verification green.
- Frozen CP2b selector is **5** identities / SHA-256 `56f5443cb55f374c771efa9ec7ee25a33028cdfc88814a0ee5546e0957828de8`; exact combined gate is **292 = accepted 287 + 5** / SHA-256 `fc6bfc2b90c8a39512ee89e73106f2592fd4664aa90929c8c970e3ef0455245e`. Selector derived from accepted CP2 immutable artifact plus the five frozen CP2b names; generated discovery was not used.
- Code + Build executed no generated Directional runtime; `runtimeExecution=false`. Package creation consumes CP2b attempt **1 of 3** and raises M3 cumulative package count to **11**, reported only. No runtime regression/candidate was observed; stable totals remain **39 / 14 / 25**, produced-witness debt **5**. Latest accepted runtime remains CP2 until TB. Exact next: immutable `M3-CP2b-TB` on artifact `9388213803`, 292 identities.

### Changed — M3 CP3a authority Review confirms separate CP2b atlas checkpoint

- `M3-CP3a-AUTHORITY-CENSUS-REVIEW` independently upheld the pre-edit stop: accepted A1 owns relative Z4 transport but no canonical per-face branch frame/boundary pairing or checked local singularity-port attachment; A2a port ordinal is enumeration, and legacy `family/sign`/face-axis/nearest-direction machinery is not admissible semantic authority.
- The Review confirms **`M3-CP2b`** as a separate A1 semantic checkpoint and selects a nested immutable `FieldTransportAtlas` extension over a sibling public product. Frozen requiring-change set is exactly three files: `FieldTransportAtlas.h`, `FieldTransportAtlas.cpp`, `FieldTransportAtlasTests.cpp`; no new ID domain/CMake/pipeline/tracing edit is planned.
- CP2b freezes five new authority-kernel identities and a non-degenerate skew index-1 singularity / equivalent-nonzero-Z4-relabel witness. Immutable CP2b gate is **292 = accepted 287 + 5**. After accepted CP2b, CP3a's six frozen identities remain valid and its gate becomes **298 = 292 + 6**, superseding provisional 293.
- Review-only: no product/test/build mutation, compile, package, test, benchmark, or generated Directional runtime; `runtimeExecution=false`. Stable totals remain **39 / 14 / 25**, produced-witness debt **5**, CP3a attempt 1 remains unconsumed, and M3 package cost remains **10** reported only. Exact next: `M3-CP2b-CB`, attempt 1 of 3.

### Changed — M3 CP2 closure verified; documents consolidated; remaining M3 decomposed with a new CP2b checkpoint

- **CP2 closure independently verified.** Review/planning only; no product, test, fixture, or build edit, no compile, package, or generated Directional runtime. The claim was checked against source and artifacts rather than accepted from the report: the immutable gate reached **287/287** with `failedIdentities=[]`; the frozen selector is unchanged (combined SHA-256 `2caa018998a56a30fd174a525209b58b1af70e0824c4703e4a78dade9a3dcd20`) with no identity removed, renamed, or made non-gating; commit `5a284388` touches exactly the two frozen files; the mandatory exact-source pre-package compile `32298525762 / 96215475032` was green; every immutability flag is false with byte-identical package/source postflight; and all 17 previously lost retained identities are restored (M1 producer **138/138**).
- **Verified in source, not inferred.** `SurfaceCellTracing.cpp:314-322` carries the specified closed/open branch including the `sourceEdges.size() >= 3` guard and `(interval + 1) % |V|` indexing. `tests/FieldAlignedCurveNetworkTests.cpp:414-528` walks a real four-edge boundary loop from `baselineMesh.EV`/`EF` with real mesh edge indices — the `M3-CP2-REVIEW-AUDIT` F1 amendment was implemented, not paraphrased — and proves all three previously unreachable cross-closure conditions (`MissingMandatoryEdge`, `ForeignMandatoryEdge`, `MandatoryKindMismatch`) positively. `rails_from_atlas` now derives `sourceEdges` via `source_edge_index(mesh, ...)`. The original open-rail ordering proof is retained; rotation and reversal preserve the semantic digest.
- **One documentation defect found and corrected:** the M3 stable-ID mapping table in `Regression_Root_Cause_Tracker.md` listed `PR8-R039 / M3-CP2-R001` as `active` while the same document's narrative recorded it RESOLVED. The table now reads `resolved`; no regression history was removed.
- **Consolidation.** New durable `M3_CP2_Closure_Record.md` owns the CP0/CP1/CP2 closure record — verification, deliverables and explicit non-claims, trajectory, cost, root cause, and the arc's five durable lessons. The consumed `Architecture_M3_CP2_R1_Artifact_Only_Test_Benchmark_Report.md` is retired after its facts were preserved there. `RETENTION_POLICY.md` now lists the M1/M2/M3-CP2 closure records in the durable set.
- **Durable documents trimmed to current fact.** `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md` sections 5-5H (consumed CP0/CP1 per-turn narrative, including a superseded review conclusion that was itself later corrected) are replaced by a pointer to the closure record, making the plan forward-looking. `Future_Chat_Session_Handoff.md` loses the rejected CP1 package-6 and CP2 package-9 sections, a verbatim-duplicated authority section, and a "Standing product state" block that still claimed M3 **9/12** with `M3-CP2-TB` as exact next. `REORIENTATION_PLAN.md` section 7 loses trailing CP1-TB narrative that still asserted CP1 4/4, M3 5/11, and CP2 blocked. `TODO.md`'s M3 section drops completed per-turn rows per its own stated purpose. Every durable-marked section is preserved.
- **Planning gap found and closed: the CP3a census stop is a missing checkpoint, not a missing plan detail.** Per-face branch frames, branch-to-boundary interval classification, and port-to-starting-branch attachment are upstream A1 single-writer authority — a different semantic domain from branch-consistent traversal. Bundling them into CP3a's first package repeats the unit-3 Batch E error that cost 4 of that unit's 6 attempts. `M3-CP2b` is therefore inserted ahead of CP3a with its own gate and its own 3-attempt budget (plan section 4A.1); CP3a narrows to a CP2b consumer. Under the retired cumulative ceiling this would have required an allocation amendment; under the per-checkpoint regime it costs nothing.
- **CP3b and CP4 decomposed** from one-line table rows into task lists (plan sections 4A.2-4A.3, mirrored in `TODO.md`): CP3b owns typed first-contact incidence, intersection nodes, termination events, exactly-once port consumption, the CP0-assigned independent composition proof, and tamper negatives; CP4 owns topology derivation, `GlobalTopologyPlan` region publication, per-region disc proof, mandatory-topology preservation, `FieldTransportUnestablished` representation, and the two representative topology witnesses. `M3-CP4-TB` remains the cumulative exit gate and `M3-FULL` remains omitted.
- `Architecture_M3_CP3a_Authority_Census_Review_Plan.md` gains binding section 4A: the Review must state whether the amendment is CP2b or genuinely CP3a **justified by semantic domain**, re-scope CP3a and re-check its six frozen contract names if the split holds, and name CP2b's own falsifiable prediction and **non-degenerate** witness — a branch-frame authority proven only where every branch is identical and every interval symmetric would be the CP1 planar-fixture and CP2 single-edge-rail failure in its next form.
- CP2 remains accepted; `PR8-R038` and `PR8-R039` remain resolved; stable totals remain **39 / 14 / 25** and produced-witness debt **5**. Exact next is `M3-CP3a-AUTHORITY-CENSUS-REVIEW`, which consumes no attempt and authorizes no package. Cumulative M3 cost remains **10 packages**, reported only.

### Changed — M3 CP3a pre-edit census stops before mutation; authority Review required

- `M3-CP3a-CB` completed its mandatory pre-edit census and answered the plan's authority-sufficiency question **NO**. Accepted `FieldTransportAtlas` provides typed relative quarter-turn transport only after an adjacency is selected, while `FieldAlignedSingularityPort` provides ownership/index/ordinal without a checked starting branch/source sector; neither publishes the per-face combinatorial inflow/outflow interval authority required by `DESIGN.md` section 4.5.
- The only current local branch-to-triangle decision path is the legacy raw face-axis/`family/sign` tracer. Reinterpreting that representation as A2a authority would violate the frozen CP3a plan and the M1/M2 single-writer rule that consumers do not reconstruct missing upstream semantics. `CanonicalRoute` composes typed observed transitions but does not choose an outgoing source edge.
- The CB therefore **stopped before semantic/test mutation**. No pre-package compile, immutable package, test, benchmark, CLI, discovery, custom mesh, or generated Directional runtime occurred; `runtimeExecution=false`. CP3a attempt **1 of 3 remains unconsumed** and M3 cumulative package cost remains **10**, reported only. No runtime regression/candidate was observed; stable totals remain **39 / 14 / 25** and produced-witness debt **5**.
- Exact next is Independent Review `M3-CP3a-AUTHORITY-CENSUS-REVIEW` under `Architecture_M3_CP3a_Authority_Census_Review_Plan.md`. It must independently census the missing branch/interval authority, choose the minimal A1 single-writer amendment, reject raw semantic fallback, freeze the amended site set, and retain a nontrivial equivalent-Z4 branch-relabel witness before Code + Build resumes.

### Changed — M3 CP2 R1 immutable gate accepted; CP3a unblocked

- `M3-CP2-TB-R1` accepted exact source/package `5a284388d360efa4ce1bd37bc584165e1db0157b / 9382182983` by immutable runtime `32300950126 / 96223162140` at **287/287**: CP2 **6/6**, CP1 A1 **6/6**, retained M2 **275/275**, retained M1 producer **138/138**, `failedIdentities=[]`.
- Result/log artifacts `9383055423 / 9383056029` have outer SHA-256 `9f1be41dacb8041ebb49468c6df2c3b44d35c026796ec94cca5caf86cb7dbf46 / 34b30b4ad63873e7144d31b595c09ba2201788057671e260ac4d30829003c48f`. Package and materialized-source postflight were byte-identical; rebuild/relink/repair/source-test-fixture mutation/generated discovery/benchmark/package mutation were all false.
- The strengthened real four-edge closed-boundary identity passed wraparound ownership, complete atlas mandatory-edge coverage, kind agreement, cyclic rotation, and reversal. Named failing-diagnostic counts are `ForeignMandatoryEdge=0`, `MissingMandatoryEdge=0`, `MandatoryKindMismatch=0`; the explicit positive assertions, not the zero failure-text counts, are the F2 cross-closure evidence.
- `PR8-R039 / M3-CP2-R001` is **RESOLVED STABLE / RECURRENCE**. Historical stable totals remain **39 / 14 / 25** and produced-witness debt **5**; no new regression/candidate was observed.
- CP2-R1 attempt **1 of 3** succeeded; cumulative M3 package cost remains **10**, reported only. Exact next is `M3-CP3a-CB`, attempt **1 of 3**, under `the retained CP3a Code + Build plan history in `CHANGELOG.md``; its successor immutable selector is **293** identities.

### Changed — M3 CP2 R1 package attempt 1 compile-green; immutable 287 gate frozen

- `M3-CP2-CB-R1` changed exactly two semantic/test files on exact source `5a284388d360efa4ce1bd37bc584165e1db0157b`: the network builder now accepts canonical closed rails (`|V|=|E|`, minimum three edges) with modulo wraparound while preserving all exact ownership/cross-closure guards; the existing ordering identity now derives a real four-edge closed boundary rail, uses real mesh edge indices, proves wraparound ownership/full atlas mandatory coverage/kind agreement, and proves cyclic/reversed semantic invariance.
- Mandatory exact-source pre-package compile `32298525762 / 96215475032` passed on `directional_core`, `directional_pipeline`, and `directional_surface_cell_producer_tests`; result/log `9382153869 / 9382154659`, SHA-256 `ced23d159e774356101d52ec90f9bf487f99ece6d0b88129ba3afddff478641e / d1a0ebf3ed7dabb11ec9af35ba0883ce753e8a0701393896c0579f0c83b479b2`. `runtimeExecution=false`; source status remained clean.
- Immutable package attempt 1 used the identical source in `32298525762 / 96215956809`; package/log `9382182983 / 9382183660`, SHA-256 `ad6be17f7c2262a33f5902ac6c0544de747daa77f01d7b4ec9c06f31e69feac1 / c82df05ab380c6c26f91a4ee2399506dc631783126d1d4f55df30f81e7842fa4`; packaged-source SHA-256 `dad1f144dda2fc6824283157a1dc1594c2f1cf402a6f58bc08e4947959ac5f79`; all manifest/source-status checks passed; `runtimeExecution=false`.
- CP2-R1 attempt **1 of 3** is consumed; cumulative M3 package cost is now **10** and remains reported, not gated. Compile/package green does not accept CP2 or resolve `PR8-R039`; stable totals remain **39 / 14 / 25**, produced-witness debt **5**. Exact next is immutable `M3-CP2-TB-R1` on artifact `9382182983` with the unchanged **287** identities and no rebuild.
- Temporary schema/apply/compile callers, trigger markers, and turn payloads were removed after evidence collection; exactly the five durable workflows remain.

### Changed — M3 CP2 review independently audited; cumulative package ceilings retired for M3-M8

- `M3-CP2-REVIEW-AUDIT` completed as Review/planning only. No product, test, fixture, or build edit; no compile, package, or generated Directional runtime. Findings amend `Architecture_M3_CP2_R1_Code_Build_Plan.md` (new section 3A, plus 4.1, 4.2.1, 7, 8, 9) rather than creating a new document.
- **`M3-CP2-RUNTIME-REGRESSION-REVIEW` upheld** on every load-bearing claim, each re-derived from source: the producer canonicalizes closed rails to `|V|=|E|` after checking `front == back` (`src/pipeline/RemeshPipeline.cpp:3579-3583`); `canonical_field_aligned_candidate(...)` requires `|V|=|E|+1` unconditionally and never reads `rail.closed` (`src/geometry/SurfaceCellTracing.cpp:314-315`, `:322-324`); all three wraparound consumers already handle the canonical form (`RemeshPipeline.cpp:3811-3823`, `:4138-4151`, `:11877-11888`); the atlas marks every boundary edge `SourceBoundary` (`src/authority/FieldTransportAtlas.cpp:504-508`), so the wraparound edge is genuinely mandatory. The root cause, the refusal to change rail production, and the two-file surface stand.
- **F1 (decisive).** `rails_from_atlas(...)` (`tests/FieldAlignedCurveNetworkTests.cpp:143-186`) fabricates one single-edge open rail per barrier, so `|V| == |E|+1` holds trivially for every rail any CP2 test has built and `rail.sourceEdges` carries a barrier list position rather than a mesh edge index. CP2 scored **6/6 on a builder that rejects every closed production rail**. This is the same degenerate-fixture failure as CP1's planar `z = 0` A1 fixtures, one checkpoint later. The plan's "or an exact producer-equivalent checked setup" wording is removed; the strengthened identity must derive its closed rail from real mesh topology — the `make_square_mesh` boundary is a genuine four-edge closed loop requiring no pipeline dependency.
- **F2.** The rail-cardinality rejection fires before `mandatoryByEdge` is built, so `ForeignMandatoryEdge`, `MissingMandatoryEdge`, and `MandatoryKindMismatch` have never executed on a closed rail. `MissingMandatoryEdge` demands complete boundary-edge coverage by rail production, which is unverified. The plan's 287/287 prediction is therefore unsupported by evidence; the strengthened identity must prove those three checks and the successor TB must report them as named diagnostics.
- **F3.** The closed branch additionally requires `sourceEdges.size() >= 3`; below that `(i+1) % |V|` yields a self-key (`DegenerateSourceEdge`) or two identical keys misreported as `DuplicateMandatoryEdge` on a single rail. `SourceEdgeTopologyKey::make` (`src/authority/AuthorityKernel.cpp:17-28`) rejects `a == b` and normalizes the pair.
- **F4, recorded not scheduled.** All three wraparound consumers guard with `closed && back() != front()` and so tolerate both closed representations: the canonical form has one writer and no enforcing reader. Added to the `TODO.md` design backlog; out of scope for CP2-R1.
- **Budget regime changed by user authorization.** Cumulative per-milestone package ceilings are **retired for M3-M8** and replaced by a per-checkpoint attempt budget: one attempt = one immutable Code + Build package submitted to its immutable TB, consumed at package creation; 3 attempts per checkpoint; a third red TB forces a mandatory independent Review before a fourth; a completed review restores 3 attempts under a ratchet (2nd review at 6 red must rescope, amend the design, or recommend stopping; 3rd at 9 red is a hard stop needing explicit authorization); cumulative cost is reported, not gated. Review turns, the mandatory pre-package compile, documentation/control-plane commits, and a CB that stops before packaging consume no attempt.
- Rationale recorded in `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md` section 1.1.3 and `REORIENTATION_PLAN.md` section 5 item 4: the M1/M2 cost calibration came entirely from cutovers and does not transfer to new-capability milestones, and M3's ceiling was amended under pressure at every binding point (11, `5 -> 6`, `6 -> 7`, `11 -> 12`, pending `12 -> 13`), which converted the stop rule into a recurring negotiation. Measured M1/M2 costs are retained as calibration history. Every mandatory review must re-derive the failure from source, check the checkpoint's fixtures against the contract's non-trivial domain, state one falsifiable prediction, and enumerate the checks the failure was masking.
- The relaxation is budget-only: the mandatory exact-source pre-package compile, package immutability, artifact-only TB, "compile-green is not acceptance", the prohibition on shrinking a frozen selector, and the prohibition on merging independent semantic checkpoints are all unchanged.
- The `12 -> 13` allocation request is **withdrawn**. `M3-CP2-CB-R1` is **UNBLOCKED** as attempt **1 of 3**. CP1 remains the accepted runtime authority at **281/281**; CP2 remains NOT accepted at **270/287**; `PR8-R039 / M3-CP2-R001` remains OPEN STABLE / RECURRENCE; stable totals remain **39 / 14 / 25** and produced-witness debt remains **5**. A review turn observes no runtime and changes none of these.

### Changed — M3 CP2 runtime Review confirms two-file cyclic-rail repair; cap 12 -> 13 authorization required

- Review-only `M3-CP2-RUNTIME-REGRESSION-REVIEW` independently enumerated authoritative rail production/consumption on exact rejected CP2 source `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff`; no product/test/fixture/build semantic edit, compile, package, or generated Directional runtime occurred.
- `build_authoritative_surface_cell_rails(...)` deliberately removes the repeated terminal vertex after verifying a closed run, publishing closed `|V|=|E|`. Existing tracing interval validation, hard-feature/boundary extraction, optimization constraints, sequence validation, and aggregate/final remap already restore or traverse the wraparound edge. The only enumerated incompatible cardinality/indexing site is CP2 `canonical_field_aligned_candidate(...)`. `PR8-R039 / M3-CP2-R001` root cause is therefore confirmed, not broadened.
- Successor `Architecture_M3_CP2_R1_Code_Build_Plan.md` freezes exactly two files: `src/geometry/SurfaceCellTracing.cpp` and `tests/FieldAlignedCurveNetworkTests.cpp`. Production distinguishes open `|V|=|E|+1` from closed `|V|=|E|` and uses modulo wraparound for the closed final interval only; the existing packaged ordering identity gains producer-shaped closed-cycle, wraparound-owner, cyclic-rotation, and reversal proof. No CMake/header/pipeline/fixture change is planned.
- Acceptance remains the same **287 identities**; the exact 17 currently lost predecessor identities remain gating. A separate exact-source pre-package compile of core/pipeline/producer owners remains mandatory before any package.
- Four independent packages remain necessary (CP2 R1, CP3a, CP3b, CP4). Minimum sound allocation is cumulative M3 ceiling **12 -> 13**, assigning package 10 to CP2 R1, 11 CP3a, 12 CP3b, 13 CP4, no retry reserve, no automatic package 14. Review does **not** authorize this amendment; `M3-CP2-CB-R1` is BLOCKED pending explicit user authorization.
- No runtime occurred, so `PR8-R039` stays OPEN STABLE / RECURRENCE and stable accounting remains **39 / 14 / 25**; produced-witness debt remains **5**.

### Changed — M3 CP2 immutable TB rejects closed-rail linearization; Review required

- Immutable `M3-CP2-TB` `32289400790 / 96186521474` consumed exact `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff / 9375452692` artifact-only. All **287/287** frozen identities selected; gate is **270/287 FAIL**: CP2 **6/6**, CP1 A1 **6/6**, retained M2 **258/275**, retained M1 producer **121/138**.
- Result/log `9378919809 / 9378920482` have SHA-256 `8fcc4ce18c41cb9f4096c3d1792ec9799e74d6ad1f0cc1f1a13425757523e074 / aa5ce53a1765aa4e64e23e93c2dc885b08fda316a87b6d83f91e6a3e84567cd4`. Package and materialized-source postflight are unchanged; no repository checkout, rebuild, relink, repair, source/test/fixture mutation, generated discovery, benchmark execution, package mutation, or materialized-source mutation occurred.
- All 17 retained reds share `field-aligned-network/InvalidRailGeometry`. Root cause: CP2 applies open-polyline `|V|=|E|+1` validation/indexing to authoritative closed rails, while production deliberately stores closed cycles without the duplicated terminal vertex (`|V|=|E|`) and requires wraparound.
- New `PR8-R039 / M3-CP2-R001` is **OPEN STABLE / RECURRENCE**, primary `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION`, detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Historical totals become **39 events / 14 categories / 25 recurrences**; produced-witness debt remains **5**.
- CP2 is NOT ACCEPTED. CP1 remains latest accepted runtime authority at **281/281**. M3 remains **9/12**; package 10 / CP3a is blocked and no CP2 retry package is authorized. Exact next is Review-only `M3-CP2-RUNTIME-REGRESSION-REVIEW`.
- The user-squashed branch was verified history-only/tree-identical before TB controls: `79af42967b4ad4c3c2ce6b9d132172ef89a6eeb8` and pre-squash `4cbe2a27ab4cdbadf39d4780b427cbd94db6c8b7` both own tree `bf7d1310ed01f582b27fd3d5f46b84c3ad6f498c`.

### Changed — M3 CP2 package 9 compile-green; immutable 287/287 candidate frozen

- Exact semantic source `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff` implements the frozen eight-file typed `FieldAlignedCurveNetwork` CP2 slice; the final compile correction is one namespace qualification in the typed seed path.
- Mandatory pre-package `32279124852 / 96153441513` was green on the literal source with `runtimeExecution=false`; result/log `9375262215 / 9375262622`.
- Package 9 `32279806492 / 96155630834` compiled and packaged the identical source. Package/log `9375452692 / 9375453342`; package outer SHA-256 `6f8865a3d3c28ea803a40cc9929f22de5a1d313f4810541f6474bbfba9b8ef79`; packaged source archive SHA-256 `5b1f047a986e9d58058b09efdf362112674ba63fe255230f5d2f4db2c0872870`, 549 members, zero symlinks; 28 files / 27 self-excluding manifest entries / five empty source-status snapshots.
- No generated runtime executed; stable totals remain **38 / 14 / 24**, produced-witness debt **5**. M3 is **9/12**. Exact next is immutable `M3-CP2-TB` at **287/287**; CP3a is blocked until CP2 acceptance.
- `tmp-lowlevel-test` contains zero unique work and remains disposable because the connector exposes no branch-delete operation.

### Changed — M3 CP1 accepted: exact-zero cycle support correction restores full frozen gate

- Immutable `M3-CP1-TB-R3` `32263614534 / 96102598799` consumed exact `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` artifact-only and passed **281/281**: A1 **6/6**, retained M2 **275/275**, retained M1 producer **138/138**. Result/log `9369359878 / 9369360425` have outer SHA-256 `829f51e1510ba6aab2eb6f6eed716bd736dcd662b1932b05a6fe16d6223917fd / b624982cd6f5479cd167124c3897725533c6ce460fb6ce96751dfcfcfb18572c`; `failedIdentities=[]`.
- Package/source postflight remained byte-identical. No repository checkout supplied semantic source; no rebuild, relink, package repair, source/test/fixture mutation, generated discovery, or benchmark execution occurred.
- `PR8-R038 / M3-CP1-R001` is resolved: exact algebraic-zero sparse cycle entries had polluted curvature support while typed transport already ignored them. R5 canonicalizes exact zero before iterator-visible curvature/support semantics, restoring one semantic support for exact lift/index and composed transport. `M3-CP1-TB-CAND-01` is also resolved at A1 6/6.
- Resolution adds no new historical incidence. Stable totals remain **38 events / 14 categories / 24 recurrences**; produced-witness debt **5**.
- CP1 is **ACCEPTED**, package budget **7/7**; M3 consumption is **8/11**. Exact next is planning-only `M3-POST-CP1-ALLOC-REPLAN`; CP2 remains blocked until three remaining packages are reconciled against four currently planned later Code + Build checkpoints.

### Changed — M3 CP1 R5 package 7 compile-green; immutable TB-R3 candidate frozen

- `M3-CP1-CB-R5` exact semantic source `9f7e222bab6c930a12d1369fa2aee869f5c0dcff` changes exactly two files: `MeshTopology.cpp` canonicalizes exact algebraic-zero final cycle-basis storage before curvature iteration, and the existing relative-boundary square test independently proves zero semantic support, identity transport, lift `4`, and oracle agreement. A1 congruence and the hard production gate remain intact.
- Mandatory external pre-package `32256978633 / 96080841350` passed **91/91** on literal `9f7e222bab6c930a12d1369fa2aee869f5c0dcff` with `runtimeExecution=false`; result/log `9366688695 / 9366689453`. It consumed no package.
- Authorized package 7 `32257160818 / 96081424766` compiled the identical source across the full approved owner closure **123/123**, producing package `9366752046` SHA-256 `5d779d578f900597053527e2edf7e61f3382de94a1852e94e2fdb712460595a7` and log `9366752647` SHA-256 `6d664f0bcc767958f4dbfddcba808f7e86fede6515595b9c5265414298dee3a9`. Package manifest/source status self-verification passed; source archive SHA-256 `50566ca66d26b92db4a008ce735a1164b061eb273206d10800b554af236d8c73`, 554 members, zero symlinks.
- No generated Directional runtime/test/benchmark/discovery/CLI executed. CP1 is **7/7**, M3 **8/11**, but CP1 remains NOT ACCEPTED. Regression totals remain **38 / 14 / 24**, produced-witness debt **5** because Code + Build observes no runtime.
- Exact next is immutable `M3-CP1-TB-R3` on `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` at unchanged **281/281** acceptance. Any red stops for Review; if green, successor is `M3-POST-CP1-ALLOC-REPLAN` before CP2.

### Changed — M3 CP1 A1 rescope: asserted cycle-transport congruence disproven; design amendment recommended

- `M3-CP1-A1-RESCOPE` completed as Review/planning only. No runtime observed, no package consumed, no product, test, fixture, or build input mutated. Owning document is `Architecture_M3_CP1_A1_Rescope_Review.md`.
- The first failed premise in the prior F5 derivation is the congruence itself. `effort_to_indices` (`src/fields/FieldMatching.cpp:5-21`) builds the cycle index from `effort` and `curvature`, and `FieldTransportAtlas.cpp:720-726` reproduces that formula exactly, so `turningLift` **is** the accepted index. `principal_matching` (`src/fields/FieldMatching.cpp:123-125`) makes `matching` an integer branch offset `round((currEffort - effort)/2π)` from a principal angle and an N-branch unwrapped sum. The two quantities come from different inputs; no congruence between `Σ matching (mod 4)` and the index follows from either definition.
- Hand-derived failing-valid cycle: any interior vertex cycle on a curved, non-singular region has `index = 0`, `curvature ≠ 0`, hence `Σ ±effort = −N·curvature ≠ 0`, per-edge `matching ≠ 0`, and `composed ≠ 0 = normalized_quarter_turn(0)` → `CycleTransportMismatch` on a valid cycle. Reversal negates both sides and `−x ≢ 0 (mod 4)` whenever `x ≢ 0`, so both orientation branches fail on identical cycles. This is why six packages of sign searching could not repair it.
- Prediction verified against evidence: `tests/FieldTransportAtlasTests.cpp:51-68` places all four `make_square_mesh` vertices at `z = 0.0`. A1's fixtures are planar, so curvature and every `matching` are zero and the congruence holds trivially `0 ≡ 0`. This explains the exact observed split — A1 **3/6** on degenerate fixtures while 20 retained M1 producer identities on curved production meshes are preempted by A1's hard gate at `src/pipeline/RemeshPipeline.cpp:6573-6583`. With the F4 oracle read-back, the checkpoint had no mechanism capable of falsifying its own central invariant.
- Recommendation: explicit A1 design amendment. Remove the congruence as a construction-time precondition with no replacement congruence, corrected sign, inequality, or tolerance — A1 re-deriving the index is authority duplication under migration rule 1. Amended A1 consumes the index, publishes it typed, and asserts typed transport completeness, reciprocity `κ(f→g) = −κ(g→f)`, index fidelity against `effort_to_indices`, non-traversable classification, and certificate binding by digest.
- `Architecture_M3_CP1_A1_Derivation_Review_Report.md` is retained as history with its `Z4` relation marked DISPROVEN; the superseded durable lesson asserting `turningLift ≡ sum(s_e*matching_e) (mod 4)` is corrected in place rather than deleted.
- `PR8-R038 / M3-CP1-R001` and `M3-CP1-TB-CAND-01` are unchanged; a review turn observes no runtime. Stable totals remain **38 / 14 / 24**, produced-witness debt **5**.
- CP1 remains **NOT ACCEPTED**, **6/6**; M3 **7/11**. This review authorizes no package. Exact next is planning-only `M3-CP1-PLAN-AMEND`, which must record the design amendment, state the quadrangulability certificate's honest scope, and amend the allocation **CP1 6 → 7 / M3 → 8/11** with explicit notice that CP2-CP4 then share 3 packages. CP2+ remain blocked.

### Changed — M3 CP1 package-6 immutable R2 reproduces A1 cycle mismatch; rescope required

- `M3-CP1-TB-R2` `32226787294 / 95987961593` consumed exact source/package `95006048225df765b5b9c31e235fed82330a1469 / 9354456191` artifact-only. Result/log `9355788148 / 9355788629` outer SHA-256 `0aa97b371e0081c094791ed568117685e1c8cfe79b8488fe8c0b28d3e6dd00b8 / 9097f7f3859676c6130ab1dc1c8015beae909008af90c325cfcd673292b6040e`; package/source postflight was byte-identical and no rebuild, relink, repair, source/test/fixture mutation, generated discovery, or benchmark execution occurred.
- All **281/281** frozen identities selected. Gate remains **258/281 FAIL**: A1 **3/6**, retained M2 **255/275**, retained loss isolated to M1 producer **118/138**; all other retained partitions are green. The same three A1 baselines and same twenty retained producer identities remain red behind `CycleTransportMismatch` or dependent early-rejection effects.
- R4's fixed cycle-row orientation, immutable expected lift, and independently source-derived cycle oracle therefore do not establish the prior F5 relation on the valid baseline. The abstract-to-repository convention mapping must be reopened rather than patched by another sign search, invariant weakening, or A1 bypass.
- `PR8-R038 / M3-CP1-R001` remains the same open stable recurrence and `M3-CP1-TB-CAND-01` remains the same non-stable three-test candidate. R2 adds no new stable event or recurrence; totals remain **38 / 14 / 24**, produced-witness debt **5**.
- CP1 remains **NOT ACCEPTED**, **6/6**, M3 **7/11**. No package 7 is authorized. Exact next is Review/planning-only `M3-CP1-A1-RESCOPE`; CP2+ remain blocked.

### Changed — M3 CP1 R4 package 6 compile-green; immutable TB-R2 candidate frozen

- User authorization amended CP1 local cap **5 -> 6**. Exact semantic source `95006048225df765b5b9c31e235fed82330a1469` changes exactly `src/authority/FieldTransportAtlas.cpp` and `tests/FieldTransportAtlasTests.cpp` (+425/-50): production removes whole-cycle orientation/sign search and immutable `turningLift` is checked once; the oracle independently derives source connection/matching/effort, cycle support/orientation, curvature, and exact lift.
- Required external owner pre-package `32222508189 / 95975565518` passed **91/91** on the literal source. Result/log `9354405173 / 9354405691` outer SHA-256 `d86c8b1b13be1f3f62a956b334a65221a4a4def6f0060202bc2cbd4604f78036 / 329fbe1c638396a1e15f522f15c8f1cf0bfe17dd5c23f78de69b1dc104532e71`. It consumed no package and recorded `runtimeExecution=false`.
- Authorized package 6 `32222669309 / 95976032350` compiled the identical source across the complete approved target set **123/123**. Result/package `9354456191` SHA-256 `da1b4e111642c4b637746c81df1f7d24eb56d47dda9ac3de0a69b5d126313c18`; log `9354456667` SHA-256 `2a1b91ff7667b8071e5647bbe9f3004f1fe34851f8ed917fea90a8ef0f1a6d97`. Manifest/source-status verification passed; `runtimeExecution=false`; no generated Directional test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- CP1 is **6/6**, M3 **7/11**, but CP1 remains **NOT ACCEPTED**. M2 remains accepted at **275/275 + K=0**. Stable regression totals remain **38 / 14 / 24**, produced-witness debt **5**; Code + Build does not resolve the historical R1 reds.
- Exact next is immutable `M3-CP1-TB-R2` consuming `95006048225df765b5b9c31e235fed82330a1469 / 9354456191` without rebuild or mutation at unchanged **281/281** acceptance. CP2+ remain blocked; no CP1 package 7 is authorized.

### Changed — M3 CP1 A1 cycle relation derived; final repair narrowed

- Independent `Architecture_M3_A1_Implementation_Review.md` correctly localized the residual package-5 failure to whole-cycle orientation search, publication of a searched `turningLift`, and an oracle that reads that published value back. Planning-only `M3-CP1-A1-DERIVATION` independently reviewed those findings; no product/test/build source, compile, package, or generated Directional runtime was authorized or executed.
- The missing F5 relation is now written explicitly from accepted repository conventions: for the signed `dual_cycles` row, `turningLift = (sum(s_e*effort_e) + 4*K_C)/(2*pi)` and **`turningLift ≡ sum(s_e*matching_e) (mod 4)`**. `QuarterTurn` composition is therefore the correct `Z4` comparison. The invariant is retained; semantic orientation may not be searched or adjusted until it passes.
- The independent review's C1 persistent staging recommendation is narrowed. `DESIGN.md` §7.5 requires A1 before topology planning, so CP1 cannot be accepted by bypassing A1 and postponing the hard gate. The twenty retained reds must be restored by making valid predecessor inputs satisfy A1.
- Final bounded repair scope is one semantic domain in two files: `src/authority/FieldTransportAtlas.cpp` (single fixed row orientation, immutable derived lift) and `tests/FieldTransportAtlasTests.cpp` (independent source-derived cycle index/oracle). `RemeshPipeline.cpp`, headers, fixtures, and build contracts are outside the final repair.
- CP1 remains **NOT ACCEPTED**, **5/5**, M3 **6/11**; M2 remains accepted at **275/275 + K=0**. Stable totals remain **38 / 14 / 24**, produced-witness debt **5**. No package 6 is authorized. Exact successor `M3-CP1-CB-R4` is BLOCKED pending explicit CP1 local-cap **5 -> 6** authorization; if authorized, a true external pre-package compile must precede package 6.

### Changed — M3 CP1 package-5 immutable R1 narrows but does not resolve A1 transport regression

- `M3-CP1-TB-R1` `32211699382 / 95945506893` consumed exact source/package `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667 / 9350420635` artifact-only. Result/log `9350958978 / 9350959164` outer SHA-256 `eb43ba06e63ba230cf9c77bcdf1efc5e856b2adb660b04ce5fac8e3378286793 / a5346129311c70d084124b342f59f3c2c0097e198606ff14dca69a1f4ed6c03e`; package/source postflight unchanged; no rebuild, relink, repair, source/test/fixture mutation, discovery, or benchmark execution.
- All **281/281** frozen identities selected. Gate is **258/281 FAIL**: A1 **3/6**, retained M2 **255/275**, retained loss isolated to M1 producer **118/138**; all other retained partitions remain green.
- R3 restores `FieldTransportAtlas.ClassifiesHardFeaturesAsNontraversableCuts` and retained `HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped`. Three A1 positives/oracles and twenty retained producer identities remain red. Surviving earliest diagnostics are `InvalidFieldTransportAtlas:field-transport-atlas/CycleTransportMismatch`; downstream variant exceptions and unreached mutation/oracle seams are dependent failures.
- `PR8-R038 / M3-CP1-R001` remains the single open stable recurrence; R1 is partial repair/refinement, not a new stable event. `M3-CP1-TB-CAND-01` narrows from four to three new A1 reds and remains non-stable. Totals stay **38 events / 14 categories / 24 recurrences**; produced-witness debt **5**.
- CP1 remains **NOT ACCEPTED**, **5/5**, M3 **6/11**. M2 remains accepted runtime authority. No package 6 is authorized. Exact next is Review/planning-only `M3-CP1-RUNTIME-REPLAN-R2`; CP2+ remain blocked.

### Changed — M3 CP1 R3 package 5 compile-green; immutable TB candidate frozen

- User authorization raised CP1 local cap from 4 to **5** while retaining the M3 hard ceiling of **11**. Exact semantic source `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667` was unchanged from the green external pre-package compile.
- Full package run/job `32209993498 / 95940623789` compiled the authority-kernel owner **91/91** then the remaining approved closure **32/32**, for **123 build actions**. Result/log `9350420635 / 9350421043` have outer SHA-256 `553da343e6400ed1acee2272acadafd5f61f59e4d1b8bdf51c3552cb339cc370 / b26965cb859c8c3cfaacbf0fc7a3e574b0fa8dacf887aee119bdc8d45725075e`; result manifest self-verification is **27/27** across 28 uploaded files and source status is clean.
- `runtimeExecution=false`; no generated test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Post-package source audit confirms every branch change after `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667` is documentation/control-plane only. CP1 is **5/5**, M3 **6/11**, no package 6 is authorized. `PR8-R038` and `M3-CP1-TB-CAND-01` remain open until immutable runtime evidence.
- Exact next is `M3-CP1-TB-R1` consuming `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667 / 9350420635` without rebuild or mutation.

### Changed — M3 CP1 runtime replan retains A1; bounded R3 correction pre-package compile-green

- Independent runtime replan retained the CP0 A1 contract and refined the failed-TB diagnosis: `dual_cycles` includes the required cycle families, but explicit sparse algebraic zero storage was treated as semantic support, while valid one-face relative-boundary regions were forced through a generic local `TriMesh` representation that can reject a single triangle.
- Exact source `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667` changes only `src/authority/FieldTransportAtlas.cpp` (+56/-2): ignore near-zero stored coefficients before strict nonzero `±1` support validation; directly publish the checked trivial one-face relative-boundary witness. Tests, fixtures, header, build contract, and semantic-domain count are unchanged.
- External owner-prepackage run/job `32208365044 / 95935875386` passed **91/91** for `directional_surface_cell_authority_kernel_tests` on literal `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667`. Result/log `9349870579 / 9349870841` SHA-256 `b206228343ccee32e05f12d782443a93488a858f4a8ef2ebcce5dc1ac98cca02 / 4cec8b2164044e0a07d6e2b4db0dfeea930f156df862a279ec0453449d81f948`. `runtimeExecution=false`; no generated Directional runtime/test/benchmark/discovery/CLI executed.
- This pre-package evidence is mechanics-only and consumes no CP1 package. CP1 remains **4/4**, M3 **5/11**, and `PR8-R038 / M3-CP1-R001` remains open until immutable runtime acceptance. Stable totals stay **38 / 14 / 24**; produced-witness debt **5**.
- Exact next is `M3-CP1-CB-R3-PACKAGE`, blocked pending explicit user authorization for CP1 package 5 / local cap 4 -> 5.

### Changed — M3 CP1 immutable runtime gate rejects atlas authority

- `M3-CP1-TB` consumed exact `9f54c77ae92161226e833cf313bf38e516aa276c / 9347879320` without rebuild/relink/repair/source-test-fixture mutation or discovery; package/source postflight unchanged.
- Run/job `32204335734 / 95924452913`; result/log `9348592210 / 9348592414`; all **281/281** selected; result **256/281**, with A1 **2/6** and retained M2 **254/275**.
- `PR8-R038 / M3-CP1-R001` records one stable RP-01 recurrence: reconstructed local tangent-bundle cycle/binding representation is promoted to canonical A1 source authority, causing valid retained paths to reject early. Four new A1 baseline-construction reds are non-stable `M3-CP1-TB-CAND-01`.
- CP1 is NOT ACCEPTED; M2 remains runtime authority at **275/275 + K=0**. Stable totals become **38 events / 14 categories / 24 recurrences**; debt remains **5**.
- CP1 is 4/4, M3 is 5/11, no package 5 is authorized. Exact next is Review/planning-only `M3-CP1-RUNTIME-REPLAN`.

### Changed — M3 CP1 R2 package compile-green after true pre-package gate

- The user explicitly authorized the CP1 local-cap amendment from 3 to **4** while retaining M3's hard cumulative ceiling of **11**. Exact semantic source `9f54c77ae92161226e833cf313bf38e516aa276c` changes only `tests/FieldTransportAtlasTests.cpp` by importing `directional::authority::FieldCycleId`; production atlas blobs remain `0c0dc968672c19887a9d0af2b84fe61056fac21c / 7d50b8567396e79938071dbc3473ec28482a960a`.
- A true external pre-package compile ran before package 4: `32201791916 / 95916966789` compiled only `directional_surface_cell_authority_kernel_tests` on the literal semantic source and passed **91/91**. Mechanics-only result/log artifacts `9347775163 / 9347775370` have outer SHA-256 `99d91c0cbcb10abfee2d7ffed42b159e517eb3a6b85b323cc0e13f949f141268 / 1a6d9a5ea7e4ec698da4b0c41ef96dd0ec892e393ac4b5b2d7856b3fe04c175e`; this result is not TB authority.
- Post-preflight source audit reconfirmed the frozen CP1 slice, one-line source delta, unchanged production bytes, and unchanged source-derived independent-oracle semantics. No product/test/build source changed after preflight.
- Full package `M3-CP1-CB-R2` ran as `32201987864 / 95917547662` on the identical literal source SHA. Authority-kernel preflight was 91/91 and the remaining approved closure 32/32, for **123 build actions**. Result artifact `9347879320` has outer SHA-256 `213cc0dfd06370da71e964271f36e49494bf31633a70c1ae9bfe6bba1b8bcb4a`; log `9347879687` has outer SHA-256 `d5ab6b1f7f771b480277f9d298cd4af71e5174be04bc5c0b2f67c4c1eb021b89`.
- Package verification is **27/27** self-excluding manifest entries across 28 regular files, zero package/archive symlinks, six owner executables, two libraries, five empty source-status snapshots, nine dependency revisions, and a 548-member source archive SHA-256 `68173e8cb0d765debde49086256ea8511175b656908ef68eb24e7b44b9492b45`. `runtimeExecution=false`; no generated test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- R2 temporary state was removed workflow-first then marker for both pre-package (`46b65cfb876ca7ea22cec90bc402a21e52e7ff6b / 6ba2aa3523caba947721cb602a9955d5227f4b67`) and full package (`97884f05154d3fba6aa163fd7b7b88c1ae9f7702 / 057c8bcede001799b6ec4ac4546b9a268647c515`). A runtime-free documentation-source snapshot used only for exact closeout-document transfer ran as `32202383138`; its temporary caller/marker were removed by `74153aa00c194a44dfc8f8096ff95344917a281d / 0021a27c9434cba77d194dfad5549b84026eb8dc`.
- CP1 is now **4/4**, M3 **5/11**, and there is no package 5. This remains compile evidence only: M2 is still the latest accepted semantic runtime authority. Historical stable totals remain **37 events / 14 categories / 23 recurrences**, produced-witness debt **5**. Exact next is immutable `M3-CP1-TB` against source/package `9f54c77ae92161226e833cf313bf38e516aa276c / 9347879320`.

### Changed — M3 CP1 final repair package stops for process replan

- The user-authorized `M3-CP1-CB-R1` consumed CP1 package 3/3 and cumulative M3 package 4/11. Repair revision `86fa44473b05f78e76f1737e33e3a168070efa4a` fixed the reviewed hidden-friend/Eigen diagnostics, strengthened the source-derived oracle/tamper matrix, and preserved production atlas blobs `0c0dc968672c19887a9d0af2b84fe61056fac21c / 7d50b8567396e79938071dbc3473ec28482a960a`.
- Exact marker-source `5ce79f39f60186098c271b5810496d627e6504c2` ran in `32199666445 / 95910558538`. The standalone authority-kernel owner preflight stopped at `tests/FieldTransportAtlasTests.cpp:743` because the newly added `FieldCycleId` map value type was not imported or qualified. Core/pipeline linked; `preflight_exit=1`; the full target set was skipped; no result artifact exists.
- Verified log artifact `9347043139` has outer SHA-256 `20ff3e58f258f82225e9c167a35c41cf9a66fef822775fd87fbfb7fcf3a06ecc`; its sole 15,665-byte activity log has SHA-256 `2f2d0931099d5cbd817cc1aa075c37bab6253bcc8010d4cb9faa8ebb21b21953`.
- `runtimeExecution=false`: no generated binary, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input ran. This mechanics failure adds no runtime regression; stable totals remain **37 events / 14 categories / 23 recurrences**, produced-witness debt **5**.
- Cleanup passed caller-first (`cec9759fa6b07283a5be9f211630690427f7ffbb`) then marker (`c1b747e70ac89048039073832e22ad058c21f928`). Only the three durable workflows remain; trigger/observation/payload directories are absent.
- Independent guidance §6 forbids a fourth CP1 package after another mechanics failure. CP1 is **BLOCKED / NOT COMPLETE / NOT ACCEPTED** at 3/3; exact next is Review/planning-only `M3-CP1-PROCESS-REPLAN`. CP1-TB and CP2 remain blocked.

### Changed — M3 CP1 stops for replan after its second package

- The user-authorized CP0-only cadence exception remains **OMITTED / NOT EXECUTED / NOT ACCEPTED**; final M2 remains semantic runtime authority.
- CP1 package 1 implemented the frozen ten-file A1 atlas/certificate/pipeline boundary at semantic commit `4dad58a66c439c152560cb685f96a178f0902542`. Exact marker-source `cec8dfad2c4aba2330865d5664d7cb873db37a42` compiled/package green in run/job `32192286177 / 95889006356` at **123/123**, `runtimeExecution=false`. Result artifact `9344803199` has outer SHA-256 `79a99a2addc84fd0f004897c08a7e71ca1363c86008d4e3ca4349a4df136ccd8`.
- Package-1 closeout source audit found the frozen contract incomplete: its independent oracle did not cover complete cycles/singularities/admissibility/certificate tampering, explicit source/atlas digests were absent, and the full holonomy signature omitted handle-cycle lifts. The compile-green artifact is therefore not a CP1 acceptance candidate.
- CP1 package 2 revision `c2d6a76337aa2fb6be62ae57b89a202e5f4c2cd9` stayed within three existing slice files and attempted the full digest/oracle/tamper closure. Exact marker-source `d2006209c2be9d6da64afddeb5c99350f9ede0b4` failed compiling `tests/FieldTransportAtlasTests.cpp` in run/job `32194456711 / 95895504105` at step 101/123: two qualified calls could not find the hidden-friend `compose`, and an Eigen `cross()` used dynamically sized row expressions. Core and pipeline libraries linked, but no result artifact was produced.
- Package-2 log artifact `9345461584` has verified outer SHA-256 `1ada8f90d485c40e9e44e16e8d4504108eb9d7a8eda9b25c92d4a8f5d1d50e86`; its sole 20,938-byte `activity.log` has SHA-256 `06bd142dcbdf20991d43c06a6ce8a37d6162b52f2aa04d788830c93aa1d45e4e`.
- No generated Directional runtime, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed in either package. No runtime regression/candidate was observed; historical totals remain **37 events / 14 categories / 23 recurrences**, produced-witness debt **5**.
- Package-2 cleanup passed caller-first (`62323b7ad895c62142ba16ad03efc79eabbfd424`) then marker (`af93d376f50104bfde6274416fa1250364687554`). Only the three durable workflows remain, with no connector trigger, observation, or payload directory.
- CP1 has consumed its frozen **2/2** package allocation and is **BLOCKED / NOT COMPLETE / NOT ACCEPTED**. Exact next is Review/planning-only `M3-CP1-REPLAN`; CP1-TB and CP2 remain blocked.

### Changed — M3 CP0 authority census frozen and runtime-free package completed

- `M3-CP0-CB` completed without M3 semantic production/test implementation. Added `Architecture_M3_CP0_Authority_Census.md` and retained Code + Build report.
- Frozen the 457-blob predecessor inspection, 173-file review corpus, 21-file semantic count surface, current A1/A2a/A2b representation classifications, missing contracts, and exact ten-file CP1 vertical slice.
- Defined the conservative `FieldTransportAtlas` / `FieldQuadrangulabilityCertificate` boundary and independent factory-free tamper oracle. The Shen gcd condition is treated as sufficient, not necessary; boundary components require their own constructive relative witness.
- Split CP3 into CP3a combinatorial tracing and CP3b contact/event graph. `M3-CP3b-TB` now owns the explicit trace/decomposition composition proof.
- Declared a hard 11-package M3 ceiling: CP0 1; CP1/CP2/CP3a/CP3b/CP4 2 each, with no third checkpoint attempt and no package 12.
- Runtime-free compile/package authority is exact source/artifact `f51b7d7fc5b63c9efeeffabdf286a897119d75d9 / 9343406869`, run/job `32188666437 / 95878012079`. Eight approved targets completed **121/121** Ninja steps; `build_exit=0`; `compile_status=0`.
- Result/log artifacts are `9343406869 / 9343407254` with outer SHA-256 `edf7be6e739cc769758f232b4f9dafc36018de6935e91788965423be35e5c7e4 / bfbad6d15b70373fc425954ba361f57ba97aa21bef535c7d2d11cd0399310f96`.
- Package integrity passed at **25 manifest entries / 26 files**, zero symlinks, five clean status snapshots, nine dependency revisions, all six owner executables and both libraries. `runtimeExecution=false`; no generated Directional binary, test, discovery, benchmark, or custom input executed.
- Cleanup order passed: temporary workflow removed first (`e6495b881eee227c03414709a680d46fae180b1a`), trigger marker second (`0952f76fe58317b68c023050bf46f9021815cc40`). Only the three durable workflows remain.
- No runtime regression/candidate was observed; historical totals remain **37 events / 14 categories / 23 recurrences** and produced-witness debt remains **5**.
- Exact next turn is artifact-only `M3-CP0-TB` under `Architecture_M3_CP0_Code_Build_Report.md`. CP1 remains unauthorized until that census gate accepts.

### Changed — M2 closure verified and consolidated; M3 plan reviewed

- Documentation-only Review turn. No production, test, or build change.
- **M2 closure verified and upheld.** Branch head byte-identical to accepted source `9fda64e8…`; gate `32183306224 / 95861164621` at **275/275** with static **K=0** — eight products closed, direct semantic context references zero, CP3 forbidden reads zero.
- **Both prescribed CP4 remediations landed exactly.** `RemeshPipeline.cpp:11532` now uses `std::find_if` and publishes `surfaceCellFirstInvalidProducerCell` **after** `reject_merge_authority` — the ordering matters, since that helper resets diagnostics and an earlier assignment would have been silently wiped. The rail witness is stronger than specified: proven grid substrate, `incidentFaces = {-1}` retained as the mutation, and assertions pinning both the typed `InvalidFeatureEdge` kind and `failedEdgeIndex == 0`.
- **`M2_Closure_Record.md` created**, consolidating and retiring the M2 plan, the CP4 TB report, and the fixture-authority inventory. The inventory's live remainder — three latent sites, the un-removed `= {}` generator, and the ungated-file idiom — is preserved in its section 6 and carried into `TODO.md`.
- **Durable documents trimmed.** `REORIENTATION_PLAN.md` section 6 reduced to a closure pointer; milestone table now M2 complete, M3 active; the retry-budget line records M2's **actual 11 packages** rather than the nominal ceiling. `TODO.md` rewritten forward-looking around M3.
- **M3 plan independently reviewed — correctly aligned and adequately decomposed.** Verified clean on the defect that cost M2 a cycle: `FieldTransportAtlas`, `FieldQuadrangulabilityCertificate`, `FieldAlignedCurveNetwork`, and `GlobalTopologyPlan` have **zero occurrences** in `src/`, `include/`, `tests/`, so "introduce" is the correct verb.
- **Three gaps recorded for CP0 to close before CP1.** (1) The **A1 certificate construction and independent tamper oracle** is an open design-backlog item that plan sections 2 and 3 already depend on — building against an undefined certificate is the criterion-5 shape that cost M1 two corrections. (2) The **composition-validation obligation** — `DESIGN.md` warns sound ingredients do not compose into a sound composite, CP3 implements exactly that composition, and no checkpoint owns the proof. (3) **No retry budget is declared**, which section 5 requires before work starts. CP3 sizing also likely splits into two domains.
- **Cost-model caveat recorded:** M3 is new capability, not a cutover. M1/M2 re-typed existing behaviour validated against an accepted baseline throughout; M3 has no prior correct behaviour for its new parts, so the domains-per-checkpoint calibration is advisory rather than predictive and a red checkpoint is more likely a design defect than a migration defect.
- Stable totals remain **37 / 14 / 23**; produced-witness debt remains **5**. No runtime evidence claimed.

### Changed — M2 closes at 275/275 + static K=0 after CP4 R1 immutable TB

- Immutable `M2-CP4-TB-R2` `32183306224 / 95861164621` accepts exact semantic source/package `9fda64e88ddc885ce993ff8da3ad6a51765724a4 / 9340456431`. TB result/log `9341623741 / 9341624025` have SHA-256 `a3a2beb4fec4d9576c2539e166c4a268d4e723624ed3ff5b183efbf4d77f7ab1 / 75097ec6cca7c00cacb25904d6aca2c28921dc1b413b9903ae3c63f56cbc2174`.
- Required-green is **275/275 PASS**: frozen M1 **234/234** (19/138/36/41), CP1 **5/5**, CP2 **34/34**, CP4 **2/2**, exact combined selector SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`.
- Independently regenerated static M2 closure is **K=0**: eight closed products, 23 diagnostic snapshot fields, 62 lexical snapshot refs, direct semantic context refs **0**, CP3 forbidden reads **0**.
- Package/source/manifest/status/dependency/owner preflight and postflight package immutability pass. Rebuild, relink, package repair, semantic-source checkout, source/test/fixture mutation, generated discovery, and benchmark execution are all false.
- `PR8-R037 / M2-CP4-R001` is resolved by restoring the accepted failing-patch diagnostic from declared product authority; it remains in historical stable counts. `M2-CP4-TB-CAND-01` is resolved non-stable after the repaired rail witness reaches and passes the typed `InvalidFeatureEdge` rejection seam. No new regression/candidate is observed; stable totals remain **37 / 14 / 23**, produced-witness debt **5**.
- **M2 is CLOSED / ACCEPTED.** Exact next is runtime-free `M3-CP0-CB`, inventory/census + compile only, under `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md`.

### Changed — M2-CP4 R1 bounded remediation compiles green and re-proves static K=0

- After independent `M2-CP4-REPLAN`, the user explicitly authorized one additional bounded CP4 package. Exact semantic source `9fda64e88ddc885ce993ff8da3ad6a51765724a4` changes only `src/pipeline/RemeshPipeline.cpp` and `tests/SurfaceCellREPackageTests.cpp` (**7 insertions / 7 deletions**): the declared-product invalid-completed-patch guard now preserves the offending patch index diagnostic via `std::find_if`, and the CP4 rail rejection witness uses the known-good rectangular grid substrate while retaining `edge.incidentFaces = {-1}` and the strict typed `InvalidFeatureEdge` assertions. No semantic context read, product shape, compatibility alias, validator contract, or frozen assertion was weakened/restored.
- Bounded source-application control `32179683587 / 95849539548` verified exact old/new Git blobs and committed semantic source `9fda64e88ddc885ce993ff8da3ad6a51765724a4`; result/log artifacts `9340305741 / 9340306119`. `runtimeExecution=false`.
- Runtime-free compile/static run `32180027413` completed all eight approved targets at **121/121** with `build_exit=0` and **109/111 ccache hits**. Immutable result/package `9340456431` / SHA-256 `3ea977fae1467952571f7176668a3ba2e8498dcb0e43f9e1968f8012f334fb94`; persistent compile log `9340456763` / SHA-256 `6a3e69d9bd1f5487d035f574e7b8d2e4817bb1969fafaebd5635e49733bf65da`. Five source-status snapshots are clean and the 25-entry recursive self-excluding manifest verifies.
- Static closure job `95850612342` produced artifact `9340415023` / SHA-256 `0f0e18f0f961e5328cf429cd412c983b79ea75e1beaa43405fd9c4f9b6fa1168`: all **8/8** scheduled products remain closed, diagnostic product domains **23**, lexical snapshot refs **62**, direct semantic context refs **0**, CP3 forbidden reads **0**, final M2 static **K=0**. No generated test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Code + Build cannot resolve the runtime records: `PR8-R037 / M2-CP4-R001` remains open stable/recurrence and `M2-CP4-TB-CAND-01` remains open non-stable test-authority pending immutable runtime proof. Stable totals remain **37 events / 14 categories / 23 recurrences**; produced-witness debt remains **5**; latest accepted semantic runtime remains CP3-R1 at **273/273**.
- The explicitly authorized eleventh M2 package is consumed. Exact next is immutable **`M2-CP4-TB-R2`** on package `9340456431`, requiring frozen M1 **234/234** + CP1 **5/5** + CP2 **34/34** + CP4 **2/2** = **275/275** at selector SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b` plus independently regenerated static M2 **K=0**. If TB-R2 misses the full gate, stop/restructure; no twelfth package.

### Changed — M2-CP4 immutable TB passes static K=0 but rejects runtime candidate at 273/275

- Corrected immutable `M2-CP4-TB-R1` `32175491853 / 95836337325` consumed exact source/package `8cd82a63f00bd53aee3c7e01f4bef0c258b21ef3 / 9336162929` with no rebuild, relink, package repair, repository checkout for semantic source, source/test/fixture mutation, generated discovery, or benchmark execution. Result artifact `9338923657` / SHA-256 `8c25a2564b5df7df0fdeaefc3086800fc7f6af720fcb1117802c6ee2b224ff44`; persistent log `9338924194` / SHA-256 `5b46568b2e05323ec7e86ec06966390bd6b44f7387d99f540a91adde35df5b55`. Package outer digest, recursive manifest, exact source metadata, five clean source-status snapshots, and postflight immutability all passed.
- The independently regenerated static M2 closure is **K=0**: all eight scheduled stage result products are closed over typed `ProducerOutcome<Product, Failure>`; the frozen CP0 product-shaped context fields are contained in diagnostic-only `SurfaceCellDiagnosticProductSnapshots`; direct semantic context reads are zero; and the CP3 forbidden-read family remains zero.
- Runtime required-green is **273/275**: frozen M1 authority/producer/completion/validation **19/19 + 137/138 + 36/36 + 41/41 = 233/234**, accepted CP1 **5/5**, accepted CP2 **34/34**, CP4 closed-product witnesses **1/2**. The 275-name non-overlapping selector reconstructs exactly at SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`.
- Stable `PR8-R037 / M2-CP4-R001` is a recurrence of `RP-03 / POLICY_STAGE_STATE_CONFLATION`: the CP4 declared-product invalid-patch precheck correctly replaces the legacy context-shadow read but returns before canonical aggregate identity rebuild and preserves only `AggregateIdentityInvalidPatchMetadata`, dropping the accepted failing-patch index diagnostic (`surfaceCellFirstInvalidProducerCell=-1`). The correction must preserve declared-product authority and exact patch-index diagnostics; restoring context semantic authority is forbidden. Stable totals become **37 events / 14 categories / 23 recurrences**; produced-witness debt remains **5**.
- Non-stable `M2-CP4-TB-CAND-01 / RP-02` is a test-authority fixture-precondition defect: `SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails` throws a DCEL consistency error in its one-triangle `TriMesh::set_mesh` setup before reaching the typed rail-rejection seam, so the new witness is non-evidence rather than an accepted-green product regression. Initial control `32175260213 / 95835604030` also exposed `M2-CP4-TB-CAND-02`, a resolved orchestration-only owner-binary mapping error; authoritative R1 corrected only that mapping.
- CP4 is **NOT ACCEPTED** and M2 remains **OPEN**. Latest accepted runtime authority stays CP3-R1 `0a06127555405abef474af501e2bd09de3320c1b / 9328335558` at **273/273**. All ten currently authorized M2 Code + Build packages are consumed; exact next turn is **`M2-CP4-REPLAN` review/planning-only** to bound the two corrections and decide whether to explicitly authorize an additional remediation package.

### Changed — M2-CP4 Code + Build closes terminal products and packages the final M2 candidate

- Exact semantic source `8cd82a63f00bd53aee3c7e01f4bef0c258b21ef3` completes the CP4 write-side cutover: product-shaped `surfaceCellContext` observations are contained under the explicitly diagnostic `SurfaceCellDiagnosticProductSnapshots`; `RemeshResult` and `SurfaceCellRailBuildResult` publish typed `ProducerOutcome<Product, Failure>` outcomes; downstream/test consumers use the closed product/rejection APIs rather than restored compatibility aliases.
- The compile loop exposed only migration/build-contract defects in the CP4 change surface: the R-E CMake authority marker still named the pre-migration `context.traceNetwork` path; initial terminal wrappers used the closed-outcome symbols through the wrong namespace and one call site lacked its local `crossFieldAccepted`; stale quotient/test consumers still addressed removed open `RemeshResult` payload fields. Each was corrected surgically without weakening an assertion, restoring a semantic context read, or adding a legacy alias. Hosted-runner stalls before configure/compile were treated as infrastructure only and did not change semantic source.
- Final runtime-free compile `32167688494 / 95811322355` checked out exact source `8cd82a63f00bd53aee3c7e01f4bef0c258b21ef3`, configured cleanly, and completed the eight approved targets in **121/121** Ninja steps with `build_exit=0`; ccache recorded **109/111 hits**. Five source-status checkpoints were clean and the packaged recursive self-excluding manifest verified.
- Result/package `9336162929` / SHA-256 `67a776f290e3ab6fe6682138f3ae36184357cf27563e9c2be1e5413824ebfd38` and persistent log `9336163241` / SHA-256 `a99ea905ffc900b2f7d81959d6a3eed4ae4d13071eb52b64631055290c7a3b9e` are the immutable CP4 Code + Build evidence. `runtimeExecution=false`; no generated Directional test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- `M2-CP4-CB` is **COMPLETE / PACKAGE-COMPLETE / COMPILE-GREEN**, but it is not semantic acceptance. Latest accepted runtime authority remains CP3-R1 at **273/273** on `0a06127555405abef474af501e2bd09de3320c1b / 9328335558`. CP4 consumes the final planned package in the effective ten-package allocation; no additional remediation package is authorized. Exact next turn is immutable artifact-only **`M2-CP4-TB`** on package `9336162929`.

### Changed — M2-CP3 TB-R1 accepts declared-product read cutover at 273/273

- Immutable artifact-only `32150796184 / 95755876548` consumes exact R1 source/package `0a06127555405abef474af501e2bd09de3320c1b / 9328335558`. Result/log `9329750748 / 9329751478` have SHA-256 `a663a9f49396ed4c41c6dccba379c12d1b5f4ca09e288faf7c3ff72581754824 / 3f4a36fcfe626ee14814d989ef790478c682cfcc97795ac0f212ed837a816d98`; package outer digest, recursive manifest, exact source, clean status snapshots, owner blobs, and postflight immutability all pass.
- The three formerly red frozen counterfactual contracts pass explicit focused **3/3** and then pass again inside M1 producer **138/138**. Full required-green is frozen M1 **234/234** + CP1 **5/5** + CP2 **34/34** = **273/273 PASS** at combined selector SHA-256 `91f4b470fefffa162d15a0a216a4bbe7d9e044f5525461dd780280c9bd0f5dbb`.
- CP3 static read elimination remains green with `forbiddenRemaining=0`; 31 remaining aggregate component-context refs are diagnostic/memory or explicit shadow guards. The counterfactual seam is now the declared `SurfaceCellComponentStageProducts` consumed by aggregation; no context-to-product semantic backflow or assertion weakening is used.
- Boundary remained no rebuild/relink/package repair/source-test-fixture mutation/generated discovery/repository checkout/benchmark. `M2-CP3-TB-CAND-01` is **RESOLVED / NON-STABLE**; no regression was observed, stable totals remain **36 / 14 / 22**, produced-witness debt **5**.
- `M2-CP3` is **CLOSED / ACCEPTED**. `0a06127555405abef474af501e2bd09de3320c1b / 9328335558` is the latest accepted M2 semantic runtime authority; exact next is `M2-CP4-CB`.

### Changed — M2-CP3 R1 counterfactual-authority remediation compiles green

- After CP3 TB rejected the first candidate at **270/273**, the user explicitly authorized one bounded remediation package. Exact compiled source `0a06127555405abef474af501e2bd09de3320c1b` migrates `ComponentAggregationInputMutator` from `RemeshResult &` only to the exact declared `SurfaceCellComponentStageProducts` sidecar consumed by disconnected aggregation. All 11 existing counterfactual callbacks use the new signature; exactly the three rejected frozen contracts mutate declared stage-product authority. No production consumer reconstructs semantic products from `surfaceCellContext`, and no frozen assertion was weakened or deleted.
- Runtime-free compile `32147101079 / 95743427238` completed the seven approved targets at **117/117**, `build_exit=0`. The fixed compiler cache key restored exactly; ccache was **95/108 hits**, **13/108 misses**.
- Result/package `9328335558` / SHA-256 `8f75d835e4461ba1dabda91793a88f265e9c00de752a17ec8906943f70f9ced2` and persistent log `9328336222` / SHA-256 `687d395877d92f940cd4f1dd477846ffcc5b6a1f31d39c2546044ea32140a04b` passed exact-source, recursive manifest, source archive, five clean source-status snapshots, and command-boundary verification. `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- A doubled callback-close punctuation error introduced by the static source transform was detected and corrected before the compile/package attempt by runtime-free control `32146707321 / 95742099492`; no package was consumed by that pre-build correction.
- Compile success is not semantic acceptance. Latest accepted runtime remains CP2 at **273/273**; tracker candidate `M2-CP3-TB-CAND-01` remains open/non-stable pending immutable `M2-CP3-TB-R1`. Exact next is artifact-only package `9328335558`; CP4 remains blocked. Stable totals remain **36 / 14 / 22** and produced-witness debt remains **5**.

### Changed — M2-CP3 TB rejects candidate at 270/273 on unmigrated counterfactual authority seam

- Immutable artifact-only `32139341913 / 95718023464` consumes exact `dc837f7ac529c55aa7ba4775621e3b681f74d36b / 9322254546` with result/log `9325322211 / 9325322646` (`db12e52c5b6236c9db1e823ef93988d94b0cd0fae13b9bd961231795a6caa9bd / 2e78d926ffc24d4881064428db4d1ad7175aeff7ce30347575d404fcb77360b7`). Package/source/manifest immutability passes; rebuild/relink/package repair/source-test-fixture mutation/generated discovery/repository checkout/benchmark are all false.
- CP3 static read elimination remains green (`forbiddenRemaining=0`, 31 remaining component-context refs classified diagnostic/memory or explicit shadow guards). CP1 is **5/5**, CP2 **34/34**, and frozen M1 is **231/234**, giving **270/273** required-green.
- The three reds are `SurfaceCellAuthorityContractCutover.DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches`, `SurfaceCellAuthorityContractCutover.AggregateIdentityRebuildReportsInvalidPatchMetadataSubInvariant`, and `SurfaceCellAuthorityContractCutover.FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing`. They were green in accepted CP2. CP3 moved aggregation semantics to `ComponentRun::stageProducts`, but the frozen `ComponentAggregationInputMutator` still mutates only `RemeshResult`/legacy context after sidecar capture, so the negative injections no longer target the authority production aggregation consumes.
- Tracker candidate `M2-CP3-TB-CAND-01` classifies this as **TEST-AUTHORITY / MIGRATION-SEAM / NON-STABLE PENDING AUTHORIZED REMEDIATION**. Stable totals remain **36 / 14 / 22**; produced-witness debt remains **5**.
- CP3 is **NOT ACCEPTED** and CP4 remains blocked. A truthful counterfactual-seam remediation requires an additional Code + Build package, so execution is blocked until the user explicitly reopens the M2 package ceiling. No test weakening or context-to-stage-product semantic backflow is authorized.

### Changed — M2-CP3 semantic context-read cutover compiles green

- Exact semantic source `dc837f7ac529c55aa7ba4775621e3b681f74d36b` (`RemeshPipeline.cpp` blob `922f50a9ffaf797f469803fbf87b9ba3387eedab`) moves production semantic consumers from mutable `surfaceCellContext` state to declared local/component stage products. Context writes remain only for the CP4-owned cleanup surface; diagnostic/memory reads and explicit shadow-integrity guards remain intentionally.
- Post-transform static census `32130834052 / 95691389992` inspected the exact source, reported `forbidden_remaining=0`, and executed no generated runtime.
- Runtime-free compile `32131095060 / 95692198141` built the seven approved targets through the durable reusable compiler and completed **117/117** Ninja steps with `build_exit=0`. Fixed cache key `directional-ccache-Linux-gcc-13.3.0-release-static-pretest-v1` was an exact hit; ccache was **107/108** hits.
- Result/package `9322254546` / SHA-256 `26326fff9ae0c590a4bc7cb03990e265446217c84229d8e99515693d2259658d` and log `9322255075` / SHA-256 `49bb0eb367233b87fd67e8f373c00a9844ad0399a8848c32da18af5dc2bf124f` passed packaged source, recursive manifest, source-status, and command-boundary verification. `runtimeExecution=false`; no generated test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- `M2-CP3-CB` is complete but not semantically accepted. Exact next is immutable `M2-CP3-TB`; CP4 remains blocked. Stable regression totals remain **36 / 14 / 22** and produced-witness debt remains **5**.

### Changed — M2-CP2 TB accepts completion-stage closed products at 273/273

- Final immutable run/job `32119584283 / 95656737849` accepts exact source/package `61273efa3f2f2e6bbfb1592f40a29e3f7b7f4cef / 9316462253`. Result/log `9318077877 / 9318078273` have SHA-256 `53c30fc6265cbe53709b756111fd765611d2c8cb1f3dbecea24ffaf7759fd460 / cdcf7e6dcdd37755747db9efcda7590bfa4a452b1cd9a5c5a9cd85a08aef7c2e`.
- Required-green is **273/273 PASS**: frozen M1 **234/234** (19/138/36/41), accepted CP1 **5/5**, and CP2 **34/34** at selector SHA-256 `53f5bf57a2edb1c68260186b85964022cd034a899a51bcbf740a37d1c4815c0d`. Static closure and package immutability passed.
- Broad changed-block control `32118066037` exposed 12 candidate reds; accepted-CP1 differential `32118624560` reproduced the exact same **12/12** reds on package `9309981828`. They remain inherited/non-gating. No test or fixture was weakened or mutated.
- `M2-CP2-TB-CAND-01/02` are resolved non-stable orchestration/test-authority findings. Stable totals remain **36 / 14 / 22**; produced-witness debt remains **5**.
- Boundary remained no rebuild/relink/package repair/source-test-fixture mutation/generated discovery/benchmark. CP2 is **CLOSED / ACCEPTED**; exact next is `M2-CP3-CB`.

### Changed — M2-CP2 initial Code + Build stops on one test-helper compile omission

- CP2 semantic implementation source `440f6bb4ac662ab9d2f899206e04e2c29b97a082` closes the three planned completion-stage public results over the existing `ProducerOutcome` abstraction, cuts their consumers to typed exhaustive handling, removes the default completion-options argument, and adds the authority-carrying completion test idiom.
- Runtime-free compile run/job `32105325228 / 95613458781` configured successfully and reached **104/117**. `directional_core` and `directional_pipeline` linked; the only observed compile stop is `PatchDescriptorMilestoneETests.cpp:317`, where the new test helper calls `canonicalize_surface_cell_ownership(complex)` instead of the required `(complex, F)`. Build exit `1`; no result/package artifact was produced. Log artifact `9313019727`, SHA-256 `7f7ba3bc8018fabddab3b9ed55d5cef4c6303bcc2acc00c990dd4d528ec9f29e`.
- No generated Directional runtime, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed. This is compile-time test-helper wiring evidence, not a runtime/product regression.
- Exact correction is one test-only argument addition: `canonicalize_surface_cell_ownership(complex, F)`. No retry is executed because the active M2 plan explicitly requires the standing **8-attempt ceiling to be reopened** before any additional Code + Build retry.

### Changed — M2-CP1 TB-R3 accepts CP1 at 239/239; CP2 unblocked

- Immutable R3 source/package `65183336d092d8fe165b6ed4709c4759a0b7fe33 / 9309981828` was accepted by artifact-only run/job `32101777174 / 95603538759`. Result/log artifacts `9311843660 / 9311843967` have SHA-256 `1f7639af848e8eb8432febd54793d2f2e325a3b08b3c645766d9e08ca58aa748 / a79d9351f426b95ede367bad221352519742976a0a886277db18170451a3e182`.
- Exact frozen M1 remains **234/234 PASS** with owner partition **19/138/36/41** and selector `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687`; all five CP1 contracts pass, so the combined gate is **239/239 PASS**.
- `SharedEdgeParityRepairConforminglyCompletesTwoOddCells`, the sole TB-R2 red, now reaches and passes completion after the fixture independently constructs canonical two-face source authority and passes it via `SurfaceCellComplexCompletionOptions::sourceAuthority`. R2 preconditions and strict assertions remain intact; production `include/**` / `src/**` are unchanged from CP1 semantic source.
- Preflight/postflight verified the exact package digest, **24/24** manifest entries, **25** package files, five clean source snapshots, seven-target package, exact R3 test blob, source archive, and `package_mutated=false`. Boundary remained rebuild/relink/packageRepair/sourceMutation/testMutation/fixtureMutation/generatedDiscovery/benchmarkExecution all false.
- No regression was observed. `M2-CP1-TB-R2-CAND-01` is **RESOLVED / NON-STABLE**; stable totals remain **36 / 14 / 22**, produced-witness debt remains **5**. The standard working-branch push-marker + reusable observer path was directly successful for this turn.
- `M2-CP1` is **CLOSED / ACCEPTED**. Exact next turn is `M2-CP2-CB`: completion-stage closed products only; CP3/CP4 remain blocked.

### Changed — fixture-authority omission class scanned repo-wide before `M2-CP1-CB-R3`

- Review/inspection-only turn. No production, test, or build change.
- **Class identified:** an options-struct member carrying mandatory authority defaulted to `nullptr`, reached through an API that defaults the whole options struct — `complete_surface_cell_complex(..., const SurfaceCellComplexCompletionOptions &options = {})` at `PatchDescriptor.h:427` with `sourceAuthority = nullptr` at `:271`, rejected by the strict guard `completion_ownership_face_matches_authority` (`PureQuadCompletion.cpp:1223`). This is the **struct-member form** of the class closed at unit 1 as `R-C-CB-01b`, which closed the function-parameter form and explicitly deferred this one as "a different and weaker shape." It was not weaker; it cost two CP1 checkpoints.
- **Inventory:** 10 defaulted authority members across 6 options structs. Completion family is **8/8 authority-unset** — 1 proven live (`PatchDescriptorMilestoneETests.cpp:826`, the R3 target), **3 latent** (`:1220`, `:1260`, `:1811`, defaulted options asserting success, passing only because their complexes never reach boundary-ownership resolution, and none in the frozen 234-selector so nothing gates them), 1 benign negative (`:1244`, pinned to `IncompleteSurfaceCellComplex`).
- **Assessed and cleared:** tracing (121 raw hits), arrangement, optimizer, and validator families are not defects. `SurfaceCellTracingOptions` documents `sourceFaceComponents`/`sourceFaceSheets` as the ingress path from which `sourceAuthority` is constructed; their consumers carry no equivalent strict guard. Raw counts are a candidate set, not a defect count.
- **Structural cause recorded:** only 3 of `PatchDescriptorMilestoneE`'s contracts are in the frozen selector and none is a completion test, so that file's prevailing idiom is authority-free completion and a new gated CP1 contract inherited it. Fixing `:826` alone leaves the idiom intact.
- **Follow-ups scheduled:** a test-support helper making authority-carrying completion options the local idiom (recurrence prevention), and removal of the `= {}` default on the authority-consuming overload so omission stops compiling — a production change, scheduled for CP2/CP4, out of R3's fixture-only scope. The three latent sites are a named CP2 re-check.
- Stable totals remain **36 / 14 / 22**; produced-witness debt remains **5**. No runtime evidence claimed.

### Changed — M2-CP1 TB-R2 preserves M1, reaches completion, and isolates one final fixture-authority omission

- Artifact-only run/job `32092820628 / 95578263202` consumed exact R2 package `9308369859` from source `aba6639a122e7fd9ddb8aeb72138f1c075d01312`; result/log `9309632210 / 9309632882` have SHA-256 `a26a0b9b126f55a8308447175db54786922a08f8ccc16f7a1177ad46d9aebc5 / 727049f36d80bea97dc50778ca9f7d87d45523c50afdb084ea6f74fe2135e307`.
- Frozen M1 remains **234/234 PASS**; CP1 is **4/5**. `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` now reaches completion and performs parity repair, but `complete_surface_cell_complex` rejects with `CompletionOwnershipComponentSheetMismatch` because the fixture's default `SurfaceCellComplexCompletionOptions` does not provide required `SourceTopologyRegions` through `sourceAuthority`.
- The previously red side-fallback witness now reaches the intended rollback-like `Produced` path and passes. No frozen M1 regression or production defect was observed; the sole remaining red is a **test-fixture authority omission**. No stable regression ID/count change is justified.
- Package/source/manifest integrity passed; `package_mutated=false`; no rebuild/relink/package repair/source-test-fixture mutation/generated discovery/benchmark occurred. `M2-CP1` remains unaccepted; exact next is fixture-only `M2-CP1-CB-R3` after repository-wide audit of the same omission class.

### Changed — M2-CP1 R2 fixture-only correction compiles green

- Exact R2 source `aba6639a122e7fd9ddb8aeb72138f1c075d01312` changes only `tests/SurfaceCellREPackageTests.cpp`: the shared-edge parity fixture now supplies a canonical two-face source scope with explicit ownership, preserves boundary vertices 0..5, and exposes `sourceFaces` separately from semantic `sourceFaceScopes` in the local helper.
- Production `include/**` / `src/**` remain identical to CP1 semantic source `3be733a72330ce688013687f11cd3098ed6c849f`.
- Runtime-free compile `32091161263 / 95573431125` built all seven approved targets through `.github/workflows/agent-compile-reusable.yml`, completed **117/117** Ninja steps with `build_exit=0`, and executed no generated Directional binary/test/benchmark/discovery/CLI/GUI/fuzzer/help/version/custom input.
- Result/package `9308369859` / SHA-256 `304f6489e347f8f8ee0bb0a717b823fb477bfdfc54c2c1a84e76b1bc37a34b2e` and persistent log `9308370117` / SHA-256 `95f391908091423b05709171366286768891228fc116e647621c9b70aadac1f8b` passed recursive self-excluding manifest, source archive, exact source commit, five clean status snapshots, and command boundary.
- The trigger lifecycle used the standard two-commit working-branch pattern with reusable observer; no temporary branch was created. Compile success is not semantic acceptance; exact next is `M2-CP1-TB-R2` against package `9308369859`.

### Changed — M2-CP1 TB-R1 preserves M1, exposes two invalid/non-vacuous CP1 witnesses

- Artifact-only run/job `32075576934 / 95527922027` consumed exact corrected package `9302765681` from unchanged CP1 semantic source `3be733a72330ce688013687f11cd3098ed6c849f`.
- Frozen M1 is **234/234 PASS**; CP1 is **3/5**. `SharedEdgeParityRepairConforminglyCompletesTwoOddCells` reproduces `MissingCellSourceScope` on the accepted M1 package as well as CP1, so the fixture is inherited-invalid for the intended completion witness; `SideRepairNonconvergencePublishesConsumableRollbackProduct` aborts on `ownership-registry-mismatch` before `repair_surface_cell_sides` reaches the fallback branch, so it is non-vacuous failure evidence rather than product failure evidence.
- No stable product regression is observed. `M2-CP1-TB-CAND-01` is resolved as a packaging/orchestration finding after corrected package availability; new candidate findings `M2-CP1-TB-CAND-02/03` are non-stable test-authority defects pending fixture-only correction.
- No rebuild/relink/package repair/source/test/fixture mutation/generated discovery/benchmark occurred. Exact next is fixture-only `M2-CP1-CB-R2`; production CP1 semantics remain frozen.

### Changed — M2-CP1 package completeness corrected without semantic source change

- `M2-CP1-TB` preflight proved initial package `9300782872` cannot execute the frozen M1 gate because `directional_surface_cell_authority_kernel_tests` is missing: exactly **19/234** identities are unrunnable. No generated Directional runtime or discovery/listing was executed; this is pre-semantic packaging evidence, not a code regression.
- `M2-CP1-CB-R1` recompiles **unchanged semantic source** `3be733a72330ce688013687f11cd3098ed6c849f` through the durable reusable compiler with the missing owner target included. Run/job `32074026365 / 95523174425` completed **117/117** Ninja steps with `build_exit=0` and `runtimeExecution=false`.
- Corrected result/package `9302765681` / SHA-256 `3d61880290415f9c2a4e6d635b00064ca15cb34b11262f65335005293e84c66f` and persistent log `9302765964` / SHA-256 `123b14ba9d711b0dc99f2d655ad4fb50c30de74288c492471e0dfacaf2f30dc3` passed recursive manifest, exact source, five clean status snapshots, seven-target inventory, and command-boundary verification. All four frozen-selector owner executables are packaged; frozen selector remains 234 / `dd8ba17ccf67fd3d184ae87272b97028e1debf70b00eab262c3a2aae812de687`.
- Compile success is not semantic acceptance. Exact next is immutable `M2-CP1-TB-R1` consuming corrected package `9302765681`; CP2-CP4 remain blocked.

### Changed — M2-CP1 closed repair-product candidate compiles green

- Exact semantic source `3be733a72330ce688013687f11cd3098ed6c849f` generalizes the existing `ProducerOutcome` over failure type without adding a parallel wrapper, closes the three CP1 repair products (`SurfaceCellSubdivisionResult`, `SurfaceCellParityRepairResult`, `SurfaceCellSideRepairResult`), and migrates immediate consumers to typed exhaustive handling. A rollback-like side nonconvergence that remains consumable is represented as `Produced`, not recovered from text or a legacy success flag.
- Five focused CP1 contract tests were added/adjusted to prove subdivision production, parity production, side rollback production, typed rejection without payload, and unchanged phase-front semantics; no runtime was executed in the Code + Build turn.
- Final runtime-free compile `32068329967 / 95505511477` built the six approved targets in **115/115** Ninja steps with `build_exit=0`; ccache recorded **106 hits / 1 miss**. Package/log `9300782872 / 9300783399` have SHA-256 `12b5df2e4653e0f3aa2179b231ac6ebc419a2a6dfacd1b297ba536e6e746bf0e / 10414bc8eae0f4badfaadd4dba86c261af0de865403e3826b5efe4076baa405d`. Manifest verification and all source-status snapshots are clean.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed. Compile success is not semantic acceptance; exact next is immutable artifact-only `M2-CP1-TB` on `9300782872` plus frozen M1 234-selector.

### Changed — M2-CP0 TB accepts frozen census; corrects CP1 premise before implementation

- `M2-CP0-TB` consumed immutable runtime-free result/log `9297625996 / 9297626384` from exact source `79f078cd33db031269ed47d779872da24712f4e5` with no rebuild, relink, source/test/fixture mutation, generated Directional binary execution, or benchmark execution.
- Independent artifact-only reconstruction exactly matched both frozen candidate sets: stage results **33 found / 33 classified / K=8**, context mutations **290 found / 290 classified / K=62**. Deferred-blocker exposure remains none; stable totals and produced-witness debt are unchanged.
- TB found one **planning mismatch** before CP1 code: accepted `ProducerOutcome<T>` already exists but hard-codes `SurfacePhaseFrontFailure`, so CP1 must generalize that existing abstraction over failure type before using it for repair products. This is `M2-CP0-TB-CAND-01`, non-stable and resolved by updating the plan; no product regression is recorded.
- `M2-CP0-CB` and `M2-CP0-TB` are complete. Exact next is `M2-CP1-CB`; no CP2-CP4 or deferred-blocker work is authorized.

### Changed — M2-CP0 frozen census packaged; M2 implementation not yet started

- `M2-CP0-CB` inspected exact semantic source `79f078cd33db031269ed47d779872da24712f4e5` without product/runtime execution. Frozen stage-result surface is **33 found / 33 classified / K=8**, covering the eight cross-stage products allocated across CP1, CP2, and CP4. Frozen context-mutation surface is **290 found / 290 classified / K=62** semantic mutation sites across **23** top-level fields; the remaining **228** are declared product/diagnostic publications or stage-local whole-context resets. No deferred-blocker exposure was found.
- Runtime-free compile `32058370298 / 95473008362` built `directional_core`, `directional_pipeline`, four split frozen-selector owner test targets, and `directional_benchmarks` with `build_exit=0` using `.github/workflows/agent-compile-reusable.yml`. `runtimeExecution=false`; no generated Directional binary/test/benchmark/discovery/CLI/GUI/fuzzer/help/version/custom input executed.
- Immutable result/log artifacts `9297625996 / 9297626384` have SHA-256 `5c54fc3ed998a05eb06dc747783639044bfb3f38b9ac49b750bb6395bab930c22 / b0033674b8627f1739246978f5fa7c35dfbce8ceda147d3ab3d53764dc20910`; package includes exact source archive, recursive manifest, clean source-status snapshots, dependency revisions, configure/build logs, census files, and the required binaries/libraries.
- CP0 compile success is **not M2 semantic acceptance**. Exact next is artifact-only `M2-CP0-TB`, which must independently reconstruct both frozen candidate sets and reject any mismatch before CP1 begins.

### Changed — M1 closes on 234/234 required-green with K=0; M2 unblocked

- Final immutable `M1-FULL-TB` gate `32055365696 / 95464163035` consumed exact source/package `8232216a66020d440e5a6400b61904ca0430b6c1 / 9293593175` with result/log `9295592429 / 9295592776`. All four frozen selector-owner groups pass: authority **19/19**, producer **138/138**, completion **36/36**, validation **41/41**, total **234/234**.
- Static cutover proof passes **K=0** for all eight forbidden-authority domains. The final summary records acceptance criteria **1 through 6 all PASS** after the documented M1 criterion-5 architectural correction: F1/F2 require `Produced` at their actual simplification semantic stage, F3 requires producer `Produced`; later verifier-assigned `Certified` disposition is a forward M7 obligation, not an M1 state the implementation can express.
- `M1_Closure_Record.md` is the durable closure record; it includes the exact criterion mapping, artifact authority, regression/debt ledger, and the corrected non-vacuity/fixture applicability rationale. No legacy behavior was removed and no product output changed in the M1 closeout itself.
- M1 is **CLOSED**; M2 is unblocked. Exact next is `M2-CP0-CB` under `Architecture_M2_Closed_Products_Single_Writers_Code_Build_Plan.md`. Stable regression totals remain **36 / 14 / 22**; produced-witness debt remains **5**.

### Changed — M1-FULL-CB compile-green candidate packaged; immutable M1-FULL-TB is next

- Exact M1-FULL-CB candidate source `8232216a66020d440e5a6400b61904ca0430b6c1` records six retained criterion-5 fixtures as the revised application set: F1/F2 require `Produced` at the simplification semantic stage, F3 requires producer `Produced`; later verifier-assigned `Certified` disposition remains a forward M7 obligation and is not backfilled into M1.
- Runtime-free compile `32049943157 / 95447146667` completed **117/117** Ninja steps across `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, and `directional_benchmarks`; `build_exit=0`; ccache recorded **95 hits / 13 misses**.
- Result/package `9293593175` / SHA-256 `80856361002f568296423374236650645969f85beff19eff3a3faf647c9f70c8ec` and persistent log `9293593561` / SHA-256 `8bf4797f8614268e39ef18f82ea8aee89530fe9a50bd37dd030a525996903a46` passed exact source archive, recursive manifest, five clean source snapshots, dependency revisions, command boundary, and approved-target inventory. `runtimeExecution=false`; no generated Directional runtime, test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version, or custom input executed.
- M1-FULL-CB is compile-complete but **not semantically accepted**. Exact next is immutable artifact-only `M1-FULL-TB` on package `9293593175`; do not start M2 before acceptance.

### Changed — M1 criterion-5 gate corrected to milestone-available semantics

- Review rechecked `REORIENTATION_PLAN.md`, `DESIGN.md`, `M1_Closure_Record.md`, the retained M1-FULL-CB report, the full 234-selector, exact source `b2ba93208f300add446884f8ef5cd30d8f1b7b3d`, and the accepted R-C package/report. The original M1 criterion 5 is **unsatisfiable by construction** in two independent ways: it requires verifier-assigned `Certified`/D0 before M7 defines any disposition product, and it requires a producer disposition for the directly-constructed F1 simplification fixture that has no producer stage.
- The M1 gate is corrected as an architecture amendment, not an implementation workaround: F1/F2 require `Produced` at the simplification semantic stage, F3 requires producer `Produced`; exact-count checks remain unchanged. The stronger verifier-assigned `Certified` requirement moves to **M7**, which is the first milestone capable of discharging it, as an explicit exit criterion and TODO obligation.
- No frozen selector identity is removed or weakened, no production/test/build/runtime source changes, and no acceptance is claimed. M1 remains open pending a fresh compile package and uninterrupted artifact-only full TB under the corrected criteria.
- Resume-critical rule added: a gate criterion applied to a fixture set must name concepts that exist for every member at that member's actual semantic stage; milestone-crossing obligations belong to the milestone that can discharge them.

### Changed — M1-FULL-TB-CAND-01 resolved as unsatisfiable gate; reopen M1-FULL-CB

- Immutable M1-FULL-TB candidate `32031854705 / 95392087424` consumed exact source/package `b2ba93208f300add446884f8ef5cd30d8f1b7b3d / 9285533569`. Result/log artifacts `9287686929 / 9287687545` have SHA-256 `7357b7aed155e2e0c4cf112deab9ab804cfe77a1bc50dfb007365dd38c8c2f70 / 303b3e6144cc07fc88431be454fdc3e7ee377af0a44f29cfbfae2d2d65ae988e`.
- Criteria 1, 2, 3, 4, and 6 pass; the full frozen selector is **234/234**, and static cutover is **K=0** across all eight domains. Criterion 5 is the only failure, and artifact-only diagnostic `32039560638 / 95416273389` proved the implementation exposes no disposition enum/product/string/token at all outside the criterion-5 script, while `REORIENTATION_PLAN.md` schedules D0-D4 disposition for M7. Therefore M1's criterion-5 demand for verifier-assigned `Certified` is unsatisfiable by construction, not a product regression.
- Tracker candidate `M1-FULL-TB-CAND-01` is **RESOLVED / GATE-DESIGN / NON-STABLE**. Stable totals remain **36 / 14 / 22**; produced-witness debt remains **5**. No test or fixture is weakened, and no implementation change is authorized until the criterion itself is corrected at the architecture level.
- M1 remains open. Exact next is `M1-FULL-CB` for an architecture/gate correction that maps M1 criterion 5 to milestone-available semantics while keeping the stronger `Certified` obligation as an explicit M7 exit criterion.

### Changed — M1-FULL-TB candidate passes 234/234 and K=0; criterion 5 blocks acceptance

- Immutable M1-FULL-TB run/job `32031854705 / 95392087424` consumed exact source/package `b2ba93208f300add446884f8ef5cd30d8f1b7b3d / 9285533569`. Result/log artifacts are `9287686929 / 9287687545`, with SHA-256 `7357b7aed155e2e0c4cf112deab9ab804cfe77a1bc50dfb007365dd38c8c2f70 / 303b3e6144cc07fc88431be454fdc3e7ee377af0a44f29cfbfae2d2d65ae988e`.
- Criteria **1/2/3/4/6 PASS** and full frozen selector is **234/234 PASS**: authority 19/19, producer 138/138, completion 36/36, validation 41/41. Static cutover is **K=0** across all eight domains.
- Criterion 5 is **FAIL / undecidable as authored**. Its F1/F2/F3 script explicitly says disposition is unavailable, infers `Produced` from runtime facts, then returns failure because it cannot prove verifier-assigned `Certified`. `DESIGN.md` requires strict fixtures to be D0, while `REORIENTATION_PLAN.md` schedules disposition D0-D4 for M7, not M1.
- No stable implementation regression is evidenced; `M1-FULL-TB-CAND-01` is a non-stable gate-design/architecture candidate pending review. Stable totals remain **36 / 14 / 22** and produced-witness debt remains **5**. M1 is not closed and M2 remains blocked.

### Changed — M1-FULL-CB closes final typed-owner partials and packages full gate

- R-A was 5/5 complete on accepted source `a7fc3a494ebf1eb6914ed5977d43a60b03a455a1`; R-B was 3/3 complete on accepted source `24f439655640b024efb886e6148fe16c759ffdac0`; R-C was 4/4 complete on accepted source `b2ba93208f300add446884f8ef5cd30d8f1b7b3d`.
- M1 final code edge migrated global output support/lineage ownership and optimization provenance off raw semantic face IDs onto typed `SourceFaceId`, cut final producer/materializer/validator consumers to typed authority, and made remaining raw face rows diagnostic/serialization leaves only.
- Final semantic source is exact commit `b2ba93208f300add446884f8ef5cd30d8f1b7b3d`. Static post-migration census found zero forbidden raw-identity semantic patterns across the M1 surface.
- Runtime-free compile run/job `32018743501 / 95353464856` completed **117/117** Ninja steps across `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, and `directional_benchmarks`; `build_exit=0`; ccache recorded **107 hits / 1 miss**.
- Result/package `9285533569` / SHA-256 `fe5b3ec999019d2f91b4f310403149577095dc7b36f067d2943fe73f1db28d43` and log `9285534196` / SHA-256 `4e0defda358b63d64266d8c3b34ebc71bec3eac965569e62b78acfeee08fc0f6` passed recursive manifest, source archive, five clean source-status snapshots, dependency revisions, command boundary, and approved target inventory.
- `runtimeExecution=false`; no generated Directional runtime/test/benchmark/discovery/CLI/GUI/fuzzer/help/version/custom input was executed. M1-FULL-CB is compile-complete but **not semantically accepted**. Exact next is immutable artifact-only `M1-FULL-TB` on package `9285533569`.

### Changed — M1 R-C Product Outcomes completes 4/4 partials; full M1-FULL-CB is next

- **P-CB-01a:** exact source `fc20f91144fa992bba4a34a4cf00c537d6bc0d76`; compile `31996034281`; result/log `9278201278 / 9278201621` (`d50ba5d5b37289c937192798b529ca96533934621406e5120abe752b61f3258fe / 23b986d886f6217beb95425031488432e8478eca396ac79fe0dac962473912d77`). Added typed phase-front `ProducerOutcome`, internal single phase-front writer, typed tracing publication and exhaustive downstream consumption.
- **P-CB-01b:** exact source `d2e857371942033d7ff7c54f458d7d759ec44c1e`; compile `32001126621`; result/log `9279757246 / 9279757611` (`15057696856799103c0acee68b3641d5aba10eae1ccd943af13c7e7e922bc715 / b7ec4a5f7f27d31db09cf1c776198ef734e9d5475970725645633fff7a1d3a03`). Removed default arguments from tracing APIs so production callers must provide explicit source authority; no legacy aliases restored.
- **P-CB-01c:** exact source `fda0bd13c0ddfca61320bcb7b63bc3b31fa7d6f9`; compile `32005669861`; result/log `9281323136 / 9281323512` (`3a0e2b999205d172623471548648876ab0602b6c425194499a05ee67bd80fb368 / 4eb625ca8e25fab99a14623f4dc234f16aa2f680648a730359f897b629d3f5a7`). Tightened frozen tracing tests so explicit authority is required and missing/tampered authority fails closed. Frozen owner slices remain compilable; no test runtime executed.
- **P-CB-01d:** exact source `b2ba93208f300add446884f8ef5cd30d8f1b7b3d`; compile `32011529523`; result/log `9283272908 / 9283273412` (`6d274841fe9cc0e7d0bc4da5e2d82351615d0a84840eaab0da416e590255888e / 9442ead72d134f18d3b25c08bd543496b11a6d3183e9378b506108a39cd2adfa`). Audited and removed the last general tracing overload that still defaulted source authority; retained only explicit `SourceTopologyRegions` entry. Final R-C static contract: one closed phase-front output, one semantic writer, no success/emptiness outcome reconstruction, no default authority ingress.
- All four partials are runtime-free Code + Build only; no generated Directional test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed. The user-authorized R-C partial edge is now complete; exact next is M1-FULL-CB, then full artifact-only M1-FULL-TB before M2 may start.

### Changed — M1 R-B Public API completes three runtime-free partials

- R-B's bounded inventory fixed the public semantic surface at **31** API symbols: **27** approved domain-preserving row/value leaves, **2** approved serialization-boundary adapters, and **2** legacy semantic entry points requiring deletion (`make_source_topology_regions(F, componentByFace, localSheetByFace)` and `build_surface_arrangement(...sourceFaceComponents/sourceFaceSheets...)`). No additional raw semantic surface is authorized.
- `P-CB-01a` removed the public raw `make_source_topology_regions` overload and migrated all production/tests/benchmarks to typed `SourceSurfaceLabels` ingestion; exact source `765112ef4d385d712c9c2b2cfe1163d0a7148389`, runtime-free compile `31974430461`, result/log `9271307315 / 9271307898` (`69a7d64155ad7132718cb142512819dc5245b649c5d4b1f2d04a51233160243f / 9b99bacf0a1b91881be0399a08239d3cf1c16ec7a773d03f9b4c5c7b07f47159`).
- `P-CB-01b` removed the public arrangement raw-label overload, introduced one canonical `build_surface_arrangement(..., const SourceTopologyRegions&, ...)` entry point, and migrated callers to typed authority; exact source `5a38492e2fa9bbe50b88d03f829cfac9c7fc59a8`, compile `31979076197`, result/log `9272759103 / 9272759567` (`f056219b4769218de129eac91f72aeb5da74a818340a2a0d90c40131076dc11d / 398ae7b0baf82b8105d5174183544548df3654923d5e429d8a538bc488043b9bd`).
- `P-CB-01c` re-audited all 31 symbols: the two legacy K entries are now deleted, all 29 approved leaves/adapters remain semantically one-way, and no new raw semantic entry point was introduced. Exact source `24f439655640b024efb886e6148fe16c759ffdac0`, compile `31983393037`, result/log `9274072410 / 9274072877` (`d5e60d6332375045bb521bb8090585683961334ced43117635df35b1e6c6a0dd / 7645ca72328286032cf74f2a14c0c03cbc87bd61b891458d7288ebdb9c8c9bc2`).
- R-B is **3/3 partials complete** and semantically unaccepted until M1-FULL-TB. All three partials built only the approved seven targets through the reusable compiler with `runtimeExecution=false`; no generated test, benchmark, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed. Exact successor is `M1 R-C Product Outcomes P-CB-01a`.

### Changed — M1 R-A Internal Semantics completes five runtime-free partials

- **P-CB-01a — canonical authority kernel:** introduced `include/directional/authority/AuthorityKernel.h` plus implementation, migrated source-face → region/component/sheet storage and arrangement ownership to typed authority, and added authority-kernel contract tests. Exact source `46675d180b7d8b7b67692950b4aab57ab66aa77b`; compile `31956183285`; result/log `9265640685 / 9265641021` (`54f5251e50a054ae0bc8f60db85d1a7815294aa6cddf3d06859bef7093698cbf / c1ba1d3fc87c2211a929f6d62683c5d2c990522cb16043d52e218a40c9854328`).
- **P-CB-01b — tracing/FlowRep identity families:** added typed source-entity/trace/rail/FlowRep IDs and migrated semantic identity assignment/storage while preserving explicit row projections at API/diagnostic leaves. Exact source `007d0bc3279776e464396139c40276d56234ce6b`; compile `31961310219`; result/log `9267278282 / 9267278596` (`6cbd77f63847b79018518521739038c76602b20bfbc3991a4412c25dfd9c2348 / 052029e727d449476053bc8c3b4d51614bbf08113655ae88e3408582eb96c061c`).
- **P-CB-01c — completion domain and generated lineage:** migrated completion domain identity and generated-vertex parent/source provenance to typed authority, including all completion validity and lineage consumers. Exact source `8d653208318e5e5223a49abe63ca2d96591027a4`; compile `31965670525`; result/log `9268668087 / 9268668403` (`9021b26d739f87c8b89b98e4b146e7eae3de5181523e1fef8d2c1c8720cf0573 / c3d121e36361990acc48419e808540b81591878c4a81c7127ce683376132b4fc6`).
- **P-CB-01d — transitions, quotient classes, and periodic owners:** migrated transition, quotient, periodic relation, and canonical quotient ownership to typed authority without changing physical transition algebra. Exact source `6af87c665c108847f78229653023f48023a9f9ba5`; compile `31970025102`; result/log `9269978752 / 9269979254` (`f0af3e8014032e182a9749024235da3512401097d8c899743d18d4cc0b5c67e0 / ece9c767def908206509321bba5037ac8832f75a71b73704f14735cb3ee2f9549`).
- **P-CB-01e — terminal output support/lineage:** migrated final output face support, generated output lineage, optimization provenance, and final source-authoritative validation owners to typed authority; exact source `a7fc3a494ebf1eb6914ed5977d43a60b03a455a1`; compile `31974548353`; result/log `9271346569 / 9271347000` (`e0f51249425beb37df355646303933afcde630278091c87c61045a1da9cf25462 / c34c7b306362f659b85454b95c17693349363eeea5358ff431c84cdf37af5f84`).
- All five partials were compile/package-only with `runtimeExecution=false`; no generated tests, benchmarks, discovery/listing, `ctest`, CLI/GUI, fuzzer, help/version commands, or custom input were executed. R-A is complete at the compile boundary and remains semantically unaccepted until the final M1 full TB. Exact successor is `M1 R-B Public API P-CB-01a`.

### Changed — M1 R-A Internal Semantics P-CB-01c completes typed completion-domain and lineage identities

- Exact source `8d653208318e5e5223a49abe63ca2d96591027a4` extends the M1 R-A typed-authority migration from tracing/FlowRep into the completion surface: `SurfaceCellDomainId` replaces raw completion domain indices, generated vertices carry typed `SourceFaceId` parents, and canonical surface point / `PureQuadVertexSource` source-face identity is typed. Completion ownership validation, provenance audits, and lineage propagation consume those typed identities directly.
- Runtime-free compile `31965670525 / 95202247940` built the seven approved targets through the durable reusable compiler and completed **117/117** Ninja steps with `build_exit=0`; ccache was **102/108 hits**, **6/108 misses**.
- Result/package `9268668087` / SHA-256 `9021b26d739f87c8b89b98e4b146e7eae3de5181523e1fef8d2c1c8720cf0573` and persistent log `9268668403` / SHA-256 `c3d121e36361990acc48419e808540b81591878c4a81c7127ce683376132b4fc6` passed recursive self-excluding manifest verification, five clean source-status snapshots, exact source archive, dependency revisions, configure/build logs, and command-boundary verification.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Source scope was bounded to `AuthorityKernel.h`, `SurfacePoint.h`, `FlowRepStrands.h`, `PureQuadCompletion.h/.cpp`, `PatchDescriptor.h/.cpp`, `RemeshPipeline.cpp`, `SurfaceCellProductOracle.cpp`, and directly affected frozen owner tests. No R-A-01d transition/quotient migration or R-A-01e terminal output-support migration leaked into this partial.
- This partial remains semantically unaccepted until the final M1 full TB; exact successor is M1 R-A P-CB-01d.

### Changed — M1 R-A Internal Semantics P-CB-01b completes typed tracing/FlowRep identity families

- Exact source `007d0bc3279776e464396139c40276d56234ce6b` extends the M1 R-A typed-authority kernel from source-face region identity into tracing/FlowRep semantic families: `SurfaceCellRail::id` and rail references use `HardRailId`, trace identity uses `SurfaceCellTraceId`, FlowRep arc identity uses `FlowRepArcId`, and source-entity canonical identity is a typed value rather than a raw row/index convention.
- Runtime-free compile `31961310219 / 95189093593` built the seven approved targets through `.github/workflows/agent-compile-reusable.yml` and completed **117/117** Ninja steps with `build_exit=0`; ccache was **104/108 hits**, **4/108 misses**.
- Result/package `9267278282` / SHA-256 `6cbd77f63847b79018518521739038c76602b20bfbc3991a4412c25dfd9c2348` and persistent log `9267278596` / SHA-256 `052029e727d449476053bc8c3b4d51614bbf08113655ae88e3408582eb96c061c` passed recursive self-excluding manifest verification, five clean source-status snapshots, exact source archive, dependency revisions, configure/build logs, and command-boundary verification.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Source scope was bounded to `AuthorityKernel.h`, `SurfaceCellTracing.h`, `FlowRepStrands.h`, `SurfaceArrangement.h`, `SurfaceCellTracing.cpp`, `FlowRepStrands.cpp`, `SurfaceArrangement.cpp`, `RemeshPipeline.cpp`, direct consumers, and affected frozen owner tests. No R-A-01c completion-lineage migration or later R-A work leaked into this partial.
- This partial remains semantically unaccepted until the final M1 full TB; exact successor is M1 R-A P-CB-01c.

### Changed — M1 R-A Internal Semantics P-CB-01a introduces canonical typed authority kernel

- Exact source `46675d180b7d8b7b67692950b4aab57ab66aa77b` introduces `include/directional/authority/AuthorityKernel.h` / `src/authority/AuthorityKernel.cpp`, the one typed authority kernel named by the M1 plan. `SourceFaceId`, `SourceComponentId`, `LocalSheetId`, `SourceTopologyRegionId`, `SurfaceCellDomainId`, `GeneratedLineageId`, `HardRailId`, `SurfaceCellTraceId`, `FlowRepArcId`, `SurfaceCellOccurrenceId`, `TransitionClassId`, `QuotientClassId`, `PeriodicRelationId`, and `OutputSupportId` are now explicit distinct semantic identity domains instead of interchangeable raw ints.
- `SourceTopologyRegions` now lives in the authority kernel, and source-face-to-component/sheet/region mappings store typed identities. `SurfaceArrangementCell` carries a typed domain ID; region/component/sheet compatibility and cell-source scope validation consume typed authority directly, with raw rows remaining one-way access/projection leaves only.
- Runtime-free compile `31956183285 / 95173249097` completed **117/117** Ninja steps across the seven approved targets with `build_exit=0`; ccache recorded **87 hits / 21 misses**.
- Result/package `9265640685` / SHA-256 `54f5251e50a054ae0bc8f60db85d1a7815294aa6cddf3d06859bef7093698cbf` and persistent log `9265641021` / SHA-256 `c1ba1d3fc87c2211a929f6d62683c5d2c990522cb16043d52e218a40c9854328` passed exact source archive, recursive self-excluding manifest verification, five clean source-status snapshots, dependency revisions, configure/build logs, and command-boundary verification.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- This is **partial 1/5** of M1 R-A and remains semantically unaccepted until the final M1 full TB. Exact successor is M1 R-A P-CB-01b; no Test + Benchmark may intervene on this user-authorized partial edge.

### Changed — M1 R-A Internal Semantics compile plan split into five bounded partials

- The previously planned one-turn M1 R-A Internal Semantics unit is too large for one Code + Build turn. It is now explicitly split into five sequential partial Code + Build turns: `P-CB-01a` typed authority kernel/region identity, `P-CB-01b` tracing/FlowRep identities, `P-CB-01c` completion-domain and lineage identities, `P-CB-01d` transition/quotient/periodic ownership identities, and `P-CB-01e` terminal output-support/lineage identities.
- This split is covered by the user's standing partial-CB cadence exception for the exact M1 full-authority task listed in `TODO.md`: only the declared `P-CB -> P-CB` edges may omit intervening TB, every partial remains runtime-free and semantically unaccepted, and no later M1 unit may start before all five R-A partials compile cleanly.
- Each partial owns only the named semantic family plus directly affected tests/fixtures/docs, uses the existing durable reusable compile/cache workflow, and must preserve frozen M1 authority behavior without introducing new raw semantic identity domains. Full artifact-only `M1-FULL-TB` remains the first semantic acceptance point for M1.

### Changed — M1-S4-CB compile-green candidate packaged; M1-S4-TB next

- Exact implementation source `d4af2b940bed2bf3d451f279385025b4bb33e3f83` removes legacy public array/vector authority for current cross-stage consumers, retaining only direct row/value accessors and verified container/diagnostic leaves. Completion consumers use source-row accessors into the typed `SourceTopologyRegions` object; optimizer-to-validator seam now passes independent input-derived `SourceTopologyRegions` rather than output-derived `SourceCellOwnershipRegistry`.
- Runtime-free compile run/job `31920545993 / 95066197476` completed **117/117** Ninja steps with `build_exit=0`; ccache was **107/108 hits**, **1/108 miss**.
- Result/package `9254345974` / SHA-256 `6ba220180921423712611aa857d1737879624080e6332b57612942839b901278a` and persistent log `9254346306` / SHA-256 `a0a608f3839306c90b5d0ccd5f4143f387671387564ac508060a74c341d7fd17` passed recursive self-excluding manifest verification, five clean source-status snapshots, source archive, dependency revisions, configure/build logs, and command-boundary verification.
- `runtimeExecution=false`; no generated Directional binary, test, benchmark, discovery/listing command, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.
- Exact next is immutable artifact-only `M1-S4-TB` on package `9254345974`; no M1-S5 or later implementation is authorized before that gate.

### Changed — M1-S3-TB accepts stage-result boundary cutover at 273/273

- Immutable artifact-only gate `31909418131 / 95032193025` consumed exact source/package `cb7e2b48ed50c6420015ac32cad7b73227b4905a / 9250721294` and passed **273/273** required-green: frozen M1 **234/234** + CP1 **5/5** + CP2 **34/34**. Static closure remained green for CP1/CP2/CP3 domains; no rebuild/relink/package repair/source-test-fixture mutation/generated discovery/repository checkout/benchmark occurred.
- `M1-S3-TB` is **PASS / ACCEPTED**. `cb7e2b48ed50c6420015ac32cad7b73227b4905a / 9250721294` becomes the latest accepted runtime authority; exact next is `M1-S4-CB`.

### Changed — M1-S3-CB compiles typed stage-result boundary cutover

- Exact semantic source `cb7e2b48ed50c6420015ac32cad7b73227b4905a` moves stage-result authority to closed `ProducerOutcome` values at the public seam, removes boolean/emptiness reconstruction from consumers, and preserves diagnostics as non-authoritative observation only.
- Runtime-free compile `31906214457 / 95022514178` completed the approved targets with `build_exit=0`; packaged result/log authority is `9250721294 / 9250721625`.
- No generated runtime executed. Exact next is immutable `M1-S3-TB`.

### Changed — M1-S2-TB accepts typed authority migration

- Immutable artifact-only gate `31899452289 / 95001658256` consumed exact source/package `76b8304d63de40119b0859c23560932a0099d6f4 / 9248471449`, passed the frozen predecessor and focused typed-authority contracts, and confirmed static K=0 for the scheduled S2 domains.
- `M1-S2-TB` is **PASS / ACCEPTED**. Exact next is `M1-S3-CB`.

### Changed — M1-S2-CB compiles typed authority migration

- Exact semantic source `76b8304d63de40119b0859c23560932a0099d6f4` introduces the scheduled typed authority identities and migrates the bounded consumer set without changing product behavior.
- Runtime-free compile/package succeeded; no generated runtime executed. Exact next is immutable `M1-S2-TB`.

### Changed — M1-S1-TB accepts single-writer authority cutover

- Immutable artifact-only gate `31890924116 / 94975631668` consumed exact source/package `bf1104757ea1dccadcf679eaac0cb2691c525e35 / 9245682941`, passed frozen predecessor and focused S1 authority contracts, and confirmed no duplicate semantic writer remains in the bounded domain.
- `M1-S1-TB` is **PASS / ACCEPTED**. Exact next is `M1-S2-CB`.

### Changed — M1-S1-CB compiles single-writer authority cutover

- Exact semantic source `bf1104757ea1dccadcf679eaac0cb2691c525e35` cuts the first scheduled duplicated authority surface to one writer, preserves diagnostic mirrors as one-way observation, and compiles the required targets without runtime execution.
- Exact next is immutable `M1-S1-TB`.

### Changed — M1 architecture correction adopted

- `Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md` became the active implementation plan after independent architectural review found the prior milestone decomposition permitted duplicate mutable semantic authority to survive across stage boundaries.
- M1 is explicitly about one semantic authority per fact, typed identities, closed product outcomes, and eliminating mutable cross-stage context reads. Later product work remains blocked until M1 closes.

### Changed — R-C-REV-21 closure accepted

- Independent review closed the final R-C review item after verifying `ProducerOutcome` use, explicit source authority ingress, exhaustive consumer handling, and absence of newly introduced legacy semantic aliases.
- R-C review findings are retained in the independent review/report authority; exact next followed the M1 plan.

### Changed — R-C runtime package accepted

- The final R-C package passed its immutable artifact-only gate; focused contracts and frozen predecessor selectors were green, and no validation weakening was used.

### Changed — R-B closure accepted

- R-B removed the remaining scheduled public raw authority entry points and passed its immutable validation gate.

### Changed — R-A closure accepted

- R-A completed the typed authority migration across the planned internal semantic families and passed the corresponding immutable runtime gate.

### Changed — M1 reorientation plan adopted

- `REORIENTATION_PLAN.md` was updated to make single semantic authority, typed identity, closed products, and stage-local ownership prerequisites for later surface-cell production work.

### Changed — Gate 4 review incorporated

- The Gate 4 topology-region design review was incorporated into the active architecture, including source-authority requirements, quotient/periodic ownership obligations, and deferred blocker ledgers.

### Changed — regression audit normalized

- `Regression_Root_Cause_Tracker.md` and `PR_8_Regression_Audit_Inventory.md` were normalized around stable event/category/recurrence counts while retaining candidate/non-stable findings separately.

### Changed — direct surface-cell path remains fail-closed

- Direct `SurfaceCells` requests continue to fail rather than silently executing the legacy integer backend when direct production cannot establish the required invariants.

### Changed — source-grid recovery made explicit and default-off

- Source-grid recovery is default-off and cannot satisfy direct production acceptance unless a future gate explicitly authorizes it as a distinct product path.

### Changed — retained evidence and handoff policy established

- Durable project authority, cleanup/retention rules, and mandatory handoff start/end checklists were established under `.agents/Directional/`.
