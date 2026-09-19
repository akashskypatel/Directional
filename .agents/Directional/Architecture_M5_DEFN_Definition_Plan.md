# M5-DEFN Definition Plan

**Turn:** `M5-DEFN`
**Milestone:** M5 — certificate-carrying chart and quotient relations
**Mode:** planning / runtime-free
**Predecessor:** `M4-CP4-TB3-REV` / M4 CLOSED + ACCEPTED
**Accepted entering runtime authority:** package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**

## 1. Goal

Freeze the semantic contract that lets M5 replace verifier-side reachability reconstruction, boolean witness compression, front-edge equality and relation-vector coupling with canonical relation IDs plus explicit selected path certificates. Do not implement or execute anything in `M5-DEFN`.

## 2. Required definition outputs

1. **Canonical relation identity.** Define the typed relation-ID domain, producer ownership, creation point, equality/ordering rules, and checked conversions. Container position, output row, front-edge index, hash iteration order and execution handle may not be semantic identity.
2. **Explicit selected path certificate.** Define the complete ordered certificate carried for each participating occurrence/chart selection, including endpoints, relation sequence, orientation/transform composition, and the independent facts a validator must recompute. A boolean `witnessed` flag or reachable-set membership is insufficient.
3. **Producer/consumer cutover.** Freeze the single writer and every bounded consumer that must stop reconstructing reachability or coupling semantics to relation-vector ordering.
4. **Typed failure matrix.** Freeze independent negative witnesses and error ownership for missing, duplicate, conflicting, nonreciprocal, and representation-renumbered relations. State the exact fail-closed locus and prohibit silent repair/reordering.
5. **Unused-valid-relation invariance.** Define the invariant proving an unused but valid relation cannot alter the selected certificate.
6. **Direct-production witnesses.** For every witness named by the plan, state the highest product stage already proven to be reached. No fixture-file existence or direct/synthetic construction may substitute for required production reachability.
7. **Debt ownership.** Preserve all four M5 produced-witness debts unchanged:
   - `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`: M5-CP1 mechanism + M5-CP3 direct-production re-proof, preserving the original `>=2` relation/edge discriminator;
   - `MissingPeriodicRelationOwnerIsRejected`: M5-CP2 mechanism + M5-CP3 direct-production re-proof;
   - `FullPeriodicRotationAndTranslationMaterialize`: M5-CP3 direct nonzero-Z4 production;
   - `TamperedFullPeriodicTransformIsRejected`: M5-CP3 direct nonzero-Z4 production/tamper.
8. **Checkpoint split.** Freeze CP1 as canonical IDs/path certificates, CP2 as typed relation failures, and CP3 as direct-production torus lineage/quotient exit evidence plus unused-valid-relation invariance.

## 3. Assumptions to challenge

- Do not assume current relation-vector order is stable semantic authority.
- Do not assume verifier reachability reconstruction is equivalent to validating a producer-carried selected path.
- Do not assume same-sheet/container equality identifies one relation without a typed canonical ID.
- Do not assume a zero-Z4 or direct-plan witness can discharge the M5 nonzero-periodic direct-production debts.
- Do not broaden M5 into A5 occurrence-complex ownership; the closed candidate-bearing-complex debt remains M6-owned.

## 4. Acceptance criteria for `M5-DEFN`

`M5-DEFN` is complete only when one frozen definition record states every identity/domain/owner above, maps each negative case to a typed failure and independent falsifier, binds every named witness to proven production stage reachability, preserves the four M5 debt discriminators, and yields one surgical `M5-CP1` Code + Build plan with observable compile and future artifact-only validation criteria.

No source/test/benchmark/build/selector mutation, compilation, or Directional runtime is authorized in this definition turn.
