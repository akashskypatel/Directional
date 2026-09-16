# Durable handoff policy — DURABLE, DO NOT DELETE

At the end of every turn:

1. replace stale next-turn/status text instead of appending chronological narrative;
2. keep unresolved, current-authority, and immediately resume-critical facts in this handoff;
3. move completed history to `CHANGELOG.md` and exact evidence to the owning report/tracker without deleting durable lessons or policies;
4. never treat a documentation/control-plane commit as implementation, build, test, benchmark, or runtime evidence;
5. preserve the mandatory start/end checklists and all other sections explicitly marked durable;
6. preserve every section explicitly marked durable in **any** durable document. Durable sections must not be deleted, collapsed, renamed away, replaced by a summary, or stripped of durable meaning unless the user explicitly authorizes that destructive edit and its exact scope;
7. `[ChatGPT Web]` perform work directly on the configured working branch. Do **not** create temporary, control, side, or staging branches unless doing so is absolutely necessary to circumvent a concrete procedural blocker that cannot safely be resolved on the working branch. If an exception is unavoidable, record the blocker and why the branch is necessary, keep it narrowly scoped, remove/reset it as soon as the blocker clears, return to the configured working branch, then proceed to the next turn;
8. every Test + Benchmark turn must categorize **every observed regression** in `.agents/Directional/Regression_Root_Cause_Tracker.md` and record root-cause analysis before the turn closes. If evidence does not justify a stable regression ID/count change, create or update a candidate/non-stable record and explicitly state why historical stable totals do or do not change, then proceed to the next turn;
9. `[ChatGPT Web]` `.github/workflows/agent-compile-reusable.yml` owns one durable compiler-cache namespace/schema. Turn-specific callers must not invent cache epochs, cache namespaces, or unrelated per-turn compatibility keys. Restore must always use the durable compatible namespace so prior ccache entries are reusable across turns.
10. work units 2 and 3, plus the exact M1 full-authority partial edges tasklisted in `TODO.md`, have the user-authorized partial-CB cadence exception: only those exact `P-CB` → `P-CB` edges may omit an intervening TB. Every partial remains runtime-free and semantically unaccepted; the final packaging partial must advance to its TB before later milestone work starts.
11. `[ChatGPT Web]` `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md` is durable operating authority and a mandatory full read at the start of every turn. Apply it before selecting repository-read, workflow-observation, artifact-download, multi-file-write, cleanup, or PR-comment strategies.
12. **`.agents/Directional/ORIENTATION.md` is DURABLE and must be updated at every REVIEW turn.** It is the cold-start context document: architecture, current position, witnesses, open problems, recurring defect patterns and source pointers, deliberately **substance-only** with no procedural content. It may be corrected or extended; it must not be deleted, renamed away, collapsed into another document, or replaced by a summary without explicit user authorization. Every REVIEW turn updates its currency line, "where we are", the witness table if a witness changed, open problems in priority order, and the recurring-defect section if the turn found a new pattern or instance. Authority: user instruction, preserved in `M3_CP4c_Consolidated_Record.md` §6.6 and the 2026-08-29 R7-REV/DOC-R1 changelog entries.
13. `[ChatGPT Web]` `RETENTION_POLICY.md`'s **downloadable work-preservation durability barrier is mandatory**. Any coherent repository-applicable work that exists only in the local/container workspace must be emitted as a File-Library-backed downloadable `Directional__<TURN-ID>__base-<12SHA>__work-preservation.patch` before entering tool-heavy remote orchestration or another interruption-risk phase. A local `/mnt/data` file alone is not durable. The patch is recovery material, not semantic/build/test authority.
14. **Every REVIEW turn must perform document consolidation before closing** — `CLEAN_UP_POLICY.md`
    §"Document consolidation — every REVIEW turn". Preserve each folded document's durable facts in a retained
    record first, append its exact filename and verdict to the family's **folded document index**, retain one
    current document per role plus every selector file, and repair live citations in the same turn. It is a
    preservation procedure, not a reduction target, and it never reaches durable project authority, normative
    definitions, policies, closure records or selector files. Authority: user instruction 2026-09-03, first
    applied at `M3-CP4c-3-TB18-REV`.

15. **`STATUS` at repository top level is maintained by BOTH the Review agent and the Implementation agent,
    at the end of every turn, in exactly the format below.** It is a cold-read beacon: one screen that tells the
    next agent, human or otherwise, what the last turn decided and what is authoritative right now.

    ```
    ---TURN_STATUS---
    Turn: <turn id, e.g. M4-CP-SCALE-CB10>
    Role: Review | Implementation
    Date: <YYYY-MM-DD> UTC
    Status: COMPLETE | HALTED | REJECTED | BLOCKED
    Verdict: <one line: what this turn decided, in plain words>
    Accepted-Package: <artifact id of the accepted runtime authority>
    Accepted-Selector: <selector filename> <n>/<n>
    Accepted-Selector-SHA256: <full 64-hex digest>
    Accounting: <events>/<categories>/<recurrences> debt <n>
    Blocking: <obligation id + one clause, or "none">
    Boundary: <runtime-free | compile+package | artifact-only runtime>; <mutation summary>
    Successor: <exact next turn id>
    ---END_TURN_STATUS---
    ```

    Rules, all binding:

    - **Exactly one block. Overwrite it; never append.** A second block, or chronological history, defeats the
      purpose and will drift.
    - **Every field appears every turn.** A field that does not apply is answered `n/a — <reason>`; it is never
      blank and never omitted. A missing line is a missed duty, visible as a missing line.
    - **Write it before the turn's final commit**, so `STATUS` lands in the same commit as the work it describes.
    - **No commit hash, and no digest of `STATUS` itself.** A file cannot attest to the commit that contains it;
      attempts produce corrective churn rather than evidence. `Accepted-Selector-SHA256` is a digest of a *different*
      file and is therefore fine.
    - **`STATUS` is a beacon, not authority.** `ORIENTATION.md`, `Regression_Root_Cause_Tracker.md`, the frozen
      definitions and the selector files remain authoritative. **No fact may live only in `STATUS`.**
    - **On disagreement the authoritative document wins**, and the next turn repairs `STATUS` rather than the
      reverse.
    - Keep the trailing newline, and keep `Verdict` and `Blocking` to one line each. If a turn needs more than a
      line, the extra belongs in the owning record.

    A documentation, policy or control-plane turn does not invent a turn id: it leaves `Turn` and `Successor`
    describing the last substantive turn, consistent with rule 4 above.

Do not add transcripts, chronological tool history, copied superseded artifact tables, obsolete task selections, or generic procedure already owned by policy/skill files. Concision never authorizes deletion of durable information.
