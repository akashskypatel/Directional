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


## 2026-10-06T21:31Z continuation verification

- Required temporary caller `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml` remains absent on the working branch.
- Repository Actions history still shows source-snapshot run `37493944389` as the newest run; no hidden apply or compile run exists to adopt.
- Staged Drive patch file `18a7y5tTEBhVgzFfYBumQ5KgGZSxWz7SC` still exists with exact name `Directional__M6-CP3-CB1-ENTRY-R1__base-637eb6f217a8__work-preservation.patch` and size 29220 bytes.
- No source/test mutation, patch consumption, compile/package run, test, benchmark, or generated Directional runtime occurred.
- Continue this same turn only after the prepared caller is installed at the exact workflow path as a standalone commit without its trigger marker; then create the marker separately through the connector and observe the authorized workflow.


## 2026-10-06T22:02Z orchestration-template correction

- Re-read the current workflow policy and corrected the prepared caller to satisfy its SHA-256 authoring rule: the draft template now contains the quoted placeholder `@@SHA256:patch@@`, and the exact caller is materialized through `.agents/Directional/tools/write_orchestration_payload.py --sha256 patch=<digest>`.
- Template artifact: `m6-cp3-cb1-entry-r1-apply-compile.template.yml`, SHA-256 `af5005d484351f24a24816adb87b1d34c294382f9392e77a6f398bc3c37da8d8`.
- Materialized caller artifact: `m6-cp3-cb1-entry-r1-apply-compile.yml`, SHA-256 `e60a7baed7a0eaf7dcbd4933befc104b205cff85943063f4d7b88f9051015725`. This supersedes the earlier caller SHA `6e8daf9b4cbc29491368361e61863e3ba49dc739c903e2e8b17eef35080e9a9e` only because the rendered digest is now explicitly quoted; runtime semantics are unchanged.
- Local YAML parsing of the materialized caller passed and the `resolve-source` output still references `steps.resolve.outputs.source_sha`. This local parse is not a substitute for the mandatory durable SchemaStore validator.
- The caller remains absent from `.github/workflows/`; no marker was created and no workflow run was triggered. Connector capability remains unchanged, so the prior prohibition on retrying blocked workflow-file writes still applies.
- Exact next action: install the new materialized caller at `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml` as a standalone commit with no marker. The caller itself fail-closes on the durable schema validator before Drive apply, but current policy still records strict prepublication validator execution as unavailable through this connector surface.


## 2026-10-06T22:44Z current-head patch CAS verification

- Fresh compare-and-swap preflight from patch base `637eb6f217a839ec1f9a6d9871a45b67089736e7` to this attempt's control head `d099d0b2a8501fe8f5558d5fdffd2e516a946d2d` reports 39 commits ahead, 0 behind, with the base as merge base.
- The only paths changed across that range are `.agents/Directional/Architecture_M6_CP3_CB1_Entry_R1_WIP_Handoff.md`, `.workflow-mailbox/repo-source-snapshot/latest.json`, `.workflow-mailbox/repo-source-snapshot/runs/37493944389-attempt-1.json`, and `STATUS`.
- Therefore all four intended patch paths remain byte-authority-compatible with the frozen base: `include/directional/pipeline/RemeshPipeline.h`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, and `tests/SurfaceCellTransitionQuotientTests.cpp` have not changed since the patch base.
- This narrows the remaining obstacle to workflow validation/publication/trigger capability; no semantic-source rebase or patch regeneration is currently required.


## 2026-10-06T23:14Z workflow-policy precedent resolution

- Fresh exact-snapshot policy inspection found a directly analogous accepted control-plane precedent in `.agents/Directional/Architecture_M6_CP1_CB11_G4_R1_Code_Build_Report.md`: with the same connector limitation (no direct reusable-workflow dispatch), its temporary caller could not be SchemaStore-validated before first publication; the exact active caller was instead fail-closed behind `agent-workflow-schema-validator-reusable.yml`, and validation passed before patch application. That report explicitly classifies the deviation as procedural evidence only with no semantic credit.
- This resolves the prior ambiguity recorded above: for this connector limitation, project precedent permits installing the exact narrow caller first, provided it has no marker in the install commit and its validator job gates all substantive Drive/apply/compile work. The current materialized caller has that fail-closed ordering: `validate` -> `apply` -> `resolve-source` -> `compile`, with mailbox publication last.
- Current GitHub app permissions were checked and are already app-specific **Allow all actions**; the inability to write `.github/workflows/**` is therefore a connector safety/capability restriction, not a missing user permission setting.
- Plugin discovery for `GitHub Actions workflow dispatch` surfaced only the already-installed GitHub integration; no separate Actions-dispatch plugin is available in this session.
- Do not retry the previously rejected workflow-path connector mutation unchanged. Exact remaining intervention is repository-owner installation of materialized caller SHA-256 `e60a7baed7a0eaf7dcbd4933befc104b205cff85943063f4d7b88f9051015725` at `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml` as a standalone commit with the marker absent. After installation, resume this same turn, verify exact caller bytes from branch authority, then create only `.agents/connector-triggers/m6-cp3-cb1-entry-r1-apply-compile.txt` through the connector. The first run must show the validator GREEN before Drive apply is accepted as evidence.
- No source/test mutation, patch consumption, compile/package run, test, benchmark, or generated Directional runtime occurred while resolving this policy point.


## 2026-10-06T23:40Z caller source-identity hardening

- The required caller remains absent from `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml`; no trigger marker was created.
- Re-read the durable reusable contracts from the verified exact source snapshot and hardened the local caller's applied-source resolver. After Drive apply, checkout now uses `fetch-depth: 2`, requires the resolved branch-head commit's first parent to equal the original marker/event SHA, and requires the event->resolved-commit changed-path set to be exactly the four patch-authorized paths before exposing `source_sha` to the compile reusable. This fails closed on an intervening branch write instead of silently compiling an unrelated later head.
- Updated template artifact `m6-cp3-cb1-entry-r1-apply-compile.template.yml`: SHA-256 `3c7d50a3d37c6b5bc0e35e9a772d2c5e405903c827d6a55bcb677e733ddbb5b9`, 3181 bytes.
- Updated materialized caller `m6-cp3-cb1-entry-r1-apply-compile.yml`: SHA-256 `dc702bbd8d4056ce81ec3f71b64462b9c95ff83171b42c83e29a0129621341e7`, 3229 bytes. It was materialized through `write_orchestration_payload.py` from the `@@SHA256:patch@@` template; local YAML parse and guard assertions pass. This supersedes caller SHA `e60a7baed7a0eaf7dcbd4933befc104b205cff85943063f4d7b88f9051015725`.
- Google Drive patch File ID `18a7y5tTEBhVgzFfYBumQ5KgGZSxWz7SC` was rechecked and remains present with the expected filename and exact size 29220 bytes.
- Exact remaining intervention: repository-owner installation of the new materialized caller SHA above at the recorded workflow path as a standalone commit, with the marker absent. On the next continuation verify exact branch bytes first, then create only the marker. Accept no Drive/apply or compile evidence unless the caller's schema-validator gate is GREEN.
- No source/test mutation, patch consumption, compile/package run, test, benchmark, or generated Directional runtime occurred in this continuation.


## 2026-10-07T00:02Z caller contract completion

- Re-read the durable workflow contracts from the verified snapshot and found one remaining caller-contract gap: the custom `resolve-source` job was doing fallible checkout/verification work without first initializing a persistent diagnostic log and without an `if: always()` log upload, violating the mandatory workflow contract even though all reusable jobs already satisfied it.
- Corrected the local template so `resolve-source` now initializes a runner-temp persistent diagnostic log before checkout, records workflow/event/ref/repository identity and `runtimeExecution=false`, tees resolver verification output, records the exact resolved source/parent and exit status, prints the actual changed-path set, records source cleanliness, and uploads the resolver diagnostic log under `if: always()` with `if-no-files-found: error`.
- The first local materialization command in this attempt mistakenly used unsupported option `--input`; the writer rejected it before producing output. The template edit had already been made, then the command was rerun immediately with the required `--template` option. No repository or Drive state was changed by this local command error.
- Final template artifact `m6-cp3-cb1-entry-r1-apply-compile.template.yml`: SHA-256 `3f6bd960c128d8958cf6623d0d7fe399feb14428fff4cc106c28457936199714`, 4504 bytes.
- Final materialized caller `m6-cp3-cb1-entry-r1-apply-compile.yml`: SHA-256 `1e42325d56af9d5ce335b6213ac38a1b7a0436cf2e12bada1578b12f8315534e`, 4552 bytes. Materialization used `.agents/Directional/tools/write_orchestration_payload.py --template ... --sha256 patch=925be14071546c4a19b274191bf003c8f2c4aa5b0caeac01fd9b334e62e29972`; local YAML parse and caller guard assertions pass. This supersedes caller SHA `dc702bbd8d4056ce81ec3f71b64462b9c95ff83171b42c83e29a0129621341e7`.
- Trigger sequencing requirement: after the owner installs the caller and a continuation creates its marker, do not make any unrelated branch mutation until the Drive apply has pushed and `resolve-source` has frozen the applied commit. The Drive reusable pushes a commit whose parent is the marker/event SHA; an intervening control commit would cause its push or the hardened parent check to fail. Once `resolve-source` has published the immutable applied `source_sha`, later STATUS/control commits do not change compile authority because the compile reusable receives that exact SHA.
- The workflow path remains absent at this continuation check; no marker was created, no patch was consumed, and no compile/package or generated Directional runtime ran.
- Exact remaining intervention: repository-owner installation of materialized caller SHA-256 `1e42325d56af9d5ce335b6213ac38a1b7a0436cf2e12bada1578b12f8315534e` at `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml` as a standalone commit with the marker absent. On the next continuation, verify exact branch bytes, create only the marker, and wait at least through successful `validate`, `apply`, and `resolve-source` before any further repository mutation.


## 2026-10-07T00:06Z race-tolerant resolver finalization

- Hardened the custom resolver further for the bounded-response STATUS rule. The Drive reusable still requires the branch not to advance before its patch push; however, after that push a mandatory closeout STATUS commit may land before `resolve-source` checks the branch. The resolver now fetches full history, proves the marker/event SHA is an ancestor, selects the first first-parent child after that event as the applied-source candidate, proves that candidate's parent is exactly the event SHA, and proves event->candidate changed exactly the four authorized patch paths.
- If the branch has advanced beyond the applied candidate before resolver checkout, every trailing changed path must be exactly `STATUS`; any other path fails closed. This permits the mandatory final beacon after patch push without allowing later source/document mutations to be silently compiled. Compile authority remains the immutable applied candidate SHA, not the later branch head.
- A local synthetic Git-history check passed for `event -> four-path patch -> STATUS`: the resolver selected the patch commit. A corrected negative harness also confirmed a trailing `README.md` mutation is rejected with the expected nonzero guard result. The first negative-harness command used `exit` inside the shell loop and terminated the harness itself; it was immediately rerun using a function return, with the intended rejection observed. No repository/Drive state was affected.
- Reduced the normal `resolve-source` job to job-level `contents: read` permission; the caller's top-level permission union remains required by the Drive, compile-cache, and mailbox reusable jobs.
- Final template artifact now has SHA-256 `16d4686439ee07d3f23b0870345cbc437b35ececb549031db8e03f5586b8500d`, 5315 bytes.
- Final materialized caller now has SHA-256 `37dd5aaa83c081273cda7c3c689078ec1124da9ef5e65c86669e1acdf0e8455d`, 5363 bytes. It was re-materialized through the repository writer from the SHA-placeholder template and passed the local YAML/guard census. This supersedes `1e42325d56af9d5ce335b6213ac38a1b7a0436cf2e12bada1578b12f8315534e`.
- Exact owner intervention is therefore installation of caller SHA-256 `37dd5aaa83c081273cda7c3c689078ec1124da9ef5e65c86669e1acdf0e8455d` at `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml` as a standalone commit with the trigger marker absent. On continuation, verify exact branch bytes, create only the marker, and do not advance the branch until the Drive patch commit is visible. After the patch push, an unavoidable final STATUS beacon is resolver-safe; other branch mutations remain forbidden until `resolve-source` succeeds.


## 2026-10-07T00:08Z least-privilege caller finalization

- Tightened each caller job to the least privilege required by its durable reusable contract while preserving the required top-level permission union: validator and resolver use `contents: read`; Drive apply uses `contents: write` + `id-token: write`; compile uses `actions: write` + `contents: read`; mailbox uses `actions: read` + `contents: write`.
- Re-materialized from the SHA-placeholder template through the repository writer and reran the local YAML/guard census successfully.
- Current final template artifact: SHA-256 `c7ddca2356e756a67d3ae6a778a63fbd1b174ab1affd80a88e33bb9060f21c41`, 5532 bytes.
- Current final materialized caller: SHA-256 `dd18f7fb0a7bdba8f3ee795bfeade099bbe02b5f8fffac66fe822925e3c66355`, 5580 bytes. This supersedes `37dd5aaa83c081273cda7c3c689078ec1124da9ef5e65c86669e1acdf0e8455d`.
- Owner installation must use these current final caller bytes at `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml`, standalone and without the marker. Do not install any superseded caller SHA recorded earlier in this handoff.


## 2026-10-07T00:31Z caller failure-observability finalization

- Current-head CAS was rechecked from patch base `637eb6f217a839ec1f9a6d9871a45b67089736e7` through entry-beacon head `d821b7ec588c3239d2ced871747a7bdacda75302`: 53 commits ahead, 0 behind, merge base unchanged. Only the WIP handoff, source-snapshot mailbox records, and `STATUS` differ; all four patch-authorized source/test paths remain unchanged from the frozen base.
- Removed unnecessary `secrets: inherit` from the schema-validator reusable call; the validator can use `github.token` and does not require repository secrets. Drive apply retains `secrets: inherit` because its reusable contract requires the Google Workload Identity secrets.
- Hardened mailbox failure observability. If `resolve-source` did not publish an applied SHA, mailbox `source_sha` now falls back to the marker/event SHA instead of passing an empty authority. Mailbox `result` now reports the last actually reached job result across validate/apply/resolve/compile rather than reporting `skipped` merely because an upstream phase failed. The summary records all four job results.
- Re-materialized through the repository SHA-placeholder writer and re-ran local YAML/guard checks. Current template artifact: SHA-256 `f6e87960a6e568bc88d6be580349687754a98c77e3a3797d9e4b327915104908`, 5838 bytes. Current materialized caller: SHA-256 `d80a78b140b55d7917c8c589da52d87d2aec666f5470017789191f61ea1696e8`, 5886 bytes. These supersede template `c7ddca2356e756a67d3ae6a778a63fbd1b174ab1affd80a88e33bb9060f21c41` and caller `dd18f7fb0a7bdba8f3ee795bfeade099bbe02b5f8fffac66fe822925e3c66355`.
- Google Drive patch File ID `18a7y5tTEBhVgzFfYBumQ5KgGZSxWz7SC` was rechecked and remains present with exact expected filename and size 29220 bytes.
- Required caller path remains absent on the working branch. Do not retry the connector write that is already known to be rejected. Exact remaining intervention is repository-owner installation of caller SHA-256 `d80a78b140b55d7917c8c589da52d87d2aec666f5470017789191f61ea1696e8` at `.github/workflows/m6-cp3-cb1-entry-r1-apply-compile.yml` as a standalone commit with the marker absent. On continuation, verify exact branch bytes, create only the marker, and accept no patch/compile evidence unless schema validation is GREEN.
- No source/test mutation, patch consumption, compile/package run, test, benchmark, or generated Directional runtime occurred in this continuation.


## 2026-10-07T01:15Z exact-base preservation re-audit

- Re-audited the preserved source patch from the immutable snapshot archive rather than the long-lived extracted analysis trees. The archive `/mnt/data/m6cp3_r1/source.tar.gz` still hashes to `8a96433c6681df765b9a55c133ff047acd191a288c45bcbd52b7826ffaf2df9f`; its metadata binds both event/source SHA to `637eb6f217a839ec1f9a6d9871a45b67089736e7`, file_count 5550, byte_count 98948671, recursive submodules, and `runtimeExecution=false`.
- A fresh archive extraction was made at `/mnt/data/m6cp3_r1/reverify_base_0107/source`. The final preservation patch SHA-256 `925be14071546c4a19b274191bf003c8f2c4aa5b0caeac01fd9b334e62e29972` passes `git apply --check` against that fresh exact base. A fresh applied copy is `/mnt/data/m6cp3_r1/reverify_applied_0107`.
- The older local trees `srcsnap/source`, `patchrepo`, and `work/source` are **not pristine base/candidate authority anymore**. Their test file is an earlier WIP state and must not be used to judge the finalized patch. In particular, fresh-applied `tests/SurfaceCellTransitionQuotientTests.cpp` hashes to `917616ea91dc91f604fd067471885f949f22542397b56accca0dd17314c6b8ef`, while the stale local WIP trees hash that file to `9bbb864ceb597be826f67f0bb3dee868f88b4908cd9a7a62d7414de3d0a316f9`; the stale copy omits the later full relation-identity A5 diagnostics. The earlier handoff statement that all four fresh-applied bytes matched the staged working trees is superseded by this re-audit.
- Fresh-applied hashes for the other three patch paths are: `include/directional/pipeline/RemeshPipeline.h` = `59c3e1178d81a3b0d873f0d0b0a9e6ac12743b21c1b34937f1c88d8bbd51e9cc`; `src/geometry/SurfaceCellTracing.cpp` = `a8946a1cf41ca3e0e7b0e752dcf855c2323a50a7d6b43a7812955c4a5f6f926c`; `src/pipeline/RemeshPipeline.cpp` = `f84323d97a4feb6e3c21754a21cb0815cdfe192eef6239af2a945c0b46e62985`.
- Static census on the fresh-applied tree found no remaining production reference to `HardRailBranchCertificateMismatch` or legacy `InvalidHardRailTransport:branch-certificate`; uniform and periodic producers publish/check `faceBranchRotation`; reciprocal isolation evidence is scoped to the cross-sheet OrdinaryFront branch; focused30 ordinal-12 rotates typed source-face gauges; and the three A5 diagnostic sites include relation kind, first/second cell+corner, and HardRail identity. Existing project C++20 configuration covers the new `std::set::contains` test usage, and `rows_for_region` returns typed `SourceFaceId` rows, matching the ordinal-12 `.index()` usage.
- No source/test patch bytes changed in this re-audit. Future continuation must use the immutable archive/fresh extraction (or reacquire the exact snapshot) for base authority, not the stale analysis trees. The staged Drive patch and current caller remain unchanged.


## 2026-10-07T01:41Z caller freeze and continuation guard

- Re-audited the current materialized caller against the exact durable reusable contracts in the verified fresh snapshot. The caller permission union/job overrides, reusable inputs, eight-target compile boundary, mailbox dependencies, fail-closed schema gate, resolver diagnostics, exact applied-path proof, and runtime-free boundary are internally consistent with those contracts.
- Freeze the temporary caller at SHA-256 `d80a78b140b55d7917c8c589da52d87d2aec666f5470017789191f61ea1696e8` and template at `f6e87960a6e568bc88d6be580349687754a98c77e3a3797d9e4b327915104908`. Do not revise them again unless a newly diagnosed contract/schema/runtime-orchestration defect supplies specific evidence requiring a correction. Repeated speculative caller edits are no longer authorized work.
- The current branch still contains exactly the eight durable workflows; the required temporary caller is absent. The connector has already proven that direct workflow-file creation and Git-tree insertion under `.github/workflows/**` are unavailable in this session, so do not retry those mutations unchanged.
- Next continuation rule: check the exact caller path once. If absent, preserve the current artifacts/state and close the same turn without redoing source/static/caller work. If present, verify its bytes hash to the frozen caller, then create only `.agents/connector-triggers/m6-cp3-cb1-entry-r1-apply-compile.txt` and observe the single authorized run. Before the Drive patch push, make no unrelated branch mutation. After source resolution freezes the applied SHA, compile authority is immutable.
- The old source-snapshot trigger directory remains known cleanup debt. Do not delete its marker directly while `agent-source-snapshot.yml` is push-triggered on that path; retire it later through the non-recursive cleanup workflow after the active Code + Build evidence is secured.


## 2026-10-07T04:36Z split-orchestration correction — supersedes combined caller

- This section **supersedes every prior instruction to install or trigger the combined `m6-cp3-cb1-entry-r1-apply-compile.yml` caller**, including the 18:22, 18:47, 21:31, 22:02, 23:14, 23:40, 00:02, 00:06, 00:08, 00:31, and 01:41 sections above. The previously frozen combined caller SHA-256 `d80a78b140b55d7917c8c589da52d87d2aec666f5470017789191f61ea1696e8` and template `f6e87960a6e568bc88d6be580349687754a98c77e3a3797d9e4b327915104908` are now diagnostic/recovery drafts only. **Do not install or trigger them.**
- Newly completed exact contract inspection shows why the combined design is inferior: `agent-google-drive-reusable.yml` writes `steps.apply.outputs.applied_commit_sha` internally, but declares **no top-level `workflow_call.outputs`**. Therefore a caller cannot bind compile authority directly to `needs.apply.outputs.applied_commit_sha`. The combined resolver only reconstructs source identity from mutable branch history; its first-parent/path guards fail closed on many races but do not create a direct immutable output channel.
- The Drive reusable already publishes the authoritative semantic SHA into its result evidence. Its always-run `Write result` step writes `agent-google-drive-patch-result/result.env` containing `applied_commit_sha=<sha>` (or `unavailable` on failure), and `Upload result` publishes artifact `agent-google-drive-patch-result-${{ github.run_id }}`. The diagnostic log artifact `agent-google-drive-patch-log-${{ github.run_id }}` also records the applied SHA. This is the exact recovery channel for split orchestration.
- **Freeze split orchestration instead:** (1) install/validate/trigger an apply-only caller; (2) observe its terminal run and recover the exact semantic `applied_commit_sha` from the Drive result artifact/log; (3) verify that exact commit and its intended four-path diff; (4) author a separate compile-only caller pinned to that immutable semantic SHA literal; (5) validate/trigger the compile-only caller for the exact eight mandated targets; (6) publish compile mailbox authority using that exact semantic SHA. Do not derive compile authority from later branch head.
- Prepared apply-only template: `m6-cp3-cb1-entry-r1-drive-apply.template.yml`, SHA-256 `540f3dfe01c101e6758636af05033716ac8c1dfc75bb36e693851d2f191a726e`, 1777 bytes. Prepared materialized apply-only caller: `m6-cp3-cb1-entry-r1-drive-apply.yml`, SHA-256 `2f35e7a8ebc5e9e8bcc13153ef9bfdd16f4df68f52d2fe554ecd8a9cbd1dcdd7`, 1825 bytes. The template contains quoted `@@SHA256:patch@@`; the materialized caller was produced through `.agents/Directional/tools/write_orchestration_payload.py` with patch SHA `925be14071546c4a19b274191bf003c8f2c4aa5b0caeac01fd9b334e62e29972`.
- Required repository path for the apply-only caller: `.github/workflows/m6-cp3-cb1-entry-r1-drive-apply.yml`. Its unique marker is `.agents/connector-triggers/m6-cp3-cb1-entry-r1-drive-apply.txt`. It runs the durable schema validator first, then the Drive reusable only when validation reports true, then the mailbox publisher. It contains **no compile job**.
- The apply-only mailbox key is `m6-cp3-cb1-entry-r1-drive-apply`. Its `source_sha=${{ github.sha }}` intentionally identifies the control/marker event only; it is **not** the semantic patch commit. Semantic authority must be recovered from `agent-google-drive-patch-result-<run_id>/result.env` and independently verified before compile orchestration.
- Local YAML parsing and structural assertions passed for the apply-only caller. This is not SchemaStore validation and grants no workflow-validity credit. Under the established connector limitation precedent, owner installation may publish the exact fail-closed caller as a standalone commit **without its marker**; the first triggered run must show the durable schema-validator gate GREEN before Drive apply is accepted as evidence.
- Exact next external intervention is therefore owner installation of **apply-only** caller SHA-256 `2f35e7a8ebc5e9e8bcc13153ef9bfdd16f4df68f52d2fe554ecd8a9cbd1dcdd7` at `.github/workflows/m6-cp3-cb1-entry-r1-drive-apply.yml`, standalone and without the marker. Do not install the old combined caller. After branch bytes are verified, create the apply marker only early enough in a bounded turn to allow the Drive push to settle before the mandatory final `STATUS` write; if insufficient time remains, do not trigger.


## 2026-10-07T06:56Z apply-only caller observability finalization

- Re-read both durable workflow policies in full from the exact verified snapshot and retained `READ_MODE=snapshot`. No local build or generated Directional runtime was executed.
- Re-inspected the exact Drive reusable contract. `on.workflow_call` declares inputs/secrets only and exposes no reusable output for the semantic patch commit. The always-run result writer creates `${RUNNER_TEMP}/agent-google-drive-patch-result/result.env` with `event_sha`, `base_sha`, `file_id`, `patch_sha256`, `applied_commit_sha`, Drive-retirement fields, `runtimeExecution=false`, `job_status`, and `finished_at`. That directory is uploaded as `agent-google-drive-patch-result-${{ github.run_id }}`; the diagnostic log is uploaded separately as `agent-google-drive-patch-log-${{ github.run_id }}`. This is the authoritative semantic-SHA recovery channel after apply.
- Corrected one bounded observability defect in the prepared apply-only caller: when schema validation fails and the apply job is therefore skipped, mailbox `result` now falls back to the validator job result instead of reporting only `skipped`. The caller still runs exactly `validate -> apply -> mailbox` and contains no compile job.
- Current apply-only template `m6-cp3-cb1-entry-r1-drive-apply.template.yml`: SHA-256 `33b220ae028e76d1e46ac45c495a7fe6b77851456c9930ede8a911b458371908`, 1837 bytes. Current materialized caller `m6-cp3-cb1-entry-r1-drive-apply.yml`: SHA-256 `ade5751555e5f110d3a54239581c64b4af096d005bc58a5616485862a19e987d`, 1885 bytes. These supersede the apply-only hashes recorded in the 04:36 section. Materialization used the repository writer with the quoted `@@SHA256:patch@@` placeholder and patch SHA `925be14071546c4a19b274191bf003c8f2c4aa5b0caeac01fd9b334e62e29972`.
- Local YAML parsing and structural assertions passed: the trigger is limited to `.agents/connector-triggers/m6-cp3-cb1-entry-r1-drive-apply.txt`; permissions are the least-privilege union required by validator/Drive/mailbox; the validator targets the exact caller path at `${{ github.sha }}`; Drive inputs freeze File ID `18a7y5tTEBhVgzFfYBumQ5KgGZSxWz7SC`, patch/base/branch/message; mailbox key is `m6-cp3-cb1-entry-r1-drive-apply`; no compile job exists. This local parse is not SchemaStore validation credit.
- The mailbox `source_sha=${{ github.sha }}` remains explicitly **control/event authority only**, because the apply workload consumes the marker event checkout. It must never be used as the semantic source for compilation. After terminal apply, recover `applied_commit_sha` from the Drive result artifact/log, verify that immutable commit and the exact four-path diff, and only then generate a compile-only caller pinned to that literal SHA.
- Combined-caller installation advice remains superseded. The combined caller is diagnostic-only and must not be installed or triggered.
- Exact next external intervention: install the **current apply-only caller SHA-256 `ade5751555e5f110d3a54239581c64b4af096d005bc58a5616485862a19e987d`** at `.github/workflows/m6-cp3-cb1-entry-r1-drive-apply.yml` as a standalone commit with its marker absent. Do not install the superseded apply-only bytes or the combined caller. On continuation, verify exact branch bytes first; create the marker only when enough bounded-turn time remains to observe the Drive push before the mandatory final `STATUS` write.
