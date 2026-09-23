# M5-CP3-TB1-R15 Independent Review Record

- **Phase:** M5 / CP3 / TB1 / R15 Review
- **Turn:** `M5-CP3-TB1-R15-REV`
- **Validated semantic source:** `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`
- **Reviewed execution:** `M5-CP3-TB1-R15-EXEC`
- **Reviewer independence:** same-agent Review is project-authorized; the Review re-opened primary artifact bytes and the exact historical harness rather than accepting the EXEC report as self-proving.
- **Decision:** **APPROVED WITH AMENDMENTS — R15 IS ORCHESTRATION INVALID; ROOT CAUSE PROVED; ZERO GATE/PRODUCT CREDIT; CONTROL-PLANE CORRECTION REQUIRED BEFORE A FRESH R15-R1.**
- **Authoritative successor:** `M5-CP3-CB18`

## 1. Evidence reviewed independently

### Immutable candidate/build authority

CB17 candidate authority remains:

- semantic source `1a36f6483738e1047b5d8ddbefb48cc5ab6fd4a3`;
- candidate artifact `10742798135`, provider ZIP SHA-256 `eb1e2be55150022cdba05acf6b38433eb16352e4b3b6a561742e62de26cfd866`;
- compile run/job `35845003340 / 107128980299`;
- compile-log artifact `10743207155`, provider ZIP SHA-256 `cc58680de72ec58dc3cc74d3a1971d881f6232be923f0eb8672dad711e69354c`;
- root candidate manifest SHA-256 `a6c288ff4ef5afff8122f9dae0e330fe1cab4928b7bd5b5604b7d2fd5e32b951`, **28/28**;
- packaged source archive SHA-256 `e6bed804841ecf590ccd1c372c906e19b927e5cf0d253d0d361993fa92ce68e0`;
- routing artifact `10592987234`, provider/download SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- routing identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 prefix SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- routing owner census `31 / 283 / 75 / 41`.

The current repository selector was re-hashed independently during this Review: 430 LF-terminated rows, no CR bytes, with the exact selector430 and first427 hashes above.

### R15 attempt 0

Run/job `35850838725 / 107147928250` produced:

- result artifact `10745895043`, independently downloaded ZIP SHA-256 `0700b240545c182f546e6c2927a792fd00c0b743cead22eb3f7d06bfe210e806`;
- log artifact `10745825171`, independently downloaded ZIP SHA-256 `03d490b60519118dc8dcb2887b644234c81dbb94318511da1afce36425d112d8`.

The preserved boundary independently reads `runtime_started=false`, `runtime_completed=false`, `preflight_completed=false`, zero executed processes and `script_exit=1`. The diagnostic log shows the temporary harness failed while parsing its embedded Python preflight. It therefore contributes no runtime evidence and the one bounded pre-runtime correction was policy-valid.

### R15 attempt 1

Run/job `35851321165 / 107149476143` produced:

- result artifact `10745985740`, independently downloaded ZIP SHA-256 `b863d7a5a88cb9fda5b1019ba6a9d9161594455e5ca118bdabeddf563cb1d13c`;
- log artifact `10745542559`, independently downloaded ZIP SHA-256 `4be730a0a3cad33115e66f70616123d5ac427687d172fc462d1dc550d6631622`.

The boundary independently reads:

```text
runtime_started=true
runtime_completed=false
preflight_completed=true
orchestration_failure=true
selection_integrity=false
nonselector_executed=0
selector_executed=0
total_executed=0
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
mode_repair=false
source_test_fixture_selector_mutation=false
retry_after_runtime_start=false
script_exit=90
```

Its process ledger contains only the header. The first raw process is nevertheless unambiguous diagnostic provenance:

```text
Google Test filter = M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges
[ RUN      ] M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges
[       OK ] M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges (0 ms)
[  PASSED  ] 1 test.
```

The process exit status was 0, but the remaining 447 prescribed processes did not execute and no complete semantic ledger exists.

## 2. Root cause independently proved

The exact historical harness at R15 retry event commit `9161a05fe5271b8e0a75d365182e49237aa864a6` has blob `5b2f569a1ef4d54daf65ed0d1af3604a3b87db28`. Its selection accounting stored doubled bracket escapes:

```bash
selected="$(grep -Ec '^\\[ RUN      \\] ' "$raw" || true)"
skipped="$(grep -Ec '^\\[  SKIPPED \\] ' "$raw" || true)"
passed="$(grep -Ec '^\\[       OK \\] ' "$raw" || true)"
```

Against the preserved first-process raw log, this Review independently obtains:

```text
historical_selected=0
corrected_selected=1
historical_passed=0
corrected_passed=1
corrected_skipped=0
```

The failure is therefore a **temporary control-plane/evidence-parser defect**, not a product failure and not a zero-selected test. The parser rejected a visibly executed exact-one PASS because its own regular expression was wrong.

This is an instance of existing project lessons, not a new regression category: zero-selected filters are orchestration failures; exit 0 is insufficient without positive execution proof; structured/raw protocol evidence outranks a broken summary parser; and a harness-status transition with no product-behavior transition is a harness result, not a product result.

## 3. Challenge to the EXEC disposition

### 3.1 Upheld: R15 has zero gate/product credit

The EXEC disposition is correct. Once attempt 1 began generated Directional runtime, the frozen no-retry-after-runtime-start rule barred another same-EXEC correction. The R15 contract was **448 fresh independent processes**; one raw process cannot be stitched to a later retry, and the header-only ledger is not a 448-row result.

Therefore R15 proves none of the following:

- no CB17 candidate recovery or promotion;
- no produced-row 4/5 recovery;
- no selector430 runtime credit;
- no stable-regression transition;
- no nonzero-Z4 debt discharge;
- no closure of the independent row4 direction observation;
- no CP3 publication credit.

R14 remains the latest mechanically valid CP3 runtime at **446/448 PASS** with complete **916/916** evidence and selector430 **430/430**. Accepted runtime remains package `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`.

### 3.2 Amendment: the correction owner is a bounded control-plane Code + Build turn

A fresh R15-R1 should not be launched directly from Review by reauthoring the harness ad hoc. Two consecutive temporary-harness materialization defects have now occurred before a complete R15 ledger, and the second occurred only after runtime began. Precedent in M4 uses a runtime-free control-plane Code + Build turn to freeze and statically falsify the corrected execution plane before a fresh runtime turn.

The simplest sufficient successor is therefore **`M5-CP3-CB18`**, control-plane only. It must correct and freeze the exact-one parser, prove the parser against literal GTest protocol lines before any generated runtime, bind the successor caller to the exact harness bytes, preserve the timeout-free full-gate contract, and change no product/test/fixture/A3/selector/candidate semantics. It must not compile or repackage Directional.

Fresh `M5-CP3-TB1-R15-R1-EXEC` then restarts at process 1 with **all 448 original R15 identities**, benchmark 0, and zero carry-forward from either invalid R15 attempt. Mandatory `M5-CP3-TB1-R15-R1-REV` follows regardless of PASS/RED.

## 4. Prior obligations

- `M5-CP3-TB1-R6-REV-OBS-01` — **OPEN / CARRIED.** Row4 never reached its independent Forward -> Reverse comparator/inverted-pair rejection in a mechanically valid recovery gate.
- `M5-CP2-TB1-REV-OBS-01` — **OPEN / CARRIED.** Selector publication still requires a complete corrected CP3 gate and Review.
- `M5-DEFN-REV-OBS-01` — **OPEN / CARRIED** to the eventual M5 closure/publication owner.
- `M5-CP3-TB1-R13-REV-OBS-01` — **DISCHARGED AS TRIGGERED** before DEFN-R1; no change.
- `M5-CP3-TB1-R14-REV-OBS-01` — **DISCHARGED** by DEFN-R1's independent committed-torus derivation; no change.
- `M5-CP3-DEFN-R1-REV-OBS-01` — **PARTIALLY SATISFIED / RUNTIME CREDIT CARRIED.** CB17 authored exactly the requested discriminating mechanism case (`A=1, G_F=2, G_R=1 -> Q=2 != A`) and the invalid R15 attempt's raw first process shows it ran once and passed. Because R15 is orchestration-invalid and grants zero gate credit, the observation is not closed from that raw diagnostic alone; fresh R15-R1 must re-run it inside the complete valid ledger before R15-R1 Review can discharge it.
- two M5 nonzero-Z4 produced debts — **OPEN / CARRIED** to fresh R15-R1 Review.
- M6 closed-complex produced debt — **OPEN / M6-OWNED**, unaffected.

Stable accounting remains **51 events / 14 categories / 37 recurrences**. Produced-witness debt remains **3**. `M5-CP3-TB1-R15-EXEC-CAND-01` remains **NON-STABLE / +0**, now independently cause-proved as a control-plane exact-one parser defect owned by CB18.

## 5. Engineering-guideline review of the successor

- **Material assumptions challenged:** no product defect is inferred from a broken selection parser; no prior semantic row is imported from an invalid gate; candidate/source/routing/selector identities remain fixed.
- **Simpler alternatives considered:** a direct R15-R1 launch was rejected because it would repeat ad-hoc harness authoring without an independently frozen parser control. Product/test changes are unnecessary and prohibited.
- **Unrelated/speculative work removed:** no reusable-workflow permission change, no source/fixture/A3/selector change, no candidate rebuild, no benchmark addition, no M6 pullback.
- **Surgical scope:** CB18 is only execution-plane/parser authority plus static control validation.
- **Observable success:** literal protocol self-test must classify one RUN/one OK/zero SKIPPED; the historical doubled-backslash parser must fail that falsifier; shell/YAML/static boundary checks must pass; no Directional runtime/compile/repackage may occur in CB18.

## 6. Decision

**`approved_with_amendments`.** The EXEC classification is upheld, and the root cause is independently proved. The amendment is sequencing: a fresh R15-R1 is authorized **only after** runtime-free control-plane correction `M5-CP3-CB18` freezes and statically proves the corrected harness/caller. No semantic/product/test/fixture/A3/selector change is authorized.

The authoritative next plan is `.agents/Directional/Architecture_M5_CP3_CB18_R15_R1_Orchestration_Correction_Plan.md`.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; 430 LF rows, no CR. |
| Decisive claims independently re-derived | Re-hashed both R15 result/log ZIP pairs; re-opened both execution boundaries; inspected the first raw process and header-only ledger; fetched the exact historical retry harness; independently reproduced historical parser count 0 versus corrected count 1; re-hashed selector430/first427. |
| Non-vacuity checked | The preserved raw log visibly contains exactly one `[ RUN ]`, one `[ OK ]`, zero `[ SKIPPED ]`; the historical doubled-escape parser returns 0 while the corrected bracket expression returns 1. This distinguishes parser failure from zero selection. |
| Prior obligations discharged/carried | R6 direction, CP2 publication, M5-DEFN and both nonzero-Z4 debts carried; DEFN-R1-REV observation partially satisfied but retained for valid R15-R1 ledger; R13 trigger and R14 freeze observation remain discharged. |
| Stable accounting | **51 events / 14 categories / 37 recurrences**, debt **3**; accepted package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`; selector430 unchanged. |
| New candidates/obligations recorded | No new stable candidate. Existing `M5-CP3-TB1-R15-EXEC-CAND-01` upgraded to Review-confirmed/cause-proved control-plane parser defect, owner `M5-CP3-CB18`, +0. |
| ORIENTATION currency line | `M5-CP3-TB1-R15-REV`, 2026-09-23 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated CP3 authority, torus witness state, priority list and existing zero-selection/harness-evidence pattern instance; stale CB17-next text removed. |
| CHANGELOG | R15 Review adjudication and CB18 successor entry added. |
| ROADMAP | M5-CP3 updated to CB17 compile-green / R15 orchestration-invalid / CB18 control-plane correction next; R14 remains latest valid runtime. |
| Selector manifest | n/a — no selector byte added, changed, precommitted or accepted. |
| LESSONS | No new lesson number: this is a new instance of existing zero-selected/non-vacuity, raw-evidence-over-summary, and harness-result-not-product-result lessons. |
| Consolidation under CLEAN_UP_POLICY | Superseded R14 Review, consumed DEFN-R1 plan/record, consumed CB17 plan/report and consumed R15 plan/invalid report folded/indexed into `M5_Consolidated_Record.md`; retained current R14 runtime report + this Review + one CB18 plan + frozen definitions/selectors. |
| Successor frozen | Exactly one successor: `M5-CP3-CB18`; static parser falsifier, fixed semantic inputs, zero-runtime/zero-compile boundary and fresh-R15-R1 rules are frozen in `Architecture_M5_CP3_CB18_R15_R1_Orchestration_Correction_Plan.md`. |
| Turn boundary held | Yes — Review is runtime-free with respect to Directional; only static artifact/log/parser checks were performed; no product/test/fixture/benchmark/build/selector byte changed and no Directional binary was executed. |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** on the complete documentation/consolidation diff with declared selector430 hash `1c412850...a9db6`. |
| `STATUS` lifecycle maintained | Entry beacon: Turn `M5-CP3-TB1-R15-REV`, IN_PROGRESS, successor self, Started at `2026-09-23T11:30:44Z`, latest Resumed at `2026-09-23T11:49:01Z`, Ended at empty. Terminal COMPLETE -> `M5-CP3-CB18` is reserved for the final repository mutation. |
| Pushed to origin, branch in sync | n/a to local `git status -sb` — this is a connector-native turn with no authoritative local branch; exact PR head and temporary-control directories are re-read after cleanup before terminal `STATUS`. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** The zero-credit disposition is correct and complete, and the CB17 mechanism identity
satisfies my freeze observation in authorship — exceeding what was asked. Accounting correctly holds at
**51 events / 14 categories / 37 recurrences**, debt **3**. One targeted process finding is recorded.

### V1 — zero credit is the right call and is drawn completely

R15 never started runtime by the preserved boundary (`runtime_started=false`, `preflight_completed=false`, zero
executed processes, `script_exit=1`), and the no-retry-after-runtime-start rule correctly barred a same-EXEC
correction once attempt 1 had begun. The refusals are enumerated rather than gestured at: no selector430 runtime
credit, no nonzero-Z4 debt discharge, no CP3 publication credit, with R14 retained as the latest mechanically
valid CP3 runtime.

That completeness matters here, because a visibly passing `[  PASSED  ] 1 test.` line sits in the preserved
evidence. Taking partial credit from it would have been the tempting move, and the Review declines it. Accounting
is right for the same reason: nothing executed, so no accepted-prefix ordinal transitioned and no event arises.

### V2 — my freeze observation is satisfied in authorship, and better than specified

`M5-CP3-DEFN-R1-REV-OBS-01` asked for a focused mechanism identity constructing `g_F != g_R` and checking the
correction against an independently computed expectation. `TEST(M5CP3, PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges)`
does exactly that, and the algebra checks out against frozen §16.3:

`A = 1`, `G_F = 2`, `G_R = 1` gives `q = -g_R + a + g_F = -1 + 1 + 2 = 2`, and the test expects **2**.

What makes it stronger than requested are three discriminating negatives, which rule out the alternatives rather
than merely confirming one value:

- `EXPECT_NE(sourceTransport, relationRotation)` — `2 != 1`, so the correction is non-trivial and the degenerate
  case that worried me is genuinely escaped;
- `EXPECT_NE(relationRotation, compose(G_R.inverse(), A))` — rules out a reverse-gauge-only rule (`0 != 2`);
- `EXPECT_NE(relationRotation, compose(A, G_F))` — rules out a forward-gauge-only rule (`3 != 2`).

It then checks §3's closure equation in endpoint form (`reverseState->branchRotation ==
compose(relationRotation, forwardState->branchRotation)`) and the lattice rotation. Exposing
`periodic_relation_rotation(sourceTransport, forwardCutGauge, reverseCutGauge)` as a named function is the right
design response — it makes the frozen model directly testable without a produced subject, which is what the
observation was reaching for.

**"PARTIALLY SATISFIED / RUNTIME CREDIT CARRIED" is the honest disposition**: the identity exists and is correct
by inspection, but R15 was orchestration-invalid, so it has never executed. One caveat to carry forward: this is
a **mechanism** identity over hand-constructed states, so under frozen §8.1 it carries no produced-witness credit
and cannot discharge debts 3 or 4 even when green. It validates the model, not the production witness.

### V3 — FINDING: the defect is double-escaping, and evidence parsers are outside the existing rules

The harness counted with `grep -Ec '^\\[ RUN      \\] '`. Inside single quotes the shell passes `\\[` through, so
ERE sees a **literal backslash** followed by a bracket expression — it matches lines beginning with a backslash,
which gtest never emits. Hence `historical_selected=0` and `historical_passed=0` against a log containing a
genuine `[ RUN      ]` / `[       OK ]` pair. The correct pattern is `'^\[ RUN      \] '`. This is a
double-escaping bug from embedding a script inside another layer and escaping for a layer that does not exist.

That makes it the **third embedded-harness escaping or encoding failure in M5** — after the malformed frozen
digests (`M5-CP1-TB1-EXEC-OBS-01`, escalated at `M5-CP3-TB1-REV-OBS-01`) and the harness decode/path repairs
(`M5-CP1-TB1-R1-EXEC-OBS-01`) — and the fourth orchestration-class turn loss overall, counting the R10 manifest
finalization defect.

The existing rules do not reach it. They cover **literals asserted about artifacts** (check length, copy from the
durable record) and **executor end-to-end validation** (decode the harness, resolve package paths). An evidence
parser is neither: it is a literal that asserts something about *output format*, and the only thing that can
validate it is real output.

**The check is trivial, and this Review performed it — afterwards.** §2 replays the pattern against the preserved
raw log and obtains `corrected_selected=1`, `corrected_passed=1` in seconds. Run before the gate instead of in
the post-mortem, it costs nothing and saves the turn.

Recorded as `M5-CP3-TB1-R15-REV-OBS-01`: **any change to evidence-parsing logic must be replayed against
preserved raw evidence from a known-good prior run, and must reproduce that run's recorded counts, before the
gate is triggered.**

### V4 — carried items and verification limits

`M5-CP3-TB1-R6-REV-OBS-01` correctly remains OPEN — row 4 never reached the Forward → Reverse comparator or
inverted-pair rejection in a mechanically valid gate, so nothing about direction became decidable.
`M5-CP2-TB1-REV-OBS-01` remains open under §13.3. Debts 3 and 4 remain OPEN; the M6 closed-complex debt remains
M6-owned.

Re-derived from repository bytes: the full body of the CB17 mechanism identity and its algebra against §16.3, the
three discriminating negatives, the new `periodic_relation_rotation` signature, CB17's change scope, and the ERE
semantics of the failing pattern. Accepted as reported: the preserved execution-boundary flags, harness blob
identity, and the replayed historical/corrected counts.
