# M3 CP4ab Closure Record — global topology plan and per-region disc authority

Date: 2026-08-24 UTC
Status: **`M3-CP4ab` CLOSED / ACCEPTED at 316/316.**

This is the consolidated closure record for the merged CP4a/CP4b checkpoint after the mandatory rescope. It does not replace the binding DEFN amendments or independent-review decisions; it records what was finally accepted, what it proves, and what remains for CP4c.

## 1. Closure verification

| Check | Result |
|---|---|
| Accepted semantic source is the CB-R11 package source | PASS — `157bf784a9cdd2765018206ae0ac26729ed7a584` |
| Immutable package identity/digest preserved | PASS — `9527801615`, `a8e03a21…54557` |
| Package manifest before/after runtime | PASS — 27/27 both times |
| Five packaged source-status snapshots | PASS — all empty |
| Exact source archive before/after runtime | PASS — `498cbb58…ab157`, unchanged |
| Frozen predecessor selector | PASS — 304 unique at `c05a4c43…b666` |
| Frozen CP4ab selector | PASS — 12 unique at `7e7e32f1…34ec` |
| Cumulative selector | PASS — 316 unique at `601ce2b6…0193c` |
| Accepted predecessor surface | PASS — 304/304 |
| CP4ab surface | PASS — 12/12 |
| Cumulative acceptance gate | **PASS — 316/316** |
| Configure/build/relink/repair/discovery in TB-R3 | PASS — none executed |
| Source/test/fixture/selector/package mutation in TB-R3 | PASS — none |

**Closure claim: VERIFIED.**

### 1a. Independent verification, 2026-08-24

The table above is the closing turn's self-report. It was re-verified independently against GitHub's
API and the repository, not accepted as written.

**From the GitHub Actions API:**

| Check | Result |
|---|---|
| Run `32758293793` exists, is "Agent M3 CP4ab TB-R3 Execution", on the working branch | PASS — `conclusion: success` |
| Result artifact `9531769503` digest | PASS — `sha256:1b4b3784d55f398d113b18c5bc84543cad9f03c48d329d91005598d63ed801fc`, exact match |
| Log artifact `9531770393` digest | PASS — `sha256:cff83f726fd9fa6dc762126a3632178e0d94abd3d17f4e57b287d0738cd69643`, exact match |
| Package `9527801615` provenance | PASS — it is `m3-cp4ab-cb-r11-result-32747790694`, digest `sha256:a8e03a21…54557`, exact match |

**From the job log of `97530833220`** (the machine JSON emitted by the run itself):
`gate.required=316 / executed=316 / failures=0`; `acceptedPredecessor 304/304/0`; `cp4ab 12/12/0`;
`orchestrationErrors=0`; `configure/build/relink/repair/generatedDiscovery` all `false`;
`sourceMutation/testMutation/fixtureMutation/selectorMutation/packageMutation` all `false`;
`package_zip_post_sha256` and `source_archive_post_sha256` equal to their preflight values;
`manifest_post_count=27`; `sourceCommit=157bf784a9cdd2765018206ae0ac26729ed7a584`.

**From the accepted source tree at `157bf784`** — the check that matters most, because a green gate
proves the package passed, not that it implements what the binding Review required. All four V-series
semantic corrections are present:

| Measure | Verified at |
|---|---|
| V1 — `validate_single_boundary_walk` hoisted above `region_orbit` inside `build_region_certificates`, both call sites covered | `GlobalTopologyPlan.cpp:2440` before `:2444`; defensive call retained at `:2115` |
| V2 — canonical candidate hoisted once, ownership comparison under the id+boundary guard that keeps B3 green | `GlobalTopologyPlan.cpp:2686-2747`, guard variable `canonicalRegionBoundaries` |
| V4 — B4 Euler identity excludes exterior orbits | `tests/FieldAlignedCurveNetworkTests.cpp:1896-1900`, subtracts `partition->exteriorOrbits.size()` |
| V5 — B4 publishes a typed failure reason instead of a bare bool | `IndependentDiscProofResult independent_disc_proof_oracle(...)` at `:1879`; test prints `embedded_graph_chi` at `:2398` |

**Independent verdict: the closure claim is correct.** The gate is real, the artifacts are the ones
named, the package is the one built from the accepted commit, and the accepted source implements the
binding corrective measures rather than merely passing.

### 1b. Consolidation defect found and repaired at closure review

The closing turn retired **34** CP4-era per-turn documents (~6,300 lines) into this record. The
retirement itself is sound — the content that remained load-bearing had already been inlined into
`Architecture_M3_CP4_DEFN_Frozen_Definitions.md` amendments 1–12, which were re-read and confirmed
self-contained. Two defects were introduced and are repaired at this review:

1. **Twelve normative attribution lines in DEFN, and two in the M3 Code + Build Plan, cited retired
   documents without saying they were retired.** A future agent following `binding)` would find no
   file. Each is now annotated as retired-provenance; no amendment content changed.
2. **Every current routing pointer named "section 4A.3c", which has never existed.** CP4c's content
   was the `#### M3-CP4c` subsection of §4A.3 — a scope statement, not a decomposition. Routing now
   points at `M3_CP4c_Consolidated_Record.md`.

### 1c. Final CP4ab per-turn report retirement — 2026-08-31

`M3_CP4ab_Closure_Record.md` was the last remaining CP4ab
per-turn report. It is now retired into this closure record; its authoritative acceptance facts were already
represented in §§1–2 and are unchanged. The remaining non-duplicated provenance from that report is retained here:

- schema validation run/job `32758229076 / 97530617094` passed before acceptance execution;
- the frozen selector hashes were predecessor 304 `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`,
  CP4ab 12 `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec`, and cumulative 316
  `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- the package source archive was materialized without stripping its recorded root layout, the known plane fixture
  was present, and fresh pre/post-runtime extractions were byte-identical with zero-byte source diffs;
- the report recorded one process-only ordering miss: connector schema discovery preceded the mandatory tool-use
  policy read, but no repository inspection, runtime, semantic mutation, or acceptance authority was affected.

The retired report's exact bytes remain recoverable from Git history. No current or future authority points to it.

## 2. Accepted immutable authority

- semantic source: `157bf784a9cdd2765018206ae0ac26729ed7a584`
- immutable package: `9527801615`
- package ZIP SHA-256: `a8e03a2181ab4ce2de7386d6b38d66cd361a739f21aa33dde6091a6a2fa54557`
- source archive SHA-256: `498cbb586c8b5dd1d49c3442364b9483d9f04e6d999432a93e72caa9cb4ab157`
- compile/package run/job: `32747790694 / 97497441516`
- acceptance run/job: `32758293793 / 97530833220`
- acceptance result artifact: `9531769503`, SHA-256 `1b4b3784d55f398d113b18c5bc84543cad9f03c48d329d91005598d63ed801fc`
- execution log artifact: `9531770393`, SHA-256 `cff83f726fd9fa6dc762126a3632178e0d94abd3d17f4e57b287d0738cd69643`
- cumulative gate: **316/316 PASS**
- acceptance cost: **1 of 3**, green
- final diagnostic cost before acceptance: **1 of 2**

## 3. What CP4ab delivers

CP4ab establishes the production A2b global topology-plan layer on the accepted A1/A2a network authority:

1. regions are faces of the embedded network graph rather than an unrelated source-face partition;
2. the published rotation system is consistent with typed network events;
3. every source face has exactly one canonical region owner under the reviewed fragment model;
4. mandatory source boundary and hard-feature topology is preserved;
5. region authority is invariant to enumeration order and equivalent branch relabeling;
6. every emitted region carries a checked disc certificate with a single boundary walk, connected fragment interior, correct bounded-surface Euler relation, and no forbidden interior singularity;
7. independent test authority recomputes the disc proof rather than mirroring the production validator;
8. ownership, boundary-walk, Euler/interior-singularity, certificate, network-binding, and unestablished-transport tamper surfaces reach typed owning validators.

The accepted corrections preserve the binding K2R/K3R fragment ownership, reviewed fragment adjacency, pinch rejection, fan-anchored port order, and validation ordering. The final B4 oracle uses the bounded-surface relation with exterior orbits excluded rather than the withdrawn capped-surface formula.

## 4. What CP4ab does not claim

CP4ab does **not** close M3. It does not add or accept the two representative CP4c witnesses, does not prove the six C identities, and does not run the 322 exit gate. It also does not repair or claim progress on downstream `G4-B001`, `G4-B002`, `G4-B003`, or `G4-B004` product blockers.

CP4c remains responsible for:

- **wiring `GlobalTopologyPlan` into the production entry path** — established at this review and not
  previously recorded anywhere: `GlobalTopologyPlan` is constructed **nowhere** in
  `src/pipeline/RemeshPipeline.cpp`. A2a is wired (`:6587`, published at `:6604-6605`); A2b is not, and
  no product slot for it exists. C1/C2's "…ThroughProductionEntryPath" is therefore not satisfiable
  today by fixtures alone;
- the periodic/torus-style production M3 witness;
- the feature-bearing mechanical-style production M3 witness;
- carried CP3b rotation-system/face-walk consistency and crossing-tamper obligations;
- the six frozen C1–C6 identities;
- the cumulative **322 = 316 + 6** M3 exit gate.

CP4c's decomposition is `M3_CP4c_Consolidated_Record.md`.

## 5. Regression closure

`PR8-R042 / M3-CP4b-R001` (`RP-01 / AUTHORITY_DOMAIN_CONFLATION`) is **RESOLVED STABLE** at this gate. The same accepted-predecessor A identities that had regressed are green under the cumulative 316 acceptance surface. Focused DG evidence alone did not close the event; TB-R3 does.

Stable accounting remains **42 events / 14 categories / 28 recurrences** and produced-witness debt remains **5**. Resolution changes status, not historical event totals.

## 6. Cost and trajectory

The merged checkpoint required multiple review/correction arcs because the original CP4a/CP4b split, whole-component ownership, fragment-disc proof, Euler reduction, singularity-port ordering, barrier terminus representation, validation ordering, and independent-oracle boundary arithmetic each had to be corrected without weakening the frozen acceptance contracts.

Final cumulative M3 package count is **34** at CP4ab closure. The final accepted package is CB-R11 `9527801615`; TB-R3 consumes acceptance attempt 1/3 and no new package. The final reset diagnostic window consumed one gate at DG-R6.

With CP4ab accepted, A2b's region/disc-authority portion is complete. The exact next bounded turn is `M3-CP4c-CB`; CP4c has its own untouched 3-attempt budget and its planned diagnostic gate.

---

## Folded document index — DURABLE, DO NOT DELETE

The 35 per-turn CP4ab documents below were folded into this closure record in an earlier consolidation. On **2026-09-03** every remaining reference to them across the project was redirected here, so their names no longer appear as live pointers. This index keeps the mapping legible; the full text of each remains in git history (`git log --diff-filter=D -- .agents/Directional/<name>`).

- `Architecture_M3_CP4ab_CB_R5_Package_Independent_Review.md`
- `Architecture_M3_CP4ab_CB_R6_Static_Authority_Independent_Review.md`
- `Architecture_M3_CP4ab_CB_R6_Static_Authority_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_CB_R7_Precondition_Independent_Review.md`
- `Architecture_M3_CP4ab_CB_R8_S0_Independent_Review.md`
- `Architecture_M3_CP4ab_CB_R8_S0_Static_Precondition_Stop_Report.md`
- `Architecture_M3_CP4ab_DG_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4ab_DG_R2_Independent_Review.md`
- `Architecture_M3_CP4ab_DG_R3_Artifact_Only_Diagnostic_Report.md`
- `Architecture_M3_CP4ab_DG_R3_Independent_Review.md`
- `Architecture_M3_CP4ab_DG_R3_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_DG_R4_Artifact_Only_Diagnostic_Report.md`
- `Architecture_M3_CP4ab_DG_R4_Independent_Review.md`
- `Architecture_M3_CP4ab_DG_R4_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_DG_R5_Artifact_Only_Diagnostic_Report.md`
- `Architecture_M3_CP4ab_DG_R5_Independent_Review.md`
- `Architecture_M3_CP4ab_DG_R5_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_DG_R6_Artifact_Only_Diagnostic_Report.md`
- `Architecture_M3_CP4ab_K5_Routing_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_R10_Terminal_Zero_Cell_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R11_Validation_Ordering_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R2_Code_Build_Plan.md`
- `Architecture_M3_CP4ab_R2_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R3_Code_Build_Plan.md`
- `Architecture_M3_CP4ab_R4_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R5_Instrumentation_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R6_Static_Authority_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R7_Cyclic_Port_Order_Code_Build_Plan.md`
- `Architecture_M3_CP4ab_R7_Cyclic_Port_Order_Code_Build_Report.md`
- `Architecture_M3_CP4ab_R9_Mandatory_Arc_Split_Code_Build_Report.md`
- `Architecture_M3_CP4ab_TB_R1_Independent_Review.md`
- `Architecture_M3_CP4ab_TB_R2_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4ab_TB_R2_Independent_Review.md`
- `Architecture_M3_CP4ab_TB_R2_Independent_Review_Plan.md`
- `Architecture_M3_CP4ab_TB_R3_Artifact_Only_Test_Benchmark_Report.md`
