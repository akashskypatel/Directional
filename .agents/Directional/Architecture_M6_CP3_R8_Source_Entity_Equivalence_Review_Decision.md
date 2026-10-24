# Architecture Review Decision — M6 CP3 R8 source-entity equivalence (rungs 17 and 18)

**Review turn:** `M6-CP3-R8-SOURCE-ENTITY-EQUIVALENCE-REV`
**Adjudicated:** `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` (rung 17) and
`M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST` (rung 18)
**Frozen amendment:** RA-76
**Verdicts:** both **ACCEPTED**. **The branch is settled: (b).** Two charges.
**Review window:** 2026-10-16T09:40:07Z — 2026-10-16T10:31:55Z
**Semantic source:** `f0d7240455b10237af47de58c035cd4c576d889a` (new — `R4-VIN-01` re-arms)

---

## RA-76.1 THE RESULT — branch (b), and no row anywhere denotes a different source entity

Re-derived independently from `source-entity-census.tsv`: **2,628 rows, 0 errors**, three
outcomes — `carrier-orientation` **1,008 SAME / 0 DIFFERENT**;
`not-same-interior-carrier-point` **1,296 SAME / 324 DIFFERENT**.

**The 48 decisive comparisons.** Every row with `sampled_face=3` and `accepted_face=7`
resolves to the **same canonical source vertex**: 42 × `vertex:4 ‖ vertex:4` and
6 × `vertex:2 ‖ vertex:2`, all 48 classified `SAME_ENTITY`. (The 4/2 split is the RA-67.5
first-appearance vertex compaction appearing yet again — one phenomenon in two index
domains, now at occurrence granularity.)

**The 324 are not a counterexample, and this is measured rather than characterised.** The
record describes them as "one-ULP-like hexfloat edge-parameter representations." Verified
exactly, by parsing every token and computing the integer ULP distance:

| check | result |
|---|---|
| rows classified `DIFFERENT_ENTITY` | 324 |
| of those, on the **same canonical edge** | **324 / 324** |
| ULP distance histogram | **`{1: 324}`** — every one is exactly one ULP |
| `DIFFERENT` rows involving a **vertex** entity | **0** |

So all 324 differ only in the final mantissa bit of an edge parameter **on an identical
canonical edge**. **No row in the census denotes a different source entity or sheet.**
Branch (a) — "the accepted and chart points denote different source entities, so the
override is invalid upstream" — has **zero support in the measurement**. **Branch (b)
stands: the override substitutes a different *representation* of the same source entity,
and the defect is the consumer's contract demanding raw face equality.**

## RA-76.2 RA-75.3's open question is closed by measurement

`override` is `1` on **all 2,628 rows**. The substitution fires at **every** measured
grid-boundary node, including the `FirstTo` corner whose published face equals its sample.
So `FirstTo` *was* overridden and happened to agree. **RA-74.1's narrowing (RA-75.3) is
confirmed: the override is not junction-specific**, and the earlier appearance that it
distinguished the 21 was an artefact of only one corner's face changing.

## RA-76.3 Rung 17 — the first probe with deletions, and they are correct

Three lines were deleted, which no prior probe did, so each was checked individually:

```cpp
-      const int sampledFace = points[node_index(u, v)].face;
+      const SurfaceTracePoint sampled = points[node_index(u, v)];
+      const int sampledFace = sampled.face;
+      const SurfaceTracePoint *accepted = nullptr;
       if (useAcceptedConformity) {
-        const SurfaceTracePoint *accepted = nullptr;
```

Both edits are **semantics-preserving**: `sampledFace` holds the same value, and the
`accepted` declaration is hoisted out of the `if` with its `nullptr` initialisation intact,
so it is `nullptr` exactly when the block does not run. The widened capture is what
instruction 2 required — the substitution at `:17279` overwrites in place, so the point had
to be copied before it was destroyed — and the hoist is the only way to observe the
`accepted != nullptr` outcome that instruction 1a demanded. **Minimal and necessary.**

**Neutrality verified.** The emission sits at depth 1 inside the rejection branch, which
opens at `src/geometry/SurfaceCellTracing.cpp:19507` and closes at `:19825`; the new
emission is at `:19743`. No added line assigns to `points[`, `cell.`, `proposal.` or
`frame.`; the only `result.*` writes are to the diagnostic map
`boundarySourceEntityProbes`, declared beside the existing `latticeUvCandidateProbes` and
propagated by a plain map merge at the region build. The consumer hunk is a read-only
iteration filtered to the two involved regions, emitting `none` when empty.

**The classifier is built in the right domain** — the RA-75.4 lesson applied one rung after
it was charged. `source_entity` tests `point.barycentric[i] == 1.0` and `!= 0.0`
**exactly**, with no tolerance, as instructed; it reports a vertex as a **source vertex id**
`faces(point.face, i)` and an edge as a **canonical `(lo, hi)` source-vertex pair** with the
parameter in hexfloat. That is what makes a point in face 3 and a point in face 7
comparable at all — the identity is expressed in a domain both faces share.

## RA-76.4 Chain and artifacts, re-derived

| check | result |
|---|---|
| probe commit `f0d724045` cpp blob | `fd07f514dab95b5fa9ecde35c8b0eec294c729ee` = **HEAD** |
| `include` / `tests` at `f0d724045` and HEAD | **byte-identical** |
| snapshot `12035302774` (run `38876338945`) | digest `0577eedd0c31…`, success |
| patch-apply `12035488476` (run `38877023124`) | digest `2fb730bb1a4b…`, success |
| compile `12035788036` (run `38877282902`) | digest `1967771d10b7…`, success |
| result `12036818514` (run `38880040401`) | ZIP **recomputed** `4305035309ef…`, success |
| result manifest | **49 OK / 0 BAD** |
| `execution-boundary.txt` | `planned=44 executed=44 red=44 missing=0 postflight=True exit=0`, `compile=false relink=false benchmarks=false selector497=false` |
| disclosed failure `38879689539` | independently **`conclusion=failure`** |
| disclosed failure `38879850655` | independently **`conclusion=failure`** |
| `ledgers --base 7f5160cd8` | **ALL CHECKS PASSED** — no shrink; RA-74.6 not repeated |

Both dispatcher failures are real — an unsupported `environment_json` and an incorrect
copied selector digest, each rejecting before any test ran — and both were disclosed with
their run ids when only the third run carries evidence. **`RP-03` satisfied a twelfth
consecutive turn.**

## RA-76.5 CHARGE — the result is hedged where it is actually total

The record writes that the 324 "**include** one-ULP-**like** hexfloat edge-parameter
representations, not proof of illegal topology." Measured: **all 324, exactly one ULP, on
an identical canonical edge, with no vertex entity involved.** The hedge understates a
clean and complete result, and leaving "324 DIFFERENT" unqualified in the same paragraph
invites a successor to believe branch (a) retains partial support. **It retains none.**

This is the fifth turn in the claim-calibration family — RA-67.9, RA-70.7, RA-71.10,
RA-73.6 and now RA-76.5 — though not monotone, since RA-74.9 credited a correction and
RA-75 was well-calibrated. The pattern is specifically that **a hedge is attached to a
measurement that the turn's own data already settle**.

## RA-76.6 CHARGE — the beacon is `IN_PROGRESS` with a self-referential `Successor` again

`STATUS` reads `Turn: M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST`,
`Status: IN_PROGRESS`, `Successor:` naming that same turn. **Six consecutive NEXT_TURN
blocks have required `Successor` be left EMPTY while in progress and never self-naming
(RA-67.11).** RA-73.8 charged exactly this; it was then correct for two rungs and has now
recurred.

**Mitigation, and it is substantial.** The cause is a genuine transport failure — the
closeout patch could not be applied because "Files reported no active container session" —
and the record says plainly "**do not claim this patch pushed**" and "keep current TB8 turn
IN_PROGRESS until verified remote apply." Declaring an incomplete closeout rather than
faking one is the correct behaviour. The charge is narrow: the `Successor` field costs
nothing to leave empty, and a successor reading it is handed a cycle.

**Consequence:** `Regression_Root_Cause_Tracker.md` was again not written, its content
staged in an unapplied patch. This Review writes the authoritative tracker section and
closes the beacon.

## RA-76.7 A latent locus the measurement exposes

The accepted boundary and the chart sample compute the **same** edge parameter to within
one ULP but **not bit-identically** — 324 instances. Any consumer that compares those
parameters by exact equality will fail on them. Nothing in the measured 44 turns on this
today, because the failures are vertex cases, but it is a real property of the two
producers and it bears directly on the contract rung 19 must specify. Recorded as backlog;
**not authorized for repair**, and specifically **no epsilon may be introduced to paper
over it** — the contract must say what equality is required, not loosen a comparison.

## RA-76.8 `RP-01` state — every producer is now exonerated

For the first time, the chain is clear end to end:

| component | status |
|---|---|
| chart sampler (`point_on_periodic_chart`) | **exonerated** — RA-74 measured `sampled-min` in all 21 |
| planar selector (`point_on_source`) | **exonerated** for these cells — RA-71.5 amended |
| accepted-boundary producer | **exonerated** — RA-75.2, face from `run.sourceFaces[edgeIndex]` |
| the override itself | **exonerated** — RA-76.1, same source entity in every row |
| route publisher, carrier producer, tracer, `from` corner | **exonerated** — RA-70.7 |
| **consumer endpoint admission** | **the sole remaining candidate** |

`RP-01` is therefore **localized to the consumer's endpoint-equivalence contract**: the
admission test compares raw `SurfaceTracePoint::face` where the producers only ever
guaranteed *source-entity* identity. **Code remains NOT authorized** — the contract has to
be specified before it is changed, and the obvious weakening is exactly the kind of
predicate relaxation that has been prohibited throughout. `RP-02` **UNREACHED**.

## RA-76.9 LESSON — a classifier stricter than the question answers a different question

`DIFFERENT_ENTITY` was reported 324 times and the entity was identical every time; the
classifier compared exact float tokens where the question asked about entities. **When a
measurement's verdict column disagrees with its own evidence columns, the verdict is the
thing to re-derive.** Had the 324 been taken at face value, branch (a) would have looked
partially alive and the next rung would have been scoped to adjudicate a difference that
does not exist.

---

## Rung 19 — scope

`M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC`, **documents only**. Branch (b) is
settled, so the question is what the consumer's contract should be:

1. **Where exactly does admission demand raw face equality?** Name every comparison in the
   endpoint-certificate path that tests `SurfaceTracePoint::face` or a face-keyed lookup
   against a corner, with line anchors.
2. **What equality did the producers actually guarantee?** RA-75.2 and RA-76.1 establish
   source-entity identity, not face identity, and RA-76.7 shows edge parameters agree only
   to one ULP. State the guarantee precisely, including the ULP caveat.
3. **Specify the contract the consumer should require**, and prove it is not a weakening:
   show what it would *still* reject. The carrier is edge-keyed (RA-67.6) and the measured
   `to` endpoint is a vertex of the crossed edge, so an incidence-based test is the obvious
   candidate — and the obvious danger. **Gate C remains SUSPENDED (RA-65.5, RA-68.3) and no
   vertex-star predicate may be introduced**, so the contract must be expressible from
   already-published witnesses.
4. **Apply RA-65.5**, and say for each candidate whether it is repair or **relocation**
   (RA-72.5).

No code, no compile, no runtime. Specifying the contract and proving it does not weaken
admission is the deliverable.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark. No source, test, selector,
binary, harness or workflow change by this Review. PR #8 draft/open.

**`R4-VIN-01` re-arms at `f0d724045`.** Every earlier artifact — through `12030150301`,
`12032341939`, `12035302774`, `12035788036` — is a **baseline, never a comparand**. The 44
RED are the baseline for `f0d724045` alone, **candidate / non-stable**.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED. RA-73.5 SUPERSEDED. RA-74.1 NARROWED and now CONFIRMED by
measurement (RA-76.2). Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for `RP-01`
(RA-70.11).** `PROCESS-01` discharged. `RP-03` satisfied a twelfth consecutive turn. The
historical `ledgers` failure at `b2b6e6541` remains permanent for any earlier base, is
correct, and must not be suppressed.

**Successor:** `M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` (rung 19).
