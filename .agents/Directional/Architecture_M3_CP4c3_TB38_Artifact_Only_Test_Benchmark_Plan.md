# M3-CP4c-3-TB38 Artifact-Only Test + Benchmark Plan

**State:** FROZEN / EXECUTABLE NEXT PLAN
**Next turn:** `M3-CP4c-3-TB38-EXEC`
**Boundary:** Test + Benchmark / artifact-only; no configure, compile, relink, regeneration, repair, source/test/fixture/selector mutation
**Benchmarks:** prohibited for this gate; compiled benchmark presence is package evidence only

## 1. Immutable authority

TB38 consumes exactly CB43 package103 and nothing rebuilt from later documentation/control commits.

| Authority | Exact value |
|---|---|
| evidence source | `2fcde465b1de2e42a348d224f5165ce8b87e4fbe` |
| CB43 build run/job | `34167182718 / 101880462158` |
| package artifact ID | `10034608071` |
| package artifact name | `m3-cp4c3-cb43-result-34167182718` |
| provider / ZIP SHA-256 | `426622beb03208d2e6b0cc77479942a92f2aca9967e3bf6251f5034ac533008e` |
| packaged source archive SHA-256 | `1d4c59d8482ffc240f93119ea04e57541930241a73ff3bb8bdd4154f40fe5a28` |
| selector | 409 identities |
| selector409 SHA-256 | `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e` |
| selector408-prefix SHA-256 | `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6` |
| artifact-only harness SHA-256 | `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3` |
| accepted prefix | ordinals 1-365 |

`M3-CP4c-3-TB37` remains current valid semantic runtime authority until TB38 is reviewed: selector409, **402 PASS / 7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`, ownership **300/0/0**.

## 2. Objective

Execute selector409 exactly once from immutable package103 and determine, without changing semantics: accepted-prefix preservation; protected-identity preservation; whether 366/367 advance past `RegionEulerCharacteristicNotOne`; whether every accepted-region `euler_certificate` row satisfies DEFN-R6.7; whether carried 368/369/370/374/398 move; and whether all package/source/execution views remain immutable.

TB38-EXEC preserves raw execution evidence. It does not patch, retry semantic RED, alter stable regression counts, or adjudicate a later-stage frontier. Diagnostics and semantic classification belong to TB38-REV / the required independent review boundary.

## 3. Required execution environment

```text
TURN_ID=M3-CP4c-3-TB38-EXEC
ARTIFACT_ID=10034608071
EXPECTED_ARTIFACT_NAME=m3-cp4c3-cb43-result-34167182718
EXPECTED_PROVIDER_DIGEST=sha256:426622beb03208d2e6b0cc77479942a92f2aca9967e3bf6251f5034ac533008e
EXPECTED_ZIP_SHA256=426622beb03208d2e6b0cc77479942a92f2aca9967e3bf6251f5034ac533008e
EXPECTED_SOURCE_SHA=2fcde465b1de2e42a348d224f5165ce8b87e4fbe
SELECTOR_RELATIVE_PATH=.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt
EXPECTED_SELECTOR_COUNT=409
EXPECTED_SELECTOR_SHA256=eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e
ACCEPTED_PREFIX_COUNT=365
```

After preflight, execute exactly:

```bash
bash .agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh --execute
```

The packaged harness, selector, fixtures, and binaries are authority. Do not run generated discovery/list/help commands.

## 4. Fail-closed preflight

Before the first Directional process starts, prove:

1. artifact ID/name/provider digest/downloaded ZIP SHA-256 match §1;
2. `metadata/source-commit.txt` equals `2fcde465b1de2e42a348d224f5165ce8b87e4fbe`;
3. root `SHA256SUMS` verifies **28/28 PASS** and excludes itself;
4. command boundary is `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`;
5. GMP evidence contains GMPXX and GMP linkage;
6. all eight compiled targets are present and six runtime executables retain packaged hashes/mode `0755`;
7. selector409 count/hash, selector408-prefix hash, and harness hash match §1;
8. packaged `tests/FieldAlignedCurveNetworkTests.cpp` SHA-256 is `913752b8e869b310e2bcb4d0b81a06c4231acdf0470db4427952958de7b3583b`;
9. pre/post package, source-view, and execution-view byte+mode censuses are established;
10. every selector identity maps to exactly one fresh process; zero selection is orchestration failure.

No configure, compile, relink, generated discovery, repair, chmod fix, package rewrite, source checkout mutation, fixture mutation, selector rewrite, or reusable-workflow mutation is permitted.

## 5. Execution contract

Run all 409 identities in selector order, one identity per fresh process, accepted **1-365 first**. Preserve raw stdout/stderr/exit code, complete ledger, identity map, resource accounting, failure-detail digests, ownership census, retired-code checks, `euler_certificate` records, and pre/post censuses.

Do not retry semantic RED. Do not partition/stitch the gate to evade elapsed runtime. Timeout or zero selection is orchestration failure. Do not execute `directional_benchmarks`.

## 6. Accepted-prefix and protected-identity hard gate

Hard stops: accepted **1-365 = 365/365 PASS**, ordinal **312 PASS**, ordinal **409 PASS**. Also preserve 390/393/404/406/407/408. Any accepted loss or 312/409 RED is semantic regression: preserve evidence and stop at review.

Retired `TraceArcDoesNotSeparateItsSides` and `UncutFaceComponentOrbitSeedNotUnique` remain absent. Where published, certified ownership remains **300 established / 0 unavailable / 0 conflicting** unless raw evidence proves otherwise; movement is review-owned.

## 7. DEFN-R6.7 per-region proof obligation

Collect every `M3_CP4AB_FRAGMENT_DIAG record=euler_certificate` line. For **every emitted region on accepted ordinals 1-365**, parse `X`, `E_one`, `B_int`, `fullMinusReduced`, `V_int`, `E_int`, `V_total`, `E_total`, `F`, `chiReduced`, `chiFull` and verify row-by-row:

```text
chiReduced == V_int - E_int + F
chiFull == V_total - E_total + F
fullMinusReduced == chiFull - chiReduced
fullMinusReduced == X - E_one - B_int
```

Classify each accepted-region row:

- `fullMinusReduced == 0`: reduced/full equivalence holds;
- nonzero difference with selector identity still PASS: record exact difference and **unchanged accepted verdict**; this discharges R6.7 without the forbidden blanket "no slits" assumption;
- arithmetic mismatch or accepted verdict change: preserve fields and stop at review.

The result artifact must contain a machine-readable per-region table keyed by selector ordinal plus region/orbit identity where available, with all four checks and discharge classification.

## 8. Decisive correction evidence — 366 and 367

TB37 measured:

```text
X=36
E_one=20
B_int=12
V_total=136
E_total=385
F=250
chiReduced=-3
chiFull=1
fullMinusReduced=4
```

Verify the emitted row against those values, or preserve exact new values if a different authoritative region is reached.

When the full row still has `chiFull=1`, `RegionEulerCharacteristicNotOne` must **not** remain terminal:

- **PASS:** correction removes Euler rejection and no later gate rejects;
- **later-stage RED:** correction is effective; the first later failure is a **new frontier**, not a CB43 regression;
- **still Euler RED with `chiFull=1`:** implementation/definition disagreement; stop at review;
- **`chiFull != 1`:** runtime source-submesh measurement differs from TB37; preserve all fields and stop at review.

Do not force 366/367 to PASS or weaken a later validator.

## 9. Separately owned carried RED surfaces

Ordinals **368, 369, 370, 374, 398** are outside CB43 ownership. Record complete before/after detail against TB37. Unchanged surfaces carry existing ownership; movement to another failure or PASS is review-required and is not automatically owned by CB43.

## 10. Required result evidence

Make `312, 366, 367, 368, 369, 370, 374, 390, 393, 398, 404, 406, 407, 408, 409` directly inspectable. Preserve complete 409-row ledger/identity map, exact PASS/RED lists, process/timeout/resource accounting, accepted-region certificate table, 366/367 rows and terminal details, failure-detail digest table, ownership/retired-code checks, all pre/post censuses, exact run/job/source/artifact IDs/digests, and explicit no-build/no-benchmark/no-mutation evidence.

## 11. Stop and next-state rules

- orchestration failure: no semantic ledger; preserve invalid-attempt provenance and route only control-plane correction;
- accepted loss, 312/409 RED, arithmetic mismatch, or 366/367 still Euler-RED with `chiFull=1`: preserve evidence and stop;
- later-stage 366/367 RED or carried RED: preserve raw evidence and stop at TB38-REV / independent review;
- all green: preserve green evidence; TB38-REV still performs the requested execution-log review before later implementation work;
- benchmarks: never run `directional_benchmarks`.

TB38-EXEC makes **no stable event/recurrence repricing**. Semantic classification and tracker changes belong to the review half of the split TB turn.

**`M3-CP4c-3-TB38-EXEC` is the single exact next execution turn.**
