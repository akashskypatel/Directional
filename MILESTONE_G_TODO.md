# Milestone G Production Readiness TODO

Last updated: 2026-08-05

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **P5-TB36 artifact-only R2E8 Test + Benchmark**.
- Next turn: **P5-R2E9 canonical boundary wrap-sector and bounded rail-orbit chart publication Code + Build**.
- R2 remains open. Do not advance to R2F or R3.

## P5-TB36 authority

- Exact source: `478d058ab2060a1a02a1e4ca3bfc0e6625fa8047`.
- Artifact: `8944910920`, SHA-256 `5b93e86db0ddccf4ca3eba2e9b53e6523f02d7ef70809aa8eb67b91f6e9bef39`.
- Manifest **13/13**; package files **14**; staged fixtures **26**; recursive submodules **9**.
- Artifact-only execution; no configure, rebuild, relink, patch, regeneration, or repository source/test/fixture/validator/workflow modification.
- Evidence SHA-256: `af3747b1238a01802a4fc158032451a505cbeb224c51601d888e390b6fd01096`.

## Results

- [x] source chart + validator **17/17**;
- [x] recovery authority **9/9**;
- [x] feature/barrier **8/8**;
- [ ] graph-dependent **5/6**;
- [ ] R2 focused **13/16**;
- [ ] Milestone D **5/7**;
- [ ] Phase 16 **45/47**;
- [x] Phase 17 **26/26**;
- [x] Phase 18 **57/57**;
- [ ] Phase 14–18 **241/244**;
- [ ] Phase 20 **46/48**;
- [ ] complete suite **603/625**, 22 failures.

Compared with P5-TB35, exactly six Phase 17 failures close naturally. No new failure appears and no other failure closes.

## R2 status

- [x] degree-two and genuine four-disk boundary partitions remain passing;
- [x] source-row and whole-orientation identity remain passing;
- [x] planar direct incidence now publishes and reaches topology validation;
- [ ] planar omits the required cyclic-wrap interior sector and closes Euler `0` rather than `1`;
- [x] hard rail retains one exterior and two bounded disks, complete ownership, and distinct bounded rail-twin owners;
- [ ] hard-rail authoritative embedding/chart support remains invalid;
- [x] Phase 17 restores from **20/26** to **26/26** without Phase 17 changes;
- [ ] cylinder and bunny remain independent;
- [ ] direct plane, seam, close-sheets, and cylinder production remain incomplete;
- [ ] direct bunny remains deterministic but produces zero arrangement cells and zero quads.

## Required P5-R2E9 work

- [ ] enumerate canonical cyclic R1 fan pairs independently of chart-filtered angle-list truncation;
- [ ] include vector wrap and resolve every pair to one exact chart corner;
- [ ] exclude the independently proven exterior pair once and only once;
- [ ] require complete local incoming/target bijection and planar Euler-one disk closure;
- [ ] carry each selected hard-rail root through the complete bounded orbit;
- [ ] materialize bounded-cell authoritative source-chart support from the accepted orbit root;
- [ ] retain full provenance separately and keep the embedding validator unchanged;
- [ ] preserve all accepted R2 and Phase 17 authority;
- [ ] leave cylinder, bunny, FlowRep, completion, optimizer, fallback/recovery, and downstream validators out of scope;
- [ ] compile only the four approved targets and execute no project binary.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB36_Artifact_Only_R2E8_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E9_Canonical_Wrap_Sector_Rail_Orbit_Chart_Code_Build_Plan.md`
- `benchmark-results/p5-tb36-summary.json`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- durable design, reorientation, remediation, and workflow-policy documents
- `TODO`

Every completed turn ends with a new final PR #8 handoff comment after all documentation and PR metadata writes.

P5 remains open.
