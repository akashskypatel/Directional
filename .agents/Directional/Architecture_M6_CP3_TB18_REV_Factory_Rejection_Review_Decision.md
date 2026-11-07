# RA-105 — TB18-REV reviewed: measurements confirmed; RA-104 corrected; RP-01 realigned to the checked-factory rejections (2026-10-20)

**Turn:** Review of `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV` (RA-104, `Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Independent_Review_20261020.md`). **Inputs:** TB18 Part A `12231529583`, Part B `12232299548`; CB18 source `3bd24682c` (HEAD `00696aedd` has identical `src/include/tests/CMakeLists.txt`). **S** = `src/geometry/SurfaceCellTracing.cpp`, **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp`, **P10** = `tests/SurfaceCellsPhase10Tests.cpp`, all at HEAD. **Amends:** RA-104 items 2–4 and its successor; RA-103.6 and RA-96.6 (order only).

## RA-105.1 Measurements confirmed

- Review verified both artifacts before RA-104 existed and withheld its numbers. They match the harvest and RA-104 exactly:
  - Part A: 18/18 hashes, 12/14 PASS.
  - Part B: 1019/1019 hashes, 448/497.
  - Against TB16C: 23 RED→PASS, 0 PASS→RED.
  - Classes: B1 = B2 = B3 = U6 = 0.
  - The 30 former B2 identities are 16 PASS and 14 RED.

  TB18 is accepted as candidate evidence only.
- Part A #10 and #11 are `cp3entry:2` and `cp3entry:6`. Part A has eight gates (#1–#7 and #13), not the four RA-104 states; all eight PASS.

## RA-105.2 Corrections to RA-104

1. **Wrong locus.** `PublishedProductRejected` is set at exactly one site, S:13097. It is set when the checked factory `SurfacePhaseFrontProduct::make` (S:13080) rejects state that the A4 consumer has already certified. #10 and #11 are therefore checked-factory rejections of consumer-published products. They are not "producer fixture" exceptions that occur before the factory runs. The RA-103.5 falsifier "factory `InvalidSourceAuthority` on an R-certified route" is **undetermined**: its precondition is demonstrated, but the rejecting clause is not logged (`require_produced`, TQ:426, prints only the reason name).
2. **No separation of mechanisms.** RA-104 left all 49 RED as "other". The 14 former-B2 RED and the 6 torus RED fall under two mechanisms (RA-105.3, RA-105.4); this record proves two of the rejections statically.
3. **Wrong priority.** Every cross-region CP3-entry identity (`cp3entry:1`, `2`, `6`) now ends at the checked factory, and no fixture-debt item touches any of them. RA-96.6 and RA-103.6 (both Review's own) placed fixture debt after TB18 on the assumption that the B2 exit would complete the production path; TB18 falsified that assumption. The selector242 plan stays as fixture debt (RA-105.7). Its qualifier "if supported by actual field-atlas contract" is struck: the oracle stays as written, or the turn STOPs.

## RA-105.3 M1 — the certificate binding shadows frozen precedence (10 identities; static proof)

The identities are `focused30:3, 22, 23` and `selector:139, 140, 142, 211, 219, 227, 230`. Each test edits `route`, `railId` or `oppositeEdge` on one edge of a produced cross-region HardRail pair and leaves `hardRailRouteCertificates` untouched.

- **Proof.**
  - No clause of `make` before S:8756 reads `edges`.
  - S:8766–8775 compares exactly those three fields with the certificate and returns code 0 (`InvalidSourceAuthority`).
  - The raw logs of 211 and 219 show code 0 where the oracle expects 7 (`InvalidOppositeEdge`, S:9242–9249).
  - The other eight print no code. Each fails at the factory's throw or null return, or at the test's `"InvalidPhaseFrontProduct"` mapping (TQ:2345).
- **Origin.** S:8755–8775 arrived with `80fc1688f` (2026-10-08, R2 route τ), after CP2 acceptance. The check stayed hidden because `hard_rail_fixture()` did not produce until CB18.
- **Conflict.**
  - The `M6-CP1-TB6-A6-REV` HardRail amendment (2026-09-29): the reciprocity guard belongs at A5 publication and maps to `InvalidHardRailTransport`.
  - RA-15.2–15.4:
    - malformed routes keep `InvalidHardRailAuthority`;
    - pair failures, including 139 and 142, stay `InvalidHardRailTransport`;
    - route-validity semantics are not duplicated.
  - RA-19 item 1: observable precedence is fixed for 212, 227/230 and 139/140/142.

  No RA amended any of these for certified pairs, so `80fc1688f` is an unreviewed contract change.
- **Disposition.** This is a candidate `VALIDATION_ORDER_SHADOWING` recurrence, owned by production; it is not fixture debt. The binding stays fail-closed. A DEFN after TB19-REV decides who owns it:
  - A4, with amended names; or
  - A5, as the TB6-A6-REV amendment states.

  No M1 oracle changes before that DEFN.

## RA-105.4 M2 — the relational A3 gauge pin over-reaches its domain (hypothesis H-pin)

> **Confirmed by RA-110.3 (2026-10-20):** H-pin holds on both measured edges; the corrected domain is defined by `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN`.

RA-45.3's pin (S:8510–8550) requires `compose(T_A3, g_first) == g_second` on **every** source edge with two incident faces. That includes HardRail carriers and periodic cut edges.

- **`focused30:12` (static proof).**
  - The test adds 1 to the face gauge and to the cell and edge branch rotations of one topology region (TQ:4934–4973). It then requires construction to succeed (TQ:4980).
  - In `hard_rail_fixture()`, the rail edges {1,4} and {4,7} are the only edges joining the two regions, and each has one incident face in each region.
  - The unchanged baseline passes the same pin with the same atlas, so the relabel breaks the pin on those carriers.
  - Nothing in `make` before S:8510 reads branch values: S:8458–8504 cover only the atlas and source binding, presence and range.
- **Torus group (static argument).** The identities are `cp3entry:1`, `focused30:6, 20, 24` and `selector:446, 447`.
  - The witness field (TQ:993–1025) has nonzero Z4 holonomy around the major loop. Around a closed loop, the pin forces the product of the transitions to be the identity, so no face gauge can pass.
  - The first observable changed from `ORGANIC_ODD_TAU_WITNESS_ABSENT` at R3 (`d82e34427`) to `PublishedProductRejected` at CB13A (`e88ac65f`). The pin (`1eaea310f`) landed in that window.
  - `selector:446` was accepted green at CP2.
  - `focused30:24` joins this group: it builds `hard_rail_fixture()` (now produced) and then the torus witness.
- **Contradictions with frozen text.**
  - RA-31a item 1: "the published F is region-relative".
  - RA-33.3: τ is "not a difference of region gauges".
  - RA-34.3 requires a produced witness with `(F_b−F_a) mod 4 ≠ τ_ab`. If the gauge is pinned across carriers, no factory-accepted product can be that witness.
  - Nothing consumes the cross-region gauge difference (RA-45.1).
- **Not yet shown:** which clause rejects `cp3entry:2` and `cp3entry:6`. The pin is a candidate, alongside the R-endpoint clauses (S:8885–8994) and the junction transport (S:9096–9104).

## RA-105.5 Next unit — `M6-CP3-CB19-RP01-FACTORY-REJECTION-SITE` (Code + Build, compile only; rejection-only)

> **RA-106 (2026-10-20):** CB19 failed to compile. The corrected build is `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE` (RA-106.3/106.4/106.6).

1. `include/directional/geometry/SurfaceCellTracing.h`:
   - add `std::string sourceAuthoritySite` as the **last** member of `SurfacePhaseFrontProductError`;
   - add `std::string publishedProductSourceAuthoritySite` as the last member of `SurfacePhaseFrontFailure`.
2. `SurfacePhaseFrontProduct::make` (S:8439–9530): immediately before every `return error;` whose code is `InvalidSourceAuthority`, add one assignment of a site label unique to that return.
   - The label is `<clause>`, followed by:
     - `;edge=<v0>,<v1>` at pin returns;
     - `;certificate=<k>;rail=<id>` inside the certificate loop;
     - `;endpoint=<0|1>;kind=<T|R|I|TR>` inside the endpoint loop;
     - `;junction=<j>` inside the junction loop.
   - **Additive only:** no existing line of `make` changes or moves.
   - The CB record lists every label with its S line.
3. S:13097 block: copy the site into `publishedProductSourceAuthoritySite` (additive).
4. Test reporting only; no assertion or oracle changes:
   - `require_produced` (TQ:426) appends ` product=<int> detail=<int|none> site=<site>` for `PublishedProductRejected`;
   - TQ:4980's `ASSERT_NE` streams the factory code and the site.
5. One new test, in a new suite `SurfaceCellFactoryRejectionSite` that is outside every frozen selector, on `hard_rail_fixture()`:
   - **positive control:** the unmodified draft constructs;
   - **negative:** adding 1 (mod 4) to the gauge of one face that has an intra-region interior edge rejects it with code 0. The site is the pin label, with an edge incident to that face.
6. Build with GMP/GMPXX for the eight targets, `runtimeExecution=false`. **Out of scope:** any change to a condition, an ordering or a code; `RemeshPipeline.cpp`; selectors; harnesses; fixtures.
7. **Review falsifiers (static):**
   - any line inside `make` deleted or modified;
   - a duplicate label;
   - an unlabelled `InvalidSourceAuthority` return;
   - any file outside items 1–5.

## RA-105.6 TB19 — `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (artifact-only, focused, after CB19)

> **Amended by RA-106.5 (2026-10-20):** the empty-site falsifier applies only to `product=0`. TB19 pins the CB19A package.
> **Superseded by RA-107.3 (2026-10-20)** as the TB19 specification: TQ line mapping and the exact 22-row table.

TB19 uses the TB18 Part A harness with the CB19 values and runs 22 identities:
- **M2 (9):** `cp3entry:1, 2, 6`; `focused30:6, 12, 20, 24`; `selector:446, 447`.
- **M1 (10):** the ten identities in RA-105.3.
- **Controls (3):** `selector:217`, Part A #14 and the new test.

**Predictions:**
- every TB18 status is unchanged;
- M1 first failures are byte-identical to TB18, apart from pointer addresses;
- `focused30:12` reports the pin label with a rail-carrier edge;
- the six torus identities report the pin label;
- `cp3entry:2` and `cp3entry:6` report a site; no prediction is made for them.

**Falsifiers:**
- any change of status;
- a `PublishedProductRejected` with an empty site;
- a torus or `focused30:12` site other than the pin;
- the new test RED.

TB19-REV adjudicates every falsifier. TB19-REV also settles the RA-103.5 falsifier: an R-endpoint label on `cp3entry:2` or `cp3entry:6` fires it.

## RA-105.7 Sequence

> **Amended by RA-110.6 (2026-10-20):** the DEFN is split; the gauge-pin domain (DEFN-P1) comes first and the M1 binding owner follows TB20-REV.

CB19 (site) → TB19 → TB19-REV (mandatory; rules on H-pin and on `cp3entry:2/6`) → DEFN on the gauge-pin domain and the M1 binding owner, as TB19-REV orders → corrective CB/TB → fixture debt → census → RP-01 Review.

- **Fixture debt:** 242, then 174 → 250 → adjacent-sheet → 191 → 442, plus the I/R sites TQ:3017, TQ:3257, TQ:8832, RE:713 and P10:7518.
- `focused30:12` becomes a uniform-relabel debt (RA-45.4) only if Review keeps the pin's present domain.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.
