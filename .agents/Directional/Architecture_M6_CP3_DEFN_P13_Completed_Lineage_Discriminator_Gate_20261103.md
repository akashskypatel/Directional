# P13-j — completed-boundary ownership discriminator (same Review, 2026-11-03)

> **Resolved (2026-11-03) by [RA-200](Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md) §1 item 1:** the measurement below was taken on the scratch build. Branch (A) holds: the certificates on both sides are identical at 5351/5355/5356/5357/5359, and only the descriptor key differs. The fix is Amendment 32, exact CB79 → TB73.

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`. This is a source-and-retained-evidence decision gate, **not** a completed Review, corrective patch, runtime test, or Code + Build authorization.

## Immutable authority and independent recheck

- Semantic base: CB78 `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; compiled eight-target GMP/GMPXX package `13181887585`. TB72A 883/883 is verified **unpromoted**; accepted CP2 491/491, stable 66 events / 17 categories / 49 recurrences, debt 1, 81 deferred and membership 964 unchanged.
- Exact source snapshot: `5bf12419f1cb185aef2e297b3ad17b2e470a916f`, run `41645502073`, artifact `13233879616`, source archive SHA-256 `59cdf6240fb20b09e329e8171343535af38418a948693069acdbdba3b79503fd`. Re-ran `sha256sum -c`: **6,128/6,128 PASS**, zero mismatches. Authenticated GitHub comparison from the snapshot to this attempt's entry head lists only three Review documents, removed temporary snapshot marker, and `STATUS`; no semantic C++/test/fixture/workflow/selector changes.
- Re-read independent ring report `p13j_ring_identity_probe.json` SHA-256 `4bd03c5bb2adf69368a9f13c77501e3872527a71e82083091ccbed1b8bf64907` and source endpoint report `vase_source_endpoint_audit.json` SHA-256 `86da0aec57a7bf0ef37f47543973061c3b3cbc3a7084aa8d5bd775bdfaec7bd5`. These are prior scratch-derived and independently parsed read-only reports, **not new C++ measurements**.

## What is proven and what is missing

The prepared node 5355 has a valid four-cell reciprocal ring (cells 26569, 3, 0, 26570). The descriptor-boundary key pairs in the retained report are:

| Neighbor node | Reciprocal cells | Descriptor keys | Evidence |
|---|---|---|---|
| 5351 | 26569 / 3 | (1,61357) = (1,61357) | Positive control |
| 5356 | 26570 / 0 | (1,50500) != (1,50501) | Split |
| 5357 | 26569 / 26570 | (1,89848) != (1,89849) | Split |
| 5359 | 3 / 0 | (1,50195) != (1,5144) | Split |

The three mismatched endpoints have common intrinsic source support in the original Vase source, and the prior **native scratch probe** established bidirectional chart transition, region 0, sheet 0, and compatible chart component for these pairs. In `PatchDescriptor.cpp:414-445,1758-1760`, `arrangement_node_identity` *filters* to the outgoing halfedge's selected source scope, so descriptor keys already diverge **before the assembler**. `PureQuadCompletion.cpp:2838+,3426-3495` then consumes the keys and fail-closes incompatible typed certificates and geometry. This identifies the **current failure-producing boundary** as descriptor-to-completion stitch identity, not a license to change the assembler's `NonManifoldStitchedVertex` rule.

The reviewed ring JSON contains **only** the two cells, outgoing source-face rows, and the compact descriptor keys per neighbor. The endpoint JSON records original source support, but **neither reports the actual completed-patch `vertexLineage.sourceCharts` vectors, selected completed `sourcePoint`, topology region/sheet vectors, source occurrences, relation paths, or cache reuse at assembly**. Static non-A5 chart-closure reasoning predicts compatibility conditionally, but does not measure these outputs. No amount of renaming, source-position-only hashing, or a new Python connectivity model substitutes for that evidence.

## Single next discriminating measurement (separate authorized scratch execution)

Using **unchanged CB78 semantic source** and its scratch-only diagnostic execution path, capture the *existing completed patch products* immediately before the original assembly lookup at `PureQuadCompletion.cpp:3426-3495`. For each side of reciprocal nodes **5351, 5356, 5357, 5359**, and for each of the four contributors at center **5355**, record:

1. Exact source cell / patch / local boundary-vertex identity and the matching prepared node/twin endpoint; full resolved `PureQuadStitchIdentity` (both numeric and typed members), completed `vertexLineage.stitchIdentity` and `authoritativeIdentity`.
2. Actual completed `vertexProvenance` / lineage source point and `sourceSupport`, full sorted `sourceTopologyRegions`, `sourceIsolationSheets`, **literal** `sourceCharts` (typed chart and canonical face), plus source occurrences and selected relation-path certificates.
3. Cache creation/reuse result for that completed patch; provenance rebind candidate faces; the pairwise and cumulative typed-authority intersection and any common provenance rebinding face.

The report must include *both* sides and cannot summarize a chart set as `chart_component=0`. Keep the original rejection and tests untouched; no product source, tests, fixtures, selectors, or benchmark mutation in this Review. Any instrumentation, C++ run, or compile belongs only to a **separately authorized scratch diagnostic/CB/TB boundary**, with exact source and artifacts recorded; do not silently execute it under this Review.

**Decision tree:** (A) all reciprocal typed certificates and global 5355 certificate compatible, while three descriptor pairs differ: design only the exact upstream semantic owner-key producer and prove row/corner/repair/injective class invariance; (B) a required pair's *actual* completed certificates are incompatible: first adjudicate the completing producer/source-chart closure, **not** a descriptor-only key merge; (C) compatible identities but reused cache product has changed owner: independently prove same-key/different-full-membership through the real reuse validator while preserving unchanged-owner reuse; (D) the corrected key reaches an original face/vertex manifold or source provenance rejection: retain that rejection and re-evaluate owner eligibility. No branch licenses geometric welding or synthetic green.

## Review boundary and continuation

`python3 .agents/Directional/tools/review_check.py boundary` on the verified snapshot **exited 1**: it lacks Git history and cannot authenticate durable rewrite baseline ancestry, marking selectors as untracked. This is not PASS. Prior authenticated GitHub compare establishes byte-level semantic unchanged paths but cannot replace the mandated command on a history-bearing checkout.

The exact owner-key serialization, disjoint point-contact and hard-rail/sheet/fan sector admissibility, repair-generated node ownership, and completion-cache full-member reuse certificate remain unaccepted. The Review §5 document closeout and any Code + Build successor must wait for a genuinely discriminating measurement and its adjudication. Do not replay CB78/TB72A or promote CP3/selector497.

**Current disposition:** same canonical Review unresolved; the missing completed-lineage measurement is a **review/design conditional gate**, not a connector authorization or safety-check failure. No successor starts in this turn.
