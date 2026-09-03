# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in
`M3_CP4c_Frozen_Definitions.md` Part VI; selector files remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB18`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current runtime selector** | **383** — `a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`, TB18 authority |
| **Current runtime authority** | **`M3-CP4c-3-TB18`**, source `57635e87306a416daabb8321e1f36fa9c788d208`, run/job `33785382790 / 100748821924`, result/log `9905330011 / 9905330748` |
| **Current build authority** | **`M3-CP4c-3-CB20`**, diagnostic-only source `57635e87306a416daabb8321e1f36fa9c788d208`, compile `33780005014 / 100731152066` |
| **Ledger** | `a99c31d84200cb97e78bb399fa32c76bea1f3767092f29fc339c4cc9130604ed` — **375 PASS / 8 RED** |
| **First red** | ordinal **366**, `TraceCutFaceFragmentCountMismatch`, source face **`(0,1,102)`** = mesh row 259 |
| **Measured mismatch** | `fragmentOrbitCount=1`, `tracePieceCount=1`, `expectedFragmentCount=2` — **actual < expected** |
| **Red set** | 366, 367, 368, 369, 370, 371, 372, 374 |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **84** |

---

## 2. The current frontier

TB18 runtime-measures the fragment-count failure that TB17-REV classified statically. On face `(0,1,102)`:

- one real chord is retained (`trace=1`, `arc=15`, `segment=4`, `orientation=Forward`);
- `incomingCarrier=none`, `outgoingCarrier=0-102`;
- **both** oriented chord sides map to global orbit id `0`;
- neither side is dropped by `exteriorOrbits`;
- each of the face's three edge-evidence rows contains only orbit `0`;
- consequently `fragmentOrbits.size()==1` while `tracePieceCount+1==2`.

This is direct runtime evidence of the **shared-global-owner** low-side mechanism. It is not an exterior-filter case.
The old equality therefore compares a local geometric fragment count to a deduplicated global owner count on a witness
where that map is visibly non-injective.

TB18 does **not** choose the replacement representation or invariant. That is the exact responsibility of the
independent review. A local count tweak, special case for `(0,1,102)`, disabling deduplication, or changing exterior
filtering is not authorized without a proved contract and accepted-boundary argument.

One required text diagnostic remains absent: the retained selector logs contain no
`M3_CP4AB_FRAGMENT_DIAG record=fragment_reconciliation` line for the failing face. The typed production failure does
retain all three edge-evidence rows. The frozen TB18 plan forbids an ad-hoc rerun solely to obtain the missing record.

---

## 3. Exact next turn — `M3-CP4c-3-TB18-REV`, independent REVIEW + PLAN only

Review immutable report `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Report.md` and adjudicate the
representation contract. The review must:

1. preserve selector 383 runtime authority **375 PASS / 8 RED** and accepted **365/365**;
2. use the measured `1 / 1 / 2` mismatch and exact chord/orbit incidence as the primary new evidence;
3. distinguish **local fragments** from **global region-orbit owners** explicitly and decide which quantity the
   product must represent at this stage;
4. account for the three edge-evidence rows and BS9-5's missing `fragment_reconciliation` text record without
   authorizing an evidence-seeking rerun retroactively;
5. preserve CB19's terminal-slit/carrier-less contract and the independent owners of 368/369/370/374;
6. freeze exactly one bounded successor only after the contract is proved. No semantic Code + Build is pre-authorized
   by TB18 itself.

Because this is a REVIEW turn, `ORIENTATION.md` must be updated before closeout.

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB17-CAND-01` | **ACTIVE / GATING / MECHANISM RUNTIME-MEASURED / CONTRACT UNADJUDICATED** — TB18 observes one real chord whose forward/reverse sides both map to global orbit `0`, no exterior filtering, actual/trace/expected `1/1/2`. Owner: TB18-REV representation adjudication. |
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

1. `ORIENTATION.md` — read first and update it during this REVIEW turn.
2. **this file** — current state and exact successor.
3. `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Report.md` — current immutable runtime authority.
4. `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md` — frozen contract that produced the evidence.
5. `Architecture_M3_CP4c3_TB17_Independent_Review_Record.md` — prior static owner-class adjudication.
6. `M3_CP4c_Frozen_Definitions.md` Part VI — normative definitions and amendments.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed.

**Review tooling.** `.agents/Directional/tools/` holds read-only helpers: `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes and ordinal ↔ identity lookups, and
`fixture_probe.py` for fixture topology, dihedrals and vertex fans. See `tools/README.md` for caveats.
