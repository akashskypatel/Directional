# TB9 — terminal-star-path harvest (2026-10-16)

**Turn:** `M6-CP3-TB9-R9-TERMINAL-STAR-PATH-HARVEST`. Immutable artifact-only execution. Compiled semantic source `18cc4da5e2bc41138c5363a74de4e2db1e28ef23`; input workflow `38916496178`, artifact `12052388003`, ZIP SHA-256 `ed250e970a78dcdae621117cb2a7fd9333849d6083cc8e01775cb207823c07b9`; 28/28 packaged checksums validated. Execution workflow [38921052963](https://github.com/akashskypatel/Directional/actions/runs/38921052963), request commit `13cd4d75d582cb53cd877785c1429e859269904b`, result artifact `12055460315`, result ZIP SHA-256 `fa729d87b7b8057f6800ba64d1146d1f8293d0192bb45580234281beefb5a0ae`.

**Execution evidence:** 44 selected identities, 44 executed, 44 RED, 0 missing, 0 PASS. Runtime job completed successfully; compile job skipped. No rebuild, relink, benchmark or selector497 execution. Immutable postflight verified `package=true source=true execution_view=true frozen_selectors=true`. The RED results are historical expected failures, not new accepted-green regression evidence.

**F1/F2:** 48 rejection diagnostic observations: 21 same-vertex bit-exact one-hot observations in 21 identities and 27 nonvertex observations. Across **all 21 vertex observations**, the following fields were invariant:

| Diagnostic | All 21 |
|---|---|
| Published terminal contact / matching source component | `1` / `1` |
| Exact same one-hot source vertex | `1` |
| Published-terminal/carrier-endpoint conjunction | **`0`** |
| Orientation 0 first/second path | `Unique` / `Unique` |
| Orientation 0 disjoint faces / A3 transport | `1` / `1` |
| Orientation 1 first/second path | `Missing` / `Missing` |
| Orientation 1 disjoint faces / A3 transport | `0` / `1` |
| Admissible orientation count | **`0`** |

**Disposition:** **0/21** vertex observations satisfy branch V's full five-part conjunction. The reverse `Missing` paths alone do **not** invalidate the unique forward orientation; the forward candidate fails because `a3ProbePublishedCarrierEndpoint=0`. This is a *composite* predicate requiring both published-contact endpoint membership and canonical carrier-edge endpoint membership; this probe does not resolve which subcondition fails. Avoid inventing that subclassification. Thus the RA-79 branch-V contract is not applicable to the measured 21 cases; this does not prove the contract itself unsound. No repair or relaxed admission is justified. Branch I exact-rational strictness remains; branch C remains suspended; `RP-01` open, `RP-02` unreached. Stable ledger `66/17/49`, debt 1, CP2 `491/491` accepted, R3 `403/497` rejected, frozen selector497 unchanged.

**Independent evidence cross-check:** The committed execution harness verifies immutable execution, 44 exact-filter runs, and 2,628 older `a2bProbe` source-entity records; it does **not** aggregate `a3Probe` directly. A separate literal-field scan of all 44 raw logs inside result artifact `12055460315` independently counted the 48 A3 records (21 exact same-one-hot vertex, 27 nonvertex) and confirmed every value in the table above. Thus this conclusion is based on the immutable raw diagnostic bytes, not on an A3-specific harness assertion. Both the original harness summary and the new probe data remain individually attributable. No binaries were rerun during this cross-check.

**Formal closeout:** `Regression_Root_Cause_Tracker.md` candidate/non-stable entry and durable handoff/TODO/CHANGELOG dispositions are part of the associated documentation patch. The earlier Drive patch-upload attempt reported `container_session_unavailable` and is not claimed to have succeeded. No independent Review has approved a successor turn identifier: **UNKNOWN**. Do not start conditional rung 22 without Review. No stable regression ID/count or accepted-green ledger adjustment is justified.
