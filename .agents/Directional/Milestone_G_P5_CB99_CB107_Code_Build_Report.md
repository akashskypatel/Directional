# Milestone G P5-CB99–P5-CB107 Code + Build Report

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Checkpoint

- Workflow-definition commit:
  `9aa4a5ecf156f8ba3f402f69bcfc655e2c85f322`.
- Exact implementation and compiled-source commit:
  `94bf8347b10eebcd8d3e777c6f5f0a2227283a2e`.
- Compile-only workflow run: `30867891341` — **success**.
- Compiled artifact: `8876934846`,
  `surface-cell-p5-cb107-github-source-linux-release`.
- Artifact archive digest:
  `sha256:ba06737ab313f30e23c74f402114649ee2c9f9d7c3a7177c7e0ba3328749df47`.
- Mandatory workflow-log artifact: `8876935182`,
  `surface-cell-p5-cb107-workflow-logs-30867891341`.
- Log artifact digest:
  `sha256:465aad3a957b99fdb8e7bf76b2040facc25b1ea1b2c00bfdca1d58990f1498dd`.
- Packaged fixture files: **26**.
- Packaged checksums independently verified: **39/39**.
- Packaged source status: empty.

The workflow compiled only the required targets and did not execute a test,
benchmark, custom mesh, or compiled project binary.

## Compile evidence

| Target | Result | SHA-256 |
|---|---|---|
| `directional_core` | compiled | `ad538940c622a28b2b88766a1bda5b8179b71c619376b273d144bccebd16c807` |
| `directional_pipeline` | compiled | `c781034ba0c5fd25b312b620388ac7aecf23c8eb8500dd189168aa11a2bd3fca` |
| `directional_phase1_tests` | compiled, not executed | `77c7ccb483795768010cb21d48d9d8006c342f060102f2176adba09d3c7ed280` |
| `directional_benchmarks` | compiled, not executed | `cb69ee8fa93a37ff7632cd83a392c89413882060f34c414bd7c713f07b1318f6` |

Configuration used Ninja, Release, GCC 13.3, CMake 3.31.6, static libraries,
and disabled optional GMP, PARDISO, cuDSS, and SuiteSparse backends.

## Source changes

### P5-CB99 — canonical physical cell-side ownership

- Added an explicit canonical source-ownership class to arrangement cells and
  domain identities.
- Added an exact sorted per-source-face chart map
  `(component, source face, local sheet)`.
- Built physical ownership classes from intrinsic stitched-DCEL adjacency;
  same-face local labels are never joined merely because they are nearby or
  share numeric values.
- Kept rail lineage independent from source-sheet identity.
- Removed the invalid requirement that every valid multi-face cell use one raw
  `localSheetByFace` ID.

### P5-CB100 — simplification propagation

- Structural hashes and storage accounting now include canonical ownership and
  exact chart maps.
- Candidate extraction compares canonical physical ownership rather than raw
  local-sheet IDs.
- Transactional cell merges require compatible canonical ownership and preserve
  the union of exact per-face charts.

### P5-CB101 — parity and subdivision authority

- Parity/subdivision preflight validates each oriented edge against the
  committed canonical ownership and exact chart map.
- Canonical cells no longer fail solely because adjacent source faces use
  different local chart IDs.
- Rebuilt edges and node occurrences retain exact source-face chart records;
  legacy unit fixtures retain their strict legacy path.
- Rollback identities include the new ownership records.

### P5-CB102 — completion ownership and reuse dependencies

- Patch-domain identity, conflict classification, and completion dependency
  keys now include canonical physical ownership and exact chart maps.
- Same-source-support comparisons use the canonical ownership contract instead
  of raw representative sheet equality.
- These changes allow exact completion reuse to reach its existing dependency
  and rebind validation path after the mixed-chart precondition is removed.

### P5-CB103 — intended invalid-midpoint fixture

- The malformed-midpoint fixture now supplies a valid common source chart on
  the forward and twin records before introducing the malformed midpoint.
- The intended runtime contract remains
  `InvalidMidpointEmbedding` after temporary mutation with exact rollback.

### P5-CB106 — ownership accounting extension

- Logical and retained-capacity accounting includes exact chart-map storage and
  canonical ownership vectors in arrangement, patch, repair, and simplification
  products.

### P5-CB107 — regression and compile gate

Added compile-valid regressions for:

- adjacent per-face charts sharing one canonical physical ownership class;
- disconnected close sheets retaining distinct ownership classes;
- the corrected invalid-midpoint precondition.

The workflow checksum-verified the reviewed patch, committed the exact source,
pushed it to the working branch, verified the remote SHA, compiled the four
required targets, packaged the 26-fixture closure and source archive, and always
uploaded detailed activity logs.

## Runtime acceptance not claimed

This was a code + compile-only turn. The following acceptance gates remain
unverified until the next artifact-only test and benchmark turn:

- restoration of all 22 P5-TB17 assertions;
- positive exact completion reuse and mixed reuse/recompute counts;
- canonical open-cylinder incidence/topology closure;
- nonempty valid direct production outputs without fallback/recovery;
- at least 75% categorized peak-RSS ownership reconciliation;
- deterministic random-bunny output or the next authoritative typed failure.

No test was weakened and no runtime result is inferred from compilation.

## Next turn

Run **P5-TB18 artifact-only test and benchmark** directly from artifact
`8876934846`, without rebuilding or modifying source. Start with the focused
P5-CB99–P5-CB107 regressions and Phase 14–18/Milestone D closure, then execute
the production fixture matrix, deterministic random-bunny face-edge and smooth
paths, reuse assertions, and memory reconciliation gates. Use any first invalid
producer and typed evidence to define the next code + build turn.
