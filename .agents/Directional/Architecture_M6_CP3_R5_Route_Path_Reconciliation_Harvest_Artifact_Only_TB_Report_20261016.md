# M6 CP3 R5 — route/path reconciliation: artifact-only TB5 harvest

**Turn:** `M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST`
**Execution:** [GitHub Actions run 38831615391](https://github.com/akashskypatel/Directional/actions/runs/38831615391), successful workflow and TB harness; immutable result artifact [12017109271](https://github.com/akashskypatel/Directional/actions/runs/38831615391/artifacts/12017109271), 81,938 bytes, **recomputed outer ZIP SHA-256** `e394c4deab99e5f8dca919a7a8e61a24aa93de3ba0ed96c3c3afddc19f8b9458` (matches provider digest). Log artifact `12017213842`, provider digest `7218f112524f9ac5e3f32153e214d3735589ec310e2caca2470610fee92f621b`.
**Package:** immutable build artifact `12015849679`, independently verified ZIP SHA-256 `92a014a6d0bc4de3bef55b2ebcec2fd8c5095d3b65f90eb7bd79567dbcb10444`, semantic source `a143af264bc8b33f0e1b2f8def16b2479b53d5fc`, 28/28 source package SHA256SUMS verified before and after.
**Harness:** `.agents/Directional/tools/m6_cp3_r5_route_path_harvest_harness.sh`, executor commit `c46615bccdbc490040ef77449f20f897043e4d1f`, measured SHA-256 `64a6bb67a02ec425b8ea084ddebe3b5c0a19b14eb2b039fa6fe38987b4a3b72f`, retry event `fab558a61b8bf828e44b933105c1d55bc32b37db`.

## Verified execution boundary

Artifact ZIP digests match provider evidence; result internal `SHA256SUMS` passed. `execution-boundary.txt` records `planned=44, executed=44, red=44, missing=0, postflight=true, exit=0`, and `compile=false, relink=false, benchmarks=false, selector497=false`. `immutability.txt` confirms `package=true source=true execution_view=true selector=true`, from exact pre-/post-run byte inventories. The selected corpus is the same historical R3/A4 39-identity inventory excluding ordinal **405**, plus six supplemental identities, yielding 44 processes. All 44 ran as independent processes against the packaged producer test binary, without building, modifying binaries/fixtures, changing source or selector, or executing full TB497.

The first dispatch [38831159326](https://github.com/akashskypatel/Directional/actions/runs/38831159326) was **orchestration RED**, despite executing 44/44, because two test identities each emitted three identical diagnostic lines and the first harness incorrectly aggregated multiple occurrences into one route. Its `postflight=false` and `exit=1` are not accepted. The diagnosed harness correction now validates each diagnostic occurrence, records per-identity multiplicities, and preserves all raw evidence; no test or production assertion was changed. The corrected workflow is GREEN for the *diagnostic harvest*, not for production tests.

## Measured route/path partition

| Identity population | Count | First rejecting condition | One-step route topology key | Endpoint face rows | Actual traced boundary path face rows | Route edge incident to to-attachment face |
|---|---:|---|---|---|---|---|
| Interior controls | 23 | `not-same-interior-carrier-point` | (1,4) | 0 → 3 | 0 → 3 | **23 yes** |
| Junction A | 15 | `carrier-orientation` | (1,4) | 0 → 7 | 0 → 3 | **15 no** |
| Junction B | 6 | `carrier-orientation` | (1,2) | 0 → 7 | 0 → 3 | **6 no** |

All 44 records have `a2bProbeRouteStepCount=1`, `a2bProbeFailure=no-exact-terminal-corner`, complete canonical source-face/route evidence, and no missing expected field. Diagnostic multiplicity: 42 identities emitted one occurrence; two identities (the repeated `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement` entry) emitted **three identical occurrences** each. The harness checked every occurrence for the same route signature. Authoritative per-identity data are `route-path-reconciliation.tsv`; original process output is retained in 44 `raw/*.log` files.

**RA-68.9 falsifier not observed:** in all 21 junction cases no route step is an edge incident to the actual `to` endpoint's canonical `SourceFaceTopologyKey`; all 23 controls do have that incidence. The actual second owning-cell boundary path traverses source-face row **3**, while the paired junction corner lies in row **7**. This independently supports a **corner/path reconciliation mismatch upstream of endpoint admission**, not either candidate A or B repair. It does *not* uniquely identify the faulty producer, establish a vertex-star sector, authorize a correction, or revive the withdrawn publisher-truncation hypothesis RA-64.6. A source-face *row* and a canonical face *vertex triple* are different identity spaces; the incidence comparison is between each route **edge vertex pair** and the actual ToAttachment face **vertex triple**.

## Disposition

No producer change, acceptance credit, stable regression event, ledger recomputation, selector mutation, full TB497, or benchmark is warranted by this diagnostic-only turn. Freeze **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, selector **497**, `RP-02` **UNREACHED**; RA-61.9 and RA-64.6 withdrawn, gate C suspended. The observed 44 REDs remain a non-stable diagnostic vintage of `R4-VIN-01`, not a new stable recurrence.

The next substantive step needs a **separate independent Review/producer-definition decision** that traces actual A4 front-edge corner ownership to its own traced boundary paths. No source change or producer-definition ID is authorized here; successor remains **UNKNOWN** until frozen by repository authority.
