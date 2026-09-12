# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-CB7` COMPLETE / BUILD GREEN / RUNTIME-FREE / CANDIDATE ONLY / CP3 OPEN
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP3-TB5-EXEC` artifact-only Test + Benchmark execution

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Corrected R4 artifact `10289601000` remains accepted M4-CP3 runtime authority. Accepted selector403 is `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`, **403/403**.
- Candidate selector408 remains byte-frozen at `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`, 408 LF identities, first403 byte-identical to accepted selector403, owner partition **30 / 262 / 75 / 41**. It is **not promoted**.
- TB4 Review classified the prior row408 RED as `M4-CP3-TB4-REV-CAND-01` = **TEST-AUTHORITY / FIXTURE-PRECONDITION COMPOSITION + REACHABILITY DRIFT / NON-STABLE**. The prior fixture supplied 18 user Hard edges but default classification added 48 disjoint automatic Hard edges, so production consumed 66 rails and failed before the intended A3→A4 seam. Stable accounting remains **47 events / 14 categories / 33 recurrences**, debt **5**.
- CB7 pre-mutation guard proves the committed torus has maximum non-user dihedral `60.852573735971816°`; row408-local `179/180` CAD+organic bands therefore yield **18 user Hard / 0 automatic Hard / exactly 18 effective HardFeature edges**, one 144-face source region, and the already-proved two-generator disc-complement topology.
- CB7 semantic source is `dbcc2f1fe07b611ce7360cd00e31ae4e6cd157c8`. Only `tests/FieldAlignedCurveNetworkTests.cpp` changed: four row-local threshold assignments plus an exact effective-HardFeature source-edge set assertion inside row408. Product source/header, rows404-407, row408 identity, selectors, ownership and CMake semantics are unchanged.
- Authoritative compile/package run/job `34678708800 / 103513182449` is GREEN. Candidate artifact `10293750596` hashes to `f95decac9b059bcc7c7b341ecda1e95e8a5b0028211eaa7f902144a196c60831`; log artifact `10293990184` hashes to `72447200a886c4e07768f8e81a156f0878f400321cddd054341cf68d758863f9`. Root `SHA256SUMS` is 28/28 PASS; source archive `ca16770d8ceff1da119687284eb7c01b31af9ce237be01753ed4c962305ff18d`; manifest `43e8e4c35712c8b69d4906288390745f2bdb507160cf52c31ad8f7545faa91ed`; GMP/GMPXX linked; `runtimeExecution=false`; source status stayed clean.
- The first temporary compile caller run `34678598168` was a zero-job startup failure caused by the caller permission ceiling only. Reusable workflow permissions were not changed. Run `34678622666` later compiled green but its caller repeated the producer target in target metadata; it is intentionally non-authoritative. Run `34678708800` is the sole eight-unique-target package authority.
- No Directional runtime, test, benchmark, GTest discovery/listing, or `ctest` ran in CB7. Compilation does not promote selector408, close `G4-B002`, close CP3, or change stable accounting.

## Exact next — `M4-CP3-TB5-EXEC`

Authority: `.agents/Directional/Architecture_M4_CP3_TB5_Artifact_Only_Test_Benchmark_Plan.md`.

Consume artifact `10293750596` unchanged. Before runtime, verify artifact/package/source/selector/owner provenance and immutable hashes. Then execute exactly **821 fresh exact-filter processes** in this frozen order:

```text
phase A row408 focused A           1
phase B row408 focused B           1
phase C rows404-407 controls A+B   8
phase D accepted selector403     403
phase E candidate selector408    408
-----------------------------------
total                            821
```

Every identity runs in its packaged owner binary and must select exactly one test. Gate is fail-fast. No TB3/TB4 process may be credited. Immutable postflight is mandatory after success or the first semantic stop. TB-EXEC may not configure, compile, relink, mutate source/fixture/package, diagnose product cause, or plan remediation.

A green EXEC is still not promotion. `M4-CP3-TB5-REV` is mandatory and independently owns package/selector disposition, the TB4 non-stable candidate, `G4-B002`, CP3 and regression accounting.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/TB-EXEC.md
required:
  - turn-based-coding-agent/references/core/turn-boundaries.md
  - turn-based-coding-agent/references/core/evidence.md
conditional_modules:
  - trigger: artifact/workflow operations through GitHub
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB5_Artifact_Only_Test_Benchmark_Plan.md
  - .agents/Directional/Architecture_M4_CP3_CB7_Compile_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB7_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_TB4_Review_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt
  - .agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt
do_not_preload:
  - TB-REVIEW diagnosis
  - M5/M6 implementation
  - any source/build mutation
```
