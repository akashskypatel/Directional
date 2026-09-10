# M4-CP1-TB1 Execution Record

**Status:** COMPLETE / MECHANICALLY VALID / GATE RED / REVIEW REQUIRED / PACKAGE114 NOT PROMOTED
**Turn:** `M4-CP1-TB1-EXEC`
**Semantic source:** `680f9f1573d3c7e56a273366436463e40e196131`
**Immutable package:** package114, artifact `10142108806`

## 1. Boundary and provenance

TB1 executed only the immutable package114 authority issued by `M4-CP1-CB3`. No configure, build, relink, source
mutation, fixture mutation, selector mutation, package repair, or CP2/CP3 implementation occurred. Ordinary ZIP
extraction preserved the archived executable mode; no `chmod` or package mutation was used.

The first caller attempt, run `34472703151` at event SHA
`ee719697dd28b0644cb46bba8861622fd597a1b4`, was an **invalid orchestration attempt**: malformed workflow YAML
produced zero jobs and no Directional runtime. The caller YAML was corrected only at the control-plane layer and the
unchanged package114 was re-executed. No semantic evidence is credited to that first attempt.

The mechanically valid execution is run `34473066831`, TB job `102857316952`, event/control SHA
`8057babfd9299782c767e68920bc0b1f94d59089`. Result artifact `10150408043` has provider SHA-256
`c12e73d69fc33572ca7e324656db257dad3fc0b8d789482b8447fc540ec4c5cf`; diagnostic-log artifact
`10150408431` has provider SHA-256
`d84daf27417751cee121b28cf062869edfae7e7034b6166bd05c2fe9412ce566`.

## 2. Immutable preflight

Preflight passed completely before runtime:

- artifact ID/name and provider digest matched package114 exactly;
- downloaded archive SHA-256 matched
  `9a87181f771a1814fa854bc2056050b05880b6ec8dfe4ef9c9346102ee26fa36`;
- `metadata/source-commit.txt` matched semantic source
  `680f9f1573d3c7e56a273366436463e40e196131`;
- command-boundary metadata retained `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
  `exactArithmeticBackend=GMP`, and `semanticContracts=compiled-not-executed`;
- GMP and GMPXX discovery/link evidence was present;
- packaged test binary SHA-256 matched
  `5b1064e6025b052aed7aeee66b8e1c3f6218bc73791d55fed4675484f4ea2afd`;
- `libdirectional_core.a` SHA-256 matched
  `0325a5d45181014ff45783596c8d952a14f86d383b46d9f6ba43ccfc92315c4b`;
- every package `SHA256SUMS` entry verified;
- selector373 had exactly 373 LF rows, full SHA-256
  `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`, and accepted first-365 prefix SHA-256
  `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.

Preflight evidence file SHA-256 is
`63822b62e9e15664f190d175f3015df4f5ce34eab6c0817d02be63f2988ddd26`.

## 3. Focused CP1 result — GREEN

The exact eight CP1 identities were executed twice from the same immutable binary. Both runs selected and executed
**8/8**, with **8 PASS / 0 RED / 0 SKIP / 0 MISSING** and exit code 0. The two verdict vectors are byte-identical
(SHA-256 `1de2c1c28c80b304100cda5a57a07277bca8ec4fb604c5415db96af3274363a8`).

This directly runtime-proves the compiled CP1 assertions for compact breakpoint/reverse-incidence symmetry, exact
binary64 ingress, arbitrary-precision cap/radix/objective values, fixed-`M=2` refinement against the independent tiny
exhaustive oracle, genuinely bidirected loop determinism, tamper rejection, and values beyond bounded scalar widths.
The focused runs do **not** by themselves close CP1 because the frozen plan also requires the cumulative selector373.

Resource receipt: focused run 1 wall time `0.02 s`, max RSS `10,716 KiB`; focused run 2 completed below the one-second
summary resolution, max RSS `10,612 KiB`.

## 4. Cumulative selector373 result — RED

The exact 373-row filter was passed unchanged to the same packaged binary. GTest selected and executed **227**, not
373. Verdict classification over the frozen selector is therefore:

- **189 PASS**;
- **38 RED**;
- **0 SKIP**;
- **146 MISSING**;
- accepted predecessor rows 1-365: **181 PASS / 38 RED / 0 SKIP / 146 MISSING**;
- CP1 rows 366-373: **8/8 PASS**.

The selector verdict vector SHA-256 is
`3c80be7aba1388292a6b4eddb015219a298625552855a5cca75314744b46df8a`; the complete raw gtest output SHA-256 is
`b1f48d1d1e8dbdc13493f0436bf6611d5c1657a344dc9684af621a2c35065bda`. Runtime was `137 s` by the harness
summary (`2:17.17` `/usr/bin/time` wall clock), max RSS `27,316 KiB`.

Every one of the 38 selected RED identities threw the same exception before its intended fixture-backed assertions:
`Directional test-data package not found adjacent to test executable`. Package114 contains no adjacent `test-data`
bundle. This is an execution/package-contract failure surface, not evidence that the 38 product assertions themselves
were reached and falsified.

The 146 MISSING identities are not registered in `directional_surface_cell_producer_tests`. Current
`cmake/DirectionalTests.cmake` builds that default producer target from a bounded source list, while selector373
retains accepted identities owned by additional test source files. Thus the frozen cumulative condition
`373 selected / 373 executed` is not satisfiable by package114's single packaged producer binary as currently
constructed. The exact selector was not weakened or edited.

## 5. Regression classification

TB1 creates two **non-stable candidates** and no stable regression count change:

1. **`M4-CP1-TB1-EXEC-CAND-01` — PACKAGE TEST-TARGET COVERAGE MISMATCH / REVIEW REQUIRED / NON-STABLE.**
   146 selector identities are absent from the packaged producer binary. This is a frozen-gate/package composition
   mismatch. It is not priced as a product event because those identities did not execute. Review must decide the
   correct immutable cumulative execution surface (additional packaged test target(s) versus a deliberately unified
   gate binary) without silently deleting accepted selector rows.
2. **`M4-CP1-TB1-EXEC-CAND-02` — PACKAGED TEST-DATA ABSENT / REVIEW REQUIRED / NON-STABLE.**
   All 38 selected REDs have the one identical adjacent-test-data exception. They are grouped under one package
   evidence cause because none reached its intended semantic assertion. Review must decide the authoritative packaging
   correction and whether a re-execution of unchanged semantic source is sufficient.

The focused CP1 identities are green and deterministic; this execution does not establish a CP1 product regression.
The cumulative gate is nevertheless RED exactly as the frozen plan defines it. Stable accounting remains
**47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, accepted packages **113**. package114
is **not promoted**. M3 package113/TB48 remains reviewed semantic runtime authority.

## 6. Immutable postflight

Postflight passed: every package `SHA256SUMS` entry remained unchanged, the binary hash remained
`5b1064e6025b052aed7aeee66b8e1c3f6218bc73791d55fed4675484f4ea2afd`, selector full hash remained
`6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`, and its first-365 prefix remained
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. Postflight evidence SHA-256 is
`70ed2045ef28225ab2b1684aa42366be7dcce32e2c620e40612777d32be5aae4`.

The run summary is `SEMANTIC_RED` because the frozen cumulative gate failed after credible runtime. Result
`summary.txt` SHA-256 is `ee9f0186dd93e5085b79605a749b84782ef65495c1f9de4390e70d75612837bb`.

## 7. Routing

Per the frozen TB1 plan and durable turn policy, a credible runtime RED routes to **`M4-CP1-TB1-REV` — independent
Review + Plan / runtime-free**. Do not retry the gate, rebuild package114, change selector373, add test data, broaden
the packaged binary, or author a corrective CB before that review adjudicates the two non-stable candidates.
