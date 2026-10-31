# CB52 RP-01 — E2 factory rejection site pins (2026-10-29)

- **Turn:** `M6-CP3-CB52-RP01-E2-FACTORY-SITE-PINS`; Code + Build, compile-only.
- **Authority:** RA-170.4/.8 (`Architecture_M6_CP3_TB49_REV_Reaudit_P1_O4_DEFNs_E2_Site_Pins_OffGate_Census_20261028.md`).
- **Patch:** exact P6 diff body SHA-256 `9f538bc2be2c6b42de796ed87a83f35e5e881fcbfd160796fcbd1a8b48976c91`.
- **Scope:** `tests/SurfaceCellTransitionQuotientTests.cpp` only; `+16/−6`, five typed source-authority sites pinned with an optional assertion helper. No production, fixture, selector, or workflow changes.
- **Source:** `7cf0857b4818186638ce77e4859adacbeebd288f`; independently compared against source-snapshot `09404a62aacf597ff9c58b20c81e07dd708f3906` (+16/−6 test, dispatcher control only).
- **GMP compile:** [run 40919618039](https://github.com/akashskypatel/Directional/actions/runs/40919618039), eight approved targets; GMP and GMPXX link evidence, `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- **Package:** artifact `12918290481`, ZIP SHA-256 `89449f4f9c014c1d8c3235056c3dca2d2239ba136e09dd88e3e02710b253b5c1`; packaged integrity and source metadata verified.
- **No native tests, benchmarks or Directional runtime executed.** Build success is not semantic acceptance.
- **Frozen:** CP2 491/491 accepted; TB49 504/0 reviewed candidate, selector497 unpromoted; stable 66/17/49, debt1, RP-01 open.
- **Next:** `M6-CP3-TB50-RP01-FULL-GATE-EXEC` separately, frozen 508-case manifest `6d5b7886…`, forecast 508/0 unverified.
