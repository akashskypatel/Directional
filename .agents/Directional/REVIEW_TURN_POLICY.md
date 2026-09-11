# Review Turn Policy — DURABLE, DO NOT DELETE

**Authoritative for every REVIEW, REVIEW + PLAN, TB-REVIEW, CB-REVIEW and DEFN turn, including delegated
ones and same-agent reviews authorized by `AGENT_POLICY.md`.** Where another document lists review duties,
this one is the superset and governs; `ORIENTATION.md`'s durable header remains binding and is reproduced
here as §3.1.

## 1. Why this exists

Review turns kept completing with their *adjudication* correct and their *closeout* incomplete. Observed
misses: `ORIENTATION.md` left naming a superseded turn as "next" (twice in three delegated turns),
`ROADMAP.md` left stale across three turns, resolved warnings left standing as though current and
contradicting the bullet below them, and obligations issued by one review never checked at the next.

None of these are reasoning failures. They are closeout failures, and they are expensive in a way that is
easy to underestimate: a cold-start agent trusts the durable documents, so a stale one sends the next turn
to the wrong work, and an unchecked carried obligation silently expires.

The mechanism this policy adds is **visibility**: §5's closeout block must appear in the review record with
every row answered. A skipped duty then shows up as a missing row rather than as an absence nobody notices.
This is the same discipline the project already applies to runtime evidence — publish the receipt, so
"done" and "not done" stay distinguishable (`LESSONS.md` 160, 171).

## 2. Verification duties

A review adjudicates evidence; it does not accept a report as self-proving.

1. **Re-derive decisive claims from the bytes.** Hash the selector yourself; recompute the arithmetic; sum
   the owner outcomes. A number copied forward from the reviewed turn's own report is not independent
   evidence, and stale copied values have been found this way.
2. **Verify the accepted prefix is byte-identical.** The new selector's first *N* rows must hash exactly to
   the accepted selector. State the hashes.
3. **Re-derive any partition or classification independently.** If a turn bins REDs into causes, confirm the
   bins from source — that exactly the claimed identities share the claimed cause, and that none is
   double-counted or mis-binned.
4. **Test non-vacuity.** Green is not evidence when nothing could have failed. Ask whether the evidence
   distinguishes *proved* from *reached a vacuous branch*, whether a tamper matrix covers field families
   rather than one broad noun, and whether a newly added mechanism would change any outcome if deleted.
5. **Discharge or re-carry every obligation from prior reviews.** List them by id, each marked discharged
   (with the evidence) or carried (with its new owner). An obligation nobody names at the next review is an
   obligation that has quietly expired.
6. **Classify honestly.** A stable event requires accepted-green loss. Test-authority defects on an
   unpromoted package are non-stable — and saying so is not the same as saying the contract is proved.

## 3. Durable-document duties

These are the ones that get missed. Every one is mandatory; "nothing changed" is an acceptable answer only
when stated explicitly in §5.

### 3.1 `ORIENTATION.md` — update before closing, without exception

1. the **currency line** — turn ID and date;
2. **§3 Where we are** — selector authority, stable accounting, checkpoint status;
3. **§4 witness table** — if any witness's state changed;
4. **§7 Open problems** — re-ordered by current priority, **with resolved items removed or explicitly marked
   discharged**;
5. **§8 Recurring defect patterns** — if the turn found a new pattern or a new instance of an existing one.

**Item 4 has a failure mode of its own.** Adding the new state while leaving the superseded warning in place
produces a document that contradicts itself, and the reader cannot tell which bullet is current. When a
turn resolves something you or a predecessor flagged, edit that bullet — do not only append below it.

### 3.2 Other durable documents

- `CHANGELOG.md` — an entry for the turn. Amending a delegated turn's entry is correct; adding a second
  competing entry for the same turn is not.
- `Regression_Root_Cause_Tracker.md` — every new candidate or carried obligation, with root cause,
  falsifier, owner, and what is prohibited.
- `ROADMAP.md` — whenever checkpoint status moves. Check it even when the turn did not mention it.
- `Required_Green_Selector_Manifest.md` — whenever a selector is added or accepted.
- `LESSONS.md` — a new lesson only for a genuinely new pattern; otherwise cite the existing number.
- Closure records — when a checkpoint closes, including the reasoning for any exit conjunct whose
  satisfaction is not self-evident from the evidence. An unstated justification inside a closed checkpoint
  invites re-litigation later.
- Document consolidation under `CLEAN_UP_POLICY.md`, preserving durable facts before deletion.

## 4. Successor and boundary duties

1. **Freeze exactly one bounded successor**, with falsifiers stated **before** the build, and stop rules
   that name what would halt it.
2. **Do not fold unrelated work into a turn whose evidential value depends on holding variables fixed**
   (`LESSONS.md` 170). A control experiment with a second change makes its own prediction unfalsifiable.
   Carry such work to the next turn that legitimately touches that surface, and say so.
3. **Respect the turn boundary.** A REVIEW is runtime-free and mutates no product, test, fixture, selector,
   benchmark or build source. Repairing test source is Code + Build work, not TB work.
4. **Run `python3 .agents/Directional/tools/review_check.py boundary`** and record the result.
5. **Commit and push to `origin` on the working branch**, then verify with `git status -sb` that the branch
   is in sync. Pushing a different ref can exit 0 while landing nothing (`LESSONS.md` mechanics 79).

## 5. Mandatory closeout block

Every review record must end with this block, every row answered. A row that does not apply is answered
`n/a` **with a reason**, never left blank and never deleted. A review record without a complete block is
incomplete regardless of how sound its adjudication is.

```text
## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | <hashes, or n/a + reason> |
| Decisive claims independently re-derived | <what was recomputed> |
| Non-vacuity checked | <what could have failed, and how you know> |
| Prior obligations discharged/carried | <ids + disposition, or "none outstanding"> |
| Stable accounting | <events / categories / recurrences, debt, accepted package + selector> |
| New candidates/obligations recorded | <ids + tracker updated, or none> |
| ORIENTATION currency line | <turn id + date written> |
| ORIENTATION §3 / §4 / §7 / §8 | <updated, incl. superseded bullets edited — or n/a + reason each> |
| CHANGELOG | <entry added/amended> |
| ROADMAP | <updated, or n/a + reason> |
| Selector manifest | <updated, or n/a + reason> |
| LESSONS | <new number, or existing number cited, or n/a> |
| Consolidation under CLEAN_UP_POLICY | <what was folded, or n/a> |
| Successor frozen | <exactly one turn + where its falsifiers are stated> |
| Turn boundary held | <runtime-free; no product/test/selector mutation> |
| review_check.py boundary | <result> |
| Pushed to origin, branch in sync | <commit + git status -sb confirmation> |
```

## 6. For the agent reviewing a delegated turn

Reviewing another agent's review is itself a review turn and carries every duty above for its own output.
Two additions:

1. **Check the delegated turn's closeout block, not only its findings.** An adjudication can be entirely
   correct while its closeout left a durable document stale. When you find a gap, fix it in the same turn
   rather than only noting it — then record what you fixed.
2. **Apply the project's standards to your own requests.** An obligation you issued is subject to the same
   non-vacuity test as anything else: if a mechanism you asked for would change no outcome when deleted, it
   is inert, and saying so plainly is part of the job. Likewise, when a risk you raised turns out not to
   have materialized, state that in those words rather than letting the hardening imply a near miss.
