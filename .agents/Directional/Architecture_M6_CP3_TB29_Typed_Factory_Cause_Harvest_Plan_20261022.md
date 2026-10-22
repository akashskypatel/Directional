# TB29 — targeted artifact-only typed-cause harvest (2026-10-22)

**Canonical successor:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST`. **Boundary:** Test + Benchmark only; separate independent TB29-REV afterward. Authority: RA-136.4 and CB28A independent review; exact compiled semantic source `4473e41e94a35f1bf189fa046e86bac92c7391fb`, immutable compile artifact **12465330920** from [run 39867988763](https://github.com/akashskypatel/Directional/actions/runs/39867988763), SHA-256 `da56650a18f99443abf5f721620bb00fd5701dd1e660741da9aafb924a6dfbf5`, 28/28 package entries. Do not rebuild, reconfigure, relink, regenerate, repair, or change the package.

## Exact targeted identity contract — 44 executions

1. **Four new A7 negatives, source-defined test identities:** `M6CP3.CertifiedSeamRejectsConnectingEvidenceOnUnrelatedSeam`; `M6CP3.CertifiedSeamRejectsMissingCertificate`; `M6CP3.CertifiedSeamSharedNodeRequiresSameLatticeCoordinate`; `M6CP3.CertifiedSeamRejectsSpanBindingWithdrawnFromEndpointWedge`. Require each to pass by reaching its specified A7 site; a PASS from an earlier unrelated failure is not accepted.
2. **Two source-produced positive controls:** frozen `cp3entry:3` (D3) and `cp3entry:5` (D7), with their original identity and exact owning executable.
3. **Three existing A7 site-guard controls:** `M6CP2.A7WedgeTransitionWrongRegionRejects`, `M6CP2.A7WedgeTransitionTouchWithoutConnectivityRejects`, `M6CP2.A7ThreeSheetPartialConnectivityRejects`; before dispatch, establish against the immutable prior guard list that these are the intended three; stop for Review rather than substitute different identities if that cannot be proved.
4. **All 35 inherited TB28 RED rows, without omissions, duplicates or substitutions:** take their exact `phase`, `ordinal`, `identity` and `owner` from `.agents/Directional/Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv` (35 data rows; source SHA-256 `66c0ba377c834a969d481cf1ee2253688fa12b7686a0ced6d9da9695e01eb3da`). This includes `focused30:12,22,23`, the full factory, A3, A5, producer/oracle and D2 groups. Use the exact frozen mapping rather than regenerating case ordinals.

The harness must enumerate exactly **44 distinct test identities**, resolve each to an already packaged binary, and reject any name collision, nonexistent test, skipped case or execution beyond this whitelist. Construct one bounded artifact-only harness under `.agents/Directional/tools/`, checked and hashed in its separate Code + Build authorization **only if** the current TB boundary permits harness preparation; otherwise stop and request the prescribed predecessor authorization. Use the durable `test_benchmark` dispatcher with an exact harness SHA-256 and immutable package. No locally executed Directional binaries.

## Outputs and independent checks

- For all 44: original phase/ordinal, exact test name, binary, single `[ RUN ]`, verdict, exit code, raw log SHA-256, first failure and authentic error/site; no synthetic PASS, suppression, retry after start, or assertion changes.
- Four A7 negatives: compare the reached first failure/site to each preserved oracle expectation, inspect D3/D7 positive preconditions, and report false guards separately.
- Each of the **35 REDs**: extract the typed factory `code`, `sourceAuthoritySite`, relevant carriers, typed A3 atlas code/locus, or typed A5 code/site, or explicitly `reason-not-observed`. Categorize by **first observed failing condition**, not test topic; prove category counts sum to 35 and that all identities are disjoint.
- Preserve prior 462/497 TB28 as **candidate** until a separate census Review authorizes promotion; TB29's targeted run is not an accepted 497/497 replay. Stable 66/17/49, debt 1, CP2 491/491; RP-01 open, RP-02 unreached, Gate C suspended.
- Verify immutable ZIP and internal manifests before and after; certify `compile_execution=false`, `relink_execution=false`, `configure_execution=false`, `benchmark_execution=false`, `package_repair=false`, `source_test_fixture_selector_mutation=false`, `retry_after_runtime_start=false`.

**Falsifiers and stop rules:** any missing/duplicate identity, mismatched binary, unverified source/package/harness SHA, unexpected A7 site, control failure, absent diagnostic reason where the expected new assertion was reached, altered test logic, or a required compiler/rebuild action. Retain raw evidence and return to the independent TB29-REV; do not silently change predicates, names, fixtures, package, selector or production code.

**Next:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV` only after an immutable complete TB29 report exists; that Review decides DEFN-M1 and D2/fixture-debt disposition from observed clauses, not prior assumptions.
