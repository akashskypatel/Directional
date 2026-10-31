# P13 — independent design-acceptance review and runtime-probe separation (2026-10-31)

**Current canonical turn:** `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` (Review/Definition). This record is the authoritative *review decision*, not runtime acceptance. Source for the review: exact snapshot `0a3f22557b651ab0e370b7cafd25f95efaf2e2b1`, 6,046/6,046 source hashes verified. [Provisional independent byte audit](Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Review_Working_Evidence_20261031.md).

## Independent platform adjudication and non-vacuity

- CB63 artifact `13043004468`, semantic source `f6113c4eb0fbf6a02350eee2d37e7e4dab821429`: independently rehashed ZIP `14b7589aba85ed1fa0fdf62d233007293150491d559820dc2b24b8e83df27462`, 30/30 package contents. Linux Release/static CLI and GUI compile/link, generated GMP+GMPXX commands, compile-only boundary verified; **no GUI launch/appearance claim**.
- TB62 result `13046191343`, ZIP `95a1b5f87b711e4a9587210fce9ff474623f078726e4c416f47ce2f4d0c5c303`: independently rehashed 1,734/1,734 contents and 863 separately selected raw logs. Frozen 863-row manifest `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`, v4 ledger 82 `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`, union/membership 945, zero duplicates/omissions and postflight true. 854 GUARD, 9 POSITIVE; each raw filter has exactly one matched RUN/OK/PASS. The eleven supplementary Linux CLI checks are retained in TB62's report, but not independently byte-audited in this review.
- The three passed direct-production controls (Plane `offgate:364`, MultiFaceSeam `offgate:363`, CloseSheets `offgate:361`) establish source-authoritative direct outputs for those fixture identities **only**. Cylinder, BunnyRandom, Vase are **DEFERRED** and did not run in TB62.
- The macOS O16 row283 remains carried from TB60, not discharged by the Linux PASS. DR1/DR3 remain open; DR2/DR4 remain owned by M8-CP2. Accepted CP2 491/491, selector497 unchanged/unpromoted, stable 66/17/49 and produced-witness debt1. No P13 or CP3 acceptance.

## Normative decision — separate execution from Review

`Future_Chat_Session_Handoff.md` calls this DEFN 'probe-capable' and calls for 300-second runtime probes. However, `REVIEW_TURN_POLICY.md` §4.3, `Turn_Cadence.md` §6 and `AGENT_POLICY.md` expressly make Review/Definition **runtime-free**. This is a genuine instructions conflict, not authority to ignore the durable policy. Resolve it by **retaining P13's product requirements and assigning runtime to separately frozen CB→TB turns**. The current DEFN can decide reachability obligations, immutable witnesses, registration and stop rules without running the binaries. No code, test, fixture, selector, benchmark, workflow, compiler or Directional executable is changed/executed here.

**Exact successor when this DEFN formally closes:** `M6-CP3-CB64-P13-ARTIFACT-PROBE-REGISTRATION` (Code + Build only). Register a three-row *separate OBSERVE census* and a bounded 300s case timeout in a deterministic artifact-only harness; do not rewrite the existing 863-case gate or 82-row v4 ledger, disable tests, or change the 600s production-gate harness behavior. Reuse existing frozen binaries where permitted; any mandatory CB compile must honor GMP/GMPXX and be compile-only. Freeze hashes, exact semantic package/runner identities and a comparison plan before executing. The CB may not declare P13 accepted.

**Conditional successor after valid CB:** a separately bounded `M6-CP3-TB63-P13-CYLINDER-FIRST-DIAGNOSTIC-EXEC` (artifact-only). It must execute and preserve the **full current 863-case gate** with v4 membership **and**, separately, an OBSERVE census of the three deferred design-acceptance identities on immutable verified package/source. Each census row is its own fresh process, 300s maximum, with bounded resource observation; execute Cylinder first, then BunnyRandom and Vase only under registered time/resource gates. OBSERVE cannot mix with PASS/RED gate rows, and observational PASS never promotes deferred membership. One 300s timeout is ABNORMAL/unfinished, never a successful negative. A semantic RED routes to independent Review + Plan; orchestration-only failures follow the separate correction cadence. Do not run TB from this DEFN.

## Six-fixture matrix and pre-registered falsifiers

Source: `tests/SurfaceCellDesignAcceptanceTests.cpp`. It invokes direct `remesh_from_raw_cross_field` with `SurfaceCells`, `fallbackPolicy=Fail`, `allowSourceGridRecovery=false`, and the separately implemented `surface_cell_oracle`. Valid acceptance requires `CompletedSurfaceCells` origin, positive pure-quads, manifold/source authority, no fallback/recovery, and independent oracle PASS; failure-closed/partial/stage-reached output is not a pass.

| Fixture | Identity | Evidence and next decision |
|---|---|---|
| Plane | `offgate:364` | TB62 gated PASS; preserve control |
| MultiFaceSeam | `offgate:363` | TB62 gated PASS; preserve control |
| CloseSheets | `offgate:361` | TB62 gated PASS; retain cross-sheet non-merge |
| Cylinder | `offgate:362` | Frozen ledger ABNORMAL/124 after 600s; first P13 diagnostic. Measure bounded termination, stages, periodic source-chart/phase closure, source-authoritative output and independent oracle |
| BunnyRandom | `offgate:360` | Frozen ledger RED; historical A3 cut Euler mismatch `expected=-5`, `observed=-3` (needs independently repeated first-failure proof) |
| Vase | `offgate:365` | Frozen ledger ABNORMAL/124 after 600s; verify actual earliest stage, O6 applicability and direct output under bounded time |

**O6:** `src/geometry/SurfaceCellTracing.cpp` presently rejects a nonrectangular `phaseRecord` at the bounded disk producer with `InvalidBoundedDiskFrontPairing` (approximately line 17208 in the frozen snapshot). This is a real *static capability gap*, not a proven first failure for Vase or Bunny. Check whether each case reaches the nonrectangular branch before assigning ownership or a fix. No generic rectangle coercion or returning partial quads.

**Exact atlas:** honor RA-176/RA-180/RA-181's exact-stored-double face gauge, port ordering, tie and half-open-sector rules; a row/permutation or FMA variance is a falsifier. Do not infer cross-platform equivalence from Linux alone.

**O9:** log `max(route.oriented_steps().size())` on *produced* A4 open-rail routes; any value >1 falsifies the existing accepted-defensive no-junction ruling (RA-178.3). Zero produced routes cannot prove the single-step bound.

**O15c:** independently log maximum exact A4 continuation width, plus any `BranchContinuationExactMagnitudeExceeded`. Current bound 4,096 bits; **>2,048 bits** or actual overflow triggers a separate exact-direction decision (RA-181). Previously reported sphere 1,531 bits is not a P13 fixture measurement. Do not instrument production or rely on unobserved values without an authorized CB.

**Stop rules:** Any gate RED, immutability violation, changed observed test membership, wrong SHA, missing GMP, absent required full gate, 300s timeout, invalid selection, unproven direct output, mixed OBSERVE/gate rows, or a source-sheet/feature provenance mismatch prevents P13 promotion. Preserve diagnostic RED/timeout even when the harness command itself terminates successfully.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | No selector changed; frozen 863-manifest and 82-ledger hashes independently verified; CP2 491 remains accepted |
| Decisive claims independently re-derived | Source 6046/6046, CB63 30/30, TB62 1734/1734 and each of 863 process receipts, 945 membership |
| Non-vacuity checked | Actual selected positive GTest receipts and independent product oracle; 3 deferred cases unexecuted rather than counted |
| Prior obligations discharged/carried | TB62 Linux compile/gate discharged at its scope; macOS O16, DR1/DR3 and DR2/DR4 carried; P13 Cylinder/Bunny/Vase, O6, exact atlas, O9, O15c carried to CB64/TB63 |
| Stable accounting | 66/17/49, debt1; accepted CP2 491/491; selector497 frozen |
| New candidates/obligations recorded | No new stable regression; P13 bounded probe registration and re-observation required; static O6 branch retained |
| ORIENTATION currency line | Updated to P13 review/CB64 boundary in same documentation patch |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 refreshed; §4 witness matrix retained, §8 n/a no newly confirmed defect pattern |
| CHANGELOG | P13 adjudication and future bounded execution boundary recorded |
| ROADMAP | M6-CP3 still unaccepted; P13 3 deferred; updated current platform note |
| Selector manifest | n/a no selector edit or promotion |
| LESSONS | Existing evidence and runtime-boundary lessons applied; no new universal rule |
| Consolidation under CLEAN_UP_POLICY | No eligible P13 historical file to fold: retained working audit is primary evidence and this is current decision; no deletions |
| Successor frozen | `M6-CP3-CB64-P13-ARTIFACT-PROBE-REGISTRATION`; bounds/falsifiers above; conditional artifact-only TB63 follows |
| Turn boundary held | Review-only static sources, immutable byte audits and docs, no Directional runtime or implementation edits |
| `review_check.py boundary` | **Not yet independently run against full real history in this response**; no unverified PASS claimed |
| `STATUS` lifecycle maintained | Resume entry beacon; final COMPLETE only after durable docs, checks and cleanup |
| Pushed to origin, branch in sync | **Pending** verification of exact documentation patch application and remote HEAD; do not mark complete prematurely |
