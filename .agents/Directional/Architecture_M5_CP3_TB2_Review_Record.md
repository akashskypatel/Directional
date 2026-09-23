# M5-CP3-TB2 Final Review Record

**Turn:** `M5-CP3-TB2-REV`
**Boundary:** independent, runtime-free Review of the published selector448 TB2 evidence
**Verdict:** **APPROVED / SELECTOR448 ACCEPTED** — ~~M5 CLOSED~~ → **M5 CLOSURE HELD** (reviewing-agent addendum, below)
**Exact successor:** ~~`M6-DEFN`~~ → **`M5-DEFN-R1`**; `M6-DEFN` deferred

## 1. Authority independently reopened

Review re-opened the immutable TB2 result/log artifacts rather than relying on the EXEC report. Authoritative run/job is `35913334490 / 107358491487`; result/log artifacts are `10775185139 / 10774217117` with provider ZIP SHA-256 `01142fbc1f4cf0a4fb695cda1ed973d39b3b51e5dc11e05ff34336b84875261b / b58678cbf37d9c7757e8a36e8b590381919f5d1413a6ac02d11038e12e040fc6`.

The result artifact contains exactly **917 non-manifest files** and **917 `SHA256SUMS` rows**; every row independently verifies. The manifest file hashes to `9681fda2357103470162e7cd1362713df07078732dc2a1e8a4fff17b75a843c1`. The boundary records runtime started/completed, preflight complete, no orchestration failure, exact selection integrity, 448 executed identities, benchmark 0, and no configure/compile/relink/discovery/repair/mutation/retry activity. Package, packaged source, and execution-view byte+mode censuses are identical before/after runtime, and the CB20 package root manifest remains 28/28.

## 2. Selector and routing authority

Published selector448 independently hashes to `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`: **448 rows / 448 unique / terminal LF / no CRLF**. Accepted selector430 independently hashes to `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, and the first 430 selector448 rows are byte-identical to it.

The 448-row static routing receipt hashes to `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`; ordinal and identity sequences exactly equal selector448 and owner census is **32 authority-kernel / 300 producer / 75 completion / 41 validation**. Runtime ledger routing agrees row-for-row with the static receipt.

All 448 ledger rows were independently parsed: ordinals are exactly 1..448, identities exactly equal selector order, routed binary exactly equals the static receipt, and every process records exit0, selected=1, skipped=0, passed=1 and `PASS`. Every raw-log hash matches the ledger, and every raw log contains exactly one matching `[ RUN ]`, one matching `[ OK ]`, and no skip. Selector-ledger SHA-256 is `91c861fca2a7627b256ae6f7cb3241c5992689056da57d1622a135519bd600c3`. Protected ordinals 191/192/247/408 and all newly published rows431-448 are fresh-green.

## 3. Frozen M5 exit theorem (§13.1)

Final closure is accepted only because all seven frozen conjuncts hold on one reviewed authority chain:

1. **Selected relation paths retained and independently verified.** CP1 closure remains accepted; fresh selector rows435/436 preserve canonical relation ID/path certificate authority through permutation, while produced rows443/446 consume direct produced relation authority rather than a reconstructed proxy.
2. **Unused independently valid relations are decision-neutral.** Row437 remains required-green and produced row448 freshly proves that adding an unused valid produced relation does not alter the selected certificate.
3. **Typed checked failures remain required-green.** Missing owner is covered by accepted row220 and direct-produced row445; duplicate identity by row296; conflicting relation by row439; nonreciprocal relation by row440; representation-renumbered relation by row441. All are fresh-green under selector448.
4. **Torus lineage and quotient acceptance are direct production.** Accepted row408 remains green, and rows443/446 reach direct produced relation publication/materialization/certificate consumption. No helper-only identity is substituted for produced credit.
5. **All four M5 produced debts are discharged on produced authority.** R7 discharged relation/container-order ownership and missing-owner typing. R16 established the remaining two nonzero-Z4 debts, and TB2 freshly re-proves rows446/447: genuine semantic `Q=3` with nonzero translation reaches materialization/certificate/positive consumption, while one-transform tamper rejects typed.
6. **CP1/CP2 mechanism evidence remains required-green without production credit.** Appended mechanism rows433-441 remain in selector448 and pass freshly; their role stays mechanism/falsifier evidence only.
7. **Publication discipline is complete.** R16 Review precommitted exact selector448; CB20 published those exact bytes and compiled/package-green without runtime; TB2 executed the published selector freshly and immutably; this independent Review re-derived the evidence and accepts it.

`M5-DEFN-REV-OBS-01` is therefore **DISCHARGED**: the final M5 exit is stated once here and reconciles `DESIGN.md` §14 M5 with frozen §§8-9/13 without crediting mechanism-only rows as produced evidence.

## 4. R16 closure observations

### `M5-CP3-TB1-R16-REV-OBS-01` — DISPOSED / NO M5 CREDIT

A source census contains exactly ten `TEST(M5CP3, ...)` identities. Eight are selector448 identities; the only two excluded identities are `M5CP3.PeriodicRelationEndpointGaugeIsIndependentAndExact` and `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`. They were compiled at CB14 but **never executed in an accepted gate**, are intentionally absent from selector448, and receive **no credit toward any M5 exit conjunct**. No report-only execution is stitched into M5.

Immediate successor `M6-DEFN` owns a bounded hygiene decision: it must freeze whether each dormant identity is deleted or assigned to the first appropriate M6 Code + Build gate, and name that exact implementation owner before M6 product work uses either. Until then both remain dormant/no-credit.

### `M5-CP3-TB1-R16-REV-OBS-02` — RECORDED / NOT FIRING

Rows446/447 fresh-pass while deliberately pinning inverse canonical storage, so the representation-drift risk has not fired. The observation remains a future classification rule, not an M5 closure debt.

### `M5-CP3-TB1-R16-REV-OBS-03` — DISCHARGED

`M5_Consolidated_Record.md` is repaired to one chronological, unique §4.1-§4.31 sequence. The formerly late CB17/R15/CB18/R15-R1 sections are moved before R15-R1 Review, all subsequent sections are renumbered, and live section citations are repaired.

## 5. Selector/package promotion and accounting

Selector448 becomes **ACCEPTED CURRENT AUTHORITY**. CB20 package/source `10771899191 / cef1c6ee26ca6fb6791f0e80a66f9b0dc441e0f1` is promoted as final accepted M5 runtime package/source under selector448 **448/448**. Selector430 remains the exact accepted historical prefix.

TB2 observed no regression and Review finds no new candidate. Stable accounting remains **51 events / 14 categories / 37 recurrences**. All four M5 produced debts are discharged. Project debt remains **1**, the separate M6-owned closed-complex `G4-B002` subject.

**M5 is CLOSED / ACCEPTED.**

## 6. Consolidation and successor

This Review folds the superseded R16 Review into `M5_Consolidated_Record.md`; already-retired R16 runtime and CB20 plan/report are explicitly indexed there. The retained M5 family surface is the current TB2 runtime report, this final Review record, consolidated history, frozen definitions, byte-frozen selector/routing evidence, closure record, and exactly one successor plan.

Exact successor is runtime-free `M6-DEFN`. Its plan freezes the four M6 stage products and verifier recompute boundary, adjudicates the M6-owned closed-complex debt and `G4-B001` ownership before implementation, and resolves the two dormant CB14 identities without granting retroactive M5 credit. Any unresolved product-schema ambiguity, verifier-repair allowance, or inability to name the later cleanup/gating owner stops M6 implementation.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; selector448 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`; first430 byte-identical |
| Decisive claims independently re-derived | 917/917 result manifest; all 448 ledger rows/raw hashes/protocol counts; selector/prefix/routing hashes; owner census; §13.1 seven-conjunct exit; ten-identity M5CP3 source census |
| Non-vacuity checked | protected 191/192/247/408 and rows431-448 fresh PASS; rows446/447 retain inverse-storage, nonzero-Z4, materialization/consumption and one-transform tamper discriminators |
| Prior obligations discharged/carried | `M5-DEFN-REV-OBS-01` discharged; R16 `-OBS-01` no-credit disposed with M6-DEFN hygiene owner; `-OBS-02` recorded/not firing; `-OBS-03` discharged |
| Stable accounting | 51 events / 14 categories / 37 recurrences; project debt 1 M6-owned; accepted package/source `10771899191 / cef1c6ee...`; selector448 448/448 |
| New candidates/obligations recorded | none; tracker updated with final no-regression/closure disposition |
| ORIENTATION currency line | `M5-CP3-TB2-REV`, 2026-09-23 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and torus §4 updated to M5 closure; §7 reprioritized to M6; §8 n/a — no new defect pattern |
| CHANGELOG | final TB2 Review/M5 closure entry added |
| ROADMAP | M5 marked CLOSED / ACCEPTED; M6-DEFN next |
| Selector manifest | selector448 promoted to ACCEPTED CURRENT AUTHORITY; selector430 historical prefix |
| LESSONS | n/a — no genuinely new recurring pattern; existing exact-authority/immutable-evidence lessons apply |
| Consolidation under CLEAN_UP_POLICY | R16 Review folded; retired R16 runtime + CB20 plan/report indexed; consolidated numbering/citations repaired; one M6-DEFN plan retained |
| Successor frozen | exactly `M6-DEFN`; falsifiers/stop rules in `Architecture_M6_DEFN_Occurrence_Embedding_Verifier_Plan.md` |
| Turn boundary held | runtime-free Review; no product/test/fixture/selector/benchmark/build source mutation |
| review_check.py boundary | PASS — all checks passed, including no product/test/fixture/build mutation, no selector mutation, and selector448 declared hash |
| `STATUS` lifecycle maintained | entry/resume beacon maintained for `M5-CP3-TB2-REV`; final COMPLETE beacon will name `M6-DEFN` and preserve `Started at` / `Resumed at` |
| Pushed to origin, branch in sync | CONFIRMED — closure patch push `d15c7278d690aa5ad62c3d47767ed5c6ff1ebef0` succeeded; temporary state cleanup succeeded at `65be47ef694ed39e7e6a51823a5dbd25071da175`; this final documentation update is a direct remote write with no unpublished local state |


---

## Independent verification addendum (reviewing agent)

Runtime-free. **Runtime and package evidence UPHELD. Selector448 acceptance and the CB20 package promotion STAND. The M5 closure verdict is WITHDRAWN and closure is HELD.** Successor changes from `M6-DEFN` to runtime-free **`M5-DEFN-R1`**. Accounting is unchanged at **51 / 14 / 37**, debt **1**.

### V1 — primary evidence re-derived from fresh downloads

- **TB2 result/log** `10775185139 / 10774217117`: ZIP SHA-256 `01142fbc...261b / b58678cb...0fc6` match. `SHA256SUMS` hashes to `9681fda2...43c1`, and 917 rows cover 917 files with 0 failures. The selector ledger hashes to `91c861fc...00c3`. All **448** rows are `exit0 / selected1 / skipped0 / passed1 / PASS`. Every raw-log hash matches its row. Every raw log has exactly one `[ RUN ]` and one `[ OK ]` naming its identity, one test run and no `SKIPPED`. The ledger identity column equals selector448 bytes. `ordinal / identity / binary` equals the routing receipt row for row. Package, source and execution-view censuses are identical before and after. Protected ordinals 191/192/247/408 and 446-448 PASS.
- **CB20 package** `10771899191`: ZIP `d0f26b16...2cbe`, 28/28 at `b3afa490...c3f3`, and source archive `dabed7ea...80b7`, all re-hashed. `source-commit.txt` is `cef1c6ee`. The packaged `src/tests/include/cmake` trees are identical to the branch, with zero diff against `a8b33cb7`. The packaged selector448 and routing receipt are byte-identical to the repository copies. `DIRECTIONAL_ENABLE_GMP=ON`, the link lines carry `libgmpxx`/`libgmp`, all eight targets are linked and the build exits 0.
- **Harness.** The staged TB2 harness (`e3d3f2fe`) hashes to `78d4549b...4f25` as reported. It reads selector448 and the receipt from the **packaged** source, not the live branch.
- **Independent corroboration.** Published selector448 is byte-identical to the precommit I rebuilt at R16. The CB20 routing receipt `c91a5e2f...1dd7c` is byte-identical to the static owner map I derived independently from CMake target membership at R16.
- **§13.1 row citations** resolve correctly: 220 and 445 missing-owner, **296** `DuplicatePeriodicRelationIdentityRejectsAtCheckedFactory`, 439/440/441, 435-438, 443-448 and 408. One precision note: conjunct 1's "independently verified" is best evidenced by ordinal **438** (`AlteredSelectedRelationTransformFailsCertificateValidation`, consumer-side certificate rejection), which the conjunct-1 bullet does not cite.

### V2 — BLOCKING: an M5 exit obligation outside §13.1 was never adjudicated

`Architecture_M4_DEFN_Frozen_Definitions.md` §11.2 (frozen, normative) says: "**M5 owns the focused positive multi-isolation quotient relation/certificate witness.** It must prove the relation producer emits positive multi-isolation authority with explicit owners/certificate, matching `REORIENTATION_PLAN.md` §9". M6's half is to prove "the M5-produced authority is materialized/consumed exactly once and independently verified". `REORIENTATION_PLAN.md` §9 (durable) and the `ROADMAP.md` `G4-B004` row restate the M5 ownership.

- **No M5 record ever took it on.** `git log --all -S"G4-B004"` over every M5 definition, consolidated, closure and review file returns nothing, and the M5 frozen record never mentions multi-isolation. This Review's seven-conjunct exit and `M5_Closure_Record.md` omit it. The `M6-DEFN` plan omitted the M6 half too.
- **The state documents contradicted the verdict.** Even after this Review, ORIENTATION §7 item 9 read "`G4-B004` … ADJUDICATED. M5 owns focused positive relation/certificate production", and TODO still listed "`G4-B004` … M5/M6" as open.
- **No accepted row satisfies it.** Selector448's only positive isolation-seam materialization row is ordinal 186, `ReciprocalIsolationSeamCertificateMaterializes` (`tests/SurfaceCellTransitionQuotientTests.cpp:2288`). It asserts **exactly one** isolation certificate and `consumedInternalIsolationSeams == 1`, so it is single-isolation. The other isolation rows (183-185, 187-188, 210, 237-254) are typed-failure or classification rows. The M5 torus is one topology region cut by HardFeature edges, not isolation seams. **[CORRECTED at the second pass, below: ordinal 239 is also positive, and under a ≥2-sheets reading rows 183-188 may satisfy the obligation. This bullet overclaimed.]**
- **Why it was missed.** `G4-B004` was never counted as produced-witness debt, and M4-DEFN had explicitly said it "adds no **M4** gate identity/debt". So it fell outside both the debt ledger and `DESIGN.md` §14 M5's acceptance list, the two sources §13.1 was reconciled against. `M5-DEFN-REV-OBS-01` existed for exactly this risk, M5's exit being "stated in several places and nowhere in full". Its discharge here reconciled only the places already known. This is a direct instance of `LESSONS.md` 168.

**Disposition.**
- I **withdraw** "M5 CLOSED" and hold closure.
- The §13.1 conjuncts 1-7, selector448 acceptance and the package promotion are unaffected.
- `M5-DEFN-REV-OBS-01`'s discharge is withdrawn in part and merged into **`M5-CP3-TB2-REV-OBS-01`**, owned by **`M5-DEFN-R1`**.
- I have not decided the substance, whether the obligation is satisfied, needs `M5-CP4`, or should be re-homed. That is definition authority, and `M5-DEFN-R1` must decide it from primary sources under falsifiers that forbid crediting ordinal 186 and forbid a re-home without a named missing M6 stage authority. **[CORRECTED: the "forbid crediting ordinal 186" falsifier prejudged the reading and was removed from the plan at the second pass.]**
- `M6-DEFN` cannot correctly proceed first, because its `G4-B004` half consumes "the M5-produced authority".

### V3 — the durable tracker had been overwritten, and I restored it

Commit **`ce9bf3cb`** (2026-09-22, "docs: track R11 manifest finalization orchestration defect") recorded one new entry by writing it as the **entire** `Regression_Root_Cause_Tracker.md`: 9,837 lines became 21.
- **What was lost:** every stable-event record before 2026-09-22, and the DURABLE sections *Stable-event criterion* (the rule behind "51 / 14 / 37"), *Closure constraint — CP-COND conjunct 4* and *Closure constraint — CP-SCALE S5*. The criterion existed **nowhere** in the repository until this addendum.
- **Why it matters:** `RETENTION_POLICY.md` lists the tracker as durable project authority requiring user authorization to remove, and none exists.
- **How long it went unnoticed:** about 20 turns, including my own R15-R1 and R16 addenda. That is on me as much as anyone. `review_check.py` guarded only the handoff and ORIENTATION.

**Fix:**
- Appended `ce9bf3cb~1`'s tracker verbatim under a "RESTORED HISTORY" heading, and byte-verified the tail against the source.
- Added the tracker to `review_check.py` `DURABLE_FILES`. The check would have failed at `ce9bf3cb`, where the marker count went 6 → 0. **[CORRECTED: false. `boundary` sees only uncommitted edits, so it could not catch a committed overwrite. See `ledgers` at the second pass.]**
- Recorded `M5-CP3-TB2-REV-OBS-02` (recovered) and `LESSONS.md` 176.

The accounting reconciles: the restored ledger ends at 50/14/36, and the retained R13-REV addendum corrects that to 51/14/37.

### V4 — other closeout gaps fixed

| # | Gap | Fix |
|---|---|---|
| G1 | The frozen M5 header still read `EXACT NEXT = M5-CP3-CB17`, three successors stale. My R16 addendum fixed §11 but missed this header. | Header and §11 now state held closure and name `M5-DEFN-R1`. §13.1 gains an omission note, with conjuncts unweakened. V5's discharge is marked withdrawn in part. |
| G2 | The ROADMAP milestone table still read "CP3 R16 REVIEW ACCEPTED / SELECTOR448 PRECOMMITTED / **CB20 NEXT**", unchanged through CB20, TB2-EXEC and this Review. | Row updated. The `G4-B004` row is annotated. |
| G3 | TB2-REV removed the M5 checklist from TODO, and with it the only open item for the **M6 closed-complex debt**. | Open item restored. |
| G4 | The folded-index entries for the three files TB2-EXEC retired said "(retired before TB2-REV)" instead of recovering line counts from git, as `CLEAN_UP_POLICY.md` procedure item 3 requires. | Recovered 106 / 487 / 68 lines. |
| G5 | The M6-DEFN plan said `review_check.py boundary` "is not required for a definition turn", contradicting `REVIEW_TURN_POLICY.md`, which governs DEFN turns. It also omitted the `G4-B004` M6 half. | Corrected. Added item 7 and a falsifier. Marked DEFERRED. |
| G6 | `M5_Closure_Record.md` named the package without its compile run, ZIP, manifest or source-archive hashes. | Added and re-verified. |
| G7 | No root `CHANGELOG.md` entry for this turn. | Added. |

The two plan files are a deliberate, temporary exception to "exactly one next-turn plan". `M5-DEFN-R1` is the one live plan, and the M6-DEFN plan is retained but marked **DEFERRED**, because deleting a reviewed plan that remains the intended M6 entry would destroy work rather than consolidate it.

## Review closeout — reviewing-agent addendum

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector448 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789` (448 / 36,382 B), first430 = selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; packaged copy byte-identical |
| Decisive claims independently re-derived | Fresh download and re-hash of TB2 result/log and CB20 package; 917/917 and 28/28; all 448 rows, raw hashes and GTest protocol; routing equals receipt; harness SHA and packaged-source reads; code equal to `a8b33cb7`; GMP; §13.1 row resolution; `G4-B004` census from frozen records and git history; tracker line counts across `ce9bf3cb` |
| Non-vacuity checked | Protocol shows exactly one matching RUN/OK per row, so no vacuous PASS. **[CORRECTED at the second pass: the following single-isolation conclusion prejudged the reading.]** Ordinal 186 is shown single-isolation (`ASSERT_EQ(1U, …)`, `consumedInternalIsolationSeams == 1`), so it cannot carry a multi-isolation claim. |
| Prior obligations discharged/carried | R16 `-OBS-01` no-credit disposition upheld, with M6-DEFN still owning its hygiene decision. `-OBS-02` still recorded. `-OBS-03` discharge upheld: numbering is unique and ordered, and the §4.11, §4.12, §4.25 and §4.31 citations resolve. **`M5-DEFN-REV-OBS-01` discharge withdrawn in part, merged into `M5-CP3-TB2-REV-OBS-01` → `M5-DEFN-R1`.** |
| Stable accounting | 51 / 14 / 37; debt 1 (M6), which may become 2 under `M5-DEFN-R1` disposition C. Package `10771899191 / cef1c6ee...` under selector448 448/448. |
| New candidates/obligations recorded | `M5-CP3-TB2-REV-OBS-01` (open, closure-blocking) and `-OBS-02` (recovered), both in the tracker. |
| ORIENTATION currency line | `M5-CP3-TB2-REV` (incl. reviewing-agent addendum), 2026-09-23 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3 banner and M5 paragraph updated to held closure. §4 unchanged, since torus witness state is correct. §7 reprioritized: item 1 is `M5-DEFN-R1`, 1a is `M6-DEFN` deferred, and the stale "ADJUDICATED" in item 9 is edited in place. §8 gains two instances, closure-census miss (`LESSONS.md` 168) and ledger overwrite (176). |
| CHANGELOG | Agent entry amended; root entry added |
| ROADMAP | Status line, stale M5 milestone row, M5 section and `G4-B004` row updated |
| Selector manifest | n/a. The existing 448 ACCEPTED row is correct and makes no closure claim. |
| LESSONS | New 176 (append-only ledger overwrite). Cited 168. |
| Consolidation under CLEAN_UP_POLICY | Line counts recovered for the three TB2-EXEC-retired files. Addendum paragraph added to the consolidated record. Nothing further to fold. |
| Successor frozen | Exactly `M5-DEFN-R1`. Falsifiers and stop rules are in `Architecture_M5_DEFN_R1_G4_B004_Exit_Reconciliation_Plan.md` §§3-4. |
| Turn boundary held | Runtime-free. No product/test/fixture/CMake/benchmark/selector change. One review-tool guard added (`tools/review_check.py` `DURABLE_FILES`), outside the code surfaces. |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** with `--expect-selector 448=70ff0860… 430=1c412850…` over the 15-document addendum diff. No product/test/fixture/build or selector mutation. Durable markers: handoff 1→1, ORIENTATION 2→4, tracker **0→11** (restoration; newly guarded). |
| `STATUS` lifecycle maintained | Resume beacon `IN_PROGRESS` (Resumed at = handoff `2026-09-23T21:16:54Z`) published first. Final `COMPLETE → M5-DEFN-R1` is the last write. |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the final push |

---

## Second reviewing-agent pass (re-handoff at 14:37:23)

Runtime-free. Origin had **no new commits** since the first addendum. The only intervening writes were the concurrent implementation session's two STATUS commits (`a051b203`, `cca8de6a`), which re-closed this turn as `COMPLETE → M6-DEFN`, and that re-close triggered this handoff. The first addendum's final beacon (`COMPLETE → M5-DEFN-R1`) was already later on origin and remains authoritative. This pass audited the current state and my own first addendum as hostile input (`REVIEW_TURN_POLICY.md` §6.2). **Verdict:** the closure hold is upheld. Two of my own claims were wrong or overstated and are corrected here, and one further durable-data loss is repaired.

### P1 — the central finding survives a broader search

`git log --all -S"G4-B004"` and `-S"multi-isolation"` over **every** M5-named path in history return only my own first-addendum commit. No M5 record ever absorbed the M4-DEFN §11.2 obligation, so closing M5 without adjudicating it remains a `LESSONS.md` 168 failure. The hold and `M5-DEFN-R1` stand.

### P2 — my census overclaimed and prejudged the definition (corrected)

The first addendum called ordinal 186 "the only positive isolation row", "single-isolation" and "cannot be credited", and wrote that into `M5-DEFN-R1`'s falsifiers. On re-examination:
- Ordinal **239** (`ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam`) is a second positive, producer-built, materialized isolation row. It also asserts one certificate across two sheets.
- `split_isolation_fixture()` is **producer-built** (`build_surface_cell_network` + `require_produced`) from test-supplied sheet labels `{0,1}`. So 186 and the tamper family 183-185/187-188 are producer output, not direct/helper rows.
- The repository's own ungated test `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` uses **"multi-isolation" to mean ≥2 isolation sheets** on that same single-seam fixture. `tests/TESTING_STRATEGY.md` §8.4 lists "multi-isolation relation graphs" under occurrence quotient, which is M6.
- A second ungated produced witness exists: `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`, a pipeline torus with internal isolation seams, a multi-sheet region and every certificate and periodic relation consumed. Neither ungated test has ever been executed in any gate, and neither is mentioned in any record.
- More broadly, **360 of 808** identities compiled into the four gate binaries are in no selector. That is a known design property, historical rows are not gated, but it means census claims must be made from source, not from the selector alone.

So whether accepted evidence already satisfies the obligation **depends on the reading**, which is `M5-DEFN-R1`'s decision. Disposition A (rows 183-188 under a ≥2-sheets reading) is a live, possibly likely, outcome. I corrected the census and falsifiers in the plan, the frozen §13.1 note, ORIENTATION, TODO, the handoff, ROADMAP, the consolidated record, the M6-DEFN plan and tracker OBS-01. The replacement falsifier forbids crediting anything under a reading the DEFN has not frozen with cited authority, in either direction.

### P3 — the guard I added was inert against the real failure path (corrected)

I claimed the new `DURABLE_FILES` entry "would have failed at `ce9bf3cb`". It could not have. `boundary` compares only the reviewer's uncommitted tree with HEAD, and the overwrite was committed by an EXEC turn that never runs the check. I added `review_check.py ledgers --base <rev>`, which scans **committed** history for any >10% shrink of the tracker, agent CHANGELOG, LESSONS and root CHANGELOG. Verified: `--base ce9bf3cb~2` **FAILs** and names `ce9bf3cb 9837→21` and `0043dd4c 13317→14`. `--base d9441606` **PASSes**. `LESSONS.md` 176 now states both corollaries: test a guard against the incident path, and search for sibling instances.

### P4 — a second durable ledger had been overwritten (restored)

Commit **`0043dd4c`** (2026-09-22 12:27, "docs: log R11 orchestration-invalid attempt"), from the same minute and action as `ce9bf3cb`, overwrote the **agent CHANGELOG** from 13,317 lines (466 entries) to 14. It was never restored. My first addendum fixed the tracker and wrote a lesson about the pattern without looking for siblings. I then scanned every durable and agent document since 2026-08-20 for surviving files that shrank by more than 65%:
- `ce9bf3cb` and `0043dd4c` are the only unauthorized losses.
- `a1c8753c` ("noop", emptied the M4 CP-COND TB3 review record) was restored the same day by `ca518917`.
- The remaining hits are named consolidations with DURABLE markers preserved.

The agent CHANGELOG is restored verbatim under "RESTORED HISTORY", with its tail byte-verified. Recorded as `M5-CP3-TB2-REV-OBS-03`.

### P5 — process note: concurrent implementation session

At 14:30:12 the monitor started a new implementation session while the first addendum was in progress. That session read the `IN_PROGRESS` beacon, "resumed" this turn and re-closed it with its own remembered successor, `M6-DEFN`. The first addendum's later beacon superseded it. Had STATUS instead still read `COMPLETE → M6-DEFN`, the new session would have started M6-DEFN concurrently with this Review. This is recorded for the user. It is monitor behaviour, which is outside the repository and outside this Review's authority.

## Review closeout — second reviewing-agent pass

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Unchanged since the first addendum; re-confirmed by `boundary --expect-selector 448=70ff0860… 430=1c412850…` |
| Decisive claims independently re-derived | All-history `G4-B004` / multi-isolation search over M5 paths; isolation-row census from test source (186, 239, 183-188, two ungated); fixture construction path; ungated-identity count (360/808); durable-document shrink scan; `ledgers` verified against the incident range |
| Non-vacuity checked | The new guard FAILs on the real incident commits and PASSes otherwise. The census now distinguishes gated from ungated and producer-built from helper. |
| Prior obligations discharged/carried | `M5-CP3-TB2-REV-OBS-01` stays open with its census corrected, owner `M5-DEFN-R1`. OBS-02 is recovered, with its guard claim corrected. **OBS-03** is new and recovered. R16 OBS-01 and OBS-02 are unchanged. |
| Stable accounting | 51 / 14 / 37; debt 1 (M6); package `10771899191 / cef1c6ee…` under selector448 |
| New candidates/obligations recorded | `M5-CP3-TB2-REV-OBS-03` (recovered), in the tracker |
| ORIENTATION currency line | `M5-CP3-TB2-REV` (incl. two reviewing-agent passes), 2026-09-23 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3 census sentence corrected. §4 unchanged. §7 item 1 census corrected. §8 ledger entry corrected to name both overwrites and the effective guard. |
| CHANGELOG | Agent CHANGELOG restored and TB2-REV entry amended. Root entry amended. |
| ROADMAP | M5 section census sentence corrected |
| Selector manifest | n/a — no selector change |
| LESSONS | 176 corrected: inert-guard and sibling-search corollaries |
| Consolidation under CLEAN_UP_POLICY | n/a — nothing further to fold |
| Successor frozen | Exactly `M5-DEFN-R1`, with falsifiers and stop rules in the plan §§3-4 (corrected) |
| Turn boundary held | Runtime-free; no product/test/fixture/CMake/benchmark/selector change. `tools/review_check.py` gains the read-only `ledgers` subcommand. |
| review_check.py boundary | All checks **PASS except** `durable markers preserved in ORIENTATION.md 4 -> 3`. This is a **false positive**: the removed occurrence is my own first-pass prose ("`review_check.py` now guards its DURABLE markers"), deleted because that claim was false. ORIENTATION's DURABLE heading (line 1) is intact. I deliberately did not re-insert the word to satisfy the counter (`LESSONS.md` 172). Selectors 448/430 match their declared hashes, with no product/test/fixture/build or selector mutation. **`review_check.py ledgers --base d9441606`: ALL PASS.** |
| `STATUS` lifecycle maintained | Resume `IN_PROGRESS` (Resumed at = re-handoff `2026-09-23T21:37:23Z`) published first. The final `COMPLETE → M5-DEFN-R1` is the last write. |
| Pushed to origin, branch in sync | Confirmed by `git status -sb` after the final push |
