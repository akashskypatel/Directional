# M6-DEFN Occurrence / Embedding / Independent Verifier Definition Plan

**Turn:** `M6-DEFN`
**Boundary:** runtime-free definition only
**Predecessor:** the Review that finally accepts the `G4-B004` M5-half reading and closes M5. That is currently pending `M5-DEFN-R2`, because `M5-DEFN-R1-REV` did not accept DEFN-R1's disposition A.

**DEFERRED — NOT THE CURRENT NEXT TURN.** M5 closure is held. `M5-DEFN-R1-REV` did not accept DEFN-R1's "multi-isolation-sheet" reading of the `G4-B004` M5 half, on chronology and redundancy grounds. The exact next turn is `M5-DEFN-R2` (`Architecture_M5_DEFN_R2_G4_B004_Reading_Plan.md`). This plan becomes live only after that reading is frozen and Review-accepted. Item 7 must then be re-read against it. *(DEFN-R1 had rewritten this banner and item 7 to assume its disposition A. The reviewing agent reverted them to neutral.)*

## Goal

Freeze the M6 vertical contract before any occurrence, quotient, embedding, or verifier implementation changes. This turn changes definitions/plans only: no product source, test, fixture, selector, benchmark, build source, compile, or generated runtime.

## Required definition outputs

1. Freeze **four complete immutable stage products** corresponding to occurrence creation, quotient construction, source-attached geometry embedding, and independent verification. State each product's sole producer, typed inputs, immutable outputs, certificate payload, and failure ownership.
2. Freeze the verifier recompute boundary: validation may independently recompute elementary source incidence/output topology from immutable inputs and certificates, but may **never repair, infer, canonicalize, substitute, or complete malformed producer state**.
3. Freeze exact identity/equality rules for `SurfaceOccurrenceComplex` and quotient classes so equal lattice coordinates or equal 3D positions do not imply equality without a certified relation.
4. Freeze ownership and proof route for the remaining M6 closed-complex `G4-B002` debt: M6-CP1 mechanism/stage separation and M6-CP3 direct-production re-proof must remain distinct.
5. Adjudicate `G4-B001 / PR8-R034 / G4-R007` at the earliest M6 boundary: either freeze it as an M6-owned product-contract defect with a specific checkpoint owner, or prove from current authority that its precondition belongs later. Do not implement a fix in DEFN.
6. Resolve the two dormant CB14 identities from `M5-CP3-TB1-R16-REV-OBS-01` with **no retroactive M5 credit**: for each identity, freeze either deletion as superseded/redundant test authority or a concrete later M6 gating owner. Name the first implementation checkpoint/turn family that may act.
7. **`G4-B004` M6 half.** Under M4-DEFN §11.2, M6 must prove that the M5-produced positive multi-isolation authority is materialized/consumed exactly once and independently verified on the **representative occurrence/embedding/verifier path**. It must do so under whatever M5-half reading is finally frozen and Review-accepted (pending `M5-DEFN-R2`). Do not assume a reading, and do not assume M5 produced the authority until that Review accepts it.

## Required falsifiers

- A verifier contract that can reconstruct a missing endpoint/route/owner, choose an equivalent relation, weld by coordinates/position, or mutate producer state **falsifies** the definition.
- A stage product whose semantic identity depends on vector position, emission order, representative sheet, world-space coincidence, or post-hoc repair **falsifies** the definition.
- A closed-complex debt plan that credits mechanism-only evidence as direct production **falsifies** closure ownership.
- Any treatment of the two dormant CB14 identities as historical M5 evidence **falsifies** the no-credit disposition.
- Any unresolved ownership conflict between occurrence creation, quotient construction, embedding, and verification **halts** M6 implementation.
- A `G4-B004` M6 contract that assumes an M5-half reading or M5 production not yet Review-accepted, that credits focused M5 evidence as representative M6 evidence, or that credits M6 representative work back to M5, **falsifies** the definition.

## Stop rules

Stop without authorizing Code + Build if any of the following remains ambiguous: the four product schemas; relation-consumption ownership; verifier recompute vs repair boundary; `G4-B001` owner; the M6 closed-complex debt proof route; or deletion/gating ownership for either dormant CB14 identity. Do not select a successor Code + Build turn until those items are frozen and mutually consistent with `DESIGN.md` §§8-9/14 and `ROADMAP.md` M6.

## Completion evidence

A complete Definition Record must enumerate the four products, typed failures/certificates, verifier permissions/prohibitions, exact M6 debt ownership, `G4-B001` disposition, dormant-test disposition, and exactly one bounded successor with its own falsifiers. `REVIEW_TURN_POLICY.md` governs DEFN turns. Its §5 closeout block, including the `review_check.py boundary` row, is mandatory. No generated Directional runtime is permitted. *(Corrected by the reviewing agent. The earlier wording said `review_check.py` was not required for a definition turn, which contradicted policy.)*
