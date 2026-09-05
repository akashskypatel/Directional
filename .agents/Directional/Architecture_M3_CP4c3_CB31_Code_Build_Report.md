# M3-CP4c-3-CB31 — Code + Build Report

**Turn:** `M3-CP4c-3-CB31`
**Disposition:** **COMPLETE / COMPILE GREEN / RUNTIME NOT EXECUTED / SEMANTICALLY UNACCEPTED**
**Scope owner:** CK8–CK9 of `Architecture_M3_CP4c3_TB26_Independent_Review_Record.md` (folded into
`M3_CP4c_Consolidated_Record.md` at `M3-CP4c-3-TB27-INDEPENDENT-REVIEW`)
**Exact successor:** `M3-CP4c-3-TB27` — artifact-only Test + Benchmark on selector 406.

## 1. Boundary and source authority

CB31 is a Code + Build turn only. It publishes evidence already computed by CB30, repairs two test contracts that
were stale against that publication, and names the two partitions involved in the ownership failure. It does not
choose an owner and does not change product topology or barrier semantics.

- frozen input authority used for implementation: `d70312ee97ea0943f34175d128b04e3e70057e22`;
- semantic patch commit produced by Drive apply:
  `751106491e2440fb17b3fef9e42ccc33bd3d992c`;
- exact clean semantic source compiled after temporary Drive-control retirement:
  **`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`**;
- post-compile temporary control cleanup is content-identical to that semantic source;
- `runtimeExecution=false` throughout this turn.

The pre-CB31 semantic runtime authority remains TB26-R1 on CB30 source
`e045bf7147afc02bd90eff4822e4b609edbaba66` / package `9957324848`: **397 PASS / 8 RED**, accepted
**365/365**. CB31 compile success does not replace or reinterpret that runtime ledger.

## 2. CK8 implementation — publish the deciding rows

CB31 serializes the complete failing-component evidence surface without truncation:

- **interior arc rows:** arc identifier, typed arc kind, `forwardOrbit`, `reverseOrbit`;
- **seed attribution rows:** `sourceEdge`, `componentFace`, `oppositeFace`, orbit, typed attribution rule;
- **boundary-edge rows:** `sourceEdge`, `componentFace`, `oppositeFace`, barrier class, barrier presence,
  opposite-face trace-cut state, and side-owner presence;
- **vertex-transit rows:** trace, segment index, source vertex, non-barrier adjacency and optional adjacent
  edge/face information;
- component face count and stable face-set digest.

A shared source-face-set digest helper is used by both diagnostic authorities so the comparison is over the same
canonicalized face-key representation.

Ordinal **404**, `SurfaceCutGraph.UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure`, is strengthened in
place. It requires all four publication truncation flags to be false, validates the face-set digest, and requires
every published interior-arc row to carry both orbit fields. It remains a publication/completeness gate and asserts
no predicted orbit value.

Ordinal **393** keeps its identity and ordinal but drops the stale one-observation-per-face arity assertion. It now
requires the untruncated owner observation surface and equality between the set of distinct observed source faces
and the failing component face set. The multi-owner observation multiset remains fully published.

## 3. CK9 implementation — name the two partitions

CB31 adds typed partition identity to the certifier census and the plan failure locus.

The certifier side publishes:

- domain rule `NotTraceCut`;
- typed barrier composition for cut-graph cut edges, embedded mandatory/cut arc source edges, and non-terminal
  trace-carrier edges;
- component face-set digest.

The plan side publishes:

- domain rule `EmptyFragmentOrbits`;
- typed barrier composition for `mandatoryEdges`, `traceTouchedEdges`, and `cutEdges`;
- failing-component face-set digest;
- the corresponding certifier census identity/digest when present;
- an explicit boolean stating whether the certifier census component face set equals the failing plan component
  face set.

This is diagnostic authority only. No partition is unified and no equality is assumed.

## 4. Selector authority

CB31 adds:

`.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_406.txt`

Authority:

- identity count: **406**;
- LF SHA-256:
  **`efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`**;
- selector 405 is the exact 405-line prefix;
- selector 405 remains byte-identical at
  `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7`;
- the single appended identity is
  `GlobalTopologyPlan.UncutComponentCensusNamesThePartitionItDescribesAndWhetherItMatchesTheFailingComponent`.

The new identity requires both partition identities, both digests, and publication of the correspondence/match
boolean. It deliberately does **not** require that the boolean be true.

## 5. Compile evidence

GitHub Actions compile authority:

- run: **`33940038189`**;
- compile job: **`101235542774`**;
- exact compiled source from package metadata:
  **`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`**;
- result artifact: **`9961564041`**,
  SHA-256 **`ca1b69de319fba92e0c6accc580e698f2430505eb811e821c03d44e6629263cf`**;
- persistent log artifact: **`9961564295`**,
  SHA-256 **`f05d03dfe8457fe93c49a086915f1a69069ceb50726a02f0463887a734b4d73a`**;
- preflight exit code: **0**;
- build exit code: **0**;
- source status before configure, after configure, after build, and final: clean;
- all **28** entries in the result artifact's internal `SHA256SUMS` verified against the downloaded package;
- command boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
  `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`.

The approved compiled targets are exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

The package's GMP evidence records `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and
`/usr/lib/x86_64-linux-gnu/libgmp.so` on the test-link command. No Directional executable was run.

## 6. Patch transport and preservation

The coherent CB31 implementation was preserved as a complete Drive-backed patch before remote application.

- patch SHA-256:
  `ad151f3d476cd896d90b27fdec363bffde5839aed1ea34a6e64916c3708f3a9d`;
- embedded diff-body SHA-256:
  `1408da76f184d7b2708b05679f1265c93871d3afcd78549ce432972f3221b131`;
- Drive apply run: **`33939858921`**;
- Drive apply result/log artifacts: `9961438306 / 9961438600`;
- apply job succeeded and pushed semantic commit
  `751106491e2440fb17b3fef9e42ccc33bd3d992c`;
- the reusable workflow reported owner cleanup required for the staged Drive file; it was permanently deleted
  after successful application;
- temporary Drive-apply workflow and marker were retired workflow-first.

The compile caller and marker were likewise retired workflow-first after compile evidence was captured. Their
cleanup history has no net file delta relative to semantic source `eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`.

## 7. Scope audit

CB31 changes no behavior that can resolve the ownership RED by itself:

- no barrier added or removed;
- no attribution rule changed;
- no seed winner selected;
- no plan/certifier partition unified;
- no `terminalSlit` handling changed;
- ordinal 398 remains the strong ownership-totality gate;
- accepted identities 1–365 are not changed;
- selectors 397/401/403/405 remain byte-frozen;
- no Directional runtime, benchmark, or semantic acceptance execution occurred.

The independent review's prediction that the four certifier interior arcs are bridges remains a prediction.
Likewise, the plan/certifier component match boolean has not been observed on the runtime witness. Compile evidence
cannot answer either question.

## 8. Accounting and exact successor

Stable regression accounting is unchanged at **44 events / 14 categories / 30 recurrences**. Produced-witness
debt remains **5**. CB31 advances semantic M3 package count from 91 to **92**, but package 92 is compile-green and
semantically unaccepted.

**Exact next: `M3-CP4c-3-TB27`.** Execute selector 406 artifact-only on immutable package `9961564041` / source
`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc`, one identity per fresh process, with no rebuild, repair, package
mutation, source/test/fixture/selector mutation, or other semantic change. TB27 is the first turn authorized to use
the CK8–CK9 publication as runtime evidence.
