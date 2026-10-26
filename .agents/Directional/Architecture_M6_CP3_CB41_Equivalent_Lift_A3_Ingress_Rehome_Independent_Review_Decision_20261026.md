# CB41 independent review — selector189 equivalent signed-lift A3 ingress (2026-10-26)

**Canonical turn:** `M6-CP3-CB41-RP01-EQUIVALENT-LIFT-A3-INGRESS-REHOME-REV`
**Static disposition:** source/test review supports CB42 conditionally; formal closeout awaits the mandatory authentic-Git `review_check.py boundary` proof. **Not runtime acceptance.** This review derives the assertions from the independently retrieved immutable compile package and byte-matched full source snapshot. No Directional binary, test, benchmark, compilation or source repair was run by this Review.

## Evidence and source authority

- Exact compiled source `53830149ea16473d0321e53da2587695916fd9cb`. Compile [run 40275357335](https://github.com/akashskypatel/Directional/actions/runs/40275357335), artifact `12630300861`, independently downloaded ZIP SHA256 `4e0d81532a8c33733b06ffb5be2054fc32e451fd54205d3784d778ab9fb0b2b1`; **28/28** internal hashes passed.
- Eight approved targets recorded (core, pipeline, authority-kernel, producer, completion, validation, API tests and benchmarks), compile/preflight exit **0/0**, `DIRECTIONAL_ENABLE_GMP=ON`, explicit `libgmpxx.so` and `libgmp.so` in authoritative linker line, clean source, `runtimeExecution=false`. Initial failed compile [40274040338](https://github.com/akashskypatel/Directional/actions/runs/40274040338) was not accepted.
- Full source snapshot commit `4ecb9742cce63be875d2ca7c1c883ae6e3949b08`, [run 40277564806](https://github.com/akashskypatel/Directional/actions/runs/40277564806), artifact `12630653248`, ZIP SHA256 `638647e2142a0ba55d2bea33d35a954f2ac83d956f2645f825862e06a4f48555`; tar hash passed; **5900/5900** file hashes passed. `tests/SurfaceCellsPhase10Tests.cpp` is byte-identical to the packaged compiled source. Snapshot differs from the compile commit in documentation/control-plane state; it is not separately compiled evidence.
- GitHub compare `0d227875d8f031a467e661be2da4dd901846797c` → `53830149ea16473d0321e53da2587695916fd9cb`: test/implementation surface change only `tests/SurfaceCellsPhase10Tests.cpp`, +60/−4, alongside documentation/control-plane paths. No implementation, fixture, selector manifest, benchmark or CMake changes in that interval.

## Independent re-derivation — RA-155.3 C

1. `EquivalentSignedRepresentationsNormalizeSemantically` makes a copy of the independently produced balanced periodic fixture field. The two matching records are selected by the fixture's independently named source-edge topology; one is incremented by **+4**, the other decremented by **−4**, with unchanged mod-4 quarter-turn assertions. This deliberately changes the integer lifts while preserving semantic transport.
2. `build_source_topology_regions` constructs the shared source-topology authority. `FieldTransportAtlas::make` is invoked **twice**, with `baselineField` and `equivalentField` respectively, and both must have values. `FieldTransportAtlas.cpp` builds `forward=QuarterTurn::from_integer(raw.matching)` while retaining `raw.matching` as `forwardLift`; reverse lookup negates that integer lift. Thus the test's directed lift difference must equal the directed raw matching difference, with absolute value **4**, while `original->transport == relabeled->transport`.
3. The helper `build_periodic_route_network_with_source_atlas(fixture, tracingField, sourceField)` explicitly derives the A3 atlas from `sourceField` and passes it into the checked A4 options. Each A4 subject now receives its **own** field in both arguments, rather than using baseline atlas authority for the equivalent subject.
4. The preserved positive A4 `Produced` and exactly-one-holonomy assertions precede the `PeriodicHolonomySnapshot` equality. That snapshot contains the full `GridAutomorphism`, primary canonical route and cut route, rather than rotation alone. The construction is no longer the prior unconsumed-stimulus oracle: deleting the own-field A3 branch or normalizing away raw integer signed lifts would falsify checked prerequisites or lift differences. Runtime reachability is nevertheless unmeasured until TB41.
5. Final compile-only correction on source `53830149ea16473d0321e53da2587695916fd9cb` replaces two pointer-style accesses with guarded `.value()` accesses, leaving every assertion and the two field assignments unchanged. The original failed artifact is not counted as green.

## Scope, carried obligations, and adjudication

The first documentation apply (run 40279714936) failed the workflow whitespace gate because the initial patch added a trailing-space Markdown line. The prior local whitespace-verification claim was incorrect. The revised complete patch removes the defect; no documentation landed in the failed attempt.


**Approve static test authority only.** Frozen selector497 is unchanged and unpromoted; CP2 remains accepted **491/491**, TB38 reviewed candidate **490/504**, stable accounting **66 events / 17 categories / 49 recurrences**, debt **1**, RP-01 open, RP-02 unreached. There are no new runtime results, no new stable events and no new tracker candidate. RA-155.3 C is statically discharged. O3 belongs to CB42; TB41 owns runtime verification of 189/191/192/204/247/250/251/252 and guards. O1/O2/O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4 and G4-B002 remain with their previously assigned owners. No safe superseded CP3 per-turn evidence was identified for folding: CB39/CB40/CB41 compile and Review source/identity evidence remain required through TB41. No selector files are folded.

**Exactly one successor:** `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN` (test-only Code + Build, RA-156 J3/O3). Require polygonal-disk rejection oracles in cases 251, 252 and `:2936` to pin `cell=-1, side=-1` at the actual source-owned rejecting locus, without broadening the predicate, relaxing failure assertions, changing production/selector/fixtures, or running tests in CB42. Review then follows as its own `-REV` before immutable artifact-only TB41. A failure to show that the added assertion binds the real typed rejection locus is a stop condition.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — CB41 changes no selector bytes or accepted prefix. Source GitHub compare has no selector file; existing accepted 491/491 not reexecuted. |
| Decisive claims independently re-derived | Own-field A3 make, raw ±4 directed lift, mod-4 transport, full A4 snapshot, two guarded `.value()` accesses; 28/28 compile hashes and 5900/5900 snapshot hashes. |
| Non-vacuity checked | Two different raw-field A3 constructors, exact signed integer checks, own-field A4 route, positive Produced and full snapshot checks; runtime pending TB41. |
| Prior obligations discharged/carried | RA-155.3 C statically discharged; O3→CB42, runtime→TB41, all named carried obligations preserved. |
| Stable accounting | 66/17/49 debt1; CP2 491/491 accepted, TB38 490/504 candidate, selector497 frozen/unpromoted. |
| New candidates/obligations recorded | None; no runtime observation or new root-cause claim. |
| ORIENTATION currency line | Updated to CB41-REV static decision and CB42 successor, 2026-10-26. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a no witness status change; §8 retains the prior unconsumed-oracle pattern, no new pattern found. |
| CHANGELOG | One CB41-REV entry inserted. |
| ROADMAP | CP3 current boundary updated; milestone status unchanged. |
| Selector manifest | n/a — no selection addition or acceptance. |
| LESSONS | Existing non-vacuity and evidence-boundary principles apply; no distinct new lesson. |
| Consolidation under CLEAN_UP_POLICY | CP3 census: no safely superseded documents; zero folded; pending TB41 still needs historic compile/review files. |
| Successor frozen | `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN`; O3 `cell=-1,side=-1` and failure-stop contract above. |
| Turn boundary held | Static source/artifact review; no runtime or product/test/fixture/selector/build changes. |
| review_check.py boundary | **PENDING**: not run against authentic Git history; exact source/snapshot hashes and GitHub changed-file inventory are supporting but not substitute evidence. Do not claim a boundary PASS or formal review closure. |
| `STATUS` lifecycle maintained | Entry/resume beacons published. Retain same-turn IN_PROGRESS until authentic-Git boundary proof and final COMPLETE beacon. |
| Pushed to origin, branch in sync | Corrected patch applied by workflow 40280230101 at commit `9870215dedb4dfe820b97ce784f84495e021d075`; exact six document paths independently verified via GitHub commit inventory. Authentic `git status -sb` not established. |
