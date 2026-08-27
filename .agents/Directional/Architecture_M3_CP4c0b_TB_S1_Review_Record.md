# Architecture M3 CP4c-0b — TB-S1 Evidence Review Record

**Status:** COMPLETE / REVIEW GREEN / S1 STOP NOT TRIGGERED
**Turn:** `M3-CP4c-0b-TB-S1-REV`
**Scope:** evidence review and successor planning only. No Directional runtime, compile, benchmark, package creation, product/test/fixture/selector/build-configuration semantic change, or acceptance attempt occurred in this review turn.

## 1. Authorities reviewed

- accepted continuation authority: CP4c-0 **346/346**, frozen selector SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`;
- S1 build semantic source / immutable GMP package: `4bb467806df99c70889394a323c17c13bc185ca3 / 9655632444`, package SHA-256 `c22e9b020e533ca8fc558bcafc3e138a062702a59bee68a097958b432d70bc5f`;
- TB-S1 execution: run/job `33097182476 / 98605092984`;
- raw result/log artifacts: `9656967036 / 9656967437`, SHA-256 `dd1f8aa8f2346612beb445d7e5d6a8768a438e36c543e0b4d407b444523d85a4 / 667b9c54ad24e9e33855d3fd47a322593c4522bde4984177dfa593a1df7f6bb8`;
- pre-authored plan authority: `Architecture_M3_CP4c0b_P0_3_Independent_Review_Record.md` measures S0-S8;
- frozen termination authority: `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md` as amended by P0.3 Amendment A1.

The raw TB-S1 result artifact was independently re-hashed in this review and matched its recorded SHA-256. Its `result.json` records `exactArithmeticBackend=GMP`, package source `4bb467...`, `346/346 PASS`, diagnostic identity selected exactly once/PASS with `gateCredit=0`, `requiresIndependentReview=false`, no configure/compile/relink/repair/generated discovery, no mutation, and immutable postflight PASS.

## 2. S1 census — independently read from the raw artifact

| witness | population | A / B / C | current shared-face contacts | proper / non-proper / unevaluated | nodes | disposition |
|---|---|---:|---:|---:|---:|---|
| `two-ring` | included | `1 / 0 / 0` | `0` | `0 / 0 / 0` | `9` | reached |
| `four-triangle-fan` | excluded fixture artifact | `1 / 0 / 0` | `0` | `0 / 0 / 0` | `8` | reached but non-creditable |
| `sphere_prescribed` | included | n/a | **not reported** | **not reported** | n/a | unreached at N1 |
| `torus` | included | `0 / 0 / 0` | `0` | `0 / 0 / 0` | `0` | reached |

The prescribed sphere stopped before `finalize_field_aligned_events` at the expected typed `TraceCombinatorialRecurrenceExceeded`: `traceSteps=65`, `traceStepBudget=9216`, `traceCombinatorialVisits=3`, `traceCombinatorialVisitAllowance=2`. **This review does not translate that into a zero-contact claim.**

For the two-ring, the event histogram is `SingularityPortOrigin=1, FirstContact=3, TraceIntersection=1, MandatoryBarrierTermination=3`; the sole recorded site is **A**, the singularity-origin junction, at source vertex `0`. The excluded fan has the same event histogram and one site-A junction at source vertex `4`. Torus has no nodes or events.

## 3. Review interpretation

### R1 — the S1 routing stop is not triggered

P0.3's binding stop is: if a **current product contact on an accepted witness** is non-proper (or cannot be evaluated), correcting the predicate would change accepted trace/contact semantics and must return to Review before S3.

No reached included witness has a site-B product contact at all. The S1 diagnostic calls the same `field_aligned_first_trace_contact` used by production finalization and records every contact that this product mechanism actually selects before truncation. On the bounded completed traces of the reached included witnesses, site B is therefore empty. There is no non-proper or unevaluated selected contact to trigger the stop.

**Verdict:** S1's mandatory return-to-review condition is discharged. S2-S6 may resume under the already frozen semantics.

### R2 — `requiresIndependentReview=false` is a routing result, not proof that the proper-crossing predicate was exercised

The zero values are a **zero denominator** for the crossing classifier on reached included witnesses. They establish that replacing the faulty shared-face predicate cannot change those witnesses through site B, because site B is unused there. They do **not** dynamically demonstrate a live proper crossing, endpoint touch, or collinear overlap.

This distinction matters because the prescribed sphere — the non-trivial contact-domain witness — never reaches current post-hoc finalization. Its proper-crossing evidence remains the independently frozen pre-contact measurement in the CP4c-0b DEFN: each of the six circulating traces has many proper transversal crossings against other traces and a first available crossing at its own step 0. S1 neither strengthens nor weakens that measurement.

### R3 — S3 is behavior-preserving on the reached accepted contact surface, but S2 is intentionally not byte-preserving

For the reached included witnesses, **S3 alone is behavior-preserving with respect to current product contact selection**: current site-B count is exactly zero, so narrowing site B from co-face to proper crossing removes no selected contact.

S1 simultaneously gives positive evidence that **S2 changes an accepted event stream on purpose**. The two-ring has site `A=1` and its only `TraceIntersection` is that singularity-origin junction. S2 must reclassify that event as the new singularity-junction kind while retaining `TraceIntersection` exclusively for site B. Because event kind participates in the semantic digest, the two-ring semantic digest may change even though its traces, node count, barriers, and contact termini do not.

P0.3 explicitly authorized this vocabulary split and S7 permits an accepted expectation edit when S1 predicted the affected witness in advance. S1 has now done so for site A.

### R4 — exact predecessor migration boundary

Two accepted CP3b identities are statically known to encode the old site-A vocabulary and are therefore explicitly authorized for S2 re-authoring:

1. `FieldAlignedCurveNetwork.DeclaresTraceIntersectionsAsTypedNetworkEvents` — its witness is the multi-port singularity junction and must assert the new junction kind rather than calling site A a `TraceIntersection`;
2. `FieldAlignedCurveNetwork.IndependentCompositionOracleValidatesTraceEventGraph` — its two-ring precondition currently requires a `TraceIntersection` only because site A supplies one; after S2 it must require the explicit singularity-junction event while keeping the independent terminal/contact composition checks strict.

Relative digest/invariance identities remain semantically binding and are **not** authorized to weaken. `PublishesTypedFirstContactAndTerminationEvents` remains a barrier-termination contract on the two-ring and has no S1 site-B contact to migrate. Any other accepted identity requiring a changed expected semantic outcome is a stop and returns to Review unless the CB report can tie it to the S1-measured site-A migration above.

## 4. Successor plan — one complete Code + Build, no invented partial-CB edge

The exact next turn is **`M3-CP4c-0b-CB1-S2-S6`**. It is the resumed completion of the already reviewed CB1 surface, not a new checkpoint and not a user-unauthorized partial-CB cadence exception. It implements S2 through S6 in the frozen order and emits one final immutable package only after the integrated semantic source is complete.

Within that Code + Build turn:

- **S2 — vocabulary:** add a new non-reused `SingularityPortJunction` kind for site A and a new non-reused `TraceSelfClosure` kind for site C; `TraceIntersection` means only site B. Update validators, hashing/name/report surfaces, and the two explicitly authorized predecessor identities above. No retired numeric enum value is reused.
- **S3 — exact predicate:** promote the already authored exact barycentric four-orientation proper-crossing predicate into the production contact decision. Shared singularity origins remain excluded. Endpoint touches and collinear overlaps are typed observations, never widened into contacts. `field_aligned_common_carrier` remains diagnostic only.
- **S4 — priority:** replace trace-index seniority with frozen `ArcLengthFiltered`, computing the forward error bound alongside the accumulated value. Inconclusive comparisons and exact ties use mutual termination. Remove `existingIndex < traceIndex` as topology authority; no hidden seniority tie-break survives. Alternatives remain diagnostic-only and production cannot select them.
- **S5 — relocation:** move contact detection into the global tracing advance/priority queue so crash-on-contact can terminate circulating traces before N1. `finalize_field_aligned_events` publishes already-decided events/nodes and no longer truncates traces or clears terminal state.
- **S6 — terminal datum:** add exact `terminalContact` carrying the crossing point plus struck trace/segment identity. Every completed trace has exactly one of singularity, barrier, or contact. `NetworkNodeId` acquires no positional meaning. The CB report must state whether `NetworkNode::sourceVertex` remains only provenance and cannot be mistaken for contact position.

Code + Build remains runtime-free. GMP/GMPXX is mandatory. The exact changed-owner target must compile in a separate pre-package run, followed only then by the full eight-standard-target package compile on the **same semantic SHA**. No Directional binary/test/benchmark/discovery process may execute in CB.

## 5. Required new-contract surface before acceptance

CB1-S2-S6 freezes the CP4c-0b selector as predecessor **346 + n**; `n` is the actual authored new-contract identity count, not a guessed count. At minimum the new identities must make these seams non-vacuous:

- exact proper crossing accepted;
- shared singularity origin rejected as contact;
- endpoint touch and collinear overlap published as typed non-contact observations;
- site A/B/C vocabulary is disjoint and no retired enum value is reused;
- production priority is only `ArcLengthFiltered` and the alternatives harness is unreachable from production;
- computed comparison bound has conclusive/inconclusive evidence and no literal epsilon;
- exact tie/inconclusive arrival produces mutual termination;
- `terminalContact` carries the exact locus/struck trace/segment and completed traces have exactly one terminal kind;
- N1/N2/N4 do not fire on a witness that reaches A2a;
- prescribed sphere publishes the required 24-trace network (Q8 criterion 2);
- prescribed sphere produces a corrected-predicate terminal `TraceIntersection` (Q8 criterion 3, as clarified by P0.3);
- two-ring gains no contact terminus; torus remains zero-trace; excluded fan remains non-creditable.

Because S1 had no live site-B example and the sphere was masked by N1, the immutable package should first run an attempt-free **`M3-CP4c-0b-DG`** containing only these newly authored CP4c-0b identities. If DG is green, the **same immutable package** advances to the full `346 + n` artifact-only acceptance TB. If DG is red, return to Review/CB according to the diagnostic-gate rules; do not spend an acceptance attempt on a known-red new seam.

## 6. Falsifiable predictions for the next package

1. **Reached accepted contact behavior:** two-ring still has no site-B contact/`terminalContact`; its trace segment content and node count remain unchanged at 9. Its site-A event kind changes exactly once from overloaded `TraceIntersection` to `SingularityPortJunction`. Torus remains 0 traces / 0 nodes / 0 events. The fan remains excluded.
2. **Predecessor gate:** the predecessor 346 identity set passes after only the explicitly authorized site-A contract re-authoring above. Any unrelated predecessor expectation edit is a stop.
3. **Sphere termination:** prescribed sphere publishes a 24-trace network instead of N1 rejection; Q8 criteria 2 and 3 pass on corrected contact semantics.
4. **Measured runaway population:** in the frozen 48-port diagnostic superset, the prior 42 singularity-terminating traces remain singularity-terminating and only the 6 circulating traces acquire contact termini. A different split returns to Review.
5. **Contact geometry:** the six previously circulating traces encounter proper crossings within the first lap; the frozen measurement predicts the first available crossing at own step 0. Endpoint-touch and collinear-overlap incidence remains zero on the sphere. A required widening of the predicate is not authorized.
6. **Guards:** N1, N2 and N4 fire on no witness that reaches A2a. A firing is semantic RED; no allowance/bit/step bound may be widened in response.
7. **Priority:** no production-reachable non-default priority and no seniority fallback exists. A material `ArcLengthFiltered` inconclusive rate routes to Review rather than widening the computed bound; exact/inconclusive ties terminate mutually as frozen.
8. **Terminal exhaustivity:** every completed trace has exactly one terminal kind. No legitimate singularity/barrier terminus is erased by event publication.

## 7. Checks that N1 has been masking

Once S5 terminates the circulating sphere traces before N1, the next package exposes work that current accepted runtime cannot reach. The DG/TB must therefore treat failures there as newly revealed evidence rather than immediately attributing them to S5:

- final event publication and checked candidate/event-incidence validation on a sphere network;
- `terminalContact` exact-locus ownership and terminal-kind exhaustivity;
- corrected site-B `TraceIntersection` plus Q8 criterion 3 non-vacuity;
- Q8 criterion 2's 24-trace published-network requirement;
- grazing `edgeTransitExit` support on an actually published sphere network;
- downstream semantic digest/order invariance under the new event vocabulary;
- N1/N2/N4 incidence after contact is structurally available;
- tamper negatives that require an actually produced terminal trace intersection.

A failure in one of these newly reached surfaces is not permission to change an unrelated expectation, tolerance, guard threshold, or priority rule. It becomes review evidence at its first typed seam.

## 8. Candidate and accounting disposition

`M3-CP4c0b-P03-CAND-01` remains **ACTIVE / PRODUCT SEMANTICS / PRE-EXISTING**. S1 has now discharged its re-proof-risk routing role but D1-D6 are not resolved until S2-S6 land and CP4c-0b's full artifact-only TB is green. `M3-CP4c0-TB-R8-CAND-01` remains transferred to CP4c-0b and is resolved only by the green no-guard prediction.

No new regression or candidate is created by this evidence review. Stable accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**, M3 packages **52**.

## 9. Exact successor

**`M3-CP4c-0b-CB1-S2-S6` — Code + Build only.** Implement the frozen S2-S6 correction atomically, compile/package with GMP on one semantic SHA, execute no Directional runtime, then hand the immutable package to the new-contract-only DG before any full acceptance TB.
