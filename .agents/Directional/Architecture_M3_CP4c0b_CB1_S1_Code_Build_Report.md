# M3-CP4c-0b-CB1-S1 Code + Build Report

**Status:** COMPLETE / BUILD GREEN / RUNTIME-FREE
**Turn:** `M3-CP4c-0b-CB1-S1`
**Semantic / evidence source:** `4bb467806df99c70889394a323c17c13bc185ca3`
**Boundary:** Code + Build only; no Directional runtime/test/benchmark execution.

## 1. Authority and scope

`M3-CP4c-0b-P0.3-REVIEW-PLAN` withdrew false P0.3 and superseded P0–P9 with S0–S8. The review requires S1 — a non-gating census of the already-shipped shared-face contact behavior — before any semantic correction. If an accepted witness currently truncates at a same-face pair that is not a proper crossing, changing the predicate changes accepted authority and requires independent review.

This CB therefore implements **S0 + S1 only**. S2–S6 were not entered.

## 2. S0 corrected preflight

S0.1–S0.6 were re-established statically before S1:

- accepted CP4c-0 selector remains 346 identities, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`;
- candidate-trace terminal state remains the pre-contact accepted representation;
- all three existing `TraceIntersection` emission sites remain present;
- `field_aligned_first_trace_contact` remains same-face-only production authority;
- contact-node placement remains the face's `vertices().front()` source vertex;
- tracing still completes/fails before post-hoc `finalize_field_aligned_events`, and N1/N2/N4 remain present.

S0.7 is now satisfied by the authoritative GMP compile in §4: `DIRECTIONAL_ENABLE_GMP=ON`, GMP/GMPXX linked, `exactArithmeticBackend=GMP`.

## 3. S1 implementation

Touched durable semantic/test paths:

- `include/directional/geometry/SurfaceCellTracing.h`
- `src/geometry/SurfaceCellTracing.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`
- `.agents/Directional/Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt`

The S1 diagnostic records, without altering production decisions:

- every contact fired by the current shared-face predicate;
- trace ID / segment index and existing trace ID / segment index;
- source face plus the pre-existing common-carrier diagnostic label;
- exact-barycentric proper-crossing classification computed only for the census;
- the trace's `terminalSingularity` / `terminalBarrier` / none state **before** current truncation erases it;
- contact-node IDs and their current `sourceVertex`;
- site A / B / C counts, total node count, and event-kind histogram.

The diagnostic entry point calls the canonical A2a construction path with an optional census sink. The accepted production entry point passes no sink, so current contact, truncation, event, node, trace, and termination behavior is unchanged.

The separate non-gating identity is:

`ResolvedBranchCorrection.ContactPredicateCensusIsPublishedNonGating`

It emits `m3Cp4c0bS1` records for the two-ring, excluded four-triangle fan, prescribed sphere, and torus witnesses. The accepted 346 selector is untouched.

## 4. Build evidence

### 4.1 Patch transport correction

Initial apply run `33091855034` failed before commit. Patch bytes and hashes were valid, but the preservation header encoded four `intended_paths` with commas while `agent-google-drive-reusable.yml` parses that field with semicolons. The changed-path equality check therefore compared one comma-containing string against four actual paths and failed closed. No semantic commit was created and `runtimeExecution=false`.

The corrected preservation patch changed metadata delimiters only; its diff-body SHA-256 remained `05f6bcfaa65da104daaffa92ca06d97f03c34c150f12e956c3478ddfb122833f`. Retry apply run/job `33092961074 / 98590434004` succeeded and pushed semantic commit `4bb467806df99c70889394a323c17c13bc185ca3`.

- apply result `9655159304`, SHA-256 `7c56e84ab41398a567ccfb0f27c70a0b107e7ddd3234949f7ee056458c4de0f9`;
- apply log `9655160089`, SHA-256 `95c753aaf46a4facade10889aa4569a87daf4e78754483e8823a01069cefbc42`;
- Google Drive staging retired after successful push.

### 4.2 Compile correction and authoritative compile

Caller run `33093222009` ended `startup_failure` before any jobs because the first compile caller provided `contents: read`; the reusable observer requires the caller permission union to include `contents: write`. This is orchestration-only evidence and produced no build/runtime authority.

Corrected authoritative run `33093440552` used the durable `.github/workflows/agent-compile-reusable.yml` twice on **the same semantic source** `4bb467...`:

1. mandatory pre-package compile — job `98592131066`, target `directional_surface_cell_producer_tests`, success;
2. eight-target package compile — job `98593728046`, success for `directional_core`, `directional_pipeline`, authority-kernel tests, producer tests, completion tests, validation tests, compiled API tests, and benchmarks.

Evidence:

| evidence | artifact | SHA-256 |
|---|---:|---|
| pre-package result | `9655528709` | `cf179bae7d1897f66b286e5688afb8540760d289ecca6de598fdb1d0638ef3f6` |
| pre-package log | `9655529401` | `68fa64caa92340251eeeed77236aaf90ff895a7202c253c0ab6f44d9308d6609` |
| eight-target package | `9655632444` | `c22e9b020e533ca8fc558bcafc3e138a062702a59bee68a097958b432d70bc5f` |
| package compile log | `9655633229` | `ad36b3523bd3843b3618bee8ff71aa4789be6381554d8e089d1f4469d44e4b9e` |

Both compile jobs configured `DIRECTIONAL_ENABLE_GMP=ON`, verified GMP discovery and generated GMP/GMPXX linkage, recorded `exactArithmeticBackend=GMP`, and reported `runtimeExecution=false`. No produced Directional binary, test, benchmark, discovery/help/version command, CLI, fuzzer, or custom input was executed.

## 5. Executable Test + Benchmark plan

**Next:** `M3-CP4c-0b-TB-S1-EXEC`
**Immutable package:** `9655632444`
**Semantic source:** `4bb467806df99c70889394a323c17c13bc185ca3`

1. Download the package once; extract with executable modes preserved. Verify `SHA256SUMS`, source commit, `exactArithmeticBackend=GMP`, and `runtimeExecution=false`.
2. No configure/compile/relink/repair/generated discovery and no source/test/fixture/selector mutation.
3. Execute `.agents/Directional/Architecture_M3_CP4c0_Required_Green_Selector.txt` unchanged: exactly 346 gating identities, one fresh process per identity, mutation flags false.
4. Execute `.agents/Directional/Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt` separately. Its one S1 identity is diagnostic only and contributes no gate credit.
5. Preserve all `m3Cp4c0bS1` output. For each included witness report reached/unreached state, shared-face contact count, proper/non-proper/unevaluated counts, `requiresReview`, site A/B/C split, pre-truncation terminal kinds, contact-node source vertices, node count, and event histogram.
6. Preserve the excluded four-triangle fan as explicitly excluded. If the prescribed sphere exits during tracing at N1, record `status=unreached`; do **not** report zero contacts.
7. Re-hash the immutable package after execution and require byte-identical postflight.

### Acceptance / routing

- Gate must remain **346/346** with zero timeout/escaping exception and immutable postflight.
- Any reached included accepted witness with `nonProperCrossingCount > 0`, `unevaluatedCrossingCount > 0`, or `requiresReview=1` routes to independent `M3-CP4c-0b-S1-REVIEW-PLAN`. S2–S6 remain prohibited.
- An expected sphere N1 `status=unreached` is recorded as evidence of the current post-hoc limitation; an unexpected diagnostic error routes to review.
- If the gate is green and every reached included witness has `requiresReview=0`, advance only to evidence-review state `M3-CP4c-0b-TB-S1-REV`; no semantic implementation occurs inside TB.

## 6. Closeout

Code + Build boundary held. No S2–S6 implementation leaked into this turn. Stable regression accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**. The new immutable S1 package advances the M3 package count to **52**. Runtime authority remains the accepted CP4c-0 TB-R9 re-proof 346/346 until TB-S1 executes.
