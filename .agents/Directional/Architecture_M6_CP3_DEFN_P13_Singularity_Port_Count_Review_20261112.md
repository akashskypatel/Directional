# RA-235 — Singularity port count, P13-e (BunnyRandom vertex 49)

Turn `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT`, Review agent only, runtime-free. RA-234 routed it.

Input: TB115's production census artifact `13960224847`, downloaded and verified (ZIP SHA-256 `51ddc7823fabb89c64ca86dd94252b83606d47e3945e0951c098dd1eea832ff7`, as in the TB115 report). I read its BunnyRandom log `raw/2.log`, where the atlas already writes its port partition to stderr.

## 1. What the log shows

BunnyRandom has seven singularities. Six partition correctly, for example vertex 47 (index +1: 3 classes from 4 incidences). Vertex 49 does not:

```text
FieldTransportAtlas.partition summary singularity=6 sourceVertex=49 topologyRegion=0 incidences=4 classes=4 expectedClasses=5
incidences: fan 0 branch 2, fan 2 branch 0, fan 4 branch 0, fan 6 branch 0 (one class each)
adjacency signed lifts around the 8-face fan: +1, +3, +1, 0, +1, 0, -1, 0  (sum 5)
```

## 2. The rule and why it can miss a port

The atlas finds a singularity's ports per fan face (`FieldTransportAtlas.cpp:564–660`). In each face, a branch is an incidence when its constant direction lies in the face's half-open wedge at the vertex. Incidences are then joined across radial edges by the transported branch, and the class count must equal `4 − index` (`:784`).

| # | Finding | Evidence |
|---|---|---|
| F1 | **The per-face count has the wrong parity.** Take ψ = field angle − ray angle as the ray sweeps around the vertex. It changes by −(4 − k)·90°, so a continuous field has a number of separatrices with the same parity as 4 − k. Here k = −1, so 4 − k = 5 is odd, and the atlas found 4. The index (−1) is consistent with the fan's lifts mod 4 (sum 5 ≡ 1) | Log lines above |
| F2 | **A face-wise constant field moves the missing separatrix onto an edge.** Within a face ψ falls monotonically, and every crossing of a multiple of 90° there is an incidence. Across a radial edge ψ jumps by the transport. A jump that passes a multiple of 90° is a separatrix lying on the edge itself, and no wedge contains it. The counts satisfy: in-face crossings = (4 − k) − (downward jump crossings) + (upward jump crossings). An odd in-face shortfall therefore means a jump crossed a multiple of 90° | Algebra on the rule at `:504–527` |
| F3 | **Two owners are possible, and the log cannot tell them apart.** **(i) A1's sector rule:** the field is legal (a valid piecewise-constant field with consistent matchings), and the rule cannot represent a port on a radial edge. **(ii) The transport lift:** the +3 across (49,109) could be a −90° jump written as its mod-4 equivalent, which would change which jump counts as a crossing. Deciding needs the branch directions in each fan face, which the log lacks | Log has lifts, no directions |
| F4 | **Remedies differ by owner.** Under (i), A1 needs edge ports: a separatrix starting along a radial edge, with a start face chosen by rule. Or the pre-A0 input conditioner (the only place allowed to change values, Amendment 20) rotates the faces at such a fan by the least amount that takes the jump off the edge direction. Under (ii), the lift representative is fixed in the atlas. Neither is a threshold change | DESIGN §4.8 (Amendment 20) |

## 3. Decision

Owner not yet named; measure first (RA-225: check a defect occurs before designing its cure). CB135 adds, inside the atlas's existing partition diagnostics, one line per fan face and branch with that branch's direction weights on the wedge's two far vertices and the predicate's own `inSector` verdict. It is a `std::clog` line only: no behaviour, digest or receipt changes.

## 4. CB135 — port direction census (compile only)

[Exact patch](Architecture_M6_CP3_CB135_P13_Singularity_Port_Direction_Census_Exact.diff): SHA-256 `fd9ccba26c722edfb75644083ae017c3896fe27bc0f138d90b935332f6c29996`, 39 lines, no single-space context lines. Numstat: `28 0` `src/authority/FieldTransportAtlas.cpp`. Base: HEAD `ca7586757` (CB134 source `c565a3ada` plus documentation).

Line format:

`FieldTransportAtlas.partition direction singularity=S fanIndex=i branch=b v<id>=<weight> v<id>=<weight> next=<id> inSector=<0|1>`

Mismatch → `M6-CP3-PLAN-P13-SINGULARITY-PORT-DIRECTION-CENSUS-STOP`; infrastructure → `M6-CP3-CB135A-P13-SINGULARITY-PORT-DIRECTION-CENSUS-ORCH`.

## 5. TB116 — full gate and census

`M6-CP3-TB116-P13-SINGULARITY-PORT-DIRECTION-CENSUS-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB116_P13_Singularity_Port_Direction_Census_Full_Gate_Case_Manifest.tsv`: TB115's byte for byte, 945 rows, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, membership 1,026, `SELF_CHECK_PASS cases=945 deferred=81`. The production census runs as before.

**MATCH needs all of:**
- 945/945.
- Census verdicts unchanged: Cylinder PASS, BunnyRandom and Vase registered RED.
- Every receipt line TB115 recorded byte-identical, including the existing `FieldTransportAtlas.partition summary/incidence/adjacency` lines.
- BunnyRandom's census log contains `partition direction singularity=6` lines for fan faces 0–7. Among them, `inSector=1` holds on exactly (fan 0, branch 2), (fan 2, branch 0), (fan 4, branch 0) and (fan 6, branch 0), the four existing incidences.
- Those lines are recorded verbatim in the report.

Every other line is evidence.

Mismatch → `M6-CP3-TB116-P13-SINGULARITY-PORT-DIRECTION-CENSUS-FULL-GATE-REV`; infrastructure → `M6-CP3-TB116A-P13-SINGULARITY-PORT-DIRECTION-CENSUS-ORCH`. On MATCH close with `Successor: M6-CP3-DEFN-P13-SINGULARITY-PORT-OWNER`.

## 6. Follow-on — `M6-CP3-DEFN-P13-SINGULARITY-PORT-OWNER` (Review agent only)

From the vertex-49 direction lines and lifts it decides:
- whether a jump at a radial edge passes the edge direction (owner (i), A1's rule);
- or whether a lift representative is wrong (owner (ii)).

It then freezes the fix with an exact model of vertex 49's fan.

## 7. Sequence

| Step | Turn | Owner |
|---|---|---|
| P13-e.0 **COMPLETE** | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (this record) | Review |
| P13-e.1 | `M6-CP3-CB135-P13-SINGULARITY-PORT-DIRECTION-CENSUS` (§4) | implementation agent |
| P13-e.2 | `M6-CP3-TB116-P13-SINGULARITY-PORT-DIRECTION-CENSUS-FULL-GATE-EXEC` (§5) | implementation agent |
| P13-e.3 | `M6-CP3-DEFN-P13-SINGULARITY-PORT-OWNER` (§6) | **Review agent only** |
| then | 65A → 65B → 65C (O41, switch activation) → 65D; O31/O32 in parallel | Review, then implementation |

**Gaps, stated.**
- The parity argument shows a separatrix is missing; it does not say where.
- The direction weights are printed as doubles from exact rationals, which is enough for signs and order but is not bit-exact.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB116 = TB115 manifest byte for byte; selector497/CP3 unpromoted |
| Decisive claims re-derived | The port-collection loop, the half-open sector predicate, the class union and the count check were read by me. Vertex 49's log lines come from the verified TB115 artifact |
| Runtime-free checks | `-fsyntax-only` returns 0 on `FieldTransportAtlas.cpp` with CB135; CB135 applies at HEAD; manifest self-check passes. The artifact was read with `unzip`/`grep` in its own scratch directory |
| Non-vacuity | The four `inSector=1` positions must equal the existing incidences, so a misindexed weight goes to REV |
| Obligations carried | P13-e.1–P13-e.3; 65A–65D (O41, activation in 65C); O31; O32b–e; O33; D6 user decision pending; O34 (narrowed); O30b |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB115 945/945, membership 1,026 |
| Turn boundary | No product or test source changed in the repository |
