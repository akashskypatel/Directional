# M3 CP3 Closure Record — A2a field-aligned curve network

Date: 2026-08-21 UTC
Status: **CP3a CLOSED / ACCEPTED at 298/298. CP3b CLOSED / ACCEPTED at 304/304.**

This is the consolidated record for the two halves of A2a. It replaces the retired per-turn CP3a/CP3b
census, plan, build, diagnostic, and test reports. Exact per-turn runtime evidence remains newest-first
in `CHANGELOG.md`; regression adjudication remains in `Regression_Root_Cause_Tracker.md`.

## 1. Closure verification

Both claims were independently verified at closure from source and CI evidence rather than from the
closing reports. What was checked, and what it showed:

| Check | Result |
|---|---|
| Both semantic source SHAs exist as commits on the working branch | PASS |
| Both acceptance runs/jobs exist, `conclusion=success` | PASS |
| Job step lists contain no configure/compile/rebuild step | PASS — artifact-only confirmed structurally, not just by report assertion |
| Trigger SHA on each run matches the report's declared event SHA | PASS |
| CP3b result/log artifact SHA-256 digests match the report | PASS — `c88f8505…` and `18a5cfb0…` both matched exactly |
| The six CP3a and six CP3b identity names exist in source, exactly as frozen | PASS — 12 of 12 |
| `tests/FieldTransportAtlasTests.cpp`, `tests/support/`, `RemeshPipeline.cpp` frozen across CP3a corrective work and all of CP3b | PASS |
| Gate arithmetic 292 + 6 = 298 and 298 + 6 = 304 | PASS |

**Both closure claims are VERIFIED.**

## 2. Accepted immutable authority

| | CP3a | CP3b |
|---|---|---|
| Semantic source | `558a35c67919d54899c53de11dc9c69b6dfc9519` | `611b3f8f3926792baee9d1078d6677d22006a6c4` |
| Immutable package | `9435408599` | `9456073195` |
| Package ZIP SHA-256 | `8d31055edb7fbdbcaed1ad168dc9e1b9e2493d577429d88989589715f6009c94` | `6126acc44121ae6ca05f8b01f075bd26ce72e4f08851c80d09209c2a225a3c31` |
| Acceptance run / job | `32485441510 / 96780835699` | `32515222447 / 96875297990` |
| Result / log artifact | `9447743880 / 9447744442` | `9458599611 / 9458599992` |
| Own selector (6 ids) | `fa9bab1118b80f4727fb1ca7361b2967061d95d8a9e7de667d3648599e3b227b` | `4e9bc4a9697ab86f13a85effccbf20eb3c4debdd11fa4920c4b3213479b0ba8d` |
| Combined selector | 298 at `44dede9235fb53b486e351c02f87d4f8d5044e50ec77df6d7befbf072dfb5a25` | 304 at `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666` |
| Gate | **298/298** | **304/304** |
| Acceptance attempts | **1 of 3** consumed, green | **1 of 3** consumed, green |
| Diagnostic gates | **2 of 2** used (red 2/6, then green 6/6) | none allocated, none used |

Both gates recorded zero failures, `generatedDiscovery=false`, and byte-identical package/materialized-source
postflight.

## 3. What each half delivered

**CP3a — branch-consistent combinatorial tracing into candidate segments.** Traversal *consumes*
accepted CP2b branch topology and never re-derives frames, gauge, or interval classification. Each
candidate trace seeds from a typed port attachment's checked start face and starting branch; each
per-face step selects its outgoing interval combinatorially from the face pairing; each adjacency
crossing updates branch identity only through atlas-owned typed transport; mandatory barriers are
recognized before crossing and terminate the segment.

**CP3b — typed first-contact / intersection / termination event graph.** Events carry typed kinds
(`SingularityPortOrigin`, `FirstContact`, `TraceIntersection`, `MandatoryBarrierTermination`) with
typed incidence roles. Crossings become graph nodes at declaration time. An independent test-only
composition oracle validates the graph without calling the production validator.

**Neither claimed:** global topology selection, region emission, disc proof, M4 scheduling, or repair
of any accepted upstream product.

## 4. The CP3a arc — one red diagnostic, one corrective build, accepted first try

CP3a's first package `9432965083` was runtime-free; its attempt-free diagnostic came back **red 2/6**.
Independent review classified the four reds into two causes and authorized corrective measures J1–J6.
The corrected package went green **6/6** on the second and final diagnostic (`32463985548 / 96716645034`),
then accepted at 298/298 on acceptance attempt 1. The diagnostic-gate mechanism did exactly what it was
added to do: it bought two rounds of semantic evidence for zero acceptance attempts.

Two findings drove the correction, and both are worth keeping:

**The one-ring witness was topologically incapable of the contract it was asked to prove.** CP3a's plan
directed reuse of the accepted CP2b skew-fan witness on the reasoning that it was already proven
non-degenerate through a green gate. That reasoning was wrong, and the review that produced it was mine.
In a one-ring fan every edge opposite the singular vertex is a boundary edge, so multi-face traversal
cannot occur on that mesh at all — the non-vacuity requirement was unsatisfiable by construction. Being
green in a *previous* checkpoint's gate says the witness was adequate for *that* contract, not this one.
The fix was a genuine two-ring skew disc (11 vertices, 15 faces) whose singular-fan opposite carriers are
interior, and — critically — a runtime `ASSERT` in the fixture that *every* singular-fan opposite carrier
is interior, so the same mistake cannot be made silently again.

**One digest was carrying two semantic domains.** The network's semantic digest folded in the full
`field_transport_atlas_hash`, which is gauge-dependent. That made a *semantic* identity vary under a
consistent per-face Z4 relabel of the same physical field. The fix split the two roles: the digest now
consumes `branch_topology().semantic_digest()` (gauge-invariant), while the full atlas hash is retained
separately for binding/provenance verification. The accepted negative asserts both halves explicitly —
that the branch-topology digest is *equal* across a gauge relabel while the raw atlas hash *differs*.

## 5. The CP3b arc — accepted first try, no diagnostic needed

CP3b needed no diagnostic gate and consumed one acceptance attempt. Its only pre-package friction was a
compile-only defect (`std::vector::resize` on an intentionally non-default-constructible element type,
repaired to iterator `erase`) and a control-plane glob collision. Both are resolved compile-only /
orchestration and non-stable.

CP3b carried the CP3a fixture lesson forward without being told to: every one of its six identities
establishes that the thing it is about to assert on actually exists — a non-null event of the required
kind, at least two distinct incident traces, more than two events before reversing them — before
asserting any property of it. This is the first M3 checkpoint authored with non-vacuity guards built in
from the start rather than added after a red gate.

## 6. Carried debt — two plan obligations have no owning identity

The frozen six-identity CP3b selector is **narrower than plan section 4A.2's six-item obligation list**.
Everything the six identities assert is real and non-vacuous, and the gate is legitimately green. But two
named obligations were never assigned an identity, so nothing proves them:

1. **Rotation-system / face-walk consistency** (section 4A.2 item 5). The independent oracle checks five
   of the six named sweep properties — earliest declared contact, no undeclared interior crossing,
   exactly one terminal owner per trace, exactly-once port consumption, and terminal-kind agreement with
   barrier presence. It performs **no** rotation-system or face-walk check. Order-invariance is covered
   by a sibling identity.
2. **Crossing tamper** (section 4A.2 item 6). `RejectsContactCrossingEventOrIncidenceTamper` tampers a
   missing contact event and an incidence role. No case tampers a `TraceIntersection` crossing.

Neither is grounds to reopen an accepted green gate. Both transfer to CP4, which is the M3 exit gate and
must prove the section 2 criteria anyway — criterion 5 (structural cleanliness) and criterion 9
(independent/tamper evidence) are the criteria that own them. They are listed in the CP4 task list and in
`TODO.md` so they cannot be lost.

The general point is already in `LESSONS.md` section 6: a plan's prose obligation list and its frozen
selector are two different artifacts, and only the second one is enforced. Reconcile them item-by-item
before freezing, not after.

## 7. Cost and accounting

- CP3a: 2 packages (`9432965083`, `9435408599`), 2 diagnostic gates, 1 acceptance attempt.
- CP3b: 1 package (`9456073195`), 0 diagnostic gates, 1 acceptance attempt.
- Cumulative M3 packages: **21**, reported only — the per-checkpoint attempt regime gates on attempts,
  not on package count.
- Stable regression accounting is unchanged at **41 events / 14 categories / 27 recurrences**. Every
  CP3a and CP3b candidate (`M3-CP3a-DG-CAND-01/02`, `M3-CP3a-TB-CAND-01..04`, `M3-CP3b-CB-CAND-01/02`,
  `M3-CP3b-TB-CAND-01..04`) is resolved and non-stable; none is a product regression.
- Produced-witness debt is unchanged at **5** (3 → M4 via `G4-B002`, 2 → M5 via `G4-B003`).

Eight of the twelve resolved candidates across these two checkpoints were **orchestration/transport**
failures, not semantic ones — malformed YAML, permission ceilings, base64/gzip corruption, changed-path
guards missing untracked files. They consumed no acceptance attempts and produced no runtime, but they
did consume real turns. That ratio is itself the signal: at this point the control plane is a larger
source of lost turns than the mathematics is.

## 8. Trajectory

**A2a is complete and accepted.** A1 transport authority (CP1) plus branch/interval/port-attachment
authority (CP2b) plus branch-consistent candidate traversal (CP3a) plus typed event incidence and
composition validation (CP3b) together satisfy the `DESIGN.md` A2a requirement. No checkpoint
implemented M4+ work and no checkpoint repaired an accepted upstream product.

**A2b remains, and it is CP4's** — topology-plan derivation, plus the cumulative M3 exit gate. The CP4
decomposition and its four sub-checkpoints are in
`Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md` section 4A.3.
