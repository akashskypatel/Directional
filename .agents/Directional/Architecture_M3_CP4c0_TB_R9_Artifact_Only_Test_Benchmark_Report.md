# M3-CP4c-0-TB-R9 — GMP Artifact-Only Test + Benchmark Report

**Status:** COMPLETE / GATE GREEN — **346/346; CP4c-0 CLOSED / ACCEPTED**
**Turn boundary:** Test + Benchmark, artifact-only. No configure, compile, relink, repair, generated discovery, product/test/fixture/selector mutation, or performance benchmark was permitted or performed during TB.
**Successor boundary:** `M3-CP4c-0b-CB1` is now the next eligible implementation turn, but it is **not authorized automatically** by this closeout.

## 1. Fresh immutable authority for the accepted re-proof

| Authority | Value |
|---|---|
| Semantic source containing both TB-R9 candidate corrections | `7bbc0480d9ab5954329b940992ef41a9223102ed` |
| Fresh compile run / job | `33079499974 / 98542697746` |
| Fresh immutable GMP package | `9649395432` |
| Package ZIP SHA-256 | `557207bf8f668884295258690e3bd31485cbd7709f0be47aa98daea0c53b3e2e` |
| Packaged source archive SHA-256 | `f58cfdc0d1886af11328f9b7dfaab8be1bd92d0220549a97d5954944ff7ac68f` |
| Compile log artifact | `9649395842`, ZIP SHA-256 `45c6c92fc92a6085780bd0b2f56e7ffb80bc3a4ecf8f2cda4744caf8de151179` |
| Exact arithmetic backend | `GMP` |
| TB-R9 re-proof control/event SHA | `392410f6e09e98d91ae5af40e01545449d3e5ccb` |
| Authoritative re-proof run / workload job | `33079817998 / 98543736213` |
| Result artifact | `9649625534`, GitHub ZIP SHA-256 `6cd4e3c21dc46fd7e0d6df2209ee5a382531d768f50ae52d190302e05bec02af` |
| Diagnostic artifact | `9649626115`, GitHub ZIP SHA-256 `3ba381cd12ec1188bd9ae36020d35bdaa458271ea2c7b1163aac31a9a474d7f9` |
| Frozen 346 selector | `Architecture_M3_CP4c0_Required_Green_Selector.txt`, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| Accepted first-316 prefix | **316/316 PASS**, SHA-256 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
| First-328 prefix | **328/328 PASS**, SHA-256 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600` |

The fresh compile used the durable reusable compile workflow and compiled/linked all eight standard targets. Package metadata records build/preflight exit `0`, clean source-status snapshots, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`; generated link evidence contains both `libgmpxx` and `libgmp`. The compile package is M3 package **51**.

## 2. Frozen TB-R9 test authority was preserved

The accepted re-proof did **not** edit the TB-R9 selector, test identities, fixtures, product source, or the test source during TB. The 346-line selector remains byte-identical at SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; its first-316 and first-328 prefix hashes remain unchanged.

The runner recovered the exact historical TB-R9 execution plan from git blob `af9d1c0adb713b6b154d96d5a5fb2c825bbf5981` and changed only its immutable package-authority constants to point at fresh package `9649395432`, source `7bbc0480d9ab5954329b940992ef41a9223102ed`, and their verified hashes. The plan retained the original execution semantics: accepted 316 block, earlier CP4c 12 block, first CP4c-0 8 block, and the final 10 identities as fresh individually bounded processes, aggregated to exactly 346 identities. Every identity retained the frozen 60-second stop bound.

The two prior test-side corrections were already part of the compiled semantic source before this TB turn:

- `M3-CP4c0-TB-R9-CAND-01`: backend-independent deliberately lossy `1/7` witness from CB-R10;
- `M3-CP4c0-TB-R9-CAND-02`: non-degenerate `{-2,1,1}` positive control with exact `1/4` edge exit from CB-R11.

Thus the TB-R9 **test/gate definition is unchanged**; only the defective test preconditions identified by the earlier valid RED run had been corrected in prior CB turns.

## 3. Complete frozen-gate result — 346/346 GREEN

The fresh artifact-only re-proof executed the complete frozen gate successfully:

- **346/346 PASS**, **0 RED**, **0 skipped**;
- accepted first-316 **316/316 PASS**;
- first-328 **328/328 PASS**;
- **346 unique identities selected / 346 expected**;
- **0 timeouts** at the 60-second per-identity stop bound;
- **0 escaping C++ exceptions**;
- **0 orchestration errors**;
- package/source/fixture/selector/executable preflight and postflight: **PASS**;
- package runtime mutation: **false**;
- Q8 criteria owned by CP4c-0: **criterion 1 PASS, criterion 4 PASS, criterion 5 PASS**;
- Q8 criteria 2 and 3 remain moved together to CP4c-0b by Amendment 11;
- no configure, compile, relink, repair, generated discovery, or performance benchmark occurred in TB.

The result ledger contains exactly 346 entries, 346 unique identities, and every entry is `PASS`. The test runner's final status is `success`.

## 4. Historical initial TB-R9 RED and candidate closure

The earlier authoritative TB-R9 execution `33048964354 / 98439563813` on GMP package `9634245265` remains valid historical evidence: **344/346 PASS** with accepted prefixes 316/316 and 328/328 green, Q8 criteria 1/4/5 green, no timeout, no escaping exception, and immutable postflight PASS. Its only two RED identities were localized to non-stable test-side preconditions:

1. ordinal 333 `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` — `M3-CP4c0-TB-R9-CAND-01`, test-side GMP portability;
2. ordinal 344 `ResolvedBranchCorrection.ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance` — `M3-CP4c0-TB-R9-CAND-02`, test-side fixture/precondition.

CB-R10/TB-R10 and CB-R11/TB-R11 individually corrected and focused-reproved those identities. This whole-gate re-proof now demonstrates that **both corrected identities pass in their original frozen 346-identity context** and that no additional regression was exposed.

The prescribed `M3-CP4c-0-TB-R9-REVIEW-PLAN` remains **skipped by explicit user instruction / not completed**. This report does not rewrite that historical operator decision as a review completion.

## 5. Acceptance, accounting, and closeout

The whole frozen CP4c-0 gate is now **346/346 GREEN** on a fresh immutable GMP package containing both candidate corrections. Therefore **M3-CP4c-0 is CLOSED / ACCEPTED**.

Neither prior candidate is an accepted-behavior regression, so stable accounting remains **42 events / 14 categories / 28 recurrences** and produced-witness debt remains **5**. The fresh compile advances the M3 package count to **51**. The latest accepted runtime authority is now this TB-R9 re-proof: **346/346**, run/job `33079817998 / 98543736213`.

`M3-CP4c-0b-CB1` is the next eligible implementation turn under frozen measures P0–P9. **Do not start it automatically**: this closeout authorizes only the requested TB-R9 recompile, whole-gate re-proof, and documentation closure.
