from pathlib import Path

path = Path('src/geometry/SurfaceArrangement.cpp')
text = path.read_text(encoding='utf-8')
old = '''        }\n        }\n\n        if (candidateNext[static_cast<std::size_t>(exteriorIncoming)] !=\n'''
new = '''        }\n\n        if (candidateNext[static_cast<std::size_t>(exteriorIncoming)] !=\n'''
count = text.count(old)
if count != 1:
    raise RuntimeError(f'expected one duplicated higher-valence scope close, found {count}')
path.write_text(text.replace(old, new, 1), encoding='utf-8')
