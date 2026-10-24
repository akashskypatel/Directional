# TB24 — Torus A5 seam-face diagnostic harvest (2026-10-21)

**Canonical turn:** `M6-CP3-TB24-RP01-TORUS-A5-SEAM-FACE-HARVEST` (Test + Benchmark; immutable artifact only).

## Authority and immutable execution

- CB23 semantic source: `e859175333f879273a75e3bfc321600e451048aa`.
- Compile package artifact: `12355892070`, ZIP SHA-256 `5215e5c216cde5cd45d851d36c9aa9b2a62de496aa78db2aac54d828996af91f`.
- Harness executor commit: `04a1799b9bab042c254e9a618ecba5afbccfefad`. Harness SHA-256 `f0b30909d598b451603ff90f4c228af9ceae49628e6b91f7d2e1e0c1cea1bd84`. Rendered frozen harness SHA-256 `8ccc47a0dabb94f36f8ce39ff448f4f2b0371f68841aa29f9c6c2f43408c2635`.
- Dispatcher request commit: `840eccf1bbdf900d5e4750f7c8110e95f097866e`.
- [Workflow run 39641426480](https://github.com/akashskypatel/Directional/actions/runs/39641426480) GREEN; immutable result artifact `12364838156`, outer ZIP SHA-256 `dcf42df92170fa82d1adca54b5fc480ad7f22c6ae45f1835ebde3d9c037220d3`.
- All 13 result-manifest entries verified against raw result files. Original 28/28 package checks, source commit and source tar digest, frozen selectors, original executable/runtime-GMP dependency, pre/post package/source/execution-view inventories checked by harness.
- `9/9` selected and executed in independent processes; 0 skipped; **three predicted A5 RED**, **six guard/control PASS**. `site_bad=0`, `ctrl_bad=0`, `postflight=True`. No recompile, relink, benchmarks, selector change or product/test/fixture mutation.

## Registered falsifiers

**P1 held:** the three A5 identities `focused30:20`, `selector:444`, and `focused30:28` all failed with one byte-identical complete site:

```text
relation-collinear-seam;region=0;seam=60,61;relation=0:1,1:0;first=120/0;second=97/2;certs=1;cert0=120/0->97/2:first-face;sel=121/0,121/0;support=vertex,vertex;wedge=120/0+121/0,97/2;spanOnly0=forward
```

The site prefix through `cert0` matches TB23, while appended `sel/support/wedge/spanOnly0` occur in the registered order, agree byte for byte, and have no absent values.

**P2 held:** the atlas guard `selector:447` and all five controls (`cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`) PASS with no A5 site.

**Pre-registered branch evidence:** selected face `121/0` and `support=vertex` are consistent with the B-fan branch's vertex-61 fan (118/119/121/142 on sheet 0). `spanOnly0=forward` means dropping the two face-equality clauses permits a forward certificate in this particular recorded relation. This does **not** authorize removing the guard or implementing DEFN-ISO. Independent TB24 Review must adjudicate the binding and clause owner before corrective work.

## Disposition

The TB24 runtime harvest is complete and its P1/P2 predictions were observed. This report documents immutable candidate evidence, **not** accepted CP3 promotion. Stable 66/17/49, fixture debt 1, CP2 491/491 accepted, R3 403/497 rejected, TB21 candidate 449/497, selector 497 frozen; RP-01 remains open, RP-02 unreached, Gate C suspended.

Next boundary: independent TB24 Review; canonical Review ID `UNKNOWN` pending independent authorization. No Code + Build, DEFN-ISO or successor work is authorized inside TB24.

The complete independent raw logs and exact row hashes are in result artifact `12364838156` (`ledger.tsv`, `raw/1.log`–`raw/9.log`, `SHA256SUMS`, `execution-boundary.txt`, `seam-face-proof.txt`). Documentation synchronization to tracker/TODO/handoff/CHANGELOG and workflow-trigger cleanup remain closeout obligations.
