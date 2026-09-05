# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-04** at `M3-CP4c-3-CB31` Code + Build closeout.

---

## 1. Where the checkpoint stands

**TB26-R1 remains the latest semantic runtime authority:** **397 PASS / 8 RED**, accepted **365/365**, on CB30
package `9957324848` / source `e045bf7147afc02bd90eff4822e4b609edbaba66` / selector405. Result artifact
`9958722468`; run/job `33931380325 / 101210520053`.

**CB31 is the current compile authority and is not yet semantically accepted:** clean source
`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`, immutable package `9961564041`, selector406, compile run/job
`33940038189 / 101235542774`. The package compiled all eight approved targets Release/static `PRE_TEST` with
GMP/GMPXX linked, preflight/build exit codes zero, and `runtimeExecution=false`. CB31 advances semantic M3 package
count to **92**. CP4c-3 remains OPEN. Stable accounting stays **44 / 14 / 30**, debt **5**.

Selector 406 has 406 identities, LF SHA-256
`efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`; selector405 is its exact prefix.
No Directional runtime has executed on CB31.

## 2. Current frontier — the discriminator is now published but not yet executed

CB31 implemented CK8–CK9 without changing product behavior. The failure locus can now serialize every relevant
certifier census row, the plan and certifier partition identities, their stable face-set digests, and whether the
census component matches the failing plan component. Ordinal 393 now owns distinct-source-face coverage rather
than observation-row arity; ordinal 404 owns untruncated publication and both dart-orbit fields; ordinal 406 owns
publication of partition correspondence, **not equality**.

The architectural distinction remains settled: the plan partitions faces with empty fragment orbits using
`mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`; the certifier partitions faces not crossed by a trace with its
own typed barrier composition. **76 versus 97 remains a lawful domain difference, not omitted rows.** CB31 merely
makes the two identities and their correspondence auditable.

The independent review's static bridge argument remains deliberately unresolved by Code + Build evidence. It
predicts that each of the four certifier interior-arc rows will have equal forward/reverse orbits, but only TB27 may
measure those values. Likewise, compile success says nothing about whether the plan and certifier component face
sets match on the runtime witness.

## 3. Exact next turn — `M3-CP4c-3-TB27`

Artifact-only Test + Benchmark on immutable CB31 package `9961564041` / source
`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc` / selector406. No rebuild, relink, repair, package mutation,
source/test/fixture/selector mutation, or other semantic change is authorized.

- Execute the full **406** identities one per fresh process.
- Preserve accepted-prefix authority **1–365** and ordinal **398** unchanged.
- Report ordinal **393** distinct-source-face coverage and full owner observations.
- Report ordinal **404** complete named census rows, including both dart orbits for every interior arc.
- Report ordinal **406** plan/census partition identities, digests, and the published match boolean.
- Produce the ordinary semantic ledger and immutable pre/post source/package/execution-view censuses.

CB31 compiled publication surfaces; **TB27 is the first turn authorized to use them as runtime evidence.**

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB26-REV-CAND-01` | **UPHELD / IMPLEMENTED IN CB31 / AWAITING TB27** — complete named rows and both dart orbits are now compiled for publication; runtime values remain unmeasured. |
| `M3-CP4c3-TB26-REV-CAND-02` | **RESOLVED / LAWFUL DOMAIN DIFFERENCE** — 76 and 97 are boundaries of two different partitions; no row was omitted. |
| `M3-CP4c3-TB26-REV-CAND-03` | **UPHELD / IMPLEMENTED IN CB31 / AWAITING TB27** — ordinal 393 now gates distinct-source-face coverage and untruncated owner publication, not row arity. |
| `M3-CP4c3-TB26-REV-CAND-04` | **ACTIVE / INSTRUMENTED IN CB31 / AWAITING TB27** — both partition identities/digests and their correspondence are now compiled for publication. |
| `M3-CP4c3-TB25-REV-CAND-02` | **ACTIVE / GATING / UNDECIDED** — *is the failing component contained in a single certified face?* CB31 exposes the evidence; TB27 must decide what the runtime rows support. |
| `M3-CP4c3-DEFN-R3-CAND-01` | **GATING / INSTRUMENTED IN CB31 / AWAITING TB27** — the two partition identities are now explicit; selector406 gates publication of their correspondence. |
| `M3-CP4c3-TB24-REV-CAND-02` | **ACTIVE / ARCHITECTURAL** — ownership of non-arc-incident faces is a derivation, not a read. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE / EVIDENCE INTEGRITY / CB31 CONTRACT REPAIRED** — 393 now measures distinct-face coverage; TB27 must execute it. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed at this review, runtime-proved:** `M3-CP4c3-TB25-REV-CAND-01` (starved seed rule — restored, reproduces
`[0,1,3]`), `M3-CP4c3-TB25-REV-CAND-03` (389/390 foreign assertions — both PASS). **Previously closed:**
`M3-CP4c3-TB21-CAND-01` (ill-formed), `M3-CP4c3-TB19-CAND-01`, `M3-CP4c3-TB24-REV-CAND-01`,
`M3-CP4c3-TB25-ORCH-01`, `M3-CP4c3-TB23-REV-CAND-01/02`, `M3-CP4c3-TB23-R1-REV-CAND-01`,
`M3-CP4c3-TB21-CAND-02`, `M3-CP4c3-TB10-REV-CAND-01`, `M3-CP4c3-TB19-REV-CAND-02`, `M3-CP4c3-TB17-CAND-01`.

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
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load only the minimum current authority:

1. `ORIENTATION.md` — read first.
2. **this file** — current frontier and candidate ownership.
3. `Architecture_M3_CP4c3_CB31_Code_Build_Report.md` — current immutable compile/package authority.
4. `Architecture_M3_CP4c3_TB26_Independent_Review_Record.md` — CK0–CK9 and the evidence questions TB27 must answer.
5. `Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md` — latest semantic runtime baseline.
6. `M3_CP4c_Frozen_Definitions.md`, `Regression_Root_Cause_Tracker.md`, `Required_Green_Selector_Manifest.md`.
7. `M3_CP4c_Consolidated_Record.md` — folded-document resolver.

Exact next is `M3-CP4c-3-TB27`, artifact-only execution of selector406 on immutable CB31 package `9961564041`.
No CB31 compile result may be treated as runtime evidence.
