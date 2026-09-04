# M3 CP4c — Current State and Forward Plan

**Purpose — DURABLE, DO NOT DELETE.** This is the single current and forward-looking record for the `M3-CP4c`
family: where the checkpoint stands, what the next turn must do, which candidates are open, and which surfaces are
deferred under their own owners. Superseded per-turn plans, reports and review records are folded into
`M3_CP4c_Consolidated_Record.md`; normative definitions live in `M3_CP4c_Frozen_Definitions.md`; selector files
remain byte-frozen alongside and are indexed by `Required_Green_Selector_Manifest.md`.

Anything in this file that is no longer current is moved to the consolidated historical record, not deleted from
the project. It may be corrected or extended; it must not be collapsed into another document or replaced by a
summary without explicit user authorization.

Last updated **2026-09-04** at `M3-CP4c-3-TB23-EXEC` closeout.

---

## 1. Where the checkpoint stands

`M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1` and **`M3-CP4c-2` are CLOSED / ACCEPTED** at selector **365**. **CP4c-3 remains OPEN.**
TB23-EXEC terminated with an orchestration-invalid runtime attempt; it did not establish a semantic ledger. TB22 therefore remains the latest authoritative runtime.

| Authority | Current value |
|---|---|
| Latest semantic runtime authority | `M3-CP4c-3-TB22` — 387 PASS / 6 RED, accepted 365/365 |
| CB25 semantic/evidence source | `e12396d471c0754b112a40272a7992020ff49ced` |
| Immutable package | `9921914679`, SHA-256 `db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7` |
| Current gate selector | selector 397, 397 identities, `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5` |
| TB23-EXEC invalid-runtime evidence | `33833497955 / 100901221113`; result `9922540133`; log `9922540522` |
| Raw invalid ledger | 342 PASS / 55 RED, accepted 327/365 — **not semantic authority** |
| Exact next | `M3-CP4c-3-TB23-REV` — independent diagnostics/review boundary |

Stable accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic M3 package count **88**.

## 2. The current frontier — no valid gate has consumed CB25 yet

**Authoritative semantic runtime remains `M3-CP4c-3-TB22`** — selector **393**, **387 PASS / 6 RED**, accepted
**365/365**, reds {366, 367, 368, 369, 370, 374}.

**`M3-CP4c-3-CB25`** produced package **`9921914679`** (`sha256:db346ad9…f444a4fe7`) from source
`e12396d471c0754b112a40272a7992020ff49ced` with frozen selector **397**
(`d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`, 397 identities; selector 393 and accepted 365
both exact prefixes). Appended ordinals **394–397** are the certificate-diagnostic witnesses.

**`M3-CP4c-3-TB23-EXEC` is ORCHESTRATION-INVALID.** The frozen plan required a fixture at the path the packaged
executable resolves before runtime; the harness checked the extracted source workspace instead, then ran 397
processes against a missing fixture tree. Its raw **342 PASS / 55 RED, accepted 327/365** are fixture-open
failures — **audit-only, not regression authority**. The package was byte-identical before and after.

**`M3-CP4c-3-TB23-REV` (CC0–CC8) located the defect and cleared CB25:**

- **The package never contains `test-data`.** `.github/workflows/agent-compile-reusable.yml` copies only the eight
  targets to `$OUT/bin` and two libraries to `$OUT/lib`; no workflow references `test-data`. Fixtures reach the
  binaries only because the **execution harness stages them** into a layout `tests/TestFixturePaths.h:51–64`
  resolves. TB18–TB22 did that staging; **TB23 omitted it**. Not a CB25 regression, not a package regression.
- **`test_data_root()` fails open** — when neither candidate path exists it returns the sibling path anyway — which
  is why a harness slip became a 397-row pseudo-ledger instead of one typed stop.
- **CB25 statically satisfies CA1 and CA3.** `certificate_side_orbit` is gone; `certifiedFaceBySourceFace` in
  `GlobalTopologyCertificateDiagnostics.h` is built from certificate evidence and assigns an owner only when a
  component's certified-face set has exactly one element; the CA3 pair loop quantifies over uncut adjacent pairs
  outside `componentBarriers` with a **satisfiable** predicate. CB24's structural zero cannot recur in this form.
  **CA2/CA4/CA5/CA6 remain runtime-unconfirmed** — the invalid run's ordinals 394–397 are not credited.

**Both branches of `M3-CP4c3-TB21-CAND-01` remain live** until a valid gate publishes the certified-face multiset.

---

## 3. Exact next turn — `M3-CP4c-3-CB26`, orchestration correction, `CD0–CD8`

**Routing changed on 2026-09-04:** an orchestration failure now routes to a **`CB` orchestration-correction turn**
followed by a re-executing `TB`, not to `REVIEW + PLAN`. Rule 4 is untouched — a *semantic* red still routes to
review. Full text in §7 of `Architecture_M3_CP4c3_TB23_Independent_Review_Record.md`.

- **CD0** — **control-plane only**; reuse package `9921914679`, source `e12396d4` and selector **397**
  byte-frozen; no rebuild, no repackage, no product/test/fixture/selector byte changed.
- **CD1** — stage the execution view so `test-data/benchmarks/fixtures` sits where `tests/TestFixturePaths.h`
  resolves it.
- **CD2** — verify a known fixture **through the consumer's own resolution rule**, not the source workspace.
- **CD3** — **fail closed**: do not start Directional runtime if CD2 fails.
- **CD4** — write the required staged layout into the frozen plan and the harness, so it stops being an
  undocumented dependency five gates relied on.
- **CD5** — preserve TB23-EXEC's evidence as invalid-attempt provenance; promote none of it.
- **CD6** — no product change; the fail-open resolver (`M3-CP4c3-TB23-REV-CAND-01`) is **out of scope** here
  because it would force a rebuild and break package reuse.
- **CD7** — audit by assumption; package census unchanged at `9c7b12f4…0359a927`.
- **CD8** — publish `M3-CP4c-3-TB23-R1`'s obligations, chiefly a **non-zero `examinedPairCount`** and the failing
  component's **certified-face multiset**, which names the live branch.

**Then `M3-CP4c-3-TB23-R1`** re-executes the frozen TB23 plan on the same immutable package. The successor after it
is an independent `M3-CP4c-3-TB23-R1-REV`. TB22-REV's prohibition stands: **no further diagnostic turn on the
projection surface** — CB25's contract is the last one.

---

## 4. Open candidates

Authoritative detail stays in `Regression_Root_Cause_Tracker.md`; this is the index.

| Candidate | State |
|---|---|
| `M3-CP4c3-TB23-REV-CAND-01` | **NEW / ACTIVE / TEST INFRASTRUCTURE / NON-GATING** — `test_data_root()` fails open, so a missing fixture tree produces a pseudo-ledger instead of one typed stop. Owner: the next Code + Build turn already changing source; **not** CB26. |
| `M3-CP4c3-TB23-REV-CAND-02` | **NEW / ACTIVE / ORCHESTRATION** — the TB23 harness omitted the execution-view staging every prior gate performed. Owner: **CD1–CD4**. Closes when a valid gate runs. |
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / ARCHITECTURAL / GATING / BOTH BRANCHES LIVE** — the source-face component construction is an unvalidated projection of a certified cellular complex. CB24's evidence was vacuous, so neither the missing-barrier nor the seed-read branch is eliminated. Owner: CA1–CA4, then TB23-REV. |
| `M3-CP4c3-TB22-REV-CAND-01` | **NEW / ACTIVE / EVIDENCE INTEGRITY** — two production diagnostics report values that cannot vary; ordinal 393 pins the vacuous contract as required-green. Owner: CA1–CA3 and CA6. |
| `M3-CP4c3-TB21-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 391 passes with the sphere half explicitly skipped. |
| `M3-CP4c3-TB20-REV-CAND-02` | **ACTIVE / FORMAL ONLY** — CB21 not reverted; Parts IV/V's written prohibition remains unlifted. Owner: a DEFN turn. |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / SYMPTOM RECORD** under `M3-CP4c3-TB21-CAND-01`. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE / DEFERRED** — folded-cone witness, ordinal 374. |
| `M3-CP4c3-DEFN-R2-CAND-01` | **ACTIVE / ARCHITECTURAL CLASS** — an exact decision with no declared input-size bound. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE** — vertex-30 evidence contract. **There is still no vertex-30 discriminator.** |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE** — prescribed sphere 368. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE / QUALITY / COVERAGE** — saturation, ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE / PRODUCT** — ordinal 370. **No correction authorized.** |
| finalize/contact fall-through | **ACTIVE** — `terminalContact` never read in `finalize_field_aligned_events`; separate owner. |

**Closed:** `M3-CP4c3-TB21-CAND-02`, `M3-CP4c3-TB10-REV-CAND-01`, `M3-CP4c3-TB19-REV-CAND-02`,
`M3-CP4c3-TB17-CAND-01`. The historical torus `UncutFaceComponentOrbitSeedNotUnique` record stays separate as the
genuine non-cellular case Part I proved.

---

## 5. Settled facts a successor must not reopen

- **`projectionFaithfulnessResidual = 0` is a structural zero** — the predicate is unsatisfiable by construction.
  It never ruled anything out and must not be cited as evidence.
- **The minority rows' certificate-face columns are the seed value re-printed.** Their agreement is a tautology.
- **Both branches of `M3-CP4c3-TB21-CAND-01` are live.**
- **The mechanical actual embedded complex is cellular** — `22 − 26 + 6 − 2 = 0`, all faces certified discs.
- **Part I §3 is an implication with a premise**; it says nothing about the source-face projection.
- **The certificate and the seed guard test different objects**; neither validates the other.
- **CB21 is not reverted**; only the formal Parts IV/V gap remains, owned by a DEFN turn.
- **371/372 and ordinal 391 are closed**; the atlas accessor is test-only and never product authority.
- **A universal chord non-crossing invariant is refuted**; `localFragmentCount` must not become a fatal oracle.
- The face walk is a validated total permutation; shared orbit ownership by the two sides of one arc is legitimate
  topology. **BS9-5 remains retired.**
- Identical typed error names across witnesses do not establish identical root cause.
- **Accepted ordinals 1–365** are the load-bearing boundary. A correction that changes any behaviour those
  identities exercise must demonstrate safety, not argue it.
- 368/369/370/374 are unchanged carried surfaces with separate owners. Vertex 30 and finalize/contact remain
  separate and untouched.

---

## 6. Resume pointer

After the durable start-of-turn checklist, load only the minimum current authority:

1. `ORIENTATION.md` — read first.
2. **this file** — current frontier and settled/candidate ownership.
3. `Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md` — frozen execution contract.
4. `Architecture_M3_CP4c3_TB23_EXEC_Artifact_Only_Test_Benchmark_Report.md` — immutable execution-integrity evidence and invalid-attempt provenance.
5. `Architecture_M3_CP4c3_CB25_Code_Build_Report.md` — exact compile/package provenance and CA0–CA9 implementation mapping.
6. `M3_CP4c_Frozen_Definitions.md` — prohibited lists and premise-bearing definitions; do not reinterpret them from failure names.
7. `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `Required_Green_Selector_Manifest.md` — selector counts, hashes, prefixes, current role.
9. `M3_CP4c_Consolidated_Record.md` only if historical lineage is needed.

Exact next is TB23-REV. It consumes the preserved execution-integrity evidence; do not continue into a correction from this record.
