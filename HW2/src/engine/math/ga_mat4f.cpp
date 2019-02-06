/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "math/ga_mat4f.h"

#include "math/ga_math.h"

#include <math.h>

void ga_mat4f::make_identity()
{
	// TODO: Homework 2
	(*this).data[0][0] = 1; 
	(*this).data[1][1] = 1; 
	(*this).data[2][2] = 1; 
	(*this).data[3][3] = 1; 
	(*this).data[0][1] = 0;
	(*this).data[0][2] = 0;
	(*this).data[0][3] = 0;
	(*this).data[1][0] = 0;
	(*this).data[1][2] = 0;
	(*this).data[1][3] = 0;
	(*this).data[2][0] = 0;
	(*this).data[2][1] = 0;
	(*this).data[2][3] = 0;
	(*this).data[3][0] = 0;
	(*this).data[3][1] = 0;
	(*this).data[3][2] = 0;
	
}

void ga_mat4f::make_translation(const ga_vec3f& __restrict t)
{
	(*this).make_identity(); 
	(*this).data[3][0] = t.x; 
	(*this).data[3][1] = t.y;
	(*this).data[3][2] = t.z;
	// TODO: Homework 2
}

void ga_mat4f::make_scaling(float s)
{
	// TODO: Homework 2
	(*this).make_identity();
	data[0][0] = s;
	data[1][1] = s; 
	data[2][2] = s;

}

void ga_mat4f::make_rotation_x(float angle)
{
	(*this).make_identity(); 
	(*this).data[1][1] = signiCloseZero(ga_cosf(angle));
	(*this).data[2][1] = signiCloseZero(-1 * ga_sinf(angle));
	(*this).data[1][2] = signiCloseZero(ga_sinf(angle));
	(*this).data[2][2] = signiCloseZero(ga_cosf(angle));
	

	// TODO: Homework 2
}

void ga_mat4f::make_rotation_y(float angle)
{
	// TODO: Homework 2
	(*this).make_identity();
	(*this).data[0][0] = signiCloseZero(ga_cosf(angle));
	

	(*this).data[2][0] = signiCloseZero(ga_sinf(angle));



	(*this).data[0][2] = signiCloseZero(-1 * ga_sinf(angle));
	(*this).data[2][2] = signiCloseZero(ga_cosf(angle));
}

void ga_mat4f::make_rotation_z(float angle)
{
	// TODO: Homework 2
	(*this).make_identity();
	(*this).data[0][0] = signiCloseZero(ga_cosf(angle));
	(*this).data[1][0] = signiCloseZero(-1 * ga_sinf(angle));
	(*this).data[0][1] = signiCloseZero(ga_sinf(angle));
	(*this).data[1][1] = signiCloseZero(ga_cosf(angle));
}

void ga_mat4f::translate(const ga_vec3f& __restrict t)
{
	ga_mat4f tmp;
	tmp.make_translation(t);
	(*this) *= tmp;
}

void ga_mat4f::scale(float s)
{
	ga_mat4f tmp;
	tmp.make_scaling(s);
	(*this) *= tmp;
}

void ga_mat4f::rotate_x(float angle)
{
	ga_mat4f tmp;
	tmp.make_rotation_x(angle);
	(*this) *= tmp;
}

void ga_mat4f::rotate_y(float angle)
{
	ga_mat4f tmp;
	tmp.make_rotation_y(angle);
	(*this) *= tmp;
}

void ga_mat4f::rotate_z(float angle)
{
	ga_mat4f tmp;
	tmp.make_rotation_z(angle);
	(*this) *= tmp;
}

ga_mat4f ga_mat4f::operator*(const ga_mat4f& __restrict b) const
{
	// TODO: Homework 2
	ga_mat4f newMat;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			newMat.data[j][i] = 0;
			for (int k = 0; k < 4; k++)
			{
				newMat.data[j][i] += (*this).data[k][i] * b.data[j][k];
			}
		}
	}
	return newMat;
}

ga_mat4f& ga_mat4f::operator*=(const ga_mat4f& __restrict m)
{
	(*this) = (*this) * m;
	return (*this);
}

ga_vec4f ga_mat4f::transform(const ga_vec4f& __restrict in) const
{
	// TODO: Homework 2
	ga_vec4f copyVec = {0,0,0,0};
	for (int i = 0; i < 4; i++) {
		for (int p = 0; p < 1; p++) {
			float rowNum = 0;
			for (int j = 0; j < 4; j++) {
				rowNum += ((*this).data[j][i] * in.axes[j]);
			}
			copyVec.axes[i] = rowNum;
		}

	}
	copyVec.x = copyVec.axes[0];
	copyVec.y = copyVec.axes[1];
	copyVec.z = copyVec.axes[2];
	copyVec.w = copyVec.axes[3];



	return copyVec;
}

ga_vec3f ga_mat4f::transform_vector(const ga_vec3f& __restrict in) const
{
	// TODO: Homework 2
	ga_vec4f copyVec; 
	ga_vec3f resultVec; 
	copyVec.x = in.x;
	copyVec.y = in.y;
	copyVec.z = in.z;
	copyVec.w = 0;
	ga_vec4f finVec4;
	for (int i = 0; i < 4; i++) {
			float rowNum = 0;
			for (int j = 0; j < 4; j++) {
				rowNum += ((*this).data[j][i] * copyVec.axes[j]);
			}
			finVec4.axes[i] = rowNum;

	}
	resultVec = { finVec4.x , finVec4.y, finVec4.z};
	
	return resultVec;
}

ga_vec3f ga_mat4f::transform_point(const ga_vec3f& __restrict in) const
{
	// TODO: Homework 2
	ga_vec4f copyVec;
	ga_vec3f resultVec;
	copyVec.x = in.x;
	copyVec.y = in.y;
	copyVec.z = in.z;
	copyVec.w = 1;
	ga_vec4f finVec4;

	for (int i = 0; i < 4; i++) {
			float rowNum = 0;
			for (int j = 0; j < 4; j++) {
				rowNum += ((*this).data[j][i] * copyVec.axes[j]);
			}
			finVec4.axes[i] = rowNum;
	}

	resultVec = { finVec4.x , finVec4.y, finVec4.z };

	resultVec.printVec3();
	return resultVec;
}

void ga_mat4f::transpose()
{
	ga_mat4f tempMat; 
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tempMat.data[j][i] = (*this).data[i][j];
		}
	}

	(*this) = tempMat;
	// TODO: Homework 2
}

bool ga_mat4f::equal(const ga_mat4f& __restrict b)
{
	bool is_not_equal = false;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			is_not_equal = is_not_equal || !ga_equalf(data[i][j], b.data[i][j]);
		}
	}
	return !is_not_equal;
}

void ga_mat4f::printMatrix() {
	for (int i = 0; i < 4; i++) {
		std::cout << "{ ";
		for (int j = 0; j < 4; j++) {
			std::cout << (*this).data[j][i] << " " ;
		}
		std::cout << std::endl; 
	}
	std::cout << "\n";
}

float ga_mat4f::signiCloseZero(float data) {
	if (data < .000009) {
		//return 0; 
	}
	return data; 
}