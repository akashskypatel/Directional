# M6-CP3-CB1-ENTRY-R1 WIP handoff — 2026-10-06T17:43Z

Turn remains IN_PROGRESS. No compile/package or generated Directional runtime was executed in this attempt.

## Authority and source

- Exact verified source snapshot remains run/artifact `37493944389 / 11426961344`.
- Exact source/event SHA: `637eb6f217a839ec1f9a6d9871a45b67089736e7`.
- Provider digest: `sha256:dcee2920ecec34c88dc074f5bdff982d09664d263d0855954538909efc761896`.
- Embedded source archive SHA-256: `8a96433c6681df765b9a55c133ff047acd191a288c45bcbd52b7826ffaf2df9f`.
- Source manifest: **5550/5550 verified**; snapshot metadata records `runtimeExecution=false`.
- Process observation: this resume attempt inspected the already-materialized exact snapshot before re-reading `TOOL_USE_CONSERVATION_POLICY.md`. The policy was then re-read in full, `READ_MODE=snapshot` was retained, and no piecemeal connector source reads were used. This is a process-order miss only; source authority was not weakened.

## Complete preserved patch

Newest recovery candidate:
- chat/File-Library file: `Directional__M6-CP3-CB1-ENTRY-R1__base-637eb6f217a8__work-preservation.patch`
- exact base: `637eb6f217a839ec1f9a6d9871a45b67089736e7`
- complete patch SHA-256: `925be14071546c4a19b274191bf003c8f2c4aa5b0caeac01fd9b334e62e29972`
- diff-body SHA-256: `33b452cf4e8c946891d43212dae6cbecc1d4b17c2b0c1b0862fe8f557b74ac9f`
- intended paths:
  - `include/directional/pipeline/RemeshPipeline.h`
  - `src/geometry/SurfaceCellTracing.cpp`
  - `src/pipeline/RemeshPipeline.cpp`
  - `tests/SurfaceCellTransitionQuotientTests.cpp`
- metadata header is `Directional-Work-Preservation-Patch-v1`.
- `git diff --check` on the prepared diff: clean.
- fresh exact-base `git apply --check`: passed.
- applied fresh-base bytes compare exactly with the staged working files on all four paths.

Google Drive transport staging:
- folder: `My Drive/Directional-CI`
- file ID: `18a7y5tTEBhVgzFfYBumQ5KgGZSxWz7SC`
- file name: `Directional__M6-CP3-CB1-ENTRY-R1__base-637eb6f217a8__work-preservation.patch`
- exact staged bytes are the complete patch above.
- Do not delete this Drive file until the patch has pushed successfully or is deliberately abandoned.

The older `M6-CP3-CB1-ENTRY-R1-WIP-20261006T1626Z.patch` and `...1715Z.patch` are superseded preservation artifacts. Do not layer them onto the complete patch.

## Implemented in the complete patch

1. P1: uniform and periodic regional producers publish complete exact `faceBranchRotation`; periodic publication retains the winning strip-candidate branch map and rejects missing/conflicting/non-Z4 gauges.
2. RA-31a: removes `HardRailBranchCertificateMismatch`, the A5 HardRail branch-certificate rejection, and the legacy `:branch-certificate` mapping while preserving coordinate-rigid transport and endpoint gauge evidence.
3. P2: reciprocal isolation evidence is required only in the certified cross-sheet collinear OrdinaryFront seam branch; ordinary non-cross-sheet relations keep full identity/sheet/wedge checks without that evidence requirement.
4. T1: focused30 ordinal 12 rotates every affected `sourceFaceBranchRotations` entry together with the HardRail region relabel.
5. T2 audit: the existing produced nonzero-Z4 torus witness already asserts a 90/270 endpoint face-gauge delta before downstream authority checks.
6. Identity 2: baseline A5 production and 90/270 HardRail witness remain required; withdrawn certificate error expectations are removed and the certificate assertions remain the pre-registered RED surface.
7. Identity 6: unexpected A5 rejection is surfaced before the required A6/A7 path.
8. A5 rejection diagnostics for identities 2 and 6 now print exact relation identity fields: relation kind, both occurrence cell/corner identities, and HardRail ID.
9. T4: the oracle now checks typed hard-feature carriers directly against `SourceChartTransitionGraph`: typed barriers block face transitions, removing the hard Periodic carrier restores its transition, HardRail carriers are typed/blocked, and adding a typed barrier blocks an otherwise admissible ordinary transition. No arbitrary endpoint chart-component inequality remains.

## Orchestration state

- A combined temporary apply+compile caller was drafted locally with self-schema-validation first, Drive apply second, applied-head resolution third, and the mandatory eight-target reusable compile fourth.
- GitHub connector safety blocked both direct workflow-file creation and Git-tree insertion under `.github/workflows/**`. No caller commit, trigger marker, patch commit, or compile run was created.
- An unreferenced Git blob `7ed5586b5056fc4f789a9fd55b559cc20d159d5a` contains the drafted caller, but it is not reachable from the branch and is not repository authority.
- Do not create a duplicate source snapshot. The old source-snapshot trigger marker remains cleanup debt from the prior attempt.

## Exact continuation

1. Resume the same turn and use the complete patch + Drive File ID above.
2. Establish an authorized executable caller for `agent-google-drive-reusable.yml` without weakening workflow policy. If the connector still blocks writing `.github/workflows/**`, retain IN_PROGRESS and require an alternate authorized trigger path rather than direct source writes.
3. Apply the complete patch through the durable Drive reusable.
4. Compile/package all eight mandated GMP/GMPXX targets through `agent-compile-reusable.yml` only; execute no generated Directional runtime.
5. If compile/package is green, record Code + Build evidence, retire staged Drive patch/control state, remove temporary caller before its marker, clean the old source-snapshot marker, and close with successor `M6-CP3-TB1-ENTRY-R1-EXEC`.


## 2026-10-06T18:00Z control-plane capability diagnosis

This continuation did not mutate source/test bytes and did not run a build or generated runtime.

- The current GitHub connector action inventory has no workflow-dispatch/create-dispatch action. It can re-run an existing run/job but cannot supply new `workflow_dispatch` inputs.
- The generic GitHub fetch surface can list Actions runs read-only. A repository-wide run read at this attempt confirmed there has been no newer workflow run after source snapshot run `37493944389`; no hidden apply/compile run exists to adopt.
- `agent-google-drive-reusable.yml` itself already supports `workflow_dispatch`, but there is no authenticated dispatch mutation exposed by the current connector.
- The installed GitHub plugin is the only relevant plugin surfaced by plugin discovery; no separate GitHub-Actions trigger integration is available in this session.
- Historical workflow re-run is not a safe substitute because previous callers freeze different Drive File IDs, patch hashes, base SHAs, and compile source SHAs.
- Do not retry connector writes under `.github/workflows/**` unless the connector capability changes; the previous attempt already proved direct workflow creation and Git-tree insertion are rejected by the connector safety layer.
- Do not bypass the standard Drive transport by direct-writing the four source/test files.

Continuation therefore remains procedural: preserve the exact staged patch and wait for an authorized way to invoke a caller/dispatch. Once such a trigger exists, use the existing Drive File ID/hash/base from this handoff, apply through `agent-google-drive-reusable.yml`, then compile all eight targets through `agent-compile-reusable.yml` before claiming Code + Build completion.


## 2026-10-06T18:22Z prepared alternate caller handoff

The already-drafted combined caller was corrected locally before exposure: the applied-head resolver now places `id: resolve` on the shell step that writes `source_sha` to `$GITHUB_OUTPUT`, rather than on the checkout step. Without that correction, `needs.resolve-source.outputs.source_sha` would be empty and the compile stage would not receive the applied source SHA.

Prepared caller:
- required repository path: `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml`
- local/chat artifact name: `m6-cp3-cb1-entry-r1-apply-compile.yml`
- SHA-256: `6e8daf9b4cbc29491368361e61863e3ba49dc739c903e2e8b17eef35080e9a9e`
- behavior: self-schema-validation -> exact Drive patch apply -> resolve pushed branch head -> mandatory eight-target compile/package -> mailbox.
- marker path is fixed as `.agents/connector-triggers/m6-cp3-cb1-entry-r1-apply-compile.txt`.

Because the current connector cannot create a new file under `.github/workflows/**`, the only policy-compatible intervention available from this session is for the repository owner to install the attached caller at the exact path above on the working branch, as its own commit, **without creating the marker**. Once that caller exists, the next continuation can create the marker through the GitHub connector as a separate commit, observe the run, and continue normal evidence/cleanup handling. Do not edit the caller's embedded Drive File ID, patch hash, base SHA, target branch, target list, or runtime-free compile boundary.


## 2026-10-06T18:47Z continuation check

- Rechecked the required caller path on the working branch after this attempt's entry beacon: `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml` is still absent.
- Revalidated the prepared caller locally from the preserved snapshot/container: SHA-256 remains `6e8daf9b4cbc29491368361e61863e3ba49dc739c903e2e8b17eef35080e9a9e`; YAML parses and the resolved-source output is attached to the step that writes `source_sha`.
- The verified snapshot contains only the eight durable workflows; no existing generic push-triggered workflow can accept the staged Drive File ID/hash/base and then compile the resulting source. The Drive reusable remains dispatch/call-only, so no policy-compatible trigger can be synthesized from a non-workflow marker alone.
- No source/test mutation, compile/package run, generated runtime, or patch-consumption action occurred in this continuation.
- Exact next action remains owner installation of the prepared caller at its recorded path as a standalone commit, without the trigger marker. After that, resume this same turn and create only the marker through the connector.
