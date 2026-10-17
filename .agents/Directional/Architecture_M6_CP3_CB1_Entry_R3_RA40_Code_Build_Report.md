## CURRENT authoritative RA-40 Code + Build result — 2026-10-10 06:02Z

**COMPLETE / compile GREEN / runtime unexecuted** for `M6-CP3-CB1-ENTRY-R3`, pending durable docs push and final root STATUS beacon. RA-40 A/B/C Review completed; exact source `d82e34427adc6fe09ad216a4363fea23dd0ae0b8` includes five-file source-attested A3 factory/11-caller migration patch `7de636c88fe6ad8c4f09c1956161f56f88995785` and one-file fixed-size Eigen test-helper correction. Initial eight-target compile `38028700056` failed on dynamic `.cross()` Eigen static assertion; corrected compile **run `38029281891` succeeds** (`compile / compile` job `114146685417`), immutable result artifact **`11661566000`** outer ZIP SHA-256 **`18591009acf98b4c6ea996bc4bb1445959bbd49b1f96cc78327caacfb302ac95`**, internal **28/28 SHA256SUMS**, metadata `source-commit.txt` exact match, `preflight-exit-code=0`, `build-exit-code=0`, eight approved targets, `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, actual generated linker command contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`. No tests, benchmarks, Directional binaries, or TB harness executed.

**Authorized successor:** `M6-CP3-TB1-ENTRY-R3-EXEC` — distinct artifact-only frozen 497-process TB; four supplementary RA-40(C) tests must be separately scheduled and counted with diagnostic-only weight; do not merge into 497. Organic produced witnesses, historical R2 first failures, and 47 accepted→RED restorations remain entirely unverified until TB; no promotion or test pass claim. Any prior local entries below describing the second compile as pending are historical and superseded by this record.

---

# M6-CP3-CB1-ENTRY-R3 — RA-40 Source-Bound A3 Factory Compile Checkpoint

 **Update (2026-10-10 05:58Z):** Initial GMP run `38028700056` failed only on Eigen compile-time vector-size assertion in test `FlowRepStrandsPhase15Tests.cpp:79` (`preflight_exit=0`, `build_exit=1`, `runtimeExecution=false`); one-file typed `Eigen::RowVector3d` correction applied successfully by workflow `38029206658` and semantic commit `d82e34427adc6fe09ad216a4363fea23dd0ae0b8`. Repair patch SHA256 `1cdb28c1c4ac8a1752f8201de3602053a4c10b1a2abcd8a9a2f01f37adb4cb26`; staging retired. Second immutable eight-target compile request event `b94820aaf64ee4c68f670e7c69b49b0f5f50b81a` pinned to `d82e344...`, mailbox `m6-cp3-r3-ra40-eigen-repair-gmp-compile-r2`, terminal result pending. No runtime work.


Turn: `M6-CP3-CB1-ENTRY-R3` (Code + Build only; no runtime). Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains draft/unmerged.

## Source patch and verified application

- Initial immutable source: `b61acce407d2e0887c8712ba9838df3cac62b53a`, snapshot workflow `38022333747` and source artifact `11658753507`, verified 5,801/5,801 source hashes in preceding bounded attempt.
- Exact RA-40 patch: `Directional__M6-CP3-CB1-ENTRY-R3__base-b61acce407d2e__work-preservation.patch`, 65,361 bytes, full SHA-256 `6c88a8fbf674656383bd67a4620bb0791551ea51274e57902aefe3e333ed34eb`; diff body SHA-256 `95c94aa339c684343672515a22c9c858e7f85d60054b78b8d00cb12c1d224fdb`; 5 intended code/test paths.
- Exact Drive File ID `170PP45osR7xZHmBiAFn5q2wneQHP16n0` was accepted in `My Drive/Directional-CI` (65,361 bytes). Durable dispatcher `drive_apply` event `0fc5185703147d653a797637823a688e2604caf8`, workflow `38028610928`, apply job `114144704947` **success**. Result artifact `11660584451` verified SHA-256 `ce55e2a8326f4597ee1755e86c1edd325de579a6e95bf1a1b1a05443f5403391`.
- Applied exact code/test source commit: `7de636c88fe6ad8c4f09c1956161f56f88995785`; verified remote commit compares to base as only five intended source/test changed paths plus independent previous control/doc/status/mailbox changes. `runtimeExecution=false` on apply. Drive owner cleanup permanently deleted the consumed file (`success=true`).

## Implementation scope

1. Bind `SurfacePhaseFrontProduct::make` to exact `sourceFaces`, checked vertex count, and mandatory source-bound `FieldTransportAtlas`; independently authenticate every supplied A3 carrier χ and nonrail φ using source `transition_value` with reverse reciprocity.
2. Pass existing production source/A3 authority through A4 `publish_phase_front_result` without default permissive overload or substituted per-face gauge.
3. Migrate source-exact public callers in three test files; add real source-bound atlas fixtures, balanced transport-tamper and missing/mismatched atlas rejections, and positive source-attested rebuilding. Preserve RA-39 one-terminal carrier semantics.
4. Static diff `5 files, 341 insertions, 79 deletions`, `git diff --check` and clean-baseline `git apply --cached --check` passed. No source GoogleTest identity or selector change; frozen `497=30+12+449+6` unchanged; four supplemental identities remain outside and must be separately counted.

## GMP compile and runtime boundary

- Compile request event: `8ff01b62485d79eaccb610e3f515e54dffa52672`, exact source `7de636c88fe6ad8c4f09c1956161f56f88995785`, mailbox `m6-cp3-r3-ra40-atlas-a3-gmp-compile-r1`; eight approved targets, mandatory GMP/GMPXX; no binary runtime permitted.
- **COMPILE EVIDENCE: first compile RED run 38028700056; corrected eight-target GMP/GMPXX run 38029281891 GREEN; source d82e34427adc6fe09ad216a4363fea23dd0ae0b8; result artifact 11661566000 SHA256 18591009acf98b4c6ea996bc4bb1445959bbd49b1f96cc78327caacfb302ac95; 28/28 SHA256SUMS, both exits zero, no runtime.**

## Non-claims and next turn

No runtime source product, D1/D2/D3/D5/A6/A7 positive, odd-τ witness, recovered historical R2 RED or accepted-to-RED restoration is claimed. Frozen 497-case TB and four separate supplemental diagnostic executions require their own artifact-only authorized successor(s), not this Code + Build turn. Stable ledger remains 64/17/47, debt 1, without new runtime findings. RA-40 decisions A/B/C are resolved in `Architecture_M6_CP3_R3_ABC_Review_Decision.md`.
