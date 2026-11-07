# RA-109 — TB19 harvest report accepted; TB19 closed by Review; TB19A gains a static edge classification (2026-10-20)

**Turn:** `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-CLOSEOUT-REV`. **Inputs:**
- report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md` (commit `b2b2aa9c1`);
- the agent's handoff commits `2e71e6aeb` and `2c81346a0`;
- STATUS `IN_PROGRESS` (`74d81af6a`);
- TB19 artifact `12285225197`.

**Amends:** RA-108.5 (adds one item to the report). **TQ** = `tests/SurfaceCellTransitionQuotientTests.cpp` at `d2c7483cd`.

## RA-109.1 TB19 report accepted

- **Checked against the artifact ledger:** all 22 raw-log SHA-256 values and all 22 TB18 statuses match.
- **Rulings applied as written:**
  - the six torus rows are marked NOT MEASURED;
  - `focused30:12` has `product=0`, site `gauge-pin-consistency;edge=1,4` and detail `not streamed`;
  - the falsifier lines match RA-108.3, with the R-route NOT REACHED.
- **No adjudication** is made, as RA-108.4 requires.
- **Accepted** as TB19's harvest evidence. H-pin is still not ruled on; TB19-REV rules on it after TB19A.

## RA-109.2 TB19 closed

- **What remained open.** TB19 yielded `IN_PROGRESS`. Its own note said the TODO, CHANGELOG and regression-tracker updates were still pending.
- **Review finishes them.** These are shared durable records that every Review turn maintains anyway, so Review completes them in this turn.
- **TB19 is closed.** No implementation turn is scheduled for bookkeeping alone.

## RA-109.3 Handoff restored to the template

The agent's handoff departed from `Future_Chat_Session_Handoff_Template.md` in three ways:
- **Heading.** It replaced `## Mandatory next turn — … — EXACT NEXT` with `## Pending successor — … — NOT ENTERED`.
- **Contradictory state.** It marked the TB19 closeout `done` in the Turn Sequence, and called it "complete" in Currency, while STATUS said `IN_PROGRESS`.
- **Shortened lines.** It cut the `load_next` line, dropping "never Code + Build".

**Restored:**
- the template headings and fields;
- in Turn Sequence, only the next authorized edge and the frozen conditional edges, per the template. The past rows, including those Review added in RA-107 and RA-108, are removed; `TODO.md` and `CHANGELOG.md` hold the history.

## RA-109.4 Addition to TB19A: classify each torus edge statically

- **Basis.**
  - The torus witness declares 18 hard edges (`torus_row408_hard_edges`, TQ:908–927):
    - the minor cycle 0–3–25–37–49–61–0;
    - the major cycle 0–1–4–6–8–10–12–14–16–18–20–22–0.
  - The witness requires at least one of these edges to carry a nonzero Z4 matching (TQ:1617–1631).
  - The rectangle rows reject on a declared hard edge, (1,4).
- **Why it matters.** Whether each torus site's edge is one of the 18 hard edges decides whether the torus rows fall in the same rail-carrier domain as the rectangle rows. It is the input TB19-REV needs for the "rail carriers vs. periodic cuts" split.
- **Added to the TB19A report:** for each torus row that reports `gauge-pin-consistency;edge=a,b`, state whether {a,b}, as an unordered pair, is one of the 18 hard edges, and which cycle it is on.
  - This is a static lookup in the pinned source;
  - nothing is executed or changed for it, and it does not adjudicate.
- **Unchanged:** the RA-108.5 harness, rows, falsifiers G1–G4, STOP rules and boundary.

## RA-109.5 Sequence and accounting

- **Sequence:** TB19A → TB19-REV (mandatory, over the TB19 and TB19A reports) → [DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB] → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:**
  - 66/17/49, debt 1;
  - CP2 491/491;
  - R3 403/497 rejected;
  - TB18 candidate 448/497;
  - selector 497.

  `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.
