# M3-CP4c-3-TB20 Artifact-Only Test + Benchmark Plan

## Validation identity

- Phase: `M3-CP4c-3-TB20`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence commit to validate: **`c5d3c65936e14e1c3e2c8afcffbc4236f37aa131`**
- Compile run/job: **`33805683152 / 100815534364`**
- Immutable compile result artifact: **`9912976409`**
- Artifact ZIP SHA-256: **`b4cbcbf5304ff94bd815790264ac360fa1275f23b3af2080cffda381a698a851`**
- Compile log artifact: `9912977164`, SHA-256 `583621ab73e508fccafefddca3351f5ac1a3681761e33e4468800f50242287ff`
- Packaged source archive SHA-256: `cec7db850646ffc4c2de0ed1515afc42d544f989ec83ca20055c30accd9929d3`
- Planned platform: the standard Linux artifact-only GitHub Actions execution plane used by TB19.

## Validation objective

TB20 answers the one unresolved CB22 question without changing product behavior: does the mechanical
`UncutFaceComponentOrbitSeedNotUnique` component have **no seeds** or **multiple seeds**?

It also proves that diagnostic retention did not move the previously accepted boundary or alter carried failure
surfaces.

## Frozen gate

- accepted prefix: selector 365, 365 identities, SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- prior runtime selector: selector 384, 384 identities, SHA-256 `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564`;
- TB20 selector: `Architecture_M3_CP4c3_Required_Green_Selector_385.txt`,
  **388 identities**, SHA-256 **`164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca`**;
- selector 384 must be an exact byte prefix of selector 385;
- identities 385–388 are the four CB22 diagnostic witnesses only.

A zero-selected filter, selector mismatch, source/artifact mismatch, package mutation, or missing evidence is an
**orchestration failure**, never a semantic pass.

## Preconditions and artifact integrity

Before runtime:

1. Download artifact `9912976409` and verify ZIP SHA-256 exactly `b4cbcbf5304ff94bd815790264ac360fa1275f23b3af2080cffda381a698a851`.
2. Verify packaged `metadata/source-commit.txt` is exactly `c5d3c65936e14e1c3e2c8afcffbc4236f37aa131`.
3. Verify build and preflight exit codes are zero, final source-status evidence is clean, and
   `metadata/command-boundary.txt` records `exactArithmeticBackend=GMP` and CB-only compile provenance.
4. Verify every internal `SHA256SUMS` entry and packaged mode/executable expectations without repairing anything.
5. Verify selector hashes/counts and the 384→385 exact-prefix relation.
6. Record a complete pre-runtime package byte+mode census.

No configure, compile, relink, package repair, mode repair, generated test discovery, source mutation, test
mutation, fixture mutation, selector mutation, or benchmark mutation is permitted.

## Ordered execution plan

### 1. Execute the complete selector

Use the frozen artifact-only TB runner contract from TB19 unchanged except for the exact evidence source/artifact
and selector above.

Execute **all 388 identities in selector order**, one exact GoogleTest identity per fresh process. Require exactly
one selected test per process. Preserve for every ordinal:

- identity;
- process exit/pass/red state;
- exact stdout/stderr log;
- log SHA-256;
- terminal typed error/details when red.

Do not rerun a completed identity to seek a different semantic outcome.

### 2. Accepted-prefix discriminator

Ordinals **1–365 must remain 365/365 PASS**. Any accepted-prefix red is a gating regression.

### 3. Load-bearing frontier discriminator

Ordinal **366** must still terminate at `UncutFaceComponentOrbitSeedNotUnique`. Movement to another typed terminal
surface falsifies CB22's `BV7` observational-only assumption and must be reported as semantic evidence, not hidden.

For ordinal 366 retain the complete new decision evidence:

- `component`;
- `seedCount`;
- `seedState ∈ {None, Multiple}`;
- source-face locus kind;
- component face count;
- bounded face membership and truncation;
- bounded boundary-edge rows and truncation;
- every boundary row's barrier class, labeled-side/owner state, contributed seed or exact skip reason, including
  `edgeOrbitEvidence` non-unique;
- matching component census row.

The value of `seedState` is the primary TB20 discriminator. Do not infer or pre-author its expected branch.

### 4. Component-census and projection witnesses

Ordinals **385–388 must pass** and demonstrate that:

- production failure evidence retains decision state;
- pipeline projection preserves decision + boundary evidence;
- fragment-owner evidence projects the component census including `None` and `Multiple`;
- an unrelated `InvalidSourceBinding` projection remains byte-identical when no uncut-seed diagnostics exist.

### 5. Carried surfaces

Report ordinals **367/371/372** as co-reachers and **368/369/370/374** under their existing owners. Their terminal
typed surfaces/details must remain unchanged from TB19 except for additive CB22 diagnostics on the component-seed
surface. Do not decouple 371/372 in TB20.

### 6. Package immutability and ledger closure

After all identities:

- record a complete post-runtime package byte+mode census;
- require it to be byte-for-byte/mode-for-mode identical to the pre-runtime census;
- produce one 388-row ledger and verify `PASS + RED = 388`;
- preserve result and diagnostic artifacts with exact SHA-256s.

## BV9 completion criteria

TB20 is complete only when all six discriminators are answerable from retained evidence:

1. accepted 1–365 = **365/365 PASS**;
2. ordinal 366 still reds at `UncutFaceComponentOrbitSeedNotUnique`;
3. ordinal 366 publishes explicit `seedState`, deciding zero versus multiple;
4. its component face count, bounded membership and bounded boundary rows retain every skip reason;
5. component census exists with explicit truncation flags;
6. carried 368/369/370/374 and co-reachers 367/371/372 remain under their established surfaces.

The new diagnostic identities 385–388 are gating because selector 385 appends them to the frozen gate.

## Benchmark plan

No performance benchmark is authorized or required. `directional_benchmarks` is a compiled package member only and
must not be executed unless a separately frozen TB20 criterion explicitly requires it; none does.

## Regression-accounting gate

Every observed regression/terminal change must be categorized in
`Regression_Root_Cause_Tracker.md` before TB20 closes. If the evidence only resolves
`M3-CP4c3-TB19-CAND-01` without justifying a new stable event/category, record the candidate disposition and state
why stable totals remain unchanged.

## Stop / blocker conditions

Stop and preserve evidence if artifact identity/integrity, selector identity/count/prefix, GMP provenance, package
modes, one-test-per-process selection, or pre/post census integrity fails. Such a stop is orchestration failure.

A semantic red is not an orchestration failure and must run through the full selector unless the process cannot
continue safely under the frozen artifact-only contract.

## Reruns

No unchanged deterministic semantic failure is rerun. A rerun is allowed only after a diagnosed orchestration
defect is corrected without changing the evidence source/artifact/selector semantics.

## Successor

Because CP4c-3 is currently open and TB20 is a diagnostic discriminator turn, the expected successor is
**`M3-CP4c-3-TB20-REV` — independent REVIEW + PLAN**. TB20 itself does not authorize a product correction.
