# RA-154 — TB37-REV audit; Review-owned TB38 census manifest (2026-10-25)

**Turn:** `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY-REV-AUDIT`. **Decision:** TB37-REV **ACCEPTED** (focused D2 evidence). Its TB38 hand-off is **under-specified and is replaced** by RA-154.4. Static review plus independent artifact re-verification; no build, test or product change.

## RA-154.1 Independent verification

- TB37 result artifact `12593545901` re-downloaded: ZIP SHA-256 `d7fd939b…1348` matches; **21/21** `SHA256SUMS` OK; ledger 14 PASS / 2 RED; raw/1–3 each `[ OK ]` one test; raw/6 fails at the `Rejected` disposition assertion with actual `01` (Produced) and reason `00` (None). The TB37-REV adjudication of the harness flag is correct.
- The CB36 hunk (`SurfaceCellTracing.cpp:14937–14998`) matches RA-153.3 exactly. `git diff 038ae7fd7..HEAD` touches no `src`, `include`, `tests`, `benchmarks`, CMake or selector file, so package `12590917524` is still current.
- **Witness discrimination holds.** k=1 and k=2 assert reason 29 with **every** location −1. Only the route guard (`:15015`, no locus) produces that. The new missing-transport branch would carry face/edge loci, and `make` would give 68.

## RA-154.2 Gaps in TB37-REV

- **G1 — TB38 had no Review-issued manifest and no per-row predictions.** "Unexplained discrepancy against the 19 inherited RED" cannot be falsified. Replaced by RA-154.4.
- **G2: one root class is spread across the "untyped" queue.** Three supposedly untyped REDs are tamper oracles stranded by the atlas rewiring, the same class as 191/192. Each test builds A3 from the unmodified field, tampers only the tracing copy, expects `Rejected`, and gets `Produced`. The TB32 raw logs confirm this.

  | Selector | Area | Tamper | Expected reason | Rewired in | Twin |
  |---|---|---|---|---|---|
  | 204 | segment route | `sourceEdge = -1` (`Phase10Tests:~1631`) | — | `4ee15ada1`, 2026-10-11 | 191 |
  | 242 | isolation seam | `matching += 1` (`:3354`) | `InvalidTopologyRegionTransport` | — | — |
  | 247 | periodic | `matching += 1` (`:5236`) | `PeriodicHolonomyMismatch` | `285a50105`, 2026-10-11 | 192 |

  Under RA-152 D1 (single writer), A4 does not consume tracing containers, so these oracles cannot be satisfied by design. They are not producer defects.
  - **Real untyped remainder:** 174 (DCEL exception) and 201 (REPackage terminal vertex).
  - **Already typed:** 405 (`InvalidHardRailRouteCertificate`, `endpoint-0`) and 250 (68, see G3).
- **G3 — `selector:250` is D2-reachable and was not flagged.** TB32 `raw/292.log` shows a positive periodic composition through the atlas ending `PublishedProductRejected` (68), the same outward signature as the pre-D2 witnesses. Statically, `make`'s gauge-pin check (`:8565–8582`) compares face branch rotations, not route steps, so D2 is **not** predicted to clear it. Any first-failure drift on 250 is admissible but must be adjudicated, not credited. The `make` sub-site is unmeasured, so 250 counts as a typed-outcome periodic owner, not untyped.
- **G4 — do not fix the TB37 harness; retire it.** TB38 reuses `tools/m6_cp3_targeted_artifact_harness.sh` unchanged (SHA-256 `436f5fff…3c9a`, the TB32 harness). It classifies by GTest terminal markers and exit code, not enum text. `control_bad>0` already fails the run, and `unexpected_pass` is recorded without being fatal.
- **G5 — compare first failures by assertion, not line number.** CB34/CB35 shifted `SurfaceCellsPhase10Tests.cpp` lines (247: 4933 → ~5240). TB38-REV must match the asserted statement and its expected and actual values.

## RA-154.3 Observation O1 (recorded, no owner now)

- **Cut-route steps still publish identity.** The periodic cut-route steps (`SurfaceCellTracing.cpp:~15052`) carry `GridAutomorphism::identity()`, while observed steps now carry the raw atlas transport.
- **No consumer composes cut-step transports today.** The consumers are route equality, `periodic_relation_id`, diagnostics and the product digest.
- **The product digest moves for some products.** It hashes every step transport (`RemeshPipeline.cpp:1837–1851, 2191–2192`), so D2 changes the A4 digest of any produced periodic product with non-identity raw step transport. No test pins a literal digest, but cross-run digest equality across the CB36 boundary is **not** a regression signal.
- **Rule going forward:** any future consumer that composes `cutRoute()` transports must first source them from the atlas (RA-152.5 / DEFN scope).

## RA-154.4 TB38 binding specification

- **Package:** CB36 `12590917524` (ZIP SHA-256 `6dcbfe5a…7d03`), source `038ae7fd7`.
- **Harness:** `m6_cp3_targeted_artifact_harness.sh` unchanged, SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`.
- **Manifest:** `Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Case_Manifest.tsv`, **504 rows**, SHA-256 `b27eecb6b4f6f32fd060b8510a0cabf71f86b8fe1028dbb10c36003867dcf8c2`; `--self-check … 504` PASS.
  - Rows 1–500 carry TB32 manifest `597741…6437` identities, tests, binaries and order unchanged. Only rows 231/232/235/236/237 (`selector:189,190,193,194,195`) flip from RED to GUARD/PASS.
  - Rows 501–504 are the three TB36 witnesses plus `BalancedRouteFieldIsPureFaceGauge` (GUARD).
- **Prediction:** **490 PASS / 14 RED.** On the 497 selector that is 483/14, against TB32's 478/19.
- **The 14 RED:**
  - `focused30:12`, `cp3entry:1/2/4`, `selector:442`, 174, 201, 405: same first-failure assertion as TB32;
  - 191, 192, 204, 242, 247: the `Rejected` assertion fails with Produced;
  - 250: RED, with drift admissible.
- **STOP → TB38-REV:**
  - any GUARD row not PASS (an accepted-green or control loss);
  - any of the 14 RED passing (record it, no credit);
  - a first-failure assertion change on any RED except 250;
  - any integrity failure (hash, selection, duplicate, skip, postflight).
- **Prohibited:** any source, test, harness, manifest or selector edit; any compile; CP3 promotion.

## RA-154.5 Turn sequence

1. `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` → `…-REV`.
2. `M6-CP3-DEFN-RP01-ATLAS-INGRESS-TAMPER-ORACLE-HOMES` replaces the periodic-only DEFN. It is design only; scope 189, 190, 191, 192, 204, 242, 247; then DEFN-REV.
   - For each oracle, decide its stated property, its authoritative home, keep-identity-with-re-homed-ingress versus retire, and selector bookkeeping.
   - Also list any test outside the selector with the same pattern, e.g. `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed` (`:3580`).
   - Recommended homes:
     - 191 and 204: A3 `NonReciprocalAdjacency` negatives (E1).
     - 192 and 247: atlas-built k=1/k=2 fields, or retire as superseded by TB36 witnesses 1/2.
     - 242: an A3 negative from the tampered field.
     - 189/190: state what they discriminate under atlas ingress, or retire.
3. Test-only CB groups, compile only, each followed by its REV. One focused TB → REV after all three.
   - **A:** 191 + 204.
   - **B:** 192 + 247.
   - **C:** 242 + 189/190.
4. **Only if** TB38 still shows 68 for 250: a diagnostic turn that adds a test-side print of the `publishedProductError` code and site. Diagnostic only.
5. Owner queue in order:
   - 405 (A4 hard-rail certificate `endpoint-0`);
   - 174 and 201 (untyped);
   - `focused30:12`;
   - `cp3entry:4`;
   - `selector:442`;
   - DEFN-T1 (`cp3entry:1/2`);
   - census;
   - RP-01 Review.

   Carried: `DIAG-RETAIN`, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4 and G4-B002.

**Accounting unchanged:** stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate; TB37 14/16 focused accepted; selector497 frozen; RP-01 open.
