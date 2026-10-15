# RA-67 — `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` Review Decision

**Turn reviewed:** `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` (artifact-only Test + Benchmark)
**Verdict:** **ACCEPTED.** One latent instrument defect recorded, verified harmless for this
measurement. One reporting omission. No open REVIEW_BLOCKER. No promotion, no stable event, no
regression recurrence, no gate credit.
**Date:** 2026-10-15

Everything below was re-derived from repository bytes and immutable artifacts. Nothing is accepted on
the turn's report.

---

## RA-67.1 — The result package is closed by bytes

Run [38782417387](https://github.com/akashskypatel/Directional/actions/runs/38782417387) `success`,
`headSha 8e8cf1cfa` (the dispatch commit). Result artifact `11996317553`, 80,281 bytes. **The ZIP
SHA-256 was recomputed on the downloaded bytes —
`44df6e2fc1bdba1e15f81e11ddec7bbb6cc90e2d43adcda4f334d875d1dbd9c9` — and matches both the provider
digest and the report.** The manifest was **re-verified rather than read**: `shasum -a 256 -c
SHA256SUMS` over the extracted archive returns **51 OK, 0 BAD** across 52 files.

`execution-boundary.txt`: `artifact_id=11994726341`, `source_sha=5be5e123e…`, `planned=44`,
`executed=44`, `red=44`, `missing=0`, `postflight=true`, `compile=false`, `relink=false`,
`benchmarks=false`, `selector497=false`, `exit=0`. `ledger.tsv` carries **44 RED**, no
`NOT_SELECTED`, no `NOT_EXECUTED`. `manifest-before.txt` and `manifest-after.txt` are **byte-identical
at 28 OK each**, so the immutable package was not mutated across execution.

One precision about the boundary file: `planned=44` is a **literal** in the `finish` printf
(`m6_cp3_r4_endpoint_chart_harvest_harness.sh:11`), not the computed counter. It is nevertheless
true, because `:120` asserts `[[ "$planned" == 44 ]] || die` and the recorded `exit=0` can only be
reached past that assertion. A reader must therefore read `exit` before `planned`; on a die the file
would still print `planned=44`. Recorded as an instrument note, not a defect.

## RA-67.2 — The harness pins the new package, and the old harness was not reused

Harness SHA-256 independently recomputed as
`5b13f121bd678ec975e9c4d00df3685e79893eff8f7f9f42f980402b9b955fab`, identical to the value pinned in
`agent-dispatch-request.json` and reported. It pins artifact **`11994726341`** and source
`5be5e123e…` (`:17-21`, `:27`); artifact `11976790988` does not appear anywhere in the file. The
RA-66.11 hazard was therefore avoided in fact, not only in words.

RA-61-standard pinning is intact and fail-closed throughout: provider digest (`:19`), recomputed ZIP
digest (`:21`), manifest hash and 28-count (`:24-26`), source identity (`:27`), `GMP` /
`runtimeExecution=false` (`:28-29`), packaged source archive hash (`:31`), four frozen selector
hashes (`:33-39`), three before/after byte inventories with `cmp` (`:40-44`, `:199-204`), postflight
manifest (`:205`), and a closing `executed==44 && missing==0 && postflight` assertion (`:209`). The
census inventory is pinned by SHA with a duplicate assertion (`:45-51`); I re-verified its hash
(`de05a7bd…`), its 39 rows and its single ordinal `405`, giving 38 + 6 = 44.

**The harness never asserts the verdict.** `red` is counted, never required. The population is
fail-closed; the outcome is not. That is the correct shape for a measuring instrument and is recorded
as credit.

The two `SurfaceCellTracingPhase14` identities are **not** bundled: `Phase14` appears once in the
harness, in the comment at `:83-84` declaring them deliberately out of scope, and zero times in the
ledger.

## RA-67.3 — The partition table re-derived independently, and it holds

I re-derived the table from `endpoint-chart-harvest.tsv` without reference to `chart-summary.txt` or
the report, grouping on the full tuple of condition, both face rows, both attachment keys, both
carrier keys, the computed edge, membership, swap and verdict. **Exactly three distinct tuples exist,
with counts 23 / 15 / 6, all `RED`, all `COMPLETE`:**

| n | first failure | rows | attachments | carrier pair | edge | membership |
|---:|---|---|---|---|---|---|
| 23 | `not-same-interior-carrier-point` | 0 → 3 | (0,1,4) → (1,4,5) | (0,1,4)/(1,4,5) | (1,4) | **both**, not swapped |
| 15 | `carrier-orientation` | 0 → 7 | (0,1,4) → (4,7,8) | (0,1,4)/(1,4,5) | (1,4) | **one** (the *from*) |
| 6 | `carrier-orientation` | 0 → 7 | (0,1,2) → (2,6,8) | (0,1,2)/(1,2,5) | (1,2) | **one** (the *from*) |

The uniformity the report presents is real: every one of the 15 and every one of the 6 is identical
in all measured fields. The intersections check by hand — `(0,1,4) ∩ (1,4,5) = {1,4}` and
`(0,1,2) ∩ (1,2,5) = {1,2}` — and membership is exact key equality, never a row comparison. The
first-order partition RA-66.7 scoped is therefore **settled: 21/21 exactly one, always the *from*
attachment; zero neither, zero both, zero swapped, zero missing keys.**

## RA-67.4 — RA-66.4 is discharged in the right way

The carrier edge is computed by a genuine two-element set intersection
(`:172 edge = sorted(set(c) & set(d))`), guarded on cardinality exactly two (`:173`), and the
instrument **says in its own output** that the value is derived: `chart-summary.txt` line 1 reads
`carrier_edge_derivation=two-element set intersection of CarrierFirstFace and CarrierSecondFace
canonical vertex triples; not an emitted field`. The report repeats it at its line 19. No edge is
printed as though the probe had emitted one. The evidence is fail-closed: any `carrier-orientation`
case with an unresolvable key or a missing face row appends to `missing` and raises `SystemExit`
(`:181-182`, `:196-197`), so "zero missing keys" is enforced rather than asserted.

## RA-67.5 (NEW) — The two junction groups are one phenomenon in two vertex-index domains

The report prints the 15 and the 6 as two rows of one table, with plain integer triples and no domain
column. They are not two findings. They are **the same measurement under two different vertex
labellings**, and the relabelling is recoverable exactly.

`make_disconnected_rectangular_feature_pair_mesh` (`tests/SurfaceCellsPhase10Tests.cpp:223-263`)
builds two disconnected 3×3 grids. For a component at vertex offset `k` the face rows are emitted in
this order:

```
f0=(k+0,k+1,k+4)  f1=(k+0,k+4,k+3)  f2=(k+1,k+2,k+5)  f3=(k+1,k+5,k+4)
f4=(k+3,k+4,k+7)  f5=(k+3,k+7,k+6)  f6=(k+4,k+5,k+8)  f7=(k+4,k+8,k+7)
```

Canonically sorted, component 0 gives `f0=(0,1,4)`, `f3=(1,4,5)`, `f7=(4,7,8)` — **exactly the
Junction-A keys.** Component 1 gives `(9,10,13)`, `(10,13,14)`, `(13,16,17)` — not the Junction-B
keys either. But relabel the component's vertices by **order of first appearance in its face list** —
`0,1,4,3,2,5,7,6,8 → 0,1,2,3,4,5,6,7,8`, i.e. `4→2`, `2→4`, `7→6`, `6→7` — and:

| component-local face | global key | compacted key | measured as |
|---|---|---|---|
| f0 | (0,1,4) | **(0,1,2)** | `CarrierFirstFace`, `FromAttachment` |
| f3 | (1,4,5) | **(1,2,5)** | `CarrierSecondFace` |
| f7 | (4,7,8) | **(2,6,8)** | `ToAttachment` |

Six independent confirmations of one mapping: three face keys, the carrier edge (`(1,4) → (1,2)`,
matching the measured Junction-B edge), and both source-terminal vertices (`4 → 2`, matching the
measured `fromV=2, toV=2` against Junction A's `fromV=4, toV=4`). The face **rows** `0 → 7` coincide
across both groups because the compaction relabels vertices and leaves face order untouched.

**Consequence.** The 21 junction identities are a single uniform phenomenon, observed twice in two
index domains, and the apparent two-row structure of the table is an artifact of vertex relabelling.
The report's framing is not wrong per identity — membership is computed inside a row and is therefore
domain-consistent — but the sentence treating `0 → 7` as one measured fact spans two domains, and the
table offers no column that would let a reader notice. **A probe that prints a `SourceVertexId`
without naming its domain makes one object look like two.** That is `RP-01
AUTHORITY_DOMAIN_CONFLATION` reproducing itself inside the instrument built to measure it.

## RA-67.6 (DECISIVE) — The mechanism, exhibited from bytes line by line

RA-65.11 asked which rail sector owns the endpoint and RA-66.7 ruled that the answer must be
exhibited from the fixture's bytes, never asserted. It can now be exhibited, and it does not require
a sector.

1. The fixture declares **two** hard edges per component, and they **share a vertex**:
   `add_rectangular_midline_hard_feature` (`tests/SurfaceCellsPhase10Tests.cpp:266-273`) inserts
   `{offset+1, offset+4}` and `{offset+4, offset+7}`. In component-local terms: edge **(1,4)** and
   edge **(4,7)**, meeting at vertex **4**.
2. From the face table above, edge **(1,4)** lies in faces **{0, 3}** (`f0=(0,1,4)`, `f3=(1,4,5)`),
   and edge **(4,7)** lies in faces **{4, 7}** (`f4=(3,4,7)`, `f7=(4,7,8)`).
3. The measurement puts the front edge's two endpoints at **face 0 and face 7** — one face of the
   first hard edge and one face of the **second**. Both endpoints sit at vertex 4
   (`fromV=4, toV=4`), the vertex the two hard edges share.
4. A carrier record is **edge-keyed by construction**: `SurfaceHardRailFieldTransition`
   (`include/directional/geometry/SurfaceCellTracing.h:1482-1489`) holds one
   `SourceEdgeTopologyKey` and exactly two `SourceFaceTopologyKey`s — the two faces of **that one
   edge**.
5. `oriented_carrier` (`src/geometry/SurfaceCellTracing.cpp:19106-19114`) returns a record only when
   `{record.firstFace, record.secondFace}` equals `{from, to}` in one order or the other.

Therefore: **when a front edge's two endpoint faces are drawn from two different hard edges, no
carrier record can contain both, and `oriented_carrier` cannot match in either orientation.** The
refusal is structural, not numerical, and not a tolerance. Every premise is a repository byte; the
only measured input is the endpoint face pair, which the harvest supplies.

This is `RP-01`'s third expression, no longer merely located but **demonstrated**: an edge-keyed
authority is being asked a question that is about a vertex. It is also why **gate C stays suspended**
rather than being revived — the measurement confirms the *shape* gate C was reaching for (both
endpoints at one source vertex, 15× at v4 and 6× at the same vertex relabelled v2), and changes
nothing about RA-65.5, because a witness with no producer remains unimplementable. Confirming that a
witness would be apt is not the same as finding its publisher.

**What this does not establish.** It does not say what the repair is. Two shapes are admissible on
the face of it — the A4 publisher splitting a front edge at a junction vertex so each piece has one
carrier, or the consumer predicate becoming vertex-aware — and they differ in which authority gains a
new obligation. Choosing between them is a definition question, not a measurement, and no code is
authorized by this decision.

## RA-67.7 — The row pair `{0,7}` does not vindicate the withdrawn RA-64.6

The rows I invented at RA-64.4 and withdrew at RA-65.3 appear in the measurement. **The withdrawal
stands and the inference is not rehabilitated.** Three reasons, each from the data above: the same
row pair arises in two different index domains (RA-67.5), so it is not one object; the rows are the
*least* informative field measured, since the predicate compares keys and never rows; and RA-64.6's
actual claim was that a publisher had **truncated a route**, which nothing here shows — the
publisher cannot shorten a route at all, only reject (established from
`assign_open_front_boundary_authority`, `:12481-12692`). A number that happens to coincide is exactly
what **RA-65.4** warns about, and the coincidence is evidence for that lesson, not against it.
**RA-64.6 remains withdrawn, final.**

## RA-67.8 (DEFECT, latent — verified harmless here) — the first-match probe parse

The harvester extracts each field with `re.search(name + r'=([^;\r\n"]+)')` over the whole log
(`:164`), which takes the **first** emission and records no occurrence count. The probe fires once
per rejected edge, so a test that rejects several edges contributes only its first chart, silently.

I checked rather than assumed. Two of the 44 raw logs — `27.log` and `41.log` — emit the probe
**three** times; the other 42 emit it once. In both multi-emission logs all three emissions are
**byte-identical** in every field, and both belong to the interior-shaped 23, so none of the 21
junction rows is affected and nothing in RA-67.3 changes. The loss is nil for this measurement; the
**narrowing is undisclosed**, and a future divergent case would be hidden the same way while the run
still looked clean. Remedy for the successor instrument: record the per-log emission count in the
TSV and assert uniformity, or emit one row per emission.

## RA-67.9 — Harvested but unanalyzed, and it confirms a struck conjunct

The TSV carries eight interval fields the report never discusses. They are uniform per group: both
intervals present in all 44; `FirstSpan == SecondSpan` in all 44 (span 3 for the 23 and the 15, span
2 for the 6); and the ordinal pairs are **reciprocal and reversed** — `(0/1, 1/1)` against
`(1/1, 0/1)` for the 23, `(3/1, 4/1)` against `(4/1, 3/1)` for the 21.

That is **RA-65.6a measured**. I struck the reciprocal-ordinal conjunct from the gate A specification
on the argument that reciprocity is a construction identity of `append_arc`
(`src/geometry/SurfaceCellTracing.cpp:17043-17107`, ordinals minted as `ordinal` and `ordinal + 1`).
The harvest shows it holding for all 44 cases **including every one of the 44 RED** — a conjunct that
is satisfied by every rejected case cannot discriminate, which is what vacuous means. The strike is
confirmed by measurement, not only by argument. The integer ordinals also re-confirm the RA-65.7
locus: the published object is the **index**, never the parameter.

Charged lightly against the turn as **under-reporting**: the fields were harvested voluntarily, which
is good, and then left unexamined, which left a confirmation on the floor.

## RA-67.10 — The long-file mutation was verified against an immutable pre-image

The closeout did something new and right. Rather than editing a 13,512-line protected document on
trust, the turn took an exact source snapshot first — run
[38805395498](https://github.com/akashskypatel/Directional/actions/runs/38805395498) `success` at
`393d6c548`, artifact `12005034654` — and patched against it.

I re-verified the whole chain. The outer ZIP SHA-256 recomputed on the downloaded bytes is
`09a865c0e7b6398a2b1dcc6cc3ed839449dd1de0486e81dfb56b2bc6d759e96e`, matching the provider digest; the
inner `source.tar.gz` hashes to `adbc497359822d338a2831aade5e752a70907455f48932accb0783440fbd0225`,
matching both its sidecar and `snapshot-metadata.json`; and `shasum -a 256 -c SHA256SUMS` over the
extracted source tree returns **5,647 OK, 0 BAD**.

**This is the RA-65.1 defect structurally eliminated, not merely reworded.** At RA-65 the evidence
line said "5640/5640 source hashes" when the snapshot recorded only `snapshot_file_count` and
verified nothing; at RA-66 the wording was corrected in the turn's own words; here the snapshot
package **contains a 5,647-line per-file manifest** and the ratio is a real checksum verification. A
provenance charge answered first in language and then in the instrument is the best available
outcome, and it is recorded as credit.

The preservation claim itself also verifies. The snapshot's pre-image of the tracker is **exactly
13,512 lines** — the floor on record — HEAD's is **13,524**, the diff is **+12 / −0**, and the
trailing 13,512 lines of HEAD are **byte-identical** to the pre-image. Append-only is proven against
an immutable artifact rather than asserted.

## RA-67.11 — Beacon and documents

The beacon closed correctly: `Status: COMPLETE`, all six fields, `Resumed at:` and `Ended at:`
populated, `Successor: UNKNOWN` **with reasoning carried in both the handoff and `TODO.md`** — the
RA-63.13 shape, **no defect**. The self-referential `Successor` that stood while the turn was
`IN_PROGRESS` was removed at closeout and never appeared on a `COMPLETE` beacon, so **RA-64.10 is not
charged**; it is noted only because a continuation beacon that names itself cannot be distinguished
from a stalled one, and the next long turn should write `Successor:` empty rather than self-naming
while in progress.

All four documents the turn touched are **pure insertions, zero deletions**, prepended with prior
sections intact: tracker +12, handoff +8, root `CHANGELOG.md` +7, `.agents/Directional/CHANGELOG.md`
+4. Floors clear before this Review's own prepends: tracker 13,524 lines / 656 `## ` / 13 marker
occurrences; handoff 4,601 / 310; root changelog 1,854 / 237.

## RA-67.12 — Prohibitions honored, accounting unchanged

No C++, no compile, no relink, no new semantic source, no selector change, no 497, no benchmark, no
fixture change — `src`, `include`, `tests`, `benchmarks`, `cmake`, `.github` and every selector are
untouched across the whole turn. No sector, mechanism, repair or root cause was asserted by the turn:
the report states at its line 29 that the measurement "does **not** establish which upstream rail
segment, front sector, or publisher continuation should own the endpoint", and
`chart-summary.txt` records `sector_classification=NOT_INFERRED`. Ordinal 405 excluded with its
reason. `R4-VIN-01` correctly recorded as **candidate / non-stable** — the 44 RED are the baseline
for `16c3134c0` alone, and `5be5e123e` is a new semantic source, so `11976790988` and `11967601999`
stay **baselines, never comparands**.

Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected, frozen selector
**30+12+449+6 = 497** — unchanged. No ledger credit, no promotion, no stable event, no regression
recurrence, no gate credit. `RP-01` **measured and mechanistically derived (RA-67.6), code still
unauthorized**; `RP-02` **UNREACHED**; `RP-03` satisfied a **fourth** consecutive turn; `PROCESS-01`
discharged. **RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED (RA-65.5).**

## RA-67.13 (LESSON) — Two labels for one object are not two observations

An identifier printed without its domain turns one phenomenon into two rows of a table, and the
duplicate then reads as corroboration. The 21 junction identities looked like two groups with
different keys and different carrier edges; they are one group seen twice. A measurement must name
the index domain of every identifier it prints, or it manufactures the appearance of independent
confirmation — the failure the instrument was built to detect, committed by the instrument.

## Disposition

`M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` — **ACCEPTED**. Successor:
**`M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC`**, a definition turn, no code.
