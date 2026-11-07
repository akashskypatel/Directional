# Architecture Review Decision — M6 CP3 R7 pre-snap lattice-UV candidates (rungs 14 and 15)

**Review turn:** `M6-CP3-R7-LATTICE-UV-CANDIDATE-REV`
**Adjudicated:** `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` (rung 14) and
`M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` (rung 15)
**Frozen amendment:** RA-74
**Verdicts:** both **ACCEPTED**. The measurement **exonerates the face selector entirely** and
relocates `RP-01` to a wholesale, unreconciled point substitution. One **hard** charge on
append-only ledger destruction, two lesser.
**Review window:** 2026-10-16T07:05:18Z — 2026-10-16T07:58:40Z
**Semantic source:** `cdd6dc4a9ba95a42aace6226194b38e712b53e4b` (new — `R4-VIN-01` re-arms)

---

## RA-74.1 THE RESULT — the sampler is innocent; the point is replaced after it

Measured, then confirmed in the bytes. At
`src/geometry/SurfaceCellTracing.cpp:17256-17281`, inside the **bounded-disk** producer:

```cpp
if (!point_on_periodic_chart(chartTriangles, uv, faces.rows(),
        points[node_index(u, v)])) { /* reject */ }
const int sampledFace = points[node_index(u, v)].face;      // probe-added
if (useAcceptedConformity) {
  const SurfaceTracePoint *accepted = nullptr;
  if (v == 0)                 accepted = &acceptedBoundary[0].points[u];
  else if (u == result.gridU) accepted = &acceptedBoundary[1].points[v];
  else if (v == result.gridV) accepted = &acceptedBoundary[2].points[gridU - u];
  else if (u == 0)            accepted = &acceptedBoundary[3].points[gridV - v];
  if (accepted != nullptr) {
    points[node_index(u, v)] = *accepted;                   // WHOLESALE REPLACEMENT
  }
}
```

When the node lies on the bounded-disk **grid boundary**, the sampled `SurfaceTracePoint` is
**replaced in its entirety** by the accepted-conformity boundary point — a different point
with its own `face` and `barycentric`. There is **no face-admissibility check, no
source-entity comparison, and no agreement test against the chart sample.**

**Production does not even retain the discarded value.** `grep -n sampledFace` returns
exactly two lines — `:17264`, its declaration, and `:17305`, the probe's own emission — and
both were **added by the CB7 probe** (`git show cdd6dc4a9 | grep sampledFace` shows them as
`+` lines). Before this rung, the chart sample's face left no trace anywhere.

## RA-74.2 The measurement, re-derived

Result artifact `12030150301`, ZIP SHA-256 **recomputed** `de79aed888a2…`, matching the
provider digest; internal manifest **51 OK / 0 BAD**;
`planned=44 executed=44 red=44 missing=0 postflight=true exit=0`,
`compile=false relink=false benchmarks=false selector497=false`. Re-derived independently
from `producer-presnap-candidates.tsv` — 96 rows, 0 errors, four categories:

| n | condition | endpoint | producer | sampled | published | published_is_min |
|---:|---|---|---|---:|---:|---|
| 21 | `carrier-orientation` | FirstTo | bounded-disk | 0 | 0 | **true** |
| 21 | `carrier-orientation` | SecondFrom | bounded-disk | **3** | **7** | **false** |
| 27 | `not-same-interior-carrier-point` | FirstTo | none | — | — | not measured |
| 27 | `not-same-interior-carrier-point` | SecondFrom | none | — | — | not measured |

The harness's own summary records `sampled-min` for **both** junction categories. So in all
21 `SecondFrom` endpoints the sampler chose **3, the minimum passing candidate**, and
publication reports **7**.

## RA-74.3 What this settles, and what it overturns

- **RA-72.6 is CONFIRMED at the producer's own sample point** — `sampled_is_min` is true in
  all 21. The minimum-row rule holds. It is also now **irrelevant to the defect**, because
  the sample is discarded.
- **RA-73.5 is SUPERSEDED.** The "published the largest" framing described a *selection*
  asymmetry. There is none: it is a **sample/publication substitution**. The clause stands
  as a correct observation of published values and a wrong account of their cause.
- **RA-71.5 is AMENDED.** It named the planar `point_on_source` in
  `build_uniform_phase_front_for_faces` as the locus. The measured endpoints come from the
  **bounded-disk** producer via `point_on_periodic_chart`. `point_on_source` is **exonerated
  for these cells**.
- **My RA-73.6 charge is vindicated.** Sampling at the producer's own point rather than the
  published one changed the answer and relocated the locus. That is exactly what RA-73.10
  predicted would be at stake.

## RA-74.4 The pattern, now in its strongest form

RA-68.3: the junction certificate existed but was **ordered after** the admission it would
authorize. RA-71.7: the corner/path reconciler existed but compared **position** where
identity was required. **RA-74.4: here no reconciliation exists at all** — one authority's
output is overwritten by another's, and the overwritten value is not even held in a
variable. The progression is worth freezing as a search order: *ordered too late → present
but comparing the wrong thing → absent entirely.*

## RA-74.5 Rung 14 honoured the constraint it was given

RA-73.7 established that the producer's lattice UV is not reconstructible downstream because
`UniformPhaseFrame` carries no step. The instruction said: recover it and say how, or move
producer-side — and **do not substitute an approximate input**. The turn moved
producer-side and said why, in the record ("avoiding consumer-side reconstruction from an
incomplete `UniformPhaseFrame`") and in a source comment:

```cpp
// A bounded-disk chart has its own UV basis and canonical face-key
// selection. Do not substitute a planar face_barycentric_from_uv call:
// it would inspect a different sample from this producer's own chart.
```

That is **RA-73.10 applied one rung after it was frozen**, and it is the reason this
measurement is decisive where the last one was not. The singleton-`{face}` technique from
rung 12 was carried forward.

**Neutrality for a producer-side probe, verified by content rather than brace depth:** the
added lines assign only to probe-local `sourceVertex`, `raw`, `incidentCount` and the
emission stream. A scan for assignments to `points[`, `cell.`, `result.`, `proposal.` or
`frame.` among the added lines returns **none**. Chain closed by content: probe blob
`4a524d204ea2dc2a55111247fdfa03b2fc57e955` **= HEAD**; `include` and `tests`
**byte-identical** at `cdd6dc4a9` and HEAD.

| artifact / run | verified |
|---|---|
| snapshot `12027572751` (run `38857271030`) | digest `0ee9aeee80b7…`, success |
| patch-apply `12029085105` (run `38859325067`) | digest `df921d8e5edd…`, success |
| compile `12028682600` (run `38859497594`) | digest `54b7f5a73ae7…`, success |
| result `12030150301` (run `38861867717`) | ZIP recomputed `de79aed888a2…`, success |

---

## RA-74.6 HARD CHARGE — the append-only ledger was destroyed and pushed

`Regression_Root_Cause_Tracker.md` went from **14,225 lines / 664 sections / 13 markers** to
**6 lines / 1 section / 0 markers** at commit `b2b6e6541`, and remained destroyed across
**four pushed commits** — `b2b6e6541`, `9b4061c59`, `e082128ac`, `0aca74462` — before being
restored at `9d0ed94e6`. The new section had been written as a **whole-file overwrite**
instead of a prepend.

**The restore is byte-faithful.** Verified: the restored file's tail from line 8 is
**byte-identical** to the tracker at the last good commit `7c83fb0ec` (`cmp` clean), and
counts reconcile exactly — 14,232 = 14,225 + 7, 665 = 664 + 1, markers 13 throughout. **No
content was permanently lost.**

What is charged is that it happened and was pushed. **The mandated gate catches it.**
`cmd_ledgers` walks every commit in the range (`rev-list --reverse base..HEAD -- path`) and
compares `rev~1` against `rev`, so it is sound — and it fails here:

```
[FAIL] no historical shrink of .../Regression_Root_Cause_Tracker.md  b2b6e654 14225->6
```

with a true exit code of **1** (confirmed separately; the tool is not at fault). **Five
consecutive NEXT_TURN blocks have required both gates be run and reported before closing.**
Had either been run, four commits carrying a destroyed durable ledger would not be on
`origin`. The append-only property is an architectural invariant of the ledger system, not a
bookkeeping convention, which is why this is a hard charge rather than a procedural note.

**Mitigation, stated plainly:** the agent detected the destruction itself, restored it
byte-perfectly, and named the restore in the commit subject rather than quietly amending.
That is the right recovery. The defect is the absent pre-push verification.

## RA-74.7 CHARGE — the controls were not measured, so they cannot discriminate here

All 54 control endpoints record `producer=none` and no sampled or published face: the
ambiguous-node probe never fired for them. The report states this accurately ("Not
measured") but does not draw the consequence — **the 23 controls provide no control for the
override**, because nothing establishes whether the override fires in them and happens to
agree. No later turn may cite the controls as evidence that the substitution is
junction-specific. This is the RA-68.5 pattern recurring: a control population that does not
control for the property under test.

## RA-74.8 CHARGE — `ORIENTATION.md` not updated, second consecutive rung

Rung 13 skipped it and this Review restored it; rung 15 skipped it again. This Review
restores it again.

## RA-74.9 Credits

- **Claim calibration corrected in one rung.** RA-73.6 charged a headline that overstated;
  this report leads with "Runtime evidence complete; separate independent Review required"
  and states plainly that "the record does **not** independently prove that the subsequent
  boundary override is valid under the A2b endpoint/side-carrier authority." That is the
  calibration the charge asked for.
- **Beacon correct.** `Successor: UNKNOWN` with reasoning in the owning document — the
  RA-63.13 shape, **not** self-referential. The RA-73.8 charge was absorbed in one rung.
- **Two non-evidential failures disclosed** — a local exploratory run that exceeded a
  60-second allowance after 16 of 44 logs, and a local Python run that failed on file
  permissions — with both explicitly excluded from the result.
- **`RP-03` satisfied a tenth consecutive turn**: the measurement relocated the locus off the
  reviewer's named target and said so.

## RA-74.10 `RP-01` state

**Locus relocated and fully specified**, for the third time: the unreconciled wholesale
substitution at `:17266-17281` in the bounded-disk producer, under
`useAcceptedConformity` (`:14993`), at grid-boundary nodes only. **Code remains NOT
authorized**, because the question is no longer *what happens* but *which authority is
right* — and that has never been adjudicated. `RP-02` **UNREACHED**.

## RA-74.11 LESSON — when one producer overwrites another's output, the question is ownership, not correctness of either

Three rungs were spent asking whether the face selector picked correctly. It did. The defect
is that a second authority replaces its answer wholesale, and **nothing in the system records
that a replacement occurred**. Before fixing a value, establish which producer owns it; a
substitution with no reconciliation is an ownership defect wearing the costume of a
computation bug.

---

## Rung 16 — scope

`M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC`, **documents only**. Four questions, all
statically answerable:

1. **What authority does `acceptedBoundary` carry?** Where is it produced (`:16822`,
   `:16867-16885`), what does `useAcceptedConformity` (`:14993`) and
   `useAcceptedCutDomain` (`:14998`) gate, and what — if anything — does it guarantee about
   `.face`?
2. **Is the override's boundary condition coextensive with the measured 21?** The guard is
   `v == 0 || u == gridU || v == gridV || u == 0`. Establish whether the 21 are exactly the
   grid-boundary nodes and the 23 exactly the interior ones, from source, not from the
   measurement.
3. **Which authority owns the corner's face at a conformity-baseline boundary node — the
   chart sample or the accepted boundary?** If the accepted boundary is authoritative, face
   7 is *correct* and `RP-01` is a downstream consumer defect; if the chart sample is, the
   override is the bug. **This reframes `RP-01` and must be settled before any code.**
4. **Apply RA-65.5 to each candidate repair** and state, for each, whether it is repair or
   merely **relocation** (RA-72.5): a face-admissibility check at the override would reject
   the 21 at producer stage and make no cell succeed.

No code, no compile, no runtime. Naming the owning authority is the deliverable.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark. No source, test, selector,
binary, harness or workflow change by this Review. PR #8 draft/open.

**`R4-VIN-01` re-arms at `cdd6dc4a9`.** Every earlier artifact — through `12019178209`,
`12021892076`, `12024554349`, `12027572751`, `12028682600` — is a **baseline, never a
comparand**. The 44 RED are the baseline for `cdd6dc4a9` alone, **candidate / non-stable**.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED (this decision) — the planar selector is exonerated for the
measured cells. RA-73.5 SUPERSEDED (this decision) — a substitution, not a selection
asymmetry. RA-72.6 CONFIRMED at the sample point and now moot. Gate C SUSPENDED (RA-65.5,
RA-68.3) and moot for `RP-01` (RA-70.11).** `PROCESS-01` discharged. `RP-03` satisfied a
tenth consecutive turn.

**Successor:** `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` (rung 16).
