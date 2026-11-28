# CB-184 — Nearest-chord seed switch (Code + Build)

## Situation

The exact frozen CB-184 patch was applied and compiled. No Directional runtime test, benchmark or compiled program was executed.

## Background

- Authority: TB-REV-164 adversarial record Z1–Z6 and stacked CB-184 exact diff SHA-256 `fe9576d84e79d125712b847cd345bfe4308ba26a0c88b9ff48e9291c1a6f758a` (+71/−29), three intended files only.
- Source snapshot: `72676b7ea829c4fd6e7149b2eab1cb098e2e5786`, run `45037068703`, artifact `14759907546`; 5,744/5,744 checksums verified.
- [Patch application run 45037382158](https://github.com/akashskypatel/Directional/actions/runs/45037382158): semantic source `5b5cdf15a670236635d74a15f3791422b182ffe0`; transport patch SHA-256 `cdb0163963c7f29163180b67eef60fad6d7d7923bec938073b40a0915a1fb1f8`, verified exact intended paths.
- Source postimage SHA-256: header `ce13e2a69ef289bda3fea9d5c8bdfe100046d3045c2d3ff1ab2b85e2283008bf`; source `e387a0592f842d68e8f6f6514b4c3ec410775131c1e67ad850a09c22f39d2e`; test `fea486ed3e01e795945b62cb9e04b27a8fb8ebae4814577c62b0c3b377a68e27`.
- Initial dispatcher run `45037662200` failed at request parsing (`targets` supplied as a string); corrected request commit `48270deede063cf44c9e08a853f8d630af2ac9e8` uses the same source and eight targets as an array. The first failure did not reach compilation.
- [GMP/GMPXX compile run 45039218665](https://github.com/akashskypatel/Directional/actions/runs/45039218665), artifact `14760674864`, ZIP SHA-256 `e1717c5959346978cff3fee531fb387c26a296572cdee6698c2017e973b9bec3`; eight required targets compiled and linked, `runtimeExecution=false`.

## Assessment

The frozen change collects all chord candidates before certification, excludes unordered-segment faces from seeding, selects the nearest certified outermost third-edge chord, and adds the staged `SphereStagedNearestChordSeed` receipt to row 979. It changes no selectors, manifests, production activation policy, or acceptance evidence. Latest runtime is TB164 982/982 and three-case census 3/3; accepted CP2 491/491; stable 66/17/49, debt1, deferred81; CP3/497/D0/H4 unpromoted.

## Recommendation

Next turn only: `M6-CP3-TB-EXEC-165-P13-NEAREST-CHORD-SEED-FULL-GATE`, artifact-only 984-row full gate and three-case census, then independent TB-REV-165. Predicted receipt values are not accepted results until verified. No successor work was started in CB-184.
