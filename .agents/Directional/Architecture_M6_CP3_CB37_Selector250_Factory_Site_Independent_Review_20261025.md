# CB37-REV — independent static selector250 factory-site review (2026-10-25)

**Turn:** `M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE-REV`. **Verdict:** ACCEPT static diagnostic-only CB37 hunk and existing compile package. No source/test/fixture/selector, production or build change in this Review; no runtime execution; no CP3, stable or selector promotion.

## Independent evidence

- Exact GitHub semantic commit `c9d7c80f6d41abdbc2ecd02de7006c7847988df8` has a single changed file, `tests/SurfaceCellsPhase10Tests.cpp`. Its diff at `:3666–3672` changes **only the stream on the existing** `ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced, network.phaseFront.disposition())`: old reason-name stream becomes `curved_disk_factory_rejection_detail(network.phaseFront)`, `" site="`, and null-guarded `rejection()->publishedProductSourceAuthoritySite`. No assertion operand or macro mutation. The helper is defined at `:2630` before the test, includes reason, `publishedProductError`, and `publishedProductSourceAuthorityDetail`, and returns a string. The producer writes all three fields in `src/geometry/SurfaceCellTracing.cpp:13196–13201` when checked product creation fails. The print is evaluated only as a failed assertion message and cannot admit a product.
- Independently downloaded [compile run 40216902065](https://github.com/akashskypatel/Directional/actions/runs/40216902065) artifact `12607777892`; outer ZIP SHA-256 **`fa437659c633de1b5e69dc93b35bcbb65dec84c212a957d005ada58e4dd01b58`**. Verified **28/28** `SHA256SUMS` entries from actual bytes. The nested source tarball identifies exact semantic `c9d7c80f6d41abdbc2ecd02de7006c7847988df8`; the same test-file SHA-256 `8eed19d8153757eaa1ff141a49e95ec63c35232414ee47101bfb30dcd9d98ef4` appears in independent source snapshot and the packaged source. Source status files are all empty.
- Build metadata lists precisely `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`. Preflight/build exit **0/0**; authoritative link command includes `libgmpxx.so` and `libgmp.so`, configured `DIRECTIONAL_ENABLE_GMP=ON`; `runtimeExecution=false`. These are compile evidence, not claims that any binary was run in this Review.
- An independent source-snapshot workflow [40218911335](https://github.com/akashskypatel/Directional/actions/runs/40218911335), SHA `dee5a81d82520b5d5bb47d650dd550cd4625f348`, produced exact `source.tar.gz` digest `64ace384db698395545a25d2e6c624f2f5db3ec8d9e281d61137d36db358afdf` and **5,884/5,884** file hashes. This later snapshot contains only turn control/document updates beyond CB37; the reviewed test file matches the embedded CB37 exact-source package byte for byte.

## Non-vacuity, boundary and acceptance

This change exposes three independent checked-factory diagnostics instead of only the rejection-reason name. It cannot make selector250 PASS: the `ASSERT_EQ` still fails whenever disposition is `Rejected`. The `rejection()` guard avoids dereferencing a null pointer and reports an empty site if none was published. **Only TB39 runtime raw output** can establish the actual rejection sub-site; neither this diagnostic source nor build-green implies a measured owner. The unchanged 497 selector/491 accepted prefix are not re-executed or appended here; no accepted-green loss or regression claim arises from this static Review.

## Exactly one successor — immutable TB39 gate

`M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST` uses the unchanged targeted artifact harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a` and a new frozen **seven-row** manifest `Architecture_M6_CP3_TB39_Selector250_Factory_Site_Harvest_Case_Manifest.tsv` SHA-256 `a304aeebb6bbbaadf17be43c56b080714e2e39fe4e7f8615da126f3f0150cc61`. Rows: selector250 RED, TB36 quarter/half/directed route GUARD x3, and selector193–195 GUARD x3; each identity is unique and is copied unmodified from the independently reviewed TB38 manifest. Exact immutable CB37 artifact and source above, no compile/relink/repair. STOP on any input identity/hash drift, absent/nonterminal/duplicate case, failed GUARD, unexpected selector250 PASS, missing typed site for a site-bearing rejection, or postflight mutation. TB39-REV separately classifies observed 250 site using RA-155.6 code branches (56–66/O1, 0/InvalidSourceAuthority, otherwise typed).

**Carry unchanged:** RA-152.5, O1, O2, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002, DIAG-RETAIN; A/B/C re-homes, remaining candidate RED owners and RP-01, RP-02 gates. Stable **66/17/49**, debt 1; CP2 accepted **491/491**; TB32 **481/500** and TB38 **490/504** reviewed candidates, selector497 frozen and CP3 unpromoted.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Selector449 independently SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; original 491 accepted identities and 497 frozen selector unchanged in reviewed source; no new accepted selector |
| Decisive claims independently re-derived | Exact GitHub single-file commit hunk; helper and factory field producer; 28/28 package and 5,884/5,884 snapshot hashes, exact source-file match, 8 GMP/GMPXX targets, 0/0 compile status |
| Non-vacuity checked | Existing ASSERT_EQ remains rejecting and streams expanded diagnostics only on failure; no runtime result or site ownership claimed |
| Prior obligations discharged/carried | CB37 hunk/compile independent review discharged; RA-155 A/B/C and 250 site measurement carried to TB39, O1/O2 and all listed debt unchanged |
| Stable accounting | 66 / 17 / 49, debt 1; accepted CP2 491/491, TB32 481/500 and TB38 490/504 candidate, selector497 frozen, CP3 open |
| New candidates/obligations recorded | No new regression; TB39 site measurement is RA-155's already-open obligation, assigned to its exact successor; no tracker count change |
| ORIENTATION currency line | Updated to CB37-REV and TB39 successor, 2026-10-25 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 current evidence/next action updated; §4 unchanged fixture membership; §7 stale CB37 owner replaced by TB39; §8 unchanged known defect patterns |
| CHANGELOG | Entry prepended for CB37-REV |
| ROADMAP | CP3 boundary updated without milestone promotion |
| Selector manifest | n/a: accepted selector and frozen 497 unchanged; TB39 is only focused execution manifest |
| LESSONS | Existing non-vacuity, first-site and compile-vs-runtime rules; no new pattern |
| Consolidation under CLEAN_UP_POLICY | No superseded current-authority CB37 evidence folded; source/package record remains necessary through TB39; no unverified historical deletion |
| Successor frozen | Exact TB39 turn and seven-row manifest above, with fail-closed stop conditions |
| Turn boundary held | Static Review only; no product/test/selector/fixture mutation and no binary/test/benchmark execution |
| review_check.py boundary | Local synthetic baseline: code/test/selector boundary and all selector hash checks PASS; 4 ancestry/durable rewrite-baseline checks FAIL because immutable snapshot excludes `.git` history. No authentic-history PASS claimed; later workflow/history check required to clear this limitation |
| `STATUS` lifecycle maintained | Entry/resume beacon set for this Review; final beacon to be written after all repository documentation operations |
| Pushed to origin, branch in sync | Local snapshot has no remote tracking history; require applied-commit/push workflow evidence plus GitHub branch-head readback before final beacon; no local `git status -sb` sync claim |
