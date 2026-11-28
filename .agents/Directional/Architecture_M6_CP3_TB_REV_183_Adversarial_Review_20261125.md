# TB-REV-183 adversarial continuation (2026-11-25 UTC)

This continues `M6-CP3-TB-REV-183`, after the [independent review](Architecture_M6_CP3_TB_REV_183_Display_Stop_Locus_Contract_Independent_Review_20261125.md).

- **Method:** runtime-free. Source reading, plus Haiku read-only work on four questions:
  - whether the CB-204 line shift touches the gate tooling;
  - whether row 393's oracle is the same as row 978's;
  - a static classification of every remaining production sphere reader against the staged receipts measured by TB183;
  - the canonical-candidate call sites.
- **Product and test bytes:** unchanged.

## Verdict

- **Upheld:** TB183 1005/1005, and CB-204 exactly as frozen.
  - Diff `a89a68f8…4d34`, 2,544 B; preimage `9f08edd7…d690` equals HEAD; `git apply --check` passes; no source drift since `58baa583`.
- **Realigned:** the activation plan inherited from TB-REV-182 R5 (my own record) and from the CB-204 manifest's TB-REV-184 clause had three errors:
  - It specified a wrong replacement for row 393 (S2).
  - It left the activation site ambiguous (S3).
  - It did not measure which fixtures activation reaches (S4).
- **New turn:** a receipt turn is inserted before activation.

## Findings

**S1 — CB-204 is sound.**
- Row 978's explicit `false` keeps today's behavior, because the parameter default is `false`.
- Row 979 checks that the production network equals an explicit unstaged network before the old negative runs on it. So when activation later flips only this equality to "production equals staged", the negative stays meaningful.
- No name collides in row 979's scope: `productionCut` is fully replaced, and `unstaged` and `unstagedCut` are not used anywhere else in 18051–18640.
- The 8-line shift moves 70 later gated tests. No byte or expectation changes:
  - The only pinned `asserted_site` is row 216, which is in another file.
  - GUARD rows never consult a site.
  - The deferred-ledger pins are all at or below line 17295.
  - PASS output carries no line numbers. The only `SCOPED_TRACE` after 18060 (line 21710) prints only on failure.
- The receipt label `productionCut=` now prints the unstaged cut. This is acceptable for byte stability only because equality is asserted first. CB-205/206 must rename it, or record it as intentional.
- Residual risk: Review did not syntax-check CB-204. The change only adds an argument to an existing overload (`SurfaceCellTracing.h:625–631`) and declares a new local, so the risk is low. CB-204 compiles it.

**S2 — Correction: row 393 is not a certain flip, and the "assert eight carrier ends" replacement is withdrawn.**
- **What row 393's oracle reads.** It is a *whitelist* of the mutual terminal pairs 4/6 and 15/19 (`tests:17680–17762`), with partner, 7-segment, edge 0/2 and 25/27, and mutual-struck checks. Row 978's `carrierEnds` is a different predicate: any terminal contact with a carrier locus.
- **Under the staged network:**
  - The four new stops (traces 5/8/17/20) fall into the `!expectedCarrierEnd` branch. That branch asserts only `struckSegmentIndex < wall segments`, which row 978's `:17955/17961` implies.
  - Their events have Terminal and Interior roles, so they cannot change `terminalEvents`, `carrierNodes`, `hasMutualTermination`, or the `{4,6,15,19}` set.
  - The only check left unproven is the exact barycentric sum on the new contacts (`:17758`), which is a validity invariant.
- **Consequences:**
  - Row 393 joins the unchanged STOP-on-RED set.
  - Putting row 978's eight ends into `:17762` would have been **wrong**: the oracle can only ever return a subset of the whitelist.
  - Two statements are withdrawn: TB-REV-182 independent ("row393 must cover all eight exact carrier ends") and the CB-204 manifest's "row393 eight carrier ends".

**S3 — The activation site is binding; row 669 is its falsifier.**
- Every caller except `diagnose_with_arrival_priority` passes the canonical default: `make` `:6336`, `make_from_candidate` `:6409`, validation `:5830`, and both census entries `:6262/:6303`.
- Row 669 (`:17084`) requires `make`'s digest to equal the census digest.
- So the activation **must** flip the default in the `canonical_field_aligned_candidate` signature (`:5336`), not at the `make` call site. A call-site flip would break row 669, and would also make replay validation reject every staged production candidate, which is V11's warning.
- Row 669 is therefore SAFE under a signature flip and FLIPS under a call-site flip. Keep it unedited as the V11 falsifier.

**S4 — Reach is unmeasured, beyond the sphere.**
- Static classification over 14 rows:
  - **SAFE:** 844, 968, and 972 (TB183 printed 10 distinct slide carriers).
  - **SAFE given S3:** 669.
  - **SAFE (S2):** 393.
  - **UNKNOWN:** 394, 396, 397, 644, 645, 693, 694, 843, 963, 971.
- **Several UNKNOWNs are not about the sphere:**
  - 396 and 397 pick a fixture conditionally among two-ring, torus and mechanical.
  - 645 also validates the torus and two-ring.
  - 693 and 843 build the sphere through other recipes (`rails_from_atlas`; RemeshOptions `lengthRatio 0.02`, `integralSeamless=true`), so they are not the measured network.
- `stopAtLaterSlideEntry` applies to every fixture that has a later slide entry. No receipt measures which fixtures activation changes at all.
- Running the activation gate with ten unknown rows plus unknown reach invites a rejected TB with several causes mixed together.
- **Realignment:** insert a test-only reach receipt. This is the next new row, 1006:
  - For each fixture and recipe used by the production readers above, it builds `make` (unstaged) and `diagnose_with_arrival_priority(..., true)` (staged), and prints the digests, trace and event counts, and the number of later-entry stops.
  - It asserts only measured facts: the pipeline sphere differs, and its staged stop count is 4.
  - Every fixture whose digest does not change is thereby proven SAFE for all readers.
  - The rows still left UNKNOWN then get exact quantity receipts, or are frozen as corrections from data.

**S5 — Carried.**
- TB-REV-182 R1, R3, R4, R6 and V11 are carried.
- R5 is amended by S2–S4.
- P1, D-U/O3, J6, E5, CB-190 and the V5 BunnyRandom census at activation are held.
- No CP3/497/D0/H4 promotion.

## Turn sequence (supersedes TB-REV-182 adversarial steps 4–5 and the CB-204 manifest's TB-REV-184 clause)

1. **`M6-CP3-CB-204-P13-SLIDE-ENTRY-PRE-STAGING`:** exact, compile only. Unchanged.
2. **`M6-CP3-TB-EXEC-184-…-FULL-GATE`:** 1005/1005, under the CB-204 manifest rules (row 979 gains one identical 30-line block).
3. **`M6-CP3-TB-REV-184`:** accept, then freeze **CB-205**, the activation-reach receipt (test-only new row 1006, S4), with an exact fixture list taken from the reader census.
4. **CB-205 → TB-EXEC-185 → TB-REV-185:** classify each reader as SAFE, needing a correction, or needing a quantity receipt. Freeze **CB-206** activation:
   - the signature-default flip (S3);
   - exact replacements for rows 648, 978 and 979 (the receipt label included);
   - row 858 is already contract-based.
   - Every other reader stays unedited unless data proves it flips.
5. **CB-206 → TB-EXEC-186:** the V5 BunnyRandom census, plus STOP-on-RED. Then TB-REV-186.
6. **Then, one turn each:** parameter deletion, V3b, R1, O48. CB-190 stays off the critical path.

## Lessons

- Before freezing a replacement assertion, compare the oracle that will hold it with the oracle that measured the value. Two quantities named "carrier ends" were different predicates.
- When a default flip is meant to be single-source, name the exact site, and keep one equality test as the falsifier for a flip made at the wrong site.
- Measure where a behavior switch reaches (digest equality per fixture) before classifying readers. Most "unknown" readers become provably safe once their fixture is shown to be unchanged.
