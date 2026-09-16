# Turn Cadence — DURABLE, DO NOT DELETE

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
