# DEFN off-selector review continuation — exact WIP preservation

This is a **working record, not a completed DEFN disposition**. Resume `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION`; do not start CB53/TB51. `STATUS` entry start time is `2026-10-29T23:56:55Z` and must be preserved on continuation.

## Authority and independently checked evidence

- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`, snapshot source `76c2aacf4c5bd3f8018831ddc12f77c8df71d52a` (only entry STATUS and source-snapshot trigger committed before this snapshot). Source snapshot Actions run `40976584569`, artifact `12942827622` checked against `a95f3def88e34758a6069900ddfd03d2732d500bd4aff7553171f32034893980`.
- TB50C-R2 run `40965775275`: immutable results `12941320247`, logs `12940158599`; 408/408 OBSERVE, 323 PASS/83 RED/2 ABNORMAL/0 INVALID, 822/822 internal checksums, 408/408 raw log digests. Product semantic source `7cf0857b4818186638ce77e4859adacbeebd288f`, package `12918290481`.
- Prior candidate TB50-R2 is 508/508 independently reviewed; CP2 491/491 remains last accepted. Stable regression 66/17/49, debt 1. No accepted-green loss adjudicated, no retirement, no CP3 acceptance or selector497 promotion.
- Output work: `Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Working_Inventory_20261029.md` (85 rows, 14 working first-failure groups P01–P14), and `Architecture_M6_CP3_TB51_Proposed_916_Case_Manifest.tsv` (508 unchanged prefix + 408 proposed GUARD rows). **The proposed manifest is not an authorized or executable gate**; 916 is only the all-retained size, and revised gate size is 508 + (408 - independently justified retirements).

## Verification and restrictions

- ZIPs were hash checked; exact source-snapshot archive verified. No builds, native tests, source, test, or fixture edits were performed.
- The snapshot is deliberately distributed without `.git`. Running `python3 .agents/Directional/tools/review_check.py boundary` in that extracted snapshot fails its *Git ancestry* checks (`durable rewrite baseline exists and is ancestor`, sources for handoff/ORIENTATION/tracker), so it does **not** establish a real review-boundary defect. Re-run in proper Git checkout after actual repository edits.
- One source-snapshot trigger created under `.agents/connector-triggers/source-snapshot/20261029-defn-off-selector-coverage.txt` by commit `76c2aacf...`; classify and retire through the approved cleanup process, not mistaken for semantic source work.
- Google Drive patch transport first failed when `files__manage_library(container_path=...)` returned `container_session_unavailable`, but succeeded after exporting the identical patch bytes to an exact `file_...` reference. An initial Markdown-MIME duplicate was deleted, and a replacement was staged to `My Drive/Directional-CI` as `text/x-diff`. This preservation-stage Drive file is **not** a patch application; obtain the latest staged File ID and checksum from the chat closeout, and verify the dispatcher application independently on continuation. No safety-check rejection occurred; the turn is not BLOCKED.

## Remaining critical work

1. Inspect complete raw logs and source for each of 85 observations, distinguishing a common first error from common causal root; classify as valid producer/validator defect, stale independent oracle, invalid fixture, legacy O2 obligation, proven platform issue, or legitimately retired case. The four unconditional `FAIL()` probes are merely **retirement candidates**, not authorized removals.
2. For each proven cause group specify an exact minimal corrective patch, target files/constraints, independent falsifiers, tests and acceptance; one CB per proven cause. Do not weaken tests, bypass production authority, or mark new stable regression without accepted-green historical evidence.
3. Decide any individually evidenced retirements and coverage replacements; freeze the actual TB51 manifest as `508 + (408 - retired)` only after full adjudication, correct validation of invariant 508 prefix, and Review-authorized checks.
4. Complete the DEFN review record and required durable tracker/TODO/handoff/ORIENTATION/changelog updates under authorized scope, perform Review closeout checklist and boundary validation in Git context, publish validated patch via Google Drive dispatcher, verify application and clean up; only then mark the turn COMPLETE and release authorized successor.
