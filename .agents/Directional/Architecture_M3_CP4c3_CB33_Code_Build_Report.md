# M3-CP4c-3-CB33 — Code + Build Report

**Turn:** `M3-CP4c-3-CB33`
**Disposition:** **COMPLETE / ORCHESTRATION CORRECTION INSTALLED / STATIC PREFLIGHT GREEN / NO DIRECTIONAL RUNTIME / NO COMPILE REQUIRED / SEMANTIC AUTHORITY UNCHANGED**
**Scope owner:** CM7 of `Architecture_M3_CP4c3_TB28_Independent_Review_Record.md` (folded into `M3_CP4c_Consolidated_Record.md` at `M3-CP4c-3-TB28-R3-REV`; its frozen correction is restated in `Architecture_M3_CP4c3_TB28_R3_Independent_Review_Record.md` §7)
**Exact successor:** `M3-CP4c-3-TB28-R3-EXEC`, then evidence-only `M3-CP4c-3-TB28-R3-REV`.

## 1. Boundary and authority

CB33 repaired only the artifact-only execution harness. It did **not** change product, test, fixture, benchmark,
build, selector, or reusable-workflow semantics, and it did not apply the separating-arc barrier correction frozen
by the independent review.

The valid semantic runtime authority therefore remains `M3-CP4c-3-TB27-R1`:

- source `eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`;
- package `9961564041`;
- selector406;
- **399 PASS / 7 RED**;
- accepted prefix **365/365**;
- RED `[366,367,368,369,370,374,398]`;
- ledger SHA-256 `8da2002701437c5d0c4a57d613e24195f4f690d1ae4494da1234d58bb9a24da5`.

TB28-R1 run `33990315861` and TB28-R2 run `33990951740` remain invalid-attempt provenance with no semantic credit.
TB28-R2's reported `407 PASS / 0 RED` may not be quoted as a gate or accepted-prefix result.

## 2. Exact source snapshot and work preservation

ChatGPT Web source authority was frozen before implementation at
`b580e2038707f1685876019b0828f0535c17be33`. Durable source-snapshot run `33994314873` produced artifact
`9977585312` (`m3-cp4c-3-cb33-source-33994314873`), GitHub digest
`8bc779d0e14cf36a48b1bcb6c853bb9f10d7e08b7c0a1578f03901020d5cd3d1`; the archive metadata names the same
source SHA and `runtimeExecution=false`.

The coherent harness+plan work unit was preserved before remote orchestration as:

- `Directional__M3-CP4c-3-CB33__base-b580e2038707__work-preservation.patch`;
- patch SHA-256 `136ed1d51febd36ecbcd37eb935a7721ee8ce19f47fd96b18ab6bdc273ff8d04`;
- diff-body SHA-256 `d7597581e2b9cc0fa6447bc72919dea7a1b79a7d23fe35f8934551f36070788a`;
- intended paths exactly the R3 plan and harness.

The identical patch bytes were staged transiently in `My Drive/Directional-CI`, applied by run `33995086043`, and
committed as `75dbc4dbc9caabbbb39471636c0c807b09b2543d`. The service-account path could not trash the owner file, so the
Drive staging object was permanently deleted through the authenticated owner connector after successful push.

## 3. CM7 orchestration correction

CB33 adds `.agents/Directional/tools/m3_cp4c3_tb28_r3_harness.sh` and the executable
`Architecture_M3_CP4c3_TB28_R3_Artifact_Only_Test_Benchmark_Plan.md`.

The harness now enforces all CM7 requirements:

1. **Per-identity binary routing.** It statically parses selector407, `cmake/DirectionalTests.cmake`, and packaged
   `TEST*` declarations and requires exactly one compiled owner per identity. No Directional binary is executed for
   discovery.
2. **Selection proof.** Every runtime row records `selected`; the execution environment sets
   `GTEST_FAIL_IF_NO_TEST_SELECTED=1` and `GTEST_COLOR=no`. PASS requires `selected == 1 && exit == 0`; a zero- or
   multi-selected row is RED and invalidates selection integrity.
3. **Complete ledger/evidence contract.** Execution mode emits all 407 rows with
   `ordinal, identity, binary, exit, selected, result, raw_log`, the ledger/map hashes, RED ordinals, accepted-prefix
   count, per-row raw/resource evidence, three pre/post byte+mode censuses, and required raw-log indexes.
4. **Invalid-attempt provenance.** TB28-R1 and R2 are explicitly retained as orchestration-invalid and
   `semantic_credit=false`.
5. **Artifact immutability.** The harness verifies artifact ID/name/digest, root `SHA256SUMS`, exact packaged source,
   selector hashes/prefixes, GMP compile evidence, executable byte+mode identity, executable-relative fixture layout,
   and pre/post package/source/execution-view censuses.

No product correction was added. Selector bytes 397/401/403/405/406/407 remain untouched.

## 4. Static remote preflight — GREEN

The harness was remotely executed only in `--preflight-only` mode; no generated Directional executable ran.

- trigger/control SHA: `daabd6eb6f9e0228ebf8e0e26e417b607f055103`;
- run/job: **`33995166968 / 101384352855`**;
- result artifact: **`9977824674`**, Actions digest
  `c0394bae2d7bbb7bfe0f88df538feb043e949c747068de4a64488fbe6aa159c3`;
- diagnostic-log artifact: **`9977824834`**, Actions digest
  `09120a6b27353c189c8e274da188a7eeca8afb0563146e4325f022a39ca074ea`.

Preflight proved:

- immutable artifact `9975737868` and ZIP SHA
  `16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec`;
- selector407 = 407 identities and exact frozen prefix chain 365/397/401/403/405/406/407;
- static identity map = **407/407 unique owners**, SHA-256
  `9e726c011f884da55877e6bbca420be530f05325263eddcd86993c1f0a54d3fd`;
- owner distribution: authority-kernel 30, completion 75, producer 261, validation 41;
- six packaged runtime executables recorded with SHA-256, mode **755**, and size; executable table SHA-256
  `e0e862248bdf4089ce97b6419805f46a190b357409f5eee6fdd1f7b913c57c8b`;
- ordinals 366, 367, 368, 369, 370, 374, 398, 404, 406 and 407 all statically route to
  `directional_surface_cell_producer_tests`;
- package/source/execution-view pre/post censuses were byte+mode-identical;
- `runtime_started=false`, `runtime_completed=false`, `preflight_completed=true`,
  `execution_view_verified=true`, `orchestration_failure=false`;
- configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation/
  benchmark flags all remained false.

This is orchestration evidence only. It does not re-prove a single semantic selector row.

## 5. Build disposition

No compile was required or authorized: CB33 changed only the external artifact execution harness and TB plan, while
the semantic package under control is the already compile-green immutable CB32 artifact `9975737868`. Running a
replacement compile would have created a new package/source authority and defeated the control experiment.

No reusable workflow permissions were changed.

## 6. Process note

A small number of connector repository reads occurred before `READ_MODE=snapshot` was explicitly frozen at turn
start. No semantic or durable source mutation occurred during that interval. The turn then switched to the required
snapshot authority and used the exact snapshot for all local source/code inspection and patch generation. This is a
procedural deviation only; the authoritative source and work-preservation checks above remain exact.

## 7. Exact next gate

Run **`M3-CP4c-3-TB28-R3-EXEC`** using
`.agents/Directional/Architecture_M3_CP4c3_TB28_R3_Artifact_Only_Test_Benchmark_Plan.md` and
`.agents/Directional/tools/m3_cp4c3_tb28_r3_harness.sh --execute` against package `9975737868` unchanged.

R3 receives semantic credibility only if ordinals **366, 367, and 398 are RED** with exactly one selected test per
row and all immutability gates green. The EXEC turn preserves raw evidence only. `M3-CP4c-3-TB28-R3-REV` then
reviews that evidence without new runtime work. If any control ordinal is green on the unchanged product, do not
proceed to CB34; replace the harness wholesale with the proven TB23-R1 harness architecture. If the control is
credible, the next implementation turn is CB34 and may implement only the already-frozen separating-arc barrier
rule.

Stable accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3
package count **93**. CP4c-3 remains **OPEN**. PR #8 remains draft and unmerged.
