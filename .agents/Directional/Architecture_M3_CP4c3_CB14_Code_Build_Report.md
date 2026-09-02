# M3-CP4c-3-CB14 Code + Build Report

**Status:** COMPLETE / BUILD GREEN / DIAGNOSTIC-ONLY.
**Turn boundary:** Code + Build only. No Directional runtime test, gate, benchmark, generated discovery, CLI/help/version command, fuzzer, or custom runtime input executed.

## Objective and exact authority

CB14 discharges **BH0-BH9** from `Architecture_M3_CP4c3_TB11_Independent_Review_Record.md` §8 without changing rotation, ordering, cut, or topology semantics. The first diagnostic implementation commit is `1d684f954deb48a8a2490b2a7453e143a134d0e9`; the final corrective test/selector commit and exact compile/package source is **`71ece3ca184e90858d9222fb014b37c16d292294`**.

The initial preserved patch is SHA-256 `b93677c03695d4d241487c5dd5820303a17ea085f76fe1e33b53b3b0c81ced9a` with diff-body SHA-256 `2e140cda654e062184bb9d14b575664027e19d99866463b139210a80959d6bd2`. The corrective patch is SHA-256 `b1a1b2cdf234e2696a3c9f82a00c69b2787e9def36c5666f9dfa6e4a54370a45` with diff-body SHA-256 `c31711cdd67aa548d6c1cc9abfd6d7a38109ca3810a716f75838d34de5e74050`. Both Drive-apply workflows verified base identity, patch/body digests, exact changed-path manifests, `git apply --check`, `git diff --check`, and `runtimeExecution=false` before committing ordinary source files.

## BH0 / BH6 — frozen gate and selector 378

Selector 377 is byte-identical at SHA-256 **`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`**, 377 lines / 377 unique identities. Static review demonstrated the diagnostic projection gap required by BH5, so CB14 appends exactly one diagnostic identity and publishes selector **378** at SHA-256 **`86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`**, 378 lines / 378 unique identities. Selector 377 is the exact 377-line prefix of selector 378. The appended identity is:

`GlobalTopologyPlan.RotationRayOrderCollisionDiagnosticsSurviveProductionFailureProjection`

Accepted semantic authority remains **365/365**; no gate identity was executed in CB14.

## BH1-BH3 — collision identity and bounded fan census

`build_rotation_system` now retains diagnostic evidence for both adjacent sorted rays when `RotationRayOrderKeyCollision` fires. The retained data names each side's ray kind, `primary`, `secondary`, arc, optional trace, orientation, optional source face, resolved fan slot, origin port ordinal, and origin port source vertex. Error propagation/projection preserves a previous/current pair all the way to the production failure renderer.

The failing locus also carries a bounded keyed-fan census with an explicit total count and truncation flag. The census is capped at 16 entries, so diagnostic capture remains bounded and cannot alter the rotation construction itself.

## BH4 — honest certification counters

`SurfaceCutGraphError::nonDiscComponentCount` and `remainingAdmissibleEdgeCount` are now optional diagnostics rather than zero-initialized observations. Paths that measure those values still assign them; the initial-certification rotation collision does not fabricate `0` for measurements that were never made. The production renderer emits either a populated measurement or no field.

## BH5 — compiled witnesses, not executed

CB14 adds a synthetic same-sector collision diagnostic witness that passes through the production cut-graph failure projection and production message renderer. Its assertions require both ray identities, both key operands, orientations, origin-port provenance, fan census/truncation information, certification attempt/cut-edge identity, and absence of unassigned certification counters.

The existing mechanical production-entry witness keeps its prior assertions verbatim and adds a pre-existing-failure check that, if ordinal 366 still throws before the original assertions, the rendered failure line must carry both ray identities (`arc`/`secondArc`, `trace`/`secondTrace`, and previous/current ray payloads) before the exception is rethrown. This source was compiled only; its runtime behavior remains for TB12.

## BH7 / BH8 — prohibition and assumption audit

The final source does **not** change the collision predicate, sorting comparator, `RayOrderKey` members, `primary`/`secondary` construction, `trace_ray_face`, the incidence map, counter-clockwise rotation publication, cut proposals, cut admissibility, or any topology decision. It does not add arc/orientation to the collision predicate, revert CB12, repair finalize/contact fall-through, decouple 371/372, or alter sphere/saturation/370/folded-cone behavior.

The implementation adds only error/diagnostic state, propagation/rendering, witness source, and the selector append. Success-path product outputs and ordering/cut decisions are unchanged by construction; only a typed failure path can publish the additional evidence. No fixture was changed.

## Compile evidence — GREEN

Final compile workflow run/job **`33653092570 / 100324843819`** compiled and linked exactly these eight required targets:
`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

- exact compile source: **`71ece3ca184e90858d9222fb014b37c16d292294`**;
- result artifact **`9855741844`**, Actions SHA-256 `b4b98c3f8ee0ad0a777f69f591591303e37c99d136dc028d511967b746e7fb16`;
- log artifact **`9855742445`**, Actions SHA-256 `aaf9c901cf2a36b3d925e3ba670cf5bd07f86b7afc2f218e3986ae3d157ee81a`;
- configure/preflight/build completed successfully; source status was clean and internal artifact checksums were verified;
- authoritative link evidence contains both GMPXX and GMP and reports `exactArithmeticBackend=GMP`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

The earlier green compile `33651279544` at `1d684f95...` is superseded as final CB14 evidence because the BH5 mechanical assertion and selector 378 were added afterward.

## Immutable package 82

Package workflow run/job **`33653737897 / 100327139865`** consumed compile artifact `9855741844` without replacement compilation and without executing a Directional binary. It reverified source identity, compile manifest, GMP evidence, clean source status, selectors 373-378 and every prefix relation, 27 package-relative fixtures, six executable-mode binaries, and package manifests before and after deterministic extraction.

- package artifact **`9855841174`**, Actions SHA-256 `4f597d260a6fb258767378489741326a6f6c2322522bdd60ef9fd071970c26ed`;
- package log artifact **`9855841773`**, Actions SHA-256 `434e5c4457281ff75dc4e9855aa86f609d28a2751c783d9191b88fecdd186e59`;
- inner deterministic `package82.tar.gz` SHA-256 **`58393e9927e80e894a753cafee074202fd6df8fec43d8cba244fe1404e23a5e1`**;
- packaged source archive SHA-256 **`3ae91b7544749f00487ff57e1705d657d23d84ffe3107ce1a4565c3a24d35f1e`**;
- selector 378 SHA-256 `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`; frozen selector 377 SHA unchanged;
- `fixture_count=27`, six packaged `directional_*` executables remain executable;
- `runtimeExecution=false`, `packageRepair=false`, exact arithmetic backend GMP.

Authoritative semantic M3 package count advances **78 -> 79**. This is packaging/build evidence only, not semantic acceptance.

## BH9 — TB12 discriminators

CB14 publishes the following mandatory next-turn discriminators, without executing them:

1. selector ordinals 1-365 remain 365/365;
2. ordinal 366 remains `RotationRayOrderKeyCollision` at `sourceVertex=47`, `certificationAttempt=0`, `certificationCutEdges=0`; movement falsifies the diagnostic-only assumption;
3. ordinal 366 names both arcs, traces, faces, orientations, origin-port ordinals/source vertices, and previous/current ray payloads;
4. the bounded fan census at vertex 47 exposes occupancy around the colliding sector, including truncation state;
5. `nonDiscComponentCount` / `remainingAdmissibleEdgeCount` are populated only if measured, otherwise absent.

Exact executable procedure and stop rules are in `Architecture_M3_CP4c3_TB12_Artifact_Only_Test_Benchmark_Plan.md`.

## Exit

CB14 is **BUILD GREEN / RUNTIME-FREE**. CP4c-3 remains **OPEN**; accepted authority remains **365/365**; stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic package count is **79**. The exact next turn is artifact-only **`M3-CP4c-3-TB12`** on immutable package 82. No TB12 runtime work is part of this report or CB14.
