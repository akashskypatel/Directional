# M3-CP4c-3-CB34 — Code + Build Report

**Turn:** `M3-CP4c-3-CB34`
**Disposition:** **IN PROGRESS / PRODUCT + TEST EDIT PREPARED / COMPILE PENDING / RUNTIME NOT EXECUTED**
**Frozen owner:** CM9 + CN7 from `Architecture_M3_CP4c3_TB28_R3_Independent_Review_Record.md`.

## 1. Resume authority

CB34 resumed the interrupted Code + Build turn rather than starting a new turn.

- recovered WIP commit: `1b3ca3394033569f6ffc28f223dc04afce1b481b`;
- pre-resume branch head: `6cce83978ffc85e8e4072a0ce647e425800c543b`;
- exact resume snapshot source: `353c5c3e2d37d0eddefc2d8e8b0fc296d94c598d`;
- source-snapshot run/artifact: `34000881754 / 9979446955`;
- snapshot artifact SHA-256: `51a80ae4381417ec1f863a3a3fbfa4aa2b9dc771004092435d9acbceb8db37bc`;
- snapshot archive metadata names the exact source above and verifies 5,217 source files;
- no Directional runtime, test, benchmark, discovery command, or local build has executed in CB34.

The source-snapshot read mode was mandatory. A procedural miss occurred before the verified resume snapshot was
materialized: several small connector reads were used to recover the already-preserved WIP and mandatory policy
context. Once identified, source inspection switched to the verified exact snapshot and all substantive static
inspection thereafter used the local snapshot. This does not alter semantic bytes or evidence, but is retained as
turn evidence under `TOOL_USE_CONSERVATION_POLICY.md`.

## 2. Frozen separating-arc correction

The WIP product edit is retained exactly at the frozen owner seam,
`build_source_face_ownership`.

For a trace arc whose forward and reverse darts belong to different certified face-walk orbits,
`separatesCertifiedFaces = forwardOrbit != reverseOrbit`. A terminal segment now follows the already-existing
trace-cut/carrier-barrier path when that predicate is true. A terminal segment still takes the old
`TerminalSlit` exclusion when the two dart orbits are equal.

This is the one product correction authorized by CM9. No attribution rule, seed winner, partition rule,
`proves_cellularity()` contract, accepted identity, or existing selector byte is changed.

### Accepted-prefix safety by construction

The edit changes only one branch condition:

- non-terminal segments already entered the trace-cut/carrier-barrier path and remain byte-for-byte on that path;
- terminal segments with equal dart orbits still take the old `TerminalSlit` exclusion;
- terminal segments with unequal dart orbits are the only newly admitted cases;
- trace-not-found, invalid-segment-range, out-of-range-dart, and missing-face branches are unchanged.

The immutable TB28-R3 ownership evidence enumerates the mechanical trace arcs:

| Arc | Trace | Terminal slit | Dart orbits | CB34 effect |
|---:|---:|---|---|---|
| 14 | 0 | yes | `0 / 1` | newly trace-cut/barrier |
| 15 | 1 | no | `0 / 0` | unchanged; already processed |
| 16 | 2 | yes | `2 / 3` | newly trace-cut/barrier |
| 17 | 3 | yes | `2 / 1` | newly trace-cut/barrier |
| 18 | 4 | yes | `0 / 4` | newly trace-cut/barrier |
| 19 | 5 | no | `0 / 0` | unchanged; already processed |
| 20 | 6 | yes | `0 / 0` | unchanged terminal slit |
| 21 | 7 | yes | `2 / 5` | newly trace-cut/barrier |
| 22 | 8 | yes | `0 / 3` | newly trace-cut/barrier |
| 23 | 9 | yes | `0 / 5` | newly trace-cut/barrier |
| 24 | 10 | yes | `0 / 0` | unchanged terminal slit |
| 25 | 11 | yes | `2 / 4` | newly trace-cut/barrier |

For the four interior arcs of the failing plan component specifically, the newly affected terminal-slit faces are
arc 14 face `28,29,35` and arc 22 face `10,79,151`; the equal-orbit terminal-slit faces on arcs 20 and 24 remain
excluded exactly as before.

## 3. Required selector 408 witness

CB34 appends only:

`SurfaceCutGraph.SeparatingArcBarrierRuleExcludesCrossedFacesFromUncutCensus`

to frozen selector 407.

- selector 407 remains **407 identities**, LF SHA-256
  `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`;
- selector 408 is **408 identities**, LF SHA-256
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- selector 407 is an exact byte/identity prefix of selector 408;
- the new identity asserts census effects and preservation of equal-orbit terminal slits; it predicts no owner.

`selector_manifest.py` was corrected only so its mandatory regeneration is additive: existing hand-authored
per-selector authority notes are retained instead of being deleted by regeneration. This changes no selector byte
and no Directional product/test behavior.

## 4. CN7 — retained transcription of the 191-face ownership evidence

This section transcribes existing immutable TB28-R3 runtime evidence from diagnostic-log artifact
`9978114502`, whose downloaded artifact SHA-256 was verified as
`bad7431f68be53da770069ad48cabb0033ffeb02a2dde94c6a06ba8b47e9a994`.
No runtime or new diagnostic was used to produce this section.

### 4.1 Failing component and comparison-census identities

**Failing plan component**

- component: `0`;
- domain: `EmptyFragmentOrbits`;
- face count: **191**;
- face-set digest: **`17919102493633069558`**;
- seed count/state: **3 / `Multiple`**;
- fragment-owner seed orbits: **`[0,1,3]`**;
- certified-face multiset: orbit `0` on 191 source faces, orbit `1` on 191 source faces, orbit `3` on 191 source faces.

**Published comparison census**

- component: `0`;
- domain: `NotTraceCut`;
- face count: **214**;
- face-set digest: **`7937364815223192706`**;
- failing component matches census component: **false**;
- failing component is a subset of census component: **true**;
- published seed-attribution rows: **46**.

The two component ids are both numerically zero but belong to different partition domains and different face sets.
They must not be conflated.

### 4.2 Interior-arc rows published for the failing plan component

| Row | Arc | Dart orbits | Crossed source faces |
|---:|---:|---|---|
| 0 | 14 | `0 / 1` | `8,10,11`<br>`9,11,17`<br>`16,17,23`<br>`22,23,29`<br>`28,29,35` (certifier=0; plan=0; reason=TerminalSlit) |
| 1 | 20 | `0 / 0` | `36,38,39` (certifier=0; plan=0; reason=TerminalSlit)<br>`39,40,41`<br>`41,42,43`<br>`43,44,45`<br>`45,46,47` |
| 2 | 22 | `0 / 3` | `10,79,151` (certifier=0; plan=0; reason=TerminalSlit)<br>`45,47,73`<br>`73,75,148`<br>`75,77,149`<br>`77,79,150` |
| 3 | 24 | `0 / 0` | `66,67,120` (certifier=0; plan=0; reason=TerminalSlit)<br>`67,68,124`<br>`68,69,128`<br>`69,70,132`<br>`70,71,92` |

Thus arcs **14** (`0 / 1`) and **22** (`0 / 3`) separate certified face-walk orbits, while arcs **20** and **24**
have equal dart orbits (`0 / 0`). The `TerminalSlit` miss reason appears on the terminal crossed face for each of
these four rows in the pre-CB34 evidence.

### 4.3 Published comparison-census seed attributions

These are the 46 explicit `m3Cp4c3UncutComponentSeedAttribution` rows published for the `NotTraceCut` census
component that contains the 191-face failing component as a strict subset. They are retained here because CN7
requires the seed attributions to be available outside the artifact.

| Row | Source edge | Component face | Opposite face | Orbit | Rule |
|---:|---|---|---|---:|---|
| 0 | `0-1` | `0,1,2` | `0,1,102` | 0 | `SingleFaceOwner` |
| 1 | `1-4` | `1,4,5` | `1,4,139` | 0 | `SingleFaceOwner` |
| 2 | `1-102` | `1,102,139` | `0,1,102` | 0 | `SingleFaceOwner` |
| 3 | `4-6` | `4,6,7` | `4,6,143` | 0 | `SingleFaceOwner` |
| 4 | `4-139` | `4,139,143` | `1,4,139` | 0 | `SingleFaceOwner` |
| 5 | `6-8` | `6,8,9` | `6,8,147` | 0 | `SingleFaceOwner` |
| 6 | `6-143` | `6,143,147` | `4,6,143` | 0 | `SingleFaceOwner` |
| 7 | `8-147` | `8,147,151` | `6,8,147` | 0 | `SingleFaceOwner` |
| 8 | `9-11` | `8,9,11` | `9,11,17` | 0 | `EdgeSideOwner` |
| 9 | `10-79` | `10,79,151` | `10,11,79` | 3 | `EdgeSideOwner` |
| 10 | `10-151` | `10,79,151` | `8,10,151` | 0 | `SingleFaceOwner` |
| 11 | `16-17` | `9,16,17` | `16,17,23` | 0 | `EdgeSideOwner` |
| 12 | `22-23` | `16,22,23` | `22,23,29` | 0 | `EdgeSideOwner` |
| 13 | `24-32` | `24,26,32` | `24,30,32` | 0 | `SingleFaceOwner` |
| 14 | `25-30` | `24,25,30` | `25,30,31` | 0 | `SingleFaceOwner` |
| 15 | `26-33` | `26,27,33` | `26,32,33` | 0 | `SingleFaceOwner` |
| 16 | `27-34` | `27,28,34` | `27,33,34` | 0 | `SingleFaceOwner` |
| 17 | `28-35` | `28,29,35` | `28,34,35` | 0 | `SingleFaceOwner` |
| 18 | `29-35` | `28,29,35` | `29,35,91` | 1 | `EdgeSideOwner` |
| 19 | `30-31` | `30,31,119` | `25,30,31` | 0 | `SingleFaceOwner` |
| 20 | `30-32` | `30,32,123` | `24,30,32` | 0 | `SingleFaceOwner` |
| 21 | `32-33` | `32,33,127` | `26,32,33` | 0 | `SingleFaceOwner` |
| 22 | `33-34` | `33,34,131` | `27,33,34` | 0 | `SingleFaceOwner` |
| 23 | `34-35` | `34,35,135` | `28,34,35` | 0 | `SingleFaceOwner` |
| 24 | `35-135` | `34,35,135` | `35,95,135` | 0 | `EdgeSideOwner` |
| 25 | `39-41` | `39,41,140` | `39,40,41` | 0 | `SingleFaceOwner` |
| 26 | `40-41` | `40,41,42` | `39,40,41` | 0 | `SingleFaceOwner` |
| 27 | `41-43` | `41,43,144` | `41,42,43` | 0 | `SingleFaceOwner` |
| 28 | `42-43` | `42,43,44` | `41,42,43` | 0 | `SingleFaceOwner` |
| 29 | `43-45` | `43,45,148` | `43,44,45` | 0 | `SingleFaceOwner` |
| 30 | `44-53` | `44,52,53` | `44,46,53` | 0 | `EdgeSideOwner` |
| 31 | `52-59` | `52,58,59` | `52,53,59` | 0 | `EdgeSideOwner` |
| 32 | `58-65` | `58,64,65` | `58,59,65` | 0 | `EdgeSideOwner` |
| 33 | `64-71` | `64,70,71` | `64,65,71` | 0 | `EdgeSideOwner` |
| 34 | `67-68` | `61,67,68` | `67,68,124` | 0 | `SingleFaceOwner` |
| 35 | `68-69` | `62,68,69` | `68,69,128` | 0 | `SingleFaceOwner` |
| 36 | `68-124` | `68,124,128` | `67,68,124` | 0 | `SingleFaceOwner` |
| 37 | `69-70` | `63,69,70` | `69,70,132` | 0 | `SingleFaceOwner` |
| 38 | `69-128` | `69,128,132` | `68,69,128` | 0 | `SingleFaceOwner` |
| 39 | `70-71` | `64,70,71` | `70,71,92` | 0 | `SingleFaceOwner` |
| 40 | `73-148` | `45,73,148` | `73,75,148` | 0 | `EdgeSideOwner` |
| 41 | `75-149` | `75,148,149` | `75,77,149` | 0 | `EdgeSideOwner` |
| 42 | `77-150` | `77,149,150` | `77,79,150` | 0 | `EdgeSideOwner` |
| 43 | `93-132` | `93,132,133` | `92,93,132` | 0 | `EdgeSideOwner` |
| 44 | `94-133` | `94,133,134` | `93,94,133` | 0 | `EdgeSideOwner` |
| 45 | `95-134` | `95,134,135` | `94,95,134` | 0 | `EdgeSideOwner` |

The failing component's own ownership summary independently records `seedOrbits=[0,1,3]` and `seedState=Multiple`.
The table above belongs to the distinct `NotTraceCut` census object and is retained with that domain label to avoid
repeating the off-object-evidence error documented in `LESSONS.md` 126 and 131.

## 5. Static verification

Pending final pre-push static verification. No compile result is claimed in this draft.

## 6. Compile evidence

Pending. CB34 may compile only the exact pushed semantic source through
`.github/workflows/agent-compile-reusable.yml`, with GMP/GMPXX linked and `runtimeExecution=false`.

## 7. Successor

Pending successful compile. The next turn will be artifact-only Test + Benchmark execution of selector 408; CB34
does not execute it.
