# RA-166 — CB47 E3 block resolved: D5 and D2 witnesses re-homed to A4's real representation; E1 defect fixed; exact CB47 patch (2026-10-27)

**Turn:** `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES-REV` (Review).

**Decision:** The CB47 claim is **CONFIRMED**. Its cause is a definition defect, not a producer defect.
- RA-33.5 (10-07) and DEFN-E E3 require an `OrdinaryInterior` side with a nonempty `route`. That is impossible: A5 has forbidden it since 10-04, and A4 never writes one.
- The D2 single-certificate junction (RA-38, RA-59.8–.12) is likewise unreachable under A4's R-endpoint design.
- Both obligations are **re-homed**, not weakened.
- The compiled CB47 E1 commit `dabb0970e` is **defective**: it would have produced an unregistered RED in TB47.
- CB47 resumes with one probe-verified exact patch, then TB47 on manifest v2.

**Basis:** scratch probes (local GMP library build, copies of test bodies at HEAD `764fa4e5d`). These are diagnostic only, never gate authority. No production code changed.

## RA-166.1 Verification (source)

- **A5** `RemeshPipeline.cpp:3643–3650` rejects `OrdinaryInterior` with `!edge.route.empty()` → `InvalidOrdinaryFrontRelation`. This rule has existed since the `993932656` squash (10-04).
- **A4 sets `edge.route` only** in `assign_open_front_boundary_authority` (`SurfaceCellTracing.cpp:12837–13045`).
  - That function requires a non-ordinary segment kind (GenuineSourceBoundary, HardRail or EmbeddedReliefCut) and nonempty steps; PeriodicCut routes are set at `:15243–15244`.
  - An ordinary side's source crossings live in `cell.boundaryPaths[side][k].entryRoute` (`SurfaceCellTracing.h:1226–1229`). A5 validates them at `RemeshPipeline.cpp:3599–3630`.
- **The D5 block was unsatisfiable from inception.** RA-33.5 conflated the boundary route with the crossing route. cp3entry:4 always failed earlier in its body, so the D5 block first executed at TB46 (`:4063`).
- **`junctions` has no consumer.** Only the A4 checked factory (`SCT:8860, 9080`) and output hashing (`RP:2140`) read it. No A5, A6 or A7 code consumes it.

## RA-166.2 Probe evidence (scratch, diagnostic)

- **E3, cp3entry:4**
  - P0 (HEAD) reproduces TB46 `:4063` exactly.
  - The square fixture has 2 source faces, 4 cells and 16 sides, each inside one face. **No ordinary side crosses any source edge.**
  - Census of 8 fixtures (square, split_isolation, overlap, transition_domain, hard_rail, nonconstant_hard_rail, cylinder, torus):
    - **only `transition_domain`** has qualifying OrdinaryFront pairs: 4 pairs with crossings, reciprocal-equal, eligible, and an unrelated live transition;
    - the other 7 have zero entry-route crossings.
  - With the RA-166.4 E3 hunk, **the whole cp3entry:4 test passes**.
- **E2, cp3entry:2**
  - `nonconstant_hard_rail` produces 10 certificates, all single-step. In every fixture the maximum route length is 1 step and there are zero junctions.
  - **Sweep:** `lengthRatio` ∈ {0.17, 0.2, 0.23, 0.29, 0.31, 0.37, 0.45} × vertex 4 at (1,1) or shifted off-lattice to (1,1.13). The result is always **2 R endpoints at vertex 4** and **0 multi-step certificates**.
  - So A4 ends rail sides at interior rail vertices by design (`ccc0b00ab`, 10-19), not by coincidence of the lattice.
  - One exception: ratio 0.29 with no shift fails at the producer with `InvalidFrontBoundaryAuthority` on a legal input. Registered as **O8**.
- **R-adjacency invariant**, both face-row orders:
  - certificates on (1,4) and (4,7) of the same rail both carry R at vertex 4;
  - independent A3 sector paths in the non-hard star of vertex 4 are separated;
  - `compose(B.cross, s0) == compose(s1, A.cross)` **holds** with cross transport 3 (non-identity), and a +1 quarter-turn mutation **breaks** it.
- **E1, 201, `dabb0970e` (compiled, never executed)** fails three times in sequence:
  1. `REPackageTests:793`: exact rational equality on **double** barycentrics. The two sides read 0.19999999999999998 and 0.19999999999999996; both points carry an exact `exactEdgePoint`.
  2. `:932–934`: `authenticatedJunctions > 0`.
  3. `:1024`: the RA-43.1 germ is seeded only from junction sector paths.

  With the RA-166.4 E1-fix hunk, **the whole 201 test passes**.
- **Clean patched file, pin check:** cp3entry:1 `:2916`, cp3entry:2 `:3154` and `focused30:12` `:5581` (shifted +18 by E3) fail at their pins; cp3entry:4 passes. The manifest v2 self-check passes 504 rows, and the harness self-test passes 12/12.

## RA-166.3 Decisions

- **D1 — D5 (amends RA-33.5 and DEFN-E E3).**
  - The carrier source is the filled cell's `boundaryPaths[filledSide]` `entryRoute` steps. The reciprocal side must have an equal multiset of crossed topologies, and `edge.route` must be **empty** on both sides (the A4/A5 contract).
  - Fixture: `transition_domain_fixture()`.
  - The barrier check, the unrelated live carrier and the A4 `open-rail-chain` negative stay unchanged.
  - DEFN-E's added "two A5-reaching negatives" are **withdrawn**: they are not in RA-33.5, and D5's barrier is `SourceChartTransitionGraph`.
- **D2 — R-split is the canonical A4 representation (amends RA-38 and RA-59.8–.12).**
  - For each interior rail vertex v of an open rail, require:
    - exactly two certificates of that rail with R endpoints at v, on its two distinct incident carriers;
    - independent A3 sector paths in the non-hard star of v;
    - commutation `compose(B.cross, s0) == compose(s1, A.cross)`;
    - that a quarter-turn mutation breaks it;
    - that it survives face-row reversal.
  - A stitched-together "two-carrier route" is still forbidden. The A4 junction-certificate code is kept, unwitnessed (**O9**).
- **D3 — E1 correction** (201):
  - exact `exactEdgePoint` equality, with the double reconstruction kept as a 1e-12 cross-check;
  - R-adjacency (exactly 2 carriers per R vertex) replaces the junction counts;
  - the RA-43.1 germ is seeded from R-endpoint `contactPaths` at `railVertex`.

  The old junction loop stays as a validator: it does nothing when there are no junctions.
- **D4 — cp3entry:2 rewrite leaves CB47.** The test body (`:3114–3711`) is built around `junctions`, including tamper, permutation and radial checks. It needs a probe-authored exact patch: Review turn `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH`. Until then it stays RED at its pin.

## RA-166.4 CB47 resume — `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES`

- **Apply exactly** `Architecture_M6_CP3_RA166_CB47_Exact_Test_Patch_20261027.patch` (SHA-256 `2de51be6…24c1`) on HEAD.
  - `git apply --check` passes at `764fa4e5d`.
  - Expected numstat: `26 18 tests/SurfaceCellREPackageTests.cpp` and `24 6 tests/SurfaceCellTransitionQuotientTests.cpp`.
  - No other byte may change.
- **Evidence:** the established eight GMP/GMPXX targets, `runtimeExecution=false`, and a record of at most 25 lines.
- **Outcome:**

  | Observed | Successor |
  |---|---|
  | Compile OK, numstat exact | `M6-CP3-TB47-RP01-FULL-GATE` |
  | The patch does not apply (HEAD drift) | S3 → `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES-REV` |
  | C2 compile error | Not expected (probe-compiled); no in-hunk edits allowed → S2 → same REV |
  | Orchestration failure | `Turn_Cadence.md` rule 5 |

## RA-166.5 TB47 — `M6-CP3-TB47-RP01-FULL-GATE`

- Artifact-only, on the CB47 package.
- Harness: the CB47A harness, unchanged.
- **Manifest v2**, the same file `Architecture_M6_CP3_TB47_Full_Gate_Case_Manifest.tsv`, SHA-256 `488a20b658fc18ddf64addacd9f3150b35b68b067fd37ba7b11346db958d5955`. It supersedes `6f9b3582…`. Only three rows change:
  - row 243 `selector:201`: RED → POSITIVE, PASS, `-`;
  - row 495 `cp3entry:4`: pin → `-` (must pass);
  - row 12 `focused30:12`: pin `:5563` → `:5581`.
- **Prediction: 500 PASS / 4 RED.** The REDs are `focused30:12` `:5581`, `selector:442`, `cp3entry:1` `:2916` and `cp3entry:2` `:3154`. Harness exit 0.

| Observed | Successor |
|---|---|
| 500/4 at the pins | `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review) |
| A pinned RED passes | Same DEFN; it records the pass |
| A GUARD or POSITIVE row fails, or a RED fails at an unregistered site | S4 → `M6-CP3-TB47-RP01-FULL-GATE-REV` |
| Infra, coverage or hash failure | S5 → `M6-CP3-TB47A-ORCH`, then re-run |

## RA-166.6 Findings and rules

- **F6, generalising RA-165 F1.**
  - A Review that authorizes a test oracle must scratch-probe it before freezing the TB prediction. The CB then applies the exact probe-verified hunks.
  - Neither DEFN-E's E2/E3 "investigate in a CB" nor the unexecuted E1 commit met this rule. That cost a BLOCKED CB, and would have cost an S4 TB.
- **F7.** A witness definition must be checked against the producer and consumer invariants of the field it reads. RA-33.5 contradicted an A5 rule that already existed.
- **O8 (carried):** the producer fails with `InvalidFrontBoundaryAuthority` on the legal 3×3 midline at `lengthRatio=0.29`. RP-01 decides the owner.
- **O9 (carried):** the A4 junction-certificate path (`SCT:20400–20610`, factory `:8860, 9080`) has no produced witness and no downstream consumer. RP-01 decides between retiring it and keeping it with synthetic factory negatives.
- **Residual harness constant:** the 174 informational note is hard-coded in `read_cases`. Fold it into the manifest at the next harness change; it does not block.

## RA-166.7 Turn sequence (frozen IDs)

1. `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES` (resume; exact patch) → `M6-CP3-TB47-RP01-FULL-GATE` (predict 500/4).
2. `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review). It absorbs TB47, decides G (442, `focused30:12`, cp3entry:1), and emits probe-verified exact hunks and the TB48 manifest.
3. `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH` (Review, probe-backed). It writes the exact cp3entry:2 rewrite to D2, and disposes of the junction tamper sections per O9.
4. `M6-CP3-CB48-…` (G, named by DEFN-G) → `M6-CP3-CB48E-RP01-E2-RAIL-VERTEX-ADJACENCY` (exact patch) → `M6-CP3-TB48-RP01-FULL-GATE`.
5. `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review) → CB49 → TB49.
6. A green full gate → RP-01 Review (O6, O7, O8, O9).
7. After RP-01: the O2 DEFN, then DIAG-RETAIN.

**Accounting unchanged:**
- Stable 66/17/49, debt 1. CP2 491/491 accepted.
- TB46 re-run 498/6 candidate. Selector497 frozen. RP-01 open.
