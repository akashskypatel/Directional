# M5-CP3-TB1 Review Record

**Turn:** `M5-CP3-TB1-REV`
**Mode:** independent Test + Benchmark Review / runtime-free
**Reviewed execution:** `M5-CP3-TB1-EXEC`
**Decision:** **CONFIRMED ORCHESTRATION DEFECT / CORRECTED R1 EXECUTION AUTHORITY FROZEN / ZERO SEMANTIC CREDIT**

## 1. Review question and boundary

The predecessor Test + Benchmark turn stopped before semantic runtime after the frozen plan rejected accepted routing artifact `10592987234` by digest. This Review asks only whether that rejection came from a malformed frozen plan literal or from changed/corrupt routing authority, and—if it is a plan defect—what exact immutable authority may be used for a fresh artifact-only retry.

This Review executes no Directional binary, test, benchmark, configure, compile, relink, generated discovery, fixture generation or package repair. It does not mutate product/test/benchmark/build logic or any selector byte. Candidate promotion and produced-witness debt credit are prohibited because the predecessor executed **0/445** semantic processes.

## 2. Independent evidence reopening

### 2.1 Final predecessor retry is trustworthy pre-runtime failure evidence

Review independently re-opened run/job `35544717675 / 106168570124` and downloaded result artifact `10616206801`. The downloaded ZIP hashes to `48509074dfe81f89133290dc4b8f51454e205ce2e2f1c7df40e3d8553ebfc71c`; its self-manifest verifies **4/4**. The result records candidate artifact `10615252806` at the expected provider/download SHA-256 `1e32fa2b55f84b9097b0d617bcfc1b5f7ad1ab7e5ffc2bdb8e0cde8ea715bf20`, then stops on routing authority before semantic execution.

The boundary receipt is exact: `preflight_completed=false`, `runtime_started=false`, `runtime_completed=false`, `orchestration_failure=true`; benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters are all **0**. There is therefore no production, fixture, expectation, nondeterminism or performance result to adjudicate from TB1.

### 2.2 The predecessor plan literal is malformed

The frozen predecessor plan records routing artifact `10592987234` with:

`352c8cfc9c89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`

That literal is **62 hexadecimal characters**, so it cannot be a SHA-256 digest. The executor correctly failed closed rather than changing frozen authority during `TB-EXEC`.

### 2.3 Accepted routing authority independently resolves the exact bytes

Review independently re-opened M4-TB3 routing artifact `10592987234` from run `35470130614`. Live artifact metadata reports provider digest:

`sha256:352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`

A fresh downloaded copy independently hashes to the same exact 64-character value. Its `identity-map.tsv` hashes to `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, contains exactly **430 rows / 430 unique identities / ordinals 1..430**, and has owner census **31 authority-kernel / 283 producer / 75 completion / 41 validation**. The artifact's own manifest verifies its retained evidence. Accepted M4-TB3 durable reports record the same routing ZIP and identity-map hashes.

This is independent byte authority, not inference from the malformed literal. The corrected routing digest is therefore exactly:

`352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`

### 2.4 Accepted selector prefix remains byte-frozen

Review independently re-hashes `.agents/Directional/Architecture_M4_CP4_CB8_Required_Green_Selector_430.txt`: **430 LF-terminated rows**, full SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact first427 prefix SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. No selector byte changes in this Review.

## 3. Classification and adjudication

`M5-CP3-TB1-EXEC-OBS-01` is **CONFIRMED / RESOLVED / ORCHESTRATION / FROZEN PLAN AUTHORITY / NON-STABLE**. The root cause is a malformed frozen routing digest literal, not changed routing bytes and not Directional semantics. The executor's fail-closed response is correct.

Stable accounting is unchanged: **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. Candidate `10615252806` / source `fc2aa5fa68cac890051614c2104979aef4a60d21` remains compile-only and unpromoted. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. All four M5 produced debts remain open.

## 4. Corrected execution authority

The sole authorized successor execution plan is `Architecture_M5_CP3_TB1_R1_Artifact_Only_Test_Benchmark_Plan.md`. It preserves the predecessor's immutable candidate, source, package hashes, nine reviewed mechanism rows, six produced rows, selector430 bytes/order/hash, routing identity-map hash/census, exact-one/zero-skip rule, immutable pre/postflight, semantic-RED continuation rule and benchmark count **0**.

The only semantic-neutral authority correction is the routing artifact ZIP digest from the malformed 62-character literal to the independently verified 64-character digest `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`. R1 must restart from process **1**; none of the blocked predecessor attempts contributes semantic credit. If preflight succeeds, the required semantic surface remains **9 + 6 + 430 = 445 fresh exact-filter processes**.

The mechanically complete R1 execution must be followed by independent runtime-free `M5-CP3-TB1-R1-REV`. Candidate promotion, the four produced-debt decisions and exact successor-selector publication precommitment remain owned by that subsequent Review.

## 5. Prior obligations

- `M5-CP3-TB1-EXEC-OBS-01` — **DISCHARGED / RESOLVED NON-STABLY** by the byte-level routing authority proof above.
- `M5-CP2-TB1-REV-OBS-01` — **CARRIED to `M5-CP3-TB1-R1-REV`**. The original owner could not pre-commit publication bytes because no valid CP3 semantic runtime exists. The obligation is unchanged: only after a mechanically complete R1 gate may Review freeze the exact successor-selector bytes/order/LF SHA-256 and owner census before publication Code + Build.
- M5 produced debts 1-4 — **OPEN**; TB1 provides zero semantic credit.
- M6 closed-complex produced debt — **OPEN / M6-owned**; no A5 authority is pulled backward.

## 6. Consolidation and retained authority

This Review folds superseded per-turn records only after their durable facts are preserved here, in `M5_Consolidated_Record.md`, `Regression_Root_Cause_Tracker.md`, `CHANGELOG.md`, `ORIENTATION.md` and git history:

- `Architecture_M5_CP3_CB1_Review_Record.md` (141 lines) — superseded Review; §14 adjudication remains in frozen definitions and retained M5 records.
- `Architecture_M5_CP3_CB2_Direct_Production_Promotion_Plan.md` (197 lines) — consumed implementation plan; current candidate authority remains in the retained CB2 build report.
- `Architecture_M5_CP3_TB1_Artifact_Only_Test_Benchmark_Plan.md` (148 lines) — consumed blocked plan; its malformed digest and fail-closed outcome are preserved in the retained TB1 report, this Review and the tracker.

Current retained role documents are the CB2 build report, blocked TB1 runtime report, this Review, the corrected R1 plan, M5 consolidated/frozen records, and byte-frozen selectors.

## 7. Decision and successor

**Decision: confirmed orchestration defect; corrected immutable execution authority approved.** Exact successor: **`M5-CP3-TB1-R1-EXEC`**. No runtime, compile or semantic source/test/selector mutation is authorized by this Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 = `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 = `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; 430 LF rows, unchanged. |
| Decisive claims independently re-derived | Final retry result ZIP/self-manifest/boundary; malformed predecessor literal length 62; live provider + fresh routing ZIP exact 64-char digest; identity-map hash, 430/430 uniqueness/ordinal/census; selector430/first427 hashes. |
| Non-vacuity checked | Corrected authority is backed by live immutable artifact bytes plus identity-map content/census, not a guessed string completion; R1 preserves all 445 semantic discriminators and restarts at process 1. |
| Prior obligations discharged/carried | `M5-CP3-TB1-EXEC-OBS-01` resolved non-stably; `M5-CP2-TB1-REV-OBS-01` carried to `M5-CP3-TB1-R1-REV`; four M5 produced debts remain open. |
| Stable accounting | **49 / 14 / 35**, debt **5**; accepted package `10601978228`; candidate `10615252806` remains unpromoted. |
| New candidates/obligations recorded | No new stable category/event. Existing TB1 observation is confirmed and closed; publication precommitment is explicitly re-homed because semantic runtime never began. |
| ORIENTATION currency line | `M5-CP3-TB1-REV`, 2026-09-20 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated for compile-green CB2 candidate, pre-runtime TB1 block, corrected R1 authority, unchanged torus credit, exact R1 priority and existing orchestration-literal validation pattern. |
| CHANGELOG | Review entry added with independent routing-byte adjudication and zero-credit boundary. |
| ROADMAP | CP3 advances to corrected fresh `M5-CP3-TB1-R1-EXEC`; no M5 debt/promotion claim. |
| Selector manifest | n/a — no selector file added, modified or accepted in this Review. |
| LESSONS | Existing fail-closed/frozen-authority lesson applies; this is another instance, not a new generalizable category. |
| Consolidation under CLEAN_UP_POLICY | Three superseded CP3 documents folded/indexed after durable facts were preserved; retained CB2 build report, TB1 report, current Review and one corrected R1 plan. |
| Successor frozen | `M5-CP3-TB1-R1-EXEC`; mechanically complete R1 must next enter `M5-CP3-TB1-R1-REV`. |
| Turn boundary held | Runtime-free; no product/test/fixture/benchmark/build/selector mutation, compile or Directional runtime execution. |
| review_check.py boundary | **ALL CHECKS PASSED** with selector430 exact-hash expectation on the prepared Review delta. |
| `STATUS` lifecycle maintained | Review entry beacon already published; durable docs and workflow-first cleanup are verified. The COMPLETE successor beacon is the next and final repository write for this turn. |
| Pushed to origin, branch in sync | **CONFIRMED** after durable documentation push and workflow-first cleanup; current remote authority was re-read with only durable workflows present, all connector-trigger/workflow-observation/turn-payload temporary state absent, and all current-turn Drive staging patches permanently retired. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** The orchestration classification is correct, the correction is semantic-neutral, and
deferring the four produced-debt decisions and the selector pre-commitment to `M5-CP3-TB1-R1-REV` is right.
Accounting holds at **49 / 14 / 35**, debt **5**; selector430 re-hashes to `1c412850…9db6` at 430 rows with its
first 427 rows byte-identical to selector427.

### V1 — the corruption is precisely characterised, and the corrected plan is clean

The malformed literal is **62** characters and the verified digest is **64**. They are not independently wrong
values: the malformed literal is *exactly* the correct digest with `9b` deleted —
`352c8cfc9c`**`9b`**`89cf…afce` → `352c8cfc9c89cf…afce`. A two-character mid-string drop.

I then applied the check this class actually needs to the corrected plan: every hex literal in
`Architecture_M5_CP3_TB1_R1_Artifact_Only_Test_Benchmark_Plan.md`, with lengths. All **eight** SHA-256 values are
exactly 64 characters — including the corrected routing digest `352c8cfc9c9b89cf…afce`, the identity-map digest
`7a92e7a3…cf6c`, selector430 `1c412850…9db6` and the selector427 prefix `f9c88380…e86f` — and the single 40-character
value is the git SHA-1 semantic source `fc2aa5fa…`. **No fourth malformed literal.** The R1 plan is well-formed.

§2.3's method is also right: the digest was re-derived from live artifact metadata plus a fresh download, not
inferred from the malformed literal. Inferring the correct value from the corrupted one would have been circular.

And the executor failed closed rather than editing frozen authority mid-execution — the third time that
separation has held under pressure (`M5-CP1-TB1-EXEC`, `M5-CP1-TB1-R1-EXEC`, here). That discipline is why each
of these cost a turn instead of corrupting an acceptance.

### V2 — ESCALATED: this is a transcription failure, not a knowledge failure

This is the **third** malformed frozen literal in M5, and the decisive fact is that **the correct value was
already in the durable record**. `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce` appears
verbatim in at least five committed documents — including `Architecture_M4_CP4_TB3_Review_Record.md` and
`Architecture_M5_CP2_TB1_Artifact_Only_Test_Benchmark_Report.md` — and it was independently verified by this
reviewer at `M4-CP4-TB3-REV` and again at `M5-CP1-TB1-PREFLIGHT-REV`. The same artifact's *identity-map* digest
was the one truncated to 63 characters at `M5-CP1-TB1-EXEC`.

So the standing rule recorded at `M5-CP1-TB1-EXEC-OBS-01` — validate every literal against the artifact it names
before freezing — is correct but is not working, because it prescribes artifact re-derivation, which is
expensive and keeps being skipped. Nothing about these failures required artifact access to detect:

1. **A length check catches both observed instances for free.** A SHA-256 literal is 64 hex characters; a git
   SHA-1 is 40. The 63-character and 62-character literals were detectable without opening anything. The single
   command above validated all eight literals in the corrected plan.
2. **A digest already present in the durable record must be copied from it, not re-typed.** Every one of these
   values existed verbatim in committed documents; a `grep` for the literal would have failed instantly on a
   corrupted copy.

Recorded as `M5-CP3-TB1-REV-OBS-01`: before any plan is frozen, mechanically check that every hex literal has a
valid length for its type, and that any digest already recorded in a durable document matches that record
verbatim. This is seconds of work and catches the entire observed failure class; artifact re-derivation remains
required only for values that are genuinely new.

### V3 — obligations and credit boundaries are correctly held

`M5-CP2-TB1-REV-OBS-01` (pre-commit the successor selector bytes/order/SHA-256/census before publication) is
carried to `M5-CP3-TB1-R1-REV` for the right reason: no valid CP3 semantic runtime exists yet, and the selector's
content depends on which produced identities pass. Pre-committing before that would be pre-committing a guess.

M5 produced debts **1-4 remain OPEN** with **zero semantic credit** from TB1, and the M6 closed-complex debt
remains M6-owned with no A5 authority pulled backward. Frozen §13.4's naming boundary and the §8.1 mechanism-only
classification of the direct/draft helpers are untouched, so nothing here moves a debt.

### V4 — verification limits

Re-derived from repository bytes: both literals' lengths and the exact `9b` deletion relating them, the presence
of the correct digest in five committed documents, every hex literal and its length in the corrected R1 plan, and
selector430's row count, full hash and 427-row prefix. Accepted as reported: live artifact metadata for
`10592987234`, the fresh-download hash, run/job identifiers and the predecessor's pre-runtime failure receipts.
