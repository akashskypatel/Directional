# M6 CP3 TB16 — exact-I witness checker harvest (2026-10-19)

**Authority:** RA-97.5. **Run:** https://github.com/akashskypatel/Directional/actions/runs/39246335010; result artifact `12183498229`, ZIP SHA-256 `8a329317a610a014cb834947d841fac788ffa55813519dc5259c342a3b62dc32`.
**Immutable executable:** CB16 package `12154623660`, semantic source `1c45e89ae0ca7a072c5140aea2b95be6387ec078`, packaged ZIP SHA-256 `821edfc6653af356c902d2debedc065a0ee6b51d287c27bdfd0679ef3a619956`. Harness SHA-256 `f8db713ee6a98445cc26f29ce8dfc248cca88de1b927ceabf1892ed0aa43769b`.

## Results

All **12/12** independent exact-filter processes selected exactly one test; **6 PASS / 6 RED**. Package checksums 28/28 and result manifest 16/16 passed; postflight `package=true source=true execution_view=true frozen_selectors=true`. GMP dynamic dependency present. `compile=false`, `relink=false`, `benchmarks=false`, `selector497=false`, immutable harness exit `0`. A workflow success means the harvest completed, **not** that all tests passed.

| Ordinals | Verdict | Evidence and comparison |
|---|---|---|
| 1–2 | PASS | CB16 same-point and unequal-exact tests. |
| 3 | **RED — falsifier** | `ExactWitnessUnboundFailsClosedAndMixedKeepsLegacy` fails twice at P10:9463–9464. The `nextafter` mutation to the reverse chart's barycentric slot 2 changes `0x1.9999999999998p-3` into `0x1.9999999999999p-3`; the latter is exactly the *forward*-direction accepted-boundary rounding for the same rational 1/5. The checker intentionally permits either reconstructed orientation, so the mutation does not prove witness corruption. This is a fixture/oracle design defect, **not evidence that the checker accepts unbound geometry**. Independent Review must adjudicate before test or code modification. |
| 4–7 | PASS | All three CB15 tests and chain interval truth table. |
| 8–9 | RED — pre-existing B2 | First-predicate records are **byte-identical** to TB15 ordinals 5/6, at `endpoint-1`, front `61,179`, `a2bProbeFirstFailedCondition=carrier-orientation`. RA-97.5's firstPredicate wording is not the literal log predicate; the subcondition does report carrier-orientation. No new outcome. |
| 10–12 | RED — B3 progressed | The old first failure at `endpoint-1`, front `17,203` is gone in all three. The first recorded failure is now `endpoint-1`, front `97,283`; `a2bProbeFirstFailedCondition=carrier-orientation` for #10/11 and #12 remains route rejection. This is progression, **not** full-pipeline acceptance. |

No `exact-witness-` or `open-rail-chain-interval` probe label appears. The **#3 gate falsifier** triggers mandatory independent Review + Plan; do **not** run conditional TB16C yet or implement CB17. Stable accounting remains **66/17/49**, debt **1**, CP2 **491/491**, rejected R3 **403/497**, last full census TB14A **425/497**. `RP-01` remains open; `RP-02` UNREACHED; Gate C suspended. No selector mutation or success promotion.

**Required next action:** independent TB16 Review + Plan (canonical turn ID not yet assigned by authority): determine test #3's valid one-ULP falsifier, compare B2 subcondition-vs-predicate terminology, and classify later B3 front `97,283` before reauthorizing harness/test correction or TB16C. The next turn is **not** TB16C automatically.
