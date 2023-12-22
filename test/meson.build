gtest_proj = subproject ('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

src_dir = meson.source_root() / 'src'
src = []
foreach ext : ['cpp', 'h']
  r = run_command('find', src_dir, '-name', '*.' + ext)
  src += files(r.stdout().strip().split('\n'))
endforeach

test_dir = meson.current_source_dir()
test_src = []
foreach ext : ['cpp', 'h']
  r = run_command('find', test_dir, '-name', '*.' + ext)
  test_src += files(r.stdout().strip().split('\n'))
endforeach

inc_dirs = include_directories('../src', '../src/core', '../src/Password', '../src/Engine')

ApplicationTest_exe = executable('ApplicationTest',
'ApplicationTest.cpp', src, include_directories : inc_dirs,
  dependencies : [
    gtest_dep,
    gmock_dep],
)

PasswordTest_exe = executable('PasswordTest',
'PasswordTest.cpp', src, include_directories : inc_dirs,
  dependencies : [
    gtest_dep,
    gmock_dep],
)

EngineTest_exe = executable('EngineTest',
'EngineTest.cpp', src, include_directories : inc_dirs,
  dependencies : [
    gtest_dep,
    gmock_dep],
)
#test('pwgen_test', test_exe)

test('ApplicationTest', ApplicationTest_exe)

test ('PasswordTest', PasswordTest_exe)

test('EngineTest', EngineTest_exe)
