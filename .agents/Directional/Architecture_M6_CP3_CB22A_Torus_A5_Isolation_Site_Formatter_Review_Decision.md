# RA-119 — CB22A harvested and accepted statically; five A5-ISO rows cannot show the site; test-message routing authorized as CB22B (2026-10-21)

**Turn:** `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER-REV`. **Input:** CB22A left STATUS `IN_PROGRESS` while its compile ran, with no record; Review harvests (RA-118.5 closeout clause). Source `f082d9aeb`, compile run `39573431400`. **Lines:** RP = `src/pipeline/RemeshPipeline.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at `f082d9aeb` (TQ is identical to `384961bb4`). **Amends:** RA-118.6 (TB23 frame) and RA-118.7 (sequence).

## RA-119.1 Harvest: CB22A compile GREEN (this decision is the CB22A record)

- Source `f082d9aebce0ad72906ccbf70c37a4bf90a9ae6f`; run [39573431400](https://github.com/akashskypatel/Directional/actions/runs/39573431400), `compile / compile` success.
- Package artifact `12333216637`, ZIP SHA-256 `ecde506738eae14082e888932fb15bd462ecd9c3ee20cef36e9a66f8805f4066` (recomputed locally), expires 2026-10-28T09:05:23Z.
- 28/28 `SHA256SUMS` entries verify; root manifest SHA-256 `af8e4e421fb54828d3c558d1a0da3e2f8a7ddf3ecac56b7c7f18f9c0bd6cff8b`; source archive `29a16107bf0bfdbf627b11d3ce78ee2755612991e3316bdc54a6b0c42a506527`, whose 350 `src`/`include`/`tests` files match `f082d9aeb` byte for byte.
- Build exit 0; the eight targets; GMP/GMPXX linked; `runtimeExecution=false`; source status clean before configure, after build and final. TQ compiled for the first time with the CB22 atlas line (step 30/53).

## RA-119.2 CB22A diff accepted statically against RA-118.5

- One file, RP, +29/−23 against `384961bb4`. Every hunk lies in RP:5264–5317 (old numbering), inside the authorized RP:5264–5337. Header, TQ and every other file are identical.
- **Formatter:** each endpoint prints as `<cell>:<corner>` (RA-118.3).
- **Names:** all four inner names carry the `canonical` prefix. No bare `firstSpan`, `secondSpan`, `firstOccurrence` or `secondOccurrence` remains in the block. No added line exceeds 100 columns.
- No A5 predicate, ordering, code or return value changed. CB22 and CB22A are accepted statically as one compiled unit; runtime acceptance belongs to TB23.

## RA-119.3 Design finding: the site does not reach five A5-ISO rows

RA-117.5 routed `isolationSite` only into the pipeline failure string (RP:9082–9084). It was the reviewer's specification gap, not an implementation defect. Rows that print that string will show the site: `focused30:20` (TQ:5832), `selector:444` (TQ:7951), `selector:446` (TQ:8325) and `selector:448` (TQ:8464). Five rows call A5 directly, or assert without a message:

| Row | Fixture | Failing assertion | Output today |
|---|---|---|---|
| `focused30:24` | nonzero-Z4 witness (TQ:6184) | TQ:6008 `ASSERT_NE(a5, nullptr)` | none |
| `focused30:25` | `run_retained_torus_pipeline()` | TQ:6193 `hasArrangement` | none |
| `focused30:26` | `torus_fixture()` | TQ:6478–6483 | `A5:<code name>` |
| `focused30:27` | `torus_fixture()` | TQ:6550–6555 | `A5:<code name>` |
| `focused30:28` (G4-B002) | `torus_fixture()` via TQ:960 helper | TQ:6587 | `A5:<code name>` |

`focused30:25–28` build from `milestone-g/torus.rawfield`, not the nonzero-Z4 witness, so their site cannot be inferred from the pipeline rows. The M6 exit row G4-B002 is among them. TB23 on the CB22A package would therefore leave the exit row unexplained. The correction is test-only and message-only.

## RA-119.4 Next unit — `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES` (Code + Build, compile only)

**Base:** `f082d9aeb`. **TQ only:**
1. **Helper.** Immediately before `build_torus_closed_complex_view` (TQ:960), add `std::string a5_rejection_message(const directional::pipeline::SurfaceOccurrenceComplexProducer::ConstructionResult &construction)`. It returns `A5:unexpected-disposition` when the result holds no error; otherwise `A5:` and `surface_occurrence_complex_error_name(error->code)`, followed by `;site=` and `isolationSite` when that is non-empty.
2. **TQ:973–978:** `*firstFailure = a5_rejection_message(a5);` (covers `focused30:28` and the second `focused30:25` assertion).
3. **TQ:6008:** `ASSERT_NE(a5, nullptr) << a5_rejection_message(a5Construction);` (`focused30:24`).
4. **TQ:6193:** append `<< retained_pipeline_first_failure(run)` (`focused30:25`; its first reason is the materialization failure, which carries the site, RP:13179).
5. **TQ:6475–6483 and TQ:6547–6555:** stream `"torus downstream first rejection=" << a5_rejection_message(a5Construction)` and delete the now-unused `a5Error` declarations (`focused30:26`, `focused30:27`).

**Constraints:**
- RP, the header and every file other than TQ stay byte-identical to `f082d9aeb`.
- No assertion condition, fixture, selection or control-flow change. Existing message text is unchanged except for the `;site=` suffix and the two new messages.
- No line is longer than 100 columns.

**Build:** GMP/GMPXX, the eight targets, package, `runtimeExecution=false`. **Record:** `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Code_Build_Record_20261021.md` (≤ 30 lines): source SHA; TQ diff stat and changed ranges against `f082d9aeb`; compile run, package id, ZIP SHA-256, hash count, expiry, root-manifest and source-archive SHA-256.

**STOP and return to Review** on any compile error, or any need to edit outside TQ or to change an assertion.

## RA-119.5 TB23 frame (amends RA-118.6; CB22B-REV adds the package and issues the plan)

- **Rows (16, unchanged):** A5-ISO `focused30:20`, `24`, `25`, `26`, `27`, `28`, `selector:444`, `446`, `448`; F `focused30:6`, `selector:447`; controls `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`.
- **Measurements per A5-ISO row:** fixture, output path (pipeline or direct), site label, region, seam, `cert=` or certificate clauses.
- **Predictions:**
  - every row that fails with an isolation-evidence code shows `;site=` with one of the five labels, and no clause is `valid`;
  - `focused30:25` (pipeline) and `focused30:26/27/28` (direct) share the torus product, so they are expected to name the same label, region and seam; a disagreement is reported, not reconciled;
  - the F rows pass `atlas-binding`, and any failure is a later site;
  - every control is GREEN, with no `site=` in its output.
- **Falsifier:** an isolation-evidence code without `site=` is an instrumentation gap and a Review stop, not a result.

## RA-119.6 Unchanged and sequence

- **Accounting:** RA-117.4 unchanged. Frozen: 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, selector 497, candidate evidence TB21 449/497. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.
- **Sequence:** CB22-REV (RA-118) → CB22A (compile GREEN, harvested) → CB22A-REV (RA-119) → **CB22B** → CB22B-REV → TB23 (torus A5 site harvest) → TB23-REV → DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review.

Closed by RA-120 (`Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md`): CB22B accepted statically; TB23 issued.
