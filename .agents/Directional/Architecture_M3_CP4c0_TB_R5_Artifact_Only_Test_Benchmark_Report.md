# M3-CP4c-0-TB-R5 — Artifact-Only Test + Benchmark Report

**Status:** COMPLETE / VALID SEMANTIC RED
**Turn boundary:** Test + Benchmark, artifact-only. No build, repair, source/test/fixture/selector mutation, or acceptance rewrite.

## 1. Immutable authority

| Authority | Value |
|---|---|
| Semantic source | `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e` |
| Immutable package artifact | `9601160869` |
| Package ZIP SHA-256 | `143cab907b4086a3f3bfc6f29dfdbb103919c9429698b0cce0757ae16f36cefb` |
| Packaged source archive SHA-256 | `f7f2e59cf9866beb8e784aeaefc2320cc2306a49ab1813133b7e343d5f3e35e3` |
| TB control SHA | `3f9864fddef696dc7d95084fdd41b680a78f5b37` |
| Hosted run / job | `32994846466 / 98261255799` |
| Result artifact | `9616160533`, ZIP SHA-256 `1ecfd85f06b40466f0e8193d1603950cd93b120723568024a1b50595e9902ad8` |
| Diagnostic artifact | `9616161522`, ZIP SHA-256 `7cb10caee2f1e861368da3098e320f10bee3b13d51439bc868e1e3c60aa14b0e` |

The package internal `SHA256SUMS` verifies **27/27** before and after runtime. `metadata/source-commit.txt`, build/preflight exit codes, clean source-status files, and `runtimeExecution=false` all match the CB5 authority.

## 2. Frozen selector and fresh-process gate

The packaged selector is unchanged:

- 338 SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
- first 316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- first 328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.

All **338 identities executed in exact selector order, one identity per fresh process**. Result: **338/338 PASS**, accepted prefix **316/316 PASS**, first-328 **328/328 PASS**, `first_red_ordinal=0`. Static dispatch resolved every identity uniquely to the packaged authority-kernel, producer, completion, or validation target.

F3 executed its two required supplementals in separate fresh processes and is **2/2 PASS**. G5 and H1 were then executed separately and remain explicitly **non-gating / uncredited**. Total fresh semantic processes: **342**.

## 3. G5 — sphere A2a outcome remains the same

G5 is PASS/non-gating and the prescribed sphere still does not publish a network. It reports:

- `networkError=BranchTransportFlowDisagreement`;
- source edge `6-8`;
- source face `6-8-9`, branch `3`;
- related face `6-8-97`, branch `1`;
- `signedLift=2`;
- trace seed `0/0`;
- seven ordered trace-history steps from `0-1-2` branch 0 through `6-8-9` branch 3.

This is the same live condition adjudicated after TB-R4, now with H2/H3's exact lift/history publication.

## 4. H1 — A1-only cross-face flow-agreement census

H1 is PASS/non-gating and emitted all four required witness summaries plus every violation locus.

| Witness | Pairs | Violations | Rate | Published signed-lift counts among violations |
|---|---:|---:|---:|---|
| two-ring | 160 | 4 | 2.5% | `0:4` |
| four-triangle-fan | 32 | 2 | 6.25% | `0:2` |
| prescribed sphere | 2304 | 144 | 6.25% | `-3:8, -2:6, -1:7, 0:102, 1:7, 2:6, 3:8` |
| torus | 1728 | 240 | 13.8889% | `-3:6, -2:11, -1:11, 0:184, 1:11, 2:11, 3:6` |
| **total** | **4224** | **390** | **9.23295%** | lift 0 dominates |

Representative exact loci establish that the census is not only reproducing edge `6-8`:

- two-ring: edge `0-5`, branch `2 → 2`, `signedLift=0`;
- fan: edge `1-4`, branch `1 → 1`, `signedLift=0`, both published `d[opp]=-1/2`;
- sphere: edge `0-1`, branch `2 → 2`, `signedLift=0`; edge `6-8`, branch `3 → 1`, `signedLift=2`;
- torus: violations likewise include a large lift-0 population plus symmetric nonzero lifts.

### H1 classification

Machine classification: **`H-B_OR_OTHER_SPARSE_REVIEW_REQUIRED`**.

The frozen hypotheses can now be narrowed without guessing a correction:

1. **H-A excluded.** Violations are not restricted to odd lifts. In fact the two-ring/fan violations are all lift 0, and lift 0 accounts for 102/144 sphere and 184/240 torus violations. Even ±2 violations are also present.
2. **H-C excluded.** A1 is not clean: 390 disagreements exist before A2a tracing. The prior sphere failure therefore cannot be attributed only to a branch A2a carried into otherwise-sound A1 authority.
3. **~50% systematic-index branch unsupported.** Per-witness violation rates are 2.5%, 6.25%, 6.25%, and 13.8889%, not approximately one half and not uniform.
4. **H-B remains plausible, not proved.** H1 does not establish singularity localization, and the manually prescribed fan also has two lift-0 disagreements although its matching was not computed through the aliasing path. Independent review is required before changing matching or transport semantics.

## 5. Frozen Q8 evaluation

Q8 is **creditable** because package integrity is exact, gate is 338/338, and F3 is 2/2. Frozen criteria remain unchanged:

| Criterion | TB-R5 result |
|---|---|
| 1. accepted 316/316 green | **PASS** |
| 2. prescribed sphere publishes 24 traces | **RED** |
| 3. at least one terminal `TraceIntersection` | **NOT_EVALUABLE** |
| 4. face `1-2-5` crossover choice/flip | **PASS** |
| 5. torus mechanical A1 failure unchanged | **CARRIED_UNCHANGED_NOT_RERUN** |

Binding reason: `criterion2_sphere_network_not_published`. This red was expected because CB5 was diagnostic-only and changed no production semantics.

## 6. Postflight integrity and orchestration disposition

Postflight compares package files, packaged source, fixtures, selector, and producer executable against their pre-runtime SHA-256 inventories; every comparison is identical. `manifest-post.txt` is 27/27 PASS. `orchestration_errors=0`. No configure, compile, relink, repair, generated discovery, or performance benchmark occurred.

Two owner-authorized self-hosted attempts during the GitHub-hosted Actions outage are **not** semantic evidence: `32993852779 / 98257876870` and `32994482392 / 98260020875` both stopped at immutable control-payload hash verification before the TB script or any Directional binary executed. Checkout line-ending normalization changed the staged shell-part bytes. Hosted run `32994846466` is the sole TB-R5 runtime authority.

## 7. Regression accounting and successor

Accepted CP4ab authority remains green at 316/316 and CP4c-0 has never been accepted. TB-R5 continues the existing non-stable sphere/A1 candidate and introduces no stable regression event. Stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt **5**; M3 packages **44**.

**Exact successor:** `M3-CP4c-0-TB-R5-REVIEW-PLAN`, independent review/planning only. Do not retry TB-R5, patch production, or enter CP4c-1/2/3 before that review.
