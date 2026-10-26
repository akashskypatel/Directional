# CB43 independent Review — RA-160.3 selector190 ingress re-home (2026-10-26)

**Turn:** `M6-CP3-CB43-RP01-SELECTOR190-LEGACY-INGRESS-REHOME-REV`. **Decision: ACCEPT STATIC SOURCE + COMPILE evidence only.** Authorize the frozen four-row `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY` manifest. The new A4 assertion is an *unmeasured hypothesis* until TB43; no runtime, selector497, CP3, or accepted-prefix promotion.

## Re-derived source and compile authority

- Verified source snapshot: GitHub run `40345708399`, artifact `12661646215`, ZIP SHA256 `437043a83cb02ae35bdb5747efebc214c01f0851b9ff1adcf80315fd436c7356`; event/source SHA `8fa4e27a13287d653406ee4d668825f63b1994aa`, 5914/5914 source hashes and tar digest passed. Temporary snapshot trigger is not semantic source.
- Independently fetched CB43 semantic commit `d354d6ae95afc73df968fc5cc4ee69fe5b7de451`: exactly **one** changed path, `tests/SurfaceCellsPhase10Tests.cpp`, in the named selector190 test body. No production, other test, selector, harness, or workflow edit in CB43. The compiled source tar and frozen later snapshot both hash the modified test file to SHA256 `29e15633c14ec2f4c919bbf24f08c5711cef08b7562d64f062118467fa2b3c87`.
- Independently downloaded immutable build package `12657932087` from compile run `40338106985`. ZIP SHA256 `4a65d5004e2afc08ab68361493a517c462cab68da6dd8019b94732cd3f860a26`; all **28/28** SHA256SUMS passed, preflight/build exit codes 0/0; all eight prescribed targets packaged; five source-status files empty. Package names exact semantic source `d354d6ae…`, `runtimeExecution=false`, GMP enabled, and the authoritative link includes both `libgmpxx.so` and `libgmp.so`. No binaries executed in Review.
- Recompared all **47/47** `Required_Green_Selector*` files byte-for-byte between compiled source tar and snapshot, unchanged. Existing accepted 449 selector SHA256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; CP2 focused12 SHA256 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`. No accepted selector bytes were changed by this review.

## Four independently assessed oracle halves

1. **Positive:** authoritative own-field A3 atlas is constructed and A4 must produce exactly one periodic holonomy. The original independently asserted `Produced` behavior was preserved; prior shared-atlas legacy-versus-authoritative comparison was removed, eliminating the known vacuous comparison.
2. **A3 negative:** source A2 is reconstructed using consistent component/sheet options. Independent face-triangle incidence enumerates a nonempty set of interior `SourceEdgeTopologyKey`s and chooses its minimum from ordered `std::map`. `FieldTransportAtlas::make` sorts source edges by the same key and rejects the empty legacy `edgeTransitions` with `MissingAdjacency` at that first key; exact code and key are asserted. The compact `matching`/`effort` vectors do not supply the edge-transition map at A3.
3. **Anti-vacuity:** restoring only `authoritativeField.edgeTransitions` into the same legacy field is explicitly asserted to make A3 succeed. This proves that missing adjacency, not unrelated fixture invalidity, causes the negative outcome when the test runs.
4. **No-atlas A4:** the cross-field overload routes legacy compact matching/effort and empty `edgeTransitions` when `options.fieldTransportAtlas==nullptr`; it independently requests the factory with no bound atlas. `SurfacePhaseFrontProduct::make` first checks the exact source/atlas binding and reports `InvalidSourceAuthority` / `AtlasSourceMismatch` / `atlas-binding`; `publish_phase_front_result` propagates `PublishedProductRejected`. Test requires `Rejected`, null product, and empty seeds/traces/proposals, and streams the rejection fields. **Limit:** if the fixture reaches a different producer or NotApplicable path, these assertions must fail in TB43. Static review cannot pre-credit them; NotApplicable seed fallback on other no-atlas inputs remains open under RA-160 D2.

**Frozen TB43 manifest:** `Architecture_M6_CP3_TB43_Selector190_Rehome_Verification_Case_Manifest.tsv`; SHA256 `812b843b8b01bb68cdb8e6845d9f6bd5aaa87c0b973a5a72967b241badffc676`. Exactly four unique rows: POSITIVE selector190; GUARD selectors 28, 179, 233. Use immutable CB43 package `12657932087`, semantic SHA `d354d6ae95afc73df968fc5cc4ee69fe5b7de451`, existing artifact-only TB harness and dedicated event; **no compile, relink, fixture repair, or broader selector497 run**. Falsifiers: any preflight hash/source mismatch; a missing, duplicate or skipped row; a nonzero process exit or expected-PASS failure (especially A4 factory locus); package mutation; a guard change. Stop and route discrepancies to independent TB43 Review; never repair test or producer inside TB.

## Disposition, debts and process limitations

RA-160.3 test-only re-home is statically accepted. No new stable regression or candidate; stable **66 events / 17 categories / 49 recurrences**, debt **1**, CP2 **491/491** accepted; TB38 **490/504** candidate and selector497 frozen/unpromoted; RP-01 open, RP-02 unreached. Carried: RA-160 D2–D5 and post-RP-01 O2, O1, O4, O5, O6, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 and DIAG-RETAIN. No new tracker row without observed regression.

Conservation miss: repository document reads preceded the mandatory `READ_MODE=snapshot` selection. Further substantive source inspection used the one verified snapshot; this miss is disclosed, not treated as compliance. `review_check.py boundary` was attempted on an extracted snapshot lacking authentic `.git` history: content checks appeared clean but ancestor/durable-baseline checks failed, so its full boundary verification is **unproven**, not PASS. Confirm source-only semantic diff separately from the GitHub commit, 47/47 compiled-selector byte identity, and immutable package. No authentic local branch sync claim.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 47/47 compiled/current selector files identical; accepted selector449 `d4a0d1b7…d6414`, CP2 focused12 `2aa57aac…c67374ed` unchanged. |
| Decisive claims independently re-derived | CB43 one-file commit; 5914/5914 snapshot; 28/28 package; 8 targets, 0/0 exits and GMP link; source/test SHA equality. |
| Non-vacuity checked | Minimum independent source-edge key plus A3 negative / restore-positive and no-atlas A4 typed rejection, pending TB43. |
| Prior obligations discharged/carried | RA-160.3 static discharged; RA-160 D2–D5, O1/O2/O4/O5/O6, and listed obligations carried unchanged. |
| Stable accounting | 66/17/49 debt1, CP2 491/491 accepted; selector497 frozen, CP3 not accepted. |
| New candidates/obligations recorded | None; no runtime in Review. |
| ORIENTATION currency line | Updated to CB43-REV and TB43 exact next. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 advanced to TB43; §4 unchanged (no representative execution); §8 unchanged (no new mechanism). |
| CHANGELOG | CB43 independent static Review entry added. |
| ROADMAP | CP3 boundary updated; status unchanged. |
| Selector manifest | New TB43 case manifest; required-green selector unchanged. |
| LESSONS | Existing non-vacuity and immutable-artifact guidance reused; no new lesson category. |
| Consolidation under CLEAN_UP_POLICY | CB43 record and RA-160 stay live for imminent TB43 and O2; no superseded evidence safely deletable this turn. |
| Successor frozen | `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY`, four-row manifest and explicit stop predicates above. |
| Turn boundary held | Read-only static review; no Directional binaries run, no product/test/fixture/selector/build mutation. |
| review_check.py boundary | Partial content checks; ancestor/source-baseline failed due absent real Git history in snapshot; not represented as passed. |
| `STATUS` lifecycle maintained | Entry published; final beacon updated only after durable document/cleanup processing. |
| Pushed to origin, branch in sync | Must verify remotely after patch transport; local snapshot is not an authentic Git checkout. |
