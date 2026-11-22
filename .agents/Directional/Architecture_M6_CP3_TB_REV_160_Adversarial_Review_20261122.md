# TB-REV-160 — adversarial continuation after handover (2026-11-22 UTC)

Continues `M6-CP3-TB-REV-160-P13-STAGED-SLIDE-ENTRY-STOP-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_160_Staged_Slide_Entry_Stop_Full_Gate_Independent_Review_20261122.md). Runtime-free: source reading, the TB160 report and receipt, three Haiku read-only audits, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **TB160 PASS upheld.** The independent re-derivation of 978/978, CP2 491/491, 977/977 predecessor equality and census 3/3 stands.
- **The frozen prose `M6-CP3-CB-178-P13-SLIDE-ENTRY-STOP-PRODUCTION-ACTIVATION` is WITHDRAWN** (V2). In its place is the exact test-only `M6-CP3-CB-178-P13-STAGED-SLIDE-ENTRY-STOP-DOWNSTREAM-RECEIPT`. Activation moves to CB-179, frozen in TB-REV-161 from the new receipt.

## Findings

**V1 — `cutGraph=built` is the production cellularity certificate, not only reachability.**
- Row 978 calls the canonical `SurfaceCutGraph::make`, the same stage production calls at `RemeshPipeline.cpp:12936`.
- Success requires `proves_embedded_cellularity()` (`SurfaceCutGraph.cpp:1115–1123`):
  - graph components equal source components;
  - boundary loops equal excluded orbits;
  - `eulerCharacteristic == sourceEulerCharacteristic`;
  - every face disc. The per-face flag is the global χ predicate (`:890–910`).
- So on the staged network, the χ residual is gone at the production certificate. The cut search also no longer exhausts, and that exhaustion is the sphere's current production boundary (`:1108/:1110`).
- Not proven:
  - source-face-owner cellularity (`proves_cellularity`, checked at `GlobalTopologyPlan.cpp:2679`);
  - the plan and later stages;
  - row 686's test-side oracle χ (`tests:9530`, a separate network-plus-crossings count);
  - mesh acceptance.
- The independent review's "χ+4 not discharged" is too strong for the certificate and right for the plan and output.
- Reason it matters: the sphere boundary moves from the cut search to `GlobalTopologyPlan::make`, which nothing has measured.

**V2 — the frozen CB-178 has no reachable exit, and it is monolithic (RA-280, RA-261).**
- Stop gate 2 asks a compile-only turn to derive the sphere premises "from actual source-produced data". A Code + Build turn cannot produce runtime data, so it would either guess or run tests. Both are forbidden.
- It also bundles five separate changes into one turn:
  - activation;
  - deletion of the staging parameter;
  - five premise-row rewrites;
  - a V3b reaching test with a mutation falsifier;
  - lifetime proofs.
- Withdrawn. The measurement it needs becomes its own exact test-only turn.

**V3 — row 648's sphere branch has never executed.**
- `tests:14128–14137` returns early with `status=SKIPPED` when the pipeline cut graph is absent, which is every run so far.
- After activation the branch runs for the first time. It asserts `ASSERT_FALSE(sphere.plan)` and failure-locus Euler census fields, which presume a later-stage failure.
- So 648 is not a premise replacement. It needs the plan outcome, which is now measured by row 979.

**V4 — row 393's carrier-end check has a coverage hole.**
- `expectedCarrierEnd` is the literal `id ∈ {4,6,15,19}` (`tests:17416`). Only those ids reach the carrier checks, and the set check at `:17498` is a literal too.
- Traces 5/8/17/20 gaining carrier ends would fail only at `:17498`. Their edge, parameter and node literals are never checked.
- The activation replacement must cover all eight carrier ends from row 979's per-trace lines, plus the carrier-node count (`:17499`).

**V5 — no gate row witnesses a pending-wall stop; the first production witness is the BunnyRandom census.**
- The TB159 receipts show only two `wallCommitted=0` stops, both in BunnyRandom: `142:2→87:0` and `26:1→99:0`. Every gate receipt is a sphere with committed walls.
- TB-REV-161 must freeze a census falsifier for the activation TB:
  - BunnyRandom may change its RED site;
  - it must not end in a binding or index failure (`InvalidNetworkBinding`, or a carrier-contact struck-index rejection at `EmbeddedGraphTopology.cpp:873/894/1255`).

**V6 — V3b scope corrected.**
- The edge-locus ray composition check (`edge_locus_edge_ray_composition_valid`, `EmbeddedGraphTopology.cpp:2635`, used at `:3080`) runs inside `build_rotation_system` on every candidate, so row 978's built graph passed it.
- Still missing: an assertion on the specific contact node's counted composition `(0,2)`. The counts are locals of `build_rotation_system`; the public diagnostics (`S4ExecutionDiagnostics`, `EmbeddedGraphTopology.h:703–709`) expose none.
- The independent review asked for a same-direction mutation at the full builder. Canonical networks cannot be hand-built (RA-248), so that falsifier stays at the pure composition helper. V3b becomes a test-only turn after activation, frozen by TB-REV-162 once the production node exists.

**V7 — the receipt row is designed to be non-vacuous.**
- Row 979 asserts three things:
  - the production network fails with `CutSearchExhaustedBeforeCellularity`;
  - the staged network builds;
  - the certificate proves embedded cellularity with χ = source χ = 2.
- A wiring that did nothing would fail the first two together. Everything else is printed:
  - the cut-graph counts and Amendment 14 slide-carrier selection;
  - the plan outcome;
  - 24 per-trace end lines (segments, struck trace and segment, carrier and parameter, node);
  - per-slide-segment source-piece counts.
- Together these cover what rows 393, 648, 858 (plan error), 971 (pieces) and 972 read.

## Frozen artifacts

| Artifact | SHA-256 | Notes |
|---|---|---|
| `Architecture_M6_CP3_CB178_P13_Staged_Slide_Entry_Stop_Downstream_Receipt_Exact.diff` | `d26394449baa92ede456d4a3400ada7e4a109d546bdedc1add50ba5a4deb5b0f` (9,709 B) | tests only, +193/−0. Preimage = CB-177 postimage `82a1ec498d7ba7fea877cfeda78aedea9457e0124c124b48c69546892ebba87c`; postimage `58f9493591084628a51d9e4519938c49a67bf73745e7f290c61857afeeb5f4ae`. `git apply --check` OK; `-fsyntax-only` 0 errors, 9 warnings = HEAD. |
| `gates/Architecture_M6_TB161_P13_Staged_Slide_Entry_Stop_Downstream_Receipt_Full_Gate_Case_Manifest.tsv` | `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a` (146,958 B) | 979 rows; rows 1–978 byte-equal to TB160 `d7eb3c35…ca5a`; census manifest unchanged `3af1dc0d…e793` |

## TB161 rules (STOP unless all hold)

1. 979/979 PASS; CP2 491/491.
2. Rows 1–978 raw logs equal TB160 under N1–N3, with a zero allowance.
3. Census 3/3 equal TB160 artifact `14737279153` under N1–N4, with a zero allowance.
4. Row 979 passes, and all its receipt lines are published verbatim. The lines are `SphereStagedCutGraph`, `SphereStagedPlan`, 24 `SphereStagedTrace`, every `SphereStagedSlidePiece`, and `SphereStagedSlidePieces`.
   - Predictions (a mismatch is reported, not a STOP): `productionCut=CutSearchExhaustedBeforeCellularity chi=2 sourceChi=2`.
   - Traces 17/20/5/8: `segments=8`, ending on contacts at `0:6`/`1:6`/`21:6`/`22:6` with row 978's carriers.
   - Everything else is a measurement.
5. Any failure → STATUS BLOCKED and a return to Review. Do not edit tests or the manifest.

## Turn sequence

1. CB-178: test-only receipt, compile only.
2. TB-EXEC-161.
3. TB-REV-161, which freezes the exact CB-179:
   - the production default;
   - deletion of the staging parameter;
   - row 978 rewritten as a production assertion;
   - exact replacements for rows 393/648/858/971/972 from row 979;
   - the BunnyRandom census falsifier (V5).

   If the plan fails, TB-REV-161 decides whether activation still goes first, or a plan-stage DEFN does, based on where the plan fails.
4. CB-179.
5. TB-EXEC/REV-162.
6. CB-180: V3b node test, test-only.
7. R1 slide-start subdivision.
8. RA-275 S4a.
9. O48.

## Lessons

- Read what a "built" receipt certifies before calling it reachability. A canonical constructor's success predicate is a measured invariant.
- A compile-only turn cannot derive expectations from data. Withdraw any CB whose stop gate needs a run.
- Grep a premise test for early-return branches. A dormant branch made live by a switch is new coverage, not a premise replacement.
