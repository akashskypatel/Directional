# P13 lens same-rail returns — protected endpoint-degree veto review

**Canonical turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. **2026-11-02; interim independent Review/Definition evidence, not a finished turn or an implementation authorization.** A source-level deletion veto is proved; deletion correctness and needle ownership are not.

## Authority and scope

- Exact semantic production source: CB76 `f59f92f889fc6fe22d689fd7559c024cd09c6c72`. Reused verified snapshot `898316210ab810daa10d2072db927f9ebe4b2a98` (outer ZIP SHA-256 `418579f76225ace51e940afbddcef2be12313058a971660421f1da0dfc2e7062`). All **6,092/6,092** file hashes passed; the CB76-to-current-head GitHub comparison found **zero semantic-source changes**. Source-file SHA-256: `FlowRepStrands.cpp` `d599f478a516804e166b125c2890e55ccc40fe85a82a85b363d81d618b34a5b6`; `RemeshPipeline.cpp` `fca712094c21313fddb81f40160b392dbf1ab1888e632fa4f3c00e17b764db12`.
- Raw independent prior Vase scratch stderr SHA-256 `e0a28c941bdaf4d86a1a5d0cf23216ac890f266b67d591e2a7c528a00e189530` from immutable conversation artifact `directional-p13-sliver-nine-cell-review-evidence.zip`, ZIP SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2`. That prior scratch runtime violated the Review boundary. This continuation is **offline-only**.
- Stand-alone offline source/receipt audit: `p13_protected_degree_review.py`, SHA-256 `4f91077fafd344e9976138838429eea26c49cc8289c314a481c3563c7566c56b`, emitted `p13_protected_degree_review.json`, SHA-256 `51ee46e1521ce7add0998532d66e9f1e35c1dca89f1c2684ecaa1e465a505d06`. It independently parsed raw `P13_ARC/HALFEDGE/NODE` and relevant source, verifying **5/5** original-vertex joins.

## Original-source contact proof

Each originally emitted optional support FlowRep arc has one endpoint at exactly the same **source face and one-hot barycentric vertex** as a separate **mandatory rail-0 FlowRep arc**, **before arrangement splitting**. Intrinsic endpoint identity in `FlowRepStrands.cpp:1915–1985` includes this same source-vertex topology and its source region/sheet; for arcs emitted from the same source face, both scope labels come from the same `network_source_scope`. Therefore both endpoints contribute to the **same protected endpoint key** in sparse selection. The dense degree is **at least 2**, not necessarily exactly 2.

| Lens cell | Seed trace (`4×seed+branch`) | Source-vertex node | Source face | Original support arc | Original mandatory rail arc | Hypothetical pure-deletion degree delta |
|---|---|---:|---:|---:|---:|---:|
| 26735 | 1037 (`259,1`) | 56385 | 2321 | 2644 | 130 | −1 or less |
| 26764 | 878 (`219,2`) | 47581 | 2151 | 2514 | 109 | −1 or less |
| 26781 | 20 (`5,0`) | 56412 | 2262 | 156 | 2 | −1 or less |
| 26802 | 422 (`105,2`) | 53651 | 2385 | 981 | 53 | −1 or less |
| 26812 | 612 (`153,0`) | 23821 | 2400 | 1857 | 77 | −1 or less |

All five support arcs have `proposal=-1`, `hard=0`, `rail=-1`, and `strandProvenance=-2-supportTraceId`. All five matched rail arcs have `hard=1`, `rail=0`. Original endpoints were checked within 1e-10; arrangement-split incidence alone is insufficient.

## The exact source-level veto (not an observed diagnostic reason)

1. `FlowRepStrands.cpp:610–720` constructs each anchored seed support path as an **optional** `FlowRepArc` with seed-derived `supportTraceId=4*seedIndex+branch`. The `FlowRepArc` default `initiallyActive=true` applies, unlike singular transition-ring support paths re-rooted later. Mandatory rails also enter the dense network as active constraint arcs. `build_flow_rep_selection_input` precedes `select_sparse_flow_rep_network` and `complete_flow_rep_endpoints` in `RemeshPipeline.cpp:13487–13576`.
2. `FlowRepStrands.cpp:2126–2158` counts **all initially active endpoint incidences**, including optional support arcs. Any endpoint touched by `boundaryRail`, `hardFeatureRail`, `mandatoryRail`, `singularitySupport`, or having degree≥3 is protected. The shared original source vertex of each row is therefore protected by the mandatory rail, and the required degree includes its optional support incidence.
3. `FlowRepStrands.cpp:2161–2178` demands *exact equality* between every required protected degree and the trial degree. Removing an optional support flowline that contains the listed arc **without a compensating active arc endpoint at that same intrinsic key** reduces a required protected degree. Therefore **`preserves_protected_endpoint_degrees` must return false for that deletion**. This is a necessary selector veto for these five observed source configurations, independently of any coverage/cycle or geometric decision.
4. `FlowRepStrands.cpp:2560–2628` builds the frozen degree map once before greedy transactions and rejects/rematerializes any removal when either the evidence or endpoint guard fails. Source code treats `mandatoryRail`, `hardFeatureRail`, `boundaryRail`, `singularitySupport` as mandatory flowline ownership; the seed-derived supports in this review are optional. The `constraintOnlyNetwork` fast path cannot explain the observed retained positive-proposal arcs in Vase; the ordinary transactional path is relevant.
5. This **establishes a deletion-veto mechanism**, not the observed first rejection reason: the archived scratch stdout/stderr has no per-flowline trial ledger, and another guard may also reject the same trial. In particular, the raw record does **not** prove that these five traces are redundant under valid cycle coverage, singularity or topology constraints. Blanket removal or relaxed degrees is unjustified.

**Non-vacuity:** The offline audit also evaluated the literal protected-degree equality rule on three deliberately distinct logical cases: deletion at a protected endpoint fails; deletion at a genuinely unprotected endpoint passes the *degree check*; replacing the deleted incidence at the protected endpoint passes the *degree check*. These are proof controls for the predicate, **not product tests** or evidence that replacement yields a valid geometric network.

## Correct causal boundary and outstanding falsifiers

The preceding ten-node wedge audit reported 30/30 internally consistent predecessor choices, with five lenses each supported by the same rail-return source arcs. **Upstream tracing admits** those anchored support paths; **FlowRep sparse selection structurally cannot simply delete them** because the mandatory rail's protected original vertex degree includes the optional incidence; **arrangement then faithfully embeds** their retained source network as two-sided lens cells; **patch completion correctly fails closed**. This chain narrows where a correction could be made. It does **not** prove that the original path was invalid: two-sided source-cell geometry could be an unavoidable consequence of a valid tracing contract or demand a different upstream layout.

Next evidence must establish each trace's terminal, seed, same-sheet rail interval, singularity obligation, **coverage delta**, and **cycle energy**. If proven redundant, compare admission rejection with validated replacement; never globally relax protected degrees. Demand positive required rail-return control, negative redundant support control, reversed/permuted rail case, exact source-chart/sheet scope, invariant rail ownership, coverage/cycle witnesses and unchanged accepted prefix. Review remains runtime-free; new probes need CB/TB authority or explicit exception.

**Four needle cells remain independent:** `6095,20533,20968,22350` have very thin **Euclidean** opposing sides and distinct seed proposal ownership. The rail degree veto does not explain them; intrinsic width/proposal admissibility remains outstanding. Do not merge the two owners or freeze a new Code + Build successor without that decision.

## Review closeout (interim, not a completed turn)

| Required duty | Evidence / carry |
|---|---|
| Decisive claims / non-vacuity | Five original source endpoint joins independently rederived from raw logs; protected-degree equality source verified; three logical predicate controls differentiated outcomes. |
| Accepted selector prefix | No selector edited or promoted; accepted CP2 491/491 and TB70 candidate 880/880 with membership 961 are unchanged by this review, but prefix was **not rehashed** in this continuation. |
| Stable accounting | Stable 66 events / 17 categories / 49 recurrences; debt 1 per existing durable authority, **not independently recounted here**. |
| Prior obligations | P13-i direct deletion guard narrowed; actual path validity / coverage / cycle still carried. P13-h2 needle-source ownership, P13-e and O23 separate. |
| Corrective source/test/selector edits | None; Review boundary held, no new runtime or compile. |
| ORIENTATION, CHANGELOG, tracker and successor | Still pending formal review closeout; no accepted checkpoint or selector changed. Roadmap and manifest unchanged. |
| `review_check.py boundary` | Historical run on archive-only tree exited nonzero on Git-ancestry requirements. **Not rerun** and **not claimed PASS**; proper Git-history verification still pending. |
| GitHub sync / lifecycle | Work committed directly to target remote branch. Final PR diff and direct root `STATUS` beacon to be verified/written at response closeout. Original start `2026-11-02T05:14:30Z` must be preserved. |

**Turn remains `IN_PROGRESS`; successor is the same Review turn**, not an authorized implementation. No required independent external approval or outage has been demonstrated, because the source/provenance and needle investigations still have available authorized offline work.