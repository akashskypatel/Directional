# CB135 — Singularity-port direction census: Code + Build record (2026-11-12)

## Situation

`M6-CP3-CB135-P13-SINGULARITY-PORT-DIRECTION-CENSUS` is complete at the Code + Build boundary. The next, separate turn is `M6-CP3-TB116-P13-SINGULARITY-PORT-DIRECTION-CENSUS-FULL-GATE-EXEC`. No compiled binary, test, or benchmark was executed in CB135.

## Background

RA-235 measured four port classes at BunnyRandom vertex 49 although index −1 requires five. It froze the 28-line addition to `src/authority/FieldTransportAtlas.cpp` to report one `partition direction` line for every fan-face branch. The output reports two endpoint-direction weights, the next vertex, and `inSector`; it does not modify the field, matching, ownership, or validators. Upstream exact diff SHA-256: `fd9ccba26c722edfb75644083ae017c3896fe27bc0f138d90b935332f6c29996`.

## Assessment

- One exact source snapshot at `fe0544389d51676cd5d331b1eb332df5f37b2812`, [run 43270153830](https://github.com/akashskypatel/Directional/actions/runs/43270153830), artifact `13967073315`, ZIP SHA-256 `ecac7644c2f759a7909192b521e29f31976cc5f6ce784036ec705296dc32e8ca`. All 5,529 source-file checksums passed.
- Applied exactly one production path with 28 insertions, 0 removals. The tested exact patch SHA-256 was `302bb481aaa092b1e6d7e809d01a1576686ab7e746cdae72278ce21e9a00f426`; [Drive apply 43270996606](https://github.com/akashskypatel/Directional/actions/runs/43270996606) succeeded. Exact semantic commit: [`40f979d203b08cec236d047e4e9968b5d86d15d3`](https://github.com/akashskypatel/Directional/commit/40f979d203b08cec236d047e4e9968b5d86d15d3). Owner-authorized Google Drive staging deletion succeeded.
- [Compile run 43271247925](https://github.com/akashskypatel/Directional/actions/runs/43271247925) succeeded. Immutable artifact `13968642290`, ZIP SHA-256 `e952583fdcb74d30f25ba55c2613d288626b8c37e078100a7f7ee958f544e41e`. All packaged checksums were verified; all eight required targets compiled and linked. Generated link evidence includes `libgmpxx.so` and `libgmp.so`; `exactArithmeticBackend=GMP`, source-status empty, build exit zero, `runtimeExecution=false`.
- This turn gives **compile evidence only**. It gives no BunnyRandom direction output or TB116 acceptance evidence. Existing TB115 scoped 945/945 PASS and 1,026 membership, CP2 491/491 accepted, stable 66/17/49, debt 1, deferred 81 remain the inherited baseline, not new CB135 results. CP3/selector497 are not promoted; `chainRimSchedules=false`, D10 stays defer.

## Recommendation

In a new turn, run `M6-CP3-TB116-P13-SINGULARITY-PORT-DIRECTION-CENSUS-FULL-GATE-EXEC` using only CB135 artifact `13968642290` and exact source `40f979d203b08cec236d047e4e9968b5d86d15d3`. Reuse the frozen 945-row manifest without rebuilding or modifying source; require the 945/945 gate, unchanged prior receipts and census verdicts, and eight `partition direction singularity=6` fan-face groups with `inSector=1` on exactly (0,2), (2,0), (4,0), and (6,0). Route mismatches to the authorized stop/review path. Do not decide A1 versus lift ownership before runtime evidence and an independent Review.
