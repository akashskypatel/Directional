# M3-CP4c-3-CB48 Code + Build Plan

**Status:** FROZEN BY `M3-CP4c-3-DEFN-R8` / NOT YET EXECUTED
**Canonical turn:** Code + Build
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Definition authority:** `M3_CP4c_Frozen_Definitions.md` Part XII (R8.1–R8.7)
**Current semantic runtime authority:** promoted TB42 / package107 / selector409 **398 PASS / 11 RED**, accepted **365/365**
**Runtime boundary:** compile only; execute no Directional binary, test, benchmark, discovery/list/help/version command, or custom fixture

## Objective

Correct the **evidence-domain contract** for protected ordinals 390/393/406/407 without changing the
uncut-component partition, region construction, ownership, fragment ownership, or any accepted contract.

TB42 proved the uncut-component census is healthy but disjoint from the terminal failing region: 226 unlabelled
faces in 9 components, 9 owner-consistency rows, while the failing region has 10 source faces and 0 in the
partition. The old stage-name branch was a proxy for domain membership. CB48 replaces that proxy with a typed
domain predicate, keeps each census-owned oracle live against its producer, and adds the exact region/fragment
owner-orbit relation needed by a `RegionCertification` failure.

## Assumptions frozen by Part XII

1. The plan uncut-component domain remains `EmptyFragmentOrbits` / the unlabelled-face partition built with
   `mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`.
2. Distinct plan/certifier partitions are lawful; cross-domain substitution is the defect. Do not unify them.
3. Part XI/Part XI-A and the CB46 content-anchor binding remain authoritative and untouched.
4. `RegionSourceFaceOwningFragmentMissing` at 366/367 is not corrected in this turn.
5. The observed failing face has 3 local fragments / 3 owners / expected 3 / deficit 0, so EE1 must publish exact
   owner-orbit membership, not another count-only diagnostic.

## EE0 — typed domain predicate

Introduce the smallest typed representation needed to classify the authoritative failure subject against the
uncut-component domain:

`Inside | Outside | Partial | Unresolved`.

For region failures the subject is the complete current `region.sourceFaces` set. The predicate is derived from
membership in the already-built unlabelled-face partition. `regionFrontierFailureStage` remains chronology only
and must not enable/disable a census assertion.

**Verify statically:** no `stage ==/!= "UncutComponent"` controls the protected census oracle after the patch.

## EE1 — exact region/fragment owner relation

At `RegionSourceFaceOwningFragmentMissing`, preserve existing `region`, `sourceFace` and
`regionOwningFragmentOrbit`. Additionally publish:

- complete deterministic owner-orbit IDs currently present for the failing source face;
- exact count;
- `regionOwningFragmentOrbitPresent`.

Project all fields through `RemeshDiagnostics` and render them in the existing CP4c failure-locus path. This is
observation only. Do not mutate `fragmentOrbits`, `fragmentCorners`, ownership, the region, or the return code.

**Verify statically:** the failure still returns `RegionSourceFaceOwningFragmentMissing` at the same source site.

## EE2 — preserve unrelated diagnostics

The new domain/orbit fields must be default-absent on unrelated errors. Rendering must not append default-valued
fields to unrelated loci. Existing byte-identical unrelated-error witnesses must remain unchanged.

## EE3 — producer-owned census predicates

Factor the four protected invariants into deterministic test predicates/helpers that consume the census producer's
own published rows. The terminal failure's domain relation is checked separately. Remove the helper shape that
requires `regionFrontierComponentCount > 0` for every later stage.

Every helper must have a real-data positive and a deliberately corrupted same-domain negative in its owning
identity. The negative is test-local and does not add a selector identity.

## EE4 — ordinal-specific obligations

- **390:** validate real uncut-component boundary/seed attribution and completeness; separately assert terminal
  `Outside` plus EE1 evidence on the current mechanical failure.
- **393:** validate distinct-source-face owner/projection coverage from a real `P_U` component; terminal `Outside`
  does not waive the producer check.
- **406:** validate both partition identities and the typed subject/domain relation; equality across distinct
  domains is never required. Current mechanical region must classify `Outside`.
- **407:** validate crossed faces and component IDs in both named partitions from an actual `P_U` census subject,
  retaining typed absent-membership reasons; do not reinterpret the outside terminal region as a plan component.

Do not rename any test or change selector409 bytes.

## EE5 — branch receipts and non-vacuity

Each protected identity emits one deterministic receipt naming:

- census predicate executed: yes/no (must be yes);
- terminal subject relation: `Inside|Outside|Partial|Unresolved`;
- same-domain corruption rejected: yes (must be yes);
- RegionCertification evidence branch executed where applicable.

A PASS with `census predicate executed=no` is an invalid gate.

## EE6 — frozen-surface audit

Before compile, verify:

- selector409 hash remains `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- no selector file changed;
- accepted test blocks 311/312/314/315/356/357/404/408/409 are untouched;
- Part XI binding, `region_orbit`, orbit-key lookup and content anchor are untouched;
- no change to `unlabeledFaces`, component barriers, region construction, cut selection, ownership,
  `fragmentCorners`, `fragmentOrbits`, or A2a′ cellularity semantics;
- 366/367 failure control flow is unchanged.

Any violation stops CB48 before compile.

## EE7 — compile-only evidence

Use the durable compile reusable on the exact pushed CB48 source. Compile the changed owner target first, then the
standard package targets. GMP/GMPXX linkage remains mandatory. No runtime command may execute any produced
Directional binary.

Compile success is evidence only; it does not make 390/393/406/407 green and does not promote runtime authority.

## EE8 — mandatory TB43 plan

CB48 closeout authors exactly one artifact-only `M3-CP4c-3-TB43-EXEC` plan tied to the exact immutable compile
artifact. TB43 must rebuild nothing and execute selector409 exactly once per identity under the normal artifact-only
harness.

Expected if CB48 is correct and carried owners are unchanged: **402 PASS / 7 RED / 0 SKIP**, accepted **365/365**,
RED `[366,367,368,369,370,374,398]`. This expectation is a falsifier, not a synthesized result.

## Hard stop / falsification

Stop and return to review if:

- accepted 365/365 or any of 311/312/314/315/356/357/404/408/409 is threatened;
- selector409 bytes would change;
- a protected identity can pass without executing its census predicate;
- a corrupted same-domain census is accepted;
- owner-orbit membership cannot be published exactly without changing ownership semantics;
- the proposed fix requires widening/unifying a partition or altering 366/367 product behavior.

## Success criteria for CB48

1. Surgical EE0–EE6 patch only.
2. Static/frozen-surface audit passes.
3. Work-preservation patch emitted and remote source mutation is recoverable.
4. Compile-only reusable workflow succeeds on the exact pushed source with GMP/GMPXX and `runtimeExecution=false`.
5. Immutable package and logs are preserved.
6. One exact TB43 artifact-only plan is frozen; no TB43 runtime runs in CB48.
