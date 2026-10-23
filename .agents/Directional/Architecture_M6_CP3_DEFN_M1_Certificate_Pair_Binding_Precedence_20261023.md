# DEFN-M1 — hard-rail certificate/consumer rejection precedence (2026-10-23)

**Turn:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` (documents only). **Disposition: unresolved architecture stop; not an approved corrective CB.** Evidence: semantic source `4473e41e94a35f1bf189fa046e86bac92c7391fb`, inspected in exact snapshot `9e61f4c0765870c6db421357940966ded9f041b4`; TB29 artifact `12481556884`; RA-142 supersedes conflicting six-row scope in the plan/RA-141.

## 1. First-rejection audit

1. A4 `SurfacePhaseFrontProduct::make` (`src/geometry/SurfaceCellTracing.cpp:8439+`) authenticates the A3/source inputs and certificate/rail domains before inspecting edge pairs. Its certificate loop at `8814–8841` checks indices, then `HardRail` kinds, **both** `oppositeEdge` values, **both** `railId`s, `first.route == certificate.route`, `second.route == certificate.route.reversed()`, and distinct source topology regions. Any disagreement returns `InvalidSourceAuthority` with site `certificate-pair-binding`.
2. The A4 per-edge `oppositeEdge` reciprocity check (`:9331–9353`) later returns `InvalidOppositeEdge`; the certificate check masks it for 211/219. A4 certificate endpoint/source attachments and A3 transition evidence continue after the pair-binding clause. Do not delete these certificate-authentication guards.
3. Once A4 publishes, A5 `SurfaceOccurrenceComplexProducer::produce` (`src/pipeline/RemeshPipeline.cpp:~4890–5090`) first verifies each HardRail route using `exact_interior_route_valid` (`HardRailRouteAuthorityInvalid` → adapter `InvalidHardRailAuthority`), then rail owner, cross-region, reciprocal reversed route, hard-feature carriers (`HardRailOwnerMismatch`/`HardRailRegionMismatch`/`HardRailRouteMismatch` → `InvalidHardRailTransport`), and only then constructs the placement/certificate evidence. A5's later certificate lookup requires exact edge pair, rail and first route (`:5040+`). A6 consumes A5 evidence; the adapter maps typed errors. RA-15, RA-16 §5 and RA-19 freeze this order.
4. `tests/SurfaceCellTransitionQuotientTests.cpp:2551–2563` `materialize` maps **every** rejected A4 construction to `InvalidPhaseFrontProduct`, obscuring an A5/pipeline code. Six TB29 failures measured `code=0;sourceAuthoritySite=certificate-pair-binding;certificate=0;rail=2`; four additional members are statically shown to reach that clause (RA-142.2). Their site strings were not measured.

## 2. Frozen M1 ownership matrix (exactly ten)

| Identity | Tamper / tested behavior | Frozen first owner and outcome | Current first clause / evidence | Needed first rejection |
|---|---|---|---|---|
| `focused30:3` | Publish valid front, then missing/duplicate/malformed A5 relation endpoints | A5 `RelationEndpointMissing` / `UnownedRelation`, by variant | A4 `certificate-pair-binding` **measured** on fixture setup | Valid baseline passes A4; A5 `publish_records_for_validation` owns later tamper |
| `focused30:22` | Append duplicate step to first HardRail route | A5 `HardRailRouteAuthorityInvalid` or `InvalidHardRailAuthority`; adapter `InvalidHardRailAuthority` | A4 pair-binding **measured** | A5 `exact_interior_route_valid` before pair transport |
| `focused30:23` | Same route tamper; checks precedence | A5 route authority then adapter `InvalidHardRailAuthority` | A4 pair-binding **measured** | Same A5 route-authority clause; no transport preemption |
| `selector:139` | Change second route to a different pair's route | A5 strict pair reciprocity → `InvalidHardRailTransport` | A4 pair-binding **measured** | A5 `first.route != second.route.reversed()` |
| `selector:140` | Give the two sides differing rail IDs | A5 strict pair owner → `InvalidHardRailTransport` | A4 pair-binding **measured** | A5 rail-owner mismatch |
| `selector:142` | Give second route same (not reversed) orientation | A5 strict pair reciprocity → `InvalidHardRailTransport` | A4 pair-binding **measured** | A5 reversed-route mismatch |
| `selector:211` | Set opposite side `oppositeEdge` to itself | A4 `InvalidOppositeEdge` | A4 pair-binding **static**, TB code 0 | A4 global reciprocity before binding |
| `selector:219` | Set first `oppositeEdge` to −1 | A4 `InvalidOppositeEdge` | A4 pair-binding **static**, TB code 0 | A4 HardRail counterpart-required + reciprocity before binding |
| `selector:227` | Duplicate route's transition topology | A5/pipeline `InvalidHardRailAuthority` | A4 pair-binding **static**; adapter shows `InvalidPhaseFrontProduct` | A5 individual exact-route authority before pair check |
| `selector:230` | Substitute wrong interior-transition ID | A5/pipeline `InvalidHardRailAuthority` | A4 pair-binding **static**; adapter shows `InvalidPhaseFrontProduct` | A5 individual exact-route authority before pair check |

## 3. Option audit and explicit stop

- **(a) Structural-first with typed A4 binding:** fixes `211/219`, but A4 still rejects the deliberately tampered fronts in `focused30:22/23` and `selector:227/230` *before* A5; `focused30:22/23` require A4 success. Typed A4 failure is not A5 authority.
- **(b) Binding-first with field-specific errors:** preserves A4 rejection but cannot satisfy those published-front assertions, and `materialize` masks the factory error. Merely aliasing the error name is insufficient and violates independent ownership.
- **(c) Defer A5-owned pair/route checks:** would enable A5 precedence and preserve the final pipeline's fail-closed behavior, **but** if A4 still returns an authoritative checked product on a mismatched `edge.route`/`railId`/`oppositeEdge` and certificate, the present A4 *edge-to-certificate binding invariant* is relaxed. A5's later certificate lookup rejects, but later rejection is not equivalent to A4's immutable product guarantee. No independently reviewed split between (i) A4 certificate authenticity and (ii) A5 edge-to-certificate association authorizes this weakening today.

**Decision:** no option is yet proven to satisfy *all ten*, **and** retain A4 certificate binding, without a test change or disabling a guard. Invoke RA-142.4/plan STOP: return to independent architectural Review before a corrective CB. Review must decide whether the checked A4 product type may explicitly represent *pending A5 binding*, with a separate non-consumable/untrusted state, or whether the frozen downstream test ownership and A4 product invariant require a higher-level contract change. Neither change is authorized by this DEFN.

## 4. Non-weakening obligations (unresolved until Review approves an owner split)

| Forgery / invalidity | Required rejection and named guard |
|---|---|
| Missing certificate / duplicated or reordered pair indices | A4 `certificate-pair-indices` and missing/uniqueness guards |
| Forged certificate with wrong source attachment / A3 transition or source star | A4 source-attachment and A3-certificate checks; never infer certificates from untrusted edges |
| Wrong rail or counterpart identity | A4 `InvalidOppositeEdge` for broken opposite structure; A5 `HardRailOwnerMismatch` for unequal IDs; certificate-to-edge agreement remains mandatory before downstream acceptance |
| Reversed/mismatched route or invalid route topology | A5 `HardRailRouteMismatch` / `HardRailRouteAuthorityInvalid` with RA-15 route-before-pair precedence; exact certified route must still match prior to acceptance |
| Same source topology region across HardRail pair | A5 `HardRailRegionMismatch` or existing A4 binding; no same-region HardRail publication into A6 |

## 5. Corrective TB predictions and falsifiers (conditional; no runtime executed)

- Ten M1 identities must meet the per-row frozen outcomes **without modifying selector/test expectations**; focused30:3 must publish its valid front and reach its independent A5 relation mutation, focused30:22/23 must publish their deliberately invalid-route drafts then reject in A5; 227/230 must not collapse to `InvalidPhaseFrontProduct`.
- The **seven non-M1 factory rows** remain separate: `selector:220,221,296,302,304,439` still reject at `face-gauge-missing`, `cp3entry:4` at `open-rail-chain`. The direct periodic-owner fixture (TQ:~358) does not supply face gauges; do not reinterpret it as evidence that the six are solved.
- All **nine TB29 controls** must continue to PASS; A7/D3/D7 negative controls must remain non-vacuous; A4 forged/absent certificates must still fail. A published A4 product with unchecked certificate binding, any lost A5 guard, any changed frozen error, or unexpected green from a malformed input **falsifies** a proposed contract.
- Preserve stable **66/17/49**, witness debt **1**, CP2 **491/491 accepted**, R3 **403/497 rejected**, TB28 **462/497 candidate only**, RP-01 open, RP-02 unreached, Gate C suspended. The 44-case TB29 is diagnostic, not acceptance.

## 6. Exclusions and distinct owners

- `selector:220,221,296,302,304,439` → A4/A6 source-face-gauge/certificate owner (separate DEFN). `cp3entry:4` → A4 open-rail-chain owner.
- `selector:189–195` → A3 cycle-locus provenance; `selector:442` → A3 singularity/fixture authority. `focused30:12` → A5 occurrence HardRail transport/relabelled gauge owner.
- `cp3entry:1/2` → independent producer-witness owners (periodic odd gauge / hard-rail midline). The other **nine** untyped rows (excluding 211/219/227/230) → separate first-failure/call-site classification. `DEFN-T1`/fixture debt/497 census/`DIAG-RETAIN` remain later Review-sequenced tasks.

**Next boundary:** independent Review of this incompatibility; **no** code, tests, selector, build, TB, fixture, or successor work authorized by this stopped definition.