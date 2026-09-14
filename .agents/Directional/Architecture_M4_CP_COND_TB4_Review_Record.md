# M4-CP-COND-TB4-REV — Review Record

**Turn:** `M4-CP-COND-TB4-REV`
**Disposition:** **SELECTOR422 + PACKAGE ACCEPTED / CP-COND REMAINS OPEN / BOUNDARY RAW-PRECONDITION AUTHORITY MISSING / NON-STABLE**
**Runtime/build/product/test/fixture/selector mutation:** none
**Accepted runtime authority after this Review:** package `10327643907` / selector422 **422/422**
**Exact successor:** `M4-CP-COND-CB5`

## 1. Review decision

TB4 mechanical evidence is independently upheld. Immutable CB4 artifact `10327643907` is accepted as the current M4 runtime authority and `Architecture_M4_CP_COND_CB4_Required_Green_Selector_422.txt` is accepted as the current cumulative selector:

- selector422 is exactly **422 LF rows**, SHA-256 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- its first408 is byte-identical to accepted selector408, SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`;
- rows409-422 are exactly the fourteen already-reviewed CP-COND gates in frozen order;
- TB4 executes selector422 **422/422 PASS**, including predecessor408 **408/408** and appended gates **14/14**;
- the report-only boundary identity executes once as the expected SKIP and remains outside selector422;
- zero gating RED, timeout or actual-selection mismatch occurs;
- package/source/execution-view postflight is byte+mode identical to preflight;
- the evidence checksum manifest is non-self-referential and independently verifies every substantive evidence file.

This closes `M4-CP-COND-TB3-REV-CAND-01` **RECOVERY PROVED / SELECTOR-AUTHORITY REPAIRED / NON-STABLE** and closes `M4-CP-COND-TB3-REV-OBS-01` **ORCHESTRATION REPAIRED / NON-BLOCKING**.

`M4-CP-COND` nevertheless remains **OPEN**. Frozen §12 conjunct 4 still requires an independently proved boundary-truncated raw witness precondition. TB4 deliberately does not provide one.

Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 2. Immutable evidence independently re-derived

Review reopened `/mnt/data/M4-CP-COND-TB4-EXEC-evidence.tar.gz` rather than trusting the EXEC summary. The evidence archive SHA-256 is `4a840f8ea53d054dcade6672da59fac6840091167b835cf5d5037a34502eb016`.

Independent checks over the raw evidence established:

1. `EVIDENCE_SHA256SUMS` contains exactly the substantive evidence files and excludes itself; `sha256sum -c` passes for every entry.
2. Selector ledger contains exactly 422 data rows with ordinals 1..422, unique intended identities, `selected=1`, PASS, exit 0 and timeout 0 for every row.
3. Raw per-process logs contain the intended identity and one-test PASS marker for every selector row; no `FAILED` marker occurs.
4. Report-only ledger contains exactly one row, ordinal423, identity `InputConditionerCPCondCB1.BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker`, `selected=1`, SKIP, exit 0, timeout 0.
5. Owner census re-derives **30 authority-kernel / 276 producer / 75 completion / 41 validation = 422**.
6. Package/source/execution-view pre/post censuses are identical.
7. The runtime boundary records no configure, compile, relink, generated discovery, package repair, source/test/fixture/selector mutation or benchmark execution.

The EXEC report itself re-hashes to `89a997bb511dfe3a7da3b10b19c24891e0f9d2a0577e47e4faffa36dfc1009a7`; the non-self-referential checksum manifest re-hashes to `d8625429b4b3d96a561da6c348c0db04287b355fcdeb41aacab22495cbe8b297`.

## 3. Selector/package authority

CB4 did not alter the fourteen gate semantics. GitHub history comparison from corrected test-authority source `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675` to packaged CB4 source `702d9e10afff1fc3ac2ed3f3458acf8f19b617a5` contains no product/test/fixture/CMake semantic change; it is selector/document/orchestration publication only.

TB3 Review had already independently accepted the gate semantics, including the corrected raw-derived negative-index oracle and its one-LSB falsifier. TB4 now supplies the missing cumulative-selector proof on the unchanged semantic subject. The prior selector-publication objection is therefore fully discharged.

The accepted M4 runtime authority is promoted from CP3 package `10307919492` / selector408 to CB4 package `10327643907` / selector422. This promotion does **not** imply CP-COND closure; selector acceptance and checkpoint exit are distinct claims.

## 4. Boundary-truncated conjunct remains unsatisfied

Frozen `Architecture_M4_CP_COND_Frozen_Definitions.md` §10 requires the boundary item to have an **independent source-boundary/field construction that proves, before production execution, that one separatrix is truncated by a real source boundary and that conditioning preserves the data on which the derivation depends**. §12 conjunct 4 requires that precondition to be independently proved; the TB3 Review addendum correctly forbids treating merely-unproved reachability as the unreachable escape hatch.

The current report-only identity is intentionally not such an oracle. `tests/InputConditionerTests.cpp` constructs `make_square_input()`, checks only that it has two faces, calls `exact_boundary_truncation_precondition_is_proved_without_a2a()` which returns `false`, and SKIPs. It does not derive a singularity, a separatrix route, or a source-boundary truncation from raw bytes.

The alternate “genuinely unreachable” route is also not supportable from current A2a authority. Accepted inherited selector identities already demonstrate that singularity-port candidate traces can terminate on mandatory barriers on the open two-ring disc. That fixture supplies no hard-feature edges, while A2a's `mandatoryByEdge` admits only `SourceBoundary` and `HardFeature`; therefore those terminal mandatory barriers are genuine source boundaries. In particular:

- `FieldAlignedCurveNetwork.TracesSingularityPortsIntoBranchConsistentCandidateSegments` proves a singularity-port trace terminates at a mandatory barrier without crossing it;
- `FieldAlignedCurveNetwork.CandidateTraceStopsAtMandatoryBarrierWithoutCrossing` proves at least one such terminal mandatory carrier exists;
- both identities are in the accepted predecessor prefix and pass again inside TB4 selector422.

Those production-observing identities are enough to reject a claim of **genuine unreachability**, but they do not satisfy CP-COND's stronger **pre-production independent raw-precondition oracle**. Production output cannot certify the raw precondition of the gate that is supposed to test production preservation.

Therefore CP-COND has one exact remaining exit defect: independent boundary-truncated raw test authority plus cumulative gate credit.

## 5. Exact successor — `M4-CP-COND-CB5`

CB5 is a bounded **test-authority + selector-publication Code + Build** turn. It may not change production behavior.

It must:

1. author one test-local raw witness with a real source boundary and field/singularity data suitable for a boundary-truncated separatrix;
2. author an **independent oracle over the raw subject** that proves the source-boundary/field precondition before invoking the conditioner. The oracle must not call `condition_surface_cell_input`, `FieldTransportAtlas`, `FieldAlignedCurveNetwork`, `trace_surface_field`, or read any production output to obtain its answer;
3. derive the relevant singularity/separatrix route and terminal source-boundary locus from raw topology/field bytes, using exact/discrete arithmetic for the authority decision;
4. include a mutation falsifier that changes or invalidates the oracle's conclusion when the load-bearing raw field/route data is changed;
5. run the conditioner under the frozen production policy and prove `Produced` preserves the exact source-boundary, field and correspondence data on which the independent oracle depends; rechecking the independent oracle on a raw view reconstructed from the conditioned product must yield the same boundary-truncation proof;
6. replace the current report-only placeholder with one gating identity named `InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`;
7. publish selector423 = accepted selector422 byte-for-byte as rows1-422 plus that identity as row423. First422 must hash to `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`; expected ownership becomes **30 / 277 / 75 / 41 = 423**;
8. update only the necessary test/CMake ownership metadata and selector/manifest/docs; no `src/`, `include/`, fixture file, benchmark, accepted selector row, A3/A4 semantic or public fallback change is authorized;
9. compile/package the complete seven-target owner set with GMP/GMPXX and `runtimeExecution=false`; execute no Directional runtime;
10. freeze an artifact-only TB5 plan: selector423 **423/423** in fresh exact-filter processes, exact immutable pre/postflight, then mandatory `M4-CP-COND-TB5-REV`.

### CB5 STOP/falsifiers

STOP and return to Review/DEFN before semantic mutation if any of the following is true:

- the proposed oracle needs production tracing/atlas output to prove its precondition;
- the witness can only be justified by epsilon/proximity rather than exact/discrete raw authority;
- a raw mutation leaves the purported oracle proof unchanged when that mutated datum is claimed load-bearing;
- proving the witness requires a production algorithm change rather than test authority;
- conditioned output cannot preserve/reconstruct the independent raw proof under the frozen conditioner contract;
- selector423 cannot retain exact selector422 as its first422 bytes;
- the correction needs a second value writer, selector weakening/reordering, fixture weakening, or CP-SCALE/CP4/M5+ scope.

## 6. Carried obligations

- `M4-CP3-TB1-R1-REV-OBS-01` remains owned by the first later independently falsifiable M4 test-authority turn before CP4. CB5 may discharge it only if the boundary-witness work naturally supplies the required same-region multiplicity-2 independent oracle; it must not distort the witness to absorb unrelated debt.
- `M4-CP3-CB4-REV-OBS-02` remains owned by the next legitimate row399 touch.
- TB3 row408 provenance remains a historical-claim bound.
- three `G4-B002` produced-witness debts remain M4-CP4 gates; two `G4-B003` debts remain M5 gates.
- CP-SCALE remains blocked until CP-COND closes.

## 7. Review closeout checklist

| Review requirement | Result |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector422 `bbd496f3...f7cc`; first408 `c689c0cd...484` |
| Decisive claims independently re-derived | PASS — raw ledgers/logs, owner census, exact immutability, manifest integrity, selector prefix and package semantic-history comparison |
| Non-vacuity checked | PASS for accepted fourteen gates via prior independent Review + unchanged semantics + cumulative rerun; boundary raw oracle remains explicitly MISSING rather than credited |
| Prior obligations discharged/carried | selector-publication candidate CLOSED; checksum observation CLOSED; boundary conjunct re-carried as one explicit test-authority candidate; other named obligations retained |
| Stable accounting | UNCHANGED — **49 / 14 / 35**, debt **5** |
| New candidate/owner | `M4-CP-COND-TB4-REV-CAND-01` -> CB5 -> TB5-EXEC -> TB5-REV |
| ORIENTATION | updated §§3/7/8; §4 unchanged because no witness state changed |
| CHANGELOG | updated |
| ROADMAP | updated; selector422 accepted but CP-COND remains OPEN |
| Selector manifest | selector422 marked accepted and Review receipt appended; selector bytes unchanged |
| LESSONS | no new entry — existing independent-oracle/non-vacuity and selector-enforcement lessons already cover the instance |
| Consolidation | TB3/CB4/TB4 consumed per-turn records folded into `M4_Consolidated_Record.md`; current TB4 Review + CB5 plan retained |
| Successor | exactly one: `M4-CP-COND-CB5` |
| Turn boundary | PASS — runtime-free Review; no product/test/fixture/selector/build-source mutation |
| `review_check.py boundary` | PASS locally against the exact b49afb34 snapshot baseline — ALL CHECKS PASSED; no product/test/fixture/build or selector mutation |
| Pushed to origin, branch in sync | PASS — ChatGPT Web equivalent: connector PR/branch authority was re-read after durable publication and confirmed the working branch at the published Review head, open/draft/unmerged; this session has no permitted local origin worktree for `git status -sb`. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** Accepting selector422 and the package at **422/422** while holding CP-COND open on a
single named exit defect is correct on both halves. Accounting holds at **49 / 14 / 35**, debt **5**.

### V1 — the conjunct-4 constraint is honoured, and exceeded

The `M4-CP-COND-TB3-REV` addendum required the boundary-truncated item to resolve into one of the two states
frozen §12 conjunct 4 admits — independently proved, or proved genuinely unreachable — and, failing both, to be
declared unsatisfied rather than parked under the hatch. §4 does exactly that, and then goes further than the
constraint asked.

It **affirmatively rejects** the unreachability route rather than merely declining to claim it, citing two
identities that show the situation is reachable in production:
`FieldAlignedCurveNetwork.TracesSingularityPortsIntoBranchConsistentCandidateSegments` and
`FieldAlignedCurveNetwork.CandidateTraceStopsAtMandatoryBarrierWithoutCrossing`. Both were verified here to sit
at selector rows **17** and **4** — inside the accepted prefix — and both pass again inside TB4. That closes the
escape permanently instead of leaving it available to a future turn under time pressure.

The closing distinction is the precise one: those production-observing identities are enough to **reject**
genuine unreachability, yet they do not **satisfy** §10's stronger pre-production independent construction
requirement. Production observation and pre-production independent authority are different evidential objects,
and conflating them is exactly how the hatch would have been misused.

Keeping ordinal423 `BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` outside selector422 as a
report-only row is the honest form of "explicit blocker rather than fabricated" — the blocker is visible in the
ledger and claims nothing it has not proved.

### V2 — lineage re-derived, and the full M4 chain is byte-exact

`Architecture_M4_CP_COND_CB4_Required_Green_Selector_422.txt` has **422** rows, hashes to `bbd496f3396bd656…`,
and its **first 408 rows hash to `c689c0cd8a51f9a8…`** — byte-identical to accepted selector408. The appended
count is exactly `422 − 408 = 14`, matching the fourteen CP-COND gate identities.

With this link the whole M4 selector chain has now been verified byte-exact by this reviewer, each link at the
turn that created it:

**373 ⊂ 380 ⊂ 382 ⊂ 394 ⊂ 403 ⊂ 408 ⊂ 422**

No accepted prefix has shifted at any point across CP1, CP2, CP3 and CP-COND.

### V3 — dispositions confirmed

`M4-CP-COND-TB3-REV-CAND-01` closes recovery-proved with the selector-authority gap repaired, and
`M4-CP-COND-TB3-REV-OBS-01` closes with the evidence-manifest self-hash repaired. Accounting is correctly
unchanged: no accepted ordinal transitioned PASS → RED, and predecessor408 re-ran **408/408** inside the
cumulative gate rather than being assumed.

### V4 — forward constraint for `M4-CP-COND-CB5`

CB5 owns the remaining defect, and §4's own reasoning implies a constraint worth stating before the build: the
new boundary oracle must be **pre-production independent**. It may not establish its precondition by observing
production output, because this Review has just shown that production observation — while sufficient to reject
unreachability — does not satisfy §10.

The negative-index repair accepted at TB3 is the working template, and it is worth following deliberately rather
than rediscovering: construct the raw configuration directly, compute the precondition from the **raw bytes** by
the test's own exact method, assert it **before** the conditioner runs, and make it falsifiable by a raw
mutation. An identity that would still pass when its raw input is perturbed has not established a raw
precondition, whatever its name says.
