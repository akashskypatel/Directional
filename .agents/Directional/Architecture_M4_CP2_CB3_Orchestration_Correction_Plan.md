# M4-CP2-CB3 Orchestration Correction Plan

**Status:** **AUTHORIZED AFTER TB2 ORCHESTRATION FAILURE / RUNTIME-FREE / CONTROL-PLANE-ONLY**
**Date:** 2026-09-10 UTC

## 1. Purpose

Correct the single deterministic evidence-harness defect that invalidated `M4-CP2-TB2-EXEC`, without changing or rebuilding the candidate package whose semantics were under test.

This is a Code + Build turn only because the durable workflow routes TB orchestration failure to a bounded runtime-free orchestration correction before retry. It is **not** a product/source corrective turn.

## 2. Immutable authority

Package117 remains frozen:

- semantic source: `534c0d41ae05b31e66711f21f4b4280b59f6483f`
- package artifact: `10172820820`
- package ZIP SHA-256: `e804c8a88082befcdfbc7091f64182b854f5fe8eac00861ddf1ccdb47ecb7725`
- selector382 SHA-256: `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`
- accepted selector373 prefix: `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`
- selector380 prefix: `512c9ecea76b20ed85f6d74cbbdd9c415504ffc69d37a595d68b2de78bc409c4`

No package117 byte may change in CB3.

## 3. Invalid-attempt provenance

`M4-CP2-TB2-EXEC` run/job `34532107988 / 103055098832` produced result/log artifacts `10174031432 / 10174032131`, SHA-256 `7742a385e5f2f0b408a5a946a836915abf1a636057d7b3fe0c6612f6dce88a44 / d15ecf14508eb49a154bb443df184de0daf892e9d99635d369f1d0f9d283278b`.

The attempt is `M4-CP2-TB2-EXEC-CAND-01`: **OPEN / ORCHESTRATION / NON-STABLE**. It receives no semantic credit. Preserve those artifacts as invalid-attempt provenance.

## 4. Exact defect

The preflight harness persists the execution-view census as:

`execution-view-before.tsv`

The postflight harness requires:

`execution-view-census-before.tsv`

All frozen test processes completed before that lookup, but the naming mismatch made the required postflight fail with exit `90`.

## 5. Authorized correction

Make the smallest sufficient correction: use **one canonical execution-view preflight census basename consistently**. Prefer `execution-view-census-before.tsv`, matching the existing `execution-view-census-after.tsv` postflight name.

Allowed CB3 mutation is limited to temporary/artifact-only validation harness or caller material required to enforce that name consistently and to CB3/TB-retry planning documentation.

Explicitly forbidden:

- product implementation changes;
- test-definition or assertion changes;
- fixture changes;
- selector or selector-manifest changes;
- CMake/build-semantic changes;
- package117 changes or repackaging;
- compiling/linking Directional targets;
- executing any Directional binary, test, benchmark, generated discovery, CLI, help/version command, fuzzer, or custom runtime input;
- changing durable reusable-workflow permissions.

## 6. Verifiable CB3 exit gate

CB3 closes only when all of the following are true:

1. the corrected harness/caller is syntax/schema valid;
2. static inspection proves the preflight writer and postflight reader use the same execution-view census basename;
3. no product/test/fixture/selector/CMake/package byte changed;
4. package117 authority above is unchanged and explicitly carried forward;
5. no Directional runtime, compile, relink, generated discovery, or benchmark executed;
6. invalid TB2 attempt provenance remains preserved;
7. an executable artifact-only retry plan is issued for the same package117.

A local or workflow static/file-only dry check may verify the filename contract, but it must not execute a produced Directional binary.

## 7. Exact successor

On CB3 green, exact next is **`M4-CP2-TB2-R1-EXEC`**. It re-executes the frozen TB2 semantic gate against the same immutable package117 artifact `10172820820`. It must not rebuild, repackage, repair, or semantically alter package117.
