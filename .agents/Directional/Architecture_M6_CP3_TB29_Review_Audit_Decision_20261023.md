# RA-142 — Audit of the TB29 review (RA-141): evidence upheld; M1 is ten rows (six measured, four proven statically); DEFN-M1 scope restored (2026-10-23)

**Turn:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV-AUDIT` (independent audit of RA-141).

**Verdict:**
- **Upheld:** RA-141's evidence and its partition of the 35 REDs; the exclusions of the seven non-M1 factory rows, the A3 rows, `focused30:12` and `cp3entry:1/2`; and the authorization of `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE`.
- **Corrected:** RA-141 left `selector:211, 219, 227, 230` out of M1 as "reason-not-observed". The source proves they reach the **same** R2 certificate-pair-binding clause first.
- **Why it matters:** they are M1's frozen-precedence oracles, the tests that state which error must win: `InvalidOppositeEdge` and `InvalidHardRailAuthority`. A DEFN-M1 scoped without them would define precedence without its decisive oracles.
- **DEFN-M1 is re-scoped to all ten RA-105.3 rows**, still documents-only.

## RA-142.1 Re-verified

- **Artifact:** result `12481556884`. The provider digest equals the local ZIP SHA-256 `4e639a63…ae1`; it expires 2026-10-30T05:47:15Z. **92/92** checksums pass. `execution-boundary.json` shows 44/44 executed, 9 PASS, 35 RED, every `*_bad`/missing value 0, postflight true, exit 0.
- **Partition confirmed:**
  - factory 13: `certificate-pair-binding` 6, `face-gauge-missing` 6, `open-rail-chain` 1;
  - A3 8;
  - A5 1;
  - untyped 13.
- **Factory code 0** is `InvalidSourceAuthority` (`SurfaceCellTracing.h:1900–1901`).
- **The four A7 negatives** are non-vacuous, as RA-141 states (RA-135 design; CB27A/CB27 preconditions).

## RA-142.2 The four "untyped" rows are R2 certificate-pair-binding rejections (static proof)

The R2 clause (SCT:8828–8841) rejects with `InvalidSourceAuthority`, site `certificate-pair-binding`, if a certified hard-rail pair has a mismatched `oppositeEdge`, `railId`, `route`/`route.reversed()`, or region. It runs **before** the factory's own `InvalidOppositeEdge` check (SCT:9350).

| Row | Test | Tamper | First clause reached | Frozen expectation preempted | Log evidence |
|---|---|---|---|---|---|
| `selector:219` | `MissingHardRailCounterpartIsRejected` (TQ:9049) | hard-rail `oppositeEdge = -1` | `first.oppositeEdge != certificate.secondFrontEdge` (SCT:8833) | `InvalidOppositeEdge` (7) | actual code `<00-00 00-00>` = 0 |
| `selector:211` | `AmbiguousHardRailCounterpartIsRejected` (TQ:9067) | the opposite's `oppositeEdge = self` | `second.oppositeEdge != certificate.firstFrontEdge` (SCT:8834) | `InvalidOppositeEdge` (7) | actual code 0 |
| `selector:227` | `DuplicateSemanticRouteTopologyFailsClosed` (TQ:10189) | hard-rail `route` replaced | `first.route != certificate.route` (SCT:8836) | pipeline `InvalidHardRailAuthority` | `InvalidPhaseFrontProduct`, which the TQ `materialize` helper (TQ:2551–2563) returns for **any** factory rejection |
| `selector:230` | `RouteTopologyTransitionMismatchFailsClosed` (TQ:10146) | hard-rail route transition changed | `first.route != certificate.route` (SCT:8836) | pipeline `InvalidHardRailAuthority` | as above |

**Status of the claim:**
- For 211/219, the observed code already narrows the cause to an `InvalidSourceAuthority` clause. The listed clause is the first one in the factory that reads the tampered field.
- For 227/230, the observation shows only that the factory rejected the draft. The route clause is the first factory clause that reads `route`.
- Not measured: the site string. The harness can't read GoogleTest's byte rendering of an enum (`<00-00 00-00>`), and `materialize` discards the factory error.
- The post-fix TB will settle it: if any of the four still fails with code 0, or with `InvalidPhaseFrontProduct`, after the M1 correction, that falsifies the claim.

**Result:** M1 = RA-105.3's ten rows, exactly: `focused30:3, 22, 23`; `selector:139, 140, 142, 211, 219, 227, 230`. Six are measured at site `certificate-pair-binding;certificate=0;rail=2` and four are statically proven. RA-141's statement that RA-105.3's ten-row grouping is unproven is withdrawn: the grouping holds, partly proven from the source rather than measured.

## RA-142.3 The design question DEFN-M1 must answer

- **The shared failure:** the A4 product factory checks hard-rail pair integrity (opposite, rail id, route, region) against the A4-owned certificate. It reports every mismatch as generic `InvalidSourceAuthority`. That preempts two kinds of frozen, specific rejections:
  1. the factory's **own** structural check, `InvalidOppositeEdge` (211/219);
  2. **downstream** owners: the pipeline's `InvalidHardRailAuthority` (227/230), and A5's hard-rail route and strict-transport validation (focused30:22/23, which encode RA-15/RA-19 precedence; `selector:139/140/142`, strict transport; focused30:3, A5 relation-endpoint checks reached through a published draft).
- **DEFN-M1 must decide, per tampered field, which single owner rejects first and with which typed code.** Options:
  - (a) structural checks run before certificate binding, which then reports field-specific codes;
  - (b) the binding stays first but carries frozen field-specific codes and sites;
  - (c) A4 drops checks that A5 owns, if RA-15/RA-19 make A5 the owner.
- **Each option needs a non-weakening table:** every tamper must still reject, at the owner the frozen tests name, and a forged certificate must still reject.
- **Test expectations are not to change.**

## RA-142.4 DEFN-M1 deliverables (amended)

The output is `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md`, at most 100 lines, anchored at HEAD. It must contain:

1. **Clause audit:** the factory's validation order (`SurfacePhaseFrontProduct::make`, SCT:8439), from the R2 binding loop (SCT:8814–8841) through `InvalidOppositeEdge` (SCT:9350), plus the A5 hard-rail route and strict-transport checks that 22/23 and 139/140/142 expect.
2. **Ownership matrix for the ten rows:** tamper; expected frozen code and owner; currently reached clause (measured or static); proposed first-rejecting clause.
3. **The chosen option**, (a), (b) or (c), with a rationale traced to RA-15.2–15.4, RA-19.1 and RA-105.3.
4. **Non-weakening table:** forged or absent certificate, wrong rail, reversed route, same region; each still rejects, with the named clause.
5. **Predictions and falsifiers for the corrective TB:**
   - the ten rows reach their frozen expected outcome;
   - the seven non-M1 factory rows are unchanged (still `face-gauge-missing` / `open-rail-chain`);
   - the nine TB29 controls still PASS.
6. **Exclusions,** each with its owner:
   - face-gauge-missing (6), with a note that the direct periodic-owner fixture (TQ:≈358) passes no face gauges;
   - open-rail-chain (1);
   - A3 (8);
   - A5 `focused30:12`;
   - `cp3entry:1/2`;
   - the other 9 untyped rows.

**STOP** and return to Review if no option satisfies all ten frozen expectations without changing a test or disabling a guard.

## RA-142.5 Sequence and accounting

- **Sequence:** audit (this) → **DEFN-M1 (ten rows)** → DEFN-M1-REV → corrective CB (product, scoped by DEFN-M1-REV) → CB-REV → TB (the ten M1 rows, the seven non-M1 factory rows, the nine controls; targeted harness with a Review-owned manifest) → TB-REV.
- **After that:** owners for face-gauge-missing, A3 cycle locus and A5 `focused30:12` (each DEFN or diagnostic first) → DEFN-T1 → fixture debt → census (needs an RA-139.3-compliant harness) → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; TB28 462/497 candidate; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | Result digest, 92/92, boundary state; partition; enum value 0; the four tests' tampers and failure blocks; R2 clause conditions (SCT:8828–8841); `InvalidOppositeEdge` site (SCT:9350); `materialize` mapping (TQ:2551–2563) |
| Non-vacuity | Static first-clause proof per row, with an explicit falsifier at the post-fix TB |
| Obligations | RA-141 upheld except the M1 exclusion; DEFN-M1 scope and deliverables amended; RA-139.5 carried |
| Durable docs | Handoff, TODO, tracker, CHANGELOG, ORIENTATION, Frozen Definitions index, DEFN-M1 plan pointer |
| Boundary | Review-only; no source, test, harness, manifest, selector, workflow or runtime change |
