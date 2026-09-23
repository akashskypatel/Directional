# M5-CP3-CB16 Occurrence-Branch Gauge Authority Correction Plan

**Turn:** `M5-CP3-CB16`
**Type:** Code + Build / runtime-free
**Owner:** `M5-CP3-TB1-R13-REV`
**Goal:** correct the one proved first-branch authority seam without broadening periodic correspondence semantics
**Runtime in this turn:** **forbidden**

## 1. Entering authority and exact defect

R13 is mechanically complete at **445/447 PASS** with selector430 **430/430**. Produced rows4/5 alone RED at typed `PeriodicActionFirstBranchMismatch`; every preceding correspondence predicate passes. R13 Review proves the mismatch is an authority-domain defect, not a free direction/translation choice:

- generator rotation `R` is exact A3/source authority between the **Forward occurrence carrier face** and **Reverse occurrence carrier face**;
- current endpoint `branchRotation` is copied from `LocalLatticeState`, whose value is authored from the cell corner/trace-point source face plus bounded-disk `chartUBranch`;
- no bridge re-expresses that local chart branch at the exact occurrence carrier face before frozen §16 branch comparison.

Canonical stored relation direction is already corrected by CB15 and must not be reopened. The CB14 relation-owned coordinate separation remains required; only its branch-authority input is now proved incomplete.

## 2. Required pre-mutation derivation

Before editing product code, write the exact endpoint derivation in the implementation notes/code comments and preserve these variables explicitly:

```text
F_local = source face attached to this endpoint trace point
F_occ   = accepted A3 boundary-occurrence face for (occurrence, span, carrier)
B_local = LocalLatticeState.branchRotation
B_face_local = faceBranchRotation[F_local]
C = B_local - B_face_local            (mod 4)   # bounded-disk chart +U offset
B_rel = faceBranchRotation[F_occ] + C  (mod 4)   # relation endpoint branch
R = exact Forward-occurrence -> Reverse-occurrence generator rotation
```

The implementation may use an equivalent exact derivation, but it must prove equivalence. `F_occ` must come from accepted A3 occurrence/carrier authority, never from whichever endpoint face was first retained as representation provenance.

For relation-owned endpoint coordinates:

```text
q = c                     when R == 0
q = rotate(B_rel, c)      when R != 0
```

where `c` is the unchanged cut-domain cell coordinate. The branch field stored in `SurfacePeriodicRelationEndpointState` is `B_rel`. This keeps the relation-owned coordinate and branch in one gauge. Ordinary `LocalLatticeState` and cell placement remain untouched.

## 3. Product scope

Implement the smallest semantic bridge needed to author relation endpoint states from exact occurrence authority. It may extend/move `make_periodic_relation_endpoint_state(...)` or provide an explicit branch-authority input, but must keep authority visible rather than hiding a face guess in a generic helper.

Required validation:

1. validate local endpoint source face and its face-branch state;
2. resolve the exact accepted A3 occurrence-carrier face for the same span/carrier used by generator-route authority;
3. validate occurrence face branch state;
4. derive one deterministic `B_rel` as above (or prove an equivalent exact formulation);
5. author both `branchRotation` and nonzero coordinate gauge from that same `B_rel`;
6. retain the existing fixed-order correspondence predicates and typed failures unchanged except where signatures must carry exact authority.

The checked `SurfacePhaseFrontProduct::make(...)` path and authoritative materializer must rederive/validate the same relation-owned state from the same exact authority. Do not create a producer-only value that consumers cannot independently reconstruct.

## 4. Focused test authority

Add one semantically named focused identity, recommended:

`M5CP3.PeriodicRelationEndpointBranchUsesAcceptedOccurrenceAuthority`

It must be independent enough to falsify the exact defect:

- use genuine nonzero quarter-turn transport;
- make the endpoint's retained local/trace source face branch differ from the accepted occurrence-carrier branch so raw `LocalLatticeState.branchRotation` cannot pass accidentally;
- independently derive the expected occurrence-carrier branch/gauge from source/A3 authority;
- prove the corrected relation endpoint branch and coordinate match that expectation;
- prove substituting the raw local branch fails the branch correspondence (or checked relation state), so the test cannot pass if the old authority is restored;
- preserve an `R==0` control proving relation coordinates reduce exactly to raw cell coordinates.

Do not add the test to selector430 in CB16. Do not weaken any existing test or change any fixture/field merely to make the subject pass.

## 5. Explicit prohibitions

CB16 may not:

- try action and inverse and choose the one that passes;
- invert `R` to cure the branch mismatch;
- fit/search a translation, rotation, branch offset or endpoint mapping against the partner;
- rewrite either endpoint after a failed predicate;
- change canonical relation ID/storage semantics or CB15's deterministic semantic-action resolver;
- change field construction, hard-feature carriers, A3 plan/occurrence identity, source transitions, selector430 or routing authority;
- weaken/remove branch, delta or endpoint-map correspondence predicates;
- execute generated Directional tests/benchmarks/discovery/CLI in Code + Build.

If the exact A3 occurrence branch cannot be deterministically derived from existing authority without introducing a new semantic owner, stop and return to Review rather than inventing one.

## 6. Compile/package gate

Use mandatory `agent-compile-reusable.yml` with GMP/GMPXX and compile/link exactly the standard eight targets:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Require clean source receipts, complete package manifest, exact source archive and `runtimeExecution=false`. No generated Directional executable may run.

## 7. Runtime successor and falsifiers

A compile-green CB16 authorizes fresh artifact-only `M5-CP3-TB1-R14-EXEC`, then mandatory Review. R14 must run the new branch-authority identity first and then the unchanged R13 **447** identities, for **448 fresh exact-filter processes**, exact-one selection/zero skips, benchmark 0, complete self-manifest and immutable postflight.

Minimum falsifiers:

1. new branch-authority identity PASS;
2. produced rows1/2/3/6 remain PASS;
3. selector430 remains **430/430**, with 191/192/247/408 PASS;
4. rows4/5 must progress beyond `PeriodicActionFirstBranchMismatch` or CB16 is rejected;
5. if row4 reaches the independent direction comparator, it must prove exact Forward -> Reverse agreement and inverted-pair rejection; only Review may close `M5-CP3-TB1-R6-REV-OBS-01`;
6. if row5 reaches transform tamper, exact typed `NonReciprocalPeriodicRelation` is required for debt credit;
7. any later typed correspondence RED is evidence for Review and must not be repaired in R14 EXEC.

No promotion, debt discharge, observation closure or selector publication occurs in Code + Build or EXEC.
