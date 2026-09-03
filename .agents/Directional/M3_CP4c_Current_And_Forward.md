# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in
`M3_CP4c_Frozen_Definitions.md` Part VI; selector files remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB19-REV`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime authority** | **`M3-CP4c-3-TB19`** — source `b00efbd53d3da8caa2bcac0d66594e06e44d2cb2`, run/job `33798040003 / 100790444711`, **376 PASS / 8 RED** |
| **Current gate selector** | **384** — `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`, 384 identities, selector 383 an exact prefix, accepted 365 an exact prefix |
| **Immutable package** | compile run/job `33794307778 / 100778238374`, result artifact `9908695433`, ZIP SHA-256 `efb65c06cc6d73d233ee271a31fc82705d2575da313fb7f18b389a5196441fc5` |
| **TB19 artifacts** | result/log `9910078670 / 9910079341` |
| **Ledger** | `e9ab64a8392aa1e16e30e03f440865914df846567e4b4fd12f3dce241841c04b` — 376 + 8 = 384, closes |
| **First red** | ordinal **366**, `UncutFaceComponentOrbitSeedNotUnique`, source face **`(0,1,2)`** = mesh row 0 |
| **Red set** | 366, 367, 368, 369, 370, 371, 372, 374 |
| **Package census** | pre/post identical, `c238668140634325a75dbb48ed23ce5659376cb5d2d7b79f3f3f46ab275e133d` |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **85** |

---

## 2. The current frontier — locus proved non-discriminating, mechanism unobservable

**CB21 is confirmed against BU0–BU9.** Ordinals 1–365 stay 365/365; ordinal 366 leaves
`TraceCutFaceFragmentCountMismatch` (the load-bearing discriminator); 367/371/372 move with it; ordinal 384 passes;
face `(0,1,102)` retains `localFragmentCount=2 / ownerCount=1 / ownerDeficit=1` non-fatally. The accepted-boundary
safety proof TB18-REV made by construction is now runtime-visible. **`M3-CP4c3-TB17-CAND-01` closes.**

The new frontier is `UncutFaceComponentOrbitSeedNotUnique` at source face `(0,1,2)`, emitted at
`GlobalTopologyPlan.cpp:1151–1163` in the block that labels faces no chord touched. `componentBarriers` is
`mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`; components are maximal sets of unlabeled faces joined across
non-barrier edges; `seedOrbits[component]` unions the labeled neighbour's orbit over every non-barrier boundary
edge; the guard demands `size() == 1`.

**`M3-CP4c-3-TB19-REV` adjudicated it under CR0–CR8**
(`Architecture_M3_CP4c3_TB19_Independent_Review_Record.md`):

- **The reported locus is an iteration artifact, proved.** `failure.sourceFace` is the **first unlabeled face in
  `std::map` key order**. `(0,1,2)` is **row 0 of the mechanical fixture and row 0 of the torus fixture**, and the
  historical torus stop of the same name reported the identical face. Two unrelated witnesses, same code, same
  locus.
- **Zero seeds versus two-or-more is NOT derivable from committed bytes.** Neither the component id, its
  membership, nor its seed set is retained. Partial evidence favours two-or-more — face `(0,1,2)` neighbours
  labeled row 259 `(0,1,102)` across edge `0-1`, which the TB18 chord never made a carrier
  (`incomingCarrier=none`) — but the barrier membership of `0-1` is a product decision not recoverable statically.
- **The torus stop is a different mechanism; the candidates are not merged.** With **0 traces** no face acquires a
  chord label, so no edge has a labeled side and every seed set is empty — provably the **zero** branch. The
  mechanical witness has 70 labeled faces and 6 non-exterior orbits and cannot be that.
- **The deciding numbers are discarded, sixth instance.** The component id, its membership and `seedOrbits` are all
  in hand at the failure; only `sourceFace` survives, and it is the one field that cannot discriminate.
- **A universal chord non-crossing invariant is REFUTED, not merely unproved.** The tracer builds
  `TraceIntersection` contact nodes bound to a source face, so crossings are a modelled case in which `k` chords
  make `k + 1 + c` local fragments. The 70/70 non-crossing rows are witness-local sufficiency only.

---

## 3. Exact next turn — `M3-CP4c-3-CB22`, diagnostic-only, `BV0–BV9`

Full text in §10 of `Architecture_M3_CP4c3_TB19_Independent_Review_Record.md`. Zero and two-or-more imply
**opposite** corrections, so no product correction is authorized. TB18-REV's prohibition on further diagnostic-only
turns was scoped to the fragment-count surface, which CB21 corrected and TB19 closed; **it does not reach this
surface.** In brief:

- **BV0** — accepted 365 untouched; selector **384 byte-frozen** and republished unchanged; eight standard compile
  targets with **mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BV1** — the component id, its seed count, and an explicit **`seedState ∈ {None, Multiple}`** on the error.
- **BV2** — the failing component's face count and bounded membership, with a truncation marker.
- **BV3** — bounded boundary-edge rows: edge key, labeled-side flag, owner count, barrier class, and the seed or
  the exact reason none was contributed — **including the silent `edgeOrbitEvidence`-not-unique skip at
  `:1136–1139`**.
- **BV4** — publish that `sourceFace` is an iteration-order locus; add the component identity as the
  discriminating one.
- **BV5** — extend the existing `TraceFragmentOwnerEvidenceDiagnostic` census with component rows.
- **BV6** — one witness per new field plus an unrelated-error regression witness; append **selector 385**; 384
  stays an exact prefix.
- **BV7** — **no semantic change**: the predicate, `componentBarriers`, the partition, `seedOrbits`,
  `edgeOrbitEvidence`, `add_fragment_orbit`, the `exteriorOrbits` filter, `is_terminal_slit`, the face walk, the
  rotation system, region drafts and CB21's comparison stay untouched. **`localFragmentCount` stays non-fatal.**
  No 371/372 test decoupling.
- **BV8** — audit by assumption; prove 1–365 unaffected by construction.
- **BV9** — six `M3-CP4c-3-TB20` discriminators, chiefly: 1–365 stay 365/365; ordinal 366 **still** reds at the
  same site; and the failure now publishes **`seedState`**, deciding zero versus multiple.

**One diagnostic turn only.** The successor after TB20 is an independent `M3-CP4c-3-TB20-REV`, expected to
authorize a product correction rather than a further observation turn.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / GATING / MECHANISM UNOBSERVABLE / LOCUS PROVED NON-DISCRIMINATING** — the component-seed frontier; zero-versus-multiple undetermined. Owner: BV1–BV4, then TB20-REV. |
| `M3-CP4c3-TB19-REV-CAND-02` | **NEW / ACTIVE / EVIDENCE CONTRACT** — `UncutFaceComponentOrbitSeedNotUnique` retains only `sourceFace`, an iteration-order locus two unrelated witnesses both report as `(0,1,2)`. Owner: BV4. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED** — a universal non-crossing invariant is refuted by the product's own `TraceIntersection` contact nodes. Closure requires `localFragments = k + 1 + interiorCrossings` validated on a crossing witness. **Must not be promoted to fatal.** |
| `M3-CP4c3-TB10-REV-CAND-01` | **ACTIVE / TEST-COUPLING / DEFERRED with a standing trigger** — 371/372 abort in a fixture constructor that will stop throwing once the plan builds. Authorize the test-only atlas-scoped decoupling at the first review that either closes the mechanical production frontier or finds it unmoved across two consecutive TB turns. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. No atlas invariant may be weakened for it. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared bound on its input size. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368, `CellularityNotEstablished` originating `RotationSystemInconsistent / TraceEventPositionInvalid`, trace 2 / event 30. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — zero-node / zero-arc closed-surface cut-graph behaviour, ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**`M3-CP4c3-TB17-CAND-01` is CLOSED at TB19**: its runtime condition was that ordinal 366 move past the
fragment-owner low-side mismatch, and 366/367/371/372 all do with accepted 365/365 preserved.

**The historical torus `UncutFaceComponentOrbitSeedNotUnique` record is NOT merged** with
`M3-CP4c3-TB19-CAND-01`; §2 proves a different mechanism.

Other closed candidates remain closed unless new immutable runtime evidence reopens them.

---

## 5. Settled facts a successor must not reopen

- **CB21's correction is runtime-proved** and must not be reverted. `|global owners| = k+1` is not a valid
  universal invariant; the low-side relaxation stands and high-side owner overcount remains fatal.
- **The reported `sourceFace` of `UncutFaceComponentOrbitSeedNotUnique` is an iteration artifact**, and the torus
  stop of the same name is a different mechanism.
- **A universal chord non-crossing invariant is refuted**; `localFragmentCount` must not become a fatal oracle
  without the crossing derivation and a crossing witness.
- The face walk is a validated total permutation; its orbits are its cycles. Shared orbit ownership by the two
  sides of one arc is legitimate topology.
- **BS9-5 remains retired.**
- Identical typed error names across witnesses do not establish identical root cause.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first.
2. **this file** — current state, frozen successor, candidate index.
3. `Architecture_M3_CP4c3_TB19_Independent_Review_Record.md` — the frozen **CB22** scope, §10 BV0–BV9.
4. `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Report.md` — current immutable runtime authority.
5. `M3_CP4c_Frozen_Definitions.md` Part VI — normative definitions and amendments.
6. `GMP_COMPILE_POLICY.md` — mandatory for every compile.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed; its **folded document index**
   resolves every folded per-turn plan, report and record.

**Review tooling.** `.agents/Directional/tools/` holds read-only helpers: `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes and ordinal ↔ identity lookups, and
`fixture_probe.py` for fixture topology, dihedrals and vertex fans. See `tools/README.md` for the caveats — in
particular that geometric sharpness is not the product's barrier set, and that the singularity reconstruction is
corroboration only.

**Document consolidation.** Every REVIEW turn folds its superseded per-turn documents into
`M3_CP4c_Consolidated_Record.md`'s folded document index under `CLEAN_UP_POLICY.md` §"Document consolidation —
every REVIEW turn". Preserve durable facts in a retained record first; never fold current authority, normative
definitions, policies or selector files.
