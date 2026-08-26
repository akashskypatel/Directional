# M3 CP4c — Consolidated Historical Record

**Purpose.** One durable record for the whole **CP4c family** — the CP4c parent turns and the CP4c-0 and
CP4c-1 sub-checkpoints. It consolidates twenty-four per-turn execution documents and review briefs that
were retired on 2026-08-26 under explicit user authorization, preserving **every** evidence identifier
they carried.

**Status:** CP4c-0 and CP4c-1 are **OPEN**. This is therefore a *historical* record, **not** a closure
record. No checkpoint is closed by this document, and none may be.

**What this document does not replace.** These remain live and normative:

| Retained document | Why |
|---|---|
| `Architecture_M3_CP4c0_DEFN_Charter.md` | the CP4c-0 charter (D0–D5) |
| `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` | **normative** for CP4c-0; carries Amendments 1–7 |
| `Architecture_M3_CP4c_TB_R1_Independent_Review.md` | the CP4c split rationale; budget abolition |
| `Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md` | Amendments 1–5; measures E0–E10 |
| `Architecture_M3_CP4c0_TB_R2_Review_Plan_Independent_Review.md` | Amendment 6; measures F0–F8 |
| `Architecture_M3_CP4c0_TB_R3_Review_Plan_Independent_Review.md` | Amendment 7; measures G0–G8 |
| `Architecture_M3_CP4c0_TB_R4_Review_Plan_Independent_Review.md` | measures H0–H7 that prescribed CB5/TB-R5 |
| `Architecture_M3_CP4c0_TB_R5_Artifact_Only_Test_Benchmark_Report.md` | current immutable TB-R5 evidence |
| `Architecture_M3_CP4c0_TB_R5_Review_Plan.md` | independent review brief |
| `Architecture_M3_CP4c0_TB_R5_Review_Plan_Independent_Review.md` | completed independent review record; J0–J7 authority |
| `Architecture_M3_CP4c*_Required_Green_Selector.txt`, `..._Non_Gating_Diagnostic_Selector.txt` | selector authority |

**Retired-provenance convention.** A citation elsewhere naming any document in §5's retirement list
refers to material **inlined here**. It means *retired provenance*, never lost authority.

---

## 1. Why CP4c exists, and how it was split

`DESIGN.md` §4.5 requires the inflow/outflow interval pairing to be **resolved**, with barycentric
positions propagating in arbitrary precision. It was half-implemented: the pairing existed, the
resolution did not.

**CP4c was split on 2026-08-25** by `Architecture_M3_CP4c_TB_R1_Independent_Review.md` after TB-R1
returned VALID RED 316/322. The finding that forced the split: CP4c's two committed witnesses are
**closed surfaces** (torus χ = 0 genus 1; mechanical χ = 2), while every witness that had ever validated
A2b is a **bounded disc** (χ = 1). Two of the three failure families were therefore **scope gaps in
already-accepted authority**, not CP4c defects.

| Checkpoint | Domain | Gate |
|---|---|---|
| **CP4c-0** | resolved interval pairing with propagated barycentric positions | **338** = 316 + 12 + 10 |
| **CP4c-1** | diagnosability, witness observability, event non-vacuity | **318** = 316 + C4 + C5 |
| **CP4c-2** | closed / higher-genus region authority in A2b | 321 (needs `-DEFN`) |
| **CP4c-3** | closed-surface missing field-transport adjacency in A1 | 322 (needs `-DEFN`) |

The same review **abolished the attempt budget, the diagnostic cap, and the `DG` turn type**, on the
finding that `DG` executed a strict subset of `TB`'s runtime surface and so was not a different
measurement. The workflow became `CB → TB → (red) → REVIEW + PLAN → CB`.

### The measured diagnosis

The TB-R3 census that justified CP4c-0's existence:

| Witness | frames | pairings | `(in × out)` distribution | ambiguous | % |
|---|---:|---:|---|---:|---:|
| two-ring skew disc | 15 | 60 | `1×2:30, 2×1:30` | 30 | **50 %** |
| four-triangle fan | 4 | 16 | `1×1:8, 1×2:4, 2×1:4` | 4 | **25 %** |
| torus | 144 | 576 | `1×2:288, 2×1:288` | 288 | **50 %** |
| prescribed sphere | 192 | 768 | `1×2:384, 2×1:384` | 384 | **50 %** |

Exactly 50 % on every non-degenerate witness — the arithmetic signature of `dbary = {−u−v, u, v}`
summing identically to zero, so a face is either `2×1` (resolvable) or `1×2` (ambiguous), with no third
case. **Both accepted witnesses carry non-zero ambiguity: the defect was latent in accepted authority
and never witness-specific.**

Site pin (prescribed sphere): failure at `field_aligned_outgoing_carrier` after one completed segment,
face `1-2-5`, incoming carrier `1-2`, outgoing carriers `{1-5, 2-5}`, multiplicity 2. The two carriers
share vertex 5 — the geometry of the tie case.

**The gap was two missing data:** the entry position on trace segments, and the barycentric direction,
which A1 computed and then discarded.

---

## 2. CP4c parent turns — evidence

| Turn | Semantic source | Run / job | Package | Result |
|---|---|---|---|---|
| **CB1** — A2b production wiring (W0–W5) | `428e0ecb6f769b501c99405ae2a90c24d5401cca` (control `a74217ac0cd258ef7acd1c3d1cc8185b0d41767e`) | `32770533316 / 97569642420` | `9531769503`; logs `9536072497` / `4c9545b9ccce2c80c61e644fc4fa6f21c58fc562192231cd6ecc4e617b1853d7`, `9536073130` / `0c4098cca5a9a7d2455eaa48a55c3142f02285604f32f82ca9a7852b9f032881` | BUILD GREEN |
| **DG1** — artifact-only diagnostic (the last diagnostic turn this project ran) | `428e0ecb6f769b501c99405ae2a90c24d5401cca` | `32776212123 / 97587757347` | `9536499549`, ZIP `4c64c0c3ea872dbf889c4de398ed40f9e0193fce534ee6117348e3b7a5514660`; source archive `33e546764b3b3017fbb043cfd91a4366a3ae27244861ade457743fcf10cf49ac` | completed |
| **CB2** — production witnesses (W7–W9) | `a5edb1a31c315d51df216f3bb51470989ff64e33` | `32784809188 / 97614400563`, `32784892656 / 97614667050`, `32785147649 / 97615440289` | `9541087171`, `9541087678` | BUILD GREEN |
| **TB-R1** | `a5edb1a31c315d51df216f3bb51470989ff64e33` | `32791027809 / 97632461750` | `9541369624`, ZIP `bb636eac863475ce41c336713ce7344c11d4a4ed6cd85a6b04634d083a03a778`; source archive `03e7c09d45715de96f1c58ec6cf21b32ca1b542078cfe196ea359c98dea8de66` | **VALID RED 316/322** |

CB1's wiring regressed nothing: the accepted 316 were green in the same immutable run.

---

## 3. CP4c-0 — the turn sequence

**Frozen selector authority, unchanged since CB2 and re-verified at every subsequent turn:**

- full **338**: `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`
- accepted first-**316**: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- first-**328**: `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`

| Turn | Semantic source | Package (ZIP SHA-256) | Run / job | Result |
|---|---|---|---|---|
| **DEFN** | — | — | — | Frozen definitions; D0–D5 answered |
| **CB1** | `e784e44ce86e458b250b04689288f5f365ca507b` | `9577900736` (`b9c597584177f31fd2d923b622a4b20fbb243c7bd007b37cced8ff128e349f31`) | `32886067534 / 97927044884` | BUILD GREEN; selector frozen at 328 |
| **TB** | `e784e44ce86e458b250b04689288f5f365ca507b` | `9577900736` | `32891161394 / 97943220460`; result `9579600371` / `fe472587aba74c2face26a2f65c0706439232bec2e5cc594d81711a26773b399`; log `9579600958` / `7ddfe4c8e48b1b618c7a60ad6cf900a767ff954309a1c3cc52a8896306d98039` | **328/328 PASS; Q8 RED** — sphere `BranchContinuationDegenerateEntry`, edge `6-8` |
| **CB2** | `390e65b373063c667e3c3f5e78b74ed9d859093b` (control `bd4ddf26296c72f3796d6d3f5d1a26c244620a1e`) | `9586196535` (`9f74856149909bc1fbcaffe638fd64b4719cddcb8ed8d92972dd52289362003f`); log `9586197038` / `7c3e56dbdea97b318bbfe10f11c48679293838fcf1f6f94cd66793302f986e2b` | `32909482352 / 98031548435` | BUILD GREEN; selector re-frozen at **338**; manifest 27/27 |
| **TB-R2** | `390e65b373063c667e3c3f5e78b74ed9d859093b` | `9586196535` | `32914546494 / 98015432540` (control `26c55d13b7449953f27a4e8bd36e3c5b474f00d9`); result `9587747391` / `89d72a42b07bb879f2ba35b18b3771359d522e3c0f444e33e79ce0214d8fc5a3`; log `9587747654` / `2b43c3bda84edffe7ea23cd9763fa3c96858285b785624102f202d4e72479dab` | **RED at ordinal 329** — `std::uint8_t` branch serialization; Q8 not run. Retry 0 `32914435964 / 98015089869` orchestration-only |
| **CB3** | `b135e219ee9269a73eaee32992d80c3921318011` (control `950d158c333622f59ed9d26c53b2028706954275`) | `9589508430` (`7bb4bd1a40af68ffd1e2ce06001490d61504e6ed0300505646c0abce97693015`); log `9589508670` / `2c29c76b2b0ac9d700ca9f68ec671969d85065b210ec2eb59bb11ddd9293c92f`; source archive `1bcc6420190be927e5fca962ba5280bb2e340e892ce81a40fcb5a17a3d432681` | `32919909928 / 98031291970`, `98031548435` | BUILD GREEN; manifest 27/27 |
| **TB-R3** | `b135e219ee9269a73eaee32992d80c3921318011` | `9589508430` | `32921851098 / 98036868098` (control `faf84aff4e7a64a3771e863199b82bd00425c318`); result `9590143527` / `af4f5b28e509623af1fc93d55c4b766479362915e8517c741db4ae718d216604`; log `9590143871` / `ec9c29b7534053b023c8b6ba60fafb4c9d791e719caea3c37c3e2f742b08f5b7` | **336/338**; reds at ordinals 333, 334 (both test-side); F3 2/2; Q8 not run |
| **CB4** | `de291a17d5e9bfb6f54918660320ecfa1d521be4` (initial `76c38686f6f79617477dd39b5f70e330143ed47f`; control `baf7ed2ea9381ad47b3ae807d00d61bee0f0dcfe`) | `9591540182` (`8a93b553df337bc8ad952e6a5b348a3eaac8b2304b50c1402f5184a8ce4c561f`); source archive `6077902a83b88d1ef839ab6d2bc285050f0c059511a71c9125b0324383d69a32` | `32926004147 / 98048909565` | BUILD GREEN; test-side corrections only |
| **TB-R4** | `de291a17d5e9bfb6f54918660320ecfa1d521be4` | `9591540182` | `32928381384 / 98055727654` (control `bb21207f288c631b1d4149b56b37e78080edade7`); result `9592385698` / `6ffe56ef5a86bf44dfd2ea4e2f44514d71b6037cc5c34067aeda571a70260643`; log `9592386266` / `669e51f2d0c30573c751c43a4d49b737f8a4ddeba8be2236f9782c995f6ac3cb` | **338/338 PASS**, F3 2/2, G5 PASS; **Q8 creditable, RED at criterion 2** |
| **CB5** | `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e` (control `fc4892c89bc9bb4a0510bdd47187f4f0d3482c8e`) | `9601160869` (`143cab907b4086a3f3bfc6f29dfdbb103919c9429698b0cce0757ae16f36cefb`); source archive `f7f2e59cf9866beb8e784aeaefc2320cc2306a49ab1813133b7e343d5f3e35e3`; log `9601161248` / `7fab20369e529ea674a8c1fc9561753d935bce2d50297750d9007941fe788b91` | `32953176800 / 98129036272` | **BUILD GREEN**; H1–H3 diagnostic-only; H4 source-audited; H5 no production change; `runtimeExecution=false` |
| **TB-R5** | `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e` | package `9601160869`; result `9616160533` (`1ecfd85f06b40466f0e8193d1603950cd93b120723568024a1b50595e9902ad8`); log `9616161522` (`7cb10caee2f1e861368da3098e320f10bee3b13d51439bc868e1e3c60aa14b0e`) | `32994846466 / 98261255799` (control `3f9864fddef696dc7d95084fdd41b680a78f5b37`) | **VALID SEMANTIC RED**; 338/338, F3 2/2, G5 PASS; H1 `390/4224` `H-B_OR_OTHER_SPARSE_REVIEW_REQUIRED`; Q8 creditable RED criterion 2 |

### TB-R5 retained result and H1 disposition

TB-R5 executed **342 fresh processes** on the immutable CB5 package: 338 gate identities, F3's two required supplementals, G5 and H1. The gate is 338/338 with `first_red_ordinal=0`; F3 is 2/2; package manifest remains 27/27 and all pre/post byte inventories match. G5 still reaches `BranchTransportFlowDisagreement` at sphere edge `6-8` (`6-8-9` branch 3 → `6-8-97` branch 1, `signedLift=2`) after a seven-step published trace history.

H1 checked **4224** A1-only cross-face branch pairs and found **390 (9.23295%)** disagreements: two-ring `4/160`, fan `2/32`, sphere `144/2304`, torus `240/1728`. Lift 0 dominates (`4/4`, `2/2`, `102/144`, `184/240` respectively), while sphere/torus also contain symmetric ±1/±2/±3 violations. This **excludes H-A** (odd-lift-only) and **H-C** (zero A1 violations), and does not match the review's ~50% systematic-index branch. It does **not** prove H-B: the manually prescribed fan also has lift-0 disagreements although computed matching aliasing is not live there. Exact next is independent TB-R5 review/planning to localize the sparse pattern and freeze one bounded successor. Stable accounting remains `42 / 14 / 28`; debt 5; packages 44.

During a GitHub-hosted Actions outage, self-hosted runs `32993852779` and `32994482392` failed before runtime at immutable control-payload hash verification because checkout line-ending conversion changed the staged shell bytes. They are orchestration-only and carry no semantic result. Hosted run `32994846466` is the sole TB-R5 authority.

### The corrective arc, in one paragraph each

- **TB → review (E0–E10, Amendments 1–5).** Root cause: A1 decided the **sign of a barycentric
  direction coordinate** with a `double` tolerance in three places and published those verdicts as
  topological ownership, while A2a's new rule re-decided the same sign exactly on A1's own datum. T6 and
  Q8 were both correct and unamended; the states reaching T6 stopped being produced.
- **TB-R2 → review (F0–F8, Amendment 6).** Ordinal 329 was **solely** a `std::uint8_t` stream-insertion
  defect at two call sites, and it exposed a contract gap: "observable" had constrained the *value* and
  not the *mechanism*. A second defect of the same shape (≈15 surviving trace-seed back-fills) was found.
  Both were **class defects certified by instance falsifiers**.
- **TB-R3 → review (G0–G8, Amendment 7).** Both reds test-side. Ordinal 333 built a **single-triangle**
  mesh, which `DCEL::check_consistency`'s `checkPureBoundary` always rejects. Ordinal 334 iterated a
  numeric `FieldBranch` across faces — but branch numbering is **gauged per face**, so the same label is
  a different physical direction on each. Production was correct at both sites.
- **TB-R4 → review (H0–H7).** Gate green, Q8 creditable and **red at criterion 2**. G5 published the
  sphere's rejection for the first time: `BranchTransportFlowDisagreement`, edge `6-8`, source face
  `6-8-9` branch `3`, related face `6-8-97` branch `1`. **Both faces classify the shared edge as
  Outflow** (`−1.0035…`, `−0.5770…`), which is geometrically impossible; the physically correct target
  branch is `3`, two quarter-turns from the published `1`. Mechanism undetermined; a census is frozen to
  decide it.

### CB5 retained Code + Build report and TB-R5 plan

**Build evidence.** CB5 semantic source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e` contains exactly the diagnostic H-series implementation authorized by the TB-R4 independent review: H1 adds the non-gating A1-only four-witness flow-agreement census; H2 publishes the exact `signedLift` in `BranchTransportFlowDisagreement`; H3 carries ordered trace-step history; the DEFN required-loci row was updated accordingly. No production branch choice, transport equation, matching computation, tolerance, fixture, selector, or acceptance expectation changed. The frozen selector hashes remain 338 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`, first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`, first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`; H1 is not in that selector.

Authoritative compile-only run/job `32953176800 / 98129036272` checked out exact source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e`, compiled/linked all eight standard targets, recorded preflight/build exit `0`, kept every packaged source-status file empty, self-verified all 27 manifest entries, and explicitly recorded `runtimeExecution=false`. Result artifact `9601160869` has ZIP SHA-256 `143cab907b4086a3f3bfc6f29dfdbb103919c9429698b0cce0757ae16f36cefb` and source archive SHA-256 `f7f2e59cf9866beb8e784aeaefc2320cc2306a49ab1813133b7e343d5f3e35e3`; compile log artifact `9601161248` has ZIP SHA-256 `7fab20369e529ea674a8c1fc9561753d935bce2d50297750d9007941fe788b91`. A first caller attempt `32953028850` had no jobs because its static reusable-workflow permission ceiling was insufficient; this was corrected before the authoritative run and produced no semantic/build evidence.

**H4 matching provenance.** Two-ring computes matching through `finalize_cross_field_result(..., true)` → `principal_matching` → `populate_cross_field_edge_transitions`. Sphere and torus load raw vector fixtures but compute matching during `finalize_surface_cell_raw_cross_field` → `principal_matching(rawField, false)` → `populate_cross_field_edge_transitions`. The four-triangle fan instead constructs zero matching/transitions and manually changes one singular-cycle edge. Computed transition records copy `CartesianField::matching(edge)`. H-B matching aliasing is therefore a live hypothesis for two-ring/sphere/torus, not the fan's manually prescribed matching.

**TB-R5 / H7 — executable artifact-only plan.** Consume only package `9601160869` / `143cab907b4086a3f3bfc6f29dfdbb103919c9429698b0cce0757ae16f36cefb`. Verify outer digest, internal `SHA256SUMS`, exact source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e`, build/preflight exit 0, empty source-status files, and `runtimeExecution=false`. From the packaged source archive verify the 338 selector and all three frozen hashes above. Run every selector identity in exact order, exactly one selected identity per fresh process, dispatched statically from `cmake/DirectionalTests.cmake` to the packaged authority-kernel / producer / completion / validation executable; record ordinal, identity, target, exit, elapsed time, and full output. F6 requires continuing through all 338 after any red while preserving `first_red_ordinal` and withholding credit after the first red. Then run F3's two producer supplementals (`NetworkDiagnosticsContainNoControlCharactersForAnyCode`, `TracingPathNeverPublishesSeedIdentityAsFailureLocus`) in fresh processes. Then run G5 (`PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating`) and H1 (`CrossFaceFlowAgreementCensusIsPublishedNonGating`) separately, report them, and give them no gate credit.

Q8 is creditable only when package integrity is exact, the 338 gate is **338/338**, and F3 is **2/2**. It is **expected to remain RED at criterion 2**, because H5 forbade the production fix. TB-R5's success criterion is not Q8 closure; it is a complete authoritative H1 census. Classify that census exactly as frozen: odd-lift-only violations ⇒ H-A sign/direction convention; sparse singularity-localized/non-parity violations ⇒ H-B aliasing; ~50%/uniform ⇒ unenumerated systematic index error; zero violations ⇒ H-C/A2a carried branch. Preserve every per-witness pair count, violation rate, edge/faces/branches, published lift, and exact `d[opp]` locus. Use `first_red_ordinal` consistently in postflight. Do not rebuild, repair, mutate fixtures/selectors/package bytes, or rerun TB-R4.

**Accounting after CB5:** stable regressions remain **42 / 14 / 28**, produced-witness debt **5**, M3 packages **44**. Latest accepted runtime remains CP4ab 316/316. Exact next: `M3-CP4c-0-TB-R5`; CP4c-1/2/3 remain blocked.

### CB6 retained Code + Build report and TB-R6 plan

**Build evidence.** CB6 semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6` implements the independent TB-R5 review's diagnostic-only J0–J7 series. J1 extends H1 with declared `matching`, `rawGaugeSource`, `rawGaugeTarget`, published `signedLift`, singular incidence, distinct-pair counts, and matching histograms; J2 explicitly classifies the fan as an excluded fixture artifact; J3 adds the tracing-independent matching-versus-geometry census; J4 records matching provenance; J5 adds `.gitattributes` payload line-ending protection; J6 restores the brief/review naming convention; J7 creates the frozen TB-R6 plan. J0 forbids and CB6 makes **no production semantic change**. The 338/316/328 selector authorities remain unchanged.

Authoritative compile-only run/job `33002848081 / 98288918300` checked out exact semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`, configured Release/static/PRE_TEST out of tree, and compiled/linked the eight standard targets. Preflight and build exit `0`; all packaged source-status snapshots are empty; `runtimeExecution=false`; no Directional test or benchmark executed. Result/package artifact `9619352525` has GitHub ZIP SHA-256 `b45306c3c5b3b9ff094131be8073aed5c6180533fdbe0b04f220ca929b4dd672` and packaged source archive SHA-256 `308e02580033b5a319e08d7916afc921693d2b15f645813c2cdbaed336320093`; compile-log artifact `9619353059` has ZIP SHA-256 `1b2a0ffc9889305ca6a2efa847a2442c941583df01ad94c4c12226aea47be4c4`.

**TB-R6 / J7 authority.** `Architecture_M3_CP4c0_TB_R6_Artifact_Only_Test_Benchmark_Plan.md` consumes only package `9619352525`. It re-proves immutable package/source/selector/fixture identity; runs the unchanged 338 gate in exact order, F3, G5, decomposed H1, and J3; conditionally runs Q8 only after exact package integrity + 338/338 + F3 2/2. H1/J3 remain uncredited diagnostics. The fan is excluded from legitimate population totals. The cycle's deliverable is the J1/J3 owner decision table; **Q8 is expected to remain RED at criterion 2** because CB6 contains no production fix.

**Accounting after CB6:** stable regressions remain **42 / 14 / 28**, produced-witness debt **5**, M3 packages **45**. Latest accepted runtime remains CP4ab 316/316. Exact next: `M3-CP4c-0-TB-R6`; CP4c-1/2/3 remain blocked.

### TB-R6 retained artifact-only Test + Benchmark report and review handoff

**Runtime evidence.** TB-R6 authoritative control/run/job `a9ae307590b0cc23080452c4a5013674efc48fc2 / 33006282429 / 98300813772` consumed only CB6 package `9619352525` at semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`. Result artifact `9620769314` / `fe6a73175399b764f7cbb3ea2963a8deb40d6d0b5afcc3e9a603102ee4936684`; diagnostic `9620770049` / `ce87da5a919e31f7e36a8d904dfaad7c7d9c92b9bebf36a494de096e7cb691cb`. Frozen gate 338/338, accepted prefix 316/316, first-328 328/328, F3 2/2; G5/H1/J3 PASS non-gating. Q8 is creditable and RED at criterion 2. Postflight PASS; all mutation/build flags false.

**J1/H1 + J3 decision evidence.** H1 reproduces the reviewed legitimate population exactly: **388 directed / 194 distinct**, excluding fan 2/1. Legitimate decomposition: matching-nonzero 48/24, matching-zero unequal-gauge 86/43, matching-zero equal-gauge lift-zero 254/127. J3 independently checks **524 legitimate interior transitions and finds 524/524 agreement with geometry**; the only J3 mismatch is the excluded fan edge `1-4`. The live Q8 edge `6-8` is `matching=0`, raw gauges `1→3`, `signedLift=2`, so the frozen table points at **A1 gauge composition in `build_branch_transports`** rather than matching aliasing. The equal-gauge 254/127 residual separately points at **A1 flow classification / direction publication in `build_boundary_pairing`** and remains for independent adjudication.

A first control `33006048971 / 98300014224` is resolved orchestration-only: Python ZIP extraction lost executable modes and the first binary launch failed before Directional runtime. The semantic retry used ordinary `unzip` without package repair.

**Accounting after TB-R6:** stable regressions **42 / 14 / 28**, debt **5**, packages **45**, latest accepted CP4ab 316/316. Exact next is independent `M3-CP4c-0-TB-R6-REVIEW-PLAN` under `Architecture_M3_CP4c0_TB_R6_Review_Plan.md`; CP4c-1/2/3 remain blocked.

---

## 4. CP4c-1 — evidence (OPEN, blocked on CP4c-0)

| Turn | Semantic source | Run / job | Package | Result |
|---|---|---|---|---|
| **CB** | `51f510861a02377d1f45607908191f2fdebdcd33` | `32867889140`; jobs `97867532883`, `97867597370`, `97867694421`, `97868351487` — all PASS | `9570940997` (`23876c55e51b94ca3a1e5bcfb727a4c0cebce3294fcd2fbda21336b57ae1de16`) | BUILD GREEN |
| **TB / TB-R2** | `51f510861a02377d1f45607908191f2fdebdcd33` | `32872112507 / 97881418987`; result `9572545977` | `9570940997` | **VALID RED 316/318** |

Selectors: required 318 `2f2c24acab0e891273c170c82cdc31b6afa3ae4d43e93c95dbdf6d90a88f45bc`; accepted 316-prefix
`601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; non-gating 5
`9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`.

C4/C5 remain the only required blockers and **stay gating** — demotion to non-gating was considered and
rejected. They cannot pass until CP4c-0 lands. Next turn is `M3-CP4c-1-CB3` under measures Z0–Z5, whose
root-cause record (the Cartesian-product defect) is inlined in
`Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md`.

---

## 5. Documents retired into this record — 2026-08-26

Retired under explicit user authorization ("consolidate CP4c docs"). Every evidence identifier each
carried is inlined above. **CP4c parent:** `..._CB1_Global_Topology_Plan_Code_Build_Report`,
`..._CB2_Production_Witness_Code_Build_Report`, `..._DG1_Artifact_Only_Diagnostic_Plan`,
`..._DG1_Artifact_Only_Diagnostic_Execution_Report`,
`..._DG1_Artifact_Only_Diagnostic_Independent_Review_Record`,
`..._TB_R1_Artifact_Only_Test_Benchmark_Report`, `..._Code_Build_Plan` (already marked SUPERSEDED).
**CP4c-0:** `..._Artifact_Only_Test_Benchmark_Report`, `..._CB2_Code_Build_Report`,
`..._CB2_Artifact_Only_Test_Benchmark_Plan`, `..._CB2_Artifact_Only_Test_Benchmark_Report`,
`..._CB3_Code_Build_Report`, `..._CB3_Artifact_Only_Test_Benchmark_Plan`, `..._CB4_Code_Build_Report`,
`..._CB4_Artifact_Only_Test_Benchmark_Plan`, and the four superseded review briefs `..._TB_Review_Plan`,
`..._TB_R3_Review_Plan`, `..._TB_R4_Review_Plan`. **CP4c-1:** `..._Code_Build_Report`,
`..._Artifact_Only_Test_Benchmark_Plan`, `..._Artifact_Only_Test_Benchmark_Report`,
`..._TB_Review_Plan`, `..._TB_R2_Review_Plan`.

Each review brief was **answered in full** by the independent review that succeeded it; those reviews
restate every question in their `R`-sections and are retained.

---

## 6. Standing accounting

Stable regression accounting has held at **42 events / 14 categories / 28 recurrences** across the
entire CP4c family, because **CP4c has never been accepted** and the accepted 316 prefix has stayed
green in every run that executed it. Produced-witness debt remains **5**. Latest accepted runtime
authority remains **CP4ab 316/316**, source/package
`157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`.
