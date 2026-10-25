# CB37 — selector 250 factory-site message (Code + Build, 2026-10-25)

- Turn: `M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE`. Authority RA-155.5; **test-only diagnostic message**, no assertion/selector/product semantics altered.
- Source snapshot `62dce7e77e745b450cc7c0ad723a6628b8a359e7` (5,883 hashes verified); source commit [`c9d7c80f6d41abdbc2ecd02de7006c7847988df8`](https://github.com/akashskypatel/Directional/commit/c9d7c80f6d41abdbc2ecd02de7006c7847988df8).
- One changed source path: `tests/SurfaceCellsPhase10Tests.cpp` at original lines 3666–3669; helper visible at 2630, source authority site member exists; operands and macro of `ASSERT_EQ(Produced, …)` unchanged.
- Preservation patch: `Directional__M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE__base-62dce7e77e74__work-preservation.patch`; SHA256 `3ef44e11755d30a8b413dcabbac7947d90fc6d22d243e564aebbeac39f380d62`; diff body `d8043092ac4aa2c5a0e3ffccb42165a728970e54abe4801af5c018a055c12146`; `git apply --check` and `git diff --check` PASS.
- Drive apply [run 40215866109](https://github.com/akashskypatel/Directional/actions/runs/40215866109) SUCCESS. Owner permanently deleted staged patch after applied commit.
- Compile-only [run 40216902065](https://github.com/akashskypatel/Directional/actions/runs/40216902065); result artifact `12607777892` (SHA256 `fa437659c633de1b5e69dc93b35bcbb65dec84c212a957d005ada58e4dd01b58`), 28/28 packaged checksums, eight approved targets, both GMPXX/GMP on authoritative link, `DIRECTIONAL_ENABLE_GMP=ON`, preflight/build exit 0/0, clean source status, `runtimeExecution=false`. No test/benchmark binaries executed.
- Accounting preserved: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidates only; selector497 frozen, CP3 unpromoted, RP-01 open.
- Next: `M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE-REV` independent static source/package Review, then TB39 manifest only if accepted.

Exact authorized hunk:
```diff
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
