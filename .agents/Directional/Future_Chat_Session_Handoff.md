# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-TB2-PLAN` COMPLETE / AUTHORITATIVE TEST-ONLY RECOVERY FROZEN / EXACT NEXT `M4-CP3-CB4-R2`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Code + Build, `M4-CP3-CB4-R2`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Package119 / selector394 **394/394** remains accepted M4 runtime authority.
- Package120 / selector403 remains mechanically green but **unpromoted** because `M4-CP3-TB2-REV-CAND-01` found row400 non-vacuous coverage invalid.
- Package120 semantic source is `3f909a5a2cfd305d423faf7a260bc465c7b06892`; artifact `10280703200`; ZIP SHA-256 `3f0ae49f1549ff2f5c4f821ee1db5bc0314405f8f726c04cecaaf5fa3cdf80a4`.
- Selector403 remains frozen at SHA-256 `e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802`; first394 is accepted selector394 at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`.
- TB2-EXEC mechanics remain valid evidence: 815/815 PASS, selector394 394/394, selector403 403/403, immutable postflight. They do not promote package120 because row400's intended contract is unproved.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.
- CP3 is open. A3→A4 cutover remains unauthorized.

## Frozen successor — `M4-CP3-CB4-R2`

Authority: `.agents/Directional/Architecture_M4_CP3_CB4_R2_Code_Build_Plan.md`.

The turn is a one-variable test-authority recovery. Before mutation it must prove an existing production path can supply the required witness. Then it may change only row400/test-local support in `tests/FieldAlignedCurveNetworkTests.cpp`:

1. use an actual source-face row whose ordered vertices differ from its canonical `SourceFaceTopologyKey`;
2. make that row participate in the existing production A2a/A2b face-point path, not a detached assertion;
3. use three distinct exact barycentric components;
4. independently derive canonical component order by matching vertex identity;
5. assert raw tuple != canonical expected tuple and published exact point == canonical expected tuple, so omitted/swapped remapping fails;
6. emit one deterministic live row400 receipt only after semantic assertions pass.

No production/public-API/CMake/selector/A4 change is authorized. If the existing product path cannot provide the witness without such changes, **STOP-GUARD before mutation and return to review**.

Compile is GitHub Actions/GMP only and runtime-free. The changed producer owner preflights first, then the complete four-owner/API/benchmark package surface compiles. Selector403 bytes must remain frozen.

## Future validation

After compile/package, exact next runtime is `M4-CP3-TB2-R1-EXEC` on the immutable candidate. Frozen semantic matrix is **799** fresh processes:

```text
row400 focused A      1
row400 focused B      1
selector394         394
selector403         403
-----------------------
total               799
```

Require 799/799 PASS, deterministic row400 receipt, selector394 394/394, selector403 403/403, zero skip/mismatch/timeout, and immutable postflight. `M4-CP3-TB2-R1-REV` alone may promote the package.

## Carried obligation

`M4-CP3-TB1-R1-REV-OBS-01` remains open: multiplicity weighting has only `[1,1,1]` runtime evidence. It is explicitly **out of CB4-R2** to preserve the row400 control experiment. Assign it to the first later independently falsifiable test-authority turn—prefer naturally suitable CP3 cutover test work, otherwise a dedicated bounded test-only turn before CP3 closure.

## Planning provenance

- reviewed evidence: `.agents/Directional/Architecture_M4_CP3_TB2_Review_Record.md`
- normative definition: `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §17.12
- authoritative successor plan: `.agents/Directional/Architecture_M4_CP3_CB4_R2_Code_Build_Plan.md`
- accepted runtime source/package: package119 / selector394 **394/394**
- blocked candidate source: `3f909a5a2cfd305d423faf7a260bc465c7b06892`
- TB2 review candidate: `M4-CP3-TB2-REV-CAND-01`
- planning source snapshot event: `0eb2c573e0a0843141420fb46c6c71892cafd209`
- planning source snapshot run/artifact: `34653889150 / 10284248466`
- snapshot ZIP provider SHA-256: `2d11415493e8706c0eb553525d6da57c01aa67773f6b5dd33e333a5e69d5d5db`
- snapshot archive SHA-256: `1b03307662da9f69923b881bc7b0e9119715d50534f07b489ee4f2469e63d1ac`, 5253/5253 hashes verified, `runtimeExecution=false`

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
conditional_modules:
  - trigger: row400 unit/regression test repair
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub Actions compile/package orchestration
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_CB4_R2_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_TB2_Review_Record.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
do_not_preload:
  - A3-to-A4 cutover implementation
  - M4-CP3-TB1-R1-REV-OBS-01 fixture work
  - unrelated historical M3 records
  - new runtime evidence before CB4-R2 compiles a candidate
```
