/**
(C) Copyright 2011-2018 DQ Robotics Developers

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
- Mateus Rodrigues Martins (martinsrmateus@gmail.com)
*/

#include<dqrobotics/legacy/DQ_kinematics.h>
#include<dqrobotics/DQ.h>

namespace DQ_robotics
{

/****************************************************************
**************NAMESPACE ONLY FUNCTIONS***************************
*****************************************************************/

/**
*/
int n_links( const DQ_kinematics& dq_kin)
{
    return dq_kin.n_links();
}

/**
* Returns a constant vector representing the theta joint angles offset of a robotic system.
*/
VectorXd  theta( const DQ_kinematics& dq_kin)
{
    return dq_kin.theta();
}

/**
* Returns a constant vector representing each 'd' offset along previous z to the common normal of a robotic system DQ_kinematics object.
*/
VectorXd  d( const DQ_kinematics& dq_kin)
{
    return dq_kin.d();
}

/**
* Returns a constant vector representing each 'a' length of the common normal of a robotic system DQ_kinematics object.
*/
VectorXd  a( const DQ_kinematics& dq_kin)
{
    return dq_kin.a();
}

/**
* Returns a constant vector representing each 'alpha' angle about common normal, from old z axis to new z axis of a
* robotic system DQ_kinematics object.
*/
VectorXd  alpha( const DQ_kinematics& dq_kin)
{
    return dq_kin.alpha();
}

/**
* Returns a constant vector representing the existing 'dummy' axes of a robotic system DQ_kinematics object.
*/
VectorXd  dummy( const DQ_kinematics& dq_kin)
{
    return dq_kin.dummy();
}

/**
* Returns a constant int representing the number of 'dummy' axes of a robotic system DQ_kinematics object.
*/
int  n_dummy( const DQ_kinematics& dq_kin)
{
    return dq_kin.n_dummy();
}

/**
* Returns a constant std::string representing the Denavit Hartenberg convenction (standard or modified) used in a robotic system
* DQ_kinematics object.
*/
std::string  convention( const DQ_kinematics& dq_kin)
{
    return dq_kin.convention();
}

/**
* Returns a constant DQ object representing current defined base of a robotic system DQ_kinematics object.
*/
DQ  base( const DQ_kinematics& dq_kin)
{
    return dq_kin.base();
}

/**
* Returns a constant DQ object representing current defined end effector of a robotic system DQ_kinematics object.
*/
DQ  effector( const DQ_kinematics& dq_kin)
{
    return dq_kin.effector();
}


/**
* Sets, by new_base parameter, the pose of current base of a robotic system DQ_kinematics object and returns it in a constant DQ object.
*/
DQ  set_base( DQ_kinematics& dq_kin, const DQ& new_base)
{
    return dq_kin.set_base(new_base);
}


/**
* Sets, by new_effector parameter, the pose of current end effector of a robotic system DQ_kinematics object and returns it in a constant DQ object.
*/
DQ  set_effector(DQ_kinematics& dq_kin, const DQ& new_effector)
{
    return dq_kin.set_effector(new_effector);
}

/**
* Calculates the forward kinematic model and returns a DQ object corresponding to the last joint.
*/
DQ  raw_fkm( const DQ_kinematics& dq_kin, const VectorXd& theta_vec)
{
    return dq_kin.raw_fkm(theta_vec);
}

/**
* Calculates the forward kinematic model and returns a DQ object corresponding to the ith joint.
*/
DQ  raw_fkm( const DQ_kinematics& dq_kin, const VectorXd& theta_vec, const int& ith)
{
    return dq_kin.raw_fkm(theta_vec, ith);
}


/**
* Calculates the forward kinematic model and returns a DQ object corresponding to the last joint
*/
DQ  fkm(DQ_kinematics dq_kin, VectorXd theta_vec)
{
    return dq_kin.fkm(theta_vec);
}

/**
* Calculates the forward kinematic model and returns a DQ object corresponding to the ith joint.

*/
DQ  fkm(DQ_kinematics dq_kin, VectorXd theta_vec, int ith)
{
    return dq_kin.fkm(theta_vec, ith);
}


/** Returns the correspondent DQ object, for a given link's Denavit Hartenberg parameters.
*/
DQ  dh2dq( const DQ_kinematics& dq_kin, const double& theta_ang, const int& link_i)
{
    return dq_kin.dh2dq(theta_ang, link_i);
}

DQ  get_z( const DQ_kinematics& dq_kin, const VectorXd& q)
{
    return dq_kin.get_z(q);
}

/** 
Returns a MatrixXd 8x(links - n_dummy) representing the Jacobian of a robotic system DQ_kinematics object.
*/
MatrixXd  pose_jacobian( const DQ_kinematics& dq_kin, const VectorXd& theta_vec)
{
    return dq_kin.pose_jacobian(theta_vec);
}

MatrixXd pose_jacobian(const DQ_kinematics& dq_kin, const VectorXd& theta_vec, const int& to_link)
{
    return dq_kin.pose_jacobian(theta_vec,to_link);
}

MatrixXd raw_pose_jacobian( const DQ_kinematics& dq_kin, const VectorXd& theta_vec, const int& to_link)
{
    return dq_kin.raw_pose_jacobian(theta_vec,to_link);
}

/**
* Obtains the rotation jacobian, relating the derivative of the rotation quaternion to the derivative of the joint variables as being the first 4 rows of the analytical jacobian.
* \param MatrixXd pose_jacobian The robot analytical jacobian.
* \return The rotation jacobian.
*/
MatrixXd  rotation_jacobian( const MatrixXd& pose_jacobian)
{
    return pose_jacobian.block(0,0,4,pose_jacobian.cols());
}

/** Returns the translation Jacobian; that it, the Jacobian that satisfies the relation dot_p = Jp * dot_theta.
* Where dot_p is the time derivative of the translation quaternion and dot_theta is the time derivative of the joint vector.
* To use this member function type: 'dh_matrix__object.jacobp(param_jacobian, x).
* \param Eigen::MatrixXd param_jacobian is the Jacobian of a robotic system
* \param Eigen::Matrix<double,8,1> x is the vector which constructs a translation DQ object
* \return A constant Eigen::MatrixXd
*/
MatrixXd  translation_jacobian(const MatrixXd& pose_jacobian, const DQ &x)
{
    DQ dq_x(x);
    DQ dq_x_conj_P = dq_x.P();
    dq_x_conj_P = dq_x_conj_P.conj();
    MatrixXd aux_J1(4,pose_jacobian.cols());
    MatrixXd aux_J2(4,pose_jacobian.cols());
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < pose_jacobian.cols(); j++) {
            aux_J1(i,j) = pose_jacobian(i,j);
            aux_J2(i,j) = pose_jacobian((i+4),j);
        }
    }
    MatrixXd aux = hamiplus4(dq_x.D())*C4();
    MatrixXd Jp = 2*(haminus4(dq_x_conj_P)*aux_J2) + 2*(aux*aux_J1);
    return Jp;
}

/**
 * @brief The line Jacobian given the \p rotation_jacobian, the \p translation_jacobian, the \p pose, and a \p line_direction
 * @param rotation_jacobian the current rotation Jacobian \see rotation_jacobian()
 * @param translation_jacobian the current translation Jacobian \see translation_jacobian()
 * @param pose the current end-effector pose \see fkm()
 * @param line_direction the line direction w.r.t. the \p pose reference frame. For example using i_, j_, and k_
 * will return the line Jacobian collinear with, respectively, the x-axis, y-axis, and z-axis of \p pose,
 */
MatrixXd line_jacobian(const MatrixXd& pose_jacobian, const DQ& pose, const DQ& line_direction)
{
    /// Aliases
    const DQ&       x  = pose;
    const MatrixXd& Jt = translation_jacobian(pose_jacobian,pose);
    const MatrixXd& Jr = rotation_jacobian(pose_jacobian);

    ///Translation
    const DQ xt = translation(x);

    ///Rotation and Rotation Jacobian
    const DQ xr = rotation(x);

    ///Line direction w.r.t. base
    const DQ l = xr*(line_direction)*conj(xr);

    ///Line direction and moment Jacobians
    const MatrixXd Jrx = haminus4(line_direction*conj(xr))*Jr + hamiplus4(xr*line_direction)*C4()*Jr;
    const MatrixXd Jmx = crossmatrix4(l).transpose()*Jt + crossmatrix4(xt)*Jrx;

    ///Line Jacobian
    MatrixXd Jlx(8,Jr.cols());
    Jlx << Jrx,Jmx;
    return Jlx;
}

/**
 * @brief The plane Jacobian given the \p rotation_jacobian, the \p translation_jacobian, the \p pose, and a \p plane_normal
 * @param rotation_jacobian the current rotation Jacobian \see rotation_jacobian()
 * @param translation_jacobian the current translation Jacobian \see translation_jacobian()
 * @param pose the current end-effector pose \see fkm()
 * @param plane_normal the plane normal w.r.t. the \p pose reference frame. For example using i_, j_, and k_
 * will return the plane Jacobian whose normal is collinear with, respectively, the x-axis, y-axis, and z-axis of \p pose,
 */
MatrixXd plane_jacobian(const MatrixXd& pose_jacobian, const DQ& pose, const DQ& plane_normal)
{
    /// Aliases
    const DQ&       x  = pose;
    const DQ&       xt = translation(x);
    const DQ&       xr = rotation(x);
    const MatrixXd& Jr = rotation_jacobian(pose_jacobian);
    const MatrixXd& Jt = translation_jacobian(pose_jacobian,pose);

    ///Plane normal w.r.t base
    const DQ nz = xr*(plane_normal)*conj(xr);

    ///Plane normal Jacobian
    const MatrixXd Jnz = haminus4(plane_normal*conj(xr))*Jr + hamiplus4(xr*plane_normal)*C4()*Jr;

    ///Plane distance Jacobian
    const MatrixXd Jdz  = (vec4(nz).transpose()*Jt+vec4(xt).transpose()*Jnz);

    ///Plane Jacobian
    MatrixXd JPI = MatrixXd::Zero(8,Jt.cols());
    JPI << Jnz,Jdz,MatrixXd::Zero(3,Jdz.cols());
    return JPI;
}

MatrixXd point_to_point_distance_jacobian(const MatrixXd& translation_jacobian, const DQ& robot_point_translation, const DQ& workspace_point_translation)
{
    if(Re(robot_point_translation)!=0 || Re(workspace_point_translation)!=0 || D(robot_point_translation)!=0 || D(workspace_point_translation)!=0)
    {
        throw std::range_error("The arguments translation and position have to be imaginary quaternions.");
    }
    return 2*vec4(robot_point_translation-workspace_point_translation).transpose()*translation_jacobian;
}

double   point_to_point_residual         (const DQ& robot_point_translation, const DQ& workspace_point_translation, const DQ& workspace_point_translation_derivative)
{
    if(Re(robot_point_translation)!=0 || Re(workspace_point_translation)!=0 || Re(workspace_point_translation_derivative)!=0 || D(robot_point_translation)!=0 || D(workspace_point_translation)!=0 || D(workspace_point_translation_derivative)!=0)
    {
        throw std::range_error("The arguments translation, position, and position_derivative have to be imaginary quaternions.");
    }
    DQ tmp = 2.0*dot(robot_point_translation-workspace_point_translation,-1.0*workspace_point_translation_derivative);
    return tmp.q(1);
}

MatrixXd point_to_line_distance_jacobian(const MatrixXd& translation_jacobian, const DQ& robot_point_translation, const DQ& workspace_line)
{
    if(Re(robot_point_translation)!=0 || D(robot_point_translation)!=0)
    {
        throw std::range_error("The argument translation has to be imaginary quaternions.");
    }
    const DQ& t = robot_point_translation;

    const DQ l = P(workspace_line);
    const DQ m = D(workspace_line);

    return 2.0*vec4( cross(t,l)-m ).transpose()*crossmatrix4(l).transpose()*translation_jacobian;
}

double   point_to_line_residual(const DQ& robot_point_translation, const DQ& workspace_line, const DQ& workspace_line_derivative)
{
    if(Re(robot_point_translation)!=0 || D(robot_point_translation)!=0)
    {
        throw std::range_error("The argument translation has to be imaginary quaternions.");
    }
    const DQ& t = robot_point_translation;

    const DQ& l = P(workspace_line);
    const DQ& m = D(workspace_line);
    const DQ& l_dot = P(workspace_line_derivative);
    const DQ& m_dot = D(workspace_line_derivative);

    DQ tmp = 2.0*dot( cross(t,l_dot) - m_dot , cross(t,l) - m );
    return tmp.q(0);
}

MatrixXd point_to_plane_distance_jacobian(const MatrixXd& translation_jacobian, const DQ& robot_point_translation, const DQ& workspace_plane)
{
    if(Re(robot_point_translation)!=0 || D(robot_point_translation)!=0)
    {
        throw std::range_error("The argument translation has to be imaginary quaternions.");
    }
    const DQ n = P(workspace_plane);
    const DQ d = D(workspace_plane);

    return vec4(n).transpose()*translation_jacobian;
}

double point_to_plane_residual(const DQ& translation, const DQ& plane_derivative)
{
    if(Re(translation)!=0 || D(translation)!=0)
    {
        throw std::range_error("The argument translation has to be imaginary quaternions.");
    }
    const DQ& t = translation;
    const DQ n_dot = P(plane_derivative);
    const DQ d_dot = D(plane_derivative);

    return vec4(dot(t,n_dot) - d_dot)(0);
}

MatrixXd line_to_point_distance_jacobian (const MatrixXd& line_jacobian, const DQ& robot_line, const DQ& workspace_point_translation)
{
    MatrixXd Jl = line_jacobian.block(0,0,4,line_jacobian.cols());
    MatrixXd Jm = line_jacobian.block(4,0,4,line_jacobian.cols());

    // Extract line quaternions
    DQ l = P(robot_line);
    DQ m = D(robot_line);

    return 2.0*vec4(  cross(workspace_point_translation,l)-m ).transpose()*(crossmatrix4(workspace_point_translation)*Jl-Jm);
}

double   line_to_point_residual(const DQ& robot_line, const DQ& workspace_point_translation, const DQ& workspace_point_translation_derivative)
{
    // Extract line quaternions
    DQ l = P(robot_line);
    DQ m = D(robot_line);

    // Notational simplicity
    DQ hc1 = cross(workspace_point_translation,l)-m;
    DQ hc2 = cross(workspace_point_translation_derivative,l);

    DQ tmp = 2.0*dot(hc2,hc1);
    return tmp.q(0);
}

MatrixXd line_to_line_distance_jacobian(const MatrixXd& line_jacobian, const DQ& robot_line, const DQ& workspace_line)
{
    const int DOFS  = line_jacobian.cols();
    const DQ& l_dq  = workspace_line;

    ///Dot product dual part square norm
    //Dot product Jacobian
    const MatrixXd Jdot     = -0.5*(hamiplus8(l_dq)+haminus8(l_dq))*line_jacobian;
    const MatrixXd Jdotdual = Jdot.block(4,0,4,DOFS);
    //Norm Jacobian
    const DQ Dlzldot             = D(dot(robot_line,l_dq));
    const MatrixXd Jnormdotdual  = 2*vec4(Dlzldot).transpose()*Jdotdual;

    ///Cross product primary part square norm
    //Cross product Jacobian
    const MatrixXd Jcross        = 0.5*(haminus8(l_dq)-hamiplus8(l_dq))*line_jacobian;
    const MatrixXd Jcrossprimary = Jcross.block(0,0,4,DOFS);
    //Norm Jacobian
    const DQ Plzlcross                = P(cross(robot_line,l_dq));
    const MatrixXd Jnormcrossprimary  = 2*vec4(Plzlcross).transpose()*Jcrossprimary;

    ///Distance Jacobian
    // a
    const double a_temp = vec4(Plzlcross).norm();
    const double a = (1.0)/(a_temp*a_temp);
    // b
    const double b_temp = vec4(Dlzldot).norm();
    const double b = -((b_temp*b_temp)/(a_temp*a_temp*a_temp*a_temp));

    ///Robot line--line squared distance Jacobian
    return a*Jnormdotdual+b*Jnormcrossprimary;
}


double   line_to_line_residual(const DQ& robot_line, const DQ& workspace_line, const DQ& workspace_line_derivative)
{
    const DQ& l_dq_dot = workspace_line_derivative;
    const DQ& l_dq     = workspace_line;

    //Dot product residual
    const DQ zetadotdual         = D(dot(robot_line,l_dq_dot));
    //Norm Jacobian
    const DQ Dlzldot             = D(dot(robot_line,l_dq));
    const double zetanormdotdual = 2*vec4(Dlzldot).transpose()*vec4(zetadotdual);

    //Cross product residual
    const DQ zetacrossprimary    = P(cross(robot_line,l_dq_dot));
    //Norm Jacobian
    const DQ Plzlcross                = P(cross(robot_line,l_dq));
    const double zetanormcrossprimary = 2*vec4(Plzlcross).transpose()*vec4(zetacrossprimary);

    // a
    const double a_temp = vec4(Plzlcross).norm();
    const double a = (1.0)/(a_temp*a_temp);
    // b
    const double b_temp = vec4(Dlzldot).norm();
    const double b = -((b_temp*b_temp)/(a_temp*a_temp*a_temp*a_temp));

    return a*zetanormdotdual+b*zetanormcrossprimary;
}

MatrixXd plane_to_point_distance_jacobian(const MatrixXd& plane_jacobian, const DQ& robot_plane, const DQ& workspace_point)
{
    // Break Jpi into blocks
    MatrixXd Jnz = plane_jacobian.block(0,0,4,plane_jacobian.cols());
    MatrixXd Jdz = plane_jacobian.block(4,0,1,plane_jacobian.cols());

    // Extract plane quaternions
    DQ n_pi = P(robot_plane);
    DQ d_pi = D(robot_plane);

    // Plane distance Jacobian
    return vec4(workspace_point).transpose()*Jnz-Jdz;
}

double   plane_to_point_residual(const DQ& robot_plane, const DQ& workspace_point_derivative)
{
    DQ n_pi = P(robot_plane);

    DQ tmp = dot(workspace_point_derivative,n_pi);
    return tmp.q(0);
}


/** Returns the distance Jacobian; that it, the Jacobian that satisfies the relation dot_(d^2) = Jd * dot_theta.
* where dot_(d^2) is the time derivative of the square of the distance between the end-effector and the base and dot_theta is
* the time derivative of the joint vector.
* To use this member function type: 'dh_matrix__object.jacobd(param_jacobian, x).
* \param Eigen::MatrixXd param_jacobian is the Jacobian of a robotic system
* \param Eigen::Matrix<double,8,1> x is the vector which constructs a translation DQ object
* \return A constant Eigen::MatrixXd
*/
MatrixXd  distance_jacobian( const MatrixXd& param_jacobian, const DQ& x)
{
    DQ dq_x(x);
    DQ p = translation(dq_x);
    MatrixXd Jp = translation_jacobian(param_jacobian, x);
    MatrixXd vec4p_T(1,4);
    for (int i = 0; i < 4; i++) {
        vec4p_T(0,i) = vec4(p)(i,0);
    }
    MatrixXd Jd = 2 * (vec4p_T * Jp);

    return Jd;
}

/**
* Pseudo inverse implementation mimicking the on in MATLAB.
* \param Eigen::MatrixXd matrix: the matrix whose pseudoinverse you want.
* \return A constant Eigen::MatrixXd that is the Moore-Penrose pseudoinverse of matrix with the default MATLAB tolerance.
* \see  http://www.mathworks.com/help/matlab/ref/pinv.html
*/
MatrixXd  pseudo_inverse( const MatrixXd& matrix)
{
    int num_rows = matrix.rows();
    int num_cols = matrix.cols();

    MatrixXd pseudo_inverse(num_cols,num_rows);
    JacobiSVD<MatrixXd> svd(num_cols,num_rows);
    VectorXd singular_values;
    MatrixXd svd_sigma_inverted(num_cols,num_rows);
    svd_sigma_inverted = MatrixXd::Zero(num_cols,num_rows);

    svd.compute(matrix, ComputeFullU | ComputeFullV);
    singular_values = svd.singularValues();

    //Tolerance Calculation
    double eps =  std::numeric_limits<double>::epsilon();
    int max =  (num_rows > num_cols) ? num_rows : num_cols;
    double norm = singular_values(0); //Matlab uses the 2-NORM, which is the largest singular value. Meyer p.281
    double tol = max*norm*eps;

    for(int i=0;i<singular_values.size();i++)
    {
        if(singular_values(i) > tol)
            svd_sigma_inverted(i,i) = 1/(singular_values(i));
        else
            svd_sigma_inverted(i,i) = 0;
    }

    pseudo_inverse = svd.matrixV() * (svd_sigma_inverted * svd.matrixU().adjoint());
    
    return pseudo_inverse;
}

MatrixXd pose_jacobian_derivative(const DQ_kinematics& dq_kin,   const VectorXd& theta_vec, const VectorXd& theta_vec_dot, const int& to_link)
{
    return dq_kin.pose_jacobian_derivative(theta_vec,theta_vec_dot,to_link);
}

///DEPRECATED SIGNATURES
MatrixXd analyticalJacobian( const DQ_kinematics& dq_kin,   const VectorXd& theta_vec){return pose_jacobian(dq_kin,theta_vec);}
MatrixXd jacobian(           const DQ_kinematics& dq_kin,   const VectorXd& theta_vec,  const int &to_link){return pose_jacobian(dq_kin,theta_vec,to_link);}
MatrixXd jacobian(           const DQ_kinematics& dq_kin,   const VectorXd& theta_vec){return pose_jacobian(dq_kin,theta_vec);} //The MATLAB syntax, kept for legacy reasons.
MatrixXd jacobianDerivative( const DQ_kinematics& dq_kin,   const VectorXd& theta_vec, const VectorXd& theta_vec_dot, const int& to_link){return pose_jacobian_derivative(dq_kin,theta_vec,theta_vec_dot,to_link);}
MatrixXd raw_jacobian(       const DQ_kinematics& dq_kin,   const VectorXd& theta_vec, const int& to_link){return raw_pose_jacobian(dq_kin,theta_vec,to_link);}
MatrixXd rotationJacobian(   const MatrixXd& pose_jacobian){return rotation_jacobian(pose_jacobian);}
MatrixXd translationJacobian(const MatrixXd& pose_jacobian, const DQ& x){return translation_jacobian(pose_jacobian,x);}
MatrixXd jacobp(             const MatrixXd& pose_jacobian, const DQ& x){return translation_jacobian(pose_jacobian,x);} //The MATLAB syntax, kept for legacy reasons.
//MatrixXd distanceJacobian(   const MatrixXd& param_jacobian, const DQ& x){return distance_jacobian(param_jacobian,x);}
//MatrixXd jacobd(             const MatrixXd& param_jacobian, const DQ& x){return distance_jacobian(param_jacobian,x);}
MatrixXd pseudoInverse(      const MatrixXd& matrix){return pseudo_inverse(matrix);}
int      links(              const DQ_kinematics& dq_kin){return n_links(dq_kin);}

/****************************************************************
**************DQ KINEMATICS CLASS METHODS************************
*****************************************************************/


/**
* DQ_kinematics constructor using boost matrix
*
* Returns a DQ_kinematics object based on a 4xn or 5xn matrix named 'A' containing the Denavit-Hartenberg parameters.
* 'n' is the number of links of the robotic system. If 'A' has 4 rows there are no dummy joints. If 'A' has 4 rows,
* exists at least one dummy joint. 'A' matrix must be 4xn or 5xn. The 'A' rows 1 to 5 are respectively, 'theta' 1 to n,
* 'd' 1 to n, 'a' 1 to n, 'alpha' 1 to n and 'dummy joints' 1 to n parameters. The DH convention used is according to
* the 'type' parameter. 'type' is a string that can be 'standard' or 'modified' depending on the wanted convention. If
* something different of these values are attributed to 'type' parameter the standard convention is used as default.
* To create a DQ_kinematics object using this, type: 'DQ dh_matrix__object(A,type)';

* \param MatrixXd A contain the Denavit-Hartenberg parameters for the kinematic model.
* \param std::string type contain the convention used in Denavit_Hartenberg.
*/
DQ_kinematics::DQ_kinematics(const MatrixXd& dh_matrix, const std::string& convention ){

    if (convention != "standard" && convention != "modified")
    {
        throw(std::range_error("Bad DQ_kinematics(dh_matrix, convention) call: convention must be 'standard' or 'modified' "));
    }
    if (dh_matrix.rows() != 4 && dh_matrix.rows() != 5)
    {
        throw(std::range_error("Bad DQ_kinematics(dh_matrix, convention) call: dh_matrix should be 5xn or 4xn"));
    }

    //dh_matrix_.resize(dh_matrix);
    dh_matrix_ = dh_matrix;
    curr_base_ = DQ(1);
    curr_effector_ = DQ(1);
    dh_matrix_convention_ = convention;
}

/**
* DQ_kinematics Destructor
*
* Deletes from memory the DQ_kinematics object caller. To use this destructor, type: 'dh_matrix__object.~DQ_kinematics();'. Dont need parameters.
*/
DQ_kinematics::~DQ_kinematics(){}

// Public constant methods

/**

*/
MatrixXd DQ_kinematics::getDHMatrix()
{
    MatrixXd DHMatrix = dh_matrix_;
    return DHMatrix;
}


/**
* Returns a constant int representing the number of links of a robotic system DQ_kinematics object.
* It gets the number of columns of matrix 'A', passed to constructor and stored in the private attributte dh_matrix_.
* To use this member function, type: 'dh_matrix__object.links();'.
* \return A constant int.
*/
int  DQ_kinematics::n_links() const
{
    return dh_matrix_.cols();
}

/**
* Returns a constant vector representing the theta joint angles offset of a robotic system DQ_kinematics object.
* It gets the first row of matrix 'A', passed to constructor and stored in the private attributte dh_matrix_.
* To use this member function, type: 'dh_matrix__object.theta();'.
* \return A constant Eigen::VectorXd (number of links).
*/
VectorXd  DQ_kinematics::theta() const
{
    VectorXd aux_theta(dh_matrix_.cols());
    for (int i = 0; i < dh_matrix_.cols(); i++) {
        aux_theta(i) = dh_matrix_(0,i);
    }
    return aux_theta;
}



/**
* Returns a constant vector representing each 'd' offset along previous z to the common normal of a robotic system DQ_kinematics object.
* It gets the second row of matrix 'A', passed to constructor and stored in the private attributte dh_matrix_.
* To use this member function, type: 'dh_matrix__object.d();'.
* \return A constant Eigen::VectorXd (number of links).
*/
VectorXd  DQ_kinematics::d() const
{
    VectorXd aux_d(dh_matrix_.cols());
    for (int i = 0; i < dh_matrix_.cols(); i++) {
        aux_d(i) = dh_matrix_(1,i);
    }
    return aux_d;
}

/**
* Returns a constant vector representing each 'a' length of the common normal of a robotic system DQ_kinematics object.
* It gets the third row of matrix 'A', passed to constructor and stored in the private attributte dh_matrix_.
* To use this member function, type: 'dh_matrix__object.a();'.
* \return A constant Eigen::VectorXd (number of links).
*/
VectorXd  DQ_kinematics::a() const
{
    VectorXd aux_a(dh_matrix_.cols());
    for (int i = 0; i < dh_matrix_.cols(); i++) {
        aux_a(i) = dh_matrix_(2,i);
    }
    return aux_a;
}

/**
* Returns a constant vector representing each 'alpha' angle about common normal, from old z axis to new z axis of a
* robotic system DQ_kinematics object. It gets the fourth row of matrix 'A', passed to constructor and stored in the private attributte
* dh_matrix_. To use this member function, type: 'dh_matrix__object.alpha();'.
* \return A constant Eigen::VectorXd (number of links).
*/
VectorXd  DQ_kinematics::alpha() const
{
    VectorXd aux_alpha(dh_matrix_.cols());
    for (int i = 0; i < dh_matrix_.cols(); i++) {
        aux_alpha(i) = dh_matrix_(3,i);
    }
    return aux_alpha;
}

/**
* Returns a constant vector representing the existing 'dummy' axes of a robotic system DQ_kinematics object.
* It gets the fifth row of matrix 'A', passed to constructor and stored in the private attributte dh_matrix_ when it exists.
* If not, dummy vector is a null with n elements. Being n equal to number of links. To use this member function, type:
* 'dh_matrix__object.dummy();'.
* \return A constant Eigen::VectorXd (number of links).
*/
VectorXd  DQ_kinematics::dummy() const
{
    VectorXd aux_dummy(dh_matrix_.cols());
    if (dh_matrix_.rows() > 4){
        for (int i = 0; i < dh_matrix_.cols(); i++) {
            aux_dummy(i) = dh_matrix_(4,i);
        }
        return aux_dummy;
    }
    else {
        for (int i = 0; i < dh_matrix_.cols(); i++) {
            aux_dummy(i) = 0;
        }
        return aux_dummy;
    }
}


void DQ_kinematics::set_dummy( const VectorXd& dummy_vector)
{

    if(dummy_vector.size() != dh_matrix_.cols())
    {
        std::cerr << std:: endl << "Cannot change dummy status: argument vector is of size = "
                  << dummy_vector.size() << " when it should be of size = " << dh_matrix_.cols() << std::endl;
        //Do nothing
        return;
    }

    if (dh_matrix_.rows() > 4){
        for (int i = 0; i < dh_matrix_.cols(); i++) {
            dh_matrix_(4,i) = dummy_vector(i);
        }
    }
    else{
        std::cerr << std::endl << "Kinematics body has no dummy information to change." << std::endl;
        //Do nothing
    }



}


/**
* Returns a constant int representing the number of 'dummy' axes of a robotic system DQ_kinematics object.
* If there are no dummy axes the result is 0. To use this member function, type: 'dh_matrix__object.n_dummy();'.
* \return A constant int.
*/
int  DQ_kinematics::n_dummy() const
{
    int aux_n_dummy = 0;
    if (dh_matrix_.rows() > 4){
        for (int i = 0; i < dh_matrix_.cols(); i++) {
            if(dh_matrix_(4,i) == 1.0)
                aux_n_dummy = aux_n_dummy + 1;
        }
        return aux_n_dummy;
    }
    else
        return aux_n_dummy;
}

/**
* Returns a constant std::string representing the Denavit Hartenberg convenction (standard or modified) used in a robotic system
* DQ_kinematics object. To use this member function, type: 'dh_matrix__object.convention();'.
* \return A constant std::string.
*/
std::string  DQ_kinematics::convention() const
{
    return dh_matrix_convention_;
}

/**
* Returns a constant DQ object representing current defined base of a robotic system DQ_kinematics object.
* To use this member function, type: 'dh_matrix__object.base();'.
* \return A constant DQ object.
*/
DQ  DQ_kinematics::base() const
{
    return curr_base_;
}

/**
* Returns a constant DQ object representing current defined end effector of a robotic system DQ_kinematics object.
* To use this member function, type: 'dh_matrix__object.effector();'.
* \return A constant DQ object.
*/
DQ  DQ_kinematics::effector() const
{
    return curr_effector_;
}

/**
* Sets, by new_base parameter, the pose of current base of a robotic system DQ_kinematics object and returns it in a constant DQ object.
* To use this member function, type: 'dh_matrix__object.set_base();'.
* \param DQ new_base representing the new pose of robotic system base
* \return A constant DQ object.
*/
DQ  DQ_kinematics::set_base( const DQ& new_base)
{
    curr_base_ = new_base;
    return curr_base_;
}

/**
* Sets, by new_effector parameter, the pose of current end effector of a robotic system DQ_kinematics object and returns it in a constant DQ object.
* To use this member function, type: 'dh_matrix__object.set_effector();'.
* \param DQ new_effector representing the new pose of robotic system end effector
* \return A constant DQ object.
*/
DQ  DQ_kinematics::set_effector( const DQ& new_effector)
{
    curr_effector_ = new_effector;
    return curr_effector_;
}

/**
* Calculates the forward kinematic model and returns a DQ object corresponding to the last joint.
* The displacements due to the base and the effector are not taken into account. theta_vec is the vector of joint variables.
* This is an auxiliary function to be used mainly with the jacobian function.
* To use this member function, type: 'dh_matrix__object.raw_fkm(theta_vec);'.
* \param Eigen::VectorXd theta_vec is the vector representing the theta joint angles.
* \return A constant DQ object.
*/
DQ  DQ_kinematics::raw_fkm( const VectorXd& theta_vec) const
{

    if(int(theta_vec.size()) != (this->n_links() - this->n_dummy()) )
    {
        throw(std::range_error("Bad raw_fkm(theta_vec) call: Incorrect number of joint variables"));
    }

    DQ q(1);
    int j = 0;
    for (int i = 0; i < this->n_links(); i++) {
        if(this->dummy()(i) == 1.0) {
            q = q * DQ_robotics::dh2dq((*this), 0.0, i+1);
            j = j + 1;
        }
        else
            q = q * DQ_robotics::dh2dq((*this), theta_vec(i-j), i+1);
    }
    return q;
}

/**
* Calculates the forward kinematic model and returns a DQ object corresponding to the ith joint.
* The displacements due to the base and the effector are not taken into account. theta_vec is the vector of joint variables.
* This is an auxiliary function to be used mainly with the jacobian function.
* To use this member function, type: 'dh_matrix__object.raw_fkm(theta_vec, ith);'.
* \param Eigen::VectorXd theta_vec is the vector representing the theta joint angles.
* \param int ith is the position of the least joint included in the forward kinematic model
* \return A constant DQ object.
*/
DQ  DQ_kinematics::raw_fkm( const VectorXd& theta_vec, const int& ith) const
{

    if(int(theta_vec.size()) != (this->n_links() - this->n_dummy()) )
    {
        throw(std::range_error("Bad raw_fkm(theta_vec,ith) call: Incorrect number of joint variables"));
    }

    DQ q(1);
    int j = 0;
    for (int i = 0; i < ith; i++) {
        if(this->dummy()(i) == 1.0) {
            q = q * DQ_robotics::dh2dq( (*this) , 0, i+1);
            j = j + 1;
        }
        else
            q = q * DQ_robotics::dh2dq( (*this) , theta_vec(i-j), i+1);
    }
    return q;
}

/**
* Calculates the forward kinematic model and returns a DQ object corresponding to the last joint.
* This function takes into account the displacement due to the base's and effector's poses. theta_vec is the vector of joint variables.
* To use this member function, type: 'dh_matrix__object.fkm(theta_vec);'.
* \param Eigen::VectorXd theta_vec is the vector representing the theta joint angles.
* \return A constant DQ object.
*/
DQ  DQ_kinematics::fkm( const VectorXd& theta_vec) const
{
    DQ q = curr_base_ * ( this->raw_fkm(theta_vec) ) * curr_effector_;
    return q;
}


/**
* Calculates the forward kinematic model and returns a DQ object corresponding to the ith joint.
* This function takes into account the displacement due to the base's and effector's poses. theta_vec is the vector of joint variables.
* To use this member function, type: 'dh_matrix__object.fkm(theta_vec, ith);'.
* \param Eigen::VectorXd theta_vec is the vector representing the theta joint angles.
* \return A constant DQ object.
*/
DQ  DQ_kinematics::fkm( const VectorXd& theta_vec, const int& ith) const
{
    DQ q = curr_base_ * ( this->raw_fkm(theta_vec, ith) ) * curr_effector_;
    return q;
}

/** Returns the correspondent DQ object, for a given link's Denavit Hartenberg parameters.
* To use this member function type: 'dh_matrix__object.dh2dq(theta,i), where theta is the joint angle and i is the link number
* \param double theta_ang is the joint angle
* \param int link_i is the link number
* \return A constant DQ object
*/
DQ  DQ_kinematics::dh2dq( const double& theta_ang, const int& link_i) const {

    Matrix<double,8,1> q(8);

    double d     = this->d()(link_i-1);
    double a     = this->a()(link_i-1);
    double alpha = this->alpha()(link_i-1);

    if(this->convention() == "standard") {

        q(0)=cos((theta_ang + this->theta()(link_i-1) )/2.0)*cos(alpha/2.0);
        q(1)=cos((theta_ang + this->theta()(link_i-1) )/2.0)*sin(alpha/2.0);
        q(2)=sin((theta_ang + this->theta()(link_i-1) )/2.0)*sin(alpha/2.0);
        q(3)=sin((theta_ang + this->theta()(link_i-1) )/2.0)*cos(alpha/2.0);
        double d2=d/2.0;
        double a2=a/2.0;
        q(4)= -d2*q(3) - a2*q(1);
        q(5)= -d2*q(2) + a2*q(0);
        q(6)=  d2*q(1) + a2*q(3);
        q(7)=  d2*q(0) - a2*q(2);
    }
    else{

        double h1 = cos((theta_ang + this->theta()(link_i-1) )/2.0)*cos(alpha/2.0);
        double h2 = cos((theta_ang + this->theta()(link_i-1) )/2.0)*sin(alpha/2.0);
        double h3 = sin((theta_ang + this->theta()(link_i-1) )/2.0)*sin(alpha/2.0);
        double h4 = sin((theta_ang + this->theta()(link_i-1) )/2.0)*cos(alpha/2.0);
        q(0)= h1;
        q(1)= h2;
        q(2)= -h3;
        q(3)= h4;
        double d2=d/2.0;
        double a2=a/2.0;
        q(4)=-d2*h4 - a2*h2;
        q(5)=-d2*h3 + a2*h1;
        q(6)=-(d2*h2 + a2*h4);
        q(7)=d2*h1 - a2*h3;
    }
    return DQ(q);
}


DQ  DQ_kinematics::get_z( const VectorXd& q) const
{
    Matrix<double,8,1> z(8);

    z(0) = 0.0;
    z(1)=q(1)*q(3) + q(0)*q(2);
    z(2)=q(2)*q(3) - q(0)* q(1);
    z(3)=(q(3)*q(3)-q(2)*q(2)-q(1)*q(1)+q(0)*q(0))/2.0;
    z(4)=0.0;
    z(5)=q(1)*q(7)+q(5)*q(3)+q(0)*q(6)+q(4)*q(2);
    z(6)=q(2)*q(7)+q(6)*q(3)-q(0)*q(5)-q(4)*q(1);
    z(7)=q(3)*q(7)-q(2)*q(6)-q(1)*q(5)+q(0)*q(4);

    return DQ(z);
}


MatrixXd DQ_kinematics::raw_pose_jacobian(const VectorXd& theta_vec, const int& to_link) const
{
    DQ q_effector = this->raw_fkm(theta_vec,to_link);
    DQ z;
    DQ q(1);

    MatrixXd J(8,(to_link - this->n_dummy()) );

    for (int i = 0; i < J.rows(); i++) {
        for(int j = 0; j < J.cols(); j++) {
            J(i,j) = 0;
        }
    }

    int ith = -1;
    for(int i = 0; i < to_link; i++) {

        // Use the standard DH convention
        if(this->convention() == "standard") {
            z = this->get_z(q.q);
        }
        // Use the modified DH convention
        else {
            DQ w(0, 0, -sin(this->alpha()(i)), cos(this->alpha()(i)), 0, 0, -this->a()(i)*cos(this->alpha()(i)), -this->a()(i)*sin(this->alpha()(i)));
            z =0.5 * q * w * q.conj();
        }
        if(this->dummy()(i) == 0.0) {
            q = q * this->dh2dq(theta_vec(ith+1), i+1);
            DQ aux_j = z * q_effector;
            for(int k = 0; k < J.rows(); k++) {
                J(k,ith+1) = aux_j.q(k);
            }
            ith = ith+1;
        }
        else
            // Dummy joints don't contribute to the Jacobian
            q = q * this->dh2dq(0.0,(i+1));
    }

    return J;
}

/** Returns a MatrixXd 8x(links - n_dummy) representing the Jacobian of a robotic system DQ_kinematics object.
* theta_vec is the vector of joint variables.
* \param Eigen::VectorXd theta_vec is the vector representing the theta joint angles.
* \return A constant Eigen::MatrixXd (8,links - n_dummy).
*/
MatrixXd  DQ_kinematics::pose_jacobian(const VectorXd& theta_vec, const int &to_link) const
{
    MatrixXd J = raw_pose_jacobian(theta_vec,to_link);
    if(to_link==this->n_links())
    {
        J = hamiplus8(curr_base_)*haminus8(curr_effector_)*J;
    }
    else
    {
        J = hamiplus8(curr_base_)*J;
    }
    return J;
}

MatrixXd DQ_kinematics::pose_jacobian(const VectorXd &theta_vec) const
{
    return pose_jacobian(theta_vec,n_links());
}

MatrixXd DQ_kinematics::pose_jacobian_derivative(const VectorXd &theta_vec, const VectorXd &theta_vec_dot, const int &to_link) const
{

    int n = to_link;
    DQ x_effector = raw_fkm(theta_vec,to_link);
    MatrixXd J    = raw_pose_jacobian(theta_vec,to_link);
    VectorXd vec_x_effector_dot = J*theta_vec_dot.head(to_link);

    DQ x = DQ(1);
    MatrixXd J_dot = MatrixXd::Zero(8,n-n_dummy());
    int jth=0;

    for(int i=0;i<n;i++)
    {
        DQ w;
        DQ z;
        // Use the standard DH convention
        if(this->convention() == "standard") {
            w = k_;
            z = get_z(x.q);
        }
        else //Use the modified DH convention
        {
            w = DQ(0,0,-sin(alpha()(i)),cos(alpha()(i)),0,0,-a()(i)*cos(alpha()(i)),-a()(i)*sin(alpha()(i)));
            z = 0.5*x*w*conj(x);
        }

        if( dummy()(i)!=1.0 )
        {
            VectorXd vec_zdot = 0.5*(haminus8(w*conj(x)) + hamiplus8(x*w)*C8())*raw_pose_jacobian(theta_vec,i)*theta_vec_dot.head(i);

            J_dot.col(jth) = haminus8(x_effector)*vec_zdot + hamiplus8(z)*vec_x_effector_dot;
            x = x*dh2dq(theta_vec(jth),i+1);
            jth = jth+1;
        }
        else
        {
            //Dummy joints don't contribute to the Jacobian
            x = x*dh2dq(0,i);
        }
    }

    return J_dot;
}

///DEPRECATED SIGNATURES
MatrixXd DQ_kinematics::analyticalJacobian( const VectorXd& theta_vec) const{return pose_jacobian(theta_vec);}
MatrixXd DQ_kinematics::jacobian(           const VectorXd& theta_vec, const int& to_link) const{return pose_jacobian(theta_vec,to_link);}
MatrixXd DQ_kinematics::jacobian(           const VectorXd& theta_vec) const{return pose_jacobian(theta_vec);}
MatrixXd DQ_kinematics::raw_jacobian(       const VectorXd& theta_vec, const int& to_link) const{return raw_pose_jacobian(theta_vec,to_link);}
MatrixXd DQ_kinematics::jacobianDerivative( const VectorXd& theta_vec, const VectorXd& theta_vec_dot, const int& to_link) const{return pose_jacobian_derivative(theta_vec,theta_vec_dot,to_link);}
int      DQ_kinematics::links() const{return n_links();}

}//namespace DQ_robotics

