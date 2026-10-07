# M6-CP3-TB1-ENTRY-R1-REV WIP handoff

Turn is **IN_PROGRESS**. This is a runtime-free independent Review. Do not repair product/test source, run generated binaries, or begin CP3 exit work.

## Exact review authority

- Review entry STATUS commit: `5e6c6a4ccc4f1a86696e7f74476786a83218a18d`.
- Exact review snapshot trigger/event: `e08872dbe3235e2c4a35dd71ad76088b7e0423e5`.
- Snapshot run: `37690809635`; validator, snapshot, and mailbox jobs are GREEN.
- Snapshot artifact: `11513042423`; provider/download SHA-256 `56b84036ced75ff5989ad6e726a08f9e5e88345e26dd523eb2d27a268a0ac166`; verified source archive SHA-256 `fae0c0d368c7b85927d29ab7da7818c9020118bb3f79c3be8275119c4ee1222e`; `runtimeExecution=false`.
- Immutable R1 TB run/job: `37645974118 / 112876903729`.
- R1 result artifact: `11495166428`, SHA-256 `5ee8380ee7bb557a58274ef0b7cefa47e1abf1ef549650afcb7fff1330f161a6`.
- Semantic package source/artifact: `68000a95a94b1d95f22694dc093dc6a538e1b7b4 / 11488700954`.
- Independent result verification: self-manifest 1019/1019; 497 exact-filter processes; 482 PASS / 15 RED; exact-one 497/497; zero skips; benchmark 0; package/source/execution-view censuses unchanged; no configure/compile/relink/discovery/repair/retry.
- Frozen gate re-hash independently matches: focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`; selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.
- All 15 raw RED logs were independently SHA-256 checked against `red-ledger.tsv`; all matched. Combined/focused/selector/CP3 ledgers also match their published digest files.

## Independent adjudication in progress

### R1-CAND-01 — same stable event as prior CAND-02; recovery not proved

Ten produced-torus/A6 rows remain RED. Direct rows reject with `MissingIsolationSeamEquivalenceAuthority:a6-side-evidence`; downstream rows disappear after the same A6 failure. Current A6 still defines `crossSheetSeam` as shared `collinearEdge` plus unequal sheet, then requires reciprocal isolation evidence and a seam certificate. That repeats the already-counted `RP-01 AUTHORITY_DOMAIN_CONFLATION` root from prior CP3-entry CAND-02: source-edge collinearity/sheet inequality is not itself certified isolation-seam authority.

Provisional Review disposition: **existing stable event / recovery NOT proved / no new pricing**. R1-CAND-01 must not add another event or recurrence. Stable totals remain 63/17/46, debt 1 unless later Review evidence contradicts this.

Required definition work: freeze an independent producer-owned discriminant between an ordinary cross-sheet collinear relation and a certified isolation seam, and prove a missing/tampered seam certificate cannot silently downgrade a true seam into the ordinary path.

### R1-CAND-02 — D1 non-stable witness authority defect

Identity 1 chooses `nonzero_z4_torus_witness_fixture()` for a source/A3 nonzero-Z4 relation and only afterward asserts that the selected endpoint face gauges differ by 90/270 degrees. It REDs because that selected relation does not meet the added premise.

RA-31a required evidence that **some produced nonzero-Z4 periodic pair** satisfies the non-self-inverse gauge premise; it did not authorize assuming the preselected source witness has it. Provisional disposition: **NON-STABLE test/witness authority defect**. The next Definition must statically derive a deterministic real-produced relation/fixture meeting the premise or STOP; no runtime search/tuning and no hand-built A4/A5 record.

### R1-CAND-03 — D2 non-stable witness/definition authority defect

Identity 2 successfully produces A5 but finds no HardRail relation with 90/270 endpoint face-gauge difference, so it fails before the pre-registered withdrawn-certificate assertion. Identity 6 on the same nonconstant HardRail fixture passes, proving the A5/global-sheet-label recovery itself is reachable.

RA-31a explicitly required D2 non-vacuity/A5 production to pass and allowed the sole RED only at the withdrawn-certificate assertions. Therefore the R1 acceptance shape is not met. Provisional disposition: **NON-STABLE witness/definition defect**, owned by the already-planned `M6-DEFN-R5-R1` cross-rail matching-τ redefinition.

### R1-CAND-04 + R1-CAND-06 — one non-stable seam-collinear fixture reachability defect

D3 and D7 both call the same `m6cp3_seam_ordinary()` helper on `split_isolation_fixture()` and both get no produced qualifying relation. The fixture's known seam crosses bridge-corner interiors; it does not establish a seam-collinear `OrdinaryFront` relation. The R1 plan froze D3/D7 product semantics, so these two REDs do not authorize production changes.

Provisional disposition: **merge into one NON-STABLE test-fixture reachability obligation**. The next Definition must freeze a deterministic producer-reachable seam-collinear OrdinaryFront witness, or STOP if none can be derived without record forgery/runtime tuning.

### R1-CAND-05 — D4 non-stable oracle contradiction

Identity 4 searches a `square_fixture()` phase-front edge of kind `OrdinaryInterior` and then requires `!edge.route.empty()` so it can take the first route step as a carrier. Production A5 validation explicitly requires the opposite: an `OrdinaryInterior` is invalid when `!edge.route.empty()`. The test is therefore contradictory to the frozen producer contract before it reaches the intended typed-barrier check.

Provisional disposition: **NON-STABLE test-oracle defect**. The next Definition must derive the ordinary barrier carrier directly from source topology / `SourceChartTransitionGraph`, prove the unmarked transition exists, then prove inserting that exact source edge into typed `hardFeatureEdges` blocks it. Do not add a route to OrdinaryInterior.

### Identity 6

`M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` PASSes. This independently supports the RA-31a global-sheet-label recovery but cannot promote the package because the 497 gate has 14 additional unexpected REDs plus identity 2 failing too early.

## Provisional Review disposition

**REJECT R1 candidate for definition-gated recovery; keep it unpromoted.** The RA-31a acceptance shape was 496 PASS plus only identity 2 RED after its non-vacuity/A5 prerequisites. Actual result is 482/497.

- No new stable event/category/recurrence is presently justified.
- Stable accounting remains **63 events / 17 categories / 46 recurrences**, debt 1.
- Reviewed runtime remains CP2 authority `11391685901 / 5ce3132e...` (491/491).
- CP3 exit remains held.
- Provisional exact successor: **`M6-DEFN-R5-R1`**, runtime-free Definition, followed by its mandatory Definition Review before any further Code + Build.

## Successor scope to freeze before this Review closes

`M6-DEFN-R5-R1` should be bounded to:
1. D2 cross-rail matching `τ` redefinition and a discriminating real-produced HardRail witness.
2. Exact producer-owned A6 isolation-seam classification that distinguishes certified seam authority from mere collinearity/global-sheet difference and remains fail-closed under certificate/evidence tamper.
3. Deterministic non-vacuous witness authority for D1 (produced nonzero-Z4 90/270 pair), D2 (produced HardRail 90/270 premise), D3/D7 (produced seam-collinear OrdinaryFront), and D4 (source-transition carrier barrier oracle), with no runtime search/tuning or forged stage records.
4. Explicit STOP rules when any required witness cannot be statically derived from a real producer fixture.
5. Preserve the frozen 497-name gate; no selector mutation in the Definition turn.

## Remaining Review closeout work

Before completing this Review:
- write the final `Architecture_M6_CP3_TB1_Entry_R1_Review_Record.md` with mandatory closeout table;
- update `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md` (currency, §3, torus witness state, §7, §8), `ROADMAP.md`, `TODO.md`, `Future_Chat_Session_Handoff.md`, and root `CHANGELOG.md`;
- add the bounded `M6-DEFN-R5-R1` Definition plan;
- run `python3 .agents/Directional/tools/review_check.py boundary` against the exact review working tree and record the result;
- consolidate stale contradictory current-state prose;
- cleanup the Review snapshot trigger via the durable manifest workflow while retaining mailboxes/request slot/durable workflows;
- verify branch hygiene/sync;
- only then complete to `M6-DEFN-R5-R1`. Do not begin the successor in the same canonical turn.
