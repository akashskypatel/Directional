# M4-CP-SCALE-TB12-R3-REV — Independent Review Record

**Turn:** `M4-CP-SCALE-TB12-R3-REV`
**Type:** runtime-free independent REVIEW + PLAN
**Disposition:** **COMPLETE / GATE-A RED MECHANICALLY UPHELD / TEST-AUTHORITY PRECONDITION DEFECT / CB16 NOT FALSIFIED / PRODUCTION RETRY STILL OWED**
**Reviewed candidate:** artifact `10523132151`, compile source `a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9`
**Reviewed runtime:** `35289133532 / 105427980925`, result/log artifacts `10526001047 / 10525856300`
**Exact successor:** `M4-CP-SCALE-CB17`

## 1. Review verdict

TB12-R3's fourth Gate-A process is a real, mechanically valid RED, but it does **not** exercise the authority surface claimed by the frozen acceptance role. The test `FieldTransportAtlas.BuildsSyntheticGenusTwoAtlasWithMultiComponentBoundarySupport` reconstructs the retained closed genus-two mesh with a test-local source authority whose face component/sheet labels are all zero and whose hard-feature set is empty, then calls `FieldTransportAtlas::make(..., {}, field)`. The production S5 path instead derives source labels and authoritative hard-feature rails from production products and passes those exact hard-feature edges into both `build_source_topology_regions` and `FieldTransportAtlas::make`.

That distinction is decisive. On the connected closed retained genus-two mesh, the test-local empty-hard-feature reconstruction merges the whole source into one closed source region. The retained fixture has zero source boundary loops, and `build_source_topology_regions` crosses every interior edge that shares the same component unless it is in `hardFeatureEdges`. The failing Gate-A test nevertheless requires a published `FieldCycleKind::BoundaryLoop` with at least two closed support components. It therefore requires a boundary-row subject that its own authority construction does not establish.

The observed `CycleTransportMismatch;topologyRegion=0` is consequently evidence about that test-authored authority, not a valid discriminator for the production S5 authority. CB16's production correction is **not falsified** by this Gate-A failure. The original `RP-07` production candidate is also **not closed**, because the frozen fail-fast prevented the unchanged S5 process from running after CB16.

Review classifies a new non-stable test-authority candidate, `M4-CP-SCALE-TB12-R3-EXEC-CAND-01`, under existing `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`: **OPEN / INVALID PRECONDITION + AUTHORITY-SURFACE DIVERGENCE / TEST-ONLY CORRECTION OWNED BY CB17**.

## 2. Independent immutable-evidence re-derivation

Review reopened the candidate and runtime artifacts independently rather than accepting the EXEC report as its oracle.

- Candidate ZIP SHA-256 is `2962e2c0e4ea6dc9294d159c19c78543ddf173b5ff342436c9e89e26b4410f73`.
- Candidate root `SHA256SUMS` hashes to `61bf5fcabfb8a41f2de32b0ea7e1b3059579ecdd5ac07862cb657c46eedd3db5`; all **28/28** rows verify.
- Package metadata names exact compile source `a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9`; packaged source archive SHA-256 is `4be61bb45a1f925c4cff0cf5b6cc0b263948417b6271c43a919808f5c5133e99`.
- Selector426 is **426 unique LF rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; its first425 prefix re-hashes to `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`. Independent static ownership is **30 / 280 / 75 / 41** with no ambiguous owner. No selector427 exists.
- Retained genus-two fixture hashes independently match OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, rawfield `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.
- The result artifact outer ZIP hashes to `50ca965d0f8bd8d94a17f5a15e95bee9817abc2f1804306ebdaa9db95072895d`. Its execution ledger hashes to `1330c5002dbc4aab900e518860c8f653cfcadb0910797caf1175828dc5cda290` and contains exactly four Gate-A rows: PASS/PASS/PASS/RED, each exactly one selected process and no skip.
- The fourth raw receipt independently reproduces `FieldTransportAtlasTests.cpp:2144`, `built=false`, `code=CycleTransportMismatch;topologyRegion=0`.
- Frozen fail-fast is therefore correctly applied: Gate B is **0/1**, selector426 **0/426**, benchmark **0**. No downstream credit is available.

The Review source snapshot run `35290905539`, artifact `10525559955`, captures exact review head `1b6c57cd42c0eb919f875973529c7ea5a6d239d4` with archive SHA-256 `f6d3fb7c95ee2d1a26a1318d2e5f46ad80bc80888e878947c5a0d0a4ca9c28ec`. Relevant semantic files and retained fixture bytes are byte-identical to the candidate package source; the review-head difference is control/document state, not a new semantic implementation.

## 3. Source-level authority audit

### 3.1 The failing Gate-A test constructs the wrong source authority

`tests/FieldTransportAtlasTests.cpp` defines `make_source_authority(mesh, hardFeatureEdges={})` by assigning component `0` and sheet `0` to every face, then calling `build_source_topology_regions` with the supplied hard-feature set. The failing genus-two test uses the default empty set and separately passes `{}` into `FieldTransportAtlas::make`.

`build_source_topology_regions` crosses an interior edge whenever the two faces share the raw component and that edge is not in `options.hardFeatureEdges`. Because this test sets every face to the same component and supplies no hard features, the connected closed genus-two mesh becomes one source region. Independent fixture census and retained metadata both establish **zero boundary loops** for the closed source.

The test's later requirement to find a `BoundaryLoop` cycle with at least two closed components is therefore not preconditioned by the authority it actually supplied. Even if atlas construction reached publication, a boundary-loop row is not established by this setup.

### 3.2 Production S5 uses a materially different authority

The unchanged S5 test calls `remesh_from_raw_cross_field`, then reconstructs its independent source authority from `products.authoritativeRails` and `products.sourceSurfaceLabels`. It derives `hardFeatureEdges` with `hard_feature_edge_keys_from_rails`, supplies production component/sheet labels to `build_source_topology_regions`, and passes those same hard-feature edges into `FieldTransportAtlas::make`.

That authority is the one that prior TB12-R2 evidence measured: topology region 0 had **14 interior local vertices and one boundary loop**; boundary row14 had **34 support edges / 34 unique outgoing faces** and prematurely closed one successor orbit. The failing R3 test discards the hard-feature partition that makes that production boundary row exist. The two tests therefore do not prove or falsify the same object. This is the existing authority-domain rule in `LESSONS.md` 145 and the existing test-authority family `RP-02`, not a new regression pattern.

## 4. The positive synthetic integration witness already existed

The source immediately preceding CB16 contained a test-local mesh helper `make_two_interior_islands_disk()` and the integration identity `FieldTransportAtlas.OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow`. Its independent cycle derivation requires a `BoundaryLoop` row with exactly **6 support steps / 2 closed components** before invoking `FieldTransportAtlas::make`; after construction it compares the published order to independently derived expected support and runs the independent snapshot validator.

CB16 removed that helper/integration identity while adding the retained-genus-two test. The frozen CB16 plan had required **“a positive synthetic atlas case whose boundary algebraic row has at least two closed successor components.”** The removed disk witness matches that contract more directly than the replacement: it establishes the multi-component boundary row independently before atlas construction and does not depend on the production S5 fixture/rail partition.

Review does not grant runtime credit to the historical test body. It uses the source history only to bound the correction: CB17 can restore/adapt that synthetic witness to the current independent canonical-component oracle without changing production code or S5.

## 5. Candidate and accounting disposition

`M4-CP-SCALE-TB12-R1-EXEC-CAND-01` remains **OPEN / CORRECTION BUILT + DIRECT-CONTROL RUNTIME PROVED / ACTUAL PRODUCTION-PATH RETRY + REVIEW OWED / `RP-07` / NON-STABLE**. The first three CB16 controls passing are valid evidence for the direct component-order contract. They are insufficient to close the production candidate because S5 never executed after CB16.

New `M4-CP-SCALE-TB12-R3-EXEC-CAND-01` is **OPEN / TEST-AUTHORITY INVALID PRECONDITION + AUTHORITY-SURFACE DIVERGENCE / `RP-02` / NON-STABLE**, corrective owner `M4-CP-SCALE-CB17`. It does not add a stable event, category or recurrence because the failing test was newly authored correction authority with no accepted-green baseline.

Accepted runtime authority remains package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. `M4-CP-SCALE-DEFN-OBS-04` remains open: retained genus-two topology is proved, while admissible production atlas/A3 reachability remains unproved.

## 6. Exact bounded successor — `M4-CP-SCALE-CB17`

CB17 is a **test-authority-only Code + Build** turn. It may change `tests/FieldTransportAtlasTests.cpp` only (plus ordinary docs/control-plane mechanics). It must replace the invalid retained-genus-two Gate-A control with a synthetic integration witness that independently establishes a boundary algebraic row containing at least two closed successor components **before** atlas construction. The preferred bounded repair is to restore/adapt `make_two_interior_islands_disk()` plus `OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow` to the current `independent_canonical_component_order` / `independent_closed_component_count` oracle.

CB17 must not change `src/**`, public headers, `tests/FieldAlignedCurveNetworkTests.cpp`, `dual_cycles`, retained fixture/rawfield/metadata, CMake/benchmark semantics, selector426, or publish selector427. It must preserve the three already-valid direct Gate-A controls and compile/package the standard eight targets under GMP/GMPXX with `runtimeExecution=false`.

A compile-green CB17 candidate remains unpromoted. Its later artifact-only successor, if separately authorized after CB17, must run the four corrected Gate-A controls first, then the unchanged S5 focus, and only if those are green run selector426. Mandatory Review still precedes any S5/selector credit or candidate promotion.

## 7. Review closeout checklist

| Required closeout item | Disposition |
|---|---|
| Accepted selector prefix re-hashed | selector426 `41f4d559...b5114`; first425 `e0e0f394...90e0b`, independently re-derived |
| Decisive claims independently re-derived | candidate package, runtime ledger/raw failure, source-authority construction and S5 production authority independently reopened |
| Non-vacuity checked | invalid A4 requires `BoundaryLoop` while its own empty-hard-feature closed-source authority establishes no boundary loop; historical synthetic disk independently asserts 6 support / 2 components before atlas construction |
| Prior obligations discharged/carried | `DEFN-OBS-04`, S1 calibration, zero-transport helper audit, S2 arrival fallback and produced-witness debts carried; no S5/selector credit |
| Stable accounting | **49 / 14 / 35**, debt **5**; accepted package `10473134357` / selector426 unchanged |
| New candidates/obligations recorded | `M4-CP-SCALE-TB12-R3-EXEC-CAND-01` recorded under existing `RP-02`; `M4-CP-SCALE-TB12-R1-EXEC-CAND-01` remains open under `RP-07` |
| ORIENTATION currency line | `M4-CP-SCALE-TB12-R3-REV`, 2026-09-18 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | S5 state, genus-two authority distinction, exact CB17 owner and RP-02 authority-divergence instance updated |
| CHANGELOG | R3 Review adjudication + CB17 successor recorded |
| ROADMAP | CP-SCALE advanced through R3 Review; CB17 exact next |
| Selector manifest | n/a — no selector appended/promoted; selector426 stays byte-frozen |
| LESSONS | existing authority-object/precondition lessons and `RP-02` apply; no new general category added |
| Consolidation under CLEAN_UP_POLICY | R2 report/Review, CB16 plan/report and consumed R3 plan folded into `M4_Consolidated_Record.md`; current R3 report/Review + CB17 plan retained |
| Successor frozen | exactly one: `M4-CP-SCALE-CB17` |
| Turn boundary held | Review is runtime-free; no Directional binary/build/benchmark/discovery command executed |
| `review_check.py boundary` | required before patch publication/closeout; selector426 exact hash expected |
| STATUS lifecycle maintained | IN_PROGRESS entry written first; COMPLETE beacon deferred until after durable docs + mandatory cleanup |
| Pushed to origin, branch in sync | required after preservation patch apply and cleanup before final COMPLETE beacon |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** Accounting and accepted authority unchanged. One carried falsifier is **not yet
satisfied** and is re-issued to CB17.

### V1 — the Gate-A classification is right, and CB16 is correctly not falsified

§3.1's mechanism is the decisive one: `build_source_topology_regions` crosses an interior edge whenever the two
faces share the raw component and the edge is absent from `options.hardFeatureEdges`, so the authority the test
actually supplied cannot produce the multi-component `BoundaryLoop` it later requires. The test asserts a
condition its own setup never establishes — the same class as the torus hard-rail precondition defect at
`M4-CP3-TB3-REV` and the S4 prerequisite at `TB8-REV`, and the third time this shape has appeared in this
sequence.

That is also why **CB16 is not falsified**: the RED reports the absence of a precondition, not a failure of the
multi-component walk. §3.2's separation is the right one — the genuine multi-component case lives on the
production path that TB12-R2 measured (region 0, fourteen interior local vertices, one boundary loop, row 14 with
34 support edges), not in the Gate-A synthetic.

### V2 — the deletion catch deserves emphasis

§4 records that the source immediately preceding CB16 already contained
`make_two_interior_islands_disk()` and a positive multi-component integration identity, and that **CB16 removed
them** while adding the genus-two test — even though the frozen CB16 plan required a positive synthetic atlas case
whose support decomposes into multiple components.

A corrective turn deleting the very coverage its own plan mandated is worth stating plainly, because it is not a
drafting slip: it removed the one witness that could have demonstrated the multi-component walk works, and left
the correction resting entirely on a production path whose precondition then failed for an unrelated reason.
Declining to grant runtime credit to the historical test body while using source history to bound the correction
is exactly the right handling.

### V3 — RE-ISSUED: the component-ordering falsifier is still unsatisfied

`M4-CP-SCALE-TB12-R2-REV` §8 V2 required, alongside independent derivation, that **perturbing the producer's
component order while leaving the step multiset unchanged must be detected**. That is not yet satisfied.

The independent derivation half did land: `independent_cycle_facts(mesh, field)` builds expectations from mesh and
field rather than from producer output, which closes the self-authorizing hazard. But `IndependentCycleRow`
(`tests/FieldTransportAtlasTests.cpp:722-729`) carries `support` as a **sorted** vector and `composed` as a
`QuarterTurn`. Sorting discards order by construction, and the composed total is addition modulo four — which the
CB16 contract itself established is **order-invariant**. Neither field can distinguish one component ordering from
another.

So the canonical-ordering half of the CB16 semantic contract, items 2 and 3, is presently **unenforced by any
independent check**. The walk may well be correct; nothing would notice if it were not. This is the same
structural-presence-without-behavioural-coverage pattern as `LESSONS.md` 171, applied to an ordering rule instead
of a fixture feature: deleting the canonicalization would change no assertion.

**Required of CB17**, alongside restoring the positive synthetic witness: `IndependentCycleRow` must carry an
expected **ordered** component sequence — derived from the sparse row's support and adjacency, not from emitted
steps — and the comparison against the producer's flattened sequence must be order-sensitive. The falsifier stands
as written: perturb component order, leave the multiset unchanged, and the validator must fail.
