# M5-CP3-CB13 R11 Result-Manifest Finalization Orchestration Correction Report

**Turn:** `M5-CP3-CB13`  
**Disposition:** **COMPLETE / CONTROL-PLANE-ONLY / RUNTIME-FREE / STATIC+SYNTHETIC GREEN**  
**Exact successor:** `M5-CP3-TB1-R11-R1-EXEC`

## 1. Scope and preserved semantic authority

CB13 corrects only the orchestration defect recorded as `M5-CP3-TB1-R11-EXEC-CAND-01`. It does **not** modify Directional product source, tests, fixtures, selector/routing semantics, compile/package contents, or accepted runtime authority.

The immutable retry candidate remains:

- candidate artifact/source: `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`;
- candidate ZIP SHA-256: `faf4def9e6823f718e56091876bb97047f5e91a8bfb561ca40d91d70d2af61ce`;
- root manifest SHA-256: `352f7553e2f0dc627ada385d78327bcb93d4f3b66125f4faf540d6965a1c2c33`, 28/28;
- packaged source archive SHA-256: `506e9d75976802f7045b95344ef8cc0ff1e4d39b8343bdaddaa009a58e04a673`;
- routing artifact: `10592987234`;
- routing ZIP SHA-256: `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- identity-map SHA-256: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 / first427 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6 / f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Accepted runtime remains `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316`. Stable accounting remains **50 events / 14 categories / 36 recurrences**. Produced-witness debt remains **3**. CB12 remains unpromoted and selector publication remains prohibited.

## 2. Correction

The invalid R11 caller wrote `SHA256SUMS.new` inside the result tree before enumerating that tree. CB13 replaces that with an external temporary manifest:

```bash
manifest_tmp="${RUNNER_TEMP}/${TURN_ID}-SHA256SUMS.final"
...
cp "$authority" "$result/driver-authority.txt"
...
cd "$result"
find . -type f ! -name SHA256SUMS -print0 \
  | LC_ALL=C sort -z \
  | xargs -0 sha256sum > "$manifest_tmp"
mv "$manifest_tmp" SHA256SUMS
sha256sum -c SHA256SUMS
manifest_rows="$(grep -cve '^$' SHA256SUMS)"
actual_non_manifest="$(find . -type f ! -name SHA256SUMS | wc -l | tr -d ' ')"
test "$manifest_rows" = "$actual_non_manifest"
```

The retry workflow additionally fail-closes if the temporary manifest path is under the result tree. `driver-authority.txt` is copied before manifest generation. `SHA256SUMS` remains the sole intended self-exclusion.

Expected SHA-256 authorities are no longer transcribed directly into the retry workflow. They are frozen in the retained R11-R1 plan and parsed into an environment file before `write_orchestration_payload.py` materializes the driver. The workflow contains zero raw 64-hex SHA-256 literals.

## 3. Frozen retry authority

CB13 creates:

- `.agents/Directional/Architecture_M5_CP3_TB1_R11_R1_Artifact_Only_Test_Benchmark_Plan.md`;
- `.agents/Directional/turn-payloads/m5_cp3_tb1_r11_r1_exec.py.in`;
- `.github/workflows/m5-cp3-tb1-r11-r1-exec.yml`.

The retry driver is byte-identical to the invalid R11 driver template after substituting only
`M5-CP3-TB1-R11-EXEC` -> `M5-CP3-TB1-R11-R1-EXEC`. Static proof restores the old turn string and reproduces historical R11 template SHA-256
`370ebb5aaa6b77f8839ac0a7c5a20f24a22cd584876ea17a11d222a5ec4f9624`.

Therefore the semantic execution vector is unchanged: **9 mechanism + 1 focused + 6 produced + 430 selector = 446 fresh processes**, exact-one/zero-skip, benchmark count **0**. R11-R1 imports zero semantic rows or verdicts from invalid R11.

## 4. CB13 verification evidence

Source snapshot run `35774876423` produced exact branch snapshot artifact `10716035645` at provider ZIP SHA-256
`8425597c0a694153027e334b8ec49eadba73703b12a365a84cc69f9221d23cd1`.

Control-plane validation run `35775766068` completed GREEN at event SHA
`d078db5b8816cd2eed30c4418c26b9b1ce33497e`:

- retry-workflow schema job `106908450647`: GREEN;
- CB13 self-schema job `106908451034`: GREEN;
- static/synthetic job `106908512994`: GREEN;
- result artifact `10716415780`, provider ZIP SHA-256
  `e8a3d09981e6eb22df70325741bb265cc2f81cc141c507f6f1577e1e8efeb20b`;
- diagnostic log artifact `10716260918`, provider ZIP SHA-256
  `f1cfbc376c05be90da52f7e6660eb86589ec79578e3f0aba35a44e01b10df88b`.

The result proves:

- retry and CB13 workflows schema-valid;
- no in-tree manifest temporary path;
- authority copy precedes manifest generation;
- final `sha256sum -c` is fail-closed;
- manifest-row/non-manifest-file equality is explicit;
- synthetic result baseline is **3/3**;
- synthetic checksum corruption is detected;
- synthetic late-file count mismatch is detected;
- retry driver materialization succeeds;
- retry driver differs from R11 only by turn ID;
- planned process count remains **446** and benchmark count **0**;
- `directional_runtime_execution=false`;
- configure/compile/relink/generated-discovery/package-repair/mode-repair counters remain **0** for CB13.

No Directional executable or benchmark ran in CB13.

## 5. Disposition of the orchestration defect

`M5-CP3-TB1-R11-EXEC-CAND-01` is **CORRECTED / STATIC+SYNTHETIC GREEN / NON-STABLE / +0 / RETRY CONFIRMATION PENDING**.

CB13 proves the known self-inclusion mechanism is removed and the corrected finalizer fails closed under checksum and file-count mismatch. It does not convert invalid R11 runtime rows into semantic evidence. Fresh R11-R1 remains mandatory and must restart the full 446-process gate from process 1 on the unchanged candidate.

## 6. Exact successor

Exact successor is **`M5-CP3-TB1-R11-R1-EXEC`** under
`.agents/Directional/Architecture_M5_CP3_TB1_R11_R1_Artifact_Only_Test_Benchmark_Plan.md`.

Do not rebuild or repackage. Do not reuse any invalid R11 process result. Do not modify product/test/fixture/selector/routing semantics. A mechanically complete R11-R1 routes to mandatory `M5-CP3-TB1-R11-R1-REV`.
