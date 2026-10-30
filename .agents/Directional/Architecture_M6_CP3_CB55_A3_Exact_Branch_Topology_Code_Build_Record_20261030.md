# CB55 — A3 exact branch topology (O15) (2026-10-30)

- **Turn:** `M6-CP3-CB55-A3-EXACT-BRANCH-TOPOLOGY`; Code + Build, compile-only. It was run locally, because the implementation agent was unavailable and the user directed local builds.
- **Authority:** [RA-180](Architecture_M6_CP3_DEFN_A3_Exact_Branch_Topology_Predicates_20261030.md) §.5 and §.7.
- **Patch:** extracted from the committed RA-180.7 block.
  - SHA-256 `824e64cc76f9ebf6fdba905a8258c68ddc1a5a30b64a3baa36e8489803bf0f70`; `git apply --check` passed.
  - Numstat `119 81` (atlas), `14 0` (FieldAlignedCurveNetworkTests) and `51 0` (FieldTransportAtlasTests).
  - The resulting atlas SHA-256 is `43d156a3273495504fcd73a253e60ac09baeea4102f84b90186f8e6883a49461`. All exact.
- **Source:** commit `0402716703e26cb640f6bc8a423389c31987107f`.
- **Build:** a fresh out-of-tree configure of a clean worktree, with the CI flags at **default arithmetic** (Release, static, GMP, tests and benchmarks ON).
  - Eight targets, 151/151 steps, exit 0, from 23:50:20Z to 23:56:15Z.
  - macOS arm64, Apple clang 21.0.0. `positive_oriented_angle` and `counter_clockwise_sector_angle` are absent from the archived atlas object.
- **Package:** `build/local-evidence/CB55/pkg.zip` (gitignored).
  - ZIP SHA-256 `69104b95a433104e91ca698e61f73dd865eea610a06170283163dc3be6aebb51`; root `SHA256SUMS` `3479136027cbc61fd69fbf33446957cb5a4bc6b188b5e0b6d605a92bbee4bebc` (18 entries, all verified).
  - Source archive `6066039e…`. Binary SHA-256 prefixes: producer `f85aed10…`, authority kernel `1b00f0d7…`.
  - A Haiku subagent staged the package; the Review agent re-verified the ZIP, the checksum list, the exact `command-boundary.txt` and byte equality of all eight outputs with the build.
- **No native tests were executed in CB55.**
- **Next:** `M6-CP3-TB54-O15-FULL-GATE-EXEC`: gate `53683907…` (857), ledger v3 (83), expected membership 940, with row 283 the only pre-classified red (RA-180.6).
