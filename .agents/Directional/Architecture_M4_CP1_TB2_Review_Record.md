# M4-CP1-TB2 Review Record

**Status:** COMPLETE / APPROVED / PACKAGE115 PROMOTED / M4-CP1 CLOSED / RUNTIME-FREE
**Turn:** `M4-CP1-TB2-REV`
**Review model:** same-agent adversarial review, user-authorized 2026-09-10; evidence independence, not personnel separation
**Reviewed semantic source:** `680f9f1573d3c7e56a273366436463e40e196131`
**Reviewed package:** package115, artifact `10159019500`
**Reviewed TB:** run/job `34497233764 / 102938757986`

## 1. Boundary and independence disclosure

This turn executes no Directional runtime, compile, relink, benchmark, generated test discovery, or product/test/fixture/selector mutation. The user explicitly authorized the same agent to perform REVIEW and DEFN turns. Therefore this is not a claim of personnel separation. The compensating control is stronger evidence discipline: primary TB2 result/log/package bytes were re-opened and decisive facts were re-derived from those bytes rather than accepted from this agent's earlier narrative.

The start-of-turn repository-read procedure had one process miss: initial policy/handoff connector reads occurred before the mandatory `READ_MODE` declaration. The turn recorded the miss, switched to `READ_MODE=snapshot`, obtained exact source snapshot run `34499900022`, and performed subsequent source/document analysis from the verified local snapshot. No semantic conclusion below depends on the pre-snapshot reads.

## 2. Primary evidence reopened

- package115 artifact `10159019500`, provider/downloaded SHA-256 `de391c44744d83622dee30cf3a78f781c3b9ad95f0b517a866e7285e77a6b45b`;
- package metadata source commit `680f9f1573d3c7e56a273366436463e40e196131`; `runtimeExecution=false`; `exactArithmeticBackend=GMP`; GMPXX/GMP link line present; all four selector-owner test executables were compiled;
- TB2 result artifact `10160450899`, SHA-256 `0b7f1551fe3881a0fd46386e1a45ae043faa307f6cb167e91cb4ef78839b9e38`;
- TB2 diagnostic log artifact `10160451919`, SHA-256 `2feedf2c278e4735d3506afa124f0cad367d2f23be43cd0d5c3aa66d03f9b955`;
- selector373 LF SHA-256 `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`, exact owner distribution **30 authority-kernel / 227 producer / 75 completion / 41 validation**.

## 3. Independent receipt re-derivation

The result artifact was parsed independently of `semantic-summary.txt`. The full ledger has exactly **373** rows with ordinals `1..373` exactly once; every row has `selected=1`, `exit=0`, and `result=PASS`. Focused A and B each contain exactly ordinals `366..373`, all `selected=1 / exit=0 / PASS`, and their verdict vectors are identical. The ledger, both focused ledgers, and identity map match their recorded SHA-256 sidecars.

All **389** per-process raw logs were scanned: 373 full-selector processes plus 8 focused-A plus 8 focused-B. Every file contains exactly one GoogleTest `RUN` and one `OK` receipt; no `FAILED` or `SKIPPED` receipt appears. This independently confirms one-identity-per-fresh-process selection rather than relying on aggregate counters alone.

All three immutable postflight pairs are byte-identical: package census before/after, extracted-source census before/after, and execution-view census before/after. `execution-boundary.txt` independently records `runtime_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, zero timeouts, and false configure/compile/relink/package-repair/mode-repair/source-test-fixture-selector-mutation flags.

## 4. Frozen TB2 acceptance criteria

Every frozen TB2 criterion, now preserved in `M4_CP1_Closure_Record.md` and `M4_Consolidated_Record.md` §2.6, is satisfied:

| Criterion | Reviewed result |
|---|---|
| exact package/provenance/checksum/GMP preflight | **PASS** |
| selector373 identity and exact four-owner map | **PASS** |
| package-source-derived consumer-visible fixture view | **PASS** |
| focused CP1 A, rows 366-373 | **8/8 PASS** |
| focused CP1 B, rows 366-373 | **8/8 PASS**, vector identical to A |
| full selector373, one identity per fresh process | **373/373 PASS** |
| accepted predecessor | **365/365 PASS** |
| CP1 appended surface | **8/8 PASS** |
| timeout/skip/selection mismatch | **0 / 0 / 0** |
| package/source/execution-view immutability | **PASS** |

The full-green result is therefore mechanically and semantically creditable under the frozen gate.

## 5. TB1 candidate disposition

`M4-CP1-TB1-EXEC-CAND-01` is **CLOSED / RECOVERY PROVED / NON-STABLE**. TB1 omitted 146 rows because package114 lacked three established selector-owner binaries. Package115 carried all four owners, the exact 30/227/75/41 mapping held, and all 373 rows selected and passed. No selector shrink, test relocation, or product-semantic change was needed.

`M4-CP1-TB1-EXEC-CAND-02` is **CLOSED / RECOVERY PROVED / NON-STABLE**. TB1's 38 selected REDs failed before assertions because the executable-relative `test-data` view was absent. TB2 materialized that unchanged consumer-visible view solely from package-owned source bytes and those failures disappeared without test/fixture/product semantic change.

The CB4 falsifier is therefore met exactly: changing only package ownership and execution-view staging removes both failure surfaces. Neither candidate becomes a stable product regression.

## 6. Package promotion and checkpoint closure

Package115/TB2 is promoted to **reviewed M4 semantic runtime authority** for selector373. `Architecture_M4_CP1_Required_Green_Selector_373.txt` becomes the accepted M4 required-green selector at **373/373**; its first 365 rows remain the byte-identical accepted M3 selector365 prefix. Package114 remains unpromoted historical failed-gate evidence.

`M4-CP1` is **CLOSED / ACCEPTED**. Stable regression accounting remains **47 events / 14 categories / 33 recurrences** and produced-witness debt remains **5**. Accepted package authority advances from package113 to **package115**; this does not imply package114 was accepted. M3 package113/TB48 remains the historical M3 closure/final-audit authority.

The deferred multi-coordinate bidirected `±2` exhaustive-oracle finding does not reopen CP1: TB1 review explicitly classified the existing CP1 oracle as valid bounded evidence, deferred the stronger risk-exercising instance until after the unchanged-semantics control, and froze no definition change. The obligation is now due in the first later Code + Build turn authorized to edit test source, `M4-CP2-CB1`.

## 7. Successor

Exact next is **`M4-CP2-CB1`**, runtime-free Code + Build under `Architecture_M4_CP2_CB1_Code_Build_Plan.md`. CP2 must add carried positivity/parity/terminal-optimality certification and typed subset-scoped infeasibility without changing the now-accepted CP1 feasible schedule semantics.

---

## Verification-pass addenda (static, appended after adjudication)

A verification pass re-derived this record from primary evidence and source. **The adjudication is upheld and the
closure stands.** One mandated receipt is supplied and one undefined referent is recorded.

### V1 — confirmed

- **The full green is genuine, and the strongest control here is the log scan.** An independent count of all 389
  raw gtest process logs (8 + 8 + 373) found **389 `[ RUN ]`, 389 `[ OK ]`, 0 `[ SKIPPED ]`, 0 `[ FAILED ]`**. That
  establishes every identity *executed*, not merely that a ledger reported PASS — the control this project has
  repeatedly needed and repeatedly lacked.
- **The fixture defect was fixed at the right layer.** `TestFixturePaths` was left **unchanged** and resolved
  through its existing **sibling** rule to a package-derived `test-data` tree materialized from package-owned source
  bytes. TB1-REV §5 forbade teaching the resolver a new fallback, and that prohibition held.
- **The control held.** The semantic source is `680f9f1573d3c7e56a273366436463e40e196131`, unchanged between CB3 and
  CB4, so TB1-REV §7's prediction remained falsifiable and was met. The mis-targeted oracle obligation that would
  have destroyed that control was withdrawn before CB4 ran.
- **Both TB1 candidates are correctly closed with recovery proved**, and the closure carefully notes that promoting
  package115 *"does not imply package114 was accepted."*
- **The deferred oracle obligation is carried correctly** to `M4-CP2-CB1` — which is also where §13 places
  optimality, since CP1's conjunct 7 requires only that the solver contract be **compiled**.

**A fairness correction to this reviewer's earlier §10.2 framing.** The eight CP1 identities are broader and
better chosen than that finding implied. `ExactValuesExceedLibSatsumaAndBlossomScalarWidths` directly guards
`M4-CP1-CB1-REV` §9's `int`/`double` rejection; `IndependentValidatorRejectsTamperMatrix` is a real tamper
negative; and the oracle identity **does** exercise the tie-break — its `(d₁,d₂) = (3,1)` instance ties across
`x ∈ {1,2,3}` at cost 2 and must resolve to the smallest, so conjunct 9's *"tie"* half is genuinely covered. The
one-degree-of-freedom concern applies only to the **optimum** half of that single identity.

### V2 — the `M4-DEFN` §12 predecessor-prefix receipt was not published; supplied and verified here

`M4-DEFN` §12 requires that *"every selector publication must record line count, LF SHA-256 **and predecessor-prefix
SHA**,"* and §12.1 requires selector365 preserved **byte-for-byte** as the prefix. TB2 records selector373's count
and LF hash but **no predecessor-prefix SHA**, so byte-for-byte preservation was asserted by construction rather
than evidenced — while the entire `365/365` accepted claim depends on it.

Verified independently from the repository:

| quantity | LF SHA-256 (first 16) |
|---|---|
| `Architecture_M4_CP1_Required_Green_Selector_373.txt`, 373 rows | `6d00cafa939a0e89` — matches TB2's recorded hash |
| `Architecture_M3_CP4c2_Required_Green_Selector_365.txt`, 365 rows | `6b5b6555d39c250c` |
| **first 365 rows of the M4 selector373** | **`6b5b6555d39c250c`** |

**The prefix relation holds exactly.** The accepted `365/365` claim is about the correct set, and rows 366–373 are
the eight `GlobalConformity*` identities. This is a **missing receipt, not a defect** — recorded so the next
selector publication carries it rather than re-deriving it.

### V3 — CP1's exit conjunct 9 references a set that was never frozen

`M4-DEFN` §13 closes CP1 on nine conjuncts. Eight are clearly discharged by the eight identities and the green
gate. The ninth reads:

> *"…and fixed-small test oracles independently reproduce optimum/tie results on **the frozen CP1 graph classes**."*

**That phrase appears exactly once in the entire retained corpus — in the exit condition itself.** No CP1 graph
classes are frozen anywhere: not in `M4-DEFN`, not in `M4-DEFN-R1`, not in any CP1 plan or record. Conjunct 9 was
therefore discharged against an **undefined referent**, and this review closed CP1 without reconciling it.

**CP1 is not reopened on this**, and that is a deliberate proportionality judgement: eight conjuncts are
well-evidenced, the ninth has real evidence (optimum *and* tie, on the instance it has), and the gap is a
definitional omission rather than a contradicted claim. Reopening a well-evidenced closure over a documentation
gap would be the wrong trade.

> **Added to `M4-CP2-CB1` (non-optional), alongside the multi-coordinate oracle obligation it already owns:**
> **freeze the CP1 graph classes retroactively** — either name the set conjunct 9 intended, or state that the
> single two-row class was the intended set and why — and confirm the oracle coverage against it. An exit condition
> whose referent cannot be read is not an exit condition (`LESSONS.md` 167), and an undefined referent inside a
> closed checkpoint is exactly the shape that made M3's CP4c-0 row unreadable.

### V4 — accounting

Unchanged. Static addendum, **+0 events / +0 recurrences**. Accepted package authority remains **package115**;
`M4-CP1` remains **CLOSED / ACCEPTED**; stable accounting remains **47 / 14 / 33**, debt **5**.
