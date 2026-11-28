# TB135 — edge-transit entry full gate (2026-11-18 UTC)

## Situation

**MATCH**. `M6-CP3-TB135-P13-EDGE-TRANSIT-ENTRY-FULL-GATE-EXEC`. 956/956 MATCH under RA-256 S5; gate `14398029488` 952/953 and census `14398329619` Cylinder PASS/288, BunnyRandom/Vase RED; accepted prefix 491/491. 66 sphere receipts on 19 rows have no slide tokens; both BunnyRandom receipts carry precisely 43:11, 43:13, 15:19. On (94,210), t43=0.26324148596788688, t15=0.93470265131543506, ratio=0.0886278847694711840154612716578249278676129003001871014945774 (relative 1e-12 criterion met). No production acceptance or promotion.

## Background — immutable authority

- CB158 source/executor `5bdc7c092a8935faeab75cf7a739928fd8ddca46`, package `14397197316` ZIP SHA-256 `9282956b0115eb9455b0504e0b32bb6d9200b465313fcb30392954af02310bda`. Root manifest `73c4ca81a2b106017aa7b185a807eb0a316cc29ab44cc83956a6b8a073c83e35`; source archive `55c977b5f4db5f6f6c508894a8d27f122b4ca29e7618dfd108ea6d9fc6f7a6dc`. Eight GMP/GMPXX targets; 28/28 checksums, six executable modes, 371/371 source files. No rebuild, relink, configure, repair, fixture or source change.
- Snapshot `4311be687be9d442f740412244acafa2623ff497`, run 44238739700/job 134581193456/artifact 14399160183, ZIP SHA-256 `2538c7ad59f5a8ae70c38e3d2e03ea18a44df141111ab0edd4e3f15438610b16`; archive `bfc0babdca17eff8c518b031250aaafb23faf6a90e94f0f8dc4666e57f8b2c62`, 5546/5546 checksums.
- Comparator TB134 gate `14390702505` ZIP `532ae16d7872c5699a85c0bc11d819856660fb22b1fcaae99f454db714bf0640`; census `14391390784` ZIP `dcf867473ebc5bd0310ff5249644d4c4cd4a8cf6214cdca9942f2b0ec52fe149`.
- Frozen gate `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962`, census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, deferred `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, harness `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.

| Role | Event / request SHA-256 | Run / runtime job | Mailbox |
|---|---|---|---|
| gate | `77cca72caea05b6ba42049a321836ede81641bf6` / `2dba93a14705534de12cd52ca54d008ddf85a02a1b4daf00d2f766d2880dfa15` | [44239014989](https://github.com/akashskypatel/Directional/actions/runs/44239014989) / `134582217156` | `m6-cp3-tb135-gate-v1` |
| census | `26f4ea0b2df97d34862d748eccd0c6f4ebca0ffd` / `45acbe2a256e0d6f61a5cf19114e92dbf5e3f69e1168a08a05482ddc3b712ea4` | [44239053464](https://github.com/akashskypatel/Directional/actions/runs/44239053464) / `134585784882` | `m6-cp3-tb135-census-v1` |

| Archive | Artifact ID | ZIP SHA-256 |
|---|---:|---|
| gate result | 14398029488 | `4cc06b817c8ecfb20b7316b7017337fd2cfc9ab81c15f0360f2d2ef8f7ccc394` |
| gate log | 14398318956 | `52f125919913269e63e96f94f3149d4e74c65f43521c8e9eb1dea6216f726ee2` |
| gate reusable-log | 14398359044 | `48831746bb96ca121ea9462947b9f74d2e987d9b1ed0f0ae0c9339ad75a035f8` |
| census result | 14398329619 | `8840f1d0bf9b303a7364a1346d2f5be88f31f23eab8e73d8ae391e6308ad5453` |
| census log | 14398129887 | `6d239e5c2cdc4bc1d680424e0a9b7452797d433a5e6c566a4978e43d97130ce2` |
| census reusable-log | 14399810035 | `0bb599a37cb2221bf7510a19601ac768eb1bfb4c4008b50f32acd257b8be26e9` |

## Assessment

- Both terminal identities, jobs, artifact inventories, outer digests and postflight verified. Gate exit 90 (row 858 required-control RED), census exit 0. 3846 archive checks and 1912 raw-log bindings. 1034 membership (953 gated + 81 deferred) byte-identical. All 17 negative and 5 positive comparator controls passed.
- Six frozen checks passed: all ledger substantive bytes equal (raw hashes bound independently); logs equal under N1–N4 plus N6; each slide token immediately precedes its transit; no sphere slides; precise BunnyRandom segment/carrier set and strict interior positions; ratio prediction and order match. No abnormal, missing, skipped, duplicate, unexpected pass, later positive RED or unexpected RED site.

| Trace/segment | Carrier | Slide start | Transit |
|---|---|---:|---:|
| 43:11 | (60,290) | 0.079930581417586133 | 1 |
| 43:13 | (94,210) | 0.26324148596788688 | 0 |
| 15:19 | (94,210) | 0.93470265131543506 | 0 |

Both receipts agree. Ratio `(1-t15)/(1-t43)` = 0.0886278847694711840154612716578249278676129003001871014945774. This measures the stored start parameters; interpretation and independent verification belong to the next Review. H3 remains unverified.

### Regression disposition

No new semantic regression relative to TB134. Sphere C5/O47, BunnyRandom O48, Vase RED, row858 premise RED at `SurfaceCellTracingDisplayTests.cpp:155`, and row648 unreached sphere assertions unchanged. C5/O42/O43/O46/O47/O48, FC-1/FC-4, H2 and middle-piece direction witness remain open. O45 consumer proxy closure narrowly retained. FC-6, terminal-cut and row858 fix held. Stable 66/17/49, debt 1, deferred 81; CP2 491/491. D11=A, D12=A, D10 deferred, D6 pending; `chainRimSchedules=false`. No CP3/selector497/D0 promotion.

Procedure deviation: initial source reads preceded explicit snapshot-mode selection and some mandatory document reads were truncated/not confirmed in full before dispatch. Subsequent inspection used one verified snapshot. The timer used a shell rather than Python; absolute time boundary retained. No semantic or test-input changes.

## Recommendation

Exact separate next `M6-CP3-TB135-P13-EDGE-TRANSIT-ENTRY-FULL-GATE-REV`. Re-open both immutable results and independently verify RA-256 S5, including the measured start parameters. The sphere DEFN remains parallel; then `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP`. No successor work in this execution turn.
