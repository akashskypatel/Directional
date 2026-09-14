# M4-CP-COND-TB4-EXEC report

**Turn:** `M4-CP-COND-TB4-EXEC`
**Disposition:** **MECHANICALLY GREEN / REVIEW REQUIRED / NO PROMOTION**
**Successor:** `M4-CP-COND-TB4-REV`

## Authority

TB4-EXEC consumed the immutable CB4 compile/package artifact only. No rebuild, configure, relink, generated test discovery, package repair, source edit, fixture edit, test edit, or selector mutation was performed.

- Artifact ID: `10327643907`
- Artifact ZIP SHA-256: `78c8d14e9e4ed63ca900f393ca696df4a684cb5d3e6fe2ec3438e92aae89a0e8`
- Packaged source: `702d9e10afff1fc3ac2ed3f3458acf8f19b617a5`
- Selector422 SHA-256: `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`
- First-408 prefix SHA-256: `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`
- Exact arithmetic package evidence: GMP/GMPXX linked; CB4 `runtimeExecution=false`.

## Immutable preflight

Preflight passed before runtime:

- outer artifact digest matched;
- packaged `SHA256SUMS` verified all 27 entries;
- compile/preflight exit codes were zero;
- all five packaged source-status receipts were empty;
- selector422 contained exactly 422 rows;
- rows 1-408 reproduced the accepted selector408 byte prefix;
- rows 409-422 were exactly the fourteen frozen CP-COND identities in order;
- the boundary-truncated separatrix identity was absent from selector422;
- owner distribution was exactly 30 authority-kernel / 276 producer / 75 completion / 41 validation;
- required owner binaries and support libraries existed with executable/file modes preserved;
- package, extracted source, and execution-view byte+mode censuses were frozen for postflight comparison.

## Runtime result

The authoritative attempt launched 423 fresh exact-filter processes:

- selector422: **422/422 PASS**;
- inherited rows 1-408: **408/408 PASS**;
- appended rows 409-422: **14/14 PASS**;
- report-only process 423, `InputConditionerCPCondCB1.BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker`: **expected SKIP**, selected exactly once, exit 0;
- zero gating RED;
- zero timeout;
- zero actual-selection mismatch;
- total launched Directional processes: **423**.

The report-only SKIP remains outside selector422 and earns no selector credit. It does not satisfy frozen CP-COND conjunct 4; Review must carry it as the named unresolved blocker unless independent authority proves the alternate frozen condition.

Earlier interrupted orchestration attempts receive zero semantic credit. The complete authoritative attempt restarted from selector ordinal 1 and is the only runtime ledger used by this report.

## Exact immutable postflight

Postflight byte+mode census exactly matched preflight for:

- immutable package;
- extracted packaged source;
- execution view.

The final execution summary records:

- `immutability=true`;
- `configure_execution=false`;
- `compile_execution=false`;
- `relink_execution=false`;
- `generated_discovery=false`;
- `package_repair=false`;
- `source_test_fixture_selector_mutation=false`.

## Evidence integrity

`EVIDENCE_SHA256SUMS` is intentionally non-self-referential: it hashes every substantive evidence file other than itself and is generated only after those files are finalized. `sha256sum -c EVIDENCE_SHA256SUMS` passes without exceptions or special-casing.

## Stop boundary

This is mechanical Test + Benchmark evidence only. TB4-EXEC does **not** promote the CB4 package or selector422 and does **not** close CP-COND. Mandatory successor: **`M4-CP-COND-TB4-REV`**.
