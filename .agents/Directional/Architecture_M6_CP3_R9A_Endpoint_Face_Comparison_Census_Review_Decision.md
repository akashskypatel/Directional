# Architecture Review Decision — M6 CP3 R9A endpoint face-comparison census (rung 19a)

**Review turn:** `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS-REV`
**Adjudicated:** `M6-CP3-DEFN-R9A-ENDPOINT-FACE-COMPARISON-CENSUS` (rung 19a)
**Frozen amendment:** RA-78
**Verdict:** **ACCEPTED.** It corrected my localization and **found a second active admission
path nobody in this investigation had examined**. One charge, one note.
**Review window:** 2026-10-16T11:52:30Z — 2026-10-16T12:44:18Z
**Semantic source:** unchanged at `f0d7240455b10237af47de58c035cd4c576d889a`

---

## RA-78.1 Provenance and boundary

| check | result |
|---|---|
| snapshot artifact `12040008801` (run `38888296894`) | digest `501523b30aaa1f53ed13fb57bb7e27b0d23f9398e2bd585d1920c69acfbcd957`, matches |
| `src`/`include`/`tests` at `b34c57176`, `f0d724045`, `cd4a539e8`, `HEAD` | **tree-identical** — `b65cb9b2c7…`, `790328c2bc…`, `cbef8d5ec4…` |
| turn boundary | documents only; no `src/`, `tests/`, `include/`, `cmake/`, `benchmarks/`, `.github/` change |
| `ledgers --base 053ec455a` | **ALL CHECKS PASSED** |

The census read exactly the bytes compiled at rung 17 and measured at rung 18, and the
split rung delivered — the re-scoping at RA-77.3 was the right call.

## RA-78.2 It corrects my localization, and the correction is material

RA-76.8 said admission "compares raw `SurfaceTracePoint::face`." **It does not.** Verified
by exhaustive search:

```
grep -nE '(fromPoint|toPoint|first\.(from|to)|second\.(from|to))\.face\s*[!=]='
   →  no matches
```

There is **no direct endpoint-to-endpoint face comparison anywhere**. The over-specific
demand is **indirect**, through two places the census names:

- `oriented_carrier` (`:19253-19261`, used at `:19332-19334`, `:19372-19388`) requires its
  **ordered source-face pair** to equal the endpoint-derived attachment keys, or their
  reverse, and otherwise rejects;
- `path_to(firstAttachment, oriented.firstFace)` (`:19425-19450`, used `:19463-19466`)
  requires exactly one admissible face-keyed path, **taking its start face from the
  endpoint's representative**.

So the consumer never asks whether the two endpoints agree with each other; it asks whether
**each endpoint's representative face agrees with the carrier's**. **RA-76.8 is AMENDED
accordingly** — a more precise localization, and the one 19b must actually write against.

## RA-78.3 THE DISCOVERY — a second admission path, active, never examined

`src/geometry/SurfaceCellTracing.cpp:8621-8736` is an independent checked-product verifier.
The census flags it as "also active, not just diagnostic," and that is verified:

```cpp
if (!vertex) {
  if (!endpoint.contactPaths[0].empty() || !endpoint.contactPaths[1].empty() ||
      carrier.firstFace  != endpoint.firstAttachment ||
      carrier.secondFace != endpoint.secondAttachment ||
      !same_interior_carrier_point(firstPoint, secondPoint, sourceFaces, carrier.edge)) {
    error.code = SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority;
    return error;
  }
  continue;
}
```

It returns an **error code**, not evidence. Two consequences, both material:

**(1) Any consumer-side repair must satisfy two independent checkers.** Eighteen rungs of
this investigation have reasoned about the endpoint certificate at `:19265-19495` alone. A
contract written against that one checker would have been defeated here. This is exactly
the kind of omission that sinks a repair after it is implemented, and the census found it
unprompted.

**(2) The vertex branch already implements the relation the repair needs.** For a vertex
endpoint it does **not** demand face equality. It demands `exact_vertex_attachment` on both
points, that the vertex terminate the carrier edge, and then:

```cpp
for (const auto [from, to] : {std::pair{endpoint.firstAttachment,  carrier.firstFace},
                              std::pair{endpoint.secondAttachment, carrier.secondFace}}) {
  const auto path = unique_terminal_star_path(*vertex, from, to);
  if (path == TerminalStarPathResult::Unique) continue;
  ... InvalidSourceAuthority, MissingTerminalA3Path / AmbiguousTerminalA3Path
}
```

**"Same source vertex, different representative face, reconciled by a unique A3 star path"
is therefore already an accepted relation in production code** — and the measured 21 are
vertex cases (`vertex:4` ×42, `vertex:2` ×6, RA-76.1). The repair 19b must specify is a
**precedent to be applied consistently, not an invention**. That substantially de-risks it.

## RA-78.4 CLARIFICATION — the vertex-star prohibition, stated precisely

I have written "no vertex-star predicate may be introduced" in six consecutive NEXT_TURN
blocks. Read loosely, RA-78.3 would be barred by my own instruction. It is not, and the
boundary needs freezing so 19b is neither blocked by a misreading nor handed a loophole.

- **Gate C (RA-65.5, RA-68.3) concerns a *pre-admission, rail-scoped, producer-authored
  vertex-star sector certificate*** — a published artifact that does not exist, whose
  nearest analogue (`SurfaceHardRailRouteJunctionCertificate`) is ordered after the
  admission it would license. **Gate C remains SUSPENDED and moot for `RP-01`.**
- **`unique_terminal_star_path` is a consumer-side lambda at `:8452`**, computed from source
  topology at consumption time and **already enforced in production**.

**These are different objects.** The prohibition bars *introducing a new producer-authored
vertex-star certificate*. It does **not** bar 19b from reasoning about, or proposing
consistent application of, an existing consumer-side star-path check that the product
verifier already runs. 19b may **not** invent a new star predicate, weaken
`unique_terminal_star_path`, or treat `Ambiguous` or `Missing` as acceptable.

## RA-78.5 The one-ULP hazard is confirmed consequential

`same_interior_carrier_point` (`:91-97`) is **exact rational equality**:

```cpp
const auto a = interior_carrier_parameter(first, faces, edge);
const auto b = interior_carrier_parameter(second, faces, edge);
return a.has_value() && b.has_value() && *a == *b;
```

RA-76.7 measured the accepted boundary and the chart sample agreeing on an edge parameter
only to **one ULP** in 324 instances. This test would reject such a pair outright. It is
**not** the current cause — the measured 21 are vertex cases and take the other branch —
but it is a live constraint on any contract 19b writes, and the census is right to flag it
without proposing a tolerance. **No epsilon is authorized here or anywhere.**

## RA-78.6 Credits

- **It stated its search queries verbatim** — both `rg` invocations are printed in the
  document. That is **RA-71.4 applied**, one rung after I restated it, and it is what makes
  the census falsifiable rather than merely assertive.
- **It respected the split.** "Former R9 questions 1 and 2 only… No replacement contract,
  soundness proof, repair, code, compile, runtime, selector change or implementation
  authorization." It did not drift into 19b, which is the failure mode a split invites.
- It used `UNCLEAR`-equivalent hedging honestly where the source does not settle a
  classification ("whether the *point's chosen representative* must be that face is a
  separate, unproved demand"), rather than guessing.
- The beacon is `COMPLETE` with `Successor: UNKNOWN` and the reasoning stated in the owning
  document — the RA-63.13 shape, not self-referential.
- Transport limitation disclosed (`container_session_unavailable`), with no claim of a
  staging push.

## RA-78.7 CHARGE — neither gate was run or reported, for the sixth consecutive mandate

The census carries no closeout duty table and no gate output. I have required, verbatim, in
**six consecutive NEXT_TURN blocks**, that both gates be run before pushing and their output
reported. Both pass — I ran them — so the defect is the silence, not the state.

This is not cosmetic. **RA-74.6 was the one genuine integrity incident of this
investigation** — the append-only tracker destroyed and pushed across four commits — and
the `ledgers` gate detects it exactly. Running it before pushing is the control that
prevents a recurrence, and it has now been mandated six times and delivered approximately
never.

**I am changing the ask rather than repeating it a seventh time** (RA-77.5 applied to
myself): the next rung must paste **one line each** into its closeout — the final
`ALL CHECKS PASSED` or `FAILED:` line from each gate, verbatim. A two-line deliverable is
harder to drop than a procedure.

## RA-78.8 NOTE — three durable documents were not written

`Regression_Root_Cause_Tracker.md` (fourth omission), `ORIENTATION.md` (third) and
`Architecture_M6_Frozen_Definitions.md` were not touched. Not charged — the Review writes
the authoritative sections of all three regardless, and it has done so every rung — but the
pattern is now consistent enough to record rather than keep re-noting.

## RA-78.9 `RP-01` state — localized more precisely

Not "the consumer compares raw faces," which is false. The demand is:

> each endpoint's **representative face** must either **equal** the carrier's face (product
> verifier, interior branch, `:8662-8674`) or **admit a unique A3 terminal star path** to it
> (product verifier, vertex branch, `:8685-8699`); and independently, `oriented_carrier`
> must find its ordered face pair equal to the endpoint-derived attachments
> (`:19253-19261`), with `path_to` taking its start face from the endpoint's representative
> (`:19425-19450`) — **in two separately enforced checkers.**

Every producer remains exonerated (RA-76.8). **Code remains NOT authorized.** `RP-02`
**UNREACHED**.

## RA-78.10 LESSON — a census that finds a second enforcement path has changed the repair's scope, not just its description

Eighteen rungs reasoned about one admission site. The enumeration found another that is
equally binding, and a relation already enforced there that the repair can follow rather
than invent. **Enumerate the enforcers before designing the rule**: a contract proved sound
against one checker and silently defeated by a second is worse than no contract, because it
fails after implementation rather than before.

---

## Rung 19b — scope, now properly specified

`M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC`, **documents only**:

1. **Specify the contract against BOTH checkers** — the endpoint certificate
   (`:19265-19495`) and the checked-product verifier (`:8621-8736`). A rule that satisfies
   one and not the other is not a candidate.
2. **Prove it is not a weakening**, by exhibiting what it still rejects. The vertex branch
   at `:8685-8699` is the precedent: same vertex, differing representative face, **unique**
   star path. Show what `Missing` and `Ambiguous` still exclude.
3. **State what happens at interior endpoints**, where `same_interior_carrier_point`
   demands exact rational equality and RA-76.7's one-ULP difference would reject. Say
   whether the contract covers them, and if not, say so explicitly.
4. **Apply RA-65.5** and classify each candidate as repair or **relocation** (RA-72.5).

No code, no compile, no runtime. No new star predicate, no weakening of
`unique_terminal_star_path`, no epsilon.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark, no binary executed. No source,
test, selector, binary, harness or workflow change by rung 19a or by this Review. PR #8
draft/open.

`R4-VIN-01` remains armed at `f0d724045` with **no new semantic source**; every earlier
artifact through `12036818514` and `12040008801` is a **baseline, never a comparand**. The
44 RED remain the baseline for `f0d724045` alone, candidate / non-stable.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED. RA-73.5 SUPERSEDED. RA-74.1 NARROWED and CONFIRMED. RA-76.8
AMENDED (this decision). Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for `RP-01`
(RA-70.11), with its boundary clarified at RA-78.4.** `PROCESS-01` discharged. **`RP-03`
satisfied a thirteenth turn** — the census corrected the reviewer's localization and found
an enforcement path the reviewer had missed. The historical `ledgers` failure at
`b2b6e6541` remains permanent for any earlier base, is correct, and must not be suppressed.

**Successor:** `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` (rung 19b).
