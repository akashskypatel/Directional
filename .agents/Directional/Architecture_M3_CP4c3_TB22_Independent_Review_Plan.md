# M3-CP4c-3-TB22-REV — Independent Review + Plan

## Boundary

**Independent REVIEW + PLAN, STATIC ONLY.** Review the immutable TB22 evidence and source definitions; do not edit product/test/fixture/selector/build logic, configure, compile, link, execute Directional binaries, run tests/benchmarks, regenerate evidence, or claim a correction was implemented. A later Code + Build or DEFN turn is not pre-authorized until this review adjudicates ownership.

## Evidence authority

- Semantic source: `d69729a69a40b020968ed6ef1fbc1bc788284518`.
- Immutable package: artifact `9919225745`, `sha256:7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`.
- Selector 393: 393 identities, `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`.
- TB22 run/job: `33826248118 / 100879465830`.
- TB22 result/log artifacts: `9920122224 / 9920122598`, digests `862d3a4ccb7bc6a2dca1c1b6cda01fba7b21ca0d458c046f296e94fac45f0fab` / `67a3e1878a4f4985c80c077fb780fe72906a2f62a140bed968e45ace4f33a65a`.
- Complete ledger: 387 PASS / 6 RED; accepted 365/365; REDs 366,367,368,369,370,374; ledger SHA-256 `4998ca25b1477c2a32299bc3eb3d552e3ea9b0e2ccbf0eb4894393964f29dbbe`.
- Package census: pre/post identical at `7e0c552c79281f97b7553406acd44383ff867197f36da54cd306ac9258fa2b74`.

## BZ0 — Re-establish exact authority

Verify the evidence/source/selector/artifact identities above, the complete 393-row ledger, accepted-prefix 365/365 result, and package immutability. Prove that later orchestration/documentation commits did not alter the semantic source under review. Treat the early cleanup failure as orchestration-only only after confirming its removal/comment steps were skipped.

## BZ1 — Adjudicate the runtime gate and ordinal 391 closure

Confirm the six-RED set and that 371/372, 391, 392 and 393 each selected exactly once and PASS. Confirm ordinal 391's sphere half is explicitly `SKIPPED,reason=ordinal368-open` while its mechanical/torus assertions execute. If so, close `M3-CP4c3-TB21-CAND-02` as runtime-proved/non-stable without changing stable accounting.

## BZ2 — Validate what `projectionFaithfulnessResidual=0` actually proves

Inspect the source implementation and frozen definitions around the source-face component projection, certificate face ownership, and `componentBarriers`. Establish independently whether the residual exactly counts adjacent **uncut** source-triangle pairs in different certified actual-complex faces whose shared source edge is absent from `componentBarriers`.

Check for false-zero routes: missing certificate attribution, filtered boundary classes, ambiguous owners, omitted edges, truncation, or a construction that measures a weaker relation than the stated faithfulness premise. Do not accept the diagnostic name as its proof. If the implementation does measure the intended relation completely, record that zero residual rules out the missing-barrier/different-certificate-face branch for this witness.

## BZ3 — Inspect the two minority seed rows at the production rule

For source edges `10-79` and `29-35`, reconcile all retained facts:

- seeds `3` and `1` respectively;
- `seedRule=edgeOrbitEvidence`;
- `otherSideLabeled=true`, `labeledFaceOwnerCount=2`, `barrierClass=none`;
- component/labeled source faces `10,79,151` ↔ `10,11,79` and `28,29,35` ↔ `29,35,91`;
- certificate-face pairs `3/3` and `1/1`.

Trace the exact production seed-read rule in `GlobalTopologyPlan` and identify which object each seed orbit names. Contrast that edge-orbit evidence with the certificate face that the unlabeled component is being projected into.

## BZ4 — Derive the seed-selection contract independently

Starting from the frozen region/cut/certificate invariants rather than current output, derive what seed information is sufficient and necessary to attach one connected uncut source-face component to the certified region structure. Decide whether an edge-level face-walk orbit can legitimately differ while both sides belong to the same certified face, and whether such evidence should contribute distinct component seeds.

Preserve the uniqueness guard as a safety property unless the independent derivation proves a different invariant. Do not collapse multiple seeds merely because this fixture currently has `[0,1,3]`; any correction must generalize to arbitrary valid meshes and maintain deterministic ownership.

## BZ5 — Choose the next owner, or stop for definition work

Only after BZ2–BZ4:

- authorize a **Code + Build seed-rule correction** if the normative contract is already clear and current `edgeOrbitEvidence` is demonstrably the wrong representation for component ownership;
- authorize **DEFN** only if the frozen definitions genuinely fail to state which certified object owns an uncut source-face component or otherwise make the required rule ambiguous;
- do **not** authorize a barrier-set change merely to force uniqueness if BZ2 confirms faithful same-certificate projection with residual zero.

Specify the smallest sufficient correction and its invariant. No implementation occurs in review.

## BZ6 — Keep unrelated REDs and debts independently owned

Reconfirm 368, 369, 370 and 374 retain their existing owners and evidence. Ordinal 367 may co-reach 366 but must not be used to infer a broader common root without source/evidence proof. Keep vertex-30 and finalize/contact fall-through separate. Stable regression accounting remains 44 / 14 / 30 unless review finds genuinely new stable evidence; produced-witness debt remains 5 unless a debt is independently discharged.

## BZ7 — Freeze successor validation obligations

Any authorized correction must preserve:

- accepted ordinals 1–365 = 365/365 PASS;
- the seed-uniqueness safety invariant or its independently justified replacement;
- the certified actual-complex cellularity evidence;
- 371/372 closure;
- ordinal 391's dependency decoupling;
- required-green 392/393 diagnostic contracts unless review explicitly supersedes them with stronger non-fixture-specific evidence;
- separate ownership of 368/369/370/374.

Define the next selector/test implications and artifact-only validation plan before authorizing implementation. Do not add a fixture-specific branch or lower any existing assertion merely to clear ordinal 366.

## BZ8 — Close review and establish one exact successor

Produce one independent review record that states the adjudicated object model, the status of `M3-CP4c3-TB21-CAND-01`, the exact next owner, and the bounded successor measures. Update `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md`, tracker/TODO/handoff, and fold superseded per-turn records according to cleanup policy. Stop at the review boundary; do not execute the successor in the same turn.
