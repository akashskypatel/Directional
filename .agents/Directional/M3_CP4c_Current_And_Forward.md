# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in
`M3_CP4c_Frozen_Definitions.md` Part VI; selector files remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB17-REV`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current gate selector** | **382** — `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`, 382 identities, accepted 365 as an exact prefix |
| **Current runtime authority** | **`M3-CP4c-3-TB17`**, immutable package **87**, source `bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e`, run/job `33770523736 / 100699356052` |
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

## 3. Exact next turn — `M3-CP4c-3-CB20`, diagnostic-only, `BS0–BS9`

Full text in §10 of `Architecture_M3_CP4c3_TB17_Independent_Review_Record.md`. In brief:

- **BS0** — accepted 365 untouched; selector **382 byte-frozen** and republished unchanged; eight standard compile
  targets with **mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BS1** — put **actual**, **expected** and `tracePieceCount` on the error and render them through the production
  locus path.
- **BS2** — retain the failing face's contributing incidences: per real chord the trace and arc ids, segment index,
  orientation, both carriers, **both** orbit ids, and any exterior-drop flag. Bounded, with a truncation marker.
- **BS3** — publish the accumulated `edgeOrbitEvidence` for the face's three edges, bounded the same way.
- **BS4** — make the existing `fragment_reconciliation` diagnostic reachable on the failing path.
- **BS5** — one witness per new field through the production path, plus a byte-identical regression witness.
- **BS6** — append selector **383** only on demonstrated falsification; no reordering.
- **BS7** — **no semantic change whatsoever**: the comparison, `tracePieceCount`, `add_fragment_orbit`, the
  `exteriorOrbits` filter, `is_terminal_slit`, `resolve_carrierless_corner_binding`,
  `build_fragment_corner_incidence`, `build_regions` and all orbit/region construction stay untouched; CB19 is not
  reverted.
- **BS8** — audit by assumption; prove ordinals 1–365 unaffected by construction.
- **BS9** — six `M3-CP4c-3-TB18` discriminators, chiefly: 1–365 stay 365/365; ordinal 366 **still** reds at the
  same face (any movement falsifies BS7); and the line now carries the **direction** of the mismatch plus the
  per-chord incidences.

**No product correction is authorized until TB18 supplies the direction and the contributing incidences.** The
successor after TB18 is an independent `M3-CP4c-3-TB18-REV`, which owns the representation decision.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB17-CAND-01` | **ACTIVE / GATING** — owner class named at TB17-REV (local-fragment vs global-owner representation); corrective contract unadjudicated. Owner: BS1–BS4, then TB18-REV. |
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
3. `Architecture_M3_CP4c3_TB17_Independent_Review_Record.md` — the frozen **CB20** scope, §10 BS0–BS9.
4. `Architecture_M3_CP4c3_TB17_Artifact_Only_Test_Benchmark_Report.md` — current runtime authority.
5. `M3_CP4c_Frozen_Definitions.md` Part VI — normative definitions and amendments.
6. `GMP_COMPILE_POLICY.md` — mandatory for every compile.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed.

**Review tooling.** `.agents/Directional/tools/` holds read-only helpers: `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes and ordinal ↔ identity lookups, and
`fixture_probe.py` for fixture topology, dihedrals and vertex fans. See `tools/README.md` for the caveats — in
particular that geometric sharpness is not the product's barrier set, and that the singularity reconstruction is
corroboration only.
