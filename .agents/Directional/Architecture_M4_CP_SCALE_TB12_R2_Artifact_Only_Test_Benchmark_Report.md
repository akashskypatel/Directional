# M4-CP-SCALE-TB12-R2-EXEC — Artifact-Only Cycle-Ordering Diagnostic Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB12-R2-EXEC`
**Disposition:** **COMPLETE / FOCUSED SEMANTIC RED REPRODUCED / DISCRIMINATOR CAPTURED / REVIEW REQUIRED**
**Immutable candidate:** artifact `10517300204`, compile source `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21`
**Accepted runtime authority entering/leaving this TB:** package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**

## 1. Immutable artifact preflight

TB12-R2 consumed the CB15 package without configure, compile, relink, regeneration, permission repair, fixture repair, discovery/list/help/version commands, CTest, benchmark execution, or source/package mutation. Provider/local ZIP SHA-256 is `dceab12b7fe9ee8feccf972837455b89f6fe8b4bc30b44ee4947fc2343bd2711`; the root self-excluding manifest verifies **28/28**. Package metadata names exact source `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21`; source archive SHA-256 is `14a1eccff69d402b72bf803f47b0ebf778f96d9f2da87baf46b74b1e49873ebc`; preflight/build are `0/0`; all recorded source-status snapshots are empty; `runtimeExecution=false`; `exactArithmeticBackend=GMP`; authoritative link evidence contains both `libgmpxx.so` and `libgmp.so`.

The producer executable is archived mode `0755`, SHA-256 `3c5ff0af1b1b3ba78781692b9661c8c59e167acc14793feae291104fcecd269c`. Selector426 is unchanged at 426 unique LF rows, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, exact first425 prefix `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, owners **30 authority-kernel / 280 producer / 75 completion / 41 validation**; no selector427 exists. Retained S5 hashes are OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, rawfield `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

## 2. Independent retained-fixture precondition

Independent parsing of the exact packaged OBJ re-derives **V/E/F=120/366/244**, one connected component, zero boundary edges/loops, zero non-manifold edges, orientable=true, `chi=-2`, genus `2`. The retained raw field still has degree 4 with 244 data rows after its header. This establishes the frozen genus-two topology/file-shape precondition only; it does not grant atlas or A3 authority.

## 3. Exactly one focused process — semantic RED with requested discriminator

Exactly one fresh producer process executed only `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`. The process started and ended at `2026-09-17T20:40:46Z`, selected exactly one test, exited `1`, and produced **0 PASS / 1 FAIL**. Raw stdout SHA-256 is `ab4dfc14f0b2555ab43bd08e2240b3e77777f2d7ed1613cff4c0a84c52c8de47`; stderr is empty.

The old semantic boundary is unchanged: `crossField=true`; independent/production atlas authority is not established; production deepest stage is `source-labels`; terminal code/stage remains `InvalidFieldTransportAtlas / field-transport-atlas/IncompleteCycleBasis`; `IncompleteCycleBasisReason` remains `CycleOrderingFailed`; A3 remains absent; the frozen assertion still fails at `independentAtlas.has_value()`.

CB15's additive receipt now resolves the previously collapsed ordering failure to:

```text
cycleOrdering={row=14,kind=BoundaryLoop,supportEdges=34,uniqueFromFaces=34,reason=SupportEdgeReused,currentFace=0,sourceEdge=0-72}
```

This is the requested structural discriminator. TB12-R2 does not adjudicate why that boundary-loop support reuses the reported edge or how production should repair it; that is Review work. The unchanged outer error/reason and unchanged RED decision are evidence consistent with CB15's intended diagnostic neutrality.

## 4. Frozen fail-fast counts

The retry plan forbids cumulative runtime regardless of focus outcome. Actual generated-runtime counts are therefore exactly:

- S5 focus: **1 fresh process**, **0 PASS / 1 FAIL**;
- selector426: **0/426 executed**;
- benchmark: **0 executed**.

No selector427 was published and no S5 credit is granted.

## 5. Immutable postflight

Package, execution-view and exact packaged-source byte+mode censuses are identical before/after the single process. Producer mode/hash, selector426 hash/prefix, retained fixture hashes and source/package evidence remain unchanged. Runtime receipts exist only outside the immutable package/source trees. No rebuild, repair, `chmod`, regeneration or package mutation occurred.

## 6. Regression disposition and successor

TB12-R2 reproduces the existing `M4-CP-SCALE-TB12-R1-EXEC-CAND-01`; it does **not** create a new stable candidate. The new evidence narrows the exact failing subcondition to boundary-loop cycle row `14`, 34 support edges / 34 unique source faces, subtype `SupportEdgeReused`, locus current face `0`, source edge `0-72`. The candidate remains **OPEN / PRODUCTION FIELD-TRANSPORT CYCLE-BASIS ORDERING DEFECT / `RP-07 CYCLIC_TOPOLOGY_LINEARIZATION` / NON-STABLE** pending mandatory Review.

Accepted runtime authority remains package `10473134357` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. Exact successor is runtime-free `M4-CP-SCALE-TB12-R2-REV`; no semantic repair, retry, selector runtime or benchmark may precede Review.
