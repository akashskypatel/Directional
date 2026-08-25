# Architecture M3 CP4c DG1 — Artifact-Only 316-Identity Diagnostic Plan

**Status:** COMPLETE / DG-REV VERIFIED GREEN; CB2 UNBLOCKED
**Parent turn:** `M3-CP4c-CB1`
**Ordered subturns:** `M3-CP4c-DG1-DG-EXEC` then mandatory `M3-CP4c-DG1-DG-REV`
**Budget:** diagnostic **1/2**; acceptance attempts **0/3**, unchanged

## Validation Identity

- working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- exact semantic source: `428e0ecb6f769b501c99405ae2a90c24d5401cca`
- immutable package artifact: `9536499549`
- package ZIP SHA-256: `4c64c0c3ea872dbf889c4de398ed40f9e0193fce534ee6117348e3b7a5514660`
- package source archive SHA-256: `33e546764b3b3017fbb043cfd91a4366a3ae27244861ade457743fcf10cf49ac`
- package compile run/job: `32771584396 / 97572920008`
- package log artifact: `9536500171`, SHA-256
  `86c4ab983bba5bcf1a57213aa73ee6f6db48b7cfbe2c89a9487194e46e905732`
- package manifest: 27/27; five source-status snapshots empty; package build
  `runtimeExecution=false`
- frozen predecessor selector: 304 identities, SHA-256
  `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`
- frozen CP4ab selector: 12 identities, SHA-256
  `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec`
- planned platform: GitHub-hosted Linux runner using the immutable package only

## Objective and Sufficiency

Measure the sole new CB1 risk: fail-closed production A2b construction can reject an identity that was
accepted before the wiring existed. Replaying the byte-frozen accepted **316 = predecessor 304 +
CP4ab 12** surface against the immutable CB1 package is sufficient because it covers all accepted
authority without spending an acceptance attempt or introducing new identities.

This is diagnostic evidence only. Green does **not** accept CP4c, authorize C1–C6, or alter stable
regression totals. Red blocks CB2 and returns to independent Review.

## Context Load Plan for DG-EXEC

Before any trigger or artifact transfer, DG-EXEC must fully read the latest upstream
turn-based-coding-agent skill and its routed diagnostic/evidence/recovery/GitHub workflow material,
then fully read:

1. `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md`; declare `READ_MODE=snapshot` and initialize
   a fresh in-memory tool-call ledger.
2. `.agents/Directional/Future_Chat_Session_Handoff.md`, `RETENTION_POLICY.md`, `CLEAN_UP_POLICY.md`,
   `GitHub_Workflow_Policy.md`, `LESSONS.md` (especially §§1, 7, 8), and `TODO.md`.
3. `Architecture_M3_CP4c_Code_Build_Plan.md` §§2, 5, 6, 8 and
   `Architecture_M3_CP4_DEFN_Frozen_Definitions.md` §§10–11.
4. `Architecture_M3_CP4c_CB1_Global_Topology_Plan_Code_Build_Report.md` and this plan.
5. `M3_CP4ab_Closure_Record.md` and
   `Architecture_M3_CP4ab_TB_R3_Artifact_Only_Test_Benchmark_Report.md` only as needed to verify the
   accepted 316 selector provenance and prior artifact-only orchestration contract.

Then verify PR #8 remains open, draft, unmerged; branch authority has not semantically moved away from
source `428e0ecb...`; artifact `9536499549` and both frozen selector digests remain exact; and no stale
temporary workflow/payload/marker exists. For closeout, follow the current `CLEAN_UP_POLICY.md`;
user commit `c359ea925b04471500575a9dcc17bdc6e4bb52d1` superseded the earlier no-cleanup override.

## Preconditions and Integrity Checks

DG-EXEC must fail closed before runtime unless all are true:

1. Download artifact `9536499549` exactly once and verify its outer SHA-256.
2. Extract only into a new temporary directory. Verify `SHA256SUMS` is 27/27 and reject extra,
   missing, duplicated, or digest-mismatched members.
3. Verify the packaged source archive digest and its recorded semantic source identity
   `428e0ecb6f769b501c99405ae2a90c24d5401cca`.
4. Verify all five packaged source-status snapshots are present and empty.
5. Recover the two accepted selectors from their accepted evidence source without discovery or
   regeneration; verify exact SHA-256, 304 and 12 non-empty lines respectively, no blank identities,
   and 316 unique identities in ordered concatenation.
6. Verify all required packaged executables and runtime libraries from the 27-member manifest exist;
   do not configure, build, relink, repair, or substitute any binary.

An integrity/preflight failure consumes no diagnostic only if no Directional identity process has
started. Preserve the failure evidence and stop.

## DG-EXEC Ordered Execution

1. Materialize a minimal temporary artifact-only runner and frozen selector inputs. Workflow setup may
   inspect archive files and hashes but may not invoke a Directional binary for discovery, listing,
   help, version, or probe execution.
2. Execute the frozen predecessor selector in its exact order, **one identity per fresh process**.
3. Execute the frozen CP4ab selector in its exact order, **one identity per fresh process**.
4. For every identity record its selector ordinal, exact identity string, process exit code, elapsed
   time, and complete identity-scoped stdout/stderr raw stream. Do not retry an identity to turn red
   green. A single execution is the diagnostic observation.
5. Derive machine-readable totals separately for predecessor 304, CP4ab 12, and combined 316. Report
   orchestration errors separately from test failures.
6. If any identity is red, extract the first structured typed rejection from that identity's raw
   stream. Do not infer a typed failure by grepping assertion prose for enum names.
7. Re-hash the package and selectors after execution; verify the artifact tree is unmodified. Preserve
   source-status snapshots showing no repository/source/test/fixture/selector/package mutation.

No configure, build, relink, repair, generated discovery, selector generation, test filtering by
discovery output, source edit, test edit, fixture edit, identity edit, expectation edit, package edit,
or repository mutation is permitted. No benchmark or custom input is permitted.

## Acceptance Criterion

DG-EXEC is green only when all conditions hold:

- predecessor: **304/304**, zero red;
- CP4ab: **12/12**, zero red;
- combined: **316/316**, zero red;
- exactly 316 identity processes and 316 unique frozen identities;
- zero orchestration errors;
- pre/post package and selector digests byte-identical;
- all configure/build/relink/repair/discovery and mutation flags false.

This consumes CP4c diagnostic **1/2** and consumes **no acceptance attempt**, regardless of green or
red. Green unblocks mandatory DG-REV only; it does not directly authorize CB2.

## Exact Evidence to Preserve

Preserve an immutable result artifact and raw log artifact, each with GitHub artifact ID and outer
SHA-256, containing at minimum:

- run id, job id, workflow path, event SHA, branch, runner OS/image;
- exact package artifact id/name, outer digest, source archive digest, semantic source identity;
- pre/post `SHA256SUMS` 27/27 results and member inventory;
- all five source-status snapshots before and after, empty;
- both selector files verbatim, their digests, line counts, uniqueness result, and ordered combined
  selector digest;
- all 316 identity-scoped raw streams and per-process exit/status/timing records;
- machine JSON with predecessor/CP4ab/combined pass/fail totals and orchestration-error count;
- explicit booleans for configure, build, relink, repair, discovery, source mutation, test mutation,
  fixture mutation, selector mutation, and package mutation;
- `runtimeExecution=true` for DG-EXEC itself, plus the exact count of 316 identity processes;
- first structured typed rejection per red identity, if any;
- temporary-path inventory and post-cleanup absence verification.

## Stop and Blocker Conditions

Stop immediately and preserve evidence if:

- source/package/selector identity or any digest differs from this plan;
- manifest is not exactly 27/27 or any source-status snapshot is non-empty;
- an identity is missing, duplicated, reordered by generated discovery, or would not run in its own
  process;
- execution would require configure/build/relink/repair/discovery or any mutation;
- an orchestration error makes identity totals ambiguous;
- any process is externally terminated or any raw stream is missing;
- the result is anything other than 316/316.

On any post-runtime red, CB2 remains blocked and the next turn after DG-REV is mandatory independent
Review. Do not spend diagnostic 2/2, switch W1 to publish-or-omit, patch a fixture/expectation, widen the
selector, or adapt production code inside DG-EXEC.

## DG-REV — Mandatory Independent Review

DG-REV is a separate agent turn with no runtime and no repository mutation except its durable review
record/handoff closeout. It independently verifies from the GitHub API and downloaded artifacts:

- run/job terminal state and artifact digests;
- exact package/source/selector identities and 27/27 pre/post integrity;
- 316 one-process executions, per-surface totals, zero orchestration errors, and complete raw streams;
- all prohibited-action/mutation flags false;
- any red identity's structured typed rejection classification;
- diagnostic accounting (1/2) and acceptance accounting (0/3).

Only a DG-REV verdict of **VERIFIED GREEN** may unblock `M3-CP4c-CB2`. A red, incomplete, contradictory,
or unverifiable result requires Review; it never authorizes an in-place correction.

## Completion and Handoff

DG1 is complete. DG-EXEC is green on authoritative run/job `32776212123 / 97587757347`, and
independent `M3-CP4c-DG1-DG-REV` returned **VERIFIED GREEN** in
`Architecture_M3_CP4c_DG1_Artifact_Only_Diagnostic_Independent_Review_Record.md`.
`M3-CP4c-CB2` is unblocked and is the exact next turn. Diagnostic accounting remains **1/2** and
acceptance accounting remains **0/3**.
