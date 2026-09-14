# M4-CP-SCALE-DEFN — Definition / Review + Plan

**Turn:** `M4-CP-SCALE-DEFN`
**Type:** DEFN / review + plan only / runtime-free
**Predecessor:** `M4-CP-COND-TB5-REV` — CP-COND CLOSED / ACCEPTED
**Accepted entering M4 runtime authority:** package `10331193451` / selector423 **423/423**
**Product/test/fixture/selector/build/runtime mutation:** prohibited

## 1. Purpose

Freeze the checkpoint-local S1-S5 scale/boundedness contract before implementation. `Architecture_M4_DEFN_Frozen_Definitions.md`
and `ROADMAP.md` already assign the semantic domain to CP-SCALE, but they intentionally do not guess the concrete
production predicate surfaces, thresholds, witness reachability, or selector membership. This DEFN must resolve those
questions from source/evidence rather than letting a CB invent them.

## 2. Required source/evidence inventory

Re-open the current production source and retained primary evidence and, for every proposed witness, record the deepest
stage it is **proved** to reach. File presence or a test name is not reachability evidence.

Inventory at minimum:

1. every exact predicate whose cost/bit width is relevant to S1;
2. every current floating/certified-filter candidate seam that could own S2, including its exact fallback;
3. the current state/history representation and any real nontermination/limit-cycle evidence relevant to S3;
4. the exact disc/Betti authority and earliest safe monotone rejection seam relevant to S4;
5. all retained genus-1 and any genus>=2 fixtures, with primary evidence for the deepest stage each reaches.

Do not execute Directional runtime in DEFN. If reachability cannot be established from retained evidence, record it as a
precondition/blocker for the later owning TB instead of fabricating gate credit.

## 3. Definitions to freeze

### S1 — expression-swell measurement

Freeze one deterministic measurement schema over exact arithmetic work/bit widths. Initial S1 measurements are
**diagnostic / non-gating**. Do not freeze an acceptance threshold from the current <=152-vertex/300-face witness set.
Measurement must not alter execution decisions or exact results.

### S2 — certified-filter equivalence

Freeze the exact predicate surfaces eligible for filtering and the certificate/fallback rule. A filter is only an
accelerator: it may return a decision only when its certificate proves the same exact sign/classification; otherwise the
existing exact predicate remains semantic authority. Gating identities must compare filtered and exact decisions on
independently constructed positive/negative/near-boundary subjects and include a discriminating tamper/counterexample.

### S3 — typed exact limit-cycle termination

Freeze the exact semantic state key whose repetition constitutes a cycle, the typed `LimitCycleTermination` outcome,
and the point in the producer where it may be emitted. Elapsed time, iteration budget, wall-clock timeout, floating
state proximity, or container address may not define a semantic cycle. Existing historical nontermination evidence may
motivate the witness but cannot substitute for a constructed/reachable precondition.

### S4 — incremental Betti early rejection

Freeze an incremental topological invariant that can reject **earlier, never differently** than the existing exact disc
proof. It may not rewrite A2a' cuts, backtrack into a producer, or become a second topology authority. Define an
independent oracle and exact reachability precondition before any gating identity is admitted.

### S5 — genus>=2 coverage

Genus-1 torus evidence is insufficient. Freeze the required genus>=2 fixture properties and required reached stage. If
no current retained witness is proved to reach A3, S5 remains an explicit blocker/non-selector until construction and
reachability are independently established; guaranteed-red or guaranteed-green credit is forbidden.

## 4. Selector/gate contract to freeze

Start from accepted selector423 byte-for-byte. DEFN must publish a per-identity table before any code turn stating:

- intended identity and owner binary;
- exact independent precondition;
- deepest currently proved witness stage;
- gating versus non-gating diagnostic status;
- decisive falsifier;
- whether source/test/product changes are required.

S1 uncalibrated measurements contribute zero gate credit. S2-S5 identities become gating only when their frozen
preconditions are independently established, per M4 §12 selector policy.

## 5. Required DEFN outputs

1. one checkpoint-local frozen definitions document for CP-SCALE;
2. one source/evidence reachability inventory with primary evidence references;
3. one gate/diagnostic membership table and append-only selector lineage plan from selector423;
4. one bounded first Code + Build plan with exact changed surfaces and STOP rules;
5. ORIENTATION/ROADMAP/TODO/handoff updates to the one exact successor.

No runtime acceptance, compile/package evidence, or selector promotion occurs in DEFN.

## 6. STOP / falsifiers

STOP and keep CP-SCALE in definition/review if any proposed design requires:

- a guessed numeric threshold from the small current witness set;
- a filtered/approximate predicate to become semantic authority when exact fallback disagrees or is unavailable;
- timeout/iteration count/floating proximity as S3 cycle semantics;
- S4 to modify A2a' cuts, backtrack, or weaken the exact disc theorem;
- genus1 substituted for genus>=2;
- gate credit for a witness whose precondition/reachability is not independently proved;
- any change to accepted CP-COND, CP3 A3/A4, selector423 prefix, M5/M6/M7 semantics, or CP4 debt ownership.

## 7. Expected successor

If and only if DEFN freezes all required authority boundaries and a bounded first implementation slice, issue exactly one
`M4-CP-SCALE-CB1` Code + Build plan. Otherwise issue the smallest definition/review amendment; do not enter Code + Build
by assumption.
