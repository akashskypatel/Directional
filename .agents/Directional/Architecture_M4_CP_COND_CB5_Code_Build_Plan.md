# M4-CP-COND-CB5 — Code + Build Plan

**Turn:** `M4-CP-COND-CB5`
**Type:** Code + Build / test-authority + selector-publication / runtime-free
**Accepted predecessor:** package `10327643907`, selector422 **422/422**, SHA-256 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`
**Checkpoint:** `M4-CP-COND` OPEN
**Successor on compile/package GREEN:** `M4-CP-COND-TB5-EXEC`

## Objective

Discharge the sole remaining CP-COND exit defect: independently prove a real boundary-truncated separatrix raw precondition before production execution, prove the conditioner preserves the authority on which that derivation depends, append exactly one gating identity to accepted selector422, and package the full owner closure without runtime.

## Authorized semantic scope

Authorized:

- `tests/InputConditionerTests.cpp`: one independent boundary-truncation raw oracle/witness and its mutation falsifier;
- minimal CMake packaged-test ownership metadata required by the new exact test identity;
- one new selector423 extending selector422 by exactly one row;
- selector manifest, TB5 artifact-only test plan, Code + Build report and routine handoff/TODO/changelog updates.

Not authorized:

- any `src/` or `include/` production semantic change;
- any external fixture file or benchmark change;
- any accepted selector422 row change/reorder/removal;
- A0-A4 authority semantics, fallback, tolerance/proximity or second-writer behavior;
- CP-SCALE, CP4, M5+ work;
- Directional runtime during CB5.

## Required test-authority construction

The gating identity is frozen as:

`InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`

Before invoking `condition_surface_cell_input`, a test-local oracle must read the raw mesh/field subject and independently establish:

1. a specific genuine source-boundary carrier;
2. a valid raw singularity/separatrix branch from the raw field/topology;
3. an exact/discrete route showing that branch is truncated by that boundary carrier;
4. the exact raw geometry/field/topology values on which the proof depends.

The oracle must not obtain its answer from the conditioner, A0/A1/A2a production products, production trace functions, or a pre-authored expected boolean/index detached from the raw bytes.

At least one load-bearing raw mutation must cause the oracle to reject or derive a different route/locus.

Then the test runs the frozen conditioner policy and requires `Produced`. It must prove the certificate/correspondence preserves the source boundary and raw field authority required by the oracle, reconstruct a raw view from the conditioned product, and re-run the same independent oracle with the same proved boundary-truncation result.

The current report-only `BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` placeholder is retired/replaced by this proved gate; it must not remain an unresolved closure claim after the new identity exists.

## Selector423

Publish one new selector file whose rows1-422 are byte-identical to `Architecture_M4_CP_COND_CB4_Required_Green_Selector_422.txt` and whose row423 is the new identity above.

Required static facts:

- count: 423 LF rows;
- first422 SHA-256: `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- row423 unique and owner-resolved exactly once;
- owner census: **30 authority-kernel / 277 producer / 75 completion / 41 validation = 423**.

## Compile/package gate

Use GitHub Actions only. Build/package the unchanged seven-target CP-COND owner closure with GMP/GMPXX and `runtimeExecution=false`. Package must include the selector423 bytes, source status receipts, executable/file mode census and checksum manifest. No Directional test process may execute during CB5.

The CB turn must author the complete artifact-only TB5 plan before closeout. TB5 must consume the immutable CB5 artifact without rebuild/repair and run selector423 as 423 fresh exact-filter processes in file order, with exact pre/postflight and mandatory `M4-CP-COND-TB5-REV`.

## STOP rules

STOP before semantic mutation/build if:

- the oracle depends on production trace/atlas/conditioner output to discover the expected boundary event;
- exact/discrete raw authority cannot prove the precondition;
- a claimed load-bearing mutation does not falsify the oracle;
- production source must change;
- conditioned correspondence cannot preserve the proved raw authority;
- selector422 cannot be retained byte-for-byte as the first422 rows;
- any unrelated accepted selector/test/fixture semantic must change.

## Verification checklist

1. Independent oracle proves the raw precondition before conditioner call.
2. Mutation falsifier proves the oracle reads load-bearing raw data.
3. Conditioner Produces under frozen policy.
4. Conditioned raw view re-proves the identical independent boundary route/locus.
5. Existing fourteen CP-COND gates remain untouched.
6. Selector423 exact prefix/count/owner census verified.
7. Full seven-target GMP/GMPXX package GREEN, `runtimeExecution=false`.
8. TB5 plan frozen.
9. No product/fixture/benchmark semantic drift.
10. Work-preservation patch emitted before risky orchestration and normal cleanup policy followed.

## Amendment — the boundary oracle must be pre-production independent (TB4-REV addendum §V4, reviewing agent)

TB4 Review established that production-observing identities are sufficient to **reject** genuine unreachability but
do **not** satisfy frozen §10's pre-production independent construction requirement. The new boundary oracle
therefore may not establish its precondition by observing production output.

Follow the negative-index repair accepted at TB3 as the template: construct the raw source-boundary/field
configuration directly, compute the precondition from the **raw bytes** by the test's own exact method, assert it
**before** the conditioner runs, and make it falsifiable by a raw mutation.

**Falsifier, before compile acceptance:** perturbing the raw input must change the oracle's computed precondition or
break the comparison. An identity that still passes when its raw input is perturbed has not established a raw
precondition, whatever its name says.

