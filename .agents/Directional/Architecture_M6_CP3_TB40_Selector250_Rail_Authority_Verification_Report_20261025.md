# TB40 — immutable selector-250 rail-authority verification (2026-10-25)

**Turn:** `M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY`.
**Disposition:** **FOCUSED GATE PASS, candidate only; independent TB40 Review required.** All 13/13 cases passed. Frozen RED row selector250 is an **unexpected PASS** under the preregistered manifest; 12/12 other GUARD rows passed. Do not count this as CP3/497 acceptance.

## Immutable authority

- Exact CB38 source `41f39ba920eace2dad7b36d2b26c8073ce740239`, compile run `40232132945`, artifact `12613073521`; original ZIP SHA-256 `ca7358b7de3ff7ce5bc234f69c2b06036a7a5681f96d9a2d6c9e7cd298797ab3`; root `SHA256SUMS` SHA-256 `250e5da9175b89f9ee3857afe094127bc4c96f0006f39526b8847223a3275234`, source archive SHA-256 `b2c8d4c8cbdf98535873fe76e3478dd0cf19b375db8ec295c0c431dcd1aec8e8`.
- Frozen [13-case manifest](Architecture_M6_CP3_TB40_Selector250_Rail_Authority_Verification_Case_Manifest.tsv) SHA-256 `5dd7d9499918b04a277b907835993beb7829e6d9f52c4cc345faf5e3cd2158e4`; existing targeted artifact harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`.
- Executor commit `d8d9b8c1148f73812ae6eff6aca71d9ee676ab07`; dispatcher trigger `1dc2ff9ebb69905f30946d02a3e16f23f6f85dbf`; [remote run 40240164913](https://github.com/akashskypatel/Directional/actions/runs/40240164913), result artifact `12616556389`, outer ZIP SHA-256 `84d63107293cd7e3f47969849507e2a96c3435a97613345f4723906dd7e7a320`.
- Harness reports 13 selected/executed; 13 PASS / 0 RED; 0 missing/skipped/duplicates/control failures; `unexpected_pass=1` on selector250, `postflight=true`, exit zero. Original package source/mode/compiled boundary validated, staged binaries and fixtures immutable before/after execution; no project rebuild/configure/relink/benchmark, no semantic code, fixture, selector or manifest edit.
- Archive's `SHA256SUMS` and all 13 raw row logs independently verified after download. Raw selector250 log records exactly one test and `[ OK ]` in 44 ms.

## Interpretation and follow-up

Selector250's expected RED→PASS is a measured positive result after supplying authentic combined-fixture rail authority through the production functions. This discharges **the focused observed failure** as a candidate, not a full matrix or direct-production proof. TB40 Review must independently verify raw logs, source, digest joins, and non-vacuity before promoting this result or closing the RA-156 owner; the frozen selector497 remains unaccepted. Historical TB39 `hard-rail-contact-missing` is not a new stable regression; do not modify the 66/17/49 stable ledger or debt 1. All carried O1/O2/O3 and re-home obligations remain.

**Next authorized stage:** separate independent TB40-REV turn; full canonical ID has not been explicitly frozen in repository authority. Do not start successor work here.
