# M6-CP3-CB1-ENTRY-R4 — public strict trace foreign-edge oracle Code + Build receipt

Canonical turn remains `M6-CP3-CB1-ENTRY-R4`; no successor.

## Source and patch authority

- Verified exact source snapshot `45d210e51a12dd3b8416c5179e6737edbb53e4e3`, workflow `38359143085`, artifact `11793278212`, 5612/5612 source checksums.
- Exact 5,601-byte patch SHA-256 `d62ed1a55e33a0dfc7b13b83e76727cafca39bb93cc4bf471424ca2c247d7287`; diff-body `8040253a74afdbf40ec40373bf9df2058a7e6ce5ed09944695a02461c50973ae`.
- Drive staging file `1jugp7GPvp8Lysf5ytmDT-jkK2U8JU94k`; durable dispatcher drive_apply run `38366995891` succeeded, exact applied semantic commit `f5c0d0b325ecf7333abbd3573759ed09a011ea3e`. Patch touched only Phase14 tracing tests, TODO, and handoff (+23 lines). Staging file subsequently deleted by owner-authorized Drive connector.
- Nonvacuous source regression: intact typed source-edge rail accepted by strict public tracing ingress; missing published key first-rejects `FieldMetadata`; present/in-range foreign published key `(1,4)` replacing `(0,4)` independently first-rejects `FieldMetadata`. Source-only assertions; runtime unexecuted.

## Compile evidence

- Initial request run `38367221870` failed before compiling because the dispatcher requires `targets` as a JSON array, not a space-delimited string. No C++ compiler executed in that attempt.
- Corrected compile dispatcher request event `087a36c7bb92ef9c57e9cd4dfd7606657d24db5f`, pinned to source `f5c0d0b325ecf7333abbd3573759ed09a011ea3e`, eight standard GMP/GMPXX targets. Mandatory reusable compile workflow `38367436364` succeeded (compile job `115196008862`), exact immutable result artifact `11796334785` ZIP SHA-256 `1a56a2ee7fee179e9c5c251e5d68560fb3e714364f8b89084b6ec39707b40f19`, diagnostic artifact `11797264021` ZIP SHA-256 `3269fab6890c6422543a12210d81c64e7c058ae61cb5f11a6e692f94428cd297`. Artifact internal manifest **28/28**, all eight requested targets compiled, `preflight-exit-code=0`, `build-exit-code=0`, authoritative generated link command contains `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`, five source-status files clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No compiled Directional binary was executed.

## Remaining authority

This is Code + Build only. No test, benchmark, TB497, or runtime acceptance; frozen 497-selector unchanged. RA-50 discharges RA-43.2 and forbids invented filled-side receipts. RA-43.1/.4 global, RA-46.5, RA-47.12 executed liveness, historical 39/34/7/88/six and odd-τ multi-carrier obligations remain open. Preserve the same canonical turn.
