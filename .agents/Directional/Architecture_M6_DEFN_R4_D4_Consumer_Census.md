# D4 Consumer and Frozen-Assertion Census

**Authority:** exact snapshot `c7deb092e86f0912a304397e364d47dc94587a5a` (source-snapshot run `37137065911`, artifact `11277809639`).

This census is intentionally conservative: every exact textual reference to the frozen D4 output names under `src/`, `include/`, `tests/`, and `benchmarks/` is retained. A row marked `producer/*` is not discarded, so the census cannot hide a read embedded in a mutation expression. `production` means runtime/library source; `test` includes test/benchmark evidence code. Test rows name the enclosing GTest identity when statically recoverable and map it to selector449 and focused-12 when present.

Unique reference sites: **1189** (`production` 666, `test` 523).

| Output | Reference sites |
|---|---:|
| `vertexPositions` | 63 |
| `vertexProvenance` | 159 |
| `sourcePoint` | 115 |
| `sourceSupport` | 164 |
| `sourceCharts` | 226 |
| `sourceIsolationSheets` | 71 |
| `sourceTopologyRegions` | 276 |
| `quotientClass` | 29 |
| `equivalences` | 34 |
| `selectedRelationPaths` | 21 |
| `hash_completion` | 18 |
| `BenchmarkQuality` | 18 |

| file:line | class | role hint | output(s) | frozen test authority | source |
|---|---|---|---|---|---|
| `include/directional/diagnostics/RemeshDiagnostics.h:89` | production | consumer/read | `sourceIsolationSheets` | — | `std::vector<int> sourceIsolationSheets;` |
| `include/directional/geometry/PureQuadCompletion.h:233` | production | consumer/read | `sourceSupport` | — | `std::optional<authority::SourceSupport> sourceSupport;` |
| `include/directional/geometry/PureQuadCompletion.h:243` | production | consumer/read | `sourceSupport` | — | `return sourceSupport.has_value() && startChartComponent.valid &&` |
| `include/directional/geometry/PureQuadCompletion.h:276` | production | consumer/read | `sourcePoint` | — | `SurfacePoint sourcePoint;` |
| `include/directional/geometry/PureQuadCompletion.h:287` | production | consumer/read | `sourceTopologyRegions` | — | `std::vector<authority::TopologyRegionId> sourceTopologyRegions;` |
| `include/directional/geometry/PureQuadCompletion.h:288` | production | consumer/read | `sourceCharts` | — | `std::vector<SourceProjectionChart> sourceCharts;` |
| `include/directional/geometry/PureQuadCompletion.h:289` | production | consumer/read | `sourceIsolationSheets` | — | `std::vector<authority::IsolationSheetId> sourceIsolationSheets;` |
| `include/directional/geometry/PureQuadCompletion.h:290` | production | consumer/read | `sourceSupport` | — | `std::optional<authority::SourceSupport> sourceSupport;` |
| `include/directional/geometry/PureQuadCompletion.h:292` | production | consumer/read | `quotientClass` | — | `std::optional<authority::QuotientClassId> quotientClass;` |
| `include/directional/geometry/PureQuadCompletion.h:295` | production | consumer/read | `equivalences` | — | `std::vector<PureQuadEquivalenceProvenance> equivalences;` |
| `include/directional/geometry/PureQuadCompletion.h:296` | production | consumer/read | `selectedRelationPaths` | — | `std::vector<SelectedRelationPathCertificate> selectedRelationPaths;` |
| `include/directional/geometry/PureQuadCompletion.h:300` | production | consumer/read | `sourcePoint` | — | `sourcePoint.valid()) \|\|` |
| `include/directional/geometry/PureQuadCompletion.h:366` | production | consumer/read | `vertexPositions` | — | `Eigen::MatrixXd vertexPositions;` |
| `include/directional/geometry/PureQuadCompletion.h:367` | production | consumer/read | `vertexProvenance` | — | `std::vector<SurfacePoint> vertexProvenance;` |
| `include/directional/geometry/PureQuadCompletion.h:394` | production | consumer/read | `sourceSupport` | — | `std::optional<authority::SourceSupport> sourceSupport;` |
| `include/directional/geometry/PureQuadCompletion.h:409` | production | consumer/read | `sourceSupport` | — | `const SurfacePointSourceSupportResolver *sourceSupportResolver = nullptr;` |
| `include/directional/geometry/PureQuadCompletion.h:528` | production | consumer/read | `sourceSupport` | — | `const SurfacePointSourceSupportResolver *sourceSupportResolver,` |
| `include/directional/geometry/SourceChartTransitions.h:121` | production | consumer/read | `sourceSupport` | — | `ResolvedSourceEntity(authority::SourceSupport sourceSupport,` |
| `include/directional/geometry/SourceChartTransitions.h:125` | production | consumer/read | `sourceSupport` | — | `: support(std::move(sourceSupport)), chart(std::move(projectionChart)),` |
| `include/directional/geometry/SurfaceArrangement.h:374` | production | consumer/read | `sourceCharts` | — | `std::vector<SourceProjectionChart> sourceCharts;` |
| `include/directional/geometry/SurfaceCellOwnership.h:44` | production | consumer/read | `sourceCharts` | — | `std::vector<SurfaceCellSourceChartIdentity> sourceCharts;` |
| `include/directional/geometry/SurfaceCellOwnership.h:52` | production | consumer/read | `sourceCharts` | — | `!ownershipClasses.empty() \|\| !sourceCharts.empty() \|\|` |
| `include/directional/geometry/SurfaceCellOwnership.h:76` | production | consumer/read | `sourceCharts` | — | `mix(static_cast<std::int64_t>(sourceCharts.size()));` |
| `include/directional/geometry/SurfaceCellOwnership.h:89` | production | consumer/read | `sourceCharts` | — | `lhs.sourceCharts, lhs.hardRails,` |
| `include/directional/geometry/SurfaceCellOwnership.h:94` | production | consumer/read | `sourceCharts` | — | `rhs.sourceCharts, rhs.hardRails,` |
| `include/directional/geometry/SurfaceCellOwnership.h:108` | production | consumer/read | `sourceCharts` | — | `lhs.sourceCharts, lhs.hardRails,` |
| `include/directional/geometry/SurfaceCellOwnership.h:113` | production | consumer/read | `sourceCharts` | — | `rhs.sourceCharts, rhs.hardRails,` |
| `include/directional/geometry/SurfaceCellOwnership.h:183` | production | consumer/read | `sourceSupport` | — | `SurfaceCellCanonicalIdentity sourceSupport;` |
| `include/directional/geometry/SurfaceCellOwnership.h:191` | production | consumer/read | `sourceSupport` | — | `int sourceSupportCount = 0;` |
| `include/directional/geometry/SurfaceCellOwnership.h:203` | production | consumer/read | `sourceSupport` | — | `mix(sourceSupport.hash());` |
| `include/directional/geometry/SurfaceCellOwnership.h:210` | production | consumer/read | `sourceSupport` | — | `mix(static_cast<std::uint64_t>(sourceSupportCount));` |
| `include/directional/geometry/SurfaceCellOwnership.h:239` | production | consumer/read | `sourceSupport` | — | `sourceSupportCount == other.sourceSupportCount &&` |
| `include/directional/geometry/SurfaceCellOwnership.h:241` | production | producer/write-or-init | `sourceSupport` | — | `sourceSupport == other.sourceSupport;` |
| `include/directional/geometry/SurfaceCellOwnership.h:249` | production | consumer/read | `sourceSupport` | — | `sourceSupportCount == other.sourceSupportCount &&` |
| `include/directional/geometry/SurfaceCellOwnership.h:251` | production | producer/write-or-init | `sourceSupport` | — | `sourceSupport == other.sourceSupport;` |
| `include/directional/geometry/SurfaceCellOwnership.h:262` | production | consumer/read | `sourceSupport` | — | `lhs.sourceSupportCount == rhs.sourceSupportCount &&` |
| `include/directional/geometry/SurfaceCellOwnership.h:265` | production | producer/write-or-init | `sourceSupport` | — | `lhs.sourceSupport == rhs.sourceSupport;` |
| `include/directional/geometry/SurfaceCellOwnership.h:287` | production | consumer/read | `sourceSupport` | — | `if (lhs.sourceSupportCount != rhs.sourceSupportCount) {` |
| `include/directional/geometry/SurfaceCellOwnership.h:288` | production | consumer/read | `sourceSupport` | — | `return lhs.sourceSupportCount < rhs.sourceSupportCount;` |
| `include/directional/geometry/SurfaceCellOwnership.h:296` | production | consumer/read | `sourceSupport` | — | `if (lhs.sourceSupport != rhs.sourceSupport) {` |
| `include/directional/geometry/SurfaceCellOwnership.h:297` | production | consumer/read | `sourceSupport` | — | `return lhs.sourceSupport < rhs.sourceSupport;` |
| `include/directional/geometry/SurfaceCellTracing.h:540` | production | consumer/read | `sourceTopologyRegions` | — | `sourceTopologyRegions(std::move(topologyRegions)) {}` |
| `include/directional/geometry/SurfaceCellTracing.h:549` | production | consumer/read | `sourceTopologyRegions` | — | `std::vector<authority::TopologyRegionId> sourceTopologyRegions;` |
| `include/directional/geometry/SurfaceCellTracing.h:1789` | production | consumer/read | `sourceTopologyRegions` | — | `make(int gridU, int gridV, SourceTopologyRegions sourceTopologyRegions,` |
| `include/directional/geometry/SurfaceCellTracing.h:1802` | production | consumer/read | `sourceTopologyRegions` | — | `[[nodiscard]] const SourceTopologyRegions &sourceTopologyRegions() const noexcept {` |
| `include/directional/geometry/SurfaceCellTracing.h:1803` | production | consumer/read | `sourceTopologyRegions` | — | `return sourceTopologyRegions_;` |
| `include/directional/geometry/SurfaceCellTracing.h:1833` | production | consumer/read | `sourceTopologyRegions` | — | `int gridU, int gridV, SourceTopologyRegions sourceTopologyRegions,` |
| `include/directional/geometry/SurfaceCellTracing.h:1843` | production | consumer/read | `sourceTopologyRegions` | — | `sourceTopologyRegions_(std::move(sourceTopologyRegions)),` |
| `include/directional/geometry/SurfaceCellTracing.h:1854` | production | consumer/read | `sourceTopologyRegions` | — | `SourceTopologyRegions sourceTopologyRegions_;` |
| `include/directional/geometry/SurfaceCellTracing.h:1892` | production | consumer/read | `sourceTopologyRegions` | — | `product.sourceTopologyRegions().regions().empty() \|\|` |
| `include/directional/geometry/SurfaceCellTracing.h:1893` | production | consumer/read | `sourceTopologyRegions` | — | `product.sourceTopologyRegions().face_count() == 0U) {` |
| `include/directional/geometry/SurfaceCellTracing.h:2122` | production | consumer/read | `sourceTopologyRegions` | — | `std::optional<SourceTopologyRegions> sourceTopologyRegions;` |
| `include/directional/geometry/SurfaceMeshOptimizer.h:139` | production | consumer/read | `vertexProvenance` | — | `std::vector<SurfacePoint> vertexProvenance;` |
| `include/directional/geometry/SurfaceMeshOptimizer.h:190` | production | consumer/read | `vertexProvenance` | — | `std::vector<SurfacePoint> vertexProvenance;` |
| `include/directional/geometry/SurfaceMeshOptimizer.h:798` | production | producer/write-or-init | `vertexProvenance` | — | `const std::vector<SurfacePoint> *vertexProvenance = nullptr,` |
| `include/directional/meshing/PatchQuadrangulator.h:72` | production | consumer/read | `vertexPositions` | — | `if (mesh.vertexPositions.rows() ==` |
| `include/directional/meshing/PatchQuadrangulator.h:74` | production | consumer/read | `vertexPositions` | — | `return output_has_no_t_junctions(mesh, mesh.vertexPositions);` |
| `include/directional/meshing/PatchQuadrangulator.h:81` | production | consumer/read | `vertexPositions` | — | `const Eigen::MatrixXd &vertexPositions) {` |
| `include/directional/meshing/PatchQuadrangulator.h:82` | production | consumer/read | `vertexPositions` | — | `if (vertexPositions.rows() !=` |
| `include/directional/meshing/PatchQuadrangulator.h:84` | production | consumer/read | `vertexPositions` | — | `vertexPositions.cols() != 3) {` |
| `include/directional/meshing/PatchQuadrangulator.h:125` | production | consumer/read | `vertexPositions` | — | `vertexPositions, faces, options);` |
| `include/directional/meshing/PatchRegion.h:52` | production | consumer/read | `vertexPositions` | — | `Eigen::MatrixXd vertexPositions;` |
| `include/directional/pipeline/RemeshPipeline.h:323` | production | consumer/read | `sourceTopologyRegions` | — | `std::optional<geometry::SourceTopologyRegions> sourceTopologyRegions;` |
| `include/directional/pipeline/RemeshPipeline.h:816` | production | consumer/read | `sourcePoint` | — | `geometry::SurfacePoint sourcePoint,` |
| `include/directional/pipeline/RemeshPipeline.h:817` | production | consumer/read | `sourceSupport` | — | `authority::SourceSupport sourceSupport,` |
| `include/directional/pipeline/RemeshPipeline.h:825` | production | consumer/read | `sourcePoint` | — | `: id(occurrenceId), point(std::move(sourcePoint)),` |
| `include/directional/pipeline/RemeshPipeline.h:826` | production | consumer/read | `sourceSupport` | — | `support(std::move(sourceSupport)),` |
| `include/directional/pipeline/RemeshPipeline.h:1057` | production | consumer/read | `quotientClass` | — | `: quotientClass(std::move(classId)), root(rootOccurrence),` |
| `include/directional/pipeline/RemeshPipeline.h:1060` | production | consumer/read | `quotientClass` | — | `SurfaceQuotientClassId quotientClass;` |
| `include/directional/pipeline/RemeshPipeline.h:1075` | production | consumer/read | `equivalences` | — | `std::vector<geometry::PureQuadEquivalenceProvenance> equivalences;` |
| `include/directional/pipeline/RemeshPipeline.h:1325` | production | consumer/read | `hash_completion` | — | `std::uint64_t hash_completion_mesh(` |
| `include/directional/pipeline/RemeshPipeline.h:1329` | production | consumer/read | `hash_completion` | — | `std::uint64_t hash_completion(const geometry::PureQuadMesh &mesh);` |
| `include/directional/pipeline/RemeshPipeline.h:1665` | production | consumer/read | `sourceTopologyRegions` | — | `std::optional<geometry::SourceTopologyRegions> sourceTopologyRegions;` |
| `include/directional/validation/MeshValidator.h:78` | production | consumer/read | `vertexProvenance` | — | `std::vector<geometry::SurfacePoint> vertexProvenance;` |
| `include/directional/validation/MeshValidator.h:453` | production | consumer/read | `vertexProvenance` | — | `if (options.vertexProvenance.empty()) {` |
| `include/directional/validation/MeshValidator.h:458` | production | consumer/read | `vertexProvenance` | — | `if (maxIndex >= options.vertexProvenance.size()) {` |
| `include/directional/validation/MeshValidator.h:462` | production | consumer/read | `vertexProvenance` | — | `options.vertexProvenance[static_cast<std::size_t>(vertex)];` |
| `include/directional/validation/MeshValidator.h:464` | production | consumer/read | `vertexProvenance` | — | `options.vertexProvenance[static_cast<std::size_t>(a)];` |
| `include/directional/validation/MeshValidator.h:466` | production | consumer/read | `vertexProvenance` | — | `options.vertexProvenance[static_cast<std::size_t>(b)];` |
| `include/directional/validation/MeshValidator.h:482` | production | consumer/read | `vertexProvenance` | — | `options.vertexProvenance.size() <` |
| `include/directional/validation/SourceAuthoritativeMeshValidator.h:65` | production | consumer/read | `sourceCharts` | — | `std::vector<geometry::SourceProjectionChart> sourceCharts;` |
| `include/directional/validation/SourceAuthoritativeMeshValidator.h:74` | production | producer/write-or-init | `vertexProvenance` | — | `const std::vector<geometry::SurfacePoint> *vertexProvenance = nullptr;` |
| `include/directional/validation/SourceAuthoritativeMeshValidator.h:320` | production | consumer/read | `sourceSupport` | — | `geometry::SurfacePointSourceSupportResolver sourceSupport;` |
| `include/directional/validation/SourceAuthoritativeMeshValidator.h:327` | production | consumer/read | `sourceSupport` | — | `: sourceFaces(faces), authority(sourceAuthority), sourceSupport(faces),` |
| `include/directional/validation/SourceAuthoritativeMeshValidator.h:395` | production | consumer/read | `sourceSupport` | — | `return sourceSupport.available() && transitionGraph.available() &&` |
| `include/directional/validation/SourceAuthoritativeMeshValidator.h:405` | production | consumer/read | `sourceSupport` | — | `return sourceSupport.resolve(point).incidentFaces;` |
| `src/bench/BenchmarkQuality.cpp:1` | production | consumer/read | `BenchmarkQuality` | — | `#include "BenchmarkQuality.h"` |
| `src/bench/BenchmarkQuality.cpp:569` | production | consumer/read | `BenchmarkQuality` | — | `BenchmarkQuality &quality) {` |
| `src/bench/BenchmarkQuality.cpp:1080` | production | consumer/read | `sourceSupport` | — | `lineage.sourceSupport.has_value() ? 1 : 0});` |
| `src/bench/BenchmarkQuality.cpp:1081` | production | consumer/read | `sourceSupport` | — | `if (lineage.sourceSupport.has_value()) {` |
| `src/bench/BenchmarkQuality.cpp:1082` | production | consumer/read | `sourceSupport` | — | `const auto &support = lineage.sourceSupport.value();` |
| `src/bench/BenchmarkQuality.cpp:1106` | production | consumer/read | `sourceTopologyRegions` | — | `append_semantic_ids(record, lineage.sourceTopologyRegions);` |
| `src/bench/BenchmarkQuality.cpp:1107` | production | consumer/read | `sourceIsolationSheets` | — | `append_semantic_ids(record, lineage.sourceIsolationSheets);` |
| `src/bench/BenchmarkQuality.cpp:1108` | production | producer/mutation-or-mixed | `quotientClass` | — | `record.push_back(lineage.quotientClass.has_value()` |
| `src/bench/BenchmarkQuality.cpp:1110` | production | consumer/read | `quotientClass` | — | `lineage.quotientClass->index())` |
| `src/bench/BenchmarkQuality.cpp:1115` | production | consumer/read | `sourceCharts` | — | `lineage.sourceCharts;` |
| `src/bench/BenchmarkQuality.cpp:1128` | production | consumer/read | `equivalences` | — | `for (const auto &equivalence : lineage.equivalences) {` |
| `src/bench/BenchmarkQuality.cpp:1186` | production | consumer/read | `selectedRelationPaths` | — | `for (const auto &certificate : lineage.selectedRelationPaths) {` |
| `src/bench/BenchmarkQuality.cpp:1188` | production | producer/mutation-or-mixed | `sourceSupport` | — | `path.push_back(certificate.sourceSupport.has_value()` |
| `src/bench/BenchmarkQuality.cpp:1191` | production | consumer/read | `sourceSupport` | — | `certificate.sourceSupport.value()))` |
| `src/bench/BenchmarkQuality.cpp:1193` | production | consumer/read | `sourceSupport` | — | `if (certificate.sourceSupport.has_value()) {` |
| `src/bench/BenchmarkQuality.cpp:1194` | production | consumer/read | `sourceSupport` | — | `const auto &support = certificate.sourceSupport.value();` |
| `src/bench/BenchmarkQuality.cpp:1403` | production | consumer/read | `BenchmarkQuality` | — | `BenchmarkQuality evaluate_benchmark_quality(` |
| `src/bench/BenchmarkQuality.cpp:1408` | production | consumer/read | `BenchmarkQuality` | — | `BenchmarkQuality quality;` |
| `src/bench/BenchmarkQuality.cpp:1487` | production | producer/write-or-init | `sourcePoint` | — | `const geometry::SurfacePoint sourcePoint =` |
| `src/bench/BenchmarkQuality.cpp:1489` | production | consumer/read | `sourcePoint` | — | `if (sourcePoint.valid()) {` |
| `src/bench/BenchmarkQuality.cpp:1490` | production | consumer/read | `sourcePoint` | — | `const int a = sourceMesh.faces(sourcePoint.face, 0);` |
| `src/bench/BenchmarkQuality.cpp:1491` | production | consumer/read | `sourcePoint` | — | `const int b = sourceMesh.faces(sourcePoint.face, 1);` |
| `src/bench/BenchmarkQuality.cpp:1492` | production | consumer/read | `sourcePoint` | — | `const int c = sourceMesh.faces(sourcePoint.face, 2);` |
| `src/bench/BenchmarkQuality.cpp:1503` | production | consumer/read | `sourcePoint` | — | `field_alignment_error(tangent, field, sourcePoint.face));` |
| `src/bench/BenchmarkQuality.cpp:1552` | production | consumer/read | `BenchmarkQuality` | — | `const BenchmarkQuality &quality) {` |
| `src/bench/BenchmarkQuality.h:15` | production | consumer/read | `BenchmarkQuality` | — | `struct BenchmarkQuality {` |
| `src/bench/BenchmarkQuality.h:70` | production | consumer/read | `BenchmarkQuality` | — | `[[nodiscard]] BenchmarkQuality evaluate_benchmark_quality(` |
| `src/bench/BenchmarkQuality.h:81` | production | consumer/read | `BenchmarkQuality` | — | `const BenchmarkQuality &quality);` |
| `src/bench/DirectionalBenchmark.cpp:2` | production | consumer/read | `BenchmarkQuality` | — | `#include "BenchmarkQuality.h"` |
| `src/bench/DirectionalBenchmark.cpp:90` | production | consumer/read | `BenchmarkQuality` | — | `BenchmarkQuality quality;` |
| `src/bench/DirectionalBenchmark.cpp:713` | production | consumer/read | `BenchmarkQuality` | — | `std::map<std::uint64_t, BenchmarkQuality> *qualityCache = nullptr) {` |
| `src/bench/DirectionalBenchmark.cpp:1239` | production | consumer/read | `sourceTopologyRegions` | — | `result.surfaceCellContext.productSnapshots.traceNetwork.sourceTopologyRegions.has_value()` |
| `src/bench/DirectionalBenchmark.cpp:1240` | production | consumer/read | `sourceTopologyRegions` | — | `? &*result.surfaceCellContext.productSnapshots.traceNetwork.sourceTopologyRegions` |
| `src/bench/DirectionalBenchmark.cpp:2210` | production | consumer/read | `sourceSupport` | — | `if (ownershipRejection.sourceSupport.has_value()) {` |
| `src/bench/DirectionalBenchmark.cpp:2213` | production | consumer/read | `sourceSupport` | — | `&ownershipRejection.sourceSupport.value())) {` |
| `src/bench/DirectionalBenchmark.cpp:2218` | production | consumer/read | `sourceSupport` | — | `&ownershipRejection.sourceSupport.value())) {` |
| `src/bench/DirectionalBenchmark.cpp:3402` | production | consumer/read | `BenchmarkQuality` | — | `std::map<std::uint64_t, directional::bench::BenchmarkQuality>` |
| `src/geometry/FlowRepStrands.cpp:475` | production | consumer/read | `sourceTopologyRegions` | — | `if (!network.sourceTopologyRegions.has_value() \|\| sourceFace < 0) {` |
| `src/geometry/FlowRepStrands.cpp:478` | production | consumer/read | `sourceTopologyRegions` | — | `const SourceTopologyRegions &authority = *network.sourceTopologyRegions;` |
| `src/geometry/PatchDescriptor.cpp:76` | production | producer/mutation-or-mixed | `sourceCharts` | — | `destination.sourceCharts.push_back(` |
| `src/geometry/PatchDescriptor.cpp:324` | production | producer/mutation-or-mixed | `sourceCharts` | — | `destination.values.push_back(static_cast<std::int64_t>(identity.sourceCharts.size()));` |
| `src/geometry/PatchDescriptor.cpp:340` | production | producer/mutation-or-mixed | `sourceCharts` | — | `destination.sourceCharts.insert(destination.sourceCharts.end(),` |
| `src/geometry/PatchDescriptor.cpp:341` | production | consumer/read | `sourceCharts` | — | `identity.sourceCharts.begin(),` |
| `src/geometry/PatchDescriptor.cpp:342` | production | consumer/read | `sourceCharts` | — | `identity.sourceCharts.end());` |
| `src/geometry/PatchDescriptor.cpp:546` | production | producer/mutation-or-mixed | `sourceCharts` | — | `charts.reserve(cell.sourceCharts.size());` |
| `src/geometry/PatchDescriptor.cpp:547` | production | consumer/read | `sourceCharts` | — | `for (const SourceProjectionChart &chart : cell.sourceCharts) {` |
| `src/geometry/PatchDescriptor.cpp:556` | production | producer/write-or-init | `sourceCharts` | — | `result.sourceCharts = std::move(charts);` |
| `src/geometry/PatchDescriptor.cpp:563` | production | consumer/read | `sourceCharts` | — | `return std::binary_search(cell.sourceCharts.begin(), cell.sourceCharts.end(),` |
| `src/geometry/PatchDescriptor.cpp:600` | production | consumer/read | `sourceCharts` | — | `if (!cell.sourceTopologyRegion.has_value() \|\| cell.sourceCharts.empty() \|\|` |
| `src/geometry/PatchDescriptor.cpp:601` | production | consumer/read | `sourceCharts` | — | `!std::is_sorted(cell.sourceCharts.begin(), cell.sourceCharts.end())) {` |
| `src/geometry/PatchDescriptor.cpp:619` | production | consumer/read | `sourceCharts` | — | `for (const SourceProjectionChart &chart : cell.sourceCharts) {` |
| `src/geometry/PatchDescriptor.cpp:795` | production | producer/write-or-init | `sourceSupport` | — | `audit.identity.sourceSupport = source_support_identity(cell, F);` |
| `src/geometry/PatchDescriptor.cpp:800` | production | consumer/read | `sourceSupport` | — | `audit.identity.sourceSupportCount = source_support_count(cell, F);` |
| `src/geometry/PatchDescriptor.cpp:802` | production | consumer/read | `sourceSupport` | — | `if (!audit.identity.sourceSupport.valid \|\|` |
| `src/geometry/PatchDescriptor.cpp:806` | production | consumer/read | `sourceSupport` | — | `audit.identity.sourceSupportCount <= 0) {` |
| `src/geometry/PatchDescriptor.cpp:875` | production | consumer/read | `sourceSupport` | — | `std::vector<SurfaceCellCanonicalIdentity *> sourceSupports;` |
| `src/geometry/PatchDescriptor.cpp:885` | production | producer/mutation-or-mixed | `sourceSupport` | — | `sourceSupports.push_back(&descriptor.patch.domainIdentity.sourceSupport);` |
| `src/geometry/PatchDescriptor.cpp:893` | production | consumer/read | `sourceSupport` | — | `compact_identity_group(std::move(sourceSupports), 4);` |
| `src/geometry/PatchDescriptor.cpp:1255` | production | consumer/read | `sourceSupport` | — | `identity.sourceSupportCount,` |
| `src/geometry/PatchDescriptor.cpp:1262` | production | consumer/read | `sourceSupport` | — | `append_repair_identity(destination, identity.sourceSupport);` |
| `src/geometry/PatchDescriptor.cpp:1416` | production | consumer/read | `sourceCharts` | — | `bytes += static_cast<std::uint64_t>(cell.sourceCharts.size()) *` |
| `src/geometry/PatchDescriptor.cpp:1453` | production | consumer/read | `sourceCharts` | — | `bytes += static_cast<std::uint64_t>(cell.sourceCharts.capacity()) *` |
| `src/geometry/PatchDescriptor.cpp:1564` | production | consumer/read | `vertexPositions` | — | `bytes += static_cast<std::uint64_t>(mesh.vertexPositions.size()) *` |
| `src/geometry/PatchDescriptor.cpp:1566` | production | consumer/read | `vertexProvenance` | — | `bytes += static_cast<std::uint64_t>(mesh.vertexProvenance.size()) *` |
| `src/geometry/PatchDescriptor.cpp:1592` | production | consumer/read | `vertexPositions` | — | `bytes += static_cast<std::uint64_t>(mesh.vertexPositions.size()) *` |
| `src/geometry/PatchDescriptor.cpp:1594` | production | consumer/read | `vertexProvenance` | — | `bytes += static_cast<std::uint64_t>(mesh.vertexProvenance.capacity()) *` |
| `src/geometry/PatchDescriptor.cpp:1924` | production | consumer/read | `sourceSupport` | — | `first.patch.domainIdentity.sourceSupport.hash();` |
| `src/geometry/PatchDescriptor.cpp:1926` | production | consumer/read | `sourceSupport` | — | `identity.sourceSupport.hash();` |
| `src/geometry/PatchDescriptor.cpp:1928` | production | consumer/read | `sourceSupport` | — | `first.patch.domainIdentity.sourceSupportCount;` |
| `src/geometry/PatchDescriptor.cpp:1930` | production | consumer/read | `sourceSupport` | — | `identity.sourceSupportCount;` |
| `src/geometry/PatchDescriptor.cpp:1940` | production | consumer/read | `sourceSupport` | — | `identity.sourceSupport, identity.undirectedBoundary};` |
| `src/geometry/PatchDescriptor.cpp:1957` | production | consumer/read | `sourceSupport` | — | `first.patch.domainIdentity.sourceSupport.hash();` |
| `src/geometry/PatchDescriptor.cpp:1959` | production | consumer/read | `sourceSupport` | — | `identity.sourceSupport.hash();` |
| `src/geometry/PatchDescriptor.cpp:1961` | production | consumer/read | `sourceSupport` | — | `first.patch.domainIdentity.sourceSupportCount;` |
| `src/geometry/PatchDescriptor.cpp:1963` | production | consumer/read | `sourceSupport` | — | `identity.sourceSupportCount;` |
| `src/geometry/PatchDescriptor.cpp:2034` | production | producer/mutation-or-mixed | `sourceCharts` | — | `identity.sourceCharts.push_back({chart.chart, chart.face});` |
| `src/geometry/PatchDescriptor.cpp:2205` | production | consumer/read | `sourceSupport` | — | `patch.domainIdentity.sourceSupportCount,` |
| `src/geometry/PatchDescriptor.cpp:2216` | production | consumer/read | `sourceSupport` | — | `append_identity(fields.sourceDomain, patch.domainIdentity.sourceSupport);` |
| `src/geometry/PatchDescriptor.cpp:2482` | production | consumer/read | `sourceSupport` | — | `const SurfacePointSourceSupportResolver sourceSupportResolver(F);` |
| `src/geometry/PatchDescriptor.cpp:2728` | production | consumer/read | `sourceSupport` | — | `completionOptions.sourceSupportResolver = &sourceSupportResolver;` |
| `src/geometry/PatchDescriptor.cpp:2844` | production | consumer/read | `sourceSupport` | — | `&sourceSupportResolver, &F, options.sourceAuthority,` |
| `src/geometry/PatchDescriptor.cpp:3591` | production | consumer/read | `sourceSupport` | — | `left->domain.sourceSupport.valid &&` |
| `src/geometry/PatchDescriptor.cpp:3592` | production | consumer/read | `sourceSupport` | — | `right->domain.sourceSupport.valid &&` |
| `src/geometry/PatchDescriptor.cpp:3593` | production | producer/write-or-init | `sourceSupport` | — | `left->domain.sourceSupport == right->domain.sourceSupport) \|\|` |
| `src/geometry/PureQuadCompletion.cpp:346` | production | producer/mutation-or-mixed | `vertexProvenance` | — | `mesh.vertexProvenance.clear();` |
| `src/geometry/PureQuadCompletion.cpp:347` | production | producer/mutation-or-mixed | `vertexProvenance` | — | `mesh.vertexProvenance.reserve(mesh.vertices.size());` |
| `src/geometry/PureQuadCompletion.cpp:352` | production | producer/mutation-or-mixed | `vertexProvenance` | — | `mesh.vertexProvenance.push_back(point);` |
| `src/geometry/PureQuadCompletion.cpp:359` | production | producer/mutation-or-mixed | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.push_back(` |
| `src/geometry/PureQuadCompletion.cpp:363` | production | producer/mutation-or-mixed | `sourceCharts` | — | `lineage.sourceCharts.push_back(` |
| `src/geometry/PureQuadCompletion.cpp:390` | production | producer/write-or-init | `sourcePoint` | — | `lineage.sourcePoint = point;` |
| `src/geometry/PureQuadCompletion.cpp:412` | production | producer/mutation-or-mixed | `vertexProvenance` | — | `mesh.vertexProvenance.push_back(point);` |
| `src/geometry/PureQuadCompletion.cpp:415` | production | producer/write-or-init | `sourcePoint` | — | `lineage.sourcePoint = point;` |
| `src/geometry/PureQuadCompletion.cpp:422` | production | producer/mutation-or-mixed | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.push_back(` |
| `src/geometry/PureQuadCompletion.cpp:424` | production | producer/mutation-or-mixed | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.push_back(` |
| `src/geometry/PureQuadCompletion.cpp:439` | production | producer/mutation-or-mixed | `vertexPositions` | — | `mesh.vertexPositions.resize(static_cast<int>(mesh.vertices.size()), 3);` |
| `src/geometry/PureQuadCompletion.cpp:441` | production | consumer/read | `vertexProvenance` | — | `if (i < static_cast<int>(mesh.vertexProvenance.size()) &&` |
| `src/geometry/PureQuadCompletion.cpp:442` | production | consumer/read | `vertexProvenance` | — | `mesh.vertexProvenance[static_cast<std::size_t>(i)].valid()) {` |
| `src/geometry/PureQuadCompletion.cpp:443` | production | consumer/read | `vertexPositions` | — | `mesh.vertexPositions.row(i) =` |
| `src/geometry/PureQuadCompletion.cpp:444` | production | consumer/read | `vertexProvenance` | — | `mesh.vertexProvenance[static_cast<std::size_t>(i)].position;` |
| `src/geometry/PureQuadCompletion.cpp:448` | production | consumer/read | `vertexPositions` | — | `if (!mesh.vertexPositions.row(i).allFinite()) {` |
| `src/geometry/PureQuadCompletion.cpp:463` | production | consumer/read | `sourcePoint` | — | `lineage.sourcePoint.valid()) {` |
| `src/geometry/PureQuadCompletion.cpp:464` | production | consumer/read | `sourcePoint` | — | `point = &lineage.sourcePoint;` |
| `src/geometry/PureQuadCompletion.cpp:504` | production | consumer/read | `vertexProvenance` | — | `if (index < mesh.vertexProvenance.size()) {` |
| `src/geometry/PureQuadCompletion.cpp:505` | production | consumer/read | `vertexProvenance` | — | `const SurfacePoint &point = mesh.vertexProvenance[index];` |
| `src/geometry/PureQuadCompletion.cpp:558` | production | consumer/read | `vertexPositions` | — | `row->second >= mesh.vertexPositions.rows()) {` |
| `src/geometry/PureQuadCompletion.cpp:563` | production | consumer/read | `vertexPositions` | — | `mesh.vertexPositions.row(row->second).transpose();` |
| `src/geometry/PureQuadCompletion.cpp:656` | production | consumer/read | `sourceTopologyRegions` | — | `if (!lineage.sourceTopologyRegions.empty() &&` |
| `src/geometry/PureQuadCompletion.cpp:657` | production | consumer/read | `sourceTopologyRegions` | — | `std::find(lineage.sourceTopologyRegions.begin(),` |
| `src/geometry/PureQuadCompletion.cpp:658` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.end(), region) ==` |
| `src/geometry/PureQuadCompletion.cpp:659` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.end()) {` |
| `src/geometry/PureQuadCompletion.cpp:662` | production | consumer/read | `sourceIsolationSheets` | — | `if (!lineage.sourceIsolationSheets.empty() &&` |
| `src/geometry/PureQuadCompletion.cpp:663` | production | consumer/read | `sourceIsolationSheets` | — | `std::find(lineage.sourceIsolationSheets.begin(),` |
| `src/geometry/PureQuadCompletion.cpp:664` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.end(), sheet) ==` |
| `src/geometry/PureQuadCompletion.cpp:665` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.end()) {` |
| `src/geometry/PureQuadCompletion.cpp:737` | production | producer/write-or-init | `sourceSupport` | — | `rejection->sourceSupport = support.identity;` |
| `src/geometry/PureQuadCompletion.cpp:859` | production | consumer/read | `sourcePoint` | — | `!lineage.sourcePoint.valid() \|\| !support.valid()) {` |
| `src/geometry/PureQuadCompletion.cpp:863` | production | consumer/read | `sourceSupport` | — | `if (lineage.sourceSupport.has_value() &&` |
| `src/geometry/PureQuadCompletion.cpp:864` | production | consumer/read | `sourceSupport` | — | `lineage.sourceSupport != support.identity) {` |
| `src/geometry/PureQuadCompletion.cpp:878` | production | consumer/read | `sourcePoint` | — | `lineage.sourcePoint.face, sourceAuthority->face_count());` |
| `src/geometry/PureQuadCompletion.cpp:891` | production | consumer/read | `sourceCharts` | — | `lineage.sourceCharts;` |
| `src/geometry/PureQuadCompletion.cpp:893` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions;` |
| `src/geometry/PureQuadCompletion.cpp:895` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets;` |
| `src/geometry/PureQuadCompletion.cpp:926` | production | producer/write-or-init | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions = retainedSourceRegions;` |
| `src/geometry/PureQuadCompletion.cpp:927` | production | producer/write-or-init | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets = retainedSourceSheets;` |
| `src/geometry/PureQuadCompletion.cpp:928` | production | producer/write-or-init | `sourceCharts` | — | `lineage.sourceCharts = retainedSourceCharts;` |
| `src/geometry/PureQuadCompletion.cpp:931` | production | producer/write-or-init | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions = {selectedRegion};` |
| `src/geometry/PureQuadCompletion.cpp:932` | production | producer/write-or-init | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets = {selectedSheet};` |
| `src/geometry/PureQuadCompletion.cpp:933` | production | producer/mutation-or-mixed | `sourceCharts` | — | `lineage.sourceCharts.clear();` |
| `src/geometry/PureQuadCompletion.cpp:941` | production | consumer/read | `sourcePoint` | — | `if (!transitionGraph.rebind(lineage.sourcePoint, candidateFace, rebound)) {` |
| `src/geometry/PureQuadCompletion.cpp:946` | production | producer/mutation-or-mixed | `sourceCharts` | — | `lineage.sourceCharts.push_back(chart.value());` |
| `src/geometry/PureQuadCompletion.cpp:956` | production | consumer/read | `equivalences` | — | `lineage.equivalences.begin(), lineage.equivalences.end(),` |
| `src/geometry/PureQuadCompletion.cpp:961` | production | consumer/read | `selectedRelationPaths` | — | `if (hasSelectedRelationEvidence && lineage.selectedRelationPaths.empty()) {` |
| `src/geometry/PureQuadCompletion.cpp:965` | production | consumer/read | `selectedRelationPaths` | — | `if (!lineage.selectedRelationPaths.empty()) {` |
| `src/geometry/PureQuadCompletion.cpp:992` | production | consumer/read | `selectedRelationPaths` | — | `lineage.selectedRelationPaths) {` |
| `src/geometry/PureQuadCompletion.cpp:993` | production | consumer/read | `sourceSupport` | — | `if (!certificate.valid() \|\| certificate.sourceSupport != support.identity \|\|` |
| `src/geometry/PureQuadCompletion.cpp:1068` | production | consumer/read | `equivalences` | — | `lineage.equivalences) {` |
| `src/geometry/PureQuadCompletion.cpp:1107` | production | consumer/read | `equivalences` | — | `lineage.equivalences) {` |
| `src/geometry/PureQuadCompletion.cpp:1162` | production | consumer/read | `sourceTopologyRegions` | — | `std::sort(lineage.sourceTopologyRegions.begin(),` |
| `src/geometry/PureQuadCompletion.cpp:1163` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.end());` |
| `src/geometry/PureQuadCompletion.cpp:1164` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.erase(` |
| `src/geometry/PureQuadCompletion.cpp:1165` | production | consumer/read | `sourceTopologyRegions` | — | `std::unique(lineage.sourceTopologyRegions.begin(),` |
| `src/geometry/PureQuadCompletion.cpp:1166` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.end()),` |
| `src/geometry/PureQuadCompletion.cpp:1167` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.end());` |
| `src/geometry/PureQuadCompletion.cpp:1168` | production | consumer/read | `sourceIsolationSheets` | — | `std::sort(lineage.sourceIsolationSheets.begin(),` |
| `src/geometry/PureQuadCompletion.cpp:1169` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.end());` |
| `src/geometry/PureQuadCompletion.cpp:1170` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.erase(` |
| `src/geometry/PureQuadCompletion.cpp:1171` | production | consumer/read | `sourceIsolationSheets` | — | `std::unique(lineage.sourceIsolationSheets.begin(),` |
| `src/geometry/PureQuadCompletion.cpp:1172` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.end()),` |
| `src/geometry/PureQuadCompletion.cpp:1173` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.end());` |
| `src/geometry/PureQuadCompletion.cpp:1174` | production | consumer/read | `sourceCharts` | — | `std::sort(lineage.sourceCharts.begin(), lineage.sourceCharts.end());` |
| `src/geometry/PureQuadCompletion.cpp:1175` | production | consumer/read | `sourceCharts` | — | `lineage.sourceCharts.erase(` |
| `src/geometry/PureQuadCompletion.cpp:1176` | production | consumer/read | `sourceCharts` | — | `std::unique(lineage.sourceCharts.begin(), lineage.sourceCharts.end()),` |
| `src/geometry/PureQuadCompletion.cpp:1177` | production | consumer/read | `sourceCharts` | — | `lineage.sourceCharts.end());` |
| `src/geometry/PureQuadCompletion.cpp:1178` | production | consumer/read | `sourceCharts` | — | `if (lineage.sourceCharts.empty()) {` |
| `src/geometry/PureQuadCompletion.cpp:1182` | production | producer/write-or-init | `sourceSupport` | — | `lineage.sourceSupport = support.identity;` |
| `src/geometry/PureQuadCompletion.cpp:1193` | production | consumer/read | `vertexProvenance` | — | `mesh.vertices.size() != mesh.vertexProvenance.size() \|\|` |
| `src/geometry/PureQuadCompletion.cpp:1208` | production | consumer/read | `vertexProvenance` | — | `const SurfacePoint &provenance = mesh.vertexProvenance[row];` |
| `src/geometry/PureQuadCompletion.cpp:1213` | production | consumer/read | `sourcePoint` | — | `!lineage.sourcePoint.valid() \|\|` |
| `src/geometry/PureQuadCompletion.cpp:1214` | production | consumer/read | `sourcePoint` | — | `lineage.sourcePoint.face != provenance.face \|\|` |
| `src/geometry/PureQuadCompletion.cpp:1215` | production | consumer/read | `sourcePoint` | — | `(lineage.sourcePoint.barycentric - provenance.barycentric).norm() >` |
| `src/geometry/PureQuadCompletion.cpp:1217` | production | consumer/read | `sourcePoint` | — | `(lineage.sourcePoint.position - provenance.position).norm() > 1.0e-12) {` |
| `src/geometry/PureQuadCompletion.cpp:1223` | production | consumer/read | `sourceSupport` | — | `if (!support.valid() \|\| !lineage.sourceSupport.has_value() \|\|` |
| `src/geometry/PureQuadCompletion.cpp:1224` | production | consumer/read | `sourceSupport` | — | `lineage.sourceSupport != support.identity) {` |
| `src/geometry/PureQuadCompletion.cpp:1240` | production | consumer/read | `sourceSupport` | — | `const SurfacePointSourceSupportResolver *sourceSupportResolver,` |
| `src/geometry/PureQuadCompletion.cpp:1245` | production | consumer/read | `vertexProvenance` | — | `if (mesh.vertices.size() != mesh.vertexProvenance.size() \|\|` |
| `src/geometry/PureQuadCompletion.cpp:1325` | production | consumer/read | `vertexProvenance` | — | `SurfacePoint &provenance = mesh.vertexProvenance[row];` |
| `src/geometry/PureQuadCompletion.cpp:1334` | production | producer/write-or-init | `sourcePoint` | — | `lineage.sourcePoint = provenance;` |
| `src/geometry/PureQuadCompletion.cpp:1341` | production | consumer/read | `sourceSupport` | — | `if (boundaryVertex && sourceSupportResolver != nullptr &&` |
| `src/geometry/PureQuadCompletion.cpp:1342` | production | consumer/read | `sourceSupport` | — | `sourceSupportResolver->available()) {` |
| `src/geometry/PureQuadCompletion.cpp:1343` | production | consumer/read | `sourceSupport` | — | `support = sourceSupportResolver->resolve(provenance);` |
| `src/geometry/PureQuadCompletion.cpp:1525` | production | producer/write-or-init | `sourcePoint` | — | `lineage.sourcePoint = provenance;` |
| `src/geometry/PureQuadCompletion.cpp:1527` | production | producer/write-or-init | `sourceSupport` | — | `lineage.sourceSupport = support.identity;` |
| `src/geometry/PureQuadCompletion.cpp:2114` | production | consumer/read | `sourceSupport` | — | `const SurfacePointSourceSupportResolver *sourceSupportResolver =` |
| `src/geometry/PureQuadCompletion.cpp:2115` | production | consumer/read | `sourceSupport` | — | `options.sourceSupportResolver;` |
| `src/geometry/PureQuadCompletion.cpp:2122` | production | consumer/read | `sourceSupport` | — | `if (sourceSupportResolver == nullptr) {` |
| `src/geometry/PureQuadCompletion.cpp:2125` | production | consumer/read | `sourceSupport` | — | `sourceSupportResolver = ownedSourceSupport.get();` |
| `src/geometry/PureQuadCompletion.cpp:2181` | production | consumer/read | `sourceSupport` | — | `patch, mesh, options.completionVariant, sourceSupportResolver,` |
| `src/geometry/PureQuadCompletion.cpp:2248` | production | consumer/read | `vertexPositions` | — | `mix(patch.vertexPositions.rows());` |
| `src/geometry/PureQuadCompletion.cpp:2250` | production | consumer/read | `vertexPositions` | — | `for (int row = 0; row < patch.vertexPositions.rows(); ++row) {` |
| `src/geometry/PureQuadCompletion.cpp:2251` | production | consumer/read | `vertexPositions` | — | `for (int column = 0; column < patch.vertexPositions.cols(); ++column) {` |
| `src/geometry/PureQuadCompletion.cpp:2253` | production | consumer/read | `vertexPositions` | — | `patch.vertexPositions(row, column) * 1.0e10)));` |
| `src/geometry/PureQuadCompletion.cpp:2262` | production | consumer/read | `sourceCharts` | — | `std::vector<SourceProjectionChart> sourceCharts;` |
| `src/geometry/PureQuadCompletion.cpp:2263` | production | consumer/read | `sourceSupport` | — | `std::optional<authority::SourceSupport> sourceSupport;` |
| `src/geometry/PureQuadCompletion.cpp:2269` | production | consumer/read | `sourceTopologyRegions` | — | `certificate.topologyRegions = lineage.sourceTopologyRegions;` |
| `src/geometry/PureQuadCompletion.cpp:2270` | production | consumer/read | `sourceIsolationSheets` | — | `certificate.isolationSheets = lineage.sourceIsolationSheets;` |
| `src/geometry/PureQuadCompletion.cpp:2271` | production | producer/write-or-init | `sourceCharts` | — | `certificate.sourceCharts = lineage.sourceCharts;` |
| `src/geometry/PureQuadCompletion.cpp:2272` | production | producer/write-or-init | `sourceSupport` | — | `certificate.sourceSupport = lineage.sourceSupport;` |
| `src/geometry/PureQuadCompletion.cpp:2279` | production | consumer/read | `sourceCharts` | — | `normalize(certificate.sourceCharts);` |
| `src/geometry/PureQuadCompletion.cpp:2282` | production | consumer/read | `sourceCharts` | — | `certificate.sourceCharts.empty() \|\|` |
| `src/geometry/PureQuadCompletion.cpp:2283` | production | consumer/read | `sourceSupport` | — | `!certificate.sourceSupport.has_value()) {` |
| `src/geometry/PureQuadCompletion.cpp:2342` | production | consumer/read | `sourceSupport` | — | `!sourceTransitions.available() \|\| !certificate.sourceSupport.has_value() \|\|` |
| `src/geometry/PureQuadCompletion.cpp:2343` | production | consumer/read | `sourceCharts` | — | `certificate.sourceCharts.empty()) {` |
| `src/geometry/PureQuadCompletion.cpp:2349` | production | producer/mutation-or-mixed | `sourceCharts` | — | `ownedRegions.reserve(certificate.sourceCharts.size());` |
| `src/geometry/PureQuadCompletion.cpp:2350` | production | producer/mutation-or-mixed | `sourceCharts` | — | `ownedSheets.reserve(certificate.sourceCharts.size());` |
| `src/geometry/PureQuadCompletion.cpp:2351` | production | consumer/read | `sourceCharts` | — | `for (const SourceProjectionChart &claimedChart : certificate.sourceCharts) {` |
| `src/geometry/PureQuadCompletion.cpp:2357` | production | consumer/read | `sourceSupport` | — | `if (!source_support_is_incident_to_face(certificate.sourceSupport.value(),` |
| `src/geometry/PureQuadCompletion.cpp:2419` | production | consumer/read | `sourceSupport` | — | `if (!first.sourceSupport.has_value() \|\| !second.sourceSupport.has_value() \|\|` |
| `src/geometry/PureQuadCompletion.cpp:2420` | production | consumer/read | `sourceSupport` | — | `first.sourceSupport != second.sourceSupport) {` |
| `src/geometry/PureQuadCompletion.cpp:2424` | production | producer/write-or-init | `sourceSupport` | — | `compatible.sourceSupport = first.sourceSupport;` |
| `src/geometry/PureQuadCompletion.cpp:2433` | production | consumer/read | `sourceCharts` | — | `intersect(first.sourceCharts, second.sourceCharts, compatible.sourceCharts);` |
| `src/geometry/PureQuadCompletion.cpp:2435` | production | consumer/read | `sourceCharts` | — | `compatible.isolationSheets.empty() \|\| compatible.sourceCharts.empty()) {` |
| `src/geometry/PureQuadCompletion.cpp:2445` | production | consumer/read | `sourceCharts` | — | `certificate.isolationSheets.empty() \|\| certificate.sourceCharts.empty() \|\|` |
| `src/geometry/PureQuadCompletion.cpp:2446` | production | consumer/read | `sourceSupport` | — | `!certificate.sourceSupport.has_value()) return {};` |
| `src/geometry/PureQuadCompletion.cpp:2457` | production | producer/mutation-or-mixed | `sourceCharts` | — | `for (const SourceProjectionChart &chart : certificate.sourceCharts) identity.canonical.sourceCharts.push_back({chart.chart, chart.face});` |
| `src/geometry/PureQuadCompletion.cpp:2458` | production | consumer/read | `sourceSupport` | — | `const authority::SourceSupport &support = certificate.sourceSupport.value();` |
| `src/geometry/PureQuadCompletion.cpp:2470` | production | consumer/read | `sourceTopologyRegions` | — | `std::vector<authority::TopologyRegionId> topologyRegions = lineage.sourceTopologyRegions;` |
| `src/geometry/PureQuadCompletion.cpp:2471` | production | consumer/read | `sourceIsolationSheets` | — | `std::vector<authority::IsolationSheetId> isolationSheets = lineage.sourceIsolationSheets;` |
| `src/geometry/PureQuadCompletion.cpp:2476` | production | consumer/read | `sourceCharts`, `sourceSupport` | — | `if (topologyRegions.empty() \|\| isolationSheets.empty() \|\| lineage.sourceCharts.empty() \|\| !lineage.sourceSupport.has_value()) return {};` |
| `src/geometry/PureQuadCompletion.cpp:2768` | production | consumer/read | `sourceSupport` | — | `firstMesh->domainIdentity.sourceSupport.hash();` |
| `src/geometry/PureQuadCompletion.cpp:2770` | production | consumer/read | `sourceSupport` | — | `secondMesh->domainIdentity.sourceSupport.hash();` |
| `src/geometry/PureQuadCompletion.cpp:2772` | production | consumer/read | `sourceSupport` | — | `firstMesh->domainIdentity.sourceSupportCount;` |
| `src/geometry/PureQuadCompletion.cpp:2774` | production | consumer/read | `sourceSupport` | — | `secondMesh->domainIdentity.sourceSupportCount;` |
| `src/geometry/PureQuadCompletion.cpp:2828` | production | consumer/read | `sourceSupport` | — | `firstMesh->domainIdentity.sourceSupport.valid &&` |
| `src/geometry/PureQuadCompletion.cpp:2829` | production | consumer/read | `sourceSupport` | — | `secondMesh->domainIdentity.sourceSupport.valid &&` |
| `src/geometry/PureQuadCompletion.cpp:2830` | production | producer/write-or-init | `sourceSupport` | — | `firstMesh->domainIdentity.sourceSupport ==` |
| `src/geometry/PureQuadCompletion.cpp:2831` | production | consumer/read | `sourceSupport` | — | `secondMesh->domainIdentity.sourceSupport &&` |
| `src/geometry/PureQuadCompletion.cpp:2832` | production | consumer/read | `sourceSupport` | — | `firstMesh->domainIdentity.sourceSupportCount ==` |
| `src/geometry/PureQuadCompletion.cpp:2833` | production | consumer/read | `sourceSupport` | — | `secondMesh->domainIdentity.sourceSupportCount &&` |
| `src/geometry/PureQuadCompletion.cpp:3071` | production | consumer/read | `vertexPositions` | — | `static_cast<std::size_t>(patch.vertexPositions.rows()) \|\|` |
| `src/geometry/PureQuadCompletion.cpp:3072` | production | consumer/read | `vertexProvenance` | — | `patch.vertices.size() != patch.vertexProvenance.size() \|\|` |
| `src/geometry/PureQuadCompletion.cpp:3095` | production | consumer/read | `vertexProvenance` | — | `patch.vertexProvenance[static_cast<std::size_t>(localRow)];` |
| `src/geometry/PureQuadCompletion.cpp:3123` | production | consumer/read | `vertexPositions` | — | `patch.vertexPositions.row(localRow).transpose();` |
| `src/geometry/PureQuadCompletion.cpp:3286` | production | producer/mutation-or-mixed | `vertexPositions` | — | `result.mesh.vertexPositions.resize(` |
| `src/geometry/PureQuadCompletion.cpp:3288` | production | producer/mutation-or-mixed | `vertexProvenance` | — | `result.mesh.vertexProvenance.reserve(pendingVertices.size());` |
| `src/geometry/PureQuadCompletion.cpp:3290` | production | consumer/read | `sourceSupport` | — | `const SurfacePointSourceSupportResolver sourceSupport(sourceFaces);` |
| `src/geometry/PureQuadCompletion.cpp:3294` | production | consumer/read | `vertexProvenance` | — | `SurfacePoint selected = fallbackPatch.vertexProvenance[` |
| `src/geometry/PureQuadCompletion.cpp:3310` | production | consumer/read | `vertexProvenance` | — | `.vertexProvenance.size())) {` |
| `src/geometry/PureQuadCompletion.cpp:3315` | production | consumer/read | `vertexProvenance` | — | `.vertexProvenance[static_cast<std::size_t>(localRow)];` |
| `src/geometry/PureQuadCompletion.cpp:3331` | production | consumer/read | `sourceSupport` | — | `sourceSupport.resolve(*candidates.front());` |
| `src/geometry/PureQuadCompletion.cpp:3377` | production | consumer/read | `vertexPositions` | — | `result.mesh.vertexPositions.row(row) = pending.position;` |
| `src/geometry/PureQuadCompletion.cpp:3384` | production | producer/mutation-or-mixed | `vertexProvenance` | — | `result.mesh.vertexProvenance.push_back(canonicalProvenance);` |
| `src/geometry/PureQuadCompletion.cpp:3392` | production | consumer/read | `vertexProvenance` | — | `lineagePatch.vertexProvenance[static_cast<std::size_t>(` |
| `src/geometry/PureQuadCompletion.cpp:3395` | production | producer/write-or-init | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions = pending.typedAuthority.topologyRegions;` |
| `src/geometry/PureQuadCompletion.cpp:3396` | production | producer/write-or-init | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets = pending.typedAuthority.isolationSheets;` |
| `src/geometry/PureQuadCompletion.cpp:3397` | production | producer/write-or-init | `sourceCharts` | — | `lineage.sourceCharts = pending.typedAuthority.sourceCharts;` |
| `src/geometry/PureQuadCompletion.cpp:3398` | production | producer/write-or-init | `sourceSupport` | — | `lineage.sourceSupport = pending.typedAuthority.sourceSupport;` |
| `src/geometry/PureQuadCompletion.cpp:3410` | production | producer/write-or-init | `sourcePoint` | — | `lineage.sourcePoint = canonicalProvenance;` |
| `src/geometry/PureQuadCompletion.cpp:3875` | production | consumer/read | `vertexPositions` | — | `if (mesh.vertexPositions.rows() ==` |
| `src/geometry/PureQuadCompletion.cpp:3897` | production | consumer/read | `vertexPositions` | — | `validation::MeshValidator::validate_surface_mesh(mesh.vertexPositions,` |
| `src/geometry/PureQuadCompletion.cpp:3955` | production | consumer/read | `vertexProvenance` | — | `if(mesh.quads.empty()\|\|F.cols()!=3\|\|mesh.vertexProvenance.size()!=mesh.vertices.size()) return false; std::map<int,int> row; for(int i=0;i<(int)mesh.vertices.size();++i) row[mesh.vertices[i]]=i; std::set<std::set<int>> pairs;` |
| `src/geometry/PureQuadCompletion.cpp:3957` | production | producer/mutation-or-mixed | `vertexProvenance` | — | `for(const auto&q:mesh.quads){ std::set<int> sv; for(int v:q){auto it=row.find(v); if(it==row.end())return false; int x=source_vertex_from_point(mesh.vertexProvenance[it->second],F); if(x<0)return false; sv.insert(x);} if(sv.size()!=4\|\|!pairs.count(sv))return false;} return true; }` |
| `src/geometry/SurfaceArrangement.cpp:1020` | production | consumer/read | `sourceCharts` | — | `bytes += vector_storage_bytes(cell.sourceCharts);` |
| `src/geometry/SurfaceArrangement.cpp:1572` | production | consumer/read | `sourceCharts` | — | `!std::is_sorted(cell.sourceCharts.begin(), cell.sourceCharts.end())) {` |
| `src/geometry/SurfaceArrangement.cpp:1575` | production | consumer/read | `sourceCharts` | — | `for (const SourceProjectionChart &chart : cell.sourceCharts) {` |
| `src/geometry/SurfaceArrangement.cpp:1597` | production | consumer/read | `sourceCharts` | — | `record.exactCharts = cell.sourceCharts;` |
| `src/geometry/SurfaceArrangement.cpp:1647` | production | consumer/read | `sourceCharts` | — | `cell.sourceCharts.erase(` |
| `src/geometry/SurfaceArrangement.cpp:1648` | production | consumer/read | `sourceCharts` | — | `std::remove_if(cell.sourceCharts.begin(), cell.sourceCharts.end(),` |
| `src/geometry/SurfaceArrangement.cpp:1654` | production | consumer/read | `sourceCharts` | — | `cell.sourceCharts.end());` |
| `src/geometry/SurfaceArrangement.cpp:7191` | production | consumer/read | `sourcePoint` | — | `SurfacePoint sourcePoint;` |
| `src/geometry/SurfaceArrangement.cpp:7192` | production | consumer/read | `sourcePoint` | — | `sourcePoint.face = sourceFace;` |
| `src/geometry/SurfaceArrangement.cpp:7193` | production | consumer/read | `sourcePoint` | — | `sourcePoint.barycentric = sourceBarycentric.transpose();` |
| `src/geometry/SurfaceArrangement.cpp:7195` | production | consumer/read | `sourcePoint` | — | `if (!transitionGraph.rebind(sourcePoint, edge.sourceFace, rebound)) {` |
| `src/geometry/SurfaceArrangement.cpp:7243` | production | producer/mutation-or-mixed | `sourceCharts` | — | `cell.sourceCharts.clear();` |
| `src/geometry/SurfaceArrangement.cpp:7257` | production | producer/mutation-or-mixed | `sourceCharts` | — | `cell.sourceCharts.push_back(selected.chart.value());` |
| `src/geometry/SurfaceArrangement.cpp:7259` | production | consumer/read | `sourceCharts` | — | `std::sort(cell.sourceCharts.begin(), cell.sourceCharts.end());` |
| `src/geometry/SurfaceArrangement.cpp:7260` | production | consumer/read | `sourceCharts` | — | `cell.sourceCharts.erase(` |
| `src/geometry/SurfaceArrangement.cpp:7261` | production | consumer/read | `sourceCharts` | — | `std::unique(cell.sourceCharts.begin(), cell.sourceCharts.end()),` |
| `src/geometry/SurfaceArrangement.cpp:7262` | production | consumer/read | `sourceCharts` | — | `cell.sourceCharts.end());` |
| `src/geometry/SurfaceArrangement.cpp:7263` | production | consumer/read | `sourceCharts` | — | `if (cell.sourceCharts.empty() \|\| selectedCharts.empty() \|\|` |
| `src/geometry/SurfaceArrangement.cpp:7735` | production | consumer/read | `sourceCharts` | — | `for (const SourceProjectionChart &chart : cell.sourceCharts) {` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:38` | production | consumer/read | `sourceCharts` | — | `std::vector<SourceProjectionChart> sourceCharts;` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:71` | production | producer/mutation-or-mixed | `sourceCharts` | — | `identity.sourceCharts.push_back(chart);` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:188` | production | consumer/read | `sourceCharts` | — | `static_cast<std::int64_t>(cell.sourceCharts.size()));` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:189` | production | consumer/read | `sourceCharts` | — | `for (const SourceProjectionChart &chart : cell.sourceCharts) {` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:269` | production | consumer/read | `sourceCharts` | — | `mix(static_cast<std::uint64_t>(identity.sourceCharts.size()));` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:1020` | production | consumer/read | `sourceCharts` | — | `if (!cell.sourceTopologyRegion.has_value() \|\| cell.sourceCharts.empty() \|\|` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:1021` | production | consumer/read | `sourceCharts` | — | `!std::is_sorted(cell.sourceCharts.begin(), cell.sourceCharts.end())) {` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:1039` | production | consumer/read | `sourceCharts` | — | `!std::binary_search(cell.sourceCharts.begin(), cell.sourceCharts.end(),` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:1378` | production | consumer/read | `sourceCharts` | — | `static_cast<std::uint64_t>(cell.sourceCharts.capacity()) *` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:1430` | production | consumer/read | `sourceCharts` | — | `if (!cell.sourceTopologyRegion.has_value() \|\| cell.sourceCharts.empty()) {` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:1440` | production | consumer/read | `sourceCharts` | — | `!std::binary_search(cell.sourceCharts.begin(), cell.sourceCharts.end(),` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:1582` | production | consumer/read | `sourceCharts` | — | `std::binary_search(cell.sourceCharts.begin(),` |
| `src/geometry/SurfaceCellFeasibilityRepair.cpp:1583` | production | consumer/read | `sourceCharts` | — | `cell.sourceCharts.end(), scope.chart.value())) {` |
| `src/geometry/SurfaceCellTracing.cpp:4539` | production | consumer/read | `sourceTopologyRegions` | — | `field_aligned_hash_consume(hash, edge.sourceTopologyRegions.size());` |
| `src/geometry/SurfaceCellTracing.cpp:4540` | production | consumer/read | `sourceTopologyRegions` | — | `for (const authority::TopologyRegionId region : edge.sourceTopologyRegions) {` |
| `src/geometry/SurfaceCellTracing.cpp:7969` | production | consumer/read | `sourceTopologyRegions` | — | `int gridU, int gridV, SourceTopologyRegions sourceTopologyRegions,` |
| `src/geometry/SurfaceCellTracing.cpp:7979` | production | consumer/read | `sourceTopologyRegions` | — | `if (sourceTopologyRegions.regions().empty() \|\|` |
| `src/geometry/SurfaceCellTracing.cpp:7980` | production | consumer/read | `sourceTopologyRegions` | — | `sourceTopologyRegions.face_count() == 0U) {` |
| `src/geometry/SurfaceCellTracing.cpp:8000` | production | consumer/read | `sourceTopologyRegions` | — | `if (find_region(sourceTopologyRegions, cell.sourceTopologyRegion) == nullptr) {` |
| `src/geometry/SurfaceCellTracing.cpp:8029` | production | consumer/read | `sourceTopologyRegions` | — | `if (find_region(sourceTopologyRegions, relation.sourceTopologyRegion()) == nullptr) {` |
| `src/geometry/SurfaceCellTracing.cpp:8058` | production | consumer/read | `sourceTopologyRegions` | — | `if (face.index() >= sourceTopologyRegions.face_count()) return false;` |
| `src/geometry/SurfaceCellTracing.cpp:8059` | production | consumer/read | `sourceTopologyRegions` | — | `const auto &vertices = sourceTopologyRegions.topology_for_row(face).vertices();` |
| `src/geometry/SurfaceCellTracing.cpp:8073` | production | consumer/read | `sourceTopologyRegions` | — | `branchAuthority.localFace.index() >= sourceTopologyRegions.face_count() \|\|` |
| `src/geometry/SurfaceCellTracing.cpp:8075` | production | consumer/read | `sourceTopologyRegions` | — | `sourceTopologyRegions.face_count() \|\|` |
| `src/geometry/SurfaceCellTracing.cpp:8076` | production | consumer/read | `sourceTopologyRegions` | — | `sourceTopologyRegions.region_for_row(branchAuthority.localFace) !=` |
| `src/geometry/SurfaceCellTracing.cpp:8078` | production | consumer/read | `sourceTopologyRegions` | — | `sourceTopologyRegions.region_for_row(` |
| `src/geometry/SurfaceCellTracing.cpp:8096` | production | consumer/read | `sourceTopologyRegions` | — | `find_region(sourceTopologyRegions, edge.sourceTopologyRegion) == nullptr) {` |
| `src/geometry/SurfaceCellTracing.cpp:8355` | production | consumer/read | `sourceTopologyRegions` | — | `for (const SurfaceTopologyRegion &region : sourceTopologyRegions.regions()) {` |
| `src/geometry/SurfaceCellTracing.cpp:8367` | production | consumer/read | `sourceTopologyRegions` | — | `if (find_region(sourceTopologyRegions, phase.sourceTopologyRegion) == nullptr) {` |
| `src/geometry/SurfaceCellTracing.cpp:8380` | production | consumer/read | `sourceTopologyRegions` | — | `gridU, gridV, std::move(sourceTopologyRegions),` |
| `src/geometry/SurfaceCellTracing.cpp:9194` | production | consumer/read | `sourcePoint` | — | `std::vector<SurfaceTracePoint> sourcePoints;` |
| `src/geometry/SurfaceCellTracing.cpp:9195` | production | producer/mutation-or-mixed | `sourcePoint` | — | `sourcePoints.reserve(seeds.size());` |
| `src/geometry/SurfaceCellTracing.cpp:9198` | production | producer/mutation-or-mixed | `sourcePoint` | — | `sourcePoints.push_back(seed.point);` |
| `src/geometry/SurfaceCellTracing.cpp:9202` | production | consumer/read | `sourcePoint` | — | `intrinsicGraph, vertices, faces, sourcePoints);` |
| `src/geometry/SurfaceCellTracing.cpp:11876` | production | consumer/read | `sourceTopologyRegions` | — | `std::optional<SourceTopologyRegions> sourceTopologyRegions;` |
| `src/geometry/SurfaceCellTracing.cpp:11913` | production | consumer/read | `sourceTopologyRegions` | — | `if (!state.sourceTopologyRegions.has_value()) {` |
| `src/geometry/SurfaceCellTracing.cpp:11918` | production | consumer/read | `sourceTopologyRegions` | — | `state.gridU, state.gridV, std::move(*state.sourceTopologyRegions),` |
| `src/geometry/SurfaceCellTracing.cpp:12458` | production | consumer/read | `sourceCharts` | — | `const SourceChartTransitionGraph &sourceCharts,` |
| `src/geometry/SurfaceCellTracing.cpp:12558` | production | consumer/read | `sourceCharts` | — | `const auto canonicalChart = sourceCharts.chart(segment.face);` |
| `src/geometry/SurfaceCellTracing.cpp:12583` | production | consumer/read | `sourceCharts` | — | `const SourceChartTransitionGraph &sourceCharts,` |
| `src/geometry/SurfaceCellTracing.cpp:12685` | production | consumer/read | `sourceCharts` | — | `const auto canonicalChart = sourceCharts.chart(segment.face);` |
| `src/geometry/SurfaceCellTracing.cpp:16845` | production | producer/write-or-init | `sourceTopologyRegions` | — | `result.sourceTopologyRegions = sourceAuthority;` |
| `src/geometry/SurfaceCellTracing.cpp:16853` | production | producer/mutation-or-mixed | `sourceTopologyRegions` | — | `regions.reserve(result.sourceTopologyRegions->regions().size());` |
| `src/geometry/SurfaceCellTracing.cpp:16854` | production | consumer/read | `sourceTopologyRegions` | — | `for (const SurfaceTopologyRegion &region : result.sourceTopologyRegions->regions()) {` |
| `src/geometry/SurfaceCellTracing.cpp:16860` | production | consumer/read | `sourceTopologyRegions` | — | `const auto faceId = result.sourceTopologyRegions->row_for_topology(member.topology);` |
| `src/geometry/SurfaceCellTracing.cpp:16938` | production | consumer/read | `sourceTopologyRegions` | — | `region, *result.sourceTopologyRegions, options, sourceEdgeFaces, sourceMatchingIndices, edgeMatching,` |
| `src/geometry/SurfaceCellTracing.cpp:16943` | production | consumer/read | `sourceTopologyRegions` | — | `region, *result.sourceTopologyRegions, options, sourceEdgeFaces, sourceMatchingIndices, edgeMatching,` |
| `src/geometry/SurfaceCellTracing.cpp:16949` | production | consumer/read | `sourceTopologyRegions` | — | `region, *result.sourceTopologyRegions, options, sourceEdgeFaces, sourceMatchingIndices, edgeMatching,` |
| `src/geometry/SurfaceCellTracing.cpp:17022` | production | consumer/read | `sourceTopologyRegions` | — | `const auto row = result.sourceTopologyRegions->row_for_topology(` |
| `src/geometry/SurfaceCellTracing.cpp:17179` | production | consumer/read | `sourceTopologyRegions` | — | `if (coveredRegions.size() != result.sourceTopologyRegions->regions().size()) {` |
| `src/geometry/SurfaceCellTracing.cpp:17210` | production | consumer/read | `sourceTopologyRegions` | — | `if (!result.sourceTopologyRegions.has_value() \|\|` |
| `src/geometry/SurfaceCellTracing.cpp:17211` | production | consumer/read | `sourceTopologyRegions` | — | `id.index() >= result.sourceTopologyRegions->regions().size()) {` |
| `src/geometry/SurfaceCellTracing.cpp:17214` | production | consumer/read | `sourceTopologyRegions` | — | `return &result.sourceTopologyRegions->region(id);` |
| `src/geometry/SurfaceCellTracing.cpp:17566` | production | consumer/read | `sourceTopologyRegions` | — | `!result.sourceTopologyRegions.has_value()) {` |
| `src/geometry/SurfaceCellTracing.cpp:17571` | production | consumer/read | `sourceTopologyRegions` | — | `result.sourceTopologyRegions->region_for_row(*localFace) !=` |
| `src/geometry/SurfaceCellTracing.cpp:17573` | production | consumer/read | `sourceTopologyRegions` | — | `result.sourceTopologyRegions->region_for_row(*occurrenceFace) !=` |
| `src/geometry/SurfaceCellTracing.cpp:17742` | production | consumer/read | `sourceTopologyRegions` | — | `vertices, faces, faceAxisX, faceAxisY, *result.sourceTopologyRegions,` |
| `src/geometry/SurfaceCellTracing.cpp:17872` | production | producer/write-or-init | `sourceTopologyRegions` | — | `network.sourceTopologyRegions = *options.sourceAuthority;` |
| `src/geometry/SurfaceCellTracing.cpp:17874` | production | producer/write-or-init | `sourceTopologyRegions` | — | `network.sourceTopologyRegions =` |
| `src/geometry/SurfaceCellTracing.cpp:17878` | production | consumer/read | `sourceTopologyRegions` | — | `if (!network.sourceTopologyRegions.has_value()) {` |
| `src/geometry/SurfaceCellTracing.cpp:17886` | production | consumer/read | `sourceTopologyRegions` | — | `faces, *network.sourceTopologyRegions,` |
| `src/geometry/SurfaceCellTracing.cpp:17896` | production | consumer/read | `sourceTopologyRegions` | — | `authoritativeOptions.sourceAuthority = &*network.sourceTopologyRegions;` |
| `src/geometry/SurfaceCellTracing.cpp:17900` | production | consumer/read | `sourceTopologyRegions` | — | `*network.sourceTopologyRegions, authoritativeOptions,` |
| `src/geometry/SurfaceComplexSimplification.cpp:187` | production | consumer/read | `sourceCharts` | — | `for (const SourceProjectionChart &chart : cell.sourceCharts) {` |
| `src/geometry/SurfaceComplexSimplification.cpp:1123` | production | producer/mutation-or-mixed | `sourceCharts` | — | `mergedCharts.insert(cell.sourceCharts.begin(), cell.sourceCharts.end());` |
| `src/geometry/SurfaceComplexSimplification.cpp:1130` | production | consumer/read | `sourceCharts` | — | `mergedCell.sourceCharts.assign(mergedCharts.begin(), mergedCharts.end());` |
| `src/geometry/SurfaceMeshOptimizer.cpp:783` | production | consumer/read | `vertexProvenance` | — | `i < static_cast<int>(constraints.vertexProvenance.size())` |
| `src/geometry/SurfaceMeshOptimizer.cpp:784` | production | consumer/read | `vertexProvenance` | — | `? constraints.vertexProvenance[static_cast<std::size_t>(i)]` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1453` | production | producer/write-or-init | `sourcePoint` | — | `const SurfacePoint &sourcePoint = provenance[static_cast<std::size_t>(i)];` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1454` | production | consumer/read | `sourcePoint` | — | `if (!provenance_is_complete(sourcePoint, constraints)) {` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1459` | production | consumer/read | `sourcePoint` | — | `(p - sourcePoint.position.transpose()).squaredNorm();` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1744` | production | consumer/read | `vertexProvenance` | — | `const std::vector<SurfacePoint> *vertexProvenance,` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1747` | production | consumer/read | `vertexProvenance` | — | `vertexProvenance != nullptr` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1748` | production | consumer/read | `vertexProvenance` | — | `? vertexProvenance` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1749` | production | consumer/read | `vertexProvenance` | — | `: (constraints != nullptr ? &constraints->vertexProvenance : nullptr);` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1783` | production | producer/write-or-init | `vertexProvenance` | — | `validatorOptions.vertexProvenance = &provenance;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1881` | production | producer/write-or-init | `sourcePoint` | — | `const SurfacePoint &sourcePoint =` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1883` | production | consumer/read | `sourcePoint` | — | `if (!provenance_is_complete(sourcePoint, constraints)) {` |
| `src/geometry/SurfaceMeshOptimizer.cpp:1888` | production | consumer/read | `sourcePoint` | — | `2.0 * (point - sourcePoint.position.transpose());` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2289` | production | producer/write-or-init | `vertexProvenance` | — | `result.vertexProvenance = constraints.vertexProvenance;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2305` | production | consumer/read | `vertexProvenance` | — | `&result.vertexProvenance, &projectionCache);` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2308` | production | consumer/read | `vertexProvenance` | — | `std::all_of(result.vertexProvenance.begin(), result.vertexProvenance.end(),` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2407` | production | consumer/read | `vertexProvenance` | — | `nullptr, nullptr, &result.vertexProvenance,` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2452` | production | producer/write-or-init | `vertexProvenance` | — | `rejected.vertexProvenance = constraints.vertexProvenance;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2501` | production | consumer/read | `vertexProvenance` | — | `const std::vector<SurfacePoint> &provenance = optimization.vertexProvenance;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2539` | production | producer/write-or-init | `sourcePoint` | — | `const SurfacePoint sourcePoint =` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2544` | production | consumer/read | `sourcePoint` | — | `if (!sourcePoint.valid()) {` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2550` | production | consumer/read | `sourcePoint` | — | `constraints, sourcePoint, 0, options.targetSize);` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2552` | production | consumer/read | `sourcePoint` | — | `std::sqrt(sourcePoint.squaredDistance) /` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2575` | production | consumer/read | `sourcePoint` | — | `SurfacePoint sourcePoint;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2576` | production | consumer/read | `sourcePoint` | — | `sourcePoint.face = face;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2577` | production | consumer/read | `sourcePoint` | — | `sourcePoint.barycentric = barycentric;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2578` | production | consumer/read | `sourcePoint` | — | `sourcePoint.position = source_point_position(` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2580` | production | consumer/read | `sourcePoint` | — | `constraints.sourceFaces, sourcePoint)` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2582` | production | consumer/read | `sourcePoint` | — | `sourcePoint.squaredDistance = 0.0;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2584` | production | consumer/read | `sourcePoint` | — | `sourcePoint.position.transpose(), sourceScope);` |
| `src/geometry/SurfaceMeshOptimizer.cpp:2591` | production | consumer/read | `sourcePoint` | — | `constraints, sourcePoint, 0, options.targetSize);` |
| `src/geometry/SurfaceMeshOptimizer.cpp:3012` | production | consumer/read | `sourcePoint` | — | `SurfacePoint sourcePoint;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:3020` | production | consumer/read | `sourcePoint` | — | `sourcePoint.face = face;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:3021` | production | consumer/read | `sourcePoint` | — | `sourcePoint.barycentric.setZero();` |
| `src/geometry/SurfaceMeshOptimizer.cpp:3022` | production | consumer/read | `sourcePoint` | — | `sourcePoint.barycentric(corner) = 1.0;` |
| `src/geometry/SurfaceMeshOptimizer.cpp:3023` | production | consumer/read | `sourcePoint` | — | `sourcePoint.position = position.transpose();` |
| `src/geometry/SurfaceMeshOptimizer.cpp:3027` | production | consumer/read | `sourcePoint` | — | `if (sourcePoint.valid()) {` |
| `src/geometry/SurfaceMeshOptimizer.cpp:3035` | production | consumer/read | `sourcePoint` | — | `const double target = sourcePoint.valid()` |
| `src/geometry/SurfaceMeshOptimizer.cpp:3036` | production | consumer/read | `sourcePoint` | — | `? local_target_size(constraints, sourcePoint,` |
| `src/pipeline/RemeshPipeline.cpp:1110` | production | consumer/read | `sourceTopologyRegions` | — | `static_cast<std::uint64_t>(phaseFront->sourceTopologyRegions().face_count()) *` |
| `src/pipeline/RemeshPipeline.cpp:1114` | production | consumer/read | `sourceTopologyRegions` | — | `vector_owned_bytes(phaseFront->sourceTopologyRegions().regions());` |
| `src/pipeline/RemeshPipeline.cpp:1124` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront->sourceTopologyRegions().regions()) {` |
| `src/pipeline/RemeshPipeline.cpp:1164` | production | consumer/read | `sourceTopologyRegions` | — | `static_cast<std::uint64_t>(phaseFront->sourceTopologyRegions().face_count()) *` |
| `src/pipeline/RemeshPipeline.cpp:1168` | production | consumer/read | `sourceTopologyRegions` | — | `vector_logical_bytes(phaseFront->sourceTopologyRegions().regions());` |
| `src/pipeline/RemeshPipeline.cpp:1178` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront->sourceTopologyRegions().regions()) {` |
| `src/pipeline/RemeshPipeline.cpp:2066` | production | consumer/read | `sourceTopologyRegions` | — | `hash_combine_u64(seed, phaseFront->sourceTopologyRegions().regions().size());` |
| `src/pipeline/RemeshPipeline.cpp:2067` | production | consumer/read | `sourceTopologyRegions` | — | `for (const auto &region : phaseFront->sourceTopologyRegions().regions()) {` |
| `src/pipeline/RemeshPipeline.cpp:2581` | production | consumer/read | `sourceCharts` | — | `hash_combine_u64(seed, cell.sourceCharts.size());` |
| `src/pipeline/RemeshPipeline.cpp:2582` | production | consumer/read | `sourceCharts` | — | `for (const auto &chart : cell.sourceCharts) {` |
| `src/pipeline/RemeshPipeline.cpp:2648` | production | consumer/read | `hash_completion` | — | `std::uint64_t hash_completion_mesh(` |
| `src/pipeline/RemeshPipeline.cpp:2664` | production | consumer/read | `hash_completion` | — | `std::uint64_t hash_completion(const geometry::PureQuadMesh &mesh) {` |
| `src/pipeline/RemeshPipeline.cpp:2670` | production | consumer/read | `sourceSupport` | — | `hash_combine_i64(seed, mesh.domainIdentity.sourceSupportCount);` |
| `src/pipeline/RemeshPipeline.cpp:2677` | production | consumer/read | `vertexPositions` | — | `hash_matrix(seed, mesh.vertexPositions);` |
| `src/pipeline/RemeshPipeline.cpp:2682` | production | consumer/read | `vertexProvenance` | — | `for (const geometry::SurfacePoint &point : mesh.vertexProvenance) {` |
| `src/pipeline/RemeshPipeline.cpp:2695` | production | consumer/read | `sourceTopologyRegions` | — | `hash_vector(seed, lineage.sourceTopologyRegions);` |
| `src/pipeline/RemeshPipeline.cpp:2696` | production | consumer/read | `sourceIsolationSheets` | — | `hash_vector(seed, lineage.sourceIsolationSheets);` |
| `src/pipeline/RemeshPipeline.cpp:2697` | production | consumer/read | `sourceSupport` | — | `hash_source_support(seed, lineage.sourceSupport);` |
| `src/pipeline/RemeshPipeline.cpp:2698` | production | consumer/read | `quotientClass` | — | `hash_combine_i64(seed, lineage.quotientClass.has_value() ? 1 : 0);` |
| `src/pipeline/RemeshPipeline.cpp:2699` | production | consumer/read | `quotientClass` | — | `if (lineage.quotientClass.has_value()) {` |
| `src/pipeline/RemeshPipeline.cpp:2700` | production | consumer/read | `quotientClass` | — | `hash_semantic_id(seed, lineage.quotientClass.value());` |
| `src/pipeline/RemeshPipeline.cpp:2703` | production | consumer/read | `sourceCharts` | — | `hash_combine_u64(seed, lineage.sourceCharts.size());` |
| `src/pipeline/RemeshPipeline.cpp:2704` | production | consumer/read | `sourceCharts` | — | `for (const auto &chart : lineage.sourceCharts) {` |
| `src/pipeline/RemeshPipeline.cpp:2708` | production | consumer/read | `equivalences` | — | `hash_combine_u64(seed, lineage.equivalences.size());` |
| `src/pipeline/RemeshPipeline.cpp:2709` | production | consumer/read | `equivalences` | — | `for (const auto &equivalence : lineage.equivalences) {` |
| `src/pipeline/RemeshPipeline.cpp:2730` | production | consumer/read | `selectedRelationPaths` | — | `hash_combine_u64(seed, lineage.selectedRelationPaths.size());` |
| `src/pipeline/RemeshPipeline.cpp:2731` | production | consumer/read | `selectedRelationPaths` | — | `for (const auto &certificate : lineage.selectedRelationPaths) {` |
| `src/pipeline/RemeshPipeline.cpp:2732` | production | consumer/read | `sourceSupport` | — | `hash_source_support(seed, certificate.sourceSupport);` |
| `src/pipeline/RemeshPipeline.cpp:3317` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().face_count() !=` |
| `src/pipeline/RemeshPipeline.cpp:3333` | production | consumer/read | `sourceTopologyRegions` | — | `sourceFaces, phaseFront.sourceTopologyRegions(), hardFeatureEdges);` |
| `src/pipeline/RemeshPipeline.cpp:3361` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().regions()) {` |
| `src/pipeline/RemeshPipeline.cpp:3440` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().region_for_row(*faceId) != region) {` |
| `src/pipeline/RemeshPipeline.cpp:3444` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().topology_for_row(*faceId),` |
| `src/pipeline/RemeshPipeline.cpp:3445` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().sheet_for_row(*faceId),` |
| `src/pipeline/RemeshPipeline.cpp:3689` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().row_for_topology(` |
| `src/pipeline/RemeshPipeline.cpp:3737` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().row_for_topology(` |
| `src/pipeline/RemeshPipeline.cpp:3815` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().topology_for_row(*selectedFaceId);` |
| `src/pipeline/RemeshPipeline.cpp:3882` | production | consumer/read | `sourceTopologyRegions` | — | `const auto row = phaseFront.sourceTopologyRegions().row_for_topology(` |
| `src/pipeline/RemeshPipeline.cpp:4974` | production | producer/mutation-or-mixed | `equivalences` | — | `quotient.equivalences.push_back(std::move(equivalence));` |
| `src/pipeline/RemeshPipeline.cpp:4981` | production | producer/mutation-or-mixed | `equivalences` | — | `quotient.equivalences.push_back(certificate.evidence);` |
| `src/pipeline/RemeshPipeline.cpp:4984` | production | consumer/read | `equivalences` | — | `std::sort(quotient.equivalences.begin(), quotient.equivalences.end());` |
| `src/pipeline/RemeshPipeline.cpp:4985` | production | consumer/read | `equivalences` | — | `quotient.equivalences.erase(` |
| `src/pipeline/RemeshPipeline.cpp:4986` | production | consumer/read | `equivalences` | — | `std::unique(quotient.equivalences.begin(), quotient.equivalences.end()),` |
| `src/pipeline/RemeshPipeline.cpp:4987` | production | consumer/read | `equivalences` | — | `quotient.equivalences.end());` |
| `src/pipeline/RemeshPipeline.cpp:5009` | production | producer/write-or-init | `sourceSupport` | — | `legacy.sourceSupport = occurrenceById.at(root)->support;` |
| `src/pipeline/RemeshPipeline.cpp:5408` | production | consumer/read | `quotientClass` | — | `if (published.quotientClass.members.empty() \|\|` |
| `src/pipeline/RemeshPipeline.cpp:5409` | production | consumer/read | `quotientClass` | — | `published.root != published.quotientClass.members.front() \|\|` |
| `src/pipeline/RemeshPipeline.cpp:5411` | production | consumer/read | `quotientClass` | — | `!std::binary_search(published.quotientClass.members.begin(),` |
| `src/pipeline/RemeshPipeline.cpp:5412` | production | consumer/read | `quotientClass` | — | `published.quotientClass.members.end(),` |
| `src/pipeline/RemeshPipeline.cpp:5417` | production | producer/mutation-or-mixed | `quotientClass` | — | `.insert({published.quotientClass, published.target})` |
| `src/pipeline/RemeshPipeline.cpp:5558` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().face_count() !=` |
| `src/pipeline/RemeshPipeline.cpp:5578` | production | consumer/read | `sourceTopologyRegions` | — | `sourceFaces, phaseFront.sourceTopologyRegions(), hardFeatureEdges);` |
| `src/pipeline/RemeshPipeline.cpp:5609` | production | consumer/read | `sourceTopologyRegions` | — | `if (phaseFront.sourceTopologyRegions().face_count() !=` |
| `src/pipeline/RemeshPipeline.cpp:5615` | production | consumer/read | `sourceTopologyRegions` | — | `for (const auto &region : phaseFront.sourceTopologyRegions().regions()) {` |
| `src/pipeline/RemeshPipeline.cpp:5623` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().row_for_topology(member.topology);` |
| `src/pipeline/RemeshPipeline.cpp:5631` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().region_for_row(*faceId) !=` |
| `src/pipeline/RemeshPipeline.cpp:5756` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().region_for_row(*source_face_id(firstFace)) !=` |
| `src/pipeline/RemeshPipeline.cpp:5758` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().region_for_row(*source_face_id(secondFace)) !=` |
| `src/pipeline/RemeshPipeline.cpp:5760` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().component_for_row(*source_face_id(firstFace)) !=` |
| `src/pipeline/RemeshPipeline.cpp:5762` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().component_for_row(*source_face_id(secondFace)) !=` |
| `src/pipeline/RemeshPipeline.cpp:5764` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().sheet_for_row(*source_face_id(firstFace)) !=` |
| `src/pipeline/RemeshPipeline.cpp:5766` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFront.sourceTopologyRegions().sheet_for_row(*source_face_id(secondFace)) !=` |
| `src/pipeline/RemeshPipeline.cpp:6088` | production | consumer/read | `quotientClass` | — | `selectedPathsByClass.emplace(path.quotientClass, &path);` |
| `src/pipeline/RemeshPipeline.cpp:6091` | production | producer/mutation-or-mixed | `vertexPositions` | — | `result.mesh.vertexPositions.resize(` |
| `src/pipeline/RemeshPipeline.cpp:6150` | production | consumer/read | `vertexPositions` | — | `result.mesh.vertexPositions.row(outputVertex) =` |
| `src/pipeline/RemeshPipeline.cpp:6152` | production | producer/mutation-or-mixed | `vertexProvenance` | — | `result.mesh.vertexProvenance.push_back(representativeOccurrence.point);` |
| `src/pipeline/RemeshPipeline.cpp:6156` | production | producer/write-or-init | `sourcePoint` | — | `lineage.sourcePoint = representativeOccurrence.point;` |
| `src/pipeline/RemeshPipeline.cpp:6159` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.assign(topologyRegions.begin(),` |
| `src/pipeline/RemeshPipeline.cpp:6161` | production | consumer/read | `sourceCharts` | — | `lineage.sourceCharts.assign(charts.begin(), charts.end());` |
| `src/pipeline/RemeshPipeline.cpp:6162` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.assign(isolationSheets.begin(),` |
| `src/pipeline/RemeshPipeline.cpp:6164` | production | producer/write-or-init | `sourceSupport` | — | `lineage.sourceSupport = representativeOccurrence.support;` |
| `src/pipeline/RemeshPipeline.cpp:6171` | production | producer/write-or-init | `quotientClass` | — | `lineage.quotientClass = compatibilityId.value();` |
| `src/pipeline/RemeshPipeline.cpp:6173` | production | producer/write-or-init | `equivalences` | — | `lineage.equivalences = quotient.equivalences;` |
| `src/pipeline/RemeshPipeline.cpp:6174` | production | producer/write-or-init | `selectedRelationPaths` | — | `lineage.selectedRelationPaths = std::move(selectedPaths);` |
| `src/pipeline/RemeshPipeline.cpp:6228` | production | consumer/read | `vertexPositions` | — | `result.mesh.vertexPositions.row(pending.vertices.back());` |
| `src/pipeline/RemeshPipeline.cpp:7029` | production | producer/write-or-init | `sourceCharts` | — | `authority.sourceCharts = lineage.sourceCharts;` |
| `src/pipeline/RemeshPipeline.cpp:7030` | production | consumer/read | `sourceCharts` | — | `std::sort(authority.sourceCharts.begin(), authority.sourceCharts.end());` |
| `src/pipeline/RemeshPipeline.cpp:7031` | production | consumer/read | `sourceCharts` | — | `authority.sourceCharts.erase(` |
| `src/pipeline/RemeshPipeline.cpp:7032` | production | consumer/read | `sourceCharts` | — | `std::unique(authority.sourceCharts.begin(), authority.sourceCharts.end()),` |
| `src/pipeline/RemeshPipeline.cpp:7033` | production | consumer/read | `sourceCharts` | — | `authority.sourceCharts.end());` |
| `src/pipeline/RemeshPipeline.cpp:7034` | production | consumer/read | `sourceCharts` | — | `if (authority.sourceCharts.empty()) {` |
| `src/pipeline/RemeshPipeline.cpp:7039` | production | consumer/read | `equivalences` | — | `lineage.equivalences) {` |
| `src/pipeline/RemeshPipeline.cpp:7065` | production | consumer/read | `sourceCharts` | — | `return !authority.retained \|\| authority.sourceCharts.empty();` |
| `src/pipeline/RemeshPipeline.cpp:7107` | production | consumer/read | `equivalences` | — | `lineage.equivalences) {` |
| `src/pipeline/RemeshPipeline.cpp:7242` | production | consumer/read | `quotientClass` | — | `return lineage.quotientClass.has_value() &&` |
| `src/pipeline/RemeshPipeline.cpp:8727` | production | producer/mutation-or-mixed | `vertexProvenance` | — | `result.mesh.vertexProvenance.push_back(point);` |
| `src/pipeline/RemeshPipeline.cpp:8731` | production | producer/write-or-init | `sourcePoint` | — | `lineage.sourcePoint = point;` |
| `src/pipeline/RemeshPipeline.cpp:9011` | production | producer/mutation-or-mixed | `vertexPositions` | — | `result.mesh.vertexPositions.resize(static_cast<int>(outputPositions.size()),` |
| `src/pipeline/RemeshPipeline.cpp:9018` | production | consumer/read | `vertexPositions` | — | `result.mesh.vertexPositions.row(outputVertex) =` |
| `src/pipeline/RemeshPipeline.cpp:9220` | production | consumer/read | `sourceTopologyRegions` | — | `std::optional<geometry::SourceTopologyRegions> sourceTopologyRegionsProduct;` |
| `src/pipeline/RemeshPipeline.cpp:9753` | production | consumer/read | `sourceTopologyRegions` | — | `sourceTopologyRegionsProduct =` |
| `src/pipeline/RemeshPipeline.cpp:9756` | production | consumer/read | `sourceTopologyRegions` | — | `if (!sourceTopologyRegionsProduct.has_value() \|\|` |
| `src/pipeline/RemeshPipeline.cpp:9757` | production | consumer/read | `sourceTopologyRegions` | — | `!sourceTopologyRegionsProduct->matches_source_faces(` |
| `src/pipeline/RemeshPipeline.cpp:9763` | production | producer/write-or-init | `sourceTopologyRegions` | — | `result.surfaceCellContext.productSnapshots.sourceTopologyRegions =` |
| `src/pipeline/RemeshPipeline.cpp:9764` | production | consumer/read | `sourceTopologyRegions` | — | `sourceTopologyRegionsProduct;` |
| `src/pipeline/RemeshPipeline.cpp:9765` | production | consumer/read | `sourceTopologyRegions` | — | `tracingOptions.sourceAuthority = &*sourceTopologyRegionsProduct;` |
| `src/pipeline/RemeshPipeline.cpp:9814` | production | consumer/read | `sourceTopologyRegions` | — | `meshWhole, *sourceTopologyRegionsProduct, hardFeatureRailEdges,` |
| `src/pipeline/RemeshPipeline.cpp:9907` | production | consumer/read | `sourceTopologyRegions` | — | `*sourceTopologyRegionsProduct, *fieldTransportAtlasProduct,` |
| `src/pipeline/RemeshPipeline.cpp:9924` | production | consumer/read | `sourceTopologyRegions` | — | `*sourceTopologyRegionsProduct, *fieldTransportAtlasProduct,` |
| `src/pipeline/RemeshPipeline.cpp:9946` | production | consumer/read | `sourceTopologyRegions` | — | `*sourceTopologyRegionsProduct, *fieldAlignedNetworkProduct,` |
| `src/pipeline/RemeshPipeline.cpp:10066` | production | consumer/read | `sourceTopologyRegions` | — | `if (!sourceTopologyRegionsProduct.has_value() \|\|` |
| `src/pipeline/RemeshPipeline.cpp:10067` | production | consumer/read | `sourceTopologyRegions` | — | `!phaseFrontProduct->sourceTopologyRegions().matches_source_faces(` |
| `src/pipeline/RemeshPipeline.cpp:10071` | production | consumer/read | `sourceTopologyRegions` | — | `meshWhole.F, phaseFrontProduct->sourceTopologyRegions(),` |
| `src/pipeline/RemeshPipeline.cpp:10078` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFrontProduct->sourceTopologyRegions().regions().size();` |
| `src/pipeline/RemeshPipeline.cpp:10084` | production | consumer/read | `sourceTopologyRegions` | — | `for (const auto &region : phaseFrontProduct->sourceTopologyRegions().regions()) {` |
| `src/pipeline/RemeshPipeline.cpp:10117` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFrontProduct->sourceTopologyRegions().regions().begin(),` |
| `src/pipeline/RemeshPipeline.cpp:10118` | production | consumer/read | `sourceTopologyRegions` | — | `phaseFrontProduct->sourceTopologyRegions().regions().end(),` |
| `src/pipeline/RemeshPipeline.cpp:10122` | production | consumer/read | `sourceTopologyRegions` | — | `if (region == phaseFrontProduct->sourceTopologyRegions().regions().end()) {` |
| `src/pipeline/RemeshPipeline.cpp:10141` | production | producer/mutation-or-mixed | `sourceIsolationSheets` | — | `diagnostic.sourceIsolationSheets.reserve(regionSheets.size());` |
| `src/pipeline/RemeshPipeline.cpp:10143` | production | producer/mutation-or-mixed | `sourceIsolationSheets` | — | `diagnostic.sourceIsolationSheets.push_back(` |
| `src/pipeline/RemeshPipeline.cpp:10307` | production | consumer/read | `sourceTopologyRegions` | — | `sourceTopologyRegionsProduct.has_value()` |
| `src/pipeline/RemeshPipeline.cpp:10308` | production | consumer/read | `sourceTopologyRegions` | — | `? &sourceTopologyRegionsProduct.value()` |
| `src/pipeline/RemeshPipeline.cpp:11165` | production | consumer/read | `sourceSupport` | — | `if (ownershipRejection.sourceSupport.has_value()) {` |
| `src/pipeline/RemeshPipeline.cpp:11168` | production | consumer/read | `sourceSupport` | — | `&ownershipRejection.sourceSupport.value())) {` |
| `src/pipeline/RemeshPipeline.cpp:11174` | production | consumer/read | `sourceSupport` | — | `&ownershipRejection.sourceSupport.value())) {` |
| `src/pipeline/RemeshPipeline.cpp:11280` | production | consumer/read | `vertexPositions` | — | `completedVertices = aggregateLineageMesh.vertexPositions;` |
| `src/pipeline/RemeshPipeline.cpp:11281` | production | consumer/read | `vertexProvenance` | — | `completedProvenance = aggregateLineageMesh.vertexProvenance;` |
| `src/pipeline/RemeshPipeline.cpp:11346` | production | consumer/read | `hash_completion` | — | `std::uint64_t completionHash = hash_completion_mesh(` |
| `src/pipeline/RemeshPipeline.cpp:11582` | production | consumer/read | `sourceSupport` | — | `hash_source_support(completionHash, hashRejection.sourceSupport);` |
| `src/pipeline/RemeshPipeline.cpp:11634` | production | consumer/read | `sourceSupport` | — | `if (failure.sourceSupport.has_value()) {` |
| `src/pipeline/RemeshPipeline.cpp:11637` | production | consumer/read | `sourceSupport` | — | `&failure.sourceSupport.value())) {` |
| `src/pipeline/RemeshPipeline.cpp:11747` | production | producer/write-or-init | `vertexProvenance` | — | `constraints.vertexProvenance = completedProvenance;` |
| `src/pipeline/RemeshPipeline.cpp:11831` | production | producer/write-or-init | `vertexProvenance` | — | `completedCheckpoint.vertexProvenance = completedProvenance;` |
| `src/pipeline/RemeshPipeline.cpp:11938` | production | consumer/read | `vertexProvenance` | — | `optimization.vertexProvenance.size();` |
| `src/pipeline/RemeshPipeline.cpp:11990` | production | consumer/read | `vertexProvenance` | — | `result.outputVertexProvenance = optimization.vertexProvenance;` |
| `src/pipeline/RemeshPipeline.cpp:12004` | production | producer/write-or-init | `sourceTopologyRegions` | — | `componentProducts->sourceTopologyRegions = sourceTopologyRegionsProduct;` |
| `src/pipeline/RemeshPipeline.cpp:12928` | production | consumer/read | `sourceTopologyRegions` | — | `if (lineage.sourceTopologyRegions.empty() \|\|` |
| `src/pipeline/RemeshPipeline.cpp:12929` | production | consumer/read | `sourceCharts`, `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.empty() \|\| lineage.sourceCharts.empty() \|\|` |
| `src/pipeline/RemeshPipeline.cpp:12930` | production | consumer/read | `sourceSupport` | — | `!lineage.sourceSupport.has_value() \|\| !domain.complete()) {` |
| `src/pipeline/RemeshPipeline.cpp:12947` | production | producer/mutation-or-mixed | `sourceCharts` | — | `localBindings.reserve(lineage.sourceCharts.size());` |
| `src/pipeline/RemeshPipeline.cpp:12950` | production | consumer/read | `sourceCharts` | — | `for (const geometry::SourceProjectionChart &chart : lineage.sourceCharts) {` |
| `src/pipeline/RemeshPipeline.cpp:12973` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.begin(), lineage.sourceTopologyRegions.end());` |
| `src/pipeline/RemeshPipeline.cpp:12975` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.begin(), lineage.sourceIsolationSheets.end());` |
| `src/pipeline/RemeshPipeline.cpp:13001` | production | consumer/read | `sourceSupport` | — | `const authority::SourceSupport &support = lineage.sourceSupport.value();` |
| `src/pipeline/RemeshPipeline.cpp:13002` | production | consumer/read | `sourceCharts` | — | `for (const geometry::SourceProjectionChart &chart : lineage.sourceCharts) {` |
| `src/pipeline/RemeshPipeline.cpp:13090` | production | consumer/read | `sourceTopologyRegions` | — | `lineage.sourceTopologyRegions.assign(remappedRegions.begin(),` |
| `src/pipeline/RemeshPipeline.cpp:13092` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.assign(remappedSheets.begin(),` |
| `src/pipeline/RemeshPipeline.cpp:13094` | production | consumer/read | `sourceCharts` | — | `lineage.sourceCharts.assign(remappedCharts.begin(), remappedCharts.end());` |
| `src/pipeline/RemeshPipeline.cpp:13098` | production | consumer/read | `sourceSupport` | — | `&lineage.sourceSupport.value())) {` |
| `src/pipeline/RemeshPipeline.cpp:13103` | production | consumer/read | `sourceSupport` | — | `&lineage.sourceSupport.value())) {` |
| `src/pipeline/RemeshPipeline.cpp:13113` | production | consumer/read | `sourceSupport` | — | `&lineage.sourceSupport.value())) {` |
| `src/pipeline/RemeshPipeline.cpp:13119` | production | producer/write-or-init | `sourceSupport` | — | `lineage.sourceSupport = std::move(remappedSupport);` |
| `src/pipeline/RemeshPipeline.cpp:13125` | production | consumer/read | `sourceTopologyRegions` | — | `normalize(lineage.sourceTopologyRegions);` |
| `src/pipeline/RemeshPipeline.cpp:13126` | production | consumer/read | `sourceIsolationSheets` | — | `normalize(lineage.sourceIsolationSheets);` |
| `src/pipeline/RemeshPipeline.cpp:13127` | production | consumer/read | `sourceCharts` | — | `normalize(lineage.sourceCharts);` |
| `src/pipeline/RemeshPipeline.cpp:13128` | production | consumer/read | `sourceTopologyRegions` | — | `return !lineage.sourceTopologyRegions.empty() &&` |
| `src/pipeline/RemeshPipeline.cpp:13129` | production | consumer/read | `sourceIsolationSheets` | — | `!lineage.sourceIsolationSheets.empty() &&` |
| `src/pipeline/RemeshPipeline.cpp:13130` | production | consumer/read | `sourceCharts`, `sourceSupport` | — | `!lineage.sourceCharts.empty() && lineage.sourceSupport.has_value();` |
| `src/pipeline/RemeshPipeline.cpp:14113` | production | consumer/read | `vertexProvenance` | — | `patch.vertexProvenance.size() != patch.vertices.size() \|\|` |
| `src/pipeline/RemeshPipeline.cpp:14149` | production | consumer/read | `sourcePoint`, `vertexProvenance` | — | `patch.vertexProvenance[row] = lineage.sourcePoint;` |
| `src/pipeline/RemeshPipeline.cpp:14402` | production | consumer/read | `sourceTopologyRegions` | — | `!run.stageProducts.sourceTopologyRegions.has_value() \|\|` |
| `src/pipeline/RemeshPipeline.cpp:14403` | production | consumer/read | `sourceTopologyRegions` | — | `!run.stageProducts.sourceTopologyRegions->matches_source_faces(` |
| `src/pipeline/RemeshPipeline.cpp:14419` | production | consumer/read | `sourceTopologyRegions` | — | `&run.stageProducts.sourceTopologyRegions.value();` |
| `src/pipeline/RemeshPipeline.cpp:14423` | production | producer/write-or-init | `vertexProvenance` | — | `constraints.vertexProvenance = componentProduct.outputVertexProvenance;` |
| `src/pipeline/RemeshPipeline.cpp:14450` | production | consumer/read | `vertexPositions` | — | `completed.vertexPositions.rows() == componentProduct.vertices.rows() &&` |
| `src/pipeline/RemeshPipeline.cpp:14769` | production | consumer/read | `quotientClass` | — | `std::size_t quotientClassOffset = 0U;` |
| `src/pipeline/RemeshPipeline.cpp:15084` | production | consumer/read | `sourceTopologyRegions` | — | `if (!componentProducts.sourceTopologyRegions.has_value()) {` |
| `src/pipeline/RemeshPipeline.cpp:15115` | production | consumer/read | `sourceTopologyRegions` | — | `componentProducts.sourceTopologyRegions.value(),` |
| `src/pipeline/RemeshPipeline.cpp:15132` | production | consumer/read | `sourceTopologyRegions` | — | `componentProducts.sourceTopologyRegions.value();` |
| `src/pipeline/RemeshPipeline.cpp:15460` | production | consumer/read | `quotientClass` | — | `quotientClassIdRemap;` |
| `src/pipeline/RemeshPipeline.cpp:15485` | production | consumer/read | `quotientClass` | — | `const auto existing = quotientClassIdRemap.find(local);` |
| `src/pipeline/RemeshPipeline.cpp:15486` | production | consumer/read | `quotientClass` | — | `if (existing != quotientClassIdRemap.end()) return existing->second;` |
| `src/pipeline/RemeshPipeline.cpp:15488` | production | consumer/read | `quotientClass` | — | `quotientClassOffset + quotientClassIdRemap.size();` |
| `src/pipeline/RemeshPipeline.cpp:15489` | production | consumer/read | `quotientClass` | — | `if (globalIndex < quotientClassOffset) return std::nullopt;` |
| `src/pipeline/RemeshPipeline.cpp:15493` | production | consumer/read | `quotientClass` | — | `!quotientClassIdRemap.emplace(local, global.value()).second) {` |
| `src/pipeline/RemeshPipeline.cpp:15546` | production | consumer/read | `equivalences` | — | `lineage.equivalences) {` |
| `src/pipeline/RemeshPipeline.cpp:15575` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.size() == 1U` |
| `src/pipeline/RemeshPipeline.cpp:15577` | production | consumer/read | `sourceIsolationSheets` | — | `lineage.sourceIsolationSheets.front())` |
| `src/pipeline/RemeshPipeline.cpp:15579` | production | producer/write-or-init | `sourcePoint` | — | `lineage.sourcePoint = remap_component_surface_point(` |
| `src/pipeline/RemeshPipeline.cpp:15580` | production | consumer/read | `sourcePoint` | — | `lineage.sourcePoint, component, index, projectionSheet);` |
| `src/pipeline/RemeshPipeline.cpp:15588` | production | consumer/read | `sourcePoint` | — | `!lineage.sourcePoint.valid()) \|\|` |
| `src/pipeline/RemeshPipeline.cpp:15595` | production | consumer/read | `quotientClass` | — | `if (lineage.quotientClass.has_value()) {` |
| `src/pipeline/RemeshPipeline.cpp:15597` | production | consumer/read | `quotientClass` | — | `remap_quotient_class_id(lineage.quotientClass.value());` |
| `src/pipeline/RemeshPipeline.cpp:15599` | production | producer/write-or-init | `quotientClass` | — | `lineage.quotientClass = remapped.value();` |
| `src/pipeline/RemeshPipeline.cpp:15608` | production | consumer/read | `equivalences` | — | `lineage.equivalences) {` |
| `src/pipeline/RemeshPipeline.cpp:15653` | production | consumer/read | `selectedRelationPaths` | — | `lineage.selectedRelationPaths) {` |
| `src/pipeline/RemeshPipeline.cpp:15654` | production | consumer/read | `sourceSupport` | — | `if (!certificate.sourceSupport.has_value() \|\|` |
| `src/pipeline/RemeshPipeline.cpp:15655` | production | consumer/read | `sourceSupport` | — | `!lineage.sourceSupport.has_value()) {` |
| `src/pipeline/RemeshPipeline.cpp:15658` | production | producer/write-or-init | `sourceSupport` | — | `certificate.sourceSupport = lineage.sourceSupport;` |
| `src/pipeline/RemeshPipeline.cpp:15704` | production | consumer/read | `equivalences` | — | `std::sort(lineage.equivalences.begin(),` |
| `src/pipeline/RemeshPipeline.cpp:15705` | production | consumer/read | `equivalences` | — | `lineage.equivalences.end());` |
| `src/pipeline/RemeshPipeline.cpp:15706` | production | consumer/read | `equivalences` | — | `lineage.equivalences.erase(` |
| `src/pipeline/RemeshPipeline.cpp:15707` | production | consumer/read | `equivalences` | — | `std::unique(lineage.equivalences.begin(),` |
| `src/pipeline/RemeshPipeline.cpp:15708` | production | consumer/read | `equivalences` | — | `lineage.equivalences.end()),` |
| `src/pipeline/RemeshPipeline.cpp:15709` | production | consumer/read | `equivalences` | — | `lineage.equivalences.end());` |
| `src/pipeline/RemeshPipeline.cpp:15710` | production | consumer/read | `selectedRelationPaths` | — | `std::sort(lineage.selectedRelationPaths.begin(),` |
| `src/pipeline/RemeshPipeline.cpp:15711` | production | consumer/read | `selectedRelationPaths` | — | `lineage.selectedRelationPaths.end());` |
| `src/pipeline/RemeshPipeline.cpp:15712` | production | consumer/read | `selectedRelationPaths` | — | `lineage.selectedRelationPaths.erase(` |
| `src/pipeline/RemeshPipeline.cpp:15713` | production | consumer/read | `selectedRelationPaths` | — | `std::unique(lineage.selectedRelationPaths.begin(),` |
| `src/pipeline/RemeshPipeline.cpp:15714` | production | consumer/read | `selectedRelationPaths` | — | `lineage.selectedRelationPaths.end()),` |
| `src/pipeline/RemeshPipeline.cpp:15715` | production | consumer/read | `selectedRelationPaths` | — | `lineage.selectedRelationPaths.end());` |
| `src/pipeline/RemeshPipeline.cpp:15716` | production | consumer/read | `sourceTopologyRegions` | — | `return !lineage.sourceTopologyRegions.empty() &&` |
| `src/pipeline/RemeshPipeline.cpp:15717` | production | consumer/read | `sourceIsolationSheets` | — | `!lineage.sourceIsolationSheets.empty() &&` |
| `src/pipeline/RemeshPipeline.cpp:15718` | production | consumer/read | `sourceCharts` | — | `!lineage.sourceCharts.empty() &&` |
| `src/pipeline/RemeshPipeline.cpp:15719` | production | consumer/read | `sourceSupport` | — | `lineage.sourceSupport.has_value();` |
| `src/pipeline/RemeshPipeline.cpp:15812` | production | consumer/read | `sourceIsolationSheets` | — | `remappedLineage.sourceIsolationSheets.size() == 1U` |
| `src/pipeline/RemeshPipeline.cpp:15814` | production | consumer/read | `sourceIsolationSheets` | — | `remappedLineage.sourceIsolationSheets.front())` |
| `src/pipeline/RemeshPipeline.cpp:15867` | production | consumer/read | `vertexProvenance` | — | `if (patch.vertexProvenance.size() != patch.vertexLineage.size()) {` |
| `src/pipeline/RemeshPipeline.cpp:15910` | production | consumer/read | `sourcePoint`, `vertexProvenance` | — | `patch.vertexProvenance[vertex] = patch.vertexLineage[vertex].sourcePoint;` |
| `src/pipeline/RemeshPipeline.cpp:16049` | production | consumer/read | `quotientClass` | — | `quotientClassOffset += quotientClassIdRemap.size();` |
| `src/pipeline/RemeshPipeline.cpp:16112` | production | producer/write-or-init | `sourceTopologyRegions` | — | `staged.surfaceCellContext.productSnapshots.sourceTopologyRegions = globalSourceAuthority.value();` |
| `src/pipeline/RemeshPipeline.cpp:16120` | production | producer/write-or-init | `vertexProvenance` | — | `finalAuthorityOptions.vertexProvenance = &staged.outputVertexProvenance;` |
| `src/pipeline/RemeshPipeline.cpp:16238` | production | producer/write-or-init | `vertexProvenance` | — | `aggregateOptimizationResult.vertexProvenance =` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:740` | production | consumer/read | `sourceSupport` | — | `support = sourceSupport.resolve(point);` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:800` | production | consumer/read | `sourceCharts` | — | `if (!authority.retained \|\| authority.sourceCharts.empty() \|\|` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:801` | production | consumer/read | `sourceCharts` | — | `!std::is_sorted(authority.sourceCharts.begin(),` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:802` | production | consumer/read | `sourceCharts` | — | `authority.sourceCharts.end()) \|\|` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:803` | production | consumer/read | `sourceCharts` | — | `std::adjacent_find(authority.sourceCharts.begin(),` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:804` | production | consumer/read | `sourceCharts` | — | `authority.sourceCharts.end()) !=` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:805` | production | consumer/read | `sourceCharts` | — | `authority.sourceCharts.end() \|\|` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:823` | production | consumer/read | `sourceCharts` | — | `!std::binary_search(authority.sourceCharts.begin(),` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:824` | production | consumer/read | `sourceCharts` | — | `authority.sourceCharts.end(), declared.value())) {` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:830` | production | consumer/read | `sourceCharts` | — | `authority.sourceCharts) {` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:1019` | production | producer/write-or-init | `vertexProvenance` | — | `options.sourceAuthority == nullptr \|\| options.vertexProvenance == nullptr \|\|` |
| `src/validation/SourceAuthoritativeMeshValidator.cpp:1126` | production | consumer/read | `vertexProvenance` | — | `const auto &provenance = *options.vertexProvenance;` |
| `tests/FieldAlignedCurveNetworkTests.cpp:876` | test | consumer/read | `sourceTopologyRegions` | `FieldAlignedCurveNetwork.RejectsMissingDuplicateOrForeignMandatoryEdges`; selector449 row 16 | `EXPECT_EQ(2U, hard->sourceTopologyRegions.size());` |
| `tests/FieldAlignedCurveNetworkTests.cpp:7122` | test | consumer/read | `sourceTopologyRegions` | `GlobalTopologyPlan.UnestablishedFieldTransportCannotProduceATopologyPlan`; selector449 row 316 | `<< ";sourceTopologyRegionsSnapshot="` |
| `tests/FieldAlignedCurveNetworkTests.cpp:7123` | test | consumer/read | `sourceTopologyRegions` | `GlobalTopologyPlan.UnestablishedFieldTransportCannotProduceATopologyPlan`; selector449 row 316 | `<< (products.sourceTopologyRegions.has_value() ? "yes" : "no")` |
| `tests/FieldAlignedCurveNetworkTests.cpp:7163` | test | producer/write-or-init | `sourceTopologyRegions` | `GlobalTopologyPlan.UnestablishedFieldTransportCannotProduceATopologyPlan`; selector449 row 316 | `report << ";sourceTopologyRegions=false;furthestStage=pre-source-topology";` |
| `tests/FieldAlignedCurveNetworkTests.cpp:7167` | test | producer/write-or-init | `sourceTopologyRegions` | `GlobalTopologyPlan.UnestablishedFieldTransportCannotProduceATopologyPlan`; selector449 row 316 | `report << ";sourceTopologyRegions=true"` |
| `tests/FieldAlignedCurveNetworkTests.cpp:7827` | test | consumer/read | `sourceTopologyRegions` | `GlobalTopologyPlan.UnestablishedFieldTransportCannotProduceATopologyPlan`; selector449 row 316 | `fixture.sourceAuthority = products.sourceTopologyRegions;` |
| `tests/FieldAlignedCurveNetworkTests.cpp:15058` | test | consumer/read | `sourceTopologyRegions` | `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`; selector449 row 427 | `ASSERT_TRUE(products.sourceTopologyRegions.has_value());` |
| `tests/MilestoneDClosureTests.cpp:555` | test | consumer/read | `sourceCharts` | `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`; not in focused-12/selector449 | `ASSERT_EQ(left.sourceCharts.size(), 1U);` |
| `tests/MilestoneDClosureTests.cpp:556` | test | consumer/read | `sourceCharts` | `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`; not in focused-12/selector449 | `ASSERT_EQ(right.sourceCharts.size(), 1U);` |
| `tests/MilestoneDClosureTests.cpp:557` | test | consumer/read | `sourceCharts` | `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`; not in focused-12/selector449 | `EXPECT_NE(left.sourceCharts.front().face, right.sourceCharts.front().face);` |
| `tests/MilestoneFBenchmark.cpp:190` | test | producer/mutation-or-mixed | `vertexProvenance` | enclosing GTest not statically recovered | `constraints.vertexProvenance.reserve(static_cast<std::size_t>(vertexCount));` |
| `tests/MilestoneFBenchmark.cpp:192` | test | producer/mutation-or-mixed | `vertexProvenance` | enclosing GTest not statically recovered | `constraints.vertexProvenance.push_back(` |
| `tests/MilestoneGP25Tests.cpp:89` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `EXPECT_EQ(lhs.product().outputVertexLineage[index].sourcePoint.face,` |
| `tests/MilestoneGP25Tests.cpp:90` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `rhs.product().outputVertexLineage[index].sourcePoint.face);` |
| `tests/MilestoneGP25Tests.cpp:91` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `EXPECT_EQ(lhs.product().outputVertexLineage[index].sourcePoint.component,` |
| `tests/MilestoneGP25Tests.cpp:92` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `rhs.product().outputVertexLineage[index].sourcePoint.component);` |
| `tests/MilestoneGP25Tests.cpp:277` | test | consumer/read | `vertexProvenance` | `MilestoneGP25.SequentialAndParallelSchedulesAreStructurallyIdentical`; not in focused-12/selector449 | `.vertexProvenance.size());` |
| `tests/MilestoneGP25Tests.cpp:325` | test | consumer/read | `sourcePoint` | `MilestoneGP25.ProvenanceAndLineageAreRemappedToOriginalMesh`; not in focused-12/selector449 | `EXPECT_GE(lineage.sourcePoint.face, 0);` |
| `tests/MilestoneGP25Tests.cpp:326` | test | consumer/read | `sourcePoint` | `MilestoneGP25.ProvenanceAndLineageAreRemappedToOriginalMesh`; not in focused-12/selector449 | `EXPECT_LT(lineage.sourcePoint.face, mesh.faces.rows());` |
| `tests/MilestoneGP26Tests.cpp:370` | test | consumer/read | `vertexPositions` | `MilestoneGP26.RecoveryTargetProjectionIsBoundedAndDeterministic`; selector449 row 43 | `meshData.vertices, meshData.faces, recovery.mesh.vertexPositions,` |
| `tests/MilestoneGP26Tests.cpp:371` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RecoveryTargetProjectionIsBoundedAndDeterministic`; selector449 row 43 | `quads, recovery.mesh.vertexProvenance, requested, 2.0);` |
| `tests/MilestoneGP26Tests.cpp:374` | test | consumer/read | `vertexPositions` | `MilestoneGP26.RecoveryTargetProjectionIsBoundedAndDeterministic`; selector449 row 43 | `meshData.vertices, meshData.faces, recovery.mesh.vertexPositions,` |
| `tests/MilestoneGP26Tests.cpp:375` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RecoveryTargetProjectionIsBoundedAndDeterministic`; selector449 row 43 | `quads, recovery.mesh.vertexProvenance, requested, 2.0);` |
| `tests/MilestoneGP26Tests.cpp:425` | test | consumer/read | `vertexPositions` | `MilestoneGP26.RequiredProductionRecoveryTargetsAreFeasible`; selector449 row 44 | `meshData.vertices, meshData.faces, recovery.mesh.vertexPositions,` |
| `tests/MilestoneGP26Tests.cpp:426` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RequiredProductionRecoveryTargetsAreFeasible`; selector449 row 44 | `quads, recovery.mesh.vertexProvenance, requested, 2.0);` |
| `tests/MilestoneGP26Tests.cpp:469` | test | producer/write-or-init | `vertexProvenance` | `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets`; not in focused-12/selector449 | `options.vertexProvenance = &provenance;` |
| `tests/MilestoneGP26Tests.cpp:696` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.ProductionFieldFilesFinalizeAuthoritatively`; not in focused-12/selector449 | `first.mesh.vertexProvenance.size());` |
| `tests/MilestoneGP26Tests.cpp:844` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RecoveryPreservesComponentAndSheetProvenance`; selector449 row 42 | `ASSERT_FALSE(recovery.mesh.vertexProvenance.empty());` |
| `tests/MilestoneGP26Tests.cpp:845` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RecoveryPreservesComponentAndSheetProvenance`; selector449 row 42 | `for (const auto &point : recovery.mesh.vertexProvenance) {` |
| `tests/MilestoneGP27Tests.cpp:3` | test | consumer/read | `BenchmarkQuality` | enclosing GTest not statically recovered | `#include "BenchmarkQuality.h"` |
| `tests/MilestoneGP27Tests.cpp:74` | test | consumer/read | `BenchmarkQuality` | enclosing GTest not statically recovered | `using directional::bench::BenchmarkQuality;` |
| `tests/MilestoneGP27Tests.cpp:109` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.face = sourceFaces[static_cast<std::size_t>(vertex)];` |
| `tests/MilestoneGP27Tests.cpp:110` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.component = 0;` |
| `tests/MilestoneGP27Tests.cpp:111` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.sheet = 0;` |
| `tests/MilestoneGP27Tests.cpp:112` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.barycentric =` |
| `tests/MilestoneGP27Tests.cpp:114` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.position = result.vertices.row(vertex).transpose();` |
| `tests/MilestoneGP27Tests.cpp:115` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.squaredDistance = 0.0;` |
| `tests/MilestoneGP27Tests.cpp:118` | test | producer/write-or-init | `sourceTopologyRegions` | enclosing GTest not statically recovered | `lineage.sourceTopologyRegions = {test_topology_region_id(0)};` |
| `tests/MilestoneGP27Tests.cpp:119` | test | producer/write-or-init | `sourceIsolationSheets` | enclosing GTest not statically recovered | `lineage.sourceIsolationSheets = {test_isolation_sheet_id(0)};` |
| `tests/MilestoneGP27Tests.cpp:120` | test | producer/write-or-init | `sourceCharts` | enclosing GTest not statically recovered | `lineage.sourceCharts = {test_projection_chart(` |
| `tests/MilestoneGP27Tests.cpp:122` | test | producer/write-or-init | `sourceSupport` | enclosing GTest not statically recovered | `lineage.sourceSupport = test_source_vertex_support(vertex);` |
| `tests/MilestoneGP27Tests.cpp:148` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.face = component;` |
| `tests/MilestoneGP27Tests.cpp:149` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.component = component;` |
| `tests/MilestoneGP27Tests.cpp:150` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.sheet = component;` |
| `tests/MilestoneGP27Tests.cpp:151` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.barycentric = Eigen::Vector3d(1.0, 0.0, 0.0);` |
| `tests/MilestoneGP27Tests.cpp:152` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.position = result.vertices.row(vertex).transpose();` |
| `tests/MilestoneGP27Tests.cpp:153` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint.squaredDistance = 0.0;` |
| `tests/MilestoneGP27Tests.cpp:156` | test | producer/write-or-init | `sourceTopologyRegions` | enclosing GTest not statically recovered | `lineage.sourceTopologyRegions = {test_topology_region_id(component)};` |
| `tests/MilestoneGP27Tests.cpp:157` | test | producer/write-or-init | `sourceIsolationSheets` | enclosing GTest not statically recovered | `lineage.sourceIsolationSheets = {test_isolation_sheet_id(component)};` |
| `tests/MilestoneGP27Tests.cpp:158` | test | producer/write-or-init | `sourceCharts` | enclosing GTest not statically recovered | `lineage.sourceCharts = {test_projection_chart(component, component)};` |
| `tests/MilestoneGP27Tests.cpp:159` | test | producer/write-or-init | `sourceSupport` | enclosing GTest not statically recovered | `lineage.sourceSupport = test_source_vertex_support(vertex % 4);` |
| `tests/MilestoneGP27Tests.cpp:230` | test | consumer/read | `BenchmarkQuality` | enclosing GTest not statically recovered | `void remove_quality_artifacts(const BenchmarkQuality &quality) {` |
| `tests/MilestoneGP27Tests.cpp:286` | test | consumer/read | `BenchmarkQuality` | `MilestoneGP27.QualitySchemaContainsEveryRequiredProductionMetric`; not in focused-12/selector449 | `const BenchmarkQuality quality =` |
| `tests/MilestoneGP27Tests.cpp:394` | test | producer/write-or-init | `sourceSupport` | `MilestoneGP27.SemanticHashDetectsConnectivityAndLineageMutation`; not in focused-12/selector449 | `lineageMutation.outputVertexLineage.front().sourceSupport =` |
| `tests/MilestoneGP27Tests.cpp:409` | test | consumer/read | `BenchmarkQuality` | `MilestoneGP27.QualityCountsSelfIntersectingPolygon`; not in focused-12/selector449 | `const BenchmarkQuality quality =` |
| `tests/PatchDescriptorMilestoneETests.cpp:93` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `if (cell.sourceCharts.size() != cell.sourceFaces.size()) {` |
| `tests/PatchDescriptorMilestoneETests.cpp:97` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `for (std::size_t index = 0; index < cell.sourceCharts.size(); ++index) {` |
| `tests/PatchDescriptorMilestoneETests.cpp:98` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `cell.sourceCharts[index] = canonical_projection_chart_for_source_row(` |
| `tests/PatchDescriptorMilestoneETests.cpp:99` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `faces, cell.sourceFaces[index], cell.sourceCharts[index].chart);` |
| `tests/PatchDescriptorMilestoneETests.cpp:101` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `std::sort(cell.sourceCharts.begin(), cell.sourceCharts.end());` |
| `tests/PatchDescriptorMilestoneETests.cpp:102` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `cell.sourceCharts.erase(` |
| `tests/PatchDescriptorMilestoneETests.cpp:103` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `std::unique(cell.sourceCharts.begin(), cell.sourceCharts.end()),` |
| `tests/PatchDescriptorMilestoneETests.cpp:104` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `cell.sourceCharts.end());` |
| `tests/PatchDescriptorMilestoneETests.cpp:171` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `cell.sourceCharts.push_back(test_projection_chart(0, sourceFace));` |
| `tests/PatchDescriptorMilestoneETests.cpp:528` | test | producer/write-or-init | `sourceCharts` | enclosing GTest not statically recovered | `cell.sourceCharts = {test_projection_chart(0, sourceFace)};` |
| `tests/PatchDescriptorMilestoneETests.cpp:548` | test | producer/write-or-init | `sourceCharts` | enclosing GTest not statically recovered | `exterior.sourceCharts = {` |
| `tests/PatchDescriptorMilestoneETests.cpp:748` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `cell.sourceCharts.push_back(test_projection_chart(0, sourceFace));` |
| `tests/PatchDescriptorMilestoneETests.cpp:861` | test | consumer/read | `sourceCharts` | `PatchDescriptorMilestoneE.RejectsOddBoundaryAndHardBarrierCrossing`; not in focused-12/selector449 | `ASSERT_EQ(cell.sourceFaces.size(), cell.sourceCharts.size())` |
| `tests/PatchDescriptorMilestoneETests.cpp:865` | test | consumer/read | `sourceCharts` | `PatchDescriptorMilestoneE.RejectsOddBoundaryAndHardBarrierCrossing`; not in focused-12/selector449 | `F, cell.sourceFaces[index], cell.sourceCharts[index].chart);` |
| `tests/PatchDescriptorMilestoneETests.cpp:866` | test | consumer/read | `sourceCharts` | `PatchDescriptorMilestoneE.RejectsOddBoundaryAndHardBarrierCrossing`; not in focused-12/selector449 | `EXPECT_EQ(expectedChart, cell.sourceCharts[index])` |
| `tests/PureQuadCompletionPhase18Tests.cpp:229` | test | consumer/read | `sourceSupport` | enclosing GTest not statically recovered | `identity.sourceSupportCount = 2;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:234` | test | consumer/read | `sourceSupport` | enclosing GTest not statically recovered | `identity.sourceSupport.valid = true;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:235` | test | consumer/read | `sourceSupport` | enclosing GTest not statically recovered | `identity.sourceSupport.values = {307, token};` |
| `tests/PureQuadCompletionPhase18Tests.cpp:249` | test | consumer/read | `sourceSupport` | enclosing GTest not statically recovered | `identity.sourceSupportCount = 2;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:254` | test | consumer/read | `sourceSupport` | enclosing GTest not statically recovered | `identity.sourceSupport.valid = true;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:255` | test | consumer/read | `sourceSupport` | enclosing GTest not statically recovered | `identity.sourceSupport.values = {307, 9};` |
| `tests/PureQuadCompletionPhase18Tests.cpp:596` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.CompletionVerticesCarrySourceProvenance`; selector449 row 73 | `ASSERT_EQ(completion.product().vertexProvenance.size(),` |
| `tests/PureQuadCompletionPhase18Tests.cpp:598` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.CompletionVerticesCarrySourceProvenance`; selector449 row 73 | `ASSERT_EQ(completion.product().vertexPositions.rows(),` |
| `tests/PureQuadCompletionPhase18Tests.cpp:600` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.CompletionVerticesCarrySourceProvenance`; selector449 row 73 | `for (const auto &point : completion.product().vertexProvenance) {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:605` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.CompletionVerticesCarrySourceProvenance`; selector449 row 73 | `EXPECT_NEAR(completion.product().vertexPositions(0, 2), 1.0, 1.0e-12);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:769` | test | producer/mutation-or-mixed | `vertexPositions` | `PureQuadCompletionPhase18.ValidationReportsNonPureAndInvariantFlags`; not in focused-12/selector449 | `mesh.vertexPositions.resize(3, 3);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:770` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.ValidationReportsNonPureAndInvariantFlags`; not in focused-12/selector449 | `mesh.vertexPositions << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1050` | test | consumer/read | `sourcePoint` | `PureQuadCompletionPhase18.P18GeneratedInteriorVertexHasSourceTriangleLineage`; selector449 row 87 | `EXPECT_TRUE(generated->sourcePoint.valid());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1070` | test | producer/mutation-or-mixed | `vertexProvenance` | `PureQuadCompletionPhase18.P18RejectsPairedSourceTriangleBoundaryProofFixture`; not in focused-12/selector449 | `mesh.vertexProvenance.push_back(point);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1073` | test | producer/write-or-init | `sourcePoint` | `PureQuadCompletionPhase18.P18RejectsPairedSourceTriangleBoundaryProofFixture`; not in focused-12/selector449 | `lineage.sourcePoint = point;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1103` | test | producer/mutation-or-mixed | `vertexProvenance` | `PureQuadCompletionPhase18.P18RejectsPairedSourceTriangleBoundaryProofFixture`; not in focused-12/selector449 | `mesh.vertexProvenance.push_back(point);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1106` | test | producer/write-or-init | `sourcePoint` | `PureQuadCompletionPhase18.P18RejectsPairedSourceTriangleBoundaryProofFixture`; not in focused-12/selector449 | `lineage.sourcePoint = point;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1152` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `for (int row = 0; row < completion.product().vertexPositions.rows(); ++row) {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1154` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `std::llround(completion.product().vertexPositions(row, 0) * 1000000.0),` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1155` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `std::llround(completion.product().vertexPositions(row, 1) * 1000000.0));` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1164` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_NEAR(0.5, completion.product().vertexPositions(row, 0), 1.0e-12);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1165` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_NEAR(0.5, completion.product().vertexPositions(row, 1), 1.0e-12);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1166` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_TRUE(completion.product().vertexProvenance[static_cast<std::size_t>(row)]` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1323` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `completion.rejection()->ownershipRejection.sourceSupport.has_value());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1326` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `completion.rejection()->ownershipRejection.sourceSupport.value()));` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1353` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `allowedMesh.vertexProvenance[row].face = allowedFace;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1354` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `allowedMesh.vertexProvenance[row].barycentric << 0.2, 0.3, 0.5;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1355` | test | producer/write-or-init | `sourcePoint` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `allowedMesh.vertexLineage[row].sourcePoint =` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1356` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `allowedMesh.vertexProvenance[row];` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1389` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `escapedMesh.vertexProvenance[row].face = 2;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1390` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `escapedMesh.vertexProvenance[row].barycentric << 0.2, 0.3, 0.5;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1391` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `escapedMesh.vertexProvenance[row].position =` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1395` | test | producer/write-or-init | `sourcePoint` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `escapedMesh.vertexLineage[row].sourcePoint =` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1396` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `escapedMesh.vertexProvenance[row];` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1720` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `patches[1].vertexPositions(row, 0) += 0.25;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1849` | test | consumer/read | `sourceTopologyRegions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_FALSE(lineage.sourceTopologyRegions.empty());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1850` | test | consumer/read | `sourceIsolationSheets` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_FALSE(lineage.sourceIsolationSheets.empty());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1851` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_FALSE(lineage.sourceCharts.empty());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1852` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_TRUE(lineage.sourceSupport.has_value());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1917` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `.sourceSupport.value());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1945` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `ASSERT_EQ(firstLineage.sourceSupport, secondLineage.sourceSupport);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1946` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `ASSERT_TRUE(firstLineage.sourceSupport.has_value());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1951` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `&firstLineage.sourceSupport.value());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1977` | test | producer/write-or-init | `sourceCharts` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `firstLineage.sourceCharts = {commonChart, firstExtraChart};` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1978` | test | producer/write-or-init | `sourceCharts` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `secondLineage.sourceCharts = {commonChart, secondExtraChart};` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1979` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `std::sort(firstLineage.sourceCharts.begin(), firstLineage.sourceCharts.end());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1980` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `std::sort(secondLineage.sourceCharts.begin(), secondLineage.sourceCharts.end());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1996` | test | consumer/read | `sourceTopologyRegions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `const auto expectedRegions = intersect(firstLineage.sourceTopologyRegions,` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1997` | test | consumer/read | `sourceTopologyRegions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `secondLineage.sourceTopologyRegions);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1998` | test | consumer/read | `sourceIsolationSheets` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `const auto expectedSheets = intersect(firstLineage.sourceIsolationSheets,` |
| `tests/PureQuadCompletionPhase18Tests.cpp:1999` | test | consumer/read | `sourceIsolationSheets` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `secondLineage.sourceIsolationSheets);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2001` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `intersect(firstLineage.sourceCharts, secondLineage.sourceCharts);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2005` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `ASSERT_NE(firstLineage.sourceCharts, secondLineage.sourceCharts);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2027` | test | consumer/read | `sourceTopologyRegions` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_EQ(expectedRegions, published->sourceTopologyRegions);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2028` | test | consumer/read | `sourceIsolationSheets` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_EQ(expectedSheets, published->sourceIsolationSheets);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2029` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_EQ(expectedCharts, published->sourceCharts);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2030` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.P18FailsClosedWhenQuadLineageIsMissing`; selector449 row 86 | `EXPECT_EQ(firstLineage.sourceSupport, published->sourceSupport);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2066` | test | producer/write-or-init | `sourceTopologyRegions` | `PureQuadCompletionPhase18.UnownedRegionCertificatePublishesNothing`; selector449 row 100 | `patches.front().vertexLineage.front().sourceTopologyRegions = {fake.value()};` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2092` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `return lineage.sourceSupport.has_value() &&` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2095` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `lineage.sourceSupport.value());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2103` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `if (std::find(lineage.sourceCharts.begin(), lineage.sourceCharts.end(),` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2104` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `secondChart) == lineage.sourceCharts.end()) {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2105` | test | producer/mutation-or-mixed | `sourceCharts` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `lineage.sourceCharts.push_back(secondChart);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2108` | test | consumer/read | `sourceTopologyRegions` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `if (std::find(lineage.sourceTopologyRegions.begin(),` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2109` | test | consumer/read | `sourceTopologyRegions` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `lineage.sourceTopologyRegions.end(),` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2110` | test | consumer/read | `sourceTopologyRegions` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `secondRegion) == lineage.sourceTopologyRegions.end()) {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2111` | test | producer/mutation-or-mixed | `sourceTopologyRegions` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `lineage.sourceTopologyRegions.push_back(secondRegion);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2114` | test | consumer/read | `sourceIsolationSheets` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `if (std::find(lineage.sourceIsolationSheets.begin(),` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2115` | test | consumer/read | `sourceIsolationSheets` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `lineage.sourceIsolationSheets.end(),` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2116` | test | consumer/read | `sourceIsolationSheets` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `secondSheet) == lineage.sourceIsolationSheets.end()) {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2117` | test | producer/mutation-or-mixed | `sourceIsolationSheets` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `lineage.sourceIsolationSheets.push_back(secondSheet);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2128` | test | producer/write-or-init | `sourceIsolationSheets` | `PureQuadCompletionPhase18.SparseOwnerCertificatePublishesNothing`; selector449 row 96 | `lineage.sourceIsolationSheets = {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2165` | test | producer/write-or-init | `sourceIsolationSheets` | `PureQuadCompletionPhase18.WrongOwnerSheetCertificatePublishesNothing`; selector449 row 103 | `completion.product().vertexLineage.front().sourceIsolationSheets = {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2186` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.WrongFaceChartCertificatePublishesNothing`; selector449 row 102 | `ASSERT_FALSE(lineage.sourceCharts.empty());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2187` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.WrongFaceChartCertificatePublishesNothing`; selector449 row 102 | `ASSERT_TRUE(lineage.sourceSupport.has_value());` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2192` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.WrongFaceChartCertificatePublishesNothing`; selector449 row 102 | `&lineage.sourceSupport.value())) {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2198` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.WrongFaceChartCertificatePublishesNothing`; selector449 row 102 | `&lineage.sourceSupport.value())) {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2209` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.WrongFaceChartCertificatePublishesNothing`; selector449 row 102 | `&lineage.sourceSupport.value())) {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2228` | test | consumer/read | `sourceCharts` | `PureQuadCompletionPhase18.WrongFaceChartCertificatePublishesNothing`; selector449 row 102 | `lineage.sourceCharts.front().face =` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2378` | test | consumer/read | `sourceTopologyRegions` | `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing`; selector449 row 97 | `EXPECT_EQ(first.product().vertexLineage.front().sourceTopologyRegions,` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2379` | test | consumer/read | `sourceTopologyRegions` | `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing`; selector449 row 97 | `second.product().vertexLineage.front().sourceTopologyRegions);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2380` | test | consumer/read | `sourceIsolationSheets` | `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing`; selector449 row 97 | `EXPECT_EQ(first.product().vertexLineage.front().sourceIsolationSheets,` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2381` | test | consumer/read | `sourceIsolationSheets` | `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing`; selector449 row 97 | `second.product().vertexLineage.front().sourceIsolationSheets);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2382` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing`; selector449 row 97 | `EXPECT_NE(first.product().vertexLineage.front().sourceSupport,` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2383` | test | consumer/read | `sourceSupport` | `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing`; selector449 row 97 | `second.product().vertexLineage.front().sourceSupport);` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2428` | test | consumer/read | `vertexProvenance` | `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing`; selector449 row 97 | `for (auto &point : tampered.vertexProvenance) {` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2433` | test | consumer/read | `sourcePoint` | `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing`; selector449 row 97 | `lineage.sourcePoint.component = 903;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2434` | test | consumer/read | `sourcePoint` | `PureQuadCompletionPhase18.StaleCanonicalAuthorityPublishesNothing`; selector449 row 97 | `lineage.sourcePoint.sheet = 904;` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2465` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.StitchingIsPatchOrderInvariant`; selector449 row 98 | `EXPECT_TRUE(forward.mesh.vertexPositions.isApprox(` |
| `tests/PureQuadCompletionPhase18Tests.cpp:2466` | test | consumer/read | `vertexPositions` | `PureQuadCompletionPhase18.StitchingIsPatchOrderInvariant`; selector449 row 98 | `reverse.mesh.vertexPositions, 0.0));` |
| `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp:117` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `options.vertexProvenance = &provenance;` |
| `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp:155` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `options.vertexProvenance = &provenance;` |
| `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp:190` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `options.vertexProvenance = &provenance;` |
| `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp:239` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `options.vertexProvenance = &provenance;` |
| `tests/SourceGridRecoveryAuthorityTests.cpp:136` | test | consumer/read | `vertexPositions` | `MilestoneGP26.RecoveryTargetProjectionIsBoundedAndDeterministic`; selector449 row 43 | `recovery.mesh.vertexPositions, quads,` |
| `tests/SourceGridRecoveryAuthorityTests.cpp:137` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RecoveryTargetProjectionIsBoundedAndDeterministic`; selector449 row 43 | `recovery.mesh.vertexProvenance, requested, 2.0);` |
| `tests/SourceGridRecoveryAuthorityTests.cpp:141` | test | consumer/read | `vertexPositions` | `MilestoneGP26.RecoveryTargetProjectionIsBoundedAndDeterministic`; selector449 row 43 | `recovery.mesh.vertexPositions, quads,` |
| `tests/SourceGridRecoveryAuthorityTests.cpp:142` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RecoveryTargetProjectionIsBoundedAndDeterministic`; selector449 row 43 | `recovery.mesh.vertexProvenance, requested, 2.0);` |
| `tests/SourceGridRecoveryAuthorityTests.cpp:194` | test | consumer/read | `vertexPositions` | `MilestoneGP26.RequiredProductionRecoveryTargetsAreFeasible`; selector449 row 44 | `recovery.mesh.vertexPositions, quads,` |
| `tests/SourceGridRecoveryAuthorityTests.cpp:195` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RequiredProductionRecoveryTargetsAreFeasible`; selector449 row 44 | `recovery.mesh.vertexProvenance, requested, 2.0);` |
| `tests/SourceGridRecoveryAuthorityTests.cpp:259` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RequiredProductionRecoveryTargetsAreFeasible`; selector449 row 44 | `first.mesh.vertexProvenance.size());` |
| `tests/SourceGridRecoveryAuthorityTests.cpp:325` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RecoveryPreservesComponentAndSheetProvenance`; selector449 row 42 | `ASSERT_FALSE(recovery.mesh.vertexProvenance.empty());` |
| `tests/SourceGridRecoveryAuthorityTests.cpp:326` | test | consumer/read | `vertexProvenance` | `MilestoneGP26.RecoveryPreservesComponentAndSheetProvenance`; selector449 row 42 | `for (const auto &point : recovery.mesh.vertexProvenance) {` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1411` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `ASSERT_EQ(2U, cell->sourceCharts.size());` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1413` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `source_face_row_for_topology(fixture.faces, cell->sourceCharts[0].face);` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1415` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `source_face_row_for_topology(fixture.faces, cell->sourceCharts[1].face);` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1428` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `EXPECT_TRUE(std::binary_search(cell->sourceCharts.begin(),` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1429` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `cell->sourceCharts.end(), chart.value()));` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1571` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `ASSERT_EQ(interior->sourceCharts.size(), 2U);` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1573` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `fixture.faces, interior->sourceCharts[0].face);` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1575` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `fixture.faces, interior->sourceCharts[1].face);` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1667` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `ASSERT_EQ(2U, interior->sourceCharts.size());` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1671` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `fixture.faces, interior->sourceCharts[0].face);` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1673` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `fixture.faces, interior->sourceCharts[1].face);` |
| `tests/SurfaceArrangementPhase16Tests.cpp:1678` | test | consumer/read | `sourceCharts` | `SurfaceArrangementPhase16.MemoryRatioAndOverlayChannelsAreBounded`; not in focused-12/selector449 | `EXPECT_NE(interior->sourceCharts[0].face, interior->sourceCharts[1].face);` |
| `tests/SurfaceCellPipelinePhase20Tests.cpp:461` | test | producer/mutation-or-mixed | `vertexPositions` | enclosing GTest not statically recovered | `mesh.vertexPositions.resize(4, 3);` |
| `tests/SurfaceCellPipelinePhase20Tests.cpp:462` | test | consumer/read | `vertexPositions` | enclosing GTest not statically recovered | `mesh.vertexPositions << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,` |
| `tests/SurfaceCellPipelinePhase20Tests.cpp:474` | test | consumer/read | `vertexPositions` | enclosing GTest not statically recovered | `point.position = mesh.vertexPositions.row(vertex).transpose();` |
| `tests/SurfaceCellPipelinePhase20Tests.cpp:475` | test | producer/mutation-or-mixed | `vertexProvenance` | enclosing GTest not statically recovered | `mesh.vertexProvenance.push_back(point);` |
| `tests/SurfaceCellPipelinePhase20Tests.cpp:738` | test | consumer/read | `vertexProvenance` | `SurfaceCellPipelinePhase20.CompletionHashChangesWhenProvenanceChangesWithoutCount`; not in focused-12/selector449 | `second.vertexProvenance[0].face = 3;` |
| `tests/SurfaceCellPipelinePhase20Tests.cpp:739` | test | consumer/read | `vertexProvenance` | `SurfaceCellPipelinePhase20.CompletionHashChangesWhenProvenanceChangesWithoutCount`; not in focused-12/selector449 | `second.vertexProvenance[0].barycentric = Eigen::RowVector3d(0.8, 0.1, 0.1);` |
| `tests/SurfaceCellPipelinePhase20Tests.cpp:741` | test | consumer/read | `hash_completion` | `SurfaceCellPipelinePhase20.CompletionHashChangesWhenProvenanceChangesWithoutCount`; not in focused-12/selector449 | `EXPECT_NE(directional::pipeline::hash_completion(first),` |
| `tests/SurfaceCellPipelinePhase20Tests.cpp:742` | test | consumer/read | `hash_completion` | `SurfaceCellPipelinePhase20.CompletionHashChangesWhenProvenanceChangesWithoutCount`; not in focused-12/selector449 | `directional::pipeline::hash_completion(second));` |
| `tests/SurfaceCellPipelinePhase20Tests.cpp:1832` | test | consumer/read | `vertexProvenance` | `SurfaceCellPipelinePhase20.ValidationRejectionCannotReportCompletedSurfaceCells`; not in focused-12/selector449 | `EXPECT_EQ(result.surfaceCellContext.productSnapshots.optimizationResult.vertexProvenance.size(),` |
| `tests/SurfaceCellProductOracleTests.cpp:113` | test | producer/write-or-init | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint = point;` |
| `tests/SurfaceCellProductOracleTests.cpp:165` | test | producer/write-or-init | `sourcePoint` | enclosing GTest not statically recovered | `lineage.sourcePoint = point;` |
| `tests/SurfaceCellProductOracleTests.cpp:255` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `remap_source_point(lineage.sourcePoint, oldToNewSourceFace);` |
| `tests/SurfaceCellProductOracleTests.cpp:596` | test | consumer/read | `sourcePoint` | `SurfaceCellProductOracleLineage.RejectsOutOfDomainSourceFace`; not in focused-12/selector449 | `product.result.product().outputVertexLineage.front().sourcePoint.face =` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:1` | test | consumer/read | `BenchmarkQuality` | enclosing GTest not statically recovered | `#include "BenchmarkQuality.h"` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:532` | test | consumer/read | `sourceTopologyRegions` | enclosing GTest not statically recovered | `!snapshots.sourceTopologyRegions.has_value() \|\|` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:1397` | test | consumer/read | `sourceTopologyRegions` | enclosing GTest not statically recovered | `!snapshots.sourceTopologyRegions.has_value() \|\|` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:1409` | test | consumer/read | `sourceTopologyRegions` | enclosing GTest not statically recovered | `*snapshots.sourceTopologyRegions, *snapshots.globalTopologyPlan,` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:1461` | test | consumer/read | `sourceTopologyRegions` | enclosing GTest not statically recovered | `product.sourceTopologyRegions(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:1814` | test | producer/mutation-or-mixed | `selectedRelationPaths` | enclosing GTest not statically recovered | `result.insert(result.end(), lineage.selectedRelationPaths.begin(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:1815` | test | consumer/read | `selectedRelationPaths` | enclosing GTest not statically recovered | `lineage.selectedRelationPaths.end());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:1948` | test | producer/mutation-or-mixed | `quotientClass` | enclosing GTest not statically recovered | `signature.emplace_back(lineage.quotientClass, lineage.sourceOccurrences);` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:2119` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; focused-12 ordinal 7 | `baselineFixture.network.phaseFront.product().sourceTopologyRegions();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:2131` | test | consumer/read | `equivalences` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; focused-12 ordinal 7 | `for (const auto &equivalence : lineage.equivalences) {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:2156` | test | consumer/read | `sourcePoint` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; focused-12 ordinal 7 | `if ((lineage.sourcePoint.position - point).norm() <= 1.0e-12) {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:2171` | test | consumer/read | `sourceIsolationSheets` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; focused-12 ordinal 7 | `EXPECT_EQ(expectedSheets, v0->sourceIsolationSheets);` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:2172` | test | consumer/read | `sourceIsolationSheets` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; focused-12 ordinal 7 | `EXPECT_EQ(expectedSheets, center->sourceIsolationSheets);` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:2173` | test | consumer/read | `sourceIsolationSheets` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; focused-12 ordinal 7 | `EXPECT_EQ(expectedSheets, v2->sourceIsolationSheets);` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:2200` | test | consumer/read | `sourceIsolationSheets` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; focused-12 ordinal 7 | `EXPECT_EQ(1U, lineage.sourceIsolationSheets.size());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:2202` | test | consumer/read | `selectedRelationPaths` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; focused-12 ordinal 7 | `EXPECT_TRUE(lineage.selectedRelationPaths.empty());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:2215` | test | consumer/read | `sourceIsolationSheets` | `M6CP1.SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority`; focused-12 ordinal 7 | `lineage.sourceIsolationSheets,` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3056` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `fixture.network.phaseFront.product().sourceTopologyRegions().regions().begin(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3057` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `fixture.network.phaseFront.product().sourceTopologyRegions().regions().end(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3061` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `if (region == fixture.network.phaseFront.product().sourceTopologyRegions().regions().end() \|\|` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3066` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `fixture.network.phaseFront.product().sourceTopologyRegions().rows_for_region(` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3201` | test | consumer/read | `sourcePoint` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourcePoint.face = component;` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3202` | test | consumer/read | `sourcePoint` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourcePoint.component = component;` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3203` | test | consumer/read | `sourcePoint` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourcePoint.sheet = component;` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3204` | test | consumer/read | `sourcePoint` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourcePoint.barycentric = Eigen::Vector3d(1.0, 0.0, 0.0);` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3205` | test | consumer/read | `sourcePoint` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourcePoint.position = result.vertices.row(vertex).transpose();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3206` | test | consumer/read | `sourcePoint` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourcePoint.squaredDistance = 0.0;` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3207` | test | producer/write-or-init | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourceTopologyRegions = {test_topology_region_id(component)};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3208` | test | producer/write-or-init | `sourceIsolationSheets` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourceIsolationSheets = {test_isolation_sheet_id(component)};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3209` | test | producer/write-or-init | `sourceCharts` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourceCharts = {test_projection_chart(component, component)};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3210` | test | producer/write-or-init | `sourceSupport` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourceSupport = test_source_vertex_support(vertex % 4);` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3448` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `static_cast<std::int64_t>(product.sourceTopologyRegions().regions().size()),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3449` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `product.sourceTopologyRegions().regions().size() + 1U);` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3453` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `product.sourceTopologyRegions(), wrongRegion.value(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3478` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `product.sourceTopologyRegions(), certificate.region(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3503` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `product.sourceTopologyRegions(), certificate.region(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3524` | test | consumer/read | `sourceIsolationSheets` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `if (lineage.sourceIsolationSheets.size() <= 1U) continue;` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3526` | test | consumer/read | `sourceIsolationSheets` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `EXPECT_TRUE(std::is_sorted(lineage.sourceIsolationSheets.begin(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3527` | test | consumer/read | `sourceIsolationSheets` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourceIsolationSheets.end()));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3528` | test | consumer/read | `sourceCharts` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `EXPECT_TRUE(std::is_sorted(lineage.sourceCharts.begin(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3529` | test | consumer/read | `sourceCharts` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `lineage.sourceCharts.end()));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3530` | test | consumer/read | `equivalences` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `EXPECT_FALSE(lineage.equivalences.empty());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3542` | test | consumer/read | `vertexPositions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `for (int first = 0; first < result.mesh.vertexPositions.rows(); ++first) {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3543` | test | consumer/read | `vertexPositions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `for (int second = first + 1; second < result.mesh.vertexPositions.rows();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3545` | test | consumer/read | `vertexPositions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `if ((result.mesh.vertexPositions.row(first) -` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3546` | test | consumer/read | `vertexPositions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `result.mesh.vertexPositions.row(second))` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3554` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `if (firstLineage.sourceTopologyRegions !=` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3555` | test | consumer/read | `sourceTopologyRegions` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`; focused-12 ordinal 12 | `secondLineage.sourceTopologyRegions) {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3665` | test | consumer/read | `hash_completion` | `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`; selector449 row 436 | `EXPECT_EQ(directional::pipeline::hash_completion(baseline.mesh),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3666` | test | consumer/read | `hash_completion` | `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`; selector449 row 436 | `directional::pipeline::hash_completion(reordered.mesh));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3701` | test | consumer/read | `hash_completion` | `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`; selector449 row 437 | `EXPECT_EQ(directional::pipeline::hash_completion(baseline.mesh),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3702` | test | consumer/read | `hash_completion` | `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`; selector449 row 437 | `directional::pipeline::hash_completion(extended.mesh));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3717` | test | consumer/read | `selectedRelationPaths` | `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`; selector449 row 438 | `return !candidate.selectedRelationPaths.empty() &&` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3718` | test | consumer/read | `selectedRelationPaths` | `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`; selector449 row 438 | `!candidate.selectedRelationPaths.front().orderedSteps.empty();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3721` | test | consumer/read | `selectedRelationPaths` | `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`; selector449 row 438 | `auto &step = lineage->selectedRelationPaths.front().orderedSteps.front();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3729` | test | consumer/read | `sourceTopologyRegions` | `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`; selector449 row 438 | `&fixture.network.phaseFront.product().sourceTopologyRegions(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3927` | test | consumer/read | `sourceTopologyRegions` | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`; selector449 row 443 | `ASSERT_EQ(1U, product.sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:3997` | test | consumer/read | `sourceTopologyRegions` | `M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion`; selector449 row 449 | `const auto &sourceAuthority = product.sourceTopologyRegions();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4174` | test | consumer/read | `hash_completion` | `M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion`; selector449 row 449 | `EXPECT_EQ(directional::pipeline::hash_completion(baseline.mesh),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4175` | test | consumer/read | `hash_completion` | `M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion`; selector449 row 449 | `directional::pipeline::hash_completion(reordered.mesh));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4704` | test | consumer/read | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `const auto &sourceAuthority = product.sourceTopologyRegions();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4794` | test | consumer/read | `hash_completion` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_EQ(directional::pipeline::hash_completion(baseline.mesh),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4795` | test | consumer/read | `hash_completion` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `directional::pipeline::hash_completion(extended.mesh));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4932` | test | consumer/read | `sourcePoint` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_TRUE(lineage.sourcePoint.valid());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4933` | test | consumer/read | `sourceSupport` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_TRUE(lineage.sourceSupport.has_value());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4934` | test | consumer/read | `quotientClass` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_TRUE(lineage.quotientClass.has_value());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4938` | test | consumer/read | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_FALSE(lineage.sourceTopologyRegions.empty());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4939` | test | consumer/read | `sourceIsolationSheets` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_FALSE(lineage.sourceIsolationSheets.empty());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4940` | test | consumer/read | `sourceCharts` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_FALSE(lineage.sourceCharts.empty());` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4941` | test | consumer/read | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_TRUE(std::is_sorted(lineage.sourceTopologyRegions.begin(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4942` | test | consumer/read | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourceTopologyRegions.end()));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4943` | test | consumer/read | `sourceIsolationSheets` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_TRUE(std::is_sorted(lineage.sourceIsolationSheets.begin(),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4944` | test | consumer/read | `sourceIsolationSheets` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourceIsolationSheets.end()));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4946` | test | consumer/read | `sourceCharts` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `std::is_sorted(lineage.sourceCharts.begin(), lineage.sourceCharts.end()));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4948` | test | consumer/read | `equivalences` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `std::is_sorted(lineage.equivalences.begin(), lineage.equivalences.end()));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:4949` | test | consumer/read | `equivalences` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `for (const auto &equivalence : lineage.equivalences) {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5123` | test | producer/write-or-init | `sourceSupport` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `mutation.product().outputVertexLineage.front().sourceSupport =` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5136` | test | consumer/read | `sourcePoint` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourcePoint.component = 0;` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5137` | test | consumer/read | `sourcePoint` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourcePoint.sheet = 0;` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5138` | test | producer/write-or-init | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourceTopologyRegions = {test_topology_region_id(0)};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5139` | test | producer/write-or-init | `sourceIsolationSheets` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourceIsolationSheets = {test_isolation_sheet_id(0)};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5140` | test | producer/write-or-init | `sourceCharts` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourceCharts = {test_projection_chart(0, 0)};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5163` | test | producer/mutation-or-mixed | `equivalences` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `mutation.product().outputVertexLineage.front().equivalences.push_back(` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5251` | test | consumer/read | `vertexProvenance` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `for (auto &point : tampered.vertexProvenance) {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5256` | test | consumer/read | `sourcePoint` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourcePoint.component = 403;` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5257` | test | consumer/read | `sourcePoint` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourcePoint.sheet = 404;` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5264` | test | consumer/read | `hash_completion` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `EXPECT_EQ(directional::pipeline::hash_completion(materialized.mesh),` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5265` | test | consumer/read | `hash_completion` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `directional::pipeline::hash_completion(tampered));` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5276` | test | consumer/read | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `fixture.network.phaseFront.product().sourceTopologyRegions();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5299` | test | consumer/read | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `for (const auto region : lineage.sourceTopologyRegions) {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5304` | test | consumer/read | `sourceIsolationSheets` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `for (const auto sheet : lineage.sourceIsolationSheets) {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5309` | test | consumer/read | `sourceCharts` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `for (const auto &chart : lineage.sourceCharts) {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5323` | test | consumer/read | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `fixture.network.phaseFront.product().sourceTopologyRegions();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5331` | test | producer/write-or-init | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `baseline.sourceTopologyRegions = {domain->localRegionsByFace.front()};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5332` | test | producer/write-or-init | `sourceIsolationSheets` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `baseline.sourceIsolationSheets = {domain->localSheetsByFace.front()};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5333` | test | producer/write-or-init | `sourceCharts` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `baseline.sourceCharts = {domain->localChartsByFace.front()};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5334` | test | producer/write-or-init | `sourceSupport` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `baseline.sourceSupport =` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5348` | test | producer/write-or-init | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `unownedRegion.sourceTopologyRegions = {sparseRegion.value()};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5358` | test | producer/write-or-init | `sourceIsolationSheets` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `unownedSheet.sourceIsolationSheets = {sparseSheet.value()};` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5368` | test | producer/write-or-init | `sourceCharts` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `wrongChart.sourceCharts = {directional::geometry::SourceProjectionChart(` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5377` | test | producer/write-or-init | `sourceSupport` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `wrongFaceSupport.sourceSupport =` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5388` | test | consumer/read | `sourceSupport` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `incomplete.sourceSupport.reset();` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5497` | test | producer/write-or-init | `sourceTopologyRegions` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourceTopologyRegions = {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5499` | test | producer/write-or-init | `sourceIsolationSheets` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourceIsolationSheets = {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5501` | test | producer/write-or-init | `sourceCharts` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourceCharts = {` |
| `tests/SurfaceCellTransitionQuotientTests.cpp:5503` | test | producer/write-or-init | `sourceSupport` | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`; selector449 row 448 | `lineage.sourceSupport =` |
| `tests/SurfaceCellsPhase10Tests.cpp:125` | test | consumer/read | `sourceTopologyRegions` | enclosing GTest not statically recovered | `phaseFront.product().sourceTopologyRegions().regions().begin(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:126` | test | consumer/read | `sourceTopologyRegions` | enclosing GTest not statically recovered | `phaseFront.product().sourceTopologyRegions().regions().end(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:128` | test | consumer/read | `sourceTopologyRegions` | enclosing GTest not statically recovered | `if (found == phaseFront.product().sourceTopologyRegions().regions().end()) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:735` | test | producer/mutation-or-mixed | `vertexPositions` | `SurfaceCellsPhase10.DefectVisualizerColorsExactIssueReferences`; not in focused-12/selector449 | `mesh.vertexPositions.resize(5, 3);` |
| `tests/SurfaceCellsPhase10Tests.cpp:736` | test | consumer/read | `vertexPositions` | `SurfaceCellsPhase10.DefectVisualizerColorsExactIssueReferences`; not in focused-12/selector449 | `mesh.vertexPositions << 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0,` |
| `tests/SurfaceCellsPhase10Tests.cpp:751` | test | producer/mutation-or-mixed | `vertexProvenance` | `SurfaceCellsPhase10.GeometricTJunctionIgnoresDisconnectedCloseSheet`; not in focused-12/selector449 | `options.vertexProvenance.resize(5);` |
| `tests/SurfaceCellsPhase10Tests.cpp:753` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.GeometricTJunctionIgnoresDisconnectedCloseSheet`; not in focused-12/selector449 | `options.vertexProvenance[static_cast<std::size_t>(vertex)].face = 0;` |
| `tests/SurfaceCellsPhase10Tests.cpp:755` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.GeometricTJunctionIgnoresDisconnectedCloseSheet`; not in focused-12/selector449 | `options.vertexProvenance[4].face = 1;` |
| `tests/SurfaceCellsPhase10Tests.cpp:804` | test | producer/mutation-or-mixed | `vertexProvenance` | `SurfaceCellsPhase10.GeometricTJunctionIgnoresDisconnectedCloseSheet`; not in focused-12/selector449 | `options.vertexProvenance.resize(5);` |
| `tests/SurfaceCellsPhase10Tests.cpp:805` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.GeometricTJunctionIgnoresDisconnectedCloseSheet`; not in focused-12/selector449 | `options.vertexProvenance[0].face = 0;` |
| `tests/SurfaceCellsPhase10Tests.cpp:806` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.GeometricTJunctionIgnoresDisconnectedCloseSheet`; not in focused-12/selector449 | `options.vertexProvenance[1].face = 0;` |
| `tests/SurfaceCellsPhase10Tests.cpp:807` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.GeometricTJunctionIgnoresDisconnectedCloseSheet`; not in focused-12/selector449 | `options.vertexProvenance[4].face = 1;` |
| `tests/SurfaceCellsPhase10Tests.cpp:808` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.GeometricTJunctionIgnoresDisconnectedCloseSheet`; not in focused-12/selector449 | `for (auto &point : options.vertexProvenance) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:1741` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`; selector449 row 241 | `guidance.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:1753` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`; selector449 row 241 | `ASSERT_EQ(1U, guidance.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:2953` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`; selector449 row 241 | `ASSERT_EQ(2U, network.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:3044` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`; selector449 row 241 | `ASSERT_EQ(1U, network.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:3045` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`; selector449 row 241 | `EXPECT_FALSE(network.phaseFront.product().sourceTopologyRegions().regions().front()` |
| `tests/SurfaceCellsPhase10Tests.cpp:3051` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`; selector449 row 241 | `EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions().regions().front().id(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:3053` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`; selector449 row 241 | `EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions().regions().front()` |
| `tests/SurfaceCellsPhase10Tests.cpp:3066` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`; selector449 row 241 | `EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions().regions().front().id(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:3076` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`; selector449 row 241 | `EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions().regions().size(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:3176` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.CurvedBoundedDiskPhaseFrontIsStructurallyApplicable`; not in focused-12/selector449 | `const auto regionCount = product.sourceTopologyRegions().regions().size();` |
| `tests/SurfaceCellsPhase10Tests.cpp:3183` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.CurvedBoundedDiskPhaseFrontIsStructurallyApplicable`; not in focused-12/selector449 | `product.gridU(), product.gridV(), product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:3210` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.CurvedBoundedDiskPhaseFrontIsStructurallyApplicable`; not in focused-12/selector449 | `product.gridU(), product.gridV(), product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:4489` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_FALSE(network.phaseFront.product().sourceTopologyRegions().regions().empty());` |
| `tests/SurfaceCellsPhase10Tests.cpp:4490` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions().regions().size(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:4493` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `network.phaseFront.product().sourceTopologyRegions().face_count());` |
| `tests/SurfaceCellsPhase10Tests.cpp:4495` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `rowIndex < network.phaseFront.product().sourceTopologyRegions().face_count();` |
| `tests/SurfaceCellsPhase10Tests.cpp:4498` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `rowIndex, network.phaseFront.product().sourceTopologyRegions().face_count());` |
| `tests/SurfaceCellsPhase10Tests.cpp:4500` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_LT(network.phaseFront.product().sourceTopologyRegions()` |
| `tests/SurfaceCellsPhase10Tests.cpp:4502` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `network.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:4505` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `for (const auto &region : network.phaseFront.product().sourceTopologyRegions().regions()) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:4526` | test | consumer/read | `sourcePoint` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_TRUE(lineage.sourcePoint.valid());` |
| `tests/SurfaceCellsPhase10Tests.cpp:4527` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(lineage.sourceTopologyRegions.empty());` |
| `tests/SurfaceCellsPhase10Tests.cpp:4528` | test | consumer/read | `sourceIsolationSheets` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(lineage.sourceIsolationSheets.empty());` |
| `tests/SurfaceCellsPhase10Tests.cpp:4529` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(lineage.sourceCharts.empty());` |
| `tests/SurfaceCellsPhase10Tests.cpp:4530` | test | consumer/read | `sourceSupport` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_TRUE(lineage.sourceSupport.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5191` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_EQ(1U, network.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5193` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `const auto &region = network.phaseFront.product().sourceTopologyRegions().regions().front();` |
| `tests/SurfaceCellsPhase10Tests.cpp:5222` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_EQ(1U, network.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5223` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `const auto &region = network.phaseFront.product().sourceTopologyRegions().regions().front();` |
| `tests/SurfaceCellsPhase10Tests.cpp:5249` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_EQ(1U, network.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5250` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `const auto &region = network.phaseFront.product().sourceTopologyRegions().regions().front();` |
| `tests/SurfaceCellsPhase10Tests.cpp:5279` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_EQ(2U, network.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5329` | test | consumer/read | `sourcePoint` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `lineage.sourcePoint.component = token + 3;` |
| `tests/SurfaceCellsPhase10Tests.cpp:5330` | test | consumer/read | `sourcePoint` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `lineage.sourcePoint.sheet = token + 4;` |
| `tests/SurfaceCellsPhase10Tests.cpp:5337` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `for (auto &point : patch.vertexProvenance) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:5342` | test | consumer/read | `sourcePoint` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `lineage.sourcePoint.component = token + 11;` |
| `tests/SurfaceCellsPhase10Tests.cpp:5343` | test | consumer/read | `sourcePoint` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `lineage.sourcePoint.sheet = token + 12;` |
| `tests/SurfaceCellsPhase10Tests.cpp:5382` | test | consumer/read | `sourceSupport` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `if (!lineage.sourceSupport.has_value()) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:5385` | test | producer/mutation-or-mixed | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `rows.emplace_back(lineage.sourceTopologyRegions,` |
| `tests/SurfaceCellsPhase10Tests.cpp:5386` | test | consumer/read | `sourceIsolationSheets` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `lineage.sourceIsolationSheets,` |
| `tests/SurfaceCellsPhase10Tests.cpp:5387` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `lineage.sourceCharts,` |
| `tests/SurfaceCellsPhase10Tests.cpp:5388` | test | consumer/read | `sourceSupport` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `lineage.sourceSupport.value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5399` | test | producer/write-or-init | `vertexPositions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `semanticMesh.vertexPositions = value.product().vertices;` |
| `tests/SurfaceCellsPhase10Tests.cpp:5400` | test | producer/write-or-init | `vertexProvenance` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `semanticMesh.vertexProvenance = value.product().outputVertexProvenance;` |
| `tests/SurfaceCellsPhase10Tests.cpp:5415` | test | consumer/read | `hash_completion` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `return directional::pipeline::hash_completion(semanticMesh);` |
| `tests/SurfaceCellsPhase10Tests.cpp:5440` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_FALSE(lineage.sourceTopologyRegions.empty());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5441` | test | consumer/read | `sourceIsolationSheets` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_FALSE(lineage.sourceIsolationSheets.empty());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5442` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_FALSE(lineage.sourceCharts.empty());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5443` | test | consumer/read | `sourceSupport` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_TRUE(lineage.sourceSupport.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5444` | test | consumer/read | `sourcePoint` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `auto &sheets = lineage.sourcePoint.face < 2 ? firstComponentSheets` |
| `tests/SurfaceCellsPhase10Tests.cpp:5446` | test | consumer/read | `sourceIsolationSheets` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `for (const auto sheet : lineage.sourceIsolationSheets) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:5485` | test | producer/write-or-init | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `componentResult.product().outputVertexLineage.front().sourceTopologyRegions =` |
| `tests/SurfaceCellsPhase10Tests.cpp:5526` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `if (lineage.sourceTopologyRegions.empty()) continue;` |
| `tests/SurfaceCellsPhase10Tests.cpp:5535` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `lineage.sourceTopologyRegions.front(), equivalence.route,` |
| `tests/SurfaceCellsPhase10Tests.cpp:5548` | test | producer/mutation-or-mixed | `equivalences` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `lineage.equivalences.push_back(std::move(equivalence));` |
| `tests/SurfaceCellsPhase10Tests.cpp:5558` | test | consumer/read | `equivalences` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `for (const auto &equivalence : lineage.equivalences) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:5584` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_TRUE(result.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value())` |
| `tests/SurfaceCellsPhase10Tests.cpp:5588` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_TRUE(result.surfaceCellContext.productSnapshots.sourceTopologyRegions->matches_source_faces(` |
| `tests/SurfaceCellsPhase10Tests.cpp:5616` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_TRUE(result.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5618` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `result.surfaceCellContext.productSnapshots.sourceTopologyRegions.value();` |
| `tests/SurfaceCellsPhase10Tests.cpp:5772` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_TRUE(result.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:5774` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `result.surfaceCellContext.productSnapshots.sourceTopologyRegions.value();` |
| `tests/SurfaceCellsPhase10Tests.cpp:5996` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `result.surfaceCellContext.productSnapshots.sourceTopologyRegions;` |
| `tests/SurfaceCellsPhase10Tests.cpp:6048` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `product.gridU(), product.gridV(), product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6182` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `product.gridU(), product.gridV(), product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6202` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `product.gridU(), product.gridV(), product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6252` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `&fixture.mesh.F, &product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6314` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `&product.sourceTopologyRegions(), &fixture.hardFeatureEdges,` |
| `tests/SurfaceCellsPhase10Tests.cpp:6327` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `&fixture.mesh.F, &product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6340` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `for (const auto &chart : authority.sourceCharts) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:6347` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_GE(materialized.mesh.vertexLineage[row].sourceTopologyRegions.size(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6351` | test | consumer/read | `sourceIsolationSheets` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `materialized.mesh.vertexLineage[row].sourceIsolationSheets.size())` |
| `tests/SurfaceCellsPhase10Tests.cpp:6371` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `validationOptions.sourceAuthority = &product.sourceTopologyRegions();` |
| `tests/SurfaceCellsPhase10Tests.cpp:6372` | test | producer/write-or-init | `vertexProvenance` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `validationOptions.vertexProvenance = &materialized.mesh.vertexProvenance;` |
| `tests/SurfaceCellsPhase10Tests.cpp:6381` | test | consumer/read | `vertexPositions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `materialized.mesh.vertexPositions, outputQuads, validationOptions);` |
| `tests/SurfaceCellsPhase10Tests.cpp:6401` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `&product.sourceTopologyRegions(), &fixture.hardFeatureEdges,` |
| `tests/SurfaceCellsPhase10Tests.cpp:6413` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `&fixture.mesh.F, &product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6421` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `options.sourceAuthority = &product.sourceTopologyRegions();` |
| `tests/SurfaceCellsPhase10Tests.cpp:6422` | test | producer/write-or-init | `vertexProvenance` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `options.vertexProvenance = &materialized.mesh.vertexProvenance;` |
| `tests/SurfaceCellsPhase10Tests.cpp:6430` | test | consumer/read | `vertexPositions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `materialized.mesh.vertexPositions, outputQuads, options);` |
| `tests/SurfaceCellsPhase10Tests.cpp:6447` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `chartGraph.chart(materialized.mesh.vertexProvenance[row].face);` |
| `tests/SurfaceCellsPhase10Tests.cpp:6453` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `const std::size_t before = authority.sourceCharts.size();` |
| `tests/SurfaceCellsPhase10Tests.cpp:6454` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.erase(` |
| `tests/SurfaceCellsPhase10Tests.cpp:6455` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `std::remove_if(authority.sourceCharts.begin(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6456` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.end(), [&](const auto &chart) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:6460` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.end());` |
| `tests/SurfaceCellsPhase10Tests.cpp:6461` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `mutated = authority.sourceCharts.size() < before;` |
| `tests/SurfaceCellsPhase10Tests.cpp:6488` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `chartGraph.chart(materialized.mesh.vertexProvenance[row].face);` |
| `tests/SurfaceCellsPhase10Tests.cpp:6506` | test | producer/mutation-or-mixed | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.push_back(candidate.value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:6507` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `std::sort(authority.sourceCharts.begin(), authority.sourceCharts.end());` |
| `tests/SurfaceCellsPhase10Tests.cpp:6508` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.erase(` |
| `tests/SurfaceCellsPhase10Tests.cpp:6509` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `std::unique(authority.sourceCharts.begin(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6510` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.end()),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6511` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.end());` |
| `tests/SurfaceCellsPhase10Tests.cpp:6587` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_TRUE(result.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:6589` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `result.surfaceCellContext.productSnapshots.sourceTopologyRegions.value();` |
| `tests/SurfaceCellsPhase10Tests.cpp:6603` | test | consumer/read | `equivalences` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `for (const auto &equivalence : lineage.equivalences) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:6615` | test | consumer/read | `sourcePoint` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `const auto support = supportResolver.resolve(lineage.sourcePoint);` |
| `tests/SurfaceCellsPhase10Tests.cpp:6618` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `for (const auto &chart : lineage.sourceCharts) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:6630` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_GE(lineage.sourceTopologyRegions.size(), 2U)` |
| `tests/SurfaceCellsPhase10Tests.cpp:6632` | test | consumer/read | `sourceIsolationSheets` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_EQ(1U, lineage.sourceIsolationSheets.size())` |
| `tests/SurfaceCellsPhase10Tests.cpp:6680` | test | producer/write-or-init | `vertexProvenance` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `validationOptions.vertexProvenance == nullptr \|\|` |
| `tests/SurfaceCellsPhase10Tests.cpp:6693` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.size() < 2U) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:6697` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.erase(` |
| `tests/SurfaceCellsPhase10Tests.cpp:6698` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.begin() + 1,` |
| `tests/SurfaceCellsPhase10Tests.cpp:6699` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.end());` |
| `tests/SurfaceCellsPhase10Tests.cpp:6706` | test | consumer/read | `vertexProvenance` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `(*validationOptions.vertexProvenance)[row];` |
| `tests/SurfaceCellsPhase10Tests.cpp:6728` | test | producer/mutation-or-mixed | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.push_back(candidate.value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:6729` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `std::sort(authority.sourceCharts.begin(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6730` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.end());` |
| `tests/SurfaceCellsPhase10Tests.cpp:6731` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.erase(` |
| `tests/SurfaceCellsPhase10Tests.cpp:6732` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `std::unique(authority.sourceCharts.begin(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6733` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.end()),` |
| `tests/SurfaceCellsPhase10Tests.cpp:6734` | test | consumer/read | `sourceCharts` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `authority.sourceCharts.end());` |
| `tests/SurfaceCellsPhase10Tests.cpp:6792` | test | consumer/read | `equivalences` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `for (const auto &equivalence : lineage.equivalences) {` |
| `tests/SurfaceCellsPhase10Tests.cpp:7075` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(rejected.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:7118` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(rejected.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:7166` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(rejected.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:7242` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(rejected.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:7309` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(rejected.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:7455` | test | producer/write-or-init | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `componentResult.product().outputVertexLineage.front().sourceTopologyRegions =` |
| `tests/SurfaceCellsPhase10Tests.cpp:7468` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(rejected.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:7525` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_FALSE(rejected.surfaceCellContext.productSnapshots.sourceTopologyRegions.has_value());` |
| `tests/SurfaceCellsPhase10Tests.cpp:7547` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `network.phaseFront.product().sourceTopologyRegions();` |
| `tests/SurfaceCellsPhase10Tests.cpp:7666` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `const auto &regions = product.sourceTopologyRegions().regions();` |
| `tests/SurfaceCellsPhase10Tests.cpp:7709` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_EQ(2U, network.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:7714` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `const auto regionCount = product.sourceTopologyRegions().regions().size();` |
| `tests/SurfaceCellsPhase10Tests.cpp:7719` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `product.sourceTopologyRegions().regions().begin(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:7720` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `product.sourceTopologyRegions().regions().end(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:7724` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `product.gridU(), product.gridV(), product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:7751` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_EQ(2U, network.phaseFront.product().sourceTopologyRegions().regions().size());` |
| `tests/SurfaceCellsPhase10Tests.cpp:7758` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `product.sourceTopologyRegions().regions().begin(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:7759` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `product.sourceTopologyRegions().regions().end(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:7761` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `ASSERT_NE(product.sourceTopologyRegions().regions().end(), replacement);` |
| `tests/SurfaceCellsPhase10Tests.cpp:7764` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `product.gridU(), product.gridV(), product.sourceTopologyRegions(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:7837` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions().regions().size(),` |
| `tests/SurfaceCellsPhase10Tests.cpp:7840` | test | consumer/read | `sourceTopologyRegions` | `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`; selector449 row 250 | `network.phaseFront.product().sourceTopologyRegions().face_count());` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:297` | test | producer/mutation-or-mixed | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.ProjectionDoesNotJumpAcrossComponents`; not in focused-12/selector449 | `constraints.vertexProvenance.resize(4);` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:299` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.ProjectionDoesNotJumpAcrossComponents`; not in focused-12/selector449 | `auto &point = constraints.vertexProvenance[static_cast<std::size_t>(vertex)];` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:381` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.ProjectsToSourceTrianglesWithProvenance`; not in focused-12/selector449 | `ASSERT_EQ(result.vertexProvenance.size(), 4U);` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:385` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.ProjectsToSourceTrianglesWithProvenance`; not in focused-12/selector449 | `for (const auto &point : result.vertexProvenance) {` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:647` | test | producer/mutation-or-mixed | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.FinalValidationUsesAuthorityOptions`; selector449 row 261 | `constraints.vertexProvenance.resize(4);` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:648` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.FinalValidationUsesAuthorityOptions`; selector449 row 261 | `for (auto &point : constraints.vertexProvenance) {` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:663` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.FinalValidationUsesAuthorityOptions`; selector449 row 261 | `ASSERT_EQ(result.vertexProvenance.size(), 4U);` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:664` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.FinalValidationUsesAuthorityOptions`; selector449 row 261 | `EXPECT_TRUE(result.vertexProvenance[0].valid());` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:665` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.FinalValidationUsesAuthorityOptions`; selector449 row 261 | `EXPECT_EQ(result.vertexProvenance[0].component, 0);` |
| `tests/SurfaceMeshOptimizerPhase19Tests.cpp:666` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase19.FinalValidationUsesAuthorityOptions`; selector449 row 261 | `EXPECT_EQ(result.vertexProvenance[0].sheet, 2);` |
| `tests/SurfaceMeshOptimizerPhase20Tests.cpp:243` | test | producer/mutation-or-mixed | `vertexProvenance` | enclosing GTest not statically recovered | `constraints.vertexProvenance.resize(4);` |
| `tests/SurfaceMeshOptimizerPhase20Tests.cpp:246` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `constraints.vertexProvenance[static_cast<std::size_t>(vertex)] =` |
| `tests/SurfaceMeshOptimizerPhase20Tests.cpp:248` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `constraints.vertexProvenance[static_cast<std::size_t>(vertex)].component = 0;` |
| `tests/SurfaceMeshOptimizerPhase20Tests.cpp:249` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `constraints.vertexProvenance[static_cast<std::size_t>(vertex)].sheet = 3;` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:184` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance = project_provenance(output, constraints);` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:238` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance, constraints);` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:285` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `oneProvenance[0] = optimization.vertexProvenance[0];` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:326` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance = project_provenance(source, constraints);` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:337` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance, constraints);` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:395` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance = project_provenance(output, constraints);` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:396` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `for (auto &point : optimization.vertexProvenance) {` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:431` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance = project_provenance(output, constraints);` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:432` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `ASSERT_EQ(optimization.vertexProvenance.size(), 4U);` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:433` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance[0].sheet = 0;` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:434` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance[1].sheet = 1;` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:435` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance[2].sheet = 0;` |
| `tests/SurfaceMeshOptimizerPhase21Tests.cpp:436` | test | consumer/read | `vertexProvenance` | enclosing GTest not statically recovered | `optimization.vertexProvenance[3].sheet = 1;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:97` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `options.vertexProvenance = &provenance;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:120` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `constraints.vertexProvenance = provenance;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:206` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `for (auto &chart : vertexAuthority.sourceCharts) {` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:217` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `std::sort(vertexAuthority.sourceCharts.begin(),` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:218` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `vertexAuthority.sourceCharts.end());` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:303` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `authority.sourceCharts.push_back(source_chart(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:312` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `authority.sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:315` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `std::sort(authority.sourceCharts.begin(), authority.sourceCharts.end());` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:359` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `authority.sourceCharts.push_back(source_chart(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:372` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `center.sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:375` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `center.sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:378` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `center.sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:384` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `bToCPeer.sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:390` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `aToBPeer.sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:396` | test | producer/mutation-or-mixed | `sourceCharts` | enclosing GTest not statically recovered | `aToDPeer.sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:402` | test | consumer/read | `sourceCharts` | enclosing GTest not statically recovered | `std::sort(authority.sourceCharts.begin(), authority.sourceCharts.end());` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:451` | test | producer/write-or-init | `vertexProvenance` | enclosing GTest not statically recovered | `constraints.vertexProvenance = fixture.provenance;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:706` | test | producer/write-or-init | `vertexProvenance` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `optimization.vertexProvenance = provenance;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:766` | test | producer/write-or-init | `vertexProvenance` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `constraints.vertexProvenance = provenance_for(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:799` | test | producer/mutation-or-mixed | `vertexProvenance` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `options.vertexProvenance.resize(4);` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:801` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `auto &point = options.vertexProvenance[static_cast<std::size_t>(vertex)];` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:811` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `options.vertexProvenance[3].component = 701;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:812` | test | consumer/read | `vertexProvenance` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `options.vertexProvenance[3].sheet = 907;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:936` | test | producer/write-or-init | `vertexProvenance` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `optimization.vertexProvenance = provenance;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1004` | test | producer/write-or-init | `vertexProvenance` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `constraints.vertexProvenance = provenance;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1112` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `auto &peerCharts = fixture.authority[5].sourceCharts;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1184` | test | producer/mutation-or-mixed | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `unsupported.authority[1].sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1187` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `std::sort(unsupported.authority[1].sourceCharts.begin(),` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1188` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `unsupported.authority[1].sourceCharts.end());` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1237` | test | producer/mutation-or-mixed | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `authority[vertex].sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1249` | test | producer/mutation-or-mixed | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `authority[static_cast<std::size_t>(vertex)].sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1260` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `std::sort(vertexAuthority.sourceCharts.begin(),` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1261` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `vertexAuthority.sourceCharts.end());` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1302` | test | producer/mutation-or-mixed | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `authority[vertex].sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1305` | test | producer/mutation-or-mixed | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `authority[0].sourceCharts.push_back(` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1307` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `std::sort(authority[0].sourceCharts.begin(),` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1308` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `authority[0].sourceCharts.end());` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1334` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `original.authority[static_cast<std::size_t>(vertex)].sourceCharts;` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1369` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `EXPECT_EQ(original.authority[static_cast<std::size_t>(vertex)].sourceCharts,` |
| `tests/SurfaceMeshOptimizerPhase22Tests.cpp:1370` | test | consumer/read | `sourceCharts` | `SurfaceMeshOptimizerPhase22.MissingHardFeatureRailEdgeFailsClosed`; selector449 row 275 | `reversed.authority[static_cast<std::size_t>(vertex)].sourceCharts);` |
| `tests/support/SurfaceCellProductOracle.cpp:638` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `sourceValid = valid_source_point(lineage.sourcePoint, sourceFaces,` |
| `tests/support/SurfaceCellProductOracle.cpp:754` | test | consumer/read | `sourcePoint` | enclosing GTest not statically recovered | `lineage->sourcePoint, sourceVertices,` |
