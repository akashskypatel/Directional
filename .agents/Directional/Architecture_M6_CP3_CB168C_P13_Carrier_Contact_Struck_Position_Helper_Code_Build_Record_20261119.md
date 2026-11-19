# CB168C — carrier-contact struck-position helper (Code + Build, 2026-11-19 UTC)

## Situation

**Compile PASS.** `M6-CP3-CB168C-P13-CARRIER-CONTACT-STRUCK-POSITION-HELPER` produced source `e0f085eb65ed186bf836305f2896c69c6c90c519`. [Compile run 44457640890](https://github.com/akashskypatel/Directional/actions/runs/44457640890) completed with `success`. Immutable package `14498438448` has ZIP SHA-256 `041ee85006926b674b3692a1315e9ba0695397a144ea0f00c406b4a6cfee081f`. Compile log artifact `LOG14498438448`. Eight mandatory GMP/GMPXX targets compiled. `runtimeExecution=false`. No Directional tests or benchmarks executed.

## Background

[RA-265 frozen plan](Architecture_M6_CP3_CB168B_CB168C_TB144_P13_Framing_And_Struck_Position_Plan_20261119.md) authorized only [the exact patch](Architecture_M6_CP3_CB168C_P13_Carrier_Contact_Struck_Position_Helper_Exact.diff), SHA-256 `f8badfdf09864bb88b9ff4d2a870b8e0ba1b03f57b4513d5dfc0f9f7719ee204`. Source snapshot run `44456940377` verified `5600` files at source `91204a2987f393fd88363e0df2b7aba4cd1399af`. Comparison with CB168B source `ddd4d158701bdcca73fe3eb5034d51dd4ff1b694` found no `src`, `include`, or `tests` changes before this patch. The patch applies to that product and edits exactly five authorized paths (+126/-0).

## Assessment

The helper `carrier_contact_struck_position` returns the boundary before the struck segment only for a matching trace, an interior carrier entry crossing, and an exact edge parameter. The terminal contact stores an optional `carrierLocus`, and the digest includes it only when present. The hand-built focused test supplies two positive entry cases and seven negative controls. The helper remains unwired. No EC2b or EC3 switch was made, and no acceptance test was run.

The generated full-index preservation patch SHA-256 is `2a00c6bf50f3dca8c9d2a1f39ee732fd54757ae4ab0da8f7ae049504cd1d6121` (9,704 bytes); base `91204a2987f393fd88363e0df2b7aba4cd1399af`, diff-body SHA-256 `b6548610e3c94e24a1e80f07b24b656fb809a5d7af4ff17270fb8cd4ea1f6c2d`. It was staged to Drive File ID `11evNJbzIvqgOn0sLgTiAZPIYkV8ySqnI` under `Directional-CI`. Remote patch application and exact source commit are recorded above. Compile verification is limited to build/package evidence. Previous TB143 runtime and RA-265 review authority remain unchanged: 962/962 prior records under N1–N7, stable 66/17/49, one witness debt, 81 deferred, CP2 491/491. No CP3/D0 product acceptance.

## Recommendation

Proceed next with `M6-CP3-TB144-P13-FRAMING-AND-STRUCK-POSITION-FULL-GATE-EXEC` against immutable CB168C package `14498438448` under the frozen manifest SHA-256 `fc1264e96628ad659302905f5537d8f4fc09973ffbfeaea3a4f228069613e949`. Use the separate artifact-only gate and independent review. Do not reinterpret this compile checkpoint as runtime proof.
