# M3-CP4c-2 TB-X2-R6-REV Independent Review and Plan

## 0. Verdict

`M3-CP4c-2-TB-X2-R6-REV` is **COMPLETE / REVIEW GREEN**.

- **`PR8-R043 / M3-CP4c2-R001` is RESOLVED AT ITS LOCUS.** Accepted ordinal 305 passes on the CB4 package.
  DEFN-R1's actual-embedded-graph complex did what it was defined to do. **Full closure is deferred** until the
  whole 355 prefix is green, because R6 stopped at 310 and ordinals 311–355 have not executed.
- **`PR8-R044 / M3-CP4c2-R002` is CONFIRMED and independently re-localized.** The EXEC classification is
  correct in every particular. **The corrective template already exists in this repository** and is named in §4.
- **One finding the EXEC did not reach**, and it would survive the obvious fix: the cellularity certificate is
  keyed by raw **orbit indices**, which are enumeration artifacts. Removing `atlasDigest` alone leaves a latent
  instance of the same pattern. §5.

A bounded `M3-CP4c-2-CB5` is **AUTHORIZED** under measures **AD0–AD9**. No runtime, build, compile, package, or
product/test/fixture/selector change was made in this review.

## 1. What R6 establishes, verified rather than accepted

- Immutable preflight is complete: outer digest, internal `SHA256SUMS`, source commit, GMP linkage, eight
  targets, six binaries at mode `0755`, and **all six frozen selector hashes** recomputed exactly.
- **310 fresh-process rows, no duplicate identity, 309 exit 0.** Ordinal 310 is the first and only red.
- **R6-5 postflight ran unconditionally after the red and passed**, with package and source byte-and-mode
  equality and every mutation flag false. This directly discharges `M3-CP4c2-TB-X2-R5-ORCH-01`: a semantic red
  no longer suppresses finalization. **That fix worked and should be preserved.**

**What R6 does not establish, and must not be inferred:** ordinals 311–355; R6-2's actual-complex oracle;
R6-3's retained barrier diagnostic; R6-4's D2 localization; any 357/358 branch; any cumulative gate. The EXEC
report is correctly explicit about this.

**`M3-CP4c2-TB-X2-CAND-04` — the prescribed sphere's `CellularityNotEstablished` — remains UNLOCALIZED for the
seventh consecutive turn.** D2 has now been scheduled and skipped in R2, R3, R4, R5 and R6. That is not a
criticism of any single turn; each stop was correct. It is a standing fact about this arc that the next plan
should weigh, and §8 does.

## 2. `PR8-R043` — resolved at its locus, closure deferred

Ordinal 305 `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` failed in R5 at
`SurfaceCutGraph::make = CellularityNotEstablished` and **passes in R6**. The mixed-complex certificate that
produced `9 − 11 + 2 = 0 ≠ 1` is gone, replaced by the actual embedded-graph complex frozen in DEFN-R1
Amendment 13.

**Disposition: RESOLVED AT LOCUS / CLOSURE PENDING FULL-PREFIX RE-PROOF.** The distinction matters and is not
pedantry — R6 executed 309 of 355 accepted identities. `PR8-R043` closes when a run reaches **355/355** with
ordinal 305 green, and not before. Recording it closed on a 309-ordinal prefix would be exactly the
partial-evidence promotion this project has corrected twice.

CB4 also delivered `src/geometry/EmbeddedGraphTopology.{h,cpp}` — the shared pre-region authority AC1 required.
Its existence as a single owned unit, rather than a second copy inside `SurfaceCutGraph`, is the structural
half of the fix and satisfies `LESSONS.md` 22e.

## 3. `PR8-R044` — independently re-localized, and the irony is the point

The EXEC localization is confirmed at source, exactly as reported.

**`GlobalTopologyPlan.cpp:1511-1519`:**

```cpp
hash_consume(hash, candidate.sourceDigest);
hash_consume(hash, candidate.cutGraphDigest);          // <-- the leak
// Deliberately consume only the gauge-invariant network identity. The exact
// network/atlas provenance lives in candidate.networkDigest instead.
hash_consume(hash, network.semantic_digest());
```

**`SurfaceCutGraph.cpp:263-265`, `candidate_hash`:**

```cpp
hash_consume(hash, candidate.sourceDigest);
hash_consume(hash, candidate.atlasDigest);             // <-- gauge-dependent
hash_consume(hash, candidate.networkDigest);
… cut edges, then the whole certificate …
```

and `canonical_candidate` stores `network.atlas_digest()` into `candidate.atlasDigest`.

**A2b knows the rule, writes it in a comment, obeys it on the line the comment guards — and is defeated two
lines earlier.** It carefully consumes `network.semantic_digest()` rather than the atlas hash, then consumes
`cutGraphDigest`, which carries `atlasDigest` in through the back door. Branch relabeling changes the gauge →
changes `atlas_digest()` → changes `candidate_hash` → changes the plan's semantic digest → ordinal 310's
invariance assertion fails. The observed digests `12176020141753559903 / 14339407889897379635` are the
consequence.

**The underlying error is a domain conflation, not a hashing bug.** `candidate_hash` is a **provenance** hash
and is *correct as such*: `make_from_candidate` uses it to reject a candidate built against a foreign or
tampered atlas, and it must keep consuming `atlasDigest` to do that job. The defect is that a second consumer
reads a provenance hash as a **semantic** identity. One digest is serving two incompatible domains.

## 4. The corrective template already exists in this repository

This is the third occurrence of `RP-05 / REPRESENTATION_DEPENDENT_IDENTITY` in the same family, and the
correction was worked out and written down the first two times:

- **`PR8-R040 / M3-CP2b-R001`** — stable, same domain mistake.
- **`M3-CP3a-DG-CAND-02`** — the *`FieldAlignedCurveNetwork`'s own* semantic digest carried
  "gauge-invariant network semantics and representation-dependent atlas binding/provenance" in one value. The
  recorded correction: *"semantic identity consumes `branch_topology().semantic_digest()` while retaining the
  full atlas hash separately for binding/provenance and preserving foreign/tampered-atlas rejection."*

**`SurfaceCutGraph` must be given exactly the split that `FieldAlignedCurveNetwork` was given in CP3a.** Two
digests, two names, two purposes:

| digest | consumes | consumed by |
|---|---|---|
| `semantic_digest()` — **new** | source digest, `network.semantic_digest()`, cut edges, and only the gauge- and enumeration-invariant certificate terms (§5) | `GlobalTopologyPlan::candidate_semantic_digest` |
| `candidate_hash` / provenance — **unchanged** | everything it consumes today, **including `atlasDigest` and `networkDigest`** | `make_from_candidate` tamper rejection; the plan's `candidate.networkDigest` provenance path |

**Do not "fix" this by deleting `atlasDigest` from `candidate_hash`.** That would silently weaken
foreign/tampered-atlas rejection — trading a semantic defect for a security-of-authority defect one level down,
which is `LESSONS.md` 22e's warning in its other direction. **Add a digest; do not weaken the existing one.**

## 5. The finding EXEC did not reach — orbit indices are enumeration artifacts

Removing `atlasDigest` from the semantic path is necessary and **not sufficient**.

`SurfaceCutGraph.cpp:258` builds each certificate face record as:

```cpp
certificate.faces.push_back({orbit, 1U, embedded.faceWalk.orbits[orbit].size(), discEmbeddingEstablished});
```

where `orbit` is the **loop index** into `embedded.faceWalk.orbits`. `candidate_hash` then consumes
`face.orbit` for every face. An orbit index is an artifact of the order in which `walk_graph_faces` enumerated
darts, which follows the order arcs were built. **It is not a semantic identity of a face.**

Ordinal 310 asserts invariance to **enumeration order *and* branch relabeling**. A digest that consumes
enumeration indices is therefore a latent instance of the very pattern being fixed, and it will not be caught
by removing `atlasDigest` — it may simply not fire today because arc construction happens to be canonical.

**This must be resolved deliberately, not left to luck (AD3).** Two acceptable outcomes, and the CB must state
which it took and why:

- **prove** that orbit enumeration is canonical — derived from a total order on `NetworkArcId` and the cut-edge
  order, independent of gauge and of container iteration — and record the proof; or
- **replace** the orbit index in the semantic digest with a content-derived canonical key, such as the sorted
  multiset of the face's boundary arc identities, and sort the face records by it.

The same question applies to every certificate term. §6 partitions them.

## 6. Term-by-term partition of the certificate

The CB must place each term explicitly. This table is the reviewer's reading and the CB must confirm or correct
each row **with a reason**, not adopt it silently.

| certificate term | semantic? | note |
|---|---|---|
| `complex` | yes | names the object certified; must stay |
| `vertexCount`, `edgeCount`, `faceCount`, `totalOrbitCount` | yes | counts, invariant |
| `excludedBoundaryOrbitCount`, `sourceBoundaryLoopCount` | yes | counts, invariant |
| `graphComponentCount`, `sourceComponentCount`, `disconnectedComponentCorrection` | yes | DEFN-R1 §5.2 terms, invariant |
| `eulerCharacteristic`, `sourceEulerCharacteristic` | yes | invariant |
| `faces[].orbit` | **NO — §5** | enumeration index; prove canonical or replace |
| `faces[].boundaryWalkCount`, `boundaryArcCount`, `discTopologyEstablished` | yes | invariant given a canonical face key |
| `cutCandidates[].sourceEdge` | yes | a canonical source-topology key |
| `cutCandidates[].classification`, `.selected` | yes | the admissibility decision is semantic |
| `atlasDigest` | **NO** | gauge-dependent provenance; provenance digest only |
| `networkDigest` | **NO** | exact-network provenance; provenance digest only |
| `sourceDigest` | yes | source identity is not gauge-dependent |

## 7. Measures **AD0–AD9** for `M3-CP4c-2-CB5`

- **AD0 — preconditions.** Accepted historical authority remains CP4c-1 **355/355**. Preserve all six frozen
  selector files and hashes: 316 `601ce2b6…0193c`, 346 `20d3b0b1…3e46a`, 353 `51ff96d7…ac6a5`, 355
  `e9d88f11…5afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…b64fbe62`. Compile under `GMP_COMPILE_POLICY.md`
  with GMP/GMPXX; `runtimeExecution=false`. Keep `selected_r2_branch=NONE`, `selected_gate=NONE`,
  `gate_execution_authorized=false`.
- **AD1 — add a semantic digest; do not weaken the provenance hash.** Give `SurfaceCutGraph` a
  `semantic_digest()` per §4's table. **`candidate_hash` keeps `atlasDigest` and `networkDigest` unchanged**, and
  `make_from_candidate`'s foreign/tampered-atlas rejection must remain exactly as strong. State in the report
  that it is unchanged and why.
- **AD2 — convert the consumer.** `GlobalTopologyPlan::candidate_semantic_digest` consumes the cut graph's
  **semantic** digest. Its provenance path keeps the full hash. Extend the existing comment at
  `GlobalTopologyPlan.cpp:1515-1517` so the invariant is stated at *both* consumption sites — the comment was
  correct and was still defeated, so it needs to cover the term that defeated it.
- **AD3 — settle the orbit-index question explicitly.** Per §5, either prove orbit enumeration canonical and
  record the proof, or replace the index with a content-derived key and sort by it. **"It passes now" is not an
  answer.** Report which option was taken and the reasoning.
- **AD4 — confirm or correct §6 row by row.** Every certificate term is placed in exactly one domain with a
  stated reason. A term that cannot be justified as invariant goes in provenance, not semantic.
- **AD5 — a test that would have caught this.** Ordinal 310 caught it only because CP4c-1 had already written
  an invariance identity. Add a **non-gating** diagnostic that, for each witness, publishes the cut graph's
  semantic and provenance digests under baseline and gauge-relabeled input and asserts semantic equality with
  provenance inequality. This makes the split checkable at the cut-graph boundary instead of two stages
  downstream.
- **AD6 — preserve what works.** Do not disturb `EmbeddedGraphTopology.{h,cpp}` as the single shared authority
  (AC1), the actual-complex certificate (AC2), the unconditional postflight path that discharged
  `R5-ORCH-01`, or AA1's snapshot placement.
- **AD7 — do not encode witness answers.** No witness-name branch, expected-digest table, or constant. The
  two-ring's invariance must fall out of the representation.
- **AD8 — the successor runs the full prefix.** `PR8-R043` closes only at **355/355** with ordinal 305 green,
  and `PR8-R044` closes only with ordinal 310 green in the same run. Report both explicitly. **A green 309
  prefix is not closure for either.**
- **AD9 — prohibited.** Removing `atlasDigest` from `candidate_hash` or otherwise weakening tamper rejection;
  a second implementation of the arc/orbit machinery; reverting AA1, AC1, AC2, or the unconditional postflight;
  changing or inventing selectors; running a cumulative gate, 357/358, or D2 before AD8's prefix is green;
  relaxing `proves_cellularity()`; mixing any barrier-partition quantity into a cellularity certificate;
  subdividing an immutable trace; A2a′ reading a `GlobalTopologyPlan`; touching the mechanical witness, C2, or
  CP4c-3.

## 8. On the seven-turn D2 debt — a note for the next planner, not a measure

D2 has been scheduled and correctly skipped in five consecutive runs. Each stop was right, and I am not
proposing to weaken any of them. But the pattern is worth naming: **every stop has been upstream of the
measurement, and the measurement is the checkpoint's actual question.**

The accepted-prefix re-proof is the right gate and must stay first. The observation worth carrying forward is
that CP4c-2's diagnostics are all sequenced *behind* a full accepted-prefix gate that has failed for a
different reason each time. If AD8's run stops again before D2, the next plan should consider whether the
sphere diagnostic can be made to run **independently of** the accepted-prefix outcome — it is non-gating, it
grants no credit, and its evidence would be admissible regardless. That is a planning question for the next
review, deliberately not decided here.

## 9. Falsifiable predictions

1. After AD1/AD2 the two-ring's baseline and relabeled plans produce **equal** semantic digests and **unequal**
   provenance digests, and ordinal 310 goes green.
2. Ordinal 305 stays green; AC1/AC2's actual-complex work is untouched by this correction.
3. The orbit-index question (§5) resolves as **canonical in fact** — arc order derives from `NetworkArcId` — so
   AD3 is discharged by proof rather than by replacement. *This is the prediction most likely to be wrong, and
   AD3 is written so that being wrong is cheap.*
4. Ordinals 311–355 pass, giving **355/355**, and both `PR8-R043` and `PR8-R044` close in the same run.
5. No accepted identity other than 310 changes state.
6. `NoAdmissibleCutForNonDiscComponent` is defined and does not fire.

Prediction 4 is the one that closes two stable regressions. Prediction 3 is the one to watch.

## 10. Stop / successor

The exact next turn is **`M3-CP4c-2-CB5`**, Code + Build, runtime-free, under measures **AD0–AD9**.

Its successor is artifact-only **`M3-CP4c-2-TB-X2-R7`**, which must re-prove the **full 355** accepted prefix
including ordinals 305 and 310, then publish R6-2's actual-complex oracle, R6-3's retained barrier diagnostic,
and R6-4's D2 localization. `selected_r2_branch` remains **NONE**, `selected_gate` remains **NONE**, and
`gate_execution_authorized` remains **false**.
