# Architecture M3 CP4c DG1 — Artifact-Only Diagnostic Execution Report

**Status:** DG-EXEC COMPLETE / GREEN; INDEPENDENT DG-REV REQUIRED
**Turn:** `M3-CP4c-DG1-DG-EXEC`
**Semantic source:** `428e0ecb6f769b501c99405ae2a90c24d5401cca`
**Immutable package:** `9536499549`

## Authoritative result

Corrected authoritative run/job `32776212123 / 97587757347` completed successfully on GitHub-hosted
Ubuntu 24.04. It executed the frozen predecessor 304 selector followed by the frozen CP4ab 12 selector,
one exact identity per fresh process.

- predecessor: **304/304 PASS**
- CP4ab: **12/12 PASS**
- combined: **316/316 PASS**
- process count: **316**
- orchestration errors: **0**
- first structured typed rejection: none
- diagnostic consumed: **1/2**
- acceptance attempt consumed: **0**

Machine evidence records `runtimeExecution=true` and all of `configure`, `build`, `relink`, `repair`,
`generatedDiscovery`, `sourceMutation`, `testMutation`, `fixtureMutation`, `selectorMutation`, and
`packageMutation` as false. Post-cleanup temporary runtime material was absent.

## Immutable inputs and artifacts

- package ZIP SHA-256: `4c64c0c3ea872dbf889c4de398ed40f9e0193fce534ee6117348e3b7a5514660`
- source archive SHA-256: `33e546764b3b3017fbb043cfd91a4366a3ae27244861ade457743fcf10cf49ac`
- accepted selector evidence artifact `9531769503`, SHA-256 `1b4b3784d55f398d113b18c5bc84543cad9f03c48d329d91005598d63ed801fc`
- predecessor 304 selector SHA-256: `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`
- CP4ab 12 selector SHA-256: `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec`
- combined 316 selector SHA-256: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- result artifact `9538137947`, SHA-256 `e5ed2cea7b0b351bbfce6a0252a8ae6331107387feaf84be6500cd0119cb26a7`
- execution log `9538138294`, SHA-256 `626c6b7056db49cb02fb733919f18fab26d71c765dc9ce65def5ec456959691e`
- control log `9538138652`, SHA-256 `e4655e096632e5136a9e46c3ba9dd66e4b60fae84249e8c0ea6d722d97d19908`

Pre/post package, accepted-result, and source-archive digests were byte-identical. Package manifest
preflight was exactly 27 entries with zero duplicates, missing members, or extras.

## Non-authoritative first execution

Run `32775399340` reported 26 predecessor reds while all 12 CP4ab identities passed. This run is
**NON-AUTHORITATIVE PROCESS EVIDENCE**: the harness materialized packaged source in a temporary path,
while several immutable test binaries contain absolute fixture-source paths derived from the original
compiled workspace. The resulting missing fixture inputs caused the apparent failures.

The correction changed only orchestration: packaged source was materialized at the runner workspace
expected by the immutable binaries. No package, product source, test, fixture, selector, expectation,
or identity bytes changed. The corrected runner was schema-validated successfully by run
`32776159932` before the authoritative retry. All 26 apparent reds then passed.

This process issue does not create or reopen a stable product regression. Stable accounting remains
**42 events / 14 categories / 28 recurrences**, produced-witness debt **5**, and M3 package count **35**.

## Handoff

DG-EXEC green does not accept CP4c and does not authorize CB2 directly. Exact next is separate
`M3-CP4c-DG1-DG-REV`, with no runtime. It must independently verify the GitHub run/job and downloaded
artifact evidence defined by the DG1 plan. Only **VERIFIED GREEN** may unblock `M3-CP4c-CB2`.
