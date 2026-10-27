# CB47 endpoint witness interim investigation — 2026-10-27

**Canonical:** M6-CP3-CB47-RP01-ENDPOINT-WITNESSES (unfinished). This is a source-backed interim finding, **not** the independent Review decision or a CB47 acceptance. Do not enter TB47.

## E1: exact committed correction and compile evidence

- Commit `dabb0970ef2fd2f50dafb934e4050d62fe0f80f6` changes only `tests/SurfaceCellREPackageTests.cpp`: validates authentic hard-rail endpoints as terminal (T), interior rail vertex (R), or interior source-edge carrier (I), using independent source and A1 rail authority. Existing junction/source-transport/FlowRep/arrangement checks remain.
- Verified applied patch SHA256 `58096ec60b261ab12639e112cce3998f76f8208ada048ab207310d289782a6c4`. Apply run [40488789515](https://github.com/akashskypatel/Directional/actions/runs/40488789515) reports `applied_commit_sha=dabb0970...`, runtimeExecution=false. Owner permanently deleted the consumed Drive patch after push.
- Initial compile dispatch [40489153651](https://github.com/akashskypatel/Directional/actions/runs/40489153651) failed parser validation (`unknown request fields: retention_days`); **not a compile failure**. Corrected [compile run 40489392387](https://github.com/akashskypatel/Directional/actions/runs/40489392387) succeeded on exact E1 source. Artifact `12728075441`, ZIP SHA256 `73fb6bc55176e8212666361d35bd37de255db6d8efd5a11fd8fee63f4a704e44`: 28/28 checksum matches, eight required targets, `gmpxx` and `gmp` on verified link line, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No tests run.

## E2: authentic two-carrier A4 certificate still absent

- `tests/SurfaceCellTransitionQuotientTests.cpp:3116–3212` demands **one** A4-produced two-carrier route `(1,4)->(4,7)` with vertex-4 junction. TB46 evidence in the DEFN-E Review lists ten actual **one-step** certificates, zero junctions. Combining two one-step certificates after publication is not valid proof.
- `src/geometry/SurfaceCellTracing.cpp:12837–13045` derives route steps from real retained cell boundary segments. `:18880–18955` pairs chart copies only by exact (component, span, ordinal interval, route steps). `:19474–20630` publishes a route certificate per paired front edge, with junction logic only for routes containing multiple steps (`:20411`).
- **Unresolved producer locus:** why the current 3×3 source, field and size generate only single-carrier front sides, and whether a source-admissible alternative stimulus can generate one genuinely spanning side. Do not construct post hoc two-carrier claims or weaken the RED. No E2 source correction is claimed.

## E3: frozen witness definition contradicts accepted producer contract

- `tests/SurfaceCellTransitionQuotientTests.cpp:4027–4055` demands an A5 `OrdinaryFront` relation with reciprocal A4 `OrdinaryInterior` edges **and** a nonempty route (`edge.route.empty()` causes the selection to skip). It iterates that route's source carriers.
- `src/pipeline/RemeshPipeline.cpp:4892–4903` maps A4 `OrdinaryInterior` pairs to A5 `OrdinaryFront`. **But `RemeshPipeline.cpp:3643–3650` explicitly rejects any `OrdinaryInterior` front edge with a nonempty route**, reporting `InvalidOrdinaryFrontRelation`.
- Therefore no A5-accepted OrdinaryFront satisfies E3's nonempty-route selection, regardless of fixture or source-face permutation. This is a deterministic contract contradiction, **not evidence of a faulty OrdinaryFront producer**. The DEFN-E Review's requirement for an OrdinaryFront with exact reversed nonempty A4 route is incompatible with the production invariant.
- **Required Review disposition:** authorize a nonvacuous E3 witness using authentic A5 relation evidence (candidate: paired source-edge collinear spans and isolation seam transport certificate), reciprocal front-edge identities and separately verified unrelated carrier. Preserve `open-rail-chain` A4 negative; enforce one typed-valid positive and two genuinely A5-reaching negatives. Never change production validation merely to satisfy the impossible test predicate or fabricate a route. E3 remains RED.
- This is a **REVIEW_BLOCKER** to formally completing CB47 under the frozen E3 witness definition. Compilation of E1 alone must not be treated as CB47 completion.

## Immutable gates

TB47 frozen 504-row manifest and selector497 unchanged; CP2 accepted 491/491, stable 66/17/49 debt 1, RP-01 remains open. Current same-turn continuation must not execute binaries or advance to TB47. Source snapshot SHA `9a7695fae6a4fd9c301603b58859d6d271b495e3`, all 5946 file hashes verified. This report supplements (does not supersede) the DEFN-E decision.

