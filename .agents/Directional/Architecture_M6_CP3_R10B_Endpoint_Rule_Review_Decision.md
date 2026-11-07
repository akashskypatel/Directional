# RA-84 — R10B endpoint rule reviewed: accepted with amendments; four Code + Build units

**Turn:** `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE-REV` (Review). **Subject:** `Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md` at `000949084`. **S** = `src/geometry/SurfaceCellTracing.cpp`, **H** = `include/directional/geometry/SurfaceCellTracing.h`, **P** = `src/pipeline/RemeshPipeline.cpp`; lines at HEAD.

## Gates (full clone)

- `review_check.py authority df37ffc19` PASS (ancestor of HEAD, no code drift); `boundary` PASS; `ledgers --base 43d5fd512` PASS; `document_drift_audit.py --root . --base 43d5fd512` 0 errors, 1 routine protected-change warning (handoff).
- `git diff d938ecb57..HEAD -- src include tests` is empty: the R10B snapshot is the TB10 source.

## RA-84.1 Accepted

- Witness source (b): the ordered open-rail chain from `build_authoritative_surface_cell_rails`, carried to the factory alongside the existing terminal pair. Two-spoke inference (a) is correctly refused: without a T end nothing ties an I–R or R–R route to the named rail.
- Classification: authority plumbing at the verifier boundary (RA-72.5), not a Gate C producer-authored vertex-star certificate (RA-65.5/68.3/78.4). Gate C stays suspended.
- Per-endpoint R conjunction (§2), typed R distinct from `terminalVertex`, route anchor (§3), six-shape matrix (§4), I–I rejected by both checkers, T–T/T–I/C/I unchanged, `Missing`/`Ambiguous` never accepted.

## RA-84.2 Correction — one trust root, not an independent witness

`hardFeatureEdges` is `hard_feature_edge_keys_from_rails(authoritativeRails)` (P:12348-12350, passed at P:12485), and the terminal pair is the same rails' first/last vertex (P:9756-9765). Re-checking the chain against `hardFeatureEdges` or the terminal pair is a **consistency check between projections of one rail product** (P:12335-12336, built from mesh + feature map before A4), not independent evidence. Only the source-face/component check (as the factory does for closed chains, S:8397-8433) is independent of that product. This is sufficient: T admission already trusts the same product, so R gets T's trust root, no stronger. Tests must not claim to detect a chain forged consistently with its `hardFeatureEdges`; they may claim detection only through source faces, component, or terminal mismatch.

## RA-84.3 Correction — the factory has no shared-boundary interval

§2 lists "shared-boundary interval" among clauses both checkers derive. The factory never receives `sharedBoundaryInterval`; it is consumer-only (S:19413-19421), as for I today. On the factory side the corresponding authority is the route's contiguity on the projected chain.

## RA-84.4 Required clauses added to the R rule

1. **Exactly two hard spokes.** The hard-feature edges incident to R are exactly its two chain edges and nothing else, mirroring the junction check (S:8800-8812: `hardSpokes == 2`, no foreign hard edge).
2. **R is the outer vertex of its end step.** For endpoint 0, R lies on `steps[0]` and not on `steps[1]`; for endpoint 1, symmetrically on the last step. On a one-step route R is the step vertex not claimed by the other endpoint. Two vertex endpoints are distinct. The matched chain interval fixes the orientation.
3. **Chain validity vs. R eligibility.** Projection and factory-entry validation accept every open chain with ≥2 vertices; "≥3 vertices" applies only to R eligibility. Applying it at entry would reject every single-edge open rail.
4. **Vacuous negative replaced.** "Internal chain vertex with only one hard spoke" cannot occur: a chain-internal vertex has two chain edges by construction. Replace it with two cases: one chain edge missing from `hardFeatureEdges` is rejected at factory entry (U2), and a third hard edge at R rejects the R endpoint (U3).

## RA-84.5 Unit split and order (supersedes R10B §5 groups)

Each unit carries its own tests; R10B group E is not a separate unit. The order never creates a consumer-admits / factory-rejects state.

| Unit | Turn | Scope | Behaviour change |
|---|---|---|---|
| U1 | `M6-CP3-CB11-R10-OPEN-RAIL-ROUTE-ANCHOR` | Move the factory's open-rail route rule (S:8576-8615) into one pure helper. The factory and the consumer both call it, the consumer just before its push at S:20243. | Consumer rejects what publication already rejects (closes RA-83.2). No `Produced` result changes. |
| U2 | `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | Add an open-chain map to the projection (P:9732-9767), the options (H:2246-2248), the publish call (S:20248-20253), `publish_phase_front_result` (S:12832-12869), `make` and a product accessor (H:1916-1917, 1965-1967, 1984-2018). Each chain is validated at entry like a closed chain (S:8397-8433). Its ends equal its rail's terminal pair, and its rail ids are one-to-one with the terminal contacts. | None. No cross-rail edge-uniqueness or coverage clause. |
| U3 | `M6-CP3-CB13-R10-FACTORY-RAIL-VERTEX-ENDPOINT` | Typed R field (H:1492-1509). The helper gains an R anchor and chain-interval contiguity for routes with an R end. Factory R branch (S:8699-8765), with star incidence for R (S:8495-8519). | The factory admits R. The consumer still never emits R; this factory-only admission is safe and lasts until U4. |
| U4 | `M6-CP3-CB14-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` | The consumer emits R (S:19397-19425) and uses the extended helper. End-to-end agreement test over the six shapes. | Full agreement. |

Each `CB` compiles only and is followed by its `TB` (`M6-CP3-TB11…TB14`, same suffix). A red `TB` routes to Review (Turn_Cadence rule 4). After TB14, a Review measures every conjunct on the 21 RP-01 records (RA-80.8) before any claim about RP-01. Only U1 is authorized now. U2–U4 are frozen in this order, and each is authorized only after the previous TB has been reviewed and is green.

## RA-84.6 Observation (no action)

The factory's I branch does not check interval ordinals (consumer-only at S:19413-19421). The factory is weaker than the consumer here, which cannot break publication. Out of scope; unchanged.

## RA-84.7 Documentation

- R10B §5 group A omitted the publish call site S:20248-20253; added in U2.
- The Definition opened a second `CURRENT` section in `TODO.md`; the Review merged it into the top section.
- RA-83's record is folded into `M6_Consolidated_Record.md`. The R10A census and the R10B rule stay live for U1–U4.

**Next:** `M6-CP3-CB11-R10-OPEN-RAIL-ROUTE-ANCHOR`. Accounting unchanged: 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
