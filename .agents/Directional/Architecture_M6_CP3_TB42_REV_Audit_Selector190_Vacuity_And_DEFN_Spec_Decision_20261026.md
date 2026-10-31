# RA-159 — TB42-REV audit: selector190 vacuity, legacy-path DEFN spec, O6 (2026-10-26)

**Turn:** `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY-REV-AUDIT` (Review). **Decision:** TB42-REV is **confirmed** (O3 3/3 focused candidate; no promotion). Its successor `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` stands, but its premise is corrected and its questions are bound (RA-159.3).

## RA-159.1 Independent verification

- TB42 result `12644936205`: ZIP SHA-256 `2d0c6cf7ab7e1eb7321f1adf0720e5ea2fd585c6762e9458de03c4f260d9b1b6`; 5/5 inner hashes; ledger row joined to `raw/1.log` (hash, one RUN, one OK, `PASSED 1`, no FAILED); boundary planned=executed=passed=1, `postflight=true`, compile/relink/configure false, source `8dc8cdeae`, package `12634151125`.
- Manifest SHA-256 `b266c05669dac6159e12b71831de6c7e17d4f64b9f47a8dae1d76a2bf5578885`, identical at freeze commit `b394edf88` (before dispatch `a7acf506d`).
- The rejection is the unique `:17186–17192` site (after `chartConstructed=true`, `cell`/`side` default −1).

## RA-159.2 Findings

- **N1 — O3 pins a limitation, not a capability (new O6).** `make_polygonal_curved_disk_fixture` (`Phase10Tests:2822`) is a six-corner L-shaped disk with an axis-aligned field and a hard boundary — a routinely quadrangulable input. The producer rejects every nonrectangular bounded disk by design (`SurfaceCellTracing.cpp:17182–17185`: lattice clipping/pairing "remains a distinct deeper front-construction contract"). Neither `DESIGN.md` nor `ROADMAP.md` names a requirement or owner for that contract, and M8's representative-witness gate will meet such inputs. The O3 tests are correct fail-closed oracles today; they will flip by design when the capability lands. **O6:** the RP-01 Review must state whether CP3 excludes nonrectangular bounded disks and name the roadmap owner. Not an RP-01 corrective item.
- **N2 — selector190 is a vacuous PASS, not "unsatisfiable".** RA-155 H2 called it unsatisfiable; TB38 measured it GUARD PASS. Both are explained by commit `7ccdcd527` (2026-10-11), which changed 190 from `build_periodic_route_network(fixture, legacyField)` to `build_periodic_route_network_with_source_atlas(fixture, legacyField, authoritativeField)` (`Phase10Tests:5182–5183`). The atlas is built from `authoritativeField`, and A4 takes each step's transport from the atlas before any field transition (`SurfaceCellTracing.cpp:14937–14979`: atlas → `hasTransitions` → `edgeMatching`). `legacyField` only selects the provenance lookup (`:14926–14929`, `hasTransitions ? edgeTransitions : nullptr`), which succeeds on this fixture; it never decides a transport. The holonomy comparison is therefore authoritative-versus-authoritative. It is the **last** mismatched call in the periodic-route family; every other call site passes the same field twice (189 was the same defect, fixed by CB41).
- **N3 — the accepted-prefix credit for 190 is for a different oracle.** CP2 was accepted 2026-10-06, before `7ccdcd527`. Its 190 asserted that a legacy-only field publishes, which D1/RA-40 now forbids (`SurfacePhaseFrontProduct::make` rejects a null atlas, `SurfaceCellTracing.cpp:8462`). So: the CP2 credit is historical and not revocable, the original oracle is architecturally void, and the TB38/TB41-era 190 PASS rows are not legacy-path evidence.
- **N4 — O2 has a live detail-level consumer.** `SurfaceCellVertexContinuationRouteTransportAuthorityMigration.LegacyMatchingPathUsesSameTypedRouteComposition` (`Phase10Tests:5716`) calls the continuation resolver with `nullptr` transitions and so exercises the legacy branch directly. It is in no gate (O5). Removing the legacy branch (`:6731ff`) deletes its subject.
- **N5 — documentation drift.** TODO listed the DEFN twice (NEXT and Then); the handoff "Latest candidate" row omitted the TB42 result. Corrected.

## RA-159.3 DEFN specification — `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION`

Design only; one record ≤60 lines; no source/test/selector/workflow change. It must answer, each with file:line evidence:

1. **Vacuity (confirm or refute N2).** Trace `legacyField` in 190 from the helper (`Phase10Tests:4490–4516`) to every A4 read, including the provenance lookup at `:14926–14929`; state whether any transport or published value depends on it.
2. **190 disposition — choose exactly one:** (a) re-home under the same identity as an A3 negative: untampered `FieldTransportAtlas::make(authoritativeField)` succeeds; `make(legacyField)` fails with `MissingAdjacency` and the first missing edge key; or (b) retire the identity. State the expected first error code from `FieldTransportAtlas.cpp:2016–2018` and why it discriminates.
3. **Accounting rule** for an identity in the accepted 449 prefix whose original oracle is void under D1: selector bytes unchanged (re-home keeps the name) or changed (retire); how CP2 491/491 is annotated (historical credit kept, not re-counted as legacy evidence); how TB38/TB41 rows are annotated.
4. **O2 inventory.** Every non-atlas branch in the producer (at least `SurfaceCellTracing.cpp:14952–14979` and `:6731ff`), each classified: reachable through `build_surface_cell_network` + checked factory to a published product / reachable only to a rejection / reachable only through detail APIs used by tests / unreachable. Name each test that consumes it and its gate (in-gate or O5).
5. **Removal scope** (no code): whether removal changes any rejection reason or locus on no-atlas inputs, and which test identities then die or must be re-homed.
6. **Successor:** at most one test-only CB (for 190) and, separately, at most one production CB (O2 removal), each with exact files, assertions and STOP rules.

**Falsifiers / STOP → Review:** any production caller publishes without an atlas (that is a defect, not a DEFN); `make(legacyField)` returns a code other than `MissingAdjacency`; a legacy branch decides a published product; the accounting rule would alter selector497 bytes without explicit user authorization.

## RA-159.4 Turn sequence

1. `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` → `…-REV`.
2. `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4) → `…-REV`.
3. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` (242) → `…-REV`.
4. Code/TB turns authorized by steps 1–3 (their Reviews assign IDs).
5. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`).
6. `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (O5) → `…-REV`.
7. Census → RP-01 Review (must include the O6 scope statement).

## RA-159.5 Accounting

Unchanged: stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 and TB38 490/504 candidate; TB41 18/18 and TB42 1/1 focused candidate; selector497 frozen; RP-01 open, RP-02 unreached. Carried: DIAG-RETAIN, O1, O2, O4, O5, O6, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.
