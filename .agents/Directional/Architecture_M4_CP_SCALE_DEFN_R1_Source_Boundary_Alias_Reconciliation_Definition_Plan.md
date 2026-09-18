# M4-CP-SCALE-DEFN-R1 — Source-Boundary Alias Reconciliation Definition Plan

**Turn:** `M4-CP-SCALE-DEFN-R1`
**Type:** runtime-free definition / architecture amendment
**Predecessor:** `M4-CP-SCALE-TB12-R9-REV`
**Accepted runtime authority:** package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**
**Unpromoted subject:** CB22 artifact `10548849094` / source `ec348a1d13f96764da5674b66a3ce314a4a8c2cb`
**Runtime / compile / product mutation:** forbidden

## 1. Goal

Freeze one exact semantic rule for producer boundary-index aliases after source-topology hard-feature cuts can place the same source-boundary vertex on multiple region-relative boundary loops. The definition must resolve R9's `SingularityMismatch;sourceVertex=1;topologyRegion=1` without guessing an implementation and without weakening the original CP2b obligation to reconcile legacy boundary aliases against typed authority before collapsing them.

This turn produces definition only. It does not edit product/test/fixture/selector/build source, execute generated Directional runtime, compile, package, retry R9, promote CB22, grant S5/A3 credit or publish selector427.

## 2. Facts already frozen by R9 Review

1. `dual_cycles(...)` maps every source-boundary vertex on one loop to one aggregate global boundary-cycle row; `effort_to_indices(CartesianField&)` can therefore emit that one boundary-loop index once per boundary vertex.
2. Those vertex-keyed entries are legacy aliases of one global source-boundary-cycle fact, not independent singularity ports. Existing `LESSONS.md` 42 requires alias collapse **with reconciliation**, never silent discard.
3. In the corrected skew fan, hard edges `(1,4)` and `(3,4)` create two source-topology regions `{0,3}` and `{1,2}`. Boundary vertex1 belongs to both regional boundary loops.
4. Current `boundaryCycleByGlobalVertex` allows exactly one regional `(TopologyRegionId, FieldCycleId)` per source vertex. R9 fails when the second real regional owner is encountered.
5. Region-relative boundary `turningLift` may include region-level correction and therefore is not automatically the global source-boundary-cycle numerator. R7 already falsified the analogous global-interior-index/per-region-boundary-lift equality.
6. CB21's globally-interior separating-owner path is recovery-proved and must not be reopened by redefining boundary aliases.

## 3. Required definition questions

The definition must answer each question explicitly and from exact authority, not implementation convenience.

### D1 — What owns the global boundary-index fact?

Choose and justify the single typed owner for the source-boundary loop's index. A per-vertex alias key is not itself semantic ownership. If the owner is a global source-boundary-cycle witness, define its exact identity and where A1 obtains or reconstructs it without creating a second numeric authority.

### D2 — What is the relation to regional boundary loops?

Define whether a global boundary-cycle fact has zero, one or many region-relative associations after hard-feature cuts. If several regional loops meet one alias vertex, state whether those are support/incidence relations only or carry semantic ownership. A deterministic minimum region is not a proof of ownership.

### D3 — What exact reconciliation invariant survives the cut?

The old uncut invariant `boundary alias numerator == owning BoundaryLoop.turningLift` is insufficient once the only available loops are region-relative. Freeze one exact replacement, such as a global-cycle reconciliation, a proved aggregate relation, or another single-authority statement. Do not invent a congruence, tolerance or arbitrary representative.

### D4 — What does atlas publication retain?

Specify whether boundary aliases appear in `FieldSingularityFact`, diagnostics only, or another typed boundary-cycle relation. Preserve the rule that source-boundary aliases do not become independent singularity ports. State how tamper/mismatch remains rejectable after aliases are collapsed.

### D5 — What must remain unchanged?

The definition must preserve:

- accepted selector426 and TB11 authority;
- CB21's source-incidence/containment owner for globally-interior separating singularities;
- `4-index` singularity port-class arithmetic and attachment validation;
- all-component cycle ordering and canonical component sequence rules;
- hard-feature source-topology partitioning;
- the accepted uncut boundary-alias negative/reconciliation intent;
- retained genus-two fixture/rawfield bytes and production S5 focus semantics.

## 4. Independent source proof required

Before freezing the amendment, statically trace all consumers of `rawBoundarySingularity`, `boundaryCycleByGlobalVertex`, source-boundary `FieldCycleKind::BoundaryLoop` witnesses and `sourceBoundaryBoundSingularityCount`. Build a complete ownership/dataflow table that distinguishes:

- global source-boundary cycle;
- legacy per-vertex alias;
- topology-region relative boundary loop;
- globally-interior separating owner;
- same-region slit owner.

For each equality or map key in that path, record the authority domain on both sides. The definition is incomplete if any global/relative equality remains justified only because it happened to hold on an uncut fixture.

## 5. Falsifiers and STOP conditions

STOP and do not authorize Code + Build if any of the following holds:

1. no unique global owner for the boundary-index fact can be identified without re-deriving field semantics from a second authority;
2. the proposed rule chooses a regional owner only by stable ordering/minimum ID rather than a semantic identity binding;
3. the proposed reconciliation silently drops aliased producer entries without a falsifiable mismatch check;
4. the proposal requires weakening `SingularityMismatch`, port-class arithmetic, cycle transport, source partitioning or an accepted selector identity;
5. the proposal needs runtime evidence to decide between materially different semantics — in that case freeze the smallest diagnostic/evidence-producing successor instead of guessing;
6. the source audit finds another consumer that independently treats a boundary alias as a singularity fact or per-region lift and the amendment does not cover it.

The frozen “third distinct product cause” count remains unspent: R9 is an `RP-01` refinement. DEFN-R1 exists because the ownership invariant is presently underspecified, not because the count threshold fired.

## 6. Completion and successor contract

A complete DEFN-R1 turn must publish one normative amendment (or an explicit proof that existing authority already uniquely determines the answer), update the tracker/handoff/TODO/ROADMAP/ORIENTATION, and freeze exactly one successor.

If the invariant is fully determined and implementation is bounded, the successor may be one Code + Build turn limited to that invariant plus independent direct controls and compile/package only. If definition remains ambiguous, the successor must be the smallest runtime-free evidence/measurement turn required to resolve it. No artifact-only retry is authorized directly from this plan.
