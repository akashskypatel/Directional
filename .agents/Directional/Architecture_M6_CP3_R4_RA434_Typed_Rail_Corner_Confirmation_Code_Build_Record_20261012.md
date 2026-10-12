# M6-CP3-CB1-ENTRY-R4 — typed rail corner confirmation checkpoint

**Scope:** RA-43.4 incremental Code + Build correction. Same canonical turn; not RA-43.4 closeout and not permission for TB497. No Directional binary, test, benchmark or local build execution.

**Exact inspection authority:** snapshot workflow `38320218596`, source commit `b178f5628bf9e07a4ede14f4717fbe37c2b6e3ab`, artifact `11778466781`, outer SHA-256 `2824e4e64bdc5df4069d509dcb690fdc4e7b02f090064ec81366e749b636d560`, 6,556/6,556 manifest hashes verified, `runtimeExecution=false`.

**Targeted defect:** `rail_sample_geometry_is_valid` accepted a caller-supplied typed vertex based on valid sample geometry and coincident 3D position without itself confirming that the ID was a source-face corner and the barycentrics were bit-exact one-hot. The downstream typed interval validation already checked that invariant, so this is an independent helper boundary hardening, **not evidence of a demonstrated production-path exploit or runtime regression**.

**Change:** When the optional producer-published vertex is supplied, require that ID to occur in the sample's actual source face, not in its local excluded source-edge slot, and require bit-exact one-hot barycentrics at that corner. Keep existing numeric position confirmation, legacy standalone no-ID diagnostics, downstream interval check, and every other validation predicate. A focused existing Phase14 test adds a coincident-position foreign source-vertex negative and near-corner typed negative alongside the accepted exact-corner positive.

**Verification:** Source patch requires exact-base `git apply --check` and whitespace verification, Drive apply with semantic commit evidence, then mandatory eight-target GMP/GMPXX compile and immutable package manifest/link/source-status checks. Compilation does not run tests or establish any runtime PASS; no TB497.

**Still open:** RA-43.2 producer-attested oriented terminal side bindings; global RA-43.4 legacy diagnostic disposition; RA-46.5 first-rejection coverage; RA-47.12 executed default-path liveness; 39 endpoint / 34 Phase10 / seven DCEL / 88 historical accepted CP2 losses / six CP3 positive gates / odd-τ multi-carrier proof. The RA-49.5 factory-before-use architectural change is reserved for Definition. Ledger 66/17/49 and debt 1 unchanged. Continue R4.
