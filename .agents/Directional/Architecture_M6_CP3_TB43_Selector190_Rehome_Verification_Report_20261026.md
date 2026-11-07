# TB43 — selector190 artifact-only verification (2026-10-26)

**Canonical turn:** `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY`. **Focused result: 4/4 PASS**. Independent TB43 Review is required before any promotion.

## Frozen authority

- CB43 source `d354d6ae95afc73df968fc5cc4ee69fe5b7de451`, compiled artifact `12657932087` SHA256 `4a65d5004e2afc08ab68361493a517c462cab68da6dd8019b94732cd3f860a26`, 28/28 package members checked.
- Packaged source archive SHA256 `6112e78fff4cd3e363cdca3ffa5cf6114c0b0933b04dabd9d2a1dc9b4e52817e`; root SHA256SUMS SHA256 `468d07a64daf0c515b10c66a40b5247e98f30efee29be5c41efcbbd50320440a`.
- Frozen [four-case manifest](Architecture_M6_CP3_TB43_Selector190_Rehome_Verification_Case_Manifest.tsv) SHA256 `812b843b8b01bb68cdb8e6845d9f6bd5aaa87c0b973a5a72967b241badffc676`; executor `e4cea5645799f60d09384aeab23e37a68caba47c`; unchanged targeted harness SHA256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`.
- Dispatcher event `ce6c084bf4cbb83439cedec650659a3da3db3c96`; [run 40353956056](https://github.com/akashskypatel/Directional/actions/runs/40353956056), mailbox `workflow-mailbox/.workflow-mailbox/m6-cp3-tb43-selector190-verify/latest.json`.
- Result artifact `12664712967` ZIP SHA256 `fbe75000b96917f26a90afa9a3fd1ec777e741e5973d0989144a76bd89b26804`; **12/12 result members verified**. Harness-log artifact `12664502544` ZIP SHA256 `8154f5623eacce38e980fe0d4ecddb619d1af8db00203449f6a93ba8db9afbc6`.

## Four exact selected processes

| Identity | Role | Outcome | Raw log SHA256 |
|---|---|---|---|
| selector:190 | POSITIVE | PASS | `d4a8a63d4669f7e8d291fc145ce76c9a7ff1b0ae76fd7f683a8560e153d168e7` |
| selector:28 | GUARD | PASS | `890de6666423bbbe63af252f6fed5cfdf970a8f2aa34c3373b353b37ec9921a7` |
| selector:179 | GUARD | PASS | `f23196fb915aa56080c156d736fe44ccbbcd14ec99476267957105ee823a8ba1` |
| selector:233 | GUARD | PASS | `f13eca5306af77a7e60ff8d3a98d4d61a4ec87982c06bebc870a699209a1a8b4` |

Each had exactly one selected GTest RUN and matching OK, exit 0, no skipped/duplicate/invalid rows. Execution boundary: `planned=4,executed=4,passed=4,red=0,missing=0,skipped=0,duplicate=0,control_bad=0,unexpected_pass=0,postflight=true,exit=0`. `compile=false,relink=false,configure=false,benchmark=false`; workflow compile, Drive apply and noop jobs skipped; test, dispatcher, validator, mailbox jobs succeeded.

This is focused evidence that the re-homed selector190 positive/A3-negative/restore-positive/A4-no-atlas assertions and the three guard tests passed, **not** an independent review of oracle non-vacuity, a full 497-selector gate, or CP3 acceptance. No regressions observed in these four rows, so no new regression tracker record or stable count change. Frozen CP2 **491/491** accepted, stable **66/17/49**, debt **1**, selector497 frozen, RP-01 open and RP-02 unreached; RA-160 D2–D5 and post-RP-01 O2 remain open.

**Successor:** `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY-REV`, independent result/log/oracle Review; no successor work in this TB turn.

**Process limitation:** initial repository document reads preceded explicit snapshot read-mode selection; later local source inspection used the reviewed snapshot ZIP `437043a83cb02ae35bdb5747efebc214c01f0851b9ff1adcf80315fd436c7356`. Exact turn-local tool-call ledger was not initialized from first call and is not claimed.
