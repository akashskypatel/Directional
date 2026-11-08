# TB87 Review — canonical route orientation versus observed A3 interval

**Turn:** `M6-CP3-TB87-P13-A3-RECORDED-BOUNDARY-INTERVALS-FULL-GATE-REV` · 2026-11-08 · independent static Review, no runtime or build.

## Verdict and immutable evidence

**Oracle-frame defect in GUARD 910; no production defect established by the reported mismatch.** The test compares `CanonicalRoute::steps().front().orientation()` (lexicographically canonical storage) to `sharedBoundaryInterval.orientation` (observed physical-rim traversal). Those are different frames. The single-step canonical Boundary route is reversed by canonical minimization when its observed orientation is Forward; the resulting canonical Reverse value is not evidence that the producer emitted a wrong interval.

- Immutable product: CB104 source `b41fbf72a4d4d2255b4b0e94e0148de8378e2364`, eight-target GMP compile run `42484665857`, package `13619640763`.
- Gate [42488019698](https://github.com/akashskypatel/Directional/actions/runs/42488019698), artifact `13620204214`: outer SHA256 `f3fcd27fa87151933f8a41c6487ea6a6cd453f5a91fe7a246eb97fa9983f9925`; verified **1,828/1,828** internal hashes. Gate 909 PASS, 1 RED, 910 executed, membership 991. Raw `910.log` contains 64 failures at 32 edge indices repeated identically for the two face-row orders: `0,4,8,12,128,132,136,140,141,157,173,189,205,221,237,253,256,260,264,268,384,388,392,396,397,413,429,445,461,477,493,509`. Every observed comparison is stored route Reverse (-1) versus interval Forward (+1). Both row orders hit the same mismatch class. No missing/skipped/abnormal control can explain it.
- Census [42488045371](https://github.com/akashskypatel/Directional/actions/runs/42488045371) 1 PASS/2 registered RED, 9/9 hashes. All 7 platform and 7 A3 digest lines remain byte-identical to TB86. It is not evidence for accepting GUARD 910.
- Verified source snapshot artifact `13620151862` (outer `18cd18bf91709c9b0aee281ebb5ed25cd64bdd87c7b617b64d1e0f5772df78b0`; 6,255/6,255 hashes) and current control-plane snapshot artifact `13621539326` (outer `e9665b1fe059a79278a29e70e3d29ac36360d201290527f40fd146e00fa042a9`; 6,257/6,257 hashes); current snapshot event `d8b42b00598f4a39a6419012979c75c053a4a40a`. Neither snapshot alters immutable CB104 semantics.

## Independent source re-derivation

1. `src/authority/AuthorityKernel.cpp:81–99`: `from_observed_steps` chooses the lexicographically smaller of the observed sequence and its reversal. Reversal calls `TransitionStep::reversed()` and flips its orientation. Therefore `steps()` is a *canonical unordered-route representation*, and it cannot certify observed signed traversal. `oriented_steps()` returns the forward observed sequence (reversing canonical storage when required). `composed_transport()` already uses it.
2. `src/geometry/SurfaceCellTracing.cpp` in `assign_open_front_boundary_authority`: the Boundary step orientation is constructed from traversal on the physical source edge. The curved-disk rim interval records the corresponding A3 ordinal travel direction. Its span, carrier, and source edge are checked separately in GUARD 910.
3. `tests/SurfaceCellsPhase10Tests.cpp:7441–7445`: the guard checks `edge.route.steps().size()==1` and reads `edge.route.steps().front()`, then equates its *canonical* orientation with the *observed* interval orientation. This is the exact incorrect observation. The 64 logged mismatches are consistent with it. They do not isolate any producer error; no counterexample to the producer's own traversal sign was observed.
4. `CanonicalRoute::oriented_steps()` is the type-owned, existing accessor for the correct frame. This is not a direction-agnostic weakening; it compares the recorded interval to the route's observed Boundary orientation while still checking physical carrier identity and one-step shape. The test's independent A3 count, coverage, source boundary/exterior/no-twin, ordinal and tamper assertions remain unchanged.

## Exact corrective implementation and falsifiers

**Frozen successor:** `M6-CP3-CB105-P13-A3-OBSERVED-ROUTE-ORIENTATION-ORACLE` (one test-only edit, compile/package only, GMP/GMPXX, no execution). Apply [the exact approved patch](Architecture_M6_CP3_TB87_REV_P13_A3_Observed_Route_Oracle_Exact.diff) against source authority `b41fbf72a4d4d2255b4b0e94e0148de8378e2364` (source-semantic files unchanged by TB87). Full SHA256 of patch `9e9635aea3245ee298906101f873db6427d9bf08d9842614f4b75ff027e801a8`; test preimage `7f70db2393f4f439b907d26497e5e9366c623a448887960d80556e47c4d74695`, postimage `a43eb329e874cbeb527d13c8dbc5c879bea638e422b08452f4402f236a4c52f4`.

Change only the route observation to:

```cpp
const auto observedSteps = edge.route.oriented_steps();
ASSERT_EQ(1U, observedSteps.size()) << index;
const auto &step = observedSteps.front();
```

**Subsequent immutable Test + Benchmark:** `M6-CP3-TB88-P13-A3-OBSERVED-ROUTE-ORIENTATION-FULL-GATE-EXEC`. Reuse frozen TB87 910-row gate manifest SHA256 `c435519f6304fdcedb794e45187c8c4645e0bb36d32ec567e7979d292fb245bf`, membership 991, ledger v5 81; execute all cases from the new immutable CB105 package (no rebuild). Require 910/910, all rim comparisons in both face-row orders, positive GUARD 909, 910, and all four existing test tamper checks (dropped interval coverage; stretched span; flipped ordinal sign; interior rim invalid), all 7/7 platform and 7/7 A3 lines byte-identical to TB86. Census must remain exactly registered Cylinder PASS, BunnyRandom P13-e RED, Vase legacy-completion RED. Any mismatch → separate independent Review, never relax or silently rebaseline. No compiled/test result is claimed here.

**Limits:** A3 source-rim interval factory does not prove A3 source attachment (D9c → step 65). Uniform and annulus A3 consumption D4 → step 64A; D7/D5 → step 64. The original RA-215 oracle's *frame comparison* is withdrawn; its substantive coverage, conservation, and row-invariance obligations are retained. A compile-successful CB105 is not acceptance. D6 proposed Vase expected D1 remains pending user decision.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector added or accepted; TB87 membership 991 and accepted CP2 491/491 remain frozen. Historical prefix bytes not freshly re-hashed here. |
| Decisive claims independently re-derived | Gate ZIP+1,828 internal hashes; repeated 32-index tuple across both face-row orders; exact `CanonicalRoute` reversal/observed accessor; test predicate and A3 producer signs. |
| Non-vacuity checked | Original comparison fails on 64 observations; corrected comparison retains observed sign and complete source-carrier/coverage/tamper checks. Actual corrected runtime pending TB88. |
| Prior obligations discharged/carried | TB87 guard attribution discharged as oracle-frame mistake; RA-215 substantive D9 rim pending TB88; D9c→65, D4→64A, D7/D5→64, D6 user decision pending, P13-e/O30b/O31/O32b–e/O33/O27–29 carried. |
| Stable accounting | No accepted-green regression: CP2 491/491, 66/17/49, debt 1, ledger v5 81, selector497/CP3 unpromoted. |
| New candidates/obligations recorded | GUARD 910 test-oracle candidate; independent patch verification and execution assigned CB105/TB88. |
| ORIENTATION currency line | Updated to TB87-REV and its reviewed result. |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7 updated in place; §4 n/a (fixture state not changed); §8 canonical-versus-observed-frame failure pattern referenced. |
| CHANGELOG | TB87-REV entry prepended. |
| ROADMAP | n/a: M6-CP3 remains active, no milestone exit or status change. |
| Selector manifest | n/a: no selector mutation or promotion. |
| LESSONS | Existing lesson on conflated authority / independent oracle retained; new non-vacuous instance documented here. |
| Consolidation under CLEAN_UP_POLICY | Original TB87 report retained as immutable primary evidence; no safe superseded historical record deleted. |
| Successor frozen | CB105 exact one-test patch above, followed separately by TB88 artifact-only falsifiers above. |
| Turn boundary held | Review-only: no product, test, fixture, selector, benchmark or build source changed; no generated Directional runtime executed. |
| review_check.py boundary | **PASS** on authentic Git history: [static run 42494441417](https://github.com/akashskypatel/Directional/actions/runs/42494441417), 6,257 source snapshot files previously verified; zero product/test/fixture/build/selector mutations, all 39 selector hashes match committed blobs, durable rewrite headings retained; ledgers check also PASS (append-only since `8b7299b43`). Log artifact `13623006637`, ZIP SHA256 `53c2edd7ef243970abd4a6ceb52e7b9f584a2d7a246f2f7a011179521c5a338c`. |
| `STATUS` lifecycle maintained | Entry beacon published with original UTC Start; final beacon to be published as final repository mutation only after patch/docs application and closeout. |
| Pushed to origin, branch in sync | [Drive apply run 42494152760](https://github.com/akashskypatel/Directional/actions/runs/42494152760) pushed commit `7c9f4c79d75760dfda8cb0f31cca04c91300d328`; branch head read via GitHub before closing. A local `git status -sb` confirmation is unavailable in ChatGPT Web; no fabricated local result is claimed. |
