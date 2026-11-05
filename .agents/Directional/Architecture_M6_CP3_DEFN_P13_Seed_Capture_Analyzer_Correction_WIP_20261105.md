# O32a scratch capture analyzer correction — WIP evidence

**Canonical review:** `M6-CP3-DEFN-P13-ROW-PERMUTATION-SEEDS`. This note supplements, but does not supersede, `Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_WIP_20261105.md`. It must be consolidated into the primary review before formal closeout.

## Finding and correction

The previous scratch analyzer hashed sorted source-triangle corner/barycentric entries together with 3D position/provenance. A source vertex represented from a different incident triangle therefore changed its allegedly semantic digest even when its semantic position and provenance were identical. This is a **diagnostic false-positive risk**, not independent proof that production seeds differ.

Prepared `analyze_o32a_captures_v2.py` separates `semantic` candidate identity (position/provenance/source) from `representation` identity (semantic values plus full triangle support). It rejects missing phases, mismatched per-phase seed counts, empty coverage, missing explicit termination, invalid seed-face markers, and different source-face-triple multisets. Two non-vacuity checks ran locally: chart-representation changes were detected without a semantic-digest difference; incomplete phase inventory caused a nonzero exit. **No C++ producer was built or executed.** Position/provenance identity is not itself sheet/fan/hard-rail identity, so further instrumentation remains mandatory.

## Remote scratch preparation

Previous two-file scratch-only instrumentation patch was wrapped with standard exact transport metadata and verified by `git apply --check` on source `4e151e5c139d09ecabca663ea1125d0544c32abb`. Raw Drive staging object in `My Drive/Directional-CI`: ID `1kucBxUvhEqvOVJUg4Ia04jDa1XKCU8Uo`, title `Directional__O32a__review_scratch_only.patch`, 6,791 bytes, MIME `text/x-diff`, SHA-256 `9a19f8386d3acb6a904e264f86fff4496f3dc4662bbd0da82e676a9e411427fe`. Metadata was read back. It has **not been applied or consumed**; retain until deliberately executed/retired. The source snapshot's 6,184 per-file hashes passed from the correct snapshot root.

The permanent dispatcher cannot insert a scratch patch into its immutable `compile` workload; a disposable scratch branch/caller would need a validated, strictly bounded policy exception and cleanup. None was created. Do not modify production source/tests/selector on the working branch or misreport scratch evidence as a TB gate.

## Status and required next evidence

**Review remains IN_PROGRESS**. Actual producer logs across base plus >=3 face-row permutations, exact upstream-input comparison, earliest seed-phase classification, fan/rail-safe candidate falsification, downstream trace/strand remeasurement, and the mandatory Review closeout/checklist are pending. No Code + Build successor has been frozen. This note and its companion chat evidence archive are preservation only.
