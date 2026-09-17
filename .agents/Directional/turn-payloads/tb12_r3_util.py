import hashlib,os,pathlib,stat
def sha(p):
 h=hashlib.sha256()
 with open(p,'rb') as f:
  for b in iter(lambda:f.read(1<<20),b''): h.update(b)
 return h.hexdigest()
def census(root,out):
 root=pathlib.Path(root); rows=[]
 for p in [root,*sorted(root.rglob('*'),key=lambda q:q.relative_to(root).as_posix())]:
  rel='.' if p==root else p.relative_to(root).as_posix(); st=p.lstat(); mode=oct(stat.S_IMODE(st.st_mode))[2:]
  if stat.S_ISREG(st.st_mode): kind='file'; dig=sha(p); target='-'
  elif stat.S_ISDIR(st.st_mode): kind='directory'; dig=target='-'
  elif stat.S_ISLNK(st.st_mode): kind='symlink'; dig='-'; target=os.readlink(p)
  else: kind='other'; dig=target='-'
  rows.append(f'{rel}\t{kind}\t{mode}\t{st.st_size}\t{dig}\t{target}\n')
 pathlib.Path(out).write_text(''.join(rows))

TG=['directional_surface_cell_authority_kernel_tests','directional_surface_cell_producer_tests','directional_surface_cell_completion_tests','directional_surface_cell_validation_tests']
