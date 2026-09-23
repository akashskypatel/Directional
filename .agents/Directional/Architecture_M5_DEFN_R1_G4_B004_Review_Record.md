# M5-DEFN-R1-REV — `G4-B004` M5-Half Independent Review Record

**Turn:** `M5-DEFN-R1-REV`
**Date:** 2026-09-23 UTC
**Reviewer:** reviewing agent. It performed the independent Review named by `M5-DEFN-R1` under `Architecture_M5_DEFN_R1_G4_B004_Review_Plan.md`.
**Boundary:** runtime-free. No product/test/fixture/selector/CMake/benchmark mutation, compile or Directional runtime.
**Verdict:** **DISPOSITION A NOT ACCEPTED. §13.1 conjunct 8 as worded by DEFN-R1 is NOT accepted. M5 CLOSURE REMAINS HELD.** Exact successor: runtime-free **`M5-DEFN-R2`**.

## 1. What DEFN-R1 got right (independently re-verified)

DEFN-R1's **evidence** claims all hold. The rejection below concerns the **reading** alone.

- Ordinals 183-188, 237, 239, 240, 242, 253 and 254 are all `exit0 / selected1 / skipped0 / PASS` in the authoritative TB2 selector ledger (`91c861fc...00c3`, re-read from the downloaded result artifact `10775185139`).
- `split_isolation_fixture()` is `make_square_fixture(true, false)`: `build_surface_cell_network(...)` with test-supplied `sourceFaceSheets {0,1}`, guarded by `require_produced(...)`. It is producer output, not a direct/helper product.
- Row 239 (`tests/SurfaceCellsPhase10Tests.cpp:3014-3080`, byte-identical to `a8b33cb7`) asserts the following:
  - `Produced` disposition;
  - one region with a non-empty internal isolation seam;
  - exactly one certificate, whose `region()` and `seam()` equal the region's, with a bounded `transition()`, `firstSheet != secondSheet` and `forward().inverse() == reverse()`;
  - a cross-sheet cell scope;
  - materialization success with `consumedInternalIsolationSeams == certificates.size()`.
- Row 186 independently asserts the reciprocal certificate across distinct sheets, materialization success and consumption of exactly one seam.
- Rows 183-185 and 187-188 are the typed duplicate/missing/nonreciprocal/wrong-owner/wrong-sheet tamper family on the same fixture.
- The selector448/430 hashes, accounting 51/14/37 and debt 1 are unchanged. DEFN-R1 mutated no product/test/fixture/selector/CMake/benchmark bytes, and the code surfaces are identical to `a8b33cb7`.

## 2. Why disposition A fails

### 2.1 Chronology: A says the obligation was met before it was assigned (decisive)

Rows **186 and 239 are in `M1_Full_Required_Green_Selector.txt`** (lines 116 and 169), and row 188 is too. They were accepted green at **M1 closure**. Yet after M1:

- the persistent-blocker table (restored tracker, maintained through `M4-CP3-TB8-REV`) kept `G4-B004` open as "Positive multi-isolation quotient witness", owned by M5/M6;
- `Architecture_M4_DEFN_Frozen_Definitions.md` §11.2 then **assigned** the M5 half as future work: "It must prove the relation producer emits positive multi-isolation authority with explicit owners/certificate";
- `REORIENTATION_PLAN.md` §9 was amended to the same effect.

Under reading A, every one of those records assigned or kept open an obligation that accepted M1 evidence already satisfied. A frozen assignment of future work that was already met when it was issued is vacuous. The more economical reading is that the authors meant something M1's rows do not provide. DEFN-R1 never checked when its evidence was first accepted. The Review plan DEFN-R1 wrote for its own reviewer omitted exactly this falsifier.

A could survive only with a primary record explaining why `G4-B004` stayed a blocker, and was assigned to M5, after 186/239 were accepted. I searched the durable set, both restored ledgers, the M1 closure record, `PR_8_Regression_Audit_Inventory.md`, the design/audit reports, git history back to the root squash (`79af4296`) and the PR #8 body and comments. There is no such record.

### 2.2 The "multi-" becomes redundant under A

DEFN-R1's own argument (§2.2) is that `SurfaceIsolationSeamTransportCertificate` rejects `SameSheet`, so "one valid positive certificate therefore already certifies a relation between two different isolation authorities". Taken at face value, **every** positive isolation-seam certificate is "multi-isolation" by construction. The qualifier would then add nothing to "positive isolation-seam certificate witness", which M1 already required and accepted. A reading that makes a deliberate qualifier redundant is disfavoured unless the source says it is redundant, and no source does.

### 2.3 A plausible reading consistent with chronology and context was never considered

All four `G4-B` persistent blockers come from the same **torus production** campaign:
- `G4-B001` is the direct torus `LocalSheetMismatch`, a *sheet* authority failure;
- `G4-B002` is the exact torus `InvalidHardRailPairing`;
- `G4-B003` is nonzero periodic Z4 production on the torus.

In that family, "positive multi-isolation **quotient** witness" reads naturally as a produced witness in which **quotient (periodic) relations operate inside a region spanning multiple isolation sheets**. That means M5's relation/certificate machinery succeeding where isolation seams and periodic quotient relations coexist. The repository contains a never-gated candidate that asserts exactly that shape: `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` (`tests/SurfaceCellsPhase10Tests.cpp:4436`). It is a pipeline-produced committed torus with internal isolation seams, a multi-sheet region with an internal seam, non-empty periodic holonomies, every certificate and periodic relation consumed, and isolation-sheet lineage on every output vertex. It has existed since the root squash, and it has never been executed in any recorded gate.

I do **not** freeze this reading. That is definition authority, and other readings remain possible, such as pipeline-derived rather than test-supplied sheets, or ≥2 seams. The point is narrower. DEFN-R1 adopted the one reading that makes the assignment vacuous, while a non-vacuous reading that fits the blocker family was available and unexamined. The plan's falsifier "primary authority actually requires … rather than multiple sheet authorities" is therefore not refuted. The burden sat with the DEFN, and it was not met.

### 2.4 Consequences

- §13.1 conjunct 8 **as worded** (multi-isolation-*sheet* certificate witness) is **not accepted**. The underlying M4-DEFN §11.2 obligation stands unchanged.
- `M5-CP3-TB2-REV-OBS-01` stays **OPEN** and moves to `M5-DEFN-R2`. The merged remainder of `M5-DEFN-REV-OBS-01` stays open with it.
- The M6-DEFN plan's item 7, which DEFN-R1 rewrote to assume A, is reverted to a neutral form.
- None of this affects selector448 acceptance, the CB20 package promotion, §13.1 conjuncts 1-7, accounting 51/14/37 or debt 1.

## 3. Process defects in `M5-DEFN-R1`

1. **COMPLETE was published before the work existed on the branch** (`M5-DEFN-R1-REV-OBS-01`). The first `COMPLETE → M5-DEFN-R1-REV` beacon was written at 22:11:35Z. The only copy of the definition work was then a Drive file named `Directional__M5-DEFN-R1__base-56a6e667c731__work-preservation.patch` with `state=prepared-unapplied`, created at 22:13:16Z. The monitor handed the turn to Review at 22:15:11Z, when the branch still contained only STATUS beacons. The docs landed at 22:16:25Z (`d17aada2`), the caller and trigger were retired at 22:17:20 and 22:17:47, and STATUS was rewritten again at 22:18:53 (`Ended at` 22:18:51Z).
   - This breaks `Mandatory_End_Checklist.md` items 11-12 and `Durable_Handoff_Policy.md` item 15: the COMPLETE beacon must be the **final** repository write.
   - The record's own closeout row stated that rule while the turn violated it.
   - A reviewer that fetched at 22:15 would have reviewed an empty turn.
2. **Tracker entry rewritten with facts dropped.** DEFN-R1 replaced the `M5-CP3-TB2-REV-OBS-01` entry in place and dropped its *root cause*, *falsifier* and *prohibited* bullets. `REVIEW_TURN_POLICY.md` §3.2 requires all three. I restored them, marked as restored.
3. **Unverifiable `ledgers` baseline.** The closeout reports `ledgers` PASS against "local baseline `5337217f...`", which is not a commit on the branch. My own run, `ledgers --base f0c7a60b` (the last pre-DEFN commit), PASSes. The recorded claim is still unverifiable as written.

## 4. Successor

Exactly one successor: runtime-free **`M5-DEFN-R2`** under `Architecture_M5_DEFN_R2_G4_B004_Reading_Plan.md`. It must fix the meaning of the `G4-B004` M5 half with a reading that survives the chronology and non-redundancy falsifiers, or stop **BLOCKED** with a precise question for the user. The falsifiers are stated there, before the turn.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector448 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789` and selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, via `boundary --expect-selector` |
| Decisive claims independently re-derived | TB2 ledger status of 183-188/237/239/240/242/253/254 from the downloaded artifact; split fixture construction; row 239 and 186 assertions; **first-acceptance chronology** (M1 selector membership of 186/188/239 against the blocker table and the M4-DEFN §11.2 assignment); a search for any rationale record (durable set, restored ledgers, root squash, PR #8); `G4-B` family context |
| Non-vacuity checked | Evidence is non-vacuous as DEFN-R1 claims. The **reading** is vacuous: it discharges an obligation already met when it was issued, and it makes the "multi-" qualifier redundant. |
| Prior obligations discharged/carried | `M5-CP3-TB2-REV-OBS-01` and the merged `M5-DEFN-REV-OBS-01` remainder are **carried** to `M5-DEFN-R2`. R16 OBS-01/02 are unchanged. |
| Stable accounting | 51 / 14 / 37; debt 1 (M6); package `10771899191 / cef1c6ee…` under selector448 448/448 |
| New candidates/obligations recorded | `M5-DEFN-R1-REV-OBS-01` (premature COMPLETE), in the tracker; the OBS-01 dropped bullets are restored |
| ORIENTATION currency line | `M5-DEFN-R1-REV`, 2026-09-23 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3 banner and M5 paragraph updated. §4 unchanged. §7 item 1 is now `M5-DEFN-R2` and item 9 is updated. §8 gains the vacuity-by-chronology instance (`LESSONS.md` 177). |
| CHANGELOG | Agent and root entries added by edit (append-only) |
| ROADMAP | M5 row, section and `G4-B004` row updated |
| Selector manifest | n/a — no selector change |
| LESSONS | **New 177**: check when a candidate's evidence was first accepted against when the obligation was issued. Cited: 168, 176. |
| Consolidation under CLEAN_UP_POLICY | Folded the DEFN-R1 record (verdict: disposition A not accepted) and the consumed Review plan into the consolidated index. DEFN-R1's arguments are summarized in §§1-2 above. |
| Successor frozen | Exactly `M5-DEFN-R2`, with falsifiers in `Architecture_M5_DEFN_R2_G4_B004_Reading_Plan.md` |
| Turn boundary held | Runtime-free. No product/test/fixture/CMake/benchmark/selector change. |
| review_check.py boundary / ledgers | `boundary --expect-selector 448=70ff0860… 430=1c412850…`: **ALL CHECKS PASSED**. No product/test/fixture/build or selector mutation, and durable markers are preserved (handoff 1→1, ORIENTATION 3→3, tracker 13→13). `ledgers --base f0c7a60b` (the last commit before DEFN-R1): **ALL CHECKS PASSED**, with no >10% shrink of any append-only ledger. |
| `STATUS` lifecycle maintained | Entry `M5-DEFN-R1-REV / IN_PROGRESS` at `2026-09-23T22:21:35Z`, before any other write. The final `COMPLETE → M5-DEFN-R2` is the last write. |
| Pushed to origin, branch in sync | Confirmed by `git status -sb` after the final push |
