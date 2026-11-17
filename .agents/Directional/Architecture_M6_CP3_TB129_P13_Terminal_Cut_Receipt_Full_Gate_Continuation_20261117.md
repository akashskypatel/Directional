# TB129 P13 terminal-cut receipt — execution continuation (2026-11-17 UTC)

## Situation

Canonical turn `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-EXEC`, entered 2026-11-17T12:28:20Z. CB151 was COMPLETE at entry. Both frozen Test + Benchmark execution requests have been committed. Resume this same turn. No duplicate dispatch, rebuild, source/test/fixture/build/manifest edit, successor execution or promotion is authorized. Neither candidate result is verified yet. No MATCH/MISMATCH or H1/H2 claim.

## Background — immutable authority

- Semantic source and harness executor: `c45e9abe5085f39c1f5bcb149ec07f95b719177e`; CB151 package `14327212608`, ZIP `9ef0f781947748cf2433566f3704259ab362dbf8f042999f87248ca6d645eb69`, source archive `434a3817c90395366c572287e205c3d0d9268241817b20c3f106ba6e2a500417`; root manifest `0c65a1f63be701f8497fb828d3826f3b7a2a23f00042d97600570263647677b7`. 28/28 package checksums, six executable modes and GMP/GMPXX dependency evidence verified. Exact harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Frozen gate `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962` (953 rows), deferred ledger `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 identities), census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3 rows). Harness self-check passed for both manifests; no binaries executed locally.
- TB128 comparison gate `14318100443`, ZIP `e208416775f474f75d79ec76697ed19d643a121d8ad086cd37b8f3a330436e5d`; census `14317054197`, ZIP `cdf7dab92f0e8c2650db6e2e5ac015d7ab5f07e251b4acdd17e6ed511ee7ccf4`. 1,923/1,923 archive member SHA checks, frozen row identities, every raw-log hash, boundary and gate membership checked. TB128 951/953 PASS, rows 858/952 RED; census 1 PASS, 2 allowed RED. These are baseline results, not TB129.
- Snapshot source `a6fbf0e7cd718d4017a8dca5a33411bd885d9d8e`, run `44083674865`, snapshot job `134040521983`, artifact `14327658805` ZIP `60117c76247b2b4aa1874662358c05f21390cf63a92de51244bb15a4138cf855`; 5,522/5,522 file hashes verified. Snapshot marker `.agents/connector-triggers/source-snapshot/tb129-20261117T122820Z.txt` requires cleanup when safe. No source delta after semantic source; only control/docs changes. PR #8 draft, open, unmerged.

## Assessment — exact submitted requests

| Work | Event commit | Mailbox key (ref `workflow-mailbox`) | Request SHA-256 |
|---|---|---|---|
| Full gate | `d86a4d8cd5df50fa9441f4656ed1f3ee508a4007` | `m6-cp3-tb129-gate-v1` | `172788d0c07d4d08f6827e31a23814143cdb6b5ebbe22d1ac9c255b981efdf25` |
| Census | `9b6721c617d850666159fe22b7dd8f7892cc080f` | `m6-cp3-tb129-census-v1` | `3d0607a041db9c59bae092d23705c6b9e51c0f314e3d6afbc9e1ebb49f00a37a` |

Both exact request blobs are Git-addressable at `.agents/Directional/agent-dispatch-request.json` at their event commits. The durable dispatcher serializes requests and checks out the exact event commit. A later request-slot value does not invalidate an existing execution. At last observation no final mailbox record had been published; absence is not evidence of failure. No candidate score or receipt classification established. Product totals remain 66/17/49, debt 1, deferred 81, CP2 491/491; CP3/selector497/D0 unpromoted.

## Recommendation — exact continuation

1. Read/update root STATUS at entry, preserve the original start time. Read both mailbox paths `.workflow-mailbox/<key>/latest.json` on orphan ref `workflow-mailbox`. Verify event and source SHA, run/jobs, result/log artifacts and ZIP/checksum/boundary identity. If a mailbox is absent after plausible completion, use the authorized bounded recent-runs fallback, not duplicate dispatch. If execution fails, retain exact failure evidence and route per RA-250.
2. Verify complete gate rows and membership 1,034; compare every row against TB128 under the exact permitted normalization. Rows 644/669/698 must have one receipt per rejected network and only the expressly authorized fields changed; row 164 complete-record multiset only. Confirm row 858 and 952 PASS and no other receipt under R6. Compare census Cylinder/Vase and BunnyRandom complete preterminal prefix and receipt. Classify every sphere and BunnyRandom receipt H1/H2/new owner exactly; H2 candidate face needs carrier binding proof. Do not infer a class from static plausibility alone. Preserve raw logs and all discrepancies; no corrective implementation in this turn.
3. Write owning execution report, update regression tracker for observed candidates, handoff/TODO and CHANGELOG; complete cleanup and drift audit. Set final STATUS with the frozen route only after evidence and durable closeout. MATCH → `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; MISMATCH → `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-REV`; infrastructure failure → `M6-CP3-TB129A-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-ORCH`. Read RA-250 §R6 in `Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md`. No successor work in this turn.
