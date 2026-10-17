# Review decision — RA-83: R10A witness census

**Turn:** `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV` · **Verdict:** R10A ACCEPTED as facts, with one correction and one sharpened finding · **Date:** 2026-10-17
**Census:** `Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md`, source `9c4da0f1d` (identical to `d938ecb57` and HEAD in `src`, `include`, `tests`).

## Gates (full clone, RA-82.3)

`review_check.py boundary` and `ledgers --base 8b7299b43`: ALL PASS. `document_drift_audit.py --base cbdf48570`:
0 errors, 1 warning (handoff, the turn's mandated in-place update). No code, test, fixture, workflow or
selector byte changed. `authority` not applicable: no new package.

## RA-83.1 — accepted facts

Re-read independently against source:
- All six shape outcomes in table 1, in both checkers. RA-82.4 is **confirmed**: the verifier rejects an
  R endpoint at route level (`S:8597-8614`) and per endpoint (`S:8699-8721`).
- The verifier seeds star incidence only for published contact endpoints (`S:8495-8519`). For an R vertex,
  `unique_terminal_star_path` therefore returns `Invalid` at `S:8176-8178` before any path search.
- `unique_terminal_star_path` skips every hard spoke (`S:8182`). At a manifold vertex where two rail edges
  meet it can return `Unique` per side, but only conditionally. The census's "conditional" is correct.
- The junction certificate is built after endpoint admission (`S:20040-20245`) and cannot witness an
  endpoint (RA-68.3).
- The cited controls exist: `SurfaceCellsPhase10Tests.cpp:7145-7187` (T–I produced, forged terminal rejected).

## RA-83.2 — correction: the I–I asymmetry is consumer-admits, publication-rejects

The census says the consumer's I–I outcome "may still" be rejected by "downstream route checks,
S:20000-20045". Those lines are the endpoint diagnostic and the start of the junction loop.

The consumer has **no route-level terminal requirement** anywhere up to the certificate push
(`S:20243-20245`). An I–I front that passes the endpoint and junction checks is pushed there.
`publish_phase_front_result` (`S:12832`) then calls `SurfacePhaseFrontProduct::make` (`S:12858`), and the
verifier rejects it at `S:8603-8614`.

So the two checkers disagree in sequence: the consumer certifies a front that publication then refuses.

## RA-83.3 — sharpened: the ordered open-rail chain reaches the consumer but not the verifier

The census marks named-rail membership of R "absent at the checker boundary". That is half right.

- **The witness exists.** `SurfaceCellRail::sourceVertices` / `sourceEdges` (`H:104-115`) hold each rail's
  ordered source chain. `build_authoritative_surface_cell_rails` builds them (`P:9258`, called at
  `P:12336`) before tracing, independently of any A4 certificate.
- **The consumer has it, unused.** The chain is passed whole to tracing as
  `SurfaceCellTracingOptions::authoritativeRails` (`H:2246`, set at `P:12476`). The consumer copies it into
  `authoritativeOptions` (`S:19059`) and republishes it on the network (`S:19023`). The endpoint checker
  never reads it.
- **The verifier does not have it.** `SurfacePhaseFrontProduct::make` receives only the projection from
  `hard_rail_source_provenance_from_rails` (`S:12858-12869`). That projection publishes the whole chain for
  closed rails (`P:9741-9754`) but only the first and last vertex for open rails (`P:9756-9765`). The
  verifier's star seeding (`S:8495-8519`) and both of its terminal checks key on it.

So the absence is a **plumbing loss at the verifier boundary**, a relocation question under RA-72.5. No new
producer is needed. This is a fact for R10B to weigh, not a chosen rule.

## RA-83.4 — constraints frozen for R10B

R10B is the documents-only rule turn:

1. **One rule, both layers.** It must state the rule for the per-endpoint branch in both checkers and for
   the verifier's route-level terminal requirement.
2. **No disagreement.** After the rule, the consumer and the verifier must give the same outcome for each
   of the six shapes. That includes I–I (RA-83.2).
3. **Independent witnesses.** Every clause cites an R10A table-2 row or a `file:line`. A witness that the A4
   producer authors does not count (RA-65.5).
   - If the rule uses the open-rail chain, it states how that chain reaches both checkers (RA-83.3).
   - It also classifies that chain against the RA-78.4 / gate C boundary.
4. **No regression.** T–T and T–I outcomes stay unchanged, and the forged-terminal tamper still rejects.

## Disposition

`RP-01` open, owned by the endpoint contract (per endpoint and route level). `RP-02` unreached; Gate C
suspended. Stable 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497 unchanged; no promotion.

**Consolidation:** the RA-81 and RA-82 review records are folded into `M6_Consolidated_Record.md`. Their
substance is frozen as RA-81 and RA-82 and is restated by R10A.

**Next:** `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE`, documents only.
