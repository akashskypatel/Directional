# P13-j stitched-vertex Review/Definition — same-turn preflight (2026-11-02)

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` — **INCOMPLETE**. This record preserves source-verified static findings, an exact diagnostic plan, and the unresolved decision. It is *not* an adjudication or an authorization for a Code + Build turn.

## Immutable authority and boundaries

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft and unmerged. Entry `STATUS` commit `531ee98476e977f31ee1839992e345eb444428ee`, started `2026-11-02T23:31:04Z`.
- Read-only source snapshot: event/source `f3f91234124731cef85938b67dd0732b40b14180`; run `41546168024`; artifact `13187758198`; outer SHA-256 `25f33d683a5161af3e001b1bac694fd13ef8b10a3f1e54d4a18a0a46adb634e6`, 6116/6116 source-file hashes verified.
- Immutable CB78 package: semantic source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`, artifact `13181887585`, ZIP SHA-256 `076a19de16db5b0d7be3fb7d133c0324383dde319467afb22b3edc99922658e4`, package manifest verified.
- Corrected TB72A gate: 883/883 PASS, membership 964, 81 deferred; registered independent production census: Cylinder PASS, BunnyRandom P13-e RED (`SingularityPortClassCountMismatch;sourceVertex=49`), Vase P13-j RED (`AssemblyRejected/NonManifoldStitchedVertex`). Gate green does not imply Vase production green. Accepted CP2 remains 491/491, stable 66/17/49 debt 1, selector497 unpromoted.
- Authority: `Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md` RA-199 F7 / §RA-199.6. Objective: name the failing stitched vertex, exact source support, incident cells/patches, discriminate between assembly, completion boundary sharing and arrangement, **then** freeze an exact corrective patch.
- **Cross-version source match (re-derived):** streamed the exact immutable CB78 source tarball and independently compared it against the verified head snapshot: `src/geometry/PureQuadCompletion.cpp` SHA-256 `9eb46a71b4f8af85b7b9ccda703606fe39dd4d7eb61a67d10e00ff5998f45476`, `src/geometry/PatchDescriptor.cpp` `108e5481fe85ecafa566d4a14f089afbf00956f8e543fbbc8b0c5f176f31f491`, and `DESIGN.md` `d6d3ba7fa4ecbbf29d271699253c0165a7774b6b188f2b762a55eda6b9d7e289` — **all byte-identical** between compiled CB78 semantic source and review snapshot.
- No source, test, fixture, selector, benchmark or build mutations; no new compiled or production runtime evidence. This Review/Definition turn may not substitute speculation for the required witness.

## Independently verified static facts

1. `src/geometry/PureQuadCompletion.cpp:3260` builds an assembly from completed patches. In `resolved_stitch_identity` (~2838), shared boundary occurrences take `patch.boundaryNodeIdentities[boundaryIndex]`, if valid; generated interiors have patch-local ownership.
2. `stitch_pure_quad_patches` (~3390–3510) maps patch-local occurrences into a global vertex row keyed by `PureQuadStitchIdentity`. A repeated key requires overlapping owner-validated typed-authority certificates and positions within the configured tolerance; occurrences are saved in `PendingOutputVertex::provenanceCandidates`. These checks establish typed support compatibility, **not a connected output fan**.
3. The routine rejects duplicate global quads and edges incident to more than two quads, then constructs edge/face incidence. At ~3810–3854 it walks the quads incident to each stitched vertex using **only shared edges touching that vertex**. If `reached.size() != incidentSet.size()`, it returns only `NonManifoldStitchedVertex`, without vertex index, identity, patch owners, local quads, fan-component partition or source support.
4. `src/geometry/PatchDescriptor.cpp:3046` / ~3222 calls the stitcher, and later surfaces the assembly failure as `AssemblyRejected`. RA-199 independently observed two different Vase networks hitting this same terminal class; that proves a recurring failure stage, **not the underlying owner**.
5. A stitched vertex can pass every earlier key/typed-authority/edge-count check while its link contains multiple edge-disconnected incident-quad components (for example two patches sharing a vertex but no incident edge). The present evidence does not distinguish a false identity equivalence, a missing matched boundary edge, or invalid incoming arrangement sectors.

**Current disposition:** exact failing global vertex number, original source support, first contributing patch/cell, and responsible producing stage **NOT ESTABLISHED**. No patch, test expectation, regression acceptance, or successor Code + Build identity is frozen.

## Required bounded discriminating witness (scratch diagnostic; no production edit)

At the **first** `NonManifoldStitchedVertex` rejection, before discarding `pendingVertices` and `uniqueFaceOwners`, extract one deterministic, compact record keyed by the failing global row:

1. **Identity/source:** global row; full canonical stitch identity (kind, values, topology regions, isolation sheets, support faces), resolved authoritative identity, final typed-authority certificate, canonical source-entity type/ID, source-face/barycentric support, and all sorted `provenanceCandidates` with (patch index, domain identity, patch owner, local row, local vertex, source chart). Do not replace exact keys with position proximity.
2. **Fan partition:** sorted incident global quad IDs and the corresponding `CompletedFaceOwnershipRecord` (patch/local quad, ordered global quad, source-support lineage), the two incident edges at each corner, exact shared-edge adjacency, and *all* connected components of the vertex-link graph. Record whether each link component is a path, cycle, branching or repeated-edge walk, and incident boundary edge counts. Preserve the output as a diagnostic artifact only, not an accepted mesh.
3. **Upstream comparison:** for each pair of fan components, compare (a) source entity + sheet/chart-sector equivalence using the authoritative `SourceChartTransitionGraph`, (b) intended boundary-side and ordered subdivision ownership on completed patches, and (c) source arrangement node/cell sectors and originating arcs. Identify the earliest stage at which the two claims became inconsistent.
4. **Cross-checks:** repeat the same capture against the immutable CB78 Vase case; verify Cylinder stays a connected-fan positive control and BunnyRandom stays at its distinct P13-e predecessor failure. If a scratch perturbation or later Code + Build regression is used, prove its negative case actually fails with the expected witness. Require stable canonical identity across deterministic replay/face-row permutations; do not infer equivalence from changed ordinal row numbers.

## Decision table — select only after the witness

- **Assembly owner** iff patches have compatible matching boundary edges and source chart sectors, but assembly maps distinct canonical incident-fan identities into one global vertex (or otherwise loses correct incidence). Correct the assembly identity/adjacency *at the shared source*, not by suppressing the validator.
- **Completion-boundary sharing owner** iff incoming arrangement/source sectors are correct but completed patches disagree on shared boundary edge subdivision, identity or ordered adjacency, yielding disconnected fan components. Correct patch boundary authority or completion with a guarded consistent interface.
- **Arrangement owner** iff incompatible sectors, repeated node ownership or missing edge relationships already exist in the authoritative arrangement before completion. Correct the original construction; no assembly-stage coordinate merge or post-hoc fan repair.
- If all evidence is still ambiguous, record competing hypotheses and a narrower follow-up diagnostic. In every case preserve fail-closed topology, exact source provenance, hard rails, deterministic order, existing validators, and all accepted selector bytes.

## Continuation and closeout accounting

- **Next action, same canonical turn:** perform the focused scratch witness capture using exact CB78 source and Vase input, derive the owner from the measured fan components, then issue a falsifiable exact patch and bounded separate CB successor only if justified. Do not start P13-e successor or edit production semantics inside this Review turn.
- **No production tests/builds run by this chat.** Local inspection of the existing package included listing test identities only. `review_check.py boundary` and true in-sync origin verification were not executed; do not claim those checks passed.
- Current in-chat source snapshot trigger `.agents/connector-triggers/source-snapshot/p13-assembly-20261102.txt` is temporary and must be retired before closeout. The durable dispatcher/request slot and `workflow-mailbox` history must remain.
- Tool-use conservation pre-read gate miss: early small handoff/TODO/policy reads happened before formal snapshot selection; subsequent iterative inspection used the verified exact snapshot. This is a workflow-policy deviation, not evidence about the product.
- No accepted selector, stable regression, roadmap milestone, architecture amendment or production acceptance changes are warranted by the static preflight.

## Same-turn continuation — 2026-11-02

- Resumed from the authoritative `STATUS` beacon; did not advance to the unknown corrective successor.
- Re-inspected the exact source snapshot: the stitched-vertex validator builds `edgeFaces`, then for each vertex BFSes incident quads through edges `(vertex, previous)` and `(vertex, next)`; `reached.size() != incidentSet.size()` is the sole trigger for `NonManifoldStitchedVertex`. The rejection still carries no failing vertex or patch-owner identity. This confirms that the required source-specific witness cannot be inferred from this error alone.
- Ran `python3 .agents/Directional/tools/review_check.py boundary` against the **extracted source snapshot**, not an authenticated Git checkout. It reported no product/test/fixture/build or selector mutation, but **overall FAILED**: missing Git ancestry for durable rewrite baseline `8b7299b43` and source verification of `Future_Chat_Session_Handoff.md`, `ORIENTATION.md`, `Regression_Root_Cause_Tracker.md`. The source archive excludes `.git`, so these failures are verification-environment limitations, **not proof the boundary passed**. A genuine repository checkout with ancestry is required for authoritative review-check verification.
- The required first-failing-vertex production diagnostic remains uncollected. No root-cause owner, precise corrective patch or CB successor is justified. No runtime tests or build were executed. Keep this Review/Definition turn open for the exact immutable CB78 diagnostic, rather than inventing an implementation.

## Same-turn continuation — 2026-11-03

- Verified the repository beacon still authorized this exact unfinished P13-j Review/Definition turn; updated its attempt timestamp without advancing to successor work.
- Re-fetched the review preflight and enumerated source-snapshot workflow run `41546168024` artifacts. Confirmed the immutable source snapshot artifact `13187758198` remains listed, alongside workflow schema and publisher logs; **none** of these are a failing-vertex runtime witness. This establishes that re-downloading the same snapshot will not independently resolve the attribution question.
- The GitHub connector currently exposes workflow run/artifact reads and reruns, but no workflow-dispatch action in the available tool set. No unauthorized mutation of reusable CI workflows or production code was attempted. An actual CB78 Vase execution with a temporary diagnostic capture is still necessary. No build, tests, or new witness executed in this attempt.
- Unresolved next action: capture the first rejected stitched vertex with canonical identity, all provenance candidates, incident-face ownership, and fan components, then cross-check authoritative arrangement/completion sectors to determine the earliest invalid equivalence. Keep fail-closed validation and this same canonical turn until evidence supports a precise implementation handoff.
