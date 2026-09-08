# M3-CP4c-3-TB39 Artifact-Only Test + Benchmark Plan

**State:** FROZEN / EXECUTABLE NEXT PLAN
**Next turn:** `M3-CP4c-3-TB39-EXEC`
**Boundary:** Test + Benchmark / artifact-only; no configure, compile, relink, regeneration, repair, source/test/fixture/selector mutation
**Benchmarks:** prohibited for this gate; compiled benchmark presence is package evidence only
**Review boundary after EXEC:** `M3-CP4c-3-TB39-REV` — evidence-only independent review; no implementation may follow before that review

## 1. Immutable authority

TB39 consumes exactly CB44 package104 and nothing rebuilt from later documentation/control commits.

| Authority | Exact value |
|---|---|
| evidence source | `8756cfe983bf7e05209f560d59a522a6b5b0674a` |
| CB44 build run/job | `34174521296 / 101901200478` |
| package artifact ID | `10036808934` |
| package artifact name | `m3-cp4c3-cb44-result-34174521296` |
| provider / ZIP SHA-256 | `8944f1d16c1cab8884e7c39da236df7a3ec5846ae1fc085b8272440c8941b519` |
| packaged source archive SHA-256 | `5ec4b65a576b081b91f2f487fce9eea9b2188f72bbc969ec124135e8d986cf20` |
| selector | 409 identities |
| selector409 SHA-256 | `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e` |
| selector408-prefix SHA-256 | `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6` |
| artifact-only harness SHA-256 | `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3` |
| test source SHA-256 | `913752b8e869b310e2bcb4d0b81a06c4231acdf0470db4427952958de7b3583b` |
| accepted prefix | ordinals 1–365 |

`M3-CP4c-3-TB37` remains current valid semantic runtime authority until TB39 is independently reviewed: selector409, **402 PASS / 7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`.

TB38 is reference evidence only: mechanically valid, semantically RED, not promoted, **395 PASS / 14 RED**, accepted **362/365**.

## 2. Objective

Execute selector409 exactly once from immutable package104 and answer only the measurements frozen by DA7:

1. does restoring the reduced criterion restore accepted 1–365 and protected 390/393/406/407;
2. are 312 and 409 still PASS on byte-frozen source;
3. are `euler_certificate` rows non-vacuously emitted for certified regions;
4. do all published reduced/full equations close row by row;
5. what are the third-complex measurements (`trace_cut_faces`, `split_fragments`, `fragment_corner_attributions`, one-side and both-side barrier counts) for every emitted region;
6. what raw frontier do 366/367 reach after the restoration;
7. do separately owned 368/369/370/374/398 remain unchanged.

TB39-EXEC preserves raw execution evidence. It **must not decide which Euler complex is mathematically authoritative**, reprice stable events, patch a RED, or infer a new definition. Those decisions belong to TB39-REV / later `DEFN-R7`.

## 3. Required execution environment

```text
TURN_ID=M3-CP4c-3-TB39-EXEC
ARTIFACT_ID=10036808934
EXPECTED_ARTIFACT_NAME=m3-cp4c3-cb44-result-34174521296
EXPECTED_PROVIDER_DIGEST=sha256:8944f1d16c1cab8884e7c39da236df7a3ec5846ae1fc085b8272440c8941b519
EXPECTED_ZIP_SHA256=8944f1d16c1cab8884e7c39da236df7a3ec5846ae1fc085b8272440c8941b519
EXPECTED_SOURCE_SHA=8756cfe983bf7e05209f560d59a522a6b5b0674a
SELECTOR_RELATIVE_PATH=.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt
EXPECTED_SELECTOR_COUNT=409
EXPECTED_SELECTOR_SHA256=eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e
ACCEPTED_PREFIX_COUNT=365
```

After fail-closed preflight, execute exactly:

```bash
bash .agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh --execute
```

The packaged harness, selector, fixtures, and binaries are authority. Do not run generated discovery/list/help/version commands.

## 4. Fail-closed preflight

Before the first Directional process starts, prove:

1. artifact ID/name/provider digest/downloaded ZIP SHA-256 match §1;
2. `metadata/source-commit.txt` equals `8756cfe983bf7e05209f560d59a522a6b5b0674a`;
3. root `SHA256SUMS` verifies **28/28 PASS** and excludes itself;
4. command boundary is `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`;
5. GMP evidence contains GMPXX and GMP linkage;
6. all eight compiled targets are present and six runtime executables retain packaged hashes/mode `0755`;
7. selector409 count/hash, selector408-prefix hash, harness hash, and packaged test-source hash match §1;
8. pre/post package, source-view, and execution-view byte+mode censuses are established;
9. every selector identity maps to exactly one fresh process; zero selection is orchestration failure;
10. no runtime evidence from the invalid first CB44 caller startup (`34174442452`) is consumed — that run had no jobs and no compile.

No configure, compile, relink, generated discovery, repair, chmod fix, package rewrite, source checkout mutation, fixture mutation, selector rewrite, or reusable-workflow mutation is permitted.

## 5. Execution contract

Run all 409 identities in selector order, one identity per fresh process, accepted **1–365 first**. Preserve raw stdout/stderr/exit code, complete ledger, identity map, resource accounting, failure-detail digests, ownership census, retired-code checks, every `euler_certificate` line, and all pre/post censuses.

Do not retry semantic RED. Do not partition/stitch the gate to evade elapsed runtime. Timeout or zero selection is orchestration failure. Do not execute `directional_benchmarks`.

## 6. Restoration hard gate

Required runtime restoration:

- accepted **1–365 = 365/365 PASS**;
- ordinal **312 PASS**;
- ordinal **409 PASS**;
- protected **390/393/406/407 PASS**;
- preserve 404/408 as previously green;
- selector409, selector408 prefix, harness, and test-source hashes remain byte-frozen.

Any accepted loss or 312/409 RED is semantic regression. Preserve complete evidence and stop at TB39-REV; do not repair in EXEC.

Retired `TraceArcDoesNotSeparateItsSides` and `UncutFaceComponentOrbitSeedNotUnique` remain absent. Where published, certified ownership remains **300 established / 0 unavailable / 0 conflicting** unless raw evidence proves otherwise.

## 7. Non-vacuous `euler_certificate` proof obligation

Collect every line matching:

```text
M3_CP4AB_FRAGMENT_DIAG record=euler_certificate
```

Publish `euler_certificate_row_count` in the result summary and machine-readable evidence.

**Hard failure conditions:**

- global row count is zero;
- any accepted identity that reaches region certification has no row for an actually certified region;
- any verifier reports arithmetic success over an empty table.

For every emitted row, parse at least:

```text
region
X
E_one
B_int
B_int_one_side
B_int_both_sides
fullMinusReduced
V_int
E_int
V_total
E_total
F
chiReduced
chiFull
trace_cut_faces
split_fragments
fragment_corner_attributions
```

Verify row by row:

```text
chiReduced == V_int - E_int + F
chiFull == V_total - E_total + F
fullMinusReduced == chiFull - chiReduced
fullMinusReduced == X - E_one - B_int
B_int == B_int_both_sides
```

The machine-readable table must include selector ordinal, identity, region/orbit identifier when available, every raw field, and one boolean per arithmetic relation. Never collapse rows to only an aggregate PASS.

## 8. Third-complex measurement — publication only

For each row preserve exactly the CB44 third-complex census:

- `trace_cut_faces`;
- `split_fragments`;
- `fragment_corner_attributions`;
- `B_int_one_side`;
- `B_int_both_sides`.

TB39-EXEC must not derive a new Euler characteristic from these fields, must not call one count authoritative, and must not alter `fragmentCorners` semantics.

Two explicit falsifier notes are raw evidence only:

1. if the torus region reports `split_fragments == F`, record that DA7's current fragment-count reading does not distinguish the traced/split complex on that fixture; **do not reinterpret it in EXEC**;
2. if `fullMinusReduced == 0` on every accepted row, record that accepted rows cannot discriminate reduced versus full; **do not choose a complex from that fact**.

Both observations, if present, are handed unchanged to TB39-REV / `DEFN-R7`.

## 9. Decisive fixtures and 366/367

Make the torus and mechanical region rows directly inspectable.

Reference observations from TB38/TB37:

```text
Torus:      X=24, E_one=24, B_int=1, V_total/E_total/F=24/48/24,
            chiReduced=1, chiFull=0, fullMinusReduced=-1.
Mechanical: X=36, E_one=20, B_int=12, V_total/E_total/F=136/385/250,
            chiReduced=-3, chiFull=1, fullMinusReduced=+4.
```

Because CB44 restored the reduced criterion, 356/357/362 and protected 390/393/406/407 are expected to recover. For 366/367, preserve the actual terminal stage and row values. Do not force them to PASS and do not weaken a later validator. Any movement is raw frontier evidence for review.

## 10. Separately owned carried RED surfaces

Ordinals **368, 369, 370, 374, 398** are outside CB44 ownership. Record complete before/after details against TB37. Unchanged surfaces carry existing ownership. Movement to another failure or PASS is review-required and is not automatically owned by CB44.

## 11. Required result evidence

The result artifact must include, at minimum:

- complete 409-row ledger and identity map;
- exact PASS/RED ordinals and accepted-prefix count;
- process, timeout, and resource accounting;
- `euler_certificate_row_count`;
- complete per-region Euler/third-complex TSV or equivalent machine-readable table;
- direct rows/details for `312, 356, 357, 362, 366, 367, 368, 369, 370, 374, 390, 393, 398, 404, 406, 407, 408, 409`;
- failure-detail digest table;
- ownership and retired-code checks;
- package/source/execution pre/post byte+mode censuses;
- exact run/job/source/artifact IDs and digests;
- explicit `no_build=true`, `no_benchmark=true`, and no-mutation evidence.

The persistent workflow log must be uploaded regardless of success or failure.

## 12. Stop and next-state rules

- orchestration failure: no semantic ledger; preserve invalid-attempt provenance and correct only the orchestration mechanism;
- accepted <365/365, protected 390/393/406/407 RED, or 312/409 RED: preserve evidence and stop;
- zero certificate rows or any empty-table arithmetic success: preserve evidence and stop;
- row arithmetic mismatch: preserve the exact row and stop;
- later-stage 366/367 RED or carried RED: preserve raw evidence and stop at review;
- all green: preserve green evidence; **still stop at `M3-CP4c-3-TB39-REV`** before any implementation or definition change;
- benchmarks: never run `directional_benchmarks`.

TB39-EXEC makes **no stable event/recurrence repricing and no definition decision**. Semantic classification, candidate ownership, and any `DEFN-R7` plan belong to the review half of the split TB turn.

**`M3-CP4c-3-TB39-EXEC` is the single exact next execution turn.**
