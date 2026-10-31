# CB21 — Torus witness scope: Code + Build

- Turn: `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE`.
- Exact implementation source: `8453e19e6ac7d976a9cac45978ad31104a52f034`.
- Patch base: `0d23d5cf8f721a37328291711246be0908a5fe93`; patch SHA-256: `d2aac44eebf5bc354d9b8817d7968c80f3465e5214e2c3426e88f98c72330055`.
- Scope: only `tests/SurfaceCellTransitionQuotientTests.cpp`, 73 insertions, 47 deletions. No product, library, selector, harness or workflow modification.
- Implemented complete per-candidate reciprocal/holonomy and gauge census, selection prioritization, seven-count diagnostic receipt, and preserved the existing `cp3entry:1` D2 assertion with appended receipt.
- Patch apply run: [39540716878](https://github.com/akashskypatel/Directional/actions/runs/39540716878), success; applied exact source above.
- Compile run: [39540888446](https://github.com/akashskypatel/Directional/actions/runs/39540888446), success; eight required targets with GMP/GMPXX linkage.
- Package artifact ID: `12318897957`, name `m6-cp3-cb21-torus-witness-scope-result-39540888446`.
- Package ZIP SHA-256: `f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`.
- Package expires: `2026-10-28T03:54:02Z`.
- Package root `SHA256SUMS` SHA-256: `4726b88230cb81560ae5464327680a4199bcc7ce42a0e1de011728ba6c171bc0`.
- Packaged exact `source/source-8453e19e6ac7d976a9cac45978ad31104a52f034.tar.gz` SHA-256: `63b260ac5045c141b8918b6d2678a673450e49d82429826bc6614f6d44c98520`.
- Evidence verification: 28/28 packaged checksums pass; zero nonmatching hashes; preflight/build exits `0/0`; all packaged source statuses empty; `runtimeExecution=false`.
- No runtime tests or benchmarks executed. Direct success, selector-497 change, or D2 attainability are **not claimed**.
- Required successor: `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE-REV`, independent Review for static diff and TB22 predictions. 
