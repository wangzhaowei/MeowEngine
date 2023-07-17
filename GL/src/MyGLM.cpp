//
//  MyGLM.cpp
//  GL
//
//  Created by Felis Meow on 2023/6/29.
//

#include "MyGLM.hpp"
#include <GLFW/glfw3.h>
//#include <OpenGL/OpenGL.h>
//#include <OpenGL/gl.h>
//#include <OpenGL/gl3.h>
#include <vector>
#include <math.h>

namespace MeowEngine{
using namespace std;

template<class T>
void printMat(const T&& mat){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%f, ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    fflush(stdout);
}

void printMat(std::vector<float>& mat){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%f, ", mat[i * 4 + j]);
        }
        printf("\n");
    }
    printf("\n");
    fflush(stdout);
}

template<class T>
vector<T> cross(std::vector<T> const& a, std::vector<T> const& b){
    vector<T> r (a.size());
    r[0] = a[1]*b[2]-a[2]*b[1];
    r[1] = a[2]*b[0]-a[0]*b[2];
    r[2] = a[0]*b[1]-a[1]*b[0];
    return r;
}

template<class T>
void normalize(vector<T>& vec) {
    double mag = 0;
    for(size_t i = 0; i < vec.size(); ++i){
        mag += vec[i] * vec[i];
    }
    
    double magInv = 1.0 / pow(mag, 0.5);
    
    for(size_t i = 0; i < vec.size(); ++i){
        vec[i] *= magInv;
    }
}

template<class T>
float dot(vector<T>& v1, vector<T>& v2){
    float ret = 0.0;
    for(int i = 0; i < v1.size(); i++){
        ret += v1[i] * v2[i];
    }
    return ret;
}

glm::vec3 vec3_2_glmvec3(std::vector<float> vec){
    return glm::vec3(vec[0], vec[1], vec[2]);
}

GLuint myLookAt(std::vector<float> eye, std::vector<float> center, std::vector<float> up, std::vector<float>& viewMatrix){
    
    vector<float> Z{center[0] - eye[0], center[1] - eye[1], center[2] - eye[2]};
    vector<float> X = cross(up, Z);
    vector<float> Y = cross(Z, X);
    
    normalize(Z);
    normalize(X);
    normalize(Y);
        
    vector<float> ret{
        X[0], Y[0], Z[0], 0,
        X[1], Y[1], Z[1], 0,
        X[2], Y[2], Z[2], 0,
        -dot(X, eye), -dot(Y, eye), -dot(Z, eye), 1,
    };
    viewMatrix = ret;
//    
//    printMat(ret);
//    printMat(glm::lookAt(vec3_2_glmvec3(eye), vec3_2_glmvec3(center), vec3_2_glmvec3(up)));
    
    return 0;
}
};
