# RA-155 — TB38-REV audit; tamper-oracle homes bound; 250 site first (2026-10-25)

**Turn:** `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS-REV-AUDIT`. **Decision:** TB38-REV **ACCEPTED** (candidate census 490/14). Its successor, a single seven-oracle DEFN turn, is **replaced**. Review binds the determinate homes here (RA-155.3) and narrows the DEFN to the two oracles that cannot yet be decided (RA-155.4). Static review plus independent artifact re-verification; no build, test or product change.

## RA-155.1 Independent verification

- TB38 result artifact `12597140251` re-downloaded:
  - ZIP SHA-256 `0cdfe445…a9870` matches; **1,014/1,014** `SHA256SUMS` OK.
  - `execution-boundary.json`: 504/504 executed, 490 PASS / 14 RED; missing, skipped, duplicate, `control_bad` and `unexpected_pass` all 0; `postflight=true`.
  - The 14 RED identities match RA-154.4.
- Raw logs 233/234 (191/192) fail at the `Rejected` assertion with Produced. Raw log 292 (250) is still `PublishedProductRejected` (68).
- TB38-REV's table is correct.

## RA-155.2 Gaps in TB38-REV

- **H1 — the successor is monolithic.** One DEFN covering seven oracles with different mechanisms, several of them decidable statically now. Replaced by RA-155.3/.4.
- **H2 — test 190 is architecturally unsatisfiable, not merely "non-discriminating".**
  - `SurfacePhaseFrontProduct::make` rejects a null atlas (`SurfaceCellTracing.cpp:8462`, `atlas-binding`).
  - A3 cannot be built from a legacy-only field: `edgeTransitions` is empty, so `MissingAdjacency` (`FieldTransportAtlas.cpp:2017`).
  - So no legacy matching path can ever publish a product.
  - **O2:** the producer's legacy branches (`SurfaceCellTracing.cpp:14950–14979`) and the legacy branch of `resolve_branch_transition` (`:6731ff`) are unreachable for any produced output. Removing them is a later DEFN, not now.
- **H3 — 242 does not belong with the others.**
  - Its tampered edge is cross-region (sheets `{0,1}`). A3 keeps the `transition_value` but builds no adjacency for it (`FieldTransportAtlas.cpp:2050–2057`).
  - A4 branch propagation reads `transport()` and never crosses that edge, and the `make` gauge-pin skips cross-region edges (`SurfaceCellTracing.cpp:8558–8561`).
  - A single-record `matching += 1` is reciprocal by construction, because A3 derives `reverse = forward.inverse()`.
  - No A2–A4 consumer exists for the stimulus. Its home is downstream (isolation-seam certificate; DEFN-SEAM-NZ), or the test retires.
- **H4 — test 192's own stimulus is not a monodromy.** A single-edge `+2` (`assign_directed_matching`) fed to A3 is rejected at S1 `CycleTransportMismatch` (the TB34 mechanism). Re-homing therefore needs the turning field, not the existing stimulus.
- **H5 — the 250 diagnostic was left conditional, though its condition was met.** 68 persisted in TB38. The checked-factory rejection already carries `publishedProductError`, `publishedProductSourceAuthorityDetail` and `publishedProductSourceAuthoritySite` (`SurfaceCellTracing.cpp:13196–13201`), so a message-only test change exposes the exact `make` site. Test 250 is the only **positive** periodic composition still failing, which makes it the highest-value item on the RP-01 trajectory. **It goes first.**

## RA-155.3 Bound homes

All re-homes below are test-only. Each keeps its test identity, so no selector byte changes.

- **A — 191 and 204 (`sourceEdge = -1`):**
  - The tampered field becomes the **A3 input**.
  - Assert the untampered `FieldTransportAtlas::make` succeeds.
  - Assert the tampered `make` fails with `NonReciprocalAdjacency` and `error.sourceEdge ==` the tampered topology key.
  - Do not call A4 on the tampered input.
  - This covers the A3 branch `raw.sourceEdge != edgeIndex` (`FieldTransportAtlas.cpp:2020`), which **no existing test** covers; the `FieldTransportAtlasTests` matrix tampers faces only.
  - Moving the expected failure from A4 (29 / `MissingTransitionProvenance`) to A3 is authorized here. It relocates the failure to the single writer and is not a relaxation.
- **B — 192 and 247 (monodromy):**
  - Replace the stimulus with an atlas built from a turning field: 192 uses k=1 via `turning_periodic_route_field`; 247 uses k=2 on the committed cylinder and rawfield (a mesh-level overload of that helper is allowed).
  - Keep every original A4 assertion: Rejected, 29, no product, empty seeds/traces/proposals, and for 192 the all-−1 locus.
  - Keep each positive half, and assert A3 succeeds and `singularIndices` is empty.
- **C — 189 (equivalent lift):**
  - Build each run's A3 from **its own** field: baseline, and the ±4 equivalent.
  - Assert both A3 builds succeed and the A4 periodic snapshots are equal.
  - This discriminates whether the raw lift (`signedLift`) leaks into A4. The current version is vacuous because the ±4 copy is never consumed.

## RA-155.4 Narrowed DEFN (after the CB groups)

`M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES`, design only:
- **190:** retire it, or re-home it as an A3 `MissingAdjacency` negative. Either way it needs an accounting rule for an identity in the accepted prefix.
- **242:** find a downstream consumer of cross-region `transition_value`, or retire it; coordinate with DEFN-SEAM-NZ.
- **O2:** the scope for removing the legacy branches.
- Also inventory the out-of-selector analogue `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed` (`Phase10Tests:~3580`).

## RA-155.5 CB37 specification (next turn)

- **Turn:** `M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE`, test-only, compile only.
- **Edit:** `tests/SurfaceCellsPhase10Tests.cpp:3666–3669` only, the **streamed message** of the existing `ASSERT_EQ(Produced, …)`. Replace it with `curved_disk_factory_rejection_detail(network.phaseFront)` (helper at `:2630`, which prints the reason, `publishedProductError` and the detail), followed by `" site="` and `rejection()->publishedProductSourceAuthoritySite`, null-guarded.
- **Must not change:** the assertion's operands or macro; any other line; production code; selectors; the harness.
- **Evidence:** the 8 GMP/GMPXX targets, `runtimeExecution=false`, and a record of 30 lines or fewer with the exact hunk.
- **STOP:** the helper is not visible at `:3666`, or the field name differs.

## RA-155.6 Turn sequence

1. CB37 (250 message) → CB37-REV (static; issues the TB39 manifest).
2. `M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST`, artifact-only on the targeted harness. Rows: 250 (RED, site harvested) plus the 3 TB36 witnesses and 193–195 as GUARD. Then TB39-REV classifies the site:
   - codes 56–66 → periodic action convention (links to O1);
   - code 0 / `InvalidSourceAuthority` → the reported site;
   - otherwise as typed.
   - It then binds the 250 owner.
3. CB38-A (191+204) → REV.
4. CB39-B (192+247) → REV.
5. CB40-C (189) → REV.
6. TB40, focused on the re-homes: 189, 191, 192, 204, 247 plus guards (TB36 witnesses, 193–195, the two A3 guards). Then TB40-REV.
7. DEFN legacy-path and seam oracles (RA-155.4) → REV → its CB/TB.
8. 250 owner turns, per the TB39-REV binding.
9. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) → census → RP-01 Review.

Carried: `DIAG-RETAIN`, O1, O2, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:** stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidate; selector497 frozen; RP-01 open, RP-02 unreached.
