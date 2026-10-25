# TB37-REV — independent periodic-route atlas verification (2026-10-25)

**Turn:** `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY-REV`. **Decision:** **ACCEPT focused TB37 candidate evidence**; no checkpoint, full-selector or stable accounting promotion. No tests, binaries, benchmarks, builds, fixtures, selectors or product source executed or changed in this Review.

## Independent immutable evidence audit

- [Successful TB37 execution](https://github.com/akashskypatel/Directional/actions/runs/40179570318): result artifact `12593545901`, ZIP SHA-256 `d7fd939bfb3ab79b412d856ce214082558c3039c4a692b08613478dbafa31348`; diagnostic log artifact `12593955561`, ZIP SHA-256 `9ed45905ac1235ad0d6893c79cbd10b38e6cd69c9fea2e180f7e1c137aad28b8`.
- Re-hashed all **21/21** result `SHA256SUMS` records and individually checked **16/16** raw logs against the ledger. Unique manifest test identities 16/16; every selected exactly once, no skip, no missing/zero-selection, terminal GTest markers present. Independently counted 14 PASS (exit 0, one GTest passed) and 2 RED (exit 1, one GTest failed), matching the postflight JSON, rather than relying on report totals.
- The exact committed 16-row manifest independently hashes `d14b24d96c66c6a2c346b60003a5697dfab1764109b45854a3f145bba70b667d`. Row identities, predicted GREEN (14) / unchanged RED (2) and the result ledger match. Existing 497-row accepted/entry selector was **not** changed; the focused manifest does not extend the accepted 491-prefix.
- Original CB36 artifact `12590917524`: independently verified ZIP SHA-256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03` and **28/28** packaged `SHA256SUMS`, source `038ae7fd7c290731c28225d2693a3e13866e325a`, eight compiled targets, GMPXX and GMP linkage in packaged link command, `runtimeExecution=false`; immutable postflight `compile=false`, `relink=false`, `selector_mutation=false`, `postflight=true`. This Review did not recompile or rerun the package.
- Rechecked prior TB36-R1 baseline artifact `12586275698`, with **9/9** file hashes: frozen 191/192 GTest source lines, expected values and actual numeric enum values match TB37 rows 6/7 exactly. `Rejected` expected `02-00 00-00`, actual `Produced` `01-00 00-00`; expected `PeriodicHolonomyMismatch` `1D-00 00-00` (29), actual `00-00 00-00`. Row 7 independently confirms `is_produced()==true`. Therefore the harness's two `FROZEN_191_192_DISPOSITION_CHANGED` flags result from textual-name matching against numeric GTest presentation, **not actual changed dispositions**. No harness edit is authorized inside this Review.
- Previous 0/16 orchestration attempt `40179382655` receives **zero semantic credit**; its incorrect 13-row cardinality gate was corrected before the valid fresh-process 16-row run.

## Claims, scope and non-vacuity

The k=1 and k=2 tests check A3 admission, nonzero independent route rotation, A4 `PeriodicHolonomyMismatch(29)`, rejection, absent produced product and all negative locus fields. The directed route test checks the ordered 32-step face/edge mapping against independent expected compact IDs, distinguishes reversal, and requires non-identity `+1/-1` transport on distinguished steps. These three RED in TB36-R1 and PASS in TB37; retaining their meaningful assertions makes the D2 producer fix behaviorally discriminating. The 11 previously passing TB35 controls are still green. This is focused **synthetic periodic-route behavior**, not proof of whole-matrix production or an accepted 497-row census; in particular 189/190's legacy-ingress claims remain non-discriminating under atlas ingress.

RA-153.4 preregistered STOP conditions are independently checked: new witnesses did not remain at reason 68; frozen 191/192 did not change disposition; no prior PASS became RED. Consequently accept TB37 as focused evidence only. No new stable regression, no new stable ID; existing non-stable harness classification should remain recorded until a separately authorized orchestration fix. **Stable 66 events / 17 categories / 49 recurrences, debt 1; CP2 491/491 accepted; TB32 481/500 candidate; 497 entry selector frozen; CP3 unaccepted; RP-01 open, RP-02 unreached; G4-B002 still outstanding.**

## Exactly one successor and falsifiers

**Authorized successor:** `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` — Test + Benchmark only, a separate immutable CB36-package 497-identity census versus the independently retained TB32 historical ledger (not a replay of TB37 or a new selector). Before runtime, freeze exact 497 identities and immutable package SHA; preserve 491 accepted prefix. **STOP for independent Review** if any accepted-green loss, missing/duplicated/zero-selected case, package/selector hash drift, failed immutable postflight, bad typed first failure, or unexplained discrepancy against the TB32 19 inherited RED. No source, fixture, oracle, selector or compiled package changes in TB38. Do not promote CP3 on the census alone.

**Carried:** RA-152.5 axis binding; RA-153 E1/D4 frozen 191/192 oracle re-homing through separate DEFN (191 A3 source-edge, 192 k=1 atlas field, 189/190 meaningful positive authority); seven untyped owners; A5 `focused30:12`; A4 `cp3entry:4`; A3 `selector:442`; DEFN-T1; DIAG-RETAIN; DEFN-SEAM-NZ; RA-146.2/4; RA-45.4; G4-B002. No obligations silently discharged by the 14 focused passes.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Accepted 491 prefix not amended or claimed re-executed; 16-row focused manifest SHA above; exact accepted 449/other frozen hashes handled by unchanged baseline checker; no selector mutation |
| Decisive claims independently re-derived | 16 raw process/log joins, 14/2 distribution, 21/21 hashes, 28/28 package hashes, TB36 original numeric enum comparison, target/GMP proof |
| Non-vacuity checked | Three formerly RED witnesses now PASS with A3/route/locus/reversal checks; 11 historical PASS controls preserved; 191/192 not promoted |
| Prior obligations discharged/carried | RA-153.4 focused D2 measurement discharged; RA-153 E1/D4, RA-152.5, G4-B002, RA-146.2/4, RA-45.4, RP-01, DIAG-RETAIN and listed owner queue carried |
| Stable accounting | 66 / 17 / 49, debt 1, accepted CP2 491/491, TB32 481/500 candidate, frozen selector497, CP3 open |
| New candidates/obligations recorded | Existing TB37 non-stable harness warning adjudicated; tracker updated in place; no new stable ID |
| ORIENTATION currency line | Updated 2026-10-25 to accepted TB37 focused and TB38 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 evidence and priority updated; §4 n/a (witness matrix membership unchanged); §7 reordered; §8 prior unresolved warning corrected for TB37 runtime |
| CHANGELOG | New TB37-REV entry prepended |
| ROADMAP | CP3 boundary updated; checkpoint remains active; no milestone closure |
| Selector manifest | n/a: no selector appended, changed or promoted |
| LESSONS | Existing non-vacuity and predicted-vs-observed lessons cited; no genuinely new pattern |
| Consolidation under CLEAN_UP_POLICY | n/a: no stale history deletion or redundant durable records introduced |
| Successor frozen | `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` with falsifiers and stop conditions above |
| Turn boundary held | Review analysis only; no implementation/test/fixture/selector mutation, no compile or benchmark |
| review_check.py boundary | Local synthetic snapshot baseline: all selector hashes and no source/test changes PASS; historical rewrite-ancestor and blob checks FAIL because snapshot omits real Git history. These are verification limits, not a claimed clean full check |
| `STATUS` lifecycle maintained | Entry beacon written; final beacon to be written directly after remote closeout, with same start timestamp |
| Pushed to origin, branch in sync | Pending Google Drive patch transport; verify applied commit and current branch before final beacon; no claim that synthetic local Git HEAD proves remote sync |
