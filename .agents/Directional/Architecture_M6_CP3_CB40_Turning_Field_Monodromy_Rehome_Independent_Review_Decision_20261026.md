# CB40 independent review — selector 192/247 turning-field monodromy (2026-10-26)

**Canonical turn:** `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME-REV`  
**Disposition:** APPROVED — independent static Review of CB40 selectors192/247 and immutable compile source, with genuine Git history checks PASS. No runtime acceptance.

## Authority independently inspected

- Exact semantic source commit `0d227875d8f031a467e661be2da4dd901846797c`; 7-commit GitHub compare from `f262f153e8acc87c6c76e0e34d08841792ab5735` changes only `tests/SurfaceCellsPhase10Tests.cpp` on the implementation/test surface (+37/−12, plus an Eigen assertion compile correction +2/−2 on the final semantic commit). Other changes are request and STATUS control files.
- Compile run [40264202131](https://github.com/akashskypatel/Directional/actions/runs/40264202131); artifact `12625069994`; independent downloaded ZIP SHA-256 `0f5e554b975bd1306df587f7bb0031707136f2a629fb550beab61e02301e3d41`. All **28/28** manifest entries verified, packaged source matches the exact reviewed file, eight targets present, GMP/GMPXX linked with `DIRECTIONAL_ENABLE_GMP=ON`, compile/preflight exit `0/0`, clean source package, `runtimeExecution=false`.
- Current whole-source snapshot: commit `08bb7921dfe3e059066923ddc1d0a1dcdfc983e8`, run `40267335096`, artifact `12626459653`, ZIP SHA-256 `57841b3c82a9abcb67ed9bd7993a9f33fc60e5020d0ed6b972288a8cb66ac333`, source tree **5898/5898** file hashes verified, test source byte-identical to packaged compile source.
- PR #8 was verified open/draft, working branch `agent/surface_cell_quad/p5-recover-bridge-healing`. No source, tests, fixture, selector, build logic or benchmarks were changed or executed during this review.

## Independent source review

1. **Selector 192:** Previously mutated one directed edge matching and reached an A3-invalid cycle. The replacement derives `turning_periodic_route_field(fixture,1)` from the committed cylinder's face geometry/raw arms, asserts zero interior singularity indices, derives observed signed quarter-turn (`+1` or inverse), separately constructs `build_source_topology_regions` and requires `FieldTransportAtlas::make` success. The checked producer then receives the *same turning field* for both field and atlas generation. The unchanged positive balanced-field A4-produced baseline and the negative `Rejected/PeriodicHolonomyMismatch`, no product and typed `-1` locus assertions remain.
2. **Selector 247:** The previous local `transition->matching += 1` mutation was replaced by `turning_periodic_route_field(fixture,2)`. The test independently asserts the loaded mesh vertices, triangle faces and raw-field bytes correspond to the committed cylinder fixture; requires zero singular indices, observed half-turn `2`, and successful `FieldTransportAtlas::make` before injecting its resulting atlas and matching field into the A4 producer. The original A4 rejection reason and empty seeds/traces/proposals remain intact.
3. **Non-vacuity:** A3-invalid local perturbation no longer masquerades as a periodic A4 test. Different `k=1` and `k=2` stimuli explicitly demand different observed monodromy. Both demand atlas construction without error. The expected negative is the specific A4 `PeriodicHolonomyMismatch` rather than any failure; positive baseline is preserved. Tests are still **unexecuted on this artifact**; actual runtime assertion reachability and outcome belong exclusively to TB41.
4. **Compile-only assertion correction:** `Eigen::VectorXi.empty()` did not compile; the final change uses `ASSERT_EQ(0, singularIndices.size())` in two places. This retains the same zero-index requirement; initial failed compile is not erased or presented as a pass.
5. **Scope:** No product implementation/selector/fixture/benchmark code change; no selector497 or CP3 promotion. Accepted CP2 remains 491/491, reviewed TB38 candidate 490/504, stable 66/17/49, debt one, RP-01 open. Carry O1–O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 and TB41 execution ownership.

## Continuation evidence (same review turn; 2026-10-26)

- Prepared and preserved a three-path documentation patch at base `08bb7921dfe3e059066923ddc1d0a1dcdfc983e8`. First Drive apply run `40270071077` failed *after verified patch application to the runner checkout* but **before commit**: the `intended_paths` patch-header metadata used commas while the reusable parses semicolons. No semantic or documentation commit was produced by that failed run.
- Corrected only the patch header; body SHA-256 remained `994c36552ed9bfca7902db18b3c21a25d6f24fba115cccca9b233a72f61c671a`. Corrected full patch SHA-256 `8fed4dd6d8344eea6db30badf31cf75b41ad0b97cdaa5d06fcab1cc33554a296`; successful Drive apply [run 40270355447](https://github.com/akashskypatel/Directional/actions/runs/40270355447) result artifact `12627009986`, output commit [`aaf48a9bd49acbb35ea176a095e90a709b599175`](https://github.com/akashskypatel/Directional/commit/aaf48a9bd49acbb35ea176a095e90a709b599175). Exactly `Future_Chat_Session_Handoff.md`, `ORIENTATION.md`, and `TODO.md` changed. Both staged Drive files were retired by the owner connector.
- Restored the frozen local source snapshot after an unintended **local hardlink-overlay** modification during audit-tree creation, directly from its verified source tar; verified `5898/5898` source-manifest hashes afterward. No remote source mutation occurred.
- `document_drift_audit.py` on the prepared living-document overlay reported zero errors and warnings **when the known remotely committed review decision path was represented in the local mirror**. The first source-only audit had reported three broken links solely because its frozen snapshot predates that review decision. This check does not establish Git-history boundary, human document-drift approval, consolidation, or the currency of the separate `ROADMAP.md` next-turn prose, which still needs correction at formal closeout.

## Authentic history checks — PASS

[Run 40271541658](https://github.com/akashskypatel/Directional/actions/runs/40271541658) source `14cae5bab5701198c35478cd287f28678e964d56`, evidence artifact 12627973672, verified ZIP SHA256 `3c11103bcf2bc0ded9a2d46e8dc92ac4e693fa6eb7990e47575035a969587b6e`: `review_check.py authority`, `boundary`, and `ledgers` each PASS (exit 0), full Git checkout, 39 selector hash matches, no product drift, protected headings intact, historical ledger shrink absent, clean `git status -sb`. No runtime. Earlier Gitless-snapshot failures were inconclusive, not accepted.

[Documentation apply 40272031076](https://github.com/akashskypatel/Directional/actions/runs/40272031076), verified commit `3d97667c29842e0a007303ddbb38ee8951664043` changed only Handoff, ORIENTATION, ROADMAP, TODO and CHANGELOG. Staging Drive file deleted; source/fixture/selector untouched. Local complete-doc-overlay drift audit 0 errors, 0 warnings. Temporary history caller and trigger deleted and absence verified; mailbox retained. CP3 consolidation census: no safely superseded document in CB40-REV selector192/247 scope; CB39/CB40 compile and review evidence still required by TB41; zero documents folded, no unsafe deletion.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no selector added; 39 tracked selector hashes match HEAD in authentic boundary PASS |
| Decisive claims independently re-derived | Verified exact test hunks, raw-field/atlas/A4 dependency and 28/28 package + 5898/5898 snapshot hashes |
| Non-vacuity checked | k=1 and k=2 monodromy, atlas success, specific A4 rejection; runtime reachability not measured |
| Prior obligations discharged/carried | RA-155.3 B, RA-157.4 statically addressed; TB41, O1–O4 and listed carried owners remain |
| Stable accounting | 66/17/49 debt 1; CP2 491/491; TB38 candidate 490/504; selector497 unpromoted |
| New candidates/obligations recorded | None new; existing O1–O4 and TB41 carried unchanged |
| ORIENTATION currency line | Updated to CB40-REV accepted, CB41 next (2026-10-26) |
| ORIENTATION §3 and §7 | §3/§7 updated; §4 n/a no witness change; §8 n/a no recurring semantic defect |
| CHANGELOG | CB40-REV entry added in docs push 40272031076 |
| ROADMAP | Stale CB40-next corrected to CB41; CP3 unchanged |
| Selector manifest | Not modified; no selector accepted or appended |
| LESSONS | Existing non-vacuity / build evidence principles; no new generalizable lesson |
| Consolidation under CLEAN_UP_POLICY | CP3 live-authority census: no safe superseded document; zero folded, no deletion |
| Successor frozen | CB41 test-only, RA-155.3 C; prohibited until this review formally closes |
| Turn boundary held | Yes; static review only, no runtime/product/selector/test change |
| review_check.py boundary | PASS exit 0 in authentic Git run 40271541658; authority and ledgers also PASS |
| STATUS lifecycle maintained | Resumed beacon maintained; final direct COMPLETE beacon will close turn |
| Pushed to origin, branch in sync | Clean git status -sb at history run; later docs push succeeded and exact commit verified on target branch |
