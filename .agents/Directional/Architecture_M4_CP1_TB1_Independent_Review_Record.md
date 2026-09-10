# M4-CP1-TB1 Independent Review Record

**Status:** COMPLETE / APPROVED WITH AMENDMENTS / CUMULATIVE TB1 INVALID AS SEMANTIC GATE EVIDENCE / PACKAGE114 NOT PROMOTED / CB4 NEXT
**Turn:** `M4-CP1-TB1-REV`
**Reviewed semantic source:** `680f9f1573d3c7e56a273366436463e40e196131`
**Reviewed immutable package:** package114, artifact `10142108806`
**Reviewed runtime:** `34473066831 / 102857316952`
**Review snapshot/control SHA:** `40a6a397f4d4ec4060cb0c79d3913492e38bed30`

## 1. Review boundary and independence

This is Review + Plan only. No production source, test source, fixture, selector, build configuration, package, or
runtime artifact is modified here, and no Directional binary, test, benchmark, compile, or package build is executed.
The user explicitly authorized this agent to perform `M4-CP1-TB1-REV` in this turn. Because the same conversation has
prior implementation/validation context, this is an adversarial same-agent review rather than a claim of personnel
separation; the decision below is therefore grounded in reopened primary evidence and independently re-derived static
source facts instead of relying on the TB1 narrative.

## 2. Primary evidence reviewed

The review re-opened the immutable TB1 result/log artifacts rather than accepting the execution report as authority:

- result artifact `10150408043`, provider SHA-256
  `c12e73d69fc33572ca7e324656db257dad3fc0b8d789482b8447fc540ec4c5cf`;
- diagnostic log artifact `10150408431`, provider SHA-256
  `d84daf27417751cee121b28cf062869edfae7e7034b6166bd05c2fe9412ce566`;
- package114 source `680f9f1573d3c7e56a273366436463e40e196131`, artifact `10142108806`;
- selector373 LF SHA-256 `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`,
  first-365 prefix SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- current `cmake/DirectionalTests.cmake`, `tests/TestFixturePaths.h`, compile reusable packaging logic, and the retained
  artifact-only M3 harness pattern;
- prior package-closure and execution-view incidents in `Regression_Root_Cause_Tracker.md` and the governing
  package/fixture lessons in `LESSONS.md` §§1 and 8.

The immutable evidence is internally consistent: preflight/postflight pass, the focused CP1 run is **8/8 PASS twice**
with the same verdict vector, and cumulative selector373 reports **189 PASS / 38 RED / 0 SKIP / 146 MISSING** with
only 227 identities selected. All 38 selected REDs contain the same pre-assertion fixture-root exception.

## 3. Independent static reconstruction

### 3.1 The 146 MISSING rows are exactly the omitted owner binaries

The review independently parsed all 373 frozen selector identities from semantic source and mapped each test
identity to the default CMake test target that owns its unique source definition. The map is exact: **373 mapped,
0 missing, 0 duplicate**.

| owner binary | selector373 rows | accepted rows 1-365 | CP1 rows 366-373 |
|---|---:|---:|---:|
| `directional_surface_cell_authority_kernel_tests` | 30 | 30 | 0 |
| `directional_surface_cell_producer_tests` | 227 | 219 | 8 |
| `directional_surface_cell_completion_tests` | 75 | 75 | 0 |
| `directional_surface_cell_validation_tests` | 41 | 41 | 0 |
| **total** | **373** | **365** | **8** |

CB3 compiled only `directional_core` and `directional_surface_cell_producer_tests`. The reusable packager copies each
owner executable only when it exists in the build directory. Therefore package114 necessarily carries the 227-row
producer owner and omits exactly `30 + 75 + 41 = 146` frozen rows. The selector is correct; the package closure is
not. A unified test executable or relocation of 146 tests would be a larger semantic/build-surface change with no
justification.

### 3.2 The 38 RED rows are an execution-view materialization defect, not absent fixture authority

`directional_copy_manifest_fixture(directional_surface_cell_producer_tests)` already creates
`<target-dir>/test-data/benchmarks/fixtures` at build time. `TestFixturePaths.h` resolves only a sibling
`../test-data` or legacy `bin/test-data` tree and fails closed when neither exists. TB1 ran the extracted package
binary directly from `/home/runner/work/_temp/m4-cp1-package114/bin`, where neither layout exists.

Package114 nevertheless contains the immutable source archive
`source/source-680f9f1573d3c7e56a273366436463e40e196131.tar.gz`; its `SHA256SUMS` was verified in TB1. The already-retained
M3 artifact-only harness pattern extracts that package-owned source archive, copies `benchmarks/fixtures` into a
fresh execution view at `test-data/benchmarks/fixtures`, copies the immutable binaries into `execution-view/bin`,
and verifies package/source/execution-view censuses before and after runtime. That is the established solution to
this exact consumer-relative fixture-root problem. It does not mutate or repair the immutable package.

Therefore changing production fixtures, `TestFixturePaths`, or the reusable package format is unnecessary for this
failure. The correction belongs in the artifact execution view and its preflight.

## 4. Findings and adjudication

1. **TB1 focused CP1 evidence is credible and retained.** The eight new CP1 identities were present, selected, and
   executed twice from the exact immutable binary; all eight pass deterministically. This is valid bounded semantic
   evidence for those eight assertions, but it cannot close CP1 without the frozen accepted predecessor.
2. **The cumulative result is not a product-semantic RED.** Calling the entire run `SEMANTIC_RED` is too strong.
   The cumulative gate is mechanically failed, but 146 rows never selected and the remaining 38 REDs failed before
   their intended assertions on a missing execution-view precondition. The accepted predecessor was therefore not
   semantically re-proved or semantically falsified.
3. **`M4-CP1-TB1-EXEC-CAND-01` is adjudicated as PACKAGE CLOSURE / OWNER-TARGET OMISSION / NON-STABLE.** Exact static
   mapping proves all 146 missing rows have one existing owner among the three default binaries CB3 did not build.
   No selector or test relocation is authorized.
4. **`M4-CP1-TB1-EXEC-CAND-02` is adjudicated as EXECUTION-VIEW FIXTURE MATERIALIZATION / NON-STABLE.** Exact fixture
   bytes already exist in the package-owned source archive; the TB1 harness failed to construct the executable-relative
   runtime layout that accepted M3 artifact-only gates already use.
5. **No stable product regression is established.** Both candidates are package/control-plane closure defects, so
   stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, accepted
   packages **113**. package114 remains unpromoted.
6. **The frozen selector373 is upheld byte-for-byte.** It is neither too broad nor mis-owned: static reconstruction
   finds one owner for every row. Shrinking it would discard accepted authority; unifying all tests into the producer
   target would solve the symptom by changing an intentional target decomposition.

## 5. Engineering-guideline challenge

The simplest sufficient correction is smaller than either option posed by the raw TB1 report. Do **not** create a
unified gate binary, relocate test definitions, change fixtures, teach `TestFixturePaths` a new fallback, or modify
production semantics. Rebuild the unchanged semantic source with the four already-established selector-owner targets,
then execute through a preflighted immutable execution view derived solely from the new package's own binaries and
source archive.

This repeats two previously proven project controls rather than inventing new machinery: package closure follows the
frozen selector's owner set, and artifact-only runtime materializes the exact fixture root the binary resolves. The
failure is a recurrence of existing package/fixture process lessons; no new `LESSONS.md` rule is needed.

## 6. Decision

**`approved_with_amendments`.** TB1's package114 non-promotion, raw counts, focused-green receipt, and non-stable
candidate grouping are upheld. The amendment is semantic classification and corrective scope: the cumulative 373-row
result is **orchestration/package-closure invalid as semantic gate evidence**, not evidence of 38 product regressions;
its correction is package closure plus execution-view staging, not selector/test/product modification.

Package114 remains immutable historical evidence. It is not repaired or retried. The exact successor is
**`M4-CP1-CB4` — runtime-free Code + Build / package-closure and TB-harness correction** under
`Architecture_M4_CP1_CB4_Code_Build_Plan.md`.

## 7. Falsifiable prediction

If CB4 builds the unchanged semantic source `680f9f1573d3c7e56a273366436463e40e196131` with all four statically proven
selector-owner binaries and the successor TB materializes `test-data/benchmarks/fixtures` from that package's own
source archive before any Directional process starts, then selector373 preflight will map **373/373 exact-once** to
present executable owners, every identity process will report `selected=1`, and the 146 MISSING plus 38 fixture-root
failures will disappear. If any row remains ownerless/multiply-owned, any mapped executable is absent, or one known
fixture cannot be resolved through the consumer's own `TestFixturePaths` rule, CB4/TB2 must fail closed before semantic
promotion rather than weakening selector373.

This prediction does **not** predict that all 373 semantic assertions must be green; any remaining assertion-level RED
after package/execution-view integrity is established is new credible runtime evidence and must be classified normally.

## 8. Integrity confirmation

- Production code changed: **no**.
- Test/benchmark definitions changed: **no**.
- Fixture or selector bytes changed: **no**.
- Build configuration/reusable workflow changed: **no**.
- Directional compile/package/runtime/test/benchmark executed: **no**.
- Review-only static parsing/inspection performed: **yes**.

## 9. Live handoff

- Evidence source: `680f9f1573d3c7e56a273366436463e40e196131` / package114 / TB1 run `34473066831`.
- Review snapshot/control: `40a6a397f4d4ec4060cb0c79d3913492e38bed30` (`runtimeExecution=false`).
- Review-approved next plan: `Architecture_M4_CP1_CB4_Code_Build_Plan.md`.
- Next canonical turn: **`M4-CP1-CB4`**.
- Runtime authority remains M3 package113/TB48 until a later complete M4 gate is promoted.

---

## 10. Verification-pass addenda (static, appended after adjudication)

A verification pass re-derived §§1–9. **The adjudication is upheld.** One gap in the new identities' evidentiary
reach is added.

### 10.1 — confirmed, and the §1 disclosure is the right way to handle it

- **The classification is correct and precisely stated.** §4.2 refuses `SEMANTIC_RED` on the right grounds: 146
  rows were never selected and the other 38 failed **before** their intended assertions on a missing execution-view
  precondition, so the accepted predecessor was *"not semantically re-proved or semantically falsified."* Neither an
  acceptance claim nor a regression claim is made from an incomplete run.
- **The static reconstruction is real verification, not narrative.** Mapping all 373 selector identities to owning
  CMake targets — **373 mapped, 0 missing, 0 duplicate** — and deriving `30 + 75 + 41 = 146` from the three unbuilt
  owners establishes the defect independently of the TB1 report.
- **§5's restraint is correct.** Refusing to unify targets, relocate tests, or teach `TestFixturePaths` a new
  fallback avoids fixing a symptom by widening a resolution rule. Both defects are recurrences of retained
  fixture/package lessons, and declining to mint a new one is the right call.
- **§7 is framed as a falsifier, not a target** — explicitly *not* predicting 373 green, and requiring any
  remaining assertion-level RED to be classified normally.
- **The §1 independence disclosure is exactly the right handling.** Naming the same-conversation limitation and
  describing the compensating control — reopened primary artifacts and independently re-derived source facts — is
  more useful than an unsupportable claim of separation.

### 10.2 — the tiny oracle cannot exercise the risk that `M=2` was chosen against

§4.1 credits the eight CP1 identities as *"valid bounded semantic evidence."* They are: the oracle at
`tests/GlobalConformityPlanTests.cpp:248` genuinely executes, and the comparison test additionally asserts
`refinementM == 2`, refinement-count consistency, strict per-step scalar decrease, and terminal non-improvement
validation. Nothing here is vacuous in the sense of `LESSONS.md` 155/160.

**But its subject cannot exhibit the failure mode under test.** `tiny_exhaustive_equal_counts_oracle` searches a
**single scalar** `x ∈ [1,8]` minimizing `|x−d₁| + |x−d₂|` and returns `{x, x}`; the paired fixture is
`two_row_equal_counts_problem`. That is **one degree of freedom**.

`M4-DEFN-R1` §R6 traded the outer polynomial bound for `FiniteExactConvergence`, and CB3 confirmed Theorem 3.8
gives global optimality **for `M >= 2`**. The residual implementation risk that trade creates is precisely this:
that `M=2` refinement **stalls at a local fixed point** on an instance where improvement requires a coordinated
change across three or more coordinates. **A one-variable instance has no such structure**, so on this fixture any
correct method — `M=1`, `M=2`, or plain enumeration — returns the same answer. The comparison would pass even if
`M=2` were insufficient.

`GenuinelyBidirectedLoopPermutationAndReversalAreDeterministic` does exercise the bidirected `±2` structure, but
for **determinism**, not optimality. So bidirected structure and optimality-against-an-oracle are currently tested
on **disjoint** instances.

The gap is also narrower than the definition permits: `M4-DEFN` §8 authorizes the tiny oracle over *fixed small
feasible graphs* at `E<=6, x_s<=8`. Full enumeration at `E=6` is `8^6 = 262,144` vectors — trivially cheap — so the
frozen envelope already allows a multi-coordinate oracle. **No definition change is needed.**

> **Added to CB4 / the successor TB (non-optional):** extend the exhaustive comparison to at least one instance
> that is **multi-coordinate** and **carries the bidirected `±2` structure**, enumerating the full count vector
> within the frozen `E<=6, x_s<=8` bound and comparing against the solver's terminal schedule. Publish, per CP1
> identity, a receipt naming the instance's coordinate count and whether it contains a `±2` incidence — so
> "compared against an oracle" and "compared against an oracle that could have disagreed" remain distinguishable
> in the ledger.

This is a coverage obligation, not a defect finding: nothing in §§1–9 is shown wrong, and the eight identities
remain credible for what they assert. **The `M=2` sufficiency claim is currently carried entirely by a cited
theorem, with no runtime witness able to falsify its implementation** — which is exactly the class of assurance
this project has twice paid to discover late.

### 10.3 — accounting

Unchanged. Static addendum, **+0 events / +0 recurrences**. Package114 remains unpromoted; runtime authority remains
**M3 / package113 / TB48**; accepted selector **365** unchanged. **Exact next remains `M4-CP1-CB4`.**
