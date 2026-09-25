# M6-DEFN-R1-REV — Definition Review Plan

**Turn:** `M6-DEFN-R1-REV`
**Type:** mandatory runtime-free Review
**Predecessor:** `M6-DEFN-R1`
**Candidate definition:** `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md` plus amended `Architecture_M6_Frozen_Definitions.md`
**Accepted runtime authority (unchanged):** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**

## Goal

Independently adjudicate the seam-incident occurrence/wedge/side semantics frozen by `M6-DEFN-R1`. Review only; no product/test/fixture/selector/build mutation and no generated Directional runtime.

## Required independent checks

1. Re-open the exact source used by Definition or a newer exact source proven code-equivalent; do not accept the Definition narrative as authority.
2. Re-derive the split-square 2×2 wedge table, including v0, center, v2 certificate orientations and all eight endpoint-pair memberships.
3. Re-derive an interior seam-vertex chain where two seam edges share a sheet pair and decide whether certificate identity remains unique without a representative.
4. Prove or reject the exact seam-collinear side rule: incident-cell interior face must be derivable from canonical cycle plus exact source-chart orientation.
5. Check that per-wedge face bindings remove the current outgoing-face/node-face provenance mixture without changing occurrence identity.
6. Check A6 ownership boundaries: OrdinaryFront remains owner-less; HardRail/Periodic owners remain unchanged; mid-side/collinear isolation evidence belongs to wedge/side objects and A6 does no global search.
7. Check row140 compatibility: only the legacy adapter maps `OccurrenceHardRailOwnerMismatch` to `InvalidHardRailTransport`; transport-content checks remain downstream.
8. Re-hash selector449/routing449 and confirm existing six focused identities are unchanged. Confirm the seventh pre-registered identity does not already exist.
9. Re-derive stable accounting **54 / 16 / 38**, debt 1; this definition creates no runtime event.
10. Run the mandatory review boundary check and perform Review-turn document consolidation.

## Acceptance shape

If all checks pass, mark `M6-DEFN-R1` accepted, fold/index its consumed plan as allowed by `CLEAN_UP_POLICY.md`, and authorize exactly the re-scoped `M6-CP1-CB4` plan. CB4 remains runtime-free Code + Build and TB4 remains **7 + 449 = 456** artifact-only processes.

## Falsifiers

Return to a corrected Definition instead of CB4 if any of these is true: wedge authority needs a representative face; the seam-collinear rule is ambiguous; the split-square table is wrong; A6 needs a global certificate search; row140 recovery requires weakening a semantic transport check; or implementation would alter frozen identity/selector/owner semantics.
