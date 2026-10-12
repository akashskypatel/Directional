# M6-CP3-CB1-ENTRY-R4 — RA-43.2 open-rail terminal provenance first-rejection regression

**Boundary:** same unfinished Code + Build turn. No runtime test, benchmark, or TB497 execution. RA-43.2 oriented producer side binding is **not closed** by this limited negative.

## Grounded first predicate

- Verified source snapshot: workflow `38324507316`, source/event SHA `4a68d108a592126a9443ae8644c2fcab2df6d181`, artifact `11780376487`, outer ZIP SHA-256 `5d8e62f5235db09aabc3ede41bd279ff468fec090c761268c9a94e49628edd36`, internal source tar SHA-256 `52dfffecdb294aea5302da16f2133b7916873f6bdfee604ab3ecfae0ac3f1ad4`, all **6574/6574** source manifest hashes verified, metadata `runtimeExecution=false`.
- `src/pipeline/RemeshPipeline.cpp::hard_rail_source_provenance_from_rails` publishes typed open-rail endpoint IDs from the existing feature-chain producer. Its product is passed into `tracingOptions.hardRailTerminalContacts` at the pipeline ingress; no independently oriented *filled-side* terminal-germ ownership is published by this data type. The full RA-43.2 producer/consumer architecture obligation therefore remains open.
- `src/geometry/SurfaceCellTracing.cpp::endpoint_certificate` first reads those contacts before `publish_phase_front_result` invokes the checked A4 factory (the RA-49 consumer-before-factory ordering). If a selected open rail lacks a contact and lacks separately published closed-chain provenance, the first rejection is `missing-terminal-or-closed-rail-provenance`; there is **no valid fallback to treating an open rail as closed**. The guard is load-bearing and its non-vacuous missing-contact fixture was not previously in the recent rectangular Phase10 regression set.

## Source-only regression

New `SurfaceCellAuthorityContractCutover.MissingOpenRailTerminalContactRejectsBeforeClosedRailFallback` in the existing Phase10 test source uses the actual accepted rectangular HardRail pipeline fixture, selects an actual open produced route, erases **only its** typed contact from an otherwise original contact map, and calls `build_fixed_plan_rectangular_hard_rail_network` with the existing fixed A2b/A3 plan. Assertions require `InvalidHardRailRouteCertificate`, `EndpointAttachment`, and exact first consumer diagnostic `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`, not a later/extraneous `no-exact-terminal-corner`. The witness is a source-valid missing authority record, not fabricated source geometry. The test is unexecuted; compilation only is allowed in this turn.

## Remaining R4 work

This test neither creates nor authenticates the **oriented source-face side/rail-interval/front-filled-side** occurrence demanded by RA-43.2. It also does not retire the RA-43.4 legacy standalone diagnostic opt-out, establish RA-47.12 runtime liveness, cover the outstanding `missing-terminal-A3-path`, `overlapping-terminal-sectors`, or `missing-or-nonreciprocal-terminal-A3` diagnostics, or recover the 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2-loss / six CP3 positive or true odd-τ multi-carrier gates. RA-49.5 validate-before-first-use is reserved for Definition. CP2 491/491 accepted and R3 403/497 rejected with 94 RED and 88 CP2 losses; ledger 66/17/49, debt 1 unchanged. No selector/test identity is renamed; TB497 remains forbidden in R4 Code + Build.
