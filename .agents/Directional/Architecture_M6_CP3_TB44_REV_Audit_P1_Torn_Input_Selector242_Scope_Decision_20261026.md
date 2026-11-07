# RA-162 — TB44-REV audit; P1-a remedy corrected (torn input); selector242 DEFN scoped (2026-10-26)

**Turn:** `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY-REV-AUDIT`. **Decision:** TB44-REV is **CONFIRMED** on its evidence, on 405 (a focused positive candidate, not promoted), and on the P1-a/P1-b diagnoses. Its P1-a corrective remedy is **REJECTED as written**: it would make a production-unreachable input pass. The successor stays the selector242 DEFN, but RA-162.4 narrows its scope. This audit made no build, runtime, test or product change.

## RA-162.1 Independent verification

- Re-downloaded result artifact `12680557878`. ZIP SHA-256 `f1b30006…6b986` matches. `SHA256SUMS` passes **11/11** (TB44 and TB44-REV both recorded "10/10"; the archive has 11 members, all valid).
- Ledger to raw-log joins are 4/4. Each log has exactly one `[ RUN ]`. Logs 1–3 each have one `[ OK ]`. Log 4 has `[ FAILED ]` and the first diagnostic `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`.
- Manifest SHA-256 `f410b550…a6a8a` was added at `2d0a23005`, an ancestor of dispatch `9eef47208`.
- No `src`, `include`, `tests` or CMake change since CB44 `c25667111`. The CB44 hunk implements RA-161.4 exactly.
- 405 non-vacuity: under accepted conformity, `target` is validated (`SurfaceCellTracing.cpp:17550–17560`) and then never read again. Grid dimensions come from the accepted boundary intervals (`:17561–17577`).
  - So the 0.5×/2.0× invariance holds by construction. The test is still a valid regression guard against target-dependence returning. It does not show any computation by which the plan "dominates" the target. **Accepted.**

## RA-162.2 Findings

- **F1 — The P1-a remedy is unsound (corrects TB44-REV).**
  - Production derives `hardFeatureEdges` from the rails: `hard_feature_edge_keys_from_rails(authoritativeRails, …)` (`RemeshPipeline.cpp:12645–12647`), assigned at `:12783`. A2b provenance is derived from the same rails (`:12775–12782`). So `hardFeatureEdges` always equals the set of rail edges.
  - 8219 inserts a **non-rail** spoke into `hardFeatureEdges` and leaves rails, provenance, A2a and A3 unchanged. That input is torn: production can never produce it.
  - With full provenance supplied, which is TB44-REV's remedy, the spoke becomes an orphan hard edge. The terminal-star walk skips it (`SurfaceCellTracing.cpp:19775`), and the test would then probably reach `missing-terminal-A3-path`.
  - A green 8219 would therefore certify a predicate on an impossible state, and it would hide F2.
  - TB44-REV left soundness as an open question for O5. This audit resolves it: **not sound**. The 8219 negative must be rebuilt as a production-reachable witness. Acceptable forms:
    - a fixture where a second rail genuinely splits the terminal star; or
    - an A3-side absence or non-reciprocity at the needed spoke, built through `FieldTransportAtlas::make` — not a caller-set override.
- **F2 — A4 hard-edge/rail cover is asymmetric (new obligation `RA-162 C1`).**
  - The checked factory (`SurfaceCellTracing.cpp:8655–8716`) checks closed-only rail sets with `closed-rail-cover`, which requires closed-chain edges == `hardFeatureEdges`.
  - When terminal contacts are present, nothing requires `hardFeatureEdges ⊆ ⋃ open/closed chain edges`. `hard_rail_open_chains_valid` (`:8394–8435`) checks only chain ⊆ hard.
  - Production can't reach this today, because both sets are derived from the same rails. But `build_surface_cell_network` and `SurfacePhaseFrontProduct::make` are public, and they accept a torn set.
  - Owner: the O5 DEFN, as a fail-closed decision: either enforce cover with a typed site, or justify an orphan hard edge as a legitimate non-rail barrier. Not on the RP-01 critical path.
- **F3 — The P1-b diagnosis is confirmed.** The forged `sourceEdges.front()` fails `rail.sourceEdges[interval] != publishedEdge` (`SurfaceCellTracing.cpp:6160–6168`) before any lookup of network ownership.
  - Caution for O5: a "network-absent" variant may already be rejected at a binding site. The differential must be pre-registered as a pair of first rejection sites, not as two verdicts.
- **F4 — Static pre-analysis of selector242 (it shapes the DEFN).**
  - `NonReciprocalSourceAdjacentIsolationSeamFailsClosed` (`Phase10Tests:3340–3391`) builds the atlas from the **unmutated** `sourceField` and mutates only `crossField.edgeTransitions[k].matching`.
  - With an atlas bound, `build_surface_cell_network(crossField)` reads only face axes and passes `nullptr` legacy containers (`SurfaceCellTracing.cpp:21181–21184`). The mutation is never observed, so A4 produces. That is TB38's `Produced` result.
  - This is RA-160's selector-190 anti-pattern. It matches TB41-REV's falsifier that a field the A3 atlas never consumes cannot force an A4 negative.
  - Separately, A3 builds reverse := forward.inverse() (`FieldTransportAtlas.cpp:2033–2036`). So a **non-reciprocal transition cannot be represented** through `matching`.
  - The only remaining A3 sensitivity to a single-edge matching change is the singularity / boundary-cycle consistency check (`FieldTransportAtlas.cpp:2091–2160`). Static reading cannot decide whether that check fires here.

## RA-162.3 P1 re-scope (supersedes the TB44-REV P1 remedy 1)

These items are carried into the O5 DEFN, with a separate test-only CB/TB/REV before any full-selector credit:

- **P1-a (8219):** replace the caller-set hard-edge override with a production-reachable missing-terminal-A3-path witness, using a split star or an A3-side absence (F1). Keep the site assertions `EndpointAttachment` and `missing-terminal-A3-path`, and keep the negative `no-exact-terminal-corner`.
  - Falsifiers: the witness mutates only a caller-supplied set that production derives; or an earlier provenance or cover site fires.
- **P1-b (7414):** unchanged from TB44-REV remedy 2, plus F3's caution.
- **RA-162 C1:** F2 cover decision. If C1 enforces cover, the current 8219 fixture would fail at that new site. This is a further reason not to apply remedy 1 as written.

## RA-162.4 DEFN `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` — required scope

Design only. No code or build. Output: one decision document of at most 80 lines, plus a CB45 specification.

- **D1 — owner of the invariant.** Name the producer that owns isolation-seam transport reciprocity in the atlas-bound architecture (A3 `make`, or the A4 certificate built at the seam). Name its observable rejection site, if one exists. Positive control: sibling `ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam` (`Phase10Tests:3270–3338`).
- **D2 — is the input representable at A3?** Decide whether `FieldTransportAtlas::make(mesh, regions, {}, mutatedField)` rejects, and with which code and site. Decide from `FieldTransportAtlas.cpp:2091–2160` if the source settles it. Otherwise, pre-register both outcomes for TB45.
- **D3 — re-home, by branch.**
  - **(A) A3 rejects:** 242 asserts the A3 rejection (code plus edge) on the mutated field, and asserts that A4 bound to the source atlas still produces.
  - **(B) A3 accepts:** the claim is not representable through `matching`. Specify a replacement that is production-reachable, keeps the same identity, and has a discriminating observable. Do not re-enter the legacy ingress, and do not weaken the test into a positive. Any change to the selector's meaning needs an explicit Review disposition.
- **D4 — coordination.** Record how this relates to DEFN-SEAM-NZ, and note the overlap with the O2/T2 identity-fallback discriminator. Do not absorb O2.
- **Falsifiers:** the proposed negative mutates a container that atlas-bound A4 never reads; the expected site cannot be observed separately; the branch choice cites no line evidence.
- **STOP → Review:** the reciprocity owner cannot be identified; or the fix needs a production change. A production change gets its own CB owner, not a test edit.

## RA-162.5 Turn sequence (frozen IDs)

1. `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV` (RA-162.4).
2. `M6-CP3-CB45-RP01-SELECTOR242-SEAM-REHOME` (test-only, compile only, per DEFN) → `…-REV` (static; issues the TB45 manifest).
3. `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY` → `…-REV`. 242 is the positive row; sibling `:3270` is a guard.
4. 174 → 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`). One owner per turn; Review assigns the IDs.
5. O4 DEFN, then O5 DEFN (now carrying P1-a re-scoped, P1-b, RA-162 C1) → REV for each.
6. Census → RP-01 Review (O6 scope statement). After RP-01: O2 DEFN (RA-160.4 + RA-161 T2).

**Carried:** DIAG-RETAIN, O1, O2, O4, O5 (+P1, C1), O6, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- Stable 66/17/49, debt 1.
- CP2 491/491 accepted.
- Candidate: TB32 481/500, TB38 490/504.
- Focused candidate: TB41 18/18, TB42 1/1, TB43 4/4, TB44 405 PASS (guards 3/4).
- Selector497 frozen. RP-01 open. The nine TB38 REDs are not counted recovered until a complete gate runs.
