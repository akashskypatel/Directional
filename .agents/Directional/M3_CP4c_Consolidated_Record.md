# M3 CP4c — Consolidated Historical Record

**Purpose.** One durable record for the whole **CP4c family** — the CP4c parent turns and the CP4c-0 and
CP4c-1 sub-checkpoints. It consolidates twenty-four per-turn execution documents and review briefs that
were retired on 2026-08-26 under explicit user authorization, preserving **every** evidence identifier
they carried.

**Status:** CP4c-0 is **CLOSED / ACCEPTED** and CP4c-1 remains **OPEN**. This remains primarily a historical record; CP4c-0 closure authority is the retained `Architecture_M3_CP4c0_TB_R9_Artifact_Only_Test_Benchmark_Report.md`, not this consolidated record.

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
| `Architecture_M3_CP4c0_TB_R9_Artifact_Only_Test_Benchmark_Report.md` | current CP4c-0 acceptance and immutable TB-R9 evidence |
| `Architecture_M3_CP4c0_TB_R5_Review_Plan.md` | independent review brief |
| `Architecture_M3_CP4c0_TB_R5_Review_Plan_Independent_Review.md` | completed independent review record; J0–J7 authority |
| `Architecture_M3_CP4c*_Required_Green_Selector.txt`, `..._Non_Gating_Diagnostic_Selector.txt` | selector authority |

**Retired-provenance convention.** A citation elsewhere naming any document in §5's retirement list
refers to material **inlined here**. It means *retired provenance*, never lost authority.

---

## 0. Current addendum — complete TB-R9 whole-gate re-proof closes CP4c-0

After CB-R10/TB-R10 and CB-R11/TB-R11 individually resolved the two non-stable test-side TB-R9 candidates, the user explicitly authorized a fresh compile and complete frozen TB-R9 re-proof. Semantic source `7bbc0480d9ab5954329b940992ef41a9223102ed` compiled all eight standard targets with GMP in run/job `33079499974 / 98542697746`; immutable package `9649395432` has ZIP SHA-256 `557207bf8f668884295258690e3bd31485cbd7709f0be47aa98daea0c53b3e2e`, build/preflight exit 0, and `runtimeExecution=false`. This advances the M3 package count to **51**.

Artifact-only TB-R9 re-proof run/job `33079817998 / 98543736213` preserved the exact 346-line selector SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` and returned **346/346 PASS**: first-316 **316/316**, first-328 **328/328**, Q8 criteria 1/4/5 PASS, zero timeouts, zero escaping C++ exceptions, zero orchestration errors, and immutable package postflight PASS. Result artifact `9649625534` / `6cd4e3c21dc46fd7e0d6df2209ee5a382531d768f50ae52d190302e05bec02af`; diagnostic artifact `9649626115` / `3ba381cd12ec1188bd9ae36020d35bdaa458271ea2c7b1163aac31a9a474d7f9`.

Disposition: the original 344/346 TB-R9 execution remains valid historical RED evidence, but both corrected identities now pass in their frozen whole-gate context and no further RED was exposed. **CP4c-0 is CLOSED / ACCEPTED.** Stable accounting remains **42 / 14 / 28**, debt **5**. The skipped `M3-CP4c-0-TB-R9-REVIEW-PLAN` remains skipped/not completed historically. `M3-CP4c-0b-CB1` is next eligible but not automatically authorized.

## 0. Current addendum — CB-R11 / focused TB-R11 CAND-02 fixture correction

On 2026-08-27 the user authorized `CB-R11 → TB-R11` to diagnose and correct the remaining `M3-CP4c0-TB-R9-CAND-02`. Independent diagnosis confirmed production was correct: incoming edge `(0,1)` at parameter `1/2` gives barycentrics `[1/2,1/2,0]`; the old direction `{-1,2,-1}` made coordinate 2 an outflow minimizer with exact exit time zero, so typed `BranchContinuationDegenerateEntry` was mandatory.

CB-R11 changed only `tests/FieldAlignedCurveNetworkTests.cpp`. Direction `{-2,1,1}` makes coordinate 0 the sole outflow and gives exact exit time `1/4`; the positive control now asserts `EdgeExit`, outgoing `(1,2)`, and exact exit point `boundary_point(outgoing,1,4)`. The oversized exact-magnitude rejection is untouched. Semantic source `267272d22f7de67ce7d8e368a53cc78a37ca3e8f` compiled all eight standard targets in run/job `33077493539 / 98535503386`; GMP package `9648550565` has ZIP SHA-256 `1f0275e96fa75b7fc6fb447eaffb79b414c94230823da7897a4f2d91df33615c`; build/preflight exit 0 and `runtimeExecution=false`.

Focused artifact-only TB-R11 run/job `33077761701 / 98536455697` consumed only that package. `ResolvedBranchCorrection.ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance` selected exactly once and passed (`exit=0`, failures/errors 0, 39 ms harness elapsed); package preflight/postflight hashes matched. Result artifact `9648618375` / `469cab3ee5a541a5faa29fcdac2a6ff213ca202c8ff38522e131b0a9a4ba6113`; log artifact `9648618836` / `c15831693911134a4ab3eba6fa8060af8b95e85eac679d5374c632fcecdc908d`.

Disposition: `CAND-02` is **RESOLVED / NON-STABLE / TEST-SIDE FIXTURE-PRECONDITION**. Together with R10, both TB-R9 RED identities are individually resolved. Stable accounting remains **42 / 14 / 28**, debt **5**, M3 package count **50**. At the end of focused TB-R11, CP4c-0 still remained OPEN because focused corrective runs alone did not constitute whole-gate acceptance. The later complete TB-R9 re-proof recorded above supplied that acceptance evidence.

## 0. Current addendum — CB-R10 / focused TB-R10 GMP-portability correction

On 2026-08-27 the user explicitly **skipped, without completing**, `M3-CP4c-0-TB-R9-REVIEW-PLAN` and authorized a bounded `CB-R10 → TB-R10` sequence for the GMP-related `M3-CP4c0-TB-R9-CAND-01` only. This is an operator override of the normal red→review cadence; it does not retroactively create an independent review and it does not adjudicate `CAND-02`.

CB-R10 changed only `tests/FieldAlignedCurveNetworkTests.cpp`: the lossy-round-trip regression now constructs an exact `1/7` witness and performs its deliberate lossy conversion explicitly in test code, rather than relying on legacy `to_double(18)` decimal truncation that GMP does not implement. Semantic source `30ef2792e2915e0016dfd11f5fa2b3727e5503c0` compiled all eight standard targets in run/job `33067140968 / 98499967674`; GMP package `9644214591` has ZIP SHA-256 `b9e7729fb557eddc203e38a1c11564bab3ad180982e10740d4374fe06748a390`, with build/preflight exit 0 and `runtimeExecution=false`.

Focused artifact-only TB-R10 run/job `33067370314 / 98500728780` consumed only that package. `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` selected exactly once and passed with no timeout/failure/error; package preflight/postflight immutability matched. Result artifact `9644274456` has SHA-256 `4d80bc1ca8e9d0f624e709eb7c467e5b1c2c880d6a1619f1f8ced95151305693`; log artifact `9644274922` has SHA-256 `2c8922ccf03e356db0e78fbe07a4a22bb99019009e4e40669f58bba16fcdd122`.

Disposition at the end of TB-R10: `CAND-01` was resolved/non-stable/test-side GMP portability while `CAND-02` still remained active. CB-R11/TB-R11 subsequently resolved CAND-02, and the complete TB-R9 re-proof recorded above later closed CP4c-0. Stable accounting remained unchanged.

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

**Accounting after TB-R6:** stable regressions **42 / 14 / 28**, debt **5**, packages **45**, latest accepted CP4ab 316/316. The subsequent independent review identifies the disagreements as a near-tangency discretization phenomenon and freezes diagnostic-only K0–K7 for CB7; CP4c-1/2/3 remain blocked.

### CB7 retained Code + Build report and TB-R7 plan

**Build evidence.** CB7 final semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c` implements only review-authorized K0–K7 diagnostics and contract/control-plane hygiene. K1 publishes exact per-face tangency ratios, lossless dyadic angle proxy serialization and opposite-coordinate ranks for both disagreement and agreement distributions; K2 publishes prescribed-sphere grazing continuation-cost evidence; K3 correctly relabels J3 as a principal-matching implementation cross-check and adds independent vertex-fan holonomy; K4 removes misleading owner labels; K5 records the piecewise-constant discretization assumption; K6 requires mode-preserving TB extraction; K7 freezes TB-R7 → `M3-CP4c-0-DEFN-2`. CB7 makes **no production semantic change** and does not edit the fixture, selector, tolerances, T6, or Q8.

A first compile-only attempt on source `6341b13c708f98208eece40dcccea5806a97b0c7` exposed one test-diagnostic API misuse in K3 (`DomainResult<SourceVertexId>` dereferenced instead of using `.value()`). The bounded one-line repair produced final semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c` without changing diagnostic meaning.

Authoritative compile-only run/job `33018117005 / 98341565781` checked out exact semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c`, configured Release/static/PRE_TEST out of tree, and compiled/linked the eight standard targets. Preflight and full build exit `0`; every packaged source-status snapshot is empty; `runtimeExecution=false`; no Directional runtime/test/benchmark/discovery/CLI/fuzzer/custom input executed. Result/package artifact `9625495708` has GitHub ZIP SHA-256 `dc07d4288b9a529ca71c06f96e0277b168d2e5a28c5a9eeba3fdf7341a33237a` and packaged source archive SHA-256 `6ecafbc5a5904568780e6518f39b9d4b1336c94e08a53f7fc0c31d8926e26344`; compile-log artifact `9625496280` has ZIP SHA-256 `e42240c280738fd70e8eddc09bc9899537cac53f477e3d3f88d26f6b4a0a978f`.

**TB-R7 / K7 authority.** `Architecture_M3_CP4c0_TB_R7_Artifact_Only_Test_Benchmark_Plan.md` consumes only package `9625495708`. It requires mode-preserving extraction and immutable package/source/selector verification, then runs the unchanged 338 gate, F3, G5, K1/H1, K2, J3/K3 holonomy, and conditional Q8. K1–K3 are non-gating diagnostics. **Q8 is expected to remain RED at criterion 2** because CB7 contains no production fix. After a valid TB-R7, the frozen successor is `M3-CP4c-0-DEFN-2`.

**Accounting after CB7:** stable regressions remain **42 / 14 / 28**, produced-witness debt **5**, M3 packages **46**. Latest accepted runtime remains CP4ab 316/316. Exact next: `M3-CP4c-0-TB-R7`; CP4c-1/2/3 remain blocked.


### TB-R7 retained artifact-only report and DEFN-2 disposition

**Authority.** Artifact-only TB-R7 control/run/job `3d1ef24d6bcccb7e4e821d713a21860bc0598bd0 / 33019554121 / 98346293968` consumed only CB7 package `9625495708` at semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c`. Result artifact `9626003625` / `61994abc1e67fc55bc1d48d38a521598b6b56e458972d948ebcae112fa27eaaa`; diagnostic log `9626004016` / `9f6307b90b93ba557af7643c5a2d4a021969708b2a77e74fc546ae4f263e441c`. K6 mode-preserving extraction passed without permission repair; all six executables remained `0755`; package/source/fixture/selector inventories were immutable.

**Gate/Q8.** Frozen gate 338/338, accepted 316/316, first-328 328/328, F3 2/2, 345 fresh processes, zero orchestration errors. G5 is unchanged. Q8 is creditable and RED at criterion 2; criterion 3 not evaluable; criterion 4 pass; criterion 5 carried unchanged.

**K1/J3/K3.** K1 reproduces the legitimate near-tangency separation: sphere 144/2304 disagreements with median min-ratio `0.021788`, max `0.200424`, agreeing median `0.915773`; two-ring and torus show the same rank-smallest grazing regime. J3 is explicitly only a principal-matching implementation cross-check and remains legitimate 524/524. Independent K3 holonomy covers 176/176 complete vertex fans with 0 mismatches. These satisfy the corrected definition-gap decision row.

**K2 limitation.** The continuation-cost proxy reaches grazing on 0/24 traces; every trace reports one traversed edge, no first-grazing step, and no consecutive grazing crossings. P3 is therefore not observed. This is retained as a diagnostic limitation/non-stable observation, not a product regression. The proxy provides no cost discrimination among the four frozen grazing models and selects none.

**Accounting after TB-R7:** stable regressions remain **42 / 14 / 28**, produced-witness debt **5**, M3 packages **46**. Latest accepted runtime remains CP4ab 316/316. Exact next: definition-only `M3-CP4c-0-DEFN-2`; CP4c-1/2/3 remain blocked.

---

### DEFN-2 — the `DESIGN.md` §4.5 grazing gap, closed

**Turn boundary.** Independent definition/review/planning only. No Directional runtime, build,
benchmark, or product/test/fixture/selector/build-configuration change. Committed fixtures and source
were read and arithmetic performed on their contents.

**Chosen model — grazing edge transit.** A carrier's relation to the face a trace is about to enter is a
three-way classification read from that face's published `direction` at the coordinate opposite the
carrier (`> 0` `Inflow`, `== 0` `Tangent`, `< 0` `Outflow`), never from carrier-set membership, which
cannot separate `Tangent` from `Outflow`. `Outflow` on both sides is grazing: the trace neither crosses
nor stops, but transits along the edge to the endpoint both faces drive the published parameter toward —
the common sign of `d[index of edge.second()]` in each face — and re-enters the existing T2/T3 vertex
dispatch. `BranchTransportFlowDisagreement` is retired from production emission (enum value 25 retained,
never reused); the ambiguous case becomes `BranchGrazingSlideDirectionAmbiguous`.

**Why, and why not the other three.** The rule is the **unique continuous extension of Amendment 3**:
at exact tangency the frozen rule already slides along the edge and selects the same endpoint by the
same expression, so a grazing terminus would be discontinuous across a measure-zero configuration — and
would additionally forfeit Q8 criterion 2, because the grazing edges lie in corridors along the field's
own separatrices. A refinement precondition would reject every non-degenerate witness the project owns,
two of them already accepted, and is aimed at mesh quality where the phenomenon is field-driven. A
general edge-following mode is unnecessary: the directions are constant per face, so the grazing
predicate and both parameter rates are constant along the whole edge and the transit completes in one
hop. **K2 contributed nothing** — it walks traces with the retired Cartesian carrier lookup, carries no
position, and stops on the first `1x2` face (`M3-CP4c0-DEFN2-CAND-01`, test-side, owned by measure L8).

**Evidence, re-derived from the committed fixtures alone.** Sphere **72** grazing configurations on
**72 distinct** edges (histogram `{1: 72}`), torus **120** of 864 `(edge, branch)` pairs; ratio median
`0.021788` / max `0.200424` and `0.074604` / `0.102869`, matching TB-R7's runtime K1 figures to six
decimal places by a route sharing no code with the product. **Slide-direction ambiguity: 0 of 192.** The
eight sphere singularities are exactly the corners of an inscribed cube, `(±1, ±1, ±1)/sqrt(3)`, with
**3** grazing edges each. The live locus `6-8` transits to **vertex 8, a singularity**, terminating by
**T3 `SingularityTermination`**.

**Contract impact.** A1 is untouched and `branch_topology_digest` does not move; the grazing relation is
derived on demand and never stored. T6 stays frozen and unreachable. No new `FieldAlignedNetworkEventKind`,
so CP3b's terminal-kind exhaustivity assumption is untouched. `FieldAlignedCandidateTraceSegment` gains
one optional `edgeTransitExit`. Because the current build already rejects grazing and TB-R7 re-proved the
accepted prefix at 316/316 with that rejection live, **no accepted trace crosses a grazing edge**, so no
accepted trace can change.

**Q8 is not amended.** Criterion 3 (`TraceIntersection`) is predicted unsatisfiable on the prescribed
sphere because a cube-corner separatrix network pairs singularities and never self-contacts; the
response is pre-committed and the question is re-homed to CP4c-1.

**Accounting after DEFN-2:** stable regressions remain **42 / 14 / 28**, produced-witness debt **5**, M3
packages **46**. Latest accepted runtime remains CP4ab 316/316. Exact next: **`M3-CP4c-0-CB8`**, Code +
Build only under measures **L0-L9**; CP4c-1/2/3 remain blocked.


### CB8 retained Code + Build report

**Build evidence.** CB8 implemented only frozen DEFN-2 measures **L0–L9** and compiled the exact pushed semantic source. Code + Build only; no Directional runtime, test, benchmark, generated discovery, CLI, fuzzer, or custom-input execution.

- semantic source: `19ba8e9c5e58f9c33c14b309841165d3f0401db5`
- compile caller install commit `dc36d0fff98936280da51bc02522954a1a33c204`; trigger commit `8abb7a37267ac20c6576160fd0984208af6914fa`
- authoritative compile run `33025705457`; preflight job `98366398970`; full package job `98367264215`
- immutable result/package artifact `9628445643`; package ZIP SHA-256 `869e06a3524ecdb7fd901e2583d5ba5c60309cce3085e2e1996a37ddd780bce6`
- packaged semantic-source archive SHA-256 `98e7db71647a54f41edfd93aea56ef7f50e014989bbc3c617edc179791380d5d`
- compile diagnostic artifact `9628446136` / `562bb275fccb61629a3a60bfd1f71c3cb8332a239674dab660ebcd1626f33d27`
- package metadata: `preflight-exit-code=0`, `build-exit-code=0`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, empty final source-status snapshots, recursive `SHA256SUMS` verified clean
- all eight standard targets compiled and linked; frozen selector **343** with SHA-256 `63ca177e8c0f22a83085cfb1028915b444db67bf2bb3da79555e4a3033a74d09`

### TB-R8 retained artifact-only report — INCOMPLETE / BLOCKED

**Authority.** Run/job `33028238313 / 98374531360`, consuming only CB8 package `9628445643`. Environment GitHub Actions `ubuntu-24.04`; ordinary `unzip` + `tar`; no package repair. Partial result artifact `9629797616` / `50462c5023a5cab817859eefb00b3f523e6cfe1e6d601188cd7c1e14a149c287`.

- P0 immutable-package preflight completed before any test process.
- P1 completed **342/343** fresh selector processes before the user cancelled the workflow; **1 missing** (ordinal 343).
- Accepted prefix **316/316 PASS**; prior first-328 **328/328 PASS**.
- **Ordinal 338**, `ResolvedBranchCorrection.AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections`, ran **853.437 s** and failed with an uncaught `C++ exception with description "gcd(): while running too long! "`.
- **Ordinal 343**, `ResolvedBranchCorrection.GrazingTraceSegmentsPublishExactEndpointSupport`, did not return before cancellation; the payload runs selector order synchronously, so the workflow was inside that process.
- P2–P8 and final postflight were never reached; **no acceptance credit**, and CB8 runtime semantics remain unaccepted.

### CB9 — the corrective, and the three defects it closed

Adjudicated and corrected in one turn at explicit user instruction; the full record is retained as
`Architecture_M3_CP4c0_TB_R8_Review_And_CB9_Corrective_Record.md`. Summary of what it established, because it is the evidence CP4c-0b's definition consumes:

1. **Six of the prescribed sphere's separatrices circulate forever**, lapping a closed 32-state circuit. The first-return map is exactly affine and contracting, `a = 0.9999999999999996` constant across every lap, exact fixed point `p* ≈ 0.970180376877834` inside the interval — an attracting limit cycle approached asymptotically and never reached.
2. **Neither existing guard could see it.** The cycle guard keys on a state containing the exact position, which drifts every lap; the step budget authorised **1,775,616** steps the arithmetic could never survive.
3. **Exact values grow ~1.12 base-1e9 limbs per step and the fallback bignum answers by throwing.** At ~step 205 Euclid passed its fixed 10,000-iteration cap. `gcd(): while running too long!` was the third symptom, not the fault.

Measures **N0–N7** landed: position-free combinatorial recurrence guard (allowance 2 against a measured terminating maximum of 1), deterministic exact-magnitude policy (4096 bits), bignum iteration caps replaced by bounds derived from the algorithms' own worst cases, step budget reduced to a provable envelope of the recurrence guard (1,775,616 → 9,216), a producer closed against escaping exceptions, four falsifying identities, and one identity demoted to non-gating. Selector **343 → 346**, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; accepted first-316 and first-328 prefix hashes byte-identical.

### CP4c-0b — the split, and the termination contract

`M3-CP4c-0b-DEFN` split the checkpoint rather than reorder or re-scope it, on the finding that CP4c-0 had been carrying two unrelated obligations under one gate. **CP4c-0** keeps continuation and closes at gate **346** on Q8 criteria 1, 4 and 5. **CP4c-0b** owns trace/trace contact, arrival priority, the contact node and event, and retirement of the CB9 stand-in guards, together with Q8 criteria **2** and **3** (Amendment 11, moved together and unweakened). Full contract:
`Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md`.

Two candidate stopping rules were excluded **by measurement**, and both are recorded so neither is re-proposed:

- **Self-contact never fires.** 2,548 co-face segment pairs over 420 steps: zero proper crossings, zero endpoint touches, zero collinear overlaps. Structural, because A1 publishes one constant direction per `(face, branch)` so repeat visits lay **parallel** segments, and the circuit is 32 distinct faces each on a single branch.
- **A mesh-derived length budget cannot separate the populations.** Longest correctly terminating trace **5.0175**; one lap of a never-terminating trace **5.0175** — separation ratio **1.000**, zero margin. Bounding boxes are also not rotation-invariant, arc length is not exactly comparable, and a truncated trace leaves an arc that bounds no region.
- **What does work:** contact with the **perpendicular** branch family, available to every circulating trace at its own **step 0**, always on pairs `(0,1)`, `(0,3)`, `(1,2)`, `(2,3)` and never `(0,2)`/`(1,3)`.

---

### CP4c-0 closure chain — CB-R10 / TB-R10, CB-R11 / TB-R11, and TB-R9 acceptance

Between CB9 and CP4c-0's acceptance the user explicitly skipped `M3-CP4c-0-TB-R9-REVIEW-PLAN` and authorized two bounded corrective cycles for the two non-stable TB-R9 candidates, then a fresh compile and complete frozen-gate re-proof.

**CB-R10 / TB-R10 — focused GMP portability.** Corrected semantic source `30ef2792e2915e0016dfd11f5fa2b3727e5503c0`; compile run/job `33067140968 / 98499967674`; immutable package `9644214591`, ZIP SHA-256 `b9e7729fb557eddc203e38a1c11564bab3ad180982e10740d4374fe06748a390`. GMP `libgmp-dev 2:6.3.0+dfsg-2ubuntu6.1`; CMake resolved `libgmpxx.so` and `libgmp.so`; generated test linkage carries both. All eight standard targets compiled and linked; preflight and build exit `0`; source-status snapshots empty. **No GMP, exact-number, continuation, selector, fixture or production semantics changed.**

**CB-R11 / TB-R11 — focused `M3-CP4c0-TB-R9-CAND-02`.** Semantic source `267272d22f7de67ce7d8e368a53cc78a37ca3e8f`; compile run/job `33077493539 / 98535503386`; immutable GMP package `9648550565`, ZIP SHA-256 `1f0275e96fa75b7fc6fb447eaffb79b414c94230823da7897a4f2d91df33615c`; compile log `9648551415` / `c7e4c83c6727117af6cdfc5874762d70dc4a8633cfe7e241e1e36ec001a83e2b`. The positive control was **structurally degenerate** before magnitude-policy behaviour could be demonstrated; **no product or GMP arithmetic defect was found**, and the oversized exact-magnitude fail-closed case is unchanged.

**TB-R9 final — CP4c-0 ACCEPTED.** Fresh GMP package `9649395432` from semantic source `7bbc0480d9ab5954329b940992ef41a9223102ed`; artifact-only run/job `33079817998 / 98543736213`; **346/346 PASS**, first-316 **316/316**, first-328 **328/328**, Q8 criteria 1/4/5 PASS, zero timeouts, zero escaping C++ exceptions, immutable postflight PASS. The earlier `344/346` run remains historical valid RED evidence and both non-stable test-side candidates are resolved. **`Architecture_M3_CP4c0_TB_R9_Artifact_Only_Test_Benchmark_Report.md` is retained as CP4c-0's closure evidence.**

### CP4c-0b — CB1 S1, TB-S1-EXEC, CB1 S2–S6, and DG

**CB1 P0 preflight — stopped at P0.3.** Source-inspection authority: semantic head `49831e30433d72504a69b5a8c817aa6fa00f953c`; verified source-snapshot event SHA `a850b99e7d6b8d8053fee98fefba1e0bcca37704`, run `33084860326`, source artifact `9651687435`. No runtime. P0.1/P0.2/P0.4/P0.5 supported; **P0.3 false**. Adjudicated in full by `Architecture_M3_CP4c0b_P0_3_Independent_Review_Record.md`, which supersedes P0–P9 with S0–S8.

**CB1 S1 — build green, runtime-free.** Semantic/evidence source `4bb467806df99c70889394a323c17c13bc185ca3`; work-preservation patch diff-body SHA-256 `05f6bcfaa65da104daaffa92ca06d97f03c34c150f12e956c3478ddfb122833f`; apply run/job `33092961074 / 98590434004`; apply result `9655159304` / `7c56e84ab41398a567ccfb0f27c70a0b107e7ddd3234949f7ee056458c4de0f9`; apply log `9655160089` / `95c753aaf46a4facade10889aa4569a87daf4e78754483e8823a01069cefbc42`; authoritative compile run `33093440552`, pre-package job `98592131066`. S0.7 satisfied by a GMP compile with `DIRECTIONAL_ENABLE_GMP=ON` and `exactArithmeticBackend=GMP`. S1 adds diagnostic observation only and changes no production contact, node, event, trace or termination decision.

**TB-S1-EXEC — execution green.** Immutable package `9655632444` / `c22e9b020e533ca8fc558bcafc3e138a062702a59bee68a097958b432d70bc5f`; run/job `33097182476 / 98605092984`; raw result `9656967036` / `dd1f8aa8f2346612beb445d7e5d6a8768a438e36c543e0b4d407b444523d85a4`; TB diagnostic log `9656967437` / `667b9c54ad24e9e33855d3fd47a322593c4522bde4984177dfa593a1df7f6bb8`; schema-validation artifact `9656857388` / `3b12cceafeb6cfb3ada110d7dfed7e0700c7694cb97dc0e7e27b490bb843b670`; observer log `9656859884` / `b988cfce44017606058458fc563a256f985c89066f20b18b4d402490ce20ba3d`. **346/346 PASS** on the unchanged frozen selector; the separate S1 identity selected exactly once and PASS with zero gate credit; zero escaping exceptions; immutable postflight PASS.

**S1 census result, and the caveat that later mattered.** Two-ring and torus reached with **zero shared-face contacts** and `requiresReview=0`; the excluded fan remained excluded; `sphere_prescribed` was explicitly `status=unreached` at `TraceCombinatorialRecurrenceExceeded` (65 steps, budget 9216, visits 3, allowance 2). Two-ring `nodeCount=9`, torus `nodeCount=0`. **Those node figures were measured under `rails_from_atlas`**, which `M3-CP4c-0b-DG-REV` later established is a different rail authority from the production pipeline's `authoritativeRails` — the cause of the DG red. The S1 census did not publish the rail authority alongside the figure; measure **T3** requires that it now does.

**CB1 S2–S6 — build green** at semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d`. The S1 review record authorized S2–S6 exactly as frozen and explicitly authorized re-authoring `DeclaresTraceIntersectionsAsTypedNetworkEvents` and `IndependentCompositionOracleValidatesTraceEventGraph` for the site-A vocabulary split; any other accepted expectation edit is a stop.

**DG — valid semantic red 6/7.** Immutable package `9664890562` / `94beb349763ff261d603839176a458d1f69e976192aafcd0c69d2617abd88273`; corrected run/job `33120730355 / 98686699036`; result `9666352028` / `286f738f02315d72dea7cc03bed61bc12ef6b5345ddf15264a898b5bfa45db72`. A first control run `33120437486` / job `98685729035` executed **zero** Directional identities — a temporary-harness `tar | grep` pipeline under `set -o pipefail` misclassified a closed-pipe write as a missing fixture; recorded as `M3-CP4c0b-DG-CAND-01`, **RESOLVED ORCHESTRATION / NON-STABLE**, corrected in the harness only with no semantic byte changed. Six of seven new identities passed; the sole red is `TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit`, adjudicated by `Architecture_M3_CP4c0b_DG_Independent_Review_Record.md`.

---

### S1 census — the measured table, retained because T5 depends on it

Measured under **`rails_from_atlas`** (the authority the census used; `M3-CP4c-0b-DG-REV` later established this differs from the pipeline's `authoritativeRails`, and measure T3 now requires every census figure to name its authority).

| witness | population | A / B / C | shared-face contacts | proper / non-proper / unevaluated | nodes | disposition |
|---|---|---:|---:|---:|---:|---|
| `two-ring` | included | `1 / 0 / 0` | `0` | `0 / 0 / 0` | `9` | reached |
| `four-triangle-fan` | excluded fixture artifact | `1 / 0 / 0` | `0` | `0 / 0 / 0` | **`8`** | reached but non-creditable |
| `sphere_prescribed` | included | n/a | not reported | not reported | n/a | unreached at N1 |
| `torus` | included | `0 / 0 / 0` | `0` | `0 / 0 / 0` | `0` | reached |

Two-ring event histogram: `SingularityPortOrigin=1, FirstContact=3, TraceIntersection=1, MandatoryBarrierTermination=3`, its sole recorded site being **A**, the singularity-origin junction at source vertex `0`. The excluded fan has the **same** histogram with its site-A junction at source vertex `4`. The torus has no nodes or events under this authority. The prescribed sphere stopped before `finalize_field_aligned_events` at the expected typed `TraceCombinatorialRecurrenceExceeded` — `traceSteps=65`, `traceStepBudget=9216`, `traceCombinatorialVisits=3`, `traceCombinatorialVisitAllowance=2` — and the S1 review explicitly declined to translate that into a zero-contact claim.

**The fan row's `nodes = 8` is load-bearing.** It is the same figure accepted ordinal 13 (`FieldAlignedCurveNetwork.PublishesTypedSingularityPortsAndMandatoryGraph`) asserts absolutely, under the same rail authority, and it decomposes as `5` structural nodes plus `3` terminal 0-cells — one per barrier-terminating trace. See `Architecture_M3_CP4c0b_DG_T4_Independent_Review_Record.md` §4.4.

**Authorized accepted re-authorings, frozen by the S1 review and unchanged since.** Exactly two, both for the site-A vocabulary split: `FieldAlignedCurveNetwork.DeclaresTraceIntersectionsAsTypedNetworkEvents` (accepted ordinal **7**) and `FieldAlignedCurveNetwork.IndependentCompositionOracleValidatesTraceEventGraph` (accepted ordinal **9**). **Any other accepted expectation edit is a stop.** Relative digest and invariance identities remain semantically binding and are not authorized to weaken.

### CB1 S2–S6 and the first DG — retained identities

**CB1 S2–S6 build green** at semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d`.

**First DG — VALID SEMANTIC RED 6/7.** Immutable package `9664890562` / `94beb349763ff261d603839176a458d1f69e976192aafcd0c69d2617abd88273`; corrected run/job `33120730355 / 98686699036`; result `9666352028` / `286f738f02315d72dea7cc03bed61bc12ef6b5345ddf15264a898b5bfa45db72`; diagnostic log `9666352544` / `651e9cb9fc78d109d725fdf725fd26b72c450f6bba44fd77e638780c0df2712e`; schema report `9666336581`; observer log `9666337089`. DG selector then **7** / `14570409facfb9c9072375cae3ad4319e383386380ee1060d4af75c6e61c5724`; full selector then **353** / `91371d5ab637447c31c0d25e829be0d58fa61f17245e69bd231dcaec94f21efb`. Six identities passed; the sole red was `TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit` at `tests/FieldAlignedCurveNetworkTests.cpp:6952`.

A first control run `33120437486` / job `98685729035` executed **zero** Directional identities: a temporary harness checked the packaged fixture with `tar -tzf … | grep -Fxq …` under `set -o pipefail`, `grep` exited after the match, and `tar`'s closed-pipe write error was misclassified as a missing fixture. Recorded as **`M3-CP4c0b-DG-CAND-01`, RESOLVED ORCHESTRATION / NON-STABLE**; corrected in the harness only, with the tar listing materialized first, and no semantic/package/test/fixture/selector byte changed.

### CB2 and DG-T4 — current authority

**CB2 (T0–T3) build green.** Inspection/control snapshot `48352cb2cb88a16d4a66104eadcc9b700f3e449f`; semantic source `b2629040450c12507367c232f68a4d972b46450f`; patch SHA-256 `c297a55afb1b04c9fb2b854b91f8aa4883c6ec8a3e33a22d5655998115713be9`; compile-only run `33126178643`, changed-owner job `98704812754` PASS, eight-target package job `98705144144` PASS with GMP/GMPXX; immutable package `9668492827` / `e0661e66cfc12ce8945962a18b8a8f6fc8aa5a1213b3ad4d2409054573dce0b8`, manifest 28/28, clean source status, executable modes preserved, `runtimeExecution=false`; compile log `9668493344` / `f596c69c6bbdbe21d00cdbfd92d5a708480236971ba065ebc74c4d40fad5de4a`.

**T1 result — first decision row.** Atlas-derived torus rails yield 0 mandatory edges / 0 singularities / 0 nodes / 0 traces / 0 events; pipeline-authoritative rails yield **48 `HardFeature` mandatory edges / 0 singularities / 48 structural endpoint nodes / 0 traces / 0 events**, every node a mandatory-edge endpoint with **zero contact provenance**. No second rail-authority divergence was found. `M3-CP4c0b-DG-CAND-02` **RESOLVED / TEST-SIDE OVER-SPECIFICATION / NON-STABLE**.

**DG-T4 — EXECUTION GREEN 7/7.** Run/job `33128261911 / 98711506300`; result `9669229181` / `364d5d546bca4c664be67e52b336a48cbc1f49b6bd672371ea6351e396dcc84c`; diagnostic log `9669229414` / `39c7530a70650702f4345fea9de558ea6139fecd715f8d9b504ef945a94447ef`; runner GMP `libgmp-dev=2:6.3.0+dfsg-2ubuntu6.1`. Re-frozen DG selector **7** / `d28bbeeb74ed8e07810b06d870bdaf470bab1f294bbfe810deaa4f63276e245c`; full selector **353** / `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, whose **first 346 lines hash to the accepted CP4c-0 selector** `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` — the accepted prefix is preserved in order. All seven identities selected once, exit 0, PASS; zero escaping exceptions; package and materialized-source byte-and-mode postflight PASS.

**Still unmeasured after T4:** S2–S6's effect on **accepted authority**. Measures **U0–U7** in `Architecture_M3_CP4c0b_DG_T4_Independent_Review_Record.md` §5 bind the T5 turn.

**T5 preflight and CB3-INSTR.** The first T5 attempt stopped correctly before runtime at **0/353** because U3/U4 named evidence package `9668492827` could not publish while U7 prohibited instrumentation/build inside T5. Independent `M3-CP4c-0b-TB-T5-PREFLIGHT-REV` upheld the blocker and authorized test/non-gating-only CB3-INSTR under V0-V7. CB3 source `93059089881c8715a168a61968a8d6874ee1a670` changes only `tests/FieldAlignedCurveNetworkTests.cpp` plus the non-gating selector; `src/`/`include/` and the 353 selector remain unchanged. Compile run `33133572290` is green on changed-owner job `98728445391` and eight-target job `98728639650`; immutable GMP package `9671190795` has ZIP SHA-256 `2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1`, 28/28 manifest PASS, clean source status and `runtimeExecution=false`. Required 353 remains `51ff96d7…ac6a5`; first-346 `20d3b0b1…3e46a`; non-gating is now four identities / `d4224002…d9ad`. M3 packages are **55**. Exact next is artifact-only T5 on this package; no acceptance credit is claimed by CB3.

---

## 3b. The independent review arc — one digest per retired review

Seven independent reviews took CP4c from a frozen-but-unexecutable plan to a root cause and a frozen contract. Each is retired here; its **normative output** lives in the frozen-definition documents, its **lessons** in `LESSONS.md`, and its **evidence identities** in §2–§3 above. What follows preserves each one's finding, the amendment it produced, and the reviewer errors it owned.

### CP4c parent — `TB-R1-INDEPENDENT-REVIEW`

Evidence: run/job `32791027809 / 97632461750`, CB2 package `9541369624`, source `a5edb1a31c315d51df216f3bb51470989ff64e33`. Result reviewed: **VALID RED 316/322**, accepted prefix 316/316, CP4c C1–C6 **0/6**.

| # | Subject | Disposition |
|---|---|---|
| D1 | Does DG execute a different runtime surface than TB? | **No** — DG's surface is a strict subset of TB's under identical rules. The distinction was pure budget bookkeeping. |
| D2 | Attempt budget and the DG turn type | **Both abolished.** The workflow becomes `CB → TB → (red) → REVIEW+PLAN → CB`. |
| D3 | C1 / C3 / C6 — torus | **Frozen-definition scope gap in accepted A2b authority**, not a witness defect. A2b assumes every trace arc separates its two sides — a genus-0, bounded-surface assumption. The torus is closed, χ = 0, genus 1. |
| D4 | C2 — mechanical | **Accepted A1 authority fails on a surface class it has never been driven with**: `FieldTransportAtlas::make` rejects `IncompleteCycleBasis`, upstream of A2a entirely. Not CP4c scope. |
| D5 | C4 / C5 | **Authored against a witness that provably cannot satisfy them**, and the proof was already in the durable record before CB2 ran. |
| D6 | CP4c as frozen | **Not executable.** The frozen `322 = 316 + C1–C6` is reopened and CP4c is split. |
| D7 | Blame | The plan, not CB2. CB2 implemented §7.1 correctly, including reading the new `globalTopologyPlan` slot rather than the legacy `traceNetwork`. |

Stable accounting unchanged at 42 / 14 / 28; the six reds are first-acceptance candidates, not regressions. All 316 accepted identities were green **in the same immutable run** — the strongest available evidence that CB1's production wiring regressed nothing. **This review produced the CP4c-0/1/2/3 decomposition now owned by `ROADMAP.md` §3.**

### `M3-CP4c-0-DEFN-Charter` — D0–D5, discharged

The charter posed six questions and forbade any implementation until they were frozen. Each is answered in `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` §0 and the section it names: **D0** exact position authority → `FieldBoundaryPoint`, §3; **D1** within-face continuation → exact minimum-ratio exit, §4; **D2** A1 contract shape → `connections` deleted, direction published, §5; **D3** accepted-prefix re-proof → §6; **D4** witness-stage capability → §7; **D5** terminus-datum unification → unified, §8. Its stop conditions did not fire, which is what authorized the DEFN to freeze. The charter is discharged and retired.

### `TB-REVIEW-PLAN` — Amendments 1–5, measures E0–E10

The 328 gate went green but the sphere was rejected at **T6** (`t* = 0`, `BranchContinuationDegenerateEntry`, `sourceEdge=6-8`). Found **five defects in the frozen DEFN**: the surviving `kBranchTopologyTolerance` decides carrier-set membership and is therefore a tolerance-derived ownership key; the vertex-sector predicate is neither a partition nor a cover at `tol > 0`; T1 was not exhaustive for an exit parameter of exactly 0 or 1; cross-edge flow agreement was never asserted; and locus fields were being back-filled from trace seeds. All five are **Amendments 1–5**, stated in full in the frozen-definitions §10. Also proved Theorems 1–3, that T6 is unreachable from any well-formed production state after the amendments.

### `TB-R2-REVIEW-PLAN` — Amendment 6, measures F0–F8

Two class defects that instance falsifiers had passed over: a `std::uint8_t` returned by value was **character-streamed** at a diagnostic boundary, and roughly fifteen trace-seed back-fills survived because Amendment 5's wording was line-scoped. **Amendment 6** redefines "observable" by *mechanism* — formatted through a named `*_locus` helper, printable ASCII only, parseable, site-sourced at every emission site — and requires every diagnostic contract to be falsified by a **class** identity quantifying over all codes and sites, never an instance one.

### `TB-R3-REVIEW-PLAN` — Amendment 7, measures G0–G8

Two test-side reds, and the discovery of the **per-face gauge**: `build_face_branch_frame` assigns each face a gauge against its canonical reference edge, so `FieldBranch` is a per-face *label*, not a portable direction identifier, and cross-face comparison is valid only through the published `signedLift = matching + g_source − g_target`. Production was compliant everywhere; the oracle that assumed otherwise was not. **Amendment 7** also forbids a required falsifier from asserting the *existence* of a current production failure.

**Reviewer error owned:** the review predicted identities 330–337 would all be green; **333 and 334 went red**. The cause was auditing the assertions without auditing the preconditions and authority the identity consumes.

### `TB-R4-REVIEW-PLAN` — measures H0–H7

G5 published the live rejection and the review framed three candidate mechanisms — matching sign convention, matching aliasing, and A2a carrying the wrong branch — then prescribed the H1 cross-face flow-agreement census to discriminate them. It also **formed and then refuted** the canonical-normal-parity hypothesis before publishing: the two faces do have opposite canonical parity, and parity mismatch covers 86.8 % of the sphere's interior edges, but the gauge is an index shift into a per-face array and **cancels** in `matching + g_X − g_Y` regardless of frame.

**Reviewer errors owned, both corrected at TB-R6:** the claim that both faces calling a shared edge `Outflow` is *"geometrically impossible for a single continuous direction"*, and the argument that `|d| = 1.0035` being "three orders of magnitude above any epsilon" excluded near-tangency. Tangency is a **ratio**, and 1.0035 is the *smallest* of `{4.00, 5.01, 1.00}`.

### `TB-R5-REVIEW-PLAN` — Amendment 8, measures J0–J7

H1's census delivered 390 disagreements. The review proved the **four-triangle fan's two violations are a fixture artifact**: its census field leaves the direction vectors globally constant and merely *imposes* `matching = ±1` on one edge, so the published lift is exactly correct and the disagreement is forced by a matching that contradicts the geometry. Corrected population: **388 directed / 194 distinct** over three legitimate witnesses. Also established that **the lift histogram is uninformative about matching** — `signedLift` is a sum of three unobserved terms — and that the census's two-direction loop imposes the ±k tail symmetry and doubles every count. **Amendment 8**: the cross-edge flow invariant audits the field's **input matching** as much as A1's composition, so a witness with imposed matching will trip it correctly and its firing does not by itself indict A1 code.

**Reversal recorded:** the review began asserting that A1 published a wrong lift on the fan assuming `matching ≡ 0`, checked the fixture, found `make_index_one_singularity_field` imposes `matching = ±1`, and reversed the conclusion to "fixture artifact" before publishing.

### `TB-R6-INDEPENDENT-REVIEW-RECORD` — Amendment 9, measures K0–K7 — **root cause**

The cycle that identified the root cause, and it is a contract gap rather than an implementation defect. The census was reproduced from the committed `.obj` and `.rawfield` alone — no product code — yielding **exactly 144 directed disagreements**, matching runtime. The **tangency ratio** `min(|d_opp| / max|d|)` has median **0.0218** across the 144 disagreeing pairs against **0.9233** across the 1008 agreeing ones: a 42× separation, overlapping at the bottom, so a geometric regime rather than a threshold. **Every published term at the live locus verifies correct** — matching 0 is geometrically right with a 42° margin, `0 + 1 − 3 ≡ 2` reproduces the published lift, both gauges map their semantic branch to raw index 0, both `dbary` triples reproduce to 10 decimal places, and all 288 interior edges are normal adjacency with none folded.

**Three standing readings withdrawn.** The live locus does not indict `build_branch_transports`. There are not two classes — the unequal-gauge and equal-gauge/lift-0 populations are one near-tangency phenomenon. And **J3's 524/524 does not exclude H-B**: `independent_edge_measurement` re-implements **principal matching**, the algorithm H-B suspects, so it is an implementation cross-check and not an aliasing test. H-B is excluded, but by direct measurement at the live locus, not on J3's authority.

**Amendment 9**: Amendment 4 / measure E5's cross-edge flow invariant is a **continuum** statement and is unsound for a piecewise-constant field near edge tangency. `BranchTransportFlowDisagreement` becomes a typed grazing observation, `DESIGN.md` §4.5 is declared incomplete, no tolerance may classify grazing, and every cross-stage invariant asserted on discrete data must state its discretization assumptions.

**Reviewer errors owned:** the TB-R4 impossibility and magnitude-versus-ratio claims above, and the **J3 specification**, which said "find which target raw index the source direction actually maps to" — that *is* principal matching, so the suspect was named as its own oracle.

### Withdrawn predictions, kept as a record of what estimation cost

| Prediction | Turn | Outcome |
|---|---|---|
| Identities 330–337 all green | TB-R3 review | **Falsified** — 333 and 334 red |
| Canonical-normal parity explains the disagreements | TB-R4 review | **Refuted before publication**; the gauge cancels in the lift |
| The fan's violations indict A1 | TB-R5 review | **Reversed before publication**; fixture-imposed matching |
| Near-tangency excluded because `\|d\|` is far above any epsilon | TB-R4 review | **Falsified at TB-R6**; tangency is a ratio |
| Decision-table rows assigning owners to the disagreement classes | TB-R5 review | **Withdrawn at TB-R6**; one geometric regime, no owner |
| K2 would discriminate the four grazing models | TB-R6 review | **Void** — K2 walked the retired Cartesian rule |
| The sphere's separatrix network is the cube's edge graph, all 24 traces terminating at singularities | DEFN-2 §9.2 | **Falsified at CB9** — 42 of 48 terminate, 6 circulate |

---

## 3c. Where CP4c information now lives

| Information | Authoritative location |
|---|---|
| Continuation contract, Amendments 1–11 | `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` |
| Grazing classification and edge transit | `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md` |
| Trace termination, contact predicate, arrival priority | `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md` |
| Non-terminating traces, the CB9 guards, the measured evidence | `Architecture_M3_CP4c0_TB_R8_Review_And_CB9_Corrective_Record.md` |
| Normative architecture, incl. the §4.5 grazing paragraph and the §4.6 termination condition | `DESIGN.md` |
| Checkpoint decomposition and gates | `ROADMAP.md` |
| Current gate, next action, task status | `TODO.md` |
| Exact next-turn instructions and current immutable authority | `Future_Chat_Session_Handoff.md` |
| Completed history, newest first | `CHANGELOG.md` |
| Regression and candidate root-cause history | `Regression_Root_Cause_Tracker.md` |
| Durable lessons | `LESSONS.md` |
| Per-turn evidence identities for every retired CP4c document | **this record**, §2–§3 |

---

## 4. CP4c-1 — evidence (OPEN / TB READY after CB3 cumulative rebase)

| Turn | Semantic source | Run / job | Package | Result |
|---|---|---|---|---|
| **CB (historical)** | `51f510861a02377d1f45607908191f2fdebdcd33` | `32867889140`; jobs `97867532883`, `97867597370`, `97867694421`, `97868351487` — all PASS | `9570940997` (`23876c55e51b94ca3a1e5bcfb727a4c0cebce3294fcd2fbda21336b57ae1de16`) | BUILD GREEN |
| **TB / TB-R3 (historical)** | `51f510861a02377d1f45607908191f2fdebdcd33` | `32872112507 / 97881418987`; result `9572545977` | `9570940997` | **VALID RED 316/318** |
| **CB3 cumulative rebase (current)** | `66a065b5e07910568a317e24f0fc6b93d890d104` | `33139188595 / 98746005796` | `9673249952` / `17a3f8da793fc20562e5ec2f0ab441d39f795dd146171e989fb952e6f942d2ea`; log `9673250286` / `cffa6fc4a72c0d60fa2199131cdd6073c7a8c7f15482a0e48af98cb3dadf32b9` | **BUILD GREEN / RUNTIME-FREE** |

Historical checkpoint-local selector was 318 /
`2f2c24acab0e891273c170c82cdc31b6afa3ae4d43e93c95dbdf6d90a88f45bc`, with accepted 316 prefix
`601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`. Historical/current
non-gating selector remains 5 /
`9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`.

After CP4c-0 and CP4c-0b acceptance, CB3 froze the cumulative required selector at **355** /
`e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`. Its first **353** lines are
byte-exact accepted CP4c-0b authority `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`;
the first 346 and first 316 retain their accepted hashes. C4/C5 are exactly ordinals 354/355 and remain
gating:

1. `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing`
2. `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced`

CB3 changed no product implementation, test body, fixture, accepted expectation, or non-gating selector.
All eight standard targets compiled/linked with GMP/GMPXX, package manifest 28/28, clean source status,
and `runtimeExecution=false`. A first compile caller `33139114617` failed at workflow startup because its
permission ceiling was below the reusable observer graph; only the caller permission changed before the
authoritative compile.

C4/C5 remain the only checkpoint-local required blockers and **stay gating**. The accepted 353 predecessor
is now their frozen ordered prefix. Exact next is artifact-only **`M3-CP4c-1-TB-R4`** against package
`9673249952`, requiring 353/353 accepted-prefix green plus C4/C5 green for **355/355**. The five diagnostics
remain report-only with zero gate credit. Stable accounting remains **42 / 14 / 28**, debt **5**, packages
**56**. CP4c-2/3 are not entered.

Root-cause history for the Cartesian-product continuation defect and Z0-Z5 measurements remains in this
record and `Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md`; CB3 does not re-litigate it.

---

## 5. Documents retired into this record

Retired under explicit user authorization. Every evidence identifier, finding, amendment, reviewer
error and disposition each carried is inlined in §1–§3c above. **No amendment, lesson, stable ID,
artifact identity, unresolved blocker or acceptance criterion was removed** — each now has exactly one
authoritative home, listed in §3c.

### 2026-08-26 — first consolidation ("consolidate CP4c docs")

**CP4c parent:** `..._CB1_Global_Topology_Plan_Code_Build_Report`,
`..._CB2_Production_Witness_Code_Build_Report`, `..._DG1_Artifact_Only_Diagnostic_Plan`,
`..._DG1_Artifact_Only_Diagnostic_Execution_Report`,
`..._DG1_Artifact_Only_Diagnostic_Independent_Review_Record`,
`..._TB_R1_Artifact_Only_Test_Benchmark_Report`, `..._Code_Build_Plan` (already marked SUPERSEDED).
**CP4c-0:** `..._Artifact_Only_Test_Benchmark_Report`, `..._CB2_Code_Build_Report`,
`..._CB2_Artifact_Only_Test_Benchmark_Plan`, `..._CB2_Artifact_Only_Test_Benchmark_Report`,
`..._CB3_Code_Build_Report`, `..._CB3_Artifact_Only_Test_Benchmark_Plan`, `..._CB4_Code_Build_Report`,
`..._CB4_Artifact_Only_Test_Benchmark_Plan`, and the superseded review briefs `..._TB_Review_Plan`,
`..._TB_R3_Review_Plan`, `..._TB_R4_Review_Plan`. **CP4c-1:** `..._Code_Build_Report`,
`..._Artifact_Only_Test_Benchmark_Plan`, `..._Artifact_Only_Test_Benchmark_Report`,
`..._TB_Review_Plan`, `..._TB_R2_Review_Plan`.

### 2026-08-27 — second consolidation ("consolidate and cleanup CP4c historical docs")

**Tier 1 — per-turn evidence, identities inlined in §3 (11 documents).**
`Architecture_M3_CP4c0_CB8_Code_Build_Report.md`,
`..._TB_R5_Artifact_Only_Test_Benchmark_Report.md`, `..._TB_R5_Review_Plan.md`,
`..._TB_R6_Artifact_Only_Test_Benchmark_Plan.md`, `..._TB_R6_Artifact_Only_Test_Benchmark_Report.md`,
`..._TB_R6_Review_Plan.md`, `..._TB_R7_Artifact_Only_Test_Benchmark_Plan.md`,
`..._TB_R7_Artifact_Only_Test_Benchmark_Report.md`,
`..._TB_R8_Artifact_Only_Test_Benchmark_Plan.md`, `..._TB_R8_Review_Plan.md`,
`..._TB_R8_Test_Benchmark_Report.md`.

**Tier 2 — independent reviews and the discharged charter, digested in §3b (8 documents).**
`Architecture_M3_CP4c_TB_R1_Independent_Review.md`, `Architecture_M3_CP4c0_DEFN_Charter.md`,
`..._TB_Review_Plan_Independent_Review.md`, `..._TB_R2_Review_Plan_Independent_Review.md`,
`..._TB_R3_Review_Plan_Independent_Review.md`, `..._TB_R4_Review_Plan_Independent_Review.md`,
`..._TB_R5_Review_Plan_Independent_Review.md`, `..._TB_R6_Independent_Review_Record.md`.

**Why Tier 2 could be retired.** Each review's **normative output** is an amendment, and Amendments
1–11 are stated in full in `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` §10 — that document, not
the review, is the amendment's authoritative home, so retaining both was duplication. Each review's
**durable lessons** were moved to `LESSONS.md` in the turn that produced them. Each review's **evidence
identities** are in §2–§3. What remained unique to the reviews — the finding, the reviewer errors owned,
and the refutations and reversals — is preserved in §3b, including the withdrawn-prediction table, which
exists specifically so the cost of each estimation error stays visible.

### 2026-08-27 — third consolidation (`M3-CP4c-0b-DG-REV`)

Retired after inlining every evidence identity into §3 above: `Architecture_M3_CP4c0_TB_R10_Focused_GMP_Portability_Verification_Report.md`, `Architecture_M3_CP4c0_TB_R11_Focused_CAND02_Verification_Report.md`, `Architecture_M3_CP4c0b_CB1_P0_Preflight_Record.md`, `Architecture_M3_CP4c0b_CB1_S1_Code_Build_Report.md`, `Architecture_M3_CP4c0b_TB_S1_EXEC_Artifact_Only_Test_Benchmark_Report.md`.

The P0 preflight record is fully quoted and adjudicated by `Architecture_M3_CP4c0b_P0_3_Independent_Review_Record.md`; the S1 build and execution reports are fully consumed by `Architecture_M3_CP4c0b_TB_S1_Review_Record.md`, which remains **live authority** because it is the document that authorizes the two accepted re-authorings measure T5 depends on.

### 2026-08-28 — fourth consolidation (`M3-CP4c-0b-DG-T4-REV`)

Retired after inlining every durable fact into §3 above: `Architecture_M3_CP4c0b_TB_S1_Review_Record.md` (its census table, the fan's load-bearing `nodes = 8`, and the two authorized accepted re-authorings are reproduced verbatim), `Architecture_M3_CP4c0b_CB1_S2_S6_Code_Build_Report.md` (superseded by the CB2 package), and `Architecture_M3_CP4c0b_DG_Artifact_Only_Test_Benchmark_Report.md` (its 6/7 red is superseded by T4's 7/7; its `DG-CAND-01` orchestration record and every artifact identity are inlined).

### Retained, and why

| Document | Why it is retained |
|---|---|
| `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` | **Normative.** The continuation contract and Amendments 1–11. |
| `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md` | **Normative.** The grazing classification and edge-transit contract. |
| `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md` | **Normative and current.** The termination contract and the CP4c-0b plan. |
| `Architecture_M3_CP4c0_TB_R8_Review_And_CB9_Corrective_Record.md` | **Current authority.** The measured evidence CP4c-0b's definition consumes, and the only record of the CB9 corrective. |
| `Architecture_M3_CP4c0_Required_Green_Selector.txt` | Live gate authority — 346. |
| `Architecture_M3_CP4c1_Required_Green_Selector.txt`, `Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt` | Live gate authority for CP4c-1, which is open. |
| `Architecture_M3_CP4c_Required_Green_Selector.txt` | Parent CP4c 322 selector; the record of which identities constitute C1–C6, needed by the still-unopened CP4c-2 and CP4c-3. |
| `Architecture_M3_CP4c0b_P0_3_Independent_Review_Record.md` | **Normative.** Withdraws P0.3, names the six defects in the accepted contact mechanism, and supersedes P0–P9 with S0–S8. |
| `Architecture_M3_CP4c0b_TB_S1_Review_Record.md` | **Live authority.** It is the only document authorizing the two accepted re-authorings that measure T5 must honour. |
| `Architecture_M3_CP4c0b_DG_Independent_Review_Record.md` | Adjudicates `DG-CAND-02` and freezes T0–T7; superseded as *current plan* by the T4 review but retained as the rail-authority analysis. |
| `Architecture_M3_CP4c0_TB_R9_Artifact_Only_Test_Benchmark_Report.md` | **CP4c-0's closure evidence** — the 346/346 acceptance run. Retained until a dedicated CP4c-0 closure record exists. |
| `Architecture_M3_CP4c0b_Required_Green_Selector.txt`, `..._Diagnostic_Gate_Selector.txt`, `..._Non_Gating_Diagnostic_Selector.txt` | Live CP4c-0b gate authority — 353 / 7 / non-gating. |
| `M3_CP4c_Consolidated_Record.md` | This record. |

---

## 6. Standing accounting

Stable regression accounting has held at **42 events / 14 categories / 28 recurrences** across the
entire CP4c family, because **CP4c has never been accepted** and the accepted 316 prefix has stayed
green in every run that executed it. Produced-witness debt remains **5**. Latest accepted runtime
authority remains **CP4ab 316/316**, source/package
`157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`.

## 2026-08-27 — TB-R9 GMP artifact-only re-proof and mandatory review boundary

TB-R9 consumes GMP-linked package `9634245265` from source `66325345567106fe7de8560ee2aee5f07ca665de`; package ZIP SHA-256 `4ef834465ee8db3110f40f7882cde4a39f94821b6bc0daba3ae0b0e04d7e5629`. Authoritative run/job `33048964354 / 98439563813`; result artifact `9636849182` / `b485c1cfe5f929600bae382b1a01954b319dd4d1904e1dd1675cb2ad02771c57`; log artifact `9636849748` / `9a23f1e9f8de5bb36086ed2ea1e20900cbb9cf53a940bc7c336a4ab2516d4023`.

The frozen CP4c-0 selector is **346** (`20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`). Runtime completed **344/346 PASS**: accepted first-316 **316/316**, first-328 **328/328**, Q8 criteria 1/4/5 all PASS, zero timeout, zero escaping C++ exception, zero orchestration error, immutable postflight PASS. The TB-R8 pathological identity now returns PASS in **102 ms**.

Two RED identities remain and are deliberately **not** repaired in TB:

1. ordinal 333 `ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip`: the test's `to_double(18)` witness search relies on legacy digit-limited decimal truncation, while GMP's implementation is `get_d()` and ignores `maxDigits`; candidate `M3-CP4c0-TB-R9-CAND-01`, test-side GMP portability;
2. ordinal 344 `ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance`: the narrow positive-control fixture reaches an exact zero-time exit and correctly receives `BranchContinuationDegenerateEntry`; candidate `M3-CP4c0-TB-R9-CAND-02`, test-side fixture/precondition.

Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **48**. CP4c-0 remains OPEN and receives no acceptance credit. Exact next is independent `M3-CP4c-0-TB-R9-REVIEW-PLAN`; no runtime, compile, mutation, rerun, or automatic CP4c-0b-CB1 entry is authorized in that review.
