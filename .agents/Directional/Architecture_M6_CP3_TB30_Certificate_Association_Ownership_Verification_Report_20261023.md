# TB30 — targeted certificate-association ownership verification (2026-10-23)

**Canonical turn:** `M6-CP3-TB30-RP01-CERTIFICATE-ASSOCIATION-OWNERSHIP-VERIFICATION`.
**Measured gate: expected results reproduced for 29/29 targeted identities.** This is not a full 497-selector acceptance, CP3 closure, or independent Review. Separate TB30-REV is required by RA-143.4 before a further definition, implementation, or promotion.

## Immutable evidence and execution boundary

- Authority: CB29 independent review `Architecture_M6_CP3_CB29_A4_Certificate_Association_Ownership_Review_Decision_20261023.md` (RA-143.4), exact 29-row manifest `Architecture_M6_CP3_TB30_Targeted_Case_Manifest.tsv` SHA-256 `2b41ac11aad179770c5eb538876abcfb8fa0fd1d8df5315af0605ab35a7c59f6`.
- Package: compiled CB29 semantic commit `2602e7398cdc6f1281abe11a758de35166b6590c`, artifact `12492950387`, ZIP SHA-256 `9e2da1f4b5cf95ac45364e8c428f0bd9116dcfe96772de18d02a5a7bfb167319`, internal 28/28 package hashes, exact GMP/GMPXX compile provenance. Target harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`.
- GitHub Actions [run 39949886169](https://github.com/akashskypatel/Directional/actions/runs/39949886169), source dispatch event SHA `9ef1f596fb91b49f8fb18e5028e3eb5010593e7a`, `workflow-mailbox` key `m6-cp3-tb30-certificate-association`, mailbox result `success`; result artifact `12500088095` (`m6-cp3-tb30-cert-assoc-result-39949886169`), ZIP SHA-256 `bba928eb45957a29521a221ad093891de29f6a498c156691acc9c68b3a7308bf`.
- Independent local verification of **downloaded artifact only**: all 61 `SHA256SUMS` file rows verified; the `ledger.tsv` identities are unique and match the 29 review-owned manifest rows in order; each reports one GoogleTest run, correct individual terminal result and per-log SHA-256. No Directional binary was rerun locally.
- `execution-boundary.json` records `planned=29`, `executed=29`, `passed=22`, `red=7`, `missing=0`, `skipped=0`, `duplicate=0`, `control_bad=0`, `unexpected_pass=0`, `postflight=true`, `exit=0`, and `compile=false`, `relink=false`, `configure=false`, `benchmark=false`.

## Measured outcome against pre-registered predictions

| Group | Expected | Measured | Verdict |
|---|---|---|---|
| Prior TB29 controls | 9 PASS | 9 PASS | Expected |
| Certificate-association M1 corrective cases | 10 PASS | 10 PASS | Expected |
| Non-M1 factory failures | 7 unchanged typed RED | 7 unchanged typed RED | Expected, still unresolved |
| RA-143.4 authenticity guards | 3 PASS | 3 PASS | Expected |
| Invalid, missing, skipped, duplicate, unexpected PASS | zero | zero | Expected |

The ten M1 identities are `focused30:3,22,23` and `selector:139,140,142,211,219,227,230`. This observation supports the RA-143 one-clause A4/A5 division for these tests, but not a broader pipeline correctness claim. The seven non-M1 REDs continue to arise at earlier factory rejection sites (six `face-gauge-missing`, one `open-rail-chain`), distinct from M1. Their `code=0` diagnostic alone does **not** establish complete root cause or repair authority.

### Exact 29-case result ledger

| Row | Identity | Role | Measured | First typed failure site |
|---:|---|---|---|---|
| 1 | `A7NEG:1` | NEGATIVE | PASS | — |
| 2 | `A7NEG:2` | NEGATIVE | PASS | — |
| 3 | `A7NEG:3` | NEGATIVE | PASS | — |
| 4 | `A7NEG:4` | NEGATIVE | PASS | — |
| 5 | `cp3entry:3` | POSITIVE | PASS | — |
| 6 | `cp3entry:5` | POSITIVE | PASS | — |
| 7 | `RA130.9:A7-1` | GUARD | PASS | — |
| 8 | `RA130.9:A7-2` | GUARD | PASS | — |
| 9 | `RA130.9:A7-3` | GUARD | PASS | — |
| 10 | `focused30:3` | POSITIVE | PASS | — |
| 11 | `focused30:22` | POSITIVE | PASS | — |
| 12 | `focused30:23` | POSITIVE | PASS | — |
| 13 | `selector:139` | POSITIVE | PASS | — |
| 14 | `selector:140` | POSITIVE | PASS | — |
| 15 | `selector:142` | POSITIVE | PASS | — |
| 16 | `selector:211` | POSITIVE | PASS | — |
| 17 | `selector:219` | POSITIVE | PASS | — |
| 18 | `selector:227` | POSITIVE | PASS | — |
| 19 | `selector:230` | POSITIVE | PASS | — |
| 20 | `selector:220` | RED | RED | `sourceAuthoritySite=face-gauge-missing` |
| 21 | `selector:221` | RED | RED | `sourceAuthoritySite=face-gauge-missing` |
| 22 | `selector:296` | RED | RED | `sourceAuthoritySite=face-gauge-missing` |
| 23 | `selector:302` | RED | RED | `sourceAuthoritySite=face-gauge-missing` |
| 24 | `selector:304` | RED | RED | `sourceAuthoritySite=face-gauge-missing` |
| 25 | `selector:439` | RED | RED | `sourceAuthoritySite=face-gauge-missing` |
| 26 | `cp3entry:4` | RED | RED | `sourceAuthoritySite=open-rail-chain` |
| 27 | `RA143.4:AUTH-1` | GUARD | PASS | — |
| 28 | `RA143.4:AUTH-2` | GUARD | PASS | — |
| 29 | `RA143.4:AUTH-3` | GUARD | PASS | — |

The six face-gauge cases are `selector:220,221,296,302,304,439` (`code=0;sourceAuthoritySite=face-gauge-missing;edge=-1;event=-1;cell=none;region=none;periodicRelation=none`). `cp3entry:4` retains `code=0;sourceAuthoritySite=open-rail-chain;edge=-1;event=-1;cell=none;region=none;periodicRelation=none`. These are independent typed loci, not newly observed failures and not passing tests.

## Root-cause limits and next disposition

No PASS→RED was observed within the bounded matrix. All seven REDs are inherited from the prior TB29 inventory; they remain **candidate/non-stable**, with their existing owners for later separate Review/Definition. The run does not exercise A3 cycle locus or A5 `focused30:12`; no inference about them is made. Historical stable accounting remains **66 events / 17 categories / 49 recurrences**, with **one produced-witness debt**. M6-CP2 `491/491` is the last accepted cumulative gate; R3 `403/497` was rejected and TB28 `462/497` remains candidate only; CP3/RP-01 not accepted, RP-02 unreached, Gate C suspended. No selector, test, fixture, source, build, or benchmark changes are made by this TB.

**Required next action:** independent TB30-REV re-opens the immutable 29-case logs/hashes, adjudicates M1 successes and seven carried failures, verifies absence of an unexpected owner-precedence regression and issues explicit subsequent owners/stop rules. The prior CB29 review required this separate Review but did not assign its full canonical turn identifier; handoff uses `UNKNOWN — STOP` until that authority is frozen. No automatic successor Code + Build or full census is authorized.
