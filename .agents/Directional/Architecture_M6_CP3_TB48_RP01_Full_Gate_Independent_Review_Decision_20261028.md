# TB48 RP-01 independent full-gate Review — 2026-10-28

**Turn:** `M6-CP3-TB48-RP01-FULL-GATE-REV`. **Decision:** TB48 is a valid immutable **candidate** gate, **502 PASS / 2 registered RED**, not an accepted-green gate. No CP3 or selector497 promotion. CP2 remains 491/491 accepted; stable 66 events / 17 categories / 49 recurrences and debt 1. The two REDs are not waived or reclassified as PASS.

## Primary evidence independently checked

- Compile source `4c611941f0bee7dc2515755fbd159402463879e2`; package `12834041300`, ZIP SHA-256 `a544b0c6c5756b428c90377ce36b3be6322620af167a6a7db908d7882761fe3d`, internal **28/28**. Package `source-commit.txt` matches; `command-boundary.txt` says `runtimeExecution=false`, `exactArithmeticBackend=GMP`; generated link has `gmpxx` and `gmp` and eight compiled targets.
- TB48 run [40731722985](https://github.com/akashskypatel/Directional/actions/runs/40731722985), runtime job `122969711723` successful, no compile job ran. Result artifact `12836819707`, ZIP SHA-256 `3aa8b6bc597abef4b4eb3e8168243e7854e09aea95f3e73fc4d531a92dc20131`. Independently recomputed **1,014/1,014 distinct internal file hashes**, 504 unique ledger rows, 504 unique identities, **504/504** manifest-to-ledger value joins, 504/504 raw-log SHA-256 joins, 504 individual raw GTests and resource reports. Execution boundary reports 504 executed, 502 passed, 2 red, no missing/skips/duplicates/unexpected pass/control violation, immutable postflight true, and no configure/compile/relink/benchmark.
- Frozen TB48 manifest SHA-256 `a3187d5557d792fe22bfd500e14fb0de8e6e14c06888aa17d18b7144ab5900bb`. Compared to the immutable TB47 manifest `488a20b658fc18ddf64addacd9f3150b35b68b067fd37ba7b11346db958d5955`, exactly four existing rows change: 12 and 484 registered RED → POSITIVE/PASS after documented test-authority re-homes; 492 and 493 retain RED and update their native first-failure pins. All 504 case identities, test names and binaries preserve their order. Historical selector449 SHA `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` matches its immutable repository bytes; the 42 CP1/CP2 plus 449 selector identities remain in order. These are identity-continuity checks; changed RED/POSITIVE expectation bytes are **not** misrepresented as an identical manifest prefix.

## Root cause and negative-oracle assessment

**P-G3 (row 492, `cp3entry:1`): genuine reproducible production defect, non-stable.** The native first failure is `SurfaceCellTransitionQuotientTests.cpp:3027` (`G3 periodic endpoint pairs disagree`); the second in the same test at `:3038` shows A5 rejects the otherwise valid source-level odd-gauge torus. The raw trace contrasts two gauge-conjugated endpoint actions: translation (−30,6) versus (−31,5), and one branch rotation differs. Source inspection of `src/geometry/SurfaceCellTracing.cpp:19088–19123` verifies that a single relation turn is inferred from **From** endpoint carrier gauges and reused for **To** endpoints. `make_periodic_relation_endpoint_state` (`:8194–8218`) applies the relation turn to the reverse-side local branch/coordinates without an independently established To-endpoint gauge conjugation. This is a concrete correction site, not a proof that a particular untested fix is sufficient. **Falsifier:** a corrected source-authenticated A3/A4 producer must yield the same canonical periodic action from both endpoint pairs under an odd source face-gauge relabel; A5/A6 must accept, with reciprocal/inverse, holonomy and negative-tamper guards preserved. Never change this test into an expected failure or strip the gauge oracle.

**E2 (row 493, `cp3entry:2`): incomplete witness/reachability obligation, non-stable.** First failure is `SurfaceCellTransitionQuotientTests.cpp:3183`: the expected **actual A4-produced two-carrier** HardRail `(1,4)->(4,7)` is not in `hardRailRouteCertificates`; the inventory contains multiple single-carrier records, not the required pair. Assertions after `ASSERT_NE` were not reached. No A4/A5 gauge-covariance conclusion can be inferred from this RED. **Falsifier:** a valid production-reachable rail-vertex A3/A4 ingress produces the exact two-carrier certificate with real junction/paired attachments, and the subsequent positive plus appropriate wrong-sign/source tamper assertions actually execute. Owner `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH`; RA-166 D2 is the required oracle contract.

**Stable accounting:** P-G3 is a product defect in an **unpromoted** 504-case gate, not an accepted-green loss. Independent Review policy §2.6 requires accepted-green loss for a stable event; no historical stable recurrence or new category is established. E2 is not an independently witnessed producer regression. Keep **66/17/49, debt 1**. No 504/0 claim, no acceptance of incomplete positive tests.

## Next immutable gate and authorization

`Architecture_M6_CP3_TB49_Full_Gate_Case_Manifest.tsv` is frozen as a **conditional, future** 504-row case specification, SHA-256 `a0e39fa25d707bfc8eabb25ac9e8c494cff8ebf032e2040718b90366d0250ef0`. It has the identical ordered test/binary/identity set as TB48, changes **only rows 492 and 493** from RED to POSITIVE/PASS with no first-failure pin, and therefore predicts 504/0 **only after** the separate G3 and E2 corrective Code + Build turns compile. The manifest is neither a claim that the corrections exist nor authorization to run/rebuild TB49 today; before TB49 execution the independent CB reviews must confirm the test identities still exist in the new package and the manifest remains exact. Test source cannot be edited in this Review.

**Exactly one next turn:** `M6-CP3-DEFN-RP01-G3-PERIODIC-GAUGE-COVARIANCE` (probe-capable DEFN). It must produce a source-proved, falsifier-backed exact A4 correction patch; no production mutation in DEFN. E2 remains a separate explicit dependency before CB49E/TB49. Do **not** authorize CB49 or CB49E until their respective DEFN outputs are independently settled. Carry O1/O2/O6–O12, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4 and G4-B002 unchanged. The ten-fixture direct surface-cell D0 gate remains open.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Selector449 `d4a0d1b7…d6414`; TB47 `488a20b6…5955`; TB48 `a3187d55…00bb`; 504 ordered identities match; exactly four authorized field changes, hence no false byte-identical-manifest claim. |
| Decisive claims independently re-derived | Package 28/28; result 1014/1014; manifest/ledger/log 504/504; raw first failures; A4 source at stated ranges. |
| Non-vacuity checked | G3 odd source-gauge and two inconsistent endpoint actions; E2 fails before downstream assertions, so no false E2 credit. |
| Prior obligations discharged/carried | G1/G2 re-homes confirmed PASS as candidate; P-G3 and E2 open with explicit falsifiers; O1/O2/O6–O12 and G4-B002 carried. |
| Stable accounting | 66/17/49, debt 1, CP2 491/491 accepted; selector497 frozen, CP3 unpromoted. |
| New candidates/obligations recorded | P-G3 non-stable and E2 witness, tracker updated; no new stable number. |
| ORIENTATION currency line | TB48 Review updated. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a (ten-fixture definitions unchanged); §8 existing gauge/witness pattern, no new category. |
| CHANGELOG | One TB48 Review entry added. |
| ROADMAP | CP3 candidate status clarified, not promoted. |
| Selector manifest | n/a: no selector altered or accepted; future TB49 case manifest is separately frozen. |
| LESSONS | Existing evidence/non-vacuity obligations applied; no novel pattern. |
| Consolidation under CLEAN_UP_POLICY | No deletion: TB48 report and RA-167 are live evidence for forthcoming corrective turns; no safe superseded family records identified. |
| Successor frozen | `M6-CP3-DEFN-RP01-G3-PERIODIC-GAUGE-COVARIANCE`; falsifiers specified above. |
| Turn boundary held | Review-only static analysis and immutable evidence checks; no C++ builds/tests, product/test/fixture/selector changes. |
| review_check.py boundary | Requires authentic Git DAG; a tarball without `.git` ancestry cannot certify historical ledgers. Independently re-hashed manifest and evidence; run real DAG checker before final RP-01 closure. |
| `STATUS` lifecycle maintained | Entry status written before review; final beacon written after documentation application. |
| Pushed to origin, branch in sync | Drive apply workflow push and returned exact changed-path/commit evidence must be verified at publication; a tarball has no truthful `git status -sb` against origin. |
