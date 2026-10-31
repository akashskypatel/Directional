# TB39 — selector250 checked-factory site harvest (2026-10-25)

**Turn:** `M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST`. **Evidence disposition:** seven-case immutable artifact-only execution complete; six required guards PASS, selector250 retains its expected RED. This is **diagnostic evidence only**, not corrected production or CP3/selector acceptance. Next authority is independent `M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST-REV`.

## Immutable identity and execution

- Executor commit `4b3932b3a7e709b04bfbba5747ea361eda682f9c`, separate from CB37 semantic source `c9d7c80f6d41abdbc2ecd02de7006c7847988df8`. CB37 immutable package artifact `12607777892`, ZIP SHA-256 `fa437659c633de1b5e69dc93b35bcbb65dec84c212a957d005ada58e4dd01b58`; internal **28/28** SHA256SUMS verified, GMP/GMPXX/runtime-free compile evidence intact.
- Frozen seven-row manifest `Architecture_M6_CP3_TB39_Selector250_Factory_Site_Harvest_Case_Manifest.tsv`, SHA-256 `a304aeebb6bbbaadf17be43c56b080714e2e39fe4e7f8615da126f3f0150cc61`, no row, expectation, identity, or selector mutation. Unmodified harness `tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`.
- [GitHub Actions run 40221114658](https://github.com/akashskypatel/Directional/actions/runs/40221114658), dispatcher event `0ba72389ab8867e1ea94d30c340eb67a6e79b1ec`. Test workload and both schema-validation jobs succeeded; compile/drive/noop jobs skipped; mailbox `m6-cp3-tb39-selector250-factory-site` on `workflow-mailbox` reports success.
- Result artifact `12609665120`, outer ZIP SHA-256 `10af6fa84e855973e11a9fcd5c9d91e9d4bf13b97662082f658b3ec693271f06`; **17/17** internal result manifest hashes match, **7/7** ledger-to-raw log hashes match. Separate harness log artifact `12609398898`.
- `execution-boundary.json`: planned/executed **7/7**; PASS **6**, expected RED **1**; missing/skipped/duplicate/control_bad/unexpected_pass all **0**; postflight `true`; exit `0`. `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. Seven distinct fresh processes; every GUARD passed, selector250 failed its frozen `Produced` assertion. No binaries executed outside the GitHub test workload.

## Measured selector250 first failure (raw/1.log)

```text
../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:3666: Failure
Expected: SurfaceCellProducerDisposition::Produced
Actual: SurfaceCellProducerDisposition::Rejected
PublishedProductRejected publishedProductError=0 publishedProductSourceAuthorityDetail=6 site=hard-rail-contact-missing
```

- Raw first failure remains the `Produced`-versus-`Rejected` assertion; failure exit is `1` with one complete GoogleTest terminal RED, not a crash, skip, timeout, or fabricated PASS.
- The harness ledger's typed extraction is `site=hard-rail-contact-missing`; the **full raw line** adds `publishedProductError=0` and `publishedProductSourceAuthorityDetail=6`. Preserve all three in Review analysis. Do not infer the responsible owner solely from the numeric code or semantic name.
- Three TB36 controls (quarter-turn, half-turn, directed published route) and selector193/194/195 all PASS. No accepted-green loss is measured on this seven-case vector. This execution did **not** re-run all 497 frozen selector identities or the 504-case TB38 census.

## Gate and continuation

All TB39 harness integrity and expected-outcome checks passed. The observed site discharges the narrow **measurement** obligation, not the independent interpretation/owner assignment. Review must classify the measured site under RA-155.6 against the original factory code and causal evidence (including code 56–66/O1, code 0/`InvalidSourceAuthority`, or other typed owner), decide any follow-on work, and prohibit promoting the inherited 250 RED merely for obtaining a typed site. No code, tests, fixture, accepted selector, harness, package, or stable ledger changed in this TB turn.

Carry stable **66 events / 17 categories / 49 recurrences**, project debt **1**; CP2 **491/491 accepted**; TB32 **481/500 candidate**; TB38 **490/504 reviewed candidate**; selector497 frozen and unpromoted; RP-01 open, RP-02 unreached. The exact next turn is `M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST-REV`.
