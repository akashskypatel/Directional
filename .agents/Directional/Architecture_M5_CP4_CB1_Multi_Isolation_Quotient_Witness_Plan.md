# M5-CP4-CB1 — Focused Multi-Isolation Quotient Producer Witness Code + Build Plan

**Turn:** `M5-CP4-CB1`
**Role:** Code + Build
**Boundary:** test-authority implementation plus compile/package only. **No Directional runtime, test execution, benchmark, selector publication, or product-semantic change.**
**Predecessor:** `M5-DEFN-R2` disposition B and `Architecture_M5_Frozen_Definitions.md` §18.
**Accepted prefix:** selector448, 448 rows, SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`.

## 1. Goal

Author one focused producer-boundary identity that makes the frozen `G4-B004` M5 half falsifiable on the committed torus pipeline. The test must prove one **common producer subject** contains all of the following before occurrence/materialization/embedding/verifier work:

1. `SurfaceCellProducerDisposition::Produced` phase-front authority from `torus_fixture()` / `make_torus_pipeline_fixture()`; no direct/draft/helper substitute and no test-supplied `sourceFaceSheets`;
2. one authoritative `SourceTopologyRegion` whose source faces span at least two distinct `IsolationSheetId` values;
3. at least one internal isolation seam owned by that region;
4. a checked `SurfaceIsolationSeamTransportCertificate` for that region/seam with explicit transition, source faces, distinct endpoint sheets, and reciprocal quarter-turn transport;
5. at least one canonical `SurfacePeriodicHolonomy` whose `sourceTopologyRegion()` is exactly that same region;
6. at least one `SurfaceFrontBoundaryKind::PeriodicCut` edge in that region whose `periodicRelation` names that exact relation owner, with reciprocal opposite-edge ownership/provenance consistent with the existing row443 contract.

Suggested semantic identity: `M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion`. The exact name may vary only if repository naming conventions require it; it may not encode a planning/checkpoint phrase in non-test production symbols.

## 2. Scope

### Authorized

- modify only the minimal existing test source needed to add the focused identity;
- reuse existing torus fixture and independent helper/oracle functions when they already expose the required producer authority;
- add a minimal test-local helper only if needed to derive a region's distinct isolation-sheet set or bind the checked certificate/relation owner without duplicating product logic;
- update CMake/test ownership only if the new identity cannot compile/discover under the existing owner target;
- run the mandatory GMP/GMPXX reusable compile/package workflow for all owner targets required by the eventual artifact-only gate.

### Forbidden

- product/source semantic edits;
- fixture or raw-field edits;
- changing `torus_fixture()` semantics or injecting sheet labels;
- modifying selector448 or publishing selector449;
- weakening existing row443/446/447 assertions;
- asserting M6 outcomes such as materialization success, exact-once quotient consumption, output lineage, occurrence embedding, or verifier acceptance in the new M5 identity;
- executing any generated Directional binary, test, benchmark, discovery/list/help/version command, or `ctest` in this Code + Build turn;
- manufacturing success with direct/draft/helper products, expected counters, copied producer decisions, or post-hoc ownership repair.

## 3. Independent-oracle requirements

The new identity must derive its decisive expectations from product structure, not from the function under test:

- derive the set of isolation sheets for a topology region from its owned source-face rows and authoritative per-face sheet labels already retained in the produced pipeline context;
- identify seam certificate ownership by typed region/seam IDs and independently check reciprocity (`forward().inverse() == reverse()`), distinct sheets, and source-face ownership;
- independently recompute the expected canonical periodic relation ID from relation owner region plus generator/cut carrier routes, following the already-reviewed row443 oracle; do not trust stored vector index/order;
- bind at least one reciprocal `PeriodicCut` edge pair to that relation ID and same topology region.

The identity is **non-vacuous only if all six §1 conditions are positively witnessed on one region**.

## 4. Compile/package gate

Use `.github/workflows/agent-compile-reusable.yml` exactly as required by `GitHub_Workflow_Policy.md` and `GMP_COMPILE_POLICY.md`.

The package must contain the new owner executable plus all executables owning selector448 so the successor TB can execute **449 fresh exact-filter processes** from one immutable artifact. Compile evidence must record:

- exact source SHA;
- `runtimeExecution=false`;
- GMP enabled and `gmpxx` + `gmp` present on authoritative generated link commands;
- all required targets compiled/linked;
- clean source status and recursive self-excluding package manifest.

No selector publication occurs in CB1.

## 5. Falsifiers and stop rules

Stop and hand to mandatory Review rather than broadening this turn if any of the following occurs:

1. the committed torus producer does not expose one region satisfying the entire same-subject join;
2. proving the M5 contract requires materialization, occurrence, embedding, output lineage, or verifier authority;
3. the only way to obtain multiple sheets is to inject test-owned sheet labels or mutate the fixture/field;
4. no periodic relation is explicitly owned by the same multi-isolation region;
5. an existing accepted producer row regresses at compile/source-contract level;
6. product code would have to change;
7. any proposed assertion merely combines independent facts from different regions or different fixtures.

A compile failure may be corrected in this Code + Build turn only when the correction is bounded to build/test-authority mechanics and does not cross a falsifier above.

## 6. Exact successor on compile-green

**`M5-CP4-TB1-EXEC`** — artifact-only prepublication gate over selector448 plus the one new focused identity, **449 fresh exact-filter processes**, exact-one selection, zero skips, benchmark 0, immutable postflight. It may not publish selector449 or claim conjunct-8 acceptance. Mandatory successor after execution is **`M5-CP4-TB1-REV`**.

## 7. Reviewing-agent amendment (`M5-DEFN-R2` review) — clarifications, no scope change

1. **Which falsifiers CB1 can evaluate.** CB1 executes nothing, so §5 falsifiers 1 and 4 (whether the torus region exposes the join) **cannot be evaluated in CB1**. They are evaluated by the fresh `M5-CP4-TB1-EXEC` gate and adjudicated by `M5-CP4-TB1-REV`. CB1 may stop on them only if static source reading proves the join impossible, and it must quote the proving source when it does. Falsifiers 2, 3, 5, 6 and 7 do apply to CB1's authoring.
2. **The subject is fixed before runtime.** The subject is `torus_fixture()` / `make_torus_pipeline_fixture()`: the committed torus plus the 18 row408 user hard edges. The only evidence that *a* committed-torus configuration has a multi-sheet region with an internal seam is the never-executed `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`. That test uses the same mesh and field **without** the hard edges. Nothing observed yet shows `torus_fixture()`'s single region spans ≥2 sheets or keeps a non-hard-feature seam; row 240 forbids reinterpreting a hard feature as an isolation seam. A RED is therefore a real possibility. **Switching subject after seeing TB1 results is prohibited.** Any subject change needs a Review-authorized amendment before any new runtime (`LESSONS.md` 170, 177).
3. **A RED must localize itself.** Check the six §1 facts in the order listed, each with an `ASSERT_*`/`EXPECT_*` failure message that names the fact, for example "fact 2: region spans >=2 isolation sheets". A TB1 RED must then identify the first unmet fact without another diagnostic Code + Build cycle.
4. **Record the new row's owner.** Record the new identity's static owner executable and a 449th routing row, `449<TAB><identity><TAB><owner>`, in the CB1 report. `M5-CP4-TB1-EXEC` routes rows 1-448 from accepted receipt `c91a5e2f…1dd7c` and row 449 from that record. Precommitting selector449 bytes remains `M5-CP4-TB1-REV`'s authority.
5. **Leave the ungated identities alone.** Do not modify, gate or delete `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`, `MultiIsolationMaterializationRetainsAllLocalSheets` or the two dormant CB14 identities in this turn.
