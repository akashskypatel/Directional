# M6-CP3-CB1-ENTRY-R4 — RA-50 R4-SID-01 A4 side pin regression

**Boundary:** Continuing R4 Code + Build. Test source only; **no Directional executable, test, benchmark, or TB497** is authorized here. This is not an R4 closeout and does not add a source-authored filled-side receipt.

## Authority and construction

- Independent RA-50 review `Architecture_M6_CP3_R4_Oriented_Terminal_Side_Authority_Review_Decision.md` discharges RA-43.2 and refuses a fictitious upstream filled-side owner. It identifies the trace-to-certificate pin at `SurfacePhaseFrontProduct::make`, and the separate A5 occurrence selected-face pin, as load-bearing. The transport comparison alone cannot detect global side inversion when the attached quarter-turn is self-inverse (0 or 2).
- Source snapshot: exact `2ddf6fa143f61335fbfba511943d5e9cdde3dbe6`, workflow `38338458218`, artifact `11786485593`, outer ZIP SHA-256 `f8224469955ec46e12f74c1d29b0c895e4de05f002cd227060ce15677de837c6`, verified 5,554/5,554 source SHA256SUMS and the internal source archive checksum. `runtimeExecution=false`.
- New separate test `M6CP3.CheckedA4RejectsGlobalHardRailSideSwapWithSelfInverseTau` uses the existing real pipeline-produced constant-field, open hard-rail fixture, requires a real paired certificate with nonidentical face attachments and both endpoint transports satisfying τ=τ⁻¹, and swaps both attachment faces, both corresponding source-star paths, and carrier orientation at both endpoints. Each selected endpoint's composed τ must remain unchanged; the checked A4 factory must nevertheless reject `InvalidSourceAuthority` at the external trace attachment pin. A vacuous certificate-only self-authentication test is prohibited by RA-50.

## Evidence boundaries and follow-up

- The baseline fixture and the rebuilt checked factory share unchanged source mesh, field atlas, front edges, cells, contacts and hard-feature authority. This tests the A4 trace attachment pin, **not** the distinct A5 occurrence selected-face pin. A5's face-identity check must remain separately protected; no test is credited until executed during an authorized TB turn.
- Verification required: exact-base patch checksum and forward/reverse/whitespace validation; Google Drive dispatcher apply with semantic commit and owner staging retirement; pinned eight-target GMP/GMPXX compile artifact with all checksums, source SHA, generated linkage and `runtimeExecution=false`. Source compilation is not runtime acceptance.
- RA-43.1/43.4 global disposition, RA-46.5 remaining consumer first-rejections, RA-47.12 runtime, 39 endpoint + 34 Phase10 + seven DCEL + 88 accepted CP2 losses + six CP3 positives, and genuine odd-τ multi-carrier proofs remain open. Frozen 497 selectors, product API/ABI, validators, and recovery behavior are unchanged. RA-49.5 stays deferred to Definition. Ledger 66/17/49, debt 1; CP2 491/491 accepted; R3 403/497 rejected.
