# TB32 — immutable periodic-owner gauge verification (2026-10-23)

**Turn:** `M6-CP3-TB32-RP01-PERIODIC-OWNER-FIXTURE-GAUGE-VERIFY`. **Evidence-only result:** 500/500 executed; **481 PASS / 19 inherited RED / 0 INVALID**. The unchanged 497 identity selector measures **478 PASS / 19 RED**, compared with reviewed TB31 candidate **472 PASS / 25 RED**. Six specified RED→PASS; zero PASS→RED. **Candidate, not M6-CP3 acceptance.** Independent TB32-REV must adjudicate this evidence.

## Exact authority and immutable evidence

- Compile-only CB30 package: semantic source `19267540081a4ff3a99826e3b9a766f1dbbded42`, [build run 40023541183](https://github.com/akashskypatel/Directional/actions/runs/40023541183), artifact `12531891913`, ZIP SHA-256 `040b7b12e4b36fa78f2c5eae6465ddaadd2a1fbd8ee9bf18ebda6e35e9a3b97b` (28/28 package checksums; eight GMP/GMPXX targets; no runtime).
- **TB32 immutable run:** [40028643379](https://github.com/akashskypatel/Directional/actions/runs/40028643379), exact dispatcher event SHA `9e4d05a347e3504103ff61f9049f28ca95a69669`, executor `1b12e128e8e2cca3b849703df60f9783a70b7d31`, result artifact **`12534679588`**, outer ZIP SHA-256 **`2c809e72489a69396c3c9e97e2a40ebb15f726de84a19b5610bb092fb9f85ddd`**. The orphan mailbox `m6-cp3-tb32-owner-gauge-verify` confirms run/source/result and `success`.
- Frozen TB32 500-case manifest `597741409f06a80877cb8ae6f5fd2f92785de99a629a7d2c6453921858996437`: original 497 names, owning binaries, IDs, ordinal rows, asserted sites unchanged from TB31, six expected changes `selector:220,221,296,302,304,439`, and three additional controls `cb30control:1..3`.
- Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`. Local artifact inspection independently verified **1,006/1,006 internal SHA256SUMS** and all 500 distinct individual raw log SHA-256 values, test-start/terminal verdict/name/binary/exit joins, manifest identity and expected outcomes.
- `execution-boundary.json`: planned/executed 500/500; PASS 481, RED 19, missing 0, skipped 0, duplicate 0, bad controls 0, unexpected pass 0, `postflight=true`, `exit=0`; configure/compile/relink/benchmark each `false`. No product, test, fixture, manifest, selector, workflow or package modifications were made in TB32.

## Measured changes and independent checks

| Case | TB31 | TB32 |
|---|---|---|
| `selector:220` | RED — `face-gauge-missing` | PASS |
| `selector:221` | RED — `face-gauge-missing` | PASS |
| `selector:296` | RED — `face-gauge-missing` | PASS |
| `selector:302` | RED — `face-gauge-missing` | PASS |
| `selector:304` | RED — `face-gauge-missing` | PASS |
| `selector:439` | RED — `face-gauge-missing` | PASS |
| `cb30control:1` (missing gauge rejection) | absent | PASS |
| `cb30control:2` (one-face gauge tamper) | absent | PASS |
| `cb30control:3` (uniform gauge shift) | absent | PASS |

All other 491 original identities have the same measured verdict as TB31; all 19 remaining REDs preserve their predecessor's **first typed reason**. Exact full test names, owning binaries, first-failure strings and per-log SHA-256 values: [`Architecture_M6_CP3_TB32_Residual_Red_Inventory.tsv`](Architecture_M6_CP3_TB32_Residual_Red_Inventory.tsv). The original raw logs and immutable 500-row ledger remain downloadable from artifact `12534679588`. Nine residual cases have `reason-not-observed`; this is not a causal classification.

### Remaining first-failure groups (19)

- Seven A3 `CycleTransportMismatch`: `selector:189–195`; actual exception is missing usable fixture source A3, not proof of a production cycle-error locus.
- One A3 `SingularityMismatch`: `selector:442`, source edge `(2,3)`.
- One A5 `OccurrenceHardRailTransportMismatch`: `focused30:12`.
- One `open-rail-chain`: `cp3entry:4`.
- Two missing/insufficient produced-witness cases: `cp3entry:1/2`.
- Seven untyped producer/oracle failures: `selector:174,201,204,242,247,250,405`.

**Disposition:** recovered six synthetic periodic-owner fixture cases only. Passing factory control data does **not** prove real odd-transport/unequal-gauge permutation, reciprocal periodic action, produced periodic/A5/A6 topology, or RA-45.4 produced A6 outcome invariance. No new accepted-green regression, stable classification or promoted M6-CP3 gate: **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, CP2 **491/491 accepted**, CP3 **unaccepted**, RP-01 open, RP-02 unreached, Gate C suspended.

**Mandatory successor:** `M6-CP3-TB32-RP01-PERIODIC-OWNER-FIXTURE-GAUGE-VERIFY-REV` — independently reopen exact artifact, audit individual logs and first sites, evaluate six recovered assertions and three controls for non-vacuity, preserve the 19 owner-specific REDs, and decide candidate evidence disposition. No runtime or later-owner implementation in this TB turn.
