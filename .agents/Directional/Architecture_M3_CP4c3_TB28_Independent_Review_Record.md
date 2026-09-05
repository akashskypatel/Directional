# M3-CP4c-3-TB28 Independent Review Record

## Status

**COMPLETE / STATIC / NO RUNTIME / NO COMPILE / NON-STABLE / TB28-R2 REJECTED / CORRECTION FROZEN.**

`M3-CP4c-3-TB28-INDEPENDENT-REVIEW` is REVIEW + PLAN only. It executed no Directional runtime, no compile, no
package operation, and mutated no product, test, fixture, benchmark, build or selector byte.

**TB28-R2's `407 PASS / 0 RED` result is rejected as orchestration-invalid.** It is not a semantic ledger, it
carries no semantic credit, and it does not advance the checkpoint. The last valid semantic runtime authority
remains **`M3-CP4c-3-TB27-R1`** — 399 PASS / 7 RED on selector 406, accepted 365/365. CP4c-3 remains **OPEN**.

**CL8 is discharged in full.** The product correction is frozen in §4 of this record, unconditionally and with its
exact rule. What §5 sequences is only *when* it is applied, because a gate that cannot be trusted cannot confirm
any correction.

`review_check.py authority 098ac7d93ea203222dd0ac50cdb68667744f0fd4` — **ALL CHECKS PASSED**. Static review of the
working tree is valid evidence about immutable package `9975737868`.

---

## 1. CM0 — the result contradicts an unchanged product, and that is provable

TB27-R1 executed selector 406 and reported **7 RED**, including ordinals **366**
(`GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`), **367** and **398**
(`SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`).

Selector 407 is verified here to be selector 406 plus exactly one appended identity, with 406 as its **exact
406-line prefix** (LF SHA-256 `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`, matching the
plan). So ordinals 366, 367 and 398 are present in selector 407 unchanged. A `407 PASS / 0 RED` gate asserts that
**all three now pass**.

**CB32 cannot have caused that.** The complete diff
`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc..098ac7d93ea203222dd0ac50cdb68667744f0fd4` over
`src/geometry/SurfaceCutGraph.cpp` adds one map, `traceCutExclusionReasons`, records a typed reason at each
pre-existing `continue`, and builds the crossed-face census rows. **Every reference to `traceCutFaces` in the added
lines is a `.count()` read.** Nothing writes `barriers`, `traceCutFaces`, `directOwners`, the seed rule, the
component partition, or `proves_cellularity()`. `GlobalTopologyPlan.cpp` and `RemeshPipeline.cpp` add failure-locus
and diagnostics-row publication only. CB32's own report states the same, and CL8's prohibitions required it.

Ordinal 398 fails exactly when `proves_cellularity()` is false, which requires the source-face owner map to be
total with singleton owners for every face the network does not cross. At TB27-R1 the mechanical component still
carried three conflicting owners `[0,1,3]`, so those 191 faces were `Conflicting` and the map was not total.
**Nothing in CB32 changes that, so ordinal 398 must still be RED.**

**A status change with no behaviour change is a harness result, not a product result.** `LESSONS.md` 129.

## 2. CM1 — what the report does not contain, and the mechanism that fits

The frozen TB28 plan §4 requires an ordered ledger of `ordinal, identity, binary, exit, selected, result, raw_log`
with **407/407 rows and one exact selection per row**, plus the ledger SHA-256, the identity-map SHA-256,
per-ordinal raw logs, a semantic summary with RED ordinals and the **accepted-prefix count for ordinals 1–365**,
pre/post package, packaged-source and execution-view censuses, and resource evidence.

The TB28-R2 report publishes **none of those**. It publishes aggregate counts and `selector407FullGatePassed=true`.
Every prior valid TB report in this checkpoint carried the ledger hash, the RED ordinal list, the accepted-prefix
count, three census hashes and per-process resource evidence; this one carries a result artifact digest and a
boolean.

**The mechanism that fits every observation:** the report records exactly **one** "Runtime binary SHA-256" and one
binary size. The package contains five test executables plus the benchmark binary, and the plan's §2.6 identity map
exists precisely because *"exactly one compiled binary owner"* must be resolved **per identity**. The 407
identities cannot all live in one binary. If every row is invoked against a single binary, `--gtest_filter` matches
nothing for identities owned by the other four, GoogleTest **exits 0**, and the plan's rule *"classify exit 0 as
PASS"* converts every unmatched identity into a false PASS. The plan anticipated this and required a per-row
`selected` column; the report never states a selection count.

I am naming this as the **probable and checkable** mechanism, not as a proven one — the raw ledger that would
settle it was not published, which is itself the defect. CM4 tests it directly.

Note the shape: R1 failed on a `SHA256SUMS.txt` layout assumption, and the R2 "harness correction" produced a
perfect green. **An orchestration correction that turns a known-red gate green has not fixed the harness.**

## 3. CM2 — the CL6 census was also taken off-object, for the fourth consecutive turn

The report's CL6/CL7 block reads:

```
failure reason: ReliefTopologyBuildFailed;  quadPatchIndex=0
failing plan component: 1;  candidate face count: 27
candidateFacesEqualCensusComponent=false;  candidateFacesSubsetOfCensusComponent=true
censusFailureCount=0;  failing-plan interior arc count: 101
arc=(0,2):sourceFace=0:certifierComponent=0:planComponent=1:notTraceCutReason=TerminalSlit
```

None of it is the frontier. The frontier is `UncutFaceComponentOrbitSeedNotUnique` on **component 0** with **191**
faces, **97** boundary edges and **4** interior arcs. This block reports a **`ReliefTopologyBuildFailed`** at
`quadPatchIndex=0` — a different pipeline stage — over a **27-face** candidate set in component **1**, with **101**
interior arcs and **`censusFailureCount=0`**.

`censusFailureCount=0` says the certifier census observed **no ownership failure at all**, which is consistent with
§1's contradiction and inconsistent with the product.

So the CL6 evidence is not evidence about the object CL6 was written for. That is the fourth consecutive turn in
which a census was computed or read on the wrong object — after CJ6's certifier-partition census, CK9's
`matchesFailingComponent=false`, and CL6's own reason for existing. **The `subset=true` finding cannot be credited
either**, because the sets it compares are a 27-face relief-topology candidate list and a certifier census
component, neither of which is the 191-face failing component whose containment CL7 asked about.

## 4. CM3 — CL8 discharged: the product correction, frozen now

CL8 requires this review to freeze a product correction, and forbids "insufficient evidence" as a finding. **The
correction is frozen here, unconditionally.** It is the pre-named default, and it does not depend on any TB28-R2
value.

> **The separating-arc barrier rule.** In `build_source_face_ownership`, for every arc of `embedded.arcs` whose two
> darts satisfy `orbitByDart[forwardDart] != orbitByDart[reverseDart]`, the arc's source edges enter `barriers`,
> and every source face the arc crosses is treated as trace-cut and therefore excluded from `uncutFaces`.

Properties that make this the right default rather than a guess:

1. **It is derived from certified data, not from a heuristic.** The face-walk orbits are computed from the embedded
   graph independently of any partition or seed rule, so keying on them is non-circular — the standing requirement
   since DEFN-R3.
2. **It is exactly the invariant a partition of certified ownership must satisfy.** Only arcs separate certified
   faces; a component that a separating arc crosses cannot lie in one certified face, so propagating a single owner
   across it is unsound. TB27-R1 measured that this is not hypothetical: arcs **14** `(0,1)` and **22** `(0,3)`
   separate.
3. **It does not over-cut.** Arcs 20 and 24 have equal orbits and are unaffected, so genuine non-separating slits
   keep their present treatment. The `terminalSlit` skip is superseded **only for separating arcs**.
4. **It is a superset of current behaviour where current behaviour is already right**, which is what makes its
   accepted-prefix safety demonstrable rather than arguable.

**Accepted-prefix safety must be demonstrated, not argued** — the standing rule for any change touching behaviour
that ordinals 1–365 exercise. CM7 requires the construction argument and CM8 requires the runtime proof.

## 5. CM4 — sequencing, and why this is not a seventh escape hatch

I considered applying the correction immediately and rejected it for one reason: **the only instrument that can
tell us whether the correction worked is the gate, and the gate currently reports green on a product that provably
fails.** Applying a partition-changing correction under an untrustworthy gate would produce a result nobody could
interpret, on the checkpoint's load-bearing boundary.

So the correction is frozen — written out above, not deferred to another review — and the order is:

1. **`M3-CP4c-3-CB33`** — orchestration correction only. Control-plane, **reusing immutable package `9975737868`
   unchanged**, per the standing rule that an orchestration failure routes to a `CB` that fixes the harness and
   reuses the package so the re-execution stays comparable.
2. **`M3-CP4c-3-TB28-R3`** — re-execute selector 407 on that same package. **Expected outcome: the known REDs
   reappear.** This is the control.
3. **`M3-CP4c-3-CB34`** — apply the frozen §4 correction. Its scope is set here and the intervening review **may
   not re-derive, re-open, widen or narrow it**; that review's only business is confirming the harness is
   trustworthy and recording the restored CL6 census.

**CL8 is not weakened by this.** CL8 banned another *diagnostic* turn on source-face ownership and required the
correction to be frozen. CB33 is a harness repair, not a diagnostic turn, and it authorizes no new measurement of
ownership. The correction is frozen. What remains is establishing that the instrument reads.

**A stop rule of my own, so this cannot recur:** if TB28-R3 again reports any ordinal in {366, 367, 398} as PASS
while the product is unchanged, the harness is to be treated as unfit for this checkpoint and replaced wholesale by
the last harness that produced a reproducible ledger — `tools/m3_cp4c3_tb23_r1_harness.sh`, which the plan itself
names as the reference implementation — rather than corrected again.

## 6. CM5 — accounting

**No stable event, category, or recurrence is added.** Totals remain **44 events / 14 categories / 30
recurrences**, produced-witness debt **5**, semantic M3 package count **93** (CB32, compile-green and semantically
unaccepted).

1. **TB28-R2 carries no semantic credit.** An invalid gate produces no ledger, so there is nothing to classify, and
   the accepted-prefix count is **unestablished for TB28** — it is not 365/365, and it is not a regression either.
   The last established accepted-prefix result remains TB27-R1's **365/365**.
2. R1's `SHA256SUMS.txt` failure was already orchestration-only and is unchanged in that status.
3. No accepted-green behaviour was lost, because no valid measurement of accepted behaviour was taken.

**This is recorded as a turn that produced no runtime authority**, which is a different and weaker statement than
"the turn was green", and the two must not be conflated in any successor document.

## 7. CM6 — candidates

**New.**

- `M3-CP4c3-TB28-REV-CAND-01` — **NEW / ACTIVE / GATING / ORCHESTRATION.** The TB28-R2 harness reported
  `407 PASS / 0 RED` on a product whose ownership behaviour is byte-for-byte unchanged from a 7-RED baseline, and
  published none of the ledger artifacts its frozen plan requires. Probable mechanism: single-binary routing with
  `exit 0` treated as PASS and no per-row selection count. Owner: **CM7**. Falsified when TB28-R3 reproduces the
  known REDs with a per-row `selected` column.
- `M3-CP4c3-TB28-REV-CAND-02` — **NEW / ACTIVE / EVIDENCE INTEGRITY.** The CL6/CL7 block was published from the
  relief-topology/quad-patch path over a 27-face candidate set with `censusFailureCount=0`, not from the 191-face
  ownership frontier. Owner: **CM7**, then the TB28-R3 review.

**Carried, unchanged in status.** `M3-CP4c3-TB25-REV-CAND-02` (is the failing component inside one certified
face?), `M3-CP4c3-TB26-REV-CAND-04` and `M3-CP4c3-DEFN-R3-CAND-01` (both **confirmed and gating**),
`M3-CP4c3-TB27-REV-CAND-01` (the certifier partition merges faces in different certified faces — **this is what §4
corrects**), `M3-CP4c3-TB27-REV-CAND-02`, `M3-CP4c3-TB24-REV-CAND-02`, `M3-CP4c3-TB22-REV-CAND-01`,
`M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`,
`M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact
fall-through.

Nothing is discharged by TB28-R2, because an invalid gate discharges nothing.

---

## 8. CM7–CM9 — frozen successors

### CM7 — `M3-CP4c-3-CB33`, orchestration correction only

Control-plane only where possible. **Reuses immutable package `9975737868` unchanged**; it recompiles only if the
harness genuinely cannot be fixed without a source change, and it must say which case applies.

1. **Per-identity binary routing.** Every row is invoked against the binary the static identity map assigns it.
   Record the SHA-256 and mode of **every** runtime executable in the package, not one.
2. **Selection is proved, never assumed.** Each row records a `selected` count. **A row that selects zero tests is
   RED, never PASS**, regardless of exit code. Set `GTEST_FAIL_IF_NO_TEST_SELECTED` or parse the run summary; do
   not rely on the exit code alone.
3. **Publish the ledger the plan requires** — `ordinal, identity, binary, exit, selected, result, raw_log` for all
   407 rows, its SHA-256, the identity-map SHA-256, per-ordinal raw logs, RED ordinal list, the accepted-prefix
   count for 1–365, pre/post package, packaged-source and execution-view censuses, and resource evidence.
4. **Preserve TB28-R1 and TB28-R2 as invalid-attempt provenance.** Neither may be promoted to semantic authority,
   and the `407 PASS` figure may not be quoted as a gate result anywhere.

### CM8 — `M3-CP4c-3-TB28-R3`, the control re-execution

Re-execute selector 407 on package `9975737868`, unchanged. **The run is only credible if ordinals 366, 367 and
398 are RED**; the product has not changed since TB27-R1 and they were RED then. Publish the restored CL6/CL7
census **for the 191-face failing component**, not for whatever object publishes first.

If the run again reports those ordinals green, apply §5's stop rule and replace the harness wholesale rather than
correcting it a third time.

### CM9 — `M3-CP4c-3-CB34`, the frozen product correction

Implements §4's separating-arc barrier rule, and nothing else.

1. Barriers and trace-cut status key on `forwardOrbit != reverseOrbit`, not on `terminalSlit`. Non-separating arcs
   are untouched.
2. **Demonstrate accepted-prefix safety by construction** — show the rule is a no-op wherever the current code
   already inserts the same barrier, and enumerate what changes where it does not.
3. `proves_cellularity()`, ordinal 398, and every ordinal 397–407 keep their contracts. **No ordinal is weakened
   to obtain a green.**
4. Selector unchanged unless a witness for the new rule is required; if one is, it appends as **408** with 407 as
   an exact prefix, asserting the rule's *effect on the census*, never a predicted owner value.

The review between CM8 and CM9 confirms harness validity and records the census. **It may not re-derive, re-open,
widen or narrow the §4 correction.**

### Prohibited across CB33 and TB28-R3

1. Changing any accepted identity 1–365, or any byte of selector 397/401/403/405/406/407.
2. Any product behaviour change in CB33 — it is a harness repair.
3. Quoting TB28-R2's `407 PASS / 0 RED` as a gate result, an accepted-prefix result, or evidence that any candidate
   is discharged.
4. Retrying TB28-R3 to obtain a cleaner result, widening or narrowing the selector, repairing fixtures, or
   regenerating expected data.
5. Any new diagnostic contract on source-face ownership. CL8 stands; §4 is the correction.

---

## 9. Consolidation performed

Per `CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn". Durable facts were verified present in this
record, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
before any fold.

Folded: `Architecture_M3_CP4c3_TB27_Independent_Review_Record.md` (superseded review authority, CL0–CL9 — its CL8
stop rule is discharged by §4 of this record), `Architecture_M3_CP4c3_CB31_Code_Build_Report.md` (consumed build
report, superseded as package authority by CB32).

**Retained deliberately:** `Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md` — it is **the
current valid semantic runtime authority**, because TB28-R2 is rejected. It must not be folded as "superseded"
until a valid successor exists. `Architecture_M3_CP4c3_TB28_R2_Artifact_Only_Test_Benchmark_Report.md` and the
frozen `Architecture_M3_CP4c3_TB28_Artifact_Only_Test_Benchmark_Plan.md` are retained as invalid-attempt provenance
and the contract TB28-R3 re-executes. `Architecture_M3_CP4c3_CB32_Code_Build_Report.md` is the package under test.

## 10. Lessons added

`LESSONS.md` **129** — a status change with no behaviour change is a harness result, not a product result.
`LESSONS.md` **130** — "exit 0 is PASS" needs proof that something ran; a filter matching nothing exits 0.

## 11. Exact successor

**`M3-CP4c-3-CB33`** — orchestration correction only, control-plane where possible, reusing immutable package
`9975737868` unchanged, under **CM7**. Then `M3-CP4c-3-TB28-R3` under **CM8**, then `M3-CP4c-3-CB34` under
**CM9**, which implements the correction frozen in §4.
