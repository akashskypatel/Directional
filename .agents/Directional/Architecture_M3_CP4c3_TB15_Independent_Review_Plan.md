# M3 CP4c-3 TB15 — Independent Review + Plan

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB15-REV`
Status: **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED**

## Authority

Review the completed immutable package-85 TB15 run; do not rerun any identity:

- semantic/package source **`1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4`**;
- immutable package **85** artifact `9872426500`, Actions SHA-256 `6c0e960b3f689bae2d2ef7f79c32709f63d1fefa87ecefdf6351427ac91ea0e2`;
- inner tar SHA-256 `98f5940254beaa50ec200157a3cbe6ab0ec15d8a5117006679d42684968aad08`;
- selector **381** SHA-256 `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`, selector 380 frozen prefix `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`;
- run/job **`33700074471 / 100477303760`**;
- result artifact **`9873244271`**, SHA-256 `4bf9cbbf415aecf42f08f6840890e7e21dfd18899cfec863f4984ddab618493a`;
- diagnostic-log artifact **`9873244582`**, SHA-256 `243d8867a5a2807d329d2945184ca4999622ed1ae2129fbe30026d2c40919c46`;
- selector result **372 PASS / 9 RED**, accepted 1-365 **365/365 PASS**, first red **366**;
- ordinal 366 unchanged at `RotationSystemInconsistent -> EdgeTraceSecondaryRankInvalid`, edge `25-31`, face `(25,30,31)`, attempt 0 / zero cut edges;
- exact typed branch **`SourceVertexFallbackUnbound`**;
- retained incidence: source vertex **35**, arc **19**, trace **5**, Reverse, segment interval `[0,5)`, incoming carrier none, outgoing `25-31`, contact index 2, other carrier none, face corners `{25,30,31}`;
- complete bounded census: **3 rays**, untruncated; the failing trace ray is primary 3 with secondary unavailable;
- selector 381 typed-production witness **PASS**; selector 380 **RED**; non-gating mechanical diagnostic **RED** with the same upstream reason/trace/edge;
- immutable pre/post 58-file census SHA-256 `3235eb993863ba4e4eaa88e83e46d6c4663eb5ebb6c2b4f3990ab6d1a8af6295`;
- no build/configure/relink/repair/discovery/mutation/benchmark in TB15.

Package 85 also contains a non-semantic metadata mismatch: its contract names nonexistent diagnostic `GlobalTopologyPlan.EdgeTraceSecondaryRankUnavailableIsTypedAndObservable`; the frozen TB15 plan names and executed `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`. Review it as package-authoring metadata only; do not reinterpret the semantic run or repair package 85.

## Objective

Determine the exact semantic contract behind **`SourceVertexFallbackUnbound`** at the first reached edge-locus contact node. Decide whether the retained incidence is invalid/stale producer provenance that should have been rejected earlier, or a valid contact-node trace ray for which `edge_locus_secondary_rank` uses the wrong binding datum. Freeze exactly one bounded successor from proved source/fixture invariants only. Preserve accepted 365/365, the full v47 five-ray/distinct-secondary obligation, and independently owned report-only surfaces.

This turn is static REVIEW + PLAN only. It changes no product/test/fixture/selector/build semantics and executes no Directional runtime, benchmark, configure, compile, link, or package.

## Required measures — BO0–BO8

### BO0 — Re-establish immutable evidence authority

Verify package/source/selector hashes, run/job/artifact identities, 381 fresh-process selections, 372/9 disposition, accepted 365/365 prefix, ordinal-366 locus/reason/typed branch, selector-381 PASS, non-gating diagnostic, and byte/mode-identical postflight. Prove the package metadata diagnostic-name mismatch cannot have affected the already executed selector or frozen-plan diagnostic choice. No rerun or package repair is authorized.

### BO1 — Prove the exact `SourceVertexFallbackUnbound` control path

Audit `edge_locus_secondary_rank`, its typed CB17 result, the single `EdgeTraceSecondaryRankInvalid` emitter, and the production rendering path. Establish the precise preconditions entering the fallback, what prior carrier-based alternatives were attempted or unavailable, and why this exact incidence reaches `SourceVertexFallbackUnbound`. Confirm no translation layer can fabricate the subreason.

### BO2 — Reconstruct the failing contact-node incidence end to end

Trace arc 19 / trace 5 / Reverse / `[0,5)` from the field-aligned network through contact-node construction and `build_node_loci` into the edge-locus ray. Account for source vertex 35, source face `(25,30,31)`, outgoing carrier `25-31`, absent incoming/other carrier, contact index 2, and the three-ray census. Identify which datum is the geometric/topological origin of this ray at the contact locus and which datum `trace.sourceVertex=35` represents. Do not treat those namespaces as interchangeable.

### BO3 — Decide semantic validity and the canonical binding datum

For this exact Reverse contact-node ray, determine whether a secondary rank **must exist** under the frozen rotation-system contract. If the incidence is valid, derive the canonical face-local endpoint/corner/side datum that should bind the secondary rank and prove it is orientation-correct, enumeration-invariant, and independent of fixture vertex IDs. If the incidence is invalid, prove the earliest producer invariant that should reject it rather than manufacturing a rank in rotation assembly.

A rule such as “use vertex 25/30/31 because this fixture needs it” is forbidden. The correction must follow topology/provenance semantics.

### BO4 — Audit the fallback contract across all edge-locus trace rays

Review Forward and Reverse rays, first/middle/last segments, contact nodes with only incoming or only outgoing carriers, ordinary two-carrier crossings, endpoint coincidences, canonical edge reversal, and both incident face sides. Determine exactly when source-vertex fallback is semantically meaningful and when it is a namespace error. Prove any proposed rule composes with `primary`, `secondary`, `sideRank`, mandatory/cut-edge rays, and collision detection while failing closed on true ambiguity.

### BO5 — Prove generalization and accepted-boundary safety

Identify the complete class of inputs a correction would change and the negative cases that remain rejected. Explain why accepted ordinals 1-365 cannot change except by preserving their already observed results. Freeze focused test contracts that validate the semantic rule, not this fixture's IDs or ordering. Selector 381's PASS is diagnostic-contract evidence only and must not be misused as proof of the product correction.

### BO6 — Preserve the v47 production obligation

`M3-CP4c3-TB11-CAND-01` remains open until production publishes the full five-ray v47 rotation and distinct secondary ranks for the former pair (arc 20 / trace 6 / Forward and arc 23 / trace 9 / Reverse). Selector 380 remains RED at the upstream edge-locus stop, so `M3-CP4c3-TB12-REV-CAND-01` remains runtime-open/partially discriminated. Do not infer closure from selector 381 PASS or absence of `RotationRayOrderKeyCollision`. There is still no vertex-30 discriminator.

### BO7 — Keep carried surfaces and metadata independently owned

Confirm the new branch owner does not absorb independent report-only surfaces:

- 368 prescribed-sphere `TraceEventPositionInvalid / NoCarrierMatch`;
- 369 saturation/ordinary-proposal coverage;
- 370 empty-network typed-code/locus surface;
- 371/372 shared mechanical-fixture coupling only;
- 374 folded-cone `atlasBuild=false` fixture surface;
- vertex 30 and finalize/contact remain separate.

Adjudicate `M3-CP4c3-TB15-PKG-01` as package-authoring metadata, with no semantic rerun or package-85 repair. Stable accounting changes only if tracker rules prove a distinct historical accepted regression; the current evidence itself causes no accepted-green loss.

### BO8 — Freeze exactly one bounded successor

If BO1-BO5 prove a product contract defect, freeze one bounded Code + Build successor with surgical production/test changes, compile-only acceptance, mandatory GMP/GMPXX, selector-prefix preservation, and one following immutable artifact-only TB. If they instead prove invalid/stale producer provenance, freeze the correspondingly bounded producer-side correction. If static authority is still insufficient, freeze only the minimum diagnostic CB needed to expose the missing semantic datum; do not guess.

In every case:

- no REVIEW runtime, benchmark, configure, compile, link, package, product/test/fixture/selector mutation;
- no accepted-boundary weakening, reason suppression, or fixture special-case;
- update `.agents/Directional/ORIENTATION.md` as required for every REVIEW turn;
- accepted authority remains **365/365**;
- stable accounting remains **44 events / 14 categories / 30 recurrences** unless tracker rules prove otherwise;
- produced-witness debt remains **5** and semantic package count remains **82** until a later CB produces a new immutable package.

## Exit gate

The review closes only when BO0-BO8 are discharged, the contact-node Reverse-ray semantics and canonical binding owner are proved (or a minimum diagnostic gap is proved), all inherited candidates have explicit dispositions, carried surfaces remain independently owned, and exactly one bounded successor is frozen. The typed reason identifies the branch; it does not by itself authorize a correction.
