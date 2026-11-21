# RA-277 — adversarial re-review of TB154 independent Review (2026-11-21 UTC)

## Situation — qualified PASS

**The TB154 971/971 PASS and TB153 comparison remain valid.** No accepted-case loss was found. However, the TB154 Review's claim that row 971 would reject a no-op ray-classification receipt is too strong. The test records actual values but does not assert the full receipt or require every source slide to be observed. Correct that review statement and carry a narrow test-strength obligation. This does not establish production behavior. The next authorized work remains the bounded producer-switch Code + Build turn, not its successor.

## Background — primary and independent evidence

- Exact GitHub snapshot: source commit `98995a1ad087cb40f98d5f7e7e8dc95203f8a4ec`; snapshot run `44883942942`, artifact `14698449287`; archive SHA-256 `eb15c2d09ac553bba98de6b3c490aa558e5b425afc45efd6b3e9ccc4861b8c3a`. This review made no test or source code changes.
- Immutable gate: `14696380156`, ZIP SHA-256 `ce172d892dbf3f52084eaf3a148ec03443bc19c06ec9e5262f89e35c89b648c0`, internal 1950/1950. TB153 baseline: `14692372657`, ZIP SHA-256 `5e102074ae1bbfcf9c1a94a928e8d354725b484c67fa7dc53410d887a12f8147`, internal 1944/1944.
- Immutable census: `14696590265`, ZIP SHA-256 `0dd3b6ea13c1c0b6db4822fe91fd58483990cd7515898e99e780bb3bc19991e6`, internal 9/9. TB151 baseline: `14621727104`, ZIP SHA-256 `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611`, internal 9/9.
- Selector byte prefix independently verified: TB153 145,036 bytes, SHA-256 `fc075b4c33e0f934d8636a4c9c4186d19fea24e5cd6ae88e516c5c6ff1514116`; TB154 145,526 bytes, SHA-256 `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305`. TB154 starts with the exact TB153 bytes; three additional rows 969–971 are required-green. Membership: 971 required and 81 deferred; CP2's 491 remain accepted.

## Assessment — independently checked findings

### A1. Gate preservation supported, no new stable regression

Directly parsed `ledger.tsv` in both gate ZIPs: TB153 contains 968 PASS (958 GUARD + 10 POSITIVE); TB154 contains 971 PASS (961 GUARD + 10 POSITIVE), zero failed. All 968 prior row identities and outcome metadata agree. Their raw SHA-256 fields are identical on 558/968 rows; observed differences in sampled rows 1, 686 and 968 are only elapsed Google Test times. I independently normalized all 968 old raw logs using N1 (elapsed Google Test millisecond values, including `ms total`), N2 (line endings), and N3 (sorted multiset of the exact `region_support_projection` lines). **All 968 match**; exactly 1,750 projection lines occur on each side and no other raw bytes differ after normalization. No out-of-scope text was masked. The first 491 outcome rows remain PASS. The census has the same three identities and outcomes: Cylinder PASS, BunnyRandom RED, Vase RED. Each of the two RED logs in each census has two `GetParam()` address payloads. Applying only N1/N2 plus N4 masking of those exact payloads gives 3/3 raw matches; independent byte-hash verification passes. No new stable loss: 66 events / 17 categories / 49 recurrences; one produced-witness debt, 81 deferred.

### A2. Row 971 diagnostic coverage is not a strong regression guard (new non-stable test-authority finding RA-277-NV1)

The raw `raw/971.log` genuinely reports 34 vertex rays, ten along-edge rays, four edge rays, zero failures, zero ordinary-ray changes, zero equal-edge collisions and ten `SpherePieceRaySlideEnd` lines. These are **measured observations**, not invented counts. But source `tests/FieldAlignedCurveNetworkTests.cpp:17623–17959` increments `changedOrdinary`, `failures`, `coincidentAlongEdge`, `coincidentWithEdgeArc`, `slideArcEnds` and other counters, then only prints the totals. `EXPECT_LT(0U, slideArcEnds)` requires at least one, not ten. Per-slide `EXPECT_FALSE(failed)` allows a valid-but-wrong `inWedge` classification instead of the expected `alongEdge` type. The printed `noNode kind=none` path does not fail the test when a candidate slide is not in `slideEnds`. A returned valid wedge ray for all slides could leave this test green while no slide is classified along-edge. Thus the previous Review's statement that a no-op classification receipt would fail its minimum and type checks is unsupported.

Rows 969 and 970 are meaningful independent focused helper checks (the 2/3 versus 0 chord distinction and along-locus-edge versus legacy rank 4, with negative controls). The helper tests therefore provide evidence, but row 971 cannot by itself enforce exact sphere coverage, absence of ray collisions or ordinary-ray preservation. The earlier Review already states row 971 is non-gating for the future *production switch*; the correction here strengthens that limit, not the immutable gate membership. This is a **test-oracle gap**, not a newly observed source regression. Do not add it to the stable event count.

### A3. Production, segment reader and conformity limits upheld

`src/geometry/EmbeddedGraphTopology.cpp` still builds one face chord and a one-element count in active `build_arcs`; production does not call the new piece rays. The digest still uses the source path, not the segment counts. Trace-piece test row 968 supports real-piece reach but does not prove a cellular sphere plan or the first slide-bearing conformity path. The Review's existing inventory of three ownership readers, conformity spans, accepted chord assumptions, opposite-face side semantics and all-edge-only cases remains a valid set of **unproved future requirements**, not proof of a defect in the test run. Sphere χ6 versus source χ2, four unowned slide contacts, rows 669/698 and O49 remain open. No CP3, selector 497, D0 or H4 promotion.

### A4. Closeout and procedure assessment

The delegated TB154 Review contains the required closeout table and correctly records its `review_check.py boundary` exit 1 on a Git-free snapshot. RA-277 independently invoked this script and observed exit 1 for absent `.git` rewrite history; do not claim a green script. The snapshot is deliberately Git-free; hash and changed-path checks are reported separately. This re-review's early repository document reads took place before the required `READ_MODE=snapshot` decision, contrary to `TOOL_USE_CONSERVATION_POLICY.md` Step 2. After identifying the miss, the review stopped piecemeal source reads, obtained and verified one exact snapshot, and inspected source locally. This procedural miss did not alter product evidence; do not repeat it.

No source, test, fixture, selector, benchmark, CMake, build, or workflow code is changed in RA-277. No Directional binary was run. The only change requested is documentary correction and an explicit future independent test obligation. No prior review obligation is silently discharged: the chord-test preimage, producer/rank consumers, three ownership readers, source-side obligations, count hash, all-edge-only case, first slide-only-face plan and stop-switch suffix checks are carried to their original owners.

## Recommendation — retain exactly one bounded successor

**Qualified PASS:** uphold the immutable TB154 execution and bounded authorization, but reject the prior Review's overly broad row 971 non-vacuity statement. Next only `M6-CP3-CB-169S-P13-TRACE-PIECE-PRODUCER-SWITCH` (compile-only). Its existing scope and STOP rules remain in the TB154 Review.

**New independent-check requirement RA-277-NV1:** During that Code + Build turn, strengthen the *future* sphere helper/producer test oracle with a predeclared expected slide identity set, exact along-edge classification per source-supported carrier, full coverage of every source slide (including rejecting missing `slideEnds`), absence of unexpected helper failures, a check on ordinary-ray invariance, and explicit duplicate-ray/cross-edge collision controls. Derive expected values from source trace records or a separate test oracle, not from the output being tested. Keep rows 969/970 negative controls. Any changed accepted test premise must retain a meaningful failure path; do not rewrite the frozen selector in the Code + Build turn. Its later immutable TB must run these checks; a print-only counter must not be promoted to proof. Do not demand that unmodified production already satisfies these assertions.

**Falsifier:** an earlier claimed full row 971 non-vacuity proof, a deleted/incorrect type classification still passing the future check, an unaccounted change in the 491 accepted cases, a real-piece segment-reader/face-side failure, or any unauthorized stop-switch work. A RED in the following TB goes to Review; no acceptance by normalization. This RA-277 review did not begin CB169S.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 145,036-byte TB153 manifest `fc075b4c…1514116` is an exact byte prefix of 145,526-byte TB154 `0f9c417c…4e305`; CP2 491 accepted unchanged. |
| Decisive claims independently re-derived | All four ZIP outer and internal digests; 968 prior metadata; 971 PASS rows; 558 equal log SHA fields; 491 PASS prefix; three census outcomes; row971 source assertions and observed raw receipt. Full 968/968 raw N1–N3 and 1,750 projection records independently re-normalized; census 3/3 raw N1/N2/N4 normalized. |
| Non-vacuity checked | Row969/970 assert distinct cases and negative controls; row971 only requires at least one slide and valid checked ends. Finding RA-277-NV1 carried. |
| Prior obligations discharged/carried | All producer cutover, O47/C5, O49, source/chart/face-side, first slide-conformity, accepted chord-tests and 491-prefix obligations carried to CB169S and later TB/Review; no product obligation discharged here. |
| Stable accounting | 66/17/49, debt1, deferred81; CP2 491/491; CP3/497/D0/H4 not accepted. |
| New candidates/obligations recorded | RA-277-NV1 is a non-stable test-authority risk; tracker records exact falsifier, next CB owner and later TB validation. |
| ORIENTATION currency line | Updated for RA-277 (2026-11-21), no new runtime state. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 clarify qualified PASS and next check; §4 n/a: existing witness unchanged; §8 reuses existing test-nonvacuity lesson, no new design pattern. |
| CHANGELOG | RA-277 entry added. |
| ROADMAP | n/a: M6/CP3 status and milestone position unchanged. |
| Selector manifest | n/a: no selector mutation or acceptance. |
| LESSONS | Existing non-vacuous oracle and acceptance evidence rules cited; no new general pattern. |
| Consolidation under CLEAN_UP_POLICY | n/a: current TB154 and RA-277 reviews retain live evidence and source links; no source report superseded for removal. |
| Successor frozen | Only `M6-CP3-CB-169S-P13-TRACE-PIECE-PRODUCER-SWITCH`; scope from TB154 Review with RA-277-NV1 added as bounded test-oracle duty. |
| Turn boundary held | Runtime-free; only review/handoff/documentation changes; no implementation/test/fixture/selector/build mutation. |
| review_check.py boundary | Exit 1: no `.git` in source snapshot. Independent hashes and source-boundary inspection used; not reported as PASS. |
| `STATUS` lifecycle maintained | Resumed RA-277 with original start `2026-11-21T07:38:04Z` and resumption `2026-11-21T08:13:52Z`; final direct beacon must be last write. |
| Pushed to origin, branch in sync | Document patch to be verified against the exact GitHub branch after dispatcher apply. Git-free snapshot prevents local `git status -sb`; do not assert that command ran. |
