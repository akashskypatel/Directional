# M3 CP4c-3 TB10 — Artifact-Only Test + Benchmark Plan

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB10`
Status: **FROZEN SUCCESSOR PLAN / NOT EXECUTED**

## Validation identity

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Evidence source: **`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`**.
- Compile run/job: **`33581576670 / 100096794713`**.
- Raw compile artifact **`9828721201`**, Actions SHA-256
  **`53b40433f2b63c551d07ee5fdf7dd9a67c278825b7c3f8b2a1aa0ca1b9194155`**.
- Immutable mode-preserving package **80**:
  run/job **`33582280392 / 100098880900`**,
  artifact **`9828786744`**, Actions SHA-256
  **`f4643d0535684f81de5afc9660ef40f2ffb941d1c540b91026225681314fe20e`**.
- Inner `package80.tar.gz` SHA-256:
  **`4e8303489adb46528ae0a92c7ecf9dae65f0cbd57527740d845d318c65af02ce`**.
- Packaged source archive SHA-256:
  **`026a8b1efa2dc85fe2b474e0e64657bf8f997aee5b49f274c7c0c69d279fd18a`**.
- Frozen selector 374 SHA-256:
  `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`.
- Frozen selector 375 SHA-256:
  `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0`.
- Frozen selector 376 SHA-256:
  `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`.
- Execution selector **377** SHA-256:
  **`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`**;
  selector 376 must be its unchanged 376-line prefix.
- New identity 377:
  `ResolvedBranchCorrection.BarrierAbsorbedMechanicalTerminationUsesNetworkNodeWithoutPort`.
- Benchmark: **none**; correctness validation only.

Package 79 and earlier packages are superseded as TB10 inputs.

## Objective

Consume CB12's immutable package without rebuilding it. Re-prove the accepted 365-prefix, determine whether the
ordinal-366 mechanical path clears the TB9 singularity-port ownership defect, execute every already-authorized
report-only identity, and prove the new mechanical barrier-absorbed termination witness. TB10 validates; it does not
correct product behavior.

## Immutable preflight — before any Directional runtime

1. Download package artifact `9828786744` directly and verify its Actions digest and exact inner tar
   digest above.
2. Extract `package80.tar.gz` with normal `tar` extraction preserving archived executable mode bits. Do not use
   Python `zipfile.extractall` for executable payloads and do not `chmod`, rebuild, regenerate, relink, or repair the
   package.
3. Verify every internal `SHA256SUMS` entry, exact source commit/archive digest, clean source-status records,
   `runtimeExecution=false`, `packageRepair=false`, `exactArithmeticBackend=GMP`, preflight/build exit code `0`, and
   link evidence containing both GMPXX and GMP.
4. Require exactly 27 package-relative fixture files and exactly six packaged `directional_*` executables with their
   archived executable mode intact.
5. Recompute selectors 374–377 from packaged source. Require the exact hashes above, cardinalities 374/375/376/377,
   uniqueness, and exact prefix relations `374=head(375,374)`, `375=head(376,375)`, `376=head(377,376)`.
6. Map every selector-377 identity to exactly one packaged executable before runtime. A zero-selected or duplicate-
   selected identity is orchestration failure, never semantic evidence.
7. Record a package-tree byte/mode census for postflight comparison.
8. No configure, compile, relink, generated discovery, source/test/fixture/selector mutation, package repair, or
   benchmark is permitted.

Any mismatch is orchestration failure. Stop before runtime and do not claim a semantic result.

## Ordered execution — selector 377 from ordinal 1

Execute selector **377 from ordinal 1**, one exact identity per fresh process. Gate credit stops at the first
semantic red. After the first red, execute every remaining already-authorized identity through 377 exactly once as
report-only/diagnostic evidence with zero gate credit; that remainder must never alter `first_red_ordinal`, accepted
prefix count, or acceptance.

### BD9 mandatory discriminators

TB10 must resolve all five before closeout:

1. **Accepted prefix:** ordinals **1–365 remain 365/365 PASS**. Any red in this prefix invalidates inherited accepted
   authority and is new gating evidence.
2. **TB9 ownership defect must move or clear:** ordinal 366 must **not** report
   `SingularityTerminationPortOwnershipMismatch` at `traceSeedVertex=47;traceSeedSingularity=5`. Repetition of that
   same condition **and** seed falsifies CB12's correction.
3. **If ordinal 366 remains red, it must be genuinely different:** preserve the exact new error condition, locus,
   seed, and trace provenance. Do not reinterpret a renamed/rendered equivalent of the old ownership failure as
   progress.
4. **Mechanical node ownership:** identity 377 must prove terminal vertex **v36**, `BarrierAbsorbed` policy, a
   mandatory-barrier incidence, no synthesized singularity port, fail-closed missing-node rejection, and positive
   `SingularityTermination` publication at v36's network node.
5. **Candidate closure:** `M3-CP4c3-TB9-REV-CAND-01` closes only if discriminators **1, 2, and 4** all pass. If any
   fails, retain the candidate and route the exact evidence to review/planning.

**No vertex-30 discriminator is authorized.** CB12 does not prove the corrected mechanical path reaches vertex 30;
`M3-CP4c3-TB6-CAND-01` remains active unless later runtime independently reaches and adjudicates it.

## Gate and report-only accounting

- Ordinals **1–365** carry inherited accepted gate credit and must remain green.
- Ordinal **366** is the current gating frontier. Record its organic result before interpreting later identities.
- After a first red, run ordinals **367–376** exactly once report-only with zero gate credit. Preserve pre-classified
  sphere, saturation, empty-network/370, mechanical, folded-cone, and diagnostic dispositions unless emitted
  evidence actually changes.
- Ordinal **377** executes exactly once with zero inherited gate credit. It is the CB12 regression witness and must
  satisfy discriminator 4.
- If ordinal 366 passes, continue sequentially and record the next organic first red; do not close CP4c-3 merely
  because the old first red moved.

Do not impose an elapsed-time watchdog on the complete selector execution and do not partition/retry/stitch partial
semantic runs to manufacture completion.

## Regression/accounting review

Before TB10 closes, categorize every observed regression/candidate in `Regression_Root_Cause_Tracker.md` and record
root-cause analysis required by project policy. `M3-CP4c3-TB9-REV-CAND-01` may close only under BD9. A moved first red
is new semantic evidence, not automatic stable-event promotion. Preserve stable totals unless tracker criteria and
the evidence justify a change.

## Immutable postflight

After all authorized runtime, re-run the internal manifest; re-check source archive, selector hashes, binary hashes
and executable modes; compare the package-tree byte/mode census; and prove configure/compile/relink/repair/generated
discovery/product/test/fixture/selector mutation and benchmark flags remain false.

A postflight mismatch invalidates semantic authority and is orchestration evidence, not a product verdict.

## Stop/rerun rules

- A red in ordinals 1–365 is a new gating failure; preserve it and stop gate credit.
- Repetition of `SingularityTerminationPortOwnershipMismatch` at seed 47 / singularity 5 falsifies CB12; do not
  patch or rebuild inside TB10.
- Identity 377 failing its v36/network-node contract falsifies BD4/BD5 independently of ordinal 366; preserve both
  observations.
- An orchestration-only failure may be retried only after its exact control defect is diagnosed, with package 80
  unchanged. Never rerun an unchanged deterministic semantic failure merely to see whether it passes.

## Completion criteria

A valid TB10 result requires package pre/postflight PASS, complete ordered selector-377 execution under the gate/
report-only rules, all BD9 discriminators recorded, and regression tracker disposition updated. Runtime acceptance
or the next correction/review boundary is decided from that evidence; TB10 itself does not mutate product source.
