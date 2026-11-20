# CB168K — slide-contact arrival-order receipt (Code + Build, 2026-11-20 UTC)

## Situation

**Compile PASS.** [Compile run 44679070165](https://github.com/akashskypatel/Directional/actions/runs/44679070165); source `0955d28e37a4f17f2488f0f4dd196a2d24aa3c11`, immutable artifact `14603866682` (archive SHA-256 `b5da1e638be05ec80dd946a15d417e40f3613b5ada6652224bea1fdba5fef8d8`). Eight RA-245 GMP/GMPXX targets compiled; `runtimeExecution=false`. No tests, benchmarks or Directional binaries ran.

## Background

The [RA-270 independent review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md#ra-270--adversarial-re-review-of-this-review-2026-11-20-utc) established four unowned sphere sliding-wall contacts, but did not establish which trace arrived later at each contact. Its exact frozen diagnostic diff `fc70c9aa07ea31f4121ac297f7bc24fca3f82ffadec6ef6880b82f8d99ecb4a4` adds only the `FieldAlignedCurveNetwork.slideContactArrival` receipt at the source producer. The difference from the earlier compiled source `d78404724a7f0bfb0c9c73769e6a68b9f2addd81` was empty under `src/`, `include/`, and `tests/` before this patch.

## Assessment

The verified preimage snapshot was `d6c91a743ba9b5150cf5b4746d208ee00ecbc912`. The patch passed `git apply --check` and whitespace checking. [GitHub patch application](https://github.com/akashskypatel/Directional/actions/runs/44678801350) applied exactly 28 insertions and zero deletions to `src/geometry/SurfaceCellTracing.cpp`, producing source `0955d28e37a4f17f2488f0f4dd196a2d24aa3c11`; the file blob is `400805c7c18c7fed78850cca1719f1e88d783db4`. Apply result ZIP SHA-256: `632b37dd25ee653871defa3826edceb2ff3ac453f53e862f69f4014ac20459cf`. Staged Drive patch was retired after successful push.

Compile result confirmed `28/28` packaged file checksums and `exactArithmeticBackend=GMP`; `gmpxx` and `gmp` linked. Compilation only, with no product, test, fixture, selector, manifest, acceptance, or runtime-semantic mutation. TB148 remains the last semantic runtime gate: 963/963, accepted 491/491, and four unowned sphere slide contacts; row686 remains χ6 versus expected χ2. Stable regression accounting stays 66 events, 17 categories, 49 recurrences, one produced-witness debt and 81 deferred. No CP3 or selector promotion.

## Recommendation

Next canonical turn only: `M6-CP3-TB149-P13-SLIDE-CONTACT-ARRIVAL-FULL-GATE-EXEC`, an immutable artifact-only Test + Benchmark. Use the compiled package; preserve unchanged TB148 manifest SHA-256 `4350378c95fefeb0dbab6e742b50dcd976af406f865ddef45cc03b35f7b4c01c`. Strip only new `slideContactArrival` diagnostic lines for the 963/963 prior-gate comparison and the 3-case census. Require accepted prefix 491/491 and 963/963 prior rows MATCH TB148; otherwise STOP. Give the exact four arrival-order lines verbatim to the Review. The prediction of four `wallCommitted=1 movingArrival=later` lines is unverified until TB149. Do not implement a stop switch, cut-position change, or other successor work in this turn.
