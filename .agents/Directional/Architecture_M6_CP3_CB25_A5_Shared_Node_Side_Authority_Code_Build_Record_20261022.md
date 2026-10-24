# CB25 — A5 shared-node side authority: Code + Build (2026-10-22)

- Turn: `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` (RA-127.5). Source snapshot `1b9b742663bb29b864c9f1710a42a9e1b1e4eb07`, run `39716482308`, artifact `12399162643`, outer SHA-256 `efe064eba68dc9b1794c489ce6d04a6496828ddedb19cd82be78076f7eede433`, 5769/5769 source hashes.
- Only `src/pipeline/RemeshPipeline.cpp` changed (+21/-6); no headers, tests, selectors, workflows or A6 changes.
- Shared `certified_seam_shared_node` helper: exact equal `support`, `placement.selectedFace`, and integer `latticeCoordinate` (RA-127.2).
- A5 `certified_seam_direction`: skip only first/second span-to-selected-face equalities for shared nodes; all other clauses and certified-side orientation unchanged.
- A5 rejection-site clause classifier: mirrors the same helper for `first-face`/`second-face` labels; existing site text format retained (RA-127.3).
- Prepared patch SHA-256 `58d0ee33bc62c59f9ef0a52ba853ebfbfa324dd58a6747620a5e90245201e991`, diff-body SHA-256 `4a660ff4158cea3fba4ce8bbab616ecdbdcfa8cb8bead3f2d6660ff0c52c117f`; clean-base application and `git diff --check` passed locally (no local build).
- Patch apply workflow run [39717014344](https://github.com/akashskypatel/Directional/actions/runs/39717014344), result artifact `12398808897` SHA-256 `d6f94a96aa4f1c44a33393a4a67490a93e523abf4d330f80bc80576b4c1964c2`; source commit `c5e0b242f3c3015f1f4f5f886058f0086fe1f679`. Staged Drive patch deleted after successful push.
- Eight-target GMP/GMPXX compile: [run 39717280320](https://github.com/akashskypatel/Directional/actions/runs/39717280320) GREEN, package `12399179446`, outer ZIP SHA-256 `a82c75e0f648fa8f1c8e34e07934d7a01321692e12e993638f02465766f236e9`; 28/28 manifest hashes, eight targets, preflight/build 0/0, five empty source statuses, link evidence includes `libgmpxx.so` and `libgmp.so`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- No tests, benchmarks, binary executions, or runtime-acceptance claim. Existing 66/17/49, debt 1, CP2 491/491, R3 403/497, candidate TB21 449/497, selector 497 remain unchanged; RP-01 open.
- Authorized next turn: `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV` (independent Review, then TB26 if accepted).
