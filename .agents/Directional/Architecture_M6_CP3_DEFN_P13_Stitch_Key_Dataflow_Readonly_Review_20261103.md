# P13-j — exact stitch-key producer-to-assembler read-only check (2026-11-03)

**Turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`, still IN_PROGRESS. This is a same-turn **Review/Definition evidence note**, not a corrective source patch, accepted design, runtime verdict, or Code + Build authorization.

## Immutable input and verification

- Working-branch snapshot run [41645502073](https://github.com/akashskypatel/Directional/actions/runs/41645502073), source `5bf12419f1cb185aef2e297b3ad17b2e470a916f`, source artifact `13233879616`. Internal archive hash verified; **6,128/6,128** file hashes passed, zero errors, `runtimeExecution=false`.
- GitHub compare `afd72107d3213a396ed7f35b53f67dceeea7e7ca...5bf12419f1cb185aef2e297b3ad17b2e470a916f`: 176 commits ahead, zero behind; changed paths are review/documentation, `STATUS`, dispatcher/control, or snapshot markers, **no C++/test/build/workflow/selector semantic changes**. The immutable CB78 source remains the semantic baseline.
- Independently checked exact local source SHA-256: `PatchDescriptor.cpp=108e5481fe85ecafa566d4a14f089afbf00956f8e543fbbc8b0c5f176f31f491`; `PureQuadCompletion.cpp=9eb46a71b4f8af85b7b9ccda703606fe39dd4d7eb61a67d10e00ff5998f45476`.
- Read-only audit passed 16 distinct source/witness assert statements (one is executed for three separate broken neighbors), including the four recorded neighbor keys and all eight subsets of the three fractured seam matches. Audit script SHA-256 `d1bd82e34c43ae85759992cf40c9e6d81095d5712a423805f2e234e2f67903fe`; JSON SHA-256 `74442212f83fc3a198db518f4acdf65e378c7ccbaa22b67792bcf20bf1116112`. **Not Directional C++ tests**. The earlier count of 14 was incorrect and is corrected here.

## Precisely located responsibility

1. `PatchDescriptor.cpp:414-445` builds `arrangement_node_identity` only from occurrences exactly matching `source_scope(outgoingHalfedge)`; `derive_patch_descriptor:1758-1760` publishes this as each completed-patch boundary-node identity. Thus two reciprocal patch corners can inherit different exact chart-scoped keys at the **descriptor producer**, even when they refer to the same prepared node and intrinsic source support. Source-support geometry alone does not certify admissible equivalence.
2. `compact_identity_group:833-869` replaces the numeric `values` vector with namespace/rank but retains the typed vectors. **Matching ranks alone do not repair mismatching typed identities.**
3. `PureQuadCompletion.cpp:341-373` initializes the completed mesh and boundary vertex lineage from descriptor identities. `resolved_stitch_identity:2838+` reads the mesh boundary identity as its resolved key and rejects mismatch against the lineage key. A descriptor-key fix cannot be simulated by rewriting only a cached mesh boundary vector.
4. `intersect_typed_authority_certificates:2744+` independently requires matching exact source support and nonempty region, sheet, and literal source-chart intersections. The original `IncompatibleTypedStitchAuthority`, position, and `NonManifoldStitchedVertex` fail-closed checks must not be weakened.
5. The inherited real Vase witness has one four-cell prepared ring at 5355. At neighboring 5351 the two compact keys match; at 5356, 5357, 5359 they differ. The read-only graph independently gives three disconnected sectors. **Equating any two of the three mismatched interfaces produces one connected graph**; therefore a green aggregate vertex-link result would be vacuous as a complete stitching oracle.

## Same-turn adjudication: what is and is not proven

**Established:** key fragmentation is already present at the descriptor-to-completion boundary, before the assembler's final nonmanifold validation. Repair is to be investigated at source-owned completed-boundary equivalence, not by positional welding or suppressing the assembly rejection. The source snapshot contains no semantic drift from the CB78 base.

**Not established:** injective row/corner/permutation-stable class identity for original and repair-split nodes; admissible reciprocal hard-rail/cut, region, sheet, and fan policy; exact full cache owner-member equality after structural rebuilding; *actual completed* Vase `vertexLineage.sourceCharts` vectors and selected source-provenance pairings; live descriptor-through-assembler positive/negative execution; controlled Vase performance.

The source-level fresh-completion chart closure predicts overlap when provenance stays within the certified support/fan class, but no completed-lineage vector was measured. **V2 and reciprocal-incidence owner-key candidates remain UNACCEPTED.** No CB/TB or separate BunnyRandom P13-e successor is authorized. The future distinct positive must verify **all four** reciprocal corner pairs individually, and negatives must preserve disconnected same-position/near-coincident nodes, hard-rail/fan/sheet separation, typed certificate intersection and exact cache invalidation where owners change. Do not infer these from only a model or connectivity counter.

## Boundary-check and procedural limits

`python3 .agents/Directional/tools/review_check.py boundary` on the verified source archive **exited 1**: authentic Git rewrite ancestry could not be established because the snapshot has no `.git`; the checker labels selector files `untracked`. This is **not** an accepted boundary PASS. Authenticated GitHub compare establishes ancestry and unchanged semantic paths, but does not replace the full checker.

During session bootstrap, repository document reads preceded the conservation-policy read-mode gate; this was a procedural miss. Source inspection subsequently switched to the mandatory verified snapshot rather than continuing piecemeal connector reads. The 20-minute response closeout and exact current canonical turn remain binding.

No product/source/test/fixture/selector/benchmark/build was changed, no Directional runtime was executed, and accepted CP2 **491/491**, stable **66/17/49**, debt **1**, unpromoted TB72A **883/883** / selector497 are unchanged. This Review remains unfinished; mandatory Review §5 closeout and authenticated boundary proof are pending.

## Existing C++ regression coverage audit (same turn)

Read-only audit of six existing C++ test bodies and CB78 descriptor/cache/assembler source: script SHA-256 `6c45d772c84af2910f45e105a7ad2abb3bd92f2f9d55919d9a9e0c88962ce43a`; JSON SHA-256 `2b0c5b919b9a12bf31fba70904b8bb5b22129bc6cc653852facd3200f258d3a1`. **These are static checks, not executed C++ test results.**

- `PatchDescriptorMilestoneETests.cpp:1404+` **already checks boundaryNodeIdentities equality** under a source-face-row permutation; it tests one patch, not *two reciprocal patches* selecting different outgoing source-chart scopes at the same prepared node.
- `PatchDescriptorMilestoneETests.cpp:1481+` and `:1605+` explicitly require nonzero reused patch completions **after structural repair**. Blanket disabling cross-repair cache reuse would violate these existing positives; preserve valid unchanged-owner reuse while rejecting a same-dependency changed-owner product.
- `PureQuadCompletionPhase18Tests.cpp:2003+,2429+,2474+` verify successful compatible typed stitch and incompatible-sheet/support rejection. They do not prove the descriptor generates matching keys across Vase's three fractured reciprocal interfaces.
- `PatchDescriptor.cpp:2205+` does not include exact `boundaryNodeIdentities` member equivalence in cache dependency fields. A hypothetical same-dependency changed-owner reuse still needs a real negative; this risk is **not** the proven cause of the initial Vase conflict.

**Non-vacuous future gate (not authorized yet):** separately assert matching descriptor/completed-lineage/assembler keys at Vase 5351,5356,5357,5359; retain disconnected same-support/no-twin, hard-rail, fan/sheet, near-coincident, row/corner/patch-order, and repair-generated twin-reversal negatives; retain valid cache-reuse positive alongside changed-owner same-rank rejection and actual fail-closed manifold/typed checks. An aggregate four-cell connectedness assertion alone is insufficient. Capture *actual completed* sourceCharts/support/region/sheet/occurrence/relation-path vectors and resolved keys on both sides in an authorized scratch probe, not by inference from chart-component IDs.

No source/test/build/selector changed, no Directional binary executed; owner-class injectivity, typed sector policy, cache proof and Review closeout remain open. No Code + Build successor is frozen.
