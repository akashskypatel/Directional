# RA-112 — CB20 compile stop reviewed: source accepted statically; test accessor correction authorized as CB20A (2026-10-20)

**Turn:** `M6-CP3-CB20-RP01-GAUGE-PIN-DOMAIN-REV`. **Input:** `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md`; source commit `7dc9b89ec`, whose `src`, `include` and `tests` are identical to HEAD `fa1601d5b`. **Lines:** S = `src/geometry/SurfaceCellTracing.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `7dc9b89ec`. **Amends:** RA-111.6 item 5 (oracle tightened) and RA-111.7 (sequence).

## RA-112.1 Stop verified

- Workflow [39512680019](https://github.com/akashskypatel/Directional/actions/runs/39512680019): `compile / compile` failed.
- Its log has exactly five errors, all `no match for 'operator*'` on `DomainResult<SourceFaceId>`, at TQ:1941, 1947, 1972, 1978 and 1979. `directional_core`, which contains S, compiled.
- The agent stopped as RA-111.6 requires. No package exists, so CB20 is not complete.

## RA-112.2 S patch accepted statically against RA-111.4

- **Domain skip** (S:8559–8563): it follows the open-boundary skip and the incidence-size rejection, as specified.
- **Union** (S:8564): it precedes the A3 check. This is harmless, because a failed check returns.
- **Index safety:** `face-gauge-shape` (S:8500–8508) guarantees that the gauge count equals `face_count()`. `from_index(row, size)` therefore yields `index() == row`, so the union-find and the span loop address the same rows.
- **Span guard** (S:8584–8598): a single-face region passes. The region index is bounded by `regions().size()`, because `region()` reads `regions_.at(id.index())`.
- **Comment** (S:8509–8511): three lines. Nothing else in S changes.

This acceptance is static only; runtime acceptance belongs to TB20.

## RA-112.3 Root cause: wrong accessor, not a design defect

`DomainResult<T>` (`include/directional/authority/AuthorityIds.h:73–93`) offers `has_value()`, an explicit `operator bool` and `value()`. It has no dereference operator. S's own patch uses `faceId.value()`, as does the rest of TQ.

The test logic is sound. The correction replaces `*face0` and `*face` with `face0.value()` and `face.value()` on the five lines. The widest resulting line is 89 columns.

## RA-112.4 Static walk of the three tests

Fixture `hard_rail_fixture()`:
- 9 vertices and 8 faces, with hard carriers (1,4) and (4,7);
- left region: faces {0,1,4,5}; right region: faces {2,3,6,7}.

**Item 4: `OneFaceGaugePinNamesSourceEdge`.**
- Face 0 = (0,1,4). Edge (0,1) is open boundary and (1,4) is hard.
- (0,4) is therefore face 0's only pinned edge, and the site is exactly `edge=0,4`.

**Item 5: `RegionGaugeShiftPassesPin` — oracle tightened.**
- The right region's pinned edges (1,5), (4,5) and (5,8) keep their gauge differences. Edges (1,4) and (4,7) are hard and are skipped. The old pin rejected at one of those two edges.
- Between the span guard and the product store (S:9629), `make` never reads `sourceFaceBranchRotations` again. The outcome is therefore a product.
- RA-111.6 item 5 also accepted "an error whose site does not begin with `gauge-pin-`". Such an error could only come from a consumer reading a gauge difference across the rail, which is RA-111.2's STOP condition. That condition must turn the test red, not pass it.
- **Amendment:** the test asserts a product. On failure, its message prints `sourceAuthoritySite`.

**Item 6: `HardEdgeIsolatingFaceRejectsAtSpan`.**
- (0,4) is face 0's only non-hard two-face edge.
- The draft copies `sourceTopologyRegions` from the product, so the regions stay as built. Nothing before the pin block (S:8458–8508) reads `hardFeatureEdges`.
- The span guard takes row 0 as the first face of the left region. Row 1, also in the left region, has a different root, so the guard rejects with `gauge-pin-span;region=<left index>`.
- Face 0's region has four faces, so the single-face STOP does not apply.

## RA-112.5 Next unit — `M6-CP3-CB20A-RP01-GAUGE-PIN-TEST-ACCESSOR` (Code + Build, compile only)

**TQ only:**
1. **Accessors.** On TQ:1941, 1947, 1972, 1978 and 1979, replace `*face0` with `face0.value()` and `*face` with `face.value()`.
2. **Item 5 oracle.** In `RegionGaugeShiftPassesPin`, replace the product-or-other-error branch with one assertion that the result is a `SurfacePhaseFrontProduct`. The failure message prints the error's `sourceAuthoritySite`.

**Constraints:**
- S, `include` and every other file stay byte-identical to `7dc9b89ec`.
- No line is longer than 100 columns.

**Build:** the CB20 procedure — GMP/GMPXX, the eight targets, package, `runtimeExecution=false`. The CB20A record gives the TQ diff against `7dc9b89ec`, the package hashes, and the 48-label count carried from CB20.

**STOP and return to Review** on:
- any compile error (record the first diagnostic of each distinct error);
- any need to change a line outside items 1–2.

There is no second repair inside the turn.

**On success:** `M6-CP3-CB20A-RP01-GAUGE-PIN-DOMAIN-REV` (Review). It accepts CB20 and CB20A together, authorizes TB20 and sets its rows.

## RA-112.6 Sequence and accounting

> *Closed by RA-113 (2026-10-21): CB20A compiled green; CB20 and CB20A are accepted together and TB20 is authorized.*

- **Sequence:** CB20 (compile RED, stopped) → CB20-REV (RA-112) → **CB20A** → CB20A-REV → [TB20 → TB20-REV] → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.
