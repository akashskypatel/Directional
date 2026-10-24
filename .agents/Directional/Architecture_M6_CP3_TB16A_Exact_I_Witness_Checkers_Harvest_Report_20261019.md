# M6 CP3 TB16A — exact-I endpoint witness checker harvest (2026-10-19)

**Authority:** RA-100.3. **Run:** https://github.com/akashskypatel/Directional/actions/runs/39277232731; result artifact `12198063461`, ZIP SHA-256 `7f8769edbddc8439662526ca9520919ad78888b31a12abdd9548d476edd06cba`.
**Package:** immutable CB16A artifact `12193816372`, semantic source `7cfa5b4612ed67ec0bbddb747edbc6c53076b781`. **Harness SHA-256:** `20b2ebd80f96e7d4bab6cb727b4f55cfa74f6c7006bf8c1e25e35a289f9aafea`.
**Harness diff:** compared with TB16 `f8db713ee6a98445cc26f29ce8dfc248cca88de1b927ceabf1892ed0aa43769b`, only lines 7–9 (`sha`, `artifact`, `digest`) and the two `TB16_` output labels changed. The 12 identities and four pinned selector hashes were unchanged.

All **12/12** exact-filter processes selected/executed once: **7 PASS / 5 expected diagnostic RED / 0 missing**.

| Identity ordinals | Verdict | Comparison with TB16 |
|---|---|---|
| 1–2 | PASS | Same verdicts |
| 3 | PASS | Corrected from RED under RA-99/RA-100 |
| 4–7 | PASS | Same verdicts |
| 8–9 | RED | `first_failure` byte-identical to TB16 |
| 10–12 | RED | `first_failure` byte-identical to TB16 |

Baseline TB16 result artifact `12183498229`, ZIP SHA-256 `8a329317a610a014cb834947d841fac788ffa55813519dc5259c342a3b62dc32`; its 16/16 result manifest and TB16A's 16/16 result manifest verified.
TB16A postflight: `package=true source=true execution_view=true frozen_selectors=true`; `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`, exit 0. Workflow success certifies execution, **not** that all diagnostics are green.

**Disposition:** All RA-100.3 predictions held. No demonstrated new stable regression; retain 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB14A 425/497 census. RP-01 open, RP-02 UNREACHED, Gate C suspended.
**Conditional next turn after durable closeout:** `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS` (RA-100.4); do not begin it within this turn.
