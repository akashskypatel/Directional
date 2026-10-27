# CB46 — rail-oracle re-home and endpoint diagnostics (Code + Build)

- **Turn:** `M6-CP3-CB46-RP01-RAIL-ORACLE-REHOME-AND-ENDPOINT-DIAGNOSTICS`; [RA-164.4](Architecture_M6_CP3_TB45_REV_Audit_Rail_Oracle_Triage_Cadence_Realignment_Decision_20261027.md); test-only, compile-only.
- **Source commit:** `c05d52dd7c710d1ca32922f6cfe1f6b61a29db99`; exactly `tests/SurfaceCellREPackageTests.cpp`, `tests/SurfaceCellTransitionQuotientTests.cpp` modified in the successful [patch-apply workflow](https://github.com/akashskypatel/Directional/actions/runs/40446912263).
- **Exact patch:** r2 SHA-256 `313fa9150283b214c1925cdba04c1660761936684d61ea171f724c1a7dded712`; body SHA-256 `d346364ef2b3bc4f7162e9d1570b53d3e37e565e3071d3412650db54c98a7c9a`; +40/−24, two test files; checks pass. Initial patch attempt [40446597351](https://github.com/akashskypatel/Directional/actions/runs/40446597351) failed on comma-delimited intended-path metadata before commit; corrected separator, exact diff unchanged.
- **H1:** nonmanifold 3-face input rejects at `TriMesh::set_mesh`; overfull hard-feature fake incidence is separately tested on a valid manifold source, keeping four existing typed-rejection checks.
- **H2:** valid phase-front product control; cleared hard-edge input rejected at A4 checked factory as `InvalidSourceAuthority` / `open-rail-chain`; unreachable A5 negative removed.
- **D1:** terminal assertion message gains R/I endpoint kind, certificate/route/junction counts, carrier pair; predicate unchanged.
- **D2:** failed midline assertion message gains full produced certificate carrier/endpoint/junction inventory; predicate unchanged.
- **D3:** unequal-face-gauge assertion message gains both face gauges; predicate unchanged.
- **Compile:** [run 40447038466](https://github.com/akashskypatel/Directional/actions/runs/40447038466), package 12708707491 (ZIP SHA-256 `03f534ac5db362746be238bdc1929931586e071fbbdf00fa68ed5891c9036035`). Eight standard targets compiled. Exact source verified, GMP/GMPXX required, `runtimeExecution=false`; no tests/benchmarks executed.
- **Scope and accounting:** production, selectors, manifests, harnesses, workflows, and accepted accounting unchanged (CP2 491/491; 66/17/49; debt1). No CP3 promotion claimed.
- **Next:** `M6-CP3-TB46-RP01-FULL-GATE` directly, frozen 504-row manifest, artifact-only.
