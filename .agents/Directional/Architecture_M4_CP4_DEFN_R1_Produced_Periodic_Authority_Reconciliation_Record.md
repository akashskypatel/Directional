# M4-CP4-DEFN-R1 — produced periodic-authority reconciliation

**Turn:** `M4-CP4-DEFN-R1`
**Result:** **COMPLETE / READING B FROZEN / RUNTIME-FREE / M4-CP4 REMAINS OPEN**
**Accepted runtime authority:** package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**
**Stable accounting:** **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**

## 1. Decision

Freeze **Reading B**. The two periodic `G4-B002` produced-witness debts are explicitly re-homed from M4-CP4 to M5. They are not deleted, satisfied, weakened, or credited by this definition turn.

M4 retains exactly one `G4-B002` produced-witness debt:

- `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` — **M4-CP4**.

M5 now owns the two periodic debts:

- `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` — **M5-CP1 mechanism / M5-CP3 direct-production proof**;
- `MissingPeriodicRelationOwnerIsRejected` — **M5-CP2 typed-failure mechanism / M5-CP3 direct-production proof**.

The original `>=2` distinct produced periodic relation IDs / periodic edges requirement and the exact missing-owner discriminator remain unchanged.

## 2. Reading C is disproved on the current torus authority

R3 Review required DEFN-R1 to test the cheaper third possibility before selecting A or B: the product permits multiple relations on **distinct** `sourceTopologyRegion`s, so two one-relation regions could in principle satisfy the existing multiplicity contract without a same-sheet basis solver.

That path does not exist for the row408 torus.

Static source authority in `build_source_topology_regions(...)` constructs face adjacency across same-component incident faces and omits an adjacency edge when it is in `options.hardFeatureEdges`. The exact committed row408 fixture uses `benchmarks/fixtures/milestone-g/torus.obj` with the two canonical hard-edge cycles and exactly **18** unique hard edges.

An independent static census over those exact bytes gives:

- vertices: **72**;
- faces: **144**;
- hard edges: **18 / 18 present**;
- every hard edge has exactly **2** incident faces;
- connected components of the exact face-adjacency graph after all 18 hard edges are omitted: **1**;
- resulting region size: **144 faces**.

Therefore the row408-aligned produced torus does **not** decompose into two or more distinct source topology regions able to carry one relation each. `M4-CP4-TB1-R3-REV-OBS-01` is discharged.

This result is consistent with torus topology: the authored cycles are nonseparating generator cuts. Omitting their dual adjacencies cuts periodic traversal but does not by itself produce two disconnected face regions under the current region builder.

## 3. Reading A is not an M4-local semantic boundary

With Reading C eliminated, satisfying the two periodic debts in M4 would require canonical identities for two independent periodic generators **inside one `sourceTopologyRegion`**, plus a canonical binding from produced periodic edges to those identities.

Current product source deliberately refuses to guess that basis. `insert_periodic_holonomy(...)` returns `AmbiguousBasis` for a second distinct relation in the same source topology region and states that distinct same-sheet cycles require a later topology-basis solver; discovery-order retention is unsound. Its separate support for multiple relations on distinct authoritative sheets/components does not solve the one-region torus case.

`DESIGN.md` §14 assigns the needed semantics to M5:

- canonical relation IDs;
- explicit path certificates;
- representation-renumbering invariance;
- typed missing/duplicate/conflicting/nonreciprocal relation failures;
- direct-production torus lineage and quotient acceptance.

A new M4 same-sheet basis/owner contract would therefore duplicate or pre-empt M5's canonical relation domain rather than remain a bounded conformity-plan concern. Reading A is rejected and Reading B is frozen.

## 4. Exact debt accounting and M4 exit theorem

Produced-witness debt remains **5** total.

| Debt | Status after DEFN-R1 | Owner / closure gate |
|---|---|---|
| `G4-B002` produced closed-complex candidate extraction | OPEN | M4-CP4; corrected produced witness -> immutable TB + Review |
| `G4-B002` periodic relation owners survive container reorder | OPEN | M5-CP1 canonical relation mechanism; M5-CP3 direct-production re-proof |
| `G4-B002` missing periodic relation owner rejects typed | OPEN | M5-CP2 typed relation-failure mechanism; M5-CP3 direct-production re-proof |
| `G4-B003` produced nonzero-Z4 materialization | OPEN | M5, unchanged |
| `G4-B003` tampered nonzero-Z4 transform rejects | OPEN | M5, unchanged |

M4-CP4 may close without produced periodic relation authority only when every **remaining M4-owned** conjunct is satisfied:

1. selector427 remains byte-exact as the cumulative prefix;
2. the produced closed-complex `G4-B002` debt is proved on genuine pipeline authority;
3. the already reviewed production work/boundedness evidence remains valid through publication/final cumulative gate;
4. the already reviewed produced same-region multiplicity-2 evidence remains valid through publication/final cumulative gate;
5. the zero-transport helper-precondition audit remains discharged, with the focused row6 expectation corrected to exact `NonIntegralCycleLift`;
6. every M4 CP4 identity proposed for publication is independently reviewed;
7. final append-only publication and artifact-only cumulative runtime + Review satisfy the frozen sequence.

The M5-owned periodic debts receive zero M4 credit and remain part of the global debt count.

## 5. Related R3 findings

### 5.1 Row2 — test-witness reachability

`M4-CP4-TB1-R3-CAND-01` remains **OPEN / NON-STABLE / TEST-AUTHORITY**. The generic helper's `NotProductionReady/tracing` stop does not establish a product defect. `M4-CP4-CB5` may align only the test-local production precondition to the already accepted row408 production-reachable hard-rail setup while preserving fail-closed execution, recovery disabled, retained intermediate geometry, and the independent candidate oracle/tamper.

### 5.2 Row6 — exact typed expectation

`M4-CP4-TB1-R3-CAND-03` remains **OPEN / NON-STABLE / TEST-AUTHORITY**. Source validation ordering and R3 runtime jointly support exact `NonIntegralCycleLift` for this witness before `CycleTransportMismatch`. CB5 changes only the expected typed code; generic rejection and product validation-order changes are forbidden.

### 5.3 Periodic focused rows

`M4-CP4-TB1-R3-CAND-02` is **CLOSED AS AN M4 OWNERSHIP QUESTION / RE-HOMED TO M5 / NON-STABLE**. The two underlying debts remain open. The existing periodic focused test identities are not edited by CB5 and are not part of M4's successor runtime acceptance surface; M5 definition work will decide their eventual ownership/naming without retroactively granting M4 credit.

## 6. Boundary and process evidence

This turn remained runtime-free and changed no product, test, fixture, selector, benchmark, CMake, or build semantics. The torus-region result above was derived by static parsing/connectivity analysis of repository bytes; it did not execute a generated Directional binary.

One process nonconformance occurred at turn startup: handoff/TODO repository documents were fetched directly before the mandatory `READ_MODE` gate had been explicitly selected. Once `TOOL_USE_CONSERVATION_POLICY.md` was read in full, the miss was recorded, `READ_MODE=snapshot` was selected, and all subsequent static source/document inspection used the single verified source snapshot. No semantic claim depends on the premature reads.

Source-snapshot authority for static review: workflow run `35433761426`, artifact `10582101479`, outer digest `49be09928b7ef944303e24197da9a6b50fb36f7ddfe9b19dc0abf1bb57e9643e`, exact snapshot/event SHA `7259af1f020c208337a69471e11495c6cd9fd196`, archive SHA-256 `7a92fbb81221caec14dcf87d934fec3f4f02691339409ad72b7529646ec9758c`, `runtimeExecution=false`.

Resume reconciliation after the continuation request used source-snapshot run `35435078981`, artifact `10581333102`, outer digest `12540f1dc01c37787c118f1d2debbf263b4b8e9034cb3ef34a8877dd29482375`, exact snapshot/event SHA `1aa96b251951e9ef5021ae7a8bc1e37627fa1209`, archive SHA-256 `bd078fab6ff9888e556eeffa7ed21460f64c0957c51d5dbc10eedc85eb2a897c`, and `runtimeExecution=false`. All 13 prepared documentation paths matched origin byte-for-byte (including the two intended removals), leaving no local-only unpushed work. The Drive patch `1rLxjoEulPhnJZjclLVzDWKE5MLLc9ofR` was owner-deleted after successful push evidence, and final temporary caller/marker cleanup left only durable workflows with no workflow-observation or turn-payload files.

## 7. Exact successor

Exactly one successor is frozen: **`M4-CP4-CB5`**, under `Architecture_M4_CP4_CB5_Code_Build_Plan.md`.

Its falsifiers are written before implementation. Scope is limited to the row2 production-witness precondition and row6 exact typed expectation in two test files, followed by compile-only GMP verification of the two affected test executables. Product/fixture/selector semantics and the two M5-owned periodic focused identities are frozen.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector427 re-hashed as `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; exact first-426 prefix re-hashed as `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; 427 LF rows confirmed. |
| Decisive claims independently re-derived | Re-derived row408 torus hard-edge inventory and exact `build_source_topology_regions` connectivity result: 72 vertices, 144 faces, 18/18 valid two-face hard edges, one 144-face source topology region. Re-read same-sheet `AmbiguousBasis` refusal and M5 canonical relation/path ownership. |
| Non-vacuity checked | Reading C had a concrete falsifier (`>=2` produced topology regions) and is false on exact bytes; Reading A was tested against the M4/M5 authority boundary rather than rejected by label. The periodic debts remain open with unchanged discriminators, so re-homing creates no vacuous green. |
| Prior obligations discharged/carried | `M4-CP4-TB1-R3-REV-OBS-01` discharged; CAND-02 ownership question resolved to M5 while both debts remain open; CAND-01 and CAND-03 carried to CB5; prior discharged observations remain discharged; M8/row399/row408 carried owners unchanged. |
| Stable accounting | **49 / 14 / 35**, produced-witness debt **5**; accepted package `10565723112` / selector427 **427/427** unchanged. M4-owned produced-witness debt count becomes 1; M5-owned produced-witness debt count becomes 4. |
| New candidates/obligations recorded | No new stable regression. Ownership amendments and the discharged Reading-C observation are recorded in the tracker; no debt is added or removed. |
| ORIENTATION currency line | `M4-CP4-DEFN-R1`, 2026-09-19 UTC written. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated for Reading B, one-region torus evidence, new M4/M5 debt split, CB5 priority, and the existing representation-expressibility pattern; stale DEFN-next wording removed. |
| CHANGELOG | One `M4-CP4-DEFN-R1` entry added. |
| ROADMAP | M4-CP4 exit ownership and M5 CP1/CP2/CP3 debt ownership updated; total debt preserved. |
| Selector manifest | n/a — no selector was added or accepted; selector427 remains byte-frozen. |
| LESSONS | n/a — this is an existing representation/authority-boundary pattern, not a new general lesson. |
| Consolidation under CLEAN_UP_POLICY | R3 Review record (235 lines) and consumed DEFN-R1 plan (95 lines) folded/indexed in `M4_Consolidated_Record.md` after their durable facts were preserved; current runtime report, this definition record, frozen definitions, and exactly one CB5 successor plan remain. |
| Successor frozen | Exactly one: `M4-CP4-CB5`; falsifiers are stated before authorized edits in `Architecture_M4_CP4_CB5_Code_Build_Plan.md` §2. |
| Turn boundary held | Yes — runtime-free; no product/test/fixture/selector/benchmark/build semantics changed and no generated Directional binary executed. |
| review_check.py boundary | **ALL CHECKS PASSED** against the prepared documentation-only delta with selector427 explicitly re-hashed. |
| `STATUS` lifecycle maintained | `Turn=M4-CP4-DEFN-R1`; entry `IN_PROGRESS`; `Started at=2026-09-19T09:04:39Z`; continuation `Resumed at=2026-09-19T09:30:09Z`; final COMPLETE / `Successor=M4-CP4-CB5` / Ended timestamp is reserved for the final direct STATUS mutation. |
| Pushed to origin, branch in sync | The verified documentation patch is pushed to the configured working branch and final branch authority is re-read before the final STATUS beacon; no alternate ref is used. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** Reading B is correctly frozen. The Reading C disproof reproduces exactly from
committed bytes, the Reading A rejection rests on pre-existing authority rather than authority written this turn,
debt is preserved at **5** with zero M4 credit, and selector427 re-hashes byte-exact at 427 rows. Accounting
holds at **49 / 14 / 35**.

### V1 — Reading C is disproved; I withdraw it

Reading C was mine (`M4-CP4-TB1-R3-REV-OBS-01`). DEFN-R1 tested it against a concrete falsifier instead of
arguing about it, which is the right response. I re-derived the census independently from
`benchmarks/fixtures/milestone-g/torus.obj` and the two authored cycles in
`cp4c_torus_hard_rail_remesh_options()`, and every number reproduces:

| Quantity | DEFN-R1 | Independently re-derived |
|---|---|---|
| vertices | 72 | **72** |
| faces | 144 | **144** |
| unique hard edges | 18 | **18** |
| hard edges present in mesh | 18 / 18 | **18 / 18** |
| hard edges with exactly 2 incident faces | 18 | **18** |
| face-adjacency components after omitting all 18 | 1 | **1** |
| resulting region size | 144 faces | **144** |

Total mesh edges are 216, so `V − E + F = 72 − 216 + 144 = 0` — the fixture is genuinely a torus, which the
census did not state but which confirms the subject is the right one. **Reading C is false and is withdrawn.**

### V2 — the disproof is stronger than measured: one region is structurally necessary

§2 concludes the result "is consistent with torus topology". It is more than consistent — it is forced, and
saying so matters for what comes next.

Cutting a surface along a simple closed curve leaves it connected exactly when the curve is **non-separating**.
Both authored cycles are canonical torus generators, hence non-separating by definition: cutting along the first
yields a cylinder (connected), and the second then runs between that cylinder's two boundary circles, yielding a
disc (connected). A canonical generator pair therefore always produces exactly **one** region. Two regions would
require a *separating* cycle — and a separating cycle carries no periodic generator, so it cannot serve the
purpose Reading C needed it for.

**Consequence:** Reading C cannot be rescued by choosing a different torus fixture, a finer mesh, or a different
generator pair. The 144-face census is not a property of this fixture; it is a property of cutting a genus-1
surface along its generators. A later turn must not re-litigate Reading C on the theory that a different subject
would decompose — recorded so that door is closed rather than merely unvisited.

### V3 — the Reading A rejection is not circular

Re-homing two produced-witness debts across a milestone boundary is the least reversible action available in this
sequence, and its stated ground is that `DESIGN.md` §14 already assigns the needed semantics to M5. That ground
would be worthless if the assignment had been written during this same turn, so I checked the **pre-turn** file.

At `cfe1673e~1`, §14's M5 section already read *"certificate-carrying chart and quotient relations … canonical
relation IDs and explicit path certificates"*, with acceptance requiring that *"missing, duplicate, conflicting,
nonreciprocal, and representation-renumbered relations fail typed"* and that *"torus lineage and quotient
acceptance are direct production evidence."* Every element §3 cites was already chartered to M5 before DEFN-R1
ran. The two lines added to `DESIGN.md` in `cfe1673e` are labelled as the DEFN-R1 amendment and record the
decision; they do not manufacture the authority the decision rests on.

Combined with §3's verified same-sheet `AmbiguousBasis` refusal, Reading A's rejection is sound: a bounded M4
same-sheet basis contract would duplicate M5's chartered relation domain.

### V4 — the normative amendment actually landed, and the discriminator survived intact

Reading B required coordinated normative edits rather than a record-only decision. Verified in `cfe1673e`:
`Architecture_M4_CP4_Frozen_Definitions.md` gains §2.1 freezing Reading B, and §§3.2/3.3 are marked
**OPEN / RE-HOMED TO M5** with named owners (`M5-CP1` canonical ID/path mechanism, `M5-CP2` typed missing-owner
failure, `M5-CP3` direct-production re-proof).

The load-bearing clause is preserved verbatim: *"The `>=2` periodic-relation/edge discriminator is **preserved
unchanged** … It is not weakened to `>=1`, inferred from…"*. Re-homing moved the *owner*, not the *bar* — which
is the distinction that separates a legitimate ownership decision from quiet debt relief. Debt stays at **5**
(1 `G4-B002` M4-owned, 2 `G4-B002` M5-owned, 2 `G4-B003` M5-owned), with explicit zero M4 credit, and the amended
M4 exit theorem enumerates the seven remaining M4-owned conjuncts.

### V5 — successor scope and process

`Architecture_M4_CP4_CB5_Code_Build_Plan.md` is compile-only, test-authority only, confined to row2's production
precondition and row6's exact typed expectation, and publishes four **stop falsifiers before implementation** —
including that CB5 must stop if row2 could only be reached via production-code, fixture-byte, fallback-policy
changes or a synthetic/weakened candidate predicate, and if source no longer supports `NonIntegralCycleLift` as
the exact code. Writing the conditions for abandoning the turn before starting it is the correct order.

§6's self-reported process nonconformance — repository documents fetched before the `READ_MODE` gate was
selected — was recorded rather than concealed, and no semantic claim in the turn depends on those reads; the
decisive census was re-derived here from committed bytes independently of any snapshot. Correctly handled; no
finding.

### V6 — verification limits

Re-derived from repository bytes: the full torus census and component count, the Euler characteristic, the
pre-turn `DESIGN.md` §14 M5 charter, the frozen-definitions amendment and its preserved `>=2` clause, the debt
table, selector427's 427 rows and SHA-256, and the CB5 scope/falsifiers. Accepted as reported: source-snapshot
run/artifact/digest identifiers and Drive transport evidence.

**No obligations are carried out of this review.** `M4-CP4-TB1-R3-REV-OBS-01` is discharged and withdrawn.
