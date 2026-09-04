# M3 CP4c-3 TB23 — Independent Review + Plan Record

Date: 2026-09-04 UTC
Turn: `M3-CP4c-3-TB23-REV`
Type: **independent REVIEW + PLAN — STATIC ONLY**
Status: **COMPLETE / ORCHESTRATION-INVALID CLASSIFICATION UPHELD / HARNESS OWNS THE DEFECT, NOT CB25 OR THE PACKAGE / CB25 STATICALLY SATISFIES ITS CONTRACT / ORCHESTRATION-CORRECTION CB FROZEN / NON-STABLE**

No Directional runtime, configure, compile, link, package, benchmark, package repair, fixture staging, or
product/test/fixture/selector mutation occurred in this turn. Measures discharged: **CC0–CC8**. Successor frozen:
exactly one — **`M3-CP4c-3-CB26`** under **CD0–CD8**, an orchestration-correction Code + Build turn.

> **Routing note — the workflow changed during this turn.** The user authorized, on 2026-09-04, that an
> orchestration failure routes to a **`CB` orchestration-correction turn** followed by a re-executing `TB`, rather
> than to `REVIEW + PLAN`. An orchestration failure produces no semantic ledger, so there is nothing for a review
> to adjudicate; under the new rule **this review turn would not have been scheduled**. Its diagnosis is retained
> because it is exactly what the correction turn needs, and the successor below is re-pointed from a combined
> re-execution to the `CB → TB` pair the new rule requires. Rule 4 is untouched: a **semantic** red still routes to
> `REVIEW + PLAN`.

**Headline.** The invalid run is not a CB25 regression and not a package regression. The reusable compile workflow
has **never** packaged a `test-data` tree — TB18 through TB22 passed because their harnesses *staged* fixtures into
the executable-relative layout, and TB23's harness omitted that step while verifying the wrong path. The reason a
harness slip became a 397-process pseudo-ledger is a **separate, product-side defect**: `test_data_root()` **fails
open**, returning a non-existent path instead of reporting that no fixture tree exists.

---

## 1. CC0 — authority and immutability

| Check | Result |
|---|---|
| Semantic source `e12396d471c0754b112a40272a7992020ff49ced` exists | **PASS** — `diag: M3-CP4c-3-CB25 certificate-face diagnostics`, 2026-09-04 02:54:02 +0000 |
| Source is an ancestor of branch HEAD | **PASS** |
| No code drift `source..HEAD` | **PASS** — static reading of the working tree is valid evidence about the package |
| Selector 397 hash `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5` | **PASS**, **397 identities** — name and count agree |
| Selector 393 is an exact prefix | **PASS**, prefix digest `ee8cc033…27644c4d` |
| Accepted 365-prefix authority | **PASS**, unchanged |
| Appended identities | **PASS** — exactly ordinals 394–397, no reordering |
| Package census pre/post | **EQUAL**, `9c7b12f4…0359a927`; extracted source census equal at `e7bec159…6d2d8654` |
| Prohibited-operation flags | **PASS** — benchmark, configure, compile, relink, discovery, package repair, mode repair and source/test/fixture/selector mutation all `false` |

The immutable package was **not modified** by the invalid attempt. Attempt 1 (`33833432331`) failed before any
Directional runtime on a control-plane permission ceiling and consumed no semantic result; its correction was
permission-only.

---

## 2. CC1 — the orchestration-invalid classification is UPHELD

The frozen plan required a known committed fixture to exist **at the exact path the packaged executable resolves**
before any Directional process ran. The harness verified fixtures in the extracted **source workspace** instead, so
its `preflight_completed=true` is not proof of the frozen requirement. Runtime then began.

**The classification is correct, and TB23-EXEC's restraint was correct.** It preserved the raw evidence, attempted
no package repair, no fixture relocation, no relaunch from a different root, and no diagnosis-driven probe. Under
the turn workflow an orchestration failure is *not* a RED turn failure, and none of the 397 process results may be
promoted to semantic authority.

**The workflow job succeeding is not evidence of validity** — the harness records semantic REDs without failing the
job, so job success and gate validity are independent. That distinction was correctly applied.

**Latest authoritative semantic runtime remains `M3-CP4c-3-TB22`: 387 PASS / 6 RED, accepted 365/365.**

---

## 3. CC2 — the defect is the harness's execution view, not CB25 and not the package

This is the ownership question, and static evidence settles it.

**The package has never contained a `test-data` tree, by design.** The durable reusable workflow
`.github/workflows/agent-compile-reusable.yml` builds the artifact by copying **only** the eight compiled targets
into `$OUT/bin` and the two static libraries into `$OUT/lib`, plus the source archive and metadata, then hashing
the result into `SHA256SUMS`. There is no `test-data` copy step anywhere in it, and no workflow in the repository
references `test-data` at all. The packages consumed by TB18–TB22 were produced by this same reusable workflow.

**How fixtures resolved on the passing turns.** `tests/TestFixturePaths.h:51–64` resolves in this order:

1. `executableDirectory.parent_path() / "test-data"` — the *sibling* layout, used when `…/test-data/benchmarks/fixtures` exists;
2. `executableDirectory / "test-data"` — the *legacy* layout, which `cmake/DirectionalTests.cmake`'s
   `directional_copy_manifest_fixture` creates at build time under `$<TARGET_FILE_DIR>`;
3. otherwise **return the sibling path anyway**.

TB21's report records the working arrangement explicitly: *"executable test binaries were hard-linked into the
execution view and fixtures extracted from the packaged source."* That view is what satisfied branch 1 or 2.

**What TB23's harness did differently.** It ran the binaries from the package's `bin` directory, where no
`test-data` exists at either candidate path, and verified fixtures in the extracted source workspace — a location
the binaries never consult.

**Therefore:**

- **Not CB25.** Its diff touches `RemeshDiagnostics.h`, `GlobalTopologyPlan.h`, a new
  `GlobalTopologyCertificateDiagnostics.h`, `GlobalTopologyPlan.cpp`, `RemeshPipeline.cpp` and
  `FieldAlignedCurveNetworkTests.cpp` — **no CMake, no `TestFixturePaths.h`, no packaging.**
- **Not the package.** It is byte-identical to what the reusable workflow always produces.
- **The TB23 execution harness owns it**: it omitted the execution-view construction that every prior passing turn
  performed, and its preflight checked a path the executable never resolves, so the omission was not caught.

---

## 4. CC3 — why a harness slip became a 397-process pseudo-ledger

The harness omission alone should have produced an immediate, unambiguous stop. It did not, and the reason is a
**second and independent defect on the product side**:

```cpp
inline std::filesystem::path test_data_root() {
  … if (exists(siblingPackage / "benchmarks" / "fixtures")) return siblingPackage;
  … if (exists(legacyPackage  / "benchmarks" / "fixtures")) return legacyPackage;
  return siblingPackage;                       // <-- neither exists; returned anyway
}
```

**`test_data_root()` fails open.** When neither candidate exists it returns a path it has just established does
not exist, with no error, no typed reason and no diagnostic. Every fixture-dependent identity then fails
individually with an ordinary file-open error, and the gate runs to completion producing a **plausible-looking but
meaningless** ledger — 342 PASS / 55 RED with accepted 327/365.

That shape is consistent with the fixture explanation: identities needing no fixture pass, identities needing one
fail, and the 38 accepted-prefix failures are fixture-open failures rather than semantic regressions. **The raw
numbers are audit-only and establish nothing about the product**, exactly as TB23-EXEC recorded and as this review
confirms.

**This is the project's recurring class again:** a precondition helper that cannot report its own failure. Had it
failed closed, the invalid attempt would have stopped at the first identity with one typed reason instead of
manufacturing a 397-row ledger that has to be argued away afterwards. Recorded as lesson 112, and as
`M3-CP4c3-TB23-REV-CAND-01`.

---

## 5. CC4 — CB25 statically satisfies its contract, so re-execution is worth doing

No runtime evidence about CB25 exists. But a static read of the packaged source shows the CA measures were
implemented as specified, which is what makes a re-execution worthwhile rather than a wasted turn:

- **CA1 — discharged.** `certificate_side_orbit` **no longer exists** anywhere in the source; the seed-derived
  helper this review's predecessor required to be retired is gone. Certified ownership now comes from
  `GlobalTopologyCertificateDiagnostics.h`, where `certifiedFaceBySourceFace` is built from
  `directCertifiedFaces` and per-component certified-face sets, and a face's owner is assigned **only when that
  set has exactly one element** (`:135–137`) — certificate evidence, not `edgeOrbitEvidence` or `fragmentOrbits`.
- **CA3 — discharged, and the predicate is satisfiable.** The pair loop (`:181–200`) quantifies over edges with
  two incident faces, **not** in `componentBarriers`, **both sides uncut** — with no
  `certificateSeparatingSourceEdges` intersection anywhere. `examinedPairCount` increments for **every** such
  edge, and `differingPairCount` only when both certified faces are known and differ. The structural zero that
  invalidated CB24's residual **cannot recur in this form**.
- **CA6 — the required variation witness exists.** Ordinal **396** is
  `GlobalTopologyPlan.CertificatePairMeasurementCanReportNonZeroDifferingCount` — precisely the falsifiability
  witness CA6 demanded. Ordinal **395**
  (`CertificateSideLookupDoesNotAliasOppositeSideOrSeed`) targets CA2's independence requirement.

**Not verified, and explicitly not credited:** the invalid attempt reported ordinals 394–396 PASS and 397 RED.
Those results are orchestration-invalid and are **not** used here. CA2, CA4, CA5 and CA6 remain
**runtime-unconfirmed** until a valid gate runs.

---

## 6. CC5 — carried state, candidates and accounting

Carried REDs keep their owners from TB22 and are untouched by this review: **367** co-reaches 366; **368**
prescribed sphere; **369** saturation; **370** typed error `<04>` with no locus; **374** folded-cone. Vertex-30 and
the finalize/contact fall-through remain separate. **There is still no vertex-30 discriminator.**

| Candidate | Transition |
|---|---|
| `M3-CP4c3-TB23-REV-CAND-01` | **NEW / ACTIVE / TEST-INFRASTRUCTURE / NON-GATING** — `test_data_root()` fails open, returning a non-existent path when no fixture tree is found, so a missing fixture tree produces a full pseudo-ledger instead of one typed stop. Owner: a later Code + Build turn; **not** the re-execution, which mutates no source. |
| `M3-CP4c3-TB23-REV-CAND-02` | **NEW / ACTIVE / ORCHESTRATION / NON-STABLE** — the TB23 harness omitted the execution-view construction every prior passing turn performed and verified fixtures at a path the executable never resolves. Owner: **CD1–CD3**. Closes when a valid gate runs. |
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / GATING / BOTH BRANCHES LIVE** — unchanged; CB25's evidence is not yet runtime-confirmed. Owner: CD's re-execution, then TB23-R1-REV. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE / EVIDENCE INTEGRITY** — CA1 and CA3 are statically discharged (§5); closes when a valid run confirms them. |
| `M3-CP4c3-TB20-REV-CAND-02` | **ACTIVE / FORMAL ONLY** — unchanged; CB21 not reverted; owned by a DEFN turn. |
| `M3-CP4c3-TB19-CAND-01`, `M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact | **ACTIVE**, unchanged. |

**Accounting.** No authoritative semantic runtime was produced, so no regression accounting changes and the raw
invalid REDs are **execution-integrity evidence, not stable events**. **+0 events / +0 recurrences.** Totals remain
**44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3 package count **88**.
Authoritative semantic runtime remains **TB22 at 387 PASS / 6 RED, accepted 365/365**. CP4c-3 remains **OPEN**.

### Lessons recorded

- **112.** *A fixture-path resolver must fail closed.* `test_data_root()` checks two candidate locations and, when
  neither exists, returns one of them anyway. A harness slip that should have produced one typed stop instead
  produced a complete 397-process ledger with 38 accepted-prefix failures that then had to be argued away. A
  helper that resolves a required precondition must report when it cannot, not hand back a path it knows is
  absent.
- **113.** *A preflight must check the path the consumer resolves, not a path that merely contains the same
  bytes.* The harness verified fixtures in the extracted source workspace; the packaged binaries resolve
  `test-data` relative to their own executable directory. Both locations held the same files, so the check looked
  correct and proved nothing. Verify a precondition **through the consumer's own resolution rule**.
- **114.** *When several turns pass on an arrangement no artifact records, that arrangement is an undocumented
  dependency.* TB18–TB22 worked because their harnesses staged fixtures into an executable-relative view; nothing
  in the package, the compile workflow, or a durable document stated that this staging was required. The first
  harness that omitted it had no way to know. Write the required runtime layout into the frozen plan.

---

## 7. CC6 — closeout and the one frozen successor

Document consolidation ran under `CLEAN_UP_POLICY.md`, including retrospective indexing of anything the CB25/TB23
turns retired between reviews. `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md`, the tracker, `TODO.md` and the
handoff are updated. Exactly one successor is frozen.

### `M3-CP4c-3-CB26` — Code + Build, **ORCHESTRATION CORRECTION**, `CD0–CD8`

Under the 2026-09-04 routing rule, an orchestration failure routes to a `CB` that fixes the orchestration,
followed by a `TB` that re-executes. **CB26 is that correction turn.** Its subject is the execution harness and the
control plane, not the product.

- **CD0 — control-plane-only, and say so.** The defect is in the harness, not in source (§3), so CB26 **must not**
  change product, test, fixture or selector bytes and **must not** rebuild or repackage. It **reuses immutable
  package `9921914679`** (`sha256:db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7`) built from
  source `e12396d471c0754b112a40272a7992020ff49ced`, with selector **397**
  (`d67e5fb7…9b4853ee5`) byte-frozen. The report must state explicitly that this is the control-plane case, so the
  re-executed gate stays comparable to the frozen TB23 plan.
- **CD1 — construct the execution view.** Stage the packaged binaries together with the fixture tree extracted
  from the packaged source archive into a layout `tests/TestFixturePaths.h` resolves: a `test-data` directory that
  is either a sibling of the executable's parent or a child of the executable's directory, containing
  `test-data/benchmarks/fixtures`.
- **CD2 — verify through the consumer's resolution rule.** The preflight must confirm a known committed fixture is
  readable at the path the packaged executable itself resolves, by reproducing `test_data_root()`'s two-candidate
  rule against the staged view — **not** by checking the extracted source workspace.
- **CD3 — fail closed.** If CD2 does not pass, the harness must **not** start Directional runtime; it terminates
  with the frozen stop reason and preserves the evidence. This is the rule TB23-EXEC's harness violated.
- **CD4 — document the required layout so it stops being an undocumented dependency.** Write the staged-view
  contract into the frozen TB plan and the harness itself, with the resolution order spelled out. Five gates
  depended on this arrangement while no artifact recorded it (lesson 114).
- **CD5 — preserve the failed attempt.** TB23-EXEC's run/job `33833497955 / 100901221113`, artifacts
  `9922540133 / 9922540522` and ledger `839e95fe…7ffc76e85e8d` remain **invalid-attempt provenance**. CB26 may not
  promote any of it, and may not repair, relocate, or re-launch it.
- **CD6 — no product change, and the fail-open resolver stays out of scope.** `M3-CP4c3-TB23-REV-CAND-01`
  (`test_data_root()` failing open) is a **source** change that would invalidate package reuse and force a
  rebuild. It is deliberately **not** fixed here; it belongs to the next Code + Build turn that is already
  changing source. CB26 also executes no Directional runtime.
- **CD7 — audit by assumption.** Show that no product, test, fixture, selector or package byte changed, that the
  package census still matches `9c7b12f4…0359a927`, and that the only edits are harness/control-plane.
- **CD8 — publish the successor TB's obligations.** `M3-CP4c-3-TB23-R1` re-executes the frozen TB23 plan against
  the same package and must publish: accepted **1–365 = 365/365**; ordinal 366's seed state unchanged (component
  0, `Multiple`, orbits `[0,1,3]`, 191 faces); the CA3 pair measurement's **`examinedPairCount` non-zero**
  alongside `differingPairCount`; independently measured certified faces on both sides of each minority edge with
  the seed shown alongside; **the failing component's certified-face multiset**; ordinals **394–397** results;
  carried surfaces **367/368/369/370/374** unchanged; and **371/372/391/392/393** still PASS.

**Then `M3-CP4c-3-TB23-R1`** — artifact-only re-execution of the frozen TB23 plan on the same immutable package,
one identity per fresh process across all 397, every mutation flag false, with CD8's discriminators published and
an explicit statement of whether the run is semantically authoritative.

CD8's certified-face multiset **names the live branch** of `M3-CP4c3-TB21-CAND-01`: several certified faces means
the missing-barrier branch, one means the seed-read branch. The successor after TB23-R1 is an independent
`M3-CP4c-3-TB23-R1-REV`, which owns the correction. TB22-REV's prohibition stands: **no further diagnostic turn is
authorized on that surface** — CB25's contract is the last one.

---

## 8. What a successor must not reopen

- **TB23-EXEC's raw 342/55 ledger and its accepted 327/365 are not semantic authority.** They are fixture-open
  failures from an invalid launch.
- **The package is not defective and CB25 is not implicated.** The compile workflow has never packaged
  `test-data`; the harness has always staged it.
- **CA1 and CA3 are statically discharged** (§5); CA2/CA4/CA5/CA6 remain runtime-unconfirmed.
- **Authoritative semantic runtime is TB22** — 387 PASS / 6 RED, accepted 365/365 — until a valid gate replaces it.
- Accepted ordinals **1–365** remain the load-bearing boundary.
- Everything TB22-REV settled remains settled: the CB24 residual was a structural zero, its certificate columns
  were the seed re-printed, both branches of `M3-CP4c3-TB21-CAND-01` are live, the mechanical complex is cellular,
  and CB21 is not reverted.
