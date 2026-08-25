# Architecture M3 CP4c-1 — Artifact-Only Test + Benchmark Report

**Turn:** `M3-CP4c-1-TB-R3`
**Scope:** immutable-package runtime only; 318 required-green + 5 non-gating diagnostics
**Status:** COMPLETE / VALID RED 316/318
**Exact next:** `M3-CP4c-0-DEFN` — REVIEW / definition / planning only; no implementation before that definition freezes the blocking predecessor contract

## 1. Immutable authority

- semantic source: `51f510861a02377d1f45607908191f2fdebdcd33`;
- Code + Build run: `32867889140`;
- immutable package artifact: `9570940997`;
- package SHA-256: `23876c55e51b94ca3a1e5bcfb727a4c0cebce3294fcd2fbda21336b57ae1de16`;
- package internal manifest: **27/27 PASS**;
- required 318 selector SHA-256: `2f2c24acab0e891273c170c82cdc31b6afa3ae4d43e93c95dbdf6d90a88f45bc`;
- accepted 316-prefix SHA-256: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- non-gating 5 selector SHA-256: `9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`.

The corrected runtime verified the downloaded package ZIP against the frozen outer digest, verified all 27 internal `SHA256SUMS` entries, verified the embedded semantic source and both selector hashes, and materialized source only from the immutable package. No repository checkout was used as semantic authority.

## 2. Execution and integrity

The first TB-R3 orchestration run `32871811711` is **INVALID / PRE-RUNTIME**. Its package preflight used an early-exit `tar -tzf ... | grep -q` pipeline under `pipefail`; `grep -q` exited after the match and `tar` observed a broken pipe, so the job stopped before the runtime step. **Zero identities executed.** This is control-plane orchestration only and is excluded from semantic evidence.

The corrected authoritative execution is:

- workflow run: `32872112507`;
- schema-validation job: `97881374699` — PASS;
- artifact-only TB job: `97881418987` — SUCCESS;
- result artifact: `9572545977` — `m3-cp4c1-tb-r3-result-32872112507`;
- result artifact ZIP SHA-256: `06941e750b8c88b295cf43b7d5c27b060321f693f7715eb650128f125d9b4a8c`.

The result artifact was independently downloaded and re-hashed during closeout; its SHA-256 matches the GitHub artifact digest. Exactly **323 fresh processes** executed: 318 required identities followed by 5 non-gating observations. Every process selected exactly one identity; orchestration errors are **0**.

Pre/post package and materialized-source hash inventories are byte-identical. `package-postflight.diff` and `source-postflight.diff` are both empty. All prohibited operations remained false: configure, compile, rebuild, relink, package repair, source mutation, test mutation, fixture mutation, generated discovery, and benchmark execution. Runtime execution was true only for the planned immutable test identities.

## 3. Required gate — VALID RED 316/318

Required result is exactly the plan prediction:

- accepted predecessor: **316/316 PASS**;
- C4 `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing`: **FAIL**;
- C5 `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced`: **FAIL**;
- required total: **316/318 PASS**.

Both C4/C5 still stop at the prescribed sphere's explicit network precondition. The sphere reaches A1 / `FieldTransportAtlas` and A2a rejects `InvalidCandidateTraceTransport` at `singularity=0`, `sourceVertex=0`, `sourceEdge=1-2`. No accepted-prefix identity regressed, so this remains a first-acceptance non-vacuity blocker rather than loss of accepted CP3b behavior.

## 4. Existing non-gating reachability observations

All five diagnostics deliberately fail after publishing their observation and are excluded from the 318 gate.

### Torus

Unchanged:

- source Euler `0`, boundary loops `0`, genus `1`, interior local vertices `72`;
- A1 establishes;
- A2a publishes `0` traces / `0` events;
- A2b rejects `UncutFaceComponentOrbitSeedNotUnique` at `sourceFace=0-1-2`.

This remains deferred to blocked `M3-CP4c-2-DEFN`.

### Mechanical feature

Unchanged:

- source Euler `2`, boundary loops `0`, genus `0`, interior local vertices `152`;
- A1 rejects `IncompleteCycleBasis` at source edge `0-3`;
- `fieldTransportAdjacencyExists=false`;
- `globalEF=1,158`, `localEF=1,158`, `localV=152`, `localF=300`, `localBoundaryEdges=0`.

This remains deferred to blocked `M3-CP4c-3-DEFN`.

### Prescribed sphere reachability

Unchanged stage result:

- source Euler `2`, boundary loops `0`, genus `0`, interior local vertices `98`;
- source topology and A1 establish;
- A2a rejects `InvalidCandidateTraceTransport` at singularity `0`, source vertex `0`, source edge `1-2`;
- no field-aligned network is published.

## 5. Z1 — branch-pairing census confirms the genericity claim

`FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique` reports:

| Witness | Frames | Pairings | Pairing-shape distribution | Ambiguous pairings | Ambiguous % |
| --- | ---: | ---: | --- | ---: | ---: |
| two-ring skew disc | 15 | 60 | `1x2:30, 2x1:30` | 30 | 50% |
| four-triangle fan | 4 | 16 | `1x1:8, 1x2:4, 2x1:4` | 4 | 25% |
| torus | 144 | 576 | `1x2:288, 2x1:288` | 288 | 50% |
| mechanical | — | — | atlas not published | — | — |
| prescribed sphere | 192 | 768 | `1x2:384, 2x1:384` | 384 | 50% |

The accepted two-ring and four-triangle-fan witnesses both have **non-zero** ambiguous continuation authority, so the review's genericity claim is confirmed on accepted witnesses rather than inferred only from the sphere. The torus and prescribed sphere are exactly 50% ambiguous. The four-triangle fan contains eight `1x1` pairings and therefore measures 25% ambiguous overall.

The sphere's actual failing face is itself ambiguous:

- face: `1-2-5`;
- incoming carriers: `1-2`;
- outgoing carriers: `1-5,2-5`;
- incoming multiplicity: **2**;
- `sphereFailingFaceAmbiguous=true`.

This confirms that the published A1 `connections` relation does not encode one resolvable continuation for the trace state that fails in production.

## 6. Z2 — prescribed-sphere failure site confirms the CP4c-0 domain

`FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable` reports:

- site: **`field_aligned_outgoing_carrier`**;
- completed segments: **1**;
- current face: `1-2-5`;
- source edge: `1-2`;
- incoming carriers: `1-2`;
- outgoing carriers: `1-5,2-5`;
- incoming multiplicity: **2**;
- field-transport adjacency exists: **true**;
- production error: `InvalidCandidateTraceTransport`, singularity `0`, source vertex `0`, source edge `1-2`.

Every binding Z2 prediction is confirmed. The failure is not `field_aligned_next_face` and not `topology.transport`; branch transport adjacency exists for the carrier. The trace completed one segment before reaching the ambiguous continuation, so the start attachment, first carrier, initial branch, and first cross-face transport are all viable.

Combined with the Z1 census, TB-R3 confirms the independent review's production-side diagnosis: A1 publishes a Cartesian inflow × outflow relation where A2a requires a function, and the missing within-face position/continuation datum is generic and latent even in accepted witnesses.

## 7. Regression categorization

No accepted-green identity regressed. Stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**; M3 package count remains **39** because this TB created no build package.

Current CP4c candidates are refined as follows:

- `M3-CP4c-TB-R1-CAND-01`: torus and mechanical observations are unchanged and remain deferred to CP4c-2/3; Z1 additionally confirms ambiguous pairing authority is latent in published accepted/closed-surface atlases but does not convert those deferred scope gaps into stable regressions.
- `M3-CP4c-TB-R1-CAND-02`: the terminal-`TraceIntersection` non-vacuity blocker is now localized to a **production A1→A2a contract gap**, not witness invalidity. Z1 proves non-zero ambiguity on accepted witnesses; Z2 pins the sphere to `field_aligned_outgoing_carrier` after one completed segment with multiplicity 2 and valid transport adjacency. It remains non-stable because CP4c-1 has never been accepted and the accepted 316-prefix remains green.
- `M3-CP4c-1-TB-R3-CAND-01`: the first R3 orchestration run's `tar|grep -q` / `pipefail` broken-pipe preflight is resolved control-plane evidence. It executed zero identities and changes no semantic regression totals.

## 8. Completion and routing

`M3-CP4c-1-TB-R3` is **COMPLETE / VALID RED 316/318**. Its required red is the expected honest checkpoint state, while both Z1 and Z2 confirm the review predictions and the `M3-CP4c-0` charter domain.

Under the binding `CB → TB → red → REVIEW + PLAN` workflow, the exact next turn is **`M3-CP4c-0-DEFN`**. That turn is review/definition/planning only and must consume the TB-R3 measurements to freeze exact barycentric-position authority, the within-face continuation rule/rejections, A1 transport-contract shape, accepted-prefix re-proof surface, witness-stage capability, and terminus-datum unification before any implementation is authorized.

Do not rerun TB-R3, patch the sphere, resolve the ambiguity inside A2a, weaken C4/C5, or enter a pairing/position Code + Build turn before `M3-CP4c-0-DEFN` closes.
