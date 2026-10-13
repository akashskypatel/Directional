# M6-CP3-CB1-ENTRY-R4 — public strict trace foreign-edge oracle transport handoff (2026-10-13 UTC)

**Same canonical Code + Build turn.** No successor, runtime test, benchmark, or TB497 execution.

## Exact authority and authored WIP

- GitHub snapshot workflow `38359143085`, result artifact `11793278212`, exact source/event SHA `45d210e51a12dd3b8416c5179e6737edbb53e4e3`. ZIP SHA-256 `6cf4c61df86f4d43707aef86c36085953d1b7dcf5556405cd8da2d9ebbfc45b9`. Nested source archive hash verified; source file manifest **5612/5612**.
- Local WIP file `Directional_M6_CP3_R4_Public_Foreign_Edge_Oracle_WIP.patch`, SHA-256 `d62ed1a55e33a0dfc7b13b83e76727cafca39bb93cc4bf471424ca2c247d7287`. Its header carries the exact base, diff-body hash, and three intended paths.
- Three intended paths: `tests/SurfaceCellTracingPhase14Tests.cpp`, `TODO.md`, `.agents/Directional/Future_Chat_Session_Handoff.md`. Git whitespace check, reverse check against edited tree, and forward patch application against exact baseline copies all PASS.
- The only test source edit extends existing `SurfaceCellTracingPhase14.ProducedRailEndpointsRequireExactSourceVertexIncidence`. A known-good strict no-network `trace_surface_field` call already avoids `FieldMetadata`; a separate missing-key negative already rejects. The new negative substitutes only an existing but foreign source-edge key `(1,4)` for authoritative `(0,4)`, requiring public-entry `FieldMetadata` before tracing. This distinguishes public ingress from already-covered helper-level rejection.

## Publication impediment

Upload of the local patch via the available Library/Google Drive file-transfer surface was attempted twice, then retried after initializing Files materialization. Both paths repeatedly returned `container_session_unavailable` (`No active container session was found for container_path`). This establishes an inability to transfer this container's patch bytes through that surface in this session, **not** an outage of Google Drive itself and not a GitHub content safety denial. No Drive File ID, dispatcher `drive_apply` request, semantic patch commit, or compile evidence was created for this WIP.

The exact WIP patch is emitted as a downloadable chat artifact. Before resuming, recover those exact bytes (or regenerate from the frozen source), verify SHA-256 and exact base, stage by the approved `Directional-CI` Drive patch transport, submit a unique `drive_apply` dispatcher request, verify the applied semantic SHA, then run the mandatory eight-target GMP/GMPXX compile-only request. Keep original runtime gates closed and do not change the frozen selector.

RA-50 still discharges RA-43.2; RA-43.1/.4 global disposition, RA-46.5, RA-47.12 executable liveness, 39 endpoint / 34 Phase10 / 7 DCEL / 88 accepted-restoration / six CP3 and true odd-τ multi-carrier obligations remain open. R4 is not complete.
