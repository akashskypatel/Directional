# Field comparison report format

Directional field comparisons can be saved as a three-file report bundle. The
selected JSON path is the bundle entry point.

- `*.fieldcmp.json`: versioned metadata and aggregate metrics.
- `*.fieldcmp.faces.csv`: one row per input triangle for spatial analysis.
- `*.fieldcmp.heatmap.ply`: triangle-soup heatmap for external viewers.

## JSON identity

```json
{
  "schema": "directional.field-comparison",
  "schema_version": 1
}
```

Readers should reject an unknown `schema` and select a parser from
`schema_version`. Paths in `artifacts` are relative to the JSON report.

## Candidate and reference roles

The **candidate** is the automatically calculated Directional field. The
**reference** is the uploaded field, normally the NeurCross/FNN result. The
report stores the candidate algorithm parameter snapshot captured when the
candidate field was generated, not the current values of the GUI controls.

## Recommended optimization objective

`comparison.primary_objective` is the area-weighted mean squared chordal error
between the degree-4 complex representatives:

```text
|q_candidate^4 - q_reference^4|^2
```

It is invariant to branch signs, branch permutations, and 90-degree cross
rotations. Its range is `[0, 4]`, and lower is better. Unlike raw angular error,
it is continuous at the 4-RoSy branch boundary, making it suitable as the
primary scalar for parameter sweeps.

Do not optimize only this scalar. Track these secondary diagnostics to prevent
a lower average from hiding regressions:

- `angular_error_degrees.weighted_rms` and `p95` for the error tail.
- `high_error.area_fraction` and connected components for localized failures.
- `smoothness.*` to distinguish matching the reference from over-smoothing.
- `topology.*` for singularity count, index, and location agreement.
- `shape_operator_alignment.*` when proxy-shape scoring is enabled.

## Per-face CSV

The CSV columns are:

```text
face_index
centroid_x, centroid_y, centroid_z
face_area
cross_field_difference_degrees
signed_difference_degrees
q4_squared_chordal_error
high_error
high_error_component
```

Optional shape-operator columns are appended when enabled. Face indices match
the input triangle order. `high_error_component` is `-1` outside the threshold
mask; non-negative IDs are deterministic connected-component IDs.

## Topology diagnostics

Singularity indices are represented by integer numerators divided by four.
Exact vertex/index mismatches are reported along with same-index nearest
singularity distances normalized by the mesh average edge length. Topology
extraction failures do not invalidate the orientation comparison; the report
sets `topology.available` to `false` and records the diagnostic error.
