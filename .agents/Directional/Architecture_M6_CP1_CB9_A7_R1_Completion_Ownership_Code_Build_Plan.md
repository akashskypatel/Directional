# `M6-CP1-CB9-A7-R1` — Completion Ownership Authority Recovery Code + Build Plan

> **Review-agent amendment (RA-22a, `M6-CP1-TB9-A7-REV` addendum) — this block is added to the plan below.**
>
> **What failed.** The failing clause is deduced statically: the destination sheet differs from the representative's sheet (Review record §H2). G3's sheet-membership change is the operative fix. Keep G2/G3's region and component checks as fail-closed restatements.
>
> **G5 — diagnostics (mandatory, no predicate change).**
> - Emit `CompletionOwnershipInvalidSelectedRelationDestination` with exactly one suffix, `:dest-unresolved`, `:dest-region`, `:dest-sheet` or `:dest-component`, chosen by the first false subclause in that order. Apply this to both the A7 and the legacy branches.
> - Emit the G2 singleton failure as `CompletionOwnershipInvalidRetainedSourceAuthority:component-singleton`.
> - Static check: no test or production caller compares these base strings exactly. Re-verify with a grep and record it in the CB report.
>
> **Out of scope** (recorded, not for R1): the A7 cross-sheet proxy (owner: `M6-CP1-CLOSE-REV`) and single-sourcing `τ` (owner: CB10).
>
> **TB9-R1 classification note.** If focused 20 is still RED, the suffix identifies the clause. Any non-destination completion failure after the fix is a newly exposed downstream check; Review classifies it. Do not broaden R1 scope inside the turn.

**Type:** Code + Build only. **Runtime forbidden.**
**Review authority:** `Architecture_M6_CP1_TB9_A7_Review_Record.md`, RA-22.
**Input candidate lineage semantics:** CB9 A7 at `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`.
**Successor if compile/package green:** `M6-CP1-TB9-A7-R1-EXEC` -> mandatory `M6-CP1-TB9-A7-R1-REV`.

## Goal

Repair only the completion consumer boundary exposed by focused20. A7 publishes class-wide chart/region/sheet authority; completion must validate a selected relation destination against that class-wide authority, not against the representation-only `lineage.sourcePoint.face`.

## Required implementation

### G1 — separate legacy selected-face authority from A7 class authority

In `close_completion_lineage_source_authority`:

- keep `selectedRegion`, `selectedSheet`, and `selectedComponent` only for the legacy path where `sourceOccurrences` is empty;
- when `sourceOccurrences` is nonempty, treat `retainedSourceCharts`, `retainedSourceRegions`, and `retainedSourceSheets` as the semantic A7 authority;
- do not overwrite or narrow those retained sets from the representative point.

### G2 — derive exact class-wide source-component authority

For A7 lineage, derive source components from every retained chart with `SourceChartTransitionGraph::source_component`.

- every retained chart must resolve to a source component;
- normalize into a set;
- require exactly one component, otherwise fail closed with an existing ownership-authority failure or a narrowly named completion ownership failure if an existing code cannot state the condition truthfully;
- selected-relation destination component must equal this singleton.

Do not infer component authority from `lineage.sourcePoint.face`.

### G3 — validate relation destination by retained membership

For every A7 `selectedRelationPath` destination:

- retain the existing exact endpoint-chart and chart-component certificate checks;
- require destination region membership in `retainedSourceRegions`;
- require destination sheet membership in `retainedSourceSheets`;
- require destination source component equality to the G2 singleton;
- remove the A7 requirement `candidateSheet == selectedSheet`;
- do not search for a different destination, path or chart.

The current region/sheet retained-chart preflight may remain even where later membership checks are redundant; do not weaken fail-closed validation merely to reduce duplication.

### G4 — preserve unrelated semantics exactly

Do not change:

- A7 producer or product structures;
- A5/A6 occurrence, quotient, relation or selected-path authority;
- RA-18 support kind/identity/same-simplex point checks;
- `canonicalRelationValue`, `canonicalTransport`, `relationTransport`, or composition order;
- focused-20 or focused-12 bytes;
- selector449/routing449;
- fixtures;
- CB10/CB11 plans or reserved focused identities 21-28;
- non-A7 legacy completion closure (`sourceOccurrences.empty()`).

## Required static review checks before compile

1. For A7 lineage, no selected-relation destination decision compares a candidate sheet/component to the representative face's sheet/component.
2. A7 destination chart, region and sheet are checked only against retained class authority.
3. A7 component authority is recomputed from retained charts and is singleton/fail-closed.
4. No relation graph search, alternate-route selection, tolerance weld, placement-transport read, or sourcePoint-based semantic selection is introduced.
5. `git diff --check` passes and changed semantic source is bounded to the completion integration seam unless Review explicitly reopens scope.

## Compile/package gate

Use only `.github/workflows/agent-compile-reusable.yml` with mandatory GMP/GMPXX authority and the standard eight targets. Record `runtimeExecution=false`. No generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, help/version invocation or custom input may execute in this turn.

A compile failure may be repaired in this same Code + Build turn only when the repair remains inside the RA-22 boundary. A semantic-scope expansion stops for Review.

## Recovery runtime gate after compile-green

`M6-CP1-TB9-A7-R1-EXEC` consumes the new candidate immutably and executes exactly:

1. `Architecture_M6_CP1_Required_Green_Focused_20.txt` in file order;
2. selector449 in file order with frozen routing449;
3. total **20 + 449 = 469** fresh exact-filter processes;
4. exact-one selection, zero skips, benchmark 0;
5. immutable package/source/fixture/selector postflight.

No new focused identity is added. Focused20 is already the production-completion falsifier for RA-22. Recovery-green is **469/469**, followed immediately by mandatory runtime-free `M6-CP1-TB9-A7-R1-REV`. CB10 remains held until that Review.
