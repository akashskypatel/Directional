# GMP Compile Policy

## Status — DURABLE, MANDATORY, DO NOT DELETE

This is repository-wide compile authority for Directional. It applies to **every future compile**, regardless of agent, host, IDE, CI provider, or build entry point. It may be strengthened or corrected, but it must not be weakened, bypassed, or removed without explicit user authorization.

## Mandatory backend

1. Every authoritative Directional compile must use the **GMP exact-arithmetic backend**. The fallback `BigInteger` / `ExactNumber` backend is not acceptable compile, package, or Test + Benchmark authority.
2. CMake must be configured with `DIRECTIONAL_ENABLE_GMP=ON`. A configure that disables GMP, silently falls back because GMP is missing, or links only one half of the GMP/GMPXX pair is invalid evidence and must fail closed.
3. Every compiled target that consumes `directional_core` must resolve the public GMP linkage. Build evidence must prove both **`gmpxx` and `gmp`** are present on an authoritative generated link command.
4. Build/package evidence must record `exactArithmeticBackend=GMP`. A missing or different backend record is an orchestration/build-evidence failure, never permission to accept fallback output.
5. On Linux CI, provision `libgmp-dev` before configure and use the system root (currently `GMP_ROOT=/usr`) unless the toolchain has an equivalent explicit GMP prefix. On Windows or other supported platforms, the configured dependency mechanism must still resolve both GMP and GMPXX.
6. Artifact-only Test + Benchmark execution of a dynamically linked package must provide the GMP runtime libraries required by that package. TB may not rebuild or relink to repair a missing GMP runtime.

## GitHub Actions implementation

All ChatGPT Web compile work must continue to use `.github/workflows/agent-compile-reusable.yml`. That durable workflow is the implementation authority for this policy and must continue to:

- provision/verify GMP before configure;
- force `DIRECTIONAL_ENABLE_GMP=ON`;
- verify CMake reports GMP discovery;
- verify an authoritative link command contains both `gmpxx` and `gmp`;
- package GMP evidence and `exactArithmeticBackend=GMP`; and
- fail closed if any of those checks fail.

Turn-specific compile callers may select only the approved source SHA, targets, artifact prefix, and other inputs explicitly owned by the reusable workflow contract. They may not disable, replace, or bypass GMP.
