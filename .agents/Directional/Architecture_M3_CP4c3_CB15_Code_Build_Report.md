# M3-CP4c-3-CB15 Code + Build Report

**Status:** COMPLETE / BUILD GREEN / PRODUCT CORRECTION / RUNTIME-FREE.
**Turn boundary:** Code + Build only. No Directional runtime test, selector identity, benchmark, generated discovery, CLI/help/version command, fuzzer, or custom runtime input executed.

## Objective and exact authority

CB15 discharges **BJ0-BJ9** from `Architecture_M3_CP4c3_TB12_Independent_Review_Record.md` §8.2. It corrects only the vertex-locus trace-ray `RayOrderKey::secondary` contract proved wrong by TB12-REV: a ray's origin-port ordinal is not a meaningful within-wedge order at a different locus vertex.

The product correction first landed at `ab0501de362c3518f1f040015f19b64c179aa007`. The final compile/package source is **`a2fd98eaa015ff5872890bb1945cf4e9e9493615`**, whose only follow-up semantic-source change aggregate-initializes `GlobalTopologyArc` in the new compiled witness because its semantic-ID members intentionally delete default construction.

Preserved recovery patches:

- product patch SHA-256 **`63f4c2d3aa00d95b2810082337691697a619ec1493dc730d7c696be722b679ab`**, diff-body SHA-256 `e8371b7df00babcc13bdabc4d3c24b5d3b60c9d195407e0229d45c9d9f1b1644`;
- compile-fix patch SHA-256 **`7b9ba3dee25a182c12e7c84df81aba7dc2d6ac28d403aeee31cb631870bc8c21`**, diff-body SHA-256 `39b9dcfc873ce00373566a6cec4cc41c753c24e145c09a55ddf0b375593d0a81`.

Both successful Drive-apply paths verified patch/base/body identity and `runtimeExecution=false`. The compile-fix Drive file required owner-side retirement and was permanently deleted after successful application.

## BJ0 / BJ6 — frozen accepted boundary and selector 379

Selector 378 remains byte-identical at SHA-256 **`86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`**, 378 lines / 378 unique identities. Static falsification of the old vertex-locus rank justified one appended compiled witness, so CB15 publishes selector **379** at SHA-256 **`ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`**, 379 lines / 379 unique identities. Selector 378 is the exact 378-line prefix of 379.

The appended identity is:

`GlobalTopologyPlan.VertexLocusSecondaryRankUsesExactWithinWedgeGeometry`

Accepted semantic authority remains **365/365**; no selector identity was executed in CB15.

## BJ1 / BJ2 — exact locus-relative within-wedge ordering

The vertex branch of `build_rotation_system` no longer assigns `key.secondary = port->ordinal`. For each trace ray incident at a source-vertex locus, it now derives an exact ray parameter inside the shared face wedge from the ray's own first point away from that locus:

- `Forward` uses `segments[arc.firstSegment]`;
- `Reverse` uses `segments[arc.onePastLastSegment - 1U]`;
- boundary-transit points are converted to exact face barycentrics;
- a trace terminating inside the wedge ranks from its exact terminal barycentric point rather than being excluded.

For the locus corner, the helper computes the exact ratio between the two barycentric coordinates opposite the locus. Dense rank is then assigned from those `FieldExactRational` parameters. The implementation uses exact arithmetic only: no floating-point tolerance, trigonometry, world-space angle, arc identity, trace identity, or orientation identity participates in the order.

## BJ3 / BJ4 — exact coincidence remains fail-closed

Distinct rays that produce the same exact within-wedge parameter are **not** ordered by an arbitrary identifier. They fail closed under the new typed reason:

`RotationVertexTraceRaysExactlyCoincident`

The historical `RotationRayOrderKeyCollision` remains available for its original collision class. `primary`, `build_vertex_fan_slots`, `trace_ray_face`, the edge-locus branch, incidence ownership, cut search, and topology decisions are otherwise unchanged. No Mandatory/Cut same-slot behavior was altered.

## BJ5 / BJ8 — compiled witnesses and accepted-boundary proof

`GlobalTopologyPlan.VertexLocusSecondaryRankUsesExactWithinWedgeGeometry` compiles four focused observations:

1. two Forward rays in one wedge at exact parameters `1/4` and `3/4`, deliberately supplied in reverse input order, receive dense ranks matching geometric order;
2. Reverse orientation obtains its exact parameter from the last segment's entry point;
3. an interior terminal contact receives an exact within-wedge parameter (`2/3` in the witness);
4. exact parameter coincidence produces equal dense rank and the typed `RotationVertexTraceRaysExactlyCoincident` fail-close reason.

The regression portion proves a wedge with only one trace ray receives rank zero. This matches the review's structural accepted-boundary proof: `secondary` is compared only after a `primary` tie, a trace-ray `primary` tie means a shared wedge, and every shared-wedge trace case was rejected before CB15. Therefore no previously successful rotation can be reordered by this change.

No fixture was changed.

## BJ7 — prohibition audit

CB15 does **not**:

- add `arc`, `trace`, or `orientation` as an ordering/tie-break identity;
- alter fan-slot construction, edge-locus secondary ranking, incidence ownership, cut candidates, or cut admissibility;
- revert or weaken CB12 terminal ownership or CB14 diagnostics;
- repair `finalize_field_aligned_events` fall-through;
- decouple ordinals 371/372;
- change the unguarded Mandatory/Cut same-slot case;
- change prescribed-sphere 368, saturation 369, ordinal 370, folded-cone 374, vertex 30, or any fixture.

## Compile evidence — GREEN

A mandatory separate pre-package core compile completed first on source `ab0501de362c3518f1f040015f19b64c179aa007`: run/job **`33664981149 / 100364438045`**, result artifact `9860215940` (Actions SHA-256 `e8b4f18e67351416a8e342ce0b272ab702432b38bce4e317dbe2aff04882c394`). It linked with GMP/GMPXX and executed no Directional runtime.

The first eight-target compile attempt then correctly exposed only a compile defect in the new witness: `GlobalTopologyArc` cannot be default-constructed because semantic IDs delete default construction. No Directional binary ran. The surgical aggregate-initialization fix produced final source `a2fd98eaa015ff5872890bb1945cf4e9e9493615`.

Final compile workflow run/job **`33667287957 / 100372314673`** compiled and linked exactly the eight required targets:
`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

- exact compile source: **`a2fd98eaa015ff5872890bb1945cf4e9e9493615`**;
- result artifact **`9861189794`**, Actions SHA-256 **`310d8ac7a0b40cd11932e0e0a1a8c1b9e19689f927a6d9f383981867e6810f50`**;
- log artifact **`9861190565`**, Actions SHA-256 **`dfce2f1c1e8b0ca877d5ceb4ba576f36812ebd4582ef264806ac32c408115e2e`**;
- configure, preflight, and build exit codes are zero; recursive artifact manifest verifies; final source status is empty;
- all six packaged test/benchmark executables have executable mode `0755`;
- authoritative link evidence contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`, with `exactArithmeticBackend=GMP`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

## Immutable package 83

Package workflow run/job **`33667812301 / 100373836357`** consumed compile artifact `9861189794` directly. It performed no replacement compile and executed no Directional binary. It reverified exact source identity, compile manifest, GMP evidence, clean source status, selectors 373-379 and every prefix relation, 27 package-relative fixtures, executable modes, and package manifests before and after deterministic extraction.

- package artifact **`9861269273`**, Actions SHA-256 **`1b8ce6a12edc8f7949deea3c43855e94e5755c0e73ed1cb603a2acd50901cab4`**;
- package log artifact **`9861270098`**, Actions SHA-256 **`a8b374c2059736dfcac43737b18edf4a156990fd7988d0dccea7f8892ef889e1`**;
- inner deterministic `package83.tar.gz` SHA-256 **`c09d98ed35e9155805f759f27f54491b03643851650ce49dcb65c2191fc069ff`**;
- packaged source archive SHA-256 **`55305976488edc1edc13432e953787555c5ef5d4dcaff041617c0ae568d922c2`**;
- selector 379 SHA-256 `ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`; frozen selector 378 SHA unchanged;
- `fixture_count=27`; six packaged `directional_*` executables remain executable;
- `runtimeExecution=false`, `packageRepair=false`, exact arithmetic backend GMP.

Authoritative semantic M3 package count advances **79 -> 80**. This is build/package evidence only, not semantic acceptance.

## BJ9 — frozen TB13 discriminators

CB15 publishes these mandatory next-turn discriminators without executing them:

1. selector ordinals **1-365 remain 365/365**;
2. ordinal **366 no longer reports** `RotationRayOrderKeyCollision` at source vertex 47; an identical repeat falsifies BJ1;
3. the two previously colliding rays (arc 20 / trace 6 / Forward from v47 and arc 23 / trace 9 / Reverse from v71) receive **distinct** `secondary` values and the v47 rotation publishes all five rays;
4. any remaining ordinal-366 red is at a different stage, reason, or locus; certification may then proceed into face walking where `nonDiscComponentCount` / `remainingAdmissibleEdgeCount` can legitimately be measured for the first time;
5. `M3-CP4c3-TB11-CAND-01` closes only if discriminators 1, 2, and 3 all hold.

**No vertex-30 discriminator is published.** Nothing in CB15 proves the corrected v47 rotation reaches vertex 30.

The executable procedure and stop rules are frozen in `Architecture_M3_CP4c3_TB13_Artifact_Only_Test_Benchmark_Plan.md`.

## Exit

CB15 is **COMPLETE / BUILD GREEN / RUNTIME-FREE**. CP4c-3 remains **OPEN**; accepted authority remains **365/365**; stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic package count is **80**. The exact next turn is artifact-only **`M3-CP4c-3-TB13`** on immutable package 83. No TB13 runtime work is part of CB15.
