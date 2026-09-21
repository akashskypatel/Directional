# M5-CP3-TB1 Artifact-Only Test + Benchmark Report

## Status

`M5-CP3-TB1-EXEC` is **COMPLETE / BLOCKED PRE-RUNTIME / FROZEN PLAN DIGEST DEFECT / ZERO SEMANTIC CREDIT**.

Exact successor: `M5-CP3-TB1-REV`.

No Directional test, benchmark, produced binary, configure, compile, relink, generated discovery, package repair, mode repair, or source/test/fixture/selector mutation occurred in any execution attempt.

## Frozen authority

- Evidence source: `fc2aa5fa68cac890051614c2104979aef4a60d21`
- Candidate artifact: `10615252806`, SHA-256 `1e32fa2b55f84b9097b0d617bcfc1b5f7ad1ab7e5ffc2bdb8e0cde8ea715bf20`
- Candidate root `SHA256SUMS`: 28 entries, file SHA-256 `322b04df9767a80bc246b4b0a03886cc6abb118b8e13147ed8fa1126de74a7c1`
- Candidate source archive SHA-256: `6fe16061079b01079bc53006f102575a5452a950b663807b4f278949ff3ef967`
- Accepted routing artifact: `10592987234`
- Accepted routing artifact provider SHA-256: `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`
- Accepted routing `identity-map.tsv` SHA-256: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`
- Selector430 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`
- First427 SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`

Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316`. Candidate `10615252806` remains unpromoted. Stable accounting remains **49 / 14 / 35**, produced-witness debt **5**.

## Execution attempts

Three workflow attempts occurred. All stopped before valid semantic preflight and therefore contribute zero semantic credit.

1. Run `35544087129` failed before preflight while downloading immutable artifacts through the first Python HTTP path. Result/log artifacts: `10615399779` SHA-256 `5e44a0c8e0e204e75c911107d972fdc3185ec962b742c521296f1ec949f8dffa` / `10615424786` SHA-256 `2b74796283f135ce062525abc543a65c561bda11da7d3b1b54ec04c8fe761945`.
2. Run `35544211517` repeated the same pre-runtime HTTP 401 failure. Result/log artifacts: `10615539791` SHA-256 `433228d7adb17d1a5150ed890834aa71f46a9966ec8758814329b1aba82b3bf2` / `10616011456` SHA-256 `479d79e17215a95f0a08796e57d3d4d6062b931a6790f714dc99fb61c8aa90f9`.
3. Run `35544717675`, after the diagnosed redirect-safe `curl -L` correction, passed workflow-schema validation and driver-byte verification. Candidate artifact `10615252806` then verified at the frozen digest, proving artifact authentication/download recovery. Preflight immediately failed on accepted routing artifact `10592987234` because its provider digest is `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce` while the frozen CP3 TB1 plan records `352c8cfc9c89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`.

Final run result/log artifacts are `10616206801` SHA-256 `48509074dfe81f89133290dc4b8f51454e205ce2e2f1c7df40e3d8553ebfc71c` / `10616186884` SHA-256 `6e91e0eb8ab632ccfea3c491fe44dadc7c0c1a7641068107a24bb5dfb686de01`. The result artifact self-manifest verifies 4/4 files.

## Exact blocker

The historical frozen TB1 plan (folded after Review; resolver `M5_Consolidated_Record.md` §5) freezes the routing ZIP SHA-256 as:

`352c8cfc9c89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`

That literal is only **62 hexadecimal characters** and disagrees with accepted M4-TB3 routing authority. Existing durable accepted records independently preserve the 64-character provider/download digest:

`352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`

The final executor intentionally used the frozen TB1 plan literal, so the mismatch failed closed before routing extraction or any Directional runtime. Changing the expected digest in TB-EXEC would silently amend the frozen plan and exceed the active turn boundary.

## Runtime boundary

Final run `35544717675` records:

- `preflight_completed=false`
- `runtime_started=false`
- `runtime_completed=false`
- `orchestration_failure=true`
- mechanism processes executed: **0 / 9**
- produced processes executed: **0 / 6**
- selector processes executed: **0 / 430**
- benchmark executions: **0**
- configure / compile / relink / generated discovery: **0**
- package repair / mode repair: **0**
- source/test/fixture/selector mutation: **0**

Because preflight never became valid, no M5 production debt is adjudicated, no selector result exists, and no candidate promotion is possible.

## Regression / observation disposition

`M5-CP3-TB1-EXEC-OBS-01` is **OPEN / ORCHESTRATION / FROZEN PLAN AUTHORITY / NON-STABLE**.

Root cause is a malformed 62-character routing-artifact digest literal in the frozen CP3 TB1 plan, not candidate behavior. This creates **+0 stable event / +0 category / +0 recurrence**. Stable totals remain **49 / 14 / 35**, debt **5**.

The two preceding 401 attempts are execution-orchestration recovery evidence only. The third run proves the HTTP correction reached immutable artifact verification and exposed the independent frozen-plan defect.

## Successor requirements

`M5-CP3-TB1-REV` must remain runtime-free and independently:

1. verify the 62-character frozen plan literal against accepted M4-TB3 routing evidence;
2. decide and record the corrected plan authority rather than silently editing execution expectations;
3. preserve candidate `10615252806`, evidence source `fc2aa5fa...`, selector430, focused identities and 445-process order unless Review finds a separate authority defect;
4. authorize a fresh artifact-only execution from process 1 only after the corrected routing digest is durably frozen;
5. keep candidate promotion, production-debt discharge and successor-selector publication prohibited until a mechanically complete TB execution is independently reviewed.
