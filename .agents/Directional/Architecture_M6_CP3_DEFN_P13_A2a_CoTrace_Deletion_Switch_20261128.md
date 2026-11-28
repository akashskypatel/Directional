# M6-CP3-DEFN-P13-A2A-COTRACE-DELETION-SWITCH — activating claimed co-trace deletion (2026-11-28 UTC)

## Situation

Activates DESIGN Amendment 35 in production: `deleteClaimedCoTraces` defaults to true in every derivation (make, validation, make_from_candidate, diagnose). `false` remains only to observe the traced network before step-7 selection (tests, tracing diagnostics, unstaged slide-entry controls), the status `stopAtLaterSlideEntry` already has. One compile-only CB is frozen with the TB-EXEC-194 contract. Runtime-free.

## SW1 — Censuses (TB-REV-193 obligations 1–3)

- **27 sphere rows:** 7 assertion rows change (393, 963, 968, 971, 978, 979 assert 24 traces; 648 asserts 18/30/14), 5 print-only (644, 645, 686, 698, 858), 13 unchanged; 397 unchanged (both terminal kinds survive), 1006 unchanged once its lookup is by id.
- **Readers:** no src reader indexes by trace id; `originByPort` is built over all ports, so a port without a trace is unused; region corner ownership accepts a deleted-trace port because the claimant arrival ends at the same singular node; `arrivalPort` is read only inside SurfaceCellTracing.
- **Downstream:** on the sphere's legacy-fallback route no stage after GlobalTopologyPlan reads the A2a network or the plan for an accept/reject decision (seeds come from singularity ports; the phase-front producers decline a singular domain at entry). The flip therefore cannot unlock downstream stages on the sphere; it changes A2a/plan products, their identity hashes and diagnostic prints.
- **Cost:** the deletion runs after tracing, never re-traces, and is linear-ish (classification over arrivals × rays, one candidate copy); tracing's O(T²) scans dominate. It runs in each of make's three canonical derivations.

## SW2 — Decision

Keep the option as a control with production default true (not removed). The author's STOP items showed tests whose subject is the tracing loop itself: row 393 witnesses the head-on mutual termination of traces 4/6/15/19, which selection removes; row 1013 needs the pre-deletion candidate; the unstaged controls in 978/979/1006 compare against pre-activation tracing. Those observe the traced network with `false`; everything else, including all production paths, deletes. A build and its validation always use the same value.

## SW3 — CB-219 test changes (no assertion weakened)

- 24 → 14 traces in rows 963, 968, 971, 978 (staged), 979 (staged): measured by TB193 row 1012.
- Row 648: 18/30/14 → 12/18/8: V = 12 network nodes (no cut), E = 6 whole arrivals + 4 split arrivals × 2 + 4 stopped traces = 18, F = 2 − 12 + 18 = 8; the same count reproduces 18/30/14 before deletion.
- Row 971: contact nodes 12–15 → 8–11 (surviving old ids 0–7 and 12–15, dense re-index in old-id order); slides 10, splits 4, whole/prefix/suffix 6/4/4 unchanged (every slide and split contact belongs to a kept trace).
- Row 1006: `laterEntryStops` stays 4 (traces 5/8/17/20 on walls 21/22/0/1, all kept).
- Positional `traces[id]` lookups replaced by id lookups with existence assertions in rows 963, 971, 978, 1006 (positional lookup was always wrong once D13 made ids non-dense); row 968 prints ids.
- Row 1012 asserts the EE3 facts on the production network, rejects a candidate with a cleared `arrivalPort`, and compares against the deletion-off build (24 traces, no `arrivalPort`, different digest) so it fails if production stops deleting.
- Traced-network observers with `false`: row 393 (all assertions and name unchanged), row 1013 (input from the deletion-off build), unstaged runs of 978/979/1006, the trace-scale and contact census diagnostics. Row 669 compares the census digest with a deletion-off build (its relation "census sees the same network as a traced build" is unchanged; it no longer compares against the production network).

## SW4 — Frozen CB and TB contract

See the [exact manifest](gates/Architecture_M6_CP3_CB219_TB194_CoTrace_Deletion_Switch_Exact_Manifest.md).

## SW5 — Risks carried to TB-EXEC-194 (falsifiers, STOP not repair)

- Every other fixture with singularities now runs the deletion. An arrival matching no port or several fails `make` with a typed `CoTraceDeletion…` condition; a claim on another fixture changes its network. Mechanical fixture claims would change rows 1010/1011 (`retraced == 4`).
- Downstream assertions in 648, 971, 972, 979 are unchanged but have never run on the 14-trace network.
- O52 (slivers 2/4) and DD5 unequal sides remain for the corners DEFN; O50, B1 held, B2 unmeasured; stable 67/17/50, debt1/deferred81.

## SW6 — Turn sequence

1. `M6-CP3-CB-219-P13-COTRACE-DELETION-SWITCH` (compile only) → 2. `M6-CP3-TB-EXEC-194` → 3. `M6-CP3-TB-REV-194` → 4. `M6-CP3-DEFN-P13-A4-DISC-CORNERS` + O52 → Vase row → A4 unequal-side construction.
