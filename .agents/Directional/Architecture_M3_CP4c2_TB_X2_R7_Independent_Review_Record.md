# M3-CP4c-2 TB-X2-R7-REV Independent Review and Plan

## 0. Verdict

`M3-CP4c-2-TB-X2-R7-REV` is **COMPLETE / REVIEW GREEN**.

**R7-0's stop was correct and the executor deserves credit for it.** Faced with a preflight mismatch it did the
one right thing: it refused to substitute the observed values for the plan's constants, because doing so would
have silently rewritten executable authority mid-run. It stopped before the first Directional process, left the
package untouched, and re-verified integrity afterward.

**The defect is fabricated hash constants in documentation, and it is fully localized.** No product semantics,
no selector bytes, and no immutable package are involved. `M3-CP4c2-TB-X2-R7-ORCH-01` is adjudicated
**ORCHESTRATION / DOCUMENT-AUTHORITY / NON-STABLE**, and the corrective is documentation-only.

**Proof that these were fabricated rather than stale:** the R7 plan's expected value for selector 357 is
**63 characters long**. A SHA-256 is 64 hex characters. A stale-but-real digest would still be 64. §2 gives the
full mechanism, and **part of the cause is mine** — §3.

A bounded, documentation-only `M3-CP4c-2-DOC-R1` is **AUTHORIZED** under measures **AE0–AE9**, after which R7
retries unchanged. No runtime, build, compile, package, or product/test/fixture/selector change was made in this
review.

## 1. Independent verification — all six hashes recomputed from bytes

Not read from any document. Computed from the committed selector files in this working tree:

| authority | source | recomputed SHA-256 |
|---|---|---|
| accepted first 316 | `head -316` of `Architecture_M3_CP4c1_Required_Green_Selector.txt` | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
| accepted first 346 | `head -346` of the same file | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| accepted first 353 | `head -353` of the same file | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` |
| accepted 355 | the complete file | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| frozen candidate 357 | `Architecture_M3_CP4c2_Required_Green_Selector_357.txt` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| frozen candidate 358 | `Architecture_M3_CP4c2_Required_Green_Selector_358.txt` | `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` |

**These are the authoritative values.** They match the immutable package, R6-EXEC's successful preflight, and
`ORIENTATION.md` exactly. **The selector bytes never changed**, and the accepted authority chain is intact.

`ORIENTATION.md` is confirmed correct as a hash reference and was used by R7-EXEC as corroborating authority —
which is precisely what it was created for.

## 2. The mechanism, and the proof it was fabrication

Compare each failing constant against truth:

| selector | R7 plan constant | truth | shared prefix | shared suffix | length |
|---|---|---|---|---|---:|
| 346 | `20d3b0b1b942af39…4ac3e46a` | `20d3b0b1400d5cab…20f3e46a` | `20d3b0b1` | `3e46a` | 64 |
| 353 | `51ff96d7dd690510…0b958ac6a5` | `51ff96d72e1c2c88…59f71ac6a5` | `51ff96d7` | `ac6a5` | 64 |
| 357 | `b896d0db98bdf3ea…f17464dc70` | `b896d0db7f26aeb0…e364dc70` | `b896d0db` | `64dc70` | **63** |
| 358 | `6eda3aadbeaa4b99…86b64fbe62` | `6eda3aad83de81fc…1bb64fbe62` | `6eda3aad` | `b64fbe62` | 64 |

Every failing constant **shares the first eight hex characters and the trailing characters with the truth, and
differs only in the middle.** That is the exact signature of an abbreviated digest of the form
`PREFIX…SUFFIX` being expanded back into a full-length string by inventing the interior.

And 316 and 355 — the two that **passed** — are the two whose full values were readily available in
un-abbreviated form in the sources the author had open.

**The 63-character value is the clincher.** No hash function produces 63 hex characters. A stale digest, a digest
of a different file, or a digest from an older commit would all still be 64. A value of the wrong length can only
have been assembled by hand, and **nothing in the authoring path checked its length** — the malformed string
travelled from the CB5 closeout report into the R7 plan and was only caught at R7-0's byte comparison, a full
turn later.

## 3. My share of the cause, stated plainly

`M3-CP4c-2-TB-X2-R6-REV` measure **AD0** wrote the six hashes in abbreviated form:

> `316 601ce2b6…0193c, 346 20d3b0b1…3e46a, 353 51ff96d7…ac6a5, 355 e9d88f11…5afeaa, 357 b896d0db…64dc70,
> 358 6eda3aad…b64fbe62`

The four values later fabricated are exactly four of those six abbreviations, and the fabricated strings carry
exactly those prefixes and suffixes. Full values did exist elsewhere — in `ORIENTATION.md` and in R6-EXEC — so
the abbreviation did not *force* the error. But it supplied a template that reads like a value, sits in a
measures table where values belong, and can be expanded into something plausible.

**The rule I should have followed, now made durable in AE3: a cryptographic digest is either written in full or
not written at all.** An ellipsis inside a hash is not an abbreviation of a value; it is a *reference* wearing a
value's clothes, and a later reader cannot reliably tell the difference. Where brevity matters, name the file
and say "recompute", which is both shorter and unforgeable.

## 4. The deeper design point — compare against bytes, not against prose

Correcting four strings would clear this instance and leave the class intact. Two structural observations:

**4.1 A transcribed constant cannot distinguish the two things it is meant to detect.** A preflight
compare-to-constant exists to catch *selector drift*. But a mismatch has two possible causes — the selector
changed, or the constant was mistranscribed — and the check cannot tell them apart. R7 spent an entire turn
establishing that it was the second. **The constant must therefore be derived, at plan-authoring time, by
computing it from the named committed file**, and the plan must record the file path and the derivation, not
just the number. Drift detection is preserved; transcription risk is removed.

**4.2 A format check would have caught this at authoring, for almost nothing.** Any expected digest must be
validated as exactly 64 lowercase hex characters at the moment it is written into a plan or report. The
63-character value would have failed instantly, one turn earlier, before it ever reached an executor. **AE4**
makes this mandatory and it is the single cheapest control in this correction.

## 5. What R7 did right, and must be preserved

Recorded so the corrective turn does not "fix" any of it:

- **The hard stop before runtime.** The frozen rule said any preflight mismatch is a hard stop and the package
  must not be repaired. R7 obeyed it exactly.
- **It refused to self-heal.** It explicitly did not substitute observed values for planned constants. That
  restraint is the difference between a one-turn documentation defect and a silently rewritten authority.
- **Post-preflight integrity check even though runtime never started.** It re-hashed and re-statted the package
  and source and re-ran the internal manifest, all passing. That is the R5-ORCH-01 lesson correctly generalized:
  finalization evidence is produced on every exit path, not only after runtime.

## 6. What remains unmeasured, and it is now seven turns and eight

- **`PR8-R043`** — RESOLVED AT LOCUS, closure still pending a full 355/355. R7 did not run ordinal 305.
- **`PR8-R044`** — the CB5 correction is **compiled but runtime-unproved**. R7 did not run ordinal 310. The
  semantic/provenance digest split, the orbit-index resolution and the AD5 diagnostic all remain unverified at
  runtime.
- **`M3-CP4c2-TB-X2-CAND-04`** — the prescribed sphere's `CellularityNotEstablished` is now **unlocalized for an
  eighth turn**. D2 has been scheduled and not run in R2, R3, R4, R5, R6 and R7.

**Every one of those six stops was individually correct.** But the pattern from R6-REV §8 now has one more
instance, and it has strengthened rather than weakened: **CP4c-2's diagnostics sit behind a full accepted-prefix
gate that has failed for a different reason every single time, and this time it failed for a reason that had
nothing to do with the product at all.** §7's AE8 acts on that, in the narrowest way that does not weaken any
gate.

## 7. Measures **AE0–AE9** for `M3-CP4c-2-DOC-R1`

This is a **documentation-only** turn. No compile, no package, no runtime, no product/test/fixture/selector
change.

- **AE0 — recompute, do not copy.** Derive all six hashes yourself from the committed selector files, exactly as
  §1 does: `head -316`, `head -346`, `head -353` and the whole of
  `Architecture_M3_CP4c1_Required_Green_Selector.txt`, plus the two CP4c-2 candidate files. **Do not copy them
  from this record, from `ORIENTATION.md`, or from any other prose** — including the table in §1. Independent
  derivation is the point; agreement with §1 afterwards is the check.
- **AE1 — correct exactly the four wrong constants**, in the CB5 closeout report's AD0 audit and in the R7 plan's
  preflight table. **Do not touch any selector file.** Confirm afterwards that all six selector files are
  byte-identical to their pre-turn state, and report the confirmation.
- **AE2 — sweep for the same defect elsewhere.** The abbreviated-then-expanded pattern may have propagated.
  Search all of `.agents/Directional/**` for 64-hex-looking strings that are presented as selector hashes and
  verify each against the recomputed truth. **Report the count checked and the count corrected**, even if that
  count is zero. A silent sweep is not evidence a sweep happened.
- **AE3 — the abbreviation rule, made durable.** Record in `LESSONS.md` that a cryptographic digest is written
  in full or replaced by a file reference plus "recompute" — never as `PREFIX…SUFFIX` in a position where a
  value is expected. Apply the rule going forward; **do not retro-edit historical records** to expand their
  abbreviations, which would be a large destructive edit for no evidential gain.
- **AE4 — format validation, mandatory.** Every expected digest written into a plan or report must be validated
  as **exactly 64 lowercase hexadecimal characters** at authoring time. State in the report that the check ran
  and what it covered. This alone would have caught the 63-character value one turn earlier.
- **AE5 — plans name their derivation.** Any future preflight hash table must record, for each row, the
  **source file and the derivation** (`head -N <file>` or the whole file) alongside the value, so a later reader
  can regenerate it rather than trust it. Update the R7 plan's table to this form as part of AE1.
- **AE6 — `ORIENTATION.md` is durable and updated every REVIEW turn.** See §8. Add the durable marking to the
  document itself, to the handoff's durable policy list, and to the mandatory end-of-turn checklist. Update its
  "where we are" content as part of this turn.
- **AE7 — preserve R7's correct behaviour.** Do not alter the hard-stop-on-preflight-mismatch rule, the
  no-self-heal rule, or the post-preflight integrity check that runs even when runtime never starts. §5.
- **AE8 — one narrow sequencing change, and its justification.** After AE1–AE5, R7 retries **unchanged in
  content**, with one ordering amendment: the **non-gating** diagnostics R7-2 through R7-5 execute **before** the
  accepted-prefix gate, and their evidence is published regardless of the gate's outcome. Justification: they
  are non-gating, grant no credit, mutate nothing, and cannot affect the gate's result; sequencing them first
  costs nothing and ends an eight-turn evidence drought. **The accepted-prefix gate itself is unchanged, still
  mandatory, and still decides acceptance** — this reorders publication, not authority. If the implementation
  agent judges that this ordering would let a diagnostic observe state the gate would have rejected, **stop and
  say so** rather than proceeding: that judgement is exactly what would make the change unsafe.
- **AE9 — prohibited.** Editing any selector file; changing any product, test, or fixture; compiling or
  packaging; running any Directional runtime including the accepted prefix, 357, 358, D2 or a cumulative gate;
  altering `PR8-R043`/`PR8-R044` closure conditions; retro-expanding historical abbreviated digests; touching
  the mechanical witness, C2, or CP4c-3.

## 8. `ORIENTATION.md` — durable, and updated at every REVIEW turn

Adopted at the user's instruction and recorded here as the authority for it.

`ORIENTATION.md` is **DURABLE**. It may be corrected or extended; it must not be deleted, renamed away,
collapsed into another document, or replaced by a summary without explicit user authorization.

**Every REVIEW turn must update it** before closing, so that a cold-start agent is never more than one review
behind. The required update covers: the currency line; "where we are" including selector authority and stable
accounting; the witness table if any witness's state changed; open problems in priority order; and the recurring
defect patterns if the turn found a new one or a new instance of an old one.

It stays **substance-only** — no turn workflow, no policies, no checklists, no transport or connector mechanics.
That boundary is what makes it cheap to read and is the reason it exists; keeping it means a fresh agent gets
oriented from one document instead of reconstructing context from per-turn records.

This turn's evidence is the argument for the rule: R7-EXEC used `ORIENTATION.md` as corroborating hash authority
and was right to, because its values were correct.

## 9. Falsifiable predictions

1. AE0's independent recomputation reproduces §1's six values exactly.
2. AE2's sweep finds the same four wrong constants and **no others** — the fabrication is confined to the CB5
   closeout report and the R7 plan.
3. After AE1, R7-0 preflight passes on all six rows against the unchanged immutable package `9719216316`.
4. With AE8's ordering, R7-2 through R7-5 publish evidence on the retry **whatever the accepted prefix does** —
   ending the eight-turn `CAND-04` drought.
5. Ordinal 310 goes green, proving the CB5 semantic/provenance split at runtime; ordinal 305 stays green; the
   full prefix reaches **355/355** and both `PR8-R043` and `PR8-R044` close in that run.

Prediction 2 is the one worth being wrong about — if the fabrication propagated further, that is materially
worse than this turn assumes and AE2 exists to find out.

## 10. Stop / successor

The exact next turn is **`M3-CP4c-2-DOC-R1`**, documentation-only, under measures **AE0–AE9**.

Its successor is **`M3-CP4c-2-TB-X2-R7`** retried on the unchanged immutable package `9719216316`, with AE8's
ordering. `selected_r2_branch` remains **NONE**, `selected_gate` remains **NONE**, and
`gate_execution_authorized` remains **false**.
