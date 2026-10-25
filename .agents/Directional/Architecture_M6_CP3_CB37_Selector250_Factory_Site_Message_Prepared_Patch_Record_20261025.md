# CB37 — selector 250 factory-site message: source patch applied; compile pending

- Turn: `M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE`.
- Source snapshot: `62dce7e77e745b450cc7c0ad723a6628b8a359e7`; verified 5,883 file SHA-256 entries.
- Authorized scope: `tests/SurfaceCellsPhase10Tests.cpp`, streamed `ASSERT_EQ` failure message only.
- Diff SHA-256: `d8043092ac4aa2c5a0e3ffccb42165a728970e54abe4801af5c018a055c12146`.
- Full patch SHA-256: `3ef44e11755d30a8b413dcabbac7947d90fc6d22d243e564aebbeac39f380d62`.
- Patch: `Directional__M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE__base-62dce7e77e74__work-preservation.patch` (downloadable in originating chat).
- Static verification: `git apply --check` PASS; `git diff --check` PASS. No compilation, test or benchmark execution.
- Initial `container_path` transport failed; exact source-file reference staged to Google Drive as `1fhK44VCv8mImClm0QeH79CzIndmTfwT_`.
- Durable `drive_apply` [run 40215866109](https://github.com/akashskypatel/Directional/actions/runs/40215866109) SUCCESS: applied commit `c9d7c80f6d41abdbc2ecd02de7006c7847988df8`, patch SHA matched, `runtimeExecution=false`.
- Compile/package **NOT STARTED**; no 8-target GMP evidence yet. Do not mark CB37 complete.

Exact authorized hunk:
```diff
       mesh, crossField, targetSize, options);
   ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
             network.phaseFront.disposition())
-      << directional::geometry::surface_phase_front_failure_reason_name(
-             network.phaseFront.rejection_reason());
+      << curved_disk_factory_rejection_detail(network.phaseFront)
+      << " site="
+      << (network.phaseFront.rejection()
+              ? network.phaseFront.rejection()->publishedProductSourceAuthoritySite
+              : std::string{});
```

Continuation: compile exactly applied commit `c9d7c80f6d41abdbc2ecd02de7006c7847988df8` with eight GMP/GMPXX targets and `runtimeExecution=false`; verify package, then close CB37 and route to independent CB37-REV. No runtime tests or benchmarks in CB37.
