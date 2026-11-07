# RA-146 — FG01 independent factory-contract review (2026-10-23)

**Turn:** `M6-CP3-DEFN-FG01-RP01-PERIODIC-FACE-GAUGE-FACTORY-CONTRACT-REV`.
**Verdict: ACCEPT WITH BINDING AMENDMENTS.** The missing-gauge diagnosis and fixture-only correction are sound. FG01 as originally written is incomplete about witness strength and permutation non-vacuity; it does not establish periodic production correctness. Authorize only `M6-CP3-CB30-RP01-PERIODIC-OWNER-FIXTURE-GAUGE` below. No production correction, gate promotion, or other failure-owner work is authorized.

## Independently checked authority

Reviewed origin `44ac66b3660b3a643f5ca677c24e41e314123619`; GitHub compare from CB29 semantic `2602e7398cdc6f1281abe11a758de35166b6590c` is ahead by 61 commits with no src/include/tests/benchmark/build changes. Thus the inspected implementation is the CB29 implementation, not an assumed newer repair. Entry beacon is documentation only.

Downloaded TB31 artifact `12506242253`, run `39959505758`; independently obtained ZIP SHA-256 `97828fac57a63b5d8ca85ef0e5fd35fb7d5ed71c2b2579cd463bacc20d5e947b` and verified 1,000/1,000 internal checksums. Read all six raw logs (262,263,338,344,346,481), matching their ledger hashes, exact names, one executed test, terminal failure and `face-gauge-missing` exception before owner assertions. This is artifact inspection, not new test execution.

Rehashed frozen 30/12/449 components:
- 30: `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`.
- 12: `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`.
- 449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.
- TB31 manifest: `b1c135d429f8c659e190f648b8678669cb7c14d393e0db9069568ea3838aa43e`.

These are unchanged authority, not a new accepted prefix. CP2 491/491 remains accepted; TB31 472/497 remains candidate. Stable 66/17/49, debt 1, RP-01 open, RP-02 unreached, Gate C suspended.

## Findings and architectural adjudication

### RA-146.1 — confirmed fixture defect; preserve production admission

`tests/SurfaceCellTransitionQuotientTests.cpp:283–406` constructs one two-face disk region, two periodic-owner records and a real field atlas, but its factory call omits the gauge. `SurfaceCellTracing.cpp:8492–8498` correctly rejects absent gauges when periodic or seam consumers exist. The relational pin at 8509–8597 authenticates reciprocal transport across same-region, non-hard two-face edges and requires connected pin domains. This matches RA-45 and RA-111; a two-face disk has one such diagonal, (0,2), so deriving the second gauge from that edge is sufficient for this bounded witness.

The cloning/reconstruction path at TQ:1897–1955 already preserves the vector and atlas; no second repair there is needed. Production publishes its face gauges already. Do not change the factory, atlas, transport model, runtime, or original six assertions.

### RA-146.2 — high-impact evidence limitation: synthetic ownership is not periodic production

The fixture's `SurfaceFrontEdge` values leave `oppositeEdge=-1`, routes empty, shared intervals and periodic endpoints absent. The factory's reciprocal/action checks at S:9414–9559 are conditional on a reciprocal opposite pair; this witness never enters them. Its synthetic generator routes even name boundary edges as interior routes through the test-only helper. The relation constructor/owner map can represent those tokens without establishing realizable annular/torus holonomy.

**Decision:** admit this fixture solely as an owner-map/factory unit witness. It may test missing, duplicate, foreign, conflicting and reordered owner records. It cannot be called a producer-equivalent periodic product, a valid A5/A6 materialization witness, or evidence that real periodic topology/transport is correct. No new bypass is needed: the existing factory admits a deliberately limited shape. Whether every production-reachable malformed unpaired periodic front should be rejected is a separate reachability/contract question, not established as a production bug here. Do not expand FG01 into factory redesign.

Static path inspection finds no additional rejection for this fixture after legal gauge input: nonempty cells/edges, valid region/cell ownership, distinct canonical relation IDs, present owners, empty seam/bounded-disk obligations; paired periodic guards are not applicable. This supports a falsifiable six-PASS prediction, **not a measured result**.

| Frozen identity | Intended observation after valid baseline |
|---|---|
| selector:220 | Removing edge owner rejects MissingPeriodicRelationOwner |
| selector:221 | Reordering relation storage preserves the complete independently captured owner values |
| selector:296 | Duplicate identity/value rejects DuplicatePeriodicRelationId |
| selector:302 | Foreign relation region rejects InvalidPeriodicRelationRegion |
| selector:304 | Unknown edge owner rejects MissingPeriodicRelationOwner |
| selector:439 | Same ID with changed action rejects ConflictingPeriodicRelation |

There are exactly six direct helper call sites. Relation ordering tests and tampering remain unchanged. Preserve the produced torus owner guards (including selector:445); no synthetic credit for G4-B002.

### RA-146.3 — incomplete permutation oracle

FG01's same-field planar baseline does not require unequal gauges or nonzero directed transport. Permuting equal values cannot detect a row/topology association defect, and zero or half-turn transport cannot distinguish a direction inversion. Merely requiring that the atlas be real is insufficient to make this oracle discriminating.

**Amendment:** separate a small subsequent transport/permutation unit. Require real atlas transport with value 1 or 3 on the shared edge, reciprocal inverse, unequal derived gauges, a topology-keyed root and complete remapping of face rows/field rows/authority. Valid remapping must preserve semantic owner outcomes. A stale unremapped vector must reject at the same canonical edge; reversing the directed transport must be independently detected. Cyclic triangle-corner rotation preserves orientation; arbitrary winding reversal is not silently included. Obtain branch relabeling through the actual raw-field/atlas ingress, never forge atlas transitions. If the chosen ingress canonicalizes away the odd transition, stop with that evidence rather than weaken the precondition.

This is a separate planned unit, not extra work hidden inside CB30. No generic mesh-gauge solver or new production abstraction is justified.

### RA-146.4 — factory shift is not A6 gauge invariance

FG01's uniform-shift row observes only checked-factory admission. RA-45.4 additionally requires identical A6 relation outcomes, while RA-45.5 forbids normalization and explicitly allows provenance digest changes. The two-edge synthetic witness cannot discharge that later obligation.

The existing `M6CP3.A6UniformFaceGaugeRotationPreservesRelationOutcome` test at TQ:2995 onward compares actual A5/A6 products, certificates, consumption and paths, but its identity is absent from the frozen TB31 497-row manifest. Its current runtime result is therefore **unverified by TB31**. Do not infer PASS from its existence or from selector counts. Preserve this produced-witness obligation under the periodic/DEFN-T1 owner; don't add it to CB30 or edit frozen selectors. Factory-level shifted-input preservation remains a useful, narrower control.

## Exactly one authorized implementation unit

**NEXT_TURN: `M6-CP3-CB30-RP01-PERIODIC-OWNER-FIXTURE-GAUGE` (compile-only).**

Only `tests/SurfaceCellTransitionQuotientTests.cpp` may change as executable source:
1. In the shared direct fixture, resolve the two source faces by topology key and the exact shared edge; resolve rows through existing authority. Choose the first semantic face's local representative zero; derive the other value from the real directed atlas transition; independently require reciprocal inverse, same region and non-hard incidence.
2. Supply the resulting two-entry vector at the existing optional factory argument, retaining all other fixture topology, relations, original six tests and factory behavior. Reuse existing draft helpers. No generic solver, no all-zero shortcut.
3. Add three narrowly named companion cases in the existing test target: `SurfacePhaseFrontProductFactoryAuthority.PeriodicOwnerFixtureMissingGaugeRejects`, `PeriodicOwnerFixtureOneFaceGaugeTamperRejects`, and `PeriodicOwnerFixtureUniformGaugeShiftPreservesOwners` (same suite). Each first establishes a valid unmodified baseline. Missing gauge must yield InvalidSourceAuthority/face-gauge-missing; one-face +1 must yield InvalidSourceAuthority/gauge-pin-consistency;edge=0,2; uniform +1 must preserve complete owner values and preserve the supplied shifted vector byte-for-value, without asserting equal digests. No A6 claim.
4. Compile/package with mandatory GMP/GMPXX; no project binary execution, discovery, test or benchmark. Publish exact changed test names and package/source authority for Review. Do not edit any frozen selector or TB31 manifest.

**Falsifiers/STOP:** typed face/edge or reciprocal premise cannot be established; a required code change escapes the single test file; synthetic owner shape needs redesign; original assertions must change; or compile fails. Report the exact blocker. No production weakening or speculative repair.

## Narrow sequence and carried obligations

| Order | Unit | Gate and scope |
|---|---|---|
| 1 authorized | M6-CP3-CB30-RP01-PERIODIC-OWNER-FIXTURE-GAUGE | Shared helper plus three local controls; compile/package only |
| 2 conditional on a complete CB30 package; also owns a blocked CB30 | M6-CP3-CB30-RP01-PERIODIC-OWNER-FIXTURE-GAUGE-REV | Inspect exact diff/package; verify only six callers affected, original assertions preserved and three controls discriminate; no runtime |
| 3 planned, authority withheld until step 2 | TB32 bounded immutable verification | Run six original cases plus three controls; additionally retain the full frozen 497 census on the same package to detect other changes, without redefining its identities or counting inherited RED as accepted. Prediction: six recoveries, 478 PASS/19 inherited RED in the unchanged 497, plus three focused PASS. Any contradiction routes to Review |
| 4 planned | TB32 independent Review | Audit first failure sites, original owner assertions, all control paths and census; decide only this repair's acceptance |
| 5 planned, separately authorize after step 4 | Nonzero transport/permutation CB → immutable TB → Review | RA-146.3's odd-transition witness and stale-vector/inverse counterexamples; no production correction |
| later, independently gated | Existing remaining failure owners and produced A6 gauge witness | Seven A3 cycle, seven untyped, A5 focused30:12, A4 cp3entry:4, singularity selector:442, DEFN-T1 cp3entry:1/2, census and RP-01 review |

The three companion cases are targeted evidence beside the frozen census, not a replacement/extension of accepted selectors. Step 2 freezes executable dispatch and prediction metadata before TB; six expected recoveries must not be mislabeled unexpected PASS by reusing the old TB31 prediction manifest unchanged.

RA-145's six initial failures are explained, **not runtime repaired**. All other 19 REDs retain their owners; the seven A3 exceptions still do not isolate a cycle-error locus. G4-B002 real-produced closed-complex extraction, DIAG-RETAIN, DEFN-SEAM-NZ and periodic/DEFN-T1 obligations remain open. This work restores test reachability; M6 production readiness still requires genuine end-to-end evidence, then M7/M8.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Unchanged 30/12/449 and 497 manifest hashes above; no new selector/prefix or acceptance |
| Decisive claims independently re-derived | Source call graph and ordered factory guards; six archived raw failures and hashes; 1,000 artifact checksums; package-source ancestry and code-surface equality |
| Non-vacuity checked | Owner-map scope distinguished from skipped reciprocal guards; equal-gauge permutation weakness identified; three discriminating controls and separately scoped odd-transport unit |
| Prior obligations discharged/carried | RA-145 FG01 classification discharged statically; runtime repair open; RA-45.4/146.4 produced A6 obligation carried; other 19 REDs and G4-B002 unchanged |
| Stable accounting | 66/17/49, debt1; CP2 491 accepted, CB29/TB31 472/497 candidate only |
| New candidates/obligations recorded | RA-146.1–4 in tracker; test-authority/coverage issues, no new stable event |
| ORIENTATION currency line | RA-146 / 2026-10-23 |
| ORIENTATION §3 / §4 / §7 / §8 | Current boundary and priorities corrected; witness set unchanged, synthetic limit stated; non-vacuous permutation instance recorded |
| CHANGELOG | RA-146 entry added |
| ROADMAP | Current CP3 note realigned; no checkpoint promotion |
| Selector manifest | n/a: no selector change or acceptance |
| LESSONS | Existing “A witness must be capable of falsifying its assertion”, “A test's actual assertion is its scope”, and “A limitation a specification leaves open must reappear in every later plan” apply; no new generic lesson |
| Consolidation under CLEAN_UP_POLICY | FG01 normative definition retained and amended in place; RA-145 retained as owning 497 census review, CB29/TB30/TB31 remain load-bearing evidence. No evidence file folded/deleted; old TODO CURRENT headings explicitly historical, durable contents retained |
| Successor frozen | CB30 above; identical next action/conditional sequence in handoff and TODO |
| Turn boundary held | Runtime-free; no product/test/fixture/selector/build/workflow mutation |
| Documentation drift audit | Executed on the partial materialization: 39 missing-link and four missing-policy reports; all 43 targets independently exist in the authoritative Git tree, so these are local materialization limits, not repository defects. No other audit finding. Current durable headings preserved (handoff 4/4, orientation 1/1), full pre-existing changelog suffix retained; no clean full-checkout audit claim |
| review_check.py boundary | Executed: exit 1 because partial connector-materialized source has no Git rewrite baseline/history; its apparent clean-path messages are not authoritative. Connector base/final diff and protected-byte comparison provide the bounded replacement; no claim that exact script passed |
| STATUS lifecycle maintained | Entry IN_PROGRESS published; final COMPLETE with CB30 successor follows all documentation writes |
| Pushed to origin, branch in sync | Connector atomic publication and final head/content readback used; no local checkout exists, so no git status -sb claim. Final publication verification reported in chat |
