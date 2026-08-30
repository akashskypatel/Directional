#!/usr/bin/env bash
set -uo pipefail
ART=9724864897
OUTER=a4d9803eea326b5a22f6c4e21cc07e0908eaede944d02a726ae3c5f6d856734c
BUILD_SRC=1230621baff6d04fb20df3b1bf48903cd65b5d69
SEM_SRC=4f0f3ca74a88ba260a20c019437bc4995f2056e0
SRC_SHA=3b4decd367a3fdb932754c3c6e420b536fa7607755e8ff2541f137f1589d5544
EIGEN=769c72fd8019e389810d1de1e7c243521a43b594
H365=6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1
H361=61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b
H357=b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70
H355=e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa
E="$RUNNER_TEMP/r8-evidence"; W="$RUNNER_TEMP/r8-work"; R="$RUNNER_TEMP/r8-result"; H="$RUNNER_TEMP/r8-harness.py"
mkdir -p "$E/processes" "$W" "$R"; : > "$E/execution-ledger.tsv"; : > "$E/not-run.tsv"
STATUS=ORCHESTRATION_RED; REASON=uninitialized; RUNTIME=0; ACCEPTED_GREEN=0; CHECKPOINT_GREEN=0; FIRST_RED=0; HAVE_BASE=0
source "$RUNNER_TEMP/r8-lib.sh"
GH_TOKEN=${GH_TOKEN:?} gh api "repos/$GITHUB_REPOSITORY/actions/artifacts/$ART/zip" > "$W/package.zip" || { REASON=artifact_download_failure; finish 2; }
[[ $(sha256sum "$W/package.zip"|cut -d' ' -f1) == "$OUTER" ]] || { REASON=outer_digest_mismatch; finish 2; }
unzip -q "$W/package.zip" -d "$W/package" || { REASON=artifact_extract_failure; finish 2; }
(cd "$W/package" && sha256sum -c SHA256SUMS > "$E/preflight-sha256sums.txt" 2>&1) || { REASON=internal_manifest_failure; finish 2; }
[[ $(grep -c ': OK$' "$E/preflight-sha256sums.txt") == 28 ]] || { REASON=manifest_count_mismatch; finish 2; }
[[ $(cat "$W/package/metadata/source-commit.txt") == "$BUILD_SRC" ]] || { REASON=build_source_mismatch; finish 2; }
ST="$W/package/source/source-$BUILD_SRC.tar.gz"; [[ -f $ST && $(sha256sum "$ST"|cut -d' ' -f1) == "$SRC_SHA" ]] || { REASON=source_archive_mismatch; finish 2; }
grep -qx 'exactArithmeticBackend=GMP' "$W/package/metadata/command-boundary.txt" && grep -qx 'runtimeExecution=false' "$W/package/metadata/command-boundary.txt" && grep -qx 'turnBoundary=Code+Build-only' "$W/package/metadata/command-boundary.txt" || { REASON=command_boundary_mismatch; finish 2; }
grep -qi 'gmpxx' "$W/package/metadata/gmp-evidence.txt" && grep -qi 'gmp' "$W/package/metadata/gmp-evidence.txt" || { REASON=gmp_evidence_missing; finish 2; }
grep -q "$EIGEN external/eigen" "$W/package/metadata/dependency-revisions.txt" || { REASON=eigen_revision_mismatch; finish 2; }
for f in "$W/package"/metadata/source-status-*.txt; do [[ ! -s "$f" ]] || { REASON="dirty_packaged_source:$(basename "$f")"; finish 2; }; done
for b in directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests directional_compiled_api_tests directional_benchmarks; do [[ -x "$W/package/bin/$b" ]] || { REASON="binary_not_executable:$b"; finish 2; }; done
rm -rf "$GITHUB_WORKSPACE"/* "$GITHUB_WORKSPACE"/.[!.]* "$GITHUB_WORKSPACE"/..?* 2>/dev/null || true
tar -xzf "$ST" -C "$GITHUB_WORKSPACE" || { REASON=source_extract_failure; finish 2; }
test -f "$GITHUB_WORKSPACE/benchmarks/fixtures/milestone-g/torus.rawfield" || { REASON=fixture_layout_failure; finish 2; }
inv "$W/package" "$E/package-before.tsv"; inv "$GITHUB_WORKSPACE" "$E/source-before.tsv"; HAVE_BASE=1
S="$GITHUB_WORKSPACE/.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_365.txt"
N="$GITHUB_WORKSPACE/.agents/Directional/Architecture_M3_CP4c2_Non_Gating_Diagnostic_Selector.txt"
[[ $(wc -l < "$S") == 365 && $(sort "$S"|uniq|wc -l) == 365 ]] || { REASON=selector_cardinality_or_uniqueness; finish 2; }
{ head -n355 "$S"|sha256sum; head -n357 "$S"|sha256sum; head -n361 "$S"|sha256sum; sha256sum "$S"; } > "$E/selector-hashes.txt"
mapfile -t hs < <(awk '{print $1}' "$E/selector-hashes.txt"); exp=("$H355" "$H357" "$H361" "$H365"); for i in {0..3}; do [[ ${hs[$i]:-} == ${exp[$i]} ]] || { REASON="selector_hash_mismatch:$i"; finish 2; }; done
python3 - "$GITHUB_WORKSPACE" "$S" > "$E/new-identity-static-resolution.txt" <<'PY'
import pathlib,re,sys,collections
root=pathlib.Path(sys.argv[1]); ids=pathlib.Path(sys.argv[2]).read_text().splitlines()[355:]
pat=re.compile(r'\bTEST(?:_F)?\s*\(\s*([A-Za-z_][A-Za-z0-9_]*)\s*,\s*([A-Za-z_][A-Za-z0-9_]*)\s*\)')
c=collections.Counter()
for p in (root/'tests').rglob('*.cpp'):
  for m in pat.finditer(p.read_text(errors='replace')): c[f'{m.group(1)}.{m.group(2)}']+=1
for i in ids: print(f'{i}\t{c[i]}')
if any(c[i]!=1 for i in ids): raise SystemExit(1)
PY
[[ $? == 0 ]] || { REASON=new_identity_static_resolution_failure; finish 2; }
printf 'selected_gate=365\nselector_sha256=%s\nartifact_id=%s\ngate_execution_authorized=true\nselected_r2_branch=NONE\n' "$H365" "$ART" > "$E/gate-authority.txt"
printf 'artifact=%s\nouter_sha256=%s\nbuild_transport_source=%s\nsemantic_source=%s\nsource_archive_sha256=%s\neigen=%s\nselector_count=365\nmanifest_ok=28/28\n' "$ART" "$OUTER" "$BUILD_SRC" "$SEM_SRC" "$SRC_SHA" "$EIGEN" > "$E/preflight.txt"
STATUS=RUNNING; REASON=runtime_started; RUNTIME=1
while IFS= read -r id; do run1 R8-NG "$id" directional_surface_cell_producer_tests || { STATUS=ORCHESTRATION_RED; REASON="R8-NG:harness_or_selection_failure"; finish 2; }; (( RUN_RC >= 0 && RUN_RC <= 1 )) || { STATUS=ORCHESTRATION_RED; REASON="R8-NG:process_integrity:$RUN_RC"; finish 2; }; done < "$N"
for id in GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating; do run1 R8-DIAG "$id" directional_surface_cell_producer_tests || { STATUS=ORCHESTRATION_RED; REASON="R8-DIAG:harness_or_selection_failure:$id"; finish 2; }; (( RUN_RC >= 0 && RUN_RC <= 1 )) || { STATUS=ORCHESTRATION_RED; REASON="R8-DIAG:process_integrity:$RUN_RC"; finish 2; }; done
ord=0
while IFS= read -r id; do ((ord++)); [[ $ord -le 355 ]] || break; suite=${id%%.*}; bin=$(owner "$suite"); run1 R8-ACCEPTED "$id" "$bin" "$ord" || { STATUS=ORCHESTRATION_RED; REASON="accepted:harness_or_selection_failure:$ord"; finish 2; }; if [[ $RUN_RC != 0 ]]; then FIRST_RED=$ord; ACCEPTED_GREEN=$((ord-1)); STATUS=SEMANTIC_RED; REASON="accepted:first_red:$ord:$id"; finish 1; fi; ACCEPTED_GREEN=$ord; done < "$S"
ord=355
while IFS= read -r id; do ((ord++)); suite=${id%%.*}; bin=$(owner "$suite"); run1 R8-CHECKPOINT "$id" "$bin" "$ord" || { STATUS=ORCHESTRATION_RED; REASON="checkpoint:harness_or_selection_failure:$ord"; finish 2; }; if [[ $RUN_RC != 0 ]]; then FIRST_RED=$ord; CHECKPOINT_GREEN=$((ord-355-1)); STATUS=SEMANTIC_RED; REASON="checkpoint:first_red:$ord:$id"; finish 1; fi; CHECKPOINT_GREEN=$((ord-355)); done < <(tail -n +356 "$S")
STATUS=SEMANTIC_GREEN; REASON=selector_365_green; finish 0
