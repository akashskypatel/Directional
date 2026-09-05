# M3-CP4c-3-TB27-R1 — Artifact-Only Test + Benchmark Report

**Verdict:** COMPLETE / VALID SEMANTIC RUNTIME / SEMANTIC RED / ACCEPTED PREFIX SAFE / ROUTE TO INDEPENDENT REVIEW + PLAN.

## Immutable authority

- semantic source: `eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`
- immutable CB31 package artifact: `9961564041`, SHA-256 `ca1b69de319fba92e0c6accc580e698f2430505eb811e821c03d44e6629263cf`
- selector 406: `efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`
- formal run/job: `33946094875 / 101252363079`, SUCCESS
- result artifact: `9963419649`, SHA-256 `adaee20abd667108dbf7ffc0e3db8f0d2f85f9682a15434b83d6291982f1e026`
- diagnostic-log artifact: `9963419830`, SHA-256 `6ea8381fed0ebd501957961dc6f8b483fb8a355d003d1b39aede7f59f05c855d`
- ledger SHA-256: `8da2002701437c5d0c4a57d613e24195f4f690d1ae4494da1234d58bb9a24da5`
- identity-map SHA-256: `b071f8e60b2458d9303aa017032582a25fbfd5e1eb8c933bdec2ef1049a20b2b`

The formal run downloaded the immutable CB31 package by artifact ID and independently rechecked both the provider
digest and downloaded ZIP digest. Selector 405/403/401/397/365 exact-prefix authority passed before runtime.

A prior attempt, run `33946019995`, stopped in preflight before any Directional runtime because a filesystem census
hash had been frozen from a different extraction environment. Its boundary records
`runtime_started=false;orchestration_failure=true`. The correction changed only the harness to compare runner-local
pre/post censuses while retaining artifact digest and internal `SHA256SUMS` authority. No process result from that
invalid attempt is semantic evidence.

## Execution boundary

All **406** identities executed exactly once, in selector order, one identity per fresh process.
`orchestration_failure=false`, `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, and
`execution_view_verified=true`. Configure, compile, relink, generated discovery, package repair, mode repair,
benchmark execution, and source/test/fixture/selector mutation were all false.

The immutable package and packaged-source byte+mode censuses are exactly equal before/after on the same runner, and
the execution-view census is also equal. Binaries were hard-linked from the immutable package; fixtures were copied
only from the immutable packaged source and resolved through the sibling `test-data` consumer rule.

Census hashes:

- package: `470859572b8f82c3d982677b71672f24fd616c9d5e926b579da5aa12662d347a`
- packaged source: `d6b69a68d582e20847346af187189e17fb4d9a53dc6d8bc1aeb08ef2bbbc283d`
- execution view: exact pre/post census equality recorded by the result artifact

## Ledger

**399 PASS / 7 RED.** Accepted prefix **1–365 = 365/365 PASS**. RED ordinals:

`366, 367, 368, 369, 370, 374, 398`

Relative to TB26-R1, ordinal **393 recovers RED → PASS**. Ordinals **404 and 406 PASS**. Ordinal **398 remains
RED** and unchanged as the strong ownership-totality gate. There is no accepted-green loss.

Key gate results:

| Ordinal | Result | Runtime fact |
|---:|:---:|---|
| 393 | PASS | `sourceFaceCount=300;ownerMapCount=300;componentFaceCount=191;certifiedOwners=0:191,1:191,3:191;allEqual=false` |
| 398 | RED | strong `proves_cellularity()` ownership-totality gate remains false |
| 404 | PASS | certifier component 0 fully publishes 76 boundary rows, 4 interior-arc rows, 53 vertex-transit rows, 46 seed-attribution rows |
| 406 | PASS | plan/failure and certifier census partition identities/digests publish with `matchesFailingComponent=false` |

## TB27 runtime diagnostic findings

### 1. CK8 publication is complete; the static all-bridges prediction is refuted on the certifier partition

Ordinal 404 names the certifier census object as component 0 with **214 faces**, face-set digest
`7937364815223192706`, domain `NotTraceCut`, 76 boundary rows, 4 interior arcs, 53 vertex transits and 46 seed
attributions. The four complete interior-arc rows are:

| Arc | Kind | Forward orbit | Reverse orbit | Runtime relation |
|---:|---|---:|---:|---|
| 14 | Trace | 0 | 1 | different / separating |
| 20 | Trace | 0 | 0 | equal |
| 22 | Trace | 0 | 3 | different / separating |
| 24 | Trace | 0 | 0 | equal |

Therefore **2 of 4** certifier interior trace arcs have different forward/reverse face-walk orbits. The TB26
independent review's falsifiable static prediction that all four rows would have equal orbits is **refuted** for the
certifier component. This is runtime evidence only about the certifier `NotTraceCut` partition.

`M3-CP4c3-TB26-REV-CAND-01` is discharged as an evidence-publication defect: the exact rows and deciding fields are
now externally auditable and ordinal 404 PASSes.

### 2. CK9 proves the census and failing component are different runtime objects

Ordinal 406 publishes:

`failingComponent=0;failingDomain=EmptyFragmentOrbits;failingFaceSetDigest=17919102493633069558;`
`censusComponent=0;censusDomain=NotTraceCut;censusFaceSetDigest=7937364815223192706;`
`matchesFailingComponent=false`.

This is the load-bearing result. The 191-face ownership failure is raised on the plan's
`EmptyFragmentOrbits` partition; ordinal 404's 214-face census is the certifier's `NotTraceCut` partition. The two
face-set digests differ and the product explicitly reports **false correspondence**. Consequently, the two
separating arcs measured by ordinal 404 cannot be promoted into evidence about the failing plan component.

This runtime-proves the central facts behind `M3-CP4c3-TB26-REV-CAND-04` and
`M3-CP4c3-DEFN-R3-CAND-01`: duplicated constructions are producing different partition objects, and the diagnostic
census runs on the one that does not raise the ownership failure. The earlier **76 versus 97** boundary discrepancy
remains a lawful domain distinction, now paired with explicit 214-versus-191 face-count and digest evidence.

### 3. Ordinal 393's stale arity contract is repaired without hiding the owner conflict

Ordinal 393 now PASSes because it checks **distinct source-face coverage** and untruncated owner publication rather
than forcing one observation row per component face. Runtime still publishes the full conflicting owner population:

`componentFaceCount=191;certifiedOwners=0:191,1:191,3:191;allEqual=false`.

So the contract repair removes only the false rejection; it does not choose a winner or make the ownership frontier
green. `M3-CP4c3-TB26-REV-CAND-03` is discharged as test-authority debt.

### 4. The product frontier remains honestly RED

Ordinals **366/367** remain the open ownership frontier and continue to fail closed; **398** remains the unchanged
strong ownership-totality gate. Ordinals **368/369/370/374** are carried surfaces with separate owners and no
cross-cause merge is inferred. The runtime does **not** decide whether the 191-face failing plan component lies
inside one certified face: the newly measured separating arcs belong to a different 214-face certifier component.
`M3-CP4c3-TB25-REV-CAND-02` therefore remains undecided for the failing object.

## Resource evidence

- longest identity: ordinal 137, **26.95 s**
- peak RSS: ordinal 147, **18,640 KiB**
- all identity invocations completed within the frozen 180-second per-process timeout

## Accounting and routing

No accepted regression occurred and no new stable event/category/recurrence is justified. Stable accounting remains
**44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic M3 package count
remains **92**. CP4c-3 remains **OPEN**.

Because this is a valid **semantic RED** TB, the mandatory route is the separate
**`M3-CP4c-3-TB27-INDEPENDENT-REVIEW`**. No retry, corrective CB, selector mutation, barrier change, partition
unification, or owner-selection heuristic is authorized before that review.
