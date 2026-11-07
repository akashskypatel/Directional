# Linux CLI/GUI compilation evidence — bounded Code + Build plan (2026-10-31)

**Next exact turn:** `M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE` (**CB / implementation track**). **Owner authorization:** 2026-10-31 user authorization to proceed with the exact Linux CLI/GUI compilation and verification successor. No semantic product/test/fixture/selector change is authorized by this plan; no CP3 acceptance is inferred.

## Immutable authority and defect to close

- CB62 semantic source `e7c27b0a5f53788569109c85a028e3be44035aaf`, Linux eight-target package `13034987618`, TB61 [Linux 863/863](https://github.com/akashskypatel/Directional/actions/runs/41182654107), membership 945. TB61 independent review confirms the eight-target run, but CB62 configured `DIRECTIONAL_BUILD_CLI=OFF` and `DIRECTIONAL_BUILD_GUI=OFF`. This cannot establish Linux compilation/link of CB60 CLI or CB61 GUI.
- The durable `.github/workflows/agent-compile-reusable.yml` presently hardcodes both options `OFF` at its CMake configure command. The existing standard dispatcher accepts target names, not CMake feature-flag overrides. The missing build targets therefore cannot be validated by merely adding target strings to a dispatcher request.

## Code + Build task and falsifiers

1. Make the **smallest** workflow/build orchestration correction needed to enable Linux CLI **and** GUI targets in the reusable compile path; reuse the existing compile reusable and dispatcher. Preserve existing workflow permissions and GMP/GMPXX requirements. If a workflow YAML is changed, prevalidate the exact YAML through the repository schema-validation path before treating it as executable.
2. Freeze an exact semantic source SHA; package the existing eight targets **plus** Linux `directional` and `directional-ui` in Release. Require actual generated link commands proving GMP/GMPXX where applicable; record `DIRECTIONAL_BUILD_CLI=ON` and `DIRECTIONAL_BUILD_GUI=ON` in packaged `CMakeCache.txt` and the two CLI/GUI entries in `compiled-targets.txt`.
3. Verify both executables/targets were produced from the same source configuration and are present in the immutable artifact. A target not built, disabled flag, missing binary, broken link, wrong source, or fallback arithmetic is **failure**, not success.
4. Execute **no** Directional runtime, unit tests, GUI launch or benchmarks in this Code + Build turn. `runtimeExecution=false` is mandatory. The GUI's on-screen appearance remains a distinct manual check, not evidence claimed by compilation.
5. Preserve the source SHA, compile logs, CMake flags, output/target membership, GMP link receipts and artifact SHA-256; update durable handoff and report before closing. Maintain a strict single source/turn boundary; do not silently modify product behavior or weaken the existing test matrix.

## Authorized follow-up

On successful CB63 packaging, move **in a subsequent turn** to `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC` (artifact-only TB-EXEC) using that immutable package, with the **entire 863-case frozen TB58 gate**, 82 deferred ledger items, membership 945, and explicitly registered Linux CLI verification (including applicable existing 11 CLI checks) plus GUI link/artifact verification. Do not claim GUI display without an on-screen check. A semantic RED routes to independent Review + Plan; orchestration failure routes to orchestration-correction CB under `Turn_Cadence.md`. P13 remains deferred until this evidence is reviewed/accepted; no selector497 promotion and macOS O16 remains separate.
