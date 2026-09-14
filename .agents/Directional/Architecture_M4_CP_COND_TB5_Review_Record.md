# M4-CP-COND-TB5-REV — Review Record

**Turn:** `M4-CP-COND-TB5-REV`
**Type:** Review + Plan only / runtime-free
**Date:** 2026-09-14 UTC
**Verdict:** **ACCEPTED / SELECTOR423 PROMOTED / CP-COND CLOSED**
**Successor:** `M4-CP-SCALE-DEFN`

## 1. Frozen subject and review boundary

This Review re-opened the exact CB5/TB5 subject frozen by the predecessor plan. No Directional runtime, configure,
compile, relink, package repair, product/test/fixture/selector semantic mutation, or CP-SCALE implementation was
performed in this Review.

Frozen candidate authority:

- immutable package artifact `10331193451`, provider/ZIP SHA-256
  `3f23572a4869e469a6f3ba1082af8a7836c29d9566d143e1a395950d8a94230b`;
- packaged semantic source `07984711db59eaa228820e7d44e5552a652edadf`;
- selector423 `Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt`, 423 LF rows, SHA-256
  `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- accepted predecessor selector422 SHA-256
  `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- TB5 run/job `34805164109 / 103855521990`;
- result artifact `10333057375`, SHA-256
  `240d22578a48570b8ecab26c158d24ccc70f4e5a5c79a53d4bdd9359e1c78bb3`;
- diagnostic artifact `10332819388`, SHA-256
  `e2b3262b5188149a8bfe3664e7473c44feeb73ad119216081d1d0889c9d66499`.

Entering accepted authority was package `10327643907` / selector422 **422/422**. It remains the accepted predecessor;
this Review advances current M4 runtime authority only after the independent checks below pass.

## 2. Independent TB5 primary-evidence re-derivation

The Review did not trust the EXEC report as acceptance evidence. It re-opened the primary result/log bytes and found:

1. **Outer identities:** locally re-hashed result/log archives exactly match the frozen SHA-256 values above.
2. **Evidence manifest:** `EVIDENCE_SHA256SUMS` excludes itself and verifies all **440** substantive evidence files.
3. **Package authority:** the candidate package re-hashes to the frozen package SHA; package `SHA256SUMS` verifies
   **27/27** entries; `metadata/source-commit.txt` is exactly `07984711...03f0`; all recorded source-status receipts are
   clean and `runtimeExecution=false`.
4. **Exact backend/runtime linkage:** package build metadata records `exactArithmeticBackend=GMP` and link evidence for
   both `libgmpxx.so` and `libgmp.so`. TB5 `ldd-producer.txt` resolves both `libgmpxx.so.4` and `libgmp.so.10`; the
   remaining owner binaries resolve GMP as required by their linked code paths.
5. **Selector authority:** selector423 independently re-hashes to `4e67e4dc...d89343`; it has exactly 423 unique LF
   rows. Rows1-422 compare byte-for-byte to selector422 and hash to `bbd496f3...f7cc`; rows1-408 hash to accepted
   selector408 `c689c0cd...b0484`; row423 is exactly
   `InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`.
6. **Owner census:** primary ledger/owner-map bytes independently yield **30 authority-kernel / 277 producer / 75
   completion / 41 validation = 423**, with row423 producer-owned.
7. **Process ledger:** exactly 423 data rows, ordinals exactly 1..423, 423 unique requested identities matching the
   selector row-for-row, exact owner/binary agreement, `selected=1`, exit 0, timeout 0, and PASS on every row.
8. **Raw process evidence:** every one of the 423 raw logs contains exactly one `[ RUN ]` identity equal to its selector
   row, exactly one matching `[ OK ]`, `Running 1 test`, and `1 test` passed; no raw log contains a failed test.
9. **Cumulative result:** inherited selector422 is **422/422**, appended row423 is **1/1**, and `non-pass.tsv` has no
   data row. The primary summary is **423/423 PASS**, zero RED/SKIP/timeout/selection mismatch.
10. **Immutable postflight:** package, materialized source and execution-view byte+mode census files are exactly equal
    pre/post. Their census SHA-256 values are respectively `92130fdb...9f86`, `6678fd3d...3dfb`, and
    `fbbdce5a...6647`. Postflight records `immutability=true` and false for configure, compile, relink, generated
    discovery, package repair, and source/test/fixture/selector mutation.
11. **No stitched subject:** the authoritative run is one immutable-package execution. No generated discovery, retry
    stitching, alternate package, or repaired execution view contributes acceptance credit.

These checks independently reproduce the mechanically-green TB5 gate rather than inheriting its report conclusion.

## 3. Independent boundary raw-precondition review

The decisive semantic question was whether row423 is genuine pre-production test authority under frozen CP-COND §10/§12.
It is.

### 3.1 Raw witness and independent oracle

`make_boundary_truncation_witness()` constructs a raw five-face open fan around vertex 0 from raw binary64 mesh and
cross-field bytes before any conditioner call. Every fan face has one opposite ring edge with source incidence one.
The test-local oracle:

- exactifies every binary64 scalar by bit decomposition to GMP rationals;
- independently derives one closed face fan and unique center;
- verifies the per-face Z4 cross structure exactly;
- chooses each cross-face branch transport by exact rational dot-product maximization and requires one common offset;
- derives offsets `[3,3,3,3,3]`, residue 3, hence signed cycle numerator **-1**;
- solves ray/segment intersection with exact rational cross/dot arithmetic; and
- requires positive ray parameter and strict `0 < boundaryParameter < 1` on an edge whose independent incidence is
  exactly one.

A static dependency check over the witness/oracle/reconstruction helper region finds **zero** calls to
`condition_surface_cell_input`, `FieldTransportAtlas`, `FieldAlignedCurveNetwork`, or `trace_surface_field`. Thus the
raw precondition is not read back from conditioner/A0/A1/A2a production output.

A second, independently written Python exact-rational derivation from the same raw construction re-derived:

- singularity vertex `0`;
- cycle numerator `-1`;
- source face `0`, field branch `0`;
- boundary edge `{1,2}` with incidence `1`;
- raw `boundaryParameter = 5960850622990838592579032842240 / 11921701245981676844040653741493`.

This is exact/discrete authority, not epsilon/proximity evidence.

### 3.2 Load-bearing mutation

The test changes only face-0 raw field bytes to `cross_row_for_angle(2*pi/9)` and re-runs the same oracle. The exact
independent re-derivation preserves the carrier `(vertex=0, cycle=-1, face=0, branch=0, edge={1,2})` but changes the
exact boundary parameter to
`52149126351258260866451405537280 / 95141284647432590305679220304487`. Therefore the complete oracle result changes.
The field datum is load-bearing rather than decorative, satisfying the existing lessons **“An oracle built on the
mechanism it tests is not yet a test”** and **“A fixture can contain a structure without exercising it — require the
discriminating twin.”**

### 3.3 Conditioner preservation and authority separation

Only after the raw and mutated oracles are established does row423 call the conditioner. `production_identity()` is
the frozen bit-preserving default policy: geometry/field quantization, exact-duplicate merge, field-branch
canonicalization and sliver refusal are all disabled by default. The conditioner returns `Produced`; the independent
product validator returns no failure. Reconstruction uses only the emitted certificate/correspondence surfaces:
conditioned-to-raw vertex ownership, face correspondence, the field `branchPermutation`, and feature correspondence.
The same independent raw oracle on that reconstructed view equals the original oracle exactly.

The reconstruction does not create a second semantic writer; it is a test-side view used only to verify what the
certificate says was preserved. Production remains the single writer frozen by CP-COND.

### 3.4 No hidden semantic or fixture weakening

Repository history comparison from entering accepted semantic source `702d9e10...17a5` to packaged source
`07984711...03f0` shows **no `src/`, `include/`, benchmark, or fixture-file change**. The semantic cutover consists of
test authority in `tests/InputConditionerTests.cpp`, one CMake packaged-owner guard, selector423, and
control/documentation lineage. The only removed test material is the old report-only
`BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` plus its helper that returned literal `false`; it was not
an accepted selector row. Accepted selector422 bytes are unchanged. A second history comparison from package source to
the Review snapshot head finds documentation/control cleanup only and no later product/test/CMake/selector drift.

The previously rejected “genuinely unreachable” escape is not reopened: no new primary evidence falsifies TB4 Review's
accepted A2a boundary-termination reachability evidence.

## 4. Frozen CP-COND exit condition — conjunct-by-conjunct

One immutable candidate package now runtime-proves the cumulative selector423, and the Review independently validates
its authority:

| Frozen §12 conjunct | Reviewed evidence | Verdict |
|---|---|---|
| 1. single-writer conditioned product + exact policy identity | rows409, 420-422; production-identity/static history check; no second writer/product drift | **PASS** |
| 2. independently validated raw-to-conditioned correspondence | rows409-411 and 417; independent validator/certificate surfaces | **PASS** |
| 3. typed inadmissibility + exact sliver refusal | rows412-413 and 416 | **PASS** |
| 4. high-valence, negative-index, boundary-truncated preconditions independently proved | rows414-415 and independently reviewed row423 | **PASS** |
| 5. non-vacuous correspondence tamper discrimination | row417 tamper matrix | **PASS** |
| 6. exact idempotence | row418 | **PASS** |
| 7. exact S6 same-cell equivalence | row419 | **PASS** |
| 8. accepted CP3 A3/A4 semantics unchanged; selector408 preserved | no production semantic delta; selector423 first408 exact `c689c0cd...b0484` | **PASS** |

All eight frozen conjuncts are satisfied. **M4-CP-COND is CLOSED / ACCEPTED.**

## 5. Candidate, accounting and authority disposition

`M4-CP-COND-TB4-REV-CAND-01` is **CLOSED / RECOVERY/TEST-AUTHORITY PROVED / NON-STABLE**. CB5 supplied the exact
falsifier TB4 Review required and TB5 proved it in the complete cumulative gate. There is no accepted PASS->RED event,
so stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

Current accepted M4 runtime authority advances to:

- package `10331193451` / semantic source `07984711db59eaa228820e7d44e5552a652edadf`;
- selector423 **423/423**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`.

Selector422/package `10327643907` remains the accepted predecessor and historical CP-COND recovery baseline.

Carried obligations are not silently absorbed by this closure:

- `M4-CP3-TB1-R1-REV-OBS-01` remains due before M4-CP4;
- `M4-CP3-CB4-REV-OBS-02` remains due on the next legitimate row399 touch;
- TB3 row408 provenance remains a historical-claim bound;
- the three `G4-B002` produced-witness debts remain M4-CP4 gates;
- the two `G4-B003` debts remain M5 gates.

## 6. Consolidation disposition

The M4 consolidated record now indexes the three files already retired by CB5/TB5 stale-evidence cleanup and the
superseded current-head CP-COND per-turn records folded at closure. Selector files, frozen definitions, durable policy,
this Review, and the new closure record remain retained authority.

## 7. Exact successor — `M4-CP-SCALE-DEFN`

CP-SCALE is now unblocked, but its high-level M4 definition is not enough to begin semantic mutation safely. The exact
next turn is **`M4-CP-SCALE-DEFN`**, planning/runtime-free under
`Architecture_M4_CP_SCALE_DEFN_Plan.md`. It must freeze S1-S5 evidence surfaces, witness reachability/preconditions,
gating versus diagnostic membership, exact-fallback dominance, and one bounded CB successor before any implementation.

STOP if that DEFN would guess a numeric threshold, turn a certified filter into alternate semantic authority, use an
elapsed-time cutoff as S3 semantics, backtrack S4 into A2a', credit genus1 as S5, or gate an unproved witness.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector423 first422 is exact selector422 `bbd496f3...f7cc`; first408 is exact accepted selector408 `c689c0cd...b0484`. |
| Decisive claims independently re-derived | PASS — artifact hashes/manifests, ledger/raw logs, owner map, immutable postflight, source history, exact raw boundary oracle and conditioner reconstruction independently checked. |
| Non-vacuity checked | PASS — row423's load-bearing raw-field mutation changes the exact oracle result; inherited tamper gates remain cumulative-green. |
| Prior obligations discharged/carried | Boundary test-authority candidate discharged; CP3 observations, row408 provenance, `G4-B002` and `G4-B003` debts explicitly carried. |
| Stable accounting | UNCHANGED — **49 / 14 / 35**, produced-witness debt **5**. |
| New candidates/obligations recorded | None. CP-SCALE's already-frozen S1-S5 work becomes current priority; no new regression candidate is created. |
| ORIENTATION currency line | Updated to `M4-CP-COND-TB5-REV`, 2026-09-14; package10331193451/selector423 accepted and CP-COND closed. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 current authority/checkpoint updated; §4 notes the accepted boundary raw witness without conflating it with production milestone witnesses; §7 re-prioritized to CP-SCALE; §8 marks the raw-oracle pattern discharged and cites existing lessons, no new pattern. |
| CHANGELOG | Updated with reviewed promotion/closure and exact successor. |
| ROADMAP | CP-COND marked CLOSED/ACCEPTED; CP-SCALE marked next at DEFN. |
| Selector manifest | selector423 receipt promoted to ACCEPTED CURRENT M4 RUNTIME AUTHORITY after TB5 Review. |
| LESSONS | No new reusable defect pattern. Existing raw-oracle/non-vacuity/discriminating-twin lessons apply and are cited here/ORIENTATION. |
| Consolidation under CLEAN_UP_POLICY | M4 consolidated index updated; stale CB5/TB5 files and superseded CP-COND per-turn records indexed before folding. |
| Successor frozen | `M4-CP-SCALE-DEFN` under `Architecture_M4_CP_SCALE_DEFN_Plan.md`; planning/runtime-free. |
| Turn boundary held | PASS — Review performed no Directional runtime, configure/compile/package, product/test/fixture/selector semantic mutation, or CP-SCALE implementation. |
| review_check.py boundary | **PASS** — `review_check.py boundary --expect-selector 423=4e67e4dc...d89343` reports no product/test/fixture/build mutation, no selector mutation, all committed selector hashes preserved, durable markers preserved, and `ALL CHECKS PASSED`. |
| Pushed to origin, branch in sync | **PASS AT TURN CLOSEOUT** — durable Review/closure/plan patch is required to land on the configured working branch, temporary control state is then removed workflow-first, and final PR authority is re-read before the mandatory final comment; no local-only semantic work exists. |
