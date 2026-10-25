# TB39-REV — selector250 checked-factory site independent adjudication (2026-10-25)

**Canonical turn:** `M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST-REV`. **Verdict:** accept TB39 as sound, **diagnostic-only** immutable evidence (not a product success); assign the 250 immediate rejection to **A4 checked-product source-rail provenance validation / missing fixture-owned rail provenance**, not periodic-action convention O1. **No promotion** of 250, selector497, CP3, or RP-01. Review is runtime-free; it neither repairs the positive fixture nor changes any test/product/selector/fixture.

## Independent evidence and source proof

- Re-downloaded TB39 result `12609665120` (run `40221114658`); independently computed outer ZIP SHA-256 `10af6fa84e855973e11a9fcd5c9d91e9d4bf13b97662082f658b3ec693271f06` and verified its **17/17** `SHA256SUMS`. Rejoined the seven immutable `ledger.tsv` rows to distinct `raw/1.log`…`raw/7.log` outcomes: **7/7 run, 6 GUARD PASS, selector250 one expected RED**, no skips/missing/duplicate/control bad/unexpected pass, postflight true; `compile/relink/configure/benchmark=false` in `execution-boundary.json`. This is not a re-execution of tests.
- The raw first assertion is `SurfaceCellsPhase10Tests.cpp:3666`, `Produced` expected versus `Rejected` actual; the attached checked-factory diagnostic is precisely `PublishedProductRejected publishedProductError=0 publishedProductSourceAuthorityDetail=6 site=hard-rail-contact-missing`. Source enum `SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority=0` (`include/directional/geometry/SurfaceCellTracing.h:1901`) and `SurfacePhaseFrontSourceAuthorityDetail::MissingRailTerminalContact=6` (`:1932`) are independently identified.
- In the exact snapshotted source `0c39ce0b6d3652eb49ae2be7fde2d1edac7e7d41` (semantic CB37 input `c9d7c80f6d41abdbc2ecd02de7006c7847988df8`), `SurfacePhaseFrontProduct::make` at `src/geometry/SurfaceCellTracing.cpp:8655–8661` returns that **unique site** iff `hardFeatureEdges` is nonempty and both `hardRailTerminalContacts` and `hardRailClosedChains` are empty. `publish_phase_front_result` at `:13180–13202` invokes `make`, preserves both code/detail/site, and wraps the result as `PublishedProductRejected`. This is a checked-factory authority gate before further product acceptance, not evidence of a 56–66 periodic-action error.
- The positive combined plane/cylinder/curved-disk test at `tests/SurfaceCellsPhase10Tests.cpp:3613–3669` inserts disk hard-feature edge keys (`:3650–3660`) but sets neither terminal contacts nor closed-chain provenance; it passes those default-empty options via `build_phase10_with_source_atlas` (`:5820–5841`), which builds A2/A3 but **does not** synthesize rail provenance. Contrast a real production boundary at `src/pipeline/RemeshPipeline.cpp:12774–12785` which derives terminal contacts, open chains and closed chains from authoritative rails, and the focused curved-disk fixture at `tests/SurfaceCellsPhase10Tests.cpp:2613–2626` which similarly publishes the complete provenance. Thus this test's positive acceptance assumption is under-specified at the single-writer source-rail authority boundary.
- The factory failure is mechanically proven; the missing fixture authority is the **immediate trigger**. The independent evidence does **not** prove that adding legitimate provenance makes the combined three-sheet test succeed, nor does it discharge any periodic or downstream obligations. Later failures remain unmeasured.

## Classification, falsifier, and corrective owner

**Classification:** inherited unpromoted selector250 positive-fixture authority defect (non-stable candidate; no accepted-green loss); A4 checked-factory guard operates as written. Do not relax `MissingRailTerminalContact`, inject synthetic placeholders, infer contacts from world-space proximity, or relabel the failure as a periodic route mismatch.

**Falsifiable corrective requirement (later 250-owner Code + Build turn):** derive authoritative, source-topology-consistent rail chains/contact provenance covering the combined fixture's exact hard-feature edges, with valid component/sheet and rail IDs, using the existing shared producer facility where possible. Keep the `Produced` assertion and all later positive cell/periodic/curved-disk checks unchanged; add an independent negative/removal control only if the owning plan authorizes it. A following artifact-only TB must show that the specific `hard-rail-contact-missing` rejection disappears *and* that all the remaining positive assertions actually execute; any new rejection is a new measured prerequisite, not grounds to weaken gates. This would falsify the narrow hypothesis if valid supplied provenance still produces the same missing-contact code/site. Code+Build compiles only; runtime belongs to a separate TB; independent Review must accept each.

**Sequencing:** existing RA-155.6 next **`CB38-A`** (test-only re-home of 191/204 at A3 `NonReciprocalAdjacency`) remains next, then its Review, CB39-B, CB40-C and TB40/Review, narrowed legacy/seam DEFN/Review, then the specifically bound selector250 source-rail authority owner. Do not initiate CB38-A within this review turn. Carried unchanged: O1/O2, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 and `DIAG-RETAIN`.

**Accounting:** stable 66 events / 17 categories / 49 recurrences; project debt 1. CP2 **491/491 accepted**; TB32 481/500 candidate; TB38 490/504 reviewed candidate; frozen 497 selector unpromoted; RP-01 open, RP-02 unreached. TB39's 7 cases have no broad-prefix acceptance significance. Its seven-case manifest independently hashes to `a304aeebb6bbbaadf17be43c56b080714e2e39fe4e7f8615da126f3f0150cc61`. The accepted 491-row selector is untouched; a new selector/prefix comparison is n/a because this review made no selector change and the seven-case diagnostic manifest is not an acceptance selector.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no selector mutation or new acceptance; frozen 497 left byte-identical in snapshotted source; seven-case manifest independently hashed above. |
| Decisive claims independently re-derived | 17/17 ZIP member hashes, 7 distinct raw/log outcomes, exact enum values and factory guard/source-options chain. |
| Non-vacuity checked | The failing positive `Produced` assertion was reached; controls each ran exactly one and passed; six guards do not prove positive 250. Factory predicate is falsifiable by source-owned contact or closed-chain data. |
| Prior obligations discharged/carried | RA-155.6 site measurement independently classified; 250 positive not discharged. CB38-A/B/C, O1/O2, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 and DIAG-RETAIN carried. |
| Stable accounting | 66/17/49, debt1; CP2 491/491 accepted; TB38 490/504 candidate; 497 frozen; no CP3 promotion. |
| New candidates/obligations recorded | Selector250 source-rail fixture-provenance correction assigned to later 250 owner; tracker updated. |
| ORIENTATION currency line | 2026-10-25 TB39-REV decision; current CB38-A successor. |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7, §8 revised in place; §4 n/a: fixture list/witness classification unchanged. |
| CHANGELOG | Review entry added. |
| ROADMAP | M6-CP3 boundary refreshed; checkpoint status unchanged. |
| Selector manifest | n/a — no selector added or accepted. |
| LESSONS | Existing lessons §2 non-vacuity, §3 single-writer identity, §5 diagnostics cited; no new generally applicable lesson. |
| Consolidation under CLEAN_UP_POLICY | n/a — TB39 report retains raw artifact and is still current measurement authority; prior RA-155 remains active; deleting either would lose live evidence. |
| Successor frozen | `CB38-A` exactly as RA-155.6; test-only 191/204 A3 source-edge tamper and unweakened typed negative; after CB38-A, mandatory independent Review. |
| Turn boundary held | Static review only; no runtime, recompilation, product/test/fixture/selector source mutation. |
| review_check.py boundary | Execute against prepared documentation patch and report actual result before final beacon. |
| `STATUS` lifecycle maintained | Entry beacon written; final direct beacon only after durable record publication. |
| Pushed to origin, branch in sync | Publication and remote verification required before final beacon; not claimed by this prepared record. |
