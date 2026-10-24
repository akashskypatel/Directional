# Independent Review — the interior-endpoint repair, its encoding collapse, and the pre-registered TB (RA-60)

**Turn:** `M6-CP3-TB1-R4-REPAIR-REV` (Review only). **Disposition:** the **compile is ACCEPTED**; the **implementation is ACCEPTED as faithful to RA-59.9** on every authentication requirement, verified line by line against the bytes; the **Step 0 falsifier CLEARS**, but on this Review's derivation rather than the turn's; and **four defects plus one principal design finding are recorded**, one of which must be fixed before any re-measurement if a specific branch occurs. No source, test, selector, binary, harness, workflow or ledger change was made in this Review, and no Directional binary was executed. Ledger **66 events / 17 categories / 49 recurrences**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen selector **497** — unchanged. No promotion, no stable event, no new recurrence, no 497 run, no gate credit. **No runtime outcome has been observed and none is claimed** (LESSON 160: a compile is not a restoration).

## RA-60.1 — Compile accepted; the turn boundary held

Eight-target GMP/GMPXX compile **GREEN**: run [38720128740](https://github.com/akashskypatel/Directional/actions/runs/38720128740) on exact semantic `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`, result artifact `11964478813` (outer SHA-256 `0e1e87a48ef090588c8675bd87bc8c7560a1ade5dbe44cac391c78e0cbe21ae5`), log artifact `11964676618`. 28/28 packaged checksums, eight target names, preflight/build exits `0/0`, `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, real `gmpxx`/`gmp` linkage, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No test binary, benchmark, artifact-only harness or 497.

Independently confirmed the change surface: exactly **two** files — `src/geometry/SurfaceCellTracing.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`. The test change is **purely additive** (zero deleted lines). `tests/SurfaceCellTransitionQuotientTests.cpp`, `tests/SurfaceCellREPackageTests.cpp`, `cmake/`, `benchmarks/` and every selector file are **untouched**. No fixture geometry was changed, which the retained plan and RA-59.12 both required.

## RA-60.2 — The implementation is faithful to the selected model, and strengthens it

Checked against each RA-59.9 requirement at the new site (`src/geometry/SurfaceCellTracing.cpp:19221-19241`):

| RA-59.9 requirement | implementation | verdict |
|---|---|---|
| typed carrier key | `find_carrier(edge)` → `oriented_carrier(*carrier, …)`; `edge` passed to the parameter check | ✔ |
| both incident source faces, **across-rail** per RA-57.5 | `firstAttachment`/`secondAttachment` are `topology_for_row(source_face_id(fromPoint.face))` / `(toPoint.face)` (`:19130-19138`); `oriented_carrier` requires the carrier record's faces to equal that pair | ✔ |
| canonical exact intrinsic parameter on the **same** carrier edge, shared by both points | `same_interior_carrier_point(fromPoint, toPoint, faces, edge)` | ✔ |
| equivalent opposite-side barycentric representatives, **no** epsilon merging | `FieldExactRational::from_double_exact`, exact `==`, no tolerance anywhere in the new helpers | ✔ |
| source component/sheet agreement | carried by the topology-region keys and tied to the published carrier record by `oriented_carrier` | ✔ |
| directed A3 transport between the two incident faces | `*oriented` carries `firstToSecond`, verified when the transition record was built (`:18963-18975`, `reverse->transport == forward->transport.inverse()`) | ✔ |

`interior_carrier_parameter` (`:61-89`) is sound by construction: it locates the edge's two corners in the published chart, requires the third barycentric to be **exactly** `0.0`, converts both weights exactly, and admits only `second ∈ (0,1)` **strictly** with `first + second == 1` exactly. Three properties follow and matter:

- **A forged terminal cannot be laundered through the interior branch.** Strict interiority excludes one-hot corners, so a point at an exact corner returns `nullopt`.
- **The parameter is canonically oriented.** It returns the weight at `edge.second()`, and the edge key is canonical, so comparing the two charts compares the weight at the *same* vertex. An along-rail parameterization would have had an orientation bug here; this does not.
- **A front ending exactly at the rail's interior junction vertex 4 is rejected, not absorbed.** At vertex 4 the weight is exactly `1`, failing `second < one`. The junction case therefore remains outside this repair, consistent with RA-41's clauses standing UNEXERCISED. This was not required and is correct.

Beyond the specification, the new branch also requires **`sharedBoundaryInterval` reciprocity** — equal `span` with cross-matched `firstOrdinal`/`secondOrdinal` — which ties the interior certificate to a published shared boundary interval rather than to any two coincident points. **Recorded as a strengthening of RA-59.9, adopted.** And no parallel certificate model was introduced: absence of a terminal is expressed through the existing `std::optional` member, not a new type.

## RA-60.3 — Every prohibited invariant verified intact

- `exact_corner` and `no-exact-terminal-corner` (`:19214-19241`): the terminal loop and the exactness predicate are **unchanged**, and the new code is reachable **only** when `!terminalVertex`. Fail-closed for any endpoint claiming terminal status.
- The closed-chain branch (`:19140-19147`, `missing-terminal-or-closed-rail-provenance`): **untouched**, so the RA-58.5 torus PASS is preserved.
- **At least one certified terminal endpoint on an open rail: preserved.** At `:8572-8576`, `!bothTerminal` requires `singleTerminalValid(firstVertex, …) || singleTerminalValid(lastVertex, …)`. If **both** endpoints are interior, both disjuncts are false and the certificate is rejected. A contact-less open rail remains impossible.
- `tests/SurfaceCellsPhase10Tests.cpp:7205` (`endpoints[0].terminalVertex.has_value()`, cited as `:7157` in RA-59.9 and shifted by this turn’s additive insertion) is **untouched** and still satisfiable: the half-terminal certificate puts the terminal at `endpoints[0]`.
- Ordinal **405**'s `endpoint-0` branch is untouched; it remains a separate A2b provenance defect.
- No `Produced` precondition was weakened anywhere.

## RA-60.4 — Step 0 CLEARS, but this Review derived it; the turn did not evidence it

The record states *"the required front-publisher falsifier was checked against the exact source before editing, as recorded in the continuation artifact."* **It states no finding and cites no anchor**, and the artifact is not in the repository. The only visible trace in the source is a **rewritten contract comment** at `:18975-18978`, where *"Publish one terminal crossing per spatial endpoint"* became *"Publish one cross-rail certificate per spatial endpoint … A field-determined front end may be inside a source carrier."* A claim of having checked is not a finding (LESSON 171), and amending the statement of a contract is not a derivation of it.

Derived here instead, from the publisher. Front extent is produced in `assign_open_front_boundary_authority` (`:12481`): runs are accumulated from **traced segment barycentrics** through `canonical_retained_edge_parameter` (`:12509-12530`), and a run is published when `lastTopology != topology` (`:12574-12579`) — i.e. **cut at source-edge topology changes, never at rail terminals**. The extent is therefore field-determined, and a front end interior to a carrier edge is a legitimate product of the publisher's contract. **The falsifier CLEARS and RA-59.9 stands.**

**The amended comment is a consequence of the RA-59.9 selection, not evidence for it.** It must never be cited as authority for the model; doing so would be circular and is an `RP-01` shape. The derivation above is the authority.

## RA-60.5 — DEFECT: the new rejection is diagnostically indistinguishable from the old one

Both the unchanged terminal loop and the new interior branch end at the **same** `reject("no-exact-terminal-corner")` (`:19241`). If the next measurement reports that predicate again, nothing in the diagnostic distinguishes *"the interior branch was never reached"* from *"the interior branch refused"* — and those have opposite consequences for the model. This is the RA-57.12 / RA-59.4 failure mode designed into the instrument before the instrument runs.

**Required fix, if and only if branch (C) of RA-60.10 occurs:** a distinct predicate string for the interior refusal — e.g. `no-interior-carrier-agreement` — emitted on the existing diagnostic-only path, after rejection has already been decided, changing no decision. It is **not** authorized pre-emptively: on the RA-60.10 prediction, branch (C) is the unlikely one, and inserting a rung on speculation is the RA-54.7 defect. This is a conditional obligation, pre-registered so that a (C) result is not misread.

## RA-60.6 — The per-certificate terminal-coverage invariant was dropped, necessarily, with no aggregate replacement

The original check at `:8572` required `forward || reverse`, where (`:8544-8553`)

```cpp
const bool forward = touches(certificate.endpoints[0].terminalCarrier.edge, contact->second.endpoints[0]) &&
                    touches(certificate.endpoints[1].terminalCarrier.edge, contact->second.endpoints[1]);
```

i.e. **each accepted certificate's two endpoint carriers had to touch both of the rail's published terminals** — a whole-rail span condition. In the measured topology `routeLength=1`, so both endpoints share carrier `(1,4)`, which touches terminal **1** but not **7**; therefore `forward == reverse == false` and the original code rejected unconditionally. The repair **had** to drop that condition for the interior case; it is not gratuitous. But nothing replaces it, per rail or in aggregate, and no downstream aggregate coverage check exists.

**Consequence, stated as a prediction and not a speculation:** in these fixtures no front crosses `(4,7)`, so **terminal 7 can never be attached by any certificate.** The repair therefore necessarily produces open rails with one published terminal left unattached. Whether A5/A6/A7 tolerate that is unknown and unmeasured; it is the most likely place for the failure to reappear downstream. Pre-registered in RA-60.10 as branch (B).

## RA-60.7 — PRINCIPAL DESIGN FINDING: the interior endpoint collapses onto the closed-chain encoding

The new interior certificate is constructed as `{firstAttachment, secondAttachment, *oriented, std::nullopt, {}}` (`:19239-19241`). The closed-chain / no-contact branch of the checked factory requires precisely that shape (`:8729-8733`):

```cpp
} else if (endpoint.terminalVertex || !endpoint.contactPaths[0].empty() ||
           !endpoint.contactPaths[1].empty() ||
           carrier.firstFace != endpoint.firstAttachment ||
           carrier.secondFace != endpoint.secondAttachment) { … reject }
```

**An interior open-rail endpoint and a closed-chain endpoint are now structurally identical** — same `terminalVertex == nullopt`, same empty `contactPaths`, same carrier-equals-attachments. The only separator is which branch of `if (contact != hardRailTerminalContacts.end())` the **rail** falls into, which is a property of the rail, not of the certificate. The inference *"no terminal vertex ⇒ closed chain"*, previously sound, is now **false**.

Severity, stated honestly: **latent, not active.** The only consumer outside this file is the structural fingerprint `hash_trace_network` (`src/pipeline/RemeshPipeline.cpp:2123-2124`), which hashes `terminalVertex.has_value() ? index : -1` — so both states alias to `-1`, but a fingerprint is not an authority and the hash carries the attachments and carrier separately. Nothing infers closed-chain-ness semantically today. It is nevertheless an `RP-01 AUTHORITY_DOMAIN_CONFLATION` shape: two distinct topologies sharing one encoding, waiting for the first consumer that reads it. **Required before anything reads it semantically:** a **positive discriminator** on the endpoint — the attested interior parameter itself, or an explicit kind tag — so that *"no terminal"* and *"interior carrier attested at parameter p"* are different states rather than the same one. Recorded, **not** authorized in a measurement rung.

## RA-60.8 — DEFECT: a comment asserts an invariant its own site does not enforce

At `:8662-8675` the new branch is introduced by *"Open-rail interior carrier: the opposite endpoint must already carry an independently checked whole-rail terminal witness."* The code at that site checks contact-path emptiness, carrier/attachment equality and interior-point agreement — **it never inspects the opposite endpoint.** The invariant is real and is enforced, but at `:8572-8576`. A reader auditing `:8662` will believe a guard exists there that does not. Fix the comment to point at the enforcing site, or move the check.

## RA-60.9 — Test coverage: the first positive witness in this family, and four untested negatives

`SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard` (`tests/SurfaceCellsPhase10Tests.cpp:7148-7191`) is **nonvacuous and significant**: its first assertion demands real production from `build_rectangular_hard_rail_phase_front()`, and it then requires the producer to witness **one terminal and one interior** endpoint. Per RA-59.8 this is the **first positive witness of the acceptance half ever authored** — subject to actually passing at runtime, which is unmeasured.

Its negative half forges a terminal vertex onto the interior endpoint and requires `InvalidSourceAuthority`. That rejection is real, but it is attributable to the **retained** `(!forward && !reverse)` condition rather than to the new predicate, so the test's name over-claims: it guards the retained span condition, not corner exactness — which does not live in the factory at all. Substance stands; the name misleads.

Four negatives on the new predicate itself are **untested**, although the code rejects all four:

1. the two paired points at **different** interior parameters (`same_interior_carrier_point`);
2. an interior endpoint with **non-empty** `contactPaths` (`:8662-8675`);
3. an interior endpoint whose carrier faces disagree with its attachments (`:8662-8675`);
4. **both** endpoints interior — the contact-less-open-rail forgery the retained plan explicitly prohibits (`:8553`).

(4) is the one that matters most and is the cheapest to author. Required in the next Code + Build that touches this area; **not** authorized inside a measurement rung.

## RA-60.10 — PRE-REGISTERED PREDICTION AND DECISION RULE for the next Test + Benchmark

Registered **before** the measurement so the result cannot be reinterpreted after the fact. The measured probes were `a2bProbeFrom=0:0x0p+0,0x1.8p-1,0x1p-2` and `a2bProbeTo=3:0x1.8p-1,0x0p+0,0x1p-2` — `0.75` and `0.25`, both exactly representable, the third weight exactly `0.0`, and `0.75 + 0.25 == 1.0` exactly in **both** charts. Therefore `interior_carrier_parameter` succeeds on both points and yields the same exact rational, `same_interior_carrier_point` returns **true**, `singleTerminalValid(terminal 1, carrier (1,4))` holds, and `:8662`'s attachment equality holds by construction of `oriented_carrier`.

**Prediction: the 38 `endpoint-1` identities clear `:19241` and A4 accepts.** The three admissible outcomes and their binding interpretations:

- **(A) `Produced`, and the network-bound consumer is reached.** The repair works and `RP-02` becomes measurable for the first time. Its positive **and** negative halves must both run before any claim about `RP-02`.
- **(B) A new first failure strictly downstream — A5/A6/A7, most likely terminal coverage.** This **does NOT falsify RA-59.9.** It confirms RA-60.6 and locates the next rung. Record it; do not chase it in the same turn (RA-54.7), and do not fold it into the hard-rail carrier.
- **(C) The same `no-exact-terminal-corner` at `:19241`.** **Ambiguous**, because of RA-60.5. A (C) result mandates the diagnostic-only fix of RA-60.5 before any re-measurement, and only the distinguished predicate can separate *branch not reached* from *interior agreement refused* — the one-ULP hazard at the RA-60.11 seam. A (C) result is **not** grounds to weaken any predicate.

A persisting RED is therefore interpretable only through this table. **"Still RED" is not evidence against the model**, and nothing in branches (B) or (C) authorizes relaxing `exact_corner`, `no-exact-terminal-corner`, the closed-chain branch, or any `Produced` precondition.

## RA-60.11 — Residual: two arithmetic régimes meet at the same endpoint

The publisher admits run endpoints through `canonical_retained_edge_parameter` with `constexpr double tolerance = 1.0e-9`, an interval test on `[−tolerance, 1 + tolerance]` and `std::clamp(parameter, 0.0, 1.0)` (`:12509-12530`), and stitches runs under `std::abs(*runEndParameter - *startParameter) > tolerance` (`:12655`). The new certificate demands **exact** rational equality and **strict** interiority. Soundness is preserved — the certificate is exact, epsilon-free and fail-closed, so no false acceptance can pass — but the pairing of a tolerant producer with an exact consumer is exactly where a one-ULP cross-chart disagreement would surface, as a refusal rather than a false accept. Recorded as a bounded residual, with its observable consequence pre-registered as RA-60.10 branch (C). No epsilon may be introduced into the certificate to close it.

## RA-60.12 — Correction: the handoff reinstated a retired stop rule

The turn's handoff section directs the next TB to run *"remaining six supplemental identities **only until first RED**."* That is the pre-RA-57 rule, retired by RA-57.8 and RA-58: an early stop is what left the breadth turn unreported, and a measurement rung must execute **all** its identities regardless of RED, taking its verdict from `executed`/`missing`/`postflight` only. **Corrected:** no first-RED stop in any measurement rung. Given the RA-60.10 prediction, a first-RED stop would also discard almost everything the run could establish.

## Obligations carried, not retired

`RP-01` (and RA-60.7 is a new instance of its shape, recorded), `RP-02` (**open**; localized by RA-59.8 and now potentially reachable for the first time), `RP-03`; the RA-58.7 A5/A6/A7 loci and `R4-OHF-02` (recorded, guards retained, **no probe**); the two RA-57.9 guards and RA-41's junction/sector clauses (frozen **UNEXERCISED**, construction recipe known per RA-59.8, **not retired**, and explicitly outside this repair per RA-60.2); ordinal **405**'s separate A2b provenance defect; the 34 Phase10 / seven DCEL / six CP3 identities; the CP2 restorations outside the 37; organic D1/D2/D3/D5 and A6/A7 witnesses; the odd-τ witness; the two `SurfaceCellTracingPhase14` identities requiring a separately packaged historical executable (`cmake/DirectionalTests.cmake:554-572`), **not** to be bundled into a measurement rung. `R4-VIN-01` applies with force: the repaired package is a **new** semantic source (`570c5173…`), so every prior measurement is a baseline, never a comparand.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | All frozen selectors untouched and matching; no selector added, changed or accepted |
| Decisive claims independently re-derived | Change surface confirmed as two files with zero test deletions; all six RA-59.9 requirements checked at the new site; every prohibited invariant checked at its own anchor; the Step 0 falsifier derived from the publisher at `:12481`/`:12509-12530`/`:12574-12579`; the closed-chain shape at `:8729-8733` compared field-by-field against the new certificate; the sole downstream `terminalVertex` consumer located |
| Non-vacuity checked | The new test demands real production before asserting; its negative half traced to the condition that actually rejects (the retained span check, not the new predicate); four negatives on the new predicate found untested |
| Prior obligations discharged / carried | RA-59.9 implemented and accepted; Step 0 cleared; all other obligations carried above; nothing retired |
| Stable accounting | 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497; no promotion, no stable event, no recurrence |
| New candidates / obligations recorded | RA-60.5 conditional diagnostic fix; RA-60.6 terminal-coverage gap; RA-60.7 encoding collapse needing a positive discriminator; RA-60.8 comment/code mismatch; RA-60.9 four untested negatives; RA-60.11 arithmetic-régime seam |
| ORIENTATION currency line | `M6-CP3-TB1-R4-REPAIR-REV`, 2026-10-15 |
| CHANGELOG | 2026-10-15 root entry; root `CHANGELOG.md` is canonical |
| LESSONS | LESSON 160 cited against the compile-green status; 171 cited against the unevidenced falsifier claim; RA-56.8, RA-57.12, RA-58.8 and RA-59.4 in force |
| Successor frozen | `M6-CP3-TB1-R4-INTERIOR-WITNESS` (artifact-only Test + Benchmark on the **new** package), governed by the RA-60.10 pre-registration |
| Turn boundary held | Review only: no source, test, selector, harness, workflow, binary, benchmark or ledger change; no Directional binary executed |
| `review_check.py boundary` | Run after document commit; result recorded with the commit |
| `STATUS` lifecycle maintained | Six fields set, `COMPLETE`, named `Successor` — replacing the `Successor: UNKNOWN` the repair turn left |
