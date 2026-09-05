# M3-CP4c-3-CB32 — Code + Build Report

**Turn:** `M3-CP4c-3-CB32`
**Disposition:** **COMPLETE / COMPILE GREEN / RUNTIME NOT EXECUTED / SEMANTICALLY UNACCEPTED**
**Scope owner:** CL6–CL9 of `Architecture_M3_CP4c3_TB27_Independent_Review_Record.md` (folded into
`M3_CP4c_Consolidated_Record.md` at `M3-CP4c-3-TB28-INDEPENDENT-REVIEW`)
**Exact successor:** `M3-CP4c-3-TB28` — artifact-only Test + Benchmark on selector 407.

## 1. Boundary and source authority

CB32 is the final diagnostic Code + Build turn authorized on the source-face-ownership frontier. It publishes the
source-face locus needed to choose between the two correction branches already frozen by TB27 review. It does not
apply either correction.

- implementation base: `76289afffd3c` snapshot lineage, with later compile-only corrections;
- exact semantic evidence source compiled: **`098ac7d93ea203222dd0ac50cdb68667744f0fd4`**;
- compile-trigger/control head: `3744d80b18d716f3729f4537dccaefaf18b9943d`;
- compile run/job: **`33987769718 / 101364411259`**;
- `runtimeExecution=false` throughout CB32.

The pre-CB32 semantic runtime authority remains TB27-R1 on CB31 source
`eaa0ea54355fe6877cb94024fdd3eac5f6bad9cc` / package `9961564041`: **399 PASS / 7 RED**, accepted
**365/365**, RED `[366,367,368,369,370,374,398]`. Compile success below does not replace that runtime ledger.

## 2. CL6 implementation — arc-locus census on both partitions

CB32 extends the interior-arc census so each row can publish, without truncation, the source faces crossed by the
arc and the component containing each crossed face in both relevant partitions:

- the certifier `NotTraceCut` partition;
- the failing plan `EmptyFragmentOrbits` partition.

Each crossed-face row retains the source-face semantic identity and optional component identities from both
partitions. It also carries a optional typed `SurfaceCutGraphTraceCutExclusionReason` with the frozen categories
`TerminalSlit`, `SegmentRangeInvalid`, `TraceNotFound`, `DartOutOfRange`, `FaceNotFound`, and `Other`; the optional
field remains absent when no exclusion reason applies. The same evidence surface is assembled for interior arcs belonging to the failing plan
component, so TB28 can adjudicate the failing object rather than borrowing the certifier census.

The runtime publication deliberately stops at evidence. CB32 does **not** encode the review's correction choice in
product or diagnostic control flow. TB28 must publish the rows; the following independent review applies CL8's
frozen discriminator to those observed rows.

## 3. CL7 implementation — subset publication without partition unification

The failure diagnostics now publish source-component identity for the uncut/census views alongside the existing
partition identity and equality evidence. The implementation exposes the subset/containment relation needed by the
TB28 review, but it does **not** unify the plan and certifier partitions or reinterpret their domain rules.

No owner is selected and no attribution rule is changed.

## 4. CL9 selector and test authority

CB32 establishes:

`.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_407.txt`

Authority:

- identity count: **407**;
- LF SHA-256: **`9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`**;
- selector 406 is its exact 406-line prefix, LF SHA-256
  `efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0` in the packaged CB32 source;
- the single appended identity is
  `SurfaceCutGraph.InteriorArcCensusNamesCrossedFacesAndTheirComponentsInBothPartitions`.

Ordinal 404 is strengthened in place to require the new publication/binding surface. Its identity and ordinal do
not change. The new selector identity is publication/completeness authority; it does not require a hypothesized
runtime value or choose the eventual correction.

## 5. Compile corrections

Two compile-only defects were exposed by the authoritative GitHub build and corrected surgically:

1. a census map value contains a non-default-constructible semantic id, so `std::map::operator[]` was replaced with
   `insert_or_assign`;
2. `SurfaceCutGraphUncutComponentArcFaceCensus` was directly aggregate-initialized with `sourceFace` rather than
   default-constructed and assigned later.

Neither correction changes the diagnostic decision rule or any product behavior.

## 6. Compile evidence

GitHub Actions compile authority for the exact semantic evidence source
`098ac7d93ea203222dd0ac50cdb68667744f0fd4`:

- run: **`33987769718`**;
- compile job: **`101364411259`**;
- result artifact: **`9975737868`**, name `m3-cp4c3-cb32-compile-result-33987769718`,
  SHA-256 **`16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec`**;
- persistent log artifact: **`9975738137`**,
  SHA-256 **`ba2a7c97532f328bb50742c2de31dfd106d130b4ec4533e434250bceb9ec36ae`**;
- preflight `directional_core`: **77/77** actions successful;
- full approved target build: **49/49** actions successful;
- build exit code: **0**;
- result package contains **29** files; its self-excluding `SHA256SUMS` contains **28** entries and verification passed;
- final source status: clean;
- command boundary records `turnBoundary=Code+Build-only` and `runtimeExecution=false`;
- GMP/GMPXX configuration/link evidence is present (`libgmp-dev 6.3.0`, GMP and GMPXX link verified).

Approved compiled targets are exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command, or
custom input was executed. CB32 therefore provides compile/package authority only.

## 7. Patch transport and cleanup evidence

The second compile correction was preserved before remote application and consumed by Drive apply run
**`33987631930`**, which pushed exact evidence source `098ac7d93ea203222dd0ac50cdb68667744f0fd4`.
The consumed Drive patch file was permanently deleted after successful application, and its temporary caller and
marker were retired. The compile retry then targeted the exact evidence source above.

The final CB32 documentation closeout is documentation/control-plane only and does not alter evidence provenance.
`evidence_commit` remains `098ac7d93ea203222dd0ac50cdb68667744f0fd4` regardless of later closeout/cleanup commits.

## 8. Scope audit and successor

CB32 changes no product behavior that can resolve the ownership RED by itself:

- no barrier added or removed;
- no attribution rule changed;
- no seed winner selected;
- no plan/certifier partition unified;
- no `terminalSlit` behavior changed;
- ordinal 398 remains the strong ownership-totality gate;
- accepted identities 1–365 are untouched;
- no Directional runtime or benchmark executed.

Stable regression accounting remains **44 events / 14 categories / 30 recurrences** and produced-witness debt
remains **5**. CB32 advances the compile-green, semantically unaccepted M3 package count to **93**.

**Exact next: `M3-CP4c-3-TB28`.** Execute selector 407 artifact-only on immutable artifact `9975737868` / source
`098ac7d93ea203222dd0ac50cdb68667744f0fd4`, one identity per fresh process, with no rebuild, repair, package
mutation, source/test/fixture/selector mutation, or other semantic change. TB28 must publish the CL6/CL7 evidence
needed by its mandatory independent review; that review must freeze one product correction and may not authorize a
fourth standalone diagnostic turn.
