# M6-CP3 R3 — Decisions A, B, C: independent Review verdict

**Type:** runtime-free independent producer Design Review resolving the `M6-CP3-CB1-ENTRY-R3` A/B/C block.
**Verdicts:** **A → factory-bound atlas re-derivation (option A2, minimal form). A1 rejected.**
**B → CB may close on authoring + compile, with conditions. C → yes: separately authorized, separately counted,
diagnostic weight only.** Frozen as **RA-40**. No runtime credit; all RA-34.3 / RA-36.4-.6 / RA-38 / RA-39 gates
stand.

## Decision A — who attests A3 nonrail step values?

### Verdict: A2 in its minimal form. A1 is rejected as insufficient.

**1. The square cannot close this hole, structurally.** A balanced `+1 mod 4` on the first A3 step of *both*
paths leaves `χ_next ∘ φ_A == φ_B ∘ χ_prev` satisfied. That is not a defect in the square — a consistency
relation is invariant under a gauge shift applied to both sides. No amount of consistency checking can
substitute for authenticating the values, which is the same structural fact recorded for `Z4` at
`M5-CP3-DEFN-R1` (composition order is numerically inert; only values and signs are testable).

**2. A1 leaves `make` accepting manufactured certificates.** `make`'s signature
(`src/geometry/SurfaceCellTracing.cpp:7969-7982`) takes `hardRailFieldTransitions` and
`hardRailRouteCertificates` as **data**, with no atlas and therefore no means of authentication. Under A1, any
test or consumer that constructs or rebuilds a certificate obtains a passing A4 product. That is the
self-authorizing-oracle family this project has repeatedly been bitten by — the mechanism-versus-produced
boundary of M5 frozen §8.1, and the circular-oracle guard recorded at `M5-CP3-TB1-R15-R1-REV`. A1 would have to
impose that prohibition by decree anyway.

**3. A2 needs no new attestation schema — the authority is already reachable.** This is the decisive point.

- `SurfaceCellTracingOptions::fieldTransportAtlas` is already `const authority::FieldTransportAtlas *`
  (`include/directional/geometry/SurfaceCellTracing.h:2186`).
- A4's junction authoring already derives each value through
  `authoritativeOptions.fieldTransportAtlas->transition_value`.
- `FieldTransportAtlas::matches_source_faces` already exists
  (`include/directional/authority/FieldTransportAtlas.h:893`) and already requires exact source matrix,
  authority and vertex count.

The **only** gap is that `SurfacePhaseFrontBuildState` does not carry the atlas and `make`'s signature lacks it.
So A2-minimal is: bind the already-available atlas at the factory boundary, require `matches_source_faces`
against the same source, and have `make` **re-derive each value from `transition_value` and require exact
equality**. Checking each value individually against ground truth rejects balanced tampering, which pairwise
consistency cannot.

This is the **fourth** occurrence of one pattern in this milestone — RA-34.3 (τ retained before the
nontraversable marking), RA-35 (per-wedge bindings retained before the sort/unique collapse), RA-38 (the star is
traversed; only the carrier cut was missing), and now the atlas reachable in options but not bound at the
factory boundary. The cure is the same every time: **reach or publish what the producer already holds.**

**4. The hole is wider than the question stated.** Decision A asks about *nonrail* step values, but `make` also
accepts `hardRailFieldTransitions` — the per-carrier χ values — as unauthenticated data, with the same balanced
tampering exposure. One atlas binding authenticates **both** χ and φ. Scoping the fix to φ alone would leave the
same defect one field over.

**5. The migration is a feature, not only a cost.** Eleven of the twelve public factory invocations are tests
(production at `:12195`; tests across three files). A test that cannot supply a source-bound atlas **should not
be manufacturing route certificates for `make`** — so the migration pressure enforces exactly the discipline A1
would have had to add as a prohibition.

### Binding conditions

- `make` requires an atlas bound by `matches_source_faces` to the same source matrix, authority and vertex
  count. A mismatched atlas is a typed fail-closed error, never a permissive path.
- `make` re-derives **every** A3-sourced value it is handed — each nonrail φ and each carrier χ — via
  `transition_value`, and requires exact equality including reverse orientation and reciprocity.
- **Absent atlas → typed fail-closed.** There is no "unauthenticated but accepted" mode.
- A global per-face branch-gauge difference across cuts or holonomy may **not** substitute for true A3 values
  (already withdrawn at RA-31a).
- All twelve call sites migrate explicitly and exhaustively; no default-null convenience overload.
- RA-39 endpoint-local single-terminal-carrier χ is unchanged. This is **not** a licence to reintroduce RA-37a
  fan detours.

## Decision B — CB versus TB evidence sequencing

### Verdict: option 1. R3 CB may close on complete authoring plus exact eight-target compile/package evidence.

The binding plan forbids running Directional binaries in CB and places the **497** execution in a distinct TB.
A CB closure gate that simultaneously demands "actually produced, nonvacuous D1/D2/D3/D5 and A6/A7 witness
outcomes" and "recovery of 47 prior accepted regressions" is therefore **unsatisfiable** — no compiler can supply
it. This is the identical self-conflicting precondition resolved at `M6-CP3-CB1-ENTRY-R2` precondition 2, and the
same resolution applies: author and verify **statically**; prove existence at the gate that can run.

### Binding conditions

- CB's closeout claims **no** produced positive, and says so explicitly.
- Nonvacuity must be enforced **in compiled assertions**, not asserted in prose.
- The authorized TB successor is **named before** root `STATUS` becomes `COMPLETE`.
- The 497 gate, every organic D1/D2/D3/D5 and A6/A7 witness, the odd-τ witness, and the 47 accepted→RED
  recoveries remain **TB** obligations, not CB claims.
- Each TB RED is investigated individually and returned to a **new** authorized repair turn; no blanket
  reclassification.
- Tool or time exhaustion is **not** `BLOCKED`. `BLOCKED` is reserved for a genuine authority or evidence gap.

## Decision C — the four excluded source-defined tests

### Verdict: yes — a separately authorized, separately counted artifact-only focused diagnostic run, carrying diagnostic weight only.

The four tests are `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`,
`M6CP3.HardRailPublishedTauRequiresIncidentSourceFaces`,
`M6CP3.A6SeamDirectionRejectsForeignFaceAndWedgeBindings`, and
`M6CP3.A7TypedWedgeSheetMismatchRejectsCachedMembership`.

Both alternatives are unacceptable. **Folding them into 497** mutates a frozen, single-owned gate — prohibited,
and it would also silently imply they had run. **Leaving them unrun** makes four authored contract tests
zero-evidence, which is "structural presence is not behavioural coverage" (`LESSONS.md` 171) — the same error as
an authored-but-unexercised witness.

So: run them in a **separate** artifact-only focused diagnostic turn, **counted separately** from 497, with
results carrying **diagnostic weight only — no acceptance credit** — until a Review folds them into a successor
gate under the established pre-commitment discipline (declare the successor gate's exact composition and census
**before** the publishing turn builds it, as has now held for four consecutive selector publications).

## Non-claims

This decision settles trust ownership, evidence sequencing and the status of four excluded tests. It establishes
**no** runtime result. Existence of a produced multi-carrier paired HardRail front, the organic D1/D2/D3/D5 and
A6/A7 witnesses, the odd-τ witness, and the 47 accepted→RED recoveries all remain unproven and stop-gated. The
stable ledger stays **64 / 17 / 47**, debt **1**.

## Verification limits

Re-read from source: `make`'s full signature and its absence of an atlas parameter; the options atlas pointer at
`SurfaceCellTracing.h:2186`; `matches_source_faces` at `FieldTransportAtlas.h:893`. Accepted as reported: the
balanced-tamper algebra, the twelve call-site census, the eight-target GREEN compile receipts, and the frozen
497 composition.
