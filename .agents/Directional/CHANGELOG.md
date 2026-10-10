## 2026-10-10 — `M6-CP3-CB1-ENTRY-R4` typed rail source-incidence incremental Code + Build

Continued R4 under frozen RA-45 without runtime execution. The `rail_interval_refs` producer path now verifies ordered source-vertex incidence, exact source-edge topology and exact sample-corner support for published typed rails. A negative compile-visible test was added. First compiler attempt `38076875551` failed solely on two `DomainResult` arrow expressions; corrected with `.value().index()` and applied as semantic commit `aab8e22c1a997ffcca72cc42a13df51bf0e4d29b`. The corrected eight-target compile `38077156162` / artifact `11679541934` is GREEN, 28/28 manifest valid, GMP/GMPXX linked and `runtimeExecution=false`. This is NOT RA-43.4 completion: legacy direct rails still rely on epsilon, source-star terminal germ and multi-carrier sectors remain unproven. R4 remains IN_PROGRESS; frozen CP2/R3 and regression totals unchanged.

## 2026-10-10 — `M6-CP3-CB1-ENTRY-R4` gauge STOP resolved; RA-45 frozen, RA-44.2 withdrawn

Upheld the producer-compatibility STOP on its facts at HEAD `7f4a643d2` and resolved it by withdrawing the
requirement. Established that `sourceFaceBranchRotations` has no absolute consumer: presence-only at
`RemeshPipeline.cpp:7300-7301`, presence plus face identity at `:5613-5630`, and a single difference use
`compose(second, first.inverse())` at `tests/SurfaceCellTransitionQuotientTests.cpp:3152-3153`; Z4 being
abelian, a uniform `+1 mod 4` cancels. RA-44.2's absolute geometric pin is therefore a category error and is
withdrawn, which admits the annular best-fit producer (`SurfaceCellTracing.cpp:13510-13704`) and the curved
root-0 producer (`:15488-15556`) without producer-specific pins. The relational A3 pin already implemented at
`:8038-8080` plus the presence gate at `:8020` is the whole authentication. Reclassified balanced uniform
tamper as a gauge transformation: accept it and require a bit-identical A6 outcome. Added the no-normalisation
constraint because the gauge feeds a provenance digest at `:2134-2144`. Accepted RA-44.1's landed
`SurfaceHardRailTerminalContacts` in shape. Runtime-free: no code, test, fixture, selector, benchmark or build
change in this turn; CP2 491/491 accepted; R3 403/497 rejected; stable 66/17/49 debt 1.

## 2026-10-10 — `M6-CP3-CB1-ENTRY-R4` binding STOP resolved; RA-44 frozen

Accepted both source-authority STOP findings at HEAD `de0f9d4c1`. Withdrew RA-43.5 as vacuous:
`FieldFaceBranchFrame` publishes all four branches (`FieldTransportAtlas.h:728-734`) so `find_frame(face)`
cannot discriminate a +U gauge, and `make` holds no axes to re-derive with. Replaced by a two-part witness —
absolute geometric pin on A4's own `1 - 1e-8` alignment gate (`SurfaceCellTracing.cpp:11034-11054`) with the
axes travelling alongside the gauge, plus a relational A3 pin over `transition_value`; the relation alone is
gauge-invariant under a balanced `+1 mod 4`. Resolved the contact binding as a widening of the existing
`hard_feature_edge_keys_from_rails` reduction (`RemeshPipeline.cpp:9576-9599`, typed conversion `:3064`, rails
already stored `:12173-12179`), rejecting both options the STOP offered as heavier than the facts require.
Closed the absent-gauge hole at `:8015-8020`; ruled rail-less hard-feature fixtures fail closed; kept the
archived rail WIP patch unapplied. Accepted the typed factory rejection propagation at `:12240-12250`.
Runtime-free: no code, test, fixture, selector, benchmark or build change in this turn; CP2 491/491 accepted;
R3 403/497 rejected; stable 66/17/49 debt 1. R4 Code + Build released to continue.

## 2026-10-10 — `M6-DEFN-R5-R4-REV` producer locus resolved; RA-43 frozen

Accepted R4-REV-01A/01B/02A in full against my own prior review, then discharged their producer-proof
remedy from bytes at HEAD `fe372dded`: vertex-star producer `resolve_field_vertex_transit`
(`SurfaceCellTracing.cpp:1257`, star loop `:1452-1476`); `railFanPotentials` struck as never having existed;
terminal-contact owner located in the pipeline stage (`RemeshPipeline.cpp:9328-9356`, exact and
continuity-checked) and therefore relocated to an A4 factory-boundary binding; `sourceEdge` proved a local
corner index (`:5824`, `:5841`); `rail_sample_source_vertex` (`:5820-5844`) recorded as an existing
epsilon-incidence defect; face gauge authenticated per face against
`atlas->branch_topology().find_frame(face)` with the absent-gauge hole at `:8015-8020` closed. RA-41 frozen
scoped to the singleton, junction/sector clauses frozen unexercised. Runtime-free: no code, test, fixture,
selector, benchmark or build change; CP2 491/491 accepted; R3 403/497 rejected; stable 66/17/49 debt 1.
Successor `M6-CP3-CB1-ENTRY-R4`.

## 2026-10-10 — `M6-DEFN-R5-R4-REV` independent RA-42 re-review STOP

Source exact `0bc8080366757a2285a8265599255475ef8525b2`; source snapshot `38046815459`, artifact `11666644778`, 5851/5851 hashes. Found raw, not typed, rail source incidence; false star-traversal source-range citation; HELD R4 plan contradicting unconditional RA-40.1 and still-unproven branch gauge equality. Corrected binding normative descriptions and held plan, documented independent R4-REV-01A/01B/02A STOP. No runtime, code/build/test/selector changes, successor or new stable regression; CP2 491/491 accepted; R3 403/497 rejected, stable 66/17/49 debt 1. RA-42 design remains prospective; R4 Code+Build remains HELD.

## 2026-10-10 — `M6-CP3-R4-TERMINAL-CONTACT-ARCH-REV`: R4-REV-01/-02 resolved as RA-42

Runtime-free independent producer Design Review. **Both blocking findings resolved; frozen as RA-42.** The
review's RA-38.3 boundary-scope ruling is accepted (that STOP governs multi-carrier through-junction sector
transport and does not fire at a terminal contact vertex). No runtime credit; ledger **66 / 17 / 49**, debt 1.

**R4-REV-01.** `SurfaceTracePoint` is `{int face; Eigen::RowVector3d barycentric;}` — no source vertex, no source
edge, and `face` is a raw row index rather than a `SourceFaceTopologyKey`. RA-41.2's witness therefore cannot be
authored from a trace point, and recovering incidence from `barycentric` would mean testing a `double` for exact
zero: RP-01 authority-domain conflation in a pipeline that exactifies binary64 bit-for-bit. It also explains why
`faceEnds=0,2|0,3` was ambiguous — the record is untyped. The authority exists on the rail producer instead
(`SurfaceCellRail::sourceVertices`, `SurfaceCellRailSample::{sourceFace,sourceEdge}`), the fifth occurrence of
the publish/reach pattern after RA-34.3, RA-35, RA-38 and RA-40.

**R4-REV-02 → option (A); the conditional exception is withdrawn.** Its premise that a rail-free product carries
nothing A3-derived is refuted by `sourceFaceBranchRotations`, a raw gauge vector; and the exception would apply
precisely at the production `CrossFieldResult` null-atlas ingress where the 34 failures arise, preserving in
production the hole RA-40 exists to close. RA-40.1 stays unconditional, callers migrate, the seven DCEL failures
are fixture defects to fix rather than exempt, and `sourceFaceBranchRotations` comes inside the boundary.

**Undischarged.** The 39-row family is one carrier configuration with zero multi-carrier instances, so RA-41.2's
junction clauses remain unexercised and R4's multi-carrier STOP stands.

## 2026-10-10 — `M6-DEFN-R5-R4-DIAG-NEXT`: hypothesis disproven; reading (b) verified with exact germs

Next-steps determination. The DIAG audit is correct and my cross-contamination hypothesis is **withdrawn**,
disproven by independently re-deriving `MeshComponents.cpp:72-116` first-encounter local numbering
(`orig->local {...,4:2,...}`), which makes original `(1,4)` into local `(1,2)` with incident faces `{0,3}`. The
diagnostic is faithful; the inventory is internally consistent (33 + 5 MATCH, 1 receiptless).

**All 38 diagnosed rows are one carrier configuration** — original `(1,4)`, `routeLength=1` — so the family
supplies zero multi-carrier instances and R4's multi-carrier STOP is entirely undischarged.

**Reading (b) is now verified on the observed data.** Germs: `star(1)={0,2,3}` cuts to `{0}`/`{2,3}`;
`star(4)` cuts to `{0,1,4}`/`{3,6,7}`. Face 2 is not incident to vertex 4, which forces the end assignment;
both spatial ends then land in opposite germs. So `faceEnds=0,2|0,3` is a correct reciprocal pair under germ
semantics and contradicts only RA-39.1's row-equality at the trace endpoint. The contact walk is one non-rail
step `2 -> 3` across `(1,5)`, after which the contacts are `{3,0}` — the carrier's incident pair. RA-39.1 was
right about the contacts and wrong only in applying equality to trace endpoints.

**Blocking hazard:** vertex 1 is a boundary vertex and RA-38.3 fail-closes on boundary vertices, so correcting
RA-39.1 alone would re-reject all 38 under a different code. Both must land together.

RA-41 stays unfrozen; next turn `M6-DEFN-R5-R4-REV`, then `M6-CP3-CB1-ENTRY-R4`. Ledger 66 / 17 / 49, debt 1.

## 2026-10-10 — M6-DEFN-R5-R4-DIAG: static carrier diagnostic audit

Corrected the R4-next hypothesis that `front=13,131;edge[0]=1,2:faces=0,3` necessarily mixes carrier identity and face incidence. In five component-aggregation cases `(1,2)` is **local** identity for original hard rail `(1,4)`. 38 explicit R3 carried-family carrier records independently match two source-face incidences (21 original `front=17,203`, 12 original `front=13,131`, five compacted `front=13,131`); the 39th has no printed carrier. Actual `faceEnds=0,2|0,3` failure remains unresolved. Audit and 39-row TSV under `Architecture_M6_DEFN_R5_R4_DIAG_*`. RA-41 unfrozen; Review next; no runtime, compilation, production semantics or test changes. CP2/R3 frozen evidence and ledger unchanged.

## 2026-10-10 — `M6-DEFN-R5-R4-NEXT`: RA-41's cited carrier incidence is impossible in the reference fixture

Next-steps determination. R4 accepted as strong — it resolved all three remitted findings, and its **boundary
germ** construction is sharper than Review's reading (b): cutting one incident rail at a vertex yields two
boundary germs even when the one-ring minus that edge stays connected, which is why unrestricted non-rail BFS is
insufficient for a singleton. RA-41.1/.2 correctly held as candidates, not frozen.

**But a load-bearing input is provably wrong.** D2 cites "`front=13,131`, carrier `(1,2)` with rows `{0,3}`".
Re-derived from `tests/SurfaceCellTransitionQuotientTests.cpp:578-591`: edge `(1,4)` -> `{0,3}`, edge `(4,7)` ->
`{4,7}`, edge **`(1,2)` -> `{2}`** — a boundary edge with one incident face. `{0,3}` is edge (1,4)'s incidence,
and edge (1,2)'s sole face is **2**, precisely the anomalous face in `faceEnds=0,2|0,3`. Either that record
belongs to a different fixture (so the incidence is uncorroborated), or the diagnostic mis-reports by pairing one
carrier with another's incidence — which would explain `faceEnds=0,2|0,3` with no semantics change and make
RA-41.2's contact-witness machinery the wrong cure for part of the 39-row family.

The RA-40(C) supplemental `HardRailTransitionNeedsExactlyTwoSourceFaceIncidences` was written to catch exactly
this and remains unexecuted; it is now a candidate first-locus discriminator.

**Determination:** next turn is `M6-DEFN-R5-R4-DIAG`, a bounded runtime-free diagnostic-fidelity audit, then
`M6-DEFN-R5-R4-REV` to freeze RA-41 on a verified observation, then the CB. RA-41 stays unfrozen; ledger
66 / 17 / 49, debt 1.

## 2026-10-10 — `M6-CP3-TB1-ENTRY-R3-REV-ADJ`: R3-REV adjudicated ACCEPTED; three findings remitted to R4

Runtime-free independent adjudication of `M6-CP3-TB1-ENTRY-R3-REV`. **Review ACCEPTED** as complete and
accurate; `REJECT R3 / UNPROMOTED` stands; ledger **66 / 17 / 49**, debt 1, stands. No correction to the
reviewed turn.

**Re-derived rather than accepted.** The 41-rows-to-2-events grouping was challenged and the challenge
**withdrawn** — the tracker's precedent fixes the unit as **root cause**, not ordinal ("do not call cascades new
stable events"; "ten A6/D7 rows are not a new stable event"). Ledger arithmetic is coherent: two causes in
existing categories → events +2, categories +0, recurrences +2. The 47-versus-41 correction is right and
material (47 was the R2 loss, not the R3 accepted-CP2 RED count; recovery scope widens to **88**). RA-40.1 is
sound: `make` binds the atlas and fails closed, and `matchesA3` re-derives via `transition_value` at `:8074`,
`:8147` and `:8232` checking forward and `reverse->transport == expected.inverse()`. The carrier-edge suspicion
**failed**: `transitionValues.push_back` precedes the `hardFeatureEdges` `continue`
(`FieldTransportAtlas.cpp:2041-2048`), so RA-34.3 is correctly implemented. R4's D2 **does** cover the carried
39; the charter is not under-scoped.

**Finding 1.** The singleton case is falsifiable now: by RA-39.6 both endpoint pairs share the one carrier, so
with `(1,4)` owning `{0,3}` the expected record is `faceEnds=0,0|3,3`; observed is `0,2|0,3`, where face `2` is
not a carrier face and both fronts touch face `0`. No correct reciprocal singleton pair can produce it, so D2
becomes a test rather than an investigation.

**Finding 2.** RA-39.1 presumes a front's `from`/`to` faces **are** the rail's side faces, but they are
`SurfaceTracePoint` curve endpoints (`SurfaceCellTracing.h:1514-1515`) and no frozen definition relates them to
rail sides — the same class of error as superseded RA-36.1, identity frozen where only connectivity is
warranted. Remitted, not amended, consistent with RA-36.1's handling; R4 must resolve whether RA-39.1 is right
(front construction at fault) or too strict (attachment is side membership) and freeze the contract.

**Finding 3.** RA-40's blanket atlas mandate is RP-01 authority-domain conflation where a product carries no
A3-derived value; scoping preserves the whole anti-tamper property and creates no unauthenticated-but-accepted
mode. Conditional pre-commitment only, after typed stage/error propagation; null-atlas acceptance for products
carrying rails or route certificates stays prohibited; `sourceFaceBranchRotations` must not be silently exempted.

## CURRENT — 2026-10-10 independent Review `M6-CP3-TB1-ENTRY-R3-REV`: R3 REJECTED

**Review verdict: R3 candidate is REJECTED / UNPROMOTED, but artifact-only execution is mechanically valid.** Frozen 497 fresh processes: **403 PASS / 94 RED** (30:15/15, 12:10/2, 449:378/71, 6:0/6); 1019/1019 result checksums and 497/497 individual log hashes independently verified; no test skipped or rebuilt. Exact source `d82e34427adc6fe09ad216a4363fea23dd0ae0b8`; runtime `38030196207`, artifact `11661044443`, SHA256 `555b973a69810f95a2f170fdea30aac11c0805ba7e25bc9914577bdd1bb26ac5`. **53/53 historical R2 RED remain RED, zero recovered; 41 additional accepted CP2 tests turn RED, making 88/491 accepted CP2 identities RED in R3** (47 R2-carried + 41 new). The prior 94-row EXEC report incorrectly tagged these 41 as `CP2_ACCEPTED=false`; its historical file is preserved, with a distinct independent 94-row corrected overlay. New accepted-loss families: 34 A4 publication/authority ingress failures (`R3-REV-NEW-01`) and seven synthetic mesh DCEL fixture exceptions (`R3-REV-NEW-02`); first rejected predicates observed, exact algorithmic roots not yet proven. Stable events now **66 / 17 / 49** (two grouped new recurrences), debt **1**. CP2 **491/491** remains latest reviewed accepted candidate; R3 may not be promoted. The 39 carried R2 rail endpoint errors are not counted a second time. Four RA-40(C) supplemental tests remain unexecuted and excluded from 497.

**Review authority:** `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Independent_Review_Record.md` and `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv`. **Authorized successor only after final COMPLETE beacon:** `M6-DEFN-R5-R4` Definition, plan `.agents/Directional/Architecture_M6_DEFN_R5_R4_Recovery_Definition_Plan.md`; independent R4 Definition Review required before any Code + Build. No new implementation, runtime, benchmark, promotion, selector alteration or fake A3 atlas is authorized in this Review.

---

## CURRENT authoritative RA-40 Code + Build result — 2026-10-10 06:02Z

**COMPLETE / compile GREEN / runtime unexecuted** for `M6-CP3-CB1-ENTRY-R3`, pending durable docs push and final root STATUS beacon. RA-40 A/B/C Review completed; exact source `d82e34427adc6fe09ad216a4363fea23dd0ae0b8` includes five-file source-attested A3 factory/11-caller migration patch `7de636c88fe6ad8c4f09c1956161f56f88995785` and one-file fixed-size Eigen test-helper correction. Initial eight-target compile `38028700056` failed on dynamic `.cross()` Eigen static assertion; corrected compile **run `38029281891` succeeds** (`compile / compile` job `114146685417`), immutable result artifact **`11661566000`** outer ZIP SHA-256 **`18591009acf98b4c6ea996bc4bb1445959bbd49b1f96cc78327caacfb302ac95`**, internal **28/28 SHA256SUMS**, metadata `source-commit.txt` exact match, `preflight-exit-code=0`, `build-exit-code=0`, eight approved targets, `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, actual generated linker command contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`. No tests, benchmarks, Directional binaries, or TB harness executed.

**Authorized successor:** `M6-CP3-TB1-ENTRY-R3-EXEC` — distinct artifact-only frozen 497-process TB; four supplementary RA-40(C) tests must be separately scheduled and counted with diagnostic-only weight; do not merge into 497. Organic produced witnesses, historical R2 first failures, and 47 accepted→RED restorations remain entirely unverified until TB; no promotion or test pass claim. Any prior local entries below describing the second compile as pending are historical and superseded by this record.

---

## 2026-10-10 — RA-40 source-bound A3 factory patch applied; compile pending

 **Update (2026-10-10 05:58Z):** Initial GMP run `38028700056` failed only on Eigen compile-time vector-size assertion in test `FlowRepStrandsPhase15Tests.cpp:79` (`preflight_exit=0`, `build_exit=1`, `runtimeExecution=false`); one-file typed `Eigen::RowVector3d` correction applied successfully by workflow `38029206658` and semantic commit `d82e34427adc6fe09ad216a4363fea23dd0ae0b8`. Repair patch SHA256 `1cdb28c1c4ac8a1752f8201de3602053a4c10b1a2abcd8a9a2f01f37adb4cb26`; staging retired. Second immutable eight-target compile request event `b94820aaf64ee4c68f670e7c69b49b0f5f50b81a` pinned to `d82e344...`, mailbox `m6-cp3-r3-ra40-eigen-repair-gmp-compile-r2`, terminal result pending. No runtime work.


- Independent A/B/C Review accepted RA-40. `SurfacePhaseFrontProduct::make` now requires source-bound `FieldTransportAtlas` and independently checks both carrier χ and nonrail φ against exact A3 forward/reverse transport, with no unauthenticated overload. Eleven factory test callers migrated and new compiled assertions authored.
- Exact five-file patch SHA-256 `6c88a8fbf674656383bd67a4620bb0791551ea51274e57902aefe3e333ed34eb` applied in successful workflow `38028610928`, semantic commit `7de636c88fe6ad8c4f09c1956161f56f88995785`; Drive patch retired. Mandatory eight-target GMP compile has been requested but not yet verified. `runtimeExecution=false` for patch apply; no tests or benchmarks executed in CB. Frozen 497 unchanged; four supplemental diagnostic cases remain separate; 64/17/47 debt1 unchanged.

## 2026-10-10 — `M6-CP3-R3-ABC-ARCH-REV`: Decisions A, B, C resolved as RA-40; CB1-ENTRY-R3 resumes

Runtime-free independent producer Design Review. **A → factory-bound atlas re-derivation (A2 minimal), A1
rejected. B → CB may close on authoring plus compile, with conditions. C → separately authorized, separately
counted, diagnostic weight only.** Frozen as RA-40. No runtime credit; ledger **64 / 17 / 47**, debt **1**.

**A.** `make` (`SurfaceCellTracing.cpp:7969-7982`) accepts `hardRailFieldTransitions` and
`hardRailRouteCertificates` as unauthenticated data. A balanced `+1 mod 4` on both paths still satisfies
`χ_next ∘ φ_A == φ_B ∘ χ_prev`, because a consistency relation is **gauge-invariant** — consistency can never
substitute for value authentication, the same structural fact recorded for `Z4` at `M5-CP3-DEFN-R1`. A1 would
leave any test or consumer able to manufacture a passing A4 product. A2 needs **no new schema**: the atlas is
already a pointer in options (`SurfaceCellTracing.h:2186`), A4 already derives through `transition_value`, and
`matches_source_faces` (`FieldTransportAtlas.h:893`) already binds it to an exact source — only the factory
boundary lacks it, the fourth instance of the publish/reach pattern after RA-34.3, RA-35 and RA-38. **The hole is
wider than the question asked**: carrier χ is equally unauthenticated, so one binding must cover both φ and χ or
the defect survives one field over. The twelve-call-site migration is a feature — eleven are tests, and a test
that cannot supply a source-bound atlas should not be manufacturing route certificates.

**B.** The plan forbids running binaries in CB and places 497 in a distinct TB, so demanding produced runtime
witnesses or the 47 accepted→RED recoveries at CB closure is unsatisfiable — the identical self-conflicting
precondition resolved at `M6-CP3-CB1-ENTRY-R2` precondition 2. CB closes on authoring plus exact eight-target
compile/package evidence with nonvacuity in **compiled assertions**, claiming no produced positive, naming the
TB successor before `STATUS` goes `COMPLETE`. Tool or time exhaustion is **not** `BLOCKED`.

**C.** Folding the four excluded tests into 497 would mutate a frozen single-owned gate and imply they ran;
leaving them unrun makes four authored contract tests zero-evidence (`LESSONS.md` 171). They run separately,
counted separately, with diagnostic weight only and no acceptance credit until a Review folds them into a
successor gate under the pre-commitment discipline.

**Limits.** No runtime result established. The produced multi-carrier paired front, organic D1/D2/D3/D5, A6/A7,
the odd-τ witness and the 47 recoveries remain unproven and stop-gated; RA-34.3, RA-36.4/.5/.6, RA-38 and RA-39
stand unchanged.

## 2026-10-08 — `M6-CP3-R3-ENDPOINT-ARCH-REV`: P0/P1 endpoint attachment resolved as RA-39; CB1-ENTRY-R3 resumes

Runtime-free independent producer Design Review. **Block resolved and frozen as RA-39**, completing RA-37a's
P0/P1 obligation; RA-37a and RA-38 are not replaced. No runtime credit; accounting **64 / 17 / 47**, debt **1**.

**The decisive fact.** `src/geometry/SurfaceCellTracing.cpp:18271-18285` requires
`first.route == second.route.reversed()`, so `first.from`/`second.to` lie at the **same spatial end** and
`first.to`/`second.from` at the other. Each `endpoint_certificate` call is therefore a **cross-rail pair at one
spatial end** — one face per side — not a traversal of the polyline. The implementation instead sets
`current = firstAttachment` and walks **every** carrier accumulating τ (`:18297-18330`): the superseded RA-36.1
end-to-end shape reappearing at endpoint level, and neither a local crossing nor a well-defined path.

**Attachment needs no new authority, and the fix removes state.** The terminal carrier `C_j` is the route's
first/last oriented step; the pair is valid iff `{from_j, to_j} == {C_j.firstFace, C_j.secondFace}` unordered,
with `χ_j = C_j.firstToSecond` oriented by which face is `from_j` — all already published in
`SurfaceHardRailFieldTransition`. No path walk at an endpoint; any other pair fails closed as *no local
attachment*. Consistent with RA-38 on the reviewed fixture: terminal carriers `(1,4)` faces `{0,3}` and `(4,7)`
faces `{4,7}`, with the sector cut placing `0,4 ∈ A` and `3,7 ∈ B`, so each pair holds exactly one face per
sector.

**Transport belongs to the square, not the crossing.** Radial chains are unnecessary for an endpoint crossing —
that is one carrier. They serve only `χ_1 ∘ φ_A = φ_B ∘ χ_0`, a comparison after explicit transport, with
`φ_A : 0→1→4` and `φ_B : 3→6→7` on the fixture.

**The schema gap is real.** `SurfaceHardRailRouteEndpointCertificate` (`SurfaceCellTracing.h:1488-1493`) carries
`orientedSteps` over all carriers plus an end-to-end `composedTurn` — both wrong-shaped for a one-carrier
concern — and has **no field** for per-junction, per-sector ordered non-rail radial witnesses. The STOP record
was right that this is not fixed by renaming. Singleton degenerates correctly: one carrier, no junction,
`φ` identity, square reduces to existing reciprocity.

**Limits.** Existence of a produced multi-carrier paired front is still not established; if the bounded search
finds none, that path is unexercised and must not be cited as validated. All RA-34.3 stop gates and
RA-36.4/.5/.6 stand.

## 2026-10-08 — `M6-CP3-R3-SECTOR-ARCH-REV`: sector derivation resolved as RA-38; CB1-ENTRY-R3 resumes

Runtime-free independent producer Design Review. **Block resolved: the two oriented sectors are well-defined and
derivable from authority A4 already holds. Frozen as RA-38, implementing RA-37a correction (1); RA-37a is not
replaced.** No runtime credit; accounting **64 / 17 / 47**, debt **1**; gate **497 = 30 + 12 + 449 + 6**.

**The STOP was correct.** RA-37a asserts two unique oriented sectors *exist* without giving the construction, so
`M6-CP3-CB1-ENTRY-R3` was right to refuse rather than guess a sector, a global face-star potential, a
first-by-row face, or a new τ. It changed no production source and attempted no compile.

**Construction.** At a rail junction vertex `v` on an interior orientable manifold link, `v`'s star faces form a
cycle under "share a spoke edge at `v`"; cutting that cycle at the two incident hard carriers yields exactly two
arcs — the two sectors — with each carrier contributing exactly one face to each arc. Derived mechanically on the
reviewed 3×3 fixture: star cycle `0→1→4→7→6→3→0`; carriers `(1,4)`,`(4,7)`; sectors `{0,1,4}` and `{3,6,7}`;
`(1,4)` faces `{0,3}` split `0∈A/3∈B`; `(4,7)` faces `{4,7}` split `4∈A/7∈B`. This reproduces the STOP record's
observed radial chains `0→1→4` and `3→6→7` and shows they are the cut arcs, not a fixture artefact. Within a
sector, consecutive carriers' faces are joined by **non-rail** A3 transitions — exactly why superseded RA-36.1's
carrier-to-carrier face identity failed. Fail-closed cases coincide with RA-37a's frozen domain, so RA-37a needs
no amendment.

**Two distinct validator defects, which must be corrected together** — in
`src/geometry/SurfaceCellTracing.cpp:8019-8118`: (i) `previous.secondFace != transition.firstFace`, the
superseded RA-36.1 category error at a **second site**, always firing on the reviewed rails since
`{0,3} ∩ {4,7} = ∅`; and (ii) `endpoint.orientedSteps.size() != expectedSteps.size()`, which ties endpoint-path
length to **carrier count** when the real length is set by **fan valence per junction**. **The 3×3 fixture
satisfies (ii) only by coincidence** (two carriers, chain length two), so fixing only (i) and validating on 3×3
would pass while (ii) stays wrong. The A4-side gate at `:18312-18330` must also not precede the sector/junction
logic, or the corrected path stays unreachable — the `M5-CP3-TB1-R3-REV` reachability trap.

**Third instance of one pattern.** RA-34.3 retained τ before the nontraversable marking destroyed access; RA-35
retained per-wedge bindings before the sort/unique collapse; RA-38 needs only the carrier **cut** of a star A4
already traverses (`:18120-18206`) using carriers it already knows. The cure is always to publish or reach
authority the producer already computes — never new input, never consumer inference.

**Limits.** Existence of a real A4-produced multi-carrier paired HardRail front is **not** established; a
hand-authored input fixture is not a produced certificate. If the bounded search finds none, the multi-carrier
path is unexercised and must not be cited as validated. All RA-34.3 stop gates and RA-36.4/.5/.6 stand.

## 2026-10-08 — next-step determination: RA-37a accepted; `M6-CP3-CB1-ENTRY-R3` next; RA-36.1 status corrected

Runtime-free. `M6-DEFN-R5-R3-REV` accepted **RA-37a** as a bounded fail-closed source-topology contract with no
runtime promotion, and authorized **`M6-CP3-CB1-ENTRY-R3`** (Code + Build only, mandatory STOP-FIRST gates) as
the exact next turn. CP2 accepted 491/491; R2 rejected 444/497 with 47 accepted-green losses; accounting
**64 / 17 / 47**, debt **1**; frozen gate **497 = 30 + 12 + 449 + 6**. `STATUS` was already correct and is
unchanged.

**RA-37a meets all four requirements the R2 Review placed on R3, and improves on one.** Correction (1) replaces
face-identity connectivity with the two unique oriented source-vertex fan sectors **and states the domain** —
connected orientable two-manifold links without foreign barriers, otherwise fail closed — a condition the
reviewing agent's own formulation omitted. Correction (2) requires reciprocity and a typed commuting square of
source-keyed nonrail radial A3 side paths and owner-rail crossings. Correction (3) is **sharper than the fix the
R2 Review prescribed**: rather than one alternating chain `τ_ab = χ_n ∘ φ_(n-1) ∘ … ∘ φ_1 ∘ χ_1`, A4 publishes
for **each of the two distinct spatial endpoint pairs** its own locally anchored cross-rail path and `τ_j` from
trace-selected source faces, with the along-rail square only *comparing* the two endpoint mappings after explicit
transport — and forbids composing χ blindly across carriers or treating a path that reaches the opposite spatial
endpoint as a local attachment. That is right: a single end-to-end chain retains the "walk along one side" shape
that caused the original defect, since the two endpoints sit at spatially distinct rail locations.

Publish-don't-invent is honoured: the CB plan works in `src/geometry/SurfaceCellTracing.cpp:18116-18372`, the
region holding both the unsound face-identity gate (`:18312-18321`) and A4's already-written but unreachable
vertex-fan junction logic (`:18337-18342` over `railFanPotentials`, declared `:18120`, populated `:18206`), so the
ordering defect is in scope. Item 6 also targets `RemeshPipeline.cpp` near 4575/5147/5391-5509 to unify certified
seam direction to one typed `(certificate, orientation)` — the RA-34.1/RA-35 binding sites.

**Status correction applied.** The `RA-36.1` annotation still read "retained unrelaxed *pending* reconciliation
into RA-37 by `M6-DEFN-R5-R3`" after that turn completed, and RA-37a does not mention RA-36.1 — leaving the
unsound clause's status ambiguous for a linear reader. It now records **SUPERSEDED by RA-37a**, with RA-36.1's
text retained as history only and RA-36.4/.5/.6 still in force. Only the status pointer changed; no rule was
touched.

The handoff carries the binding CB constraints: STOP FIRST on two-sector certification and the `P0`/`P1`
independent local endpoint paths; no blind χ composition across carriers; A5 consumes only the published
certificate; RA-36.4/.5/.6 and all RA-34.3 stop gates retained; and diagnostic-first-locus inside
`invalid_route()` before any corrective semantic edit, since R2 logs still do not localize the first failing
predicate.

## 2026-10-08 — `M6-DEFN-R5-R3-REV` — independent source-only RA-37a amendment

**`M6-DEFN-R5-R3-REV` ACCEPTS RA-37a as a *bounded, fail-closed source-topology contract*; this is not any new runtime promotion. Exact successor after final beacon: `M6-CP3-CB1-ENTRY-R3` Code + Build only, with mandatory source A4 two-sector and both endpoint-local path STOPs.** CP2 491/491 remains accepted; R2 rejected 444/497; 47 accepted-green losses; 64/17/47, debt 1. See `Architecture_M6_DEFN_R5_R3_Review_Record.md`. No organic D1/D2/D3/D5 positives or A6 recovery accepted.

Reviewed exact 5,663-file source snapshot (run `37783521287`) and independently reconstructed two distinct source-fan transport chains on 3×3 fixture. RA-37a requires A4-owned local cross-rail paths for the two spatial endpoint pairs, while along-rail side transports provide commuting-square consistency; neither may be inferred from region F or raw sheet labels. R3 CB released conditionally with mandatory preflight STOP; no runtime/compile. No ledger increment.

---

## 2026-10-08 — `M6-CP3-TB1-ENTRY-R2-REV` review: upheld in full; RA-36.1 proven unsound (reviewer's own error)

Runtime-free review. **Upheld in full.** Accounting **64 / 17 / 47**, debt **1**, is correct; R2 candidate
UNPROMOTED; CP2 remains accepted at 491/491.

**The RA-36.1 falsifier is correct, and the unsound clause is the reviewing agent's own**, authored at
`M6-CP3-R2P3-ARCH-REV`. Verified independently from `tests/SurfaceCellTransitionQuotientTests.cpp:694-740`: the
3×3 quad triangulation gives edge `(1,4)` → faces `{0,3}` and edge `(4,7)` → faces `{4,7}`, intersection empty.
It generalizes — two **collinear** edges meeting at a vertex can never share a face, since a triangle spanning
them would be degenerate — so *"consecutive steps share exactly one typed source face"* is false for **every**
polyline carrier pair. The clause was self-defeating: RA-36 rejected singleton-only *because* polyline hard
features are legitimate, citing these very edges, then froze a premise polylines cannot satisfy. The 25
`InvalidHardRailRouteCertificate` false rejections of accepted-green evidence are its direct consequence, and
`+1 RP-01` event / `+1` recurrence is the right classification.

**Diagnosis: a primal/dual category mistake.** "Share one face" is dual connectivity (face-to-face transitions
across edges of one triangle); a HardRail route's steps are **primal** carriers meeting at a **vertex**, so the
connecting structure is the vertex fan. The composition is wrong in kind too — crossing maps do not compose as a
walk along one side. Correct form alternates cross-rail and along-side transport,
`τ_ab = χ_n ∘ φ_{n-1} ∘ … ∘ φ_1 ∘ χ_1`, with RA-36.3's square as consistency; RA-36.3 half-anticipated this and
RA-36.1/.2 contradicted it.

**New evidence added by this review.** A4 **already** computes the fan authority and **already** has junction
logic: `railFanPotentials` is declared at `src/geometry/SurfaceCellTracing.cpp:18120`, populated at `:18206`, and
consumed at `:18337-18342`. But it has **zero header references**, so A5 cannot consume it as RA-36.2 demands —
and the face-identity gate at `:18312-18321` threads a single `current` face and rejects the generic polyline
case **before** `:18337` runs. The clause therefore made already-written correct code **unreachable**, the same
pattern as `M5-CP3-TB1-R3-REV`, with the same cure as RA-34.3/RA-35: publish the authority the producer already
holds.

**RA-36.1 is annotated PROVEN UNSOUND but retained unrelaxed**, owner `M6-DEFN-R5-R3`. The reviewing agent
declined to amend its own frozen rule here: the only authorized successor is a runtime-free Definition turn
chartered to reconcile RA-36 into RA-37, so no Code + Build can implement against the unsound clause in the
interim, and amending outside that turn would fragment authority. RA-36's rejection of singleton-only is
**unaffected and strengthened**; RA-36.4/.5/.6 and every RA-34.3 stop gate stand.

Credit where due: the Review recorded a new stable event **against a reviewer's own frozen premise** rather than
softening the number, kept singleton accepted, declined to infer a replacement contract from a static
counterexample, and required diagnostic-first-locus inside `invalid_route()` before corrective change — the
instrumentation-before-guessing discipline that ended fifteen turns of static guessing in M5-CP3.

Exact successor: `M6-DEFN-R5-R3` — runtime-free Definition proposing RA-37 with typed vertex-fan-side A3
transports; mandatory `M6-DEFN-R5-R3-REV` before any new Code + Build.

## 2026-10-08 — R2 independent Review REJECTED (444/497), R3 Definition next

**M6-CP3-TB1-ENTRY-R2-REV COMPLETE: R2 REJECTED 444/497; 53 RED; 47 previously accepted CP2 identities now RED.** Independent cross-run comparison: CP2 491/491, rejected R1 482/497, rejected R2 444/497; R1→R2 38 new RED, zero recoveries. Stable **+1 new RP-01 product event**, current ledger **64 events / 17 categories / 47 recurrences**, produced-witness debt **1**; prior A6 RP-01 remains OPEN. Exact source `80fc1688f13e5ed52699177a845f25cc4dbda38b`; mechanical R2 run/job `37767144537 / 113277596566`, result artifact `11545716507`, ZIP sha256 `d6469bea1b4ef6fb3b142d05a97d01dbab98331cfc91d930c7bc30da555ec0ca`, internal 1019/1019. Direct new A4 `InvalidHardRailRouteCertificate` producer regression on accepted HardRail fixtures; accepted RA-36.1 adjacent-carrier shared-face assumption is unsound for legal rail polyline (1,4) faces {0,3}, (4,7) faces {4,7}; input counterexample is NOT a demonstrated produced multi-step route. Organic D1/D2/D3/D5 positives unproved. Candidate UNPROMOTED; CB2/CP3 exit HELD. **Exact authorized successor (only after final STATUS closure): `M6-DEFN-R5-R3` runtime-free Definition, then mandatory independent `M6-DEFN-R5-R3-REV`; no implementation until acceptance.** Canonical review `Architecture_M6_CP3_TB1_Entry_R2_Review_Record.md`, row classification `Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv`, held plan `Architecture_M6_DEFN_R5_R3_CP3_Entry_Recovery_Definition_Plan.md`; complete full reviews mirrored in ChatGPT Library `/Directional/Evidence/`.

---

## 2026-10-08 — `M6-CP3-R2P3-ARCH-REV`: HardRail route transport resolved as RA-36; CB1-ENTRY-R2 resumes

Runtime-free independent producer-owned architecture Review. **Multi-edge A4 route transport certificate
APPROVED; singleton-only route contract REJECTED. Frozen as RA-36.** No runtime credit granted; accounting
**63 / 17 / 46**, debt **1**; frozen gate **497 = 30 + 12 + 449 + 6** unchanged.

**Diagnosed error — a miscoded structural impossibility.** A5's `rail_tau`
(`src/pipeline/RemeshPipeline.cpp:4916-4957`) loops every step of `first.route.steps()` and requires that step's
`SurfaceHardRailFieldTransition` record to carry the *same* incident-face pair as the relation's two
`placement.selectedFace` values. Two distinct triangles share at most one edge, so any route with ≥2 distinct
edges is unsatisfiable by construction and deterministically returns `HardRailTransportMismatch` — asserting a
transport disagreement that was never evaluated. The predicate conflates **endpoint attachment** with
**transport agreement** and applies both per step, when τ along a path **composes** rather than repeating.

**Singleton-only rejected on three grounds.** The invariant does not exist — A4 appends one step per distinct
retained source-edge topology with no cap (`src/geometry/SurfaceCellTracing.cpp:11712`), so the option would add
a producer restriction rather than document an invariant. The domain it would narrow is legitimate — consecutive
hard edges `(1,4)`/`(4,7)` are a real bounded producer input
(`tests/SurfaceCellTransitionQuotientTests.cpp:694-759`) and polyline hard features are ordinary CAD geometry.
And it would not avoid the work: a multi-edge route must still reject with a typed unsupported-route code rather
than a false transport mismatch, and once that distinction is mandatory, publishing the route is strictly more
informative than refusing to.

**Approved contract.** Correct decomposition is attachment at the two ends and composition through the interior,
making singleton the degenerate fold of length 1 — one contract, not two. A4 publishes per route the
canonical-orientation step sequence, per-step typed incident faces with exact oriented A3 `firstToSecond`
validated against `FieldTransportAtlas::transition_value`, the endpoint attachment faces, and path connectivity.
A5 composes τ as a typed fold, verifies selected faces equal the published attachment faces, and applies
`(B_b − B_a − R_coord − τ_ab) mod 4 = 0` at both endpoint pairs with the reverse inverting all orientations
together. Consecutive transports must satisfy `χ_(i+1) ∘ φ_a = φ_b ∘ χ_i`; no averaging, no equal-τ-per-carrier,
no first-step selection; typed fail-closed on absent/ambiguous path, disconnected star, nontrivial singular
holonomy, nonreciprocal A3 transitions or mismatching hard-feature owner. Singleton behaviour must not regress.
Reusing `HardRailTransportMismatch` for an uncertifiable route is prohibited.

**Limits carried.** Existence of a produced multi-edge route is **not** established — the two-hard-edge fixture
declares inputs, it does not prove A4 emits a spanning reciprocal route. If the bounded search finds none, the
multi-edge path is unexercised and must not be cited as validated, the same discipline applied to the degenerate
nonzero-Z4 witness at `M5-CP3-DEFN-R1`. All RA-34.3 R2-P3 stop gates stand — odd `τ ∈ {1,3}`, `F_b − F_a ≠ τ`,
sign-inversion negative, reciprocal/face-permutation invariance — and an empty search stops for Review.

Full basis: `Architecture_M6_CP3_R2P3_HardRail_Route_Transport_Review_Decision.md`.

## 2026-10-08 — `M6-CP3-R2P1-ARCH-REV`: wedge-to-certificate binding block RESOLVED; CB1-ENTRY-R2 resumes

Runtime-free producer-owned architecture review. **The reported block's premise is false and no new A4
publication is required.** `M6-CP3-CB1-ENTRY-R2` resumes compile-only. Accounting **63 / 17 / 46**, debt **1**;
frozen gate **497 = 30 + 12 + 449 + 6**; no product, test, fixture or selector change in this turn.

`M6-CP3-CB1-ENTRY-R2` stopped on `R2-P1` reporting that A4 lacks an independently published oriented
wedge-to-isolation-certificate sheet/side binding. The stop gate behaved correctly, but the authority is already
published on both sides in the **same key space**. The A4 certificate carries `firstFace`/`secondFace` as
`authority::SourceFaceTopologyKey` plus `firstSheet`/`secondSheet`
(`SurfaceCellTracing.h:1316-1324`), and its builder enforces **distinctness**
(`if (firstTopology == secondTopology || firstSheet == secondSheet) return false;`,
`SurfaceCellTracing.cpp:16743-16745`) and a **canonical orientation** via the `secondTopology < firstTopology`
swap (`:16746-16750`). A5's `SurfaceOccurrence::cornerWedgeBindings` stores populated per-wedge
`CornerWedgeFaceBinding{ face, sheet, chart }` (`RemeshPipeline.h:769-775`), built at
`RemeshPipeline.cpp:4313-4440` and passed at `:4487`.

**Binding (RA-35 candidate):** `b.face == C.firstFace()` → First; `b.face == C.secondFace()` → Second; otherwise
off-seam. Unambiguous because the certificate's two faces lie in distinct topologies, so no binding matches both.
Orientation is **A4-owned** — the certificate's canonical ordering — not an A5 inference and not a global label
comparison. Sheets are **verified after** the face join, mismatch typed fail-closed, so sheet labels neither
grant nor deny certificate lookup: frozen **RA-34.1** satisfied.

**Why it looked missing:** the producer also flattens the bindings at `:4464-4471`
(`push_back(binding.sheet)` + `sort` + `unique`), discarding `face` and per-wedge association. Both products are
stored, but consumers read the lossy one — **15** `cornerWedgeSheets` references against **3** for
`cornerWedgeBindings`, decisively `:5180-5181` (`binary_search` membership over global labels) and `:7083-7086`
(`size() <= 1U`). The binding was unreachable through the accessor everyone uses, not absent. This is
`RA-34.3`'s τ disease a second time — a lossy downstream projection standing in for retained producer authority —
with the same cure.

`R2-P1` reduces to: add a typed accessor returning `{First, Second, NotOnSeam}` with sheet agreement verified
after the face match; migrate `:5180-5181` and `:7083-7086` onto it; add no new A4 publication and leave the
certificate builder and `CornerWedgeFaceBinding` unchanged. Live stops retained: a wedge on a certified seam
matching neither certificate face, or a matched side whose sheet disagrees, is a genuine producer defect — stop
for Review rather than widen the join. `R2-P2`/`R2-P4`/`R2-P5` and the D2/D3/D4/D5 organic-witness stop gates are
untouched, and precondition 2 keeps its narrow reading.

Full analysis: `Architecture_M6_CP3_R2P1_Wedge_Certificate_Binding_Resolution_Record.md`.

## 2026-10-08 — next-step determination: RA-34 accepted; `M6-CP3-CB1-ENTRY-R2` next, with precondition 2 disambiguated

Runtime-free. `M6-DEFN-R5-R2-REV` accepted RA-34 "for bounded implementation, not runtime acceptance", froze it
in `Architecture_M6_Frozen_Definitions.md` (§RA-34), and released
`Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md` with mandatory stop gates. Exact next turn is
**`M6-CP3-CB1-ENTRY-R2`**, compile/package only, `runtimeExecution=false`. Accounting **63 / 17 / 46**, debt
**1**; frozen gate **497 = 30 + 12 + 449 + 6**. `STATUS` was already correct and is unchanged.

The acceptance is sound and properly bounded. Both R1 findings are discharged **as Definition only** with the
production side left open — `OBS-01` "Definition discharged, production recovery open", `OBS-02` "Definition
discharged, produced τ witness open". Frozen RA-34.1 carries the R1 Review's exact requirement that the seam be
found "without raw/global sheet-label equality **granting or denying** certificate lookup", and the R2 Review
independently recalculated the τ discriminator rather than accepting it on report. The closeout states that
real-produced D2/D3/D4/D5 positives are **NOT proved and stop-gated**.

**Determination: the CB plan is self-conflicting and was disambiguated in the handoff.** Precondition 2 requires
the agent to "independently prove" the organic periodic, HardRail and seam-collinear witnesses "under
Review-approved finite real-producer constructions", while the same plan's boundary forbids execution —
"preflight tests may be read/compiled, **not executed**", `runtimeExecution=false`, no test or binary
invocation. Existence of a produced witness is a runtime fact that no compile-only turn can establish. The R2
Review resolves it in favour of the narrow reading, having released the plan while recording the positives as
unproved and carrying those witnesses *to* CB1: precondition 2 means author the approved searches and verify
**statically** that each is well-formed, correctly ordered (preconditions before selection) and not provably
empty, stopping for Review otherwise — with existence proved later at `M6-CP3-TB1-ENTRY-R2-EXEC` by the 497-process
gate.

Both misreadings are recorded as live hazards: executing runtime inside the turn forfeits the compile-only
boundary, and declaring a witness "proved" from static reasoning alone repeats the M5-CP3 CB9 failure, where a
nonzero-Z4 witness authored on static plausibility missed bounded-disk closure by nine orders of magnitude.
Authorship is not proof.

## 2026-10-08 — Independent M6-DEFN-R5-R2-REV accepts RA-34 (Definition-only)

Verified source snapshot `48370d9913b40b3e42299082188ea404af4c7ca1` (run 37723060299 / artifact 11526935503); source-only review. RA-34.1 corrects one typed certificate orientation and removes raw/global sheet-label equality/inequality as grant/deny authority. RA-34.3 requires real-produced odd-oriented HardRail τ and independent F/τ inequality; algebra is not producer evidence. R1 OBS-01/02 discharged as *Definition* issues only. RP-01 and D2/D3/D4/D5 organic positives open. Exactly one successor `M6-CP3-CB1-ENTRY-R2` compile-only, then immutable 497 TB and mandatory Review. CB2 held; selector unchanged, CP2 491/491, R1 entry 482/497 rejected, stable 63/17/46 and debt 1. No code/build/test/runtime mutation or execution.

## 2026-10-08 — next-step determination: `M6-DEFN-R5-R2-REV` is next; RA-34 addresses both R1 findings

Runtime-free. `M6-DEFN-R5-R2` is COMPLETE and the exact next turn is the mandatory independent Definition Review
**`M6-DEFN-R5-R2-REV`**. `Architecture_M6_CP3_CB1_Entry_R2_Recovery_Code_Build_Plan.md` remains correctly
**HELD** — RA-34 is a candidate, not implementation authority — and its hold was properly re-pointed from the
superseded `M6-DEFN-R5-R1-REV` to `M6-DEFN-R5-R2-REV` rather than left stale. `STATUS` was already correct and
is unchanged; no resume timestamp was fabricated.

Both R1 Review findings are addressed substantively. **OBS-01:** RA-34.1 returns one oriented matched object
`(certificate, Forward|Reverse)` and binds that same orientation across every downstream check, names the
helper's global-label rejection as the source contradiction, and requires the certificate's own
`firstSheet()/secondSheet()` to be distinct typed authorities — then goes beyond the finding with a
mixed-orientation **negative** (forward 1 / reverse 3, faces matching only Reverse, branch strip forward 1) that
must reject. **OBS-02:** the replacement counterexample `F_a=0, F_b=3, τ_ab=1, τ_ba=3, R_coord=1, B_a=0, B_b=2`
is strictly better on all three axes, re-checked arithmetically: the rule accepts (`(2−0−1−1) mod 4 = 0`), it
still discriminates τ from regional `F` (`3 ≠ 1`), and τ is now odd so `−τ_ab = 3 ≠ τ_ab` makes the τ
orientation falsifiable. The `Z4`-abelian note is recorded.

The handoff now carries the Review agenda: confirm the bound orientation reaches every check with no residual
disjunction and that the mixed-orientation negative is reachable; confirm no global sheet-ID comparison can
grant **or deny** the special case at `RemeshPipeline.cpp:4520-4551`; confirm D2/D4/D5 carried forward unchanged;
and confirm every stop gate survives, since D2, D3 and D4 each still rest on an unproven search.

Also recorded in the handoff: live routing is the newest top block, while the `# Current handoff —
M6-CP3-TB1-ENTRY-REV` heading and its `## Exact next turn` naming `M6-CP3-CB1-ENTRY-R1` are historical and
several turns stale — left intact as history, flagged so they are not read as current routing.

## 2026-10-08 — M6-DEFN-R5-R2 candidate RA-34; implementation held

Verified snapshot `f3ae67ade2ac37f00d2317d0de007aaf959f8969` / run `37717936915` / artifact `11524367318`. Independent R1 Review rejected RA-33. Corrected D1: bind one typed certificate orientation for every seam conjunct and disallow global sheet equality or inequality as either admission or lookup rejection; A4-owned typed incidence is required, otherwise stop. Corrected D3: demand baseline-green produced HardRail with `(F_b-F_a) mod4 != τ_ab` and **odd** `τ_ab`, test sign reversal, never claim a τ=0 or algebraic example proves direction; Z4 order not numerically falsifiable. D2/D4/D5 carried unchanged with organic witness stop gates. Rejected entry remains 482/497, stable 63/17/46, debt 1. No source/test/fixture/selector/build/runtime changed or executed. Mandatory successor `M6-DEFN-R5-R2-REV`; R2 Code+Build/CB2 HELD.

## 2026-10-08 — `M6-DEFN-R5-R1` review: D2/D4/D5 sound; D1 holed; D3 right with an untestable witness

Runtime-free architecture review of the CP3 entry recovery definition candidate. **Not accepted as written.**
No runtime, no product/test/fixture change; accepted authority untouched.

**D1 (RA-33.1) — two defects, both from source.** `seam_transport_certificate(...)`
(`src/pipeline/RemeshPipeline.cpp:4520-4551`) computes `forward` and `reverse` separately and returns
`if (forward || reverse) return certificate;` — **discarding which orientation matched**. D1 then requires the
certificate to match "in either forward or reverse orientation" *and*, separately, that branch stripping equal
"the oriented certificate's `forward()` or `reverse()`". Those disjunctions are independently satisfiable, so a
relation matching faces/sheets **reversed** while its transport matches **forward** is granted the certified
special path and waives full `sourceChart`/`branchRotation` equality on a mixed orientation. D3 already states
the guard ("do not mix orientations"); D1 omits it. Separately, D1 forbids global sheet labels from *granting*
the special case but leaves them *gating discovery*: the same helper opens with
`firstSpan.interiorBinding.sheet == secondSpan.interiorBinding.sheet → nullopt`, so under RA-32's own premise a
genuinely certified seam with equal labels is never found — a false negative built on the error being removed.
Recorded as `M6-DEFN-R5-R1-REV-OBS-01`.

The diagnosis itself is confirmed: at `:5400-5403` `crossSheetSeam` is computed from `collinearEdge` equality plus
label inequality with no certificate consulted, and only `!crossSheetSeam` requires full representation equality.

**D3 (RA-33.3) — architecturally right, witness insufficient.** Making A4 the publication owner for oriented
`(sourceEdge, fromFace, toFace, matching)` rather than letting A5 re-derive τ from regional gauges is the correct
reading of RA-31a, and the data provably exists before exclusion (`FieldTransportAtlas.cpp:2020-2047` adds the
transition value *before* marking the carrier nontraversable — the retain-then-exclude structure from M5-CP3
§15). The rail-vertex holonomy rule is well specified and closes both shortcuts. But the sole discriminating
structure has **`τ_ab = 0`**, which is self-inverse and so cannot falsify `τ_ab` versus `τ_ba = −τ_ab` — while the
same paragraph requires the reverse relation to invert all three transports. At least one qualifying witness with
`τ_ab ∈ {1,3}` is required. Also recorded: `Z4` is abelian, so "compose right-to-left" is numerically inert and
no fixture can falsify the composition **order** — only the signs. `M6-DEFN-R5-R1-REV-OBS-02`.

**D2, D4, D5 sound, with derived rather than asserted premises.** D2's `{1,3}` gauge-difference premise follows
from 180° being self-inverse and therefore unable to discriminate direction; enumerating all relations, picking
the smallest key *after* preconditions, and enforcing non-vacuity before the equality assertion remove the
select-then-assert defect. D4's fixture geometry was checked rather than assumed — seam carrier `(1,4)` is a
genuine interior edge shared by exactly `(0,1,4)` and `(1,5,4)`, one face per sheet, and all four triangles are
CCW. D5 correctly inverts a selection-before-precondition defect and rejects component-label coincidence. All
five obligations carry honest "outstanding proof" admissions and stop gates rather than synthesis.

Exact successor: `M6-DEFN-R5-R2` — amend D1 and D3 as above; D2/D4/D5 carry forward unchanged.

## 2026-10-07 — `M6-CP3-TB1-ENTRY-R1-REV` — R1 rejected; RA-32 routes Definition repair

- Re-derived the valid R1 gate at **482/497** and rejected/unpromoted the candidate.
- Ten A6/D7 REDs remain the same open `RP-01 / AUTHORITY_DOMAIN_CONFLATION` event; P1 and T1 stable regressions are recovery-proved.
- D1/D3/D4/D7 are non-stable witness/oracle defects; D2 returns to its RA-31a `τ`-based Definition owner.
- Stable accounting remains **63 / 17 / 46**, debt 1. Exact next: `M6-DEFN-R5-R1` -> mandatory Definition Review.

## 2026-10-06 — `M6-CP3-TB1-ENTRY-REV` review-agent addendum: RA-31 published; RA-31a withdraws the HardRail branch certificate

- **Re-derived independently:** result `11413899043` (`61dab4f6`) and log `11413964659` (`d26bb318`); 1019/1019; ledgers in frozen order; 373/497; the classification TSV covers every RED exactly once with matching hashes.
- **Confirmed:** CAND-01 (A4 face-gauge publication gap; the uniform producer computes but does not publish), CAND-02, CAND-04, CAND-06, CAND-07; accounting 63 / 17 / 46.
- **CAND-05 re-adjudicated:** the D2 certificate strips region-relative gauges, but the cross-rail matching τ is required. The rule holds only if `F_b − F_a = τ`. A5 rejects the only nonzero-gauge HardRail fixture.
- **RA-31a:** withdraw the certificate rejection; identity 2 pre-registered RED; identity 6 must pass; T2 stop rule; `M6-DEFN-R5-R1` redefines D2.
- **Docs:** RA-31 published (it was missing from the frozen definitions); R1 plan block; lesson 207; handoff / ORIENTATION / TODO / ROADMAP / tracker / consolidated.

## 2026-10-06 — `M6-CP3-TB1-ENTRY-REV` — candidate rejected; RA-31

Independent Review re-partitioned the immutable 124 REDs exactly: CAND-01 110, CAND-02 9, CAND-07 1, CAND-04 1, CAND-05 2, CAND-06 1. CAND-01 is stable new singleton `INCOMPLETE_AUTHORITY_PUBLICATION`; CAND-02 is stable `RP-01`; CAND-07 is stable `RP-02`; the three new-entry witness/oracle defects are non-stable. Stable totals become **63/17/46**, debt 1. Candidate `11411137781 / 912760f1...` rejected; RA-31 releases only `M6-CP3-CB1-ENTRY-R1` → TB 497 → mandatory Review.

## 2026-10-06 — `M6-CP3-TB1-ENTRY-EXEC` COMPLETE / 373 PASS + 124 RED

- Immutable artifact-only run/job `37464309062 / 112271440079` consumed `11411137781 / 912760f1...` and completed all **497** exact-filter processes: focused30 4/30, focused12 0/12, selector449 369/449, CP3-entry 0/6. Exact-one selection and zero skips held; benchmark count 0.
- Result/log artifacts `11413899043 / 11413964659`; result manifest **1019/1019**; candidate package manifest **28/28** pre/post; package/source/execution-view censuses and all frozen gate hashes unchanged.
- All 124 RED rows are classified in `Architecture_M6_CP3_TB1_Entry_Red_Classification.tsv`. Six Review-owned non-stable candidates are recorded; no stable repricing in EXEC. Accounting remains **60 / 16 / 44**, debt 1.
- Exact successor is mandatory `M6-CP3-TB1-ENTRY-REV`; CB2 held.
- Durable closeout: RED-evidence commit `145f7af552483ead00a6605e0ec793cb9f4af595`; cleanup run `37470228257` / cleanup SHA `4eae760859ed48a7898d9383e583681111fe9023`; staged Drive patch owner-deleted. Superseded CB1 plan/report and TB1 WIP handoff were retired after preservation and are recoverable at git commit `4eae760859ed48a7898d9383e583681111fe9023`; mandatory Review must index the retired filenames.

## 2026-10-06 — `M6-CP3-CB1-ENTRY` COMPLETE / compile-package GREEN

- Implemented RA-30 + RA-30a CP3 entry authority at semantic source `912760f1ffc785676f5d50717177b1cd8be69234`: Periodic exact-A3 gauge separation, HardRail branch certification, OrdinaryFront isolation-seam identity, typed A4→A5 hard-feature barriers, and relation-kind-aware A7 sheet semantics.
- Added exactly six frozen CP3-entry identities; focused30/focused12/selector449/routing449 authority was not edited.
- First Drive apply `37455665769 / 112242600282` failed before commit because the earlier local base directory had been modified; the patch was regenerated from a fresh immutable source extraction. Corrected apply `37458022713 / 112250373902` pushed `912760f1...`; owner-side Drive deletion completed.
- Mandatory compile `37458495402 / 112251921276` passed all eight standard GMP/GMPXX targets. Result/log artifacts `11411137781 / 11410478676`; result provider SHA-256 `704b1b70...7234`; manifest **28/28**; clean source; `runtimeExecution=false`.
- Historical CB1 evidence report `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Report.md` was retired at TB1 cleanup after preservation; recover it at `4eae760859ed48a7898d9383e583681111fe9023`. No runtime acceptance is claimed. Exact next: immutable `M6-CP3-TB1-ENTRY-EXEC`, **497** fresh processes, then mandatory `M6-CP3-TB1-ENTRY-REV`; CB2 held. Accounting remains **60 / 16 / 44**, debt 1.

## 2026-10-06 — `M6-DEFN-R5-REV`: CP3-entry Definition accepted with RA-30a; CB1 released

- **Verified:** D1, D7 and D8 against source; D4's diagnosis; the 497/507 gate arithmetic (the G4-B001 rows are not in selector449).
- **RA-30a fixes:**
  - **V1:** D4's authority comes from A4, with no A5 signature change;
  - **V2:** D2 needs a produced non-constant-field HardRail witness (the cited evidence was periodic);
  - **V3:** D3 certifies the seam branch with the validated seam quarter-turn (it had dropped the branch check);
  - **V4:** GP26/GP27 need the historical target;
  - **V5:** D6 needs canonical accumulation order;
  - **V6:** the scheduler permutation is defined;
  - **V7:** the D1 witness needs a non-involutive gauge difference;
  - **V8:** D2 site suffix.
- **Docs:** new `Architecture_M6_DEFN_R5_Review_Record.md`; CB1 plan released; lesson 206; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated. Accounting 60 / 16 / 44.

## 2026-10-06 — M6-DEFN-R5 CP3-entry Definition complete

- Completed D1-D9 and published candidate **RA-30**.
- Froze six-entry **497** gate, intended final **507** gate, relation/gauge/barrier/sheet semantics, class-wide optimizer reference, permutation falsifier and direct-exit evidence owners.
- Froze current-source G4-B001 strict 3/3 as Phase10 exact committed torus, P26 torus end-to-end and P27 production matrix; explicitly did not invent historical exact names absent from durable evidence.
- Added held `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Plan.md`; mandatory next is `M6-DEFN-R5-REV`.
- Runtime-free verified snapshot `37441143188 / 612d914d... / 11400583983`, 5518/5518; no source/test/fixture/selector/build/runtime change. Accounting remains 60 / 16 / 44, debt 1.

## 2026-10-06 — `M6-CP2-TB2-COVERAGE-EXEC` COMPLETE / 491/491 mechanically green

- Immutable runtime `37419256039 / 112124748161` consumed `11391685901 / 5ce3132e...`: focused30 **30/30**, CP2-focused12 **12/12**, selector449 **449/449**, aggregate **491/491**, exact-one 491/491, zero skips, benchmark 0.
- Result/log artifacts are `11393198123 / 11393312986`; result self-manifest verifies **1005/1005**. Candidate package manifest is **28/28** before and after runtime.
- Package/source/execution-view censuses are unchanged; focused30/focused12/selector449/routing449 hashes remain frozen. No configure/compile/relink/discovery/repair/mutation/retry occurred.
- No RED or regression candidate: accounting remains **60 / 16 / 44**, debt 1.
- Candidate is mechanically green but EXEC does not close/promote CP2. Exact next: mandatory `M6-CP2-CLOSE-REV`; `M6-DEFN-R5` remains held.

## 2026-10-06 — `M6-CP2-CB2-COVERAGE` COMPLETE / compile-package GREEN

- Implemented RA-29d G1-G3 at semantic source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`: exact A7 vertex binding, dead-code cleanup / `BoundaryOrEulerMismatch` predicates, expanded identities 2-4, and the ten-row §6.3 identity-5 map.
- Added the G4 §6.2/§6.3 coverage table in `Architecture_M6_CP2_CB2_Coverage_Code_Build_Report.md`.
- Frozen focused30 / focused12 / selector449 / routing449 hashes remain unchanged; gate stays 491.
- Compile run/job `37415985763 / 112114628756` GREEN on all eight standard GMP/GMPXX targets; result/log `11391685901 / 11390994385`, manifest 28/28, clean source, `runtimeExecution=false`.
- No runtime acceptance or CP2 closure is claimed. Accounting remains **60 / 16 / 44**, debt 1. Exact next: `M6-CP2-TB2-COVERAGE-EXEC` → mandatory `M6-CP2-CLOSE-REV`.

## 2026-10-06 — `M6-CP2-TB1-VERIFIER-R2-REV` review-agent addendum: CP2 closure revoked (RA-29d)

- **Re-derived independently:** result `11387562709` (`dada6a75`) and log `11387233341` (`5a695053`); 1005/1005; all three ledgers in frozen order; 491/491; all raw hashes match. Candidate `c64baacd` == HEAD. RA-29c is implemented as specified. **The promotion is confirmed.**
- **CP2 closure revoked:**
  - **U1:** the RA-28a §2 A7 vertex binding is unimplemented;
  - **U2:** about 14 of 56 verifier sites are tested; the exact-once ledger, forest = Joining, A5 ownership and `MissingPublishedAuthority` have no executed negative; identity 5 covers one §6.3 class;
  - **U3:** dead codes;
  - **U4:** no closure record.
- **RA-29d:** `M6-CP2-CB2-COVERAGE` (G1–G4), then TB (491), then `M6-CP2-CLOSE-REV`.
- **Docs:** new CB2 plan; lesson 205; handoff / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated. Accounting 60 / 16 / 44.

## 2026-10-06 — `M6-CP2-TB1-VERIFIER-R1-REV` review-agent addendum: RA-29c replaces the A7 fallback

- **Re-derived independently from job log `112044082007`:** 491 RUN in frozen order; 462/491; 29 REDs (19 `a7:a5-relation-step`, 1 `a0:component-adjacency`, 9 downstream). R1-REV's clustering and R1-REV-02 are confirmed.
- **Owned review-agent errors:** RA-29a §3 and §4 caused both failure classes.
- **New:** RA-29b §1's same-owner-ID fallback would falsely reject inverse `canonicalRelationValue`s (A5 inverts on non-canonical storage).
- **RA-29c:** an exact three-hop binding (`a5:selected-step-value`, `a6:legacy-projection`, `a7:selected-paths`); no ambiguity witness; O(P log P), which also removes R2's O(V·P) scan; behavioral ownership check in identity 11.
- **Docs:** R3 plan block; lesson 204; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §55. Gate 491; accounting 60 / 16 / 44.

## 2026-10-05 — `M6-CP2-TB1-VERIFIER-REV` review-agent addendum: RA-29a extends verifier recovery

- **Re-derived independently:** result `11370598981` (`e9260e35`) and log `11370413984` (`a455e284`); 1005/1005; all three ledgers in frozen order; 488/491; all 491 raw hashes match; REDs at focused-12 ordinals 2, 6 and 7.
- **Confirmed:** CAND-01/02/03 (no-op or vacuous witnesses) and REV-OBS-01/03/04; REV-OBS-03 extended to A7. **Withdrawn:** REV-OBS-02.
- **New:**
  - split-class fail-open (`a6:relation-class`);
  - quadratic topology loops in production (linear-time required);
  - first-match A7 step binding (exact citation via the A6 path `orderedRelations`);
  - no A0 component-adjacency recompute;
  - an address-bound verified token.
- **Precision:** identities 6 and 7.
- **Docs:** RA-29a in frozen definitions; R2 plan block; lesson 203; handoff / ORIENTATION / TODO / ROADMAP / tracker (+0, OBS-05..09) / consolidated §54. Gate 491; accounting 60 / 16 / 44.

## 2026-10-05 — M6-CP2 TB1 verifier Review rejects first candidate; RA-29

Independent Review validates the 488/491 execution mechanics but rejects promotion. The three REDs are non-stable invalid witnesses; four static RA-28a gaps are also recovery-owned: no carried pipeline verification report, unproved wrong-region authority, duplicated support-incidence logic instead of the shared resolver, and selected-path composition without independent forest-path identity. Exact recovery is `M6-CP2-CB1-VERIFIER-R2`; gate remains 491; accounting remains 60/16/44, debt 1.

## 2026-10-05 — `M6-CP2-TB1-VERIFIER-EXEC` COMPLETE: 488/491, three non-stable Review-owned candidates

- Artifact-only retry `37368784487 / 111962223674` consumed immutable `11365308211 / 265c8fbb...`.
- Gate result: focused30 **30/30**, CP2 focused12 **9/12**, selector449 **449/449** = **488/491**; exact-one, zero skips, benchmark 0, immutable postflight PASS.
- RED ordinal 2 is a source-face permutation no-op because `SourceFaceTopologyKey::make` sorts vertices.
- RED ordinal 6 resets a certificate field already reset for `OrdinaryFront`; no payload mismatch is created.
- RED ordinal 7 fails fixture non-vacuity before verifier execution because the square fixture has no disjoint classed-cell pair.
- All three are active non-stable Review-owned candidates; no accepted-green row regressed. Stable accounting remains **60 / 16 / 44**, debt 1.
- Candidate remains unpromoted. Exact next: mandatory `M6-CP2-TB1-VERIFIER-REV`.

## 2026-10-05 — `M6-CP2-CB1-VERIFIER-R1` COMPLETE: independent verifier compile/package GREEN

- Implemented copy-by-value A5/A6/A7 verification records, independent A0/A5/A6/A7 recomputation, deterministic dependency-gated findings, exact relation/certificate-chain binding, `VerifiedSurfaceProducts`, and verifier placement after A7 / before adapter projection.
- Added frozen CP2 focused-12: semantic-order/permutation, independent A0/A5/A6/A7 checks, forbidden-repair rejection, chain binding, weld-pinched manifoldness, three wedge tampers, pipeline placement, and RA-28b representative-scope confinement. No `SurfaceMeshOptimizer` production change.
- Drive patch apply retry `37355062298 / 111915359845` produced semantic commit `3cc00697...`; the first apply attempt lost an agent-caused control-plane branch race and was not force-pushed.
- First compile run `37357362493` exposed only a new-test `DomainResult` dereference typo; bounded correction `265c8fbb...` changed `.value()` access only.
- Compile/package retry `37358279504 / 111926243775` passed all eight standard GMP/GMPXX targets. Result/log `11365308211 / 11365537617`; package **28/28**; `exactArithmeticBackend=GMP`; `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next: immutable `M6-CP2-TB1-VERIFIER-EXEC`, **491** fresh processes, then mandatory Review. Accounting remains **60 / 16 / 44**, debt 1.

## 2026-10-05 — `M6-CP2-CB1-VERIFIER-REV`: RA-28a §7 stop discharged; RA-28b; successor `M6-CP2-CB1-VERIFIER-R1`

- **Stop report verified.** A5 picks `selectedFace` from the canonical corner face; edge/vertex wedge bindings are built independently; A7 `sourceCharts` come only from bindings.
- **Root cause:** RA-28a §7 over-tightened RA-26 §5(iii) (sheet → face membership) and required an unpublished precondition. Review-agent error, owned.
- **RA-28b:**
  - no A5 invariant (the representative face stays representation-only);
  - no optimizer change: authoritative `project_vertices` is confined to the seed scope, and that static property is certified by the completion RA-22b guard and verifier RA-28a §3 before movement, and by final validation after;
  - identity 12 re-specified as a confinement falsifier (gate 491 unchanged);
  - a note for DEFN-R5 that the class-wide reference must not assume `selectedFace` ∈ class chart faces.
- **Docs:** new `Architecture_M6_CP2_CB1_Stop_Review_Record.md`; CB1 plan RA-28b block; lesson 202; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §52. Accounting 60 / 16 / 44.

## 2026-10-05 — `M6-CP2-CB1-VERIFIER` stopped for Review on RA-28a §7

- Re-derived the representative-face precondition on exact semantic source `8bc1f52b...` and found it is not certified by current A5/A7 semantics.
- A5 derives `placement.selectedFace` from the canonical corner face but edge/vertex wedge bindings from side-span/wedge traversal; no membership invariant connects them. Phase-front closure is positional, not source-face-identical. A7 `sourceCharts` are the union of wedge-binding charts.
- RA-28a's conditional stop therefore fired before repository implementation or compile/package. The exploratory verifier WIP remains unapplied and is evidence only.
- Added `Architecture_M6_CP2_CB1_Verifier_Code_Build_Report.md`; TB1 is held; runtime authority and accounting are unchanged. Successor remains UNKNOWN pending Review.

## 2026-10-05 — `M6-CP2-DEFN-REV`: CP2 verifier Definition accepted with RA-28a; CB1 released

- **Accepted:** the record-view negative seam; C4 accepted-defensive with a verifier-manifoldness falsifier; three wedge tampers; A8 after A7 and before projection; gate 491.
- **RA-28a, design fixes** before implementation:
  - exact-once / forest / spanning / cycle checks (the binding was one-directional);
  - an exact A6 → A5 field table (A6 copies verbatim; stop if a producer transforms);
  - A5 wedge, binding, sheet, seam and support checks against A0 (the evidence was self-declared);
  - dependency gating;
  - two predicate-less codes removed;
  - a `VerifiedSurfaceProducts` type invariant (the placement test was unobservable);
  - the optimizer check gated on `retained` (non-authoritative callers would regress);
  - tamper precision;
  - the A0 tuple and failure string.
- **Docs:** new `Architecture_M6_CP2_DEFN_Review_Record.md`; CB1 plan released; lesson 201; handoff / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §51. Accounting 60 / 16 / 44.

## 2026-10-05 — `M6-CP2-DEFN` froze the independent verifier candidate contract

- Defined tamperable verification record views instead of unchecked products and froze typed semantic finding identity/order.
- Froze exact A5→A6→A7 certificate-chain binding and the §6.2/§6.3 recompute/reject matrix.
- Classified C4 accepted-defensive; verifier manifoldness owns the pinched-topology falsifier.
- Added three planned wedge-rule negatives, production A8 placement, and class-wide optimizer chart-membership ownership.
- Planned CP2 focused-12; first TB gate **491**. Exact next `M6-CP2-DEFN-REV`; no implementation/runtime changed.

## 2026-10-05 — `M6-CP1-CLOSE-REV` accepted; CP1 closed mechanism-only

- Checked the six frozen CP1 exit items verbatim on current semantic source and the promoted 479/479 runtime; all pass.
- Re-ran the RA-26 provenance-consumer census: no authority-deciding consumer exists; reference-selection/permutation obligations remain later-owned.
- Kept `G4-B002` open and debt at 1; stable accounting remains **60 / 16 / 44**.
- Added `Architecture_M6_CP1_Close_Review_Record.md`, `M6_CP1_Closure_Record.md`, and the bounded `Architecture_M6_CP2_Definition_Plan.md`.
- Exact next: `M6-CP2-DEFN`; `M6-DEFN-R5` follows CP2.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-R1-REV` review-agent addendum: promotion confirmed; RA-27b; close plan amended

- **Re-derived independently:** result `11333591947` (`ef5dba11`) and log `11333547162` (`dd782961`); 497/497; focused-30 and selector449 ledgers in frozen order; 479/479; all 479 raw-log hashes match their ledgers. Candidate `3f40f04a` == HEAD.
- **Confirmed:** the RA-27a wedge rule (fixed-point reachability; region and in-set filters; fails closed on unsorted or duplicated input), the C4 `Quotient` name (required by DEFN-R3), and identity 29 on a consistent chain.
- **Corrected:**
  - the runtime proof covers one dimension of the wedge rule; the region filter and connectivity versus "touches" are static (OBS-01 → first CP2 CB);
  - C4 has no executed falsifier (→ `M6-CP2-DEFN`);
  - the C2 empty-front branch is accepted as defensive;
  - the adapter drops A7's cross-sheet site (OBS-02 → M8-CP2).
- **RA-27b:** the close plan now requires verbatim exit items, defensive-branch classification, and `G4-B002` staying open, with post-closure successor `M6-CP2-DEFN`. `M6-CP2-DEFN` absorbs the A6 → A5 binding and RA-26 §5(iii). `M6-DEFN-R5` follows CP2.
- **Docs:** close-plan review-agent block; lesson 200; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §49. Accounting 60 / 16 / 44.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-R1-REV` accepted R1 recovery and promoted 479/479 runtime

- Independently re-derived runtime `37280517630 / 111667316992`, result/log `11333591947 / 11333547162`, result manifest **497/497**, focused30 **30/30** + selector449 **449/449** = **479/479 PASS**, exact-one, zero skips, benchmark 0 and immutable postflight.
- Accepted RA-27a: exact member-local wedge connectivity and the consistent-chain identity29 falsifier are both runtime-proved; C4 diagnostic name is exact.
- Closed `M6-CP1-TB12-CLOSE-EXEC-CAND-01` as recovery-proved/non-stable; no stable repricing. Accounting stays **60 / 16 / 44**, debt 1.
- Promoted package/source `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` as current reviewed M6 runtime authority.
- Exact next: runtime-free `M6-CP1-CLOSE-REV`; CP1 remains active until its six exit items and current-HEAD close obligations are independently discharged.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-R1-EXEC` COMPLETE — 479/479 GREEN

- Candidate `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`; runtime run/job `37280517630 / 111667316992`.
- Result/log artifacts `11333591947 / 11333547162`, provider SHA-256 `ef5dba1131f25025bc536ba160475191629cc8bffed0465a087dd72fc4d1474b / dd78296134b6e71d2080ab2b1b6623841f75725e6a43deffe6ec2ad50dd46e53`.
- Focused30 **30/30** and selector449 **449/449** = **479/479 PASS**; exact-one, zero skips, benchmark 0. Result self-manifest **497/497** (`9d7f244f...a4bd67`); immutable postflight PASS.
- Identity29 RA-27a recovery and identity30 both GREEN. Zero RED rows; no new regression candidate/event; stable accounting remains **60 / 16 / 44**, debt 1.
- EXEC grants no promotion. Exact next is mandatory runtime-free `M6-CP1-TB12-CLOSE-R1-REV`; CP1 close Review remains held.

## 2026-10-05 — `M6-CP1-CB12-CLOSE-R2` COMPLETE: RA-27a recovery compiled and packaged

- Replaced A7's per-occurrence `has any isolation transition` wedge proxy with exact member-local sheet-graph connectivity over region-matching `cornerWedgeIsolation`; rejection site is `cross-sheet:wedge`.
- Corrected C4 diagnostic name to `QuotientClosedComplexStripContinuationMismatch`; selected-forest cross-sheet edge semantics remain unchanged.
- Recovered identity29 with baseline A5→A6→A7 acceptance, bridge-wedge-only tamper, A5 republish, fresh A6 production/success, then exact A7 wedge rejection. No stale A6 is reused.
- Verified frozen focused30 / selector449 / routing449 hashes unchanged.
- Drive patch apply run/job `37277892065 / 111658980414` produced semantic source `3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`; owner-authorized Drive deletion completed.
- Compile run/job `37278068286 / 111659540374` passed all eight standard GMP/GMPXX targets. Result/log `11330703256 / 11330837905`; package 28/28; clean source receipts; `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next: immutable `M6-CP1-TB12-CLOSE-R1-EXEC` at 479 processes, then mandatory R1 Review. Accounting remains **60 / 16 / 44**, debt 1.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-REV` review-agent addendum: RA-27 withdrawn → RA-27a; R2 re-scoped

- **Re-derived independently:** result `11326949864` (`da42bf2a`) and log `11328055226` (`70880747`); 979/979; focused-30 and selector449 ledgers in frozen order; 478/479; ordinal 29 fails before its tamper. Candidate `02149f15` source == HEAD.
- **Code review:** C2 and C3 accepted. C4 fails closed, but its name lacks the `Quotient` prefix and the branch has no executed falsifier.
- **CAND-01 cause corrected:** the split-isolation fixture has no disjoint-sheet relation (the diagonal seam crosses cells; crossings happen inside bridge corners), so forest selection is irrelevant. RA-27 §2–§3 are withdrawn.
- **High:** C1 left the reachable per-occurrence wedge proxy (`RemeshPipeline.cpp:6884-6895`) in place, and neither A5 publication nor A6 checks it. **RA-27a** requires:
  - an exact wedge rule (site `cross-sheet:wedge`);
  - the C4 name fix;
  - identity 29 on a bridge-member tamper with A6 re-produced (consistent chain).

  The edge-rule falsifier is deferred.
- **Observations:** OBS-01 (A6 has no binding to its A5) and OBS-02 (relation-kind-agnostic edge rule).
- **Docs:** R2 plan review-agent block; lesson 199; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §47. Accounting 60 / 16 / 44.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-REV`: identity29 is a fixture-witness false rejection; RA-27 recovery

- Independently re-derived TB12 478/479 and exact ordinal29 failure before the C1 tamper.
- The split-isolation fixture is not contractually required to put a cross-sheet relation in A6's selected spanning forest; absence of that selected edge is not a production-selection defect.
- CAND-01 -> **FALSE REJECTION / TEST-FIXTURE WITNESS DEFECT / RECOVERY REQUIRED / NON-STABLE**. Candidate remains unpromoted; C1 negative runtime proof remains outstanding.
- RA-27 authorizes test-only `M6-CP1-CB12-CLOSE-R2`; no production change. Recovery gate remains focused30 + selector449 = 479, then mandatory R1 Review. Accounting 60 / 16 / 44, debt 1.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-EXEC`: mechanically valid 478/479; identity29 witness non-vacuity RED

- Runtime `37266239234 / 111623615471`: focused30 **29/30**, selector449 **449/449**, aggregate **478/479**, exact-one, zero skips, benchmark 0, 979/979 evidence and immutable postflight.
- Sole RED identity29 has no selected cross-sheet forest edge; its C1 tamper is never reached.
- Recorded non-stable Review-owned CAND-01; stable accounting **60 / 16 / 44**, debt 1. Candidate unpromoted; exact next `M6-CP1-TB12-CLOSE-REV`.
- Earlier run `37264751953` was startup-invalid with zero jobs due unquoted YAML colon; corrected and schema-validated before runtime.

## 2026-10-05 — `M6-CP1-CB12-CLOSE-R1`: C1–C4 compile/package GREEN; TB12 next

- Implemented exact A7 cross-sheet isolation-transition connectivity, distinct A5 source diagnostics, A5-owned validated isolation-certificate accounting, and RA-25 fail-closed strip-continuation ambiguity.
- Added identities 29/30 and focused-30 (`1e815443...a1d6`) with exact focused-28 prefix. C5 remains discharged by RA-26; optimizer/final validation unchanged.
- First compile-only run `37259162318` exposed one pointer member-access typo; bounded one-line correction produced final source `02149f1518fc6a753acf3235f7dcdc6fcdf59f24`.
- Compile/package run/job `37259524323 / 111603703243` GREEN for all eight GMP/GMPXX targets; result/log `11324028392 / 11323679468`, 28/28 manifest, clean source, `runtimeExecution=false`.
- Exact next: immutable artifact-only `M6-CP1-TB12-CLOSE-EXEC`, gate **479**, then mandatory Review.

## 2026-10-05 — `M6-CP1-CB12-CLOSE-REV`: CB12 C5 stop discharged; RA-26; successor `M6-CP1-CB12-CLOSE-R1`

- **Source authority:** HEAD source is byte-identical to the reviewed runtime `8dd95821` (both fetched by SHA after the history squash).
- **Flagged site reclassified:** `SurfaceMeshOptimizer.cpp:3015-3031` reads source-mesh incidence, not a provenance face, and is test-only (`make_surface_optimization_overlay` has no production caller). OBS-01 → M8-CP2.
- **Full audit** of 12 optimizer and final-validation sites: no authority-deciding consumer.
  - Optimizer energy/gradient (corner 0's representative face for normal and field) and the field-metric fallback are reference-selecting.
  - **RA-26** re-homes them to `M6-DEFN-R5` / `M6-CP3`, with a representative-permutation falsifier.
- **CB12 plan:** gains an RA-26 header block. C5 is discharged; R1 runs C1–C4 and identities 29/30 with no optimizer change.
- **Docs:** new Review record `Architecture_M6_CP1_CB12_Close_Stop_Review_Record.md`; lesson 198; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0, OBS-01/02) / consolidated §44. Accounting 60 / 16 / 44.

## 2026-10-05 — Workflow mailbox becomes authoritative run-discovery process

- Added durable `.github/workflows/workflow-mailbox-publisher.yml` from the approved GitHub connector workflow-mailbox protocol.
- Updated ChatGPT Web workflow, tool-conservation, cleanup, retention, start/end, handoff, agent and compile policies so `.workflow-mailbox/<workflow-key>/latest.json` is the authoritative completed-run rendezvous; immutable per-attempt records remain under `runs/`.
- PR run-observer comments are now fallback-only. Repository-wide recent-run discovery and the legacy branch-file observer remain secondary/tertiary fallback paths when mailbox publication is absent or fails.
- Updated source-snapshot and turn-cleanup workflows to publish mailbox records after their artifacts; observer fallback executes only when mailbox publication fails.
- Smoke validation: source-snapshot run `37251013709` published `repo-source-snapshot/latest.json` for exact source/event SHA `3d3ddcef4b7cb60d72dc5aee6a2c774dce8b04f2`; validate, snapshot and mailbox jobs all succeeded; fallback observer was skipped.

## 2026-10-05 — `M6-CP1-CB12-CLOSE` stopped at C5 audit

- Found an anchor-assuming optimizer consumer at `SurfaceMeshOptimizer.cpp:3015-3031`: first incident source face -> one component/sheet scope -> break.
- RA-22b / RA-25 and the CB12 plan require Stop for Review and forbid fixing it inside CB12.
- No C1-C4 code/test edits, identities 29/30, compile/package, or runtime started. Reviewed runtime stays 477/477; accounting 60 / 16 / 44, debt 1.

## 2026-10-05 — `M6-CP1-TB11-G4-R1-REV` review-agent addendum: promotion confirmed; RA-25; successor `M6-CP1-CB12-CLOSE`

- **TB11-R1 re-derived independently:** result `11316968568` digest `1082edce...`, 973/973 manifest, focused-28 and selector449 ledgers in frozen order (477/477), ordinals 25/28 OK; HEAD == `8dd95821`.
- **Confirmed:** the RA-24 production change (vertex-incident edge-loop continuation; nothing else changed) and the identity 25/28 oracles.
- **M1:** the continuation drops non-unique opposites silently (`RemeshPipeline.cpp:6305`). **RA-25** makes it fail closed.
- **Successor re-routed** to close-out CB12, because the CP1 carried obligations need code:
  - exact A7 cross-sheet certification through `fromSheet/toSheet`;
  - distinct A5 diagnostics;
  - A5-sourced isolation counter;
  - RA-25;
  - provenance-face consumer audit.

  New plan `Architecture_M6_CP1_CB12_Close_Out_Code_Build_Plan.md`; gate 479.
- **Docs:** lesson 197; handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §43. Accounting 60 / 16 / 44.

## 2026-10-04 — `M6-CP1-TB11-G4-R1-REV` accepted recovery and promoted R1 runtime

- Independently re-derived candidate `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` and runtime `37240414090 / 111547976292`: package 28/28, result 973/973, focused28 28/28 + selector449 449/449 = **477/477**, exact-one, zero skips, benchmark 0, immutable postflight.
- RA-24 is discharged: production strip closure is edge-loop continuation at interior valence-4 quotient vertices; identity28 independently reconstructs the partition, validates emitted candidates, requires a produced eligible closed loop and reaches tamper rejection.
- RA-21c/RA-21d is discharged: identity25 uses per-occurrence arrangement witnesses, exact reciprocal phase-front/relation authority and barrier-only relaxation; Ordinary non-isolation chain/node equality remains exact.
- Closed CAND-01 as recovery-proved false-rejection/non-stable and CAND-02 as recovery-proved production-definition defect/non-stable; no stable repricing. Accounting remains **60 / 16 / 44**, debt 1.
- Promoted `11316716869 / 8dd958...` as current reviewed M6 runtime authority. Authorized exact successor `M6-CP1-CLOSE-REV`; CP1 is not yet closed.

## 2026-10-04 — `M6-CP1-TB11-G4-R1-EXEC`: 477/477 artifact-only recovery gate GREEN

- Executed immutable candidate `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` at run/job `37240414090 / 111547976292`.
- Focused28 **28/28**, selector449 **449/449**, aggregate **477/477 PASS**; exact-one selection, zero skips, benchmark 0, header-only RED ledger.
- Ordinals 25 and 28 both PASS under the strengthened R1 identities.
- Result/log artifacts `11316968568 / 11317493022`; result self-manifest **973/973**; package/source/execution-view and frozen gate authorities unchanged.
- No configure/compile/relink/discovery/repair/mutation/retry occurred in EXEC. +0 new regression events/candidates; stable accounting remains **60 / 16 / 44**, debt 1.
- Candidate remains unpromoted. Exact next after cleanup is mandatory `M6-CP1-TB11-G4-R1-REV`.

## 2026-10-04 — `M6-CP1-CB11-G4-R1` COMPLETE: RA-24 / RA-21d recovery compiled and packaged

- Replaced quad-opposite rung-set strip closure with RA-24 edge-loop continuation at interior valence-4 quotient vertices; no other production behavior changed.
- Identity25 now uses per-occurrence arrangement witnesses and retains exact shared chain/node equality only for Ordinary non-isolation edges; HardRail, Periodic and isolation seams are validated per-side.
- Identity28 independently reconstructs the produced-torus edge-loop partition, validates every emitted candidate, requires an eligible `ClosedLoop`, and keeps hard-feature tamper rejection.
- Pre-apply static review caught a missing `<numeric>` include and corrected it before repository application.
- Patch apply run/job `37238821980 / 111543246587` produced semantic source `8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`; owner-side Drive cleanup succeeded.
- Mandatory compile run/job `37238936105 / 111543578349` passed all eight standard GMP/GMPXX targets. Result/log artifacts `11316716869 / 11316583672`; package manifest 28/28; clean receipts; `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next is `M6-CP1-TB11-G4-R1-EXEC`, focused28 + selector449 = **477**, then mandatory Review. Accounting remains **60 / 16 / 44**, debt 1.

## 2026-10-04 — `M6-CP1-TB11-G4-REV` review-agent addendum: F2 overturned (RA-24 edge-loop strips); RA-21d; R1 re-scoped

- **TB11 re-derived independently:** result `11312313559` digest `7de4a320...`, 973/973 manifest; RED at focused 25 and 28; selector449 449/449.
- **F2 overturned.** Ordinal 28's `extracted.candidates` is empty, not "no eligible emitted candidate".
  - R4 D3 §4.3 rule 7's quad-opposite closure (`RemeshPipeline.cpp:6289-6291`) yields rung sets.
  - The path-degree classifier (`:6343-6436`) skips them, so there are zero candidates on any closed quad complex.
  - RA-23's synthetic 4×4 torus would fail identically, and the test-only R1 was doomed.
  - **RA-24:** edge-loop (strand) closure, the topology analogue of the retired `(family, strand)` connected curves. The produced torus is expected to yield eligible loops parallel to its hard cycles.
- **F1 confirmed.** RA-21d keeps arrangement chain and node equality across Ordinary non-isolation edges; relaxation applies only across barrier seams.
- **R1 plan re-scoped:** R1-0 changes the production strip relation only; identity 25 per RA-21c/d; identity 28 uses the produced torus.
- **Accountability:** R4 D3 rule 7 was accepted by R4-REV (review agent). Lesson 196.
- **Docs:** handoff (top + live) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §41. Accounting 60 / 16 / 44.

## 2026-10-04 — `M6-CP1-TB11-G4-REV` rejects CB11 candidate; RA-21c / RA-23 recovery frozen

- Independently re-derived TB11: candidate 28/28, result 973/973, focused **26/28**, selector449 **449/449**, aggregate **475/477**, exact-one, zero skips, benchmark 0 and immutable postflight.
- Ordinal25 is a false rejection: RA-21b conflated quotient identity across distinct relation-cut occurrences with physical arrangement-node/chain identity. RA-21c replaces the oracle with per-occurrence/per-side degree-2 arrangement witnesses plus reciprocal A4 and A5/A6 relation authority.
- Ordinal28 is a definition/fixture-witness gap, not a demonstrated extractor defect. The old arrangement `(family,strand)` candidate does not prove non-vacuity under quotient opposite-edge strip closure. RA-23 separates produced-torus universal checks from CP1 mechanism-only non-vacuity/tamper on a canonical closed 4x4 toroidal A6 test view.
- `M6-CP1-TB11-G4-EXEC-CAND-01` closed false-rejection/non-stable; CAND-02 reclassified non-stable definition-witness recovery. Stable accounting remains **60 / 16 / 44**, debt 1.
- Candidate `11308472138 / 582da20a...` remains unpromoted; reviewed runtime remains `11299078582 / 96b456f9...`. Exact next is `M6-CP1-CB11-G4-R1` (test-authority recovery only), then unchanged 477 TB gate and mandatory R1 Review.

## 2026-10-04 — `M6-CP1-CB11-G4` COMPLETE: A6 closed-complex boundary compiled and packaged

- Implemented the RA-20/RA-21/RA-21b A6 `SurfaceQuotientClosedComplexView`, including canonical side-incidence edges, certificate-derived relation labels, explicit typed-source hard-feature protection, quotient lineage and opposite-edge strip closure.
- Candidate extraction now consumes the A6 closed-complex view directly and does not require retained arrangement authority.
- Added focused identities 25-28. Focused28 SHA-256 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`; focused24 is its exact prefix.
- First compile exposed only test/API compile-contract defects. A bounded runtime-free correction produced semantic source `582da20a925ba920c923bf5aacb9e0e56ef0723d`.
- Final compile run/job `37216400150 / 111477707423` passed all eight standard GMP/GMPXX targets. Result/log artifacts `11308472138 / 11308317584`; 28/28 manifest; clean source receipts; `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next is `M6-CP1-TB11-G4-EXEC`, focused28 + selector449 = **477**, then mandatory Review. Accounting remains **60 / 16 / 44**, debt 1.

## 2026-10-04 — `M6-CP1-TB10-A5V-R1-REV` review-agent addendum: promotion confirmed; RA-21b readies CB11

- **TB10-R1 re-derived independently:** result `11300407906` digest `b9f2daed...`, 965/965 manifest, focused-24 and selector449 ledgers in frozen order (473/473), focused 20/24 OK; HEAD == `96b456f9`.
- **R1 confirmed:** publish first, then the moved checks on the published complex (`RemeshPipeline.cpp:4937-4951`, `:3467`, `:3603`).
- **Identity 24 confirmed** to assert every field of the result, mesh and both lineage structs.
- **CB11 pre-analysis:**
  - proposals map positionally to `phaseFront.cells()` with no `CellId` (`SurfaceCellTracing.cpp:17901-17916`);
  - `halfedge.proposalId` is the primary entry only (`SurfaceArrangement.cpp:2426`; the provenance groups are at `:2701-2709`);
  - cell sides are per-face polylines.
- **RA-21b:** positional preconditions, provenance side chains, degree-2-contraction equivalence, chain `hardFeature` labels; RA-21's stop rule kept for every other kind of subdivision. CB11 plan amended.
- **Docs:** lesson 195; handoff live section (it still said CB10-R1) / ORIENTATION / TODO / ROADMAP / tracker (+0) / consolidated §39. Accounting 60 / 16 / 44.

## 2026-10-04 — `M6-CP1-TB10-A5V-R1-REV` accepted recovery and promoted R1 runtime

- Independently re-derived candidate `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` and runtime `37194004252 / 111411987330`: package 28/28, result 965/965, focused24 24/24 + selector449 449/449 = **473/473**, exact-one, zero skips, benchmark 0, immutable postflight.
- F1/RA-19 is discharged: A5 publication precedes moved validation and the helper consumes the published complex certificate/cells/occurrences.
- F2 is discharged: identity24 independently covers every adapter-written result/mesh/vertex-lineage/face-lineage field.
- Closed TB10 Review CAND-01/CAND-02 as recovery-proved/non-stable; no stable repricing. Accounting remains **60 / 16 / 44**, debt 1.
- Promoted `11299078582 / 96b456...` as current reviewed M6 runtime authority. Authorized exact successor `M6-CP1-CB11-G4`; TB11 is 28+449=477 then mandatory Review.

## 2026-10-04 — `M6-CP1-TB10-A5V-R1-EXEC`: 473/473 artifact-only gate GREEN

- Executed immutable R1 candidate `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` at run/job `37194004252 / 111411987330`.
- Focused24 **24/24**, selector449 **449/449**, aggregate **473/473 PASS**; exact-one selection, zero skips, benchmark 0, header-only RED ledger.
- Result/log artifacts `11300407906 / 11300542138`; result self-manifest **965/965**; package/source/execution-view and frozen gate authorities unchanged; package manifest remains **28/28**.
- No configure/compile/relink/discovery/repair/mutation/retry occurred in EXEC.
- +0 new regression events/candidates; stable accounting remains **60 / 16 / 44**, debt 1. Existing TB10 Review CAND-01/CAND-02 remain open for mandatory R1 Review.
- Candidate remains unpromoted. Exact next after EXEC cleanup is `M6-CP1-TB10-A5V-R1-REV`; CB11 held.

## 2026-10-04 — `M6-CP1-CB10-A5V-R1` COMPLETE: RA-19a ordering / full projection oracle; compile-package GREEN

- Restored RA-19a validation precedence: `publish_records_for_validation` now precedes moved phase-front checks, and the helper consumes the published `SurfaceOccurrenceComplex`, including certificate-directed side count and published cells.
- Strengthened `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` to the TB10 Review §J3 exact field-table oracle using independent A5/A6/A7/A4-derived expectations and fixed/default compatibility values.
- Preserved focused24/focused20/selector449/routing449 hashes exactly: `6bcc8a...067bf / 15d04a...827d2 / d4a0d1...d6414 / 9c88a5...6c5707`.
- Drive patch `d1880a55...faeb` applied in run/job `37192632740 / 111407894004`, producing semantic commit `96b456f925be00e00bad6645e6eb905a804c14ea`; owner-side Drive deletion succeeded.
- Mandatory compile run/job `37192727051 / 111408174395` passed all eight standard GMP/GMPXX targets. Candidate artifact `11299078582` (`sha256:142bac1b...5afd`), log `11299068422` (`sha256:1ede0d09...b6c50`), manifest 28/28, clean source receipts, `runtimeExecution=false`.
- Candidate remains unpromoted. Exact next is `M6-CP1-TB10-A5V-R1-EXEC`, focused24 + selector449 = **473**, then mandatory Review; CB11 held.


## 2026-10-10 — M6-DEFN-R5-R4-REV source-only architecture review

Independent source-star proof confirms the face-2 to face-3 terminal-germ candidate, rejects any claim of an already producer-authenticated contact, and identifies conflict between RA-40.1 and conditional-null-atlas RA-41.1. Review returns `REVIEW_BLOCKER` R4-REV-01/02; RA-41 remains unfrozen and R4 CB is held. See `Architecture_M6_DEFN_R5_R4_Independent_Review_Record.md`. No binaries, compile, tests, selectors, source producer or normative definitions changed.
