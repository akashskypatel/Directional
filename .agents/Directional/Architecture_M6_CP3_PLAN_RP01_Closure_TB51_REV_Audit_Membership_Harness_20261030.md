# RA-174 — TB51-REV audit; RP-01 closure plan; gate membership harness P8 (2026-10-30)

This record covers two Review turns: an audit of `M6-CP3-TB51-RP01-FULL-GATE-REV` (RA-173, performed on the implementation track) and `M6-CP3-PLAN-RP01-CLOSURE` (PLAN, Review). It amends RA-172.5.

## RA-174.1 TB51 independently re-verified

- Result `12963899691`: ZIP `e6339e12…`; 1,668/1,668 internal checksums; boundary 831/831 PASS, postflight true, no compile.
- **Joins:** all 831 manifest rows join the ledger on row, kind, identity, test and binary.
- **Logs:** every row has `verdict=PASS`, `exit=0` and a log whose SHA matches. Each log has exactly one `[ RUN ]` and one `[ OK ]` for its own test, `[  PASSED  ] 1 test.`, and no `FAILED`.
- **Determinism:** each of the 323 promoted rows now has passed twice on the same package. The slowest case is row 795 (CloseSheets) at 296 s.
- RA-173's evidence claims are accurate.

## RA-174.2 Findings

- **F1 — the gate's scope is narrower than the packaged tests (major).** RA-172.3 and RA-173 call 916 tests the complete inventory, but it covers only four binaries.
  - The CB52 package also ships `bin/directional_compiled_api_tests`, a default-built gtest target (23 tests). No CP3 gate or census has ever run it.
  - `directional_surface_cell_oracle_tests` (29 tests, O7) is default-built but does not compile, so it is not packaged.
  - Within the four binaries the claim holds. Source declarations equal gate ∪ ledger exactly: producer 606 (including six `TEST_P` instances), authority kernel 39, completion 187, validation 84.
  - Cause: membership is asserted by Review, and nothing executes it. Fixed by P8 (RA-174.4).
- **F2 — RP-01's footprint is already green.** All **497/497** selector497 identities are in TB51 and passed, and so does the `G4-B002` exit row (one of `focused30:25–28`). RA-173 lists "RP-01 open" without saying what remains.
- **F3 — RA-172.5 is mis-scoped (Review defect).** RP-01 is the rail-endpoint admission contract (RA-81/84/85/87: T/R/I endpoints, terminal and nonterminal A3 side paths, A2b rail provenance, checked-factory rail cover). P13 (design acceptance) and P12b (produced-invariant tests) are **CP3-exit** obligations, not RP-01 blockers. Corrected in RA-174.3.
- **Design-acceptance status.** The producer-gate contract (`cmake/DirectionalTests.cmake`) names plane, multi-face seam, close-sheet and periodic cylinder as the deliberate acceptance matrix. Plane, MultiFaceSeam and CloseSheets now pass. **Cylinder** (600 s timeout), Vase (timeout) and BunnyRandom (A3 cut Euler identity) are P13, which is CP3's product-critical path.

## RA-174.3 RP-01 closure plan (amends RA-172.5)

- **RP-01 blockers:** deferred rows whose subject is the RP-01 contract.
  - 223 `CheckedFactoryRejectsForgedTerminalA2bSideGerm`.
  - 225 `TerminalRailContactPathsUseTypedSourceStarA3`: its oracle predates the RA-84 R/I endpoint classes.
  - 261 `MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate`.
  - The ruling on **O9** (A4 junction path has no produced witness; it owns `missing-terminal-A3-path`).
- **RP-01 closes** when a reviewed gate passes 223, 225 and 261, repaired without weakening any assertion, and O9 is either witnessed or removed with a reason.
- **CP3 (M6 exit) requires all of:**
  - RP-01 closed.
  - Zero ledger rows: each one is repaired into the gate or retired by a CB.
  - The design-acceptance matrix gated at 6/6.
  - O14 enforced by P8 on every gate run.
  - O7 resolved: the oracle binary is compiled, packaged and governed, or its target is removed with a reason.
  - The `G4-B002` exit row gated (already met).
  - CP3-REV decides selector497 promotion and stable accounting.
- **O-item owners:**
  - O6 (bounded disks that are not rectangular are rejected by design) → the P13 probe DEFN, because Vase and Bunny are such inputs.
  - O7 → its own probe DEFN.
  - O8 and O10 → CP3-exit probe DEFNs after P13.
  - O9 → the RP-01 slice.
  - O12 → Review tooling, no CP3 effect.
  - O14 → P8.
- **Repair-slice rule:** before repairing a FIXTURE group, its DEFN confirms that the production pipeline reaches the stage under test. If it does not, the group moves to O2 legacy retirement and is not repaired.

## RA-174.4 Patch P8 — gate membership preflight (O14)

The patch is harness-only, and the workflow already passes any extra environment key through to the harness.

- **Gate runs (any non-`OBSERVE` manifest) must set `MEMBERSHIP_LEDGER` and `MEMBERSHIP_LEDGER_SHA256`.** A census run must not set them.
- **Ledger checks:** the ledger is read with the RA-172 header. It must contain valid names and classes, no duplicate tests, and no test that is also gated.
- **Listing check, after staging:** every packaged `bin/*_tests` executable runs `--gtest_list_tests`. The parser skips the `gtest_main` preamble, strips `  # GetParam()` and `TypeParam` notes, and includes `DISABLED_` tests. Typed suites fail closed.
- **Fail-closed conditions:** the run fails before any case executes if any of these holds:
  - the set of packaged test binaries differs from the binaries named in manifest ∪ ledger;
  - any listed test is ungoverned;
  - any governed test is stale (not listed).
- **Outputs:** `membership.tsv` (binary, test, GATED/DEFERRED) is written into the result, and `state.membership` holds its count.
- **`--self-check <manifest> <n> [<ledger>]`** also validates the ledger offline.

**Effect:** after P8, TB51 cannot be re-run with the 85-row ledger, because `directional_compiled_api_tests` is ungoverned. This is intended. TB52 is the first gate that P8 can pass.

**Probe evidence (local, diagnostic):**
- Real `--gtest_list_tests` output from a googletest probe build (`gtest_main`, named `TEST_P` instances, `DISABLED_`) parses exactly.
- `bash -n` OK; `--self-test` → `SELF_TEST_PASS cases=30`.
- Self-checks pass: TB49 504, TB50 508, TB50C 408 and TB51 831; TB51 with the ledger prints `SELF_CHECK_PASS cases=831 deferred=85`; TB50C with the ledger prints `SELF_CHECK_FAIL a census takes no deferred ledger`.
- Seven mutations (dropping the preamble skip, keeping the parameter note, and removing the stale, ungoverned, binary-set, overlap or census check) each make the self-test fail.
- **Hashes:** patch SHA-256 `80ee9e4275f4a1276cddabaa948782e886fe5cd76330c3fc801b67258d578fe8`, numstat `136 13`; resulting harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.

## RA-174.5 TB52C census manifest (frozen)

[`Architecture_M6_CP3_TB52C_API_Binary_Census_Case_Manifest.tsv`](Architecture_M6_CP3_TB52C_API_Binary_Census_Case_Manifest.tsv): SHA-256 `81395065279e6ae6590c6feea30b719d661a328ecd90bea7ad8ef0f3a3a474ed`.
- 23 `OBSERVE` rows for `directional_compiled_api_tests`, in source order, with identity `apicensus:<n>`.
- Built from source declarations, the same method that matched the four gate binaries exactly.
- Both the current harness and the P8 harness self-check it at 23.

## RA-174.6 Turn sequence and outcome tables

| # | Turn | Type / track | Gate |
|---|---|---|---|
| 1 | `M6-CP3-CB53-RP01-GATE-MEMBERSHIP-PREFLIGHT` | CB / I | Exact P8; offline checks only |
| 2 | `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-EXEC` | TB-EXEC / I | CB52 package, harness `78b8002c…`, manifest `81395065…`, 23 OBSERVE rows |
| 3 | `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-REV` | TB-REV / R | Disposition of the 23; freeze the TB52 gate (831 + PASS rows) and ledger v2 |
| 4 | `M6-CP3-TB52-RP01-FULL-GATE-EXEC` → `-REV` | TB-EXEC / I; TB-REV / R | First run with membership over all five packaged test binaries |
| R∥ | `M6-CP3-DEFN-RP01-TERMINAL-PATH-WITNESSES` → CB54 → TB53 → TB53-REV | DEFN / R; CB, TB / I; TB-REV / R | Probe and repair 223, 225 and 261, plus the O9 ruling; RP-01 closes at TB53-REV |
| then | P13 probe DEFN (Cylinder first; O6) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) | per slice | Each slice moves its rows from the ledger to the gate; CP3-REV comes last |

**CB53 checks:**
- Extract the RA-174.7 `~~~diff` block verbatim, adding a trailing newline. Its SHA-256 must be `80ee9e42…`.
- Apply it with `git apply`; numstat must be exactly `136 13`, and the harness SHA-256 must then be `78b8002c…`.
- `bash -n` passes; `--self-test` → `SELF_TEST_PASS cases=30`.
- `--self-check` passes for TB49 504, TB50 508, TB50C 408, TB51 831 and TB52C 23.
- `--self-check` on TB51 831 with the ledger → `cases=831 deferred=85`. TB50C 408 with the ledger must FAIL.

| CB53 result | Successor |
|---|---|
| All exact | TB52C-EXEC |
| Patch, SHA or self-test mismatch | `M6-CP3-PLAN-RP01-MEMBERSHIP-STOP` (PLAN, R) |
| Dispatcher or apply failure | `M6-CP3-CB53A-RP01-ORCH` (CB, I), then retry |

**TB52C-EXEC.** Dispatch with the RA-170 package environment (`12918290481`, ZIP `89449f4f…`, root `6ae4eb5b…`, source archive `c02a0be4…`, source `7cf0857b…`) and these values:
- `harness_sha256=78b8002c…`
- `CASE_MANIFEST=.agents/Directional/Architecture_M6_CP3_TB52C_API_Binary_Census_Case_Manifest.tsv`
- `CASE_MANIFEST_SHA256=81395065…`
- `EXPECTED_CASE_COUNT=23`
- **no** `MEMBERSHIP_LEDGER`

Report PASS/RED/ABNORMAL counts and each non-PASS `first_failure`. Make no classification.

| TB52C result | Successor |
|---|---|
| Postflight true with 23 ledger rows | TB52C-REV |
| Preflight error or no artifact | `M6-CP3-PLAN-RP01-MEMBERSHIP-STOP` |
| Dispatcher failure before the harness starts | CB53A-ORCH, then one retry |

## RA-174.7 Exact patch P8

~~~diff
diff --git a/.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh b/.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh
index e4bda53..8274cc3 100755
--- a/.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh
+++ b/.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh
@@ -1,25 +1,28 @@
 #!/usr/bin/env bash
 set -euo pipefail
-if [[ "${1:-}" == "--self-check" && "$#" -eq 3 ]]; then
+if [[ "${1:-}" == "--self-check" && ( "$#" -eq 3 || "$#" -eq 4 ) ]]; then
   mode=self-check
   manifest_arg=$2
   count_arg=$3
+  ledger_arg=${4:-}
 elif [[ "${1:-}" == "--self-test" && "$#" -eq 1 ]]; then
   mode=self-test
   manifest_arg=''
   count_arg=''
+  ledger_arg=''
 elif [[ "${1:-}" == "--execute" && "$#" -eq 1 ]]; then
   mode=execute
   manifest_arg=''
   count_arg=''
+  ledger_arg=''
   : "${RUNNER_TEMP:?}"
   : "${TURN_ID:?}"
   exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
 else
-  echo 'usage: harness --self-check <case-manifest.tsv> <expected-count> | --self-test | --execute' >&2
+  echo 'usage: harness --self-check <case-manifest.tsv> <expected-count> [<deferred-ledger.tsv>] | --self-test | --execute' >&2
   exit 64
 fi
-python3 - "$mode" "$manifest_arg" "$count_arg" <<'PY'
+python3 - "$mode" "$manifest_arg" "$count_arg" "$ledger_arg" <<'PY'
 import csv
 import hashlib
 import json
@@ -33,9 +36,12 @@ import sys
 import tarfile
 import tempfile
 
-MODE, MANIFEST_ARG, COUNT_ARG = sys.argv[1:]
+MODE, MANIFEST_ARG, COUNT_ARG, LEDGER_ARG = sys.argv[1:]
 HEADER = ['row', 'kind', 'identity', 'test', 'binary', 'expect', 'asserted_site']
 KINDS = {'NEGATIVE', 'POSITIVE', 'GUARD', 'RED', 'OBSERVE'}
+LEDGER_HEADER = ['census_row', 'identity', 'test', 'binary', 'verdict', 'exit', 'group', 'class',
+                 'first_failure']
+CLASSES = {'FIXTURE', 'PRODUCT', 'OPEN', 'RETIRE'}
 HEX64 = re.compile(r'[0-9a-f]{64}\Z')
 HEX40 = re.compile(r'[0-9a-f]{40}\Z')
 # Plain Suite.Test, or value-parameterized Prefix/Suite.Test/Param.
@@ -93,6 +99,61 @@ def read_cases(path, count):
     require(len({case[1] == 'OBSERVE' for case in cases}) == 1, 'OBSERVE rows mixed with gate rows')
     return cases
 
+# O14: every test a packaged *_tests binary lists is gated or deferred, never both.
+def read_ledger(path, cases):
+    require(cases[0][1] != 'OBSERVE', 'a census takes no deferred ledger')
+    with Path(path).open(newline='', encoding='utf-8') as stream:
+        reader = csv.reader(stream, delimiter='\t', strict=True)
+        require(next(reader, None) == LEDGER_HEADER, 'wrong deferred ledger header')
+        rows = list(reader)
+    gated = {case[3] for case in cases}
+    tests, entries = set(), []
+    for index, row in enumerate(rows, 1):
+        require(len(row) == len(LEDGER_HEADER), f'ledger row {index}: wrong column count')
+        test, binary, disposition = row[2], row[3], row[7]
+        require(bool(TEST.fullmatch(test)), f'ledger row {index}: invalid gtest name')
+        require(bool(BIN.fullmatch(binary)) and binary not in {'.', '..'}, f'ledger row {index}: invalid binary')
+        require(disposition in CLASSES, f'ledger row {index}: unknown class {disposition!r}')
+        require(test not in tests, f'ledger row {index}: duplicate test {test}')
+        require(test not in gated, f'ledger row {index}: also gated: {test}')
+        tests.add(test)
+        entries.append((test, binary))
+    return entries
+
+def list_tests(text):
+    names, suite = [], None
+    for line in text.splitlines():
+        if not line.strip() or (suite is None and line.startswith('Running main() from ')):
+            continue
+        head = line.split('  # ', 1)[0].rstrip()  # drop GetParam()/TypeParam notes
+        if not line.startswith(' '):
+            require(head.endswith('.') and len(head) > 1, f'unparsable listing line: {line!r}')
+            suite = head[:-1]
+            continue
+        require(suite is not None, 'listed test before its suite')
+        name = f'{suite}.{head.strip()}'
+        require(TEST.fullmatch(name) is not None, f'unsupported listed test: {name}')
+        names.append(name)
+    require(len(names) == len(set(names)), 'duplicate listed test')
+    return set(names)
+
+def membership(cases, ledger, listings):
+    governed = {}
+    for test, binary in [(case[3], case[4]) for case in cases] + ledger:
+        governed.setdefault(binary, set()).add(test)
+    require(set(listings) == set(governed),
+            f'ungoverned or unpackaged test binaries: {sorted(set(listings) ^ set(governed))}')
+    gated = {case[3] for case in cases}
+    members = []
+    for binary in sorted(listings):
+        listed = list_tests(listings[binary])
+        ungoverned = sorted(listed - governed[binary])
+        stale = sorted(governed[binary] - listed)
+        require(not ungoverned and not stale, f'{binary}: {len(ungoverned)} ungoverned '
+                f'{ungoverned[:3]}, {len(stale)} stale {stale[:3]}')
+        members += [[binary, test, 'GATED' if test in gated else 'DEFERRED'] for test in sorted(listed)]
+    return members
+
 # Preserve all completed execution evidence even when a later gate fails.
 def sha_manifest(path):
     result = []
@@ -278,7 +339,45 @@ def self_test():
             raise ValueError('mixed OBSERVE/gate manifest accepted')
         path.write_text(''.join('\t'.join(row) + '\n' for row in rows[:2]))
         require(len(read_cases(path, 1)) == 1, 'OBSERVE-only manifest rejected')
-    print(f'SELF_TEST_PASS cases={len(examples) + len(param_examples) + len(observed)}')
+
+    # Real --gtest_list_tests output (gtest_main, named TEST_P instances, DISABLED_).
+    listing = ('Running main() from src/gtest_main.cc\nPlain.\n  First\n  DISABLED_Off\nFix.\n  Third\n'
+               'U/Accept.\n  Out/Plane  # GetParam() = 16-byte object <D3-8D>\n'
+               '  Out/Seam  # GetParam() = 16-byte object <D9-8D>\n')
+    listed = {'Plain.First', 'Plain.DISABLED_Off', 'Fix.Third', 'U/Accept.Out/Plane', 'U/Accept.Out/Seam'}
+    require(list_tests(listing) == listed, 'gtest listing misparsed')
+    gate = [['1', 'GUARD', 'g:1', 'Plain.First', 'bin_tests', 'PASS', '-'],
+            ['2', 'GUARD', 'g:2', 'U/Accept.Out/Plane', 'bin_tests', 'PASS', '-']]
+    ledger = [('Plain.DISABLED_Off', 'bin_tests'), ('Fix.Third', 'bin_tests'), ('U/Accept.Out/Seam', 'bin_tests')]
+    states = {row[1]: row[2] for row in membership(gate, ledger, {'bin_tests': listing})}
+    require(states == {'Plain.First': 'GATED', 'U/Accept.Out/Plane': 'GATED', 'Plain.DISABLED_Off': 'DEFERRED',
+                       'Fix.Third': 'DEFERRED', 'U/Accept.Out/Seam': 'DEFERRED'}, 'membership states wrong')
+    rejected = [('ungoverned', gate, ledger[:2], {'bin_tests': listing}),
+                ('stale', gate, ledger + [('Fix.Gone', 'bin_tests')], {'bin_tests': listing}),
+                ('unpackaged', gate, ledger + [('Other.Case', 'other_tests')], {'bin_tests': listing}),
+                ('ungoverned-binary', gate, ledger, {'bin_tests': listing, 'new_tests': 'New.\n  Case\n'}),
+                ('typed-suite', gate, ledger, {'bin_tests': listing + 'T/0.  # TypeParam = int\n  Case\n'})]
+    for name, gate_rows, ledger_rows, listings in rejected:
+        try:
+            membership(gate_rows, ledger_rows, listings)
+        except ValueError:
+            pass
+        else:
+            raise ValueError(f'membership {name} accepted')
+    with tempfile.TemporaryDirectory() as scratch:
+        path = Path(scratch) / 'ledger.tsv'
+        entry = ['85', 'offgate:85', 'Fix.Third', 'bin_tests', 'RED', '1', 'P01', 'FIXTURE', '-']
+        path.write_text('\t'.join(LEDGER_HEADER) + '\n' + '\t'.join(entry) + '\n')
+        require(read_ledger(path, gate) == [('Fix.Third', 'bin_tests')], 'valid ledger rejected')
+        for name, bad_cases in (('overlap', gate + [['3', 'GUARD', 'g:3', 'Fix.Third', 'bin_tests', 'PASS', '-']]),
+                                ('census', [['1', 'OBSERVE', 'c:1', 'Plain.First', 'bin_tests', 'OBSERVE', '-']])):
+            try:
+                read_ledger(path, bad_cases)
+            except ValueError:
+                pass
+            else:
+                raise ValueError(f'ledger {name} accepted')
+    print(f'SELF_TEST_PASS cases={len(examples) + len(param_examples) + len(observed) + 1 + len(rejected) + 3}')
 
 if MODE == 'self-test':
     try:
@@ -290,7 +389,8 @@ if MODE == 'self-test':
 if MODE == 'self-check':
     try:
         cases = read_cases(MANIFEST_ARG, expected_count(COUNT_ARG))
-        print(f'SELF_CHECK_PASS cases={len(cases)}')
+        deferred = f' deferred={len(read_ledger(LEDGER_ARG, cases))}' if LEDGER_ARG else ''
+        print(f'SELF_CHECK_PASS cases={len(cases)}{deferred}')
     except Exception as error:
         print(f'SELF_CHECK_FAIL {error}', file=sys.stderr)
         sys.exit(1)
@@ -303,7 +403,7 @@ OUT = Path(str(ROOT) + '-result')
 ROOT.mkdir(parents=True, exist_ok=True)
 state = dict(planned=0, executed=0, passed=0, red=0, abnormal=0, missing=0,
              skipped=0, duplicate=0, control_bad=0, unexpected_pass=0,
-             later_positive_red=0, red_site_bad=0, postflight=False)
+             later_positive_red=0, red_site_bad=0, membership=0, postflight=False)
 rows = []
 exit_code = 90
 source_sha = ''
@@ -326,14 +426,24 @@ try:
     require(re.fullmatch(r'[A-Za-z0-9_.-]+/[A-Za-z0-9_.-]+', repo) is not None, 'invalid repository')
     token = os.environ['GH_TOKEN']
     workspace = Path(os.environ['GITHUB_WORKSPACE']).resolve()
-    relative_manifest = Path(values['CASE_MANIFEST'])
-    require(not relative_manifest.is_absolute() and '..' not in relative_manifest.parts, 'manifest must be repo relative')
-    case_path = (workspace / relative_manifest).resolve()
-    require(workspace in case_path.parents and case_path.is_file() and not case_path.is_symlink(), 'manifest missing/unsafe')
-    require(digest(case_path) == values['CASE_MANIFEST_SHA256'], 'case manifest checksum mismatch')
+
+    def repo_file(relative, sha256, label):
+        relative = Path(relative)
+        require(not relative.is_absolute() and '..' not in relative.parts, f'{label} must be repo relative')
+        path = (workspace / relative).resolve()
+        require(workspace in path.parents and path.is_file() and not path.is_symlink(), f'{label} missing/unsafe')
+        require(HEX64.fullmatch(sha256) is not None and digest(path) == sha256, f'{label} checksum mismatch')
+        return path
+
+    case_path = repo_file(values['CASE_MANIFEST'], values['CASE_MANIFEST_SHA256'], 'case manifest')
     cases = read_cases(case_path, expected_count(values['EXPECTED_CASE_COUNT']))
+    # A gate run must account for every packaged test (O14); a census never takes a ledger.
+    gate = cases[0][1] != 'OBSERVE'
+    require(gate == ('MEMBERSHIP_LEDGER' in os.environ), 'gate runs require MEMBERSHIP_LEDGER; censuses forbid it')
+    ledger = read_ledger(repo_file(os.environ['MEMBERSHIP_LEDGER'], os.environ.get('MEMBERSHIP_LEDGER_SHA256', ''),
+                                   'deferred ledger'), cases) if gate else []
     state['planned'] = len(cases)
-    print(f'PREFLIGHT cases={len(cases)} source={source_sha} artifact={artifact_id}', flush=True)
+    print(f'PREFLIGHT cases={len(cases)} deferred={len(ledger)} source={source_sha} artifact={artifact_id}', flush=True)
 
     api = f'https://api.github.com/repos/{repo}/actions/artifacts/{artifact_id}'
     curl = ['curl', '-fsSL', '-H', 'Authorization: Bearer ' + token]
@@ -379,6 +489,19 @@ try:
         deps_text = deps.stdout + deps.stderr
         require('not found' not in deps_text and 'libgmp' in deps_text, f'GMP dependency missing for {binary}')
         (OUT / f'dependencies-{binary}.txt').write_text(deps_text)
+    if gate:
+        listings = {}
+        for entry in sorted(view_bin.iterdir()):
+            if entry.is_file() and entry.name.endswith('_tests'):
+                listing = subprocess.run(['env', 'GTEST_COLOR=no', str(entry), '--gtest_list_tests'],
+                                         cwd=ROOT, capture_output=True, text=True, timeout=120)
+                require(listing.returncode == 0, f'test listing failed: {entry.name}')
+                listings[entry.name] = listing.stdout
+        members = membership(cases, ledger, listings)
+        with (OUT / 'membership.tsv').open('w', newline='', encoding='utf-8') as stream:
+            csv.writer(stream, delimiter='\t').writerows([['binary', 'test', 'state']] + members)
+        state['membership'] = len(members)
+        print(f'MEMBERSHIP binaries={len(listings)} tests={len(members)}', flush=True)
 
     for case in cases:
         row, kind, identity, test, binary, expect, site = case
~~~
