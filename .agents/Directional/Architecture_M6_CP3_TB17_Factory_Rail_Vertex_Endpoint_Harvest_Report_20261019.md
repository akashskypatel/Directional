# TB17 — factory rail-interior-vertex verification (2026-10-19)

**Turn:** `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT`. **Authority:** RA-102.5 (`Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md`).
**Run:** [39313027637](https://github.com/akashskypatel/Directional/actions/runs/39313027637); result artifact `12215967774`; ZIP SHA-256 `b32366a1b4f102a2c09388bd5debb34bbbb6b6ff9d71931f8e0a06e700ea2ace`.
**Immutable input:** CB17 artifact `12214741070`, ZIP SHA-256 `9acb50815485cb597d5673d3daab473ad140eb8aaddcd0a2dbe7d4c435b45ca5`, semantic source `ccc0b00ab6a94d0889ed7c60e4532b6c985ce03e`.
**Executor:** GitHub commit `209947282a152e125fbaf3801818ae858da27a93`; harness `.agents/Directional/tools/open_rail_interior_vertex_harness.sh` SHA-256 `efa91d9ba48b1a26b6caf189b7a6d76ca3746109c969d8f20531e32d2191c7a9`, derived from the TB16A harness `20b2ebd80f96e7d4bab6cb727b4f55cfa74f6c7006bf8c1e25e35a289f9aafea` solely by source/artifact/digest/labels/count and appended gate #13.

All **13/13** exact-filter processes selected once: **8 PASS / 5 expected diagnostic RED / 0 missing**. Gates #1–#7 and #13 PASS; #7 includes the compiled R interval cases and #13 is `SurfaceCellAuthorityContractCutover.OpenRailInteriorVertexEligibilityTruthTable`. Diagnostics #8–#12 remain RED with **byte-identical `first_failure`** values to the verified TB16A result artifact `12198063461` for every ordinal. No RA-102.5 falsifier was observed.

The downloaded TB17 result ZIP digest and every result-manifest file digest were verified. `postflight=True`, `package=true`, `source=true`, `execution_view=true`, `frozen_selectors=true`; `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`; harness exit 0. CB17's factory R branch is not exercised by the unchanged consumer; no direct-production or selector-497 acceptance is claimed.

**Regression classification:** the five diagnostic REDs are retained pre-existing non-stable endpoint-route failures, not a new stable regression. All comparison identities and first failures are unchanged; stable ledger **66/17/49**, debt **1**, last candidate census **425/497**, selector **497**, `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

**Mandatory successor after complete durable closeout:** `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT-REV`; independently re-derive the result and issue the CB18 U5 consumer specification. Do not start CB18 in this turn.
