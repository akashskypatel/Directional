# M6-CP3-CB1-ENTRY-R3 — mandatory source-producer preflight STOP (2026-10-08)

## Post-RA-38 source preflight recheck (2026-10-08)

**Disposition: the RA-38 sector-construction STOP is resolved; the independent
spatial-endpoint ownership STOP is not.** On exact source
`e5ecfc91af02462016029732120df6cb36853509` (snapshot workflow
`37802439839`, artifact `11560713142`, 5,672 verified source files),
the implemented A4 producer still cannot provide a witnessed local `P0`
and `P1` path for a genuine produced paired HardRail front.

RA-38 proves how to derive the two source-side sectors: cut the orientable
vertex-star cycle at its two incident hard-carrier spokes, creating two
separate radial arcs of nonrail A3 transitions. This removes the earlier
*sector-existence* ambiguity only; it does not attach either observed A4
front endpoint to its owning rail-side wedge or locate the single owner-rail
crossing at that endpoint. A source-input 3×3 fan is not a produced front.

The bounded source inspection found no endpoint-local witness in
`SurfaceHardRailRouteEndpointCertificate` (two face attachments, a
carrier-only `orientedSteps` list, one composed turn). In
`SurfaceCellTracing.cpp:18271-18371`, both `endpoint_certificate`
instances independently receive trace-selected face rows, but each
traverses **all** route carriers from its starting face, rather than
restricting to its own spatial endpoint, admissible within-sector radial
path, and one local crossing. A later `railFanPotentials` comparison
cannot create the missing owner wedge. In `:8019-8118`, the independent
cardinality error (`endpoint.orientedSteps.size() == route.steps().size()`)
and carrier-to-carrier face equality remain. Both must be removed together
only after producer-owned endpoint source attachment is established.

**Mandatory next independent producer Design Review:** demonstrate from
real paired-front `first/second` product data the exact source endpoint,
incident owner-rail carrier and side wedge for each of `P0=(first.from,
second.to)` and `P1=(first.to, second.from)`; show the disjoint,
orientation-correct nonrail A3 paths and exactly one local crossing per
endpoint, plus their typed transported commuting square. If no real
multi-carrier product is produced in bounded search, record it as
unexercised; do not claim positive witness coverage. Keep RA-36.4/.5/.6,
RA-34.3 and all six nonvacuity gates. **Do not implement a guessed
replacement, modify selectors, run a compile, or start TB/CB2.**

The prior preflight's original evidence remains retained below. This
recheck made no source, test, selector or build mutations. Accepted CP2
491/491, rejected R2 444/497, 47 accepted-green losses, stable 64/17/47
and debt 1 remain unchanged. Turn `M6-CP3-CB1-ENTRY-R3` remains held at
its mandatory preflight; no new successor is invented.

---

## Disposition

**Conditional/architectural STOP under independently accepted RA-37a.** The source-only preflight does not establish the two independently source-attached endpoint-local cross-rail paths required for an A4 HardRail paired-front product. Do not replace the existing unsound fold with a guessed sector, a global face-star potential, a first-by-row face choice, or a new τ definition. **No production-source/test/build/selector files were changed; no compile or runtime verification was attempted.** The R3 Code + Build turn cannot be formally completed. Return the missing A4 ownership proof to an independent producer Design Review before making semantic edits.

This is **not** a proof that the intended producer is impossible. It records that its required source/owner witness and local endpoint-binding decision have not been demonstrated at the mandatory preflight gate. It also does not claim that every R2 RED has the same first cause.

## Immutable evidence

- Source authority: exact post-entry source-snapshot SHA `3c8fb8e3375c616e3ac7a184b3909b94504669c7`, workflow run `37792789519`, artifact `11557381370`, archive SHA-256 `4586d91d9247aadde1ebdae795b0b43395bdfed6f2343738119e2352388b6dfd`. Embedded source `source.tar.gz` and all **5,668/5,668** SHA256SUMS entries verified. Compared with reviewed source `6b2a167341101c686d5d839aa1e2e4cc3a67aff2`: subsequent branch delta was docs, STATUS, mailbox and workflow-trigger state, **not** semantic `src/` or `tests/` modifications.
- Independently rejected R2 gate: immutable artifact `11545716507` verified **1,019/1,019** internal hashes. R2 is **444/497** with 47 accepted CP2-to-R2 regressions, not a valid promotion. Logs contain terminal `InvalidHardRailRouteCertificate`, but do not publish first-rejection predicate, actual failed route length, endpoint-local owner-side wedge, or complete face/transport witnesses.
- Binding review: `Architecture_M6_DEFN_R5_R3_Review_Record.md` RA-37a A1–A4 and R3-REV-01/02, and `Architecture_M6_CP3_CB1_Entry_R3_Recovery_Code_Build_Plan.md` STOP FIRST.

## Source-level findings

1. `src/geometry/SurfaceCellTracing.cpp:18120-18206` builds `railFanPotentials` by traversing the **whole** vertex face star, including hard carriers. RA-37a permits these A3 values only as a post-ownership consistency cross-check. They do not distinguish the two disjoint owner sectors or ensure that a paired front's selected trace face attaches to the correct source side.
2. `src/geometry/SurfaceCellTracing.cpp:18271-18371` constructs both `endpoint_certificate(first.from.face, second.to.face)` and `endpoint_certificate(first.to.face, second.from.face)`. Each function nevertheless starts at its first attachment and advances `current` across **every** route carrier by comparing one carried face with the next carrier's incident faces (`:18312-18330`), then sums carrier `firstToSecond` turns. This is a face-domain discontinuity for valid consecutive distinct carriers, not a certified local endpoint crossing. The later `phiA/phiB` star-potential comparison (`:18337-18359`) cannot establish prior source-owner sector admissibility.
3. `include/directional/geometry/SurfaceCellTracing.h:1488-1502` represents an endpoint as two attachments, the `orientedSteps` vector, and one `composedTurn`. There is no ordered independently source-attached **local P0/P1 cross-rail path**, no per-step nonrail radial A2b source-edge witness, no unique oriented sector, and no explicit local-owner crossing/codomain evidence. This absence is not fixed by renaming the existing fields.
4. `src/geometry/SurfaceCellTracing.cpp:8019-8118` validates endpoint paths by requiring one transition for every route carrier and `previous.secondFace == next.firstFace`. For the already reviewed 3×3 legal hard rails `(1,4)` and `(4,7)`, the respective carrier incident faces are `{0,3}` and `{4,7}`; no face is shared. The source topology may have two oriented radial chains (`0→1→4`, `3→6→7`) without making either chain an actual A4-produced endpoint attachment. An input fixture is **not** a genuine produced multi-carrier certificate.
5. The A5 consumer `src/pipeline/RemeshPipeline.cpp:4932-4990` can only consume the published A4 endpoint attachments/turns. It must not perform its own path search or infer an alternate certificate from sheet/region labels.

## Required independent producer Review decision

Review must answer, with concrete typed A2b source-star and A4 front-product evidence rather than only the hand-authored 3×3 input:

1. For a **real** pair of opposite HardRail front edges, what exact source-attached owner-side ray/wedge maps each of the four trace-selected endpoint faces to the two unique oriented sectors at each carrier junction? How is unique orientation established for all admitted link types, and how are boundary, singular, hard-barrier and nonmanifold cases rejected?
2. For `P0=(E.from,E'.to)` and `P1=(E.to,E'.from)` **independently**, identify their actual local spatial endpoints, source-face attachments and typed paths of zero or more admissible same-side radial transitions plus exactly one owner-rail crossing, including the direction and `τ_j`. A path reaching the other spatial endpoint is not locally admissible.
3. Specify the exact typed domains and codomains for each source-keyed A3 transport arrow, reciprocal inverse, and `χ_(i+1) ∘ φL_i = φR_i ∘ χ_i` commuting square **after** owner topology fixes both sectors. Demonstrate a produced multi-carrier example, or explicitly declare the producer case unsupported with a typed fail-closed condition.
4. Show how `SurfacePhaseFrontProduct::make` validates the new certificate without silently retaining the existing false consecutive-carrier face-equality rule, and how the singleton length-one case remains unchanged.
5. Require the existing `invalid_route()` to report a bounded deterministic **first-locus** predicate, route length, carrier/source-face keys, spatial endpoint identity and owner sector on the next authorized diagnostic/code turn. Classify the 25 direct A4 REDs and downstream rows before any semantic acceptance change.

## Frozen boundary and continuation

- No guessed R3 implementation, unverified direct promotion, recovered source-grid fallback, arbitrary search, test oracle change, selector rename or test/benchmark execution.
- Accepted CP2 remains **491/491**; frozen future entry gate remains **497 = 30 + 12 + 449 + 6**, with the **47** R2 lost-green identities protected. Stable ledger remains **64 events / 17 categories / 47 recurrences**, debt **1**.
- A6 seam-isolation and organic D1/D2/D3/D5 nonvacuity remain independently open.
- This stop report is the only durable new task artifact. Do not fabricate a successor turn identifier; independent Design Review must explicitly reauthorize continuation of R3 Code + Build and its compile-only gate. The root STATUS beacon remains the authoritative state indicator.
