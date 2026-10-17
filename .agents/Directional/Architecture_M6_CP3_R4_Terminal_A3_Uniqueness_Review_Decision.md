# M6-CP3-CB1-ENTRY-R4 — terminal A3 dual-path feasibility: Review decision

**Type:** runtime-free independent Definition/Review adjudication of the terminal A3 uniqueness request.
**Verdict:** the lemma is **CONFIRMED**, and **strengthened** — unreachability does not depend on the RA-37a
manifold premise. The impossible two-admissible-path fixture obligation is **RETIRED** as **RA-46**, coupled to
four guard conditions. R4 Code + Build continues.

Read at HEAD `d8b565c9e`. The proof below is re-derived from bytes, not from the request's prose.

---

## 1. The lemma, re-derived from the two implementations

Both path counters build the same object. Consumer side, `endpoint_certificate`
(`src/geometry/SurfaceCellTracing.cpp:18979-19031`): `std::map<Face, std::vector<Transition>> localStar`,
populated only from `sourceEdges` filtered to spokes containing `*terminalVertex` (`:18981-18982`), rejecting
`sourceEdgeFaceCounts.at(spoke) > 2U` (`:18983`), skipping `hardFeatureEdges` spokes (`:18984`), skipping
spokes without two incident faces (`:18985`), and requiring reciprocal A3 (`:18996-18998`). Checked-factory
side, `unique_terminal_star_path` (`:8318-8352`): `std::map<StarFace, std::set<StarFace>> adjacency`, the same
filters at `:8325-8326`, plus `*firstRow == *secondRow → return false` (`:8330`) and `matchesA3` (`:8333`).

**(a) Maximum degree is 2.** Adjacency arises only from spokes at `v`. A face incident to such a spoke
contains both its endpoints, hence contains `v` as a corner; a triangle has **exactly two** edges at a given
corner. So each face-node has degree at most two. (On the factory side `std::set` additionally collapses any
duplicate, so the bound is strict there.) Every component is therefore a simple path or a simple cycle.

**(b) The carrier's component is acyclic.** The terminal carrier is a hard-feature edge containing `v`, and
hard-feature spokes are excluded at `:8326` and `:18984`. So the carrier edge is absent from the graph, and
the component holding the carrier's incident faces has lost at least one of its edges. A path minus an edge is
a forest; a cycle minus an edge is a path. Either way: **acyclic**.

**(c) The target is always carrier-incident.** `:8523-8526` targets `carrier.firstFace` and
`carrier.secondFace`; `:19044-19047` targets `oriented.firstFace` and `oriented.secondFace`. There is no call
site with any other target.

**(d) Conclusion.** In an acyclic graph there is at most one simple path between an ordered pair of nodes; if
`from` lies in a different component there are zero. By (b) and (c) the target always lies in an acyclic
component. Therefore **`pathCount >= 2` is unreachable for every input the preceding guards admit.**

## 2. Why this is stronger than the request's argument

The request conditions the lemma on RA-37a's connected oriented two-manifold link and on distinct triangles.
Neither premise is needed, and both of the gaps those premises were papering over are closed by (b)+(c):

- **Pinch / bowtie vertex** — two fans meeting only at `v`. Every edge incidence is still 2, so the `> 2U`
  guard does **not** catch it, and the link is disconnected with an untouched cycle. It still cannot yield two
  paths: the untouched cycle contains no carrier-incident face, so a target there is unreachable (zero paths),
  and a target in the cut component sits in an acyclic component (at most one).
- **Doubled triangle ("pillow")** — the only structure that could give the consumer-side multigraph a
  2-cycle. Two faces joined by two distinct spokes at `v` must share both edges at `v`, so they span the same
  vertex set; their only two spokes at `v` are exactly those two, and the carrier — being a hard edge
  containing `v` — is necessarily one of them. Cutting it leaves a single edge: one path.

So the lemma does not rest on the accepted manifold contract, and retiring the obligation does not borrow
authority from RA-37a. **A counterexample is not merely absent from the fixtures; it does not exist.**

## 3. The retirement is coupled to four conditions

Unreachability is a theorem **relative to its guards**. A dead negative is dead only while they hold, so
RA-46 binds the retirement to all four, and any weakening of any one revives the obligation:

1. source faces are **triangles**, giving exactly two edges at a corner — this is the degree bound;
2. hard-feature spokes are **excluded** from the star graph (`:8326`, `:18984`);
3. the terminal carrier **is** a hard-feature edge containing the terminal vertex;
4. the DFS target **is** a carrier-incident face (`:8523-8526`, `:19044-19047`).

## 4. Findings on the landed code

**Accepted — the diagnostics are already correctly separated.** `:19048-19053` sets `ambiguousTerminalPath`
only when `firstPathCount > 1 || secondPathCount > 1`, and `:19071-19074` selects among
`overlapping-terminal-sectors`, `ambiguous-terminal-A3-path` and `missing-terminal-A3-path`. The unreachable
condition does **not** share a message with the reachable zero-path case. No defect here.

**Finding R4-A3U-01 — the checked-factory side conflates zero with ambiguous.**
`unique_terminal_star_path` returns `bool` (`:8352`) and both call sites collapse into a bare
`InvalidSourceAuthority` (`:8527-8528`) with no sub-code. The factory is the **authoritative** check, so under
RA-42.3 it is the side that most needs typed diagnostics: a genuine no-path rejection is today
indistinguishable from the unreachable ambiguity branch. Required: a typed sub-code distinguishing them, so
that the zero-path negative can be verified at its actual first rejecting predicate. Not a block.

**Clarified — `exact_corner` is a confirming predicate and does not violate RA-42.2.** `:18957-18963` tests
`point.barycentric[i] != (i == corner ? 1.0 : 0.0)` bit-exactly, with **no tolerance**. The vertex identity is
taken from the typed published contact `contact->second.endpoints` (`:18966`, RA-44.1); the barycentric test
only confirms it. RA-42.2 forbids **deriving** incidence from geometry, not confirming it, and this predicate
can only false-reject, never false-accept. Recorded so it is not later mistaken for a violation — and so it is
not "fixed" by introducing a tolerance, which **would** be the violation.

**Accepted — sector disjointness is enforced at the factory.** `:8552-8556` requires `used[0]` and `used[1]`
to be disjoint, and `:19055-19064` does the same consumer-side via `overlappingSectors`. This is RA-38's
boundary-germ separation enforced where it counts, and it is the structural reason the two contact walks
cannot collude.

**Hardening, not a block.** `sourceEdgeFaceCounts.at(spoke)` (`:18983`) throws if the two maps are ever built
from different sources; prefer a bounds-safe lookup that fails closed.

## 5. Answers to the request's four items

1. **Confirmed**, by §1, and strengthened by §2. No counterexample is required or possible.
2. **Granted** as RA-46: the literal two-admissible-path source-witness demand is retired. The
   `pathCount != 1` guard is **retained** as a fail-closed defence with **no fixture obligation** on its
   `>= 2` branch. Note the guard is not dead overall — its `== 0` branch is reachable and keeps its obligation.
3. **Approved** as specified, targeting the reachable first-rejection diagnostics that already exist:
   `missing-terminal-A3-path`, `overlapping-terminal-sectors`, `no-exact-terminal-corner`,
   `ambiguous-terminal-contact`, `missing-or-nonreciprocal-terminal-A3`, `nonmanifold-terminal-star-spoke`,
   plus the new factory sub-code from R4-A3U-01. No frozen test identity changes; no runtime assertion.
4. **Not applicable** — item 4's branch does not arise, since the lemma holds without the manifold premise.
   No new source topology class is defined and none is needed.

No runtime ran. Selector 497 untouched. CP2 491/491 accepted; R3 403/497 rejected, 94 RED, 88 accepted CP2
losses. Stable ledger **66 / 17 / 49**, debt **1** — unchanged: retiring an unrealizable obligation is a
definition correction, not a runtime regression.
