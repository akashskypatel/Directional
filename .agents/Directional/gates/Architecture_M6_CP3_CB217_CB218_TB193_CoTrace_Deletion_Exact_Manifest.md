# CB-217, CB-218 exact manifests and TB-EXEC-193 contract (2026-11-27 UTC)

Authority:
- [DEFN-P13-A2A-PARTIAL-COTRACE-REMOVAL](../Architecture_M6_CP3_DEFN_P13_A2a_Partial_CoTrace_Removal_20261127.md);
- DESIGN §7.2.1 Amendment 35;
- [TB-REV-192 adv.](../Architecture_M6_CP3_TB_REV_192_Adversarial_Review_20261127.md) EE1–EE5.

Both CBs are Code + Build only:
- apply exactly one diff;
- compile the eight GMP/GMPXX targets with `runtimeExecution=false`;
- STOP on any hash, path, patch or compile mismatch, and do not adapt.

## `M6-CP3-CB-217-P13-UNIQUE-ARRIVAL-CLASSIFICATION` — A2a, compile only, behaviour-neutral

Diff [`Architecture_M6_CP3_CB217_P13_Unique_Arrival_Classification_Exact.diff`](../Architecture_M6_CP3_CB217_P13_Unique_Arrival_Classification_Exact.diff): SHA-256 `d3d3102e85a372d5b5cf4e999fef6caf0852efb3581336f4ba922f566626aff8`, 15,476 B, +190/−31. It applies on the TB192 executor source `c76e74b3…3033` (current HEAD product state).

| Path | Preimage SHA-256 | Postimage SHA-256 |
|---|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `7fcb9fc2f30b4856f11fe8357c2e91fbf4a1c5d927a878cfeda7d0c9d8def49e` | `57097999e067402204bef603b40ca24f966fdaf562596a425da125c6e4ebc22a` |
| `src/geometry/SurfaceCellTracing.cpp` | `d6dbb123c7d86db3f12032c7827dc68c1b4629c328cfcea956bd7fa010bc650a` | `aed2930648277451c90b94a386d2c00c4d09de6aa385eed118ade7fd2de7bf80` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `9b08f17416d2a9468e6a8668793429b02b4cbc4d167b488e35bfb2f762cf338b` | `c220a00af5ad8d6da07adb604d9165e275d6cff837e29f9401877fbb29751994` |

Content:
- `classify_field_aligned_candidate_arrivals(candidate, rays, attachments)` collects every matched slot. It returns `FieldAlignedArrivalPortMatch::{Unique, NoPortSlot, SeveralPortSlots}` with each arrival.
- The public `classify_field_aligned_singularity_arrivals` keeps its signature and wraps the new function.
  - On ambiguity it returns `nullopt` (fail closed).
  - With no match, `port` stays empty, as before.
- No production caller is added.
- New test (row 1011): `FieldAlignedCurveNetwork.CandidateArrivalClassificationRequiresExactlyOnePortSlot`.
  - The candidate-level and network-level results agree on the mechanical fixture.
  - Node order does not change the result.
  - Injected rays produce `SeveralPortSlots` and `NoPortSlot`.

## `M6-CP3-CB-218-P13-CLAIMED-COTRACE-DELETION` — A2a, compile only, on CB-217, option default off

Diff [`Architecture_M6_CP3_CB218_P13_Claimed_CoTrace_Deletion_Exact.diff`](../Architecture_M6_CP3_CB218_P13_Claimed_CoTrace_Deletion_Exact.diff): SHA-256 `b0be915a4fd5f967a96e354fb6fa2fb78eaba6849028b12014eb50bae98cfab5`, 32,417 B, +498/−12.

| Path | Preimage SHA-256 (CB-217 postimage) | Postimage SHA-256 |
|---|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `57097999e067402204bef603b40ca24f966fdaf562596a425da125c6e4ebc22a` | `522cfebbf90dcb806cd9f4f9caf9add379777145689cc75ed73c4aff2beae387` |
| `src/geometry/SurfaceCellTracing.cpp` | `aed2930648277451c90b94a386d2c00c4d09de6aa385eed118ade7fd2de7bf80` | `3a67db446800efe1378c04a1471d64926e2aad88214cfa635c28ce1a3de7c09c` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `c220a00af5ad8d6da07adb604d9165e275d6cff837e29f9401877fbb29751994` | `d02c8507f56f5d7bb55fb909bd74cd614bf60203abcc8a1d6ea91d0d99360bc8` |

Content:
- `surface_cell_tracing_detail::field_aligned_delete_claimed_co_traces` runs right after `field_aligned_select_retraced_traces`, only when `deleteClaimedCoTraces` is true.
- The option defaults to false. It is threaded through both canonical functions, `validate_field_aligned_candidate`, `make_from_candidate` and `diagnose_with_arrival_priority`. `make` is unchanged.
- Five new `InvalidNetworkTerminalOwnership` conditions, values 13–17, each with a name:
  - `CoTraceDeletionArrivalMatchesNoPort`
  - `CoTraceDeletionArrivalMatchesSeveralPorts`
  - `CoTraceDeletionPortClaimedTwice`
  - `CoTraceDeletionClaimedTraceArrives`
  - `CoTraceDeletionKeptTraceEndsOnDeletedTrace`
- A rejection leaves the candidate unchanged.
- Node ids are re-indexed densely in id order across nodes, ports, mandatory edges and events. Trace ids are kept.
- New tests:
  - Row 1012: `FieldAlignedCurveNetwork.PrescribedSphereClaimedCoTraceDeletionKeepsOneTracePerSeparatrix`. With the option on it asserts EE3:
    - 24 ports;
    - traces {0,1,5,8,9,10,11,12,13,14,17,20,21,22};
    - `arrivalPort` 0→4, 1→6, 9→3, 10→23, 11→7, 12→19, 13→15, 14→2, 21→16, 22→18;
    - every port owned exactly once;
    - 12 dense nodes;
    - validation equal under the option.

    With the option off, the network equals the pipeline network (24 traces, no `arrivalPort`).
  - Row 1013: `FieldAlignedCurveNetwork.PrescribedSphereClaimedCoTraceDeletionRejectsInadmissibleClaims`. It has a positive control (14 traces), and each of the five conditions is injected from the valid sphere candidate.

**Verification (DEFN, syntax only, not compile evidence).** An independent Haiku pass found:
- both diffs apply in order and reverse to the preimages;
- every hash above matches;
- `clang++ -fsyntax-only -include iterator` gives 0 errors at preimage and after A+B (`SurfaceCellTracing.cpp` 40 warnings, tests 42, display 24);
- the warning multisets with locations stripped are identical, so no new warning;
- no plan identifier appears in the added code.

## `M6-CP3-TB-EXEC-193` — full gate on the CB-218 package

**Inputs:**
- the CB-218 package;
- harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`;
- **manifest [1013 rows](Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Full_Gate_Case_Manifest.tsv)**, SHA-256 `b910f2a96626660f46042c34360a8062c7546f35fb1980432d038ba8f41d2fc2`. Its header plus rows 1–1010 equal TB192's `c9f6325e…e9f5`;
- deferred `fd433f54…64ce` (81), so membership is 1094.

No rebuild, retry, timeout substitution or V5.

**Comparisons**, under N1–N3 against TB192 result `15195820651`:
- All 1013 rows must PASS.
- Rows 1–1010, **row858 included**, must be N1–N3-equal. This includes:
  - the 12 arrival lines;
  - the 27 sphere-carrying rows (380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858, 963, 968, 971, 972, 978, 979, 1006);
  - every named control.

  The default is off, and CB-217 keeps the public classifier's output wherever the match is unique.

**Predictions.** A mismatch is STOP for review, never a repair.
- Rows 1011–1013 PASS.
- A row858 change of `SphereSingularityArrivals … classified=1` to `classified=0` falsifies the inferred uniqueness of the sphere matches (EE5 / PC3).
- A row1012 failure falsifies EE3 or Amendment 35's sphere evidence. Record which assertion failed.

**Not allowed:**
- gate credit before `M6-CP3-TB-REV-193`;
- turning the option on anywhere outside rows 1012/1013;
- any change to tracing, D13 selection, A2b or A3, dispatch or the veto;
- B1 or fallback repair, CB-207D;
- promotion of CP3/497/D0/H4.
