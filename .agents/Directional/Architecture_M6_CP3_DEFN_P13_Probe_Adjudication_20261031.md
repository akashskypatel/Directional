# RA-188 — P13 probe adjudication: three deferred rows, three causes (2026-10-31)

**Turn:** `M6-CP3-DEFN-P13-PROBE-ADJUDICATION` (DEFN, Review track). It reviews `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` ([P13 decision](Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Decision_20261031.md)) and replaces its unstarted successors.
- **Method:** scratch probes are diagnostic only and carry no gate authority (RA-165.2 F1, RA-166.6 F6). They ran on a local macOS arm64 build of `e1fd0e4b…`, which equals HEAD in `src`, `include`, `tests`, `benchmarks`, `CMakeLists.txt` and `cmake` (the CB63 semantic source), at default arithmetic, with one fixture per process. TB63's census is the Linux confirmation.

## RA-188.1 Review of the P13 decision

**Upheld:**
- The TB62/CB63 audit, the frozen hashes, membership 945 and the stable accounting.
- No gate runtime or acceptance inside a DEFN.
- The six-fixture contract summary.
- The O6 branch exists as stated (`SurfaceCellTracing.cpp:17208`).

**Defects:**

| # | Defect | Effect |
|---|---|---|
| D1 | All three deferred dispositions come from the pre-CB55 TB50C census. None was re-observed at current source. | The matrix is stale: each row now has a different first failure (RA-188.2). |
| D2 | It read "runtime-free" as forbidding Review scratch probes. RA-165.2 F1 and RA-166.6 F6 require them whenever a disposition rests on one; what "runtime-free" excludes is gate runtime and acceptance. | It turned a three-minute probe into a CB+TB cycle. |
| D3 | It froze CB64 to give the frozen P8 harness (`78b8002c…`) a 300 s cap. P8 already runs OBSERVE-only censuses (a separate manifest with no ledger, 600 s cap). | An unnecessary harness edit. A 300 s cap is also below unpatched Cylinder's Linux runtime (>600 s), so the census was certain to come back ABNORMAL with no information. |
| D4 | It required TB63 to observe stages, per-stage time, O9 step counts and O15c widths. The acceptance test prints none of these, and a timed-out process prints nothing. | The obligations were vacuous. |
| D5 | It assigned O6 to Vase and BunnyRandom and treated O15c as something to monitor. | Neither fixture reaches tracing. O15c is Vase's first failure. |

**Ruling:** `M6-CP3-CB64-P13-ARTIFACT-PROBE-REGISTRATION` and `M6-CP3-TB63-P13-CYLINDER-FIRST-DIAGNOSTIC-EXEC` are withdrawn; neither started. The P13 decision record stays as history, and its audit stands.

## RA-188.2 Probe findings (current source, macOS)

| Fixture | Result | First failure / cause | Owner |
|---|---|---|---|
| Cylinder `offgate:362` (80 V, 128 F) | **PASS**, 181.7 s, peak RSS 58 MB | About 96% of stack samples (2,229 of 2,315) are inside `SourceChartTransitionGraph::available()`, which re-runs the O(F) `SourceTopologyRegions::matches_source_faces` check on every query, sometimes twice per query. The A8 optimizer reaches it per point via `quad_reference_surface_point` → `rebind` / `resolve_entity` / `source_face_row` / `isolation_sheet`. The ledger's 600 s ABNORMAL is a performance defect, not a product defect. | **P13-a**: CB64 |
| BunnyRandom `offgate:360` | **RED**, 0.66 s | A3 `CutTransportDomainIdentityMismatch`. Region 0 has χ = 2 and no boundary. The 17 hard-feature (rail) edges form 7 tree components; 2 of them are single edges whose two endpoints are both tips (`68–216`, `169–331`). DESIGN Amendment 15.3 duplicates no tip, so those edges stay glued: the cut gives χ −3 with 5 loops, against identity 15.4's −5. A vertex-indexed `TriMesh` cannot represent a one-edge slit. The guard fails closed correctly; this is a **DESIGN gap** (15.3 cannot realise 15.4 for a tip–tip arc). | **P13-c**: DEFN |
| Vase `offgate:365` | **RED**, 1.6 s | A4 `field-aligned-network` / `BranchContinuationExactMagnitudeExceeded` at edge (320,713), face (320,712,713), branch 1, from the entry-width guard (`SurfaceCellTracing.cpp:548`, 4,096 bits). The A4 trace-scale census shows the exact width growing **linearly, about 200 bits per continuation step**: 1,018 / 2,076 / 3,096 / 4,080 / 4,282 bits at steps 5 / 10 / 15 / 20 / 21. The bound therefore admits about 20 faces per trace. This meets RA-181's O15c trigger. Before CB55 the same row timed out at 600 s. | **P13-b**: DEFN |

- **Equivalence of the P13-a fix:** with the RA-188.8 patch, the pipeline produces Cylinder in 7.85 s (optimization 6.1 s). The CLI output is byte-identical before and after (`6e1e6a9d…`, 216 s → 9.0 s wall).
- **O6 and O9** are reached by none of the three. They stay carried until Vase and BunnyRandom pass A3/A4.
- **O17 (new, hygiene, not P13):** production code writes diagnostics to stderr unconditionally. `GlobalTopologyPlan.cpp:2634` passes `emitEulerDiagnostics = true`, and `FieldTransportAtlas.cpp:746` emits the partition dump. Owner: M8-CP2.

## RA-188.3 Rulings: architecture and trajectory

- **P13 splits by cause into three independent slices.** Each slice is one exact patch and one full-gate TB that also runs the three-row census. No slice waits for another.
- **P13-b is architectural, not a parameter.** Exact rational continuation through a chain of faces accumulates width linearly, and arithmetic cost grows with it. A 4,096-bit bound fails beyond about 20 faces, while production meshes routinely need traces of hundreds of faces. The DEFN must measure the per-step growth and choose among:
  1. **A revised bound.** This only moves the cliff.
  2. **RA-181's correctly-rounded direction.** This lowers the slope but stays linear.
  3. **A canonical bounded-precision continuation.** Each exit parameter is rounded deterministically to a fixed dyadic grid. Every predicate (exit-edge choice, ties, ordering) stays exact on the rounded values, as RA-176, RA-180 and RA-181 require. The fail-closed guard stays.

  Only option 3 bounds the width. Whichever option is chosen must keep topological decisions exact and platform-independent.
- **P13-c amends DESIGN Amendment 15.** Options:
  1. A transport-domain representation in which a slit does not require duplicating a vertex.
  2. A typed rail-product policy for interior tip–tip single-edge rails. Hard features come from rails (`RemeshPipeline.cpp:12676`), and this option must be reconciled with A0's "no value-changing sanitization".

  The DEFN probes what BunnyRandom hits after each option.
- **Gate promotion:** Cylinder joins the gate only after a Linux census PASS (Turn_Cadence's non-gating rule). If TB63 matches its pre-registration, the P13-b DEFN freezes manifest 864 and ledger v5 81.
- **No TB-REV when TB63 matches** (lean sequencing). Probe-backed DEFNs stay on the Review track; the implementation agent gets only CB64 and TB63.

## RA-188.4 CB64 — exact patch

**Turn:** `M6-CP3-CB64-P13-CHART-BINDING-CACHE` (CB; implementation agent; Linux workflow runner).
- **Change:**
  - `available()` stops re-validating every face row on each call. It reads a binding flag that `build()` sets after its existing `matches_source_faces` check.
  - The design-acceptance test's `failure_context` adds `detail=<terminalFailureDetailCode>` without changing its line count. Vase's A4 code then reaches the census log, and the ledger site `:197` is unchanged.
  - No verdict, ordering, admission or output changes.
- **Checks:**
  - The RA-188.8 block, extracted verbatim with a trailing newline, has SHA-256 `fad8986caf897b4fc5eba3f9e667f30518077b81143823e7b65c65314f536c1e`.
  - Run `git apply --check`, then apply. The numstat must be exactly `7 4` (`include/directional/geometry/SourceChartTransitions.h`) and `2 2` (`tests/SurfaceCellDesignAcceptanceTests.cpp`).
  - Resulting SHA-256: `aa981c5a916f0ddfff0f4f78fd5acccd3e33148ccbce7a9a7a42f3d1cad256dd` and `fff33d6c1f2b99a92af22ac7fcf24b14ab735ef621eb443a67e5a14ba2422590`.
  - Before applying, HEAD must equal `e1fd0e4b…` in `src include tests benchmarks CMakeLists.txt cmake`.
- **Build:** the standard `agent-compile-reusable.yml` with the CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI and GUI OFF), eight targets. Record the artifact ID, the ZIP and root `SHA256SUMS` SHA-256s and the source archive SHA-256. No native runs.

| CB64 result | Successor |
|---|---|
| Patch exact, package built | `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC` |
| SHA/numstat/source mismatch | `M6-CP3-PLAN-P13-CHART-BINDING-STOP` (PLAN, Review) |
| Infrastructure failure | `M6-CP3-CB64A-P13-CHART-BINDING-ORCH`, then one retry |

## RA-188.5 TB63 — frozen inputs and pre-registered outcomes

**Turn:** `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC` (TB-EXEC; implementation agent; Linux workflow runner). It makes two P8 harness `--execute` runs on the immutable CB64 package (harness `78b8002c…`, unchanged).

1. **Gate:**
   - Manifest: [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv), 863 rows, `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`.
   - `MEMBERSHIP_LEDGER`: ledger v4, 82 rows, `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`.
   - Pre-registered: **863/863 PASS**, postflight true, membership 945.
2. **Census:**
   - Manifest: [`Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`](Architecture_M6_TB63_P13_Census_Case_Manifest.tsv), 3 OBSERVE rows (Cylinder, BunnyRandom, Vase), `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`. No ledger.
   - Pre-registered: row 1 **PASS**, row 2 **RED** with `CutTransportDomainIdentityMismatch` and `cutChi=-3`, row 3 **RED** with `detail=BranchContinuationExactMagnitudeExceeded`.
   - A census PASS never changes gate membership.

| TB63 result | Successor |
|---|---|
| Gate as pre-registered and census as pre-registered | `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH` (Review); no TB-REV |
| Gate RED, or census differs (a platform split is a determinism lead, RA-176) | `M6-CP3-TB63-P13-CENSUS-FULL-GATE-REV` (TB-REV, Review) |
| Membership error | `M6-CP3-PLAN-P13-CENSUS-MEMBERSHIP-STOP` (PLAN, Review) |
| Orchestration failure | `M6-CP3-CB64A-P13-CHART-BINDING-ORCH` → `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC-R1` |

## RA-188.6 Probe evidence (local, diagnostic)

- **Before the patch:** the three probes ran one process each with a 1,500 s cap. Cylinder: exit 0 in 183.4 s. BunnyRandom: exit 1 in 5 s wall. Vase: exit 1 in 5 s wall. The failure texts are quoted in RA-188.2.
- **Locus probes:** a scratch probe replicated the test options and read `terminalFailureDetailCode`, `terminalFailureLocus`, the retained `fieldTransportAtlasError` barrier components, and `diagnose_field_aligned_trace_scale_census` (57 rows, 3 traces, longest 21 steps).
- **With the patch:** the RA-188.8 patch was applied to the scratch build (43 incremental steps, 2 min 50 s at `-j2`).
  - A row-per-process probe over the TB58 manifest gives **862/863**. Only row 283 fails, the pre-registered macOS O16 row; TB60 gave the same result.
  - The three census rows match the RA-188.5 pre-registration:
    - Cylinder: **PASS** in 7.8 s, independent oracle included.
    - BunnyRandom: **RED**, `CutTransportDomainIdentityMismatch` … `cutChi=-3`.
    - Vase: **RED**, `detail=BranchContinuationExactMagnitudeExceeded`.

## RA-188.7 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| 1 — NEXT | `M6-CP3-CB64-P13-CHART-BINDING-CACHE` | CB / implementation agent, Linux | Package built, patch exact |
| 2 | `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC` | TB-EXEC / implementation agent, Linux | Gate 863/863 and census as pre-registered |
| 3 | `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH` | DEFN / Review, probes; may start during steps 1–2 | Vase continuation policy; Cylinder promoted (manifest 864, ledger v5 81) → CB65 → TB64 |
| 4 | `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` | DEFN / Review, probes; independent of step 3 | Amendment 15 for tip–tip arcs → CB66 → TB65 |
| 5 | P13 re-census → O6 / O9 where reached → matrix 6/6 | per slice | Then retire → FIXTURE → PRODUCT → OPEN → CP3-REV |
| carried | DR1, DR3; DR2/DR4 and O17 → M8-CP2; O2b, O15b, O16 | — | — |

## RA-188.8 Exact CB64 patch

~~~diff
diff --git a/include/directional/geometry/SourceChartTransitions.h b/include/directional/geometry/SourceChartTransitions.h
index 216bcd661..6e4c96f69 100644
--- a/include/directional/geometry/SourceChartTransitions.h
+++ b/include/directional/geometry/SourceChartTransitions.h
@@ -208,10 +208,11 @@ public:
                                    hardFeatureEdges, barycentricTolerance) {}
 
   [[nodiscard]] bool available() const {
-    return faces_ != nullptr && faces_->cols() == 3 && authority_ != nullptr &&
-           authority_->matches_source_faces(*faces_) &&
-           consistent_ && faceChartComponent_.size() ==
-                              static_cast<std::size_t>(faces_->rows());
+    // build() checks the exact source binding once; the graph borrows
+    // immutable stage products, so queries do not re-validate every row.
+    return sourceBound_ && faces_->cols() == 3 && consistent_ &&
+           faceChartComponent_.size() ==
+               static_cast<std::size_t>(faces_->rows());
   }
 
   [[nodiscard]] std::optional<SourceProjectionChart>
@@ -597,6 +598,7 @@ private:
         !authority_->matches_source_faces(*faces_)) {
       return;
     }
+    sourceBound_ = true;
 
     const int faceCount = faces_->rows();
     int maximumVertex = -1;
@@ -929,6 +931,7 @@ private:
       vertexFan_;
   std::vector<SourceChartTransition> transitions_;
   bool consistent_ = true;
+  bool sourceBound_ = false;
 };
 
 } // namespace directional::geometry
diff --git a/tests/SurfaceCellDesignAcceptanceTests.cpp b/tests/SurfaceCellDesignAcceptanceTests.cpp
index 1c761a782..3ebd635ac 100644
--- a/tests/SurfaceCellDesignAcceptanceTests.cpp
+++ b/tests/SurfaceCellDesignAcceptanceTests.cpp
@@ -37,8 +37,8 @@ const directional::bench::BenchmarkCase &find_benchmark_case(
 
 std::string failure_context(const directional::pipeline::RemeshResult &result) {
   return "terminal=" + result.diagnostics.terminalFailureCode + ":" +
-         result.diagnostics.terminalFailureStage +
-         " traceSegments=" +
+         result.diagnostics.terminalFailureStage + " detail=" +
+         result.diagnostics.terminalFailureDetailCode + " traceSegments=" +
          std::to_string(result.diagnostics.surfaceCellTraceSegmentCount) +
          " arrangementCells=" +
          std::to_string(result.diagnostics.surfaceCellArrangementCellCount) +
~~~

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector edit. TB58 manifest `31c1360a…` and ledger v4 `36241caa…` re-hashed unchanged; census manifest self-check `SELF_CHECK_PASS cases=3` |
| Decisive claims independently re-derived | Every P13 row re-observed at current source. Barrier components read from the retained A3 error. A4 widths from A4's own census. Hot path from 2,315 stack samples. Equivalence from byte-identical CLI output |
| Non-vacuity checked | Each probe printed a terminal code with its locus. Cylinder PASS ran the independent oracle. The patch probe gate executed every row: 862/863, with only O16 row 283 failing |
| Prior obligations discharged/carried | P13 decision D1–D5 ruled. CB64/TB63 (old) withdrawn. O6 and O9 carried to P13 re-census. O15c is now P13-b. DR1, DR3, DR2/DR4, O2b, O15b, O16 carried |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-a (CB64), P13-b (O15c DEFN), P13-c (Amendment 15 DEFN), O17 (M8-CP2) |
| ORIENTATION currency line | Updated to RA-188 / CB64 next, 2026-10-31 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 Next and §7 Immediate updated. §4: n/a, the witness matrix is unchanged. §8: n/a, no defect pattern is confirmed yet |
| CHANGELOG | Entry added |
| ROADMAP | CP3 boundary line updated |
| Selector manifest | n/a: no selector change |
| LESSONS | New lesson: re-observe deferred rows at current source before planning on them |
| Consolidation under CLEAN_UP_POLICY | n/a: the P13 decision and its working evidence stay as history |
| Successor frozen | `M6-CP3-CB64-P13-CHART-BINDING-CACHE` (RA-188.4); TB63 falsifiers in RA-188.5 |
| Turn boundary held | No gate runtime and no product, test, fixture, selector or benchmark change in the repository. Probes ran only on a scratch build |
| `review_check.py boundary` | **ALL CHECKS PASSED**. `ledgers --base 95565e7ee` also PASSED. `document_drift_audit.py`: 0 errors, 0 warnings |
| `STATUS` lifecycle maintained | Turn `M6-CP3-DEFN-P13-PROBE-ADJUDICATION`, COMPLETE, Successor CB64 |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the push |
