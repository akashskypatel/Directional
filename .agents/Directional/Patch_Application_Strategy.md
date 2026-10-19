# `[ChatGPT Web]` Patch Application Strategy — DURABLE, DO NOT DELETE

> This file requires EXPLICIT USER AUTHORIZATION to modify or delete. Any modifications or deletions must be reverted during documentation drift audit unless explicitly approved by the user.

Historical Directional turns show a consistent empirical GitHub connector write limit of approximately 10 KB per individual write operation. Writes exceeding this size may be silently truncated without the connector returning an error. This is an observed connector behavior rather than a documented GitHub API limit.

Keep direct connector writes for genuinely minor changes when every individual content write is `<=10 KB`. Direct write remains the preferred path for an isolated small document/control change; modified workflow YAML must still satisfy `GitHub_Workflow_Policy.md` schema-validation requirements before execution.

For coherent code or documentation work that is not a genuinely minor direct write, use this standard transport and do not stage patch bytes, compressed Base64, or patch fragments in the repository:

1. **Snapshot** — obtain one exact source snapshot with `.github/workflows/agent-source-snapshot.yml` and download/verify that immutable snapshot once.
2. **Prepare + preserve locally** — edit the snapshot-derived source in the local container, generate one complete `git diff --binary --full-index --no-ext-diff` patch covering both source/code and documentation changes as applicable, verify `git apply --check` plus `git diff --check`, and emit that exact patch as a user-visible downloadable chat/File-Library backup under `RETENTION_POLICY.md`.
3. **Stage externally** — upload the exact verified patch with the `Google Drive` connector to `My Drive/Directional-CI`. Record the returned Google Drive **File ID** and the complete patch SHA-256. Google Drive is transport staging only; the chat/File-Library patch remains the interruption-recovery copy.
   1. Ensure the patch exists as a ChatGPT conversation attachment or connector-managed file and obtain its exact `file_...` reference.
   2. Discover the `mcp__Google_Drive__upload_file` action and inspect its argument schema.
   3. Locate `My Drive/Directional-CI` using `mcp__Google_Drive__search` with `item_type="folder"`. Retain the returned folder ID.
   4. Call `mcp__Google_Drive__upload_file` with `file_uri=<file reference>`, `parent_folder_id=<folder ID>`, the exact patch filename, and `mime_type="text/x-diff"`.
   5. Require `success=true`, `accepted_input="file_uri"`, and a nonempty Drive File ID.
   6. Verify the uploaded object using `mcp__Google_Drive__get_file_metadata`. Check filename, MIME type, size, and parent folder. Do not claim content-hash verification from metadata alone.
   7. Pass the returned Drive File ID and independently established patch SHA-256 to the existing `drive_apply` workflow, following the repository's normal authorization, exact-base verification, and cleanup requirements.
   Do not pass `/mnt/data/...` paths to `upload_file`. It expects a file reference, not a local filesystem path. Do not convert the patch to a Google Doc, Sheet, or Slide; preserve the raw patch bytes.

The important change is limited to the patch-upload transport step. The existing patch format, SHA-256 validation, base-commit checks, path validation, application workflow, and cleanup requirements should remain unchanged.
4. **Mandatory Audit** — Audit the patch to make sure it's not editing any durable documents or sections.
5. **Apply by File ID** — install only the minimal temporary caller/trigger control files required to invoke durable `.github/workflows/agent-google-drive-reusable.yml`. Pass the File ID, exact patch SHA-256, exact patch base SHA, target branch, and commit message. The reusable workflow must fetch the patch by File ID, verify full-patch and embedded diff-body hashes, verify the recorded base and that intended touched paths have not changed, run `git apply --check`, apply, run `git diff --check`, verify the exact changed-path set, commit, and push. Patch transport may not modify `.github/workflows/**`; workflow-file edits remain direct connector changes under the workflow policy.
6. **Move staged patch to trash after success** — only after the patch commit has pushed successfully, `agent-google-drive-reusable.yml` must inspect `capabilities.canTrash`. When true, move the Google Drive patch to trash using the same File ID and report `drive_file_trashed=true`; when false, skip the mutation request and report `drive_file_retirement_required=true` so the owner-authorized Drive control plane can retire it without a deterministic 403. If application/push fails, retain the Drive file and File ID for diagnosis/retry instead of retiring the only remote transport copy.
7. **Retire repository control state** — after result/log evidence and Drive retirement are verified, delete the temporary caller first, then retire its marker and any other temporary repository control files through the normal cleanup lifecycle. Do not leave turn-specific patch payloads or fragments under `.agents/Directional/turn-payloads/`.

Before any remote application, resolve current branch authority. If the branch advanced after the patch base, the reusable workflow must fail closed when any intended path changed; reconstruct/rebase the patch deliberately rather than force-pushing or applying blindly.