# Architecture Review Decision — `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE-REV`

**Date:** 2026-10-15 · **Reviewer turn:** `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE-REV`
**Adjudicates:** `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` (commits `83b74252f`, `4c114b248`,
`5be5e123e`, `243a9feb7`, `b0dc97e86`, `cdb8b5bb4`, `a7eca7372`, `44fd97fc6`, `3d4b13292`)
**Subject record:** `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Code_Build_Record_20261015.md`
**Verdict:** **ACCEPTED.** One silent mandate deviation charged and recoverable. No open
REVIEW_BLOCKER. No promotion, no stable event, no regression recurrence, no gate credit.

---

## RA-66.1 — the compile chain is closed by bytes, end to end

Nothing here is taken on report.

- **Snapshot** run `38775481890` (`Agent Source Snapshot`) `success`, `headSha 4c114b248…` — the pin
  commit. Artifact `11993616345` present at 24,114,547 bytes.
- **Compile** run `38776964197` (`Agent Durable Operation Dispatcher`) `success`,
  `headSha 243a9feb7…` — the dispatcher request commit. Result artifact `11994726341` present at
  39,026,791 bytes.
- **ZIP SHA-256 recomputed on the downloaded bytes:**
  `b59dc16f4417693c4aec79025160da2054cfbca3a1589ef051ee3a171d3185bb` — **identical to the reported
  value**.
- **Manifest re-verified, not read:** `shasum -a 256 -c SHA256SUMS` over the extracted package gives
  **28 entries, 28 OK, 0 BAD**, matching the claimed 28/28.
- **Eight targets**, exactly as claimed: `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, `directional_benchmarks`.
- `preflight-exit-code.txt` = **0**, `build-exit-code.txt` = **0**; package records
  `exactArithmeticBackend=GMP` and `runtimeExecution=false`; `source-commit.txt` =
  `5be5e123e14e2ddab8bb8c0db2a354a0a900435a`.
- **The decisive link.** `src/geometry/SurfaceCellTracing.cpp` *inside the manifest-verified package*
  hashes to `3833d8f4e204f6c202b1e9faa9b3e88da5c1e30a81ccd2b11f24d31408c3f91f`, which is
  **byte-identical to HEAD's**. The `src` tree is `fd09300ba38b10dfea728c8c3f7c4ed6b732c89c` at both
  the semantic source `5be5e123e` and HEAD, and `5be5e123e`'s parent is the pin commit `4c114b248`.

The package therefore contains exactly the probe code that is in the branch, with no gap anywhere in
the chain from pin to artifact.

`include`, `tests`, `benchmarks`, `cmake`, `.github` and every selector are **untouched**. No
Directional binary, test, benchmark or frozen-497 selector was executed.

## RA-66.2 — decision-neutral by construction, verified structurally rather than asserted

The 23 added lines sit at `:19439-19461`, inside the block opened at
`:19360 if (!firstEndpoint || !secondEndpoint) {`, immediately after the pre-existing
`:19438 const auto *probeCarrier = find_carrier(endpointEdge);`. Every added line either declares a
local (`append_face_key`, the two scoped `face` bindings) or streams into `endpointEvidence`. No
acceptance path can observe any of it, because the block is only entered once both certificates have
already returned. The ladder, the predicates, `endpoint_certificate` itself and every rejection string
are unchanged.

## RA-66.3 — the turn improved on the mandate, in the right direction

The mandate asked for raw face rows. The turn emitted the raw rows **and** the canonical attachment
keys — `a2bProbeFromAttachment` and `a2bProbeToAttachment`, each a three-vertex
`SourceFaceTopologyKey` triple — alongside `a2bProbeCarrierFirstFace` and
`a2bProbeCarrierSecondFace`.

That is better than what was asked, because `oriented_carrier` (`:19106-19114`) compares
`record.firstFace == from && record.secondFace == to` on exactly these keys. The failing comparison is
now observable **field against field**, with no row→key re-derivation needed at review time and no
opportunity for the reviewer to supply the missing half from imagination. Given RA-65.3, that is the
correct instinct.

## RA-66.4 (DEFECT, recoverable) — a mandated field is absent and the omission is unacknowledged

`a2bProbeCarrierEdge` was item 3 of five. `grep -c a2bProbeCarrierEdge src/geometry/SurfaceCellTracing.cpp`
returns **0**. Neither the record nor the handoff notes the deviation; the record lists its six fields
as though six were what was asked.

**The information is not lost.** `SourceFaceTopologyKey::vertices()` returns
`std::array<SourceVertexId, 3>` (`include/directional/authority/AuthorityIds.h:442`), and the carrier
edge is the two-element **intersection** of the `CarrierFirstFace` and `CarrierSecondFace` triples.
The substantive loss is nil; the **silence** is the defect. The Test + Benchmark successor must compute
the intersection and state that it computed it rather than printing a carrier edge as though it had
been emitted.

## RA-66.5 — a new dereference, raised and discharged

The probe adds `network.sourceTopologyRegions->topology_for_row(...)`, which the RA-63 probe did not
contain. The enclosing function already dereferences that pointer unguarded at `:18967`, `:18968`,
`:19048`, `:19050`, `:19076`, `:19136`, `:19138`, `:19154` and `:19196` — and `:19076` lies on every
path that reaches the probe. **No new crash surface.**

One divergence from the real path exists and it is an improvement: `:19134` requires **both** source
faces to resolve before either is dereferenced, whereas the probe guards each independently. A case in
which exactly one face resolves now reports the half that does, instead of reporting nothing.

## RA-66.6 — the bounds idiom matches the surrounding code, and that idiom is unguarded

`topology_for_row` is not bounds-safe; elsewhere callers test `face_count()` first (`:8941`). The probe
bounds its row through `source_face_id(point.face, faces.rows())`, exactly as `:19130-19133` does —
`faces.rows()`, not `sourceTopologyRegions->face_count()`. The probe therefore introduces **no new
hazard**, but the pre-existing asymmetry between the two extents is recorded as a backlog locus. It is
not this rung's work and must not be repaired opportunistically.

## RA-66.7 — what the measurement will decide, and what it will not

The emitted set decides the **first-order partition** directly and without inference: whether neither,
exactly one, or both of `FromAttachment`/`ToAttachment` lie in
`{CarrierFirstFace, CarrierSecondFace}`, and if both, whether they are swapped. That is enough to say
where the mismatch sits.

It does **not** by itself decide the sector refinement RA-65.11 named, because the rail's *other*
incident edges at the shared vertex are not emitted. For these 21 identities the rail edge set is
byte-fixed in `tests/SurfaceCellsPhase10Tests.cpp:223-264`, so the refinement is derivable from
repository bytes — but the derivation must be **exhibited from those bytes**, not asserted. Asserting
a sector from a consistent reading is precisely RA-65.4 one level down.

## RA-66.8 — the previous charge was absorbed in the turn's own words

Record line 7 reads "5642 source files (**file count, not a checksum-verification ratio**)". RA-65.1
charged exactly that misdescription one rung earlier, and the correction appears unprompted inside the
new turn's own evidence line rather than in a reply. That is the shortest possible loop from charge to
uptake.

## RA-66.9 — documents

The handoff was **prepended**: two new sections sit above the RA-65 section, which is intact below,
and the top section states that the one beneath it is "preserved as historic pending state." Two
CURRENT sections for a single turn — a pending one and a completion one — is a readability cost rather
than a defect, since the supersession is declared in text. `TODO.md` was likewise prepended. The three
commits sharing the message "close endpoint chart compile checkpoint with verified GMP evidence" touch
**three different files** (record, handoff, `TODO.md`), so this is not the RA-64.9 retry pattern.

## RA-66.10 — beacon

`Status: COMPLETE`, six fields, `Ended at:` populated, `Successor: UNKNOWN` **with reasoning carried in
the record** — *"Next artifact-only probe execution and independent Review require separate
authorization; there is no authorized named successor at closeout"* — and reinforced in the handoff
(*"do not invent a successor"*). The RA-63.13 shape. **No defect.**

## RA-66.11 — `R4-VIN-01` re-arms, and the old harness must not be pointed at the new fields

`5be5e123e` is a **new semantic source** and `11994726341` a **new package**. Artifacts `11976790988`
and `11967601999` are now baselines, never comparands. The 44 RED remain the baseline **for
`16c3134c0`**; nothing measured against the new package may be differenced against them without
re-establishing the selector view first.

The record states this hazard about its own instrument before being asked: the pinned 44-case harness
**pins the old immutable package** and "must not be run against it to claim these new fields."
Correct, and load-bearing — a harness that silently measured the old package would report every new
field as absent and look like a clean negative.

## RA-66 — accounting

Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried
CP2 losses), frozen selector **30+12+449+6 = 497** — unchanged. No accepted-green loss, no ledger
credit, no promotion, no stable event, no regression recurrence, no 497 execution, no gate credit.
PR #8 draft/open.

`RP-01` located, three expressions, **one in question pending this measurement** — not repaired.
`RP-02` **UNREACHED**. `RP-03` satisfied a third consecutive turn. `PROCESS-01` discharged.
**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED (RA-65.5).**

Both gates run and reported: `review_check.py boundary` → ALL CHECKS PASSED;
`review_check.py ledgers --base ec7670973` → ALL CHECKS PASSED.

Successor: **`M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST`**.
