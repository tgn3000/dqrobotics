/**
(C) Copyright 2019 DQ Robotics Developers

This file is part of DQ Robotics.

    DQ Robotics is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DQ Robotics is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with DQ Robotics.  If not, see <http://www.gnu.org/licenses/>.

Contributors:
- Murilo M. Marinho (murilo@nml.t.u-tokyo.ac.jp)
*/
#include<dqrobotics/robots/Ax18ManipulatorRobot.h>

namespace DQ_robotics
{

DQ_SerialManipulator Ax18ManipulatorRobot::kinematics()
{
    const double pi2 = M_PI_2;

    Matrix<double,5,5> ax18_dh(5,5);
    ax18_dh <<   0,    0,   -pi2,  -pi2,   -pi2,
    0.167,  0,    0,    0.1225,    0,
    0,    0.159,   0.02225,  0 ,   0,
    -pi2,  0,   -pi2,      -pi2,    0,
    0,    0,    0,    0,           0;

    DQ_SerialManipulator ax18(ax18_dh,"standard");

    return ax18;
}

}
