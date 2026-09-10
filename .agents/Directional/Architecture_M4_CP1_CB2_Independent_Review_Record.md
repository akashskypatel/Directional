# M4-CP1-CB2 — Independent Review Record

**Turn:** `M4-CP1-CB2-REV` — independent review (absorbs REVIEW + PLAN).
**Status:** STATIC / EVIDENCE-ONLY / NO RUNTIME / NO COMPILE / **NON-STABLE**.
**Measures:** **FA0–FA6**.
**Adjudicated evidence:** CB2 algorithm-blocker record (folded after this review/DEFN-R1 into `M4_Consolidated_Record.md`; exact bytes retained in git history), frozen semantic source
`075f3c738d8f689437397fe925faa7eb12d72ac3`, snapshot run `34429824055` / artifact `10134050428`, `5222/5222`
manifest files verified, `runtimeExecution=false`.

---

## FA0 — the stop was correct, and it is the second one on the same clause

CB2 stopped before any product, test, selector, build-system or runtime mutation. Nothing was authored, no compile
or package workflow ran, no binary executed, no workflow permission changed. **This is a successful fail-closed
plan guard, not runtime evidence and not a semantic regression.**

`M3` / package113 / TB48 remains the reviewed semantic runtime authority. Selector **365** remains the accepted
required-green predecessor, byte-unchanged. Stable accounting is untouched.

**Both stops were right, and that is the finding.** CB1 stopped because the contract demanded a `P(V,E,B)` constant
no source supplies. CB2 stopped because the contract names an algorithm its own primary source does not disclose.
Two consecutive Code + Build turns have now halted on the same frozen clause without either being at fault.

> **When two implementation turns fail identically on one clause, the clause is the defect.** A Code + Build turn
> cannot repair a definition, and asking a third to try would be the first genuinely wrong move in this sequence.

## FA1 — the deadlock is real, and independently corroborated

Three facts, each established rather than assumed:

1. **The named source does not disclose the algorithm.** Gabow, *An Efficient Reduction Technique for
   Degree-Constrained Subgraph and Bidirected Network Flow Problems*, STOC 1983 (DOI `10.1145/800061.808776`)
   lists arbitrary-capacity minimum-cost biflow as **problem (5)** and supplies the result, not the construction.
2. **No follow-on primary source supplies it.** A bounded search located none.
3. **The difficulty is independently corroborated, not a search failure.** Medvedev et al., *Maximum Likelihood
   Genome Assembly* (2011) §5.1 describes Gabow's minimum-cost biflow algorithm as **polynomial but difficult to
   implement** — a separate group, in a separate field, reporting the same wall.

Combined with `M4-CP1-CB1-REV` §13.2's finding that **no off-the-shelf exact arbitrary-capacity bidirected MCF
library exists**, the position is: the frozen primitive can be neither imported nor implemented from its citation.

## FA2 — the premise that closed this question has been falsified

`M4-CP1-CB1-REV` §9 rejected *"port libSatsuma's full iterative Bi-MDF solver and accept finite convergence"* with
this reason:

> it weakens the frozen polynomial architecture **unnecessarily** when M4's L1 objective admits a linear Bi-MCF
> specialization.

**The rejection rested on that word.** The specialization does exist — §§4–6 prove it mathematically, and none of
that is withdrawn. What does not exist is an **implementable primitive** for the specialized problem. So the
alternative was not unnecessary; it was the only other disclosed route, rejected against an option that has since
proved unbuildable.

**That rejection is therefore re-opened for adjudication.** Re-opened, not accepted: finite convergence is a real
reduction in assurance and must be argued on its own terms, not inherited by default because the preferred path
failed.

## FA3 — the successor is a definition turn, not a third Code + Build

**Exact next: `M4-DEFN-R1`** — a static definition turn amending the solver clause of `M4-DEFN` §7 as further
amended by `M4-CP1-CB1-REV`. No runtime, no compile, no package, no product/test/selector mutation.

It must decide **one implementable, citable exact path**, under three binding rules:

- **R1 — the citation must disclose the algorithm, not only the bound.** A complexity result without a
  construction is what produced this deadlock. The chosen source must be sufficient for an implementation to be
  *traced* to it, which is precisely what CB2's stop rule requires.
- **R2 — no inherited complexity labels.** If the primitive changes, its bound comes from **its own** source.
  `O(E'^2 log V' log Cmax)` is Gabow's claim about Gabow's algorithm and may not be transferred to a substitute.
  The `WorkLedger` algorithm identity and theorem class move together or not at all.
- **R3 — any reduction in assurance is stated, not absorbed.** If the outcome is a finite rather than polynomial
  bound, that is a definition-level change to M4's architecture and must be recorded as one, with its consequences
  for CP2's certificate named.

## FA4 — the adjudication set, in the order DEFN-R1 should take it

These are the paths the record supports. **This review does not choose among them** — selecting an algorithm inside
a review is the same error as inventing one inside a build.

1. **Prove the M4 instances reduce to ordinary minimum-cost flow.** *Take this first.* If the `±2` same-row loops
   and odd structure of `M4-CP1-CB1-REV` §6.5 can be eliminated or shown not to arise for admissible M4 inputs,
   the problem leaves the bidirected class entirely — and exact ordinary min-cost flow **is** available in
   libraries, which is what the standing user authorization was granted for. Highest payoff, cheapest to test, and
   it either closes the question or is disproved quickly. It requires a **proof**, not an observation about
   current fixtures.
2. **A disclosed b-matching route.** Bidirected flow → degree-constrained subgraph → weighted matching is a
   standard chain whose terminal algorithms are fully published with pseudocode. The burden is showing the
   *capacity* handling is polynomial from a citable source — which is exactly the gap Gabow 1983 was cited to
   fill, so this must not silently reintroduce it.
3. **Port a disclosed iterative Bi-MDF method with exact types**, per FA2. Assurance drops from polynomial to a
   stated finite bound; R3 governs.
4. **Amend the frozen polynomial requirement itself**, with the assurance change recorded and CP2's certificate
   obligations restated.

## FA5 — what must not happen

- Inventing the undisclosed construction, in any turn.
- Substituting a solver while retaining Gabow's identity or bound in the `WorkLedger`.
- Accepting `int`/`double` representation on the grounds that current meshes are small — `M4-CP1-CB1-REV` §9
  prohibits this, and it is the failure mode of `LESSONS.md` 156.
- Generic ILP / IQP / branch-and-bound, heuristic big-M, or enumerating counts up to `U`; all remain prohibited.
- A fourth turn re-deriving FA1's three facts. They are established here; a successor cites them or refutes them
  with new primary evidence.

## FA6 — accounting

No runtime, no compile, no package, no semantic mutation, no accepted-identity or selector change.
**+0 events / +0 recurrences.** Stable accounting is unchanged. `M3` / package113 / TB48 remains the reviewed
semantic runtime authority; selector **365** remains the accepted predecessor.

New candidate **`M4-CP1-CB2-REV-CAND-01`** — *the frozen solver primitive is neither importable nor implementable
from its citation* — **ACTIVE / GATING / DEFINITION-OWNED**, owner `M4-DEFN-R1`.

**Exact next turn: `M4-DEFN-R1` — definition turn, static, under FA3's rules R1–R3 and FA4's adjudication set.**
