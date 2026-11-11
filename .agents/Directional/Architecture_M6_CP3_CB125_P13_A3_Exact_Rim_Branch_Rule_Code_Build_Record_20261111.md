# CB125 exact rim branch rule — code and build evidence

- Canonical turn: `M6-CP3-CB125-P13-A3-EXACT-RIM-BRANCH-RULE`; scope: Code + Build only.
- Authority: RA-226 §5; exact patch `.agents/Directional/Architecture_M6_CP3_CB125_P13_A3_Exact_Rim_Branch_Rule_Exact.diff` SHA-256 `f257368a3c6848af144f730794e840a077204cef0dae979df8275f050d4f2e37`.
- Discovery: all four patch target files in CB124 semantic source `acffbffe7f8cb247f9d6118526f37f7d5a7cebad` already had the exact post-image blobs; no additional source edit was made in this turn. Reverse patch apply check passed on verified snapshot `088271ee78a673fc4bcaeac2f737c4232d51f664`. This differs from RA-226's pending-application narrative, and remains a provenance item for closeout.
- Snapshot: [run 43099061130](https://github.com/akashskypatel/Directional/actions/runs/43099061130), artifact `13890467953`, ZIP SHA-256 `52827a0e3877995797c9f7851cb7793832f9c96c3cacd49663bf957e83171a68`; manifest and source identity verified.
- Initial compile request incorrectly supplied forbidden `retention_days`; [run 43100366561](https://github.com/akashskypatel/Directional/actions/runs/43100366561) failed at request parsing, before compilation. Corrected without changing source.
- Verified compile: [run 43100858672](https://github.com/akashskypatel/Directional/actions/runs/43100858672), artifact `13892601257`, ZIP SHA-256 `fdea19701ce2a6b78b8d77c125a33915a334c41d3947b73c85c6a3ec26cee304`.
- Package verification: 28/28 SHA-256 entries passed; exact source SHA `088271ee78a673fc4bcaeac2f737c4232d51f664`; all eight required targets present; preflight and compile exit codes 0; clean source status.
- Exact arithmetic: package records `exactArithmeticBackend=GMP`; verified both `libgmpxx.so` and `libgmp.so` on the authority-kernel test target's link line.
- Runtime boundary: `runtimeExecution=false`; no tests, benchmarks or runtime binaries executed in this turn. No TB106 or CB126 work started. No direct production acceptance claimed.
- Pending closeout: reconcile the pre-applied code provenance in the durable handoff, TODO and root CHANGELOG; clean temporary snapshot trigger; publish root STATUS as the final repository action. Only after formal closeout may TB106 start in a new turn.
