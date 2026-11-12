# CB130 annulus rim pair census — code and build record

## Situation

- **Turn:** `M6-CP3-CB130-P13-A3-ANNULUS-RIM-PAIR-CENSUS` (64D.9). Code + Build only. No runtime execution.
- **Authority:** [RA-229](Architecture_M6_CP3_DEFN_P13_A3_Annulus_Rim_Pairing_Review_20261112.md) §4 and the [frozen patch](Architecture_M6_CP3_CB130_P13_A3_Annulus_Rim_Pair_Census_Exact.diff), SHA-256 `009166a110f887198d556bdf8abd28c0e388c9ab28542e454376a39817290dc0`.

## Background

- Applied the exact 78-line patch, with `45` insertions and `1` deletion, to `tests/SurfaceCellsPhase10Tests.cpp` only. The application commit is [`d9dde92f938fab7688644fe2e420214bcefa93cb`](https://github.com/akashskypatel/Directional/commit/d9dde92f938fab7688644fe2e420214bcefa93cb); [apply run 43163566540](https://github.com/akashskypatel/Directional/actions/runs/43163566540).
- The test-only receipt measures the two rim edges under each lattice column. It reports `annulus-pair case=CommittedCylinder strips=S paired=P rimSources=E0/E1 planRims=T0/T1` before the existing `annulus-read` receipt. It adds no new assertion and changes no producer code.
- The source snapshot was verified at `f7e13debc3a7fd18599d7b9c5cda84fbbe9520d4` (run `43163095973`; 5,501/5,501 file hashes), and the patch matched its frozen digest and numstat. Patch transport applied successfully with `runtimeExecution=false`. The staged Drive file was removed after commit verification.

## Assessment

- [Compile run 43163829447](https://github.com/akashskypatel/Directional/actions/runs/43163829447) **SUCCESS**. [Immutable compile package 13918449673](https://github.com/akashskypatel/Directional/actions/runs/43163829447/artifacts/13918449673), ZIP SHA-256 `a2e42a855cd0469a137465fb631fa74c98c3d522eec24b9ad1a41a89db15679c`. Exact packaged source `d9dde92f938fab7688644fe2e420214bcefa93cb`. Verified eight targets and 28/28 package file hashes.
- GMP and GMPXX are linked (`libgmp.so`, `libgmpxx.so`), with `exactArithmeticBackend=GMP` and `runtimeExecution=false`. No test, benchmark, generated binary, help, version, or discovery command ran.
- The first compile dispatcher request was rejected by its strict schema because an unsupported `retention_days` field was present. The corrected v2 request succeeded. This was an orchestration error, not a source compilation error.
- **No test success or pair count is claimed.** TB109 remains the last measured candidate: 944/944 scoped MATCH, Cylinder PASS, BunnyRandom and Vase registered RED. CP2 acceptance remains 491/491; stable 66/17/49, debt 1, deferred 81. O36 unwired, CP3/selector497 unpromoted; PR #8 draft/open/unmerged.

## Recommendation — separate next turn

- **Next:** `M6-CP3-TB111-P13-A3-ANNULUS-RIM-PAIR-CENSUS-FULL-GATE-EXEC` (64D.10), artifact-only Test + Benchmark against this exact compiled source/package. Use the frozen TB111 manifest, byte-identical to TB109: SHA-256 `46e5c8a8ffb1a8d6337d782bef44fa852d3b17870e2f06ab037d55a8ea201f61`, 944 rows, membership 1,025.
- RA-229 §5 requires 944/944, all 41 inherited receipts and `annulus-read` unchanged, census unchanged, and `annulus-pair` with `strips=16 rimSources=16/16`. Record `paired` and `planRims` as evidence.
- After a matching TB111, route to CB129 only when `paired=16`; otherwise route to Review-only `M6-CP3-DEFN-P13-A4-ANNULUS-COUNT-TRANSITION` (O40). Mismatch routes to TB111 Review, infrastructure failure to TB111A orchestration. Neither successor began in CB130.
