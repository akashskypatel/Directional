# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-05** at `M3-CP4c-3-TB28` closeout.

---

## 1. Where the checkpoint stands

**TB28-R2 is the latest semantic runtime authority:** selector407 completed **407/407 GREEN** on immutable CB32 artifact `9975737868` / source `098ac7d93ea203222dd0ac50cdb68667744f0fd4`. Formal run `33990951740`; execution/verification jobs `101373825038 / 101374345712`; result/log artifacts `9976662518 / 9976662690` with SHA-256 `970573beb31bc43bb2cbcd4dee957edfb2f23c0c543edfe9997c5dcfc487053d` / `4272bd5fc1750d19c9fceb94daf3be8367b05d6fa9e13828fc6a97c1c6fe44d`. All source/test/fixture/selector mutation flags were false before and after runtime; package/binary/selector postflight was unchanged.

R1 `33990315861` is orchestration-invalid and non-semantic because it failed before runtime on an incorrect package-layout assumption.

CP4c-3 remains OPEN. Stable accounting stays **44 / 14 / 30**, debt **5**. Full selector green does not close the semantic checkpoint because the diagnostic contract intentionally reports the unresolved production ownership mismatch for independent review.

## 2. Current frontier — TB28 has measured the CL6 / CL7 discriminator

The mechanical failure remains `ReliefTopologyBuildFailed`, failing plan component `1`. Candidate face count is 27; `candidateFacesEqualCensusComponent=false`; `candidateFacesSubsetOfCensusComponent=true`; `censusFailureCount=0`. The failing plan component publishes 101 interior-arc rows, all 101 present and untruncated.

The decisive crossed-face publication is:

`arc=(0,2):sourceFace=0:certifierComponent=0:planComponent=1:notTraceCutReason=TerminalSlit`

Thus TB28 directly measures that a crossed source face is assigned different component ids in the certifier and plan partitions, while the candidate set is a strict subset of the census component. This closes the missing CL6/CL7 evidence surface, not the correction choice. TB28 changed no barrier, attribution, seed, partition, or terminal-slit semantics.

## 3. Exact next turn — `M3-CP4c-3-TB28-INDEPENDENT-REVIEW`

The independent review must consume `Architecture_M3_CP4c3_TB28_R2_Artifact_Only_Test_Benchmark_Report.md` together with the TB27 CL6–CL9 review record and freeze one product correction. **CL8 is binding:** no fourth standalone source-face ownership diagnostic turn is authorized and no correction CB may start before review.

The review must reconcile the active ownership candidates with the measured face/component row, update `ORIENTATION.md`, and perform the mandatory REVIEW document consolidation before closeout.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB27-REV-CAND-01` | **NEW / ACTIVE / GATING / PRODUCT** — the certifier's 214-face component contains two separating arcs, so that partition **merges faces lying in different certified faces**; any owner propagated across it would be unsound, masked only because the component has no unique seed. TB28 supplies the CL6 face/component measurement; owner is now the mandatory TB28 independent review. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 belong to different partitions; TB27 additionally exposes 214-vs-191 faces and distinct digests. |
| `M3-CP4c3-TB27-REV-CAND-02` | **NEW / ACTIVE / ARCHITECTURAL / NON-GATING** — the plan excludes from its component domain exactly the faces carrying a direct certified read (`GlobalTopologyPlan.cpp:702`, `:750`), then fails to seed that component. TB28 confirms subset-but-not-equality and a cross-partition component-id mismatch; owner is now the mandatory TB28 independent review. |
| `M3-CP4c3-TB26-REV-CAND-04` | **RUNTIME-PROVED / GATING / ARCHITECTURAL** — ordinal406 reports `matchesFailingComponent=false`; census and failure partitions differ. |
| `M3-CP4c3-TB25-REV-CAND-02` | **ACTIVE / GATING / UNDECIDED FOR THE FAILING OBJECT** — the certifier component contains two separating arcs, but it is not the 191-face failing plan component. TB28 supplies the previously missing crossed-face/component evidence; **CL8 requires the independent review to resolve it before any correction CB**. |
| `M3-CP4c3-DEFN-R3-CAND-01` | **RUNTIME-PROVED / GATING / ARCHITECTURAL** — duplicated constructions yield different partition objects on the witness; diagnostic census runs on the non-failing one. |
| `M3-CP4c3-TB24-REV-CAND-02` | **ACTIVE / ARCHITECTURAL** — ownership of non-arc-incident faces is a derivation, not a read. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE / EVIDENCE INTEGRITY** — earlier vacuous diagnostic surfaces remain historical architectural debt; ordinal393's current contract itself is runtime-proved. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed at TB27-REV, runtime-proved:** `M3-CP4c3-TB26-REV-CAND-01` (all four rows published with both dart
orbits, untruncated, digest validated) and `M3-CP4c3-TB26-REV-CAND-03` (ordinal 393 PASSes on distinct-source-face
coverage while preserving every conflicting owner observation). `M3-CP4c3-TB26-REV-CAND-02` remains RESOLVED as a
lawful domain difference. `M3-CP4c3-TB26-REV-CAND-04` and `M3-CP4c3-DEFN-R3-CAND-01` are **confirmed at runtime and
gating** — they stay open because their corrective rule is not yet authorized, not because the evidence is
lacking.

---

## 5. Settled facts a successor must not reopen

- **`projectionFaithfulnessResidual = 0` is a structural zero** — the predicate is unsatisfiable by construction.
  It never ruled anything out and must not be cited as evidence.
- **The minority rows' certificate-face columns are the seed value re-printed.** Their agreement is a tautology.
- **Both branches of `M3-CP4c3-TB21-CAND-01` are REFUTED, and the question is closed as ill-formed.** Do not re-pose it. The successor question is whether component 0 lies in a single certified face — asked about the object, not about a rule.
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
- **Two of four certifier interior arcs SEPARATE** — arc 14 `(0,1)`, arc 22 `(0,3)`; arcs 20 and 24 are `(0,0)`.
  An arc separates iff its dart orbits differ. Do not re-derive this from the terminal-slit flag: a per-segment
  property does not classify an arc.
- **`matchesFailingComponent=false` is runtime-proved.** Never quote a certifier-census number as evidence about
  the 191-face failing plan component.
- **The plan's domain is contained in the certifier's**, with the same barrier families; the 23-face difference is
  the faces carrying a direct certified read, which the plan excludes and then cannot find as seeds.
- **A diagnostic gated on the success of the thing it diagnoses can never fire on the case it was built for.**
  D3 proved this at a cost of one full turn.
- **Relocating a derivation adds no information.** CB27 moved ownership into the certifier — the right authority —
  and got `[0,1,3]` at `(0,1,2)`, the same answer as before.
- **384/385 recovered at TB25-R1; 389/390 recovered at TB26-R1 after their contracts were narrowed to identity-owned evidence.** No accepted behaviour was lost.
- **An incidence count is not a separation.** `interiorArcs=4` says four arcs touch the component; it says nothing
  about whether any of them separates certified faces. Only the per-arc dart-orbit pair does.
- **There are two partitions, not one.** The plan's is over faces with no fragment orbits; the certifier's is over
  faces not crossed by a trace. Never quote a number from one as evidence about the other.
- **A census over established values is vacuous where nothing is established.** CH8's `rowCount=0` proved this at a cost of one turn.
- **Only arcs separate certified faces.** An uncut component whose interior no arc meets lies in exactly one certified face. This is a proof, not a measurement.
- **TB27 runtime refutes the claim that all four certifier interior arcs are bridges:** arcs 14 and 22 have
  different forward/reverse orbits; arcs 20 and 24 have equal orbits. This fact is scoped to the certifier
  `NotTraceCut` partition.
- **The failure and census partitions are runtime-proved different:** ordinal406 publishes
  `matchesFailingComponent=false`. Never transfer certifier component counts/arcs to the failing plan component.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load only the minimum current authority:

1. `ORIENTATION.md` — read first.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_TB28_R2_Artifact_Only_Test_Benchmark_Report.md` — latest semantic runtime authority.
4. `Architecture_M3_CP4c3_TB27_Independent_Review_Record.md` — CL6–CL9 and CL8 hard stop.
5. `Architecture_M3_CP4c3_CB32_Code_Build_Report.md` — exact diagnostic publication/package authority.
6. `Architecture_M3_CP4c3_TB28_Artifact_Only_Test_Benchmark_Plan.md` — frozen executed runtime contract.
7. `M3_CP4c_Frozen_Definitions.md`, `Regression_Root_Cause_Tracker.md`, `Required_Green_Selector_Manifest.md`.
8. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.

Exact next is **`M3-CP4c-3-TB28-INDEPENDENT-REVIEW`**. Do not start another diagnostic or a correction CB before that review. The review must freeze the correction under CL8.
