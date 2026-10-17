# M6-CP3-CB1-ENTRY-R4 — RA-49.2 duplicate terminal first-rejection regression

**Boundary:** Code + Build only. Canonical R4 remains open; TB497 is not authorized.

**Authority:** independent RA-49 decision `Architecture_M6_CP3_R4_Ambiguous_Terminal_Contact_Feasibility_Review_Decision.md` retains `ambiguous-terminal-contact` as reachable at A4 consumer `SurfaceCellTracing.cpp:19052`, forbids any weakening of checked A4 factory or bit-exact geometry, and retires only the unreachable `nonmanifold-terminal-star-spoke` fixture.

**Source snapshot:** `7c228ec451ab605e9a1b913ec2dca8a2c14db365`, snapshot workflow `38315391692`, artifact `11775764498`, outer SHA-256 `f6543c4e53c2ce783efb819d1a299c40e3198c7058fa614848d74677190dea3b`, `6541/6541` internal hashes verified. The verified snapshot is inspection authority only; any compile must use an exact applied GitHub commit.

**Focused change:** the existing rectangular hard-rail fixture builder optionally accepts the caller-supplied terminal contact map; a new regression starts from a positively certified production front, selects its first real A4 endpoint terminal ID, injects that same ID twice in the existing rail contact pair, and asserts that the first A4 consumer rejects with `InvalidHardRailRouteCertificate`, `EndpointAttachment`, and the diagnostic `a2bProbeFailure=ambiguous-terminal-contact`. It also excludes `no-exact-terminal-corner`. No source predicate or numerical tolerance is changed, and the downstream checked factory guard remains intact.

**Evidence boundary:** source diff validation only until the separate mandatory exact-source eight-target GMP/GMPXX compile is verified. Even a GREEN compile does not establish a runtime PASS. No binaries/tests/benchmarks are executed during R4 Code + Build. RA-49.5 validate-after-use architectural repair is referred to a future Definition turn, not implemented here.

**Outstanding R4 obligations:** RA-43.2 independently producer-owned oriented side binding; global RA-43.4 legacy diagnostic opt-out; remaining RA-46.5 first-rejection negatives; RA-47.12 field-aligned liveness; historic 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2 accepted losses / six CP3 positive gates and authentic odd-τ multi-carrier proof. CP2 491/491 accepted, rejected R3 403/497 (94 RED, 88 CP2 losses); ledger 66/17/49, debt 1, unchanged. No TB497 or successor.

## Applied source and compile verification (2026-10-12)

- The complete four-file patch from snapshot `7c228ec451ab605e9a1b913ec2dca8a2c14db365` (full SHA-256 `65107ace5ae9fcf2219963154354e5cd07cfbe14ff2e8285aedca24c36fb36f0`, diff-body SHA-256 `d6c816bd7e769f31cd3880f0fb1f2f99b8f8e201fa5b5354ae9d0ff05ae101b1`) was applied successfully by durable Drive dispatcher workflow `38315990345` to semantic source `ae6af23f4a14ad0e3105b185df31478f382229c6`. Verified exactly four paths: the focused Phase10 test, this record, the handoff, and `TODO.md`. The temporary staged Drive file was owner-deleted after success.
- The exact semantic source compiled **GREEN** through the mandatory eight-target GMP/GMPXX reusable workflow: dispatcher run `38316154434`, compile job `115033248216`, result artifact `11777170416`, outer ZIP SHA-256 `9d6d8c0d7cdbccb8e11bbc5d482ab5c518d919a9347f1c512a92a4d73b1a514e`. Local package verification: 28/28 manifest hashes; preflight/build exit `0/0`; all eight targets compiled; both `gmpxx` and `gmp` appeared in the authoritative generated linker command; all source-status records clean, `runtimeExecution=false`. No test or benchmark execution and no RA-49.2 runtime PASS are claimed.
- **Turn disposition:** `M6-CP3-CB1-ENTRY-R4` remains IN_PROGRESS with the previously listed obligations. TB497 remains unauthorized. This entry closes only this focused compile checkpoint, not R4.

## Additional RA-46.5 first-rejection witness (2026-10-12)

On the subsequent verified source snapshot `c8c4cc65bca673754cb74f0ed295ba08cfdaa251` (workflow `38317818824`, artifact `11777287283`, `6548/6548` manifest), a second independent Phase10 negative is added. It starts from the same accepted source-certified hard-rail route, retains the real source mesh and first terminal, and replaces only the contact's matching typed terminal with a different **valid source vertex** not among the rail's original two terminal IDs. The distinct pair is preserved; no trace geometry or A2b/A3 receipt changes. The first consumer must reject with `a2bProbeFailure=no-exact-terminal-corner` and must not select `ambiguous-terminal-contact`.

This is compile-only test source coverage, not runtime proof. No producer/consumer predicate, factory check, tolerances, ABI, frozen identity or reusable workflow was changed. Keep the other unadjudicated RA-46.5 negatives open.

### Applied and compile-verified foreign-terminal fixture

- The four-file patch (`39a6dd19dd5c775924fdc5320e098dbfb2bac60a4fb51b2afc0eb70151e8e502`, body `3b4d7075eea886f7b17dbfd70908691ec9135d07b9ae7132a70a271b9a4d7a85`) applied successfully through Drive workflow `38318409957` at exact semantic `54a58afdc00fae0e58662134ebb68845814b13ab`, with the four intended file paths verified. The consumed Drive stage was owner-deleted.
- Exact-source eight-target GMP/GMPXX compile **GREEN** in workflow `38318599087`; artifact `11777419642` outer SHA-256 `5d2bdc39adb200797de1e90650fa46f1df284f6e368bebb5f6bec9b7b61e8534`. Verified `28/28` package checksums, all 8 targets, preflight/build `0/0`, `gmpxx` and `gmp` on generated authoritative link, and empty source-status records. `runtimeExecution=false`; **no test or benchmark run**.
- This closes only the `no-exact-terminal-corner` compile checkpoint. Remaining R4 requirements and the separately authorized TB497 gate are unchanged. No runtime first-rejection PASS claimed.
