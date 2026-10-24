# CB34-REV — independent face-gauge source and compile review (2026-10-24)

**Canonical turn:** `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR-REV`. **Decision: ACCEPT the bounded CB34 test-only change for immutable TB35 verification, not for runtime or product acceptance.** Semantic source `d5fc8f22fd309ba90ad1fd7b4fbdc3491a5a8f7d`; PR #8 remains draft. No binaries, tests, benchmarks or compilation executed in this Review.

## Independently verified authority

- New exact working-branch snapshot `b91fc01a044d1e58e7dfd76aafd122dbb24c1ca8` at [run 40112998078](https://github.com/akashskypatel/Directional/actions/runs/40112998078), artifact `12567576324`, outer ZIP SHA-256 `411d4071d33d07f16e6be5caf630448d970f2e54caf799bca6d9eb838ce5cc8d`, archive SHA-256 `a5e0ae8c5c9fd80beee9d8f59c73b9e39ab306a81b1ac3959a43cc63c146ba06`, 5,848/5,848 source file hashes checked. Exact CB34 compiled test/FTA source bytes match this snapshot.
- Historical pre-CB34 source snapshot `388854b4a611b788c2c41991cd991ae6fc574be3`, artifact `12563781300`, outer SHA-256 `5491250e51d1546298bd09bfcb0a4ad6a00866f0b99161da593331ac97569b2b`; 5,847/5,847 hashes checked. Byte diff of `tests/SurfaceCellsPhase10Tests.cpp` changes only `balanced_periodic_route_field()` and inserts one `BalancedRouteFieldIsPureFaceGauge` test. All seven original selector189–195 test bodies and helpers outside that function remain byte-identical. `compare_commits` CB33→CB34 shows the only test/source changed file is `tests/SurfaceCellsPhase10Tests.cpp`; no production/fixture/selector/workflow semantic edits.
- Compiled artifact [run 40111610291](https://github.com/akashskypatel/Directional/actions/runs/40111610291), ID `12566907246`: independent ZIP SHA-256 `ca5c490bae2d65f9c043636c285d29edcfe5695b9334c24edcc281fac26c6a17`, 28/28 packaged hashes, exact `source-commit.txt` = `d5fc8f22fd309ba90ad1fd7b4fbdc3491a5a8f7d`, 8/8 required compiled targets, preflight/build exit 0/0, five clean source status files, GMP/GMPXX link path, `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Prior compiler error on `DomainResult` dereference was corrected to `.value()`; that first failure is not erased.
- Accepted 449-line frozen selector independently SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, matching historical pre-CB34 bytes; selector497 untouched.

## Independent gauge/cycle derivation

For gauge `g(face1)=1`, all other faces `0`, the implementation adds `g(to)-g(from)` to each of face1's **three** directed matchings: into face1 +1, out of face1 −1. The source topology has three incident neighbors, faces 0, 30, 32, and each original edge is checked zero in both `edgeTransitions` and compact `matching` before mutation; `effort` is unchanged. The changed frame is `(p',s')=(-s,p)`, so raw branch `u'_k=u_{k-1}`. From the canonical A3 frame construction selecting smallest positive angle among `(p,s,-p,-s)`, this shifts `rawGauge(face1)` by **+1 modulo 4** while preserving each canonical geometric branch. In `build_branch_transports`, `canonicalLift = rawLift + rawGauge(from)-rawGauge(to)`; the additive edge gauge cancels exactly against the gauge-index difference. Therefore every canonical branch transport, and the frame and semantic digest, must be invariant, whereas raw steps into/out of face1 remain nonzero; every closed local-star sum telescopes to 0. This is a representation relabel, not the invalid two-edge-only matching edit. No epsilon, atlas guard weakening, source/tracing divergence or production mutation was introduced.

The new oracle compares *independently rebuilt original and gauged A3 atlases* for `semantic_digest`, `frames`, `transports`; separately checks all three signed raw transitions and confirms that the original two-edge-only corruption rejects with `CycleTransportMismatch`, `site=cycle-transport`, `LocalVertex`. The seven frozen tests remain decisive for periodic A4 reachability, route reversal, face row order, legacy path, and negative holonomy. **Static equivalence is accepted; actual A3 success and every subsequent assertion remain unmeasured until TB35**. Reuse of some common source topology in the invariance comparison does not make the oracle tautological because original and changed fields are distinct and raw transition assertions distinguish nonzero from zero gauge.

## TB35 independent verification authorization and falsifiers

**Exactly one successor:** `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY`. Its immutable input is artifact `12566907246` from compiled source `d5fc8f22fd309ba90ad1fd7b4fbdc3491a5a8f7d`; exact 13-case manifest `.agents/Directional/Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Case_Manifest.tsv` SHA-256 `d67e503db14f2cb1ae978482665057372edd2e56d7763cd38288469174e75af8`: frozen selector189–195 (7), new invariance oracle (1), original A3 tamper controls (2), TB33 factory controls (3). Preserve order and each literal GoogleTest filter. Fresh independent process per case, complete raw log, exact one-test and terminal result, immutable pre/postflight, no rebuild/relink/runtime repair/selector edit. Capture both PASS and RED rather than assigning success in advance. Any first A3 S1 failure on the valid gauge, non-invariant canonical result, absence of nonzero raw steps, missing/duplicate process, unsupported source hash, changed accepted GTest assertions, altered frozen selector, or guard regression **halts acceptance and returns to independent Review**. If S1 clears and A4 fails, record the new first producer-owned predicate and commission a separate DEFN; never retune the fixture. TB35-REV must independently reopen logs and hashes before any recovery or CP3 credit.

**Prior obligations:** RA-150.3 gauge/three-edge/frame and CB34 compile fidelity discharged statically; RA-150.4 runtime falsifiers, seven inherited REDs, RA-146.2/4, RA-45.4, G4-B002, DIAG-RETAIN, DEFN-SEAM-NZ, periodic A4/A6 and untyped seven carried. No new accepted-green loss, new stable event, or product acceptance: stable **66/17/49**, debt **1**, CP2 **491/491** accepted; TB32 **481/500 candidate, 19 RED**; TB34 **5 PASS / 7 RED**; selector497 frozen; RP-01 open/RP-02 unreached/Gate C suspended.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 449-row SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; same historical bytes; 497 untouched |
| Decisive claims independently re-derived | Historical and current snapshot hashes, single test-file diff, 3-edge mesh support, gauge coboundary, canonical transport cancellation, exact compiled artifact |
| Non-vacuity checked | Original/gauged atlases distinct, raw steps +1/−1/−1, two-edge negative rejects; original seven untouched; runtime pending |
| Prior obligations discharged/carried | RA-150.3 static/CB34 compile discharged; RA-150.4 + 19 inherited RED and remaining obligations carried to TB35/owners |
| Stable accounting | 66/17/49 debt1, CP2 accepted 491/491; TB32 481/500 candidate, 19 RED |
| New candidates/obligations recorded | No new stable regression; unchanged seven remain TB35 runtime obligation in manifest |
| ORIENTATION currency line | CB34-REV 2026-10-24 |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7 updated in place; §4 no witness state changed; §8 existing fixture-invalidity pattern, no new lesson |
| CHANGELOG | CB34-REV entry added |
| ROADMAP | n/a: M6 CP3 still active; no checkpoint changed |
| Selector manifest | n/a: 497 untouched; TB35 auxiliary 13-case manifest is not a selector update |
| LESSONS | Existing §2/4/6 invoked; no new generalized pattern |
| Consolidation under CLEAN_UP_POLICY | no obsolete durable file deletion or transcript duplication; prior evidence retained |
| Successor frozen | `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY`; 13 exact identities and falsifiers in manifest/this review |
| Turn boundary held | static review only; no test/benchmark/build/production/fixture/selector changes |
| review_check.py boundary | exit 1 in verified source snapshot lacking `.git`: Git-history-derived durable rewrite baseline checks unavailable, current-tree/selector checks PASS; **not** reported as full PASS |
| `STATUS` lifecycle maintained | Entry beacon before review, final direct-write after verified document publication |
| Pushed to origin, branch in sync | Drive apply run `40114015503` succeeded; result `12568026161` verified (ZIP SHA-256 `b153f2f6eed60ec91878957566ad23da8b7a3dbecde5636b76cd5189c6a63719`), applied commit `3d36c809b09f48c0879b64c651ec16495fb253f1`; GitHub compare confirms exactly six intended docs, no source/test/selector modifications; Drive staging deleted. No local `.git` in verified snapshot, therefore no claim of `git status -sb` clean sync |
