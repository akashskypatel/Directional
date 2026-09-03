# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in
`M3_CP4c_Frozen_Definitions.md` Part VI; selector files remain byte-frozen alongside.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-03** at `M3-CP4c-3-TB18-REV`.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**.
**CP4c-3 remains OPEN.**

| | |
|---|---|
| **Accepted authority** | **365 / 365** — selector 365, `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| **Current gate selector** | **383** — `a7fe57cc47c5035414a82f02f044a911f9c430f90d11f1bd3ef1bca76f3a4b2c`, 383 identities, selector 382 an exact prefix, accepted 365 an exact prefix |
| **Current runtime authority** | **`M3-CP4c-3-TB18`**, source `57635e87306a416daabb8321e1f36fa9c788d208`, run/job `33785382790 / 100748821924`, result artifact `9905330011` |
| **Ledger** | `a99c31d84200cb97e78bb399fa32c76bea1f3767092f29fc339c4cc9130604ed` — **375 PASS / 8 RED** |
| **First red** | ordinal **366**, `TraceCutFaceFragmentCountMismatch`, source face **`(0,1,102)`** = mesh row 259 |
| **Red set** | 366, 367, 368, 369, 370, 371, 372, 374 |
| **Stable accounting** | **44 events / 14 categories / 30 recurrences** |
| **Produced-witness debt** | **5** |
| **Semantic M3 package count** | **84** |

---

## 2. The current frontier — measured, adjudicated, correction authorized

Ordinal 366 fails at `src/geometry/GlobalTopologyPlan.cpp:777–779`, the sole emitter of
`TraceCutFaceFragmentCountMismatch`, which tests `fragmentOrbits[face].size() != tracePieceCount[face] + 1`.

**TB18 measured the deciding values** through CB20's diagnostic projection. On face `(0,1,102)`:

- one real chord is retained — `trace=1`, `arc=15`, `segment=4`, `orientation=Forward`;
- `incomingCarrier=none`, `outgoingCarrier=0-102`;
- **both** oriented chord sides map to global orbit id `0`;
- neither side is dropped by `exteriorOrbits`;
- each of the face's three edge-evidence rows contains only orbit `0`;
- consequently `fragmentOrbits.size() == 1` while `tracePieceCount + 1 == 2` — **actual 1 / k 1 / expected 2**, low
  by exactly one, `fragmentIncidenceCount = 1`, untruncated.

Exterior filtering and both high-side mechanisms are eliminated for this witness; **shared global orbit ownership**
is selected.

**`M3-CP4c-3-TB18-REV` adjudicated it under BT0–BT9**
(`Architecture_M3_CP4c3_TB18_Independent_Review_Record.md`):

- **The incidence is a vertex transit through a regular vertex.** Segment 4 is not segment 0, so it is not the
  trace's port origin — it is one of CB19's 48 vertex transits. The carrier-less branch binds the corner opposite
  the outgoing carrier, which for `0-102` is **vertex 1**: degree 6, angle defect 0, two 90° sharp edges. The chord
  runs corner-to-opposite-edge and separates the triangle **locally**.
- **Shared ownership is legitimate, not a merge defect.** The face walk is the canonical rotation-system face
  permutation, validated total; its orbits are its cycles, so it cannot fuse darts a valid rotation system
  separates. Two darts of one arc share an orbit exactly when the arc is a bridge or is non-separating — both
  legitimate. **`|owners| = k+1` is therefore not an invariant of any valid input;** the sound relation is
  `|owners| ≤ localFragmentCount`.
- **The correction is safe by construction.** The validation loop is pure — it returns a failure or falls through,
  mutating nothing. `size > expected` holds on a strict subset of `size != expected`, so the failing set only
  shrinks and every previously-passing input is byte-identical. 1–365 are 365/365, so the accepted boundary cannot
  move. Downstream, `fragmentOrbits[face]` registers face-to-region membership only, which is correct under shared
  ownership.
- **BS9-5 is RETIRED.** The missing `fragment_reconciliation` line is explained: it sits behind
  `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS`, which the artifact-only runner never sets, and it prints exactly the
  three values BS1 already retained. The measure asked for a text duplicate of typed evidence. Nothing is owed;
  BS4 is closed as correctly implemented.

A local count tweak, a special case for `(0,1,102)`, disabling deduplication, or changing exterior filtering
remains unauthorized.

---

## 3. Exact next turn — `M3-CP4c-3-CB21`, product correction, `BU0–BU9`

Full text in §11 of `Architecture_M3_CP4c3_TB18_Independent_Review_Record.md`. In brief:

- **BU0** — accepted 365 untouched; selector **383 byte-frozen** and republished unchanged; eight standard compile
  targets with **mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BU1** — **the only semantic change:** `found->second.size() != expected` becomes
  `found->second.size() > expected`. The high side stays fatal with its full CB20 evidence payload.
- **BU2** — retain the low-side deficit and the shared-owner chords as evidence, never as a failure.
- **BU3** — compute the local fragment count **locally** and retain it, **non-fatal**; retain chord-crossing
  evidence.
- **BU4** — publish the bridge / orbit census: per arc whether its two darts share an orbit, per trace whether it
  ends in a terminal slit, and the global total / exterior / non-exterior orbit counts.
- **BU5** — one witness per new field through the production path, a witness that one chord with one shared owner
  now passes, and a byte-identical high-side regression witness.
- **BU6** — append selector **384** with only the BU5 identities; 383 stays an exact prefix.
- **BU7** — **prohibited:** any change to `tracePieceCount`, `add_fragment_orbit`, the `exteriorOrbits` filter,
  `is_terminal_slit`, `resolve_carrierless_corner_binding`, `build_fragment_corner_incidence`, the face walk, the
  rotation system or region drafts; any new fatal condition; any revert of CB12–CB20. **BS9-5 is retired — do not
  restore it.**
- **BU8** — audit by assumption; reproduce the safety proof against the actual diff.
- **BU9** — six `M3-CP4c-3-TB19` discriminators, chiefly: 1–365 stay 365/365; **ordinal 366 no longer reds at
  `TraceCutFaceFragmentCountMismatch`** and must move to a different site; 367/371/372 move with it; the deficit at
  `(0,1,102)` is 1; the orbit census is published.

**No further diagnostic-only turn is authorized on this surface.** The successor after TB19 is an independent
`M3-CP4c-3-TB19-REV`, which owns promotion of the local-fragment assertion to fatal.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB17-CAND-01` | **ACTIVE / GATING** — owner **proved** at TB18-REV (the equality itself, in `build_regions`); correction authorized under BU1–BU2. Closes when TB19 shows ordinal 366 past this site. |
| `M3-CP4c3-TB18-REV-CAND-01` | **NEW / ACTIVE / EVIDENCE** — the sound local-fragment invariant is unproved: `k+1` local fragments holds only if no two chords cross inside a face. Owner: BU3 evidence, then TB19-REV. |
| `M3-CP4c3-TB10-REV-CAND-01` | **ACTIVE / TEST-COUPLING / DEFERRED** — ordinals 371/372 blocked by a shared fixture precondition, not their own contracts; both co-reach the fragment mismatch and should move with it. |
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

- **The face walk is a validated total permutation; its orbits are its cycles.** Shared orbit ownership by the two
  sides of one arc is legitimate topology, not a merge defect.
- **BS9-5 is retired.** Its missing record was an environment-gated text duplicate of retained typed fields.
- **The accepted boundary cannot move under BU1** — proved by construction, not argued.
- **CB19's results:** the `(9,11,17)` `RegionTraceSourcePortCarrierNotAdmissible` stop is cleared; **48** non-first
  carrier-less segments exist and **all 48** have entry support distinct from the trace origin; the positive witness
  uses `SegmentEntrySupport`; there are **10** terminal slits; the retained terminal witness has
  `realChordContribution = 0`.
- **Terminal slits contribute zero to `k`** and publish no orbit evidence — consistently excluded from both sides
  of the fragment comparison.
- **CB12 / CB14 / CB15 / CB16 / CB17 / CB18 / CB19 / CB20 corrections stand.** No successor may revert them.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first.
2. **this file** — current state, frozen successor, candidate index.
3. `Architecture_M3_CP4c3_TB18_Independent_Review_Record.md` — the frozen **CB21** scope, §11 BU0–BU9.
4. `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Report.md` — current immutable runtime authority.
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
