# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB22` closeout.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**. **CP4c-3 remains OPEN.** `M3-CP4c-3-TB22` is now the current runtime authority; its expected no-new-regression ledger closed exactly.

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime authority** | **`M3-CP4c-3-TB22`** — semantic source `d69729a69a40b020968ed6ef1fbc1bc788284518`, run/job `33826248118 / 100879465830`, **387 PASS / 6 RED** |
| **Current gate selector** | selector **393**, 393 identities, `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`; selector 391 remains an exact byte prefix |
| **Immutable package** | artifact `9919225745`, `sha256:7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`; compile run/job `33823590494 / 100871347582`; GMP/GMPXX |
| **TB22 result/log** | artifacts `9920122224 / 9920122598`; digests `862d3a4c…f0fab / 67a3e187…3a65a` |
| **Ledger / census** | ledger `4998ca25b1477c2a32299bc3eb3d552e3ea9b0e2ccbf0eb4894393964f29dbbe`; identical pre/post package census `7e0c552c79281f97b7553406acd44383ff867197f36da54cd306ac9258fa2b74` |
| **First RED** | ordinal **366**, `UncutFaceComponentOrbitSeedNotUnique`, component 0, 191 faces, `seedState=Multiple`, exact seed orbits `[0,1,3]` |
| **TB22 RED set** | **366, 367, 368, 369, 370, 374** |
| **Projection measurement** | `projectionFaithfulnessResidual=0`, zero retained witnesses, untruncated; minority edges `10-79` and `29-35` map certificate faces `3/3` and `1/1` and seed by `edgeOrbitEvidence` |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **87** |

Selector 391 remains byte-frozen at `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`. Ordinals 392/393 are the only appended identities and both PASS. Ordinals 371/372 remain closed/runtime-proved. Ordinal 391 now PASSes with the prescribed-sphere half explicitly skipped because ordinal 368 remains open.

---

## 2. The current frontier — both CB24 measurements are vacuous

TB22 is **387 PASS / 6 RED** on selector **393** with accepted **365/365**; reds are 366, 367, 368, 369, 370, 374.
Ordinals **371, 372, 391, 392 and 393** all pass. Ordinal 391 now reports its sphere half as
`SKIPPED, reason=ordinal368-open`, closing `M3-CP4c3-TB21-CAND-02`; the torus census is
`V=72, E=76, F=4, componentCount=1, χ=0, residual=0`.

Ordinal 366 is unchanged: `UncutFaceComponentOrbitSeedNotUnique`, component **0**, **191** faces,
`seedState=Multiple`, orbits **`[0,1,3]`**, boundary attribution **81 / 1 / 1** over 97 edges.

**`M3-CP4c-3-TB22-REV` adjudicated CB24's evidence under BZ0–BZ8**
(`Architecture_M3_CP4c3_TB22_Independent_Review_Record.md`) and found **neither diagnostic measures what its name
says**:

- **`projectionFaithfulnessResidual` is a structural zero.** `GlobalTopologyPlan.cpp:1362–1389` requires an edge to
  be in `certificateSeparatingSourceEdges` **and not** in `componentBarriers`. The first set is populated only
  from Mandatory and Cut arcs (`:1191–1200`), whose source edges are exactly `mandatoryEdges` (`:674`) and
  `cutEdges` (`:649`); `componentBarriers = mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges` (`:1114–1116`). **The
  subset relation makes the conjunction empty — the loop body never executes.** `residual=0, witnessCount=0` on
  every mesh, unconditionally.
- **The minority rows' certificate columns are the seed, re-printed.** `certificate_side_orbit` (`:1172–1184`)
  returns `edgeOrbitEvidence[(face,edge)]` when unique, else `fragmentOrbits[face]` when size 1 — the same two
  lookups the seed rule uses — and the component side is **assigned equal** to the labeled side (`:1272–1278`). The
  published `3/3` and `1/1` agreement is a **tautology**: one value, computed once, displayed three times.
- **Two producers; the shipped path calls the wrong one.** `certificateSideOrbitsByEdge` (`:1204–1212`) *is*
  genuinely certificate-derived from `walk.orbitByDart`, but it is consulted only inside the unreachable residual
  loop.
- **The seed asks the wrong question.** `edgeOrbitEvidence` records a dart side of a chord in the **labeled
  neighbour** — evidence about that triangle's interior arrangement, not about which certified face the **uncut**
  triangle across the edge belongs to. The uniqueness guard is **preserved** as a safety property, and `[0,1,3]` is
  fixture-specific evidence that must not drive a general rule.

**Consequently no correction is authorized and both branches of `M3-CP4c3-TB21-CAND-01` remain live.** BZ5's guard
against a barrier-set change was conditioned on BZ2 confirming faithfulness; that antecedent fails.

These were **my own measures** — BY3 and BY4 named output fields without naming a source of truth or a
falsifiability condition, so both were satisfiable without measuring anything. CA1–CA3 and CA6 fix that.

---

## 3. Exact next turn — `M3-CP4c-3-CB25`, diagnostic-only, `CA0–CA9`

Full text in §8 of `Architecture_M3_CP4c3_TB22_Independent_Review_Record.md`.

- **CA0** — accepted 365 untouched; **selector 393 byte-frozen** and republished unchanged; eight standard compile
  targets with **mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **CA1** — derive certified face ownership **from the certificate**, never from `edgeOrbitEvidence`,
  `fragmentOrbits` or `seedOrbits`; **retire or rename `certificate_side_orbit`**.
- **CA2** — measure both sides of each minority edge **independently**; neither may be assigned from the other, and
  an unavailable side must be recorded as such.
- **CA3** — replace the residual with a **satisfiable** one over adjacent uncut triangle pairs whose shared edge is
  not in `componentBarriers`, counting pairs whose certified faces **differ**; publish the **examined** count
  separately from the **differing** count.
- **CA4** — publish the failing component's **certified-face multiset**, bounded. Several faces ⇒ missing-barrier
  branch; one face ⇒ seed-read branch.
- **CA5** — one witness per new field through the production path, plus an unrelated-error regression witness.
- **CA6** — **every new diagnostic must be falsifiable, and its witness must exercise the variation.** Supersedes
  ordinal 393's contract under BZ7's escape clause.
- **CA7** — append the next selector **named by its resulting identity count**; 393 stays an exact prefix;
  regenerate `Required_Green_Selector_Manifest.md` with `tools/selector_manifest.py`.
- **CA8** — **no product semantic change**: the seed rule, the guard, `componentBarriers`, the partition,
  `seedOrbits`, `edgeOrbitEvidence`, `add_fragment_orbit`, the `exteriorOrbits` filter, `is_terminal_slit`, the
  face walk, the rotation system, region drafts, CB21's comparison, `proves_cellularity()` and the certificate stay
  untouched; `localFragmentCount` stays non-fatal. **No barrier-set change. No revert of CB21.**
- **CA9** — six `M3-CP4c-3-TB23` discriminators, chiefly a **non-zero examined-pair count**, independently computed
  certified faces on both sides of each minority edge, and the certified-face multiset that **names the live
  branch**.

**No further diagnostic turn is authorized on this surface after TB23.** The successor after TB23 is an
independent `M3-CP4c-3-TB23-REV`.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / ARCHITECTURAL / GATING / BOTH BRANCHES LIVE** — the source-face component construction is an unvalidated projection of a certified cellular complex. CB24's evidence was vacuous, so neither the missing-barrier nor the seed-read branch is eliminated. Owner: CA1–CA4, then TB23-REV. |
| `M3-CP4c3-TB22-REV-CAND-01` | **NEW / ACTIVE / EVIDENCE INTEGRITY** — two production diagnostics report values that cannot vary; ordinal 393 pins the vacuous contract as required-green. Owner: CA1–CA3 and CA6. |
| `M3-CP4c3-TB21-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 391 passes with the sphere half explicitly skipped. |
| `M3-CP4c3-TB20-REV-CAND-02` | **ACTIVE / FORMAL ONLY** — CB21 not reverted; Parts IV/V's written prohibition remains unlifted. Owner: a DEFN turn. |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / SYMPTOM RECORD** under `M3-CP4c3-TB21-CAND-01`. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed:** `M3-CP4c3-TB21-CAND-02`, `M3-CP4c3-TB10-REV-CAND-01`, `M3-CP4c3-TB19-REV-CAND-02`,
`M3-CP4c3-TB17-CAND-01`. The historical torus `UncutFaceComponentOrbitSeedNotUnique` record stays separate as the
genuine non-cellular case Part I proved.

---

## 5. Settled facts a successor must not reopen

- **`projectionFaithfulnessResidual = 0` is a structural zero** — the predicate is unsatisfiable by construction.
  It never ruled anything out and must not be cited as evidence.
- **The minority rows' certificate-face columns are the seed value re-printed.** Their agreement is a tautology.
- **Both branches of `M3-CP4c3-TB21-CAND-01` are live.**
- **The mechanical actual embedded complex is cellular** — `22 − 26 + 6 − 2 = 0`, all faces certified discs.
- **Part I §3 is an implication with a premise**; it says nothing about the source-face projection.
- **The certificate and the seed guard test different objects**; neither validates the other.
- **CB21 is not reverted**; only the formal Parts IV/V gap remains, owned by a DEFN turn.
- **371/372 and ordinal 391 are closed**; the atlas accessor is test-only and never product authority.
- **A universal chord non-crossing invariant is refuted**; `localFragmentCount` must not become a fatal oracle.
- The face walk is a validated total permutation; shared orbit ownership by the two sides of one arc is legitimate
  topology. **BS9-5 remains retired.**
- Identical typed error names across witnesses do not establish identical root cause.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first.
2. **this file** — current frontier, frozen successor, settled facts and candidate ownership.
3. `Architecture_M3_CP4c3_TB22_Independent_Review_Record.md` — the frozen **CB25** scope, §8 CA0–CA9.
4. `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` — current immutable runtime authority.
5. `M3_CP4c_Frozen_Definitions.md` — **Part I §3 is an implication with a premise**; Parts IV/V prohibited lists;
   Part VI for vertex-star definitions. **Read the prohibited lists before authorizing any correction, and carry
   each finding's premise, not just its conclusion.**
6. `GMP_COMPILE_POLICY.md` — mandatory for every compile.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `Required_Green_Selector_Manifest.md` — selector counts, LF hashes, prefix parents and roles.
9. `M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed; its **folded document index**
   resolves every folded or retired per-turn plan, report and record.

**Review tooling.** `.agents/Directional/tools/` holds read-only helpers: `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py`, `selector_manifest.py`, and `fixture_probe.py`. See
`tools/README.md` for the caveats — in particular that geometric sharpness is not the product's barrier set, and
that the singularity reconstruction is corroboration only.

**Document consolidation.** Every REVIEW turn folds its superseded per-turn documents into
`M3_CP4c_Consolidated_Record.md`'s folded document index under `CLEAN_UP_POLICY.md`, **and indexes anything a CB or
TB turn's stale-evidence cleanup retired between reviews**. Preserve durable facts in a retained record first;
never fold current authority, normative definitions, policies or selector files.
