# TB46 RP-01 full-gate rerun — immutable 504-case evidence (2026-10-27)

**Turn:** `M6-CP3-TB46-RP01-FULL-GATE` (artifact-only Test + Benchmark). **Verdict:** **valid expected RED gate**, harness exit **0** with **498 PASS / 6 registered RED**, exactly RA-165.4's predicted outcome. This is **not** a green product gate, no CP3 promotion, and does not replace CP2's accepted 491/491.

## Immutable inputs and authority

- Repo: `akashskypatel/Directional`; branch `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8.
- Semantic source SHA: `8f0d4329695de1c7542ea240e30e55761acc3a38`; immutable CB46B package artifact **12716018703**; package ZIP SHA-256 `0053f63fe9f9449e6f5024cbc2df36ca029c22cd58d75e2710fefb906af1a89f`.
- Harness SHA-256 `37b01215fcc739b86e2f17f97cef3cb1d313124075eab6d5da205cd370b0af72` (`.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`). Frozen 504-row [case manifest](Architecture_M6_CP3_TB46_Full_Gate_Case_Manifest.tsv), SHA-256 `717f4f0fb9b520ec9c0281bfa71f11b2edae98b16a1f18ffc17366fb076bb087`.
- Executor commit `5de513d0d6e132ec91fcdce6a01a4a5ce4d60597`; dispatcher commit `65d3f135314d0474eab3087d19518a8ef87160a2`; [run 40468913755](https://github.com/akashskypatel/Directional/actions/runs/40468913755), runtime job 122071096075. Same immutable gate as first dispatch; no duplicate or rerun.
- GitHub Actions result ZIP **12719412600**, SHA-256 `2a33427b5bc1af6629259469514a30158e07478ca21b3c68df3be7d3e1f5fd37`; harness log ZIP **12719912170**, SHA-256 `b1582627244ce22887fd1b2c64999a0f5fb89d5273121f896c17697afd51ed1c`; wrapper log ZIP **12719462521**, SHA-256 `0ce1c18751121f4990f508a395641693d71f06fe9032afe37582c48829ab10e6`.
- Authoritative mailbox `workflow-mailbox:.workflow-mailbox/m6-cp3-tb46-rp01-full-gate-r2/latest.json`, run ID and source SHA verified. Old TB46 run `40448739180` remains **invalid-attempt (S5)** provenance and is not averaged or promoted.

## Independently checked execution evidence

- Result ZIP digest matches mailbox/provider; **1,014/1,014** result members match internal `SHA256SUMS`, with no duplicate ZIP members or checksum keys.
- **504/504** manifest/ledger identity rows match exactly (`row`, `kind`, `identity`, `test`, `binary`). Each row has one SHA-256-verified independent raw GTest log with exactly one matching `[ RUN ]` identity and one resource measurement receipt. No missing, skipped, or duplicate rows.
- Final state: `passed=498; red=6; missing=0; skipped=0; duplicate=0; control_bad=0; unexpected_pass=0; later_positive_red=1; red_site_bad=0; postflight=true`; harness `exit=0`.
- All **497 GUARD** identities PASS. `selector:174` POSITIVE PASS after CB46B source-valid fixture correction. `cp3entry:4` POSITIVE is RED at its registered **later** D5 site, not treated as an unexpected acceptance failure.
- `execution-boundary.json` confirms `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, exact semantic source and package artifact, plus postflight; this was a test execution, **not a benchmark comparison**. No source, test, selector, manifest, or harness modification in this TB turn.

## Six registered failures — raw first-site verification

| Identity / row | Registered raw first failure | Registered witness / classification |
|---|---|---|
| `focused30:12` / 12 | `SurfaceCellTransitionQuotientTests.cpp:5563` | `A5:OccurrenceHardRailTransportMismatch` (G cluster) |
| `selector:201` / 243 | `SurfaceCellREPackageTests.cpp:715` | `endpoint.terminalVertex.has_value()` (E cluster) |
| `selector:442` / 484 | `FieldTransportAtlasTests.cpp:2856` | `code=SingularityMismatch;sourceEdge=(2,3)` (G cluster) |
| `cp3entry:1` / 492 | `SurfaceCellTransitionQuotientTests.cpp:2916` | `gaugeDelta == 1 || gaugeDelta == 3` (G cluster) |
| `cp3entry:2` / 493 | `SurfaceCellTransitionQuotientTests.cpp:3154` | `D2/RA-38 requires an ACTUAL A4-produced paired two-carrier HardRail` (E cluster) |
| `cp3entry:4` / 495 | `SurfaceCellTransitionQuotientTests.cpp:4063` | `D5 requires a real reciprocal A5 OrdinaryFront` (E cluster; permitted later POSITIVE RED) |

All six source `file:line` first failure sites and registered witness strings independently matched their per-process raw logs. `reason-not-observed` in the ledger for assertion-based rows is **not** silently reclassified into a production typed reason; their actual assertion text is the witness. No additional RED identity or unexpected pass was present.

## Regression classification and disposition

This rerun establishes **no new stable regression**. The five pinned REDs were previously registered, `cp3entry:4` is the anticipated non-gating later failure, and `selector:174` fixture failure is repaired. The stable ledger remains **66 events / 17 categories / 49 recurrences**, debt **1**. CP2 **491/491** remains the last accepted semantic runtime; selector497 and CP3 remain unpromoted; RP-01 open, RP-02 unreached.

Per RA-165.4 the exact next turn is **`M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER`** (Review). It must independently decide E cluster `selector:201`, `cp3entry:2`, and `cp3entry:4` D5, freezing the TB47 `asserted_site` source-line/witness manifest pins. G cluster `selector:442`, `focused30:12`, `cp3entry:1` follows in the later Review. Continue to respect RA-164.3 P1–P6 and RA-165.2 F1/F2. Until CB47A, all edits above hard-coded harness pins must remain line-neutral. Do **not** begin Review within this completed TB turn.
