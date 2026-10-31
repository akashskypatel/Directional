# Directional — Surface-Cell Development Roadmap

>This rewrite was expressly requested on 2026-10-16.

**Updated:** 2026-10-26 · **Track:** experimental direct surface-cell quadrangulation (Pipeline B) · **Target:** certified, production-ready output.

This roadmap answers **what is done, what comes next, and what each milestone delivers**. It is not a turn log, task queue, test ledger, definition spec, or implementation handoff. The product and acceptance contract is [DESIGN.md](DESIGN.md) (especially §§2 and 14); status, detailed plans, unresolved findings, and exact next-turn authorization live in [ORIENTATION.md](ORIENTATION.md), [Future_Chat_Session_Handoff.md](Future_Chat_Session_Handoff.md), [TODO.md](../../TODO.md), and [Regression_Root_Cause_Tracker.md](Regression_Root_Cause_Tracker.md).

## At a glance

**Completed:** M0–M5 · **Now:** M6 / CP3 (direct-production proof) · **Next:** M7 (verified disposition and degradation) · **Later:** M8 (production hardening).

| Milestone | Outcome | Status | Accepted milestone evidence |
|---|---|---|---|
| **M0 — Evidence baseline** | Preserve regression fixtures, reference behavior, and independent comparison artifacts. | **Complete** | Historical T1/M0 prerequisite |
| **M1 — Single semantic authority** | Typed source/chart/transport/region identities; no competing semantic owners. | **Closed** | [Closure](M1_Closure_Record.md) · **234/234** |
| **M2 — Closed stage products** | Immutable single-writer products and exhaustive typed outcomes across stages. | **Closed** | [Closure](M2_Closure_Record.md) · **275/275** |
| **M3 — Field-aligned curve network** | Typed, branch-consistent tracing and certified network-derived topology regions. | **Closed** | [Closure](M3_Closure_Record.md) · accepted prefix **365/365** |
| **M4 — Global conformity** | Exact shared-rail scheduling, certificate/typed infeasibility, producer cutover, conditioning, and scale proofs. | **Closed** | [Closure](M4_Closure_Record.md) · **430/430** |
| **M5 — Chart and quotient certificates** | Canonical periodic-relation identity, selected paths, typed failure handling, and produced quotient evidence. | **Closed** | [Closure](M5_Closure_Record.md) · **449/449** |
| **M6 — Occurrence, embedding, verification** | Separate occurrence/quotient/embedding products; independent verification and direct-production re-proof. | **In progress** | CP1 **479/479**, CP2 **491/491**; CP3 **not accepted** |
| **M7 — Graded disposition** | Verifier-assigned D0–D4 outcomes and explicitly certified, bounded degradation. | **Planned** | Definition and acceptance gates not yet frozen |
| **M8 — Production hardening** | Module isolation, resources, diagnostics, reproducible builds, and representative certified acceptance. | **Planned** | Production-readiness exit not yet met |

**Status interpretation:** “Closed” means the milestone's *frozen* acceptance criteria passed, **not** that the complete product is production-ready. Gate counts are the milestone's accepted evidence, not a universal measure of feature completeness. For M3, the later selector409 audit recorded **405 PASS / 4 RED**; those separately owned REDs did not change its frozen 365-row required-green acceptance.

## Completed checkpoints

Each completed milestone's [closure record](M3_Closure_Record.md) retains detailed evidence, preserved frozen definitions, amendments, and historical checkpoint records. This table records achievements only; it does not revive historical successor instructions.

| Milestone | Checkpoints delivered |
|---|---|
| **M1** | R-A/R-B/R-C: transport, chart/support and product authority; Units 2–3: typed owners, numeric projections and complete contract cutover. |
| **M2** | CP0: ownership census; CP1–CP2: closed feasibility/completion products; CP3–CP4: eliminate cross-stage semantic context reads/writes. |
| **M3** | CP1: A1 field transport; CP2/CP2b: network product and canonical branch/port authority; CP3a/CP3b: tracing and typed events; CP4ab: topology plan and disc certificates; CP4c-0/0b/1/2/3: exact continuation, termination, observability, closed-surface cut graphs and mechanical witness. |
| **M4** | CP1: shared positive schedule; CP2: certificates and typed infeasibility; CP3: production A3 consumption and pairing correction; CP-COND: conditioned-source authority; CP-SCALE: boundedness/scale evidence; CP4: cumulative M4 exit. |
| **M5** | CP1: canonical relation IDs and recorded paths; CP2: five typed failure classes; CP3: produced periodic/nonzero-Z4 re-proofs; CP4: same-region multi-isolation/quotient producer witness and cumulative M5 exit. |

## Now — M6: occurrence, embedding, independent verification

**Goal:** independently verifiable, source-attached pure-quad products with distinct occurrence identity, exact-once quotient-relation consumption, and no position-based welding or verifier-side repair. [Architecture and criteria](DESIGN.md#14-implementation-transition).

| Checkpoint | Deliverable / acceptance focus | Status |
|---|---|---|
| **M6-DEFN** | Freeze A5/A6/A7 products, verifier boundary, and ownership of later direct-production witnesses. | **Complete**; [frozen definitions](Architecture_M6_Frozen_Definitions.md) |
| **M6-CP1** | Product separation: occurrence, quotient, source-attached embedding, and thin adapter without semantic welding. | **Closed, mechanism-only** · [closure](M6_CP1_Closure_Record.md) |
| **M6-CP2** | Independent `SurfaceProductVerifier`: recompute permitted invariants; reject malformed authority without repair. | **Closed** · [closure](M6_CP2_Closure_Record.md) |
| **M6-CP3** | End-to-end direct-production and invariant re-proof, including the remaining closed-complex candidate-extraction witness and discriminating tamper. | **Active / blocked on evidence; not accepted** |

**Current CP3 boundary (2026-10-31):** TB62 Linux ten-target full gate 863/863 and CB63 GMP CLI/GUI linkage are independently audited; 82 tests remain deferred, including Cylinder, Vase, BunnyRandom P13; macOS O16 row 283 separate. P13 runtime-free Review assigned an immutable diagnostic CB→TB successor, not CP3 acceptance. Previously TB52 853/0 was an independently reviewed candidate gate ([RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md)), with 939 packaged tests enumerated (853 GATED / 86 DEFERRED); TB51 831/0 is the prior reviewed candidate. selector497 (497/497) and the G4-B002 exit row passes inside it ([RA-174](Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md)). **RP-01 is closed** ([RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md); local macOS TB53 836/19, with every red attributed to O15 or O2, and 854/855 FMA-free; a Linux confirmation is carried). CP3 exit additionally needs: zero deferred rows; the design-acceptance matrix at 6/6 (Cylinder, Vase and Bunny are open in P13); every packaged test governed (P8, O14); O7 resolved; exact A3 atlas topology decisions (O15, [RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md)).

**Outstanding M6 exit dependency:** The single remaining produced-witness debt, **`G4-B002` closed-complex candidate extraction**, must be proved on real pipeline-produced authority at CP3. `RP-01` is closed (RA-179); O15 is discharged (RA-181); the O2 entry gate has landed (RA-183). Milestone M6 remains open until its specified direct-production and invariant evidence is independently accepted. Detailed fault classification belongs in the regression tracker, not here.

## Next — M7: disposition and graded degradation

**Goal:** Turn verified results into truthful output dispositions without disguising failed strict construction as success. This work **depends on M6** because only the independent verifier can assign an output tier. [Normative contract](DESIGN.md#22-output-disposition-ladder).

| Checkpoint | Planned outcome |
|---|---|
| **M7-DEFN** | Freeze `OutputDisposition`, `DegradationCertificate`, the D0–D4 ladder and verifier layer 7 as a single contract. |
| **M7-CP1** | Verifier-only tier assignment; typed proof of each tier and monotone non-increasing disposition. |
| **M7-CP2** | One bounded, non-recursive degraded-region producer; pure quads conform to the original plan and never mutate upstream products. |
| **M7-CP3** | Complete negative/degradation/omission oracles, quotient-accounting and permutation invariance; re-prove the deferred M1 criterion-5 structural fixtures at **D0 Certified**. A degraded output never closes a strict gate. |

**Exit:** All D0–D4 results are truthful and verifiable; unrecorded/fabricated degradation fails typed; strict paths remain strict. Checkpoint gates and timing are **not yet frozen**.

## Later — M8: module boundaries and production hardening

**Goal:** Convert the accepted semantic backend into a reproducible, bounded, maintainable production implementation.

| Checkpoint | Planned outcome |
|---|---|
| **M8-CP1** | Enforce intended module/API boundaries and prevent forbidden producer–verifier and construction–disposition dependencies. |
| **M8-CP2** | Harden diagnostics, work/memory/bit-width accounting, representative scale/conditioning and exact-authority evidence, packaging, and CI—without changing accepted semantics. |
| **M8-CP3** | **Production-readiness gate:** full representative witness set satisfies all ten [Certified conditions](DESIGN.md#21-certified-acceptance), deterministic and resource-bounded operation, no strict gate closed through degradation, and no open architecture debt in the regression tracker. |

**Exit:** A verified production-level Pipeline B backend. **No release date or milestone acceptance has been committed.**

## Beyond the committed roadmap

**Pipeline A** (decomposed coordinate integration) is a documented **optional, unscheduled alternative**, not a prerequisite for M8. It may be considered only after Pipeline B produces production-level certified results on the full committed representative matrix; see [DESIGN.md §16](DESIGN.md#16-pipeline-a--optional-future-path).

## Keeping this document useful

- **Keep:** milestone purpose, order/dependencies, checkpoint outcomes, completion status, and concise acceptance signals.
- **Update:** status only after an independently accepted checkpoint decision or a substantive change in roadmap direction. Keep the current M6 row and blocker note short.
- **Do not append:** per-turn status headers, implementation commands, raw logs, package IDs, diagnostic tables, regression narratives, acceptance ledger histories, or copies of frozen definitions.
- **Reference instead:** `DESIGN.md` for normative product contracts; milestone closure records for verified history; `ORIENTATION.md` / `Future_Chat_Session_Handoff.md` for live execution routing; `TODO.md` and the regression tracker for actionable details.

The sequence is **M6 CP3 → M7 DEFN/CP1–CP3 → M8 CP1–CP3**. Only M8-CP3 can establish production readiness; earlier milestone closure does not imply it.
