# TB38 periodic route atlas census — independent evidence Review (2026-10-25)

**Turn:** `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS-REV`.
**Decision:** ACCEPT the **artifact-only census as valid candidate evidence**. Do **not** accept M6-CP3, promote the 497-selector, recategorize the 14 RED as passing, or change stable accounting. Next bounded turn: `M6-CP3-DEFN-RP01-ATLAS-INGRESS-TAMPER-ORACLE-HOMES` (definition only). This Review did not execute Directional binaries.

## Primary evidence and independent arithmetic

- Exact immutable TB38 artifact `12597140251`, from run `40185527486`: independently downloaded ZIP SHA-256 `0cdfe445fbc5388b8e95331f87c4a291001645f30458001bb5426244022a9870` and verified **1,014/1,014** SHA256SUMS entries, including **504/504** raw log hashes joined to the ledger.
- Independently downloaded TB32 baseline artifact `12534679588`, ZIP SHA-256 `2c809e72489a69396c3c9e97e2a40ebb15f726de84a19b5610bb092fb9f85ddd`; **1,006/1,006** SHA256SUMS entries and baseline 500 log-to-ledger joins verified.
- Source snapshot from exact repository `0148015ab741329a99d973177602823b66acba37` via run `40196478071`, artifact `12600670909`, archive SHA-256 `664822cf8685c132a9bd8e2147eeeed8158115ee285b452a2ce03e4b4102966e`: **5,881/5,881** source checksums. TB38 manifest SHA-256 `b27eecb6b4f6f32fd060b8510a0cabf71f86b8fe1028dbb10c36003867dcf8c2`, unchanged harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a` rehashed from source.
- Immutable CB36 package `12590917524` ZIP SHA-256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`: independently downloaded, **28/28** packaged checksums; semantic source `038ae7fd7c290731c28225d2693a3e13866e325a`, eight recorded compiled targets; link evidence contains both GMPXX and GMP, `runtimeExecution=false`.
- Parsed manifests without using TB38 report totals: same first **500 identity / test / binary / order** rows as TB32. Only expectation/kind changes occur at one-based rows **231,232,235,236,237** (selector 189,190,193,194,195: RED→GUARD/PASS); **501–504** are four new guards. No previously passing row became RED. Every raw log contains exactly one `[ RUN ]` marker and one terminal result; all 504 ledger run counts are 1 and skipped counts 0. Each manifest expectation matches observed verdict.
- Independently recounted TB38 **490 PASS / 14 RED**; original 497-row prefix **483 PASS / 14 RED**, versus TB32 **478 PASS / 19 RED**; four appended guard rows PASS. The run boundary records 504 executed, zero missing/skipped/duplicate/control_bad/unexpected_pass, `postflight=true`, exit 0, compile/configure/relink/benchmark false.

## Review of all 14 residual identities

| Identity | Independent first-failure comparison to TB32 | Disposition |
|---|---|---|
| `focused30:12` | Same missing `relabelledA5` predicate | RED, A5 owner |
| `selector:174` | Same DCEL fixture exception | RED, unresolved owner |
| `selector:191,192` | TB32 stopped with A3 `CycleTransportMismatch` fixture exception; TB38 now fails the intended expected `Rejected` vs actual `Produced` assertion (reason None). Explicitly predicted by RA-154, but **not** an oracle pass | RED, ingress re-home DEFN |
| `selector:201` | Same REPackage terminal-vertex assertion | RED, unresolved owner |
| `selector:204` | Same `Rejected` vs `Produced` / `MissingTransitionProvenance` assertion | RED, ingress re-home DEFN |
| `selector:242` | Same `Rejected` vs `Produced` / `InvalidTopologyRegionTransport` assertion; only source line and pointer address drift | RED, ingress re-home DEFN |
| `selector:247` | Same `Rejected` vs `Produced` / `PeriodicHolonomyMismatch` assertion; only source line changed | RED, ingress re-home DEFN |
| `selector:250` | Same expected `Produced` vs actual `Rejected`, terminal `PublishedProductRejected` **68**. Underlying checked-factory sub-site **not measured** | RED, conditional site diagnostic |
| `selector:405` | Same `InvalidHardRailRouteCertificate`, first predicate `endpoint-0` | RED, A4 owner |
| `selector:442` | Same `SingularityMismatch;sourceEdge=(2,3)` | RED, atlas owner |
| `cp3entry:1` | Same A5 source assertion | RED, DEFN-T1 |
| `cp3entry:2` | Same missing produced midline, pointer bytes differ nondeterministically; assertion unchanged | RED, DEFN-T1 |
| `cp3entry:4` | Same missing open-rail-chain front / code 0 | RED, A4 owner |

The RA-154.4 stop clause on assertion drift is satisfied **only with its explicit 191/192 exception**: the two earlier exception outcomes move to later failing assertions exactly as predicted. No other unapproved first-assertion change exists. No new stable event follows from failures of unpromoted oracles. All 14 are inherited unresolved evidence, not new accepted-green losses.

## Non-vacuity and carried obligations

- The four appended controls each execute one distinct registered test. Their PASS results are meaningful only for their independently asserted k=1/k=2, directed route, and face-gauge witnesses; they do **not** validate the stranded legacy tamper ingress. Five formerly RED guards represent candidate coverage and cannot silently replace negative oracles.
- **RA-154 G1** discharged (frozen 504-case manifest and rowwise predictions executed); **G2** upheld/carried (191,192,204,242,247 oracle re-homing plus 189/190 non-vacuity to next DEFN); **G3** confirmed/carried (`250` remains 68, factory sub-site unknown); **G4** discharged (unchanged TB32 harness); **G5** discharged (semantic assertions compared, not text line numbers). **O1** cut-route identity transport is retained and separate.
- Carry `DIAG-RETAIN`, RA-152.5 (axis binding), DEFN-SEAM-NZ, RA-146.2/4, RA-45.4 and G4-B002 to their previously assigned owners; do not merge their work with ingress-oracle definition.
- **Next-turn falsifiers before implementation:** every 189/190/191/192/204/242/247 oracle must have one stated semantic property, one single-writer ingress, a keep/rehome-or-retire decision, and a selector bookkeeping rule. Any proposed negative oracle that mutates unconsumed legacy containers is invalid; any definition that relaxes rejection expectations or changes tests during DEFN stops the turn. Inspect the out-of-selector curved bounded disk analog. Next DEFN executes no binaries and edits no tests.

**Stable account:** 66 events / 17 categories / 49 recurrences, debt 1; CP2 491/491 accepted; TB32 481/500 candidate; TB38 490/504 reviewed **candidate** only; frozen 497 selector not promoted; RP-01 open, RP-02 unreached.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB38 manifest full `b27eecb6…dcf8c2`; first 500 rows same identity/test/binary/order as TB32; five expectation changes recorded. Frozen 497 selector itself unchanged. |
| Decisive claims independently re-derived | 1,014+1,006 checksums, 504+500 raw log joins, manifest rows, 490/14 arithmetic, each RED first assertion, CB36 28/28. |
| Non-vacuity checked | Four appended witnesses execute; legacy tamper oracles do not reach expected single-writer ingress, rehome/retire pending. |
| Prior obligations discharged/carried | RA-154 G1,G4,G5 discharged; G2,G3,O1 carried as above; other named obligations retained. |
| Stable accounting | 66/17/49, debt1; CP2 491/491 accepted; TB38 candidate 490/504; selector497 frozen. |
| New candidates/obligations recorded | No new stable events; ingress DEFN and 250 diagnostic retained in tracker. |
| ORIENTATION currency line | Updated to TB38-REV decision. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 n/a no witness states changed; §8 n/a no new defect pattern. |
| CHANGELOG | One review entry added. |
| ROADMAP | CP3 remains active; next-turn reference updated. |
| Selector manifest | n/a: unchanged byte-frozen selectors, no selector accepted. |
| LESSONS | Existing non-vacuity / single-writer ingress lessons apply; no new pattern. |
| Consolidation under CLEAN_UP_POLICY | Current TB38 source report retained; no prior report removed pending fully indexed, safe fact-preserving fold. M6 consolidated authority index updated; substantive consolidation outstanding. |
| Successor frozen | `M6-CP3-DEFN-RP01-ATLAS-INGRESS-TAMPER-ORACLE-HOMES`; falsifiers above. |
| Turn boundary held | Review-only inspection; no local runtime/build, source/test/selector/fixture mutation. |
| review_check.py boundary | Not independently verified against real Git history from the GitHub snapshot (snapshot excludes .git). |
| `STATUS` lifecycle maintained | Entry beacon published; final beacon pending remote documentation application. |
| Pushed to origin, branch in sync | Pending remote patch application and authoritative history check; do not claim success. |
