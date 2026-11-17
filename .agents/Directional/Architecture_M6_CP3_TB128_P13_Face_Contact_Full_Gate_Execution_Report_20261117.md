# TB128 — face-contact full gate (2026-11-17 UTC)

**Canonical turn:** `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC`. **MISMATCH** under [RA-249 §4](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Freeze_Review_20261117.md#4-tb128-frozen). The full gate has two required REDs; the census meets its frozen comparison criteria. Both executions produced valid postflight evidence. This is not an infrastructure failure or production acceptance. No new source, test, fixture, manifest, selector, build or workflow mutation; no configure, compile, relink, benchmark or successor execution. PR #8 remains draft and unmerged.

## Immutable authority and preflight

- CB149 semantic source `85f9c703c5de86fb2b401cf83c03499a1ce73a27`; package `14315237769`, [compile run 44054969830](https://github.com/akashskypatel/Directional/actions/runs/44054969830); ZIP SHA-256 `39ce6f17ed010d26bf3e65dace9100646fc215a3a8050bb8cae6d621dfb23926`, root manifest `9d2953d707eeaf72323dc0b7db6d28a4889bf0381128b2f105ca66a7bca8c661`, source archive `b7a13ebccc299a3cb98bde7471c2e678b1a0ddd3e31e5d96e4f3e1d8e506fdf9`. All 28 hashes verified; five empty source-status receipts, six archived executable modes 0755, GMP/GMPXX linkage, `runtimeExecution=false`. No package repair. [CB149 compile record](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Code_Build_Record_20261117.md).
- Executor snapshot `93f53bcd82e96e0e3163a75304e197191287999c`, [run 44057997668](https://github.com/akashskypatel/Directional/actions/runs/44057997668), artifact `14315764471`, ZIP SHA-256 `9b037e9d215d92969fd5b41cb7a863124658c75121c477d9320e44ce8f883d53`; 5,523/5,523 file checksums verified. Packaged source, include, tests and benchmark fixtures match the executor. Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- [Gate manifest](gates/Architecture_M6_TB128_P13_Face_Contact_Node_Full_Gate_Case_Manifest.tsv) SHA-256 `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`, 953 rows; exact inherited 951-row manifest prefix. [Deferred ledger](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv) `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 identities. [Census manifest](gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv) `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, three rows. Both manifest self-checks passed.
- TB127 comparison authority: CB146 source `48e6f97d278b2226036f658ce9060a38b8a374b5`, package `14301616031`. Gate artifact `14302887671`, ZIP SHA-256 `017ad5589ae533d4f428312bc59d92409906544f6cd1add1a3db0ccc80383050`, 1,910/1,910 checksums; census artifact `14302668940`, ZIP SHA-256 `4edf0fe64c45fac424eb0c8ef9ed4e9eaae675373e32f06724df9ea4724f3cc5`, 9/9 checksums. Both ledgers, raw log hashes, row identities, manifest bindings and execution boundaries verified. [TB127 report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb127_p13_guard_and_rotation_locus_full_gate_execution_report_20261117md).

## Execution identity

| Work | Request event SHA | Actions run / runtime job | Mailbox key (attempt 1) |
|---|---|---|---|
| Full gate | `e30b44b8c3e4c973b7ed36362da5f62c896fd002` | [44058536482](https://github.com/akashskypatel/Directional/actions/runs/44058536482) / `133954329592` | `m6-cp3-tb128-gate-v1` — failure |
| Census | `244ce261ac99fdd14240186074e9316533ecb84b` | [44059123332](https://github.com/akashskypatel/Directional/actions/runs/44059123332) / `133959018512` | `m6-cp3-tb128-census-v1` — success |

Both orphan-branch mailbox records match the exact requests and semantic source; both schema-validation jobs and request parse passed per run. Request SHA-256: gate `2ba6f457de470f7a18c29af3b054d9e3fdde549b3a0d57d2eaa6cb2105f86fcf`; census `b85592350ebc438c1454705145c373f8d9595dcca7d8796622f1503372320c07`. Both runs ended organically. No duplicate execution.

## Full gate — MISMATCH

Result artifact `14318100443`, ZIP SHA-256 `e208416775f474f75d79ec76697ed19d643a121d8ad086cd37b8f3a330436e5d`; 1,914/1,914 hashes, all 953 raw-log bindings, exact membership and valid postflight verified. Log artifact `14317048253`, ZIP SHA-256 `1b82c8da70be331f3753b5ae864d2a7b17cd04dc14771cad04fd42f64e1a780e`. 953/953 executed, **951 PASS / 2 RED**, zero skipped/missing/duplicate/abnormal. Membership 1,034 (953 gated / 81 deferred). Harness exit 90, `ValueError: required controls failed`, `control_bad=2`.

| Row / identity | Test | Observation |
|---|---|---|
| 858 / `apicensus:19` | `SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported` | Inherited PASS → RED. `SurfaceCellTracingDisplayTests.cpp:155`: `faceLocus.sourceFace.has_value()` actual false, expected true. `surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`. |
| 952 / `ra248:face-chart-exact-geometry` | `FaceChartExactGeometry.OrdersRaysAndContactsExactlyAroundAFaceInteriorPoint` | New RED. `FieldAlignedCurveNetworkTests.cpp:18783`: `sameDoubles(towardB, nearB)` actual false, expected true. Fatal assertion; subsequent exact near-ray order, collision and empty/single-ray checks did not execute. |
| 953 / `ra249:face-contact-interior-cut` | `FaceContactNode.SplitsAStruckSegmentAtAnExactInteriorContactPoint` | New PASS. Supports the helper's tested exact path split and reason-name properties only; does not prove the wired collector or rotation on a production network. |

Of the 951 inherited rows, 950 ledger records match in all substantive fields (excluding raw log hashes). Row 858 differs in verdict/exit/passed/first_failure/typed_reason. Under RA-249 §4 elapsed-time and newline-framing rules, rows 168/173/177/195/477/705 have permitted framing differences. Five other inherited raw logs differ outside those rules:

| Row | Exact substantive difference | Classification (pending independent Review) |
|---|---|---|
| 164 | One existing `M3_CP4AB_FRAGMENT_DIAG` projection record moves past two others. The entire elapsed-time-normalized line multiset matches, but newline-free order differs. | Non-stable diagnostic order/comparison candidate, not a changed record value; frozen comparison still fails. No broadened normalization. |
| 644 | `errorSourceFace=0-1-2` becomes `none`; `originatingRotationSystemReason=TraceEventPositionInvalid` becomes `ArcTraceTerminalCutPositionMismatch`. | Prescribed-sphere rejection changes. |
| 669, 698 | Same reason change; former trace 0/event 1 `NoCarrierMatch` / `SourceEdgeUnavailable` and carrier-count diagnostic fields are absent. `traceEventClaimedSourceEdge=none` remains. | Changed rejection and its evidence, not a timing/formatting difference. |
| 858 | Required face-locus assertion fails, formerly PASS. | Inherited guard regression candidate; product versus obsolete expected locus not independently adjudicated. |

## Census — MATCH within the frozen census criteria

Result artifact `14317054197`, ZIP SHA-256 `cdf7dab92f0e8c2650db6e2e5ac015d7ab5f07e251b4acdd17e6ed511ee7ccf4`; 9/9 checksums, all three exact raw-log bindings, valid postflight. Log artifact `14318106410`, ZIP SHA-256 `52de2faf42eb8258c1517fc5078c9f40f479b13891d81b30c0b42a71f9a10a32`; reusable log `14318061576`, ZIP SHA-256 `4f62a8e4928eba88f4012e32a3e104b5b0576e4b66d2fcc61a6ab9bfa7b279eb`. All three cases executed once (one PASS, two registered RED; zero skips/missing/duplicate/abnormal); harness exit 0, not product acceptance. Cylinder and Vase substantive ledger fields and full raw logs match TB127 after only ms timings and GoogleTest GetParam byte-dump normalization. Both RED assertion lines remain 493/495. BunnyRandom's entire permitted-normalized prefix before the terminal is identical, including all four mandatory-edge inventory records and upstream receipts; substantive census ledger fields also match TB127.

| Case | Result | Recorded evidence |
|---|---|---|
| Cylinder | PASS, 288 output quads | Identical normalized log. |
| BunnyRandom | RED, zero output faces | Source vertex 3; `ArcTraceTerminalCutPositionMismatch`. |
| Vase | RED, zero accepted faces | `AggregateCompletionValidationFailure`; 189,462 segments, 26,817 arrangement cells, 67,750 internal quads. Identical normalized log. |

BunnyRandom terminal verbatim:

```text
terminal=NotProductionReady:surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent detail=CellularityNotEstablished traceSegments=0 arrangementCells=0 completedQuads=0 completion= locus history=0 vertex=3 rotationReason=ArcTraceTerminalCutPositionMismatch
```

The forbidden TB127 face-contact terminal and all other RA-249 forbidden reasons are absent. The predicted O46 downstream ownership terminal **does not occur**: arc construction still rejects before the rotation/ownership proof. No `RotationEdge*` on (241,251) or (251,278) occurs, so the specific direction falsifier does not fire; direction remains unproved. No claim that FC-1–FC-5 or C5 is closed.

## Candidate root-cause assessment (not independent adjudication)

- **New row 952, test witness/conversion mismatch:** `sameDoubles` compares `static_cast<double>(FieldExactRational::to_double())`; `FieldTransportAtlas.h:522–524` delegates to `ENumber`, and `ENumberGMP.h:147` uses `value.get_d()`. The test assumes round-to-nearest at `FieldAlignedCurveNetworkTests.cpp:18707–18717,18782–18783`. GMP truncates toward zero (existing [lesson](LESSONS.md#geometry-topology-and-mathematical-obligations), “A double is a lossy, mode-dependent image of an exact value”). The positive exact `1/2 - 2^-60` in `nearB` therefore converts to the representable value below `1/2`, while `1/2` converts exactly. This explains the fatal precondition failure without establishing a ray-order predicate defect. Do not remove the discriminating same-double requirement or redefine conversion globally to get green. Review must derive a valid exact witness under the actual conversion contract and verify all remaining expected orders independently before freezing a correction.
- **Rows 644/669/698/858 and BunnyRandom, A2a′ terminal cut/event ownership candidate:** `EmbeddedGraphTopology.cpp:1006–1079` builds ordered `TraceCutPosition` cuts; face-contact terminal records insert `(segment_count, nullopt)` and set `hasTerminal`. The remaining event loop sets `hasTerminal` for a terminal role, but `trace_event_position` (lines 154–204) also accepts the origin-node/no-edge shortcut at 0 and unique carrier matches at arbitrary segment boundaries. The new observed reason selects the guard branch with `hasTerminal=true` but final cut key unequal to `(segment_count, nullopt)`; it emits `trace.sourceVertex`, not `sourceFace`. This explains the changed locus class in BunnyRandom and is consistent with the prescribed-sphere receipts and row 858. The latter log alone does not identify the subreason or exact locus. The branch existed before CB149; the switch can expose it after the earlier no-edge event rejection clears. Which actual terminal event, trace, cut key and source record produce the mismatch (and latent versus introduced status) remain unproved. The Review must reconcile event role, terminal point, carrier-match order, skipped face-contact incidences and cut extent against the canonical network; do not infer the terminal from the origin, append a guessed cut, fabricate a face for a vertex rejection or weaken the guard. Determine the enduring display contract and use a reaching, source-authoritative witness for each locus kind.
- **Row 164:** equal record multiset but different emission order; suspected logging/interleaving rather than product mutation, causal proof not given by the log alone. Preserve strict MISMATCH; any allowance requires separate Review authorization and a demonstrated order-independent diagnostic contract.
- **Vase / Cylinder:** no new regression; same normalized evidence. O46 and the middle-piece witness are unreached/unproved. No additional execution or test repair is authorized in TB128.

## Disposition and next turn

Stable 66 events / 17 categories / 49 recurrences remain; debt 1, deferred 81. The previously green required row 858 is lost in this candidate, but stable regression classification and accepted-prefix effects require independent adjudication. CP2 491/491 remains historical accepted authority (package `11391685901`); CP3/selector497 and D0 are unpromoted. C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed; middle-piece direction witness open; D11=A, D12=A, D10 deferred, D6 pending, `chainRimSchedules=false`.

Exactly next per the frozen mismatch route: `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-REV` (independent Review, runtime-free). Re-open primary archives and adjudicate the candidates above. Do not start the MATCH-only outcome Review, CB150 or FC-6 switch before that decision. No correction plan is accepted by this execution report.

## Continuation and evidence retention

The [same-turn continuation record](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb128_p13_face_contact_full_gate_continuation_20261117md) contains the earlier in-progress dispatch and gate evidence; this report supersedes its pending-status prose. The prior snapshot at `93f53bcd82e96e0e3163a75304e197191287999c` was reused for closeout after a remote compare to resume commit `60ad08bfce2429b285cc960e7bf0973786461d80` confirmed only the added continuation, dispatcher request, removed snapshot marker and root STATUS changed. No intended closeout path changed. The two comparisons were read-only archive checks, not Directional runtime reruns. The earlier cleanup [run 44059234357](https://github.com/akashskypatel/Directional/actions/runs/44059234357) succeeded, result `14316553374`, log `14316807941`; snapshot marker and cleanup manifest absent; durable request slot retained. Unrelated pre-existing legacy controls not modified. Prior attempt had late timer/policy/read-mode loading; exact combined tool accounting and full prior checklist completion cannot be certified.

Primary raw archives, independent comparison output, frozen manifests, requests and package/snapshot verification receipts are retained in the File Library evidence bundle `Directional_TB128_verified_evidence.zip` under `/Directional/Evidence/`. The audit and documentation patch transport do not change semantic source or runtime authority.
