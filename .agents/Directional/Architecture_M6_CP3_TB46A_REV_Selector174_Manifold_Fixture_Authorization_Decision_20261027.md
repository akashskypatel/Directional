# RA-165 — TB46A-REV: selector174 has two invalid fixtures; line-neutral fix authorized; RA-164 H1 corrected (2026-10-27)

**Turn:** `M6-CP3-TB46A-ORCH-REV` (Review). **Decision:**
- The TB46A finding is **CONFIRMED but incomplete**. The isolated vertex 4 makes `manifoldHardSource.set_mesh` (`SurfaceCellREPackageTests.cpp:439`) throw. Fixing only that line still fails: `twoComponentSource.set_mesh` (`:569`, two isolated triangles) throws too, because TriMesh rejects any face whose edges are all boundary.
- RA-164 H1 was **wrong about the throw site** (RA-164.2 named the third face). This record corrects it.
- A narrow, **line-neutral** fixture CB covering **both** fixtures is authorized: `M6-CP3-CB46B-RP01-SELECTOR174-MANIFOLD-FIXTURE`. A scratch probe of the corrected body passes in full. TB46 is then re-run on the CB46B package.

The scratch probes below are **diagnostic only**: a local build outside the repository, not compile or TB authority under `GMP_COMPILE_POLICY.md`. No repository source, harness, manifest or workflow changed in this turn.

## RA-165.1 Verification

- **Three standalone `TriMesh` probes** (headers plus `Curvature.cpp`, C++20, `verbose=true`):
  - **A**, the current `:439` fixture (5 vertices, 2 faces): throws. DCEL: `valid vertex references out-of-range halfedge 4`. `DCEL::Vertex` defaults to `valid=true, halfedge=-1` (`DCEL.h:50–57`); `init` never assigns an unreferenced vertex (`:2993+`); `check_consistency` rejects it (`:1255–1265`).
  - **B** (4 vertices, 2 faces): OK, 5 edges.
  - **C**, the nonmanifold control (5 vertices, 3 faces): throws. DCEL: `directed edge (0, 1) appears in halfedges 0 and 6`. This is the reason RA-164 gave, but it belongs to the control line `:449`, not `:439`.
  - **D**, the `:564–569` fixture (6 vertices, 2 disjoint faces), and **E**, a single triangle: both throw. DCEL: `face is composed entirely of boundary edges 0` (check present since `8b01fe72f`, 2026-06-20).
- **History.**
  - The throw-on-inconsistency in `compute_edge_quantities` dates from `3e3603c64` (2026-06-20).
  - The 5-vertex fixture and `:439` date from `18357617a` (10-14 14:20).
  - The `:569` fixture dates from `b43fa8e95` (10-14 10:18), so **174 has thrown since 10-14 10:18**. `18357617a` (14:20) only moved the first throw up to `:439`.
  - The assertions at `:570–623` have never run. Those at `:440–568` have not run since 14:20 that day. Rail-builder commits `f026512e4`, `6d6d269dd`, `42d7915e9` and `5ecaa2acb` landed after that.
- **Rail-builder path for the overfull claim.** On a manifold source, `{0,1,2}` is rejected at `RemeshPipeline.cpp:9636` (`claimedFaces != support->second`), not at `>2U`. The `InvalidFeatureEdge`/0 oracle stays valid, but the test comment ("even if incidence metadata is truthful") is false and is corrected in the same hunk.
- **Scratch gtest probes** of the 174 body: a copy of HEAD `:289–625` plus the grid helper, linked against a local GMP-enabled `directional_pipeline` build.
  - **P0**, HEAD unchanged: `unknown file: Failure … DCEL consistency check failed`. This reproduces the TB46 row216 failure exactly, which gives the missing runtime attribution.
  - **P1**, only the `:439` fix: the same failure, now thrown from `:569`.
  - **P2**, the RA-165.3 hunks (the source diff is exactly 1+6 lines replaced 1:1; probe SHA-256 `d84c8fca…`): **`[ OK ]`**, every assertion through `:623` executed.
- **TB46A harness `5e6de03fa`** (file SHA-256 `37b01215…b0af72`):
  - It fails closed on GUARD failures, unregistered RED first sites, and early or unattributed POSITIVE failures.
  - Its regex and witness matching are sound. **Accepted.**
- **Compile run `40457083585`**: the eight-target contract is restored. The failed `directional_surface_cell_oracle_tests` attempt exposed a pre-existing break: `SurfaceCellProductOracleTests.cpp:116–117, 168–169` use lineage fields absent since at least the 10-04 squash. That target has never been in selector449, focused-12 or the TB46 manifest. It is registered as **O7** (below); it is not a TB46A regression.

## RA-165.2 Review findings (code and design)

- **F1 — RA-164 defect, owned by Review.** RA-164 decided H1 by reasoning about one `set_mesh` and did not check the others in the body. TB46A then repeated the same single-site reasoning, which is why both its diagnosis and its proposed fix were incomplete. A header-only `TriMesh` probe takes seconds and would have caught this.
  - **Rule from now on:** any static fixture-validity decision that relies on a `TriMesh`/DCEL precondition must check **every** `set_mesh` in the body, and attach a probe when the result decides a disposition.
- **F2 — RA-164.5 table was not executable.** The table allowed later-predicate POSITIVE failures, but the pinned harness counted every non-PASS POSITIVE as `control_bad`. TB46's S5 came from a Review spec defect, not from the TB agent.
  - **Rule from now on:** every outcome-table row must map to a classifier branch in the pinned harness, or the CB that freezes the table must change the harness.
- **F3 — the harness hard-codes per-identity `file:line` pins** (`PINNED_RED_SITES`, `PROVEN_LATER_POSITIVE_SITES`), while the manifest already has an `asserted_site` column.
  - The consequence: any CB that shifts a pinned line forces an S4 or S5 turn. Line-neutral edits are therefore mandatory **until** the pins move into the manifest. That migration is CB47A (RA-165.5).
  - The current pins are 201 → `REPackageTests:715`, `focused30:12` → `TQTests:5563`, cp3entry:1 → `:2916`, cp3entry:2 → `:3154`, and cp3entry:4 later failure → `:4063`.
- **F4 — the cp3entry:4 D5 later failure** (`TQTests:4063`: no reciprocal A5 OrdinaryFront with an A4 route on the square fixture) belongs in cluster E.
  - The D5 block dates from 10-06 to 10-10, before `ccc0b00ab` (10-19) changed the A4 route and endpoint shape.
  - DEFN-E decides it together with 201 and cp3entry:2. It is not a fixture fault to patch now.
- **F5 — trajectory.** No production change since TB38, and the 497 GUARD rows are green on the full gate (TB46 raw), so nothing has regressed. The open work is still clusters E and G and O4/O5, which RA-164 already identified.

## RA-165.3 CB46B — `M6-CP3-CB46B-RP01-SELECTOR174-MANIFOLD-FIXTURE`

Test-only, compile only, and **line-neutral**: `git diff --numstat` must show equal added and deleted counts (expected `12 12`) for `tests/SurfaceCellREPackageTests.cpp`. No other file may change. Allowlist:

- **F174-a** `REPackageTests:439`, one line → one line:
  `  ASSERT_NO_THROW(manifoldHardSource.set_mesh(incidenceVertices.topRows(4), incidenceFaces));`
  The 5-row `incidenceVertices` stays, because the nonmanifold control at `:446–450` needs vertex 4. `ASSERT_NO_THROW` makes any future fixture break show up as a source-attributed failure instead of `unknown file`.
- **F174-b** `REPackageTests:430–432`, three comment lines → three comment lines:
  ```
    // A two-sided hard rail is legitimate. TriMesh rejects a third triangle on
    // the same edge, so an overfull claim on a manifold source fails as a
    // claim/support mismatch; the >2-face rail guard is defence in depth.
  ```

- **F174-c** `REPackageTests:564–569`, six lines → six lines. Each component gains a second triangle; face indices 0 and 1 keep their meaning:
  ```
    Eigen::MatrixXd vertices(8, 3);
    vertices << 0., 0., 0., 1., 0., 0., 0., 1., 0., 3., 0., 0.,
                4., 0., 0., 3., 1., 0., 1., 1., 0., 4., 1., 0.;
    Eigen::MatrixXi faces(4, 3);
    faces << 0, 1, 2, 3, 4, 5, 1, 6, 2, 4, 7, 5;
    ASSERT_NO_THROW(twoComponentSource.set_mesh(vertices, faces));
  ```
- **F174-d** `REPackageTests:561–562`, comment 2 → 2 lines:
  ```
    // the real source component. Use two disconnected two-triangle patches
    // (TriMesh rejects all-boundary faces) as real, independent source owners.
  ```
- **Not allowed:** changes to assertions, `:446–459`, helpers, harness, manifest, workflows or production code.
- **Evidence:**
  - the established eight GMP/GMPXX targets (as in run `40457083585`), with `runtimeExecution=false`;
  - a record of at most 25 lines, containing the numstat and the new package ID.
- **Outcome:**

  | Observed | Successor |
  |---|---|
  | Compile OK, diff matches the allowlist, numstat line-neutral | `M6-CP3-TB46-RP01-FULL-GATE` (re-run) |
  | C2 compile error inside a hunk | Fix in that hunk, at most 2 attempts; otherwise S2 |
  | S1, S2 or S3, or a non-line-neutral diff | `M6-CP3-CB46B-RP01-SELECTOR174-MANIFOLD-FIXTURE-REV` |
  | Orchestration failure | `Turn_Cadence.md` rule 5 |

## RA-165.4 TB46 re-run — `M6-CP3-TB46-RP01-FULL-GATE`

- Artifact-only, on the **CB46B package**. The CB46 package `12708707491` and the TB46A package `12712389032` are superseded for gating.
- Harness: `5e6de03fa` (`37b01215…b0af72`), unchanged.
- Manifest: `717f4f0f…6bb087`, unchanged. Its `asserted_site` text for 174 is informational; the harness does not read it.
- The original TB46 run `40448739180` remains invalid-attempt provenance.
- **Prediction: 498 PASS / 6 RED, harness exit 0.**
  - GUARD 497/497 PASS.
  - POSITIVE 174 PASS.
  - Five pinned REDs at their pins.
  - POSITIVE cp3entry:4 is RED at the registered `:4063` (`later_positive_red=1`).
- The 174 prediction rests on scratch probe P2, the identical body, which passed `[ OK ]`. The probe is diagnostic, not gate credit.

| Observed | Successor |
|---|---|
| 498/6 exactly as predicted (harness exit 0) | `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review) |
| A pinned RED passes (harness exit 0, `unexpected_pass>0`) | Same DEFN; it records the pass |
| 174 fails anywhere, a GUARD row fails, or a RED/POSITIVE row fails at an unregistered site (harness `control_violation`) | S4 → `M6-CP3-TB46-RP01-FULL-GATE-REV` |
| Missing, duplicate or invalid rows, a checksum failure, or a harness or infra fault | S5 → `M6-CP3-TB46B-ORCH`, then re-run |

## RA-165.5 Turn sequence (frozen IDs; supersedes RA-164.6 steps 1–2)

1. `M6-CP3-CB46B-RP01-SELECTOR174-MANIFOLD-FIXTURE` (CB) → `M6-CP3-TB46-RP01-FULL-GATE` (re-run).
2. `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review). It decides cluster E (201, cp3entry:2, and cp3entry:4 D5 `:4063`) from the D1/D2 harvest, and it freezes the TB47 manifest **with** an `asserted_site` of `file:line|witness` for every RED and later-POSITIVE row.
3. `M6-CP3-CB47A-HARNESS-MANIFEST-PINS` (tool-only CB, no compile).
   - The harness reads pins from the manifest `asserted_site` and deletes the hard-coded dictionaries.
   - **Test:** an offline replay of the TB46 re-run raw logs must reproduce its verdicts and `control_violation` set byte for byte. A one-row pin mutation must fail closed.
   - It can run in parallel with step 4. Both must be finished before TB47.
4. `M6-CP3-CB47-…` (named by DEFN-E) → `M6-CP3-TB47-RP01-FULL-GATE`.
5. `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review; G: 442, `focused30:12`, cp3entry:1) → CB48 → `M6-CP3-TB48-RP01-FULL-GATE`.
6. `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review) → CB49 → TB49.
7. A green full gate → RP-01 Review. It must state the O6 scope and the **O7** owner.
8. After RP-01: the O2 DEFN, then DIAG-RETAIN.

RA-164.3 P1–P6 still apply, plus the F1 and F2 rules. Until CB47A lands, any CB touching a file with a pinned line must be line-neutral above the pin (S3 otherwise).

**O7 (new, carried):** `directional_surface_cell_oracle_tests` does not compile (`PureQuadVertexLineage.sourceComponent`/`.sourceSheet` removed). It is a contract-labelled independent-oracle target with no gate coverage. RP-01 Review decides whether CP3 needs it or it goes to M8-CP2. It must not be added to the eight-target CB contract before then.

**Accounting unchanged:**
- Stable 66/17/49, debt 1. CP2 491/491 accepted.
- TB38 490/504 candidate; TB46 attempt invalid (S5); focused TB41–TB45 await the TB46 re-run.
- Selector497 frozen. RP-01 open.
