# CB24 — Seam frame values Code + Build record (2026-10-21)

- **Turn:** `M6-CP3-CB24-RP01-SEAM-FRAME-VALUES-SITE`; authority RA-124.5.
- **Exact snapshot/base:** `70ac40253c1c93f4cbed3af1cca18661358ce277`; snapshot run [39665576623](https://github.com/akashskypatel/Directional/actions/runs/39665576623), archive SHA-256 `fc97cb1b692de66e25ffcfd6d92038b79702718ef965c2fa48d088218e80808b`.
- **Applied semantic source:** `dae267a82fb884ff9eba4fd0122ad61750d0c924`; [patch application run 39666734367](https://github.com/akashskypatel/Directional/actions/runs/39666734367) GREEN, `runtimeExecution=false`.
- **Diff:** `src/pipeline/RemeshPipeline.cpp` +28 at lines 5411–5438; `tests/SurfaceCellTransitionQuotientTests.cpp` +1/−6 at 2757–2759. No other source files changed.
- **Behavior:** append rejection-only `branch`, `gaugeSel`, `gaugeSpan`, and `turnN` values; propagate the full existing A5 rejection formatter in the D3 fixture helper. No admission, return, error-code or assertion changes.
- **Patch SHA-256:** `938da3d7a01b94d8717fc600bdc4f567af4b4f5829fdefbe12be27fc46d82dfb`; embedded diff-body SHA-256 `0621deb837f6fbd1ca9ce770d38b4311a851d40be61268c310714e5de3051c74`. Locally verified clean-base apply and whitespace.
- **Compile dispatcher:** corrected request commit `f3242d56523bfb00630e20dddee447840bf4a32b`; mailbox `m6-cp3-cb24-seam-frame-values-compile-b`; exact source as above; eight required targets, durable GMP/GMPXX reusable, compile only.
- **Compile/result package:** **PENDING — no GREEN, package, ZIP/hash, or expiry claim until immutable build evidence is retrieved**.
- **Test/benchmark execution:** none; no runtime acceptance claimed.
- **Transport:** applied Drive file `1mmRHWmvcJxuyG4uGUHAlAvS5hL0i0ZN0` reported `drive_file_retirement_required=true`; initial unconsumed invalid-metadata staging file `1rY6BvW8d2wOYG6m4ioISxLx97QNmbg3A` also requires owner cleanup.
- **Boundary:** preserve CB24 `IN_PROGRESS` until compile/package verification; do not enter CB24-REV or TB25 inside this turn.
