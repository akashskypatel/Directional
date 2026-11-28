# M6-CP3-TB-REV-193 — independent review (2026-11-28 UTC)

## Situation

Accept the frozen 1013-row test gate only. All 1010 inherited rows and the three new guard rows meet the TB-EXEC-193 contract. Row 1012 confirms TB-REV-192 adv. EE3 with the deletion option on; the option stays off in production. M6-CP3 stays open; CP2 491/491 stays accepted. No production, V5 or checkpoint acceptance.

## Evidence (re-derived independently, runtime-free)

An evidence agent that did not run TB-EXEC-193 re-derived every decisive claim from raw artifacts with its own comparator:

- ZIPs: TB193 result `15250401219` `c771dab68abfd32a57e66cb236d5a8d618c124cb3040d0e388e12eb9614daa7b`; TB192 `15195820651` `37bd0d7c…0ce`; TB191 `15179335926` `bab546af…b519`; CB-218 candidate `15249606947` `3d89344569f498cf2ad21afa0d3e61d25e256abe3d9dbbdf15b0cff172665a6f`. Run `46110979697` conclusion success.
- Manifest `b910f2a9…2fc2`; header + rows 1–1010 = TB192 `c9f6325e…e9f5`. Deferred ledger `fd433f54…64ce`, 81 identities, disjoint from the 1013 gated identities. Membership 1094 = 1013 GATED + 81 DEFERRED; gated pairs equal the manifest, deferred pairs equal the ledger.
- TB193 internals: SHA256SUMS 2034 entries, 0 missing, mismatched, uncovered or extra; 1013/1013 PASS, exit 0, run 1, no first_failure; every ledger log digest equals sha256(raw/N.log); execution-boundary counters planned = executed = passed = 1013, all failure counters 0, postflight true.
- Provenance: the candidate's packaged source archive (`dce0391a…`) holds the three CB-218 postimages (`522cfebb…`, `3a67db44…`, `d02c8507…`), equal to `git show abe40f6a…`; the result names candidate `15249606947` and source `abe40f6a…`.
- Comparator calibration: TB192 vs TB191 (rows 1–1008 minus 858) reproduced exactly: 770 identical, 237 N1-only, 0 N3, 0 different.
- TB193 vs TB192, rows 1–1010 including 858: 586 identical, 424 N1 (elapsed time), 0 N2-only, 0 N3, 0 different. Row 858 N1 only (six elapsed-time lines, 9196 ms → 13819 ms). All 27 sphere-carrying rows (380, 388, 393, 394, 396, 397, 644, 645, 648, 669, 686, 691, 693, 694, 698, 699, 700, 843, 844, 858, 963, 968, 971, 972, 978, 979, 1006) and the named controls are N1; 1005 identical.
- Rows 1011–1013: one RUN line each for the expected test, `[  PASSED  ] 1 test.`, no FAILED; digests `a900a9fd…e5c6`, `2ab9ea18…4db7`, `a83d053f…9371`.

## Assessment

- **Non-vacuity.** Row 1011 injects an ambiguous ray and a missing match and asserts `SeveralPortSlots` / `NoPortSlot`; a first-match classifier fails it. Row 1012 asserts the option-off network (24 traces, no `arrivalPort`) and the option-on network (traces {0,1,5,8,9,10,11,12,13,14,17,20,21,22}; `arrivalPort` 0→4, 1→6, 9→3, 10→23, 11→7, 12→19, 13→15, 14→2, 21→16, 22→18; every port owned once; 12 dense nodes; validation under the option). A no-op or mis-mapped deletion fails it. Row 1013 injects each of the five rejection conditions into the valid sphere candidate and asserts the specific condition and an unchanged candidate.
- **What is proved.** The A2a network-level deletion on the prescribed sphere, exactly as EE3 predicted. Not proved: the downstream region count (V12/E18/F8 → 8 regions), any reader beyond A2a with the option on, and cost with the option on in production.
- **Execution report accuracy.** Correct in every checked claim. Its row 1012 summary omits the 12-node and validation assertions, which the test does check.
- **Comparator reproducibility.** Two independent out-of-repo comparators, each calibrated on TB192-vs-TB191, agree. No committed normalizer exists; a small committed tool would make future TB comparisons reproducible (off the critical path).

## Obligations carried to the switch DEFN

1. Census the 27 sphere-carrying gated rows: every assertion or print that depends on the sphere's trace, node, arc or region counts, and derive exact post-flip expectations from the witness and EE3 (TB-REV-192 adv. region table).
2. Census every `src/` reader of one-trace-per-port ownership and `arrivalPort` (EmbeddedGraphTopology `originByPort`, GlobalTopologyPlan, `field_aligned_publish_origin_events`), and whether D13's production removals already exercise them.
3. Cost with the option on (row 1012 took 34.6 s for two sphere builds plus validation; V5 BunnyRandom already sits at its 600 s cap).
4. O52 (slivers 2/4) and DD5 unequal sides stay with the corners DEFN and A4 unequal-side construction. O50, B1 held, B2 unmeasured. Stable 67/17/50, debt1/deferred81; no new stable regression.

## Recommendation

Successor `M6-CP3-DEFN-P13-A2A-COTRACE-DELETION-SWITCH` (runtime-free): run the three censuses before freezing the default flip; split reader changes into their own CBs if needed. No production, V5 or promotion here.
