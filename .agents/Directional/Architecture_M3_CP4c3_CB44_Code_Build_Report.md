# M3-CP4c-3-CB44 Code + Build Report

**Status:** COMPLETE / COMPILE-GREEN / IMMUTABLE PACKAGE 104 / RUNTIME-FREE
**Canonical turn:** Code + Build
**Evidence source:** `8756cfe983bf7e05209f560d59a522a6b5b0674a`
**Authoritative compile run/job:** `34174521296 / 101901200478`
**Immutable result artifact:** `10036808934` / `m3-cp4c3-cb44-result-34174521296`
**Result ZIP SHA-256:** `8944f1d16c1cab8884e7c39da236df7a3ec5846ae1fc085b8272440c8941b519`
**Persistent compile-log artifact:** `10036809276` / `m3-cp4c3-cb44-log-34174521296`
**Compile-log ZIP SHA-256:** `a1bc7b73b0166b1e18236625982f282f1ced3fd6fe1affaa14eec1876ce18e74`
**Packaged source archive SHA-256:** `5ec4b65a576b081b91f2f487fce9eea9b2188f72bbc969ec124135e8d986cf20`

## 1. Scope and boundary

CB44 implements exactly DA7.1–DA7.5 from the historical TB38 review (DA0–DA7, now resolved through
`M3_CP4c_Consolidated_Record.md`) and prepares DA7.6–DA7.7 for artifact-only TB39. It restores the accepted criterion first, retains and ungates CB43's diagnostic surface, and publishes the third-complex measurements without choosing a new certified complex.

No Directional runtime, test, benchmark, generated discovery/list/help/version command, fuzzer, or produced binary was executed in CB44. **At CB44 closeout**, `M3-CP4c-3-TB37` remained the valid semantic runtime authority pending package104 execution/review; TB39-REV has since promoted package104/TB39.

## 2. Implementation result

### DA7.1 — reduced Euler criterion restored, nothing else promoted

`GlobalTopologyRegionDiscCertificate::eulerCharacteristic` again uses the pre-CB43 reduced value:

```text
V_int - E_int + F
```

The CB43 total source-submesh counts remain published diagnostic/certificate data. CB44 does not choose the reduced, full, or traced/split complex as the final mathematical authority; that decision is explicitly deferred to `DEFN-R7` after TB39 supplies non-vacuous rows from both decisive fixtures.

### DA7.2–DA7.3 — CB43 diagnostics retained and certificate emission ungated

The existing `euler_certificate` row retains `X`, `E_one`, `B_int`, `fullMinusReduced`, `V_int`, `E_int`, `V_total`, `E_total`, `F`, `chiReduced`, and `chiFull`.

Canonical region certification now emits that record independent of `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS`. The later validation/rebuild path suppresses duplicate diagnostic emission, while the old verbose fragment-diagnostic stream remains under its existing gate. TB39 must count emitted rows and fail closed on zero.

### DA7.4 — traced/split evidence published, not certified

Each canonical region row additionally publishes:

- `trace_cut_faces` — region source faces with at least one authoritative trace piece;
- `split_fragments` — the region's existing face-fragment construction count, `F + sum(tracePieceCount)`;
- `fragment_corner_attributions` — corners attributed to the region by the existing `fragmentCorners` owner/corner map;
- `B_int_one_side` — source-interior mandatory/cut barrier edges with exactly one incident face in the region;
- `B_int_both_sides` — source-interior mandatory/cut barrier edges with both incident faces in the region.

`B_int` retains CB43's both-sides meaning and is expected to equal `B_int_both_sides`. No ownership, `fragmentCorners`, trace-piece construction, region partitioning, or topology semantics were changed.

### DA7.5 — `fullMinusReduced` remains universal publication

For every canonical emitted region:

```text
chiReduced = V_int - E_int + F
chiFull = V_total - E_total + F
fullMinusReduced = chiFull - chiReduced
fullMinusReduced = X - E_one - B_int
```

TB39 owns runtime verification of these relationships. CB44 does not claim them from compile evidence.

## 3. Exact semantic source change

Semantic/evidence commit: `8756cfe983bf7e05209f560d59a522a6b5b0674a` (`fix: restore reduced Euler certificate and publish split census`).

The semantic patch changes exactly one production file:

- `src/geometry/GlobalTopologyPlan.cpp` — **66 insertions / 17 deletions**.

No header, test, fixture, selector, benchmark, build-system, reusable-workflow, ownership, region-construction, or `fragmentCorners` semantic edit is part of the patch.

The preserved implementation patch was generated against pre-CB44 source `952186cbf14e8c826b0ad3b489a8d8be52232b04`, passed `git apply --check` and `git diff --check`, and has SHA-256 `aeae17b6c2b1a4ce5d5df07f20bad85624fe0ed453e72983a872f335fe75508f`.

## 4. Compile and immutable package evidence

The first compile-caller attempt, run `34174442452`, failed before jobs started because the caller granted `contents: read` while the observer reusable contains a skipped branch-file job whose static permission ceiling requires `contents: write`. This was a control-plane startup failure: no compile, runtime, or source mutation occurred. The caller was corrected to the already-proven permission union used by CB43; reusable-workflow permissions were not changed.

Authoritative compile run `34174521296` invoked durable `.github/workflows/agent-compile-reusable.yml` against exact semantic source `8756cfe983bf7e05209f560d59a522a6b5b0674a` and completed successfully.

Compile/package contract:

- Release static out-of-tree PRE_TEST;
- `runtimeExecution=false`;
- `turnBoundary=Code+Build-only`;
- `exactArithmeticBackend=GMP`;
- GMPXX and GMP linked;
- preflight exit `0`, build exit `0`;
- final packaged source status empty;
- fixed durable ccache key owned by the reusable workflow.

Approved compile/link-green targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.

Package104 root `SHA256SUMS` verifies **28/28 PASS** and excludes itself.

Frozen packaged authority remains byte-identical:

- selector409: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`, **409 identities**;
- selector408 prefix: `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- artifact-only harness: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- `tests/FieldAlignedCurveNetworkTests.cpp`: `913752b8e869b310e2bcb4d0b81a06c4231acdf0470db4427952958de7b3583b`.

## 5. Accounting and authority after CB44

CB44 creates one new semantic package and no runtime event or recurrence:

- runtime authority **at CB44 closeout**: unchanged at `M3-CP4c-3-TB37`; TB39-REV later promotes TB39/package104;
- TB37: selector409, **402 PASS / 7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`;
- TB38 remains mechanically valid but semantically RED and unpromoted;
- stable accounting remains **46 events / 14 categories / 32 recurrences**;
- produced-witness debt remains **5**;
- semantic M3 package count: **104**;
- package104 artifact: `10036808934`.

No runtime verdict is promoted by this compile.

## 6. DA7.6–DA7.7 closeout and next boundary

Package104 was the immutable execution input for `M3-CP4c-3-TB39-EXEC`. The consumed executable plan is now
resolved through the folded-document index in `M3_CP4c_Consolidated_Record.md`; the resulting current runtime evidence is `Architecture_M3_CP4c3_TB39_EXEC_Report.md`.

TB39 must restore accepted **1–365 = 365/365**, restore 390/393/406/407 to PASS, keep 312/409 PASS and byte-identical, execute selector409 exactly once in fresh processes, and produce a non-empty `euler_certificate` table. It must verify every row's reduced/full arithmetic and publish all new third-complex fields without deciding which complex is authoritative. The separately owned 368/369/370/374/398 surfaces remain carried.

**CB44 terminates here. TB39 runtime is not executed in this turn.**
