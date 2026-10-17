# R3 — checked factory nonrail star-manifoldness static audit (2026-10-09)

**Scope:** Evidence-only audit inside unfinished `M6-CP3-CB1-ENTRY-R3` Code + Build. **Not** a new Review verdict, a production change, a Test + Benchmark run, a recovered R2 failure, or a license to close R3. No code, test, selector or workflow modified.

## Exact-source authority

Semantic source `f135946f1007c35960624a368df5f58318fd98e7`; 8-target GMP/GMPXX compile run `37991952457`, immutable package `11644984310`, ZIP SHA256 `e73793ed37a8663408d8615e4bd1b258ed598180aa6ea3d5fe05815584ef28e6`. Independently verified internal `SHA256SUMS` **28/28**, embedded semantic commit, preflight/build exit 0, all eight targets, GMPXX/GMP linker evidence, five clean source receipts and `runtimeExecution=false`. Comparing semantic source to active branch yielded only documentation/control/mailbox/STATUS changes, not source/test/CMake/workflow changes.

## Narrow question and source conditions

Would a 3+-face *nonrail* source spoke at a HardRail junction evade `SurfacePhaseFrontProduct::make` because the factory explicitly counts HardRail edge incidences but does not separately count nonrail sector step incidences?

At `src/geometry/SurfaceCellTracing.cpp:7677+`, `SourceTopologyRegions::make` enforces unique source face topology and one region binding per face. At `:8010–8065`, a **published HardRail** edge must have exactly two source triangle memberships. At `:8130–8220`, the checked factory requires exactly two hard spokes at the junction, every face in the vertex-star to have exactly two *other* star-face neighbors sharing a source spoke, and its two nonrail sector chains to be disjoint while exhaustively covering the whole star. Each step must join incident source faces along a spoke. At `:18530+`, the production A4 author explicitly rejects spokes without exactly two source triangle incidences.

A fixed junction vertex's star can be modeled as an undirected simple graph G: vertices are adjacent source vertices; each triangle incident to the junction contributes one edge of G. The factory's per-face two-neighbor rule says the **line graph** L(G) has degree two at every vertex. Its complete connected sector paths plus two connected terminal-carrier faces imply L(G) is connected. Therefore G is either a cycle (all spokes incident to two triangles) or the three-leaf star K1,3 (one overfull spoke, three boundary spokes). K1,3 cannot supply even one, much less two distinct, **exactly-two-face** published terminal HardRail spokes. Hence the presently checked certificate constraints already imply no overfull nonrail spoke in a valid connected junction under these assumptions. This is a source-level combinatorial inference, **not a proof of all possible source-authority hazards** and not a C++ runtime result.

Independent bounded enumeration of connected simple G with up to six adjacent source vertices found 257 graphs satisfying the 2-regular line-graph rule: cycles and K1,3 only. None contained both a spoke with incidence >2 and two distinct spokes with incidence 2. This enumeration supplements, but does not replace, the structural argument.

**Conclusion:** No concrete bypass or failing factory test was established. Do **not** add another speculative nonrail two-face guard merely because the current code lacks a literal nonrail incidence-counter conditional. Reopen only on a source-backed counterexample or an independent architecture requirement. This does **not** resolve the public factory's A3 **φ-value** attestation trust boundary, because source incidence is not a trusted transport value.

## Remaining authority

Independent A/B/C review still pending: (A) A4-owned atlas attestation versus source-attested factory nonrail φ, (B) compile-only CB closure versus later real organic witness/47-regression evidence, (C) four compiled supplemental tests outside immutable 497 selected identities. Frozen `497=30+12+449+6`, all R2 historical 53 REDs, 39 first-locus set, 47 CP2 accepted→RED, stable ledger 64/17/47 debt 1: no new runtime evidence. No Directional binary, CTest, GoogleTest, benchmark or local compile was executed. Full downloadable continuation and detailed audit in ChatGPT Library `/Directional/Evidence/Directional__M6-CP3-CB1-ENTRY-R3__continuation-20261009T2233Z.md` SHA256 `d1476aedde8b8cb827f7ed1d014606ee10221ad5eb1e4b64bb63f04d04957e7e`.
