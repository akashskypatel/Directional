# M3-CP4c-2 TB-X2-EXEC Artifact-Only Evidence

## Scope

`M3-CP4c-2-TB-X2-EXEC` executed only the frozen report-only identity
`GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable` from immutable GMP package
`9696201700`. This record preserves execution evidence only. It does **not** choose the 357/358 gate; that
decision belongs exclusively to `M3-CP4c-2-TB-X2-REV`.

## Immutable authority

- semantic/test source: `93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`
- package artifact: `9696201700`
- package SHA-256: `af3ebe2efaab66fed70de8d954cb5615abd9428f401ea974dffe1e14577c8097`
- packaged source archive SHA-256:
  `8694f0fb85d101e3c5862e5a6a8a8a3ed241c723fd229eb44f83844b30321687`
- X2 selector: one identity /
  `88af227b7c7ca78d2a6247624b3a5f860026cf50fd3c2bd6a215756b086dafc8`

## Authoritative X2 execution

Corrected artifact-only run/job: `33199227974 / 98944212158`.

- immutable preflight: PASS
- exact package source materialized at the compiled fixture root
  `/home/runner/work/Directional/Directional`
- selected identity count: 1
- report count: 1
- process exit: 1; the frozen TB plan explicitly permits this report-only identity to return red
- immutable postflight: PASS
- configure / compile / relink / repair / generated discovery / mutation: all `false`
- result artifact: `9697052371` /
  `sha256:524534f76d99500c91e921d81d9d38bc6f8607f379500cd976d0c9fa8600f22b`
- diagnostic log artifact: `9697052810` /
  `sha256:916fa2478d9bd3fc5ba42e3dd670c7373ed3e26a6fcc721a733063da42161719`

Raw X2 publication, preserved verbatim:

```text
m3Cp4c2X2;prescribed sphere;railAuthority=pipeline-authoritative;pipelineFailure=NotProductionReady;pipelineFailureStage=surface-cut-graph/CellularityNotEstablished;sourceTopologyRegionsSnapshot=no;fieldTransportAtlasSnapshot=no;fieldAlignedCurveNetworkSnapshot=no;globalTopologyPlanSnapshot=no;sourceEuler=2;sourceBoundaryLoopCount=0;sourceGenus=0;interiorLocalVertices=98;sourceTopologyRegions=true;sourceTopologyRegionCount=1;fieldTransportAtlas=true;fieldAlignedCurveNetwork=true;networkTraceCount=24;networkEventCount=56;terminalTraceIntersectionCount=10;producedTerminalEventKinds=2,4;terminalEventTraceIds=2:2,2:3,2:4,2:5,2:6,2:7,2:8,2:15,2:16,2:17,2:18,2:19,2:20,2:23,4:0,4:1,4:9,4:10,4:11,4:12,4:13,4:14,4:21,4:22;furthestStage=field-aligned-network;failedStage=surface-cut-graph;surfaceCutGraphError=CellularityNotEstablished
```

No C1, C3, C6, cumulative 357/358 selector, benchmark, generated discovery, or additional Directional runtime
was executed in this subturn.

## Orchestration deviations preserved

Two non-semantic control failures preceded the authoritative execution:

1. run `33198406913` failed at workflow startup before jobs/runtime because the caller did not satisfy the static
   permission ceiling of the reusable observer's nested `contents: write` job;
2. run/job `33198586715 / 98942044412` executed the same one X2 identity but materialized the package source
   under runner temp rather than the absolute fixture root embedded in the precompiled binary. Its sole report was
   `m3Cp4c2X2;prescribed sphere:fixture-load-failed`. Result/log artifacts were
   `9696799978 / 9696800558`, digests
   `777eead3ffc1aaa0d19725fdca83133945ef9fc1d2ddebf9ab39ce32be5cb6c6 /
   c296f569109ccd3d921f0aeaa12e35a40a0f278b83de7ba1ffaa6ecd6b30a4c4`.

Both are recorded as resolved orchestration/non-stable candidates in `Regression_Root_Cause_Tracker.md`.
Stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**.

## Exit state

Raw X2 evidence is complete and preserved. Exact next subturn:
**`M3-CP4c-2-TB-X2-REV`** using `references/turns/TB-REVIEW.md`. That review may interpret the publication
against the two frozen branches; this EXEC record does not.
