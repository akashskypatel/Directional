# M4-CP-COND-TB3 Review Record

**Turn:** `M4-CP-COND-TB3-REV`
**Disposition:** COMPLETE / NEGATIVE-INDEX AUTHORITY ACCEPTED / TB3 MECHANICS ACCEPTED / SELECTOR-AUTHORITY GAP FOUND / CP-COND OPEN
**Runtime/build/product/test/fixture/selector mutation:** none
**Exact successor:** `M4-CP-COND-CB4`

## 1. Decision

The corrected negative-index authority is **accepted**. `M4-CP-COND-TB2-REV-CAND-01` is **CLOSED / TEST-AUTHORITY REPAIRED / RUNTIME-PROVED / NON-STABLE**. CB3 replaced the detached authored `-1` with an exact test-local oracle over the actual raw binary64 mesh/branch bytes, and TB3 executes that identity GREEN on immutable artifact `10325879420`.

TB3's mechanical result is also accepted as raw execution evidence: focused **14/14 PASS**, one expected report-only boundary **SKIP**, accepted selector408 **408/408 PASS**, gating **422/422 PASS**, zero semantic RED/crash/timeout/actual selection mismatch, and exact immutable postflight.

`M4-CP-COND` nevertheless **does not close** and artifact `10325879420` is **not promoted as accepted checkpoint authority**. The reason is a separate frozen selector-authority contract that the TB3 surface does not satisfy:

- `Architecture_M4_CP_COND_Frozen_Definitions.md` §12 requires CP-COND exit to be runtime-proved **"on a cumulative append-only selector"**;
- `Architecture_M4_DEFN_Frozen_Definitions.md` §12 states that CP-COND semantic admissibility/correspondence identities are gating once their raw preconditions are independently verified and that a prose obligation without selector identity is not gate-enforced;
- TB3 keeps selector408 byte-frozen and runs the fourteen CP-COND identities only as a separate focused surface. Those identities therefore have runtime evidence, but they are not yet members of the cumulative required-green selector.

This is not a product RED and not a reason to reject the repaired oracle. It is a review-time selector/publication defect. `M4-CP-COND-TB3-REV-CAND-01` is opened **OPEN / SELECTOR-AUTHORITY / CP-COND GATING IDENTITIES OUTSIDE CUMULATIVE SELECTOR / NON-STABLE**.

Accepted M4 runtime authority therefore remains CP3 package `10307919492` / selector408 **408/408**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 2. Independent TB3 mechanical re-derivation

Review re-opened the immutable CB3 package and the raw TB3 evidence bundle rather than copying the EXEC report.

- downloaded artifact ZIP SHA-256 re-computes to `d046b8cbdcfe22af5ca732139612e96673d597fef47b5e36d1a54b1542493b2b`;
- package `SHA256SUMS` verifies completely; `metadata/source-commit.txt` is exactly `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675`;
- GMP/GMPXX is present in the package link evidence;
- selector408 re-hashes to `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; first403 re-hashes to `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- owner census is **30 authority-kernel / 262 producer / 75 completion / 41 validation = 408**;
- focused ledger is **14 rows**, all `selected=1`, all PASS, SHA-256 `c5adebb56f283edd98c50d39b97f0b9be1eded2b59d00f5313e47e83928f65e8`;
- report-only ledger is **1 row**, selected once and SKIP, SHA-256 `201f9efa06b701dcd3a710f3565cd53ce81c52bdd402dd36769d4ca43c68c084`;
- selector ledger is **408 rows**, all `selected=1`, all PASS, SHA-256 `9d9b910c54c659f76c8ed492e3a0d22df63d65bbdacd0898b844919e10358495`;
- combined ledger is **423 rows**, all `selected=1`, SHA-256 `bbe96d77a18844f9c050924f4964b8cb052f40f6f1ec75d980ae9c945ae3a034`;
- package, packaged-source and derived execution-view before/after census hashes are pairwise identical (`e36b87bf...a2be`, `305e5477...f0b8`, `952f1552...5d80` respectively);
- orchestration revalidation records `runtime_reexecuted=false`, `package_mutated=false`, `source_mutated=false`, **423** completed processes, and zero corrected selection mismatch.

The final `awk NR>1` exit-90 is correctly classified as post-runtime evidence-checker false-positive: with multiple input TSVs, only the first header is skipped. `FNR>1` skips each input header and re-derives zero mismatches without rerunning a Directional binary.

## 3. Corrected negative-index oracle — independently upheld

Review re-opened the packaged `tests/InputConditionerTests.cpp` rather than accepting the identity name or its GREEN verdict as self-proving.

The helper now reads the raw subject itself:

1. `exact_binary64()` decodes each finite binary64 bit pattern into an exact GMP dyadic rational; no production exactifier or tolerance is called.
2. `independent_closed_face_fan()` derives a unique closed face fan from `raw.faces`; the committed five-triangle witness has exactly one eligible closed fan.
3. For every raw face the oracle exactifies source vertices and all four branches, rejects zero/degenerate/non-coplanar geometry, and proves each branch is tangent, opposite-paired, orthogonal, equal-norm and consistently handed.
4. Across each adjacent fan face pair it computes all sixteen exact dot scores, requires a unique maximizing target for every branch, and requires one common `Z4` offset across the four branches. The five committed transitions derive offset `3` each; accumulated residue is `3`, represented in the signed principal class as numerator `-1`.
5. The expected value therefore depends on actual raw face/branch bytes and never reads conditioner output or authored `72°/90°` constants.
6. The one-LSB mutation of `rawCrossField(0,0)` changes the raw subject without changing the fixture topology. It breaks the exact opposite-pair/admissibility relation and makes the oracle return no value, so the raw precondition is mutation-discriminating.
7. After `production_identity()` produces the conditioned product, the same independent oracle is re-run on the preserved conditioned raw bundle and must reproduce both the raw numerator and the complete transport vector.

For this planar fan, comparing raw cross directions by exact dot product is a valid discrete transport oracle because all incident faces are independently proved coplanar with the same orientation before transport is evaluated. No producer matching/singularity/finalization helper is used.

This discharges the precise TB2 objection: the negative-index expectation is now derived from the raw subject, proves admissibility, is independent of the producer under test, and has a falsifying raw-data mutation.

## 4. CP-COND exit re-check

The semantic exit conjuncts are now individually evidenced:

- single-writer identity policy / pre-A0 routing — already independently upheld by TB2 Review and re-proved by accepted selector408 under the conditioner-routed production build;
- certified raw correspondence and distinct raw/conditioned digests — focused identity PASS;
- exact quantization/merge operation surface — focused identities PASS;
- exact sliver refusal — focused PASS;
- high-valence raw precondition — independently counted and PASS;
- negative-index precondition — repaired as §3 and PASS;
- deliberately contradictory field — typed exact refusal PASS;
- certificate tamper discrimination — PASS;
- exact idempotence — PASS;
- S6 same-cell equivalence — PASS;
- legacy/tolerant bypass prohibition and raw-entry fail-closed routing — PASS;
- boundary-truncated separatrix — remains the explicitly permitted **blocked / report-only / non-selector** item because independent A2a reachability is not proved.

The remaining unsatisfied exit conjunct is not semantic behaviour; it is the **cumulative selector publication requirement**. Until the fourteen now-credible CP-COND gates are appended to the accepted selector lineage and runtime-reproved there, CP-COND cannot close without weakening the frozen definition.

## 5. Evidence-manifest observation

Review also found one orchestration-only evidence-packaging defect. `EVIDENCE_SHA256SUMS` contains a self-entry equal to SHA-256 of the empty file (`e3b0c442...b855`), because the manifest was included in the file enumeration while its own redirected output was still empty. Consequently `sha256sum -c EVIDENCE_SHA256SUMS` fails **only** its self-entry. Every substantive evidence file covered by the manifest verifies, and the complete evidence archive is independently pinned by outer SHA-256 `b24ff247ce72b48d4ccf80af3b8a01de7e7b6ec76ebad4e3efe9916757b82b90`.

`M4-CP-COND-TB3-REV-OBS-01` is recorded **ORCHESTRATION / EVIDENCE-MANIFEST SELF-HASH / NON-BLOCKING**. TB4 evidence generation must exclude the checksum output from its own input enumeration (or otherwise generate a non-self-referential manifest). This observation changes no TB3 semantic result.

## 6. Accounting and carried obligations

No accepted-green identity became RED. Stable accounting remains **49 / 14 / 35**, debt **5**.

- `M4-CP-COND-TB2-REV-CAND-01` — **CLOSED / TEST-AUTHORITY REPAIRED / RUNTIME-PROVED / NON-STABLE**.
- `M4-CP-COND-TB3-REV-CAND-01` — **OPEN / SELECTOR-AUTHORITY / NON-STABLE**, owner `M4-CP-COND-CB4 -> TB4-EXEC -> TB4-REV`.
- `M4-CP-COND-TB3-REV-OBS-01` — **OPEN / ORCHESTRATION / NON-BLOCKING**, owner TB4 evidence harness; falsifier is a checksum manifest whose own verification passes without special casing.
- `M4-CP3-TB1-R1-REV-OBS-01` — carried to first later independently falsifiable M4 test-authority turn before CP4.
- `M4-CP3-CB4-REV-OBS-02` — carried to next legitimate row399 touch.
- TB3 provenance warning — carried as historical-claim bound.
- `G4-B002` produced-witness debt (3) — remains CP4 gating.
- `G4-B003` produced-witness debt (2) — remains M5 gating.

## 7. Exact successor

`M4-CP-COND-CB4` is a **selector-authority/package-only Code + Build** control turn. It must append the fourteen already-authored CP-COND gate identities, in the frozen focused order, after the exact selector408 prefix to create selector422. It may not change product, test, fixture, CMake, owner mapping, or any existing selector row. The boundary-truncated identity remains report-only and must not enter the selector.

CB4 must prove the first 408 selector rows hash exactly to `c689c0cd...484`, publish selector422 + manifest metadata, compile/package the unchanged seven-target owner set with GMP/GMPXX and `runtimeExecution=false`, and execute no Directional runtime. Any need to change a test or product semantic is a STOP back to Review/DEFN.

The frozen TB4 successor is artifact-only `M4-CP-COND-TB4-EXEC`: run selector422 once per exact-filter fresh process plus the one report-only boundary witness. Mechanical GREEN is selector422 **422/422 PASS** with rows 409-422 the fourteen CP-COND gates **14/14 PASS**, predecessor rows 1-408 **408/408 PASS**, one expected report-only SKIP, zero RED/crash/timeout/selection mismatch, corrected non-self-referential evidence checksums, and exact immutable postflight. Mandatory `M4-CP-COND-TB4-REV` alone may promote/close.

## 8. Consolidation

This Review folds consumed per-turn CP-COND documents after preserving their durable facts in `M4_Consolidated_Record.md` and this record. Retained CP-COND authority after closeout is:

- `Architecture_M4_CP_COND_Frozen_Definitions.md`;
- `Architecture_M4_CP_COND_TB3_EXEC_Report.md` as current runtime evidence;
- this `Architecture_M4_CP_COND_TB3_Review_Record.md`;
- exactly one next plan, `Architecture_M4_CP_COND_CB4_Code_Build_Plan.md`;
- `M4_Consolidated_Record.md`, selectors/manifest and durable project policies/records.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; first403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` |
| Decisive claims independently re-derived | PASS — package digest/manifest/source/GMP, 14+1+408 ledgers, owner census, immutable censuses, orchestration revalidation, and negative-index raw exact oracle |
| Non-vacuity checked | PASS for repaired negative-index authority — LSB raw mutation invalidates the exact oracle; FAILS CP-COND closure only on missing cumulative-selector membership, not semantic vacuity |
| Prior obligations discharged/carried | TB2 negative-index candidate closed; OBS-01/OBS-02, provenance bound and debts re-carried; new selector candidate + evidence-manifest observation assigned |
| Stable accounting | UNCHANGED — **49 / 14 / 35**, debt **5**, accepted package `10307919492`, selector408 408/408 |
| New candidates/obligations recorded | `M4-CP-COND-TB3-REV-CAND-01` selector-authority/non-stable; `M4-CP-COND-TB3-REV-OBS-01` evidence-manifest/non-blocking; tracker updated |
| ORIENTATION currency line | `M4-CP-COND-TB3-REV`, 2026-09-13 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a (no witness state changed); §8 updated with selector-publication instance |
| CHANGELOG | TB3 Review entry added |
| ROADMAP | CP-COND remains OPEN; selector-authority correction and CB4 successor recorded |
| Selector manifest | n/a — Review mutates no selector and accepts no new selector; CB4 owns selector422 publication |
| LESSONS | n/a — existing selector/gate-enforcement and evidence-integrity rules cover these instances; no genuinely new pattern added |
| Consolidation under CLEAN_UP_POLICY | TB2 EXEC report, TB2 Review record and consumed TB3 EXEC plan folded; retired CB3 plan/report indexed; current TB3 report + Review + one CB4 plan retained |
| Successor frozen | `M4-CP-COND-CB4` under `Architecture_M4_CP_COND_CB4_Code_Build_Plan.md`, with pre-mutation prefix/identity/owner falsifiers and STOP rules |
| Turn boundary held | PASS — runtime-free Review; no product/test/fixture/selector/benchmark/build-source mutation |
| review_check.py boundary | PASS — ALL CHECKS PASSED; no product/test/fixture/build or selector mutation. Accepted M4 selector408 was additionally re-hashed explicitly at `Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt` = `c689c0cd...484` because the repository also retains a historical M3 selector numbered 408. |
| Pushed to origin, branch in sync | PASS — final publication is verified by re-reading the applied working-branch/PR head through the GitHub connector before closeout; no later repository mutation is permitted before the final summary comment. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** Accepting the corrected negative-index authority is right, and refusing to close
CP-COND on a selector-publication gap — rather than treating fourteen focused PASSes as equivalent to a
cumulative gate — is the correct call. Accounting holds at **49 / 14 / 35**, debt **5**.

### V1 — the CB3 shape constraint is discharged, and implemented more sharply than required

The `M4-CP-COND-TB2-REV` addendum required the oracle to read the **raw input**, compute the index by its own
exact method independent of the producer under test, and be falsifiable by a raw perturbation. All three hold
in `tests/InputConditionerTests.cpp`:

- `independent_negative_index_oracle(witness.raw)` takes the raw bundle, not the conditioner's output, so the
  self-authorizing failure mode is closed (`:488`);
- the index is derived and then compared — `EXPECT_EQ(rawOracle->cycleNumerator, -1)` (`:490`) — rather than
  asserted from detached builder arithmetic;
- the falsifier is **stronger than specified**: `:493-497` flips a single bit of `rawCrossField(0,0)` through
  `bit_cast` and requires `independent_negative_index_oracle(mutated)` to yield nothing. A one-bit change
  breaking the oracle is direct proof that it reads the raw bytes, which is exactly what the previous version
  could not demonstrate;
- the conditioner is then run under `production_identity()` and its preserved output compared (`:499-502`).

### V2 — OBS-01 verified, and it is the third instance of one class

The cited digest is correct: `e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855` is the SHA-256
of empty input, recomputed here. So `EVIDENCE_SHA256SUMS` carries a self-entry hashing the file as it stood
before it had content, and a manifest that lists itself verifies vacuously no matter what it contains. The
classification — orchestration, non-blocking, owner TB4 — is right.

Worth recording because it has now recurred: this is the same defect class as the review-closeout row that asked
for the commit hash of the commit containing it, corrected in `REVIEW_TURN_POLICY.md` §4/§5. **A record cannot
attest to its own bytes.** TB4's evidence harness should exclude the checksum output from its own manifest, and
the same question is worth asking of any other self-describing artifact the harness emits.

### V3 — REQUIRED before closure: conjunct 4 does not admit "reachability not proved"

§4 lists the boundary-truncated separatrix as *"the explicitly permitted blocked / report-only / non-selector
item because independent A2a reachability is not proved."* That reads the escape hatch wider than it is.

Frozen `Architecture_M4_CP_COND_Frozen_Definitions.md` §12 conjunct 4 requires *"independently proved
high-valence, negative-index, and boundary-truncated witness preconditions, **with any genuinely unreachable
item left as an explicit blocker rather than fabricated**."* The hatch is for an item **proved** genuinely
unreachable, and the thing it guards against is fabricating a witness that is not real. It does not cover an
item whose reachability is simply an open question.

"Not proved reachable" is neither of the two states the conjunct admits. Treating it as the permitted blocker
converts an unresolved question into a satisfied conjunct, which is the same substitution this project
corrected at `Architecture_M4_DEFN_Frozen_Definitions.md:508` — an assertion standing in for evidence inside a
normative claim.

This does not affect TB3's adjudication, since CP-COND is open on the selector gap regardless. It is a
constraint on **closure**: before CP-COND may close, the boundary-truncated item must resolve into one of the
two evidenced states — a produced witness, or an independent proof from A2a authority that the precondition is
genuinely unreachable. If neither is obtainable, conjunct 4 is unsatisfied and closure must say so explicitly
rather than cite the hatch.

### V4 — successor and obligations confirmed

Selector422 is the right target: `408 + 14`, with CB4 required to prove the first 408 rows hash exactly to
`c689c0cd…484`, which preserves the accepted prefix byte-for-byte as conjunct 8 demands. All carried items keep
named owners — `TB2-REV-CAND-01` closed runtime-proved, the new `TB3-REV-CAND-01` and `OBS-01` with owners,
`M4-CP3-TB1-R1-REV-OBS-01` and `CB4-REV-OBS-02` carried, the TB3 provenance warning retained as a
historical-claim bound, and both `G4-B002` and `G4-B003` debts held at their gating milestones.
