# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`.
- Tested source: `074ec5d125b531db03fcfbda9d6d3654bfc696b7`.
- Artifact: `8860409984` (`surface-cell-p5-cb66-rollback-integrity-linux-release`).
- Digest: `sha256:37c04eaa694a87ed9ab4f48b2123b54f52c0a0d16d8fb9672d367ebdfdbfcee3`.
- Artifact integrity: source status empty; checksums **36/36**; no rebuild.
- Completed turn: P5-TB13 artifact-only test and benchmark.
- Next turn: P5-CB67 through P5-CB74 code changes + compile-only build.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB50 — initial global-frontier implementation.
- [x] P5-TB11 — complete inventory diagnosis; closure gates failed.
- [x] P5-CB51–P5-CB58 — budget batching, memory lifetime, fixture closure, compile-only artifact.
- [x] P5-TB12 — rollback/result/lifetime diagnosis.
- [x] P5-CB59–P5-CB66 — rollback-integrity implementation and compile-only artifact.
- [x] P5-TB13 — artifact validation; production, reuse, lifetime, rail, simplification, and wall gates failed.
- [ ] P5-CB67 — successful subdivision domain-identity validation and producer correction.
- [ ] P5-CB68 — real failed side-repair rollback regression.
- [ ] P5-CB69 — canonical semantic reusable-product cache lookup.
- [ ] P5-CB70 — restore simplification fixed-point API semantics.
- [ ] P5-CB71 — correct invalid Milestone D fixtures and retest intended contracts.
- [ ] P5-CB72 — propagate authoritative rails to arrangement halfedges.
- [ ] P5-CB73 — eliminate random-bunny result/context lifetime crashes.
- [ ] P5-CB74 — compile/package exact checkpoint without executing binaries.
- [ ] P5-TB14 — artifact-only successful-path validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## P5-TB13 evidence

Tests:

- focused subset: **9/15 passed**;
- `PatchDescriptorMilestoneE.*`: **20/22 passed**;
- Phase 14–18: **228/230 passed**;
- P23 + Phase 20: **53/54 passed**;
- authoritative non-overlapping P5 total: **301/306 passed**;
- Milestone D: **4/7 passed**;
- full packaged disposition: **579/590 passed**, with 8 assertion failures and 3 deterministic signal-11 tests.

The three signal-11 tests all stop in `bunny_1k_random__surface_cells`. Parameterized cases `0–6` and `8` pass; case `/7` is the random bunny and crashes.

Four independent random-bunny benchmark processes are deterministic but fail before descriptor acceptance:

```text
InvalidArrangementDomainIdentity;firstPatch=2;secondPatch=-1
```

Common state:

- side repair succeeds: infeasible cells `918 -> 0`, inserted vertices `8,074`;
- descriptors/completed patches/output quads: `0/0/0`;
- trace segments: `12,130`;
- arrangement/simplified cells: `7,405/7,405`;
- exact reused completions: `0`;
- fallback/recovery: neither used.

Resources:

- wall range: **40.231057–44.680662 s**;
- all four exceed the `39.228299 s` wall gate;
- maximum peak working set: **185,614,336 B**;
- memory cap: `1,115,394,560 B` — passed on the early-failure path;
- increase versus P5-TB12 early-failure maximum: **16.78%**;
- reduction versus P5-TB11 maximum: **80.18%**.

## Primary diagnosis

P5-CB59 targeted a rejected side-repair transaction. Production does not take that path: the side-repair solve succeeds, then `derive_patch_descriptors` reports cell `2` has an invalid domain identity. The next code turn must validate the successful subdivision output at the exact producer boundary and report the invalid cell/halfedge/node/source occurrence.

Additional proven defects:

- reusable completion products are still looked up by allocation-local `descriptor.cellId`, so exact semantic equality is never reached after renumbering;
- P5-CB63 removed the established default post-commit simplification candidate refresh;
- the three Milestone D failures are invalid fixture preconditions, not reasons to weaken production validation;
- authoritative rail metadata reaches embedded arcs but not arrangement halfedges;
- returned-result ownership remains unsafe for the random-bunny case.

## P5-CB67–P5-CB74 gates

- Successful side subdivision yields valid exact domain identities for every authoritative cell.
- A real permitted side-repair failure proves exact rollback equivalence.
- Product cache lookup uses canonical semantic dependency identity, not `cellId`.
- Default simplification restores deterministic dependency-bounded fixed-point refresh.
- Milestone D fixtures construct valid intended topology before evaluating production behavior.
- Rail ID, curve ID, parameters, component/sheet, and exact provenance survive into arrangement halfedges.
- Every production manifest case owns its returned result and terminates normally.
- Preserve one committed complex, one mutable transaction, compact ownership, and deferred output.
- Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
- Execute no binary in the code/build turn.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB13_Rollback_Integrity_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Successful_Subdivision_Identity_Code_Build_Plan.md`
- `benchmark-results/p5-tb13-summary.json`
- `.agents/Directional/Milestone_G_P5_Rollback_Integrity_Code_Build_Report.md`

P5 remains open. PR #8 remains draft and unmerged.
