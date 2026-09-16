# M4-CP-COND Frozen Definitions — Pre-A0 Input Conditioning

**Authority turn:** `M4-CP-COND-DEFN`
**Status:** FROZEN / implementation not yet accepted
**Accepted predecessor:** M4-CP3 package `10307919492`, semantic source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`, selector408 **408/408**
**Checkpoint state after this definition:** `M4-CP-COND` OPEN
**Exact successor:** `M4-CP-COND-CB1`

This document freezes the Amendment-20 conditioner contract. It is architecturally before A0 even though it is developed after accepted CP3. Nothing here changes accepted A2b/A3/A4 semantics or the accepted selector408 prefix.

## 1. Stage boundary and single writer

Pipeline B has one raw-input boundary:

`RawSourceInput -> InputConditioner -> ConditionedSourceProduct -> A0 SourceAuthoritySnapshot -> ...`

`InputConditioner` is the **only** writer permitted to change source geometry or raw cross-field values. It consumes the complete raw source bundle once and returns exactly one of:

- `Produced(ConditionedSourceProduct)`; or
- `Rejected(ConditioningFailure)`.

A0 and every later stage consume only the immutable `ConditionedSourceProduct`. They may validate, index, canonicalize identities, derive exact products, or reject, but they may not perform another value-changing sanitization. No SurfaceCells production entry point may publish A0 authority directly from unconditioned raw values after the CP-COND cutover.

Legacy `BoundedMeshPreconditioner` behavior is **not** CP-COND authority. Its current double-valued thresholds/local flip machinery and lack of a certified raw-to-conditioned correspondence make it a legacy preprocessing utility only. It may remain for non-SurfaceCells compatibility while CP-COND is implemented, but it may not be cited as satisfying this checkpoint, may not become a second SurfaceCells writer, and may not be silently composed with the new conditioner.

## 2. Immutable product and semantic digest

`ConditionedSourceProduct` owns, at minimum:

1. conditioned source vertices and faces;
2. conditioned per-face raw cross-field data needed by the existing A1 construction path;
3. conditioned feature/rail metadata when such metadata is part of the raw source bundle;
4. `rawInputDigest` over canonical raw bytes/topology;
5. `conditionedSemanticDigest` over canonical conditioned bytes/topology and conditioning policy identity;
6. one immutable `ConditioningCertificate` containing the complete raw-to-conditioned correspondence and operation log;
7. a typed `ConditioningPolicyId` plus its exact integer/rational parameters.

The conditioned semantic digest is a deterministic serialization of typed integer topology, canonical binary64 bit patterns where the public API remains binary64, exact rational policy values, typed correspondence, and operation records. It is not defined by approximate equality, spatial hashing, quantized floating lookup, container order, or object address.

Re-running the conditioner on an already conditioned product under the same policy must not create a second semantic writer. Idempotence is defined in §9.

## 3. Exact raw authority

The public raw API may still arrive as binary64. Finite binary64 inputs are first **exactified bit-for-bit** into exact dyadic rationals. Existing `FieldExactRational::from_double_exact` is the model for this boundary. From that point through every semantic conditioning decision:

- equality/order is exact;
- the initial CB1 lattice is **dyadic**, represented by an integer exponent, so every conditioned coordinate/component remains exactly materializable as binary64; a later non-dyadic rational lattice requires a new definition of the public representation;
- rounding onto that dyadic lattice is an explicitly frozen deterministic rule over exact rationals: nearest with ties-to-even;
- branch permutations and transport are discrete `Z4` data;
- any certified numerical filter may only return a provably exact answer or defer to exact arithmetic.

A tolerance may be reported as historical/diagnostic evidence but cannot decide whether two values are the same source identity, whether a field is admissible, whether a merge is owned, or whether conditioning succeeded.

## 4. Certified raw-to-conditioned correspondence

The certificate is an independently checkable relation. The conditioned candidate does not authenticate itself.

### 4.1 Vertex identity and ownership

Every raw vertex has exactly one correspondence entry. Under an identity/no-merge outcome it maps one-to-one. A many-to-one merge is permitted only when:

1. the vertices become **exactly equal after the single frozen lattice transform**;
2. exact combinatorial safety checks prove the merge does not conflate distinct source sheets/components/features or create duplicate/degenerate face incidence;
3. the canonical conditioned owner is the minimum raw typed vertex ID; and
4. the certificate records the ordered complete raw-owner set and the exact operation that caused equality.

If any safety condition fails, conditioning rejects. There is no nearest-point or radius merge.

### 4.2 Face identity

For the first CP-COND implementation, raw faces map **one-to-one and order-preservingly** to conditioned faces after vertex correspondence. Conditioning does not delete, add, retriangulate, flip, split, or otherwise invent source faces. If a permitted vertex merge would collapse a face or create contradictory incidence, the input is rejected instead.

This deliberately keeps topology-changing sliver repair out of CB1. Amendment 20 permits repair **or refusal**; CP-COND initially chooses exact refusal where a safe certified repair is not yet frozen.

### 4.3 Field identity

Each raw face owns the same four-branch cross set before and after conditioning. Conditioning may apply only:

- exact component lattice quantization recorded branch-by-branch; and
- an exact discrete `Z4` reindex/gauge change whose permutation is recorded and whose branch set is unchanged.

No branch is invented or deleted. A field-matching "repair" is admissible only when exact discrete transport/cycle evidence determines one canonical reindexing. Contradictory/non-integrable matching is typed refusal, never iterative perturbation until the current A1 tolerance happens to accept it.

### 4.4 Feature identity

Every raw hard feature/source barrier maps through the certified vertex/edge correspondence to one unambiguous conditioned feature. A merge that conflates incompatible feature ownership or removes a required feature edge rejects.

### 4.5 Operation log

Every value-changing operation record contains:

- typed operation kind;
- raw typed locus/owner IDs;
- exact before value or canonical input bits;
- exact after value or canonical output bits;
- exact policy parameter(s) and policy ID;
- correspondence IDs affected;
- deterministic operation evidence sufficient for an independent validator to recompute the decision.

An empty operation log is a meaningful clean outcome and must validate as such.

## 5. Permitted conditioning operations — closed list

The semantic operation list is closed. A later implementation may use fewer operations but may not add one without a new definition/review.

### C0 — canonical exactification

Convert finite public binary64 values to exact dyadic authority and canonical typed IDs. This is not a value change and must be lossless.

### C1 — bounded dyadic lattice quantization

Geometry and raw field components may be mapped once to the explicitly configured dyadic lattice `k / 2^e`. The policy stores the integer exponent `e` and any exact integer range bound; nearest/ties-to-even is evaluated over exact rationals. The exact rounding result and every changed locus are recorded. No adaptive epsilon and no repeated snap-to-fit loop is permitted. Amendment 20 permits a general bounded rational lattice, but the first accepted binary64 product freezes the exactly representable dyadic subset only.

### C2 — exact-equality near-duplicate merge

"Near duplicate" means only that C1 maps multiple raw vertices to **exactly the same conditioned lattice point**. The merge then obeys §4.1. Raw-space distance by itself never authorizes a merge.

### C3 — sliver refusal

CB1 freezes **refusal**, not topology-changing repair. Sliver/degeneracy classification must use an exact scale-aware rational predicate whose policy bound is an explicit exact input, not a source constant hidden in `double`. If a fixture exceeds that policy, return the typed failure from §7. A later sliver-repair algorithm requires a new definition because face flips/retriangulation would change the §4.2 correspondence contract.

### C4 — exact field matching admissibility reindex

Only a unique/canonical discrete `Z4` reindexing proved from exact field/transport authority is permitted. It may relabel branches but cannot perturb vectors until a cycle closes. If no unique admissible reindexing exists, reject.

No other value-changing operation is permitted. In particular, mid-pipeline mollification, geometric nearest-owner selection, topology invention, unrecorded edge flips, repeated correction until validators pass, and consumer-local snapping are forbidden.

## 6. Relationship to A0/A1 and legacy tolerant seams

Amendment 20 supersedes the older sentence in `DESIGN.md` §6.3 that called A0 mollification the single sanitization boundary. After CP-COND cutover:

- **CP-COND/InputConditioner** is the sole value-changing sanitization boundary;
- **A0** validates and publishes exact source support/identity from the immutable conditioned product; it may not mollify or mutate values;
- **A1** derives transport/matching/singularity authority from the conditioned field and may fail closed, but it may not modify the field.

The current `finalize_surface_cell_raw_cross_field` checks branch norms with `1e-12` and accepts rounded cycle indices within `1e-6`. Those checks may remain diagnostic/materialization aids while the cutover is staged, but after CP-COND acceptance they cannot be the semantic admissibility authority. CB1 must place the certified conditioner verdict ahead of them and ensure no tolerant result can override a typed conditioner refusal.

This is a **boundary correction only**. It does not change CP3 A3 counts, breakpoints, shared-boundary identities, parity scheduling, or A4-local family/advance-sign semantics.

## 7. Typed refusal semantics

`ConditioningFailure` records a stable failure code, exact locus where meaningful, raw digest, policy ID, and certificate/derivation evidence sufficient for independent validation. The minimum frozen code surface is:

- `NonFiniteInput`;
- `InvalidSourceConnectivity`;
- `ExactDegenerateFace`;
- `SliverPolicyExceeded`;
- `FeatureCorrespondenceConflict`;
- `FieldShapeInvalid`;
- `FieldTransportInadmissible`;
- `ConditioningPolicyUnrepresentable`.

The broader architecture distinction `FatalInadmissible` versus `RegularizableDegeneracy` remains typed metadata, but CP-COND does **not** assign D0-D4 or freeze M5/M7 disposition mapping here. Amendment 21's later disposition ownership is unchanged.

One invocation returns one result. There is no retry with relaxed thresholds, no alternate policy cascade, no "repair until accepted", and no fallback that bypasses the refusal.

## 8. Independent certificate validator

A separate validator receives raw input, policy and produced result. It recomputes:

- raw digest and conditioned semantic digest;
- every vertex/face/field/feature correspondence invariant;
- every operation's exact before/after relation;
- policy-bound compliance;
- no unlogged value changes;
- no missing raw owner and no multiply owned conditioned entity except a certified §4.1 merge;
- one-to-one face correspondence;
- field branch-set preservation up to the recorded exact `Z4` permutation;
- typed refusal derivation when outcome is Rejected.

The producer's own `ok` bit, digest, log or correspondence is evidence to compare, never the validator's oracle.

## 9. Idempotence and tamper semantics

For a Produced result `P` and the same frozen policy, conditioning `P` as a raw bundle must produce `P2` such that:

- `P2.conditionedSemanticDigest == P.conditionedSemanticDigest`;
- topology/typed IDs/canonical bits are byte-identical under canonical serialization;
- correspondence is identity relative to `P`;
- operation log contains zero value-changing operations.

Idempotence is not "within tolerance". Any second value change is a semantic failure.

The independent oracle must be non-vacuous. Deleting, swapping or corrupting at least one of vertex correspondence, face correspondence, field permutation, operation log or digest must change the validator outcome to rejection. A validator that verifies an empty subset or trusts the candidate's digest is invalid acceptance evidence.

## 10. CP-COND witness matrix and gate preconditions

No identity becomes a required selector gate until its raw precondition is independently established. Guaranteed-green fixtures are prohibited.

| Coverage item | independently established raw precondition | required CP-COND outcome | gate status after CB construction |
|---|---|---|---|
| sliver / anisotropic geometry | exact rational shape predicate proves the fixture crosses the fixture-declared exact sliver policy; raw connectivity itself is valid | typed `SliverPolicyExceeded` for the initial refusal-only contract, with exact locus/certificate | **gating once precondition helper is independently verified** |
| high valence | independent integer valence census proves at least one source vertex exceeds the currently accepted max-6 witness surface; no sliver/feature/field contradiction masks it | **Produced**, preserving exact incidence and certified correspondence; high valence alone is not inadmissibility | **gating once a clean high-valence raw fixture exists** |
| negative-index singularity | independent exact/discrete cycle oracle derives a **valid negative index** and proves field admissibility from raw branch/transport data rather than reading production output | **Produced**, preserving the independently derived negative-index authority through the conditioner; contradictory transport belongs to the separate deliberately-inadmissible-field gate | **gating only after the admissible expectation is independently derived** |
| boundary-truncated separatrix | independent source-boundary/field construction proves, before production execution, that one separatrix is truncated by a real source boundary and that conditioning preserves the data on which that derivation depends | **Produced** correspondence preserving boundary and field authority; later A2a behavior is not CP-COND's decision | **conditional gate; if the raw precondition cannot be proved independently, record blocker/non-selector** |
| deliberately inadmissible field | independent exact cycle/matching construction proves contradictory transport or branch-set inconsistency before conditioner execution | typed `FieldTransportInadmissible`; never vector perturbation until A1 accepts | **gating** |
| correspondence integrity | independently constructed raw owners include non-empty vertex, face, field and feature/correspondence surfaces | produced certificate validates; one-at-a-time tamper/delete/swap of each authority class fails | **gating** |
| idempotence | at least one Produced witness contains a non-empty recorded C1/C2/C4 operation surface, plus one clean identity witness | second pass same digest/topology/bits and zero changes; tampered policy/product is discriminated | **gating** |
| S6 perturbation | two raw inputs are independently proved, in exact arithmetic, to quantize to the same frozen lattice cells/branch authority | identical conditioned semantic digest/topology under same policy | **gating for exact same-cell equivalence once built; physical-distance/uncertainty metrics remain report-only until a later threshold review** |

The existing `BoundedMeshPreconditionerPhase07` tests and accepted selector408 rows do not satisfy these gates merely by being green; they do not exercise this product/certificate contract.

## 11. Carried obligations and scope exclusions

- `M4-CP3-TB1-R1-REV-OBS-01` is **not naturally independent CP-COND coverage**. It stays carried to the first later independently falsifiable M4 test-authority turn before CP4; CP-COND must not distort its multiplicity-2 oracle to absorb unrelated debt.
- `M4-CP3-CB4-REV-OBS-02` remains owned by the next legitimate row399 touch. CP-COND does not touch row399.
- TB3 row408 provenance remains a historical-claim bound.
- the three `G4-B002` produced-witness debts remain M4-CP4 gates; the two `G4-B003` debts remain M5 gates.
- CP-SCALE owns expression-swell thresholds, certified-filter scale work, typed exact-computation bounds and genus>=2 reachability.
- field generation/holonomy optimization, M5/M6 relation/quotient work and M7 disposition policy are outside CP-COND.

Stable regression accounting therefore remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 12. CP-COND exit condition

CP-COND may close only when one immutable package runtime-proves, on a cumulative append-only selector:

1. the single-writer conditioned source product and exact policy identity;
2. independently validated raw-to-conditioned correspondence;
3. typed refusal for deliberately inadmissible input and exact sliver policy breach;
4. independently proved high-valence, negative-index, and boundary-truncated witness preconditions, with any genuinely unreachable item left as an explicit blocker rather than fabricated gate credit;
5. non-vacuous correspondence-tamper discrimination;
6. exact idempotence;
7. exact S6 same-cell equivalence if its precondition is constructed;
8. no mutation of the accepted CP3 A3/A4 semantics and selector408 preserved byte-for-byte as predecessor prefix.

Definition freeze alone does not close CP-COND.

## 13. Definition falsifiers / STOP rules

STOP and return to independent definition/review if any implementation requires:

- a second source/field value writer after InputConditioner;
- epsilon/raw-floating geometry as correspondence or admissibility authority;
- topology-changing sliver repair under the CB1 one-to-one face contract;
- a repeated/relaxed repair loop whose stopping condition is acceptance;
- branch-vector perturbation to make field transport close;
- conditioned/raw identity inferred from proximity rather than the certificate;
- A0 or A1 value mutation after the conditioner;
- any change to accepted CP3 A3/A4 semantics;
- CP-SCALE thresholds, genus>=2 acceptance, M5/M6 relation work, M7 disposition mapping, or CP4 produced-witness debt;
- a gating identity whose independent raw precondition is not established.

## 14. Exact successor

**`M4-CP-COND-CB1` — Code + Build / compile-only.** Implement the smallest conditioner product/certificate/validator seam and the frozen witness fixtures/tests without executing Directional runtime. Its authoritative plan is `Architecture_M4_CP_COND_CB1_Code_Build_Plan.md`.
