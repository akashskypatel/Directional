# RA-171 — TB50-REV gate closeout; TB50C census observe contract (2026-10-29)

**Turn:** `M6-CP3-TB50-RP01-FULL-GATE-REV` (TB-REV, Review track). **Disposition: COMPLETE.** TB50-R2 508/0 is an independently verified candidate. TB50C S5 is a Review design defect in the RA-170 census freeze, not an implementation error; this record authorizes exact harness patch P7 and re-freezes the census manifest. **Exact successor:** `M6-CP3-CB50C-RP01-CENSUS-HARNESS-ORCH`.

## RA-171.1 Code review — CB50 → CB52

- `128ad9665` (RA-170) + P3 → P4 → P5 → P6, extracted from RA-169.10/.11 and RA-170.7/.8 (SHAs `9874d126…`, `c8af43a2…`, `a610f39b…`, `9f538bc2…`), is **byte-identical** to HEAD for `SurfaceCellTracing.cpp`, `SurfaceCellTransitionQuotientTests.cpp` and `SurfaceCellsPhase10Tests.cpp`. No other `src`, `tests`, `include`, CMake, fixture or harness byte changed since RA-170. CB52 source `7cf0857b4818` equals HEAD on all of those paths.
- CB50A (rows 505–508 `asserted_site` → `-`) is semantically sound. In this harness a GUARD must carry `-`, and a POSITIVE pin is consulted only when that row is RED. The rejection sites stay asserted inside the tests (P3 `firstPredicate=orphan-hard-feature-edge`, P4 `open-rail-cover`, P6 site pins), so a PASS still proves them. The defect was mine: RA-169/170 froze site text the harness schema forbids.

## RA-171.2 TB50-REV — TB50-R2 independently verified

- Result artifact `12929917136`: provider digest and downloaded ZIP `663fa4e1…` match; `SHA256SUMS` **1022/1022**, no unlisted files.
- `execution-boundary.json`: planned = executed = passed = 508; red, missing, skipped, duplicate, control_bad, unexpected_pass, later_positive_red, red_site_bad all 0; postflight true; exit 0; source `7cf0857b…`; package `12918290481`.
- Manifest `eef8855e…` ↔ ledger ↔ raw log: **508/508** joins on row/kind/identity/test/binary and log digest; every log has exactly one RUN (its own test) and one OK. Rows 283/445 (macOS-only REDs) and 505–508 (P3–P5 witnesses) PASS on CI.
- **Verdict:** TB50-R2 508/0 accepted as the reviewed RP-01 candidate gate. No CP3 acceptance or selector promotion (that waits for PLAN-RP01-CLOSURE). Stable 66/17/49, debt 1, unchanged.
- **Re-scope:** RA-170 had TB50-REV also adjudicate TB50C. That is dropped: per-row census adjudication *is* the disposition DEFN's job, so a second review of the census would duplicate it.

## RA-171.3 TB50C S5 — root cause (Review defect, two parts)

1. **Names.** The harness `TEST` regex accepts only `Suite.Test`; census rows 360–365 are value-parameterized (`UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/<Param>`). Even if the name passed, a parameterized RED would classify INVALID: gtest prints `[  FAILED  ] <name>, where GetParam() = 16-byte object <…>` (local gtest probe, real `DesignAcceptanceCase` shape), which the exact-line filter drops.
2. **Semantics** (flagged statically by the TB50C report; confirmed). Every census row was `GUARD/PASS`, and a GUARD RED is `unexpected-control-failure`. With 101/408 local REDs, the census would have run to completion and then exited 90, inviting a second S5 on evidence that is exactly what the census exists to collect.

Process cause: I froze both the TB50 and TB50C manifests without running the harness `--self-check` on them. **Rule (RA-171):** the Review runs `--self-check` (and `--self-test` on any harness patch) before freezing a manifest.

## RA-171.4 Census contract — `OBSERVE` kind (P7)

- **Names:** accept exactly `Suite.Test` or `Prefix/Suite.Test/Param` (identifier prefix/suite/test, `[A-Za-z0-9_]+` param). Typed tests, wildcards, `:` and `-` stay rejected. Terminal FAILED lines are normalized by dropping timing-suffixed lines and the `, where GetParam() = …` suffix; a timing line alone is not a verdict.
- **Kind `OBSERVE`** (`expect=OBSERVE`, `asserted_site=-`). A manifest is all-OBSERVE or has no OBSERVE (`OBSERVE rows mixed with gate rows`), so a census kind can never dilute a gate.
- **Verdicts for OBSERVE rows:** PASS and RED as for gates; **ABNORMAL** when the selected test ran exactly once, unskipped, without a PASS or RED terminal (crash, 600 s timeout, verdict-less exit). ABNORMAL is counted in the new `abnormal` state key and is not `missing`. **INVALID** (zero, wrong or duplicate RUN, or SKIPPED) still counts as missing and fails the run.
- **Exit:** 0 iff all 408 are selected and executed once with postflight intact, whatever the PASS/RED/ABNORMAL mix. Gate kinds keep their old classification and controls (self-test asserts a GUARD RED still fails).
- **Probe evidence:** patched `--self-test` → `SELF_TEST_PASS cases=21` (was 12). `--self-check` passes on TB49 (504), TB50 (508) and the re-frozen TB50C (408). The unpatched harness rejects the new manifest (`unknown kind 'OBSERVE'`), so a mismatched pairing fails closed. On real gtest logs: param PASS → PASS; ASSERT and uncaught exception → RED (`p.cpp:10: Failure` / `unknown file: Failure`); `abort()` (exit 134) → ABNORMAL under OBSERVE and INVALID under GUARD; plain RED unchanged.
- **Re-frozen census:** `Architecture_M6_CP3_TB50C_Off_Gate_Census_Case_Manifest.tsv`, SHA-256 `918239009ddee28ebc5c212ef3db0babf2b9f2b8a2755f4321242b7a1ea2ac86` (was `800e7f26…`). Only `kind` and `expect` changed (GUARD/PASS → OBSERVE/OBSERVE); all 408 row, identity, test and binary cells are identical.
- **Harness after P7:** SHA-256 `600c6455203519e79736e501288e4777921390bf365a9d3ee5e0141aa49275f8` (was `142321061c57…`).

## RA-171.5 Trajectory

RP-01 must not close while tests in the gate binaries sit outside the gate. Target for TB51: every test in the four gate binaries is either gated or retired by the disposition DEFN with a stated reason, so TB51 = 508 + (408 − retired). The census is observation only. It adds no stable regression until the DEFN classifies each RED/ABNORMAL as stale oracle, regression, O2 legacy, platform or retire, grouping rows by shared first failure (one CB per group).

## RA-171.6 Turn sequence and outcome tables

| # | Turn | Type / track | Gate |
|---|---|---|---|
| 1 | `M6-CP3-CB50C-RP01-CENSUS-HARNESS-ORCH` | CB / I | Exact P7; offline self-test + three self-checks; no native run |
| 2 | `M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC-R2` | TB-EXEC / I | Same CB52 package; harness `600c6455…`; manifest `91823900…`; 408; observe |
| 3 | `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` | DEFN / R | Classify every non-PASS row; exact patches; freeze TB51 manifest |
| 4 | CB53… (one per cause group) → `M6-CP3-TB51-RP01-FULL-GATE-EXEC` → `M6-CP3-TB51-RP01-FULL-GATE-REV` | CB, TB-EXEC / I; TB-REV / R | TB51 per RA-171.5 |
| 5 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN / R | O6 scope; O7–O12 owners |

**CB50C** — extract the RA-171.7 `~~~diff` block verbatim (with trailing newline). Its SHA-256 must be `9c30f6b622a43c0d487bb2d62097aad9105e8c5991e3ca9895e7c49f032004f0`; `git apply` it with no hand edits. Numstat must be exactly `71 8 .agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, and the harness SHA-256 must then be `600c6455…`. Run `bash -n`, then `--self-test` → `SELF_TEST_PASS cases=21`. Run `--self-check` on the TB49 manifest with 504, the TB50 manifest with 508 and the TB50C manifest with 408, each printing `SELF_CHECK_PASS cases=<n>`; verify the TB50C manifest SHA `91823900…` first.
- All exact → TB50C-EXEC-R2.
- Patch, SHA or self-test mismatch → `M6-CP3-PLAN-RP01-CENSUS-HARNESS-STOP` (PLAN, R).
- Orchestration failure → `M6-CP3-CB50CA-RP01-ORCH` → retry CB50C.

**TB50C-EXEC-R2** — dispatch with the RA-170 package environment (`12918290481`, ZIP `89449f4f…`, root `6ae4eb5b…`, source archive `c02a0be4…`, source `7cf0857b…`), `harness_sha256=600c6455…`, `CASE_MANIFEST_SHA256=91823900…`, `EXPECTED_CASE_COUNT=408`. Report PASS/RED/ABNORMAL counts per binary and suite, plus each non-PASS row's `first_failure` and `typed_reason`. **No prediction, classification or repair.**
- Postflight true and 408 ledger rows → COMPLETE → DEFN disposition, whatever the exit code. INVALID rows are disposition input.
- No result artifact, preflight error, or job cancelled (the runner job has no `timeout-minutes`, so GitHub's 6 h cap applies; TB50-R2 took 47 min for 508) → `M6-CP3-PLAN-RP01-CENSUS-HARNESS-STOP` (PLAN, R) to shard the manifest. Do not re-dispatch an identical request.

## RA-171.7 Exact patch P7 — census observe contract

SHA-256 of the block body `9c30f6b622a43c0d487bb2d62097aad9105e8c5991e3ca9895e7c49f032004f0`; numstat `71 8`.

~~~diff
diff --git a/.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh b/.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh
index 10247a55d..e4bda53f2 100755
--- a/.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh
+++ b/.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh
@@ -31,13 +31,16 @@ import shutil
 import subprocess
 import sys
 import tarfile
+import tempfile
 
 MODE, MANIFEST_ARG, COUNT_ARG = sys.argv[1:]
 HEADER = ['row', 'kind', 'identity', 'test', 'binary', 'expect', 'asserted_site']
-KINDS = {'NEGATIVE', 'POSITIVE', 'GUARD', 'RED'}
+KINDS = {'NEGATIVE', 'POSITIVE', 'GUARD', 'RED', 'OBSERVE'}
 HEX64 = re.compile(r'[0-9a-f]{64}\Z')
 HEX40 = re.compile(r'[0-9a-f]{40}\Z')
-TEST = re.compile(r'[A-Za-z_][A-Za-z0-9_]*\.[A-Za-z_][A-Za-z0-9_]*\Z')
+# Plain Suite.Test, or value-parameterized Prefix/Suite.Test/Param.
+NAME = r'[A-Za-z_][A-Za-z0-9_]*'
+TEST = re.compile(rf'(?:{NAME}\.{NAME}|{NAME}/{NAME}\.{NAME}/[A-Za-z0-9_]+)\Z')
 BIN = re.compile(r'[A-Za-z0-9_-]+\Z')
 PIN = re.compile(r'([A-Za-z_][A-Za-z0-9_]*\.cpp):([1-9][0-9]*)\|([^\r\n|]+)\Z')
 
@@ -71,7 +74,7 @@ def read_cases(path, count):
         require(bool(identity.strip()) and identity == identity.strip(), f'row {index}: invalid identity')
         require(bool(TEST.fullmatch(test)), f'row {index}: invalid gtest name')
         require(bool(BIN.fullmatch(binary)) and binary not in {'.', '..'}, f'row {index}: invalid binary')
-        require(expect == ('RED' if kind == 'RED' else 'PASS'), f'row {index}: invalid expectation')
+        require(expect == (kind if kind in {'RED', 'OBSERVE'} else 'PASS'), f'row {index}: invalid expectation')
         require(bool(site) and ('\n' not in site and '\r' not in site), f'row {index}: invalid site')
         if kind == 'RED' or (kind == 'POSITIVE' and identity != 'selector:174' and site != '-'):
             require(PIN.fullmatch(site) is not None, f'row {index}: malformed or missing asserted-site pin')
@@ -86,6 +89,8 @@ def read_cases(path, count):
         require(test not in tests, f'row {index}: duplicate test {test}')
         identities.add(identity)
         tests.add(test)
+    # A census observes; it must never dilute a gate's PASS/RED controls.
+    require(len({case[1] == 'OBSERVE' for case in cases}) == 1, 'OBSERVE rows mixed with gate rows')
     return cases
 
 # Preserve all completed execution evidence even when a later gate fails.
@@ -145,6 +150,8 @@ def matches_registered_first_failure(text, registered):
 def control_failure(kind, identity, verdict, data, site):
     if verdict == 'INVALID':
         return 'invalid-execution'
+    if kind == 'OBSERVE':
+        return None  # PASS, RED and ABNORMAL are all census evidence.
     if kind == 'RED':
         if verdict == 'PASS':
             return None  # Unexpected improvement is reported, not hidden.
@@ -161,14 +168,18 @@ def control_failure(kind, identity, verdict, data, site):
         return None  # Keep verdict RED and raw evidence unchanged.
     return 'unexpected-control-failure'
 
-def classify_case(text, test, code):
+def classify_case(text, test, code, observe=False):
     run_names = re.findall(r'(?m)^\[ RUN      \] ([^\r\n]+)', text)
     ok_names = re.findall(r'(?m)^\[       OK \] ([^\r\n]+)', text)
     skipped = len(re.findall(r'(?m)^\[  SKIPPED \] ', text))
     failed_lines = re.findall(r'(?m)^\[  FAILED  \] ([^\r\n]+)', text)
     # Only exact, unadorned per-test lines are terminal verdicts; ignore
     # GoogleTest's summary counts and decorated per-test timing lines.
-    terminal_tests = [value for value in failed_lines if TEST.fullmatch(value)]
+    # Value-parameterized failures append ", where GetParam() = <value>".
+    terminal_tests = [name for name in (value.split(', where GetParam() = ', 1)[0]
+                                        for value in failed_lines
+                                        if not re.search(r' \([0-9]+ ms\)\Z', value))
+                      if TEST.fullmatch(name)]
     run = len(run_names)
     passed = len(ok_names)
     if (code == 0 and run_names == [test] and passed == 1 and
@@ -178,6 +189,10 @@ def classify_case(text, test, code):
     elif (code == 1 and run_names == [test] and not ok_names and
           skipped == 0 and terminal_tests == [test]):
         verdict = 'RED'
+    elif observe and run_names == [test] and skipped == 0:
+        # A census keeps crashes, timeouts and verdict-less exits of the
+        # selected test as evidence; selection failures stay INVALID.
+        verdict = 'ABNORMAL'
     else:
         verdict = 'INVALID'
     return verdict, run, passed, skipped
@@ -208,6 +223,8 @@ def self_test():
          1, 'RED', 'code=17;sourceAuthoritySite=valid'),
         ('no-typed', run + header + 'assertion failed without typed data\n' + fail,
          1, 'RED', 'reason-not-observed'),
+        ('red-timed', run + header + '[  FAILED  ] Suite.Case (0 ms)\n'
+         '[  FAILED  ] 1 test, listed below:\n' + fail, 1, 'RED', 'reason-not-observed'),
     ]
     for name, data, code, expected_verdict, expected_reason in examples:
         verdict, _, _, _ = classify_case(data, test, code)
@@ -216,7 +233,52 @@ def self_test():
         require(reason == expected_reason, f'{name}: reason {reason}, expected {expected_reason}')
     require('site=early' not in failure_block(examples[10][1]), 'failure block leaks preamble')
     require(first_failure(examples[10][1]) == 'file.cpp:12: Failure', 'first failure leaks preamble')
-    print(f'SELF_TEST_PASS cases={len(examples)}')
+
+    param = 'P/Suite.Case/Param'
+    where = ', where GetParam() = 16-byte object <BE-06 8A-02>'
+    prun = f'[ RUN      ] {param}\n'
+    ptimed = f'[  FAILED  ] {param}{where} (0 ms)\n'
+    param_examples = [
+        ('param-pass', prun + f'[       OK ] {param} (0 ms)\n', 0, 'PASS'),
+        ('param-red', prun + header + ptimed + '[  FAILED  ] 1 test, listed below:\n' +
+         f'[  FAILED  ] {param}{where}\n', 1, 'RED'),
+        ('param-timed-only', prun + header + ptimed, 1, 'INVALID'),
+    ]
+    for name, data, code, expected_verdict in param_examples:
+        verdict, _, _, _ = classify_case(data, param, code)
+        require(verdict == expected_verdict, f'{name}: verdict {verdict}, expected {expected_verdict}')
+    for name in ('Suite.Case', param):
+        require(TEST.fullmatch(name) is not None, f'valid name rejected: {name}')
+    for name in ('P/Suite.Case', 'Suite.Case/Param', 'A/P/Suite.Case/Param', 'Suite.*',
+                 'Suite.Case:Other', 'P/Suite.Case/Pa-ram'):
+        require(TEST.fullmatch(name) is None, f'invalid name accepted: {name}')
+
+    observed = [('observe-red', examples[1], 'RED'), ('observe-crash', examples[2], 'ABNORMAL'),
+                ('observe-timeout', examples[3], 'ABNORMAL'), ('observe-skip', examples[4], 'INVALID'),
+                ('observe-zero-run', examples[5], 'INVALID')]
+    for name, (_, data, code, _, _), expected_verdict in observed:
+        verdict, _, _, _ = classify_case(data, test, code, observe=True)
+        require(verdict == expected_verdict, f'{name}: verdict {verdict}, expected {expected_verdict}')
+        expected_violation = 'invalid-execution' if verdict == 'INVALID' else None
+        require(control_failure('OBSERVE', 'census', verdict, data, '-') == expected_violation,
+                f'{name}: wrong census control result')
+    require(control_failure('GUARD', 'gate', 'RED', examples[1][1], '-') ==
+            'unexpected-control-failure', 'gate RED no longer fails its control')
+
+    with tempfile.TemporaryDirectory() as scratch:
+        path = Path(scratch) / 'cases.tsv'
+        rows = [HEADER, ['1', 'OBSERVE', 'census:1', param, 'bin', 'OBSERVE', '-'],
+                ['2', 'GUARD', 'gate:2', test, 'bin', 'PASS', '-']]
+        path.write_text(''.join('\t'.join(row) + '\n' for row in rows))
+        try:
+            read_cases(path, 2)
+        except ValueError as error:
+            require('mixed' in str(error), f'mixed manifest: unexpected error {error}')
+        else:
+            raise ValueError('mixed OBSERVE/gate manifest accepted')
+        path.write_text(''.join('\t'.join(row) + '\n' for row in rows[:2]))
+        require(len(read_cases(path, 1)) == 1, 'OBSERVE-only manifest rejected')
+    print(f'SELF_TEST_PASS cases={len(examples) + len(param_examples) + len(observed)}')
 
 if MODE == 'self-test':
     try:
@@ -239,7 +301,7 @@ OUT = Path(str(ROOT) + '-result')
 (OUT / 'raw').mkdir(parents=True, exist_ok=True)
 (OUT / 'resources').mkdir(parents=True, exist_ok=True)
 ROOT.mkdir(parents=True, exist_ok=True)
-state = dict(planned=0, executed=0, passed=0, red=0, missing=0,
+state = dict(planned=0, executed=0, passed=0, red=0, abnormal=0, missing=0,
              skipped=0, duplicate=0, control_bad=0, unexpected_pass=0,
              later_positive_red=0, red_site_bad=0, postflight=False)
 rows = []
@@ -343,10 +405,11 @@ try:
                 stream.flush()
                 code = 124
         data = log.read_text(errors='replace')
-        verdict, run, passed, skipped = classify_case(data, test, code)
+        verdict, run, passed, skipped = classify_case(data, test, code, kind == 'OBSERVE')
         state['executed'] += int(run == 1 and skipped == 0)
         state['passed'] += int(verdict == 'PASS')
         state['red'] += int(verdict == 'RED')
+        state['abnormal'] += int(verdict == 'ABNORMAL')
         state['skipped'] += skipped
         state['missing'] += int(verdict == 'INVALID')
         state['duplicate'] += int(run > 1)
~~~
