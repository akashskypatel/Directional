# TB35 — immutable periodic route gauge verification (2026-10-24)

**Turn:** `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY`. **Disposition:** immutable focused candidate evidence; **11 PASS / 2 RED**, no CP3 or production acceptance. Separate independent `TB35-REV` must reopen and adjudicate all original oracles.

## Exact authority and evidence

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; compiled semantic SHA `d5fc8f22fd309ba90ad1fd7b4fbdc3491a5a8f7d`; CB34 artifact `12566907246` (outer SHA-256 `ca5c490bae2d65f9c043636c285d29edcfe5695b9334c24edcc281fac26c6a17`), GMP/GMPXX, exact source.
- Frozen manifest `Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Case_Manifest.tsv`, SHA-256 `d67e503db14f2cb1ae978482665057372edd2e56d7763cd38288469174e75af8`; original 7 selector identities 189–195, new face-gauge oracle, two A3 guards, three factory controls. No test/selector/fixture edits.
- Successful [run 40116807908](https://github.com/akashskypatel/Directional/actions/runs/40116807908), artifact `12569985565`, ZIP SHA-256 `155ae1c43c7c83b43decf43ba5b8a711860cf00f304e9f975a0c552a26e1309e`; **18/18** result-file checksums verified independently, all 13 raw GTest logs re-read. 13 distinct processes, one selected terminal test each, no missing/skip. Postflight true, exact package/source hash verified, `compile=false`, `relink=false`, `benchmark=false`, `selector_mutation=false`; all required GMP runtime libraries resolved.
- First [run 40115355472](https://github.com/akashskypatel/Directional/actions/runs/40115355472) failed before execution (zero tests) because harness erroneously required 12 unique cases rather than manifest's 13. Its result `12567799356`, log `12568735157` document `duplicate case`; not accepted as runtime evidence. Corrected **only execution harness preflight** at `ab57c9f62e0b738b0ed98d8e6fd2a2e35bd08453`, SHA-256 `83edec8624c7552ed82f7b1dff0ae28601be243f3e9d2a21873fadca16b41243`; retry request commit `78ae61adb7c4f226dcc7d4dbb4240d4a52f1d6fc`. Neither attempt rebuilt or changed the immutable test/package authority.

## Results and first observed failures

| Kind / identity | Independent result |
|---|---|
| selector:189,190,193,194,195 | **PASS 5/5**; original seven improved from TB34 0/7 PASS to TB35 **5/7 PASS** |
| selector:191 | **RED**; `MalformedAuthoritativeCrossingProvenanceFailsClosed`, raw/3.log, source test line 4824 first fails: expected `Rejected` but phaseFront returned `Produced`; expected `PeriodicHolonomyMismatch`, actual `None`, then exception `Expected rejected phase-front outcome.` |
| selector:192 | **RED**; `NonzeroNetCycleFailsClosedAtPeriodicHolonomyGuard`, raw/4.log, source test line 4665 first fails: expected `Rejected` but phaseFront returned `Produced`; expected `PeriodicHolonomyMismatch`, actual `None`; produced-product and rejection invariants also fail. |
| face-gauge:invariance | **PASS**; independent gauge/canonical invariance oracle |
| atlas-guard:1, atlas-guard:2 | **PASS 2/2** |
| TB33 factory controls | **PASS 3/3** |

The prior A3 S1 `CycleTransportMismatch` no longer appears as the first failure on the seven selectors. The two remaining negative tests now exercise the phase-front negative expectation, but **failure owner is provisional**: independent Review must re-derive whether malformed provenance/nonzero tracing rotation should be rejected at A4 and why no rejection occurred. No test-fix, acceptance relaxation, source-field substitution or producer mutation is permitted in this TB turn. No cumulative 497-case recovery is inferred from a 13-case subset.

**Accounting:** no stable-event promotion; stable **66/17/49**, outstanding debt **1**, accepted CP2 **491/491**; TB32 **481/500 candidate (19 inherited RED)** remains the last full candidate census; frozen selector497 unchanged. RP-01 open, RP-02 unreached. Exact successor is independent `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY-REV`, with A4 producer DEFN only if independently authorized after review.
