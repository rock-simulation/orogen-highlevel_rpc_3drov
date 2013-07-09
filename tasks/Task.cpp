/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "Task.hpp"

using namespace highlevel_rpc_3drov;
using namespace VdalRpcIfClientNamespace;

extern VdalRpcIfClientNamespace::RpcIfClient *getVdalRpcIfClient();

Task::Task(std::string const& name)
    : TaskBase(name)
{
    toto = NULL;
}

Task::Task(std::string const& name, RTT::ExecutionEngine* engine)
    : TaskBase(name, engine)
{
    toto = NULL;
}

Task::~Task()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See Task.hpp for more detailed
// documentation about them.

bool Task::configureHook()
{
    if (! TaskBase::configureHook())
        return false;

    if (toto == NULL)
        toto = getVdalRpcIfClient();

    return true;
}
bool Task::startHook()
{
    if (! TaskBase::startHook())
        return false;
    return true;
}
void Task::updateHook()
{
    TaskBase::updateHook();

    if (toto != NULL)
    {
        std::cerr << toto->gettick() << std::endl;
        std::cerr << toto->inc_getdata() << std::endl;
        toto->inc_open();
        toto->inc_close();
        std::cerr << toto->imu_getdata() << std::endl;
        toto->imu_open();
        toto->imu_close();
        std::cerr << toto->sun_getdata() << std::endl;
        toto->sun_open();
        toto->sun_close();
        toto->cam_open(41);
        toto->cam_close(41);
        toto->loc_wheel(0.1, 0.1, 0.1, 0.1, 10, 10, 10, 10);
        toto->loc_wheel_move(2, 0.5);
        toto->loc_steer_moveto(2, -10.0);
        //toto->loc_stop();
        std::cerr << toto->getpos_rover() << std::endl;
        std::cerr << toto->getloc() << std::endl;
        toto->loc_open();
        toto->loc_close();
        toto->ptu_moveto(15.0, 17.0, 1);
        //toto->ptu_open();
        //toto->ptu_close();
        std::cerr << toto->ptu_getdata() << std::endl;
        toto->arm_joint_moveto(2, 67, 3);
        toto->arm_moveto(10, 20, 30, 40, 50, 3);
        toto->arm_stop();
        std::cerr << toto->getarm() << std::endl;
        toto->arm_open();
        toto->arm_close();
        //char *tof_getdem();
        toto->tof_open(); 
        toto->tof_close();
        //char *gnc_getdem();

    }
}
void Task::errorHook()
{
    TaskBase::errorHook();
}
void Task::stopHook()
{
    TaskBase::stopHook();
}
void Task::cleanupHook()
{
    TaskBase::cleanupHook();
}
