# `M6-CP2-DEFN` — Independent Surface Product Verifier Definition Plan

**Type:** bounded runtime-free Definition.
**Entry authority:** M6-CP1 CLOSED / ACCEPTED by `Architecture_M6_CP1_Close_Review_Record.md`.
**Reviewed runtime authority:** `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`, 479/479.
**Accounting:** 60 / 16 / 44; debt 1.

## Goal

Freeze the CP2 contract for `SurfaceProductVerifier`, which consumes immutable A0/A5/A6/A7 products and independently verifies the already-published facts without repair, alternative-route search, re-canonicalization, welding, or product mutation.

This turn defines only the verifier contract and the first CP2 implementation/test gate. It does **not** implement A8, run tests, alter selectors, discharge `G4-B002`, or pull CP3/M7 work forward.

## Binding scope

1. Freeze the exact `VerificationReport` / typed `VerificationFailure` representation and semantic finding identity/order.
2. Translate frozen §6.2 into an explicit recompute matrix. At minimum:
   - A0 incidence/component facts;
   - A5 occurrence ownership and directed-side cycle incidence;
   - A6 quad/edge incidence, connected components, boundary loops, Euler characteristic and manifoldness;
   - A5→A6 cell/membership consistency by published IDs;
   - exact named-certificate transport composition/inversion;
   - A7 support incidence;
   - deterministic equality of immutable certificate payloads.
3. Freeze a typed failure matrix for every §6.3 malformed-authority class. Every failure must be fail-closed and must identify the semantic stage/locus, not discovery order.
4. Define certificate-chain binding required by `M6-CP1-TB12-REV-OBS-01`:
   - every A6 relation certificate/consumption must equal the A5-owned relation/evidence it cites;
   - every A7 support/embedding certificate must bind to the exact A6 class/topology and referenced A5 evidence;
   - equality is deterministic over immutable semantic ordering; no search for an equivalent replacement is permitted.
5. Resolve RA-26 §5(iii): either retire the optimizer `project_vertices` component/sheet self-check as non-authoritative or replace it with membership against class-wide `vertexChartAuthority`. The Definition must state which layer owns the check and why; no optimizer code changes occur in this Definition turn.
6. Define the C4 executed witness required by RA-27b: a deliberately malformed weld-pinched A6 topology (two quad fans sharing a vertex / non-unique opposite continuation) that is rejected independently by verifier manifoldness and exercises `QuotientClosedComplexStripContinuationMismatch` without legitimizing any coordinate/position weld in production.
7. Define three appended CP2 focused tampers for `M6-CP1-TB12-R1-REV-OBS-01`, leaving identity 29 untouched:
   - wrong-region wedge transition;
   - one-endpoint-in-set / "touches" transition that does not connect the retained sheet set;
   - three-sheet partial-connectivity graph.
8. Freeze the first CP2 Code + Build test names, selector append policy, compile targets, immutable TB gate size, and stop rules. The Definition must not invent a gate number before counting the exact appended identities.

## Explicit exclusions / later owners

- `G4-B002` produced-witness debt remains CP3 and debt stays 1.
- RA-26 §5(i)(ii)(iv), gauge obligations, A5 barrier-set census, RA-27a §6 seam-collinear edge falsifier, and `M6-CP1-TB12-REV-OBS-02` remain `M6-DEFN-R5` → CP3.
- Adapter cross-sheet diagnostic-site preservation remains M8-CP2.
- M7 disposition/degradation/omission semantics are forbidden in CP2.

## Verification of this Definition turn

The resulting Definition/Review pair must prove:

1. Every allowed verifier recomputation is an elementary fact named by frozen §6.2.
2. Every forbidden operation in §6.3 has a typed failure and no repair path.
3. Certificate-chain binding is exact and cannot substitute equivalent but unreferenced authority.
4. C4 and the three RA-27a static-only conjuncts have executable falsifier designs before implementation begins.
5. The first CP2 Code + Build is bounded to verifier implementation plus the frozen appended identities; no CP3 work is mixed in.

A Definition ambiguity that changes A5/A6/A7 semantics, permits verifier repair, or requires source-product mutation stops for Review rather than being resolved in implementation.
