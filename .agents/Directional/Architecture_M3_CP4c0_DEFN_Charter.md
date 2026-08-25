# Architecture M3 CP4c-0 — Definition-Turn Charter

**Status:** AUTHORIZED CHARTER ONLY — `M3-CP4c-0-DEFN` has not executed
**Origin:** `M3-CP4c-1-TB-R2-REVIEW-PLAN`, corrective measure Z3
**Boundary:** independent definition/review + planning only; no production, test, fixture, selector, build, package, or runtime mutation

## Purpose

Define the missing within-face branch-continuation datum that blocks A2a candidate tracing on the prescribed-sphere witness. The definition turn must adjudicate the contract before any implementation turn is authorized.

The current evidence to consume is intentionally observational:

- `FieldBranchBoundaryPairing.connections` currently publishes the full incoming-carrier × outgoing-carrier relation.
- `field_aligned_outgoing_carrier` requires one unique outgoing continuation for an incoming carrier.
- `FieldAlignedCandidateTraceSegment` currently carries no within-face position datum.
- `DESIGN.md` section 4.5 requires resolved branch-boundary pairing and barycentric positions propagated with arbitrary-precision semantics.
- `M3-CP4c-1-CB3` / `M3-CP4c-1-TB-R3` are expected to add a non-gating pairing census and a prescribed-sphere failure-site observation. Those measurements are inputs to this definition turn; they do not themselves authorize a fix.

## Questions the definition turn must decide

### D0 — Exact position authority

Define the exact within-face position representation required to resolve an incoming interval to one outgoing interval:

- value/type and precision semantics;
- ID/key domain;
- canonical orientation and coordinate convention;
- single writer / publication stage;
- whether an existing `SourceSupport` representation is sufficient or a new typed value is required;
- how the value survives transport across source-face boundaries without introducing a second semantic authority.

Do not infer this from the current floating-point tracing representation. Re-derive it from the frozen design contract and source topology.

### D1 — Within-face continuation construction

Define the Ray–Sokolov-style continuation rule that maps an incoming boundary occurrence and position to exactly one outgoing boundary occurrence and position.

The definition must specify:

- valid preconditions;
- deterministic tie/degeneracy handling;
- typed rejection vocabulary;
- required rejection loci and diagnostics;
- which cases are invalid input versus an unresolved but valid continuation;
- a falsifying witness for every nontrivial branch of the rule.

### D2 — A1 transport-contract shape

Decide how `FieldBranchBoundaryPairing` changes:

- whether `connections` becomes a true function;
- whether the Cartesian-product relation is removed or retained only as non-authoritative diagnostic data;
- whether `intervals`, `incomingCarriers`, and `outgoingCarriers` remain authoritative fields;
- how semantic digests and canonical ordering bind the new datum;
- how `FieldBranchTopology::transport` and singularity-port attachments consume or remain independent of the new authority.

No implementation shape is authorized until this contract is frozen.

### D3 — Accepted-prefix re-proof surface

Inventory every accepted owner or consumer that must be re-proved if A1 semantic authority or digest changes, including at minimum:

- M3-CP1;
- M3-CP2;
- M3-CP2b;
- M3-CP3a;
- M3-CP3b;
- M3-CP4ab.

For each checkpoint, identify the exact identities or frozen contracts affected and whether the change is semantic, digest-only, diagnostic-only, or no-op. Do not weaken or silently rewrite accepted evidence.

### D4 — Witness-stage capability

For every witness proposed for definition or later implementation evidence, prove and record the furthest stage it actually reaches under the production entry path. At minimum cover:

- two-ring skew disc;
- four-triangle fan;
- torus;
- mechanical feature;
- prescribed sphere.

Do not reuse a witness merely because it was accepted for an earlier contract.

### D5 — Terminus-datum unification

Adjudicate whether the previously identified missing barrier-terminus position datum and the within-face continuation position are one semantic datum with one owner or two distinct contracts.

The definition turn must state the exact predicate each consumer needs before deciding whether the work is unified. Do not reopen an accepted product solely because both defects mention position.

## Required evidence inputs

Before `M3-CP4c-0-DEFN` may freeze an answer, consume:

1. the binding `Architecture_M3_CP4c1_TB_R2_Review_Plan.md`;
2. the exact CB3 source audit for Z0;
3. the TB-R3 non-gating branch-pairing census, including per-witness `(incoming,outgoing)` distributions;
4. the TB-R3 prescribed-sphere site pin, completed-segment count, current face, carrier sets, multiplicity, and branch-transport-adjacency observation;
5. the frozen CP4 definitions and `DESIGN.md` section 4.5;
6. the relevant durable lessons on Cartesian-product relations, missing barycentric position, witness stage reachability, single authority, and re-proof of accepted predecessors.

If TB-R3 falsifies the review prediction by locating the sphere failure at `field_aligned_next_face` or `topology.transport` rather than `field_aligned_outgoing_carrier`, stop and return to independent review before freezing this charter's proposed domain.

## Required outputs

A complete `M3-CP4c-0-DEFN` turn must produce, without implementation:

- one frozen typed definition for the missing position/continuation authority;
- one source-to-product ownership diagram or equivalent explicit ownership table;
- one rejection/diagnostic table with typed loci;
- one accepted-prefix migration/re-proof matrix;
- one witness-stage capability table;
- a determination on terminus-datum unification;
- a bounded next Code + Build plan with explicit success criteria and compile-only verification;
- updates to durable task/handoff records that route CP4c-1 through CP4c-0 without changing the 318-identity CP4c-1 required-green selector.

## Stop conditions

Stop the definition turn and return to independent review if:

- CB3/TB-R3 evidence contradicts the assumed within-face ambiguity mechanism;
- the proposed datum would create two semantic writers;
- the design source does not support a unique continuation rule for an observed nondegenerate case;
- the required accepted-prefix re-proof cannot be enumerated;
- any proposed witness cannot reach the stage whose contract it is supposed to prove.

`M3-CP4c-0-DEFN` is a prerequisite to any pairing/position implementation. This charter does not authorize production changes.
