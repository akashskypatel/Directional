# TB-REV-186 — independent activated sphere full-gate review (2026-11-26 UTC)

## Situation

**Decision: rejected for gate acceptance; approve an exact test-authority correction plan, subject to compile verification.** The activated candidate is valid semantic RED: 1005/1006 PASS. Row971 is the sole lost accepted-green identity. No activated gate credit. Do not run the next turn until root STATUS closes this Review. No implementation, test, fixture, selector, harness, or workflow definition change and no runtime execution in Review.

## Background — immutable authority

PR #8 remains open, draft and unmerged. Entry HEAD `35b5e6b8b7097b4398bc555edf45e0830caf7e70`. Reopened exact candidate `15154205483`, ZIP `cd84ab8b591759f4e01b5aaa685b048d69ed0a30a6b7e63dde6b1a97031971e8`, source `cc25a6402cdd3ca1a33a9a9778250176b182bb2a`, compile run 45895803711; 28/28 package checks, eight targets, GMP/GMPXX, runtimeExecution=false, empty source status. Source tar `5c316970e7163432d3bffb0ec2ac1646cef27ce4bc13ec999a9d70ae447eeb79`. Snapshot 15153779423 source a4849516426e285d8ed37ad7e271ea6feddddfa9, 5860/5860 checks; 1177 candidate files compared, nine document/control differences only. Remote comparison to entry HEAD lists ten document/control differences. Review edits use verified current remote blob preimages, reconstructed from prior closeout patch; not an assertion that the entire local document tree equals HEAD.

Independently re-opened Library `/Directional/TB-EXEC-186-terminal-evidence.zip`, outer SHA-256 `d6e11bc3c43e38d2989a2f07cb3be2bbfb915af71b5a5558d0eb6e4b2a0c0a20`. Verified actual file inventory and 2020/2020 member digests in each full result: TB186 15155787349 `ee1e603907561d773034c9e48fd76fa2d1e8fe6273ace85f9425f5bf557f76fa`; TB185V 15066180913 `16983f7e40ac9f5934b3a50ffd556925d582e857e41aaf34aae8f5fb3b181082`; TB187Q 15130286146 `a3fb3a89a3dd72ccc2870412fd0d6e78af4921943d7f491c4735443264de8ecc`. TB186T 15138712336 16/16 checks, ZIP `42de0d943825cd6e5b3932fb98300cf6555bd7a25a8786179d8f5bcfb670b3a3`. Mailbox `m6-cp3-tb186-exec` independently confirms run 45898832790, attempt1, job 140179501945, failure and artifact digests. Offline independent verifier returned 1 on six expected checks of the organic RED and nonzero gate exit; no other check failure. This is not a green result. Ledger, organic envelopes, membership, raw hashes, resources and postflight confirm 1006 planned/executed, 1005 PASS, one RED, control_bad1, zero abnormal/missing/skipped/duplicate. CP2 prefix 491 PASS; 1087 members, 81 deferred. Exact prefix hashes: 491 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`; 1005 `94f02d6bd2d599f02bbc7dc7cd317e490cdb00e18827596acac2cfdd827460be`; 1006 `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`; deferred81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.

## Assessment — exact comparison and adjudication

Only frozen N1 (GoogleTest timing), N2 (line endings), N3 (complete region records as exact multiset with ordered residual) used. Baseline-to-baseline 738 exact/268 N1–N2/0 material. TB186 vs TB185V 603 exact/376 N1–N2/1 N3/26 material; vs TB187Q 594/385/1/26. N3 row164. Missing, duplicate or changed complete records and changed residual are not normalized. 1614→2902 region records: +1288, none lost. All 26 material rows add repeats of the same 14 exact new sphere region records, IDs 0..13, connected, reduced and whole χ1, difference0, no interior barrier sides; sorted set LF SHA `4002f736022b437245ce7314d384e7ad2d131239c5d1c83222956f9c3fffd5e9`. Producer `GlobalTopologyPlan.cpp:1867–1903,2241` publishes region certificates. This supports plan reach, not completed output. Forensic separation of newly added region records is not a new normalizer.

| Row(s) | Independent disposition of material differences |
|---|---|
| 380,388,393,394,396,397,691,694,699,700,978 | Each +56 region records, otherwise exact ordered residual under N1/N2; row393 whitelist and 978 staged stop assertions PASS. |
| 843,844 | Each +28 region records; otherwise unchanged. |
| 644 | +28; actual graph succeeds with V18/E30/F14 χ2, no cuts, no source error. Independent barrier oracle V81/E109/F30 χ2, 30 disk components; incoming100→96, outgoing/unique109 unchanged. Four moving terminal stops explain incoming change. |
| 645 | +28; same barrier count change; cut/plan available, failure advances to completion. Baseline stdout/stderr splits `boundar` and `yCyclesValid` around an exact partition receipt; reconstructed receipt differs only incoming, cut available, plan available and failure stage. Old reconstructed SHA `8d7f6aded90976c5b1eb61c97504986a75f12f5da23fcf5cb515e69d0a695956`; new `4d4fbb92eac97118ec1e51c8f8c1edd90fa1709de2a4663da60cdff5f8cb78e7`. Retained as material, no new normalization. |
| 648 | +28; exact CB-206 predicted torus V72/E76/F4 χ0 residual0 unchanged, sphere now V18/E30/F14 χ2 residual0, no skip. |
| 669 | +56; same sample186 and 52/53/53 bits; other specimens unchanged, sphere reaches plan; replay/census assertions PASS. |
| 686 | +28; actual graph independent oracle 18→14 disk orbits, fragment inventory372→368, V18/E30, χ6→2, sourceχ2; all producer discrepancy fields zero. |
| 698 | +56; diagnostic G5 credit none unchanged; actual graph and plan reach with 14 regions, 30 arcs and 18 nodes; completion rejects. |
| 858 | +28; independently verified exact prior TB186T prefix and corrected display/detail PASS; see below. |
| 963 | +56; all four exact moving stops, incoming segments9→8, committed1→0, equal exact contact parameter, two shared events per contact, nodes12..15. |
| 968 | +56; 24 traces, segments182→178, ordinary172→168, 10 original slides/10 faceThenEdge, no rejected/path/binding failures. |
| 971 | +56; organic RED and old final ray receipt absent because fatal assertion. Test-authority defect, no stable product regression shown. |
| 972 | +28; ten carriers classified, zero selected; now cellular instead of cut-search exhaustion. Z3 prediction met. |
| 979 | +56; unstaged cut remains exhausted; staged V18/E30/F14, orbits14, χ2/sourceχ2, components1, cutEdges0, candidates288, selected0, slideCarriers10/classified10/selected0/slideCutEdges0, sourceFaceCellularity1. |
| 1006 | +112; four sphere recipes reach expected digest12659562395504099178; explicit false digest9084693800288509401 and zero stops. All eleven exact receipt lines SHA `d8407bea068c219f04c785fc2701e0a82093c9b8220514d3786c84869f4ca00c`; other recipes unchanged, ordered residual 2380 lines after separating exact changed records/recipes. |

### A1 — row971 (non-stable test-authority defect)

Raw SHA `7cbb2d9fa09314af09c82121fdc430c5a4a696d93cba1653ca3ce0a71f701f26`, one organic RUN, resource exit1, 26.12 s. `FieldAlignedCurveNetworkTests.cpp:18772` requires two pieces per arc containing an original transit segment; four actual one-piece suffixes at 0:6,1:6,21:6,22:6. :18779 counts arc occurrences instead of original slide identities (10 expected,14 observed). :18790 reads face-only contact; :19063 assumes the reversed prefix ray leaves a source vertex. The new wall contact lies inside a source edge, not at a vertex. `EmbeddedGraphTopology.cpp:816–838` gets the exact occupied slide fraction; :1720–1775 inserts an arc cut at the nonterminal contact. :955–1006 clips ordered face and edge pieces to arc endpoints, :1009–1015 reverses the actual last piece. `ExactTraceSegmentPieces.h:124+` and `SurfaceCellTracing.cpp:6044–6056` retain the underlying occupancy. Thus source slides and published arc occurrences are different semantic objects. No product violation is established by the six assertions. The fatal assertion prevents proof of remaining rays, so do not claim ray correctness yet.

The prior row978 witness and row963 raw receipt independently specify four interior contacts:

| Moving → struck | Node | Edge | Exact edge parameter |
|---|---:|---|---|
| 17:8 → 0:6 | 12 | 6,8 | 4038890029339747/4503599627370496 |
| 20:8 → 1:6 | 13 | 16,21 | 4038890029339747/4503599627370496 |
| 5:8 → 21:6 | 14 | 33,34 | 1009722507334937/1125899906842624 |
| 8:8 → 22:6 | 15 | 45,46 | 464709598030749/4503599627370496 |

Ten original segment6 slide identities: traces 0,1,9,10,11,12,13,14,21,22. Expected six whole, four prefixes, four suffixes = 14 occurrences (10 two-piece, four one-piece). Derive these from exact terminal contact and arc coverage; preserve all ten vertex-end rays and add eight interior wall rays, both orientations, exact endpoints, carriers, fractions, direction and coverage. No count-only assertion replacement. The proposed test is an independent falsifier, not evidence of passing. The exact diff is in the [manifest](gates/Architecture_M6_CP3_CB209_P13_Slide_Arc_Ray_Oracle_Exact_Manifest.md).

### A2 — row858 display and completion

Exact prior TB186T prefix 69,196 B, 397 lines SHA `32d6de52259ed91a9968109bda21b68d3dc4d37a3b1aed7b59193301c61a42d9`; immediate detail line `SphereDisplayStopDetail detail=PreparationRejected firstInvalidStage= firstInvalidReason=`; stop `SphereDisplayStop stage=completion code=NotProductionReady sourceFace=- relatedSourceFace=- sourceEdge=- sourceVertex=-`. PASS suffix under N1/N2. Corrected display premise independently supported; retain row1005/fan/genus/stop controls and !is_produced(). No invented locus. `RemeshPipeline.cpp:14156–14159` saves `closedCompletionFailure->detail` to `surfaceCellContext.completionFailure`; :14361–14365 maps PreparationRejected to completion/NotProductionReady. `PatchDescriptor.cpp:2563–2576,2622–2635,2644,2691` enumerates possible preparation failures. `SurfaceCellFeasibilityRepair.h:307–360,482–541` exposes only produced/rejected factories and exhaustive variant, so no absent/NotApplicable outcomes. Default fallback true (`PatchDescriptor.h:258`; `RemeshPipeline.cpp:13953–13997` does not disable it). Three reachable paths remain: boundary parity rejection (`BoundaryParityRepair:` plus detail), side subdivision rejection (`SideSubdivisionRepair:` plus detail), or `NoPatchDescriptors`. Stored evidence cannot distinguish them. A later separate exact test-only receipt must record the existing `surfaceCellContext.completionFailure` without inventing a locus. Do not repair or authorize that second change now. No completed sphere output proved.

## Recommendation and obligations

Only next turn after STATUS COMPLETE: `M6-CP3-CB-209-P13-SLIDE-ARC-RAY-ORACLE`, [exact manifest](gates/Architecture_M6_CP3_CB209_P13_Slide_Arc_Ray_Oracle_Exact_Manifest.md). Compile only; no tests/benchmarks. Independently verified application, whitespace and exact pre/postimages in scratch, restored; no syntax compile or runtime, not a claim of successful build. Next CB must verify exact hash and compile all eight targets. Later immutable full gate must preserve every other row under N1–N3, reproduce the 26-row activation differences against both preactivation comparators, prove exact new row971 rays/coverage and retained positive/negative controls. STOP on any RED, unpredicted difference, absent evidence or boundary violation. Do not weaken test or producer.

| Obligation | Disposition |
|---|---|
| X1/W4/Y1 | Six selected recipes terminate; full gate completes. Not general scaling evidence. |
| Y2, X2/Z1, Z3 | Census finishes, corrected row858 PASS and row972 PASS; no cap. |
| X3/V10, S2/S3/V11, U4 | Exact 648/1006, row393 whitelist, row669 and transcripts verified; wider activation reach not proved. |
| Z2 | Three reachable preparation branches; exact predicate unproved; separate receipt required after valid gate. |
| RA-277-NV1 | Carry independent arc/ray falsifiers into CB-209. |
| Y3/Y4, Z4/X5/Y5, S4/U2/U3, U5/W6/R2/R3/R5/R6 | Carry; CB-207D not authorized (no cap); CB-207C size receipt conditional. |
| V5 | Held: Cylinder, BunnyRandom and Vase, both pending wall contacts 142:2→87:0 and 26:1→99:0; no deferred credit, no census executed. |
| Remaining | X4/W5 prior syntax evidence not rerun; S1/U1/W1/W2/R1 prior discharge retained; W3 withdrawn, R4/CB-190 held. P1 supported; D-U/O3 carried; O1/O2/O4/O5 discharged, O6 held; K6/TB170 closed; J6/E5/CB190, parameter deletion, V3b/R1/O48 held. |

Stable counts **67 events /17 categories /50 recurrences**, debt1/deferred81. No CP3/497/D0/H4 promotion. Fine-resolution close_sheets 0.02 and QF1 efficacy remain unproved. Review retains active and cited predecessor records; broader historical consolidation not performed. Preflight read ordering was imperfect (direct orientation/policy reads before snapshot proof). Corrected by verifying exact source and document preimages. The local snapshot is not a complete remote current-document snapshot; remote comparison and blob checks cover all changed preimages. No hidden repair or runtime.
