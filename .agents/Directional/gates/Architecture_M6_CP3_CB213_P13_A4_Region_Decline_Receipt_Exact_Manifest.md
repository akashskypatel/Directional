# M6-CP3-CB-213-P13-A4-REGION-DECLINE-RECEIPT — exact diagnostic-only plan

Frozen by [Architecture_M6_CP3_TB_REV_189_Sphere_Route_Witness_Independent_Review_20261127.md](../Architecture_M6_CP3_TB_REV_189_Sphere_Route_Witness_Independent_Review_20261127.md). Not applied, compiled or executed in Review.

## Code + Build boundary

Apply only [the exact diff](../Architecture_M6_CP3_CB213_P13_A4_Region_Decline_Receipt_Exact.diff), 19,487 bytes, SHA-256 `c251d83bca68f1cf29adf694d679b57c211bc452e2ddae1fa77e53b2e326a035`, +156/-19. Source `39253c63c308a2699669095bdb12e4ece72d502a`; all four paths retain these exact preimages at the review snapshot. Verify and stop on mismatch; do not adapt the patch silently.

| Path | SHA-256 preimage | SHA-256 postimage |
|---|---|---|
| include/directional/geometry/SurfaceCellTracing.h | daf7b7a0c9fb66bcf58db10b534e502f7294463fb94fa7b4b30c10243e1f19d3 | 59d067acf6d3cfe39767c8e69b08c2d20a48d60e08f7e6fc31304eb6ba05c3c6 |
| src/geometry/SurfaceCellTracing.cpp | ad3c5ea3a9f73031e076330ab583b9951dadb6f92b1174991f521cc31a5c0de1 | 10117ad7db101725b76d686a187281ed237030606221bab76afbb0a9f81e958a |
| src/pipeline/RemeshPipeline.cpp | 5da1fcc98dcb08b21279a3ba59ccd81861bc1f2fc3f2d2bf2ba3acd2c979dd03 | c0dc8debed5e178b43d9ea2e0cbdf5c859d9848e9354467a792bd033ecabbf71 |
| tests/SurfaceCellTracingDisplayTests.cpp | 6149b26dc7564342261920c1b669e25dfd61cb3ba323cf844ecff07aa65f16cc | b268f4067ea6718179731796ec5d5648cab08173bc150f341536079e79a54ce1 |

The typed attempt receipt records source-region ID, actual producer, disposition, first decline predicate and failure reason before the scheduler overwrites the local attempt. Retention is opt-in via existing diagnostic retention. Early guard order remains the same; do not fabricate an attempt for an uncalled producer. Report `unclassified` explicitly for other paths. The display test appends actual source-region census and attempt receipts, plus plan-to-source support mapping. No assertion changes, no stage activation or repair. Support mapping is not proof of equivalent region ownership. Static exact replay and whitespace checks passed; no compiler or runtime verification performed. Compile with GMP/GMPXX only:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Require exact immutable compile package, 28/28 checks and runtimeExecution=false. Do not run executables. Stop on compile failure and retain evidence; any source change needs separately authorized review.

## Conditional TB-EXEC-190, then TB-REV-190

After valid compile closeout, use the same immutable executor/harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`, manifest `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587` (1006), deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81), membership 1087. Compare against TB189 result 15171482516. No V5, rebuild, timeout substitution or retries. Every row must PASS; N1–N3 comparisons unchanged outside row858. Preserve its prior 45 receipts and old transcript; only appended families below are allowed. Exact ordering follows the diff:

- One `SphereA4Attempts retained=1 sourceRegions=N attempts=M`, N > 0, with N distinct `SphereA4SourceRegion` entries.
- M actual ordered `SphereA4Attempt` entries: predict M=3N; each actual source-region ID has uniform, periodic-annulus, curved-bounded-disk attempts in that order. Predict all `NotApplicable`, predicate `global-singularity-ports`, failure `None`. Do not force N=14 or N=1. A different classified predicate falsifies the prediction; record it, do not repair it. Missing/unclassified, duplicate, unexpected producer or missing mapping is STOP.
- Fourteen `SphereA4PlanSupport` entries with exact prior plan IDs and support face counts, missing=0 and nonempty listed source-region IDs, all from the source-region census. This is source support, not equality of plan/source regions. No unpredicted material difference allowed.

Only the separate independent Review can accept the result. If the prediction holds, decide A4 ownership of closed-surface plan discs with boundary singularities and DESIGN §5.2 fallback in a separate DEFN. If not, retain evidence and reconsider the definition; no repair from this plan. B1 repair, B2 bounded BunnyRandom observation, CB-207D, CB-190, J6/E5, parameter deletion and promotions remain held. Stable counts unchanged.
