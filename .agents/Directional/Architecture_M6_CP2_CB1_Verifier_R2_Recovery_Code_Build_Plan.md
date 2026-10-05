# Architecture M6 CP2 CB1 Verifier R2 Recovery Code + Build Plan

**Turn:** `M6-CP2-CB1-VERIFIER-R2`
**Owner:** RA-29 recovery from `M6-CP2-TB1-VERIFIER-REV`
**Boundary:** Code + Build only. Compile/package; **no Directional runtime**.

## Goal

Repair exactly the four Review-owned contract gaps and the three invalid CP2 negative witnesses without changing the accepted focused30, selector449, routing449, RA-28/RA-28a/RA-28b semantics, or unrelated product behavior.

## Required implementation

1. **Identity 2 / A0 source-face witness.** Replace the triangle-corner permutation with a genuinely different canonical source-face topology. Add a pre-verifier assertion that A0 `matches_source_faces` is false. Keep exact expected site `a0:source-faces`.
2. **Identity 6 / exact A6→A5 binding witness.** Tamper an always-bound field (`relationTransport`) only after proving baseline equality to the cited A5 canonical transport. Assert the mutation is non-vacuous; require `CertificatePayloadMismatch / a6:a5-binding`.
3. **Identity 7 / pinched manifoldness witness.** Use a produced fixture with two disjoint quotient-cell components; assert the disjoint pair exists; weld one quotient corner across components and require `NonManifoldTopology / a6:vertex-link`.
4. **Identity 8 / valid wrong-region witness.** Replacement `TopologyRegionId` must be an actual member of A0 `SourceTopologyRegions` and differ from the occurrence's region. Assert membership before the tamper. Preserve both sheets in-set, republish A5, re-produce A6 successfully, then require A7 `UncertifiedCrossSheetBinding / cross-sheet:wedge`.
5. **Pipeline verified-report carrier (identity 11).** Successful `AuthoritativePhaseFrontMeshResult` must carry the exact A8 `VerificationReport` that authorized projection. Preserve failure behavior. Identity 11 must run the full authoritative pipeline and assert a present/verified carried report in addition to the existing type barrier and failure-string assertion.
6. **Shared source-support kernel (identity 2).** Recompute each A5 occurrence's support from its published point with `SurfacePointSourceSupportResolver` over A0 source faces and require exact identity equality before dependent wedge/seam checks. Do not call A5/A6/A7 producer routines to derive verifier expectations. Add a non-vacuous point/support mismatch assertion.
7. **Published selected-path structure (identity 6).** Independently derive each root→target traversal over `selectedForest`; require path class/root/target validity, one certificate for every non-root member, exact ordered relation/orientation equality to the published forest path, then compose only the cited certificates. Add a tamper that breaks path structure without merely corrupting the final transform.

## Frozen stop rules

- No optimizer source change (RA-28b).
- No A5 semantic invariant expansion beyond RA-28a.
- No weakening/removal/reordering of focused30, selector449 or routing449.
- CP2 focused12 stays exactly 12 identities in the same order and names. Repairs strengthen only the existing identities 2, 6, 7, 8 and 11.
- If any accepted focused30/selector449 source semantics must change, stop for Review.
- If a required negative cannot be made non-vacuous using produced authority, stop for Review rather than forging unchecked products.
- Compile/package all standard GMP/GMPXX targets through the reusable GitHub compile workflow; `runtimeExecution=false` is mandatory.

## Required static/compile evidence

- Exact diff census identifying production versus test-only changes.
- Compile all eight standard targets with GMP/GMPXX evidence and immutable package manifest.
- No generated Directional executable may be run during this turn.
- Report the exact final source SHA, result/log artifact IDs and digests, package manifest count, focused30/focused12/selector/routing hashes, and `runtimeExecution=false`.

## Successor

If and only if R2 compiles/packages green under these frozen requirements, successor is `M6-CP2-TB1-VERIFIER-R1-EXEC`: consume that immutable package and execute focused30 + CP2-focused12 + selector449 = **491 fresh exact-filter processes**, followed by mandatory `M6-CP2-TB1-VERIFIER-R1-REV`.
