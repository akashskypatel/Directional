# M3-CP4c-3-TB39-EXEC — Artifact-Only Test + Benchmark Execution Report

**Turn:** `M3-CP4c-3-TB39-EXEC`
**Date:** 2026-09-08 UTC
**Scope:** Test + Benchmark EXEC, artifact-only; **no build and no benchmark**.
**Semantic source under test:** `8756cfe983bf7e05209f560d59a522a6b5b0674a`
**Immutable package:** artifact `10036808934` / `m3-cp4c3-cb44-result-34174521296`
**Selector:** 409 identities, SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`

## Verdict

TB39-EXEC is **mechanically valid artifact-only runtime; the frozen TB39 semantic restoration gate is GREEN; raw
review is still required before promotion**. Authoritative run/job `34177823202 / 101910682975` executed all 409
selector identities once in order through the immutable packaged harness. Raw aggregate is **402 PASS / 7 RED**,
accepted **1–365 = 365/365 PASS**, RED `[366,367,368,369,370,374,398]`, zero selection mismatch and zero timeout.
Ordinals **312/409**, protected **390/393/406/407**, and preserved **404/408** all PASS.

This exactly restores TB37's selector colour vector and even its ledger SHA-256
`058c54603bfe4663578d174531932fa9c9716e905f48a1b2feb1b26656171366`. TB38's accepted 356/357/362 and protected
390/393/406/407 losses are not present. `M3-CP4c-3-TB37` nevertheless remains the current valid semantic runtime
authority until independent `M3-CP4c-3-TB39-REV` adjudicates these raw facts; EXEC does not close/reprice candidates
or choose the counted Euler complex.

## Immutable execution provenance

- package104 build source `8756cfe983bf7e05209f560d59a522a6b5b0674a`;
- package artifact `10036808934`, provider/download SHA-256
  `8944f1d16c1cab8884e7c39da236df7a3ec5846ae1fc085b8272440c8941b519`;
- packaged source archive SHA-256 `5ec4b65a576b081b91f2f487fce9eea9b2188f72bbc969ec124135e8d986cf20`;
- packaged harness SHA-256 `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- selector409 / selector408-prefix SHA-256
  `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e` /
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- test source SHA-256 `913752b8e869b310e2bcb4d0b81a06c4231acdf0470db4427952958de7b3583b`;
- control/source snapshot run `34176955142`, exact snapshot SHA
  `b56c742db960070b73aecb0e651520fd53cb43e3`, snapshot artifact `10037597068`;
- authoritative EXEC run/job `34177823202 / 101910682975`, workflow schema validation PASS;
- result artifact `10037931111` / `m3-cp4c3-tb39-result-34177823202`, SHA-256
  `8b84cfec3b735d10511c4ca11c40d34180ed134122e885a4fd431e17d1b63b4f`;
- persistent log artifact `10037931384` / `m3-cp4c3-tb39-log-34177823202`, SHA-256
  `4353665ba54dd8cff63904388195ff3f795a03b9d1937a8dd56fce5ffdcd3a09`.

`execution-boundary.txt` records `script_exit=0`, runtime started/completed, preflight complete,
`orchestration_failure=false`, selection integrity true, timeout count 0, and every configure/compile/relink/generated
discovery/package repair/mode repair/source-test-fixture-selector mutation/benchmark flag false. Package, packaged
source, and execution-view byte+mode censuses are identical pre/post. Maximum observed RSS is 18,872 KiB at ordinal
147; observational only.

Evidence digests:

- ledger `058c54603bfe4663578d174531932fa9c9716e905f48a1b2feb1b26656171366`;
- identity map `f33cd349fd55e962f4bf22918abbccc04c8744205c62ddbe6122d8b50958290f`;
- resource summary `4b0aad273578ec8a3fdabe400db7f64f6bf7dd38a0cb11869cea549d2aab1001`;
- failure-detail table `345457abd718dcdbf29d9d05bc45a43245c2b23ea3e9d93833a4fcbc53967fa1`;
- complete Euler table `4248b86b54f466aa84eb1ca262b803d2b45f425c621b68af003411c84fb0760e`;
- decisive Euler rows `adda7d87dd2c5b91898609005ed4197c15fc10082e9c48bab002a498d499f482`;
- machine verification JSON `fd5fb484c0620cb109033606b025d5535189a375b850baf4140642fe4671cc4b`.

## Non-vacuous certificate proof

TB39 emits **513 `euler_certificate` rows across 64 selector ordinals**, including 45 accepted-prefix ordinals.
There are **zero missing-field rows**. Every one of all 513 rows satisfies all five frozen equations:

```text
chiReduced == V_int - E_int + F
chiFull == V_total - E_total + F
fullMinusReduced == chiFull - chiReduced
fullMinusReduced == X - E_one - B_int
B_int == B_int_both_sides
```

The DEFN-R6.7 empty-table failure is therefore gone as a runtime evidence problem. The machine verifier reports
`euler_certificate_row_count=513`, `euler_certificate_arithmetic_all_rows=true`, and `semantic_gate_pass=true`.
Review still owns any semantic claim about which counted complex these internally consistent rows represent.

## Decisive traced/split measurements

The decisive torus region repeatedly publishes:

```text
X=24 E_one=24 B_int=1 B_int_one_side=24 B_int_both_sides=1
V_int/E_int/F=0/23/24       chiReduced=1
V_total/E_total/F=24/48/24 chiFull=0
fullMinusReduced=-1
trace_cut_faces=0 split_fragments=24 fragment_corner_attributions=0
```

All torus certificate rows satisfy **`split_fragments == F`**. Per the frozen plan, this is a falsifier observation,
not a definition decision: the current split-fragment count does not distinguish a third complex from `F` on that
fixture.

The mechanical region at ordinal366 (also present in ordinal367) publishes:

```text
X=36 E_one=20 B_int=12 B_int_one_side=0 B_int_both_sides=12
V_int/E_int/F=100/353/250       chiReduced=-3
V_total/E_total/F=136/385/250  chiFull=1
fullMinusReduced=4
trace_cut_faces=36 split_fragments=288 fragment_corner_attributions=86
```

Thus accepted rows do **not** all have `fullMinusReduced=0`; the reduced/full readings remain discriminated. The
third-complex fields differ materially on the mechanical fixture, but EXEC does not derive or certify a replacement
Euler characteristic from them.

## Raw frontier and carried RED surfaces

Ordinals366/367 remain RED at `RegionEulerCharacteristicNotOne` / `RegionCertification`; the mechanical row again
shows reduced `-3` versus full `+1`. Separately owned ordinals 368/369/370/374/398 remain RED at their TB37 surfaces:
prescribed-sphere `CellularityNotEstablished / RotationSystemInconsistent / TraceEventPositionInvalid`; ordinary
proposal still falls to saturation; empty-network witness still returns the wrong typed result without locus;
folded-cone atlas witness remains unavailable; and ordinal398 still cannot obtain the prescribed-sphere cut graph.
They are not re-owned by TB39.

Controls remain intact: ordinal385 publishes certified ownership **300 established / 0 unavailable / 0 conflicting**;
both retired `TraceArcDoesNotSeparateItsSides` and `UncutFaceComponentOrbitSeedNotUnique` have zero occurrences.

## Regression-tracker intake

TB39 observes **no new RED ordinal and no accepted/protected green loss**. TB38 candidates record raw recovery only;
EXEC does not close them. Existing 368/369/370/374/398 owners remain unchanged.

One new **non-stable diagnostic-contract candidate** is recorded for independent review:
`M3-CP4c3-TB39-EXEC-CAND-01`. On 366/367 the typed error payload now serializes `regionChiFull=-3`, while the same
run's independently emitted certificate row proves `V_total-E_total+F=136-385+250=1` and `chiFull=1`. Static source
localizes the mismatch: after CB44 restored `certificate.eulerCharacteristic` to the reduced value,
`GlobalTopologyPlan.cpp` still assigns `failure.regionFullEulerCharacteristic = certificate.eulerCharacteristic`.
This is `RP-01 / AUTHORITY_DOMAIN_CONFLATION` on the diagnostic surface, not a gate-colour regression; no correction
is authorized in EXEC.

Stable accounting is **not repriced in EXEC**: **46 events / 14 categories / 32 recurrences**, produced-witness debt
**5**, packages **104**. TB39-REV owns candidate adjudication and promotion/repricing.

## Exact next boundary

**STOP at independent `M3-CP4c-3-TB39-REV`.** Review must consume the immutable TB39 result/log artifacts, decide
whether TB39 replaces TB37 as semantic runtime authority, adjudicate the raw recovery of the TB38 event/evidence gap,
classify `TB39-EXEC-CAND-01`, interpret the torus/mechanical third-complex measurements without assuming a formula,
update ORIENTATION and perform mandatory REVIEW document consolidation. It must not execute new runtime or patch
product/test/fixture/selector semantics before that adjudication.
