# M4-CP4-DEFN-R1 — produced periodic-authority reconciliation plan

**Turn type:** runtime-free Definition / Review + Plan
**Authorized by:** `M4-CP4-TB1-R3-REV`
**Why this turn exists:** the row408-aligned production torus reaches `Produced` but publishes zero explicit periodic relations, while frozen CP4 §§3.2-3.3 require same-production authority with produced typed periodic ownership. Current product code intentionally refuses a second distinct same-sheet periodic relation without a topology-basis solver. Definition ownership must be reconciled before implementation.

## 1. Fixed entering authority

- Accepted M4 runtime authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**.
- Candidate `10578784752` is unpromoted. Its R3 run/job `35427068822 / 105854843699` is trustworthy evidence only: focus **2 PASS / 4 RED**, selector427 **427/427 PASS**.
- Stable accounting is **49 / 14 / 35**; produced-witness debt is **5**.
- Three `G4-B002` debts remain open at entry. Two `G4-B003` debts remain M5-owned.
- Selector427 is byte-frozen at SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

## 2. Definition question to resolve

Freeze exactly one coherent ownership model for the two CP4 periodic `G4-B002` debts:

### Reading A — bounded M4 same-sheet basis/owner authority

Keep both debts in M4 only if a **bounded, canonical, independently defined** two-generator periodic basis/owner representation can be frozen without importing the broader M5 certificate/path machinery.

Such a definition must specify:

1. the canonical domain from which the two same-sheet generators are derived;
2. typed stable identity independent of vector position, discovery order, face order and container order;
3. how produced periodic edges bind to those identities;
4. how reorder and missing-owner discriminators remain non-vacuous;
5. why this is an M4 conformity/production requirement rather than M5 certificate-carrying quotient work;
6. how row408's 18 hard-feature edges provide only production reachability/preconditioning and do not self-authorize periodic relation multiplicity.

### Reading B — explicit M5 ownership

If same-sheet basis identity cannot be defined without the topology-basis/certificate machinery already owned by M5, re-home the two periodic produced-witness debts explicitly to M5.

That requires coordinated normative amendments, not a silent scheduling change:

1. amend CP4's exit theorem and §§3.2-3.3 ownership language;
2. amend M4/M5 roadmap ownership and TODO/handoff state;
3. preserve the two debts in total debt accounting — **no debt is deleted or marked satisfied**;
4. state what M4 evidence remains required before M4 can close without those two M5-owned relations;
5. preserve the accepted row408 production fact and all existing direct periodic negative behavior as historical evidence, not CP4 produced-witness credit.

## 3. Prohibited shortcuts

The definition must reject all of these:

- treating a `HardRailMerge` / `sharedBoundaryInterval` as a `PeriodicRelationId` merely because both connect boundaries;
- deriving two relation owners from the two hand-authored hard-rail cycles;
- allocating same-sheet basis identity from discovery, vector or map iteration order;
- substituting `direct_periodic_owner_product()`, a draft product, fallback, source-grid recovery or synthetic authority;
- weakening `>=2` to `>=1` while still claiming the current periodic debt contract is satisfied;
- deleting or marking either debt satisfied because current product publishes zero relations;
- pulling general M5 certificate/quotient implementation into M4 without proving a narrow semantic boundary;
- changing selector427 or any product/test/fixture/build source in this definition turn.

## 4. Related non-periodic findings to freeze, not implement

### 4.1 Closed-complex row2

Frozen §3.1 remains unchanged in substance. The current generic torus helper stops at `NotProductionReady/tracing`; that is a test-witness reachability gap, not a proved product defect. DEFN-R1 may clarify that §3.1 does not forbid the already accepted row408 hard-rail precondition if it is needed to obtain a retained candidate-bearing arrangement, provided fallback/recovery remain disabled and the candidate oracle/tamper stay independent.

The actual test edit is deferred to the later Code + Build turn.

### 4.2 Zero-transport row6

Record the source-proved validation ordering: the current genuinely non-flat zero-effort witness is non-integral and correctly returns `NonIntegralCycleLift` before `CycleTransportMismatch` is reachable. The later Code + Build turn should change the focused typed expectation to `NonIntegralCycleLift`; it must not weaken to a generic rejection. No field-atlas product change is authorized by this definition turn.

## 5. Deliverables

DEFN-R1 is complete only when it publishes:

1. one explicit Reading A or Reading B decision with rationale from current architecture/source authority;
2. amended `Architecture_M4_CP4_Frozen_Definitions.md` and any directly affected M4/M5 normative ownership records;
3. an exact disposition for all three `G4-B002` debts after the ownership decision, with total debt accounting preserved;
4. a bounded successor Code + Build plan for the remaining actionable test/product surface, with falsifiers written before implementation;
5. updated tracker, ORIENTATION, TODO, handoff, ROADMAP, changelogs and consolidated history;
6. complete Review/DEFN closeout under `REVIEW_TURN_POLICY.md` and `CLEAN_UP_POLICY.md`.

## 6. Stop rules / falsifiers

Stop without authorizing Code + Build if any of the following is true:

- the proposed same-sheet identity depends on discovery/container order;
- HardRail authority is being relabeled as periodic authority without a semantic equivalence proof;
- the definition cannot explain why a proposed bounded M4 basis is distinct from M5's certificate-carrying quotient relation scope;
- Reading B would make M4 closure ambiguous because the remaining M4 exit theorem is not explicitly rewritten;
- any proposed change would silently reduce debt count below 5 without reviewed runtime evidence;
- the turn would need product/test/fixture/selector/build mutation, compilation or generated runtime to decide the definition.

If one of these fires, remain in definition/review authority and surface the unresolved architectural choice; do not manufacture an implementation plan.

## 7. Boundary

This turn is documentation/definition only. It executes **no** generated Directional binary, test, benchmark, discovery/list/help/version command, configure, compile or relink. It changes **no** product, test, fixture, selector, benchmark or build source.
