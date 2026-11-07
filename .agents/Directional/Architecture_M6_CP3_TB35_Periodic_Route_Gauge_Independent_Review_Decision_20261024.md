# TB35-REV — periodic negative ingress authority (2026-10-24)

**Turn:** `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY-REV`. **Decision:** the immutable TB35 execution is mechanically valid; **reject promotion** of the seven-case recovery and of M6-CP3. The two REDs are genuine, and their first cause is **negative-oracle input authority not reaching the checked A4 producer**, not an observed rejection of a malformed *authoritative* A3 transition. This does **not** license changing either frozen test or weakening fail-closed production semantics. Review only; no code, tests, selectors, compilation or benchmark execution.

## Independent primary-evidence verification

- Exact TB35 run [40116807908](https://github.com/akashskypatel/Directional/actions/runs/40116807908), result artifact `12569985565`: outer ZIP SHA-256 `155ae1c43c7c83b43decf43ba5b8a711860cf00f304e9f975a0c552a26e1309e`, **18/18** internal `SHA256SUMS` checks, 13 manifest rows and 13 unique fresh-process terminal raw logs, **11 PASS / 2 RED**, 0 missing/skip; `postflight=true`, `compile=false`, `relink=false`, `benchmarks=false`, `selector_mutation=false`.
- Original frozen 13-case manifest SHA-256 `d67e503db14f2cb1ae978482665057372edd2e56d7763cd38288469174e75af8` recomputed from repository snapshot. Result ledger matches all 13 ordered test/filter identities; no test selected twice, each process selected one test. `execution-boundary.json` and `immutability.json` independently name CB34 semantic source `d5fc8f22fd309ba90ad1fd7b4fbdc3491a5a8f7d`, package `12566907246`, and package ZIP `ca5c490bae2d65f9c043636c285d29edcfe5695b9334c24edcc281fac26c6a17`.
- Source snapshot run [40118474680](https://github.com/akashskypatel/Directional/actions/runs/40118474680) at `0036b43a8a6fed38d0826fd15f2de55f9269b60a`, source archive SHA-256 `f2a347f37d678b6ac8cad923ab6939b46907cb11c4fc3fc77a8fca89f292fe91`, verifies source materialization. GitHub commit comparison from CB34's exact semantic SHA to snapshot shows **no** `src/`, `include/`, `tests/`, fixture, selector or build-source changes: later commits affect documentation, TB35 harness/dispatcher, STATUS and snapshot marker only. Thus inspected source/test logic is the compiled candidate logic.
- Recomputed accepted selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` and frozen manifest hash. Selector497 remains unchanged; no 497-case suite or accepted-prefix execution claimed.

## Independently derived cause and owner

1. `tests/SurfaceCellsPhase10Tests.cpp`, `build_periodic_route_network_with_source_atlas` (near line 4419), builds `FieldTransportAtlas::make(..., sourceField)` and supplies that atlas in `options.fieldTransportAtlas`; `tracingField` is passed separately to `build_surface_cell_network`.
2. At the **cross-field overload** in `src/geometry/SurfaceCellTracing.cpp` (near line 21167), when `options.fieldTransportAtlas != nullptr`, it obtains axes from `tracingField` but forwards **null** for `edgeMatching`, `edgeEffort` and `edgeTransitions`. The periodic-annulus producer derives transitions from `options.fieldTransportAtlas`. Its legacy matching/provenance ingestion is therefore intentionally inactive for this authoritative path.
3. `selector:191` corrupts only `tracingField.edgeTransitions[*].sourceEdge=-1`, retaining a valid `sourceField` atlas. The corruption is invisible to A3/A4 checked transitions. `raw/3.log`: actual `Produced`/`None` vs frozen `Rejected`/`PeriodicHolonomyMismatch`, first assertion at test line 4824, followed by the failure-helper exception.
4. `selector:192` changes only `tracingField`'s signed edge matching from 1 to 2; its independent test helper computes raw rotation +1 from that edited field, while A3 still uses the **balanced** `sourceField`. A4 sees the unchanged atlas and therefore a zero canonical route rotation. `raw/4.log`: actual `Produced`/`None` vs frozen `Rejected`/`PeriodicHolonomyMismatch`, first assertion at line 4665. The helper's nonzero rotation is **not** evidence that a nonzero A3-owned rotation reached A4.
5. **First causal boundary:** split input authority at `build_surface_cell_network(CrossFieldResult, ..., options)`; the negative mutations are discarded before authoritative periodic holonomy validation. **Semantic decision still owed:** whether raw/atlas disagreement must reject at ingress, or whether the negatives must be constructed as valid A3-owned typed defects upstream of A4. This is not a proven A4 periodic-algorithm error, nor sufficient to declare the immutable negative assertions invalid. No post-hoc retune is authorized in this review.

## Positive outcomes and non-vacuity

- Original selectors **189, 190, 193, 194, 195** PASS; face-gauge oracle and both atlas guards and three factory controls PASS. The face-gauge oracle checks distinct source atlases, three nonzero raw steps and the invalid two-edge-only S1 rejection: this provides meaningful A3 invariance evidence. The reverse and face-row cases exercise independently different geometry/face-order configurations.
- **Limitation:** selector189 changes only raw `matching` by ±4, and selector190 substitutes a legacy field without `edgeTransitions`, while the supplied atlas is valid and unchanged. Because the overload ignores those legacy containers, PASS alone does **not** prove A4 consumes/normalizes their representations. Treat their claimed legacy-path sensitivity as non-vacuously **unproved**, not as accepted migration coverage.
- Selectors193–195 are limited to their original assertions; none supplies a corrupt *authoritative* A3 periodic route. Passing unrelated guards cannot discharge 191/192.

## Classification, obligations and exactly one next turn

- **RA-151.1 candidate/non-stable (new):** frozen selector191/192 invalidating a non-consumed legacy input while retaining an independent valid atlas. Mechanism identified; normative ingress/rejection contract unresolved. No accepted-green loss or stable event. Retain both RED as unsatisfied; never remove tests, weaken assertions, substitute a different source atlas silently, or claim product success from the focused 11 PASS.
- **RA-151.2 candidate/non-stable (new):** selector189/190 are insufficient as independently discriminating normalization/legacy migration oracles on atlas ingress. Preserve their actual PASS, but withhold that semantic credit.
- **RA-150.3** three-edge gauge static and compile evidence remains accepted; **RA-150.4** original seven-case runtime gate partially discharged (5 PASS, 2 RED) and carried to ingress Definition; **RA-146.2/4**, **RA-45.4**, `G4-B002`, periodic A4/A6, untyped seven and `DIAG-RETAIN` carried unchanged. TB32's 19 inherited RED remain full-census authority, including 191/192.
- Frozen accounting: **66 events / 17 categories / 49 recurrences**, debt **1**, accepted M6-CP2 **491/491**, TB32 candidate **481/500** (19 RED), RP-01 open, RP-02 unreached, selector497 unchanged; no M6-CP3 promotion.
- **Exactly one successor:** `M6-CP3-DEFN-RP01-PERIODIC-INGRESS-AUTHORITY` (DEFN, runtime-free). It must decide the single-writer contract at the cross-field/atlas ingress and derive a checked, falsifiable *authoritative* negative for invalid crossing provenance and nonzero periodic rotation, with the source of every consumed transition identified. Precommitted stop/falsifiers: if either negative still mutates only ignored containers, if the A3 local-cycle validator rejects before A4 rather than producing a valid adversarial atlas, if any positive is only an unchanged-atlas no-op, or if accepting the plan would alter frozen selectors/relax the accepted gate, **stop for independent semantic adjudication**. Only after acceptance may a separate Code + Build change production or tests; no next CB automatically authorized.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; 497 frozen/unmodified |
| Decisive claims independently re-derived | Outer and 18/18 internal artifact digests; manifest hash; 13 raw process rows; atlas ingress cross-field overload and both negative test bodies |
| Non-vacuity checked | A3 three-edge gauge and two independent tamper guards nontrivial; 189/190 legacy A4 sensitivity is *not* proved; 191/192 mutations discarded |
| Prior obligations discharged/carried | RA-150.3 retained; RA-150.4 partial; RA-146.2/4, RA-45.4, G4-B002, periodic A4/A6, untyped seven and DIAG-RETAIN carried |
| Stable accounting | 66/17/49 debt1; CP2 491/491 accepted; TB32 481/500 candidate/19 RED |
| New candidates/obligations recorded | RA-151.1 and RA-151.2 candidate/non-stable in tracker; Definition owns resolution |
| ORIENTATION currency line | `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY-REV` / 2026-10-24 |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7/§8 revised in place; §4 unchanged since no witness acceptance changed |
| CHANGELOG | TB35-REV entry added |
| ROADMAP | n/a: M6 CP3 and milestone gates unchanged |
| Selector manifest | n/a: no selector edit or acceptance |
| LESSONS | Existing §2, §3, §6 sufficient; no new global rule asserted |
| Consolidation under CLEAN_UP_POLICY | No superseded current authority safely foldable; TB35 current report and original evidence retained. Historical document deletion deferred to preserve index/evidence. |
| Successor frozen | `M6-CP3-DEFN-RP01-PERIODIC-INGRESS-AUTHORITY`, with explicit falsifiers in this decision and handoff |
| Turn boundary held | Review only: no code, test, selector, fixture, build or runtime change |
| review_check.py boundary | snapshot lacks `.git`: content/selector checks pass, historical rewrite ancestry fails; **full gate not passed**, independently checked GitHub comparison establishes no code/test/selector drift |
| `STATUS` lifecycle maintained | Initial direct beacon recorded; final direct beacon must follow all completed remote documentation writes |
| Pushed to origin, branch in sync | Only claim after verified Drive apply / connector commit; no local `.git` available for `git status -sb` |
