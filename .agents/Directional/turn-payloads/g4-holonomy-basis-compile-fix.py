from pathlib import Path

path = Path("src/pipeline/RemeshPipeline.cpp")
text = path.read_text()
old = """void hash_vector(std::uint64_t &seed, const std::vector<int> &values) {
  hash_combine_u64(seed, values.size());
  for (const int value : values) {
    hash_combine_i64(seed, value);
  }
}
"""
new = old + """
void hash_vector(std::uint64_t &seed,
                 const std::vector<std::uint64_t> &values) {
  hash_combine_u64(seed, values.size());
  for (const std::uint64_t value : values) {
    hash_combine_u64(seed, value);
  }
}
"""
if text.count(old) != 1:
    raise RuntimeError("expected exactly one integer-vector hash overload")
path.write_text(text.replace(old, new, 1))
print("G4 periodic topology hash compile fix applied")
