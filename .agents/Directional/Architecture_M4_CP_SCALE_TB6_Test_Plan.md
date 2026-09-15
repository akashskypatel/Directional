# M4-CP-SCALE-TB6 Test + Benchmark Plan — S3 exact-repeat publication

## Scope and turn boundary

`M4-CP-SCALE-TB6-EXEC` is runtime execution only against the immutable GREEN
`M4-CP-SCALE-CB7` compile/package artifact. It must not rebuild, edit source,
modify selectors, or execute unrelated benchmarks. `M4-CP-SCALE-TB6-REV` is a
mandatory independent review of the EXEC evidence before any S3 credit is
accepted.

The focused S3 identity is intentionally **not** appended to a selector in CB7:

`M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`

Accepted selector424 remains the cumulative regression authority and must stay
byte-for-byte unchanged at SHA-256
`f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`.

### Frozen CB7 candidate authority

TB6 must consume **exactly** the CB7 GREEN package produced by compile run/job
`35022869891 / 104562750677`:

- result artifact `10418328122`, provider SHA-256
  `a9f33bce6029022495fccbc4680da9bdd25cf41aa5cc733b2c04335e156ac16e`;
- exact semantic source `153047c3f92e9b9b784e11eaee1ede2de5628470`;
- packaged source archive SHA-256
  `703dcc22f18ed565b623ef4eb43e117cd8acfd5d982ed0bde111d5cfdd56e0ff`;
- root `SHA256SUMS` SHA-256
  `d5e2e620f3e5a9e78f4b646be95f872dd78ab8cbee7fe726156abf8249d6d5ad`,
  verified **28/28**;
- compile metadata `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
  `exactArithmeticBackend=GMP`.

Any different package/source is an authority mismatch and must STOP as BLOCKED;
do not rebuild or substitute a newer branch head inside TB6.

## Immutable preflight

Before executing any generated binary:

1. Verify the package artifact is the exact CB7 GREEN artifact and record its
   provider digest, nested package manifest digest, source SHA, and build run/job.
2. Verify package metadata reports `runtimeExecution=false` for CB7.
3. Verify packaged source status is clean and source SHA equals the promoted CB7
   semantic commit.
4. Verify the packaged selector424 bytes hash to the accepted SHA-256 above and
   contain exactly 424 non-empty identities in the accepted order.
5. Verify the focused S3 identity is owned by
   `directional_surface_cell_producer_tests` from packaged source/CMake and is
   absent from selector424. Do not create or infer selector425.
6. Verify GMP/GMPXX compile evidence is present and exact arithmetic backend is
   GMP as required by project policy.

Any authority mismatch is an orchestration/blocker result, not a semantic RED.

## TB6-EXEC runtime sequence

### A. Focused S3 process

Execute exactly one fresh process with the exact GoogleTest filter:

`M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`

No list/help/version/discovery command is permitted. Record process exit, elapsed
time, selected/executed identity count, stdout/stderr, and the structured success
receipt. Required semantic observations from that receipt and assertions are:

- complete exact `(sourceFace, branch, incomingCarrier, entryPoint)` repetition
  publishes typed `LimitCycleTermination`;
- a different exact entry point with the same face/branch/carrier remains
  `Advanced` and does not publish S3 credit;
- changing each of the four load-bearing state fields independently prevents
  credit until the complete original state repeats;
- position-free/combinatorial recurrence remains the typed error
  `TraceCombinatorialRecurrenceExceeded` and never becomes a semantic terminal;
- the finite step bound remains the typed error `TraceStepBudgetExhausted` and
  never becomes a semantic terminal.

The required success receipt contains:

`m4CpScaleS3;exactRepeat=LimitCycleTermination;differentExactEntry=Advanced;loadBearingTamperCount=4;combinatorialRecurrence=TraceCombinatorialRecurrenceExceeded;stepBudget=TraceStepBudgetExhausted`

Missing receipt, wrong terminal class, wrong backstop class, selection mismatch,
crash, timeout, or nonzero process exit is RED.

### B. Accepted selector424 cumulative gate

Execute all 424 selector identities as **424 fresh exact-filter processes** in
selector order using the packaged target ownership map. Reuse the TB5 execution
shape; do not use GoogleTest discovery. Record one process-ledger row per identity
with expected target, exact filter, exit, elapsed time, and status.

Acceptance requires **424/424 PASS**, zero RED/SKIP/timeout/crash/selection
mismatch/unexecuted, with the selector file still hashing to the accepted digest.
The focused S3 process is reported separately and does not change the selector
count.

### C. Immutable postflight

After all runtime execution:

1. Re-hash package/source/selector bytes and prove no mutation.
2. Re-confirm execution view/source authority equals the preflight authority.
3. Preserve focused S3 stdout/stderr and the full 424-row process ledger.
4. Preserve packaged manifest/checksum evidence and all workflow activity logs.
5. Report runtime process total as 425 only as an execution count
   (`1 focused + 424 selector`), never as selector425.

## EXEC result classification

GREEN requires both:

- focused S3: **1/1 PASS** with all five semantic discriminators proven; and
- accepted cumulative gate: **424/424 PASS** with immutable pre/post authority.

A focused semantic failure or selector regression is RED and routes to mandatory
`M4-CP-SCALE-TB6-REV`. Infrastructure/authority failure is BLOCKED and must not
be converted into semantic evidence.

## Mandatory TB6-REV review

Review must independently reopen artifact bytes and logs rather than trusting the
EXEC narrative. Re-derive:

1. focused test target ownership and exact one-process selection;
2. the structured S3 receipt and all discriminator assertions;
3. selector424 SHA/count/order and all 424 process-ledger rows;
4. source/package/execution-view immutability;
5. absence of selector425 and absence of runtime rebuild;
6. whether the product change is limited to S3 exact-repeat publication, with
   combinatorial recurrence and step budget still fail-closed backstops.

Only Review may promote S3 cumulative credit or choose the next CP-SCALE turn.
