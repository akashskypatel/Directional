# P13-d / O18 — Vase completion incidence Review/Definition (2026-11-01)

**Canonical turn:** `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE`. **Disposition:** bounded producer-boundary evidence required before any semantic fix. **Authorized next:** `M6-CP3-CB67-P13-VASE-INCIDENCE-BOUNDARY-PROBE` (Code + Build, compile-only), followed by a separate immutable Test + Benchmark execution and independent Review. This definition turn does not execute either successor.

## Frozen provenance and independent evidence

- Source snapshot: SHA `d321762fdc7e4b756911690e7c18b8ab8b772b9d`, GitHub snapshot run `41291266174`, artifact `13076978000`; `source.tar.gz.sha256` and all **6065/6065** source manifest entries verified. That source differs from CB66 runtime semantic SHA `911840c195b52ce1800b3ac7ff3ea7380137ad9c` only in repository-control-plane commits prior to this review; no semantic equivalence across refs is claimed without a source diff.
- Existing, **not re-run**, TB65 Linux source package `13067780359` and census run `41275273919`, result artifact `13071376917`, **9/9 checksum entries independently verified** here. Raw census `raw/3.log`: Vase rejected `terminal=NotProductionReady:completion`, `completion=SideSubdivisionRepair:InvalidInputIncidence`, `detail=None`, `traceSegments=192482`, `completedQuads=0`; the two other census tests are independently recorded as Cylinder PASS and BunnyRandom P13-e RED. `arrangementCells=0` is a reported diagnostic count, **not proof** that the arrangement was empty.
- Gate independently reported by TB65 as **869/869**, membership 950 = 869 gated + 81 deferred, candidate-only. This review did not re-run or newly accept it, nor re-hash the accepted 491 selector prefix. CP2 491/491 remains last accepted; stable **66 events / 17 categories / 49 recurrences**, debt **1**; selector497/CP3 unpromoted.

## Static causal investigation — earliest known rejecting predicate, not guessed producer

1. `src/pipeline/RemeshPipeline.cpp` builds `arrangementComplex`, passes it to `simplify_surface_cell_complex`, then selects `simplified.complex` if `hasComplexOutput`, otherwise the retained arrangement as `completionComplex` (`~13898–13933`). The current census does not identify which selected complex first violates incidence.
2. `src/geometry/PatchDescriptor.cpp:2476–2543` calls `repair_surface_cell_boundary_parity(complex)`, then passes the returned complex to `repair_surface_cell_side_subdivisions`.
3. `src/geometry/SurfaceCellFeasibilityRepair.cpp:1649–1666`: if `odd_bounded_cell_count(input) == 0`, parity repair returns `Produced` **without** `validate_incidence_allowing_nondisk(input)`. Only the nonzero-odd branch validates before proceeding. The zero-odd fast path therefore does **not certify incidence**. This is a contract-validation blind spot, not evidence that parity *caused* the invalid incidence.
4. In the same file (`~2073–2125`), side repair canonicalizes side metadata, then evaluates `validate_incidence_allowing_nondisk(canonicalInput)` and returns `InvalidInputIncidence` when it fails. That validator (`~426–492`) checks node/halfedge identity, twin/next/endpoint/cell constraints and bounded-cycle traversal. The census's typed rejection establishes that this predicate was false **at the side-repair boundary**; it does not say which clause was false or where it arose.
5. `src/pipeline/RemeshPipeline.cpp:~14147–14150` preserves the completion failure's detail in `surfaceCellContext.completionFailure`. The completion rejection path at `~14793–14805` writes first-invalid-producer stage/reason only when no earlier one was set, but the census user-facing `detail=None` does not contain the failing halfedge/cell. **O18 remains open**: there is no demonstrated end-to-end typed first violating incidence site in the recorded Vase result.

**Ruling:** No evidence currently distinguishes arrangement-origin invalidity, a simplification-induced invalidity, or an invalid parity transform. The parity no-op is a plausible bypass of detection; it is not a geometry-producing root cause. It would be unsafe to introduce an incidence 'repair', skip the validator, alter an assertion/selector, or attribute the defect to source geometry based solely on the current terminal string.

## Frozen bounded next Code + Build: `M6-CP3-CB67-P13-VASE-INCIDENCE-BOUNDARY-PROBE`

Change only the smallest existing producer/validation boundary needed to record the **first exact** failed incidence predicate for Vase, without altering admission, face/edge identity, topology, branch decisions, results, default recovery, or accepted tests. The implementation must preserve the pre-existing `SideSubdivisionRepair:InvalidInputIncidence` rejection. Its diagnostic must include stable, content-grounded indices/identities rather than allocation addresses, traversal-order accident or broad floating tolerance.

Evidence capture points (read-only, diagnostics-only): (a) exact arrangement output before simplification, (b) simplifier input/output or identity fallback and whether it actually changed topology, (c) parity input and output including `oddCellsBefore`, (d) side-repair input immediately before the rejecting check. Invoke **one consistent named validation oracle** at these boundaries, classify which precise clause fails first, and preserve a compact proof of where the first invalid incidence appears. Compare the exact same structural identities before/after; don't claim a producer transition from differing lossy hashes. Propagate the resulting typed locus to O18's diagnostic display without hiding the actual rejection. Keep instrumentation inert for accepted healthy fixtures.

Independent falsifiers and stop rules (freeze before compiling):

- **F1:** If any earlier boundary already violates the exact incidence oracle, attribution to later parity or side subdivision as the origin is disproved; stop and assign the earliest producer instead.
- **F2:** If arrangement passes, but simplification fails, stop and assign simplification; if both pass but parity fails, assign parity's transformation. If all pass and side repair rejects without a structural mutation, the oracle/metadata canonicalization equivalence or instrumentation contract is suspect—do not claim a geometry repair.
- **F3:** Inject a known invalid twin, missing successor, or repeated directed-edge cycle into a synthetic source-complex unit fixture and require the named clause/site to identify it; also require a valid complex to pass without adding a false positive. Tests must be independent of the producer and fail if its obligation is violated; never weaken existing assertions.
- **F4:** The repaired O18 detail must be visible on the same terminal/display path that previously printed `detail=None`, and identify an actual source-supported locus. A generic `InvalidInputIncidence` duplicated into `detail` is not sufficient.
- **F5:** Freeze source SHA, package identity and compile-only evidence with real GMP/GMPXX linkage; no binary/test/benchmark execution in CB. In a separate TB execute the unchanged 869-case gate and controlled Vase census on the exact artifact, plus the bounded non-vacuity cases. Any selected-gate RED, unexpected changed source signature, or lost rail/source-sheet/topology authority requires independent Review; no selector/CP3 promotion.

Only after a subsequent independent evidence Review establishes the *first* violating producer may a separate semantic-fix definition authorize a targeted corrective patch. No more generic downstream incidence sanitizer or fabricated success path.

**Out of scope:** BunnyRandom P13-e (separate `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT`), O16, O19, O6/O9, broader FlowRep rewrite, arbitrary surface repair, tests-as-green-status, legacy fallback, modifying or promoting selectors, rerunning TB65 in this Review.

**Process transparency:** Initial handoff/policy/TODO connector reads preceded the required `READ_MODE=snapshot` declaration; the agent corrected to an exact, hash-verified snapshot and did not continue piecemeal source inspection. First-tool invocation ledger was not initialized on time; exact call total is unknown, not estimated. No claim of authentic Git history or compiled/run verification is made from this review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector/prefix edits; accepted CP2 491 unchanged. Prior TB65 869/membership 950 cited as candidate, not independently re-hashed here. |
| Decisive claims independently re-derived | Exact source call paths, bypass/validation predicates; TB65 Vase raw log and 9/9 result archive checks. Root producer explicitly unproved. |
| Non-vacuity checked | Next probe F1–F4 requires a valid control, invalid input, and changed-stage attribution; no runtime success claimed now. |
| Prior obligations discharged/carried | P13-d/O18 retained with exact bounded probe; P13-e, O16/O17/O19, O6/O9, DR1/DR3, DR2/DR4, O2b retained by prior owners. |
| Stable accounting | 66/17/49, debt1; CP2 491/491 accepted, selector497/CP3 not promoted; TB65 869/869 candidate. |
| New candidates/obligations recorded | No new stable ID; P13-d/O18 refined to structural first-boundary probe with explicit falsifiers. |
| ORIENTATION currency line | Refreshed to this Review decision and next bounded CB. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 current boundary updated; §4 n/a unchanged witness outcome; §8 adds existing first-rejection-vs-origin defect lesson. |
| CHANGELOG | New evidence-only decision entry. |
| ROADMAP | Corrected stale TB64 boundary to TB65 and this decision. |
| Selector manifest | n/a: not changed or promoted. |
| LESSONS | Existing 'predicted cause substituted for measured cause' applied; no new lesson claimed. |
| Consolidation under CLEAN_UP_POLICY | n/a: prior evidence authoritative/historical; no obsolete duplicate document identified. |
| Successor frozen | `M6-CP3-CB67-P13-VASE-INCIDENCE-BOUNDARY-PROBE` — diagnostics-only CB, exact F1–F5 before build; independent TB then Review. |
| Turn boundary held | Review only; no local compile, native tests, benchmark, product/test/selector/fixture mutation. |
| review_check.py boundary | Pending authentic Git-history CI; must not count synthetic snapshot checks as historical verification. |
| `STATUS` lifecycle maintained | Entry beacon published; final beacon required after durable patch application, with original started timestamp retained. |
| Pushed to origin, branch in sync | Pending verified durable patch application and remote sync check. |
