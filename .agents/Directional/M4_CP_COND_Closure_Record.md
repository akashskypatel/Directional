# M4-CP-COND Closure Record

**Status:** **CLOSED / ACCEPTED**
**Closure turn:** `M4-CP-COND-TB5-REV`
**Date:** 2026-09-14 UTC

## 1. Accepted authority

CP-COND closes on reviewed immutable CB5/TB5 authority:

- semantic source `07984711db59eaa228820e7d44e5552a652edadf`;
- package artifact `10331193451`, SHA-256
  `3f23572a4869e469a6f3ba1082af8a7836c29d9566d143e1a395950d8a94230b`;
- selector423 **423 identities**, SHA-256
  `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- accepted predecessor selector422 SHA-256
  `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- TB5 run/job `34805164109 / 103855521990`;
- result/log artifacts `10333057375 / 10332819388`, SHA-256
  `240d22578a48570b8ecab26c158d24ccc70f4e5a5c79a53d4bdd9359e1c78bb3 /
  e2b3262b5188149a8bfe3664e7473c44feeb73ad119216081d1d0889c9d66499`.

Package `10327643907` / selector422 remains the accepted predecessor and historical baseline.

## 2. Closure proof

TB5 executes selector423 **423/423 PASS** in fresh exact-filter processes: inherited selector422 **422/422** and
row423 **1/1**, zero RED/SKIP/timeout/selection mismatch. Review independently re-derived the row-for-row ledger,
owner census **30/277/75/41**, one-identity raw logs, package/source/execution immutability, 27/27 package manifest,
440-entry evidence manifest, and exact selector prefix.

The final missing frozen exit conjunct is independently proved rather than inferred from production. Row423's test-local
exact-rational oracle derives a `-1` singularity and a ray that terminates in the strict interior of genuine
source-boundary edge `{1,2}` before conditioner execution. An independent Review derivation reproduces that result. A
raw-field mutation preserves the structural carrier but changes the exact boundary parameter, proving the field is
load-bearing. The frozen production-identity conditioner returns `Produced`; its certificate reconstructs the same raw
authority and the same oracle exactly.

History comparison shows no production (`src/`/`include/`) or fixture semantic change from accepted selector422 source
to the candidate. Selector423 preserves selector408 and selector422 byte-for-byte as prefixes. Thus all eight frozen
`Architecture_M4_CP_COND_Frozen_Definitions.md` §12 exit conjuncts are satisfied in one immutable cumulative package.

## 3. Candidate and accounting disposition

`M4-CP-COND-TB4-REV-CAND-01` closes **RECOVERY/TEST-AUTHORITY PROVED / NON-STABLE**. No accepted PASS->RED transition
occurred. Stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains
**5**.

## 4. Carried obligations

- `M4-CP3-TB1-R1-REV-OBS-01` — same-region multiplicity-2 end-to-end independent oracle before M4-CP4.
- `M4-CP3-CB4-REV-OBS-02` — row399 path/`sourceFaces` divergence tamper on the next legitimate row399 touch.
- TB3 row408 provenance — retain the historical-claim bound.
- `G4-B002` — three produced-witness debts remain M4-CP4 gates.
- `G4-B003` — two debts remain M5 gates.

None is part of the CP-COND frozen exit and none is discharged by this closure.

## 5. Retained and folded authority

Retain:

- `Architecture_M4_CP_COND_Frozen_Definitions.md`;
- selector422 and selector423 files;
- `Architecture_M4_CP_COND_TB5_Review_Record.md`;
- this closure record;
- M4 consolidated record, selector manifest, tracker and changelog.

Earlier CP-COND per-turn plans/reports are folded only after their durable facts and exact line counts are indexed in
`M4_Consolidated_Record.md`. Git history remains the full-text archive.

## 6. Scope not closed here

This closes **CP-COND only**, not M4. CP-SCALE and CP4 remain open. CP-SCALE owns S1-S5 scale/boundedness evidence;
CP4 remains the cumulative M4 exit and still owns the three `G4-B002` produced-witness re-proofs.

## 7. Exact successor

**`M4-CP-SCALE-DEFN`**, planning/runtime-free under `Architecture_M4_CP_SCALE_DEFN_Plan.md`. It must freeze the
detailed S1-S5 evidence/gate contract and witness reachability before any CP-SCALE Code + Build turn.
