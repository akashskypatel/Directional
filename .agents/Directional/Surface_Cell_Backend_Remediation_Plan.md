# Surface Cell Backend Remediation Plan

## Current blocker

Gate 1 remains the earliest blocker. The second bounded live-transition artifact was tested exactly and did **not** materially advance the production plane: it remains deterministic at 106 traces / 9 arrangement cells / 12 completion candidates / 15 validation failures / no output.

The seam remains a valid direct 64-quad regression. All newly added source-vertex fan contract tests pass, but isolated contract success did not become production plane output.

## No-progress conclusion

Local predicate remediation is stopped. A third Gate 1 predicate-repair turn is not authorized.

The current evidence shows two architectural questions that must be resolved first:

1. the contract fixture reconstructs the plane with different indexing and directly injected target state rather than exercising the exact committed production route;
2. a typed phase-front failure can be overwritten by later generic completion diagnostics, while the pipeline continues from phase-front non-success into the older tracing/arrangement/completion path.

The next review must determine whether the regression is a bounded production-input/control-flow error or evidence that the mixed producer architecture needs a bounded replacement boundary.

## Required sequence

1. Execute `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Plan.md` with no production source/test changes.
2. Reconstruct the exact `plane.obj` + `plane.rawfield` production authority path.
3. Compare the last successful Gate 1 source `aea10409c73c490b92f78760b73191641ef823c6` against Gate 2 and current sources.
4. Explain why the exact plane does not produce direct phase-front output while the isolated fan test passes.
5. Decide whether applicable phase-front failure may legally continue into the generic producer path or must remain a first-class fail-closed producer outcome.
6. Choose exactly one bounded architectural correction or bounded producer replacement proof.
7. Only then authorize a new Code + Build turn.

## Acceptance discipline

Every eventual success still requires direct `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete provenance, strict validation, and deterministic hashes.

Bunny and vase remain mandatory production fixtures. Historical completion-suite failures and scheduler-sensitive validator timing remain secondary while Gate 1 is red.

GitHub workflow operations are available again for future authorized Code + Build compilation/artifact production, subject to the existing cleanup policy.
