# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in
`M3_CP4c_Frozen_Definitions.md` Part VI; selector files remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-CB20`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime selector** | **382** — `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`, TB17 authority |
| **Frozen next gate selector** | **383** — `a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`, exact selector-382 prefix plus the CB20 diagnostic witness |
| **Current runtime authority** | **`M3-CP4c-3-TB17`**, immutable package **87**, source `bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e`, run/job `33770523736 / 100699356052` |
| **Current build authority** | **`M3-CP4c-3-CB20`**, diagnostic-only source `57635e87306a416daabb8321e1f36fa9c788d208`, compile `33780005014 / 100731152066`, runtime unexecuted |
| **Ledger** | `7c4464134a7be19150094bbee874ebe99878c3eaa004908d3660c1ffaa36b6fd` — **374 PASS / 8 RED** |
| **First red** | ordinal **366**, `TraceCutFaceFragmentCountMismatch`, source face **`(0,1,102)`** = mesh row 259 |
| **Red set** | 366, 367, 368, 369, 370, 371, 372, 374 |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **84** |

---

## 2. The current frontier

Ordinal 366 fails at `src/geometry/GlobalTopologyPlan.cpp:779`, the sole emitter of
`TraceCutFaceFragmentCountMismatch`:

```cpp
const std::size_t expected = tracePieceCount[faceKey] + 1U;
if (found->second.size() != expected) { … failure.sourceFace = faceKey; return failure; }
```

`M3-CP4c-3-TB17-REV` adjudicated it under **BRQ0–BRQ8**
(`Architecture_M3_CP4c3_TB17_Independent_Review_Record.md`):

- **The equality is unsound.** Each real chord contributes **one** to `tracePieceCount` and **two** insertions of
  global orbit ids into a `std::set`. Equality with `k+1` requires the local-fragment → global-owner map to be
  injective, which nothing establishes and which is false in general on a closed surface. `add_fragment_orbit`
  additionally drops any orbit in `exteriorOrbits` unconditionally.
- **Three mechanisms break it, in opposite directions**: a shared global owner (low), exterior filtering (low),
  and non-collapsing chord sides or duplicated orbit evidence (high).
- **The deciding numbers are computed and then discarded.** The same function fills `diagnostics->fragmentOrbits`,
  `tracePieceCount` and `edgeOrbitEvidence` and prints `fragment_orbit_count`, `trace_piece_count` and
  `expected_fragment_count` for every face — thirty lines *below* the early `return failure`, so the failing run
  never emits them.
- **Owner class named, corrective contract not yet provable.** Diagnostic-only is therefore mandatory under BRQ6.

Face `(0,1,102)` is mesh row **259** (stored corner order `(102,1,0)`); vertex 0 is a chamfered box corner, degree
4, defect 1.767801150, with edge `0-1` a 90° sharp edge shared by rows 0 and 259.

---

## 3. Exact next turn — `M3-CP4c-3-TB18`, artifact-only diagnostic gate

CB20 is complete under BS0–BS9. It adds only retained evidence to the existing fragment-count failure:

- actual fragment-orbit owner count, `tracePieceCount`, and expected local fragment count;
- bounded real-chord incidence with trace/arc/segment/orientation, both carriers, both face-walk orbit ids and
  exterior-drop flags;
- bounded edge-orbit evidence for the failing face's three edges;
- the existing `fragment_reconciliation` record before the failing early return;
- production projection and a compiled typed projection/regression witness.

The comparison and every topology-construction decision remain unchanged. Selector 382 is still byte-identical;
selector 383 is only selector 382 plus the one diagnostic projection witness. Exact build evidence is in
`Architecture_M3_CP4c3_CB20_Code_Build_Report.md`.

**TB18** must consume the immutable CB20 compile artifact only and discharge the six BS9 runtime discriminators:
accepted 365/365 stays green; ordinal 366 stays at the same reason/locus; exact mismatch direction becomes visible;
the bounded chord/edge incidence publishes; failing-face reconciliation is retained; and all carried failure surfaces
stay unchanged. No rebuild, repair, selector/source mutation, benchmark, or semantic correction is authorized.

Frozen plan: `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md`. The successor after a complete TB18
is **`M3-CP4c-3-TB18-REV` — independent REVIEW + PLAN only**.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB17-CAND-01` | **ACTIVE / GATING / DIAGNOSTICS COMPILED** — owner class named at TB17-REV; CB20 retains the deciding counts/incidences without changing semantics. Owner: TB18 measurement, then TB18-REV adjudication. |
| `M3-CP4c3-TB10-REV-CAND-01` | **ACTIVE / TEST-COUPLING / DEFERRED** — ordinals 371/372 blocked by a shared fixture precondition, not their own contracts. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness declares a flat-star field on a non-flat star; ordinal 374. No atlas invariant may be weakened for it. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared bound on its input size. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368, `TraceEventPositionInvalid / NoCarrierMatch / SourceEdgeUnavailable`. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — zero-node / zero-arc closed-surface cut-graph behaviour, ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; documented at TB8-REV, separate owner. |

**Closed and not to be reopened without new immutable evidence:** `M3-CP4c3-TB11-CAND-01`,
`M3-CP4c3-TB12-REV-CAND-01`, `M3-CP4c3-TB15-CAND-01` (all closed at TB16-REV, with the **v47 five-ray re-proof**
and CB18 closure preserved), `M3-CP4c3-TB11-REV-CAND-01`, `M3-CP4c3-TB13-CAND-01`,
`M3-CP4c3-TB13-REV-CAND-01`, `M3-CP4c3-TB14-CAND-01`, and the TB16 source-port candidate (closed at TB17 when the
`(9,11,17)` stop cleared).

---

## 5. Settled facts a successor must not reopen

- **CB19's results**, per BRQ1: the `(9,11,17)` `RegionTraceSourcePortCarrierNotAdmissible` stop is cleared; **48**
  non-first carrier-less segments exist and **all 48** have entry support distinct from the trace origin; the
  positive witness uses `SegmentEntrySupport`; there are **10** terminal slits; the retained terminal witness has
  `realChordContribution = 0`.
- **Terminal slits contribute zero to `k`** and publish no orbit evidence — consistently excluded from both sides
  of the fragment comparison.
- **CB12 / CB14 / CB15 / CB16 / CB17 / CB18 / CB19 corrections stand.** No successor may revert them.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first.
2. **this file** — current state, frozen successor, candidate index.
3. `Architecture_M3_CP4c3_CB20_Code_Build_Report.md` — current build authority and BS0–BS9 closeout.
4. `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md` — frozen exact next runtime plan.
5. `Architecture_M3_CP4c3_TB17_Artifact_Only_Test_Benchmark_Report.md` — current runtime authority.
6. `M3_CP4c_Frozen_Definitions.md` Part VI — normative definitions and amendments.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed.

**Review tooling.** `.agents/Directional/tools/` holds read-only helpers: `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes and ordinal ↔ identity lookups, and
`fixture_probe.py` for fixture topology, dihedrals and vertex fans. See `tools/README.md` for the caveats — in
particular that geometric sharpness is not the product's barrier set, and that the singularity reconstruction is
corroboration only.
