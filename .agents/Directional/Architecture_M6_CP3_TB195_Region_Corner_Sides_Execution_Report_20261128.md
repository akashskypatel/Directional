# M6-CP3-TB-EXEC-195 — region corner sides (2026-11-28 UTC)

## Situation

The immutable CB-220 gate executed once: 1015/1015 PASS. All frozen prediction and preservation comparisons match. Independent acceptance belongs to M6-CP3-TB-REV-195. Root STATUS governs formal closeout. No rebuild, repair, retry, V5 or production activation.

## Background — authority

- [Exact manifest](gates/Architecture_M6_CP3_CB220_TB195_Region_Corner_Sides_Exact_Manifest.md); [CB-220](Architecture_M6_CP3_CB220_P13_Region_Corner_Sides_Code_Build_Record_20261128.md); [corners DEFN](Architecture_M6_CP3_DEFN_P13_A4_Disc_Corners_20261128.md), CR1–CR4.
- Candidate 15257943465, source and executor `e55f01b9ac86e2dc0159771a45521cb6f35049be`, ZIP SHA-256 `eb7e5ea11cb129c9d0ff33931967cf9bcf7227a831ff9af59014f44f9faa4f71`, root manifest `eac14312b4efc6686fffc5b90bd888a55237e723d3a7f0a160af7a6496888bf5`, source archive `d268be90335fd0cc30fa32d99950b835405da7a55c09dec9ab395443acfa2e6c`. Entry: 28/28 checks, six executable modes, clean source status, GMP/GMPXX linkage, eight targets, compile-only boundary, four exact CB-220 postimages.
- Harness `tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. Gate [1015-row manifest](gates/Architecture_M6_CP3_CB220_TB195_Region_Corner_Sides_Full_Gate_Case_Manifest.tsv) SHA-256 `34a4e86406f043739c56eec6bc104615bee05fc08960be2dc6ae4a303b43b821`; first 1013 rows including header byte-equal to TB193 manifest. [Deferred ledger](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv), SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 rows.
- Dispatcher commit `41581462791831e89cb09f7b4ba706d06978db27`, request SHA-256 `a438c384a7ed257db9482114efa913eb05341f3738c64b3085b5f213ef31fac8`, request and mailbox key `m6-cp3-tb195-exec`. [Run 46134852307](https://github.com/akashskypatel/Directional/actions/runs/46134852307), attempt 1; validation jobs 140947741217/140947741484, parse 140947810780, runtime 140947858972, mailbox 140952034438 all success. Compile, noop and drive_apply skipped. Mailbox event and source match; publication 2026-11-28T10:40:07Z. No repeat dispatch.

## Assessment — immutable execution evidence

| Artifact | ID | ZIP SHA-256 |
|---|---|---|
| TB195 result | 15259492817 | `f2fb104ac182cc24f1f8d6f68116eeb0fcb6d0e95f166c73d6a322aadd8f2a4b` |
| Harness log (mailbox inventory) | 15259507684 | `39941302e3444608e91326522741cc8c5f70d4b7fc99bc29e2bd0601555a4507` |
| Wrapper log (mailbox inventory) | 15259253210 | `73f91e9479ccb5683d5ae52e2712740871541d7e959d2fdb6a3f4c0c75186d11` |
| TB194 comparator | 15255025606 | `5fedd54ddf3416bf1cdb475a8e53206ab6382fcd75e9ea8b4a3bfebb4f8d99b4` |

Result size 1863187 B, expiry 2026-12-12T10:39:40Z. Result and comparator archive hashes verified; respectively 2038/2038 and 2034/2034 exact manifest checks with no extra/uncovered files. Result root SHA256SUMS `45fa4de71b0c490422719e1a1a34d08ccb2e93d681dee1cb89cf122358ca3252`; ledger `5d42906a689d17cb933207f475889049eee99efe888b2a78558420865cc15c88`, membership `8a947eac40059c52f100e1aa180c9eec4864d0b4e17a5024cfd92028ff76c512`, boundary `e9416c052c8f4d3a8419126fd10eb0a6fc3f17a86ca1dd356238f2329937e41d`.

- Ordered manifest/ledger identity, one RUN/OK/PASSED per exact filter, raw hashes, binary and resource filter/exit receipts verified. 1005 GUARD + 10 POSITIVE = 1015 PASS. Membership exact 1015 GATED + 81 DEFERRED = 1096. No duplicate, unexpected or missing membership.
- Planned/executed/passed 1015; every failure counter zero, postflight true, exit 0; configure, compile, relink, benchmark false. Candidate and source exact. All inherited non-hash ledger fields equal TB194.
- Rows 1–1013 except 858: 785 byte-identical, 226 N1 (GoogleTest elapsed times), 0 additional N2 (CRLF), 1 N3 (counted complete fragment projection record reordering, ordered remainder unchanged). All 1012 required comparisons equal, no unexpected difference.
- Row858 TB194 raw SHA-256 `cff825fdb84885fb9c54389b389dde882060247bab99be351199989af3707c63`; TB195 `cdab60c113fdfa7ef6521b950b414c213f6d4285b8bc88268dc528a4cb646568`. Exact first 448 lines through GenusSingularityArrivals, exactly ten new lines, remaining suffix N1/N2 equal. All CR2 counts and corner gaps match. Each sphere region has four distinct corners with gap 1 and sum of (2 − gap) = 4.
- Guard 1014 PrescribedSphereRegionsTurnAtFourQuarterTurnCorners PASS, raw SHA-256 `b654a03094d9047ff9c7e92402a481a7e1a79a9fd23e2bfac1ccafcc2097da30`; 1015 ReversedPrescribedSphereWalkIsRejectedByItsTurning PASS, `100f0c31fc42802793a807d76e007914ac14dcf24b650ec3b1b7031736276f75`. No new stable regression.
- Sum of per-process wall receipts 1002.51 s (TB194 990.07 s); peak RSS 91336 KiB (TB194 91236 KiB), both row899. Not a controlled performance comparison; two extra tests, no V5.

### Exact new row858 receipts

```text
SphereRegionCornerSides built=1 regions=8 corners=32 sides=32
SphereRegionCornerSide region=0 corners=8,1;0,1;4,1;5,1 sides=30,35,35,32
SphereRegionCornerSide region=1 corners=0,1;1,1;3,1;2,1 sides=31,35,35,31
SphereRegionCornerSide region=2 corners=1,1;8,1;5,1;10,1 sides=1,32,1,32
SphereRegionCornerSide region=3 corners=0,1;9,1;6,1;4,1 sides=30,32,35,35
SphereRegionCornerSide region=4 corners=9,1;2,1;11,1;6,1 sides=1,32,1,32
SphereRegionCornerSide region=5 corners=1,1;10,1;7,1;3,1 sides=32,30,35,35
SphereRegionCornerSide region=6 corners=11,1;2,1;3,1;7,1 sides=32,35,35,30
SphereRegionCornerSide region=7 corners=4,1;6,1;7,1;5,1 sides=35,31,31,35
GenusRegionCornerSides built=0 failure=unsupported-arc-kind
```

The genus result is explicitly allowed by the manifest. DD5 is measured in regions 0,1,3,5,6,7; opposite counts are equal only in regions 2,4. CR1 falsifiers did not fire on this pinned witness. The corner product is not wired to production. No independent proof of the A3 count derivation, general disc completion, or output mesh is claimed. CP2 491/491; last accepted test gate TB194 1013/1013; stable 67/17/50, debt1/deferred81. O51 pinned accepted, O52 quality item carried, O50 open, B1 held, B2 unmeasured. PR #8 draft/open/unmerged.

### Control provenance

Snapshot source `39d487c3aa719ede9532777881373942814f62cd`, run 46134877497, job 140947867919, artifact 15258833421, ZIP SHA-256 `7d217140cfd822e2a9a1666d23b4bdb6d241f5452c934fb357369ac0970dbc91`, archive `a04b8a2f8f6a6b34d489a485d206beff848cfd2c348e0d51ac8157981c9fd3b9`; 5913/5913 checks. Initial read-only document reads preceded snapshot bootstrap in the first response; corrected with verified snapshot. First response cleanup run 46135180087, job 140948814157, commit `5cf4b72410a2773fc1746460f6691e92060e6618`, receipt 15259596139 ZIP `64bcb34158db839a8c86265bf44737bb858d81b1d571005881c6db206a7335a6`; snapshot trigger removed, zero PR comments deleted. Resumed at 2026-11-28T10:42:54Z; resume beacon commit `3e14ff1225e7f41b82ef972e18903554910d005a`. Reused exact snapshot; comparison to resume head found only report addition, STATUS change and marker removal. No local compile or execution of Directional binaries.

### Closeout evidence

Both harness and wrapper log ZIPs match mailbox SHA-256 values. Wrapper confirms exact executor, source, harness and exit0; harness confirms all 1015 cases and postflight. Membership has 1096 distinct binary/test pairs. Patch base 39d487c3aa719ede9532777881373942814f62cd; intended preimages unchanged through resume. Patch SHA-256 `1505c6fa96460d021186720250deec2ad114cee1f13c59d7857f6b11cb23d399`, diff-body SHA-256 `b332b1b8b579a2890d747f5e57f8f466fd485414702f351f54bdc350942ae52e`. Local apply/reverse checks, whitespace and documentation audit: zero errors, existing orientation size warning and three authorized protected navigation changes. Patch preserved in File Library. Dispatcher `c495b5242a51834529991b70ebdd96119e6099b2`, request SHA-256 `80a117c39a485851f4cd9b313d62ba7096b3018e8e37c61fa848c9228b87b77e`; [run 46136838467](https://github.com/akashskypatel/Directional/actions/runs/46136838467), job 140954019679, receipt 15260226629 ZIP `7581f79fad9d98822b146c403bce626bf52c278761105dd5ab8bc92d05a42998`, log 15260510330 ZIP `24790e21ee91a29008cc6c97e199704cd355727d13644a3ab104d52bc7127ff7`. Verify/apply/push exit0, runtimeExecution=false, six paths (+30/−25), commit `7b5498fbcfbe5ed66fccf3fc18e0c6c06b597b69`. Six remote Git blobs match local postimages. Owner-authorized delete of staged Drive ID 1qBY34jV3RleSC7w1S-dZK4Hr9N0lf-ZV succeeded. No temporary source-branch state; dispatcher retained. No review or successor work executed.

## Recommendation

Next M6-CP3-TB-REV-195: independently re-open candidate, TB195 and TB194 result authority; verify the manifest, all ledger/membership/integrity claims, all 1012 inherited comparisons, exact row858 insertion, CR1–CR4 and both guard receipts. Adjudicate DD5 and permitted genus failure, then authorize the unequal-side DEFN only if review passes. No CP3/497/D0/H4 or production promotion, source repair or successor work in TB-EXEC-195.
