# M6-CP3-CB1-ENTRY-R4 — RA-49.2 duplicate terminal first-rejection regression

**Boundary:** Code + Build only. Canonical R4 remains open; TB497 is not authorized.

**Authority:** independent RA-49 decision `Architecture_M6_CP3_R4_Ambiguous_Terminal_Contact_Feasibility_Review_Decision.md` retains `ambiguous-terminal-contact` as reachable at A4 consumer `SurfaceCellTracing.cpp:19052`, forbids any weakening of checked A4 factory or bit-exact geometry, and retires only the unreachable `nonmanifold-terminal-star-spoke` fixture.

**Source snapshot:** `7c228ec451ab605e9a1b913ec2dca8a2c14db365`, snapshot workflow `38315391692`, artifact `11775764498`, outer SHA-256 `f6543c4e53c2ce783efb819d1a299c40e3198c7058fa614848d74677190dea3b`, `6541/6541` internal hashes verified. The verified snapshot is inspection authority only; any compile must use an exact applied GitHub commit.

**Focused change:** the existing rectangular hard-rail fixture builder optionally accepts the caller-supplied terminal contact map; a new regression starts from a positively certified production front, selects its first real A4 endpoint terminal ID, injects that same ID twice in the existing rail contact pair, and asserts that the first A4 consumer rejects with `InvalidHardRailRouteCertificate`, `EndpointAttachment`, and the diagnostic `a2bProbeFailure=ambiguous-terminal-contact`. It also excludes `no-exact-terminal-corner`. No source predicate or numerical tolerance is changed, and the downstream checked factory guard remains intact.

**Evidence boundary:** source diff validation only until the separate mandatory exact-source eight-target GMP/GMPXX compile is verified. Even a GREEN compile does not establish a runtime PASS. No binaries/tests/benchmarks are executed during R4 Code + Build. RA-49.5 validate-after-use architectural repair is referred to a future Definition turn, not implemented here.

**Outstanding R4 obligations:** RA-43.2 independently producer-owned oriented side binding; global RA-43.4 legacy diagnostic opt-out; remaining RA-46.5 first-rejection negatives; RA-47.12 field-aligned liveness; historic 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2 accepted losses / six CP3 positive gates and authentic odd-τ multi-carrier proof. CP2 491/491 accepted, rejected R3 403/497 (94 RED, 88 CP2 losses); ledger 66/17/49, debt 1, unchanged. No TB497 or successor.
