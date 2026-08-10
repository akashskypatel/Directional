from pathlib import Path

SOURCE = Path("src/geometry/SurfaceCellTracing.cpp")
TESTS = Path("tests/SurfaceCellsPhase10Tests.cpp")

source = SOURCE.read_text()
tests = TESTS.read_text()

source_replacements = {
    """          authority::GridAutomorphism{
              authority::QuarterTurn::from_integer(transition.matching),
              Eigen::Vector2i::Zero()},
""": """          authority::GridAutomorphism{
              authority::QuarterTurn::from_integer(transition.matching),
              authority::LatticeTranslation{0, 0}},
""",
    """    authority::GridAutomorphism routeTransport{
        authority::QuarterTurn::from_integer(0), Eigen::Vector2i::Zero()};
""": """    authority::GridAutomorphism routeTransport =
        authority::GridAutomorphism::identity();
""",
    """      routeTransport = authority::compose(step.transport(), routeTransport);
""": """      routeTransport = compose(step.transport(), routeTransport);
""",
}
for old, new in source_replacements.items():
    if source.count(old) != 1:
        raise SystemExit(f"unexpected source correction anchor count for: {old[:80]!r}")
    source = source.replace(old, new, 1)

test_replacements = {
    """  GridAutomorphism total{QuarterTurn::from_integer(0),
                         Eigen::Vector2i::Zero()};
""": """  GridAutomorphism total = GridAutomorphism::identity();
""",
    """    total = directional::authority::compose(
        GridAutomorphism{QuarterTurn::from_integer(matching),
                         Eigen::Vector2i::Zero()},
        total);
""": """    total = compose(
        GridAutomorphism{QuarterTurn::from_integer(matching),
                         directional::authority::LatticeTranslation{0, 0}},
        total);
""",
}
for old, new in test_replacements.items():
    if tests.count(old) != 1:
        raise SystemExit(f"unexpected test correction anchor count for: {old[:80]!r}")
    tests = tests.replace(old, new, 1)

SOURCE.write_text(source)
TESTS.write_text(tests)
