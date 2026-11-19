# TB144 framing and struck-position — independent Review (2026-11-19 UTC)

> **Superseded in part by [RA-266](#ra-266--adversarial-re-review-of-this-review-2026-11-19-utc):** the MATCH verdict stands; the prose EC2b freeze is replaced by exact patches CB168D/CB168E and TB145.

## Situation

**MATCH, limited evidence; no product acceptance.** Independently verified all 963 prior comparisons (960 gate + 3 census) against TB143 using frozen N1–N7, including TB131's exact N3 rule. CB168B's diagnostic framing shows zero doubled M3 prefixes. The newly added row 961 passes, while the already-known required-control row 858 remains RED; the workflow is therefore not a green full gate. Freeze the bounded, inert EC2b successor only. No EC2b or EC3 source work occurred in this Review.

## Background and immutable evidence

- Semantic source `e0f085eb65ed186bf836305f2896c69c6c90c519`; CB168C package `14498438448`, SHA-256 `041ee85006926b674b3692a1315e9ba0695397a144ea0f00c406b4a6cfee081f`, **28/28** file hashes. Eight GMP/GMPXX targets compiled without runtime execution.
- TB144 gate run `44462908179`, artifact `14501920082`, ZIP SHA-256 `a2cdbdf635d91b9fde4be5f5fa093d96d088714b24e5f22988518051824b7922`: **1,930/1,930** hashes; 961 executed, 960 PASS, known row 858 RED, postflight true. Required-control failure is real; no skipped/missing/abnormal cases. Separate census run `44462935556`, artifact `14502085765`, SHA-256 `e7573335b7f222f6e6e383c2fa714697a14e70b5eaefac83bd89f1abdcf601c4`: **9/9** hashes; Cylinder PASS/288, BunnyRandom and Vase RED, postflight true.
- Independently downloaded TB143 gate `14490999571` (SHA-256 `ffa03f7e359eeed8e76ad3f4f7a1624bed5f69d44c97a50b860939a8a044b11d`, **1,928/1,928** hashes) and TB143 census `14492518198` (SHA-256 `4089fc0de5bf38620f98e077b80a0b00706c17240869ff564ff36eb9b8b7cfa1`, **9/9** hashes). All **3,876** indexed entries of these four runtime ZIPs verified separately. CB168C package adds 28 checks; no failed hash.
- Frozen manifest SHA-256 `fc1264e96628ad659302905f5537d8f4fc09973ffbfeaea3a4f228069613e949` (961 gated + 81 deferred). Exactly one added gated identity in comparison with TB143, `FieldAlignedCarrierOccupancy.CarrierContactCutsTheStruckTraceAtItsEntryCrossingOnly`; it is row 961. Accepted CP2 491/491 PASS, no selector497 promotion. Both runtime boundaries say `compile=false`, `relink=false`, `configure=false`, `benchmark=false`.

## Assessment — independent comparison and negative controls

1. **N1–N7:** Per-index prior ledger fields unchanged (960 gate, 3 census); after the frozen normalization, their logs have no mismatches. N3 splits each occurrence of `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` into a complete-record multiset, checks prefix count and compares all non-record remainder bytes in original order. Gate recovered 1,738 complete M3 records, census eight; no doubled M3 prefix lines across the 964 TB144 log files. No relaxation of the TB131 N3 rule. Timing and line-ending normalization, census opaque GetParam treatment and whole-line entry-receipt removal followed frozen N1/N2/N4/N7, not newly devised exceptions.
2. **Raw receipts and source binding:** Gate 1,200 each `slideProposal`/`committedSlide`, census 66 each; all 1,266 each preserved byte-for-byte. Entry-coincidence records: 240 gate across 20 rows and six census in one row; exact per-row record multisets unchanged (246 total). The pre-existing sphere 19/19 pair (`4:7`, `6:7`) still occurs at `(0,2)`, parameter `574181338608147/4503599627370496`.
3. **Decisive cases:** Row 961 PASS with one selected test and process exit zero; its injected test actually checks two valid exact positions and rejects missing locus, wrong trace/edge/parameter, out-of-range segment, vertex boundary and unsupported slides. `carrier_contact_struck_position` is pure and unwired from production. Row 858 remains `SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported`, RED at `tests/SurfaceCellTracingDisplayTests.cpp:155`, not a new regression. BunnyRandom first binding failure remains trace 82; Vase RED. Cylinder returns 288 quads. Source-grid recovery and CP3/D0 acceptance were not established.
4. **Non-vacuity:** Independently changing the comparator's prior row-169 M3 record by deletion, duplication or payload edit, or changing its non-record remainder, all caused comparison failure. A prior ledger verdict mutation also caused a mismatch. Zero doubled-prefix lines alone is not proof that the concurrent print race can never recur; the seven single-write emitters remove the known multi-insertion form. No evidence proves full runtime control green or a real carrier-locus terminal was produced.
5. **Stable accounting:** **66 events / 17 categories / 49 recurrences**, produced-witness debt one, deferred 81, accepted CP2 491/491, CP3 selector497 unpromoted. The retained required-control RED and existing census REDs do not justify a new stable event or candidate. C5/O42/O43/O46/O47/O48/O49 and H4 remain open; H2/FC-6/terminal-cut and row858 repair remain held under their existing authority; D11=A, D12=A.

## Recommendation — EC2b frozen; not executed

Freeze only **`M6-CP3-CB168D-P13-CARRIER-CONTACT-EDGE-NODE-BINDING`**, compile-only, per [RA-265 S3](Architecture_M6_CP3_TB143_P13_Entry_Coincidence_Receipt_Full_Gate_Independent_Review_20261119.md#s3--realigned-sequence) and [bounded plan](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Plan_20261119.md). The implementation must bind the optional exact carrier locus of an existing terminal contact to the struck trace's incoming crossing on the same source edge and exact parameter, with the helper's interior cut position. The resulting contact is an edge node, not a face contact; it must use the existing shared node and exact provenance, without positional merging, widening input eligibility or switching the production contact producer. No real producer sets `carrierLocus` yet, so any direct-product difference would be unexpected; first TB after compile must check strict comparison and non-vacuous injected positive and negative tests. EC3 (transverse entry/entry production switch) remains separate and later; BunnyRandom's same-face co-directional merge remains O48.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB144 manifest SHA-256 `fc1264e96628ad659302905f5537d8f4fc09973ffbfeaea3a4f228069613e949`; existing 491 accepted case verdicts PASS; no selector edited or promoted |
| Decisive claims independently re-derived | Four ZIPs, 3,876 hashes; 963 matched prior logs and ledgers; raw receipts and row verdicts; build/source package checked |
| Non-vacuity checked | Five comparator mutations detected; row961 exercised two positive and multiple negative exact cases; production contact remains unwired |
| Prior obligations discharged/carried | Diagnostic framing single-write form verified as no doubled M3 lines; EC2a row961 passed; row858, C5/O42/O43/O46/O47/O48/O49/H4/FC-6 and CP3 exit carried as above |
| Stable accounting | 66 / 17 / 49, debt1, deferred81; CP2 491/491 accepted; selector497 not promoted |
| New candidates/obligations recorded | No new stable candidate; EC2b negative/positive controls frozen in plan; tracker retained |
| ORIENTATION currency line | Updated for TB144-REV, 2026-11-19 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 current; §4 n/a (no changed witness state); §8 n/a (no new recurring defect) |
| CHANGELOG | Added independent review entry |
| ROADMAP | n/a: M6-CP3 still active/unaccepted |
| Selector manifest | n/a: no accepted selector or membership change |
| LESSONS | Existing **Compile, runtime, and acceptance are independent evidence** and **A witness must be capable of falsifying its assertion** reused; no new pattern |
| Consolidation under CLEAN_UP_POLICY | Folded four completed superseded documents (CB168A plan and compile record, consumed CB168B/CB168C/TB144 plan, and TB143 execution report) verbatim into [Volume D3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb144-review--verbatim-folded-records-2026-11-19-utc), with SHA-256, exact original names and line counts indexed in [M6 consolidated record](M6_Consolidated_Record.md#tb144-review-consolidation-2026-11-19-utc); live links repaired. Current TB144 execution and Review, RA-265 Review, CB168B/CB168C active source records and EC2b plan retained. |
| Successor frozen | `M6-CP3-CB168D-P13-CARRIER-CONTACT-EDGE-NODE-BINDING`; falsifiers and stop rules in [plan](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Plan_20261119.md) |
| Turn boundary held | Runtime-free Review; no product, test, fixture, selector, build source or benchmark changed |
| Documentation drift audit | `document_drift_audit.py --root . --base HEAD --json` on verified synthetic snapshot: 0 errors, 2 warnings (handoff navigation size 17,322 bytes; review-authorized in-place handoff change). Current durable headings and links preserved; no automated audit warning was suppressed. |
| review_check.py boundary | Local synthetic-Git checker PASS on product/test/fixture/build/selector bytes, but FAIL on rewrite baseline ancestry because the downloaded source snapshot contains no authentic Git objects. Independent GitHub comparison **proves** `8b7299b43` ancestor (behind 0), CB168C source ancestor and no product/test/build drift. All five durable headings from the rewrite baseline survive in current branch. Local full-check PASS is **not** claimed; remote equivalence is checked separately. |
| `STATUS` lifecycle maintained | Entry beacon written; final beacon is the last repository action |
| Pushed to origin, branch in sync | GitHub connector independently confirmed consolidation apply on working branch: one new commit, 15 intended documentation-only paths (four original files folded); dispatcher run `44472664640` PASS, artifact `14504917234` digest verified, complete SHA-256 and source authority matched. Final remote head must still be checked after cleanup. Local `git status -sb` cannot prove origin sync without an authentic Git checkout; do not claim that stronger check. |

## RA-266 — adversarial re-review of this review (2026-11-19 UTC)

### S1 — what holds

- TB144 is **MATCH**. A Haiku audit applied the frozen CB168B (`7ec11b82…af12`) and CB168C (`f8badfdf…e204`) diffs to `b77a81ff5`. All six changed files are SHA-equal to HEAD, and source `e0f085eb6` is an ancestor.
- A second audit found the execution report's evidence for every frozen criterion:
  - 963/963 prior MATCH;
  - 1,266 raw slide receipts of each kind;
  - 240 + 6 entry receipts;
  - row 961 PASS, 960/961;
  - 491/491;
  - row 858 at `:155`;
  - BunnyRandom trace 82;
  - Cylinder 288;
  - no doubled M3 prefix.
- The "19/19 sphere witness rows" figure is consistent with 20 receipt rows: 19 rows fail on (0,2), and all carry the `4:7/6:7` receipt.

### S2 — defects in this review's successor

1. **Prose freeze.** It froze EC2b as a prose plan, which the implementation agent would have had to design. Successors must be exact patches (RA-225, RA-261).
2. **Wrong binding rule.** It demanded that the locus edge be "in selected cut edges" and "match a real crossing", and rejected anything else with a typed error. A carrier contact on a non-cut edge has no crossing: the contact node itself is the cut point for both traces. The rule would turn valid EC3 contacts into `InvalidCutGraphBinding`.
3. **Infeasible tests.** The injected positives and negatives through `build_cut_node_bindings` and `face_contact_nodes`, and the "rotate/reorder source faces" invariance, all need a hand-built `FieldAlignedCurveNetwork`. That is impossible (RA-248). The pure arithmetic is already row 961.
4. **Existing behavior not read.** `trace_event_position` already resolves an edge-carrying event to the struck trace's incoming-carrier segment, and `build_node_loci` takes the edge locus from `event.sourceEdge`. The only real faults are two:
   - the face-contact classification, which cuts at `{k, 0}` beside the crossing `{k, ∅}`;
   - the second node at a cut-edge crossing.
5. **EC3 left without a measurement.** Nothing measured which trace arrives later at the shared entry (that trace terminates), or whether arrivals tie. EC3 would have been frozen blind.

### S3 — realigned sequence

[Frozen plan](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Plan_20261119.md).

| Turn | Scope | Evidence |
|---|---|---|
| CB168D (EC2b) | Exact diff `cf726ced…8de`: non-face carrier contact, validated binding, cut-crossing node merge, struck position from the record | compile; inert (no locus produced) |
| CB168E | Exact diff `67418422…dc0`: receipt gains `firstArrival=` and `faces=` | compile |
| TB145 | TB144 manifest unchanged; 964 records vs TB144 under N1–N7 with the receipt suffix stripped; EC3 census | full gate |
| TB145-REV | Freezes EC3 (transverse switch) as an exact patch, with predicted sphere outcomes | Review |
| then | EC3 TB → CB168 → [O49] → CB169 H4 cutover → CB170 → CB171 → CB172 (O48) | RA-262/263/265 |

### S4 — closeout

- **Review boundary.** Runtime-free: `-fsyntax-only` only, all files at base warnings, both patches stack.
- **Housekeeping.**
  - The handoff is trimmed back under its 16,000-byte budget.
  - Delegation: two read-only Haiku audits.
  - No product, test, gate or selector change.

