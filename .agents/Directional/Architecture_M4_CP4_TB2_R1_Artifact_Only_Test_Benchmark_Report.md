# M4-CP4-TB2-R1-EXEC — artifact-only Test + Benchmark report

**Turn:** `M4-CP4-TB2-R1-EXEC`
**Result:** **COMPLETE / ORCHESTRATION INVALID / NO SEMANTIC LEDGER / NON-STABLE**
**Correction successor:** `M4-CP4-CB7`

## 1. Frozen authority and pre-runtime controls

R1 preserved the frozen semantic gate exactly: immutable full CB4 artifact `10578784752`, CB5 delta `10582435470`, selector427, owner census **30 / 281 / 75 / 41**, the four M4-owned focused identities and the CB4/CB5 composite routing. Accepted M4 runtime authority remained package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427** throughout the turn.

Mandatory Test + Benchmark stale-evidence cleanup was performed before runtime orchestration. The exact CB6 caller draft was then published byte-for-byte as temporary `.github/workflows/m4-cp4-tb2-r1-exec.yml`. Fresh source snapshot run `35444548694` at event SHA `42dea9844fc09d298ba6fa7c1c1b7eb7a7df28fa` re-hashed the installed caller to SHA-256 `88ab6b51201801f2468add9b3f1ee4ad890c751052c48b1a7c0e9f773af8699c`, exactly equal to the durable draft, and re-hashed the harness to `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba` with mode `755`.

A temporary schema-only validation carrier first self-validated successfully in run `35444492066`. Exact installed-caller validation run `35444528913` then produced `valid=true` for `.github/workflows/m4-cp4-tb2-r1-exec.yml` at exact event/checkout SHA `d9bcf978374cad2a312bc8ade64c20b46e50b835`.

## 2. Runtime trigger and orchestration stop

The runtime trigger was committed separately at event SHA `f255ae88a35a16db177748affb4283cbb10e48db`. GitHub Actions created run `35444642320`, but the run concluded immediately as **`startup_failure`** and instantiated **zero jobs**. Therefore the observer, schema-validation and execute jobs never started, the R1 harness never launched, neither immutable package was downloaded by the R1 workload, and **zero generated Directional processes** executed.

No focused identity, selector row, package acquisition, composite-view materialization or postflight result exists for this attempt. The turn consequently has **no semantic ledger** and grants zero runtime, selector, promotion or debt credit.

## 3. Root-cause classification

`M4-CP4-TB2-R1-EXEC-CAND-01` is **OPEN / ORCHESTRATION / CALLER_PERMISSION_CEILING / NON-STABLE**.

The exact validated R1 caller declares top-level `contents: read`, while its called `agent-run-observer-reusable.yml` contains the optional `branch-file` job with `permissions: contents: write`. GitHub evaluates reusable-workflow permission ceilings when constructing the run; a called workflow cannot elevate permissions beyond the caller. The observed signature — `startup_failure` before any job is instantiated — matches the immediately preceding CB6 validation-carrier failure, run `35441785784`, which was corrected only after the carrier's caller ceiling was raised to `contents: write` in commit `9891a77e69dfeea771900fc8454182ca037c8927`.

SchemaStore validation was correctly GREEN because schema validation checks document structure, not cross-workflow permission-ceiling compatibility. The defect is therefore in the R1 caller control contract, not in Directional runtime, immutable package bytes or the frozen semantic gate.

## 4. Accounting and authority disposition

This orchestration failure is not a semantic regression event: **+0 event / +0 category / +0 recurrence**. Stable totals remain **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**. `M4-CP4-TB1-R3-CAND-01` and `CAND-03` remain **CORRECTED IN CB5 / RUNTIME RE-PROOF PENDING / NON-STABLE**. The M4-owned produced closed-complex debt remains open; the two periodic `G4-B002` debts remain M5-owned and unchanged.

The invalid TB2 attempts and this R1 startup failure are audit-only provenance. None contributes a process row to later acceptance.

## 5. Successor

`Turn_Cadence.md` requires `TB orchestration failure -> CB orchestration correction -> fresh TB`. Exact successor is runtime-free control-plane-only **`M4-CP4-CB7`**. CB7 must correct the caller permission ceiling without changing the frozen harness, package, selector, focus set or owner routing, and then authorize a fresh **`M4-CP4-TB2-R2-EXEC`** from ordinal 1. No same-turn retry is authorized.
