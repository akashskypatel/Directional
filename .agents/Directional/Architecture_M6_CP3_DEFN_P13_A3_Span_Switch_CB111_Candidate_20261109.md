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
