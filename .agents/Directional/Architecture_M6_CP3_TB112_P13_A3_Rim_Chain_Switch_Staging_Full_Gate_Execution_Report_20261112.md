# TB112 full-gate execution — scoped MATCH (2026-11-12 UTC)

**Canonical turn:** `M6-CP3-TB112-P13-A3-RIM-CHAIN-SWITCH-STAGING-FULL-GATE-EXEC` (64E.2, Test + Benchmark). **Authority:** RA-230 §5. **Disposition:** MATCH; the switch stays off by default pending a separate Review-only turn `M6-CP3-DEFN-P13-A3-SWITCH-ACTIVATION`.

## Exact immutable evidence

- Compiled semantic source: `240d2a1948c95521e9b90740244e7dd7de46483a`. Immutable CB131 package artifact `13931894182`, outer ZIP SHA-256 `cf7b19cb429f0983eb4b90ed5c37c75ccc0bf1402586812f4b1acbc79eeaf1c6`; 28/28 package checksums, source archive and exact GMP/GMPXX compile evidence verified. Package not modified.
- Executor snapshot at `58ac965a5fc1368bdc160ab0a06e4847e0566376`, run `43199197006`, artifact `13933998165` outer ZIP `0797c8eb8d6317e9948a8adde20cb02c34d541476b7e125d341c88ce37ebc38f`, 5,509 source checksums.
- Test request commit `33c785bf5ce1c8a8af92e43b865c4b061b89d0b5`, mailbox `m6-cp3-tb112-rim-switch-full-gate-20261112-v1`, [execution run 43199861547](https://github.com/akashskypatel/Directional/actions/runs/43199861547); runtime job `131120280669` SUCCESS; compile/Drive/noop jobs skipped, mailbox SUCCESS.
- [Immutable result artifact `13935551687`](https://github.com/akashskypatel/Directional/actions/runs/43199861547/artifacts/13935551687), outer ZIP SHA-256 `1b0178823ac5a9c0fd45589090f04b0d8f794c22301761cb00a5e1bed11b8888`; 1,898/1,898 internal SHA256SUMS verified. [Diagnostic artifact `13934708746`](https://github.com/akashskypatel/Directional/actions/runs/43199861547/artifacts/13934708746), outer ZIP SHA-256 `9dcfc88019d8e3ad61f9ddb593fa48817cebe047fa701c5923f826c133c97980`.
- Frozen manifest SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, 945 cases, membership 1,026, deferred 81. Source/package/executor/harness authority was frozen before execution.

## Gate and independent comparison

- `execution-boundary.json`: planned/executed/passed **945/945/945**; red/abnormal/missing/skipped/duplicate/control_bad/unexpected_pass/later_positive_red/red_site_bad **all zero**; membership **1,026**, postflight **true**, exit **0**.
- The exact artifact-only boundary records `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. Exactly one process per selected case (`run=1`), no skipped cases; no build, fixture repair, source/test/selector mutation, or backend default change.
- Accepted TB110 artifact `13926276289`: 944/944 PASS, 1,896/1,896 hashes, membership 1,025. TB112's rows 1–944 have the same substantive ledger fields, and all inherited receipt lines are byte-identical, including `annulus-read`, `annulus-pair`, `annulus-rim`, `d4-rim`, `rim-branch`, platform digests, and `a3-coverage`. A deterministic local independent comparator found zero differences across those logged lines.
- All ten `switch-run` lines are present: two per Plane, MultiFaceSeam, CloseSheets, Cylinder, and SmoothRimDisc. The four existing per-arc census runs each have `produced=1` and A3 tuples equal to existing `a3-coverage`: Plane 14/0/0/14/0; MultiFaceSeam 16/0/0/16/0; CloseSheets 24/0/0/24/0; Cylinder 81/32/0/49/0. The disc's per-arc line is diagnostic only under RA-230 §5.

## Ten exact switch receipts

```text
switch-run case=Plane schedule=perArc produced=1 faces=64 failure=None/ phaseFront=Produced invalid=/ a3=14/0/0/14/0
switch-run case=Plane schedule=chained produced=1 faces=100 failure=None/ phaseFront=Produced invalid=/ a3=4/4/0/0/0
switch-run case=MultiFaceSeam schedule=perArc produced=1 faces=64 failure=None/ phaseFront=Produced invalid=/ a3=16/0/0/16/0
switch-run case=MultiFaceSeam schedule=chained produced=0 faces=0 failure=NotProductionReady/completion phaseFront=Produced invalid=completion/output-validation/AggregateCompletionValidationFailure a3=4/4/0/0/0
switch-run case=CloseSheets schedule=perArc produced=1 faces=200 failure=None/ phaseFront=Produced invalid=/ a3=24/0/0/24/0
switch-run case=CloseSheets schedule=chained produced=1 faces=242 failure=None/ phaseFront=Produced invalid=/ a3=8/8/0/0/0
switch-run case=Cylinder schedule=perArc produced=1 faces=288 failure=None/ phaseFront=Produced invalid=/ a3=81/32/0/49/0
switch-run case=Cylinder schedule=chained produced=1 faces=288 failure=None/ phaseFront=Produced invalid=/ a3=81/32/0/49/0
switch-run case=SmoothRimDisc schedule=perArc produced=0 faces=0 failure=NotProductionReady/completion phaseFront=Produced invalid=completion/output-validation/AggregateCompletionValidationFailure a3=32/32/0/0/0
switch-run case=SmoothRimDisc schedule=chained produced=0 faces=0 failure=NotProductionReady/completion phaseFront=Produced invalid=completion/output-validation/AggregateCompletionValidationFailure a3=4/4/0/0/0
```

## Interpretation and regression classification

**Scoped MATCH** meets RA-230 §5. The chained schedule is *not* an acceptance condition in TB112. The chained `MultiFaceSeam` run has `produced=0`, `failure=NotProductionReady/completion`, `invalid=completion/output-validation/AggregateCompletionValidationFailure` (row 933); chained `SmoothRimDisc` has the same completion-stage result (row 945). The disc's per-arc output also fails at completion (diagnostic-only). The other three chained census cases produce output (Plane 100 faces; CloseSheets 242; Cylinder 288). These are observational receipts, not production acceptance of the chained option or proof of cause.

No gate case is RED. No accepted default-path regression or stable regression event is justified. Record the two chained completion failures as **non-stable candidate evidence** for the Review, without changing 66 stable events, 17 categories, 49 recurrences, debt 1, or deferred 81. Do not infer an A4 root cause without independent Review. The activated path requires Review ownership and explicit decision; keep `chainRimSchedules=false`, CP3/selector497 unpromoted, prior accepted CP2 491/491.

**Authorized successor, separate turn:** `{nextturn}` (Review only; RA-230 §6). Do not start that turn during TB112.
