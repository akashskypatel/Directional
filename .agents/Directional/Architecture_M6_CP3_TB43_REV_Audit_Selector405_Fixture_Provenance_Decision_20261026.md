# RA-161 — TB43-REV audit; selector405 root-caused to fixture rail provenance; O4 demoted (2026-10-26)

**Turn:** `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY-REV-AUDIT`. **Decision:** TB43-REV **CONFIRMED** (190 re-home 4/4 focused candidate, no promotion). Its successor (O4 DEFN) is **re-sequenced**: O4 closes no RED. Static analysis here root-causes accepted-prefix RED `selector:405` to a test-helper defect, so a narrow test-only CB44 goes next. No build, runtime or product change in this audit.

## RA-161.1 Independent verification

- Result artifact `12664712967` re-downloaded: ZIP SHA-256 `fbe75000…26804` matches; **12/12** `SHA256SUMS` OK; boundary 4/4 PASS, zero missing/skipped/duplicate/control_bad, `postflight=true`, compile/relink/configure false.
- 4/4 raw logs each hold exactly one `[ RUN ]`/`[ OK ]` for the ledger identity; ledger log hashes match.
- Manifest SHA-256 `812b843b…ffc676` added at `63e00c97b`, an ancestor of dispatch `ce6c084bf`. No `src`/`tests`/`include` change between CB43 source `d354d6ae9` and HEAD.
- CB43 hunk (`Phase10Tests:5176–5284`) implements RA-160.3 (a)–(d) exactly; only the 190 body changed.

## RA-161.2 Findings on TB43 / TB43-REV

- **T1 — accepted.** The vacuous atlas-versus-atlas comparison is gone; (b)+(c) discriminate the A3 transition relation; (d) pins the no-atlas factory locus `atlas-binding`.
- **T2 — (d) cannot detect a silent identity fallback.** The 190 field carries a balanced face gauge (±1 on three edges, `balanced_periodic_route_field`), so the periodic producer completes and reaches the factory whether the step rotation comes from compact matching (`SurfaceCellTracing.cpp:14966–14979`) or from the identity default (`:14937`, RA-160 D5). (d) guards the rejection *locus*, not whether legacy data is read. TB43-REV did not state this. Carried into the post-RP-01 O2 DEFN as a required discriminating fixture.
- **T3 — the successor does not advance RP-01.** O4 (`:12656/12698/12707` defensive `MissingTransitionProvenance` guards) has no RED identity. Nine REDs remain from TB38 after TB41/TB43: `selector:174, 201, 242, 405, 442`, `focused30:12`, `cp3entry:1, 2, 4`. Five are **accepted-prefix regressions** (CP2 491/491). They take precedence over oracle hygiene.

## RA-161.3 selector405 root cause (static, decisive)

- Test `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals` (`Phase10Tests:7583–7609`) calls `build_fixed_plan_rectangular_hard_rail_network(fixture, 0.5/2.0)` with **no** contacts.
- The helper (`:7099–7132`) sets `hardRailTerminalContacts`/`hardRailOpenChains` only when `contacts != nullptr` and `hardRailClosedChains` only when supplied. Production always sets all three from `hard_rail_source_provenance_from_rails(rails, V.rows())` (`RemeshPipeline.cpp:12775–12782`).
- TB38 raw log 447 (selector405): `InvalidHardRailRouteCertificate`, locus 3 (EndpointAttachment), rail 2, `a3ProbeContactPublished=0`, **`a2bProbeFailure=missing-terminal-or-closed-rail-provenance`** — the exact signature the companion negative `MissingOpenRailTerminalContactRejectsBeforeClosedRailFallback` (`:7614`) manufactures by erasing a contact.
- Conclusion: the RA-43.2/46.5 fail-closed contract is correct; 405's fixture never supplies the producer-owned A2b provenance. Defect class: **stale fixture after a production contract tightening** — not an A4 defect. All 12 other helper callers expect `Rejected`; 405 is the only positive.
- **P1 (carried):** two negatives also use the empty default — `ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer` (`:7414`, asserts `InvalidFrontBoundaryAuthority` at a cell side) and `MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate` (`:8219`, asserts `missing-terminal-A3-path`). Their asserted causes differ from the missing-contact signature, so they are probably discriminating, but they run on non-production inputs. Both are off-gate (O5). Disposition after TB44.

## RA-161.4 CB44 specification

- **Turn:** `M6-CP3-CB44-RP01-SELECTOR405-FIXED-PLAN-RAIL-PROVENANCE`, test-only, compile only.
- **Edit:** only the 405 body (`Phase10Tests:7583–7609`). Before the two builds: `const auto provenance = directional::pipeline::hard_rail_source_provenance_from_rails(fixture.rails, static_cast<std::size_t>(fixture.mesh.V.rows())); ASSERT_TRUE(provenance.has_value());` then call the helper for 0.5 and 2.0 with `&provenance->terminalContacts, nullptr, &provenance->closedChains` (the helper derives `openChains` from the same rails). Keep every existing assertion and message.
- **Must not change:** the helper, any other test, production source, selectors, harness, workflows.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, record ≤30 lines with the exact hunk.
- **STOP → Review:** symbol not visible from the test TU; helper change appears necessary; selector bytes would change. A runtime rejection after the fix is a TB44 finding (new first cause), not a CB fix.

## RA-161.5 Turn sequence (frozen IDs)

1. CB44 → `…-REV` (static; issues TB44 manifest).
2. `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY`, artifact-only, CB44 package: 405 POSITIVE; GUARD `:7614`, `:7414`, `:8219` companions (off-gate, recorded as such). → `…-REV` (disposes P1).
3. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → REV (RED; coordinate DEFN-SEAM-NZ).
4. 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`); Review assigns IDs one owner per turn.
5. `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4) and `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (O5) → REV each.
6. Census → RP-01 Review (O6 scope statement). Post-RP-01: O2 DEFN (RA-160.4 + T2).

Carried: DIAG-RETAIN, O1, O2, O4, O5, O6, P1, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:** stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidate; TB41 18/18, TB42 1/1, TB43 4/4 focused candidate; selector497 frozen; RP-01 open.
