# RA-118 — CB22 compile stop reviewed: diagnostic accepted statically; occurrence formatter and name correction authorized as CB22A (2026-10-21)

**Turn:** `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE-REV`. **Input:** `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Code_Build_Stop_Record_20261021.md`; CB22 source `384961bb4` against snapshot base `49c982195` (3 files, +122). **Lines:** RP = `src/pipeline/RemeshPipeline.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `384961bb4`. **Amends:** RA-117.5 (TB23 frame fixed here) and RA-117.6 (sequence).

## RA-118.1 Stop verified

- Run [39564087707](https://github.com/akashskypatel/Directional/actions/runs/39564087707), log artifact `12329047110`: `directional_core` linked; `RemeshPipeline.cpp.o` failed with exactly two errors, RP:5274:62 and RP:5275:48, `OccurrenceId` has no member `index`. Ninja stopped; TQ was never compiled; no package; `runtimeExecution=false`.
- GCC reports every error in a translation unit, so the rest of RP, including all instantiations of the generic lambdas `isolation_binding_label` (RP:4168) and `isolation_side_site` (RP:4173), type-checks.
- The agent stopped as RA-117.5 requires. CB22 is not complete.

## RA-118.2 CB22 diff accepted statically against RA-117.5

- **Header:** `isolationSite` is the last member, default-constructed. No code brace-initializes `SurfaceOccurrenceComplexError`.
- **Part A:** TQ:1673 matches TQ:649/861. `PhaseFrontFixture::fieldTransportAtlas` (TQ:372) and the snapshot field are both `std::optional<FieldTransportAtlas>`. Static only: TQ compiles first in CB22A.
- **Side sites:** each of `side-step` (RP:4356), `side-collinear` (RP:4400), `wedge-edge` (RP:4516) and `wedge-fan` (RP:4600) passes exactly the region, seam, from and to of its `transition_between` call (RP:4348, 4392, 4507, 4591). The `cert=` lookup uses the same `isolationCertificateBySeam` key as RP:4143, so it prints the certificate the decision read.
- **Relation site** (RP:5262–5337, inside the RP:5249 reject): the clause classifier mirrors `certified_seam_direction` (RP:3889–3911) clause for clause, in order. The passing count over region/seam-matched certificates equals `seam_transport_certificate`'s (RP:4686) count over all, because the predicate itself requires the region and seam match. `valid` is therefore unreachable when the reject fires; if TB23 prints it, that is a contradiction to report, not a result.
- **Failure string** (RP:9082–9084): appended only when `isolationSite` is non-empty, which happens only on the five isolation-evidence returns. No file under `src`, `tests`, `tools` or `include` compares the `a5-side`/`a5-wedge` names exactly.
- **Invariant holds:** every addition sits after its decision and before an existing `return error;`. No A5 predicate, ordering, code or return value changed.

The clause classifier duplicates the predicate. It is accepted as rejection-only instrumentation; DEFN-ISO decides whether it is retired or folded into the predicate. Refactoring `certified_seam_direction` to return a reason is not authorized, because it is the decision function.

## RA-118.3 Root cause: wrong identity projection, not a design defect

`OccurrenceId` (`include/directional/authority/AuthorityIds.h:250–289`) is the pair (`cell()`, `canonical_corner_role()`). By design it has no numeric projection, because container position is excluded from occurrence identity. The type-correct formatter follows the existing test idiom (TQ:3454–3468): `<id.cell().index()>:<static_cast<int>(id.canonical_corner_role())>`.

## RA-118.4 Design finding: canonical names shadow storage-order names

RP:5264–5267 redeclare `firstSpan` and `secondSpan` (outer: storage-order `const SurfaceOccurrenceSideSpan *`, RP:5208/5210), and `firstOccurrence` and `secondOccurrence` (outer: storage-order `OccurrenceId` bindings, RP:5193), as canonical-order references of other types. The binding is correct, because it reads `evidence.*` and `relationId`. But this block diagnoses an order-sensitive family (`focused30:6` is a storage-swap test), and a later edit that means the outer storage-order name would silently bind to the canonical one. **Correction:** rename the four inner names to `canonicalFirstSpan`, `canonicalSecondSpan`, `canonicalFirstOccurrence` and `canonicalSecondOccurrence`, within RP:5264–5337 only.

## RA-118.5 Next unit — `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER` (Code + Build, compile only)

**Base:** `384961bb4`. **RP only:**
1. **Formatter.** On RP:5274–5275, print each relation endpoint as `<cell>:<corner>` using the RA-118.3 formatter, giving `;relation=<c>:<k>,<c>:<k>`.
2. **Names.** Apply the RA-118.4 rename within RP:5264–5337. No other edit in the block.

**Constraints:**
- The header, TQ and every other file stay byte-identical to `384961bb4`. RP differs only within RP:5264–5337.
- No line is longer than 100 columns. No A5 predicate, ordering, code or return change.

**Build:** the CB22 procedure: GMP/GMPXX, eight targets, package, `runtimeExecution=false`. **Record:** `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Code_Build_Record_20261021.md` (≤ 30 lines): source SHA; RP diff stat and changed line range against `384961bb4`; cumulative per-file stat against `49c982195`; compile run, package id, ZIP SHA-256, hash count, expiry, root-manifest and source-archive SHA-256.

**STOP and return to Review** on any compile error (TQ compiles for the first time), or any need to edit outside RP:5264–5337.

## RA-118.6 TB23 frame (fixed; CB22A-REV adds the package identity)

- **A5-ISO rows:** `focused30:20`, `24`, `25`, `26`, `27`, `28`; `selector:444`, `446`, `448`.
- **F rows:** `focused30:6`, `selector:447`.
- **Controls:** `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, and the certified-seam positive control `focused30:7` (`M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; TQ:4272; it asserts one certificate and cross-sheet transitions on that seam; GREEN in TB21).
- **Predictions:**
  - every A5-ISO row that still fails in A5 prints `;site=` with one of the five labels, and no clause is `valid`;
  - the F rows pass `atlas-binding`, and any failure is a later site;
  - every control is GREEN, with no `site=` in its output.

## RA-118.7 Unchanged and sequence

- **Accounting:** RA-117.4 unchanged. Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497, candidate evidence TB21 449/497. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
- **Sequence:** TB22-REV (RA-117) → CB22 (compile RED) → CB22-REV (RA-118) → **CB22A** → CB22A-REV → TB23 (torus A5 site harvest) → TB23-REV → DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.

Closed by RA-119 — CB22A harvested and accepted statically; CB22B authorized (`Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md`).
