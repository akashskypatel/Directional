# M3-CP4c-3-CB49 Code + Build Plan

**Status:** FROZEN BY TB43-REV / NOT YET EXECUTED
**Turn:** `M3-CP4c-3-CB49`
**Boundary:** Code + Build only; compile/package, no Directional runtime
**Definition authority:** `M3_CP4c_Frozen_Definitions.md` Part VIII R4.1/R4.2, Part XI/Part XI-A, Part XII
**Runtime authority entering turn:** TB43/package108, selector409, 402 PASS / 7 RED, accepted 365/365

## Purpose

Repair only the predicate drift proved by TB43-REV: the orbit-keyed `FragmentCornerIncidence` projection drops
every final segment lacking `terminalBarrier`, while `build_regions()` drops that segment only when its two
certified face-walk sides are the same orbit. The correction must make the ownership projections agree without
changing region construction, actual embedded topology, cut selection, partitions, selectors, or unrelated RED
owners.

## EG0 — exact source and unchanged-surface preflight

Before editing, resolve current branch authority and verify the implementation source inherited from package108
still contains the reviewed predicates. Preserve selector409 SHA-256
`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.

Frozen unchanged surfaces include accepted identities 1–365, ordinals
311/312/314/315/356/357/390/393/404/406/407/408/409, Part XI/Part XI-A/Part XII definitions, region construction,
`fragmentOrbits`, `region_orbit`, source ownership, actual embedded graph construction, cut selection, `P_U`, the
certifier partition and carried owners 368/369/370/374/398.

## EG1 — align the corner-ownership skip predicate

In `src/geometry/GlobalTopologyPlan.cpp`, inside `build_fragment_corner_incidence()`:

- use the already-derived `forwardOrbit` and `reverseOrbit`;
- skip the no-barrier final segment only when
  `is_terminal_slit(*trace, segmentIndex) && forwardOrbit == reverseOrbit`;
- do not skip when the two certified face-walk sides differ.

This is the same separation decision `build_regions()` already applies. Do not create a second source-face/orbit
enumeration or infer ownership from fragment counts.

## EG2 — preserve shared-orbit semantics

A final no-barrier segment with `forwardOrbit == reverseOrbit` remains non-separating for this ownership projection.
The existing R4.1/R4.2 behavior that merges corners into one certified owner must remain intact. Add or adjust a
comment only as needed to state the exact predicate; do not globally redefine terminal kinds.

## EG3 — preserve genuine fail-closed certification

Do not weaken or remove `RegionSourceFaceOwningFragmentMissing`. Region certification must still reject a source
face when the current region's actual face-walk orbit is genuinely absent from `FragmentCornerIncidence`.
`RegionInteriorVertexCornerOwnerMissing` and later guards remain unchanged; they are allowed to become newly
observable only if the repaired owner row advances 366/367.

## EG4 — targeted static/test coverage

Use existing unit/fixture structure to prove the changed predicate without changing selector membership or accepted
assertion meaning. Any added/modified test must cover both sides of the decision:

- a final no-barrier segment whose certified dart sides share one orbit is still excluded from separating ownership;
- a final no-barrier segment whose certified dart sides are distinct orbits contributes the expected orbit-keyed
  corner ownership.

Prefer a bounded existing mechanical/source-derived witness over inventing a new semantic proxy. Test changes may
validate the product predicate, but must not special-case ordinals 366/367 or synthesize their runtime result.

## EG5 — semantic freeze audit

Before compile, prove the diff does not alter:

- `build_regions()` or `fragmentOrbits` semantics;
- `region_orbit()` or face-walk construction;
- actual embedded graph/cut graph construction;
- source ownership, `P_U`, barrier sets or certifier partition;
- selector409 bytes/membership;
- accepted test blocks and the Part XII non-vacuity receipts;
- the five separately owned RED paths 368/369/370/374/398.

A needed change outside the corner-incidence consumer/test surface is a hard stop for review unless it is purely
compile plumbing required by the bounded implementation.

## EG6 — changed-owner compile first

Compile the narrowest target owning `GlobalTopologyPlan.cpp` and its relevant tests first through the durable
`.github/workflows/agent-compile-reusable.yml`. Then compile the standard immutable package targets. GMP/GMPXX is
mandatory. `runtimeExecution=false` must remain true.

No generated Directional binary may be executed: no tests, benchmarks, discovery/list/help/version command,
`ctest`, CLI/GUI, or custom runtime input.

## EG7 — package and provenance

Package the exact compile-green source as the next immutable semantic package. Record exact source SHA, compile
run/job IDs, package artifact ID/name/digest, packaged source archive SHA, selector409 hash, GMP/GMPXX link evidence,
changed-path inventory and `runtimeExecution=false`.

A compile failure may be corrected inside CB49 only when the fix stays inside this bounded owner and no runtime
executes. A semantic expansion is a hard stop.

## EG8 — author exactly one TB44 artifact-only plan

Only after compile/package success, author exactly one
`Architecture_M3_CP4c3_TB44_Artifact_Only_Test_Benchmark_Plan.md` bound to the immutable CB49 package. CB49 itself
must not execute TB44.

The plan must require:

1. full selector409, one identity per fresh process, accepted 365/365;
2. 366/367 must not reproduce the exact TB43 `RegionSourceFaceOwningFragmentMissing` locus
   (`sourceFace=10,11,79`, expected orbit 1, owner set `[2,3]`); PASS or a later guard are both legitimate measured
   outcomes;
3. 390/393/406/407 remain PASS with all Part XII receipts;
4. 368/369/370/374/398 remain at their separately owned failure surfaces, otherwise the scope claim is falsified;
5. ownership 300/0/0 and retired-code silence;
6. if 366/367 advance, preserve the exact first downstream failure, including
   `RegionInteriorVertexCornerOwnerMissing` if it is exposed, for independent review.

Do **not** freeze an aggregate 404/5 vector. That is only the arithmetic consequence if both 366/367 go green and
nothing else moves.

## EG9 — hard stops and closeout

Hard-stop and route to review if implementation requires any of the following:

- changing region/face-walk semantics to make the corner map agree;
- changing selector membership or an accepted oracle;
- weakening/removing a certification error instead of fixing the owner projection;
- altering the five carried RED owners;
- unifying the plan/certifier partitions or embedded-graph builders;
- executing Directional runtime during CB49.

On success, close CB49 as compile-green/runtime-free, retain exactly one current build report and the one TB44 plan,
then hand off exactly to **`M3-CP4c-3-TB44-EXEC`**.
