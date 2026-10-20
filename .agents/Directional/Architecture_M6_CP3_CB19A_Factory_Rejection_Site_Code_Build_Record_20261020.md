# M6 CP3 CB19A — factory rejection-site corrective Code + Build (2026-10-20)

- Authorized scope: RA-106.3, RA-106.4 and RA-106.6; only `src/geometry/SurfaceCellTracing.cpp` and `tests/SurfaceCellTransitionQuotientTests.cpp` changed.
- CB19A source commit: `d2c7483cde8e65d6c35c5df06fa880465a4da46c`; earlier CB19 `1f73d0abd` compile failure retained in its separate record.
- Patch: SHA-256 `c7df5bbd081de16256b3dd23f38399666a822590f18661d481ebcb669a9edb8a`, base `5eb62406b48467e92cdb6b5689ce907d2633aaea`, apply run `39446123275`.
- Immutable compile: [run 39446712217](https://github.com/akashskypatel/Directional/actions/runs/39446712217), artifact `12275794192`, ZIP SHA-256 `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`.
- Eight requested targets compiled, GMP and GMPXX linked; preflight/build exit codes `0/0`; `28/28` packaged hashes; five source statuses empty; exact source SHA matched.
- `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; no tests, executable runs or benchmarks were performed.
- Corrective changes: 26 certificate/endpoint/junction labels use scope-local suffix lambdas; two gauge-pin labels use `std::string` first operand; TQ edge oracle checks both corners of face 0.
- Static label census: 47 uniquely named `InvalidSourceAuthority` returns in `make` (line numbers from CB19A packaged source):
- `atlas-binding` S:8469 | `region-empty` S:8489 | `face-gauge-missing` S:8497 | `face-gauge-shape` S:8506 | `gauge-pin-face-row` S:8522 | `gauge-pin-edge-key` S:8532
- `gauge-pin-edge-incidence;edge=` S:8542 | `gauge-pin-consistency;edge=` S:8560 | `hard-rail-source-edge` S:8598 | `hard-rail-incidence` S:8616 | `hard-rail-contact-missing` S:8628 | `closed-rail-contact-conflict` S:8636
- `closed-rail-distinct-vertices` S:8643 | `closed-rail-edge-coverage` S:8666 | `open-rail-chain` S:8675 | `closed-rail-cover` S:8682 | `rail-contact-endpoints` S:8690 | `rail-contact-source-vertex` S:8712
- `rail-transition-a3` S:8730 | `terminal-star-spoke` S:8765 | `certificate-pair-indices` S:8794 | `certificate-pair-binding` S:8808 | `certificate-attachments` S:8829 | `certificate-route-length` S:8835
- `certificate-open-interval` S:8852 | `certificate-closed-edge` S:8867 | `certificate-closed-interval` S:8892 | `certificate-rail-kind` S:8897 | `endpoint-carrier` S:8930 | `endpoint-kind-overlap` S:8936
- `endpoint-interior-point` S:8966 | `endpoint-source-vertex` S:8991 | `endpoint-a3-path` S:9008 | `endpoint-contact-path` S:9025 | `endpoint-contact-target` S:9032 | `endpoint-sector-overlap` S:9039
- `endpoint-no-contact` S:9048 | `junction-edge-continuation` S:9067 | `junction-hard-spokes` S:9088 | `junction-star-size` S:9095 | `junction-manifold-star` S:9117 | `junction-sector-step` S:9142
- `junction-sector-cover` S:9153 | `junction-next-carrier` S:9161 | `junction-transport` S:9172 | `certificate-final-carrier` S:9179 | `hard-rail-uncertified-pair` S:9192
- No selection, admission, predicate, fixture, harness, or acceptance contract changed; frozen 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 448/497 candidate, selector 497; `RP-01` remains open and `RP-02` UNREACHED.
- Next separately authorized turn: `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (artifact-only 22 identities, RA-105.6 amended by RA-106.5); mandatory independent TB19 review follows.
