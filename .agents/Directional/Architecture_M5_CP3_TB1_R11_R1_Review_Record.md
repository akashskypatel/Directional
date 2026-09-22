# M5-CP3-TB1-R11-R1 Review Record

**Turn:** `M5-CP3-TB1-R11-R1-REV`  
**Type:** **REVIEW + PLAN / runtime-free / no implementation**  
**Disposition:** **R11-R1 MECHANICALLY UPHELD / CB12 DIRECTION RECOVERY PROVED / PRODUCT ROOT CAUSE PROVED / EXISTING RP-01 CONTINUATION / CANDIDATE UNPROMOTED**  
**Exact successor:** `M5-CP3-CB14`

## 1. Independent runtime/evidence re-derivation

Review independently re-opened R11-R1 result/log artifacts and the exact source snapshot. The mechanically valid authority is:

- candidate/source: `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`;
- run/job: `35778555375 / 106917917282`;
- result/log: `10717297354 / 10717921412`;
- result/log ZIP SHA-256:
  `d76dff757919a0c8bb139b6aa4d54840f5344fc9bf0b88f57a5d9629d3807656 /
  c09c1c5797640e85ed485d5b6a034970a266c36fb0bbf488441be1674aff0cd0`;
- result self-manifest: **912/912**, SHA-256
  `16dfe18019afee726ce2d2d1845187619c27c74bfa9ff238904237c7de3ab589`;
- candidate ZIP/root-manifest/source-archive SHA-256:
  `faf4def9e6823f718e56091876bb97047f5e91a8bfb561ca40d91d70d2af61ce /
  352f7553e2f0dc627ada385d78327bcb93d4f3b66125f4faf540d6965a1c2c33 /
  506e9d75976802f7045b95344ef8cc0ff1e4d39b8343bdaddaa009a58e04a673`;
- routing/identity-map SHA-256:
  `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce /
  7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 / first427 SHA-256:
  `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 /
  f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

All **446/446** fresh exact-filter processes select exactly once with zero skips:
mechanism **9/9**, focused atlas **1/1**, produced **4/6**, selector430 **430/430**,
for **444 PASS / 2 RED**. Protected selector ordinals **191/192/247/408** are PASS.
Benchmark count is **0**. Package/source/execution-view postflight is exact and all prohibited-operation counters are zero.

Produced rows4/5 alone fail at exact `PeriodicActionCorrespondenceMismatch`. Row4 does not reach
materialization/certificate assertions; row5 does not reach its transform tamper or typed rejection.

Turn-local Review source snapshot run/artifact is `35789577173 / 10721696280`, provider ZIP SHA-256
`be3a48cc07f4af55344c6d3a4819888a3ee89c36950d81a0b387eb198f92e522`.
No Directional runtime is executed by Review.

## 2. CB12 directed authority is recovery-proved

Exact candidate source no longer lets representation order choose a directed transform. Same-region reciprocal grouping remains
unordered only for membership; before generator/action construction, CB12 selects the interval whose exact A3 orientation is
`Forward` as `directedFirst` and the `Reverse` interval as `directedSecond`. Those exact occurrences are passed to
`generator_route_for_span(ForwardOccurrence, ReverseOccurrence)` and then to
`periodic_action_for_pair(ForwardEdge, ReverseEdge, generatorRotation)`.

No pair-vector index, insertion order, inverse retry, best-of-two direction search or fallback supplies the direction.
The generator route resolves the exact Mandatory carrier and queries the atlas-owned transition value for the exact directed
occurrence-owned source-face pair.

Therefore `M5-CP3-TB1-R10-REV-CAND-01` is **CLOSED / RECOVERY PROVED / NON-STABLE / +0**.
The R10 insertion-order authority defect is not the cause of R11-R1 rows4/5.

`M5-CP3-TB1-R6-REV-OBS-01` is also **DISCHARGED**: the nonzero-Z4 subject now reaches the exact semantically directed
Forward -> Reverse construction path. The subsequent RED is a distinct downstream authority seam.

## 3. Split of the collapsed correspondence guard

The collapsed product guard is:

```text
!periodic_action_for_pair(ForwardEdge, ReverseEdge, generatorRotation)
OR generatorRoute.rotation != action.rotation
```

Review proves the second alternative cannot be the observed cause. When `periodic_action_for_pair` returns a value, it constructs
`GridAutomorphism{rotation, shift}` using the exact `generatorRotation` argument, so returned
`action.rotation == generatorRoute.rotation` by construction. R11-R1 therefore reaches the RED only because
`periodic_action_for_pair` returns no action.

Inside that helper:

1. all four endpoint `sourceChart` values are present by the bounded-disk cell-construction path or production would have
   rejected earlier as `MissingFaceState`;
2. all four `scaleLevel` values remain the default zero, so reciprocal scale predicates pass;
3. the two branch-state predicates are the exact directed source-transition predicates. On the accepted source/A3 pair, reversing
   the same source edge contributes the expected half-turn while the independent cut-disk face gauge differs by the directed edge
   transition; the accepted opposite-run branch relation therefore yields
   `second.branchRotation == compose(R, first.branchRotation)` at both endpoints;
4. the helper defines `shift = second.to - rotate(R, first.from)`, so its first endpoint mapping is true by construction;
5. the **second endpoint mapping is false**.

Item 5 is the first false predicate after the independently satisfied preconditions and the shift-defined first endpoint.

## 4. Exact algebraic cause: cell-grid coordinates are used as quotient-seam coordinates

The CB10 source-authoritative chart oracle independently fixes the accepted subject to four canonical boundary runs
`[0,1,2,3]`, and the bounded-disk producer materializes that subject as one rectangle. Its cell-grid boundary directions are
therefore exactly:

```text
side 0: +X
side 1: +Y
side 2: -X
side 3: -Y
```

Each reciprocal copy of one row408 generator lies on opposite rectangle sides. For the semantically directed pair, let

```text
d1 = first.toLattice.latticeCoordinate - first.fromLattice.latticeCoordinate
d2 = second.toLattice.latticeCoordinate - second.fromLattice.latticeCoordinate
R  = generatorRoute.composed_transport().rotation
```

The rectangle forces `d2 = -d1`, with `d1` a nonzero unit cardinal vector. One action mapping
`first.from -> second.to` and `first.to -> second.from` requires, after subtraction,

```text
rotate(R, d1) == -d2 == d1.
```

For every genuinely nonzero quarter-turn `R in {1,2,3}`, `rotate(R,d1) != d1`. Therefore the second exact endpoint mapping
cannot hold. This is deterministic integer algebra; no floating tolerance or runtime inference is involved.

The defect is not the fixture's source/A3 nonzero-Z4 precondition. It is a **product authority-domain conflation**:
`LocalLatticeState::latticeCoordinate` is the single cut-open rectangle's cell-placement coordinate, but the relation builder
uses it directly as though both periodic seam copies were already expressed in one quotient-relation gauge. They are not when the
generator transport is nonzero.

This is the deeper continuation of the R9 `RP-01 / AUTHORITY_DOMAIN_CONFLATION` finding. CB11 correctly removed the raw
family/sign veto and CB12 correctly removed storage-order direction, but the endpoint-state representation remains in the wrong
gauge. No new stable category or event is opened.

## 5. Test-authority adjudication

The R8/R9 test-authority recovery remains upheld. The committed seam ramp is independently source-derived, has the exact row408
18-edge hard authority, genuinely nonzero source transitions, canonical closed four-run bounded-disk chart, and no product-output
search for the nonzero precondition.

The test's chart oracle proves **cut-domain chart admissibility**; it does not claim that the raw rectangular cell coordinates are
already quotient-seam coordinates. Treating those two coordinate domains as identical is the product defect above, not a reason to
retune the field or weaken rows4/5.

Rows4/5 remain the correct debt discriminators. Row4 still must prove a genuinely nonzero rotation and translation through
relation publication, selected certificate consumption and quotient materialization. Row5 still must alter only the published
nonzero transform and reject typed `NonReciprocalPeriodicRelation`.

## 6. Regression/accounting disposition

`M5-CP3-TB1-R11-R1-CAND-01` is reclassified as:

**CAUSE PROVED / PRODUCT / EXISTING `RP-01 AUTHORITY_DOMAIN_CONFLATION` CONTINUATION /
CUT-DOMAIN CELL COORDINATE USED AS QUOTIENT-SEAM ENDPOINT AUTHORITY / NON-STABLE / OWNER `M5-CP3-CB14` / +0.**

`M5-CP3-TB1-R10-REV-CAND-01`: **CLOSED / RECOVERY PROVED / +0**.  
`M5-CP3-TB1-R6-REV-OBS-01`: **CLOSED / DIRECTION AUTHORITY PROVED**.  
`M5-CP3-TB1-R11-EXEC-CAND-01`: remains **CLOSED / ORCHESTRATION RECOVERY CONFIRMED / +0**.  
`M5-CP2-TB1-REV-OBS-01`: remains **OPEN**; selector publication is still prohibited.

Stable accounting remains **50 events / 14 categories / 36 recurrences**. Produced-witness debt remains **3**:
the two M5 nonzero-Z4 debts plus the one M6 closed-complex debt. Accepted runtime remains
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`; CB12 candidate remains unpromoted.

## 7. Corrective measure

The next product correction must separate **cell-grid placement authority** from **periodic relation endpoint-gauge authority**.

For same-region periodic cuts only, each endpoint supplied to the relation action must be represented in a deterministic
relation-owned lattice gauge derived independently from that endpoint's own accepted A3 boundary occurrence, source-chart/branch
state and the one directed generator transport. The derivation must occur before relation construction and may not inspect or fit
against the partner endpoint or a desired action result. Cell-grid coordinates used for ordinary cell ownership/interior pairing
remain unchanged.

The relation builder and checked `SurfacePhaseFrontProduct` validator must consume the same explicit relation-endpoint authority.
The implementation may reuse existing fields only if their semantics can be made unambiguous without changing ordinary cell-grid
ownership; otherwise it must add the smallest typed edge/relation-local state needed to keep the domains separate.

The correction must preserve frozen §16 exactly: one directed `R`, exact
`rotate(R,d1) == -d2`, both branch states, both exact integer endpoint mappings, no inverse retry, no best-of-two search, no
rotation search, no endpoint rewrite and no translation fitting. A representation that merely transforms the second endpoint from
the first after observing a mismatch is prohibited.

## 8. Exact successor

Exact successor is runtime-free Code + Build **`M5-CP3-CB14`** under
`Architecture_M5_CP3_CB14_Periodic_Seam_Lattice_Gauge_Authority_Correction_Plan.md`.

CB14 may modify only the bounded same-region periodic relation endpoint-state authority and the minimum validation/test support
needed to prove that authority. It must compile/package with mandatory GMP/GMPXX linkage and run no Directional runtime. A green
CB14 routes to a fresh artifact-only gate with all 446 existing identities unchanged and mandatory Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Selector430 independently re-hashed at `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. |
| Decisive claims independently re-derived | Re-parsed the complete 912/912 R11-R1 evidence and 446-row ledger; re-derived CB12 Forward -> Reverse source/A3 authority; split the collapsed action guard; proved the second exact endpoint map is the first false predicate; derived the rectangle `d2=-d1` contradiction against nonzero `R`. |
| Non-vacuity checked | Rows4/5 are genuine nonzero source/A3 witnesses; the failure occurs before row4 materialization and row5 tamper, while rows1/2/3/6 and selector430 remain green. The failing exact endpoint equation would change if the relation endpoint gauge were correct, so the proposed CB14 seam is falsifiable. |
| Prior obligations discharged/carried | `M5-CP3-TB1-R10-REV-CAND-01` CLOSED recovery-proved; `M5-CP3-TB1-R6-REV-OBS-01` CLOSED direction-authority proved; `M5-CP2-TB1-REV-OBS-01` carried OPEN; both nonzero-Z4 M5 debts carried to CB14/R12; invalid-R11 orchestration candidate remains CLOSED recovery-confirmed. |
| Stable accounting | **50 events / 14 categories / 36 recurrences**, produced-witness debt **3**; accepted package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`, selector430 **430/430**. |
| New candidates/obligations recorded | `M5-CP3-TB1-R11-R1-CAND-01` reclassified cause-proved as existing `RP-01 AUTHORITY_DOMAIN_CONFLATION`, owner `M5-CP3-CB14`; tracker updated. |
| ORIENTATION currency line | `M5-CP3-TB1-R11-R1-REV`, 2026-09-22 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated current CP3 state, torus witness, exact-next/open-obligation bullets, and the endpoint-gauge authority-domain pattern; superseded R10/R6 warnings were explicitly closed. |
| CHANGELOG | Root and Directional changelogs updated with Review result and exact successor. |
| ROADMAP | Updated M5 CP3 status to Review cause-proved / CB14 next. |
| Selector manifest | n/a — no selector was added, changed, or accepted by this Review. |
| LESSONS | Added lesson 175: cut-domain cell placement is not automatically quotient-seam endpoint authority. |
| Consolidation under CLEAN_UP_POLICY | Folded consumed R11-R1 Review plan; indexed that plan plus seven per-turn documents retired between Reviews with exact filenames/line counts in `M5_Consolidated_Record.md`; retained the current runtime report, this Review record, exactly one CB14 plan, frozen definitions and selector files. |
| Successor frozen | Exactly one successor: `M5-CP3-CB14`, with pre-mutation authority gate, falsifiers, preservation requirements and stop rule in `Architecture_M5_CP3_CB14_Periodic_Seam_Lattice_Gauge_Authority_Correction_Plan.md`. |
| Turn boundary held | Yes — Review remained runtime-free and made no product/test/fixture/selector/benchmark/build-source mutation. |
| review_check.py boundary | **ALL CHECKS PASSED**; no product/test/fixture/build mutation, no selector mutation, selector430 declared hash matched, durable markers preserved. |
| `STATUS` lifecycle maintained | Entry and resume beacons were direct-written with the original start time preserved; the terminal COMPLETE/CB14 beacon is reserved as the final repository mutation immediately before response. |
| Pushed to origin, branch in sync | n/a for local `git status -sb`: this ChatGPT Web turn writes through the GitHub connector/reusable workflow directly to origin; final PR-head equality is verified after the closeout write rather than claiming a local branch state. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld with one disposition reversed.** The manifest obligation is discharged, CB12's directed
ordering is real, and the item-1-to-5 localization is careful work. Accounting holds at **50 events /
14 categories / 36 recurrences**, debt **3**. `M5-CP3-TB1-R6-REV-OBS-01` is **reopened**.

### V1 — my manifest requirement was met, and the protections held

`M5-CP3-TB1-R10-REV-OBS-01` required complete result self-manifest coverage before any turn needing acceptance
credit. R11-R1 reports **912/912**, so the driver finalization ordering is fixed and the rule was satisfied
before the publication gate rather than under pressure at it — which was the entire point of recording it early.

The standing protections also hold: selector430 is **430/430** with protected ordinals **191, 192, 247 and 408**
all PASS, and produced rows 1/2/3/6 remain PASS, so the two debts discharged at R7 and the §16 `R = 0` reduction
are both intact. Totals stay 50 / 14 / 36 with debt 3; the candidate remains unpromoted.

### V2 — CB12's directed ordering is implemented, and that defect is correctly closed

Verified in `src/geometry/SurfaceCellTracing.cpp:17229-17241`: `directedFirst` / `directedSecond` are selected by
exact A3 orientation — the `Forward` interval bound first, the `Reverse` interval second — rather than by storage
or insertion order. The unordered pair is used only for membership. That is exactly what frozen §14.3 requires,
and `M5-CP3-TB1-R10-REV-CAND-01` is rightly closed as recovery-proved.

### V3 — REOPENED: `M5-CP3-TB1-R6-REV-OBS-01` is discharged on an argument this Review itself rejects elsewhere

§2 discharges the direction observation because "the nonzero-Z4 subject now reaches the exact semantically
directed Forward → Reverse construction path."

§3 applies the correct standard two pages later. It discounts `action.rotation == generatorRoute.rotation`
because the helper builds the action *from* the generator rotation, so the equality is "by construction"; and it
discounts item 4's first endpoint mapping because `shift = second.to - rotate(R, first.from)` makes it "true by
construction". Both are properly identified as non-probative, which is why item 5 is correctly named the first
genuinely false predicate. That is good analysis.

By that same standard, **reaching the directed construction path proves the ordering code executes — not that
the ordering is correct.** It is the same class of self-consistency the Review declines to credit elsewhere.

The observation asked for two things, and neither is reported:

1. the produced relation's action checked against an expectation derived **independently of the face order that
   produced it** — §14.2/§16 reciprocity being the natural instrument; and
2. an **inverted** pair **failing**.

Rows 4 and 5 stop at item 5, before the comparator, so the falsifier has not run. An inverted ordering that
happened to produce a mirrored-but-self-consistent action would look identical to this evidence, which is the
precise failure mode the observation exists to exclude — and the one that converts today's clean fail-closed
state into a plausible wrong answer.

**Disposition:** `M5-CP3-TB1-R6-REV-OBS-01` returns to **OPEN**, carried to the first Review in which produced
row 4 passes item 5 and reaches the Forward → Reverse comparator. Recorded as `M5-CP3-TB1-R11-R1-REV-OBS-01`.
Nothing else in this Review depends on the discharge, so reopening costs no other conclusion; the ordering-source
defect (`R10-REV-CAND-01`) stays closed on its own evidence.

### V4 — the predicate walk is the right kind of diagnosis

Enumerating the five predicates and labelling which are tautological is what makes item 5 a real localization
rather than another guess. Items 1-3 are independently satisfied, item 4 is true by definition of `shift`, and
the second endpoint mapping is the first constraint the subject can actually fail. That is the discipline this
checkpoint arrived at after five static-plausibility edits and one instrumentation turn, now applied without
needing another runtime round to find the branch.

CB14's target follows from it directly: cut-domain cell coordinates being used as quotient-seam endpoint
authority is an algebraic cause, not a plausible story, and it is the natural reading of a second endpoint
mapping failing once `shift` has absorbed the first.

### V5 — carried items and verification limits

`M5-CP2-TB1-REV-OBS-01` correctly remains **OPEN**; §13.3 still prohibits selector-publication pre-commitment
while the gate is RED. Debts 3 and 4 remain OPEN with no credit; the M6 closed-complex debt remains M6-owned.

Re-derived from repository bytes: the `directedFirst`/`directedSecond` Forward/Reverse selection, selector430's
rows and hash, and the frozen §14.3 requirement it satisfies. Accepted as reported: the 912/912 manifest
verification, artifact and ledger digests, gate tallies, and the runtime predicate outcomes underlying the
item-1-to-5 walk.
