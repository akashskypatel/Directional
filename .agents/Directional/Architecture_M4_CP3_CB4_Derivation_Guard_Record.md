# M4-CP3-CB4 Derivation Guard Record

**Status:** HALTED / PRE-MUTATION DERIVATION GUARD / REVIEW REQUIRED
**Turn:** `M4-CP3-CB4`
**Execution mode:** canonical Code + Build, stopped before semantic mutation
**Normative contract:** `Architecture_M4_DEFN_Frozen_Definitions.md` §17
**Frozen plan:** `Architecture_M4_CP3_CB4_Code_Build_Plan.md`
**Accepted runtime authority remains:** package119 / selector394 **394/394**

## 1. Verdict

CB4 executed the mandatory pre-mutation derivation census and **stopped before any production, test, selector, benchmark, CMake, or reusable-workflow semantic mutation**.

The stop is required by CB4 plan §3: accepted upstream products do not publish enough exact ordered source-path authority to derive one exact §17 A3 `ConformitySpanInput` for every full A2b arc. The decisive case is a `GlobalTopologyArcKind::Cut` arc split by an exact trace/cut crossing. A2b construction knows the exact crossing parameter and the synthetic `NetworkNodeId` binding, but that binding is construction-private and is not retained in the published `SurfaceCutGraph` or `GlobalTopologyArc` product.

Using the full source edge for every split cut arc, reproducing construction-private synthetic-node numbering, or reconstructing an endpoint from floating geometry would invent a new convention. CB4 plan §3 explicitly forbids doing that in Code + Build and requires return to Review.

No compile/package and no Directional runtime were executed. CB4 is therefore **not complete**, no package120 is created, and no TB2 plan is authorized.

## 2. Exact inspected authority

- semantic predecessor before the source-snapshot marker: `b315fea406c04fa65ff7c9a19f3886054470b16d`;
- exact source-snapshot control head: `128f7d738382eb4957b5680de2fbcab8d2953c26`;
- source-snapshot workflow run: `34630928953`;
- source-snapshot artifact: `10275967628`;
- provider ZIP SHA-256: `70bd27c980df85fcd1c86efca5d2887e3caf323ec565e8dfad405b3776297ee2`;
- inner `source.tar.gz` SHA-256: `f14658d30bc7f1332aade58cbb111f7d03ee03041c1610e30788e5e6ac538897`;
- snapshot metadata: **5,258 files / 94,604,070 bytes**;
- snapshot runtime boundary: `runtimeExecution=false`.

The only difference between the semantic predecessor and snapshot control head is the source-snapshot trigger marker; no product/test/build semantics changed before the census.

## 3. Mandatory census

The six frozen census classes are complete:

| Class | Found | Classified | Require change if guard is resolved |
|---|---:|---:|---:|
| A2a / A2a′ / A2b construction + publication | 9 | 9 | 1 cutover site |
| Production ingress capable of carrying A2b/A3 into A4 | 3 | 3 | 1 ingress structure |
| A4 shared-boundary subdivision selectors/materializers | 8 | 8 | at least 5 |
| Hard-rail grouping/pairing / `support_key` consumers | 10 | 10 | 7 |
| A2b↔A4 region-domain crossings | 4 | 4 | 2 |
| Baseline/span/breakpoint construction + validation APIs | 9 | 9 | 2 missing production call sites |

No shared-boundary consumer or region-domain boundary remained unclassified. The guard fails for **missing published exact upstream authority**, not incomplete census coverage.

## 4. Decisive exact-path publication gap

### 4.1 Published A2a′ authority is insufficient for split cut arcs

`SurfaceCutGraph` publicly exposes the selected cut-edge set plus its certificate/digests (`include/directional/geometry/SurfaceCutGraph.h:390-396`). It does not publish exact cut-crossing positions or an exact `NetworkNodeId -> source-edge parameter` map.

### 4.2 Published A2b arc authority drops the exact split parameters

`GlobalTopologyArc` publishes arc kind, endpoint node IDs, optional mandatory edge / trace / cut edge, trace segment range, and source-face support (`include/directional/geometry/GlobalTopologyPlan.h:43-55`). It does not publish ordered exact support pieces or exact endpoint parameters.

During A2b construction, `src/geometry/EmbeddedGraphTopology.cpp:262-350` obtains exact cut-crossing parameters from `FieldAlignedCandidateTraceSegment::entryPoint.parameter` and binds them to synthetic `NetworkNodeId`s. Split cut arcs are then emitted between those nodes at `:569-600`. When the public `GlobalTopologyArc` is materialized at `:618-622`, the exact crossing-parameter binding is no longer represented.

Therefore two or more full A2b `Cut` arcs may refer to the same source cut edge while owning different exact subsegments, yet the accepted published products do not expose the exact subsegment endpoints needed by §17.3/§17.4.

A similar publication problem exists for split `Mandatory` arcs, but the `Cut` case alone is sufficient to fail the frozen guard.

## 5. Classified downstream cutover surface

If Review supplies/fixes the missing exact path authority, CB4 still has the already-classified implementation surface:

- construct and independently validate one production A3 plan immediately after A2b publication in `RemeshPipeline.cpp`;
- extend the tracing ingress, which currently carries `SourceTopologyRegions`, field transport, and A2a but no A2b/A3 authority;
- explicitly map or rebase `NetworkRegionId` to the A4 `TopologyRegionId` domain;
- replace target-derived shared-boundary subdivision/materialization with exact A3 span/ordinal breakpoints while preserving truly local transverse resolution where proven independent;
- replace floating `HardRailPairKey` / `support_key` ownership with exact A3 shared-boundary identity;
- retain A4-local route reversal, `family`, and `advanceSign` consistency checks required by frozen §17.11;
- add the frozen focused cutover tests only after the authority contract is resolved.

No implementation of these items was attempted after the guard failed.

## 6. Non-effects and accepted authority

This stop does **not** invalidate any accepted predecessor evidence:

- package119 / selector394 stays accepted at **394/394**;
- historical package117 / selector382 remains retained framed CP1/CP2 authority;
- stable regression accounting remains **47 events / 14 categories / 33 recurrences**;
- produced-witness debt remains **5**;
- `M4-CP3-TB1-R1-REV-OBS-01` remains non-blocking and is still explicitly deferred from CB4;
- CP3 remains open;
- PR #8 remains open, draft, and unmerged.

## 7. Required successor boundary

**Exact next: independent `M4-CP3-CB4-REV` — Review + Plan, runtime-free.**

That turn must independently reopen this census and accepted upstream product shapes, decide the authoritative way to publish exact ordered support for every full A2b arc (including split `Cut` and `Mandatory` arcs), adjudicate whether §17 or an upstream frozen product contract requires amendment, and issue the successor Code + Build plan.

Do not resume the A3→A4 cutover, compile a successor package, or author TB2 until Review freezes that authority. This record is the Code + Build stop boundary; the current session must not cross into Review.
