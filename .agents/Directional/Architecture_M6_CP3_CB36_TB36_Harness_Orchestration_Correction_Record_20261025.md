# CB36 — TB36 harness orchestration correction (2026-10-25)

**Turn:** `M6-CP3-CB36-ORCH-RP01-TB36-HARNESS-CORRECTION` (control-plane-only Code + Build).

## Authority and scope

- Exact inspected source snapshot: `96525e106ea2d8c46cb96cd844c504bbf8a8bc48`, source-snapshot run `40156612586`, artifact `12584469765`; artifact ZIP SHA-256 `0aa0c405b6abb6e3be3c9f1a3d871d84c6147ed00d95a952f96f9d90ad1a54c0`; inner archive and 5,866/5,866 file checksums verified.
- Previous invalid TB36 attempt: run `40155549123`, harness exited 90 at preflight, 0/5 tests; retained as invalid orchestration provenance, no semantic results.
- Correction commit: [`0ba22724c97e9231f24a6d9bc7201e58b3c6da81`](https://github.com/akashskypatel/Directional/commit/0ba22724c97e9231f24a6d9bc7201e58b3c6da81); only `.agents/Directional/tools/m6_cp3_tb36_periodic_monodromy_baseline_harness.sh` changed, three textual replacements (uniqueness comparison and two source-location regex sites). GitHub resulting blob SHA `e45c53e70a8fb32db0d79ad42fac893c736cd252`, equal to the locally independently generated blob.
- Corrected harness SHA-256: `343cdc6e53daf33da7d2893086751e0f762e6a3ed2111e69bf077555a4e3f439`. Existing five-row frozen TB36 manifest SHA-256 `ab2711b2efc64103a9106b9a63f03064c63dc6e93a16c0602f3c6b3f866c1d0c` unchanged.
- Immutable semantic source `7de805c487fa66bcb96744f51b8bfbe7210ee8dc` and package artifact `12580989509` with ZIP SHA-256 `a594b8617493087ff9ab50391e30cc7a8870f2dcf92427c03899b076e344bb54` unchanged.

## Corrective evidence

1. Compare `len({test})` and `len({identity})` each against **5**, not inherited TB35 **13**.
2. Change both Python raw regex uses from literal-backslash matching to real `\.cpp` / `\d+` pattern escapes so the GTest first failure line is extractable.
3. Local `bash -n` and extracted embedded Python `ast.parse` passed.
4. Independent manifest read: 5 rows, 5 distinct test names, 5 distinct identities, exact original manifest hash; no tests selected or run.
5. Representative raw GTest filename/line matched in both regex callsites; negative malformed filename and nonnumeric line failed to match.
6. No configure, compile, link, Directional executable, runtime, benchmark, package regeneration, selector or workflow permission changes. `runtimeExecution=false`. The initial independent verifier incorrectly transcribed the 64-character manifest digest by dropping its final `c`; the verifier was corrected to compare full independently computed bytes to the literal embedded harness digest and then passed. That verifier typo did not affect any repository content.

## Authorized successor

**`M6-CP3-TB36-R1-RP01-PERIODIC-MONODROMY-BASELINE`** — a new, separately scheduled artifact-only Test + Benchmark turn. Freeze its own executor SHA (including this corrected harness) and exact SHA-256 above. Use the same immutable semantic source, package, manifest and all five frozen tests and prior stop gates. Do not reuse the invalid run or alter runtime/test/selector/fixture evidence. After a valid run, perform TB36 independent Review before any CB36 production repair. Stable accepted CP2 491/491, TB32 candidate 481/500, TB35 11 PASS / 2 RED and stable 66/17/49 with debt 1 remain unchanged.

**Policy observation:** Before selecting snapshot read mode, the turn fetched several source documents directly. This violated `TOOL_USE_CONSERVATION_POLICY.md` pre-read gate; further source inspection used the exact verified snapshot. The corrected harness was committed through the connector's authorized isolated minor-file direct-write path, not through the Drive patch workflow.
