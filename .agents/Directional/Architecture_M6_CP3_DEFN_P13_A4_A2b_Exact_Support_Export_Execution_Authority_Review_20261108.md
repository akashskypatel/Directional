# M6-CP3 P13 A4/A2b — exact source-support export correction and Review execution gate (2026-11-08)

**Canonical turn:** `M6-CP3-DEFN-P13-A4-A2B-DISC-PRODUCER`. **Source:** verified immutable snapshot `c54184c3caab9dfd37eab6653ae923e0a5c733e9`, workflow 42452191280, 6,234 source SHA-256 entries. This is a continued **Review**, not an implementation or a runtime/acceptance report. Read together with the [previous extraction seam](Architecture_M6_CP3_DEFN_P13_A4_A2b_Readonly_Authority_Extraction_Review_20261108.md) and [RA-213](Architecture_M6_CP3_DEFN_P13_Vase_Producer_Path_Adversarial_Review_A2b_Disc_Construction_20261108.md).

## E1 — Original scratch export loses source-support identity

The prior review-only `review_vase_a2b_a3_export.py` prints `authority::support_kind(x.carrier)` in both `ARCPIECE` and `SPANPIECE`. That emits only Vertex/Edge/FaceInterior, **not** the carrier's canonical `SourceVertexId`, `SourceEdgeTopologyKey`, or `SourceFaceTopologyKey`. Source authority explicitly distinguishes these carriers in `include/directional/authority/SourceSupport.h:13-36`; `include/directional/authority/ExactSourcePath.h:37-44` includes the entire `SourceSupport` in each `ExactSourceSupportPiece`'s identity. The old Python oracle compared only the serialized rows. If both A2b and A3 mistakenly named the same *different* edge, the old oracle had no carrier-identity observation to reject it. It also checked individual pieces but not their shared consecutive endpoint.

**Correction — off-branch scratch only:** `review_vase_a2b_a3_export_v2.py` serializes canonical carrier tokens `V,<vertex>`, `E,<u>,<v>`, `F,<u>,<v>,<w>` without changing the TSV row layout; the companion `verify_vase_a2b_a3_export_v2.py` verifies each exact endpoint is supported on that simplex, canonical rational parameters, and consecutive piece endpoint equality. The A2b/A3 exact piece list equality is retained. This is **not** a new production API, validator, test or accepted A4 conformance result.

## E2 — Independent negative controls

Run: `PYTHONPATH=<scratch-folder> python <scratch-folder>/test_export_oracle_nonvacuity_v2.py` (one pastable command with real paths substituted).

Observed locally on the **scratch checker only**:
- Single-piece synthetic valid stream: PASS.
- Two-piece valid exact source-edge path: PASS.
- Seven individual mutations: all rejected — wrong face orbit, nonterminal breakpoint, reversed A2b walk orientation, duplicate incidence, zero target metric, missing export terminator, and one-sided wrong source carrier.
- Two paired/structural mutations: both rejected — synchronized wrong carrier on A2b and A3, and a broken joint between consecutive path pieces while both sides report the same broken path.
- Python `py_compile` PASS; generated overlay reproduced from the checked-in test file at source SHA-256 `48bd985008a3803b6cdcadaa90ecf244f980ad4c5e20d76c56da2e0419935a1e`.

Reproducibility: all v2 scratch source files, generated off-branch C++ overlay, stdout, and SHA-256 manifest are preserved in `Directional_A4_A2b_Exact_Support_Export_Review_20261108.zip`. The C++ overlay SHA-256 is `b055f1981613ff29ba8efff02be70a91851bbd4bf1c84e1a8f391389cafd89e6`. **No C++ compiler, project executable or runtime test was invoked**. Thus the C++ type compatibility, expected stage-3 injection, actual A2b walks/face fragments, exact A3 breakpoint schedule and full A4 gates remain **UNVERIFIED**. Even the corrected checker validates only a subset of source attachment: it does not derive the original source mesh, trace direction field, or complete field-fragment geometry.

## E3 — Canonical authority conflict blocks the requested full Review exit

`.agents/Directional/REVIEW_TURN_POLICY.md` §4.3: a Review is runtime-free and may mutate no product, test, fixture, selector, benchmark or build source. `.agents/Directional/Turn_Cadence.md` retains distinct Code + Build (compile/package without Directional runtime) and Test + Benchmark (artifact-only runtime) gates. Yet RA-213 §4 step 58 and the current `Future_Chat_Session_Handoff.md` require a Claude scratch **build** and the measurement of an actual A3 maximal-chain re-solve, per-disc A4 Vase construction and every quality gate before freezing implementation slices. The accepted `.github/workflows/agent-operation-dispatcher.yml` has no custom scratch-overlay operation; `GitHub_Workflow_Policy.md` requires all project compiles through `agent-compile-reusable.yml` and prior schema validation for any new workflow. Directly injecting scratch source into the working branch's tests would violate the Review boundary. The earlier RA-213 scratch build does not itself amend the policy.

**Disposition:** The shortfall is not a tool safety-check refusal, Github outage, or failed GMP build. It is a specific governance/authority conflict over the demanded scratch runtime evidence. Ask the user for **one of** (a) a narrowly scoped authorization for off-branch, non-accepting Review scratch execution using the approved GMP compilation path and separately recorded runtime, without modifying production/tests/fixtures/selectors, or (b) an authorized distinct diagnostic Code + Build followed by artifact-only Test + Benchmark before this Review may finish. Do not silently invent a scratch workflow or change reusable workflow permissions. The separate D6 choice is still pending: recommend considering expected D1 `QualityRelaxed` with named quality exceptions, **but change no acceptance gate without explicit user approval and measurements**.

## Carried exact remaining obligations

1. Compile/execute the corrected scratch exporter only under resolved authority and independently verify the resulting true Vase A2a′ face-fragment owners, three A2b oriented disc walks and A3 exact support-piece breakpoints.
2. Define a segmentation-stable D5 maximal Mandatory-chain geometry metric and positivity contract before any true A3 re-solve; previous exact-rational counterexample rules out naive piece-index reuse.
3. Produce source-attached A4 per actual A2b disc with exact A3 breakpoint sharing, central port valence, and full geometric/field/density/quality measurements. The prior 7,212-quad and surrogate three-disc experiments are **not** compliant witnesses.
4. Independently verify A4→A3 occurrence ownership and retain typed `not exercised` for the four existing non-A3-consuming producers. Freeze no new CB slice until D4/D5/D6 and runtime evidence are resolved.

**Protected state unchanged:** accepted CP2 491/491, stable 66/17/49, debt 1, ledger v5 81 deferred, TB85 908/908 unpromoted, CB102 withdrawn. No source/test/selector/workflow mutation. Review remains unfinished, with no authorized implementation successor. Do not mark complete, reinterpret failed checks as passes, or claim actual Vase runtime evidence.
