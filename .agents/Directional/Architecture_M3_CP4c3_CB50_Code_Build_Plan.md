# M3-CP4c-3-CB50 Code + Build Plan

**Status:** FROZEN / EXACT SUCCESSOR / RUNTIME-FREE

**Turn:** `M3-CP4c-3-CB50`
**Authority:** `M3-CP4c-3-TB44-REV`, measures EG0–EG9
**Runtime authority entering:** TB44/package109/selector409 — **398 PASS / 11 RED / 0 SKIP**, accepted **365/365**
**Stable accounting:** **47 events / 14 categories / 33 recurrences**, debt **5**, packages **109**

## 1. Objective

Apply exactly two independent bounded corrections exposed by TB44 without changing topology definitions, fixtures,
selector409, carried RED owners, or runtime cadence:

1. **Product:** stop treating all carrierless trace rays on one source face as one source-corner fan in
   `build_fragment_corner_incidence()`.
2. **Protected tests:** make Part XII terminal evidence conditional on the authoritative failure subject rather than
   unconditionally requiring current-region fields whenever chronology says `RegionCertification`.

CB50 compiles/packages only. It executes no Directional binary.

## 2. Product correction — face + source-corner authority

In `src/geometry/GlobalTopologyPlan.cpp`, keep each carrierless ray's existing exact
`binding->sourceCorner`. Change the ray aggregation/validation so that:

- carrierless rays are partitioned by `(sourceFace, sourceCorner)` before ordering;
- each source-corner fan is sorted by existing `port->ordinal`;
- duplicate-ordinal and orbit-chain consistency checks remain fail-closed within that fan;
- each fan publishes the same orbit→source-vertex corner contributions the current single-fan logic publishes;
- contributions from multiple fans on the same face merge only through the existing set-valued
  `FragmentCornerIncidence` map;
- full-chord/ray incompatibility and every invalid source/dart/binding guard remain live.

Do not add a new traversal, geometry heuristic, topological certificate, face-walk derivation, region derivation or
fallback owner. Do not modify `build_regions()`, `fragmentOrbits`, `region_orbit()`, face-walk construction, cut
selection, partitions or source authority.

The exact TB44 falsifier is source face `10,11,79`, where the owner census is 3/3/3 with two non-crossing trace
chords. The correction must not collapse distinct source corners merely to retain the old whole-face ordering.

## 3. Protected-test correction — typed terminal subject

In `tests/FieldAlignedCurveNetworkTests.cpp`, preserve the real-data and deliberately-corrupted-data predicates for
ordinals 390/393/406/407. Their `UncutCensus` branch must remain non-vacuous.

Replace the shared region-only terminal-evidence expectation with a typed subject check consistent with Part XII:

- always require `regionFrontierSubjectDomainRelation == "Outside"` for this mechanical witness;
- **current-region subject:** when `topologyRegion` is present, require the existing
  `region_fragment_owner_relation_is_valid(locus)` relation plus both region source-face counts;
- **source-face subject:** when no current region exists but `sourceFace` is present, require the source-face subject
  and require current-region-only owner/count fields to be absent rather than synthesized;
- **unresolved subject:** if neither can be identified, fail closed.

Extend the deterministic R8 receipt only as needed to name which terminal-subject branch executed. Do not remove or
weaken `censusPredicateExecuted=yes`, `sameDomainCorruptionRejected=yes`, `terminalSubjectRelation=Outside`, or the
real producer predicate itself.

Do not alter fixtures, selector identities, `P_U`, the uncut partition, owner census, or production diagnostics to
make the tests pass.

## 4. Frozen unchanged surface

CB50 must not change:

- selector409 bytes or any selector manifest;
- accepted identities 1–365 except source compilation caused by the bounded product/helper edits;
- fixtures, meshes, fields, rails, network seeds or benchmark inputs;
- Part VIII, Part XI/Part XI-A, or Part XII normative definitions;
- `build_regions`, region IDs/boundaries, actual embedded graph construction, `region_orbit`, cut selection,
  `fragmentOrbits`, `P_U`, plan/certifier partitions;
- carried RED owners 368/369/370/374/398;
- ownership policy or the 300/0/0 certification contract;
- retired error/proxy behavior.

No drive-by refactor, generalized terminal-kind redesign, selector growth, new fallback, or assertion weakening is
authorized.

## 5. Build boundary and evidence

Use the durable `.github/workflows/agent-compile-reusable.yml` with mandatory GMP/GMPXX. The exact pushed semantic
source is the compile authority.

CB50 may perform source/static checks and compile/link approved targets. It must execute **no** generated
Directional binary: no tests, benchmarks, `ctest`, discovery/list/help/version commands, CLI, fuzzer or custom input.
The package must record `runtimeExecution=false`, exact source SHA, GMP/GMPXX link evidence, recursive manifest and
normal source-status evidence.

Package count advances only on an accepted new immutable compile package; stable event/category/recurrence totals do
not change in CB50.

## 6. Required static review before compile

Before publishing the patch, verify from source that:

1. every existing carrierless `RayCut` insertion still records exact `sourceCorner`;
2. the previous whole-face `sourceCorner != rays.front().sourceCorner` assumption is gone as a cross-corner
   rejection, not merely hidden behind reordered input;
3. duplicate ordinal / orbit chain guards still execute per source-corner fan;
4. no new owner is invented from unrelated face/corner data;
5. 390/393/406/407 still execute their real producer predicate and corrupted-copy negative before terminal evidence;
6. the terminal helper distinguishes current-region vs source-face subjects from authoritative locus fields, not
   from stage-name string matching.

## 7. TB45 artifact-only falsifiers

After compile/package success, author exactly one `M3-CP4c-3-TB45-EXEC` artifact-only plan bound to the immutable
CB50 package and unchanged selector409.

TB45 must measure all 409 identities exactly once in fresh processes under the standard immutable-gate controls.
Its review-critical observations are:

- 366/367 do not reproduce `FragmentCornerSourceCornerMismatch` on source face `10,11,79`; PASS or a later
  fail-closed guard is preserved for review;
- 390/393/406/407 PASS only if their real `P_U` predicates execute, corrupted copies are rejected, `Outside` is
  published and the typed terminal subject evidence is valid;
- accepted 1–365 remains 365/365;
- 368/369/370/374/398 stay at their carried owners;
- 311/312/314/315/356/357/404/408/409 remain PASS;
- ownership remains 300 established / 0 unavailable / 0 conflicting and retired-code silence remains.

Do not freeze a synthetic aggregate. A 404/5 outcome is only the arithmetic consequence if the six targeted REDs
recover and every carried owner stays fixed.

## 8. Exact successor on successful compile

**`M3-CP4c-3-TB45-EXEC` — Test + Benchmark / artifact-only**, under the plan authored from the accepted immutable
CB50 package. If compile/package orchestration fails, remain within the CB correction boundary; do not execute
runtime from an unaccepted package.
