# M6 CP3 TB15 — exact interior-endpoint witness harvest (2026-10-18)

**Turn:** `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER`.
**Authority:** RA-96.5 in `Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`. This is a diagnostic artifact-only TB, not acceptance of CB16, RP-01 or direct production.

- Immutable eight-target compile/package: semantic source `e4785d734e35d2f01ca3ee8099772f6ab5257f4c`, artifact `12150973440`, ZIP SHA-256 `7f56c6a551494ab4e5b9276719946e358ea23bd8b2c5bddec94014796d76c073`.
- TB harness: `.agents/Directional/tools/m6_cp3_tb15_exact_i_endpoint_witness_harness.sh`, SHA-256 `b3aa46de663157e8c3a232dbb39a602ba632104b73eb3d1c9f78cc1deb659317`, committed at `f20bf54c770eee86e3b659235c2ced2aaff9bc43`.
- Dispatcher event `971834454552560658d8b99978e84c26cbd2926d`, [Actions run 39170298228](https://github.com/akashskypatel/Directional/actions/runs/39170298228), result artifact `12152685129`, ZIP SHA-256 `2536c38b958f76cfef6c5e0ef951e902e958d2cdb863e650e2b8b4002a50f748`.
- Nine individual fresh processes, exact-filter selection **9/9**, not selected **0**; harness exit **0**. 28/28 packaged checksums passed, immutable package/source/execution-view postflight passed. GMP and GMPXX compile evidence was present. **No compile, relink, repair, benchmarks, source/test/selector mutation, or 497-selector run** occurred in TB15.

## Observed results (RA-96.5 order)

| Identities | Observation |
|---|---|
| 1–3 | All three new exact source-edge witness tests **PASS**. |
| 4 | `OpenRailRouteChainIntervalTruthTable` **PASS**. |
| 5–6 | Both B2 middle-rail tests **RED** at `endpoint-1`, front `61/179`; `FromExact=none`, `ToExact=none`, binds `0/0`. |
| 7–8 | `cp3entry:2/6` **RED** at `endpoint-1`, front `17/203`; both exact witnesses `1,4@1/5`, binds `1/1`; `chi=3`. |
| 9 | Selector 217 **RED** at the same predicate/front; both exact witnesses `1,4@1/5`, binds `1/1`; `chi=0`. |

`1/5` is strictly interior, equal on both sides, and the producer's observed face-0 conversion is `0x1.9999999999999p-3` (this is not round-to-nearest of mathematical 1/5). The two template-face barycentrics remain asymmetric by one ULP, as previously measured.

**Independent comparison:** remove *only* `a2bProbeFromExact`, `a2bProbeFromExactBinds`, `a2bProbeToExact`, `a2bProbeToExactBinds` from each new first-failure record. Identities 5–8 then compare byte-for-byte equal to TB13A result artifact `12134411966` cases 3–6 respectively; identity 9 compares byte-for-byte equal to the TB14A selector-217 record in artifact `12141843937`. No unexpected earlier predicate change, witness absence/mismatch, or forbidden admission change was observed.

**Disposition:** RA-96.5 predictions held. The five RED cases are already-open RP-01 diagnostics, not new stable regressions. Frozen **66/17/49**, produced-witness debt **1**, CP2 accepted **491/491**, R3 rejected **403/497**, latest census **425/497** remain unchanged. RP-01 open, RP-02 UNREACHED, Gate C suspended. No semantic gate promotion or full-selector acceptance is claimed.

**Mandatory successor:** independent `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER-REV` must re-derive evidence and decide whether to issue the CB16 rule. **Do not automatically dispatch CB16.**
