# CB-219 — Co-trace deletion switch (2026-11-28 UTC)

## Situation

`M6-CP3-CB-219-P13-COTRACE-DELETION-SWITCH` passed the compile-only gate. Root `STATUS` governs formal closeout. Successor: `M6-CP3-TB-EXEC-194`. The option defaults on; the tracing-loop control remains off where the frozen definition requires it. No test or benchmark ran.

## Background

[Exact manifest](gates/Architecture_M6_CP3_CB219_TB194_CoTrace_Deletion_Switch_Exact_Manifest.md); [switch definition](Architecture_M6_CP3_DEFN_P13_A2a_CoTrace_Deletion_Switch_20261128.md), DESIGN Amendment 35 (Activation). The frozen diff [`Architecture_M6_CP3_CB219_P13_CoTrace_Deletion_Switch_Exact.diff`](Architecture_M6_CP3_CB219_P13_CoTrace_Deletion_Switch_Exact.diff), SHA-256 `636ee790b73e883a0a542812e571d21bff54d83521217235ec8ba8ded24db89d` (26,716 bytes, +137/−76), applies on CB-218 postimages. Exact preimages and postimages verified:

| Path | Preimage SHA-256 (CB-218 postimage) | Postimage SHA-256 |
|---|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `522cfebbf90dcb806cd9f4f9caf9add379777145689cc75ed73c4aff2beae387` | `16992cc75b2182e8ff7e70d815bb75960d93ecfdb78f8deccfdc3dac9684048e` |
| `src/geometry/SurfaceCellTracing.cpp` | `3a67db446800efe1378c04a1471d64926e2aad88214cfa635c28ce1a3de7c09c` | `34719fab75267c2617b9fc2365e74e5e246c4249e34c0686c7c4dc20c4a6411b` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `d02c8507f56f5d7bb55fb909bd74cd614bf60203abcc8a1d6ea91d0d99360bc8` | `c453480681c3bb29633d979754ccac286489d2529fdc1435274be19571c90ef6` |

The option `deleteClaimedCoTraces` defaults to true in every derivation. A build and its validation use the same value. Tracing-loop, diagnostic, and unstaged slide-entry controls use false as defined in SW3. No change outside the exact three paths. Apply/reverse and whitespace checks pass.

## Assessment

| Evidence | Exact authority |
|---|---|
| Source snapshot | Run `46118525439`, job `140897674961`, artifact `15252792139`, source `0c65a41dbc89fb809f69eb3e2648bcb25ef01cff`, ZIP SHA-256 `2e98c4febf611540966ff03f8334a3a77d272d3bffc284702d4a87d5f87a6042`, 5904/5904 file checks. |
| Application | [Run 46118732064](https://github.com/akashskypatel/Directional/actions/runs/46118732064), job `140898375197`, event `69d43d13983ae9dd2aab64dc59f4315e91e5d02d`, result `15253100503` ZIP SHA-256 `82fc2bcfd22932595003d7615eefd9d5b4000dfe413171a3a12ecbed73852651`, log `15252897345` ZIP `0a18ea71a5c17eb7cf4a2ff613410fc114ce1b7e80dbc41d3cfd6f65eff698ea`. Full transport patch SHA-256 `c9e62f8e924738d7d844a3e5614548bfe329f1415d736c7d495e93d0ae429e1b`; apply and push exit 0. Owner-authorized Drive retirement confirmed. |
| Cleanup | Run `46118877621`, receipt `15252807820` ZIP SHA-256 `9cee4e27c642c1c3a877075308e9e252516ed732bb3ebed5fcd9ab84bc25c5b6`; cleanup commit `c76f16ec38e4abc31a5ef19cf4035476ca81eea8`, only the snapshot trigger and cleanup manifest removed, zero PR comments deleted. |
| Source | Commit `26eef1ce54b7b311cbf1cedf597ee0c106be52c2`. Exactly three paths; +137/−76. |
| Compile request | Commit `a0a0a1bde69d5985bf4c74b3356d618f9879f6b3`, `operation=compile`, request and mailbox `m6-cp3-cb219-compile`, prefix `m6-cp3-cb219`. |
| Compile | [Run 46118862242](https://github.com/akashskypatel/Directional/actions/runs/46118862242), attempt 1, job `140898773338`, mailbox result success, executed jobs pass; other operation jobs skip. Compile log artifact `15252694515`, ZIP SHA-256 `ea8738b9c43c152628d9eff47bc9972511b08169947590b913b020c2604e5fc1`. |
| Candidate | Artifact `m6-cp3-cb219-result-46118862242`, ID `15252943713`, 46639902 bytes, expiry `2026-12-05T07:07:22Z`; ZIP SHA-256 `b12b9ede5678f6d8942559e821c134c602b6ba7446b6a338152573f4cb722f35` (matches mailbox); SHA256SUMS 28/28, no uncovered or extra files. Root manifest SHA-256 `78482f7f1e34b05cab1038d18c3e3fd767d9e3125b5a5a695e740bcf413a8e68`. Source archive SHA-256 `bc32deb11ed5487a986fd8ad98de48b064493ce7674d172ea3d208ad2b8353f2`; all three postimages match. |

Candidate checks: two static libraries, six executables (all executable modes preserved), eight targets; build and preflight exit 0; five empty source-status files. GMP and GMPXX link evidence, `exactArithmeticBackend=GMP`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`. No local compile, test, benchmark, runtime, or unapproved source change. Previous acceptance remains TB-REV-193 1013/1013 for the test gate only, CP2 491/491. Stable 67/17/50, debt1/deferred81; O51 open pending independent acceptance, O52 and O50 open, B1 held, B2 carried, V5 not rerun. No production or checkpoint promotion. The candidate retains the exact harness, case manifest and deferred ledger hashes.

Documentation audit: zero errors. The ORIENTATION and ROADMAP size warnings predate CB-219. The three protected-file warnings concern the handoff, ORIENTATION and ROADMAP updates required for closeout and authorized by the user. No policy, design, fixture, selector or workflow file changed in this documentation patch.

## Recommendation

Next `M6-CP3-TB-EXEC-194` on candidate `15252943713` and source `26eef1ce54b7b311cbf1cedf597ee0c106be52c2`. Same 1013-row manifest and TB193 comparator `15250401219`. Follow the exact manifest predictions and falsifiers. Only the 29 enumerated rows may differ. The frozen manifest states 983 remaining rows, but the 1013-row manifest and exact exception list leave 984. Reconcile this discrepancy at successor preflight without expanding the exceptions. This does not change the compile gate or the frozen manifest. Then TB-REV-194. No successor work in CB-219.
