# `M6-CP2-CB1-VERIFIER` — Independent Verifier Code + Build Plan

> **HELD until `M6-CP2-DEFN-REV` accepts or amends the Definition.** This plan is not implementation authority before that Review.

**Type:** Code + Build only; runtime forbidden.
**Definition authority:** `Architecture_M6_CP2_Definition_Record.md` plus the accepted Review amendment, if any.
**Entering runtime:** `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`, 479/479.
**Accounting:** 60 / 16 / 44; debt 1.

## Goals

1. Add record-view exports for A5/A6/A7 and `SurfaceProductVerifier`; no unchecked product factory.
2. Implement only frozen §6.2 elementary recomputations and typed report/failure ordering.
3. Implement exact A5→A6 and A6/A5→A7 certificate-chain binding; no replacement search/substitution.
4. Integrate verifier immediately after successful A7 and before adapter projection; fail closed on findings.
5. Replace optimizer component/sheet self-check with class-wide `vertexChartAuthority` membership as a reject-only projection safety check.
6. Add the three D3 wedge tampers and the independent weld-pinched record-view manifoldness witness.
7. Create `Architecture_M6_CP2_Required_Green_Focused_12.txt` with the 12 Definition-frozen identities and no others.

## Frozen tests

Use the 12 identities and exact order in `Architecture_M6_CP2_Definition_Record.md` §7. Identity29 and focused-30 remain unchanged.

## Static/build checks

- `git diff --check`.
- selector449 SHA-256 remains `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.
- focused-30 bytes remain unchanged and are not copied into CP2 focused-12.
- no unchecked A5/A6/A7 constructor/factory is added.
- verifier implementation does not call producer search/repair/canonicalization/fallback routines.
- compile/package only through `.github/workflows/agent-compile-reusable.yml`, mandatory GMP/GMPXX, standard eight targets, `runtimeExecution=false`.
- no generated Directional test, benchmark, discovery, CLI, help/version command, `ctest`, fuzzer or custom input executes.

Compile-green successor: immutable artifact-only `M6-CP2-TB1-VERIFIER-EXEC`, exactly **491** fresh processes (focused30 + CP2-focused12 + selector449), then mandatory Review.

## Stop rules

Stop for Review if implementation requires changing A5/A6/A7 semantics; adding a production unchecked factory; searching/substituting equivalent authority; weakening any existing producer validation; changing selector449/focused30/routing449; or if the verifier rejects an accepted row once TB runs. `G4-B002` remains open and CP3-owned for direct production proof.
