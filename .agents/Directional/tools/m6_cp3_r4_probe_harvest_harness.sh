#!/usr/bin/env bash
set -euo pipefail
[[ "${1:-}" == --execute ]] || exit 64
: "${GITHUB_REPOSITORY:?}" "${GH_TOKEN:?}" "${RUNNER_TEMP:?}" "${TURN_ID:?}"
r="$RUNNER_TEMP/$TURN_ID"; o="$RUNNER_TEMP/$TURN_ID-result"
mkdir -p "$r/p" "$r/s" "$r/v/bin" "$r/run" "$o/raw"
exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
executed=0; red=0; missing=0; postflight=false; planned=0
finish() {
  rc=$?; set +e
  printf 'artifact_id=11976790988\nsource_sha=16c3134c02ab3872eee77a6b9dcc9d3fc6e01b7b\nplanned=44\nexecuted=%d\nred=%d\nmissing=%d\npostflight=%s\ncompile=false\nrelink=false\nbenchmarks=false\nselector497=false\nexit=%d\n' "$executed" "$red" "$missing" "$postflight" "$rc" > "$o/execution-boundary.txt"
  (cd "$o"; find . -type f ! -name SHA256SUMS -print0 | sort -z | xargs -0 sha256sum > SHA256SUMS)
}
trap finish EXIT
die() { echo "ORCHESTRATION_FAILURE $*" >&2; exit 90; }
sha() { sha256sum "$1" | cut -d' ' -f1; }
z="31faf55a33c31abb60c8f34acb64ad901514de821cd6d2f3acbdcd817b1dbb36"
curl -fsSL -H "Authorization: Bearer $GH_TOKEN" "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/11976790988" > "$r/provider.json"
grep -q "sha256:$z" "$r/provider.json" || die 'provider digest'
curl -fsSL -H "Authorization: Bearer $GH_TOKEN" "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/11976790988/zip" -o "$r/a.zip"
[[ "$(sha "$r/a.zip")" == "$z" ]] || die 'artifact digest'
unzip -q "$r/a.zip" -d "$r/p"
p="$r/p"; s="$r/s"
[[ "$(sha "$p/SHA256SUMS")" == 0733087eeea65acccd5638cf208ff957f5091fb3dd4a303ad9bb96811aee43ae ]] || die manifest
(cd "$p"; sha256sum -c SHA256SUMS) > "$o/manifest-before.txt" || die integrity
[[ "$(grep -c ': OK$' "$o/manifest-before.txt")" -eq 28 ]] || die manifest_count
[[ "$(cat "$p/metadata/source-commit.txt")" == 16c3134c02ab3872eee77a6b9dcc9d3fc6e01b7b ]] || die source_identity
grep -qx 'exactArithmeticBackend=GMP' "$p/metadata/command-boundary.txt" || die arithmetic
grep -qx 'runtimeExecution=false' "$p/metadata/command-boundary.txt" || die compile_only
a="$p/source/source-16c3134c02ab3872eee77a6b9dcc9d3fc6e01b7b.tar.gz"
[[ "$(sha "$a")" == 9671b28a187fccb5f0355f11487517bff744938f15e1bcb23c2a1cb8670d8440 ]] || die packaged_source_hash
tar -xzf "$a" -C "$s"
for pair in \
 '.agents/Directional/Architecture_M6_CP1_Required_Green_Focused_30.txt:1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6' \
 '.agents/Directional/Architecture_M6_CP2_Required_Green_Focused_12.txt:2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed' \
 '.agents/Directional/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt:d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414' \
 '.agents/Directional/Architecture_M5_CP4_CB2_Selector_449_Static_Routing_Receipt.tsv:9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707'; do
 [[ "$(sha "$s/${pair%%:*}")" == "${pair##*:}" ]] || die "frozen selector $pair"
done
(cd "$p"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/p0"
(cd "$s"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/s0"
cp -a "$p/bin/." "$r/v/bin/"
mkdir -p "$r/v/test-data/benchmarks"; cp -a "$s/benchmarks/fixtures" "$r/v/test-data/benchmarks/"
(cd "$r/v"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/v0"
inventory="$GITHUB_WORKSPACE/.agents/Directional/Architecture_M6_CP3_R4_Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv"
[[ -f "$inventory" ]] || die 'census inventory missing'
[[ "$(sha "$inventory")" == de05a7bd5ca27eb243156ecd38434fbc69d06f4b791bdd3dbcfc5982c273a865 ]] || die 'census inventory drift'
mapfile -t tests < <(tail -n +2 "$inventory" | cut -f2)
mapfile -t historical_ordinals < <(tail -n +2 "$inventory" | cut -f1)
[[ "${#tests[@]}" == 39 ]] || die "identity count ${#tests[@]}"
[[ "$(printf '%s\n' "${tests[@]}" | sort -u | wc -l)" == 39 ]] || die 'duplicate identities'

printf 'index\thistorical_ordinal\tidentity\towner\texit\tselected\tpassed\tverdict\n' > "$o/ledger.tsv"
for i in "${!tests[@]}"; do
 historical="${historical_ordinals[i]}"
 [[ "$historical" == 405 ]] && continue # separate non-interior mechanism, not part of 44
 planned=$((planned+1)); n=$planned; name="${tests[i]}"; exe=directional_surface_cell_producer_tests
 if [[ ! -x "$r/v/bin/$exe" ]]; then
  missing=$((missing+1)); echo "MISSING_IMMUTABLE_EXECUTABLE $exe ($name)";
  printf '%s\t%s\t%s\t%s\t-\t0\t0\tNOT_EXECUTED\n' "$n" "$historical" "$name" "$exe" >> "$o/ledger.tsv"
  continue
 fi
 mkdir -p "$r/run/$n"
 set +e
 (cd "$r/run/$n"; /usr/bin/time -v env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$r/v/bin/$exe" --gtest_filter="$name") > "$o/raw/$n.log" 2>&1
 code=$?
 set -e
 cat "$o/raw/$n.log"
 picked="$(grep -c '^\[ RUN      \] ' "$o/raw/$n.log" || true)"
 passed="$(grep -c '^\[       OK \] ' "$o/raw/$n.log" || true)"
 skipped="$(grep -c '^\[  SKIPPED \] ' "$o/raw/$n.log" || true)"
 if [[ "$picked" != 1 || "$skipped" != 0 ]]; then
  missing=$((missing+1))
  printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\tNOT_SELECTED\n' "$n" "$historical" "$name" "$exe" "$code" "$picked" "$passed" >> "$o/ledger.tsv"
  echo "NOT_SELECTED ordinal=$n identity=$name selected=$picked skipped=$skipped"
  continue
 fi
 verdict=RED; [[ "$code" == 0 && "$passed" == 1 ]] && verdict=PASS
 printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$n" "$historical" "$name" "$exe" "$code" "$picked" "$passed" "$verdict" >> "$o/ledger.tsv"
 executed=$((executed+1))
 if [[ "$verdict" == RED ]]; then red=$((red+1)); fi
done
# Additional named supplemental witnesses (two Phase14 identities require a
# separate historical test executable and are deliberately outside this rung).
# Every identity executes independently, including after an observed RED.
extra=(
  SurfaceCellAuthorityContractCutover.ProducedRailIntervalReachesNetworkBoundOpenFrontConsumer
  SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard
  SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement
  SurfaceCellAuthorityContractCutover.DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate
  SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress
  M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm
)
for i in "${!extra[@]}"; do
 planned=$((planned+1)); n=$planned; name="${extra[i]}"; exe=directional_surface_cell_producer_tests
 if [[ ! -x "$r/v/bin/$exe" ]]; then
  missing=$((missing+1))
  printf '%s\tSUPPLEMENTAL\t%s\t%s\t-\t0\t0\tNOT_EXECUTED\n' "$n" "$name" "$exe" >> "$o/ledger.tsv"
  continue
 fi
 mkdir -p "$r/run/$n"
 set +e
 (cd "$r/run/$n"; /usr/bin/time -v env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no "$r/v/bin/$exe" --gtest_filter="$name") > "$o/raw/$n.log" 2>&1
 code=$?
 set -e
 cat "$o/raw/$n.log"
 picked="$(grep -c '^\[ RUN      \] ' "$o/raw/$n.log" || true)"
 passed="$(grep -c '^\[       OK \] ' "$o/raw/$n.log" || true)"
 skipped="$(grep -c '^\[  SKIPPED \] ' "$o/raw/$n.log" || true)"
 if [[ "$picked" != 1 || "$skipped" != 0 ]]; then
  missing=$((missing+1))
  printf '%s\tSUPPLEMENTAL\t%s\t%s\t%s\t%s\t%s\tNOT_SELECTED\n' "$n" "$name" "$exe" "$code" "$picked" "$passed" >> "$o/ledger.tsv"
  continue
 fi
 verdict=RED; [[ "$code" == 0 && "$passed" == 1 ]] && verdict=PASS
 printf '%s\tSUPPLEMENTAL\t%s\t%s\t%s\t%s\t%s\t%s\n' "$n" "$name" "$exe" "$code" "$picked" "$passed" "$verdict" >> "$o/ledger.tsv"
 executed=$((executed+1))
 if [[ "$verdict" == RED ]]; then red=$((red+1)); fi
done
[[ "$planned" == 44 ]] || die "planned count $planned"
# Parse directly from each independent raw process; absence of a probe is visible, not synthesized.
python3 - "$o" <<'PY_HARVEST'
import csv, pathlib, re, sys
o = pathlib.Path(sys.argv[1])
fields = ["a2bProbeFailure", "a2bProbeFirstFailedCondition",
          "a2bProbeFromSourceVertex", "a2bProbeToSourceVertex",
          "a2bProbeFirstIntervalPresent", "a2bProbeSecondIntervalPresent",
          "a2bProbeFirstSpan", "a2bProbeSecondSpan",
          "a2bProbeFirstFirstOrdinal", "a2bProbeFirstSecondOrdinal",
          "a2bProbeSecondFirstOrdinal", "a2bProbeSecondSecondOrdinal"]
with (o / 'ledger.tsv').open(newline='') as src, (o / 'probe-harvest.tsv').open('w', newline='') as dst:
    rows = list(csv.DictReader(src, delimiter='\t'))
    writer = csv.writer(dst, delimiter='\t')
    writer.writerow(['index', 'historical_ordinal', 'identity', 'verdict', 'probe_emitted'] + fields)
    for row in rows:
        raw = o / 'raw' / (row['index'] + '.log')
        content = raw.read_text(errors='replace') if raw.exists() else ''
        values = []
        for key in fields:
            match = re.search(re.escape(key) + r'=([^;\r\n"]+)', content)
            values.append(match.group(1) if match else '')
        writer.writerow([row['index'], row['historical_ordinal'], row['identity'],
                         row['verdict'], int(any(values))] + values)
PY_HARVEST
(cd "$p"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/p1"
(cd "$s"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/s1"
(cd "$r/v"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/v1"
cmp -s "$r/p0" "$r/p1" || die package_mutation
cmp -s "$r/s0" "$r/s1" || die source_mutation
cmp -s "$r/v0" "$r/v1" || die execution_view_mutation
(cd "$p"; sha256sum -c SHA256SUMS) > "$o/manifest-after.txt" || die postflight_manifest
echo 'package=true source=true execution_view=true selector=true' > "$o/immutability.txt"
postflight=true
echo "MEASUREMENT_COMPLETE: $executed/44 executed; $red RED; $missing missing; all independent identities attempted."
[[ "$executed" == 44 && "$missing" == 0 && "$postflight" == true ]] || die 'incomplete interior-witness measurement'
exit 0
