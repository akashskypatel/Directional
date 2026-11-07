# M6-CP3-TB19 Factory Rejection-Site Harvest Report (2026-10-20)

**Turn:** `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (harvest-only closeout). **Authority:** RA-107.3 as amended by RA-108.3–108.4. No new runtime or dispatch occurred.

## Immutable evidence and verification

- GitHub Actions run: [39464430751](https://github.com/akashskypatel/Directional/actions/runs/39464430751); result artifact: `12285225197`, expires `2026-11-03T17:19:06Z`.
- Downloaded ZIP SHA-256: `2b5dfacf79e068cad8e28af5c840668c3f26287a2a473fade63924d12d77dec0`, independently recalculated and equal to provider digest.
- Immutable package: `12275794192`; semantic source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`.
- `SHA256SUMS`: **26/26 verified**. Raw log ↔ ledger hashes: **22/22 verified**.
- Boundary manifest: planned `22`, executed `22`, RED `19`, missing `0`, postflight `true`, exit `0`. Every row selected exactly one gtest.
- GMP and GMPXX were linked. `package=true source=true execution_view=true frozen_selectors=true`; `compile=false relink=false benchmarks=false selector497=false`.
- **RA-108 validity:** 16 rows valid (#2, #3, #5, #10–#22); 6 torus rows (#1, #4, #6–#9) **NOT MEASURED — fixture staging (RA-108.2)**, despite their literal gtest `RED` and exit 1.
- Valid observations: `cp3entry:2/6` and `focused30:12` all reject at `product=0`, `site=gauge-pin-consistency;edge=1,4`; 10 M1 failures unchanged under RA-107.2 line mapping per RA-108; controls 3/3 PASS.

## Full 22-row ledger

Raw-log hashes below are independently checked against `raw/<index>.log`. `—` indicates a field not streamed. For `focused30:12`, the harness ledger omits the factory fields; `product=0` and the rejection site are extracted from the first-failure assertion and detail is `not streamed`. The first-failure column reproduces the harness-captured failure, including its mapped line numbers.

| # | Group | Identity | TB18 | TB19 observed | First failure (RA-107.2 mapped) | Product | Detail | Site | Raw SHA-256 |
|---:|---|---|---|---|---|---|---|---|---|
| 1 | M2 | cp3entry:1 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 99fa232f0a6783b2679e70e3f8f9da5361918c8f7a6dc755100b52ad42a990eb |
| 2 | M2 | cp3entry:2 | RED | RED | unknown file: Failure \| C++ exception with description "non-constant internal-midline hard-rail rectangle producer failed: PublishedProductRejected product=0 detail=none site=gauge-pin-consistency;edge=1,4" thrown in the test body. | 0 | none | gauge-pin-consistency;edge=1,4 | d4558ec2316ad952e99a88d50a01b6a81c93cf789ee43e7e561782b8ff191cc3 |
| 3 | M2 | cp3entry:6 | RED | RED | unknown file: Failure \| C++ exception with description "non-constant internal-midline hard-rail rectangle producer failed: PublishedProductRejected product=0 detail=none site=gauge-pin-consistency;edge=1,4" thrown in the test body. | 0 | none | gauge-pin-consistency;edge=1,4 | 5fc4d9634e06484a422e79c2aecca747eab34e6194d7a2e51afcd61b423952a1 |
| 4 | M2 | focused30:6 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 8aa450024489093331b7591ac6f84423c4811e43fc80d98403195d0f706c18f3 |
| 5 | M2 | focused30:12 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:5036: Failure \| Expected: (relabelledFront) != (nullptr), actual: NULL vs (nullptr) \| product=0 site=gauge-pin-consistency;edge=1,4 | 0 | not streamed | gauge-pin-consistency;edge=1,4 | 90dee9731373e98ed41db42ce0e1a3ed2a7db350f05d76ab5bdb43a584fa693f |
| 6 | M2 | focused30:20 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 5c542ddec1f3d995c05dc5013048a5a0f16eac75d0a120495155793a3aabd67b |
| 7 | M2 | focused30:24 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 236f2e6112ed0daebbc3641afdc743ad5560092e46e457eaac8bc08d50bb6d92 |
| 8 | M2 | selector:446 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 0c468214c2404ae03dfc72ecc0de837aac7ade9269c62d3cc98989e2367fd6c8 |
| 9 | M2 | selector:447 | RED | NOT MEASURED — fixture staging (RA-108.2) | unknown file: Failure \| C++ exception with description "Directional test-data package not found adjacent to test executable: /home/runner/work/_temp/M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE/view/bin" thrown in the test body. | — | — | — | 660cf171750c0313ebc436cc856fcd051ad9be5aa3d37422c10ef914d2649f51 |
| 10 | M1 | focused30:3 | RED | RED | unknown file: Failure \| C++ exception with description "Malformed phase-front draft rejected at publication." thrown in the test body. | — | — | — | cfbfd88ba21c24579cb0413d38de3daffc03aaee3191ca726217c588ca138899 |
| 11 | M1 | focused30:22 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:5828: Failure \| Expected: (front) != (nullptr), actual: NULL vs (nullptr) | — | — | — | 5d6ea2f2c088d448a29a88ad4b811d5d4013a56369cc09ce53e725482f4d826d |
| 12 | M1 | focused30:23 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:5869: Failure \| Expected: (front) != (nullptr), actual: NULL vs (nullptr) | — | — | — | c4ee2b4ca4352fc998e60ea1c9e671bba383e28d1083df75edab26a1cdac2fac |
| 13 | M1 | selector:139 | RED | RED | unknown file: Failure \| C++ exception with description "Failed to rebuild structurally valid phase-front product." thrown in the test body. | — | — | — | 971c2b0511906f6c7b141de3d0f8966924d2372df986bf6d63918751c3105d0d |
| 14 | M1 | selector:140 | RED | RED | unknown file: Failure \| C++ exception with description "Failed to rebuild structurally valid phase-front product." thrown in the test body. | — | — | — | 4111ca2374322f1380c2bdab530158d74d0407e7a2df775b1186ff00303edeed |
| 15 | M1 | selector:142 | RED | RED | unknown file: Failure \| C++ exception with description "Failed to rebuild structurally valid phase-front product." thrown in the test body. | — | — | — | e5b26fc203bc7a30d75ec60d11b589a9a4bc836b349b7aab104b761160ddbde0 |
| 16 | M1 | selector:211 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:8600: Failure \| Expected equality of these values: \| directional::geometry::SurfacePhaseFrontProductErrorCode:: InvalidOppositeEdge \| Which is: 4-byte object <07-00 00-00> \| error->code \| Which is: 4-byte object <00-00 00-00> | — | — | — | 651bbc7fca05ed778d14d2784cce78cd224909bd2f10861c2636bf13be09aa5e |
| 17 | M1 | selector:219 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:8579: Failure \| Expected equality of these values: \| directional::geometry::SurfacePhaseFrontProductErrorCode:: InvalidOppositeEdge \| Which is: 4-byte object <07-00 00-00> \| error->code \| Which is: 4-byte object <00-00 00-00> | — | — | — | f731e9bd9378e557e2b6ed980d341195e3a5c0d2082857916424432ac7af4c99 |
| 18 | M1 | selector:227 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:9722: Failure \| Expected equality of these values: \| "InvalidHardRailAuthority" \| result.failure \| Which is: "InvalidPhaseFrontProduct" | — | — | — | e0ceb8ed23f2973d6798fa014993ce61e4797f730cfce329e39f6870278713c0 |
| 19 | M1 | selector:230 | RED | RED | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:9702: Failure \| Expected equality of these values: \| "InvalidHardRailAuthority" \| result.failure \| Which is: "InvalidPhaseFrontProduct" | — | — | — | 036ea6d705a7a8d4c116407e8af84b8301eda1d29c3f53cd9780f1481b3e8618 |
| 20 | control | selector:217 | PASS | PASS | — | — | — | — | b19bc49261dce0f3eab7da41182dde262b5c57812d111725dd1128ddd7da89c1 |
| 21 | control | TB18 A#14 | PASS | PASS | — | — | — | — | 1dc0511a439ae5925ddccbf03dab7a5261ec1f31de7d1fe7ea50cb422e393f28 |
| 22 | control | new | — | PASS | — | — | — | — | 13e3963318088fd2da4c97b0d17ca421545bd8188787d8cd3cb4e90f97e84031 |

## Falsifiers and limits (RA-108.3)

- **F1: HELD on the 16 valid rows.** The six torus rows were **NOT MEASURED**.
- **F2: HELD.** No valid `PublishedProductRejected product=0` has an empty site.
- **F3: HELD** for `focused30:12` at edge `(1,4)`; torus rows **NOT MEASURED**.
- **F4: HELD, 10/10.** M1 first failures agree with TB18 after the RA-107.2 TQ mapping (independent adjudication: RA-108.1).
- **RA-103.5 R-route: NOT REACHED.** Gauge pin rejects `cp3entry:2/6` before the endpoint-certificate loop; no endpoint-R inference is made.
- **RA-106.5 non-zero product code: NONE.** No follow-up under this rule.

## Boundary, disposition, and successor

RA-108.2 identifies the staging defect: `view/test-data/benchmarks` was populated rather than the required `view/test-data/benchmarks/fixtures`. An exit status of zero for the harness does not validate the six torus rows. This report does not adjudicate H-pin, rail-carrier/periodic-cut meaning, or the R-route.

**Authorized successor:** `M6-CP3-TB19A-RP01-TORUS-REJECTION-SITE` (seven-row artifact-only torus rerun under RA-108.5, separate turn). Next mandatory Review after TB19A: `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV`. No code, test, selector, fixture, workflow or package changes in this turn.

**Stable accounting unchanged:** 66/17/49, debt 1; CP2 491/491; R3 403/497 rejected; TB18 candidate 448/497; selector 497 frozen; RP-01 open, RP-02 UNREACHED, Gate C suspended.
