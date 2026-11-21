# Turn Cadence — DURABLE, DO NOT DELETE

> This file requires EXPLICIT USER AUTHORIZATION to modify or delete. Any modifications or deletions must be reverted during documentation drift audit unless explicitly approved by the user.

**Authorized by the user on 2026-08-25 and binding for all future work.**

```
CB  →  TB  →  green?  →  checkpoint CLOSES
                ↓ semantic red
        REVIEW + PLAN  →  CB  →  …
                ↓ orchestration failure
        CB (orchestration fix)  →  TB (re-execute)  →  …
```

1. **`CB`** — Code + Build. Authors semantics, compiles, packages. Executes no Directional runtime.
2. **`TB`** — artifact-only Test + Benchmark on the immutable package. Executes **the full current
   gate**, one identity per fresh process, with every mutation flag false.
3. **A green TB closes the checkpoint.** There is no separate acceptance ceremony.
4. **A red TB mandatorily routes to `REVIEW + PLAN`.** No retry, no patch, and no further CB without
   an intervening review.
5. **Orchestration failure routes to `CB`, not to `REVIEW + PLAN` — user-authorized 2026-09-04.** An
   orchestration failure is **not** a `RED` turn failure and produces **no semantic ledger**: nothing about the
   product was measured, so there is nothing for a review to adjudicate. It routes directly to a **`CB`
   orchestration-correction turn** that fixes the harness, control plane, or execution contract, followed by a
   `TB` that re-executes the failed turn.
   - The orchestration-correction `CB` is **control-plane-only where possible** and then **reuses the existing
     immutable package unchanged**, so the re-executed `TB` remains comparable to the frozen plan it consumes. It
     compiles and repackages only when the fix genuinely requires a source change, and it says which case applies.
   - It must **preserve the failed attempt's evidence** as invalid-attempt provenance, and may **not** promote any
     of its process results to semantic authority.
   - Rule 4 is unchanged and independent: a **semantic** red still routes to `REVIEW + PLAN`, with no retry, patch
     or further `CB` without an intervening review. Only orchestration failures take this edge.
   - The latest authoritative semantic runtime is unchanged by an orchestration failure and remains whatever the
     last valid `TB` established.
6. **A red TB is information, not a debit.** Nothing is consumed, nothing is reset.

**Non-gating diagnostic identities**: A checkpoint may declare
identities that TB executes and reports but that are **excluded from the gate count**, each with a
written rationale and an owning corrective measure. A non-gating identity may never be promoted to
gating without a review recording why its precondition is now independently established.

**`DEFN` absorbs `REVIEW + PLAN` — user-authorized 2026-08-30.** When `DEFN` is the next step in the
chain, it **is** the review-and-plan turn for its checkpoint: one turn freezes definitions, adjudicates
the inherited candidates, decides gate membership per identity, and issues the successor's measures. A
separate `REVIEW + PLAN` turn is no longer scheduled ahead of a `DEFN`. This collapses only the
`REVIEW+PLAN → DEFN` edge; every other edge above is unchanged, and a red TB that routes to
`REVIEW + PLAN` without a `DEFN` still gets its own review turn. First applied at
`M3-CP4c-3-DEFN`.

**Same-agent REVIEW/DEFN is allowed — user-authorized 2026-09-10.** The same agent/session may perform a REVIEW, REVIEW + PLAN, or DEFN turn even when it authored or executed an earlier turn in the same chain. "Independent" in review/oracle/verification language means independent **evidence, re-derivation, authority, or implementation path**, not required personnel separation, unless a specific criterion explicitly says otherwise. A same-agent REVIEW must re-open primary evidence and re-derive decisive facts; a same-agent DEFN remains planning/runtime-free. All cadence, stop, validation-integrity, source-authority, compile/runtime, and acceptance boundaries remain unchanged.

**Turn ID format — user-authorized 2026-11-21.** For every turn type that carries a sequence number (`CB`, `TB`, `DEFN`, `PLAN`, and the TB execution and Review turns), the turn type token and the sequence number are delimited by `-`; a revision letter stays attached to the number. The type token for a Test + Benchmark execution turn is `TB-EXEC` and for a TB Review turn is `TB-REV`: nothing is ever placed between `TB` and `EXEC`/`REV`. The order is type token, sequence number (with revision), then every additional identifier; additional identifiers always come AFTER the type token and number, never between `TB` and `EXEC`. The milestone/checkpoint prefix still leads. `RA-` turns already comply.

- `CB216R` is wrong; `CB-216R` is correct. `TB123R` is wrong; `TB-123R` is correct. The same applies to `DEFN` and `PLAN` turns.
- `TB123R-EXEC` is wrong; `TB-EXEC-123R` is correct. `TB123R-FULL-GATE-EXEC` is wrong; `TB-EXEC-123R-FULL-GATE` is correct. The same applies to `TB-REV` (`TB-REV-123R-FULL-GATE`).
- Full form: `M6-CP3-TB154-P13-TRACE-PIECE-RAY-HELPERS-FULL-GATE-EXEC` is wrong; `M6-CP3-TB-EXEC-154-P13-TRACE-PIECE-RAY-HELPERS-FULL-GATE` is correct. `M6-CP3-CB-169-P13-TRACE-PIECE-RAY-HELPERS` is correct.

The rule governs turns named from 2026-11-21 forward; completed turns, filenames and historical records keep the names they were issued under.
