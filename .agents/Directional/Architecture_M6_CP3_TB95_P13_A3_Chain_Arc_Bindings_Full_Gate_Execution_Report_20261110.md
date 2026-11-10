# TB95 — immutable chain arc-binding full-gate execution (2026-11-10)

**Canonical turn:** `M6-CP3-TB95-P13-A3-CHAIN-ARC-BINDINGS-FULL-GATE-EXEC` (64B.7). **Verified disposition: MATCH**, per RA-219 §8, with no CP3/selector497 or direct-production promotion. All execution was artifact-only; no project configure/compile/relink/benchmark, no source/test/fixture/selector mutation, no implementation repair.

## Immutable authority and execution

- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft/unmerged. Exact CB112 candidate commit `35912b11ff870d914c08599ef7b3d45f5a09c89b`, compile run `42798741749`, immutable package artifact `13754529459`; ZIP SHA-256 `dc8096a810fba4a000aa16ee1cc786f5e3460cf7692eaf76e3a9408e56f812e1`; packaged checksums 28/28, GMP/GMPXX compiler and linker evidence, `runtimeExecution=false`.
- Frozen TB95 manifest `.agents/Directional/gates/Architecture_M6_TB95_P13_A3_Chain_Arc_Bindings_Full_Gate_Case_Manifest.tsv`, SHA-256 `bcf9420d6ae0caee0d66100bb777946bd45c85dad609a7f9b648c67ea7345229`; 929 cases, 81 deferred; membership 1,010. Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Full gate dispatcher event `225c00b3b1c75ec7cdaed9041c37886d500da07c`; [run 42804987908](https://github.com/akashskypatel/Directional/actions/runs/42804987908) SUCCESS; result artifact **13757883667**, ZIP SHA-256 `eb23cc25c8dac9b9ff4126ac0dbdef507e3f715c83ae0ce70413167d8c542b0a`. **1,866/1,866 SHA256SUMS entries verified**.
- Production census dispatcher event `5d2f36688087cf3f5b8e6b5631e26bf367ad8cb5`; [run 42805285534](https://github.com/akashskypatel/Directional/actions/runs/42805285534) SUCCESS; result artifact **13760020055**, ZIP SHA-256 `f2616e1d12e321b6cae2f532b33e522dd76e7d2abe04640c0f117a1c55855fb1`. **9/9 SHA256SUMS entries verified**.
- Both mailboxes on orphan ref `workflow-mailbox` confirmed event SHA, source SHA, result and artifact IDs. Both execution boundaries independently show `compile=false`, `relink=false`, `configure=false`, `benchmark=false`, exit `0`, no error and postflight true.

## Independent gate verdict

- **929 planned / 929 executed / 929 PASS**, each exactly one run; `missing=skipped=duplicate=abnormal=control_bad=unexpected_pass=later_positive_red=red_site_bad=0`; postflight true. Membership exact: 929 gated and 81 deferred.
- Rows 1–925 matched TB94's verified 925/925 ledger on every verdict/identity/test/binary/run/exit/passed/skipped/first-failure/typed-reason field (log SHA-256 deliberately excluded because different runs have different logs). GUARD 926–929 all independently PASS.
- The **seven literal `platform-digest` lines and seven literal `a3-coverage` lines** (four from the gate, three from census) are byte-identical to TB94, covering Plane, CloseSheets, MultiFaceSeam, Cylinder gate/census, BunnyRandom and Vase.
- Exactly one receipt each from the four new guards: `D5_BINDING_RECEIPT case=shapes`, `case=rejections`, `case=square`, `case=baselineRejections`. Shapes cover three-arc, reversed and pair bindings with `permuted=same`; rejections report `rejected=15 branchSibling=accepted`; square reports `perArc=1,1,1,1 pair=1,1,2 pairs=1,1 backSide=opposite digests=4 crossRejected=12`; baseline rejections report `count=1 partition=4`. These receipts are supported by the passing assertions, not promoted into producer-use proof.
- Census: **3/3 executed**, Cylinder PASS, BunnyRandom RED, Vase RED. Each row matches TB94 on every non-log-hash ledger field, including the two RED cases' `reason-not-observed` type and registered first site `SurfaceCellDesignAcceptanceTests.cpp:271`. These are continuing registered failures, not direct-success evidence.

## Regression and successor disposition

**MATCH — no newly observed stable regression, accepted-green loss or accounting change.** Accepted CP2 remains 491/491; stable **66 events / 17 categories / 49 recurrences**, regression debt 1, deferred v5 81. Keep selector497 and CP3 unpromoted; BunnyRandom P13-e and Vase completion/producer RED remain unresolved. CB112 remains product-neutral because the pipeline factory supplies no chains. No test or fixture was altered for green results.

Per RA-219 §8, after TB95 completion the authorized successor is `M6-CP3-DEFN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION` (Review only), unless its independent 64B.8 definition has already frozen CB113. Do **not** execute successor work within this TB95 turn.
