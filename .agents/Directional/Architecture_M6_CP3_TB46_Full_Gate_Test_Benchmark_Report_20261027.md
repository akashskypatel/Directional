# M6-CP3-TB46 full-gate artifact-only test/benchmark record — 2026-10-27

**Turn:** `M6-CP3-TB46-RP01-FULL-GATE`. **Disposition:** complete *execution*, **invalid acceptance/orchestration STOP S5** (`required controls failed`); no semantic acceptance or package promotion. Do not fabricate a 499/5 result or use the provisional raw 497/7 ledger as a mechanically valid accepted gate.

## Immutable inputs and execution

- Repository/branch: `akashskypatel/Directional` / `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Original CB46 semantic source `c05d52dd7c710d1ca32922f6cfe1f6b61a29db99`; compiled package artifact `12708707491`; ZIP SHA-256 `03f534ac5db362746be238bdc1929931586e071fbbdf00fa68ed5891c9036035`; root `SHA256SUMS` digest `a05f1d826431986294a7eecc969b1be7db8703423498f030a50799f490d8d395`.
- Executor SHA `a84d719f7b371a5ae0ad2f1a56ac418b69c549b5`; dispatcher event SHA `ccef48b464283aac8d724496ad21d27231be74b5`; unchanged harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`; 504-row manifest SHA-256 `717f4f0fb9b520ec9c0281bfa71f11b2edae98b16a1f18ffc17366fb076bb087`.
- [Actions run 40448739180](https://github.com/akashskypatel/Directional/actions/runs/40448739180), runtime job `122006250303` (completed failure); mailbox `workflow-mailbox:.workflow-mailbox/m6-cp3-tb46-full-gate/latest.json` matches event and semantic source. Result artifact `12711165610`, provider ZIP SHA-256 `158b8d25cd3f49089cf1c14b20e11718d1f93af87a270fadf27162bdc91f9ed1`; harness log artifact `12711016096`, digest `42935dbff11599abe80741e9d643b9d5c860ff27940fd825c8893abe06709dad`; reusable log `12711205512`, digest `8cb7377dfebdd465d22b88cb3d497f6aa5a1a92a77aa9dc7b39b7b7ec0af1c04`.
- Full result archive: 1,014/1,014 `SHA256SUMS` entries verified (504 raw logs, 504 resource records, 4 dependency receipts, ledger and execution boundary); 504 independent raw log digests matched the ledger and exact manifest row order/identity/binary/test; one `[ RUN ]` and one terminal GTest result per log, zero missing/skipped/duplicate. All 504 resource files exist. Package immutable postflight **true**. Harness `compile=false`, `relink=false`, `configure=false`, `benchmark=false`; no local execution/rebuild/repair.

## Observed 504-case table (not the predicted 499/5)

| Kind | PASS | RED | Invalid/skipped |
|---|---:|---:|---:|
| GUARD | 497 | 0 | 0 |
| expected RED | 0 | 5 | 0 |
| POSITIVE | 0 | 2 | 0 |
| **Total** | **497** | **7** | **0** |

Five pre-registered REDs remained at their pinned predicates:

1. `focused30:12` row12 — `SurfaceCellTransitionQuotientTests.cpp:5563`, `A5:OccurrenceHardRailTransportMismatch`.
2. `selector:201` row243 — `SurfaceCellREPackageTests.cpp:715`, `endpointKind=I;certificateCount=10;routeSteps=1;junctions=0;carrier=(1,4)` (D1). The former `terminalVertex` oracle is not met.
3. `selector:442` row484 — `FieldTransportAtlasTests.cpp:2856`, `SingularityMismatch;sourceEdge=(2,3)`.
4. `cp3entry:1` row492 — `SurfaceCellTransitionQuotientTests.cpp:2916`, no odd face-gauge pairs among 5 candidates, selected `c0 fromGauge=0 toGauge=0` (D3).
5. `cp3entry:2` row493 — `SurfaceCellTransitionQuotientTests.cpp:3154`, 10 separate single-step A4 rail certificates, none joining `(1,4)->(4,7)` or with a junction (D2).

The two formerly RED, now POSITIVE test identities **did not pass**:

- `selector:174` row216 — `unknown file: Failure`, uncaught `compute_edge_quantities(): DCEL consistency check failed` exception. Static CB46 H1 `EXPECT_THROW` is at `SurfaceCellREPackageTests.cpp:449`; the unhandled exception is not source-attributed, so do **not** assert that it came after the frozen `:459` boundary. Earlier `set_mesh` calls exist at `:293` and `:439`. Whether the corrected H1 expectations were reached is unresolved.
- `cp3entry:4` row495 — the re-homed A4 `open-rail-chain` checks at `:3987–4002` are not the reported failure; instead `SurfaceCellTransitionQuotientTests.cpp:4063` fails later at `ordinaryCarrier.has_value()` because the D5 test did not find a live reciprocal OrdinaryFront carrier with the expected independent transition. This later first failure is within RA-164.5's latent-failure clause, but must not be represented as a PASS.

## Critical control-plane/contract discrepancy and stop disposition

The unchanged harness counts **every non-RED failure** as `control_bad`; both POSITIVE failures set `control_bad=2`, raising `ValueError: required controls failed`, exit **90**. Its code requires `state['control_bad'] == 0` unconditionally. RA-164.5 separately permits later-predicate failures of `selector:174` or `cp3entry:4` while preserving their failures as evidence. The policy and executor therefore disagree on permitted control outcomes, and selector174's unlocalized exception cannot safely be granted the later-predicate exception merely by relabeling it.

**Classification: S5 — harness/acceptance-contract failure; current attempted gate not promotion-worthy.** `M6-CP3-TB46A-ORCH` is the pattern-authorized orchestration-correction **Code + Build** successor under RA-164.3 P4/S5; it is not product remediation and must not invent a new semantic assertion. It should freeze input package/manifest and adapt the reusable harness/caller policy to distinguish (a) source-proven later-predicate POSITIVE failure, (b) unlocalized/early unexpected POSITIVE failure, (c) GUARD regression, and (d) the five RED first-site pins. It must **fail closed** on (b)/(c), preserve raw test results and independent evidence, and correct any source test preconditions only with separately authorized Code + Build scope if independently justified. Re-execute TB46 as a separate artifact-only turn on the immutable package after authorized correction. Do **not** retry blindly, weaken assertions, promote the provisional ledger, or route to DEFN-E until an authoritative TB outcome satisfies RA-164.5.

The two POSITIVE failures are non-stable candidate findings; stable regression accounting remains **66 events / 17 categories / 49 recurrences**, debt **1**. Last accepted semantic runtime remains CP2 **491/491**; selector497 and CP3 are unpromoted. The completed raw result is retained as invalid-attempt provenance, not a new stable event.

## Closeout and cleanup

The temporary one-time source snapshot and run-inventory monitoring triggers/caller were deleted before this result; no test source or semantic code was changed during TB46. Dispatcher request slot and workflow-mailbox history remain durable. The immediate next action is S5 orchestration-correction scope definition and Code + Build under the exact prior authority, followed by a fresh TB46. No direct tests may be run in a compile-only correction turn.
