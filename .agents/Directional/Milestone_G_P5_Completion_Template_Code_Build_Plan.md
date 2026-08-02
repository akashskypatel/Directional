# Milestone G P5 — Completion Ownership Classification and Repair

**Authority:** Next code + build turn for `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Validated source:** `d4c1bce4338b7f2e91264c349a73b6b260e80f54`  
**Validation artifact:** `8840174777`  
**Turn type:** Code changes + compile-only build. Do not execute tests or benchmarks.  
**Review policy:** Never; this plan is authoritative immediately.

## 1. Validated failure

Two independent direct `bunny_1k_random.obj` runs, with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled, failed identically at completion:

```text
DuplicateStitchedQuad:firstPatch=378;firstLocalQuad=1;
secondPatch=394;secondLocalQuad=4;
globalVertices=7643,7644,7647,7648;
classification=completion-template;
firstDomainHash=1626132098604174973;
secondDomainHash=12830489233532523937;
firstBoundaryNodeHash=9853059121513979599;
secondBoundaryNodeHash=6530130091133399252;
firstBoundaryHalfedgeHash=11019542682270369445;
secondBoundaryHalfedgeHash=4213466302263896358;
firstSourceSupportHash=9777327708078931779;
secondSourceSupportHash=17251474233191701613
```

Every one of 21,297 descriptors completed, zero descriptors failed, and zero required endpoints remained unresolved. No output escaped the failed transaction.

The distinct domain, boundary, and source-support hashes rule out duplicate oriented-domain ownership and overlapping undirected-boundary ownership.

## 2. Classification caveat

The current runtime selected `completion-template`, but the B-vs-D decision is not yet fully authoritative:

- per-corner identity hashes are compared in operation-local order rather than as a canonical cyclic/reversed face cycle;
- identity kinds and hashes are not serialized in the benchmark diagnostic;
- completion backend and operation-local region lineage are not reported in the failure string.

A rotated or reversed equivalent identity cycle can therefore miss the `false-merge` equality branch. The first work package must correct the diagnostic contract before changing ownership behavior.

## 3. Required work packages

### P5-CB7 — Canonical completed-face ownership

1. Represent each completed quad by an orientation-aware canonical cycle of stitch identities.
2. Canonicalize cyclic rotation deterministically.
3. Preserve orientation; compare reversed cycles explicitly instead of sorting the four corners as an unordered set.
4. Record for every corner:
   - stitch identity kind;
   - canonical identity values or collision-safe interned identity ID;
   - diagnostic hash;
   - source component and sheet;
   - local and global vertex IDs.
5. Record source patch/domain, completion backend, and operation-local quad.
6. Include these semantics in structural hashes.

Hashes are diagnostic accelerators only. Equality must compare canonical identity records, not hashes alone.

### P5-CB8 — Reclassify the 378/394 conflict

After canonical face ownership exists:

- **Case B — false stitch equivalence:** if distinct source-authoritative corner identities collapse to one stitch key, strengthen the key at its construction point. Preserve valid shared arrangement-node and feature-interval merging.
- **Case D — completion-template ownership:** if the canonical corner identities are correctly shared but two distinct domains emit the same face, constrain the responsible completion backend to its patch-local region and source support.

Do not discard either final face, weaken `DuplicateStitchedQuad`, branch on the observed IDs, or enable recovery/fallback.

### P5-CB9 — Completion-domain proof

For every emitted local quad, validate before assembly that:

1. generated interior corners are owned by the source patch;
2. boundary corners belong to that patch's canonical boundary;
3. source-point support is contained in the descriptor's source-face support;
4. the local face is associated with exactly one operation-local region;
5. no template emits a boundary-only face that belongs wholly to an adjacent patch unless explicit shared-face topology authorizes it.

Fail closed with a typed completion ownership diagnostic when the proof cannot be established.

### P5-CB10 — Generalized regression sources

Add minimized fixtures that distinguish the two remaining classes:

1. same authoritative corner identities in rotated and reversed local order produce the same canonical face identity;
2. under-qualified stitch identity is classified as false merge;
3. two distinct domains whose templates emit the same shared-boundary face are classified as completion-template ownership;
4. valid adjacent patches sharing only an edge still assemble conformingly;
5. patch order and source-face row order do not alter classification.

### P5-CB11 — Correct invalid Milestone E fixtures

Correct only the fixture construction; preserve or strengthen intended assertions:

1. `SharedEdgeParityRepairConforminglyCompletesTwoOddCells`: create a topology-valid two-cell odd arrangement with a real shared interior interface. The current shared-edge-coincident arcs fail before parity repair on both the baseline and current artifacts.
2. `GlobalDescriptorAssignmentRejectsAmbiguousInteriorSingularity`: use two distinct canonical domains incident to the same singular source vertex rather than duplicating one entire domain.
3. `ComplexCompletionFailsClosedInsteadOfReturningPartialOutput`: use distinct source support for the valid and non-disk patches so duplicate-domain validation does not preempt the transactional completion contract.

Do not change the expected semantic contract to match an invalid fixture.

### P5-CB12 — Ownership memory and runtime remediation

The exact same-machine comparison regressed from:

- 22.981569 s to a 26.775241 s mean (+16.51%);
- 749,375,488 bytes to a 1,696,000,000-byte mean peak working set (+126.32%);
- 4.168940 s to a 6.318718 s mean completion stage (+51.57%).

Reduce repeated variable-length identity storage by using collision-safe interned records or compact stable IDs. Preserve exact equality and deterministic ordering. Do not remove diagnostic evidence or weaken identity qualification.

## 4. Compile-only gate

The next turn must:

1. modify only ownership, completion, diagnostics, relevant regression fixtures, trackers, and the exact build workflow if packaging requires it;
2. configure a clean Release build;
3. compile `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
4. run no test, benchmark, or custom mesh executable;
5. package exact source, binaries, libraries, logs, source commit/status, and checksums;
6. update TODO, milestone tracker, this plan, and draft PR;
7. leave P5 open and the PR unmerged for the next test + benchmark turn.

## 5. Following validation turn

The following test + benchmark turn must run, without rebuilding:

- canonical face-ownership discriminator regressions;
- corrected `PatchDescriptorMilestoneE.*`;
- `SurfaceArrangementPhase16.*` and `PureQuadCompletionPhase18.*`;
- Phase 14–18 aggregate;
- Milestone G P23 and Phase 20;
- direct random bunny at least twice with recovery disabled;
- same-machine baseline performance comparison.

P5 closes only when direct completion proceeds beyond assembly without duplicate ownership, fallback, recovery, or validator weakening, and the ownership overhead is acceptable.

## 6. Completed code/build checkpoint

This plan was executed in the code changes + compile-only build turn.

- Implementation commit: `713eb310ec0afe6e2608cf3b0f3b8f6962b485e5`.
- Exact compiled source commit: `dcef9fbf65930b20db93128deb193f10702dc9c7`.
- GitHub Actions run: `30771945124` — success.
- Artifact: `8840866875`, `surface-cell-p5-branch-linux-release`.
- Artifact digest: `sha256:d67a464b2f2c2f6d58bbb9fa15a0e87009176698f14d19a9054facfbcb97cd90`.
- Required targets compiled: `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
- Artifact source status is empty and every packaged checksum passes.
- No test, benchmark, or custom mesh executable ran.

Work packages P5-CB7 through P5-CB12 are implemented and compile-valid. Runtime correctness and performance remain unverified. The authoritative next turn is test and benchmark using artifact `8840866875` without rebuilding. See `Milestone_G_P5_Completion_Template_Code_Build_Report.md` for the implementation and build evidence.
