# M3-CP4c-3-TB25 — Immutable Artifact-Only Test + Benchmark Execution Plan

**Turn:** `M3-CP4c-3-TB25-EXEC`
**Status:** **PREPARED / NOT EXECUTED**
**Owner:** Test + Benchmark EXEC only; interpretation belongs to `M3-CP4c-3-TB25-REV`.

## 1. Immutable authority

TB25 must execute the already-built CB28 artifact and nothing else.

- semantic product source: `3d7f7f9a3afad3ed37fc615a206801cf6310f4ac`;
- compile run/job: `33907875533 / 101137084443`, SUCCESS;
- immutable compile result/package artifact: `9950303110`, SHA-256
  `84c9cd0bdf5d8bef2288e1ca57d52bcec8d1503f368d82101ae10cfa14c49189`;
- compile log artifact: `9950303474`, SHA-256
  `c0401abdcab22df514a05b09084c27fb408619106652b0e4d7a02ceaaa33e204`;
- selector: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_403.txt`, **403 identities**,
  LF SHA-256 `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`;
- selector 401 is the exact first 401 lines, SHA-256
  `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`;
- accepted selector 365 remains the load-bearing prefix.

Latest semantic runtime authority before TB25 is TB24: **389 PASS / 12 RED**, accepted **365/365**, RED ordinals
`366,367,368,369,370,374,384,385,389,390,393,398`. No CB28 compile result changes those runtime facts.

## 2. Execution boundary

Execute all 403 selector identities exactly once from the immutable artifact in fresh processes using the existing
artifact-only TB harness. Record a complete identity map and PASS/RED ledger.

**Prohibited:** configure, compile, rebuild, relink, generated discovery, package repair, executable-mode repair,
source/test/fixture/selector mutation, benchmark generation from source, or substituting any branch-built executable
for the packaged artifact. Package source, packaged source, and execution-view censuses must remain equal before and
after execution. The benchmark invocation, if selected by the frozen harness, must use the benchmark binary already
inside artifact `9950303110`.

TB25-EXEC reports outcomes and evidence. It does not diagnose a new root cause, update stable regression counts,
close CP4c-3, or authorize corrective code. Those decisions belong to independent `M3-CP4c-3-TB25-REV`.

## 3. Required ledger and immutability evidence

Record at minimum:

- all 403 ordinal → identity mappings and per-ordinal PASS/RED result;
- total PASS/RED counts and exact RED ordinal set;
- accepted 1–365 result and explicit accepted-green-loss status;
- ledger SHA-256 and identity-map SHA-256;
- package artifact id/name/digest and exact semantic source SHA;
- package, packaged-source, and execution-view pre/post censuses;
- `runtime_started`, `runtime_completed`, `preflight_completed`, `execution_view_verified`, and orchestration status;
- explicit false/true values for benchmark execution and every prohibited configure/compile/relink/discovery/repair/
  mutation flag.

## 4. Required CB28 witness observations

The following are observations, not pre-credited expectations:

- **366** — record whether the production path now reaches the component/owner consistency failure and, if so, the
  exact component plus conflicting certified-owner multiset. If it fails earlier, preserve that exact boundary.
- **384 / 389 / 390** — record whether the published `cutGraph` restores their evidence subjects with their existing
  assertions unchanged. CB28 predicts this but compile success is not runtime proof.
- **385** — execute the changed-in-place ownership-status/publication diagnostic assertion and preserve its census.
- **393** — record the component-0 certified-owner multiset if publication now makes it observable; otherwise record
  the exact reason it remains unavailable.
- **398** — remains gating and was expected RED at plan freeze. Record actual owner-map totality evidence without
  weakening its assertion or treating an expected RED as accepted.
- **402** — record whether the certified-owner conflict census publishes on the production ownership-failure path,
  including row count and each emitted row.
- **403** — verify the independent unit witness names one non-barrier source edge separating two established,
  differing certified owners.
- **371 / 372 / 391 / 392 / 397 / 399 / 400 / 401** — all were prior-green and must be reported explicitly; no
  green result is assumed in advance.
- **367 / 368 / 369 / 370 / 374** — carried gating RED surfaces; report actual results without changing their owners.

## 5. CH8 discriminator to preserve as evidence

For each certified-owner conflict row, preserve the exact edge, incident faces, owners, and barrier class.
Independent review will classify the observed state as follows:

1. any differing-owner row whose independently derived `barrierClass != None` while the edge was excluded from the
   actual barrier partition ⇒ **barrier-classification / missing-barrier branch**, with the edge named;
2. differing-owner rows with `barrierClass == None` ⇒ **certified-owner mis-attribution / derivation branch**, with
   the first falsifying edge named;
3. no conflict rows while a component still has zero/unavailable or non-singleton established ownership ⇒ **third
   mechanism / incomplete ownership establishment**;
4. no conflict rows and exactly one established owner per component ⇒ **partition consistency succeeds**; any later
   failure is downstream and must be recorded separately.

EXEC must publish the raw evidence needed to choose among these branches but must not itself rewrite architecture or
close `M3-CP4c3-TB21-CAND-01`.

## 6. Successor boundary

After a valid TB25 execution, stop at **`M3-CP4c-3-TB25-REV`**, independent REVIEW + PLAN. That review must
adjudicate every RED, decide the CH8 discriminator from the raw census, update stable accounting only when evidence
justifies it, perform mandatory REVIEW document consolidation plus `ORIENTATION.md`, and authorize at most one
bounded successor.
