# M3-CP4c-3-TB28 R2 Artifact-Only Test + Benchmark Report

## Status

`M3-CP4c-3-TB28` produced one valid semantic artifact-only runtime on the immutable
CB32 package. The 407-identity required-green selector passed in full. This closes
the TB28 evidence-collection turn only; it does **not** accept the checkpoint or
authorize a product correction.

Under CL8, the exact next turn is
`M3-CP4c-3-TB28-INDEPENDENT-REVIEW`. No further source-face ownership diagnostic
or product correction may be selected before that review freezes the correction.

## Immutable authority

- Compile source: `098ac7d93ea203222dd0ac50cdb68667744f0fd4`
- Compile artifact: `9975737868`
- Compile artifact SHA-256:
  `16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec`
- Runtime binary SHA-256:
  `b31d41981114475c6149ea25a0c9db04600c8e83db769e8ee3b070179c1d4065`
- Runtime binary size: `24381304`
- Selector:
  `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_407.txt`
- Selector rows: `407`
- Selector LF SHA-256:
  `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`

## TB28 execution evidence

### R1 — non-semantic orchestration failure

Run `33990315861` failed before runtime because the harness assumed an incorrect
`SHA256SUMS.txt` package layout. No product binary invocation occurred and R1
contributes no semantic evidence.

### R2 — authoritative semantic run

- Workflow run: `33990951740`
- Fresh artifact-only execution job: `101373825038`
- Verification job: `101374345712`
- Result artifact: `9976662518`
- Result artifact SHA-256:
  `970573beb31bc43bb2cbcd4dee957edfb2f23c0c543edfe9997c5dcfc487053d`
- Log artifact: `9976662690`
- Log artifact SHA-256:
  `4272bd5fc1750d19c9fceb94daf3be8367b05d6fa9e13828fc6a97c1c6fe44d`

The run completed successfully with the immutable package and selector identities
verified before runtime. Execution-boundary evidence records one artifact
download, zero local builds, zero source checkouts, and a runtime start.

All mutation flags were false before and after runtime:

- `sourceMutation=false`
- `testMutation=false`
- `fixtureMutation=false`
- `selectorMutation=false`

Postflight verification also records the runtime binary and selector unchanged and
the package manifest valid.

## Full required-green gate

- selector rows: `407`
- passed rows: `407`
- failed rows: `0`
- crashed rows: `0`
- timed-out rows: `0`
- missing rows: `0`
- `selector407FullGatePassed=true`

Every selector identity ran in a fresh child process with one binary invocation per
child process.

## CL6 / CL7 semantic measurement

The authoritative R2 evidence reports:

- failure reason: `ReliefTopologyBuildFailed`
- `quadPatchIndex=0`
- failing plan component: `1`
- candidate face count: `27`
- `candidateFacesEqualCensusComponent=false`
- `candidateFacesSubsetOfCensusComponent=true`
- `censusFailureCount=0`
- failing-plan interior arc count: `101`
- published failing-plan interior arc rows: `101`
- `failingPlanInteriorArcRowsTruncated=false`

The decisive published row is:

`arc=(0,2):sourceFace=0:certifierComponent=0:planComponent=1:notTraceCutReason=TerminalSlit`

This is direct evidence that source face `0` is named in different components by
the certifier and plan partitions for the measured failing-plan arc, while the
candidate face set is a strict subset rather than an equal set.

## Interpretation boundary

TB28 validates the CB32 diagnostic publication and measures the partition mismatch.
It does not establish which product behavior must change and does not authorize a
barrier, attribution, seed, partition, or `terminalSlit` semantic modification.

The root cause and corrective action therefore remain **unfrozen** until
`M3-CP4c-3-TB28-INDEPENDENT-REVIEW`.

## Verdict

**TB28 artifact-only evidence: VALID. Full selector407 gate: GREEN. Checkpoint:
SEMANTICALLY UNACCEPTED PENDING MANDATORY INDEPENDENT REVIEW.**

Exact next:
`M3-CP4c-3-TB28-INDEPENDENT-REVIEW`.
