# CB40 independent review — selector 192/247 turning-field monodromy (2026-10-26)

**Canonical turn:** `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME-REV`  
**Disposition:** Source/test-oracle and compile-package evidence support **static approval**, conditional on the required genuine-Git boundary and ledger closeout. **Formal REVIEW closeout remains IN PROGRESS**; this record is not runtime acceptance or authorization to start CB41.

## Authority independently inspected

- Exact semantic source commit `0d227875d8f031a467e661be2da4dd901846797c`; 7-commit GitHub compare from `f262f153e8acc87c6c76e0e34d08841792ab5735` changes only `tests/SurfaceCellsPhase10Tests.cpp` on the implementation/test surface (+37/−12, plus an Eigen assertion compile correction +2/−2 on the final semantic commit). Other changes are request and STATUS control files.
- Compile run [40264202131](https://github.com/akashskypatel/Directional/actions/runs/40264202131); artifact `12625069994`; independent downloaded ZIP SHA-256 `0f5e554b975bd1306df587f7bb0031707136f2a629fb550beab61e02301e3d41`. All **28/28** manifest entries verified, packaged source matches the exact reviewed file, eight targets present, GMP/GMPXX linked with `DIRECTIONAL_ENABLE_GMP=ON`, compile/preflight exit `0/0`, clean source package, `runtimeExecution=false`.
- Current whole-source snapshot: commit `08bb7921dfe3e059066923ddc1d0a1dcdfc983e8`, run `40267335096`, artifact `12626459653`, ZIP SHA-256 `57841b3c82a9abcb67ed9bd7993a9f33fc60e5020d0ed6b972288a8cb66ac333`, source tree **5898/5898** file hashes verified, test source byte-identical to packaged compile source.
- PR #8 was verified open/draft, working branch `agent/surface_cell_quad/p5-recover-bridge-healing`. No source, tests, fixture, selector, build logic or benchmarks were changed or executed during this review.

## Independent source review

1. **Selector 192:** Previously mutated one directed edge matching and reached an A3-invalid cycle. The replacement derives `turning_periodic_route_field(fixture,1)` from the committed cylinder's face geometry/raw arms, asserts zero interior singularity indices, derives observed signed quarter-turn (`+1` or inverse), separately constructs `build_source_topology_regions` and requires `FieldTransportAtlas::make` success. The checked producer then receives the *same turning field* for both field and atlas generation. The unchanged positive balanced-field A4-produced baseline and the negative `Rejected/PeriodicHolonomyMismatch`, no product and typed `-1` locus assertions remain.
2. **Selector 247:** The previous local `transition->matching += 1` mutation was replaced by `turning_periodic_route_field(fixture,2)`. The test independently asserts the loaded mesh vertices, triangle faces and raw-field bytes correspond to the committed cylinder fixture; requires zero singular indices, observed half-turn `2`, and successful `FieldTransportAtlas::make` before injecting its resulting atlas and matching field into the A4 producer. The original A4 rejection reason and empty seeds/traces/proposals remain intact.
3. **Non-vacuity:** A3-invalid local perturbation no longer masquerades as a periodic A4 test. Different `k=1` and `k=2` stimuli explicitly demand different observed monodromy. Both demand atlas construction without error. The expected negative is the specific A4 `PeriodicHolonomyMismatch` rather than any failure; positive baseline is preserved. Tests are still **unexecuted on this artifact**; actual runtime assertion reachability and outcome belong exclusively to TB41.
4. **Compile-only assertion correction:** `Eigen::VectorXi.empty()` did not compile; the final change uses `ASSERT_EQ(0, singularIndices.size())` in two places. This retains the same zero-index requirement; initial failed compile is not erased or presented as a pass.
5. **Scope:** No product implementation/selector/fixture/benchmark code change; no selector497 or CP3 promotion. Accepted CP2 remains 491/491, reviewed TB38 candidate 490/504, stable 66/17/49, debt one, RP-01 open. Carry O1–O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 and TB41 execution ownership.

## Required historical boundary — unresolved

`python3 .agents/Directional/tools/review_check.py boundary` was **actually invoked and returned exit 1** on the verified GitHub-generated source snapshot. The snapshot intentionally contains no `.git` directory, so the checker cannot resolve the protected rewrite baseline or historical committed blobs; its apparent selector-untracked lines are **not** accepted historical checks. No successful authentic-history `boundary` or `ledgers` run is claimed. Complete them in a Git-aware authorized environment, then complete consolidation, drift audit, durable document updates and final STATUS before marking this REVIEW complete. Source/package static approval does not waive these duties.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Pending authentic-Git ledgers; no selector was changed |
| Decisive claims independently re-derived | Verified exact test hunks, raw-field/atlas/A4 dependency and 28/28 package + 5898/5898 snapshot hashes |
| Non-vacuity checked | k=1 and k=2 monodromy, atlas success, specific A4 rejection; runtime reachability not measured |
| Prior obligations discharged/carried | RA-155.3 B, RA-157.4 statically addressed; TB41, O1–O4 and listed carried owners remain |
| Stable accounting | 66/17/49 debt 1; CP2 491/491; TB38 candidate 490/504; selector497 unpromoted |
| New candidates/obligations recorded | No new semantic candidate; outstanding authentic-Git boundary and ledgers |
| ORIENTATION currency line | Pending review closeout; do not advance next turn before complete |
| ORIENTATION §3 / §4 / §7 / §8 | Pending review closeout; no witness status change demonstrated |
| CHANGELOG | Pending review closeout |
| ROADMAP | No checkpoint movement; currency check pending |
| Selector manifest | Not modified; no selector accepted or appended |
| LESSONS | Existing non-vacuity / build evidence principles; no new generalizable lesson |
| Consolidation under CLEAN_UP_POLICY | Pending review closeout |
| Successor frozen | CB41 test-only, RA-155.3 C; prohibited until this review formally closes |
| Turn boundary held | Yes; static review only, no runtime/product/selector/test change |
| review_check.py boundary | **FAIL exit 1 due absent Git history**; not a passing check |
| STATUS lifecycle maintained | Entry beacon published, final closeout pending; same turn retained |
| Pushed to origin, branch in sync | This record is committed by GitHub connector; authentic `git status -sb` check pending |

**Resume the same CB40-REV turn**, finish the required historical checks and documentation/consolidation, and only then publish a COMPLETE beacon with the separately authorized CB41 successor.
