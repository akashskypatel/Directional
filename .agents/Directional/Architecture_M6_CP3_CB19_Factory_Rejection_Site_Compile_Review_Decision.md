# RA-106 — CB19 compile failure reviewed: diagnostic design stands; corrective CB19A authorized (2026-10-20)

**Turn:** `M6-CP3-CB19-RP01-FACTORY-REJECTION-SITE-REV`. **Inputs:**
- CB19 semantic commit `1f73d0abd`;
- compile run `39428435345`, artifact `12265949093`, which failed in the `directional_core` preflight;
- record `Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Failure_20261020.md`.

**Base:** `3bd24682c`, whose src/include/tests are identical to `2a02d3b8e`. S and TQ lines are at HEAD `7c207ea75`. **Amends:** RA-105.6 (one falsifier) and RA-105.5 item 5 (one assertion).

## RA-106.1 Static verification of the CB19 patch

- **Diff against the base:**
  - header +2/−0;
  - S +49/−0;
  - TQ +59/−1. The one removed line is the authorized TQ:4980 `ASSERT_NE`.
  - No other source path changed.
- **Labels are complete.** All 77 `return error;` in `make` (S:8439–9577) were mapped to their codes:
  - 47 are `InvalidSourceAuthority`, each with exactly one label, and all 47 labels are unique;
  - the other 30 set an explicit non-zero code, so none returns the default code 0 unlabelled;
  - none of the static falsifiers in RA-105.5 item 7 fired.
- **Failure struct.** S:13146 copies the site, and both new members are last. Neither struct has an equality operator or a serializer.
- **Reporting reaches every M2 identity.** All nine fail through a path that now prints the site:
  - `require_produced` at TQ:862 (rectangle: `cp3entry:2/6`);
  - `require_produced` at TQ:1672 (torus: `cp3entry:1`, `focused30:6/20/24`, `selector:446/447`);
  - TQ:4980 (`focused30:12`).
- **Selectors.** No selector file contains a wildcard, so `SurfaceCellFactoryRejectionSite` is outside every frozen selector.

## RA-106.2 The compile failure: cause, extent, and what it could hide

- **Cause, confirmed.** 28 labels begin `"<literal>" + ";…"`, which is `const char[N] + const char[M]` and is ill-formed. They are 2 pin, 9 certificate, 9 endpoint and 8 junction labels. The other 19 labels are plain literals.
- **No second defect is masked.** Every other name in those expressions resolves (C++20):
  - `endpointIndex` (S:8900) and `junctionIndex` (S:9033);
  - `SemanticId::index()` for `HardRailId` and `SourceVertexId`, and `SourceEdgeTopologyKey::first()/second()`;
  - `std::vector::data()`, `std::optional` in `&&`, and the `const char*` ternary.
- **The TQ changes have never been compiled.** The build stopped before any test target. Their helpers were checked statically:
  - `hard_rail_fixture` TQ:782;
  - `phase_front_draft` TQ:1844;
  - `construct_phase_front_product` TQ:1861;
  - `test_source_edge_topology` TQ:74.

  Only the eight-target build can accept them.
- **Verdict: this is an implementation defect, not a design or architecture block.** The RA-105.5 label set, format and insertion points stand. CB19's diagnostic is still the right next step for RP-01: TB19 cannot rule on H-pin or `cp3entry:2/6` without it.

## RA-106.3 Required correction: one suffix definition per scope, not 26 copies

The record's proposed fix, a `std::string` leftmost operand on each line, would compile. It is not accepted:
- it keeps 26 copies of an expression up to 412 columns wide that encodes the same certificate, endpoint and junction suffix;
- that breaks the file's wrapping idiom: no line of `make` before CB19 is longer than 100 columns;
- the label format would live in 26 places that can drift apart without any error.

Required instead. Every change below is a new line, so the `make` diff against `3bd24682c` stays insertions-only.

1. Add as the first statement of the certificate loop body (after S:8776):
   ```cpp
       const auto certificate_site = [&](const char *clause) {
         return std::string(clause) + ";certificate=" +
                std::to_string(static_cast<std::size_t>(
                    &certificate - hardRailRouteCertificates.data())) +
                ";rail=" + std::to_string(certificate.rail.index());
       };
   ```
2. Add after `const auto &endpoint = certificate.endpoints[endpointIndex];` (S:8901):
   ```cpp
         const auto endpoint_site = [&](const char *clause) {
           return certificate_site(clause) + ";endpoint=" +
                  std::to_string(endpointIndex) + ";kind=" +
                  (endpoint.terminalVertex && endpoint.railVertex ? "TR"
                   : endpoint.terminalVertex                      ? "T"
                   : endpoint.railVertex                          ? "R"
                                                                  : "I");
         };
   ```
3. Add after `const auto &junction = certificate.junctions[junctionIndex];` (S:9035):
   ```cpp
         const auto junction_site = [&](const char *clause) {
           return certificate_site(clause) + ";junction=" +
                  std::to_string(junctionIndex);
         };
   ```
4. Rewrite each of the 26 scoped labels as `error.sourceAuthoritySite = certificate_site("<clause>");`, using `endpoint_site` or `junction_site` in their scopes, with the same clause strings.
5. The two pin labels become `std::string("gauge-pin-<clause>;edge=") + std::to_string(edge.first().index()) + "," + std::to_string(edge.second().index())`, wrapped to the file's width.
6. The 19 plain labels are unchanged.
7. Every produced label string must be byte-identical to the label CB19 intended.

## RA-106.4 Test correction (new test, TQ:1892)

- **Weak check.** The incidence check accepts an edge with only one vertex on face 0. For example, edge (1,2) would pass.
- **Required.** Both edge vertices must be corners of `fixture.mesh.F.row(0)`. Nothing else in the test changes.
- **Static basis:**
  - face 0 = (0,1,4) and face 1 = (0,4,3) share the intra-region edge (0,4);
  - (1,4) is the rail carrier between faces 0 and 3;
  - the baseline passes the pin;
  - a +1 (mod 4) change to face 0 alters `compose(T, g_first) == g_second` only on face 0's two-face edges. The first rejected edge must therefore be (0,4) or (1,4), and the stronger assertion is not flaky.

## RA-106.5 TB19 falsifier amended (RA-105.6)

- **The falsifier is wrong by construction.** RA-105.6 lists "a `PublishedProductRejected` with an empty site" as a falsifier, but only the 47 `InvalidSourceAuthority` returns carry a site.
- **Amended falsifier:** `product=0` with an empty site.
- **A non-zero `product=` is a recorded result,** not a falsifier.
- **Codes with several returns.** Five non-zero codes cannot be told apart by code alone:
  - `NonReciprocalPeriodicRelation` (6 returns);
  - `RepresentationRenumberedPeriodicRelation` (3);
  - `InvalidSharedBoundaryInterval` (3);
  - `MissingPeriodicRelationOwner` (2);
  - `InvalidPeriodicRelationOwner` (2).

  If `cp3entry:2` or `cp3entry:6` reports one of them, TB19-REV orders a separate site follow-up for that code only. Nothing is labelled for them now.

## RA-106.6 Next unit — `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE` (Code + Build, compile only)

- **Scope:** RA-106.3 in S and RA-106.4 in TQ, on top of `1f73d0abd`. Nothing else: no header change, no S:13146 change, no other test, selector, harness, fixture or `RemeshPipeline.cpp` change.
- **Static acceptance:**
  - against `3bd24682c`, the `make` diff is insertions only;
  - 47 labels, unique, byte-identical to CB19's;
  - no single line in `make` is longer than 100 columns.
- **Build:**
  - GMP/GMPXX, eight targets, package, `runtimeExecution=false`;
  - the CB19A record has the label → S-line table and supersedes CB19 as the build record. The CB19 failure record stays as evidence.
- **STOP:** any compile error. Record the first diagnostic of each distinct error and return to Review. There is no second repair inside the turn.
- **Carried:** CB19's staged transport file goes to the CB19A closeout.
- **On success:** TB19 under RA-105.6 as amended by RA-106.5, pinned to the CB19A package. TB19-REV remains mandatory.

## RA-106.7 Sequence and accounting

> **Amended by RA-110.6 (2026-10-20):** sequence.

- **Sequence:** CB19A → TB19 → TB19-REV (mandatory) → [DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB] → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:**
  - 66/17/49, debt 1;
  - CP2 491/491;
  - R3 403/497 rejected;
  - TB18 candidate 448/497;
  - selector 497.

  `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.
