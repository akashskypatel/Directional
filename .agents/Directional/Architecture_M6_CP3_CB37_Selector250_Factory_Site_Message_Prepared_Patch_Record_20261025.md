# CB37 — selector 250 factory-site message: prepared patch (unapplied)

- Turn: `M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE`.
- Source snapshot: `62dce7e77e745b450cc7c0ad723a6628b8a359e7`; verified 5,883 file SHA-256 entries.
- Authorized scope: `tests/SurfaceCellsPhase10Tests.cpp`, streamed `ASSERT_EQ` failure message only.
- Diff SHA-256: `d8043092ac4aa2c5a0e3ffccb42165a728970e54abe4801af5c018a055c12146`.
- Full patch SHA-256: `3ef44e11755d30a8b413dcabbac7947d90fc6d22d243e564aebbeac39f380d62`.
- Patch: `Directional__M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE__base-62dce7e77e74__work-preservation.patch` (downloadable in originating chat).
- Static verification: `git apply --check` PASS; `git diff --check` PASS. No compilation, test or benchmark execution.
- Remote transport: `files__manage_library` container-path upload to `/Google Drive/Directional-CI` failed `container_session_unavailable` on retries; no Drive File ID or source commit.

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

Continuation: reuse and verify exact preserved patch first; stage via authorized raw-file reference, apply via durable dispatcher, compile eight GMP/GMPXX targets without runtime, then write final record and handoff.
