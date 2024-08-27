

#Source('main.cc')
#Source('car/tick.cc')

Import('*')
env = Environment()

env.Append(CPPPATH = ['car'])

source_files = ['main.cc', 'car/tick.cc', 'car/car.cc',  'test/car_test.cc', 'path/straight_defpath.cc',
                'control/base/matrix.cc', 'control/mpc/cost_func_Kinematics.cc', 'control/mpc/cost_func.cc',
                'control/mpc/testmpc.cc', 'control/interact.cc', 'simulate/simulate.cc',  'test/mpc.cc', 
                'control/mpc/state_ref.cc', 'path/imtpath.cc', 'control/mpc/solver.cc']

obj = [env.Object([sc for sc in source_files])]
env.Program(target = 'carsim', source = obj)
Return('obj')
