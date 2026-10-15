#!/usr/bin/env bash
set -euo pipefail
[[ "${1:-}" == --execute ]] || exit 64
: "${GITHUB_REPOSITORY:?}" "${GH_TOKEN:?}" "${RUNNER_TEMP:?}" "${TURN_ID:?}"
r="$RUNNER_TEMP/$TURN_ID"; o="$RUNNER_TEMP/$TURN_ID-result"
mkdir -p "$r/p" "$r/s" "$r/v/bin" "$r/run" "$o/raw"
exec > >(tee "$RUNNER_TEMP/$TURN_ID.log") 2>&1
executed=0; red=0; missing=0; postflight=false
finish() {
  rc=$?; set +e
  printf 'artifact_id=11939982141\nsource_sha=953f812ff1f431e3ad3af3b68a92284a7831c94a\nexecuted=%d\nred=%d\nmissing=%d\npostflight=%s\ncompile=false\nrelink=false\nbenchmarks=false\nselector497=false\nexit=%d\n' "$executed" "$red" "$missing" "$postflight" "$rc" > "$o/execution-boundary.txt"
  (cd "$o"; find . -type f ! -name SHA256SUMS -print0 | sort -z | xargs -0 sha256sum > SHA256SUMS)
}
trap finish EXIT
die() { echo "ORCHESTRATION_FAILURE $*" >&2; exit 90; }
sha() { sha256sum "$1" | cut -d' ' -f1; }
z="2d5d1fc3f75b573307cae8af3c837da3dde2302ffdb4fe0ef3dd34d2aafeed7a"
curl -fsSL -H "Authorization: Bearer $GH_TOKEN" "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/11939982141" > "$r/provider.json"
grep -q "sha256:$z" "$r/provider.json" || die 'provider digest'
curl -fsSL -H "Authorization: Bearer $GH_TOKEN" "https://api.github.com/repos/$GITHUB_REPOSITORY/actions/artifacts/11939982141/zip" -o "$r/a.zip"
[[ "$(sha "$r/a.zip")" == "$z" ]] || die 'artifact digest'
unzip -q "$r/a.zip" -d "$r/p"
p="$r/p"; s="$r/s"
[[ "$(sha "$p/SHA256SUMS")" == 6c5938b9bc19377041649ce0546b86b2e6c6e2c9d6969fe01639da7baf4af203 ]] || die manifest
(cd "$p"; sha256sum -c SHA256SUMS) > "$o/manifest-before.txt" || die integrity
[[ "$(grep -c ': OK$' "$o/manifest-before.txt")" -eq 28 ]] || die manifest_count
[[ "$(cat "$p/metadata/source-commit.txt")" == 953f812ff1f431e3ad3af3b68a92284a7831c94a ]] || die source_identity
grep -qx 'exactArithmeticBackend=GMP' "$p/metadata/command-boundary.txt" || die arithmetic
grep -qx 'runtimeExecution=false' "$p/metadata/command-boundary.txt" || die compile_only
a="$p/source/source-953f812ff1f431e3ad3af3b68a92284a7831c94a.tar.gz"
[[ "$(sha "$a")" == 3d0bf938f0bf2828ef407ceeb092254b003682336c97e83f88867efa2c3c38e9 ]] || die packaged_source_hash
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
tests=(
 M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm
 SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement
 SurfaceCellAuthorityContractCutover.DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate
 SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress
)
printf 'ordinal\tidentity\towner\texit\tselected\tpassed\tverdict\n' > "$o/ledger.tsv"
for i in "${!tests[@]}"; do
 n=$((i+1)); name="${tests[i]}"; exe=directional_surface_cell_producer_tests
 if [[ ! -x "$r/v/bin/$exe" ]]; then
  missing=$((missing+1)); echo "MISSING_IMMUTABLE_EXECUTABLE $exe ($name)";
  printf '%s\t%s\t%s\t-\t0\t0\tNOT_EXECUTED\n' "$n" "$name" "$exe" >> "$o/ledger.tsv"
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
 [[ "$picked" == 1 && "$skipped" == 0 ]] || die "selected=$picked skipped=$skipped name=$name"
 verdict=RED; [[ "$code" == 0 && "$passed" == 1 ]] && verdict=PASS
 printf '%s\t%s\t%s\t%s\t%s\t%s\t%s\n' "$n" "$name" "$exe" "$code" "$picked" "$passed" "$verdict" >> "$o/ledger.tsv"
 executed=$((executed+1))
 if [[ "$verdict" == RED ]]; then red=$((red+1)); fi
done
(cd "$p"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/p1"
(cd "$s"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/s1"
(cd "$r/v"; find . -type f -print0 | sort -z | xargs -0 sha256sum) > "$r/v1"
cmp -s "$r/p0" "$r/p1" || die package_mutation
cmp -s "$r/s0" "$r/s1" || die source_mutation
cmp -s "$r/v0" "$r/v1" || die execution_view_mutation
(cd "$p"; sha256sum -c SHA256SUMS) > "$o/manifest-after.txt" || die postflight_manifest
echo 'package=true source=true execution_view=true selector=true' > "$o/immutability.txt"
postflight=true
echo "MEASUREMENT_COMPLETE: $executed/4 executed; $red RED; $missing missing; all independent identities attempted."
[[ "$executed" == 4 && "$missing" == 0 ]] || die 'incomplete breadth'
[[ "$red" == 0 ]]
