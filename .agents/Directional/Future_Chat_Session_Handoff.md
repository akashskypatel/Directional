# Future Chat Session Handoff

## Mandatory next turn

Run **M1l Phase-Front Cell Topology-Region Consumer — Code + Build only** under:

`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`

Repository: `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Draft PR #8 stays open, draft, and unmerged. Product gate **G4 topology-distinct completion and singularities** remains active. Architecture slices M1a through M1k are immutable accepted. Review policy is `never`.

M1l is bounded to:

`SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.

Migrate only cell-owned topology-region identity to checked `TopologyRegionId`. Preserve `SurfaceTopologyRegion::id`, raw region-by-face maps, certificate/periodic/bounded-disk/occurrence/lineage region schemas, topology-region discovery/partition/numbering, accepted component/sheet and edge-region authority, M2-M6, fallback/recovery, optimization, and G4 behavior.

This is **Code + Build only**. Execute no generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input. Exactly six M1l production-path contracts compile only. Expected following runtime authority is producer **226**, M1l **6/6**, required-green **211/211**, plus all entering preservation gates.

Current immutable report:
`.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Authoritative next plan:
`.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`.

## Current immutable authority

M1k implementation `b9181364926cea840e9cb50da21fe721f33fd874` is immutable accepted from exact Code + Build artifacts `9079318682 / 9079319269` and authoritative artifact-only runtime `31433794426 / 93603203081`. Runtime evidence/log artifacts are `9080245848 / 9080246452`.

Acceptance authority:

- producer discovery **220**;
- M1k focused **6/6**;
- M1j-M1b focused preservation green;
- M1d route witnesses **3/3** and M1c transition counterexamples **3/3**;
- required-green producer **205/205**;
- validation **77/77**, M1a **14/14**, T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean;
- all eight historical/deferred red classes unchanged;
- exact **68/68** immutable postflight.

Strict-validator timing sampled **10/10 pass** in fresh processes but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect. Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase remains bounded safety-only at 60 seconds.

No stable product regression event or recurrence was created. Historical totals remain **34 events / 14 categories / 20 recurrences**; `PR8-R034 / G4-R007` remains active.

Historical milestone and acceptance details are maintained in `.agents/Directional/CHANGELOG.md`, not in this handoff.

## Standing product and regression state

- Product gate **G4 topology-distinct completion and singularities** remains active and separate from architecture migration.
- `PR8-R034 / G4-R007` remains active under production artifact `9031804178`.
- Direct torus remains **0/3** after 192 completed quads with 241 `LocalSheetMismatch` issues.
- Historical exact torus remains `InvalidHardRailPairing`.
- Persistent blockers remain `G4-B001` through `G4-B004`.
- M1a through M1k architecture acceptance does not claim G4 product completion.

## Resume-critical execution lessons

- Use the exact accepted M1k source/package authority above; later documentation/control-plane commits are not runtime evidence commits.
- Python `zipfile.extractall` did not preserve packaged executable mode bits during one local validation attempt. Immutable runtime extraction must use a method such as CLI `unzip` that preserves the archive's natural executable attributes; never `chmod` or repair the package.
- A single local Cylinder harness stall did not reproduce in immediate bounded local execution or controlled remote runs. Do not add product workarounds for it without new product evidence.
- The first remote M1k semantic run was green but its evidence upload used the wrong temporary-root path. Future workflows must use `${{ runner.temp }}` / `$RUNNER_TEMP` consistently.
- M1b focused names belong to the validation executable; zero-selected filters are orchestration errors and never semantic passes.
- Temporary Actions YAML must not use an unindented shell heredoc inside a block scalar. Prefer a committed helper payload or indentation-safe script when a temporary workflow needs Python.
- For temporary path-filtered workflow cleanup, remove or disable the workflow first, then delete its trigger marker/payload. The opposite order retriggered redundant run `31343858635` during M1d cleanup; that run is not acceptance authority.

## Handoff / changelog boundary — mandatory

`.agents/Directional/CHANGELOG.md` is the durable historical record for completed changes and immutable acceptance checkpoints. Maintain it separately from this handoff.

- The handoff contains only the mandatory next action, current immutable authority, live blockers, resume-critical lessons, and durable operating policy needed by a new agent to continue correctly.
- Do not accumulate completed milestone narratives, old artifact tables, superseded turn summaries, or historical acceptance logs in this handoff.
- When a completed turn creates a durable implementation or acceptance change, add or update the corresponding newest-first entry in `CHANGELOG.md` using its documented style before removing historical detail from the handoff.
- Preserve exact implementation commits, artifact/run identities, stable regression IDs, failure classifications, and material operational lessons in the changelog when they cease to be resume-critical.
- Keep unresolved or immediately actionable information in the handoff until it is no longer needed to resume the next turn correctly.
- A changelog entry supplements authoritative per-turn reports; it does not replace the exact evidence report while that report is the current immutable authority.

## Durable `.agents/Directional` cleanup policy — mandatory

This section is durable handoff policy and must remain in every future rewrite of this handoff unless the user explicitly changes it.

- Long-running or resource-heavy tests and benchmarks may be executed using narrowly scoped GitHub Actions workflows when local or connector execution is impractical or would exceed interactive resource limits. This does not relax turn separation: runtime tests and benchmarks remain Test + Benchmark work, must consume exact immutable artifacts when artifact-only validation is required, and must not rebuild, relink, regenerate, or edit product/test content during that turn. Temporary workflows must follow `GitHub_Workflow_Policy.md`, retain unconditional detailed diagnostic logs plus exact source/artifact authority, and be removed or disabled before their trigger markers/payloads are cleaned up.
- Keep durable project authority: `DESIGN.md`, `REORIENTATION_PLAN.md`, `Surface_Cell_Backend_Remediation_Plan.md`, `Surface_Cell_Architecture_Independent_Design_Review_Report.md`, `Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`, `GitHub_Workflow_Policy.md`, `Regression_Root_Cause_Tracker.md`, `PR_8_Regression_Audit_Inventory.md`, `CHANGELOG.md`, and this handoff. `TODO`, `MILESTONE_G_TODO.md`, and `tests/TESTING_STRATEGY.md` are also durable even though they are outside this directory.
- In addition to the durable set, retain only the **current authoritative evidence/report** and the **single next-turn plan** needed to resume work. Do not accumulate superseded per-turn Code+Build plans/reports, Test+Benchmark plans/reports, review plans/reports, evidence indexes, machine summaries, or temporary workflow payloads once their authoritative facts have been folded into durable/live records.
- **Every Test + Benchmark turn must begin with stale-evidence cleanup**: remove prior Test+Benchmark evidence and other superseded turn documents from `.agents/Directional` after verifying their accepted facts, stable regression IDs, artifact identities, and unresolved blockers are already represented in the durable trackers/changelog/current authority.
- **Every Test + Benchmark turn must end by replacing stale evidence with current evidence**: retain the newly authoritative Test+Benchmark report plus exactly one next Code+Build plan; remove the consumed Test+Benchmark plan, the superseded preceding Code+Build report/plan, and any older turn evidence. Never delete the current immutable source/package authority until its facts are captured in the new report/live handoff/changelog as appropriate.
- Raw machine-readable evidence that is still the sole authority for a claim is not stale. Fold its necessary facts into the current authoritative report/live tracker/changelog before deleting any repository-side summary. External GitHub Actions artifacts may remain by retention policy; repository cleanup concerns stale checked-in documents/evidence, not immutable artifact history.
- Never remove, weaken, consolidate, reinterpret, or replace a durable document or mandatory handoff instruction merely to reduce file count. Durable-document changes must be additive or narrowly corrective unless the user explicitly authorizes broader replacement.
- After cleanup, audit retained documents for references to deleted stale files and repair those references before turn closeout.

### Durable-information mutation prohibition — user authorization required

This policy is durable and must remain in every future rewrite of this handoff unless the user explicitly changes it.

- Destructive edits to durable information are prohibited unless they are within the approved documentation scope of a Review turn explicitly authorized by the user, or the user explicitly authorizes the destructive edit and its scope. No other turn type—and no general instruction to update, clean, condense, reconcile, keep concise/current, or remove stale evidence—grants that authority.
- A destructive edit includes deleting a durable document; removing findings, rationale, decisions, invariants, design or architecture detail, policies, acceptance criteria, historical evidence or provenance, stable IDs, artifact identities, failed-attempt lessons, unresolved blockers, or resume guidance; replacing detailed authority with a summary; weakening or obscuring prior meaning; or moving information without a durable, traceable replacement.
- Protected information includes design, architecture, policy, remediation and roadmaps, plans, audit/review findings, regression/root-cause history, testing strategy, workflow/process rules, TODO/handoff recovery state, and any other record whose purpose is durable project memory.
- Routine stale per-turn evidence cleanup applies only to records expressly classified as temporary after all necessary facts have been preserved. It never authorizes destructive edits to protected durable information.
- Without the required authorization, edits must be additive or narrowly corrective and must preserve all prior durable meaning. If classification or authority is uncertain, stop and ask the user before editing.
- Before an authorized destructive edit, inventory the information at risk, define the exact authorized scope, and verify the resulting diff against that scope.

## Core references

- `.agents/Directional/Architecture_M1k_Phase_Front_Edge_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`;
- `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Code_Build_Plan.md`;
- `.agents/Directional/CHANGELOG.md`;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Regression_Root_Cause_Tracker.md`;
- `.agents/Directional/GitHub_Workflow_Policy.md`;
- `tests/TESTING_STRATEGY.md`;
- `TODO`;
- `MILESTONE_G_TODO.md`.
