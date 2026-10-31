# M6-CP3 R2-P1 — oriented wedge-to-isolation-certificate binding: architectural resolution

**Type:** runtime-free producer-owned architecture review resolving the `M6-CP3-CB1-ENTRY-R2` stop.
**Verdict:** **BLOCK RESOLVED — the stated premise is false. No new A4 publication is required.**
**Effect:** `R2-P1`'s stop condition ("an independent A4-owned wedge-to-certificate sheet/side mapping is missing
or ambiguous") does not hold. The mapping exists in published authority on both sides and is unambiguous.

## 1. The block as reported

> A4 lacks an independently published oriented wedge-to-isolation-certificate sheet/side binding.

`M6-CP3-CB1-ENTRY-R2` correctly refused to proceed: `R2-P1` requires a stop *before* any special seam behavior if
that mapping is missing or ambiguous, and the agent could not find it. The stop gate worked. The premise,
however, does not survive source inspection.

## 2. The authority already exists on both sides

**A4 — the certificate carries both faces, a distinctness guarantee and a canonical orientation.**
`SurfaceIsolationSeamTransportCertificate`
(`include/directional/geometry/SurfaceCellTracing.h:1316-1324`) publishes
`firstFace`/`secondFace` as `authority::SourceFaceTopologyKey`, and `firstSheet`/`secondSheet` as
`authority::IsolationSheetId`. Its builder (`src/geometry/SurfaceCellTracing.cpp:16670-16750`) derives sheets
from `sourceAuthority.sheet_for_row(...)` and then enforces two properties that make a binding well-defined:

- **Distinctness** (`:16743-16745`): `if (firstTopology == secondTopology || firstSheet == secondSheet) return false;`
  — the two certificate faces lie in **distinct topologies**.
- **Canonical orientation** (`:16746-16750`): when `secondTopology < firstTopology`, face/topology/sheet are
  swapped together, fixing a deterministic First/Second ordering derived from typed topology authority.

**A5 — the occurrence already retains per-wedge typed bindings.**
`CornerWedgeFaceBinding` (`include/directional/pipeline/RemeshPipeline.h:769-775`) is
`{ authority::SourceFaceTopologyKey face; authority::IsolationSheetId sheet; geometry::SourceProjectionChart chart; }`,
and `SurfaceOccurrence::cornerWedgeBindings` stores the full vector — populated, not vestigial: it is constructed
at `src/pipeline/RemeshPipeline.cpp:4313-4440` and passed at `:4487`
(`std::move(wedgeSheets), std::move(wedgeBindings)`).

**The join key is the same type on both sides** — `authority::SourceFaceTopologyKey`. No conversion, no
re-derivation, no inference.

## 3. The binding (RA-35 candidate)

For an occurrence wedge binding `b` and a certified seam certificate `C`:

```text
b.face == C.firstFace()   ->  side = First
b.face == C.secondFace()  ->  side = Second
otherwise                 ->  b is not on C's certified seam
```

- **Unambiguous by construction.** `C.firstFace()` and `C.secondFace()` lie in distinct topologies
  (`:16743`), so no binding can match both. Several wedges may legitimately share one side; that is
  multiplicity, not ambiguity.
- **Orientation is A4-owned.** First/Second is the certificate's own canonical ordering, fixed by typed topology
  comparison — not a global label comparison and not an A5 inference. A5 contributes only *which face a wedge
  sits on*; it never decides the side.
- **Sheets are verified, never used to find.** After the face join, require
  `b.sheet == C.firstSheet()` on the First side and `b.sheet == C.secondSheet()` on the Second; a mismatch is a
  typed fail-closed error. Sheet labels therefore **neither grant nor deny** certificate lookup, which is exactly
  what frozen **RA-34.1** demands.

## 4. Why it appeared missing

The producer computes `wedgeBindings` and then *additionally* flattens them
(`src/pipeline/RemeshPipeline.cpp:4464-4471`):

```cpp
for (const auto &binding : wedgeBindings) wedgeSheets.push_back(binding.sheet);
std::sort(wedgeSheets.begin(), wedgeSheets.end());
wedgeSheets.erase(std::unique(...), wedgeSheets.end());
```

That collapse discards `face` and the per-wedge association, leaving an unordered deduplicated **set of sheets**
with no face, no side and no orientation. Both products are stored, but consumers read the lossy one:
**15** references to `cornerWedgeSheets` against **3** to `cornerWedgeBindings` in `RemeshPipeline.cpp`. The two
decisive consumers are sheet-label reasoning of precisely the kind RA-32/RA-34.1 removed elsewhere:

- `:5180-5181` — `std::binary_search(occurrence.cornerWedgeSheets.begin(), …, sheet)`, a membership test over
  global labels;
- `:7083-7086` — `if (occurrence.cornerWedgeSheets.size() <= 1U) return true;`, a cardinality test over the same
  flattened set.

So the binding was never absent. It was **unreachable through the accessor everyone uses.**

## 5. Structural precedent — this is RA-34.3's disease, already cured once

`RA-34.3` resolved τ by the same reasoning: `FieldTransportAtlas` computes the oriented transition value and
*then* marks the carrier nontraversable (`src/authority/FieldTransportAtlas.cpp:2020-2047`), so the cure was to
retain and publish the value **before** the step that destroys access, with A5 consuming published evidence and
never inferring τ from its regional gauges.

Here the producer computes per-wedge bindings and then flattens them. Same disease — a lossy downstream
projection standing in for retained authority — and the same cure: consume the retained typed bindings rather
than the flattened proxy. Same ownership principle: the producer that computes a quantity publishes it, and the
consumer never re-derives it from a lossy label space.

## 6. Decision and bounded scope

**`R2-P1`'s stop condition is not met; the mapping is neither missing nor ambiguous.** `M6-CP3-CB1-ENTRY-R2` may
resume under its existing compile-only boundary, with `R2-P1` reduced to a bounded, typed change:

1. Add a typed accessor expressing §3's join — certificate + wedge binding → `{First, Second, NotOnSeam}` —
   returning the side as A4-owned orientation, with sheet agreement **verified** after the face join and a typed
   fail-closed error on mismatch.
2. Migrate the seam-relevant consumers at `:5180-5181` and `:7083-7086` off `cornerWedgeSheets` onto that
   accessor. `cornerWedgeSheets` may remain for non-seam uses; it must not decide certified-seam questions.
3. Do **not** add new A4 publication, change the certificate builder's distinctness or canonical-ordering rules,
   or alter `CornerWedgeFaceBinding`.

**Stop conditions that remain live.** If any certified seam yields a wedge binding whose `face` matches neither
certificate face while A6 nonetheless selects that relation as a certified seam, or if a matched side's
`b.sheet` disagrees with the certificate sheet, that is a genuine producer defect — stop for Review rather than
widen the join or fall back to sheet-set membership.

## 7. Verification limits

Re-derived from repository bytes: the certificate field types and both guarantee sites; `CornerWedgeFaceBinding`'s
fields; the construction and passing of `wedgeBindings`; the flattening site; the consumer counts and the two
decisive consumer sites; and the identity of the join key type on both sides. Not established here: whether any
*produced* certified seam currently yields wedges on both sides — that is a runtime fact for
`M6-CP3-TB1-ENTRY-R2-EXEC`, and the organic-witness stop gates (D2/D3/D4/D5) are untouched by this resolution.
