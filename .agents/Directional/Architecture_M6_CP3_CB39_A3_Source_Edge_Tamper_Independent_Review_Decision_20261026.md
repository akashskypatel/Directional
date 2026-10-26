# CB39 A3 source-edge tamper — independent static Review (2026-10-26)

**Canonical turn:** `M6-CP3-CB39-RP01-A3-SOURCE-EDGE-TAMPER-REHOME-REV`. **Verdict:** ACCEPTED as a **static, compile-only test-source correction** under RA-157.3; no runtime acceptance is claimed. The next separately authorized turn is `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME` (192 k=1, 247 k=2; test-only Code + Build). PR #8 remains draft/open.

## Independent evidence

- Exact semantic/package source `c6cc82aa0aa8e5e46dc58cfc887050bf46a65963`; commit diff changes **only** `tests/SurfaceCellsPhase10Tests.cpp` in two hunks (`@@ -1623,31 +1623,35 @@`, `@@ -5053,32 +5057,36 @@`), net +50/−42. No production, fixture, helper, selector, benchmark or build-system modification.
- Compile [run 40254362620](https://github.com/akashskypatel/Directional/actions/runs/40254362620), [artifact 12621099926](https://github.com/akashskypatel/Directional/actions/runs/40254362620/artifacts/12621099926); independently computed outer ZIP SHA-256 `0d2ad13c768a830d3f7a9954ee50effc72481706b89e1544684fd003f018089b`, independently verified **28/28** `SHA256SUMS` members. Packaged source tar names the exact semantic SHA; source-status files empty.
- Compile result: all eight required targets listed in `metadata/compiled-targets.txt` and completed; preflight/build exit codes both 0; `DIRECTIONAL_ENABLE_GMP:BOOL=ON`; authoritative link command includes `libgmpxx.so` and `libgmp.so`; `runtimeExecution=false`, `turnBoundary=Code+Build-only`. No executable was run in this Review.
- Selector **204**, `MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback`: pre-existing untampered A4 `Produced` and nonempty forward observations preserved. Independent A2 uses same all-zero source-component and sheet arrays as `build_segment_route_network`; untampered `FieldTransportAtlas::make` is asserted successful. Tamper key is route element 1, source edge (6,7); `interior_source_edges` proves that key is interior. Only `sourceEdge` is set to −1. Tampered atlas is required to fail with exact `NonReciprocalAdjacency` and `sourceEdge == tamperedKey`.
- Selector **191**, `MalformedAuthoritativeCrossingProvenanceFailsClosed`: independent A2 uses the same all-zero component/sheet arrays as periodic route helper; untampered field is `balanced_periodic_route_field(fixture)`, validated by an `ASSERT_TRUE` atlas success prerequisite. The first expected periodic route edge must belong to `interior_source_edges`; only its transition's `sourceEdge` becomes −1. Tampered atlas must return the same exact code and typed edge key.
- Independent predicate trace: `src/authority/FieldTransportAtlas.cpp` builds transition lookup by endpoint `SourceEdgeTopologyKey` (about lines 1966–1975), then checks `raw.sourceEdge != edgeIndex` before emitting `NonReciprocalAdjacency` with the currently visited edge key (about lines 2016–2027). This tamper therefore remains locatable by the endpoint key rather than disappearing from lookup. Untampered A3 positive prerequisites discriminate against an always-rejecting atlas; mutation changes a single source-index member, leaving the face-key disjuncts unaffected.
- Both old A4 negative calls on tampered inputs were removed per RA-157.3; their expected failures were bypassed by checked A3 under D1. The A4 `MissingTransitionProvenance` reachability question is **O4**, already assigned to the later `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` turn. This Review does not reinterpret removed A4 negatives as runtime success.

## Scope, residuals and successor

CB39 satisfies the authorized *static* test-body and compile contract. Freeze the intended TB41 identities **191 and 204** for later artifact-only runtime verification, not as PASS outcomes. No new candidate/stable event: stable **66/17/49**, debt **1**; CP2 **491/491** accepted; TB38 **490/504** candidate; selector497 unpromoted; RP-01 open, RP-02 unreached. Preserve RA-157 K3 (selector250 rail assertion gap covered by 236) and O1–O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 with their existing owners.

The next turn `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME` is limited to selector192 (k=1) and selector247 (k=2), re-homing the turning-field monodromy negative stimulus while retaining A4 assertions. Falsifiers: the actual A3 prerequisite rejects the intended balanced field; either negative fails to reach intended A4 owner; the two witnesses collapse into a vacuous identical case; or unrelated test/production/selector bytes change. Stop on any falsifier and route to Review rather than compensating through validator weakening. No successor source work occurs in this Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no selector added, modified or promoted; source diff lists only the two existing test bodies. |
| Decisive claims independently re-derived | Commit two-hunk source diff, A2/A3 fixture options, endpoint-key lookup/predicate, source-edge error locus, outer ZIP and 28/28 member hashes, GMP link, eight-target compile boundary. |
| Non-vacuity checked | Untampered atlas positive assertion precedes single-member source-edge tamper; exact code + key test fails on accepting malformed source-edge metadata. Runtime of these new expectations remains TB41's responsibility. |
| Prior obligations discharged/carried | RA-157.3 CB39 static spec discharged; O4 and all named carried obligations retained with existing later owners. |
| Stable accounting | 66 events / 17 categories / 49 recurrences; debt1; CP2 491/491 accepted; TB38 490/504 candidate; 497 frozen/unpromoted. |
| New candidates/obligations recorded | None; O4 already in tracker/DEFN owner. |
| ORIENTATION currency line | Updated to CB39-REV 2026-10-26. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 updated, §4 n/a witness acceptance unchanged, §7 CB39 item advanced to CB40, §8 existing unconsumed-negative-stimulus pattern remains applicable. |
| CHANGELOG | Historical entry added for independent CB39-REV. |
| ROADMAP | Active M6-CP3 checkpoint unchanged; stale exact-next CB39 pointer replaced by CB40. |
| Selector manifest | n/a — no selector changed/promoted; TB41 191/204 future selection freeze is not a new selector manifest. |
| LESSONS | Existing rules on independent oracles, single-writer authority and compile/runtime boundary reused; no new generalizable pattern. |
| Consolidation under CLEAN_UP_POLICY | Inventory completed; CB39 compile source/package record remains live required TB41 authority; prior RA-157 and TB40 decisions carry distinct operative facts. No eligible per-turn record retired in this Review. |
| Successor frozen | `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME`, RA-155.3 B / RA-157.4, with falsifiers above. |
| Turn boundary held | Independent static analysis only; no product, test, fixture, selector, build-source changes, compile, benchmark or Directional runtime. |
| review_check.py boundary | Not executable authoritatively on downloaded snapshot: source archive has no Git history or baseline commit; independent byte-scope inspection performed instead. Must be run in a proper Git checkout before formal final compliance is asserted. |
| `STATUS` lifecycle maintained | Entry beacon published; final beacon requires independent write after durable closeout. |
| Pushed to origin, branch in sync | Pending documented patch transport and postflight; not claimed by this source snapshot. |
