# TB-REV-171 — along-edge face-piece full gate, independent review (2026-11-23 UTC)

## Situation

**REJECT the full-gate result.** New row 994 passes, but the immutable candidate gives **987/994 PASS, seven RED**. The accepted baseline TB169 remains **993/993 PASS**. This is a continuation of the already counted accepted-green mechanical regression, **not** a new independently established event. Do not promote CP2 back to green from the candidate, CP3/497, D0/H4, or the sphere production result. The next turn is a **single measurement-only Code + Build**; it is not executed in this Review.

## Background and exact authorities

- Review turn `M6-CP3-TB-REV-171-P13-ALONG-EDGE-FACE-PIECE-FULL-GATE`; branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open/draft. No production, test, benchmark, manifest, selector, or workflow source modification in this turn.
- Accepted TB169 run `45104059492`, artifact `14787082075`, outer ZIP SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`; verified **1,994/1,994** internal file hashes.
- Candidate TB171 run `45133081384`, artifact `14799346720`, outer ZIP SHA-256 `b79b5cc26044acd357243c3c8fe7350e6a68e450171400aad6228e059e143d0c`; verified **1,996/1,996** internal file hashes. Candidate package compiled source `462010254fa90bf6c853768019bcfc9132b5c631`, compile run `45130510704`, package `14797941489`, SHA-256 `49824e664c79d13fc1b2ba047bd044303683f41b28df7a3344902e74d84b41cf`, GMP/GMPXX, `runtimeExecution=false`.
- Independently verified source snapshot event and checked-out SHA `643ec10c3a324326d56d57a8eacf3e47ad74f4e9`, snapshot run `45139199860`, artifact `14800813069`, outer ZIP SHA-256 `3170f17fa5cf0b2ae70d389692069999c3e0619d91691969c601f988728c57d4`; inner tar and **5,789/5,789** file hashes verified. This snapshot is later than the compiled source and is **review-only documentary/source inspection authority**, not a substitute for the immutable CB192 runtime package.

## Independent evidence and adjudication

1. Manifest `gates/Architecture_M6_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Case_Manifest.tsv` has **994** unique selected rows, SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6`. Header + first **491** rows independently hash to `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038` (the accepted frozen CP2 prefix). The first 993 selected row identities match TB169 exactly. The added row994 `ArcFaceVisits.FacePiecesAlongOneEdgeReadAsSlides` is PASS. Membership is **1,075** (994 required + 81 deferred), without skipped, abnormal, or duplicate cases. TB171 CP2 is **490/491**, not accepted.
2. Independently compared 993 pairs of raw logs with only the allowed **N1** Google Test duration normalization, **N2** line-end normalization and **N3** whole-record unordered `M3_CP4AB_FRAGMENT_DIAG` comparison. Exactly **22** rows differ after N1–N3, including permitted sphere row979; **21 off-row differences**: `396,397,445,637,638,649,650,652,653,656,658,660,662,665,669,687,784,786,787,788,857`. There are **1,750** baseline and **1,450** candidate complete diagnostic records: **300 removed**, zero added. Row669 also changes non-N3 pipeline-stage text. Fourteen other off-row tests stay PASS but their required evidence is different. Their PASS status is not transcript equivalence.
3. Exact former-PASS-to-RED mechanical controls remain **445, 652, 653, 656, 658, 660, 786**; these are the same seven controls already classified at TB-REV-170. Rows 652 and 656 now fail with `NotProductionReady/global-topology-plan/RegionElectedCutComponentEmpty` at `RegionConstruction`; five others fail downstream plan-presence requirements. Both baseline controls were PASS. The candidate exits 90 with a required-controls failure, and postflight finishes. No compile, relink, new benchmark, or selector generation is reported in either TB result.
4. Source inspection at `src/geometry/GlobalTopologyPlan.cpp` shows the new failure is returned **only after region drafts are elected and one `owned[index]` list is empty** (near the `RegionElectedCutComponentEmpty` return). The diagnostic records do **not** print the elected draft's orbit or which source-face fragment mappings were absent. A globally empty draft is proved; its *cause* is **not** proved. It could be an invalid non-exterior elected orbit, missing face/orbit ownership evidence, or a source-face-boundary classification inconsistency. The current data cannot choose one without guessing.
5. The source `ArcFaceVisits` reader now classifies same-edge face pieces as edge-side-only rather than an interior face chord. Row652 face `(1,4,139)` confirms `traceChordCount=0`, `expectedFragmentCount=1`, `ownerCount=1`, `ownerDeficit=0`. Yet its separate local diagnostic still lists `localFragmentCount=2`, `sharedOwnerChordCount=1` for arc15 segment3; the downstream source segment walk can populate diagnostic local chords even for edge-side pieces. Face `(0,1,102)` still has `traceChordCount=1`, `expectedFragmentCount=2`, `ownerCount=1`, `ownerDeficit=1`; its arc15 segment4 retains local diagnostics. These are **potentially inconsistent receipts, not proof of the empty-draft cause**. Do not fix counts to match by weakening the checker or manufacture an owner.
6. Sphere row979 PASS reports `RegionContainsInteriorSingularity` at vertex 8 and `RegionCertification`. It is a **staged diagnostic reach only**. No sphere plan, verified pure-quad production mesh, new production census or acceptance is established. CB192's one new classifier guard tests the local distinction but is not a full integration oracle.

**Non-vacuity and falsifiability:** the seven same controls PASS on the immutable accepted TB169 baseline and fail on the candidate; the normalization checks loss of 300 complete records even where a test still passes. The new local guard can PASS while the enclosing topology plan fails. Only a positive demonstration of a nonempty independently sourced face-to-draft map and unchanged accepted controls can remove this failure family; a new error code alone is not sufficient.

## Prior obligations and stable accounting

- TB-REV-170 W1/W4: accepted 993-row TB169 and seven-control full gate, respectively; W1 is retained and W4 still **fails** in TB171. W2 sphere-stage result is observed narrowly but not production. W3/RA-235 now requires the exact region-election owner reason. W5 remains Branch B: receipt **before** any repair. W6 and CB190 S4/S6/S7 remain deferred.
- TB-REV-170 adversarial A1: `CutAlongOneEdge` misclassification was corrected by CB192 for the local piece, but **the mechanical plan is still RED**. Do not reactivate the withdrawn CB191 cut-reason patch or infer it solves this later stage.
- TB-REV-168 Q6 C1/C2 continue without executed typed-code witnesses. CP3/497/D0/H4, V3b, Y7, sphere activation/parameter deletion and M7/M8 remain held. No selector or acceptance gate is changed.
- Historical stable ledger remains **67 events / 17 categories / 50 recurrences**, produced-witness debt **1**, deferred **81**. The `RegionElectedCutComponentEmpty` subtype is one unclassified **non-stable candidate** within the existing mechanical regression, not a new stable entry or a second recurrence.

## Exactly one frozen successor — no execution in this Review

**Next turn: `M6-CP3-CB-193-P13-EMPTY-REGION-DRAFT-OWNERSHIP-RECEIPT`** — Code + Build, **measurement only; compile only**. Use the exact CB192 semantic source `462010254fa90bf6c853768019bcfc9132b5c631` and current verified branch authority. Do not change source-face selection, region election, ownership, validators, test pass conditions, manifests, selectors, or fallbacks. Minimal admissible instrumentation: expose the **first empty elected draft's exact draft index, canonical orbit identity, exterior/non-exterior classification, boundary-walk identity, and source-face fragment-to-draft membership reasons**, at the existing rejected mechanical production entry. Reuse existing fields/types and the existing failing control before adding any new diagnostic family. If no exact source authority can justify the receipt without changing behavior, stop for Review rather than inventing semantics.

**Falsifiers and stop rule:** a separately authorized artifact-only TB must show which elected orbit has no owner and why, including a matched positive elected draft and exact face/orbit assignment; verify the receipt belongs to the real failing production path and that a negative manipulation would change the printed cause while preserving RED. The new measurement-only build **must not claim restoration**; expect seven mechanical controls to remain RED until a distinct reviewed correction, and require all first 993 accepted identities plus row994 and the same strict N1–N3 comparison in the later TB. If measurement changes any production verdict, topology decision, or test selection, or if the first failure is different from the recorded `RegionElectedCutComponentEmpty`, STOP and return to Review. No runtime execution in the Code + Build turn; use mandated GMP/GMPXX compile-only workflow, then a separate Test + Benchmark and independent Review. Do not start this successor now.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Manifest `704dcf6c…09c6`; header + 491 rows `483f1101…038`, unchanged |
| Decisive claims independently re-derived | Two outer ZIP digests, 1,994/1,996 internal hashes, 993 paired logs, 994 identities, 1,075 membership, seven RED, 21 off-row differences, 300 missing complete records, source failure mapping |
| Non-vacuity checked | Seven immutable prior PASS controls now RED; 300 missing complete N3 records detected; isolated row994 PASS cannot hide an integration RED |
| Prior obligations discharged/carried | W1/W2 narrow; W3/W4/W5 active, W6/CB190 later; Q6 C1/C2 and CP3/497/D0/H4 held |
| Stable accounting | 67 / 17 / 50, debt1, deferred81; accepted TB169 `14787082075` and accepted CP2 491-row selector unchanged |
| New candidates/obligations recorded | Empty-elected-region candidate remains non-stable; tracker updated, successor owns exact cause receipt |
| ORIENTATION currency line | TB-REV-171, 2026-11-23 UTC, refreshed |
| ORIENTATION §3 / §4 / §7 / §8 | All four refreshed; superseded CB191/CB192-next instructions replaced; carried historical evidence remains |
| CHANGELOG | Review result entry added, no production claims |
| ROADMAP | Current M6/CP3 view refreshed, no milestone advanced |
| Selector manifest | n/a — immutable selected gate and accepted CP2 selector; no selector mutation authorized |
| LESSONS | Existing RA-235 independence and root-producer diagnosis apply; no distinct generalized lesson established |
| Consolidation under CLEAN_UP_POLICY | n/a — reviewed TB169/TB171 and prior review records remain live cited evidence; no safe unrelated archive deletion in scoped review |
| Successor frozen | `M6-CP3-CB-193-P13-EMPTY-REGION-DRAFT-OWNERSHIP-RECEIPT`; receipt fields, independent positive/negative falsifiers, and STOP rule above |
| Turn boundary held | Runtime-free source/artifact review, no source/test/manifest/selector/build mutation |
| review_check.py boundary | Static boundary tool reports clean product/test/fixture/build and selector mutation; ancestry and rewrite-source assertions FAIL on history-free snapshot (not a full PASS) |
| `STATUS` lifecycle maintained | Current turn entered with `Started at: 2026-11-23T08:29:47Z`; final status written last after durable publish/cleanup |
| Pushed to origin, branch in sync | Pending connector patch application and independent head check; synthetic local Git status cannot verify origin sync |
