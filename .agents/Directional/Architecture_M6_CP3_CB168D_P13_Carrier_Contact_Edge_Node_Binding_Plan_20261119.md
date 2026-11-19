# EC2b — carrier-contact edge-node binding (frozen after TB144 independent Review)

## Situation and scope

**Next only:** `M6-CP3-CB168D-P13-CARRIER-CONTACT-EDGE-NODE-BINDING`. Code + Build, compile-only. Implement RA-265 S3's inert consumer connection; do not start EC3 or change the carrier-contact producer. The reference source is CB168C `e0f085eb65ed186bf836305f2896c69c6c90c519`, package `14498438448`; preserve unrelated production, tests and required gates.

## Required dataflow and exact authority

1. `FieldAlignedTerminalContact::carrierLocus` is optional and no real producer sets it. `carrier_contact_struck_position` in `EmbeddedGraphTopology.cpp` is already pure and requires struck trace ID, segment range, exact incoming carrier and equal interior parameter. Reuse it; do not duplicate its logic, infer position geometrically or accept a vertex-end point.
2. In `build_cut_node_bindings` (`EmbeddedGraphTopology.cpp`), enumerate only terminal records with a valid locus and an actual struck trace. Demand that its `(source edge, exact parameter)` is in selected cut edges, matches a real crossing and corresponds to the helper-returned struck position. Bind terminating contact to the **same** edge-crossing graph node, with exact edge, parameter, terminating trace, and interior position. Do not allocate a second node for the same cut point, change unrelated crossing-node identity or allow a cross-sheet/topology merge. Reject inconsistent published authority with the existing typed error; do not silently omit a malformed nonempty locus.
3. Ensure `face_contact_nodes` and `is_face_contact_event` exclude these specifically edge-keyed terminal contact events. Preserve current face-contact treatment of true interior contacts and existing barrier terminations. The trace's arc cut position must be the helper result; no private downstream repair.
4. Strictly no `first_field_aligned_carrier_contact` production switch and no EC3 transverse entry/entry classification. Do not alter the frozen N1–N7 normalization, gate manifests, CP2 accepted prefix, output fallback, source-grid recovery, hard rails or validator.

## Independent falsifiers / required future tests

- One **non-vacuous injected positive** constructs an exact interior locus with struck trace segment entering on that carrier. The terminal and struck crossing must share exactly one node; the helper's returned segment index must govern the interior cut position. Rotate/reorder source faces or candidate order without changing source identity; resulting exact binding must be invariant.
- Negatives, each independently targeted: no locus (no new edge contact), wrong struck trace, wrong edge, wrong exact parameter, segment out of bounds, parameter zero or one, unselected cut edge, conflicting node ownership, non-face edge event fed to face contact path. A negative must fail the specific owning guard, not merely earlier input validation.
- Frozen direct run: **no current producer sets a locus**, so prior 964 gate/census rows should remain identical under the TB144 normalization without new unexpected PASS/RED; 491/491 CP2 stays accepted. New focused case is added only in a later authorized gate turn; no source changes in this Review.
- Stop rather than weaken an oracle if a valid produced edge contact cannot be constructed, if a terminal and crossing demand different exact nodes, or if `build_cut_node_bindings` cannot express the required association without a normative owner decision. No fabricated producer output, no positional weld and no arbitrary alternate ownership.

## Compile-only boundary

Implement smallest shared-source change, add only directly necessary independent tests in the Code + Build turn, compile through mandatory reusable workflow with eight GMP/GMPXX targets, `runtimeExecution=false`. Do not execute binaries in Code + Build. After independent test/benchmark turn, decide whether EC3 can start; no automatic EC3 progression from compilation.
