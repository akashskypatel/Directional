> **SUPERSEDED (2026-11-09) by [RA-219](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Span_Switch_Takeover_Review_20261109.md).** This working document froze nothing and authorizes nothing. It is kept as provenance only.

# CB111 stop-set candidate — definition-turn preservation (2026-11-09)

**Canonical owner:** `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SPAN-SWITCH` (64B.3). **Draft only — NOT FROZEN, NOT APPLIED, NOT A CB turn.** This is a continuation aid subordinate to [RA-218](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md) and the [working review](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Span_Switch_Working_Review_20261109.md). Do not advance to CB111.

## Exact preserved candidate

- Verified source snapshot base: `82d74f543d51803f92002f156a4250f32bf968a1` (run `42699570720`, artifact `13710408472`; archive SHA-256 `73ed73f3fd0862810344a7b6f13f799107fd306b44152b79094659b0f88e91d1`; 5,405 file checksums).
- Candidate full binary Git diff (no special wrapper): `Directional__M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SPAN-SWITCH__base-82d74f543d51__CB111-review-candidate.patch`, **7,890 bytes**, SHA-256 `dd9ad6b73ea0fb0cd131e0ae5c1775a1a029ad95597f0383be62118fc70ff482`.
- User Library preserved at `/Directional/Work-Preservation/` under that filename.
- Google Drive `My Drive/Directional-CI` preserved raw diff file ID `1KLPuoh4twhUSXb8_iV4NfOW_OGuNDEv9`. Metadata checked: name, text/x-diff, size 7,890, parent `1I_-EViWSpaxg69pbglfPPVnFRYb1s5O0`. **Staged for preservation only, NOT dispatched or applied**; content-hash verified locally before upload, but metadata alone does not attest remote bytes.
- Intended exact three paths: `src/geometry/GlobalConformityBaselineSupport.{h,cpp}`, `tests/GlobalConformityBaselineTests.cpp`. Numstat 15/0, 45/0, 64/0 respectively, total +124/-0.
- Diff passes `git diff --check`; `git apply --reverse --check` on the edited synthetic snapshot and `git apply --check` on a freshly extracted pristine copy of those three source files. The synthetic index is NOT authentic repository Git history; no actual GitHub commit, compile, tests, benchmark, product or selector edits.
- Candidate reuses existing `FieldAlignedCurveNetworkNode`, `FieldAlignedSingularityPort` and `AdaptiveFeatureMap` types. It takes published feature `corners`/`junctions`, stops all matching graph nodes, requires typed port→node→source-vertex agreement, rejects duplicate node/port identities and invalid vertex bounds. It does not re-derive feature angles or wire A3.
- New proposed GTest checks feature and port positive stops, permutation invariance, unrepresented but valid feature corner, malformed feature indices, mismatched/missing/duplicate ports, duplicate nodes and invalid node vertex extent. Tests are *authored in the patch only, not executed*.

## Required follow-on inside this same DEFN

1. Critically inspect this candidate for compatibility with real port/node authority; in particular, do not require every feature-curve vertex to be an A2b graph node (only matching nodes become stops).
2. Freeze CB112's multi-piece curved-disk bridge, including how a schedule with **count smaller than source-piece count** is split into rational subintervals; audit every hard-coded unit-ordinal validator and pairing assumption before claiming behavior neutrality. The existing `SurfaceSharedBoundaryInterval` uses exact rational ordinal values but `summarize_a3_span_coverage`, front validation and hard-rail pairing demand width one.
3. Freeze CB113's atomic baseline input/validator/switch, retaining each original `ConformityBoundaryIncidenceId` while deriving **logical span ends by oriented region-side sectors**, not naive region-ID deduplication. Do not count every child incidence as a separate parity row on one chain, and preserve two true sides even if they belong to the same region.
4. Independently verify all three finished exact diffs, register separate compile-only CB and artifact-only full-gate TB predictions/falsifiers and stop paths, then complete the mandated Review policy closeout. No CB successor is authorized by this candidate alone.

The direct-read-before-snapshot preflight deviation from the previous attempt remains acknowledged; this continuation reused the previously verified exact snapshot because product/source semantics did not change. No tests or builds were run.

## Additional source-derived CB113 coupling census

- `src/pipeline/RemeshPipeline.cpp:1005–1015`: `make_global_conformity_baseline_input` currently receives only source vertices, target sizes and the A2b topology, emitting **one span for each arc**; the production call is at `:13016–13019`. The existing input type (`include/directional/geometry/GlobalConformityBaseline.h:181`) has no feature-map/network/stop authority. CB113 must bind existing upstream feature map, typed network nodes/ports and Mandatory hard-rail edges into the baseline input, or supply another independently re-derivable contract. An unattested precomputed chain map is insufficient.
- The baseline validator repeats `spans.size() == topology.arcs().size()` and maps region-boundary arc IDs directly to span IDs (`GlobalConformityBaselineValidator.cpp:354, 390`). The producer has the same assumptions (`GlobalConformityBaseline.cpp:287, 345`). Update both and validate child-arc coverage, canonical chain support, orientation, region-side multiplicity and parity; preserve original `ConformityBoundaryIncidenceId` records for provenance.
- The curved-disk consumer requires `supportPieceIndex == 0` (`SurfaceCellTracing.cpp:17642`), the uniform producer demands schedule-per-arc (`:18433–18441`), while `summarize_a3_span_coverage` and hard-rail pairing demand unit ordinals (`:9680–9730, :19087–19095`). The switch must represent legitimate fractional piece-scoped intervals without weakening reciprocal topology checks. `SurfaceSharedBoundaryInterval` already stores exact-rational ordinals; no parallel floating-ordinal identity is needed.
- The same baseline input factory is used by isolated tests in `FieldAlignedCurveNetworkTests.cpp`; baseline tests also construct inputs directly. Contract changes must account for them instead of making synthetic fixtures vacuously green or silently treating missing stop authority as permission to skip the switch.
- **No CB113 decision frozen:** region-side grouping, input authority, exact fractional-ordinal carrier and full-gate observable predictions remain active review work, not proof of impossibility.

## Third-attempt independent static verification and CB111 gate candidate (2026-11-09 22:28Z)

The 7,890-byte CB111 diff was checked against a **fresh copy** of the 5,405-hash verified source snapshot, not against the locally edited tree. Original Git blob IDs exactly match patch preimages:

| Path suffix | Original blob (matching patch index) | Patched blob (matching patch index) |
|---|---|---|
| `GlobalConformityBaselineSupport.cpp` | `131662adb8b5e290f874db0bac99b8004c8120d7` | `77220c731fc043ada1b2b4d5eb8e04ffc5c36512` |
| `GlobalConformityBaselineSupport.h` | `3706eb9fac97cd32272007d5a4fef2e48e8bb75d` | `7b9d810f879b8274c61d958801545b815dd56608` |
| `GlobalConformityBaselineTests.cpp` | `50c5aa169f1d32aa6655cdf974a57c255754fc5b` | `4110defe7ba3f811b03ed61f6cf8032aa6f20467` |

`git apply --check`, application and `git apply --reverse --check` succeeded on those files in an isolated temporary directory. These establish patch-byte fidelity, **not** C++ compilation or test success. The source snapshot-to-current-branch GitHub comparison contained only review documentation, a removed temporary snapshot trigger and `STATUS`, not product/test source edits.

An exact **candidate** TB94 gate manifest was created as TB93's unchanged 137,337-byte, 923-row prefix, plus one GUARD test `GlobalConformityBaseline.D5StopNodesUseUpstreamFeaturesAndPortBindings` (row 924). New manifest SHA-256 `d7eb8e8dd9045d33b68d15d3c6b2de22772167496ae3a7d04d2c0f6e441044b7`, 137,513 bytes, 924 distinct identities/tests. The unchanged harness `m6_cp3_targeted_artifact_harness.sh --self-check` reported `SELF_CHECK_PASS cases=924 deferred=81`. Two manipulated copies failed independently: duplicate row-924 identity (exit 1), nonsequential row number (exit 1). **These are static manifest controls**, not any native Directional gate. Candidate preserved in ChatGPT Library `/Directional/Work-Preservation/Directional_A3_CB111_TB94_Candidate_924_Cases.tsv` and Google Drive `My Drive/Directional-CI`, raw file ID `12gTYTXvZgmnYWxoDqtODQE0CST599E2A`. Staged, not dispatched or accepted. The CB111 source patch remains externally preserved at Drive ID `1KLPuoh4twhUSXb8_iV4NfOW_OGuNDEv9`. No CB111 implementation was entered.

### Newly proven periodic/cut-path coupling — do not miss in CB112/CB113

- `SurfaceCellTracing.cpp:16060–16066` builds `AcceptedCutBoundaryFaceAuthorityKey{raw occurrence, **child arc ID**, source edge}`. `:18875–18882` retrieves it using an argument named `span` but supplied as an arc ID. Under a multi-arc chain, passing only the first-arc logical span for a later child's source edge causes lookup failure. **Retain raw child-arc IDs in face-authority keys**; derive the full logical chain and its ordered occurrence run separately.
- `:18900–18913` resolves the 'generator span' by `find_arc(span)` and enforces `sourcePath.size() == 1`; `:19202–19217` requires a one-step route and one representative occurrence-carrier face on each side. These are independent single-arc assumptions, **not repaired** by updating the baseline incidence map alone.
- `:19023–19026` requires each pair's two endpoint states to reference the same raw occurrence. For one global output interval spanning multiple child arcs, an unchecked 'first occurrence' representative cannot prove all source-edge carriers. The exact solution must re-derive a complete, ordered per-child carrier/occurrence/face route (or prove an equivalently strict typed certificate) and verify reciprocal route inversion and periodic transport. Reuse the existing `CanonicalRoute` and exact source path/transport primitives; do not invent a chain identity or relax the one-unit final front check.
- `:9690–9720` counts `baseline.incidences()` to set expected **front interval multiplicity**. If those incidences remain per raw child as required for provenance, the count will be too large for a joined span. This counterexample is obligatory in CB113: a three-child chain, one global scheduled interval, two logical sides, six raw occurrences must expect **two** interval copies, not six. A single-region two-sided chain must similarly count two logical sides, not one deduplicated region.
- The existing `AcceptedCutBoundarySegment` already stores raw `incidence`, `arc`, `supportPieceIndex`, orientation, source-edge and source-face authority (`:15559–15570,15756–15759`). Reuse these rather than add a redundant parallel identifier or compress source provenance prematurely.

This substantiates a **cross-consumer design obligation**, not a proof that D5 is impossible: CB112/CB113 remain unfrozen pending a correct complete route/certificate and source-produced falsifiers. No review STOP or successor has been declared, and no build or runtime execution was performed.
