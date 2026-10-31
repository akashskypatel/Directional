# M6-CP3-CB1-ENTRY-R4 — unsupported-sheet source A3 first-rejection candidate (2026-10-12)

Same canonical Code + Build turn, IN_PROGRESS, successor UNKNOWN. Draft PR #8. Not a TB497 execution, runtime regression acceptance or permission to advance.

## Source and patch authority

- Verified snapshot `38208239400`, event/source `29dbe34f35cc7d8bb2ea4bd1479aa11a242a75f4`, artifact `11727344883` ZIP SHA-256 `2e4049043008b8580dc3c53baf5218bd1de1fe2833e4e4890103729ba2358ae2`, internal tar SHA-256 `6b9aa77213c40a48fb1801b60b29e33b4be4a6dd68ca5ef066c87f2654e3b7c5`, 6376/6376 SHA256SUMS, `runtimeExecution=false`.
- One-file exact-base patch `Directional_M6_CP3_R4_Unsupported_Sheet_Original_A3_WIP.patch`, SHA-256 `9777fa86e1b80d7a76ee4f27db7cd5aec56b85aa9ec2be62195b4a4d967e78cb`, diff-body SHA-256 `d2e31ba4baf5c180ea34900bae212293ec7b1c25679c74bb7640546adecf4b58`; `git apply --check`, forward/reverse replay and whitespace checks passed.
- Drive apply workflow `38208759469` job `114678071918`, result artifact `11729035200` ZIP SHA-256 `f93a5aaff338f6e449fdd638d2f5239c00a0017bb22fc8dd84dbc18173cd9949`, exact semantic source `24fbd353332c1d55ec2612e9a0ccbe748a861d9f`. Staging Drive file `1O1s8545_Qi3LhHBhL8_eyfBN21NjlRx-` permanently deleted after successful source push.

## Bounded change

`tests/SurfaceCellsPhase10Tests.cpp` negative `PhaseFrontProducedThenUnsupportedSheetFailsClosedWithoutPartialAuthority` previously called the axis-overload with no independent A3 and could encounter the null-atlas gate instead of its requested unsupported-sheet first rejection. The fixture now constructs the same exact source geometry as a `TriMesh`, materializes a complete four-direction raw cross field from its unmodified per-face axes, derives source A2 regions from its original component/sheet labels, and obtains a checked `FieldTransportAtlas::make`. Only a local bound options copy passes that atlas pointer to the unchanged axis-overload, whose lifetime is entirely inside the factory call. The returned options are the original unbound labels, avoiding a dangling atlas pointer. Both face-row orders, source geometry, region labels, rejection type and all existing asserts remain unchanged. Compilation does not prove that either rejection oracle passes at runtime.

## Compile-only evidence

- Eight-target mandatory GMP/GMPXX workflow: **GREEN**; run `38208927096`; job `114678596602`.
- Immutable result artifact `11728751414` ZIP SHA-256 `883c7a811aec1138d7aecaa0f8b225aae6fe7eb5a712909a31a08a4fa7f3c273`; separate diagnostic artifact `11729000824` ZIP SHA-256 `705e72e9ab6fd2d455b362d83f2b22924e559e0f5795113c4faecdedf981f6a4`.
- `runtimeExecution=false`. No Directional binary, test, benchmark, test discovery or frozen TB497 was run locally or remotely. The frozen historical CP2 491/491 and rejected R3 403/497 are not changed.

## Remaining authority

RA-43.4 complete legacy-rail removal, independent three-face overfull-A3 feasibility Review, 39 endpoint effects, 34 Phase10 producer positives, seven DCEL negative oracles, 88 formerly accepted CP2 REDs, six CP3 positive gates, and genuine multi-carrier odd-τ sector witnesses all remain OPEN and untested. The original `UnsupportedSourceSheetTopology` first-rejection oracle requires separately authorized execution and acceptance. Do not start TB497 or a successor.
