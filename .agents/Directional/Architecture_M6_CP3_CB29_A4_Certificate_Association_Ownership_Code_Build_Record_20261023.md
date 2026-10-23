# CB29 — A4 certificate association ownership (Code + Build; in progress)

- Authority: RA-143.3, mandatory turn M6-CP3-CB29-RP01-A4-CERTIFICATE-ASSOCIATION-OWNERSHIP.
- Frozen source: b592ab719b8f2c284921929296033836840264fd; snapshot run 39930016168, artifact 12491187495, 5812/5812 file hashes verified.
- Scope: src/geometry/SurfaceCellTracing.cpp certificate pair clause near line 8831 only.
- Diff: removed both opposite-edge comparisons, both rail-ID comparisons, both route comparisons, and source-region equality rejection.
- Preserved both HardRail kinds and certificate-pair-binding; added one RA-15/RA-16 §5/RA-143 comment.
- Preserved existing downstream A4 certificate-authenticity and structural reciprocity checks; A5 retains edge-to-certificate association.
- Verified local diff confined to this clause; git diff --check and git apply --check passed. No test or benchmark execution.
- Preservation patch: cd7401cbc7f966f6bc70139bef9199f7beb616301145408e5d826aeecd773467; 1592 bytes; base b592ab719b8f2c284921929296033836840264fd.
- Google Drive patch applied by run 39931295425; apply result reported successful code commit 2602e7398cdc6f1281abe11a758de35166b6590c and runtimeExecution=false.
- Applied patch Drive file 1aukt4C8pbKS9RfESgf3FvuXVYXatATwe was deleted via owner connector after success.
- Snapshot trigger cleanup: run 39931520371 reports success; branch advanced to c9bc7afd2f6b8db3f5c09785f4c0cc791c33db6b.
- **Compilation not run.** Eight target compile, GMP/GMPXX check, immutable build artifact/manifest and final acceptance remain outstanding.
- Resume same turn; do not redo source edit or reapply patch. Trigger compile-only durable dispatcher with runtimeExecution=false, then record package IDs/hashes and update TODO/handoff if successful.
- This is not a completed Code + Build checkpoint. Successor Review is not yet authorized.
