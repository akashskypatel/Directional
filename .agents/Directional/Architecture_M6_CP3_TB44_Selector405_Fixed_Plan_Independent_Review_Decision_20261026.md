# TB44 independent Review — selector405 focused plan and RA-161 P1 (2026-10-26)

**Turn:** `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY-REV`. **Decision:** TB44 evidence is mechanically valid, but its four-case gate is **3 PASS / 1 RED**, not acceptable as a four-row green gate. Retain `selector:405` as a **focused positive candidate**, not accepted-prefix/selector497 or CP3 promotion. No production or test source was changed in this Review.

## Independent immutable-evidence audit

- Compiled CB44 ZIP `12674401457` SHA-256 `38d88bbda3b6b768f1d243b9b121db6233a740d3b296ccd35a58a9d1e5932bd3`, **28/28** packaged checksums valid, `metadata/source-commit.txt` exactly `c256671115c92f7dd55fea5d680feeac3cbb5190`; source archive and source state verified, `metadata/command-boundary.txt` says `runtimeExecution=false`.
- TB44 run [40387240269](https://github.com/akashskypatel/Directional/actions/runs/40387240269): dispatcher validate/parse success; `test_benchmark / runtime` terminal **failure**; `compile`, `drive_apply`, and `noop` skipped. Result ZIP `12680557878` SHA-256 `f1b300067c4020f0fd156b772785ee7a54b1e5deecdfcda91fb16afe3376b986`, **10/10** member checksums valid; diagnostic log ZIP `12680372908` SHA-256 `4b647e282c7a14e891369bfb721a22fa98730dbc9ead68c9f983b03e6b0f1b98`.
- Frozen manifest SHA-256 `f410b55091cd8cc4fec743e141d4277662165f4feb6aa82de0590d716e5a6a8a` (four distinct identities). All four raw logs independently SHA-256-match `ledger.tsv`, each has exactly one matching `RUN`, one terminal `OK` or `FAILED`, one GTest suite/case, and no skips or duplicate processes: `selector:405` PASS, `phase10:7614` PASS, `phase10:7414` PASS, `phase10:8219` RED. Boundary JSON confirms `planned=4, executed=4, passed=3, red=1, missing=skipped=duplicate=0`, `postflight=true`, `compile=relink=configure=benchmark=false`. `control_bad=1` is genuine guard RED rather than orchestration corruption. No binaries were run in this Review.
- Accepted CP2 baseline **491/491** and frozen selector497 were not altered or re-executed; no new accepted selector was proposed, so accepted-prefix rehash is *not applicable* to a new selector. The published four-row manifest was independently rehashed; do not treat it as a replacement selector.

## Source-grounded P1 adjudication

**P1-a — guard `8219`: invalid negative setup, not evidence of expected A3-path rejection.** Exact compiled source `tests/SurfaceCellsPhase10Tests.cpp:8203–8241` selects a produced non-hard endpoint path step and inserts it in `blocked` hard keys, but calls `build_fixed_plan_rectangular_hard_rail_network(fixture, 1.0, nullptr, &blocked)`. Helper `:7099–7132` supplies A2b terminal contacts/open chains only when `contacts != nullptr`, and closed chains only when explicitly passed. `SurfaceCellTracing.cpp` rejects missing contacts/closed-chain provenance *before* looking for the missing terminal A3 path. Raw `4.log` at `:8236` has the actual first diagnostic `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`, with `a2bProbeCarrierPresent=1`, `a2bProbeA3Present=1`, `a2bProbeContactPresent=0`, `a2bProbeClosedChainPresent=0`, `a3ProbeContactPublished=0` — not the expected `missing-terminal-A3-path`. This is a stale/invalid fixture precondition for that assertion; it does **not** establish a production regression, nor prove the intended A3 guard is reachable.

**P1-b — guard `7414`: producer-consumer reachability is non-vacuous, but network *dependence* remains unproved.** The test `:7349–7443` first requires genuine produced `HardRail` edges with nonempty routes, actual filled cells, and source edges owned by the original A2a network. Static `assign_open_front_boundary_authority` is the publishing path, so the positive witness cannot pass if the entire boundary consumer is skipped. Its forged-rail negative rejects with `InvalidFrontBoundaryAuthority` and real cell/side indices, consistent with the consumer being reached. **However** the test replaces a published source-edge key without updating typed source vertex incidence. In `SurfaceCellTracing.cpp:6160–6168`, `rail_interval_refs` rejects this as `TypedAuthorityMismatch` independently of `fieldAlignedNetwork` (before mandatory network ownership is checked). Consequently the negative would still reject if the network binding were disabled. The passing guard demonstrates typed-rail/boundary reachability but **does not discriminate the network-bound validation branch**. Its helper also omits terminal/closed-chain provenance, although the forged rail already fails before those checks.

`7614` is a valid negative control for missing authentic open-rail contact and intentional fail-closed `EndpointAttachment` rejection. `405` supplies full producer-derived provenance and passes fine/coarse fixed-conformity checks. Neither proves the complete selector497 or production matrix.

## RA-161 P1 — corrective owner, stop criteria and falsifiers

Carry **RA-161 P1 OPEN** into the existing off-selector **O5 definition** (`M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION`), with a **separately bounded test-only CB/TB/REV owner before any full-selector credit**. O5 must specify two independent falsifiable corrections, not dilute or delete failing tests:

1. `8219`: derive `hard_rail_source_provenance_from_rails(fixture.rails, V.rows())` and provide authentic terminal contacts and closed chains to the fixed-plan helper while *only* withholding the selected non-hard A3 step. Preserve exact first-site `EndpointAttachment` and `missing-terminal-A3-path` assertions. **Falsifier:** any earlier provenance rejection persists, or the intended `missing-terminal-A3-path` does not occur. Independently inspect whether changing caller hard edges without rebuilding A1/A2b authority is a sound A3-path negative; re-home at the true producer if not.
2. `7414`: preserve the positive produced-rail/front-side witness, but pass full authentic A2b provenance to the negative and add a source-valid, geometrically/typed-consistent rail mutation that is accepted by the *network-absent* typed rail-interval check and rejected only by the *network-present* mandatory-edge ownership check (or prove this differential with an independent instrumented witness). **Falsifier:** identical rejection and first site both with and without the bound network, or pre-consumer rejection. Do not call existing mismatched source-edge-key rejection proof of network dependency.

Review boundary: no code, tests, fixtures, selectors, workflow, build, or runtime mutation. Next authorized turn from existing handoff: `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER`; do not execute successor inside this Review. O5 remains later, before the RP-01 census. Stable **66 events / 17 categories / 49 recurrences**, debt **1**; CP2 accepted **491/491**; RP-01 open, RP-02 unreached; nine historical TB38 RED identities remain in prior full-selector evidence, including `selector:405` until a complete accepted gate establishes recovery.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no selector introduced/changed in TB44 or this Review; four-row manifest SHA-256 rehashed as above |
| Decisive claims independently re-derived | Three ZIP digests; 28/28 and 10/10 checksums; four ledger/raw-log joins; source-path first-failure analysis |
| Non-vacuity checked | 405 producer positive passes; 7614 missing-contact negative is meaningful; 7414 proves consumer reach but not network dependency; 8219 fails at earlier fixture-precondition predicate |
| Prior obligations discharged/carried | RA-161 P1 OPEN at O5; RA-161 T2 at post-RP-01 O2; O1, O4, O5, O6, DIAG-RETAIN, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 carried |
| Stable accounting | 66 / 17 / 49, debt 1, CP2 491/491 accepted, selector497 frozen and unpromoted |
| New candidates/obligations recorded | P1-a and P1-b explicit owner/falsifiers in tracker and TODO |
| ORIENTATION currency line | TB44-REV 2026-10-26 recorded |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a — no witness-state promotion; §8 updated for precondition masking and non-discriminating negative |
| CHANGELOG | root changelog entry added |
| ROADMAP | n/a — M6 CP3 status did not change; inspected |
| Selector manifest | n/a — no selector or accepted-prefix changes |
| LESSONS | Existing witness non-vacuity and earliest-first-rejection principles applied; no new general lesson |
| Consolidation under CLEAN_UP_POLICY | n/a — TB44 source report retains unique raw provenance and this Review retains adjudication; no superseded same-family duplicates removed |
| Successor frozen | `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER`; P1 falsifiers above and carried O5, not rolled into 242 |
| Turn boundary held | Source-only independent Review; no build, executable execution, or product/test mutation |
| review_check.py boundary | Local snapshot-only `review_check.py boundary` FAILED ancestor checks (no history in snapshot-created temporary Git repo); selector hashes and source/test path boundary independently checked; run on full-history workflow if later needed |
| `STATUS` lifecycle maintained | Entry/resume beacon written; final COMPLETE beacon only after durable patch is applied and verified |
| Pushed to origin, branch in sync | Not yet established within source snapshot; verify on remote after patch workflow before COMPLETE beacon |
