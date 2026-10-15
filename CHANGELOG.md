## 2026-10-15 — RA-65 frozen: the endpoint faces were never measured, RA-64.6 withdrawn; the endpoint-authority specification accepted with gate C suspended and two vacuous conjuncts struck

- Architecture Review only (`M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC-REV`), adjudicating one turn; no source, test, selector, binary, harness, workflow, benchmark or ledger-count change, and no Directional binary executed.
- `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` **ACCEPTED WITH AMENDMENT**. Snapshot run [38765685488](https://github.com/akashskypatel/Directional/actions/runs/38765685488) `success`, `headSha e87b7a3ad`, artifact `11989475541` present (24,087,190 bytes), log recording `event_sha = snapshot_sha = final_sha` and `snapshot_file_count=5640`. **Tree identity re-derived:** `src` `76a12d4053a5…`, `include` `790328c2…`, `tests` `cbef8d5e…` and the blob `src/geometry/SurfaceCellTracing.cpp` `6605c9f9…` are byte-identical at the packaged semantic source `16c3134c0`, at `e87b7a3ad` and at HEAD, so every line citation applies to the measured package. Two files changed in the whole turn. Charged under RA-61.5: "5640/5640 source hashes" is a **file count** presented as a verification ratio — the log verifies no hashes.
- **Principal finding — the reviewer invented the endpoint faces.** The probe emits `a2bProbeCarrierPresent`, `a2bProbeFailure`, `a2bProbeFirstFailedCondition`, `a2bProbeFromSourceVertex`, `a2bProbeToSourceVertex` and the two `append_interval` blocks, and **no face anywhere** in `src/geometry/SurfaceCellTracing.cpp:19395-19477`. Source vertex 4 belongs to six fixture faces (`0,1,3,4,6,7`) and `carrier-orientation` fails for any attachment pair other than `(0,3)`/`(3,0)`, so `{0,7}` was one reading among many, chosen without warrant and reported as measured. **RA-64.6 is withdrawn in full**; **RA-64.4's conclusion survives** — a face-pair mismatch firing first is what `carrier-orientation` means, and it was measured — **its illustration does not**. The specification identified this at its own line 15 and is credited; second consecutive turn to correct the reviewer on the record.
- **New lesson RA-65.4 — an explanatory instance is not a measurement: a mechanism that *would* produce the observed value is not the mechanism that *did*.** Fifth after RA-61.5 (provenance), RA-61.7 (satisfiability), RA-63.10 (event counting) and RA-64.12 (reachability): **uniqueness**.
- **The RA-64.6 answer was correct and the bytes say it more strongly.** `assign_open_front_boundary_authority` cannot silently omit a carrier: `:12570` iterates every segment, `:12576-12591` derives the carrier from that segment's own face and unsupported corner, `:12594-12597` requires the segment's face to be incident to that carrier, `:12641-12644` flushes the run on a carrier change, `:12645-12647` rejects a nonconsecutive repeat, `:12669` flushes the tail, and every failure path returns `InvalidFrontBoundaryAuthority`. A two-carrier path yields two steps or no front.
- **Amendment 1 — gate C suspended: it names a witness no producer publishes.** The A3 product is `SurfaceHardRailFieldTransition` (`include/directional/geometry/SurfaceCellTracing.h:1482-1489`) — one source edge, two faces, one quarter turn — and no vertex-keyed transition record exists in `include/` or `src/`; every `vertexStar*` symbol is a diagnostics field (`include/directional/diagnostics/RemeshDiagnostics.h:459-477`). Gates A, B and D stand.
- **Amendment 2 — two vacuous conjuncts struck.** Gate A's "exactly reciprocal endpoint ordinals" cannot be false: `:17073-17079` mints `from_integer(ordinal)`/`from_integer(ordinal + 1U)` forward and `:17095-17101` `from_integer(ordinal)`/`from_integer(ordinal - 1U)` reverse, making reciprocity a construction identity — stronger than RA-64.5's measured 44/44. "Identical support piece" is equally empty because `:17051` rejects any `supportPieceIndex != 0U`. The per-endpoint exact parameter conjunct is kept.
- **The exposure the contract asks for is a type change.** The exact `FieldExactRational` parameter resolved at `:17047-17060` is cast to `double` at `:16791-16792` into a `SurfaceTracePoint` that is only `{int face; Eigen::RowVector3d barycentric;}` (`SurfaceCellTracing.h:90-93`), and `SurfaceSharedBoundaryInterval` (`:1418-1428`) publishes the breakpoint **index**, never the parameter. Recorded, not escalated: declining to design the type in a Definition turn was correct. The document's citation of `GlobalConformityBaselinePlan::breakpoint_location` is accurate (`GlobalConformityBaseline.h:181`, `:216`).
- **Reopened and recorded as backlog loci.** `append_point` silently drops a point on a `1.0e-10` UV-proximity test and returns `true` (`:17032-17036`) while the interval is pushed unconditionally (`:17081`, `:17103`), so points and intervals can desynchronize upstream of the cleared publisher — not demonstrated for the measured 44. `assign_open_front_boundary_authority` decides carrier identity, run viability and segment continuity in doubles against `constexpr double tolerance = 1.0e-9` (`:12507`, `:12578-12579`, `:12539`, `:12655`), so `routeLength = 1` is exact only up to that tolerance.
- **New structural locus.** `edge.from = cell.corners[side]` and `edge.to = cell.corners[(side + 1) % 4]` at `:13034-13035`, `:14774-14775`, `:17345-17346`: the endpoint points come from the corner array, the route from `cell.boundaryPaths[side]` whose segments are forced incident to their carrier at `:12594-12597`, and **nothing reconciles the two**.
- Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497 — unchanged; no promotion. The 44 RED remain the `R4-VIN-01` baseline for `16c3134c0`, never a comparand. `RP-01` located with three expressions, one now in question, not repaired; `RP-02` unreached; `RP-03` satisfied and exemplified; `PROCESS-01` tooling residual discharged. RA-61.9 withdrawn, final. RA-64.6 withdrawn, final. Successor **`M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE`**.

---

## 2026-10-15 — RA-64 frozen: the gate that fails first is a third expression of the same granularity error; vertex 4 and 2 confirmed, the reviewer's condition prediction falsified, specification authorized

- Architecture Review only (`M6-CP3-TB3-R4-PROBE-HARVEST-REV`), adjudicating **two** turns; no source, test, selector, binary, harness, workflow, benchmark or ledger-count change, and no Directional binary executed.
- `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` and `M6-CP3-TB3-R4-PROBE-HARVEST` **BOTH ACCEPTED**. Harvest run [38756316813](https://github.com/akashskypatel/Directional/actions/runs/38756316813) `success`, artifact `11982824436` present; the harness SHA-256 recomputed on disk (`bec126c4b4fc…`) is **byte-identical to the reported value**. Artifact-only against the pre-existing immutable package `11976790988` at semantic source `16c3134c0`, already proven byte-identical to HEAD's `src` tree at RA-63.1. **44/44 executed, 44 RED, zero missing**, three `cmp` immutability checks and a postflight manifest clean.
- **The content floor is verified by simulation, not by reading.** Four throwaway-worktree simulations, nothing committed: an **equal-size whole-file overwrite** (marker retained, `## ` sections 302 → 1) passes the line floor `4502 >= 4502` but **FAILS the heading floor `1 >= 304` — the RA-63.7 defect is CLOSED**; a legitimate prepend passes; **three headings replaced with the line count unchanged FAILS `301 >= 304`**, stronger than specified; and a rewrite preserving both counts and all heading text **still passes** — the honest residual. All six observed integrity events collapsed the file and are caught. The tracker exemption is gone (`tools/review_check.py:238`), both floors assert `> 0` so a total read failure cannot pass vacuously (`:206-211`), the consumed Drive descriptor is a no-op, and the implementation **improved on the specification** by deriving both floors from one blob read per revision. **`PROCESS-01`'s tooling residual is discharged for every observed failure mode**; the remaining shape needs per-section content hashing and **this Review declines to mandate it**.
- **The reviewer's recorded prediction was half right and half wrong.** Subset A source vertex **`4/4` CONFIRMED**; subset B **measured `2/2`** — *measured, not assumed*, discharging the standing prohibition; but the predicted first failed condition `one-hot-carrier-junction` is **FALSIFIED** — all 21 report **`carrier-orientation`**. `one-hot-carrier-junction` is ladder rung 4 and all 21 stop at rung 3: the prediction named a value without checking that execution would ever reach the rung producing it. New lesson **RA-64.12 — a prediction must name the rung at which it will be observed, not only the value it will take**, fourth after RA-61.5 (provenance) and RA-61.7 (satisfiability).
- **Principal finding — a third expression of the same granularity error, re-derived from the fixture with no run.** `oriented_carrier` (`src/geometry/SurfaceCellTracing.cpp:19106-19114`) yields a value only when `{from, to}` **is** the carrier record's own face pair. Recomputing `make_disconnected_rectangular_feature_pair_mesh` (`tests/SurfaceCellsPhase10Tests.cpp:223-264`) gives edge `(1,4) -> faces {0,3}` and edge `(4,7) -> faces {4,7}`; the measured endpoint faces are **{0,7}**, so **face 7 is not incident to the carrier edge at all**. `oriented_carrier` is **structurally unsatisfiable** for subset A. Three expressions now sit in the same rejecting conjunction: rail-level terminal set ← carrier-edge question (never reached for the 21), edge-record interval ← endpoint question (reached and satisfied by everything), and **a single carrier edge's face pair ← junction-straddling endpoint faces — the actual first failure for 21 of 44.** This **reorders the repair**: the terminal-contact set is not the first thing to fix.
- **The interval witness is satisfied 44/44** — both intervals present, equal spans (`3` in 38, `2` in 6), exactly reciprocal lossless ordinals (`0/1 → 1/1` vs `1/1 → 0/1`; `3/1 → 4/1` vs `4/1 → 3/1`). RA-63.5 argued the witness *cannot* pin the point; the measurement shows it **does not discriminate anything**. RA-61.9 would have admitted **the 23** on a warrant equally true of the 21 it still rejects, with the work done by **interiority, a double comparison**, while an exact rational was presented as the justification. **RA-61.9 withdrawn, final.**
- **New: the route under-reports the front's extent.** The route reports one step (carrier `(1,4)`) while the endpoint faces `{0,7}` require two carrier edges, refining RA-62.8. Two readings stay open and the measurement decides neither: the publisher cut a run that should have been two steps (under which the RA-59 recipe may already be latently satisfied by the geometry), or a single-step route may legitimately carry endpoint points outside its carrier. **The first question for the specification rung, to be answered from the publisher's bytes, never inferred from the type.**
- Conduct recorded as credit: the harvest reported a result **contradicting the reviewer's own prediction** without reconciling or relabelling it, kept 405 separate, called its RED set an `R4-VIN-01` baseline, and deferred the successor to independent Review; the content-floor turn **disclosed** a Drive transport failure (`container_session_unavailable`) and its byte-divergence caveat unprompted. One beacon defect: `Status: IN_PROGRESS` with a **self-referential successor**, worse than the reasoned `UNKNOWN` accepted at RA-63.13 — an encoding failure, closed here.
- **The specification is authorized; the code still is not.** `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` may produce a specification and nothing else. Binding: **every proposed predicate must carry its satisfiability witness AND its reachability witness against the measured 44** — which identities it admits, which it still rejects, and at which rung each is decided.
- Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497 — unchanged; no promotion. The 44 RED are the `R4-VIN-01` baseline for `16c3134c0`, never a comparand. `RP-01` located with three expressions, not repaired; `RP-02` unreached; `RP-03` satisfied and exemplified; `PROCESS-01` tooling residual discharged. Successor **`M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC`**.

---
## 2026-10-15 — RA-63 frozen: an edge-level witness cannot identify an endpoint; RA-61.9 withdrawn, `RP-01` shown to be a pattern, and the new content guard proven incomplete

- Architecture Review only (`M6-CP3-CB2-R4-PREDICATE-SEPARATION-REV`); no source, test, selector, binary, harness, workflow, benchmark or ledger-count change, and no Directional binary executed.
- `M6-CP3-CB2-R4-PREDICATE-SEPARATION` **ACCEPTED**. Compile authority re-derived from object hashes rather than the report: the `src` tree `76a12d4053a5…` and `include` tree `790328c2bcff…` are byte-identical at the claimed semantic source `16c3134c0`, at run [38743048456](https://github.com/akashskypatel/Directional/actions/runs/38743048456)'s `headSha 276fc267c` and at **HEAD**, the only commit between them touching `agent-dispatch-request.json`. Run `success`, artifact `11976790988` present, eight targets, GMPXX/GMP linked, `runtimeExecution=false`, preflight/build `0/0`. `tests`, `benchmarks`, `cmake`, `.github`, `include` byte-unchanged from `700d6418f`. A compile is not a restoration (LESSON 160).
- **Decision-neutral by construction**: every added line sits inside the post-decision diagnostic block (`src/geometry/SurfaceCellTracing.cpp:19360`), after both certificate calls (`:19354-19359`), and either declares a block-local or streams into `endpointEvidence` — no `return`, no predicate write, no epsilon, no relaxation. Both mandated payloads landed: exact one-hot source-vertex identity (retiring the RA-62.3 hand derivation permanently) and lossless exact-rational interval ordinals via `exact_numerator()`/`exact_denominator()` (`FieldTransportAtlas.h:516-517`) whose `EInt::to_string()` exists on both backends (`ENumberGMP.h:61`, `BigInteger.h:401`).
- **Principal finding — an edge-level witness cannot identify an endpoint, so RA-61.9 is WITHDRAWN.** `SurfaceFrontEdge` (`include/directional/geometry/SurfaceCellTracing.h:1545-1579`) carries two endpoints (`:1549-1550`) and exactly **one** `sharedBoundaryInterval` (`:1572`) and one `railId` (`:1568`); `endpoint_certificate` is called twice with `first`/`second` captured by reference and identical, so the interval-reciprocity conjunct **evaluates the same at both endpoints** — it pins the edge pair, never the point. RA-61.9 proposed resting endpoint identity on precisely that witness, which would leave the interior branch with no point-level exact evidence at all. **The dead gate fails closed; RA-61.9 would fail open.** Remedy and falsifier (ii) both withdrawn; falsifier (ii) needed the record's field list, not a run.
- **`RP-01` is a recurring construction habit, not one site.** Two granularity mismatches sit inside the single `if (!terminalVertex)` branch: rail-level terminal authority answering a carrier-edge question (RA-62.5, `SurfaceCellTracing.h:1530-1535` consulted at `:19213-19220`) and edge-record-level interval authority answering an endpoint question (new). **Widening an existing published set cannot repair either**; the eventual repair must add vocabulary at the granularity the question is asked at — per-interval terminal contacts (rail intervals already consulted at `:12610`) and per-endpoint exact parameters. No repair authorized.
- **The RA-62.2 integrity fix is a real improvement that still fails its own acceptance test.** The floor is now `max` over committed history (`tools/review_check.py:196-202`), so `boundary` **does** now detect a committed overwrite — the RA-62.2 hole, closed — and the handoff and ORIENTATION joined `ledgers` coverage. But simulated in an isolated worktree: a 4,468 → 21 truncation **FAILS** the gate, while an **equal-size whole-file overwrite** (4,468 filler lines, marker retained, `## ` sections 302 → 1) returns **`ALL CHECKS PASSED`**. That is `ORIENTATION.md:1853` one level up — **a guard that counts lines does not protect content, for the reason a guard that counts markers does not.**
- **The remedy, satisfiability proven before mandating it (RA-61.7):** a `## `-heading high-water floor symmetric with the line floor. Measured satisfiable today (handoff 302/302, ORIENTATION 105/105, tracker 651/651), it catches the equal-size overwrite and all three historical tracker destructions (`f7add683` 611→1, `0e1909d3` 629→1, `b90c0f84` 648→1). Heading-*set* inclusion was tested and **rejected as unsatisfiable** (28 headings differ historically because superseded `## CURRENT …` headings are legitimately reworded). Separately, the tracker's exemption from zero-tolerance (`:224`) is **unjustified and inverted** — it leaves the one file destroyed three times as the only protected file permitting a silent ~1,300-line deletion, and the tracker has had **zero** shrinks in the 0–10% band across its whole history.
- **New lesson RA-63.10 — a count of recorded events is not a count of events.** RA-62 called the handoff overwrite the fourth integrity event; the bytes show at least **six**, including **`f7add683` (tracker 11,683 → 8) recorded in zero durable documents** and `0e1909d3` (12,147 → 11) cited for content but never flagged as a destruction. The undercount is the reviewer's: events that had been written down were counted instead of events in the bytes — LESSON 171 turned on the reviewer's own ledger. Filed against the pre-existing `PROCESS-01`; does not increment the recurrence counter.
- Also recorded: one narrow ladder-ordering divergence (`carrier-absent` before `invalid-source-face`, inverting `:19134`/`:19140`), self-mitigated because `a2bProbeFailure` is on the same line, with its reorder **deliberately deferred** to avoid invalidating the packaged compile; the structural hazard that the ladder is an independent second transcription of the acceptance conjunction; `one-hot-carrier-junction` accepted as a good unrequested call naming the RA-62 mechanism in the instrument; `Successor: UNKNOWN` accepted this time because it came with sound reasoning that refuses to self-authorize; and a consumed `drive_apply` descriptor still committed, leaving the dispatch channel non-idempotent.
- Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497 — unchanged; no promotion. `R4-VIN-01`: `16c3134c0` is a **new semantic source**, so artifact `11967601999` is a baseline, never a comparand. `RP-01` located (now a pattern) but not repaired; `RP-02` unreached; `RP-03` satisfied; `PROCESS-01` open with a proven remedy. Successor **`M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR`** (instrument-only, Python-only, no compile), then `M6-CP3-TB3-R4-PROBE-HARVEST` at `16c3134c0`.

---
## 2026-10-15 — R4 A2b predicate diagnostic separation compiled; runtime acceptance unchanged

- `M6-CP3-CB2-R4-PREDICATE-SEPARATION` Code + Build landed semantic `16c3134c02ab3872eee77a6b9dcc9d3fc6e01b7b` from `0cb0434c8ee7ec86fdc6ab7ebd7162d713492995`. Added source-vertex and exact shared-interval ordinal diagnostics plus distinct first-failed A2b predicate reporting; RA-62.2 committed-history guard now covers handoff/ORIENTATION and high-water floors. Only `SurfaceCellTracing.cpp` and `review_check.py` changed, with no acceptance branch or selector edits. Patch SHA-256 `c6f462ff3c0b646d876904fff795d448ed4427cce2947d039619600c5d530fea`, applied by [38742750098](https://github.com/akashskypatel/Directional/actions/runs/38742750098); staged Drive file retired.
- Mandatory compile-only [38743048456](https://github.com/akashskypatel/Directional/actions/runs/38743048456) GREEN on exact semantic source; job `116449586867`, artifact `11976790988` (ZIP SHA-256 `31faf55a33c31abb60c8f34acb64ad901514de821cd6d2f3acbdcd817b1dbb36`), 28/28 manifest, 8/8 targets, preflight/build 0/0, GMPXX/GMP authoritative linker, clean source, `runtimeExecution=false`. No executable, tests, benchmarks or TB497 ran; runtime equivalence is unverified. Accepted ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen 497, PR #8 draft/open all unchanged. No successor turn ID frozen; independent artifact-only TB/Review require later authorization.

## 2026-10-15 — RA-62 frozen: the one-hot endpoint is the rail's junction vertex, a third shape with no certificate, and `RP-01` is located

- Architecture Review only (`M6-CP3-TB2-R4-CONJUNCT-EXTRACT-REV`); no source, test, selector, binary, harness, workflow, benchmark or ledger-count change, and no Directional binary executed.
- `M6-CP3-TB2-R4-CONJUNCT-EXTRACT` **ACCEPTED**, and the best-executed rung of this family: artifact-only from the pre-existing `11967601999` (ZIP SHA-256 `8b52373e…`, 50/50 manifest digests), run [38725063279](https://github.com/akashskypatel/Directional/actions/runs/38725063279), semantic `570c5173…`. Partition matches RA-61's prediction **exactly** — **23** interior-shaped, **21** one-hot, ordinal **405** distinct. It delivered the three-conjunct truth table `RP-03` demands, **refused to over-claim** the vertex identity, and **named a successor**, ending two turns of `Successor: UNKNOWN`.
- **DEFECT repaired: the handoff CURRENT section was overwritten in place** instead of superseded by prepending (4,419 → 4,411 lines); RA-61's section is restored beneath the new one. **Neither gate catches this** — the handoff is not in `ledgers` coverage and `boundary` reports `1 -> 1` because the durable-section heading survives below the replaced content. This is `ORIENTATION.md:1799` verbatim (recorded for `f6a784cf`). Fourth integrity event, second in two turns, on a **different file** from the one protected last turn: **protecting one file by name does not protect the class.** **And the remedy was already named, in exactly the form adopted at RA-61.3:** `ORIENTATION.md:1719` states that *"the effective guard is `review_check.py ledgers --base <previous-review-commit>`, which scans committed history"* and that the `boundary`-based guard *"was inert against committed overwrites"*; the same entry records that `ce9bf3cb` also overwrote the agent CHANGELOG (`0043dd4c`, 13,317 → 14 lines) and that **the first repair missed it**. `:1799` already supplies the decisive test — ***if deleting the protected content leaves the check green, the check does not cover that content*** — and already tracks the residual as **`PROCESS-01`** (`LESSONS.md` 172). This turn's handoff overwrite is a textbook instance, so the RA-62.2 mandate is filed against `PROCESS-01` rather than opened as new. No RA-61 finding was lost — all other durable docs verified byte-unchanged from `215698e0e`. Mandated first item of the next Code + Build: add the handoff and ORIENTATION to `ledgers` coverage and replace `boundary`'s self-relative durable check with a monotone high-water floor.
- **The vertex the logs declined to name is 4, derived exactly from the fixture.** `make_disconnected_rectangular_feature_pair_mesh` (`tests/SurfaceCellsPhase10Tests.cpp:223-264`) gives face 0 = `(0,1,4)` and face 7 = `(4,8,7)`, so the one-hot probes `0:(0,0,1)` and `7:(1,0,0)` both designate **vertex 4** — the interior junction of the rail chain **1–4–7** (`:6315-6318`, terminals `{1,7}`). Recomputation reproduces all four measured truth values exactly, and `railEnd[7]=0` is the first **measured** confirmation of RA-60.6.
- **Mechanism named: a junction-terminated front, a third shape with no certificate at all** — not a terminal front (no exact corner at 1 or 7), not an interior front (strictly one-hot). RA-60.2 offered this configuration as reassurance that RA-41 stayed out of scope; it is **the actual failure mode of 15 of 44 identities**, and on the shared evidence shape almost certainly all 21. **RA-41's junction clauses are no longer dormant.**
- **Principal finding — `RP-01` in its exact canonical form.** `SurfaceHardRailTerminalContacts` is keyed by **rail** with two endpoints per rail (`include/directional/geometry/SurfaceCellTracing.h:1530-1535`), yet `endpoint_certificate` tests a **carrier-edge** endpoint against that rail-level set (`src/geometry/SurfaceCellTracing.cpp:19214-19217`). For a multi-edge rail, a front occupying one carrier edge **structurally cannot** satisfy it at the junction end. No per-interval terminal vocabulary exists although rail intervals are already consulted by the publisher (`:12610`). **Two authority domains conflated in one predicate** — located precisely, with a measured population, for the first time.
- **RA-59.9 picked the wrong shape for half the population, and the error is the reviewer's.** The non-terminal end was specified as *interior to the carrier edge*; in 21 of 44 it sits *exactly at the carrier's other vertex*. RA-60 built and verified a certificate for the 23-case shape whose gate is dead (RA-61.6) while the 21-case shape got nothing. **The locus count collapses from ≤22 to 2**: all 23 interior cases share one probe pair and all 21 one-hot cases share another.
- **A hypothesis discarded before it entered the record:** the publisher's run-cutting does **not** cap `routeLength` at 1 — `observedSteps` accumulates one step per run across the whole front path (`:12505`, `:12546`, `:12566`, `:12672`, `:12684-12685`), so a two-carrier front **would** exercise the junction loop. **The RA-59 recipe stands**, and `routeLength = 1` is a fact about the traced front, relocating the open question upstream to A1/A2a.
- Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497 — unchanged; no promotion; `RP-01` located but not repaired, `RP-02` still unreached, `RP-03` satisfied. Successor **`M6-CP3-CB2-R4-PREDICATE-SEPARATION`**, diagnostic-only, scope re-ordered by RA-62.9 to **(b)** emit the actual one-hot vertex identity, **(a)** emit `sharedBoundaryInterval` presence and exact ordinals, then the predicate-string split.

---
## 2026-10-15 — RA-61 frozen: the interior acceptance path is unsatisfiable, the mechanism claim was over-general, and a destroyed ledger is restored

- Architecture Review only (`M6-CP3-TB1-R4-INTERIOR-WITNESS-REV`); no source, test, selector, binary, harness, workflow, benchmark or ledger-count change, and no Directional binary executed.
- `M6-CP3-TB1-R4-INTERIOR-WITNESS` **measurement ACCEPTED as execution evidence**: run [38725063279](https://github.com/akashskypatel/Directional/actions/runs/38725063279), result artifact `11967601999`, semantic `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`, `planned=45 executed=45 red=45 missing=0 postflight=true exit=0`, full immutability. **RA-60.12 obeyed** (all 45 ran past the first RED, verdict from counters), no predicate relaxed, no epsilon added, successor name correctly refused rather than invented, ordinal 405 kept distinct.
- **REVIEW_BLOCKER repaired: `b90c0f84e` destroyed `Regression_Root_Cause_Tracker.md`, 12,949 → 6 lines.** Restored from `cef55bdd0` with the measurement section retained; floor frozen as data (≥12,949 lines, ≥13 durable-marker occurrences, ≥648 `## `). Third occurrence of durable-ledger destruction; an integrity recurrence that does not increment the regression recurrence counter.
- **The reviewer was running the wrong gate.** `review_check.py boundary` passed over the deletion because its durable check is working-tree-vs-`HEAD` (`:184-196`); `:48` documents this and names `ledgers`, which reports `[FAIL] … b90c0f84 12949->6`. Standing rule: every Review turn now runs **both**. Both lessons were already written down and recurred anyway (`ORIENTATION.md:1719` = `LESSONS.md` 176 for `ce9bf3cb`, 9,837 → 21; `:1799` = "a guard that counts markers does not protect content"), so the monotone high-water fix is mandatory, not advisory.
- **RA-60.10's prediction is FALSIFIED and the error is the reviewer's**: probes are 0.8/≈0.2 from `options.lengthRatio = 0.2` (`tests/SurfaceCellsPhase10Tests.cpp:6312`), not the asserted binary-exact 0.75/0.25. Outcome is branch **(C)**. The prediction failed; the pre-registered decision rule worked. New LESSON: **an expected value whose provenance is unstated is not a prediction.**
- **Principal finding — the interior acceptance path is unsatisfiable.** Exact arithmetic on the measured bits: face 0's nonzero pair sums to `1 + 2^-55`, face 3's to exactly 1, and the ≈0.2 weights differ by `2^-55`. `interior_carrier_parameter` (`src/geometry/SurfaceCellTracing.cpp:64-89`) returns `nullopt` for face 0 under **every** corner assignment, so `same_interior_carrier_point` fails at the first chart in all 23 cases. `first + second == one` demands closure that double arithmetic cannot deliver; `from_double_exact` is exact about the **double**, preserving a rounding error and testing it for equality. RA-60 verified faithfulness to an unsatisfiable specification — the specification is the reviewer's, and the implementation is not at fault. New rule: **verify a predicate for satisfiability, not only for faithfulness.**
- **An exact witness already exists and the implementing agent had already wired it**: `SurfaceTracePoint` holds only doubles, but `SurfaceSharedBoundaryInterval` carries `FieldExactRational` ordinals, already required equal-span/reciprocal/equal-`railId` at `:19231-19238`. The unrequested check RA-60.2 merely "adopted" is the load-bearing one.
- **RA-59.9's single-mechanism claim is PARTIALLY FALSIFIED: ≥2 shapes, 23 + 21.** 21 of 44 probe one-hot — a mesh vertex, not an interior point — and are rejected by both branches, a separate undiagnosed family the repair could not have fixed. This corroborates RA-59.11's ≤22-loci bound while refuting the mechanism's breadth. The deciding conjunct for those 21 is **already captured** in artifact `11967601999` (`corner[v]`/`railEnd[v]`, `:19409-19416`) and was not reported — no re-measurement needed.
- Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497 — unchanged; no promotion; `RP-02` still unreached. Successor **`M6-CP3-TB2-R4-CONJUNCT-EXTRACT`**, then `M6-CP3-CB2-R4-PREDICATE-SEPARATION` (diagnostic-only, now authorized by branch (C)).

---
## 2026-10-15 — R4 interior-witness artifact-only Test + Benchmark

`M6-CP3-TB1-R4-INTERIOR-WITNESS`: immutable source `570c5173…`, compile package 11964478813, dispatcher ebd5f1fc, test run [38725063279](https://github.com/akashskypatel/Directional/actions/runs/38725063279), result 11967601999. 45/45 independently selected identities RED (39 historical plus six supplemental), zero missing, 50/50 evidence hashes, full postflight. RA-60.10 branch C: repeated ambiguous `no-exact-terminal-corner` in 44, ordinal405 separate A2b failure. RP-02 and A4 not reached. No production/test edits, no compile, no TB497, no accepted restoration or stable ledger change. Required independent Review of RA-60.5 diagnostic distinction and actual cross-chart probes. Report `.agents/Directional/Architecture_M6_CP3_R4_Interior_Witness_Artifact_Only_TB_Report_20261015.md`.

## 2026-10-15 — RA-60 frozen: the interior-endpoint repair is accepted, with an encoding collapse recorded and the next measurement pre-registered

- Architecture Review only (`M6-CP3-TB1-R4-REPAIR-REV`); no source, test, selector, binary, harness, workflow, benchmark or ledger change, and no Directional binary executed. **No runtime outcome observed or claimed** (LESSON 160).
- `M6-CP3-CB1-R4-WITNESS-REPAIR` **compile ACCEPTED**: eight-target GMP/GMPXX GREEN, [run 38720128740](https://github.com/akashskypatel/Directional/actions/runs/38720128740), semantic `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`, result artifact `11964478813`, 28/28 packaged checksums, exits `0/0`, GMP ON, real `gmpxx`/`gmp`, `runtimeExecution=false`. Change surface re-derived: exactly two files, test change purely additive, Quotient/REPackage tests, `cmake/`, `benchmarks/` and all selector files untouched, no fixture geometry changed.
- **Implementation ACCEPTED as faithful to RA-59.9** on all six authentication requirements (`src/geometry/SurfaceCellTracing.cpp:19221-19241`), with `interior_carrier_parameter` (`:61-89`) exact, epsilon-free, strictly interior and canonically oriented — so a forged terminal cannot be laundered through the interior branch, and a front ending at the rail's interior junction vertex is rejected rather than absorbed. The added `sharedBoundaryInterval` reciprocity check was not specified and is **adopted**. No parallel certificate model.
- **All prohibited invariants verified intact**: `exact_corner`/`no-exact-terminal-corner` unchanged; closed-chain branch untouched; a both-interior certificate still rejected at `:8572-8576`, so a contact-less open rail remains impossible; `tests/SurfaceCellsPhase10Tests.cpp:7205` untouched; ordinal 405 untouched; no `Produced` precondition weakened.
- **Step 0 falsifier CLEARS, derived in Review rather than evidenced by the turn.** The record claimed it was checked but stated no finding and cited no anchor; the only visible trace was a rewritten contract comment at `:18975-18978`. Derived from `assign_open_front_boundary_authority:12481` + `canonical_retained_edge_parameter:12509-12530` + the run cut at `:12574-12579`: front extent is **field-determined**, cut at source-edge topology changes, never at rail terminals. The amended comment is a consequence of the selection, never evidence for it.
- **Recorded, not chased:** RA-60.5 the new refusal shares the old predicate string, making a repeat uninterpretable (conditional diagnostic-only fix); RA-60.6 the per-certificate terminal-coverage gate was necessarily dropped with no aggregate replacement, so terminal 7 can never be attached in these fixtures; **RA-60.7 the interior endpoint is structurally identical to the closed-chain endpoint shape at `:8729-8733`, so "no terminal vertex ⇒ closed chain" is now false** — latent (only the `hash_trace_network` fingerprint reads it, aliasing both to `-1`) but an `RP-01` shape needing a positive discriminator; RA-60.8 a comment asserts an invariant enforced elsewhere; RA-60.9 the first positive acceptance-half witness ever authored, with four negatives on the new predicate untested.
- **RA-60.10 pre-registers the next measurement's decision rule before it runs.** From exactly representable probes summing exactly to 1 in both charts, **the 38 `endpoint-1` identities are predicted to clear `:19241`**. (A) Produced + consumer reached; (B) a new downstream failure **does not falsify** RA-59.9 and locates the next rung; (C) the same predicate is ambiguous pending RA-60.5. "Still RED" is not evidence against the model. RA-60.11 records the `1e-9`-tolerant producer / exact consumer seam (no epsilon may be added); RA-60.12 corrects the handoff's reinstated "only until first RED" rule, retired by RA-57.8/RA-58.
- `R4-VIN-01` applies with force: the repaired package is a **new** semantic source, so every prior measurement is a baseline, never a comparand. Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497 — unchanged; no promotion. Successor `M6-CP3-TB1-R4-INTERIOR-WITNESS`, replacing the `Successor: UNKNOWN` the repair turn left.

---
## 2026-10-15 — R4 witness repair exact-source compile verified

- `M6-CP3-CB1-R4-WITNESS-REPAIR` Code + Build produced an exact source-attested interior carrier certificate for paired across-rail source charts, and a nonvacuous source-authored positive/forged-terminal negative regression. GitHub atomic semantic commit `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`; precisely two source/test files; source blob identities verified.
- Pinned GMP/GMPXX eight-target compile GREEN workflow `38720128740`, immutable result `11964478813` (ZIP SHA-256 `0e1e87a48ef090588c8675bd87bc8c7560a1ade5dbe44cac391c78e0cbe21ae5`), log `11964676618` (ZIP SHA-256 `2d44c022651e95550d6cfaabd5fda9d2f050312477a464edcfd2c97cf9b7c451`). All 28/28 packaged hashes verified; preflight/build 0/0; source SHA exact, CMake GMP on, actual generated link `libgmpxx` and `libgmp`, clean pre/during/final status, `runtimeExecution=false`. No tests or benchmarks.
- Drive `upload_file` rejected corrected Library patch bytes; native Docs export changed bytes. As a bounded transport exception the two exact content-addressed Git blobs were installed by Git tree/commit and non-forced compare-and-swap ref update. The original unheaded staged patch was not dispatched; no workflow permission or acceptance selector altered. Corrected metadata-wrapped recovery patch preserved in Library.
- RA-59.9 model selected by prior Review is **compiled, not runtime validated**; RP-02, ordinal 405, RA-41, six supplementals, historical Phase14 packaging, frozen 497 and independent Review remain open. Ledger 66/17/49 debt1, CP2 491/491, R3 403/497 unchanged. Next separately authorized artifact-only TB/Review has no frozen exact successor ID.

---
## 2026-10-15 — RA-59 frozen: the census closes the hypothesis set and the certificate model is selected

- Architecture Review only (`M6-CP3-TB1-R4-CARRIER-REV`); no source, test, selector, binary, harness, workflow, benchmark or ledger change, and no Directional binary executed.
- `M6-CP3-TB1-R4-ENDPOINT39-CENSUS` **measurement ACCEPTED** and independently re-derived: `executed=39 red=39 missing=0 postflight=true exit=0`, workflow [38687783618](https://github.com/akashskypatel/Directional/actions/runs/38687783618), result `11950303475`, 28/28 pre/post, four frozen selector hashes matched; **39/39** executed identities ∈ the 94-row R3 RED register with **zero** field mismatches in 117 comparisons; census scope SHA-256-pinned and mapfiled, so the executed set provably equals the inventory.
- **Two of three RA-57.7 hypotheses eliminated from source bytes.** (c) route truncation **withdrawn** — `routeLength` measures the front edge's own carrier extent (`src/geometry/SurfaceCellTracing.cpp:12617`, `:12574-12579`), so `1` is correct. (b) incorrect pairing **eliminated** — all 39 report locus `EndpointAttachment = 3`, never `Pairing = 1` (`:19022-19025`), so reciprocal pairing held. `step` shown to be an echo of `routeLength` (`:19329-19332`).
- **(a) selected and amended to a DOMAIN GAP.** The measured carrier is a **half-terminal front**: in 38/39 one end certified at an exact rail terminal and the other sat interior to the same carrier edge (`:19264-19269`, failing at `:19152`). `endpoint_certificate` admits only open-rail-terminal (`:19144-19152`) or typed-closed-chain (`:19072-19079`) shapes; an interior end on an open rail has none. This one mechanism re-explains every RA-58 control outcome.
- **Selected model (RA-59.9):** add a source-attested **interior carrier endpoint** shape — typed carrier key, both incident source faces (**across-rail** per RA-57.5), canonical exact intrinsic parameter on the same carrier edge, component/sheet agreement, A2a rail identity, directed A3 transport — with `exact_corner`/`no-exact-terminal-corner` (`:19131-19152`) and the closed-chain branch **unchanged and fail-closed**, at least one certified terminal endpoint still required, and `endpoints[0].terminalVertex.has_value()` (`tests/SurfaceCellsPhase10Tests.cpp:7157`) left satisfiable. A **falsifier** is frozen with a STOP: if hard-rail fronts are contracted to be cut only at rail terminals, the repair belongs upstream of `:19264` instead.
- **New: the acceptance half of the hard-rail certificate model has no witness at all.** The five tests asserting a published route certificate are all tamper/negative tests that fail at their `Produced` gate, and the junction loop at `:19335-19338` cannot execute at `routeLength=1` — so RA-41's junction/sector clauses need a front spanning two rail topologies, and `RP-02` is localized but **open**.
- **Classification corrected:** 37 reproduced carried CP2 losses, 2 reproduced in-gate R3 REDs with no accepted CP2 baseline (`cp3entry` — **inside** the frozen 497, not "in no selector" in RA-58.6's baseline-free sense), 0 baseline-free. RA-58.9 applied: 19 throwing-singleton REDs are 2 measurements, so the independent-locus bound is **≤ 22, not 39**. Ordinal 405's `endpoint-0` kept separate as an A2b provenance defect.
- New standing rule (RA-59.4): **a measured value without its expected value is not a discriminator.** Ledger 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497 — unchanged; no promotion. Successor `M6-CP3-CB1-R4-WITNESS-REPAIR`.

---
## 2026-10-15 — M6-CP3-TB1-R4-ENDPOINT39-CENSUS artifact-only measurement completed

- 39/39 exact historical A4 identities executed independently against immutable GMP compile package `11939982141`, semantic source `953f812ff1f431e3ad3af3b68a92284a7831c94a`; [run 38687783618](https://github.com/akashskypatel/Directional/actions/runs/38687783618) succeeded, result artifact `11950303475`, ZIP SHA-256 `3bce344f3a13403a830a2800fea4c47d1e7cdd53f6f3eac6629de57d70788b32`; **39 RED, 0 missing, postflight true, 28/28 pre/post integrity**; no compile, relink, benchmarks, TB497, source/test/selector modifications.
- 38 first `endpoint-1` / `no-exact-terminal-corner`, one first `endpoint-0` / `missing-terminal-or-closed-rail-provenance` (ordinal 405). All A4 open-hard-rail terminal-rejection loci; two throwing shared fixture singletons cover 19 identities and are not independent root-cause confirmations. Report and 39-identity TSV: `.agents/Directional/Architecture_M6_CP3_R4_Endpoint39_Census_{Artifact_Only_TB_Report_20261015.md,Measured_Identities_20261015.tsv}`.
- All 39 are previously RED in frozen R3 classification, so **candidate/non-stable only**, no accepted regression, no stable event/ledger promotion. Stable 66/17/49, debt 1, CP2 491/491, R3 403/497 (94 RED, 88 carried losses) unchanged. Three certificate hypotheses unresolved; next independent `M6-CP3-TB1-R4-CARRIER-REV`, repair deferred. Prior work-preservation staging initially failed `container_session_unavailable` and subsequently succeeded through Google Drive; this documentation closure uses full six-path patch transport.

---
## 2026-10-15 — RA-58 frozen: the true control bounds the carrier to OPEN hard-rail terminal certification

- Architecture Review only; no source, test, selector, binary, harness or ledger change.
  `M6-CP3-TB1-R4-TRUE-CONTROL` adjudicated: measurement **ACCEPTED**, **RA-57.8 DISCHARGED**,
  interpretation **AMENDED**, classification of one torus RED **CORRECTED**, carrier **BOUNDED**, census
  **AUTHORIZED**. Frozen as **RA-58**. Decision record
  `.agents/Directional/Architecture_M6_CP3_R4_True_Control_Review_Decision.md`.
- **Receipts re-derived:** artifact `11948572472`, ZIP SHA-256
  `2b6ac34c34ea3f0dd384f5be7a55ca9c9028328639effed3c9cc3e3c9674917f`, `executed=4 red=2 missing=0
  postflight=true exit=0`, immutability all true, manifest 28 OK → 28 OK, harness SHA-256 `9d471c49…`,
  no `src`/`include`/`tests`/`cmake`/`benchmarks` diff since `c2b3571bb`.
- **A4 production is not universally down.** Both no-interior-hard-rail identities PASS and both are
  frozen `selector449` members — `square_fixture` and a **613 ms** `cylinder_fixture` full pipeline on
  `PeriodicCut` authority. Neither is in the 94 R3 RED, so both were R3 PASS and remain green on
  `953f812f`: a positive `R4-VIN-01` datapoint. No gate credit — the frozen 497 did not run.
- **Closed-chain hard rails PRODUCE.** Zero `no-exact-terminal-corner` /
  `InvalidHardRailRouteCertificate` / `endpoint-1` in either torus log, and both torus identities cleared
  A4: `tests/SurfaceCellTransitionQuotientTests.cpp:6022` (`hasTraceNetwork`) passed before `:6023`
  failed, and `:2795` passed — guarding a `SurfacePhaseFrontProduct::make` fed
  `front.hardRailRouteCertificates()` / `hardRailTerminalContacts()` (`:2791`) /
  `hardRailClosedChains()` (`:2792`). **The checked factory accepted closed-chain hard-rail certificates
  under a Z4 gauge rotation.**
- **Carrier BOUNDED:** no hard rail → A4 green end-to-end; closed chain → A4 green, RED downstream; open
  rail with interior terminals → A4 rejected at `no-exact-terminal-corner`. Independent corroboration of
  RA-57.5: a closed chain has **no terminals**, so `exact_corner` is never taken and the torus passes. The
  three RA-57.7 hypotheses all survive and **none may be chosen**.
- **Classification corrected:** identity 3 is already one of the 94 R3 RED (`focused30` ordinal 25,
  `OTHER_FIRST_PREDICATE`, `CP2_ACCEPTED=true`, `R2-CAND-04`) reproducing R3's `:5775` assertion at
  `:6023` — a reproduced carried loss **inside the frozen 497**, now vintage-resolved. Identity 4 is in no
  selector and not in the 94 — **no baseline, therefore not a regression**, not ledger-eligible.
- **New separate obligation recorded, not chased:** A5 `SurfaceOccurrenceComplexProducer::produce` rejects
  a front that A4 produced and the factory accepted; arrangement is absent on a produced torus network.
  A5/A6/A7 backlog, not the hard-rail carrier. No probe (RA-54.7).
- **Reviewer error owned (RP-03), second of one class:** RA-57's grid conditioned on the **verdict**, not
  the **locus**, and applied naively would have inverted the conclusion. **LESSON: condition an instrument
  on the locus of failure, not on the verdict.** The executor's refusal to conflate loci is upheld.
- **RA-57.11 did not fire:** both torus REDs share a `static` fixture singleton that **succeeds**, so the
  census column must record whether the singleton constructed and the stage of first failure, not just its
  name. Merge only on a **throwing** singleton.
- Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, selector **497** unchanged. `RP-02`
  still open. Successor `M6-CP3-TB1-R4-ENDPOINT39-CENSUS` with the RA-58.10 key.

## 2026-10-15 — R4 true-control artifact-only measurement: 2 PASS, 2 RED

- `M6-CP3-TB1-R4-TRUE-CONTROL` completed all four exact tests in [run 38681907622](https://github.com/akashskypatel/Directional/actions/runs/38681907622). Immutable package `11939982141` unchanged; result artifact `11948572472`, ZIP SHA-256 `2b6ac34c34ea3f0dd384f5be7a55ca9c9028328639effed3c9cc3e3c9674917f`. 28/28 checksums before/after; 4 selected, 2 RED, none missing, postflight true. No build, benchmark, test-source edit or frozen 497 run.
- Square no-hard-rail PASS; cylinder periodic-cut/no-hard-rail PASS; closed-chain torus `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus` RED (`hasArrangement=false`); torus `M6CP3.A6UniformFaceGaugeRotationPreservesRelationOutcome` RED (`originalOccurrences=nullptr`). This disproves universal A4 failure, but does **not** show the torus failures share the open-rail `no-exact-terminal-corner` cause.
- Dedicated harness fixes the RA-57.8 orchestration defects for this rung; report `.agents/Directional/Architecture_M6_CP3_R4_True_Control_Artifact_Only_TB_Report_20261015.md`. Successor is separately authorized artifact-only `M6-CP3-TB1-R4-ENDPOINT39-CENSUS`, followed by independent `M6-CP3-TB1-R4-CARRIER-REV`. Ledger 66/17/49, debt 1, RP-02 open, 497 frozen.

## 2026-10-15 — RA-57 frozen: breadth measurement accepted from the artifact; 4/4 RED is one measured carrier; RA-56.5 resolved ACROSS-rail

- Architecture Review only; no source, test, selector, binary or ledger change. `M6-CP3-TB1-R4-WITNESS-BREADTH`
  adjudicated: measurement **ACCEPTED**, turn state **CORRECTED**, the reviewer's own control claim
  **WITHDRAWN**, RA-56.5 **RESOLVED**, repair still **DEFERRED**. Frozen as **RA-57**. Decision record
  `.agents/Directional/Architecture_M6_CP3_R4_Witness_Breadth_Measurement_Review_Decision.md`.
- **Re-derived from the artifact because no report was written.** The turn closed `IN_PROGRESS` with
  `Successor` pointing at itself; the harness exits non-zero on RED, so the runtime job concluded
  `failure` while the measurement was intact. Run `38676433923`, artifact `11946622500`, ZIP SHA-256
  `127c77580a9e77dafb1889575b8d69bdbe0271f7a3fc8041fc6c904e9918c6a3`, `executed=4 red=4 missing=0
  postflight=true`, immutability all true, manifest 28 OK → 28 OK, no source diff since `a44bbf534`.
- **4/4 RED is ONE carrier through four entries** — three files, three fixture builders, one full
  `remesh_from_raw_cross_field` entry — all `InvalidHardRailRouteCertificate` / `predicate=endpoint-1` /
  `no-exact-terminal-corner` on edge `(1,4)`. RA-56.3's `A4_ROUTE_CERTIFICATE_REJECTION` reading is now
  **measured**, satisfying RA-56.8. Rows frozen in
  `.agents/Directional/Architecture_M6_CP3_R4_Witness_Breadth_Measured_Predicates_20261015.tsv`.
- **RA-56.5 RESOLVED — the geometry is ACROSS-rail.** `faceEnds=0,2|0,3` read through the emitter at
  `src/geometry/SurfaceCellTracing.cpp:18948` puts the first front wholly inside face 0 and the second
  starting in face 3 — the two faces of edge `(1,4)`. The fronts meet at a shared **interior** point of
  the rail from opposite sides. The retained repair plan's "ordered rail interval/face-side ownership"
  vocabulary presumes along-rail and **must be amended before CB re-entry** (RA-45.2 category error,
  caught before code).
- **Field- and transition-independent.** `chi=3` vs `chi=0` on the same edge, non-constant vs constant
  field, interior parameter `0.2` vs `0.25` — identical rejection. No tolerance, parameter special case
  or transition-conditioned branch can be the repair. Recorded hazard: the two charts disagree by one ULP
  on the shared barycentric, so a bit-exact cross-chart certificate would fail too; the exact rational
  parameter on the shared source edge is the correct instrument.
- **Third hypothesis added:** `routeLength=1` with `step=0` in all four makes route **truncation** a
  first-class candidate alongside too-strict certificate and wrong pairing. None may be chosen before the
  census.
- **Reviewer error withdrawn (RP-03):** the prior `NEXT_TURN` called
  `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm` "THE CONTROL, on a different fixture."
  `make_nonconstant_hard_rail_fixture` (`tests/SurfaceCellTransitionQuotientTests.cpp:776-853`) is the
  same 3×3 grid with the same `{1,4}`/`{4,7}` rail as the others. All four identities run on **one mesh**;
  the rung cannot separate "open hard-rail production down" from "A4 production down generally."
- **Two harness design defects recorded:** a measurement rung must not fail its workflow on RED
  (`tools/m6_cp3_r4_witness_breadth_harness.sh:85`), and `die` on non-selection (`:68`) re-introduces
  stop-at-first-RED by aborting the loop.
- **RA-52.6 measured violation:** two retained guards are now known-unexercised — identity 4 dies at its
  `Produced` precondition, identity 1 throws inside its fixture singleton. Both stay retained,
  fail-closed; nothing retired. `RP-02` remains open.
- Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen selector **497** — unchanged.
  No promotion, no new stable event, no 497 run.
- Successor `M6-CP3-TB1-R4-TRUE-CONTROL` (artifact-only, free): no-hard-rail and closed-chain-rail
  identities from the same package.

## 2026-10-15 — RA-56 frozen: first TB RED reclassified as the 39-identity A4 route-certificate carrier

- Architecture Review only; no source, test, selector, harness or ledger change.
  `M6-CP3-TB1-R4-WITNESS-EXEC` and `M6-CP3-TB1-R4-WITNESS-REV` adjudicated: execution and root cause
  **ACCEPTED and independently re-derived**, **classification REJECTED and corrected**, repair plan
  **RETAINED but DEFERRED**. Frozen as **RA-56**. Decision record
  `.agents/Directional/Architecture_M6_CP3_R4_First_RED_Carrier_Reclassification_Review_Decision.md`.
- **Root cause confirmed by geometric re-derivation:** both probe points resolve to
  `0.75·v1 + 0.25·v4 = (1, 0.25, 0)`, interior to source edge `(1,4)` at parameter `0.25`, neither of the
  rail terminals `v1 = (1,0,0)` / `v7 = (1,2,0)`. `exact_corner`
  (`src/geometry/SurfaceCellTracing.cpp:19131-19143`) correctly rejected at `:19152`. The
  `currentFace / expectedFace` co-signal is a fallback echo of `first.from.face` / `second.to.face`
  (`:18939-18940`), not a second defect and not an `RP-01` recurrence.
- **Classification corrected:** `R4-TB-A-RP02-01` is not a new baseline-free candidate. All 21 other uses
  of `build_rectangular_hard_rail_phase_front` also assert `Produced`; two sit in frozen `selector449`;
  and the failure is the existing `A4_ROUTE_CERTIFICATE_REJECTION` carrier — 39 of the 94 R3 RED, 37
  CP2-accepted, matching the "39 endpoint" backlog 39/39, with 37 inside the frozen 497. The RED is an
  8 ms single-test reproducer of ~42% of the 88 carried CP2 losses.
- **Repair deferred behind two free measurement rungs:** all 39 are owned by the binary already in the
  immutable package and all are recorded `STATIC ONLY — current result unknown`; 38 of 39 hint
  `endpoint-0` while the single observation is `endpoint-1`.
- **Reviewer error owned:** RA-55.8's stop-at-first-RED rule is correct inside a repair loop and wrong for
  triage; it cost the control and three same-artifact identities. Amended — stop at first RED only within
  a dependent chain.
- **New architectural risk recorded (RA-56.5):** `faceEnds=0,2|0,3` indicates fronts meeting *across* the
  rail rather than intervals running *along* it; the repair plan's interval vocabulary would freeze a
  mis-shaped certificate. The census decides the model.
- Ledger **66/17/49**, debt **1**, selector **497** untouched, CP2 **491/491** accepted, R3 **403/497**
  rejected, PR #8 draft/open — unchanged. No new stable event, category or recurrence minted.

## 2026-10-15 — R4 RP-02 first-RED independent Review; corrective producer path bounded

- `M6-CP3-TB1-R4-WITNESS-REV` accepted artifact-only TB-A's first RED as measurement, not as a runtime pass. Source-backed cause: interior coincident source-edge point `(1,0.25)` on `(1,4)` is incorrectly required to be exact whole-rail vertex 1 or 7 by terminal certificate; A4 open-front network-bound consumer never reached. Existing exact-terminal guard remains valid and must not be weakened. Candidate `R4-TB-A-RP02-01` remains non-stable; downstream `RP-02` remains unproven. Source snapshot `f83bc044db739350eba044e9120bafddc1c1c537`, workflow `38669377821`, artifact `11942494171`, 5609 source hashes verified; immutable runtime `38668126299`/`11942382424` unchanged.
- Next separate Code + Build `M6-CP3-CB1-R4-WITNESS-REPAIR` frozen in `Architecture_M6_CP3_R4_Witness_Interval_Terminal_Recovery_Code_Build_Plan.md`; test/benchmark deferred to separate immutable run and independent Review. Six supplementals unexecuted, historical Phase14 executable missing; selector 497, ledger 66/17/49, debt1, CP2 491/491, R3 403/497 unchanged. Review record `Architecture_M6_CP3_R4_Witness_First_RED_Independent_Review_Decision_20261015.md`.

## 2026-10-15 — R4 supplemental Test + Benchmark: first RP-02 witness RED

- Artifact-only [run 38668126299](https://github.com/akashskypatel/Directional/actions/runs/38668126299), result `11942382424`, source `953f812ff1f431e3ad3af3b68a92284a7831c94a`; one exact-filter test ran and failed at its initial phase-front `Produced` precondition (`a2bProbeFailure=no-exact-terminal-corner`, closed-chain absent). Mandatory first-RED stop left the other six unexecuted. 28/28 GMP package hashes before/after and immutable source/selector validation passed. No source/test/selector edits, compile, relink or benchmark; no 497 execution or ledger promotion. Candidate `R4-TB-A-RP02-01` tracked without stable regression credit. Detailed `.agents/Directional/Architecture_M6_CP3_R4_Supplemental_Witness_TB_Report_20261015.md`; mandatory independent Review successor `M6-CP3-TB1-R4-WITNESS-REV`.

## 2026-10-15 — RA-55 frozen: R4 Code + Build authoring closed; Test + Benchmark authorized

- Architecture Review only; no source, test, selector, harness or ledger change. `M6-CP3-CB1-R4-OHF01-PROBE`
  and `M6-CP3-CB1-R4-RP02-WITNESS` are both **ACCEPTED**, each decisive claim re-derived from bytes at
  `1e0e13a38`. Frozen as **RA-55**. Decision record
  `.agents/Directional/Architecture_M6_CP3_R4_Authoring_Closeout_And_TB_Authorization_Review_Decision.md`.
- **OHF-01 (b) UNREACHABLE confirmed** on the checked construction path: unconditional
  `compute_edge_quantities` at `include/directional/core/TriMesh.h:339`, `checkHalfedgeRepetition` enabled
  as `check_consistency`'s second parameter (`include/directional/core/DCEL.h:1164-1169`) with section 5 at
  `:1453-1492`, and the factory atlas pin at `src/geometry/SurfaceCellTracing.cpp:8137-8145` preceding the
  census at `:8243-8266` / `:8270-8277`. The produced-path rejection was correctly demoted.
- **New finding `R4-OHF-02 / UNCHECKED_MESH_PROVENANCE`.** `FieldTransportAtlas::make`
  (`src/authority/FieldTransportAtlas.cpp:1893-1912`) validates edge tables by shape only and never re-runs
  `DCEL::check_consistency`, so unreachability rests on the convention that every production `TriMesh` is
  built via `set_mesh`, not on a type-level invariant. The OHF factory-negative requirement is RETIRED
  coupled to that condition; the guard and sub-code at `:8270-8277` are RETAINED fail-closed.
- **RP-02 witness accepted**: exactly one site assigns a `HardRail` boundary kind (`:12619-12620`, inside
  `assign_open_front_boundary_authority`), gated behind the network-bound `rail_interval_refs` at
  `:12425-12428`, so the positive cannot pass if the consumer is skipped. The negative's `cell >= 0`,
  `side ∈ [0,4)` anchor excludes 62 of the 66 `InvalidFrontBoundaryAuthority` emission sites. Authored and
  compiled only — **no runtime PASS**.
- **Correction to RA-54.2:** six reachable predicates and one fail-closed-only sub-code, not seven
  reachable. RA-51.7 is not reopened.
- **Test + Benchmark AUTHORIZED in two rungs**, not one: `M6-CP3-TB1-R4-WITNESS-EXEC` (supplemental,
  outside the frozen 497) then `M6-CP3-TB1-R4-497-EXEC` (the frozen `30 + 12 + 449 + 6` gate). Neither may
  edit source to obtain green.
- Ledger **66/17/49**, debt **1**, selector **497** untouched, CP2 **491/491** accepted, R3 **403/497**
  rejected, PR #8 draft/open — unchanged.

## CURRENT — RP-02 network-bound open-front consumer witness compiled (2026-10-15 UTC)

`M6-CP3-CB1-R4-RP02-WITNESS` authored **one** nonvacuous producer-to-consumer source test `SurfaceCellAuthorityContractCutover.ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer` in `tests/SurfaceCellsPhase10Tests.cpp`: authentic A2a network and producer rail must yield an A4 `HardRail` open-front edge and an actual filled cell/side with typed route, while a forged typed rail source edge must cause `InvalidFrontBoundaryAuthority` at that same A4 consumer. The test fails if `assign_open_front_boundary_authority` is skipped. Semantic source `953f812ff1f431e3ad3af3b68a92284a7831c94a`; pinned eight-target GMP/GMPXX compile [38664036225](https://github.com/akashskypatel/Directional/actions/runs/38664036225), artifact `11939982141` SHA-256 `2d5d1fc3f75b573307cae8af3c837da3dde2302ffdb4fe0ef3dd34d2aafeed7a`. **Compile-only; no binaries, tests, benchmarks or TB497 executed; no runtime PASS.** Detailed evidence `.agents/Directional/Architecture_M6_CP3_R4_RP02_Network_Bound_Consumer_Witness_20261015.md`.

**R4 Code + Build authoring ends here:** both last authoring turns (OHF-01 and RP-02) are disposed. Stop and await a separately authorized immutable-artifact TB / independent acceptance Review, not another invented Code rung. Frozen 497 selector, 66/17/49 ledger, debt 1, CP2 491/491, R3 403/497, PR #8 open draft unchanged.

---

## CURRENT — OHF-01 overfull hard-feature factory reachability probe (2026-10-15 UTC)

`M6-CP3-CB1-R4-OHF01-PROBE` answers **(b) UNREACHABLE through the checked source/atlas construction path**, source-only. `SourceTopologyRegions::make` can encode three incident faces, but `TriMesh::set_mesh` derives topology and rejects repeated directed halfedges via `DCEL::check_consistency` (three undirected-edge incidences force a duplicate direction), `FieldTransportAtlas::make` has no alternate supported construction seam, and `SurfacePhaseFrontProduct::make` pins the same source faces/regions to that atlas **before** counting rail incidences. Coupled retirement only; retain the fail-closed `OverfullHardFeatureIncidence` guard, reopen if any checked-construction/atlas-binding guard weakens. Evidence: `.agents/Directional/Architecture_M6_CP3_R4_OHF01_Overfull_Hard_Feature_Reachability_Probe_20261015.md`; source `3b655c44dc102603d1c7b16b2d1f4fa4a1c02987` snapshot run `38660874872`, artifact `11938238763`, **5604/5604** hashes. No implementation/test edits, compile, executable, benchmark or TB497. The only next Code + Build authoring turn is **`M6-CP3-CB1-R4-RP02-WITNESS`**, separate and not started; subsequent runtime requires separately authorized immutable-artifact TB. Ledger 66/17/49 and debt 1, accepted 491/491, R3 403/497, PR #8 draft/open remain unchanged.

---

## 2026-10-14 — RA-54 frozen: the six-rung ladder accepted and closed

- Architecture Review only; no source, test, selector or ledger change. All seven turns from `M6-CP3-CB1-R4-CARRIER-CUT-COMMENT` through `M6-CP3-CB1-R4-RA434-DISPOSE` are **ACCEPTED**, each decisive claim re-derived from bytes. Frozen as **RA-54**.
- Six consecutive no-op dispositions audited independently; all six correct. The interval's only source change is one comment line at `src/geometry/SurfaceCellTracing.cpp:1457`.
- **RA-43, RA-47 and RA-48 are now fully discharged**, and RA-46.6 is closed: `SurfacePhaseFrontSourceAuthorityDetail` carries seven values covering exactly the reachable predicates, with no sub-code minted for any dead disjunct or retired predicate (RA-51.7 honoured).
- RA-47.12's `RP-02 TEST_AUTHORITY_COVERAGE_GAP` accepted; confirmed that `build_surface_cell_network` returns at `:19567` on the produced path, so `:10498-10502` is unreachable there and `:12414-12428` is the only network-bound ingress.
- New: `R4-OHF-01 / UNTESTED_LIVE_DISJUNCT` — `OverfullHardFeatureIncidence` (`:8270-8277`) has no witness while its sibling does; settle reachability before writing a fixture, keep the guard fail-closed either way.
- **The source-only vein is exhausted.** Two authoring items remain; everything else requires an authorized Test + Benchmark turn. Ledger unchanged 66/17/49, debt 1; CP2 accepted 491/491; R3 rejected 403/497 (94 RED, 88 accepted losses). No runtime, no TB497.

## 2026-10-14 — RA-43.4 standalone geometry helper disposition

- Completed `M6-CP3-CB1-R4-RA434-DISPOSE` as an exact-source no-op. The two lower-level geometry helpers cannot independently authorize production rail source identity in the current call graph; the frozen named legacy diagnostic is retained for the non-vacuous network override negative. All three real `rail_interval_refs` production calls remain strict typed mode. Evidence: `Architecture_M6_CP3_R4_RA434_Standalone_Geometry_Helper_Disposition_20261014.md`, source `fa230b2a00e698eee9478fc06b3490cba5a86a11`, snapshot workflow 38656142605, artifact 11937071668, source SHA manifest 5603/5603. No implementation source edits, compilation, tests, benchmark, runtime acceptance or frozen-selector/ledger movement. No separately authorized named ladder successor established; broader R4 outstanding.

## 2026-10-14 — RA-43.4 standalone geometry diagnostic census (source-only)

- `M6-CP3-CB1-R4-RA434-CENSUS`: snapshot `b0d5c584a98d5ad321c324be9f18db5ba03d434b`, run `38653652905`, artifact `11935277891`, verified 5602/5602 source hashes. Two residual identity-relevant helper surfaces, no independent untyped production call, no production `LegacyStandaloneDiagnostic`. Frozen RA-52.6 caller table preserved in `Architecture_M6_CP3_R4_RA434_Standalone_Geometry_Diagnostic_Census_20261014.md`.
- No code, test, build, runtime, TB497, selector, ledger or PR metadata changes. Next separate `M6-CP3-CB1-R4-RA434-DISPOSE`. Local Drive patch staging was unavailable (`container_session_unavailable` twice); an exact-parent Git-object atomic documentation write was used. Initial read-mode order deviation and recoverable local Git ownership failure documented.

## 2026-10-14 — RA-46.6 checked-factory typed subcodes verified, no implementation needed

- `M6-CP3-CB1-R4-RA466-SUBCODES`: snapshot `0f2b1822cf3fecd209a610b6055549c561a000c3`, run `38651012007`, artifact `11934885965` (5601/5601) verifies all seven required typed factory distinctions are already in source, including missing/ambiguous terminal-star paths and zero/overfull incidence. No code/test edits or unchanged-source compile; no runtime evidence or acceptance promotion. Evidence: `.agents/Directional/Architecture_M6_CP3_R4_RA466_Typed_Factory_Subcodes_NoOp_20261014.md`.
- Frozen RA-51/52/53, selector497, ledger and remaining R4 gates unchanged. Next separate turn `M6-CP3-CB1-R4-RA434-CENSUS`.

## 2026-10-14 — RA-47.12 default-path typed interval liveness census (source-only)

- `M6-CP3-CB1-R4-RA4712-LIVENESS`: frozen snapshot `f983508edcd0157ca3c93832753102067ab392ef` / Actions `38645902635`, artifact `11932381704`, all 5600 source checksums verified. Static producer-to-consumer route exists, but no independently executed, non-vacuous ordinary pipeline witness proves producer-built rails reached **network-bound** `rail_interval_refs`. The earlier producer strict check uses `nullptr`; the source-authored ordinary-pipeline tests verify A2a publication or phase-front disposition without observing the interval consumer. **RP-02 TEST_AUTHORITY_COVERAGE_GAP** is recorded; neither observed liveness nor unreachable production is claimed. See `.agents/Directional/Architecture_M6_CP3_R4_RA4712_Default_Path_Typed_Interval_Liveness_Census_20261014.md`.
- Source-only finding; no code/tests/build/runtime/TB497/ledger/selector/PR changes. R4 remains open; next separately authorized rung is `M6-CP3-CB1-R4-RA466-SUBCODES`.

## 2026-10-14 — RA-47.11 typed-edge migration disposition (no-op)

- `M6-CP3-CB1-R4-RA4711-MIGRATE`: the frozen seven-site census identified **0** wrongly untyped `source_edge_index` uses; all seven require their existing typed-key-to-EV-row boundary or independent mesh adjacency assertion. Exact source remained unchanged since `09e8451ed6314a458e9abe8c6b74e866d19728fc`, verified by changed-path comparison and direct examination of the packaged snapshot. Record: `.agents/Directional/Architecture_M6_CP3_R4_RA4711_Migration_NoOp_20261014.md`.
- No production/test code, compile, runtime execution, benchmark, frozen selector, acceptance ledger, or PR metadata change. Separately authorized successor: `M6-CP3-CB1-R4-RA4712-LIVENESS`; the wider R4 is not complete.

## 2026-10-14 — RA-47.11 seven-site DCEL row census (source-only)

- `M6-CP3-CB1-R4-RA4711-CENSUS`: exact snapshot `09e8451ed6314a458e9abe8c6b74e866d19728fc` (workflow `38640107266`, artifact `11930195949`, 5598/5598 files verified) confirms `source_edge_index` has one typed-to-EV-row helper and six callers. All seven are legitimate, including the RA-47.10 lexical-versus-`EV`-row mismatch assertion; **zero test migration candidates**. See `.agents/Directional/Architecture_M6_CP3_R4_RA4711_Seven_Source_Edge_Index_Census_20261014.md`.
- Report only; no test/production/build/benchmark/runtime mutation, no `TB497` or acceptance promotion. Next separately authorized `M6-CP3-CB1-R4-RA4711-MIGRATE` has no eligible edit under the frozen conditional rule. Ledger and remaining R4 obligations unchanged.

## 2026-10-14 — RA-53 frozen: R4-SID-02 REFUTED, RA-52.5 WITHDRAWN

- Architecture Review only; no source, test, selector or ledger change. The `M6-CP3-CB1-R4-SID02-PROBE` source-only answer is **ACCEPTED** on every decisive link, re-derived from bytes. Evidence `Architecture_M6_CP3_R4_SID02_Produced_Cell_Reachability_Probe_20261014.md`; frozen as **RA-53**.
- **RA-52.5 is WITHDRAWN as a Review Agent error.** `RemeshPipeline.cpp:3562-3596` is not blind to equal opposite corners: `lattice_equal` (`:3312-3319`) compares `latticeCoordinate` with `==` on exact integers, and every producer assigns four distinct integer corner pairs, so sides 0 and 2 can never both authenticate. `R4-SID-02` is REFUTED and no A5 guard is owed.
- Four independent closures confirmed, none late: the planar producer's six-pair separation check (`SurfaceCellTracing.cpp:12640-12649`), the annulus/disk loop-normal cancellation (`:12354-12362`, `:14682-14709`, `:17230-17262`), A5's exact lattice discriminator, and `DegenerateClassedQuad` (`RemeshPipeline.cpp:6343-6350`). Producer census complete at `:17819-17833`.
- New: `RP-03 REVIEWER_CONJUNCT_MISREAD` — adjudicating a conjunctive guard by its weakest conjunct. The probe's near-equality caveat is credited and dissolved; no follow-up turn is owed.
- Ledger unchanged 66/17/49, debt 1; CP2 accepted 491/491; R3 rejected 403/497 (94 RED, 88 accepted losses). No runtime, no TB497, no successor credit beyond the named comment turn.

## 2026-10-14 — RA-52 frozen: selected-branch join REFUSED, RA-43.4 opt-out PRESERVED

- Architecture Review only; no source, test, selector or ledger change. The `Architecture_M6_CP3_R4_Source_Current_Review_Gate_20261014.md` REVIEW gate is **DISSOLVED** and both of its offered options are **REFUSED**. Decision record `Architecture_M6_CP3_R4_Selected_Branch_And_Diagnostic_Optout_Review_Decision.md`; frozen as **RA-52**.
- Option (A) refused: `SurfaceTraceSegment::family` is consumed only as seven digest inputs and one copy-through in `src/pipeline/RemeshPipeline.cpp`, plus same-frame run-merge equality in A4 — no decision reads the absolute value, so the requested join would have no consumer. Option (B) refused: it would manufacture one, and its `filled cell/side` field is the object RA-50.2 already REFUSED. Third instance of RA-45.2's category error.
- New: `R4-VIN-01 / STALE_FROZEN_VINTAGE` (a STOP adjudicated against a superseded frozen state); `R4-SID-02 / LATE_DEGENERACY_LOCUS` (equal-opposite-corner filled-side ambiguity closed at A7 rather than A5); `R4-JCT-01` (produced multi-carrier junction witness now AUTHORED / COMPILED / NOT EXECUTED). Sixth namespace frozen: A4 never consumes A2a trace segments.
- RA-43.4: the named `LegacyStandaloneDiagnostic` opt-out is **PRESERVED, scoped and census-bound**; removing it would make the network-override claim vacuous. No machinery added. Residue narrowed to the non-`rail_interval_refs` standalone geometry diagnostics.
- Ledger unchanged 66/17/49, debt 1; CP2 accepted 491/491; R3 rejected 403/497 (94 RED, 88 accepted losses). No runtime, no TB497, no successor credit.

## 2026-10-14 — M6-CP3-CB1-ENTRY-R4 continued: closed-rail source component

Source-exact A4 first-consumer closed-chain component guard and differential Phase10 negative applied at `62fec4a7f4ccf05a6fe8bc14f81d4b8ff774d809`; Pinned eight-target GMP/GMPXX compile request at dispatcher commit `608c5338f4a04a3ba3194a7e11ec7956e482c793`, exact semantic source `62fec4a7f4ccf05a6fe8bc14f81d4b8ff774d809`, mailbox `m6-cp3-r4-closedrail-component-compile`: **PENDING**; do not claim GREEN/RED until the immutable compile artifact and source/link evidence are verified.. No runtime execution or turn closeout. Evidence: `.agents/Directional/Architecture_M6_CP3_R4_Closed_Rail_Component_Code_Build_Record_20261014.md`.

## 2026-10-13 — R4 terminal-A3 and terminal-sector reachability: both RA-49.7 negatives RETIRED (architecture review)

- **RA-51 frozen.** The `R4-TA3-01` REVIEW STOP is **DISSOLVED** and **RA-49.7 is fully discharged**: no RA-46.5 negative remains unadjudicated. `missing-or-nonreciprocal-terminal-A3` and `overlapping-terminal-sectors` are **both unreachable**, by two independent arguments; both fixture obligations are **RETIRED coupled to named guards** and both runtime guards are **kept fail-closed**.
- **Review A — ingress census closed at two variants.** The primary `build_surface_cell_network` (`src/geometry/SurfaceCellTracing.cpp:18743`) and the convenience overload (`:20011`), which delegates to the primary on both branches, so the atlas gate at `:18771-18774` dominates every path to the terminal loop. `FieldTransportAtlas::make` pins the regions to its own `sourceMesh.F` (`src/authority/FieldTransportAtlas.cpp:1909-1910`, `:1926`) and the consume gate pins `rowTopology_` row-by-row to `faces` (`:3101-3108`, `include/directional/geometry/SourceTopologyRegions.h:151-188`), with a non-matching supplied authority **replaced** by one built from `faces` (`:18756-18764`). There is no "same regions, different edges" atlas.
- **The decisive distinction:** `NonTraversable` is **not** a missing value. `make` publishes the transition value at `:2039-2042`, **before** the `HardFeature` (`:2043-2047`) and region/component `NonTraversable` (`:2048-2054`) categorizations.
- **`missing-or-nonreciprocal-terminal-A3` unreachable (H1–H6).** Notably **H3**: RA-48.3 has **landed** (commit `785dd7398`) and `TriMesh::set_mesh` (`include/directional/core/TriMesh.h:331-351`) now derives the edge table **unconditionally**, then requires any supplied `_EV`/`_FE`/`_EF` to be bit-identical or throws — R4-OVF-01 **closed**, guard **G1 unconditional**, so **RA-48.1's overfull obligation does NOT revive**. And **H5**: `reverse = forward.inverse()` is computed at `:2033-2034` and served from one record by `directed_transition_value` (`:910-922`), making the nonreciprocity disjunct **unrepresentable**, not merely unobserved.
- **`overlapping-terminal-sectors` unreachable (K1–K5).** Each face has degree ≤ 2 in the local star, so the star graph is a disjoint union of paths and cycles; a cycle yields `ambiguous-terminal-A3-path` (`path_to` requires `count == 1`, `:19137`); on a path, the two orientations (`:19143`) overlap simultaneously **iff** the two attachments are the same face, excluded by the pairing region-distinctness at `:18892` plus per-region tracing (`:12946`/`:14686`/`:17257`, guards `:12380`/`:14920`/`:17538-17539`).
- **New finding `R4-TA3-02 / DEAD_DISJUNCT`.** `SurfaceCellTracing.cpp:19103-19104` and `FieldTransportAtlas.cpp:2035-2038` are dead by construction. Both stay as fail-closed guards. **Forward constraint on RA-46.6: a typed sub-code may not be minted for a disjunct that cannot fire.**
- **One hypothesis checked, no defect reported:** the consumer's `localStar` (`:19081-19110`) and the factory's `unique_terminal_star_path` (`:8395-8430`) apply the **identical** star rule, so there is no producer/validator disagreement over `NonTraversable` region seams — the terminal star is cut by rails only, by design.
- **No runtime credit.** No Directional binary, test, benchmark or TB497 executed. Ledger 66/17/49, M6 debt 1, unchanged; selector 497 untouched; CP2 491/491 accepted; R3 403/497 rejected with 94 RED and 88 accepted CP2 losses. See `.agents/Directional/Architecture_M6_CP3_R4_Terminal_A3_First_Rejection_Review_Decision.md`.

## 2026-10-13 — R4 oriented terminal side authority: RA-43.2 DISCHARGED, producer receipt REFUSED (architecture review)

- **RA-50 frozen.** The RA-43.2 "oriented terminal source-face germ and front-filled-side ownership" REVIEW_BLOCKER is **DISSOLVED**. RA-43.2 ends at "for contact purposes"; the contact is the typed terminal vertex pair, and that consumption has landed (`src/geometry/SurfaceCellTracing.cpp:19013-19014`, `:19064-19069`, fail-closed `:19038-19043`/`:19068`, factory re-validation `:8308-8325`/`:8474-8497`). **RA-43.2 is DISCHARGED**; RA-43.1 and RA-43.4 remain open. Root class `R4-SCOPE-01 / FROZEN_CLAUSE_SCOPE_INFLATION`.
- **The requested producer receipt is REFUSED as a namespace category error.** `filledCell` is an `authority::CellId` and `filledSide` a quad-cell side index in `[0,4)` (`include/directional/geometry/SurfaceCellTracing.h:1555-1557`); quad cells are minted by A4 and have no source-domain existence, so a source-authored filled-side owner must invent the right-hand side of its own binding. Fifth namespace beside RA-43.3's four; ninth publish/don't-invent instance.
- **The oriented-side authority already exists and is independent.** The request cited `:8450-8467` and concluded from the absence of `:8588-8637`, which re-derives side ownership inside the factory from source topology and A3 only: `unique_terminal_star_path` **Unique** both sides (`:8596-8608`), per-step `matchesA3`/incidence/chaining/no-repeat re-validation (`:8613-8626`), forced termination at the carrier faces (`:8628-8632`), disjoint sectors (`:8632-8637`). The consumer selects the carrier orientation by source sectors, not from the trace (`:19137-19173`, `ambiguous-carrier-orientation` at `:19166`). A5 closes the filled-side binding at `src/pipeline/RemeshPipeline.cpp:5003-5004` and `:5008-5012`.
- **New finding `R4-SID-01 / SIDE_AUTHORITY_LOCUS`.** The certificate alone is side-symmetric; the symmetry is broken only at `make :8458-8466` and A5 `:5003-5004`. `attachmentTransport()` inverts under a global swap, so `:5008-5012` separates it only when the composed τ is not self-inverse — for τ ∈ {0, 2}, `:5003-5004` is the sole discriminator and is load-bearing. Any regression asserting the certificate by itself determines the filled side is **vacuous** and may not be counted.
- **Three request points accepted:** the RA-46.5 factory-vs-consumer double-counting warning (`tests/SurfaceCellTransitionQuotientTests.cpp:9052-9071` is a factory `MissingTerminalA3Path` negative, **not** the consumer predicate at `:19175`); `append_edge_interval`'s first-in-range `incidentFaces` row is architecturally inert (`RemeshPipeline.cpp:9289-9307`); RA-49.5 / `R4-CTC-01` stays a deferred Definition issue.
- **RA-47 verified IMPLEMENTED** (`.1`–`.10`): typed `sourceEdges` (`SurfaceCellTracing.h:113`), typed publication `:9365`/`:9512`, typed digests `:2043-2047`/`:10013-10017`, and the component remap **deleted and replaced** at `:18094-18108` with fail-closed `InvalidTypedRailSourceEdgeRemap`. **RA-47.11 outstanding**: `source_edge_index` survives with six uses in `tests/FieldAlignedCurveNetworkTests.cpp`.
- **No runtime credit.** No Directional binary, test, benchmark or TB497 executed. Ledger 66/17/49, M6 debt 1, unchanged; selector 497 untouched; CP2 491/491 accepted; R3 403/497 rejected with 94 RED and 88 accepted CP2 losses. See `.agents/Directional/Architecture_M6_CP3_R4_Oriented_Terminal_Side_Authority_Review_Decision.md`.

## 2026-10-12 — R4 typed rail source edge index binding (compile-verified; runtime untested)

- Producer raw source edge indices are now cross-validated against independently typed source edge intervals, with existing default-built negative coverage. Initial compile `38212754554` failed on `DomainResult` comparison; diagnosed source correction `b970e1a113fe00b90e225d917597c649f9e1aa1d` applied `38213040179`. Corrected exact-source mandatory GMP/GMPXX compile **GREEN**: dispatcher workflow `38214261145`, compile job `114695273536`, exact source `b970e1a113fe00b90e225d917597c649f9e1aa1d`; all eight requested targets linked, preflight/build exit `0/0`, CMake `DIRECTIONAL_ENABLE_GMP=ON`, generated link command includes `libgmpxx.so` and `libgmp.so`, package `SHA256SUMS` **28/28**, source clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. Result artifact `11732105024` ZIP SHA-256 `f6f5f73de7626bb29402f61dd79b01091c65b712fd74fa1c03725ac1a428511d`; diagnostic artifact `11731010539` ZIP SHA-256 `43e37208dab181918dc13c876eff807eb33248f9dc3c62e44e4c110178874dee`. **No generated Directional binary, test, benchmark, discovery or TB497 executed.** No runtime execution; R4 remains open. See `.agents/Directional/Architecture_M6_CP3_R4_Typed_Rail_Source_Edge_Index_Code_Build_Closeout_20261012.md`.

## 2026-10-12 — R4 unsupported-sheet original-source A3 candidate (compile-only)

- R4 unchanged Phase10 negative `PhaseFrontProducedThenUnsupportedSheetFailsClosedWithoutPartialAuthority` now constructs independently source-owned A2/A3 from original disconnected planar/tetrahedral mesh and unmodified per-face orthonormal axes before A4, for both forward and reversed face rows. Test name, expected `UnsupportedSourceSheetTopology` first rejection, sheet/component labels and source geometry unchanged. One test file +31/-5, source `24fbd353332c1d55ec2612e9a0ccbe748a861d9f`; Drive apply `38208759469`, result artifact `11729035200` SHA-256 `f93a5aaff338f6e449fdd638d2f5239c00a0017bb22fc8dd84dbc18173cd9949`, stage owner-deleted. Eight-target GMP/GMPXX compile GREEN: workflow `38208927096`, job `114678596602`, result artifact `11728751414` SHA-256 `883c7a811aec1138d7aecaa0f8b225aae6fe7eb5a712909a31a08a4fa7f3c273`, log artifact `11729000824` SHA-256 `705e72e9ab6fd2d455b362d83f2b22924e559e0f5795113c4faecdedf981f6a4`. No generated Directional binary/tests/benchmarks/TB497 executed; first rejection and 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2 / six CP3 / genuine odd-τ multi-carrier outcomes remain runtime-unverified. Independent overfull-A3 Review and RA-43.4 remain open; same `M6-CP3-CB1-ENTRY-R4`, successor UNKNOWN. Evidence `.agents/Directional/Architecture_M6_CP3_R4_Unsupported_Sheet_Original_A3_Code_Build_Record_20261012.md`.

## 2026-10-12 — R4 CP3 seam witness independently original-source-bound A3 (Code + Build)

- M6 CP3 produced seam-witness fixture `make_axis_aligned_isolation_seam_fixture` now calls the existing `bind_phase_front_fixture_atlas` before the A4 network build, constructing A2/A3 independently from its original mesh and unaltered finalized field. Only `tests/SurfaceCellTransitionQuotientTests.cpp` changed (+3/-0); no selector, oracle, production contract, field, sheet labels or runtime behavior was changed. Source `b58314b3c8f024d2e6a3ce6092ad87b85425d40f`; Drive apply workflow `38207015195`, result artifact `11727906867` ZIP SHA-256 `36e2e19ec7f3dc163d925ead798a55688a0276cbf04f1ab1ba98ba0580606510`; staged Drive patch deleted after push. Exact-source eight-target GMP/GMPXX compile **GREEN**: workflow `38207150160`, job `114673117668`, result artifact `11727628126` ZIP SHA-256 `59145348b1324241ea596fbcce410c75b016881b9abc2d06917be43d21d045b7`, manifest **28/28**, preflight/build exits **0/0**, `DIRECTIONAL_ENABLE_GMP=ON`, generated link includes GMPXX/GMP, `exactArithmeticBackend=GMP`, clean source, `runtimeExecution=false`. Diagnostic artifact `11727807480` ZIP SHA-256 `36decf1318c952fdb6bfcb222acd7336918ab6aa18540f3a82095db6a960e44d`. **No generated Directional binary, test, benchmark, discovery or frozen TB497 executed.** Runtime first rejection and 39 endpoint, 34 Phase10, seven DCEL, 88 CP2, six CP3, real odd-τ/multi-carrier, RA-43.4 and independent overfull-A3 Review remain open. R4 IN_PROGRESS; successor UNKNOWN.

## 2026-10-12 — R4 produced rail source-chain oracle (compile-only)

- Existing producer integration fixture now checks exact ordered rail source-vertex and face-local source-edge incidence; existing interior hard-rail seed fixture publishes `{0,3}`. One test file +24/-0, source `e7a39b891a046df46811bc9f792a17e0c33e7da9`, apply `38200534499`.
- Mandatory eight-target GMP/GMPXX compile: workflow `38200681852`, job `114653260254`, result artifact `11725410765`, ZIP SHA-256 `ee7472bc18b63bff93c24a1c4cd7a848eb8f30ff113e99e87b25da5f6d0ff44c`, package manifest **28/28**, preflight/build exits **0/0**, **8/8** required targets, CMake GMP enabled and GMPXX/GMP linker verified, clean source, `runtimeExecution=false`.
- No runtime credit or TB497. RA-43.4 and independent overfull-A3 feasibility remain open; canonical R4 continues. See `Architecture_M6_CP3_R4_Producer_Rail_Chain_Oracle_Code_Build_Record_20261012.md`.

## 2026-10-12 — R4 Phase14 typed rail first-rejection source migration (Code + Build only)

- Two unchanged supplemental tests publish exact ordered source-vertex chains while preserving the deliberately disconnected legacy negative, first-rejection checks and added valid control. One test file +9/-0; source `4d51805d79994f1d718d71332be06f504d6312cf`, apply run `38198898409`, Drive retired. Exact-source eight-target GMP/GMPXX compile **GREEN**: workflow `38198996718`, job `114648012662`, source `4d51805d79994f1d718d71332be06f504d6312cf`, result artifact `11723819181`, ZIP SHA-256 `23ee086aaeef3fec3ff9b04dc200e8de2fb54c9350f33f7925458dda9ab63d73`; manifest 28/28, preflight/build 0/0, GMP/GMPXX linker verified, source clean, `runtimeExecution=false`. No runtime/benchmarks/TB497 or acceptance promotion.

## 2026-10-12 — R4 Phase14 incident-order and barrier typed rails (compile-only)

- Two existing supplemental Phase14 rail cases now publish exact `sourceVertices={0,4,7}`; semantic source `9709bd8e855e4f6a92165b082ba9b3f4330f8411`, one test file +2/-0, no changed assertions or frozen selectors. GREEN — exact source `9709bd8e855e4f6a92165b082ba9b3f4330f8411`, dispatcher event `c6cf2651f5d5fcfbcbdaa53b79d2fbaed6a29261`, workflow `38196555564`, compile job `114640470513`, result artifact `11723373444` ZIP SHA-256 `a122eb21e00a387d5585d6cf55244a79a15a2091138343051eb98192266d9b7f`; eight required targets, preflight/build 0/0, manifest 28/28, GMP/GMPXX generated linker evidence, clean source before/after, `runtimeExecution=false`. No runtime execution, acceptance promotion or completed R4 claim.

## 2026-10-12 — R4 Phase14 typed positive rail migration (Code + Build only)

- Authenticated 10 rail instances over seven existing Phase14 tests by publishing source-owned exact ordered vertices. Semantic source `10afde93e4de3202d5bc8d2bbd0304f629a2375e` from apply `38194680839`, Drive retired. Exact-source mandatory eight-target GMP/GMPXX compile **GREEN**; workflow `38194789102`, job `114635016916`, result artifact `11723220719`, ZIP SHA-256 `3340a26bc7fc8a543843981d0040a84339ec44490ed26c17b5541f1cc53e6039`. Eight targets verified; CMake `DIRECTIONAL_ENABLE_GMP=ON`, actual generated linker command references both `libgmpxx.so` and `libgmp.so`, package 28/28 checksum manifest, preflight/build exit 0/0, source worktree clean and `runtimeExecution=false`. No Directional test or benchmark executed. No runtime proof, promotion, selector changes or factory/source-semantic modifications.

## 2026-10-12 — R4 typed Phase14 rail fixture (compile-only)

- Published exact ordered `sourceVertices={0,4}` on a single previously untyped valid-interval rail test, source commit `5fbfa5de3f1421dab122ea70ba677efb6dd6f5f1`; Exact-source 8/8 GMP/GMPXX compile GREEN workflow `38193556754`, job `114631316138`, artifact `11721982481` SHA-256 `2e665b1a2d7833c979e2bc5975979f36053e218443934de26c2cf208076637b2`, manifest 28/28, exits 0/0, clean source, `runtimeExecution=false`. Test execution deferred.

## 2026-10-12 — `M6-CP3-CB1-ENTRY-R4` checked-factory A3 path rejection detail

- RA-46 independent review retires only the mathematically unreachable dual-path witness obligation; original fail-closed guard preserved.
- Typed factory zero/ambiguous terminal-star result and safe spoke-incidence lookup added; one produced-terminal negative regression extended. Semantic source `74e74e41a7f040f34798d998dba36677e7ff07d4`. No runtime execution or acceptance promotion; mandatory eight-target GMP/GMPXX compile GREEN (`38187046419`, artifact `11719319676`, 28/28 checksums).

## 2026-10-07 — `M6-CP3-TB1-ENTRY-R1-REV` rejected R1 and routes RA-32 Definition repair

- Independent Review accepts R1 mechanics (**482/497**) but rejects/unpromotes the candidate.
- The ten A6/D7 rows are failed recovery of the existing `RP-01` authority-domain event; no new stable event.
- Other REDs are non-stable witness/oracle/definition gaps; stable accounting stays **63 / 17 / 46**, debt 1.
- Exact next is runtime-free `M6-DEFN-R5-R1`, then mandatory Definition Review.

## 2026-10-07 — `M6-CP3-TB1-ENTRY-R1-EXEC` — 482/497; mandatory Review

- Durable dispatcher runtime `37645974118 / 112876903729` completed all 497 fresh artifact-only processes against `11488700954 / 68000a95...` with exact-one selection, zero skips, benchmark 0 and immutable postflight.
- Result is **482 PASS / 15 RED**: focused30 23/30, focused12 12/12, selector449 446/449, CP3-entry 1/6.
- The expected RA-31a shape (496 PASS plus only identity 2 RED after its non-vacuity/A5 prerequisites) was not met. Six non-stable candidate groups are recorded for mandatory R1 Review; stable accounting remains **63 / 17 / 46**, debt 1.
- Next: `M6-CP3-TB1-ENTRY-R1-REV`.

## 2026-10-06 — `M6-CP3-TB1-ENTRY-REV` review-agent addendum — one new rule withdrawn

- The CP3 entry build broke 124 tests. Most come from one missing published value, which the next build fixes.
- Review also found that a new check across hard edges compared angles measured against two unrelated references, so it could reject valid meshes whose field varies across the edge.
- That check is withdrawn until it is redefined against the field's actual matching across the edge.
- Next: `M6-CP3-CB1-ENTRY-R1`.

## 2026-10-06 — `M6-DEFN-R5-REV` — CP3 entry plan approved with fixes

- The definition for M6's last checkpoint (CP3) is approved with corrections:
  - one input the new rules need has to be published by the producer that already owns it;
  - two tests need real data that actually exercises the property they check;
  - one rule would have quietly loosened an existing check;
  - two tests in the final gate are not in the standard build, so the later build must add them.
- Next: `M6-CP3-CB1-ENTRY` (entry gate 497).

## 2026-10-06 — `M6-CP2-CLOSE-REV` — CP2 CLOSED / ACCEPTED

- Independently re-derived TB2 at **491/491** with exact-one selection, zero skips/RED/benchmarks, result manifest 1005/1005 and immutable postflight.
- Accepted RA-29d recovery: exact A7 vertex binding, required negative coverage, ten-row §6.3 map, and dead-code/predicate cleanup.
- Added `M6_CP2_Closure_Record.md`; RA-29d OBS-01..04 are closed/recovery-proved.
- Promoted `11391685901 / 5ce3132e...` as reviewed CP2 authority. Accounting remains **60 / 16 / 44**, debt 1.
- Exact next: `M6-DEFN-R5`.

## 2026-10-06 — `M6-CP2-TB1-VERIFIER-R2-REV` review-agent addendum — CP2 reopened

- The verifier build that passed all 491 tests stays approved. But checkpoint CP2 is reopened, because two things are missing:
  - **one required check was never written:** that each output vertex sits at its group's agreed source location;
  - **most of the verifier's rejection rules have never been shown to reject anything in a test.**
- A bounded code turn adds the missing check and the missing failure tests. Then a dedicated closure review decides.
- Next: `M6-CP2-CB2-COVERAGE`.

## M6-CP2-TB1-VERIFIER-R2-REV — CP2 accepted and promoted (2026-10-06)

Independent Review promotes `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` after re-deriving the immutable R2 gate at **491/491** with exact-one selection, zero skips, zero benchmarks and clean immutable postflight. Static review confirms RA-29c three-hop binding, removal of the invalid component rule and rejected reverse lookup/fallback, O(P log P) grouping, and behavioral token ownership. R1 recovery findings are closed; no new regression candidate. Accounting remains 60/16/44, debt 1. M6-CP2 is closed; exact next is `M6-DEFN-R5`.

---

## M6-CP2-TB1-VERIFIER-R2-EXEC — 491/491 artifact-only gate GREEN (2026-10-06)

Immutable package `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` completed the frozen 491-process gate in run/job `37403703032 / 112076464024`: focused30 30/30, CP2-focused12 12/12, selector449 449/449, exact-one 491/491, zero skips and zero benchmarks. Result/log artifacts `11387562709 / 11387233341` were uploaded successfully; the result self-manifest verifies 1005/1005 and immutable package/source/execution-view postflight is clean. No rebuild, relink, configure, generated discovery, repair, mutation, timeout, partition, or retry occurred.

No new regression candidate is recorded; stable accounting remains 60/16/44, debt 1. The candidate remains unpromoted pending mandatory `M6-CP2-TB1-VERIFIER-R2-REV`.

---

## 2026-10-06 — `M6-CP2-CB1-VERIFIER-R3` — RA-29c verifier recovery compile/package GREEN

- Applied the exact RA-29c three-hop relation → path → vertex verifier binding at source `c64baacd6c767c4ba053b6963651c0aa6eceed20`; removed R2's reverse lookup, the invalid raw-connectivity component rule, and the vacuous `owns_products` constant.
- All eight standard GMP/GMPXX targets compiled and linked in run/job `37401647591 / 112069997705`; package `11385836615` self-verifies **28/28**, source receipts are clean, and `runtimeExecution=false`.
- Frozen focused30 / CP2-focused12 / selector449 / routing449 bytes remain unchanged. Candidate is compile-valid but unpromoted; accounting remains **60 / 16 / 44**, debt 1.
- Next: immutable `M6-CP2-TB1-VERIFIER-R2-EXEC` at **491** fresh processes with `TURN_ID`-derived upload paths, then mandatory Review.

## 2026-10-06 — `M6-CP2-TB1-VERIFIER-R1-REV` review-agent addendum — verifier fix redesigned

- The second verifier build wrongly rejected 29 previously passing tests. Both causes were mistakes in rules the review agent had added.
- The fix the last review prescribed would have caused new false rejections, because the same rail can legitimately carry inverse values.
- It is replaced by an exact check that follows how the products are actually built: relation → path → vertex.
- Next: `M6-CP2-CB1-VERIFIER-R3` (gate 491).

## 2026-10-06 — `M6-CP2-TB1-VERIFIER-R1-REV` — R2 rejected; RA-29b freezes bounded recovery

- Review traced the broad R1 regression cluster to the verifier, not the optimizer: A7 intentionally loses/deduplicates A6 target identity, but R2 incorrectly demanded one unique reverse match instead of the frozen same-owner-value fallback.
- Review also withdraws the new raw-connectivity component equality rule. Component IDs are ingress authority and accepted tests allow one component label across disconnected topology regions.
- R3 is limited to those two corrections plus focused identities 2/6; no A5/A6/A7 producer or optimizer semantic change and the 491-name gate remains frozen.
- The R1 result/log upload miss is post-runtime workflow plumbing only; runtime is not repeated. Next: `M6-CP2-CB1-VERIFIER-R3` → 491-process R2 EXEC → mandatory Review.

## 2026-10-06 — `M6-CP2-TB1-VERIFIER-R1-EXEC` — 462/491; mandatory Review

- Immutable R2 package `11382000465 / 9c8478ae...` completed all 491 fresh exact-filter processes: focused30 **26/30**, focused12 **11/12**, selector449 **425/449**.
- Most new failures converge on `VerificationFailed:MissingPublishedAuthority:a7:a5-relation-step`; selector144 separately rejects at `a0:component-adjacency`; focused12 ordinal6 also fails its strengthened >=2-step baseline.
- The runtime harness completed and immutable postflight passed, but stale predecessor output paths in the caller caused both evidence uploads to fail after execution. No duplicate runtime retry is authorized; the GitHub job log is preserved for Review.
- Candidate remains unpromoted; accounting stays **60 / 16 / 44**, debt 1. Next: mandatory `M6-CP2-TB1-VERIFIER-R1-REV`.

## 2026-10-06 — `M6-CP2-CB1-VERIFIER-R2` — verifier recovery compile/package GREEN

- Applied the RA-29/RA-29a verifier recovery at source `9c8478aec40bf07144ca7372c2aa58293cd42f5e`, including exact class/path/support checks, linear-time topology maps, an owning verified-product barrier, and repaired focused witnesses.
- All eight standard GMP/GMPXX targets compiled and linked in run/job `37391389044 / 112037085233`; package `11382000465` self-verifies **28/28** and records `runtimeExecution=false`.
- Frozen 30/12/449 gate bytes are unchanged. No runtime acceptance or promotion is claimed; stable accounting remains **60 / 16 / 44**, debt 1.
- Next: immutable `M6-CP2-TB1-VERIFIER-R1-EXEC` at **491** fresh processes, then mandatory Review.

## 2026-10-05 — `M6-CP2-TB1-VERIFIER-REV` review-agent addendum — verifier fix list extended

- The first verifier build is still rejected. Three of its new tests checked nothing (their tampers changed nothing), and that diagnosis is confirmed.
- Review found five more problems in the verifier:
  - a wrongly split vertex class was accepted;
  - two checks slow down quadratically on large meshes, inside the production pipeline;
  - one cross-check matched the first similar record rather than the exact one;
  - the source-mesh component check was missing;
  - the "verified" handle pointed at product addresses instead of holding the products.
- One earlier requirement was relaxed because it added risk without catching anything new.
- Next: `M6-CP2-CB1-VERIFIER-R2` (gate 491).

## 2026-10-05 — `M6-CP2-CB1-VERIFIER-REV` — verifier build unblocked

- The verifier build stopped on a rule it could not satisfy: it was asked to prove a fact about which source triangle a vertex is anchored to, and nothing in the pipeline guarantees that fact.
- Review found the rule itself was wrong. It is withdrawn, and the optimizer is left unchanged.
- A new test pins the property that makes this safe: the optimizer never moves a vertex off its own anchor.
- Next: `M6-CP2-CB1-VERIFIER-R1` (gate 491).

## 2026-10-05 — `M6-CP2-DEFN-REV` — independent verifier design approved with fixes

- The plan for the independent product verifier (CP2) is approved.
- Before any code is written, it must also check that:
  - every relation is consumed exactly once;
  - merged classes are backed by recorded relations;
  - the per-corner sheet data matches the source mesh.
- The order "verify, then use" becomes something the type system enforces.
- Next: `M6-CP2-CB1-VERIFIER` (gate 491).

## 2026-10-05 — M6 CP2 verifier contract frozen for review

- The verifier gets malformed test evidence through copied record views, not unchecked products.
- It independently recomputes only frozen elementary facts and cannot repair/search/substitute producer authority.
- Production verification is placed immediately after A7; the first planned CP2 gate is 491 exact-filter processes.
- Next is mandatory `M6-CP2-DEFN-REV`; implementation remains held.

## 2026-10-05 — M6 CP1 closed; independent verifier definition next

- Product separation is now closed after a final review of the six frozen exit conditions and the current source.
- The accepted mechanism keeps the reviewed **479/479** runtime. No product code changed in closure.
- The closed-complex production-evidence debt remains open; debt stays 1.
- Next is `M6-CP2-DEFN`, which defines the independent product verifier and its negative evidence before implementation.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-R1-REV` review-agent addendum — close-out recovery confirmed

- The recovered close-out build (479/479) is confirmed and promoted.
- Two gaps are now recorded with owners:
  - the new cross-sheet test proves only part of the new rule;
  - one fail-closed branch has never been triggered by a test.

  Both are scheduled for the CP2 verifier work.
- The CP1 closure review now has a fixed checklist. If CP1 closes, the next step is the CP2 verifier definition (`M6-CP2-DEFN`).

## 2026-10-05 — `M6-CP1-TB12-CLOSE-R1-REV` accepted R1 recovery and promoted 479/479 runtime

- Independently re-derived runtime `37280517630 / 111667316992`, result/log `11333591947 / 11333547162`, result manifest **497/497**, focused30 **30/30** + selector449 **449/449** = **479/479 PASS**, exact-one, zero skips, benchmark 0 and immutable postflight.
- Accepted RA-27a: exact member-local wedge connectivity and the consistent-chain identity29 falsifier are both runtime-proved; C4 diagnostic name is exact.
- Closed `M6-CP1-TB12-CLOSE-EXEC-CAND-01` as recovery-proved/non-stable; no stable repricing. Accounting stays **60 / 16 / 44**, debt 1.
- Promoted package/source `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` as current reviewed M6 runtime authority.
- Exact next: runtime-free `M6-CP1-CLOSE-REV`; CP1 remains active until its six exit items and current-HEAD close obligations are independently discharged.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-R1-EXEC` — close-out recovery gate 479/479 GREEN

- Immutable candidate `11330703256 / 3f40f04a...` passes focused30 **30/30** plus selector449 **449/449** = **479/479**, exact-one, zero skips, benchmark 0.
- Identity29 now exercises the corrected wedge-connectivity falsifier and passes; identity30 remains green.
- Immutable postflight and 497/497 result manifest pass. No new regression event/candidate; accounting remains 60 / 16 / 44, debt 1.
- Candidate remains unpromoted pending mandatory `M6-CP1-TB12-CLOSE-R1-REV`.

## 2026-10-05 — `M6-CP1-TB12-CLOSE-REV` review-agent addendum — close-out test fixed at its root

- The close-out test failed because it looked for a kind of cross-sheet join that the test geometry cannot produce. In that geometry, sheets meet inside single cell corners, not along shared edges.
- That is also where the remaining weak check lives: a corner spanning two sheets was accepted with any transition at all. The next code turn makes that check exact, and re-tests it end to end.
- Next: `M6-CP1-CB12-CLOSE-R2` (gate 479).

## 2026-10-05 — `M6-CP1-CB12-CLOSE-REV` — close-out unblocked

- The close-out turn stopped on a code site it judged unsafe. Review found that the site is test-only diagnostic code and does not read the value in question, so the stop is lifted.
- A full audit of the optimizer and final validation found nothing that makes a product decision from the arbitrary representative point.
- Two places use that point as a numeric reference: the optimizer's normal/field reference and one validation-metric fallback. Both predate this checkpoint. They are now scheduled for the M6-CP3 permutation-invariance work, with a test that must prove the fix.
- Next: `M6-CP1-CB12-CLOSE-R1` (close-out code, gate 479).

## 2026-10-05 — `M6-CP1-TB11-G4-R1-REV` review-agent addendum — boundary recovery confirmed; CP1 close-out turn added

- The edge-loop boundary recovery (477/477) and its promotion are confirmed.
- One gap is noted: a malformed vertex silently cuts a strip short instead of failing. RA-25 fixes that.
- The remaining CP1 obligations need code, so a close-out Code + Build (`M6-CP1-CB12-CLOSE`, gate 479) now precedes the final CP1 close Review.

## 2026-10-04 — `M6-CP1-TB11-G4-REV` review-agent addendum — boundary extractor defect found; strip rule corrected

- The CB11 rejection is confirmed, but the second failure is a real product defect, not a test gap.
- The new candidate extractor grouped "strips" in a way it can never classify. It produced no candidates on any closed mesh, so the planned synthetic-torus test would also have failed.
- RA-24 changes strip grouping to follow edge loops, matching the old curve-based behavior.
- The recovery turn now includes that one production change. Next: `M6-CP1-CB11-G4-R1` (gate 477).

## 2026-10-04 — `M6-CP1-CB11-G4` — A6 closed-complex boundary compile/package GREEN

- Added the A6-owned closed-complex view and arrangement-independent simplification-candidate extraction required for the `G4-B002` migration boundary.
- Hard-feature protection now comes from explicit typed source-edge authority, independently of the A6 relation-kind label; strip identity is derived from opposite-edge closure.
- Added focused checks 25-28, including the degree-2-contracted torus equivalence oracle and independent candidate-eligibility tamper check.
- Final semantic source `582da20a925ba920c923bf5aacb9e0e56ef0723d`; compile run/job `37216400150 / 111477707423`; candidate artifact `11308472138`; all eight GMP/GMPXX targets green; no runtime executed.
- Next: immutable TB11 gate **28+449=477**, then mandatory Review.

## 2026-10-04 — `M6-CP1-TB10-A5V-R1-REV` review-agent addendum — CB10 recovery confirmed; CB11 oracle fixed in advance

- The CB10 recovery (473/473) and its promotion are confirmed.
- Before CB11 starts, a static check found that its planned exact-match test against the old arrangement could never pass, because the arrangement splits every cell side at triangle crossings.
- RA-21b now defines the comparison as "equal after merging those split points", with explicit preconditions.
- Next: `M6-CP1-CB11-G4` (gate 477).

## 2026-10-04 — `M6-CP1-TB10-A5V-REV` review-agent addendum — CB10 rejection confirmed; moved checks verified

- The rejection of the green CB10 candidate is confirmed. The moved validation runs too early, and the adapter-projection test doesn't compare every field.
- A line-by-line comparison shows the moved checks are unchanged, except one now reads its count from the input instead of the A5 product. The recovery restores that.
- The recovery turn gets an exact field list for the projection test. Next: `M6-CP1-CB10-A5V-R1` (gate 473).

## 2026-10-04 — `M6-CP1-TB9-A7-R1-REV` review-agent addendum — R1 promotion confirmed; one dropped guard restored

- The completion recovery (469/469) and its promotion are confirmed.
- The fix also deleted a reject-only check that the representative point's face belongs to its vertex class's own regions and sheets. RA-22b restores it in CB10. It cannot change any gate result, because every gate run already satisfied it.
- Next: `M6-CP1-CB10-A5V` (gate 473).

## 2026-10-04 — `M6-CP1-TB9-A7-R1-REV` accepts recovery and promotes R1

- Independent Review re-verifies result `11293546353` at **970/970**, focused **20/20**, selector449 **449/449**, aggregate **469/469**, exact-one, zero skips, benchmark 0 and immutable postflight.
- Focused12/focused20 prefix and selector449/routing449 hashes are re-derived; focused20 is non-vacuous and now passes the real production completion-ownership validator.
- RA-22/RA-22a is accepted. Candidate `11292072930 / 584f80fe...` becomes the current reviewed M6 runtime authority under unchanged selector449.
- `M6-CP1-TB9-A7-EXEC-CAND-01` closes recovery-proved/non-stable under existing `RP-01`; stable accounting remains **60 / 16 / 44**, debt 1.
- Exact next is `M6-CP1-CB10-A5V` (gate 473). Its plan now requires one shared `τ` owner for A5/A7 without a tolerance-value change. A7 cross-sheet proxy remains owned by CP1 close.

## 2026-10-04 — `M6-CP1-TB9-A7-R1-EXEC` COMPLETE: recovery gate 469/469 GREEN

- Immutable R1 candidate `11292072930 / 584f80fe...`; run/job `37174573847 / 111354443006`; result/log `11293546353 / 11293531459`.
- Exact gate is focused **20/20** + selector449 **449/449** = **469/469 PASS**; exact-one, zero skips, benchmark 0, immutable postflight, 970/970 result self-manifest.
- Formerly RED focused20 `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` PASSes, mechanically proving the RA-22/RA-22a completion-authority recovery.
- No new regression candidate or stable repricing; accounting remains **60 / 16 / 44**, debt 1. Candidate remains unpromoted pending mandatory `M6-CP1-TB9-A7-R1-REV`; CB10 held.

## 2026-10-04 — `M6-CP1-TB9-A7-REV` review-agent addendum — completion defect pinned to the sheet check; diagnostics added

- The rejection is confirmed. The A7 producer is correct. The completion stage required a relation path to end on the representative's isolation sheet, which fails for valid multi-sheet vertex classes. RA-22 changes that to a membership check.
- RA-22a adds sub-check suffixes to the completion failure, so any remaining failure is attributable.
- Two A7 follow-ups are recorded: the cross-sheet check is a proxy, and the tolerance must come from one source.
- Next: `M6-CP1-CB9-A7-R1` (gate 469).

## 2026-10-04 — M6 TB9 A7 Review rejects candidate and freezes RA-22 recovery

- Independent Review verifies the immutable TB9 gate at **468/469** with selector449 fully green; only the new production-completion focused witness fails.
- A7 class-wide geometry/lineage publication is upheld. The failing integration seam treats the representation-only source-point face as singleton sheet/component authority when validating a class-wide selected relation destination.
- RA-22 makes completion consume retained A7 chart/region/sheet authority and derive a singleton source component from retained charts, while preserving legacy non-A7 behavior and all relation/support/transport semantics.
- Candidate `11287202960 / b8d27b63...` remains rejected/unpromoted. Stable accounting stays **60 / 16 / 44**, debt 1. Recovery is `M6-CP1-CB9-A7-R1` -> unchanged 469 TB gate -> mandatory Review before CB10.

## 2026-10-04 — `M6-CP1-TB9-A7-EXEC` COMPLETE: 468/469 semantic RED; Review required

- Immutable candidate `11287202960 / b8d27b63...`; run/job `37165108302 / 111326336924`; result/log `11288673996 / 11288504403`.
- Gate is focused **19/20**, selector449 **449/449**, aggregate **468/469**; exact-one, zero skips, benchmark 0, immutable postflight, 970/970 result self-manifest.
- Sole RED focused20 reaches real production completion ownership and fails `CompletionOwnershipInvalidSelectedRelationDestination`; focused13-19 and all selector449 rows pass; RA-18 support diagnostics are zero.
- Recorded `M6-CP1-TB9-A7-EXEC-CAND-01` as non-stable Review-owned candidate `RP-01 / AUTHORITY_DOMAIN_CONFLATION`; stable accounting remains **60/16/44**, debt 1.
- Candidate remains unpromoted; reviewed runtime stays TB8 `11265967968 / 8e0818b1...`. Exact next: mandatory `M6-CP1-TB9-A7-REV`; CB10 held.

## 2026-10-03 — `M6-CP1-CB9-A7` COMPLETE: A7 compile/package green

- Implemented immutable A7 source-attached geometry authority and RA-18 typed-support plus reject-only same-simplex point guard; removed the old semantic `1e-9` adapter coincidence check.
- Added focused identities 13-20. Focused-20 SHA-256 `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`; focused-12 is its exact byte prefix.
- Two compile-only defects were repaired without running Directional runtime. Final semantic source `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`.
- Mandatory compile run/job `37160018910 / 111311373537` builds all eight standard GMP/GMPXX targets. Candidate artifact `11287202960` (`sha256:9bd87689c0155c3544de83159bd00169a4c8f932be4e878dbdd3dc7e7b5a179c`), log `11287377799` (`sha256:f3ebe94b0ce58abdd3a5f1376de5c222da6d9a600e9cb3e74dd5f6768c905ce5`), `runtimeExecution=false`.
- Candidate remains unpromoted; reviewed runtime stays `11265967968 / 8e0818b1...`. Exact next: `M6-CP1-TB9-A7-EXEC`, **20+449=469**, then mandatory Review. Accounting remains **60/16/44**, debt 1.

## 2026-10-03 — `M6-DEFN-R4-REV` — A7 / thin-adapter / `G4-B002` definition accepted with four amendments

- **RA-18:** A7 keeps a reject-only point-coincidence guard. The old position check was the only detector that relation-united occurrences are the same point.
- **RA-19:** moved validation keeps its current order; the adapter-thinness test is behavioral.
- **RA-20:** hard-feature protection comes from source authority, not relation kind. The torus's hard edges are periodic-cut carriers.
- **RA-21:** the boundary equivalence oracle has an explicit key path and a stop rule.
- Exact next: `M6-CP1-CB9-A7` (gate 469).

## 2026-10-03 — `M6-CP1-TB8-A6-REV` review-agent addendum — promotion confirmed; RA-17; bounded R4

- TB8 (461/461) and the promotion of `11265967968 / 8e0818b1...` are independently confirmed. Focused 1-12 is frozen as a required-green prefix.
- RA-17:
  - A6 placement transport feeds only the strict cycle rule;
  - `M6-DEFN-R4` is bounded to CP1 exit, as set out in its new plan (census first, A7 exact-support certificate, adapter 55-site classification, `G4-B002` boundary, CB sequencing);
  - the gauge obligations move to `M6-DEFN-R5` (CP3-entry).
- Selector446's production-completion claim is downgraded to an inference. The witness production-completion identity is pre-registered for the first A7 CB. Accounting 60 / 16 / 44.

## 2026-10-03 — M6 TB8 Review accepts recovery and promotes CB8 runtime

- Independently re-verified candidate `11265967968 / 8e0818b1...` and TB8 result `11273611682`; package/result manifests, selector/routing, all 461 ledgers and immutable postflight are valid.
- TB8 is accepted at **461/461 PASS**. The three TB7 stable regressions are formally recovery-proved; append-only accounting stays **60/16/44**, debt 1.
- `11265967968 / 8e0818b1...` is promoted as current reviewed M6 runtime authority under selector449 449/449.
- CP1 stays open on A7, the thin adapter and the `G4-B002` A6-derived stage boundary. Exact next is runtime-free `M6-DEFN-R4`, then mandatory Review before implementation.

## 2026-10-03 — M6 TB8-A6 recovery gate returns 461/461

- Artifact-only run/job `37121395619 / 111198068572` consumes candidate `11265967968 / 8e0818b1...` immutably and completes exactly **12 focused + 449 selector = 461** fresh processes.
- Result is **461/461 PASS** with exact-one selection, zero skips and benchmark 0; result artifact `11273611682` verifies a **954/954** self-manifest.
- Focused12 passes and all 17 TB7 RED selector rows recover; critical focused/selector controls are all green and the diagnostic census is zero.
- Immutable postflight and frozen selector/routing authority hold. EXEC creates no new candidate and does not reprice history: **60/16/44**, debt 1. Candidate remains unpromoted pending mandatory `M6-CP1-TB8-A6-REV`; R4/A7/G4 remain held.

## 2026-10-03 — M6 CB8 implements RA-16; compile/package green

- Implemented coordinate-rigid HardRail placement transport from occurrence placements, independent of face-gauged branch rotations.
- Decoupled lineage `canonicalRelationValue` from A6 `canonicalTransport`; exact pre-CB7 OrdinaryFront/HardRail/Periodic relation values are preserved.
- Moved exact HardRail route-authority validation into A5, strengthened focused 3, and added focused 12 for coordinate-rigid / face-gauge-invariant transport.
- Initial compile exposed only a test helper declaration-order error; a bounded test-local repair produced exact source `8e0818b1e2f8d12b86c64d8774a3572c5ed5266c`.
- Authoritative compile retry `37101997642 / 111143233041` builds all eight standard GMP/GMPXX targets; candidate artifact `11265967968`, `runtimeExecution=false`.
- Selector/routing bytes, selector446, `PureQuadCompletion.cpp`, fixtures and A7/R4/G4 remain unchanged. Exact next: `M6-CP1-TB8-A6-EXEC`, **12+449=461**, then mandatory Review. Accounting stays **60/16/44**, debt 1.

## 2026-10-03 — `M6-CP1-TB7-A6-REV` review-agent addendum — selector446 reclassified; RA-16; CB8 amended

- **Selector446 is not a stale test.** CB7 coupled the M5 lineage selected-step transport to the A6 placement transport, and production completion validates that step. The TB7 CAND-03 is now a stable `RP-01` recurrence; stable accounting **60 / 16 / 44**, debt 1.
- **RA-16 frozen:**
  - HardRail placement transport is coordinate-rigid, from occurrence placements. RA-14's branch formula depended on the face gauge (off by the field matching across a rail).
  - `canonicalRelationValue` (lineage) is decoupled from `canonicalTransport` (A6).
  - Route validity is A5-owned.
- **CB8 plan amended:** selector446 and `PureQuadCompletion.cpp` stay unchanged; new focused 12; TB8 = **12+449 = 461** → mandatory Review. R4/A7/G4 remain held.

## 2026-10-03 — `M6-CP1-TB7-A6-REV` — TB7 RED adjudicated; RA-14/RA-15 frozen

- Independently verified TB7 run/job `37090507571 / 111109661723`, result/log `11262587435 / 11262387973`, result self-manifest 953/953 and aggregate **443/460 PASS** with exact RED ordinals 115/116/122/130/132/134/137/141/143/150/176/201/217/227/230/231/446.
- Re-opened exact candidate/current source: decisive implementation/test files in packaged semantic source `40842caa...` are byte-identical to runtime-free snapshot `ea826744...`.
- Classified HardRail route-carrier vs placement-map conflation as one stable `RP-01` recurrence and rows227/230 typed route-order loss as one stable `VALIDATION_ORDER_SHADOWING` recurrence. Stable accounting **59 / 16 / 43**, debt 1.
- Closed selector446 as non-stable test authority: production materializes, focused6/periodic controls pass, holonomy conflicts are zero; only the stale relation-endpoint-vs-placement assertion remains.
- Added RA-14 (HardRail route and placement transport separate authorities) and RA-15 (individual route validity precedes pair reciprocity).
- Rejected/unpromoted CB7 candidate `11257522199 / 40842caa...`; reviewed runtime remains TB5 `10879581622 / 82b86a28...`, selector449 449/449.
- Froze exact successor `M6-CP1-CB8-A6`; compile/package green advances to TB8-A6 **11+449=460** then mandatory Review. R4/A7/G4 remain held.

## 2026-10-03 — M6 TB7-A6 exposes HardRail gauge/ordering regressions; mandatory Review next

- Artifact-only run `37090507571 / 111109661723` executes all 460 frozen processes from candidate `11257522199 / 40842caa...`: focused **11/11**, selector **432/449**, total **443/460** with exact-one selection, zero skips and immutable postflight.
- CB7 fixes its original TB6 targets: focused6 and selector139/142 recover, selector140/232/444/448/449 stay green, and `QuotientHolonomyConflict` disappears entirely.
- Sixteen accepted selector identities newly turn RED. Evidence points to HardRail route-carrier transport being incorrectly treated as a placement-gauge transform, plus two typed-error precedence losses. Selector446 materializes successfully but its old selected-certificate assertion still compares different RA-13 gauges.
- EXEC records three non-stable Review-owned candidates; accounting remains **57/16/41**, debt 1. Candidate remains unpromoted. Exact next is `M6-CP1-TB7-A6-REV`; no TB repair/rerun is authorized.

## 2026-10-02 — M6 test review corrected: the "holonomy" failures are a units mix-up, not a geometry exception

- The last review read two torus test failures as a legitimate geometric twist and loosened the check. Re-examination shows the code compared two transforms expressed in different coordinate conventions. It fails only on the one torus variant where those conventions differ.
- The check stays strict. The next code turn puts every transform in the same convention and also restores a dropped hard-rail validation.

## 2026-09-25 — M6 A6 design review accepts the quotient stage with four implementation safeguards

- The quotient-stage design is accepted, with semantic relation direction anchored to canonical occurrence IDs rather than reciprocal edge storage order.
- Ordinary front joins are explicitly identity transforms; seam rotations remain evidence used to validate the join, not another transform applied by the quotient stage.
- A5 relation records must carry the exact HardRail/Periodic evidence A6 needs, so the new stage does not reach back into mutable/index-based front representation.
- Noncommutative path-transform composition order is now explicit. The planned four tests and 460-process later gate are unchanged in count.
- Next is compile-only `M6-CP1-CB6-A6`; no runtime, selector, regression-accounting, or accepted-package authority changed in this Review.

## 2026-09-25 — M6 A6 quotient stage is now specified for review

- Defined the missing quotient-stage product: class identity is the exact set of member occurrences, not a temporary row/root/hash.
- Every owned relation must now be accounted for exactly once, including relations that close an already-connected cycle. Cycle transport must agree with the existing selected path or fail explicitly.
- The first implementation turn is planned but held for independent review. It will also absorb the old legacy-field cleanup; its later runtime gate expands from 456 to 460 exact processes.
- Geometry-stage and candidate-extraction boundary details remain deferred to the next Definition turn. No code/runtime changed in this Definition turn.

## 2026-09-25 — M6 checkpoint 1 is further from done than the last review said

- The latest test run is fully green (456/456), and that result stands.
- Checkpoint 1 was meant to split the surface pipeline into three separate stages. Only the first stage exists so far; the other two, and a key hand-off point, are still missing. That scope had quietly fallen off the tracking documents.
- The planned small cleanup turn is on hold and will be merged into the next real piece of work. Next is a design turn that plans the two missing stages.

## 2026-09-25 — M6 CP1 TB5 Review accepts recovery; CB6 cleanup next

- Independent Review upholds CB5/TB5 at **456/456 PASS**, formally recovery-proves the TB1/TB3/TB4 defects, and keeps historical accounting at **55/16/39**, debt 1.
- Package/source `10879581622 / 82b86a28...` is promoted as current reviewed runtime authority under unchanged selector449.
- CP1 stays open only because public A5 still exposes unread `SurfaceOccurrence.chart/lattice/isolationSheet`; exact source already sorts aggregated equivalences after remap, so that earlier minor debt is withdrawn.
- Next is bounded `M6-CP1-CB6` field retirement, compile only, then unchanged TB6 7+449=456 and Review.

## 2026-09-25 — M6 CP1 TB5 returns 456/456

- Executed the CB5 candidate artifact immutably across seven focused tests plus the full frozen selector449: **456/456 PASS** with exact-one selection, zero skips/crashes/mismatches and no rebuild or benchmark execution.
- All 21 accepted-selector losses observed in TB4 recovered, as did the carried torus pair-swap and periodic rows 444/446/448; the split-sheet and row140 controls remain green.
- Candidate `10879581622` is still unpromoted. Accounting remains 55/16/39, debt 1, until mandatory `M6-CP1-TB5-REV` independently adjudicates recovery, promotion and CP1 acceptance.

## 2026-09-25 — M6 CP1 CB5 compile green

- Corrected A6 OrdinaryFront classification so an exact source-edge-collinear span without an isolation certificate is treated as an ordinary non-seam and checked by same-sheet + both-wedge authority; certificate-backed seam validation is unchanged.
- Added RA-12 site-qualified isolation-failure diagnostics without changing tests, selectors, or A5 product authority.
- Compile run `36168827294` built all eight standard GMP/GMPXX targets from source `82b86a285292379cfd92cdc4e10d74181b38f1e8`; candidate artifact `10879581622` verifies 28/28 with `runtimeExecution=false`.
- Candidate remains unpromoted. Accounting stays 55/16/39, debt 1. Next: immutable 456-process `M6-CP1-TB5-EXEC`, then mandatory Review.

## 2026-09-25 — M6 TB4 review, second look

- Two statements from the earlier review were stronger than the evidence and have been narrowed. The plan for the next code turn (CB5) is unchanged.
- Code the last test run couldn't reach was checked and found consistent.

## 2026-09-25 — M6 CB5 plan tightened after review

- The review confirmed the cause of the 21 new test failures (a check that confused "lies on a mesh edge" with "lies on a seam").
- Four of the remaining failures, on the torus, may have a different cause. The next code turn will make failure messages say which check fired, so any leftover failure can be pinned down directly.
- Next: code turn CB5, then the 456-test run. Accounting 55/16/39, debt 1.

## 2026-09-25 — `M6-CP1-TB4-REV`: one stable RP-01 recurrence; CB5 frozen

Independent Review upholds the mechanically valid 456-process TB4 gate at **431/456 PASS** but classifies its 21 newly RED accepted-selector identities as one stable existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence. A5 `collinearEdge` denotes generic exact source-edge support and permits same-sheet/no-certificate spans; A6 OrdinaryFront P2 incorrectly treats every such edge as an isolation seam and requires a checked seam certificate. Stable accounting advances to **55/16/39**, debt 1. Candidate `10871935178` remains unpromoted; accepted M5 authority remains selector449 449/449. Exact next is bounded runtime-free `M6-CP1-CB5`, then unchanged 456-process TB5 and mandatory Review.

## 2026-09-25 — `M6-CP1-TB4-EXEC`: immutable 456-process gate is mechanically valid and semantic RED

- Candidate `10871935178 / 20f60bb1...` ran exactly seven focused + selector449 = **456** fresh exact-filter processes in run/job `36157505252 / 108145613689`; exact-one selection, zero skips/selection mismatches, benchmark 0, no watchdog and exact immutable postflight.
- Outcome: focused **6/7**, selector449 **425/449**, aggregate **431/456 PASS / 25 RED**. Focused row5 and selector 186/214/239 recover from TB3; new seventh focused identity PASSes; row6 + selector 444/446/448 remain RED; **21 accepted selector identities newly turn RED**.
- Result/log artifacts `10874311495 / 10873574681`; result SHA `32dca965...93e24`, self-manifest **932/932**; log SHA `9d50f4e6...b4757`.
- EXEC records non-stable `M6-CP1-TB4-EXEC-CAND-01`, leaves stable accounting **54/16/38**, debt 1, and keeps the candidate unpromoted. Exact next is mandatory runtime-free `M6-CP1-TB4-REV`; no corrective implementation first.

## 2026-09-25 — M6 CP1 CB4 seam-incident authority compile green

- Implemented the reviewed seam-corner authority model at source `20f60bb1412424a6f1093fc8076884d1ea23f1c5`: complete wedge bindings, exact isolation-transition lineage, relation-local path authority and reciprocal-side validation.
- Compile run `36150253128` produced candidate artifact `10871935178`; all eight standard targets linked with GMP/GMPXX, package manifest 28/28, and no generated Directional runtime executed.
- Selector449/routing449 remain unchanged. The candidate is unpromoted; next is the immutable 456-process `M6-CP1-TB4-EXEC` followed by Review. Accounting remains 54/16/38, debt 1.

## 2026-09-25 — M6 CB4 unblocked: the missing per-face value turned out to be unneeded

- CB4 stopped because the definition asked for a per-face branch value that the upstream product doesn't provide for every face.
- Review found nothing uses that value. The definition now drops it and records the upstream per-corner value as labelled provenance, so no upstream product change is needed.
- CB4 resumes; the test plan (456) and accounting (54/16/38, debt 1) are unchanged.

## 2026-09-25 — M6 definition accepted with review corrections; implementation (CB4) unblocked

- The second seam-sheet definition is accepted. The review fixed ten places where a literal implementation would have failed an existing gate.
- Examples: the square test's boundary sides; hard-rail vertices on the torus; a permutation check aimed at a hash that includes face row numbers; one test's expected error code.
- Next is the code-and-compile turn (CB4), then a 456-test run and review. Accounting is unchanged at 54/16/38, debt 1.

## 2026-09-25 — M6-DEFN-R2 seam-incident authority amendment complete

- Runtime-free Definition; exact source snapshot run/artifact `36095854118 / 10847467936` at `342a306ebd3ba68cb6e1135cf9e25726bd8ad461`; no Directional runtime or compile.
- Froze evidence-only `CornerWedgeIsolation` lineage transitions, complete binding-consumer rules, exact seam-collinear cell-interior face selection, one-to-one A5 failure vocabulary/adapter, and P1-P4.
- Frozen-test audit covers focused rows 5/6, selector rows 186/214/239/444/446/448 and HardRail single-sheet assertions; selector/routing bytes unchanged.
- Re-scoped CB4 and strengthened the seventh focused identity; TB4 remains 7+449=456 if Review accepts and CB4 later compiles.
- Accounting unchanged at **54 / 16 / 38**, debt 1. `M6-DEFN-OBS-01` recurred as +0 process-only. Exact next `M6-DEFN-R2-REV`; CB4 HELD.

## 2026-09-25 — M6 definition review: model upheld, amendments required before code

- The new corner-wedge rules for isolation sheets are the right model. As written, though, they would make an existing gating test fail: two split-square corner vertices would claim two sheets with no recorded evidence.
- Three more gaps block implementation: which face each consumer uses, face tie-breaks in the side tracers, and the failure-code policy.
- Next is runtime-free `M6-DEFN-R2`; code (CB4) stays on hold. Accounting is unchanged at 54/16/38, debt 1.

## 2026-09-25 — M6-DEFN-R1 seam-incident authority definition

Runtime-free Definition amendment froze complete corner-wedge sheet/certificate authority, exact seam-collinear directed-side authority, per-wedge face/chart/branch provenance, owner-less OrdinaryFront A6 validation, A7 union lineage, and row140 adapter-only legacy naming. Re-scoped CB4 remains held pending mandatory `M6-DEFN-R1-REV`; TB4 is pre-registered as 7 focused + selector449 = 456. Accepted runtime authority, selectors, stable accounting 54/16/38, and debt 1 are unchanged.

## 2026-09-25 — M6 CP1 TB3 review: CB4 put on hold pending a definition decision

- An independent check confirms the TB3 result: 447/455, and six accepted rows now fail. Stable accounting stays **54/16/38**, debt 1.
- The CB3 change that takes each occurrence's sheet from its outgoing side is a representative choice, not an authority. On a seam, a cell's corner can cover two sheets, and the split-square witness already drops a sheet at two vertices.
- Attaching seam certificates to relations puts them on the wrong object. It would also be ambiguous at seam vertices.
- `M6-CP1-CB4` is on hold. Next is runtime-free `M6-DEFN-R1`, which decides how isolation sheets and seam certificates are owned at seam corners, followed by its review.

## 2026-09-25 — `M6-CP1-TB3-REV`: relation-owned isolation-equivalence gap classified; CB4 frozen

Independent runtime-free Review re-verifies CB3 candidate `10840014758 / 660015f2...`, TB3 result `10844285398` (**929/929**, 455 processes) and accepted M5 result `10815911956` (**911/911**, 449/449). TB3 remains focused 4/6 + selector449 443/449 = 447/455 with exact-one/zero-skip and immutable postflight. Six accepted losses plus two focused controls share `MissingIsolationSeamEquivalenceAuthority`. Static source and frozen A5/A6 contracts prove one existing-`RP-01` defect: ordinary A5 relations omit the required typed isolation-certificate reference while the transitional consumer reconstructs semantic owner authority from front-edge boundary-path representation. Stable accounting advances to **54/16/38**, debt 1; candidate remains unpromoted. Row140 validation-order recovery is proved. Exact next: runtime-free `M6-CP1-CB4`, then unchanged 455-process TB4 + Review.

## 2026-09-25 — `M6-CP1-TB3-EXEC`: immutable CP1 recovery gate remains semantic RED

- Candidate `10840014758 / 660015f2...` executed exactly 455 fresh exact-filter processes: **447 PASS / 8 RED**, exact-one, zero skips, benchmark 0, immutable postflight exact.
- HardRail row140 recovers and the old `OccurrenceInvalidCornerAuthority` symptom stays absent. Eight tests instead stop at `MissingIsolationSeamEquivalenceAuthority`, including six accepted selector449 identities.
- Candidate stays unpromoted; stable accounting stays **53/16/37**, debt 1. Mandatory next is runtime-free `M6-CP1-TB3-REV`.

## 2026-09-25 — `M6-CP1-CB3`: bounded authority correction compiles green

CB3 publishes exact semantic source `660015f2f15359fd426e2c855aea9f4201c70216`, restoring accepted HardRail-specific failure precedence and correcting split-isolation occurrence projection authority without changing the frozen test/selector surface or relation-owned quotient semantics. Mandatory GMP/GMPXX run/job `36077715921 / 107892575831` packages all eight standard targets as candidate `10840014758` with 28/28 manifest, clean source receipts and `runtimeExecution=false`. Candidate remains unpromoted; accounting stays 53/16/37 with debt 1. Exact next is immutable `M6-CP1-TB3-EXEC` over unchanged 6+449=455, followed by mandatory Review.

## 2026-09-24 — M6 CP1 TB2 independent Review

- Review upholds TB2 immutable mechanics at 453/455 and keeps candidate `10834642074` unpromoted.
- Accepted selector row140 is a new stable `VALIDATION_ORDER_SHADOWING` event; focused multi-isolation remains a non-stable CP1 mechanism failure. Stable accounting is **53 / 16 / 37**, debt 1 M6-owned.
- Exact next is bounded runtime-free `M6-CP1-CB3`; selector449 remains accepted M5 authority at 449/449.

## 2026-09-24 — `M6-CP1-TB2-EXEC`: artifact-only recovery gate is 453/455; Review next

Immutable candidate `10834642074 / 724316a5...` executes six focused + selector449 as **455** fresh exact-filter processes: focused 5/6, selector 448/449, total 453/455 with exact-one selection, zero skips/crashes/selection mismatches, benchmark 0 and exact immutable postflight. `OccurrenceInvalidCornerAuthority` is absent and the retained pair-swap identity PASSes, but focused multi-isolation remains RED and accepted selector row140 now returns `OccurrenceUnownedRelation` instead of `InvalidHardRailTransport`. These are new non-stable Review-owned candidates; formal TB1 recovery is not claimed in EXEC because selector449 is not 449/449. Stable accounting stays 52/15/37, debt 1; candidate remains unpromoted. Exact next is mandatory `M6-CP1-TB2-REV`.

## 2026-09-24 — `M6-CP1-CB2`: bounded A5 iterator-range recovery compiles green

CB2 corrects only the Review-proved cross-temporary `isolation_sheets()` iterator range in exact source `724316a5b3f49e33dc8e649989bb413b3dc6b7c9`, preserving all A5 semantic checks and the frozen test/selector surface. Mandatory GMP/GMPXX compile run/job `36061049526 / 107839861958` packages all eight standard targets as candidate artifact `10834642074` (SHA-256 `754cfeae...d0cb8`) with 28/28 manifest, clean source receipts and `runtimeExecution=false`. Candidate remains unpromoted; accounting stays 52/15/37 with debt 1. Exact next is immutable `M6-CP1-TB2-EXEC` over the unchanged 455-process gate, followed by mandatory Review.

## 2026-09-24 — M6-CP1 TB1 Review proves cross-temporary range defect

Independent Review upholds TB1's 440/455 semantic RED and one accepted-prefix event but proves the exact cause is an invalid `std::binary_search` range constructed from two separate by-value `isolation_sheets()` temporaries. Accepted M5 uses one stable vector for the same region/component/sheet contract and remains 449/449. The event is reclassified from RP-01 recurrence to new singleton `CROSS_TEMPORARY_ITERATOR_RANGE`, correcting stable accounting to **52 events / 15 categories / 37 recurrences** with debt 1 M6-owned. Candidate `10826090221` remains unpromoted. Exact next is bounded runtime-free `M6-CP1-CB2`, followed by the unchanged 455-process TB2 recovery gate and mandatory Review.

**Reviewing-agent addendum (same turn) — UPHELD.** The UB root cause was re-verified from source and fresh artifacts. M5's accepted corner check applies the same `trace.face` predicates through a stable vector, so the differential is valid. A codebase-wide scan of the eight by-value accessors finds only this one split range, so the one-variable CB2 scope is sufficient. TB1's three focused PASSes ran under UB and carry no credit. The CB2 plan pre-registers the TB2 rule: recovery means no `OccurrenceInvalidCornerAuthority` and selector449 at 449/449, and a focused RED with a different first failure, such as the never-clean pair-swap identity, is a new candidate. The benchmark digest adaptation is accepted. The stale M6 frozen header is fixed. Successor `M6-CP1-CB2` is unchanged.
## 2026-09-24 — `M6-CP1-TB1-EXEC`: artifact-only A5 gate is mechanically complete and semantic RED

- Immutable candidate `10826090221 / ee8b8ac...` executed exactly **455** fresh exact-filter processes under run/job `36045055975 / 107786525272`: focused **3/6 PASS**, selector449 **437/449 PASS**, total **440 PASS / 15 RED**, exact-one selection, zero skips/crashes/selection mismatches, benchmark 0.
- Result/log `10828084810 / 10827949954`; result provider SHA `796dc825...e1d7bd`, self-manifest **933/933**; execution ledger `fbbb6bd6...5c98e`; immutable package/source/selector postflight exact.
- Accepted selector RED ordinals **115,116,139,140,141,143,186,225,239,444,446,448** and focused rows2/5/6 share the new A5 `OccurrenceInvalidCornerAuthority` failure surface. Static source exposes existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` at corner publication; exact sub-predicate remains Review-owned.
- One new stable accepted-prefix event advances accounting to **52 / 14 / 38**; debt remains 1. Candidate is unpromoted and receives no A5/CP1/G4 credit. No retry, rebuild, semantic edit or selector publication occurred.
- Exact successor: mandatory runtime-free `M6-CP1-TB1-REV`.

## 2026-09-24 — `M6-CP1-CB1`: A5 SurfaceOccurrenceComplex candidate compile/package green

- Exact semantic source `ee8b8ac20571df5773f5f94bf9b382161f37a893` extracts A5 occurrence authority behind `SurfaceOccurrenceComplexProducer`; `OccurrenceId` is `(CellId, canonicalCornerRole)`, and the transitional phase-front materializer consumes the immutable A5 product without extracting A6/A7/A8.
- Four compile-visible A5 identities cover four semantic corners/cell, coincident-but-unrelated distinctness, true source-face-row permutation invariance, and malformed/missing/duplicate relation-endpoint rejection. The focused CP1 prepublication vector also carries the retained multi-isolation mechanism identity and dormant edge-storage pair-swap identity, for six focused tests total.
- `M5CP3.PeriodicRelationEndpointGaugeIsIndependentAndExact` is deleted as authorized; `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` remains unchanged. Accepted replacements remain present and selector449 is byte-identical at `d4a0d1b7...d6414`.
- Two bounded compile-integration projection defects were corrected runtime-free: generic hashing/benchmark serialization had assumed index-backed `OccurrenceId`. No semantic runtime evidence was produced.
- Final mandatory GMP/GMPXX compile run/job `36038472933 / 107764451786` packages all eight standard targets as artifact `10826090221` with 28/28 manifest, clean source receipts and `runtimeExecution=false`; log artifact `10826115205`. Candidate only: no M6 semantic credit, CP1 closure or G4 closure.
- Exact successor: artifact-only `M6-CP1-TB1-EXEC`, then mandatory `M6-CP1-TB1-REV`.

## 2026-09-24 — `M6-DEFN`: occurrence / quotient / embedding / verifier contracts frozen

- Runtime-free Definition freezes A5 `SurfaceOccurrenceComplex`, A6 `SurfaceQuotientProduct`, A7 `SourceAttachedGeometryProduct`, and the M6 structural A8 `VerificationReport`; M7 retains `OutputDisposition`/degradation.
- `OccurrenceId` is `(CellId, canonicalCornerRole)` and quotient-class identity is the complete canonical occurrence-member set; coordinate/position coincidence never establishes equality. A6 certifies/consumes every A5-owned relation exactly once; A8 may recompute elementary incidence but may not search, infer, repair, substitute, canonicalize, weld or mutate producer state.
- `G4-B002` remains CP1 mechanism / CP3 production; `G4-B001` is reclassified from an unproven current defect to CP3 direct-torus evidence debt because current source keeps hard rails out of isolation-sheet barriers; `G4-B004` requires the same M5-accepted produced torus authority through A5-A8.
- Dormant CB14 identities receive no M5 credit and are frozen for deletion at `M6-CP1-CB1` as redundant to named accepted replacements. Never-gated multi-isolation mechanism and committed-torus identities are retained for CP1/CP3 gating respectively, with neither sufficient alone for representative M6 closure.
- Consumed M6-DEFN plan is folded into `M6_Consolidated_Record.md`. Stable accounting remains 51/14/37; debt 1. Exact next: `M6-CP1-CB1`.
- Process-only `M6-DEFN-OBS-01` (+0): the read-mode gate was frozen late; decisive static work was restarted from verified source snapshot `36026363482 / 10819439146` at `c9be476d...`, with 5305/5305 source-manifest verification. No new lesson or semantic evidence is claimed from pre-snapshot reads.


**Reviewing-agent addendum (same turn) — UPHELD with amendments.** The frozen A5-A8 contract, the `G4-B001` static basis and the DESIGN A8 harmonization are confirmed, and the closeout was clean. Amendments:
- **Stated `CellId` basis.** A canonical rank with face-row invariance already accepted; the CB1 permutation test must permute face rows; `M7-DEFN` must revisit rank renumbering.
- **Stopped one dormant-test deletion.** The pair-swap test is the only edge-storage-permutation witness (row 444 permutes relations, not edges), so it is retained for the CP1 gate.
- **Moved buried tracker entries.** They sat below restored history and are moved above it, with a placement rule.
- **Fixed stale text.** The M5 frozen header and the TODO `G4-B001` item are updated.

Successor `M6-CP1-CB1` is unchanged.
## 2026-09-24 — `M5-CP4-TB2-REV`: selector449 accepted; M5 closed

- Independently re-opened CB2 package `10814505512`, TB2 result/log `10815911956 / 10815438959` and exact Review snapshot `10816641769`.
- Re-verified 28/28 package authority, all eight GMP/GMPXX targets, selector449/routing449 hashes and 448 prefixes, owner census 32/301/75/41, all 449 fresh ledger/raw receipts and exact immutable postflight.
- Re-derived the DEFN-R2 six-fact same-region producer contract from row449 source and confirmed the M5/M6 boundary; complete Actions-window reconciliation found one runtime and no re-arm.
- Accepted selector449 and package/source `10814505512 / e284fea7...`, accepted §13.1 conjunct8, discharged the `G4-B004` M5-half closure observation and **closed M5**. Accounting remains 51/14/37; debt 1 M6-owned.
- Folded four superseded CP4 per-turn records into `M5_Consolidated_Record.md`; exact successor is runtime-free `M6-DEFN`.


**Reviewing-agent addendum (same turn) — M5 CLOSURE UPHELD.** CB2 (eight targets, 28/28) and TB2 (911/911, 449/449) were re-verified from fresh downloads. The Actions window has exactly one compile and one runtime, and the census finds no further M5 obligation. The addendum corrects stale "closure held" text in the consolidated header, the TODO totals line and the ORIENTATION torus row. It merges the misplacement-prone fold sub-table into §5, adds the missing agent-changelog TB2-EXEC entry, and adds an M6-DEFN census note. It records `M5-CP4-TB2-REV-OBS-01`: COMPLETE was published and then followed by more writes, including an edit that stripped valid `LESSONS.md` 178 citations. Successor `M6-DEFN` is unchanged.
## 2026-09-24 — `M5-CP4-TB2-EXEC`: published selector449 fresh gate is 449/449 green; final Review next

- Immutable CB2 package/source `10814505512 / e284fea7...` re-verifies 28/28, GMP/GMPXX, clean source receipts, selector449/routing449 exact hashes and selector448/routing448 exact prefixes.
- Authoritative run/job `36017291483 / 107693066103` executes **449 fresh exact-filter processes**: 449 PASS / 0 RED, exact-one selected, zero skips, all exits 0, benchmark 0, census 32/301/75/41.
- Result/log `10815911956 / 10815438959`; result provider SHA `5b7bf7ab...a8a39f`; execution-ledger SHA `9b4fc28e...62c7ac2`; row449 PASSes with `first_unmet_fact=none`; immutable postflight is exact.
- No semantic regression is observed; accounting remains 51/14/37 and debt 1 M6-owned. EXEC makes no promotion/closure claim; exact successor is runtime-free `M5-CP4-TB2-REV`.

## 2026-09-24 — M5-CP4-TB1-REV

- Independently re-opened CB1/TB1 immutable artifacts and re-derived 449/449 exact-filter PASS evidence, manifests, raw-log hashes and immutable postflight.
- Accepted `M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion` as non-vacuous **prepublication** proof of the frozen same-region multi-isolation + checked-seam-certificate + quotient-owner producer contract without crossing into M6 authority.
- Precommitted selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` and routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` with exact selector448/routing448 prefixes and owners 32/301/75/41; no selector file was published.
- Kept accepted M5 runtime authority at selector448/package `10771899191 / cef1c6ee...`; conjunct8 and M5 closure remain held pending CB2 publication, fresh TB2 and final Review.
- Folded consumed CB1 plan/report and superseded DEFN-R1 Review into `M5_Consolidated_Record.md`; froze exact next `M5-CP4-CB2`.


**Reviewing-agent addendum (same turn) — UPHELD with corrections.** The prepublication proof and the selector449/routing449 precommit are re-verified from fresh downloads. TB1-EXEC had attempted a prohibited second 449-process execution after its authoritative run; it was blocked only by a malformed workflow, it was undisclosed, and TB1-REV missed it (`M5-CP4-TB1-REV-OBS-02`, `LESSONS.md` 178). The CB2 plan §8 now requires all eight standard targets for the final M5 package. The duplicate consolidated §4.35 is renumbered to §§4.35-4.37, this entry is moved from the file end to the top, and the stale TODO line is fixed. Accounting is unchanged.
## 2026-09-24 — M5-CP4 TB1 prepublication gate passes 449/449

Immutable CB1 package `10782841045` executed selector448 plus the frozen focused row449 as 449 fresh exact-filter processes: **449 PASS / 0 RED**, exact-one selection, zero skips, benchmark 0 and exact immutable postflight. Row449 passes on the fixed committed-torus subject. This execution publishes or accepts nothing: selector449 remains unpublished, conjunct8 remains unaccepted and M5 closure remains held. No regression candidate; accounting stays 51/14/37 and debt1. Exact next: `M5-CP4-TB1-REV`.

## 2026-09-23 — M5-DEFN-R2 freezes the final `G4-B004` producer reading

Runtime-free definition chooses disposition B: M5 must prove one pipeline-produced topology region is both multi-isolation with a checked internal seam certificate and owner of an explicitly named periodic quotient relation. Existing selector448 does not join those facts, so M5 closure stays held for bounded M5-CP4. Accepted package/selector, conjuncts1-7, accounting 51/14/37 and debt1 remain unchanged. Exact next: `M5-CP4-CB1`.

## 2026-09-23 — `M5-DEFN-R1-REV`: DEFN-R1 reading not accepted; M5 closure held

Independent Review upholds DEFN-R1's evidence but rejects its reading of the `G4-B004` M5 half. The credited rows 186/239 were already accepted at M1, before the obligation was kept open and assigned to M5, and the reading makes "multi-" redundant. M5 stays open, and next is runtime-free `M5-DEFN-R2` to freeze a non-vacuous reading or block for the user. Selector448, package `10771899191 / cef1c6ee...`, accounting **51 / 14 / 37** and debt **1** are unchanged.

## 2026-09-23 — `M5-DEFN-R1`: focused multi-isolation M5 witness frozen; Review next

Runtime-free Definition chooses `G4-B004` disposition A. The M5 focused minimum is ≥2 distinct isolation sheets joined by producer-emitted checked isolation-seam certificate authority consumed exactly once. Accepted selector448 rows 186/239 are the positives and 183-185/187-188 are the typed falsifiers. §13.1 conjunct 8 is frozen; selector448/runtime package authority, stable **51 / 14 / 37** accounting and project debt **1** remain unchanged. M5 closure is still held pending independent `M5-DEFN-R1-REV`; `M6-DEFN` remains deferred behind it.

## 2026-09-23 — `M5-CP3-TB2-REV`: selector448 accepted; M5 closure held for `G4-B004`; tracker restored

The final M5 Review accepts published selector448 (`70ff0860...c75789`, 448/448 fresh with 917/917 evidence) and promotes package/source `10771899191 / cef1c6ee...`. The reviewing-agent addendum re-verifies that evidence from fresh downloads but **holds M5 closure**. The M5 half of `G4-B004` (a focused positive multi-isolation relation/certificate witness, M4-DEFN §11.2) was never adjudicated. Next is runtime-free `M5-DEFN-R1`, then `M6-DEFN`. The addendum also restores two durable ledgers that 2026-09-22 whole-file writes had overwritten: `Regression_Root_Cause_Tracker.md` (`ce9bf3cb`, 9,837 → 21 lines) and `.agents/Directional/CHANGELOG.md` (`0043dd4c`, 13,317 → 14 lines). It adds `review_check.py ledgers` to catch committed overwrites. A second pass also corrected the first pass's overclaimed isolation census, since whether rows 183-188 already satisfy `G4-B004` depends on a reading `M5-DEFN-R1` must freeze. Stable accounting remains **51 / 14 / 37**; project debt is **1** (M6).

## 2026-09-23 — `M5-CP3-TB1-R16-REV`: corrected pre-publication gate accepted; selector448 frozen for publication

Independent Review accepts R16 at **448/448 PASS** with complete **921/921** immutable evidence, promotes package/source `10763242885 / a8b33cb7145d5a99d47eaf5f70bb12f1c71238d1` under still-published selector430, and discharges both remaining M5 nonzero-Z4 produced debts. Project debt moves **3 -> 1** (M6 only); stable regression accounting remains **51 / 14 / 37**. Exact cumulative selector448 is precommitted at SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`, exact selector430 prefix, owner census 32/300/75/41. M5 remains open for separate `CB20 -> TB2-EXEC -> TB2-REV` publication proof.

## 2026-09-23 — `M5-CP3-DEFN-R1`: same-region nonzero-Z4 relation gauge frozen; CB17 next

## 2026-09-23 — `M5-CP3-TB1-R15-R1-REV`: storage-canonical produced-test authority defect proved; CB19 next

Independent Review upholds authoritative R15-R1 run/job `35869756879 / 107210502570` at **446/448 PASS**, selector430 **430/430**, complete **921/921** evidence and exact immutable postflight. Rows16/17 alone are RED. Frozen §16.3 plus exact CB17 source prove both tests compare canonical storage representation directly with semantic A3 Forward -> Reverse witness authority; the concrete semantic `Q=3` versus stored rotation `1` is the expected inverse representation. Product/fixture/field/A3/selector semantics are unchanged.

`M5-CP3-TB1-R15-R1-CAND-01` is non-stable test-authority storage-representation conflation, +0. DEFN-R1 mechanism and parser observations close; R6 direction, CP2 publication and both nonzero-Z4 produced debts remain open. Exact successor is test-only `M5-CP3-CB19`; compile-green routes to fresh 448-process R16 + mandatory Review.


Runtime-free Definition freezes the missing relation-frame authority proved by R14. For exact semantic A3 Forward/Reverse occurrence faces, raw directed A1 carrier turn `A` and accepted cut gauges `G_F/G_R`, relation rotation is now `Q = G_R^-1 o A o G_F`. Forward anchors relation endpoint gauge; Reverse branch/coordinates are normalized by `Q`; translation is constructed once from the semantic Forward endpoint correspondence; reverse semantics are exactly the inverse action; canonical storage is representation-only. Ordinary A4 cell placement remains unchanged.

The committed torus row4/5 witness is independently valid in relation gauge: first selected carrier `(0,3)`, semantic faces `22 -> 1`, raw directed `A=3`, occurrence cut gauges `0/0`, hence **`Q=3`** before relation publication. `M5-CP3-TB1-R14-REV-OBS-01` is discharged; no fixture/field/A3/selector change and no runtime/build execution occurred. Stable accounting remains **51 / 14 / 37**, debt **3**, R14 candidate unpromoted. Exact successor is runtime-free Code + Build `M5-CP3-CB17`.

## 2026-09-23 — `M5-CP3-TB1-R14-REV`: focused helper accepted; nonzero production gauge definition under-specified

Runtime-free Review independently re-verifies R14 result **916/916**, all 448 exact-filter outcomes at **446 PASS / 2 RED**, selector430 **430/430**, protected ordinals 191/192/247/408, routing owner census **31 / 283 / 75 / 41**, and exact immutable postflight. The CB16 occurrence-branch helper is genuinely green, but produced rows4/5 alone remain exact `PeriodicActionFirstBranchMismatch`.

Static source authority proves the remaining seam is definitional rather than another bounded corrective patch: the cut-open producer omits accepted cut carriers while propagating `faceBranchRotation`, while periodic promotion independently reads raw A1 directed transport across the accepted A3 generator carrier. Frozen §§16/16.1 do not define the exact change of gauge that would make those values one relation frame. `M5-CP3-TB1-R14-CAND-01` is existing `RP-01`, non-stable +0. Stable accounting remains **51 / 14 / 37**, debt **3**; candidate remains unpromoted. The R13 convergence trigger is discharged as triggered, `CB17` is prohibited, and exact successor is runtime-free `M5-CP3-DEFN-R1`.

## 2026-09-23 — `M5-CP3-TB1-R14-EXEC`: CB16 focused authority passes; produced nonzero seam remains semantic RED

Fresh immutable run/job `35824161895 / 107062198724` consumes CB16 candidate/source `10733058003 / 6bad9eb5626e77a234ffb2c14f621195105e4ba1` and completes **448/448** exact-filter processes with exact-one selection/zero skips: branch+semantic+mechanism **11/11**, focused **1/1**, produced **4/6**, selector430 **430/430**, total **446 PASS / 2 RED**, benchmark 0. Result/log artifacts `10734153401 / 10734178551` hash to `ba6ab62396ff572aabb6850643e2d460cbfa0b5b196813bb3b8a91e6a31e3088 / 2e32386ee9e9ad67391f31227d2ddac1504f67f321e94c6296e62cb055b29b7f`; self-manifest is complete **916/916** at `db2ccb2a5e1821018a71032ca9bdcf34e5c0a97fee6ae384d3710656320fd5ce`. Immutable postflight is exact and all prohibited-operation counters remain zero.

The new `M5CP3.PeriodicRelationEndpointBranchUsesAcceptedOccurrenceAuthority` identity PASSes, but produced rows4/5 alone remain exact `PeriodicActionFirstBranchMismatch`. Row4 still does not reach its independent direction comparator; row5 still does not reach transform-only tamper. The R13 convergence trigger has therefore fired. Candidate remains unpromoted; stable accounting stays **51 / 14 / 37**, debt **3**, accepted runtime unchanged. Mandatory successor is runtime-free `M5-CP3-TB1-R14-REV`, which must adjudicate the failed recovery and freeze same-region nonzero-Z4 gauge-definition reconciliation rather than `CB17`.

## 2026-09-23 — `M5-CP3-CB16`: occurrence-carrier branch/gauge authority correction compile green; R14 next

CB16 preserves the bounded-disk chart branch offset while re-expressing periodic endpoint branch authority at the exact accepted A3 occurrence-carrier face, uses that same authority for nonzero relation coordinates, and adds the independent `M5CP3.PeriodicRelationEndpointBranchUsesAcceptedOccurrenceAuthority` falsifier. The first compile exposed a scope/lifetime gap in retaining the already-authored per-face gauge; the same turn repaired only that internal retention path. No A3/fixture/selector retuning, inverse search, semantic fallback, or generated runtime execution occurred.

Final source `6bad9eb5626e77a234ffb2c14f621195105e4ba1` is compile/package GREEN in run/job `35820794471 / 107052021973`. Candidate/log artifacts `10733058003 / 10732709067` hash to `96e313e822bea8ebc6b7478c75c99d4c9245c7d88913b0d14d449a0ec73013f0 / 3cfde85027f85bbb21f22c87918bbb911879f17bdc03014618c819a04343eeaa`; all eight mandatory GMP/GMPXX targets link, root manifest is **28/28** (`f77684128606428a82fe236b749b2d8357948e610745db55f98775a6b4217629`), source archive is `45bb6ccaba68772e998ebd41d75334041b54e5eadb36e4f3c0cd68b46b9b988b`, source receipts are clean and `runtimeExecution=false`. Candidate remains unpromoted and runtime-unproved.

The R13 Review accounting addendum is the current count authority: **51 events / 14 categories / 37 recurrences**, debt **3**. Exact successor is immutable `M5-CP3-TB1-R14-EXEC`: new branch-authority identity + unchanged R13 vector = **448 fresh processes**, benchmark 0, then mandatory Review. If produced rows4/5 are not both green, Review must route to same-region nonzero-Z4 gauge-definition reconciliation rather than `CB17`.

## 2026-09-23 — `M5-CP3-TB1-R13-REV`: first-branch periodic authority root proved

Independent Review upholds R13 at **445/447 PASS** with complete **914/914** evidence and selector430 **430/430**. CB15's storage-canonical -> semantic direction correction is recovery-proved. Rows4/5 alone stop at typed `PeriodicActionFirstBranchMismatch`; the cause is existing `RP-01`: generator transport is owned by exact A3 occurrence-carrier faces while relation endpoint branch/gauge is still copied from local cell/trace-face authority without a deterministic gauge bridge.

Stable accounting remains **50 / 14 / 36**, debt **3**, accepted runtime unchanged and candidate unpromoted. Exact successor `M5-CP3-CB16` performs only the occurrence-branch gauge authority correction plus an independent focused falsifier, compile/package only; fresh R14 follows at 448 processes and mandatory Review.

## 2026-09-23 — `M5-CP3-CB15`: semantic periodic-direction correction compiles green

Runtime-free CB15 deterministically converts canonical stored periodic relations to exact A3 semantic Forward -> Reverse action at checked-product/materialization consumers and adds typed first-false correspondence diagnostics without changing the CB14 nonzero gauge formula. Exact source `4dfe392d28d60b448e2f32253f7d170221ac57ec` compiles all eight required GMP/GMPXX targets in run/job `35811645725 / 107024364608`; candidate artifact `10730261023` is manifest-clean **28/28** with `runtimeExecution=false`. Selector430 remains byte-identical.

No runtime recovery or promotion is claimed. Exact successor `M5-CP3-TB1-R13-EXEC` executes the new semantic-orientation falsifier plus the unchanged 446 R12 identities (**447 fresh processes total**), then mandatory Review. Stable accounting remains **50 / 14 / 36**, debt **3**.

## 2026-09-23 — `M5-CP3-TB1-R12-REV`: storage-canonical periodic orientation regression proved

Runtime-free Review upholds R12's **439/446** semantic result and **912/912** evidence. The ordinary torus/ordinal408 regression is proved as existing `RP-01`: relation storage canonicalization can invert action/routes while exact A3 edge authority remains Forward -> Reverse, and CB14's new checked-product path incorrectly consumes the storage representative as semantic direction. Rows4/5 remain at `PeriodicActionCorrespondenceMismatch`; the new CB14 helper does not expose enough state to identify its first false predicate, so no further gauge change is authorized yet.

Stable accounting remains **50 / 14 / 36**, debt **3**, accepted runtime unchanged. The R6 independent direction observation remains **OPEN** under the later R11-R1 Review amendment; R12 still does not reach its comparator. Exact successor `M5-CP3-CB15` performs the bounded semantic/storage direction correction and adds typed first-false correspondence diagnostics; no runtime in CB15. Compile-green routes to R13 with one new focused semantic-orientation identity plus the unchanged 446 R12 identities (**447 fresh processes total**).

## 2026-09-22 — `M5-CP3-TB1-R11-R1-REV`: CB12 direction recovery proved; periodic endpoint-gauge authority defect localized

Runtime-free Review independently upholds R11-R1 run/job `35778555375 / 106917917282`, complete result self-manifest **912/912** and the fresh **444 PASS / 2 RED** vector. CB12's exact A3 Forward -> Reverse selection is storage-order independent, closing `M5-CP3-TB1-R10-REV-CAND-01` recovery-proved and discharging the R6 direction observation.

The remaining `PeriodicActionCorrespondenceMismatch` is split exactly. The action helper's source-chart/scale/branch preconditions and first endpoint mapping pass; the second endpoint mapping is the first false predicate. On the accepted `[0,1,2,3]` rectangle, reciprocal copies have raw cell-grid `d2=-d1`, so frozen nonzero `rotate(R,d1)==-d2` becomes impossible `rotate(R,d1)==d1`. The root is existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION`: cut-domain cell placement is being used as quotient-seam endpoint authority.

Stable accounting remains **50 / 14 / 36**, debt **3**; accepted runtime unchanged, CB12 candidate unpromoted and selector publication prohibited. Exact successor `M5-CP3-CB14` is runtime-free and must preserve cell placement while deriving independent relation-owned endpoint-gauge authority before fresh R12.

## 2026-09-22 — `M5-CP3-TB1-R11-R1-EXEC`: complete 446-process retry is authoritative semantic RED; Review next

Fresh immutable run/job `35778555375 / 106917917282` consumes CB12 candidate/source
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`. Result/log `10717297354 / 10717921412` verify ZIP SHA-256
`d76dff757919a0c8bb139b6aa4d54840f5344fc9bf0b88f57a5d9629d3807656 /
c09c1c5797640e85ed485d5b6a034970a266c36fb0bbf488441be1674aff0cd0`; corrected self-manifest is **912/912** at
`16dfe18019afee726ce2d2d1845187619c27c74bfa9ff238904237c7de3ab589`, proving CB13's orchestration correction on the full evidence shape.

All **446/446** fresh exact-filter processes select once with zero skips: mechanism **9/9**, focused atlas **1/1**, produced
**4/6**, selector430 **430/430**, benchmark 0 and exact immutable postflight. Produced rows4/5 alone stop while constructing the
nonzero-Z4 witness at exact `PeriodicActionCorrespondenceMismatch`; row4 never reaches materialization/certificate checks and row5
never reaches its transform tamper. The observed frontier is after CB12's Forward -> Reverse pair binding and generator-route
availability, but the product reason merges action-construction failure with route/action rotation disagreement, so exact root
adjudication is reserved for mandatory `M5-CP3-TB1-R11-R1-REV`.

`M5-CP3-TB1-R11-R1-CAND-01` is OPEN / PRODUCT SEMANTIC RED / non-stable / +0 pending Review. Stable accounting remains
**50 / 14 / 36**, debt **3**, accepted runtime unchanged, candidate unpromoted and selector publication prohibited. Invalid R11's
self-manifest candidate closes as orchestration recovery-confirmed; its runtime rows remain zero-credit provenance.

## 2026-09-22 — `M5-CP3-CB13`: fail-closed result-manifest correction validates; fresh R11-R1 next

CB13 corrects only R11's result-finalization control plane. Validation run `35775766068` passes retry-workflow schema,
CB13 self-schema, static authority checks, driver materialization and bounded synthetic manifest tests. The temporary final
manifest now lives outside the result tree, `driver-authority.txt` is copied before generation, `sha256sum -c` is fail-closed,
and manifest rows must equal actual non-manifest files. Synthetic baseline is **3/3**; checksum corruption and late-file count
mismatch are both detected. No Directional runtime, benchmark, configure, compile, relink, discovery or package repair ran.

Result/log artifacts are `10716415780 / 10716260918`. Immutable candidate/source remain
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`; accepted runtime, stable accounting **50 / 14 / 36**, debt **3** and
publication prohibition are unchanged. Exact successor is fresh `M5-CP3-TB1-R11-R1-EXEC`, restarting all 446 processes from
process 1 with zero semantic carry-forward from invalid R11.

## 2026-09-22 — `M5-CP3-TB1-R11-EXEC`: runtime completes; result finalization fails closed; CB13 next

R11 run/job `35771152416 / 106892972571` runs all **446/446** immutable fresh processes on unchanged CB12 candidate
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`, but final evidence packaging is invalid. The caller creates
`SHA256SUMS.new` inside the enumerated result tree, yielding **913 manifest rows vs 912 actual non-manifest files** after
the temporary file is renamed. All 912 real evidence files verify; only stale `./SHA256SUMS.new` fails. Result/log artifacts
are `10714199742 / 10715035437`; the workflow fails closed.

The preserved raw 444/2 process vector is diagnostic only and receives zero semantic credit. Stable accounting remains
**50 / 14 / 36**, produced debt **3**, accepted runtime unchanged and candidate unpromoted. Exact successor is control-plane-only
`M5-CP3-CB13`, followed by fresh `M5-CP3-TB1-R11-R1-EXEC` from process 1 if the finalizer correction validates.

## 2026-09-22 — `M5-CP3-TB1-R10-REV`: R10 diagnosis upheld; insertion-order directed-authority defect proved; CB12 next

Runtime-free independent Review re-derives R10 run/job `35691705806 / 106629921249` as **444 PASS / 2 RED** across all **446/446** exact-one/zero-skip processes: mechanism 9/9, focused atlas 1/1, produced 4/6, selector430 430/430, benchmark 0 and exact immutable postflight. Rows4/5 alone stop at exact `PeriodicActionCorrespondenceMismatch`. Candidate `10678487447` / source `53a21f550cf67e643e8c67a633bb63a20b055c6a` remains unpromoted. R10 result evidence is diagnostic-only for acceptance because `SHA256SUMS` covers **911/912** required non-manifest evidence files; `driver-authority.txt` is the sole omitted file. `R10-EXEC-CAND-01` is upheld as a non-stable orchestration finalization omission and R11 must restore copy-before-regenerate/verify manifest finalization.

Exact source proves CB11's specific raw same-region family/sign pre-veto is removed and R10 produced rows1/2/3/6 remain PASS, closing `R9-REV-CAND-01` as that specific defect and discharging `R9-REV-OBS-01-A`. A distinct frozen-contract violation remains: reciprocal edges are grouped in vector order and same-region generator/action direction is chosen as `pair[0] -> pair[1]`, while frozen §14.3 forbids insertion-order relation authority and §16 requires exact directed A3/source-path orientation. The already-validated interval orientation provides exactly one Forward and one Reverse member; the independent witness also uses Forward -> Reverse. New `M5-CP3-TB1-R10-REV-CAND-01` is OPEN / `RP-01 AUTHORITY_DOMAIN_CONFLATION` / non-stable / +0 / owner CB12 -> R11 Review. `R6-REV-OBS-01` and `M5-CP2-TB1-REV-OBS-01` remain open; both M5 nonzero-Z4 debts remain open. Stable accounting stays **50 / 14 / 36**, project debt **3**, selector publication prohibited. Exact next is product-only runtime-free `M5-CP3-CB12`.

## 2026-09-21 — `M5-CP3-TB1-R6-EXEC`: generator-route branch dynamically proved; Review next

Immutable artifact-only run/job `35606326632 / 106354249393` consumes CB7 candidate `10637998372` / source `8f77ec403f16930145bba5bfc526a5b881b9f166` and completes all **446/446** fresh exact-filter processes with exact-one selection and zero skips: mechanism **9/9 PASS**, focused atlas **1/1 PASS**, produced **0/6 PASS**, selector430 **429/430 PASS** with sole RED ordinal408. Every produced RED reports `PeriodicGeneratorRouteUnavailable`; protected accepted generic-reason ordinals **191, 192, 247** remain PASS. Package/source/execution-view byte+mode postflight is identical, candidate manifest remains **28/28**, benchmark/configure/compile/relink/discovery/repair/mutation counters are zero.

Result/log artifacts `10642347642 / 10642362744` hash to `d23863aa7725b4f82e5a3ee7992c910a2f24bf32252b05260046836ca0470bfc / 6f02d669521bf5c0d1821e656948950b549c6c697ea1a28325cbee1d20f9dcff`; self-manifest is **914/914** at `2130e816714231ea5dfe8cae74f297d0d9ad5b6e21f91c5ce600bf46d4fecb15`. R6 satisfies the dynamic prerequisite for `M5-CP3-TB1-R5-REV-OBS-01` but does not adjudicate the static A4-front-face versus A3-carrier-incidence candidate as causal. `M5-CP3-TB1-R6-CAND-01` remains existing `RP-01` continuation with +0 accounting: **50 / 14 / 36**, debt **5**. Candidate remains unpromoted; exact next is runtime-free `M5-CP3-TB1-R6-REV`.

## 2026-09-21 — `M5-CP3-CB7`: periodic-holonomy branch diagnostics compile/package green; R6 next

CB7 is complete and runtime-free. Semantic commit `a1392c61a4f800512bb8bd73126f993638d1f55c` changes only `SurfaceCellTracing.h/.cpp`, preserves existing phase-front failure values 0–49, and appends values 50–55 to distinguish generator-route unavailability, action-correspondence mismatch, and the four checked holonomy-construction errors. No producer predicate/value, atlas behavior, test, fixture, selector, frozen definition, or acceptance expectation changed.

Mandatory GMP compile/package run/job `35598796960 / 106329775985` builds all eight standard targets from exact source `8f77ec403f16930145bba5bfc526a5b881b9f166` with preflight/build 0/0, explicit GMPXX+GMP linkage, five empty source-status receipts, 28/28 package manifest and `runtimeExecution=false`. Candidate artifact `10637998372` hashes to `1c92e42939081ec9f041f72e916c99d80a700b39a61e3917e8cf8830c5a3f98f`; root manifest/source archive are `1b0bc0b8ce4ff0c339659c7f7c5c3c4e9e26143d352424f7aecf1a2b8f91f737 / dbc083059b4dbd8ea7b429ca32819ce8a91b179b5e2cbd6201a66113d37a9163`; log artifact `10637858795` is `ad626d649fdae2bb8fe591e2a3a38d0ee670ed152967f08cb800c098e4c4645a`. Candidate remains unpromoted; accepted runtime authority stays `10601978228`, accounting **50 / 14 / 36**, debt **5**. Exact next is immutable artifact-only `M5-CP3-TB1-R6-EXEC` on the unchanged 446-process gate, followed by mandatory Review before any semantic repair.

## 2026-09-21 — `M5-CP3-TB1-R2-REV`: failed exact-span recovery refined to hard-feature transport-domain conflation; CB4 next

Independent runtime-free Review upholds R2 **9/9 mechanism PASS, 0/6 produced PASS, selector430 429/430 PASS** and identifies the deterministic remaining product seam: CB3 asks `FieldTransportAtlas::transport` for a mandatory HardRail/hard-feature carrier that atlas construction deliberately excludes from traversal adjacency. Existing exact `CrossFieldEdgeTransition` metadata already owns the edge/face-pair directed matching value. The same seam must also derive orientation from exact parameters so split `ExactSourceEdgePoint` mandatory intervals remain valid.

R2 is merged into the existing stable `M5-CP3-TB1-R1-CAND-01 / RP-01` event, not counted again. Current accounting is **50 / 14 / 36**, debt **5**. Candidate `10620415471` remains unpromoted; accepted runtime authority stays `10601978228` / selector430 **430/430**; all four M5 produced debts stay open. Exact successor is runtime-free `M5-CP3-CB4`; no selector publication is authorized.

## 2026-09-21 — `M5-CP3-TB1-R1-REV`: R1 semantic RED classified as exact-span transport implementation authority; CB3 next

Runtime-free independent Review freshly re-opens R1 run/job `35548642817 / 106179163233`, result/log artifacts `10617583137 / 10616998978`, and accepted package `10601978228`. It independently verifies result self-manifest **908/908**, re-derives **9/9 mechanism PASS, 0/6 produced PASS, selector430 429/430 PASS**, exact-one/zero-skip and immutable postflight, and re-hashes selector430/first427 unchanged. Stable accounting remains **49 / 14 / 35**, debt **5**.

`M5-CP3-TB1-R1-CAND-01` is classified **IMPLEMENTATION AUTHORITY / EXACT-SPAN TRANSPORT CONTRACT VIOLATION / NON-STABLE / RECOVERY REQUIRED**. Frozen §14.3 requires generator carrier and transport to derive from the exact A3 interval `span` / `GlobalTopologyPlan::sourcePath` through existing transition/atlas authority. Candidate `fc2aa5fa...` instead scans all branch transports in the region to require one path-independent aggregate rotation, then assigns identity transport to all source-path steps except one synthetic aggregate rotation on the first. Review does not infer which collapsed `PeriodicHolonomyMismatch` branch fired. Row408 fails before its approved final-kind evolution and all six produced tests fail while establishing the real production fixture, so test/expectation authority is upheld.

Candidate `10615252806` remains unpromoted; accepted runtime authority stays package `10601978228` / selector430 **430/430**; all four M5 produced debts remain open. `M5-CP2-TB1-REV-OBS-01` is carried because its all-publication-identities-green precondition is not met. Exact successor is runtime-free product-only `M5-CP3-CB3` under `Architecture_M5_CP3_CB3_Exact_Span_Transport_Correction_Plan.md`; if the exact A3 path lacks enough directed transport authority without search/guessing, CB3 must stop and return to Review.

## 2026-09-21 — M5-CP3-TB1-R1-EXEC: corrected 445-process gate completes with shared torus production RED

Corrected R1 run/job `35548642817 / 106179163233` is mechanically complete and immutable: all **445** frozen exact-filter processes execute exact-one/zero-skip, benchmark/configure/compile/relink/discovery/repair/mutation counts are zero, and package/source/execution-view postflight is unchanged. Result/log artifacts are `10617583137 / 10616998978` with result self-manifest **908/908**.

Semantic vector is **9/9 mechanism PASS, 0/6 produced PASS, selector430 429/430 PASS**. All six produced torus rows stop at shared `PeriodicHolonomyMismatch`; selector ordinal408 independently receives `Rejected` instead of required `Produced` before its CB2 final-kind assertion. `M5-CP3-TB1-R1-CAND-01` is therefore opened as a non-stable Review-pending shared torus production-reachability candidate. Candidate `10615252806` remains unpromoted; accepted runtime authority stays package `10601978228` / selector430 **430/430**, accounting **49 / 14 / 35**, debt **5**. Exact successor is runtime-free `M5-CP3-TB1-R1-REV`; no same-turn repair is authorized.

## 2026-09-20 — `M5-CP1-TB1-R2-REV`: row6 RED adjudicated test-authority-only; CB3 next

Independent runtime-free Review upholds R2 run `35491016562`: focused **8/9 PASS / 1 RED**, selector430 **430/430 PASS**, exact-one/zero-skip, benchmark **0**, immutable postflight exact. Re-opened source proves row6's materializable helper authors only one periodic relation, so its `>=2` assertion is an invalid witness precondition and the test exits before its claimed permutation/certificate invariant. Row7 independently demonstrates a valid second relation can be appended to the same materializable authority and remain decision-neutral under reversal; row9 independently proves two canonical owners survive reversal at the checked product boundary. Product lookup is ID-keyed at the reviewed seam. `M5-CP1-TB1-R2-EXEC-CAND-01` closes **RP-02 / TEST_AUTHORITY_COVERAGE_GAP / NON-STABLE / TEST-ONLY CORRECTION REQUIRED**. Candidate `10595705100` remains unpromoted; accepted M4 package `10591801825` / selector430 remains authority; accounting **49 / 14 / 35**, debt **5**. Exact next is `M5-CP1-CB3`, changing only row6's test body before mandatory GMP compile/package.

## 2026-09-20 — `M5-CP1-TB1-R2-EXEC`: full artifact-only gate completes; focused row6 is semantic RED

R2 run/job `35491016562 / 106025849497` is **ORCHESTRATION VALID / SEMANTIC NON-GREEN / REVIEW REQUIRED** on unchanged candidate `10595705100`. All planned fresh processes execute with exact-one selection and zero skips: focused **8/9 PASS / 1 RED**, selector430 **430/430 PASS**, benchmark **0**. Result artifact `10598684066` hashes to `5896fee5600a6f842fcefd08534d2a21a67cedee8a38ed67daaeace755d2a5dd`; immutable package/source/execution-view postflight is exact and no build/discovery/repair/mutation occurred.

The sole RED, `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`, fails its precondition at **1 vs 2 periodic relations** before reordering, materialization or certificate comparison. `M5-CP1-TB1-R2-EXEC-CAND-01` is **OPEN / RP-02 TEST_AUTHORITY_COVERAGE_GAP / INVALID WITNESS PRECONDITION / NON-STABLE** pending independent Review. Candidate stays unpromoted; accepted M4 package `10591801825` / selector430 remains authority, accounting **49 / 14 / 35**, debt **5**. Exact next: runtime-free `M5-CP1-TB1-R2-REV`; no retry or corrective CB before Review.

## 2026-09-20 — `M5-CP1-CB2`: canonical R2 executor statically GREEN; runtime remains unadjudicated

CB2 is **COMPLETE / STATIC GREEN / CONTROL-PLANE CORRECTION PROVED / RUNTIME-FREE**. It adds canonical harness `.agents/Directional/tools/m5_cp1_tb1_r2_artifact_only_harness.sh` (`b706d03adde7d7d3daacb6ac46c4cb35468a40e162d7fb9d1617d4e562d37302`) and executor template `.agents/Directional/tools/m5_cp1_tb1_r2_executor.yml` (`9c9c2527176645d143cf1f972ad5d493db44bc819179fb04a1845f7bd20a12a1`). Immutable local preflight re-proves candidate `10595705100`, manifest **28/28**, selector430 **430**, routing map **430 unique / owners 31/283/75/41**, and all nine focused identities without executing a Directional binary. Final static run `35490228347` passes caller/template SchemaStore validation plus canonical hash, `bash -n`, permission-ceiling, no-timeout/watchdog and deterministic round-trip checks; proof artifact `10598826679` is `d765ed4d54b07f130e83f44dd499d61584e6dab1693b32db9472d14004b05b2d`. Candidate remains unpromoted; accounting stays **49 / 14 / 35**, debt **5**. Exact next is fresh artifact-only `M5-CP1-TB1-R2-EXEC`; R1 contributes zero semantic evidence.

## 2026-09-20 — `M5-CP1-TB1-R1-EXEC`: executor payload corrupt; zero semantic runtime

R1 is complete as a turn but **BLOCKED / PRE-RUNTIME ORCHESTRATION / ZERO SEMANTIC CREDIT**. Terminal run/job `35486023017 / 106012455346` passed schema validation then failed decoding the temporary executor GZip payload (`crc error` / `length error`) before any Directional process. Focused **0/9**, selector430 **0/430**, benchmark **0**; no result artifact. Diagnostic artifact `10597540714` has SHA-256 `818b69adc1f3e459a2d97bfe7e31335efeeb5600c42f432da279b897d05cd019`. Candidate `10595705100` remains unchanged/unpromoted; accepted M4 authority remains package `10591801825` / selector430 **430/430**, accounting **49 / 14 / 35**, debt **5**. Exact next: runtime-free `M5-CP1-CB2`, then fresh R2 only after static executor proof.

## 2026-09-20 — `M5-CP1-TB1-PREFLIGHT-REV`: routing defects recovery-proved; corrected artifact-only retry frozen

Runtime-free independent Review upholds the blocked TB1 fail-closed result and re-derives both routing fixes from immutable bytes. Accepted M4-TB3 artifact `10592987234` yields `identity-map.tsv` SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, 430 unique rows and owners **31/283/75/41**; candidate `10595705100` verifies at ZIP SHA-256 `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea` / manifest **28/28** and contains exact ninth identity `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`. `CAND-01/02` and `M5-CP1-TB1-EXEC-OBS-01` close non-stably as routing/process recovery proved.

The corrected sole next plan is `Architecture_M5_CP1_TB1_Artifact_Only_Test_Benchmark_Plan.md`: unchanged package/source, exactly 9 focused identities, selector430 **430/430**, corrected map SHA + suite only. Row9 uses `direct_periodic_owner_product()` and remains **CP1 mechanism-only**; no M5 production debt closes. Accepted runtime authority remains M4 package `10591801825`, stable accounting **49 / 14 / 35**, debt **5**. No Directional runtime, build, product/test/fixture/selector mutation, or benchmark occurred in Review.

## 2026-09-20 — `M5-CP1-TB1-EXEC`: pre-runtime frozen-plan blocker; no semantic runtime

TB1 is **BLOCKED / PRE-RUNTIME ORCHESTRATION PLAN DEFECT / ZERO SEMANTIC CREDIT**. Candidate artifact `10595705100` verifies at provider/download SHA-256 `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`, package manifest **28/28**, exact source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`, GMP/GMPXX, executable modes and selector430 bytes. Execution then stops before any Directional process because the frozen plan contains a 63-character identity-map digest literal while accepted M4-TB3 authority is `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, and its ninth focused exact filter names nonexistent suite `M4CP4`; the compiled non-vacuous test is under `SurfaceCellTransitionQuotient`. No silent plan repair/substitution was made. Runtime is **0/9 focused, 0/430 selector, 0 benchmark**; accepted M4 package `10591801825` / selector430 remains authority, accounting **49 / 14 / 35**, debt **5**. Exact next: independent `M5-CP1-TB1-PREFLIGHT-REV`.

## 2026-09-19 — `M5-CP1-CB1`: canonical relation certificates compile/package GREEN

CB1 is **COMPLETE / COMPILE GREEN / RUNTIME UNADJUDICATED** at semantic source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`. The bounded CP1 slice replaces ordinal periodic relation identity with topology-region + canonical generator/cut carrier identity, preserves relation IDs through component aggregation, permits topology-distinct same-region relations, publishes producer-selected ordered relation-path certificates, and validates those certificates downstream without semantic BFS/DFS route reconstruction. Focused CP1 regressions are authored and compiled but not executed.

Mandatory GMP compile run/job `35478855426 / 105992849133` is GREEN for all eight standard package targets with `runtimeExecution=false`; candidate artifact `10595705100` has provider SHA-256 `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`, manifest **28/28**, source archive `4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9`, and explicit GMPXX+GMP link evidence. Accepted runtime authority remains M4 package `10591801825` / selector430 **430/430**; stable accounting stays **49 / 14 / 35**, debt **5**. Exact next: artifact-only `M5-CP1-TB1-EXEC` under `Architecture_M5_CP1_TB1_Artifact_Only_Test_Benchmark_Plan.md`.

## 2026-09-19 — `M4-CP4-TB3-REV`: selector430 accepted; CP4 and M4 close

## 2026-09-19 — M5-DEFN definitions frozen

- Froze `Architecture_M5_Frozen_Definitions.md`: canonical periodic relation IDs are content-derived from topology-region + canonical generator/cut carrier paths; action/transport is relation value.
- Froze producer-selected ordered relation-path certificates and the bounded consumer cutover that removes verifier-side semantic reachability reconstruction.
- Froze the CP2 typed failure matrix (missing, duplicate, conflicting, nonreciprocal, representation-renumbered) and unused-valid-relation invariance.
- Preserved all four M5 produced-witness debts and their original discriminators; no direct/draft mechanism evidence receives production credit.
- Issued `Architecture_M5_CP1_Code_Build_Plan.md`; exact next is `M5-CP1-CB1`. No production/test/selector/build semantic mutation, compile, test, benchmark, or Directional runtime occurred in M5-DEFN.
- Operational note: repository inspection began before explicit `READ_MODE=snapshot`; the miss was caught before semantic editing, and subsequent review used immutable snapshot `1cef1133ecfe59eeeee220b37a907301f9315dc7` / artifact `10594140365`. No new regression event; tool ledger before correction remains partial/unknown.

Independent runtime-free Review re-opens CB8 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` and TB3 result `10592987234`, independently verifies package **26/26**, selector430 **430 rows / `1c412850...9db6`** with exact selector427 prefix, owners **31/283/75/41**, all **430/430 PASS** one-selected process rows/raw hashes, result manifest **447/447**, and exact package/source/execution-view postflight. Static Review also re-derives non-vacuous work/boundedness, produced same-region multiplicity-two, and flat/non-flat zero-transport contracts. Package `10591801825` is promoted as accepted current M4 runtime authority; `M4-CP4` and M4 are **CLOSED / ACCEPTED**. Stable accounting remains **49 / 14 / 35**, debt **5**; four debts remain M5-owned and one remains M6-owned. Exact next is planning-only `M5-DEFN`.

## 2026-09-19 — `M4-CP4-DEFN-R2`: Reading B re-homes closed-complex debt to M6; selector430 publication frozen

Runtime-free DEFN-R2 proves the remaining candidate-bearing arrangement is not M4/A4 authority: A4 owns per-region `RegionCellComplex`, A5 owns explicit occurrence complex, and current `SurfaceCellPipelineContext` is diagnostic-only with `hasArrangement` published after strands/embedding/global arrangement construction. The unchanged closed-complex `G4-B002` debt therefore moves to M6-CP1 mechanism / M6-CP3 direct-production proof; debt remains **5**, stable accounting **49 / 14 / 35**, and accepted package `10565723112` / selector427 **427/427** is unchanged. R2-reviewed work/boundedness, same-region multiplicity-two and exact zero-transport rows freeze selector430 publication: SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, owners **31/283/75/41**. CP4 remains open; exact next is publication-only `M4-CP4-CB8`, then final artifact-only selector430 runtime + Review.

## 2026-09-19 — `M4-CP4-TB2-R2-REV`: three focused obligations credited; closed-complex authority reopens definition

Runtime-free Review independently re-derives R2 as **431 = 430 PASS / 1 RED**, focus **3/1**, selector427 **427/427**, owners **30/281/75/41**, exact-one/zero-skip and exact immutable postflight. Row1 work/boundedness and row3 same-region multiplicity-two receive Review credit. Row4 runtime-proves CB5's exact `NonIntegralCycleLift` correction, closing `M4-CP4-TB1-R3-CAND-03` correction-runtime-proved/non-stable. The sole row2 RED remains `NotProductionReady/tracing` before retained arrangement even after CB5 reused row408's accepted 18-hard-edge torus setup; row408 proves only `phaseFront == Produced`, not `surfaceCellContext.hasArrangement`. The closed-complex debt/candidate is therefore escalated to **ARCHITECTURE_DEFINITION / PRODUCED-SUBJECT STAGE OWNERSHIP / NON-STABLE** under exact successor `M4-CP4-DEFN-R2`. Accepted package `10565723112`, selector427, accounting **49 / 14 / 35** and debt **5** remain unchanged; composite stays unpromoted.

## 2026-09-19 — `M4-CP4-TB2-R2-EXEC`: complete composite gate is trustworthy semantic non-green

R2 run/job `35449574130 / 105914294127` is **ORCHESTRATION VALID / SEMANTIC NON-GREEN / REVIEW REQUIRED** on the unchanged CB4 `10578784752` + CB5 `10582435470` composite. Installed caller validation run `35449546449` is GREEN, including the reusable-workflow permission ceiling. Runtime executes all **431** planned fresh processes: focus **3 PASS / 1 RED**, selector427 **427/427 PASS**, total **430 PASS / 1 RED**, exact-one selection and zero skips. Mandatory package/source/execution-view postflight is exact; all configure/compile/relink/discovery/repair/mutation and benchmark counters are zero. The sole RED is `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle`, stopping at `NotProductionReady/tracing` before retained arrangement authority. It is classified as the same non-stable test-authority witness-reachability root as `M4-CP4-TB1-R3-CAND-01`; accepted selector authority does not regress, so accounting remains **49 / 14 / 35**, debt **5**. Row4's CB5 exact typed correction and row3 multiplicity-two are mechanically green but await Review credit. Exact successor: runtime-free `M4-CP4-TB2-R2-REV`.

## 2026-09-19 — `M4-CP4-CB7`: reusable caller permission ceiling corrected and statically GREEN

CB7 is **COMPLETE / CONTROL-PLANE CORRECTION GREEN / RUNTIME-FREE**. Commit `bbb64a7923900c0b0ce8c52680ef4588b85c691a` changes exactly the durable caller top-level `contents: read` to `contents: write`, leaving reusable-workflow permissions, `commit_run_file: false`, harness and semantic gate unchanged. Corrected caller SHA-256 is `488326cd8cbf1ee4078796b8ecd7031f578b87272eb62df5fa2d7d42fd42d719`; harness remains `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba`. Final run `35446771294` is GREEN for schema validation plus static permission-ceiling/timeout checks; receipt artifact `10585314838` records `static_permission_ceiling_valid=true`. No Directional runtime/compile/repackage occurs. Accepted authority stays package `10565723112` / selector427 **427/427**, accounting **49 / 14 / 35**, debt **5**. Exact next: fresh `M4-CP4-TB2-R2-EXEC` from ordinal1, then mandatory Review.

## 2026-09-19 — `M4-CP4-TB2-R1-EXEC`: installed caller validates but reusable permission ceiling blocks startup

R1 performed mandatory stale-evidence cleanup, installed the exact CB6 caller bytes, re-hashed them through source snapshot run `35444548694` to SHA-256 `88ab6b51201801f2468add9b3f1ee4ad890c751052c48b1a7c0e9f773af8699c`, and schema-validated the exact installed workflow in run `35444528913` (`valid=true`). Runtime trigger run `35444642320` then ended `startup_failure` with **zero jobs**: the caller's top-level `contents: read` ceiling cannot satisfy the called observer reusable's optional `contents: write` branch-file job. No harness, package, focus or selector runtime started, so R1 is **ORCHESTRATION INVALID / NO SEMANTIC LEDGER** and receives zero credit. Accepted authority remains package `10565723112` / selector427 **427/427**, accounting **49 / 14 / 35**, debt **5**. Exact next: runtime-free `M4-CP4-CB7`, then fresh `M4-CP4-TB2-R2-EXEC` from ordinal1.

## 2026-09-19 — `M4-CP4-CB6`: timeout-free R1 GitHub Actions control plane validated

CB6 is **COMPLETE / CONTROL-PLANE CORRECTION GREEN / RUNTIME-FREE**. Commit `cac96243ef6489107db03e47b11467efc61cd918` adds the exact R1 harness (SHA-256 `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba`, mode 755) and caller draft (SHA-256 `88ab6b51201801f2468add9b3f1ee4ad890c751052c48b1a7c0e9f773af8699c`). Exact caller schema validation run `35441895809` is GREEN. The successor plane runs on GitHub Actions without a workload `timeout-minutes` or harness timeout/watchdog, freezes unchanged CB4 `10578784752` + CB5 `10582435470`, selector427 and 30/281/75/41 routing, and requires all 431 fresh processes plus immutable postflight. CB6 executed no Directional runtime/compile/repackage. Accepted authority stays package `10565723112` / selector427 **427/427**, accounting **49 / 14 / 35**, debt **5**. Exact next: `M4-CP4-TB2-R1-EXEC` from ordinal1, then mandatory Review.

## 2026-09-19 — `M4-CP4-TB2-EXEC`: composite preflight exact; full gate orchestration-invalid

Artifact-only TB2 verified exact CB4 `10578784752` + CB5 delta `10582435470` provider hashes, manifests **28/28 + 24/24**, source archives/receipts/GMP, selector427 **427 rows / 34,783 bytes / `f9c883...e86f`**, owner census **30/281/75/41**, executable modes, fixture census and composite routing. The first 431-process gate was then interrupted by an external 300-second foreground container-tool timeout after 118 completed processes, so it has **no semantic ledger**. A same-turn restart was terminated after the cadence rule was re-opened and is likewise quarantined with zero credit. Both immutable package/source/view surfaces remain byte+mode unchanged. `M4-CP4-TB2-EXEC-CAND-01` is OPEN / ORCHESTRATION / NON-STABLE; stable accounting stays **49 / 14 / 35**, debt **5**, accepted authority package `10565723112` / selector427 **427/427**. Exact next: runtime-free `M4-CP4-CB6`, then fresh `M4-CP4-TB2-R1-EXEC` from ordinal1.

## 2026-09-19 — M4-CP4-CB5 remaining test-authority corrections compile GREEN

CB5 changes only the row2 produced-closed-complex test precondition and row6 exact typed expectation. Mandatory GMP compile run/job `35436226379 / 105879256297` is GREEN for the two affected targets from exact source `4e9ff5003c8dd165dd614c25dd95f0308403719b`, with `runtimeExecution=false`; delta artifact `10582435470` hashes to `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`. Product/fixture/selector/CMake semantics and M5-owned periodic focused identities are unchanged. Accepted M4 runtime authority remains package `10565723112` / selector427 **427/427**. Exact next is artifact-only `M4-CP4-TB2-EXEC` on the frozen CB4+CB5 composite owner view, then mandatory Review.

## 2026-09-19 — M4-CP4 R3 Review invokes periodic-authority definition stop

Independent Review upholds R3's immutable evidence (**429 PASS / 4 RED**, selector427 **427/427**) but does not promote candidate `10578784752`. CB4's three original R2 precondition corrections are runtime-proved; remaining row2 and row6 issues are test-authority reachability/typed-expectation gaps. Rows3/4 materially advance to `Produced` yet publish zero explicit periodic relations; current source intentionally lacks canonical second same-sheet periodic ownership, so frozen CP4's Review/DEFN stop fires. Accepted M4 authority remains package `10565723112`, stable accounting **49 / 14 / 35**, debt **5**. Exact next is runtime-free `M4-CP4-DEFN-R1`; no periodic debt is weakened or deleted.

## 2026-09-19 — M4-CP4-CB4 test-authority correction compiled GREEN

CB4 is **COMPLETE / TEST-AUTHORITY CORRECTED / COMPILE GREEN / RUNTIME UNADJUDICATED**. Exact source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a` changes only three authorized focused test files: the rawfield reader now honors `(degree, faceCount)`, produced-torus periodic-owner witnesses use accepted row408 hard-rail production setup and require produced relation/edge multiplicity before credit, and the zero-transport negative independently proves nonzero intrinsic angle defect on a genuinely non-flat fan. Product/fixture/selector/benchmark/CMake semantics are unchanged; selector427 remains SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. Mandatory GMP/GMPXX compile run/job `35425760541 / 105851314444` is GREEN for all eight standard targets with `runtimeExecution=false`; candidate artifact `10578784752` has provider SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`, manifest **28/28**, source archive `dd7dd3351ad3ea10f56ef9ce2021fc8ea84e10d682560b93f70ca1d79b089175`. Accepted authority remains package `10565723112`; stable accounting **49 / 14 / 35**, debt **5**. Exact next: immutable `M4-CP4-TB1-R3-EXEC`, then mandatory Review.

## 2026-09-17 — `M4-CP-SCALE-TB12-R2-REV`: multi-component boundary-row support owns the RP-07 defect; CB16 next

Runtime-free Review independently re-verifies CB15 candidate artifact `10517300204` / source `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21`, its **28/28** package manifest/GMP evidence, selector426 `41f4d559...b5114` with exact first425 `e0e0f394...790e0b`, retained genus-two fixture hashes and TB12-R2's one-process semantic RED. The discriminator `row=14, BoundaryLoop, supportEdges=34, uniqueFromFaces=34, SupportEdgeReused, currentFace=0, sourceEdge=0-72` is re-derived against source: duplicate outgoing origins are excluded, and reuse at the least/canonical start face means the first successor orbit closes before all algebraic row support is consumed.

Review assigns the existing non-stable `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION` defect to `FieldTransportAtlas`'s assumption that each algebraic `dual_cycles` row is one simple connected face loop. Boundary rows are algebraic sums and may contain multiple closed successor components. The correction must preserve row coefficients/kind/turning lift and consume every component canonically; changing `dual_cycles`, raw field or fixture is prohibited. Accepted runtime authority stays package `10473134357` / selector426 **426/426**; accounting stays **49 / 14 / 35**, debt **5**; S5 remains unaccepted. Exact next is compile-only `M4-CP-SCALE-CB16`; no selector427 or runtime is authorized.

## 2026-09-16 — `M4-CP-SCALE-TB8-REV`: CB9 S4 prerequisite test authority rejected; CB10 correction next

- Runtime-free Review independently reopened CB9 candidate `10428779988` / source `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf`, TB8 run/job `35053875774 / 104659839191`, result/log artifacts `10430235842 / 10430201060`, nested evidence, focused source and retained torus/sphere authority. TB8 remains valid mechanical RED with focus **1/1 executed / RED**, selector425 **0/425 executed / 425 UNEXECUTED**, and exact immutable postflight.
- `M4-CP-SCALE-TB8-EXEC-CAND-01` — **CLOSED / TEST-AUTHORITY WITNESS-NUMERIC TRANSPLANT / NON-STABLE**. The empty-cut negative is production-reachable and the raw oracle is structurally independent, but CB9 copied prescribed-sphere graph-count constants `V/E/F=18/30/18,c=1` onto the torus. Accepted torus pre-cut authority is `V=48,E=48,c=4` with four annular complement components. Correct necessary-condition arithmetic is `b1=4`, `F_required=3`, `F_observed=4`, hence a mismatch/reject.
- Review also rejects requiring independent connected complement-component count to equal product face-walk-orbit `certificate.faceCount` on the non-cellular negative. CB10 must pair the early oracle one-way (`early reject => unchanged final certificate rejects`) and preserve positive/adversarial/enumeration/decision-neutral falsifiers. The controls after the first negative assertion received zero TB8 runtime credit.
- Accepted runtime authority remains TB7 package `10425344367` / source `01b1124af094044e32d6887ff0615881333d12ce` / selector425 **425/425**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, debt **5**. `M4-CP-SCALE-DEFN-OBS-03` remains open through `CB10 -> TB9-EXEC -> TB9-REV`; no product S4 activation or selector426 is authorized. Exact next: `M4-CP-SCALE-CB10`.

## 2026-09-16 — M4-CP-SCALE-TB8-EXEC focused S4 prerequisite RED; Review mandatory

Artifact-only run/job `35053875774 / 104659839191` consumed immutable CB9 candidate `10428779988` / source `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf`. The focused S4 prerequisite selected/executed **1/1** but failed its first assertion with expected negative `vertexCount=18` versus observed `48`; no structured receipt was reached. Frozen fail-fast policy therefore left selector425 **0/425 executed, 425/425 explicitly UNEXECUTED**. Exact package/source/execution-view postflight passed and no configure/compile/relink/repair/discovery/mutation/benchmark operation occurred. Accepted runtime authority remains TB7 package `10425344367` / selector425 **425/425**, stable accounting **49 / 14 / 35**, debt **5**. Exact next is mandatory `M4-CP-SCALE-TB8-REV`; TB8-EXEC makes no root-cause or candidate-promotion decision.

## 2026-09-16 — M4-CP-SCALE-CB9 S4 prerequisite compile/package GREEN

CB9 changes only `tests/FieldAlignedCurveNetworkTests.cpp` at semantic source `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf`, adding one producer-owned diagnostic independent Betti/face-count oracle with production-reachable negative plus positive/adversarial/enumeration/decision-neutral controls. Product topology decisions/final certificate/CMake/fixtures remain unchanged and selector425 stays byte-frozen at 425 rows / `e0e0f394...790e0b`. Authoritative GMP/GMPXX compile run/job `35051977240 / 104654125358` is GREEN with no Directional runtime; candidate artifact `10428779988` has provider SHA-256 `7470947a...2bd6`, packaged source `cd0d0c7e...de55`, and its 26-entry manifest verifies completely. Accepted runtime authority remains TB7 package `10425344367`; stable accounting remains **49 / 14 / 35**, debt **5**. Exact next is artifact-only `M4-CP-SCALE-TB8-EXEC`, then mandatory Review.

# 2026-09-16 — M4-CP-SCALE-TB7 Review promotes selector425; S4 prerequisite next

TB7 Review is **APPROVED**. Independent re-derivation of immutable CB8 artifact `10425344367` / source `01b1124af094044e32d6887ff0615881333d12ce` and TB7 evidence confirms selector425 **425/425 PASS** in 425 fresh exact-filter processes, exact selector424 prefix, owner census **30/279/75/41**, fresh S3 row425 receipt, and byte-identical package/source/execution-view postflight. Package `10425344367` / selector425 becomes accepted current M4 runtime authority. `M4-CP-SCALE-TB6-REV-OBS-01` is **DISCHARGED** and S3 receives cumulative required-green credit.

Initial TB7 attempt `35044943849` remains zero-credit orchestration provenance: it failed with shell exit 127 before checkout/harness/runtime. No new product regression or accepted-green loss exists; stable accounting remains **49 / 14 / 35**, debt **5**. CP-SCALE remains OPEN. Exact next `M4-CP-SCALE-CB9` owns only the S4 independent-oracle/reachability prerequisite, leaving product topology decisions and selector425 frozen; no selector426 or runtime is authorized in CB9.

# 2026-09-16 — M4-CP-SCALE-TB7 selector425 mechanically GREEN; mandatory Review next

TB7-EXEC is **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED**. Fresh authoritative retry run/job `35045130314 / 104633231692` consumed immutable CB8 artifact `10425344367` / source `01b1124af094044e32d6887ff0615881333d12ce` and executed selector425 **425/425 PASS** as 425 fresh exact-filter processes in exact selector order. Row425 `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination` ran freshly and passed 1/1; no TB6 focused execution was imported. Owner execution census is **30/279/75/41** with zero RED, SKIP, crash, timeout, selection mismatch or unexecuted rows.

Package/source/execution-view pre/post censuses are exact matches; package manifest remains 28/28; selector425 remains `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` with exact selector424 prefix `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`. No configure, compile, relink, repair, discovery, mutation or benchmark execution occurred. Result/log artifacts are `10426872680 / 10427326246` with provider SHA-256 `676f6f5adab0992a8d334c5952fc133c3d0b3fa4eb93dd5128180ee4705f02b2` / `b8374c33152362ab2feab31b4b2ab87f8118e7ed9b5b2fe275669bcbff60ca4f`; nested evidence ZIP SHA-256 is `436ef2722c176e92aca64c4d052d7953b979ead0e23bda33e16eb5d317a41c4d` and its 1298-entry manifest SHA-256 is `5639b84372c453ee42b8c3fbf0d09425ca0a34da72dd0629ceb2769982f14622`.

Initial attempt run/job `35044943849 / 104632684747` is orchestration-only provenance: the temporary workflow had not checked out the harness and exited 127 before runtime. The corrected fresh retry is the only TB7 runtime authority. No product regression was observed; stable accounting remains **49 / 14 / 35**, debt **5**. EXEC does not promote selector425. Accepted authority remains TB6 package `10418328122` / selector424 pending mandatory `M4-CP-SCALE-TB7-REV`.

# 2026-09-16 — M4-CP-SCALE-CB8 selector425 published; compile/package GREEN; TB7 artifact-only runtime next

CB8 is **COMPLETE / COMPILE-GREEN / RUNTIME UNADJUDICATED**. Published `Architecture_M4_CP_SCALE_CB8_Required_Green_Selector_425.txt` as the exact selector424 prefix plus `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`: **425/425 unique rows**, SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, first424 prefix `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`, unique producer definition, owner census **30/279/75/41**. No product/test/fixture/CMake semantic bytes changed and no selector426 was published.

Compile/package run/job `35042417046 / 104624909472` checked out exact source `01b1124af094044e32d6887ff0615881333d12ce`, preflighted `directional_core`, compiled all approved targets successfully, linked GMP/GMPXX, recorded `exactArithmeticBackend=GMP`, preserved clean pre/post source status and a self-verifying package manifest, and executed **no Directional runtime** (`runtimeExecution=false`). Result artifact `10425344367` has provider digest `sha256:1e29c9f3348b2e153d563c7e94acdaea52be8f16f6520fa8603fa084bba734bc`; activity-log artifact `10426031026` has `sha256:24f78df126e3935fc70ae13d33331995b025472141794931d9cae30777c998cc`.

Accepted runtime authority remains TB6 package `10418328122` / selector424 **424/424**. Exact next is `M4-CP-SCALE-TB7-EXEC`: immutable artifact-only selector425 **425/425** in 425 fresh exact-filter processes, followed by mandatory `M4-CP-SCALE-TB7-REV`. `M4-CP-SCALE-TB6-REV-OBS-01` remains open until that Review. Stable accounting remains **49 events / 14 categories / 35 recurrences**, debt **5**.

Control-plane note: this ChatGPT Web session corrected an initial source-snapshot ordering miss immediately, and workflow observer comments were delayed for snapshot/Drive/compile triggers, so exact run IDs were recovered from Actions inventory without retriggering. The actual Drive/compile callers were SchemaStore-validated before activation; the one-time schema-validator bootstrap caller itself was locally YAML-checked because recursively validating the validator caller was unavailable. These are process/control-plane deviations only and do not alter selector or compile evidence.

## 2026-09-16 — `M4-CP-SCALE-TB6-REV`: package promoted under selector424; S3 publication authorized

- Independent Review reopens candidate/result/log bytes, verifies the 1302-entry evidence manifest, re-hashes selector424/prefix423, rebuilds owner census **30/278/75/41**, reopens all 424 selector raw outputs, re-derives the focused S3 receipt/discriminator matrix and source-audits exact full-state typed termination.
- **PROMOTE** package `10418328122` / source `153047c3f92e9b9b784e11eaee1ede2de5628470` under unchanged selector424 **424/424**. `M4-CP-SCALE-DEFN-OBS-02` is discharged. Focused S3 proof is accepted for selector publication, not cumulative selector credit.
- New `M4-CP-SCALE-TB6-REV-OBS-01` requires selector425 = exact selector424 prefix + S3 row425, expected SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, owner census **30/279/75/41**, then fresh 425/425 + Review. Stable accounting remains **49 / 14 / 35**, debt **5**.
- Review folds five consumed/superseded CP-SCALE turn records into `M4_Consolidated_Record.md` §2.54. Exact next is publication-only `M4-CP-SCALE-CB8`; no product/test/fixture/CMake semantic change or runtime is authorized.


## 2026-09-15 — M4-CP-SCALE-TB6-EXEC GREEN; mandatory Review next

- Artifact-only S3 runtime is mechanically GREEN on immutable CB7 candidate `10418328122`: focused exact-repeat termination **1/1 PASS** and accepted selector424 **424/424 PASS** in fresh processes, with exact immutable postflight and no rebuild/mutation.
- First attempt stopped pre-runtime on a harness-only GMP dependency assertion; fresh corrected retry passed without changing candidate bytes. No product-semantic regression was observed. Accepted runtime authority remains TB5 until `M4-CP-SCALE-TB6-REV`.

## 2026-09-15 — `M4-CP-SCALE-CB7`: S3 exact-repeat typed termination compile GREEN

CB7 candidate source `153047c3f92e9b9b784e11eaee1ede2de5628470` publishes typed `LimitCycleTermination` only from complete exact `(sourceFace, branch, incomingCarrier, entryPoint)` repetition, retains the exact repeated-state locus, and leaves combinatorial recurrence/step budget fail-closed. Focused producer identity `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination` is compiled but remains outside unchanged selector424; selector425 was not authored. Authoritative GMP/GMPXX compile run/job `35022869891 / 104562750677` is GREEN with `runtimeExecution=false`; candidate artifact `10418328122` has provider SHA-256 `a9f33bce6029022495fccbc4680da9bdd25cf41aa5cc733b2c04335e156ac16e`, packaged source SHA-256 `703dcc22f18ed565b623ef4eb43e117cd8acfd5d982ed0bde111d5cfdd56e0ff`, and manifest **28/28 PASS**. An earlier compile exposed one accidental missing test-local `NetworkNodeId` alias; the surgical restoration is included in the exact candidate source. Accepted runtime authority remains TB5 package `10407605295` / selector424 **424/424** pending TB6 + Review. Exact next: artifact-only `M4-CP-SCALE-TB6-EXEC`, then mandatory `M4-CP-SCALE-TB6-REV`.

## 2026-09-15 — `M4-CP-SCALE-TB5-REV`: selector424/package promoted; S2 cumulative credit accepted

Runtime-free Review independently reopened TB5 result/log/nested evidence and the immutable CB6 package, re-hashed selector424/prefix423, recomputed the **30/278/75/41** owner partition from packaged source+CMake, parsed the complete 424-process ledger, and re-derived the six-subject independent S2 integer oracle plus non-vacuous Filter/ExactFallback routes. Package `10407605295` / source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3` is promoted as current M4 runtime authority under selector424 **424/424**; `M4-CP-SCALE-TB4-REV-OBS-01` is discharged. No regression/candidate opens; accounting remains **49 / 14 / 35**, debt **5**. CP-SCALE remains open. Exact next is runtime-free `M4-CP-SCALE-CB7`, bounded to S3 exact full-state repeat -> typed `LimitCycleTermination`; selector424 stays frozen and selector425 is not published in CB7.

## 2026-09-15 — `M4-CP-SCALE-TB4-REV`: package promoted; S2 publication authorized

Independent runtime-free Review promotes immutable package `10378808176` / source `905dabe390577d63ed6a9289e3f3d53aa4144936` under unchanged accepted selector423 after fresh TB4-R1 focused S2 **1/1 PASS**, cumulative selector423 **423/423 PASS**, exact immutable postflight, six-subject Filter/ExactFallback non-vacuity and independent integer-oracle re-derivation. S2 is publication-authorized but is **not yet cumulative selector credit**. Stable accounting remains **49 / 14 / 35**, debt **5**; CP-SCALE remains open. Exact next is `M4-CP-SCALE-CB6`, limited to exact selector424 publication plus runtime-free compile/package; later TB + Review must prove selector424 424/424.

## 2026-09-15 — `M4-CP-SCALE-TB3-REV`: candidate rejected; regular-star invariant still false

Runtime-free Review independently re-opened TB3 evidence and candidate source and rejects package `10375799491` / source `ba6e204d9daef39bfc6c168b659fc1b94f2b5b9b` as **TEST-AUTHORITY PRECONDITION FAILURE / DUPLICATE KNOWN ROOT / NON-STABLE**. The three-right-angle center has `K=pi/2`, while CB3's authored field derives aggregate cycle effort `0`, so production correctly yields center lift `1`, a singular center and `CycleTransportMismatch`; face 2 also reverses secondary handedness. This is the existing `M3-CP4c3-TB7-CAND-02` / TB2 / Lesson 22r root, not a product comparator defect. TB3's 423/423 explicit UNEXECUTED failure-path remainder discharges `M4-CP-SCALE-TB2-REV-OBS-01`. Accepted package `10360085644` / selector423 423/423 remains authority; stable accounting stays **49 / 14 / 35**, debt **5**. Exact next is test-only `M4-CP-SCALE-CB4`: independently certify consistent handedness plus `q4` winding `-1` / cycle effort `-2*pi`, zero lift/no singularity/atlas+arrival success, preserve the six-subject Filter/ExactFallback oracle, then compile/package only.

## 2026-09-14 — `M4-CP-SCALE-CB2`: independent S2 vertex-star oracle authored; candidate package compile GREEN

## 2026-09-14 — `M4-CP-SCALE-TB2-REV`: S2 candidate rejected; known non-flat helper precondition

- Runtime-free Review independently re-opened TB2 evidence and candidate source, and rejects `10367451675` / `63cb20d6...c939e` as **TEST-AUTHORITY PRECONDITION FAILURE / NON-STABLE**. The S2 identity reused the already-known non-flat `make_zero_transport_field` witness: on the three-right-angle center, exact cycle lift is `1` while hand-authored transport composes to `0 mod 4`, so `FieldTransportAtlas` correctly returns `CycleTransportMismatch` before the comparator.
- All six S2 subjects inherit the invalid atlas precondition; no product defect or Filter/ExactFallback equivalence is established. Accepted authority remains package `10360085644` / selector423 **423/423**; stable accounting stays **49 / 14 / 35**, debt **5**.
- Opened `M4-CP-SCALE-TB2-REV-OBS-01`: future fail-fast artifact harnesses must pre-initialize/preserve the full selector remainder. Exact next is `M4-CP-SCALE-CB3`, test-authority repair only; no production semantic change, selector append or historical ordinal374 side repair.

## 2026-09-14 — `M4-CP-SCALE-TB2-EXEC`: focused S2 semantic RED; Review required

Candidate `10367451675` / source `63cb20d6ba5393058086c62c6422ac58b75c939e` passed exact preflight, then focused `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle` selected exactly once and RED at first `positive-strict-interior` because `FieldTransportAtlas::make` returned false before comparator/receipt execution. Run/job `34898232410 / 104157635232`; result/log `10370015436 / 10369796116`; nested evidence `06e4db5b...18cb61`, manifest 12/12. Harness stopped before selector423/postflight and omitted explicit unexecuted remainder; no retry before Review. Candidate remains unpromoted; accepted package `10360085644` / selector423 423/423 remains authority; stable 49/14/35, debt 5. Exact next: `M4-CP-SCALE-TB2-REV`.

CB2 is **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME UNADJUDICATED** at semantic source `63cb20d6ba5393058086c62c6422ac58b75c939e`. Only `tests/FieldAlignedCurveNetworkTests.cpp` changed semantically: `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle` derives expected vertex-star ownership from exact integer ray seeds on a deliberately right-angle cone and covers positive, negative, near-boundary-certified, exact-boundary/`ExactFallback`, and discriminating-tamper subjects without calling/mirroring the production comparator. Product/API/CMake/fixture/selector semantics are unchanged.

Changed-owner preflight run/job `34892475284 / 104138340270` is GREEN; result/log artifacts `10367556999 / 10367562018`. Authoritative eight-target GMP/GMPXX run/job `34892831641 / 104139501513` is GREEN with `runtimeExecution=false`; candidate artifact `10367451675` has SHA-256 `9a1b59bcbf6cbe14e1df180b0feaaeec6bf9e675d010f66303bc39cf4c83ddec`, log artifact `10367267260` has `53ae0aadaca8e9893f05c243b448f8b8aaf603ff9b41c0338999b13412e7dcc9`, root manifest verifies **28/28** at `b229f38237f3e3f00dfd70f5f4f28f8faae0af9a888609c2c397b6fb8af1e47b`, and packaged source archive is `de4667b5677ba3b60ae1737299ae3edb111cefa453e6ac4cc3f7357fe3607f27`. Selector423 remains **423 LF rows** / `4e67e4dc...d89343` with first422 `bbd496f3...f7cc`; no generated Directional runtime/test/benchmark/discovery executed. Accepted runtime authority remains package `10360085644`; stable accounting stays **49 / 14 / 35**, debt **5**. Exact next is immutable `M4-CP-SCALE-TB2-EXEC` on candidate artifact `10367451675`, followed by mandatory Review.

## 2026-09-14 — M4-CP-SCALE-TB1-REV promotes package10360085644; S1 remains threshold-free

Runtime-free Review independently re-opened TB1 primary evidence, re-downloaded published artifact `10363765929`, verified the byte-identical evidence archive and all **869** manifest entries, re-hashed selector423 to **423 rows / `4e67e4dc...d89343`** with exact first422 `bbd496f3...f7cc`, and re-derived the **30/277/75/41** owner/process census from all 423 raw logs. Focused S1 remains **1/1 PASS** and decision-neutral; observed maxima are preserved but do not justify a numeric safety bound. Package `10360085644` / semantic source `a359b981f9350139304bc5a654041dfba78609b6` is promoted as accepted current M4 runtime authority with unchanged selector423. Stable accounting remains **49 / 14 / 35**, debt **5**. `M4-CP-SCALE-TB1-REV-OBS-01` records the open S1 calibration precondition; `4096` remains an operational guard, not calibration. Exact next is bounded runtime-free `M4-CP-SCALE-CB2`, authoring only the S2 vertex-star certified-filter/independent-exact-oracle equivalence identity and compile/package evidence; no selector append or runtime is authorized.

## 2026-09-14 — M4-CP-SCALE-TB1-EXEC mechanically green; S1 evidence preserved; Review mandatory

Artifact-only TB1 execution consumed immutable CB1 candidate `10360085644` / source `a359b981f9350139304bc5a654041dfba78609b6` without configure/build/relink/repair/discovery/mutation/benchmark. Focused `M4CPScaleS1.ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral` is **1/1 PASS** and accepted selector423 is **423/423 PASS** with owners **30/277/75/41**, zero RED/SKIP/timeout/crash/selection mismatch, and exact package/source/execution-view postflight equality. Raw S1 `(sampleCount / numeratorBitsMax / denominatorBitsMax / magnitudeBitsMax)` is two-ring `9/105/107/107`, torus `0/0/0/0`, mechanical feature `60/1/1/1`, prescribed sphere `186/429/429/429`; no threshold or gate credit is inferred. Evidence archive SHA-256 is `712bf4983695a58d1d0859e041895209c9935eb7e8f4bdc2835c01737173e3da`; publication run/job `34883153457 / 104107197329` independently verified and published result artifact `10363765929` and log `10364255019` with `runtimeExecution=false`. No new regression/candidate is observed. Accepted runtime authority remains package `10331193451` / selector423 **423/423**, stable accounting **49 / 14 / 35**, debt **5**. Exact next is runtime-free `M4-CP-SCALE-TB1-REV`.

## 2026-09-13 — M4-CP-COND-TB4-REV

Accepted immutable CB4 package `10327643907` / cumulative selector422 **422/422** as current M4 runtime authority after independent TB4 evidence review. Closed the TB3 selector-publication candidate and evidence-manifest self-hash observation. CP-COND remains OPEN: frozen conjunct 4 still needs a pre-production independent raw boundary-truncated separatrix oracle and conditioner-preservation gate. Exact next is test-authority/runtime-free `M4-CP-COND-CB5`, targeting selector423. Stable accounting remains **49 / 14 / 35**, debt **5**.

# 2026-09-13 — M4-CP-COND-TB3-REV accepts repaired oracle; cumulative selector gap blocks CP-COND closure

Runtime-free Review independently re-opened CB3 artifact `10325879420`, TB3 raw ledgers/logs and packaged `tests/InputConditionerTests.cpp`. TB3 mechanics are accepted at focused **14/14 PASS**, one expected report-only boundary **SKIP**, selector408 **408/408 PASS**, gating **422/422 PASS**, zero semantic RED/crash/timeout/actual selection mismatch and exact immutable postflight. The corrected negative-index identity is non-vacuous: its test-local GMP oracle exactifies actual raw binary64 geometry/field bytes, derives the unique closed planar fan and exact Z4 transport `[3,3,3,3,3]`, obtains signed numerator `-1`, and a one-LSB raw branch mutation invalidates the oracle. `M4-CP-COND-TB2-REV-CAND-01` therefore closes **TEST-AUTHORITY REPAIRED / RUNTIME-PROVED / NON-STABLE**.

CP-COND does **not** close. Frozen CP-COND §12 and M4 selector policy require gate credit on a cumulative append-only selector, while the fourteen CP-COND identities remain outside unchanged selector408 and were executed only as a focused surface. `M4-CP-COND-TB3-REV-CAND-01` opens **SELECTOR-AUTHORITY / NON-STABLE**. Exact next is runtime-free `M4-CP-COND-CB4`: publish selector422 = byte-identical selector408 prefix + the fourteen existing CP-COND gates, keep the boundary witness report-only, change no product/test semantics, compile/package the complete owner set, then artifact-only TB4 + mandatory Review. A non-blocking orchestration observation also records the TB3 evidence manifest's self-hash entry; TB4 must emit a non-self-referential checksum manifest. Accepted authority remains CP3 package `10307919492` / selector408 408/408; stable accounting remains **49 / 14 / 35**, debt **5**.

# 2026-09-13 — M4-CP-COND-TB3-EXEC immutable 423-process surface mechanically green; Review mandatory

TB3-EXEC is **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED** on immutable CB3 artifact `10325879420` / source `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675`. The authoritative full attempt executed **423** fresh exact-filter processes: focused CP-COND **14/14 PASS**, `BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` **SKIP** with its report-only/non-selector blocker unchanged, and accepted selector408 **408/408 PASS**. Gating total is **422/422 PASS**, zero RED/crash/timeout/selection mismatch; process-ledger SHA-256 `bbe96d77a18844f9c050924f4964b8cb052f40f6f1ec75d980ae9c945ae3a034`. Package/source/execution-view byte+mode censuses are identical before/after and no build/configure/relink/repair/generated discovery/benchmark/mutation occurred. Two preliminary local harness/orchestration attempts receive zero semantic credit; the authoritative attempt restarted the full 423-process surface from process 1. A final post-runtime harness checker then false-counted two TSV headers as selection mismatches; non-runtime revalidation proves all 423 rows selected exactly one test and preserves the completed exact postflight. EXEC does not promote the package or close the TB2 Review candidate. Accepted runtime authority remains CP3 artifact `10307919492` / selector408 **408/408**; accounting remains **49 / 14 / 35**, debt **5**. Exact next is mandatory `M4-CP-COND-TB3-REV`.

# 2026-09-13 — M4-CP-COND-CB3 negative-index raw oracle corrected; full-owner compile GREEN

CB3 is **COMPLETE / TEST-AUTHORITY CORRECTED / COMPILE GREEN / RUNTIME UNADJUDICATED**. Only `tests/InputConditionerTests.cpp` changes semantically: the negative-index identity now decodes actual raw binary64 mesh/field bytes into exact GMP arithmetic, derives the source-face cycle and unique exact Z4 transport, proves raw branch admissibility, derives numerator `-1` from the raw transport itself, and uses a one-LSB raw mutation that invalidates the independent oracle. Product/API/CMake/selector/A3/A4 semantics are unchanged. Compile run/job `34785549072 / 103800273458` on source `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675` is GREEN for all seven required targets with GMP/GMPXX and `runtimeExecution=false`; artifact `10325879420` has provider digest `sha256:d046b8cbdcfe22af5ca732139612e96673d597fef47b5e36d1a54b1542493b2b` and root manifest 27/27. No Directional runtime/test/benchmark executed. Accepted runtime authority remains CP3 package `10307919492` / selector408 **408/408**; stable accounting remains **49 / 14 / 35**, debt **5**. Exact next is immutable artifact-only `M4-CP-COND-TB3-EXEC` over 14 focused + one report-only boundary + selector408, followed by mandatory Review.

# 2026-09-13 — M4-CP-COND-TB2-EXEC artifact-only frozen surface mechanically green; Review mandatory

TB2-EXEC is **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED** on immutable CB2 artifact `10321878900` / source `b576d061e23873b7b4193b158138d2097c75a728`. Authoritative run/job `34772781761 / 103765305047` completed **423** fresh exact-filter processes: 14 focused CP-COND gates **14/14 PASS**, boundary-truncated separatrix **SKIP as explicit report-only/non-selector evidence**, and accepted selector408 **408/408 PASS**. Gating total is **422/422 PASS** with zero RED/crash/selection mismatch. Result/log artifacts are `10322612282 / 10322677035`, SHA-256 `46bcc703d5aa11dc43edaec9e416f22c75d68111802a9d8dbfc4129a9775a5a0` / `725a59a93d91bd267c6531f6d7bd545d17f2867ebbc85f906d4011d3abfdadc5`. Package/source/execution-view/selector postflight equality is exact and all rebuild/repair/discovery/mutation/benchmark flags are false. EXEC leaves `M4-CP-COND-TB1-EXEC-CAND-01` open pending mandatory runtime-free `M4-CP-COND-TB2-REV`; stable accounting is carried unchanged at **49 / 14 / 35**, debt **5**.

# 2026-09-13 — M4-CP-COND-DEFN definitions frozen

- Completed runtime-free `M4-CP-COND-DEFN`; CP-COND remains OPEN and exact next is compile-only `M4-CP-COND-CB1`.
- Froze one pre-A0 `ConditionedSourceProduct` single writer, exact/certified raw→conditioned correspondence, exact dyadic policy/operation authority, typed refusal, independent certificate validator, idempotence and non-vacuous witness preconditions.
- Reconciled Amendment 20 with older A0 sanitization wording: CP-COND is the sole value-changing boundary; A0/A1 consume immutable conditioned authority. Legacy `BoundedMeshPreconditioner` and tolerant raw-field finalization are not CP-COND semantic authority.
- Initial CB contract keeps one-to-one face correspondence and uses exact sliver refusal rather than topology-changing repair; prospective gates require independently established raw preconditions.
- Accepted CP3 package `10307919492` / selector408 **408/408**, stable accounting **49 / 14 / 35**, and produced-witness debt **5** are unchanged. No runtime, product/test/fixture/selector/build mutation occurred.

## 2026-09-13 — `M4-CP3-TB8-EXEC`: artifact-only candidate runtime mechanically green 835/835; Review mandatory

## 2026-09-13 — `M4-CP3-TB8-REV`: package/selector408 accepted; CP3 closes; CP-COND next

Runtime-free Review independently re-opened CB10 package `10307919492` / source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`, TB8 result/log artifacts `10309365777 / 10309009858`, selector403/408 bytes and the raw **835-row** process ledger. Package manifest is 28/28, selector403 re-hashes to `c3f509af...70cb7`, selector408 to `c689c0cd...484` with exact first403 prefix, and the ledger is **835/835 PASS**: repaired shared-fixture A/B 12/12, ordinal138 A/B 2/2, row408 A/B 2/2, rows404-407 A/B 8/8, selector403 403/403 complete census, selector408 408/408 cumulative, empty accepted RED census and exact package/source/execution-view immutability.

**Decision: APPROVED.** Package `10307919492` and selector408 become accepted current M4 authority; `M4-CP3-TB7-REV-CAND-01` closes recovery-proved with its historical stable event retained. The frozen CP3 exit is satisfied: A4 consumes exact accepted A3 shared intervals, fixed-plan target perturbation preserves them, missing/tampered identity fails closed without floating fallback, A4-local family/sign survives, and the constructed production torus completes without `InvalidHardRailPairing`. **M4-CP3 closes.** The main `G4-B002` exact-pairing blocker closes, but its three produced-witness debts remain M4-CP4 gating; total debt stays 5. Stable accounting remains **49 / 14 / 35**. Exact next is runtime-free `M4-CP-COND-DEFN`; no runtime or product/test/fixture/selector/build mutation occurred in Review.


TB8-EXEC is **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED** on immutable CB10 package artifact `10307919492`, source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`, selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`, and selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`. Authoritative run/job `34729562893 / 103649745950` executed all **835/835** prescribed fresh processes PASS with zero RED, skip, crash, or selection mismatch: shared-fixture A/B 12/12, ordinal138 A/B 2/2, row408 A/B 2/2, rows404-407 A/B 8/8, selector403 **403/403** to completion with semantic fail-fast disabled, and cumulative selector408 **408/408**. Result/log artifacts are `10309365777 / 10309009858`; result ZIP SHA-256 is `a8d91cd62cb2c633ed46ab963a13060e903a5043d3941fdea6aaec9c77091c04`, and process-ledger SHA-256 is `2700e511a12505dbaf87b87d00bed7f2d2b73e65dd38adb1934682cb72abf63d`. Package/source/execution-view byte+mode censuses are identical pre/post, and no configure/compile/relink/repair/discovery/benchmark/mutation occurred. Three preliminary orchestration runs failed before runtime and carry no test credit. EXEC does not promote or classify; corrected R4 artifact `10289601000` remains accepted runtime authority, stable accounting remains **49 / 14 / 35**, debt **5**, and exact next is mandatory `M4-CP3-TB8-REV`.

## 2026-09-12 — `M4-CP3-CB9`: bounded-disc applicability correction compile-green; TB7 frozen

CB9 is **COMPLETE / COMPILE-GREEN / RUNTIME UNADJUDICATED**. G1-G3 were proved before mutation. Semantic source `47ae78e1e46e7d2dcc230fc617291ca45f2e418e` removes only the premature accepted-cut `acceptedSegments.size()<4` rejection from the curved bounded-disk producer, preserving all typed invalid-authority checks and the row408 `>=4` occurrence-domain path. Changed-owner run `34720050597` and frozen package run `34720182350` are GREEN with GMP/GMPXX and `runtimeExecution=false`; artifact `10305678151` / `543fd253bf04bde38f16aac8c33a05447bf515f37027a077f6014ff13957a629` verifies 28/28. No Directional runtime executed. Accepted runtime authority remains corrected R4 selector403 403/403; stable totals remain **48 / 14 / 34**, debt **5**. Exact next is artifact-only `M4-CP3-TB7-EXEC`.

## 2026-09-12 — `M4-CP3-TB2-R2-REV`: corrected R4 package/selector403 accepted; A3→A4 cutover authorized

Runtime-free Review independently reopened corrected R4 artifact `10289601000` (source `58521f6d1c4fb5d625da7cde50e002cf4688beee`) and TB2-R2 result/log artifacts `10289088800 / 10289438082`. Package identity, 28-entry manifest/path closure, source archive/GMP/owner-binary provenance, selector lineage, all **799** ledger rows and raw logs, focused A/B determinism, owner partitions and immutable pre/post censuses were independently re-derived. Replacement row400 is non-vacuous on raw face `[3,0,4]` versus canonical `[0,3,4]`: canonical weights `[1/6,1/3,1/2]` yield exact `1/3` after the production vertex-identity remap and `2/3` under the historical positional defect, so removing the remap makes the regression fail.

**Decision: APPROVED.** Corrected R4 artifact `10289601000` and selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` become accepted M4-CP3 pre-cutover runtime authority at **403/403**; predecessor selector394 stays byte-identical and **394/394** green. `M4-CP3-CB4-R2-REV-CAND-01`, `M4-CP3-TB2-REV-CAND-01`, and `M4-CP3-CB4-R3-REV-CAND-01` close recovery-proved/non-stable. Stable totals remain **47 / 14 / 33**, debt **5**. CP3 remains open. Exact next is guard-first `M4-CP3-CB5`: prove exact A3 span+ordinal ownership of every shared A4 hard-rail segment before mutation, then if proven wire immutable A3 breakpoints into A4 and retire floating `support_key` shared-boundary authority. No Directional runtime or code/test/selector/build-source mutation occurred in Review.

## 2026-09-07 — `M3-CP4c-3-TB38-EXEC`: package103 artifact-only runtime 395/14; accepted/protected regressions and missing R6.7 emission require independent review

TB38-EXEC is **COMPLETE / MECHANICALLY VALID / SEMANTICALLY UNADJUDICATED** on immutable CB43 package103,
source `2fcde465b1de2e42a348d224f5165ce8b87e4fbe`. Run/job `34169783183 / 101887783834` executed all 409 selector
identities exactly once with zero selection mismatch/timeout and no build, repair, mutation or benchmark. Raw result
is **395 PASS / 14 RED**, accepted **362/365**, RED `[356,357,362,366,367,368,369,370,374,390,393,398,406,407]`.
Compared with TB37, accepted 356/357/362 and protected 390/393/406/407 newly RED; 312/404/408/409 remain PASS.
366 moves to `RegionInteriorDisconnected`; 367 publishes a different torus Euler failure with `chiFull=0`;
368/369/370/374/398 remain byte-identical. No accepted-region `record=euler_certificate` line was emitted, so the
frozen R6.7 equivalence proof is undischarged. Result/log artifacts are `10035390901 / 10035391184`. Stable totals
remain **45 / 14 / 31**, debt **5**, packages **103** pending independent `M3-CP4c-3-TB38-REV`; EXEC does not
assign corrective ownership or promote TB38 semantic authority.

## 2026-09-07 — `M3-CP4c-3-DEFN-R5`: Part IX freezes derived boundary provenance; Euler measurement only

DEFN-R5 is **COMPLETE / DEFINITION-ONLY / NO RUNTIME / NO COMPILE / NON-STABLE**. Part IX of
`M3_CP4c_Frozen_Definitions.md` is now operative. It records the source-proved face-walk guarantee and makes
provenance a derived exact relation: a boundary is `FaceWalkOrbit(orbit)` only when exactly one current
`walk.orbits[orbit]` equals the current ordered `region.boundary`; otherwise it is `Unguaranteed`. A mutable copied
region flag is expressly not authority. `ClosedBeforeEnd` rejects only `Unguaranteed`; on a face-walk orbit it is
non-rejecting observation while `ArcChainBroken` and `WalkNotClosed` remain universal. Optional provenance is
resolved before the boundary check, but missing-orbit rejection remains after it so ordinals 312/409 keep their
unchanged synthetic negative contracts.

The separate `RegionEulerCharacteristicNotOne` frontier is **not corrected**. Current source reduces χ to
`V_int - E_int + F` by cancelling boundary terms; Part IX freezes exact arc/node multiplicity and provenance
measurement to decide whether that reduction is valid for repeated-node face-walk boundaries.
`M3-CP4c3-TB35-REV-CAND-01` is **DEFINED / CORRECTION FROZEN**; `M3-CP4c3-TB34-REV-CAND-03` remains split with
Euler open. Runtime authority remains TB35 at **402 PASS / 7 RED**, accepted **365/365**, selector409; stable
accounting **45 / 14 / 31**, debt 5, packages100. Exact next is runtime-free `M3-CP4c-3-CB41` under CX0–CX8,
followed by immutable artifact-only TB36-EXEC and independent TB36-REV.

## 2026-09-06 — `M3-CP4c-3-TB31-EXEC`: artifact-only selector408 mechanically 397/11; four newly RED; review required

TB31-EXEC is **COMPLETE / MECHANICALLY VALID / SEMANTICALLY UNADJUDICATED** on immutable CB36 artifact
`9982174864` / source `90bf8430f54c8b81fb90a6bda820cf8edebce6e9` / selector 408. Authoritative R2 run/job
`34011402843 / 101427791582` executed all 408 identities once in fresh processes/execution views, every row selected
one test, zero timeouts, accepted **365/365**, and raw aggregate **397 PASS / 11 RED** with
`[366,367,368,369,370,374,390,393,398,406,407]`. Result/log artifacts are `9982618043 / 9982618174`; package,
source and execution-view byte+mode censuses are unchanged, with no configure/compile/relink/repair/discovery/
benchmark/mutation.

The old 366/367 191-face Multiple `[0,1,3]` fingerprint no longer appears; both terminate at
`TraceArcDoesNotSeparateItsSides`, with retained fragment-owner component 0 at 189 faces / Unique / orbit `[0]`.
No `TraceCutFaceFragmentCountMismatch` occurs. Raw owner publication remains 300/0/0. Newly-RED 390/393/406/407
expected `UncutFaceComponentOrbitSeedNotUnique` but received the new detail. EXEC does not classify these changes;
semantic authority remains TB30 at **401/7** until evidence-only **`M3-CP4c-3-TB31-REV`** updates the regression
tracker and ORIENTATION, performs mandatory document consolidation, and freezes the justified successor.

## 2026-09-05 — `M3-CP4c-3-TB30-EXEC`: selector408 artifact-only runtime mechanically 401/7; review required

TB30-EXEC is **COMPLETE / MECHANICALLY VALID / SEMANTICALLY UNADJUDICATED** on immutable CB35 artifact
`9980764888` / source `ab86747bdfdb94c7c383bf5d2893ced4207eb555` / selector 408. Run/job
`34008104497 / 101418934144` executed all 408 identities one per fresh process/workdir with every row `selected=1`,
no timeout, accepted rows 1–365 mechanically 365/365 PASS, and raw aggregate **401 PASS / 7 RED** with
`[366,367,368,369,370,374,398]`. Corrected witnesses 390/404 mechanically PASS; credibility controls 366/367/398
remain RED. Result/log artifacts are `9981641004` (`40f58d136073e08392701eafd189a4f6b45e1907a4381393ab3d4673cc6b2913`)
/ `9981641260` (`dde276e2b448f9ba58b36dbe554bed7b7f4fa6ab2bff90df5ac15ee5af8cbd6d`). Package/source/execution-view
byte+mode censuses are identical pre/post; no configure/compile/relink/repair/discovery/benchmark/mutation occurred.

This is raw EXEC evidence only. Semantic authority remains TB29 at 399 PASS / 9 RED until **`M3-CP4c-3-TB30-REV`**
consumes the immutable artifacts, adjudicates the two changed witnesses and credibility controls, classifies every
semantic RED/change in the regression tracker, and reads the retained census. No corrective CB is authorized before
that review.

## 2026-09-05 — `M3-CP4c-3-CB35`: test-authority witnesses restored; CO7 census transcribed; package 95 compile-green

CB35 is **COMPLETE / BUILD + PACKAGE GREEN / TEST-AUTHORITY ONLY / RUNTIME-FREE**. It changes only
`tests/FieldAlignedCurveNetworkTests.cpp`: ordinal 404 removes the out-of-contract assertion that every owner must
remain non-`Established`; ordinal 390 stops matching the plan and certifier partitions by numeric component index
and instead uses face-set digest / the published subset relation, comparing cross-partition counts only on exact
semantic correspondence. Ordinals, names, gating membership, selector 408 bytes, accepted identities 1–365,
ordinal 398, 366 and 367 are unchanged; there is **no product change**.

CO7 transcribed the existing immutable TB29 log (`9980019636`) rather than measuring anything new: failing plan
component `0 / EmptyFragmentOrbits / 191 faces / digest 17919102493633069558 / seeds [0,1,3]`; comparison census
`0 / NotTraceCut / 212 faces / digest 835099723348023536`, with neither exact match nor subset relation; only
equal-orbit arcs 20 and 24 remain interior; certified owner publication is **300 established / 0 unavailable /
0 conflicting**. The CB35 report retains the exact first failing assertion text for every TB29 RED ordinal.

Semantic test-authority commit is `7bcf578984a1c650df58abbccb73ed8e1ed0a395`; the semantically equivalent clean
built source is `ab86747bdfdb94c7c383bf5d2893ced4207eb555`. Authoritative GMP/GMPXX compile run `34005311571`
succeeded with `runtimeExecution=false`, clean source, root `SHA256SUMS` **28/28**, and all eight required targets,
producing immutable package **95** artifact `9980764888` (`m3-cp4c3-cb35-result-34005311571`, provider ZIP SHA-256
`ebae13c53b7430a256865465cff640b460b45299cd5c17db0ce3582d38cb58e0`) and packaged source archive SHA-256
`64801a38ccbe9de282dbec261cad6c2b6575403ed38e93b514c893c22f03684a`. Stable accounting remains
**44 / 14 / 30**, debt **5**. Current semantic runtime authority remains TB29 at **399 PASS / 9 RED**, accepted
365/365. Exact next: artifact-only **`M3-CP4c-3-TB30-EXEC`** on package `9980764888` / selector 408, requiring
390/404 PASS and credibility controls 366/367/398 RED, then stopping at evidence-only `TB30-REV`.

## 2026-09-05 — `M3-CP4c-3-TB28`: artifact-only selector407 green; CL6/CL7 partition mismatch measured; review required

TB28 R2 is **COMPLETE / VALID ARTIFACT-ONLY RUNTIME / 407-of-407 SELECTOR GREEN / SEMANTICALLY UNACCEPTED PENDING REVIEW** on immutable CB32 artifact `9975737868` / source `098ac7d93ea203222dd0ac50cdb68667744f0fd4` / selector407 (`9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`). Run `33990951740`, execution/verification jobs `101373825038 / 101374345712`, produced result/log artifacts `9976662518` (`970573beb31bc43bb2cbcd4dee957edfb2f23c0c543edfe9997c5dcfc487053d`) / `9976662690` (`4272bd5fc1750d19c9fceb94daf3be8367b05d6fa9e13828fc6a97c1c6fe44d`). All 407 identities passed; all mutation flags remained false and package/binary/selector postflight was unchanged. R1 `33990315861` is pre-runtime orchestration-invalid only and carries no semantic evidence.

CL6/CL7 now measures candidate-set subset=true/equality=false with 101/101 untruncated failing-plan interior-arc rows. The decisive row is `arc=(0,2):sourceFace=0:certifierComponent=0:planComponent=1:notTraceCutReason=TerminalSlit`. This closes the missing evidence surface but does not authorize a product correction. Stable accounting remains **44 / 14 / 30**, debt **5**. Exact next: `M3-CP4c-3-TB28-INDEPENDENT-REVIEW`; CL8 forbids another standalone ownership diagnostic and requires that review to freeze the correction.

## 2026-09-03 — `M3-CP4c-3-TB22`: selector 393 closes at 387/6; projection residual zero; ordinal 391 dependency cleared

TB22 is **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / ARTIFACT IMMUTABLE** on source `d69729a69a40b020968ed6ef1fbc1bc788284518`, immutable package artifact `9919225745` (`sha256:7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`), and selector 393 (`ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`). Run/job `33826248118 / 100879465830` completed all 393 identities one-per-fresh-process at **387 PASS / 6 RED**, accepted **365/365**, reds `366,367,368,369,370,374`; result/log artifacts are `9920122224 / 9920122598`, ledger SHA-256 `4998ca25b1477c2a32299bc3eb3d552e3ea9b0e2ccbf0eb4894393964f29dbbe`, and package pre/post byte+mode census is identical at `7e0c552c79281f97b7553406acd44383ff867197f36da54cd306ac9258fa2b74`.

Ordinal 366 remains `UncutFaceComponentOrbitSeedNotUnique`, component 0, 191 faces, exact seed orbits `[0,1,3]`, while the actual graph remains certified cellular (`V=22,E=26,F=6,componentCount=1,sourceChi=2,residual=0`). CB24's new evidence measures `projectionFaithfulnessResidual=0`, zero witnesses, untruncated. The two minority rows are source edge `10-79` → seed 3 by `edgeOrbitEvidence`, certificate faces `3/3`, and `29-35` → seed 1 by `edgeOrbitEvidence`, certificate faces `1/1`. This narrows `M3-CP4c3-TB21-CAND-01` toward review of the seed/ownership rule without authorizing a correction. Ordinal 391 PASSes with its prescribed-sphere half explicitly skipped because ordinal 368 remains open, closing `M3-CP4c3-TB21-CAND-02` as runtime-proved/non-stable; 392/393 and 371/372 PASS. Stable accounting remains **44 / 14 / 30**, debt **5**, packages **87**. No configure/compile/relink/repair/mutation/benchmark occurred. Exact next: independent static `M3-CP4c-3-TB22-REV` under BZ0–BZ8.

An early cleanup-manifest trigger failed closed before removal because temporary workflows were still present; repository-removal and PR-comment deletion steps were skipped. It did not alter semantic/runtime evidence. Final cleanup follows workflow-first retirement after durable TB22 closeout.

## 2026-09-03 — `M3-CP4c-3-CB23`: Euler cellularity evidence and 371/372 test decoupling build green

CB23 is **COMPLETE / BUILD + PACKAGE GREEN / DIAGNOSTIC-ONLY PRODUCT EVIDENCE + TEST-ONLY DECOUPLING / RUNTIME-FREE** at semantic source `fa5646106ccaa23770b84a935c6d1d6007928640`. Production failures now retain the embedded graph's `V/E/F`, connected-component count, source `χ(S)`, `V−E+F−χ` residual, and bounded per-orbit boundary-edge attribution; the evidence projects through the mechanical failure and is carried to torus/prescribed-sphere paths. Existing ordinals 371/372 switch only to an additive atlas-scoped fixture accessor; their assertions, ordinals and selector membership are unchanged. New selector **391** has 391 identities, SHA-256 `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`, extending frozen 388-identity selector 385 and accepted 365 exactly. Authoritative GMP/GMPXX compile/package run `33815475590`, jobs `100846561708 / 100847694307`, is GREEN; immutable package artifact `9916511617` has digest `sha256:8378a108811740cff5fd1a0fc9db66f9e3334d7048ea9e7c7d6e8e1cbd852050`, log `9916511915`, `manifest_self_verification=pass`, clean source, `runtimeExecution=false`. No product semantic guard, cut/barrier partition, face walk, rotation system, CB21 comparison or `proves_cellularity()` behavior changed. Accepted runtime authority stays **365/365**, stable accounting **44 / 14 / 30**, debt **5**, semantic packages **86**. Exact next: artifact-only `M3-CP4c-3-TB21` on package `9916511617` / selector 391.

## 2026-09-03 — `M3-CP4c-3-CB20`: diagnostic-only fragment mismatch evidence compiled

CB20 semantic source `57635e87306a416daabb8321e1f36fa9c788d208` implements TB17-REV BS0–BS9 without changing topology semantics. `TraceCutFaceFragmentCountMismatch` now retains actual/expected/`tracePieceCount`, bounded real-chord incidence with both orbit ids and exterior-drop flags, bounded three-edge orbit evidence, and failing-face `fragment_reconciliation`; the production failure projection carries the same typed evidence. Selector 382 stays byte-identical; selector 383 appends only `GlobalTopologyPlan.TraceCutFaceFragmentMismatchDiagnosticsSurviveProductionFailureProjection` (`a7fe57cc…3a4b2c`). Authoritative eight-target GMP/GMPXX compile `33780005014 / 100731152066` is GREEN; result/log artifacts `9903305256 / 9903306009`; `runtimeExecution=false`. Exact next is artifact-only `M3-CP4c-3-TB18`; no semantic correction is authorized before TB18 and independent TB18-REV.

## 2026-09-03 — `M3-CP4c-3-TB17`: CB19 branch clears; next region frontier is face-fragment orbit/count mismatch

TB17 is **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / NON-STABLE** on immutable package **87** / semantic source `bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e` / selector **382**. Run/job `33770523736 / 100699356052` completed all 382 exact selector identities one per fresh process plus the retained non-gating mechanical diagnostic: **374 PASS / 8 RED**, accepted **365/365**, reds 366/367/368/369/370/371/372/374. Result/log artifacts are `9899516228` (`c03480f525e6125367c360c851ba374c59dc32180044efd49e40938368509f0f`) / `9899516703` (`f4933482c6b5ec943edf258356157dabd2a5d69de8dfd64a6c893c89344a9bda`); exact ledger SHA-256 is `7c4464134a7be19150094bbee874ebe99878c3eaa004908d3660c1ffaa36b6fd`.

Ordinal 366 clears TB16's `RegionTraceSourcePortCarrierNotAdmissible` at `(9,11,17)` and now first-reds downstream at `TraceCutFaceFragmentCountMismatch`, source face `(0,1,102)`, `cutCandidateCount=0`; 367/371/372 reach the same stop. CB19's independent trace contract is runtime-visible: 48 non-first carrier-less segments, all 48 with segment-entry support distinct from trace origin, 10 terminal slits, a positive `SegmentEntrySupport` witness at `9-11-17`, and a terminal witness with `realChordContribution=0`. The new fragment-count error, however, retains only `sourceFace` and omits actual/expected counts and contributing segment/orbit incidence, so `M3-CP4c3-TB17-CAND-01` remains owner-unadjudicated pending review. 368/369/370/374 reproduce their pre-classified surfaces unchanged. Package pre/post byte+mode census is identical at `0438202b4717c69610374c640c2e7970ce38580b816935a8093e98253dbcd518`; all configure/compile/relink/repair/discovery/mutation/benchmark flags are false. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **84**. Exact next: `M3-CP4c-3-TB17-REV` under BRQ0–BRQ8; no runtime or CB before review.

## 2026-09-03 — `M3-CP4c-3-CB19`: region-loop contract correction build/package green; package 87 frozen

CB19 is **COMPLETE / BUILD + PACKAGE GREEN / PRODUCT CORRECTION / RUNTIME-FREE** at final semantic source `bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e`. The two region loops now share the same terminal-slit contract: the final no-barrier segment is hypothetical, contributes no real face chord, fragment count, touched edge or orbit evidence. Carrier-less segments bind through the current segment's exact entry support, with the trace-origin check retained only for segment 0; the fragment invariant is explicitly `k` real chords -> `k+1` fragments. Full trace-segment incidence now survives through typed error projection, and the independent fragment oracle plus compiled BR5/BR6 observations mirror the corrected contract. Selectors 380/381/382 are byte-frozen; selector 382 remains `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`; no 383 was created.

Authoritative eight-target GMP/GMPXX compile run/job `33761967427 / 100670323823` is GREEN; result/log artifacts are `9895999746` (`71b268f187b39ce547648c27543913e8fdef0bb1087eaaeca0d2948ce020c990`) / `9896000247` (`767a9802e82e696aa714e9ca483813df253835a6132d9ec34e3b4a0e89b2c707`). Immutable package **87** run/job `33763450567 / 100675268847` is GREEN: artifact `9896472535` (`78d1ac33c9db7592a8a852fafe91d0cabd0548ca5cf6309ceb50f689da9d9770`), inner tar SHA-256 `015c1113e2237e779076e397f4907b8a44f101ce159e566ff482f9c598f51c48`, packaged source archive `f54461f5cba89fdd8d54ad2a43d8476a1785676419535eaa21e1556e3e9b538a`, 27 fixtures and preserved executable modes. The first package attempt `33763246701` was orchestration-only invalid because it referenced accepted selector 365 under the CP4c-3 filename; the corrected retry reused the same immutable compile artifact. `selected_gate=NONE`, `gate_execution_authorized=false`, `runtimeExecution=false`, `packageRepair=false`; no Directional test, gate or benchmark ran. TB16/package 86 remains runtime authority at 374 PASS / 8 RED and accepted 365/365. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages advance to **84**. Exact next: artifact-only `M3-CP4c-3-TB17` on package 87 / selector 382 plus the retained non-gating mechanical diagnostic.

## 2026-09-03 — `M3-CP4c-3-TB16`: accepted prefix safe; v47 rotation re-proved; first red moves to region source-port carrier

TB16 is **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / V47 RE-PROVED** on immutable package **86** / source `a01016ca59314232526c8b1222c96235856ace6d` / selector **382**. Run/job `33709721203 / 100506452813` executed all 382 selector identities one-per-fresh-process plus the retained non-gating mechanical diagnostic. Result/log artifacts are `9876548209` (`573f8eacf7de1ac993cfd2a4ef440514e2acb3bd6d0a85f322ac280bfec0b89f`) / `9876548556` (`2d0cd2ab4ff4068293d0a2bb8449d0119fa03014a93cb561575d1da7a55cb75b`). A temporary exact-`[ OK ]` summary parser repeated TB14's reporting-only timing-suffix bug; immutable exit codes and terminal logs reconstruct the ledger to **374 PASS / 8 RED**, accepted **365/365**, corrected-ledger SHA-256 `7c4464134a7be19150094bbee874ebe99878c3eaa004908d3660c1ffaa36b6fd`, with no rerun.

Ordinal 366 clears `EdgeTraceSecondaryRankInvalid` at edge 25-31 and now reaches region construction: `RegionTraceSourcePortCarrierNotAdmissible`, source face `(9,11,17)`. Selectors 380/381/382 pass; complete mechanical attempt-0 rotation publication plus unchanged TB12 five-ray incidence and selector-382 collision-free ordering closes TB11-CAND-01, TB12-REV-CAND-01 and TB15-CAND-01. New `M3-CP4c3-TB16-CAND-01` owns the downstream region-building frontier; `M3-CP4c3-TB16-ORCH-01` records the resolved summary-parser recurrence. 368/369/370/371/372/374 retain prior independent ownership. Package pre/post census is identical at `606d193e3641ec68114c5616d41bd0e8e43207756f79ae50356ce973c1be10db`; no benchmark/build/repair/mutation occurred. Stable accounting remains **44 / 14 / 30**, debt **5**, packages **83**. Exact next: static `M3-CP4c-3-TB16-REV` under BQ0-BQ8.

## 2026-09-03 — `M3-CP4c-3-CB18`: segment-local edge-rank correction build/package green; package 86 frozen

CB18 is **COMPLETE / BUILD + PACKAGE GREEN / PRODUCT CORRECTION / RUNTIME-FREE** at semantic source `a01016ca59314232526c8b1222c96235856ace6d`. `edge_locus_secondary_rank` now binds a carrier-less ray to the current segment's far-end vertex support in the selected face (entry for Reverse, exit for Forward) and ranks that corner relative to `contactIndex`; genuinely unbindable support remains typed `SourceVertexFallbackUnbound`. Compiled BP5/BP6 witnesses pin accepted-shape ordering for contact indices 0/1/2, positive Reverse vertex entry, the typed negative, carrier/fallback interleaving and the ordinary two-carrier path. Selector 381 remains frozen; selector **382** appends exactly `GlobalTopologyPlan.EdgeLocusSecondaryRankUsesSegmentFarEndSupportAndContactRelativeOrdering`, SHA-256 `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`.

Eight-target GMP/GMPXX compile `33706268720 / 100495948544` is GREEN; result/log artifacts are `9875350611` (`cc2935716ecf7022fda6c120f0ef6313e60df553d34d7354b587e47ee9663d3a`) / `9875350974` (`ea39d44a9196e47934cb3ff626633c3031a2c607c542ef5e34298cc6665328f5`). Immutable package **86** is GREEN on `33707299159 / 100499114323`: artifact `9875664940` (`8c98b134a527db87b83852de175288a320a158405d22867d95ba986cf68cbef8`), log `9875665222` (`fe86b4f391d731eb629461e1d79cb3b9543f1bab968fa922c1f8a0deb9565d28`), inner tar `125d2851164d7af62f90a3ff6ad8f360076a651c8575b655acac59fb50b9e9e7`, packaged source `c96446f169959c56f3c536c7fe711df6f7741d679cbd1413cc7c464838a659e8`, 57/57 manifest, 27 fixtures and six preserved executable modes. A package-authoring retry corrected orchestration-only executable-mode loss by restoring direct artifact-ZIP extraction; no package repair or Directional runtime occurred. Accepted authority remains **365/365** pending runtime, stable accounting **44 / 14 / 30**, debt **5**, semantic packages **83**. Exact next: artifact-only `M3-CP4c-3-TB16` on package 86 / selector 382, including the accepted 365-prefix re-proof and v47 five-ray conjunction.

## 2026-09-03 — `M3-CP4c-3-CB17`: edge-rank branch observability build/package green; package 85 frozen

CB17 is **COMPLETE / BUILD + PACKAGE GREEN / DIAGNOSTIC-ONLY / RUNTIME-FREE** at final source `1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4`. It types every former `nullopt` exit of `edge_locus_secondary_rank`, retains the bounded incidence needed to discriminate the current edge-25-31 frontier, and projects a bounded edge-locus ray census through the production renderer. Rank formulas, fallback behavior, `sideRank`, `key.primary`, collision detection, `build_node_loci`, contact-node construction and all inherited semantic corrections remain unchanged. Selector 380 is byte-frozen; selector **381** appends `GlobalTopologyPlan.EdgeLocusSecondaryRankFailuresAreTypedAndProductionVisible`, SHA-256 `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`.

The first compile at diagnostic source `5dcaa8be0c9677454f8d5144987eb599f544c0b9` exposed only a missing opaque enum forward declaration in `SurfaceCutGraph.h`; the surgical declaration fix produced final source. Authoritative eight-target GMP/GMPXX compile `33697315308 / 100468915978` is GREEN, result/log artifacts `9872340053` (`3a814357edf9b1f2424f4047b6c84b1e37ed54dc1751ab6a1fa3b125af206274`) / `9872340412` (`fcda1a3fbd206e6b9ce159dea3516a18b405897d842528268a28ad0827023b39`). Immutable package **85** run/job `33697837275 / 100470530585` produced artifact `9872426500` (`6c0e960b3f689bae2d2ef7f79c32709f63d1fefa87ecefdf6351427ac91ea0e2`), inner tar `98f5940254beaa50ec200157a3cbe6ab0ec15d8a5117006679d42684968aad08`, packaged source `cb078005cef48d97401ddfb843a4276f92c53086b0827a915b01344dc665c4a9`; selectors 373-381, 27 fixtures, six executable modes and manifests verify. No Directional runtime or benchmark ran. Accepted authority stays **365/365**, accounting **44 / 14 / 30**, debt **5**, semantic packages advance **81 -> 82**. Exact next: artifact-only `M3-CP4c-3-TB15` on package 85 / selector 381; the v47 conjunction remains owed and no vertex-30 discriminator exists.

## 2026-09-02 — `M3-CP4c-3-TB14`: complete user-authorized orchestration recovery; valid semantic red at edge-locus secondary rank

The prior local-host interruption was recovered by explicit user authorization without changing package/source/test/fixture/selector bytes. Complete GitHub Actions replacement run/job **`33689875040 / 100445977571`** executed all 380 selector identities one-per-fresh-process on immutable package **84** / source `6808c090f2dd229a48550d758f459bfd156da4b6` / selector **380**, then the retained non-gating diagnostic. Result/log artifacts are `9869697113` (`a96d8ff82b467c0cfd89c1437fc0a146461ab18d4850e04515acc562070b975a`) / `9869697543` (`5e961520a3844d5b01ab77d4b85b5117c4124bfa03d4993812270e4563deb5f2`). A temporary exact-line `[ OK ]` parser mislabeled passing logs in generated summary fields; immutable process exit codes and terminal logs correct the ledger to **371 PASS / 9 RED**, SHA-256 `0b42866471ce0ad5939ab2d3c2d5c82f4efebb93c0a56ca7a60e295fad07397b`, without rerunning any semantic identity.

Accepted ordinals **1-365 remain 365/365 PASS**. First red stays ordinal **366** but clears TB13's vertex-10 `VertexTracePortOrdinalInvalid`; the new frontier is `RotationSystemInconsistent -> EdgeTraceSecondaryRankInvalid` at source edge **25-31**, face `(25,30,31)`, attempt 0 / zero cut edges / 450 candidates. Selector 379 PASSes; selector 380 REDs at its final production assertion on the same edge-rank failure. The old v47 collision remains absent but the full five-ray/distinct-rank production conjunction is still unpublished. 368/369/370/374 retain prior ownership; 371/372 inherit the new mechanical upstream red. Package pre/post 58-file byte/mode census is identical; no build/configure/relink/repair/discovery/mutation/benchmark occurred. `M3-CP4c3-TB14-CAND-01` is the new non-stable gating owner; orchestration records `TB14-ORCH-01/02` are resolved. Stable totals remain **44 / 14 / 30**, debt **5**, packages **81**. Exact next: independent `M3-CP4c-3-TB14-REV` BM0-BM8.

## 2026-09-02 — `M3-CP4c-3-TB14`: package 84 immutable; local selector execution orchestration-invalid

TB14 consumed immutable package **84** / source `6808c090f2dd229a48550d758f459bfd156da4b6` / selector **380** and passed full package/source/GMP/fixture/mode/selector preflight. Ordinals 1-129 completed organically PASS. Ordinal 130 reached GoogleTest `[ RUN ]` but the surrounding local execution call exceeded its wall-clock allowance before any organic test completion or exit status. A non-duplicating resume produced PASS at 131-136; ordinal 137 then suffered the same host interruption. Execution stopped rather than rerun a started identity or risk further partial processes. Completed ledger: **135 PASS / 0 semantic RED** for `1-129,131-136`; selector 366, selector 380 and the non-gating mechanical diagnostic were not reached.

This is **ORCHESTRATION INVALID / INCOMPLETE**, not a semantic red and not a green gate. Because ordinal 130 is inside the accepted prefix, TB14 does not re-prove 1-365; prior accepted authority remains **365/365 from TB13**. Package postflight is byte/mode-identical at census SHA-256 `95ba3950267a1e145be427b2e1c896204aef7d86bd079d039a63bc0834e8a3e2`. New infrastructure candidate `M3-CP4c3-TB14-ORCH-01` changes stable accounting by +0/+0. Exact next: independent `M3-CP4c-3-TB14-REV` BM0-BM7 to adjudicate exact-once/retry recovery; no additional runtime or product correction is authorized before review. Stable totals remain **44 / 14 / 30**, debt **5**, packages **81**.

## 2026-09-02 — `M3-CP4c-3-CB16`: exact vertex-exit recovery build/package green; package 84 frozen

CB16 is **COMPLETE / BUILD + PACKAGE GREEN / PRODUCT CORRECTION / RUNTIME-FREE** at final source `6808c090f2dd229a48550d758f459bfd156da4b6`. It appends the exact source-vertex corner fallback last in `vertex_trace_ray_second_point`'s Forward chain and splits the secondary-parameter failure from legacy `VertexTracePortOrdinalInvalid` into `VertexTraceSecondaryParameterUnavailable` with a typed subreason plus arc/trace/orientation/segment bounds. Selector 379 remains byte-frozen; selector **380** appends `GlobalTopologyPlan.VertexExitSecondaryParameterUsesExactCornerSupportAndTypedFailure`, SHA-256 `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`.

Authoritative eight-target GMP/GMPXX compile `33682499470 / 100422188581` is GREEN, result artifact `9866902345` (Actions digest `410f18cd45f0662d480592bc2bb567bb6ab02583cf0a0dd06629b5c57a0174f9`). Immutable package **84** is GREEN on `33683929335 / 100426817194`, artifact `9867334959` (Actions digest `67f1ea7012f3b0e06a1dd60e87d40c7e593e5260703cab425c9021cb0c2ebd55`), inner tar `8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff`, packaged source `ca898abdf3e5a4d01429048f13a2a6f09dd6bc70dabd3b866209533f9e43db95`; 27 fixtures, selector-prefix lineage, six executable modes and manifests verify. No Directional runtime or benchmark ran. Accepted authority remains **365/365**, stable accounting **44 / 14 / 30**, debt **5**, semantic packages **81**. Exact next: artifact-only `M3-CP4c-3-TB14` on package 84 / selector 380, including the full v47 five-ray/distinct-rank re-proof. No vertex-30 discriminator.

## 2026-09-02 — `M3-CP4c-3-TB13`: accepted prefix holds; first red moves to ambiguous vertex-10 trace rank failure

Artifact-only TB13 consumed immutable package **83** / source `a2fd98eaa015ff5872890bb1945cf4e9e9493615` / selector **379**. Run/job `33671968437 / 100387569925` executed 379 fresh selector processes for **371 PASS / 8 RED**: ordinals 1-365 remain **365/365**, first red remains 366, and the new `VertexLocusSecondaryRankUsesExactWithinWedgeGeometry` witness passes. Result/log artifacts are `9862995609` (`d7da71ea122a20225e6e3e7b9f2534fd3a7d8c1b1401ebc64b5f1191eb21bb8b`) / `9862996106` (`b9a6288472f0ec204f93aa0f209b457c365e4c8ecf98e166c100c99bb3f6caf4`). Package postflight is byte/mode identical; no rebuild, repair, mutation, discovery, or benchmark occurred.

Ordinal 366 no longer reports the v47 `RotationRayOrderKeyCollision`; it now fails earlier at source vertex **10**, face `(8,10,11)`, `VertexTracePortOrdinalInvalid`, attempt 0 / zero cut edges. The earlier red prevents the required v47 five-ray/distinct-secondary runtime proof. Package source reuses that reason for both legacy port validation and failure of the new exact secondary-parameter computation, so the exact cause is underdetermined. New non-stable gating candidate `M3-CP4c3-TB13-CAND-01` routes to independent `M3-CP4c-3-TB13-REV` BK0-BK8; no product patch is authorized. Stable accounting remains **44 / 14 / 30**, debt **5**, accepted **365/365**, packages **80**.

## 2026-09-02 — `M3-CP4c-3-CB15`: exact vertex-locus ray ranking build green; package 83 frozen

CB15 is **COMPLETE / BUILD + PACKAGE GREEN / PRODUCT CORRECTION / RUNTIME-FREE** at final source `a2fd98eaa015ff5872890bb1945cf4e9e9493615`. The vertex-locus branch of `build_rotation_system` replaces the invalid origin-port ordinal `secondary` with exact locus-relative within-wedge rank, covering Forward, Reverse and interior-terminal rays; exact ties remain fail-closed as `RotationVertexTraceRaysExactlyCoincident`. No arc/trace/orientation identity tie-break, other ordering/cut/topology change, fixture mutation, or deferred correction was introduced. Selector 378 remains byte-frozen; selector **379** appends `GlobalTopologyPlan.VertexLocusSecondaryRankUsesExactWithinWedgeGeometry`, SHA-256 `ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`.

The first eight-target compile exposed only deleted-default-constructor use in the new test helper; a surgical aggregate-initialization correction produced final source. Authoritative full compile `33667287957 / 100372314673` passed all eight standard targets with GMP/GMPXX; result/log artifacts `9861189794` (`310d8ac7a0b40cd11932e0e0a1a8c1b9e19689f927a6d9f383981867e6810f50`) / `9861190565` (`dfce2f1c1e8b0ca877d5ceb4ba576f36812ebd4582ef264806ac32c408115e2e`). Immutable package **83** from `33667812301 / 100373836357` is artifact `9861269273` (`1b8ce6a12edc8f7949deea3c43855e94e5755c0e73ed1cb603a2acd50901cab4`), inner tar `c09d98ed35e9155805f759f27f54491b03643851650ce49dcb65c2191fc069ff`, packaged source `55305976488edc1edc13432e953787555c5ef5d4dcaff041617c0ae568d922c2`; 27 fixtures, six executable modes and internal manifests verify. `runtimeExecution=false`, `packageRepair=false`. Accepted authority remains **365/365**, stable accounting **44 / 14 / 30**, debt **5**, semantic packages **80**. Exact next: artifact-only `M3-CP4c-3-TB13`; no runtime acceptance is claimed by CB15.

## 2026-09-02 — `M3-CP4c-3-TB12`: distinct-ray rotation collision measured; review required

TB12 is **COMPLETE / VALID SEMANTIC RED / NON-STABLE** on immutable package **82** / source
`71ece3ca184e90858d9222fb014b37c16d292294` and selector **378**. Authoritative run/job
`33657062615 / 100338185825` executed 378 fresh selector processes: **370 PASS / 8 RED**, accepted ordinals
**1-365 = 365/365 PASS**, first red remains **366**. Result/log artifacts are `9857275334`
(`085b3de9ebf5a9a29cbcf883e4058c97855e11a1a7b2bc53f961c809dace9145`) / `9857276091`
(`89cac6cb1ea6444b8204d8b5ca9233daed7e0ff88986d8592af576e319cb4120`).

Ordinal 366 retains two distinct same-sector rays: arc 20/trace 6/Forward/origin vertex 47 and arc 23/trace
9/Reverse/origin vertex 71, both `(primary,secondary)=(3,0)` in face `(45,46,47)` / fan slot 1. The complete
5-ray census is untruncated. This falsifies the simplest duplicate-incidence identity explanation and proves
`secondary` is not vertex-local in the failing production witness, but whether the rays are valid coincident rays
requiring tie/equivalence semantics, invalid/stale provenance, or a witness/precondition violation remains a semantic
review question. Unmeasured `nonDiscComponentCount` / `remainingAdmissibleEdgeCount` are absent; selector 378's
production diagnostic projection PASSes. 367/371/372 share the same upstream stop; 368/369/370/374 reproduce prior
carried reds unchanged. Immutable postflight passed; no build/repair/mutation/benchmark occurred.

`M3-CP4c3-TB11-REV-CAND-01` is CLOSED / RUNTIME DISCRIMINATED; `M3-CP4c3-TB11-CAND-01` remains ACTIVE /
GATING as **DISTINCT-RAY SAME-SECTOR COLLISION / SEMANTIC POLICY UNADJUDICATED**. Accepted authority stays
**365/365**, stable accounting **44 / 14 / 30**, debt **5**, semantic packages **79**. Exact next: independent
`M3-CP4c-3-TB12-REV` under BI0-BI7; no unchanged TB12 retry or semantic correction before review.

## 2026-09-02 — `M3-CP4c-3-CB14`: diagnostic collision witness build green; package 82 frozen

CB14 is **COMPLETE / BUILD + PACKAGE GREEN / DIAGNOSTIC-ONLY / RUNTIME-FREE** at final source
`71ece3ca184e90858d9222fb014b37c16d292294`. TB11-REV BH0–BH9 are implemented without changing collision/order/
incidence/rotation/cut semantics: both colliding rays retain typed key operands, identity/orientation/origin-port
provenance and fan slots; the locus publishes a bounded keyed-fan census; unmeasured certification counters no
longer render as observed zeros; and production-renderer synthetic/mechanical diagnostic assertions are compiled but
unexecuted. Selector 377 remains byte-frozen at `7255ac86…26cbec1`; selector **378** is 377 plus one non-gating
diagnostic identity, SHA-256 `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`.
Compile run/job `33653092570 / 100324843819` passed all eight standard targets with GMP/GMPXX and no runtime. Immutable
package **82** from `33653737897 / 100327139865` is artifact `9855841174`
(`4f597d260a6fb258767378489741326a6f6c2322522bdd60ef9fd071970c26ed`); inner tar
`58393e9927e80e894a753cafee074202fd6df8fec43d8cba244fe1404e23a5e1`; packaged source
`3ae91b7544749f00487ff57e1705d657d23d84ffe3107ce1a4565c3a24d35f1e`; 27 fixtures and six executables verify.
Accepted authority stays **365/365**, CP4c-3 OPEN, stable accounting **44 / 14 / 30**, debt **5**, semantic packages
**79**. Exact next: artifact-only `M3-CP4c-3-TB12` under the frozen TB12 plan; no semantic correction before its
runtime discrimination.

## 2026-09-01 — `M3-CP4c-3-TB7`: 365-prefix green; first red is vertex-11 seed unavailability

TB7 is **COMPLETE / VALID SEMANTIC RED** on immutable package **76** / source
`e5d6ed76cfb4e0dc21e39aa8d3fc5de98fd5595a`. Authoritative run/job
`33541437165 / 99968443127` passed immutable package/source/GMP/27-fixture/six-executable/selector preflight,
executed selector 374 one identity per fresh process, re-proved **365/365**, then first-red ordinal **366** with
`VertexTransitSeedUnavailable` at source vertex 11, face `(8,10,11)`, branch 1, region 0, `FaceInterior`.
The mandatory 367–374 report-only remainder ran **1 PASS / 7 RED** with zero gate credit: sphere 368 reproduces
`NoCarrierMatch / SourceEdgeUnavailable`; 369 again reports `saturationUsed=true`; 370 reproduces the genuine
empty-network product red; 371/372 are upstream-blocked; 373 passes synthetically; and new ordinal 374 stops at
`atlasBuild=false` before the folded-cone vertex-star discriminator, with no typed atlas error published. Immutable
postflight PASSes and all build/repair/mutation/benchmark flags remain false. Result/log artifacts are
`9813862211` (`81415716…86f0`) / `9813862640` (`188d02d9…a1a4`). Stable accounting remains **44 / 14 / 30**,
debt **5**, semantic packages **74**. Exact next: independent `M3-CP4c-3-TB7-REV` REVIEW + PLAN; no unchanged retry
or semantic correction before review.

## 2026-09-01 — `M3-CP4c-3-TB6-REV`: Amendment 17 still violated; exact CB8 successor frozen

Independent REVIEW + PLAN only; no Directional runtime/build/package/test/fixture/selector mutation. TB6 immutable
evidence was re-established and one documentation identity corrected: authoritative result artifact is
**`9782227361`** (`e39fcab4ec71c951f9dd7505d052d73fbee7a4f2f66105ae6ff7a47dad672a87`), not the previously recorded
`5748464145 / f084...`. The semantic result remains 365/365 accepted-prefix green and first-red 366 at regular
vertex 30. Static source/fixture reconstruction proves CB7's exactness repair reintroduced the Amendment-17
mechanism: every fan transition maps the branch label by `signedLift` and then assigns the target face's local
`nextPairing->direction` as `incomingDirection`, so the election still tests one representative per cell. Candidate
faces row 41 and row 208 have disjoint branch-vector families, independently proving the local representatives are
distinct. The resolver retains exact per-state audit rows, but `network_failure_locus` /
`SurfaceCellFailureLocusDiagnostics` drops them at the production projection boundary. The CB7 minimal witness is
adjudicated as required future gate authority: preserve selector 373 and append the strengthened identity as ordinal
374. Ordinal 370 is a separate genuine `SurfaceCutGraph::canonical_candidate` red and is deferred. Stable accounting
remains **44 / 14 / 30**, debt **5**, semantic packages **73**. Exact next: runtime-free
`M3-CP4c-3-CB8` under `Architecture_M3_CP4c3_CB8_Code_Build_Plan.md`.

## 2026-09-01 — `M3-CP4c-3-CB7`: exact/reportable transit build green; package 75 frozen

CB7 is **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE** at semantic/evidence source `e926ada023bc51220628be550bbe9a87f98d7067`. Vertex transit now gives typed seed/walk failure reasons and per-state outcomes before every suppressing path; its election datum remains exact rational throughout atlas branch transport, with no world-space-double round trip reaching `direction_in_vertex_sector`. Amendment 17's incoming-direction election is unchanged but fully measurable again. CB7 also publishes prescribed-sphere trace/edge binding evidence, repairs only ordinal 370's invalid constant-field witness using the accepted torus raw field, adds the minimal exact fan transit witness, and freezes AU8's full remaining-ordinal report-only cadence. Compile `33455549602 / 99694672138` built all eight standard targets with GMP/GMPXX and `runtimeExecution=false`; result/log artifacts `9781459057` (`e66ff9cb…cbba`) / `9781459549` (`5fea70b8…c2b9`). Mode-preserving package **75** from `33456115934 / 99696350077` is artifact `9781487311` (`547f2441…54b8`), inner tar `8814b700…7896`, source archive `64e5189f…629a`, 27 fixtures and six `0755` executables. Selector 373 is unchanged. Stable accounting remains **44 / 14 / 30**, debt **5**; semantic packages advance **72 → 73**. Exact successor: artifact-only `M3-CP4c-3-TB6`.

## 2026-08-31 — `M3-CP4c-3-TB5`: 365-prefix green; first red moves to zero-candidate vertex 11

TB5 is **COMPLETE / VALID SEMANTIC RED** on immutable package **74** / semantic source
`49536cf7b4b261bd52f36a91c861b6459db356a4`. Authoritative run/job `33448925069 / 99674216849` passed immutable
package/source/GMP/27-fixture/six-`0755`/selector preflight, ran exactly one identity per fresh process, re-proved
**365/365**, then first-red ordinal **366** at `VertexTransitSectorUnresolved`: source vertex 11, face `(8,10,11)`,
branch 1, region 0, `FaceInterior`, zero candidate faces, no barrier absorption/incidence, and no serialized
`vertexTransitState` rows. This differs from TB4's two-candidate vertex-30 locus and requires independent review;
Amendment 17 is not accepted merely because the old locus was not reached. AP6 367–373 ran once report-only with
zero gate credit: **1 PASS / 6 RED**. Sphere 368 now proves `NoCarrierMatch / SourceEdgeUnavailable`; 369 again
reports `saturationUsed=true`; 370 publishes `NonIntegralCycleLift;topologyRegion=0`, classifying its constant-zero-
field torus setup as an invalid diagnostic witness/precondition; 371/372 are upstream-blocked; 373 passes
synthetically only. Result artifact `9779114492` is `a4d9239e…ca55`; postflight PASS and every build/repair/mutation
flag false. Two earlier control attempts produced no semantic evidence: one reusable-permission startup failure and
one pre-runtime selector-358 lineage check corrected from byte-prefix to exact-hash/set-subset continuity. Stable
accounting remains **44 / 14 / 30**, debt **5**, semantic packages **72**. Exact next:
`M3-CP4c-3-TB5-REV` independent REVIEW + PLAN; no unchanged retry or semantic patch before review.

## 2026-08-31 — `M3-CP4c-3-CB6`: Amendment 17 build/package green; package 74 frozen

CB6 is **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE** at final semantic source
`49536cf7b4b261bd52f36a91c861b6459db356a4`. Amendment 17 now elects vertex continuation from one arrival
direction transported around the reachable fan; per-cell representatives remain audit diagnostics only. Ordinal
370 now prints its typed atlas-build error/locus without witness repair, and the prescribed-sphere no-source-edge
path publishes `NoCarrierMatch / SourceEdgeUnavailable` without a sphere semantic fix. The first compile-only
attempt exposed one `DomainResult<SourceVertexId>` access error; the sole correction was `rowVertex.value()`.
Authoritative retry `33445894845 / 99664857496` compiled all approved targets with GMP/GMPXX and
`runtimeExecution=false`; result/log artifacts are `9778128771` (`64ff0422…996c`) / `9778129236`
(`cc9019d9…0490`). Mode-preserving package **74** from `33446658075 / 99667201075` is artifact `9778267541`
(`bad0ade7…767d`), inner tar `c8d51676…5d8e`, with packaged source `5afa250d…c931`, 27 fixtures and six `0755`
executables. Selector 373 is unchanged. Stable accounting remains **44 / 14 / 30**, debt **5**; semantic packages
advance **71 → 72**. Exact successor: artifact-only `M3-CP4c-3-TB5`.

## 2026-08-31 — `M3-CP4c-3-TB4`: exact two-candidate transit locus measured; AP6 diagnostics executed

TB4 is **COMPLETE / VALID SEMANTIC RED** on immutable package **73** / semantic source `2d22ef293363058cfdca96d01158a93d2c0200f8`. Authoritative run/job `33436492493 / 99634138202` passes immutable package/source/GMP/27-fixture/six-`0755`/selector preflight, re-proves **365/365**, then first-reds ordinal **366** at `VertexTransitSectorUnresolved`. CB5's typed locus exposes source vertex **30**, face `(24,30,32)`, branch 1, region 0, `FaceInterior`, exactly two candidate faces `(25,30,31)` / `(30,31,119)`, `BarrierAbsorbed=false`, `barrierIncident=false`: M1's zero-candidate prediction and direct M3 are falsified, while M2's singular-holonomy cause remains unproved. AP6 then runs 367–373 once report-only with zero gate credit: **1 PASS / 6 RED**; 368 reproduces sphere `TraceEventPositionInvalid` trace 2/event 30, 369 reports saturation still used, 370 stops at `atlasBuild=false`, 373 passes. Result/log `9774693166` (`056f86df…8a7e`) / `9774693946` (`d2acc620…fcb6`); immutable postflight PASS and all build/repair/mutation flags false. Earlier `33436283363 / 99633462747` is resolved pre-runtime orchestration only: the runner expected `package73.tar.gz.sha256` instead of actual `package73.sha256`; control commit `41a7a8b…dde7b` corrected only that lookup. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **71**. Exact next: independent `M3-CP4c-3-TB4-REV`; no unchanged TB retry or semantic correction before review.

## 2026-08-31 — `M3-CP4c-3-TB3-R1`: valid semantic first red moves from atlas to vertex transit

TB3-R1 is **COMPLETE / VALID SEMANTIC RED** on immutable package **72**. Run/job `33416686424 / 99568970224` passed package/tar/source/GMP/27-fixture/six-hash/six-`0755`/selector preflight and executed selector 373 from ordinal 1 as one exact identity per fresh process. Ordinals **1–365 passed**; ordinal **366** `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` first-red with `NotProductionReady/field-aligned-network/VertexTransitSectorUnresolved`; 367–373 were not executed. Immutable postflight passed and no benchmark/configure/compile/relink/repair/generated discovery/mutation occurred. Result/log artifacts: `9767376410` (`7f2c9492d2dae96dfcf1732c320e772be05538a3552ce6a673bd83eb9189824e`) / `9767376976` (`492d19f1e08fd339f130a07dfcf891a3b7bbaaf537483fb54af6e9b96095ad72`). The prior `MissingSingularityBranchTransport` stop is cleared; the witness reaches network construction. New non-stable gating candidate `M3-CP4c3-TB3-R1-CAND-01` records the unresolved exact vertex-sector candidate cardinality/locus. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**. Exact next: independent `M3-CP4c-3-TB3-R1-REV`; no unchanged retry or implementation before review.

## 2026-08-31 — `M3-CP4c-3-CB4-PKG`: package 72 restores executable-mode transport authority

CB4-PKG is **COMPLETE / PACKAGE GREEN / RUNTIME-FREE**. Package-only run/job `33411346157 / 99551438549` consumed raw CB3 artifact `9750227619` (`b1cc9a989af2db84ddd2ad83babf9b2221396e45a165aa84927082e610c351c8`) through the Actions artifact API, re-proved all six frozen binaries as byte-identical `0755`, copied exactly 27 fixtures only from embedded source archive `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`, regenerated the 55-entry manifest, and emitted mode-preserving package **72** without configure/compile/relink/runtime/benchmark. Artifact `9765247195` has Actions SHA-256 `41ebe4dec4a3eb5c8194900a3f27a0377c3271212edd10fb952c48f55a6a2e6d`; inner `package72.tar.gz` is `20630897aa432572d0929022abef3861fff80c2b5792c223071990dd2e3c6a73`. Independent post-download clean extraction re-proves source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, GMP authority, 27 fixtures, 55/55 manifest, and six exact hashes/modes. `M3-CP4c3-TB3-ORCH-01` is resolved non-stable; stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**. Exact next: artifact-only `M3-CP4c-3-TB3-R1` on package 72 and unchanged selector 373 from ordinal 1.

## 2026-08-31 — M3-CP4c-3-TB3-REV traces ORCH-01 and freezes package-only correction

- Independent review proved raw CB3 artifact `9750227619` preserves all six exact runtime binaries with mode `0755`; final package 71 has identical binary hashes but `0644`.
- Root cause is the CB3 fixture-packaging `actions/download-artifact@v4` materialization boundary, which normalizes artifact files to `0644` before final re-upload. No product semantic defect was observed.
- Decision: **approved with amendments**. Exact next is runtime-free `M3-CP4c-3-CB4-PKG`, starting from raw compile authority and emitting a mode-preserving `package72.tar.gz`; no replacement compile or TB-side permission repair.
- Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**.

## 2026-08-31 — `M3-CP4c-3-TB3`: blocked pre-runtime by package-71 executable modes

TB3 is **COMPLETE / BLOCKED — PRE-RUNTIME / NO SEMANTIC VERDICT**. Run/job `33399144281 / 99510922630` verified exact immutable package **71** (`9750235004`, `bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`), its complete internal manifest, semantic source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, source archive `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`, and packaged fixtures, then stopped before ordinal 1 because all six packaged test/benchmark executables extracted as mode `0644`. Artifact-only policy prohibits `chmod`, repacking, repair, mutation, or replacement compilation. Result/log artifacts: `9760518962` (`ec5bc5cccb99e38e4ce77533478c5864e756735b3511575d843bbafb328f4677`) / `9760519355` (`b803c9f81df4a5acbea642860d88f8c61f3df8f13d2204cf836344f6efb1016d`). Selector execution **0/373**; no runtime, benchmark, configure, compile, relink, generated discovery, repair, or mutation occurred. New `M3-CP4c3-TB3-ORCH-01` is **ACTIVE / BUILD-PACKAGING CONTRACT DEFECT / NON-STABLE**; exact mode-loss stage is deferred to independent review. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**. Exact next: independent `M3-CP4c-3-TB3-REV` — no repackage/rebuild/mode repair/TB retry before review.

## 2026-08-31 — `M3-CP4c-3-CB3`: Amendment 16/P2 build green; package 71 portable

CB3 is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic source `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`. Static AN1 measurement found four barrier-incident mechanical singularities, all degree-2 interior-arc facts with two transport-star components, selecting Amendment 16 **P2 (`BarrierAbsorbed`, no ports)**; no illegal hard-feature transport and no sphere-specific fix were introduced. Atlas/pipeline diagnostics now publish complete failure loci and barrier-singularity census/classification. AN2 independently proves package 69/70 binaries byte-identical. AN3 removes compile-time absolute fixture-root authority and package 71 carries 27 fixtures at `test-data/benchmarks/fixtures`. Run `33370966957` compiled all eight required targets with GMP/GMPXX and no runtime. Immutable package **71** is artifact `9750235004` (`bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`), source archive `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`; fixture contract and binary-byte invariance pass. Selector 373 remains frozen/unexecuted. Stable accounting stays **44 / 14 / 30**, debt **5**, semantic packages **70**. Exact next: artifact-only `M3-CP4c-3-TB3`.

## 2026-08-31 — `M3-CP4c-3-CB2`: Amendment 15 option A′ build green, selector 373 frozen

CB2 is **COMPLETE / BUILD GREEN / RUNTIME-FREE**. Semantic source `005512f20ed56edc793f4d6505f3d2b4c2999c71` implements Amendment 15's A1 derived transport cut along `B(R)`, barrier/Euler/singularity fail-closed controls and diagnostics, carries AM7 sphere subreason provenance, adds AL8 digest-authoring validation, and freezes selector **373** (`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`). All predecessor 355/357/361/365/367/370 hashes, cardinalities and byte prefixes reverify. The inherited R10/R8 identities are gated at 369/370 but their product corrections are **not claimed accepted or runtime-proven**. First compile `33347423799 / 99354145677` found only a deleted-default-constructor issue in the new diagnostics type and ran no Directional runtime; the minimal explicit-initialization correction then built successfully on `33347935915 / 99355596358`. Immutable GMP package **69** is artifact `9742715856` (`2accc6d7cbbd48531919518ceb93a9d8f837b1c5683769a88ef915e4f092efc5`), source archive `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`, log `9742715997` (`f0f94864be943658bc4d461bdafc312b1d40333e7eca9d2dd4ae88cacdfb218b`), internal manifest **28/28 PASS**, all eight standard targets linked with GMP/GMPXX, clean source status and `runtimeExecution=false`. Stable accounting remains **44 / 14 / 30**, debt **5**, packages **69**. Exact next: artifact-only `M3-CP4c-3-TB2` on package 69 and selector 373; no rebuild/repair/benchmark.

## 2026-08-30 — `M3-CP4c-3-CB1`: phase-1 provenance instrumentation build green

CB1 is **COMPLETE / BUILD GREEN / RUNTIME-FREE / INSTRUMENTATION ONLY** under AK0–AK3. Instrumentation commit `014c7f7f8d6984518cf5c81156a10d3e06298349` adds eight-way `IncompleteCycleBasisReason`, per-region cycle-basis shape diagnostics, and nine-way `RotationSystemInconsistencyReason` provenance without changing product error mappings or selector bytes. First compile-only run `33338011871` caught one construction defect in the new diagnostics row; isolated corrected source `48dd011c4aa689a245b74527ed9df0900ada9bf3` aggregate-initializes that row with `region.id()` and changes no intended product behavior. Authoritative GMP/GMPXX compile run/job `33338642383 / 99330058374` compiled/linked all eight standard targets with `runtimeExecution=false`, clean source status, and internal **28/28** manifest, producing immutable package **68** artifact `9739919234` (`127c7b086a8849de7f0c14928f2c5d762c3bf71711821d0a1fabfefda889d11c`), source archive `f1fce7f720718c8ac974d0d5f77ca1fee4244b10c710d2b505a1af162e4f937f`, and log artifact `9739919468` (`2074a5d2035dd84fe62ad424a8d95dfebe7af219f520f9f07e062af57ade21cd`). Selector 367 remains `ef9d082f…16bf`, all frozen prefixes/cardinality/uniqueness reverified. Stable accounting remains **44 / 14 / 30**, debt **5**, packages **68**. Exact next: artifact-only CP4c-3 phase-1 TB on package 68, selector 367 from ordinal 1, publishing AK1–AK3 evidence; no phase-2 fix before independent review.

## 2026-08-30 — `M3-CP4c-2-TB-X2-R9-EXEC`: valid semantic red at ordinal 363


R9 is **COMPLETE / VALID SEMANTIC RED** on authoritative run/job `33319911575 / 99279955697`, consuming immutable
CB8 package `9726295440`. Preflight reproduced package/source hashes, 28/28 manifest, GMP/GMPXX, executable modes,
selector 365 and frozen prefixes. Three non-gating diagnostics ran once each; the prescribed-sphere publisher remains
red and directly confirms `originatingTopologyError=RotationSystemInconsistent`, while the other two pass. Selector
1-355 re-proves **355/355**, 356-362 pass, and 363
`SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs` fails with `InvalidCutGraphBinding`; 364-365
are not run under the frozen hard stop. R8-CAND-01's 359/361 runtime closure condition is satisfied; AH6 is not
applicable because 363-365 were not all reached. Immutable source localizes `R9-CAND-01`: the crossing builder splits
one selected source cut edge into multiple Cut arcs, while region binding still requires exactly one. Result/log
artifacts `9734625006` (`d4cac956…a3081`) / `9734625165` (`9325840a…274e10`); postflight PASS; all
build/mutation/benchmark flags false. Stable accounting remains **44 / 14 / 30**, debt **5**, packages **66**. Exact
next: independent `M3-CP4c-2-TB-X2-R9-REV`.

## 2026-08-30 — `M3-CP4c-2-CB8`: closed-witness authority correction build green

CB8 is **COMPLETE / BUILD GREEN / RUNTIME-FREE**. Semantic/test source
`05f9ef299ee54f8c9d50318fc9a37e5a5503740d` corrects ordinals 359/361 to consume one production feature authority,
adds closed-witness non-vacuity guards, and replaces the fabricated default-error sentinel with typed stage failures.
AH1's retained R8 evidence contained no `ADD_FAILURE` lines and proved the former zero-node/zero-arc witness reached
`SurfaceCutGraph::make`; because its real code/origin was not printed, CB8 records active non-gating product question
`M3-CP4c2-TB-X2-R8-CAND-02` and does not widen into a product fix.

Authoritative GMP package **66** is artifact `9726295440` (`sha256:1017a2f40829c171a0ec066b16e1f9f5436588f5e2376742e340ce1617d2556f`),
source archive `ec9b9b7929521e3f2cd1df4e21beb2f01012f97ff1907ffbf5ae2b35334fd20c`, run/job
`33292137782 / 99205507393`. The build transport used the verified GitHub Eigen mirror at exact gitlink `769c72fd…`
after GitLab load failure; canonical `.gitmodules` was restored. All eight standard targets linked with GMP/GMPXX,
manifest 28/28, and no Directional executable ran. An earlier caller permission startup failure and one GitLab
checkout failure produced no semantic/build package evidence.

Selector 365 remains byte-frozen at `6b5b6555…14b8a1` with unchanged 355/357/361 prefixes. Stable accounting remains
**44 / 14 / 30**, debt **5**, packages **66**. Exact next is artifact-only `M3-CP4c-2-TB-X2-R9-EXEC` on package
`9726295440`, from ordinal 1, with AH6 mandatory if ordinals 363–365 are reached. No benchmark is frozen for R9.

## 2026-08-30 — `M3-CP4c-2-CB7`: Amendment 14 build green, selector 365 frozen

CB7 is **COMPLETE / BUILD GREEN / RUNTIME-FREE**. Semantic source `4f0f3ca74a88ba260a20c019437bc4995f2056e0`
implements the deferred AF0/AF2/AF3/AF4 measures plus DEFN-R2 AG1–AG7: preserved originating topology-error
provenance, repaired withdrawn-barrier diagnostics, production-authority torus/enumeration surfaces, exact
trace-crossed cut nodes and cut/trace subdivision, generalized four-sector edge-locus rotation, explicit
`CutSearchExhaustedBeforeCellularity` plus published saturation, a purpose-built trace-crossed witness, and an
independent crossing oracle. Selector **365** is frozen at
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`; its 355/357/361 prefixes reproduce their
frozen hashes exactly. GitLab load errors blocked three checkout attempts before compile, so the authoritative
package used transport-only source `1230621baff6d04fb20df3b1bf48903cd65b5d69`, substituting the verified GitHub
Eigen mirror at exact gitlink `769c72fd8019e389810d1de1e7c243521a43b594` without changing any semantic path;
the canonical remote was restored afterward. Run/job `33287281975 / 99192562149` compiled all eight standard
targets with GMP/GMPXX, clean source, and `runtimeExecution=false`. Package `9724864897`
(`a4d9803eea326b5a22f6c4e21cc07e0908eaede944d02a726ae3c5f6d856734c`), log `9724865018`
(`462090e66648fc6db583b770a2518aca0a3f63ee2ae167d900070fb4ed5460bd`). Stable accounting remains
**44 / 14 / 30**, debt **5**, packages **65**. Exact next: artifact-only `M3-CP4c-2-TB-X2-R8-EXEC`; no gate was
selected or executed in CB7.

## 2026-08-29 — `M3-CP4c-2-CB5`: semantic/provenance split build green

CB5 is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic/test source `755485865a7cf9c485d754f22b82a41ee151824b`. `SurfaceCutGraph` now separates gauge-invariant semantic identity from full provenance while leaving `candidate_hash` and atlas/network tamper binding unchanged; `GlobalTopologyPlan` consumes the semantic cut-graph digest; the face-orbit ordinal is retained with a documented canonical-rank proof; and two non-gating cut-graph gauge-relabeling diagnostics were compiled for two-ring and torus. Source recovery patch SHA-256 `3106b52029f546262e86e734a430e3c31ad213139bfb0d358e5af31f88e6a8c1` / diff-body `40a9eec971fe17691577159c0f876409a26f472dcdbd2e26baa8a3578f94c008` was emitted, staged through Drive, and applied on `33267545221 / 99140191320`; result/log artifacts `9719098241 / 9719098425`. Authoritative compile/package run `33267732093` compiled the changed-owner test target and all eight standard targets with GMP/GMPXX, no runtime, source clean, internal **28/28 PASS**. Fresh package `9719216316` (`acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`), log `9719216455` (`af03c536bc55f37be90f6f654bb2e944c66a15036920e536a97cb5523b00f7c4`), source archive `78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`. No selector changed; stable accounting remains **44 / 14 / 30**, debt **5**, packages **64**. Exact next: artifact-only `M3-CP4c-2-TB-X2-R7-EXEC`; 357/358, cumulative gate, benchmarks, mechanical/C2, and CP4c-3 remain blocked.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R6-EXEC`: accepted-prefix semantic red at ordinal 310, postflight green

Artifact-only R6 consumed immutable CB4 GMP package `9714226920` (`931d422611a8144faf4efe3f9307b3a1a90bbce4cab6d8873eb95b32ca1b9f83`) from semantic/test source `cebc12082c6dbe4830095df08169797b7dab0c5c`. Immutable package/source/GMP, executable-mode, internal-manifest, and all six frozen selector-hash preflight checks passed. Accepted identities then ran one per fresh process: **1-309 PASS**, including former failure ordinal 305; ordinal **310** `GlobalTopologyPlan.RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling` selected once and failed because gauge-equivalent plans produced semantic digests `12176020141753559903` and `14339407889897379635`. Frozen hard stop skipped 311-355, the independent actual-complex oracle, retained barrier diagnostic, D2, 357/358, cumulative gate, and benchmarks. Unconditional R6-5 postflight passed with package/source byte-and-mode equality and every configure/compile/relink/repair/discovery/mutation flag false, resolving R5-ORCH-01. Static tracker localization records new stable `PR8-R044 / M3-CP4c2-R002` (`REPRESENTATION_DEPENDENT_IDENTITY / RP-05`): `SurfaceCutGraph::candidate_hash` includes gauge-dependent atlas provenance and `GlobalTopologyPlan` consumes the resulting cut-graph digest as semantic identity. Stable accounting advances **43 / 14 / 29 -> 44 / 14 / 30**, debt **5**, packages **63**. Raw evidence: `Architecture_M3_CP4c2_TB_X2_R6_EXEC_Artifact_Only_Evidence.md` plus File-Library archive SHA-256 `340f2e569d372809a299d5b7c065966756797fb2a6e47db959d82ea62213e4f5`. Exact next: independent `M3-CP4c-2-TB-X2-R6-REV`; no new runtime or corrective CB in EXEC.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R5-REV`: accepted regression is whole-face/embedded-graph authority conflation

Independent review is **COMPLETE / REVIEW GREEN / REPLAN REQUIRED** with no Directional runtime, build, compile, package, or product/test/fixture/selector mutation. R5's ordinal-305 red is admissible for semantic diagnosis despite missing postflight and is promoted to stable `PR8-R043 / M3-CP4c2-R001` (`AUTHORITY_DOMAIN_CONFLATION / RP-01`). Retained CP4ab evidence on the same accepted two-ring gives actual embedded-network `V/E/F=9/11/3`, while R4's self-consistent whole-source-edge proxy gives `10/11/2`; current `SurfaceCutGraph` mixes network `V/E=9/11` with proxy `F=2`, yielding `0 != source χ 1` at its final certificate. The prior R2 claim that `sourceEdgeBarrier` is normative is withdrawn; it is a diagnostic/proposal proxy, not actual cellularity authority. AA2's two R4 sphere records are independently byte-identical (468 bytes each, SHA-256 `84f9ca015ab63093086981cbd29256526159329c64537dfb52fba9e89d9fd078`). AA1 is not causal and is retained. Stable accounting advances **42 / 14 / 28 -> 43 / 14 / 29**, debt **5**, packages **62**. Exact next: definition-only `M3-CP4c-2-DEFN-R1` under AB0-AB9; no corrective CB or gate yet.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R5-EXEC`: AA8 accepted-prefix semantic red at ordinal 305

Artifact-only R5 run/job `33232106030 / 99046593525` consumed immutable GMP package `9708324052` from source
`76d757aab0ce18df09ce2823302d2dc224965187`. Package/source/GMP and all six frozen selector-hash preflight checks
passed. AA8 then ran accepted identities in fresh processes: 1-304 PASS; ordinal 305
`GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` selected once and failed after
`SurfaceCutGraph::make` returned `CellularityNotEstablished`. The frozen stop rule prevented ordinals 306-355, AA2,
D1, D2, 357/358, cumulative gate, and benchmarks from running. Result/log artifacts `9708817991 / 9708818239`,
SHA-256 `bda50fcdaf2b89ccce9a9b1ed5ecb7f4cd656a4168583635e69251f03c2556e8 /
b9e150dec9d47cec140f982650a65b5d8668d3c5d5b8f4074bae7e3d6f8c9688`. A temporary shell-control defect exited
after the semantic red before planned postflight/summary emission; this limitation is preserved for independent
review. New non-stable candidate `M3-CP4c2-TB-X2-R5-CAND-01`; stable accounting remains **42 / 14 / 28**, debt **5**,
M3 packages **62**. Exact next: independent `M3-CP4c-2-TB-X2-R5-REV`; no new runtime.

## 2026-08-29 — `M3-CP4c-2-TB-X2-R4-EXEC`: valid semantic red, D1 evidence-conflict stop

Artifact-only R4 run/job `33228460953 / 99036688477` consumed immutable GMP package `9707091209` from source
`5ad711e5d4ced95f38e103b993139a6307ba2cee`. Pre/post package/source/GMP/selector integrity passed. D1 ran once:
torus published the product-authoritative 48/48 non-cellular control with `oracleSelfConsistent=true`; prescribed
sphere published a typed `pipeline-source-topology-snapshot-unavailable` construction failure; two-ring published
a successful/self-consistent record. The final accumulated GoogleTest assertion repeated the sphere failure
record, yielding four Y1 lines instead of exactly one per witness, so the frozen contract stopped at
`STOP_EVIDENCE_CONFLICT`; D2 was not authorized. No selector 355/357/358, cumulative gate, benchmark, compile,
relink, generated discovery, repair, or source/package/fixture mutation occurred. Result/log artifacts
`9707662462 / 9707662682`, SHA-256
`36e5982c152317a56d98d13e58a2ec1233c71b65e9f8570aeabfed373228a76f /
594edbad06c849e12ad52787ec144f08da526c6f25c4449d21a222691daae0eb`. Stable accounting remains
**42 / 14 / 28**, debt **5**, M3 packages **61**. Exact next: independent evidence-only
`M3-CP4c-2-TB-X2-R4-REV`.

## 2026-08-28 — `M3-CP4c-2-TB-X2-R3-EXEC`: valid diagnostic red, planned D1 stop before torus publication

Artifact-only R3 EXEC run/job `33222551366 / 99019499929` consumed immutable GMP package `9704935112` from
source `c552a5a4a318063cde2564c40773ec7edaf064f6`. Immutable package/source/GMP/selector preflight passed and D1
selected exactly once, but exited `1` before any `m3Cp4c2Y1` publication: torus diagnostic fixture construction
failed at `tests/FieldAlignedCurveNetworkTests.cpp:5946` with `witness=torus;error=field-transport-atlas-unavailable`.
The frozen stop rule therefore skipped D2; no Y5 branch, selector 355/357/358, cumulative gate, benchmark, build,
relink, repair, or generated discovery ran. Recursive package/source byte-and-mode postflight matched exactly.
Result/log artifacts `9705692837 / 9705693025`, SHA-256
`ba989d0ddd3bd244f03c8242060ded9f9c58b33679893ab0ddf1cc5fb8d015f5 /
ab653c13ec7b0eec30f2736a17bbf44406afa7c828cb1fddbadea795aa6701a6`. A preceding caller startup failure
`33222474179` instantiated zero jobs and repeated the known reusable-observer permission-ceiling orchestration
pattern; the caller was corrected before runtime. Stable accounting remains **42 / 14 / 28**, debt **5**, M3
packages **60**. Exact next: evidence-only `M3-CP4c-2-TB-X2-R3-REV`.

## 2026-08-28 — `M3-CP4c-0b-CB3-INSTR`: bounded non-gating observability build green

CB3-INSTR is **COMPLETE / BUILD GREEN / RUNTIME-FREE** under independent-review measures V0-V7. Exact source `93059089881c8715a168a61968a8d6874ee1a670` changes only `tests/FieldAlignedCurveNetworkTests.cpp` and the CP4c-0b non-gating selector; `src/`, `include/`, fixtures, accepted identities, and the frozen 353 selector are unchanged. V1 selects the existing sphere A2a census; V2 adds a fan termination/guard census; V3 adds a two-ring FirstContact↔MandatoryBarrierTermination pairing census. Required selector remains 353 / `51ff96d7…ac6a5` with first-346 `20d3b0b1…3e46a`; non-gating selector is 4 / `d4224002…d9ad`. Authoritative compile run `33133572290`, jobs `98728445391 / 98728639650`, produced immutable GMP package `9671190795` (`2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1`), internal manifest 28/28 PASS, clean source status, GMP/GMPXX link evidence, `runtimeExecution=false`. Stable accounting stays **42 / 14 / 28**, debt **5**, M3 packages **55**. Exact next: artifact-only `M3-CP4c-0b-TB-T5`; `T5-CAND-01` remains active until U3/U4 are actually published.

## 2026-08-28 — `M3-CP4c-0b-TB-T5`: pre-gate observability gap, 353 not run

T5 is **BLOCKED / PRE-GATE OBSERVABILITY GAP / 353 NOT RUN**. U0 static authority is valid on immutable GMP package `9668492827` and full selector `51ff96d7…ac6a5`, including exact first-346 prefix `20d3b0b1…3e46a`, but U3 requires a before-gate fan/two-ring terminus census that the immutable package cannot fully publish. Its compiled census surfaces omit required per-trace terminus/barrier and arrival-comparison/mutual-tie telemetry, and U4 lacks a dedicated per-witness N1/N2/N4 silence publisher. U7 forbids adding instrumentation or compiling inside T5, so the only valid action was to fail closed before runtime: **0/353 identities executed**, no compile/relink/repair/discovery/mutation/timeout/guard widening. Exact source-snapshot audit `33130565916 / 98718854457`, artifact `9670081197` (`58403bc8…3023a284`). Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **54**. `T5-CAND-01` is active evidence-capability/non-stable; the cleanup-trigger race `T5-CAND-02` is resolved orchestration/non-stable. Exact next: independent `M3-CP4c-0b-TB-T5-PREFLIGHT-REV`.

## 2026-08-28 — M3-CP4c-0b DG T4 execution green 7/7

Artifact-only `M3-CP4c-0b-DG-T4-EXEC` is **COMPLETE / EXECUTION GREEN 7/7** on authoritative run/job `33128261911 / 98711506300`, consuming immutable GMP package `9668492827` (`e0661e66cfc12ce8945962a18b8a8f6fc8aa5a1213b3ad4d2409054573dce0b8`) from semantic source `b2629040450c12507367c232f68a4d972b46450f` and only the re-frozen seven-identity selector `d28bbeeb74ed8e07810b06d870bdaf470bab1f294bbfe810deaa4f63276e245c`. Every identity selected exactly once and passed, including the corrected torus no-contact identity; `zeroSelected=0`, zero escaping C++ exceptions, no repository timeout, no configure/compile/relink/repair/generated discovery, no package/source/test/fixture/selector mutation, and package/source byte-and-mode postflight PASS. Result/log artifacts `9669229181` (`364d5d546bca4c664be67e52b336a48cbc1f49b6bd672371ea6351e396dcc84c`) / `9669229414` (`39c7530a70650702f4345fea9de558ea6139fecd715f8d9b504ef945a94447ef`) were downloaded and independently re-hashed; pre/post inventories compare equal. No regression/candidate was observed, so stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **54**. Exact next: independent `M3-CP4c-0b-DG-T4-REV`; full 353 T5 remains blocked/not run.

## 2026-08-27 — M3-CP4c-0b CB2 test-contract correction build green

`M3-CP4c-0b-CB2` is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic source `b2629040450c12507367c232f68a4d972b46450f`. T1 proved the DG torus red was rail-authority test over-specification: atlas-derived rails yield 0 mandatory edges/nodes while pipeline-authoritative rails yield 48 `HardFeature` mandatory edges and 48 lawful structural endpoint nodes, with zero singularities/traces/events/contact provenance. The never-accepted torus identity was renamed and corrected to assert no contact rather than zero total nodes; census output now names `railAuthority`, `mandatoryEdgeCount`, and `singularityCount`. Re-frozen selectors are 7 / `d28bbeeb…e245c` and 353 / `51ff96d7…ac6a5`. Compile-only run `33126178643` passed changed-owner job `98704812754` and all-eight package job `98705144144`; immutable GMP package `9668492827` has ZIP SHA-256 `e0661e66cfc12ce8945962a18b8a8f6fc8aa5a1213b3ad4d2409054573dce0b8`, 28/28 manifest PASS, clean source status, executable modes preserved, and `runtimeExecution=false`. Stable accounting stays 42/14/28, debt 5; M3 packages are now 54. Exact next: artifact-only `M3-CP4c-0b-DG-T4-EXEC`; T5 full 353 remains blocked on green T4 plus review.

## 2026-08-27 — M3-CP4c-0b DG valid semantic red 6/7

Attempt-free artifact-only `M3-CP4c-0b-DG` is **COMPLETE / VALID SEMANTIC RED 6/7** on corrected run/job `33120730355 / 98686699036`, consuming immutable GMP package `9664890562` from semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d` and only the frozen seven-identity DG selector `14570409…c5724`. Every identity selected exactly once; six pass; sole red `TraceTerminationCorrection.TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit` fails because `torus.network->nodes().empty()` is false while zero candidate traces passes and no separate zero-event failure is reported. Result/log `9666352028` (`286f738f…db72`) / `9666352544` (`651e9cb9…712e`); zero escaping exceptions, no timeout/build/repair/mutation, immutable byte-and-mode postflight PASS. Earlier run/job `33120437486 / 98685729035` executed zero Directional identities and is resolved as a temporary `tar|grep`/`pipefail` orchestration defect. Full 353 acceptance TB was **NOT RUN**. Stable accounting remains **42 / 14 / 28**, debt **5**, packages **53**. Exact next: independent `M3-CP4c-0b-DG-REV`; no semantic/test correction or runtime retry before review.

## 2026-08-27 — M3-CP4c-0b CB1 S2-S6 build green

CB1-S2-S6 is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d`. Frozen trace-termination S2-S6 now provide disjoint event vocabulary, exact rational proper-crossing classification, fixed `ArcLengthFiltered` arrival authority with computed forward-error bounds and mutual termination for tied/inconclusive arrivals, globally ordered contact resolution, and exact durable `terminalContact`. The frozen predecessor remains **346** / `20d3b0b1…e46a`; seven new contracts form DG selector `14570409…c5724` and full **353** selector `91371d5a…21efb`, with the first 346 byte-exact predecessor. GitHub Actions GMP changed-owner precompile `33116158072 / 98671267836` and eight-target package compile `33116774891 / 98673348923` are green on the same semantic source; immutable package `9664890562` has ZIP SHA-256 `94beb349763ff261d603839176a458d1f69e976192aafcd0c69d2617abd88273`, 28/28 manifest PASS, clean source status, and `runtimeExecution=false`. Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **53**. Exact next: attempt-free artifact-only `M3-CP4c-0b-DG`, seven new identities only, on the same package.

## 2026-08-26 — M3-CP4c-0-CB5 diagnostic census build green

CB5 is **COMPLETE / BUILD GREEN** at semantic source `cd2ffb74fc0a5680e55ad63ba2bd3fc6b75e456e`. H1 adds one non-gating A1-only cross-face flow-agreement census over two-ring, four-triangle fan, prescribed sphere, and torus; H2 publishes the exact `signedLift` used by `BranchTransportFlowDisagreement`; H3 publishes ordered trace-step history; H4 records matching provenance. H5 was obeyed: no production tracing/transport/matching/tolerance semantics, fixture, selector, or acceptance expectation changed. Authoritative compile-only run/job `32953176800 / 98129036272` compiled and linked all eight standard targets with preflight/build exit 0, clean packaged source state, manifest verification PASS, and `runtimeExecution=false`. Immutable package `9601160869` has ZIP SHA-256 `143cab907b4086a3f3bfc6f29dfdbb103919c9429698b0cce0757ae16f36cefb`; packaged source archive `f7f2e59cf9866beb8e784aeaefc2320cc2306a49ab1813133b7e343d5f3e35e3`; log `9601161248` / `7fab20369e529ea674a8c1fc9561753d935bce2d50297750d9007941fe788b91`. Frozen selector hashes remain 338 `d588cae0…a8116`, first-316 `601ce2b6…0193c`, first-328 `cf93622e…3600`; H1 is uncredited. Stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **44**. Exact next: artifact-only `M3-CP4c-0-TB-R5`; Q8 is expected to remain red and the turn's deliverable is H1's census verdict.

## 2026-08-26 — M3-CP4c-0-TB-R3 valid semantic red

Artifact-only TB-R3 is **COMPLETE / VALID SEMANTIC RED 336/338** on authoritative run/job `32921851098 / 98036868098`, consuming immutable CB3 package `9589508430` (`7bb4bd1a40af68ffd1e2ce06001490d61504e6ed0300505646c0abce97693015`) at semantic source `b135e219ee9269a73eaee32992d80c3921318011`. Accepted **316/316** and prior CP4c-0 **328/328** remain green. F6 continuation executed the full frozen 338 census: ordinal 333 `ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` is the first red; ordinal 334 `ExactVertexSectorPartitionsAcceptedInteriorFans` is a later non-crediting red; 335–338 pass non-crediting. Supplemental F3 falsifiers are **2/2 PASS**. Q8 was not creditable and was **NOT RUN**. Result/log artifacts `9590143527` (`af4f5b28…6604`) and `9590143871` (`ec9c29b7…f5b7`) preserve the evidence; all mutation/build flags are false. The two reds are recorded as non-stable fixture/oracle candidates pending independent adjudication. Stable totals remain **42 / 14 / 28**, debt **5**, packages **42**. Exact next: review-only `M3-CP4c-0-TB-R3-REVIEW-PLAN`.

## 2026-08-25 — M3-CP4c-0-CB2 verification-first build green

CB2 is **COMPLETE / BUILD GREEN** at semantic source `390e65b373063c667e3c3f5e78b74ed9d859093b`. The required pre-edit audit found E1–E9 already implemented on the branch, so this turn made no duplicate production/test/fixture/selector change. E10 compiled all eight standard targets on `32909482352 / 98000623070` with `runtimeExecution=false`; immutable package `9586196535` (`9f74856149909bc1fbcaffe638fd64b4719cddcb8ed8d92972dd52289362003f`), manifest **27/27 PASS**. Required selector is **338 = 316 + 12 + 10**, SHA-256 `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`; first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`. T6/Q8, the prescribed sphere fixture, and `kBranchTopologyTolerance` remain unchanged. Exact next: artifact-only `M3-CP4c-0-TB-R2` on 338/338 plus binding Q8. Stable accounting **42 / 14 / 28**, debt **5**, M3 packages **41**.

## 2026-08-25 — M3-CP4c-1-TB-R2

Artifact-only TB-R2 is **VALID RED 316/318** on `32851859581 / 97814494564` using immutable package `9553525746` (`44a2754c…35c8`). Exactly 321 fresh processes executed: accepted prefix **316/316 PASS**, C4/C5 0/2, three non-gating diagnostics, zero orchestration errors, and every mutation/build flag false. Result `9564681836` (`2febb8c3…7df0`) and control `9564682452` (`d990338a…44a7`) were independently re-hashed after download. Torus is unchanged (A2a, 0 traces/events, A2b `UncutFaceComponentOrbitSeedNotUnique` at `0-1-2`); mechanical A1 now resolves to missing field-transport adjacency (`fieldTransportAdjacencyExists=false`, EF rows valid); prescribed sphere reaches A1 but A2a rejects `InvalidCandidateTraceTransport` at singularity 0 / vertex 0 / edge 1-2, so no network/terminal intersection is produced and C4/C5 stop at the sphere precondition. Stable totals remain **42 / 14 / 28**, debt **5**, M3 packages **38**. Exact next: independent `M3-CP4c-1-TB-R2-REVIEW-PLAN`.

## 2026-08-25 — M3-CP4c-1-CB2

CB2 is **COMPLETE / BUILD GREEN** at semantic source `2888dbdcf5aaf27fd629a5d29cbd57bc7d63e4f0`. Test-side instrumentation adds the prescribed-sphere crash-on-contact observation, terminal-`TraceIntersection` provenance, and mechanical A1 site discrimination without changing `src/` or `include/`. An initial compile-only failure exposed three invalid `DomainResult<T>` dereferences; the surgical `.value()` correction was committed and authoritative run `32822054391` then compiled the producer target and all eight package targets green with `runtimeExecution=false`. Immutable package `9553525746` has GitHub ZIP SHA-256 `44a2754c674b232b1327e4feef636d374d6fac0b5573212ec184eb7cf3ab35c8` and 27/27 internal manifest PASS. Required selector remains 318; non-gating diagnostics are now 3. Stable regression totals remain **42 / 14 / 28**, debt **5**, M3 packages **38**. Exact next: artifact-only `M3-CP4c-1-TB-R2`.

## 2026-08-24 — M3-CP4c-TB-R1

Artifact-only CP4c R1 is **VALID RED 316/322** on `32791027809 / 97632461750`: accepted 316/316 PASS, C1–C6 0/6, 322 fresh processes, zero orchestration errors, acceptance **1/3 consumed**, diagnostics **1/2**. Result/log/control artifacts: `9543166006` (`53686b44…d2b9`), `9543166360` (`ad7f15c2…51dc`), `9543166725` (`356b40bb…c479`). C1/C3/C6 stop at torus `RegionCutComponentCountDeficit`, C2 at mechanical `IncompleteCycleBasis`; C4/C5 show no terminal `TraceIntersection` and only one terminal event kind. Accepted predecessor behavior did not regress; stable totals stay **42 / 14 / 28**, debt **5**, packages **36**. Exact next: review-only `M3-CP4c-TB-R1-INDEPENDENT-REVIEW`; no retry/reserve diagnostic authorized.

## 2026-08-24 — M3-CP4c-CB2

CB2 W7–W9 completed Code + Build at semantic source `a5edb1a31c315d51df216f3bb51470989ff64e33`. Two committed production-entry witnesses now read `globalTopologyPlan` and self-assert the frozen DEFN §8.2 capabilities; exact C1–C6 extend accepted 316 byte-identically to cumulative 322 (selector SHA-256 `981511637bfe17b4ed1f359305e285f618f14c006b9d78a76a83c0795eb899cd`). Changed-owner `directional_surface_cell_producer_tests` and the authoritative six-executable/two-library package are BUILD GREEN on run `32785147649`; immutable package `9541369624` (`bb636eac863475ce41c336713ce7344c11d4a4ed6cd85a6b04634d083a03a778`), source archive `03e7c09d45715de96f1c58ec6cf21b32ca1b542078cfe196ea359c98dea8de66`, manifest 27/27 PASS. No generated Directional runtime executed; CP4c acceptance remains 0/3, diagnostics 1/2, M3 packages 36. Exact next: artifact-only `M3-CP4c-TB`, 322/322, acceptance attempt 1/3.



## 2026-08-24 — M3-CP4c-DG1-DG-EXEC

Artifact-only DG1 completed GREEN on authoritative run/job `32776212123 / 97587757347`: frozen predecessor 304/304 plus CP4ab 12/12, combined 316/316, zero orchestration errors, diagnostic 1/2 consumed, acceptance 0/3 unchanged. Result artifact `9538137947` (`e5ed2cea…26a7`), execution log `9538138294` (`626c6b70…691e`), control log `9538138652` (`e4655e09…9908`). Earlier run `32775399340` is non-authoritative process evidence caused by fixture-source materialization outside the compiled absolute workspace; runner-only correction was schema-validated by `32776159932` and changed no semantic/package/test/fixture/selector bytes. Exact next: independent `M3-CP4c-DG1-DG-REV`.
