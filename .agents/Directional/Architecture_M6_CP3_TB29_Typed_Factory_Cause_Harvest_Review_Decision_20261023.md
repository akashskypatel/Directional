# RA-141 — Independent TB29 typed-failure review (2026-10-23)

**Turn:** `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV`. **Disposition:** TB29 immutable 44-case evidence is mechanically authentic; CP3 remains unaccepted, and no cause is assumed from test names. Source/fixture/test/selector, build and runtime are unchanged by this Review. **Authorized bounded successor:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` (Definition only). Other owners remain explicitly separate and are not authorized to change code in this turn.

## Primary evidence independently reproduced

- Original CB28A semantic source `4473e41e94a35f1bf189fa046e86bac92c7391fb`; package `12465330920`; TB29 run `39906802267`, artifact `12481556884`; downloaded ZIP SHA-256 `4e639a633a64df419f1891083911506679c6c4848f1ecbce7b206c4f5d653ae1` independently matched provider digest. 92/92 packaged checksums verified. The 44 raw-log hashes match the ledger; each has exactly one matching `[ RUN ]`; all 44 manifest/ledger identities, binaries, verdicts and 35 TB28 RED phase:ordinal mappings are exact. `execution-boundary.json`: planned/executed 44/44, PASS 9, RED 35, missing/skipped/duplicates/control_bad/unexpected_pass all zero, postflight true, no configure/compile/relink/benchmark, exit zero.
- Frozen TB29 manifest SHA-256 `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236`; TB28 35-RED inventory SHA-256 `66c0ba377c834a969d481cf1ee2253688fa12b7686a0ced6d9da9695e01eb3da`. These hashes were recomputed from source. No selector was changed; 497-case CP3 replay was not performed.
- Independent disjoint failure partition: **13 checked-factory** = 6 `certificate-pair-binding` + 6 `face-gauge-missing` + 1 `open-rail-chain`; **8 A3** = 7 `CycleTransportMismatch` + 1 `SingularityMismatch;sourceEdge=(2,3)`; **1 A5** = `OccurrenceHardRailTransportMismatch`; **13 untyped** = `reason-not-observed`. Total exactly 35, no double allocation. The literal factory `code=0` denotes `InvalidSourceAuthority` at these sites, not successful admission.
- Verified one-source, immutable-A6 non-vacuity for four new negative tests by inspecting `check_d7_certified_seam_negative` (TQ:4123+): it first builds positive A5, A6 and A7 from the actual D7 witness, applies each targeted mutation with preconditions, asserts the independently expected A6 outcome, then invokes A7 on the mutated A5 **with original A6** and asserts `UncertifiedCrossSheetBinding` and the exact site. A7NEG:1 asserts a connecting unrelated-seam transition; :3 holds source support/selected face constant while changing lattice coordinate; :4 withdraws the binding while retaining the sheet and certificate. Their four log PASS results alone would be weaker evidence; source controls make earlier A6 failure unable to masquerade as an A7 PASS.

## RA-141.1 Exact M1 measured scope and non-merging

**Only six first rejections actually reach RA-105.3's R2 certificate-pair-binding clause**, uniquely labelled at `SurfaceCellTracing.cpp` around the certificate pair check (`first/second railId`, route/opposite orientation, and region). Identities: `focused30:3,22,23` and `selector:139,140,142`. They share first-failure site `certificate-pair-binding;certificate=0;rail=2`, but have different test contracts; the Definition must preserve validation precedence, semantics and named error taxonomy without weakening the certificate binding. This is a **measured branch and a candidate precedence defect**, not proof that each expected outcome has the same correct fix. The older RA-105.3 static ten-row grouping is not accepted as a ten-row first-failure proof.

**Exclude** the other seven typed factory cases: `selector:220,221,296,302,304,439` fail at `face-gauge-missing`, before certificate checks; `cp3entry:4` fails at `open-rail-chain`. They require independent A6/gauge and open-rail-chain owners, respectively. The four other former RA-105 M1 identities `selector:211,219,227,230` emit `reason-not-observed` (wrong expected code/name observed); the TB29 typed material does **not** prove their first clause. Preserve their assertions and carry them as M1-adjacent unknowns, not scope credit. If an independent exact first-site receipt later proves certificate binding on any of these, Review must amend scope before code work.

## RA-141.2 Other first failures and explicit dispositions

- **A3 periodic fixture `selector:189–195` (7):** A3 `FieldTransportAtlas::make` reports `CycleTransportMismatch` before a usable phase-front product. Source has at least two distinct sites producing this code (local ordered cycle and boundary-cycle corrected lift); TB29's emitted reason has no cycle kind/region/step locus. **Cannot attribute fixture debt or product error from this code alone.** Separate A3 cycle-locus evidence/Review owns the distinction; the cases do not enter M1.
- **A3 `selector:442` (1):** `SingularityMismatch` on source edge `(2,3)` is independent A3 field/fixture authority, not a factory certificate conflict. Preserve hard-feature transition and singularity expectations; separate witness/atlas review must check fixture input and actual topology before assigning blame.
- **A5 `focused30:12` (1):** after the relabelled front is accepted, `produceA5` returns `OccurrenceHardRailTransportMismatch` at the A5 assertion (TQ:5525). This is an A5 relabelling/transport admissibility question, **not** M1. Require a source A5 mismatch-site and independently checked relabel equivalence before any behavior correction.
- **`cp3entry:1/2` (2):** test assertions respectively lack the expected periodic odd-gauge witness and the produced hard-rail midline certificate. These are missing witness/precondition observations, not evidence of a specific factory, A3, or A5 failure. Do not weaken them or call them production failures without a produced witness.
- **Other `reason-not-observed` (11):** `selector:174,201,204,211,219,227,230,242,247,250,405`. Keep distinct first-failure text/oracles (DCEL throw, missing terminal, wrong error codes or disposition, wrong topology). Do not relabel as M1 because of test topic. Prior RA-134.2 disposition remains tentative until individually verified.

## RA-141.3 Non-promotion and bounded successor

Stable **66 events / 17 categories / 49 recurrences**, produced witness debt **1**; CP2 **491/491 accepted**, CP3 R3 **403/497 rejected**, TB28 **462/497 candidate only**; the frozen 497 selector and accepted prefix are unchanged. TB29 is a 44-case diagnostic replay, **not** a green/full census. RP-01 OPEN, RP-02 UNREACHED, Gate C suspended. No new stable regression established.

Authorize only `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` (no source change, build, test or runtime). It must derive a clause-specific ownership/precedence contract for six observed R2 cases, retain all four adjacent untyped oracles as unresolved, spell out the A4/A5 responsibility and non-weakening table, and pre-register falsifiers **before** any subsequent CB: an invalid certificate must still reject; an A5-invalid pair must retain its specified error; existing A7/D3/D7 positive and negative paths must still discriminate; no change to other typed factory sites; no selector mutation. Halt if this ownership cannot be specified without guessing from the six log messages. Following Definition, separate independent DEFN review is mandatory before any CB; later A3/A5/witness work gets separate authority. RA-139.5 corrected crash-safe 497-case census harness remains owed and may not be satisfied by this 44-case tool.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Existing accepted focused30/focused12/selector449 immutable hashes retained; no selector changed. TB29 and TB28 inventory hashes independently recomputed as above. |
| Decisive claims independently re-derived | ZIP, 92 files, 44 exact log hashes, 44 RUN/verdict/identity mappings, 35 earlier RED mappings, 6/6/1 + 7/1 + 1 + 13 disjoint partition, source branch-check sites. |
| Non-vacuity checked | A7 negatives source-inspected at TQ:4123–4422 with original A6 independent guard, positive produced checks and site assertions; no dynamic mutation testing performed in this review. |
| Prior obligations discharged/carried | RA-140.4 M1 partition discharged to six exact observed clauses; A3 189–195 and 442, A5 focused30:12, cp3entry:1/2, 13 insufficiently typed and RA-139.5 census-harness debt carried to their separate owners. |
| Stable accounting | 66/17/49; debt 1; CP2 491/491 accepted; R3 403/497 rejected; TB28 462/497 candidate; RP-01 open, RP-02 unreached. |
| New candidates/obligations recorded | Seven typed non-M1 factory, A3/A5 and untyped adjudications; tracker update required. |
| ORIENTATION currency line | Update required before formal closeout. |
| ORIENTATION §3 / §4 / §7 / §8 | Update required; §4 no witness promotion, §8 no new pattern. |
| CHANGELOG | Update required. |
| ROADMAP | No checkpoint status movement; unchanged for substantive reason. |
| Selector manifest | Unchanged; no selector added or accepted. |
| LESSONS | Existing evidence/diagnostic/precedence lessons apply; no new lesson. |
| Consolidation under CLEAN_UP_POLICY | Folded consumed TB29 artifact-only plan into `M6_Consolidated_Record.md` with its exact filename/verdict, complete verbatim text and provenance resolver; retained authoritative TB29 report, RA-141 Review and next DEFN-M1 plan. |
| Successor frozen | `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` with falsifiers here and in next Definition plan. |
| Turn boundary held | Static independent Review only; no Directional binary, configure, compile, relink, benchmark, code/test/selector mutation. |
| review_check.py boundary | Pending authoritative Git-history check; synthetic snapshot history is not an authentic historical baseline. |
| `STATUS` lifecycle maintained | Entry beacon IN_PROGRESS; final beacon required after remote evidence/doc synchronization. |
| Pushed to origin, branch in sync | Pending remote patch application and head confirmation; no push claimed. |
