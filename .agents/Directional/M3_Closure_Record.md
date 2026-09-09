# M3 Closure Record — Field-Aligned Curve Network

**Status:** **CLOSED / ACCEPTED** at `M3-CP4c-3-TB48-REV`.
**Reviewed semantic runtime authority:** package113 source `6dae3f6959551f6dcdd81f153aedb5f38411a96b`, selector409 runtime `34409262512 / 102659650326` — **405 PASS / 4 RED / 0 SKIP**, accepted required-green prefix **365/365**, RED `[368,369,374,398]`.
**Runtime artifacts:** result `10126711178` SHA-256 `07961a2339204b80f83feac8916e93578176363f9bdf0317ea85bdc095de5747`; log `10126711588` SHA-256 `1aab2f5f9b0d23f41ffd04a1467894f572604774ee2ee6ce9e42ee4b8f6dbd7d`.
**Accepted required-green selector entering M4:** **365**, LF SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.
**Stable accounting at closure:** **47 events / 14 categories / 33 recurrences**; produced-witness debt **5**; ownership **300/0/0**; packages **113**.

This is the durable milestone-level closure record for M3. CP4c historical detail remains in
`M3_CP4c_Consolidated_Record.md`; normative CP4c definitions remain in `M3_CP4c_Frozen_Definitions.md`.

## 1. What M3 required

`DESIGN.md` §14 M3 requires a typed authoritative `FieldAlignedCurveNetwork` derived by combinatorial tracing and a
`GlobalTopologyPlan` that consumes it rather than assuming regions. Acceptance requires singularity-port ownership,
branch-consistent/non-crossing traces, typed terminal events, disc-topology proof for emitted regions, mandatory
network topology under tamper, and tracing/start-port permutation invariance.

## 2. Checkpoint trajectory

M3 closed through the accepted CP1/CP2/CP2b/CP3a/CP3b/CP4ab chain, then the CP4c decomposition:

- **CP4c-0:** exact resolved interval continuation and exact position/direction authority;
- **CP4c-0b:** typed trace termination/contact authority;
- **CP4c-1:** diagnosability and witness/event observability;
- **CP4c-2:** closed/higher-genus actual-embedded-graph `SurfaceCutGraph` and region/disc authority; accepted required-green prefix **365**;
- **CP4c-3:** mechanical closed-surface A1/continuation witness under restored **AU0–AU9**, with selector409 used as a broader audit/report-only execution surface.

### 2.1 CP4c-0's basis, recorded explicitly

`M3-CP4c-0` never ran the `M3-CP4c-0-TB-R9` turn its own roadmap row named as its gate. **Its acceptance is carried
by cumulative gate inclusion**, which is the roadmap's own stated rule — *"every checkpoint carries the full accepted
predecessor selector plus its own frozen identities."* CP4c-0's gate **346** is a strict prefix of **353**
(CP4c-0b), **355** (CP4c-1) and the accepted **365** (CP4c-2), each of which closed green. Every CP4c-0 identity
therefore lies inside the accepted prefix that has been continuously green since CP4c-2, and `TB-R9` — which would
have executed gate 346 — was superseded by three later gates closing on strict supersets of it.

This basis is recorded rather than inferred because the alternative reading is that a closed milestone contains an
open checkpoint. **`M4-DEFN` must confirm it before consuming the 365 baseline**: that no CP4c-0 identity is absent
from 365, and that Q8 criteria 1, 4 and 5 assert nothing no later gate re-executes. If either fails, M3 closure is
premature and reopens.

The final CP4c-3 review is `Architecture_M3_CP4c3_TB48_Independent_Review_Record.md`.

## 3. Why a 405/4 runtime can close M3

The four RED rows are not silently accepted. CP4c-3's frozen exit condition is explicitly **the mechanical witness
under AU0–AU9**, while the checkpoint domain separately lists inherited sphere/quality/fixture debt. The final
mechanical surface is green: 365/365 accepted prefix, 366/367 green, protected 390/393/406/407 non-vacuously green,
full 409-row report-only coverage after first RED, and all exactness/reportability prohibitions preserved.

The final targeted debt inside the closure hygiene path, ordinal370, also becomes PASS on package113 under the frozen
typed `EmptyNetworkOnClosedSurface = 6` plus `sourceFace` locus identity. The four remaining rows retain their own
owners and future schedules:

- 368 prescribed-sphere event-position binding;
- 369 ordinary proposal saturation/quality;
- 374 folded-cone invalid fixture/precondition;
- 398 downstream of 368.

They remain visible and red; they do not redefine M3's frozen exit criterion.

## 4. Final evidence

Package113 is byte-immutable across TB48. Root package authority, selector and harness hashes match the frozen plan;
all 409 identities execute once in fresh processes; selection mismatch and timeout counts are zero; package/source/
execution-view pre/post censuses match; no configure/compile/relink/discovery/repair/mutation/benchmark path runs.

Ordinal370's frozen test constructs an atlas-valid closed torus with a truly empty network and directly asserts the
existing typed error plus a non-empty source-face locus. Static package113 source has exactly the corresponding early
product branch in `SurfaceCutGraph::canonical_candidate()` after binding checks and before cut classification.

## 5. Declared limitations carried forward

M3 closure is not a production-ready claim. It does not discharge:

1. `G4-B002` shared positive rail scheduling or its three produced-witness re-proofs — **M4**;
2. `G4-B003` nonzero periodic Z4 production or its two produced-witness re-proofs — **M5**;
3. the prescribed-sphere 368/398 defect, proposal-quality 369, or folded-cone 374 fixture debt;
4. production-scale/sliver/high-valence/conditioning coverage — `M4-CP-COND` / `M4-CP-SCALE` proposals to be reconciled at M4-DEFN;
5. representative Bunny/Vase quality/resource acceptance, later milestone authority, or M7 disposition re-proof.

## 6. Accounting

Package113/TB48 is promoted as reviewed runtime authority. `M3-CP4c2-TB-X2-R8-CAND-02` and
`M3-CP4c3-TB48-EXEC-CAND-01` close non-stably; closure changes status but does not decrement or add historical
stable counts. Totals remain **47 / 14 / 33**, debt **5**, ownership **300/0/0**, packages **113**.

## 7. Exact successor

**`M4-DEFN`**, planning-only and runtime-free, under `Architecture_M4_DEFN_Definition_Plan.md`.
