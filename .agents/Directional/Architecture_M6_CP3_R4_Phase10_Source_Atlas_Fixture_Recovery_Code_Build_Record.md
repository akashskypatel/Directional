# M6-CP3-CB1-ENTRY-R4 — Phase10 source-owned A2/A3 fixture recovery (Code + Build)

## Authority and bounded result

- Canonical turn remains `M6-CP3-CB1-ENTRY-R4` **IN_PROGRESS**; successor UNKNOWN; PR #8 draft/unmerged. No Test + Benchmark authority.
- Snapshot `60ceb06a4a6f63d42fd0917a7f85b343dd5e0bd6`, workflow `38092354415`, artifact `11684083614`, outer ZIP SHA-256 `100b82ca634fe1a3a56015ddc1bbb77cd9a185760596136256fe65dd307971ce`, complete 6017/6017 source SHA256SUMS, `runtimeExecution=false`.
- Source patch applied through Drive dispatcher workflow `38092755831` / job `114332456412`; semantic source `f9db8c009835435aa1b64f07058244e58518b50b`, single file `tests/SurfaceCellsPhase10Tests.cpp` (30 added lines, 4 deleted), exact source patch SHA-256 `c637fdd2793aa864969cdaa09b658480072157466dfe978a2d5fb87246c446d1`, patch result artifact `11685125440` SHA-256 `88778b2e82522b1f9bc42aef424f2a01e9af4fd4b85a5d1e0269252b77681670`, log `11685030587` SHA-256 `20384677eb2efe2b97f32d66df29d1f935620b0b25d86c2da25d57f76d56a3a1`. Drive patch owner-deleted after verified push; backup `/Directional/Evidence/Directional_M6_CP3_R4_Phase10_Two_A3_Source_Atlas_Recovery.patch`.
- Mandatory compile GREEN: run `38092868020` / job `114332779081`; source `f9db8c009835435aa1b64f07058244e58518b50b`; 8/8 GMP/GMPXX, preflight/build exit 0/0, self-manifest 28/28, clean source, `runtimeExecution=false`; result `11685040908` SHA256 `bc2648aa9a679dc344398d8abd83a90c11c55a42a0bd36b478fb8214199e0197`; log `11684876187` SHA256 `d5c8d86b89d86f3f1be81c4ec54e561629dc14e9571b2cbf8d0ab5292195175a`.

## Causal migration and no false acceptance

The frozen rejected-R3 independent 94 overlay classifies selector ordinals `128` and `146` (both accepted under CP2) as `R3-REV-NEW-01` Phase10 A4 authority-ingress failures: `SurfaceCellAuthorityContractCutover.ExplicitSourceLabelsRemainDistinctTypedDomains` and `SurfaceCellAuthorityContractCutover.PlanarCellsReferenceRegionThatOwnsComponentAndSheet`.

A source/test-only helper `build_phase10_with_source_atlas` now constructs `SourceTopologyRegions` from the **original** test source-face topology and labels and independently constructs `FieldTransportAtlas::make` from the **original TriMesh and CrossFieldResult**; it passes that atlas to the unchanged `build_surface_cell_network` A4 production. The two frozen identities now use this helper, including the differently labeled component=2/sheet=5 case. It never builds an atlas from an A4 certificate, supplies a synthetic/mismatched A3, changes selectors, or weakens `SurfacePhaseFrontProduct::make`'s unconditional matched-atlas check. A source-invalid fixture fails before A4 rather than falling back to raw transports.

**Compilation is not runtime acceptance.** The two cases are *candidate ingress repairs*, not 2 confirmed recovered selectors. Their first actual outcomes remain to be established only by a separately authorized immutable Test + Benchmark turn. Do not infer the other 32 Phase10 identities share the exact root; preserve independent typed first-failure diagnostics, and do not change accepted totals from CP2 491/491 or rejected R3 403/497.

## Still open

39 endpoint, 34 Phase10, seven DCEL negatives, 88 formerly accepted CP2 failures, genuine odd-τ/multi-carrier producers, independent dual-admissible-path specification adjudication, and the six CP3 entry gates remain unaccepted. No source/test execution, benchmark, or 497-case selector run occurred in this Code + Build increment. The current turn and successor authority are unchanged.
