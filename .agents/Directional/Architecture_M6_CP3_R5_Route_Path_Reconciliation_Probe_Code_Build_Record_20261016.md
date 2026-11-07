# R5 route/path reconciliation probe — Code + Build record

**Turn:** `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE`; **completed compile-only**, no runtime acceptance claim.

## Authority and immutable source

RA-68 accepts the R5 definition but rejects both proposed repair shapes pending independent producer evidence. The authorized CB5 operation observes, but does not interpret or repair, the possible route/corner/path discrepancy. Frozen snapshot commit `48ba0b6b1dc920ac3a87bec89d7d9d1eececd199`, workflow [38828612903](https://github.com/akashskypatel/Directional/actions/runs/38828612903), artifact `12016346107`, ZIP SHA-256 `174cb54bb46b4cff0e4649cfce76c6a7e9f24cba55cadc1ac9dd9395956f2641`. Verified inner tar and 5651/5651 source SHA256SUMS. The original TB4 44 REDs are historical, not tests of CB5.

Semantic source commit [`a143af264bc8b33f0e1b2f8def16b2479b53d5fc`](https://github.com/akashskypatel/Directional/commit/a143af264bc8b33f0e1b2f8def16b2479b53d5fc), exact C++ blob `c12910dcc15a01e21d074039cc65d79c2234a5a6`. Only 42 lines inserted in `src/geometry/SurfaceCellTracing.cpp`, inside the existing `if (!firstEndpoint || !secondEndpoint)` rejection branch. Original endpoint evidence is retained. Added `a2bProbeRouteStepCount`, `a2bProbeRouteStep[i]` exact ordered source-edge topology keys, `a2bProbeFirstPathFaces` / `a2bProbeSecondPathFaces` as distinct source-face sets from each owning cell's actual `boundaryPaths[filledSide]`. Missing owner, invalid side and empty path are explicit. No admission/rejection logic, A2b/A3/A4/A5 predicate, source topology, fixture, selector, ledger, gate or recovery behavior changed. Interpretation is reserved to TB5 + Review.

## Source transport

Source patch SHA-256 `ddaefe488ab4b07a27f0ca2bf5d2b8bc6783508b780a769df0b37ff650fd5fa4`, prechecked with exact forward/reverse application and `git diff --check`. Google Drive patch staging failed twice with `container_session_unavailable`; GitHub Git-objects API fallback pushed exact preverified blob SHA via an expected-parent, non-force ref update. Patch bytes were not committed to the source tree. A downloadable preservation patch is retained in this chat.

## Compile verification

Durable dispatcher request commit `ffcaa5933bbf39c7eed355f54c3283246ebad061` pins `source_sha=a143af264bc8b33f0e1b2f8def16b2479b53d5fc`, `operation=compile`, `mailbox_key=m6-cp3-cb5-r5-route-path-compile`, and eight standard GMP/GMPXX targets. Mailbox event SHA equals the request commit and source SHA equals the semantic commit. **Compile GREEN:** workflow [38829147491](https://github.com/akashskypatel/Directional/actions/runs/38829147491), job `116743695976`, source `a143af264bc8b33f0e1b2f8def16b2479b53d5fc`, artifact `12015849679` outer ZIP SHA-256 `92a014a6d0bc4de3bef55b2ebcec2fd8c5095d3b65f90eb7bd79567dbcb10444`; 28/28 SHA256SUMS, all eight targets, GMPXX and GMP linked, build/preflight exits 0/0, five source-status snapshots empty, `runtimeExecution=false`. Manifest verified independently from downloaded exact ZIP bytes. `DIRECTIONAL_ENABLE_GMP=ON`; build log's retained link command explicitly links both `libgmpxx.so` and `libgmp.so`. `exactArithmeticBackend=GMP`. No tests, benchmarks, generated Directional binaries or 497 selector executed.

## Process and continuation

The first repository source/document reads happened before explicitly choosing `READ_MODE=snapshot`, contrary to `TOOL_USE_CONSERVATION_POLICY.md`; this was promptly disclosed and inspection switched to the one exact verified snapshot. The defect is procedural and does not establish a semantic test result. Snapshot trigger is the bounded `.agents/connector-triggers/source-snapshot/cb5-r5-route-path-20261016.txt`; it is historical control metadata, not source or an executable.

Ledger 66/17/49, debt 1; CP2 491/491 accepted; R3 403/497 rejected; frozen 497 selector and RP-01/RP-02 not advanced. PR #8 stays draft/open. Next turn `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` is a separate immutable artifact-only Test + Benchmark. It must use the exact package `12015849679`, separately pinned diagnostic harness, and never rebuild or change source; do not infer corner/path reconciliation before that evidence. No next-turn work commenced in CB5.
