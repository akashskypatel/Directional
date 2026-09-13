# M3 CP2b Closure Record — canonical branch topology and singularity-port attachment authority

Date: 2026-08-21 UTC
Status: **CP2b CLOSED / ACCEPTED.**
Accepted authority: source/package `1d2417c90970db81f8b49dd6e0961868cac32369 / 9428451548`, immutable `M3-CP2b-TB-R5` `32434684618 / 96633374819`, **292/292 PASS**.

This is the consolidated durable closure record for the inserted M3 CP2b checkpoint. Exact final-gate evidence is retained in `CHANGELOG.md` (retained exact TB-R5 evidence: `32434684618 / 96633374819`, result/log `9430381177 / 9430381560`); chronological attempt evidence remains in `CHANGELOG.md`; regression history remains in `Regression_Root_Cause_Tracker.md`.

## 1. Closure verification

| Check | Result |
|---|---|
| Immutable final gate | **PASS — 292/292**, 292 required / executed / unique |
| Accepted predecessor | **PASS — 287/287** |
| CP2b identities | **PASS — 5/5** |
| Combined selector | **PASS** — SHA-256 `fc6bfc2b90c8a39512ee89e73106f2592fd4664aa90929c8c970e3ef0455245e` |
| Package/source authority | **PASS** — `9428451548 / 1d2417c90970db81f8b49dd6e0961868cac32369` |
| Package ZIP SHA-256 | **PASS** — `20dc884a38d865f34a14be66780ab7827cead4855a26cf0c1f945cee67131427` |
| Immutability | **PASS** — package and materialized source byte-identical pre/post |
| Runtime boundary | **PASS** — no checkout as semantic authority, rebuild, relink, repair, mutation, discovery, benchmark, CLI/fuzzer, or custom input |
| Final result artifact | `9430381177`, SHA-256 `41292ffef7231ef7010bd416aa6b730fd6022694933bc0c4b538abadb64bf8be` |
| Final log artifact | `9430381560`, SHA-256 `a789a6567c865e119deef69c295894078ce2621f7972912666c726b1b6b886a4` |

## 2. What CP2b delivers

CP2b completes the A1 authority that the CP3a census proved was missing before traversal could be implemented safely:

- canonical per-face branch frames;
- canonical branch-to-boundary pairings / interval authority;
- checked singularity-port starting-branch and exact local source attachment authority;
- reciprocal canonical Z4 branch transport whose integer lift is stored in the unique `[0,3]` representative rather than leaking gauge-dependent raw integer representatives into equality/hashing;
- independently validated branch topology and port attachments, including equivalent-Z4 relabel invariance and strict tamper rejection.

The accepted non-degenerate singularity witness publishes five incidences grouped into three semantic classes. Two incidences may legitimately share a start face and first outgoing carrier when they carry different branches; representative identity therefore includes branch.

**What CP2b does not claim:** branch-consistent traversal/candidate segments (CP3a), contact/intersection/termination graph authority (CP3b), global topology selection/disc proof (CP4), M4 conformity scheduling, or production-quality/resource guarantees.

## 3. Attempt trajectory

The original three-attempt window was exhausted without acceptance:

- attempt 1: source/package `740f0cca2f052d6274a7b24361bd33143f8c11f6 / 9388213803`, corrected immutable gate **285/292**;
- attempt 2: `bcf45fe28468b950987d52119548e06f411e4f19 / 9390283890`, immutable `32324880480 / 96294021816`, **289/292** with predecessor restored 287/287;
- attempt 3: `90c737e11c340061dd0167eaf59fec66afa0c8ba / 9392366234`, immutable `32331037070 / 96311550091`, **287/292**, CP2b 0/5 and predecessor 287/287.

Mandatory Review then restored a fresh three-attempt window and the diagnostic regime was exhausted at 2/2:

- restored attempt 1: R5 package `9416963557`, TB-R3 valid **288/292**, first exact semantic rejection `DuplicateSingularityPortRepresentative`;
- restored attempt 2: R6 package `9422702053`, TB-R4 `32418067075 / 96583693356`, **291/292**, with G1 partition and representative-key correction green; sole red isolated to the independent relabel validator while all direct product invariance checks passed;
- restored attempt 3: R7 package `9428451548`, TB-R5 `32434684618 / 96633374819`, **292/292 ACCEPTED**.

M3 cumulative package count through CP2b is **18**, reported only under the current regime. CP3a owns a fresh independent **3-attempt budget**; its attempt 1 remains unconsumed.

## 4. Root causes closed

`PR8-R040 / M3-CP2b-R001` and `PR8-R041 / M3-CP2b-R002` remain resolved stable recurrences; closure does not erase their historical counts.

Two non-stable CP2b candidates are also closed:

- `M3-CP2b-TB-R1-CAND-02` — architecture/product representative identity was rank-one because it omitted `branch`; corrected to `(startFace, branch, firstOutgoingCarrier)` and runtime-proven by the exact 5-incidence/3-class partition.
- `M3-CP2b-TB-R1-CAND-01` — the independent test oracle conflated raw gauge-dependent matching with canonical published Z4 transport. Product canonicalization was already positively supported by TB-R4. CB-R7 independently re-derived gauge/orientation/mod-4 authority in the oracle and retained `+1` rejection / `+4` equivalence; TB-R5 proves both the relabel positive and strict tamper negative green.

Stable accounting remains **41 / 14 / 27**; produced-witness debt remains **5**.

## 5. Successor boundary

Accepted CP2b becomes the frozen **292-identity predecessor** for CP3a. The prior CP3a census already froze six CP3a contracts, so its successor gate is **298 = 292 + 6** rather than the pre-CP2b provisional 293.

CP3a remains semantically untouched in this closure. The required next turn is the separate static `M3-CP2b-ACCEPTANCE-CLOSEOUT-CP3a-REPLAN`, which must reconcile the old CP3a census/plan against the concrete accepted CP2b authority and freeze the exact bounded Code + Build surface before implementation begins.

## 6. Independent closure verification — 2026-08-21

The acceptance claim was re-derived from source and artifact evidence at closure, not accepted from
the closeout report. **VERIFIED.**

| Check | Result |
|---|---|
| Gate reached 292/292 across ten partitions at exact cardinality | **PASS** — predecessor 287/287, CP2b 5/5; GTest JSON census independently reports 292 tests / 0 failures / 292 unique identities |
| Selector unchanged | **PASS** — CP2b 5 `56f5443c…`, predecessor 287 `2caa0189…`, combined 292 `fc6bfc2b…`, all matching the frozen digests |
| Immutability | **PASS** — no checkout as authority, no configure/compile/rebuild/relink/repair/discovery/benchmark/mutation; package and materialized-source postflight byte-identical; `harness-postflight.txt` PASS |
| **H5 — product frozen** | **PASS, verified from source.** `git diff 9fdb928f…1d2417c9 -- src/ include/` is **empty**. The atlas was genuinely untouched across CB-R7/TB-R5. |
| **One-file surface** | **PASS, verified from source.** The tests diff is exactly `tests/FieldTransportAtlasTests.cpp`, +133/-3. |
| **H1 — re-derivation, not relaxation** | **PASS, verified in source.** `independent_face_gauge(...)` (`tests/FieldTransportAtlasTests.cpp:642-702`) computes the oracle's **own** per-face gauge; `:1316` forms `canonicalLift = sourceMeasurement.matching + firstGauge − secondGauge` from its own measurement; `:1322` applies its own canonical-orientation rule; `:1324` reduces mod 4. **No `rawGauge*` symbol is read anywhere in the tests** — the oracle never reads the product's gauge. |
| **H4 — congruence pinned without pinning representative choice** | **PASS, verified in source** (`:2506-2530`). A `+1` displacement (`++nonEquivalent.forwardLift`) must reject with `NonReciprocalAdjacency`; a `+4` displacement must be **accepted**. |
| **H3 — oracle still strict** | **PASS.** The tamper identity retains specific-code rejections for pairing tamper (`InvalidBranchTopology`), attachment tamper and duplicate identity (`InvalidSingularityPortAttachment`). The correction did not produce a permissive oracle. |
| Part F/G predictions | **CONFIRMED.** 5 incidences / 3 classes / expected 3; the two face-0 incidences share `startFace=(0,1,4)` and carrier `(0,1)`, use branches `2` and `3`, and sit in distinct classes `0` and `1`. |

**Note on the first closure claim.** CP2b was reported closed once before this record existed, when
the TB-R5 gate had been *triggered* but no result was recorded anywhere. That claim was rejected: a
control-plane commit is never runtime evidence, and no closure record was written and no per-turn
document retired until the gate result was supplied. The evidence above is what the second claim
supplied and what this verification checked. The durable rule is in `LESSONS.md` section 1.

