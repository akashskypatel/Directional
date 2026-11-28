# CB-206 — slide-entry activation (2026-11-26 UTC)

## Situation

`M6-CP3-CB-206-P13-SLIDE-ENTRY-ACTIVATION`: exact reviewed activation compiled. No runtime execution or activation acceptance.

## Background — exact authority

| Evidence | Exact authority |
|---|---|
| Reviewed difference | [Exact manifest](gates/Architecture_M6_CP3_CB206_P13_Slide_Entry_Activation_Exact_Manifest.md); 6621 bytes, SHA-256 `e1be85e05c505490b6025c9982b5857e612b7c28cfc1cc9198cefba669339cdb`; two paths, +17/−35. |
| Snapshot | [Run 45856966196](https://github.com/akashskypatel/Directional/actions/runs/45856966196), job `140037874510`, source `1a6ca0416e3337e4982c5800c5e0d1dcefb405a9`, artifact `15136492775`, ZIP SHA-256 `96331624a513e46122bf9060f952adc9fdc0b12537e771ab7e8c763aea345e7f`, source archive SHA-256 `2869b3c5b9fa0879306a3ad20db2906b04f0e8bc1c0852f63880fb6be51cbef0`, 5851/5851 checks. No product/test differences from accepted `9d69f8e568cad9253f8e0ac0efd1d61bc073840b`. |
| Source application | [Run 45857398257](https://github.com/akashskypatel/Directional/actions/runs/45857398257), job `140039561015`, request `2c5fb221d6f452f74418159e41119229fbc4c56f`, source `2d62bf3b15f4571504fddd21bafbdd9019f0eeb9`. Patch SHA-256 `45c296fcb6431e6013e35732d1421b9407908060f9291473159f9f1ff5743dd6`, diff body `4706087edb04489553d8a37ea1d3ed4e1a51ff0fe50ed6da39c1d7e40798f1f8`. Result `15137105311`, ZIP SHA-256 `1ef00528fcbe235404a710a0ff42f670bfbb2f5400996a46e6836c5c44cdde2b`; log `15137065304`, ZIP SHA-256 `bf9f70b8dbe325c00c203605ba2f418fee58b3d2e009b8591d9c12bc99e5d5a8`. Apply/push exit 0; owner-authorized connector deleted staged Drive file after verification. |
| Compile | [Run 45857779921](https://github.com/akashskypatel/Directional/actions/runs/45857779921), job `140040812760`, request `fbf85f2b503c7f19d467080aef830657c7d791bd`, source `2d62bf3b15f4571504fddd21bafbdd9019f0eeb9`. Configure, preflight, compile passed. |
| Candidate | [15136691967](https://github.com/akashskypatel/Directional/actions/runs/45857779921/artifacts/15136691967), ZIP SHA-256 `5b2ae326640d0b55feedeeeb46faf1c389dc110177307fafedea8e2759a40127`, root manifest SHA-256 `0a35cc8e36ec86c3a70fe40e709dbd6f4f4440fb7fc8071f66c667db98ca827f`, source archive SHA-256 `3ca963601fe85a5982375c16a6b507c461a2c1ce613ab7532f9469b873dc6f95`; 28/28 checks, expires 2026-12-03T16:23:46Z. |
| Compile log | [15136049360](https://github.com/akashskypatel/Directional/actions/runs/45857779921/artifacts/15136049360), ZIP SHA-256 `4f732902f26b89e0f3d055a18c7ab8e8e3bc0e46e7f8c91c5335e5d839553abc`. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, five empty source status files, preflight and build exit 0, GMP and GMPXX link evidence; two libraries and six executables. |

## Assessment

The exact reviewed default changes from `false` to `true` in `canonical_field_aligned_candidate`; explicit controls remain. The authorized test changes are limited to rows 648/978/979, including positive production cut and plan predictions. Row1006 source is unchanged. No other product, test, fixture, selector or harness change. Git patch and whitespace checks passed. The source pre/postimage hashes are:

| Path | Preimage SHA-256 | Postimage SHA-256 |
|---|---|---|
| `src/geometry/SurfaceCellTracing.cpp` | `4b2e56873e3e2464621738633509a9540389516fddc1686bb4fe84d773be53fb` | `ad3c5ea3a9f73031e076330ab583b9951dadb6f92b1174991f521cc31a5c0de1` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `39b22f998b29b9662640e1212440db3d3f997bd1e1eba8c5492fa25b350efc48` | `073d5254b055a74ac32e6509418375c3ad31058c20f263139f5f5481e81017da` |

All 1169 archived regular files checked against the snapshot and exact applied change. Only expected control differences: `.agents/Directional/agent-dispatch-request.json`. No local compilation, test discovery, test or benchmark execution. TB187Q remains accepted 1006/1006 preactivation, CP2 491/491 remains accepted. Stable 67 events / 17 categories / 50 recurrences; witness debt1/deferred81. QF1 non-stable. P1 supported, D-U carried. No CP3/497/D0/H4 promotion or J6/E5/CB-190 repair. Activated sphere and close_sheets termination and row858 premise are unproved.

### Closeout checks

- [Cleanup run 45857827478](https://github.com/akashskypatel/Directional/actions/runs/45857827478), job `140040815177`, result `15136403679` ZIP SHA-256 `2da20ce2e3373aef45a0bac492efc23e7ce84e4ef912a40576aba6a5c4e4a60d`, cleanup commit `b2ac29d1562a281b5134d8fddf3339f80f16b204`. Temporary snapshot marker and cleanup manifest removed. Durable workflows and dispatcher preserved.
- Process limitations: initial repository reads preceded full snapshot-mode selection; complete mandatory pre-work policy/LESSONS review is not established. Initial application request was written without the local payload writer; the workflow verified the exact SHA-256. Full-turn tool ledger not retained through context compaction. No successor work performed.
- Documentation drift audit: zero errors; existing ORIENTATION size warning.

## Recommendation — next separate turn

`M6-CP3-TB-EXEC-186T` only after CB-206 completes. Use the [frozen six-row census contract](gates/Architecture_M6_CP3_TB186T_CB207D_Activated_Sphere_Termination_Exact_Manifest.md) and candidate above. No gate credit. All OBSERVE; no membership ledger or reach-termination diagnostic mode. Harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`; manifest SHA-256 `80970f595b3fe0d46fca08ae47fae1f53567a6d2b9b500ec34f74de24019eefc`. Rows 648/843/844/858/979/1006, 600 s cap per row; no rerun or rebuild. Preserve per-row verdict, exit, elapsed, peak RSS, cutoff marker, raw log hash, first failure and exact receipts specified by the frozen contract. STOP only on provenance/package/postflight failure; an organic RED is data. Then TB-REV-186T independently adjudicates cutoff and row858 premise. Do not apply CB-207D without the review's authorization. Full gate and V5 census remain held until the independent census disposition.
