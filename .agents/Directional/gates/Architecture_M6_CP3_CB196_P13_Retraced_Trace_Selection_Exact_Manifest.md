# CB-196 exact retraced-trace selection helper manifest (2026-11-23 UTC)

**This file is a review artifact. The diff is not applied to live source.**

- **Authority:** [TB-REV-174 adversarial continuation](../Architecture_M6_CP3_TB_REV_174_Adversarial_Review_20261123.md), F1–F2. It replaces the prose CB-196 arrival-port receipt.
- **Patch:** `Architecture_M6_CP3_CB196_P13_Exact_Source_Retraced_Trace_Selection_Exact.diff`.
  - SHA-256 `d95f414457af1ff45dda04611b02ff53271cd55d325c7eb266dba514203e1499`.
  - 4,910 bytes, +82/−0, two files.
- **`include/directional/authority/ExactSourcePath.h`:**
  - git preimage `a968576efdc02027c7e1c5c2ec2cb7cf19edeeb7`, the CB-195 postimage;
  - postimage SHA-256 `0285981f850ca852ee2c172847381a1524b74bb1cd1a42d66e81e51fa443b19e`.
- **`tests/FieldAlignedCurveNetworkTests.cpp`:**
  - git preimage `bfc99a2232412ce0edafc0a2de66ae30aa2c1023`;
  - postimage SHA-256 `2b9cde9a37f89fa0ff8866938b9d7ff50845f47a4125fc304488840017d60d29`.
- **Scope:**
  - Adds the pure `ExactSourceRetracedTrace` and `exact_source_retraced_traces`, plus the `<compare>` and `<cstddef>` includes. They are unwired.
  - Appends 2 tests at the end of the file.
  - No product, selector or assertion change.
- **TB manifest:** `Architecture_M6_TB175_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv`.
  - SHA-256 `e1d77fd2a10b67e71ecbc6712a92eec48713e91e0006c7282652dc2391b43e35`, 1000 rows.
  - Its first 998 rows are the TB174 manifest exactly.
- **Verified in this review:**
  - `git apply --check` and `git diff --check` are clean.
  - `clang++ -fsyntax-only` (C++20, `USE_GMP_ENABLED`) on the test TU gives 0 errors and the same 9 warnings as before.
- **Strict stop:** a preimage mismatch or compile failure means BLOCKED; return to Review.
