# M4-CP3-CB1 derivation-guard record

**Status:** `HALTED / STOP-GUARD / NO SEMANTIC MUTATION / NO COMPILE / NO RUNTIME`

## Authority inspected

`M4-CP3-CB1` began from accepted M4 authority package117 / selector382. The production-source audit used semantic source `02643ac69cc0efabdeb987ea6043d9c5228f45e4`; the ChatGPT-Web source-snapshot control marker advanced the branch only to event SHA `5898dd5609cb9c4e41fb39a26ab5c8084f61fd09`. Snapshot workflow run `34544866975` completed successfully and produced source artifact `10178644987` (outer artifact SHA-256 `1bff74435e7a68fb8b48b359b2d24173783633b641178c4f4e085d7f0406ca3b`). Snapshot metadata records `runtimeExecution=false`.

The hard guard in `Architecture_M4_CP3_CB1_Code_Build_Plan.md` required a **unique source-derived mapping for every production A2b boundary occurrence** to:

1. `ConformitySpanId` and exact ordered `ConformitySupportPiece` path;
2. `ConformityFamily U|V`;
3. `ConformitySign +|-`;
4. incidence orientation relative to the canonical span direction.

The plan requires an immediate stop before production/test/selector/CMake semantic mutation if any occurrence cannot derive all four items from already accepted A0-A2b authority without cross-face raw `FieldBranch` comparison, tolerance, approximate geometry, or an invented convention.

## Guard result — FAIL

The universal mapping is **not uniquely representable from the accepted A0-A2b products** because production A2b contains `GlobalTopologyArcKind::Cut` arcs whose accepted cut authority has no field-family/sign binding.

### Evidence

- `GlobalTopologyArc` stores `kind`, endpoint nodes, optional mandatory-edge / trace / cut-edge provenance, segment range, and source faces. It stores no conformity family or sign (`include/directional/geometry/GlobalTopologyPlan.h`).
- `EmbeddedGraphTopology.cpp::build_arcs(...)` constructs every cut arc directly from a selected `SurfaceCutGraph` source edge. It splits the exact source edge at exact trace crossings, sets `kind = Cut` and `cutEdge = ...`, then publishes the arc. No field branch, family, or sign is selected or bound there.
- `SurfaceCutGraph` publishes selected source cut edges plus cellularity/certification evidence. Its candidate classes are topological (`Admissible`, `MandatoryAlreadyPresent`, `TraceInteriorCrossing`); its public cut-edge product has no U/V or +/- field label.
- `FieldTransportAtlas` does publish exact canonical branch topology and boundary-flow information for the four branches of each source-face frame, but an arbitrary cellularizing source cut edge has no accepted rule selecting one of those branches as *the* conformity family/sign. The cut need not be a field-aligned curve. Choosing the nearest arm, comparing raw branch integers across faces, or adding an angular/tolerance rule would create new semantics and is explicitly forbidden by the CB1 guard.
- This is not an unreachable kind. The accepted torus A2a'/A2b witness has `cutEdgeCount=28`, `torusRegionCount=4`, and actual graph `V/E/F = 72/76/4`; CP3's current gating torus therefore contains real cut-backed region-boundary arcs that need A3 incidence semantics.
- CP1/CP2 unit fixtures do not establish the missing production derivation. `make_known_feasible_input(...)` in `tests/GlobalConformityPlanTests.cpp` synthetically assigns every incidence `ConformityFamily::U` and alternates sign by boundary ordinal. That is a test-local known-feasible input, not accepted production A2b field/topology authority.
- The preceding CP2 review explicitly identified this ambiguity and required CB1 to stop if the derivation was not uniquely representable. The audit confirms that stop condition.

Span identity is available exactly as `ConformitySpanId::from_network_arc(boundary.arc)`, and boundary orientation is already explicit in `GlobalTopologyRegion::boundary`. Exact support paths also have source-backed construction routes for mandatory/trace/cut provenance. Those partial results do **not** satisfy the conjunctive guard because cut-arc `ConformityFamily` / `ConformitySign` remain undefined by accepted authority.

## Actions deliberately not taken

Because the guard failed before semantic mutation:

- no production implementation was changed;
- no test identity 383-388 or selector388 was authored;
- no accepted selector was changed;
- no CMake/build configuration was changed;
- no A3->A4 wiring or hard-rail pairing behavior was changed;
- no compile/package workflow was run;
- no Directional binary, test, benchmark, discovery command, or other runtime was executed.

A compile would add no evidence relevant to this source-definition failure and is therefore not authorized as a substitute for the guard.

## Exact next — `M4-CP3-DEFN-R1`

Run one bounded, runtime-free definition/review turn. Independently re-open the A2a'/A2b cut semantics and frozen A3 definition, then settle **how artificial cellularizing cut arcs participate in global conformity without inventing geometry/tolerance identity**. At minimum, adjudicate these architectural alternatives rather than selecting one implicitly in implementation:

- **A — distinct cut-incidence semantics:** cut-backed shared boundaries receive exact shared subdivision/breakpoint authority without pretending that an arbitrary cut has a physical U/V field-family/sign; revise the A3 constraint model only as much as required and state whether CP1/CP2 proof obligations must be re-opened.
- **B — field-certified cuts:** strengthen A2a'/A2b so every conformity-relevant cut is itself field-aligned/certified and therefore owns real family/sign semantics; record the larger upstream/M3 consequences if chosen.
- **C — exact combinatorial cut frame:** introduce a separately frozen, source/topology-derived abstract family/sign assignment for cut occurrences, but accept it only if it is uniquely defined, relabeling/enumeration invariant, and demonstrably compatible with patch-completion parity/consistency. A boundary-ordinal convention alone is not sufficient evidence.

The definition turn must either freeze one falsifiable replacement contract (including impact on already accepted CP1/CP2 authority and the exact successor CB scope) or stop with the ambiguity still open. No production/test semantic mutation or Directional runtime belongs in that definition turn.

## Tool-use ledger

The exact in-memory turn-local tool-call counter became incomplete across session compaction. Per `TOOL_USE_CONSERVATION_POLICY.md` §2 step 0, it is therefore reported as **partial/unknown** rather than reconstructed from remote services. No accounting-only tool calls were made to recover the lost count.
