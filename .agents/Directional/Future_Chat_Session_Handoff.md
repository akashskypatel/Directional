# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-CB4-R2` HALTED / STOP-GUARD / PRE-MUTATION / EXACT NEXT `M4-CP3-CB4-R2-REV`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** runtime-free Review, `M4-CP3-CB4-R2-REV`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Package119 / selector394 **394/394** remains accepted M4 runtime authority.
- Package120 / selector403 remains mechanically green but **unpromoted** because `M4-CP3-TB2-REV-CAND-01` found row400 non-vacuous coverage invalid.
- Selector403 remains frozen at SHA-256 `e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802`; first394 remains accepted selector394 at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.
- CP3 is open. A3→A4 cutover remains unauthorized.

## CB4-R2 STOP-GUARD

Authority: `.agents/Directional/Architecture_M4_CP3_CB4_R2_Derivation_Guard_Record.md`.

The frozen pre-mutation guard cannot prove the required row400 witness:

1. **proved:** a real source row can be noncanonical — prescribed-sphere zero-based row 3 is `[1,5,2]`, while `SourceFaceTopologyKey::make` canonicalizes it to `[1,2,5]`;
2. **not proved:** no accepted existing production fixture/path supplies an independently known face-interior contact with three all-distinct exact components in raw source-row order;
3. **proved:** A2a/A2b face-point coordinates are canonical by construction — boundary coordinates are indexed by `SourceFaceTopologyKey::vertices()`, contact intersection stays in that coordinate system, and A2b copies the canonical terminal-contact tuple into `ExactSourceFacePoint`;
4. **proved:** existing production snapshots can expose the published network/plan without a product-only testing API.

The deeper issue is authority shape: the accepted A2a/A2b path does not consume a raw-row barycentric tuple and then remap it. Raw source-row component positions have already disappeared before exact contact coordinates are formed. Fabricating that seam in production, deriving expected values from observed output, or cloning contact-intersection math into the test would violate the frozen recovery plan.

Accordingly `M4-CP3-CB4-R2` made **no test/product/selector/build mutation**, started **no compile**, and executed **no Directional runtime**.

## Exact next — `M4-CP3-CB4-R2-REV`

Runtime-free review must independently re-open the guard evidence and choose exactly one bounded authority disposition:

- prove an already-existing, non-circular production witness that genuinely owns raw-row-attached all-distinct coordinates and can support row400 without product mutation; or
- amend/replace the row400 test-authority contract because the current A2a/A2b exact-point seam is canonical by construction rather than a raw-row→canonical remap.

No Code + Build retry, TB2-R1-EXEC, selector promotion, or A3→A4 work is authorized before that review freezes a successor.

## Carried obligations

- `M4-CP3-TB2-REV-CAND-01` remains OPEN / NON-STABLE / TEST-AUTHORITY; CB4-R2 did not repair or runtime-close it.
- `M4-CP3-TB1-R1-REV-OBS-01` remains open: multiplicity weighting has only `[1,1,1]` runtime evidence and stays outside this row400 control experiment.
- `M4-CP3-CB4-REV-OBS-02` remains the low-cost future row399 path/`sourceFaces` consistency tamper obligation and is not part of the stopped row400 recovery.

## Snapshot provenance

- frozen semantic source before control marker: `190cb56e680dc02a91c743ccad61ca2ef10a6032`
- snapshot control head: `fc5e59e3f52e30087b1a755e67701318d4a5b128`
- source-snapshot run/artifact: `34656852303 / 10286151896`
- source-snapshot provider SHA-256: `44ee51a6e08500b75d02dd6db31fefd9ed63729cc04084bb86f2be85ca4206ed`
- inner source archive SHA-256: `35e341692d8ae9e5478e1c9bba65915ede1ebe1befbf723f2da22c662950ee8f`
- `runtimeExecution=false`

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/REVIEW.md
conditional_modules:
  - trigger: row400 test-authority contract/witness review
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector source/evidence inspection and review closeout
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_CB4_R2_Derivation_Guard_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB4_R2_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_TB2_Review_Record.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/REVIEW_TURN_POLICY.md
do_not_preload:
  - A3-to-A4 cutover implementation
  - M4-CP3-TB1-R1-REV-OBS-01 fixture work
  - M4-CP3-CB4-REV-OBS-02 row399 work
  - new runtime evidence or compile before the review disposition
```
