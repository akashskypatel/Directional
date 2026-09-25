# M6-CP1-CB6 — Legacy SurfaceOccurrence Field Retirement — Code + Build Plan

**Status:** AUTHORIZED BY `M6-CP1-TB5-REV` / RUNTIME-FREE CODE + BUILD ONLY
**Exact successor on compile-green:** `M6-CP1-TB6-EXEC`
**Mandatory Review after TB6:** `M6-CP1-TB6-REV`

## Goal

Make the public A5 `SurfaceOccurrence` representation match frozen M6 §3.2 by removing three unread representative-value fields that duplicate or contradict complete labelled wedge authority: `chart`, `lattice`, and `isolationSheet`.

## Frozen implementation scope

1. In `include/directional/pipeline/RemeshPipeline.h`, remove only:
   - constructor parameters `sourceChart`, `latticeState`, and `sheet`;
   - constructor initializers for `chart`, `lattice`, and `isolationSheet`;
   - data members `chart`, `lattice`, and `isolationSheet`.
2. In the A5 producer call site in `src/pipeline/RemeshPipeline.cpp`, remove only the corresponding arguments currently derived from `wedgeBindings.front().chart`, the unlabelled `lattice`, and `wedgeBindings.front().sheet`.
3. Preserve byte-for-semantic-purpose all live A5 authority: `id`, `point`, `support`, `chartComponent`, `topologyRegion`, `cornerWedgeSheets`, `cornerWedgeBindings`, `placement`, and `cornerWedgeIsolation`.
4. Perform a whole-repository static reader census before editing. If any semantic reader of the three fields exists on the exact CB6 source, stop and return to Review rather than translating that reader silently.

## Explicit non-goals

No test/fixture/selector/routing edits. No A5 identity or certificate change. No A6 relation, quotient, side, seam, HardRail or Periodic change. No A7 lineage/embedding change. No A4 or frozen-definition change. No opportunistic refactor, formatting sweep or compatibility alias. The previously recorded aggregated-lineage sort debt is already satisfied in current source and is **not** CB6 work.

## Static acceptance checks

- zero remaining declarations or reads of `SurfaceOccurrence.chart`, `.lattice`, `.isolationSheet`;
- constructor and sole producer call agree after parameter removal;
- `point` and `chartComponent` remain present;
- frozen selector449 and routing449 bytes/hash remain unchanged;
- source diff is confined to the minimal header/producer construction surface unless a compile error proves an additional direct syntactic dependency;
- `git diff --check` clean.

## Compile boundary

Use only durable `.github/workflows/agent-compile-reusable.yml`. Compile/package the standard eight targets with mandatory GMP/GMPXX. Require package manifest/source receipts/preflight/build evidence and `runtimeExecution=false`. Do not execute generated Directional binaries, tests, benchmarks, discovery/help/version commands, `ctest`, fuzzers or custom runtime inputs in CB6.

## TB6 frozen gate

Compile-green produces one unpromoted candidate for `M6-CP1-TB6-EXEC`. TB6 consumes it immutably and executes exactly the unchanged seven focused identities plus selector449 = **456 fresh exact-filter processes**, exact-one selection, zero skips, benchmark 0, no watchdog, immutable pre/post census. No new selector is published.

`M6-CP1-TB6-REV` independently decides candidate promotion and CP1 closure. CP1 may close only if the static public A5 product no longer contains the three legacy fields and TB6 is mechanically/semantically green without weakening any accepted authority.

## Stop rules

Stop for Review if field removal reveals any semantic consumer, requires a product-definition amendment, changes accepted selector/routing bytes, requires test/fixture changes, or exposes a runtime-relevant semantic dependency beyond the three dead representation fields. A compile failure may be repaired in the same CB6 turn only when the fix is a direct bounded syntactic consequence of the authorized removal and no generated runtime has executed.
