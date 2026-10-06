# M6-CP3-CB1-ENTRY-R1 WIP handoff — 2026-10-06T16:27Z

Turn remains IN_PROGRESS. No compile/package or generated Directional runtime was executed.

## Authority and snapshot state

- Entry STATUS commit: `41a4f08b748162d7a38eef8843073e7b263b5ddc`.
- Source-snapshot trigger marker commit: `637eb6f217a839ec1f9a6d9871a45b67089736e7`.
- The new `repo-source-snapshot` mailbox had not published before closeout. PR #8 observer comments were queried once and returned no run marker.
- Fallback inspection reused verified snapshot run/artifact `37473448866 / 11417518521`, source `e1976187f5a6297dc34c08e4c6c1075f1e8a6903`, outer artifact digest `fdbde2bf020cfb17ff3e9f42c04401aed59a63e77a2fb234bb3950b6bb058f66`, archive digest `47acf70f353393d307f1139e443b9926f931f004f401f183d10c7574abac8792`, 5544/5544 source-manifest checks passed, `runtimeExecution=false`.
- Exact compare `e1976187... -> 637eb6f...` showed only documentation/control/mailbox/STATUS/TODO changes; no `src/`, `include/`, or `tests/` paths changed. The reused snapshot is therefore byte-authoritative for the two edited source files, but this fallback must be recorded as a process deviation rather than normalized as the preferred snapshot path.

## Preserved WIP patch

Google Drive staging:
- folder: `My Drive/Directional-CI`
- file: `M6-CP3-CB1-ENTRY-R1-WIP-20261006T1626Z.patch`
- file ID: `1SqSKxMOVJaAFpNWDo38LXPE-A9dHCcFT`
- SHA-256: `4591ab1ea8c23a248231c501bd41b220c043e542940ea5f8a9428031ccbff301`
- patch base: `e1976187f5a6297dc34c08e4c6c1075f1e8a6903`
- intended paths: `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`
- dry-run application against the exact snapshot succeeded.
- WIP only: not compiled, not runtime-tested, not pushed to GitHub.

Implemented locally in that patch:
1. P1 uniform producer publishes `frame.faceBranchRotation`.
2. P1 periodic producer preserves the winning exact branch map per strip candidate, merges it into `result.faceBranchRotation`, rejects conflicting/missing/non-Z4 gauges, and publishes a complete gauge vector for active faces.
3. RA-31a removes the A5 HardRail branch-certificate rejection and legacy `:branch-certificate` mapping while retaining endpoint gauge evidence.
4. P2 moves reciprocal isolation-side evidence validation into the certified cross-sheet OrdinaryFront branch instead of requiring it for every OrdinaryFront relation.

## Still required before compile

- Re-open the R1 plan and complete T1 focused30 ordinal-12 face-gauge relabel.
- Complete T2 D1 90/270 produced nonzero-Z4 witness + stop rule.
- Amend identity 2 per RA-31a: pre-registered RED certificate assertions, but A5 production/non-vacuity must pass and any A5 rejection must print exact code/site/relation.
- Ensure identity 6 reaches/passes A5/A6/A7 under removed branch-certificate rejection.
- Complete T4 oracle so it tests typed source barrier/transition authority, not arbitrary endpoint `chartComponent` inequality.
- Static census all regional `faceBranchRotation` publication and P2 evidence scope.
- Run `git diff --check` on the complete patch and authorized path census.
- Apply the complete patch through standard Google Drive transport, then compile/package all eight mandated GMP/GMPXX targets through `agent-compile-reusable.yml` only; no runtime.

## Control state

The source-snapshot trigger marker `.agents/connector-triggers/source-snapshot/m6-cp3-cb1-entry-r1.txt` remains on the branch because the triggered run could not be authoritatively observed before closeout. Do not create a duplicate trigger blindly. First check the mailbox/recent-runs fallback and reconcile/clean the marker under workflow policy.
