# CB125 exact rim branch rule — code and build evidence

- Turn: `M6-CP3-CB125-P13-A3-EXACT-RIM-BRANCH-RULE`; Code + Build only, RA-226 §5.
- **Correction to prior record:** the original source `088271ee78a673fc4bcaeac2f737c4232d51f664` had the four **pre-patch** blobs; forward `git apply --check` passed and reverse check failed. The previous assertion that the exact patch was already applied was false.
- Frozen exact 251-line diff SHA-256 `f257368a3c6848af144f730794e840a077204cef0dae979df8275f050d4f2e37` applied to four prescribed code/test paths (+197/−3). No production caller changed; exact rule remains unwired.
- Original source snapshot [run 43099061130](https://github.com/akashskypatel/Directional/actions/runs/43099061130), artifact `13890467953`, ZIP SHA-256 `52827a0e3877995797c9f7851cb7793832f9c96c3cacd49663bf957e83171a68`; 5481/5481 file hashes verified.
- [Patch apply run 43102523069](https://github.com/akashskypatel/Directional/actions/runs/43102523069) completed, artifact `13891722660` ZIP SHA-256 `840d47cf9279ab7d18ba947a76e5e796a455f3119d329882f41c3dd42a5b8e48`; applied source commit `0ff93f167feb69dc290d4f220a0f8d32a906e2f7`, `runtimeExecution=false`.
- Pre-patch [compile run 43100858672](https://github.com/akashskypatel/Directional/actions/runs/43100858672) succeeded on unmodified source `088271...`; this is **not CB125 compile evidence**. First dispatcher parse attempt run `43100366561` rejected an unsupported field before compilation.
- Correct patched-source compile dispatched as [run 43103045569](https://github.com/akashskypatel/Directional/actions/runs/43103045569), source `0ff93f167feb69dc290d4f220a0f8d32a906e2f7`; **package verification pending**.
- No tests, benchmarks or production acceptance claimed. Next separate turn, only after a verified compile and completed documentation: `M6-CP3-TB106-P13-A3-EXACT-RIM-BRANCH-RULE-FULL-GATE-EXEC`.
