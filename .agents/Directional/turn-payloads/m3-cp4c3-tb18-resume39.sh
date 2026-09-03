#!/usr/bin/env bash
set -euo pipefail
root=$1; out=$2; selector=$3
id=9904975159
run=33784755615
sha=51dc8cdfafcb7de0f50abcbf51ebbc0e89863d6b3fa6929fccd5f88472391dce
prev="$root/attempt1"
mkdir -p "$prev"
meta="$prev/artifact.json"
gh api "repos/$GITHUB_REPOSITORY/actions/artifacts/$id" > "$meta"
test "$(jq -r .name "$meta")" = 'm3-cp4c3-tb18-result-33784755615'
test "$(jq -r .workflow_run.id "$meta")" = "$run"
test "$(jq -r .digest "$meta")" = "sha256:$sha"
test "$(jq -r .expired "$meta")" = false
zip="$prev/result.zip"
gh api "repos/$GITHUB_REPOSITORY/actions/artifacts/$id/zip" > "$zip"
test "$(sha256sum "$zip"|awk '{print $1}')" = "$sha"
unzip -q "$zip" -d "$prev/result"
res="$prev/result/results.tsv"
test "$(wc -l < "$res"|tr -d ' ')" = 40
awk -F'\t' 'NR>1 && ($1!=NR-1 || $2!="PASS" || $3!=0){bad=1} END{exit bad}' "$res"
for n in $(seq 1 39); do
  row=$(sed -n "$((n+1))p" "$res")
  IFS=$'\t' read -r ord disp code bin identity rel logsha terminal <<< "$row"
  test "$ord" = "$n"; test "$identity" = "$(sed -n "${n}p" "$selector")"
  log="$prev/result/$rel"; test -f "$log"
  test "$(sha256sum "$log"|awk '{print $1}')" = "$logsha"
  grep -Fqx "Note: Google Test filter = $identity" "$log"
  grep -Fqx "[ RUN      ] $identity" "$log"
  grep -Fq "[       OK ] $identity" "$log"
done
cp "$res" "$out/results.tsv"
cp -a "$prev/result/ordinals/." "$out/ordinals/"
cp "$prev/result/fragment-evidence.raw.txt" "$out/fragment-evidence.raw.txt"
printf '%s\n' 'resume_from_attempt=33784755615' 'resumed_after_ordinal=39' 'rerun_completed_ordinals=false' "attempt1_result_sha256=$sha" > "$out/resume.env"
