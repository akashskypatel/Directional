#!/usr/bin/env bash
set -euo pipefail

base_json="$RUNNER_TEMP/tb-exec-base.json"
base_script="$RUNNER_TEMP/tb_exec_base.sh"
fixed_script="$RUNNER_TEMP/tb_exec_fixed.sh"
expected_base_blob='bb068598a182e70f530288e7299491f3ca626cab'

gh api --method GET "repos/$GITHUB_REPOSITORY/contents/.agents/Directional/turn-payloads/m4-cp3-tb1-r1/tb_exec.sh?ref=$GITHUB_SHA" > "$base_json"
test "$(jq -r .sha "$base_json")" = "$expected_base_blob"
jq -r .content "$base_json" | tr -d '\n' | base64 --decode > "$base_script"
bash -n "$base_script"

python3 - "$base_script" "$fixed_script" <<'PY'
from pathlib import Path
import sys
src = Path(sys.argv[1]).read_text(encoding='utf-8')
old = "mapfile -t SOURCE_ARCHIVES < <(find \"$PACKAGE_ROOT\" -type f -name 'source.tar.gz' -print)"
new = "mapfile -t SOURCE_ARCHIVES < <(find \"$PACKAGE_ROOT\" -type f -name 'source-*.tar.gz' -print)"
if src.count(old) != 1:
    raise SystemExit(f'expected exactly one source-archive discovery expression, found {src.count(old)}')
Path(sys.argv[2]).write_text(src.replace(old, new), encoding='utf-8')
PY
bash -n "$fixed_script"
printf 'orchestrationRetry=1\nbasePayloadBlob=%s\nfix=source-archive-name-discovery-only\n' "$expected_base_blob" > "$RUNNER_TEMP/tb-orchestration-retry.txt"
exec bash "$fixed_script"
