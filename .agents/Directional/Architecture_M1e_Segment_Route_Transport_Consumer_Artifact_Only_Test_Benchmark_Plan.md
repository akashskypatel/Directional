# M1e Segment Route Transport Consumer — Artifact-Only Test + Benchmark Plan

**Status:** authoritative next turn  
**Turn type:** immutable Test + Benchmark only  
**Review policy:** `never`  
**Source/test/build mutation:** prohibited

## 1. Objective

Validate the exact compiled M1e package without rebuilding, relinking, regenerating, editing, repairing, or substituting source, tests, fixtures, executables, libraries, or regular package content.

Selected consumer: `surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

The turn must establish typed ordered route transport correctness and preserve accepted M1d/M1c/M1b/M1a/T1/direct authority. Compile success alone is not semantic acceptance.

## 2. Exact immutable build authority

| Evidence | Value |
|---|---|
| M1e base | `5df33fc11deaac697cb886d8defcaba622ec436f` |
| Final M1e implementation | `bb9cb63a36b64fe2f7c462ad864492c8352b65e8` |
| Build/event | `106e408065e5bda1eb680bc54aef007a1a2d68d6` |
| Run/job | `31345475101 / 93326482946` |
| Result artifact / ZIP SHA-256 | `9047295489` / `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f` |
| Log artifact / ZIP SHA-256 | `9047295703` / `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52` |
| Manifest | **61/61**, `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e` |
| Package | **62** regular files including manifest; 7 executables; 2 static libs; 27 fixtures |
| Runtime in Code + Build | **false** |
| Retention | through `2026-08-24 00:58 UTC` |

First compile-red commit `9edbef1fe34d60d2a507160aa4a27883cea36903` is not runtime authority. Immutable authority is final `bb9cb63...` only.

## 3. Preflight

Before any packaged Directional binary executes, verify exact artifact/run/API digest/outer ZIP authority; safe archive paths; manifest digest and all **61/61** entries; exactly 62 regular files, 7 executables, 2 static libraries and 27 fixtures; build authority `bb9cb63...` / event `106e408...` / PRE_TEST / `runtimeExecution=false`; all command-boundary flags false; source patch/archive/blobs; and executable hashes before permission restoration. Only after content verification may a runtime-only non-regular fixture locator symlink be created if needed.

Expected hashes: producer `0a8e67953e7221daf0fe607794c3b69f2e3fb8331b91ab08a02c10d52152943e`; oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`; authority `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`; validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`.

## 4. Discovery and focused M1e gate

Use native packaged GoogleTest discovery; zero selection is invalid. Require producer **184**, validation **77**, M1a **14**, T1 oracle **29**.

M1e must discover exactly six `SurfaceCellSegmentRouteTransportAuthorityMigration` tests: multi-step composition, reverse exact inverse, equivalent signed quarter-turns, provenance preservation, malformed-authoritative fail-closed, and legacy matching typed composition. Static manifest remains `b6a1c9035b2cd15a13844f812e7261ee0e199e72d0150d9a093a59d1ce713556`.

Run each in a fresh process, exactly one selected; require **6/6** rc=0.

Semantic intent is strict. Multi-step must expose a real multi-crossing route; reverse must find a genuine reciprocal observed route and exact inverse; equivalent signed quarter-turns must prove modulo-4 representation independence; provenance must remain exact; malformed authoritative metadata must fail closed with no fallback/recovery; legacy matching must preserve equivalent observable route behavior through typed composition.

If a fixture does not establish its precondition, do not weaken/reinterpret it in this immutable turn. Return to corrective Code + Build.

## 5. Preservation matrix

Require ordered vertex-fan **2/2**; M1d **6/6 + 3/3**; M1c **6/6 + 3/3**; M1b **6/6 + validation 77/77**; M1a **14/14**; T1 **29/29**.

## 6. Complete producer accounting

Producer total must be exactly **184**: required-green **169/169**, direct required-green **4**, nine historical/deferred known-red individually classified, BunnyRandom, and Vase. The required-green aggregate excludes only those 4 direct cases, 9 declared reds, Bunny and Vase. Do not silently exclude newly red M1e/preservation tests.

Persistence of an existing known-red class is not a new recurrence; any materially changed failure must be classified.

## 7. Direct product and Bunny/Vase

Run Plane, MultiFaceSeam, CloseSheets and Cylinder individually: one selected, rc=0, direct `SurfaceCells`, no fallback/recovery, independent-oracle clean. Record elapsed/RSS diagnostically.

For Bunny/Vase use exact artifact `9047295489`. Artifact-only Actions is authorized if needed. Any temporary workflow must verify exact artifact/run/ZIP/build/61-checksum/62-file/producer authority before runtime, mutate no regular content, retain raw evidence, reverify postflight, and be removed/disabled **before** its trigger marker/payload is deleted.

Accepted entering comparison: Bunny independent oracle rejects first followed by `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase reaches `[ RUN ]` and is bounded at 60 seconds, safety-only. Do not relabel either green merely to close M1e.

## 8. Postflight

Require original result ZIP `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f`, log ZIP `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52`, manifest `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e`, all **61/61** checksums, unchanged executable hashes and exactly 62 regular files.

## 9. Acceptance/regression disposition

Accept M1e only if all required-green gates pass and package immutability remains exact. On acceptance, accept `RP-01` checked step domains, `RP-05` semantic step identity/orientation boundary and `RP-07` typed cumulative route composition; preserve `RP-02 / TA-05` through exact 184 accounting and independent authority; leave historical totals unchanged unless a genuine restored-then-lost authority is proven; keep `PR8-R034 / G4-R007` separate unless direct product evidence changes it independently.

Any required-green failure remains at M1e and returns to corrective Code + Build. Do not advance to another M1 consumer, M2 or G4 remediation.

## 10. Mandatory evidence cleanup

At Test + Benchmark start apply the durable handoff cleanup policy. At closeout retain only durable `.agents/Directional` documents, the new M1e TB report, and exactly one following Code + Build plan. Remove consumed/superseded M1e turn evidence only after necessary facts are folded into durable/live authority.
