# FG01 — direct periodic-owner face-gauge factory contract (2026-10-23)

**Turn:** `M6-CP3-DEFN-FG01-RP01-PERIODIC-FACE-GAUGE-FACTORY-CONTRACT`. **Disposition:** definition-only, contract-consistent correction selected for independent Review. **No Code + Build or Test + Benchmark is authorized by this record.** Next: `M6-CP3-DEFN-FG01-RP01-PERIODIC-FACE-GAUGE-FACTORY-CONTRACT-REV`.

## Authority and six-case evidence

- RA-145 independently classified TB31 as **472/497 PASS, 25 inherited RED, zero INVALID**, a candidate only. Immutable TB31 result artifact `12506242253` from run `39959505758` has outer SHA-256 `97828fac57a63b5d8ca85ef0e5fd35fb7d5ed71c2b2579cd463bacc20d5e947b`; its 1,000 manifest entries and 497 raw logs were previously independently checked and were checked again for this definition.
- Selector identities `220`, `221`, `296`, `302`, `304`, `439` (TB31 ledger rows `262`, `263`, `338`, `344`, `346`, `481`) all terminate at fixture construction, **before each named rejection assertion**, with `InvalidSourceAuthority` (`code=0`), `sourceAuthoritySite=face-gauge-missing`, `edge=-1`, `event=-1`, `cell=none`, `region=none`, `periodicRelation=none`. This does not prove the six intended downstream predicates wrong or right.
- `tests/SurfaceCellTransitionQuotientTests.cpp` `direct_periodic_owner_fixture()` constructs a two-face square (triangles `0,1,2` and `0,2,3`) in one region and makes two synthetic `PeriodicCut` owners. It independently constructs a `FieldTransportAtlas`, then calls `SurfacePhaseFrontProduct::make()` **without the optional `sourceFaceBranchRotations` argument**, which therefore remains empty.
- `src/geometry/SurfaceCellTracing.cpp` checked factory rejects empty face gauge when any `periodicHolonomies` or `isolationSeamTransportCertificates` exist, and pins a supplied per-face Z4 gauge on shared, same-region non-hard edges against reciprocal `FieldTransportAtlas::transition_value()`; it checks shape, range, consistency and connected pin domains before periodic ownership. The production A4 caller passes `state.faceBranchRotation` already. This is a **fixture-precondition defect at the six observed first failures**, not demonstrated evidence for weakening production admission.

## Frozen contract and decision

1. **Single writer:** production A4 owns the face-gauge vector, with A3 atlas providing independently authenticated per-edge transport; A6 checked factory consumes this immutable vector. A direct synthetic fixture must supply a valid producer-equivalent input and cannot bypass that consumption contract.
2. **Required vector:** one integer in `[0,3]` per source-face row, mapping through the *typed face IDs* (never unordered container position). For the two-face witness, pick one local representative `g[face(0,1,2)] = 0`, then derive `g[face(0,2,3)] = compose(A3.forward(0,2), g[first])`; verify A3 reverse equals the inverse and that the typed internal edge connects same-region non-hard faces. This is a *relational gauge representative*, not a claimed absolute geometric pin. The uniform per-region Z4 shift remains gauge-equivalent (RA-45); RA-44's withdrawn absolute pin must not be restored.
3. **Selected option A:** in a **separately reviewed, authorized Code + Build** turn, correct only the shared fixture's face-gauge construction and explicit `SurfacePhaseFrontProduct::make()` input. Build it from the real atlas and topology, not hardcoded `{0,0}`, selected row numbers detached from typed faces, hash matching, bypass flags or test-expectation edits. Preserve all six tests' original tampering and independent downstream assertions. Reuse existing helpers and types; avoid a duplicate production path.
4. **Rejected option B:** allow absent gauge when periodic relations are present. This violates frozen mandatory A6 consumption and could admit unauthenticated gauge/periodic ownership. **Rejected option C:** substitute zero gauges, skip the reciprocal/connected A3 pin, or recast a source-row equality as evidence. This can be accidentally vacuous and is not a producer-equivalent witness.
5. These two synthetic periodic relations live in a topological disk. **Their later admissibility is not yet established** by the first-failure evidence. The fixture can serve a *bounded periodic-owner factory-unit* test only if the checked factory admits its remaining topology and ownership constraints; it cannot substitute for produced torus/periodic holonomy or the representative direct-production gate.

## Falsifiable CB/TB gates for independent Review to scope

| Witness / mutation | Required observation or stop condition |
|---|---|
| Baseline two-face direct fixture | Product construction succeeds through the A3 gauge checks; if it rejects another site, record the first site and return for separate review, not a new bypass. |
| Same-region interior edge `(0,2)` | Forward and inverse transitions are independently obtained from A3 and composed with the exact typed face-gauge values; no unverified manual identity assumption. |
| One-face gauge tamper (+1 modulo 4) | Deterministic `InvalidSourceAuthority` / `gauge-pin-consistency` at the shared edge before periodic-owner assertions; non-vacuous independent negative. |
| Uniform gauge shift on both faces | Remains admitted by the *relational* gauge pin (assuming all other factory preconditions); never reinstate withdrawn absolute pin. |
| Face-row and triangle-order permutation | Relabel the corresponding typed face mapping/atlas and verify identical semantic acceptance/rejection and source-edge witness, not merely the same array index. |
| Six original owner tests | Must reach their *own* intended periodic relation owner assertions without changing their predicates, expected error codes, selector identity, or frozen metadata. Any new later failure is newly observed evidence, not proof of completion. |
| Broader independent gate | Dedicated Code + Build compile-only first, then separate immutable Test + Benchmark, then independent Review before any CP3 promotion; no local build or runtime in FG01. |

## Scope, attribution, exclusions

- Owner of the **six measured initial failures:** test-local `direct_periodic_owner_fixture` missing required gauge input. **Unresolved** whether any later periodic-owner/test-oracle issue exists; accepted 491/491 CP2 and 497 identity frozen selector are unchanged.
- Do not change `SurfacePhaseFrontProduct`'s mandatory gauge admission, the A3 transport/reciprocity model, periodic relation representations, five other failure groups, or product runtime for this definition. No source/tests/fixtures/workflows/harness/selector modifications and no binaries executed.
- No stable regression event is created by this definition. Stable 66 events / 17 categories / 49 recurrences, debt 1; R3 403/497 rejected; TB31 472/497 candidate only, RP-01 open, RP-02 unreached, Gate C suspended.
- **Independent Review decision required:** accept fixture-only correction with the gates above or reject it upon a reproduced semantic conflict; only Review can issue a bounded CB authorization. Do not automatically start CB or other owner turns.
