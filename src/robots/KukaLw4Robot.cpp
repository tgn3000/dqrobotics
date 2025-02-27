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

#ifndef DQ_ROBOTICS_KUKKA_DH_H
#define DQ_ROBOTICS_KUKKA_DH_H

#include<dqrobotics/robots/KukaLw4Robot.h>

namespace DQ_robotics
{

DQ_SerialManipulator KukaLw4Robot::kinematics()
{
    const double pi2 = M_PI_2;

    Matrix<double,4,7> kukka_dh(4,7);
    kukka_dh <<  0,     0,     0,   0,   0,    0,   0,
                 0.310, 0,     0.4, 0,   0.39, 0,   0,
                 0,     0,     0,   0,   0,    0,   0,
                 pi2,   -pi2, -pi2, pi2, pi2, -pi2, 0;
    DQ_SerialManipulator kukka(kukka_dh,"standard");

    return kukka;
}

}

#endif
