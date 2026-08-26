# M3-CP4c-0 TB-R3 Independent Review + Plan

- Turn: `M3-CP4c-0-TB-R3-REVIEW-PLAN`
- Status: **PROPOSED / PENDING INDEPENDENT REVIEW**
- Turn type: independent review and planning only
- Runtime/build authority: **none** — do not execute Directional binaries, compile, rebuild, repair, or mutate fixtures/tests/product

## Immutable evidence to adjudicate

- semantic/package source: `b135e219ee9269a73eaee32992d80c3921318011`;
- immutable package: `9589508430`, SHA-256
  `7bb4bd1a40af68ffd1e2ce06001490d61504e6ed0300505646c0abce97693015`;
- TB-R3 event/control SHA: `faf84aff4e7a64a3771e863199b82bd00425c318`;
- authoritative run/job: `32921851098 / 98036868098`;
- result artifact: `9590143527`, SHA-256
  `af4f5b28e509623af1fc93d55c4b766479362915e8517c741db4ae718d216604`;
- diagnostic log artifact: `9590143871`, SHA-256
  `ec9c29b7534053b023c8b6ba60fafb4c9d791e719caea3c37c3e2f742b08f5b7`;
- selector: 338 identities, SHA-256
  `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
- first-316 / first-328 hashes:
  `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` /
  `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`.

Runtime facts are frozen: **338/338 executed, 336/338 PASS, first red ordinal 333, second red ordinal 334 as
non-crediting observation, supplemental F3 2/2 PASS, Q8 not creditable/not run, all mutation/build flags false**.

## Review questions

### R1 — adjudicate ordinal 333 before prescribing any implementation

Determine whether `ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` can throw during candidate
mesh construction before the intended `direction_in_vertex_sector` predicate executes. In particular, verify
the ordering of `TriMesh::set_mesh` versus the candidate determinant/admissibility test and whether the
near-degenerate search family includes DCEL-invalid candidates.

If this is a test fixture/search-harness defect, freeze the smallest deterministic capable witness or safe
candidate-construction rule that reaches the product predicate and retains the original lossy-roundtrip
falsification. Do **not** weaken the expectation, catch arbitrary product exceptions, or invent a tolerance.
If source evidence instead establishes a production defect, record that evidence explicitly before any product
measure is authorized.

### R2 — adjudicate ordinal 334's branch/gauge authority

Determine the semantic meaning of a `FieldBranch` integer across independently canonicalized face frames.
Verify whether `build_face_branch_frame` owns a per-face gauge derived from canonical topology reference edges,
and whether using the same numeric branch label on every face is a valid representation of one transported
physical direction.

Freeze the correct oracle: either transport branch authority across incident faces or compare published
physical/exact direction under each face's gauge. Do not special-case the four-triangle fan and do not mutate
production merely to satisfy an oracle whose cross-face identity assumption is not source-authoritative.

### R3 — adjudicate the previous review prediction against runtime

The previous independent review predicted the P2 correction identities would all be green. TB-R3 falsified
that prediction at ordinals 333 and 334. Record which premises were wrong and why the accepted predecessor
prefix remains unaffected. Also confirm the runtime re-proof of CB3 F1/F2: ordinal 329 plus supplemental
control-character falsifier green, ordinal 330 plus supplemental tracing-locus falsifier green.

### R4 — preserve Q8 and the sphere candidate correctly

Identity 338 passed only as a non-crediting observation after ordinal 333 red. Decide what narrow diagnostic
fact this re-proves about the prior sphere rejection-code candidate without treating it as gate credit or Q8.
Q8 remains verbatim frozen, unconsumed, and must not be inferred from identity 338.

### R5 — freeze exactly one smallest successor Code + Build measure set

If R1 and R2 confirm test-side fixture/oracle defects, prescribe a **test-only corrective CB** that changes no
production semantics and packages through the standard eight targets. If either review establishes a product
defect, prescribe the smallest generalized product correction with an independently falsifiable test. In both
cases prohibit fixture-specific product branches, selector shrinkage, expectation weakening, ad-hoc tolerance
changes, and unrelated refactors.

### R6 — freeze successor TB-R4

The successor artifact-only TB must rerun the **unchanged 338 frozen selector** in exact order and fresh
processes, keep F6 continuation/non-crediting semantics after any first red, then run the two supplemental F3
falsifiers separately. Q8 becomes creditable only if package integrity is exact, **338/338** is green, and
supplemental **2/2** is green. No rebuild, repair, mutation, generated discovery, or performance benchmark is
permitted in TB.

## Stop boundary

This document authorizes only independent review/planning. Do not repair the tests, fixtures, product,
selector, or runner in the review turn. The independent review must return one adjudicated root-cause record
and one bounded successor Code + Build plan, or explicitly state that evidence is insufficient and what
additional non-mutating evidence is required.
