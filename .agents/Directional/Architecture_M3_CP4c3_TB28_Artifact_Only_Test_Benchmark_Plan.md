# M3-CP4c-3-TB28 — Artifact-Only Test + Benchmark Plan

**Turn:** `M3-CP4c-3-TB28`
**Boundary:** Test + Benchmark only; **no rebuild, repair, relink, source/test/fixture/selector mutation, or replacement package**.
**Evidence source:** `098ac7d93ea203222dd0ac50cdb68667744f0fd4`
**Immutable package artifact:** `9975737868` (`m3-cp4c3-cb32-compile-result-33987769718`)
**Artifact SHA-256:** `16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec`
**Selector:** 407 identities, LF SHA-256 `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`

## 1. Purpose

Consume only the immutable CB32 compile artifact and execute selector 407 to observe the CL6/CL7 source-face
ownership publication. This turn does not choose or implement a correction. Its output is the runtime evidence for
the mandatory independent review that follows TB28.

CL8 is binding: after valid TB28 evidence, the review must freeze a product correction. If the CL6 census is
ambiguous, the correction defaults to the barrier-set branch. No fourth standalone diagnostic CB is authorized.

## 2. Preflight — fail closed before any Directional runtime

1. Download GitHub Actions artifact **`9975737868`** by artifact ID from compile run `33987769718`.
2. Verify the provider/downloaded artifact digest equals
   `16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec`.
3. Extract to a fresh runtime workspace. Verify every packaged file against root `SHA256SUMS`; reject any
   missing, extra-required, or mismatched package member.
4. Verify `metadata/command-boundary.txt` records `runtimeExecution=false` and the source package identifies exact
   source `098ac7d93ea203222dd0ac50cdb68667744f0fd4`.
5. Extract the immutable packaged source and verify selector authority from LF-normalized bytes:
   - selector407: **407** non-empty identities, hash
     `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`;
   - selector406: **406** identities, hash
     `efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`;
   - selector406 is the exact 406-line prefix of selector407;
   - selectors 405/403/401/397/365 retain their frozen prefix relationships from
     `Required_Green_Selector_Manifest.md`.
6. Build an **identity map without executing a Directional binary**, using the packaged source exactly as the
   existing artifact-only harness does in `.agents/Directional/tools/m3_cp4c3_tb23_r1_harness.sh`: parse the
   selector, `cmake/DirectionalTests.cmake`, and source `TEST*` declarations; require exactly one compiled binary
   owner for every one of the 407 identities. Do not use generated test discovery or `--gtest_list_tests`.
7. Materialize the execution view exactly from immutable package/source bytes. Fixtures may be copied only from the
   packaged source according to the frozen sibling `test-data` consumer rule. Record pre-runtime package, packaged
   source, and execution-view byte+mode censuses.
8. Record mutation flags before runtime. They must all be false: configure, compile, relink, package repair, mode
   repair, generated discovery, source/test/fixture/selector mutation, and benchmark execution.

Any failure in steps 1–8 is **orchestration failure, not semantic evidence**. Set `runtime_started=false`, preserve
raw evidence, and stop without executing a Directional binary.

## 3. Runtime execution

Execute **all 407 selector identities exactly once, in selector order, one identity per fresh process**. For each
row use the binary from the static identity map and the exact invocation shape:

```sh
(cd "$fresh_workdir" && "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity") >"$raw_log" 2>&1
```

Requirements per ordinal:

- fresh process and fresh per-identity working directory;
- exactly one test selected;
- preserve raw stdout/stderr and exit code;
- classify exit 0 as PASS and nonzero as RED without retrying or changing the filter;
- do not stop at the first semantic RED — TB27 authority is already a mixed PASS/RED selector and TB28 needs the
  later diagnostic identities as evidence;
- retain the frozen 180-second per-process timeout used by prior artifact-only CP4c-3 gates.

No benchmark is authorized in TB28; `directional_benchmarks` is present only because it is part of the immutable
Code + Build package contract.

## 4. Required ledger and evidence

Produce an ordered ledger with at least:

`ordinal, identity, binary, exit, selected, result, raw_log`.

Require **407/407 rows** and one exact selection per row. Preserve:

- ledger and SHA-256;
- identity map and SHA-256;
- per-ordinal raw logs;
- semantic summary with PASS/RED totals, RED ordinals, and accepted-prefix count for ordinals 1–365;
- the complete runtime publication for ordinals **404, 406, and 407** and any earlier identity that emits the same
  failing-plan/component diagnostic;
- pre/post package, packaged-source, and execution-view censuses;
- orchestration/runtime boundary flags and resource evidence.

Postflight must prove the immutable package, packaged source, selector, fixtures, and execution view did not change.

## 5. CL6 / CL7 adjudication fields to extract without reinterpretation

From the raw runtime publication, record verbatim/typed values sufficient to answer:

1. for every interior arc in the certifier census: arc id, forward/reverse face-walk orbit, every crossed source
   face, truncation state, the source face's `NotTraceCut` component id, its `EmptyFragmentOrbits` component id, and
   typed trace-cut miss reason;
2. the same crossed-face/component/miss-reason fields for every interior arc of the **failing plan component**;
3. failing-plan and certifier component identities, domains, face-set digests, equality, and **subset/containment**
   relation.

Do not infer a missing typed miss reason from source code or convert absent publication into a chosen branch.

## 6. Acceptance and stop rules

A **valid TB28 semantic run** requires all orchestration/postflight integrity gates to pass and all 407 identities to
execute exactly once. The selector may remain semantically RED; RED does not invalidate the run.

Additional diagnostic integrity requirements:

- ordinals 404/406/407 must execute and publish their complete frozen evidence contracts;
- no truncation may hide a CL6 crossed-face row;
- a runtime-false containment/subset relation refutes the static containment premise and must be surfaced to review
  as such;
- missing/ambiguous CL6 publication is preserved as such and routes to review under CL8's **barrier-set default**;
- accepted-prefix safety is reported independently: any new RED in ordinals 1–365 is an accepted regression and
  must be entered in `Regression_Root_Cause_Tracker.md` before TB28 closes.

Do **not** rerun unchanged semantic failures, widen/narrow the selector, repair fixtures, regenerate expected data,
or mutate the package to obtain a cleaner result. An orchestration-only failure may be retried only after preserving
its first actionable evidence and only with a harness/control-plane correction that cannot affect semantic bytes.

## 7. TB28 closeout and mandatory route

TB28 must update `Regression_Root_Cause_Tracker.md` for every observed RED/candidate, record whether stable totals
change, and retain an artifact-only report with exact source/package/run/result/log/ledger identities.

After one valid semantic TB28 run, route to **`M3-CP4c-3-TB28-INDEPENDENT-REVIEW`**. That review must consume the
CL6/CL7 evidence and freeze exactly one product-correction plan:

- **barrier-set correction** if a separating interior arc inside the failing component crosses a source face;
- **attribution-rule correction** if no such separating interior arc crosses a source face and the frozen
  attribution evidence decides the failure;
- **barrier-set correction by default** if the measured census is ambiguous/incomplete under CL8;
- explicitly adjudicate a runtime-refuted containment/subset premise if observed.

The review may not answer "insufficient evidence" by authorizing another standalone diagnostic turn.
