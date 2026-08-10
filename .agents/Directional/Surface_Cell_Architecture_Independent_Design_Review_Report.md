# Surface-Cell Architecture Independent Design Review

**Review type:** independent architecture review; durable findings authority  
**Reviewed implementation:** `6af23d9aeca29e63aa13c4ae49f50d1748939c49`  
**Reviewed branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Decision:** **changes required before architecture expansion**  
**Current status note:** M1a–M1d are immutable accepted; M1e ordered segment-route transport is compile/package complete and awaits immutable runtime. Current execution authority is the handoff/current retained report/current next-turn plan, not this historical review.

## Executive assessment

The implementation accumulated substantial correct domain knowledge—source-attached points, typed failure reasons, topology regions, local sheets, explicit holonomy data, seam certificates, direct cell materialization, and strong validation goals—but repeated regressions show that semantic authority has historically been represented and owned incorrectly.

Multiple partially overlapping truths for producer state, source identity, routes, chart equivalence, region scope, and output ownership allowed consumers to reconstruct or repair semantics from representation details. Focused tests then validated one reconstruction while another enumeration, relation set, topology, or representative fixture exposed a recurrence.

The normative target in `DESIGN.md` and staged migration in `REORIENTATION_PLAN.md` remain approved. Do not add broad feature growth on legacy authority representations merely because a focused fixture turns green.

## Finding register

### AR-01 — producer state has contradictory authorities

**Severity:** Critical  
**Patterns:** `RP-03`, `RP-08`

Legacy producer results represent disposition, attempted/succeeded state, diagnostics, and partial retention through overlapping fields. Convention rather than the type system prevents contradictory states.

**Correction:** M2 replaces this with a closed producer outcome and separates debug/partial state from consumable product authority.

### AR-02 — semantic domains are encoded as interchangeable integers and parallel arrays

**Severity:** Critical  
**Patterns:** `RP-01`, `RP-06`, `RP-07`

Routes historically store compact transition indices and canonical source-edge topology in parallel vectors while singular last-transition values duplicate route state.

**Correction:** strong IDs plus typed transition/route semantics with checked adapters at compatibility boundaries.

**Migration status:** M1a kernel, M1b source/provenance consumer, M1c edge transition consumer, and M1d phase-front route identity consumer are immutable accepted. M1e now compiles typed `TransitionStep` / `CanonicalRoute` / `GridAutomorphism` composition at the first real ordered transport-owning consumer and awaits immutable semantic validation.

### AR-03 — generic integer-vector identity erases domain schemas

**Severity:** High  
**Patterns:** `RP-01`, `RP-03`, `RP-05`

Generic vector-shaped identity permits unrelated domains or enumeration handles to masquerade as semantic identity.

**Correction:** domain-specific canonical keys with explicit construction from semantic members, not enumeration ordinals.

### AR-04 — duplicate chart and authority records invite divergence

**Severity:** High  
**Patterns:** `RP-06`, `RP-09`

Parallel chart/authority records and copied mutable phase-front/network tables permit producer, pipeline and validator to observe different copies.

**Correction:** one chart type and immutable authority snapshots/plans referenced by typed IDs. Production `FieldChartId` migration remains later M1; single-writer snapshots are M2/M4 work.

### AR-05 — canonical equality includes representation/execution details

**Severity:** High  
**Patterns:** `RP-05`

Emission positions, patch/backend handles, hashes or traversal orientation have historically entered equality/order relations.

**Correction:** semantic equality first; representation handles separate; hashes are fingerprints only; canonical route storage must not change behaviorally observed direction.

**Migration status:** M1d route identity is accepted. M1e explicitly uses `CanonicalRoute::oriented_steps()` before transport consumption and awaits runtime proof.

### AR-06 — validator reconstructs producer semantics and compresses away proof

**Severity:** Critical  
**Patterns:** `RP-01`, `RP-05`, `RP-09`

The validator historically rebuilds relation/topology meaning rather than verifying producer-owned certificates, creating a second topology producer.

**Correction:** producer-owned canonical relation registry and exact certificates; validator verifies elementary incidence/certificates only. M4/M5 own this work.

### AR-07 — independently produced rail breakpoints are paired post hoc

**Severity:** Critical  
**Patterns:** `RP-06`, `RP-09`

Independent local discretization cannot guarantee equal hard-rail breakpoint schedules.

**Correction:** global conformity planning before regional production. M3 owns exact shared rail schedules. Historical exact-torus `InvalidHardRailPairing` remains a blocker.

### AR-08 — aggregation overwrites producer semantics

**Severity:** High  
**Patterns:** `RP-03`, `RP-06`, `RP-09`

Post-production scope normalization can mask incomplete producer authority and creates multiple writers.

**Correction:** immutable region authority passed into producers; aggregation verifies/remaps representation handles only. M2/M3.

### AR-09 — source support identity has multiple tolerance-dependent implementations

**Severity:** High  
**Patterns:** `RP-01`, `RP-05`, `RP-06`

Tolerance/quantization choices have historically leaked into topology identity.

**Correction:** one sanitized tagged exact simplex-support kernel. Tolerance decides sanitization success only; identity after sanitization is exact. M5.

### AR-10 — monolithic files collapse stage ownership

**Severity:** Moderate

Large tracing/arrangement/pipeline files make semantic state accessible outside owning stages and increase change coupling.

**Correction:** decompose by responsibility incrementally as typed stage APIs are adopted; do not perform a one-shot file split.

### AR-11 — normative architecture and mutable status must remain separate

**Severity:** High for process architecture  
**Patterns:** `RP-02`, `RP-03`

`DESIGN.md` is normative only. TODO/milestone/handoff own live status; the current retained report owns current machine evidence; the tracker/audit own history. Superseded per-turn reports are intentionally cleaned.

### AR-12 — focused test authority can outpace representative production proof

**Severity:** High  
**Patterns:** `RP-02`

Focused counterfactuals can construct relation objects directly while representative producers emit a different state shape.

**Correction:** every stage contract needs positive, tamper/negative, metamorphic, and representative production evidence where applicable. Focused success cannot close a product gate.

## Root-cause concentration

| Root failure | Findings | Repeated patterns |
|---|---|---|
| no single semantic owner | AR-04, AR-08 | RP-06, RP-09 |
| type-erased domains | AR-02, AR-03, AR-09 | RP-01, RP-03 |
| representation-dependent identity | AR-05 | RP-05, RP-07 |
| proof reconstructed downstream | AR-06 | RP-01, RP-09 |
| local decisions precede global constraints | AR-07 | RP-06, RP-09 |
| lossy lifecycle state | AR-01 | RP-03, RP-08 |
| incomplete evidence boundary | AR-11, AR-12 | RP-02, RP-03 |

## Reference architecture comparison

- **Directional Fields / Directional:** explicit connection, matching, period jump, singularity and holonomy domains → typed field transport/cycle authority.
- **MIQ:** seamless grid automorphism across cuts → typed `Z4` rotation / lattice translation semantics; do not adopt its global mixed-integer integration as a requirement for this backend.
- **QEx/libQEx:** sanitized preprocessing, exact predicates, extraction/connectivity separation → exactness boundary and explicit occurrence/relations.
- **QuadWild:** global side tessellation/parity before independent patch quadrangulation → shared conformity plan before regional production.
- **Instant Meshes:** scalable local orientation/position fields → useful geometric proposal/quality machinery, not topology identity authority.
- **FlowRep:** global strand/cycle context → global rail/cycle planning evidence, not perceptual score as validity authority.
- **AutoRemesher reference:** useful staging comparison; do not adopt hole repair/largest-island/mixed-polygon recovery in strict direct mode.

## Corrective decision

The normative `DESIGN.md` remains approved as target architecture. The behavioral implementation remains migration input/comparison authority, not an approved architecture for unrestricted feature growth.

Continue the bounded sequence:

1. finish M1e immutable semantic validation;
2. select later M1 consumers only at genuine semantic owners;
3. then M2 closed outcomes/single-writer snapshots;
4. M3 global conformity;
5. M4 certificate-carrying relations;
6. M5 occurrence/embedding/independent verification;
7. M6 retire legacy representations and decompose ownership modules.

Any required-green regression blocks advancement. Product G4 remains separate: M1 migration does not itself resolve `PR8-R034 / G4-R007`, direct-torus `LocalSheetMismatch`, historical `InvalidHardRailPairing`, nonzero periodic capability, or positive multi-isolation witnesses.

## Evidence/cleanup authority

This review is durable and excluded from routine cleanup. Historical per-turn evidence cited by older commits may no longer exist at the current branch head by design. The mandatory cleanup policy in `Future_Chat_Session_Handoff.md` requires each Test + Benchmark turn to retain only current evidence plus one next plan after folding necessary facts into durable documents and immutable artifact history.
