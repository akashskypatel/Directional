# `M6-CP2-DEFN` — Independent Surface Product Verifier Definition Plan

> **Review-agent block — routing review after `M6-CP1-CLOSE-REV` (2026-10-05). Binding additions to "Binding scope". Each must be decided with `file:line` reasons before any CP2 Code + Build.**
>
> **D1. Negative-witness seam (decide first; everything else depends on it).** Products are built only through validating factories (`SurfaceOccurrenceComplexProducer::publish_records_for_validation`, `SurfaceQuotientProducer::publish_records_for_validation` at `RemeshPipeline.cpp:5572`, and the A7 producer). A verifier that only ever sees validated products has no reachable negative, so every §6.3 failure would be vacuous.
> - Define how malformed authority reaches the verifier. One option: the verifier consumes immutable **record views** exported from products (for example `SurfaceQuotientValidationRecords`, `RemeshPipeline.h:1249-1256`), and tests tamper those records.
> - **A production unchecked factory is forbidden.**
> - For each §6.3 class, state whether its witness is reachable through the seam (lesson 199). Classify any unreachable class as defensive, with a reason.
>
> **D2. C4 reachability before designing its witness (plan item 6).** A6 recomputes the class partition and rejects merges that relations don't support (`InvalidClassPartition`, `RemeshPipeline.cpp:5814-5890`). It also validates relation evidence before the closed-complex view is built (`:6074`, `:6374`). So a weld-pinched topology is probably **shadowed** before C4 runs.
> - Prove statically whether any A6 input reaches C4.
> - If none does, classify C4 as accepted-defensive (like C2) and let the verifier's §6.2 manifoldness recompute, fed through D1, be the executed falsifier for pinched topology.
> - Do not forge relations to reach C4.
>
> **D3. Three-sheet tamper source (plan item 7).** `split_isolation_fixture()` has only 2-sheet bridge occurrences. Choose and justify one of:
> - an in-chain tamper that adds a third sheet to a bridge's `cornerWedgeSheets` while its transitions connect only two (republish A5, re-produce A6, then A7; RA-27a §5);
> - a new **produced** fixture with a genuine 3-sheet corner wedge.
>
> In both cases, show that the region and touch tampers each defeat a specific mutant that identity 29 does not defeat (lesson 200).
>
> **D4. Production integration of A8.** Decide whether the production pipeline runs `SurfaceProductVerifier` and fails closed on a `VerificationFailure`, and if so where (after A7, after completion, or after final validation).
> - Running it on all 449 selector rows adds runtime and new failure modes. Pre-register a stop rule: **any accepted selector449 or focused-30 row that the verifier rejects stops for Review**, and is not to be weakened.
> - If the verifier stays test/benchmark-only in CP2, say so and assign pipeline integration to CP3.
>
> **D5. Gate architecture (plan item 8).** Decide whether CP1's focused-30 is folded into a cumulative published selector before CP2 appends, or CP2 runs focused-30 + CP2 focused + selector449. Either way:
> - selector449 and focused-30 stay byte-exact prefixes;
> - routing449 is unchanged;
> - the gate count is computed from the enumerated identities, not guessed.
>
> **D6. Successor chain.** `M6-CP2-DEFN` → mandatory **`M6-CP2-DEFN-REV`** → the first CP2 Code + Build (name frozen by the Definition) → TB → Review. No implementation is authorized by the Definition itself.
>
> Unchanged: `G4-B002` stays open (debt 1); `M6-DEFN-R5` follows CP2; RA-17's transport guard holds; M7 semantics are forbidden.

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
