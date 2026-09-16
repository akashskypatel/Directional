# M4-CP-SCALE-CB11 — S4 Product Activation Code + Build Plan

**Boundary:** product + focused-test implementation, compile/package only; **no Directional runtime**
**Accepted input authority:** package `10455353524` / source `bebb14e32a0ac53dd420acf46bfa34410cf759a1` / selector425 **425/425**
**Selector authority:** 425 LF rows / SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; first424 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`
**Required successor if GREEN:** `M4-CP-SCALE-TB10-EXEC`

## 1. Purpose

Activate the already-reviewed S4 necessary-condition accelerator in the production `SurfaceCutGraph::canonical_candidate` path without changing the final topology authority or cut-search semantics.

The accepted prerequisite proves a production-reachable empty-cut torus state for which an independently reconstructed actual-complement invariant rejects (`V48/E48/F4,c4,s1,chi0`, `b1=4`, required/observed faces `3/4`) while the unchanged final certificate also rejects; it also proves the accepted-cut state does **not** early-reject and final certification succeeds. CB11 turns that proved relation into a production optimization only.

S4 is a rejection accelerator, never an acceptance authority. The final authority remains `SurfaceCutGraphCellularityCertificate::proves_embedded_cellularity()` plus per-face disc topology.

## 2. Frozen behavior before implementation

`canonical_candidate` currently fixes `cuts`, classifies candidate evidence, calls `certify_actual_embedded_graph(...)`, returns only if the exact certificate proves embedded cellularity, and otherwise advances through the existing non-disc proposal/saturation path.

CB11 may change only the cost/order of proving that a **fixed candidate state cannot succeed**. It may not change what cut set is proposed next or what final state is accepted.

The accelerator must therefore obey:

`earlyReject(candidate) => finalCertificate(candidate).proves_embedded_cellularity() == false`

The converse is neither required nor permitted as an assumption.

## 3. Authorized source surface

Primary implementation ownership is:

- `src/geometry/SurfaceCutGraph.cpp`;
- only if required to expose an already-computed internal fixed-candidate topology prefix without duplicating authority: `src/geometry/EmbeddedGraphTopology.cpp` and `src/geometry/EmbeddedGraphTopology.h`;
- `tests/FieldAlignedCurveNetworkTests.cpp` for the focused product identity and independent oracle comparison.

A public `include/**` API change is **not expected**. If product activation requires a new public semantic field, a changed public certificate contract, CMake ownership change, fixture change, or any source beyond the bounded internal seam above, stop for Review instead of assuming that expansion.

Selector425 is frozen. Do not create selector426 in CB11.

## 4. M0 — one exact fixed-candidate S4 result type

Implement one internal exact result for the state already fixed by `(source authority, network, sorted cutEdges)`. It must publish enough values to make the decision auditable, at minimum:

- actual graph vertex count `V`;
- actual graph edge count `E`;
- actual graph component count `c`;
- source component count `s`;
- source Euler characteristic `chi`;
- independently justified connected complement-component count `F_observed` for the **same counting domain as the accepted prerequisite**;
- `b1 = E - V + c`;
- `F_required = chi - s + b1`;
- covered-class decision `reject = (F_observed != F_required)`.

All arithmetic is exact/integer. Negative/overflow/impossible intermediate states return unavailable/fail-closed-to-final-certification, not a guessed reject.

The implementation must not read the final `SurfaceCutGraphCellularityCertificate` to manufacture these fields.

## 5. M1 — observed complement count must be the proved domain

This is the load-bearing falsifier. `F_observed` must mean the same connected actual-complement component count used by the accepted independent prerequisite, not a convenient existing integer with the same value on one witness.

Specifically, **do not** substitute without a proof:

- `proposal_components(...)` source-face barrier partition count — source itself labels it a conservative proposal heuristic and source-triangle components need not equal actual embedded complement components;
- `embedded.faceWalk.orbits.size()` or final-certificate `faceCount` — TB8 established that face-walk orbit representation is not interchangeable with connected complement components off the cellular domain;
- retained source-support Euler proxy authority — it is retired.

CB11 may reuse exact lower-level topology primitives, but the product computation and the test-side prerequisite oracle must remain structurally distinct enough that the test is not simply asserting a mechanism against itself. If the only available implementation is the same oracle copied into product, stop for Review and state the missing abstraction rather than creating circular authority.

## 6. M2 — production insertion point and semantic neutrality

Invoke the S4 result only after source/atlas/network binding is valid and the candidate cut set for that certification attempt is fixed, and before invoking the full final certificate for that same candidate.

If S4 returns **reject=true**:

1. do **not** return a new product error;
2. do **not** mutate `cuts` inside S4;
3. skip only the final-certification attempt that S4 has proved cannot accept;
4. continue into the same existing proposal/non-disc/saturation logic that would have followed a non-cellular final certificate;
5. preserve certification-attempt/cut-candidate accounting semantics unless an existing field explicitly counts full certificate invocations rather than candidate attempts; if that distinction exists, document it rather than silently changing its meaning.

If S4 is unavailable or returns reject=false, run the unchanged final certification path. Only that path may accept and return a `SurfaceCutGraphCandidate`.

No backtracking, alternative cut selection, cut reordering, repair, heuristic acceptance, or final-certificate weakening is authorized.

## 7. M3 — prove the accelerator actually does work

The product-focused identity is frozen as:

`M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate`

Owner: `directional_surface_cell_producer_tests`.

The test must use the accepted test-side independent oracle as falsifier, not replace it with the product helper. It must establish at least these subjects:

1. **Reachable empty-cut torus negative:** product S4 result available and rejecting with the accepted `48/48/4/4/1/0` domain and `b1=4`, required/observed `3/4`; independently constructed final certificate for the same fixed state is non-cellular.
2. **Accepted-cut positive:** product S4 result is available and non-rejecting for `72/76/4/1/1/0`, `b1=5`, required/observed `4/4`; final certificate proves embedded cellularity.
3. **One-edge adversarial:** if product S4 rejects, final certificate is non-cellular; no converse is asserted.
4. **Enumeration invariance:** reverse permutation of the same accepted cuts gives the same canonical S4 state and decision.
5. **Production-path activation:** the standard torus `SurfaceCutGraph::make` reaches at least one S4 early rejection before its accepted final cut set and still returns the exact same accepted cuts and all pre-existing final certificate fields as the unaccelerated/reference construction available to the test.
6. **Deletion discriminator:** the activation receipt must expose a count/state proving at least one full final-certification attempt was bypassed. If the accelerator can be deleted and every observed receipt remains identical, the mechanism is vacuous and CB11 must not claim success.

A side-channel used only to prove M3.5/M3.6 must be non-semantic and bounded to tests/internal diagnostics. Do not add a public acceptance field merely to make the test easy.

## 8. M4 — reference construction for decision neutrality

The product test needs a trustworthy unaccelerated comparator. Prefer a narrow internal/test seam that runs the existing final-certificate path with acceleration disabled **without changing candidate proposal logic**. It must not become a second production mode or user-facing flag.

Compare, at minimum:

- accepted cut edges;
- all pre-existing `SurfaceCutGraphCellularityCertificate` fields and face/ownership/candidate evidence;
- final error code/locus for any negative control where the production call fails;
- source/atlas/network bindings and existing semantic output that predates CB11.

New non-semantic S4 diagnostic counters, if any, are excluded from the equality only if their sole purpose is proving activation and they are not part of pre-existing authority. Do not weaken existing `operator<=>`/hash semantics to hide a real product difference.

## 9. M5 — compile/package contract

CB11 is Code + Build only. Use the mandatory reusable compile workflow and GMP/GMPXX backend. Compile the changed-owner preflight first, then package all standard targets required by selector425 plus the focused S4 owner. Package evidence must record `runtimeExecution=false`.

Before closeout require:

- semantic changed paths remain inside §3;
- focused S4 identity has exactly one definition and producer ownership;
- selector425 remains exactly 425 unique LF rows with SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- first424 remains `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`;
- no selector426 exists;
- package/source manifests and GMP receipts verify;
- no Directional test, benchmark or runtime process executes.

Compile GREEN provides zero S4 runtime/selector credit.

## 10. Stop rules

Stop CB11 and return to Review if any of the following binds:

1. `F_observed` can only be supplied by `proposal_components`, face-walk-orbit count, final-certificate fields, or another representation not independently proved to match accepted connected actual-complement authority for the covered class;
2. the product helper and the test oracle become the same mechanism, making the gate circular;
3. an early reject would return a new semantic failure rather than follow the unchanged proposal path;
4. accepted cut edges or any pre-existing final certificate field differ between accelerated and reference paths;
5. the accelerator requires cut addition/removal/reordering, backtracking, repair, or final-certificate weakening;
6. the focused test cannot prove at least one full final-certification attempt is genuinely bypassed;
7. implementation requires public API, fixture, CMake semantic or selector changes outside §3;
8. compile/package cannot establish mandatory GMP/GMPXX authority.

## 11. Success criterion and next boundary

CB11 succeeds only when the bounded product accelerator + independent focused test compile/package cleanly under mandatory GMP/GMPXX, selector425 remains byte-identical, at least one future runtime discriminator is statically present, and `runtimeExecution=false` is proved.

The sole successor after a successful CB11 is `M4-CP-SCALE-TB10-EXEC`. TB10 must run the focused product identity first in one fresh process, validate its structured activation/safety receipt, then run selector425 as 425 additional fresh exact-filter processes only if focus is green, with fail-fast untouched remainder and immutable postflight. `M4-CP-SCALE-TB10-REV` is mandatory before selector426 publication or S4 cumulative credit.
