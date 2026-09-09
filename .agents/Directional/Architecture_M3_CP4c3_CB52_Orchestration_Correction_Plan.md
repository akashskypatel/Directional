# M3-CP4c-3-CB52 Orchestration-Correction Code + Build Plan

**Turn:** `M3-CP4c-3-CB52`
**Class:** Code + Build / control-plane orchestration correction
**Runtime:** Directional runtime forbidden
**Source/package policy:** reuse immutable package111; no semantic product/test/fixture/selector change

## 1. Entering evidence

`M3-CP4c-3-TB46-EXEC` run/job `34374946991 / 102545334482` is orchestration-invalid and produced no semantic
ledger. Its temporary caller schema-validates and verifies the frozen generic harness SHA-256
`aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`, then the nested harness returns `1`
before creating its result directory or emitting its own first environment record. Retained log artifact
`10113449239` has SHA-256 `7910fbe8fa6c0c397dfcef37aeaac0abd398d2a41dc527a9e3c2afe231bc6b42`.

Semantic runtime authority remains TB45/package110. Immutable package111 remains artifact `10112532452`, source
`4f0663ef3468996abce6f59109f1c67f5be5f604`, provider/download SHA-256
`62ae325186ef31d2936e1a797c55cef43f8aef62449b33a26e29cb1ecd9185da`. Selector409 remains 409 rows at
`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.

## 2. Bounded corrective objective

Localize the first failing command in the harness bootstrap without exposing credentials, then make the smallest
control-plane correction that lets the unchanged artifact-only contract reach and complete preflight.

The correction may touch only temporary TB46/CB52 caller/control files and, **only if the failure is proved to be in
the durable generic harness itself**, `.agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh`.

Product source, product headers, tests, fixtures, selector409, benchmark inputs, packaged binaries, and package111
are out of scope.

## 3. Required measures

1. **Bootstrap presence/writability probe.** Before nested harness invocation, fail closed on every required variable
   using presence-only diagnostics. Never print `GH_TOKEN` or any secret value. Verify `RUNNER_TEMP` exists and is
   writable and verify the safe-turn path can be created.
2. **Pre-trap localization.** Instrument only the pre-trap bootstrap surface sufficiently to identify the exact
   failing command. Do not use unsanitized `bash -x` across a command that can render `GH_TOKEN`.
3. **Surgical correction.** Correct only the proven bootstrap/control-plane cause. Do not change semantic artifact
   inputs or the selector execution algorithm.
4. **Static controls.** `bash -n` the corrected harness/caller materialization and verify the expected harness bytes
   or, if the durable harness changes, record the new SHA-256 and exact diff.
5. **Artifact-only preflight proof.** Run the corrected generic harness in `--preflight-only` mode against immutable
   package111. It must verify provider/download digest, 28/28 root manifest, source SHA, GMP/GMPXX authority,
   selector409 count/hash, six executable identities, identity map, execution-view staging, and equal immutable
   pre/post censuses.
6. **Runtime prohibition.** The proof must retain `runtime_started=false`, `runtime_completed=false`,
   `benchmark_execution=false`, and every configure/compile/relink/repair/mutation flag false. No generated
   Directional executable may run.
7. **Evidence preservation.** Upload the preflight result and persistent diagnostic log. Record exact run/job/artifact
   identities and hashes.

## 4. Stop rules

- If localization proves a semantic source/test/fixture/selector/package defect would be required, **STOP**; CB52
  does not authorize that change.
- If the corrected `--preflight-only` run does not complete with immutable postflight, **STOP** and preserve the
  earliest orchestration failure.
- Do not run `--execute` in CB52.

## 5. Exit

On a green control-plane preflight, close `M3-CP4c3-TB46-ORCH-01` as runtime-free orchestration correction and freeze
exactly one successor:

**`M3-CP4c-3-TB46-R1` — artifact-only Test + Benchmark**, reusing immutable package111 and selector409 from ordinal
1 with the same semantic measurements frozen by the still-live TB46 plan.
